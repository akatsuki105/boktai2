#include "entity.h"
#include "global.h"
#include "sprite.h"

typedef struct EntityB3D1 {
  Entity e;                   // 0x000, ENTITY_UNK_8
  u8 unk_18[0x020 - 0x018];   // 0x018, まだ未解析
  AuxSprite sprite0;          // 0x020, _Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx0;          // 0x04C, Video_GetAuxSprite(0xC046)
  u8 unk_68[0x06C - 0x068];   // 0x068, まだ未解析
  AuxSprite sprite1;          // 0x06C, _Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx1;          // 0x098, Video_GetAuxSprite(0xC046)
  u8 unk_b4[2];               // 0x0B4, まだ未解析
  u16 unk_b6;                 // 0x0B6, _Init が VM キーワード 'N' から 1/2/3/4 を入れる
  AuxSprite sprite2;          // 0x0B8, _Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx2;          // 0x0E4, Video_GetAuxSprite(0xC046)
  AuxSprite sprites3[7];      // 0x100, _Destroy が stride 0x2C で7枚 AuxSprite_Remove する
  u8 unk_234[0x250 - 0x234];  // 0x234, まだ未解析
  AuxSprite sprites4[6];      // 0x250, _Destroy が stride 0x2C で6枚 AuxSprite_Remove する
  u8 unk_358[0x398 - 0x358];  // 0x358, まだ未解析
  MainSprite mainSprites[5];  // 0x398, _Destroy が stride 0x60 で5枚 MainSprite_Remove する
  u16 unk_578;                // 0x578, _Init が VM キーワード 'p' を入れる (無ければ 0)
  u8 unk_57a[4];              // 0x57A, まだ未解析
  u16 unk_57e;                // 0x57E, _Init が 0 を入れる
  u8 unk_580[0x588 - 0x580];  // 0x580, まだ未解析
  u16 unk_588;                // 0x588, _Init が 0 を入れる
  u16 unk_58a;                // 0x58A, _Init が VM キーワード 't' の1つ目 (既定 180) を入れる
  u16 unk_58c;                // 0x58C, _Init が VM キーワード 't' の2つ目 (既定 300) を入れる
  u16 unk_58e;                // 0x58E, _Init が 0 を入れる
  u16 unk_590;                // 0x590, _Init が 0 を入れる
  u8 unk_592[2];              // 0x592, まだ未解析
  u32 unk_594;                // 0x594, _Init が 0 を入れる
  u32 unk_598;                // 0x598, _Init が 0 を入れる
  u32 unk_59c;                // 0x59C, _Init が 0 を入れる
  u32 unk_5a0;                // 0x5A0, _Init が 0 を入れる
  u32 unk_5a4;                // 0x5A4, _Init が 0 を入れる
  u32 unk_5a8;                // 0x5A8, _Init が 0 を入れる
  u32 unk_5ac;                // 0x5AC, _Init が 0 を入れる
  u8 unk_5b0[2];              // 0x5B0, まだ未解析
  u16 unk_5b2;                // 0x5B2, _Init が VM キーワード 'r' (既定 300) を入れる
  u8 unk_5b4[1468 - 0x5B4];   // 0x5B4, まだ未解析
} EntityB3D1;
static_assert(sizeof(EntityB3D1) == 1468);

extern EntityB3D1* gEntityB3D1;  // 0x03000158

INCASM("asm/entity_b3d1.inc");
