#include <iostream>
#include <algorithm>
#include <vector>

#include "Player.h"

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

using namespace glm;

const GLfloat vertices[6][2] = {
	{ -0.075f, -1.0f },
	{ -0.075f, -0.9f },
	{  0.0f,   -1.0f },
	{ -0.075f, -0.9f },
	{  0.0f,   -0.9f },
	{  0.0f,   -1.0f }
};;

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

	for (int i = 0; i < sizeof(vertices) / 8; i++) {
		glVertex2f(vertices[i][0] + xPos, vertices[i][1] + yPos);
	}
}