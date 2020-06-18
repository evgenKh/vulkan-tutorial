Me following https://vulkan-tutorial.com/

To build:
Update following in CMakeLists.txt:

set(GLFW_PATH "/home/kharj/Projects/Onboarding/glfw/bin/bin-x64")
set(GLM_PATH "/home/kharj/Projects/Onboarding/glm")

Update following in 'generate_linux.sh':
export VULKAN_SDK=/home/kharj/Projects/Onboarding/vulkan-sdk/x86_64/      

run 'generate_linux.sh'
cd linux
make
./Tutorial