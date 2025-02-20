//==================================
// 
//		げーむの処理	game.cpp
//			ryuusei.hirata 
//==================================
#include "input.h"
#include "game.h"
#include "fade.h"
#include "result.h"
#include "camera.h"
#include "light.h"
#include "meshfield.h"
#include "meshwall.h"
#include "model.h"
#include "player.h"
#include "motion.h"
#include "stage.h"
#include "item.h"
#include "block.h"
#include "time.h"
#include "billboard.h"
#include "pause.h"
#include "enemy.h"
#include "edit.h"
#include "sound.h"
#include "gimmick.h"
#include "UI.h"
#include "gonnzaresu.h"
#include "slow.h"
#include "gauge.h"
#include "KeyUI.h"
#include <time.h>
#include"ItemUI.h"

// マクロ定義
#define RAND (6) // ランダム用変数

// ゲームの状態
GAMESTATE g_gameState = GAMESTATE_NONE;	// 初期化

// 状態管理カウンター
int g_nCounterGameState = 0;

//	ポーズ
bool g_bPause = false;

//エディット
bool g_bEdit = false;

//---------------
//	初期化処理
//---------------
void InitGame(void)
{
	//　BGMを鳴らす
	PlaySound(SOUND_LABEL_BGM2);


	//　各オブジェクトの初期化処理

	//　ライト
	InitLight();

	//　カメラ
	InitCamera();

	//　メッシュフィールド
	InitMeshfield();

	//　プレイヤー
	InitPlayer();

	//　アイテム
	Inititem();

	//　タイム
	InitTime();

	//　敵
	InitEnemy();

	//　ブロック
	InitBlock();

	//　エディット
	InitEdit();

	//　ギミック
	InitGimmick();

	//　ビルボード
	InitBillboard();

	//　ポーズ
	InitPause();

	//	ゴンザレス
	InitGonzaresu();

	// スロー
	InitSlow();

	// 各オブジェクトの設定処理
	LoadEdit();

	//	ゲージ
	InitGauge();

	// 鍵のUI
	InitKeyUI();

	// アイテムのUI
	InitItemUI();
	
	//int a = rand() % 6 + 1;
	int a = rand() % RAND + 1;

	if (a == 1)
	{
		//　鍵の上部
		Setitem(D3DXVECTOR3(1413.6f, 1.5f, -491.2f), ITEMTYPE_ONE);
	}
	
	if (a == 2)
	{
		//　鍵の上部
		Setitem(D3DXVECTOR3(527.0f, 1.5f, -341.2f), ITEMTYPE_ONE);
	}

	if (a == 3)
	{
		//　鍵の上部
		Setitem(D3DXVECTOR3(878.7f, 1.5f, 651.4f), ITEMTYPE_ONE);
	}

	if (a == 4)
	{
		//　鍵の上部
		Setitem(D3DXVECTOR3(165.0f, 1.5f, 591.2f), ITEMTYPE_ONE);
	}

	if (a == 5)
	{
		//　鍵の上部
		Setitem(D3DXVECTOR3(-278.3f, 1.5f, 563.1f), ITEMTYPE_ONE);
	}

	if (a == 6)
	{//蔵
		//　鍵の上部
		Setitem(D3DXVECTOR3(-1169.5f, 1.5f, 421.5f), ITEMTYPE_ONE);
	}

	int b = rand() % RAND + 1;

	if (b == 1)
	{
		//　鍵の下部
		Setitem(D3DXVECTOR3(200.0f, 1.5f, 320.5f), ITEMTYPE_TWO);
	}

	if (b == 2)
	{
		//　鍵の下部
		Setitem(D3DXVECTOR3(932.5f, 1.5f, -512.5f), ITEMTYPE_TWO);
	}

	if (b == 3)
	{
		//　鍵の下部
		Setitem(D3DXVECTOR3(717.5f, 1.5f, 25.5f), ITEMTYPE_TWO);
	}

	if (b == 4)
	{
		//　鍵の下部
		Setitem(D3DXVECTOR3(-1092.5f, 1.5f, 452.5f), ITEMTYPE_TWO);
	}

	if (b == 5)
	{
		//　鍵の下部
		Setitem(D3DXVECTOR3(-391.5f, 1.5f, -111.5f), ITEMTYPE_TWO);
	}

	if (b == 6)
	{//蔵
		//　鍵の下部
		Setitem(D3DXVECTOR3(-10.5f, 1.5f, -387.5f), ITEMTYPE_TWO);
	}

	//　懐中時計
	Setitem(D3DXVECTOR3(-1500.0f, 0.0f, 700.0f), ITEMTYPE_SIX);

	//	救急箱
	Setitem(D3DXVECTOR3(-1000.0f, 50.0f, 700.0f), ITEMTYPE_FIVE);

	//　ビルボード(木)
	SetBillboard(D3DXVECTOR3(-100.0f, 50.0f, -200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_0,D3DXVECTOR3(15.0f,35.0f,0.0f));

	//	ビルボード(拾う)
	SetBillboard(D3DXVECTOR3(-100.0f, 75.0f, -100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_1, D3DXVECTOR3(2.0f, 2.0f, 0.0f));
	SetBillboard(D3DXVECTOR3(-100.0f, 75.0f, -100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_1, D3DXVECTOR3(2.0f, 2.0f, 0.0f));

	//	ビルボード(0/2)
	SetBillboard(D3DXVECTOR3(-1785.0f, 75.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_2, D3DXVECTOR3(4.0f, 4.0f, 0.0f));

	//	ビルボード(1/2)
	SetBillboard(D3DXVECTOR3(-1780.0f, 75.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_3, D3DXVECTOR3(4.0f, 4.0f, 0.0f));

	//	ビルボード(脱出可能)
	SetBillboard(D3DXVECTOR3(-1780.0f, 75.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_4, D3DXVECTOR3(4.0f, 4.0f, 0.0f));

	//	ビルボード(解除)
	SetBillboard(D3DXVECTOR3(-1750.0f, 75.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_5, D3DXVECTOR3(1.0f, 1.0f, 0.0f));

	//　敵
	SetEnemy(D3DXVECTOR3(-1750.0f, 0.0f, 0.0f),0);

	//　ドア
	SetGimmick(D3DXVECTOR3(-1800.0f, 0.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//	鍵のUI
	SetKeyUI(D3DXVECTOR3(940.0f, 40.0f, 0.0f), ITEMKEYUITYPE_NO5, 35.0f, 35.0f);

	SetGauge(D3DXVECTOR3(640.0f, 0.0f, 0.0f));

	//　目のUI
	InitEyeUI();

	//　初期化処理
	g_bEdit = false;
	g_gameState = GAMESTATE_NORMAL;// 通常状態に設定
}

//---------------
//	終了処理
//---------------
void UninitGame(void)
{
	//　音楽を止める
	StopSound();

	//　各オブジェクトの終了処理


	//　ライト
	UninitLight();

	//　メッシュフィールド
	UninitMeshfield();

	//　カメラ
	UninitCamera();

	//　ブロック
	UninitBlock();

	//　プレイヤー
	UninitPlayer();

	//　敵
	UninitEnemy();

	//　アイテム
	Uninititem();

	//　タイム
	UninitTime();

	//　エディット
	UninitEdit();

	//　ビルボード
	UninitBillboard();

	//　ポーズ
	UninitPause();

	//　ギミック
	UninitGimmick();

	//　目のUI
	UninitEyeUI();

	//	ゴンザレス
	UinitGonzaresu();

	//	ゲージ
	UinitGauge();

	// 鍵のUI
	UninitKeyUI();

	// アイテムのUI
	UninitItemUI();
}

//---------------
//	更新処理
//---------------
void UpdateGame(void)
{
	bool isGoal = IsGoal();			// ゴールの判定

	Player* pPlayer = GetPlayer();	//　プレイヤー情報取得

	// ポーズ処理
	if (KeybordTrigger(DIK_TAB) || JoyPadTrigger(JOYKEY_START) == true)
	{// TAB
		g_bPause = g_bPause ? false : true;
	}

	if (g_bPause == true)
	{// g_bPauseがtrue
		UpdatePause();
	}


	//エディット処理
	if (g_bEdit == true&&KeybordTrigger(DIK_F1))
	{// F1
		g_bEdit = false;

		//ブロック初期化
		InitBlock();

		//ステージをロード
		LoadEdit();
	}

	else if (g_bEdit == false && KeybordTrigger(DIK_F1))
	{// b_Editがtrue
		g_bEdit = true;

	}
	if (g_bPause == false)
	{// b_Pauseがfalse
		if (g_bEdit == false)
		{// g_Editがfalse

			//　ゲーム中の各オブジェクトの更新処理
# if 1			//メッシュフィールド
			UpdateMeshfield();

			//カメラ
			UpdateCamera();

			//ライト
			UpdateLight();

			//ブロック
			UpdateBlock();

			//プレイヤー
			UpdatePlayer();

			//敵
			UpdateEnemy();

			//ギミック
			UpdateGimmick();

			//タイム
			UpdateTime();

			//ビルボード
			UpdateBillboard();

			//アイテム
			Updateitem();

			//目のUI
			UpdateEyeUI();

			//	ゴンザレス
			UpdateGonzaresu();

			//	ゲージ
			UpdateGauge();

			//　鍵のUI
			UpdateKeyUI();

			// アイテムのUI
			UpdateItemUI();

#endif
#ifdef _DEBUG// デバッグ

			if (KeybordTrigger(DIK_O) == true || JoyPadTrigger(JOYKEY_A) == true)
			{// OまたはAボタン

				//リザルトに移る
				SetFade(MODE_RESULT);
			}

#endif
		}
		else if (g_bEdit == true)
		{//　g_Editがtrue

			//　エディット中の各オブジェクトの更新処理

			//　カメラ
			UpdateCamera();

			//　エディット
			UpdateEdit();
		}

	}

	if (isGoal == true)
	{//ゴールがtrue
		g_gameState = GAMESTATE_END;// ゲームを終了させる
	}

	if (pPlayer->nLife <= 0)
	{//プレイヤーが死んだとき

		//モード設定
		g_gameState = GAMESTATE_END;// ゲームを終了させる

		//カウントを進める
		g_nCounterGameState++;
	}

	switch (g_gameState)
	{
	case GAMESTATE_NONE:// ゲーム通常状態

		break;
	case GAMESTATE_END:	// ゲーム終了状態

		g_nCounterGameState++;

		if (g_nCounterGameState >= 30)
		{//30Fたったら
			g_gameState = GAMESTATE_NONE;	// 何もしていない
			SetFade(MODE_RESULT);			// リザルト画面に遷移
			g_nCounterGameState = 0;		// 状態カウンター初期化
		}
		break;
	}
}

//---------------
//	描画処理
//---------------
void DrawGame(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	////FOGの設定
	//SetupVertexFog(D3DCOLOR_XRGB(0, 0, 0), D3DFOG_LINEAR, TRUE, 0.08f);

	//　各オブジェクトの描画処理


	//　メッシュフィールド
	DrawMeshfield();

	//　ブロック
	DrawBlock();

	//　アイテム
	Drawitem();

	//　プレイヤー
	DrawPlayer();

	//　敵
	DrawEnemy();

	//　ギミック
	DrawGimmick();

	////FOGを消す
	//pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);

	//　ビルボード
	DrawBillboard();

	//	ゴンザレス
	DrawGonzaresu();

	//　タイム
	DrawTime();

	//　目のUI
	DrawEyeUI();

	//	ゲージ
	DrawGauge();

	//	鍵のUI
	DrawKeyUI();

	// アイテムのUI
	DrawItemUI();

	////FOGを戻す
	//pDevice->SetRenderState(D3DRS_FOGENABLE, FALSE);


	if (g_bPause == true)
	{//　g_Pauseがtrue

		//　ポーズ
		DrawPause();
	}
	if (g_bEdit == true)
	{//　g_bEditがtrue

		//　エディット
		DrawEdit();
	}
}


//----------------------
//	ポーズのbool処理
//----------------------
void SetEnablePause(bool bPause)
{
	g_bPause = bPause;
}


//------------------
//ゲーム状態の設定
//------------------
void SetGameState(GAMESTATE state)
{
	g_gameState = state;
}


//------------------------
//エディットの情報の取得
//------------------------
bool GetEditState(void)
{
	return g_bEdit;
}