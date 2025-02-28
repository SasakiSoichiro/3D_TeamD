#pragma once
#ifndef _RESULT_H_
#define _RESULT_H_

#include "main.h"
#include "game.h"
#include "input.h"

//	構造体
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXCOLOR col;
	bool bUse;			// 使われてるか
	float fHeight;		// 高さ
	float fWidth;		// 幅
}Result;

void InitResult(void);
void UninitResult(void);
void UpdateResult(void);
void DrawResult(void);

#endif // !_RESULT_H_
