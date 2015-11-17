#include "MainMenuState.h"

#include <GLFW\glfw3.h>

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

}

void MainMenuState::render() {

}

void MainMenuState::handleInput() {
	if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
		stateManager->loadState(StateManager::PLAY);
	}
}