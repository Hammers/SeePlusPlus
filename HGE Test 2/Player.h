#ifndef PLAYER_H
#define PLAYER_H
#include "hge.h"
#include "Ship.h"
#include "hgesprite.h"
#include "hgeparticle.h"
#include "hgefont.h"

class Player : public Ship{
private:
	hgeFont* fnt;
	bool invulnerable;
	float invulnerableTimer;
	int simpleRotation;
	int key;
	const char* keyChar;
	bool displayShip;
	float displayShipTimer;
public:
	Player(hgeSprite*,float,float,int,const char*);
	~Player();
	int getSimpleRotation() {return simpleRotation;}
	bool getInvulnerable() {return invulnerableTimer > 0.0f;}
	void Rotate();
	void Render();
	void Update(HGE*);
	hgeRect* getBoundingBox() {return Ship::getBoundingBox();}
};

#endif