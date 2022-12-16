#include "Mino.h"
#include<Dxlib.h>

Mino::Mino():
	m_RandMino(0),
	m_MinoTypes(0)
{
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Side; j++)
		{
			m_Tetrimino[i][j] = 0;
		}
	}
}

Mino::~Mino()
{
	
}

void Mino::Update()
{
	m_RandMino = GetRand(6);

	//SetMino();

	//GetMino(int i, int j);
}

void Mino::SetMino()
{
	switch (m_RandMino)
	{
	case 0:
		m_MinoTypes = TypeI;
		break;
	case 1:
		m_MinoTypes = TypeJ;
		break;
	case 2:
		m_MinoTypes = TypeL;
		break;
	case 3:
		m_MinoTypes = TypeO;
		break;
	case 4:
		m_MinoTypes = TypeS;
		break;
	case 5:
		m_MinoTypes = TypeT;
		break;
	case 6:
		m_MinoTypes = TypeZ;
		break;
	default:
		break;
	}
}

int Mino::GetMino(int i , int j)
{
	if (m_MinoTypes == TypeI)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 1;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoTypes == TypeJ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 0;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoTypes == TypeL)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoTypes == TypeO)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoTypes == TypeS)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoTypes == TypeT)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoTypes == TypeZ)
	{
		m_Tetrimino[0][0] = 1;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	return m_Tetrimino[i][j];
}
