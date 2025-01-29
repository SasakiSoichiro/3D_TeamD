//=============================================================
//
// Athor: HRT ryuusei  �����L���O
// 
//=============================================================
#include "ranking.h"
#include "input.h"
#include "fade.h"
#include "game.h"
#include "stdio.h"
#include "score.h"

//�����L���O�X�R�A�̍\����
typedef struct
{
	D3DXVECTOR3 pos;	//�ʒu
	int nRank;			//����
	int nScore;			//�X�R�A
}RankScore;

//�O���[�o���ϐ��錾
LPDIRECT3DTEXTURE9 g_pTextureBKG = NULL;			//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBKG = NULL;			//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureRank = NULL;				//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DTEXTURE9 g_pTextureRankScore = NULL;			//�e�N�X�`���ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffRank = NULL;			//���_�o�b�t�@�ւ̃|�C���^
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffRankScore = NULL;		//���_�o�b�t�@�ւ̃|�C���^

RankScore g_aRankScore[MAX_RANK] = {};						//�����L���O�X�R�A(5�ʕ�)�\��
int g_nRankUpdate = -1;									//�X�V�����NNo.
int g_nTimerRanking;									//�����L���O��ʕ\���^�C�}�[
int nData = 1;

//----------------------------zk
//�����L���O�̏���������
//----------------------------
void InitRanking(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	int nCntRank;
	int nRankScore;

	g_nRankUpdate = -1;//�X�VNo.��������
	g_nTimerRanking = 0;
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\number000.png",
		&g_pTextureRank);

	//�e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\number000.png",
		&g_pTextureRankScore);

	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\rankingu.png",
		&g_pTextureBKG);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_RANK, //�K�v�Ȓ��_��
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffRank,
		NULL);

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_RANK * MAX_RANKSCORE_NUM, //�K�v�Ȓ��_��
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffRankScore,
		NULL);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, //�K�v�Ȓ��_��
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBKG,
		NULL);

	VERTEX_2D* pVtx;
	//���_�o�b�t�@�����b�N���A���傤�Ă���ւ̃|�C���^���擾
	g_pVtxBuffRankScore->Lock(0, 0, (void**)&pVtx, 0);

	//�����L���O�̏��̏�����
	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{//�����L���O�̏��ʕ���
		g_aRankScore[nCntRank].pos = D3DXVECTOR3(460.0f, 150.0f + MAX_RANKSCORE_HEIGHT * nCntRank, 0.0f);
		g_aRankScore[nCntRank].nScore = 0;
		g_aRankScore[nCntRank].nRank = nCntRank + 1;

		for (nRankScore = 0; nRankScore < MAX_RANKSCORE_NUM; nRankScore++)
		{//�X�R�A�̌�������

			pVtx[0].pos.x = g_aRankScore[nCntRank].pos.x - MAX_RANKSCORE_WIDTH / 2 + MAX_RANKSCORE_WIDTH * nRankScore;
			pVtx[0].pos.y = g_aRankScore[nCntRank].pos.y - MAX_RANKSCORE_HEIGHT / 2;
			pVtx[0].pos.z = 0.0f;

			pVtx[1].pos.x = g_aRankScore[nCntRank].pos.x + MAX_RANKSCORE_WIDTH / 2 + MAX_RANKSCORE_WIDTH * nRankScore;
			pVtx[1].pos.y = g_aRankScore[nCntRank].pos.y - MAX_RANKSCORE_HEIGHT / 2;
			pVtx[1].pos.z = 0.0f;

			pVtx[2].pos.x = g_aRankScore[nCntRank].pos.x - MAX_RANKSCORE_WIDTH / 2 + MAX_RANKSCORE_WIDTH * nRankScore;
			pVtx[2].pos.y = g_aRankScore[nCntRank].pos.y + MAX_RANKSCORE_HEIGHT / 2;
			pVtx[2].pos.z = 0.0f;

			pVtx[3].pos.x = g_aRankScore[nCntRank].pos.x + MAX_RANKSCORE_WIDTH / 2 + MAX_RANKSCORE_WIDTH * nRankScore;
			pVtx[3].pos.y = g_aRankScore[nCntRank].pos.y + MAX_RANKSCORE_HEIGHT / 2;
			pVtx[3].pos.z = 0.0f;

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
			pVtx[1].tex = D3DXVECTOR2(0.1f, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
			pVtx[3].tex = D3DXVECTOR2(0.1f, 1.0f);

			pVtx += 4;//���_�f�[�^�̃|�C���^���l���i�߂�
		}
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffRankScore->Unlock();

	//���_�o�b�t�@�����b�N���A���傤�Ă���ւ̃|�C���^���擾
	g_pVtxBuffRank->Lock(0, 0, (void**)&pVtx, 0);

	//�����L���O�̏��̏�����
	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		g_aRankScore[nCntRank].pos = D3DXVECTOR3(400.0f - MAX_RANK_WIDTH, 150.0f + MAX_RANKSCORE_HEIGHT * nCntRank, 0.0f);

		pVtx[0].pos.x = g_aRankScore[nCntRank].pos.x - MAX_RANK_WIDTH / 2;
		pVtx[0].pos.y = g_aRankScore[nCntRank].pos.y - MAX_RANKSCORE_HEIGHT / 2;
		pVtx[0].pos.z = 0.0f;
		pVtx[1].pos.x = g_aRankScore[nCntRank].pos.x + MAX_RANK_WIDTH / 2;
		pVtx[1].pos.y = g_aRankScore[nCntRank].pos.y - MAX_RANKSCORE_HEIGHT / 2;
		pVtx[1].pos.z = 0.0f;
		pVtx[2].pos.x = g_aRankScore[nCntRank].pos.x - MAX_RANK_WIDTH / 2;
		pVtx[2].pos.y = g_aRankScore[nCntRank].pos.y + MAX_RANKSCORE_HEIGHT / 2;
		pVtx[2].pos.z = 0.0f;
		pVtx[3].pos.x = g_aRankScore[nCntRank].pos.x + MAX_RANK_WIDTH / 2;
		pVtx[3].pos.y = g_aRankScore[nCntRank].pos.y + MAX_RANKSCORE_HEIGHT / 2;
		pVtx[3].pos.z = 0.0f;

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
		pVtx[0].tex = D3DXVECTOR2(0.1f + 0.1f * nCntRank, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.2f + 0.1f * nCntRank, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.1f + 0.1f * nCntRank, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.2f + 0.1f * nCntRank, 1.0f);

		pVtx += 4;//���_�f�[�^�̃|�C���^���l���i�߂�
	}
	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffRank->Unlock();

	g_pVtxBuffBKG->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

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

	g_pVtxBuffBKG->Unlock();

	ResetRanking(FILE_TXT_SCORE);
	SetRanking(GetScore());
}
//----------------------------
//�����L���O�̏I������
//----------------------------
void UninitRanking(void)
{
	//�e�N�X�`���̔j��
	if (g_pTextureRank != NULL)
	{
		g_pTextureRank->Release();
		g_pTextureRank = NULL;
	}
	//�e�N�X�`���̔j��
	if (g_pTextureRankScore != NULL)
	{
		g_pTextureRankScore->Release();
		g_pTextureRankScore = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffRank != NULL)
	{
		g_pVtxBuffRank->Release();
		g_pVtxBuffRank = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffRankScore != NULL)
	{
		g_pVtxBuffRankScore->Release();
		g_pVtxBuffRankScore = NULL;
	}
	//�e�N�X�`���̔j��
	if (g_pTextureBKG != NULL)
	{
		g_pTextureBKG->Release();
		g_pTextureBKG = NULL;
	}
	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffBKG != NULL)
	{
		g_pVtxBuffBKG->Release();
		g_pVtxBuffBKG = NULL;
	}

}
//----------------------------
//�����L���O�̍X�V����
//----------------------------
void UpdateRanking(void)
{
	int nRankScore;

	g_nTimerRanking += 1;
	//���_���ւ̃|�C���^
	VERTEX_2D* pVtx;

	//���_�o�b�t�@�����b�N���A���傤�Ă���ւ̃|�C���^���擾
	g_pVtxBuffRankScore->Lock(0, 0, (void**)&pVtx, 0);

	for (nRankScore = 0; nRankScore < MAX_RANKSCORE_NUM * MAX_RANK; nRankScore++)
	{//�X�R�A�̌�������
		//���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		pVtx += 4;
	}

	pVtx -= 4 * MAX_RANKSCORE_NUM * MAX_RANK;

	//�Y���X�R�A�����L���O�X�R�A��_��
	if (g_nRankUpdate != -1 && g_nTimerRanking >= 0)
	{//�����N�C�����ĂāA���A�^�C�}�[���[���ȏゾ������
		pVtx += 4 * MAX_RANKSCORE_NUM * g_nRankUpdate;

		for (nRankScore = 0; nRankScore < MAX_RANKSCORE_NUM; nRankScore++)
		{//�X�R�A�̌�������
		//���_�J���[�̐ݒ�
			pVtx[0].col = D3DXCOLOR(0.3f, 1.0f, 0.3f, 1.0f);
			pVtx[1].col = D3DXCOLOR(0.3f, 1.0f, 0.3f, 1.0f);
			pVtx[2].col = D3DXCOLOR(0.3f, 1.0f, 0.3f, 1.0f);
			pVtx[3].col = D3DXCOLOR(0.3f, 1.0f, 0.3f, 1.0f);

			pVtx += 4;
		}
	}

	//�^�C�}�[���}�C�i�X�ɂ���
	if (g_nTimerRanking >= 5)
	{
		g_nTimerRanking *= -1;
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffRankScore->Unlock();

	if (KeybordTrigger(DIK_RETURN) == true || JoyPadTrigger(JOYKEY_START) == true)
	{
		//���[�h�ݒ�(�Q�[����ʂɈڍs)
		SetFade(MODE_TITLE);
	}
}
//----------------------------
//�����L���O�̕`�揈��
//----------------------------
void DrawRanking(void)
{
	int nCntRank;

	LPDIRECT3DDEVICE9 pDevice; //�f�o�C�X�ւ̃|�C���^
	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffBKG, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, g_pTextureBKG);
	//�|���S���`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//�v���~�e�B�u�̎��
		0,							//�`�悷��ŏ��̒��_�C���f�b�N�X
		2);

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffRankScore, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�����L���O�X�R�A�̕`��
	for (nCntRank = 0; nCntRank < MAX_RANK * MAX_RANKSCORE_NUM; nCntRank++)
	{
		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureRankScore);
		//�|���S���`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//�v���~�e�B�u�̎��
			4 * nCntRank,							//�`�悷��ŏ��̒��_�C���f�b�N�X
			2);
	}

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffRank, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	//�G�t�F�N�g�̕`��
	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		//�e�N�X�`���̐ݒ�
		pDevice->SetTexture(0, g_pTextureRank);
		//�|���S���`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//�v���~�e�B�u�̎��
			4 * nCntRank,							//�`�悷��ŏ��̒��_�C���f�b�N�X
			2);
	}
}
//----------------------------
//�����L���O�̃��Z�b�g
//----------------------------
void ResetRanking(const char* DateScore)
{
	int nCnt = 0;
	int foge = NULL;
	//�����L���O�X�R�A���̏����ݒ�
	FILE* pFile = fopen(FILE_TXT_SCORE, "r");

	if (pFile == NULL)
	{

	}
	else
	{
		//��s�ڂ�ǂݍ���
		char cTmp[125];
		foge = fscanf(pFile, "%s\n", &cTmp[0]);

		//��s�ڈȍ~��ǂݍ���
		for (nCnt = 0; nCnt < MAX_RANK; nCnt++)
		{
			foge = fscanf(pFile, "%d\n", &g_aRankScore[nCnt].nScore);
		}

		fclose(pFile);
	}

}
//----------------------------
//�����L���O�̐ݒ�
//----------------------------
void SetRanking(int nScore)
{
	int nCntRank;
	int nSelect;
	int nTemp;
	int aPosTexU[8] = {};//�i���̐������i�[
	int nData1, nData2;
	int nCnt;

	int bairitu = NULL;

	//---�����L���O�X�R�A�̕��ёւ�
	//-----�w��X�R�A�������N�C�������� g_nRankUpdate ���X�V

	if (nScore >= g_aRankScore[MAX_RANK - 1].nScore)//�\�[�g����
	{
		g_aRankScore[MAX_RANK - 1].nScore = nScore;

		for (nCntRank = 0; nCntRank < MAX_RANK - 1; nCntRank++)
		{
			for (nSelect = nCntRank + 1; nSelect < MAX_RANK; nSelect++)
			{
				if (g_aRankScore[nCntRank].nScore <= g_aRankScore[nSelect].nScore)
				{
					nTemp = g_aRankScore[nCntRank].nScore;
					g_aRankScore[nCntRank].nScore = g_aRankScore[nSelect].nScore;
					g_aRankScore[nSelect].nScore = nTemp;
				}
			}
		}
		//���ʂ��Ԃ�����
		for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
		{
			if (g_aRankScore[nCntRank].nScore == nScore)
			{
				g_nRankUpdate = g_aRankScore[nCntRank].nRank - 1;
			}
		}
	}

	//���_���ւ̃|�C���^
	VERTEX_2D* pVtx;
	//���_�o�b�t�@�����b�N���A���傤�Ă���ւ̃|�C���^���擾
	g_pVtxBuffRankScore->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		nData1 = 10000000;
		nData2 = 1000000;

		//�����Ƃɕ�������
		for (nCnt = 0; nCnt < MAX_RANKSCORE_NUM; nCnt++)
		{
			if (nCnt == 0)
			{
				aPosTexU[0] = g_aRankScore[nCntRank].nScore / nData1;
			}
			else
			{
				aPosTexU[nCnt] = (g_aRankScore[nCntRank].nScore % nData1 / nData2);
				nData1 /= 10;
				nData2 /= 10;
			}

			//-----�e�N�X�`�����W�̐ݒ�
			pVtx[0].tex = D3DXVECTOR2(0.1f * aPosTexU[nCnt], 0.0f);
			pVtx[1].tex = D3DXVECTOR2(0.1f + (0.1f * aPosTexU[nCnt]), 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.1f * aPosTexU[nCnt], 1.0f);
			pVtx[3].tex = D3DXVECTOR2(0.1f + (0.1f * aPosTexU[nCnt]), 1.0f);

			pVtx += 4;
		}
	}

	//���_�o�b�t�@���A�����b�N����
	g_pVtxBuffRankScore->Unlock();

	int ham = NULL;

	//���ʂ���������
	//�����L���O�X�R�A���̏����ݒ�
	FILE* pFile = fopen(FILE_TXT_SCORE, "w");

	if (pFile == NULL)
	{

	}
	else
	{
		char aScore[10] = "�X�R�A";

		//��s�ڂ���������
		fprintf(pFile, "%s\n", &aScore[0]);

		//��s�ڈȍ~����������
		for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
		{
			fprintf(pFile, "%d\n", g_aRankScore[nCntRank].nScore);
		}

		fclose(pFile);
	}
}