#include "MainWrapper.h"

// ライブラリを読み込む
#ifdef _DEBUG
#pragma comment(lib,"DX11LibFrame_mdd.lib")
#else
#pragma comment(lib,"DX11LibFrame_md.lib")
#endif

#include "LibInclude.h"

// シーン最初のヘッダをインクルード
#include "GameScene.h"

MainWrapper::~MainWrapper()
{
	// COM解放
	::CoUninitialize();
}

int MainWrapper::Initialize()
{
	// メモリチェック
	// リリース時、プリプロセスで自動削除
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	// COM初期化
	if( FAILED( ::CoInitialize( 0 ) ) ){
		ErrMsg( L"COM初期化失敗" );
		return FALSE;
	}

	// Unicodeの日本語指定
	setlocale( LC_ALL, "JPN" );

	return TRUE;
}

void MainWrapper::DeviceInitialize( HWND hWnd )
{
	// 入力デバイス作成
	MDInput::Instance()->CreateInputDevice();
	MDInput::Instance()->CreateKeyboard( hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND );

	// サウンドデバイス作成
	MDSound::Instance()->CreateSoundDevice( hWnd );
}

void MainWrapper::Loop( MSG& msg )
{
	// シーンの生成
	while( msg.message != WM_QUIT ){
		if( PeekMessage( &msg, nullptr, 0U, 0U, PM_REMOVE ) ){
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else{
			// シーン実行
			MDSceneManager::Instance()->Exe();
		}
	}
}

int MainWrapper::Run( HINSTANCE hInstance, WNDPROC lpfnWndProc )
{
	// Comとか細い初期化
	Initialize();

	// ウィンドウのパラメータを設定
	// ウィンドウ 幅/高さ, ウィンドウタイトル, 内部的なウィンドウ識別名, スクリーンモード
	WindowInfo info{ 800, 600, L"DirectX11Library", L"MyWindow", TRUE };
	CoreWindows coreWindow( info );

	// 多重起動防止
	if( FindWindow( info.className, info.titleName ) != nullptr )
	{
		ErrMsg( L"多重起動出来ません。" );
		return FALSE;
	}

	// ウィンドウを作成
	if( FAILED( coreWindow.Create( hInstance, lpfnWndProc )))
		return FALSE;

	// DirectXの初期化
	CoreD3D coreD3D;
	CoreD2D coreD2D;

	if( FAILED( coreD3D.Initialize( coreWindow.GetWindowHandle(), info ) ))
		return FALSE;
	if( FAILED( coreD2D.Initialize( coreD3D.devDXGI->device, coreD3D.devDXGI->swapChain ) ))
		return FALSE;

	// 入力, サウンドデバイス初期化
	DeviceInitialize( coreWindow.GetWindowHandle() );

	//シーンを作成
	MDSceneManager::Instance()->PushScene( new GameScene );

	// メイン メッセージ ループ:
	MSG msg = { 0 };
	Loop( msg );

	// 解放処理
	// シーンの解放
	MDSceneManager::Instance()->Release();

	// DirectXの解放
	coreD3D.Release();

	// ウィンドウの解放
	coreWindow.Release();

	return (int)msg.wParam;
}
