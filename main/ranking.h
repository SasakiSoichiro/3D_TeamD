#pragma once
#ifndef _RANKING_H_
#define _RANKING_H_

#include "main.h"

//�}�N����`
#define MAX_RANK (5)					//�\�����ʐ�
#define MAX_RANKTIME_NUM (4)			//�\���^�C�}�[����
#define MAX_RANKTIME_HEIGHT (100)		//�����L���OUI�̍���
#define MAX_RANKTIME_WIDTH (50)		    //�����L���OUI�̕�
#define MAX_RANK_WIDTH (50)				//�����NUI�̕�
#define MAX_RANK_TIME_ANIM_TIME (30)	//�_�ŃA�j���[�V�����̎���

#define FILE_TXT_TIME "date\\ranking\\ranking.txt"	//�X�R�A��CSV�f�[�^�t�@�C��

//�v���g�^�C�v�錾
void InitRanking(void);
void UninitRanking(void);
void UpdateRanking(void);
void DrawRanking(void);
void ResetRanking(const char* DateScore);
void SetRanking(int nTime);

#endif // !_RANKING_H_
