#pragma once
#include "gameObject.h"
#include "item.h"

struct tagInvenItem
{
	image*		img;
};

class mouse : public gameObject
{
private:
	float 			    _scale;		//마우스 이미지 스케일 
	int					_alpha;		//마우스 이미지 알파값 조정
	bool				_isScaleUp;	//마우스 이미지 스케일 불값

	animation*			_selectAnimation;		//마우스 이미지 에니메이션
	animation*			_normalAnimation;		//마우스 이미지 에니메이션 
	
	tagInvenItem		_invenItem;

	bool				_isPicking;
	tagItem*			_tempItem;
public:
	HRESULT init(string name);
	void release();
	void update();
	void render();

	void mouseControll();

	mouse() 
	:_isPicking(false){}
	~mouse() {}
};

