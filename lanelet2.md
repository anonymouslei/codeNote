##CMakeLists
you can use projects vreated with catkin just like any other
cmake project. you simply use `find_project` with that project and
this will set `<project>_INCLUDE_DIRS`, `<project>_LIBRARIES`
and `<project>_LIBRARY_DIRS`.
to make this work, cmake needs to know where to search for your
package. you can do this either with 