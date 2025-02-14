//====================================================
//
// アイテム表示の処理 [ItemUI.cpp]
// Author : yabuki yukito
//
//====================================================

#include "ItemUI.h"
#include "item.h"

//グローバル変数
LPDIRECT3DTEXTURE9 g_ItemUiTexture[ITEMUITYPE_MAX] = { };	//Uiテクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffItemUi = NULL;	//Uiバッファへのポインタ
ITEMUI g_ItemUI[ITEMUITYPE_MAX];
bool bHave;

//====================================================
//アイテムUI表示の初期化処理
//====================================================
void InitItemUI()
{

	LPDIRECT3DDEVICE9 pDevice;					//デバイスへのポインタ

	pDevice = GetDevice();						//デバイスの取得

	//テクスチャの読み込み
	for (int nCnt = 0; nCnt < ITEMUITYPE_MAX; nCnt++)
	{
		D3DXCreateTextureFromFile(pDevice,
			ITEMUI_TEXTURE[nCnt],
			&g_ItemUiTexture[nCnt]);
	}

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * ITEMUITYPE_MAX,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffItemUi, NULL);

	//頂点情報へのポインタ
	VERTEX_2D* pVtx;

	//頂点バッファのロック、頂点データへのポインタ取得
	g_pVtxBuffItemUi->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < ITEMUITYPE_MAX; nCnt++)
	{
		// 構造体変数の初期化
		g_ItemUI[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_ItemUI[nCnt].fHeight = 0.0f;
		g_ItemUI[nCnt].fWidth = 0.0f;
		g_ItemUI[nCnt].bUse = false;
		bHave = false;

		//頂点座標の設定
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

		pVtx += 4;
	}

	//頂点バッファをアンロック
	g_pVtxBuffItemUi->Unlock();

}
//====================================================
//アイテムUI表示の終了処理
//====================================================
void UninitItemUI()
{

	//テクスチャの破棄
	for (int nCnt = 0; nCnt < ITEMUITYPE_MAX; nCnt++)
	{
		if (g_ItemUiTexture[nCnt] != NULL)
		{
			g_ItemUiTexture[nCnt]->Release();
			g_ItemUiTexture[nCnt] = NULL;
		}
	}

	//頂点バッファの破棄
	if (g_pVtxBuffItemUi != NULL)
	{
		g_pVtxBuffItemUi->Release();
		g_pVtxBuffItemUi = NULL;
	}

}
//====================================================
//アイテムUI表示の更新処理
//====================================================
void UpdateItemUI()
{
	// アイテムの取得処理
	ITEM* pItem = Getitem();

	for (int nCnt = 0; nCnt < ITEMUITYPE_MAX; nCnt++, pItem++)
	{
		if (pItem->bKey_Top == true)
		{
			bHave = true;
		}
	}
}
//====================================================
//アイテムUI表示の描画処理
//====================================================
void DrawItemUI()
{
	//デバイスへのポインタ
	LPDIRECT3DDEVICE9 pDevice;

	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffItemUi, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int nCnt = 0; nCnt < ITEMUITYPE_MAX; nCnt++)
	{
		int nType = g_ItemUI[nCnt].nType;

		if (g_ItemUI[nCnt].bUse == true)
		{
			if (bHave == true)
			{
				//テクスチャの設定
				pDevice->SetTexture(0, g_ItemUiTexture[11]);
			}
			else
			{
				//テクスチャの設定
				pDevice->SetTexture(0, g_ItemUiTexture[nType]);
			}
			//アイテムUIの描画
			pDevice->DrawPrimitive(
				D3DPT_TRIANGLESTRIP,//プリミティブの種類
				nCnt * 4,//描画する最初の頂点インデックス
				2//プリミティブ（アイテムUI）の数
			);
		}
	}
}
//====================================================
//アイテムUIの設定処理
//====================================================
void SetItemUI(D3DXVECTOR3 pos, ITEMUITYPE nType, float fWidth, float fHeight)
{
	// 頂点情報のポインタ
	VERTEX_2D* pVtx;

	//頂点バッファのロック、頂点データへのポインタ取得
	g_pVtxBuffItemUi->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < ITEMUITYPE_MAX; nCnt++)
	{
		if (g_ItemUI[nCnt].bUse == false)
		{// 未使用状態だったら
			g_ItemUI[nCnt].pos = pos;
			g_ItemUI[nCnt].nType = nType;
			g_ItemUI[nCnt].fHeight = fHeight;
			g_ItemUI[nCnt].fWidth = fWidth;
			g_ItemUI[nCnt].bUse = true;

			//頂点座標の設定
			pVtx[0].pos = D3DXVECTOR3(g_ItemUI[nCnt].pos.x - fWidth, g_ItemUI[nCnt].pos.y - fHeight, 0.0f);
			pVtx[1].pos = D3DXVECTOR3(g_ItemUI[nCnt].pos.x + fWidth, g_ItemUI[nCnt].pos.y - fHeight, 0.0f);
			pVtx[2].pos = D3DXVECTOR3(g_ItemUI[nCnt].pos.x - fWidth, g_ItemUI[nCnt].pos.y + fHeight, 0.0f);
			pVtx[3].pos = D3DXVECTOR3(g_ItemUI[nCnt].pos.x + fWidth, g_ItemUI[nCnt].pos.y + fHeight, 0.0f);

			break;
		}
		pVtx += 4;
	}

	//頂点バッファをアンロック
	g_pVtxBuffItemUi->Unlock();

}