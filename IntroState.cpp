#include "IntroState.h"

IntroState::IntroState(StateManager* sm, GLFWwindow* window, Keys* keys) : 
	stateManager(sm), 
	window(window),
	keys(keys),
	tick(0), 
	alpha(0.0f), 
	target(7500) {

}

IntroState::~IntroState() {

}

void IntroState::init() {
	//load in image here and probably draw an opengl square
}

void IntroState::update() {
	handleInput();
	
	if (tick < target / 2){
		alpha += 1.0f / (target / 2);
		glClearColor(alpha, 0.0f, 0.0f, 0.0f);

		tick++;
	} else if (tick >= target){
		stateManager -> loadState(StateManager::MAINMENU);
	} else if (tick >= target / 2){
		alpha -= 1.0f / (target / 2);
		glClearColor(alpha, 0.0f, 0.0f, 0.0f);

		tick++;
	} else{
		fprintf(stderr, "Error: update method - IntroState");
	}
}

void IntroState::handleInput() {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	keys->update();
}