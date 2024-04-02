#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>

bool isDragging = false;

// 마우스 이동 콜백 함수
void cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
    if (isDragging) {
        // 드래그 중이면 배경을 빨간색으로 변경
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
}

// 마우스 버튼 콜백 함수
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        if (action == GLFW_PRESS) {
            isDragging = true; // 마우스 드래그 시작
        }
        else if (action == GLFW_RELEASE) {
            isDragging = false; // 마우스 드래그 종료
            // 드래그가 끝나면 배경을 검은색으로 변경
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }
    }
}

int main(void) {
    GLFWwindow* window;

    // GLFW 라이브러리 초기화
    if (!glfwInit()) {
        return -1;
    }

    // GLFW 윈도우 생성
    window = glfwCreateWindow(640, 480, "Drag to Change Background Color", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    // 생성된 윈도우를 현재 컨텍스트로 설정
    glfwMakeContextCurrent(window);

    // 콜백 함수 설정
    glfwSetCursorPosCallback(window, cursor_position_callback); // 마우스 이동 콜백
    glfwSetMouseButtonCallback(window, mouse_button_callback); // 마우스 버튼 콜백

    // 초기 배경색 설정
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // 윈도우가 닫힐 때까지 루프
    while (!glfwWindowShouldClose(window)) {
        // 다른 렌더링 명령을 여기에 넣을 수 있음

        // 스왑 버퍼
        glfwSwapBuffers(window);

        // 폴 이벤트
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}