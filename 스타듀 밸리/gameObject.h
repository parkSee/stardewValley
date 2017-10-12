#pragma once
#include "gameNode.h"
#include "worldNode.h"
#include <functional>
#include <unordered_map>

namespace pivot
{
	enum Enum
	{
		LEFT_TOP, CENTER, BOTTOM
	};
}

struct tagSize
{
	float width;
	float height;
};

class gameObject : public gameNode
{
private:
	bool _isLive;								//오브젝트가 살아있는지 불값
	bool _isActive;								//오브젝트 활성화 불값
	float _destroyDelayTime;						//삭제 딜레이 타임 

	vector<tagMessage> _reservedMessage;									//대기 메세지
	vector<tagMessage> _messageList;										//메세지리스트
	unordered_map<string, std::function<void(tagMessage)>> _callbackList;	//메세지 콜백 리스트 

protected:
	pivot::Enum			_pivot;						//피봇
	image*				_image;						//게임 오브젝트 이미지
	animation*			_animation;					//게임 오브젝트의 애니메이션 정보

	tagSize _size;								//가로 세로 길이
	
public:
	tagFloat _pos;								//좌표
	string _name;								//오브젝트 이름

	gameObject() {}
	virtual ~gameObject() {}

	virtual HRESULT init(string objName , string imageKey  = "", tagFloat pos = tagFloat() , pivot::Enum pivot = pivot::CENTER);
	virtual void release();
	virtual void update();
	virtual void render();

	RECT getRect();										//피봇에 따른 랜더 렉트를 반환해 준다

	bool isActiveObject();								//활성화 상태인지에 대한 불값을 반환 해준다.
	void setDestroy(float time = 0.0f);					//오브젝트 삭제명령

	void sendMessage(tagMessage msg = tagMessage());	//메세지 전송
	
	bool isLive() { return _isLive; }

	//콜백 함수 저장
	void addCallback(string msgName, std::function<void(tagMessage)> callbackFunc)
	{
		_callbackList.insert(make_pair(msgName, callbackFunc));
	}

};

