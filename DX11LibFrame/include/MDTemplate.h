#ifndef MDTEMPLATE_H
#define MDTEMPLATE_H

namespace MD
{
	// 配列の要素数を返すテンプレート( 固定長配列専用 )
	// constexpr は使えない
	// 警告出る
	template<typename TYPE, std::size_t N>
	inline 
	std::size_t count_of( const TYPE( & )[N] ){
		return N;
	}
}

#endif

