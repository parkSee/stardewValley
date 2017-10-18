#include "stdafx.h"
#include "weather.h"

HRESULT weather::init(string name)
{
	gameObject::init(name);

	for (int j = 0; j <TILEY; j++)
	{
		for (int i = 0; i < TILEX; i++)
		{
			_darkNight[i][j] = new darkNight;
			_darkNight[i][j]->init("darkNight", "dark", tagFloat(TILESIZE / 2 + (TILESIZE*i), TILESIZE / 2 + TILESIZE*j),i,j);
		}
	}


	return S_OK;
}

void weather::release()
{
	gameObject::release();

	for (int j = 0; j <TILEY; j++)
	{
		for (int i = 0; i < TILEX; i++)
		{
			_darkNight[i][j]->release();
		}
	}
}

void weather::update() 
{
	gameObject::update();

	for (int j = 0; j <TILEY; j++)
	{
		for (int i = 0; i < TILEX; i++)
		{
			_darkNight[i][j]->update();
		}
	}
}

void weather::render() 
{

	for (int j = 0; j <TILEY; j++)
	{
		for (int i = 0; i < TILEX; i++)
		{
			_darkNight[i][j]->render();
		}
	}
}
