#include "camera.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "player.h"
#include "sound.h"
#include "sprite_aux.h"

// 8枚のスプライトそれぞれに2種類のヒットボックスを持たせる設置型の仕掛け, おそらくドヴァリンによる水面からのタコ足攻撃
typedef struct Entity08202cd8 {
  Entity e;                                 // 0x000, ENTITY_UNK_9
  u32 unk_18;                               // 0x018, _Init で 0
  u32 unk_1c;                               // 0x01C, _Init で 0
  u16 unk_20;                               // 0x020, _Init で 0
  u16 unk_22;                               // 0x022, _Init で 0
  u8 unk_24;                                // 0x024, _Init で 0
  u8 unk_25;                                // 0x025, _Init で 0
  u16 plttID;                               // 0x026, gfx0->plttID
  AuxSprite sprites[8];                     // 0x028, i<3 は gfx1、それ以外は gfx0 で AuxSprite_Add する
  u8 unk_188[8];                            // 0x188
  HitboxData hitboxA[8];                    // 0x190, Hitbox_SetHandler(0x082029B8) と Hitbox_SetAttack を受ける組
  HitboxData hitboxB[8];                    // 0x410, Hitbox_SetHandler(0x082029BC) と Hitbox_SetPowerAndAttributes を受ける組
  u32 unk_690;                              // 0x690, 読み書きとも無し
  Vec3 pos;                                 // 0x694, Create の引数が指すマスの衝突タイルから作り、全スプライトの pos へ複写する
  AuxSpriteGfx gfx0;                        // 0x69C, SPRITE_DVALIN_2E78
  AuxSpriteGfx gfx1;                        // 0x6B8, SPRITE_DVALIN_2E7B
  void (*fn)(struct Entity08202cd8*, s32);  // 0x6D4, FUN_08202910 が p と加算前の unk_18 を渡して呼ぶ
  u8 unk_6d8;                               // 0x6D8, _Init で 1
  u8 unk_6d9;                               // 0x6D9
  u8 unk_6da;                               // 0x6DA, _Update が 0 を入れる
  u8 unk_6db;                               // 0x6DB, _Init で 0
  u8 unk_6dc;                               // 0x6DC, _Init で 0
  u8 unk_6dd;                               // 0x6DD, _Init で 0
  u8 unk_6de[2];                            // 0x6DE
  u16 unk_6e0;                              // 0x6E0, Create の第3引数, Hitbox_SetAttack に渡す
  u16 unk_6e2;                              // 0x6E2, Create の第2引数, Hitbox_SetPowerAndAttributes に渡す
  u8 unk_6e4[8];                            // 0x6E4
  s32 unk_6ec;                              // 0x6EC, _Init が 0 の4バイトを書く
} Entity08202cd8;
static_assert(sizeof(Entity08202cd8) == 1776);

s32 FUN_0805fe7c(HitboxData* hitbox, s32 param_2, s32 param_3, Vec3* pos, Vec3* param_5, s32 param_6);
void FUN_081fa608(void);
void FUN_081ea540(Mover* a, Mover* b, s32 param_3, s32 param_4, s32 param_5, s32 param_6);

const u16 u16_ARRAY_085ae7b8[8] = {64, 64, 64, 64, 64, 128, 128, 128};  // 0x085AE7B8

const u16 u16_ARRAY_085ae7c8[8] = {4096, 4096, 4096, 4096, 4096, 16384, 16384, 16384};  // 0x085AE7C8

const s32 s32_ARRAY_085ae7d8[8] = {-100, -60, -40, -30, -20, 10, 45, 0};  // 0x085AE7D8

NAKED s32 FUN_08200ab4(unknown* p) { INCFUNC("asm/func/FUN_08200ab4.inc"); }

void FUN_08200b2c(Entity08202cd8* p, u8 val) { p->unk_6db = val; }

void FUN_08200b38(AuxSprite* spr) { Video_SetAuxSpritePltt(spr->gfx, 306); }

void FUN_08200b48(AuxSprite* spr, Entity08202cd8* p) { Video_SetAuxSpritePltt(spr->gfx, 561); }

// 1枚目のスプライトの位置から自機へ向けて何かを飛ばす
void FUN_08200b5c(Entity08202cd8* p) {
  Mover* q = &gPlayerPtr[0]->mover;
  Mover m;

  m.pos = p->sprites[0].pos;
  FUN_081ea540(&m, q, 10, 30, 0, 10);
}

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

NAKED void FUN_082010f8(Entity08202cd8* p, s32 val) { INCFUNC("asm/func/FUN_082010f8.inc"); }

NAKED void FUN_082013d4(Entity08202cd8* p, s32 val) { INCFUNC("asm/func/FUN_082013d4.inc"); }

NAKED void FUN_082017cc(Entity08202cd8* p, s32 val) { INCFUNC("asm/func/FUN_082017cc.inc"); }

NAKED void FUN_08201f74(Entity08202cd8* p, s32 val) { INCFUNC("asm/func/FUN_08201f74.inc"); }

NAKED void FUN_08202140(Entity08202cd8* p, s32 val) { INCFUNC("asm/func/FUN_08202140.inc"); }

NAKED void FUN_082024e8(Entity08202cd8* p, s32 val) { INCFUNC("asm/func/FUN_082024e8.inc"); }

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

// unk_6db で指定された状態関数を fn に移す
s32 FUN_082028b8(Entity08202cd8* p) {
  static void (*const PTR_ARRAY_085ae7f8[8])(Entity08202cd8*, s32) = {
      NULL,
      FUN_082010f8,
      FUN_082013d4,
      FUN_082017cc,
      FUN_08202140,
      FUN_08201f74,
      FUN_082024e8,
      FUN_0820287c,
  };  // 0x085AE7F8

  if (p->unk_6db == 0 || p->unk_6db > 8) {
    return 0;
  }

  p->fn = PTR_ARRAY_085ae7f8[p->unk_6db];
  p->unk_6dc = p->unk_6db;
  p->unk_6db = 0;
  p->unk_18 = 0;
  p->unk_6d8 = 1;
  return 1;
}

void FUN_08202910(Entity08202cd8* p) {
  s32 n;

  p->unk_6d9 = 0;
  n = p->unk_18++;
  if (p->fn != NULL) {
    p->fn(p, n);
  }
}

// ゲームが止まっていなければ各パートを更新し、カメラ揺れの残り時間を減らす
s32 Entity08202cd8_Update(Entity08202cd8* p) {
  u32 mask;

  p->unk_6da = 0;
  mask = FLAG03002BC0_UNK_2;
  if (!(u32_03002bc0[0] & mask)) {
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

// hitboxA の被弾コールバック, 何もしない
void FUN_082029b8(HitboxData* a, HitboxData* b, Entity08202cd8* p) {}

// 被弾時のハンドラ, 全スプライトを赤くしてダメージを適用する
void FUN_082029bc(HitboxData* a, HitboxData* b, Entity08202cd8* p) {
  s32 i;

  p->unk_24 = 4;
  p->unk_25 = 15;
  for (i = 0; i < 8; i++) {
    FUN_08200b38(&p->sprites[i]);
  }
  Hitbox_ApplyDamage(a, b);
  p->unk_6ec = b->damage;
  PlaySound_082406e0(SE_ENEMY_DAMAGED);
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
