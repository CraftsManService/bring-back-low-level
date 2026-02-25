#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
typedef std::string string;

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(480, 480, "MyWindow", NULL, NULL);


}