#include "MainWrapper.h"

// ���C�u������ǂݍ���
#ifdef _DEBUG
#pragma comment(lib,"DX11LibFrame_mdd.lib")
#else
#pragma comment(lib,"DX11LibFrame_md.lib")
#endif

#include "LibInclude.h"

// �V�[���ŏ��̃w�b�_���C���N���[�h
#include "GameScene.h"

MainWrapper::~MainWrapper()
{
	// COM���
	::CoUninitialize();
}

int MainWrapper::Initialize()
{
	// �������`�F�b�N
	// �����[�X���A�v���v���Z�X�Ŏ����폜
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

	// COM������
	if( FAILED( ::CoInitialize( 0 ) ) ){
		ErrMsg( L"COM���������s" );
		return FALSE;
	}

	// Unicode�̓��{��w��
	setlocale( LC_ALL, "JPN" );

	return TRUE;
}

void MainWrapper::DeviceInitialize( HWND hWnd )
{
	// ���̓f�o�C�X�쐬
	MDInput::Instance()->CreateInputDevice();
	MDInput::Instance()->CreateKeyboard( hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND );

	// �T�E���h�f�o�C�X�쐬
	MDSound::Instance()->CreateSoundDevice( hWnd );
}

void MainWrapper::Loop( MSG& msg )
{
	// �V�[���̐���
	while( msg.message != WM_QUIT ){
		if( PeekMessage( &msg, nullptr, 0U, 0U, PM_REMOVE ) ){
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		else{
			// �V�[�����s
			MDSceneManager::Instance()->Exe();
		}
	}
}

int MainWrapper::Run( HINSTANCE hInstance, WNDPROC lpfnWndProc )
{
	// Com�Ƃ��ׂ�������
	Initialize();

	// �E�B���h�E�̃p�����[�^��ݒ�
	// �E�B���h�E ��/����, �E�B���h�E�^�C�g��, �����I�ȃE�B���h�E���ʖ�, �X�N���[�����[�h
	WindowInfo info{ 800, 600, L"DirectX11Library", L"MyWindow", TRUE };
	CoreWindows coreWindow( info );

	// ���d�N���h�~
	if( FindWindow( info.className, info.titleName ) != nullptr )
	{
		ErrMsg( L"���d�N���o���܂���B" );
		return FALSE;
	}

	// �E�B���h�E���쐬
	if( FAILED( coreWindow.Create( hInstance, lpfnWndProc )))
		return FALSE;

	// DirectX�̏�����
	CoreD3D coreD3D;
	CoreD2D coreD2D;

	if( FAILED( coreD3D.Initialize( coreWindow.GetWindowHandle(), info ) ))
		return FALSE;
	if( FAILED( coreD2D.Initialize( coreD3D.devDXGI->device, coreD3D.devDXGI->swapChain ) ))
		return FALSE;

	// ����, �T�E���h�f�o�C�X������
	DeviceInitialize( coreWindow.GetWindowHandle() );

	//�V�[�����쐬
	MDSceneManager::Instance()->PushScene( new GameScene );

	// ���C�� ���b�Z�[�W ���[�v:
	MSG msg = { 0 };
	Loop( msg );

	// �������
	// �V�[���̉��
	MDSceneManager::Instance()->Release();

	// DirectX�̉��
	coreD3D.Release();

	// �E�B���h�E�̉��
	coreWindow.Release();

	return (int)msg.wParam;
}
