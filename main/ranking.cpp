//=============================================================
//
// Athor: HRT ryuusei  ランキング
// 
//=============================================================
#include "ranking.h"
#include "input.h"
#include "fade.h"
#include "game.h"
#include "stdio.h"
#include "time.h"

//ランキングスコアの構造体
typedef struct
{
	D3DXVECTOR3 pos;	//位置
	int nRank;			//順位
	int nTime;			//タイマー
}RankTime;

//グローバル変数宣言
LPDIRECT3DTEXTURE9 g_pTextureBKG = NULL;			    //テクスチャへのポインタ(背景)
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBKG = NULL;			//頂点バッファへのポインタ(背景)

LPDIRECT3DTEXTURE9 g_pTextureRank = NULL;				//テクスチャへのポインタ(順位)
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffRank = NULL;			//頂点バッファへのポインタ(順位)

LPDIRECT3DTEXTURE9 g_pTextureRankTime = NULL;			//テクスチャへのポインタ(タイマー)
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffRankTime = NULL;		//頂点バッファへのポインタ(タイマー)

RankTime g_aRankTime[MAX_RANK] = {};					//ランキングタイマー(5位分)表示
int g_nRankUpdate = -1;									//更新ランクNo.
int g_nTimerRanking;									//ランキング画面表示タイマー
int nData = 1;

