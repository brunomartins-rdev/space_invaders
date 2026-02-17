// include/core/.game.h

#ifndef GAME_H
#define GAME_H

#include <raylib.h>

#include "config.h"
#include "entities/invader.h"

typedef struct Game {
  int screenWidth;
  int screenHeight;
  int currentFPS;

  Invader invaders[INVADER_ROWS][INVADER_COLS];
} Game;

void GameInit(Game *game);
void GameUpdate(Game *game, float deltaTime);
void GameDraw(Game *game);
void GameUnload(Game *game);
bool GameShouldClose(Game *game);

#endif
