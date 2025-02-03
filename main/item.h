#pragma once
#ifndef _ITEM_H_
#define _ITEM_H_

#include "main.h"
#define MAX_ITEM (6)

typedef enum
{
	ITEMTYPE_ONE = 0,	//	���̏㕔
	ITEMTYPE_TWO,		//	���̉���
	ITEMTYPE_THREE,		//	��
	ITEMTYPE_FOUR,		//	�Ȃ��Ȃ�
	ITEMTYPE_FIVE,		//	�~�}��
	ITEMTYPE_SIX,		//	�������v
	ITEMTYPE_MAX
}ITEMTYPE;

typedef struct
{
	D3DXVECTOR3 pos;	
	bool bUse;
	bool bHave;
	ITEMTYPE type;
	D3DXMATRIX mtxWorld;
	bool bKey_Top;
	bool bKey_bottom;
}ITEM;

void Inititem(void);
void Uninititem(void);
void Updateitem(void);
void Drawitem(void);
ITEM* Getitem(void);
void Setitem(D3DXVECTOR3 pos, ITEMTYPE type);

#endif // !_ITEM_H_