#include "Field.h"
#include "SceneBase.h"
#include "Mino.h"
#include<Dxlib.h>

namespace
{
	constexpr int kLengthNum = 20;
	constexpr int kSideNum = 10;
}

Field::Field() : 
	m_MinoSize(20),
	m_MinoNum(0),
	m_fallFlame(0),
	m_TensPlaceNum(0),	// 十の位
	m_OnesPlaceNum(0),	// 一の位
	m_SwitchMinoFlame(60),
	m_PredictionTenNum(0),
	m_PredictionOneNum(0),
	m_DeleteNum(0),
	m_Score(0),
	m_TotalScore(0),
	m_IsRightPressBotton(false),
	m_IsLeftPressBotton(false),
	m_IsUpPressBotton(false),
	m_IsZPressBotton(false),
	m_IsXPressBotton(false),
	m_ColumnMinoNum(0),
	m_ExistColumnMino(false),
	m_BottomMino(false),
	m_FirstMino(true),
	m_FirstHold(true),
	m_Hold(false),
	m_ExistMinoNum(0),
	m_rota1(false),
	m_rota2(false),
	m_rota3(false),
	m_rota4(false),
	m_MinusMino(false),
	m_End(false)
{
	m_func = &Field::updateAppear;

	/*for (int i = 0; i < kLengthNum; i++)
	{
		m_lengthNum[i] = 0;
	}

	for (int i = 0; i < kSideNum; i++)
	{
		m_sideNum[i] = 0;
	}*/

	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_ActiveFieldNum[i][j] = 0;
		}
	}

	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_ActiveMinoNum[i][j] = 0;
		}
	}

	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_VirtualActiveMinoNum[i][j] = 0;
		}
	}

	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_HoldMinoNum[i][j] = 0;
		}
	}

	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_NextActiveMinoNum[i][j] = 0;
		}
	}

	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_FieldNum[i][j] = 0;
		}
	}

	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_VirtualFieldNum[i][j] = 0;
		}
	}

	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_PredictionMinoFieldNum[i][j] = 0;
		}
	}

	mino = new Mino;
}

Field::~Field()
{
	delete mino;
	mino = nullptr;
}

void Field::init()
{
	m_MinoSize = 20;
	m_MinoNum = 0;
	m_fallFlame = 0;
	m_TensPlaceNum = 0;	// 十の位
	m_OnesPlaceNum = 0;	// 一の位
	m_SwitchMinoFlame = 60;
	m_IsRightPressBotton = false;
	m_IsLeftPressBotton = false;
	m_IsUpPressBotton = false;
	m_ColumnMinoNum = 0;
	m_ExistColumnMino = false;
	m_BottomMino = false;
	m_FirstMino = true;
	m_ExistMinoNum = 0;
	m_rota1 = false;
	m_rota2 = false;
	m_rota3 = false;
	m_rota4 = false;
	m_MinusMino = false;
	m_End = false;
	m_func = &Field::updateAppear;

	/*for (int i = 0; i < kLengthNum; i++)
	{
		m_lengthNum[i] = 0;
	}

	for (int i = 0; i < kSideNum; i++)
	{
		m_sideNum[i] = 0;
	}*/

	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_ActiveFieldNum[i][j] = 0;
		}
	}

	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_ActiveMinoNum[i][j] = 0;
		}
	}

	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_NextActiveMinoNum[i][j] = 0;
		}
	}

	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_FieldNum[i][j] = 0;
		}
	}

	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			m_VirtualFieldNum[i][j] = 0;
		}
	}

	mino = new Mino;
}

void Field::end()
{
}

