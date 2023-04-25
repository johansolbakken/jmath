add_executable(constant main.cpp)
target_link_libraries(constant PRIVATE jmath)
target_include_directories(constant PRIVATE ${CMAKE_SOURCE_DIR}/include)