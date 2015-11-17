#include "IntroState.h"

#include <GLFW\glfw3.h>

IntroState::IntroState(StateManager* sm) : stateManager(sm), tick(0), alpha(0.0f), target(7500) {

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
		fprintf(stderr, "Error: update method - IntorState");
	}
}

void IntroState::render() {

}

void IntroState::handleInput() {
	//stateManager->loadState(StateManager::MAINMENU);
}