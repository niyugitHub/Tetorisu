#pragma once
#include <vector>

class Mino
{
private:
	static constexpr int Column = 4;
	static constexpr int Side = 4;

public:
	Mino();

	virtual ~Mino();

	enum
	{
		TypeI,
		TypeJ,
		TypeL,
		TypeO,
		TypeS,
		TypeT,
		TypeZ
	};

	void Update();

	void SetMino();

	int GetMino1(int i, int j);

	int GetMino2(int i, int j);

	int GetMino3(int i, int j);

	int GetMino4(int i, int j);

private:
	int m_RandMino;

	int m_MinoTypes;
	int m_Tetrimino[Column][Side];
};

