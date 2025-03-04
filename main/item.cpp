//=================================================================
//
//
//
//				あ　い　て　む　処　理　！！
//
//
//
//==================================================================
#include "item.h"
#include "player.h"
#include "input.h"
#include "sound.h"
#include "slow.h"
#include "nannjamo.h"
#include "ItemUI.h"
#include "pickupUI.h"

// グローバル変数宣言
ITEM g_item[ITEMTYPE_MAX];
ITEMINFO Iteminfo[ITEMTYPE_MAX]; // 種類

//=================
//	初期化処理
//=================
void Inititem(void)
{
	//	デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = GetDevice();
	

	for (int nCnt = 0; nCnt < ITEMTYPE_MAX; nCnt++)
	{
		//	Xファイルの読み込み
		D3DXLoadMeshFromX(ITEM_MODEL[nCnt],
			D3DXMESH_SYSTEMMEM,
			pDevice,
			NULL,
			&Iteminfo[nCnt].pBufferMat,
			NULL,
			&Iteminfo[nCnt].dwNuMat,
			&Iteminfo[nCnt].pMesh);
	}

	for (int count = 0; count < ITEMTYPE_MAX; count++)
	{
		g_item[count].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f); // 座標
		g_item[count].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f); // 角度
		g_item[count].nType = 0; // 種類
		g_item[count].bUse = false; // 未使用判定
		g_item[count].bHave = false;
		g_item[count].bOldHave = false;
		g_item[count].bHold = false;
		g_item[count].nIdxUI = 0;

		// マテリアルのポインタ
		D3DXMATERIAL* pMat;

		//	マテリアルを代入
		pMat = (D3DXMATERIAL*)Iteminfo[count].pBufferMat->GetBufferPointer();

		for (int nCntMat = 0; nCntMat < (int)Iteminfo[count].dwNuMat; nCntMat++)
		{
			//	テクスチャの読み込み
			if (pMat[nCntMat].pTextureFilename != NULL)
			{
				D3DXCreateTextureFromFile(pDevice,
					pMat[nCntMat].pTextureFilename,
					&Iteminfo[count].pTexture[nCntMat]);
			}
		}
	}
}

//=================
//	終了処理
//=================
void Uninititem(void)
{
	//音を消す
	StopSound();

	for (int count = 0; count < ITEMTYPE_MAX; count++)
	{
		int nType = g_item[count].nType;

		for (int nCntMat = 0; nCntMat < (int)Iteminfo[count].dwNuMat; nCntMat++)
		{
			//	テクスチャの破棄
			if (Iteminfo[nType].pTexture[nCntMat] != NULL)
			{
				Iteminfo[nType].pTexture[nCntMat]->Release();
				Iteminfo[nType].pTexture[nCntMat] = NULL;
			}
		}
	}

	for (int count = 0; count < ITEMTYPE_MAX; count++)
	{
		//	メッシュの破棄
		if (Iteminfo[count].pMesh != NULL)
		{
			Iteminfo[count].pMesh->Release();
			Iteminfo[count].pMesh = NULL;
		}

		//	マテリアルの破棄
		if (Iteminfo[count].pBufferMat != NULL)
		{
			Iteminfo[count].pBufferMat->Release();
			Iteminfo[count].pBufferMat = NULL;
		}
	}
}

