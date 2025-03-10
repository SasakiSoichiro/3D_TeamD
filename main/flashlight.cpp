//======================================================
//
//		懐中電灯  flashlight.cpp
//		Auther:Sasaki Soichiro
//
//======================================================
#include "flashlight.h"
#include "main.h"
#include "player.h"
#include "input.h"
#include "camera.h"

//	グローバル
FLASHLIGHT g_FlashLight[MAX_FLASH];

void InitFlashLight(void)
{
	//	デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	D3DXVECTOR3 vecDir[MAX_FLASH];

	//プレイヤー情報の取得
	Player* pPlayer = GetPlayer();

	//	ライトをクリアする
	ZeroMemory(&g_FlashLight, sizeof(D3DLIGHT9) * MAX_FLASH);

	for (int nCntLight = 0; nCntLight < MAX_FLASH; nCntLight++)
	{
		g_FlashLight[nCntLight].light.Type = D3DLIGHT_POINT;  // スポットライト
		g_FlashLight[nCntLight].light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// 白色の拡散光
		g_FlashLight[nCntLight].light.Specular = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);  // 鮮明な光
		g_FlashLight[nCntLight].light.Ambient = D3DXCOLOR(0.1f, 0.1f, 0.1f, 1.0f);   // 周囲の光
		g_FlashLight[nCntLight].light.Range = 10.0f;  // 光の到達距離
		g_FlashLight[nCntLight].light.Position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);  // 初期位置
		g_FlashLight[nCntLight].light.Falloff = 1.0f;  // 光の減衰
		g_FlashLight[nCntLight].light.Attenuation0 = 1.0f;
		g_FlashLight[nCntLight].light.Attenuation1 = 0.0f;
		g_FlashLight[nCntLight].light.Attenuation2 = 0.0f;
		// スポットライトの角度（懐中電灯のビームの広がり）
		//g_FlashLight[nCntLight].light.Theta = D3DXToRadian(60.0f);  // ビームの広がり（30度の角度）
		//g_FlashLight[nCntLight].light.Phi = D3DXToRadian(120.0f);    // ビームの範囲（60度の角度）
		g_FlashLight[nCntLight].bLight = false;

		//	ライトを設定する
		pDevice->SetLight(nCntLight, &g_FlashLight[nCntLight].light);

		//	ライトを有効にする
		pDevice->LightEnable(nCntLight, TRUE);
	}
}

void UninitFlashLight(void)
{

	//	デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	for (int nCntLight = 0; nCntLight < MAX_FLASH; nCntLight++)
	{
		//	ライトを有効にする
		pDevice->LightEnable(nCntLight, FALSE);
	}
}

void UpdateFlashLight(void)
{

	//プレイヤー情報の取得
	Player* pPlayer = GetPlayer();

	Camera* pCamera = GetCamera();

	//	デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	for (int nCntLight = 0; nCntLight < MAX_FLASH; nCntLight++)
	{
		if (g_FlashLight[nCntLight].bLight == true)
		{
			g_FlashLight[nCntLight].light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// 白色の拡散光

			g_FlashLight[nCntLight].light.Position = pPlayer->pos;

			g_FlashLight[nCntLight].light.Position.y = pPlayer->pos.y+100.0f;

			g_FlashLight[nCntLight].light.Direction = pCamera->rot;  // プレイヤーの向いている方向にライトを向ける

			g_FlashLight[nCntLight].light.Range = 800.0f;  // 光の到達距離

			//	ライトを設定する
			pDevice->SetLight(nCntLight, &g_FlashLight[nCntLight].light);

		}
		else if (g_FlashLight[nCntLight].bLight == false)
		{
			g_FlashLight[nCntLight].light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// 白色の拡散光

			g_FlashLight[nCntLight].light.Position = pPlayer->pos;

			g_FlashLight[nCntLight].light.Position.y = pPlayer->pos.y + 100.0f;

			g_FlashLight[nCntLight].light.Direction = pCamera->rot;  // プレイヤーの向いている方向にライトを向ける

			g_FlashLight[nCntLight].light.Range = 10.0f;  // 光の到達距離

			//	ライトを設定する
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
		g_FlashLight[nCntLight].light.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);		// 白色の拡散光
		g_FlashLight[nCntLight].light.Position = D3DXVECTOR3(pos.x, pos.y, pos.z); // ライトの位置
		g_FlashLight[nCntLight].light.Range = 100.0f;
	}
}
FLASHLIGHT* GetFlashLight(void)
{
	return &g_FlashLight[0];
}