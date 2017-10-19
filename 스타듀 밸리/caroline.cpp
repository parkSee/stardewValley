#include "stdafx.h"
#include "caroline.h"


caroline::caroline()
{
}


caroline::~caroline()
{
}


HRESULT caroline::init(string name, string imageKey, tagFloat pos)
{
	npc::init(name, imageKey, pos);

	return S_OK;
}

void caroline::release()
{
	npc::release();
}

void caroline::update()
{
	npc::update();
}

void caroline::render()
{
	npc::render();
}
