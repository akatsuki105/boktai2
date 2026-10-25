#include "boss/duneyrr.h"

#include "boss.h"
#include "camera.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

// ドゥネイル
// 0x2B8 から 5 個並ぶ部品
typedef struct {
  u16 state;          // 0x00, 0..3, 変わると timer が 0 に戻る
  u16 timer;          // 0x02
  Vec3 offset;        // 0x04, sprite.pos は親の sprite.pos にこれを足した位置
  MainSprite sprite;  // 0x0C
} DuneyrrElem;
static_assert(sizeof(DuneyrrElem) == 108);

typedef struct Duneyrr {
  Boss base;                       // 0x000
  u16 height;                      // 0x158, base.mover.pos.y はこれに 0x100 を足した値
  s16 spriteOffsetY;               // 0x15A, sprite.pos.y を base.mover.pos.y からずらす量
  u8 unk_15c[0x15E - 0x15C];       // 0x15C
  u16 unk_15e;                     // 0x15E
  u16 unk_160;                     // 0x160
  u16 unk_162;                     // 0x162
  u8 quadrant;                     // 0x164, 部屋を x=0x680, z=0x780 で4分割した区画
  u8 playerQuadrant;               // 0x165, プレイヤーのいる区画
  u8 hurtAngle;                    // 0x166, 攻撃してきた相手の方向
  u8 unk_167;                      // 0x167
  u16 elemsActive;                 // 0x168, elems のスプライトを出している間 1
  u16 unk_16a;                     // 0x16A
  u16 invincibleTimer;             // 0x16C, 0 でない間は hurtbox を隠す
  u8 unk_16e;                      // 0x16E
  u8 unk_16f;                      // 0x16F
  u8 unk_170;                      // 0x170, 0..3, 部屋のどの壁沿いに進むか
  u8 unk_171;                      // 0x171
  u8 unk_172;                      // 0x172
  u8 unk_173;                      // 0x173, 1 か 2 のとき FUN_08024b70 が次の下位状態を決める
  u16 unk_174;                     // 0x174
  u8 unk_176[0x178 - 0x176];       // 0x176
  Vec3 shakeOrigin;                // 0x178, 揺れる前の base.mover.pos
  s32 unk_180;                     // 0x180, unk_188 から unk_190 へ跳ぶ速さ
  s32 unk_184;                     // 0x184, unk_188 から unk_190 へ跳ぶのにかかるフレーム数
  Vec3 unk_188;                    // 0x188, FUN_08023530 を呼んだときの base.mover.pos
  Vec3 unk_190;                    // 0x190, unk_188 から unk_167 の向きに進んだ先を壁沿いに寄せた位置
  HitboxData hitbox;               // 0x198
  HitboxData hurtbox;              // 0x1E8, ハンドラは Duneyrr_OnHurt
  MainSpriteGfx gfx;               // 0x238, SPRITE_DUNEYRR
  MainSprite sprite;               // 0x258
  DuneyrrElem elems[5];            // 0x2B8
  AuxShadow shadow;                // 0x4D4
  s16 damage;                      // 0x540, 最後に受けたダメージ
  s16 unk_542;                     // 0x542, '.j[0]=150'
  s16 unk_544;                     // 0x544, ダメージを受けるたびに減り, 0 以下になると怯む
  s16 unk_546;                     // 0x546, '.j[1]=50', ダメージを受けたとき unk_544 から余分に引く
  s16 flashTimer;                  // 0x548, 0 になったらパレットを 0x223 に戻す
  u8 shakeAmp;                     // 0x54A, sprite.pos をランダムに揺らす幅, 毎フレーム減る
  u8 unk_54b;                      // 0x54B
  u8 unk_54c;                      // 0x54C
  u8 unk_54d;                      // 0x54D
  u8 unk_54e;                      // 0x54E
  u8 unk_54f;                      // 0x54F
  u8 unk_550;                      // 0x550
  u8 unk_551;                      // 0x551
  u8 unk_552;                      // 0x552
  u8 unk_553;                      // 0x553, 下位状態 10 に入るたびに増える, hurtboxPower の次の '.j[2]=3' と比べる
  u8 unk_554;                      // 0x554, lowHP のときに増える, 8 回に1回は下位状態 8 を選ぶ
  u8 unk_555[0x55A - 0x555];       // 0x555
  u16 stateDuration;               // 0x55A, 状態を続ける最短フレーム数
  u16 moveSpeed;                   // 0x55C
  u32 arriveDistSq;                // 0x560, base.targetDistSq がこれ以下になったら止まる
  u32 unk_564;                     // 0x564, 毎フレーム +1
  u8 unk_568[4];                   // 0x568, Entity5DA5 の4つ分, 0 になったときに Entity5DA5_SetState する残りフレーム
  Entity08059a1c* entity08059a1c;  // 0x56C
  rgb555 pltt[16][16];             // 0x570, gObjPlttData の同じ16色を16回写す
  Vec3 homePos;                    // 0x770
  u16 hurtboxPower;                // 0x778, '.s[1]=10'
  u16 hurtboxPower2;               // 0x77A, '.s[2]=0'
  u16 unk_77c;                     // 0x77C, '.j[2]=3', unk_553 がこれ以上になったら下位状態 7 を選ぶ
  s16 hitboxPower;                 // 0x77E, '.a[0]=35'
  s16 hitboxKnockback;             // 0x780, '.a[1]=50'
  s16 hitboxUnk44;                 // 0x782, '.a[2]=60'
  s16 hitboxPower2;                // 0x784, '.a[3]=50'
  s16 hitboxKnockback2;            // 0x786, '.a[4]=240'
  s16 hitboxUnk44_2;               // 0x788, '.a[5]=60'
  s16 dustPower;                   // 0x78A, '.a[6]=13', DustManager_Emit に渡す鱗粉の power
  s16 unk_78c;                     // 0x78C, '.a[7]=35', Entity08059a1c_Create の power
  s16 unk_78e;                     // 0x78E, '.e[0]=30'
  s16 unk_790;                     // 0x790, '.e[1]=0'
  s16 unk_792;                     // 0x792, '.e[2]=28'
  u16 unk_794;                     // 0x794, '.e[3]=1'
  u16 unk_796;                     // 0x796
  u32 unk_798;                     // 0x798, '.e[4]=0'
  s32 weaponExp;                   // 0x79C, '.K'
  u8 unk_7a0[1956 - 0x7A0];        // 0x7A0
} Duneyrr;
static_assert(sizeof(Duneyrr) == 1956);

const s16 s16_ARRAY_085aaabc[4] = {0x40, 0x80, 0xC0, 0x20};  // 0x085AAABC

const s16 s16_ARRAY_085aaac4[4] = {0x40, 0x40, 0x60, 0x20};  // 0x085AAAC4

const u8 u8_ARRAY_085aaacc[4][4][2] = {
    {{0, 2}, {1, 2}, {2, 2}, {3, 2}},
    {{0, 3}, {1, 2}, {2, 3}, {3, 2}},
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 3}, {1, 0}, {2, 3}, {3, 0}},
};  // 0x085AAACC

const u16 u16_ARRAY_085aaaec[5] = {15, 16, 12, 13, 14};  // 0x085AAAEC

const u16 u16_ARRAY_085aaaf6[4][2] = {
    {0x400, 0x500},
    {0x900, 0x500},
    {0x400, 0xA00},
    {0x900, 0xA00}
};  // 0x085AAAF6

s32 FUN_0805fe7c(HitboxData* hitbox, s32 param_2, s32 param_3, Vec3* pos, Vec3* param_5, s32 param_6);
void FUN_08059248(void);
s32 FUN_080591f4(void);
s32 FUN_08059054(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, Vec3* pos);
s32 DustManager_Emit(s32 count, u32 angle, s32 angleRange, u32 speed, s32 speedRange, u32 delay, u32 power, s32 kind, Vec3* pos);
s32 FUN_08059210(void);
s32 FUN_080592a4(void);
unknown* Entity08058ffc_Create(s32 param_1, s32 param_2, s32 param_3);
void FUN_08015ce0(s32 count, u32 kind, u32 flags, u32 animSpeed, u32 angleXZ, u32 angleXZRand, u32 speedXZ, s32 speedXZRand, u32 speedY, s32 speedYRand, WorldPos* pos);
s32 Entity5DA5_SetState(s32 index, s32 state, s32 param_3);
void FUN_08015d3c(WorldPos* pos, u32 kind, u32 flags, u32 animSpeed, u32 speedY, s32 speedYRand, u32 speedXZ, s32 speedXZRand);
void FUN_08015a90(WorldPos* pos, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay);
s32 Entity5DA5_AreAllLit(void);

void Duneyrr_UnregisterHurtbox(Duneyrr*);
void Duneyrr_RemoveElems(Duneyrr*);

void FUN_08024c38(Duneyrr*);
void FUN_08024c84(Duneyrr*);
void FUN_08024cec(Duneyrr*);
void FUN_08024e58(Duneyrr*);
void FUN_08024fe4(Duneyrr*);
void FUN_0802506c(Duneyrr*);
void FUN_08025170(Duneyrr*);
void FUN_080251f0(Duneyrr*);
void FUN_0802523c(Duneyrr*);

void (*const PTR_ARRAY_085aab08[9])(Duneyrr*) = {
    FUN_08024c38,
    FUN_08024c84,
    FUN_08024cec,
    FUN_08024e58,
    FUN_08024fe4,
    FUN_0802506c,
    FUN_08025170,
    FUN_080251f0,
    FUN_0802523c,
};  // 0x085AAB08

void FUN_0802534c(Duneyrr*);
void FUN_080253b8(Duneyrr*);

void (*const PTR_ARRAY_085aab2c[2])(Duneyrr*) = {
    FUN_0802534c,
    FUN_080253b8,
};  // 0x085AAB2C

void FUN_080253dc(Duneyrr*);
void FUN_08025414(Duneyrr*);
void FUN_08025458(Duneyrr*);
void FUN_0802549c(Duneyrr*);
void FUN_08025504(Duneyrr*);

