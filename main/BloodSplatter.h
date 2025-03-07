//=============================================================================
//
// �����Ԃ��̏��� [BloodSplatter.h]
// Author : Hirata ryuusei
//
//=============================================================================

#ifndef _BLOODSPLATTER_H_
#define _BLOODSPLATTER_H_

#include "main.h"

//	�t�F�[�h�̏��
typedef enum
{
	UI_NONE = 0,	// �������Ă��Ȃ����
	UI_IN,			// �t�F�[�h�C�����
	UI_OUT,			// �t�F�[�h�A�E�g���
	UI_DRAW,
	UI_MAX
}UI_MODE;

// �����Ԃ��̍\���̒�`
typedef struct
{
	D3DXCOLOR col;
	UI_MODE ui;
	bool bUse;
	int count;
}UI;

// �v���g�^�C�v�錾
void InitBloodSplatter(void);
void UinitBloodSplatter(void);
void UpdateBloodSplatter(void);
void DrawBloodSplatter(void);
void SetBloodSplatter(int count);

#endif // !_UI_H_
