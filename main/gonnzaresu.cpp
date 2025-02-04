//==============================================
//
//
//			�S���U���X(�����Ԃ�)�̂����
//
//
//===============================================
#include "gonnzaresu.h"
#include "ui.h"
#include "player.h"

//	�O���[�o��
UI g_ui = {};
//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureUI = NULL;
//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffUI = NULL;

//====================
//	����������
//====================
void InitGonzaresu(void)
{
	g_ui.ui = UI_IN;
	g_ui.col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	g_ui.count = 0;
	g_ui.bUse = false;

	//	�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\Gonzaresu.png",
		&g_pTextureUI);

	//	���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffUI,
		NULL);

	VERTEX_2D* pVtx;
	//	���b�N
	g_pVtxBuffUI->Lock(0, 0, (void**)&pVtx, 0);

	//	���_���W�̐ݒ�
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

	//	rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//	tex���W
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//	���_�J���[
	pVtx[0].col = D3DXCOLOR(g_ui.col);
	pVtx[1].col = D3DXCOLOR(g_ui.col);
	pVtx[2].col = D3DXCOLOR(g_ui.col);
	pVtx[3].col = D3DXCOLOR(g_ui.col);

	//	�A�����b�N
	g_pVtxBuffUI->Unlock();
}

//====================
//	�I������
//====================
void UinitGonzaresu(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureUI != NULL)
	{
		g_pTextureUI->Release();
		g_pTextureUI = NULL;
	}

	//���_�o�b�t�@�̉��
	if (g_pVtxBuffUI != NULL)
	{
		g_pVtxBuffUI->Release();
		g_pVtxBuffUI = NULL;
	}
}

//====================
//	�X�V����
//====================
void UpdateGonzaresu(void)
{
	Player* pPlayer = GetPlayer();

	if (g_ui.ui != UI_NONE)
	{
		if (g_ui.ui == UI_IN)
		{
			//	�t�F�[�h�C��
			g_ui.col.a -= 0.01f;		//�|���S���������ɂȂ鑬��
			if (g_ui.col.a <= 0.0f)
			{
				g_ui.col.a = 0.0f;
				g_ui.ui = UI_NONE;		//�������Ă��Ȃ����
			}
		}
		else if (g_ui.ui == UI_OUT)
		{
			//	�t�F�[�h�A�E�g
			g_ui.col.a += 0.02f;

			if (g_ui.col.a >= 1.0f)
			{
				g_ui.col.a = 1.0f;
				g_ui.ui = UI_NONE;
			}
		}

		VERTEX_2D* pVtx;
		//	���b�N
		g_pVtxBuffUI->Lock(0, 0, (void**)&pVtx, 0);

		//	���_�J���[
		pVtx[0].col = D3DXCOLOR(g_ui.col);
		pVtx[1].col = D3DXCOLOR(g_ui.col);
		pVtx[2].col = D3DXCOLOR(g_ui.col);
		pVtx[3].col = D3DXCOLOR(g_ui.col);

		//	�A�����b�N
		g_pVtxBuffUI->Unlock();
	}

	if (g_ui.bUse == true)
	{
		g_ui.count--;
	}

	if (g_ui.count <= 0 && g_ui.ui == UI_NONE && pPlayer->nLife >= 2 && g_ui.bUse == true)
	{
		g_ui.ui = UI_IN;
		g_ui.bUse = false;
		g_ui.count = 0;
	}
	else if (g_ui.count <= 0 && pPlayer->nLife <= 1 && g_ui.bUse == true)
	{
		g_ui.ui = UI_NONE;
		g_ui.count = 0;
	}
}

//====================
//	�`�揈��
//====================
void DrawGonzaresu(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffUI, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	if (g_ui.bUse == true)
	{
		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureUI);

		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	}
}

//====================
//	�z�u����
//====================
void SetGonzaresu(int count)
{
	g_ui.ui = UI_OUT;
	g_ui.count = count;
	g_ui.bUse = true;
}