void (*const PTR_ARRAY_085aab34[5])(Duneyrr*) = {
    FUN_080253dc,
    FUN_08025414,
    FUN_08025458,
    FUN_0802549c,
    FUN_08025504,
};  // 0x085AAB34

void FUN_08025568(Duneyrr*);

void (*const PTR_ARRAY_085aab48[1])(Duneyrr*) = {
    FUN_08025568,
};  // 0x085AAB48

void FUN_08025584(Duneyrr*);

void (*const PTR_ARRAY_085aab4c[1])(Duneyrr*) = {
    FUN_08025584,
};  // 0x085AAB4C

void FUN_080255a0(Duneyrr*);

void (*const PTR_ARRAY_085aab50[1])(Duneyrr*) = {
    FUN_080255a0,
};  // 0x085AAB50

void FUN_080255bc(Duneyrr*);
void FUN_080255f8(Duneyrr*);
void FUN_08025614(Duneyrr*);

void (*const PTR_ARRAY_085aab54[3])(Duneyrr*) = {
    FUN_080255bc,
    FUN_080255f8,
    FUN_08025614,
};  // 0x085AAB54

void FUN_08025654(Boss*, s32);
void FUN_080256c4(Boss*, s32);
void FUN_08025830(Boss*, s32);
void FUN_08025948(Boss*, s32);
void FUN_08025c84(Boss*, s32);
void FUN_08025cf8(Boss*, s32);
void FUN_08025e10(Boss*, s32);
void FUN_08025f8c(Boss*, s32);
void FUN_0802604c(Boss*, s32);
void FUN_080261b4(Boss*, s32);
void FUN_080262c0(Boss*, s32);
void FUN_08026334(Boss*, s32);
void FUN_08026514(Boss*, s32);
void FUN_08026738(Boss*, s32);
void FUN_08026968(Boss*, s32);
void FUN_08026c50(Boss*, s32);
void FUN_08027090(Boss*, s32);
void FUN_08027188(Boss*, s32);
void FUN_080271e0(Boss*, s32);
void FUN_08027278(Boss*, s32);
void FUN_0802730c(Boss*, s32);
void FUN_08027454(Boss*, s32);

// clang-format off
void (*const PTR_ARRAY_085aab60[23])(Boss*, s32) = {
    NULL,
    FUN_08025654,
    FUN_080256c4,
    FUN_08025830,
    FUN_08025948,
    FUN_08025c84,
    FUN_08025cf8,
    FUN_08025e10,
    FUN_08025f8c,
    FUN_0802604c,
    FUN_080261b4,
    FUN_080262c0,
    FUN_08026334,
    FUN_08026514,
    FUN_08026738,
    FUN_08026968,
    FUN_08026c50,
    FUN_08027090,
    FUN_08027188,
    FUN_080271e0,
    FUN_08027278,
    FUN_0802730c,
    FUN_08027454,
};  // 0x085AAB60
// clang-format on

void FUN_08024500(Duneyrr*);
void FUN_08025630(Duneyrr*);
void FUN_08027588(Duneyrr*);
void FUN_080245e4(Duneyrr*);

// 下位状態を最初に戻し, その状態を続ける最短フレーム数を決める
static inline void Duneyrr_ResetSubStates(Duneyrr* p, u32 duration) {
  Boss_SetSubStates(&p->base, 0, 0, 0);
  p->stateDuration = duration;
}

static inline void Duneyrr_SetMoveSpeed(Duneyrr* p, u32 speed) { p->moveSpeed = speed; }

static inline void Hitbox_AddAttributes(HitboxData* hitbox, HitboxAttributes attrs) { hitbox->attributes |= attrs; }

static inline void Hitbox_RemoveAttributes(HitboxData* hitbox, HitboxAttributes attrs) { hitbox->attributes &= ~attrs; }

static inline void Hitbox_SetHalfSize(HitboxData* hitbox, Vec3* halfSize) { hitbox->halfSize = *halfSize; }

// 残差はオフセットの定数を作るレジスタの割り当てだけ (原典は r6 を足して4本使う), 2つの表に分けて命令数までは揃った
NON_MATCH void FUN_08023388(Duneyrr* p) {
#ifdef NONMATCHING_C
  u32 animID = p->sprite.unk_12;
  u32 idx = p->sprite.animCmdIdx;
  u32 duration = p->sprite.animCmdDuration;
  u32 t = p->sprite.animCmdTimer;

  if (animID == 0xC144) {
    s32 angle;

    if (duration != 0) {
      idx &= 3;
      angle = s16_ARRAY_085aaabc[idx] + Div(s16_ARRAY_085aaac4[idx] * t, duration);
    } else {
      angle = s16_ARRAY_085aaabc[idx & 3];
    }
    p->spriteOffsetY = POLAR_Z(0x20, angle);
    if (++p->unk_15e >= 36) {
      p->unk_15e = 0;
    }
  } else {
    p->spriteOffsetY = POLAR_Z(0x20, 0x40);
  }
#else
  INCFUNC("asm/func/FUN_08023388.inc");
#endif
}

void Duneyrr_OnHurt(HitboxData* a, HitboxData* b, Duneyrr* p) {
  Boss* boss = &p->base;

  if (TEST_FLAGS(a->flags, HBFLAG_ANGLE)) {
    p->hurtAngle = a->angle;
  } else {
    p->hurtAngle = ArcTan2_8(b->center.x - a->center.x, b->center.z - a->center.z);
  }
  Hitbox_ApplyDamage(a, b);
  p->damage = b->damage;
  a->damage += boss->damageBonus;
  Boss_SetWeaponExpMask(boss, a->weakness);
  Boss_SetHurtAttributes(boss, a->attributes);
}

void FUN_080234d8(void) {}

void Duneyrr_UnregisterHurtbox(Duneyrr* p) { Hitbox_Unregister(&p->hurtbox); }

s32 Duneyrr_GetQuadrant(Vec3* pos) {
  if (pos->z < 0x780) {
    if (pos->x < 0x680) {
      return 0;
    }
    return 1;
  } else {
    if (pos->x < 0x680) {
      return 2;
    }
    return 3;
  }
}

