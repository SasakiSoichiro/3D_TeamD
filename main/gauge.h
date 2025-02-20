#pragma once
#ifndef _GAUGE_H_
#define _GAUGE_H_

#include "main.h"

typedef struct
{
	D3DXVECTOR3 pos;
	bool bUse;
	float fCnt;
	bool bKeyhave;
}Gauge;

void InitGauge(void);
void UinitGauge(void);
void UpdateGauge(void);
void DrawGauge(void);
void SetGauge(D3DXVECTOR3 pos);

#endif // !_GAUGE_H_
