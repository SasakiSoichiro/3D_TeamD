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
	ITEM_FLAME = 0,
	ITEM_NAGINATA,
	ITEM_HEAL,
	ITEM_POCKETWATCH,
	ITEM_CAMERAWAKU,
	ITEM_MAX
}ITEMUI;

typedef struct
{
	D3DXVECTOR3 pos;	//位置
	D3DXVECTOR3 move;	//動き
	float fWidth;		//幅
	float fHeight;		//高さ
	int nType;			//ブロックのタイプ
	bool bUse;			//使用しているかどうか
}ItemUI;

static const char* ITEMUI_TEXTURE[ITEM_MAX] =
{
	"data\\texture\\waku.png",		//枠
	"data\\texture\\naginata.png",	//薙刀
	"data\\texture\\heal.png",		//回復
	"data\\texture\\time.png",		//懐中時計
	"data\\texture\\waku1.png",		//カメラの枠
};

//プロトタイプ宣言
void InitItemUI(void);
void UninitItemUI(void);
void UpdateItemUI(int nType);
void DrawItemUI(void);
void SetItemUI(D3DXVECTOR3 pos, int nType, float fWidth, float fHeight);
#endif