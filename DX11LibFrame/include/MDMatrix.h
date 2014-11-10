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

	//FLOAT4x4 をXMMATRIXに変換
	XMMatrix Matrix4x4Conversion( Matrix4x4 matrix );
	//XMMATRIXをFLOAT4x4に変換
	Matrix4x4 XMMatrixConversion( XMMatrix* xmMatrix );
	//単位行列
	Matrix4x4 Identity();
	//逆行列
	Matrix4x4 Inverse( Matrix4x4 matrix );
	//注目
	Matrix4x4 LookAtLH( Matrix4x4& out, const MDVector3* pEye, const MDVector3* pTarget, const MDVector3* pUp );
	//PerspectiveFovLH
	Matrix4x4 PerspectiveFovLH( Matrix4x4& out, FLOAT fovy, FLOAT aspect, FLOAT znear, FLOAT zfar );
	//移動
	Matrix4x4 Translate( Matrix4x4& matrix, MDVector3 move );
	//回転
	Matrix4x4 Rotate( Matrix4x4& matrix, MDVector3 r );
	//スケーリング
	Matrix4x4 Scale( Matrix4x4& matrix, MDVector3 scale );
private:
	//ベクトルの関数群
	MDVector3Helper vec;
};
#endif

