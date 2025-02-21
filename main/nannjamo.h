#pragma once
#ifndef _NANNJAMO_H_
#define _NANNJAMO_H_

#include "main.h"

//	フェードの状態
typedef enum
{
	Nannjamo_NONE = 0,	//	何もしていない状態
	Nannjamo_IN,		//	フェードイン状態
	Nannjamo_OUT,		//	フェードアウト状態
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
