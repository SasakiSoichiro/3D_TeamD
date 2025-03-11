//=============================================================================
//
// ���q�̏��� [Particle.cpp]
// Author : yabuki yukito
//
//=============================================================================

#include "Particle.h"
#include "effect.h"

//�}�N����`
#define MAX_PARTICLE (128)																//�p�[�e�B�N���̍ő吔

//�O���[�o���ϐ�
Particle g_aParticle[MAX_PARTICLE];														//�p�[�e�B�N���̏��
LPDIRECT3DTEXTURE9 g_pTextureParticle = NULL;											//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffParticle = NULL;										//���_�o�b�t�@�ւ̃|�C���^

//=============================================================================
//���q�̏���������
//=============================================================================
void InitParticle(void)
{
	//�S�p�[�e�B�N����������
	for (int nCnt = 0; nCnt < MAX_PARTICLE; nCnt++)
	{
		g_aParticle[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aParticle[nCnt].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aParticle[nCnt].col = D3DXCOLOR(1.0f, 1.0, 1.0f, 1.0f);
		g_aParticle[nCnt].nLife = 0;
		g_aParticle[nCnt].bUse = false;
	}

}

//=============================================================================
//���q�̏I������
//=============================================================================
void UninitParticle(void)
{

}

//=============================================================================
//���q�̍X�V����
//=============================================================================
void UpdateParticle(void)
{
	for (int nCntParticle = 0; nCntParticle < MAX_PARTICLE; nCntParticle++)
	{

		if (g_aParticle[nCntParticle].bUse == true)
		{
			for (int nCntApper = 0; nCntApper < 3; nCntApper++)
			{
				//�ʒu�X�V
				g_aParticle[nCntParticle].pos += g_aParticle[nCntParticle].move;

				D3DXVECTOR3 pos = g_aParticle[nCntParticle].pos;

				float fAngleX = (float)(rand() % 628 - 314) * 0.01f;
				float fAngleY = (float)(rand() % 628 - 314) * 0.01f;
				float fAngleZ = (float)(rand() % 628 - 314) * 0.01f;

				float fMoveX = (float)(rand() % 10 - 5);
				float fMoveY = (float)(rand() % 10 - 5);
				float fMoveZ = (float)(rand() % 10 - 5);

				g_aParticle[nCntParticle].move.x += sinf(fAngleX) * fMoveX;
				g_aParticle[nCntParticle].move.y += sinf(fAngleY) * fMoveY;
				g_aParticle[nCntParticle].move.z += cosf(fAngleZ) * fMoveZ;

				D3DXVECTOR3 move = g_aParticle[nCntParticle].move;

				D3DXCOLOR col = g_aParticle[nCntParticle].col;

				int nLife = rand() % g_aParticle[nCntParticle].nLife + 60;

				//���C�t�̌���
				g_aParticle[nCntParticle].nLife--;

				if (g_aParticle[nCntParticle].nLife <= 0)
				{
					g_aParticle[nCntParticle].bUse = false;
				}

				SetEffect(pos, move, nLife, col);
			}
		}
	}
}

//=============================================================================
//���q�̕`�揈��
//=============================================================================
void DrawParticle(void)
{

}

//=============================================================================
//���q�̐ݒ菈��
//=============================================================================
void SetParticle(D3DXVECTOR3 pos, D3DXVECTOR3 move, D3DXCOLOR col, int nLife)
{
	for (int nCnt = 0; nCnt < MAX_PARTICLE; nCnt++)
	{
		if (g_aParticle[nCnt].bUse == false)
		{
			g_aParticle[nCnt].pos = pos;
			g_aParticle[nCnt].move = move;
			g_aParticle[nCnt].col = col;
			g_aParticle[nCnt].nLife = nLife;
			g_aParticle[nCnt].bUse = true;
			break;
		}
	}
}
