#include "entity.h"
#include "entity_9a9f.h"
#include "global.h"
#include "player.h"
#include "solar.h"
#include "sprite.h"
#include "time.h"
#include "vm.h"

// 天窓から差し込む(スポット的な)光, スプライトは SPRITE_SPOTLIGHT
typedef struct {
  Vec3 pos;             // 0x00, '.p', 足元のタイルの高さに合わせてから入る
  AuxSprite sprite[2];  // 0x08
  AuxSpriteGfx gfx[2];  // 0x60
  s16 unk_98;           // 0x98, '.n', 読み手が見つかっていない
  bool8 unk_9a;         // 0x9A
  u8 unk_9b;            // 0x9B
  u8 unk_9c;            // 0x9C, '.t' の値の4倍
  bool8 active;         // 0x9D
  u16 mapArea;          // 0x9E
  u16 minX;             // 0xA0, 床に落ちる光の矩形, 大きさは '.t', 向きは '.r' で決まる
  u16 minZ;             // 0xA2
  u16 maxX;             // 0xA4
  u16 maxZ;             // 0xA6
} SkylightBeam;
static_assert(sizeof(SkylightBeam) == 168);

// 天窓の光を最大16個持ち、プレイヤーが光の中にいる間 太陽ゲージに応じて ENE を回復させる
// おそらく、太陽光を浴びている状態の判定と浴びている時間に関するEntity, 天窓の情報も管理
typedef struct Entity5CCC {
  Entity e;                // 0x000, ENTITY_UNK_9
  Player* player;          // 0x018
  bool16 unk_1c;           // 0x01C
  s16 charge;              // 0x01E, 120 たまるごとに ENE が1回復する
  u16 idleTimer;           // 0x020, 無操作の間 900 まで増える, 900 に達すると charge が増えなくなる
  u16 unk_22;              // 0x022
  u16 pltt;                // 0x024
  u8 count;                // 0x026, beams の使用数
  u8 unk_27;               // 0x027
  bool8 unk_28;            // 0x028
  bool8 unk_29;            // 0x029
  u8 unk_2a[2];            // 0x02A
  SkylightBeam beams[16];  // 0x02C
  u8 unk_aac[8];           // 0xAAC
} Entity5CCC;
static_assert(sizeof(Entity5CCC) == 2740);

extern Entity5CCC* gEntity5CCC;  // 0x03000140
extern u16 u16_03002bf0;

void FUN_0809df6c(void) { gEntity5CCC = NULL; }

NAKED bool32 FUN_0809df78(Vec3* pos) { INCFUNC("asm/func/FUN_0809df78.inc"); }

NON_MATCH bool32 FUN_0809dfec(s32 param_1) {
#ifdef NONMATCHING_C
  Entity5CCC* p = gEntity5CCC;
  SkylightBeam* beam;
  s32 i;

  if (p == NULL) {
    return FALSE;
  }
  beam = p->beams;
  for (i = 0; i < p->count; i++, beam++) {
    if (beam->unk_9a && beam->mapArea == param_1) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_0809dfec.inc");
#endif
}

// 太陽ゲージに比例した量を返す, 0 にはならない
s32 FUN_0809e034(s32 coef) {
  s32 n = Div(gStat->sunGauge * coef, 10);
  if (n < 1) {
    n = 1;
  }
  return n;
}

// 引数の座標が天窓の下にあるかどうかを判定
NAKED s32 FUN_0809e05c(Vec3* pos) { INCFUNC("asm/func/FUN_0809e05c.inc"); }

// 引数の座標が太陽光を受けているかを判定 (敵用?, 敵には太陽光でダメージを受けるものがいるのでその辺に関係)
NON_MATCH s32 FUN_0809e0d4(Vec3* pos, s32 coef) {
#ifdef NONMATCHING_C
  if (gStat->sunGauge == 0) {
    return 0;
  }
  if (!(gStat->unk_934 & SF934_OUTDOOR) && FUN_0809e05c(pos) < 0 && gEntity5CCC->unk_29 == 0) {
    return 0;
  }
  return FUN_0809e034(coef);
#else
  INCFUNC("asm/func/FUN_0809e0d4.inc");
#endif
}

// プレイヤーが太陽光を受けているかを判定
NON_MATCH bool32 FUN_0809e138(Player* p) {
#ifdef NONMATCHING_C
  if (gStat->sunGauge == 0) {
    return FALSE;
  }
  if ((gStat->unk_934 & SF934_OUTDOOR) || (gEntity5CCC != NULL && FUN_0809e05c(&p->mover.pos) >= 0)) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_0809e138.inc");
#endif
}

NAKED void FUN_0809e198(SkylightBeam* beam, s32 param_2, Vec3* pos, s32 param_4) { INCFUNC("asm/func/FUN_0809e198.inc"); }

void FUN_0809e1f8(void) {
  Entity5CCC* p = gEntity5CCC;

  if (p == NULL) {
    return;
  }
  if (VM_SeekToNamedArg('t')) {
    p->unk_27 = VM_GetValue();
  } else {
    p->unk_27 = 0;
  }
}

NAKED void FUN_0809e22c(SkylightBeam* beam, s32 param_2, Vec3* pos, u32 param_4, s32 pltt) { INCFUNC("asm/func/FUN_0809e22c.inc"); }

NAKED void FUN_0809e2c4(void) { INCFUNC("asm/func/FUN_0809e2c4.inc"); }

NAKED void FUN_0809e3a0(void) { INCFUNC("asm/func/FUN_0809e3a0.inc"); }

NAKED void FUN_0809e54c(void) { INCFUNC("asm/func/FUN_0809e54c.inc"); }

NAKED void FUN_0809e5c4(void) { INCFUNC("asm/func/FUN_0809e5c4.inc"); }

NAKED void FUN_0809e630(Entity5CCC* p, s32 param_2) { INCFUNC("asm/func/FUN_0809e630.inc"); }

NON_MATCH void FUN_0809e734(Entity5CCC* p) {
#ifdef NONMATCHING_C
  u32 flags = p->player->unk_20;
  s32 mode;

  if (flags & 0x20) {
    mode = 2;
  } else {
    mode = (flags & 0x10) != 0;
  }
  FUN_0809e630(p, mode);
#else
  INCFUNC("asm/func/FUN_0809e734.inc");
#endif
}

NAKED void FUN_0809e75c(Entity5CCC* p) { INCFUNC("asm/func/FUN_0809e75c.inc"); }

NAKED void FUN_0809e7c4(Entity5CCC* p) { INCFUNC("asm/func/FUN_0809e7c4.inc"); }

NAKED void FUN_0809e840(Entity5CCC* p) { INCFUNC("asm/func/FUN_0809e840.inc"); }

NAKED void FUN_0809e89c(Entity5CCC* p) { INCFUNC("asm/func/FUN_0809e89c.inc"); }

bool32 FUN_0809e9d0(Entity5CCC* p) {
  if (p->unk_1c) {
    u32 span = Time_GetSpanOfTime();

    if (span < TIME_MORNING || span > TIME_SUNSET) {
      return TRUE;
    }
  }
  return FALSE;
}

// 日光の有無と屋内外で毎フレームの処理を振り分ける
s32 Entity0809eb24_Update(Entity5CCC* p) {
  if (p->unk_29 != 0) {
    p->unk_29 = 0;
  }

  p->player = gPlayerPtr[0];
  if (gPlayerPtr[0] != NULL) {
    u16 override;
    bool32 forced;

    if (gStat->lx == 0) {  // 太陽光が0 (ライジングサンなども含めたもの)
      if (FUN_0809e9d0(p)) {
        FUN_0809e89c(p);
      } else {
        FUN_0809e840(p);
      }
    } else if (gStat->unk_934 & SF934_OUTDOOR) {  // 太陽光がある場合は、屋外と屋内で処理を分ける
      FUN_0809e734(p);                            // 屋外
    } else {
      FUN_0809e7c4(p);  // 屋内
    }

    override = gSunGaugeOverride;
    forced = FALSE;
    if (override == 1) {
      forced = TRUE;
    }
    if (forced && u16_03002bf0 != 0) {
      p->unk_29 = 1;
    }
  }
  return 0;
}

s32 Entity0809eb24_Destroy(Entity5CCC* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (p->beams[i].active) {
      AuxSprite_Remove(p->beams[i].sprite);
    }
  }
  gEntity5CCC = NULL;
  return 0;
}

