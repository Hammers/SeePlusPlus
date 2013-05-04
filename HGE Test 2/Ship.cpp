#define _USE_MATH_DEFINES
#include "Ship.h"
#include <math.h>

Ship::Ship(hgeSprite* spr,float xIn, float yIn,int keyIn, const char* keyCharIn){
	// Create and set up a sprite
	x = xIn;
	y = yIn;
	dx = 0;
	dy = 0;
	key = keyIn;
	keyChar = keyCharIn;
	speed = 90;
	friction = 0.7f;
	rotation = 0;
	shipSprite=spr;
	shipSprite->SetColor(0xFFFFA000);
	shipSprite->SetHotSpot(16,16);
	fnt = new hgeFont("font1.fnt");
	fnt->SetScale(0.7);
	// Create and set up a particle system
	particleSprite=spr;
	particleSprite->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
	particleSprite->SetHotSpot(16,16);
	particle=new hgeParticleSystem("trail.psi",particleSprite);
	particle->Fire();
}

void Ship::Render(){
	particle->Render();
	shipSprite->RenderEx(x, y, M_PI*(float)rotation/2);
	fnt->printf(x-5, y-8, HGETEXT_LEFT, keyChar);
}

void Ship::Rotate(){
	rotation += 1;
	if (rotation > 3) rotation = 0;
}

void Ship::Update(HGE* hge){
	float dt=hge->Timer_GetDelta();

	// Process keys
	if (hge->Input_KeyDown(HGEK_SPACE)) this->Rotate();
	if (hge->Input_GetKeyState(key) && rotation==0) dx += speed*dt;
	if (hge->Input_GetKeyState(key) && rotation==1) dy += speed*dt;
	if (hge->Input_GetKeyState(key) && rotation==2) dx -= speed*dt;
	if (hge->Input_GetKeyState(key) && rotation==3) dy -= speed*dt;
	
	// Do some movement calculations and collision detection	
	dx*=friction; dy*=friction; x+=dx; y+=dy;
	if(x>784) {x=784-(x-784);dx=-dx;}
	if(x<16) {x=16+16-x;dx=-dx;}
	if(y>584) {y=584-(y-584);dy=-dy;}
	if(y<16) {y=16+16-y;dy=-dy;}

	// Update particle system
	particle->info.nEmission=(int)(dx*dx+dy*dy)*2;
	particle->MoveTo(x,y);
	particle->Update(dt);
}

Ship::~Ship(){
	delete particleSprite;
	delete particle;
}