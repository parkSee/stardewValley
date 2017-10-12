#include "stdafx.h"
#include "saveLoadTest.h"


saveLoadTest::saveLoadTest()
{
}


saveLoadTest::~saveLoadTest()
{

}

void saveLoadTest::update(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) save();
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON)) load();
}

void saveLoadTest::save(void)  
{
	//파일 입출력
	//C - FILE*
	//C++ - ifstream, ofstream
	//WIN32 - CreateFile

	HANDLE file;

	char str[128] = "현지니 리즈시절은 꽃미남";

	DWORD write;

	file = CreateFile("오미크론의꽃미남.txt", GENERIC_WRITE, FALSE, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, strlen(str), &write, NULL);

	CloseHandle(file);

}

void saveLoadTest::load(void)  
{
	HANDLE file;

	char str[128];

	DWORD read;

	file = CreateFile("오미크론의꽃미남.txt", GENERIC_READ, FALSE, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, strlen(str), &read, NULL);

	CloseHandle(file);

	MessageBox(_hWnd, str, "반장어딨어", MB_OK);
}

