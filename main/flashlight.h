//======================================================
//
//		â˘íÜìdìî  flashlight.cpp
//		Auther Sasaki Soichiro
//
//======================================================
#ifndef _FLASHLIGHT_H_
#define _FLASHLIGHT_H_

#include "main.h"

#define MAX_FLASH (1)

typedef struct
{
	D3DLIGHT9 light;	//	ÉâÉCÉgèÓïÒ
	bool bLight;
}FLASHLIGHT;

void InitFlashLight(void);
void UninitFlashLight(void);
void UpdateFlashLight(void);
FLASHLIGHT* GetFlashLight(void);
void InitFlashGlobal(int nCnt);
void bFlashTRUE(int nCnt);
void bFlashFALSE(int nCnt);

#endif // !_LIGHT_H_