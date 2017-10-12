#pragma once
#include "gameNode.h"
#include "minion.h"	//붕어빵틀로 찍어낸 붕어빵1
#include "bullets.h"
#include <vector>

//상호참조 시 컴파일단계에서 헤더파일 무한루프를 빠져나오기 위한 
//전방선언 (실무에서는 남발수준으로 사용한다)
class spaceShip;

class enemyManager : public gameNode
{
private:
	typedef vector<enemy*> vEnemy;
	typedef vector<enemy*>::iterator viEnemy;

private:
	vEnemy _vMinion;
	viEnemy _viMinion;

	bullet* _bullet;

	spaceShip* _ship;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void setMinion(void);

	void minionBulletFire(void);

	void removeMinion(int arrNum);

	void collision(void);

	void setSpaceShipMemoryAddressLink(spaceShip* ship) { _ship = ship; }
	
	
	//선물 *^^*
	inline vector<enemy*> getVMinion(void) { return _vMinion; }
	inline vector<enemy*>::iterator getVIMinion(void) { return _viMinion; }



	enemyManager();
	~enemyManager();
};

