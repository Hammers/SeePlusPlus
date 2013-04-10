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
public:
	Ship(HTEXTURE,float,float);
	~Ship();
	void setX(float inX) {x = inX;}
	float getX() {return x;}
	void setY(float inY) {y = inY;}
	float getY() {return y;}
	void setDx(float inDx) {dx = inDx;}
	float getDx() {return dx;}
	void setDy(float inDy) {dy = inDy;}
	float getDy() {return dy;}
	void Render();
	void Update(float);
	void Boom();
};

#endif