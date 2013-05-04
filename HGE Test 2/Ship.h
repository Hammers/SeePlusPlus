#ifndef SHIP_H
#define SHIP_H
#include "hge.h"
#include "hgesprite.h"
#include "hgeparticle.h"
#include "hgefont.h"

class Ship{
private:
	hgeSprite* shipSprite;
	hgeSprite* particleSprite;
	hgeParticleSystem* particle;
	hgeFont* fnt;
	float x;
	float y;
	float dx;
	float dy;
	float speed;
	float friction;
	int rotation;
	int key;
	const char* keyChar;
public:
	Ship(hgeSprite*,float,float,int,const char*);
	~Ship();
	void setX(float inX) {x = inX;}
	float getX() {return x;}
	void setY(float inY) {y = inY;}
	float getY() {return y;}
	void setDx(float inDx) {dx = inDx;}
	float getDx() {return dx;}
	void setDy(float inDy) {dy = inDy;}
	float getDy() {return dy;}
	void setSpeed(float inSpeed) { speed = inSpeed;}
	float getSpeed() {return speed;}
	void setFriction(float inFriction) { friction = inFriction;}
	float getFriction() {return friction;}
	int getRotation() {return rotation;}
	void Render();
	void Update(HGE*);
	void Boom();
	void Rotate();
};

#endif