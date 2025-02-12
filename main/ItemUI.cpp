//====================================================
//
// アイテム表示の処理 [ItemUI.cpp]
// Author : yabuki yukito
//
//====================================================

#include "ItemUI.h"

//グローバル変数
LPDIRECT3DTEXTURE9 g_ItemUiTexture[MAX_ITEMTEX] = {};	//Uiテクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffItemUi = NULL;	//Uiバッファへのポインタ

//====================================================
//アイテムUI表示の初期化処理
//====================================================
void InitItemUI()
{

	LPDIRECT3DDEVICE9 pDevice;					//デバイスへのポインタ

	pDevice = GetDevice();						//デバイスの取得

	//テクスチャの読み込み
	//枠
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\waku.png",
		&g_ItemUiTexture[0]);

	//懐中電灯
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\flashPicture.png",
		&g_ItemUiTexture[1]);

	//救急箱
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\heal.png",
		&g_ItemUiTexture[2]);

	//薙刀
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\naginata.png",
		&g_ItemUiTexture[3]);

	//懐中時計
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\time.png",
		&g_ItemUiTexture[4]);

	//鍵なし
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\NOkagi.png",
		&g_ItemUiTexture[5]);

	//1/2鍵持ち
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\YesNoKagi.png",
		&g_ItemUiTexture[6]);

	//鍵
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\Perfectkagi.png",
		&g_ItemUiTexture[7]);

	//位置の初期化
	D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_ITEMUI,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffItemUi, NULL);

	//頂点情報へのポインタ
	VERTEX_2D* pVtx;

	//頂点バッファのロック、頂点データへのポインタ取得
	g_pVtxBuffItemUi->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_ITEMUI; nCnt++)
	{
		//使用状態
		bool bUse = true;

		//頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(1000.0f + nCnt * 55.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(1000.0f + nCnt * 55.0f + 50.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(1000.0f + nCnt * 55.0f, 50.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(1000.0f + nCnt * 55.0f + 50.0f, 50.0f, 0.0f);

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
	for (int nCnt = 0; nCnt < MAX_ITEMTEX; nCnt++)
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

	for (int nCnt = 0; nCnt < MAX_ITEMTEX; nCnt++)
	{
		//テクスチャの設定
		pDevice->SetTexture(0, g_ItemUiTexture[0]);

		//タイマーの描画
		pDevice->DrawPrimitive(
			D3DPT_TRIANGLESTRIP,//プリミティブの種類
			nCnt * 4,//描画する最初の頂点インデックス
			2//プリミティブ（タイマー）の数
		);

	}

}
