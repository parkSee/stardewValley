#pragma once
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <iostream>
#include <memory.h>
#include <tchar.h>

using namespace std;

#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "imageManager.h"
#include "keyManager.h"
#include "soundManager.h"
#include "timeManager.h"
#include "effectManager.h"
#include "sceneManager.h"
#include "cameraManager.h"

#include "utils.h"
#include "collision.h"
#include "txtData.h"

#include "keyAniManager.h"
#include "iniDataManager.h"

//================���� ���======================
#include "tagMessage.h"
#include "townWorld.h"
#include "worldTime.h"

using namespace OMICRON_UTIL;

//========================================
// ## ������ �� ## 17.07.03 ##
//========================================

#define WINNAME (LPTSTR)(TEXT("Omicron API"))
#define WINSTARTX 80
#define WINSTARTY 10
#define WINSIZEX 1300
#define WINSIZEY 800
#define WINSTYLE WS_CAPTION | WS_SYSMENU


//=============================================================
// ## 17.07.06 ## Singleton Define ##
//=============================================================

#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define SCENEMANAGER sceneManager::getSingleton()
#define KEYANIMANAGER keyAniManager::getSingleton()
#define CAMERAMANAGER cameraManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define INIDATA iniDataManager::getSingleton()
#define WORLDTIME worldTime::getSingleton()


#define TOWNWORLD townWorld::getSingleton()

//=============================================================
// ## 17.07.06 ## Macro ##
//=============================================================

#define SAFE_DELETE(p) {if(p) {delete(p); (p) = NULL;}}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p)=NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p) { delete[](p); (p) = NULL;}}

//=============================================================
// ## 17.07.06 ## �������� ##
//=============================================================

extern HINSTANCE _hInstance;
extern HWND _hWnd;
extern POINT _ptMouse;
extern BOOL _leftButtonDown;

#define ABSMOUSEX (CAMERAMANAGER->getRenderRc().left + _ptMouse.x)
#define ABSMOUSEY (CAMERAMANAGER->getRenderRc().top + _ptMouse.y)
