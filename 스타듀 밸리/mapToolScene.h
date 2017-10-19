#pragma once
#include "gameNode.h"		//이미 전역화 된 헤더지만 그냥 달아주자
#include "worldNode.h"		//이미 전역화 된 헤더지만 그냥 달아주자
#include "mapToolNode.h"
#include "tileMap.h"
#include "testObject.h"


class mapToolScene : public gameNode
{
private:
	enum MODE
	{
		MODE_MAP,
		MODE_SPRITE
	};
	enum KIND
	{
		KIND_NONE,
		KIND_TERRAIN,
		KIND_OBJECT
	};
	struct tagTileSampleRect
	{
		RECT rc;
		KIND kind;
		TERRAIN::Enum terrain;
		OBJECT::Enum object;
		string str;

		tagTileSampleRect() :
			rc({ 0,0,0,0 }), kind(KIND_NONE),
			terrain(TERRAIN::NONE), object(OBJECT::NONE), str("") {}

		void init()
		{
			rc = { 0,0,0,0 };
			kind = KIND_NONE;
			terrain = TERRAIN::NONE;
			object = OBJECT::NONE;
			str = "";
		}
	};
	//------------------------

	tileMap* _map;

	vector<RECT> _vSpriteRect;		//스프라이트 선택할 버튼 만들 렉트
	vector<tagTileSampleRect> _vtileSampleSelect;		//타일샘플 전용 선택버튼 구조체
	SPRITE::Enum _sprite;			//현재 선택한 스프라이트 이넘
	image* _spriteImage;			//현재 선택한 스프라이트의 이미지
	MODE _mode;						//맵인지 스프라이트인지 모드
	tagInt _mapCam, _spriteCam;		//맵이랑 스프라이트랑 왔다갔다 할 때 카메라 좌표 저장


	int _selectIdX, _selectIdY;

	//샘플타일용
	KIND _selectKind;
	TERRAIN::Enum _selectTerrain;
	OBJECT::Enum _selectObject;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void changeSprite(SPRITE::Enum spriteEnum);
	void leftClickInSprite();

	void setTileSampleSelect();
	void tileSampleToMap();

	mapToolScene() {}
	~mapToolScene() {}
};
