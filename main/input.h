#pragma once
#ifndef _INPUT_H_
#define _INPUT_H_

#include "main.h"

//================
//	キーの種類
//================
typedef enum
{
	JOYKEY_UP = 0,	//	十字キー(↑)
	JOYKEY_DOWN,	//	十字キー(↓)
	JOYKEY_LEFT,	//	十字キー(←)
	JOYKEY_RIGHT,	//	十字キー(→)
	JOYKEY_START,	//	スタート
	JOYKEY_BACK,	//	バック
	JOYKEY_LPUSH,	//	スティック押し込み	左
	JOYKEY_RPUSH,	//	スティック押し込み	右
	JOYKEY_LB,		//	L1
	JOYKEY_RB,		//	R1
	JOYKEY_LT,		//	L2
	JOYKEY_RT,		//	R2
	JOYKEY_A,		//	Aボタン
	JOYKEY_B,		//	Bボタン
	JOYKEY_X,		//	Xボタン
	JOYKEY_Y,		//	Yボタン
	JOYKEY_MAX
}JOYKEY;

typedef enum
{
	MOUSE_L = 0,
	MOUSE_R,
	MOUSE_H,
	MOUSE_MAX
}MouseButton;

typedef enum
{
	PLAYER_1 = 0,
	PLAYER_2,
	PLAYER_MAX
}PLAYER;

typedef enum
{
	DX_INPUT_KEY_PAD1 = 0, // キー入力とパッド１
	DX_INPUT_PAD1, //パッド１
	DX_INPUT_PAD2, //パッド２
	DX_INPUT_KEY, //キー入力
	DX_INPUT_MAX
}InputType;


//==================
//プロトタイプ
//==================
//キーボード
HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd);
void UninitKeyboard(void);
void UpdateKeyboard(void);
bool GetKeyboardPress(int nKey);
bool KeybordTrigger(int nKey);
bool KeybordRelease(int nKey);
bool KeybordRepeat(int nKey);

//ジョイパッド
HRESULT InitJoypad(void);
void UninitJoypad(void);
void UpdateJoypad(void);
bool GetJoypadPress(JOYKEY key, int player);
bool JoyPadTrigger(JOYKEY key, int player);
bool GetJoyStick(int player);
XINPUT_STATE* GetJoyStickAngle(void);
XINPUT_STATE* GetState(void);
int GetJoypadInputState(int InputType);

//	マウス
HRESULT InitMausu(HINSTANCE hInstance, HWND hWnd);
void UninitMausu(void);
void UpdateMausu(void);
bool OnMouseDown(MouseButton button_type);
bool OnMouseUp(MouseButton button_type);
D3DXVECTOR2 GetMouseVelocity();
D3DXVECTOR2 GetMouseVelocityOld();

#endif