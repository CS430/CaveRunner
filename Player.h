#include "Entity.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Entity {
public:
	Player();
	~Player();

	void init();
	void update();
private:
	const float zPos = 0.0f;
	float xPos;
	float yPos;
};

#endif