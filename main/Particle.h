//=============================================================================
//
// 粒子の処理 [Particle.h]
// Author : yabuki yukito
//
//=============================================================================

#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "main.h"

//プロトタイプ
void InitParticle(void);
void UninitParticle(void);
void UpdateParticle(void);
void DrawParticle(void);
void SetParticle(D3DXVECTOR3 pos);

#endif