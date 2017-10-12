#pragma once
#include "animation.h"

//=========================================
// ## 2017. 07. 19 ## image Class ## 
//=========================================

class image
{
public:
	//이미지 불러오는 종류
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,	//from 리소스파일
		LOAD_FILE,		//from 파일
		LOAD_EMPTY,		//빈 이미지파일
		LOAD_END	
	};

	typedef struct tagImageInfo
	{
		DWORD	resID;			//레지스터 아이디 리소스파일은 해당 레지스터 아이디로부터 가져오는데 안쓸꺼야 아마 ㅋ _ㅋ
		HDC		hMemDC;			//메모리 DC(DC영역의 메모리)
		HBITMAP hBit;			//비트맵
		HBITMAP hOBit;			//올드 비트맵
		float	x;
		float	y;
		int		width;			//가로 크기
		int		height;			//세로 크기
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

	//빈 비트맵 이미지 초기화
	HRESULT init(int width, int height);
	//파일 이미지 초기화
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

	//이미지 렌더함수(dc영역, 뿌릴좌표X, 뿌릴좌표Y)
	void render(HDC hdc, int destX, int destY);
	//이미지 렌더			뿌릴좌표X 뿌릴좌표Y, 뿌려올X좌표 뿌려올Y좌표 뿌려올가로크기  뿌려올세로크기
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);


	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	void loopRender(HDC hdc, const LPRECT drawArea, int OffSetX, int OffSetY);

	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	//주로 사용하는 랜더 
	void aniRender(HDC hdc, int destX, int destY, animation* ani);
	void scaleAniRender(HDC hdc, int destX, int destY, animation* ani, int scaledWidth, int scaledHeight);
	void scaleRender(HDC hdc, int destX, int destY, int scaledWidth, int scaledHeight);
	void alphaAniRender(HDC hdc, int destX, int destY, animation* ani, float alpha);
	void alphaScaleAniRender(HDC hdc, int destX, int destY, animation* ani, int scaledWidth, int scaledHeight, float alpha);
	void alphaScaleFrameRender(HDC hdc, int destX, int destY, int frameX, int frameY, int scaledWidth, int scaledHeight, float alpha);
	void frameScaleRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, int scaledWidth, int scaledHeight);


	//=================================================
	// 이미지 조작을 간편하게 하기 위한 접근자, 설정자
	//=================================================

	inline HDC getMemDC() { return _imageInfo->hMemDC; }

	inline void setX(float x) { _imageInfo->x = x; }
	inline float getX(void) { return _imageInfo->x; }

	inline void setY(float y) { _imageInfo->y = y; }
	inline float getY(void) { return _imageInfo->y; }

	//가운데 좌표로 보정
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

