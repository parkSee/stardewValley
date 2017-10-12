#pragma once
#include "gameNode.h"

//ºÎ¸ð²ø¶ó¾²~
class enemy : public gameNode
{
protected:
	image* _imageName;
	RECT _rc;

	int _currentFrameX;
	int _currentFrameY;

	int _count;
	int _fireCount;
	int _rndFireCount;

public:
	HRESULT init(void);
	HRESULT init(const char* imageName, POINT position);
	void release(void);
	void update(void);
	void render(void);

	void move(void);
	void draw(void);

	bool bulletCountFire(void);

	inline RECT getRect(void) { return _rc; }

	enemy();
	~enemy();
};

