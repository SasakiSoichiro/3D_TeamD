//=============================================================================
//
//�@�A�C�e��UI���� [itemUI.cpp]
// �@Author : ���X�ؑt��Y
//
//=============================================================================
#include "itemUI.h"
#include "player.h"
#include "input.h"

#define MAX_ITEMUI (3)
#define ITEMUI_SIZE (60)

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_pTextureItemUI[ITEM_MAX] = {};		//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffItemUI = NULL;		//���_�o�b�t�@�ւ̃|�C���^
ItemUI g_aItemUI[MAX_ITEMUI];							//�u���b�N�̏��

//=====================
//�u���b�N�̏���������
//=====================
void InitItemUI(void)
{
	//���[�J���ϐ�
	LPDIRECT3DDEVICE9 pDevice;	//�f�o�C�X�ւ̃|�C���^
	VERTEX_2D* pVtx = 0;		//���_���ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();
	for (int nCnt = 0; nCnt < ITEM_MAX; nCnt++)
	{
		//�e�N�X�`���̓ǂݍ���
		D3DXCreateTextureFromFile(pDevice,
			ITEM_TEXTURE[nCnt],
			&g_pTextureItemUI[nCnt]);
	}
	//���[�v����
	for (int nCntBlock = 0; nCntBlock < MAX_ITEMUI; nCntBlock++)
	{//�u���b�N�̐������[�v����

		g_aItemUI[nCntBlock].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�ʒu������������
		g_aItemUI[nCntBlock].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//�ړ��l������������
		g_aItemUI[nCntBlock].fWidth = 0.0f;							//��������������
		g_aItemUI[nCntBlock].fHeight = 0.0f;						//����������������
		g_aItemUI[nCntBlock].nType = ITEM_A;						//��ނ�����������
		g_aItemUI[nCntBlock].bUse = false;							//�g���Ă��Ȃ���Ԃɂ���	
	}


	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ITEMUI,//(sizeof(VERTEX_2D)*�K�v�Ȓ��_��
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffItemUI,
		NULL);


	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffItemUI->Lock(0, 0, (void**)&pVtx, 0);

	//���[�v����
	for (int nCntBlock = 0; nCntBlock < MAX_ITEMUI; nCntBlock++)
	{//�u���b�N�̐������[�v����

		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(1000.0f + nCntBlock * ITEMUI_SIZE, 50.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(1000.0f + nCntBlock * ITEMUI_SIZE + ITEMUI_SIZE, 50.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(1000.0f + nCntBlock * ITEMUI_SIZE, 50.0f + ITEMUI_SIZE, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(1000.0f + nCntBlock * ITEMUI_SIZE + ITEMUI_SIZE, 50.0f + ITEMUI_SIZE, 0.0f);

		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//���_�J���[�̐ݒ�@�@�@�@
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;//���_�f�[�^�̃|�C���^��4���W�߂�
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffItemUI->Unlock();
}

//==================
//�u���b�N�̏I������
//==================
void UninitItemUI(void)
{
	for (int nCnt = 0; nCnt < ITEM_MAX; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (g_pTextureItemUI[nCnt] != NULL)
		{
			g_pTextureItemUI[nCnt]->Release();
			g_pTextureItemUI[nCnt] = NULL;
		}
	}

	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffItemUI != NULL)
	{
		g_pVtxBuffItemUI->Release();
		g_pVtxBuffItemUI = NULL;
	}

}

//==================
//�u���b�N�̍X�V����
//==================
void UpdateItemUI(void)
{
	if (KeyboardTrigger(DIK_1) == true)
	{
		for (int nCnt = 0; nCnt < ITEM_MAX; nCnt++)
		{
			if (g_aItemUI[nCnt].nType == ITEM_A)
			{
				g_aItemUI[nCnt].nType = ITEM_B;

				break;
			}
		}
	}
	else if (KeyboardTrigger(DIK_2) == true)
	{
		for (int nCnt = 0; nCnt < ITEM_MAX; nCnt++)
		{
			if (g_aItemUI[nCnt].nType == ITEM_A)
			{
				g_aItemUI[nCnt].nType = ITEM_C;

				break;
			}
		}
	}
}

//==================
//�u���b�N�̕`�揈��
//==================
void DrawItemUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;//�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();
	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffItemUI, 0, sizeof(VERTEX_2D));
	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//���[�v����
	for (int nCntItemUI = 0; nCntItemUI < MAX_ITEMUI; nCntItemUI++)
	{//�u���b�N�̐������[�v����


			//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(ITEM_A, g_pTextureItemUI[g_aItemUI[nCntItemUI].nType]);
		pDevice->SetTexture(ITEM_B, g_pTextureItemUI[g_aItemUI[nCntItemUI].nType]);
		pDevice->SetTexture(ITEM_C, g_pTextureItemUI[g_aItemUI[nCntItemUI].nType]);
		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 4 * nCntItemUI, 2);
	}
}