#pragma once
#include "LibInclude.h"

class MDTextureLoadWrapper : private MDUncopyable
	
{
public:
	MDTextureLoadWrapper();
	~MDTextureLoadWrapper();


	// 2Dテクスチャ読み込むライブラリ
	// でも、既に読み込みは出来てるので、3Dのみの利用でよろしく
	//TexMetadata metadata;
	// DirectX::ScratchImage image;
	//DirectX::LoadFromWICFile( L"filename", 0 , ?, 最終的なデータの出力先 );
	// DirectX11::LoadFromDDSFile
	// DirectX11::LoadFromTGAFile


	// シェーダーリソースビューを作成
	//DirectX::CreateShaderResourceView( "デバイス", image.GetImages(), image.GetImageCount(), metadata, "最終的なデータの出力先" );

	// シェーダーリソースビューを作成
	void CreateShaderResourceViewDDS( LPCTSTR filename, ID3D11ShaderResourceView** resource );
	void CreateShaderResourceViewWIC( LPCTSTR filename, ID3D11ShaderResourceView** resource );
};

