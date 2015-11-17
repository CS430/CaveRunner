#include "State.h"

#include <GLFW\glfw3.h>

#ifndef PAUSE_STATE_H
#define PAUSE_STATE_H

class PauseState : public State {
public:
	PauseState(StateManager* sm, GLFWwindow* window);
	~PauseState();

	void init();
	void update();
	void render();
	void handleInput();

private:
	StateManager* stateManager;
	GLFWwindow* window;
};

#endif