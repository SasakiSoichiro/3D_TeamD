//==================================
//		���[�ނ̏���	game.cpp
//			ryuusei.hirata 
//==================================
#include "input.h"
#include "game.h"
#include "fade.h"
#include "result.h"
#include "camera.h"
#include "light.h"
#include "meshfield.h"
#include "meshwall.h"
#include "model.h"
#include "player.h"
#include "motion.h"
#include "stage.h"
#include "item.h"
#include "block.h"
#include "time.h"
#include "billboard.h"
#include "pause.h"
#include "enemy.h"
#include "edit.h"
#include "sound.h"
#include "gimmick.h"

// �Q�[���̏��
GAMESTATE g_gameState = GAMESTATE_NONE;	// ������

// ��ԊǗ��J�E���^�[
int g_nCounterGameState = 0;

//	�|�[�Y
bool g_bPause = false;

//�G�f�B�b�g
bool g_bEdit = false;

//---------------
//	����������
//---------------
void InitGame(void)
{
	//�@BGM��炷
	PlaySound(SOUND_LABEL_BGM2);


	//�@�e�I�u�W�F�N�g�̏���������
	

	//�@���C�g
	InitLight();

	//�@�J����
	InitCamera();

	//�@���b�V���t�B�[���h
	InitMeshfield();

	//�@�v���C���[
	InitPlayer();

	//�@�A�C�e��
	Inititem();

	//�@�^�C��
	InitTime();

	//�@�G
	InitEnemy();

	//�@�u���b�N
	InitBlock();

	//�@�G�f�B�b�g
	InitEdit();

	//�@�M�~�b�N
	InitGimmick();

	//�@�r���{�[�h
	InitBillboard();

	//�@�|�[�Y
	InitPause();


	//�@�e�I�u�W�F�N�g�̐ݒ菈��
	LoadEdit();
	
	//�@���̏㕔
	Setitem(D3DXVECTOR3(50.0f, 1.0f, 0.0f), ITEMTYPE_ONE);

	//�@�㓁
	Setitem(D3DXVECTOR3(200.0f, 0.0f, 0.0f), ITEMTYPE_FOUR);

	//�@�r���{�[�h
	SetBillboard(D3DXVECTOR3(-100.0f, 50.0f, -200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_0,D3DXVECTOR3(15.0f,35.0f,0.0f));
	SetBillboard(D3DXVECTOR3(-100.0f, 50.0f, -100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_1, D3DXVECTOR3(2.0f, 2.0f, 0.0f));
	SetBillboard(D3DXVECTOR3(-100.0f, 50.0f, -100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_1, D3DXVECTOR3(2.0f, 2.0f, 0.0f));
	SetBillboard(D3DXVECTOR3(-1800.0f, 50.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_2, D3DXVECTOR3(4.0f, 4.0f, 0.0f));
	SetBillboard(D3DXVECTOR3(-1800.0f, 50.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_3, D3DXVECTOR3(4.0f, 4.0f, 0.0f));
	SetBillboard(D3DXVECTOR3(-1800.0f, 50.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_4, D3DXVECTOR3(1.0f, 1.0f, 0.0f));

	//�@�G
	SetEnemy(D3DXVECTOR3(800.0f, 0.0f, 0.0f),0);

	//�@�h�A
	SetGimmick(D3DXVECTOR3(-1800.0f, 0.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//�@����������
	g_bEdit = false;
	g_gameState = GAMESTATE_NORMAL;// �ʏ��Ԃɐݒ�
}

//---------------
//	�I������
//---------------
void UninitGame(void)
{
	//�@���y���~�߂�
	StopSound();

	//�@�e�I�u�W�F�N�g�̏I������


	//�@���C�g
	UninitLight();

	//�@���b�V���t�B�[���h
	UninitMeshfield();

	//�@�J����
	UninitCamera();

	//�@�u���b�N
	UninitBlock();

	//�@�v���C���[
	UninitPlayer();

	//�@�G
	UninitEnemy();

	//�@�A�C�e��
	Uninititem();

	//�@�^�C��
	UninitTime();

	//�@�G�f�B�b�g
	UninitEdit();

	//�@�r���{�[�h
	UninitBillboard();

	//�@�|�[�Y
	UninitPause();

	//�@�M�~�b�N
	UninitGimmick();
}

//---------------
//	�X�V����
//---------------
void UpdateGame(void)
{
	bool isGoal = IsGoal();			// �S�[���̔���

	Player* pPlayer = GetPlayer();	//�@�v���C���[���擾

	// �|�[�Y����
	if (KeybordTrigger(DIK_TAB) == true)
	{// TAB
		g_bPause = g_bPause ? false : true;
	}

	if (g_bPause == true)
	{// g_bPause��true
		UpdatePause();
	}


	//�G�f�B�b�g����
	if (g_bEdit == true&&KeybordTrigger(DIK_F1))
	{// F1
		g_bEdit = false;

		//�u���b�N������
		InitBlock();

		//�X�e�[�W�����[�h
		LoadEdit();
	}
	else if (g_bEdit == false && KeybordTrigger(DIK_F1))
	{// b_Edit��true
		g_bEdit = true;

	}
	if (g_bPause == false)
	{// b_Pause��false
		if (g_bEdit == false)
		{// g_Edit��false

			//�@�Q�[�����̊e�I�u�W�F�N�g�̍X�V����

			//���b�V���t�B�[���h
			UpdateMeshfield();

			//�J����
			UpdateCamera();

			//���C�g
			UpdateLight();

			//�u���b�N
			UpdateBlock();

			//�v���C���[
			UpdatePlayer();

			//�G
			UpdateEnemy();

			//�r���{�[�h
			UpdateBillboard();

			//�A�C�e��
			Updateitem();

			//�^�C��
			UpdateTime();

			//�M�~�b�N
			UpdateGimmick();

#ifdef _DEBUG// �f�o�b�O

			if (KeybordTrigger(DIK_O) == true || JoyPadTrigger(JOYKEY_A) == true)
			{// O�܂���A�{�^��

				//���U���g�Ɉڂ�
				SetFade(MODE_RESULT);
			}

#endif
		}
		else if (g_bEdit == true)
		{//�@g_Edit��true

			//�@�G�f�B�b�g���̊e�I�u�W�F�N�g�̍X�V����

			//�@�J����
			UpdateCamera();

			//�@�G�f�B�b�g
			UpdateEdit();
		}

	}

	if (isGoal == true)
	{//�S�[����true
		g_gameState = GAMESTATE_END;// �Q�[�����I��������
	}

	if (pPlayer->nLife <= 0)
	{//�v���C���[�����񂾂Ƃ�

		//���[�h�ݒ�
		g_gameState = GAMESTATE_END;// �Q�[�����I��������

		//�J�E���g��i�߂�
		g_nCounterGameState++;
	}

	switch (g_gameState)
	{
	case GAMESTATE_NONE:// �Q�[���ʏ���

		break;
	case GAMESTATE_END:	// �Q�[���I�����

		g_nCounterGameState++;

		if (g_nCounterGameState >= 30)
		{//30F��������
			g_gameState = GAMESTATE_NONE;	// �������Ă��Ȃ�
			SetFade(MODE_RESULT);			// ���U���g��ʂɑJ��
			g_nCounterGameState = 0;		// ��ԃJ�E���^�[������
		}
		break;
	}
}

//---------------
//	�`�揈��
//---------------
void DrawGame(void)
{
	//�@�e�I�u�W�F�N�g�̕`�揈��


	//�@���b�V���t�B�[���h
	DrawMeshfield();

	//�@�u���b�N
	DrawBlock();

	//�@�A�C�e��
	Drawitem();

	//�@�v���C���[
	DrawPlayer();

	//�@�G
	DrawEnemy();

	//�@�^�C��
	DrawTime();

	//�@�r���{�[�h
	DrawBillboard();

	//�@�M�~�b�N
	DrawGimmick();

	if (g_bPause == true)
	{//�@g_Pause��true

		//�@�|�[�Y
		DrawPause();
	}
	if (g_bEdit == true)
	{//�@g_bEdit��true

		//�@�G�f�B�b�g
		DrawEdit();
	}
}


//----------------------
//	�|�[�Y��bool����
//----------------------
void SetEnablePause(bool bPause)
{
	g_bPause = bPause;
}


//------------------
//�Q�[����Ԃ̐ݒ�
//------------------
void SetGameState(GAMESTATE state)
{
	g_gameState = state;
}


//------------------------
//�G�f�B�b�g�̏��̎擾
//------------------------
bool GetEditState(void)
{
	return g_bEdit;
}