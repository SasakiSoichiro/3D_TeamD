//====================================================
//
// 木の処理 [billboard.cpp]
// Author : yabuki yukito
//
//====================================================

#include "billboard.h"
#include "player.h"
#include "item.h"
#include "input.h"
#include "gimmick.h"

//++++++++++++++++++++++++++++++++++++++++++++++++++++
// グローバル変数宣言
//++++++++++++++++++++++++++++++++++++++++++++++++++++
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffBillboard = NULL;					//頂点バッファへのポインタ
LPDIRECT3DTEXTURE9 g_pTextureBillboard[BILLBOARDTYPE_MAX] = {};		//テクスチャへのポインタ
Billboard g_Billboard[MAX_BILLBOARD];
static float a;
bool bExchange;
bool bNext;
bool bChange;

//====================================================
//アイテムの初期化処理
//====================================================
void InitBillboard()
{
	LPDIRECT3DDEVICE9 pDevice;			//デバイスへのポインタ

	pDevice = GetDevice();				//デバイスの取得

	//テクスチャの読み込み
	for (int nCnt = 0; nCnt < BILLBOARDTYPE_MAX; nCnt++)
	{
		D3DXCreateTextureFromFile(pDevice,
			ITEM_TEXTURE[nCnt],
			&g_pTextureBillboard[nCnt]);
	}

	//頂点バッファの生成
	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_BILLBOARD,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffBillboard, NULL);

	VERTEX_3D* pVtx = NULL;

	//頂点バッファをロック
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_BILLBOARD; nCnt++)
	{
		//各変数の初期化
		g_Billboard[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Billboard[nCnt].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_Billboard[nCnt].bTest = false;
		g_Billboard[nCnt].bDisplay = false;
		g_Billboard[nCnt].bUse = false;
		bExchange = false;
		bNext = false;
		bChange = false;
		a = 0.0f;

		//頂点情報の設定
		pVtx[0].pos = D3DXVECTOR3(-15.0f, 35.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(15.0f, 35.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-15.0f, -35.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(15.0f, -35.0f, 0.0f);

		//各頂点の法線の設定(ベクトルの大きさは1にする)
		pVtx[0].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[1].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[2].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);
		pVtx[3].nor = D3DXVECTOR3(0.0f, 0.0f, -1.0f);

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
	//頂点バッファのアンロック
	g_pVtxBuffBillboard->Unlock();
}

//====================================================
//アイテムの終了処理
//====================================================
void UninitBillboard()
{
	//頂点バッファの解放
	if (g_pVtxBuffBillboard != NULL)
	{
		g_pVtxBuffBillboard->Release();
		g_pVtxBuffBillboard = NULL;
	}

	for (int nCnt = 0; nCnt < BILLBOARDTYPE_MAX; nCnt++)
	{
		//テクスチャの破棄
		if (g_pTextureBillboard[nCnt] != NULL)
		{
			g_pTextureBillboard[nCnt]->Release();
			g_pTextureBillboard[nCnt] = NULL;
		}
	}
}

//====================================================
//アイテムの更新処理
//====================================================
void UpdateBillboard()
{
	VERTEX_3D* pVtx = NULL;

	//頂点バッファをロック
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	Player* pPlayer = GetPlayer();
	ITEM* pItem = Getitem();
	bool isbill = IsBill();
	GIMMICK* pGimick = GetGimmick();
	HOLD* pHold = GetHold();
	
	for (int count = 0; count < MAX_ITEM; count++, pItem++)
	{
		for (int nCnt = 0; nCnt < MAX_BILLBOARD; nCnt++)
		{

			if (pItem->bUse == true)
			{
				//プレイヤーの半径の算出用変数
				float fPRadPos = 28.0f;

				//アイテムの半径の算出用変数
				float fIRadPos = 28.0f;

				//プレイヤーの位置を取得
				D3DXVECTOR3 PlayerPos = GetPlayer()->pos;

				//アイテムのプレイヤーの距離の差
				D3DXVECTOR3 diff = PlayerPos - pItem->pos;

				//範囲計算
				float fDisX = PlayerPos.x - pItem->pos.x;
				float fDisY = PlayerPos.y - pItem->pos.y;
				float fDisZ = PlayerPos.z - pItem->pos.z;

				//二つの半径を求める
				float fRadX = fPRadPos + fIRadPos;

				//プレイヤーがアイテムの範囲に入ったら
				if ((fDisX * fDisX) + (fDisY * fDisY) + (fDisZ * fDisZ) <= (fRadX * fRadX))
				{

					//拾うビルボードが使われてるとき
					if (g_Billboard[nCnt].nType == BILLBOARDTYPE_1)
					{

						g_Billboard[nCnt].bUse = true;
						g_Billboard[nCnt].bDisplay = true;
						g_Billboard[nCnt].pos.x = pItem->pos.x;
						g_Billboard[nCnt].pos.y = pItem->pos.y + 10.0f;
						g_Billboard[nCnt].pos.z = pItem->pos.z;

						//Fを押されたとき
						if (KeybordTrigger(DIK_F) == true)
						{
							g_Billboard[nCnt].bUse = false;
						}
					}
				}

				//プレイヤーがアイテムの範囲外にいったら
				else if ((fDisX * fDisX) + (fDisY * fDisY) + (fDisZ * fDisZ) > (fRadX * fRadX))
				{
					g_Billboard[nCnt].bDisplay = false;
				}
			}
			//鍵を持った時
			if (pItem->bKey_Top == true)
			{

				//脱出ドアの範囲に入ったとき
				if (isbill == true)
				{

					//脱出可能ビルボードを使われてるとき
					if (g_Billboard[nCnt].nType == BILLBOARDTYPE_4)
					{
						bExchange = true;
						bChange = false;
						g_Billboard[nCnt].bUse = true;
						g_Billboard[nCnt].bDisplay = true;
					}
				}

				//脱出ドアの範囲外にいったら
				else if (isbill == false)
				{
					g_Billboard[nCnt].bUse = false;
					g_Billboard[nCnt].bDisplay = false;
				}

				//プレイヤーの半径の算出用変数
				float fPRadPos = 28.0f;

				//アイテムの半径の算出用変数
				float fIRadPos = 28.0f;

				//プレイヤーの位置を取得
				D3DXVECTOR3 PlayerPos = GetPlayer()->pos;

				//アイテムのプレイヤーの距離の差
				D3DXVECTOR3 diff = PlayerPos - pGimick->pos;

				//範囲計算
				float fDisX = PlayerPos.x - pGimick->pos.x;
				float fDisY = PlayerPos.y - pGimick->pos.y;
				float fDisZ = PlayerPos.z - pGimick->pos.z;

				//二つの半径を求める
				float fRadX = fPRadPos + fIRadPos;

				//プレイヤーがアイテムの範囲に入ったら
				if ((fDisX * fDisX) + (fDisY * fDisY) + (fDisZ * fDisZ) <= (fRadX * fRadX))
				{

					if (g_Billboard[nCnt].nType == BILLBOARDTYPE_5)
					{
						bChange = false;
						g_Billboard[nCnt].bUse = true;
						g_Billboard[nCnt].bDisplay = true;
						bNext = true;

						g_Billboard[nCnt].pos.x = pGimick->pos.x + 10.0f;
						g_Billboard[nCnt].pos.y = pGimick->pos.y + 10.0f;
						g_Billboard[nCnt].pos.z = pGimick->pos.z;

						if (GetKeyboardPress(DIK_F) == true)
						{//Fを押されたとき
							a += 0.1f;
						}
						else
						{
							a -= 0.01f;
						}
						if (a >= 30.0f)
						{
							a = 10.0f;
						}
						else if (a < 0)
						{
							a = 0.0f;
						}

						pVtx[0].pos = D3DXVECTOR3(-g_Billboard[nCnt].size.x, g_Billboard[nCnt].size.y, g_Billboard[nCnt].size.z);
						pVtx[1].pos = D3DXVECTOR3(g_Billboard[nCnt].size.x * a, g_Billboard[nCnt].size.y, g_Billboard[nCnt].size.z);
						pVtx[2].pos = D3DXVECTOR3(-g_Billboard[nCnt].size.x, -g_Billboard[nCnt].size.y, g_Billboard[nCnt].size.z);
						pVtx[3].pos = D3DXVECTOR3(g_Billboard[nCnt].size.x * a, -g_Billboard[nCnt].size.y, g_Billboard[nCnt].size.z);
					}
				}
				//プレイヤーがアイテムの範囲外にいったら
				else if ((fDisX * fDisX) + (fDisY * fDisY) + (fDisZ * fDisZ) > (fRadX * fRadX))
				{
					g_Billboard[nCnt].bDisplay = false;
				}

				pVtx += 4;
			}
			
			//アイテムが使われてるとき
			if (pItem->bUse == true)
			{
				//脱出ドアの範囲に入ったとき
				if (isbill == true)
				{
					//鍵を持っているが1つのみ(1/2)ビルボードが使われてるとき
					if (g_Billboard[nCnt].nType == BILLBOARDTYPE_3)
					{
						bChange = true;							//鍵を持っていない(0 / 2)ときをtrueにする
						bExchange = false;						//脱出可能をfalseにする
						g_Billboard[nCnt].bUse = true;			//使用する
						g_Billboard[nCnt].bDisplay = true;		//見えるようにする
					}
				}

				//脱出ドアの範囲の外にいったとき
				if (isbill == false)
				{

					//鍵を持っているが1つのみ(1/2)ビルボードが使われてるとき
					if (g_Billboard[nCnt].nType == BILLBOARDTYPE_3)
					{
						bChange = false;						//鍵を持っていない(0 / 2)ときをelseにする
						bExchange = true;						//脱出可能をtrueにする
						g_Billboard[nCnt].bUse = false;			//使用する
						g_Billboard[nCnt].bDisplay = false;		//見えるようにする
					}
				}
			}
		}
	}

		

	//頂点バッファのアンロック
	g_pVtxBuffBillboard->Unlock();
}

//====================================================
//アイテムの描画処理
//====================================================
void DrawBillboard()
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//計算用マトリックス
	D3DXMATRIX mtxRot, mtxTrans;

	//ライトを無効にする
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	for (int nCnt = 0; nCnt < MAX_BILLBOARD; nCnt++)
	{
		if (g_Billboard[nCnt].bUse == true&& g_Billboard[nCnt].bDisplay==true)
		{
			//ワールドマトリックスの初期化
			D3DXMatrixIdentity(&g_Billboard[nCnt].mtxWorld);

			D3DXMATRIX mtxView;
			pDevice->GetTransform(D3DTS_VIEW, &mtxView);

			//カメラの逆行列を指定
			g_Billboard[nCnt].mtxWorld._11 = mtxView._11;
			g_Billboard[nCnt].mtxWorld._12 = mtxView._21;
			g_Billboard[nCnt].mtxWorld._13 = mtxView._31;
			g_Billboard[nCnt].mtxWorld._21 = mtxView._12;
			g_Billboard[nCnt].mtxWorld._22 = mtxView._22;
			g_Billboard[nCnt].mtxWorld._23 = mtxView._32;
			g_Billboard[nCnt].mtxWorld._31 = mtxView._13;
			g_Billboard[nCnt].mtxWorld._32 = mtxView._23;
			g_Billboard[nCnt].mtxWorld._33 = mtxView._33;

			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, g_Billboard[nCnt].pos.x, g_Billboard[nCnt].pos.y, g_Billboard[nCnt].pos.z);
			D3DXMatrixMultiply(&g_Billboard[nCnt].mtxWorld, &g_Billboard[nCnt].mtxWorld, &mtxTrans);

			//ワールドマトリックスの設定
			pDevice->SetTransform(D3DTS_WORLD, &g_Billboard[nCnt].mtxWorld);

			//頂点バッファをデバイスのデータストリームに設定
			pDevice->SetStreamSource(0, g_pVtxBuffBillboard, 0, sizeof(VERTEX_3D));

			//脱出可能の条件文
			if (bExchange == true && bNext == false)
			{
				//テクスチャの設定
				pDevice->SetTexture(0, g_pTextureBillboard[3]);
			}

			//溜めゲージの条件文
			if (bNext == true && bExchange == false)
			{
				//テクスチャの設定
				pDevice->SetTexture(0, g_pTextureBillboard[4]);
			}

			//鍵を持っていない(0 / 2)ときの条件文
			if (bChange == true)
			{
				//テクスチャの設定
				pDevice->SetTexture(0, g_pTextureBillboard[2]);
			}

			//全部の条件文以外
			else
			{
				//テクスチャの設定
				pDevice->SetTexture(0, g_pTextureBillboard[g_Billboard[nCnt].nType]);
			}

			//頂点フォーマット
			pDevice->SetFVF(FVF_VERTEX_3D);

			//アイテムの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, nCnt * 4, 2);

		}
	}

	//ライトを有効にする
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
}

