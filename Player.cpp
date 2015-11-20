#include <iostream>
#include <algorithm>
#include <vector>

#include "Player.h"

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Player::Player(float xPos, float yPos) : xPos(xPos), yPos(yPos) {
	hasDoubleJumped = false;
	xAccel = 0.0f;
	yAccel = 0.0f;
}

Player::~Player() {

}

void Player::init() {

}

void Player::setXAccel(float x) {
	xAccel += x;
}

float Player::getXAccel() {
	return xAccel;
}

float Player::getYPos() {
	return yPos;
}

void Player::setYAccel(float y) {
	yAccel = y;
}

void Player::setHasDoubleJumped(bool j) {
	hasDoubleJumped = j;
}

bool Player::getHasDoubleJumped() {
	return hasDoubleJumped;
}

void Player::update() {
	yAccel -= gravity;
	yPos += yAccel;
	
	if (xAccel > 0.0f) {
		xAccel -= friction;
	} else if (xAccel < 0.0f) {
		xAccel += friction;
	} else {
		xAccel = 0;
	}

	xPos += xAccel;

	if (yPos <= 0.0f) {
		yPos = 0.0f;
		yAccel = 0.0f;
		hasDoubleJumped = false;
	}

	GLfloat v0[] = { -0.075f + xPos, -1.0f + yPos };
	GLfloat v1[] = { -0.075f + xPos, -0.9f + yPos };
	GLfloat v2[] = { 0.0f + xPos, -1.0f + yPos };
	GLfloat v3[] = { -0.075f + xPos, -0.9f + yPos };
	GLfloat v4[] = { 0.0f + xPos, -0.9f + yPos };
	GLfloat v5[] = { 0.0f + xPos, -1.0f + yPos };

	glVertex2fv(v0);
	glVertex2fv(v1);
	glVertex2fv(v2);

	glVertex2fv(v3);
	glVertex2fv(v4);
	glVertex2fv(v5);
}