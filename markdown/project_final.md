# Final Project - Advanced Autonomous Navigation with ROS 2 and Docker

## 1. Project Introduction

This final project aims to consolidate and expand the knowledge acquired during the course, taking your robot to a new level of autonomy. You will implement a complete navigation system using **Nav2**, the standard navigation stack of ROS 2, and develop a node to manage multiple waypoint missions. In addition, you will apply good development practices when packaging the entire solution using Docker and Docker Compose.

This is a project that integrates several concepts and technologies in mobile robotics, preparing you for complex real-world problems.

## 2. General Objectives

At the end of this project, you will be able to:

* **Implement and Configure Nav2:** Integrate and perform _tuning_ of the Nav2 stack to enable robust autonomous navigation of the simulated differential robot.

* **Develop a Mission Manager:** Create a ROS 2 node that sequentially sends waypoints to Nav2, controlling the flow of a navigation mission.

* **Use Docker for Deployment:** Package all software dependencies and developed nodes in Docker containers, orchestrating them with Docker Compose.

* **Apply Integrated Knowledge:** Demonstrate an integrated understanding of the various subsystems of an autonomous mobile robot (perception, localization, planning, control, and mission execution).


## 3. Steps and Requirements Details

This section details each component of the project that will be evaluated.

### 3.1. Implementation and _Tuning_ of Nav2 (4 points)

* **Description:**

    The main objective of this step is to enable autonomous navigation of your differential robot using the Nav2 stack. You should start from the Nav2 configuration for TurtleBot3 (presented in class) and adapt it to the specificities of the robot that your team developed.

* **Essential Tasks:**

    * Adapt the Nav2 configuration files (YAML parameters, _launch_ files, etc.) to use the correct sensor topics (LIDAR, IMU, odometry) and the TF _frames_ of your robot.

    * Adjust the physical parameters of the robot in Nav2, such as _footprint_ (shape and dimensions), radius, velocities and maximum/minimum accelerations.

    * Properly configure the _costmaps_ (global and local), including the inflation and obstacle layers, according to the characteristics of your robot and the simulation environment.

    * Perform the _tuning_ of the global and local planning algorithms and the _controller_ to obtain an efficient and safe navigation behavior.

* **Success Criteria:**

    The robot must be able to receive a target pose (_goal_) through the "Nav2 Goal" tool in RViz2 and navigate autonomously to it, planning routes, avoiding known and dynamic obstacles on the map and updating its planning as necessary.

### 3.2. Sequential Waypoint Publisher Node (3 points)

* **Description:**

    Develop a node in ROS 2 that manages a navigation mission, sending a predefined sequence of _waypoints_ (target poses) to Nav2.

* **Essential Tasks:**
    * The node must use the _action_ `nav2_msgs/action/NavigateToPose` to send each _waypoint_ individually to Nav2.

    * The _waypoint_ sequence must be defined in the node code or loaded from an external configuration file (e.g. YAML).

    * The start of sending the _waypoint_ sequence must be triggered by a ROS 2 service, that is, when started, the node must be active waiting for the service to be called to start navigation.

* **Success Criteria:**

    After triggering the service, the robot must wait for the service to be called to navigate sequentially through all the rooms in its simulation environment. The node must correctly manage the mission flow.

### 3.3. Project Dockerization (2 points)

* **Description:**

    Create a Dockerized environment to facilitate the deployment and execution of the location, navigation system and the waypoint publishing node.

* **Essential Tasks:**

    * **`Dockerfile`:** Develop a `Dockerfile` that configures a ROS 2 Foxy environment and installs all necessary dependencies, including the Nav2, AMCL, EKF and new waypoint publishing node packages.

    * **`docker-compose.yml`:** Create a `docker-compose.yml` file to orchestrate the following services:

    * `localization`: Starts the robot localization-related nodes (AMCL and EKF)

    * `navigation`: Starts the Nav2 navigation stack (Lifecycle Manager, planners, controllers, costmaps, BT navigator, etc.).

    * `waypoint_follower`: Starts the waypoint publisher node developed by you.

* **Success Criteria:**

    The `docker-compose up` command must be able to start all defined services, allowing the complete system (localization, navigation, mission) to function correctly, communicating with the Gazebo simulator (which must be running separately, on the host).

### 3.4. Workspace Structure and Overall Quality (1 point)

* **Description:**

    The organization of the ROS 2 workspace, the quality of the code, and the documentation are fundamental to a good engineering project.

