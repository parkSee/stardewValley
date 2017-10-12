#include "stdafx.h"
#include "cameraManager.h"
#include "gameObject.h"

using namespace direction;

HRESULT cameraManager::init()
{
	_pos.x = WINSIZEX / 2;
	_pos.y = WINSIZEY / 2;
	
	_mapSize.x = WINSIZEX;
	_mapSize.y = WINSIZEY;

	_shakeStrenth = 0;
	_shakeTimer = 0;
	
	_isShake = false;
	_direction = NULL_TARGET;

	_start.x = 0;
	_start.y = 0;
	_end.x = 0; 
	_end.y = 0;
	_angle = 0;
	_range = 0;
	_worldTimeCount = 0;
	_time = 0;
	
	_fadeOut = IMAGEMANAGER->addImage("fadeOut", "resource/UI/fadeOut.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	_isFadeOut = false;
	_fadeAlpha = 0;
	_isChange = false;

	return S_OK;
}

void cameraManager::release()
{

}

void cameraManager::update()
{
	if (_reservedTarget != NULL)									//����Ÿ���� null�� �ƴ϶��(����Ⱦְ� �ִٸ�)
	{
		if (_reservedTimer > 0.0f)									//���� �ð��� 0���� ũ�ٸ�
		{
			_reservedTimer -= TIMEMANAGER->getElapsedTime();		//������ð� ���

			if (_reservedTimer <= 0.0f)								//��� �ð��� ������
			{
				_target = _reservedTarget;							//Ÿ�ٿ� ���� Ÿ���� �־��ش�.
				_reservedTimer = 0.0f;								//Ÿ�̸� �ʱ�ȭ
				_reservedTarget = NULL;								//�ٽ� �ʱ�ȭ
				_direction = CONNECT_TO_TARGET;						//ī�޶� ���´� Ŀ��Ʈ ���ִ� ���·�
			}
		}
	}

	this->cameraMove();

	//���̵� �� ���̵� �ƿ� ó�� 
	//if (_isFadeOut)
	//{
	//	if (!_isChange)
	//	{
	//		_fadeAlpha++;
	//	}
	//	else if (_isChange)
	//	{
	//		_fadeAlpha--;
	//	}
	//	if (_fadeAlpha >= 255 && !_isChange)
	//	{
	//		_isChange = true;
	//	}
	//	if (_fadeAlpha <= -1)
	//	{
	//		_isChange = false;
	//		_isFadeOut = false;
	//	}
	//	
	//}


}

void cameraManager::render()
{
	//�̱����̶� ��𾾸� ���������Ƿ� ���� �������ҵ�
	//if (_isFadeOut)
	//{
	//	_fadeOut->alphaRender(getMemDC(), 0, 0, _fadeAlpha);
	//}
}

//ī�޶� �Ѿư� Ÿ���� �������ش�. ���� ������ Ÿ���� �ִٸ� ����Ÿ������ �������ش�.
void cameraManager::connectTarget(gameObject* target, float delayTime)
{
	if (_direction != MOVE_TO_TARGET)					
	{
		if (delayTime <= 0.0f)							
		{
			_target = target;						
			_pos.x = (int)target->_pos.x;
			_pos.y = (int)target->_pos.y;
			_direction = CONNECT_TO_TARGET;
		}
		else
		{
			_reservedTimer = delayTime;
			_reservedTarget = target;
		}
	}
}

void cameraManager::cameraMove()
{
	//ī�޶󿡰� ������ ����� �����Դٸ� 
	if (_direction == MOVE_TO_TARGET)
	{
		float elapsedTime = TIMEMANAGER->getElapsedTime();
		//�׼� ����ϴ� ��
		float moveSpeed = (elapsedTime / _time) * _range;	

		_pos.x += cosf(_angle) * moveSpeed;
		_pos.y -= sinf(_angle) * moveSpeed;

		if (_time + _worldTimeCount <= TIMEMANAGER->getWorldTime())		//�������� ���� �ߴٴ� ��
		{
			_worldTimeCount = TIMEMANAGER->getWorldTime();

			_pos.x = _end.x;
			_pos.y = _end.y;
			_direction = NULL_TARGET;
			//���� �ݹ� �Լ��� ����� �Ǿ� �ִٸ� ������Ѷ�
			if (_cbCamera != NULL)_cbCamera();		
		}
	}

	//ī�޶� �̵� ���� �ƴ϶�� Ÿ���� ��ǥ�� ���󰡶� 
	if (_direction != MOVE_TO_TARGET)
	{
		_pos.x = (int)_target->_pos.x;
		_pos.y = (int)_target->_pos.y;
	}
	
	//���� ��Ʈ ��ǥ �ʱ�ȭ
	_renderRc = RectMakeCenter(_pos.x, _pos.y, WINSIZEX, WINSIZEY);

	//ī�޶� ���� ������ ������ ��� �������ش�.
	if (_renderRc.left < 0)
	{
		_pos.x -= _renderRc.left; 
	}
	if (_renderRc.right > _mapSize.x)
	{
		_pos.x -= _renderRc.right - _mapSize.x;
	}
	if (_renderRc.top < 0)
	{
		_pos.y -= _renderRc.top;
	}
	if (_renderRc.bottom > _mapSize.y)
	{
		_pos.y -= _renderRc.bottom - _mapSize.y;
	}

}

//��������ǥ�� ���ϴ� �̵��ð��� �־��ָ� ī�޶� �� ��ġ�� �̵��Ѵ�. 
//�ݹ� �Լ��� �� �־��ָ� �ڵ����� NULL�� �ȴ�.
void cameraManager::moveToCamera(int endX, int endY, float time, CAMERA_CALLBACK cb)
{
	_start.x = this->_pos.x;
	_start.y = this->_pos.y;

	_end.x = endX;
	_end.y = endY;

	_range = getDistance(_start.x, _start.y, _end.x, _end.y);

	_angle = getAngle(_start.x, _start.y, _end.x, _end.y);

	_worldTimeCount = TIMEMANAGER->getWorldTime();

	_time = time;

	_direction = MOVE_TO_TARGET;

	if(_cbCamera != NULL) _cbCamera = cb;

	//=================�ݹ� �Լ� static ó�� ���ϰ� ����ϴ� ��� 1==============	

	//auto func = std::bind(&Ŭ�����̸�::�ߵ��� �Լ�, Ŭ���� �ּ�, �ŰԺ���);
	//CAMERAMANAGER->moveToCamera(������X, ������Y, �̵��ð�, func);

	//=================�ݹ� �Լ� ��� ��� 2(���ٽ�)===================================

	//CAMERAMANAGER->moveToCamera(������X, ������Y, �̵��ð�, [Ŭ������ ������]() {�Լ��̸�(); });

	//ex)CAMERAMANAGER->moveToCamera(100, 100, 3.0f, [this]() {this->init(); });

	//���� ������ ���غôµ� �Ƹ� �̷��� �ϸ� �ɰ̴ϴ�.
}


void cameraManager::fadeOut()
{
	if (!_isFadeOut)
	{
		_isFadeOut = true;
	}
}
