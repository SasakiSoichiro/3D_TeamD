//==================================
// 
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
#include "UI.h"
#include "gonnzaresu.h"
#include "slow.h"
#include "gauge.h"
#include "KeyUI.h"
#include <time.h>
#include "ItemUI.h"
#include "stamina.h"
#include "nannjamo.h"
#include "Cancellation.h"
#include "viewportwaku.h"
#include "unlock.h"

// �}�N����`
#define RAND (6) // �����_���p�ϐ�

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

	//	�S���U���X
	InitGonzaresu();

	// �X���[
	InitSlow();

	// �e�I�u�W�F�N�g�̐ݒ菈��
	LoadEdit();

	InitUnlock();

	//	�Q�[�W
	InitGauge();

	// ����UI
	InitCancellation();

	// ����UI
	InitKeyUI();

	// �A�C�e����UI
	InitItemUI();

	// �X�^�~�i
	InitStamina();
	
	//	��
	InitNannjamo();

	//	�G���_�̃r���[�|�[�g�̘g
	InitViewUI();

	//int a = rand() % 6 + 1;
	int a = rand() % RAND + 1;

	if (a == 1)
	{
		//�@���̏㕔
		Setitem(D3DXVECTOR3(1422.6f, 1.5f, -738.7f), ITEMTYPE_ONE);
	}
	
	if (a == 2)
	{
		//�@���̏㕔
		Setitem(D3DXVECTOR3(-94.6f, 1.5f, -608.8f), ITEMTYPE_ONE);
	}

	if (a == 3)
	{
		//�@���̏㕔
		Setitem(D3DXVECTOR3(-1199.0f, 1.5f, 396.1f), ITEMTYPE_ONE);
	}

	if (a == 4)
	{
		//�@���̏㕔
		Setitem(D3DXVECTOR3(785.7f, 1.5f, 615.6f), ITEMTYPE_ONE);
	}

	if (a == 5)
	{
		//�@���̏㕔
		Setitem(D3DXVECTOR3(-94.9f, 1.5f, 480.5f), ITEMTYPE_ONE);
	}

	if (a == 6)
	{//��
		//�@���̏㕔
		Setitem(D3DXVECTOR3(-1722.6f, 1.5f, -818.2f), ITEMTYPE_ONE);
	}

	int b = rand() % RAND + 1;

	if (b == 1)
	{
		//�@���̉���
		Setitem(D3DXVECTOR3(200.0f, 1.5f, 320.5f), ITEMTYPE_TWO);
	}

	if (b == 2)
	{
		//�@���̉���
		Setitem(D3DXVECTOR3(932.5f, 1.5f, -512.5f), ITEMTYPE_TWO);
	}

	if (b == 3)
	{
		//�@���̉���
		Setitem(D3DXVECTOR3(717.5f, 1.5f, 25.5f), ITEMTYPE_TWO);
	}

	if (b == 4)
	{
		//�@���̉���
		Setitem(D3DXVECTOR3(-1092.5f, 1.5f, 452.5f), ITEMTYPE_TWO);
	}

	if (b == 5)
	{
		//�@���̉���
		Setitem(D3DXVECTOR3(-391.5f, 1.5f, -111.5f), ITEMTYPE_TWO);
	}

	if (b == 6)
	{//��
		//�@���̉���
		Setitem(D3DXVECTOR3(-10.5f, 1.5f, -387.5f), ITEMTYPE_TWO);
	}

	//�@�������v
	Setitem(D3DXVECTOR3(-1500.0f, 0.0f, 700.0f), ITEMTYPE_THREE);

	//	�~�}��
	Setitem(D3DXVECTOR3(0.0f, 0.0f, 0.0f), ITEMTYPE_FIVE);

	//�@�r���{�[�h(��)
	SetBillboard(D3DXVECTOR3(-100.0f, 50.0f, -200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_0,D3DXVECTOR3(15.0f,35.0f,0.0f));

	//	�r���{�[�h(�E��)
	SetBillboard(D3DXVECTOR3(-100.0f, 75.0f, -100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_1, D3DXVECTOR3(2.0f, 2.0f, 0.0f));
	SetBillboard(D3DXVECTOR3(-100.0f, 75.0f, -100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_1, D3DXVECTOR3(2.0f, 2.0f, 0.0f));

	//	�r���{�[�h(0/2)
	SetBillboard(D3DXVECTOR3(-1785.0f, 75.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_2, D3DXVECTOR3(4.0f, 4.0f, 0.0f));

	//	�r���{�[�h(1/2)
	SetBillboard(D3DXVECTOR3(-1780.0f, 75.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_3, D3DXVECTOR3(4.0f, 4.0f, 0.0f));

	//	�r���{�[�h(�E�o�\)
	SetBillboard(D3DXVECTOR3(-1780.0f, 75.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_4, D3DXVECTOR3(4.0f, 4.0f, 0.0f));

	//	�r���{�[�h(����)
	SetBillboard(D3DXVECTOR3(-1750.0f, 75.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_5, D3DXVECTOR3(1.0f, 1.0f, 0.0f));

	//�@�G
	SetEnemy(D3DXVECTOR3(-1750.0f, 0.0f, 0.0f),0);

	//�@�h�A
	SetGimmick(D3DXVECTOR3(-1800.0f, 0.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//	����UI
	SetKeyUI(D3DXVECTOR3(960.0f, 80.0f, 0.0f), ITEMKEYUITYPE_NO5, 30.0f, 30.0f);

	//	�Q�[�W
	SetGauge(D3DXVECTOR3(640.0f, 0.0f, 0.0f));

	//�@�ڂ�UI
	InitEyeUI();

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

	//�@�ڂ�UI
	UninitEyeUI();

	//	�S���U���X
	UinitGonzaresu();

	UninitUnlock();

	//	�Q�[�W
	UinitGauge();

	// ����UI
	UinitCancellation();

	// ����UI
	UninitKeyUI();

	// �A�C�e����UI
	UninitItemUI();

	// �X�^�~�i
	UninitStamina();

	//	��
	UinitNannjamo();

	//	�G���_�̃r���[�|�[�g�̘g
	UninitViewUI();

}

//---------------
//	�X�V����
//---------------
void UpdateGame(void)
{
	bool isGoal = IsGoal();			// �S�[���̔���

	Player* pPlayer = GetPlayer();	//�@�v���C���[���擾

	// �|�[�Y����
	if (KeybordTrigger(DIK_TAB) || JoyPadTrigger(JOYKEY_START) == true)
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
# if 1			//���b�V���t�B�[���h
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

			//�M�~�b�N
			UpdateGimmick();

			//�^�C��
			UpdateTime();

			//�r���{�[�h
			UpdateBillboard();

			//�A�C�e��
			Updateitem();

			//�ڂ�UI
			UpdateEyeUI();

			//	�S���U���X
			UpdateGonzaresu();

			UpdateUnlock();

			//	�Q�[�W
			UpdateGauge();

			// ����UI
			UpdateCancellation();

			//�@����UI
			UpdateKeyUI();

			// �A�C�e����UI
			UpdateItemUI();

			// �X�^�~�i
			UpdateStamina();

			// ��
			UpdateNannjamo();

			//	�G���_�̃r���[�|�[�g�̘g
			UpdateViewUI();

			// �X���[
			UpdateSlow();
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
void DrawGame(int nIdx)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//FOG�̐ݒ�
	//SetupVertexFog(D3DCOLOR_XRGB(0, 0, 0), D3DFOG_LINEAR, TRUE, 0.08f);

	//�@�e�I�u�W�F�N�g�̕`�揈��

	//�@���b�V���t�B�[���h
	DrawMeshfield();

	//�@�u���b�N
	DrawBlock();

	//�@�A�C�e��
	Drawitem();

	switch (nIdx)
	{
	case 0:

		//�@�G
		DrawEnemy();
		break;

	case 1:
		//�@�v���C���[
		DrawPlayer();
		break;

	default:
		break;
	}
	////�@���b�V���t�B�[���h
	//DrawMeshfield();

	////�@�u���b�N
	//DrawBlock();

	////�@�A�C�e��
	//Drawitem();

	//�@�v���C���[
	//DrawPlayer();

	////�@�G
	//DrawEnemy();

	//�@�M�~�b�N
	DrawGimmick();

	//FOG������
	//pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);

	// �X���[
	DrawSlow();

	// �X�^�~�i
	DrawStamina();

	//�@�r���{�[�h
	DrawBillboard();

	//	�S���U���X
	DrawGonzaresu();

	//�@�^�C��
	DrawTime();

	//�@�ڂ�UI
	DrawEyeUI();

	DrawUnlock();

	//	�Q�[�W
	DrawGauge();

	// ����UI
	DrawCancellation();

	//	����UI
	DrawKeyUI();

	// �A�C�e����UI
	DrawItemUI();

	//	��
	DrawNannjamo();

	//	�G���_�̃r���[�|�[�g�̘g
	DrawViewUI();

	//FOG��߂�
	//pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);


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