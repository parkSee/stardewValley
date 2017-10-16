#include "stdafx.h"
#include "image.h"

//# 컴파일러 지시기
#pragma comment(lib, "msimg32.lib")

//멤버 이니셜라이즈 == const 속성의 초기화를 위해 탄생이 되었는데
//생성자는 그 객체가 할당이되면 자동으로 실행이 되기 때문에
//계속 할당해서 사용할 객체의 변수가 많다면 이런식으로
//초기화를 해서 사용할수 있다
image::image()
	: _imageInfo(NULL),
	_fileName(NULL),
	_trans(false),
	_transColor(RGB(0, 0, 0))
{
}


image::~image()
{
}

//빈 비트맵 이미지 초기화
HRESULT image::init(int width, int height)
{
	//이미지 정보에 뭔가 있다!? 면 해제를 해라
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);//빈 DC영역을 생성
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);//크기 만큼의 빈 비트맵 영역 생성
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	_fileName = NULL;

	_trans = FALSE;
	_transColor = RGB(0, 0, 0);

	//알파블렌드 셋팅
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;


	if (_imageInfo->hBit == NULL)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}
//파일 이미지 초기화
HRESULT image::init(const char* fileName, int width, int height,
	BOOL trans, COLORREF transColor)
{
	//파일이름이 없다면 에러메시지 던져라
	if (fileName == NULL) return E_FAIL;

	//이미지 정보에 뭔가 있다!? 면 해제를 해라
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);//빈 DC영역을 생성
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	//알파블렌드 셋팅
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;


	if (_imageInfo->hBit == NULL)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char* fileName, float x, float y, int width, int height,
	BOOL trans, COLORREF transColor)
{
	//파일이름이 없다면 에러메시지 던져라
	if (fileName == NULL) return E_FAIL;

	//이미지 정보에 뭔가 있다!? 면 해제를 해라
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);//빈 DC영역을 생성
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x;
	_imageInfo->y = y;
	_imageInfo->width = width;
	_imageInfo->height = height;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	//알파블렌드 셋팅
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;


	if (_imageInfo->hBit == NULL)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char* fileName, float x, float y, int width, int height,
	int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	//파일이름이 없다면 에러메시지 던져라
	if (fileName == NULL) return E_FAIL;

	//이미지 정보에 뭔가 있다!? 면 해제를 해라
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);//빈 DC영역을 생성
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x - (width / 2);
	_imageInfo->y = y - (height / 2);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	//알파블렌드 셋팅
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;


	if (_imageInfo->hBit == NULL)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

HRESULT image::init(const char* fileName, int width, int height,
	int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	//파일이름이 없다면 에러메시지 던져라
	if (fileName == NULL) return E_FAIL;

	//이미지 정보에 뭔가 있다!? 면 해제를 해라
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);//빈 DC영역을 생성
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	//알파블렌드 셋팅
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;


	if (_imageInfo->hBit == NULL)
	{
		release();

		return E_FAIL;
	}

	ReleaseDC(_hWnd, hdc);

	return S_OK;
}

void image::release(void)
{
	//이미지 정보가 있다면
	if (_imageInfo)
	{
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		SelectObject(_blendImage->hMemDC, _blendImage->hOBit);
		DeleteObject(_blendImage->hBit);
		DeleteDC(_blendImage->hMemDC);

		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);
		SAFE_DELETE(_blendImage);

		_trans = false;
		_transColor = RGB(0, 0, 0);
	}
}

void image::setTransColor(BOOL trans, COLORREF transColor)
{
	trans = trans;
	transColor = transColor;
}

