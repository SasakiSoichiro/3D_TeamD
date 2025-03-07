//====================================================
//
// �X�^�~�i�̏��� [stamina.cpp]
// Author : Sasaki Soichiro
//
//====================================================

#include "stamina.h"
#include "player.h"
#include "enemy.h"

//�}�N����`
#define MAX_TIMEWIDTH (400)
#define MAX_TIMEHEIGHT (10)

//�O���[�o���ϐ�
D3DXVECTOR3 StaminaPos;								//�X�^�~�i�̈ʒu
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffStamina = NULL;	//�o�b�t�@�ւ̃|�C���^
int g_nCntState;
bool bStamina;
bool bScreen;
int g_nStamina;

//====================================================
//�\���̏���������
//====================================================
void InitStamina()
{
	VERTEX_2D* pVtx{};

	LPDIRECT3DDEVICE9 pDevice;					//�f�o�C�X�ւ̃|�C���^

	pDevice = GetDevice();						//�f�o�C�X�̎擾

	D3DXVECTOR3 pos = D3DXVECTOR3(50.0f, 700.0f, 0.0f);

	bStamina = true;
	bScreen = false;

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffStamina, NULL);

	//���_�o�b�t�@�̃��b�N�A���_�f�[�^�ւ̃|�C���^�擾
	g_pVtxBuffStamina->Lock(0, 0, (void**)&pVtx, 0);

	//���_���̐ݒ�
	pVtx[0].pos.x = pos.x - 0.0f;
	pVtx[0].pos.y = pos.y - MAX_TIMEHEIGHT / 2.0f;
	pVtx[0].pos.z = pos.z;

	pVtx[1].pos.x = pos.x + MAX_TIMEWIDTH;
	pVtx[1].pos.y = pos.y - MAX_TIMEHEIGHT / 2.0f;
	pVtx[1].pos.z = pos.z;

	pVtx[2].pos.x = pos.x - 0.0f;
	pVtx[2].pos.y = pos.y + MAX_TIMEHEIGHT / 2.0f;
	pVtx[2].pos.z = pos.z;

	pVtx[3].pos.x = pos.x + MAX_TIMEWIDTH;
	pVtx[3].pos.y = pos.y + MAX_TIMEHEIGHT / 2.0f;
	pVtx[3].pos.z = pos.z;

	//rhw�̐ݒ�
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//���_�J���[�̐ݒ�
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);

	//�e�N�X�`�����W�̐ݒ�
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffStamina->Unlock();
}

//====================================================
//�\���̏I������
//====================================================
void UninitStamina()
{

	//���_�o�b�t�@�̔j��
	if (g_pVtxBuffStamina != NULL)
	{
		g_pVtxBuffStamina->Release();
		g_pVtxBuffStamina = NULL;
	}

}

//====================================================
//�\���̍X�V����
//====================================================
void UpdateStamina()
{
	Player* pPlayer = GetPlayer();
	bool pRange = IsRange();

	int nDate = 2;
	int aDate = 1;

	VERTEX_2D* pVtx{};

	g_nStamina = pPlayer->nStamina;
	if (pPlayer->pState == PLAYERSTATE_DASH)
	{//�v���C���[�������Ă���Ƃ�

		if (pRange == false)
		{
			//�X�^�~�i�l�����炷
			pPlayer->nStamina--;

			if (pPlayer->nStamina <= 0)
			{//�X�^�~�i��0�ɂȂ����Ƃ�
				bStamina = false;
			}
		}
		else if (pRange == true)
		{
			//�X�^�~�i�l�����炷
			pPlayer->nStamina = pPlayer->nStamina - nDate;

			if (pPlayer->nStamina <= 0)
			{//�X�^�~�i��0�ɂȂ����Ƃ�
				bStamina = false;
			}
		}
	}
	else
	{
		if (pPlayer->nStamina <= 0)
		{//�X�^�~�i��0�ɂȂ����Ƃ�

			//�J�E���g����
			g_nCntState++;

			if (g_nCntState >= 120)
			{//120F��������
				pPlayer->nStamina = 1;

				//�J�E���g������������
				g_nCntState = 0;

				//�X�^�~�i���g����悤�ɂ���
				bStamina = true;
			}

		}
		else if (pPlayer->nStamina < 300)
		{//�X�^�~�i��100�����ő����Ă��Ȃ��Ƃ�

			if (pRange == false)
			{
				pPlayer->nStamina++;
			}
			else if (pRange == true)
			{
				pPlayer->nStamina = pPlayer->nStamina + aDate;
			}
		}

	}

	float fStamina = pPlayer->nStamina * 0.01f;
	//���_�o�b�t�@�̃��b�N�A���_�f�[�^�ւ̃|�C���^�擾
	g_pVtxBuffStamina->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[1].pos.x = StaminaPos.x + MAX_TIMEWIDTH * fStamina;

	pVtx[3].pos.x = StaminaPos.x + MAX_TIMEWIDTH * fStamina;


	//���_�o�b�t�@���A�����b�N
	g_pVtxBuffStamina->Unlock();

	if (g_nStamina == pPlayer->nStamina)
	{
		bScreen = false;
	}
	else
	{
		bScreen = true;
	}

}

//====================================================
//�\���̕`�揈��
//====================================================
void DrawStamina()
{
	LPDIRECT3DDEVICE9 pDevice;					//�f�o�C�X�ւ̃|�C���^

	//�f�o�C�X�̎擾
	pDevice = GetDevice();

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, g_pVtxBuffStamina, 0, sizeof(VERTEX_2D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	if (bScreen == true)
	{
		//�|���S���̕`��
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	}


}
bool GetStamina(void)
{
	return bStamina;
}