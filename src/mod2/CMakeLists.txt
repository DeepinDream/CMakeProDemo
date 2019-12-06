cmake_minimum_required(VERSION 3.5.0)

file(GLOB_RECURSE MOD2_SRCS *.cpp)

# STATIC: 生成静态库
add_library(Mod2 STATIC ${MOD2_SRCS})