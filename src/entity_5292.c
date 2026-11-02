#include "constants/sprite.h"
#include "entity.h"
#include "global.h"
#include "random.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vm.h"

typedef struct {
  AuxSprite sprite;        // 0x00
  AuxSpriteGfx gfx;        // 0x2C, SPRITE_CC88
  s16 x;                   // 0x48, 下位4ビットが小数, 0xFFF で折り返すので画面の 0..255 を回る
  s16 y;                   // 0x4A, x と同じ
  u8 unk_4c[0x50 - 0x4C];  // 0x4C, 読み手も書き手も未発見
  s16 velX;                // 0x50, 毎フレーム x に足す, angle と speed から作る
  s16 velY;                // 0x52, 毎フレーム y に足す
  u8 unk_54[0x5C - 0x54];  // 0x54, 読み手も書き手も未発見
  u16 animTimer;           // 0x5C, 毎フレーム +1, (animTimer >> 2) & 3 が sprite.metaspriteIdx
  u16 turnTimer;           // 0x5E, 15..30, 0 になると向きと速さを選び直す
  u16 angle;               // 0x60, Entity5292.baseAngle の写し, 向きを選ぶときの中心
  u16 speed;               // 0x62, 16..31, 向きを選ぶときの速さの基準
} Entity5292Elem;
static_assert(sizeof(Entity5292Elem) == 100);

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_10
  u16 id;                    // 0x018
  u8 unk_1a[0x024 - 0x01A];  // 0x01A, まだ未解析
  u16 unk_24;                // 0x024, _Init が gRandomTable から 0..31 の乱数を入れる
  u16 baseAngle;             // 0x026, 0x60, 各要素の angle の初期値
  u8 unk_28[2];              // 0x028, まだ未解析
  u16 plttOffset;            // 0x02A, '.p=6', 要素のパレットは 0x1D3 + plttOffset
  Entity5292Elem elems[16];  // 0x02C, _Destroy が stride 0x64 で16枚 AuxSprite_Remove する
} Entity5292;
static_assert(sizeof(Entity5292) == 1644);

// 残差は gRandomTable のアドレスが r6 に残る 1 命令差, 原典は if/else の後で読み直す
NON_MATCH void Entity5292_UpdateElem(Entity5292Elem* elem) {
#ifdef NONMATCHING_C
  elem->x = (elem->x + elem->velX) & 0xFFF;
  elem->y = (elem->y + elem->velY) & 0xFFF;
  elem->sprite.pos.x = elem->x >> 4;
  elem->sprite.pos.y = elem->y >> 4;
  elem->animTimer++;
  elem->sprite.poseIdx = (elem->animTimer >> 2) & 3;
  if (--elem->turnTimer == 0) {
    s32 offset = ((Random() >> 3) & 31) - 15;
    u32 angle;
    s32 speed;

    if (offset > 0) {
      elem->sprite.flags |= SPRFLAG_XFLIP;
    } else {
      elem->sprite.flags &= ~SPRFLAG_XFLIP;
    }
    angle = offset + elem->angle;
    speed = ((Random() >> 3) & 15) + elem->speed - 7;
    elem->velX = POLAR_X(speed, angle);
    elem->velY = POLAR_Z(speed, angle);
    elem->turnTimer = (Random() & 15) + 15;
  }
#else
  INCFUNC("asm/func/Entity5292_UpdateElem.inc");
#endif
}

s32 Entity5292_Update(Entity5292* p) {
  Entity5292Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 16; i++) {
    Entity5292_UpdateElem(elem);
    elem++;
  }
  return 0;
}

s32 Entity5292_Destroy(Entity5292* p) {
  Entity5292Elem* elem = p->elems;
  s32 i;

  for (i = 0; i < 16; i++) {
    AuxSprite_Remove(&elem->sprite);
    elem++;
  }
  return 0;
}

// 残差は elem->x のアドレスを &elem->speed - 0x1A で作る点と周辺のレジスタ割当だけ, table のループ外読みは確定
NON_MATCH void Entity5292_InitElems(Entity5292* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 16; i++) {
    Entity5292Elem* elem = &p->elems[i];
    AuxSprite* spr = &elem->sprite;
    AuxSpriteGfx* gfx = &elem->gfx;
    u16* table = gRandomTable;
    s32 offset;
    u32 angle;
    s32 speed;

    Video_GetAuxSprite(gfx, SPRITE_CC88);
    AuxSprite_Add(spr, gfx, 0);
    elem->sprite.flags |= SPRFLAG_SCREEN_COORD;
    elem->sprite.priority = 1;
    elem->angle = p->baseAngle;
    elem->speed = ((_Random(table) >> 3) & 15) + 16;
    elem->x = (_Random(table) >> 3) & 0xFFF;
    elem->y = (_Random(table) >> 3) & 0xFFF;
    elem->sprite.pos.x = elem->x >> 4;
    elem->sprite.pos.y = elem->y >> 4;
    elem->animTimer = _Random(table) & 15;
    elem->sprite.poseIdx = elem->animTimer >> 2;
    Video_SetAuxSpritePltt(gfx, p->plttOffset + 0x1D3);
    offset = ((Random() >> 3) & 31) - 15;
    if (offset > 0) {
      elem->sprite.flags |= SPRFLAG_XFLIP;
    } else {
      elem->sprite.flags &= ~SPRFLAG_XFLIP;
    }
    angle = offset + elem->angle;
    speed = ((Random() >> 3) & 3) + elem->speed;
    elem->velX = POLAR_X(speed, angle);
    elem->velY = POLAR_Z(speed, angle);
    elem->turnTimer = (Random() & 15) + 15;
  }
#else
  INCFUNC("asm/func/Entity5292_InitElems.inc");
#endif
}

s32 Entity5292_Init(Entity5292* p) {
  p->baseAngle = 0x60;
  p->plttOffset = VM_SeekToNamedArg('p') ? VM_GetValue() : 6;
  Entity5292_InitElems(p);
  p->unk_24 = Random() & 31;
  return 0;
}

Entity5292* Entity5292_Create(u32 id) {
  Entity5292* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity5292));

  if (p != NULL) {
    p->id = id;
    SetEntityRoutine(p, Entity5292_Update, Entity5292_Destroy);
    if (Entity5292_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
