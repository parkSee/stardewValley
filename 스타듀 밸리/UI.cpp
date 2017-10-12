#include "stdafx.h"
#include "UI.h"
#include "worldNode.h"

using namespace uiDirection;

HRESULT UI::init(string objName)
{
	gameObject::init(objName,"mouse");
	//UI �ʱ�ȭ
	_direction = NORMAL;					
	//��ȭâ ����ü �ʱ�ȭ 
	ZeroMemory(&_conversation, sizeof(tagConverSation));
	_conversation.window = IMAGEMANAGER->findImage("tokeWindow");
	_conversation.who = IMAGEMANAGER->findImage("storeNPC");
	_conversation.scroll = IMAGEMANAGER->findImage("pierre");
	_conversation.ball = IMAGEMANAGER->findImage("txtWindowBall");
	//��ȭâ ���� ������ �ʱ�ȭ 
	_conversation.size = 1;
	_conversation.isSizeUp = false;
	_conversation.count = 0;
	_conversation.index = 0;
	//������ ������ ��� ����ũ �̹���
	_layer = IMAGEMANAGER->findImage("blackBox");
	
	//������ ��ư �ʱ�ȭ
	_exit.img = IMAGEMANAGER->findImage("exit");
	_exit.animation = new animation;
	_exit.animation->init(_exit.img->getWidth(), _exit.img->getHeight(), _exit.img->getFrameWidth(), _exit.img->getFrameHeight());
	_exit.animation->setPlayFrame(0,7,false,true);
	_exit.animation->setFPS(10);
	_exit.animation->start();

	_exit.y = 545;
	_exit.rc = RectMakeCenter(645, _exit.y, 30, 30);

	_letter.img = IMAGEMANAGER->findImage("letter");
	_letter.exit = IMAGEMANAGER->findImage("exit2");
	_letter.txt = "";
	_letter.rc = RectMake(1062, 50, _letter.exit->getWidth(), _letter.exit->getHeight());
	_letter.scale = 0.7f;
	
	//�ݹ��Լ��� �ʱ�ȭ �Լ� 
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


	//��ȭâ ������Ʈ
	if (_direction == CONVERSATION)
	{
		this->conversationUpdate();
	}
	if (_direction == LETTER)
	{
		this->letterUpdate();
	}


	//����� ��ȭâ ����� �޼��� 
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		string str = "�ܷӴ� ȸ�ǽǿ� ���ۿ� ���� ������ �ɽ��ϴ� �ڵ������� �ǹ����� �Ͼ��Ͼ�";
			
		this->sendMessage(tagMessage("conversation", 0.0f, PIERRE, 0, vector<gameObject*>(), str));

		this->setCallback([this]()
		{
			sendMessage(tagMessage("conversation", 1.0f, CAROLINE, 0, vector<gameObject*>(), PERRETESTCONVERSATION));
		});
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		string str = "���ع��� ��λ��� ������ �����~ �ϴ����� �����ϻ� �츮 ���� ���� ����ȭ ��õ�� ȭ�����ƾƾƾƾӻ�ƾƾƾƾƾ�";

		this->sendMessage(tagMessage("conversation", 0.0f, CAROLINE, 0, vector<gameObject*>(), str));
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		string str = "���������Фǐưܤ��ޤǤ�����Ǥ����������뤱�뵵������˵���������������������������������������";

		this->sendMessage(tagMessage("letter", 0.0f, 0, 0, vector<gameObject*>(), str));
	}

	
}

