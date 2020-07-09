#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <optional>
#include <vector>
#include <array>
#include <string>

class VulkanDriver;

class ImageUtils
{
public:
    ImageUtils(VulkanDriver* vulkanDriver)
    {
        this->driver = vulkanDriver;
    }

    void createTextureImage(VkDevice device);
    void createTextureImageView();
    void createTextureSampler();

    void cleanup(VkDevice device);

    VkImageView& GetTextureImageView(){
        return textureImageView;
    }
    VkSampler& GetTextureSampler()
    {
        return textureSampler;
    }


private:
    void createImageInternal(uint32_t width, uint32_t height,
        VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties,
        VkImage& image, VkDeviceMemory& imageMemory);
    void transitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);
    void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);

    VkImage textureImage;
    VkDeviceMemory textureImageMemory;
    VkImageView textureImageView;
    VkSampler textureSampler;

    VulkanDriver* driver;
};