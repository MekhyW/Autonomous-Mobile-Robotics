# Main ROS2 commands in the terminal

## Goals
- Activate the ROS2 Foxy environment and understand the importance of the source.
- Learn basic ROS2 commands to list, run and inspect nodes, topics and services.
- Practice using these commands with guided exercises, involving example nodes and the turtlesim package.
- Quickly explore the rqt tool to visualize nodes, topics and services.

## 1. Explanation of basic commands

Here is a list of the most important ROS2 commands, with brief explanations and examples of use.

1. ```source /opt/ros/foxy/setup.bash```
    
    **Description:** Loads the ROS2 environment variables for the current terminal, allowing you to use all ROS2 commands. If you have installed ROS2 in a different location, point to the corresponding path.

    **Example of use:**
    ```bash
    source /opt/ros/foxy/setup.bash
    ```
    **Tip:** insert this command at the end of your ~/.bashrc to run it automatically when opening the terminal.

2. ```ros2 run <package> <executable>```

    **Description:** Executes a node (node) of a specific package. Each package can have one or more executables.

    **Example of use:**
    ```bash
    ros2 run demo_nodes_cpp talker
    ```
    Executes the ```talker``` node of the ```demo_nodes_cpp``` package, which publishes messages to the ```/chatter``` topic.

3. ```ros2 node list```

    **Description:** Lists all active nodes, that is, ROS2 processes running at the moment.

    **Example of use:**
    ```bash
    ros2 node list
    ```
    Can return something like:
    ```bash
    /talker
    /listener
    ```

4. ```ros2 node info <nome_do_nó>``` 

    **Description:** Displays details about a specific node, including published/subscribed topics, offered services, parameters, etc.

    **Example of use:**
    ```bash
    ros2 node info /talker
    ```
    Will show which topics the ```talker``` publishes and/or subscribes to, as well as services that it may offer.

5. ```ros2 topic list```

    **Description:** Lists all topics known by the ROS2 system.

    **Example of use:**
    ```bash
    ros2 topic list
    ```
    Can return topics like ```/chatter```, ```/rosout```, ```/parameter_events```, etc.

6. ```ros2 topic echo <tópico>```

    **Description:** Shows in real time the messages published on a topic.

    **Example of use:**
    ```bash
    ros2 topic echo /chatter
    ```
    If the ```talker``` is active, you will see something like “Hello World: 1”, “Hello World: 2” etc.

7. ```ros2 topic pub <tópico> <tipo_da_msg> <conteúdo>```

    **Description:** Publishes a message manually to a topic. Useful for quick tests.

    **Example of use:**
    ```bash
    ros2 topic pub /chatter std_msgs/msg/String "{data: 'Hello, ROS2!'}" -1
    ```
    The suffix -1 publishes the message only once.

8. ```ros2 service list```

    **Description:** Lists all available services in the ROS2 system.

    **Example of use:**
    ```bash
    ros2 service list
    ```
    Can return services like ```/clear```, ```/spawn```, ```/<node>/set_pen```, etc., especially if you are using turtlesim.

9. ```ros2 service call <serviço> <tipo> <conteúdo>```

    **Description:** Calls (requests) a specific service, sending a request payload and waiting for the response.

    **Example of use:**
    ```bash
    ros2 service call /clear std_srvs/srv/Empty {}
    ```
    In turtlesim, clears the screen.

10. ```ros2 interface list```

    **Description:** Lists all types of interfaces known by ROS2, including messages (```msg```), services (```srv```) and actions (```action```).

    **Example of use:**
    ```bash
    ros2 interface list
    ```
    Can return something like ```std_msgs/msg/String```, ```geometry_msgs/msg/Twist```, ```std_srvs/srv/Empty```, etc.
    - To list only messages:
    ```bash
    ros2 interface list --only-msgs
    ```
    - To list only services:
    ```bash
    ros2 interface list --only-srvs
    ```
    - To list only actions:
    ```bash
    ros2 interface list --only-actions
    ```

11. ```ros2 interface show <tipo>```

    **Description:** Shows the structure (definition) of an interface, which can be ```msg```, ```srv``` or ```action```.

    **Example of use:**
    ```bash
    ros2 interface show std_msgs/msg/String
    ```
    Shows the content of the String message of the std_msgs package, something like:
    ```bash
    string data
    ```


12. ```rqt``` ou ```rqt_graph```

    **Description:** Opens a graphical interface that gathers plugins for monitoring and debugging (nodes, topics, data graphs, etc.).

    **Example of use:**
    ```bash
    rqt
    ```
    or
    ```bash
    rqt_graph
    ```
    rqt_graph shows the node/topic topology.

13. ```rviz2```

    **Description:** Opens the 3D visualization tool of ROS2, allowing you to see maps, robot models, sensors, TF (transform frames), etc.

    **Example of use:**
    ```bash
    rviz2
    ```
    Opens the main RViz panel.

14. ```ros2 pkg create --build-type <tipo> <nome_do_pacote>```

    **Description:** Creates the initial structure of a new ROS2 package, whether in C++ (ament_cmake) or Python (ament_python).

    **Example of use:**
    ```bash
    ros2 pkg create --build-type ament_python meu_pacote_py
    ```
    Creates a Python package called meu_pacote_py.

