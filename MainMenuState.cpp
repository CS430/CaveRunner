#include "MainMenuState.h"

MainMenuState::MainMenuState(StateManager* sm, GLFWwindow* window) : 
	stateManager(sm),
	window(window) {

}

MainMenuState::~MainMenuState() {

}

void MainMenuState::init() {
	glClearColor(0.5f, 0.2f, 0.3f, 0.0f);
}

void MainMenuState::update() {
	handleInput();
}

void MainMenuState::handleInput() {
	if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
		stateManager->loadState(StateManager::PLAY);
	}

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwDestroyWindow(window);
		glfwTerminate();
	}
}