SceneBase* Field::update()
{
	if (m_End)
	{
		if (CheckHitKey(KEY_INPUT_SPACE))
		{
			init();
			m_End = false;
		}
	}
	if (!m_End)
	{
		m_TensPlaceNum = m_MinoNum / 10;	// 十の位
		m_OnesPlaceNum = m_MinoNum % 10;	// 一の位

		/*if (m_func == &Field::updateLeft)
		{
			if (m_MinoNum % 10 != 0)
			{
				m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;

				m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum - 1] = 1;
			}
		}

		if (m_func == &Field::updateRight)
		{
			if (m_MinoNum % 10 != 9)
			{
				if (m_OnesPlaceNum < 9)
				{
					m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;

					m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum + 1] = 1;
				}
			}
		}*/

		if (IsActive())
		{
			// 落下位置の予測の初期化
			m_PredictionTenNum = 0;
			FallMino();

			PredictionMino();

			if (IsPossibleMino())
			{
				rotationMino();
			}

			if (m_fallFlame >= 20 && m_SwitchMinoFlame == 0)
			{
				for (int i = 0; i < Column; i++)
				{
					for (int j = 0; j < Side; j++)
					{
						if (m_ActiveMinoNum[i][j] == 1)
						{
							m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = 0;
						}
					}
				}
			//	m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;
				m_MinoNum += 10;

				m_TensPlaceNum = m_MinoNum / 10;
				m_OnesPlaceNum = m_MinoNum % 10;

				m_fallFlame = 0;
			}

			else if(m_SwitchMinoFlame < 60)
			{
				(this->*m_func)();
			}

			m_TensPlaceNum = m_MinoNum / 10;	// 十の位
			m_OnesPlaceNum = m_MinoNum % 10;	// 一の位

			MoveMino();

			/*FallMino();*/

			m_TensPlaceNum = m_MinoNum / 10;	// 十の位
			m_OnesPlaceNum = m_MinoNum % 10;	// 一の位

			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					if (m_ActiveMinoNum[i][j] == 1)
					{
						m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = 1;
					}
				}
			}

			//for (int i = 0; i < Column; i++)
			//{
			//	for (int j = 0; j < Side; j++)
			//	{
			//		if (m_ActiveMinoNum[i][j] == 1)
			//		{
			//			m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = 1;

			//			if (m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] == 1 && m_OnesPlaceNum + j >= 10)
			//			{
			//				m_MinoNum--;
			//			}

			//			if (m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] == 1 && m_FieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] == 1)
			//			{
			//				m_MinoNum--;
			//			}

			//			m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = 0;
			//		}
			//	}
			//}

			//m_TensPlaceNum = m_MinoNum / 10;	// 十の位
			//m_OnesPlaceNum = m_MinoNum % 10;	// 一の位

			//for (int i = 0; i < Column; i++)
			//{
			//	for (int j = 0; j < Side; j++)
			//	{
			//		if (m_ActiveMinoNum[i][j] == 1)
			//		{
			//			m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = 1;
			//		}
			//	}
			//}

			//m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum] = 1;

			m_fallFlame++;

			MinoHold();
		}

		if (m_Hold)
		{
			m_Hold = false;

	//		mino->SetMinoNow();
			if (m_FirstHold)
			{
				m_FirstHold = false;
				mino->SetMinoNow();

			}

			mino->SetMino();

			for (int i = 0; i < kLengthNum; i++)
			{
				for (int j = 0; j < kSideNum; j++)
				{
					m_ActiveFieldNum[i][j] = 0;
				}
			}

			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					if (m_ActiveMinoNum[i][j] == 1)
					{
						m_ActiveFieldNum[i][j + 4] = 1;
					}
				}
			}

			m_MinoNum = 4;
		}

		if (!IsActive())
		{
			m_IsXPressBotton = false;
			m_SwitchMinoFlame = 0;

			// m_ActiveFieldNumが1でm_FieldNumが0のときm_FieldNumに1を代入する
			for (int i = 0; i < kLengthNum; i++)
			{
				for (int j = 0; j < kSideNum; j++)
				{
					if (m_ActiveFieldNum[i][j] == 1 && m_FieldNum[i][j] == 0)
					{
						m_FieldNum[i][j] = 1;
					}
				}
			}

			if (m_FieldNum[0][4] == 1 || m_FieldNum[0][5] == 1 ||
				m_FieldNum[0][6] == 1 || m_FieldNum[0][7] == 1)
			{
				m_End = true;
			}

			if (!m_End)
			{
				// ミノが横一列そろったときミノを消すフラグをtrueに
				for (int a = 0; a < 4; a++)
				{
					for (int i = 0; i < kLengthNum; i++)
					{
						if (m_ExistColumnMino)
						{
							break;
						}
						for (int j = 0; j < kSideNum; j++)
						{
							if (j == 0)
							{
								m_ColumnMinoNum = 0;
							}

							if (m_FieldNum[i][j] == 1)
							{
								m_ColumnMinoNum++;
							}
							else
							{
								m_ColumnMinoNum = 0;
									continue;
							}

							if (m_ColumnMinoNum == 10)
							{
								for (int k = 0; k < kSideNum; k++)
								{
									m_FieldNum[i][k] = 0;
								}
								m_DeleteNum++;
								m_ExistColumnMino = true;
								m_ExistMinoNum = i;
							}

						}
					}

					// ミノが横一列そろったときミノを消す
					if (m_ExistColumnMino)
					{
						for (int i = 0; i < kLengthNum; i++)
						{
							for (int j = 0; j < kSideNum; j++)
							{
								if (m_ExistMinoNum > i && m_FieldNum[i][j] == 1)
								{
									m_VirtualFieldNum[i + 1][j] = 1;
								}

								if (m_ExistMinoNum < i && m_FieldNum[i][j] == 1)
								{
									m_VirtualFieldNum[i][j] = 1;
								}
							}
						}

						for (int i = 0; i < kLengthNum; i++)
						{
							for (int j = 0; j < kSideNum; j++)
							{
								m_FieldNum[i][j] = m_VirtualFieldNum[i][j];
								m_VirtualFieldNum[i][j] = 0;
							}
						}
						m_ExistColumnMino = false;
					}
				}

				if (m_DeleteNum > 0)
				{
					if (m_DeleteNum == 1)
					{
						m_Score += 100;
					}
					if (m_DeleteNum == 2)
					{
						m_Score += 300;
					}
					if (m_DeleteNum == 3)
					{
						m_Score += 500;
					}
					if (m_DeleteNum == 4)
					{
						m_Score += 800;
					}
					m_DeleteNum = 0;
				}
		

				for (int i = 0; i < kLengthNum; i++)
				{
					for (int j = 0; j < kSideNum; j++)
					{
						m_ActiveFieldNum[i][j] = 0;
					}
				}
				m_rota1 = true;

				if (!m_FirstMino)
				{
					mino->SetMinoNow();
					mino->SetMino();
					for (int i = 0; i < Column; i++)
					{
						for (int j = 0; j < Side; j++)
						{
							m_ActiveMinoNum[i][j] = mino->GetMino1(i, j);
						}
					}
				}

				mino->NextUpdate();

				mino->NextSetMino();

				for (int i = 0; i < Column; i++)
				{
					for (int j = 0; j < Side; j++)
					{
						m_NextActiveMinoNum[i][j] = mino->NextGetMino(i, j);
					}
				}


				if (m_FirstMino)
				{
					mino->Update();

					mino->SetMino();
		
					for (int i = 0; i < Column; i++)
					{
						for (int j = 0; j < Side; j++)
						{
							m_ActiveMinoNum[i][j] = mino->GetMino1(i,j);
						}
					}
				}

				/*if (!m_FirstMino)
				{
					for (int i = 0; i < Column; i++)
					{
						for (int j = 0; j < Side; j++)
						{
							m_ActiveMinoNum[i][j] = m_NextActiveMinoNum[i][j];
						}
					}
				}*/

				for (int i = 0; i < Column; i++)
				{
					for (int j = 0; j < Side; j++)
					{
						if (m_ActiveMinoNum[i][j] == 1)
						{
							m_ActiveFieldNum[i][j + 4] = 1;
						}
					}
				}

			//	m_ActiveFieldNum[0][5] = 1;

				m_MinoNum = 4;
			//	m_SwitchMinoFlame = 0;
				m_FirstMino = false;
			}
		}
	}
	return this;
}

