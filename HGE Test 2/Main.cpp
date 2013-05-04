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
Ship*				ship1;
Ship*				ship2;

// Handles for HGE resourcces
HTEXTURE			tex;
HEFFECT				snd;



// Play sound effect
void boom() {
	//int pan=int((x-400)/4);
	//float pitch=(dx*dx+dy*dy)*0.0005f+0.2f;
	//hge->Effect_PlayEx(snd,100,pan,pitch);
}

bool FrameFunc()
{
	if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
	ship1->Update(hge);
	ship2->Update(hge);
	return false;
}


bool RenderFunc()
{
	// Render graphics
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	ship1->Render();
	ship2->Render();
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
		ship1=new Ship(new hgeSprite(tex, 96, 64, 32, 32),96,64,HGEK_Z,"Z");
		ship2=new Ship(new hgeSprite(tex, 96, 64, 32, 32),300,300,HGEK_X,"X");
		ship2->Rotate();
		// Load a font
		fnt=new hgeFont("font1.fnt");

		// Let's rock now!
		hge->System_Start();

		// Delete created objects and free loaded resources
		delete fnt;
		delete ship1;
		delete ship2;
		hge->Texture_Free(tex);
		hge->Effect_Free(snd);
	}

	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}
