#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>

bool isDragging = false;

// ���콺 �̵� �ݹ� �Լ�
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    if (isDragging) {
        // �巡�� ���̸� ����� ���������� ����
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

// ���콺 ��ư �ݹ� �Լ�
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if (action == GLFW_PRESS) {
            isDragging = true; // ���콺 �巡�� ����
        }
        else if (action == GLFW_RELEASE) {
            isDragging = false; // ���콺 �巡�� ����
            // �巡�װ� ������ ����� ���������� ����
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }
    }
}

int main(void) {
    GLFWwindow* window;

    // GLFW ���̺귯�� �ʱ�ȭ
    if (!glfwInit()) {
        return -1;
    }

    // GLFW ������ ����
    window = glfwCreateWindow(640, 480, "Drag to Change Background Color", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // ������ �����츦 ���� ���ؽ�Ʈ�� ����
    glfwMakeContextCurrent(window);

    // �ݹ� �Լ� ����
    glfwSetCursorPosCallback(window, cursor_position_callback); // ���콺 �̵� �ݹ�
    glfwSetMouseButtonCallback(window, mouse_button_callback); // ���콺 ��ư �ݹ�

    // �ʱ� ���� ����
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // �����찡 ���� ������ ����
    while (!glfwWindowShouldClose(window)) {
        // �ٸ� ������ ����� ���⿡ ���� �� ����

        // ���� ����
        glfwSwapBuffers(window);

        // �� �̺�Ʈ
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}