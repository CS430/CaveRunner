#include "PlayState.h"

#include <GLFW\glfw3.h>

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

}

void PlayState::render() {

}

void PlayState::handleInput() {

}