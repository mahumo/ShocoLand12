#pragma once

enum TileLayerType;
struct TiledMapEditor;
class TileIDMap;
class TiledMapObjManager;
class TiledObjFactory
{
public:
	TiledObjFactory() = default;
	~TiledObjFactory() = default;

	void Create( const TileLayerType& layerType, const TiledMapEditor& editor, TileIDMap& idMap, TiledMapObjManager& manager );
};

