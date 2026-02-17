// src/core/game.c

#include "config.h"
#include "core/game.h"
#include "entities/invader.h"

#include <stdbool.h>

void GameInit(Game *game) {
  game->screenWidth = SCREEN_WIDTH;
  game->screenHeight = SCREEN_HEIGHT;
  game->currentFPS = CURRENT_FPS;

  InitWindow(game->screenWidth, game->screenHeight, "Space Invaders");
  SetTargetFPS(game->currentFPS);

  int INVADER_START_X = (float)SCREEN_WIDTH * 0.1f;
  int INVADER_START_Y = (float)SCREEN_HEIGHT * 0.1f;

  for (int row = 0; row < INVADER_ROWS; row++) {
    for (int col = 0; col < INVADER_COLS; col++) {

      Vector2 pos = {INVADER_START_X + col * INVADER_SPACING_X,
                     INVADER_START_Y + row * INVADER_SPACING_Y};

      // InvaderType type;

      // if (row == 0)
      //   type = INVADER_SMALL;
      // else if (row <= 2)
      //   type = INVADER_MEDIUM;
      // else
      //   type = INVADER_LARGE;

      InvaderInit(&game->invaders[row][col], pos, INVADER_SMALL);
    }
  }
}

bool GameShouldClose(Game *game) {
  (void)game;
  return WindowShouldClose();
}

void GameUpdate(Game *game, float deltaTime) {
  for (int row = 0; row < INVADER_ROWS; row++) {
    for (int col = 0; col < INVADER_COLS; col++) {
      InvaderUpdate(&game->invaders[row][col], deltaTime);
    }
  }
}

void GameDraw(Game *game) {
  BeginDrawing();

  ClearBackground((Color){0, 0, 0, 0});

  for (int row = 0; row < INVADER_ROWS; row++) {
    for (int col = 0; col < INVADER_COLS; col++) {
      InvaderDraw(&game->invaders[row][col]);
    }
  }

  EndDrawing();
}

void GameUnload(Game *game) {
  (void)game;
  CloseWindow();
}
