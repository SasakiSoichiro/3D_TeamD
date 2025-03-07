//====================================================
//
// スタミナの処理 [stamina.cpp]
// Author : Sasaki Soichiro
//
//====================================================

#include "stamina.h"
#include "player.h"
#include "enemy.h"

//マクロ定義
#define MAX_TIMEWIDTH (400)
#define MAX_TIMEHEIGHT (10)

//グローバル変数
D3DXVECTOR3 StaminaPos;								//スタミナの位置
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffStamina = NULL;	//バッファへのポインタ
int g_nCntState;
bool bStamina;
bool bScreen;
int g_nStamina;

//====================================================
//表示の初期化処理
//====================================================
void InitStamina()
{
	VERTEX_2D* pVtx{};

	LPDIRECT3DDEVICE9 pDevice;					//デバイスへのポインタ

	pDevice = GetDevice();						//デバイスの取得

	D3DXVECTOR3 pos = D3DXVECTOR3(50.0f, 700.0f, 0.0f);

	bStamina = true;
	bScreen = false;

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffStamina, NULL);

	//頂点バッファのロック、頂点データへのポインタ取得
	g_pVtxBuffStamina->Lock(0, 0, (void**)&pVtx, 0);

	//頂点情報の設定
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

	//rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//頂点バッファをアンロック
	g_pVtxBuffStamina->Unlock();
}

//====================================================
//表示の終了処理
//====================================================
void UninitStamina()
{

	//頂点バッファの破棄
	if (g_pVtxBuffStamina != NULL)
	{
		g_pVtxBuffStamina->Release();
		g_pVtxBuffStamina = NULL;
	}

}

//====================================================
//表示の更新処理
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
	{//プレイヤーが走っているとき

		if (pRange == false)
		{
			//スタミナ値を減らす
			pPlayer->nStamina--;

			if (pPlayer->nStamina <= 0)
			{//スタミナが0になったとき
				bStamina = false;
			}
		}
		else if (pRange == true)
		{
			//スタミナ値を減らす
			pPlayer->nStamina = pPlayer->nStamina - nDate;

			if (pPlayer->nStamina <= 0)
			{//スタミナが0になったとき
				bStamina = false;
			}
		}
	}
	else
	{
		if (pPlayer->nStamina <= 0)
		{//スタミナが0になったとき

			//カウントする
			g_nCntState++;

			if (g_nCntState >= 120)
			{//120Fたったら
				pPlayer->nStamina = 1;

				//カウントを初期化する
				g_nCntState = 0;

				//スタミナを使えるようにする
				bStamina = true;
			}

		}
		else if (pPlayer->nStamina < 300)
		{//スタミナが100未満で走っていないとき

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
	//頂点バッファのロック、頂点データへのポインタ取得
	g_pVtxBuffStamina->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[1].pos.x = StaminaPos.x + MAX_TIMEWIDTH * fStamina;

	pVtx[3].pos.x = StaminaPos.x + MAX_TIMEWIDTH * fStamina;


	//頂点バッファをアンロック
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
//表示の描画処理
//====================================================
void DrawStamina()
{
	LPDIRECT3DDEVICE9 pDevice;					//デバイスへのポインタ

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffStamina, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	if (bScreen == true)
	{
		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	}


}
bool GetStamina(void)
{
	return bStamina;
}