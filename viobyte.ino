#include <TinyScreen.h>
#include <SPI.h>
#include <Wire.h>
#include "Sprite.h"
#include "viobytetitle.h"

#define  BLACK           0x00
#define BLUE            0xE0
#define YELLO          0x1F
#define VIOLE           0xE2
#define RED             0x03
#define WHITE           0xFF
#define OR_BR           0x0A
#define GREEN           0x1C
#define DGREE          0x0C

#define STATE_TITLESCREEN 0
#define STATE_GAME 1
#define STATE_DIEING 2
#define STATE_GAMEOVER 3

TinyScreen display = TinyScreen(0);

const uint8_t PROGMEM s_BlueWall1Data[] {
 BLUE, BLUE, BLUE, BLUE, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_B1 = {5,5, s_BlueWall1Data};

const uint8_t PROGMEM s_BlueWall2Data[] {
 BLUE, BLUE, BLUE, BLUE, BLUE,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_B2 = {5,5, s_BlueWall2Data};

const uint8_t PROGMEM s_BlueWall3Data[] {
 BLUE, BLUE, BLUE, BLUE, BLUE,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_B3 = {5,5, s_BlueWall3Data};

const uint8_t PROGMEM s_BlueWall4Data[] {
 BLUE, BLUE, BLUE, BLUE, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_B4 = {5,5, s_BlueWall4Data};

const uint8_t PROGMEM s_BlueWall5Data[] {
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
};
static Sprite s_B5 = {5,5, s_BlueWall5Data};

const uint8_t PROGMEM s_BlueWall6Data[] {
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_B6 = {5,5, s_BlueWall6Data};

const uint8_t PROGMEM s_BlueWall7Data[] {
 BLUE, BLUE, BLUE, BLUE, BLUE,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK
};
static Sprite s_B7 = {5,5, s_BlueWall7Data};

const uint8_t PROGMEM s_BlueWall8Data[] {
 BLUE, BLUE, BLUE, BLUE, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE
};
static Sprite s_B8 = {5,5, s_BlueWall8Data};

const uint8_t PROGMEM s_BlueWall9Data[] {
 BLUE, BLUE, BLUE, BLUE, BLUE,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK
};
static Sprite s_B9 = {5,5, s_BlueWall9Data};

const uint8_t PROGMEM s_BlueWall10Data[] {
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_BA = {5,5, s_BlueWall10Data};

const uint8_t PROGMEM s_BlueWall11Data[] {
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_BB = {5,5, s_BlueWall11Data};

const uint8_t PROGMEM s_BlueWall12Data[] {
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_BC = {5,5, s_BlueWall12Data};

const uint8_t PROGMEM s_BlueWall13Data[] {
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_BD = {5,5, s_BlueWall13Data};

const uint8_t PROGMEM s_BlueWall14Data[] {
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE
};
static Sprite s_BE = {5,5, s_BlueWall14Data};

const uint8_t PROGMEM s_BlueWall15Data[] {
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK
};
static Sprite s_BF = {5,5, s_BlueWall15Data};

const uint8_t PROGMEM s_BlueWall16Data[] {
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK, BLUE
};
static Sprite s_BG = {5,5, s_BlueWall16Data};

const uint8_t PROGMEM s_BlueWall17Data[] {
 BLUE,BLACK,BLACK,BLACK, BLACK,
BLACK,BLACK,BLACK,BLACK, BLACK,
BLACK,BLACK,BLACK,BLACK, BLACK,
BLACK,BLACK,BLACK,BLACK, BLACK,
 BLUE,BLACK,BLACK,BLACK, BLACK,
};
static Sprite s_BH = {5,5, s_BlueWall17Data};

const uint8_t PROGMEM s_BlueWall18Data[] {
 BLUE, BLUE, BLUE, BLUE, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE
};
static Sprite s_BI = {5,5, s_BlueWall18Data};

const uint8_t PROGMEM s_BlueWall19Data[] {
 BLUE,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_BJ = {5,5, s_BlueWall19Data};

const uint8_t PROGMEM s_BlueWall20Data[] {
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_BK = {5,5, s_BlueWall20Data};

const uint8_t PROGMEM s_BlueWall21Data[] {
 BLUE, BLUE, BLUE, BLUE, BLUE,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK, BLUE
};
static Sprite s_BM = {5,5, s_BlueWall21Data};

const uint8_t PROGMEM s_BlueWall22Data[] {
 BLUE,YELLO,YELLO,YELLO, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_BN = {5,5, s_BlueWall22Data};

const uint8_t PROGMEM s_BlueWall23Data[] {
 BLUE,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_BO = {5,5, s_BlueWall23Data};

const uint8_t PROGMEM s_BlueWall24Data[] {
 BLUE, BLUE, BLUE, BLUE, BLUE,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK, BLUE
};
static Sprite s_BP = {5,5, s_BlueWall24Data};

const uint8_t PROGMEM s_BlueWall25Data[] {
 BLUE, BLUE, BLUE, BLUE, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK, BLUE
};
static Sprite s_BQ = {5,5, s_BlueWall25Data};

const uint8_t PROGMEM s_BlueWall26Data[] {
BLACK,BLACK,BLACK,BLACK, BLUE,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
BLACK,BLACK,BLACK,BLACK,BLACK,
 BLUE, BLUE, BLUE, BLUE, BLUE
};
static Sprite s_BR = {5,5, s_BlueWall26Data};

const uint8_t PROGMEM s_BlueWall27Data[] {
 BLUE,BLACK,BLACK,BLACK, BLUE,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK,BLACK,
 BLUE,BLACK,BLACK,BLACK, BLUE
};
static Sprite s_BS = {5,5, s_BlueWall27Data};


struct Tunnel
{
  int posX;
  int posY;
  int desX;
  int desY;
};

typedef const Sprite *spriteMap;

struct LevelMap
{
  Tunnel tunnel[2];
  uint16_t startX;
  uint16_t startY;
  uint16_t ghostX;
  uint16_t ghostY;
  const spriteMap *tileMap;
  const bool *dots;
};

typedef const LevelMap *pLevelMap;

const spriteMap PROGMEM spriteMap1[228] = 
{
    0,     0,     0,     0,     0,     0,     0,     0,     0, &s_B5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0, &s_B3, &s_B4,     0, &s_B3, &s_B2, &s_B2, &s_B4,     0, &s_B6,     0, &s_B3, &s_B2, &s_B2, &s_B4,     0, &s_B3, &s_B4,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    0, &s_B3, &s_B4,     0, &s_B7, &s_B8,     0, &s_B3, &s_B2, &s_BN, &s_B2, &s_B4,     0, &s_B7, &s_B8,     0, &s_B3, &s_B4,     0,
    0,     0,     0,     0, &s_BF, &s_BE,     0,     0,     0, &s_B6,     0,     0,     0, &s_BF, &s_BE,     0,     0,     0,     0,
&s_B2, &s_B2, &s_B4,     0, &s_BF, &s_BG, &s_B2, &s_B4,     0,     0,     0, &s_B3, &s_B2, &s_BH, &s_BE,     0, &s_B3, &s_B2, &s_B2,
    0,     0,     0,     0, &s_BF, &s_BE,     0,     0,     0, &s_B1,     0,     0,     0, &s_BF, &s_BE,     0,     0,     0,     0,
&s_B9, &s_B9, &s_B8,     0, &s_BB, &s_BA,     0, &s_BI,     0,     0,     0, &s_BI,     0, &s_BB, &s_BA,     0, &s_B7, &s_B9, &s_B9,
&s_BD, &s_BD, &s_BA,     0,     0,     0,     0, &s_BC, &s_B2, &s_BM, &s_B2, &s_BO,     0,     0,     0,     0, &s_BB, &s_BD, &s_BD,
    0,     0,     0,     0, &s_B7, &s_B8,     0,     0,     0, &s_B5,     0,     0,     0, &s_B7, &s_B8,     0,     0,     0,     0,
    0, &s_B3, &s_B2, &s_B2, &s_BJ, &s_BK, &s_B2, &s_B4,     0, &s_B6,     0, &s_B3, &s_B2, &s_BJ, &s_BK, &s_B2, &s_B2, &s_B4,     0,
    0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

const bool PROGMEM dots1[228] = {
false, false, false, false, false, false, false, false, false,  true, false, false, false, false, false, false, false, false, false,
false,  true,  true, false,  true,  true,  true,  true, false,  true, false,  true,  true,  true,  true, false,  true,  true, false,
false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false,
false,  true,  true, false,  true,  true, false,  true,  true,  true,  true,  true, false,  true,  true, false,  true,  true, false,
false, false, false, false,  true,  true, false, false, false,  true, false, false, false,  true,  true, false, false, false, false,
 true,  true,  true, false,  true,  true,  true,  true, false, false, false,  true,  true,  true,  true, false,  true,  true,  true,
 true,  true,  true, false,  true,  true, false, false, false,  true, false, false, false,  true,  true, false,  true,  true,  true,
 true,  true,  true, false,  true,  true, false,  true, false,  true, false,  true, false,  true,  true, false,  true,  true,  true,
 true,  true,  true, false, false, false, false,  true,  true,  true,  true,  true, false, false, false, false,  true,  true,  true,
false, false, false, false,  true,  true, false, false, false,  true, false, false, false,  true,  true, false, false, false, false,
false,  true,  true,  true,  true,  true,  true,  true, false,  true, false,  true,  true,  true,  true,  true,  true,  true, false,
false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false
};

const LevelMap PROGMEM map1 = { {{-4, 6 * 5, 18 * 5 + 4, 6 * 5}, {0, 0, 0, 0}}, 9*5, 7*5, 9*5, 3*5, spriteMap1, dots1 };

const spriteMap PROGMEM spriteMap2[228]
{
    0,     0,     0, &s_B6,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, &s_B6,     0,     0,     0,
    0, &s_BI,     0,     0,     0, &s_B3, &s_B4,     0, &s_B3, &s_B2, &s_B4,     0, &s_B3, &s_B4,     0,     0,     0, &s_BI,     0,
    0, &s_B6,     0, &s_B3, &s_B4,     0,     0,     0,     0,     0,     0,     0,     0,     0, &s_B3, &s_B4,     0, &s_B6,     0,
    0,     0,     0,     0,     0,     0, &s_BP, &s_B4,     0, &s_BN,     0, &s_B3, &s_BQ,     0,     0,     0,     0,     0,     0,
&s_B8,     0, &s_B3, &s_B2, &s_BQ,     0, &s_B5,     0,     0,     0,     0,     0, &s_B5,     0, &s_BI,     0, &s_B3, &s_B2, &s_B2,
&s_BE,     0,     0,     0, &s_B6,     0, &s_B6,     0, &s_B3, &s_B2, &s_B4,     0, &s_B6,     0, &s_B5,     0,     0,     0,     0,
&s_BR, &s_B2, &s_B4,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, &s_B6,     0, &s_B3, &s_B2, &s_B2,
    0,     0,     0,     0, &s_BP, &s_B2, &s_B2, &s_B4,     0, &s_B3, &s_B4,     0, &s_BI,     0,     0,     0,     0,     0,     0,
&s_B2, &s_B2, &s_B4,     0, &s_B6,     0,     0,     0,     0,     0,     0,     0, &s_BS, &s_B2, &s_B2, &s_B4,     0, &s_B1,     0,
    0,     0,     0,     0,     0,     0, &s_B7, &s_B8,     0, &s_B7, &s_B8,     0, &s_B5,     0,     0,     0,     0,     0,     0,
    0, &s_B3, &s_B4,     0, &s_BI,     0, &s_BB, &s_BA,     0, &s_BB, &s_BA,     0, &s_B6,     0, &s_BI,     0, &s_B3, &s_B4,     0,
    0,     0,     0,     0, &s_B5,     0,     0,     0,     0,     0,     0,     0,     0,     0, &s_B5,     0,     0,     0,     0
};

const bool PROGMEM dots2[228] = {
false, false, false,  true, false, false, false, false, false, false, false, false, false, false, false,  true, false, false, false,
false,  true, false, false, false,  true,  true, false,  true,  true,  true, false,  true,  true, false, false, false,  true, false,
false,  true, false,  true,  true, false, false, false, false, false, false, false, false, false,  true,  true, false,  true, false,
false, false, false, false, false, false,  true,  true, false,  true, false,  true,  true, false, false, false, false, false, false,
 true, false,  true,  true,  true, false,  true, false, false, false, false, false,  true, false,  true, false,  true,  true,  true,
 true, false, false, false,  true, false,  true, false,  true,  true,  true, false,  true, false,  true, false,  true,  true,  true,
 true,  true,  true, false, false, false, false, false, false, false, false, false, false, false,  true, false,  true,  true,  true,
 true,  true,  true, false,  true,  true,  true,  true, false,  true,  true, false,  true, false, false, false, false, false, false,
 true,  true,  true, false,  true, false, false, false, false, false, false, false,  true,  true,  true,  true, false,  true, false,
false, false, false, false, false, false,  true,  true, false,  true,  true, false,  true, false, false, false, false, false, false,
false,  true,  true, false,  true, false,  true,  true, false,  true,  true, false,  true, false,  true, false,  true,  true, false,
false, false, false, false,  true, false, false, false, false, false, false, false, false, false,  true, false, false, false, false
};

const LevelMap PROGMEM map2 = { {{-4, 7 * 5, 18 * 5 + 4, 5 * 5}, {0, 0, 0, 0}}, 9*5, 8*5, 9*5, 3*5, spriteMap2, dots2  };

static bool currentDots[228];
const pLevelMap PROGMEM maps[2] = { &map1, &map2 };
int currentMap = 0;
Sprite *tileSpriteMap[228];
TileMap5pix s_tileMap = { 19,12,1,4, tileSpriteMap };

const uint8_t PROGMEM s_ViobyteData[] {
ALPHA,VIOLE,VIOLE,VIOLE,ALPHA,
VIOLE,VIOLE,  RED,VIOLE,VIOLE,
VIOLE,VIOLE,VIOLE,ALPHA,ALPHA,
VIOLE,VIOLE,VIOLE,VIOLE,VIOLE,
ALPHA,VIOLE,VIOLE,VIOLE,ALPHA
};
static Sprite s_Viobyte = {5,5, s_ViobyteData};

const uint8_t PROGMEM s_ViobyteLife[] {
ALPHA,VIOLE,VIOLE,ALPHA,
VIOLE,VIOLE,  RED,VIOLE,
VIOLE,VIOLE,VIOLE,VIOLE,
ALPHA,VIOLE,VIOLE,ALPHA
};

const uint8_t PROGMEM s_Ghost1Data[] {
ALPHA,  RED,  RED,  RED,ALPHA,
  RED,WHITE,YELLO,YELLO,  RED,
  RED,  RED,  RED,  RED,  RED,
  RED,  RED,  RED,  RED,  RED,
  RED,ALPHA,  RED,ALPHA,  RED
};
static Sprite s_Ghost1 = {5,5, s_Ghost1Data};

const uint8_t PROGMEM s_Ghost2Data[] {
ALPHA,GREEN,GREEN,GREEN,ALPHA,
GREEN,WHITE,YELLO,YELLO,GREEN,
GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,GREEN,GREEN,GREEN,GREEN,
GREEN,ALPHA,GREEN,ALPHA,GREEN
};
static Sprite s_Ghost2 = {5,5, s_Ghost2Data};

const uint8_t PROGMEM s_Ghost3Data[] {
ALPHA,OR_BR,OR_BR,OR_BR,ALPHA,
OR_BR,WHITE,YELLO,YELLO,OR_BR,
OR_BR,OR_BR,OR_BR,OR_BR,OR_BR,
OR_BR,OR_BR,OR_BR,OR_BR,OR_BR,
OR_BR,ALPHA,OR_BR,ALPHA,OR_BR
};
static Sprite s_Ghost3 = {5,5, s_Ghost3Data};

const uint8_t PROGMEM s_Ghost4Data[] {
ALPHA,DGREE,DGREE,DGREE,ALPHA,
DGREE,WHITE,YELLO,YELLO,DGREE,
DGREE,DGREE,DGREE,DGREE,DGREE,
DGREE,DGREE,DGREE,DGREE,DGREE,
DGREE,ALPHA,DGREE,ALPHA,DGREE
};
static Sprite s_Ghost4 = {5,5, s_Ghost4Data};

static Sprite s_GameOver = {87,10, _image_game_over_data};

#define VIOBYTE_PLAYER1 4
#define VIOBYTE_GHOST1 0
#define VIOBYTE_GHOST2 1
#define VIOBYTE_GHOST3 2
#define VIOBYTE_GHOST4 3

SpriteInst sprites[5];

const uint8_t PROGMEM TAJoystickUp  = 1 << 0;       //Mask
const uint8_t PROGMEM TAJoystickDown = 1 << 1;      //Mask
const uint8_t PROGMEM TAJoystickLeft  = 1 << 2;     //Mask
const uint8_t PROGMEM TAJoystickRight = 1 << 3;     //Mask
const uint8_t PROGMEM TAJoystick2Up  = 1 << 4;       //Mask
const uint8_t PROGMEM TAJoystick2Down = 1 << 5;      //Mask
const uint8_t PROGMEM TAJoystick2Left  = 1 << 6;     //Mask
const uint8_t PROGMEM TAJoystick2Right = 1 << 7;     //Mask

int score = 0;
int dotsLeft = 0;
int lives = 1;
uint8_t joyDir = 0;
uint8_t curDir = TAJoystickUp;
byte leftButton=0;
byte rightButton=0;
byte leftButtonPrev=0;
byte rightButtonPrev=0;
int ghostLeaving=VIOBYTE_GHOST1;
unsigned long lastTime;
byte dir[4] = {1, 3, 1, 3};
int state = 0;
int refresh = 0;
int count = 0;
int avgrefresh = 0;
uint16_t ghostX;
uint16_t ghostY;
Tunnel tunnel[2];

void reset()
{
  memcpy_P(currentDots, pgm_read_ptr(&((pLevelMap)pgm_read_ptr(&maps[currentMap]))->dots), sizeof(currentDots));
  dotsLeft = 0;
  for (int i = 0; i < 228; i++)
  {
    if (!currentDots[i])
      dotsLeft++;
  }
  memcpy_P(tileSpriteMap, pgm_read_ptr(&((pLevelMap)pgm_read_ptr(&maps[currentMap]))->tileMap), sizeof(tileSpriteMap));
  memcpy_P(tunnel, ((pLevelMap)pgm_read_ptr(&maps[currentMap])), sizeof(tunnel));

  ghostX = pgm_read_word(&((pLevelMap)pgm_read_ptr(&maps[currentMap]))->ghostX);
  ghostY = pgm_read_word(&((pLevelMap)pgm_read_ptr(&maps[currentMap]))->ghostY);
  sprites[VIOBYTE_PLAYER1].sprite = &s_Viobyte;
  sprites[VIOBYTE_PLAYER1].x = pgm_read_word(&((pLevelMap)pgm_read_ptr(&maps[currentMap]))->startX) + s_tileMap.xPixOffset;
  sprites[VIOBYTE_PLAYER1].y = pgm_read_word(&((pLevelMap)pgm_read_ptr(&maps[currentMap]))->startY) + s_tileMap.yPixOffset;
  sprites[VIOBYTE_PLAYER1].enabled = true;
  sprites[VIOBYTE_PLAYER1].flip = false;
  sprites[VIOBYTE_GHOST1].sprite = &s_Ghost1;
  sprites[VIOBYTE_GHOST1].x = ghostX + s_tileMap.xPixOffset;
  sprites[VIOBYTE_GHOST1].y = ghostY + s_tileMap.yPixOffset;
  sprites[VIOBYTE_GHOST1].enabled = true;
  sprites[VIOBYTE_GHOST1].flip = false;
  sprites[VIOBYTE_GHOST2].sprite = &s_Ghost2;
  sprites[VIOBYTE_GHOST2].x = ghostX + s_tileMap.xPixOffset;
  sprites[VIOBYTE_GHOST2].y = ghostY + s_tileMap.yPixOffset;
  sprites[VIOBYTE_GHOST2].enabled = true;
  sprites[VIOBYTE_GHOST2].flip = false;
  sprites[VIOBYTE_GHOST3].sprite = &s_Ghost3;
  sprites[VIOBYTE_GHOST3].x = ghostX + s_tileMap.xPixOffset;
  sprites[VIOBYTE_GHOST3].y = ghostY + s_tileMap.yPixOffset;
  sprites[VIOBYTE_GHOST3].enabled = true;
  sprites[VIOBYTE_GHOST3].flip = false;
  sprites[VIOBYTE_GHOST4].sprite = &s_Ghost4;
  sprites[VIOBYTE_GHOST4].x = ghostX + s_tileMap.xPixOffset;
  sprites[VIOBYTE_GHOST4].y = ghostY + s_tileMap.yPixOffset;
  sprites[VIOBYTE_GHOST4].enabled = true;
  sprites[VIOBYTE_GHOST4].flip = false;
}

void setup()
{

  Wire.begin();
  Serial.begin(9600);
  display.begin();
  reset();
  lastTime = millis();
}

void updateJoystick(){
  Wire.requestFrom(0x22,6);
  int data[4];
  for(int i=0;i<4;i++){
    data[i]=Wire.read();
  }
  byte lsb=Wire.read();
  byte buttons=~Wire.read();
  leftButtonPrev = leftButton;
  rightButtonPrev = rightButton;
  leftButton=buttons&4;
  rightButton=buttons&8;
  for(int i=0;i<4;i++){
    
    data[i]<<=2;
    data[i]|= ((lsb>>(i*2))&3);
    data[i]-=511;
  }
  int RX=data[0];
  int RY=data[1];
  int LX=data[2];
  int LY=data[3];
  joyDir = 0;
  if (LX > 100)
  {
    joyDir |= TAJoystickLeft;
  }
  else if (LX < -100)
  {
    joyDir |= TAJoystickRight;
  }
  if (LY > 100)
  {
    joyDir |= TAJoystickUp;
  }
  else if (LY < -100)
  {
    joyDir |= TAJoystickDown;
  }
  if (RX > 100)
  {
    joyDir |= TAJoystick2Left;
  }
  else if (RX < -100)
  {
    joyDir |= TAJoystick2Right;
  }
  if (RY > 100)
  {
    joyDir |= TAJoystick2Up;
  }
  else if (RY < -100)
  {
    joyDir |= TAJoystick2Down;
  }
  randomSeed(analogRead(0));
}

void drawDots(const TileMap5pix *tilemap, int line, uint8_t lineBuffer[96])
{
  if (line < 4)
  {
    for (int i = 1; i < lives; ++i)
    {
      for (int x = 0; x < 4; ++x)
      {
        uint8_t col = pgm_read_byte_near(s_ViobyteLife + (line * 4) + x);
        if ( col != ALPHA )
        {
          lineBuffer[x + (i * 5)] = col;
        }
      }
    }
    int curNumber = score % 10;
    int remainScore = score;
    int start = 90 - 4;
    do
    {
      for (int x = 0; x < 4; ++x)
      {
        uint8_t col = pgm_read_byte_near(_image_numbers_data + (curNumber * 4 * 4) + (line * 4) + x);
        if ( col != ALPHA )
        {
          lineBuffer[start + x] = col;
        }
      }
      start -= 5;
      remainScore = remainScore / 10;
      curNumber = remainScore % 10;
    }
    while (remainScore != 0);
  }
  if (state != STATE_GAMEOVER)
  {
    if ((line - tilemap->yPixOffset) % 5 == 2)
    {
      int yWhere = (line - tilemap->yPixOffset) / 5;
      for (int i = 0; i < tilemap->xWidth; i++)
      {
        if (!currentDots[yWhere * tilemap->xWidth + i])
        {
          lineBuffer[i * 5 + 2 + tilemap->xPixOffset] = YELLO;
        }
      }
    }
  }
}

void titlescreen()
{
  display.goTo(0,0);
  display.startData();
  uint8_t lineBuffer[96];

  for(int lines = 0; lines < 64; ++lines)
  {
    memcpy_P(lineBuffer,&_image_viobytetitle_data[lines * 96],96);
    display.writeBuffer(lineBuffer,96);
  }
  display.endTransfer();
  if ((leftButton && !leftButtonPrev) || (rightButton && !rightButtonPrev))
  {
    state = STATE_GAME;
    refresh = 0;
    count = 0;
    avgrefresh = 0;
    lastTime = millis();
    currentMap = 0;
    reset();
    score = 0;
    lives = 3;
  }
}

void game_over()
{
  sprites[0].sprite = &s_GameOver;
  sprites[0].x = 4;
  sprites[0].y = 28;
  sprites[0].enabled = true;
  sprites[0].flip = false;
  drawSprites(sprites,1,NULL,0x00,&display,&drawDots);
  if ((leftButton && !leftButtonPrev) || (rightButton && !rightButtonPrev))
  {
    state = STATE_TITLESCREEN;
  }
}

void loop()
{
  // put your main code here, to run repeatedly:
  updateJoystick();
  if (state == STATE_TITLESCREEN)
  {
    titlescreen();
    return;
  }
  else if (state == STATE_GAMEOVER)
  {
    game_over();
    return;
  }
  if (joyDir & TAJoystick2Up)
  {
    state = STATE_GAMEOVER;
    if (count > 0)
    {
      if (avgrefresh == 0)
      {
        avgrefresh = refresh/count;
      }
      else
      {
        avgrefresh = (refresh + avgrefresh)/(count + 1);
      }
      score = avgrefresh;
    }
  }
  int xWhere = (sprites[VIOBYTE_PLAYER1].x - s_tileMap.xPixOffset) / 5;
  int yWhere = (sprites[VIOBYTE_PLAYER1].y - s_tileMap.yPixOffset) / 5;
  int yReal = sprites[VIOBYTE_PLAYER1].y - s_tileMap.yPixOffset;
  int xReal = sprites[VIOBYTE_PLAYER1].x - s_tileMap.xPixOffset;
  if (state == STATE_DIEING)
  {
    if (s_Viobyte.height > 1)
    {
      s_Viobyte.height--;
    }
  }
  else
  {
    if ((joyDir & TAJoystickUp) && (curDir == TAJoystickDown))
      curDir = TAJoystickUp;
    else if ((joyDir & TAJoystickDown) && (curDir == TAJoystickUp))
      curDir = TAJoystickDown;
    else if ((joyDir & TAJoystickLeft) && (curDir == TAJoystickRight))
      curDir = TAJoystickLeft;
    else if ((joyDir & TAJoystickRight) && (curDir == TAJoystickLeft))
      curDir = TAJoystickRight;
    if  ((curDir == TAJoystickDown) || (curDir == TAJoystickUp))
    {
      if (joyDir & TAJoystickLeft)
      {
        if ((xReal > 0) && ((xReal % 5) == 0) && ((yReal % 5) == 0))
        {
          if (s_tileMap.tilemap[yWhere * s_tileMap.xWidth + xWhere - 1] == 0)
          {
            curDir = TAJoystickLeft;
          }
        }
      }
      if (joyDir & TAJoystickRight)
      {
        if ((xReal < 90) && ((xReal % 5) == 0) && ((yReal % 5) == 0))
        {
          if (s_tileMap.tilemap[yWhere * s_tileMap.xWidth + xWhere + 1] == 0)
          {
            curDir = TAJoystickRight;
          }
        }
      }
    }
    else if ((curDir == TAJoystickRight) || (curDir == TAJoystickLeft))
    {
      if (joyDir & TAJoystickDown)
      {
        if ((yReal != 55) && ((yReal % 5) == 0) && ((xReal % 5) == 0))
        {
          if (s_tileMap.tilemap[(yWhere + 1) * s_tileMap.xWidth + xWhere] == 0)
          {
            curDir = TAJoystickDown;
          }
        }
      }
      if (joyDir & TAJoystickUp)
      {
        if ((yReal != 0) && ((yReal % 5) == 0) && ((xReal % 5) == 0))
        {
          if (s_tileMap.tilemap[(yWhere - 1) * s_tileMap.xWidth + xWhere] == 0)
          {
            curDir = TAJoystickUp;
          }
        }
      }
    }
    if (curDir == TAJoystickLeft)
    {
      sprites[VIOBYTE_PLAYER1].flip=true;
      if ((xReal > 0) && ((yReal % 5) == 0))
      {
        if ((xReal % 5) == 0)
        {
          if (s_tileMap.tilemap[yWhere * s_tileMap.xWidth + xWhere - 1] == 0)
          {
            sprites[VIOBYTE_PLAYER1].x--;
            xReal--;
            xWhere--;
          }
        }
        else
        {
          sprites[VIOBYTE_PLAYER1].x--;
          xReal--;
        }
      }
      else if (xReal == 0)
      {
        for (int i = 0; i < 2; ++i)
        {
          if ((xReal == tunnel[i].posX + 4) && (yReal == tunnel[i].posY))
          {
            sprites[VIOBYTE_PLAYER1].x--;
            xReal--;
            xWhere--;
          }
        }
      }
      else if (xReal == -4)
      {
        for (int i = 0; i < 2; ++i)
        {
          if ((xReal == tunnel[i].posX) && (yReal == tunnel[i].posY))
          {
            sprites[VIOBYTE_PLAYER1].x = tunnel[i].desX + s_tileMap.xPixOffset;
            sprites[VIOBYTE_PLAYER1].y = tunnel[i].desY + s_tileMap.yPixOffset;
            xWhere = (sprites[VIOBYTE_PLAYER1].x - s_tileMap.xPixOffset) / 5;
            yWhere = (sprites[VIOBYTE_PLAYER1].y - s_tileMap.yPixOffset) / 5;
            yReal = sprites[VIOBYTE_PLAYER1].y - s_tileMap.yPixOffset;
            xReal = sprites[VIOBYTE_PLAYER1].x - s_tileMap.xPixOffset;
            break;
          }
        }
      }
      else if (xReal < 0)
      {
        xReal--;
        sprites[VIOBYTE_PLAYER1].x--;
      }
    }
    else if (curDir == TAJoystickRight)
    {
      sprites[VIOBYTE_PLAYER1].flip=false;
      if ((xReal < 90) && ((yReal % 5) == 0))
      {
        if ((xReal % 5) == 0)
        {
          if (s_tileMap.tilemap[yWhere * s_tileMap.xWidth + xWhere + 1] == 0)
          {
            sprites[VIOBYTE_PLAYER1].x++;
            xReal++;
          }
        }
        else
        {
          sprites[VIOBYTE_PLAYER1].x++;
          xReal++;
          if ((xReal % 5) == 0)
            xWhere++;
        }
      }
      else if (xReal == 90)
      {
        for (int i = 0; i < 2; ++i)
        {
          if ((xReal == tunnel[i].desX - 4) && (yReal == tunnel[i].desY))
          {
            sprites[VIOBYTE_PLAYER1].x++;
            xReal++;
            xWhere++;
          }
        }
      }
      else if (xReal == 94)
      {
        for (int i = 0; i < 2; ++i)
        {
          if ((xReal == tunnel[i].desX) && (yReal == tunnel[i].desY))
          {
            sprites[VIOBYTE_PLAYER1].x = tunnel[i].posX + s_tileMap.xPixOffset;
            sprites[VIOBYTE_PLAYER1].y = tunnel[i].posY + s_tileMap.yPixOffset;
            xWhere = (sprites[VIOBYTE_PLAYER1].x - s_tileMap.xPixOffset) / 5;
            yWhere = (sprites[VIOBYTE_PLAYER1].y - s_tileMap.yPixOffset) / 5;
            yReal = sprites[VIOBYTE_PLAYER1].y - s_tileMap.yPixOffset;
            xReal = sprites[VIOBYTE_PLAYER1].x - s_tileMap.xPixOffset;
            break;
          }
        }
      }
      else if (xReal > 90)
      {
        sprites[VIOBYTE_PLAYER1].x++;
        xReal++;
      }
    }
    if (currentDots[yWhere * s_tileMap.xWidth + xWhere] == false)
    {
      currentDots[yWhere * s_tileMap.xWidth + xWhere] = true;
      score++;
      dotsLeft--;
    }
    if (curDir == TAJoystickDown)
    {
      if ((yReal != 55) && ((xReal % 5) == 0))
      {
        if ((yReal % 5) == 0)
        {
          if (s_tileMap.tilemap[(yWhere + 1) * s_tileMap.xWidth + xWhere] == 0)
          {
            sprites[VIOBYTE_PLAYER1].y++;
            yReal++;
          }
        }
        else
        {
          sprites[VIOBYTE_PLAYER1].y++;
          yReal++;
          if ((yReal % 5) == 0)
            yWhere++;
        }
      }
    }
    else if (curDir == TAJoystickUp)
    {
      if ((yReal != 0) && ((xReal % 5) == 0))
      {
        if ((yReal % 5) == 0)
        {
          if (s_tileMap.tilemap[(yWhere - 1) * s_tileMap.xWidth + xWhere] == 0)
          {
            sprites[VIOBYTE_PLAYER1].y--;
            yReal--;
            yWhere--;
          }
        }
        else
        {
          sprites[VIOBYTE_PLAYER1].y--;
          yReal--;
        }
      }
    }
    if (currentDots[yWhere * s_tileMap.xWidth + xWhere] == false)
    {
      currentDots[yWhere * s_tileMap.xWidth + xWhere] = true;
      score++;
      dotsLeft--;
    }
  }
  for (int i = VIOBYTE_GHOST1; i <= VIOBYTE_GHOST4; i++)
  {
    if (ghostLeaving == i)
    {
      sprites[i].y--;
      if (sprites[i].y == ghostY - 5 + s_tileMap.yPixOffset)
        ghostLeaving = VIOBYTE_PLAYER1;
    }
    else if ((sprites[i].x == ghostX + s_tileMap.xPixOffset) && (sprites[i].y == ghostY + s_tileMap.yPixOffset))
    {
      if (ghostLeaving == VIOBYTE_PLAYER1)
      {
        ghostLeaving = i;
      }
    }
    else
    {
      yReal = sprites[i].y - s_tileMap.yPixOffset;
      xReal = sprites[i].x - s_tileMap.xPixOffset;
      if (((xReal % 5) == 0) && ((yReal % 5) == 0))
      {
        xWhere = (sprites[i].x - s_tileMap.xPixOffset) / 5;
        yWhere = (sprites[i].y - s_tileMap.yPixOffset) / 5;
        byte possible = 0x0F;
        byte options = 3;
        possible = possible & (~(1 << ((dir[i] + 2) % 4)));
        if ((possible & 0x08) && ((xWhere == 0) || (s_tileMap.tilemap[yWhere * s_tileMap.xWidth + xWhere - 1] != 0)))
        {
          possible &= 0x07;
          options--;
        }
        if ((possible & 0x02) && ((xWhere == (s_tileMap.xWidth - 1)) || (s_tileMap.tilemap[yWhere * s_tileMap.xWidth + xWhere + 1] != 0)))
        {
          possible &= 0x0D;
          options--;
        }
        if ((possible & 0x01) && ((yWhere == 0) || (s_tileMap.tilemap[(yWhere - 1) * s_tileMap.xWidth + xWhere] != 0)))
        {
          possible &= 0x0E;
          options--;
        }
        if ((possible & 0x04) && ((yWhere == (s_tileMap.yHeight - 1)) || (s_tileMap.tilemap[(yWhere + 1) * s_tileMap.xWidth + xWhere] != 0)))
        {
          possible &= 0x0B;
          options--;
        }
        if (options == 0)
        {
          possible = (1 << ((dir[i] + 2) % 4));
          options = 1;
        }
        if (((possible & (1 << dir[i])) == 0) || (random(0,2) == 0))
        {
          int w = random(0, options);
          int w2 = w;
          dir[i] = 0;
          while ((w) || ((possible & 1) == 0))
          {
            if ((possible & 1) != 0)
             w--;
            possible >>= 1;
            dir[i]++;
          }
        }
      }
      if (dir[i] == 0)
      {
        sprites[i].y--;
      }
      else if (dir[i] == 1)
      {
        sprites[i].x++;
      }
      else if (dir[i] == 2)
      {
        sprites[i].y++;
      }
      else if (dir[i] == 3)
      {
        sprites[i].x--;
      }
    }
  }
  if (state != STATE_DIEING)
  {
    for (int index = VIOBYTE_GHOST1; index <= VIOBYTE_GHOST4; ++index)
    {
      if(sprites[index].enabled)
      {
        const Sprite* spriteType = sprites[index].sprite;
        if (((sprites[index].y <= sprites[VIOBYTE_PLAYER1].y) && (sprites[index].y + 5 > sprites[VIOBYTE_PLAYER1].y)) ||
          ((sprites[VIOBYTE_PLAYER1].y <= sprites[index].y) && (sprites[VIOBYTE_PLAYER1].y + 5 > sprites[index].y)))
        {
          if (((sprites[index].x <= sprites[VIOBYTE_PLAYER1].x) && (sprites[index].x + 5 > sprites[VIOBYTE_PLAYER1].x)) ||
            ((sprites[VIOBYTE_PLAYER1].x <= sprites[index].x) && (sprites[VIOBYTE_PLAYER1].x + 5 > sprites[index].x)))
          {
            lives--;
            state = STATE_DIEING;
            break;
          }
        }
      }
    }
  }
  drawSprites(sprites,5,&s_tileMap,0x00,&display,&drawDots);
  if (s_Viobyte.height == 1)
  {
    s_Viobyte.height = 5;
    if (lives == 0)
    {
      state = STATE_GAMEOVER;
    }
    else
    {
      sprites[VIOBYTE_PLAYER1].x = pgm_read_word(&((pLevelMap)pgm_read_ptr(&maps[currentMap]))->startX) + s_tileMap.xPixOffset;
      sprites[VIOBYTE_PLAYER1].y = pgm_read_word(&((pLevelMap)pgm_read_ptr(&maps[currentMap]))->startY) + s_tileMap.yPixOffset;
      state = STATE_GAME;
    }
  }
  unsigned long oldTime = lastTime;
  lastTime = millis();
  refresh += lastTime - oldTime;
  count++;
  if (count > 200)
  {
    if (avgrefresh == 0)
    {
      avgrefresh = refresh/count;
    }
    else
    {
      avgrefresh = (refresh + avgrefresh)/(count + 1);
    }
    refresh = 0;
    count = 0;
  }
  if ((lastTime > oldTime) && (lastTime - oldTime < 61))
  {
    delay(61 - (lastTime - oldTime));
  }
  if (dotsLeft == 0)
  {
    if (currentMap == 0)
      currentMap = 1;
    else
      currentMap = 0;
    reset();
  }
}

