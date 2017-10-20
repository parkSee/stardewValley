#include "stdafx.h"
#include "tileMap.h"

int tileMap::getHeuristic(int idX1, int idY1, int idX2, int idY2, bool eightDirection)
{
	////�Ʒ� ó�� �ϴ� �� ���� �� getDistance ���°� �� �����Ű���...�� �ƴѰ�?
	//return (int)getDistance(_pTile[idX1][idY1]->getRect().left, _pTile[idX1][idY1]->getRect().top,
	//	_pTile[idX2][idY2]->getRect().left, _pTile[idX2][idY2]->getRect().top);

	//�� �����Ÿ� ���ϱ� �ִܰ�� ��ã�°� �ƴұ�...�� ���� �����̾��� ����������������
	//�ε��� �޾Ƽ� �밢���̶� ���� �ؼ� �غ���
	int dx = abs(idX1 - idX2);
	int dy = abs(idY1 - idY2);
	int diagonal = min(dx, dy);
	return (dx - diagonal + dy - diagonal) * TILESIZE + diagonal * TILESIZE * sqrtf(2);
}
vector<mapToolTile*> tileMap::getShortestAStar(int startIdX, int startIdY, int endIdX, int endIdY, bool eightDirection)
{
	//������ ������ ������ �ٷ� ����
	if (startIdX == endIdX && startIdY == endIdY)
	{
		vector<mapToolTile*> nothing;
		return nothing;
	}

	//Ÿ�Ϲ��� ����� �Է°��� �ٷ� ����
	if (!(0 <= startIdX && startIdX < TILEX && 0 <= startIdY && startIdY < TILEY &&
		0 <= endIdX && endIdX < TILEX && 0 <= endIdY && endIdY < TILEY))
	{
		vector<mapToolTile*> nothing;
		return nothing;
	}

	//�ִ� ��� ���� (��� �ʱ�ȭ�� ���δ�)
	const int MAX = 0x0fffffff;

	//��� ����ü ����
	struct tagNode
	{
		mapToolTile* parent;
		bool isOpen;
		bool isClosed;
		int costTotal;
		int costFromStart;
		int costToEnd;

		tagNode() : parent(NULL), isOpen(false), isClosed(false),
			costTotal(MAX), costFromStart(MAX), costToEnd(MAX) {}
		//�����ڷ� �ʱ�ȭ �� �� ������ ���ִµ� ����� �����ϳ�
		//MAX�� const int �� �������Ѵ�

		void calculateTotal() { costTotal = costFromStart + costToEnd; }
	};

	//���� Ÿ�ϴ�� ��� ����
	//���� ���� �ε�����ȣ�� Ÿ���� �޸����̶�� ���� �ȴ�
	//�θ���, ��������, ��������, F, G, H
	tagNode node[TILEX][TILEY];
	//��� �ʱ�ȭ�� ��� �̴ϼȶ����� ��������� ����

	//������ ��� �ʱ�ȭ
	node[startIdX][startIdY].parent = NULL;
	node[startIdX][startIdY].isOpen = true;
	node[startIdX][startIdY].isClosed = true;
	node[startIdX][startIdY].costFromStart = 0;
	node[startIdX][startIdY].costToEnd = getHeuristic(startIdX, startIdY, endIdX, endIdY, eightDirection);
	node[startIdX][startIdY].calculateTotal();

	//������� ����
	vector<mapToolTile*> vOpen;

	//�������� ���� ����, �������� ����������
	//tagNode* startNode = &node[startIdX][startIdY];
	//tagNode* endNode = &node[endIdX][endIdY];
	//tagNode* current = startNode;
	mapToolTile* startTile = _pTile[startIdX][startIdY];
	mapToolTile* endTile = _pTile[endIdX][endIdY];
	mapToolTile* current = startTile;


	/*----------------------------------------------------------
	������ �������� �� ���� �ʱ�ȭ
	�Ʒ����� ����
	----------------------------------------------------------*/


	//���̽�Ÿ ��ã�� ����
	while (true)
	{
		if (current == NULL) break;   //������ġ

		int curX = current->getIndexX();
		int curY = current->getIndexY();

		//������ �߽� 9Ÿ�� Ž��
		for (int j = curY - 1; j <= curY + 1; ++j)
		{
			if (j < 0 || j >= TILEY) continue;
			for (int i = curX - 1; i <= curX + 1; ++i)
			{
				if (i < 0 || i >= TILEX) continue;

				//�ڱ� �ڽ��� continue
				if (i == curX && j == curY) continue;

				//8���� �̵� �Ұ����ϸ� (4���� �̵��� �����ϸ�) �����¿� �ƴϸ� continue
				if (!eightDirection)
				{
					if (!(i == curX && j == curY - 1 ||
						i == curX && j == curY + 1 ||
						i == curX - 1 && j == curY ||
						i == curX + 1 && j == curY)) continue;
				}
				else   //8���� �̵����� �������� ��ֹ��̸� �� ���� �밢�� �����ֱ�
				{
					if (!curX - 1 >= 0 && _pTile[curX - 1][curY]->getIsMovable())
						if (i == curX - 1 && j != curY) continue;
					if (!curX + 1 < TILEX && _pTile[curX + 1][curY]->getIsMovable())
						if (i == curX + 1 && j != curY) continue;
					if (!curY - 1 >= 0 && _pTile[curX][curY - 1]->getIsMovable())
						if (j == curY - 1 && i != curX) continue;
					if (!curY + 1 < TILEY && _pTile[curX][curY + 1]->getIsMovable())
						if (j == curY + 1 && i != curX) continue;
				}

				//���������� continue
				if (node[i][j].isClosed) continue;
				//��ֹ��̸� continue
				if (!_pTile[i][j]->getIsMovable())
				{
					node[i][j].isOpen = true;
					node[i][j].isClosed = true;
					continue;
				}

				//ó�� �� ����� ��Ȳ
				if (!node[i][j].isOpen)
				{
					node[i][j].isOpen = true;
					node[i][j].parent = current;
					node[i][j].costFromStart = node[curX][curY].costFromStart +
						getDistance(current->getRect().left, current->getRect().top,
							_pTile[i][j]->getRect().left, _pTile[i][j]->getRect().top);
					node[i][j].costToEnd = getHeuristic(i, j, endIdX, endIdY, eightDirection);
					node[i][j].calculateTotal();

					vOpen.push_back(_pTile[i][j]);
				}
				//���ô� ����� ��Ȳ
				else
				{
					//�޸���ƽ ���� ������ �ʴ´�
					//costFromStart�� ���ؼ� �� ������ ������
					int newG = node[curX][curY].costFromStart +
						getDistance(current->getRect().left, current->getRect().top,
							_pTile[i][j]->getRect().left, _pTile[i][j]->getRect().top);
					if (newG < node[i][j].costFromStart)
					{
						node[i][j].costFromStart = newG;
						node[i][j].calculateTotal();
						node[i][j].parent = current;
					}
				}
			}
		}

		//9Ÿ�� Ž���� ������ ���� ������Ͽ��� costTotal �ּ��� �� ����
		mapToolTile* tileMin = NULL;
		for (int i = 0; i < vOpen.size(); ++i)
		{
			if (vOpen[i] == current)
			{
				vOpen.erase(vOpen.begin() + i--);
				continue;
			}
			if (tileMin == NULL)
			{
				tileMin = vOpen[i];
				continue;
			}
			if (node[vOpen[i]->getIndexX()][vOpen[i]->getIndexY()].costTotal <
				node[tileMin->getIndexX()][tileMin->getIndexY()].costTotal)
			{
				tileMin = vOpen[i];
			}
		}
		//����Ÿ�� �������� true�� �ϰ� ����Ÿ�� ������Ͽ��� ����
		if (tileMin != NULL)
		{
			node[tileMin->getIndexX()][tileMin->getIndexY()].isClosed = true;

			//������� ������ tileMin�� ������ ã�Ƽ� �����ϴ� ������
			//���� ���� �������� �ϸ� ���ʿ��� ���� �ѹ��� ���� �� �ִ�
			//for (int i = 0; i < vOpen.size(); ++i)
			//{
			//	if (vOpen[i] == tileMin)
			//	{
			//		vOpen.erase(vOpen.begin() + i);
			//		break;
			//	}
			//}

			//����Ÿ���� ���� current�� ����
			current = tileMin;
		}
		else   //����Ÿ���� ���� == ��������� ����ִ� == �� �� �ִ� ���� ����
		{
			break;   //��ã�� ���� �����Ų��
		}

		// <��������> ����Ÿ���� ��ǥ�� ������ ��Ȳ
		if (tileMin == endTile)
		{
			vector<mapToolTile*> solution;
			vector<mapToolTile*> solutionReversed;
			mapToolTile* tempTile = current;

			//����Ÿ�Ϻ��� �θ� ���󰡸鼭 solutionReversed�� �߰�
			solutionReversed.push_back(tempTile);
			while (node[tempTile->getIndexX()][tempTile->getIndexY()].parent != NULL)
			{
				tempTile = node[tempTile->getIndexX()][tempTile->getIndexY()].parent;
				solutionReversed.push_back(tempTile);
			}

			//�ַ�Ǹ����� ����� �ַ�ǿ� ����ְ� ��ȯ
			for (int i = solutionReversed.size() - 1; i >= 0; --i)
			{
				solution.push_back(solutionReversed[i]);
			}
			return solution;
		}
		// <>
	}

	//��ã�� ������ ������������ ����� ��Ȳ
	//�� ���� ��ȯ���� ����
	vector<mapToolTile*> nothing;
	return nothing;
}
