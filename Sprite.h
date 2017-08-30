#pragma once
#include <avr/pgmspace.h>

#define ALPHA 0xBA

class Sprite
{
  public:
  int width;
  int height;
  const uint8_t* data;
};

class SpriteInst
{
  public:
  const Sprite* sprite;
  int x;
  int y;
  bool enabled;
  bool flip;
};

class TileMap5pix
{
  public:
  int xWidth;
  int yHeight;
  int xPixOffset;
  int yPixOffset;
  const Sprite** tilemap;
  
};

typedef void (*particleCallback)(const TileMap5pix *tilemap, int line, uint8_t lineBuffer[96]);

void drawSprites(SpriteInst* sprites, int numSprites, const TileMap5pix *tilemap, uint8_t bgCol, TinyScreen *display, particleCallback fn);
