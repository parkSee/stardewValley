#pragma once
#include "worldNode.h"

//�׳� ����ü�� �Ȱ���
//�׳� Ŭ������ ������ �� 

class gameObject;

namespace itemType
{
	enum Enum
	{
		FOOD, SEED, TOOL,SETTING, STONE, WOOD, NONE
	};
}

struct tagItem
{
	string				name;		//������ �̸�
	string				explain;	//������ ����
	image*				img;		//������ �̹���
	itemType::Enum		type;		//������ Ÿ�� 
	tagFloat			pos;		//������ ������
	RECT				rc;			//������ ��Ʈ
	int					count;		//������ ���� 
	float				size;		//�̹��� ������
	//�⺻ ������
	tagItem();	
	//�ѹ��� �ʱ�ȭ �� �ټ� �ִ� ����ü �Լ� 
	tagItem(string Name,string Explain, tagFloat position = tagFloat(), int Count = 0 , itemType::Enum typ = itemType::NONE);
	//���� ���� �Ҷ� ����� �Լ� 
	void addCount() { count++; }
};
