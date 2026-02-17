// include/entities/invader.h

#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include <stdbool.h>

typedef enum {
  INVADER_SMALL,
  INVADER_MEDIUM,
  INVADER_LARGE,
  INVADER_TYPE_COUNT
} InvaderType;

typedef struct Invader {
  Vector2 position;
  InvaderType type;
  bool alive;
  int animationFrame;
  Color color;
} Invader;

void InvaderInit(Invader *invader, Vector2 pos, InvaderType type);
void InvaderUpdate(Invader *invader, float deltaTime);
void InvaderDraw(Invader *invader);

#endif
