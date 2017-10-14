#include "stdafx.h"
#include "UI.h"
#include "worldNode.h"
#include <functional>

void UI::setAddCallback()
{
	//��ȭâ �ݹ� �Լ� ���
	this->addCallback("conversation", [this](tagMessage msg)
	{
		this->setConverSationWindow(msg.data, msg.conversation);
	});
	//���� �ݹ� �Լ� ���
	this->addCallback("letter", [this](tagMessage msg)
	{
		this->setLetter(msg.conversation);
	});
	//��ȭâ �� ����â ������ �ݹ� �Լ� ��� 
	this->addCallback("exit", [this](tagMessage msg)
	{
		this->exit();
	});

}


void UI::timePointer()
{
	
	
}

//�ٿ뵵 �ݹ� �Լ� ��� 
void UI::setCallback(CBFUNCTION cb )
{
	_cbFunction = cb;
}

//��ȭâ ������ִ� �Լ� 
void UI::setConverSationWindow(int who, string txt)
{
	//Ui���¸� ��ȭâ���·� ������ְ� 
	_direction = uiDirection::CONVERSATION;
	//�̹����� �־��ְ� 
	_conversation.who = getWho(who)[0];
	_conversation.scroll = getWho(who)[1];
	//�ؽ�Ʈ���� �ؽ�Ʈ �־��ְ� 
	_txt = txt;
	//�ð� �������ְ�
	WORLDTIME->_isTimeFlow = false;
}

//����â ����� �ִ� �Լ�
void UI::setLetter(string txt)
{
	_direction = uiDirection::LETTER;

	_letter.txt = txt;
	//�ð� ������ �ְ�
	WORLDTIME->_isTimeFlow = false;
}

//��ȭâ�� ���� �ι��� ������ �̹����� �̸�ǥ �̹����� ���Ϳ� ��Ƽ� ��ȯ�� �ش�. 
vector<image*> UI::getWho(int who)
{
	image* someOne;
	image* someOneScroll;
	vector<image*> vImage;

	switch (who)
	{
	case CAROLINE :	//�÷��̾�
	{
		someOne = IMAGEMANAGER->findImage("carolineProfile");
		vImage.push_back(someOne);
		someOneScroll = IMAGEMANAGER->findImage("carolineScroll");
		vImage.push_back(someOneScroll);
	}
	break;
	case PIERRE:	//��������(�Ƿ�)
	{
		someOne = IMAGEMANAGER->findImage("pierreProfile");
		vImage.push_back(someOne);
		someOneScroll = IMAGEMANAGER->findImage("pierreScroll");
		vImage.push_back(someOneScroll);
	}
	break;

	default:		//���� ����̶�� NULL�� ��Ƽ� ��ȯ�ض� 
	{
		vImage.push_back(NULL);
		vImage.push_back(NULL);
	}
	break;
	}

	return vImage;
}

//��ȭâ �� ���� â ������ ó������� �Ұ͵��� ó�����ش�.
void UI::exit()
{
	//��ȭâ ������ ��ư
	if (_direction == uiDirection::CONVERSATION)
	{
		_txt.clear();
		_conversation.count = 0;
		_conversation.index = 0;
		_direction = uiDirection::NORMAL;
	}
	//���� ������ ��ư 
	else if (_direction == uiDirection::LETTER)
	{
		_letter.txt.clear();
		_direction = uiDirection::NORMAL;
	}
	
	//������ ��ư�� �����µ� ���� ��ϵ� �ٿ뵵 �ݹ��Լ��� �ִٸ� �����϶� 
	if (_cbFunction != NULL)
	{
		_cbFunction();
		_cbFunction = NULL;			//�׸��� ���������� �ٽ� NULL�� ����ֶ� 
	}

	//��ȭâ ����â �������ϱ� �ð��ٽ� �귯���� true�� ����� �ش�.
	WORLDTIME->_isTimeFlow = true;
}


