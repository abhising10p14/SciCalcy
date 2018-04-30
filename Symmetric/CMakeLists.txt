cmake_minimum_required(VERSION 3.0)
add_compile_options(-std=c++11) 
project(Symmetric_lib)

add_library(Symmetric STATIC ./src/Symmetric.cpp)
install(TARGETS Symmetric DESTINATION lib)
install(FILES ./src/Symmetric.h DESTINATION include)
install(FILES ./src/Symmetric.cpp DESTINATION include)