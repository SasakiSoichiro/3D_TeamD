//====================================================
//
// �A�C�e���\���̏��� [ItemUI.h]
// Author : yabuki yukito
//
//====================================================

#ifndef _ITEMUI_H_
#define _ITEMUI_H_

#include "main.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++
//�}�N����`
//++++++++++++++++++++++++++++++++++++++++++++++++++++
#define MAX_WIDTH (150)  //UI�̉���
#define MAX_HEIGHT (100) //UI�̍���
#define MAX_ITEMTEX (8)      //�e�N�X�`���̐�
#define MAX_ITEMUI (5)     //�A�C�e���̐�

//++++++++++++++++++++++++++++++++++++++++++++++++++++
//�v���g�^�C�v�錾
//++++++++++++++++++++++++++++++++++++++++++++++++++++
void InitItemUI();
void UninitItemUI();
void UpdateItemUI();
void DrawItemUI();
//void SetUI();
//bool GetMinUI();

#endif