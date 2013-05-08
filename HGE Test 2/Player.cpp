#define _USE_MATH_DEFINES
#include "Player.h"
#include <math.h>

Player::Player(hgeSprite* spr,float xIn, float yIn,int keyIn,const char* keyCharIn) : Ship(spr,xIn,yIn), simpleRotation(0) {
	// Create and set up a sprite
	key = keyIn;
	keyChar = keyCharIn;
	fnt = new hgeFont("font1.fnt");
	fnt->SetScale(0.7);
}

void Player::Render(){
	Ship::Render();
	fnt->printf(getX()-5, getY()-8, HGETEXT_LEFT, keyChar);
}

void Player::Rotate(){
	simpleRotation += 1;
	if (simpleRotation > 3) simpleRotation = 0;
	setRotation(M_PI * ((float)simpleRotation / 2));
}

void Player::Update(HGE* hge){
	float dt=hge->Timer_GetDelta();

	// Process keys
	if (hge->Input_KeyDown(HGEK_SPACE)) this->Rotate();
	if (hge->Input_GetKeyState(key) && simpleRotation==0) setDx(getDx()+getSpeed()*dt);
	if (hge->Input_GetKeyState(key) && simpleRotation==1) setDy(getDy()+getSpeed()*dt);
	if (hge->Input_GetKeyState(key) && simpleRotation==2) setDx(getDx()-getSpeed()*dt);
	if (hge->Input_GetKeyState(key) && simpleRotation==3) setDy(getDy()-getSpeed()*dt);
	
	Ship::Update(hge);
}