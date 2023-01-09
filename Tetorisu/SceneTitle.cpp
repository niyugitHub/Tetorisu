#include "DxLib.h"
#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneSelection.h"
#include "SceneExplanation.h"
#include"game.h"

namespace
{
	// 拡大or縮小のとき10f止める
	constexpr int kWaitFlame = 25;
}

void SceneTitle::init()
{
//	m_RandColor = 0;
	m_handle = LoadGraph("data/enemy.png");
	m_Bhandle = LoadGraph("data/title.png");
	m_isEnd = false;
	m_textSize = 50;
	m_speed = 5.0f;
	m_Gravity = 0.3f;
	m_ExtRate = 2.0f;
	m_Expansion = 0.01f;
	m_StopFlame = 50;
}

SceneBase* SceneTitle::update()
{
	// 文字の移動
	
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitString2())
	{
		// Mainに切り替え
		return (new SceneSelection);
	
	}

	if (GetMouseInput() && MOUSE_INPUT_LEFT && HitString3())
	{
		// Mainに切り替え
		return (new SceneExplanation);
	}
	
	if (m_pos.x < Game::kScreenWidth / 2)
	{
		m_Gravity = 0.3f;
	}

	if (m_pos.x > Game::kScreenWidth - 350)
	{
		m_Gravity = -0.3f;
	}

	if (m_speed < -5.0f)
	{
		m_speed = -5.0f;
	}

	if (m_speed > 5.0f)
	{
		m_speed = 5.0f;
	}

	m_speed += m_Gravity;
	m_pos.x += m_speed;
	m_rot += 0.05f;

	if (m_ExtRate < 1.55f)
	{
		m_ExtRate = 1.55f;
		m_Expansion *= -1;
		m_StopFlame = 0;
	}

	if (m_ExtRate > 2.15f)
	{
		m_ExtRate = 2.15f;
		m_Expansion *= -1;
		m_StopFlame = 0;
	}

	if (m_StopFlame <= kWaitFlame)
	{
		m_StopFlame++;
	}

	if (m_StopFlame >= kWaitFlame)
	{
		m_ExtRate -= m_Expansion;
	}

	return this;
}

void SceneTitle::draw()
{
	DrawGraph(0, 0, m_Bhandle, true);
	SetFontSize(50);
	DrawString(150, 200, "ウイルスバスターズ！", GetColor(0, 255, 0));
	DrawString(150, 450, "ゲームスタート", GetColor(0, 255, 0));
	DrawString(150, 550, "あそびかた", GetColor(0, 255, 0));

	if (HitString2())
	{
		DrawString(150, 450, "ゲームスタート", GetColor(255, 255, 255));
	}
	if (HitString3())
	{
		DrawString(150, 550, "あそびかた", GetColor(255, 255, 255));
	}

//	if()
	DrawRotaGraph(m_pos.x, m_pos.y, m_ExtRate, m_rot,
		m_handle, true, false);
	//DrawBox(static_cast<int>(Mouse::getPos().x), static_cast<int>(Mouse::getPos().y),
	//	Mause::kMouseSize, int y2,
	//	unsigned int Color, int FillFlag);



#if false
	// randcolorの値の表示
	DrawFormatString(0 , 0, GetColor(255,255,255),"%d", m_RandColor);
#endif
}

bool SceneTitle::HitString2()
{
	if (Mouse::getPos().x > 150 &&
		Mouse::getPos().x < 150 + m_textSize * 7)
	{
		if (Mouse::getPos().y > 450 &&
			Mouse::getPos().y < 500)
		{
			return true;
		}
	}
	return false;
}
bool SceneTitle::HitString3()
{
	if (Mouse::getPos().x > 150 &&
		Mouse::getPos().x < 150 + m_textSize * 5)
	{
		if (Mouse::getPos().y > 550 &&
			Mouse::getPos().y < 600)
		{
			return true;
		}
	}
	return false;
}
