#pragma once
#include "gameObject.h"

namespace npcState
{
	enum Enum
	{
		STAND,
		STAND_UP,
		STAND_LEFT,
		STAND_RIGHT,
		WALK_UP,
		WALK_DOWN,
		WALK_LEFT,
		WALK_RIGHT,
	};
}

struct tagNPC
{
	animation* Motion;
	RECT rc;
};

using namespace npcState;

class NPC : public gameObject
{
private:
	npcState::Enum _state;
	tagNPC _npc;
	int _indexX;
	int _indexY;

	char charstandUp[sizeof("npcStandUp_")];
	char charstandDown[sizeof("npcStandDown_")];
	char charstandLeft[sizeof("npcStandLeft_")];
	char charstandRight[sizeof("npcStandRight_")];
	char charwalkUp[sizeof("npcWalkUp_")];
	char charwalkDown[sizeof("npcWalkDown_")];
	char charwalkLeft[sizeof("npcWalkLeft_")];
	char charwalkRight[sizeof("npcWalkRight_")];

	string _standUp;
	string _standDown;
	string _standLeft;
	string _standRight;
	string _walkUp;
	string _walkDown;
	string _walkLeft;
	string _walkRight;

public:
	HRESULT init(string npcName,char* imageName, int indexX, int indexY);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void stateUpdate(npcState::Enum state);
	void changeState(npcState::Enum state);

	NPC() {}
	~NPC() {}
};