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

typedef enum
{
	UITYPE_SMALL,
	UITYPE_BIG,
	UITYPE_MAX
}UITYPE;

static const char* UI_TEXTURE[UITYPE_MAX] =
{
	"data\\texture\\BloodSplatter.png",		//鍵(0/2)			0
	"data\\texture\\BloodSplatter1.png",	//鍵(1/2)			1
};

// 血しぶきの構造体定義
typedef struct
{
	D3DXCOLOR col;
	UI_MODE ui;
	UITYPE nType;
	bool bUse;
	int count;
}UI;

// プロトタイプ宣言
void InitBloodSplatter(void);
void UinitBloodSplatter(void);
void UpdateBloodSplatter(void);
void DrawBloodSplatter(void);
void SetBloodSplatter(int count, UITYPE nType);

#endif // !_UI_H_
