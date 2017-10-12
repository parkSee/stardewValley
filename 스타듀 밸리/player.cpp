#include "stdafx.h"
#include "player.h"

HRESULT player::init(string objName, tagFloat pos)
{
	//gameObject::init(objName,"player",tagFloat(WINSIZEX/2,WINSIZEY/2),pivot::BOTTOM);

//	_state = STAND;
	//_player.rc = RectMake(_pos.x, _pos.y, _image->getFrameWidth(), _image->getFrameHeight());

	return S_OK;
}
void player::release()
{
	//gameObject::release();
}
void player::update() 
{
	//gameObject::update();
}
void player::render() 
{
	//gameObject::render();

}

void player::stateUpdate(playerState::Enum state)
{
	switch (_state)
	{
	case playerState::STAND:							//¼­ÀÖ±â
		KEYANIMANAGER->findAnimation("playerStand");		
		break;
	case playerState::STAND_RIGHT:
		KEYANIMANAGER->findAnimation("rightStand");
		break;
	case playerState::STAND_LEFT:
		KEYANIMANAGER->findAnimation("leftStand");
		break;
	case playerState::STAND_BACK:
		KEYANIMANAGER->findAnimation("backStand");
		break;
	case playerState::RIGHT_RUN:
		break;
	case playerState::LEFT_RUN:
		break;
	case playerState::UP_RUN:
		break;
	case playerState::DOWN_RUN:
		break;
	case playerState::AXE_RIGHT:
		break;
	case playerState::AXE_LEFT:
		break;
	case playerState::AXE_UP:
		break;
	case playerState::AXE_DOWN:
		break;
	case playerState::HOE_RIGHT:
		break;
	case playerState::HOE_LEFT:
		break;
	case playerState::HOE_UP:
		break;
	case playerState::HOE_DOWN:
		break;
	case playerState::SICKLE_RIGHT:
		break;
	case playerState::SICKLE_LEFT:
		break;
	case playerState::SICKLE_UP:
		break;
	case playerState::SICKLE_DOWN:
		break;
	case playerState::WATER_RIGHT:
		break;
	case playerState::WATER_LEFT:
		break;
	case playerState::WATER_UP:
		break;
	case playerState::WATER_DOWN:
		break;
	default:
		break;
	}

	_state = state;
}
void player::changeState(playerState::Enum state)
{

}