#include "State.h"

#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

class MainMenuState : public State {
public:
	MainMenuState(StateManager* sm);
	~MainMenuState();

	void init();
	void update();
	void render();
	void handleInput();

private:
	StateManager* stateManager;
};

#endif