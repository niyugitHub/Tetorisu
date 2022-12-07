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
	m_fallFlame(0)
{
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
		m_FieldNum[0][5] = 1;
		m_MinoNum = 5;
		m_Active = true;
	}

	int num1 = m_MinoNum / 10;	// \‚ÌˆÊ
	int num2 = m_MinoNum % 10;	// ˆê‚ÌˆÊ

	if (m_fallFlame >= 30)
	{
		m_FieldNum[num1][num2] = 0;
		m_MinoNum += 10;
		m_FieldNum[num1 + 1][num2] = 1;
		m_fallFlame = 0;
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

			/*if (m_FieldNum[i][j] == 0)
			{
				DrawBox(j * m_MinoSize + 100, i * m_MinoSize + 100,
					(j + 1) * m_MinoSize + 100, (i + 1) * m_MinoSize + 100, GetColor(0, 0, 0), true);
			}*/
		}


	}

}
