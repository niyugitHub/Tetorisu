#pragma once
class Field
{
public:
	Field();

	virtual ~Field();
	
	void init();

	void end();

	void update();

	void draw();
private:
	// �t�B�[���h�̕�
	int m_lengthNum[20];
	int m_sideNum[10];

	// �t�B�[���h�T�C�Y
	int m_MinoSize;

	// �t�B�[���h�̏��i0,1�j
	int m_FieldNum[20][10];

	// �e�g���~�m�ԍ�
	int m_MinoNum;

	// �e�g���~�m�������Ă���Ƃ�
	bool m_Active;

	// �e�g���~�m�̗����鑬�x
	int  m_fallFlame;
};

