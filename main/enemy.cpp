#include "enemy.h"
#include "input.h"
#include "camera.h"
#include "block.h"
#include "score.h"
#include "meshwall.h"
#include "slow.h"
#include "game.h"
#include "fade.h"

#define MAX_ENEMY (36)

Enemy g_Enemy[MAX_ENEMY];
int g_nEIdxShadow;
int nCntTypeState;
int g_nNumEnemy = 0;//�G�̑���
int g_nCntEnemyState = 0;
int g_nIdxEnemyShadow;
int g_nCntPos = 0;
Enemy g_LoadEnemy[3];

//����������
void InitEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		//�e��ϐ��̏�����
		g_Enemy[nCnt].pos = D3DXVECTOR3(0.0f, 10.0f, 0.0f);
		g_Enemy[nCnt].posOld = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Enemy[nCnt].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Enemy[nCnt].rotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Enemy[nCnt].nLife = 360;
		g_Enemy[nCnt].nType = 0;

		g_Enemy[nCnt].bUse = false;

	}

	nCntTypeState = 0;
	g_nNumEnemy = 0;
	for (int nCntType = 0; nCntType < 1; nCntType++)
	{
		LoadEnemy(nCntType);
		g_LoadEnemy[nCntType].nLife = 30;
		D3DXMATERIAL* pMat;//�}�e���A���ւ̃|�C���^

		for (int nCntModel = 0; nCntModel < g_LoadEnemy[nCntType].nNumModel; nCntModel++)
		{
			//�}�e���A���f�[�^�ւ̃|�C���^���擾
			pMat = (D3DXMATERIAL*)g_LoadEnemy[nCntType].aModel[nCntModel].pBuffMat->GetBufferPointer();


			for (int nCntMat = 0; nCntMat < (int)g_LoadEnemy[nCntType].aModel[nCntModel].dwNumMat; nCntMat++)
			{
				if (pMat[nCntMat].pTextureFilename != NULL)
				{//�e�N�X�`���t�@�C�������݂���
						//�e�N�X�`���̓ǂݍ���
					D3DXCreateTextureFromFile(pDevice,
						pMat[nCntMat].pTextureFilename,
						&g_LoadEnemy[nCntType].aModel[nCntModel].apTexture[nCntMat]);
				}
			}
			g_LoadEnemy[nCntType].aModel[nCntModel].Diffuse = pMat->MatD3D.Diffuse;
			g_LoadEnemy[nCntType].aModel[nCntModel].firstDiffuse = g_LoadEnemy[nCntType].aModel[nCntModel].Diffuse;
		}

		//g_nEIdxShadow = SetShadow(g_Enemy[nCntEnemy].pos, g_Enemy[nCntEnemy].rot);

	}
	g_LoadEnemy[0].fRad = 30.01f;

}
void UninitEnemy(void)
{
	for (int nCntType = 0; nCntType < 1; nCntType++)
	{
		for (int nCntModel = 0; nCntModel < g_LoadEnemy[nCntType].nNumModel; nCntModel++)
		{
			if (g_LoadEnemy[nCntType].aModel[nCntModel].pMesh != NULL)
			{
				g_LoadEnemy[nCntType].aModel[nCntModel].pMesh->Release();
				g_LoadEnemy[nCntType].aModel[nCntModel].pMesh = NULL;

			}
		}

		for (int nCntModel = 0; nCntModel < g_LoadEnemy[nCntType].nNumModel; nCntModel++)
		{
			//���_�o�b�t�@�̉��
			if (g_LoadEnemy[nCntType].aModel[nCntModel].pBuffMat != NULL)
			{
				g_LoadEnemy[nCntType].aModel[nCntModel].pBuffMat->Release();
				g_LoadEnemy[nCntType].aModel[nCntModel].pBuffMat = NULL;
			}
		}

	}
}
void UpdateEnemy(void)
{
	Camera* pCamera = GetCamera();
	Player* pPlayer = GetPlayer();
	Slow* pSlow = GetSlow();
	float fAnglemove = 0.0f;

	float fDistanceChase = (g_Enemy[0].pos.x - pPlayer->pos.x) * (g_Enemy[0].pos.x - pPlayer->pos.x) + (g_Enemy[0].pos.y - pPlayer->pos.y) * (g_Enemy[0].pos.y - pPlayer->pos.y) + (g_Enemy[0].pos.z - pPlayer->pos.z) * (g_Enemy[0].pos.z - pPlayer->pos.z);
	D3DXVECTOR3 fRadChaseP(400.0f, 0.0f, 400.0f);
	D3DXVECTOR3 fRadChaseE(400.0f, 0.0f, 400.0f);

	float fRadiusChase = (fRadChaseP.x + fRadChaseE.x) * (fRadChaseP.x + fRadChaseE.x) + (fRadChaseP.y + fRadChaseE.y) * (fRadChaseP.y + fRadChaseE.y) + (fRadChaseP.z + fRadChaseE.z) * (fRadChaseP.z + fRadChaseE.z);

	nCntTypeState++;

	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		//if (g_Enemy[nCntEnemy].nLife <= -1)
		//{
		//	g_Enemy[nCntEnemy].nLife = 0;

		//}
		if (g_Enemy[nCntEnemy].bUse == true)
		{
			switch (g_Enemy[nCntEnemy].State)
			{
			case ENEMYSTATE_NORMAL:
				//�p�j����
				LoiterEnemy();

				if (fDistanceChase <= fRadiusChase)
				{//�G�l�~�[�̎��E���ɓ�������

					//�`�F�C�X���
					g_Enemy[0].State = ENEMYSTATE_CHASE;

				}

				break;

			case ENEMYSTATE_CHASE://�`�F�C�X���

				if (fDistanceChase > fRadiusChase)
				{//���E������O�ꂽ��

					//�p�j���
					g_Enemy[0].State = ENEMYSTATE_NORMAL;

				}

				//�`�F�C�X����
				g_Enemy[0].rotDest.y = atan2f((pPlayer->pos.x - g_Enemy[0].pos.x), (pPlayer->pos.z - g_Enemy[0].pos.z)) + D3DX_PI;
				fAnglemove = atan2f((pPlayer->pos.x - g_Enemy[0].pos.x), (pPlayer->pos.z - g_Enemy[0].pos.z));
				g_Enemy[0].move.x = sinf(fAnglemove) *4.0f;
				g_Enemy[0].move.z = cosf(fAnglemove) *4.0f;
				break;

			case ENEMYSTATE_DAMAGE:
				g_nCntEnemyState--;

				g_Enemy[nCntEnemy].move.x = 0.0f;
				g_Enemy[nCntEnemy].move.z = 0.0f;

				if (g_nCntEnemyState <= 0)
				{
					g_Enemy[nCntEnemy].State = ENEMYSTATE_NORMAL;
				}

				break;
			}

			//���݂̈ʒu��ۑ�
			g_Enemy[nCntEnemy].posOld = g_Enemy[nCntEnemy].pos;

			//�d�͉��Z
			g_Enemy[nCntEnemy].move.y -= GRAVI;

			//�ʒu���X�V
			g_Enemy[nCntEnemy].pos.x += g_Enemy[nCntEnemy].move.x;// * pSlow->fDivi;
			g_Enemy[nCntEnemy].pos.z += g_Enemy[nCntEnemy].move.z;// * pSlow->fDivi;

			//SetPositionGaugeLife(g_Enemy[nCntEnemy].nIdxLife, D3DXVECTOR3(g_Enemy[nCntEnemy].pos.x, g_Enemy[nCntEnemy].pos.y + 40.0f, g_Enemy[nCntEnemy].pos.z));


			float fDistance = (g_Enemy[nCntEnemy].pos.x - pPlayer->pos.x) * (g_Enemy[nCntEnemy].pos.x - pPlayer->pos.x) + (g_Enemy[nCntEnemy].pos.y - pPlayer->pos.y) * (g_Enemy[nCntEnemy].pos.y - pPlayer->pos.y) + (g_Enemy[nCntEnemy].pos.z - pPlayer->pos.z) * (g_Enemy[nCntEnemy].pos.z - pPlayer->pos.z);
			D3DXVECTOR3 fRadP(10.0f, 0.0f, 10.0f);
			D3DXVECTOR3 fRadE(10.0f, 0.0f, 10.0f);


			float fRadius = (fRadP.x + fRadE.x) * (fRadP.x + fRadE.x) + (fRadP.y + fRadE.y) * (fRadP.y + fRadE.y) + (fRadP.z + fRadE.z) * (fRadP.z + fRadE.z);

			//�����蔻��
			if (fDistance <= fRadius && pPlayer->pState == PLAYERSTATE_NORMAL)
			{
				g_Enemy[nCntEnemy].motionType = EMOTIONTYPE_MOVE;
				HitPlayer(1);
			}



			if (g_Enemy[nCntEnemy].rotDest.y - g_Enemy[nCntEnemy].rot.y > D3DX_PI)
			{
				g_Enemy[nCntEnemy].rot.y = g_Enemy[nCntEnemy].rot.y + (D3DX_PI * 2);
			}
			else if (g_Enemy[nCntEnemy].rot.y - g_Enemy[nCntEnemy].rotDest.y > D3DX_PI)
			{
				g_Enemy[nCntEnemy].rot.y = g_Enemy[nCntEnemy].rot.y - (D3DX_PI * 2);
			}

			g_Enemy[nCntEnemy].pos += g_Enemy[nCntEnemy].move * pSlow->fDivi;

			if (g_Enemy[nCntEnemy].pos.y < 0.0f)
			{
				g_Enemy[nCntEnemy].pos.y = 0.0f;
			}

			g_Enemy[nCntEnemy].rot.y += (g_Enemy[nCntEnemy].rotDest.y - g_Enemy[nCntEnemy].rot.y) * 0.2f;

			//CollisionWall(&g_Enemy[nCntEnemy].pos, &g_Enemy[nCntEnemy].posOld);

			//�G���m�̓����蔻��
			CollisionEnemytoEnemy(nCntEnemy);

			//SetPositionShadow(g_Enemy[nCntEnemy].IdxShadow, D3DXVECTOR3(g_Enemy[nCntEnemy].pos.x, 1.0f, g_Enemy[nCntEnemy].pos.z), g_Enemy[nCntEnemy].pos.y);

			if (g_Enemy[nCntEnemy].State != ENEMYSTATE_DAMAGE && pPlayer->pState == PLAYERSTATE_ACTION)
			{
				//CollisionEnemy();

			}

			//SetPositionShadow(g_nEIdxShadow, D3DXVECTOR3(g_Enemy[nCntEnemy].pos.x, 0.1f, g_Enemy[nCntEnemy].pos.z));
		}

		g_Enemy[nCntEnemy].motionType = EMOTIONTYPE_MOVE;

		g_Enemy[nCntEnemy].nNumKey = g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].nNumKey;


		//�S���f��(�p�[�c)�̍X�V
		for (int nCntModel = 0; nCntModel < g_Enemy[nCntEnemy].nNumModel; nCntModel++)
		{
			KEY k_Answer;

			//�L�[��񂩂�ʒu.�������Z�o
			k_Answer.fPosX = (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[(g_Enemy[nCntEnemy].nKey + 1) % g_Enemy[nCntEnemy].nNumKey].aKey[nCntModel].fPosX) - (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].aKey[nCntModel].fPosX);
			k_Answer.fPosY = (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[(g_Enemy[nCntEnemy].nKey + 1) % g_Enemy[nCntEnemy].nNumKey].aKey[nCntModel].fPosY) - (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].aKey[nCntModel].fPosY);
			k_Answer.fPosZ = (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[(g_Enemy[nCntEnemy].nKey + 1) % g_Enemy[nCntEnemy].nNumKey].aKey[nCntModel].fPosZ) - (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].aKey[nCntModel].fPosZ);
			k_Answer.fRotX = (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[(g_Enemy[nCntEnemy].nKey + 1) % g_Enemy[nCntEnemy].nNumKey].aKey[nCntModel].fRotX) - (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].aKey[nCntModel].fRotX);
			k_Answer.fRotY = (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[(g_Enemy[nCntEnemy].nKey + 1) % g_Enemy[nCntEnemy].nNumKey].aKey[nCntModel].fRotY) - (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].aKey[nCntModel].fRotY);
			k_Answer.fRotZ = (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[(g_Enemy[nCntEnemy].nKey + 1) % g_Enemy[nCntEnemy].nNumKey].aKey[nCntModel].fRotZ) - (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].aKey[nCntModel].fRotZ);

			//�p�[�c�̈ʒu.������ݒ�
			//�ʒu
			g_Enemy[nCntEnemy].aModel[nCntModel].pos.x = g_Enemy[nCntEnemy].aModel[nCntModel].posFirst.x + g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].aKey[nCntModel].fPosX + k_Answer.fPosX * (g_Enemy[nCntEnemy].nCntMotion / ((float)g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].nFlame /** pSlow->nMulti*/));//�I�t�Z�b�g�l��
			g_Enemy[nCntEnemy].aModel[nCntModel].pos.y = g_Enemy[nCntEnemy].aModel[nCntModel].posFirst.y + g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].aKey[nCntModel].fPosY + k_Answer.fPosY * (g_Enemy[nCntEnemy].nCntMotion / ((float)g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].nFlame /** pSlow->nMulti*/));
			g_Enemy[nCntEnemy].aModel[nCntModel].pos.z = g_Enemy[nCntEnemy].aModel[nCntModel].posFirst.z + g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].aKey[nCntModel].fPosZ + k_Answer.fPosZ * (g_Enemy[nCntEnemy].nCntMotion / ((float)g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].nFlame /** pSlow->nMulti*/));

			//����
			g_Enemy[nCntEnemy].aModel[nCntModel].rot.x = g_Enemy[nCntEnemy].aModel[nCntModel].rotFirst.x + g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].aKey[nCntModel].fRotX + k_Answer.fRotX * (g_Enemy[nCntEnemy].nCntMotion / ((float)g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].nFlame /** pSlow->nMulti*/));//�I�t�Z�b�g�l��
			g_Enemy[nCntEnemy].aModel[nCntModel].rot.y = g_Enemy[nCntEnemy].aModel[nCntModel].rotFirst.y + g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].aKey[nCntModel].fRotY + k_Answer.fRotY * (g_Enemy[nCntEnemy].nCntMotion / ((float)g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].nFlame /** pSlow->nMulti*/));//�I�t�Z�b�g�l��
			g_Enemy[nCntEnemy].aModel[nCntModel].rot.z = g_Enemy[nCntEnemy].aModel[nCntModel].rotFirst.z + g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].aKey[nCntModel].fRotZ + k_Answer.fRotZ * (g_Enemy[nCntEnemy].nCntMotion / ((float)g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].nFlame/* * pSlow->nMulti*/));//�I�t�Z�b�g�l��

		}
		g_Enemy[nCntEnemy].nCntMotion++;//�Đ��t���[�����ɒB�����猻�݂̃L�[��1�i�߂�

		if (g_Enemy[nCntEnemy].nCntMotion >= (g_Enemy[nCntEnemy].aMotionInfo[g_Enemy[nCntEnemy].motionType].aKeyInfo[g_Enemy[nCntEnemy].nKey].nFlame/* * pSlow->nMulti*/))
		{
			g_Enemy[nCntEnemy].nCntMotion = 0;

			g_Enemy[nCntEnemy].nKey += 1;
			if (g_Enemy[nCntEnemy].nKey >= g_Enemy[nCntEnemy].nNumKey)
			{
				g_Enemy[nCntEnemy].nKey = 0;

			}
		}
	}
}
void DrawEnemy(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();


	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;
	//���݂̃}�e���A���̕ۑ��p
	D3DMATERIAL9 matDef;//���݂̃}�e���A���̕ۑ��p
	D3DXMATERIAL* pMat;//�}�e���A���f�[�^�ւ̃|�C���^


	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_Enemy[nCntEnemy].bUse == true)
		{
			//���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&g_Enemy[nCntEnemy].mtxWorld);
			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Enemy[nCntEnemy].rot.y, g_Enemy[nCntEnemy].rot.x, g_Enemy[nCntEnemy].rot.z);
			D3DXMatrixMultiply(&g_Enemy[nCntEnemy].mtxWorld, &g_Enemy[nCntEnemy].mtxWorld, &mtxRot);

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, g_Enemy[nCntEnemy].pos.x, g_Enemy[nCntEnemy].pos.y, g_Enemy[nCntEnemy].pos.z);
			D3DXMatrixMultiply(&g_Enemy[nCntEnemy].mtxWorld, &g_Enemy[nCntEnemy].mtxWorld, &mtxTrans);

			pDevice->SetTransform(D3DTS_WORLD, &g_Enemy[nCntEnemy].mtxWorld);

			pDevice->GetMaterial(&matDef);
			//�S���f���i�p�[�c�j�̕`��
			for (int nCntModel = 0; nCntModel < g_Enemy[nCntEnemy].nNumModel; nCntModel++)
			{
				//�v�Z�p�}�g���b�N�X
				D3DXMATRIX mtxRotModel, mtxTransModel;
				D3DXMATRIX mtxParent;//�e�̃}�g���b�N�X

				//�p�[�c�̃��[���h�}�g���b�N�X�̏�����
				D3DXMatrixIdentity(&g_Enemy[nCntEnemy].aModel[nCntModel].mtxWorld);

				//�����𔽉f
				D3DXMatrixRotationYawPitchRoll(&mtxRotModel, g_Enemy[nCntEnemy].aModel[nCntModel].rot.y, g_Enemy[nCntEnemy].aModel[nCntModel].rot.x, g_Enemy[nCntEnemy].aModel[nCntModel].rot.z);
				D3DXMatrixMultiply(&g_Enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &g_Enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &mtxRotModel);

				//�ʒu�𔽉f
				D3DXMatrixTranslation(&mtxTransModel, g_Enemy[nCntEnemy].aModel[nCntModel].pos.x, g_Enemy[nCntEnemy].aModel[nCntModel].pos.y, g_Enemy[nCntEnemy].aModel[nCntModel].pos.z);
				D3DXMatrixMultiply(&g_Enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &g_Enemy[nCntEnemy].aModel[nCntModel].mtxWorld, &mtxTransModel);

				//�p�[�c�́u�e�̃}�g���b�N�X�v��ݒ�
				if (g_Enemy[nCntEnemy].aModel[nCntModel].nIdxModelParent != -1)
				{//�e���f��������ꍇ
					mtxParent = g_Enemy[nCntEnemy].aModel[g_Enemy[nCntEnemy].aModel[nCntModel].nIdxModelParent].mtxWorld;

				}
				else
				{
					mtxParent = g_Enemy[nCntEnemy].mtxWorld;
				}

				//�Z�o�����u�p�[�c�̃��[���h�}�g���b�N�X�v�Ɓu�e�̃}�g���b�N�X�v���|�����킹��
				D3DXMatrixMultiply(&g_Enemy[nCntEnemy].aModel[nCntModel].mtxWorld,
					&g_Enemy[nCntEnemy].aModel[nCntModel].mtxWorld,
					&mtxParent);
				//�p�[�c�̃��[���h�}�g���b�N�X�̐ݒ�
				pDevice->SetTransform(D3DTS_WORLD,
					&g_Enemy[nCntEnemy].aModel[nCntModel].mtxWorld);


				//�}�e���A���f�[�^�ւ̃|�C���^���擾
				pMat = (D3DXMATERIAL*)g_Enemy[nCntEnemy].aModel[nCntModel].pBuffMat->GetBufferPointer();

				for (int nCntMat = 0; nCntMat < (int)g_Enemy[nCntEnemy].aModel[nCntModel].dwNumMat; nCntMat++)
				{
					pMat[nCntMat].MatD3D.Diffuse = g_Enemy[nCntEnemy].aModel[nCntModel].Diffuse;

					//�}�e���A���̐ݒ�
					pDevice->SetMaterial(&pMat[nCntMat].MatD3D);
					//�e�N�X�`���̐ݒ�
					pDevice->SetTexture(0, g_Enemy[nCntEnemy].aModel[nCntModel].apTexture[nCntMat]);

					//���f���i�p�[�c�j�̕`��
					g_Enemy[nCntEnemy].aModel[nCntModel].pMesh->DrawSubset(nCntMat);

				}
			}


			pDevice->SetMaterial(&matDef);

		}

	}

}


