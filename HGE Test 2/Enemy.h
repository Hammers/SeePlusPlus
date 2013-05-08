#ifndef ENEMY_H
#define ENEMY_H
#include "hge.h"
#include "hgesprite.h"
#include "hgeparticle.h"
#include "hgefont.h"

class Enemy{
private:
	hgeSprite* sprite;
	hgeSprite* particleSprite;
	hgeParticleSystem* particle;
	hgeFont* fnt;
	float x;
	float y;
	float dx;
	float dy;
	float speed;
	float friction;
	float rotation;
	int key;
	const char* keyChar;
public:
	Enemy(hgeSprite*,float,float);
	~Enemy();
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
	void Render();
	void Update(HGE*);
};

#endif