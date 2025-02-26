//=================================================================
//
//
//
//				���@���@�ā@�ށ@���@���@�I�I
//
//
//
//==================================================================
#include "item.h"
#include "player.h"
#include "input.h"
#include "sound.h"
#include "slow.h"
#include "nannjamo.h"
#include "ItemUI.h"

// �O���[�o���ϐ��錾
ITEM g_item[ITEMTYPE_MAX];
ITEMINFO Iteminfo[ITEMTYPE_MAX]; // ���

//=================
//	����������
//=================
void Inititem(void)
{
	//	�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	

	for (int nCnt = 0; nCnt < ITEMTYPE_MAX; nCnt++)
	{
		//	X�t�@�C���̓ǂݍ���
		D3DXLoadMeshFromX(ITEM_MODEL[nCnt],
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&Iteminfo[nCnt].pBufferMat,
			NULL,
			&Iteminfo[nCnt].dwNuMat,
			&Iteminfo[nCnt].pMesh);
	}

	for (int count = 0; count < ITEMTYPE_MAX; count++)
	{
		g_item[count].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f); // ���W
		g_item[count].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f); // �p�x
		g_item[count].nType = 0; // ���
		g_item[count].bUse = false; // ���g�p����
		g_item[count].bHave = false;
		g_item[count].bOldHave = false;
		g_item[count].bHold = false;

		// �}�e���A���̃|�C���^
		D3DXMATERIAL* pMat;

		//	�}�e���A������
		pMat = (D3DXMATERIAL*)Iteminfo[count].pBufferMat->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)Iteminfo[count].dwNuMat; nCntMat++)
		{
			//	�e�N�X�`���̓ǂݍ���
			if (pMat[nCntMat].pTextureFilename != NULL)
			{
				D3DXCreateTextureFromFile(pDevice,
					pMat[nCntMat].pTextureFilename,
					&Iteminfo[count].pTexture[nCntMat]);
			}
		}
	}
}

//=================
//	�I������
//=================
void Uninititem(void)
{
	//��������
	StopSound();

	for (int count = 0; count < ITEMTYPE_MAX; count++)
	{
		int nType = g_item[count].nType;

		for (int nCntMat = 0; nCntMat < (int)Iteminfo[count].dwNuMat; nCntMat++)
		{
			//	�e�N�X�`���̔j��
			if (Iteminfo[nType].pTexture[nCntMat] != NULL)
			{
				Iteminfo[nType].pTexture[nCntMat]->Release();
				Iteminfo[nType].pTexture[nCntMat] = NULL;
			}
		}
	}

	for (int count = 0; count < ITEMTYPE_MAX; count++)
	{
		//	���b�V���̔j��
		if (Iteminfo[count].pMesh != NULL)
		{
			Iteminfo[count].pMesh->Release();
			Iteminfo[count].pMesh = NULL;
		}

		//	�}�e���A���̔j��
		if (Iteminfo[count].pBufferMat != NULL)
		{
			Iteminfo[count].pBufferMat->Release();
			Iteminfo[count].pBufferMat = NULL;
		}
	}
}

//=================
//	�X�V����
//=================
//void Updateitem(void)
//{
//	Player* pPlayer = GetPlayer();
//	Slow* pSlow = GetSlow();
//
//
//	for (int nCnt = 0; nCnt < MAX_ITEM; nCnt++)
//	{
//		if (g_item[nCnt].bUse == true)
//		{
//			//�v���C���[�̔��a�̎Z�o�p�ϐ�
//			float fPRadPos = 28.0f;
//
//			//�A�C�e���̔��a�̎Z�o�p�ϐ�
//			float fIRadPos = 28.0f;
//
//			//�v����[�̈ʒu���擾
//			D3DXVECTOR3 PlayerPos = GetPlayer()->pos;
//
//			//�A�C�e���̃v���C���[�̋����̍�
//			D3DXVECTOR3 diff = PlayerPos - g_item[nCnt].pos;
//
//			//�͈͌v�Z
//			float fDisX = PlayerPos.x - g_item[nCnt].pos.x;
//			float fDisY = PlayerPos.y - g_item[nCnt].pos.y;
//			float fDisZ = PlayerPos.z - g_item[nCnt].pos.z;
//
//			//��̔��a�����߂�
//			float fRadX = fPRadPos + fIRadPos;
//
//			//�v���C���[���A�C�e���͈̔͂ɓ�������
//			if ((fDisX * fDisX) + (fDisY * fDisY) + (fDisZ * fDisZ) <= (fRadX * fRadX))
//			{
//				if (KeybordTrigger(DIK_F) || JoyPadTrigger(JOYKEY_X) == true)
//				{//F�������ꂽ�Ƃ�
//					PlaySound(SOUND_LABEL_SHOT02);
//					//�A�C�e�����E��
//					g_item[nCnt].bHave = true;
//					g_item[nCnt].bUse = false;
//					
//					//	�E�o����
//					if (g_item[0].bUse == false)
//					{
//						g_item[0].bKey_Top = true;
//					}
//					else if(g_item[1].bUse == false)
//					{
//						g_item[1].bKey_bottom = true;
//					}
//
//					if (g_item[4].bUse == false)
//					{
//						if (pPlayer->nLife <= 2)
//						{
//							pPlayer->nLife += 1;
//						}
//					}
//				}
//			}
//
//			if (KeybordTrigger(DIK_E) == true && g_item[ITEMTYPE_SIX].bHave == true || JoyPadTrigger(JOYKEY_X)==true&& g_item[ITEMTYPE_SIX].bHave == true)
//			{//�A�C�e���������Ă��鎞�A�C�e�����g�p���鏈��
//
//				if (pSlow->bUse == false)
//				{
//					pSlow->bUse = true;
//					g_item[ITEMTYPE_SIX].bHave = false;
//					SetSlow();
//				}
//				
//			}
//		}
//	}
//}

