#include "stdafx.h"
#include "UI.h"
#include "worldNode.h"
#include <functional>

void UI::setAddCallback()
{
	//대화창 콜백 함수 등록
	this->addCallback("conversation", [this](tagMessage msg)
	{
		this->setConverSationWindow(msg.data, msg.conversation);
	});
	//편지 콜백 함수 등록
	this->addCallback("letter", [this](tagMessage msg)
	{
		this->setLetter(msg.conversation);
	});
	//대화창 및 편지창 나가기 콜백 함수 등록 
	this->addCallback("exit", [this](tagMessage msg)
	{
		this->exit();
	});

}


void UI::timePointer()
{
	
	
}

//다용도 콜백 함수 등록 
void UI::setCallback(CBFUNCTION cb )
{
	_cbFunction = cb;
}

//대화창 만들어주는 함수 
void UI::setConverSationWindow(int who, string txt)
{
	//Ui상태를 대화창상태롤 만들어주고 
	_direction = uiDirection::CONVERSATION;
	//이미지들 넣어주고 
	_conversation.who = getWho(who)[0];
	_conversation.scroll = getWho(who)[1];
	//텍스트에도 텍스트 넣어주고 
	_txt = txt;
	//시간 정지해주고
	WORLDTIME->_isTimeFlow = false;
}

//편지창 만들어 주는 함수
void UI::setLetter(string txt)
{
	_direction = uiDirection::LETTER;

	_letter.txt = txt;
	//시간 정지해 주고
	WORLDTIME->_isTimeFlow = false;
}

//대화창에 나올 인물의 프로필 이미지와 이름표 이미지를 벡터에 담아서 반환해 준다. 
vector<image*> UI::getWho(int who)
{
	image* someOne;
	image* someOneScroll;
	vector<image*> vImage;

	switch (who)
	{
	case CAROLINE :	//플레이어
	{
		someOne = IMAGEMANAGER->findImage("carolineProfile");
		vImage.push_back(someOne);
		someOneScroll = IMAGEMANAGER->findImage("carolineScroll");
		vImage.push_back(someOneScroll);
	}
	break;
	case PIERRE:	//상점주인(피렐)
	{
		someOne = IMAGEMANAGER->findImage("pierreProfile");
		vImage.push_back(someOne);
		someOneScroll = IMAGEMANAGER->findImage("pierreScroll");
		vImage.push_back(someOneScroll);
	}
	break;

	default:		//없는 사람이라면 NULL을 담아서 반환해라 
	{
		vImage.push_back(NULL);
		vImage.push_back(NULL);
	}
	break;
	}

	return vImage;
}

//대화창 및 편지 창 나갈때 처리해줘야 할것들을 처리해준다.
void UI::exit()
{
	//대화창 나가기 버튼
	if (_direction == uiDirection::CONVERSATION)
	{
		_txt.clear();
		_conversation.count = 0;
		_conversation.index = 0;
		_direction = uiDirection::NORMAL;
	}
	//편지 나가기 버튼 
	else if (_direction == uiDirection::LETTER)
	{
		_letter.txt.clear();
		_direction = uiDirection::NORMAL;
	}
	
	//나가기 버튼을 눌렀는데 만약 등록된 다용도 콜백함수가 있다면 실행하라 
	if (_cbFunction != NULL)
	{
		_cbFunction();
		_cbFunction = NULL;			//그리고 실행했으면 다시 NULL로 비워둬라 
	}

	//대화창 편지창 나갔으니까 시간다시 흘러가게 true로 만들어 준다.
	WORLDTIME->_isTimeFlow = true;
}


