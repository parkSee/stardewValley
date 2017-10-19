#include "stdafx.h"
#include "tileMap.h"
#include "testObject.h"


HRESULT tileMap::init()
{
	for (int j = 0; j < TILEY; ++j)
	{
		for (int i = 0; i < TILEX; ++i)
		{
			_pTile[i][j] = new mapToolTile;
			_pTile[i][j]->init(i, j);
		}
	}

	return S_OK;
}
void tileMap::release()
{

}
void tileMap::update()
{
	//Ÿ���� ������Ʈ ������ ���� -----


}
void tileMap::render()
{
	//Ÿ�� ���� - â�� ���̴� ��ŭ��!
	RECT renderRc = CAMERAMANAGER->getRenderRc();
	int startIndexX = renderRc.left / TILESIZE;
	int startIndexY = renderRc.top / TILESIZE;
	int endIndexX = renderRc.right / TILESIZE;
	int endIndexY = renderRc.bottom / TILESIZE;
	
	//Ÿ�� ���� ����°� ����
	if (startIndexX < 0) startIndexX = 0;
	if (startIndexY < 0) startIndexY = 0;
	if (endIndexX >= TILEX) endIndexX = TILEX - 1;
	if (endIndexY >= TILEY) endIndexY = TILEY - 1;
	
	for (int j = startIndexY; j <= endIndexY; ++j)
	{
		for (int i = startIndexX; i <= endIndexX; ++i)
		{
			_pTile[i][j]->render();
		}
	}
}


void tileMap::setTileFrameByAround(int indexX, int indexY)
{
	mapToolTile* tile = _pTile[indexX][indexY];

	TERRAIN::Enum terrain[3][3];
	for (int j = 0; j < 3; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			terrain[i][j] = TERRAIN::NONE;

			int x = indexX - 1 + i;
			int y = indexY - 1 + j;
			//Ÿ�� ���� ����°� ����
			if (x < 0 || x >= TILEX || y < 0 || y >= TILEY) continue;
			terrain[i][j] = _pTile[x][y]->getTerrain();
		}
	}

	switch (tile->getTerrain())
	{
	case TERRAIN::NONE:
		break;
	case TERRAIN::DIRT:
		break;
	case TERRAIN::GRASS:
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//�ֺ� �� �ܵ�
			tile->setFrameX(0); tile->setFrameY(7); break;
		}
		if (terrain[1][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::DIRT && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::DIRT &&
			terrain[1][2] == TERRAIN::DIRT)
		{		//�����¿� ��
			tile->setFrameX(6); tile->setFrameY(7); break;
		}
		if (terrain[0][0] == TERRAIN::DIRT && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//���� ���� ��
			tile->setFrameX(3); tile->setFrameY(10); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//������ ���� ��
			tile->setFrameX(0); tile->setFrameY(10); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::DIRT && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//���� �Ʒ��� ��
			tile->setFrameX(3); tile->setFrameY(8); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::DIRT)
		{		//������ �Ʒ��� ��
			tile->setFrameX(0); tile->setFrameY(8); break;
		}
		if (terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::DIRT && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//���� ��
			tile->setFrameX(3); tile->setFrameY(9); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::DIRT &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS)
		{		//������ ��
			tile->setFrameX(0); tile->setFrameY(9); break;
		}
		if (terrain[1][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//���� ��
			tile->setFrameX(1); tile->setFrameY(10); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[1][2] == TERRAIN::DIRT)
		{		//�Ʒ��� ��
			tile->setFrameX(1); tile->setFrameY(8); break;
		}
		if (terrain[1][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::DIRT && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//���� �� �� �ܵ�
			tile->setFrameX(3); tile->setFrameY(7); break;
		}
		if (terrain[1][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::DIRT &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS)
		{		//������ �� �� �ܵ�
			tile->setFrameX(2); tile->setFrameY(10); break;
		}
		if (terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::DIRT && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[1][2] == TERRAIN::DIRT)
		{		//���� �Ʒ� �� �ܵ�
			tile->setFrameX(2); tile->setFrameY(7); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::DIRT &&
			terrain[1][2] == TERRAIN::DIRT)
		{		//������ �Ʒ� �� �ܵ�
			tile->setFrameX(2); tile->setFrameY(8); break;
		}
		//�Էµ� ��Ȳ �ƴϸ� �ϳ�¥�� �ܵ��
		tile->setFrameX(6); tile->setFrameY(7); break;
		break;
	case TERRAIN::WATER:
		break;
	}
}
