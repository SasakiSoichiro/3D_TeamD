#pragma once
#ifndef _GONNZARESU_H_
#define _GONNZARESU_H_

#include "main.h"

//	フェードの状態
typedef enum
{
	UI_NONE = 0,	//	何もしていない状態
	UI_IN,		//	フェードイン状態
	UI_OUT,		//	フェードアウト状態
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
