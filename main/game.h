#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "main.h"

//	列挙型
typedef enum
{
	GAMESTATE_NONE = 0,	//何もしていない状態
	GAMESTATE_NORMAL,	//通常状態
	GAMESTATE_END,		//終了状態
	GAMESTATE_MAX
}GAMESTATE;

void InitGame(void);
void UinitGame(void);
void UpdateGame(void);
void DrawGame(void);
void SetEnablePause(bool bPause);
void SetGameState(GAMESTATE state);
bool GetEditState(void);

#endif // !_GAME_H_
