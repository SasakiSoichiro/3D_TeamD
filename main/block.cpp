//====================================================
//
// �u���b�N�̏��� [block.cpp]
// Author : yabuki yukito
//
//====================================================
#include "block.h"
//�O���[�o���ϐ��錾
BLOCK g_Block[NUM_BLOCK];
BLOCKTEX g_BlockTex[BLOCK_MAX];
//����������
void InitBlock(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	pDevice = GetDevice();

	for (int nCnt = 0; nCnt < NUM_BLOCK; nCnt++)
	{
		//�e��ϐ��̏�����
		g_Block[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Block[nCnt].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Block[nCnt].nType = BLOCK_HOUSE00_L;
		g_Block[nCnt].bUse = false;
	}


	for (int nCnt = 0; nCnt < BLOCK_MAX; nCnt++)
	{
		//x�t�@�C���̓ǂݍ���
		D3DXLoadMeshFromX(X_BLOCK[nCnt],
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&g_BlockTex[nCnt].pBuffMat,
			NULL,
			&g_BlockTex[nCnt].dwNumMat,
			&g_BlockTex[nCnt].pMesh);
	}

	int nNumVtx=0;//���_��
	DWORD sizeFVF;//���_�t�H�[�}�b�g�̃T�C�Y
	BYTE* pVtxBuff;//���_�o�b�t�@�ւ̃|�C���^

	//���_���̎擾
	for (int nCnt = 0; nCnt < BLOCK_MAX; nCnt++)
	{

		nNumVtx = g_BlockTex[nCnt].pMesh->GetNumVertices();
		sizeFVF = D3DXGetFVFVertexSize(g_BlockTex[nCnt].pMesh->GetFVF());
		//���_�o�b�t�@�̃��b�N
		g_BlockTex[nCnt].pMesh->LockVertexBuffer(D3DLOCK_READONLY, (void**)&pVtxBuff);
		
		for (int nCntVtx = 0; nCntVtx < nNumVtx; nCntVtx++)
		{
			//���_���W�̑��
			D3DXVECTOR3 vtx = *(D3DXVECTOR3*)pVtxBuff;

			//���_���W���r���ă��f���̍ŏ��l�ő�l���擾
			//X============================
			if (vtx.x > g_BlockTex[nCnt].vtxMax.x)
			{
				g_BlockTex[nCnt].vtxMax.x = vtx.x;
			}

			if (vtx.x < g_BlockTex[nCnt].vtxMin.x)
			{
				g_BlockTex[nCnt].vtxMin.x = vtx.x;
			}
			//Y============================
			if (vtx.y > g_BlockTex[nCnt].vtxMax.y)
			{
				g_BlockTex[nCnt].vtxMax.y = vtx.y;
			}

			if (vtx.y < g_BlockTex[nCnt].vtxMin.y)
			{
				g_BlockTex[nCnt].vtxMin.y = vtx.y;
			}
			//Z=============================
			if (vtx.z > g_BlockTex[nCnt].vtxMax.z)
			{
				g_BlockTex[nCnt].vtxMax.z = vtx.z;
			}

			if (vtx.z < g_BlockTex[nCnt].vtxMin.z)
			{
				g_BlockTex[nCnt].vtxMin.z = vtx.z;
			}

			//���_�t�H�[�}�b�g�̃T�C�Y���|�C���^��i�߂�
			pVtxBuff += sizeFVF;
		}
		//���_�o�b�t�@�̃A�����b�N
		g_BlockTex[nCnt].pMesh->UnlockVertexBuffer();

		D3DXMATERIAL* pMat;//�}�e���A���ւ̃|�C���^

		//�}�e���A���f�[�^�ւ̃|�C���^���擾
		pMat = (D3DXMATERIAL*)g_BlockTex[nCnt].pBuffMat->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)g_BlockTex[nCnt].dwNumMat; nCntMat++)
		{
			if (pMat[nCntMat].pTextureFilename != NULL)
			{//�e�N�X�`���t�@�C�������݂���
					//�e�N�X�`���̓ǂݍ���
				D3DXCreateTextureFromFile(pDevice,
					pMat[nCntMat].pTextureFilename,
					&g_BlockTex[nCnt].apTexture[nCntMat]);
			}
		}

	}
}
void UninitBlock(void)
{
	for (int nCntTex = 0; nCntTex < BLOCK_MAX; nCntTex++)
	{

		for (int nCntTexture = 0; nCntTexture < BLOCK_TEXTURE; nCntTexture++)
		{
			if (g_BlockTex[nCntTex].apTexture[nCntTexture] != NULL)
			{
				g_BlockTex[nCntTex].apTexture[nCntTexture]->Release();
				g_BlockTex[nCntTex].apTexture[nCntTexture] = NULL;

			}
		}
		if (g_BlockTex[nCntTex].pMesh != NULL)
		{
			g_BlockTex[nCntTex].pMesh->Release();
			g_BlockTex[nCntTex].pMesh = NULL;

		}
		//���_�o�b�t�@�̉��
		if (g_BlockTex[nCntTex].pBuffMat != NULL)
		{
			g_BlockTex[nCntTex].pBuffMat->Release();
			g_BlockTex[nCntTex].pBuffMat = NULL;
		}

	}
	for (int nCntEdit = 0; nCntEdit < NUM_BLOCK; nCntEdit++)
	{

		for (int nCntTexture = 0; nCntTexture < BLOCK_TEXTURE; nCntTexture++)
		{
			if (g_Block[nCntEdit].tex.apTexture[nCntTexture] != NULL)
			{
				g_Block[nCntEdit].tex.apTexture[nCntTexture] = NULL;

			}
		}

		if (g_Block[nCntEdit].tex.pMesh != NULL)
		{
			g_Block[nCntEdit].tex.pMesh = NULL;

		}
		//���_�o�b�t�@�̉��
		if (g_Block[nCntEdit].tex.pBuffMat != NULL)
		{
			g_Block[nCntEdit].tex.pBuffMat = NULL;
		}

	}
}
void UpdateBlock(void)
{

}
void DrawBlock(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;
	//���݂̃}�e���A���̕ۑ��p
	D3DMATERIAL9 matDef;//���݂̃}�e���A���̕ۑ��p
	D3DXMATERIAL* pMat;//�}�e���A���f�[�^�ւ̃|�C���^
	for (int i = 0; i < BLOCK_MAX; i++)
	{

		for (int nCntBlock = 0; nCntBlock < NUM_BLOCK; nCntBlock++)
		{
			if (g_Block[nCntBlock].bUse == true)
			{
				//���[���h�}�g���b�N�X�̏�����
				D3DXMatrixIdentity(&g_Block[nCntBlock].mtxWorld);
				//�����𔽉f
				D3DXMatrixRotationYawPitchRoll(&mtxRot, g_Block[nCntBlock].rot.y, g_Block[nCntBlock].rot.x, g_Block[nCntBlock].rot.z);
				D3DXMatrixMultiply(&g_Block[nCntBlock].mtxWorld, &g_Block[nCntBlock].mtxWorld, &mtxRot);

				//�ʒu�𔽉f
				D3DXMatrixTranslation(&mtxTrans, g_Block[nCntBlock].pos.x, g_Block[nCntBlock].pos.y, g_Block[nCntBlock].pos.z);
				D3DXMatrixMultiply(&g_Block[nCntBlock].mtxWorld, &g_Block[nCntBlock].mtxWorld, &mtxTrans);

				pDevice->SetTransform(D3DTS_WORLD, &g_Block[nCntBlock].mtxWorld);

				pDevice->GetMaterial(&matDef);
				//�}�e���A���f�[�^�ւ̃|�C���^���擾
				pMat = (D3DXMATERIAL*)g_Block[nCntBlock].tex.pBuffMat->GetBufferPointer();

				for (int nCntMat = 0; nCntMat < (int)g_Block[nCntBlock].tex.dwNumMat; nCntMat++)
				{
					//�}�e���A���̐ݒ�
					pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

					//�e�N�X�`���̐ݒ�
					pDevice->SetTexture(0, g_Block[nCntBlock].tex.apTexture[nCntMat]);

					//���f���i�p�[�c�j�̕`��
					g_Block[nCntBlock].tex.pMesh->DrawSubset(nCntMat);
				}
				pDevice->SetMaterial(&matDef);

			}

		}

	}
}