* **Essential Tasks:**

    The project workspace should **only** contain the following packages and files:

    ```bash
    Final_Project/
    ├── src/
    │   ├── custom_interfaces/
    │   │   ├── action/
    │   │   ├── msg/
    │   │   ├── srv/
    │   │   ├── CMakeLists.txt
    │   │   └── package.xml
    │   │
    │   ├── rm_localization/
    │   │   ├── config/
    │   │   ├── launch/
    │   │   ├── map/
    │   │   ├── CMakeLists.txt
    │   │   └── package.xml
    │   │
    │   ├── rm_navigation/
    │   │   ├── config/
    │   │   ├── launch/
    │   │   ├── CMakeLists.txt
    │   │   └── package.xml
    │   │
    │   ├── robot_description/
    │   │   ├── launch/
    │   │   ├── rviz/
    │   │   ├── urdf/
    │   │   ├── world/
    │   │   ├── CMakeLists.txt
    │   │   └── package.xml
    │   │
    │   └── waypoint_navigation_pkg/
    │       ├── launch/
    │       ├── waypoint_navigation_pkg/
    │       ├── resource/
    │       ├── package.xml
    │       └── setup.py
    │
    ├── Dockerfile
    └── docker-compose.yml
    ```

* **Success Criteria:**
    The _workspace_ must be well organized and the file names representative, allowing another person (the evaluator) to understand, compile and execute the project without difficulties.

## 4. Deliverables and Assessment

Groups (up to 3 people) must deliver a **single ZIP file** containing:

1. **Complete ROS 2_Workspace:**

    * Workspace with all ROS 2 packages developed and configured by the team.

    * Include the `Dockerfile` in the root of the _workspace_ or in an appropriate location.

    * Include the `docker-compose.yml` file in the root of the _workspace_.

2.  **Demonstration Videos (screen recordings):** Videos must be clear, objective and demonstrate how each part works.

    * **Video 1: Navigation with Nav2 (Goal via RViz2)**
        * Demonstration of item 3.1.

        * **Combined evaluation (code + video): 4 points**

        * _Suggested Script:_
            * Show the robot in Gazebo and RViz2.
            * Show the AMCL locating the robot correctly on the map (converged particles).
            * Show each of the following layers referring to the correct functioning of Nav2:
            * Global cost map
            * Local cost map
            * Footprint
            * Planned path

            To make it easier to visualize, add and remove one by one while recording the video
            * Use the "Nav2 Goal" tool in RViz2 to send one or more destinations to the robot.
            * Show the robot navigating to the goals, displaying the planned trajectory, and avoiding obstacles present on the map.

    * **Video 2: Sequential _Waypoints_ Mission**

        * Demonstration of item 3.2.

        * **Combined evaluation (code + video): 3 points**

        * _Suggested Script:_
            * Show the robot in the Gazebo and RViz2, already located.

            * Execute the command to activate the service that starts the _waypoints_ mission.

            * Show the robot navigating through the complete sequence of _waypoints_ defined.

            * While the robot navigates, add at least two dynamic obstacles to demonstrate its replanning capability.

    * **Video 3: Docker Demo**

        * Demo of item 3.3.

        * **Combined assessment (Docker files + video): 2 points**

        * _Suggested script:_

            * Show the execution of the `docker-compose up` command.

            * Display the _logs_ of the _containers_ being started.

            * Use `docker ps` to show the _containers_ of the services (`localization`, `navigation`, `waypoint_follower`) that are running.

            * Call the service to initialize navigation and show its execution in Rviz/Gazebo

## 5. Execution Tips

* **Constant Iteration and Testing:**
    * **Nav2 First:** Focus on getting Nav2 adaptation working for a single _goal_ sent by RViz2. This is the foundation for everything else
    * **Waypoint Node:** Implement sending a single _waypoint_ via _action_ first. Then add the sequencing logic and triggering service.
* **Docker:** It is recommended to have the system running locally (outside of containers) before attempting full dockerization. This simplifies debugging ROS/Nav2-related issues. A member can start preparing the Dockerfile and docker-compose.yml in parallel as the packages are developed.
* **Videos Goals:** Plan the videos to be clear and concise, covering all the aspects requested. If possible, briefly narrate what is being demonstrated. Check the audio and video quality.
* **Check the Official Documentation:** The ROS 2 Foxy, Nav2 and Docker documentation are your best friends. Many common issues and configuration examples are there. In addition, resources such as videos and tutorials like [this link](https://automaticaddison.com/the-ultimate-guide-to-the-ros-2-navigation-stack/) can be extremely helpful.

Good luck!