#pragma once
#include "gameNode.h"

//====================
//����&���� + ����&�ÿ�(feat. �Ѽ�)
//====================
//<funtional> <------
//std::funtion
//std::move
//std::bind 
//Ȱ���ؼ� �Ϲ� ��������� ����Լ� ���� �����ϰ� �ϴ°Ž� ��������
//����) �ǿܷ� ����

//�ݹ��Լ��� �Լ��������� ���¸� ���
typedef void(*CALLBACK_FUNCTION)(void);

class action : public gameNode
{
private:
	image* _image;				//�̹���
	float _startX, _startY;		//������ǥ(�����ǥ)
	float _endX, _endY;			//����ǥ(������ǥ)

	float _angle;				//����
	float _travelRange;			//������ �Ÿ�
	float _worldTimeCount;		//���� ī��Ʈ
	float _time;				//������� �ð�(��?)

	bool _isMoving;

	CALLBACK_FUNCTION _callbackFunction;

public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void moveTo(image* image, float endX, float endY, float time);
	void moveTo(image* image, float endX, float endY, float time, CALLBACK_FUNCTION cbFunction);

	void moving(void);

	bool getIsMoving(void) { return _isMoving; }




	action();
	~action();
};

