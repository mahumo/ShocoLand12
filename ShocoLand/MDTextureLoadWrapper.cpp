#include "MDTextureLoadWrapper.h"


MDTextureLoadWrapper::MDTextureLoadWrapper()
{
}


MDTextureLoadWrapper::~MDTextureLoadWrapper()
{
}

// �V�F�[�_�[���\�[�X�r���[���쐬
void MDTextureLoadWrapper::CreateShaderResourceViewDDS( LPCTSTR filename, ID3D11ShaderResourceView** resource )
{
	DirectX::TexMetadata meta;
	DirectX::ScratchImage image;
	DirectX::LoadFromDDSFile( filename, 0, &meta , image );
	DirectX::CreateShaderResourceView( CoreD3D::GetDevice(), image.GetImages(), image.GetImageCount(), meta, resource );
	image.Release();
}

void MDTextureLoadWrapper::CreateShaderResourceViewWIC( LPCTSTR filename, ID3D11ShaderResourceView** resource )
{
	DirectX::TexMetadata meta;
	DirectX::ScratchImage image;
	DirectX::LoadFromWICFile( filename, 0, &meta, image );		
	DirectX::CreateShaderResourceView( CoreD3D::GetDevice(), image.GetImages(), image.GetImageCount(), meta, resource );
	image.Release();
}
