#include "stdafx.h"
#include "motherObject.h"
#include "dropItem.h"

HRESULT motherObject::init(string objName, string imageKey, tagFloat pos, pivot::Enum pivot)
{
	gameObject::init(objName, imageKey, pos, pivot);

	_frameX = _frameY = 0;
	_idX = _idY = 0;
	_hp = 1;
	_pObj = NULL;

	_object = OBJECT::NONE;
	Motion == NULL;

	return S_OK;
}
void motherObject::release()
{
	gameObject::release();
}
void motherObject::update()
{
	gameObject::update();

}
void motherObject::render()
{

}
