#ifndef ENEMY_H
#define ENEMY_H
#include "hge.h"
#include "hgesprite.h"
#include "Ship.h"

class Enemy : public Ship{
private:
	bool onScreen;
public:
	Enemy(hgeSprite*,float,float);
	bool getOnScreen(){return onScreen;}
	void Render();
	void Update(HGE*);
	hgeRect* getBoundingBox() {return Ship::getBoundingBox();}
};

#endif