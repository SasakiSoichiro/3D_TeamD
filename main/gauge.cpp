//==============================================
//
//
//			ゲージのしょり
//
//				ひらひら
//
//===============================================
#include "gauge.h"
#include "input.h"
#include "player.h"
#include "gimmick.h"
#include "item.h"

//	グローバル
Gauge g_gauge = {};
LPDIRECT3DTEXTURE9 g_GaugeTexture = NULL;			//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffGauge = NULL;	//バッファへのポインタ

//===================
//	初期化処理
//===================
void InitGauge(void)
{
	VERTEX_2D* pVtx{};

	LPDIRECT3DDEVICE9 pDevice;					//デバイスへのポインタ
	pDevice = GetDevice();						//デバイスの取得

	g_gauge.bKeyhave = false;
	g_gauge.bUse = false;
	g_gauge.fCnt = 0.0f;
	g_gauge.pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\hold.jpg",
		&g_GaugeTexture);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffGauge, NULL);

	//頂点バッファのロック、頂点データへのポインタ取得
	g_pVtxBuffGauge->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//頂点カラーの設定
	pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	//テクスチャ座標の設定
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//頂点バッファをアンロック
	g_pVtxBuffGauge->Unlock();

}

//===================
//	終了処理
//===================
void UinitGauge(void)
{
	//テクスチャの破棄
	if (g_GaugeTexture != NULL)
	{
		g_GaugeTexture->Release();
		g_GaugeTexture = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffGauge != NULL)
	{
		g_pVtxBuffGauge->Release();
		g_pVtxBuffGauge = NULL;
	}
}

//===================
//	更新処理
//===================
void UpdateGauge(void)
{
	Player* pPlayer = GetPlayer();
	GIMMICK* pGimmick = GetGimmick();
	ITEM* pItem = Getitem();

	VERTEX_2D* pVtx{};
	//頂点バッファのロック、頂点データへのポインタ取得
	g_pVtxBuffGauge->Lock(0, 0, (void**)&pVtx, 0);

	if (g_gauge.bUse)
	{
		//プレイヤーの半径の算出用変数
		float fPRadPos = 50.0f;

		//アイテムの半径の算出用変数
		float fIRadPos = 50.0f;

		//アイテムのプレイヤーの距離の差
		D3DXVECTOR3 diff = pPlayer->pos - pGimmick->pos;

		//範囲計算
		float fDisX = pPlayer->pos.x - pGimmick->pos.x;
		float fDisY = pPlayer->pos.y - pGimmick->pos.y;
		float fDisZ = pPlayer->pos.z - pGimmick->pos.z;

		//二つの半径を求める
		float fRadX = fPRadPos + fIRadPos;

		//プレイヤーがアイテムの範囲に入ったら
		if ((fDisX * fDisX) + (fDisY * fDisY) + (fDisZ * fDisZ) <= (fRadX * fRadX))
		{

			if (GetKeyboardPress(DIK_F) || GetJoypadPress(JOYKEY_X) == true)
			{
				g_gauge.fCnt += 0.011f;
			}
			else if(g_gauge.fCnt >= 0)
			{
				g_gauge.fCnt -= 0.005f;
			}

			if (g_gauge.fCnt >= 30.0f)
			{
				g_gauge.fCnt = 30.0f;
			}
			else if (g_gauge.fCnt < 0)
			{
				g_gauge.fCnt = 0.0f;
			}

			pVtx[0].pos.x = 320.0f;
			pVtx[0].pos.y = 400.0f;
			pVtx[0].pos.z = 0.0f;

			pVtx[1].pos.x = 320.0f * g_gauge.fCnt;
			pVtx[1].pos.y = 400.0f;
			pVtx[1].pos.z = 0.0f;

			pVtx[2].pos.x = 320.0f;
			pVtx[2].pos.y = 450.0f;
			pVtx[2].pos.z = 0.0f;

			pVtx[3].pos.x = 320.0f * g_gauge.fCnt;
			pVtx[3].pos.y = 450.0f;
			pVtx[3].pos.z = 0.0f;
		}
	}

	//頂点バッファをアンロック
	g_pVtxBuffGauge->Unlock();
}

//===================
//	描画処理
//===================
void DrawGauge(void)
{
	//	デバイスへのポインタ
	LPDIRECT3DDEVICE9 pDevice;		

	//	デバイスの取得
	pDevice = GetDevice();			

	//	頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffGauge, 0, sizeof(VERTEX_2D));

	//	頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	if (g_gauge.bUse == true)
	{
		//	テクスチャの設定
		pDevice->SetTexture(0, g_GaugeTexture);

		//	ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	}
}

//===================
//	配置処理
//===================
void SetGauge(D3DXVECTOR3 pos)
{
	if (g_gauge.bUse == false)
	{
		g_gauge.pos = pos;
		g_gauge.bUse = true;
	}
}