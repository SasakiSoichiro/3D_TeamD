//====================================================
//
// âèúÇÃèàóù [Cancellation.h]
// Author : yabuki yukito
//
//====================================================
#ifndef _CANCELLATION_H_
#define _CANCELLATION_H_

#include "main.h"

typedef struct
{
	D3DXVECTOR3 pos;
	bool bUse;
	float fCnt;
	bool bKeyhave;
}Cance;

void InitCancellation(void);
void UinitCancellation(void);
void UpdateCancellation(void);
void DrawCancellation(void);

#endif // !_Cancellation_H_