void Field::draw()
{
	for (int i = -1; i <= kLengthNum; i++)
	{
		for (int j = -1; j <= kSideNum; j++)
		{
			if (i == kLengthNum || i == -1)
			{
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(255, 255, 255), true);
			}
			if (j == -1 || j == kSideNum)
			{
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100, 
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(255, 255, 255),true);
			}
		}
	}

	/*for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			if (m_PredictionMinoFieldNum[i][j] == 1)
			{
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(255, 200, 200), true);
			}
		}
	}*/

	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			DrawBox(j * m_MinoSize + 500, i * m_MinoSize + 100,
				(j + 1) * m_MinoSize + 500, (i + 1) * m_MinoSize + 100, GetColor(255, 255, 255), true);

			if (m_NextActiveMinoNum[i][j] == 1)
			{
				DrawBox(j * m_MinoSize + 500, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 500, (i + 1) * m_MinoSize + 100, GetColor(255, 100, 100), true);
			}

			DrawBox(j * m_MinoSize + 500, i * m_MinoSize + 100,
				(j + 1) * m_MinoSize + 500, (i + 1) * m_MinoSize + 100, GetColor(0, 255, 0), false);
		}
	}

	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			DrawBox(j * m_MinoSize + 500, i * m_MinoSize + 300,
				(j + 1) * m_MinoSize + 500, (i + 1) * m_MinoSize + 300, GetColor(255, 255, 255), true);

			if (m_HoldMinoNum[i][j] == 1)
			{
				DrawBox(j * m_MinoSize + 500, i * m_MinoSize + 300,
					(j + 1) * m_MinoSize + 500, (i + 1) * m_MinoSize + 300, GetColor(255, 100, 100), true);
			}

			DrawBox(j * m_MinoSize + 500, i * m_MinoSize + 300,
				(j + 1) * m_MinoSize + 500, (i + 1) * m_MinoSize + 300, GetColor(0, 255, 0), false);
		}
	}

	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			if (m_FieldNum[i][j] == 0)
			{
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(0, 255, 0), false);
			}

			if (m_FieldNum[i][j] == 1)
			{
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(255, 0, 0), true);
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(0, 255, 0), false);
			}

			if (m_ActiveFieldNum[i][j] == 1)
			{
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(255, 100, 100), true);
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(0, 255, 0), false);
			}
		}
	}
	SetFontSize(20);
	DrawFormatString(350, 300, GetColor(255,255,255),"Score::%d", m_Score);

	if (m_End)
	{
		SetFontSize(50);

		DrawString(500, 300, "ゲームオーバー",
			GetColor(0, 255, 0), 50);

		DrawString(500, 400, "もう一度遊ぶ→SPACE",
			GetColor(0, 255, 0), 50);
	}
}

