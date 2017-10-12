#pragma once
#include "gameNode.h"
#include "worldNode.h"
#include <functional>
#include <unordered_map>

namespace pivot
{
	enum Enum
	{
		LEFT_TOP, CENTER, BOTTOM
	};
}

struct tagSize
{
	float width;
	float height;
};

class gameObject : public gameNode
{
private:
	bool _isLive;								//������Ʈ�� ����ִ��� �Ұ�
	bool _isActive;								//������Ʈ Ȱ��ȭ �Ұ�
	float _destroyDelayTime;						//���� ������ Ÿ�� 

	vector<tagMessage> _reservedMessage;									//��� �޼���
	vector<tagMessage> _messageList;										//�޼�������Ʈ
	unordered_map<string, std::function<void(tagMessage)>> _callbackList;	//�޼��� �ݹ� ����Ʈ 

protected:
	pivot::Enum			_pivot;						//�Ǻ�
	image*				_image;						//���� ������Ʈ �̹���
	animation*			_animation;					//���� ������Ʈ�� �ִϸ��̼� ����

	tagSize _size;								//���� ���� ����
	
public:
	tagFloat _pos;								//��ǥ
	string _name;								//������Ʈ �̸�

	gameObject() {}
	virtual ~gameObject() {}

	virtual HRESULT init(string objName , string imageKey  = "", tagFloat pos = tagFloat() , pivot::Enum pivot = pivot::CENTER);
	virtual void release();
	virtual void update();
	virtual void render();

	RECT getRect();										//�Ǻ��� ���� ���� ��Ʈ�� ��ȯ�� �ش�

	bool isActiveObject();								//Ȱ��ȭ ���������� ���� �Ұ��� ��ȯ ���ش�.
	void setDestroy(float time = 0.0f);					//������Ʈ �������

	void sendMessage(tagMessage msg = tagMessage());	//�޼��� ����
	
	bool isLive() { return _isLive; }

	//�ݹ� �Լ� ����
	void addCallback(string msgName, std::function<void(tagMessage)> callbackFunc)
	{
		_callbackList.insert(make_pair(msgName, callbackFunc));
	}

};

