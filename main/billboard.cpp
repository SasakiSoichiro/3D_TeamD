//====================================================
//
// �؂̏��� [billboard.cpp]
// Author : yabuki yukito
//
//====================================================

#include "billboard.h"
#include "player.h"
#include "item.h"
#include "input.h"
#include "gimmick.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++
// �O���[�o���ϐ��錾
//++++++++++++++++++++++++++++++++++++++++++++++++++++
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBillboard = NULL;					//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureBillboard[BILLBOARDTYPE_MAX] = {};		//�e�N�X�`���ւ̃|�C���^
Billboard g_Billboard[MAX_BILLBOARD];
static float a = 0.0f;
bool bExchange;
bool bNext;
bool bChange;

//====================================================
//�A�C�e���̏���������
//====================================================
void InitBillboard()
{
	LPDIRECT3DDEVICE9 pDevice;			//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();				//�f�o�C�X�̎擾

	//�e�N�X�`���̓ǂݍ���
	for (int nCnt = 0; nCnt < BILLBOARDTYPE_MAX; nCnt++)
	{
		D3DXCreateTextureFromFile(pDevice,
			ITEM_TEXTURE[nCnt],
			&g_pTextureBillboard[nCnt]);
	}

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_BILLBOARD,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBillboard, NULL);

	VERTEX_3D* pVtx = NULL;

	//���_�o�b�t�@�����b�N
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_BILLBOARD; nCnt++)
	{
		//�e�ϐ��̏�����
		g_Billboard[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Billboard[nCnt].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Billboard[nCnt].bTest = false;
		g_Billboard[nCnt].bDisplay = false;
		g_Billboard[nCnt].bUse = false;
		bExchange = false;
		bNext = false;
		bChange = false;

		//���_���̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(-15.0f, 35.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(15.0f, 35.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-15.0f, -35.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(15.0f, -35.0f, 0.0f);

		//�e���_�̖@���̐ݒ�(�x�N�g���̑傫����1�ɂ���)
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

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
	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffBillboard->Unlock();
}

//====================================================
//�A�C�e���̏I������
//====================================================
void UninitBillboard()
{
	//���_�o�b�t�@�̉��
	if (g_pVtxBuffBillboard != NULL)
	{
		g_pVtxBuffBillboard->Release();
		g_pVtxBuffBillboard = NULL;
	}

	for (int nCnt = 0; nCnt < BILLBOARDTYPE_MAX; nCnt++)
	{
		//�e�N�X�`���̔j��
		if (g_pTextureBillboard[nCnt] != NULL)
		{
			g_pTextureBillboard[nCnt]->Release();
			g_pTextureBillboard[nCnt] = NULL;
		}
	}
}

//====================================================
//�A�C�e���̍X�V����
//====================================================
void UpdateBillboard()
{
	VERTEX_3D* pVtx = NULL;

	//���_�o�b�t�@�����b�N
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	Player* pPlayer = GetPlayer();
	ITEM* pItem = Getitem();
	bool isbill = IsBill();
	GIMMICK* pGimick = GetGimmick();
	HOLD* pHold = GetHold();
	
	for (int count = 0; count < MAX_ITEM; count++, pItem++)
	{
		for (int nCnt = 0; nCnt < MAX_BILLBOARD; nCnt++)
		{
		
			if (pItem->bUse == true)
			{

				//�v���C���[�̔��a�̎Z�o�p�ϐ�
				float fPRadPos = 28.0f;

				//�A�C�e���̔��a�̎Z�o�p�ϐ�
				float fIRadPos = 28.0f;

				//�v���C���[�̈ʒu���擾
				D3DXVECTOR3 PlayerPos = GetPlayer()->pos;

				//�A�C�e���̃v���C���[�̋����̍�
				D3DXVECTOR3 diff = PlayerPos - pItem->pos;

				//�͈͌v�Z
				float fDisX = PlayerPos.x - pItem->pos.x;
				float fDisY = PlayerPos.y - pItem->pos.y;
				float fDisZ = PlayerPos.z - pItem->pos.z;

				//��̔��a�����߂�
				float fRadX = fPRadPos + fIRadPos;

				//�v���C���[���A�C�e���͈̔͂ɓ�������
				if ((fDisX * fDisX) + (fDisY * fDisY) + (fDisZ * fDisZ) <= (fRadX * fRadX))
				{

					if (g_Billboard[nCnt].nType == BILLBOARDTYPE_1)
					{

						g_Billboard[nCnt].bUse = true;
						g_Billboard[nCnt].bDisplay = true;
						g_Billboard[nCnt].pos.x = pItem->pos.x;
						g_Billboard[nCnt].pos.y = pItem->pos.y + 10.0f;
						g_Billboard[nCnt].pos.z = pItem->pos.z;

						if (KeybordTrigger(DIK_F) == true)
						{//F�������ꂽ�Ƃ�
							g_Billboard[nCnt].bUse = false;
						}
					}
				}
				else if ((fDisX * fDisX) + (fDisY * fDisY) + (fDisZ * fDisZ) > (fRadX * fRadX))
				{
					g_Billboard[nCnt].bDisplay = false;
				}
			}

			if (pItem->bKey_Top == true)
			{

				if (isbill == true)
				{

					if (g_Billboard[nCnt].nType == BILLBOARDTYPE_3)
					{
						bExchange = true;
						g_Billboard[nCnt].bUse = true;
						g_Billboard[nCnt].bDisplay = true;
					}
				}
				else if (isbill == false)
				{
					bChange = true;
					g_Billboard[nCnt].bUse = false;
					g_Billboard[nCnt].bDisplay = false;
				}
				//�v���C���[�̔��a�̎Z�o�p�ϐ�
				float fPRadPos = 28.0f;
				//�A�C�e���̔��a�̎Z�o�p�ϐ�
				float fIRadPos = 28.0f;
				//�v���C���[�̈ʒu���擾
				D3DXVECTOR3 PlayerPos = GetPlayer()->pos;
				//�A�C�e���̃v���C���[�̋����̍�
				D3DXVECTOR3 diff = PlayerPos - pGimick->pos;
				//�͈͌v�Z
				float fDisX = PlayerPos.x - pGimick->pos.x;
				float fDisY = PlayerPos.y - pGimick->pos.y;
				float fDisZ = PlayerPos.z - pGimick->pos.z;
				//��̔��a�����߂�
				float fRadX = fPRadPos + fIRadPos;
				//�v���C���[���A�C�e���͈̔͂ɓ�������
				if ((fDisX * fDisX) + (fDisY * fDisY) + (fDisZ * fDisZ) <= (fRadX * fRadX))
				{
					if (g_Billboard[nCnt].nType == BILLBOARDTYPE_4)
					{

						g_Billboard[nCnt].bUse = true;
						g_Billboard[nCnt].bDisplay = true;
						bNext = true;
						g_Billboard[nCnt].pos.x = pGimick->pos.x + 10.0f;
						g_Billboard[nCnt].pos.y = pGimick->pos.y + 10.0f;
						g_Billboard[nCnt].pos.z = pGimick->pos.z;

						if (GetKeyboardPress(DIK_F) == true)
						{//F�������ꂽ�Ƃ�
							a += 0.1f;
						}
						else
						{
							a -= 0.01f;
						}
						if (a >= 30.0f)
						{
							a = 10.0f;
						}
						else if (a < 0)
						{
							a = 0.0f;
						}

						pVtx[0].pos = D3DXVECTOR3(-g_Billboard[nCnt].size.x, g_Billboard[nCnt].size.y, g_Billboard[nCnt].size.z);
						pVtx[1].pos = D3DXVECTOR3(g_Billboard[nCnt].size.x * a, g_Billboard[nCnt].size.y, g_Billboard[nCnt].size.z);
						pVtx[2].pos = D3DXVECTOR3(-g_Billboard[nCnt].size.x, -g_Billboard[nCnt].size.y, g_Billboard[nCnt].size.z);
						pVtx[3].pos = D3DXVECTOR3(g_Billboard[nCnt].size.x * a, -g_Billboard[nCnt].size.y, g_Billboard[nCnt].size.z);
					}
				}
				else if ((fDisX * fDisX) + (fDisY * fDisY) + (fDisZ * fDisZ) > (fRadX * fRadX))
				{
					g_Billboard[nCnt].bDisplay = false;
				}

				pVtx += 4;
			}
			else if (pItem->bKey_Top == false)
			{
				if (isbill == true)
				{
					if (g_Billboard[nCnt].nType == BILLBOARDTYPE_2)
					{
						bExchange = false;
						g_Billboard[nCnt].bUse = true;
						g_Billboard[nCnt].bDisplay = true;
					}
				}
			}
		}
	}

		

	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffBillboard->Unlock();
}

//====================================================
//�A�C�e���̕`�揈��
//====================================================
void DrawBillboard()
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	//���C�g�𖳌��ɂ���
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	for (int nCnt = 0; nCnt < MAX_BILLBOARD; nCnt++)
	{
		if (g_Billboard[nCnt].bUse == true&& g_Billboard[nCnt].bDisplay==true)
		{
			//���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&g_Billboard[nCnt].mtxWorld);

			D3DXMATRIX mtxView;
			pDevice->GetTransform(D3DTS_VIEW, &mtxView);

			//�J�����̋t�s����w��
			g_Billboard[nCnt].mtxWorld._11 = mtxView._11;
			g_Billboard[nCnt].mtxWorld._12 = mtxView._21;
			g_Billboard[nCnt].mtxWorld._13 = mtxView._31;
			g_Billboard[nCnt].mtxWorld._21 = mtxView._12;
			g_Billboard[nCnt].mtxWorld._22 = mtxView._22;
			g_Billboard[nCnt].mtxWorld._23 = mtxView._32;
			g_Billboard[nCnt].mtxWorld._31 = mtxView._13;
			g_Billboard[nCnt].mtxWorld._32 = mtxView._23;
			g_Billboard[nCnt].mtxWorld._33 = mtxView._33;

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_Billboard[nCnt].pos.x, g_Billboard[nCnt].pos.y, g_Billboard[nCnt].pos.z);
			D3DXMatrixMultiply(&g_Billboard[nCnt].mtxWorld, &g_Billboard[nCnt].mtxWorld, &mtxTrans);

			//���[���h�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(D3DTS_WORLD, &g_Billboard[nCnt].mtxWorld);

			//���_�o�b�t�@���f�o�C�X�̃f�[�^�X�g���[���ɐݒ�
			pDevice->SetStreamSource(0, g_pVtxBuffBillboard, 0, sizeof(VERTEX_3D));

			if (bExchange == true && bNext == false)
			{
				//�e�N�X�`���̐ݒ�
				pDevice->SetTexture(0, g_pTextureBillboard[3]);
			}
			if (bNext == true && bExchange == false)
			{
				//�e�N�X�`���̐ݒ�
				pDevice->SetTexture(0, g_pTextureBillboard[4]);
			}
			if (bChange == true)
			{
				//�e�N�X�`���̐ݒ�
				pDevice->SetTexture(0, g_pTextureBillboard[2]);
			}
			else
			{
				//�e�N�X�`���̐ݒ�
				pDevice->SetTexture(0, g_pTextureBillboard[g_Billboard[nCnt].nType]);
			}

			//���_�t�H�[�}�b�g
			pDevice->SetFVF(FVF_VERTEX_3D);

			//�A�C�e���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCnt * 4, 2);

		}
	}

	//���C�g��L���ɂ���
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
}

