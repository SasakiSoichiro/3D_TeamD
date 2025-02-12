//====================================================
//
// �A�C�e���\���̏��� [ItemUI.cpp]
// Author : yabuki yukito
//
//====================================================

#include "ItemUI.h"

//�O���[�o���ϐ�
LPDIRECT3DTEXTURE9 g_ItemUiTexture[MAX_ITEMTEX] = {};	//Ui�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffItemUi = NULL;	//Ui�o�b�t�@�ւ̃|�C���^

//====================================================
//�A�C�e��UI�\���̏���������
//====================================================
void InitItemUI()
{

	LPDIRECT3DDEVICE9 pDevice;					//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();						//�f�o�C�X�̎擾

	//�e�N�X�`���̓ǂݍ���
	//�g
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\waku.png",
		&g_ItemUiTexture[0]);

	//�����d��
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\flashPicture.png",
		&g_ItemUiTexture[1]);

	//�~�}��
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\heal.png",
		&g_ItemUiTexture[2]);

	//�㓁
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\naginata.png",
		&g_ItemUiTexture[3]);

	//�������v
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\time.png",
		&g_ItemUiTexture[4]);

	//���Ȃ�
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\NOkagi.png",
		&g_ItemUiTexture[5]);

	//1/2������
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\YesNoKagi.png",
		&g_ItemUiTexture[6]);

	//��
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\Perfectkagi.png",
		&g_ItemUiTexture[7]);

	//�ʒu�̏�����
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ITEMUI,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffItemUi, NULL);

	//���_���ւ̃|�C���^
	VERTEX_2D* pVtx;

	//���_�o�b�t�@�̃��b�N�A���_�f�[�^�ւ̃|�C���^�擾
	g_pVtxBuffItemUi->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_ITEMUI; nCnt++)
	{
		//�g�p���
		bool bUse = true;

		//���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(1000.0f + nCnt * 55.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(1000.0f + nCnt * 55.0f + 50.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(1000.0f + nCnt * 55.0f, 50.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(1000.0f + nCnt * 55.0f + 50.0f, 50.0f, 0.0f);

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
	for (int nCnt = 0; nCnt < MAX_ITEMTEX; nCnt++)
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

	for (int nCnt = 0; nCnt < MAX_ITEMTEX; nCnt++)
	{
		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_ItemUiTexture[0]);

		//�^�C�}�[�̕`��
		pDevice->DrawPrimitive(
			D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�̎��
			nCnt * 4,//�`�悷��ŏ��̒��_�C���f�b�N�X
			2//�v���~�e�B�u�i�^�C�}�[�j�̐�
		);

	}

}
