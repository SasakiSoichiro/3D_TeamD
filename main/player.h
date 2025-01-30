//=============================================================================
//
//	�v���C���[���� [player.h]
// Author : ���X�ؑt��Y
//
//=============================================================================

#ifndef _PLAYER_H_//���̃}�N����`������Ă��Ȃ�������
#define _PLAYER_H_//2�e�C���N���[�h�h�~�̃}�N����`

#include "main.h"
#include "model.h"
#include "motion.h"

#define GRAVI (0.05f)			//�d��
#define JUMP (2.0f)
#define OBJ_P (20.0f)
#define PARTS_MAX (20)
#define USEPARTS_MAX (20)

typedef enum
{
	PLAYERSTATE_NORMAL = 0,
	PLAYERSTATE_DAMAGE,
	PLAYERSTATE_MOVE,
	PLAYERSTATE_JUMP,
	PLAYERSTATE_ACTION,
	PLAYERSTATE_MAX
}PLAYERSTATE;

//�v���C���[�\����
typedef struct
{
	D3DXVECTOR3 pos;
	D3DXVECTOR3 posOld;
	D3DXVECTOR3 size;
	D3DXVECTOR3 move;
	D3DXVECTOR3 rot;
	D3DXVECTOR3 rotDest;
	D3DXVECTOR3 Offpos;
	D3DXMATRIX mtxWorld;//���[���h�}�g���b�N�X
	D3DXMATRIX SwordmtxWorld;
	int nLife;
	int nType;
	PLAYERSTATE pState;
	Motion motion;
}Player;

//�v���g�^�C�v�錾
void InitPlayer(void);
void UninitPlayer(void);
void UpdatePlayer(void);
void DrawPlayer(void);
void SetMatrix(void);
void SetMotion(int nType);
Player* GetPlayer(void);
void ReadScriptPlayer(int nType);
void HitPlayer(int nDamege);

#endif