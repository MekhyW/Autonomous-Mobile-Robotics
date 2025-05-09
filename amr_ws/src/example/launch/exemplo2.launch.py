import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import ExecuteProcess, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import DeclareLaunchArgument
from launch_ros.actions import Node
from ament_index_python.packages import get_package_prefix
from launch.substitutions import Command, LaunchConfiguration, PathJoinSubstitution

import xacro


def generate_launch_description():

    pkg_box_bot_gazebo = get_package_share_directory('example')
    description_package_name = "example"
    install_dir = get_package_prefix(description_package_name)

    robot_model_path = os.path.join(
        get_package_share_directory('example'))


    xacro_file = os.path.join(robot_model_path, 'urdf', 'exemplo2.xacro')
    # convert XACRO file into URDF
    doc = xacro.parse(open(xacro_file))
    xacro.process_doc(doc)
    params = {'robot_description': doc.toxml(), 'use_sim_time': True}

    robot_state_publisher = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='screen',
        parameters=[params]
    )

    spawn_entity = Node(package='gazebo_ros', executable='spawn_entity.py',
                        arguments=['-entity', 'arm', '-x', '0.0', '-y', '0.0', '-z', '0.0',
                                   '-topic', 'robot_description'],
                        output='screen')
    
    rviz_node = Node(
            package='rviz2',
            executable='rviz2',
            output='screen',
            name='rviz_node',
            parameters=[{'use_sim_time': True}],
        )
                        

    return LaunchDescription([
        #rviz_node,
        robot_state_publisher,
        spawn_entity,
    ])