cmake_minimum_required(VERSION 3.0.0)
project(leetcode VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(BUILD_SHARED_LIBS ON)
# find_package(fmt REQUIRED)
add_subdirectory(thirdparty/fmt)
add_definitions(-DLEETCODE)
add_executable(leetcode main.cpp)
target_link_libraries(leetcode fmt)

install(TARGETS leetcode
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib)
install(TARGETS fmt
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
