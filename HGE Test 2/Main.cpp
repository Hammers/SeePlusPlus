/*
** Haaf's Game Engine 1.8
** Copyright (C) 2003-2007, Relish Games
** hge.relishgames.com
**
** hge_tut03 - Using helper classes
*/


// Copy the files "particles.png", "menu.wav",
// "font1.fnt", "font1.png" and "trail.psi" from
// the folder "precompiled" to the folder with
// executable file. Also copy hge.dll and bass.dll
// to the same folder.


#include "hge.h"
#include "hgesprite.h"
#include "hgefont.h"
#include "hgeparticle.h"
#include "Ship.h"


// Pointer to the HGE interface.
// Helper classes require this to work.
HGE *hge=0;


// Pointers to the HGE objects we will use
hgeFont*			fnt;
Ship*				player;

// Handles for HGE resourcces
HTEXTURE			tex;
HEFFECT				snd;

const float speed=90;
const float friction=0.98f;

// Play sound effect
void boom() {
	//int pan=int((x-400)/4);
	//float pitch=(dx*dx+dy*dy)*0.0005f+0.2f;
	//hge->Effect_PlayEx(snd,100,pan,pitch);
}

bool FrameFunc()
{
	float dt=hge->Timer_GetDelta();

	// Process keys
	if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
	if (hge->Input_GetKeyState(HGEK_LEFT)) player->setDx(player->getDx()-speed*dt);
	if (hge->Input_GetKeyState(HGEK_RIGHT)) player->setDx(player->getDx()+speed*dt);
	if (hge->Input_GetKeyState(HGEK_UP)) player->setDy(player->getDy()-speed*dt);
	if (hge->Input_GetKeyState(HGEK_DOWN)) player->setDy(player->getDy()+speed*dt);
	player->Update(dt);
	return false;
}


bool RenderFunc()
{
	// Render graphics
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	player->Render();
	fnt->printf(5, 5, HGETEXT_LEFT, "dt:%.3f\nFPS:%d (constant)", hge->Timer_GetDelta(), hge->Timer_GetFPS());
	hge->Gfx_EndScene();

	return false;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);

	hge->System_SetState(HGE_LOGFILE, "hge_tut03.log");
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_TITLE, "HGE Tutorial 03 - Using helper classes");
	hge->System_SetState(HGE_FPS, 100);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_SCREENWIDTH, 800);
	hge->System_SetState(HGE_SCREENHEIGHT, 600);
	hge->System_SetState(HGE_SCREENBPP, 32);

	if(hge->System_Initiate()) {

		// Load sound and texture
		snd=hge->Effect_Load("menu.wav");
		tex=hge->Texture_Load("particles.png");
		if(!snd || !tex)
		{
			// If one of the data files is not found, display
			// an error message and shutdown.
			MessageBox(NULL, L"Can't load one of the following files:\nMENU.WAV, PARTICLES.PNG, FONT1.FNT, FONT1.PNG, TRAIL.PSI", L"Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
			hge->System_Shutdown();
			hge->Release();
			return 0;
		}
		player=new Ship(tex,96,64);
		// Load a font
		fnt=new hgeFont("font1.fnt");

		// Let's rock now!
		hge->System_Start();

		// Delete created objects and free loaded resources
		delete fnt;
		delete player;
		hge->Texture_Free(tex);
		hge->Effect_Free(snd);
	}

	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}
