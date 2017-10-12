#pragma once
#include "gameNode.h"

class pixelCollisionTest : public gameNode
{
private:
	image* _hill;	//������ �̹���
	image* _ball;	//�� �̹���

	RECT _rc;		//��Ʈ

	float _x, _y;	//��ǥ

	int _probeY;	//YŽ����
	

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	pixelCollisionTest();
	~pixelCollisionTest();
};

