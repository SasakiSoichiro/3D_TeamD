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
	BLOODTYPE_RED=0,
	BLOODTYPE_SMALL,
	BLOODTYPE_BIG,
	BLOODTYPE_MAX
}BLOODTYPE;

static const char* UI_TEXTURE[BLOODTYPE_MAX] =
{
	"data\\texture\\hold.jpg",
	"data\\texture\\BloodSplatter.png",	
	"data\\texture\\BloodSplatter1.png",
};

// 血しぶきの構造体定義
typedef struct
{
	D3DXCOLOR col;
	UI_MODE ui;
	int nType;
	bool bUse;
	int count;
}UI;

// プロトタイプ宣言
void InitBloodSplatter(void);
void UinitBloodSplatter(void);
void UpdateBloodSplatter(void);
void DrawBloodSplatter(void);
void SetBloodSplatter(int count, int nType,UI_MODE uiType);

#endif 