// 残差は dir と表の先頭アドレスを作る順番 (265/266): 原典は表のアドレスを先に載せる, 極座標の部分は entity_08059a1c.c の Vec3_SetPolar と同じ形の static inline にすれば揃う
NON_MATCH void FUN_08023530(Duneyrr* p) {
#ifdef NONMATCHING_C
  Mover* mover = &p->base.mover;
  s32 dir;

  p->unk_188 = mover->pos;
  dir = ((((p->unk_167 + 0x20) & 0xFF) >> 6) + 1) & 3;
  p->unk_170 = u8_ARRAY_085aaacc[Duneyrr_GetQuadrant(&mover->pos)][dir][p->unk_16f];
  p->unk_190.x = POLAR_X(0x1000, p->unk_167);
  p->unk_190.y = 0;
  p->unk_190.z = POLAR_Z(0x1000, p->unk_167);
  Vec3_Add(&p->unk_190, &p->unk_188);
  p->unk_190.y = (p->unk_16f << 9) + 0x400;
  switch (p->unk_170) {
    case 0: {
      if (p->unk_190.x < 0x180) {
        p->unk_190.x = 0x180;
      } else if (p->unk_190.x > 0xB80) {
        p->unk_190.x = 0xB80;
      }
      p->unk_190.z = 0x100;
      break;
    }
    case 1: {
      p->unk_190.x = 0xC00;
      if (p->unk_190.z < 0x180) {
        p->unk_190.z = 0x180;
      } else if (p->unk_190.z > 0xB80) {
        p->unk_190.z = 0xB80;
      }
      break;
    }
    case 2: {
      if (p->unk_190.x < 0x180) {
        p->unk_190.x = 0x180;
      } else if (p->unk_190.x > 0xB80) {
        p->unk_190.x = 0xB80;
      }
      p->unk_190.z = 0xC00;
      break;
    }
    case 3: {
      p->unk_190.x = 0x100;
      if (p->unk_190.z < 0x180) {
        p->unk_190.z = 0x180;
      } else if (p->unk_190.z > 0xB80) {
        p->unk_190.z = 0xB80;
      }
      break;
    }
  }
  if (p->unk_16f == 0) {
    u8 side;

    dir = ((((p->unk_167 + 0x20) & 0xFF) >> 6) + 1) & 3;
    side = u8_ARRAY_085aaacc[Duneyrr_GetQuadrant(&mover->pos)][dir][p->unk_16f + 1];
    switch (p->unk_170) {
      case 0: {
        if (side == 1) {
          p->unk_167 += 0x40;
        } else {
          p->unk_167 -= 0x40;
        }
        break;
      }
      case 1: {
        if (side == 2) {
          p->unk_167 += 0x40;
        } else {
          p->unk_167 -= 0x40;
        }
        break;
      }
      case 2: {
        if (side == 3) {
          p->unk_167 += 0x40;
        } else {
          p->unk_167 -= 0x40;
        }
        break;
      }
      case 3: {
        if (side == 0) {
          p->unk_167 += 0x40;
        } else {
          p->unk_167 -= 0x40;
        }
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_08023530.inc");
#endif
}

void DuneyrrElem_SetState(DuneyrrElem* p, u32 state) {
  p->state = state;
  p->timer = 0;
}

void Duneyrr_InitElems(Duneyrr* p) {
  DuneyrrElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 5; i++, elem++) {
    MainSprite* sprite = &elem->sprite;
    Vec3* offset = &elem->offset;

    CpuFill32(0, offset, sizeof(Vec3));
    MainSprite_Setup(sprite, &p->gfx, 0, SPRFLAG_HIDDEN, 2, 0, 60, &p->sprite.pos);
    MainSprite_SetAnim(sprite, &p->gfx, u16_ARRAY_085aaaec[i], 2, 0);
  }
  p->elemsActive = FALSE;
}

void FUN_08023818(Duneyrr* p) {
  DuneyrrElem* elem = p->elems;
  s32 i;

  for (i = 4; i >= 0; i--, elem++) {
    MainSprite* sprite = &elem->sprite;

    CpuFill32(0, &elem->offset, sizeof(Vec3));
    DuneyrrElem_SetState(elem, 0);
    elem->sprite.pos = p->sprite.pos;
    Vec3_Add(&elem->sprite.pos, &elem->offset);
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
    Video_AddMainSpriteIntoDrawList(sprite, 0);
  }
  p->elemsActive = TRUE;
}

// 残差は乱数で揺らす座標の計算で, 原典は pos.x を ldrh で読んで 0x80 を引いてから足す, 局所の Vec3 を 32bit 単位で書き直す形まで同じ
NON_MATCH void FUN_080238ac(Duneyrr* p, DuneyrrElem* elem, s32 idx) {
#ifdef NONMATCHING_C
  elem->offset.y += 0x30;
  if (idx == 4) {
    elem->offset.x -= 10;
    elem->offset.z += 10;
  } else if (idx == 0) {
    elem->offset.x += 6;
  } else if (idx == 1) {
    elem->offset.x += 10;
  }
  if ((elem->timer & 3) == 0) {
    Vec3 pos = elem->sprite.pos;
    u16* table = gRandomTable;

    pos.x += (_Random(table) & 0xFF) - 0x80;
    pos.y += (_Random(table) & 0x3F) + 0x80;
    pos.z += (_Random(table) & 0xFF) - 0x80;
    FUN_08015d3c(&pos, 5, 0x3000, 0x40, 12, 4, elem->timer & 3, 3);
  }
  if (elem->timer > 10) {
    DuneyrrElem_SetState(elem, 2);
  }
#else
  INCFUNC("asm/func/FUN_080238ac.inc");
#endif
}

// 1 回目で打ち切り
NON_MATCH void FUN_080239bc(Duneyrr* p, DuneyrrElem* elem, s32 idx) {
#ifdef NONMATCHING_C
  if (idx == 4) {
    elem->offset.y += 0x10;
    elem->offset.x -= 10;
    elem->offset.z += 10;
  } else if (idx == 0) {
    elem->offset.y += 0x10;
    elem->offset.x += 6;
  } else if (idx == 1) {
    elem->offset.y += 0x10;
    elem->offset.x += 10;
  }
  if ((elem->timer & 7) == 0) {
    Vec3 pos = elem->sprite.pos;
    u16* table = gRandomTable;

    pos.x = pos.x - 0x80 + (u8)_Random(table);
    pos.y = pos.y + 0x80 + (_Random(table) & 0x3F);
    pos.z = pos.z - 0x80 + (u8)_Random(table);
    FUN_08015d3c(&pos, 5, 0x3000, 0x40, 12, 4, elem->timer & 7, 3);
  }
  if (elem->timer < 20 ? (elem->timer & 3) == 0 : (elem->timer & 1) == 0) {
    elem->sprite.flags |= SPRFLAG_HIDDEN;
  } else {
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
  if (elem->timer > 40) {
    DuneyrrElem_SetState(elem, 3);
    elem->sprite.flags |= SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/FUN_080239bc.inc");
#endif
}

void Duneyrr_UpdateElems(Duneyrr* p) {
  if (p->elemsActive) {
    DuneyrrElem* elem = p->elems;
    s32 i;

    for (i = 0; i < 5; i++, elem++) {
      MainSprite* sprite = &elem->sprite;

      if (elem->state == 1) {
        FUN_080238ac(p, elem, i);
      } else if (elem->state == 2) {
        FUN_080239bc(p, elem, i);
      }
      elem->timer++;
      elem->sprite.pos = p->sprite.pos;
      Vec3_Add(&elem->sprite.pos, &elem->offset);
      MainSprite_AdvanceAnim(sprite, &p->gfx);
    }
  }
}

void Duneyrr_RemoveElems(Duneyrr* p) {
  if (p->elemsActive) {
    DuneyrrElem* elem = p->elems;
    s32 i;

    for (i = 4; i >= 0; i--, elem++) {
      MainSprite_Remove(&elem->sprite);
    }
    p->elemsActive = FALSE;
  }
}

// 1 回目で打ち切り
NON_MATCH void FUN_08023bd8(Duneyrr* p, s32 param_2) {
#ifdef NONMATCHING_C
  if (param_2 == 0) {
    if (p->unk_16a == 0) {
      Vec3 pos = p->sprite.pos;
      u16* table = gRandomTable;

      pos.x = pos.x - 0x80 + (u8)_Random(table);
      pos.y = pos.y + 0x80 + (_Random(table) & 0x3F);
      pos.z = pos.z - 0x80 + (u8)_Random(table);
      FUN_08015d3c(&pos, 5, 0x3000, 0x40, 2, 2, 2, 3);
      p->unk_16a = (Random() & 3) + 2;
    } else {
      p->unk_16a--;
    }
  } else {
    if (p->unk_16a == 0) {
      Vec3 pos = p->sprite.pos;
      u16* table = gRandomTable;

      pos.x = pos.x - 0x80 + (u8)_Random(table);
      pos.y = pos.y + 0x80 + (_Random(table) & 0x3F);
      pos.z = pos.z - 0x80 + (u8)_Random(table);
      FUN_08015d3c(&pos, 5, 0x3000, 0x40, 12, 4, 0, 3);
      p->unk_16a = (Random() & 3) + 1;
    } else {
      p->unk_16a--;
    }
  }
#else
  INCFUNC("asm/func/FUN_08023bd8.inc");
#endif
}

void FUN_08023d7c(Duneyrr* p) {
  if (p->base.subState0 == 0) {
    WorldPos* pos = &p->base.mover.pos;

    if (pos->x < 0x120) {
      pos->x = 0x120;
    } else if (pos->x > 0xBE0) {
      pos->x = 0xBE0;
    }
    if (pos->z < 0x220) {
      pos->z = 0x220;
    } else if (pos->z > 0xCE0) {
      pos->z = 0xCE0;
    }
  }
}

// 部屋を4分割した区画 quadrant の中心の位置を out に入れる
void Duneyrr_GetQuadrantPos(Vec3* out, u32 quadrant, u32 y) {
  out->x = u16_ARRAY_085aaaf6[quadrant][0];
  out->y = y;
  out->z = u16_ARRAY_085aaaf6[quadrant][1];
}

// 残差は乱数オフセットの足し方 (231/228): 原典は pos.x - 0x40 を先に作ってから乱数を足すが, こちらは乱数側に -0x40 を畳む, 乱数を u32/s32 のローカルに受けても揃わない
NON_MATCH void FUN_08023de8(Duneyrr* p) {
#ifdef NONMATCHING_C
  if (p->unk_550 != 0 && FUN_080591f4() < 12) {
    Vec3 pos = p->sprite.pos;

    pos.z -= 0x80;
    pos.x = pos.x - 0x40 + (Random() & 0x7F);
    pos.z = pos.z - 0x40 + (Random() & 0x7F);
    if (TileHeightAt(&pos) == 0x100 && !(GetTileAttrAt(&pos) & TATTR_UNK_0)) {
      FUN_08059054(1, Random() & 3, p->unk_78e, p->unk_790, p->unk_792, &pos);
      p->unk_550--;
    }
  }
#else
  INCFUNC("asm/func/FUN_08023de8.inc");
#endif
}

void Duneyrr_SetHurtboxPower(Duneyrr* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox;

  p->base.hurtboxPower = power;
  hurtbox->power = power;
}

void Duneyrr_SetHitboxAttack(Duneyrr* p, u32 power, u32 knockbackPower, u32 unk_44) {
  HitboxData* hitbox = &p->hitbox;

  hitbox->power = power;
  hitbox->knockbackPower = knockbackPower;
  hitbox->unk_44 = unk_44;
}

void Duneyrr_SetHitboxHalfSize(Duneyrr* p, u32 x, u32 y, u32 z) {
  Vec3 halfSize;

  VEC3_SET(halfSize, x, y, z);
  Hitbox_SetHalfSize(&p->hitbox, &halfSize);
}

void FUN_08024068(Duneyrr* p) {
  Duneyrr_SetHitboxHalfSize(p, 0xA4, 200, 0xA4);
  Duneyrr_SetHitboxAttack(p, p->hitboxPower2, p->hitboxKnockback2, p->hitboxUnk44_2);
  Hitbox_AddAttributes(&p->hitbox, HBATTR_18);
}

void FUN_080240b4(Duneyrr* p) {
  Duneyrr_SetHitboxHalfSize(p, 0x40, 0x81, 0x40);
  Duneyrr_SetHitboxAttack(p, p->hitboxPower, p->hitboxKnockback, p->hitboxUnk44);
  Hitbox_RemoveAttributes(&p->hitbox, HBATTR_18);
}

void FUN_08024100(WorldPos* pos) {
  Vec3 size;
  u16* table;
  s32 angle;
  s32 speed;
  s32 velY;

  VEC3_SET(size, 0xA4, 0x10, 0xA4);
  table = gRandomTable;
  angle = (u8)_Random(table);
  speed = (_Random(table) & 3) + 2;
  velY = (_Random(table) & 3) + 20;
  EmitSmoke(pos, 3, &size, angle, speed, velY, 2, 2);
  angle = (u8)_Random(table);
  speed = (_Random(table) & 3) + 2;
  velY = (_Random(table) & 3) + 20;
  EmitSmoke(pos, 3, &size, angle, speed, velY, 2, 2);
}

void Duneyrr_InitHitbox(Duneyrr* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 0x40, 0x81, 0x40);
  VEC3_SET(offset, 0, 0x80, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_080234d8, p);
  Hitbox_SetAttack(hitbox, p->hitboxPower, p->hitboxKnockback, 0, 0, p->hitboxUnk44);
}

void Duneyrr_InitHurtbox(Duneyrr* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 0xA4, 0x80, 0xA4);
  VEC3_SET(offset, 0, 0x80, 0);
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &p->sprite.pos, 0);
  Hitbox_SetHandler(hurtbox, Duneyrr_OnHurt, p);
  Hitbox_SetPowerAndAttributes(hurtbox, power, HBATTR_IMMORTAL | HBATTR_CLOUD, HBATTR_EARTH);
  Hitbox_Register(hurtbox);
}

void FUN_08024324(Duneyrr* p) {
  p->unk_54c = 1;
  p->unk_54d = 0;
  p->unk_54e = 0;
  p->unk_54f = 0;
}

// 溜まったメッセージを受け取り, cmd ごとに下位状態や位置を切り替える
// 残差は gMsgBus のプール定数の扱いのみ (178/179): 原典はループ内で読み直すが, こちらは r2 に載せて使い回す, Camera_PollMessages と同じ壁
NON_MATCH void Duneyrr_PollMessages(Duneyrr* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  MsgQueue* queue = &boss->msgQueue;
  s32 i;

  for (i = 0; i < queue->count[gMsgBus->bufIdx]; i++) {
    MsgPacket* msg = queue->msgs[gMsgBus->bufIdx][i];

    MsgQueue_BeginWait(queue, msg);
    switch (msg->cmd) {
      case 0: {
        Boss_SetSubStates(boss, 2, 0, 0);
        break;
      }
      case 2: {
        boss->unk_114 = ((u8)msg->args[0] + 5) * 32;
        Boss_SetSubStates(boss, 2, 0, 1);
        break;
      }
      case 1: {
        boss->mover.pos.x = msg->args[0];
        boss->mover.pos.y = msg->args[1] + p->height;
        boss->mover.pos.z = msg->args[2];
        p->sprite.pos.x = boss->mover.pos.x;
        p->sprite.pos.y = boss->mover.pos.y + p->spriteOffsetY;
        p->sprite.pos.z = boss->mover.pos.z;
        MsgQueue_EndWait(&boss->msgQueue, 1);
        break;
      }
      case 7: {
        Boss_SetSubStates(boss, 2, 0, 3);
        break;
      }
      case 8: {
        Boss_SetSubStates(boss, 2, 0, 4);
        break;
      }
      case 9: {
        Boss_ShowEmote(boss, msg->args[0], 180, 180);
        MsgQueue_EndWait(&boss->msgQueue, 1);
        break;
      }
      case 10: {
        Boss_SetSubStates(boss, 2, 0, 2);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/Duneyrr_PollMessages.inc");
#endif
}

void FUN_08024500(Duneyrr* p) {
  Mover* mover = &p->base.mover;
  Vec3** playerPos;

  Duneyrr_PollMessages(p);
  Mover_ApplyMove(mover);
  FUN_08023d7c(p);
  Boss_AdvanceAnim(&p->base, &p->sprite, &p->gfx);
  FUN_08023388(p);
  mover->pos.y = p->height + 0x100;
  p->sprite.pos.x = mover->pos.x;
  p->sprite.pos.y = mover->pos.y + p->spriteOffsetY;
  p->sprite.pos.z = mover->pos.z;
  FUN_08022e20(&p->base);
  playerPos = p->base.playerPos;
  if (*playerPos != NULL) {
    s32 dx = (*playerPos)->x - mover->pos.x;
    s32 dz = (*playerPos)->z - mover->pos.z;

    p->base.playerAngle[0] = ArcTan2_8(dx, dz);
    p->base.playerDistSq[0] = dx * dx + dz * dz;
  }
  Duneyrr_UpdateElems(p);
  p->quadrant = Duneyrr_GetQuadrant(&mover->pos);
  p->playerQuadrant = Duneyrr_GetQuadrant(*playerPos);
}

// 残差は影の表示切り替えと p のレジスタの持ち方 (232/235): 原典は HIDDEN のとき AuxShadow_Hide の呼び出しを NO_SHADOW 側と共有する, bool を返す static inline で分岐の形は揃うが p/boss のレジスタがずれる
NON_MATCH void FUN_080245e4(Duneyrr* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Mover* mover = &boss->mover;
  HitboxData* hitbox;

  FUN_08022ec0(boss);
  if (p->invincibleTimer != 0) {
    SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
    p->invincibleTimer--;
  }
  if (mover->pos.y > 0x27F) {
    SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
  }
  hitbox = &p->hurtbox;
  if (TEST_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX)) {
    Hitbox_SetFlags(hitbox, HBFLAG_HIDDEN);
  } else {
    Hitbox_ClearFlags(hitbox, HBFLAG_HIDDEN);
    Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
  }
  hitbox = &p->hitbox;
  if (TEST_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX)) {
    Hitbox_SetFlags(hitbox, HBFLAG_HIDDEN);
  } else {
    Hitbox_ClearFlags(hitbox, HBFLAG_HIDDEN);
    Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
    Hitbox_Register(hitbox);
  }
  if (p->shakeAmp != 0) {
    u32 angle = Random();

    p->sprite.pos.x += Trig_Fix12ToInt(COS(angle) * (p->shakeAmp * 2));
    p->sprite.pos.z += POLAR_Z(p->shakeAmp * 2, angle);
    p->shakeAmp--;
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_HIDDEN)) {
    MainSprite_Hide(&p->sprite);
    AuxShadow_Hide(&p->shadow);
  } else {
    MainSprite_Show(&p->sprite);
    if (TEST_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW)) {
      AuxShadow_Hide(&p->shadow);
    } else {
      AuxShadow_Show(&p->shadow);
    }
  }
  if (p->flashTimer > 0 && --p->flashTimer == 0) {
    p->sprite.plttID = 0x223;
    p->sprite.pltt = &gObjPlttData[0x223 * 16];
  }
  p->unk_564++;
  boss->weaponExpMask = 0;
  boss->hurtAttributes = 0;
  boss->frameCount++;
#else
  INCFUNC("asm/func/FUN_080245e4.inc");
#endif
}

