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
#include "hgerect.h"
#include "hgegui.h"
#include "MenuItem.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

// Pointer to the HGE interface.
// Helper classes require this to work.
HGE *hge=0;


// Pointers to the HGE objects we will use
hgeFont*				fnt;
hgeSprite*				playerSprite;
hgeSprite*				enemySprite;
hgeGUI*					gui;
//Other gameplay variables
std::vector<Player*>	players;
std::vector<Enemy*>		enemies;
std::vector<int>		keys;
float					addPlayerTimer;
float					addEnemyTimer;
float					newEnemyTime;
int						score;
bool					gameActive;

// Handles for HGE resourcces
HTEXTURE			tex;
HEFFECT				snd;

void GameInit(){
	//Create Sprites
	playerSprite = new hgeSprite(tex, 96, 64, 32, 32);
	enemySprite = new hgeSprite(tex, 72, 104, 16, 16);
	
	//Create Initial Players
	Player* player = new Player(playerSprite,400,300,HGEK_Z,"Z");
	players.push_back(player);
	
	// Load a font
	fnt=new hgeFont("font1.fnt");
	
	//Setup gameplay variables
	gameActive = false;
	addPlayerTimer = 20.0f;
	addEnemyTimer = 5.0f;
	newEnemyTime = 4.0f;
	score = 0;
	for (int i = HGEK_A; i<HGEK_Z; i++) keys.push_back(i);
}

void CheckEnemyHits(){
	for(int i=0;i < enemies.size(); i++){
		hgeRect* enemyBox;
		Enemy* enemy = enemies.at(i);
		enemyBox = enemy->getBoundingBox();
		for(int j=0; j < players.size(); j++){
			hgeRect* playerBox;
			Player* player = players.at(j);
				if (!player->getInvulnerable()) {
				playerBox = player->getBoundingBox();
				if (enemyBox->Intersect(playerBox)){
					gameActive = false;
				}
			}
		}
	}
}

void CheckEnemyBounds(){
	for(int i=0;i < enemies.size(); i++){
		Enemy* enemy = enemies.at(i);
		if (enemy->getOnScreen() && !(enemy->getX() >= 0 && enemy->getY()>=0 && enemy->getY()<=600 && enemy->getX()<=800)){
			delete enemy;
			enemies.erase(enemies.begin()+i);
			score += 1;
		}
	}
}

const char * GetKeyChar(int keyCode){
	switch(keyCode){
		case HGEK_A : return "A";
		case HGEK_B : return "B";
		case HGEK_C : return "C";
		case HGEK_D : return "D";
		case HGEK_E : return "E";
		case HGEK_F : return "F";
		case HGEK_G : return "G";
		case HGEK_H : return "H";
		case HGEK_I : return "I";
		case HGEK_J : return "J";
		case HGEK_K : return "K";
		case HGEK_L : return "L";
		case HGEK_M : return "M";
		case HGEK_N : return "N";
		case HGEK_O : return "O";
		case HGEK_P : return "P";
		case HGEK_Q : return "Q";
		case HGEK_R : return "R";
		case HGEK_S : return "S";
		case HGEK_T : return "T";
		case HGEK_U : return "U";
		case HGEK_V : return "V";
		case HGEK_W : return "W";
		case HGEK_X : return "X";
		case HGEK_Y : return "Y";
	}
}

void AddPlayer(){
	int rnd = hge->Random_Int(0,keys.size()-1);
	int keyCode = keys.at(rnd);
	keys.erase(keys.begin()+rnd);
	Player* player = new Player(playerSprite,400,300,keyCode,GetKeyChar(keyCode));
	players.push_back(player);
}

void AddEnemy(){
	int rnd = hge->Random_Int(0,3);
	int x;
	int y;
	switch(rnd){
	case 0 :
		x = hge->Random_Int(0,800);
		y = -40;
		break;
	case 1 :
		x = -40;
		y = hge->Random_Int(0,600);
		break;
	case 2 :
		x = hge->Random_Int(0,800);
		y = 640;
		break;
	case 3 :
		x = 840;
		y = hge->Random_Int(0,600);
		break;
	}
	Enemy* enemy = new Enemy(enemySprite,x,y);
	enemy->setRotation(M_PI_2 * rnd);
	enemy->setSpeed(hge->Random_Int(40,50));
	enemies.push_back(enemy);
}

void CleanUpGUI()
{
	delete gui;
}

bool UpdateGUI(float dt)
{
	int id;
	static int lastid=0;

	id=gui->Update(dt);
	if(id == -1)
	{
		switch(lastid)
		{
		case 1:
			gameActive = true;
			gui->SetFocus(1);
			gui->Enter();
			break;
		case 2: return true;
		}
	}
	else if(id) { lastid=id; gui->Leave(); }
	return false;
}

bool FrameFunc()
{
	float dt = hge->Timer_GetDelta();
	if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
	if (gameActive){
		for(int i=0;i < players.size(); i++){
			players.at(i)->Update(hge);
		}
		for(int i=0;i < enemies.size(); i++){
			enemies.at(i)->Update(hge);
		}
		CheckEnemyHits();
		CheckEnemyBounds();
		addPlayerTimer -= dt;
		if (addPlayerTimer < 0){
			AddPlayer();
			addPlayerTimer = 20;
		}
		addEnemyTimer -= dt;
		if (addEnemyTimer < 0){
			AddEnemy();
			addEnemyTimer = newEnemyTime + hge->Random_Float(0.0f,1.0f);
			if (newEnemyTime > 1.0f) newEnemyTime -= 0.1f;
		}
	}
	else
	{
		if (UpdateGUI(dt)) return true;
	}
	return false;
}


bool RenderFunc()
{
	
	
	// Render graphics
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	if (gameActive){
		//Render Players
		for(int i=0;i < players.size(); i++){
			players.at(i)->Render();
		}
	
		//Render Enemies
		for(int i=0;i < enemies.size(); i++){
			enemies.at(i)->Render();
		}

		//fnt->printf(5, 5, HGETEXT_LEFT, "PLAYER: %.2f",addPlayerTimer);
		//fnt->printf(5, 25, HGETEXT_LEFT, "ENEMY: %.2f",addEnemyTimer);
		fnt->printf(400, 5, HGETEXT_CENTER, "%d",score);
		
	}
	else {
		gui->Render();
	}
	hge->Gfx_EndScene();
	return false;
}

void AddGUI()
{
	gui=new hgeGUI();
	gui->AddCtrl(new MenuItem(1,fnt,400,200,0.0f,"Play"));
	gui->AddCtrl(new MenuItem(2,fnt,400,360,0.4f,"Exit"));
	gui->SetNavMode(HGEGUI_UPDOWN | HGEGUI_CYCLED);
	gui->SetFocus(1);
	gui->Enter();
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
		GameInit();
		AddGUI();
		// Let's rock now!
		hge->System_Start();

		// Delete created objects and free loaded resources
		delete fnt;
		delete gui;
		for(int i=0;i < players.size(); i++){
			delete players.at(i);
		}
		for(int i=0;i < enemies.size(); i++){
			delete enemies.at(i);
		}
		delete playerSprite;
		delete enemySprite;
		hge->Texture_Free(tex);
		hge->Effect_Free(snd);
	}

	// Clean up and shutdown
	hge->System_Shutdown();
	hge->Release();
	return 0;
}

