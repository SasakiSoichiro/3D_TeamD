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

typedef enum
{
	BLOODTYPE_RED=0,
	BLOODTYPE_SMALL,
	BLOODTYPE_BIG,
	BLOODTYPE_MAX
}BLOODTYPE;

static const char* UI_TEXTURE[BLOODTYPE_MAX] =
{
	"data\\texture\\hold.jpg",
	"data\\texture\\BloodSplatter.png",	
	"data\\texture\\BloodSplatter1.png",
};

// �����Ԃ��̍\���̒�`
typedef struct
{
	D3DXCOLOR col;
	UI_MODE ui;
	int nType;
	bool bUse;
	int count;
}UI;

// �v���g�^�C�v�錾
void InitBloodSplatter(void);
void UinitBloodSplatter(void);
void UpdateBloodSplatter(void);
void DrawBloodSplatter(void);
void SetBloodSplatter(int count, int nType,UI_MODE uiType);

#endif 
