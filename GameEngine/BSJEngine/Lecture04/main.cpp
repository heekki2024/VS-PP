#pragma comment(lib, "Opengl32.lib")


#include <iostream>
#include <GLFW/glfw3.h>

//과제물 프로젝트명 : Lecture04_HW
//idle : 화면색 검정색으로 clear
//마우스 오른쪽 keyDown하면 : 빨간색
//마우스 오른쪽 keyUp하면 : 원상복구
// 
// 
//마우스 왼쪽 keyDown하면 : 녹색
//마우스 왼쪽 keyUp하면 : 원상복구
// 
// 
//마우스 오른쪽 keyDown하고 드래그 중이면 : 파랑색
//마우스 왼쪽 keyDown하고 드래그 중이면 : 마젠타색


void errorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error:" << description << std::endl;
}


void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) 

{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}


	class MousePos
	{
	public:
		MousePos() : oldXpos{0}, oldYpos{0}
		{}
	
		float GetXpos()
		{
			return oldXpos;
		}
		float GetYpos()
		{
			return oldYpos;
		}
		
		void SetXpos(float currentXpos)
		{
			oldXpos = currentXpos;
		}
		void SetYpos(float currentYpos)
		{
			oldYpos = currentYpos;
		}

	private:
		float oldXpos;
		float oldYpos;

	};


	bool firstLeftClick = false;
	bool firstRightClick = false;
	double currentXpos = 0.0;
	double currentYpos = 0.0;
	int smoothDragTimer = 0;
	bool smoothDrag;
	int smoothDragTimerLimit = 500;

void mouseLeftInput(GLFWwindow* window,bool & leftKeyPress , MousePos & mousePos)
{

	int Lstate = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);

	if (Lstate == GLFW_PRESS)
	{

		std::cout << "마우스 왼쪽키" << std::endl;

		glfwGetCursorPos(window, &currentXpos, &currentYpos);
		if (firstLeftClick == false)
		{
			mousePos.SetXpos(currentXpos);
			mousePos.SetYpos(currentYpos);
			firstLeftClick = true;
		}

		std::cout << "currentXpos : " << currentXpos << std::endl;
		std::cout << "currentYpos : " << currentYpos << std::endl;
	
		std::cout << "----oldXpos : " << mousePos.GetXpos() << std::endl;
		std::cout << "----oldYpos : " << mousePos.GetYpos() << std::endl;


			
		if ((currentXpos == mousePos.GetXpos()) && (currentYpos == mousePos.GetYpos()) && smoothDrag == false)
		{

			glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
			std::cout << "초록색------------------------------------------" << std::endl;


		}
		else
		if ((currentXpos == mousePos.GetXpos()) && (currentYpos == mousePos.GetYpos()) && smoothDrag == true)
		{
			smoothDragTimer++;
			
			std::cout << "드래깅 마젠타색@@@@@@@@@@@@@@" << std::endl;
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			std::cout << smoothDragTimer << std::endl;

			if (smoothDragTimer > smoothDragTimerLimit)
			{

				smoothDrag = false;

			}
		}


		else
		{
			smoothDrag = true;
			
			std::cout << "드래깅 파란색@@@@@@@@@@@@@@" << std::endl;
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			
			smoothDragTimer = 0;
		}
		leftKeyPress = true;
	}
	else if (Lstate == GLFW_RELEASE && leftKeyPress == true)
	{
		std::cout << "마우스 왼쪽키 up" << std::endl;
		firstLeftClick = false;
		smoothDrag = false;

		leftKeyPress = false;

	}
}

void mouseRightInput(GLFWwindow* window, bool& leftKeyPress, MousePos& mousePos)
{
	int Rstate = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT);

	if (Rstate == GLFW_PRESS)
	{

		std::cout << "마우스 오른쪽키" << std::endl;

		glfwGetCursorPos(window, &currentXpos, &currentYpos);
		if (firstRightClick == false)
		{
			mousePos.SetXpos(currentXpos);
			mousePos.SetYpos(currentYpos);
			firstRightClick = true;
		}

		std::cout << "currentXpos : " << currentXpos << std::endl;
		std::cout << "currentYpos : " << currentYpos << std::endl;

		std::cout << "----oldXpos : " << mousePos.GetXpos() << std::endl;
		std::cout << "----oldYpos : " << mousePos.GetYpos() << std::endl;



		if ((currentXpos == mousePos.GetXpos()) && (currentYpos == mousePos.GetYpos()) && smoothDrag == false)
		{

			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
			std::cout << "빨간색------------------------------------------" << std::endl;


		}
		else
			if ((currentXpos == mousePos.GetXpos()) && (currentYpos == mousePos.GetYpos()) && smoothDrag == true)
			{
				smoothDragTimer++;

				std::cout << "드래깅 파란색@@@@@@@@@@@@@@" << std::endl;
				glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
				std::cout << smoothDragTimer << std::endl;

				if (smoothDragTimer > smoothDragTimerLimit)
				{

					smoothDrag = false;

				}
			}


			else
			{
				smoothDrag = true;

				std::cout << "드래깅 파란색@@@@@@@@@@@@@@" << std::endl;
				glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

				smoothDragTimer = 0;
			}
		leftKeyPress = true;
	}
	else if (Rstate == GLFW_RELEASE && leftKeyPress == true)
	{
		std::cout << "마우스 오른쪽키 up" << std::endl;
		firstLeftClick = false;
		smoothDrag = false;

		leftKeyPress = false;

	}


}





void mouseLeftRightDragInput(GLFWwindow* window) {


	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

};


class Star
{
public:	Star()
	{

	}

	int Render()
	{


		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0.5f, 1.0f);
		glVertex2f(0.0f, 1.0f);

		glColor3f(1.0f, 0.5f, 1.0f);
		glVertex2f(0.18f, 0.25f);

		glColor3f(1.0f, 0.5f, 1.0f);
		glVertex2f(-0.18f, 0.25f);

		glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(0.18f, 0.25f);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-0.7f, 0.25f);

		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(0.45f, -1.0f);

		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(-0.18f, 0.25f);

		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(0.7f, 0.25f);

		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(-0.45f, -1.0f);

		glEnd();


		return 0;
	}
	
};


int Render()
{
	Star *star1 = new Star();
	star1->Render();

	return 0;
}


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
	
	//double currentXpos, currentYpos;

	MousePos mousePos;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{


		glfwPollEvents();

		//glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		// 마우스 커서의 현재 위치를 가져옴



		
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

		mouseLeftInput(window, leftKeyPress, mousePos);
		mouseRightInput(window, rightKeyPress, mousePos);

		glClear(GL_COLOR_BUFFER_BIT);

		Render();



		/*Swap frint and back buffers */
		glfwSwapBuffers(window);
		mousePos.SetXpos(currentXpos);
		mousePos.SetYpos(currentYpos);

	}

	glfwTerminate();
	return 0;
}


//별 클릭하여 드래그 하면 마우스 따라 움직임. 오른쪽으로 드래그시 크기 커짐 왼쪽으로 드래그시 크기 작아짐