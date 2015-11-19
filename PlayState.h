#include "State.h"

#include <GLFW\glfw3.h>

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

class PlayState : public State {
public:
	PlayState(StateManager* sm, GLFWwindow* window);
	~PlayState();

	void init();
	void update();
	void handleInput();

private:
	StateManager* stateManager;
	GLFWwindow* window;

	float red;
};

#endif