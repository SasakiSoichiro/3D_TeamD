//==============================================
//
//
//			なんじゃも(回復)のしょり
//
//
//===============================================
#include "nannjamo.h"
#include "ui.h"
#include "player.h"

//	グローバル
Nannjamo g_nannjamo = {};
//テクスチャへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureNannjamo = NULL;
//頂点バッファへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffNannjamo = NULL;

//====================
//	初期化処理
//====================
void InitNannjamo(void)
{
	g_nannjamo.ui = Nannjamo_IN;
	g_nannjamo.col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	g_nannjamo.count = 0;
	g_nannjamo.bUse = false;

	//	デバイス情報の取得
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\heal1.png",
		&g_pTextureNannjamo);

	//	頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffNannjamo,
		NULL);

	VERTEX_2D* pVtx;
	//	ロック
	g_pVtxBuffNannjamo->Lock(0, 0, (void**)&pVtx, 0);

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
	pVtx[0].col = D3DXCOLOR(g_nannjamo.col);
	pVtx[1].col = D3DXCOLOR(g_nannjamo.col);
	pVtx[2].col = D3DXCOLOR(g_nannjamo.col);
	pVtx[3].col = D3DXCOLOR(g_nannjamo.col);

	//	アンロック
	g_pVtxBuffNannjamo->Unlock();
}

//====================
//	終了処理
//====================
void UinitNannjamo(void)
{
	//テクスチャの破棄
	if (g_pTextureNannjamo != NULL)
	{
		g_pTextureNannjamo->Release();
		g_pTextureNannjamo = NULL;
	}

	//頂点バッファの解放
	if (g_pVtxBuffNannjamo != NULL)
	{
		g_pVtxBuffNannjamo->Release();
		g_pVtxBuffNannjamo = NULL;
	}
}

//====================
//	更新処理
//====================
void UpdateNannjamo(void)
{
	Player* pPlayer = GetPlayer();

	if (g_nannjamo.ui != Nannjamo_NONE)
	{
		if (g_nannjamo.ui == Nannjamo_IN)
		{
			//	フェードイン
			g_nannjamo.col.a -= 0.01f;		//ポリゴンが透明になる速さ
			if (g_nannjamo.col.a <= 0.0f)
			{
				g_nannjamo.col.a = 0.0f;
				g_nannjamo.ui = Nannjamo_NONE;		//何もしていない状態
			}
		}
		else if (g_nannjamo.ui == Nannjamo_OUT)
		{
			//	フェードアウト
			g_nannjamo.col.a += 0.02f;

			if (g_nannjamo.col.a >= 1.0f)
			{
				g_nannjamo.col.a = 1.0f;
				g_nannjamo.ui = Nannjamo_NONE;
			}
		}

		VERTEX_2D* pVtx;
		//	ロック
		g_pVtxBuffNannjamo->Lock(0, 0, (void**)&pVtx, 0);

		//	頂点カラー
		pVtx[0].col = D3DXCOLOR(g_nannjamo.col);
		pVtx[1].col = D3DXCOLOR(g_nannjamo.col);
		pVtx[2].col = D3DXCOLOR(g_nannjamo.col);
		pVtx[3].col = D3DXCOLOR(g_nannjamo.col);

		//	アンロック
		g_pVtxBuffNannjamo->Unlock();
	}

	if (g_nannjamo.bUse == true)
	{
		g_nannjamo.count--;
	}

	if (g_nannjamo.count <= 0 && g_nannjamo.ui == Nannjamo_NONE && g_nannjamo.bUse == true)
	{
		g_nannjamo.ui = Nannjamo_IN;
		g_nannjamo.bUse = false;
		g_nannjamo.count = 0;
	}
}

//====================
//	描画処理
//====================
void DrawNannjamo(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//頂点フォーマットの設定
	pDevice->SetStreamSource(0, g_pVtxBuffNannjamo, 0, sizeof(VERTEX_2D));

	//頂点フォーマット設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	if (g_nannjamo.bUse == true)
	{
		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureNannjamo);

		//ポリゴンの描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	}
}

//====================
//	配置処理
//====================
void SetNannjamo(int count)
{
	g_nannjamo.ui = Nannjamo_OUT;
	g_nannjamo.count = count;
	g_nannjamo.bUse = true;
}