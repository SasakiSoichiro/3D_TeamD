//=============================================================================
//
//    �����Q�[�W���� [gauge.h]
//    Author : ���X�ؑt��Y
//
//=============================================================================
#ifndef _GAUGE_H_
#define _GAUGE_H_

#include "main.h"


typedef struct
{
	D3DXVECTOR3 pos;
	bool bUse;
	float fCnt;
	float fCnt1;
	bool bKeyhave;
}Gauge;

void InitGauge(void);
void UinitGauge(void);
void UpdateGauge(void);
void DrawGauge(void);
void SetGauge(D3DXVECTOR3 pos);

#endif // !_GAUGE_H_
