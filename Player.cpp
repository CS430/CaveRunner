#include <iostream>
#include <algorithm>
#include <vector>

#include "Player.h"

#include <GL\glew.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

using namespace glm;

std::vector<std::vector<GLfloat>> vertices;

Player::Player(float xPos, float yPos, float height, float width) : xPos(xPos), yPos(yPos), height(height), width(width) {
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

float Player::getXPos() {
	return xPos;
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

void Player::setIsCrouching(bool c) {
	isCrouching = c;
}

bool Player::getIsCrouching() {
	return isCrouching;
}

float Player::getHeight() {
	return height;
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

	if (yPos - height <= -1.0f) {
		yPos = -1.0f + height;
		yAccel = 0.0f;
		hasDoubleJumped = false;
	}

	if (isCrouching) {
		height = height + width;
		width = height - width;
		height = height - width;
	}

	vertices = {
		{ xPos - width, yPos - height },
		{ xPos - width, yPos + height },
		{ xPos + width, yPos - height },
		{ xPos - width, yPos + height },
		{ xPos + width, yPos + height },
		{ xPos + width, yPos - height }
	};

	for (int i = 0; i < vertices.size(); i++) {
		glTexCoord2f(0.5f, 0.5f);
		glVertex2f(vertices[i][0], vertices[i][1]);
	}

	if (isCrouching) {
		height = height + width;
		width = height - width;
		height = height - width;

		setIsCrouching(false);
	}
}