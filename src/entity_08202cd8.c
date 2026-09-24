#include "camera.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sound.h"
#include "sprite_aux.h"

extern u32 u32_03002bc0;

s32 FUN_0805fe7c(HitboxData* hitbox, s32 param_2, s32 param_3, Vec3* pos, Vec3* param_5, s32 param_6);
void FUN_081fa608(void);

// 8枚のスプライトそれぞれに2種類のヒットボックスを持たせる設置型の仕掛け, おそらくドヴァリンによる水面からのタコ足攻撃
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_9
  u32 unk_18;             // 0x018, _Init が 0 を入れる
  u32 unk_1c;             // 0x01C, _Init が 0 を入れる
  u16 unk_20;             // 0x020, _Init が 0 を入れる
  u16 unk_22;             // 0x022, _Init が 0 を入れる
  u8 unk_24;              // 0x024, _Init が 0 を入れる
  u8 unk_25;              // 0x025, _Init が 0 を入れる
  u16 plttID;             // 0x026, gfx0->plttID
  AuxSprite sprites[8];   // 0x028, i<3 は gfx1、それ以外は gfx0 で AuxSprite_Add する
  u8 unk_188[8];          // 0x188
  HitboxData hitboxA[8];  // 0x190, Hitbox_SetHandler(0x082029B8) と Hitbox_SetAttack を受ける組
  HitboxData hitboxB[8];  // 0x410, Hitbox_SetHandler(0x082029BC) と Hitbox_SetPowerAndAttributes を受ける組
  u32 unk_690;            // 0x690, 読み書きとも無し
  Vec3 pos;               // 0x694, Create の引数が指すマスの衝突タイルから作り、全スプライトの pos へ複写する
  AuxSpriteGfx gfx0;      // 0x69C, SPRITE_DVALIN_2E78
  AuxSpriteGfx gfx1;      // 0x6B8, SPRITE_DVALIN_2E7B
  EntityFunc fn;          // 0x6D4, FUN_08202910 が NULL でなければ p を渡して呼ぶ
  u8 unk_6d8;             // 0x6D8, _Init が 1 を入れる
  u8 unk_6d9;             // 0x6D9
  u8 unk_6da;             // 0x6DA, _Update が 0 を入れる
  u8 unk_6db;             // 0x6DB, _Init が 0 を入れる
  u8 unk_6dc;             // 0x6DC, _Init が 0 を入れる
  u8 unk_6dd;             // 0x6DD, _Init が 0 を入れる
  u8 unk_6de[2];          // 0x6DE
  u16 unk_6e0;            // 0x6E0, Create の第3引数。Hitbox_SetAttack に渡す
  u16 unk_6e2;            // 0x6E2, Create の第2引数。Hitbox_SetPowerAndAttributes に渡す
  u8 unk_6e4[8];          // 0x6E4
  s32 unk_6ec;            // 0x6EC, _Init が 0 の4バイトを書く
} Entity08202cd8;
static_assert(sizeof(Entity08202cd8) == 1776);

NAKED s32 FUN_08200ab4(unknown* p) { INCFUNC("asm/func/FUN_08200ab4.inc"); }

void FUN_08200b2c(Entity08202cd8* p, u8 val) { p->unk_6db = val; }

void FUN_08200b38(AuxSprite* spr) { Video_SetAuxSpritePltt(spr->gfx, 306); }

void FUN_08200b48(AuxSprite* spr, Entity08202cd8* p) { Video_SetAuxSpritePltt(spr->gfx, 561); }

NAKED void FUN_08200b5c(unknown* p) { INCFUNC("asm/func/FUN_08200b5c.inc"); }

// 被弾の点滅を戻し、溜まったダメージを両端の中点にまとめて出す
NON_MATCH void FUN_08200b8c(Entity08202cd8* p) {
#ifdef NONMATCHING_C
  s32 i;

  if (p->unk_24 != 0) {
    p->unk_24--;
    if (p->unk_24 == 0) {
      for (i = 0; i < 8; i++) {
        FUN_08200b48(&p->sprites[i], p);
      }
    }
  }
  if (p->unk_25 != 0) {
    p->unk_25--;
  } else if (p->unk_6ec > 0) {
    Vec3 pos, size;

    FUN_081fa608();
    pos.x = p->sprites[7].pos.x - p->sprites[0].pos.x;
    pos.y = p->sprites[7].pos.y - p->sprites[0].pos.y;
    pos.z = p->sprites[7].pos.z - p->sprites[0].pos.z;
    pos.x >>= 1;
    pos.y >>= 1;
    pos.z >>= 1;
    pos.x += p->sprites[0].pos.x;
    pos.y += p->sprites[0].pos.y;
    pos.z += p->sprites[0].pos.z;
    size.x = 0x10, size.y = 0, size.z = 0x10;
    FUN_0805fe7c(&p->hitboxB[0], p->unk_6ec, 0, &pos, &size, 1);
    p->unk_6ec = 0;
  }
#else
  INCFUNC("asm/func/FUN_08200b8c.inc");
#endif
}

