#include "stdafx.h"
#include "loading.h"
#include <direct.h>

loadItem::loadItem() {}
loadItem::~loadItem() {}

HRESULT loadItem::initForImage(string keyName, int width, int height)
{
	_kind = LOAD_KIND_IMAGE_0;

	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.width = width;
	_imageResource.height = height;

	return S_OK;
}

HRESULT loadItem::initForImage(string keyName, const char* fileName, int width, int height,
	BOOL trans, COLORREF transColor)
{
	_kind = LOAD_KIND_IMAGE_1;

	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = trans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForImage(string keyName, const char* fileName, float x, float y, int width, int height,
	BOOL trans, COLORREF transColor)
{
	_kind = LOAD_KIND_IMAGE_2;

	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.trans = trans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForFrameImage(string keyName, const char* fileName, int width, int height,
	int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	_kind = LOAD_KIND_FRAMEIMAGE_0;

	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;
	_imageResource.trans = trans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForFrameImage(string keyName, const char* fileName, float x, float y, int width, int height,
	int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	_kind = LOAD_KIND_FRAMEIMAGE_1;

	memset(&_imageResource, 0, sizeof(tagImageResource));

	_imageResource.keyName = keyName;
	_imageResource.fileName = fileName;
	_imageResource.x = x;
	_imageResource.y = y;
	_imageResource.width = width;
	_imageResource.height = height;
	_imageResource.frameX = frameX;
	_imageResource.frameY = frameY;
	_imageResource.trans = trans;
	_imageResource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForSound(string keyName, const char* fileName, bool bgm, bool roop)
{
	_kind = LOAD_KIND_SOUND;

	ZeroMemory(&_soundResource, sizeof(tagSoundResource));

	_soundResource.keyName = keyName;
	_soundResource.fileName = fileName;
	_soundResource.bgm = bgm;
	_soundResource.roop = roop;

	return S_OK;
}



loading::loading()
	:_dot("")
{
}


loading::~loading()
{

}

HRESULT loading::init()
{
	IMAGEMANAGER->addImage("loading_scroll_left", "resource/UI/scroll_left.bmp", 48, 71, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("loading_scroll_right", "resource/UI/scroll_right.bmp", 48, 71, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("loading_scroll_center", "resource/UI/scroll_center.bmp", 300, 71, true, RGB(255, 0, 255));


	_count = 0;
	_index = 0;
	

	_loadingBar = new progressBar;
	_loadingBar->init("loadingBarTop", "loadingBarBottom", WINSIZEX / 2, WINSIZEY - 20, WINSIZEX, 20);
	_loadingBar->setGauge(0, 0);

	_currentGauge = 0;

	_loadingCharX = 0;

	_fileName = NULL;
	_dotCount = 0;
	_dotIndex = 0;

	return S_OK;

}

void loading::release()
{
	SAFE_DELETE(_loadingBar);
}

void loading::update()
{
	_loadingBar->update();

	_loadingCharX = _loadingBar->getProgerssBarRight();
}

void loading::render()
{
	//검은 배경 깔아줬음
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//카운트 줘서 . . . . . 하나씩 증가하게 만들었음
	char str[100];
	char behindStr[100];

	_dotCount++;
	if (_dotCount % 60 == 0)
	{
		strcat(_dot, " . ");
		_dotIndex++;
		_dotCount = 0;
		if (_dotIndex >= 3)
		{
			strtok(str, ".");
		}
	}
	//스크롤 이미지 그려주자
	IMAGEMANAGER->findImage("loading_scroll_left")->render(getMemDC(), 10, 700);
	IMAGEMANAGER->findImage("loading_scroll_center")->render(getMemDC(), 10 + IMAGEMANAGER->findImage("loading_scroll_left")->getWidth()
		, 700);
	IMAGEMANAGER->findImage("loading_scroll_right")->render(getMemDC(), 10 + IMAGEMANAGER->findImage("loading_scroll_left")->getWidth() +
		IMAGEMANAGER->findImage("loading_scroll_center")->getWidth(), 700);

	//str에 . 하나 씩 추가 해주고
	sprintf(str, "Loading~ %s", _dot);
	sprintf(behindStr, "Loading~ %s", _dot);
	//텍스트 그릴 때 흰색 바탕 안생기게 해주고
	SetBkMode(getMemDC(), TRANSPARENT);
	//textDraw해줄 렉트 
	RECT rcText = RectMake(60,685, 400, 100);
	RECT rcBehindText = RectMake(62, 687, 400, 100);
	//font 설정 
	HFONT font  = CreateFont(30,0,0,0,100,false,false,false,
		DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_DEFAULT_PRECIS,
		PROOF_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("HY엽서L"));
	HFONT oldFont = (HFONT)SelectObject(getMemDC(), font);
	//textDraw
	SetTextColor(getMemDC(), RGB(100, 100, 50));
	DrawText(getMemDC(), behindStr, strlen(behindStr), &rcBehindText, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	SetTextColor(getMemDC(), RGB(100, 100, 150));
	DrawText(getMemDC(), str, strlen(str), &rcText, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
	SelectObject(getMemDC(), oldFont);
	DeleteObject(font);

}


void loading::loadImage(string keyName, int width, int height)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, width, height);

	_vLoadItem.push_back(item);
}

void loading::loadImage(string keyName, const char* fileName, int width, int height, BOOL trans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, fileName, width, height, trans, transColor);



	_vLoadItem.push_back(item);
}

void loading::loadImage(string keyName, const char* fileName, float x, float y, int width, int height, BOOL trans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, fileName, x, y, width, height, trans, transColor);



	_vLoadItem.push_back(item);
}

void loading::loadFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForFrameImage(keyName, fileName, width, height, frameX, frameY, trans, transColor);



	_vLoadItem.push_back(item);
}

void loading::loadFrameImage(string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForFrameImage(keyName, fileName, x, y, width, frameX, frameY, height, trans, transColor);



	_vLoadItem.push_back(item);
}

void loading::loadSound(string keyName, const char* fileName, bool bgm, bool roop)
{
	loadItem* item = new loadItem;
	item->initForSound(keyName, fileName, bgm, roop);
	_vLoadItem.push_back(item);

}


BOOL loading::loadingDone()
{
	if (_currentGauge >= _vLoadItem.size())
	{
		return TRUE;
	}

	loadItem* item = _vLoadItem[_currentGauge];

	switch (item->getLoadingKind())
	{
	case LOAD_KIND_IMAGE_0:
	{
		tagImageResource img = item->getImageResource();
		IMAGEMANAGER->addImage(img.keyName, img.width, img.height);

		_loadFile = img.keyName;

		_fileName = img.fileName;
	}
	break;
	case LOAD_KIND_IMAGE_1:
	{
		tagImageResource img = item->getImageResource();
		IMAGEMANAGER->addImage(img.keyName, img.fileName,
			img.width, img.height, img.trans, img.transColor);

		_loadFile = img.keyName;

		_fileName = img.fileName;
	}
	break;
	case LOAD_KIND_IMAGE_2:
	{
		tagImageResource img = item->getImageResource();
		IMAGEMANAGER->addImage(img.keyName, img.fileName,
			img.x, img.y,
			img.width, img.height,
			img.trans, img.transColor);

		_loadFile = img.keyName;

		_fileName = img.fileName;
	}
	break;
	case LOAD_KIND_FRAMEIMAGE_0:
	{
		tagImageResource img = item->getImageResource();
		IMAGEMANAGER->addFrameImage(img.keyName, img.fileName,
			img.width, img.height,
			img.frameX, img.frameY,
			img.trans, img.transColor);

		_loadFile = img.keyName;

		_fileName = img.fileName;
	}
	break;
	case LOAD_KIND_FRAMEIMAGE_1:
	{
		tagImageResource img = item->getImageResource();
		IMAGEMANAGER->addFrameImage(img.keyName, img.fileName,
			img.x, img.y,
			img.width, img.height,
			img.frameX, img.frameY,
			img.trans, img.transColor);
		_loadFile = img.keyName;
		_fileName = img.fileName;
	}
	break;
	case LOAD_KIND_SOUND:
	{
		tagSoundResource sound = item->getSoundResource();
		SOUNDMANAGER->addSound(sound.keyName, sound.fileName, sound.bgm, sound.roop);

		_loadFile = sound.keyName;
		_fileName = sound.fileName;
	}
	break;
	}


	_loadingBar->setGauge(_currentGauge, _vLoadItem.size());
	_currentGauge++;

	return FALSE;
}




//HDC hdc = getMemDC();
//char str[1000];
//sprintf(str, "%s", _loadFile.c_str());
//SetBkMode(hdc, TRANSPARENT);
//SetTextColor(hdc, RGB(0, 255, 0));
//
//if (_fileName != NULL)
//{
//	_getcwd(str, 1000);
//	strcat(str, "\\");
//	strcat(str, _fileName);
//	TextOut(hdc, 10, 783, str, strlen(str));
//}
//로딩 파일 들 이름 불러오는건데 나중에 넣어야 되면 그때 사용