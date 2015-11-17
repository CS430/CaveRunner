#include "State.h"

#include <GLFW\glfw3.h>

#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

class MainMenuState : public State {
public:
	MainMenuState(StateManager* sm, GLFWwindow* window);
	~MainMenuState();

	void init();
	void update();
	void render();
	void handleInput();

private:
	StateManager* stateManager;
	GLFWwindow* window;
};

#endif