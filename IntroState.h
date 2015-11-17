#include "State.h"

#ifndef INTRO_STATE_H
#define INTRO_STATE_H

class IntroState : public State {
public:
	IntroState(StateManager* sm);
	~IntroState();

	void init();
	void update();
	void render();
	void handleInput();

private:

	int tick;
	float alpha;
	int target;

protected:
	StateManager* stateManager;
};

#endif