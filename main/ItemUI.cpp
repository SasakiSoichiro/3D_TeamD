//====================================================
//
// �A�C�e���\���̏��� [ItemUI.cpp]
// Author : yabuki yukito
//
//====================================================

#include "ItemUI.h"
#include "item.h"

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_ItemUiTexture[ITEMUITYPE_MAX] = { };	//Ui�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffItemUi = NULL;	//Ui�o�b�t�@�ւ̃|�C���^
ITEMUI g_ItemUI[ITEMUITYPE_MAX];
bool bHave;

//====================================================
//�A�C�e��UI�\���̏���������
//====================================================
void InitItemUI()
{

	LPDIRECT3DDEVICE9 pDevice;					//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();						//�f�o�C�X�̎擾

	//�e�N�X�`���̓ǂݍ���
	for (int nCnt = 0; nCnt < ITEMUITYPE_MAX; nCnt++)
	{
		D3DXCreateTextureFromFile(pDevice,
			ITEMUI_TEXTURE[nCnt],
			&g_ItemUiTexture[nCnt]);
	}

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * ITEMUITYPE_MAX,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffItemUi, NULL);

	//���_���ւ̃|�C���^
	VERTEX_2D* pVtx;

	//���_�o�b�t�@�̃��b�N�A���_�f�[�^�ւ̃|�C���^�擾
	g_pVtxBuffItemUi->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < ITEMUITYPE_MAX; nCnt++)
	{
		// �\���̕ϐ��̏�����
		g_ItemUI[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_ItemUI[nCnt].fHeight = 0.0f;
		g_ItemUI[nCnt].fWidth = 0.0f;
		g_ItemUI[nCnt].bUse = false;
		bHave = false;

		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		//�e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		pVtx += 4;
	}

	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffItemUi->Unlock();

}
//====================================================
//�A�C�e��UI�\���̏I������
//====================================================
void UninitItemUI()
{

	//�e�N�X�`���̔j��
	for (int nCnt = 0; nCnt < ITEMUITYPE_MAX; nCnt++)
	{
		if (g_ItemUiTexture[nCnt] != NULL)
		{
			g_ItemUiTexture[nCnt]->Release();
			g_ItemUiTexture[nCnt] = NULL;
		}
	}

	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffItemUi != NULL)
	{
		g_pVtxBuffItemUi->Release();
		g_pVtxBuffItemUi = NULL;
	}

}
//====================================================
//�A�C�e��UI�\���̍X�V����
//====================================================
void UpdateItemUI()
{
	// �A�C�e���̎擾����
	ITEM* pItem = Getitem();

	for (int nCnt = 0; nCnt < ITEMUITYPE_MAX; nCnt++, pItem++)
	{
		if (pItem->bKey_Top == true)
		{
			bHave = true;
		}
	}
}
//====================================================
//�A�C�e��UI�\���̕`�揈��
//====================================================
void DrawItemUI()
{
	//�f�o�C�X�ւ̃|�C���^
	LPDIRECT3DDEVICE9 pDevice;

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffItemUi, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int nCnt = 0; nCnt < ITEMUITYPE_MAX; nCnt++)
	{
		int nType = g_ItemUI[nCnt].nType;

		if (g_ItemUI[nCnt].bUse == true)
		{
			if (bHave == true)
			{
				//�e�N�X�`���̐ݒ�
				pDevice->SetTexture(0, g_ItemUiTexture[11]);
			}
			else
			{
				//�e�N�X�`���̐ݒ�
				pDevice->SetTexture(0, g_ItemUiTexture[nType]);
			}
			//�A�C�e��UI�̕`��
			pDevice->DrawPrimitive(
				D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��
				nCnt * 4,//�`�悷��ŏ��̒��_�C���f�b�N�X
				2//�v���~�e�B�u�i�A�C�e��UI�j�̐�
			);
		}
	}
}
//====================================================
//�A�C�e��UI�̐ݒ菈��
//====================================================
void SetItemUI(D3DXVECTOR3 pos, ITEMUITYPE nType, float fWidth, float fHeight)
{
	// ���_���̃|�C���^
	VERTEX_2D* pVtx;

	//���_�o�b�t�@�̃��b�N�A���_�f�[�^�ւ̃|�C���^�擾
	g_pVtxBuffItemUi->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < ITEMUITYPE_MAX; nCnt++)
	{
		if (g_ItemUI[nCnt].bUse == false)
		{// ���g�p��Ԃ�������
			g_ItemUI[nCnt].pos = pos;
			g_ItemUI[nCnt].nType = nType;
			g_ItemUI[nCnt].fHeight = fHeight;
			g_ItemUI[nCnt].fWidth = fWidth;
			g_ItemUI[nCnt].bUse = true;

			//���_���W�̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(g_ItemUI[nCnt].pos.x - fWidth, g_ItemUI[nCnt].pos.y - fHeight, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_ItemUI[nCnt].pos.x + fWidth, g_ItemUI[nCnt].pos.y - fHeight, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_ItemUI[nCnt].pos.x - fWidth, g_ItemUI[nCnt].pos.y + fHeight, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_ItemUI[nCnt].pos.x + fWidth, g_ItemUI[nCnt].pos.y + fHeight, 0.0f);

			break;
		}
		pVtx += 4;
	}

	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffItemUi->Unlock();

}