void Field::updateAppear()
{
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_fallFlame += 5;
	}

	if (!CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_IsRightPressBotton = false;
	}

	if (!CheckHitKey(KEY_INPUT_LEFT))
	{
		m_IsLeftPressBotton = false;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT) && !m_IsRightPressBotton)
	{
		m_func = &Field::updateRight;
	}

	if (CheckHitKey(KEY_INPUT_LEFT) && !m_IsLeftPressBotton)
	{
		m_func = &Field::updateLeft;
	}

}

void Field::updateLeft()
{
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_fallFlame += 5;
	}

	if (!m_IsLeftPressBotton)
	{
		if (IsLeft())
		{
			m_MinusMino = true;
			m_MinoNum--;
		}

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				if (m_ActiveMinoNum[i][j] == 1)
				{
					m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = 0;
				}
			}
		}
		//m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;

		//m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum - 1] = 1;
	}
	m_IsLeftPressBotton = true;

	m_func = &Field::updateAppear;
}

void Field::updateRight()
{
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_fallFlame += 5;
	}

	if (!m_IsRightPressBotton)
	{
		if (IsRight())
		{
			m_MinusMino = false;
			m_MinoNum++;
		}

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				if (m_ActiveMinoNum[i][j] == 1)
				{
					m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = 0;
				}
			}
		}

		//m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;

		//m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + 1] = 1;
	}

	m_IsRightPressBotton = true;

	//m_TensPlaceNum = m_MinoNum / 10;	// 十の位
	//m_OnesPlaceNum = m_MinoNum % 10;	// 一の位

	m_func = &Field::updateAppear;
}

