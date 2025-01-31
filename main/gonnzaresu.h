#pragma once
#ifndef _GONNZARESU_H_
#define _GONNZARESU_H_

#include "main.h"

//	�t�F�[�h�̏��
typedef enum
{
	UI_NONE = 0,	//	�������Ă��Ȃ����
	UI_IN,		//	�t�F�[�h�C�����
	UI_OUT,		//	�t�F�[�h�A�E�g���
	UI_DRAW,
	UI_MAX
}UI_MODE;

typedef struct
{
	D3DXCOLOR col;
	UI_MODE ui;
	bool bUse;
	int count;
}UI;

void InitGonzaresu(void);
void UinitGonzaresu(void);
void UpdateGonzaresu(void);
void DrawGonzaresu(void);
void SetGonzaresu(int count);

#endif // !_UI_H_
