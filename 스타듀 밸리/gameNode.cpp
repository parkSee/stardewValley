#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{

}

HRESULT gameNode::init(void)
{
	_hdc = GetDC(_hWnd);
	_managerInit = false;
		
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;

	if (_managerInit)
	{
		
		KEYMANAGER->init();
		IMAGEMANAGER->init();
		SOUNDMANAGER->init();
		TIMEMANAGER->init();
		EFFECTMANAGER->init();
		SCENEMANAGER->init();
		KEYANIMANAGER->init();
		TXTDATA->init();
		INIDATA->init();
		TOWNWORLD->init();
		CAMERAMANAGER->init();
		WORLDTIME->init();

	}

	return S_OK;
}

//�޸� ����
void gameNode::release(void)
{
	if (_managerInit)
	{
		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->releaseSingleton();
		SOUNDMANAGER->releaseSingleton();
		TIMEMANAGER->releaseSingleton();
		EFFECTMANAGER->releaseSingleton();
		SCENEMANAGER->releaseSingleton();
		KEYANIMANAGER->releaseSingleton();
		TXTDATA->releaseSingleton();
		INIDATA->releaseSingleton();
		TOWNWORLD->releaseSingleton();
		CAMERAMANAGER->releaseSingleton();
		WORLDTIME->releaseSingleton();
	}
	
	ReleaseDC(_hWnd, _hdc);

}

//������Ʈ(����)
void gameNode::update(void)
{
	KEYMANAGER->update();
}

//�׸���
void gameNode::render(void)
{

}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//HWND : ��� �����쿡�� ��� �޽����� �߻��ߴ��� üũ
	//iMessage : �޼��� ��ȣ
	//wParam : Ű���� & ���콺 Ŭ�� ���� �Է� �޽���
	//lParam : ���콺 ��ǥ �޽��� ����

	PAINTSTRUCT ps;
	HDC			hdc;

	switch (iMessage)
	{		
		case WM_MOUSEMOVE:
			_ptMouse.x = static_cast<float>LOWORD(lParam);
			_ptMouse.y = static_cast<float>HIWORD(lParam);

		break;
		case WM_LBUTTONDOWN:
			_leftButtonDown = true;
	
		break;
		case WM_LBUTTONUP:
			_leftButtonDown = false;
		break;
		case WM_KEYDOWN:
			switch (wParam)
			{
				case VK_ESCAPE:
					PostMessage(hWnd, WM_DESTROY, 0, 0);
				break;
			}
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}
