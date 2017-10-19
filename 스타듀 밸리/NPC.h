#pragma once
#include "gameObject.h"
#include "mapToolTile.h"

#define NPCSPEED 3;

namespace npcDirection
{
	enum Enum
	{
		STAND_DOWN,
		STAND_UP,
		STAND_LEFT,
		STAND_RIGHT,
		MOVE_DOWN,
		MOVE_UP,
		MOVE_RIGHT,
		MOVE_LEFT
	};
}

struct tagKeyAniString
{
	string standDown;
	string standUp;
	string standRight;
	string standLeft;
	string moveDown;
	string moveUp;
	string moveRight;
	string moveLeft;
};

class npc : public gameObject
{
private:
	npcDirection::Enum		_direction;
	RECT					_collisionRc;
	
	float					_scale;
	
	vector<mapToolTile*>		_vMoveTile;

	bool					_isMove;

	int						_indexX;
	int						_indexY;

	float					_angle;

	float					_saveAngle;
	npcDirection::Enum		_saveDirection;

	CBFUNCTION				_cb;

private:
	tagKeyAniString			_keyAniString;

public:
	virtual HRESULT init(string name, string imageKey,tagFloat pos);
	virtual void release();
	virtual void update();
	virtual void render();
	RECT getRect();

	int getIndexX() { return _indexX; }
	int getIndexY() { return _indexY; }

	void move();

	void changeState(npcDirection::Enum direction);
	void stateUpdate();

	void setMoveRoute(tagMessage msg);
	
	void keyAniInit(string name , string imageKey);

	npcDirection::Enum	 getAngleDirection(float angle);

	void setCallback(CBFUNCTION cb) { _cb = cb; }

	npc() {}
	virtual ~npc() {}
};