//================
// 更新処理
//================
void Updateitem(void)
{
	Player* pPlayer = GetPlayer();
	Slow* pSlow = GetSlow();

	for (int nCnt = 0; nCnt < ITEMTYPE_MAX; nCnt++)
	{
		//前回持っていたものを保存
		g_item[nCnt].bOldHave = g_item[nCnt].bHave;
		//アイテムが使用されていたら
		if (g_item[nCnt].bUse == true)
		{
			//プレイヤーの半径の算出用変数
			float fPRadPos = 50.0f;

			//アイテムの半径の算出用変数
			float fIRadPos = 50.0f;

			//プレやーの位置を取得
			D3DXVECTOR3 PlayerPos = GetPlayer()->pos;

			//アイテムのプレイヤーの距離の差
			D3DXVECTOR3 diff = PlayerPos - g_item[nCnt].pos;

			//範囲計算
			float fDisX = PlayerPos.x - g_item[nCnt].pos.x;
			float fDisY = PlayerPos.y - g_item[nCnt].pos.y;
			float fDisZ = PlayerPos.z - g_item[nCnt].pos.z;

			//二つの半径を求める
			float fRadX = fPRadPos + fIRadPos;


			//プレイヤーがアイテムの範囲に入ったら
			if ((fDisX * fDisX) + (fDisY * fDisY) + (fDisZ * fDisZ) <= (fRadX * fRadX))
			{
				if (KeybordTrigger(DIK_F) == true || JoyPadTrigger(JOYKEY_B) == true)
				{//Fを押されたとき

					PlaySound(SOUND_LABEL_SE1);

					//アイテムを拾う

					g_item[nCnt].bHave = true;
					g_item[nCnt].bUse = false;
					SetItemUI(g_item[nCnt].nType);

					//	脱出条件
					if (g_item[nCnt].bUse == false && g_item[nCnt].nType == ITEMTYPE_ONE)
					{
						g_item[nCnt].bHold = true;
					}

					if (g_item[nCnt].bUse == false && g_item[nCnt].nType == ITEMTYPE_TWO)
					{
						g_item[nCnt].bHold = true;
					}


				}
			}
		}
	}

	int nSelect = GetSelect();
	ItemUI *pItemUI= GetItemUI();
	
	if (KeybordTrigger(DIK_E) == true|| JoyPadTrigger(JOYKEY_X) == true)
	{//懐中時計を持っている時、懐中時計を使用する処理
		
		pItemUI += nSelect;
		for (int nCnt = 0; nCnt < ITEMTYPE_MAX; nCnt++)
		{

			switch (pItemUI->nType)
			{
			case ITEM_POCKETWATCH:	// スロー
				if (g_item[nCnt].bHave == true&& g_item[nCnt].nType==ITEMTYPE_THREE)
				{
					// SEを鳴らす
					PlaySound(SOUND_LABEL_SE3);

					pSlow->bUse = true;

					g_item[nCnt].bHave = false;

					SetUsedItemUI(g_item[nCnt].nType);

					SetSlow();
				}
				break;
			case ITEM_HEAL:		// 回復アイテム
				//プレイヤーの体力が2以下なら
				if (g_item[nCnt].bHave == true && g_item[nCnt].nType == ITEMTYPE_FIVE)
				{
					if (pPlayer->nLife <= 2)
					{
						// SEを鳴らす
						PlaySound(SOUND_LABEL_SE2);

						pPlayer->nLife += 1;
						SetNannjamo(90);
						g_item[nCnt].bHave = false;
						SetUsedItemUI(g_item[nCnt].nType);
					}
					
					break;
				}

			}
		}
		pItemUI = 0;
	}

}

//=================
//	描画処理
//=================
void Drawitem(void)
{
	//	デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//	計算用
	D3DXMATRIX mtxRot, mtxTrans;
	D3DMATERIAL9 matDef;
	D3DXMATERIAL* pMat;

	for (int count = 0; count < ITEMTYPE_MAX; count++)
	{
		if (g_item[count].bUse == false)
		{// 未使用だったら
			// 下の処理を通さないでカウントを進める
			continue;
		}

		// 種類を保存
		int nType = g_item[count].nType;

		//	ワールドマトリックスの初期化
		D3DXMatrixIdentity(&g_item[count].mtxWorld);

		//	向きを反映
		D3DXMatrixRotationYawPitchRoll(&mtxRot, g_item[count].rot.y, g_item[count].rot.x, g_item[count].rot.z);
		D3DXMatrixMultiply(&g_item[count].mtxWorld, &g_item[count].mtxWorld, &mtxRot);

		//	位置の反映
		D3DXMatrixTranslation(&mtxTrans, g_item[count].pos.x, g_item[count].pos.y, g_item[count].pos.z);
		D3DXMatrixMultiply(&g_item[count].mtxWorld, &g_item[count].mtxWorld, &mtxTrans);

		//	ワールドマトリックスの設定
		pDevice->SetTransform(D3DTS_WORLD, &g_item[count].mtxWorld);

		//	現在のマテリアルを保存
		pDevice->GetMaterial(&matDef);

		for (int nCntMat = 0; nCntMat < (int)Iteminfo[nType].dwNuMat; nCntMat++)
		{
			//	マテリアルデータへのポインタを取得
			pMat = (D3DXMATERIAL*)Iteminfo[nType].pBufferMat->GetBufferPointer();

			//	マテリアルの設定
			pDevice->SetMaterial(&pMat[nCntMat].MatD3D);

			//	テクスチャの設定
			pDevice->SetTexture(0, Iteminfo[nType].pTexture[nCntMat]);

			//	モデルの描画
			Iteminfo[nType].pMesh->DrawSubset(nCntMat);
		}

		// マテリアルを戻す
		pDevice->SetMaterial(&matDef);
	}
}

//=================
//	取得処理
//=================
ITEM* Getitem(void)
{
	return &g_item[0];
}

//=================
//	配置処理
//=================
void Setitem(D3DXVECTOR3 pos, int nType)
{
	for (int nCnt = 0; nCnt < ITEMTYPE_MAX; nCnt++)
	{
		if (g_item[nCnt].bUse == false)
		{
			g_item[nCnt].pos = pos;
			g_item[nCnt].nType = nType;
			g_item[nCnt].bUse = true;
			g_item[nCnt].nIdxUI = SetPickUpUI(g_item[nCnt].pos, D3DXVECTOR3(0.0f, 0.0f, 0.0f));
			break;
		}
	}
}