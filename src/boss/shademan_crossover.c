#include "boss.h"
#include "camera.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

// シェードマン(クロスオーバーバトル用)
typedef struct {
  Boss base;                              // 0x000
  u8 unk_158[0x15C - 0x158];              // 0x158
  u16 phaseTimer;                         // 0x15C, 状態の中の段階を進めるたびに 0 に戻すカウンタ
  u16 phase;                              // 0x15E, 状態の中の段階
  s16 unk_160;                            // 0x160
  s16 unk_162;                            // 0x162
  s16 unk_164;                            // 0x164
  u16 unk_166;                            // 0x166
  u8 unk_168;                             // 0x168
  u8 unk_169;                             // 0x169
  u8 shakeAmp;                            // 0x16A, 0 でない間スプライトを乱数で揺らして減らす
  u8 hurtAngle;                           // 0x16B, 最後に当てられた向き
  u16 unk_16c;                            // 0x16C
  u16 damage;                             // 0x16E, ShadeManCrossover_OnHurt が受けたダメージを入れる
  u16 unk_170;                            // 0x170
  u16 unk_172;                            // 0x172
  u32 hurtWeakness;                       // 0x174, 当たってきた攻撃の weakness の控え
  HitboxAttributes hurtAttributes;        // 0x178, 当たってきた攻撃の attributes の控え
  u8 unk_17c[0x180 - 0x17C];              // 0x17C
  HitboxData hitbox;                      // 0x180
  HitboxData hurtbox;                     // 0x1D0, HBFLAG_HURTBOX | HBFLAG_ANGLE | HBFLAG_UNK_0, 他のボスと違って HBFLAG_ACTOR が付かない, ハンドラは ShadeManCrossover_OnHurt
  HitboxData hitbox2;                     // 0x220
  s32 unk_270;                            // 0x270, centerPos から見た角度の 8 倍
  s32 unk_274;                            // 0x274
  s32 unk_278;                            // 0x278
  u32 unk_27c;                            // 0x27C, centerPos からの距離の 256 倍
  u32 unk_280;                            // 0x280
  u32 unk_284;                            // 0x284
  u16 unk_288;                            // 0x288
  u16 unk_28a;                            // 0x28A
  Vec3 centerPos;                         // 0x28C, '.r', 省略するとプレイヤーの位置
  Vec3 unk_294;                           // 0x294
  Vec3 unk_29c;                           // 0x29C
  Vec3 unk_2a4;                           // 0x2A4
  u16 unk_2ac;                            // 0x2AC
  u8 unk_2ae[0x2B2 - 0x2AE];              // 0x2AE
  u8 unk_2b2;                             // 0x2B2
  u8 unk_2b3;                             // 0x2B3
  u8 unk_2b4;                             // 0x2B4
  u8 unk_2b5;                             // 0x2B5
  u8 unk_2b6;                             // 0x2B6
  u8 unk_2b7;                             // 0x2B7
  u8 unk_2b8;                             // 0x2B8
  u8 unk_2b9;                             // 0x2B9
  u8 unk_2ba[0x2BC - 0x2BA];              // 0x2BA
  u8 unk_2bc[2];                          // 0x2BC
  u8 unk_2be[0x2C0 - 0x2BE];              // 0x2BE
  u8 unk_2c0;                             // 0x2C0
  u8 unk_2c1;                             // 0x2C1
  u8 unk_2c2[0x2C4 - 0x2C2];              // 0x2C2
  u16 hurtboxPower;                       // 0x2C4, '.s[1]=100'
  s16 unk_2c6;                            // 0x2C6
  s16 hitboxPower;                        // 0x2C8, '.a[0]=50'
  s16 hitboxKnockback;                    // 0x2CA, '.a[1]=50'
  s16 hitboxUnk44;                        // 0x2CC
  s16 hitbox2Power;                       // 0x2CE, '.a[3]=90'
  s16 hitbox2Knockback;                   // 0x2D0, '.a[4]=50'
  s16 hitbox2Unk44;                       // 0x2D2
  s16 unk_2d4;                            // 0x2D4
  s16 unk_2d6;                            // 0x2D6
  u16 unk_2d8;                            // 0x2D8
  s16 unk_2da;                            // 0x2DA
  s16 unk_2dc;                            // 0x2DC
  s16 unk_2de;                            // 0x2DE
  s16 unk_2e0;                            // 0x2E0
  s16 unk_2e2;                            // 0x2E2
  s16 unk_2e4;                            // 0x2E4
  s16 unk_2e6;                            // 0x2E6
  s16 unk_2e8;                            // 0x2E8
  s16 unk_2ea;                            // 0x2EA
  s16 unk_2ec;                            // 0x2EC
  s16 unk_2ee;                            // 0x2EE
  s16 unk_2f0;                            // 0x2F0
  s16 unk_2f2;                            // 0x2F2
  s16 unk_2f4;                            // 0x2F4
  s16 unk_2f6;                            // 0x2F6
  s16 unk_2f8;                            // 0x2F8
  s16 unk_2fa;                            // 0x2FA
  s16 unk_2fc;                            // 0x2FC
  s16 unk_2fe;                            // 0x2FE
  s16 unk_300;                            // 0x300
  s16 unk_302;                            // 0x302
  s16 unk_304;                            // 0x304
  s16 unk_306;                            // 0x306
  s16 unk_308;                            // 0x308
  u16 unk_30a;                            // 0x30A
  u16 unk_30c;                            // 0x30C
  u8 unk_30e;                             // 0x30E
  u8 unk_30f;                             // 0x30F
  u8 unk_310;                             // 0x310
  u8 unk_311;                             // 0x311
  u8 unk_312[0x314 - 0x312];              // 0x312
  s32 scriptID;                           // 0x314, '.o', scriptArgs の空いている値を引数にして呼ぶ
  s32 scriptID2;                          // 0x318, '.k'
  u32 scriptArgCount;                     // 0x31C
  u32 scriptArgUsed;                      // 0x320, scriptArgs のうち使ったもののビット
  u16 scriptArgs[4];                      // 0x324, '.O'
  MainSpriteGfx gfx;                      // 0x32C, SPRITE_SHADEMAN
  MainSprite sprite;                      // 0x34C
  AuxShadow shadow;                       // 0x3AC
  rgb555 pltt[16][16];                    // 0x418, gObjPlttData の同じ16色を16回写す
  rgb555 pltt_618[16][16];                // 0x618, BlendPltt で色を混ぜる先
  s8 plttFadeMode;                        // 0x818, パレットフェードの種類, -1 で止まる
  s8 plttFade;                            // 0x819, BlendPltt の混ぜ具合 (0..31)
  u16 plttFadeTo;                         // 0x81A, フェード先のパレット番号
  u16 stateDuration;                      // 0x81C, 状態を続ける最短フレーム数
  u8 unk_81e;                             // 0x81E
  u8 unk_81f;                             // 0x81F
  u16 unk_820;                            // 0x820, プレイヤーまでの距離 / 32 に 1 ずつ寄せる
  u16 unk_822;                            // 0x822
  u16 unk_824;                            // 0x824
  u16 spriteIdx;                          // 0x826, 次に使う sprites_834 の番号, 0..2 を回す
  u16 spriteTimers[3];                    // 0x828, 0 になった瞬間 sprites_834 の同じ番号を隠す
  u16 unk_82e[3];                         // 0x82E
  MainSprite sprites_834[3];              // 0x834
  struct Entity0805e67c* entity0805e67c;  // 0x954
  struct Entity0805ee80* entity0805ee80;  // 0x958
} ShadeManCrossover;
static_assert(sizeof(ShadeManCrossover) == 2396);

const u8 u8_ARRAY_085aaf2c[64] = {0, 2, 3, 4, 4, 3, 1, 6, 3, 0, 5, 0, 5, 3, 4, 6, 4, 3, 1, 6, 0, 4, 2, 3, 3, 0, 5, 0, 4, 6, 5, 3, 0, 3, 4, 2, 4, 3, 1, 6, 3, 0, 5, 0, 4, 6, 5, 3, 3, 4, 0, 2, 3, 0, 5, 0, 4, 3, 1, 6, 5, 3, 4, 6};  // 0x085AAF2C

void ShadeManCrossover_UnregisterHurtbox(ShadeManCrossover*);
void ShadeManCrossover_RemoveSprites(ShadeManCrossover*);

void FUN_0803d8e4(ShadeManCrossover*);
void FUN_0803d93c(ShadeManCrossover*);
void FUN_0803d9b4(ShadeManCrossover*);
void FUN_0803da2c(ShadeManCrossover*);
void FUN_0803da90(ShadeManCrossover*);
void FUN_0803dd88(ShadeManCrossover*);
void FUN_0803de00(ShadeManCrossover*);
void FUN_0803de78(ShadeManCrossover*);
void FUN_0803def0(ShadeManCrossover*);
void FUN_0803df68(ShadeManCrossover*);
void FUN_0803dfe0(ShadeManCrossover*);
void FUN_0803e058(ShadeManCrossover*);
void FUN_0803e4f4(ShadeManCrossover*);

void (*const PTR_ARRAY_085aaf6c[13])(ShadeManCrossover*) = {
    FUN_0803d8e4,
    FUN_0803d93c,
    FUN_0803d9b4,
    FUN_0803da2c,
    FUN_0803da90,
    FUN_0803dd88,
    FUN_0803de00,
    FUN_0803de78,
    FUN_0803def0,
    FUN_0803df68,
    FUN_0803dfe0,
    FUN_0803e058,
    FUN_0803e4f4,
};  // 0x085AAF6C

void FUN_0803e578(ShadeManCrossover*);
void FUN_0803e5d8(ShadeManCrossover*);

void (*const PTR_ARRAY_085aafa0[2])(ShadeManCrossover*) = {
    FUN_0803e578,
    FUN_0803e5d8,
};  // 0x085AAFA0

void FUN_0803e5fc(ShadeManCrossover*);

void (*const PTR_ARRAY_085aafa8[1])(ShadeManCrossover*) = {
    FUN_0803e5fc,
};  // 0x085AAFA8

void FUN_0803e618(ShadeManCrossover*);

void (*const PTR_ARRAY_085aafac[1])(ShadeManCrossover*) = {
    FUN_0803e618,
};  // 0x085AAFAC

