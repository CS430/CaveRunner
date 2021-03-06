#include "Entity.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player : public Entity {
public:
	Player(float xPos, float yPos, float height, float width);
	~Player();

	const float gravity        = 0.000003f;
	const float friction       = 0.0000005f;
	const float playerAcccel   = 0.000001f;
	const float maxPlayerSpeed = 0.00075f;
	const float jumpAccel      = 0.0015f;

	void init();
	void update();
	float getXPos();
	float getYPos();
	float getXAccel();
	float getHeight();
	void setXPos(float x);
	void setXAccel(float x);
	void setYPos(float y);
	void setYAccel(float y);
	void setHasDoubleJumped(bool j);
	bool getHasDoubleJumped();
	void setIsCrouching(bool c);
	bool getIsCrouching();
private:
	float xPos;
	float yPos;
	float xAccel;
	float yAccel;
	float height;
	float width;
	bool isCrouching;
	bool hasDoubleJumped;
};

#endif