bool Field::IsActive()
{
	if (m_FirstMino)
	{
		return false;
	}
	for (int i = 0; i < kLengthNum; i++)
	{
		if (m_BottomMino)
		{
			break;
		}

		for (int j = 0; j < kSideNum; j++)
		{
			if (m_ActiveFieldNum[kLengthNum - 1][j] == 1)
			{
				//m_SwitchMinoFlame++;
				//return false;

				m_BottomMino = true;
				break;
			}
			
			else if (m_ActiveFieldNum[i][j] == 1 && m_FieldNum[i + 1][j] == 1)
			{
				//m_SwitchMinoFlame++;
				//return false;

				m_BottomMino = true;
				break;
			}

			else
			{
				m_BottomMino = false;
			}
		}
	}

	if (m_BottomMino == true)
	{
		m_SwitchMinoFlame++;
	}

	if (m_BottomMino == false)
	{
		m_SwitchMinoFlame = 0;
	}

	if (m_SwitchMinoFlame >= 60)
	{
		m_BottomMino = false;
		return false;
	}
	return true;
}

bool Field::IsLeft()
{
	if (m_ActiveFieldNum[m_TensPlaceNum][0] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][0] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][0] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][0] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum] == 1 &&
		m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum - 1] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum] == 1 &&
		m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum - 1] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum] == 1 &&
		m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum - 1] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum] == 1 &&
		m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum - 1] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + 1] == 1 &&
		m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 1] == 1 &&
		m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 1] == 1 &&
		m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 1] == 1 &&
		m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + 2] == 1 &&
		m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum + 1] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 2] == 1 &&
		m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 1] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 2] == 1 &&
		m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 1] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 2] == 1 &&
		m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 1] == 1)
	{
		return false;
	}

	return true;
}

bool Field::IsRight()
{
	if (m_ActiveFieldNum[m_TensPlaceNum][9] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][9] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][9] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][9] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + 3] == 1 &&
		m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum + 4] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 3] == 1 &&
		m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 4] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 3] == 1 &&
		m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 4] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 3] == 1 &&
		m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 4] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + 2] == 1 &&
		m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum + 3] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 2] == 1 &&
		m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 3] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 2] == 1 &&
		m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 3] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 2] == 1 &&
		m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 3] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + 1] == 1 &&
		m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum + 2] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 1] == 1 &&
		m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + 2] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 1] == 1 &&
		m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + 2] == 1)
	{
		return false;
	}

	if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 1] == 1 &&
		m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + 2] == 1)
	{
		return false;
	}

	return true;
}

void Field::rotationMino()
{
	if (CheckHitKey(KEY_INPUT_UP) && !m_IsUpPressBotton)
	{
		m_IsUpPressBotton = true;

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = 0;
			}
		}

		if (m_rota1)
		{
			m_rota1 = false;
			m_rota2 = true;
			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					m_ActiveMinoNum[i][j] = mino->GetMino2(i, j);
				}
			}
		}

		else if (m_rota2)
		{
			m_rota2 = false;
			m_rota3 = true;
			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					m_ActiveMinoNum[i][j] = mino->GetMino3(i, j);
				}
			}
		}

		else if (m_rota3)
		{
			m_rota3 = false;
			m_rota4 = true;
			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					m_ActiveMinoNum[i][j] = mino->GetMino4(i, j);
				}
			}
		}

		else if (m_rota4)
		{
			m_rota4 = false;
			m_rota1 = true;
			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					m_ActiveMinoNum[i][j] = mino->GetMino1(i, j);
				}
			}
		}

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				if (m_ActiveMinoNum[i][j] == 1)
				{
					m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = 1;
				}
			}
		}
	}
	else if (!CheckHitKey(KEY_INPUT_UP))
	{
		m_IsUpPressBotton = false;
	}
}