void FUN_0803e634(ShadeManCrossover*);
void FUN_0803e670(ShadeManCrossover*);

void (*const PTR_ARRAY_085aafb0[2])(ShadeManCrossover*) = {
    FUN_0803e634,
    FUN_0803e670,
};  // 0x085AAFB0

void FUN_0803e6b0(Boss*, s32);
void FUN_0803e860(Boss*, s32);
void FUN_0803e9f4(Boss*, s32);
void FUN_0803ea98(Boss*, s32);
void FUN_0803ebc4(Boss*, s32);
void FUN_0803ed40(Boss*, s32);
void FUN_0803ee50(Boss*, s32);
void FUN_0803ef80(Boss*, s32);
void FUN_0803f2f4(Boss*, s32);
void FUN_0803f5b8(Boss*, s32);
void FUN_0803f8cc(Boss*, s32);
void FUN_0803fc70(Boss*, s32);
void FUN_0803fef0(Boss*, s32);
void FUN_080400a4(Boss*, s32);

void (*const PTR_ARRAY_085aafb8[15])(Boss*, s32) = {
    NULL,
    FUN_0803e6b0,
    FUN_0803e860,
    FUN_0803e9f4,
    FUN_0803ea98,
    FUN_0803ebc4,
    FUN_0803ed40,
    FUN_0803ee50,
    FUN_0803ef80,
    FUN_0803f2f4,
    FUN_0803f5b8,
    FUN_0803f8cc,
    FUN_0803fc70,
    FUN_0803fef0,
    FUN_080400a4,
};  // 0x085AAFB8

static inline void ShadeManCrossover_ResetSubStates(ShadeManCrossover* p, u32 duration) {
  Boss_SetSubStates(&p->base, 0, 0, 0);
  p->stateDuration = duration;
}

static inline void ShadeManCrossover_UpdateUnk160(ShadeManCrossover* p, s32 timer) {
  if (p->unk_162 < 62) {
    p->unk_162 += 2;
  }
  p->unk_160 = p->unk_162 + FixToInt(12, SIN(timer * 2) * 40);
  if (p->unk_160 < 0) {
    p->unk_160 = 0;
  }
}

static inline void ShadeManCrossover_SetShake(ShadeManCrossover* p, u32 amp) { p->shakeAmp = amp; }

// 本体のパレット番号を返す, パレットのフェードもこの番号へ戻す
s32 ShadeManCrossover_GetPlttID(void* _) { return BOSS_SHADEMAN_CROSSOVER; }

s32 FUN_08235408(Vec3* dst, Vec3* pos, s32 pathIdx, u32 minDistSq);
s32 Map_FindPathNodeBeyond(Vec3* dst, Vec3* pos, s32 pathIdx, u32 minDistSq);
s32 Map_FindNearestPathNode(Vec3* dst, Vec3* pos, s32 pathIdx);
void FUN_0807ae6c(struct Player* p, u32 param_2, s32 param_3);
void FUN_08050e2c(u32 param_1, u32 param_2, Vec3* pos);
struct Entity0805e67c* Entity0805e67c_Create(void);
struct Entity0805ee80* Entity0805ee80_Create(s32 param_1);
void FUN_08050e50(u32 param_1, u32 param_2);
void FUN_08050d28(void);
s32 FUN_08050d40(void);
void FUN_0823b880(s32 n);
void FUN_0805e79c(struct Entity0805e67c* p, Vec3* pos, u32 angle, s32 speed, s32 power, s32 param_6, s32 param_7);
void FUN_0805eee4(struct Entity0805ee80* p, u32 angle, s32 param_3, s32 power, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, Vec3* pos);
void FUN_0805e6bc(struct Entity0805e67c* p, Vec3* pos, u32 angle, s32 speed, s32 power, s32 param_6, s32 param_7);
s32 FUN_08050e80(void);
void FUN_08050cb8(Vec3* pos, u32 kind);
void FUN_0805ef68(struct Entity0805ee80* p, u32 angle, s32 param_3, s32 power, s32 param_5, s32 param_6, s32 param_7, s32 param_8, Vec3* pos);

void FUN_0803cee4(ShadeManCrossover*);
void FUN_0803e68c(ShadeManCrossover*);
void FUN_08040184(ShadeManCrossover*);
void FUN_0803d0a4(ShadeManCrossover*);

void ShadeManCrossover_OnHurt(HitboxData* a, HitboxData* b, ShadeManCrossover* p) {
  Boss* boss = &p->base;
  u32 weakness;
  HitboxAttributes attributes;

  Hitbox_ApplyDamage(a, b);
  p->damage = b->damage;
  if (TEST_FLAGS(a->flags, HBFLAG_ANGLE)) {
    p->hurtAngle = a->angle;
  } else {
    p->hurtAngle = ArcTan2_8(b->center.x - a->center.x, b->center.z - a->center.z);
  }
  weakness = a->weakness;
  Boss_SetWeaponExpMask(boss, weakness);
  attributes = a->attributes;
  Boss_SetHurtAttributes(boss, attributes);
  p->unk_2a4 = b->unk_2c;
  if (b->hitResult & 8) {
    p->unk_166 = 1;
  }
  p->hurtWeakness = weakness;
  p->hurtAttributes = attributes;
}

void FUN_0803c260(void) {}

void ShadeManCrossover_UnregisterHurtbox(ShadeManCrossover* p) { Hitbox_Unregister(&p->hurtbox); }

s32 FUN_0803c274(ShadeManCrossover* p, Vec3* out) {
  Mover* mover = &p->base.mover;
  s32 angle = ((mover->angle - 0x20) & ~0x3F) + 0x40;

  Vec3_SetPolar(out, angle, 0xA4);
  if (angle == 0) {
    out->z -= 0x20;
  } else if (angle == 0x40) {
    out->x -= 0x20;
  } else if (angle == 0x80) {
    out->z += 0x20;
  } else if (angle == 0xC0) {
    out->x += 0x20;
  }
  Vec3_Add(out, &mover->pos);
}

void FUN_0803c328(ShadeManCrossover* p) {
  Mover* mover = &p->base.mover;
  Vec3* target = p->base.playerPos[0];
  s32 dist = Sqrt(p->base.playerDistSq[0]) >> 5;
  s32 scale;
  Vec3 pos;

  if (p->unk_820 > dist) {
    p->unk_820--;
  } else if (p->unk_820 < dist) {
    p->unk_820++;
  }
  scale = 0x80 - p->unk_820;
  scale = FixToInt(7, scale * p->unk_822);
  VEC3_SET(pos, target->x - FixToInt(8, (target->x - mover->pos.x) * scale), target->y + 0x78, target->z - FixToInt(8, (target->z - mover->pos.z) * scale));
  Camera_MoveTo(&pos);
}

void FUN_0803c40c(Vec3* from, Vec3* to, u8* angle, u16* dist) {
  s32 dx = to->x - from->x;
  s32 dz = to->z - from->z;
  s32 distSq = dx * dx + dz * dz;

  if (distSq == 0) {
    *angle = 0;
    *dist = 0;
  } else {
    *angle = ArcTan2_8(dx, dz);
    *dist = Sqrt(distSq);
  }
}

// 残差は ofs のアドレスの持ち方 (60/60), 原典は足し算で sp を 2 回写し直す
NON_MATCH void FUN_0803c454(Vec3* dst, Vec3* center, u8 angle, u16 radius) {
#ifdef NONMATCHING_C
  Vec3 ofs;

  Vec3_SetPolar(&ofs, angle, radius);
  Vec3_Sum(dst, center, &ofs);
#else
  INCFUNC("asm/func/FUN_0803c454.inc");
#endif
}

void FUN_0803c4d4(ShadeManCrossover* p, Vec3* target, u32 duration) {
  u8 angle;
  u16 dist;
  s32 diff;

  p->unk_294 = *target;
  FUN_0803c40c(&p->centerPos, &p->unk_294, &angle, &dist);
  p->unk_274 = angle << 8;
  p->unk_280 = dist << 8;
  p->unk_288 = 0;
  p->unk_28a = duration;
  diff = p->unk_274 - p->unk_270;
  if (abs(diff) > 0x8000) {
    if (diff < 0) {
      diff += 0x10000;
    } else {
      diff -= 0x10000;
    }
    p->unk_274 = p->unk_270 + diff;
  }
  p->unk_278 = p->unk_270;
  p->unk_284 = p->unk_27c;
}

void FUN_0803c590(ShadeManCrossover* p) {
  u8 angle;
  u16 dist;

  FUN_0803c40c(&p->centerPos, &p->base.mover.pos, &angle, &dist);
  p->unk_270 = angle << 8;
  p->unk_27c = dist << 8;
}

void FUN_0803c5d0(ShadeManCrossover* p) {
  s32 rest;

  p->unk_288++;
  rest = p->unk_28a - p->unk_288;
  p->unk_270 = Div(p->unk_278 * rest + p->unk_274 * p->unk_288, p->unk_28a);
  p->unk_27c = Div(p->unk_284 * rest + p->unk_280 * p->unk_288, p->unk_28a);
  if (p->unk_270 < 0) {
    p->unk_270 += 0x10000;
  }
  p->unk_270 &= 0xFFFF;
}

void FUN_0803c660(ShadeManCrossover* p) { FUN_0803c454(&p->base.mover.pos, &p->centerPos, FixToInt(8, p->unk_270), p->unk_27c >> 8); }

// 残差は playerPos の読み方 (39/40), 原典は読んだ値を別のレジスタに写してから使い 0 を r5 に作り直す
NON_MATCH s32 FUN_0803c6a0(ShadeManCrossover* p, Vec3* min, Vec3* max) {
#ifdef NONMATCHING_C
  Vec3* pos = p->base.playerPos[0];

  if (pos != NULL) {
    bool32 inside = FALSE;

    if (pos->x >= min->x && pos->x <= max->x && pos->z >= min->z && pos->z <= max->z) {
      inside = TRUE;
    }
    if (inside) {
      return 0;
    }
  }
  return -1;
#else
  INCFUNC("asm/func/FUN_0803c6a0.inc");
#endif
}

