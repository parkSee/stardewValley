#include "stdafx.h"
#include "weather.h"

HRESULT weather::init(string name)
{
	gameObject::init(name);

	for (int j = 0; j <DARKTILEY; j++)
	{
		for (int i = 0; i < DARKTILEX; i++)
		{
			_darkNight[i][j] = new darkNight;
			_darkNight[i][j]->init("darkNight", "dark", tagFloat(TILESIZE / 2 + (TILESIZE*i), TILESIZE / 2 + TILESIZE*j),i,j);
		}
	}

	_player = (player*)TOWNWORLD->findObject(objectType::HUMAN, "player");


	return S_OK;
}

void weather::release()
{
	gameObject::release();

	for (int j = 0; j <DARKTILEY; j++)
	{
		for (int i = 0; i < DARKTILEX; i++)
		{
			_darkNight[i][j]->release();
		}
	}
}

void weather::update() 
{
	gameObject::update();

	int playerIndexX = _player->getIndexX();
	int playerIndexY = (_player->_pos.y - 50) / TILESIZE;
	
	if (WORLDTIME->_dayDirection == dayDirection::DEEP_NIGHT)
	{
		this->ifDeepNight(playerIndexX, playerIndexY);
	}
	else if (WORLDTIME->_dayDirection == dayDirection::MID_NIGHT)
	{
		this->ifMideNight(playerIndexX, playerIndexY);
	}
	else if (WORLDTIME->_dayDirection == dayDirection::EARLY_NIGHT)
	{
		this->ifEarlyNight(playerIndexX, playerIndexY);
	}
	

}

void weather::render() 
{

	for (int j = 0; j <DARKTILEY; j++)
	{
		for (int i = 0; i < DARKTILEX; i++)
		{
			_darkNight[i][j]->render();
		}
	}

}



void weather::ifDeepNight(int indexX, int indexY)
{
	int playerIndexX = indexX;
	int playerIndexY = indexY;


	for (int j = playerIndexY - 3; j <= playerIndexY + 3; j++)
	{
		for (int i = playerIndexX - 3; i <= playerIndexX + 3; ++i)
		{
			if (i < 0 || i > TILEX || j <0 || j>TILEY)continue;

			switch (abs(i-playerIndexX) + abs(j-playerIndexY))
			{
			case 0:case 1:
			{
				_darkNight[i][j]->_alpha = DARKLEVEL0;
			}
				break;
			case 2:
			{
				_darkNight[i][j]->_alpha = DARKLEVEL1;
			}
				break;
			case 3:
			{
				_darkNight[i][j]->_alpha = DARKLEVEL2;
			}
				break;
			case 4:
			{
				_darkNight[i][j]->_alpha = DARKLEVEL3;
			}
				break;
			default:
				break;
			}
		}
	}

}

void weather::ifMideNight(int indexX, int indexY)
{
	int playerIndexX = indexX;
	int playerIndexY = indexY;

	for (int j = playerIndexY - 3; j <= playerIndexY + 3; j++)
	{
		for (int i = playerIndexX - 3; i <= playerIndexX + 3; ++i)
		{
			if (i < 0 || i > TILEX || j < 0 || j > TILEY)continue;

			switch (abs(i - playerIndexX) + abs(j - playerIndexY))
			{
			case 0:case 1:
			{
				_darkNight[i][j]->_alpha = DARKLEVEL0;
			}
			break;
			case 2:
			{
				_darkNight[i][j]->_alpha = DARKLEVEL1;
			}
			break;
			case 3:
			{
				_darkNight[i][j]->_alpha = DARKLEVEL2;
			}
			break;
			case 4:
			{
				_darkNight[i][j]->_alpha =175;
			}
			break;
			default:
				break;
			}
		}
	}
}
void weather::ifEarlyNight(int indexX, int indexY)
{
	int playerIndexX = indexX;
	int playerIndexY = indexY;

	for (int j = playerIndexY - 3; j <= playerIndexY + 3; j++)
	{
		for (int i = playerIndexX - 3; i <= playerIndexX + 3; ++i)
		{
			if (i < 0 || i > TILEX || j < 0 || j > TILEY)continue;

			switch (abs(i - playerIndexX) + abs(j - playerIndexY))
			{
			case 0:case 1:
			{
				_darkNight[i][j]->_alpha = DARKLEVEL0;
			}
			break;
			case 2:
			{
				_darkNight[i][j]->_alpha = 30;
			}
			break;
			case 3:
			{
				_darkNight[i][j]->_alpha = 60;
			}
			break;
			case 4:
			{
				_darkNight[i][j]->_alpha =80;
			}
			break;
			default:
				break;
			}
		}
	}
}
void weather::ifBright(int indexX, int indexY)
{

}




