#pragma once
#include "MDCore.h"
#include "MDTypedefs.h"
#include "MDMatrix.h"
class MDCamera
{
public:
	//	�r���[�|�[�g��ݒ肷��
	void SetViewport( UINT width, UINT height );

	//	�r���[���v���W�F�N�V�����s����쐬
	void SetupMatrix( const MDVector3& eye, const MDVector3& at );

	//	�r���[�s��𐶐�����
	Matrix4x4 LookAtLH( const MDVector3& eye, const MDVector3& at );
	Matrix4x4 PerspectiveFovLH( const FLOAT fovy, FLOAT aspect, FLOAT znear, FLOAT zfar );
	Matrix4x4 View(){ return view; }
	Matrix4x4 Projection(){ return proj; }

private:
	Matrix4x4	view;
	Matrix4x4	proj;
	D3D11_VIEWPORT			vp;

	//�s��֐��Q
	MDMatrix helper;
};

