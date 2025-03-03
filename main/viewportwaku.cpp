//=============================================================================
//
//　敵視点のビューポートの枠の処理 [viewportwaku.cpp]
// 　Author : 近田尚也
//
//=============================================================================
#include "viewportwaku.h"

//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureViewUI = {};			//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffViewUI = NULL;	//頂点バッファへのポインタ

//====================================
//敵視点のビューポートの枠の初期化処理
//====================================
void InitViewUI(void)
{
	//ローカル変数
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ
	VERTEX_2D* pVtx;		//頂点情報へのポインタ

	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\enemywaku1.png",
		&g_pTextureViewUI);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,//(sizeof(VERTEX_2D)*必要な頂点数
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffViewUI,
		NULL);


	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffViewUI->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(417.5f, -20.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(836.0f, -20.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(417.5f, 227.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(836.0f, 227.0f, 0.0f);

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

	//頂点バッファをアンロックする
	g_pVtxBuffViewUI->Unlock();
}

//====================================
//敵視点のビューポートの枠の終了処理
//====================================
void UninitViewUI(void)
{

	//テクスチャの破棄
	if (g_pTextureViewUI != NULL)
	{
		g_pTextureViewUI->Release();
		g_pTextureViewUI = NULL;
	}


	//頂点バッファの破棄
	if (g_pVtxBuffViewUI != NULL)
	{
		g_pVtxBuffViewUI->Release();
		g_pVtxBuffViewUI = NULL;
	}

}

//====================================
//敵視点のビューポートの枠の更新処理
//====================================
void UpdateViewUI(void)
{

}

//====================================
//敵視点のビューポートの枠の描画処理
//====================================
void DrawViewUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//頂点フォーマットの設定
	pDevice->SetStreamSource(0, g_pVtxBuffViewUI, 0, sizeof(VERTEX_2D));

	//頂点フォーマット設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, g_pTextureViewUI);

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

}
