#pragma once
#include <vector>

class Mino
{
private:
	static constexpr int Column = 4;
	static constexpr int Size = 4;

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

	void GetMino();

private:
	int m_RandMino;

	int m_MinoTypes;
	int m_Tetrimino[Column][Size];
};
