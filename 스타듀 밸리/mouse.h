#pragma once
#include "gameObject.h"

class mouse : public gameObject
{
private:
	float 			    _scale;		//���콺 �̹��� ������ 
	int					_alpha;		//���콺 �̹��� ���İ� ����
	bool				_isScaleUp;	//���콺 �̹��� ������ �Ұ�

	animation*			_selectAnimation;		//���콺 �̹��� ���ϸ��̼�
	animation*			_normalAnimation;		//���콺 �̹��� ���ϸ��̼� 
	
public:
	HRESULT init(string name);
	void release();
	void update();
	void render();

	void mouseControll();

	mouse() {}
	~mouse() {}
};

