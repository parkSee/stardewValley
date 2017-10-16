#pragma once
#include "gameObject.h"
#include "item.h"

namespace playerState
{
	enum Enum
	{
		STAND,					//서있기
		STAND_RIGHT,
		STAND_LEFT,
		STAND_BACK,
		STAND_TAKE,				//들고 서있기
		STAND_TAKE_RIGHT,
		STAND_TAKE_LEFT,
		STAND_TAKE_BACK,
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
		PIXHOE_RIGHT,			//곡괭이 오른쪽
		PIXHOE_LEFT,			//곡괭이 왼쪽
		PIXHOE_UP,				//곡괭이 위로
		PIXHOE_DOWN,			//곡괭이 아래로
		SICKLE_RIGHT,			//낫 오른쪽
		SICKLE_LEFT,			//낫 왼쪽
		SICKLE_UP,				//낫 위로
		SICKLE_DOWN,			//낫 아래로
		SWORD_RIGHT,			//검 오른쪽
		SWORD_LEFT,				//검 왼쪽
		SWORD_UP,				//검 위로
		SWORD_DOWN,				//검 아래로
		WATER_RIGHT,			//물뿌리개 오른쪽
		WATER_LEFT,				//물뿌리개 왼쪽
		WATER_UP,				//물뿌리개 위로
		WATER_DOWN,				//물뿌리개 아래로
		TAKE_RIGHT,				//들고 오른쪽으로 달리기
		TAKE_LEFT,				//들고 왼쪽으로 달리기
		TAKE_UP,				//들고 위으로 달리기
		TAKE_DOWN				//들고 아래으로 달리기
	};
}


struct tagPlayer
{
	animation* Motion;
	
	RECT rc;
};

struct tagMyItem			//아이템은 구조체로 되어있기 때문에 이미지와 좌표를 가져와서 플레이어 쪽에서 그려준다.
{
	image* img;
	float x, y;

};

using namespace playerState;

class player : public gameObject
{
private:
	playerState::Enum _state;
	tagPlayer _player;
	tagMyItem _myItem;
	tagItem* _item;

public:
	HRESULT init(string objName, tagFloat pos);
	void release();
	void update();
	void render();

	void stateUpdate(playerState::Enum state);
	void changeState(playerState::Enum state);
	void eating();
	void lbuttonClick(tagMessage msg);
	void changeTargetItem(tagMessage msg);
	RECT rectMakeBottom();



	enum playerState::Enum getPlayerState(void) { return _state; }
	void setPlayerState(playerState::Enum state) { _state = state; }

	animation* getPlayerMotion(void) { return _player.Motion; }
	void setPlayerMotion(animation* ani) { _player.Motion = ani; }

	player() {};
	~player() {};
};

