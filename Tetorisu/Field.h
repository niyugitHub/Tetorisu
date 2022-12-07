#pragma once
class Field
{
public:
	Field();

	virtual ~Field();
	
	void init();

	void end();

	void update();

	void draw();
private:
	// フィールドの幅
	int m_lengthNum[20];
	int m_sideNum[10];

	// フィールドサイズ
	int m_MinoSize;

	// フィールドの情報（0,1）
	int m_FieldNum[20][10];

	// テトリミノ番号
	int m_MinoNum;

	// テトリミノが動いているとき
	bool m_Active;

	// テトリミノの落ちる速度
	int  m_fallFlame;
};

