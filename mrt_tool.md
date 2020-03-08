```shell
mkdir lanelet_example
mrt ws init
mrt pkg create globalplanner
mrt pkg create_executable example // create a node
mrt ws resolve_deps
mrt catkin build -rd


```