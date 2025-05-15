# Docker

Docker is a *containerization* platform that packages applications and all their dependencies into portable units called **containers**.

Its main advantages are:

* **Reproducibility**: Keeping the same version of libraries and dependencies.

* **Isolation**: Project dependencies do not “pollute” the host OS.

* **Portability**: the same image runs on PCs, the cloud or Jetson (ARM), simply by defining `--platform`.

**What you will do in this exercise**

1. **Install** Docker on your system.

2. **Build** an image based on `ros:foxy`.

3. **Run** an interactive container.

## 1. Install Docker

Follow the step-by-step instructions described in [this link](https://docs.docker.com/engine/install/ubuntu/), in the **Install using the apt repository** section, and install Docker on your virtual machine or WSL.

## 2. Grant administrator permissions to Docker

To avoid having to use administrator permissions (```sudo```) every time you start a docker, follow the steps described in [this link](https://docs.docker.com/engine/install/linux-postinstall/), under the **Manage Docker as a non-root user** section. This step is not necessary, but it can make starting up easier.

## 3. Creating the first container

To start, let's import a ready-made docker image that already contains the necessary packages to run ros2 Foxy

1. **Build the Image**

In a terminal, in the same directory as the Dockerfile, run the command:

```bash
docker pull osrf/ros:foxy-desktop
```

2. **Run the container**

With the image downloaded, we can use it to open separate containers in each terminal, and have each one execute a command/function.

**Terminal 1**
```bash
docker run --rm -it --name ros2_talker --network host osrf/ros:foxy-desktop bash
```

**Terminal 2**
```bash
docker run --rm -it --name ros2_listener --network host osrf/ros:foxy-desktop bash
```

**Flags Used**:
- **--rm**: Removes the container once we stop it
- **-it**: Leaves an interactive terminal open
- **--name**: Gives the container a name
- **--network host**: Makes the container share network interfaces with the host
- **ros:foxy-desktop**: Name of the image to be used to boot the container

3. **Run the sample nodes**

**Terminal 1**

```bash
source /opt/ros/foxy/setup.bash
ros2 run demo_nodes_cpp talker
```

**Terminal 2**

```bash
source /opt/ros/foxy/setup.bash
ros2 run demo_nodes_cpp listener
```

Note that both containers, even though they are different "machines", are able to communicate. This is possible because they are sharing the same network interface, as defined when the container was initialized.

## 4. Creating a Dockerfile

In addition to running a ready-made image, it is possible to create our own images. This is done through a file called ```Dockerfile```.

A **Dockerfile** is a text file that describes, step by step, how to build a Docker image — think of it as the “recipe” that Docker uses to make the “cake” (the image).

Each line of the Dockerfile is a declarative instruction; When you run `docker build`, the engine creates a **new immutable layer** for each instruction, resulting in a stack of layers that form the final image.
This ensures:

* **Reproducibility**: Anyone, on any machine, running the same `docker build` will get exactly the same image.
* **Versioning**: Small changes generate only new layers, saving time and storage.
* **Transparency**: The history of each modification is recorded — useful for auditing and CI/CD.

The main instructions for building the image are:

| Instruction   | What is it for                                                                      | Minimal example                                                        |
|-------------|-------------------------------------------------------------------------------------|-----------------------------------------------------------------------|
| `FROM`      | Choose the base image (starting point).                                           | `FROM ros:foxy-ros-base`                                              |
| `RUN`       | Executes shell commands at build time (installs packages, compiles code).    | `RUN apt-get update && apt-get install -y ros-foxy-gazebo-ros-pkgs`   |
| `COPY`      | Copies files from the host to the image.                                               | `COPY src/ /ws/src`                                                   |
| `ADD`       | Same as `COPY`, but also unpacks `.tar` and downloads via URL.               | `ADD https://site.com/file.tar.gz /tmp/`                              |
| `WORKDIR`   | Defines the directory in which subsequent instructions will be executed.                    | `WORKDIR /ws`                                                         |
| `ENV`       | Creates environment variables available at build **and** runtime.         | `ENV LANG=C.UTF-8`                                                    |
| `ARG`       | Declares variables only visible in the build (passed with `--build-arg`).                | `ARG UID=1000`                                                        |
| `USER`      | Change the user that will execute commands (avoids running as root).                     | `USER rosuser`                                                        |
| `VOLUME`    | Marks directories to be mounted as persistent volumes.                        | `VOLUME ["/ws/maps"]`                                                 |
| `EXPOSE`    | Documents ports that the container intends to use (does not publish automatically).       | `EXPOSE 11311/udp`                                                    |
| `LABEL`     | Add metadata to the image (author, version, commit).                                | `LABEL maintainer="lucas@example.com"`                                |
| `ENTRYPOINT`| Defines the “fixed” executable of the container.                                            | `ENTRYPOINT ["ros2"]`                                                 |
| `CMD`       | Default parameters of `ENTRYPOINT` or final command if there is no `ENTRYPOINT`.      | `CMD ["launch", "my_pkg", "bringup.launch.py"]`                       |
| `SHELL`     | Changes the interpreter used in the instructions `RUN`.                                    | `SHELL ["/bin/bash", "-c"]`                                           |
| `HEALTHCHECK`| Defines how Docker checks whether the container is healthy.                        | `HEALTHCHECK CMD curl -f http://localhost/ || exit 1`                 |
| `ONBUILD`   | Trigger that runs **when another image uses this one as a base**.                        | `ONBUILD COPY . /app/src`                                             |


### Exercise:

1. **Create the Dockerfile**:

In a directory of your choice, create a file called ```Dockerfile```

```bash
touch Dockerfile
```

2. **Create the *"recipe"***

In the newly created file, write the sequence of commands to create an image with the following requirements:

- Use the ```osrf/ros:foxy-desktop``` image as the starting point (base)
- Set the interpreter to ```["/bin/bash", "-c"]```
- Install the ROS packages ```navigation2```, ```nav2-bringup``` and ```rmw-cyclonedds-cpp```
- Add the command ```source /opt/ros/foxy/setup.py``` to the ```~/.bashrc``` file
- Set the environment variable ```RMW_IMPLEMENTATION=rmw_cyclonedds_cpp```

3. **Build the image**

In the Dockerfile directory, run the command:

```bash
docker build -t ros2:foxy-min .
```

4. **Run an interactive container**

As in the previous section, start an interactive container in a terminal.

5. **Run the simulation**

In a terminal outside the container (on the host), start the **turtlebot3** simulation and set the robot's initial position.

6. **Interaction via Docker**

Now, in the container's interactive terminal, see if you can see the topics, services, and actions related to the simulation. Then, send navigation commands in the same way as in the last lesson.









