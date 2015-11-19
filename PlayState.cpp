#include <GL\glew.h>

#include "PlayState.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

static const GLfloat g_vertex_buffer_data[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
};

// This will identify our vertex buffer
GLuint vertexbuffer;

PlayState::PlayState(StateManager* sm, GLFWwindow* window) :
	stateManager(sm),
	window(window) {

}

PlayState::~PlayState() {

}

void PlayState::init() {
	glClearColor(0.25f, 0.1f, 0.15f, 0.0f);

	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
}

void PlayState::update() {
	handleInput();

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		  0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		  3,                  // size
		  GL_FLOAT,           // type
		  GL_FALSE,           // normalized?
		  0,                  // stride
		  (void*)0            // array buffer offset
		);
	// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);
}

void PlayState::handleInput() {
	if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
		stateManager->loadState(StateManager::PAUSED);
	}

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		stateManager->loadState(StateManager::MAINMENU);
	}
}