void SetEnemy(D3DXVECTOR3 pos, int nType)
{
	for (int nCnt = 0; nCnt < MAX_ENEMY; nCnt++)
	{
		if (g_Enemy[nCnt].bUse == false)
		{
			g_Enemy[nCnt] = g_LoadEnemy[nType];
			g_Enemy[nCnt].pos = pos;
			//g_Enemy[nCnt].nIdxLife = SetGaugeLife(g_Enemy[nCnt].pos, g_Enemy[nCnt].rot, g_Enemy[nCnt].nLife);
			//g_Enemy[nCnt].IdxShadow = SetShadow(pos, g_Enemy[nCnt].rot, D3DXVECTOR3(10.0f, 1.0f, 10.0f));
			g_Enemy[nCnt].bUse = true;
			g_nNumEnemy++;//�G�̑���
			break;
		}
	}
}


void LoadEnemy(int nType)
{

	FILE* pFile;
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();
	int nCntModel = 0, nCntParts = 0, nIdx = 0, nParents = 0, nCntKey = 0, nCntMotion = 0;
	int nBool;
	char str[MAX_WORD];

	pFile = fopen("data\\MOTION\\motion1.txt", "r");

	if (pFile != NULL)
	{
		char aString[MAX_WORD];//���������i�[

		while (1)
		{
			//�t�@�C����ǂݍ���
			fscanf(pFile, "%s", &aString[0]);


			if (strcmp(aString, "SCRIPT") == 0)
			{
				while (1)
				{
					//�t�@�C����ǂݍ���
					fscanf(pFile, "%s", &aString[0]);

					if (strcmp(aString, "NUM_MODEL") == 0)
					{
						fscanf(pFile, "%s", &str[0]);
						fscanf(pFile, "%d", &g_LoadEnemy[nType].nNumModel);
						while (nCntModel < g_LoadEnemy[nType].nNumModel)
						{
							//�t�@�C����ǂݍ���
							fscanf(pFile, "%s", &aString[0]);

							if (strcmp(aString, "MODEL_FILENAME") == 0)
							{
								fscanf(pFile, "%s", &str[0]);
								fscanf(pFile, "%s", &aString[0]);

								const char* MODEL_FILE = {};
								MODEL_FILE = aString;

								//x�t�@�C���̓ǂݍ���
								D3DXLoadMeshFromX(MODEL_FILE,
									D3DXMESH_SYSTEMMEM,
									pDevice,
									NULL,
									&g_LoadEnemy[nType].aModel[nCntModel].pBuffMat,
									NULL,
									&g_LoadEnemy[nType].aModel[nCntModel].dwNumMat,
									&g_LoadEnemy[nType].aModel[nCntModel].pMesh);

								if (nCntModel < g_LoadEnemy[nType].nNumModel)
								{
									nCntModel++;
								}
							}
						}
					}

					if (strcmp(aString, "CHARACTERSET") == 0)
					{
						while (1)
						{
							//�t�@�C����ǂݍ���
							fscanf(pFile, "%s", &aString[0]);

							if (strcmp(aString, "NUM_PARTS") == 0)
							{
								fscanf(pFile, "%s", &str[0]);
								fscanf(pFile, "%d", &g_LoadEnemy[nType].nNumModel);

							}
							while (nCntParts < g_LoadEnemy[nType].nNumModel)
							{
								//�t�@�C����ǂݍ���
								fscanf(pFile, "%s", &aString[0]);

								if (strcmp(aString, "PARTSSET") == 0)
								{
									while (1)
									{
										//�t�@�C����ǂݍ���
										fscanf(pFile, "%s", &aString[0]);

										if (strcmp(aString, "INDEX") == 0)
										{
											fscanf(pFile, "%s", &str[0]);
											fscanf(pFile, "%d", &nIdx);
										}
										else if (strcmp(aString, "PARENT") == 0)
										{
											fscanf(pFile, "%s", &str[0]);
											fscanf(pFile, "%d", &g_LoadEnemy[nType].aModel[nIdx].nIdxModelParent);

										}
										else if (strcmp(aString, "POS") == 0)
										{
											fscanf(pFile, "%s", &str[0]);
											fscanf(pFile, "%f", &g_LoadEnemy[nType].aModel[nIdx].pos.x);
											fscanf(pFile, "%f", &g_LoadEnemy[nType].aModel[nIdx].pos.y);
											fscanf(pFile, "%f", &g_LoadEnemy[nType].aModel[nIdx].pos.z);
										}
										else if (strcmp(aString, "ROT") == 0)
										{
											fscanf(pFile, "%s", &str[0]);
											fscanf(pFile, "%f", &g_LoadEnemy[nType].aModel[nIdx].rot.x);
											fscanf(pFile, "%f", &g_LoadEnemy[nType].aModel[nIdx].rot.y);
											fscanf(pFile, "%f", &g_LoadEnemy[nType].aModel[nIdx].rot.z);

										}
										else if (strcmp(aString, "END_PARTSSET") == 0)
										{
											nCntParts++;
											break;
										}
									}

								}

							}
							if (strcmp(aString, "END_CHARACTERSET") == 0)
							{
								break;
							}

						}
					}
					if (strcmp(aString, "MOTIONSET") == 0)
					{
						while (1)
						{
							//�t�@�C����ǂݍ���
							fscanf(pFile, "%s", &aString[0]);

							if (strcmp(aString, "LOOP") == 0)
							{
								fscanf(pFile, "%s", &str[0]);
								fscanf(pFile, "%d", &nBool);
								if (nBool == 0)
								{
									g_LoadEnemy[nType].aMotionInfo[nCntMotion].bLoop = false;
								}
								else
								{
									g_LoadEnemy[nType].aMotionInfo[nCntMotion].bLoop = true;
								}
							}

							if (strcmp(aString, "NUM_KEY") == 0)
							{
								fscanf(pFile, "%s", &str[0]);
								fscanf(pFile, "%d", &g_LoadEnemy[nType].aMotionInfo[nCntMotion].nNumKey);

								while (nCntKey < g_LoadEnemy[nType].aMotionInfo[nCntMotion].nNumKey)
								{
									//�t�@�C����ǂݍ���
									fscanf(pFile, "%s", &aString[0]);

									if (strcmp(aString, "KEYSET") == 0)
									{
										nCntParts = 0;
										while (1)
										{
											//�t�@�C����ǂݍ���
											fscanf(pFile, "%s", &aString[0]);

											if (strcmp(aString, "FRAME") == 0)
											{
												fscanf(pFile, "%s", &str[0]);
												fscanf(pFile, "%d", &g_LoadEnemy[nType].aMotionInfo[nCntMotion].aKeyInfo[nCntKey].nFlame);
												break;
											}
										}

										while (1)
										{
											//�t�@�C����ǂݍ���
											fscanf(pFile, "%s", &aString[0]);

											if (strcmp(aString, "KEY") == 0)
											{
												while (1)
												{
													//�t�@�C����ǂݍ���
													fscanf(pFile, "%s", &aString[0]);

													if (strcmp(aString, "POS") == 0)
													{
														fscanf(pFile, "%s", &str[0]);
														fscanf(pFile, "%f", &g_LoadEnemy[nType].aMotionInfo[nCntMotion].aKeyInfo[nCntKey].aKey[nCntParts].fPosX);
														fscanf(pFile, "%f", &g_LoadEnemy[nType].aMotionInfo[nCntMotion].aKeyInfo[nCntKey].aKey[nCntParts].fPosY);
														fscanf(pFile, "%f", &g_LoadEnemy[nType].aMotionInfo[nCntMotion].aKeyInfo[nCntKey].aKey[nCntParts].fPosZ);
													}
													if (strcmp(aString, "ROT") == 0)
													{
														fscanf(pFile, "%s", &str[0]);
														fscanf(pFile, "%f", &g_LoadEnemy[nType].aMotionInfo[nCntMotion].aKeyInfo[nCntKey].aKey[nCntParts].fRotX);
														fscanf(pFile, "%f", &g_LoadEnemy[nType].aMotionInfo[nCntMotion].aKeyInfo[nCntKey].aKey[nCntParts].fRotY);
														fscanf(pFile, "%f", &g_LoadEnemy[nType].aMotionInfo[nCntMotion].aKeyInfo[nCntKey].aKey[nCntParts].fRotZ);
													}
													if (strcmp(aString, "END_KEY") == 0)
													{
														nCntParts++;
														break;
													}
												}
											}
											if (strcmp(aString, "END_KEYSET") == 0)
											{
												nCntKey++;
												break;
											}

										}
									}


								}

							}

							if (strcmp(aString, "END_MOTIONSET") == 0)
							{
								nCntMotion++;
								nCntKey = 0;
								break;
							}
						}
					}
					if (strcmp(aString, "END_SCRIPT") == 0)
					{
						break;
					}
				}
				break;

			}
		}
	}
	for (int nCnt = 0; nCnt < g_LoadEnemy[nType].nNumModel; nCnt++)
	{
		g_LoadEnemy[nType].aModel[nCnt].posFirst = g_LoadEnemy[nType].aModel[nCnt].pos;
		g_LoadEnemy[nType].aModel[nCnt].rotFirst = g_LoadEnemy[nType].aModel[nCnt].rot;
	}

}


