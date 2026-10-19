#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "sprite.h"

// 8個を使い回す粒子の枠
typedef struct {
  Particle ptcl;  // 0x00, FUN_080abfec が Particle_Remove に渡す
  u8 unk_28[20];  // 0x28
} TransEffectParticle;
static_assert(sizeof(TransEffectParticle) == 60);

// FUN_080ac090 / FUN_080ac100 / FUN_080ac13c が受け取る一式, 呼び出し元は自分の +0x2C を渡す
typedef struct {
  AuxSprite spr;           // 0x00
  u8 unk_2c[0x6C - 0x2C];  // 0x2C, まだ未解析
  u8 unk_6c;               // 0x6C, FUN_080ac13c が timer 0 のとき 0 を書く
  u8 timer;                // 0x6D, FUN_080ac100 が 0xF 未満なら +1, FUN_080ac13c が 0 でなければ -1
} TransEffectSprite;

// 魔法"トランス", "Cマウス", "Cバット" を使用した際の 魔方陣, パーティクル
typedef struct {
  Entity e;        // 0x000, ENTITY_UNK_8
  Player* player;  // 0x018
  Vec3 pos;        // 0x01C, _Init の第4引数を8バイトまるごと写す, NULL なら x/y/z を 0 にする
  u8 unk_24;       // 0x024, _Init の第3引数
  u8 unk_25;       // 0x025, _Init が player->[0x37C] を写す
  u8 unk_26[2];    // 0x026
  u16 unk_28;      // 0x028, _Init の第5引数
  u16 unk_2a;      // 0x02A, _Init の第6引数
  struct {
    AuxSprite spr;               // 0x02C, ->gfx
    AuxSpriteGfx gfx;            // 0x058, SPRITE_MAGIC_CIRCLE
  } circle;                      // 0x02C, SPRITE_MAGIC_CIRCLE, 足元の魔方陣
  u8 unk_74[0x98 - 0x74];        // 0x074
  u8 unk_98;                     // 0x098, _Update が 0 かを見る, unk_9e と揃って 0 なら KillEntity
  u8 unk_99[5];                  // 0x099
  u8 unk_9e;                     // 0x09E, _Update が 0 かを見る
  u8 unk_9f[5];                  // 0x09F
  TransEffectParticle ptcls[8];  // 0x0A4, 根拠: FUN_080abfec の stride 0x3C × 8
} TransEffect;
static_assert(sizeof(TransEffect) == 644);

NAKED void FUN_080abd74(TransEffect* p) { INCFUNC("asm/func/FUN_080abd74.inc"); }

NAKED void FUN_080abe48(TransEffect* p, u32 param_2) { INCFUNC("asm/func/FUN_080abe48.inc"); }

NAKED void FUN_080abf9c(TransEffect* p) { INCFUNC("asm/func/FUN_080abf9c.inc"); }

void FUN_080abfec(TransEffect* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
}

NAKED void FUN_080ac008(TransEffect* p) { INCFUNC("asm/func/FUN_080ac008.inc"); }

NAKED void FUN_080ac090(TransEffectSprite* s) { INCFUNC("asm/func/FUN_080ac090.inc"); }

void FUN_080ac100(TransEffectSprite* s) {
  if (s->timer <= 5) {
    s->spr.flags |= SPRFLAG_BLINK_EVEN;
  } else {
    s->spr.flags &= ~SPRFLAG_BLINK_EVEN;
  }

  if (s->timer <= 0xF) {
    s->timer++;
    FUN_080ac090(s);
  }
}

void FUN_080ac13c(TransEffectSprite* s) {
  if (s->timer <= 5) {
    s->spr.flags |= SPRFLAG_BLINK_EVEN;
  } else {
    s->spr.flags &= ~SPRFLAG_BLINK_EVEN;
  }

  if (s->timer == 0) {
    s->spr.flags |= SPRFLAG_HIDDEN;
    s->unk_6c = 0;
  } else {
    s->timer--;
    FUN_080ac090(s);
  }
}

NAKED void FUN_080ac18c(TransEffect* p) { INCFUNC("asm/func/FUN_080ac18c.inc"); }

void FUN_080ac21c(TransEffect* p) { AuxSprite_Remove(&p->circle.spr); }

NAKED void FUN_080ac228(TransEffect* p, Vec3* pos) { INCFUNC("asm/func/FUN_080ac228.inc"); }

// 戻り値は呼んだ先が r0 に残した値をそのまま使う (return 文を書くと1命令増える)
s32 TransEffect_Update(TransEffect* p) {
  FUN_080ac18c(p);
  FUN_080abf9c(p);
  if (p->unk_98 == 0) {
    if (p->unk_9e == 0) {
      KillEntity((Entity*)p);
    }
  }
}

// 戻り値は FUN_080abfec が r0 に残した値をそのまま使う (return 文を書くと1命令増える)
s32 TransEffect_Destroy(TransEffect* p) {
  FUN_080ac21c(p);
  FUN_080abfec(p);
}

s32 TransEffect_Init(TransEffect* p, Player* player, u32 param_3, Vec3* pos, u32 param_5, u32 param_6) {
  p->unk_24 = param_3;
  p->player = player;

  if (pos == NULL) {
    p->pos.x = 0, p->pos.y = 0, p->pos.z = 0;
  } else {
    p->pos = *pos;
  }

  p->unk_25 = p->player->action;
  p->unk_28 = param_5;
  p->unk_2a = param_6;
  FUN_080ac228(p, &p->player->mover.pos);
  FUN_080ac008(p);
  return 0;
}

TransEffect* TransEffect_Create(Player* player, u32 param_2, Vec3* pos, u32 param_4, u32 param_5) {
  TransEffect* p = CreateEntity(ENTITY_UNK_8, sizeof(TransEffect));

  if (p != NULL) {
    SetEntityRoutine(p, TransEffect_Update, TransEffect_Destroy);
    if (TransEffect_Init(p, player, param_2, pos, param_4, param_5) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
