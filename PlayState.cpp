#include "PlayState.h"

PlayState::PlayState(StateManager* sm, GLFWwindow* window) :
	stateManager(sm),
	window(window) {

}

PlayState::~PlayState() {

}

void PlayState::init() {
	glClearColor(0.25f, 0.1f, 0.15f, 0.0f);
}

void PlayState::update() {
	handleInput();
}

void PlayState::render() {

}

void PlayState::handleInput() {
	glfwPollEvents();

	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
		stateManager->loadState(StateManager::PAUSED);
	}

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		stateManager->loadState(StateManager::MAINMENU);
	}
}