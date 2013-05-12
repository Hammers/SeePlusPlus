#include "Ship.h"

Ship::Ship(hgeSprite* spr,float xIn, float yIn) : x(xIn), y(yIn), dx(0), dy(0), speed(90), friction(0.7f), rotation (0){
	// Create and set up a sprite
	shipSprite=spr;
	shipSprite->SetColor(0xFFFFA000);
	shipSprite->SetHotSpot(16,16);

	// Create and set up a particle system
	particleSprite=spr;
	particleSprite->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
	particleSprite->SetHotSpot(16,16);
	particle=new hgeParticleSystem("trail.psi",particleSprite);
	particle->Fire();
}

void Ship::Render(){
	particle->Render();
	shipSprite->RenderEx(x, y, rotation);
}

void Ship::Update(HGE* hge){
	float dt=hge->Timer_GetDelta();
	
	// Do some movement calculations	
	dx*=friction; dy*=friction; x+=dx; y+=dy;

	// Update particle system
	particle->info.nEmission=(int)(dx*dx+dy*dy)*2;
	particle->MoveTo(x,y);
	particle->Update(dt);
}

Ship::~Ship(){
}