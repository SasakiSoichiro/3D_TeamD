//======================================================
//
//		懐中電灯  flashlight.cpp
//		Auther Sasaki Soichiro
//
//======================================================
#ifndef _FLASHLIGHT_H_
#define _FLASHLIGHT_H_

#include "main.h"

#define MAX_FLASH (1)

typedef struct
{
	D3DLIGHT9 light;	//	ライト情報
	bool bLight;
}FLASHLIGHT;

void InitFlashLight(void);
void UninitFlashLight(void);
void UpdateFlashLight(void);
void SetupFlashLight(D3DXVECTOR3 pos);
FLASHLIGHT* GetFlashLight(void);

#endif // !_LIGHT_H_