void Updateitem(void)
{
	Player* pPlayer = GetPlayer();
	Slow* pSlow = GetSlow();

	for (int nCnt = 0; nCnt < ITEMTYPE_MAX; nCnt++)
	{
		//�O�񎝂��Ă������̂�ۑ�
		g_item[nCnt].bOldHave = g_item[nCnt].bHave;
		//�A�C�e�����g�p����Ă�����
		if (g_item[nCnt].bUse == true)
		{
			//�v���C���[�̔��a�̎Z�o�p�ϐ�
			float fPRadPos = 50.0f;

			//�A�C�e���̔��a�̎Z�o�p�ϐ�
			float fIRadPos = 50.0f;

			//�v����[�̈ʒu���擾
			D3DXVECTOR3 PlayerPos = GetPlayer()->pos;

			//�A�C�e���̃v���C���[�̋����̍�
			D3DXVECTOR3 diff = PlayerPos - g_item[nCnt].pos;

			//�͈͌v�Z
			float fDisX = PlayerPos.x - g_item[nCnt].pos.x;
			float fDisY = PlayerPos.y - g_item[nCnt].pos.y;
			float fDisZ = PlayerPos.z - g_item[nCnt].pos.z;

			//��̔��a�����߂�
			float fRadX = fPRadPos + fIRadPos;


			//�v���C���[���A�C�e���͈̔͂ɓ�������
			if ((fDisX * fDisX) + (fDisY * fDisY) + (fDisZ * fDisZ) <= (fRadX * fRadX))
			{
				if (KeybordTrigger(DIK_F) == true)
				{//F�������ꂽ�Ƃ�

					PlaySound(SOUND_LABEL_SHOT02);

					//�A�C�e�����E��

					g_item[nCnt].bHave = true;
					g_item[nCnt].bUse = false;
					UpdateItemUI(g_item[nCnt].nType);

					//	�E�o����
					if (g_item[nCnt].bUse == false && g_item[nCnt].nType == ITEMTYPE_ONE)
					{
						g_item[nCnt].bHold = true;
					}

					if (g_item[nCnt].bUse == false && g_item[nCnt].nType == ITEMTYPE_TWO)
					{
						g_item[nCnt].bHold = true;
					}

					//�񕜃A�C�e��
					if (g_item[nCnt].bUse == false)
					{
						//�v���C���[�̗̑͂�2�ȉ��Ȃ�
						if (pPlayer->nLife <= 2)
						{

							pPlayer->nLife += 1;
							SetNannjamo(90);
						}
					}

					if ((KeybordTrigger(DIK_E) == true && g_item[ITEMTYPE_THREE].bHave == true) || (JoyPadTrigger(JOYKEY_X) == true && g_item[ITEMTYPE_THREE].bHave == true))
					{//�������v�������Ă��鎞�A�������v���g�p���鏈��

						if (pSlow->bUse == false)
						{//�������v���g���ĂȂ�������

							pSlow->bUse = true;

							g_item[ITEMTYPE_THREE].bHave = false;

							SetSlow();
						}

					}
				}
			}
		}
	}
}

//=================
//	�`�揈��
//=================
void Drawitem(void)
{
	//	�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//	�v�Z�p
	D3DXMATRIX mtxRot, mtxTrans;
	D3DMATERIAL9 matDef;
	D3DXMATERIAL* pMat;

	for (int count = 0; count < ITEMTYPE_MAX; count++)
	{
		if (g_item[count].bUse == false)
		{// ���g�p��������
			// ���̏�����ʂ��Ȃ��ŃJ�E���g��i�߂�
			continue;
		}

		// ��ނ�ۑ�
		int nType = g_item[count].nType;

		//	���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&g_item[count].mtxWorld);

		//	�����𔽉f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_item[count].rot.y, g_item[count].rot.x, g_item[count].rot.z);
		D3DXMatrixMultiply(&g_item[count].mtxWorld, &g_item[count].mtxWorld, &mtxRot);

		//	�ʒu�̔��f
		D3DXMatrixTranslation(&mtxTrans, g_item[count].pos.x, g_item[count].pos.y, g_item[count].pos.z);
		D3DXMatrixMultiply(&g_item[count].mtxWorld, &g_item[count].mtxWorld, &mtxTrans);

		//	���[���h�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_WORLD, &g_item[count].mtxWorld);

		//	���݂̃}�e���A����ۑ�
		pDevice->GetMaterial(&matDef);

		for (int nCntMat = 0; nCntMat < (int)Iteminfo[nType].dwNuMat; nCntMat++)
		{
			//	�}�e���A���f�[�^�ւ̃|�C���^���擾
			pMat = (D3DXMATERIAL*)Iteminfo[nType].pBufferMat->GetBufferPointer();

			//	�}�e���A���̐ݒ�
			pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

			//	�e�N�X�`���̐ݒ�
			pDevice->SetTexture(0, Iteminfo[nType].pTexture[nCntMat]);

			//	���f���̕`��
			Iteminfo[nType].pMesh->DrawSubset(nCntMat);
		}

		// �}�e���A����߂�
		pDevice->SetMaterial(&matDef);
	}
}

//=================
//	�擾����
//=================
ITEM* Getitem(void)
{
	return &g_item[0];
}

//=================
//	�z�u����
//=================
void Setitem(D3DXVECTOR3 pos, int nType)
{
	for (int nCnt = 0; nCnt < ITEMTYPE_MAX; nCnt++)
	{
		if (g_item[nCnt].bUse == false)
		{
			g_item[nCnt].pos = pos;
			g_item[nCnt].nType = nType;
			g_item[nCnt].bUse = true;
			break;
		}
	}
}