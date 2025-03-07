//=============================================================================
//
// 血しぶきの処理 [BloodSplatter.h]
// Author : Hirata ryuusei
//
//=============================================================================

#ifndef _BLOODSPLATTER_H_
#define _BLOODSPLATTER_H_

#include "main.h"

//	フェードの状態
typedef enum
{
	UI_NONE = 0,	// 何もしていない状態
	UI_IN,			// フェードイン状態
	UI_OUT,			// フェードアウト状態
	UI_DRAW,
	UI_MAX
}UI_MODE;

// 血しぶきの構造体定義
typedef struct
{
	D3DXCOLOR col;
	UI_MODE ui;
	bool bUse;
	int count;
}UI;

// プロトタイプ宣言
void InitBloodSplatter(void);
void UinitBloodSplatter(void);
void UpdateBloodSplatter(void);
void DrawBloodSplatter(void);
void SetBloodSplatter(int count);

#endif // !_UI_H_
