#pragma once
#define DIRECTINPUT_VERSION 0x0800			// ���łɃC���N���[�h����Ă�ƌ�����BWindow.h �Œ�`�ς�?

#include "MDCore.h"
#include "MDUncopyable.h"
#include <memory>

// DirectInput�֘A�C���N���[�h����------
#include <dinput.h>
#pragma comment( lib, "dxguid.lib")						//  DirectInput �n�Ŏg���̂���?
#pragma comment(lib, "dinput8.lib")						// DirectInput lib


//------------------------------------
//�L�[�{�[�h�̗�
//dinput.h��#define���ꂽ���̂�
//�킩��₷��������
//------------------------------------
enum KEYS{
	KEYS_ESCAPE = DIK_ESCAPE,
	KEYS_KEY1 = DIK_1,
	KEYS_KEY2 = DIK_2,
	KEYS_KEY3 = DIK_3,
	KEYS_KEY4 = DIK_4,
	KEYS_KEY5 = DIK_5,
	KEYS_KEY6 = DIK_6,
	KEYS_KEY7 = DIK_7,
	KEYS_KEY8 = DIK_8,
	KEYS_KEY9 = DIK_9,
	KEYS_KEY0 = DIK_0,
	KEYS_MINUS = DIK_MINUS,
	KEYS_EQUALS = DIK_EQUALS,
	KEYS_BACK = DIK_BACK,
	KEYS_TAB = DIK_TAB,
	KEYS_Q = DIK_Q,
	KEYS_W = DIK_W,
	KEYS_E = DIK_E,
	KEYS_R = DIK_R,
	KEYS_T = DIK_T,
	KEYS_Y = DIK_Y,
	KEYS_U = DIK_U,
	KEYS_I = DIK_I,
	KEYS_O = DIK_O,
	KEYS_P = DIK_P,
	KEYS_LBRACKET = DIK_LBRACKET,
	KEYS_RBRACKET = DIK_RBRACKET,
	KEYS_ENTER = DIK_RETURN,
	KEYS_LCONTROL = DIK_LCONTROL,
	KEYS_A = DIK_A,
	KEYS_S = DIK_S,
	KEYS_D = DIK_D,
	KEYS_F = DIK_F,
	KEYS_G = DIK_G,
	KEYS_H = DIK_H,
	KEYS_J = DIK_J,
	KEYS_K = DIK_K,
	KEYS_L = DIK_L,
	KEYS_SEMICOLON = DIK_SEMICOLON,
	KEYS_APOSTROPHE = DIK_APOSTROPHE,
	KEYS_GRAVE = DIK_GRAVE,
	KEYS_LSHIFT = DIK_LSHIFT,
	KEYS_BACKSLASH = DIK_BACKSLASH,
	KEYS_Z = DIK_Z,
	KEYS_X = DIK_X,
	KEYS_C = DIK_C,
	KEYS_V = DIK_V,
	KEYS_B = DIK_B,
	KEYS_N = DIK_N,
	KEYS_M = DIK_M,
	KEYS_COMMA = DIK_COMMA,
	KEYS_PERIOD = DIK_PERIOD,
	KEYS_SLASH = DIK_SLASH,
	KEYS_RSHIFT = DIK_RSHIFT,
	KEYS_MULTIPLY = DIK_MULTIPLY,
	KEYS_LMENU = DIK_LMENU,
	KEYS_SPACE = DIK_SPACE,
	KEYS_CAPITAL = DIK_CAPITAL,
	KEYS_F1 = DIK_F1,
	KEYS_F2 = DIK_F2,
	KEYS_F3 = DIK_F3,
	KEYS_F4 = DIK_F4,
	KEYS_F5 = DIK_F5,
	KEYS_F6 = DIK_F6,
	KEYS_F7 = DIK_F7,
	KEYS_F8 = DIK_F8,
	KEYS_F9 = DIK_F9,
	KEYS_F10 = DIK_F10,
	KEYS_NUMLOCK = DIK_NUMLOCK,
	KEYS_SCROLL = DIK_SCROLL,
	KEYS_NUMPAD7 = DIK_NUMPAD7,
	KEYS_NUMPAD8 = DIK_NUMPAD8,
	KEYS_NUMPAD9 = DIK_NUMPAD9,
	KEYS_SUBTRACT = DIK_SUBTRACT,
	KEYS_NUMPAD4 = DIK_NUMPAD4,
	KEYS_NUMPAD5 = DIK_NUMPAD5,
	KEYS_NUMPAD6 = DIK_NUMPAD6,
	KEYS_ADD = DIK_ADD,
	KEYS_NUMPAD1 = DIK_NUMPAD1,
	KEYS_NUMPAD2 = DIK_NUMPAD2,
	KEYS_NUMPAD3 = DIK_NUMPAD3,
	KEYS_NUMPAD0 = DIK_NUMPAD0,
	KEYS_DECIMAL = DIK_DECIMAL,
	KEYS_OEM_102 = DIK_OEM_102,
	KEYS_F11 = DIK_F11,
	KEYS_F12 = DIK_F12,
	KEYS_F13 = DIK_F13,
	KEYS_F14 = DIK_F14,
	KEYS_F15 = DIK_F15,
	KEYS_KANA = DIK_KANA,
	KEYS_ABNT_C1 = DIK_ABNT_C1,
	KEYS_CONVERT = DIK_CONVERT,
	KEYS_NOCONVERT = DIK_NOCONVERT,
	KEYS_YEN = DIK_YEN,
	KEYS_ABNT_C2 = DIK_ABNT_C2,
	KEYS_NUMPADEQUALS = DIK_NUMPADEQUALS,
	KEYS_PREVTRACK = DIK_PREVTRACK,
	KEYS_AT = DIK_AT,
	KEYS_COLON = DIK_COLON,
	KEYS_UNDERLINE = DIK_UNDERLINE,
	KEYS_KANJI = DIK_KANJI,
	KEYS_STOP = DIK_STOP,
	KEYS_AX = DIK_AX,
	KEYS_UNLABELED = DIK_UNLABELED,
	KEYS_NEXTTRACK = DIK_NEXTTRACK,
	KEYS_NUMPADENTER = DIK_NUMPADENTER,
	KEYS_RCONTROL = DIK_RCONTROL,
	KEYS_MUTE = DIK_MUTE,
	KEYS_CALCULATOR = DIK_CALCULATOR,
	KEYS_PLAYPAUSE = DIK_PLAYPAUSE,
	KEYS_MEDIASTOP = DIK_MEDIASTOP,
	KEYS_VOLUMEDOWN = DIK_VOLUMEDOWN,
	KEYS_VOLUMEUP = DIK_VOLUMEUP,
	KEYS_WEBHOME = DIK_WEBHOME,
	KEYS_NUMPADCOMMA = DIK_NUMPADCOMMA,
	KEYS_DIVIDE = DIK_DIVIDE,
	KEYS_SYSRQ = DIK_SYSRQ,
	KEYS_RMENU = DIK_RMENU,
	KEYS_PAUSE = DIK_PAUSE,
	KEYS_HOME = DIK_HOME,
	KEYS_UP = DIK_UP,
	KEYS_PRIOR = DIK_PRIOR,
	KEYS_LEFT = DIK_LEFT,
	KEYS_RIGHT = DIK_RIGHT,
	KEYS_END = DIK_END,
	KEYS_DOWN = DIK_DOWN,
	KEYS_NEXT = DIK_NEXT,
	KEYS_INSERT = DIK_INSERT,
	KEYS_DELETE = DIK_DELETE,
	KEYS_LWIN = DIK_LWIN,
	KEYS_RWIN = DIK_RWIN,
	KEYS_APPS = DIK_APPS,
	KEYS_POWER = DIK_POWER,
	KEYS_SLEEP = DIK_SLEEP,
	KEYS_WAKE = DIK_WAKE,
	KEYS_WEBSEARCH = DIK_WEBSEARCH,
	KEYS_WEBFAVORITES = DIK_WEBFAVORITES,
	KEYS_WEBREFRESH = DIK_WEBREFRESH,
	KEYS_WEBSTOP = DIK_WEBSTOP,
	KEYS_WEBFORWARD = DIK_WEBFORWARD,
	KEYS_WEBBACK = DIK_WEBBACK,
	KEYS_MYCOMPUTER = DIK_MYCOMPUTER,
	KEYS_MAIL = DIK_MAIL,
	KEYS_MEDIASELECT = DIK_MEDIASELECT

};
//------------------------------------
//�L�[�̏��
// DOWN �L�[�������Ɖ�����Ă���
// UP	�L�[���S��������Ă��Ȃ�
// RELEASE	������Ă����L�[�����ꂽ
// PUSH		���A�L�[�������ꂽ
//------------------------------------
enum INPUT_STATE{
	DOWN,
	UP,
	RELEASE,
	PUSH,
};

