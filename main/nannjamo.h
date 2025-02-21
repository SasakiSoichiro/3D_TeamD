#pragma once
#ifndef _NANNJAMO_H_
#define _NANNJAMO_H_

#include "main.h"

//	�t�F�[�h�̏��
typedef enum
{
	Nannjamo_NONE = 0,	//	�������Ă��Ȃ����
	Nannjamo_IN,		//	�t�F�[�h�C�����
	Nannjamo_OUT,		//	�t�F�[�h�A�E�g���
	Nannjamo_DRAW,
	Nannjamo_MAX
}Nannjamo_MODE;

typedef struct
{
	D3DXCOLOR col;
	Nannjamo_MODE ui;
	bool bUse;
	int count;
}Nannjamo;

void InitNannjamo(void);
void UinitNannjamo(void);
void UpdateNannjamo(void);
void DrawNannjamo(void);
void SetNannjamo(int count);

#endif // !_NANNJAMO_H_
