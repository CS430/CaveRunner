#include "State.h"
#include "Player.h"

#include <GLFW\glfw3.h>

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

class PlayState : public State {
public:
	PlayState(StateManager* sm, GLFWwindow* window, Keys* keys);
	~PlayState();

	void init();
	void update();
	void handleInput();

private:
	StateManager* stateManager;
	GLFWwindow* window;
	Player* player;
	Keys* keys;

	float red;
};

#endif