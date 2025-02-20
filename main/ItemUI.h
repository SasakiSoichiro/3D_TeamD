//=============================================================================
//
//	�A�C�e�����̏��� [itemUI.h]
// Author : ���X�ؑt��Y
//
//=============================================================================
#ifndef _ITEMUI_H_//���̃}�N����`������Ă��Ȃ�������
#define _ITEMUI_H_//2�d�C���N���[�h�h�~�̃}�N����`
#include "main.h"

typedef enum
{
	ITEM_A = 0,
	ITEM_B,
	ITEM_C,
	ITEM_MAX
}ITEM;

typedef struct
{
	D3DXVECTOR3 pos;	//�ʒu
	D3DXVECTOR3 move;	//����
	float fWidth;		//��
	float fHeight;		//����
	int nType;			//�u���b�N�̃^�C�v
	bool bUse;			//�g�p���Ă��邩�ǂ���
}ItemUI;

static const char* ITEM_TEXTURE[ITEM_MAX] =
{
	"data\\texture\\kenmon.png",		//�u���b�N
	"data\\texture\\blue.JPG",			//�{�^��
	"data\\texture\\mitudomoe.png",		//������
};

//�v���g�^�C�v�錾
void InitItemUI(void);
void UninitItemUI(void);
void UpdateItemUI(void);
void DrawItemUI(void);
#endif