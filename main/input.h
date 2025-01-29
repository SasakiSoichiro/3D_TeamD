#pragma once
#ifndef _INPUT_H_
#define _INPUT_H_

#include "main.h"

//================
//	�L�[�̎��
//================
typedef enum
{
	JOYKEY_UP = 0,	//	�\���L�[(��)
	JOYKEY_DOWN,	//	�\���L�[(��)
	JOYKEY_LEFT,	//	�\���L�[(��)
	JOYKEY_RIGHT,	//	�\���L�[(��)
	JOYKEY_START,	//	�X�^�[�g
	JOYKEY_BACK,	//	�o�b�N
	JOYKEY_LPUSH,	//	�X�e�B�b�N��������	��
	JOYKEY_RPUSH,	//	�X�e�B�b�N��������	�E
	JOYKEY_LB,		//	L1
	JOYKEY_RB,		//	R1
	JOYKEY_LT,		//	L2
	JOYKEY_RT,		//	R2
	JOYKEY_A,		//	A�{�^��
	JOYKEY_B,		//	B�{�^��
	JOYKEY_X,		//	X�{�^��
	JOYKEY_Y,		//	Y�{�^��
	JOYKEY_MAX
}JOYKEY;

typedef enum
{
	MOUSE_L = 0,
	MOUSE_R,
	MOUSE_H,
	MOUSE_MAX
}MouseButton;

//==================
//�v���g�^�C�v
//==================
//�L�[�{�[�h
HRESULT InitKeyboard(HINSTANCE hInstance, HWND hWnd);
void UninitKeyboard(void);
void UpdateKeyboard(void);
bool GetKeyboardPress(int nKey);
bool KeybordTrigger(int nKey);
bool KeybordRelease(int nKey);
bool KeybordRepeat(int nKey);

//�W���C�p�b�h
HRESULT InitJoypad(void);
void UninitJoypad(void);
void UpdateJoypad(void);
bool GetJoypadPress(JOYKEY key);
bool JoyPadTrigger(JOYKEY key);
bool GetJoyStick(void);
XINPUT_STATE* GetJoyStickAngle(void);

//	�}�E�X
HRESULT InitMausu(HINSTANCE hInstance, HWND hWnd);
void UninitMausu(void);
void UpdateMausu(void);
bool OnMouseDown(MouseButton button_type);
bool OnMouseUp(MouseButton button_type);
D3DXVECTOR2 GetMouseVelocity();
D3DXVECTOR2 GetMouseVelocityOld();

#endif