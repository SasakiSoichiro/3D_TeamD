//=============================================================================
//
//	�u���b�N���� [block.h]
// Author : ���X�ؑt��Y
//
//=============================================================================
#ifndef _BLOCK_H_//���̃}�N����`������Ă��Ȃ�������
#define _BLOCK_H_//2�e�C���N���[�h�h�~�̃}�N����`
#include "main.h"
#include "player.h"
#define BLOCK_TEXTURE (128) //�u���b�N�̃e�N�X�`���̍ő吔
#define NUM_BLOCK (100)		//�u���b�N�̍ő吔

typedef enum
{
	//��1
	BLOCK_HOUSE00_L = 0,		//���ʂ̃u���b�N
	BLOCK_HOUSE00_R,

	////��2
	BLOCK_HOUSE01_L,
	BLOCK_HOUSE01_r,

	////��3
	BLOCK_HOUSE02_L,
	BLOCK_HOUSE02_R,

	////��4
	BLOCK_HOUSE03_L,
	BLOCK_HOUSE03_R,

	////�ԗ��
	BLOCK_IREIHI,

	////�Ŕ�
	BLOCK_KANBAN,

	////��
	BLOCK_KURA,

	////�N���ƃN���̑�
	BLOCK_KUMO,
	BLOCK_KUMONOSU,

	////������
	BLOCK_TORIGOYA,

	////���
	BLOCK_WELL,

	////�d��(�ؐ�)
	BLOCK_WTPOLE,

	////�͂�Ă��
	BLOCK_DEADTREE,

	//�X�s�[�J�[
	BLOCK_SPEACAR,

	//��
	BLOCK_KEY,
	BLOCK_KEYBOTTOM,
	BLOCK_KEYTOP,

	//��
	BLOCK_WALL00,
	BLOCK_WALL01,
	BLOCK_MAX

}BLOCKTYPE;


typedef struct
{
	LPD3DXMESH pMesh;								//���b�V���i���_���)�ւ̃|�C���^
	LPDIRECT3DTEXTURE9 apTexture[BLOCK_TEXTURE];	//�e�N�X�`���ւ̃|�C���^
	LPD3DXBUFFER pBuffMat;							//�}�e���A���ւ̃|�C���^
	DWORD dwNumMat;									//�}�e���A���̐�
	D3DXVECTOR3 vtxMin, vtxMax;						//���f���̍ŏ��l,�ő�l
}BLOCKTEX;


typedef struct
{
	BLOCKTEX tex;						//�e�N�X�`�����
	D3DXVECTOR3 pos;					//�ʒu
	D3DXVECTOR3 rot;					//����
	D3DXMATRIX mtxWorld;				//���[���h�}�g���b�N�X
	int nType;
	bool bUse;

}BLOCK;

static const char* X_BLOCK[BLOCK_MAX] =
{
	//��1��
	"data\\model\\house_L.x",
	"data\\model\\house_R.x",

	//��2��
	"data\\model\\house000_L.x",
	"data\\model\\house000_r.x",

	////��3��
	"data\\model\\house01_L.x",
	"data\\model\\house01_R.x",

	////��4��
	"data\\model\\house04_L.x",
	"data\\model\\house04_R.x",

	////�ԗ��
	"data\\model\\ireihi.x",

	////�Ŕ�
	"data\\model\\kanban.x",

	////��
	"data\\model\\kura.x",

	////�N���A�N���̑�
	"data\\model\\kumo.x",
	"data\\model\\kumonosu.x",

	////������
	"data\\model\\torigoya.x",


	////���
	"data\\model\\Well.x",

	//�d��(�ؐ�)
	"data\\model\\WoodenTelephonePole.x",

	////�͂�Ă��
	"data\\model\\deadtree000.x",

	//�X�s�[�J�[
	"data\\model\\speacar.x",

	//��
	"data\\model\\key.x",
	"data\\model\\key_bottom.x",
	"data\\model\\key_top.x",

	//��
	"data\\model\\wallmaria.x",
	"data\\model\\wallmaria2.x",
};

//�v���g�^�C�v�錾
void InitBlock(void);
void UninitBlock(void);
void UpdateBlock(void);
void DrawBlock(void);
void SetBlock(D3DXVECTOR3 pos, int nType);
void CollisionBlock(D3DXVECTOR3* pPos, D3DXVECTOR3* pPosOld);

#endif