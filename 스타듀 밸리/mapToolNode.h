#pragma once


#define TILESIZE 16
#define TILEX 20
#define TILEY 20
#define SPRITEX 25
#define SPRITEY 79
#define spriteNumber(i, j) i + j * SPRITEX

//������Ʈ �̳��� �����̰� �ٷ��
namespace OBJECT
{
	enum Enum
	{
		NONE,
		TREE1,
		TREE2,
		TREE3,
		BIG_TREE,
		BIG_BIG_TREE,
		STONE
	};
}

namespace SPRITE
{
	enum Enum
	{
		OUTDOORS_SPRING,
		FARM_BUILDINGS,
		FARMHOUSE,
		CROPS,
		TREES
	};
}
