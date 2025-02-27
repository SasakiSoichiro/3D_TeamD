//====================================================
//
// âèúÇÃèàóù [Cancellation.h]
// Author : yabuki yukito
//
//====================================================
#ifndef _CANCELLATION_H_
#define _CANCELLATION_H_

#include "main.h"

typedef enum
{
	TEX_0 = 0,
	TEX_1,
	TEX_MAX
};

typedef struct
{
	D3DXVECTOR3 pos;
	bool bUse;
	float fCnt;
	bool bKeyhave;
	int nType;
}Cance;

static const char* X_TEX[TEX_MAX] =
{
	"data\\texture\\Cancellation.png",
	"data\\texture\\Success.png",
};

void InitCancellation(void);
void UinitCancellation(void);
void UpdateCancellation(void);
void DrawCancellation(void);

#endif // !_Cancellation_H_
