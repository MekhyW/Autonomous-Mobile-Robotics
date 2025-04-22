import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():

    description_package_name = "robot_description"
    description_package_path = os.path.join(get_package_share_directory(description_package_name))
    world_file_name = 'house'

    # Include the Gazebo launch file, provided by the gazebo_ros package
    gazebo = IncludeLaunchDescription(
                PythonLaunchDescriptionSource([
                    os.path.join(
                    get_package_share_directory('gazebo_ros'), 
                    'launch', 
                    'gazebo.launch.py')]),
                launch_arguments={'world': os.path.join(description_package_path, 'world', world_file_name)}.items()
            )    
    
    return LaunchDescription([
        gazebo,
    ])
