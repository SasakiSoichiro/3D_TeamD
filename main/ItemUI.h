//====================================================
//
// ACe\¦Ì [ItemUI.h]
// Author : yabuki yukito
//
//====================================================

#ifndef _ITEMUI_H_
#define _ITEMUI_H_

#include "main.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++
//}Nè`
//++++++++++++++++++++++++++++++++++++++++++++++++++++
#define MAX_WIDTH (150)  //UIÌ¡
#define MAX_HEIGHT (100) //UIÌ³
#define MAX_ITEMUI (20)   //ACeÌ

//++++++++++++++++++++++++++++++++++++++++++++++++++++
//ACeUIÌeNX`óÔ
//++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef enum
{
	ITEMUITYPE_WAKU = 0,	//	g					0
	ITEMUITYPE_NO1,			//	ã(0/1)			1
	ITEMUITYPE_1,			//	ã(®¬)			2
	ITEMUITYPE_NO2,			//	ùd(0/1)		3
	ITEMUITYPE_2,			//	ùd(®¬)		4
	ITEMUITYPE_NO3,			//	~} (0/1)			5
	ITEMUITYPE_3,			//	~} (®¬)		6
	ITEMUITYPE_NO4,			//	ùv(0/1)		7
	ITEMUITYPE_4,			//	ùv(®¬)		8
	ITEMUITYPE_NO5,			//	®(0/2)				9
	ITEMUITYPE_YESNO5,		//	®(1/2)				10
	ITEMUITYPE_5,			//	®(®¬)			11
	ITEMUITYPE_MAX
}ITEMUITYPE;

static const char* ITEMUI_TEXTURE[ITEMUITYPE_MAX] =
{
	"data\\texture\\waku.png",				//g				0
	"data\\texture\\NOnaginata.png",		//ã(0/1)			1
	"data\\texture\\naginata.png",			//ã(®¬)		2
	"data\\texture\\NOflashPicture.png",	//ùd(0/1)		3 
	"data\\texture\\flashPicture.png",		//ùd(®¬)	4
	"data\\texture\\NOheal.png",			//~} (0/1)		5
	"data\\texture\\heal.png",				//~} (®¬)		6
	"data\\texture\\NOtime.png",			//ùv(0/1)		7
	"data\\texture\\time.png",				//ùv(®¬)	8
	"data\\texture\\NOkagi.png",			//®(0/2)			9
	"data\\texture\\YesNoKagi.png",			//®(1/2)			10
	"data\\texture\\Perfectkagi.png",		//®(®¬)			11
};

//++++++++++++++++++++++++++++++++++++++++++++++++++++
//ACeUIÌ\¢Ì
//++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef struct
{
	D3DXVECTOR3 pos;
	ITEMUITYPE nType;
	bool bUse;
	float fWidth; // ¡
	float fHeight;// ³
}ITEMUI;
//++++++++++++++++++++++++++++++++++++++++++++++++++++
//vg^Cvé¾
//++++++++++++++++++++++++++++++++++++++++++++++++++++
void InitItemUI();
void UninitItemUI();
void UpdateItemUI();
void DrawItemUI();
void SetItemUI(D3DXVECTOR3 pos, ITEMUITYPE nType, float fWidth, float fHeight);
//bool GetMinUI();

#endif