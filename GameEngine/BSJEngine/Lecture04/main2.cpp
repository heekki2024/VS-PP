#include <GLFW/glfw3.h>
#include <iostream>
#include <iomanip> // std::fixed와 std::setprecision을 위해 필요

void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
    std::cout << std::fixed << std::setprecision(2); // 소수점 이하 두 자리까지 출력
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

    // 마우스 커서의 위치를 추적하는 콜백 함수를 설정합니다.
    glfwSetCursorPosCallback(window, cursorPositionCallback);

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}