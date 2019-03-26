cmake_minimum_required(VERSION 3.4.1)

add_library( native-lib SHARED native-lib.cpp)

include_directories(include)
add_library(lib_opencv SHARED IMPORTED)
set_target_properties(lib_opencv PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/libopencv_java4.so)

find_library( log-lib log)

target_link_libraries( native-lib

        lib_opencv
        ${log-lib})