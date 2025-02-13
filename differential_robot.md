# Design of a Differential Robot with ROS2

In this activity, students will develop a ROS2 package using URDF and XACRO to describe a differential mobile robot. The robot should consist of a body (base), two wheels (defined in a separate XACRO file), and a caster ball for stability. The activity emphasizes modularization of the robot description, encouraging the creation of reusable components and proper organization of the project.

## Objectives

- Modularization with XACRO:
Divide the robot description into separate components (body and wheels) to facilitate maintenance and scalability of the project.

- Integration and visualization:
Integrate the modular descriptions into a single main file and use RViz2 to visualize the robot model.

- Practical application of mobile robotics concepts:
Design and simulate a differential robot with real and simulated elements, enabling the implementation of future control and navigation functionalities.

## Requirements

- **Body (Base):**

    - Should be represented by a cube or a cylinder.
    - Will serve as the central structure for the integration of other components.

- **Wheels:**

    - Two wheels positioned and aligned on the Y axis.
    - The wheels should be defined in a separate XACRO file from the main body, containing also the configuration of the joints that connect them to the base.

- **Caster Ball:**

    - At least one caster ball to assist in the stability of the robot.
    - If necessary, two caster balls can be used to maintain stability.
    - The definition can be included in the main file or separated, according to the chosen organization.

## 1. Preparation of the Environment

In the previous class, we created our workspace of work ```[name]_ws``` and the first own package, ```robot_description```. If you don't have these structures created, go back to the tutorial of the previous class and follow the step by step.

In this class, we will continue working on the same package, now adding the files related to the robot simulation. To start, follow the instructions below:

1. In the directory ```[name]_ws/robot_description```, create two more directories, ```urdf``` and ```rviz```. The first will be the directory where we will save the **URDF** and **XACRO** files related to the robot modeling. The second will be where the Rviz configuration file will be.

2. In the ```CMakeLists.txt``` file, add the necessary dependencies below ```find_package(ament_cmake REQUIRED)```:

    ```CMake
    find_package(urdf REQUIRED)
    find_package(xacro REQUIRED)
    ```
    and also add the recently created directories to the list of folders to be compiled:

    ```CMake
    install(
    DIRECTORY
        urdf
        launch
        rviz
        world
    DESTINATION
        share/${PROJECT_NAME}/
    )
    ```

3. Also add the dependencies to the ```package.xml``` file:

    ```xml
    <depend>urdf</depend>
    <depend>xacro</depend>
    ```
    right below ```<buildtool_depend>ament_cmake<buildtool_depend>```

4. Finally, install the package:

    ```bash
    sudo apt install ros-foxy-xacro
    ```

## 2. Organization of the XACRO Files

The ```.xacro``` files will be created inside the ```robot_description/urdf``` directory

### 2.1 Main Robot File:

1. Create a file (for example, ```differential_robot.xacro```) that will serve as the complete description of the robot.

2. In this file, define the ```base_link```, the robot body (```chassis```) and include the general parameters, such as visual, inertia and collision.

3. The ```base_link``` must be in the center of rotation of the robot. In the case of a differential robot, it will be located in the middle of the axis that joins the wheels.


### 2.2 Wheels File:

1. Create a separate file (for example, ```wheels.xacro```).

2. Model the wheel as a ```.xacro``` file, specifying its characteristics (geometry, inertia, mass, etc.) and configure the joints to connect the wheels to the robot base.

3. The wheels must be aligned on the Y axis, according to the requirement.

4. In the definition of the joint, define the ```base_link``` as ```parent```.

5. To maintain the convention, the wheel will rotate around the **Z axis**. Therefore, it will be necessary to rotate the link when defining the joint.

### 2.3 Caster Ball

1. It can be created both in the main file or in a separate one.

2. The size of it should be such that the part of the robot supported by it is at the same height as the part supported by the wheels.

