//=============================================================================
//
// 画面点滅の処理 [bloodflash.h]
// Author : Sasaki Soichiro
//
//=============================================================================

#ifndef _BLOODSFLASH_H_
#define _BLOODSFLASH_H_

#include "main.h"
#define DELTA (0.0025f) //変化量

// 画面点滅の構造体定義
typedef struct
{
	D3DXCOLOR col;
	bool bPlus;
	bool bUse;
}BLOODFLASH;

// プロトタイプ宣言
void InitBloodFlash(void);
void UninitBloodFlash(void);
void UpdateBloodFlash(void);
void DrawBloodFlash(void);

#endif 