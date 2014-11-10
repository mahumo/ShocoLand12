#pragma once
#include "MDCore.h"
#include "MDTypedefs.h"
#include "MDMatrix.h"
class MDCamera
{
public:
	//	ビューポートを設定する
	void SetViewport( UINT width, UINT height );

	//	ビュー＆プロジェクション行列を作成
	void SetupMatrix( const MDVector3& eye, const MDVector3& at );

	//	ビュー行列を生成する
	Matrix4x4 LookAtLH( const MDVector3& eye, const MDVector3& at );
	Matrix4x4 PerspectiveFovLH( const FLOAT fovy, FLOAT aspect, FLOAT znear, FLOAT zfar );
	Matrix4x4 View(){ return view; }
	Matrix4x4 Projection(){ return proj; }

private:
	Matrix4x4	view;
	Matrix4x4	proj;
	D3D11_VIEWPORT			vp;

	//行列関数群
	MDMatrix helper;
};

