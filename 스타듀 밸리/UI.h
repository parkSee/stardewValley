#pragma once
#include "gameObject.h"
#include <vector>
#include <functional>

namespace uiDirection
{
	enum Enum
	{
		NORMAL , CONVERSATION,LETTER ,END
	};
}


struct tagConverSation
{
	image*	window;					//��ȭâ ������ �̹���
	image*	who;					//��ȭâ �ι� �̹���
	image*	scroll;					//��ȭâ �ι� �̸�ǥ �̹���
	image*	ball;					//��ȭâ �� �̹���
	
	//��ȭâ ������ �Լ��� 
	bool	isSizeUp;				
	float	size;
	//��ȭâ ������ ������ 
	float	count;					//��ȭâ�� Ȱ��ȭ�� �Ǹ� ī��Ʈ�� ����鼭 �����ð����� str�� ����� �÷��ش�
	int		index;					//str�� ��� ������ �ε��� 

};

struct tagExit
{
	image*		img;
	animation*	animation;
	RECT		rc;
	float		y;
	bool		isJump;
};

struct tagLetter
{
	image*				img;
	image*				exit;
	string				txt;
	RECT				rc;
	float				scale;
	bool				isScaleUp;
};

struct tagTimeWindow
{
	image*				window;
	image*				pointer;
	int					frameX;
	RECT				windowRc;
};

class UI : public gameObject
{
private:
	image*				_layer;					//�κ��丮 â�̳� ��ȭâ�� ������ �� ��� ���İ��ִ� ����ŷ
	CBFUNCTION			_cbFunction;			//UI �ݹ�
	tagTimeWindow		_timeUI;

public:
	uiDirection::Enum	_direction;				//UI���� â
	string 				_txt;					//��ȭ ���
	tagLetter			_letter;				//���� ����ü 
	tagExit				_exit;					//������ ��ư
	tagConverSation		_conversation;			//��ȭâ ����ü
	
public :

	virtual HRESULT init(string objName);
	virtual void release();
	virtual void update();
	virtual void render();

	void setAddCallback();						//ó�� �ݹ� �Լ��ʱ�ȭ init()�Ҷ� �ѹ��� �ߵ��Ѵ�. 
	vector<image*>	getWho(int who);			//��ȭâ�� ���� �ι��� ���������� �̹��� ���Ϳ� ��� ��ȯ���ش�. 

	//��ȭâ update �� render�Լ� 
	void conversationUpdate();		
	void conversationRender();
	//���� update  �� render�Լ�  
	void letterUpdate();
	void letterRender();
	//�ð�UI
	void timePointer();
	void timeUIRender();
	//��ȭâ �ݹ��Լ�
	void setConverSationWindow(int who, string txt);
	//���� �ݹ��Լ�
	void setLetter(string txt);
	//â ������ �ݹ��Լ�
	void exit();

	//�ٿ뵵 �ݹ� ��� 
	void setCallback(CBFUNCTION cb);

	//�ٿ뵵 �ݹ� ��� ����
	//this->setCallback([this]()
	//{
	//	sendMessage(tagMessage("conversation", 1.0f, 1, 0, vector<gameObject*>(), "�ȳ�"));
	//});

	UI()
	:_cbFunction(NULL){}
	virtual ~UI() {}
};