s32 FUN_08024804(Duneyrr* p) {
  if (Entity5DA5_AreAllLit()) {
    Boss_SetSubState2(&p->base, 5);
    return TRUE;
  }
  return FALSE;
}

// 残差は p のレジスタの持ち方 (371/377): 原典は homePos に近いかを高さの判定込みで 1 / 0 の値にしてから比べる, その形の bool32 を返す static inline で縮むが一致しないので残していない
NON_MATCH void FUN_08024834(Duneyrr* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  if (Entity5DA5_AreAllLit()) {
    if (p->height <= 0xA3) {
      s32 dx = boss->mover.pos.x - p->homePos.x;
      s32 dz = boss->mover.pos.z - p->homePos.z;

      if (dx < 0) {
        dx = -dx;
      }
      if (dz < 0) {
        dz = -dz;
      }
      if (dx < 0x40 && dz < 0x40) {
        if (p->unk_553 >= p->unk_77c) {
          Boss_SetSubState2(boss, 7);
        } else {
          Boss_SetSubState2(boss, 6);
        }
      } else {
        Vec3* home = &p->homePos;

        if (home->x < 0x120) {
          home->x = 0x120;
        } else if (home->x > 0xBE0) {
          home->x = 0xBE0;
        }
        if (home->z < 0x220) {
          home->z = 0x220;
        } else if (home->z > 0xCE0) {
          home->z = 0xCE0;
        }
        Boss_SetTarget(boss, home->x, home->y, home->z);
        Boss_SetSubStates(boss, 0, 0, 1);
      }
    } else {
      Boss_SetSubState2(boss, 5);
    }
  } else if (p->unk_54c != 0) {
    Boss_SetSubState2(boss, 2);
  } else if (p->height <= 0x2FF) {
    Vec3 pos;

    Duneyrr_GetQuadrantPos(&pos, (p->playerQuadrant + 2) & 3, 0x300);
    if (pos.x < 0x120) {
      pos.x = 0x120;
    } else if (pos.x > 0xBE0) {
      pos.x = 0xBE0;
    }
    if (pos.z < 0x220) {
      pos.z = 0x220;
    } else if (pos.z > 0xCE0) {
      pos.z = 0xCE0;
    }
    Boss_SetTarget(boss, pos.x, pos.y, pos.z);
    Boss_SetSubStates(boss, 0, 0, 1);
    if (Boss_GetHPRatio(boss) < 0x60) {
      p->unk_551 = FUN_080591f4() > 5 ? 0 : FUN_08059210() != 0 ? 4 : 6;
    }
  } else if (boss->lowHP) {
    Boss_SetSubState2(boss, (p->unk_554 & 7) == 0 ? 8 : 2);
    p->unk_554++;
  } else {
    Boss_SetSubState2(boss, 2);
  }
#else
  INCFUNC("asm/func/FUN_08024834.inc");
#endif
}

void FUN_08024b70(Duneyrr* p) {
  if (!FUN_08024804(p)) {
    switch (p->unk_173) {
      case 1: {
        Duneyrr_ResetSubStates(p, 120);
        break;
      }
      case 2: {
        Boss_SetSubState2(&p->base, 3);
        break;
      }
      default: {
        FUN_08024834(p);
        break;
      }
    }
    p->unk_173 = 0;
  }
}

bool32 FUN_08024be4(Duneyrr* p) {
  if (TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_1)) {
    Boss_SetSubStates(&p->base, 1, 0, 1);
  } else if (TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_0)) {
    Boss_SetSubStates(&p->base, 1, 0, 0);
  } else {
    return FALSE;
  }
  return TRUE;
}

void FUN_08024c38(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss) == TRUE) {
    Boss_RequestState(boss, 1);
  }
  if (boss->subStateDone) {
    FUN_08024834(p);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_08024c84(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 2);
    Duneyrr_SetMoveSpeed(p, 24);
    p->arriveDistSq = 0x400;
  }
  if (boss->subStateDone) {
    FUN_08024b70(p);
  } else {
    boss->subStateTimer++;
  }
}

