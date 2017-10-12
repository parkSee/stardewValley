#pragma once
#include "gameNode.h"

//====================
//현진&용제 + 순우&시영(feat. 한숨)
//====================
//<funtional> <------
//std::funtion
//std::move
//std::bind 
//활용해서 일반 멤버변수랑 멤버함수 참조 가능하게 하는거시 수우우욱제
//함정) 의외로 쉬움

//콜백함수는 함수포인터의 형태를 띈다
typedef void(*CALLBACK_FUNCTION)(void);

class action : public gameNode
{
private:
	image* _image;				//이미지
	float _startX, _startY;		//시작좌표(출발좌표)
	float _endX, _endY;			//끝좌표(도착좌표)

	float _angle;				//각도
	float _travelRange;			//가야할 거리
	float _worldTimeCount;		//도착 카운트
	float _time;				//가고싶은 시간(초?)

	bool _isMoving;

	CALLBACK_FUNCTION _callbackFunction;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void moveTo(image* image, float endX, float endY, float time);
	void moveTo(image* image, float endX, float endY, float time, CALLBACK_FUNCTION cbFunction);

	void moving(void);

	bool getIsMoving(void) { return _isMoving; }




	action();
	~action();
};

