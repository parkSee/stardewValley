#pragma once
#include "gameNode.h"
#include "jump.h"

#define KNIGHTSPEED 2.5f

//기사의 상태
enum KNIGHTDIRECTION
{
	KNIGHTDIRECTION_RIGHT_STOP,
	KNIGHTDIRECTION_LEFT_STOP,
	KNIGHTDIRECTION_RIGHT_MOVE,
	KNIGHTDIRECTION_LEFT_MOVE,
	KNIGHTDIRECTION_RIGHT_SIT,
	KNIGHTDIRECTION_LEFT_SIT,
	KNIGHTDIRECTION_RIGHT_ATTACK,
	KNIGHTDIRECTION_LEFT_ATTACK,
	KNIGHTDIRECTION_RIGHT_SIT_ATTACK,
	KNIGHTDIRECTION_LEFT_SIT_ATTACK,
	KNIGHTDIRECTION_RIGHT_JUMP,
	KNIGHTDIRECTION_LEFT_JUMP,
	KNIGHTDIRECTION_RIGHT_MOVE_JUMP,
	KNIGHTDIRECTION_LEFT_MOVE_JUMP
};

class knight : public gameNode
{
private:
	KNIGHTDIRECTION _knightDirection;

	//기사님 이미지 + _+ 기사님 아아아아아아
	image* _image;
	float _x, _y;
	RECT _rc;

	animation* _knightMotion;

	jump* _jump;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	static void rightFire(void* obj);
	static void leftFire(void* obj);
	static void rightSitFire(void* obj);
	static void leftSitFire(void* obj);

	static void rightJump(void* obj);
	static void leftJump(void* obj);
	static void rightMoveJump(void* obj);
	static void leftMoveJump(void* obj);

	KNIGHTDIRECTION getKnightDirection(void) { return _knightDirection; }
	void setKnightDirection(KNIGHTDIRECTION direction) { _knightDirection = direction; }

	animation* getKnightMotion(void) { return _knightMotion; }
	void setKnightMotion(animation* ani) { _knightMotion = ani; }


	knight();
	~knight();
};

