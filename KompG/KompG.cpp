#include <cstdio>
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#define GLEW_DLL
#define GLFW_DLL


int main()
{
    glfwInit();
    // printf("Hello World!\n");

    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW. \n");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;
    window = glfwCreateWindow(512, 512, "window", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    GLenum ret = glewInit();
    if (GLEW_OK != ret) {
        fprintf(stderr, "ERROR: %s\n", glewGetErrorString(ret));
        return 1;
    }

    while (!glfwWindowShouldClose(window)) {
        glClearColor(1.0, 1.0, 0.5, 1);
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3f(0.2, 0.4, 1.0);
        glVertex2f(0.0, 1.0);  // Верхняя вершина
        glVertex2f(0.866, 0.5);  // Вершина справа сверху
        glVertex2f(0.866, -0.5); // Вершина справа снизу
        glVertex2f(0.0, -1.0);  // Нижняя вершина
        glVertex2f(-0.866, -0.5); // Вершина слева снизу
        glVertex2f(-0.866, 0.5);  // Вершина слева сверху
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();


}