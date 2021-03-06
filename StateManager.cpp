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

void StateManager::init(GLFWwindow* win, Keys* k) {
	gameStates = { nullptr, nullptr, nullptr, nullptr };
	window = win;
	keys = k;

	loadState(StateManager::INTRO);
}

void StateManager::loadState(int state) {
	unloadState(currentState);
	currentState = state;

	switch (state) {
		case INTRO:
			gameStates[state] = new IntroState(this, window, keys);
			break;

		case MAINMENU:
			gameStates[state] = new MainMenuState(this, window, keys);
			break;

		case PLAY:
			gameStates[state] = new PlayState(this, window, keys);
			break;

		case PAUSED:
			gameStates[state] = new PauseState(this, window, keys);
			break;
	}

	gameStates[currentState] -> init();

	fprintf(stdout, "State Loaded");
}

void StateManager::unloadState(int state) {

}

void StateManager::update() {
	gameStates[currentState]->update();
}

void StateManager::handleInput() {
	gameStates[currentState]->handleInput();
}