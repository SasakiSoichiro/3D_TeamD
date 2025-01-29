#pragma once
#ifndef _RANKING_H_
#define _RANKING_H_

#include "main.h"

//�}�N����`
#define MAX_RANK (5)					//�\�����ʐ�
#define MAX_RANKSCORE_NUM (8)			//�\���X�R�A����
#define MAX_RANKSCORE_HEIGHT (100)		//�����L���OUI�̍���
#define MAX_RANKSCORE_WIDTH (50)		//�����L���OUI�̕�
#define MAX_RANK_WIDTH (50)				//�����NUI�̕�
#define MAX_RANK_SCORE_ANIM_TIME (30)	//�_�ŃA�j���[�V�����̎���

#define FILE_TXT_SCORE "date\\ranking\\ranking.txt"	//�X�R�A��CSV�f�[�^�t�@�C��

//�v���g�^�C�v�錾
void InitRanking(void);
void UninitRanking(void);
void UpdateRanking(void);
void DrawRanking(void);
void ResetRanking(const char* DateScore);
void SetRanking(int nScore);

#endif // !_RANKING_H_
