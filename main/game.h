#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"

//	—ñ‹“Œ^
typedef enum
{
	GAMESTATE_NONE = 0,	//‰½‚à‚µ‚Ä‚¢‚È‚¢ó‘Ô
	GAMESTATE_NORMAL,	//’Êíó‘Ô
	GAMESTATE_END,		//I—¹ó‘Ô
	GAMESTATE_MAX
}GAMESTATE;

void InitGame(void);
void UninitGame(void);
void UpdateGame(void);
void DrawGame(int nIdx);
void SetEnablePause(bool bPause);
void SetGameState(GAMESTATE state);
bool GetEditState(void);

#endif // !_GAME_H_
