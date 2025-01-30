#pragma once
#ifndef _RANKING_H_
#define _RANKING_H_

#include "main.h"

//マクロ定義
#define MAX_RANK (5)					//表示順位数
#define MAX_RANKNS_NUM (2)			    //表示桁数(秒)
#define MAX_RANKMIN_NUM (2)			    //表示桁数(分)
#define MAX_RANKTIME_HEIGHT (100)		//ランキングUIの高さ
#define MAX_RANKTIME_WIDTH (50)		    //ランキングUIの幅
#define MAX_RANK_WIDTH (50)				//ランクUIの幅
#define MAX_RANK_TIME_ANIM_TIME (30)	//点滅アニメーションの時間

#define FILE_TXT_TIME "date\\ranking\\ranking.txt"	//スコアのCSVデータファイル

//プロトタイプ宣言
void InitRanking(void);
void UninitRanking(void);
void UpdateRanking(void);
void DrawRanking(void);
void ResetRanking(const char* DateScore);
void SetRanking(int nTime);

#endif // !_RANKING_H_
