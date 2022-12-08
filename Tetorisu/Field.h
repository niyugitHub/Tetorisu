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

//	bool IsActive();
private:
	void updateAppear();	// �o��
	void updateLeft();		// ���Ɉړ�
	void updateRight();		// �E�Ɉړ�
	void updateDown();		// ���ɑf�����ړ�

private:
	// �t�B�[���h�̕�
	int m_lengthNum[20];
	int m_sideNum[10];

	// �t�B�[���h�T�C�Y
	int m_MinoSize;

	// �������Ă���~�m�̏��i0,1�j
	int m_ActiveMinoNum[20][10];

	// �t�B�[���h�̏��i0,1�j
	int m_FieldNum[20][10];

	// �e�g���~�m�ԍ�
	int m_MinoNum;
	// �e�g���~�m�̏\�̈ʂ̔ԍ�
	int m_TensPlaceNum;
	// �e�g���~�m�̈�̈ʂ̔ԍ�
	int m_OnesPlaceNum;

	// �e�g���~�m�������Ă���Ƃ�
	bool m_Active;

	// �e�g���~�m�̗����鑬�x
	int  m_fallFlame;


	bool m_IsRightPressBotton;
	bool m_IsLeftPressBotton;

	// update���������o�֐��|�C���^
	void(Field:: *m_func)();
};

