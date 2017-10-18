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

	_player = (player*)TOWNWORLD->findObject(objectType::HUMAN, "player");

	_saveIndexX = _player->getIndexX()+1;
	_saveIndexY = (_player->_pos.y - 50) / TILESIZE-1;

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
		
	//�ٽ� �ε��� �ʱ�ȭ
	_saveIndexX = playerIndexX;
	_saveIndexY = playerIndexY;


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



void weather::ifDeepNight(int indexX, int indexY)
{
	int playerIndexX = indexX;
	int playerIndexY = indexY;

	//�÷��̾ ���ִ� Ÿ��
	_darkNight[playerIndexX][playerIndexY]->_alpha = DARKLEVEL0;
	//�÷��̾ ���ִ� Ÿ�� �ٷ� ��
	_darkNight[playerIndexX + 1][playerIndexY]->_alpha = DARKLEVEL0;
	_darkNight[playerIndexX - 1][playerIndexY]->_alpha = DARKLEVEL0;
	_darkNight[playerIndexX][playerIndexY + 1]->_alpha = DARKLEVEL0;
	_darkNight[playerIndexX][playerIndexY - 1]->_alpha = DARKLEVEL0;
	//�÷��̾� ���ִ� Ÿ�� �밢�� ��
	_darkNight[playerIndexX + 1][playerIndexY + 1]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX - 1][playerIndexY + 1]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX + 1][playerIndexY - 1]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX - 1][playerIndexY - 1]->_alpha = DARKLEVEL1;
	//�÷��̾� ���ִ� Ÿ�� ���� 2ĭ
	_darkNight[playerIndexX + 2][playerIndexY]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX - 2][playerIndexY]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX][playerIndexY - 2]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX][playerIndexY + 2]->_alpha = DARKLEVEL1;
	//
	_darkNight[playerIndexX - 2][playerIndexY - 1]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX - 2][playerIndexY + 1]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX - 1][playerIndexY - 2]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX + 1][playerIndexY - 2]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX + 2][playerIndexY - 1]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX + 2][playerIndexY + 1]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX - 1][playerIndexY + 2]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX + 1][playerIndexY + 2]->_alpha = DARKLEVEL2;
	//3ĭ
	_darkNight[playerIndexX + 3][playerIndexY]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 3][playerIndexY]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX][playerIndexY - 3]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX][playerIndexY + 3]->_alpha = DARKLEVEL3;
	//
	_darkNight[playerIndexX - 2][playerIndexY + 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 2][playerIndexY + 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	//
	_darkNight[playerIndexX - 3][playerIndexY + 1]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 3][playerIndexY - 1]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 1][playerIndexY - 3]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 1][playerIndexY - 3]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 3][playerIndexY - 1]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 3][playerIndexY + 1]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 1][playerIndexY + 3]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 1][playerIndexY + 3]->_alpha = DARKLEVEL3;
}

