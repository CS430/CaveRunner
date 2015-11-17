#include "State.h"

#ifndef PLAYSTATE_H
#define PLAYSTATE_H

class PlayState : public State {
public:
	PlayState(StateManager* sm);
	~PlayState();

	void init();
	void update();
	void render();
	void handleInput();

private:
	StateManager* stateManager;
};

#endif