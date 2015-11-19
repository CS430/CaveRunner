#include <GL\glew.h>

#include "PlayState.h"
#include "Player.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

PlayState::PlayState(StateManager* sm, GLFWwindow* window) :
	stateManager(sm),
	window(window),
	player(new Player(0.0f, 0.0f)) {

}

PlayState::~PlayState() {

}

void PlayState::init() {
	glClearColor(0.25f, 0.1f, 0.15f, 0.0f);
}

void PlayState::update() {
	handleInput();

	glBegin(GL_TRIANGLES); 
	player->update();
	glEnd();
}

void PlayState::handleInput() {
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
		stateManager->loadState(StateManager::PAUSED);
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		player->setXPos(player->getXPos() + 0.001f);
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		player->setXPos(player->getXPos() - 0.001f);
	}

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		if (player->getYPos() <= 0.0f) {
			player->setYAccel(0.002f);
		}
	}

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		stateManager->loadState(StateManager::MAINMENU);
	}
}