#pragma once
#include <vector>

typedef void(*CALLBACK_FUNCTION)(void);
typedef void(*CALLBACK_FUNCTION_PARAMETER)(void*);
//보이드 포인터는 뭐든지 가르킬 수 있다 == 뭐든지 담을 수 있다
//비어있기 때문에 무슨 형인지 선언해줄 필요가 있다

class animation
{
public:
	typedef vector<POINT> vFrameList;
	typedef vector<int> vPlayList;

private:
	int			_frameNum;			//프레임 넘버

	vFrameList	_frameList;			//애니메이션 프레임 리스트
	vPlayList	_playList;			//애니메이션 플레이 인덱스 리스트

	int			_frameWidth;		//가로(프레임 크기)
	int			_frameHeight;		//세로

	BOOL		_loop;				//루프 여부

	float		_frameUpdateSec;	//프레임 갱신 
	float		_elapsedSec;

	DWORD		_nowPlayIndex;		//재생 프레임 인덱스
	BOOL		_play;

	int			_maxFrameX;

	void* _obj;
	CALLBACK_FUNCTION _callbackFunction;
	CALLBACK_FUNCTION_PARAMETER _callbackFunctionParameter;

public:
	animation();
	~animation();

	//           이미지 전체 가로 세로      한 장당 가로    세로
	HRESULT init(int totalW, int totalH, int frameW, int frameH);
	void release(void);

	void setDefPlayFrame(BOOL reverse = FALSE, BOOL loop = FALSE);
	void setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);
	
	void setPlayFrame(int* playArr, int arrLen, BOOL loop = FALSE);
	void setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	void setPlayFrame(int start, int end, BOOL reverse = FALSE, BOOL loop = FALSE);
	void setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction);
	void setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj);

	void setFPS(int framePerSec);

	void frameUpdate(float elapsedTime);

	void start(void);
	void stop(void);
	void pause(void);
	void resume(void);

	inline BOOL isPlay(void) { return _play; }
	inline POINT getFramePos(void) { return _frameList[_playList[_nowPlayIndex]]; }
	inline int getFrameWidth(void) { return _frameWidth; }
	inline int getFrameHeight(void) { return _frameHeight; }

	//현재 애니메이션으로 설정된 구간에서의 프레임 번호를 가져온다.
	inline int getFrame(void) { return _nowPlayIndex; }
	//전체 스프라이트 시트 기준에서 현재 프레임의 X좌표 인덱스를 가져온다.
	inline int getFrameX(void) { return _playList[_nowPlayIndex] % _maxFrameX; }
	//전체 스프라이트 시트 기준에서 현재 프레임의 Y좌표 인덱스를 가져온다.
	inline int getFrameY(void) { return _playList[_nowPlayIndex] / _maxFrameX; }


};

