// src/entities/invader.c
#include "entities/invader.h"

#define PIXEL_SIZE 1

typedef struct {
  int width;
  int height;
  const int (*frames)[8][8];
  int frameCount;
} InvaderDefinition;

static const int squidFrames[2][8][8] = {{{0, 0, 0, 1, 1, 0, 0, 0},
                                          {0, 0, 1, 1, 1, 1, 0, 0},
                                          {0, 1, 1, 1, 1, 1, 1, 0},
                                          {1, 1, 0, 1, 1, 0, 1, 1},
                                          {1, 1, 1, 1, 1, 1, 1, 1},
                                          {0, 0, 1, 0, 0, 1, 0, 0},
                                          {0, 1, 0, 1, 1, 0, 1, 0},
                                          {1, 0, 1, 0, 0, 1, 0, 1}},
                                         {{0, 0, 0, 1, 1, 0, 0, 0},
                                          {0, 0, 1, 1, 1, 1, 0, 0},
                                          {0, 1, 1, 1, 1, 1, 1, 0},
                                          {1, 1, 0, 1, 1, 0, 1, 1},
                                          {1, 1, 1, 1, 1, 1, 1, 1},
                                          {0, 1, 0, 1, 1, 0, 1, 0},
                                          {1, 0, 0, 0, 0, 0, 0, 1},
                                          {0, 1, 0, 0, 0, 0, 1, 0}}};

static const InvaderDefinition invaderDefs[INVADER_TYPE_COUNT] = {
    {8, 8, squidFrames, 2}, {8, 8, squidFrames, 2}, {8, 8, squidFrames, 2}};

void InvaderInit(Invader *invader, Vector2 pos, InvaderType type) {
  invader->position = pos;
  invader->type = type;
  invader->alive = true;
  invader->animationFrame = 0;
  invader->color = GREEN;
}

void InvaderUpdate(Invader *invader, float deltaTime) {
  if (!invader->alive)
    return;

  invader->position.x += 20.0f * deltaTime;
}

void InvaderDraw(Invader *invader) {
  if (!invader->alive)
    return;

  const InvaderDefinition *def = &invaderDefs[invader->type];

  const int (*frame)[8] = def->frames[invader->animationFrame];

  for (int y = 0; y < def->height; y++) {
    for (int x = 0; x < def->width; x++) {

      if (!frame[y][x])
        continue;

      DrawRectangle((int)invader->position.x + x * PIXEL_SIZE,
                    (int)invader->position.y + y * PIXEL_SIZE, PIXEL_SIZE,
                    PIXEL_SIZE, invader->color);
    }
  }
}
