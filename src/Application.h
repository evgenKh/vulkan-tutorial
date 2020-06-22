#pragma once

#include <memory>

class GLFWwindow;
class VulkanDriver;

class HelloTriangleApplication
{
public:
    HelloTriangleApplication();
    ~HelloTriangleApplication();

    void run();

private:
    static void framebufferResizeCallback(GLFWwindow *window, int width, int height);

    void initWindow();
    void mainLoop();
    void drawFrame();
    void cleanup();

    GLFWwindow*                     glfwWindow{ nullptr };
    std::unique_ptr<VulkanDriver>   vulkanDriver;
    bool isFramebufferResized = false;
};