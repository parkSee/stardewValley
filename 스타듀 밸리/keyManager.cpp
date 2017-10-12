#include "stdafx.h"
#include "keyManager.h"


keyManager::keyManager() {}
keyManager::~keyManager() {}


HRESULT keyManager::init()
{
	//ó���� ��� Ű�� �������� ���� ���·� �ʱ�ȭ
	_keyCurrent.reset();
	_keyPast.reset();

	return S_OK;
}
void keyManager::release()
{

}
void keyManager::update()    //gameNode�� update�� �߰�
{
	//��� ����Ű�� ����Ű�� �������ش�
	_keyPast = _keyCurrent;
}


bool keyManager::isOnceKeyDown(int key)
{
	//�ش� Ű�� ���� ����
	if (GetAsyncKeyState(key) & 0x8000)
	{
		//�� Ű�� �������� �ʾҴٸ�
		if (!_keyPast[key])
		{
			//����Ű�� ���� ���·� �ٲٰ� return true
			_keyCurrent.set(key, true);
			return true;
		}
	}
	//�ش� Ű�� ������ ���� ����
	else _keyCurrent.set(key, false);   //����Ű�� ������ ���� ���·� �ٲ�

	return false;
}

bool keyManager::isOnceKeyUp(int key)  
{
	//�ش� Ű�� ���� ����					����Ű�� ���� ���·� �ٲ�
	if (GetAsyncKeyState(key) & 0x8000) _keyCurrent.set(key, true);
	//�ش� Ű�� ������ ���� ����
	else
	{
		//�� Ű�� �����־��ٸ�
		if (_keyPast[key])
		{
			//����Ű�� ������ ���� ���·� �ٲٰ� return true
			_keyCurrent.set(key, false);
			return true;
		}
	}
	
	return false;
}

bool keyManager::isStayKeyDown(int key)
{
	if (GetAsyncKeyState(key) & 0x8000) return true;

	return false;
}

bool keyManager::isToggleKey(int key)
{
	if (GetKeyState(key) & 0x0001) return true;

	return false;
}
