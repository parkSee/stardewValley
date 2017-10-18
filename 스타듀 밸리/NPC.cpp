#include "stdafx.h"
#include "npc.h"

using namespace npcDirection;

HRESULT npc::init(string name, string imageKey,tagFloat pos)
{
	gameObject::init(name,imageKey,pos);

	_image = IMAGEMANAGER->findImage(imageKey);

	_animation->init(_image->getWidth(), _image->getHeight(), _image->getFrameWidth(), _image->getFrameHeight());

	this->keyAniInit(name,imageKey);

	_direction = STAND_DOWN;
	
	_scale = 4.0f;

	_animation = KEYANIMANAGER->findAnimation(_keyAniString.standDown);
	_animation->start();

	_collisionRc = { getRect().left + 25,getRect().top + 25,getRect().right - 25,getRect().bottom - 25 };


	this->addCallback("changeState", [this](tagMessage msg)
	{
		this->changeState((Enum)msg.data);
	});
	//msg.targetList에 이동 경로를 담아서 보내주면 그 정보를  가지고 움직이게 한다.
	this->addCallback("setMoveRoute", [this](tagMessage msg)
	{
		this->setMoveRoute(msg);
	});
	

	return S_OK;
}
void npc::release()
{

}
void npc::update() 
{
	_collisionRc = { getRect().left + 25,getRect().top + 10,getRect().right - 25,getRect().bottom - 10 };
}
void npc::render() 
{
	RECT npcRc = this->getRect();
	RECT cameraRc = CAMERAMANAGER->getRenderRc();

	//Rectangle(getMemDC(), npcRc.left - cameraRc.left, npcRc.top - cameraRc.top,
	//	npcRc.right- cameraRc.left, npcRc.bottom - cameraRc.top);

	_image->scaleAniRender(getMemDC(), npcRc.left - cameraRc.left, npcRc.top - cameraRc.top, _animation, 
		_image->getFrameWidth() * _scale, _image->getFrameHeight() * _scale);

	//RectangleMakeCenter(getMemDC(), _pos.x- cameraRc.left, _pos.y- cameraRc.top, 30, 30);

}

RECT npc::getRect()
{
	RECT rc;

	rc.left = _pos.x - (_image->getFrameWidth()*_scale)/2;
	rc.right = _pos.x +(_image->getFrameWidth()*_scale)/2;
	rc.bottom = _pos.y;
	rc.top = _pos.y -_image->getFrameHeight() *_scale;

	return rc;
}

void npc::keyAniInit(string name, string imageKey)
{
	_keyAniString.standLeft = "standLeft_";
	_keyAniString.standRight = "standRight_";
	_keyAniString.standDown = "standDown_";
	_keyAniString.standUp = "standUp_";
	_keyAniString.moveDown = "moveDown_";
	_keyAniString.moveUp = "moveUp_";
	_keyAniString.moveRight = "moveRight_";
	_keyAniString.moveLeft = "moveLeft_";

	_keyAniString.standLeft += name;
	_keyAniString.standRight += name;
	_keyAniString.standDown += name;
	_keyAniString.standUp += name;
	_keyAniString.moveDown += name;
	_keyAniString.moveUp += name;
	_keyAniString.moveRight += name;
	_keyAniString.moveLeft += name;
	
	int standDown[]{ 0 };
	KEYANIMANAGER->addArrayFrameAnimation(_keyAniString.standDown,imageKey, standDown, 1, 10, false);
	
	int standRight[]{ 4 };
	KEYANIMANAGER->addArrayFrameAnimation(_keyAniString.standRight, imageKey, standRight, 1, 10, false);

	int standUp[]{ 8 };
	KEYANIMANAGER->addArrayFrameAnimation(_keyAniString.standUp, imageKey, standUp, 1, 10, false);

	int standLeft[]{ 12 };
	KEYANIMANAGER->addArrayFrameAnimation(_keyAniString.standLeft, imageKey, standLeft, 1, 10, false);

	int moveDown[]{ 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation(_keyAniString.moveDown, imageKey, moveDown, 4, 10, false);

	int moveRight[]{ 4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation(_keyAniString.moveRight, imageKey, moveRight, 4, 10, false);
	
	int moveUp[]{ 8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation(_keyAniString.moveUp, imageKey, moveUp, 4, 10, false);

	int moveLeft[]{ 12,13,14,15 };
	KEYANIMANAGER->addArrayFrameAnimation(_keyAniString.moveLeft, imageKey, moveLeft, 4, 10, false);
	
}