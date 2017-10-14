#pragma once
#include "gameNode.h"
#include "progressBar.h"

enum LOAD_KIND
{
	LOAD_KIND_IMAGE_0,
	LOAD_KIND_IMAGE_1,
	LOAD_KIND_IMAGE_2,
	LOAD_KIND_FRAMEIMAGE_0,
	LOAD_KIND_FRAMEIMAGE_1,
	LOAD_KIND_SOUND,
	LOAD_KIND_END
};

struct tagImageResource
{
	string keyName;
	const char* fileName;
	float x, y;
	int width, height;
	int frameX, frameY;
	bool trans;
	COLORREF transColor;
};

struct tagSoundResource
{
	string keyName;
	const char* fileName;
	bool bgm;
	bool roop;
};

class loadItem
{
private:
	LOAD_KIND _kind;
	tagImageResource _imageResource;
	tagSoundResource _soundResource;

public:
	HRESULT initForImage(string keyName, int width, int height);
	HRESULT initForImage(string keyName, const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));
	HRESULT initForImage(string keyName, const char* fileName, float x, float y, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT initForFrameImage(string keyName, const char* fileName, int width, int height,
		int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));

	HRESULT initForFrameImage(string keyName, const char* fileName, float x, float y, int width, int height,
		int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));

	HRESULT initForSound(string keyName, const char* fileName, bool bgm = false, bool roop = false);


	LOAD_KIND getLoadingKind(void) { return _kind; }

	tagImageResource getImageResource(void) { return _imageResource; }
	tagSoundResource getSoundResource() { return _soundResource; }

	loadItem();
	~loadItem();
};

class loading : public gameNode
{
private:
	typedef vector<loadItem*> arrLoadItem;
	typedef vector<loadItem*>::iterator arrLoadItemIter;

private:
	arrLoadItem _vLoadItem;

	int _count;
	int _index;

	float _loadingCharX;

	progressBar* _loadingBar;

	int _currentGauge;

	//char _loadFile[64];
	string  _loadFile;
	char    _dot[100];
	int _dotCount;
	int _dotIndex;

	const char* _fileName;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void loadImage(string keyName, int width, int height);
	void loadImage(string keyName, const char* fileName, int width, int height, BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));
	void loadImage(string keyName, const char* fileName, float x, float y, int width, int height, BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));
	void loadFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));
	void loadFrameImage(string keyName, const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));

	void loadSound(string keyName, const char* fileName, bool bgm = false, bool roop = false);

	BOOL loadingDone();

	vector<loadItem*> getLoadItem() { return _vLoadItem; }
	int getCullentGauge() { return _currentGauge; }

	loading();
	~loading();
};

