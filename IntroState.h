#include "State.h"

#include <GLFW\glfw3.h>

#ifndef INTRO_STATE_H
#define INTRO_STATE_H

class IntroState : public State {
public:
	IntroState(StateManager* sm, GLFWwindow* window);
	~IntroState();

	void init();
	void update();
	void handleInput();

private:
	int tick;
	float alpha;
	int target;

protected:
	StateManager* stateManager;
	GLFWwindow* window;
};

#endif