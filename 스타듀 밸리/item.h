#pragma once
#include "worldNode.h"

//그냥 구조체랑 똑같다
//그냥 클래스로 빼놨을 뿐 

class gameObject;

namespace itemType
{
	enum Enum
	{
		FOOD, SEED, TOOL,SETTING, STONE, WOOD, NONE
	};
}

struct tagItem
{
	string				name;		//아이템 이름
	string				explain;	//아이템 설명
	image*				img;		//아이템 이미지
	itemType::Enum		type;		//아이템 타입 
	tagFloat			pos;		//아이템 포지션
	RECT				rc;			//아이템 렉트
	int					count;		//아이템 개수 
	float				size;		//이미지 사이즈
	//기본 생성자
	tagItem();	
	//한번에 초기화 해 줄수 있는 구조체 함수 
	tagItem(string Name,string Explain, tagFloat position = tagFloat(), int Count = 0 , itemType::Enum typ = itemType::NONE);
	//개수 증가 할때 사용할 함수 
	void addCount() { count++; }
};
