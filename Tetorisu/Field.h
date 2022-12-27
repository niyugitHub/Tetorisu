#pragma once

class Mino;

class Field
{
private:
	static constexpr int Column = 4;
	static constexpr int Side = 4;
public:
	Field();

	virtual ~Field();
	
	void init();

	void end();

	void update();

	void draw();

	bool IsActive();

	bool IsLeft();

	bool IsRight();
	//bool columnExist();
private:
	void updateAppear();	// 登場
	void updateLeft();		// 左に移動
	void updateRight();		// 右に移動

private:
	// フィールドサイズ
	int m_MinoSize;

	// 今動いているミノのフィールド情報（0,1）
	int m_ActiveFieldNum[20][10];

	// 今動いているミノの情報（0,1）
	int m_ActiveMinoNum[Column][Side];

	// フィールドの情報（0,1）
	int m_FieldNum[20][10];

	// ミノが消えた時の置き換え
	int m_VirtualFieldNum[20][10];

	// テトリミノ番号
	int m_MinoNum;
	// テトリミノの十の位の番号
	int m_TensPlaceNum;
	// テトリミノの一の位の番号
	int m_OnesPlaceNum;

	// テトリミノの落ちる速度
	int m_fallFlame;
	
	// テトリミノが切り替わる時間
	int m_SwitchMinoFlame;

	bool m_IsRightPressBotton;
	bool m_IsLeftPressBotton;

	// 横一列のミノの数
	int m_ColumnMinoNum;

	// 横一列にすべてミノが存在するかどうか
	bool m_ExistColumnMino;

	// 最初に出されるミノのとき
	bool m_FirstMino;

	// 何列目のミノがそろったか
	int m_ExistMinoNum;

	// update処理メンバ関数ポインタ
	void(Field:: *m_func)();

	Mino*mino;
};

