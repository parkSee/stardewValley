#pragma once
#include "gameObject.h"
#include "dropItem.h"

// 월드노드에 넣을 거양 ============================================================
namespace OBJECT
{
	enum Enum
	{
		NONE,
		STONE,
		LAND,
		WETLAND,
		SEED,
		TREE1_BOTTOM,
		TREE1_TOP,
		TREE2,
		TREE3,
		GRASS
	};
}
// ===============================================================================


class motherObject : public gameObject
{
protected:
	int _frameX, _frameY;
	int _idX, _idY;
	int _hp;
	gameObject* _pObj;
	animation* Motion;
public:
	motherObject() {}
	~motherObject() {}

	OBJECT::Enum _object;

	virtual HRESULT init(string objName, string imageKey = "", tagFloat pos = tagFloat(), pivot::Enum pivot = pivot::CENTER);
	virtual void release();
	virtual void update();
	virtual void render();

	inline int getFrameX() { return _frameX; }
	inline int getFrameY() { return _frameY; }
	inline int getIdX() { return _idX; }
	inline int getIdY() { return _idY; }
	inline gameObject* getPObj() { return _pObj; }

	inline void setFrameX(int x) { _frameX = x; }
	inline void setFrameY(int y) { _frameY = y; }
	inline void setIdX(int x) { _idX = x; }
	inline void setIdY(int y) { _idY = y; }
	inline void setPobj(gameObject* pobj) { _pObj = pobj; }
};
