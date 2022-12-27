#pragma once

class Mino;

class Field
{
private:
	static constexpr int Column = 4;
	static constexpr int Side = 4;
public:
	Field();

	virtual ~Field();
	
	void init();

	void end();

	void update();

	void draw();

	bool IsActive();

	bool IsLeft();

	bool IsRight();
	//bool columnExist();
private:
	void updateAppear();	// �o��
	void updateLeft();		// ���Ɉړ�
	void updateRight();		// �E�Ɉړ�

private:
	// �t�B�[���h�T�C�Y
	int m_MinoSize;

	// �������Ă���~�m�̃t�B�[���h���i0,1�j
	int m_ActiveFieldNum[20][10];

	// �������Ă���~�m�̏��i0,1�j
	int m_ActiveMinoNum[Column][Side];

	// �t�B�[���h�̏��i0,1�j
	int m_FieldNum[20][10];

	// �~�m�����������̒u������
	int m_VirtualFieldNum[20][10];

	// �e�g���~�m�ԍ�
	int m_MinoNum;
	// �e�g���~�m�̏\�̈ʂ̔ԍ�
	int m_TensPlaceNum;
	// �e�g���~�m�̈�̈ʂ̔ԍ�
	int m_OnesPlaceNum;

	// �e�g���~�m�̗����鑬�x
	int m_fallFlame;
	
	// �e�g���~�m���؂�ւ�鎞��
	int m_SwitchMinoFlame;

	bool m_IsRightPressBotton;
	bool m_IsLeftPressBotton;

	// �����̃~�m�̐�
	int m_ColumnMinoNum;

	// �����ɂ��ׂă~�m�����݂��邩�ǂ���
	bool m_ExistColumnMino;

	// �ŏ��ɏo�����~�m�̂Ƃ�
	bool m_FirstMino;

	// ����ڂ̃~�m�����������
	int m_ExistMinoNum;

	// update���������o�֐��|�C���^
	void(Field:: *m_func)();

	Mino*mino;
};