bool32 FUN_0809eacc(void) {
  if (gFlag030047a4 & FLAG030047A4_UNK_8) {
    return FALSE;
  }
  if (Time_GetMoonPhase() == 4) {  // 満月
    return TRUE;
  }
  return FALSE;
}

s32 Entity0809eb24_Init(Entity5CCC* p, u32 param_2, u32 param_3) {
  p->unk_1c = FUN_0809eacc();
  p->count = 0;
  p->pltt = 410;
  p->unk_28 = 0;
  gEntity5CCC = p;
  return 0;
}

// 1人プレイのときはこっち？
Entity5CCC* Entity0809eb24_Create(u32 param_1, u32 param_2) {
  Entity5CCC* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity5CCC));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0809eb24_Update, Entity0809eb24_Destroy);
    if (Entity0809eb24_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

s32 FUN_0809eb6c(s32 param_1) { return Div(param_1 * Entity9A9F_GetUnk66(), 140); }

NAKED s32 FUN_0809eb94(Vec3* pos, s32 param_2) { INCFUNC("asm/func/FUN_0809eb94.inc"); }

NAKED bool32 FUN_0809ebf4(Player* p) { INCFUNC("asm/func/FUN_0809ebf4.inc"); }

NAKED void FUN_0809ec60(Entity5CCC* p) { INCFUNC("asm/func/FUN_0809ec60.inc"); }

void FUN_0809ed54(Entity5CCC* p) {}

NAKED void FUN_0809ed58(Entity5CCC* p) { INCFUNC("asm/func/FUN_0809ed58.inc"); }

s32 Entity0809eeb4_Update(Entity5CCC* p) {
  if (gStat->unk_934 & SF934_OUTDOOR) {
    FUN_0809ed54(p);
  } else {
    FUN_0809ed58(p);
  }
  FUN_0809ec60(p);
  return 0;
}

s32 Entity0809eeb4_Destroy(Entity5CCC* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (p->beams[i].active) {
      AuxSprite_Remove(p->beams[i].sprite);
    }
  }
  gEntity5CCC = NULL;
  return 0;
}

s32 Entity0809eeb4_Init(Entity5CCC* p, u32 param_2, u32 param_3) {
  p->count = 0;
  p->pltt = 410;
  p->unk_28 = 0;
  gEntity5CCC = p;
  return 0;
}

// 通信時はこっち？
Entity5CCC* Entity0809eeb4_Create(u32 param_1, u32 param_2) {
  Entity5CCC* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity5CCC));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0809eeb4_Update, Entity0809eeb4_Destroy);
    if (Entity0809eeb4_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 天窓の光の管理エンティティを1つだけ作る, 既にあればそれを返す
Entity5CCC* VM_Sub5CCC(u32 param_1, u32 param_2) {
  if (gEntity5CCC != NULL) {
    return gEntity5CCC;
  }
  if (gFlag030047a4 & FLAG030047A4_LINK) {
    return Entity0809eeb4_Create(param_1, param_2);
  }
  return Entity0809eb24_Create(param_1, param_2);
}
