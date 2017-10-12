#pragma once
#include <vector>

typedef void(*CALLBACK_FUNCTION)(void);
typedef void(*CALLBACK_FUNCTION_PARAMETER)(void*);
//���̵� �����ʹ� ������ ����ų �� �ִ� == ������ ���� �� �ִ�
//����ֱ� ������ ���� ������ �������� �ʿ䰡 �ִ�

class animation
{
public:
	typedef vector<POINT> vFrameList;
	typedef vector<int> vPlayList;

private:
	int			_frameNum;			//������ �ѹ�

	vFrameList	_frameList;			//�ִϸ��̼� ������ ����Ʈ
	vPlayList	_playList;			//�ִϸ��̼� �÷��� �ε��� ����Ʈ

	int			_frameWidth;		//����(������ ũ��)
	int			_frameHeight;		//����

	BOOL		_loop;				//���� ����

	float		_frameUpdateSec;	//������ ���� 
	float		_elapsedSec;

	DWORD		_nowPlayIndex;		//��� ������ �ε���
	BOOL		_play;

	int			_maxFrameX;

	void* _obj;
	CALLBACK_FUNCTION _callbackFunction;
	CALLBACK_FUNCTION_PARAMETER _callbackFunctionParameter;

public:
	animation();
	~animation();

	//           �̹��� ��ü ���� ����      �� ��� ����    ����
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

	//���� �ִϸ��̼����� ������ ���������� ������ ��ȣ�� �����´�.
	inline int getFrame(void) { return _nowPlayIndex; }
	//��ü ��������Ʈ ��Ʈ ���ؿ��� ���� �������� X��ǥ �ε����� �����´�.
	inline int getFrameX(void) { return _playList[_nowPlayIndex] % _maxFrameX; }
	//��ü ��������Ʈ ��Ʈ ���ؿ��� ���� �������� Y��ǥ �ε����� �����´�.
	inline int getFrameY(void) { return _playList[_nowPlayIndex] / _maxFrameX; }


};

