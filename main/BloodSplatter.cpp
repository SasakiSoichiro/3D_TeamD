//=============================================================================
//
// �����Ԃ��̏��� [BloodSplatter.cpp]
// Author : Hirata ryuusei
//
//=============================================================================

#include "BloodSplatter.h"
#include "ui.h"
#include "player.h"
#include "item.h"

// �O���[�o���ϐ�

// �e�N�X�`���ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureUI[UITYPE_MAX] = {};

// ���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffUI = NULL;

UI g_ui[UITYPE_MAX] = {};

//====================
//	����������
//====================
void InitBloodSplatter(void)
{
	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		g_ui[nCnt].ui = UI_IN;
		g_ui[nCnt].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		g_ui[nCnt].count = 0;
		g_ui[nCnt].bUse = false;
	}

	// �f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		D3DXCreateTextureFromFile(pDevice,
			UI_TEXTURE[nCnt],
			&g_pTextureUI[nCnt]);
	}

	// ���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * UITYPE_MAX,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffUI,
		NULL);

	VERTEX_2D* pVtx;

	// ���b�N
	g_pVtxBuffUI->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		// ���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

		// rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		// tex���W
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		// ���_�J���[
		pVtx[0].col = D3DXCOLOR(g_ui[nCnt].col);
		pVtx[1].col = D3DXCOLOR(g_ui[nCnt].col);
		pVtx[2].col = D3DXCOLOR(g_ui[nCnt].col);
		pVtx[3].col = D3DXCOLOR(g_ui[nCnt].col);

		pVtx += 4;
	}

	// �A�����b�N
	g_pVtxBuffUI->Unlock();
}

//====================
//	�I������
//====================
void UinitBloodSplatter(void)
{
	// �e�N�X�`���̔j��
	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		if (g_pTextureUI[nCnt] != NULL)
		{
			g_pTextureUI[nCnt]->Release();
			g_pTextureUI[nCnt] = NULL;
		}
	}

	// ���_�o�b�t�@�̉��
	if (g_pVtxBuffUI != NULL)
	{
		g_pVtxBuffUI->Release();
		g_pVtxBuffUI = NULL;
	}
}

//====================
//	�X�V����
//====================
void UpdateBloodSplatter(void)
{
	Player* pPlayer = GetPlayer();
	ITEM* pItem = Getitem();
	bool bNeed = IsNeed();

	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		if (g_ui[nCnt].ui != UI_NONE)
		{
			if (g_ui[nCnt].ui == UI_IN)
			{
				// �t�F�[�h�C��
				g_ui[nCnt].col.a -= 0.01f;		// �|���S���������ɂȂ鑬��
				if (g_ui[nCnt].col.a <= 0.0f)
				{
					g_ui[nCnt].col.a = 0.0f;
					g_ui[nCnt].ui = UI_NONE;		// �������Ă��Ȃ����
				}
			}
			else if (g_ui[nCnt].ui == UI_OUT)
			{
				// �t�F�[�h�A�E�g
				g_ui[nCnt].col.a += 0.02f;

				if (g_ui[nCnt].col.a >= 1.0f)
				{
					g_ui[nCnt].col.a = 1.0f;
					g_ui[nCnt].ui = UI_NONE;
				}
			}

			VERTEX_2D* pVtx;

			// ���b�N
			g_pVtxBuffUI->Lock(0, 0, (void**)&pVtx, 0);

			// ���_�J���[
			pVtx[0].col = D3DXCOLOR(g_ui[nCnt].col);
			pVtx[1].col = D3DXCOLOR(g_ui[nCnt].col);
			pVtx[2].col = D3DXCOLOR(g_ui[nCnt].col);
			pVtx[3].col = D3DXCOLOR(g_ui[nCnt].col);

			pVtx += 4;

			// �A�����b�N
			g_pVtxBuffUI->Unlock();
		}

		if (g_ui[nCnt].bUse == true)
		{
			g_ui[nCnt].count--;			// �f�N�������g
		}

		if (g_ui[nCnt].count <= 0 && pPlayer->nLife >= 2 && g_ui[nCnt].bUse == true)
		{
			g_ui[nCnt].ui = UI_NONE;		// �t�F�[�h�C�����
			g_ui[nCnt].count = 0;
		}
		else if (g_ui[nCnt].count <= 0 && pPlayer->nLife <= 1 && g_ui[nCnt].bUse == true)
		{
			g_ui[nCnt].ui = UI_NONE;		// �������Ă��Ȃ����
			g_ui[nCnt].count = 0;
		}
		if (pPlayer->nLife >= 3)
		{
			g_ui[nCnt].bUse = false;	// �\������Ă��Ȃ��Ƃ�
			g_ui[nCnt].ui = UI_IN;		// �t�F�[�h�C�����
			g_ui[nCnt].count = 0;
		}
	}
}

//====================
//	�`�揈��
//====================
void DrawBloodSplatter(void)
{
	// �f�o�C�X�ւ̃|�C���^�A��Ԏ擾
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	Player* pPlayer = GetPlayer();

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffUI, 0, sizeof(VERTEX_2D));

	// ���_�t�H�[�}�b�g�ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		if (g_ui[nCnt].bUse == true)
		{// �e�N�X�`���̐ݒ�

			if (g_ui[nCnt].count <= 0 && pPlayer->nLife >= 2 && g_ui[nCnt].bUse == true)
			{
				pDevice->SetTexture(0, g_pTextureUI[1]);
			}
			else if (g_ui[nCnt].count <= 0 && pPlayer->nLife <= 1 && g_ui[nCnt].bUse == true)
			{
				pDevice->SetTexture(0, g_pTextureUI[0]);
			}
		}
	}
	// �|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

}

//====================
//	�z�u����
//====================
void SetBloodSplatter(int count, UITYPE nType)
{
	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		if (g_ui[nCnt].bUse == false)
		{
			g_ui[nCnt].ui = UI_OUT;		// �t�F�[�h�A�E�g���
			g_ui[nCnt].count = count;
			g_ui[nCnt].nType = nType;
			g_ui[nCnt].bUse = true;		// �\������Ă���Ƃ�
			break;
		}
	}
}