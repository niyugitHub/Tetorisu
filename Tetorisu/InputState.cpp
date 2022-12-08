#include "InputState.h"
#include <DxLib.h>

InputState::InputState()
{
	inputMapTable_[InputType::next] = { {InputCategory::keybd,KEY_INPUT_RETURN},
										{InputCategory::pad,PAD_INPUT_R },
										{InputCategory::mouse, MOUSE_INPUT_LEFT} };

	inputMapTable_[InputType::prev] = { {InputCategory::keybd,KEY_INPUT_SPACE },
										{InputCategory::pad,PAD_INPUT_B } };

	inputMapTable_[InputType::pause] = { {InputCategory::keybd,KEY_INPUT_P},
										{InputCategory::pad, PAD_INPUT_L} };

	inputMapTable_[InputType::keyconf] = { {InputCategory::keybd,KEY_INPUT_P},
										{InputCategory::pad, PAD_INPUT_Y} };

	currentInput_.resize(static_cast<int>(InputType::max));
	lastInput_.resize(static_cast<int>(InputType::max));
}
void InputState::Update()
{
	lastInput_ = currentInput_; //���O�̓��͏����L�����Ă���

	char keystate[256];
	GetHitKeyStateAll(keystate);//�S�L�[���擾

	int padState = GetJoypadInputState(DX_INPUT_PAD1);//�p�b�h1�R���̏����擾����
	int mouseState = GetMouseInput();

	for (const auto& keymap : inputMapTable_)
	{
		for (const auto& input : keymap.second) {
			if (input.cat == InputCategory::keybd) {
				currentInput_[static_cast<int>(keymap.first)] = keystate[input.id];
			}
			else if (input.cat == InputCategory::pad) {
				currentInput_[static_cast<int>(keymap.first)] = padState & input.id;
			}
			else if (input.cat == InputCategory::mouse) {
				currentInput_[static_cast<int>(keymap.first)] = mouseState & input.id;
			}
		}
	}
	////�O�̃t���[���̃L�[�󋵂��R�s�[
	//for (int i = 0; i <_countof(lastKeyState); i++)
	//{
	//	lastKeyState[i] = keyState[i];
	//}
	//GetHitKeyStateAll(keyState);
}

bool InputState::IsPressed(InputType type) const
{
	return currentInput_[static_cast<int>(type)];
	/*if (type == InputType::next)
	{
		return keyState[KEY_INPUT_RETURN];
	}
	return false;*/
}
bool InputState::isTriggered(InputType type) const
{
	return IsPressed(type)&& !lastInput_[static_cast<int>(type)];
	//if (type == InputType::next)
	//{
	//	return !lastKeyState[KEY_INPUT_RETURN] && 
	//		keyState[KEY_INPUT_RETURN];
	//}
	//else if (type == InputType::prev)
	//{
	//	return !lastKeyState[KEY_INPUT_SPACE] &&
	//		keyState[KEY_INPUT_SPACE];
	//}
	//else if (type == InputType::pause)
	//{
	//	//P�L�[�������ꂽ�ꍇ�|�[�Y��ʂɈڍs(�Q�[�����̏ꍇ)
	//	//������x
	//	return !lastKeyState[KEY_INPUT_P] &&
	//		keyState[KEY_INPUT_P];
	//}
	//else if (type == InputType::keyconf) {
	//	return !lastKeyState[KEY_INPUT_K] &&
	//		keyState[KEY_INPUT_K];
	//}
	//return false;
}
