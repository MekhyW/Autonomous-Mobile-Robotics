# Path Planners

In this exercise you will visualize and understand the difference between the two route planning algorithms discussed in class, **Dijkstra** and **A\***.

The default route planner used by **Nav2** is **NavFnPlanner**, configured in the ```planner_server``` section of the **Nav2** configuration file.

```yaml
planner_server:
  ros__parameters:
    expected_planner_frequency: 20.0
    use_sim_time: True
    planner_plugins: ["GridBased"]
    GridBased:
      plugin: "nav2_navfn_planner/NavfnPlanner"
      tolerance: 0.5
      use_astar: false
      allow_unknown: true
```

This planner can use both algorithms presented, and by default it uses **Dijkstra**. To use the **A\*** algorithm, simply set the ```use_astar``` parameter to ```true```

## 1. Comparing algorithms

The main objective of this exercise will be to compare the time the algorithm takes to calculate the desired route and the total distance of the calculated route. To do this, follow the next steps.

### 1.1 Define navigation points

To accurately compare the two algorithms, define 3 navigation points for the route to be calculated. Each point must contain an ```x, y``` position value and an **orientation**.

### 1.2 Start the simulation

As in the last lessons, in a terminal, start the **turtlebot3** simulation and define its starting point.

### 1.3 Calculate planning times

To see the processing time of the ```planner_server```, we will send the planning command directly through the terminal.

In a new terminal, type the following command:

```bash
ros2 action send_goal /compute_path_to_pose nav2_msgs/action/ComputePathToPose \"{pose: {header: {frame_id: map}, pose: {position: {x: 0.0, y: 0.0, z: 0.0}, orientation: {w: 1.0}}}}\"
``` 

Replacing the position and orientation values ​​with the desired point. You should see in **rviz** that the route to the objective has been made, while in the terminal each point of the path is shown and, at the end, how long it took to complete the planning.

Note this number and repeat the process at least 5 times for the same point. At the end, take an average of the values.

Do the same with the other chosen points.

### 1.4 Changing the algorithm

In the **Nav2** configuration file, set the ```use_astar``` parameter of ```planner_server``` to ```true```. Then repeat the above procedure.

### 1.5 Comparing results

Compare the results obtained for each point using each of the algorithms.