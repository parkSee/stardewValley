#include "stdafx.h"
#include "pierre.h"

HRESULT pierre::init(string name, string imageKey, tagFloat pos)
{
	npc::init(name, imageKey, pos);

	return S_OK;
}

void pierre::release()
{
	npc::release();
}

void pierre::update() 
{
	npc::update();
}

void pierre::render() 
{
	npc::render();
}
