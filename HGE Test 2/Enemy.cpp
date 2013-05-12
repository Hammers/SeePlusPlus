#include "Enemy.h"
#include <math.h>
Enemy::Enemy(hgeSprite* spr,float xIn, float yIn) : Ship(spr,xIn,yIn) {
	shipSprite->SetHotSpot(8,8);
	onScreen = false;
}

void Enemy::Render(){
	Ship::Render();
}

void Enemy::Update(HGE* hge){
	float dt=hge->Timer_GetDelta();
	dx+=speed * dt * sin(rotation);
	dy+=speed * dt * cos(rotation);
	if (x >= 0 && y>=0 && y<=600 && x<=800) onScreen = true;
	Ship::Update(hge);
}