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
	//������Ʈ ���� Ÿ�� ���
	if (_destroyDelayTime > 0.0f)		//����������  Ÿ���� 0���� ũ�ٴ� �� ��������� Ȱ��ȭ�� ��ٴ� ��
	{
		_destroyDelayTime -= TIMEMANAGER->getElapsedTime();		//������ Ÿ�ӿ��� ELSAPSEDTIME�� ���ش�

		if (_destroyDelayTime <= 0.0f)	//0���� �۰ų� ���������Ƿ�
		{
			_isLive = false;			//�������� �Ұ� false
		}
	}

	//std::vector�� ��� �Լ��� emplace_back�� C++11���� �߰��� ��� �Լ��ν� push_back�� ���� vector�� ��� ���� ���Ҹ� �߰��ϴ� 
	//�Լ��̴�. �� �Լ��� ���� ū ��������, push_back�� ���� ���� �Լ����� ������ ��ü�� ������ 
	//emplace_back�� ���� ���� ���� �Լ��� ������ ��ü�� �����ڸ� ���� ���ڵ��� �޾� 
	//std::vector ������ ���� ��ü�� �����Ͽ� �����ϹǷ� �ӽ� ��ü�� ������ �ı�, 
	//����(Ȥ�� move)�� ���� �ʾƵ� �Ǿ� ���ɻ� �� �����ϴ�


	//��� �޼����� ���ð��� ������ �޼�������Ʈ�� ������ִ� �޼����� �־��ش�. 
	for (int i = 0; i < _reservedMessage.size(); ++i)
	{
		_reservedMessage[i].delayTime -= TIMEMANAGER->getElapsedTime();	//��� �޼����� �ִٸ� ������ Ÿ�� �ð��� ������

		if (_reservedMessage[i].delayTime <= 0.0f)					//0���� �۾������Ƿ� ������ Ÿ�ӳ�
		{
			_reservedMessage[i].delayTime = 0.0f;					
			_messageList.emplace_back(_reservedMessage[i]);			//�޼��� ����Ʈ�� �־����� 
			_reservedMessage.erase(_reservedMessage.begin() + i);	//��� �޼�������Ʈ������ ����������
			--i;
		}
	}

	//�޼��� ó���ϱ�
	for (int i = _messageList.size() - 1; i >= 0; i--)			//�޼��� ����Ʈ ��ȯ
	{
		auto iter = _callbackList.find(_messageList[i].text);	//�ݹ鸮��Ʈ�� ���鼭 �޼��� �̸��� ������ ã�´�
		
		if (iter != _callbackList.end())						//ã�Ҵٴ� ���̹Ƿ�
		{
			iter->second(_messageList[i]);						//�ݹ��Լ��� �޼��� �ŰԺ����� �־��ָ鼭 �� �ݹ� �Լ� �ߵ�
		}
		_messageList.erase(_messageList.begin() + i);			//�ߵ� �������� �� �޼��� ����Ʈ�� ���� ������ 
	}
	
}
void gameObject::render()
{


	//��� ��ǥ ,���� ��ǥ ����� ��Ʈ 
	RECT renderRC = CAMERAMANAGER->getRenderRc();

	RECT pivotRc = this->getRect();			//�Ǻ��� ���� ��Ʈ�� �޾ƿ���
	if (_image != NULL)
	{
		_image->aniRender(getMemDC(), pivotRc.left - renderRC.left, pivotRc.top - renderRC.top, _animation);
	}
}

bool gameObject::isActiveObject()
{
	if (!_isLive)			//������Ʈ�� �׾��ִٸ� ������ false
	{
		return false;
	}
	if (!_isActive)			//Ȱ��ȭ�� ���������Ƿ� false
	{
		return false;
	}

	return true;			//�װ� �ƴ϶�� true
}

void gameObject::setDestroy(float time)
{
	if (time <= 0.0f)			//0���� �۰ų� ���ٴ°� �����̰� �ʿ� ���ٴ� ���̴�
	{
		_isLive = false;		//�ٷ� �������� �Ұ� false
	}
	else
	{
		_destroyDelayTime = time;	//��Ʈ���� Ÿ�� �־��ָ鼭 Ȱ��ȭ 
	}

}


void gameObject::sendMessage(tagMessage msg )
{
	if (msg.delayTime == 0.0f)				//�޼��������� Ÿ���� ���ٸ�
	{
		_messageList.emplace_back(msg);		//�޼�������Ʈ�� �ٷ� �־��
	}
	else									//�װ� �ƴ϶��
	{
		_reservedMessage.emplace_back(msg);	//������ Ÿ���� �ִٴ� ���̹Ƿ� �޼��� ���ฮ��Ʈ�� �־�� 
	}

}


void gameObject::daysGone(tagMessage msg)
{
	
}