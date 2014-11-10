#pragma once

#include <windows.h>

//	Window����񋓂����\����
struct WindowInfo
{
public:
	int windowWidth;		//	�E�B���h�E�̉���
	int windowHeight;		//	�E�B���h�E�̏c��
	LPWSTR titleName;		// �Q�[���^�C�g��
	LPWSTR className;	//	�N���X��
	BOOL windowMode;	//	�E�B���h�E���[�h
};

class CoreWindows
{
public:
	CoreWindows( const WindowInfo& info );

	//	�E�B���h�E�̐�������
	HRESULT Create( HINSTANCE hInstance, WNDPROC lpfnWndProc );

	//	�E�B���h�E�n���h�����擾
	HWND GetWindowHandle(){ return hWnd; }

	//	�E�B���h�E�̉������
	void Release();

private:
	HRESULT WindowRegister( HINSTANCE hInstance, WNDPROC lpfnWndProc );
	HRESULT WindowCreate( HINSTANCE hInstance );

private:
	HWND hWnd;			//	�E�B���h�E�n���h��
	WindowInfo windowInfo;	// �E�B���h�E�\����
	HINSTANCE	hInst;				//	�C���X�^���X
};
