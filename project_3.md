# Project 3 - Localization and SLAM

In this Project, you will consolidate the knowledge acquired about the implementation in ROS2 of sensor fusion using extended kalman filter, Monte Carlo localization (AMCL) and SLAM (Simultaneous Localization and Mapping).

To carry out this APS, you must create two packages:

1. **rm_localization**

This package must have the following directories and files:

- **config**: containing the **EKF** and **AMCL** configuration files, which are:

- **ekf.yaml**: Must merge the odometry and imu data, having as output the topic ```/odometry/filtered```.

- **amcl.yaml**: Contains the configuration parameters of the **AMCL** package.

- **launch**: With the initialization files for each package:

- **ekf.launch.py**: Must initialize the **ekf** node from the **robot_localization** package, passing as a parameter the configuration file created in the ```launch``` directory.

- **amcl.launch.py**: Must initialize the **AMCL** node from the **nav2_amcl** package, passing as a parameter the configuration file, and the map created using **SLAM**, located in the ```map``` directory.

- **map**: Containing the ```.pgm``` and ```.yaml``` files related to the created map.

2. **rm_slam**

This package must contain the following directories and files:

- **config**: Containing the **slam_config.yaml** configuration file from the **slam_toolbox** package.

- **launch**: Contains the launch file, **slam.launch.py**, of the node ```async_slam_toolbox_node```, belonging to the package **slam_toolbox**.

## Delivery

This APS must be delivered by 23:59 on 21/04 (Monday).

A ```.zip``` file with the two packages created for this APS must be delivered via BlackBoard, containing the ```.yaml``` configuration files, the ```.launch``` files and the created map. In addition, two videos of the code execution must be recorded together with the ```.zip```:

- **Video 1**: In this video, the process of initializing the simulation environment, the node containing **EKF** and the node with the **slam_toolbox** package must be recorded, each using their respective ***launch files*** and in a separate terminal. After the nodes have been initialized, the environment must be mapped using **RVIZ** and the map saved.

- **Video 2**: In the second video, the process of initializing the simulation environment, the node containing **EKF** and the node with the **AMCL** package must be recorded, each using their respective ***launch files*** and in a separate terminal. After the nodes have been initialized, navigation in the environment must be performed, showing the successful location using the created map and its particles.

This APS can be performed in pairs. In this case, only one person in the pair must submit the work via Blackboard, adding the name of the second member in the submission comments.

## Assessment

This activity will be assessed as follows:

1. **Sensor fusion with the ```robot_localization``` package (30%)**

2. **Localization with the ```nav2_amcl``` package (30%)**

3. **Mapping with the ```slam_toolbox``` package (40%)**