# Project 2 - Basic Navigation

In this Project, you will consolidate the knowledge acquired about publishers, subscribers, services, actions and launch files. Your goal will be to create a sequential navigation system that navigates through all the rooms of the created simulation environment. Your solution should contain:

1. **A Main Node**

- Subscribes to LIDAR data (for example, in /scan) to detect if there is a wall closer than a defined limit.

- Publishes forward speed commands in ```/cmd_vel``` when no wall is detected.

- Calls an Action (action client) when it is necessary to make the robot turn.

- Server of a service that, when called, through an empty interface (Empty), starts the sequential navigation.

2. **An Action Server**

- Receives a goal to turn the robot by a certain number of degrees.

- Rotates the robot according to the goal, providing feedback on how many degrees are left to complete the rotation.

3. **A Launch File**

- Launches the main node, the action server, and the service node in a single step.

## Requirements and Goals

1. **Navigation Logic**

- The node waits for the service to be called to initialize the navigation.

- The robot moves forward until it detects a wall at a certain distance (e.g. 0.5 m).

- When it detects the wall, it stops and calls the Action Server to rotate a defined angle (e.g. 90 degrees).

- After the rotation is complete, the robot moves forward again until the next wall, exploring the rooms.

2. **Action Server**

- It must accept a goal indicating how many degrees to rotate.

- It must respond to the client whether the goal was accepted or not.

- Must provide continuous feedback on the remaining angle to rotate.

- Must signal completion or success when rotation is complete.

3. **Launch File**

- Must launch the main node and the action server.

## Delivery

This APS must be delivered by 11:59 PM on March 23 (Sunday).

A .zip file of your **python package** containing the specified nodes and the ROS launch file must be delivered via BlackBoard. The directories, subdirectories, and files must be configured so that the teacher is able to compile the code and run the launch file. In addition, a video of the simulation with the robot performing navigation must be included with the ```.zip```. 

## Assessment

This activity will be assessed as follows:

1. **Basic Functionalities (40%)**

- Presence of a master node that subscribes to the LIDAR and publishes speed commands correctly.

- Robot movement to the wall and stopping when detecting the limit distance.

- Navigation starts only when the empty service is called.

2. **Action Server (40%)**

- Correct implementation of the action server, receiving the angle as the objective, sending a response accepting the objective, feedback and returning success at the end of the rotation.

- Proper use of objective, feedback and result messages.

- Subscribes to the ```/odom``` topic and rotates correctly

3. **Launch File (10%)**

- Launch file that automatically starts the master node and the action server.

4. **Navigation (10%)**

- The robot was able to complete the route

The final score will be the sum of the items above, also considering any penalties for delays or requirements not met.
