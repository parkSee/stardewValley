#include "stdafx.h"
#include "Pierre.h"

HRESULT Pierre::init(string npcName, char* imageName, int indexX, int indexY)
{
	NPC::init(npcName, imageName, indexX, indexY);

	return S_OK;
}

void Pierre::release()  
{
	NPC::release();
}

void Pierre::update()   
{
	NPC::update();
}

void Pierre::render()   
{
	NPC::render();
}