void CollisionEnemy(void)
{
	Player* pPlayer = GetPlayer();
	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{
		if (g_Enemy[nCntEnemy].bUse == true)
		{
			float mtxX = (pPlayer->SwordmtxWorld._41 - pPlayer->motion.aModel[15].mtxWorld._41);
			float mtxY = (pPlayer->SwordmtxWorld._42 - pPlayer->motion.aModel[15].mtxWorld._42);
			float mtxZ = (pPlayer->SwordmtxWorld._43 - pPlayer->motion.aModel[15].mtxWorld._43);
			for (int nCnt = 0; nCnt < 4; nCnt++)
			{
				D3DXVECTOR3 pos;
				pos.x = pPlayer->motion.aModel[15].mtxWorld._41 + mtxX * 0.25f * nCnt;
				pos.y = pPlayer->motion.aModel[15].mtxWorld._42 + mtxY * 0.25f * nCnt;
				pos.z = pPlayer->motion.aModel[15].mtxWorld._43 + mtxZ * 0.25f * nCnt;

				float DistanceX = g_Enemy[nCntEnemy].pos.x - pos.x;
				float DistanceY = g_Enemy[nCntEnemy].pos.y - pos.y;
				float DistanceZ = g_Enemy[nCntEnemy].pos.z - pos.z;

				float fDistance = (DistanceX * DistanceX) + (DistanceY * DistanceY) + (DistanceZ * DistanceZ);

				float fPlayerRad = 20.0f;

				float fRad = g_Enemy[nCntEnemy].fRad + fPlayerRad;
				fRad = fRad * fRad;

				if (fDistance <= fRad && g_Enemy[nCntEnemy].State != ENEMYSTATE_DAMAGE)
				{

				}
			}
		}
	}
}

