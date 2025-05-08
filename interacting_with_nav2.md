# Interacting with Nav2

In this exercise, we will interact with the ROS 2 navigation stack (Nav2) via the terminal and through Nodes, sending navigation commands via code.

## 1. Sending commands via terminal

### 1.1 Modifying parameters

The **Nav2** parameters, defined in the ```.yaml``` configuration file, can be changed after the nodes have been initialized. This is a useful tool if it is necessary to change the robot's behavior in different situations, without having to recompile and restart the entire code.

This change can be made either via the terminal, by the command

```bash
ros2 param set [node] [parameter]
```

as well as using the ```rcl_interfaces/srv/SetParameters``` service interface.

Unfortunately, in this version of ROS2 (**Foxy**), changing most parameters does not take effect directly when requested. It is necessary to deactivate and reactivate the node in question. This can be done through ```lifecycle_node```, which is responsible for managing the nodes related to **Nav2**. Therefore, in this exercise we will only set the initial position.

1. **Start the simulation**

As in the previous lessons, start the **turtlebot3** simulation, but do not set the robot's initial position.

2. **Set the initial position via terminal**

See the structure of the interface used by the ```/initialpose``` topic and publish a message with the robot's initial position.

3. **Verify the change**

In **Rviz**, see if the robot's initial position was set without having to do it manually through the graphical interface.

### 1.2 Sending navigation commands

It is also possible to send navigation commands outside the **Rviz** visual interface. Since this command usually takes longer to execute, it is done through **actions**

1. **Check the action**

With the **turtlebot3** simulation still running, see how the interface used to send a navigation goal is structured:

```bash
ros2 interface show nav2_msgs/action/NavigateToPose
```

1. **Sending Goal**

Now, use the interface structure seen in the previous item and send a navigation command through the ```/navigate_to_pose``` action

3. **Visualization**

In **Rviz**, see if the robot has planned the path to the desired point and started navigation.

### 1.3 Extra commands

When initializing the navigation stack (**Nav2**), several services and actions are made available for interaction, such as clearing cost maps, clearing or replanning routes, changing the loaded map, among others. You can view the complete list using the commands:

```bash
ros2 action list
```

and

```bash
ros2 service list
```

## 2. Sending commands through Nodes

In addition to commands via the terminal, it is possible to interact with **Nav2** through Nodes, enabling the automation of tasks that we want the robot to perform.

### Exercise:

Create a node that sends a navigation command. Once the objective is reached, it must return to the starting point.

1. **Create a new package called ```rm_navigator``` to write the node**

```bash
ros2 pkg create rm_navigator --build-type ament_python --dependencies rclpy
```

2. **Create the Node file**

```bash
cd rm_navigator/rm_navigator
touch navigator.py
```

3. **Write the code**

In the newly created file, write the node that performs the desired path.

4. **Run the Node**

In a terminal, initialize the **turtlebot3** simulation. In a second, run the created node and see, in **rviz**, if the robot correctly executes the desired path.

Remember to add the node as executable in the ```setup.py``` file.





