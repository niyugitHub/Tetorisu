#pragma once
#include "SceneBase.h"
#include "Vec2.h"
#include "game.h"

class SceneTitle : public SceneBase
{
public:
//	constexpr int kMouseSize = 134;

public:
	SceneTitle()
	{
		m_handle = -1;
		m_Bhandle = -1;
		m_textSize = 0;
		m_pos.x = Game::kScreenWidth / 2;
		m_pos.y = 300;
		m_rot = 0;
		m_isEnd = false;
	}
	virtual ~SceneTitle() {}


	virtual void init()override;
	virtual void end() override {}

	virtual SceneBase* update()override;
	virtual void draw()override;

	virtual bool isEnd() { return m_isEnd; }

	// マウスと文字が当たった時
	bool HitString2();
	bool HitString3();
private:
	// 画像ハンドル
	int m_handle;
	int m_Bhandle;
	
	Vec2 m_pos;

	float m_speed;
	float m_Gravity;

	// 回転
	float m_rot;

	float m_ExtRate;
	float m_Expansion;

	int m_StopFlame;

	// テキストのサイズ
	int m_textSize;

	bool m_isEnd;
};