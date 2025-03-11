//=============================================================================
//
// 血しぶきの処理 [BloodSplatter.cpp]
// Author : Hirata ryuusei
//
//=============================================================================

#include "BloodSplatter.h"
#include "ui.h"
#include "player.h"
#include "item.h"

// グローバル変数

// テクスチャへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureUI[UITYPE_MAX] = {};

// 頂点バッファへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffUI = NULL;

UI g_ui[UITYPE_MAX] = {};

//====================
//	初期化処理
//====================
void InitBloodSplatter(void)
{
	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		g_ui[nCnt].ui = UI_IN;
		g_ui[nCnt].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		g_ui[nCnt].count = 0;
		g_ui[nCnt].bUse = false;
	}

	// デバイス情報の取得
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		D3DXCreateTextureFromFile(pDevice,
			UI_TEXTURE[nCnt],
			&g_pTextureUI[nCnt]);
	}

	// 頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * UITYPE_MAX,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffUI,
		NULL);

	VERTEX_2D* pVtx;

	// ロック
	g_pVtxBuffUI->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		// 頂点座標の設定
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

		// rhwの設定
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		// tex座標
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

		// 頂点カラー
		pVtx[0].col = D3DXCOLOR(g_ui[nCnt].col);
		pVtx[1].col = D3DXCOLOR(g_ui[nCnt].col);
		pVtx[2].col = D3DXCOLOR(g_ui[nCnt].col);
		pVtx[3].col = D3DXCOLOR(g_ui[nCnt].col);

		pVtx += 4;
	}

	// アンロック
	g_pVtxBuffUI->Unlock();
}

//====================
//	終了処理
//====================
void UinitBloodSplatter(void)
{
	// テクスチャの破棄
	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		if (g_pTextureUI[nCnt] != NULL)
		{
			g_pTextureUI[nCnt]->Release();
			g_pTextureUI[nCnt] = NULL;
		}
	}

	// 頂点バッファの解放
	if (g_pVtxBuffUI != NULL)
	{
		g_pVtxBuffUI->Release();
		g_pVtxBuffUI = NULL;
	}
}

//====================
//	更新処理
//====================
void UpdateBloodSplatter(void)
{
	Player* pPlayer = GetPlayer();
	ITEM* pItem = Getitem();
	bool bNeed = IsNeed();

	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		if (g_ui[nCnt].ui != UI_NONE)
		{
			if (g_ui[nCnt].ui == UI_IN)
			{
				// フェードイン
				g_ui[nCnt].col.a -= 0.01f;		// ポリゴンが透明になる速さ
				if (g_ui[nCnt].col.a <= 0.0f)
				{
					g_ui[nCnt].col.a = 0.0f;
					g_ui[nCnt].ui = UI_NONE;		// 何もしていない状態
				}
			}
			else if (g_ui[nCnt].ui == UI_OUT)
			{
				// フェードアウト
				g_ui[nCnt].col.a += 0.02f;

				if (g_ui[nCnt].col.a >= 1.0f)
				{
					g_ui[nCnt].col.a = 1.0f;
					g_ui[nCnt].ui = UI_NONE;
				}
			}

			VERTEX_2D* pVtx;

			// ロック
			g_pVtxBuffUI->Lock(0, 0, (void**)&pVtx, 0);

			// 頂点カラー
			pVtx[0].col = D3DXCOLOR(g_ui[nCnt].col);
			pVtx[1].col = D3DXCOLOR(g_ui[nCnt].col);
			pVtx[2].col = D3DXCOLOR(g_ui[nCnt].col);
			pVtx[3].col = D3DXCOLOR(g_ui[nCnt].col);

			pVtx += 4;

			// アンロック
			g_pVtxBuffUI->Unlock();
		}

		if (g_ui[nCnt].bUse == true)
		{
			g_ui[nCnt].count--;			// デクリメント
		}

		if (g_ui[nCnt].count <= 0 && pPlayer->nLife >= 2 && g_ui[nCnt].bUse == true)
		{
			g_ui[nCnt].ui = UI_NONE;		// フェードイン状態
			g_ui[nCnt].count = 0;
		}
		else if (g_ui[nCnt].count <= 0 && pPlayer->nLife <= 1 && g_ui[nCnt].bUse == true)
		{
			g_ui[nCnt].ui = UI_NONE;		// 何もしていない状態
			g_ui[nCnt].count = 0;
		}
		if (pPlayer->nLife >= 3)
		{
			g_ui[nCnt].bUse = false;	// 表示されていないとき
			g_ui[nCnt].ui = UI_IN;		// フェードイン状態
			g_ui[nCnt].count = 0;
		}
	}
}

//====================
//	描画処理
//====================
void DrawBloodSplatter(void)
{
	// デバイスへのポインタ、状態取得
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	Player* pPlayer = GetPlayer();

	// 頂点フォーマットの設定
	pDevice->SetStreamSource(0, g_pVtxBuffUI, 0, sizeof(VERTEX_2D));

	// 頂点フォーマット設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		if (g_ui[nCnt].bUse == true)
		{// テクスチャの設定

			if (g_ui[nCnt].count <= 0 && pPlayer->nLife >= 2 && g_ui[nCnt].bUse == true)
			{
				pDevice->SetTexture(0, g_pTextureUI[1]);
			}
			else if (g_ui[nCnt].count <= 0 && pPlayer->nLife <= 1 && g_ui[nCnt].bUse == true)
			{
				pDevice->SetTexture(0, g_pTextureUI[0]);
			}
		}
	}
	// ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

}

//====================
//	配置処理
//====================
void SetBloodSplatter(int count, UITYPE nType)
{
	for (int nCnt = 0; nCnt < UITYPE_MAX; nCnt++)
	{
		if (g_ui[nCnt].bUse == false)
		{
			g_ui[nCnt].ui = UI_OUT;		// フェードアウト状態
			g_ui[nCnt].count = count;
			g_ui[nCnt].nType = nType;
			g_ui[nCnt].bUse = true;		// 表示されているとき
			break;
		}
	}
}