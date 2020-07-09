#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <optional>
#include <vector>
#include <array>
#include <string>

class VulkanDriver;

class SwapChainUtils
{
public:
    struct SwapChainSupportDetails
    {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };

    SwapChainUtils(VulkanDriver* vulkanDriver)
    {
        this->driver = vulkanDriver;
    }

    void createSwapChain(VkPhysicalDevice physicalDevice, VkDevice device, VkSurfaceKHR surface, size_t framebufferWidth, size_t framebufferHeight);
    void createImageViews(VkDevice device);
    void createFramebuffers(VkDevice device, VkRenderPass renderPass);

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device, VkSurfaceKHR surface);

    void recreateSwapChain();
    void cleanupSwapChain(VkDevice device);

    VkExtent2D GetExtent()
    {
        return swapChainExtent;
    }

    VkFormat GetFormat()
    {
        return swapChainImageFormat;
    }

    size_t GetImageViewsCount()
    {
        return swapChainImageViews.size();
    }

    size_t GetImagesCount()
    {
        return swapChainImages.size();
    }

    VkSwapchainKHR swapChain;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;
    std::vector<VkImage> swapChainImages;
    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;


private:
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR> &availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR> &availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities, size_t framebufferWidth, size_t framebufferHeight);
    VulkanDriver* driver;
};