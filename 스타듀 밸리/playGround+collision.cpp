#include "stdafx.h"
#include "playGround.h"

//혹시나 역시나 몰랐겠지만
//객체지향이 가능해지면서 헤더파일은 여러개 cpp파일을 가질수 있음.
//게임을 만들다보면 코딩량이 상당히 길어지기 때문에
//함수 별로 cpp파일에 각각 담아서 처리하면 가독성이 편해짐
//물론 유지보수도 편해진다

//예를 들면 playGround+init, playGround+release playGround+update
//이런식으로 초기화, 메모리해제, 연산, 그려주는 것등을 한 곳에서
//처리할 수 있다.


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