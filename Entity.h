#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void handleInput() = 0;

private:
	const float zPos = 0.0f;
	float xPos;
	float yPos;
};

#endif