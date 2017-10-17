#pragma once


//#define SCALE 4
//#define TILESIZE (16 * SCALE)
//#define TILEX 43
//#define TILEY 27
#define SPRITEX 25
#define SPRITEY 79
#define spriteNumber(i, j) ((i) + (j) * SPRITEX)

////오브젝트 이넘은 동진이가 다룰거
//namespace OBJECT
//{
//	enum Enum
//	{
//		NONE,
//		FARMLAND,
//		SEED,
//		TREE1,
//		TREE2,
//		TREE3,
//		BIG_TREE,
//		BIG_BIG_TREE,
//		STONE,
//		END
//	};
//}
//namespace TERRAIN
//{
//	enum Enum
//	{
//		NONE,
//		DIRT,
//		GRASS,
//		WATER,
//		END
//	};
//}

namespace SPRITE
{
	enum Enum
	{
		OUTDOORS_SPRING,
		FARM_BUILDINGS,
		FARMHOUSE,
		CROPS,
		TREES,
		TILESAMPLE,
		END
	};
}