//----------------------------zk
//ランキングの初期化処理
//----------------------------
void InitRanking(void)
{
	LPDIRECT3DDEVICE9 pDevice;

	int nCntRank;
	int nRankTime;

	g_nRankUpdate = -1;//更新No.を初期化
	g_nTimerRanking = 0;
	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み(順位)
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\number000.png",
		&g_pTextureRank);

	//テクスチャの読み込み(タイマー)
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\number005.png",
		&g_pTextureRankTime);

	//テクスチャの読み込み(背景)
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\rankingu.png",
		&g_pTextureBKG);

	//頂点バッファの生成(順位)
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_RANK, //必要な頂点数
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffRank,
		NULL);

	//頂点バッファの生成(タイマー)
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_RANK * MAX_RANKTIME_NUM, //必要な頂点数
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffRankTime,
		NULL);

	//頂点バッファの生成(背景)
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, //必要な頂点数
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBKG,
		NULL);

	VERTEX_2D* pVtx;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffRankTime->Lock(0, 0, (void**)&pVtx, 0);

	//ランキングの情報の初期化
	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{//ランキングの順位分回す
		g_aRankTime[nCntRank].pos = D3DXVECTOR3(460.0f, 150.0f + MAX_RANKTIME_HEIGHT * nCntRank, 0.0f);
		g_aRankTime[nCntRank].nTime = 0;
		g_aRankTime[nCntRank].nRank = nCntRank + 1;

		for (nRankTime = 0; nRankTime < MAX_RANKTIME_NUM; nRankTime++)
		{//タイマーの桁数分回す

			//頂点座標の設定
			pVtx[0].pos.x = g_aRankTime[nCntRank].pos.x - MAX_RANKTIME_WIDTH / 2 + MAX_RANKTIME_WIDTH * nRankTime;
			pVtx[0].pos.y = g_aRankTime[nCntRank].pos.y - MAX_RANKTIME_HEIGHT / 2;
			pVtx[0].pos.z = 0.0f;

			pVtx[1].pos.x = g_aRankTime[nCntRank].pos.x + MAX_RANKTIME_WIDTH / 2 + MAX_RANKTIME_WIDTH * nRankTime;
			pVtx[1].pos.y = g_aRankTime[nCntRank].pos.y - MAX_RANKTIME_HEIGHT / 2;
			pVtx[1].pos.z = 0.0f;

			pVtx[2].pos.x = g_aRankTime[nCntRank].pos.x - MAX_RANKTIME_WIDTH / 2 + MAX_RANKTIME_WIDTH * nRankTime;
			pVtx[2].pos.y = g_aRankTime[nCntRank].pos.y + MAX_RANKTIME_HEIGHT / 2;
			pVtx[2].pos.z = 0.0f;

			pVtx[3].pos.x = g_aRankTime[nCntRank].pos.x + MAX_RANKTIME_WIDTH / 2 + MAX_RANKTIME_WIDTH * nRankTime;
			pVtx[3].pos.y = g_aRankTime[nCntRank].pos.y + MAX_RANKTIME_HEIGHT / 2;
			pVtx[3].pos.z = 0.0f;

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
			pVtx[1].tex = D3DXVECTOR2(0.1f, 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
			pVtx[3].tex = D3DXVECTOR2(0.1f, 1.0f);

			pVtx += 4;//頂点データのポインタを四つ分進める
		}
	}
	//頂点バッファをアンロックする
	g_pVtxBuffRankTime->Unlock();

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffRank->Lock(0, 0, (void**)&pVtx, 0);

	//ランキングの情報の初期化
	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		g_aRankTime[nCntRank].pos = D3DXVECTOR3(400.0f - MAX_RANK_WIDTH, 150.0f + MAX_RANKTIME_HEIGHT * nCntRank, 0.0f);

		//頂点座標の設定
		pVtx[0].pos.x = g_aRankTime[nCntRank].pos.x - MAX_RANK_WIDTH / 2;
		pVtx[0].pos.y = g_aRankTime[nCntRank].pos.y - MAX_RANKTIME_HEIGHT / 2;
		pVtx[0].pos.z = 0.0f;
		pVtx[1].pos.x = g_aRankTime[nCntRank].pos.x + MAX_RANK_WIDTH / 2;
		pVtx[1].pos.y = g_aRankTime[nCntRank].pos.y - MAX_RANKTIME_HEIGHT / 2;
		pVtx[1].pos.z = 0.0f;
		pVtx[2].pos.x = g_aRankTime[nCntRank].pos.x - MAX_RANK_WIDTH / 2;
		pVtx[2].pos.y = g_aRankTime[nCntRank].pos.y + MAX_RANKTIME_HEIGHT / 2;
		pVtx[2].pos.z = 0.0f;
		pVtx[3].pos.x = g_aRankTime[nCntRank].pos.x + MAX_RANK_WIDTH / 2;
		pVtx[3].pos.y = g_aRankTime[nCntRank].pos.y + MAX_RANKTIME_HEIGHT / 2;
		pVtx[3].pos.z = 0.0f;

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
		pVtx[0].tex = D3DXVECTOR2(0.1f + 0.1f * nCntRank, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.2f + 0.1f * nCntRank, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.1f + 0.1f * nCntRank, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.2f + 0.1f * nCntRank, 1.0f);

		pVtx += 4;//頂点データのポインタを四つ分進める
	}
	//頂点バッファをアンロックする
	g_pVtxBuffRank->Unlock();

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffBKG->Lock(0, 0, (void**)&pVtx, 0);

	//頂点座標の設定
	pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].pos = D3DXVECTOR3(1280.0f, 0.0f, 0.0f);
	pVtx[2].pos = D3DXVECTOR3(0.0f, 720.0f, 0.0f);
	pVtx[3].pos = D3DXVECTOR3(1280.0f, 720.0f, 0.0f);

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

	g_pVtxBuffBKG->Unlock();

	ResetRanking(FILE_TXT_TIME);
	SetRanking(GetNs());
}
//----------------------------
//ランキングの終了処理
//----------------------------
void UninitRanking(void)
{
	//テクスチャの破棄(順位)
	if (g_pTextureRank != NULL)
	{
		g_pTextureRank->Release();
		g_pTextureRank = NULL;
	}

	//テクスチャの破棄(タイマー)
	if (g_pTextureRankTime != NULL)
	{
		g_pTextureRankTime->Release();
		g_pTextureRankTime = NULL;
	}

	//テクスチャの破棄(背景)
	if (g_pTextureBKG != NULL)
	{
		g_pTextureBKG->Release();
		g_pTextureBKG = NULL;
	}

	//頂点バッファの破棄(順位)
	if (g_pVtxBuffRank != NULL)
	{
		g_pVtxBuffRank->Release();
		g_pVtxBuffRank = NULL;
	}

	//頂点バッファの破棄(タイマー)
	if (g_pVtxBuffRankTime != NULL)
	{
		g_pVtxBuffRankTime->Release();
		g_pVtxBuffRankTime = NULL;
	}

	//頂点バッファの破棄(背景)
	if (g_pVtxBuffBKG != NULL)
	{
		g_pVtxBuffBKG->Release();
		g_pVtxBuffBKG = NULL;
	}

}
//----------------------------
//ランキングの更新処理
//----------------------------
void UpdateRanking(void)
{
	int nRankTime;

	g_nTimerRanking += 1;
	//頂点情報へのポインタ
	VERTEX_2D* pVtx;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffRankTime->Lock(0, 0, (void**)&pVtx, 0);

	for (nRankTime = 0; nRankTime < MAX_RANKTIME_NUM * MAX_RANK; nRankTime++)
	{//タイマーの桁数分回す
		//頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		pVtx += 4;
	}

	pVtx -= 4 * MAX_RANKTIME_NUM * MAX_RANK;

	//該当スコアランキングタイマーを点滅
	if (g_nRankUpdate != -1 && g_nTimerRanking >= 0)
	{//ランクインしてて、かつ、タイマーがゼロ以上だったら
		pVtx += 4 * MAX_RANKTIME_NUM * g_nRankUpdate;

		for (nRankTime = 0; nRankTime < MAX_RANKTIME_NUM; nRankTime++)
		{//スコアの桁数分回す
		//頂点カラーの設定
			pVtx[0].col = D3DXCOLOR(0.3f, 1.0f, 0.3f, 1.0f);
			pVtx[1].col = D3DXCOLOR(0.3f, 1.0f, 0.3f, 1.0f);
			pVtx[2].col = D3DXCOLOR(0.3f, 1.0f, 0.3f, 1.0f);
			pVtx[3].col = D3DXCOLOR(0.3f, 1.0f, 0.3f, 1.0f);

			pVtx += 4;
		}
	}

	//タイマーをマイナスにする
	if (g_nTimerRanking >= 5)
	{
		g_nTimerRanking *= -1;
	}

	//頂点バッファをアンロックする
	g_pVtxBuffRankTime->Unlock();

	if (KeybordTrigger(DIK_RETURN) == true || JoyPadTrigger(JOYKEY_START) == true)
	{
		//モード設定(ゲーム画面に移行)
		SetFade(MODE_TITLE);
	}
}
//----------------------------
//ランキングの描画処理
//----------------------------
void DrawRanking(void)
{
	int nCntTime;

	LPDIRECT3DDEVICE9 pDevice; //デバイスへのポインタ
	//デバイスの取得
	pDevice = GetDevice();

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffBKG, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//テクスチャの設定
	pDevice->SetTexture(0, g_pTextureBKG);

	//ポリゴン描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//プリミティブの種類
		0,							//描画する最初の頂点インデックス
		2);

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffRankTime, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//ランキングスコアの描画
	for (nCntTime = 0; nCntTime < MAX_RANK * MAX_RANKTIME_NUM; nCntTime++)
	{
		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureRankTime);
		//ポリゴン描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//プリミティブの種類
			4 * nCntTime,							//描画する最初の頂点インデックス
			2);
	}

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffRank, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//エフェクトの描画
	for (nCntTime = 0; nCntTime < MAX_RANK; nCntTime++)
	{
		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureRank);
		//ポリゴン描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//プリミティブの種類
			4 * nCntTime,							//描画する最初の頂点インデックス
			2);
	}
}
//----------------------------
//ランキングのリセット
//----------------------------
void ResetRanking(const char* DateScore)
{
	int nCnt = 0;
	int foge = NULL;
	//ランキングスコア情報の初期設定
	FILE* pFile = fopen(FILE_TXT_TIME, "r");

	if (pFile == NULL)
	{

	}
	else
	{
		//一行目を読み込む
		char cTmp[125];
		foge = fscanf(pFile, "%s\n", &cTmp[0]);

		//二行目以降を読み込む
		for (nCnt = 0; nCnt < MAX_RANK; nCnt++)
		{
			foge = fscanf(pFile, "%d\n", &g_aRankTime[nCnt].nTime);
		}

		fclose(pFile);
	}

}
//----------------------------
//ランキングの設定
//----------------------------
void SetRanking(int nTime)
{
	int nCntRank;
	int nSelect;
	int nTemp;
	int aPosTexU[8] = {};//格桁の数字を格納
	int nData1, nData2;
	int nCnt;

	int bairitu = NULL;

	//---ランキングタイマーの並び替え
	//-----指定タイマーがランクインしたら g_nRankUpdate を更新

	if (nTime >= g_aRankTime[MAX_RANK - 1].nTime)//ソート処理
	{
		g_aRankTime[MAX_RANK - 1].nTime = nTime;

		for (nCntRank = 0; nCntRank < MAX_RANK - 1; nCntRank++)
		{
			for (nSelect = nCntRank + 1; nSelect < MAX_RANK; nSelect++)
			{
				if (g_aRankTime[nCntRank].nTime <= g_aRankTime[nSelect].nTime)
				{
					nTemp = g_aRankTime[nCntRank].nTime;
					g_aRankTime[nCntRank].nTime = g_aRankTime[nSelect].nTime;
					g_aRankTime[nSelect].nTime = nTemp;
				}
			}
		}
		//順位をぶち込む
		for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
		{
			if (g_aRankTime[nCntRank].nTime == nTime)
			{
				g_nRankUpdate = g_aRankTime[nCntRank].nRank - 1;
			}
		}
	}

	//頂点情報へのポインタ
	VERTEX_2D* pVtx;
	//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffRankTime->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		nData1 = 100;
		nData2 = 10;

		//桁ごとに分割する
		for (nCnt = 0; nCnt < MAX_RANKTIME_NUM; nCnt++)
		{
			if (nCnt == 0)
			{
				aPosTexU[0] = g_aRankTime[nCntRank].nTime / nData1;
			}
			else
			{
				aPosTexU[nCnt] = (g_aRankTime[nCntRank].nTime % nData1 / nData2);
				nData1 /= 10;
				nData2 /= 10;
			}

			//-----テクスチャ座標の設定
			pVtx[0].tex = D3DXVECTOR2(0.1f * aPosTexU[nCnt], 0.0f);
			pVtx[1].tex = D3DXVECTOR2(0.1f + (0.1f * aPosTexU[nCnt]), 0.0f);
			pVtx[2].tex = D3DXVECTOR2(0.1f * aPosTexU[nCnt], 1.0f);
			pVtx[3].tex = D3DXVECTOR2(0.1f + (0.1f * aPosTexU[nCnt]), 1.0f);

			pVtx += 4;
		}
	}

	//頂点バッファをアンロックする
	g_pVtxBuffRankTime->Unlock();

	int ham = NULL;

	//順位を書き込む
	//ランキングタイマー情報の初期設定
	FILE* pFile = fopen(FILE_TXT_TIME, "w");

	if (pFile == NULL)
	{

	}
	else
	{
		char aScore[10] = "スコア";

		//一行目を書き込む
		fprintf(pFile, "%s\n", &aScore[0]);

		//二行目以降を書き込む
		for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
		{
			fprintf(pFile, "%d\n", g_aRankTime[nCntRank].nTime);
		}

		fclose(pFile);
	}
}