//====================================================
//�A�C�e���̐ݒ菈��
//====================================================
void SetBillboard(D3DXVECTOR3 pos, D3DXVECTOR3 dir, TYPE nType, D3DXVECTOR3 size)
{
	VERTEX_3D* pVtx = NULL;
	LPDIRECT3DDEVICE9 pDevice;							//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();								//�f�o�C�X�̎擾

		//���_�o�b�t�@�����b�N
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_BILLBOARD; nCnt++)
	{
		if (g_Billboard[nCnt].bUse == false)
		{
			g_Billboard[nCnt].pos = pos;				//	�ʒu
			g_Billboard[nCnt].nType = nType;			//	���
			g_Billboard[nCnt].size = size;
			//if (nType == BILLBOARDTYPE_1)
			//{
			//	g_Billboard[nCnt].bUse = false;			//	�g�p���Ă���Ƃ�
			//}
			//else
			//{
				g_Billboard[nCnt].bUse = true;			//	�g�p���Ă���Ƃ�
			//}

			//	���_���̐ݒ�
			pVtx[0].pos = D3DXVECTOR3(-size.x, size.y, size.z);
			pVtx[1].pos = D3DXVECTOR3(size.x, size.y, size.z);
			pVtx[2].pos = D3DXVECTOR3(-size.x, -size.y, size.z);
			pVtx[3].pos = D3DXVECTOR3(size.x, -size.y, size.z);

			break;
		}

		pVtx += 4;
	}

	//���_�o�b�t�@�̃A�����b�N
	g_pVtxBuffBillboard->Unlock();
}
