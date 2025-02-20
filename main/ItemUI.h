//=============================================================================
//
//	アイテム持つの処理 [itemUI.h]
// Author : 佐々木奏一郎
//
//=============================================================================
#ifndef _ITEMUI_H_//このマクロ定義がされていなかったら
#define _ITEMUI_H_//2重インクルード防止のマクロ定義
#include "main.h"

typedef enum
{
	ITEM_A = 0,
	ITEM_B,
	ITEM_C,
	ITEM_MAX
}ITEM;

typedef struct
{
	D3DXVECTOR3 pos;	//位置
	D3DXVECTOR3 move;	//動き
	float fWidth;		//幅
	float fHeight;		//高さ
	int nType;			//ブロックのタイプ
	bool bUse;			//使用しているかどうか
}ItemUI;

static const char* ITEM_TEXTURE[ITEM_MAX] =
{
	"data\\texture\\kenmon.png",		//ブロック
	"data\\texture\\blue.JPG",			//ボタン
	"data\\texture\\mitudomoe.png",		//動く壁
};

//プロトタイプ宣言
void InitItemUI(void);
void UninitItemUI(void);
void UpdateItemUI(void);
void DrawItemUI(void);
#endif