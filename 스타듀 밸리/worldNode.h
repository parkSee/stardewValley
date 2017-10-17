#pragma once
#include <functional>

//모든 스탯 및 초기 값 디파인은 여기서 해준다
//이렇게 해주면 추 후 밸런스 조절 시 쉽게 조정 가능 

//ex) #define PLAYERSPEED 5
//player->init()에서 _player.speed = PLAYERSPEED

//우리 모든 아이들의 좌표
//POINTFLOAT이란게 있지만 그건 기본생성자만 있을 뿐 구조체째로 값을 초기화 해주는 그거 두번째 함수가 없기때문에 만들었음
struct tagFloat
{
	float x;
	float y;

	tagFloat() { x = 0; y = 0; };
	tagFloat(float X, float Y) { x = X; y = Y; }
};

namespace OBJECT
{
	enum Enum
	{
		NONE,
		STONE,
		FARMLAND,
		SEED,
		TREE1_BOTTOM,
		TREE1_TOP,
		TREE1,
		TREE2,
		TREE3,
		BIG_TREE,
		BIG_BIG_TREE,
		GRASS,
		END
	};
}

namespace TERRAIN
{
	enum Enum
	{
		NONE,
		DIRT,
		GRASS,
		WATER,
		END
	};
}

//================== 타일 =====================
#define SCALE 4
#define TILESIZE (16 * SCALE)
#define TILEX 43
#define TILEY 27


//=================== UI ======================

//콜백~
typedef std::function<void()> CBFUNCTION;

//대화창 인물 디파인 
#define CAROLINE			0
#define PIERRE				1

#define PERRETESTCONVERSATION "string도 이렇게 디파인을 걸어서 대화집을 만들어 놓을 수 있단다."

//메세지 통신 txt디파인

//publicUI 클래스 콜백 함수 관련
#define ADDGUIDEUI		"addGuideUI"		//가이드 UI창 콜백 메세지 이름 , msg.conversatoin 에 띄울 스트링을 입력해주면 된다.
#define ADDGETITEMUI	"addGetItemUI"		//아이템 얻었을 때 나오는 UI메세지 이름, msg.conversation에 아이템 이름(키값)을 입력

//inventory클래스 콜백 함수 관련 
#define SETTARGETTIEM	"setTargetItem"		//타겟 아이템 바뀔때 메세지 이름,msg.conversation에 아이템 이름(키값)을 입력 
#define ADDITEM			"addItem"			//아이템 인벤토리에 추가 콜백 메세지,
											//msg.converstation에 아이템 이름 ,msg.str에 아이템 부가 설명을 넣어준다.

//대화창 및 편지창 UI콜백 함수 관련
#define CONVERSATIONUI	"conversation"		//대화창 생성 메세지 이름, msg.conversation에 넣을 대화string을 입력
											//msg.data에 인물 번호코드 디파인을 넣어준다 ex)PIERRE || CAROLINE