// 1 回目で打ち切り
NON_MATCH void FUN_08024cec(Duneyrr* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Vec3* playerPos;
  s32 x;
  s32 y;
  s32 z;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 2);
    Duneyrr_SetMoveSpeed(p, 24);
    p->arriveDistSq = 0x400;
  }
  playerPos = boss->playerPos[0];
  x = playerPos->x;
  z = playerPos->z - 0x200;
  y = p->unk_54c == 0 ? 0x300 : 0x80;
  if (x < 0x120) {
    x = 0x120;
  } else if (x > 0xBE0) {
    x = 0xBE0;
  }
  if (z < 0x220) {
    z = 0x220;
  } else if (z > 0xCE0) {
    z = 0xCE0;
  }
  Boss_SetTarget(boss, x, y, z);
  if (boss->subStateDone) {
    Boss_SetSubState2(boss, 3);
  } else {
    boss->subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_08024cec.inc");
#endif
}

// 1 回目で打ち切り
NON_MATCH void FUN_08024e58(Duneyrr* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Vec3* playerPos;
  s32 x;
  s32 y;
  s32 z;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 3);
    Duneyrr_SetMoveSpeed(p, 24);
    p->arriveDistSq = 0x400;
  }
  playerPos = boss->playerPos[0];
  x = playerPos->x;
  z = playerPos->z - 0x200;
  y = p->unk_54c == 0 ? 0x300 : 0x80;
  if (x < 0x120) {
    x = 0x120;
  } else if (x > 0xBE0) {
    x = 0xBE0;
  }
  if (z < 0x220) {
    z = 0x220;
  } else if (z > 0xCE0) {
    z = 0xCE0;
  }
  Boss_SetTarget(boss, x, y, z);
  if (boss->subStateDone) {
    Duneyrr_ResetSubStates(p, 16);
  } else {
    boss->subStateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_08024e58.inc");
#endif
}

void FUN_08024fe4(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 6);
    Duneyrr_SetMoveSpeed(p, 24);
    p->arriveDistSq = 0x400;
  }
  if (boss->subStateDone) {
    Duneyrr_ResetSubStates(p, 90);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802506c(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss) == TRUE) {
    Vec3* home;

    Boss_RequestState(boss, 9);
    home = &p->homePos;
    Boss_SetTarget(boss, home->x, home->y, home->z);
    Duneyrr_SetMoveSpeed(p, 24);
    p->arriveDistSq = 0x400;
    p->unk_553 = 0;
  }
  if (boss->subStateDone) {
    Boss_SetSubState2(boss, 6);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_08025170(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 10);
    p->unk_553++;
  }
  if (boss->subStateDone) {
    Duneyrr_ResetSubStates(p, 240);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_080251f0(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 12);
  }
  if (boss->subStateDone) {
    FUN_08024834(p);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802523c(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss) == TRUE) {
    Vec3 pos;

    Boss_RequestState(boss, 13);
    Duneyrr_GetQuadrantPos(&pos, p->playerQuadrant, 0x400);
    Boss_SetTarget(boss, pos.x, pos.y, pos.z);
    Duneyrr_SetMoveSpeed(p, 32);
    p->arriveDistSq = 0x510;
  }
  if (boss->subStateDone) {
    Boss_SetSubState2(boss, 4);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0802534c(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 14);
  }
  if (!TEST_FLAGS(boss->flags, BOSSFLAG_UNK_0)) {
    Duneyrr_ResetSubStates(p, 10);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_080253b8(Duneyrr* p) {
  if (p->base.subStateEntered) {
    p->base.subStateEntered = 0;
    p->base.subStateDone = 0;
  }
  p->base.subStateTimer++;
}

void FUN_080253dc(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 18);
  }
  boss->subStateTimer++;
}

void FUN_08025414(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 19);
    MsgQueue_EndWait(&boss->msgQueue, 1);
  }
  boss->subStateTimer++;
}

void FUN_08025458(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 20);
    MsgQueue_EndWait(&boss->msgQueue, 1);
  }
  boss->subStateTimer++;
}

void FUN_0802549c(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 21);
  }
  if (boss->subStateDone) {
    Boss_SetSubState2(boss, 2);
    MsgQueue_EndWait(&boss->msgQueue, 1);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_08025504(Duneyrr* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 22);
  }
  if (boss->subStateDone) {
    Boss_SetSubState2(boss, 0);
    MsgQueue_EndWait(&boss->msgQueue, 1);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_08025568(Duneyrr* p) { PTR_ARRAY_085aab08[p->base.subState2](p); }

void FUN_08025584(Duneyrr* p) { PTR_ARRAY_085aab2c[p->base.subState2](p); }

void FUN_080255a0(Duneyrr* p) { PTR_ARRAY_085aab34[p->base.subState2](p); }

void FUN_080255bc(Duneyrr* p) {
  u32 mask = FLAG03002BC0_UNK_2;

  if (!(u32_03002bc0[0] & mask) && !FUN_08024be4(p)) {
    PTR_ARRAY_085aab48[p->base.subState1](p);
  }
}

void FUN_080255f8(Duneyrr* p) { PTR_ARRAY_085aab4c[p->base.subState1](p); }

void FUN_08025614(Duneyrr* p) { PTR_ARRAY_085aab50[p->base.subState1](p); }

void FUN_08025630(Duneyrr* p) {
  p->base.unk_9d = 0;
  PTR_ARRAY_085aab54[p->base.subState0](p);
}

void FUN_08025654(Boss* boss, s32 timer) {
  Duneyrr* p = (Duneyrr*)boss;

  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    Boss_PlayAnim(&p->base, &p->sprite, &p->gfx, 0, 1, 0);
  }
  if (!p->base.damageCallback(&p->base) && !p->base.stateRequestCallback(&p->base) && timer >= p->stateDuration) {
    p->base.subStateDone = TRUE;
  }
}

// 1 回目で打ち切り
NON_MATCH void FUN_080256c4(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 0, 1, 0);
    p->unk_550 = p->unk_551;
    p->unk_551 = 0;
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    bool32 arrived;
    s32 dy;
    s32 d;

    if (boss->targetDistSq > p->arriveDistSq) {
      u32 angle = boss->targetAngle;
      u32 speed = p->moveSpeed;

      boss->mover.delta.x = POLAR_X(speed, angle);
      boss->mover.delta.y = 0;
      boss->mover.delta.z = POLAR_Z(speed, angle);
      arrived = FALSE;
    } else {
      boss->mover.pos.x = boss->targetPos.x;
      boss->mover.pos.z = boss->targetPos.z;
      arrived = TRUE;
    }
    if ((timer & 7) == 0 && p->height > 0xFF) {
      FUN_08023de8(p);
    }
    dy = boss->targetPos.y - p->height;
    d = dy;
    if (d < 0) {
      d = -d;
    }
    if (d < 32) {
      p->height = boss->targetPos.y;
      if (arrived) {
        boss->subStateDone = TRUE;
      }
    } else {
      p->height += dy < 0 ? -32 : 32;
    }
  }
#else
  INCFUNC("asm/func/FUN_080256c4.inc");
#endif
}

// 残差は targetPos に着いたかを 1 / 0 の値にしてから比べる点と, &targetAngle を先に作る点, static inline bool32 IsWithinDist(u32 distSq, u32 maxDistSq) と Vec3_SetPolar(delta, angle, radius) で残差は &targetAngle の位置だけになるが一致しないので残していない
NON_MATCH void FUN_08025830(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 1, 2, 0);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (boss->targetDistSq <= p->arriveDistSq) {
      boss->mover.pos = boss->targetPos;
    } else {
      u32 angle = boss->targetAngle;
      u32 speed = p->moveSpeed;

      boss->mover.delta.x = POLAR_X(speed, angle);
      boss->mover.delta.y = 0;
      boss->mover.delta.z = POLAR_Z(speed, angle);
    }
    if (p->sprite.animEvents & MAIN_ANIM_EVENT_ENDED) {
      Boss_SetState(boss, FUN_08025948, 4);
    }
  }
#else
  INCFUNC("asm/func/FUN_08025830.inc");
#endif
}

// 1 回目で打ち切り (397/366), 揺れと鱗粉の位置は entity_08059a1c.c の Vec3_Sum / Vec3_SetPolar と同じ形の static inline にすると命令数は揃う (366/366), 残りは p と boss のレジスタ
NON_MATCH void FUN_08025948(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 2, 1, 0);
    p->unk_160 = 0;
    p->unk_171 = 0;
    p->shakeOrigin = mover->pos;
    p->unk_172 = (Random() & 0xF) + 0x38;
    PlaySound_0824078c(SONG_950);
  }
  if (boss->damageCallback(boss) || boss->stateRequestCallback(boss)) {
    return;
  }
  if ((timer & 7) == 0) {
    Vec3 pos = mover->pos;

    pos.x = pos.x - 0x80 + (u8)Random();
    FUN_08015ce0(1, 5, 0x3001, 0x40, 0x40, 0x10, 8, 2, -4, timer & 7, &pos);
  }
  if (timer <= 0x40) {
    Vec3 ofs;

    ofs.x = Trig_Fix12ToInt(SIN(timer * 4) * 128);
    ofs.y = 0;
    ofs.z = Trig_Fix12ToInt(SIN(timer * 8) * 32);
    mover->pos.x = p->shakeOrigin.x + ofs.x;
    mover->pos.y = p->shakeOrigin.y + ofs.y;
    mover->pos.z = p->shakeOrigin.z + ofs.z;
    if (timer >= 0x10 && timer <= 0x30 && ++p->unk_171 > 2) {
      Vec3 pos;
      s32 radius = (timer - 0x10) * 32 + (Random() & 0x3F) - 200;
      u32 angle;

      pos.x = POLAR_X(radius, 0x40);
      pos.y = 0;
      pos.z = POLAR_Z(radius, 0x40);
      pos.x = pos.x - 0x80 + ((u8)Random() + p->shakeOrigin.x);
      pos.z += p->shakeOrigin.z;
      pos.y = 0x100;
      if (p->shakeOrigin.x < pos.x) {
        angle = (Random() & 0xF) + 0x40;
      } else {
        angle = (Random() & 0xF) + 0x40;
      }
      DustManager_Emit(1, angle, 0, 2, 0, 0x20, p->dustPower, 0, &pos);
      p->unk_171 = 0;
    }
  }
  if (timer > 0x3F && (p->sprite.animEvents & MAIN_ANIM_EVENT_ENDED)) {
    Boss_SetState(boss, FUN_08025c84, 5);
  }
