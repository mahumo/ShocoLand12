#pragma once
#include <string>

//	FPS����N���X
class MDFps
{
public:
	MDFps();
	~MDFps() = default;

	//	�t���[���̃E�F�C�g
	void WaitFrame();

	//	FPS�l�̎擾
	// �Q�Ɠn�����Ď���
	const std::string GetFps();

	// �ڕWFPS�̕ύX
	void SetFps( float fps );

private:
	float			fps;				// �ڕWFPS
	double		startTime;	//	�J�n����
	double		frame;			//	1�t���[������
	double		showFps;		//	�\���p��FPS	
};
