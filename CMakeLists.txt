cmake_minimum_required(VERSION 3.17)
project(CodeGeneration)

set(CMAKE_CXX_STANDARD 20)

add_custom_command(
        OUTPUT ${CMAKE_SOURCE_DIR}/GeneratedArray.h
        COMMAND python3 ${CMAKE_SOURCE_DIR}/generator.py ${CMAKE_SOURCE_DIR}/map.png ${CMAKE_SOURCE_DIR}/GeneratedArray.h
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        DEPENDS ${CMAKE_SOURCE_DIR}/generator.py
)

add_custom_target(RunGenerator DEPENDS ${CMAKE_SOURCE_DIR}/GeneratedArray.h COMMENT "Checking if re-generation is required" )


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(WithoutGeneration WithoutGeneration.cpp)
target_link_libraries(WithoutGeneration ${OpenCV_LIBS})


add_executable(WithCodeGeneration WithCodeGeneration.cpp)
add_dependencies(WithCodeGeneration RunGenerator)
target_include_directories(WithCodeGeneration PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(WithCodeGeneration ${OpenCV_LIBS})




