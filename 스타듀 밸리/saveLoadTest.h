#pragma once
#include "gameNode.h"

class saveLoadTest : public gameNode
{
public:
	void update(void);
	void save(void);
	void load(void);


	saveLoadTest();
	~saveLoadTest();
};

