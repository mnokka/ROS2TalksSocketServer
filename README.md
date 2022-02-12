# ROS2TalksSocketServer
ROS2 publisher node , sends also same message to (localhost) socket server (port 3000). 
<br>
<br>
Build shell:<br>
    cd <ROS2 area / src > <br>
    source /opt/ros/galactic/setup.bash <br>
    colcon build --packages-select talktoqt  --event-handlers console_direct+  <br>
<br>

New running shell: <br>
 cd <ROS2 area / src > <br>
 source /opt/ros/galactic/setup.bash <br>
 . install/local_setup.bash <br>
 ros2 run talktoqt qttalker <br>
<br>

Clean:  <br>
    <ROS2 area / src >  <br>
    rm -rf build install log <br>
