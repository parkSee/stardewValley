#pragma once
#include "gameNode.h"

class animation;

class effect : public gameNode
{
protected:
	int _x;
	int _y;

	image* _effectImage;			//이펙트 이미지
	animation* _effectAnimation;	//이펙트 애니메이션
	BOOL _isRunning;				//이펙트 활성화 여부
	float _elapsedTime;

public:
	virtual HRESULT init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void startEffect(int x, int y);

	virtual void killEffect(void);

	BOOL getIsRunning(void) { return _isRunning; }



	effect();
	~effect();
};

