#include <fstream>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include "GameScreen.h"
#include "StateManager.h"

GameScreen::GameScreen() {

}

GameScreen::~GameScreen() {

}

void GameScreen::run() {
	initSystems();

	while (glfwWindowShouldClose(window) == 0) {
		update();
		render();
	}

	end();
}

void GameScreen::initSystems() {
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 

	/*----------------------------------------------------*/
	//INIT GLFW
	/*----------------------------------------------------*/
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not initilize GLFW. \n");
		exit(EXIT_FAILURE);
	}

	GameScreen::window = glfwCreateWindow(WIDTH, HEIGHT, TITLE, NULL, NULL);

	if (!window) {
		fprintf(stderr, "ERROR: Failed to open GLFW Window. \n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glewExperimental = true; // Needed in core profile

	/*----------------------------------------------------*/
	//INIT GLEW
	/*----------------------------------------------------*/
	GLenum err = glewInit();

	if (err != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		exit(EXIT_FAILURE);
	}

	/*----------------------------------------------------*/
	//INIT VAO
	/*----------------------------------------------------*/
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	stateManager.init(window);
}

void GameScreen::update() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	stateManager.update();
	//Keys.update()
}

void GameScreen::render() {
	glfwSwapBuffers(window);
	glfwPollEvents();
}

void GameScreen::draw() {

}

void GameScreen::end() {
	glfwDestroyWindow(window);
	glfwTerminate();
}