15. ```colcon build```

    **Description:** Compiles the packages located in the current workspace.

    **Exemplo de uso:**
    ```bash
    colcon build
    ```
    Ao final, você deve fazer:
    ```bash
    source install/setup.bash
    ```
    To make the system recognize the newly created packages.

## 2. Guided exercise
Now, let's practice some of these commands to consolidate the learning. Follow each step in your terminal.

### 2.1 Executing example nodes (talker/listener)

1. Open two terminals (Terminal A and Terminal B). In each one, make:
    ```bash
    source /opt/ros/foxy/setup.bash
    ```
    If this command is already specified in your ```~/.bashrc``` file, this step is not necessary.

2. Terminal A: Execute the talker node:
    ```bash
    ros2 run demo_nodes_cpp talker
    ```

3. Terminal B: Execute the listener node:
    ```bash
    ros2 run demo_nodes_cpp listener
    ````

4. Open a third terminal (Terminal C), activate ROS2 again (if necessary) and check:
    ```bash
    ros2 node list
    ros2 topic list
    ```
    You should see ```/talker``` and ```/listener``` in the nodes, and ```/chatter``` in the topics.

5. In Terminal C, run:
    ```bash
    ros2 topic echo /chatter
    ```
    Follow the messages “Hello World: X” sent by the ```talker```.

### 2.2 Interacting with topics (manual publication)

1. If the commands are still running in terminals A and C, stop them using the ```Ctrl + C``` command. In Terminal C, publish manually to the ```/chatter``` topic:
    ```bash
    ros2 topic pub /chatter std_msgs/msg/String "{data: 'Mensagem de teste!'}" -1
    ```

2. Observe in Terminal B (where the ```listener``` node is running) that the message 'Mensagem de teste!' appeared.

### 2.3 Explorando o turtlesim e serviços

1. Install and run the turtlesim simulator in a new terminal:
    ```bash
    sudo apt update
    sudo apt install ros-foxy-turtlesim
    ros2 run turtlesim turtlesim_node
    ```
    A window will appear with a turtle on a blue background.

2. In another terminal, run the teleop to control the turtle with the keyboard arrows:
    ```bash
    ros2 run turtlesim turtle_teleop_key
    ```
    Make the turtle move with the indicated keys

3. In a third terminal, see the available services:
    ```bash
    ros2 service list
    ```
    You should see ```/clear```, ```/spawn```, ```/turtle1/teleport_absolute```, etc.

4. Call the ```/clear``` service:
    ```bash
    ros2 service call /clear std_srvs/srv/Empty {}
    ```
    The turtlesim screen will be cleared

5. Teleporting the turtle to (5.0, 5.0):
    ```bash
    ros2 service call /turtle1/teleport_absolute turtlesim/srv/TeleportAbsolute "{x: 5.0, y: 5.0, theta: 0.0}"
    ```

6. Check the ```TeleportAbsolute``` service interface:
    ```bash
    ros2 interface show turtlesim/srv/TeleportAbsolute
    ```

### 2.4 Graphical tool ```rqt```

1. Keep the ```turtlesim``` and ```turtlesim_teleop``` nodes active, opened previously.

2. In a second terminal, run:
    ```bash
    rqt
    ```
    In the ```Plugins``` > ```Node Graph``` menu (or simply run ```rqt_graph```):
    ```bash
    rqt_graph
    ```
    Visualize the topology: the ```turtlesim_node``` and the ```turtle_teleop_key``` communicating through topics.

## 3. Fixation exercise

Here is a more complex exercise to consolidate what we have learned:

### 3.1 Movement via topics

1. Run the ```turtlesim``` node in a terminal.

2. Through the ```ros2 topic info``` command, discover the type of message of the ```/turtle1/cmd_vel``` topic.

3. Use the ```ros2 interface show``` command to analyze the structure of the message used by this node.

4. Use the ```ros2 topic pub``` command to move the turtle, selecting its linear and angular velocity.

### 3.2 Creating multiple turtles

1. Through the ```ros2 service info``` command, discover the type of interface used by the ```/spawn``` service.

2. Use the ```ros2 interface show``` command to analyze the structure of the service used by this node.

3. Call the ```/spawn``` service to create a second turtle, called turtle2, at position (2.0, 2.0).

4. Using the ```ros2 node list``` command, check if the new corresponding node appeared.

5. Using the ```ros2 topic list``` command, check if there are new topics for the second turtle.

### 3.3 Moving the second turtle

1. Follow the steps in section 3.1 and move the second turtle

### 3.4 Changing the pen of the new turtle

1. Using the same logic of section 3.2, change the thickness and color of the trace by calling the ```/turtle2/set_pen``` service.

### 3.5 Cleaning

1. Clean the screen, calling the ```/clear``` service

## Conclusion

You now know the **basic commands** to work with ROS2 via terminal, including:

- Activate the environment (source)
- Run nodes (ros2 run)
- List/inspect nodes, topics, services and interfaces (ros2 interface list/show)
- Publish and subscribe to topics (ros2 topic pub, ros2 topic echo)
- Call services (ros2 service call)
- Open the graphical tool rqt for visualization.
