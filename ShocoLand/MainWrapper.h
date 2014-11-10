#pragma once
//#include <Windows.h>

class MainWrapper
{
public:
	MainWrapper() = default;
	~MainWrapper();

	int Initialize();
	void DeviceInitialize( HWND hWnd );
	void Loop( MSG& msg );

	// メイン関数内は、本当に実行するだけにしたい!
	int Run( HINSTANCE hInstance, WNDPROC lpfnWndProc );
};
