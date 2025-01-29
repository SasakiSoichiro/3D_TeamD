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
#include "score.h"

//ランキングスコアの構造体
typedef struct
{
	D3DXVECTOR3 pos;	//位置
	int nRank;			//順位
	int nScore;			//スコア
}RankScore;

//グローバル変数宣言
LPDIRECT3DTEXTURE9 g_pTextureBKG = NULL;			//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBKG = NULL;			//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureRank = NULL;				//テクスチャへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureRankScore = NULL;			//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffRank = NULL;			//頂点バッファへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffRankScore = NULL;		//頂点バッファへのポインタ

RankScore g_aRankScore[MAX_RANK] = {};						//ランキングスコア(5位分)表示
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
	int nRankScore;

	g_nRankUpdate = -1;//更新No.を初期化
	g_nTimerRanking = 0;
	//デバイスの取得
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\number000.png",
		&g_pTextureRank);

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\number000.png",
		&g_pTextureRankScore);

	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\rankingu.png",
		&g_pTextureBKG);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_RANK, //必要な頂点数
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffRank,
		NULL);

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_RANK * MAX_RANKSCORE_NUM, //必要な頂点数
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffRankScore,
		NULL);

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4, //必要な頂点数
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBKG,
		NULL);

	VERTEX_2D* pVtx;
	//頂点バッファをロックし、ちょうてん情報へのポインタを取得
	g_pVtxBuffRankScore->Lock(0, 0, (void**)&pVtx, 0);

	//ランキングの情報の初期化
	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{//ランキングの順位分回す
		g_aRankScore[nCntRank].pos = D3DXVECTOR3(460.0f, 150.0f + MAX_RANKSCORE_HEIGHT * nCntRank, 0.0f);
		g_aRankScore[nCntRank].nScore = 0;
		g_aRankScore[nCntRank].nRank = nCntRank + 1;

		for (nRankScore = 0; nRankScore < MAX_RANKSCORE_NUM; nRankScore++)
		{//スコアの桁数分回す

			pVtx[0].pos.x = g_aRankScore[nCntRank].pos.x - MAX_RANKSCORE_WIDTH / 2 + MAX_RANKSCORE_WIDTH * nRankScore;
			pVtx[0].pos.y = g_aRankScore[nCntRank].pos.y - MAX_RANKSCORE_HEIGHT / 2;
			pVtx[0].pos.z = 0.0f;

			pVtx[1].pos.x = g_aRankScore[nCntRank].pos.x + MAX_RANKSCORE_WIDTH / 2 + MAX_RANKSCORE_WIDTH * nRankScore;
			pVtx[1].pos.y = g_aRankScore[nCntRank].pos.y - MAX_RANKSCORE_HEIGHT / 2;
			pVtx[1].pos.z = 0.0f;

			pVtx[2].pos.x = g_aRankScore[nCntRank].pos.x - MAX_RANKSCORE_WIDTH / 2 + MAX_RANKSCORE_WIDTH * nRankScore;
			pVtx[2].pos.y = g_aRankScore[nCntRank].pos.y + MAX_RANKSCORE_HEIGHT / 2;
			pVtx[2].pos.z = 0.0f;

			pVtx[3].pos.x = g_aRankScore[nCntRank].pos.x + MAX_RANKSCORE_WIDTH / 2 + MAX_RANKSCORE_WIDTH * nRankScore;
			pVtx[3].pos.y = g_aRankScore[nCntRank].pos.y + MAX_RANKSCORE_HEIGHT / 2;
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
	g_pVtxBuffRankScore->Unlock();

	//頂点バッファをロックし、ちょうてん情報へのポインタを取得
	g_pVtxBuffRank->Lock(0, 0, (void**)&pVtx, 0);

	//ランキングの情報の初期化
	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		g_aRankScore[nCntRank].pos = D3DXVECTOR3(400.0f - MAX_RANK_WIDTH, 150.0f + MAX_RANKSCORE_HEIGHT * nCntRank, 0.0f);

		pVtx[0].pos.x = g_aRankScore[nCntRank].pos.x - MAX_RANK_WIDTH / 2;
		pVtx[0].pos.y = g_aRankScore[nCntRank].pos.y - MAX_RANKSCORE_HEIGHT / 2;
		pVtx[0].pos.z = 0.0f;
		pVtx[1].pos.x = g_aRankScore[nCntRank].pos.x + MAX_RANK_WIDTH / 2;
		pVtx[1].pos.y = g_aRankScore[nCntRank].pos.y - MAX_RANKSCORE_HEIGHT / 2;
		pVtx[1].pos.z = 0.0f;
		pVtx[2].pos.x = g_aRankScore[nCntRank].pos.x - MAX_RANK_WIDTH / 2;
		pVtx[2].pos.y = g_aRankScore[nCntRank].pos.y + MAX_RANKSCORE_HEIGHT / 2;
		pVtx[2].pos.z = 0.0f;
		pVtx[3].pos.x = g_aRankScore[nCntRank].pos.x + MAX_RANK_WIDTH / 2;
		pVtx[3].pos.y = g_aRankScore[nCntRank].pos.y + MAX_RANKSCORE_HEIGHT / 2;
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

	g_pVtxBuffBKG->Lock(0, 0, (void**)&pVtx, 0);

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

	ResetRanking(FILE_TXT_SCORE);
	SetRanking(GetScore());
}
//----------------------------
//ランキングの終了処理
//----------------------------
void UninitRanking(void)
{
	//テクスチャの破棄
	if (g_pTextureRank != NULL)
	{
		g_pTextureRank->Release();
		g_pTextureRank = NULL;
	}
	//テクスチャの破棄
	if (g_pTextureRankScore != NULL)
	{
		g_pTextureRankScore->Release();
		g_pTextureRankScore = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffRank != NULL)
	{
		g_pVtxBuffRank->Release();
		g_pVtxBuffRank = NULL;
	}
	//頂点バッファの破棄
	if (g_pVtxBuffRankScore != NULL)
	{
		g_pVtxBuffRankScore->Release();
		g_pVtxBuffRankScore = NULL;
	}
	//テクスチャの破棄
	if (g_pTextureBKG != NULL)
	{
		g_pTextureBKG->Release();
		g_pTextureBKG = NULL;
	}
	//頂点バッファの破棄
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
	int nRankScore;

	g_nTimerRanking += 1;
	//頂点情報へのポインタ
	VERTEX_2D* pVtx;

	//頂点バッファをロックし、ちょうてん情報へのポインタを取得
	g_pVtxBuffRankScore->Lock(0, 0, (void**)&pVtx, 0);

	for (nRankScore = 0; nRankScore < MAX_RANKSCORE_NUM * MAX_RANK; nRankScore++)
	{//スコアの桁数分回す
		//頂点カラーの設定
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		pVtx += 4;
	}

	pVtx -= 4 * MAX_RANKSCORE_NUM * MAX_RANK;

	//該当スコアランキングスコアを点滅
	if (g_nRankUpdate != -1 && g_nTimerRanking >= 0)
	{//ランクインしてて、かつ、タイマーがゼロ以上だったら
		pVtx += 4 * MAX_RANKSCORE_NUM * g_nRankUpdate;

		for (nRankScore = 0; nRankScore < MAX_RANKSCORE_NUM; nRankScore++)
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
	g_pVtxBuffRankScore->Unlock();

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
	int nCntRank;

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
	pDevice->SetStreamSource(0, g_pVtxBuffRankScore, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//ランキングスコアの描画
	for (nCntRank = 0; nCntRank < MAX_RANK * MAX_RANKSCORE_NUM; nCntRank++)
	{
		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureRankScore);
		//ポリゴン描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//プリミティブの種類
			4 * nCntRank,							//描画する最初の頂点インデックス
			2);
	}

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffRank, 0, sizeof(VERTEX_2D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_2D);

	//エフェクトの描画
	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		//テクスチャの設定
		pDevice->SetTexture(0, g_pTextureRank);
		//ポリゴン描画
		pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP,	//プリミティブの種類
			4 * nCntRank,							//描画する最初の頂点インデックス
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
	FILE* pFile = fopen(FILE_TXT_SCORE, "r");

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
			foge = fscanf(pFile, "%d\n", &g_aRankScore[nCnt].nScore);
		}

		fclose(pFile);
	}

}
//----------------------------
//ランキングの設定
//----------------------------
void SetRanking(int nScore)
{
	int nCntRank;
	int nSelect;
	int nTemp;
	int aPosTexU[8] = {};//格桁の数字を格納
	int nData1, nData2;
	int nCnt;

	int bairitu = NULL;

	//---ランキングスコアの並び替え
	//-----指定スコアがランクインしたら g_nRankUpdate を更新

	if (nScore >= g_aRankScore[MAX_RANK - 1].nScore)//ソート処理
	{
		g_aRankScore[MAX_RANK - 1].nScore = nScore;

		for (nCntRank = 0; nCntRank < MAX_RANK - 1; nCntRank++)
		{
			for (nSelect = nCntRank + 1; nSelect < MAX_RANK; nSelect++)
			{
				if (g_aRankScore[nCntRank].nScore <= g_aRankScore[nSelect].nScore)
				{
					nTemp = g_aRankScore[nCntRank].nScore;
					g_aRankScore[nCntRank].nScore = g_aRankScore[nSelect].nScore;
					g_aRankScore[nSelect].nScore = nTemp;
				}
			}
		}
		//順位をぶち込む
		for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
		{
			if (g_aRankScore[nCntRank].nScore == nScore)
			{
				g_nRankUpdate = g_aRankScore[nCntRank].nRank - 1;
			}
		}
	}

	//頂点情報へのポインタ
	VERTEX_2D* pVtx;
	//頂点バッファをロックし、ちょうてん情報へのポインタを取得
	g_pVtxBuffRankScore->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntRank = 0; nCntRank < MAX_RANK; nCntRank++)
	{
		nData1 = 10000000;
		nData2 = 1000000;

		//桁ごとに分割する
		for (nCnt = 0; nCnt < MAX_RANKSCORE_NUM; nCnt++)
		{
			if (nCnt == 0)
			{
				aPosTexU[0] = g_aRankScore[nCntRank].nScore / nData1;
			}
			else
			{
				aPosTexU[nCnt] = (g_aRankScore[nCntRank].nScore % nData1 / nData2);
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
	g_pVtxBuffRankScore->Unlock();

	int ham = NULL;

	//順位を書き込む
	//ランキングスコア情報の初期設定
	FILE* pFile = fopen(FILE_TXT_SCORE, "w");

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
			fprintf(pFile, "%d\n", g_aRankScore[nCntRank].nScore);
		}

		fclose(pFile);
	}
}