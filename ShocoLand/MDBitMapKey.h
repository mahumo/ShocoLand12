#pragma once
#include "LibInclude.h"

// texture‚ğŠÇ—‚·‚éƒNƒ‰ƒX
class MDBitMapKey : private MDUncopyable
{
public:
	MDBitMapKey() = default;
	~MDBitMapKey() = default;


	static std::unique_ptr<MDBitMapKey>&  Instance();
	bool Add( const std::string& path, const std::string& key );
	bool ChackKey( const std::string& key );
	std::unique_ptr<MD2DBitmap>& GetValue( const std::string& key );

private:
	template <typename T, typename U>
	using UnMapPtr = std::unordered_map<T, std::unique_ptr<U>>;

	UnMapPtr<std::string, MD2DBitmap> texNameNumber = {};
};

inline
std::unique_ptr<MDBitMapKey>& MDBitMapKey::Instance()
{
	static auto instance = std::make_unique<MDBitMapKey>();
	return instance;
}

