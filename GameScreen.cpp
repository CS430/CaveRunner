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

	while (glfwWindowShouldClose(window) == 0 && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS) {
		//update();
		render();

		handleInput();
	}

	end();
}

void GameScreen::initSystems() {
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

	/*----------------------------------------------------*/
	//INIT GLEW
	/*----------------------------------------------------*/
	GLenum err = glewInit();

	if (err != GLEW_OK) {
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		exit(EXIT_FAILURE);
	}

	StateManager stateManager;
	stateManager.loadState(StateManager::INTRO);

	glClearColor(0.0, 0.0, 0.0, 0.0);

	/*----------------------------------------------------*/
	//INIT VAO
	/*----------------------------------------------------*/
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
}

void GameScreen::update() {
	//stateManager.update();
	//Keys.update()
}

void GameScreen::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//stateManager.render();
	glfwSwapBuffers(window);
}

void GameScreen::draw() {

}

void GameScreen::handleInput() {
	glfwPollEvents();
	/*
	Check if the butten pressed is within our input class
	if so handlie in input class

	we should look into glfwSetKeyCallback(window, name_of_callback_function)

	if (keys.contains(glfwGetKey(window, ) {

	}
	*/
}

void GameScreen::end() {
	glfwDestroyWindow(window);
	glfwTerminate();
}