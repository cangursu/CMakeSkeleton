
cmake_minimum_required(VERSION 3.14)

project(CMakeSkeleton)

include_directories(inc)

file(GLOB_RECURSE HEADER "inc/*.hpp" "inc/*.h")
file(GLOB_RECURSE SOURCE "src/*.cpp" "src/*.c")

set(CMAKE_CXX_FLAGS '-g')
# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} ${SOURCE} ${HEADER})

source_group("Header include" FILES ${HEADER})
source_group("Source src"     FILES ${SOURCE})

# link libraries
# target_link_libraries(${PROJECT_NAME} -lpthread -lboost_system -lssl -lcrypto -lrt)