void UI::render()
{
	if (_direction == NORMAL)
	{
		
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

//��ȭâ ������Ʈ 
void UI::conversationUpdate()
{
	//������ ��ư ����
	if (_exit.isJump)
	{
		_exit.y -= 0.5;
	}
	else _exit.y += 0.5;
	if (_exit.y <= 540)_exit.isJump = false;
	if (_exit.y >= 545)_exit.isJump = true;
	_exit.rc = RectMakeCenter(650, _exit.y, 40, 40);
	//������ ��ư ������ ��Ӥ� ���� ������ 
	_exit.animation->frameUpdate(0.01);


	//ȣ���� ball ������ ����
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
	//��ȭâ ������ ��Ʈ
	RECT windowRc = RectMake(WINSIZEX / 2 - _conversation.window->getWidth() / 2, WINSIZEY / 2 - _conversation.window->getHeight() / 2
		, _conversation.window->getWidth(), _conversation.window->getHeight());
	//��ȭâ ������ �̹���
	_conversation.window->render(getMemDC(), windowRc.left, windowRc.top);
	//��ȭâ ��� �̸�ǥ �̹���
	_conversation.scroll->render(getMemDC(), windowRc.right - 370, windowRc.bottom - 112);
	//��ȭâ ��� ������ �̹���
	_conversation.who->scaleRender(getMemDC(), windowRc.right - 320, windowRc.top + 70,
		_conversation.who->getWidth() * 3, _conversation.who->getHeight() * 3);
	//��ȭâ �� ȣ�ﵵ ǥ�� �� �̹��� 
	_conversation.ball->scaleRender(getMemDC(),windowRc.right-82, windowRc.bottom-157, _conversation.ball->getWidth() * _conversation.size,
		_conversation.ball->getHeight() * _conversation.size);
	//������ ��ư 
	_exit.img->aniRender(getMemDC(), windowRc.right - 465, windowRc.bottom - 94, _exit.animation);

	//==================== ��� ó�� ===================
	char str[1000];													//����� ����
	sprintf(str, "%s", _txt.c_str());								//str�� �־��ְ� 
	_conversation.count += TIMEMANAGER->getElapsedTime();			//�ð����� ī��Ʈ ���� �����ְ� 
	if (_conversation.count >= 0.07f)								//0.07�� ���� ������ �����Ǹ�
	{
		_conversation.count = 0;									//�ٽ� 0���� �ʱ�ȭ���ְ� 
		_conversation.index += 2;									//����� ���� ������ 2�� ���ϱ�

		if (_conversation.index >= strlen(_txt.c_str()))			//���� �ε�������� ��ü ������� Ŀ���� �Ѵٸ�
		{
			_conversation.index = strlen(_txt.c_str());				//Ŀ���� �ʰ� ������� 
		}
	}

	RECT drawRc = RectMake(windowRc.left + 40, windowRc.top + 40, 550, 550);		//�׷��� ���� �� ��Ʈ ����� ��Ʈ ���� 
	//��Ʈ ����
	HFONT font = CreateFont(25, 0, 0, 0, 800, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY����L"));
	HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);
	//�ؽ�Ʈ ���� �������ش�.
	SetTextColor(getMemDC(), RGB(86, 22, 12));	
	//�ؽ�Ʈ �׷��ְ�
	DrawText(getMemDC(), str, _conversation.index, &drawRc, DT_LEFT | DT_VCENTER | DT_WORDBREAK | DT_EXTERNALLEADING);

	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);


}

//���� ������Ʈ 
void UI::letterUpdate()
{
	//���� ������ ��ư������ ũ�� Ŀ���� �۾������ϴ°� 
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

	_letter.rc = RectMake(1062, 50, _letter.exit->getWidth() * _letter.scale, _letter.exit->getHeight() * _letter.scale);
}

void UI::letterRender()
{
	_layer->alphaRender(getMemDC(), 0, 0, 100);

	_letter.img->render(getMemDC(), WINSIZEX / 2 - _letter.img->getWidth() / 2,
		WINSIZEY / 2 - _letter.img->getHeight() / 2);

	_letter.exit->scaleRender(getMemDC(), _letter.rc.left, _letter.rc.top, _letter.exit->getWidth() *_letter.scale
		, _letter.exit->getHeight() * _letter.scale);


	//���� ���� string ó��
	char str[1000];
	sprintf(str, "%s", _letter.txt.c_str());

	RECT drawRc = RectMake(WINSIZEX / 2 - _letter.img->getWidth()/2 + 50, WINSIZEY / 2 - _letter.img->getHeight() / 2 + 80,
		_letter.img->getWidth() -100, _letter.img->getHeight() - 100);

	HFONT font = CreateFont(25, 0, 0, 0, 800, false, false, false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY����L"));
	HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);

	SetTextColor(getMemDC(), RGB(86, 22, 12));						//�ؽ�Ʈ ���� �������ش�.
	DrawText(getMemDC(), str, strlen(str), &drawRc, DT_LEFT | DT_VCENTER | DT_WORDBREAK | DT_EXTERNALLEADING);

	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);
	
}