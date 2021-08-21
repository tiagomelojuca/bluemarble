#include <iostream>
#include <cassert>

#include <GLFW/glfw3.h>

const int Width = 800;
const int Height = 600;

int main()
{
    glfwInit();
    GLFWwindow* Window = glfwCreateWindow(Width, Height, "Blue Marble", nullptr, nullptr);

    while(!glfwWindowShouldClose(Window)) {
        glfwPollEvents();
        glfwSwapBuffers(Window);
    }

    glfwTerminate();
    return 0;
}
