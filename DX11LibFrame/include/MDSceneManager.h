#pragma once
#include "MDUncopyable.h"
#include <stack>
#include <memory>
class MDScene;

class MDSceneManager :private MDUncopyable
	
{
public:
	MDSceneManager();
	~MDSceneManager();

	static MDSceneManager* Instance();

	//	スタックに積まれているシーンを実行
	void Exe();

	//	スタックにシーンを積む
	void PushScene( MDScene* ptr );

	//	カレントシーン実行後にシーンを変える
	void ReserveNextScene( MDScene* ptr );

	//	スタックに積まれている全シーンを解放
	void Release();


private:
	MDScene* currentScene;	//	現在実行しているシーン
	MDScene* nextScene;		//	終了後積む事が予約されたシーン

	std::stack<MDScene*> sceneStack;				//	シーンを格納するスタック
};

inline MDSceneManager* MDSceneManager::Instance()
{
	static auto instance = std::make_unique<MDSceneManager>();
	return instance.get();
}

