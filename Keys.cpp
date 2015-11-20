/*
See header file for explination of this class
*/

#include "Keys.h"
#include <GLFW\glfw3.h>

std::vector<bool> Keys::isButtonPressed = { false, false, false, false, false, false, false };
std::vector<bool> Keys::wasButtonPressed = { false, false, false, false, false, false, false };

void Keys::keyPressed(int i){
	if (i == Keys::ENTER) {
		isButtonPressed[Keys::ENTER] = true;
	} else if (i == Keys::ESC) {
		isButtonPressed[Keys::ESC] = true;
	} else if (i == Keys::SPACE) {
		isButtonPressed[Keys::SPACE] = true;
	} else if (i == Keys::W) {
		isButtonPressed[Keys::W] = true;
	} else if (i == Keys::A) {
		isButtonPressed[Keys::A] = true;
	} else if (i == Keys::S) {
		isButtonPressed[Keys::S] = true;
	} else if (i == Keys::D) {
		isButtonPressed[Keys::D] = true;
	}
}

void Keys::update(){
	for (int i = 0; i < Keys::NUMBER_OF_KEYS; i++){
		wasButtonPressed[i] = isButtonPressed[i];
		isButtonPressed[i] = false;
	}
}

bool Keys::uniquePress(int x){
	bool unique = isButtonPressed[x] && !wasButtonPressed[x];

	wasButtonPressed[x] = isButtonPressed[x];

	return unique;
}