void FUN_0803c6f0(ShadeManCrossover* p, Vec3* pos) {
  u32 plttIdx = 7;
  s32 i;

  for (i = 0; i < 3; i++) {
    rgb555* pltt;

    MainSprite_Add(&p->sprites_834[i], &p->gfx, 0, SPRFLAG_HIDDEN | SPRFLAG_BLINK_ODD, 2, PLAYMODE_PAUSE, 60, pos);
    p->sprites_834[i].plttID = 0x4300;
    pltt = &gObjPlttData[plttIdx * 16];
    p->sprites_834[i].pltt = pltt;
  }
}

void ShadeManCrossover_RemoveSprites(ShadeManCrossover* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    MainSprite_Remove(&p->sprites_834[i]);
  }
}

void FUN_0803c78c(ShadeManCrossover* p, s32 kind, u32 param_3) {
  u32 plttIdx;
  rgb555* pltt;

  p->sprites_834[p->spriteIdx].flags &= ~SPRFLAG_HIDDEN;
  FUN_0822f588(&p->sprites_834[p->spriteIdx], &p->sprite, 9);
  if (p->spriteIdx & 1) {
    p->sprites_834[p->spriteIdx].flags |= SPRFLAG_BLINK_ODD;
  } else {
    p->sprites_834[p->spriteIdx].flags |= SPRFLAG_BLINK_EVEN;
  }
  p->sprites_834[p->spriteIdx].pos = p->sprite.pos;
  p->unk_82e[p->spriteIdx] = param_3;
  p->spriteTimers[p->spriteIdx] = 12;
  switch (kind) {
    case 1: {
      plttIdx = 11;
      break;
    }
    case 0:
    default: {
      plttIdx = ShadeManCrossover_GetPlttID(p);
      break;
    }
  }
  pltt = &gObjPlttData[plttIdx * 16];
  p->sprites_834[p->spriteIdx].pltt = pltt;
  if (++p->spriteIdx > 2) {
    p->spriteIdx = 0;
  }
  p->unk_824 = 0;
}

void FUN_0803c8b4(ShadeManCrossover* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    if (p->spriteTimers[i] != 0) {
      p->spriteTimers[i]--;
      if (p->spriteTimers[i] == 0) {
        p->sprites_834[i].flags |= SPRFLAG_HIDDEN;
      }
    }
  }
  p->unk_824++;
}

s32 ShadeManCrossover_FindFreeScriptArg(ShadeManCrossover* p) {
  u32 i;

  for (i = 0; i < p->scriptArgCount; i++) {
    if (!(p->scriptArgUsed & (1 << i))) {
      return i;
    }
  }
  return -1;
}

void FUN_0803c938(ShadeManCrossover* p, Vec3* pos, u32 param_3) {
  s32 idx = ShadeManCrossover_FindFreeScriptArg(p);

  if (p->scriptID && idx >= 0) {
    u32 argv[5];
    ScriptArgs args;

    argv[0] = p->scriptArgs[idx];
    argv[1] = pos->x;
    argv[2] = pos->y;
    argv[3] = pos->z;
    argv[4] = param_3;
    args.argc = 5, args.argv = argv;
    p->scriptArgUsed |= 1 << idx;
    VM_ExecByID(p->scriptID, &args);
  }
}

void Cmd_FreeShadeManCrossoverScriptArg(void) {
  ShadeManCrossover* p = Boss_Get(BOSS_SHADEMAN_CROSSOVER);

  if (p != NULL && p->base.bossID == BOSS_SHADEMAN_CROSSOVER) {
    u32 arg = VM_GetNamedArgValue('n', 0);
    u32 i;

    for (i = 0; i < p->scriptArgCount; i++) {
      if (p->scriptArgs[i] == arg) {
        p->scriptArgUsed &= ~(1 << i);
      }
    }
  }
}

void FUN_0803ca14(void) {
  ShadeManCrossover* p = Boss_Get(BOSS_SHADEMAN_CROSSOVER);

  if (p != NULL && p->base.bossID == BOSS_SHADEMAN_CROSSOVER && p->scriptID2) {
    VM_ExecByID(p->scriptID2, NULL);
  }
}

// 残差は乱数の添字と 3 のマスクの持ち方 (99/101), Durathror の FUN_080371d4 と同じ壁
NON_MATCH void FUN_0803ca40(WorldPos* pos) {
#ifdef NONMATCHING_C
  Vec3 size;

  VEC3_SET(size, Q8(0.641), Q8(0.063), Q8(0.641));
  EmitSmoke(pos, 3, &size, (u8)Random(), (Random() & 3) + 2, (Random() & 3) + 20, 2, 2);
  EmitSmoke(pos, 3, &size, (u8)Random(), (Random() & 3) + 2, (Random() & 3) + 20, 2, 2);
#else
  INCFUNC("asm/func/FUN_0803ca40.inc");
#endif
}

void FUN_0803cb24(void) {
  ShadeManCrossover* p = Boss_Get(BOSS_SHADEMAN_CROSSOVER);

  if (p != NULL) {
    p->unk_2c0 = 0;
    p->unk_2c1 = 0;
  }
}

void FUN_0803cb4c(u32 param_1) {
  ShadeManCrossover* p = Boss_Get(BOSS_SHADEMAN_CROSSOVER);

  if (p != NULL) {
    p->unk_2c1 = param_1;
  }
}

void FUN_0803cb6c(s32 count) {
  ShadeManCrossover* p = Boss_Get(BOSS_SHADEMAN_CROSSOVER);

  if (p != NULL) {
    s32 i;

    for (i = 0; i < count; i++) {
      Vec3 pos;

      Map_PickRandomPathNode(&pos, 8);
      FUN_0803c938(p, &pos, count);
    }
    FUN_08050e2c(1, 0, &p->centerPos);
  }
}

// 残差は分岐の合流 (74/71), 原典は各分岐で players[0] のアドレスを作って FUN_08050e2c の呼び出しを共有する
NON_MATCH void FUN_0803cbb4(s32 kind) {
#ifdef NONMATCHING_C
  ShadeManCrossover* p = Boss_Get(BOSS_SHADEMAN_CROSSOVER);

  if (p != NULL) {
    if (kind == 1 || kind == 4) {
      FUN_0807ae6c(p->base.players[0], 1, Div(kind, 3) + 1);
    } else if (kind == 2 || kind == 5) {
      FUN_0807ae6c(p->base.players[0], 3, Div(kind, 3) + 1);
    } else {
      Player_ApplyBadCondition(p->base.players[0], 2, (Div(kind, 3) * p->unk_311 + p->unk_310) * 60);
    }
    FUN_08050e2c(2, 0, &p->base.players[0]->mover.pos);
  }
#else
  INCFUNC("asm/func/FUN_0803cbb4.inc");
#endif
}

void FUN_0803cc54(u32 param_1) {
  ShadeManCrossover* p = Boss_Get(BOSS_SHADEMAN_CROSSOVER);

  if (p != NULL) {
    p->unk_2c0 = param_1;
  }
}

void FUN_0803cc70(void) {
  ShadeManCrossover* p = Boss_Get(BOSS_SHADEMAN_CROSSOVER);

  if (p != NULL) {
    Hitbox_SetPowerAndAttributes(&p->hurtbox, 0, HBATTR_DARK | HBATTR_IMMORTAL, HBATTR_SOL);
    p->unk_2b6 = TRUE;
  }
}

void ShadeManCrossover_InitHitbox(ShadeManCrossover* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.25), Q8(0.5), Q8(0.25));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_0803c260, p);
  Hitbox_SetAttack(hitbox, p->hitboxPower, p->hitboxKnockback, 0, 0, p->hitboxUnk44);
}

void ShadeManCrossover_InitHitbox2(ShadeManCrossover* p) {
  HitboxData* hitbox = &p->hitbox2;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.563), Q8(0.5), Q8(0.563));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_0803c260, p);
  Hitbox_SetAttack(hitbox, p->hitbox2Power, p->hitbox2Knockback, 0, HBATTR_17 | HBATTR_18, p->hitbox2Unk44);
}

void ShadeManCrossover_InitHurtbox(ShadeManCrossover* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.375), Q8(0.5), Q8(0.375));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &p->sprite.pos, 0);
  Hitbox_SetHandler(hurtbox, ShadeManCrossover_OnHurt, p);
  Hitbox_SetPowerAndAttributes(hurtbox, power, HBATTR_IMMORTAL | HBATTR_DARK, HBATTR_SOL);
  Hitbox_Register(hurtbox);
}

// 残差は和を置くレジスタだけ (29/29)
NON_MATCH void FUN_0803ce8c(ShadeManCrossover* p) {
#ifdef NONMATCHING_C
  p->unk_169 = 0;
  p->unk_2b6 = FALSE;
  p->unk_2ac = 0;
  p->unk_2b7 = (Random() + gFrameCounter) & 3;
#else
  INCFUNC("asm/func/FUN_0803ce8c.inc");
#endif
}

// 1 回目で打ち切り (203/203), 定数の作り方とレジスタの割り当てがずれる
NON_MATCH void FUN_0803cee4(ShadeManCrossover* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Mover* mover = &p->base.mover;
  Vec3** playerPos;

  Mover_ApplyMove(mover);
  Boss_AdvanceAnim(&p->base, &p->sprite, &p->gfx);
  mover->pos.y = p->unk_164;
  p->sprite.pos.x = mover->pos.x;
  p->sprite.pos.y = p->unk_160 + mover->pos.y;
  p->sprite.pos.z = mover->pos.z;
  if (p->shakeAmp) {
    u16 angle = Random();

    p->sprite.pos.x += FixToInt(12, COS(angle) * (p->shakeAmp * 4));
    p->sprite.pos.z += FixToInt(12, SIN(angle) * (p->shakeAmp * 4));
    p->shakeAmp--;
  }
  FUN_08022e20(boss);
  playerPos = boss->playerPos;
  if (*playerPos != NULL) {
    s32 dx = (*playerPos)->x - boss->mover.pos.x;
    s32 dz = (*playerPos)->z - boss->mover.pos.z;

    boss->playerAngle[0] = ArcTan2_8(dx, dz);
    boss->playerDistSq[0] = dx * dx + dz * dz;
  }
  if (!TEST_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_UNK_1) && FUN_08050d40()) {
    s32 heal = boss->maxHP >> 4;
    s32 hp = p->base.hp;

    Boss_SetHP(&p->base, hp + heal);
    if (hp != p->base.hp) {
      Vec3 ofs;

      VEC3_SET(ofs, Q8(0.063), 0, Q8(0.063));
      CreateDamageNumber(&p->hurtbox, heal, 1, &p->base.mover.pos, &ofs, 1);
    }
    PlaySound_0824078c(SONG_884);
  }
