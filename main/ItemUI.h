//====================================================
//
// アイテム表示の処理 [ItemUI.h]
// Author : yabuki yukito
//
//====================================================

#ifndef _ITEMUI_H_
#define _ITEMUI_H_

#include "main.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++
//マクロ定義
//++++++++++++++++++++++++++++++++++++++++++++++++++++
#define MAX_WIDTH (150)  //UIの横幅
#define MAX_HEIGHT (100) //UIの高さ
#define MAX_ITEMUI (20)   //アイテムの数

//++++++++++++++++++++++++++++++++++++++++++++++++++++
//アイテムUIのテクスチャ状態
//++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef enum
{
	ITEMUITYPE_WAKU = 0,	//	枠					0
	ITEMUITYPE_NO1,			//	薙刀(0/1)			1
	ITEMUITYPE_1,			//	薙刀(完成)			2
	ITEMUITYPE_NO2,			//	懐中電灯(0/1)		3
	ITEMUITYPE_2,			//	懐中電灯(完成)		4
	ITEMUITYPE_NO3,			//	救急箱(0/1)			5
	ITEMUITYPE_3,			//	救急箱(完成)		6
	ITEMUITYPE_NO4,			//	懐中時計(0/1)		7
	ITEMUITYPE_4,			//	懐中時計(完成)		8
	ITEMUITYPE_NO5,			//	鍵(0/2)				9
	ITEMUITYPE_YESNO5,		//	鍵(1/2)				10
	ITEMUITYPE_5,			//	鍵(完成)			11
	ITEMUITYPE_MAX
}ITEMUITYPE;

static const char* ITEMUI_TEXTURE[ITEMUITYPE_MAX] =
{
	"data\\texture\\waku.png",				//枠				0
	"data\\texture\\NOnaginata.png",		//薙刀(0/1)			1
	"data\\texture\\naginata.png",			//薙刀(完成)		2
	"data\\texture\\NOflashPicture.png",	//懐中電灯(0/1)		3 
	"data\\texture\\flashPicture.png",		//懐中電灯(完成)	4
	"data\\texture\\NOheal.png",			//救急箱(0/1)		5
	"data\\texture\\heal.png",				//救急箱(完成)		6
	"data\\texture\\NOtime.png",			//懐中時計(0/1)		7
	"data\\texture\\time.png",				//懐中時計(完成)	8
	"data\\texture\\NOkagi.png",			//鍵(0/2)			9
	"data\\texture\\YesNoKagi.png",			//鍵(1/2)			10
	"data\\texture\\Perfectkagi.png",		//鍵(完成)			11
};

//++++++++++++++++++++++++++++++++++++++++++++++++++++
//アイテムUIの構造体
//++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef struct
{
	D3DXVECTOR3 pos;
	ITEMUITYPE nType;
	bool bUse;
	float fWidth; // 横幅
	float fHeight;// 高さ
}ITEMUI;
//++++++++++++++++++++++++++++++++++++++++++++++++++++
//プロトタイプ宣言
//++++++++++++++++++++++++++++++++++++++++++++++++++++
void InitItemUI();
void UninitItemUI();
void UpdateItemUI();
void DrawItemUI();
void SetItemUI(D3DXVECTOR3 pos, ITEMUITYPE nType, float fWidth, float fHeight);
//bool GetMinUI();

#endif