#pragma once
#include "gameNode.h"
#include "ship.h"

enum DIRECTION
{
	DIRECTION_LEFT_TOP,
	DIRECTION_MIDDLE_TOP,
	DIRECTION_RIGHT_TOP,
	DIRECTION_LEFT_MIDDLE,
	DIRECTION_MIDDLE_MIDDLE,
	DIRECTION_RIGHT_MIDDLE,
	DIRECTION_LEFT_BOTTOM,
	DIRECTION_MIDDLE_BOTTOM,
	DIRECTION_RIGHT_BOTTOM
};

class space : public gameNode
{
private:
	image* _background;
	int _mapSizeWidth;
	int _mapSizeHeight;

	ship* _ship;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	DIRECTION getDirection(int x, int y);

	void setShip(ship* obj) { _ship = obj; }

	space();
	~space();
};

