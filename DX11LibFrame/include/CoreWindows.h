#pragma once

#include <windows.h>

//	Window情報を列挙した構造体
struct WindowInfo
{
public:
	int windowWidth;		//	ウィンドウの横幅
	int windowHeight;		//	ウィンドウの縦幅
	LPWSTR titleName;		// ゲームタイトル
	LPWSTR className;	//	クラス名
	BOOL windowMode;	//	ウィンドウモード
};

class CoreWindows
{
public:
	CoreWindows( const WindowInfo& info );

	//	ウィンドウの生成処理
	HRESULT Create( HINSTANCE hInstance, WNDPROC lpfnWndProc );

	//	ウィンドウハンドルを取得
	HWND GetWindowHandle(){ return hWnd; }

	//	ウィンドウの解放処理
	void Release();

private:
	HRESULT WindowRegister( HINSTANCE hInstance, WNDPROC lpfnWndProc );
	HRESULT WindowCreate( HINSTANCE hInstance );

private:
	HWND hWnd;			//	ウィンドウハンドル
	WindowInfo windowInfo;	// ウィンドウ構造体
	HINSTANCE	hInst;				//	インスタンス
};
