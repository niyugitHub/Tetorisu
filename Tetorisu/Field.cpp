#include "Field.h"
#include<Dxlib.h>

namespace
{
	constexpr int kLengthNum = 20;
	constexpr int kSideNum = 10;
}

Field::Field() : 
	m_MinoSize(20),
	m_MinoNum(0),
	m_Active(false),
	m_fallFlame(0),
	m_TensPlaceNum(0),	// è\ÇÃà 
	m_OnesPlaceNum(0),	// àÍÇÃà 
	m_IsRightPressBotton(false),
	m_IsLeftPressBotton(false)
{
	m_func = &Field::updateAppear;

	for (int i = 0; i < kLengthNum; i++)
	{
		m_lengthNum[i] = 0;
	}

	for (int i = 0; i < kSideNum; i++)
	{
		m_sideNum[i] = 0;
	}

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
}

Field::~Field()
{

}

void Field::init()
{
}

void Field::end()
{
}

void Field::update()
{
	if (!m_Active)
	{
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
				m_ActiveMinoNum[i][j] = 0;
			}
		}
		m_ActiveMinoNum[0][5] = 1;
		m_MinoNum = 5;
		m_Active = true;
	}

	if (m_func == &Field::updateLeft)
	{
		if (m_MinoNum % 10 != 0)
		{
			m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;

			m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum - 1] = 1;
		}
	}

	if(m_func == &Field::updateRight)
	{
		if (m_MinoNum % 10 != 9)
		{
		m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;

		m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum + 1] = 1;
		}
	}
	(this->*m_func)();

	m_TensPlaceNum = m_MinoNum / 10;	// è\ÇÃà 
	m_OnesPlaceNum = m_MinoNum % 10;	// àÍÇÃà 

	if (m_fallFlame >= 20)
	{
		m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum] = 0;
		m_MinoNum += 10;

		m_TensPlaceNum = m_MinoNum / 10;
		m_OnesPlaceNum = m_MinoNum % 10;

		m_ActiveMinoNum[m_TensPlaceNum][m_OnesPlaceNum] = 1;
		m_fallFlame = 0;
	}

	if (m_ActiveMinoNum[19][5] == 1)
	{
		m_Active = false;
	}

	m_fallFlame++;

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
			if (m_FieldNum[i][j] == 1)
			{
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(255, 0, 0), true);
			}

			if (m_ActiveMinoNum[i][j] == 1)
			{
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(255, 0, 0), true);
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

	if (CheckHitKey(KEY_INPUT_RIGHT) && !m_IsRightPressBotton)
	{
		m_func = &Field::updateRight;
	}

	if (CheckHitKey(KEY_INPUT_LEFT) && !m_IsLeftPressBotton)
	{
		m_func = &Field::updateLeft;
	}

	if (!CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_IsRightPressBotton = false;
	}

	if (!CheckHitKey(KEY_INPUT_LEFT))
	{
		m_IsLeftPressBotton = false;
	}
}

void Field::updateLeft()
{
	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_fallFlame += 5;
	}

	if (m_MinoNum % 10 != 0 && !m_IsLeftPressBotton)
	{
		m_MinoNum--;
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

	if (m_MinoNum % 10 != 9 && !m_IsRightPressBotton)
	{
		m_MinoNum++;
	}

	m_IsRightPressBotton = true;

	m_TensPlaceNum = m_MinoNum / 10;	// è\ÇÃà 
	m_OnesPlaceNum = m_MinoNum % 10;	// àÍÇÃà 

	m_func = &Field::updateAppear;
}

//bool Field::IsActive()
//{
//	for (int i = 0; i < kLengthNum; i++)
//	{
//		for (int j = 0; j < kSideNum; j++)
//		{
//			if (m_FieldNum[kLengthNum - 1][j] == 1)
//			{
//				return false;
//			}
//		}
//	}
//	return true;
//}
