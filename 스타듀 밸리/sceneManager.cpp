#include "stdafx.h"
#include "sceneManager.h"
#include "gameNode.h"

//friend �����ϸ� ĸ��ȭ�� �����ϰ� private ���� �׳� ���ٰ�������
//��� �ǹ����� �� �Ⱦ�(���� Ư���� ���ϱ��� �ҋ� �ƴϸ�...)
DWORD CALLBACK loadingThread(LPVOID prc)
{
	sceneManager::_readyScene->init();

	sceneManager::_currentScene = sceneManager::_readyScene;

	sceneManager::_loadingScene->release();
	sceneManager::_loadingScene = NULL;
	sceneManager::_readyScene = NULL;

	return 0;
}

gameNode* sceneManager::_currentScene = NULL;
gameNode* sceneManager::_loadingScene = NULL;
gameNode* sceneManager::_readyScene = NULL;

sceneManager::sceneManager()
{
}


sceneManager::~sceneManager()
{

}

HRESULT sceneManager::init(void)
{
	_currentScene = NULL;
	_loadingScene = NULL;
	_readyScene = NULL;
	
	return S_OK;
}

void sceneManager::release(void)
{
	mapSceneIter miSceneList = _mSceneList.begin();

	for (; miSceneList != _mSceneList.end();)
	{
		if (miSceneList->second != NULL)
		{
			if (miSceneList->second == _currentScene) miSceneList->second->release();
			SAFE_DELETE(miSceneList->second);
			miSceneList = _mSceneList.erase(miSceneList);
		}
		else ++miSceneList;
	}

	_mSceneList.clear();
}

void sceneManager::update(void)	
{
	if (_currentScene) _currentScene->update();
}

void sceneManager::render(void)	
{
	if (_currentScene) _currentScene->render();
}


//�� �߰�
gameNode* sceneManager::addScene(string sceneName, gameNode* scene)				 
{
	//���� ���ٸ� �� ó��
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}

gameNode* sceneManager::addLoadingScene(string loadingSceneName, gameNode* scene)
{
	//���� ���ٸ� �� ó��
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(loadingSceneName, scene));

	return scene;
}


//�� ����
HRESULT sceneManager::changeScene(string sceneName)							
{
	//���ͷ����Ϳ� ã�����ϴ� (��) Ű ���� �ִ´�
	mapSceneIter find = _mSceneList.find(sceneName);

	//���ͷ����Ͱ� ���� ������ �����ߴ� == �� �ȿ� �� ���� �������� �ʴ´� == �����ߴٰ� �˷���
	if (find == _mSceneList.end()) return E_FAIL;

	//���ͷ������� ���� ������� ������ �ٲ��ʿ���ٰ� ���ض��~
	if (find->second == _currentScene) return S_OK;

	//���� �ٲٷ��� ���� Ű���� ã�Ҵٸ� �ʱ�ȭ. ������
	if (SUCCEEDED(find->second->init()))
	{
		//���� ���� �ִٸ� �� ���� �����ϰ�
		if (_currentScene) _currentScene->release();
		//������� ã�� ���� �ִ´�.
		_currentScene = find->second;

		return S_OK;
	}

	return E_FAIL;
}

//�ʳװ� ���߿� �� �����ؼ� �����
HRESULT sceneManager::changeScene(string sceneName, string loadingSceneName)
{
	//���ͷ����Ϳ� ã�����ϴ� (��) Ű ���� �ִ´�
	mapSceneIter find = _mSceneList.find(sceneName);

	//���ͷ����Ͱ� ���� ������ �����ߴ� == �� �ȿ� �� ���� �������� �ʴ´� == �����ߴٰ� �˷���
	if (find == _mSceneList.end()) return E_FAIL;

	//���ͷ������� ���� ������� ������ �ٲ��ʿ���ٰ� ���ض��~
	if (find->second == _currentScene) return S_OK;

	mapSceneIter findLoading = _mLoadingSceneList.find(loadingSceneName);

	if (find == _mLoadingSceneList.end()) return changeScene(loadingSceneName);

	if (SUCCEEDED(find->second->init()))
	{
		if (_currentScene) _currentScene->release();

		_loadingScene = findLoading->second;
		_readyScene = find->second;
		CloseHandle(CreateThread(NULL, 0, loadingThread, NULL, 0, &_loadingThreadID));
	}


	return E_FAIL;
}


