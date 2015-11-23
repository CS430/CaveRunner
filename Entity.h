#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
	virtual void init() = 0;
	virtual void update() = 0;

private:
	const float zPos = 0.0f;
	float xPos;
	float yPos;
	float height;
	float width;
};

#endif