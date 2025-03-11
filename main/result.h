//=============================================================================
//
//    ���U���g���� [result.h]
//    Author : ���X�ؑt��Y
//
//=============================================================================
#ifndef _RESULT_H_
#define _RESULT_H_

#include "main.h"
#include "game.h"
#include "input.h"

// �\����
typedef struct
{
	D3DXVECTOR3 pos;	// �ʒu
	D3DXCOLOR col;		// �F
	bool bUse;			// �g���Ă邩
	float fHeight;		// ����
	float fWidth;		// ��
}Result;

// �v���g�^�C�v�錾
void InitResult(void);
void UninitResult(void);
void UpdateResult(void);
void DrawResult(void);

#endif // !_RESULT_H_
