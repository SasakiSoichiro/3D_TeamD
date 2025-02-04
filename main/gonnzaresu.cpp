//==============================================
//
//
//			ゴンザレス(血しぶき)のしょり
//
//
//===============================================
#include "gonnzaresu.h"
#include "ui.h"
#include "player.h"

//	グローバル
UI g_ui = {};
//テクスチャへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureUI = NULL;
//頂点バッファへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffUI = NULL;

//====================
//	初期化処理
//====================
void InitGonzaresu(void)
{
	g_ui.ui = UI_IN;
	g_ui.col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	g_ui.count = 0;
	g_ui.bUse = false;

	//	デバイス情報の取得
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\Gonzaresu.png",
		&g_pTextureUI);

	//	頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffUI,
		NULL);

	VERTEX_2D* pVtx;
	//	ロック
	g_pVtxBuffUI->Lock(0, 0, (void**)&pVtx, 0);

	//	頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

	//	rhwの設定
	pVtx[0].rhw = 1.0f;
	pVtx[1].rhw = 1.0f;
	pVtx[2].rhw = 1.0f;
	pVtx[3].rhw = 1.0f;

	//	tex座標
	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	//	頂点カラー
	pVtx[0].col = D3DXCOLOR(g_ui.col);
	pVtx[1].col = D3DXCOLOR(g_ui.col);
	pVtx[2].col = D3DXCOLOR(g_ui.col);
	pVtx[3].col = D3DXCOLOR(g_ui.col);

	//	アンロック
	g_pVtxBuffUI->Unlock();
}

//====================
//	終了処理
//====================
void UinitGonzaresu(void)
{
	//テクスチャの破棄
	if (g_pTextureUI != NULL)
	{
		g_pTextureUI->Release();
		g_pTextureUI = NULL;
	}

	//頂点バッファの解放
	if (g_pVtxBuffUI != NULL)
	{
		g_pVtxBuffUI->Release();
		g_pVtxBuffUI = NULL;
	}
}

//====================
//	更新処理
//====================
void UpdateGonzaresu(void)
{
	Player* pPlayer = GetPlayer();

	if (g_ui.ui != UI_NONE)
	{
		if (g_ui.ui == UI_IN)
		{
			//	フェードイン
			g_ui.col.a -= 0.01f;		//ポリゴンが透明になる速さ
			if (g_ui.col.a <= 0.0f)
			{
				g_ui.col.a = 0.0f;
				g_ui.ui = UI_NONE;		//何もしていない状態
			}
		}
		else if (g_ui.ui == UI_OUT)
		{
			//	フェードアウト
			g_ui.col.a += 0.02f;

			if (g_ui.col.a >= 1.0f)
			{
				g_ui.col.a = 1.0f;
				g_ui.ui = UI_NONE;
			}
		}

		VERTEX_2D* pVtx;
		//	ロック
		g_pVtxBuffUI->Lock(0, 0, (void**)&pVtx, 0);

		//	頂点カラー
		pVtx[0].col = D3DXCOLOR(g_ui.col);
		pVtx[1].col = D3DXCOLOR(g_ui.col);
		pVtx[2].col = D3DXCOLOR(g_ui.col);
		pVtx[3].col = D3DXCOLOR(g_ui.col);

		//	アンロック
		g_pVtxBuffUI->Unlock();
	}

	if (g_ui.bUse == true)
	{
		g_ui.count--;
	}

	if (g_ui.count <= 0 && g_ui.ui == UI_NONE && pPlayer->nLife >= 2 && g_ui.bUse == true)
	{
		g_ui.ui = UI_IN;
		g_ui.bUse = false;
		g_ui.count = 0;
	}
	else if (g_ui.count <= 0 && pPlayer->nLife <= 1 && g_ui.bUse == true)
	{
		g_ui.ui = UI_NONE;
		g_ui.count = 0;
	}
}

//====================
//	描画処理
//====================
void DrawGonzaresu(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//頂点フォーマットの設定
	pDevice->SetStreamSource(0, g_pVtxBuffUI, 0, sizeof(VERTEX_2D));

	//頂点フォーマット設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	if (g_ui.bUse == true)
	{
		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureUI);

		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	}
}

//====================
//	配置処理
//====================
void SetGonzaresu(int count)
{
	g_ui.ui = UI_OUT;
	g_ui.count = count;
	g_ui.bUse = true;
}