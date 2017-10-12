#include "stdafx.h"
#include "txtData.h"


txtData::txtData()
{
}


txtData::~txtData()
{

}

HRESULT txtData::init()
{

	return S_OK;
}

void txtData::release()
{

}


//세이브
void txtData::txtSave(const char* saveFileName, vector<string> vStr)
{
	HANDLE file;

	char str[128];
	DWORD write;

	strncpy_s(str, 128, vectorArrayCombine(vStr), 126);

	file = CreateFile(saveFileName, GENERIC_WRITE, 0, NULL,
		CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, str, 128, &write, NULL);

	CloseHandle(file);

}

char* txtData::vectorArrayCombine(vector<string> vArray)			
{
	char str[128];

	ZeroMemory(str, sizeof(str));
	//예시) 벡터의 사이즈는 5개다 12345
	for (int i = 0; i < vArray.size(); i++)
	{
		//순우 왈 : 벡터에 담긴 문자열들이 str에 담긴다
		strncat_s(str, 128, vArray[i].c_str(), 126);
		//순우 왈 : 마지막 문자빼곤 죄다 콤마를 찍어준다
		if (i + 1 < vArray.size()) strcat(str, ",");
	}
	return str;
}


//로드
vector<string> txtData::txtLoad(const char* loadFileName)	 
{
	HANDLE file;

	char str[128];
	DWORD read;

	file = CreateFile(loadFileName, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, str, 128, &read, NULL);

	CloseHandle(file);

	return charArraySeparation(str);
}

vector<string> txtData::charArraySeparation(char charArray[])
{
	vector<string> vArray;

	char* temp;
	char* separator = ",";
	char* token;

	token = strtok(charArray, separator);
	vArray.push_back(token);

	while (NULL != (token = strtok(NULL, separator)))
	{
		vArray.push_back(token);
	}

	return vArray;
}
