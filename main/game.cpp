//==================================
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


	//　各オブジェクトの設定処理
	LoadEdit();
	
	//　鍵の上部
	Setitem(D3DXVECTOR3(50.0f, 1.0f, 0.0f), ITEMTYPE_ONE);

	//　薙刀
	Setitem(D3DXVECTOR3(200.0f, 0.0f, 0.0f), ITEMTYPE_FOUR);

	//　ビルボード
	SetBillboard(D3DXVECTOR3(-100.0f, 50.0f, -200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_0,D3DXVECTOR3(15.0f,35.0f,0.0f));
	SetBillboard(D3DXVECTOR3(-100.0f, 50.0f, -100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_1, D3DXVECTOR3(2.0f, 2.0f, 0.0f));
	SetBillboard(D3DXVECTOR3(-100.0f, 50.0f, -100.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_1, D3DXVECTOR3(2.0f, 2.0f, 0.0f));
	SetBillboard(D3DXVECTOR3(-1800.0f, 50.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_2, D3DXVECTOR3(4.0f, 4.0f, 0.0f));
	SetBillboard(D3DXVECTOR3(-1800.0f, 50.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_3, D3DXVECTOR3(4.0f, 4.0f, 0.0f));
	SetBillboard(D3DXVECTOR3(-1800.0f, 50.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), BILLBOARDTYPE_4, D3DXVECTOR3(1.0f, 1.0f, 0.0f));

	//　敵
	SetEnemy(D3DXVECTOR3(800.0f, 0.0f, 0.0f),0);

	//　ドア
	SetGimmick(D3DXVECTOR3(-1800.0f, 0.0f, -300.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));

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
}

//---------------
//	更新処理
//---------------
void UpdateGame(void)
{
	bool isGoal = IsGoal();			// ゴールの判定

	Player* pPlayer = GetPlayer();	//　プレイヤー情報取得

	// ポーズ処理
	if (KeybordTrigger(DIK_TAB) == true)
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

			//メッシュフィールド
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

			//ビルボード
			UpdateBillboard();

			//アイテム
			Updateitem();

			//タイム
			UpdateTime();

			//ギミック
			UpdateGimmick();

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

	//　タイム
	DrawTime();

	//　ビルボード
	DrawBillboard();

	//　ギミック
	DrawGimmick();

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