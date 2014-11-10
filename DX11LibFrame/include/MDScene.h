#pragma once
#include "IScene.h"

enum  MDSceneStay : int
{
	//	メンバ関数の動き
	FUNC_PROCESS = 0,		//	関数実行中
	FUNC_END = 1,				//	関数実行終了
	FUNC_ERROR = -1,			// 関数異常終了

	//	シーンの実行状態
	PROCESS =0,					//	シーン実行中
	END=1,							//	シーン実行終了
};


class MDScene :public IScene
{
public:
	MDScene();
	virtual ~MDScene() = default;

	// シーンクラスを実行
	int Exe();

private:
	int (MDScene::*sceneFunc[3])();	//	関数ポインタ
	int funcNo;			//	現在実行している関数No
};

