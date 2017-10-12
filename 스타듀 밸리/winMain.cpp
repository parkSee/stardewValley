#include "stdafx.h"
#include "playGround.h"

HINSTANCE	_hInstance;		//APP 고유번호
HWND		_hWnd;			//조작질

LPTSTR _lpszClass = TEXT("Omicron API");

POINT _ptMouse;
playGround _pg;

BOOL _leftButtonDown = false;

bool _isStop = false;

//함수의 프로토 타입
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void setWindowsSize(int x, int y, int width, int height);

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int cmdShow)
{
	MSG message;				//윈도우 메시지
	WNDCLASS wndClass;			//윈도우 구조체(윈도우 창의 정보)

	_hInstance = hInstance;

	wndClass.cbClsExtra = 0;										//클래스 여분 메모리 설정
	wndClass.cbWndExtra = 0;										//윈도우 여분 메모리 설정
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//윈도우 백그라운드
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);					//윈도우 커서 모양
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//윈도우 아이콘 모양
	wndClass.hInstance = hInstance;									//윈도우 인스턴스 번호
	wndClass.lpfnWndProc = (WNDPROC)WndProc;						//윈도우 프로시져
	wndClass.lpszClassName = _lpszClass;							//윈도우 클래스 이름
	wndClass.lpszMenuName = NULL;									//윈도우 메뉴 이름
	wndClass.style = CS_HREDRAW | CS_VREDRAW;						//윈도우 창 스타일

	//윈도우 정보를 등록해준다
	RegisterClass(&wndClass);

	_hWnd = CreateWindow(
		WINNAME,
		WINNAME,
		WS_OVERLAPPEDWINDOW,		//윈도우 창 스타일
		WINSTARTX,					//윈도우 시작 X좌표
		WINSTARTY,					//윈도우 시작 Y좌표
		WINSIZEX,					//윈도우 창 가로크기
		WINSIZEY,					//윈도우 창 세로크기
		NULL,
		(HMENU)NULL,
		hInstance,
		NULL);

	setWindowsSize(WINSTARTX, WINSTARTY, WINSIZEX, WINSIZEY);

	ShowWindow(_hWnd, cmdShow);		//윈도우 창 화면에 보여줘라

	//윈도우 메시지 루프
	//GetMessage : 메시지가 들어오면 그제서야 처리한다
	//PeekMessage : 게임용으로 주로쓰는데 상시 와일문이 돌아가고있다.

	//플레이그라운드 초기화가 실패하면
	if (FAILED(_pg.init()))
	{
		
		return 0;
	}

	
	while (true)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT) break;
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			//60푸레임으로!
			TIMEMANAGER->update(60.0f);
			_pg.update();
			_pg.render();
		}
	}
	

	//메시지 루프 끝나면 해제
	_pg.release();

	return message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return _pg.MainProc(hWnd, iMessage, wParam, lParam);
}

//클라이언트 영역 재조정
void setWindowsSize(int x, int y, int width, int height)
{
	RECT winRect;

	winRect.left = 0;
	winRect.top = 0;
	winRect.right = width;
	winRect.bottom = height;

	AdjustWindowRect(&winRect, WINSTYLE, false);

	SetWindowPos(_hWnd, NULL, x, y, (winRect.right - winRect.left),
		(winRect.bottom - winRect.top), SWP_NOZORDER | SWP_NOMOVE);
}