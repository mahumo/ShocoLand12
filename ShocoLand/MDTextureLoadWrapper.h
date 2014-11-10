#pragma once
#include "LibInclude.h"

class MDTextureLoadWrapper : private MDUncopyable
	
{
public:
	MDTextureLoadWrapper();
	~MDTextureLoadWrapper();


	// 2D�e�N�X�`���ǂݍ��ރ��C�u����
	// �ł��A���ɓǂݍ��݂͏o���Ă�̂ŁA3D�݂̗̂��p�ł�낵��
	//TexMetadata metadata;
	// DirectX::ScratchImage image;
	//DirectX::LoadFromWICFile( L"filename", 0 , ?, �ŏI�I�ȃf�[�^�̏o�͐� );
	// DirectX11::LoadFromDDSFile
	// DirectX11::LoadFromTGAFile


	// �V�F�[�_�[���\�[�X�r���[���쐬
	//DirectX::CreateShaderResourceView( "�f�o�C�X", image.GetImages(), image.GetImageCount(), metadata, "�ŏI�I�ȃf�[�^�̏o�͐�" );

	// �V�F�[�_�[���\�[�X�r���[���쐬
	void CreateShaderResourceViewDDS( LPCTSTR filename, ID3D11ShaderResourceView** resource );
	void CreateShaderResourceViewWIC( LPCTSTR filename, ID3D11ShaderResourceView** resource );
};

