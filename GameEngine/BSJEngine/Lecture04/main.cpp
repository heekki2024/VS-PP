#pragma comment(lib, "Opengl32.lib")


#include <iostream>
#include <GLFW/glfw3.h>

//������ ������Ʈ�� : Lecture04_HW
//idle : ȭ��� ���������� clear
//���콺 ������ keyDown�ϸ� : ������
//���콺 ������ keyUp�ϸ� : ���󺹱�
// 
// 
//���콺 ���� keyDown�ϸ� : ���
//���콺 ���� keyUp�ϸ� : ���󺹱�
// 
// 
//���콺 ������ keyDown�ϰ� �巡�� ���̸� : �Ķ���
//���콺 ���� keyDown�ϰ� �巡�� ���̸� : ����Ÿ��


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

		std::cout << "���콺 ����Ű" << std::endl;

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
			std::cout << "�ʷϻ�------------------------------------------" << std::endl;


		}
		else
		if ((currentXpos == mousePos.GetXpos()) && (currentYpos == mousePos.GetYpos()) && smoothDrag == true)
		{
			smoothDragTimer++;
			
			std::cout << "�巡�� ����Ÿ��@@@@@@@@@@@@@@" << std::endl;
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
			
			std::cout << "�巡�� �Ķ���@@@@@@@@@@@@@@" << std::endl;
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
			
			smoothDragTimer = 0;
		}
		leftKeyPress = true;
	}
	else if (Lstate == GLFW_RELEASE && leftKeyPress == true)
	{
		std::cout << "���콺 ����Ű up" << std::endl;
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

		std::cout << "���콺 ������Ű" << std::endl;

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
			std::cout << "������------------------------------------------" << std::endl;


		}
		else
			if ((currentXpos == mousePos.GetXpos()) && (currentYpos == mousePos.GetYpos()) && smoothDrag == true)
			{
				smoothDragTimer++;

				std::cout << "�巡�� �Ķ���@@@@@@@@@@@@@@" << std::endl;
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

				std::cout << "�巡�� �Ķ���@@@@@@@@@@@@@@" << std::endl;
				glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

				smoothDragTimer = 0;
			}
		leftKeyPress = true;
	}
	else if (Rstate == GLFW_RELEASE && leftKeyPress == true)
	{
		std::cout << "���콺 ������Ű up" << std::endl;
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
		// ���콺 Ŀ���� ���� ��ġ�� ������



		
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


//�� Ŭ���Ͽ� �巡�� �ϸ� ���콺 ���� ������. ���������� �巡�׽� ũ�� Ŀ�� �������� �巡�׽� ũ�� �۾���