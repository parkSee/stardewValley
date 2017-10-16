#include "stdafx.h"
#include "image.h"

//# �����Ϸ� ���ñ�
#pragma comment(lib, "msimg32.lib")

//��� �̴ϼȶ����� == const �Ӽ��� �ʱ�ȭ�� ���� ź���� �Ǿ��µ�
//�����ڴ� �� ��ü�� �Ҵ��̵Ǹ� �ڵ����� ������ �Ǳ� ������
//��� �Ҵ��ؼ� ����� ��ü�� ������ ���ٸ� �̷�������
//�ʱ�ȭ�� �ؼ� ����Ҽ� �ִ�
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

//�� ��Ʈ�� �̹��� �ʱ�ȭ
HRESULT image::init(int width, int height)
{
	//�̹��� ������ ���� �ִ�!? �� ������ �ض�
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);//�� DC������ ����
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);//ũ�� ��ŭ�� �� ��Ʈ�� ���� ����
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	_fileName = NULL;

	_trans = FALSE;
	_transColor = RGB(0, 0, 0);

	//���ĺ��� ����
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
//���� �̹��� �ʱ�ȭ
HRESULT image::init(const char* fileName, int width, int height,
	BOOL trans, COLORREF transColor)
{
	//�����̸��� ���ٸ� �����޽��� ������
	if (fileName == NULL) return E_FAIL;

	//�̹��� ������ ���� �ִ�!? �� ������ �ض�
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);//�� DC������ ����
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->width = width;
	_imageInfo->height = height;

	int len = strlen(fileName);

	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	_trans = trans;
	_transColor = transColor;

	//���ĺ��� ����
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
	//�����̸��� ���ٸ� �����޽��� ������
	if (fileName == NULL) return E_FAIL;

	//�̹��� ������ ���� �ִ�!? �� ������ �ض�
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);//�� DC������ ����
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

	//���ĺ��� ����
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
	//�����̸��� ���ٸ� �����޽��� ������
	if (fileName == NULL) return E_FAIL;

	//�̹��� ������ ���� �ִ�!? �� ������ �ض�
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);//�� DC������ ����
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

	//���ĺ��� ����
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
	//�����̸��� ���ٸ� �����޽��� ������
	if (fileName == NULL) return E_FAIL;

	//�̹��� ������ ���� �ִ�!? �� ������ �ض�
	if (_imageInfo != NULL) release();

	HDC hdc = GetDC(_hWnd);

	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);//�� DC������ ����
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

	//���ĺ��� ����
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
	//�̹��� ������ �ִٸ�
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
	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
	RECT renderRC = RectMake(_imageInfo->x, _imageInfo->y, _imageInfo->width, _imageInfo->height);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	if (_trans)
	{
		//Ư�� Į�� �����ִ� �Լ�
		GdiTransparentBlt(hdc,		//����� ����� DC
			_imageInfo->x,			//����� ��ǥ ������X(left)
			_imageInfo->y,			//����� ��ǥ ������Y(top)
			_imageInfo->width,		//����� �̹��� ����ũ��
			_imageInfo->height,		//����� �̹��� ����ũ��
			_imageInfo->hMemDC,		//���� ��� DC
			0, 0,					//����� ��������
			_imageInfo->width,		//����� ����ũ��
			_imageInfo->height,		//����� ����ũ��
			_transColor);			//������ Į��
	}
	else
	{
		BitBlt(hdc, _imageInfo->x, _imageInfo->y,
			_imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

//�̹��� �����Լ�(dc����, �Ѹ���ǥX, �Ѹ���ǥY)
void image::render(HDC hdc, int destX, int destY)
{
	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
	RECT renderRC = RectMake(destX, destY, _imageInfo->width, _imageInfo->height);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	if (_trans)
	{
		//ȭ�鿡 �Ѹ��� Ư�� ������ �ɷ����ش�
		GdiTransparentBlt(hdc,	//����� ������ DC == backDC
			destX,				//����� ��ǥ X	  == backDC�� ������ ��ǥ
			destY,				//����� ��ǥ Y
			_imageInfo->width,	//����� ũ��
			_imageInfo->height,	//����� ũ��
			_imageInfo->hMemDC,	//������ DC
			0, 0,				//�����ؿ� ��ǥ
			_imageInfo->width,	//�����ؿ� ũ��
			_imageInfo->height,
			_transColor);		//�� Į��
	}
	else
	{
		//��Ʈ�� == ����ۿ� �ִ� �� �������� ��Ӻ��� ���ִ� �Լ�
		BitBlt(hdc, destX, destY,
			_imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

void image::render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight)
{
	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
	RECT renderRC = RectMake(destX, destY, sourWidth, sourHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	if (_trans)
	{
		//ȭ�鿡 �Ѹ��� Ư�� ������ �ɷ����ش�
		GdiTransparentBlt(hdc,	//����� ������ DC == backDC
			destX,				//����� ��ǥ X	  == backDC�� ������ ��ǥ
			destY,				//����� ��ǥ Y
			sourWidth,			//����� ũ��
			sourHeight,			//����� ũ��
			_imageInfo->hMemDC,	//������ DC
			sourX, sourY,		//�����ؿ� ��ǥ
			sourWidth,			//�����ؿ� ũ��
			sourHeight,
			_transColor);		//�� Į��
	}
	else
	{
		//��Ʈ�� == ����ۿ� �ִ� �� �������� ��Ӻ��� ���ִ� �Լ�
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
	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
	RECT renderRC = RectMake(destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	if (_trans)
	{
		//ȭ�鿡 �Ѹ��� Ư�� ������ �ɷ����ش�
		GdiTransparentBlt(hdc,	//����� ������ DC == backDC
			destX,				//����� ��ǥ X	  == backDC�� ������ ��ǥ
			destY,				//����� ��ǥ Y
			_imageInfo->frameWidth,			//����� ũ��
			_imageInfo->frameHeight,			//����� ũ��
			_imageInfo->hMemDC,	//������ DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth, 
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,			
			_imageInfo->frameHeight,
			_transColor);		
	}
	else
	{
		//��Ʈ�� == ����ۿ� �ִ� �� �������� ��Ӻ��� ���ִ� �Լ�
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

	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
	//RECT renderRC = RectMake(destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight);
	//if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
	//	return;

	if (_trans)
	{
		//ȭ�鿡 �Ѹ��� Ư�� ������ �ɷ����ش�
		GdiTransparentBlt(hdc,	//����� ������ DC == backDC
			destX,				//����� ��ǥ X	  == backDC�� ������ ��ǥ
			destY,				//����� ��ǥ Y
			_imageInfo->frameWidth,			//����� ũ��
			_imageInfo->frameHeight,			//����� ũ��
			_imageInfo->hMemDC,	//������ DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);
	}
	else
	{
		//��Ʈ�� == ����ۿ� �ִ� �� �������� ��Ӻ��� ���ִ� �Լ�
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

	//������ ���� �޾ƿ� ����
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//�׷��ִ� ����
	RECT rcDest;

	//ȭ�鿡 �׷��ִ� ���� ����
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

		//�׷����� ������ ���̰����� ?? ũ��
		if (y + sourHeight > drawAreaH)
		{
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		//�ѷ��ִ� ���� 
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

			render(hdc, rcDest.left,				//�Ѹ� X
				rcDest.top,					//�Ѹ� Y
				rcSour.left, rcSour.top,	//�ѷ��� X, Y
				rcSour.right - rcSour.left,	//�ѷ��� �̹��� ����ũ��
				rcSour.bottom - rcSour.top);//�ѷ��� �̹��� ����ũ��
		}
	}
}

void image::alphaRender(HDC hdc, BYTE alpha)
{
	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
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
	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
	RECT renderRC = RectMake(destX, destY, _imageInfo->width, _imageInfo->height);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	//���İ� ( 0 - 255 ) ���� Ŭ���� �����ϴ�.
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

	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
	RECT renderRC = RectMake(destX, destY, sourWidth, sourHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;


	//���İ� ( 0 - 255 ) ���� Ŭ���� �����ϴ�.
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

	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
	RECT renderRC = RectMake(destX, destY, ani->getFrameWidth(), ani->getFrameHeight());
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	_imageInfo->currentFrameX = ani->getFrameX();
	_imageInfo->currentFrameY = ani->getFrameY();

	render(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight());
}



void image::scaleAniRender(HDC hdc, int destX, int destY, animation* ani, int scaledWidth, int scaledHeight)
{
	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
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
	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
	RECT renderRC = RectMake(destX, destY, ani->getFrameWidth(), ani->getFrameHeight());
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	_imageInfo->currentFrameX = ani->getFrameX();
	_imageInfo->currentFrameY = ani->getFrameY();

	//���İ� ( 0 - 255 ) ���� Ŭ���� �����ϴ�.
	_blendFunc.SourceConstantAlpha = alpha;

	//��� ���� �ʿ��� ���
	if (_trans)
	{
		////��� ���� ó���� �ϴ� ��� 0�� opacity 100%�� �ȴ�.
		//_blendFunc.SourceConstantAlpha = (BYTE)(255 - (alpha * 255.0f));

		//backDC�� ������ �� x, y, width, height ������ �ϴ� ����DC�� 0,0�� �����Ѵ�.
		BitBlt(_blendImage->hMemDC, 0, 0,
			ani->getFrameWidth(), ani->getFrameHeight(),
			hdc, destX, destY, SRCCOPY);

		//����DC�� �̹����� ��� �����ؼ� �����Ѵ�. (���ϴ� �����Ӹ� ©��)
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, ani->getFrameWidth(), ani->getFrameHeight(),
			_imageInfo->hMemDC,
			ani->getFramePos().x, ani->getFramePos().y,
			ani->getFrameWidth(), ani->getFrameHeight(),
			_transColor);

		//����DC�� ������ backDC�� ���ĺ����ؼ� �����Ѵ�.
		AlphaBlend(hdc, destX, destY, ani->getFrameWidth(), ani->getFrameHeight(),
			_blendImage->hMemDC,
			0, 0,
			ani->getFrameWidth(), ani->getFrameHeight(),
			_blendFunc);
	}
	//��� ���� �ʿ� ���� ���
	else
	{
		////���İ� ( 0 - 255 ) ���� Ŭ���� �����ϴ�.
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
	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
	RECT renderRC = RectMake(destX, destY, scaledWidth, scaledHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	_imageInfo->currentFrameX = ani->getFrameX();
	_imageInfo->currentFrameY = ani->getFrameY();

	//���İ� ( 0 - 255 ) ���� Ŭ���� �����ϴ�.
	_blendFunc.SourceConstantAlpha = alpha;

	//��� ���� �ʿ��� ���
	if (_trans)
	{
		////��� ���� ó���� �ϴ� ��� 0�� opacity 100%�� �ȴ�.
		//_blendFunc.SourceConstantAlpha = (BYTE)(255 - (alpha * 255.0f));

		//backDC�� ������ �� x, y, width, height ������ �ϴ� ����DC�� 0,0�� �����Ѵ�.
		BitBlt(_blendImage->hMemDC, 0, 0,
			scaledWidth, scaledHeight,
			hdc, destX, destY, SRCCOPY);

		//����DC�� �̹����� ��� �����ؼ� �����Ѵ�. (���ϴ� �����Ӹ� ©��)
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, scaledWidth, scaledHeight,
			_imageInfo->hMemDC,
			ani->getFramePos().x, ani->getFramePos().y,
			ani->getFrameWidth(), ani->getFrameHeight(),
			_transColor);

		//����DC�� ������ backDC�� ���ĺ����ؼ� �����Ѵ�.
		AlphaBlend(hdc, destX, destY, scaledWidth, scaledHeight,
			_blendImage->hMemDC,
			0, 0,
			scaledWidth, scaledHeight,
			_blendFunc);
	}
	//��� ���� �ʿ� ���� ���
	else
	{
		////���İ� ( 0 - 255 ) ���� Ŭ���� �����ϴ�.
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
	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
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

	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
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

	//���� ������ ������ ȭ�� ���̶�� �׸��� �ʴ´�.
	RECT renderRC = RectMake(destX, destY, scaledWidth, scaledHeight);
	if (renderRC.right < 0 || renderRC.left > WINSIZEX || renderRC.top > WINSIZEY || renderRC.bottom < 0)
		return;

	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (_trans)
	{
		//ȭ�鿡 �Ѹ��� Ư�� ������ �ɷ����ش�
		GdiTransparentBlt(hdc,	//����� ������ DC == backDC
			destX,				//����� ��ǥ X	  == backDC�� ������ ��ǥ
			destY,				//����� ��ǥ Y
			scaledWidth,			//����� ũ��
			scaledHeight,			//����� ũ��
			_imageInfo->hMemDC,	//������ DC
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);
	}
	else
	{
		//��Ʈ�� == ����ۿ� �ִ� �� �������� ��Ӻ��� ���ִ� �Լ�
		BitBlt(hdc, destX, destY,
			scaledWidth,
			scaledHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}
}