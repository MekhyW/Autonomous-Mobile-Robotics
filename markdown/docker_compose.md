# Docker Compose

Docker Compose is an official Docker platform tool that orchestrates multiple containers from a single docker-compose.yaml file. By manually starting each container with long docker run commands, Compose describes the entire application — services, networks, and volumes — in a declarative and versioned way, making it easier to develop, run, and share complex environments.

Key benefits:

- Simplified orchestration – A single command (docker compose up) creates, connects, and starts all the necessary services.

- Full reproducibility – The versioned yaml file ensures that the same set of containers, image versions, and environment variables are recreated on any machine.

- Rapid scalability – With --scale, additional replicas of a service are spun up without changing code.

- Isolation and internal networks – Automatically compose isolated virtual networks, ensuring that services only talk to each other or to the host when allowed.

**What you will do in this exercise**

1. Create a docker-compose.yaml file based on the ```osrf/ros:foxy-desktop``` image that contains two services:

- The first one running the ```talker``` example node.

- The second one running the ```listener``` example node.

- Visualize both communicating with each other.

2. Create a docker-compose.yaml file based on a locally created image from a ```Dockerfile``` file, that contains a service that, when started, sends a navigation command to Nav2.

## 1. Basic Docker Compose

1. In a directory of your choice, create a file called ```docker-compose.yaml``` and copy the code below:

    ```docker-compose
    services:
        base:
            image: osrf/ros:foxy-desktop
            stdin_open: true
            tty: true
            network_mode: host
            ipc: host
            privileged: true

        talker:
            extends: base
            container_name: ros2_talker
            command: ["bash", "-c", "source /opt/ros/foxy/setup.bash && ros2 run demo_nodes_cpp talker"]

        listener:
            extends: base
            container_name: ros2_listener
            command: ["bash", "-c", "source /opt/ros/foxy/setup.bash && ros2 run demo_nodes_cpp listener"]
    ```

    **Explanation**

    **image: osrf/ros:foxy-desktop**: Defines the base image used in containers, which in this case is the official ROS 2 Foxy image

    **stdin_open: true and tty: true**: Allows the container to keep an interactive terminal open, which is useful for debugging or executing commands directly in the container via docker attach or docker exec.

    **network_mode: host**: Makes the container use the host network directly, allowing ROS nodes to communicate with each other using multicast and other network features as if they were running on the host system itself.

    **ipc: host**: Shares the interprocess communication (IPC) namespace with the host, allowing access to shared memory — necessary for some applications such as Rviz and Gazebo that use /dev/shm.

    **privileged: true**: Grants elevated permissions to the container, allowing access to host devices such as USB ports, CAN network or serial interfaces. It should be used with caution, as it reduces the security isolation of the container.

    **extends: base**: Indicates that the talker and listener services reuse the entire configuration of the base service, avoiding repetition and facilitating Compose maintenance.

    **container_name**: Defines fixed names for the containers, facilitating their identification and the execution of commands such as docker logs or docker exec.

    **command**: Specifies the command to be executed when starting the container. In this case, it starts a shell, configures the ROS 2 environment with source /opt/ros/foxy/setup.bash and executes the corresponding node (talker or listener) from the demo_nodes_cpp demo package.

2. Open a terminal, in the same directory as the file, and compile the images:

    ```bash
    docker compose build
    ```

3. In the same terminal, start the ```talker``` service:

    ```bash
    docker compose up talker
    ```

4. In a second terminal, start the ```listener``` service:

    ```bash
    docker compose up listener
    ```

5. See if the initialized nodes are communicating

6. In a third terminal, stop the started services with the command:

    ```bash
    docker compose down
    ```

## 2. Volumes and Docker exec

In this step, you will learn how to mount a Docker volume in a container, allowing data written within the container to be persisted or shared between services. This is useful for logs, configuration files, experiment results, and more.

1. In the same directory as ```docker-compose.yaml``` create a directory ```test``` and, in it, a file ```test.py```. In the newly created file, write the code:

    ```python
    print("File mounted successfully!")
    ```

2. Create the volume in the ```docker-compose.yaml``` file. In the ```base``` section, add the lines:

    ```docker-compose
    volumes:
        - ./test:/test
    ```

3. In a terminal, run the ```talker``` service:

    ```bash
    docker compose up talker -d
    ```

    The ```-d``` argument makes the service run in the background, leaving the terminal free.

4. Enter the container:

    ```bash
    docker exec -it ros2_talker bash
    ```

5. Verify that the file is present in the container:

    ```bash
    cd test
    ls
    ```

6. Run the ```test.py``` file with the command:

    ```bash
    python3 test.py
    ```

    And see if the message is displayed in the terminal.

7. Exit the container with the ```Ctrl + d``` command and stop the services with the ```docker compose down``` command

## 3. Docker Compose from a Dockerfile

Similar to the previous sections, it is possible to create services based on locally created images, defined in a ```Dockerfile``` file.

1. Modify the ```docker-compose.yaml``` file to use as a base the image created in the previous lesson in the ```Dockerfile``` file. Search for how to do this.

2. Following the example of the ```talker``` and ```listener``` services, create a new service called ```nav2_goal``` that, when started, sends a navigation command to nav2.

3. Compile the ```docker-compose.yaml``` file

4. In a terminal, start the **turtlebot3** simulation and define its initial position.

5. In a second terminal, start the ```nav2_goal``` service and verify that the robot executed the command.
