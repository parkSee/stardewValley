#pragma once
class timer
{
private:
	bool _isHardware;		//고성능 하드웨어를 지원하느냐
	float _timeScale;		//타이머의 스케일()
	float _timeElapsed;		//tick 카운트

	__int64 _curTime;
	__int64 _lastTime;
	__int64 _periodFrequency;

	unsigned long _frameRate;
	unsigned long _FPSFrameCount;
	float _FPSTimeElapsed;
	float _worldTime;

public:
	HRESULT init(void);
	void tick(float lockFPS = 0.0f);
	unsigned long getFrameRate(char* str = NULL) const;

	inline float getElapsedTime(void) const { return _timeElapsed; }
	inline float getWorldTime(void) const { return _worldTime; }

	timer();
	~timer();
};

