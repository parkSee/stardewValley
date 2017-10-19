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
	//타일은 업데이트 돌리지 말자 -----


}
void tileMap::render()
{
	//타일 렌더 - 창에 보이는 만큼만!
	RECT renderRc = CAMERAMANAGER->getRenderRc();
	int startIndexX = renderRc.left / TILESIZE;
	int startIndexY = renderRc.top / TILESIZE;
	int endIndexX = renderRc.right / TILESIZE;
	int endIndexY = renderRc.bottom / TILESIZE;
	
	//타일 범위 벗어나는거 방지
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
			//타일 범위 벗어나는거 방지
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
		{		//주변 다 잔디
			tile->setFrameX(0); tile->setFrameY(7); break;
		}
		if (terrain[1][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::DIRT && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::DIRT &&
			terrain[1][2] == TERRAIN::DIRT)
		{		//상하좌우 흙
			tile->setFrameX(6); tile->setFrameY(7); break;
		}
		if (terrain[0][0] == TERRAIN::DIRT && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//왼쪽 위만 흙
			tile->setFrameX(3); tile->setFrameY(10); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//오른쪽 위만 흙
			tile->setFrameX(0); tile->setFrameY(10); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::DIRT && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//왼쪽 아래만 흙
			tile->setFrameX(3); tile->setFrameY(8); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::DIRT)
		{		//오른쪽 아래만 흙
			tile->setFrameX(0); tile->setFrameY(8); break;
		}
		if (terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::DIRT && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//왼쪽 흙
			tile->setFrameX(3); tile->setFrameY(9); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::DIRT &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS)
		{		//오른쪽 흙
			tile->setFrameX(0); tile->setFrameY(9); break;
		}
		if (terrain[1][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//위쪽 흙
			tile->setFrameX(1); tile->setFrameY(10); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[1][2] == TERRAIN::DIRT)
		{		//아래쪽 흙
			tile->setFrameX(1); tile->setFrameY(8); break;
		}
		if (terrain[1][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::DIRT && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[1][2] == TERRAIN::GRASS && terrain[2][2] == TERRAIN::GRASS)
		{		//왼쪽 위 끝 잔디
			tile->setFrameX(3); tile->setFrameY(7); break;
		}
		if (terrain[1][0] == TERRAIN::DIRT &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::DIRT &&
			terrain[0][2] == TERRAIN::GRASS && terrain[1][2] == TERRAIN::GRASS)
		{		//오른쪽 위 끝 잔디
			tile->setFrameX(2); tile->setFrameY(10); break;
		}
		if (terrain[1][0] == TERRAIN::GRASS && terrain[2][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::DIRT && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::GRASS &&
			terrain[1][2] == TERRAIN::DIRT)
		{		//왼쪽 아래 끝 잔디
			tile->setFrameX(2); tile->setFrameY(7); break;
		}
		if (terrain[0][0] == TERRAIN::GRASS && terrain[1][0] == TERRAIN::GRASS &&
			terrain[0][1] == TERRAIN::GRASS && terrain[1][1] == TERRAIN::GRASS && terrain[2][1] == TERRAIN::DIRT &&
			terrain[1][2] == TERRAIN::DIRT)
		{		//오른쪽 아래 끝 잔디
			tile->setFrameX(2); tile->setFrameY(8); break;
		}
		//입력된 상황 아니면 하나짜리 잔디로
		tile->setFrameX(6); tile->setFrameY(7); break;
		break;
	case TERRAIN::WATER:
		break;
	}
}
