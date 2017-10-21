#include "stdafx.h"
#include "gameObject.h"


HRESULT gameObject::init(string objName, string imageKey , tagFloat pos , 
	 pivot::Enum pivot)
{
	_name = objName;			
	_objEnum = OBJECT::NONE;
	
	_animation = new animation;

	if (imageKey != "")
	{
		_image = IMAGEMANAGER->findImage(imageKey);

		//_animation->init(_image->getWidth(), _image->getHeight(), _image->getFrameWidth(), _image->getFrameHeight());

		//_size.width = _image->getFrameWidth();
		//_size.height = _image->getFrameHeight();
	}
	else
	{
		_image = NULL;
		_animation->init(1, 1, 1, 1);
	}

	_pos = pos;
	_pivot = pivot;

	_isLive = true;
	_isActive = true;
	_destroyDelayTime = 0.0f;

	_pObj = NULL;
	_isMovable = false;
	
	this->addCallback("daysGone", [this](tagMessage msg)
	{
		this->daysGone(msg);
	});

	return S_OK;
}

RECT gameObject::getRect()
{
	RECT rc;
	switch (_pivot)
	{
	case pivot::LEFT_TOP:
	{
		rc = RectMake(_pos.x, _pos.y, _size.width, _size.height);
	}
	break;
	case pivot::CENTER:
	{
		rc = RectMakeCenter(_pos.x, _pos.y, _size.width, _size.height);
	}
	break;
	case pivot::BOTTOM:
	{
		rc.left = _pos.x - _size.width/2; 
		rc.top = _pos.y - _size.height;
		rc.right = _pos.x + _size.width / 2;
		rc.bottom = _pos.y;
	}
	break;
	}

	return rc;
}


void gameObject::release()
{
	_reservedMessage.clear();
	_messageList.clear();

	_animation->release();
	SAFE_DELETE(_animation);
}


void gameObject::update()
{
	//오브젝트 삭제 타임 계산
	if (_destroyDelayTime > 0.0f)		//삭제딜레이  타임이 0보다 크다는 건 삭제명령이 활성화가 됬다는 뜻
	{
		_destroyDelayTime -= TIMEMANAGER->getElapsedTime();		//딜레이 타임에서 ELSAPSEDTIME을 빼준다

		if (_destroyDelayTime <= 0.0f)	//0보다 작거나 같아졌으므로
		{
			_isLive = false;			//생존여부 불값 false
		}
	}

	//std::vector의 멤버 함수인 emplace_back은 C++11부터 추가된 멤버 함수로써 push_back과 같이 vector의 요소 끝에 원소를 추가하는 
	//함수이다. 두 함수의 가장 큰 차이점은, push_back과 같은 삽입 함수들은 삽입할 객체를 받지만 
	//emplace_back과 같은 생성 삽입 함수는 삽입할 객체의 생성자를 위한 인자들을 받아 
	//std::vector 내에서 직접 객체를 생성하여 삽입하므로 임시 객체의 생성과 파괴, 
	//복사(혹은 move)를 하지 않아도 되어 성능상 더 유리하다


	//대기 메세지의 대기시간이 끝나면 메세지리스트에 대기해있던 메세지를 넣어준다. 
	for (int i = 0; i < _reservedMessage.size(); ++i)
	{
		_reservedMessage[i].delayTime -= TIMEMANAGER->getElapsedTime();	//대기 메세지가 있다면 딜레이 타임 시간을 빼주자

		if (_reservedMessage[i].delayTime <= 0.0f)					//0보다 작아졌으므로 딜레이 타임끝
		{
			_reservedMessage[i].delayTime = 0.0f;					
			_messageList.emplace_back(_reservedMessage[i]);			//메세지 리스트에 넣어주자 
			_reservedMessage.erase(_reservedMessage.begin() + i);	//대기 메세지리스트에서는 삭제해주자
			--i;
		}
	}

	//메세지 처리하기
	for (int i = _messageList.size() - 1; i >= 0; i--)			//메세지 리스트 순환
	{
		auto iter = _callbackList.find(_messageList[i].text);	//콜백리스트를 돌면서 메세지 이름과 같은걸 찾는다
		
		if (iter != _callbackList.end())						//찾았다는 뜻이므로
		{
			iter->second(_messageList[i]);						//콜백함수에 메세지 매게변수로 넣어주면서 그 콜백 함수 발동
		}
		_messageList.erase(_messageList.begin() + i);			//발동 시켰으니 그 메세지 리스트는 삭제 해주자 
	}
	
}
void gameObject::render()
{


	//상대 좌표 ,절대 좌표 계산할 렉트 
	RECT renderRC = CAMERAMANAGER->getRenderRc();

	RECT pivotRc = this->getRect();			//피봇에 따른 렉트를 받아오자
	if (_image != NULL)
	{
		_image->aniRender(getMemDC(), pivotRc.left - renderRC.left, pivotRc.top - renderRC.top, _animation);
	}
}

bool gameObject::isActiveObject()
{
	if (!_isLive)			//오브젝트가 죽어있다면 무조건 false
	{
		return false;
	}
	if (!_isActive)			//활성화가 꺼져있으므로 false
	{
		return false;
	}

	return true;			//그게 아니라면 true
}

void gameObject::setDestroy(float time)
{
	if (time <= 0.0f)			//0보다 작거나 같다는건 딜레이가 필요 없다는 뜻이다
	{
		_isLive = false;		//바로 생존여부 불값 false
	}
	else
	{
		_destroyDelayTime = time;	//디스트로이 타임 넣어주면서 활성화 
	}

}


void gameObject::sendMessage(tagMessage msg )
{
	if (msg.delayTime == 0.0f)				//메세지딜레이 타임이 없다면
	{
		_messageList.emplace_back(msg);		//메세지리스트에 바로 넣어라
	}
	else									//그게 아니라면
	{
		_reservedMessage.emplace_back(msg);	//딜레이 타임이 있다는 것이므로 메세지 예약리스트에 넣어라 
	}

}


void gameObject::daysGone(tagMessage msg)
{
	
}