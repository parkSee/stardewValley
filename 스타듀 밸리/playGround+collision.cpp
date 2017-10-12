#include "stdafx.h"
#include "playGround.h"

//Ȥ�ó� ���ó� ����������
//��ü������ ���������鼭 ��������� ������ cpp������ ������ ����.
//������ ����ٺ��� �ڵ����� ����� ������� ������
//�Լ� ���� cpp���Ͽ� ���� ��Ƽ� ó���ϸ� �������� ������
//���� ���������� ��������

//���� ��� playGround+init, playGround+release playGround+update
//�̷������� �ʱ�ȭ, �޸�����, ����, �׷��ִ� �͵��� �� ������
//ó���� �� �ִ�.


void playGround::collision(void)
{
	for (int i = 0; i < _ship->getJerichoMissile()->getVBullet().size(); i++)
	{
		for (int j = 0; j < _em->getVMinion().size(); j++)
		{
			RECT temp;
			if (IntersectRect(&temp, &_ship->getJerichoMissile()->getVBullet()[i].rc,
				&_em->getVMinion()[j]->getRect()))
			{
				_ship->getJerichoMissile()->removeMissile(i);
				_em->removeMinion(j);
				break;
			}
		}
	}
}