#include "stdafx.h"
#include "UI.h"
#include "worldNode.h"

using namespace uiDirection;

HRESULT UI::init(string objName)
{
	gameObject::init(objName,"mouse");
	//UI 초기화
	_direction = NORMAL;					
	//대화창 구조체 초기화 
	ZeroMemory(&_conversation, sizeof(tagConverSation));
	_conversation.window = IMAGEMANAGER->findImage("tokeWindow");
	_conversation.who = IMAGEMANAGER->findImage("storeNPC");
	_conversation.scroll = IMAGEMANAGER->findImage("pierre");
	_conversation.ball = IMAGEMANAGER->findImage("txtWindowBall");
	//대화창 관련 변수들 초기화 
	_conversation.size = 1;
	_conversation.isSizeUp = false;
	_conversation.count = 0;
	_conversation.index = 0;
	//검은색 투명한 배경 마스크 이미지
	_layer = IMAGEMANAGER->findImage("blackBox");
	
	//나가기 버튼 초기화
	_exit.img = IMAGEMANAGER->findImage("exit");
	_exit.animation = new animation;
	_exit.animation->init(_exit.img->getWidth(), _exit.img->getHeight(), _exit.img->getFrameWidth(), _exit.img->getFrameHeight());
	_exit.animation->setPlayFrame(0,7,false,true);
	_exit.animation->setFPS(10);
	_exit.animation->start();

	_exit.y = 545;
	_exit.rc = RectMake(690, 658, 40, 40);

	_letter.img = IMAGEMANAGER->findImage("letter");
	_letter.exit = IMAGEMANAGER->findImage("exit2");
	_letter.txt = "";
	_letter.rc = RectMake(1062, 50, _letter.exit->getWidth(), _letter.exit->getHeight());
	_letter.scale = 0.7f;

	//타임 UI
	_timeUI.window = IMAGEMANAGER->findImage("timeWindow");
	_timeUI.windowRc = RectMake(WINSIZEX - 25 - _timeUI.window->getWidth(), 25, _timeUI.window->getWidth(),
		_timeUI.window->getHeight());
	_timeUI.pointer = IMAGEMANAGER->findImage("timePointer");
	_timeUI.frameX = 0;
	//콜백함수들 초기화 함수 
	this->setAddCallback();

	return S_OK;
}

void UI::release()
{
	gameObject::release();


}

void UI::update()
{
	gameObject::update();


	//대화창 업데이트
	if (_direction == CONVERSATION)
	{
		this->conversationUpdate();
	}
	if (_direction == LETTER)
	{
		this->letterUpdate();
	}


	//시험용 대화창 만드는 메세지 
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		string str = "외롭다 회의실에 나밖에 없다 슬프다 심심하다 코딩빌런이 되버린다 하앍하앍";
			
		this->sendMessage(tagMessage("conversation", 0.0f, PIERRE, 0, vector<gameObject*>(), str));

		this->setCallback([this]()
		{
			sendMessage(tagMessage("conversation", 1.0f, CAROLINE, 0, vector<gameObject*>(), PERRETESTCONVERSATION));
		});
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		string str = "동해물과 백두산이 마르고 닳토록~ 하느님이 보우하사 우리 나라 만세 무궁화 삼천리 화려가아아아아앙사아아아아아안";

		this->sendMessage(tagMessage("conversation", 0.0f, CAROLINE, 0, vector<gameObject*>(), str));
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		string str = "ㄴㅇㅁ혀ㅠㅗ먇겨ㅐ휴ㅗㅁㄴ대ㅗㅁㄴㄱ돔ㄷ녿ㅁ노도도돋고ㅛ도독ㄷㄴㅁㅇㅎㅇㅁㄶㅁㅇㄶㅁㅇㄶㅇㅁㅎㄴ";

		this->sendMessage(tagMessage("letter", 0.0f, 0, 0, vector<gameObject*>(), str));
	}
	if (KEYMANAGER->isOnceKeyDown('F'))
	{
		_timeUI.frameX++;
	}
	
}

void UI::render()
{
	if (_direction != LETTER)
	{
		_timeUI.window->render(getMemDC(), _timeUI.windowRc.left, _timeUI.windowRc.top);
		_timeUI.pointer->frameRender(getMemDC(), _timeUI.windowRc.left+5, _timeUI.windowRc.top, _timeUI.frameX, 0);
	}

	if (_direction == CONVERSATION)
	{
		this->conversationRender();
	
	}
	if (_direction == LETTER)
	{
		this->letterRender();
	}
	

}


//대화창 업데이트 
void UI::conversationUpdate()
{
	//나가기 버튼 점프
	if (_exit.isJump)
	{
		_exit.y -= 0.5;
	}
	else _exit.y += 0.5;
	if (_exit.y <= 540)_exit.isJump = false;
	if (_exit.y >= 545)_exit.isJump = true;
	//나가기 버튼 프레임 계속ㄱ 돌게 해주자 
	_exit.animation->frameUpdate(0.01);


	//호감도 ball 사이즈 조정
	if (_conversation.isSizeUp)
	{
		_conversation.size += 0.008;
	}
	if (!_conversation.isSizeUp)
	{
		_conversation.size -= 0.008;
	}
	if (_conversation.size >= 1.2)_conversation.isSizeUp = false;
	if (_conversation.size <= 1.0)_conversation.isSizeUp = true;
	

}

