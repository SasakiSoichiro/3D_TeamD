//=============================================================================
//
//　アイテムUI処理 [itemUI.cpp]
// 　Author : 佐々木奏一郎
//
//=============================================================================
#include "itemUI.h"
#include "player.h"
#include "input.h"

#define MAX_ITEMUI (3)
#define ITEMUI_SIZE (60)

//グローバル変数
LPDIRECT3DTEXTURE9 g_pTextureItemUI[ITEM_MAX] = {};		//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffItemUI = NULL;		//頂点バッファへのポインタ
ItemUI g_aItemUI[MAX_ITEMUI];							//ブロックの情報

//=====================
//ブロックの初期化処理
//=====================
void InitItemUI(void)
{
	//ローカル変数
	LPDIRECT3DDEVICE9 pDevice;	//デバイスへのポインタ
	VERTEX_2D* pVtx = 0;		//頂点情報へのポインタ

	//デバイスの取得
	pDevice = GetDevice();
	for (int nCnt = 0; nCnt < ITEM_MAX; nCnt++)
	{
		//テクスチャの読み込み
		D3DXCreateTextureFromFile(pDevice,
			ITEM_TEXTURE[nCnt],
			&g_pTextureItemUI[nCnt]);
	}
	//ループ処理
	for (int nCntBlock = 0; nCntBlock < MAX_ITEMUI; nCntBlock++)
	{//ブロックの数分ループする

		g_aItemUI[nCntBlock].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//位置を初期化する
		g_aItemUI[nCntBlock].move = D3DXVECTOR3(0.0f, 0.0f, 0.0f);	//移動値を初期化する
		g_aItemUI[nCntBlock].fWidth = 0.0f;							//幅を初期化する
		g_aItemUI[nCntBlock].fHeight = 0.0f;						//高さを初期化する
		g_aItemUI[nCntBlock].nType = ITEM_A;						//種類を初期化する
		g_aItemUI[nCntBlock].bUse = false;							//使われていない状態にする	
	}


	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ITEMUI,//(sizeof(VERTEX_2D)*必要な頂点数
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffItemUI,
		NULL);


	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffItemUI->Lock(0, 0, (void**)&pVtx, 0);

	//ループ処理
	for (int nCntBlock = 0; nCntBlock < MAX_ITEMUI; nCntBlock++)
	{//ブロックの数分ループする

		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(1000.0f + nCntBlock * ITEMUI_SIZE, 50.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(1000.0f + nCntBlock * ITEMUI_SIZE + ITEMUI_SIZE, 50.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(1000.0f + nCntBlock * ITEMUI_SIZE, 50.0f + ITEMUI_SIZE, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(1000.0f + nCntBlock * ITEMUI_SIZE + ITEMUI_SIZE, 50.0f + ITEMUI_SIZE, 0.0f);

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

		pVtx += 4;//頂点データのポインタを4つ分集める
	}
	//頂点バッファをアンロックする
	g_pVtxBuffItemUI->Unlock();
}

//==================
//ブロックの終了処理
//==================
void UninitItemUI(void)
{
	for (int nCnt = 0; nCnt < ITEM_MAX; nCnt++)
	{
		//テクスチャの破棄
		if (g_pTextureItemUI[nCnt] != NULL)
		{
			g_pTextureItemUI[nCnt]->Release();
			g_pTextureItemUI[nCnt] = NULL;
		}
	}

	//頂点バッファの破棄
	if (g_pVtxBuffItemUI != NULL)
	{
		g_pVtxBuffItemUI->Release();
		g_pVtxBuffItemUI = NULL;
	}

}

//==================
//ブロックの更新処理
//==================
void UpdateItemUI(void)
{
	if (KeyboardTrigger(DIK_1) == true)
	{
		for (int nCnt = 0; nCnt < ITEM_MAX; nCnt++)
		{
			if (g_aItemUI[nCnt].nType == ITEM_A)
			{
				g_aItemUI[nCnt].nType = ITEM_B;

				break;
			}
		}
	}
	else if (KeyboardTrigger(DIK_2) == true)
	{
		for (int nCnt = 0; nCnt < ITEM_MAX; nCnt++)
		{
			if (g_aItemUI[nCnt].nType == ITEM_A)
			{
				g_aItemUI[nCnt].nType = ITEM_C;

				break;
			}
		}
	}
}

//==================
//ブロックの描画処理
//==================
void DrawItemUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;//デバイスへのポインタ

	//デバイスの取得
	pDevice = GetDevice();
	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffItemUI, 0, sizeof(VERTEX_2D));
	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//ループ処理
	for (int nCntItemUI = 0; nCntItemUI < MAX_ITEMUI; nCntItemUI++)
	{//ブロックの数分ループする


			//テクスチャの設定
		pDevice->SetTexture(ITEM_A, g_pTextureItemUI[g_aItemUI[nCntItemUI].nType]);
		pDevice->SetTexture(ITEM_B, g_pTextureItemUI[g_aItemUI[nCntItemUI].nType]);
		pDevice->SetTexture(ITEM_C, g_pTextureItemUI[g_aItemUI[nCntItemUI].nType]);
		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 4 * nCntItemUI, 2);
	}
}