void Field::MoveMino()
{
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			if (m_ActiveMinoNum[i][j] == 1)
			{
				m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = 1;

				if (m_OnesPlaceNum + j >= 10 && !m_MinusMino)
				{
					m_MinoNum--;
				}

				/*if (m_FieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] == 1 && j >= 2)
				{
					m_MinoNum--;
				}*/

				///*if (m_FieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] == 1)
				//{
				//	m_MinoNum -= 10;
				//}*/

				for (int k = 0; k <= kLengthNum; k++)
				{
					if (m_ActiveFieldNum[k][0] == 1 && m_ActiveFieldNum[k + i][9] == 1 && m_MinusMino)
					{
						m_MinoNum++;
						break;
					}

					if (m_ActiveFieldNum[k + 1][0] == 1 && m_ActiveFieldNum[k + i][9] == 1 && m_MinusMino)
					{
						m_MinoNum++;
						break;
					}

					if (m_ActiveFieldNum[k + 2][0] == 1 && m_ActiveFieldNum[k + i][9] == 1 && m_MinusMino)
					{
						m_MinoNum++;
						break;
					}

					if (m_ActiveFieldNum[k + 3][0] == 1 && m_ActiveFieldNum[k + i][9] == 1 && m_MinusMino)
					{
						m_MinoNum++;
						break;
					}
				}

				/*if (m_FieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] == 1 && j < 2)
				{
					m_MinoNum++;
				}*/

				m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = 0;
			}
		}
	}
}

void Field::FallMino()
{
	if (CheckHitKey(KEY_INPUT_Z) && !m_IsZPressBotton)
	{
		m_IsZPressBotton = true;

		while (IsPossibleFall())
		{
			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = 0;
				}
			}

			m_TensPlaceNum++;
			m_MinoNum += 10;

			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					m_ActiveFieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] = m_ActiveMinoNum[i][j];
				}
			}
		}

		if (!IsPossibleFall())
		{
			m_SwitchMinoFlame = 60;
		}
	}

	else if (!CheckHitKey(KEY_INPUT_Z))
	{
		m_IsZPressBotton = false;
	}
}

void Field::PredictionMino()
{
	while (IsPredictionFall())
	{
		for (int i = 0; i < kLengthNum; i++)
		{
			for (int j = 0; j < kSideNum; j++)
			{
				m_PredictionMinoFieldNum[i][j] = 0;
			}
		}

		m_PredictionTenNum++;

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				m_PredictionMinoFieldNum[m_PredictionTenNum + i][m_OnesPlaceNum + j] = m_ActiveMinoNum[i][j];
			}
		}
	}

	if (!IsPredictionFall())
	{
		for (int i = 0; i < kLengthNum; i++)
		{
			for (int j = 0; j < kSideNum; j++)
			{
				m_PredictionMinoFieldNum[i][j] = 0;
			}
		}

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				m_PredictionMinoFieldNum[m_PredictionTenNum + i][m_OnesPlaceNum + j] = m_ActiveMinoNum[i][j];
			}
		}
	}
}

void Field::MinoHold()
{
	if (CheckHitKey(KEY_INPUT_X) && !m_IsXPressBotton)
	{
		m_IsXPressBotton = true;
		m_Hold = true;

		if (!m_FirstHold)
		{
			mino->SetHoldMino1();
		}

		mino->SetHoldMino();

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				m_ActiveMinoNum[i][j] = 0;
			}
		}

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				m_ActiveMinoNum[i][j] = m_HoldMinoNum[i][j];
			}
		}
		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				m_HoldMinoNum[i][j] = mino->GetMino1(i, j);
			}
		}

		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				if (m_ActiveMinoNum[i][j] == 1)
				{
					m_FirstHold = false;
					break;
				}
			}
		}

		if (m_FirstHold)
		{
			for (int i = 0; i < Column; i++)
			{
				for (int j = 0; j < Side; j++)
				{
					m_ActiveMinoNum[i][j] = mino->NextGetMino(i, j);
				}
			}
		}
	}
}

