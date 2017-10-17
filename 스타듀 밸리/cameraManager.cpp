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
	if (_reservedTarget != NULL)									//예약타겟이 null이 아니라면(예약된애가 있다면)
	{
		if (_reservedTimer > 0.0f)									//예약 시간이 0보다 크다면
		{
			_reservedTimer -= TIMEMANAGER->getElapsedTime();		//예약대기시간 계산

			if (_reservedTimer <= 0.0f)								//대기 시간이 끝나면
			{
				_target = _reservedTarget;							//타겟에 예약 타겟을 넣어준다.
				_reservedTimer = 0.0f;								//타이머 초기화
				_reservedTarget = NULL;								//다시 초기화
				_direction = CONNECT_TO_TARGET;						//카메라 상태는 커넥트 되있는 상태로
			}
		}
	}

	this->cameraMove();

	//페이드 인 페이드 아웃 처리 
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



//카메라가 쫓아갈 타겟을 설정해준다. 만약 딜레이 타임이 있다면 예약타겟으로 설정해준다.
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
	//카메라에게 움직임 명령이 내려왔다면 
	if (_direction == MOVE_TO_TARGET)
	{
		float elapsedTime = TIMEMANAGER->getElapsedTime();
		//항속 계산하는 식
		float moveSpeed = (elapsedTime / _time) * _range;	

		_pos.x += cosf(_angle) * moveSpeed;
		_pos.y -= sinf(_angle) * moveSpeed;

		if (_time + _worldTimeCount <= TIMEMANAGER->getWorldTime())		//도착지에 도착 했다는 뜻
		{
			_worldTimeCount = TIMEMANAGER->getWorldTime();

			_pos.x = _end.x;
			_pos.y = _end.y;
			_direction = NULL_TARGET;
			//만약 콜백 함수가 등록이 되어 있다면 실행시켜라
			if (_cbCamera != NULL)_cbCamera();		
		}
	}
	//카메라가 이동 중이 아니라면 타겟의 좌표를 따라가라 
	if (_direction != MOVE_TO_TARGET && _direction != NULL_TARGET)
	{
		_pos.x = (int)_target->_pos.x;
		_pos.y = (int)_target->_pos.y;
	}
	//카메라가 맵의 밖으로 나갔을 경우 보정해준다.
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

	//랜더 렉트 좌표 초기화
	_renderRc = RectMakeCenter(_pos.x, _pos.y, WINSIZEX, WINSIZEY);


}

//목적지좌표와 원하는 이동시간을 넣어주면 카메라가 그 위치로 이동한다. 
//콜백 함수를 안 넣어주면 자동으로 NULL이 된다.
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

	//=================콜백 함수 static 처리 안하고 등록하는 방법 1==============	

	//auto func = std::bind(&클래스이름::발동할 함수, 클래스 주소, 매게변수);
	//CAMERAMANAGER->moveToCamera(목적지X, 목적지Y, 이동시간, func);

	//=================콜백 함수 등록 방법 2(람다식)===================================

	//CAMERAMANAGER->moveToCamera(도착지X, 도착지Y, 이동시간, [클래스의 포인터]() {함수이름(); });

	//ex)CAMERAMANAGER->moveToCamera(100, 100, 3.0f, [this]() {this->init(); });

	//아직 실험은 안해봤는데 아마 이렇게 하면 될겁니다.
}


void cameraManager::fadeOut()
{
	if (!_isFadeOut)
	{
		_isFadeOut = true;
	}
}


RECT cameraManager::getRenderRc()
{
	//카메라가 맵의 밖으로 나갔을 경우 보정해준다.
	if (_renderRc.left < 0)
	{
		_pos.x -= _renderRc.left;
	}
	else if (_renderRc.right > _mapSize.x)
	{
		_pos.x -= _renderRc.right - _mapSize.x;

	}
	else if (_renderRc.top < 0)
	{
		_pos.y -= _renderRc.top;
		
	}
	else if (_renderRc.bottom > _mapSize.y)
	{
		_pos.y -= _renderRc.bottom - _mapSize.y;
		
	}

	//랜더 렉트 좌표 초기화
	_renderRc = RectMakeCenter(_pos.x, _pos.y, WINSIZEX, WINSIZEY);

	return _renderRc;
}