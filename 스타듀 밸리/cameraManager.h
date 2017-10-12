#pragma once
#include "singletonBase.h"
#include "worldNode.h"
#include <functional>

class gameObject;

typedef std::function<void()> CAMERA_CALLBACK;		//콜백함수

struct tagInt							
{
	int x;
	int y;
	
	tagInt() { x = 0; y = 0; }
	tagInt(int X, int Y) { x = X; y = Y; }
};

namespace direction
{
	enum Enum
	{
		MOVE_TO_TARGET ,  CONNECT_TO_TARGET	, NULL_TARGET
	};
}


class cameraManager : public singletonBase<cameraManager>
{
private: 
	tagInt		_mapSize;				//맵의 사이즈

	gameObject*		_target;			//카메라가 주시할 대상
	gameObject*		_reservedTarget;	//예약 대상
	float			_reservedTimer;		//예약 대상 타이머

	direction::Enum _direction;			//카메라 상태
	
	bool			_isShake;			//카메라 흔들림에 대한 불값
	float			_shakeTimer;		//카메라 흔들림 시간
	float			_shakeStrenth;		//카메라 흔들림 강도 

	RECT			_renderRc;			//상대 좌표 계산할 렉트

	//카메라 시간 지정 움직임 관련 변수들  
	tagInt			_start;				//시작점
	tagInt			_end;				//도착점 
	float			_angle;				//각도
	int				_range;				//이동거리 
	float			_worldTimeCount;	//도착 카운트
	float			_time;				//가고싶은 시간 

	CAMERA_CALLBACK	_cbCamera;			//카메라 콜백 함수 

	//페이드 아웃 페이드인 
	bool			_isFadeOut;
	bool			_isChange;
	int				_fadeAlpha;
	image*			_fadeOut;

public:
	tagInt		_pos;					//카메라 좌표

	HRESULT init();
	void release();
	void update();
	void render();
	void cameraMove();

	//카메라의 타겟을 설정해준다. 딜레이 타임이 있다면 예약타겟에 넣어 둔다.
	void connectTarget(gameObject* target , float delayTime = 0.0f);
	//카메라를 일정 좌표로 원하는 시간에 도착하게 한다. 도착 후 내릴 명령이 있다면 콜백 함수를 사용한다.
	void moveToCamera(int endX, int endY, float time, CAMERA_CALLBACK cb = NULL);
	//페이드 아웃 페이드 인
	void fadeOut();
	//맵 사이즈 설정자 
	void setMapSize(int width, int height )
	{
		_mapSize.x = width;
		_mapSize.y = height;
	}
	//맵 사이즈 접근자
	tagInt getMapSize() { return _mapSize; }
	//랜더 렉트 접근자
	RECT getRenderRc() { return _renderRc; }

	cameraManager()
		:_cbCamera(NULL){}
	~cameraManager() {}
};

