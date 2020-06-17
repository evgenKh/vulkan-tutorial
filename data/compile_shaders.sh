export VULKAN_SDK=/home/kharj/Projects/Onboarding/vulkan-sdk/x86_64
export LD_LIBRARY_PATH=$VULKAN_SDK/lib
export VK_LAYER_PATH=$VULKAN_SDK/etc/vulkan/explicit_layer.d

cd shaders
$VULKAN_SDK/bin/glslc shader.vert -o shader_vert.spv
$VULKAN_SDK/bin/glslc shader.frag -o shader_frag.spv