#else
  INCFUNC("asm/func/FUN_0803cee4.inc");
#endif
}

// 1 回目で打ち切り (590/605)
NON_MATCH void FUN_0803d0a4(ShadeManCrossover* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Mover* mover = &boss->mover;
  HitboxData* hitbox;
  s32 power;

  FUN_08022ec0(boss);
  FUN_0803c8b4(p);
  if (p->unk_172 != 0) {
    SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
    p->unk_172--;
  }
  hitbox = &p->hurtbox;
  if (TEST_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX)) {
    Hitbox_SetFlags(hitbox, HBFLAG_HIDDEN);
  } else {
    Hitbox_ClearFlags(hitbox, HBFLAG_HIDDEN);
    Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
    p->hurtbox.angle = mover->angle;
  }
  hitbox = &p->hitbox;
  if (!TEST_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX)) {
    if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_22)) {
      power = p->unk_2d4;
      if (p->unk_2b6) {
        power = (p->unk_2c6 * power) >> 6;
      }
      Hitbox_SetAttack(hitbox, power, p->unk_2d6, 0, HBATTR_17, p->unk_2dc);
    } else {
      power = p->hitboxPower;
      if (p->unk_2b6) {
        power = (p->unk_2c6 * power) >> 6;
      }
      Hitbox_SetAttack(hitbox, power, p->hitboxKnockback, 0, 0, p->hitboxUnk44);
    }
    Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
    hitbox->angle = mover->angle;
    Hitbox_Register(hitbox);
  }
  hitbox = &p->hitbox2;
  if (TEST_FLAGS(boss->flags, BOSSFLAG_HITBOX2)) {
    Vec3 pos;

    power = p->hitbox2Power;
    if (p->unk_2b6) {
      power = (p->unk_2c6 * power) >> 6;
    }
    Hitbox_SetAttack(hitbox, power, p->hitbox2Knockback, 0, HBATTR_17 | HBATTR_18, p->hitbox2Unk44);
    FUN_0803c274(p, &pos);
    Hitbox_SetPos(hitbox, &pos, 0);
    p->hitbox2.angle = ((mover->angle - 0x20) & ~0x3F) + 0x40;
    Hitbox_Register(hitbox);
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_HIDDEN)) {
    MainSprite_Hide(&p->sprite);
    AuxShadow_Hide(&p->shadow);
    CLEAR_FLAGS(boss->flags, BOSSFLAG_VISIBLE);
  } else {
    MainSprite_Show(&p->sprite);
    if (TEST_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW)) {
      AuxShadow_Hide(&p->shadow);
    } else {
      AuxShadow_Show(&p->shadow);
    }
    SET_FLAGS(boss->flags, BOSSFLAG_VISIBLE);
  }
  if (p->unk_170 > 0) {
    if (--p->unk_170 == 0) {
      u32 plttIdx = ShadeManCrossover_GetPlttID(p);

      p->sprite.pltt = plttIdx != 0 ? &gObjPlttData[plttIdx * 16] : p->pltt[0];
    }
  } else if (p->plttFadeMode == 0) {
    BlendPltt(p->pltt_618[0], &gObjPlttData[ShadeManCrossover_GetPlttID(p) * 16], &gObjPlttData[p->plttFadeTo * 16], p->plttFade, 5);
    p->sprite.pltt = p->pltt_618[0];
    if (++p->plttFade > 30) {
      p->plttFade = 31;
    }
  } else if (p->plttFadeMode == 1) {
    BlendPltt(p->pltt_618[0], &gObjPlttData[ShadeManCrossover_GetPlttID(p) * 16], &gObjPlttData[p->plttFadeTo * 16], p->plttFade, 5);
    p->sprite.pltt = p->pltt_618[0];
    if (--p->plttFade <= 0) {
      u32 plttIdx;

      p->plttFade = 0;
      p->plttFadeMode = -1;
      p->plttFadeTo = ShadeManCrossover_GetPlttID(p);
      plttIdx = ShadeManCrossover_GetPlttID(p);
      p->sprite.pltt = plttIdx == 0 ? p->pltt[0] : &gObjPlttData[plttIdx * 16];
    }
  } else if (p->plttFadeMode == 2) {
    BlendPltt(p->pltt_618[0], &gObjPlttData[ShadeManCrossover_GetPlttID(p) * 16], &gObjPlttData[p->plttFadeTo * 16], p->plttFade, 5);
    p->sprite.pltt = p->pltt_618[0];
    if (p->unk_81e) {
      if (--p->plttFade <= 0) {
        u32 plttIdx;

        p->plttFade = 0;
        p->plttFadeMode = -1;
        p->plttFadeTo = ShadeManCrossover_GetPlttID(p);
        plttIdx = ShadeManCrossover_GetPlttID(p);
        p->sprite.pltt = plttIdx == 0 ? p->pltt[0] : &gObjPlttData[plttIdx * 16];
      }
    } else if (++p->plttFade > 30) {
      p->plttFade = 31;
      p->unk_81e = TRUE;
    }
  } else if (p->plttFadeMode == 3) {
    BlendPltt(p->pltt_618[0], &gObjPlttData[ShadeManCrossover_GetPlttID(p) * 16], &gObjPlttData[p->plttFadeTo * 16], p->plttFade, 5);
    p->sprite.pltt = p->pltt_618[0];
    if (!p->unk_81e) {
      if (++p->plttFade > 30) {
        p->plttFade = 31;
        p->unk_81e = TRUE;
      }
    } else if (--p->plttFade <= 0) {
      p->plttFade = 0;
      p->unk_81e = FALSE;
    }
  }
  if (!boss->isDemo) {
    if (TEST_FLAGS(boss->flags, BOSSFLAG_VISIBLE) && !TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
      if (!p->unk_81f) {
        p->unk_81f = TRUE;
        p->unk_820 = Sqrt(boss->playerDistSq[0]) >> 5;
        p->unk_822 = 0;
      }
      FUN_0803c328(p);
      p->unk_822 += 2;
      if (p->unk_822 > 128) {
        p->unk_822 = 128;
      }
    } else {
      p->unk_81f = FALSE;
      FUN_0823b880(8);
    }
  }
  boss->weaponExpMask = 0;
  boss->hurtAttributes = 0;
  boss->frameCount++;
#else
  INCFUNC("asm/func/FUN_0803d0a4.inc");
#endif
}

s32 FUN_0803d618(ShadeManCrossover* p) {
  if (!p->unk_2c1) {
    return FALSE;
  }
  Boss_SetSubState2(&p->base, 10);
  return TRUE;
}

// 残差は unk_2b7 に入れる和のレジスタだけ (206/206), FUN_0803ce8c と同じ
NON_MATCH void FUN_0803d64c(ShadeManCrossover* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  Random();
  if (FUN_0803d618(p)) {
    return;
  }
  switch (u8_ARRAY_085aaf2c[p->unk_2ac + p->unk_2b7 * 16]) {
    case 0: {
      Vec3* dst = &p->unk_294;
      Vec3* pos = &boss->mover.pos;
      s32 dx;
      s32 dz;

      Map_FindPathNodeBeyond(dst, pos, 6, 0x300);
      dx = pos->x - dst->x;
      dz = pos->z - dst->z;
      if (dx * dx + dz * dz <= 0xFFFF) {
        Map_FindPathNodeBeyond(dst, boss->playerPos[0], 6, 0x300);
      }
      p->unk_16c = 0x40;
      Boss_SetSubState2(boss, 1);
      break;
    }
    case 1: {
      Vec3* dst = &p->unk_294;
      Vec3* pos = &boss->mover.pos;
      s32 dx;
      s32 dz;

      Map_FindPathNodeBeyond(dst, pos, 4, 0x300);
      dx = pos->x - dst->x;
      dz = pos->z - dst->z;
      if (dx * dx + dz * dz <= 0xFFFF) {
        Map_FindPathNodeBeyond(dst, boss->playerPos[0], 4, 0x300);
      }
      p->unk_16c = 0x20;
      Boss_SetSubState2(boss, 1);
      break;
    }
    case 2: {
      Boss_SetSubState2(boss, 7);
      break;
    }
    case 3: {
      Boss_SetSubState2(boss, 9);
      break;
    }
    case 4: {
      Boss_SetSubState2(boss, 3);
      break;
    }
    case 5: {
      if (Boss_GetHPRatio(boss) > 63) {
        Boss_SetSubState2(boss, 7);
      } else {
        Boss_SetSubState2(boss, 8);
      }
      break;
    }
    case 6: {
      if (Boss_GetHPRatio(boss) > 63) {
        Boss_SetSubState2(boss, 3);
      } else {
        Boss_SetSubState2(boss, 11);
      }
      break;
    }
  }
  if (++p->unk_2ac > 15) {
    p->unk_2ac = 0;
    p->unk_2b7 = (Random() + gFrameCounter) & 3;
  }
#else
  INCFUNC("asm/func/FUN_0803d64c.inc");
#endif
}

s32 FUN_0803d844(ShadeManCrossover* p) {
  if (p->base.hp <= 0 && p->base.canDie) {
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_1);
    Boss_SetState(&p->base, FUN_080400a4, 14);
  }
  p->base.canDie = 0;
  if (TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_1)) {
    Boss_SetSubStates(&p->base, 1, 0, 1);
    return TRUE;
  }
  if (TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_0)) {
    Boss_SetSubStates(&p->base, 1, 0, 0);
    return TRUE;
  }
  return FALSE;
}

