#include "DxLib.h"
#include "SceneTitle.h"
#include "Field.h"
#include"game.h"

void SceneTitle::init()
{
//	m_RandColor = 0;
	m_isEnd = false;
	m_textSize = 50;
}

SceneBase* SceneTitle::update()
{
	if (CheckHitKey(KEY_INPUT_SPACE))
	{
		// Mainに切り替え
		return (new Field);
	}
	
	return this;
}

void SceneTitle::draw()
{
	SetFontSize(50);
	DrawString(150, 200, "テトリス", GetColor(0, 255, 0));
	DrawString(150, 450, "SPACEを押してスタート", GetColor(0, 255, 0));
}