#include "MDTextureLoadWrapper.h"


MDTextureLoadWrapper::MDTextureLoadWrapper()
{
}


MDTextureLoadWrapper::~MDTextureLoadWrapper()
{
}

// シェーダーリソースビューを作成
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
