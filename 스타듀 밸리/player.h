#pragma once
#include "gameObject.h"

namespace playerState
{
	enum Enum
	{
		STAND,					//서있기
		STAND_RIGHT,
		STAND_LEFT,
		STAND_BACK,
		RIGHT_RUN,				//오른쪽
		LEFT_RUN,				//왼쪽
		UP_RUN,					//위로
		DOWN_RUN,				//아래로
		AXE_RIGHT,				//도끼 오른쪽
		AXE_LEFT,				//도끼 왼쪽
		AXE_UP,					//도끼 위로
		AXE_DOWN,				//도끼 아래로
		HOE_RIGHT,				//괭이 오른쪽
		HOE_LEFT,				//괭이 왼쪽
		HOE_UP,					//괭이 위로 
		HOE_DOWN,				//괭이 아래로
		SICKLE_RIGHT,			//낫 오른쪽
		SICKLE_LEFT,			//낫 왼쪽
		SICKLE_UP,				//낫 위로
		SICKLE_DOWN,			//낫 아래로
		WATER_RIGHT,			//물뿌리개 오른쪽
		WATER_LEFT,				//물뿌리개 왼쪽
		WATER_UP,				//물뿌리개 위로
		WATER_DOWN,				//물뿌리개 아래로
		TAKE_RIGHT,				//들고 있기 오른쪽
		TAKE_LEFT,				//들고 있기 왼쪽
		TAKE_UP,				//들고 있기 위
		TAKE_DOWN				//들고 있기 아래

	};
}

struct tagItem
{
	//아이템 포인터 
	//이미지 포인터
	image* img;
	RECT rc;
	float x, y;

};

struct tagPlayer
{
	animation* Motion;
	
	RECT rc;
};


using namespace playerState;

class player : public gameObject
{
private:
	playerState::Enum _state;
	tagPlayer _player;
	bool _isStop;
	tagItem _item;


public:
	HRESULT init(string objName, tagFloat pos);
	void release();
	void update();
	void render();

	void stateUpdate(playerState::Enum state);
	void changeState(playerState::Enum state);
	void eating();
	void lbuttonClick();
	void changeTargetItem();


	player() {};
	~player() {};
};

