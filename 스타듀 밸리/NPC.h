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

	char*	_standUp;
	char*	_standDown;
	char*	_standLeft;
	char*	_standRight;
	char*	_walkUp;
	char*	_walkDown;
	char*	_walkLeft;
	char*	_walkRight;

public:
	HRESULT init(string npcName,char* imageName, int indexX, int indexY);
	void release();
	void update(int indexX, int indexY);
	void render();

	void stateUpdate(npcState::Enum state);
	void changeState(npcState::Enum state);

	NPC() {}
	~NPC() {}
};