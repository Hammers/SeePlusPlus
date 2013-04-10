#include "Ship.h"

Ship::Ship(HTEXTURE tex,float xIn, float yIn){
	// Create and set up a sprite
	x = xIn;
	y = yIn;
	shipSprite=new hgeSprite(tex, x, y, 32, 32);
	shipSprite->SetColor(0xFFFFA000);
	shipSprite->SetHotSpot(16,16);

	// Create and set up a particle system
	particleSprite=new hgeSprite(tex, x, y, 32, 32);
	particleSprite->SetBlendMode(BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE);
	particleSprite->SetHotSpot(16,16);
	particle=new hgeParticleSystem("trail.psi",particleSprite);
	particle->Fire();
}

void Ship::Render(){
	particle->Render();
	shipSprite->Render(x, y);
}

void Ship::Update(float dt){
	// Do some movement calculations and collision detection	
	dx*=0.98f; dy*=0.98f; x+=dx; y+=dy;
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
	delete shipSprite;
	delete particle;
}