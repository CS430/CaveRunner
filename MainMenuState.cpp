#include "MainMenuState.h"

MainMenuState::MainMenuState(StateManager* sm, GLFWwindow* window, Keys* keys) : 
	stateManager(sm),
	window(window),
	keys(keys) {

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
		keys->keyPressed(Keys::ENTER);

		if (keys->uniquePress(Keys::ENTER)) {
			stateManager->loadState(StateManager::PLAY);
		}
	}

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		keys->keyPressed(Keys::ESC);

		if (keys->uniquePress(Keys::ESC)) {
			glfwDestroyWindow(window);
			glfwTerminate();
		}
	}

	keys->update();
}