3. For simulation purposes, define the friction of this body as zero, adding the following code:

    ```xml
    <gazebo reference="caster_wheel">
        <material>Gazebo/Black</material>
        <mu1 value="0.001"/>
        <mu2 value="0.001"/>
    </gazebo>
    ```

### 2.4 Integration

1. In the main file (```differential_robot.xacro```), include the file and create two instances of the wheels to compose the final robot description.

## 3. Configuration of the ```launch``` file

The ```launch``` file is responsible for running various ROS nodes simultaneously. This specific file will be responsible for running the following nodes:

- ```robot_state_publisher```: Responsible for publishing the links of the robot and their transformations, as well as the robot model.

- ```rviz2```: Opens the ```rviz2``` graphical interface

- ```gazebo```: Opens the gazebo

- ```spawner```: Opens the URDF/XACRO file in Gazebo

1. Inside the ```robot_description/launch``` directory, create the ```robot_description.launch.py``` file and copy the following code:

    ```python
    import os
    from ament_index_python.packages import get_package_share_directory
    from launch import LaunchDescription
    from launch.actions import IncludeLaunchDescription
    from launch.launch_description_sources import PythonLaunchDescriptionSource
    from launch_ros.actions import Node
    import xacro


    def generate_launch_description():

        xacro_file = "differential_robot.xacro"
        description_package_name = "robot_description"
        description_package_path = os.path.join(get_package_share_directory(description_package_name))
        xacro_file_path = os.path.join(description_package_path, 'urdf', xacro_file)

        # convert XACRO file into URDF
        doc = xacro.parse(open(xacro_file_path))
        xacro.process_doc(doc)
        params = {'robot_description': doc.toxml(), 'use_sim_time': True}

        # Include the Gazebo launch file, provided by the gazebo_ros package
        gazebo = IncludeLaunchDescription(
                    PythonLaunchDescriptionSource([os.path.join(
                        get_package_share_directory('gazebo_ros'), 'launch', 'gazebo.launch.py')]),
                )

        robot_state_publisher = Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            name='robot_state_publisher',
            output='screen',
            parameters=[params]
        )

        # RVIZ Configuration
        rviz_config_dir = os.path.join(get_package_share_directory(description_package_name), 'rviz', 'robot_vis.rviz')
        rviz_node = Node(
                package='rviz2',
                executable='rviz2',
                output='screen',
                name='rviz_node',
                parameters=[{'use_sim_time': True}],
                arguments=['-d', rviz_config_dir]
            )
        
        spawn_entity = Node(package='gazebo_ros', executable='spawn_entity.py',
                            arguments=['-entity', 'rm', '-x', '0.0', '-y', '0.0', '-z', '0.2',
                                    '-topic', 'robot_description'],
                            output='screen')
        
        
        return LaunchDescription([
            gazebo,
            robot_state_publisher,
            rviz_node,
            spawn_entity,
        ])
    ```

2. Define the ```xacro_file``` variable with the name of your main file.

## 4. Package compilation

1. In the terminal, access your workspace:
    ```bash
    cd ~/[name]_ws //if your workspace is in the home directory
    ```
2. Compile the package
    ```bash
    colcon build
    ````

3. Update the environment
    ```bash
    source install/setup.bash
    ```

## 5. Execution and test

1. Execute the ```launch``` file
    ```bash
    ros2 launch robot_description robot_description.launch.py
    ```

2. Open RViz2 and confirm that the robot model, composed of the body, wheels and sensors, is being displayed correctly.

3. The joints defined as **fixed** should already appear defined in **rviz** as soon as it initializes. The movable joints require that their value be published on the ```/joint_states``` topic. Later, a **gazebo** plugin will be responsible for this, but to visualize and validate the movement of the joints, we can use the ```joint_states_publisher_gui``` package. To do this, in a new terminal, execute:

    ```bash
    ros2 run joint_state_publisher_gui joint_state_publisher_gui
    ```

    This command should open a graphical interface where you can change the value of the movable joints.

3. If any component is not correct, review the ```.xacro``` files and the joint configurations and parameters.