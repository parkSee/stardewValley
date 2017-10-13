#pragma once
#include "gameObject.h"
#include <vector>
#include <functional>

namespace uiDirection
{
	enum Enum
	{
		NORMAL , CONVERSATION,LETTER ,END
	};
}


struct tagConverSation
{
	image*	window;					//대화창 윈도우 이미지
	image*	who;					//대화창 인물 이미지
	image*	scroll;					//대화창 인물 이름표 이미지
	image*	ball;					//대화창 볼 이미지
	
	//대화창 공관련 함수들 
	bool	isSizeUp;				
	float	size;
	//대화창 대사관련 변수들 
	float	count;					//대화창이 활성화가 되면 카운트가 감기면서 일정시간마다 str의 사이즈를 늘려준다
	int		index;					//str의 출력 사이즈 인덱스 

};

struct tagExit
{
	image*		img;
	animation*	animation;
	RECT		rc;
	float		y;
	bool		isJump;
};

struct tagLetter
{
	image*				img;
	image*				exit;
	string				txt;
	RECT				rc;
	float				scale;
	bool				isScaleUp;
};

struct tagTimeWindow
{
	image*				window;
	image*				pointer;
	int					frameX;
	RECT				windowRc;
};

class UI : public gameObject
{
private:
	image*				_layer;					//인벤토리 창이나 대화창이 켜졌을 때 배경 알파값주는 마스킹
	CBFUNCTION			_cbFunction;			//UI 콜백
	tagTimeWindow		_timeUI;

public:
	uiDirection::Enum	_direction;				//UI상태 창
	string 				_txt;					//대화 대사
	tagLetter			_letter;				//편지 구조체 
	tagExit				_exit;					//나가기 버튼
	tagConverSation		_conversation;			//대화창 구조체
	
public :

	virtual HRESULT init(string objName);
	virtual void release();
	virtual void update();
	virtual void render();

	void setAddCallback();						//처음 콜백 함수초기화 init()할때 한번만 발동한다. 
	vector<image*>	getWho(int who);			//대화창에 나올 인물이 누구인지를 이미지 벡터에 담아 반환해준다. 

	//대화창 update 및 render함수 
	void conversationUpdate();		
	void conversationRender();
	//편지 update  및 render함수  
	void letterUpdate();
	void letterRender();
	//시간UI
	void timePointer();
	void timeUIRender();
	//대화창 콜백함수
	void setConverSationWindow(int who, string txt);
	//편지 콜백함수
	void setLetter(string txt);
	//창 나가기 콜백함수
	void exit();

	//다용도 콜백 등록 
	void setCallback(CBFUNCTION cb);

	//다용도 콜백 등록 예시
	//this->setCallback([this]()
	//{
	//	sendMessage(tagMessage("conversation", 1.0f, 1, 0, vector<gameObject*>(), "안녕"));
	//});

	UI()
	:_cbFunction(NULL){}
	virtual ~UI() {}
};

