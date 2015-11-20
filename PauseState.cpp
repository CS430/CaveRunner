#include "PauseState.h"

PauseState::PauseState(StateManager* sm, GLFWwindow* window, Keys* keys) : 
	stateManager(sm),
	window(window),
	keys(keys) {

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
		keys->keyPressed(Keys::ESC);

		if (keys->uniquePress(Keys::ESC)) {
			stateManager->loadState(StateManager::MAINMENU);
		}
	}

	if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS) {
		keys->keyPressed(Keys::ENTER);

		stateManager->loadState(StateManager::PLAY);
	}

	keys->update();
}