#pragma once
#include "gameObject.h"
#include "dropItem.h"

// 월드노드에 넣을 거양 ============================================================

// ===============================================================================


class motherObject : public gameObject
{
protected:
	int _frameX, _frameY;
	int _idX, _idY;
	int _hp;
	animation* Motion;
public:
	virtual HRESULT init(string objName, string imageKey = "", tagFloat pos = tagFloat(), pivot::Enum pivot = pivot::CENTER);
	virtual void release();
	virtual void update();
	virtual void render();

	inline int getFrameX() { return _frameX; }
	inline int getFrameY() { return _frameY; }
	inline int getIdX() { return _idX; }
	inline int getIdY() { return _idY; }
	

	inline void setFrameX(int x) { _frameX = x; }
	inline void setFrameY(int y) { _frameY = y; }
	inline void setIdX(int x) { _idX = x; }
	inline void setIdY(int y) { _idY = y; }

	motherObject() {}
	virtual ~motherObject() {}
};