enum MOUSEBOTTUN{
	LEFTBOTTUN = 0,
	RIGHTBOTTUN = 1,
	CENTERBOTTUN = 2,
};

class MDInput : private MDUncopyable
{
public:
	MDInput();
	~MDInput() = default;

	static MDInput*	Instance();

	LPDIRECTINPUT8* GetInputDevice();

	//-----------------------------
	//���̓f�o�C�X�̍쐬
	//-----------------------------
	void		CreateInputDevice();

	//-----------------------------
	//�L�[�{�[�h�̏�����
	//-----------------------------
	void		CreateKeyboard( HWND hWnd ,DWORD level);

	//-----------------------------
	//�}�E�X�̏�����
	//----------------------------
	void		CreateMouse( HWND hWnd, DWORD level );

	//-----------------------------
	//�L�[�̏�Ԃ�Ԃ�
	// KEYS key		�L�[
	//-----------------------------
	INPUT_STATE	GetKeyState( KEYS key );

	//-----------------------------------
	//�}�E�X�̏�Ԃ�Ԃ�
	// MOUSEBOTTUN		�N���b�N������
	//-----------------------------------
	INPUT_STATE GetMouseState( MOUSEBOTTUN mouse );

private:
	//-------------------------------------------
	//�L�[���̍X�V
	//KEYS key  �X�V����L�[
	//char keyState[]	���ׂẴL�[�̏���
	//						�ꎞ�I�ɓ����z��
	//-------------------------------------------
	void		KeyUpdate( KEYS key, char keyState[] );

	//-------------------------------------------------------------------
	//�}�E�X�̏����X�V
	//MOUSEBOTTUN mouse			�X�V�������}�E�X
	//DIMOUSESTATE mouseState	�}�E�X��
	//-------------------------------------------------------------------
	void		MouseUpdate( MOUSEBOTTUN mouse, DIMOUSESTATE2 mouseState );

private:
	//�L�[����
	ComPtr<IDirectInput8W>				input;				//DirectInput�I�u�W�F�N�g LPDIRECTINPUT
	ComPtr<IDirectInputDevice8W>	keyDevice;		//�L�[�{�[�h�f�o�C�X LPDIRECTINPUTDEVICE8
	ComPtr<IDirectInputDevice8W>	mouseDevice;	//�}�E�X�f�o�C�X LPDIRECTINPUTDEVICE8
	int						keyCount[256];	//������Ă���L�[�̃J�E���g
	int						mouseCount[3];	//������Ă���}�E�X�̏ꏊ�̃J�E���g
};

inline MDInput* MDInput::Instance() {
	static auto instance = std::make_unique<MDInput>();	// new����v��Ȃ�
	return instance.get();
}
