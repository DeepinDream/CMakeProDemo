cmake_minimum_required(VERSION 3.5.0)
project(app VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE HEAD_RIGEL_EDITOR *.h)  #GLOB 获取./include/目录下的*.h 储存在变量HEAD_RIGEL_EDITOR中
file(GLOB_RECURSE MOD1_SRCS ./mod1/*.cpp)

file(GLOB app_SRCS "app.cpp")

add_executable(app ${HEAD_RIGEL_EDITOR} ${MOD1_SRCS} ${app_SRCS})

# 添加库
add_subdirectory(mod2)
target_link_libraries(app Mod2)

# 添加库
add_subdirectory(timezone)
target_link_libraries(app TimeZone)