void HitEnemy(int nCnt, int nDamage)
{
	g_Enemy[nCnt].nLife -= nDamage;

	if (g_Enemy[nCnt].nLife <= 0 && g_Enemy[nCnt].bUse == true)
	{
		//�����̐ݒ�
		g_Enemy[nCnt].bUse = false;
		//EraseGaugeLife(g_Enemy[nCnt].nIdxLife);
		//EraseShadow(g_Enemy[nCnt].IdxShadow);
		AddScore(150);
		g_nNumEnemy--;//�G�̑����J�E���g�_�E��
	}
	else
	{
		g_Enemy[nCnt].State = ENEMYSTATE_DAMAGE;
		g_Enemy[nCnt].move.x = sinf(D3DX_PI) * 80.0f;
		g_Enemy[nCnt].move.z = cosf(D3DX_PI) * 80.0f;
		g_nCntEnemyState = 240;
	}

}
//�G���m�̓����蔻��
void CollisionEnemytoEnemy(int nCnt)
{


	for (int nCntEnemy = 0; nCntEnemy < MAX_ENEMY; nCntEnemy++)
	{

		if (g_Enemy[nCntEnemy].bUse == true && nCnt != nCntEnemy)
		{
			D3DXVECTOR3 pos;


			float fDistance = (g_Enemy[nCntEnemy].pos.x - g_Enemy[nCnt].pos.x) * (g_Enemy[nCntEnemy].pos.x - g_Enemy[nCnt].pos.x) + (g_Enemy[nCntEnemy].pos.y - g_Enemy[nCnt].pos.y) * (g_Enemy[nCntEnemy].pos.y - g_Enemy[nCnt].pos.y) + (g_Enemy[nCntEnemy].pos.z - g_Enemy[nCnt].pos.z) * (g_Enemy[nCntEnemy].pos.z - g_Enemy[nCnt].pos.z);
			D3DXVECTOR3 fRadP(1.0f, 0.0f, 1.0f);
			D3DXVECTOR3 fRadE(1.0f, 0.0f, 1.0f);


			float fRadius = (fRadP.x + fRadE.x) * (fRadP.x + fRadE.x) + (fRadP.y + fRadE.y) * (fRadP.y + fRadE.y) + (fRadP.z + fRadE.z) * (fRadP.z + fRadE.z);

			fRadius = fRadius * fRadius;

			if (fDistance <= fRadius)
			{
				g_Enemy[nCnt].pos = g_Enemy[nCnt].posOld;
			}
		}
	}

}

