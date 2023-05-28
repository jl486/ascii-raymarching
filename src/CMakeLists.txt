#include_directories(../include)
#add_library(vector3 vector3.cpp vector3.h)
#add_library(time time.cpp time.h)

#add_library(vector3 include/vector3.h vector3.cpp)
add_executable(raymarchbin ../main.cpp vector3.cpp)
