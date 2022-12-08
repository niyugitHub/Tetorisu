#pragma once

#include<map>
#include<vector>

enum class InputType
{
	next,	//次へ行くボタン
	prev,	//前に戻るボタン
	pause,	//ポーズボタン
	keyconf, //キーコンフィグ
	max//最大入力インデックス
};
/// <summary>
/// 入力装置カテゴリー
/// </summary>
enum class InputCategory {
	keybd,//キーボード
	pad,//ゲームパッド
	mouse//マウス
};

struct InputInfo {
	InputCategory cat;//入力装置カテゴリ
	int id;//入力ID(KEY_INPUT_～,PAD_INPUT_～,MOUSE_INPUT_～)
};

/// <summary>
/// 入力状態を管理する
/// </summary>
class InputState
{
private:
	std::map< InputType, std::vector<InputInfo> > inputMapTable_;//実際の入力とゲームボタンの対応をテーブル

	std::vector<bool> currentInput_;//現在の入力情報(押してるか押されてないか)
	std::vector<bool> lastInput_;//直前の入力情報(直前押してるか押してないか)
public:
	InputState();
	/// <summary>
	/// 押した瞬間にtrueになる
	/// </summary>
	/// <param name="type">InputType</param>
	/// <returns></returns>
	bool isTriggered(InputType type) const;
	/// <summary>
	/// 押されていたらtrueになる
	/// </summary>
	/// <param name="type"></param>
	/// <returns></returns>
	bool IsPressed(InputType type) const;
	/// <summary>
	/// 入力情報を更新する
	/// </summary>
	/// (注意)毎フレーム
	void Update();
};