void FUN_0803d8e4(ShadeManCrossover* p) {
  Boss* boss = &p->base;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss) == TRUE) {
    Boss_RequestState(boss, 1);
  }
  if (boss->subStateTimer > p->stateDuration) {
    FUN_0803d64c(p);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0803d93c(ShadeManCrossover* p) {
  Boss* boss = &p->base;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 2);
  }
  if (boss->subStateDone) {
    ShadeManCrossover_ResetSubStates(p, 10);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0803d9b4(ShadeManCrossover* p) {
  Boss* boss = &p->base;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 3);
  }
  if (boss->subStateDone) {
    ShadeManCrossover_ResetSubStates(p, 15);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0803da2c(ShadeManCrossover* p) {
  Boss* boss = &p->base;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 4);
  }
  if (boss->subStateDone) {
    Boss_SetSubState2(boss, 4);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0803da90(ShadeManCrossover* p) {
  Boss* boss = &p->base;
  Mover* mover = &boss->mover;
  Vec3 front;
  Vec3 min;
  Vec3 max;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 5);
    p->unk_2b4 = 0;
  }
  Vec3_SetPolar(&front, mover->angle, 200);
  Vec3_Add(&front, &mover->pos);
  min.x = -200, min.z = -200;
  Vec3_Add(&min, &front);
  max.x = 200, max.z = 200;
  Vec3_Add(&max, &front);
  if (FUN_0803c6a0(p, &min, &max) >= 0) {
    Boss_SetSubState2(boss, 5);
  } else {
    s32 radius = 400;
    Mover* m = &p->base.mover;
    Vec3 pos;
    s32 height;
    TileAttr attr;
    s32 dy;

    Vec3_SetPolar(&pos, m->angle, radius);
    Vec3_Add(&pos, &m->pos);
    height = TileHeightAt(&pos);
    attr = GetTileAttrAt(&pos);
    dy = height - p->unk_164;
    if (dy < -0x1FF || dy > 0xFF || (attr & TATTR_WALL) || boss->subStateDone) {
      Boss_SetSubState2(boss, 6);
    } else {
      boss->subStateTimer++;
    }
  }
}

void FUN_0803dd88(ShadeManCrossover* p) {
  Boss* boss = &p->base;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 6);
  }
  if (boss->subStateDone) {
    ShadeManCrossover_ResetSubStates(p, 15);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0803de00(ShadeManCrossover* p) {
  Boss* boss = &p->base;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 7);
  }
  if (boss->subStateDone) {
    ShadeManCrossover_ResetSubStates(p, 10);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0803de78(ShadeManCrossover* p) {
  Boss* boss = &p->base;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 8);
  }
  if (boss->subStateDone) {
    ShadeManCrossover_ResetSubStates(p, 10);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0803def0(ShadeManCrossover* p) {
  Boss* boss = &p->base;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 9);
  }
  if (boss->subStateDone) {
    ShadeManCrossover_ResetSubStates(p, 10);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0803df68(ShadeManCrossover* p) {
  Boss* boss = &p->base;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 10);
  }
  if (boss->subStateDone) {
    ShadeManCrossover_ResetSubStates(p, 10);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0803dfe0(ShadeManCrossover* p) {
  Boss* boss = &p->base;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 11);
  }
  if (boss->subStateDone) {
    ShadeManCrossover_ResetSubStates(p, 10);
  } else {
    boss->subStateTimer++;
  }
}

// 1 回目で打ち切り, 原典は plttFadeMode の分岐を比較の連鎖で出し値を先にレジスタへ置く, FUN_0803f8cc と同じ
NON_MATCH void FUN_0803e058(ShadeManCrossover* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  boss->canDie = 1;
  if (Boss_EnterSubState(boss) == TRUE) {
    Boss_RequestState(boss, 4);
    p->unk_2b3 = (Random() >> 8) & 3;
    p->unk_2b2 = p->unk_2d8;
    p->unk_2b4 = TRUE;
    p->plttFadeMode = 3;
    p->plttFadeTo = 11;
    switch (p->plttFadeMode) {
      case 1: {
        p->plttFade = 31;
        break;
      }
      case 0:
      case 2:
      case 3: {
        p->plttFade = 0;
        break;
      }
    }
    p->unk_81e = 0;
    p->unk_2b5 = TRUE;
  }
  if (!boss->subStateDone) {
    s32 radius;
    Mover* mover;
    Vec3 pos;
    s32 height;
    TileAttr attr;
    s32 dy;

    if (boss->curState != 5) {
      boss->subStateTimer++;
      return;
    }
    radius = 400;
    mover = &p->base.mover;
    Vec3_SetPolar(&pos, mover->angle, radius);
    Vec3_Add(&pos, &mover->pos);
    height = TileHeightAt(&pos);
    attr = GetTileAttrAt(&pos);
    dy = height - p->unk_164;
    if (dy >= -0x1FF && dy <= 0xFF && !(attr & TATTR_WALL)) {
      boss->subStateTimer++;
      return;
    }
  }
  if (boss->curState == 4 || boss->curState == 2) {
    Boss_RequestState(boss, 5);
  } else if (boss->curState == 5) {
    if (p->unk_2b2 == 0) {
      if (p->unk_2b5) {
        p->plttFadeMode = 1;
        p->plttFadeTo = 11;
        switch (p->plttFadeMode) {
          case 1: {
            p->plttFade = 31;
            break;
          }
          case 0:
          case 2:
          case 3: {
            p->plttFade = 0;
            break;
          }
        }
        p->unk_81e = 0;
        p->unk_2b5 = FALSE;
      }
      Boss_RequestState(boss, 7);
    } else {
      Vec3 tmp;
      s32 node = Map_FindNearestPathNode(&tmp, &boss->mover.pos, 4);

      if ((u8)Random() < 128) {
        node = node - 2 - (Random() & 1);
      } else {
        node = node + 2 + (Random() & 1);
      }
      Map_GetPathNodePos(&p->unk_294, 4, node & 7);
      p->unk_16c = 32;
      Boss_RequestState(boss, 2);
      p->unk_2b2--;
    }
  } else if (boss->curState == 7) {
    u32 plttIdx;

    p->unk_81e = 0;
    p->plttFade = 0;
    p->plttFadeMode = -1;
    p->plttFadeTo = ShadeManCrossover_GetPlttID(p);
    plttIdx = ShadeManCrossover_GetPlttID(p);
    p->sprite.pltt = plttIdx == 0 ? p->pltt[0] : &gObjPlttData[plttIdx * 16];
    ShadeManCrossover_ResetSubStates(p, 15);
    p->unk_2b4 = 0;
    return;
  }
  boss->subStateTimer++;
#else
  INCFUNC("asm/func/FUN_0803e058.inc");
#endif
}

void FUN_0803e4f4(ShadeManCrossover* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 12);
    FUN_08235408(&p->unk_29c, &boss->mover.pos, 4, 0x100);
  }
  if (boss->subStateDone) {
    ShadeManCrossover_ResetSubStates(p, 10);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0803e578(ShadeManCrossover* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 13);
  }
  if (!TEST_FLAGS(boss->flags, BOSSFLAG_UNK_0)) {
    Boss_SetSubStates(boss, 0, 0, 12);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0803e5d8(ShadeManCrossover* p) {
  Boss_EnterSubState(&p->base);
  p->base.subStateTimer++;
}

void FUN_0803e5fc(ShadeManCrossover* p) { PTR_ARRAY_085aaf6c[p->base.subState2](p); }

void FUN_0803e618(ShadeManCrossover* p) { PTR_ARRAY_085aafa0[p->base.subState2](p); }

void FUN_0803e634(ShadeManCrossover* p) {
  if (!TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2) && !FUN_0803d844(p)) {
    PTR_ARRAY_085aafa8[p->base.subState1](p);
  }
}

void FUN_0803e670(ShadeManCrossover* p) { PTR_ARRAY_085aafac[p->base.subState1](p); }

void FUN_0803e68c(ShadeManCrossover* p) {
  p->base.unk_9d = 0;
  PTR_ARRAY_085aafb0[p->base.subState0](p);
}

