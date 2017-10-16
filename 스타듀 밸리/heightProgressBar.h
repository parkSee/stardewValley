#pragma once
#include "gameObject.h"

class heightProgressBar : public  gameObject
{
private:
	RECT _rcProgress;
	int _x, _y;
	float _height;

	image* _progressBarTop;
	image* _progressBarBottom;

	string _frontimage;
	string _backimage;
	
public:
	HRESULT init(string frontBar, string backbar, const char* frontfile, const char* backfile,
		int x, int y, int width, int height);
	void release();
	void update(int imagecenterX, int imagetopY, float current, float max);
	void render();

	void setGauge(float currentGauge, float maxGauge);

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

	heightProgressBar() 
	:_height(NULL),
		_x(NULL),
		_y(NULL),
		_progressBarBottom(NULL),
		_progressBarTop(NULL) {}

	~heightProgressBar() {}
};

