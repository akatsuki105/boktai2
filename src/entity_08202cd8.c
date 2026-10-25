#include "boss/dvalinn.h"
#include "camera.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "player.h"
#include "sound.h"
#include "sprite_aux.h"

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
      hb->flags |= HBFLAG_HIDDEN;
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

NAKED s32 Entity08202cd8_Init(Entity08202cd8* p, Vec3* pos, s32 param_3, s32 param_4) { INCFUNC("asm/func/Entity08202cd8_Init.inc"); }

Entity08202cd8* Entity08202cd8_Create(Vec3* pos, s32 param_2, s32 param_3) {
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
