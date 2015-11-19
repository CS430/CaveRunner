#include "Entity.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Entity {
public:
	Player(float xPos, float yPos);
	~Player();

	void init();
	void update();
	float getXPos();
	float getYPos();
	void setXPos(float x);
	void setYPos(float y);
	void setYAccel(float y);
private:
	const float zPos = 0.0f;
	float xPos;
	float yPos;
	float xAccel;
	float yAccel;
};

#endif