#include "Player.h"

#include <GL\glew.h>

Player::Player(float xPos, float yPos) : xPos(xPos), yPos(yPos) {

}

Player::~Player() {

}

void Player::init() {

}

void Player::setXPos(float x) {
	xPos = x;
}

float Player::getXPos() {
	return xPos;
}

float Player::getYPos() {
	return yPos;
}

void Player::setYAccel(float y) {
	yAccel = y;
}

void Player::update() {
	yAccel -= 0.00001f;
	yPos += yAccel;

	if (yPos <= 0.0f) {
		yPos = 0.0f;
		yAccel = 0.0f;
	}

	GLfloat v0[] = { -1.0f + xPos, -1.0f + yPos, 0.0f };
	GLfloat v1[] = { 1.0f + xPos, -1.0f + yPos, 0.0f };
	GLfloat v2[] = { 0.0f + xPos, 1.0f + yPos, 0.0f };

	glVertex3fv(v0);
	glVertex3fv(v1);
	glVertex3fv(v2);
}