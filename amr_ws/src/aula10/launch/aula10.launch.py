import launch
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import os
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    talker_node = Node(
        package='demo_nodes_cpp',
        executable='talker',
        name='talker_remap',
        remappings=[('/chatter', '/new_chatter')]
    )

    listener_node = Node(
        package='demo_nodes_cpp',
        executable='listener',
        name='listener_remap',
        remappings=[('/new_chatter', '/chatter')]
    )

    talker_listener_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource([
            os.path.join(get_package_share_directory('demo_nodes_cpp'), 'launch', 'topics', 'talker_listener.launch.py')
        ])
    )

    return launch.LaunchDescription([
        talker_node,
        listener_node,
        talker_listener_launch
    ])
    