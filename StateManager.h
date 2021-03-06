#include <vector>

#include <GLFW\glfw3.h>

#include "Keys.h"

#ifndef STATEMANAGER_H
#define STATEMANAGER_H

class State;
class StateManager {
public:
	const static int INTRO  = 0;
	const static int MAINMENU = 1;
	const static int PAUSED = 2;
	const static int PLAY = 3;

	StateManager();
	~StateManager();

	void loadState(int state);
	void unloadState(int state);
	void init(GLFWwindow* window, Keys* keys);
	void handleInput();

	//called by the gamescreen class in the main game loop;
	void update();

private:
	const static int NUM_OF_STATES = 4;

	int currentState;
	int previousState;

	std::vector<State*> gameStates;

	GLFWwindow* window;
	Keys* keys;
};

#endif