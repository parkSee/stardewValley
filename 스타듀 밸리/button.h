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

enum BUTTONDIRECTION
{
	BUTTONDIRECTION_NULL,
	BUTTONDIRECTION_UP,
	BUTTONDIRECTION_DOWN
};

class button : public gameNode
{
private:
	BUTTONDIRECTION _direction;

	const char* _imageName;
	image* _image;
	RECT _rc;
	float _x, _y;

	POINT _btnDownFramePoint;
	POINT _btnUpFramePoint;

	CALLBACK_FUNCTION _callbackFunction;

public:
	button();
	~button();

	HRESULT init(const char* imageName, int x, int y,
		POINT btnDownFramePoint, POINT btnUpFramePoint,
		CALLBACK_FUNCTION cbFunction);

	void release(void);
	void update(void);
	void render(void);

};

