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
#define MAX_ITEMTEX (8)      //テクスチャの数
#define MAX_ITEMUI (5)     //アイテムの数

//++++++++++++++++++++++++++++++++++++++++++++++++++++
//プロトタイプ宣言
//++++++++++++++++++++++++++++++++++++++++++++++++++++
void InitItemUI();
void UninitItemUI();
void UpdateItemUI();
void DrawItemUI();
//void SetUI();
//bool GetMinUI();

#endif