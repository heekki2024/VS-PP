#include <GLFW/glfw3.h>
#include <iostream>
#include <iomanip> // std::fixed�� std::setprecision�� ���� �ʿ�

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    std::cout << std::fixed << std::setprecision(2); // �Ҽ��� ���� �� �ڸ����� ���
    std::cout << "Mouse Position at (" << xpos << " , " << ypos << ")" << std::endl;
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "GLFW Example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // ���콺 Ŀ���� ��ġ�� �����ϴ� �ݹ� �Լ��� �����մϴ�.
    glfwSetCursorPosCallback(window, cursorPositionCallback);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}