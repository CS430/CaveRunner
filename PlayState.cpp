#include <GL\glew.h>

#include "PlayState.h"
#include "Player.h"
#include "Keys.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

PlayState::PlayState(StateManager* sm, GLFWwindow* window, Keys* keys) :
	stateManager(sm),
	window(window),
	keys(keys),
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
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		keys->keyPressed(Keys::ESC);

		stateManager->loadState(StateManager::PAUSED);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		keys->keyPressed(Keys::D);

		if (player->getXAccel() < player->maxPlayerSpeed) {
			player->setXAccel(player->playerAcccel);
		}
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		keys->keyPressed(Keys::A);

		if (player->getXAccel() > -player->maxPlayerSpeed) {
			player->setXAccel(-player->playerAcccel);
		}
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		keys->keyPressed(Keys::W);

		if (player->getYPos() <= 0.0f) {
			player->setYAccel(player->jumpAccel);
		}
		else if (keys->uniquePress(Keys::W)) {
			if (!player->getHasDoubleJumped()) {
				player->setYAccel(player->jumpAccel);
				player->setHasDoubleJumped(true);
			}
		}
	}

	keys->update();
}