void image::render(HDC hdc)
{
	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(_imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	if (_trans)
	{
		//특정 칼라 날려주는 함수
		GdiTransparentBlt(hdc,		//복사될 장소의 DC
			_imageInfo->x,			//복사될 좌표 시작점X(left)
			_imageInfo->y,			//복사될 좌표 시작점Y(top)
			_imageInfo->width,		//복사될 이미지 가로크기
			_imageInfo->height,		//복사될 이미지 세로크기
			_imageInfo->hMemDC,		//복사 대상 DC
			0, 0,					//복사될 시작지점
			_imageInfo->width,		//복사될 가로크기
			_imageInfo->height,		//복사될 세로크기
			_transColor);			//날려줄 칼라
	}
	else
	{
		BitBlt(hdc, _imageInfo->x, _imageInfo->y,
			_imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

//이미지 렌더함수(dc영역, 뿌릴좌표X, 뿌릴좌표Y)
void image::render(HDC hdc, int destX, int destY)
{
	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(destX, destY, _imageInfo->width, _imageInfo->height);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	if (_trans)
	{
		//화면에 뿌릴때 특정 생상을 걸러내준다
		GdiTransparentBlt(hdc,	//복사될 영역의 DC == backDC
			destX,				//복사될 좌표 X	  == backDC의 영역의 좌표
			destY,				//복사될 좌표 Y
			_imageInfo->width,	//복사될 크기
			_imageInfo->height,	//복사될 크기
			_imageInfo->hMemDC,	//복사할 DC
			0, 0,				//복사해올 좌표
			_imageInfo->width,	//복사해올 크기
			_imageInfo->height,
			_transColor);		//뺄 칼라
	}
	else
	{
		//비트블릿 == 백버퍼에 있는 걸 앞쪽으로 고속복사 해주는 함수
		BitBlt(hdc, destX, destY,
			_imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(destX, destY, sourWidth, sourHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	if (_trans)
	{
		//화면에 뿌릴때 특정 생상을 걸러내준다
		GdiTransparentBlt(hdc,	//복사될 영역의 DC == backDC
			destX,				//복사될 좌표 X	  == backDC의 영역의 좌표
			destY,				//복사될 좌표 Y
			sourWidth,			//복사될 크기
			sourHeight,			//복사될 크기
			_imageInfo->hMemDC,	//복사할 DC
			sourX, sourY,		//복사해올 좌표
			sourWidth,			//복사해올 크기
			sourHeight,
			_transColor);		//뺄 칼라
	}
	else
	{
		//비트블릿 == 백버퍼에 있는 걸 앞쪽으로 고속복사 해주는 함수
		BitBlt(hdc, destX, destY,
			sourWidth,
			sourHeight,
			_imageInfo->hMemDC,
			sourX, 
			sourY, 
			SRCCOPY);
	}
}

void image::frameRender(HDC hdc, int destX, int destY)
{
	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	if (_trans)
	{
		//화면에 뿌릴때 특정 생상을 걸러내준다
		GdiTransparentBlt(hdc,	//복사될 영역의 DC == backDC
			destX,				//복사될 좌표 X	  == backDC의 영역의 좌표
			destY,				//복사될 좌표 Y
			_imageInfo->frameWidth,			//복사될 크기
			_imageInfo->frameHeight,			//복사될 크기
			_imageInfo->hMemDC,	//복사할 DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth, 
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,			
			_imageInfo->frameHeight,
			_transColor);		
	}
	else
	{
		//비트블릿 == 백버퍼에 있는 걸 앞쪽으로 고속복사 해주는 함수
		BitBlt(hdc, destX, destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}

}

void image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{

	RECT renderRC = RectMake(destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	//RECT renderRC = RectMake(destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight);
	//if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
	//	return;

	if (_trans)
	{
		//화면에 뿌릴때 특정 생상을 걸러내준다
		GdiTransparentBlt(hdc,	//복사될 영역의 DC == backDC
			destX,				//복사될 좌표 X	  == backDC의 영역의 좌표
			destY,				//복사될 좌표 Y
			_imageInfo->frameWidth,			//복사될 크기
			_imageInfo->frameHeight,			//복사될 크기
			_imageInfo->hMemDC,	//복사할 DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);
	}
	else
	{
		//비트블릿 == 백버퍼에 있는 걸 앞쪽으로 고속복사 해주는 함수
		BitBlt(hdc, destX, destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}

}

void image::loopRender(HDC hdc, const LPRECT drawArea, int OffSetX, int OffSetY)
{
	if (OffSetX < 0) OffSetX = _imageInfo->width + (OffSetX % _imageInfo->width);
	if (OffSetY < 0) OffSetY = _imageInfo->height + (OffSetY % _imageInfo->height);

	//오프셋 영역 받아올 변수
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//그려주는 영역
	RECT rcDest;

	//화면에 그려주는 영역 지정
	int drawAreaX = drawArea->left;						//Left
	int drawAreaY = drawArea->top;						//Top
	int drawAreaW = drawArea->right - drawArea->left;	//Width
	int drawAreaH = drawArea->bottom - drawArea->top;	//Height

	//Y Axis
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		rcSour.top = (y + OffSetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;

		sourHeight = rcSour.bottom - rcSour.top;

		//그려지는 영역의 높이값보다 ?? 크면
		if (y + sourHeight > drawAreaH)
		{
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		//뿌려주는 영역 
		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		//X Axis
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			rcSour.left = (x + OffSetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;

			sourWidth = rcSour.right - rcSour.left;

			if (x + sourWidth > drawAreaW)
			{
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			render(hdc, rcDest.left,				//뿌릴 X
				rcDest.top,					//뿌릴 Y
				rcSour.left, rcSour.top,	//뿌려올 X, Y
				rcSour.right - rcSour.left,	//뿌려올 이미지 가로크기
				rcSour.bottom - rcSour.top);//뿌려올 이미지 세로크기
		}
	}
}

void image::alphaRender(HDC hdc, BYTE alpha)
{
	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(_imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;


	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, (int)_imageInfo->x, (int)_imageInfo->y, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, (int)_imageInfo->x, (int)_imageInfo->y, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, (int)_imageInfo->x, (int)_imageInfo->y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}




void image::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(destX, destY, _imageInfo->width, _imageInfo->height);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	//알파값 ( 0 - 255 ) 수가 클수록 선명하다.
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}




void image::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{

	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(destX, destY, sourWidth, sourHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;


	//알파값 ( 0 - 255 ) 수가 클수록 선명하다.
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _transColor);

		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight,
			_blendImage->hMemDC, 0, 0, sourWidth, sourHeight, _blendFunc);
	}
	else
	{
		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _blendFunc);
	}
}

void image::aniRender(HDC hdc, int destX, int destY, animation* ani)
{

	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(destX, destY, ani->getFrameWidth(), ani->getFrameHeight());
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	_imageInfo->currentFrameX = ani->getFrameX();
	_imageInfo->currentFrameY = ani->getFrameY();

	render(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight());
}



void image::scaleAniRender(HDC hdc, int destX, int destY, animation* ani, int scaledWidth, int scaledHeight)
{
	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(destX, destY, scaledWidth, scaledHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	_imageInfo->currentFrameX = ani->getFrameX();
	_imageInfo->currentFrameY = ani->getFrameY();

	if (_trans)
	{
		GdiTransparentBlt(hdc, destX, destY, scaledWidth, scaledHeight,
			_imageInfo->hMemDC,
			ani->getFramePos().x, ani->getFramePos().y,
			ani->getFrameWidth(), ani->getFrameHeight(),
			_transColor);
	}
	else
	{
		StretchBlt(hdc, destX, destY, scaledWidth, scaledHeight,
			_imageInfo->hMemDC,
			ani->getFramePos().x, ani->getFramePos().y,
			ani->getFrameWidth(), ani->getFrameHeight(),
			SRCCOPY);
	}
}


void image::alphaAniRender(HDC hdc, int destX, int destY, animation* ani, float alpha)
{
	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(destX, destY, ani->getFrameWidth(), ani->getFrameHeight());
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	_imageInfo->currentFrameX = ani->getFrameX();
	_imageInfo->currentFrameY = ani->getFrameY();

	//알파값 ( 0 - 255 ) 수가 클수록 선명하다.
	_blendFunc.SourceConstantAlpha = alpha;

	//배경 삭제 필요한 경우
	if (_trans)
	{
		////배경 삭제 처리를 하는 경우 0이 opacity 100%가 된다.
		//_blendFunc.SourceConstantAlpha = (BYTE)(255 - (alpha * 255.0f));

		//backDC에 렌더링 할 x, y, width, height 영역을 일단 블렌드DC의 0,0에 복사한다.
		BitBlt(_blendImage->hMemDC, 0, 0,
			ani->getFrameWidth(), ani->getFrameHeight(),
			hdc, destX, destY, SRCCOPY);

		//블렌드DC에 이미지를 배경 삭제해서 복사한다. (원하는 프레임만 짤라서)
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, ani->getFrameWidth(), ani->getFrameHeight(),
			_imageInfo->hMemDC,
			ani->getFramePos().x, ani->getFramePos().y,
			ani->getFrameWidth(), ani->getFrameHeight(),
			_transColor);

		//블렌드DC의 내용을 backDC에 알파블렌드해서 복사한다.
		AlphaBlend(hdc, destX, destY, ani->getFrameWidth(), ani->getFrameHeight(),
			_blendImage->hMemDC,
			0, 0,
			ani->getFrameWidth(), ani->getFrameHeight(),
			_blendFunc);
	}
	//배경 삭제 필요 없는 경우
	else
	{
		////알파값 ( 0 - 255 ) 수가 클수록 선명하다.
		//_blendFunc.SourceConstantAlpha = (BYTE)((alpha * 255.0f));

		AlphaBlend(hdc, destX, destY, ani->getFrameWidth(), ani->getFrameHeight(),
			_imageInfo->hMemDC,
			ani->getFramePos().x, ani->getFramePos().y,
			ani->getFrameWidth(), ani->getFrameHeight(),
			_blendFunc);
	}
}





void image::alphaScaleAniRender(HDC hdc, int destX, int destY,
	animation* ani, int scaledWidth, int scaledHeight, float alpha)
{
	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(destX, destY, scaledWidth, scaledHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	_imageInfo->currentFrameX = ani->getFrameX();
	_imageInfo->currentFrameY = ani->getFrameY();

	//알파값 ( 0 - 255 ) 수가 클수록 선명하다.
	_blendFunc.SourceConstantAlpha = alpha;

	//배경 삭제 필요한 경우
	if (_trans)
	{
		////배경 삭제 처리를 하는 경우 0이 opacity 100%가 된다.
		//_blendFunc.SourceConstantAlpha = (BYTE)(255 - (alpha * 255.0f));

		//backDC에 렌더링 할 x, y, width, height 영역을 일단 블렌드DC의 0,0에 복사한다.
		BitBlt(_blendImage->hMemDC, 0, 0,
			scaledWidth, scaledHeight,
			hdc, destX, destY, SRCCOPY);

		//블렌드DC에 이미지를 배경 삭제해서 복사한다. (원하는 프레임만 짤라서)
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, scaledWidth, scaledHeight,
			_imageInfo->hMemDC,
			ani->getFramePos().x, ani->getFramePos().y,
			ani->getFrameWidth(), ani->getFrameHeight(),
			_transColor);

		//블렌드DC의 내용을 backDC에 알파블렌드해서 복사한다.
		AlphaBlend(hdc, destX, destY, scaledWidth, scaledHeight,
			_blendImage->hMemDC,
			0, 0,
			scaledWidth, scaledHeight,
			_blendFunc);
	}
	//배경 삭제 필요 없는 경우
	else
	{
		////알파값 ( 0 - 255 ) 수가 클수록 선명하다.
		//_blendFunc.SourceConstantAlpha = (BYTE)((alpha * 255.0f));

		AlphaBlend(hdc, destX, destY, scaledWidth, scaledHeight,
			_imageInfo->hMemDC,
			ani->getFramePos().x, ani->getFramePos().y,
			ani->getFrameWidth(), ani->getFrameHeight(),
			_blendFunc);
	}
}




void image::scaleRender(HDC hdc, int destX, int destY, int scaledWidth, int scaledHeight)
{
	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(destX, destY, scaledWidth, scaledHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	if (_trans)
	{
		GdiTransparentBlt(hdc, destX, destY, scaledWidth, scaledHeight,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_transColor);
	}
	else
	{
		StretchBlt(hdc, destX, destY, scaledWidth, scaledHeight,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			SRCCOPY);
	}
}


void image::alphaScaleFrameRender(HDC hdc, int destX, int destY, int frameX, int frameY, int scaledWidth, int scaledHeight, float alpha)
{

	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(destX, destY, scaledWidth, scaledHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	_imageInfo->currentFrameX = frameX;
	_imageInfo->currentFrameY = frameY;

	if (_trans)
	{
		_blendFunc.SourceConstantAlpha = (BYTE)(255 - (alpha * 255.0f));
		BitBlt(_blendImage->hMemDC, 0, 0,
			scaledWidth, scaledHeight,
			hdc, destX, destY, SRCCOPY);

		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, scaledWidth, scaledHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth, _imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_transColor);

		AlphaBlend(hdc, destX, destY, scaledWidth, scaledHeight,
			_blendImage->hMemDC,
			0, 0,
			scaledWidth, scaledHeight,
			_blendFunc);
	}
	else
	{
		_blendFunc.SourceConstantAlpha = (BYTE)((alpha * 255.0f));

		AlphaBlend(hdc, destX, destY, scaledWidth, scaledHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth, _imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight,
			_blendFunc);
	}

}


void image::frameScaleRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, int scaledWidth, int scaledHeight)
{

	//만약 렌더링 영역이 화면 밖이라면 그리지 않는다.
	RECT renderRC = RectMake(destX, destY, scaledWidth, scaledHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (_trans)
	{
		//화면에 뿌릴때 특정 생상을 걸러내준다
		GdiTransparentBlt(hdc,	//복사될 영역의 DC == backDC
			destX,				//복사될 좌표 X	  == backDC의 영역의 좌표
			destY,				//복사될 좌표 Y
			scaledWidth,			//복사될 크기
			scaledHeight,			//복사될 크기
			_imageInfo->hMemDC,	//복사할 DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);
	}
	else
	{
		//비트블릿 == 백버퍼에 있는 걸 앞쪽으로 고속복사 해주는 함수
		BitBlt(hdc, destX, destY,
			scaledWidth,
			scaledHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}
}