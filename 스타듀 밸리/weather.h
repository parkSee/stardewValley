#pragma once
#include "gameObject.h"
#include "darkNight.h"
#include "player.h"

#define DARKTILEX (TILEX+3)
#define DARKTILEY (TILEY+3)

class weather : public gameObject
{
private:
	darkNight*			_darkNight[DARKTILEX][DARKTILEY];
	player*				_player;
	
	int					_saveIndexX;
	int					_saveIndexY;

public:

	HRESULT init(string name);
	void release();
	void update();
	void render();

	darkNight* getDarkKnight() { return _darkNight[TILEX][TILEY]; }

	void ifDeepNight(int indexX , int indexY );
	void ifMideNight(int indexX, int indexY);
	void ifEarlyNight(int indexX, int indexY);
	void ifBright(int indexX, int indexY);

	weather() {}
	virtual ~weather() {}
};

