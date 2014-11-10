#ifndef	MDUNCOPYABLE_H
#define	MDUNCOPYABLE_H

//	コピー不能基本クラス
//	コピーコンストラクタ、コピー代入演算子をprivate化する事で
//	このクラスを継承したクラスはコピー不能クラスとなる。
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