#else
  INCFUNC("asm/func/FUN_08025948.inc");
#endif
}

void FUN_08025c84(Boss* boss, s32 timer) {
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 3, 2, 0);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss) && (p->sprite.animEvents & MAIN_ANIM_EVENT_ENDED)) {
    boss->subStateDone = TRUE;
  }
}

// 1 回目で打ち切り, 状態関数の共通の形 (boss 局所変数, Boss_SetState) は当ててある
NON_MATCH void FUN_08025cf8(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;
  Vec3* playerPos = boss->playerPos[0];

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 0, 1, 0);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    s32 d;

    d = p->sprite.pos.z - playerPos->z;
    if (d < 0) {
      d = -d;
    }
    if (d <= 32) {
      boss->mover.delta.z = playerPos->z - p->sprite.pos.z;
    } else {
      boss->mover.delta.z = p->sprite.pos.z < playerPos->z ? 32 : -32;
    }
    d = p->sprite.pos.x - playerPos->x;
    if (d < 0) {
      d = -d;
    }
    if (d <= 32) {
      boss->mover.delta.x = playerPos->x - p->sprite.pos.x;
    } else {
      boss->mover.delta.x = p->sprite.pos.x < playerPos->x ? 32 : -32;
    }
    if (p->height <= 0x1900) {
      p->height += 0x40;
    } else {
      p->height = 0x1900;
      Boss_SetState(boss, FUN_08025e10, 7);
    }
  }
#else
  INCFUNC("asm/func/FUN_08025cf8.inc");
#endif
}

// 1 回目で打ち切り
NON_MATCH void FUN_08025e10(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 4, 2, 0);
    p->unk_16a = (Random() & 7) + 3;
    FUN_08024068(p);
    PlaySound_0824078c(SE_CHANGE_BAT | BGM_16 | BGM_QUAKE);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (p->sprite.pos.y > 0xFFF) {
      Vec3* playerPos = boss->playerPos[0];

      if (boss->playerDistSq[0] > p->arriveDistSq) {
        u32 angle = boss->playerAngle[0];
        u32 speed = p->moveSpeed;

        boss->mover.delta.x = POLAR_X(speed, angle);
        boss->mover.delta.y = 0;
        boss->mover.delta.z = POLAR_Z(speed, angle);
      } else {
        boss->mover.pos.x = playerPos->x;
        boss->mover.pos.z = playerPos->z;
      }
    }
    if (p->height <= 0x80) {
      p->height = 0x80;
      Boss_SetState(boss, FUN_08025f8c, 8);
    } else {
      p->height -= 0x80;
    }
  } else {
    FUN_080240b4(p);
  }
#else
  INCFUNC("asm/func/FUN_08025e10.inc");
#endif
}

void FUN_08025f8c(Boss* boss, s32 timer) {
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    WorldPos* pos;

    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 5, 2, 0);
    pos = &boss->mover.pos;
    FUN_08015a90(pos, 4, 5, 0x3001, 0x40, 8, 0x100, 0x100);
    FUN_08015a90(pos, 6, 5, 0x3001, 0x40, 10, 0x100, 0x100);
    FUN_080240b4(p);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss) && (p->sprite.animEvents & MAIN_ANIM_EVENT_ENDED)) {
    boss->subStateDone = TRUE;
  }
}

// 1 回目で打ち切り
NON_MATCH void FUN_0802604c(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 0, 1, 0);
    Duneyrr_SetHurtboxPower(p, p->hurtboxPower2);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    bool32 arrived;

    if (boss->targetDistSq < 0x40000 && boss->prevAnimID == 0) {
      Boss_PlayAnim(boss, &p->sprite, &p->gfx, 6, 2, 0);
    }
    if (boss->targetDistSq > p->arriveDistSq) {
      u32 angle = boss->targetAngle;
      u32 speed = p->moveSpeed;

      boss->mover.delta.x = POLAR_X(speed, angle);
      boss->mover.delta.y = 0;
      boss->mover.delta.z = POLAR_Z(speed, angle);
      arrived = FALSE;
    } else {
      boss->mover.pos.x = boss->targetPos.x;
      boss->mover.pos.z = boss->targetPos.z;
      arrived = TRUE;
    }
    if (p->height > boss->targetPos.y) {
      p->height -= 0x10;
    } else {
      p->height = boss->targetPos.y;
      if (arrived) {
        boss->subStateDone = TRUE;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_0802604c.inc");
#endif
}

void FUN_080261b4(Boss* boss, s32 timer) {
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 6, 1, 0);
    p->unk_160 = 0;
    p->unk_16e = 0;
    PlaySound_0824078c(SONG_951);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    if (p->unk_16e == 0) {
      u32 angle = Random() & 0x7F;

      if (p->entity08059a1c != NULL) {
        Entity08059a1c_AddElem(p->entity08059a1c, angle, 16);
      }
      p->unk_16e = 24;
    } else {
      p->unk_16e--;
    }
    if ((p->sprite.animEvents & MAIN_ANIM_EVENT_ENDED) && ++p->unk_160 > 15) {
      Boss_SetState(boss, FUN_080262c0, 11);
    }
  }
}

void FUN_080262c0(Boss* boss, s32 timer) {
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 7, 2, 0);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss) && (p->sprite.animEvents & MAIN_ANIM_EVENT_ENDED)) {
    boss->subStateDone = TRUE;
  }
}

// 残差 10 箇所 (212/211): Entity5DA5 タイマー初期化ループで delay=24 の初期化位置がずれる, pos.x への乱数加算で -0x80 を乱数側に畳む
NON_MATCH void FUN_08026334(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 9, 2, 0);
    if (Entity5DA5_AreAllLit()) {
      s32 i;
      s32 delay = 24;

      for (i = 0; i < 4; i++) {
        p->unk_568[i] = delay + (Random() & 3);
        delay += 3;
      }
    }
    p->unk_54c = 0;
    Duneyrr_SetHurtboxPower(p, p->hurtboxPower);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    s32 i;

    if (boss->prevAnimID == 9) {
      if (p->height < 0x300) {
        p->height += 0x10;
      }
      mover->delta.z = -4;
      if ((timer & 7) == 0) {
        Vec3 pos = mover->pos;

        pos.x = pos.x - 0x80 + (u8)Random();
        pos.y -= 0x40;
        FUN_08015ce0(1, 5, 0x3001, 0x40, 0x40, 0x10, 8, 2, -4, timer & 7, &pos);
      }
    }
    for (i = 0; i < 4; i++) {
      if (p->unk_568[i] != 0 && --p->unk_568[i] == 0) {
        Entity5DA5_SetState(i, 0, 1);
      }
    }
    if (p->sprite.animEvents & MAIN_ANIM_EVENT_ENDED) {
      Boss_SetState(boss, FUN_08025654, 1);
    }
  }
#else
  INCFUNC("asm/func/FUN_08026334.inc");
#endif
}

// 1 回目で打ち切り, 着いたかの比較は FUN_08025830 と同じく 1 / 0 の値にしてから比べる形
NON_MATCH void FUN_08026514(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;
  Mover* mover = &boss->mover;
  Vec3* playerPos = boss->playerPos[0];

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 0, 1, 0);
    p->unk_550 = FUN_080591f4() > 6 ? 3 : 6;
    p->unk_160 = 0;
  }
  if (boss->damageCallback(boss) || boss->stateRequestCallback(boss)) {
    return;
  }
  if ((timer & 7) == 0) {
    Vec3 pos;

    pos.x = mover->pos.x + (Random() & 0x1FF) - 0x100;
    pos.y = mover->pos.y;
    pos.z = mover->pos.z + (u8)Random() - 0x80;
    FUN_08015ce0(1, 5, 0x3001, 0x40, timer & 7, 0x100, 4, 2, -12, 6, &pos);
  }
  if (boss->playerDistSq[0] <= p->arriveDistSq) {
    mover->pos.x = playerPos->x;
    mover->pos.z = playerPos->z;
    if (p->unk_160 == 0) {
      p->unk_160 = 1;
    }
  } else {
    u32 angle = boss->playerAngle[0];
    u32 speed = p->moveSpeed;

    mover->delta.x = POLAR_X(speed, angle);
    mover->delta.y = 0;
    mover->delta.z = POLAR_Z(speed, angle);
  }
  if (p->unk_160 != 0) {
    if (p->height <= 0x400) {
      p->height += 0x20;
    } else {
      p->height = 0x400;
      boss->subStateDone = TRUE;
    }
  } else if (p->height > 0x190) {
    p->height -= 0x10;
  }
#else
  INCFUNC("asm/func/FUN_08026514.inc");
#endif
}

// 残差は FUN_08026334 と同じ (247/244): pos.x への乱数加算で -0x80 を乱数側に畳む
NON_MATCH void FUN_08026738(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;
  Mover* mover = &boss->mover;
  s32 i;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 8, 1, 0);
    p->unk_160 = 0;
    p->unk_544 = p->unk_542;
    for (i = 0; i < 4; i++) {
      p->unk_568[i] = 0;
    }
    p->unk_54c = 0;
    Duneyrr_SetHurtboxPower(p, p->hurtboxPower);
    PlaySound_0824078c(SONG_958);
  }
  p->unk_564 = 0;
  p->damage = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (boss->prevAnimID == 9) {
    if (p->height < 0x300) {
      p->height += 0x10;
    }
    mover->delta.z = -4;
    if ((timer & 7) == 0) {
      Vec3 pos = mover->pos;

      pos.x = pos.x - 0x80 + (u8)Random();
      pos.y -= 0x40;
      FUN_08015ce0(1, 5, 0x3001, 0x40, 0x40, 0x10, 8, 2, -4, timer & 7, &pos);
    }
  }
  for (i = 0; i < 4; i++) {
    if (p->unk_568[i] != 0 && --p->unk_568[i] == 0) {
      Entity5DA5_SetState(i, 0, 1);
    }
  }
  if (p->sprite.animEvents & MAIN_ANIM_EVENT_ENDED) {
    if (boss->prevAnimID == 8) {
      if (p->unk_160 > 3) {
        Boss_PlayAnim(boss, &p->sprite, &p->gfx, 9, 2, 0);
        if (Entity5DA5_AreAllLit()) {
          s32 delay = 24;

          for (i = 0; i < 4; i++) {
            p->unk_568[i] = delay + (Random() & 3);
            delay += 3;
          }
        }
      } else {
        p->unk_160++;
      }
    } else {
      Boss_SetState(boss, FUN_08025654, 1);
    }
  }
