#ifndef MMATRIX_H
#define MMATRIX_H
#include "MDCore.h"
#include "MDTypedefs.h"
#include "MDVector3Helper.h"

class MDMatrix
{
public:
	MDMatrix();
	~MDMatrix();

	//FLOAT4x4 ��XMMATRIX�ɕϊ�
	XMMatrix Matrix4x4Conversion( Matrix4x4 matrix );
	//XMMATRIX��FLOAT4x4�ɕϊ�
	Matrix4x4 XMMatrixConversion( XMMatrix* xmMatrix );
	//�P�ʍs��
	Matrix4x4 Identity();
	//�t�s��
	Matrix4x4 Inverse( Matrix4x4 matrix );
	//����
	Matrix4x4 LookAtLH( Matrix4x4& out, const MDVector3* pEye, const MDVector3* pTarget, const MDVector3* pUp );
	//PerspectiveFovLH
	Matrix4x4 PerspectiveFovLH( Matrix4x4& out, FLOAT fovy, FLOAT aspect, FLOAT znear, FLOAT zfar );
	//�ړ�
	Matrix4x4 Translate( Matrix4x4& matrix, MDVector3 move );
	//��]
	Matrix4x4 Rotate( Matrix4x4& matrix, MDVector3 r );
	//�X�P�[�����O
	Matrix4x4 Scale( Matrix4x4& matrix, MDVector3 scale );
private:
	//�x�N�g���̊֐��Q
	MDVector3Helper vec;
};
#endif

