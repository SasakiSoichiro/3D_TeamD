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
	UITYPE_SMALL,
	UITYPE_BIG,
	UITYPE_MAX
}UITYPE;

static const char* UI_TEXTURE[UITYPE_MAX] =
{
	"data\\texture\\BloodSplatter.png",		//��(0/2)			0
	"data\\texture\\BloodSplatter1.png",	//��(1/2)			1
};

// �����Ԃ��̍\���̒�`
typedef struct
{
	D3DXCOLOR col;
	UI_MODE ui;
	UITYPE nType;
	bool bUse;
	int count;
}UI;

// �v���g�^�C�v�錾
void InitBloodSplatter(void);
void UinitBloodSplatter(void);
void UpdateBloodSplatter(void);
void DrawBloodSplatter(void);
void SetBloodSplatter(int count, UITYPE nType);

#endif // !_UI_H_
