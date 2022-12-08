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

//	bool IsActive();
private:
	void updateAppear();	// 登場
	void updateLeft();		// 左に移動
	void updateRight();		// 右に移動
	void updateDown();		// 下に素早く移動

private:
	// フィールドの幅
	int m_lengthNum[20];
	int m_sideNum[10];

	// フィールドサイズ
	int m_MinoSize;

	// 今動いているミノの情報（0,1）
	int m_ActiveMinoNum[20][10];

	// フィールドの情報（0,1）
	int m_FieldNum[20][10];

	// テトリミノ番号
	int m_MinoNum;
	// テトリミノの十の位の番号
	int m_TensPlaceNum;
	// テトリミノの一の位の番号
	int m_OnesPlaceNum;

	// テトリミノが動いているとき
	bool m_Active;

	// テトリミノの落ちる速度
	int  m_fallFlame;


	bool m_IsRightPressBotton;
	bool m_IsLeftPressBotton;

	// update処理メンバ関数ポインタ
	void(Field:: *m_func)();
};