#else
  INCFUNC("asm/func/FUN_08026738.inc");
#endif
}

// 残差は p と boss のレジスタの持ち方 (318/326), 高さの補間で unk_184 == 0 のときと時間切れのときの代入を原典は別々に持つがこちらは1つに畳む
NON_MATCH void FUN_08026968(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;
  Mover* mover = &boss->mover;
  Vec3 pos;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 10, 1, 0);
    p->unk_16a = (Random() & 7) + 3;
    FUN_08023530(p);
    if (p->unk_180 != 0) {
      s32 dx = p->unk_190.x - p->unk_188.x;
      s32 dz = p->unk_190.z - p->unk_188.z;

      p->unk_184 = Div(Sqrt(dx * dx + dz * dz), p->unk_180);
    } else {
      p->unk_184 = 1;
    }
    if (p->unk_16f == 0) {
      Boss_GiveWeaponExp(boss, p->weaponExp);
      FUN_08022fb8(boss, &p->sprite.pos);
    }
    p->unk_174 = 0x17E;
  }
  pos = mover->pos;
  pos.y += p->unk_174;
  Camera_MoveTo(&pos);
  p->damage = 0;
  {
    u32 angle = ArcTan2_8(p->unk_190.x - mover->pos.x, p->unk_190.z - mover->pos.z);
    s32 speed = p->unk_180;

    mover->delta.x = POLAR_X(speed, angle);
    mover->delta.y = 0;
    mover->delta.z = POLAR_Z(speed, angle);
  }
  if (timer < p->unk_184) {
    if (p->unk_184 != 0) {
      p->height = p->unk_188.y + Div(timer * (p->unk_190.y - p->unk_188.y), p->unk_184);
    } else {
      p->height = p->unk_190.y;
    }
  } else {
    p->height = p->unk_190.y;
  }
  FUN_08023bd8(p, 0);
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (timer >= p->unk_184) {
    if (p->unk_16f == 0) {
      PlaySound_0824078c(SONG_955);
    } else {
      PlaySound_0824078c(SONG_955);
    }
    if (++p->unk_16f <= 1) {
      s32 i;

      p->unk_180 = (p->unk_180 * 32) >> 6;
      Boss_SetState(boss, FUN_08026968, 15);
      for (i = 0; i < 8; i++) {
        FUN_08023bd8(p, 0);
      }
    } else {
      Boss_SetState(boss, FUN_08026c50, 16);
      PlaySound_0824078c(SONG_957);
    }
  }
#else
  INCFUNC("asm/func/FUN_08026968.inc");
#endif
}

// 1 回目で打ち切り (517/494), 高さの補間は FUN_08026968 と同じ形
NON_MATCH void FUN_08026c50(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;
  Mover* mover = &boss->mover;
  Vec3 pos;

  if (boss->stateEntered) {
    s32 dx;
    s32 dz;

    boss->stateEntered = FALSE;
    p->unk_188 = mover->pos;
    p->unk_190.x = 0x680;
    p->unk_190.y = 0;
    p->unk_190.z = 0x500;
    p->unk_162 = 0;
    p->unk_180 = 8;
    dx = p->unk_190.x - p->unk_188.x;
    dz = p->unk_190.z - p->unk_188.z;
    p->unk_184 = Div(Sqrt(dx * dx + dz * dz), p->unk_180);
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 11, 2, 0);
  }
  pos = mover->pos;
  pos.y += p->unk_174;
  Camera_MoveTo(&pos);
  p->damage = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  {
    s32 dx = p->unk_190.x - mover->pos.x;
    s32 dz = p->unk_190.z - mover->pos.z;

    if (dx * dx + dz * dz >= p->unk_180 * p->unk_180) {
      u32 angle = ArcTan2_8(dx, dz);
      s32 speed = p->unk_180;

      mover->delta.x = POLAR_X(speed, angle);
      mover->delta.y = 0;
      mover->delta.z = POLAR_Z(speed, angle);
    }
  }
  if (timer < p->unk_184) {
    if (p->unk_184 != 0) {
      p->height = p->unk_188.y + Div(timer * (p->unk_190.y - p->unk_188.y), p->unk_184);
    } else {
      p->height = p->unk_190.y;
    }
  } else {
    p->height = p->unk_190.y;
  }
  if (p->unk_184 > 0) {
    p->height += Trig_Fix12ToInt(SIN(Div(timer * 128, p->unk_184)) * 256);
  }
  if (p->height > 0x1FF) {
    FUN_08023bd8(p, 1);
  }
  if (p->unk_162 == 1) {
    if (p->height <= 0x41A && p->elems[1].state == 0) {
      DuneyrrElem_SetState(&p->elems[1], 1);
    }
    if (p->height <= 0x47E && p->elems[0].state == 0) {
      DuneyrrElem_SetState(&p->elems[0], 1);
    }
    if (p->height <= 0x578 && p->elems[4].state == 0) {
      DuneyrrElem_SetState(&p->elems[4], 1);
    }
    if (p->height <= 0x300) {
      if (p->elems[2].state == 0) {
        DuneyrrElem_SetState(&p->elems[2], 2);
      }
      if (p->elems[3].state == 0) {
        DuneyrrElem_SetState(&p->elems[3], 2);
      }
      p->unk_174 = p->unk_174 > 4 ? p->unk_174 - 4 : 0;
    }
  }
  if (p->unk_162 != 0) {
    if (p->elems[2].state == 3) {
      CLEAR_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
      if (p->unk_54b > 4) {
        p->unk_54b -= 4;
      }
    } else if (p->elems[2].state == 2) {
      if (p->elems[2].sprite.flags & SPRFLAG_HIDDEN) {
        CLEAR_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
      } else {
        SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
      }
      if (p->unk_54b > 4) {
        p->unk_54b -= 4;
      }
    } else {
      SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
    }
    p->sprite.pos.y += p->unk_54b;
  }
  if (boss->animDone && p->unk_162 == 0) {
    FUN_08023818(p);
    p->unk_54b = 200;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 19, 2, 0);
    p->unk_162 = 1;
  }
  if (timer >= p->unk_184) {
    PlaySound_0824078c(SE_899);
    FUN_080592a4();
    if (Entity5DA5_AreAllLit()) {
      s32 i;

      for (i = 0; i < 4; i++) {
        Entity5DA5_SetState(i, 0, 1);
      }
    }
    Boss_SetState(boss, FUN_08027090, 17);
  }
#else
  INCFUNC("asm/func/FUN_08026c50.inc");
#endif
}

void FUN_08027090(Boss* boss, s32 timer) {
  Duneyrr* p = (Duneyrr*)boss;
  Mover* mover = &boss->mover;
  Vec3 pos;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 19, 2, 0);
    FUN_08023024(boss, &p->sprite.pos);
    p->unk_54b = 0;
  }
  if (p->unk_174 >= 5) {
    p->unk_174 -= 4;
  } else {
    p->unk_174 = 0;
  }
  pos = mover->pos;
  pos.y += p->unk_174;
  Camera_MoveTo(&pos);
  if (timer < 8) {
    p->unk_54b += 2;
  } else if (p->unk_54b >= 3) {
    p->unk_54b -= 2;
  } else {
    p->unk_54b = 0;
  }
  p->sprite.pos.y += p->unk_54b;
  p->damage = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
}

void FUN_08027188(Boss* boss, s32 timer) {
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 0, 1, 0);
  }
  p->damage = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_HIDDEN);
  boss->stateRequestCallback(boss);
}

void FUN_080271e0(Boss* boss, s32 timer) {
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite, &p->gfx, 0, 1, 0);
    p->height = 0x80;
    AuxShadow_SetScaleParams(&p->shadow, 0x60, 0x60, 0x60, 0x60, 0x1964, 100, 6, 1);
    p->height = 0x180;
    p->spriteOffsetY = 0;
  }
  p->damage = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  boss->stateRequestCallback(boss);
}

void FUN_08027278(Boss* boss, s32 timer) {
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFlip(boss, &p->sprite, &p->gfx, 17, 1, 0);
    AuxShadow_SetScaleParams(&p->shadow, 0x30, 0x30, 0x30, 0x30, 0x1964, 100, 6, 1);
    p->height = 0x100;
    p->spriteOffsetY = 0;
  }
  p->damage = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  boss->stateRequestCallback(boss);
}

// 1 回目で打ち切り
NON_MATCH void FUN_0802730c(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFlip(boss, &p->sprite, &p->gfx, 17, 1, 0);
    boss->targetPos = boss->mover.pos;
    SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
    AuxShadow_SetScaleParams(&p->shadow, 0x30, 0x30, 0x30, 0x30, 0x1964, 100, 6, 1);
    p->height = 0x100;
    p->spriteOffsetY = 0;
    PlaySound_0824078c(SE_808);
  }
  p->damage = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_NO_SHADOW);
  if (!boss->stateRequestCallback(boss)) {
    boss->mover.pos = boss->targetPos;
    if (timer < 32) {
      s32 radius = (32 - timer) * 8;

      boss->mover.delta.x = POLAR_X(radius, (~timer & 3) * 0x40);
      boss->mover.delta.y = 0;
      boss->mover.delta.z = POLAR_Z(radius, (~timer & 3) * 0x40);
    } else {
      boss->subStateDone = TRUE;
    }
  }
#else
  INCFUNC("asm/func/FUN_0802730c.inc");
#endif
}

