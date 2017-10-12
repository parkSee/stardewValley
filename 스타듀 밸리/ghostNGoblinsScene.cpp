#include "stdafx.h"
#include "ghostNGoblinsScene.h"


ghostNGoblinsScene::ghostNGoblinsScene()
{
}


ghostNGoblinsScene::~ghostNGoblinsScene()
{

}

HRESULT ghostNGoblinsScene::init()
{
	_knight = new knight;
	_knight->init();

	return S_OK;
}

void ghostNGoblinsScene::release()
{

}

void ghostNGoblinsScene::update() 
{
	_knight->update();
}

void ghostNGoblinsScene::render() 
{
	_knight->render();
}
