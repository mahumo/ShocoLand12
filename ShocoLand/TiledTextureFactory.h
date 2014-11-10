#pragma once

class TileIDMap;
struct TiledTexture;
class TiledTextureFactory
{
public:
	TiledTextureFactory();
	~TiledTextureFactory() = default;

	void Create( TiledTexture& tiledTexture, TileIDMap& idMap);
	void InitializeID();

private:
	int id;
};

