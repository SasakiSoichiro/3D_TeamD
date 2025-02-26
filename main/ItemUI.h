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
	ITEM_FLAME = 0,
	ITEM_NAGINATA,
	ITEM_HEAL,
	ITEM_POCKETWATCH,
	ITEM_CAMERAWAKU,
	ITEM_MAX
}ITEMUI;

typedef struct
{
	D3DXVECTOR3 pos;	//�ʒu
	D3DXVECTOR3 move;	//����
	float fWidth;		//��
	float fHeight;		//����
	int nType;			//�u���b�N�̃^�C�v
	bool bUse;			//�g�p���Ă��邩�ǂ���
}ItemUI;

static const char* ITEMUI_TEXTURE[ITEM_MAX] =
{
	"data\\texture\\waku.png",		//�g
	"data\\texture\\naginata.png",	//�㓁
	"data\\texture\\heal.png",		//��
	"data\\texture\\time.png",		//�������v
	"data\\texture\\waku1.png",		//�J�����̘g
};

//�v���g�^�C�v�錾
void InitItemUI(void);
void UninitItemUI(void);
void UpdateItemUI(int nType);
void DrawItemUI(void);
void SetItemUI(D3DXVECTOR3 pos, int nType, float fWidth, float fHeight);
#endif