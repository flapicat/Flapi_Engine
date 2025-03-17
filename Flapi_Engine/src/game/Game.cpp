#include "Game.h"


Game::Game()
{

}

Game::~Game()
{

}

void Game::init()
{
	m_gameState = GAME;

	m_shaderText.CompileShader("assets/shaders/ShaderText.vert", "assets/shaders/ShaderText.frag");
	m_shader3D.CompileShader("assets/shaders/shader3D.vert", "assets/shaders/shader3D.frag");
	m_shader2D.CompileShader("assets/shaders/shader2D.vert", "assets/shaders/shader2D.frag");

	m_text.init("assets/res/font/Default.ttf", 36);
	m_defaultTexture.loadTexture2D("assets/res/textures/default.png");

	
	m_camera = Engine::Camera(glm::vec3(0.0f,0.0f,2.0f));
	m_testEntity.init();
}

void Game::run()
{
	update();
	render();	
}

void Game::update()
{
	Engine::deltaTime.updateDeltaTime();

	m_camera.update();

	if (m_gameState == MENU)
	{
		glfwSetInputMode(Engine::Window::data.getWindow(), GLFW_CURSOR, GLFW_CURSOR_NORMAL);
	}
	if (m_gameState == GAME)
	{
		glfwSetInputMode(Engine::Window::data.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		if (Engine::Window::data.getMouseMoved() == true)
		{
			m_camera.ProcessMouseMovement(Engine::Window::data.getMouseOffset().x, Engine::Window::data.getMouseOffset().y);
			Engine::Window::data.setMouseMoved(false);
		}
	}
}

void Game::render()
{
	//RENDER
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	//OBJECTS
	m_shader3D.use();
	m_shader3D.setMat4("projection", Engine::Window::data.getProjection3D(m_camera.Zoom));
	m_shader3D.setMat4("view", m_camera.GetViewMatrix());

	m_defaultTexture.bindTexture2D();
	m_testEntity.render(m_shader3D);


	//TEXT (MUST BE RENDERED AT THE END !!!)
	m_shaderText.use();
	m_shaderText.setMat4("projection", Engine::Window::data.getProjection2D());
	m_text.RenderText(m_shaderText, "This is UI text", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));

	//IMGUI
	ImGuiMain();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}



void Game::input(GLFWwindow* window)
{
	if (m_gameState == GAME)
	{
		//FLOATING CAMERA MOVEMENT
		if (Engine::input.IsKeyPressed(Engine::Key::W, window))
			m_camera.ProcessKeyboard(FORWARD, Engine::deltaTime.getDeltaTime());
		if (Engine::input.IsKeyPressed(Engine::Key::S, window))
			m_camera.ProcessKeyboard(BACKWARD, Engine::deltaTime.getDeltaTime());
		if (Engine::input.IsKeyPressed(Engine::Key::A, window))
			m_camera.ProcessKeyboard(LEFT, Engine::deltaTime.getDeltaTime());
		if (Engine::input.IsKeyPressed(Engine::Key::D, window))
			m_camera.ProcessKeyboard(RIGHT, Engine::deltaTime.getDeltaTime());
		if (Engine::input.IsKeyPressed(Engine::Key::E, window))
			m_camera.ProcessKeyboard(UP, Engine::deltaTime.getDeltaTime());
		if (Engine::input.IsKeyPressed(Engine::Key::Q, window))
			m_camera.ProcessKeyboard(DOWN, Engine::deltaTime.getDeltaTime());
		if (Engine::input.IsKeyPressed(Engine::Key::LeftControl, window))
			m_camera.ProcessKeyboard(FAST, Engine::deltaTime.getDeltaTime());
		if (Engine::input.IsKeyPressed(Engine::Key::C, window))
			m_camera.zoom = true;
		if (Engine::input.IsKeyReleased(Engine::Key::C, window))
			m_camera.zoom = false;
		
		if(Engine::input.IsKeyPressed(Engine::Key::KPAdd, window))
		{
			Engine::Window::data.setWindowSize(Engine::Window::data.getWindowWidth() + 1, Engine::Window::data.getWindowHeight() + 1);
		}
	}
}

void Game::ImGuiMain()
{
	int x = Engine::Window::data.getWindowWidth(), y = Engine::Window::data.getWindowHeight();

	//GENERAL INFO
	ImGui::SetNextWindowPos(ImVec2(25, 25), ImGuiCond_Always);
	ImGui::Begin("ImGUI window");
	ImGui::Text("FPS: %.1f", 1.0f / Engine::deltaTime.getDeltaTime());
	ImGui::Text("MS: %f", Engine::deltaTime.getDeltaTime() * 100.0f);
	ImGui::Text("STATE: %s", m_gameState == MENU ? "MENU" : "GAME");
	ImGui::End();

	//WINDOW SIZE SETTINGS

	const char* items[] = { "2560 x 1440", "1920 x 1080", "1600 x 900", "1280 x 720" };
	int current_item = -1;

	ImGui::SetNextWindowSize(ImVec2(170, 150));
	ImGui::SetNextWindowPos(ImVec2(x - ImGui::GetWindowSize().x + 200, 25), ImGuiCond_Always);
	
	ImGui::Begin("Window Resolutions");
	ImGui::Text("Select an item:");
	if (ImGui::ListBox("##listbox", &current_item, items, IM_ARRAYSIZE(items))) {
		if (Engine::Window::data.fullscreen == false)
		{
			if (current_item == 0)
			{
				x = 2560; y = 1440;
				Engine::Window::data.setWindowSize(x, y);
			}
			if (current_item == 1)
			{
				x = 1920; y = 1080;
				Engine::Window::data.setWindowSize(x, y);
			}
			if (current_item == 2)
			{
				x = 1600; y = 900;
				Engine::Window::data.setWindowSize(x, y);
			}
			if (current_item == 3)
			{
				x = 1280; y = 720;
				Engine::Window::data.setWindowSize(x, y);
			}
		}
	}

	bool previousFullscreenState = Engine::Window::data.fullscreen; //MAKEING SURE THAT SCREEN MODE IS CHANGED ONLY ONCE IF CHECKOX WAS CLICKED
	ImGui::Checkbox("Full screen", &Engine::Window::data.fullscreen);
	if (Engine::Window::data.fullscreen != previousFullscreenState)
	{
		if (Engine::Window::data.fullscreen) {
			Engine::Window::data.switchToFullScreen();
		}
		else{
			Engine::Window::data.switchToWindowed();
			Engine::Window::data.centerWindow();
		}
	}
	ImGui::End();
}

void Game::close()
{

}

void Game::switchGameState()
{
	if (m_gameState == MENU)
	{
		m_gameState = GAME;
	}
	else
	{
		m_gameState = MENU;
	}
}
