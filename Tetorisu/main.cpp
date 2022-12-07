#include "DxLib.h"

#include"Vec2.h"
#include"Field.h"

namespace
{
	// �E�C���h�E���[�h�ݒ�
	constexpr bool kWindouwMode = true;
	// �E�C���h�E��
	const char* const kTitleText = "�Q�[����";
	// �E�C���h�E�T�C�Y
	constexpr int kScreenWidth = 1280;
	constexpr int kScreenHeight = 720;
	// �J���[���[�h
	constexpr int kColorDepth = 32;
}

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	// window���[�h�ݒ�
	ChangeWindowMode(kWindouwMode);
	// �E�C���h�E���ݒ�
	SetMainWindowText("�Q�[����");
	// ��ʃT�C�Y�̐ݒ�
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1)	// DX���C�u��������������
	{
		return -1;		// �G���[���N�����璼���ɏI��
	}

	// �_�u���o�b�t�@���[�h
	SetDrawScreen(DX_SCREEN_BACK);

	Field field;
	field.init();

	while (ProcessMessage() == 0)
	{
		LONGLONG time = GetNowHiPerformanceCount();
		// ��ʂ̃N���A
		ClearDrawScreen();

		SetMouseDispFlag(1);

		field.update();
		field.draw();

		// ����ʂƕ\��ʂ����ւ���
		ScreenFlip();

		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		// fps��60�ɌŒ�
		while (GetNowHiPerformanceCount() - time < 16667)
		{

		}
	}
	field.end();

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}