void UI::conversationRender()
{
	//대화창 윈도우 렉트
	RECT windowRc = RectMake(WINSIZEX / 2 - _conversation.window->getWidth() / 2, WINSIZEY / 2 
		, _conversation.window->getWidth(), _conversation.window->getHeight());
	//대화창 윈도우 이미지
	_conversation.window->render(getMemDC(), windowRc.left, windowRc.top);
	////대화창 대상 이름표 이미지
	_conversation.scroll->scaleRender(getMemDC(), windowRc.right - 360, windowRc.bottom - 90 ,300,50);
	////대화창 대상 프로필 이미지
	_conversation.who->scaleRender(getMemDC(), windowRc.right - 320, windowRc.top + 37,
		_conversation.who->getWidth() * 3, _conversation.who->getHeight() * 3);
	////대화창 옆 호삼도 표시 볼 이미지 
	_conversation.ball->scaleRender(getMemDC(),windowRc.right-82, windowRc.bottom-127, _conversation.ball->getWidth() * _conversation.size,
		_conversation.ball->getHeight() * _conversation.size);
	////나가기 버튼 
	_exit.img->aniRender(getMemDC(), windowRc.right - 465, windowRc.bottom - 94, _exit.animation);

	//==================== 대사 처리 ===================
	char str[1000];													//출력할 문자
	sprintf(str, "%s", _txt.c_str());								//str에 넣어주고 
	_conversation.count += TIMEMANAGER->getElapsedTime();			//시간마다 카운트 증가 시켜주고 
	if (_conversation.count >= 0.07f)								//0.07초 마다 조건이 충족되면
	{
		_conversation.count = 0;									//다시 0으로 초기화해주고 
		_conversation.index += 2;									//출력할 문자 사이즈 2씩 더하기

		if (_conversation.index >= strlen(_txt.c_str()))			//만약 인덱스사이즈가 전체 사이즈보다 커질려 한다면
		{
			_conversation.index = strlen(_txt.c_str());				//커지지 않게 막아줘라 
		}
	}

	RECT drawRc = RectMake(windowRc.left + 40, windowRc.top + 40, 550, 550);		//그려줄 범위 및 렉트 잡아줄 렉트 생성 
	//폰트 성정
	HFONT font = CreateFont(25, 0, 0, 0, 800, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY엽서L"));
	HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);
	//텍스트 색을 설정해준다.
	SetTextColor(getMemDC(), RGB(86, 22, 12));	
	//텍스트 그려주고
	DrawText(getMemDC(), str, _conversation.index, &drawRc, DT_LEFT | DT_VCENTER | DT_WORDBREAK | DT_EXTERNALLEADING);

	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);


}

//편지 업데이트 
void UI::letterUpdate()
{
	//편지 나가기 버튼아이콘 크기 커졌다 작아졌다하는거 
	if (_letter.isScaleUp)
	{
		_letter.scale += 0.008;
	}
	if (!_letter.isScaleUp)
	{
		_letter.scale -= 0.008;
	}
	if (_letter.scale >= 1.0)_letter.isScaleUp = false;
	if (_letter.scale <= 0.7)_letter.isScaleUp = true;

	_letter.rc = RectMake(1115, 50, _letter.exit->getWidth() * _letter.scale, _letter.exit->getHeight() * _letter.scale);
}

void UI::letterRender()
{
	_layer->alphaRender(getMemDC(), 0, 0, 100);

	_letter.img->render(getMemDC(), WINSIZEX / 2 - _letter.img->getWidth() / 2,
		WINSIZEY / 2 - _letter.img->getHeight() / 2);

	_letter.exit->scaleRender(getMemDC(), _letter.rc.left, _letter.rc.top, _letter.exit->getWidth() *_letter.scale
		, _letter.exit->getHeight() * _letter.scale);


	//편지 내용 string 처리
	char str[1000];
	sprintf(str, "%s", _letter.txt.c_str());

	RECT drawRc = RectMake(WINSIZEX / 2 - _letter.img->getWidth()/2 + 50, WINSIZEY / 2 - _letter.img->getHeight() / 2 + 80,
		_letter.img->getWidth() -100, _letter.img->getHeight() - 100);

	HFONT font = CreateFont(25, 0, 0, 0, 800, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY엽서L"));
	HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);

	SetTextColor(getMemDC(), RGB(86, 22, 12));						//텍스트 색을 설정해준다.
	DrawText(getMemDC(), str, strlen(str), &drawRc, DT_LEFT | DT_VCENTER | DT_WORDBREAK | DT_EXTERNALLEADING);

	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);
	
}