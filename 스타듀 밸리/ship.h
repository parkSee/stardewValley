#pragma once
#include "gameNode.h"
#include "bullets.h"

//모선 == 마덜 쉽
class ship : public gameNode
{
protected:
	bullet* _bullet;

	image* _image;	//모든 쉽의 이미지
	RECT _rc;		//렉트
	float _x, _y;	//좌표
	float _angle;	//앵글
	float _speed;	//스피드
	float _radius;	//반지름
public:
	virtual HRESULT init(const char* imageName, int x, int y);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	virtual void draw(void);
	virtual void keyControl(void);
	virtual void move();

	virtual void bulletFire();
	virtual void bulletMove();
	virtual void bulletDraw();

	virtual void focusDraw(void);
	virtual void defaultDraw(RECT rcFocus);
	
	image* getImage() { return _image; }
	RECT getRect() { return _rc; }

	void setAngle(float angle) { _angle = angle; }
	float getAngle() { return _angle; }

	ship();
	virtual ~ship();
};

