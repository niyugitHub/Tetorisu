#include "Field.h"
#include "Mino.h"
#include<Dxlib.h>

namespace
{
	constexpr int kLengthNum = 20;
	constexpr int kSideNum = 10;
}

Field::Field() : 
	m_MinoSize(20),
	m_MinoNum(5),
	m_fallFlame(0),
	m_TensPlaceNum(0),	// 十の位
	m_OnesPlaceNum(0),	// 一の位
	m_SwitchMinoFlame(0),
	m_IsRightPressBotton(false),
	m_IsLeftPressBotton(false),
	m_ColumnMinoNum(0),
	m_ExistColumnMino(false),
	m_ExistMinoNum(0)
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
			m_ActiveMinoNum[i][j] = 0;
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

Field::~Field()
{
	delete mino;
	mino = nullptr;
}

void Field::init()
{
}

void Field::end()
{
}

void Field::update()
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
	(this->*m_func)();

	if (IsActive())
	{
		m_TensPlaceNum = m_MinoNum / 10;	// 十の位
		m_OnesPlaceNum = m_MinoNum % 10;	// 一の位

		if (m_fallFlame >= 20)
		{
			m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;
			m_MinoNum += 10;

			m_TensPlaceNum = m_MinoNum / 10;
			m_OnesPlaceNum = m_MinoNum % 10;

			m_fallFlame = 0;
		}

		m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum] = 1;

		m_fallFlame++;
	}

	if (!IsActive() && m_SwitchMinoFlame >= 60)
	{
		m_SwitchMinoFlame = 0;
		for (int i = 0; i < kLengthNum; i++)
		{
			for (int j = 0; j < kSideNum; j++)
			{
				if (m_ActiveMinoNum[i][j] == 1 && m_FieldNum[i][j] == 0)
				{
					m_FieldNum[i][j] = 1;
				}
			}
		}

		for (int i = 0; i < kLengthNum; i++)
		{
			for (int j = 0; j < kSideNum; j++)
			{
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
					m_ExistColumnMino = true;
					m_ExistMinoNum = i;
				}

			}
		}

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
		

		for (int i = 0; i < kLengthNum; i++)
		{
			for (int j = 0; j < kSideNum; j++)
			{
				m_ActiveMinoNum[i][j] = 0;
			}
		}
		m_ActiveMinoNum[0][5] = 1;
		m_MinoNum = 5;
	//	m_SwitchMinoFlame = 0;
	}
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

			if (m_ActiveMinoNum[i][j] == 1)
			{
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(255, 0, 0), true);
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(0, 255, 0), false);
			}
		}
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

	if (m_MinoNum % 10 != 0 && !m_IsLeftPressBotton
		&& m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum - 1] == 0)
	{
		m_MinoNum--;
		m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;

		m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum - 1] = 1;
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

	if (m_MinoNum % 10 != 9 && !m_IsRightPressBotton
		&& m_FieldNum[m_TensPlaceNum][m_OnesPlaceNum + 1] == 0)
	{
		m_MinoNum++;

		m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;

		m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum + 1] = 1;
	}

	m_IsRightPressBotton = true;

	m_TensPlaceNum = m_MinoNum / 10;	// 十の位
	m_OnesPlaceNum = m_MinoNum % 10;	// 一の位

	m_func = &Field::updateAppear;
}

bool Field::IsActive()
{
	for (int i = 0; i < kLengthNum; i++)
	{
		for (int j = 0; j < kSideNum; j++)
		{
			if (m_ActiveMinoNum[kLengthNum - 1][j] == 1)
			{
				m_SwitchMinoFlame++;
				return false;
			}
			
			if (m_ActiveMinoNum[i][j] == 1 && m_FieldNum[i + 1][j] == 1)
			{
				m_SwitchMinoFlame++;
				return false;
			}
		}
	}
	return true;
}