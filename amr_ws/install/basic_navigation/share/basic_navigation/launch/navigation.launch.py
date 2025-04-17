from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration

def generate_launch_description():
    wall_distance_threshold = LaunchConfiguration('wall_distance_threshold', default='0.5')
    forward_speed = LaunchConfiguration('forward_speed', default='0.2')
    rotation_angle = LaunchConfiguration('rotation_angle', default='90.0')
    rotation_speed = LaunchConfiguration('rotation_speed', default='0.5')
    ld = LaunchDescription()
    ld.add_action(DeclareLaunchArgument('wall_distance_threshold', default_value='0.5'))   
    ld.add_action(DeclareLaunchArgument('forward_speed', default_value='0.2')) 
    ld.add_action(DeclareLaunchArgument('rotation_angle',default_value='90.0'))
    ld.add_action(DeclareLaunchArgument('rotation_speed', default_value='0.5'))
    main_node = Node(
    package='basic_navigation',
    executable='main_node',  # este é o nome do entry point, não do .py
    name='main_navigation_node',
    parameters=[{
        'wall_distance_threshold': wall_distance_threshold,
        'forward_speed': forward_speed,
        'rotation_angle': rotation_angle
    }],
    output='screen'
)

    rotation_server = Node(
        package='basic_navigation',
        executable='rotation_action_server',  # idem
        name='rotation_action_server',
        parameters=[{
            'rotation_speed': rotation_speed
        }],
        output='screen'
    )

    ld.add_action(main_node)
    ld.add_action(rotation_server)
    return ld