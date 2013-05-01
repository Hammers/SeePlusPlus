#ifndef SHIP_H
#define SHIP_H
#include "hge.h"
#include "hgesprite.h"
#include "hgeparticle.h"

class Ship{
private:
	hgeSprite* shipSprite;
	hgeSprite* particleSprite;
	hgeParticleSystem* particle;
	float x;
	float y;
	float dx;
	float dy;
	float speed;
	float friction;
	int rotation;
public:
	Ship(hgeSprite*,float,float);
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
	void Render();
	void Update(HGE*);
	void Boom();
	void Rotate();
};

#endif