//#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Application.h"
#include "VulkanDriver.h"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

HelloTriangleApplication::HelloTriangleApplication()
{

};
HelloTriangleApplication::~HelloTriangleApplication() = default;

void HelloTriangleApplication::run()
{
    initWindow();

    vulkanDriver.reset( new VulkanDriver() );
    vulkanDriver->initVulkan(WIDTH, HEIGHT, glfwWindow);

    mainLoop();
    cleanup();
}

void HelloTriangleApplication::framebufferResizeCallback(GLFWwindow* window, int width, int height) {
    auto app = reinterpret_cast<HelloTriangleApplication*>(glfwGetWindowUserPointer(window));
    app->isFramebufferResized = true;
}

void HelloTriangleApplication::initWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    //!Disabled dut to crashes
    //glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwWindow = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);

    glfwSetWindowUserPointer(glfwWindow, this);//Pass this to callback
    glfwSetFramebufferSizeCallback(glfwWindow, framebufferResizeCallback);
}


void HelloTriangleApplication::mainLoop()
{
    while (!glfwWindowShouldClose(glfwWindow))
    {
        glfwPollEvents();
        drawFrame();
    }

    //Wait before cleanup
    vulkanDriver->waitDeviceIdle();
}

void HelloTriangleApplication::drawFrame()
{
    vulkanDriver->drawFrame();
};

void HelloTriangleApplication::cleanup()
{
    vulkanDriver->cleanup();
    glfwDestroyWindow(glfwWindow);
    glfwTerminate();
}