// 1 回目で打ち切り, 状態関数の共通の形 (boss 局所変数, Boss_SetState) は当ててある
NON_MATCH void FUN_08027454(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Duneyrr* p = (Duneyrr*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFlip(boss, &p->sprite, &p->gfx, 17, 1, 0);
    boss->targetPos = boss->mover.pos;
    AuxShadow_SetScaleParams(&p->shadow, 0x30, 0x30, 0x30, 0x30, 0x1964, 100, 6, 1);
    p->height = 0x100;
    p->spriteOffsetY = 0;
    PlaySound_0824078c(SE_808);
  }
  p->damage = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_NO_SHADOW);
  if (!boss->stateRequestCallback(boss)) {
    boss->mover.pos = boss->targetPos;
    boss->mover.delta.x = POLAR_X(timer * 8, (timer & 3) * 0x40);
    boss->mover.delta.y = 0;
    boss->mover.delta.z = POLAR_Z(timer * 8, (timer & 3) * 0x40);
    if (timer > 31) {
      boss->subStateDone = TRUE;
    }
  }
#else
  INCFUNC("asm/func/FUN_08027454.inc");
#endif
}

void FUN_08027588(Duneyrr* p) {
  u32 mask;

  p->base.subStateDone = 0;
  mask = FLAG03002BC0_UNK_2;
  if (!(u32_03002bc0[0] & mask)) {
    Boss_UpdateState(&p->base);
  }
}

s32 FUN_080275b0(Duneyrr* p) {
  if (p->base.state == 0 || p->base.state > 23) {
    return FALSE;
  } else {
    Boss_SetState(&p->base, (BossUpdateFunc)PTR_ARRAY_085aab60[p->base.state], p->base.state);
    return TRUE;
  }
}

s32 Duneyrr_HandleDamage(Duneyrr* p) {
  HitboxData* hurtbox = &p->hurtbox;
  s32 damage = p->damage;

  p->damage = 0;
  if (damage > 0) {
    Vec3 ofs;

    p->unk_544 -= p->unk_546 + damage;
    p->base.hp -= damage;
    p->invincibleTimer = 15;
    p->flashTimer = 10;
    p->sprite.plttID = 0x223;
    p->sprite.pltt = p->pltt[0];
    VEC3_SET(ofs, 0x10, 0, 0x10);
    FUN_0805fe7c(hurtbox, damage, 0, &p->base.mover.pos, &ofs, 1);
    if (p->base.hp <= 0) {
      PlaySound_0824078c(SE_CHANGE_BAT | BGM_16 | BGM_10);
      p->base.hp = 0;
      SET_FLAGS(p->base.flags, BOSSFLAG_UNK_1);
      p->unk_16f = 0;
      p->unk_162 = 0;
      p->unk_180 = 0x80;
      p->unk_167 = p->base.players[0]->mover.angle;
      Boss_SetState(&p->base, FUN_08026968, 15);
      FUN_08059248();
      return TRUE;
    }
    PlaySound_0824078c(SE_ENEMY_DAMAGED);
    if (p->base.hurtAttributes & HBATTR_EARTH) {
      FUN_08024100(&p->sprite.pos);
    }
    if (p->unk_544 <= 0) {
      SET_FLAGS(p->base.flags, BOSSFLAG_UNK_0);
      Boss_SetState(&p->base, FUN_08026738, 14);
      return TRUE;
    }
  }
  return FALSE;
}

s32 Duneyrr_Update(Duneyrr* p) {
  FUN_08024500(p);
  FUN_08025630(p);
  FUN_08027588(p);
  FUN_080245e4(p);
  return 0;
}

s32 Duneyrr_Destroy(Duneyrr* p) {
  AuxShadow_Remove(&p->shadow);
  Duneyrr_UnregisterHurtbox(p);
  MainSprite_Remove(&p->sprite);
  Duneyrr_RemoveElems(p);
  Boss_Destroy(&p->base);
  return 0;
}

// 残差 15 箇所 (679/677): damageCallback / stateRequestCallback の代入で原典は関数アドレスを先に載せる, &damageBonus を r4 に置くか r8 に置くかと '.e' の既定値のオフセットの使い回し
NON_MATCH s32 Duneyrr_Init(Duneyrr* p, u32 id) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  BossID bossID = VM_GetNamedArgValue('t', 0);
  MainSpriteGfxFile* f;
  Vec3 pos;
  u32 angle;
  s32 hp;

  Boss_Register(boss, bossID);
  if (gPlayerPtr[0] != NULL) {
    boss->players[0] = gPlayerPtr[0];
    boss->playerPos[0] = &gPlayerPtr[0]->mover.pos;
  } else {
    boss->players[0] = NULL;
    boss->playerPos[0] = NULL;
  }
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_DUNEYRR);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx, f);
  p->homePos.x = 0x680;
  p->homePos.y = 0x80;
  p->homePos.z = 0x600;
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    angle = VM_GetValue();
  } else {
    VEC3_SET(pos, gStat->playerX, gStat->playerY, gStat->playerZ);
    angle = 0x40;
  }
  if (VM_SeekToNamedArg('s')) {
    hp = VM_GetValue();
    p->hurtboxPower = VM_GetValue();
    p->hurtboxPower2 = VM_GetValue();
  } else {
    hp = 500;
    p->hurtboxPower = 10;
    p->hurtboxPower2 = 0;
  }
  if (VM_SeekToNamedArg('a')) {
    p->hitboxPower = VM_GetValue();
    p->hitboxKnockback = VM_GetValue();
    p->hitboxUnk44 = VM_GetValue();
    p->hitboxPower2 = VM_GetValue();
    p->hitboxKnockback2 = VM_GetValue();
    p->hitboxUnk44_2 = VM_GetValue();
    p->dustPower = VM_GetValue();
    p->unk_78c = VM_GetValue();
  } else {
    p->hitboxPower = 35;
    p->hitboxKnockback = 50;
    p->hitboxUnk44 = 60;
    p->hitboxPower2 = 50;
    p->hitboxKnockback2 = 240;
    p->hitboxUnk44_2 = 60;
    p->dustPower = 13;
    p->unk_78c = 35;
  }
  Boss_Init(boss, id, bossID, &pos, angle);
  boss->unk_114 = angle;
  boss->unk_ab = VM_GetNamedArgValue('i', 0);
  MainSprite_Add(&p->sprite, &p->gfx, 0, 0, 2, 0, 60, &pos);
  Boss_PlayAnim(boss, &p->sprite, &p->gfx, 0, 1, 0);
  if (boss->unk_ab != 0) {
    switch (VM_GetNamedArgValue('D', 1)) {
      case 0: {
        Boss_SetSubStates(boss, 2, 0, 0);
        Boss_SetState(boss, FUN_08027188, 18);
        p->height = 0x80;
        p->spriteOffsetY = 0;
        break;
      }
      case 1: {
        Boss_SetSubStates(boss, 2, 0, 1);
        Boss_SetState(boss, FUN_080271e0, 19);
        p->height = 0x80;
        p->spriteOffsetY = 0;
        break;
      }
      case 2: {
        Boss_SetSubStates(boss, 2, 0, 2);
        Boss_SetState(boss, FUN_08027278, 20);
        p->height = 0;
        p->spriteOffsetY = 0;
        break;
      }
    }
  } else {
    Duneyrr_ResetSubStates(p, 120);
    Boss_SetState(boss, FUN_08025654, 1);
    p->height = 0x80;
    p->spriteOffsetY = 0;
  }
  boss->damageCallback = (BossCheckFunc)Duneyrr_HandleDamage;
  boss->stateRequestCallback = (BossCheckFunc)FUN_080275b0;
  Boss_InitHP(boss, hp, hp, p->hurtboxPower);
  Duneyrr_InitHitbox(p);
  Duneyrr_InitHurtbox(p, p->hurtboxPower);
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
  if (VM_SeekToNamedArg('e')) {
    p->unk_78e = VM_GetValue();
    p->unk_790 = VM_GetValue();
    p->unk_792 = VM_GetValue();
    p->unk_794 = VM_GetValue();
    p->unk_798 = VM_GetValue();
  } else {
    p->unk_78e = 30;
    p->unk_790 = 0;
    p->unk_792 = 28;
    p->unk_794 = 1;
    p->unk_798 = 0;
  }
  p->weaponExp = VM_GetNamedArgValue('K', 0);
  boss->damageBonus = VM_GetNamedArgValue('x', 2);
  p->unk_796 = 500;
  FUN_08024324(p);
  Duneyrr_InitElems(p);
  AuxShadow_Init(&p->shadow, &p->sprite.pos, 0x60, 0x60, 0x60, 0x60, 0x1964, 100, 6, 1, 0);
  AuxShadow_SetSprite(&p->shadow, SPRITE_EFF_1C1B, 7);
  if (VM_SeekToNamedArg('j')) {
    p->unk_542 = VM_GetValue();
    p->unk_546 = VM_GetValue();
    p->unk_77c = VM_GetValue();
  } else {
    p->unk_542 = 150;
    p->unk_546 = 50;
    p->unk_77c = 3;
  }
  p->unk_544 = p->unk_542;
  p->entity08059a1c = Entity08059a1c_Create(p->unk_78c, 30, 15, p->dustPower);
  if (p->entity08059a1c == NULL) {
    return -1;
  }
  if (Entity08058ffc_Create(p->unk_792, p->unk_794, p->unk_798) == NULL) {
    return -1;
  }
  {
    s32 i;

    rgb555* src = &gObjPlttData[0x132 * 16];

    for (i = 0; i < 16; i++) {
      CpuCopy32(src, p->pltt[i], sizeof(p->pltt[i]));
    }
  }
  return 0;
#else
  INCFUNC("asm/func/Duneyrr_Init.inc");
#endif
}

Duneyrr* Duneyrr_Create(u32 id) {
  Duneyrr* p = Boss_Get(BOSS_DUNEYRR);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Duneyrr));
  if (p != NULL) {
    SetEntityRoutine(p, Duneyrr_Update, Duneyrr_Destroy);
    if (Duneyrr_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
