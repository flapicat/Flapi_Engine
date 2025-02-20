#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game
{
public:
	Game();
	~Game();

	void init();
	void run();
	void input(GLFWwindow* window);
	void close();
private:

};

