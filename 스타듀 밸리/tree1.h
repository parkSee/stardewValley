#pragma once
#include "motherObject.h"

class tree1 : public motherObject
{
public:
	tree1() {}
	~tree1() {}

	int _treeNum;

	virtual HRESULT init(tagFloat pos);
	virtual void release();
	virtual void update();
	virtual void render();


};

class tree1_bottom : public motherObject
{
public:
	tree1_bottom() {}
	~tree1_bottom() {}

	virtual HRESULT init(tagFloat pos);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void setDestroy(float time = 0.0f);


	void bottomAttack();
};

class tree1_top : public motherObject
{
public:
	tree1_top() {}
	~tree1_top() {}

	float _count;
	bool _isDie;

	virtual HRESULT init(tagFloat pos);
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void setDestroy(float time = 0.0f);

	void topAttack();
};
