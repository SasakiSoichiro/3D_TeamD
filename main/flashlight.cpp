//======================================================
//
//		�����d��  flashlight.cpp
//		Auther:Sasaki Soichiro
//
//======================================================
#include "flashlight.h"
#include "main.h"
#include "player.h"
#include "input.h"
#include "camera.h"

//	�O���[�o��
FLASHLIGHT g_FlashLight[MAX_FLASH];

void InitFlashLight(void)
{
	//	�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXVECTOR3 vecDir[MAX_FLASH];

	//�v���C���[���̎擾
	Player* pPlayer = GetPlayer();

	//	���C�g���N���A����
	ZeroMemory(&g_FlashLight, sizeof(D3DLIGHT9) * MAX_FLASH);

	for (int nCntLight = 0; nCntLight < MAX_FLASH; nCntLight++)
	{
		g_FlashLight[nCntLight].light.Type = D3DLIGHT_POINT;  // �X�|�b�g���C�g
		g_FlashLight[nCntLight].light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// ���F�̊g�U��
		g_FlashLight[nCntLight].light.Specular = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);  // �N���Ȍ�
		g_FlashLight[nCntLight].light.Ambient = D3DXCOLOR(0.1f, 0.1f, 0.1f, 1.0f);   // ���͂̌�
		g_FlashLight[nCntLight].light.Range = 10.0f;  // ���̓��B����
		g_FlashLight[nCntLight].light.Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);  // �����ʒu
		g_FlashLight[nCntLight].light.Falloff = 1.0f;  // ���̌���
		g_FlashLight[nCntLight].light.Attenuation0 = 1.0f;
		g_FlashLight[nCntLight].light.Attenuation1 = 0.0f;
		g_FlashLight[nCntLight].light.Attenuation2 = 0.0f;
		// �X�|�b�g���C�g�̊p�x�i�����d���̃r�[���̍L����j
		//g_FlashLight[nCntLight].light.Theta = D3DXToRadian(60.0f);  // �r�[���̍L����i30�x�̊p�x�j
		//g_FlashLight[nCntLight].light.Phi = D3DXToRadian(120.0f);    // �r�[���͈̔́i60�x�̊p�x�j
		g_FlashLight[nCntLight].bLight = false;

		//	���C�g��ݒ肷��
		pDevice->SetLight(nCntLight, &g_FlashLight[nCntLight].light);

		//	���C�g��L���ɂ���
		pDevice->LightEnable(nCntLight, TRUE);
	}
}

void UninitFlashLight(void)
{

	//	�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	for (int nCntLight = 0; nCntLight < MAX_FLASH; nCntLight++)
	{
		//	���C�g��L���ɂ���
		pDevice->LightEnable(nCntLight, FALSE);
	}
}

void UpdateFlashLight(void)
{

	//�v���C���[���̎擾
	Player* pPlayer = GetPlayer();

	Camera* pCamera = GetCamera();

	//	�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	for (int nCntLight = 0; nCntLight < MAX_FLASH; nCntLight++)
	{
		if (g_FlashLight[nCntLight].bLight == true)
		{
			g_FlashLight[nCntLight].light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// ���F�̊g�U��

			g_FlashLight[nCntLight].light.Position = pPlayer->pos;

			g_FlashLight[nCntLight].light.Position.y = pPlayer->pos.y+100.0f;

			g_FlashLight[nCntLight].light.Direction = pCamera->rot;  // �v���C���[�̌����Ă�������Ƀ��C�g��������

			g_FlashLight[nCntLight].light.Range = 800.0f;  // ���̓��B����

			//	���C�g��ݒ肷��
			pDevice->SetLight(nCntLight, &g_FlashLight[nCntLight].light);

		}
		else if (g_FlashLight[nCntLight].bLight == false)
		{
			g_FlashLight[nCntLight].light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// ���F�̊g�U��

			g_FlashLight[nCntLight].light.Position = pPlayer->pos;

			g_FlashLight[nCntLight].light.Position.y = pPlayer->pos.y + 100.0f;

			g_FlashLight[nCntLight].light.Direction = pCamera->rot;  // �v���C���[�̌����Ă�������Ƀ��C�g��������

			g_FlashLight[nCntLight].light.Range = 10.0f;  // ���̓��B����

			//	���C�g��ݒ肷��
			pDevice->SetLight(nCntLight, &g_FlashLight[nCntLight].light);

		}

		
	}

}
void SetupFlashLight(D3DXVECTOR3 pos)
{
	ZeroMemory(&g_FlashLight, sizeof(g_FlashLight));
	for (int nCntLight = 0; nCntLight < MAX_FLASH; nCntLight++)
	{
		g_FlashLight[nCntLight].light.Type = D3DLIGHT_POINT;
		g_FlashLight[nCntLight].light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// ���F�̊g�U��
		g_FlashLight[nCntLight].light.Position = D3DXVECTOR3(pos.x, pos.y, pos.z); // ���C�g�̈ʒu
		g_FlashLight[nCntLight].light.Range = 100.0f;
	}
}
FLASHLIGHT* GetFlashLight(void)
{
	return &g_FlashLight[0];
}