NAKED void FUN_08200c8c(Entity08202cd8* p) { INCFUNC("asm/func/FUN_08200c8c.inc"); }

NAKED void FUN_08200d70(unknown* p) { INCFUNC("asm/func/FUN_08200d70.inc"); }

NAKED void FUN_08200e54(Entity08202cd8* p) { INCFUNC("asm/func/FUN_08200e54.inc"); }

// 全スプライトとヒットボックスを同じ位置に置く
void FUN_08201054(Entity08202cd8* p, Vec3* pos) {
  s32 i;

  p->pos = *pos;
  for (i = 0; i < 8; i++) {
    p->sprites[i].pos = *pos;
    Hitbox_SetPos(&p->hitboxA[i], pos, 0);
    Hitbox_SetPos(&p->hitboxB[i], pos, 0);
  }
}

// 8枚のスプライトをすべて隠す
void FUN_082010b4(Entity08202cd8* p) {
  AuxSprite* spr = p->sprites;
  s32 i;

  for (i = 0; i < 8; i++) {
    spr->flags |= SPRFLAG_HIDDEN;
    spr++;
  }
}

// 8枚のスプライトをすべて表示する
void FUN_082010d0(Entity08202cd8* p) {
  AuxSprite* spr = p->sprites;
  s32 i;

  for (i = 0; i < 8; i++) {
    spr->flags &= ~SPRFLAG_HIDDEN;
    spr++;
  }
}

void FUN_082010f0(Entity08202cd8* p, u16 a, u16 b) {
  p->unk_20 = a;
  p->unk_22 = b;
}

NAKED void FUN_082010f8(unknown* p) { INCFUNC("asm/func/FUN_082010f8.inc"); }

NAKED void FUN_082013d4(unknown* p) { INCFUNC("asm/func/FUN_082013d4.inc"); }

NAKED void FUN_082017cc(unknown* p) { INCFUNC("asm/func/FUN_082017cc.inc"); }

NAKED void FUN_08201f74(unknown* p) { INCFUNC("asm/func/FUN_08201f74.inc"); }

NAKED void FUN_08202140(unknown* p) { INCFUNC("asm/func/FUN_08202140.inc"); }

NAKED void FUN_082024e8(unknown* p) { INCFUNC("asm/func/FUN_082024e8.inc"); }

void FUN_0820287c(Entity08202cd8* p, s32 keep) {
  if (keep == 0) {
    HitboxData* hb = p->hitboxB;
    s32 i;

    for (i = 0; i < 8; i++) {
      hb->flags |= HBFLAG_UNK_2;
      hb++;
    }
  }
  p->unk_6da = 1;
  p->unk_6d9 = 1;
}

NAKED s32 FUN_082028b8(Entity08202cd8* p) { INCFUNC("asm/func/FUN_082028b8.inc"); }

NON_MATCH void FUN_08202910(Entity08202cd8* p) {
#ifdef NONMATCHING_C
  p->unk_6d9 = 0;
  p->unk_18++;
  if (p->fn != NULL) {
    p->fn((Entity*)p);
  }
#else
  INCFUNC("asm/func/FUN_08202910.inc");
#endif
}

// ゲームが止まっていなければ各パートを更新し、カメラ揺れの残り時間を減らす
s32 Entity08202cd8_Update(Entity08202cd8* p) {
  u32 mask;

  p->unk_6da = 0;
  mask = 1 << 2;
  if (!(u32_03002bc0 & mask)) {
    FUN_08200b8c(p);
    FUN_082028b8(p);
    FUN_08202910(p);
    FUN_08200e54(p);
    FUN_08200c8c(p);
    if (p->unk_20 != 0) {
      FUN_0823b9cc(p->unk_22);
      p->unk_20--;
    }
  }
  return 0;
}

s32 Entity08202cd8_Destroy(Entity08202cd8* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    AuxSprite_Remove(&p->sprites[i]);
  }
  return 0;
}

// hitboxA の被弾コールバック。何もしない
void FUN_082029b8(HitboxData* a, HitboxData* b, Entity08202cd8* p) {}

// 被弾時のハンドラ。全スプライトを赤くしてダメージを適用する
void FUN_082029bc(HitboxData* a, HitboxData* b, Entity08202cd8* p) {
  s32 i;

  p->unk_24 = 4;
  p->unk_25 = 15;
  for (i = 0; i < 8; i++) {
    FUN_08200b38(&p->sprites[i]);
  }
  Hitbox_ApplyDamage(a, b);
  p->unk_6ec = b->damage;
  PlaySound_082406e0(0x13E);
}

NAKED s32 Entity08202cd8_Init(Entity08202cd8* p, u16* pos, s32 param_3, s32 param_4) { INCFUNC("asm/func/Entity08202cd8_Init.inc"); }

Entity08202cd8* Entity08202cd8_Create(u16* pos, s32 param_2, s32 param_3) {
  Entity08202cd8* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity08202cd8));

  if (p != NULL) {
    SetEntityRoutine(p, Entity08202cd8_Update, Entity08202cd8_Destroy);
    if (Entity08202cd8_Init(p, pos, param_2, param_3) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
