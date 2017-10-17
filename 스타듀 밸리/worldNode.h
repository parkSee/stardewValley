#pragma once
#include <functional>

//��� ���� �� �ʱ� �� �������� ���⼭ ���ش�
//�̷��� ���ָ� �� �� �뷱�� ���� �� ���� ���� ���� 

//ex) #define PLAYERSPEED 5
//player->init()���� _player.speed = PLAYERSPEED

//�츮 ��� ���̵��� ��ǥ
//POINTFLOAT�̶��� ������ �װ� �⺻�����ڸ� ���� �� ����ü°�� ���� �ʱ�ȭ ���ִ� �װ� �ι�° �Լ��� ���⶧���� �������
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

//================== Ÿ�� =====================
#define SCALE 4
#define TILESIZE (16 * SCALE)
#define TILEX 43
#define TILEY 27


//=================== UI ======================

//�ݹ�~
typedef std::function<void()> CBFUNCTION;

//��ȭâ �ι� ������ 
#define CAROLINE			0
#define PIERRE				1

#define PERRETESTCONVERSATION "string�� �̷��� �������� �ɾ ��ȭ���� ����� ���� �� �ִܴ�."

//�޼��� ��� txt������

//publicUI Ŭ���� �ݹ� �Լ� ����
#define ADDGUIDEUI		"addGuideUI"		//���̵� UIâ �ݹ� �޼��� �̸� , msg.conversatoin �� ��� ��Ʈ���� �Է����ָ� �ȴ�.
#define ADDGETITEMUI	"addGetItemUI"		//������ ����� �� ������ UI�޼��� �̸�, msg.conversation�� ������ �̸�(Ű��)�� �Է�

//inventoryŬ���� �ݹ� �Լ� ���� 
#define SETTARGETTIEM	"setTargetItem"		//Ÿ�� ������ �ٲ� �޼��� �̸�,msg.conversation�� ������ �̸�(Ű��)�� �Է� 
#define ADDITEM			"addItem"			//������ �κ��丮�� �߰� �ݹ� �޼���,
											//msg.converstation�� ������ �̸� ,msg.str�� ������ �ΰ� ������ �־��ش�.

//��ȭâ �� ����â UI�ݹ� �Լ� ����
#define CONVERSATIONUI	"conversation"		//��ȭâ ���� �޼��� �̸�, msg.conversation�� ���� ��ȭstring�� �Է�
											//msg.data�� �ι� ��ȣ�ڵ� �������� �־��ش� ex)PIERRE || CAROLINE

