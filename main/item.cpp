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
ITEM g_item[MAX_ITEM] = {};
LPD3DXMESH g_pMeshItem[MAX_ITEM] = { NULL };				//	���_���̃|�C���^�[
LPDIRECT3DTEXTURE9 g_apTextureItem[128] = {};				//	�e�N�X�`���̃|�C���^�[
LPD3DXBUFFER g_pBufferMatItem[MAX_ITEM] = { NULL };			//	�}�e���A���̃|�C���^�[
DWORD g_dwNuMatItem[MAX_ITEM] = { 0 };						//	�}�e���A���̐�

//=================
//	����������
//=================
void Inititem(void)
{
	//	�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	D3DXMATERIAL* pMat;

	//	X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX("data\\model\\key_top.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_pBufferMatItem[0],
		NULL,
		&g_dwNuMatItem[0],
		&g_pMeshItem[0]);

	//	X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX("data\\model\\key_bottom.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_pBufferMatItem[1],
		NULL,
		&g_dwNuMatItem[1],
		&g_pMeshItem[1]);

	//	X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX("data\\model\\key.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_pBufferMatItem[2],
		NULL,
		&g_dwNuMatItem[2],
		&g_pMeshItem[2]);

	//	X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX("data\\model\\naginata.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_pBufferMatItem[3],
		NULL,
		&g_dwNuMatItem[3],
		&g_pMeshItem[3]);

	//	X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX("data\\model\\recovery.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_pBufferMatItem[4],
		NULL,
		&g_dwNuMatItem[4],
		&g_pMeshItem[4]);

	//	X�t�@�C���̓ǂݍ���
	D3DXLoadMeshFromX("data\\model\\pocketwatch000.x",
		D3DXMESH_SYSTEMMEM,
		pDevice,
		NULL,
		&g_pBufferMatItem[5],
		NULL,
		&g_dwNuMatItem[5],
		&g_pMeshItem[5]);

	for (int count = 0; count < MAX_ITEM; count++)
	{
		g_item[count].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_item[count].bUse = false;
		g_item[count].bHave = false;
		g_item[count].bKey_Top = false;
		g_item[count].bKey_bottom = false;

		//	�e�N�X�`���̓ǂݍ���
		pMat = (D3DXMATERIAL*)g_pBufferMatItem[count]->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)g_dwNuMatItem[count]; nCntMat++)
		{
			//	�e�N�X�`���̓ǂݍ���
			if (pMat[nCntMat].pTextureFilename != NULL)
			{
				D3DXCreateTextureFromFile(pDevice,
					pMat[nCntMat].pTextureFilename,
					&g_apTextureItem[nCntMat]);
			}
		}
	}
}

//=================
//	�I������
//=================
void Uninititem(void)
{
	StopSound();

	for (int count = 0; count < MAX_ITEM; count++)
	{
		for (int nCntMat = 0; nCntMat < (int)g_dwNuMatItem[count]; nCntMat++)
		{
			//	�e�N�X�`���̔j��
			if (g_apTextureItem[nCntMat] != NULL)
			{
				g_apTextureItem[nCntMat]->Release();
				g_apTextureItem[nCntMat] = NULL;
			}
		}
	}

	for (int count = 0; count < MAX_ITEM; count++)
	{
		//	���b�V���̔j��
		if (g_pMeshItem[count] != NULL)
		{
			g_pMeshItem[count]->Release();
			g_pMeshItem[count] = NULL;
		}

		//	�}�e���A���̔j��
		if (g_pBufferMatItem[count] != NULL)
		{
			g_pBufferMatItem[count]->Release();
			g_pBufferMatItem[count] = NULL;
		}
	}
}

//=================
//	�X�V����
//=================
void Updateitem(void)
{
	Player* pPlayer = GetPlayer();
	Slow* pSlow = GetSlow();


	for (int nCnt = 0; nCnt < MAX_ITEM; nCnt++)
	{
		if (g_item[nCnt].bUse == true)
		{
			//�v���C���[�̔��a�̎Z�o�p�ϐ�
			float fPRadPos = 28.0f;

			//�A�C�e���̔��a�̎Z�o�p�ϐ�
			float fIRadPos = 28.0f;

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
				if (KeybordTrigger(DIK_F) || JoyPadTrigger(JOYKEY_X) == true)
				{//F�������ꂽ�Ƃ�
					PlaySound(SOUND_LABEL_SHOT02);
					//�A�C�e�����E��
					g_item[nCnt].bHave = true;
					g_item[nCnt].bUse = false;
					
					//	�E�o����
					if (g_item[0].bUse == false)
					{
						g_item[0].bKey_Top = true;
					}
					else if(g_item[1].bUse == false)
					{
						g_item[1].bKey_bottom = true;
					}
				}
			}

			if (KeybordTrigger(DIK_E) == true && g_item[ITEMTYPE_SIX].bHave == true || JoyPadTrigger(JOYKEY_X)==true&& g_item[ITEMTYPE_SIX].bHave == true)
			{//�A�C�e���������Ă��鎞�A�C�e�����g�p���鏈��

				if (pSlow->bUse == false)
				{
					pSlow->bUse = true;
					g_item[ITEMTYPE_SIX].bHave = false;
					SetSlow();
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

	for (int count = 0; count < MAX_ITEM; count++)
	{
		if (g_item[count].bUse == true)
		{
			//	���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&g_item[count].mtxWorld);

			//	�ʒu�̔��f
			D3DXMatrixTranslation(&mtxTrans, g_item[count].pos.x, g_item[count].pos.y, g_item[count].pos.z);
			D3DXMatrixMultiply(&g_item[count].mtxWorld, &g_item[count].mtxWorld, &mtxTrans);

			//	���[���h�}�g���b�N�X�̐ݒ�
			pDevice->SetTransform(D3DTS_WORLD, &g_item[count].mtxWorld);

			//	���݂̃}�e���A����ۑ�
			pDevice->GetMaterial(&matDef);

			//	�}�e���A���f�[�^�ւ̃|�C���^���擾
			pMat = (D3DXMATERIAL*)g_pBufferMatItem[count]->GetBufferPointer();

			for (int nCntMat = 0; nCntMat < (int)g_dwNuMatItem[count]; nCntMat++)
			{
				//	�}�e���A���̐ݒ�
				pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

				//	�e�N�X�`���̐ݒ�
				pDevice->SetTexture(0, g_apTextureItem[nCntMat]);

				//	���f���̕`��
				g_pMeshItem[count]->DrawSubset(nCntMat);
			}
		}
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
void Setitem(D3DXVECTOR3 pos, ITEMTYPE type)
{
	switch (type)
	{
	case ITEMTYPE_ONE:			//	���̏㕔
		g_item[0].bUse = true;
		g_item[0].pos = pos;
		
		break;

	case ITEMTYPE_TWO:			//	���̉���
		g_item[1].bUse = true;
		g_item[1].pos = pos;

		break;

	case ITEMTYPE_THREE:		//	���{��
		g_item[2].bUse = true;
		g_item[2].pos = pos;

		break;

	case ITEMTYPE_FOUR:			//	�Ȃ��Ȃ�
		g_item[3].bUse = true;
		g_item[3].pos = pos;

		break;

	case ITEMTYPE_FIVE:			//	�~�}��
		g_item[4].bUse = true;
		g_item[4].pos = pos;

		break;

	case ITEMTYPE_SIX:			//	�������v
		g_item[5].bUse = true;
		g_item[5].pos = pos;

		break;

	default:
		break;
	}
}