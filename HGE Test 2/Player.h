#ifndef PLAYER_H
#define PLAYER_H
#include "hge.h"
#include "Ship.h"
#include "hgesprite.h"
#include "hgeparticle.h"
#include "hgefont.h"

class Player : Ship{
private:
	hgeFont* fnt;
	int simpleRotation;
	int key;
	const char* keyChar;
public:
	Player(hgeSprite*,float,float,int,const char*);
	int getSimpleRotation() {return simpleRotation;}
	void Rotate();
	void Render();
	void Update(HGE*);
};

#endif