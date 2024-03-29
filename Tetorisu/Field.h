#pragma once

#include "SceneBase.h"

class Mino;

class Field : public SceneBase
{
private:
	static constexpr int Column = 4;
	static constexpr int Side = 4;
public:
	Field();

	virtual ~Field();
	
	virtual void init()override;

	virtual void end()override;

	virtual SceneBase* update()override;

	virtual void draw()override;

	bool IsActive();

	bool IsLeft();

	bool IsRight();

	void rotationMino();

	void MoveMino();

	void FallMino();

	// 落下位置の予測
	void PredictionMino();

	// ホールド
	void MinoHold();

	bool IsPossibleFall();

	bool IsPredictionFall();

	bool IsPossibleMino();

	//bool columnExist();
private:
	void updateAppear();	// 登場
	void updateLeft();		// 左に移動
	void updateRight();		// 右に移動

private:
	// フィールドサイズ
	int m_MinoSize;

	// 今動いているミノのフィールド情報（0,1）
	int m_ActiveFieldNum[23][10];

	// 今動いているミノの情報（0,1）
	int m_ActiveMinoNum[Column][Side];

	// 今動いているミノの情報（0,1）
	int m_VirtualActiveMinoNum[Column][Side];

	// ホールドしたミノの情報（0,1）
	int m_HoldMinoNum[Column][Side];

	// 次に動くミノの情報（0,1）
	int m_NextActiveMinoNum[Column][Side];

	// フィールドの情報（0,1）
	int m_FieldNum[20][10];

	// ミノが消えた時の置き換え
	int m_VirtualFieldNum[20][10];

	// 落下位置の予測
	int m_PredictionMinoFieldNum[23][10];

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

	// 落下位置の値
	int m_PredictionTenNum;
	int m_PredictionOneNum;

	// 何列消えたか
	int m_DeleteNum;
	// スコア
	int m_Score;
	int m_TotalScore;

	bool m_IsRightPressBotton;
	bool m_IsLeftPressBotton;
	bool m_IsUpPressBotton;
	bool m_IsZPressBotton;
	bool m_IsXPressBotton;

	// 横一列のミノの数
	int m_ColumnMinoNum;

	// 横一列にすべてミノが存在するかどうか
	bool m_ExistColumnMino;

	// アクティブミノの下にミノが存在するとき
	bool m_BottomMino;

	// 最初に出されるミノのとき
	bool m_FirstMino;

	// 最初にホールドしたとき
	bool m_FirstHold;

	// ホールドしたとき
	bool m_Hold;

	// 何列目のミノがそろったか
	int m_ExistMinoNum;

	// 何回目の回転か
	bool m_rota1;
	bool m_rota2;
	bool m_rota3;
	bool m_rota4;

	bool m_MinusMino;

	bool m_End;

	// update処理メンバ関数ポインタ
	void(Field:: *m_func)();

	Mino*mino;
};