//====================================================
//アイテムの設定処理
//====================================================
void SetBillboard(D3DXVECTOR3 pos, D3DXVECTOR3 dir, TYPE nType, D3DXVECTOR3 size)
{
	VERTEX_3D* pVtx = NULL;
	LPDIRECT3DDEVICE9 pDevice;							//デバイスへのポインタ

	pDevice = GetDevice();								//デバイスの取得

		//頂点バッファをロック
	g_pVtxBuffBillboard->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_BILLBOARD; nCnt++)
	{
		if (g_Billboard[nCnt].bUse == false)
		{
			g_Billboard[nCnt].pos = pos;				//	位置
			g_Billboard[nCnt].nType = nType;			//	種類
			g_Billboard[nCnt].size = size;
			//if (nType == BILLBOARDTYPE_1)
			//{
			//	g_Billboard[nCnt].bUse = false;			//	使用しているとき
			//}
			//else
			//{
				g_Billboard[nCnt].bUse = true;			//	使用しているとき
			//}

			//	頂点情報の設定
			pVtx[0].pos = D3DXVECTOR3(-size.x, size.y, size.z);
			pVtx[1].pos = D3DXVECTOR3(size.x, size.y, size.z);
			pVtx[2].pos = D3DXVECTOR3(-size.x, -size.y, size.z);
			pVtx[3].pos = D3DXVECTOR3(size.x, -size.y, size.z);

			break;
		}

		pVtx += 4;
	}

	//頂点バッファのアンロック
	g_pVtxBuffBillboard->Unlock();
}
