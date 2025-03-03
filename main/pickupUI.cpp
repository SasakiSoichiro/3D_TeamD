#include "pickupUI.h"

//�O���[�o���ϐ��錾
LPDIRECT3DTEXTURE9 g_pTexturePickUpUI = NULL;//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffPickUpUI = NULL;//���_�o�b�t�@�ւ̃|�C���^
PickUpUI g_aPickUpUI[MAX_BLB];
void InitPickUpUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\time.png",
		&g_pTexturePickUpUI);

	for (int nCnt = 0; nCnt < MAX_BLB; nCnt++)
	{
		//�e��ϐ��̏�����
		g_aPickUpUI[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aPickUpUI[nCnt].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aPickUpUI[nCnt].bUse = false;
	}


	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_BLB,//(sizeof(VERTEX_3D)*�K�v�Ȓ��_��
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffPickUpUI,
		NULL);

	VERTEX_3D* pVtx = 0;//���_���ւ̃|�C���^

//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	g_pVtxBuffPickUpUI->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_BLB; nCnt++)
	{
		pVtx[0].pos = D3DXVECTOR3(-OBJBILL, OBJBILL, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(OBJBILL, OBJBILL, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-OBJBILL, -OBJBILL, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(OBJBILL, -OBJBILL, 0.0f);

		//�e���_�̖@���̐ݒ�
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

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

		pVtx += 4;
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffPickUpUI->Unlock();
}

void UninitPickUpUI(void)
{

	//�e�N�X�`���̔j��
	if (g_pTexturePickUpUI != NULL)
	{
		g_pTexturePickUpUI->Release();
		g_pTexturePickUpUI = NULL;
	}


	//���_�o�b�t�@�̉��
	if (g_pVtxBuffPickUpUI != NULL)
	{
		g_pVtxBuffPickUpUI->Release();
		g_pVtxBuffPickUpUI = NULL;
	}
}
void UpdatePickUpUI(void)
{

}
void DrawPickUpUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();
	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	//���C�g�𖳌��ɂ���
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	for (int nCntPUU = 0; nCntPUU < MAX_BLB; nCntPUU++)
	{
		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_aPickUpUI[nCntPUU].mtxWorld);

		//�r���[�}�g���b�N�X�擾
		D3DXMATRIX mtxView;
		pDevice->GetTransform(D3DTS_VIEW, &mtxView);

		//�J�����̋t�s���ݒ�
		g_aPickUpUI[nCntPUU].mtxWorld._11 = mtxView._11;
		g_aPickUpUI[nCntPUU].mtxWorld._12 = mtxView._21;
		g_aPickUpUI[nCntPUU].mtxWorld._13 = mtxView._31;
		g_aPickUpUI[nCntPUU].mtxWorld._21 = mtxView._12;
		g_aPickUpUI[nCntPUU].mtxWorld._22 = mtxView._22;
		g_aPickUpUI[nCntPUU].mtxWorld._23 = mtxView._32;
		g_aPickUpUI[nCntPUU].mtxWorld._31 = mtxView._13;
		g_aPickUpUI[nCntPUU].mtxWorld._32 = mtxView._23;
		g_aPickUpUI[nCntPUU].mtxWorld._33 = mtxView._33;


		//�ʒu�𔽉f
		D3DXMatrixTranslation(&mtxTrans, g_aPickUpUI[nCntPUU].pos.x, g_aPickUpUI[nCntPUU].pos.y, g_aPickUpUI[nCntPUU].pos.z);
		D3DXMatrixMultiply(&g_aPickUpUI[nCntPUU].mtxWorld, &g_aPickUpUI[nCntPUU].mtxWorld, &mtxTrans);
	}
	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffPickUpUI, 0, sizeof(VERTEX_3D));
	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//���[�v����
	for (int nCntPUU = 0; nCntPUU < MAX_BLB; nCntPUU++)
	{
		if (g_aPickUpUI[nCntPUU].bUse == true)
		{
			pDevice->SetTransform(D3DTS_WORLD, &g_aPickUpUI[nCntPUU].mtxWorld);//for���ɓ����

			//�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, g_pTexturePickUpUI);

			//�|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 4 * nCntPUU, 2);//for���ɓ����
		}
	}

	//���C�g��L���ɖ߂�
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
}

void SetPickUpUI(D3DXVECTOR3 pos, D3DXVECTOR3 dir)
{
	VERTEX_3D* pVtx = 0;		//���_���ւ̃|�C���^
	float rotY = 0.0f;
	int nCntPUU=0;				//�s�b�N�A�b�vUI�̔ԍ�

	//���[�v����
	for (int nCntPUU = 0; nCntPUU < MAX_BLB; nCntPUU++)
	{//�u���b�N�̍ő吔�����[�v����
		if (g_aPickUpUI[nCntPUU].bUse == false)
		{//�u���b�N���g�p����Ă��Ȃ�

			g_aPickUpUI[nCntPUU].pos = pos;			//�u���b�N�̒��_���W����
			g_aPickUpUI[nCntPUU].pos.y = pos.y+20.0f;
			g_aPickUpUI[nCntPUU].bUse = true;		//�g�p���Ă����Ԃɂ���
			break;
		}
	}

	//return nCntPUU;//�s�b�N�A�b�vUI�ԍ�(Index)��Ԃ�
}