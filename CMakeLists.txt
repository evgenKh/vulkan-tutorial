cmake_minimum_required(VERSION 3.7)

# set the project name and version
project(Tutorial)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Tutorial)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")
set(CMAKE_BUILD_TYPE Debug)

set(HEADERS_DIRS "src")

set(SOURCES "src/main.cpp"
            "src/QueueUtils.cpp"
            "src/SwapChainUtils.cpp"
            "src/VulkanDriver.cpp"
            "src/Application.cpp" )

set(HEADERS  "src/stb_image.h"
            "src/QueueUtils.h"
            "src/SwapChainUtils.h"
            "src/VulkanDriver.h"
            "src/Application.h")

add_executable(Tutorial ${HEADERS} ${SOURCES} )

set(GLFW_PATH "/home/kharj/Projects/Onboarding/glfw/bin/bin-x64")
set(GLM_PATH "/home/kharj/Projects/Onboarding/glm")
find_package(glfw3 REQUIRED PATHS ${GLFW_PATH})
#find_package(glm REQUIRED PATHS ${GLM_PATH})
find_package(Vulkan REQUIRED)

#Includes
target_include_directories(Tutorial PRIVATE ${HEADERS_DIRS})  
target_include_directories(Tutorial PRIVATE ${GLM_PATH})

#Link libs
target_link_libraries(Tutorial glfw)
target_link_libraries(Tutorial Vulkan::Vulkan)