// 1 回目で打ち切り (205/200), 原典は stateRequestCallback の戻り値 0 を sb に残して unk_2c0 に書く
NON_MATCH void FUN_0803e6b0(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  ShadeManCrossover* p = (ShadeManCrossover*)boss;

  Boss_SetAngle(boss, boss->playerAngle[0]);
  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimDir8(boss, &p->sprite, &p->gfx, 0, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  } else {
    Boss_PlayAnimDir8(boss, &p->sprite, &p->gfx, 0, PLAYMODE_LOOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (p->unk_2c0) {
      s32 heal;
      s32 hp;

      FUN_08050e2c(3, 0, &p->sprite.pos);
      heal = Div(boss->maxHP * p->unk_2c0, 16);
      hp = boss->hp;
      Boss_SetHP(boss, hp + heal);
      if (hp != boss->hp) {
        Vec3 ofs;

        VEC3_SET(ofs, Q8(0.063), 0, Q8(0.063));
        CreateDamageNumber(&p->hurtbox, heal, 1, &boss->mover.pos, &ofs, 1);
      }
      p->unk_2c0 = 0;
      PlaySound_0824078c(SONG_884);
    }
    ShadeManCrossover_UpdateUnk160(p, timer);
  }
#else
  INCFUNC("asm/func/FUN_0803e6b0.inc");
#endif
}

void FUN_0803e860(Boss* boss, s32 timer) {
  ShadeManCrossover* p = (ShadeManCrossover*)boss;

  Boss_SetAngle(boss, boss->playerAngle[0]);
  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimDir8(boss, &p->sprite, &p->gfx, 0, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
    FUN_0803c590(p);
    FUN_0803c4d4(p, &p->unk_294, p->unk_16c);
    PlaySound_0824078c(SONG_840);
  } else {
    Boss_PlayAnimDir8(boss, &p->sprite, &p->gfx, 0, PLAYMODE_LOOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    ShadeManCrossover_UpdateUnk160(p, timer);
    if (p->unk_824 > 3) {
      if (p->unk_2b4 == 1 && boss->subState2 == 11) {
        FUN_0803c78c(p, 1, 0);
      } else {
        FUN_0803c78c(p, 0, 0);
      }
    }
    if (p->unk_288 < p->unk_28a) {
      FUN_0803c5d0(p);
      FUN_0803c660(p);
    } else {
      boss->subStateDone = TRUE;
    }
  }
}

void FUN_0803e9f4(Boss* boss, s32 timer) {
  ShadeManCrossover* p = (ShadeManCrossover*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite, &p->gfx, 11, PLAYMODE_ONCE_AND_STOP, 2, MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(SE_843);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (p->sprite.animCmdIdx == 3 || p->sprite.animCmdIdx == 4) {
      SET_FLAGS(boss->flags, BOSSFLAG_HITBOX2);
    }
    if (p->sprite.animEvents & MAIN_ANIM_EVENT_ENDED) {
      boss->subStateDone = TRUE;
    }
  }
}

void FUN_0803ea98(Boss* boss, s32 timer) {
  ShadeManCrossover* p = (ShadeManCrossover*)boss;
  Mover* mover = &boss->mover;

  Boss_SetAngle(boss, boss->playerAngle[0]);
  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite, &p->gfx, 19, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
  } else {
    Boss_PlayAnimFacing(boss, &p->sprite, &p->gfx, 19, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX);
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (timer < 64) {
      Vec3_SetPolar(&mover->delta, mover->angle, -((64 - timer) >> 3));
    }
    if (timer > 63) {
      boss->subStateDone = TRUE;
    }
  }
}

void FUN_0803ebc4(Boss* boss, s32 timer) {
  ShadeManCrossover* p = (ShadeManCrossover*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite, &p->gfx, 9, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(SE_842);
  }
  if (boss->subState2 == 11) {
    SET_FLAGS(boss->flags, BOSSFLAG_UNK_22);
  } else {
    SET_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (p->unk_2b4 == 1) {
      Vec3_SetPolar(&mover->delta, mover->angle, p->unk_2da);
    } else {
      Vec3_SetPolar(&mover->delta, mover->angle, 40);
    }
    if (p->unk_824 > 3) {
      if (p->unk_2b4 == 1) {
        FUN_0803c78c(p, 1, 0);
      } else {
        FUN_0803c78c(p, 0, 0);
      }
    }
    if (timer > 159) {
      boss->subStateDone = TRUE;
    }
  }
}

void FUN_0803ed40(Boss* boss, s32 timer) {
  ShadeManCrossover* p = (ShadeManCrossover*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite, &p->gfx, 11, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(SE_843);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (p->sprite.animCmdIdx == 3 || p->sprite.animCmdIdx == 4) {
      SET_FLAGS(boss->flags, BOSSFLAG_HITBOX2);
    }
    if (timer < 10) {
      Vec3_SetPolar(&boss->mover.delta, mover->angle, (10 - timer) * 4);
    }
    if ((p->sprite.animEvents & MAIN_ANIM_EVENT_ENDED) && timer > 59) {
      boss->subStateDone = TRUE;
    }
  }
}

void FUN_0803ee50(Boss* boss, s32 timer) {
  ShadeManCrossover* p = (ShadeManCrossover*)boss;
  Mover* mover = &boss->mover;
  MainSprite* sprite = &p->sprite;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    boss->dir = Angle_ToDir8(Angle_FromDir4(Angle_ToDir4(mover->angle)));
    Boss_PlayAnimFacing(boss, sprite, &p->gfx, 21, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (timer < 20) {
      Vec3_SetPolar(&boss->mover.delta, mover->angle, 20 - timer);
    }
    if (timer < 20 && p->unk_824 > 3) {
      if (p->unk_2b4 == 1) {
        FUN_0803c78c(p, 1, 0);
      } else {
        FUN_0803c78c(p, 0, 0);
      }
    }
    if (timer > 69) {
      boss->subStateDone = TRUE;
    }
  }
}

// 残差は向きを左右に寄せるところ (391/390), 原典は両方の分岐で 0xFF を作ってから facing の格納を合流させる, FUN_0803fc70 も同じ
NON_MATCH void FUN_0803ef80(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  ShadeManCrossover* p = (ShadeManCrossover*)boss;
  MainSprite* sprite = &p->sprite;

  if (boss->stateEntered) {
    s32 i;

    boss->stateEntered = FALSE;
    if (boss->facing > 1) {
      boss->mover.angle = 0x40;
      boss->facing = 2;
    } else {
      boss->mover.angle = 0;
      boss->facing = 1;
    }
    boss->dir = Angle_ToDir8(boss->mover.angle);
    Boss_PlayAnimFlip(boss, sprite, &p->gfx, 16, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
    p->phaseTimer = 0;
    p->unk_2b8 = 0;
    p->unk_2b9 = 5;
    if ((u8)Random() < 128) {
      for (i = 0; i < 2; i++) {
        p->unk_2bc[i] = i * 2;
      }
    } else {
      for (i = 0; i < 2; i++) {
        p->unk_2bc[i] = i * 2 + 1;
      }
    }
  }
  if (boss->damageCallback(boss) || boss->stateRequestCallback(boss)) {
    return;
  }
  ShadeManCrossover_UpdateUnk160(p, timer);
  switch (p->phase) {
    case 0: {
      if (sprite->animCmdIdx == 4) {
        sprite->animCmdTimer = 0;
      }
      if (p->phaseTimer == 18) {
        PlaySound_0824078c(SONG_862);
      }
      if (p->phaseTimer == 30 || p->phaseTimer == 50) {
        Vec3 pos;
        Vec3* target;
        u32 angle;
        s32 power;

        Map_GetPathNodePos(&pos, p->unk_2b9, p->unk_2bc[p->unk_2b8]);
        pos.y = TileHeightAt(&pos);
        target = boss->playerPos[0];
        angle = ArcTan2_8(target->x - pos.x, target->z - pos.z);
        power = p->unk_2de;
        if (p->unk_2b6) {
          power = (p->unk_2c6 * power) >> 6;
        }
        FUN_0805eee4(p->entity0805ee80, angle, p->unk_2e4, power, p->unk_2e0, p->unk_2e2, p->unk_2e6, p->unk_2e8, p->unk_2ea, &pos);
        p->unk_2b8++;
      }
      if (++p->phaseTimer > 79) {
        Boss_PlayAnimFlip(boss, sprite, &p->gfx, 16, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_KEEP_FRAME | MAIN_ANIM_REVERSE);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 1: {
      if (sprite->animEvents & MAIN_ANIM_EVENT_ENDED) {
        boss->subStateDone = TRUE;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0803ef80.inc");
#endif
}

// 1 回目で打ち切り (333/332), unk_162 を増やすところからレジスタがずれる
NON_MATCH void FUN_0803f2f4(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  ShadeManCrossover* p = (ShadeManCrossover*)boss;
  Mover* mover = &boss->mover;
  MainSprite* sprite = &p->sprite;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->playerAngle[0]);
    Boss_PlayAnimFacing(boss, sprite, &p->gfx, 14, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
    p->phaseTimer = 0;
  }
  if (boss->damageCallback(boss) || boss->stateRequestCallback(boss)) {
    return;
  }
  ShadeManCrossover_UpdateUnk160(p, timer);
  switch (p->phase) {
    case 0: {
      if (sprite->animCmdIdx == 7 && sprite->animCmdTimer == 1) {
        PlaySound_0824078c(SONG_862);
      }
      ShadeManCrossover_SetShake(p, 8);
      if (sprite->animEvents & MAIN_ANIM_EVENT_ENDED) {
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 1: {
      ShadeManCrossover_SetShake(p, 8);
      if (++p->phaseTimer > 29) {
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 2: {
      if (p->phaseTimer == 0 || p->phaseTimer == 16 || p->phaseTimer == 32) {
        Vec3 pos;
        u32 angle;
        s32 power;

        Vec3_CopyOffsetY(&pos, &mover->pos, 0x100);
        angle = boss->playerAngle[0] - 16 + p->phaseTimer;
        power = p->unk_2ec;
        if (p->unk_2b6) {
          power = (p->unk_2c6 * power) >> 6;
        }
        FUN_0805ef68(p->entity0805ee80, angle, p->unk_2f2, power, p->unk_2ee, p->unk_2f0, p->unk_2f4, p->unk_2f6, &pos);
        ShadeManCrossover_SetShake(p, 4);
      }
      if (++p->phaseTimer > 127) {
        p->phase++;
        p->phaseTimer = 0;
        Boss_PlayAnimFacing(boss, sprite, &p->gfx, 23, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
      }
      break;
    }
    case 3: {
      if (sprite->animEvents & MAIN_ANIM_EVENT_ENDED) {
        boss->subStateDone = TRUE;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0803f2f4.inc");
#endif
}

// 1 回目で打ち切り (364/363), 退避枠が 1 つ多く boss と timer のレジスタが入れ替わる
NON_MATCH void FUN_0803f5b8(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  ShadeManCrossover* p = (ShadeManCrossover*)boss;
  Mover* mover = &boss->mover;
  MainSprite* sprite = &p->sprite;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->playerAngle[0]);
    Boss_PlayAnimFacing(boss, sprite, &p->gfx, 14, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
    p->phaseTimer = 0;
  }
  if (boss->damageCallback(boss) || boss->stateRequestCallback(boss)) {
    return;
  }
  ShadeManCrossover_UpdateUnk160(p, timer);
  switch (p->phase) {
    case 0: {
      if (sprite->animCmdIdx == 7 && sprite->animCmdTimer == 1) {
        PlaySound_0824078c(SONG_862);
      }
      if (++p->phaseTimer == 30) {
        Vec3 pos;
        s32 power;

        Vec3_CopyOffsetY(&pos, &mover->pos, 0xF0);
        power = p->unk_2f8;
        if (p->unk_2b6) {
          power = (p->unk_2c6 * power) >> 6;
        }
        FUN_0805e6bc(p->entity0805e67c, &pos, mover->angle - ((Random() & 3) + 10), p->unk_2fe + 2, power, p->unk_2fa, p->unk_2fc);
        FUN_0805e6bc(p->entity0805e67c, &pos, (Random() & 3) + mover->angle, p->unk_2fe, power, p->unk_2fa, p->unk_2fc);
        FUN_0805e6bc(p->entity0805e67c, &pos, (Random() & 3) + 10 + mover->angle, p->unk_2fe + 2, power, p->unk_2fa, p->unk_2fc);
        PlaySound_0824078c(SONG_234);
      }
      if (sprite->animEvents & MAIN_ANIM_EVENT_ENDED) {
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 1: {
      if (++p->phaseTimer > 31) {
        p->phase++;
        p->phaseTimer = 0;
        Boss_PlayAnimFacing(boss, sprite, &p->gfx, 23, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
      }
      break;
    }
    case 2: {
      if (sprite->animEvents & MAIN_ANIM_EVENT_ENDED) {
        boss->subStateDone = TRUE;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0803f5b8.inc");
#endif
}

// 1 回目で打ち切り (387/407), 原典は plttFadeMode の分岐を比較の連鎖で出し 2 と 11 を先にレジスタへ置く
NON_MATCH void FUN_0803f8cc(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  ShadeManCrossover* p = (ShadeManCrossover*)boss;
  Mover* mover = &boss->mover;
  MainSprite* sprite = &p->sprite;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->playerAngle[0]);
    Boss_PlayAnimFacing(boss, sprite, &p->gfx, 14, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
    p->phaseTimer = 0;
    FUN_08050e2c(0, 0, &p->sprite.pos);
    p->plttFadeMode = 2;
    p->plttFadeTo = 11;
    switch (p->plttFadeMode) {
      case 1: {
        p->plttFade = 31;
        break;
      }
      case 0:
      case 2:
      case 3: {
        p->plttFade = 0;
        break;
      }
    }
    p->unk_81e = 0;
  }
  if (boss->damageCallback(boss)) {
    u32 plttIdx;

    p->unk_2b4 = 0;
    p->unk_81e = 0;
    p->plttFade = 0;
    p->plttFadeMode = -1;
    p->plttFadeTo = ShadeManCrossover_GetPlttID(p);
    plttIdx = ShadeManCrossover_GetPlttID(p);
    p->sprite.pltt = plttIdx == 0 ? p->pltt[0] : &gObjPlttData[plttIdx * 16];
    return;
  }
  if (boss->stateRequestCallback(boss)) {
    u32 plttIdx;

    p->unk_2b4 = 0;
    p->unk_81e = 0;
    p->plttFade = 0;
    p->plttFadeMode = -1;
    p->plttFadeTo = ShadeManCrossover_GetPlttID(p);
    plttIdx = ShadeManCrossover_GetPlttID(p);
    p->sprite.pltt = plttIdx == 0 ? p->pltt[0] : &gObjPlttData[plttIdx * 16];
    return;
  }
  ShadeManCrossover_UpdateUnk160(p, timer);
  switch (p->phase) {
    case 0: {
      if (++p->phaseTimer == 20) {
        Vec3 pos;
        s32 power;

        Vec3_CopyOffsetY(&pos, &mover->pos, 0xF0);
        power = p->unk_300 + p->unk_2c1 * p->unk_302;
        if (p->unk_2b6) {
          power = (p->unk_2c6 * power) >> 6;
        }
        FUN_0805e79c(p->entity0805e67c, &pos, mover->angle, p->unk_308, power, p->unk_304, p->unk_306);
        PlaySound_0824078c(SONG_234);
        p->unk_2c1 = 0;
      }
      if (sprite->animEvents & MAIN_ANIM_EVENT_ENDED) {
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 1: {
      if (++p->phaseTimer > 199) {
        p->phase++;
        p->phaseTimer = 0;
        Boss_PlayAnimFacing(boss, sprite, &p->gfx, 23, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
      }
      break;
    }
    case 2: {
      if (sprite->animEvents & MAIN_ANIM_EVENT_ENDED) {
        boss->subStateDone = TRUE;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0803f8cc.inc");
#endif
}

// 1 回目で打ち切り (313/310), 原典は向きの計算の 0xFF と 7 をレジスタに残して使い回す
NON_MATCH void FUN_0803fc70(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  ShadeManCrossover* p = (ShadeManCrossover*)boss;
  Mover* mover = &boss->mover;
  MainSprite* sprite = &p->sprite;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->playerAngle[0]);
    if (boss->facing > 1) {
      mover->angle = 0x40;
      boss->facing = 2;
    } else {
      mover->angle = 0;
      boss->facing = 1;
    }
    boss->dir = Angle_ToDir8(mover->angle);
    Boss_PlayAnimFlip(boss, sprite, &p->gfx, 16, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    MainSprite_SetAnimFrame(sprite, &p->gfx, boss->animID, 6);
    p->phase = 0;
    p->phaseTimer = 0;
    PlaySound_0824078c(SONG_863);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
  p->damage = 0;
  p->unk_166 = 0;
  p->hurtWeakness = 0;
  p->hurtAttributes = 0;
  if (boss->stateRequestCallback(boss)) {
    return;
  }
  ShadeManCrossover_UpdateUnk160(p, timer);
  switch (p->phase) {
    case 0: {
      p->phaseTimer++;
      if (sprite->animCmdIdx > 2) {
        SET_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX);
      }
      if (sprite->animEvents & MAIN_ANIM_EVENT_ENDED) {
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 1: {
      SET_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX | BOSSFLAG_HIDDEN);
      if (++p->phaseTimer == 15) {
        mover->pos = p->unk_29c;
      }
      if (p->phaseTimer > 29) {
        Boss_SetAngle(boss, boss->playerAngle[0]);
        Boss_PlayAnimFlip(boss, sprite, &p->gfx, 16, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_REVERSE | MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnimSpeed(sprite, 0x40);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 2: {
      if (sprite->animCmdIdx <= 2) {
        SET_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX);
      }
      if (sprite->animCmdIdx == 6) {
        boss->subStateDone = TRUE;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0803fc70.inc");
#endif
}

void FUN_0803fef0(Boss* boss, s32 timer) {
  ShadeManCrossover* p = (ShadeManCrossover*)boss;
  Mover* mover = &boss->mover;
  MainSprite* sprite = &p->sprite;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, sprite, &p->gfx, 5, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    p->phase = 0;
    p->phaseTimer = 0;
  }
  p->damage = 0;
  p->unk_166 = 0;
  p->hurtWeakness = 0;
  p->hurtAttributes = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (timer < 10) {
    Vec3_SetPolar(&boss->mover.delta, mover->angle, (10 - timer) * 2);
  }
  switch (p->phase) {
    case 0: {
      ShadeManCrossover_SetShake(p, 8);
      if (sprite->animEvents & MAIN_ANIM_EVENT_ENDED) {
        Boss_PlayAnimFacing(boss, sprite, &p->gfx, 7, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 1: {
      if (sprite->animEvents & MAIN_ANIM_EVENT_ENDED) {
        Boss_PlayAnimDir8(boss, sprite, &p->gfx, 0, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
        p->phase++;
        p->phaseTimer = 0;
      }
      break;
    }
    case 2: {
      if (++p->phaseTimer > 14) {
        Boss_SetState(boss, FUN_0803fc70, 12);
      }
      break;
    }
  }
}

void FUN_080400a4(Boss* boss, s32 timer) {
  ShadeManCrossover* p = (ShadeManCrossover*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite, &p->gfx, 5, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    FUN_08022fb8(boss, &p->sprite.pos);
    p->phase = 0;
    p->phaseTimer = 0;
    FUN_08050e50(0, 1);
    FUN_08050d28();
  }
  if (p->unk_162 > 3) {
    p->unk_162 -= 4;
  } else {
    p->unk_162 = 0;
  }
  if (p->unk_160 > 3) {
    p->unk_160 -= 4;
  } else {
    p->unk_160 = 0;
  }
  p->damage = 0;
  p->unk_166 = 0;
  p->hurtWeakness = 0;
  p->hurtAttributes = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (++p->phaseTimer == 128) {
    FUN_08023024(boss, &p->sprite.pos);
  }
}

void FUN_08040184(ShadeManCrossover* p) {
  if (!TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    p->base.subStateDone = FALSE;
    Boss_UpdateState(&p->base);
  }
}

s32 FUN_080401a8(ShadeManCrossover* p) {
  if (p->base.state == 0 || p->base.state > 15) {
    return FALSE;
  } else {
    Boss_SetState(&p->base, PTR_ARRAY_085aafb8[p->base.state], p->base.state);
    return TRUE;
  }
}

// 1 回目で打ち切り (327/322), 原典は unk_2b5 のときの戻し処理を 2 か所で同じ形に出す
s32 ShadeManCrossover_HandleDamage(ShadeManCrossover* p) {
  u16 unk_166;
  Boss* boss = &p->base;
  Mover* mover = &boss->mover;
  HitboxData* hurtbox = &p->hurtbox;
  s32 damage = (s16)p->damage;
  u32 weakness;
  HitboxAttributes attributes;

  unk_166 = p->unk_166;
  weakness = p->hurtWeakness;
  attributes = p->hurtAttributes;
  p->damage = 0;
  p->unk_166 = 0;
  p->hurtWeakness = 0;
  p->hurtAttributes = 0;
  if (!FUN_08050e80()) {
    damage = 0;
  }
  if (damage > 0) {
    Vec3 ofs;

    boss->hp -= damage;
    p->unk_2a4 = boss->mover.pos;
    if (unk_166 && (weakness & 7)) {
      FUN_08050cb8(&p->unk_2a4, 0);
    }
    if (attributes & 0x7F) {
      if (weakness & 1) {
        FUN_08050cb8(&p->unk_2a4, 1);
      } else if (weakness & 2) {
        FUN_08050cb8(&p->unk_2a4, 2);
      } else if (weakness & 4) {
        FUN_08050cb8(&p->unk_2a4, 3);
      }
    }
    if (attributes & 1) {
      FUN_0803ca40(&p->unk_2a4);
    }
    p->unk_172 = 20;
    p->unk_170 = 10;
    p->sprite.pltt = p->pltt[0];
    VEC3_SET(ofs, Q8(0.063), 0, Q8(0.063));
    CreateDamageNumber(hurtbox, damage, 0, &mover->pos, &ofs, 1);
    if (boss->hp <= 0) {
      boss->hp = 0;
      SET_FLAGS(boss->flags, BOSSFLAG_UNK_1);
      Boss_SetState(boss, FUN_080400a4, 14);
      PlaySound_0824078c(SONG_973);
      if (p->unk_2b5) {
        u32 plttIdx;

        p->unk_2b4 = 0;
        p->unk_81e = 0;
        p->plttFade = 0;
        p->plttFadeMode = 0xFF;
        p->plttFadeTo = ShadeManCrossover_GetPlttID(p);
        plttIdx = ShadeManCrossover_GetPlttID(p);
        p->sprite.pltt = plttIdx == 0 ? p->pltt[0] : &gObjPlttData[plttIdx * 16];
        p->unk_2b5 = 0;
      }
      return TRUE;
    }
    ShadeManCrossover_SetShake(p, 8);
    if (unk_166 && (weakness & 7)) {
      SET_FLAGS(boss->flags, BOSSFLAG_UNK_0);
      Boss_SetState(boss, FUN_0803fef0, 13);
      if (p->unk_2b5) {
        u32 plttIdx;

        p->unk_2b4 = 0;
        p->unk_81e = 0;
        p->plttFade = 0;
        p->plttFadeMode = 0xFF;
        p->plttFadeTo = ShadeManCrossover_GetPlttID(p);
        plttIdx = ShadeManCrossover_GetPlttID(p);
        p->sprite.pltt = plttIdx == 0 ? p->pltt[0] : &gObjPlttData[plttIdx * 16];
        p->unk_2b5 = 0;
      }
      PlaySound_0824078c(SONG_866);
      return TRUE;
    }
    PlaySound_0824078c(SE_ENEMY_DAMAGED);
  }
  return FALSE;
}

s32 ShadeManCrossover_Update(ShadeManCrossover* p) {
  FUN_0803cee4(p);
  FUN_0803e68c(p);
  FUN_08040184(p);
  FUN_0803d0a4(p);
  return 0;
}

s32 ShadeManCrossover_Destroy(ShadeManCrossover* p) {
  AuxShadow_Remove(&p->shadow);
  ShadeManCrossover_UnregisterHurtbox(p);
  ShadeManCrossover_RemoveSprites(p);
  MainSprite_Remove(&p->sprite);
  Boss_Destroy(&p->base);
  return 0;
}

// 1 回目で打ち切り (833/839), 原典は bossID をレジスタに残し退避枠の並びが違う
NON_MATCH s32 ShadeManCrossover_Init(ShadeManCrossover* p, u32 id) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  BossID bossID = VM_GetNamedArgValue('t', BOSS_SHADEMAN_CROSSOVER);
  MainSpriteGfxFile* f;
  Vec3 pos;
  u32 angle;
  s32 hp;
  u32 plttIdx;

  Boss_Register(boss, bossID);
  if (gPlayerPtr[0] != NULL) {
    boss->players[0] = gPlayerPtr[0];
    boss->playerPos[0] = &gPlayerPtr[0]->mover.pos;
  } else {
    boss->players[0] = NULL;
    boss->playerPos[0] = NULL;
  }
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_SHADEMAN);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx, f);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    angle = VM_GetValue();
  } else {
    VEC3_SET(pos, gStat->playerX, gStat->playerY, gStat->playerZ);
    angle = 0x40;
  }
  p->unk_164 = pos.y;
  if (VM_SeekToNamedArg('r')) {
    p->centerPos.x = VM_GetValue();
    p->centerPos.y = VM_GetValue();
    p->centerPos.z = VM_GetValue();
  } else {
    p->centerPos.x = gStat->playerX;
    p->centerPos.y = gStat->playerY;
    p->centerPos.z = gStat->playerZ;
  }
  FUN_0803c590(p);
  if (VM_SeekToNamedArg('s')) {
    hp = VM_GetValue();
    p->hurtboxPower = VM_GetValue();
  } else {
    hp = 1000;
    p->hurtboxPower = 100;
  }
  p->unk_30e = 0x40;
  p->unk_16c = 0x40;
  p->unk_2c6 = VM_GetNamedArgValue('M', 128);
  if (VM_SeekToNamedArg('a')) {
    p->hitboxPower = VM_GetValue();
    p->hitboxKnockback = VM_GetValue();
    p->hitboxUnk44 = VM_GetValue();
    p->hitbox2Power = VM_GetValue();
    p->hitbox2Knockback = VM_GetValue();
    p->hitbox2Unk44 = VM_GetValue();
    p->unk_2d4 = VM_GetValue();
    p->unk_2d6 = VM_GetValue();
    p->unk_2dc = VM_GetValue();
    p->unk_2d8 = VM_GetValue();
    p->unk_2da = VM_GetValue();
  } else {
    p->hitboxPower = 50;
    p->hitboxKnockback = 50;
    p->hitboxUnk44 = 15;
    p->hitbox2Power = 90;
    p->hitbox2Knockback = 50;
    p->hitbox2Unk44 = 60;
    p->unk_2d4 = 100;
    p->unk_2d6 = 80;
    p->unk_2dc = 60;
    p->unk_2d8 = 4;
    p->unk_2da = 45;
  }
  if (VM_SeekToNamedArg('S')) {
    p->unk_2de = VM_GetValue();
    p->unk_2e0 = VM_GetValue();
    p->unk_2e2 = VM_GetValue();
    p->unk_2e4 = VM_GetValue();
    p->unk_2e6 = VM_GetValue();
    p->unk_2e8 = VM_GetValue();
    p->unk_2ea = VM_GetValue();
    p->unk_2ec = VM_GetValue();
    p->unk_2ee = VM_GetValue();
    p->unk_2f0 = VM_GetValue();
    p->unk_2f2 = VM_GetValue();
    p->unk_2f4 = VM_GetValue();
    p->unk_2f6 = VM_GetValue();
  } else {
    p->unk_2de = 80;
    p->unk_2e0 = 60;
    p->unk_2e2 = 60;
    p->unk_2e4 = 20;
    p->unk_2e6 = 15;
    p->unk_2e8 = 1;
    p->unk_2ea = 1;
    p->unk_2ec = 90;
    p->unk_2ee = 60;
    p->unk_2f0 = 60;
    p->unk_2f2 = 25;
    p->unk_2f4 = 0;
    p->unk_2f6 = 4;
  }
  if (VM_SeekToNamedArg('B')) {
    p->unk_2f8 = VM_GetValue();
    p->unk_2fa = VM_GetValue();
    p->unk_2fc = VM_GetValue();
    p->unk_2fe = VM_GetValue();
    p->unk_300 = VM_GetValue();
    p->unk_304 = VM_GetValue();
    p->unk_306 = VM_GetValue();
    p->unk_308 = VM_GetValue();
    p->unk_302 = VM_GetValue();
  } else {
    p->unk_2f8 = 70;
    p->unk_2fa = 30;
    p->unk_2fc = 8;
    p->unk_2fe = 24;
    p->unk_300 = 60;
    p->unk_304 = 30;
    p->unk_306 = 8;
    p->unk_308 = 32;
    p->unk_302 = 15;
  }
  if (VM_SeekToNamedArg('C')) {
    p->unk_310 = VM_GetValue();
    p->unk_311 = VM_GetValue();
  } else {
    p->unk_310 = 2;
    p->unk_311 = 2;
  }
  p->scriptID = VM_GetNamedArgValue('o', 0);
  p->scriptID2 = VM_GetNamedArgValue('k', 0);
  p->scriptArgUsed = 0;
  p->scriptArgCount = 0;
  if (VM_SeekToNamedArg('O')) {
    s32 i;

    for (i = 0; i < 4 && VM_GetPC() != NULL; i++) {
      p->scriptArgs[i] = VM_GetValue();
      p->scriptArgCount++;
    }
  }
  p->unk_30a = 0x200;
  p->unk_30c = 0x400;
  Boss_Init(boss, id, bossID, &pos, angle);
  p->unk_160 = boss->isDemo ? 0 : 0x40;
  MainSprite_Add(&p->sprite, &p->gfx, 0, 0, 2, PLAYMODE_PAUSE, 60, &pos);
  Boss_PlayAnimDir8(boss, &p->sprite, &p->gfx, 0, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  ShadeManCrossover_ResetSubStates(p, 120);
  Boss_SetState(boss, FUN_0803e6b0, 1);
  boss->damageCallback = (BossCheckFunc)ShadeManCrossover_HandleDamage;
  boss->stateRequestCallback = (BossCheckFunc)FUN_080401a8;
  Boss_InitHP(boss, hp, hp, p->hurtboxPower);
  ShadeManCrossover_InitHitbox(p);
  ShadeManCrossover_InitHurtbox(p, p->hurtboxPower);
  ShadeManCrossover_InitHitbox2(p);
  if (VM_SeekToNamedArg('c')) {
    u32 scriptA = VM_GetValue();
    u32 scriptB = VM_GetValue();

    FUN_08022fac(boss, scriptA, scriptB);
  } else {
    FUN_08022fac(boss, 0, 0);
  }
  if (VM_SeekToNamedArg('A')) {
    s32 i;

    for (i = 0; i < 4 && VM_GetPC() != NULL; i++) {
      boss->unk_e8[i] = VM_GetValue();
    }
  }
  FUN_0803ce8c(p);
  AuxShadow_Init(&p->shadow, &p->sprite.pos, 0x40, 0x40, 0x40, 0x40, 0x1900, 1, 6, 1, 0);
  AuxShadow_SetSprite(&p->shadow, SPRITE_EFF_1C1B, 7);
  {
    rgb555* src = &gObjPlttData[0x132 * 16];
    s32 i;

    for (i = 0; i < 16; i++) {
      CpuCopy32(src, p->pltt[i], sizeof(p->pltt[i]));
    }
  }
  {
    rgb555* src = &gObjPlttData[ShadeManCrossover_GetPlttID(p) * 16];
    s32 i;

    for (i = 0; i < 16; i++) {
      CpuCopy32(src, p->pltt_618[i], sizeof(p->pltt_618[i]));
      src += 16;
    }
  }
  plttIdx = ShadeManCrossover_GetPlttID(p);
  p->sprite.pltt = plttIdx == 0 ? p->pltt[0] : &gObjPlttData[plttIdx * 16];
  FUN_0803c6f0(p, &p->sprite.pos);
  p->plttFadeMode = -1;
  p->plttFadeTo = 7;
  p->entity0805e67c = Entity0805e67c_Create();
  if (p->entity0805e67c == NULL) {
    return -1;
  }
  p->entity0805ee80 = Entity0805ee80_Create(120);
  if (p->entity0805ee80 == NULL) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/ShadeManCrossover_Init.inc");
#endif
}

// 0x4AB1, HashName("クロスオーバーシェードマン")
ShadeManCrossover* ShadeManCrossover_Create(u32 id) {
  ShadeManCrossover* p = Boss_Get(BOSS_SHADEMAN_CROSSOVER);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(ShadeManCrossover));
  if (p != NULL) {
    SetEntityRoutine(p, ShadeManCrossover_Update, ShadeManCrossover_Destroy);
    if (ShadeManCrossover_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