//==========
// �p�j����
//==========
void LoiterEnemy(void)
{
	D3DXVECTOR3 Turn[POINT_MAX];

	float fAnglemove = 0.0f;

	Turn[0] = D3DXVECTOR3(500.0f, 0.0f, 500.0f);
	Turn[1] = D3DXVECTOR3(500.0f, 0.0f, -500.0f);
	Turn[2] = D3DXVECTOR3(-500.0f, 0.0f, -500.0f);
	Turn[3] = D3DXVECTOR3(-500.0f, 0.0f, 500.0f);

	float fDistance = (g_Enemy[0].pos.x - Turn[g_nCntPos].x) * (g_Enemy[0].pos.x - Turn[g_nCntPos].x) + (g_Enemy[0].pos.y - Turn[g_nCntPos].y) * (g_Enemy[0].pos.y - Turn[g_nCntPos].y) + (g_Enemy[0].pos.z - Turn[g_nCntPos].z) * (g_Enemy[0].pos.z - Turn[g_nCntPos].z);
	D3DXVECTOR3 fRadP(100.0f, 0.0f, 100.0f);
	D3DXVECTOR3 fRadE(100.0f, 0.0f, 100.0f);


	float fRadius = (fRadP.x + fRadE.x) * (fRadP.x + fRadE.x) + (fRadP.y + fRadE.y) * (fRadP.y + fRadE.y) + (fRadP.z + fRadE.z) * (fRadP.z + fRadE.z);


	if (fDistance <= fRadius)
	{//�^�[���n�_�܂ŗ�����

		//���̃^�[���n�_��ݒ�
		g_nCntPos += 1;
		g_nCntPos = g_nCntPos % POINT_MAX;

	}

	g_Enemy[0].rotDest.y = atan2f((Turn[g_nCntPos].x - g_Enemy[0].pos.x), (Turn[g_nCntPos].z - g_Enemy[0].pos.z))+D3DX_PI;
	fAnglemove = atan2f((Turn[g_nCntPos].x - g_Enemy[0].pos.x), (Turn[g_nCntPos].z - g_Enemy[0].pos.z));
	g_Enemy[0].move.x = sinf(fAnglemove) * 1.0f;
	g_Enemy[0].move.z = cosf(fAnglemove) * 1.0f;

}

Enemy* GetEnemy(void)
{
	return &g_Enemy[0];
}
int GetNumEnemy()
{
	return g_nNumEnemy;
}