#ifndef _MAIN_H
#define _MAIN_H
#include "Source.h"
#include "Player.h"
#include <string>
#include <Box2D/Box2D.h>
#include "Physics.h"

using namespace std;

class MainClass
{
public:

	void render();
	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

	SDL_Rect createRect(float, float, int, int, bool offset);
	SDL_Texture* LoadTexture(string);
	SDL_Texture* player1 = NULL;
	SDL_Texture* box = NULL;
	SDL_Rect boxRect;
	SDL_Texture *playerTexture;

	int loadCounter = 0;
	b2Vec2 pos;
	int levelWidth;
	int levelHeight;

	static SDL_Rect camera;
	SDL_Rect drawingRect;
	b2Vec2 position;

	float playerPosY = 0;
	float groundPosY = 0;

	Physics physics;
	Physics physics1;
	Physics physics2;
	static Physics obstaclePhysics;
	

private:

};

#endif
