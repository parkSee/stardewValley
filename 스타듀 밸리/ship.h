#pragma once
#include "gameNode.h"
#include "bullets.h"

//�� == ���� ��
class ship : public gameNode
{
protected:
	bullet* _bullet;

	image* _image;	//��� ���� �̹���
	RECT _rc;		//��Ʈ
	float _x, _y;	//��ǥ
	float _angle;	//�ޱ�
	float _speed;	//���ǵ�
	float _radius;	//������
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

