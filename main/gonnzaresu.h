#pragma once
#ifndef _GONNZARESU_H_
#define _GONNZARESU_H_

#include "main.h"
#define MAX_GONNZARESU (1)

typedef enum
{
	UITYPE_1 = 0,
	UITYPE_MAX
}UITYPE;

typedef struct
{
	D3DXVECTOR3 pos;
	UITYPE type;
	bool bUse;
}UI;

void InitUI(void);
void UinitUI(void);
void UpdateUI(void);
void DrawUI(void);
void SetUI(void);

#endif // !_UI_H_
