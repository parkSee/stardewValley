#pragma once
#include "gameNode.h"
#include "bullets.h"
#include "progressBar.h"

class enemyManager;

class spaceShip : public gameNode
{
private:
	image* _ship;

	missile* _missile;
	jericho* _jericho;

	enemyManager* _em;
	progressBar* _hpBar;

	float _maxHP, _currentHP;

	int _alphaValue;

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void removeMissile(int arrNum);

	void collision();

	void hitDamage(float damage);

	void setEnemyManagerMemoryAddressLink(enemyManager* em) { _em = em; }

	jericho* getJerichoMissile() { return _jericho; }
	image* getShipImage() { return _ship; }


	spaceShip();
	~spaceShip();
};

