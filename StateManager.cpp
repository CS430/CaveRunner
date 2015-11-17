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

void StateManager::loadState(int state) {
	previousState = currentState;
	currentState = state;
	unloadState(previousState);


	gameStates.push_back(&IntroState(this));
	gameStates.push_back(&PlayState(this));
	gameStates.push_back(&PauseState(this));
	gameStates.push_back(&MainMenuState(this));

	switch (state) {
		case INTRO:
			gameStates[state] = &IntroState(this);
			break;

		case MAINMENU:
			gameStates[state] = &MainMenuState(this);
			break;

		case PLAY:
			gameStates[state] = &PlayState(this);
			break;

		case PAUSED:
			gameStates[state] = &PauseState(this);
			break;
	}
	gameStates[currentState]->init();

	fprintf(stderr, "State Loaded");
}

void StateManager::unloadState(int state) {

}

void StateManager::update() {

}

void StateManager::render() {
	
}