#pragma once
#include <string>

//	FPS制御クラス
class MDFps
{
public:
	MDFps();
	~MDFps() = default;

	//	フレームのウェイト
	void WaitFrame();

	//	FPS値の取得
	// 参照渡しして死んだ
	const std::string GetFps();

	// 目標FPSの変更
	void SetFps( float fps );

private:
	float			fps;				// 目標FPS
	double		startTime;	//	開始時間
	double		frame;			//	1フレーム時間
	double		showFps;		//	表示用のFPS	
};
