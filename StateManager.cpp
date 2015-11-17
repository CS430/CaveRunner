#include "StateManager.h"
#include "IntroState.h"
#include "PlayState.h"
#include "PauseState.h"
#include "MainMenuState.h"

#include <iostream>

StateManager::StateManager() {

}

StateManager::~StateManager() {
}

void StateManager::init() {
	gameStates = { nullptr, nullptr, nullptr, nullptr };

	loadState(StateManager::INTRO);
}

void StateManager::loadState(int state) {
	previousState = currentState;
	currentState = state;
	unloadState(previousState);

	switch (state) {
		case INTRO:
			gameStates[state] = new IntroState(this);
			break;

		case MAINMENU:
			gameStates[state] = new MainMenuState(this);
			break;

		case PLAY:
			gameStates[state] = new PlayState(this);
			break;

		case PAUSED:
			gameStates[state] = new PauseState(this);
			break;
	}

	gameStates[currentState] -> init();

	fprintf(stdout, "State Loaded");
}

void StateManager::unloadState(int state) {

}

void StateManager::update() {
	gameStates[currentState] -> update();
}

void StateManager::render() {
	
}