void SetBlock(D3DXVECTOR3 pos,int nType)
{
	for (int nCnt = 0; nCnt < NUM_BLOCK; nCnt++)
	{
		if (g_Block[nCnt].bUse == false)
		{
			g_Block[nCnt].pos = pos;
			g_Block[nCnt].nType = nType;
			g_Block[nCnt].tex = g_BlockTex[nType];
			g_Block[nCnt].bUse = true;
			break;
		}
	}
}
void CollisionBlock(D3DXVECTOR3* pPos,		//���݂̈ʒu
					D3DXVECTOR3* pPosOld)	//�O��̈ʒu
{					
	Player* pPlayer = GetPlayer();
	D3DXVECTOR3* posOld = pPosOld;		//�O�t���[���̃v���C���[�̈ʒu
	D3DXVECTOR3* pos = pPos;			//���t���[���̃v���C���[�̈ʒu




	for (int nCnt = 0; nCnt < NUM_BLOCK; nCnt++)
	{
		if (g_Block[nCnt].bUse == true)
		{
			//���E��O���̂߂荞�ݔ���
			if (pos->y< g_Block[nCnt].pos.y + g_Block[nCnt].tex.vtxMax.y && pos->y + (OBJ_P * 2.0f) > g_Block[nCnt].pos.y + g_Block[nCnt].tex.vtxMin.y)
			{
				//���E�̂߂荞�ݔ���
				if (pos->z - OBJ_P< g_Block[nCnt].pos.z + g_Block[nCnt].tex.vtxMax.z && pos->z + OBJ_P > g_Block[nCnt].pos.z + g_Block[nCnt].tex.vtxMin.z)//�v���C���[�̂��͈̔͂��u���b�N�ɏd�Ȃ��Ă���
				{

					if (posOld->x + OBJ_P< g_Block[nCnt].pos.x + g_Block[nCnt].tex.vtxMin.x && pos->x + OBJ_P > g_Block[nCnt].pos.x + g_Block[nCnt].tex.vtxMin.x)//�w��������E�ɂ߂荞��
					{
						//pPlayer->pos�����f���̍����ɂ�������
						pos->x = g_Block[nCnt].pos.x + g_Block[nCnt].tex.vtxMin.x - OBJ_P - 0.1f;

					}
					if (posOld->x - OBJ_P > g_Block[nCnt].pos.x + g_Block[nCnt].tex.vtxMax.x && pos->x - OBJ_P < g_Block[nCnt].pos.x + g_Block[nCnt].tex.vtxMax.x)//�w��������E�ɂ߂荞��
					{
						//pPlayer->pos�����f���̉E���ɂ�������
						pos->x = g_Block[nCnt].pos.x + g_Block[nCnt].tex.vtxMax.x + OBJ_P + 0.1f;
					}
				}

				//��O���̂߂荞�ݔ���
				if (pos->x - OBJ_P< g_Block[nCnt].pos.x + g_Block[nCnt].tex.vtxMax.x && pos->x + OBJ_P > g_Block[nCnt].pos.x + g_Block[nCnt].tex.vtxMin.x)//�v���C���[x�͈̔͂��u���b�N�ɏd�Ȃ��Ă���
				{

					if (posOld->z + OBJ_P< g_Block[nCnt].pos.z + g_Block[nCnt].tex.vtxMin.z && pos->z + OBJ_P > g_Block[nCnt].pos.z + g_Block[nCnt].tex.vtxMin.z)//Z���������ɂ߂荞��
					{
						//pPlayer->pos�����f���̎�O���ɂ�������
						pos->z = g_Block[nCnt].pos.z + g_Block[nCnt].tex.vtxMin.z - OBJ_P - 0.1f;
					}
					if (posOld->z - OBJ_P > g_Block[nCnt].pos.z + g_Block[nCnt].tex.vtxMax.z && pos->z - OBJ_P < g_Block[nCnt].pos.z + g_Block[nCnt].tex.vtxMax.z)//Z���ォ�牺�ɂ߂荞��
					{
						//pPlayer->pos�����f���̉����ɂ�������
						pos->z = g_Block[nCnt].pos.z + g_Block[nCnt].tex.vtxMax.z + OBJ_P + 0.1f;
					}
				}

			}
			if (pos->z - OBJ_P< g_Block[nCnt].pos.z + g_Block[nCnt].tex.vtxMax.z && pos->z + OBJ_P > g_Block[nCnt].pos.z + g_Block[nCnt].tex.vtxMin.z
				&& pos->x - OBJ_P< g_Block[nCnt].pos.x + g_Block[nCnt].tex.vtxMax.x && pos->x + OBJ_P > g_Block[nCnt].pos.x + g_Block[nCnt].tex.vtxMin.x)
			{
				if (posOld->y + (OBJ_P * 2.0f) < g_Block[nCnt].pos.y + g_Block[nCnt].tex.vtxMin.y && pos->y + (OBJ_P * 2.0f) > g_Block[nCnt].pos.y + g_Block[nCnt].tex.vtxMin.y)//�w��������E�ɂ߂荞��
				{
					//pPlayer->pos�����f���̉����ɂ�������
					pos->y = g_Block[nCnt].pos.y + g_Block[nCnt].tex.vtxMin.y - (OBJ_P * 2.0f) - 0.1f;
				}
				if (posOld->y > g_Block[nCnt].pos.y + g_Block[nCnt].tex.vtxMax.y && pos->y < g_Block[nCnt].pos.y + g_Block[nCnt].tex.vtxMax.y)//�w��������E�ɂ߂荞��
				{
					//pPlayer->pos�����f���̏㑤�ɂ�������
					pos->y = g_Block[nCnt].pos.y + g_Block[nCnt].tex.vtxMax.y + 0.1f;
				}

			}

		}

	}


}

