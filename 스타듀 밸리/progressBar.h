#pragma once
#include "gameNode.h"

class progressBar : public gameNode
{
private:
	RECT _rcProgress;
	int _x, _y;
	float _width;

	image* _progressBarTop;
	image* _progressBarBottom;

	float _progeressBarRight;

public:
	HRESULT init(int x, int y, int width, int height);
	HRESULT init(char* topImage, char* bottomImage, float x, float y, int width, int height);
	void release();
	void update();
	void render();

	void setGauge(float currentGauge, float maxGauge);

	float getProgerssBarRight() { return _progeressBarRight; }

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }

	progressBar();
	~progressBar();
};

