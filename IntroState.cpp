#include "IntroState.h"

IntroState::IntroState(StateManager* sm) : stateManager(sm), tick(0), alpha(1.f), target(300) {

}

IntroState::~IntroState() {

}

void IntroState::init() {
	//load in image here and probably draw an opengl square
}

void IntroState::update() {
	handleInput();

	if (tick < target / 2){
		alpha -= .0065f;
		tick++;
	}
	else if (tick >= target / 2 && tick < target){
		alpha += .0065f;
		tick++;
	}
	else if (tick >= target){
		stateManager->loadState(StateManager::MAINMENU);
	}
	else{
		fprintf(stderr, "Error: update method - IntorState");
	}
}

void IntroState::render() {

}

void IntroState::handleInput() {
	
		//stateManager->loadState(StateManager::MAINMENU);
	

}