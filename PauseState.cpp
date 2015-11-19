#include "PauseState.h"

PauseState::PauseState(StateManager* sm, GLFWwindow* window) : 
	stateManager(sm),
	window(window) {

}

PauseState::~PauseState() {

}

void PauseState::init() {
	glClearColor(0.125f, 0.05f, 0.075f, 0.0f);
}

void PauseState::update() {
	handleInput();
}

void PauseState::handleInput() {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		stateManager->loadState(StateManager::MAINMENU);
	}

	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
		stateManager->loadState(StateManager::PLAY);
	}
}