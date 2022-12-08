#pragma once

#include<map>
#include<vector>

enum class InputType
{
	next,	//���֍s���{�^��
	prev,	//�O�ɖ߂�{�^��
	pause,	//�|�[�Y�{�^��
	keyconf, //�L�[�R���t�B�O
	max//�ő���̓C���f�b�N�X
};
/// <summary>
/// ���͑��u�J�e�S���[
/// </summary>
enum class InputCategory {
	keybd,//�L�[�{�[�h
	pad,//�Q�[���p�b�h
	mouse//�}�E�X
};

struct InputInfo {
	InputCategory cat;//���͑��u�J�e�S��
	int id;//����ID(KEY_INPUT_�`,PAD_INPUT_�`,MOUSE_INPUT_�`)
};

/// <summary>
/// ���͏�Ԃ��Ǘ�����
/// </summary>
class InputState
{
private:
	std::map< InputType, std::vector<InputInfo> > inputMapTable_;//���ۂ̓��͂ƃQ�[���{�^���̑Ή����e�[�u��

	std::vector<bool> currentInput_;//���݂̓��͏��(�����Ă邩������ĂȂ���)
	std::vector<bool> lastInput_;//���O�̓��͏��(���O�����Ă邩�����ĂȂ���)
public:
	InputState();
	/// <summary>
	/// �������u�Ԃ�true�ɂȂ�
	/// </summary>
	/// <param name="type">InputType</param>
	/// <returns></returns>
	bool isTriggered(InputType type) const;
	/// <summary>
	/// ������Ă�����true�ɂȂ�
	/// </summary>
	/// <param name="type"></param>
	/// <returns></returns>
	bool IsPressed(InputType type) const;
	/// <summary>
	/// ���͏����X�V����
	/// </summary>
	/// (����)���t���[��
	void Update();
};

