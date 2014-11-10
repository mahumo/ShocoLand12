#ifndef	MDUNCOPYABLE_H
#define	MDUNCOPYABLE_H

//	�R�s�[�s�\��{�N���X
//	�R�s�[�R���X�g���N�^�A�R�s�[������Z�q��private�����鎖��
//	���̃N���X���p�������N���X�̓R�s�[�s�\�N���X�ƂȂ�B
class MDUncopyable
{
protected:
	MDUncopyable() = default;
	virtual ~MDUncopyable() = default;
private:
	MDUncopyable( const MDUncopyable& ) = delete;
	MDUncopyable( MDUncopyable&& ) = delete;
	MDUncopyable& operator=(const MDUncopyable&) = delete;
	MDUncopyable& operator=(MDUncopyable&&) = delete;
};
#endif
