#include "stdafx.h"
#include "loadingScene.h"

void loadingScene::soonwoo()
{
	//================================= UI 이미지들 ============================================================
	//마우스 커서 이미지 
	//_loading->loadFrameImage("mouse", "resource/UI/mouse.bmp", 66, 41, 2,1,true, RGB(255, 0, 255));
	_loading->loadFrameImage("selectMouse", "resource/UI/selectMouse.bmp",82,41,2,1, true, RGB(255, 0, 255));
	//검은 상자
	_loading->loadImage("blackBox", "resource/UI/fadeOut.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	//대화창 윈도우 이미지 
	_loading->loadImage("tokeWindow", "resource/UI/tokeWindow.bmp", 1000, 350, true, RGB(255, 0, 255));
	//대화창 볼 이미지
	_loading->loadImage("txtWindowBall", "resource/UI/txtWindowBall.bmp", 28, 28, true, RGB(255, 0, 255));
	//대화창 나가기 버튼 이미지 
	_loading->loadFrameImage("exit", "resource/UI/exit.bmp", 408, 47, 8, 1, true, RGB(255, 0, 255));
	//피레(pierre )UI 이미지 로드
	_loading->loadImage("pierreProfile", "resource/UI/pierreProfile.bmp", 74, 74, true, RGB(255, 0, 255));
	_loading->loadImage("pierreScroll", "resource/UI/pierreScroll.bmp", 320, 70, true, RGB(255, 0, 255));
	//캐롤라인(caroline) UI 이미지 로드
	_loading->loadImage("carolineProfile", "resource/UI/carolineProfile.bmp", 74, 74, true, RGB(255, 0, 255));
	_loading->loadImage("carolineScroll", "resource/UI/carolineScroll.bmp", 320, 70, true, RGB(255, 0, 255));
	//편지 관련 이미지 
	_loading->loadImage("letter", "resource/UI/letter.bmp", 1000, 733, true, RGB(255, 0, 255));
	_loading->loadImage("exit2", "resource/UI/exit2.bmp", 44, 44, true, RGB(255, 0, 255));
	//퍼블릭 UI 이미지
	_loading->loadImage("publicUI", "resource/UI/publicUI.bmp", 611, 112, true, RGB(255, 0, 255));
	_loading->loadImage("getItemUI", "resource/UI/getItemUI.bmp", 188, 96, true, RGB(255, 0, 255));
	//시간 윈도우 이미지 
	_loading->loadImage("timeWindow", "resource/UI/timeWindow.bmp", 288, 236, true, RGB(255, 0, 255));
	_loading->loadFrameImage("timePointer", "resource/UI/timePointer.bmp", 672, 151,7,1, true, RGB(255, 0, 255));

	//에너지 프로그래스 바 이미지
	_loading->loadImage("energyWindow", "resource/UI/energyWindow.bmp", 48, 244, true, RGB(255, 0, 255));
	_loading->loadImage("energyBackBar", "resource/UI/energyBackBar.bmp", 24, 183, true, RGB(255, 0, 255));
	_loading->loadImage("energyFrontBar", "resource/UI/energyFrontBar.bmp", 24, 183, true, RGB(255, 0, 255));

	//===============================인벤토리 및 아이템 이미지들================================================
	//메인인벤토리 창 이미지
	_loading->loadImage("mainInven1", "resource/UI/mainInven1.bmp", 859, 588, true, RGB(255, 0, 255));
	//서브 인벤토리 이미지
	_loading->loadImage("subInventory", "resource/UI/mainInventory.bmp", 800, 95, true, RGB(255, 0, 255));
	//아이템 아이콘 이미지들
	_loading->loadImage("도끼", "resource/item/axe.bmp", 56, 56, true, RGB(255, 0, 255));
	_loading->loadImage("괭이", "resource/item/hoe.bmp", 56, 56, true, RGB(255, 0, 255));
	_loading->loadImage("곡괭이", "resource/item/pixHoe.bmp", 56, 56, true, RGB(255, 0, 255));
	_loading->loadImage("낫", "resource/item/sickle.bmp", 56, 56, true, RGB(255, 0, 255));
	_loading->loadImage("물뿌리개", "resource/item/watering.bmp", 56, 56, true);
	_loading->loadImage("검", "resource/item/sword.bmp", 56, 56, true);
	_loading->loadImage("나무", "resource/item/wood.bmp", 56, 56, true);
	_loading->loadImage("돌맹이", "resource/item/stone.bmp", 56, 56, true);
	_loading->loadImage("석탄", "resource/item/coal.bmp", 56, 56, true);
	_loading->loadImage("수액", "resource/item/수액.bmp", 56, 56, true);
	_loading->loadImage("상자", "resource/item/chest.bmp", 56, 56, true);
	_loading->loadImage("울타리", "resource/item/fence.bmp", 56, 56, true);
	_loading->loadImage("사람", "resource/item/humanItem.bmp", 56, 56, true);
	_loading->loadImage("당근씨앗", "resource/item/당근씨앗.bmp", 56, 56, true);
	
	//인벤토리 설명 창 이미지
	_loading->loadImage("explainUI", "resource/UI/explainUI.bmp", 258, 214, true, RGB(255, 0, 255));
	_loading->loadImage("공간부족", "resource/UI/fullInventory.bmp", 56, 56, true, RGB(255, 0, 255));

	//========================================NPC=====================================
	_loading->loadFrameImage("pierre", "resource/npc/pierre.bmp", 128, 128,4,4, true, RGB(255, 0, 255));
	_loading->loadFrameImage("caroline", "resource/npc/calorine.bmp", 128, 128, 4, 4, true, RGB(255, 0, 255));
	//어둠 타일 이미지
	_loading->loadFrameImage("dark", "resource/UI/fadeOut.bmp", TILESIZE, TILESIZE, true, RGB(255, 0, 255));

	//선택지 UI 창 이미지
	_loading->loadImage("selectUI", "resource/UI/selectUI.bmp", 859, 276, true, RGB(255, 0, 255));
	//집 이미지
	_loading->loadImage("house", "resource/UI/house.bmp", 144*SCALE, 144*SCALE, true, RGB(255, 0, 255));
	//아이템 크리에이트 UI이미지
	_loading->loadImage("createItem", "resource/UI/createItem.bmp", 852, 354, true, RGB(255, 0, 255));
	
	_loading->loadFrameImage("chest_obj", "resource/item/chest_obj.bmp", 64, 92,1,1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("fence_obj", "resource/item/fence_obj.bmp", 48, 64, 1, 1, true, RGB(255, 0, 255));

	//사운드 로드 
	_loading->loadSound("bgm1", "resource/sound/bgm1.mp3", true, true);
	_loading->loadSound("bgm3", "resource/sound/bgm3.mp3", true, true);
	
}