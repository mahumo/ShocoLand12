#ifndef MDTEMPLATE_H
#define MDTEMPLATE_H

namespace MD
{
	// �z��̗v�f����Ԃ��e���v���[�g( �Œ蒷�z���p )
	// constexpr �͎g���Ȃ�
	// �x���o��
	template<typename TYPE, std::size_t N>
	inline 
	std::size_t count_of( const TYPE( & )[N] ){
		return N;
	}
}

#endif

