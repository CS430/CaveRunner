#include "IntroState.h"

IntroState::IntroState(StateManager* sm, GLFWwindow* window) : 
	stateManager(sm), 
	window(window),
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
}