//=============================================================================
//
// �X���[���[�V�������� [slow.h]
// Author : ���X�ؑt��Y
//
//=============================================================================
#ifndef _SLOW_H_
#define _SLOW_H_
#include "main.h"

#define SLOW (4);

//�\����
typedef struct
{
	float fMulti;
	float fDivi;
	int nMulti;
	int nDivi;
	bool bUse;
}Slow;

//�v���g�^�C�v�錾
void InitSlow(void);
void SetSlow(void);
Slow*GetSlow(void);

#endif