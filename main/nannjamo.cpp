//==============================================
//
//
//			�Ȃ񂶂��(��)�̂����
//
//
//===============================================
#include "nannjamo.h"
#include "ui.h"
#include "player.h"

//	�O���[�o��
Nannjamo g_nannjamo = {};
//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureNannjamo = NULL;
//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffNannjamo = NULL;

//====================
//	����������
//====================
void InitNannjamo(void)
{
	g_nannjamo.ui = Nannjamo_IN;
	g_nannjamo.col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	g_nannjamo.count = 0;
	g_nannjamo.bUse = false;

	//	�f�o�C�X���̎擾
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\heal1.png",
		&g_pTextureNannjamo);

	//	���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffNannjamo,
		NULL);

	VERTEX_2D* pVtx;
	//	���b�N
	g_pVtxBuffNannjamo->Lock(0, 0, (void**)&pVtx, 0);

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
	pVtx[0].col = D3DXCOLOR(g_nannjamo.col);
	pVtx[1].col = D3DXCOLOR(g_nannjamo.col);
	pVtx[2].col = D3DXCOLOR(g_nannjamo.col);
	pVtx[3].col = D3DXCOLOR(g_nannjamo.col);

	//	�A�����b�N
	g_pVtxBuffNannjamo->Unlock();
}

//====================
//	�I������
//====================
void UinitNannjamo(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureNannjamo != NULL)
	{
		g_pTextureNannjamo->Release();
		g_pTextureNannjamo = NULL;
	}

	//���_�o�b�t�@�̉��
	if (g_pVtxBuffNannjamo != NULL)
	{
		g_pVtxBuffNannjamo->Release();
		g_pVtxBuffNannjamo = NULL;
	}
}

//====================
//	�X�V����
//====================
void UpdateNannjamo(void)
{
	Player* pPlayer = GetPlayer();

	if (g_nannjamo.ui != Nannjamo_NONE)
	{
		if (g_nannjamo.ui == Nannjamo_IN)
		{
			//	�t�F�[�h�C��
			g_nannjamo.col.a -= 0.01f;		//�|���S���������ɂȂ鑬��
			if (g_nannjamo.col.a <= 0.0f)
			{
				g_nannjamo.col.a = 0.0f;
				g_nannjamo.ui = Nannjamo_NONE;		//�������Ă��Ȃ����
			}
		}
		else if (g_nannjamo.ui == Nannjamo_OUT)
		{
			//	�t�F�[�h�A�E�g
			g_nannjamo.col.a += 0.02f;

			if (g_nannjamo.col.a >= 1.0f)
			{
				g_nannjamo.col.a = 1.0f;
				g_nannjamo.ui = Nannjamo_NONE;
			}
		}

		VERTEX_2D* pVtx;
		//	���b�N
		g_pVtxBuffNannjamo->Lock(0, 0, (void**)&pVtx, 0);

		//	���_�J���[
		pVtx[0].col = D3DXCOLOR(g_nannjamo.col);
		pVtx[1].col = D3DXCOLOR(g_nannjamo.col);
		pVtx[2].col = D3DXCOLOR(g_nannjamo.col);
		pVtx[3].col = D3DXCOLOR(g_nannjamo.col);

		//	�A�����b�N
		g_pVtxBuffNannjamo->Unlock();
	}

	if (g_nannjamo.bUse == true)
	{
		g_nannjamo.count--;
	}

	if (g_nannjamo.count <= 0 && g_nannjamo.ui == Nannjamo_NONE && g_nannjamo.bUse == true)
	{
		g_nannjamo.ui = Nannjamo_IN;
		g_nannjamo.bUse = false;
		g_nannjamo.count = 0;
	}
}

//====================
//	�`�揈��
//====================
void DrawNannjamo(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffNannjamo, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	if (g_nannjamo.bUse == true)
	{
		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureNannjamo);

		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	}
}

//====================
//	�z�u����
//====================
void SetNannjamo(int count)
{
	g_nannjamo.ui = Nannjamo_OUT;
	g_nannjamo.count = count;
	g_nannjamo.bUse = true;
}