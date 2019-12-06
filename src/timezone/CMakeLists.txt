cmake_minimum_required(VERSION 3.5.0)

file(GLOB_RECURSE TZ_SRCS *.cpp)

# STATIC: 生成静态库
add_library(TimeZone STATIC ${TZ_SRCS})

set(CURL_LIBRARY "-lcurl") 
find_package(CURL REQUIRED) 
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(TimeZone ${CURL_LIBRARIES})