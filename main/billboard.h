//====================================================
//
// �؂̏��� [billboard.h]
// Author : yabuki yukito
//
//====================================================

#ifndef _BILLBOARD_H_
#define _BILLBOARD_H_

#include "main.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++
//�}�N����`
//++++++++++++++++++++++++++++++++++++++++++++++++++++
#define MAX_BILLBOARD (11)

//�A�C�e���̎��
typedef enum
{
	BILLBOARDTYPE_0,
	BILLBOARDTYPE_1,
	BILLBOARDTYPE_2,
	BILLBOARDTYPE_3,
	BILLBOARDTYPE_MAX
}TYPE;

static const char* ITEM_TEXTURE[BILLBOARDTYPE_MAX] =
{
	"data\\texture\\Wood.png",
	"data\\texture\\itembilbord.jpg",
	"data\\texture\\batu.png",
	"data\\texture\\maru.png",

};
//++++++++++++++++++++++++++++++++++++++++++++++++++++
//�A�C�e���̍\����
//++++++++++++++++++++++++++++++++++++++++++++++++++++
typedef struct
{
	D3DXVECTOR3 pos;		//�ʒu
	D3DXVECTOR3 rot;		//����(�p�x)
	D3DXVECTOR3 VtxMaxBillboard;
	D3DXVECTOR3 VtxMinBillboard;
	D3DXMATRIX mtxWorld;	//���[���h�}�g���b�N�X
	TYPE nType;
	bool bDisplay;
	bool bTest;
	bool bUse;				//�g�p���Ă��邩�ǂ���
}Billboard;

//++++++++++++++++++++++++++++++++++++++++++++++++++++
//�v���g�^�C�v�錾
//++++++++++++++++++++++++++++++++++++++++++++++++++++
void InitBillboard();
void UninitBillboard();
void UpdateBillboard();
void DrawBillboard();
void SetBillboard(D3DXVECTOR3 pos, D3DXVECTOR3 dir, TYPE nType, D3DXVECTOR3 size);
#endif