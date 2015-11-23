#include <GL\glew.h>

#include "PlayState.h"
#include "Player.h"
#include "Keys.h"
#include "GLSLProgram.h"
#include "GameScreen.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

GLSLProgram shaders;
GLuint vertexbuffer;

PlayState::PlayState(StateManager* sm, GLFWwindow* window, Keys* keys) :
	stateManager(sm),
	window(window),
	keys(keys),
	player(new Player(0.0f, 0.0f, 0.05f, 0.015f)) {
	GLfloat vertices[6][2] = {
		{ -0.075f, -1.0f },
		{ -0.075f, -0.9f },
		{ 0.0f, -1.0f },
		{ -0.075f, -0.9f },
		{ 0.0f, -0.9f },
		{ 0.0f, -1.0f }
	};

	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(12), vertices, GL_STATIC_DRAW);
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

	// Get a handle for our "MVP" uniform
	GLuint MatrixID = glGetUniformLocation(shaders.getProgramId(), "MVP");

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	glm::mat4 Projection = glm::perspective(3.0f, (float) GameScreen::WIDTH / GameScreen::HEIGHT, 0.1f, 100.0f);

	// Camera matrix
	glm::mat4 View = glm::lookAt(
		glm::vec3(3, 3, -3), // Camera is at (4,3,-3), in World Space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
		);
	// Model matrix : an identity matrix (model will be at the origin)
	glm::mat4 Model = glm::mat4(1.0f);

	Model = Model * glm::mat4(player->getXPos(), player->getYPos(), 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, player->getXPos(), player->getYPos(), 0, 1);

	// Our ModelViewProjection : multiplication of our 3 matrices
	glm::mat4 MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around

	shaders.use();

	// Send our transformation to the currently bound shader,
	// in the "MVP" uniform
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void *)0            // array buffer offset
		);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 12 * 3); // 12*3 indices starting at 0 -> 12 triangles

	glDisableVertexAttribArray(0);
}

void PlayState::handleInput() {
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		keys->keyPressed(Keys::S);

		player->setIsCrouching(true);
	}

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		keys->keyPressed(Keys::ESC);

		stateManager->loadState(StateManager::PAUSED);
	}

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		keys->keyPressed(Keys::D);

		if (!player->getIsCrouching() && player->getXAccel() < player->maxPlayerSpeed) {
			player->setXAccel(player->playerAcccel);
		}
	}

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		keys->keyPressed(Keys::A);

		if (!player->getIsCrouching() && player->getXAccel() > -player->maxPlayerSpeed) {
			player->setXAccel(-player->playerAcccel);
		}
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		keys->keyPressed(Keys::W);

		if (!player->getIsCrouching()) {
			if (player->getYPos() - player->getHeight() <= -1.0f) {
				player->setYAccel(player->jumpAccel);
			}
			else if (keys->uniquePress(Keys::W)) {
				if (!player->getHasDoubleJumped()) {
					player->setYAccel(player->jumpAccel);
					player->setHasDoubleJumped(true);
				}
			}
		}
	}

	keys->update();
}