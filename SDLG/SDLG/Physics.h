#ifndef _PHYSICS_H
#define _PHYSICS_H

#include <string>
#include <SDL.h>
#include "Player.h"

class Physics
{
public:
	Physics();

	// Used in Main to keep track of player
	float posX = 0.0f;
	float posY = 0.0f;

	// Allows to focus on one body
	Physics* returnCurrent() { return this; }

	// Used to change textures
	Player player;

	// Used for collision and to determine which body is which
	const short CATEGORY_PLAYER = 0x0001;
	const short CATEGORY_MONSTER = 0x0002;
	const short CATEGORY_SCENERY = 0x0003;

	struct bodyUserData
	{
		int entityType;
		float health;
		std::string name;
	};

	// Moves the player via forces
	void moveBodies();
	void move(const Uint8*);

	// Creates different types of bodies
	void makeDynamic();
	void playerDynamic(float x , float y , float width, float height);
	void makeStatic(float x, float y, float width, float height);
	b2Body* makeStaticReturn(float x, float y, float width, float height);
	
	std::string bodyType = "";
	b2Body* body;
	b2Body* groundBody;
	
	// Used for the step function
	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;
	const float MTP = 100.0f;
	const float PTM = 1.0f / MTP;
};

class myCollisionDetection : public b2ContactListener
{
public:
	void BeginContact(b2Contact*);
	void EndContact(b2Contact*);
};

#endif