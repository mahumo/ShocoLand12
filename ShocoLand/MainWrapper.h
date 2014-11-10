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

	// ���C���֐����́A�{���Ɏ��s���邾���ɂ�����!
	int Run( HINSTANCE hInstance, WNDPROC lpfnWndProc );
};
