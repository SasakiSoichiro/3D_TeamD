#pragma once
#ifndef _RESULT_H_
#define _RESULT_H_

#include "main.h"
#include "game.h"
#include "input.h"

//	�\����
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXCOLOR col;
	bool bUse;			// �g���Ă邩
	float fHeight;		// ����
	float fWidth;		// ��
}Result;

void InitResult(void);
void UinitResult(void);
void UpdateResult(void);
void DrawResult(void);

#endif // !_RESULT_H_
