#include "pickupUI.h"

//グローバル変数宣言
LPDIRECT3DTEXTURE9 g_pTexturePickUpUI = NULL;//テクスチャへのポインタ
LPDIRECT3DVERTEXBUFFER9 g_pVtxBuffPickUpUI = NULL;//頂点バッファへのポインタ
PickUpUI g_aPickUpUI[MAX_BLB];
void InitPickUpUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//テクスチャの読み込み
	D3DXCreateTextureFromFile(pDevice,
		"data\\texture\\time.png",
		&g_pTexturePickUpUI);

	for (int nCnt = 0; nCnt < MAX_BLB; nCnt++)
	{
		//各種変数の初期化
		g_aPickUpUI[nCnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aPickUpUI[nCnt].rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		g_aPickUpUI[nCnt].bUse = false;
	}


	pDevice->CreateVertexBuffer(sizeof(VERTEX_3D) * 4 * MAX_BLB,//(sizeof(VERTEX_3D)*必要な頂点数
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&g_pVtxBuffPickUpUI,
		NULL);

	VERTEX_3D* pVtx = 0;//頂点情報へのポインタ

//頂点バッファをロックし、頂点情報へのポインタを取得
	g_pVtxBuffPickUpUI->Lock(0, 0, (void**)&pVtx, 0);

	for (int nCnt = 0; nCnt < MAX_BLB; nCnt++)
	{
		pVtx[0].pos = D3DXVECTOR3(-OBJBILL, OBJBILL, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(OBJBILL, OBJBILL, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(-OBJBILL, -OBJBILL, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(OBJBILL, -OBJBILL, 0.0f);

		//各頂点の法線の設定
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

	//頂点バッファをアンロックする
	g_pVtxBuffPickUpUI->Unlock();
}

void UninitPickUpUI(void)
{

	//テクスチャの破棄
	if (g_pTexturePickUpUI != NULL)
	{
		g_pTexturePickUpUI->Release();
		g_pTexturePickUpUI = NULL;
	}


	//頂点バッファの解放
	if (g_pVtxBuffPickUpUI != NULL)
	{
		g_pVtxBuffPickUpUI->Release();
		g_pVtxBuffPickUpUI = NULL;
	}
}
void UpdatePickUpUI(void)
{

}
void DrawPickUpUI(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();
	//計算用マトリックス
	D3DXMATRIX mtxRot, mtxTrans;

	//ライトを無効にする
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	for (int nCntPUU = 0; nCntPUU < MAX_BLB; nCntPUU++)
	{
		//ワールドマトリックスの初期化
		D3DXMatrixIdentity(&g_aPickUpUI[nCntPUU].mtxWorld);

		//ビューマトリックス取得
		D3DXMATRIX mtxView;
		pDevice->GetTransform(D3DTS_VIEW, &mtxView);

		//カメラの逆行列を設定
		g_aPickUpUI[nCntPUU].mtxWorld._11 = mtxView._11;
		g_aPickUpUI[nCntPUU].mtxWorld._12 = mtxView._21;
		g_aPickUpUI[nCntPUU].mtxWorld._13 = mtxView._31;
		g_aPickUpUI[nCntPUU].mtxWorld._21 = mtxView._12;
		g_aPickUpUI[nCntPUU].mtxWorld._22 = mtxView._22;
		g_aPickUpUI[nCntPUU].mtxWorld._23 = mtxView._32;
		g_aPickUpUI[nCntPUU].mtxWorld._31 = mtxView._13;
		g_aPickUpUI[nCntPUU].mtxWorld._32 = mtxView._23;
		g_aPickUpUI[nCntPUU].mtxWorld._33 = mtxView._33;


		//位置を反映
		D3DXMatrixTranslation(&mtxTrans, g_aPickUpUI[nCntPUU].pos.x, g_aPickUpUI[nCntPUU].pos.y, g_aPickUpUI[nCntPUU].pos.z);
		D3DXMatrixMultiply(&g_aPickUpUI[nCntPUU].mtxWorld, &g_aPickUpUI[nCntPUU].mtxWorld, &mtxTrans);
	}
	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, g_pVtxBuffPickUpUI, 0, sizeof(VERTEX_3D));
	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	//ループ処理
	for (int nCntPUU = 0; nCntPUU < MAX_BLB; nCntPUU++)
	{
		if (g_aPickUpUI[nCntPUU].bUse == true)
		{
			pDevice->SetTransform(D3DTS_WORLD, &g_aPickUpUI[nCntPUU].mtxWorld);//for文に入れる

			//テクスチャの設定
			pDevice->SetTexture(0, g_pTexturePickUpUI);

			//ポリゴンの描画
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 4 * nCntPUU, 2);//for文に入れる
		}
	}

	//ライトを有効に戻す
	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
}

void SetPickUpUI(D3DXVECTOR3 pos, D3DXVECTOR3 dir)
{
	VERTEX_3D* pVtx = 0;		//頂点情報へのポインタ
	float rotY = 0.0f;
	int nCntPUU=0;				//ピックアップUIの番号

	//ループ処理
	for (int nCntPUU = 0; nCntPUU < MAX_BLB; nCntPUU++)
	{//ブロックの最大数分ループする
		if (g_aPickUpUI[nCntPUU].bUse == false)
		{//ブロックが使用されていない

			g_aPickUpUI[nCntPUU].pos = pos;			//ブロックの頂点座標を代入
			g_aPickUpUI[nCntPUU].pos.y = pos.y+20.0f;
			g_aPickUpUI[nCntPUU].bUse = true;		//使用している状態にする
			break;
		}
	}

	//return nCntPUU;//ピックアップUI番号(Index)を返す
}