void weather::ifMideNight(int indexX, int indexY)
{
	int playerIndexX = indexX;
	int playerIndexY = indexY;

	//�÷��̾ ���ִ� Ÿ��
	_darkNight[playerIndexX][playerIndexY]->_alpha = DARKLEVEL0;
	//�÷��̾ ���ִ� Ÿ�� �ٷ� ��
	_darkNight[playerIndexX + 1][playerIndexY]->_alpha = DARKLEVEL0;
	_darkNight[playerIndexX - 1][playerIndexY]->_alpha = DARKLEVEL0;
	_darkNight[playerIndexX][playerIndexY + 1]->_alpha = DARKLEVEL0;
	_darkNight[playerIndexX][playerIndexY - 1]->_alpha = DARKLEVEL0;
	//�÷��̾� ���ִ� Ÿ�� �밢�� ��
	_darkNight[playerIndexX + 1][playerIndexY + 1]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX - 1][playerIndexY + 1]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX + 1][playerIndexY - 1]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX - 1][playerIndexY - 1]->_alpha = DARKLEVEL1;
	//�÷��̾� ���ִ� Ÿ�� ���� 2ĭ
	_darkNight[playerIndexX + 2][playerIndexY]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX - 2][playerIndexY]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX][playerIndexY - 2]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX][playerIndexY + 2]->_alpha = DARKLEVEL1;
	//
	_darkNight[playerIndexX - 2][playerIndexY - 1]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX - 2][playerIndexY + 1]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX - 1][playerIndexY - 2]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX + 1][playerIndexY - 2]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX + 2][playerIndexY - 1]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX + 2][playerIndexY + 1]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX - 1][playerIndexY + 2]->_alpha = DARKLEVEL2;
	_darkNight[playerIndexX + 1][playerIndexY + 2]->_alpha = DARKLEVEL2;
	//3ĭ
	_darkNight[playerIndexX + 3][playerIndexY]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 3][playerIndexY]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX][playerIndexY - 3]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX][playerIndexY + 3]->_alpha = DARKLEVEL3;
	//
	_darkNight[playerIndexX - 2][playerIndexY + 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 2][playerIndexY + 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	//
	_darkNight[playerIndexX - 3][playerIndexY + 1]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 3][playerIndexY - 1]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 1][playerIndexY - 3]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 1][playerIndexY - 3]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 3][playerIndexY - 1]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 3][playerIndexY + 1]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX - 1][playerIndexY + 3]->_alpha = DARKLEVEL3;
	_darkNight[playerIndexX + 1][playerIndexY + 3]->_alpha = DARKLEVEL3;
}
void weather::ifEarlyNight(int indexX, int indexY)
{
	int playerIndexX = indexX;
	int playerIndexY = indexY;

	//�÷��̾ ���ִ� Ÿ��
	_darkNight[playerIndexX][playerIndexY]->_alpha = DARKLEVEL0;
	//�÷��̾ ���ִ� Ÿ�� �ٷ� ��
	_darkNight[playerIndexX + 1][playerIndexY]->_alpha = DARKLEVEL0;
	_darkNight[playerIndexX - 1][playerIndexY]->_alpha = DARKLEVEL0;
	_darkNight[playerIndexX][playerIndexY + 1]->_alpha = DARKLEVEL0;
	_darkNight[playerIndexX][playerIndexY - 1]->_alpha = DARKLEVEL0;
	//�÷��̾� ���ִ� Ÿ�� �밢�� ��
	_darkNight[playerIndexX + 1][playerIndexY + 1]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX - 1][playerIndexY + 1]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX + 1][playerIndexY - 1]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX - 1][playerIndexY - 1]->_alpha = DARKLEVEL1;
	//�÷��̾� ���ִ� Ÿ�� ���� 2ĭ
	_darkNight[playerIndexX + 2][playerIndexY]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX - 2][playerIndexY]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX][playerIndexY - 2]->_alpha = DARKLEVEL1;
	_darkNight[playerIndexX][playerIndexY + 2]->_alpha = DARKLEVEL1;
	//
	//_darkNight[playerIndexX - 2][playerIndexY - 1]->_alpha = DARKLEVEL2;
	//_darkNight[playerIndexX - 2][playerIndexY + 1]->_alpha = DARKLEVEL2;
	//_darkNight[playerIndexX - 1][playerIndexY - 2]->_alpha = DARKLEVEL2;
	//_darkNight[playerIndexX + 1][playerIndexY - 2]->_alpha = DARKLEVEL2;
	//_darkNight[playerIndexX + 2][playerIndexY - 1]->_alpha = DARKLEVEL2;
	//_darkNight[playerIndexX + 2][playerIndexY + 1]->_alpha = DARKLEVEL2;
	//_darkNight[playerIndexX - 1][playerIndexY + 2]->_alpha = DARKLEVEL2;
	//_darkNight[playerIndexX + 1][playerIndexY + 2]->_alpha = DARKLEVEL2;
	////3ĭ
	//_darkNight[playerIndexX + 3][playerIndexY]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX - 3][playerIndexY]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX][playerIndexY - 3]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX][playerIndexY + 3]->_alpha = DARKLEVEL3;
	////
	//_darkNight[playerIndexX - 2][playerIndexY + 2]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX - 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX - 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX + 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX + 2][playerIndexY + 2]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX + 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX + 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX - 2][playerIndexY - 2]->_alpha = DARKLEVEL3;
	////
	//_darkNight[playerIndexX - 3][playerIndexY + 1]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX - 3][playerIndexY - 1]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX - 1][playerIndexY - 3]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX + 1][playerIndexY - 3]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX + 3][playerIndexY - 1]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX + 3][playerIndexY + 1]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX - 1][playerIndexY + 3]->_alpha = DARKLEVEL3;
	//_darkNight[playerIndexX + 1][playerIndexY + 3]->_alpha = DARKLEVEL3;
}
void weather::ifBright(int indexX, int indexY)
{

}




