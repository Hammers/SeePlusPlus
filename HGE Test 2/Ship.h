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
	float x;
	float y;
	float dx;
	float dy;
	float speed;
	float friction;
	float rotation;
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
	void setRotation(float inRotation) {rotation = inRotation;}
	float getRotation() {return rotation;}
	virtual void Render();
	virtual void Update(HGE*);
};

#endif