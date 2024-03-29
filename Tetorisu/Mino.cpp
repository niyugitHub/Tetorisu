#include "Mino.h"
#include<Dxlib.h>

Mino::Mino():
	m_RandMino(0),
	m_NextRandMino(0),
	m_MinoTypes(0),
	m_NextMinoTypes(0),
	m_HoldMino(0),
	m_tmp(0)
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
	m_tmp = m_RandMino;
}

void Mino::NextUpdate()
{
	m_NextRandMino = GetRand(6);
	m_tmp = m_RandMino;
}

void Mino::SetMinoNow()
{
	m_RandMino = m_NextRandMino;
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

void Mino::NextSetMino()
{
	switch (m_NextRandMino)
	{
	case 0:
		m_NextMinoTypes = TypeI;
		break;
	case 1:
		m_NextMinoTypes = TypeJ;
		break;
	case 2:
		m_NextMinoTypes = TypeL;
		break;
	case 3:
		m_NextMinoTypes = TypeO;
		break;
	case 4:
		m_NextMinoTypes = TypeS;
		break;
	case 5:
		m_NextMinoTypes = TypeT;
		break;
	case 6:
		m_NextMinoTypes = TypeZ;
		break;
	default:
		break;
	}
}

void Mino::SetHoldMino()
{
	m_HoldMino = m_tmp;
}

void Mino::SetHoldMino1()
{
	m_RandMino = m_HoldMino;
}

int Mino::GetMino1(int i , int j)
{
	if (m_MinoTypes == TypeI)
	{
		//m_MinoTypes = TypeI;
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

int Mino::GetMino2(int i, int j)
{
	if (m_MinoTypes == TypeI)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 1;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 0;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoTypes == TypeJ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 1;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoTypes == TypeL)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 1;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 0;
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
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoTypes == TypeT)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
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
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 1;
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
	return m_Tetrimino[i][j];
}

int Mino::GetMino3(int i, int j)
{
	if (m_MinoTypes == TypeI)
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
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 0;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 1;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoTypes == TypeJ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 1;
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
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoTypes == TypeL)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 1;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 0;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
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
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 0;
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

int Mino::GetMino4(int i, int j)
{
	if (m_MinoTypes == TypeI)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 0;
		m_Tetrimino[1][2] = 0;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 1;
		m_Tetrimino[2][1] = 1;
		m_Tetrimino[2][2] = 1;
		m_Tetrimino[2][3] = 1;
		m_Tetrimino[3][0] = 0;
		m_Tetrimino[3][1] = 0;
		m_Tetrimino[3][2] = 0;
		m_Tetrimino[3][3] = 0;
	}

	else if (m_MinoTypes == TypeJ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
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
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 1;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 1;
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
		m_Tetrimino[0][2] = 0;
		m_Tetrimino[0][3] = 0;
		m_Tetrimino[1][0] = 0;
		m_Tetrimino[1][1] = 1;
		m_Tetrimino[1][2] = 1;
		m_Tetrimino[1][3] = 0;
		m_Tetrimino[2][0] = 0;
		m_Tetrimino[2][1] = 0;
		m_Tetrimino[2][2] = 1;
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
		m_Tetrimino[1][0] = 1;
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

	else if (m_MinoTypes == TypeZ)
	{
		m_Tetrimino[0][0] = 0;
		m_Tetrimino[0][1] = 0;
		m_Tetrimino[0][2] = 1;
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
return m_Tetrimino[i][j];
}

int Mino::NextGetMino(int i, int j)
{
	if (m_NextMinoTypes == TypeI)
	{
		//m_MinoTypes = TypeI;
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

	else if (m_NextMinoTypes == TypeJ)
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

	else if (m_NextMinoTypes == TypeL)
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

	else if (m_NextMinoTypes == TypeO)
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

	else if (m_NextMinoTypes == TypeS)
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

	else if (m_NextMinoTypes == TypeT)
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

	else if (m_NextMinoTypes == TypeZ)
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
