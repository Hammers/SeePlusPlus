#include "Player.h"

Player::Player(hgeSprite* spr,float xIn, float yIn,int keyIn,const char* keyCharIn) : Ship(spr,xIn,yIn), simpleRotation(0)  {
	// Create and set up a sprite
	key = keyIn;
	keyChar = keyCharIn;
	fnt = new hgeFont("font1.fnt");
	fnt->SetScale(0.7);
	if (key == HGEK_Z) invulnerableTimer = 0.0f;
	else invulnerableTimer = 3.0f;
	displayShipTimer = 0.25f;
	displayShip = true;
}

void Player::Render(){
	if (displayShip){
		Ship::Render();
		fnt->printf(getX()-5, getY()-8, HGETEXT_LEFT, keyChar);
	}
}

void Player::Rotate(){
	simpleRotation += 1;
	if (simpleRotation > 3) simpleRotation = 0;
	setRotation(M_PI_2 * (float)simpleRotation);
}

void Player::Update(HGE* hge){
	float dt=hge->Timer_GetDelta();
	if(x>784) {x=784-(x-784);dx=-dx;}
	if(x<16) {x=16+16-x;dx=-dx;}
	if(y>584) {y=584-(y-584);dy=-dy;}
	if(y<16) {y=16+16-y;dy=-dy;}
	// Process keys
	if (hge->Input_KeyDown(HGEK_SPACE)) this->Rotate();
	if (hge->Input_GetKeyState(key) && simpleRotation==0) setDx(getDx()+getSpeed()*dt);
	if (hge->Input_GetKeyState(key) && simpleRotation==1) setDy(getDy()+getSpeed()*dt);
	if (hge->Input_GetKeyState(key) && simpleRotation==2) setDx(getDx()-getSpeed()*dt);
	if (hge->Input_GetKeyState(key) && simpleRotation==3) setDy(getDy()-getSpeed()*dt);
	if (invulnerableTimer > 0) {
		invulnerableTimer -= dt;
		displayShipTimer -= dt;
		if (displayShipTimer < 0) {
			displayShipTimer = 0.25f;
			if (displayShip) displayShip = false;
			else displayShip = true;
		}
	}
	else displayShip = true;
	Ship::Update(hge);
}

Player::~Player(){
	delete fnt;
}
