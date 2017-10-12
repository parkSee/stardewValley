#include "stdafx.h"
#include "sceneManager.h"
#include "gameNode.h"

//friend 선언하면 캡슐화를 무시하고 private 까지 그냥 접근가능해짐
//고로 실무에선 잘 안씀(정말 특정한 패턴구현 할떄 아니면...)
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


//씬 추가
gameNode* sceneManager::addScene(string sceneName, gameNode* scene)				 
{
	//씬이 없다면 널 처리
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(sceneName, scene));

	return scene;
}

gameNode* sceneManager::addLoadingScene(string loadingSceneName, gameNode* scene)
{
	//씬이 없다면 널 처리
	if (!scene) return NULL;

	_mSceneList.insert(make_pair(loadingSceneName, scene));

	return scene;
}


//씬 변경
HRESULT sceneManager::changeScene(string sceneName)							
{
	//이터레이터에 찾고자하는 (씬) 키 값을 넣는다
	mapSceneIter find = _mSceneList.find(sceneName);

	//이터레이터가 맵의 끝까지 도달했다 == 맵 안에 그 씬이 존재하지 않는다 == 실패했다고 알려라
	if (find == _mSceneList.end()) return E_FAIL;

	//이터레이터의 씬이 현재씬과 같으면 바꿀필요없다고 전해라아~
	if (find->second == _currentScene) return S_OK;

	//만약 바꾸려는 씬의 키값을 찾았다면 초기화. 성공적
	if (SUCCEEDED(find->second->init()))
	{
		//지금 씬이 있다면 그 씬을 해제하고
		if (_currentScene) _currentScene->release();
		//현재씬에 찾은 씬을 넣는다.
		_currentScene = find->second;

		return S_OK;
	}

	return E_FAIL;
}

//너네가 나중에 잘 개조해서 써봐밤
HRESULT sceneManager::changeScene(string sceneName, string loadingSceneName)
{
	//이터레이터에 찾고자하는 (씬) 키 값을 넣는다
	mapSceneIter find = _mSceneList.find(sceneName);

	//이터레이터가 맵의 끝까지 도달했다 == 맵 안에 그 씬이 존재하지 않는다 == 실패했다고 알려라
	if (find == _mSceneList.end()) return E_FAIL;

	//이터레이터의 씬이 현재씬과 같으면 바꿀필요없다고 전해라아~
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