bool Field::IsPossibleFall()
{
	for (int i = 0; i < kSideNum; i++)
	{
		if (m_ActiveFieldNum[kLengthNum - 1][i] == 1)
		{
			return false;
		}
	}

	for (int i = 0; i < Side; i++)
	{
		if (m_ActiveFieldNum[m_TensPlaceNum][m_OnesPlaceNum + i] == 1
			&& m_FieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + i] == 1)
		{
			return false;
		}

		if (m_ActiveFieldNum[m_TensPlaceNum + 1][m_OnesPlaceNum + i] == 1
			&& m_FieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + i] == 1)
		{
			return false;
		}

		if (m_ActiveFieldNum[m_TensPlaceNum + 2][m_OnesPlaceNum + i] == 1
			&& m_FieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + i] == 1)
		{
			return false;
		}

		if (m_ActiveFieldNum[m_TensPlaceNum + 3][m_OnesPlaceNum + i] == 1
			&& m_FieldNum[m_TensPlaceNum + 4][m_OnesPlaceNum + i] == 1)
		{
			return false;
		}
	}
	return true;
}

bool Field::IsPredictionFall()
{
	for (int i = 0; i < kSideNum; i++)
	{
		if (m_PredictionMinoFieldNum[kLengthNum - 1][i] == 1)
		{
			return false;
		}
	}

	for (int i = 0; i < Side; i++)
	{
		if (m_PredictionMinoFieldNum[m_PredictionTenNum][m_OnesPlaceNum + i] == 1
			&& m_FieldNum[m_PredictionTenNum + 1][m_OnesPlaceNum + i] == 1)
		{
			return false;
		}

		if (m_PredictionMinoFieldNum[m_PredictionTenNum + 1][m_OnesPlaceNum + i] == 1
			&& m_FieldNum[m_PredictionTenNum + 2][m_OnesPlaceNum + i] == 1)
		{
			return false;
		}

		if (m_PredictionMinoFieldNum[m_PredictionTenNum + 2][m_OnesPlaceNum + i] == 1
			&& m_FieldNum[m_PredictionTenNum + 3][m_OnesPlaceNum + i] == 1)
		{
			return false;
		}

		if (m_PredictionMinoFieldNum[m_PredictionTenNum + 3][m_OnesPlaceNum + i] == 1
			&& m_FieldNum[m_PredictionTenNum + 4][m_OnesPlaceNum + i] == 1)
		{
			return false;
		}
	}
	return true;
}

bool Field::IsPossibleMino()
{
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_VirtualActiveMinoNum[i][j] = 0;
		}
	}

	if (m_rota1)
	{
		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				m_VirtualActiveMinoNum[i][j] = mino->GetMino2(i, j);
			}
		}
	}

	else if (m_rota2)
	{
		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				m_VirtualActiveMinoNum[i][j] = mino->GetMino3(i, j);
			}
		}
	}

	else if (m_rota3)
	{
		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				m_VirtualActiveMinoNum[i][j] = mino->GetMino4(i, j);
			}
		}
	}

	else if (m_rota4)
	{
		for (int i = 0; i < Column; i++)
		{
			for (int j = 0; j < Side; j++)
			{
				m_VirtualActiveMinoNum[i][j] = mino->GetMino1(i, j);
			}
		}
	}

	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			if (m_VirtualActiveMinoNum[i][j] == 1 &&
				m_FieldNum[m_TensPlaceNum + i][m_OnesPlaceNum + j] == 1)
			{
				return false;
			}
		}
	}
	return true;
}
