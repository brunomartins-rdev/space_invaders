#include "core/game.h"

int main(void) {
  Game game;

  GameInit(&game);

  while (!GameShouldClose(&game)) {
    // GameUpdate(&game);
    GameDraw(&game);
  }

  GameUnload(&game);
  return 0;
}
