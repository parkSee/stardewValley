#pragma once
#include "motherObject.h"

class land  : public motherObject
{
private:
	bool _isWet;
	RECT _rc;
public:
	land() {}
	~land() {}

	

	virtual HRESULT init(tagFloat pos);
	virtual void release();
	virtual void update();
	virtual void render();

	inline bool getWet() { return  _isWet; }

	inline void setWet(bool isWet) { _isWet = isWet; }

	void hoeAttack();

};



