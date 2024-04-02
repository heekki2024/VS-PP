#pragma comment(lib, "Opengl32.lib")


#include <iostream>
#include <GLFW/glfw3.h>

//과제물 프로젝트명 : Lecture04_HW
//idle : 화면색 검정색으로 clear
//마우스 오른쪽 keyDown하면 : 빨간색
//마우스 오른쪽 keyUp하면 : 원상복구
//마우스 왼쪽 keyDown하면 : 녹색
//마우스 왼쪽 keyUp하면 : 원상복구
//마우스 오른쪽 keyDown하고 드래그 중이면 : 파랑색
//마우스 왼쪽 keyDown하고 드래그 중이면 : 마젠타색


void errorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error:" << description << std::endl;
}


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) 

{
	if (key = GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}


	class MousePos
	{
	public:
		MousePos() : oldXpos{0}, oldYpos{0}
		{}
	
		double GetXpos()
		{
			return oldXpos;
		}
		double GetYpos()
		{
			return oldYpos;
		}
		
		void SetXpos(double currentXpos)
		{
			oldXpos = currentXpos;
		}
		void SetYpos(double currentYpos)
		{
			oldYpos = currentYpos;
		}

	private:
		double oldXpos;
		double oldYpos;

	};


	bool firstclick = false;
	double currentXpos = 0;
	double currentYpos = 0;

void mouseLeftRightInput(GLFWwindow* window,bool & leftKeyPress, bool & rightKeyPress, MousePos & mousePos)
{

	int Lstate = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);
	int Rstate = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);

	if (Lstate == GLFW_PRESS)
	{

		std::cout << "마우스 왼쪽키" << std::endl;

		
		
		glfwGetCursorPos(window, &currentXpos, &currentYpos);
		if (firstclick == false)
		{
			mousePos.SetXpos(currentXpos);
			mousePos.SetYpos(currentYpos);
			firstclick = true;
		}

		std::cout << "currentXpos" << currentXpos << std::endl;
		std::cout << "currentYpos" << currentYpos << std::endl;
	
		std::cout << "oldXpos" << mousePos.GetXpos() << std::endl;
		std::cout << "oldYpos" << mousePos.GetYpos() << std::endl;


			
		if ((currentXpos == mousePos.GetXpos()) && (currentYpos == mousePos.GetYpos()))
		{
			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		}
		else
		{
			glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
			std::cout << "드래깅 파란색" << std::endl;

			
		}


		mousePos.SetXpos(currentXpos);
		mousePos.SetYpos(currentYpos);
		

		leftKeyPress = true;

	}
	else if (Lstate == GLFW_RELEASE && leftKeyPress == true)
	{
		std::cout << "마우스 왼쪽키 up" << std::endl;
		firstclick = false;

		leftKeyPress = false;

	}

	if (Rstate == GLFW_PRESS)
	{
		std::cout << "마우스 오른쪽키" << std::endl;

		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		rightKeyPress = true;

	}
	else if (Rstate == GLFW_RELEASE && rightKeyPress == true)
	{
		std::cout << "마우스 오른쪽키 up" << std::endl;

		rightKeyPress = false;
	}


}

void mouseLeftRightDragInput(GLFWwindow* window) {


	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

};

int main(void)
{

	/*Initialize the library*/
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "BSJEngine", NULL, NULL);
	

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/*Make the window's context current*/
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);
	//glfwSetMouseButtonCallback(window, mouse_button_callback);

	bool leftKeyPress = false;
	bool rightKeyPress = false;
	bool firstClick = false;
	
	double currentXpos, currentYpos;

	MousePos mousePos;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{

		glfwPollEvents();

		//glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		// 마우스 커서의 현재 위치를 가져옴



		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		mouseLeftRightInput(window, leftKeyPress, rightKeyPress, mousePos);

		glClear(GL_COLOR_BUFFER_BIT);


		/*Swap frint and back buffers */
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

