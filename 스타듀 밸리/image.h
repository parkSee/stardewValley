#pragma once
#include "animation.h"

//=========================================
// ## 2017. 07. 19 ## image Class ## 
//=========================================

class image
{
public:
	//�̹��� �ҷ����� ����
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,	//from ���ҽ�����
		LOAD_FILE,		//from ����
		LOAD_EMPTY,		//�� �̹�������
		LOAD_END	
	};

	typedef struct tagImageInfo
	{
		DWORD	resID;			//�������� ���̵� ���ҽ������� �ش� �������� ���̵�κ��� �������µ� �Ⱦ����� �Ƹ� �� _��
		HDC		hMemDC;			//�޸� DC(DC������ �޸�)
		HBITMAP hBit;			//��Ʈ��
		HBITMAP hOBit;			//�õ� ��Ʈ��
		float	x;
		float	y;
		int		width;			//���� ũ��
		int		height;			//���� ũ��
		int		currentFrameX;
		int		currentFrameY;
		int		maxFrameX;
		int		maxFrameY;
		int		frameWidth;
		int		frameHeight;
		BYTE	loadType;

		tagImageInfo()
		{
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			x = 0;
			y = 0;
			width = 0;
			height = 0;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;

private:
	LPIMAGE_INFO	_imageInfo;
	CHAR*			_fileName;
	BOOL			_trans;
	COLORREF		_transColor;

	BLENDFUNCTION	_blendFunc;
	LPIMAGE_INFO	_blendImage;

public:
	image();
	~image();

	//�� ��Ʈ�� �̹��� �ʱ�ȭ
	HRESULT init(int width, int height);
	//���� �̹��� �ʱ�ȭ
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);
	HRESULT init(const char* fileName, float x, float y, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const char* fileName, float x, float y, int width, int height,
		int frameX, int frameY, BOOL trans, COLORREF transColor);

	HRESULT init(const char* fileName, int width, int height,
		int frameX, int frameY, BOOL trans, COLORREF transColor);

	void release(void);

	void setTransColor(BOOL trans, COLORREF transColor);

	void render(HDC hdc);

	//�̹��� �����Լ�(dc����, �Ѹ���ǥX, �Ѹ���ǥY)
	void render(HDC hdc, int destX, int destY);
	//�̹��� ����			�Ѹ���ǥX �Ѹ���ǥY, �ѷ���X��ǥ �ѷ���Y��ǥ �ѷ��ð���ũ��  �ѷ��ü���ũ��
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);


	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	void loopRender(HDC hdc, const LPRECT drawArea, int OffSetX, int OffSetY);

	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	//�ַ� ����ϴ� ���� 
	void aniRender(HDC hdc, int destX, int destY, animation* ani);
	void scaleAniRender(HDC hdc, int destX, int destY, animation* ani, int scaledWidth, int scaledHeight);
	void scaleRender(HDC hdc, int destX, int destY, int scaledWidth, int scaledHeight);
	void alphaAniRender(HDC hdc, int destX, int destY, animation* ani, float alpha);
	void alphaScaleAniRender(HDC hdc, int destX, int destY, animation* ani, int scaledWidth, int scaledHeight, float alpha);
	void alphaScaleFrameRender(HDC hdc, int destX, int destY, int frameX, int frameY, int scaledWidth, int scaledHeight, float alpha);
	void frameScaleRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, int scaledWidth, int scaledHeight);


	//=================================================
	// �̹��� ������ �����ϰ� �ϱ� ���� ������, ������
	//=================================================

	inline HDC getMemDC() { return _imageInfo->hMemDC; }

	inline void setX(float x) { _imageInfo->x = x; }
	inline float getX(void) { return _imageInfo->x; }

	inline void setY(float y) { _imageInfo->y = y; }
	inline float getY(void) { return _imageInfo->y; }

	//��� ��ǥ�� ����
	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	inline float getCenterX()
	{
		return _imageInfo->maxFrameX <= 0 ? _imageInfo->x + (_imageInfo->width / 2) :
			_imageInfo->x + (_imageInfo->frameWidth / 2);
	}

	inline float getCenterY()
	{
		return _imageInfo->maxFrameY <= 0 ? _imageInfo->y + (_imageInfo->height / 2) :
			_imageInfo->y + (_imageInfo->frameHeight / 2);
	}

	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;
		if (_imageInfo->maxFrameX < frameX) _imageInfo->maxFrameX = frameX;
	}

	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (_imageInfo->maxFrameY < frameY) _imageInfo->maxFrameY = frameY;
	}

	inline int getWidth(void) { return _imageInfo->width; }
	inline int getHeight(void) { return _imageInfo->height; }

	inline int getMaxFrameX(void) { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY(void) { return _imageInfo->maxFrameY; }

	inline int getFrameX(void) { return _imageInfo->currentFrameX; }
	inline int getFrameY(void) { return _imageInfo->currentFrameY; }

	inline int getFrameWidth(void) { return _imageInfo->frameWidth; }
	inline int getFrameHeight(void) { return _imageInfo->frameHeight; }

};

