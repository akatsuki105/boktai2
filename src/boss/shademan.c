#include "boss/shademan.h"

#include "boss.h"
#include "camera.h"
#include "collision_map.h"
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

// シェードマンの残像, timer が切れると隠す
typedef struct {
  MainSprite sprite;  // 0x00
  bool8 active;       // 0x60
  s8 timer;           // 0x61
  u8 unk_62[2];       // 0x62
} ShadeManAfterimage;
static_assert(sizeof(ShadeManAfterimage) == 100);

// シェードマン(シングルプレイ用)
typedef struct ShadeMan {
  Boss base;                                 // 0x000
  s32 weaponExp;                             // 0x158, '.K'
  HitboxData hurtbox;                        // 0x15C, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_ANGLE | HBFLAG_UNK_0, ハンドラは ShadeMan_OnHurt
  HitboxData hurtbox2;                       // 0x1AC, HBFLAG_HURTBOX | HBFLAG_UNK_1 | HBFLAG_UNK_0, ハンドラは空
  HitboxData hitbox;                         // 0x1FC
  HitboxData hitbox2;                        // 0x24C
  MainSpriteGfx gfx;                         // 0x29C, SPRITE_SHADEMAN
  MainSprite sprite;                         // 0x2BC
  AuxShadow shadow;                          // 0x31C
  u8 unk_388;                                // 0x388
  u8 unk_389[0x38C - 0x389];                 // 0x389
  u32 unk_38c;                               // 0x38C, FUN_0821bd14 が bit8 を立てる
  u32 unk_390;                               // 0x390, 毎フレーム 1 ずつ増える
  u32 motion;                                // 0x394, PTR_ARRAY_085b0028 の添字
  u32 nextMotion;                            // 0x398, -1 でなければ次のフレームで motion に移る
  u32 motionTimer;                           // 0x39C, motion を切り替えてからのフレーム数
  u32 unk_3a0;                               // 0x3A0
  s32 unk_3a4;                               // 0x3A4
  u32 unk_3a8;                               // 0x3A8
  void (*motionCallback)(struct ShadeMan*);  // 0x3AC, PTR_ARRAY_085b0028[motion]
  u32 unk_3b0;                               // 0x3B0
  u32 angle;                                 // 0x3B4
  s16 animIdx;                               // 0x3B8, ShadeMan_PlayAnim で最後に再生したアニメ番号
  u16 unk_3ba;                               // 0x3BA
  s16 unk_3bc;                               // 0x3BC
  s16 hitboxPower;                           // 0x3BE, '.a[0]=0'
  s16 hitboxKnockback;                       // 0x3C0, '.a[1]=0'
  s16 hitboxUnk44;                           // 0x3C2
  s16 hitbox2Power;                          // 0x3C4, '.a[3]=0'
  s16 hitbox2Knockback;                      // 0x3C6, '.a[4]=0'
  s16 hitbox2Unk44;                          // 0x3C8
  s16 unk_3ca;                               // 0x3CA
  s16 unk_3cc;                               // 0x3CC
  s16 unk_3ce;                               // 0x3CE
  s16 unk_3d0;                               // 0x3D0
  s16 unk_3d2;                               // 0x3D2
  s16 unk_3d4;                               // 0x3D4
  s16 unk_3d6;                               // 0x3D6
  s8 unk_3d8;                                // 0x3D8
  s8 unk_3d9;                                // 0x3D9
  s8 unk_3da;                                // 0x3DA
  u8 unk_3db;                                // 0x3DB
  s32 unk_3dc;                               // 0x3DC, hp がこれ以下になると ShadeMan_HandleDamage が状態を移す
  s32 scriptID;                              // 0x3E0, '.b[1]=0'
  s32 scriptID2;                             // 0x3E4, '.b[2]=0'
  s16 hurtboxPower;                          // 0x3E8, '.s[1]=999'
  s16 hurtboxPower2;                         // 0x3EA, '.s[2]=400'
  u16 damage;                                // 0x3EC, ShadeMan_OnHurt が受けたダメージを入れる
  u16 hurtAngle;                             // 0x3EE
  s16 unk_3f0;                               // 0x3F0, 正の間 FUN_0821c2a0 が色を混ぜない
  s16 unk_3f2;                               // 0x3F2
  s32 unk_3f4;                               // 0x3F4
  s32 unk_3f8;                               // 0x3F8
  s32 unk_3fc;                               // 0x3FC, 正の間 BOSSFLAG_NO_HURTBOX を立てる
  rgb555 pltt[16][16];                       // 0x400, 白 (0x7FFF) で埋める
  rgb555 pltt_600[16][16];                   // 0x600
  u32 unk_800;                               // 0x800
  s16 stateDuration;                         // 0x804
  s16 unk_806;                               // 0x806
  u8 unk_808;                                // 0x808
  u8 unk_809;                                // 0x809
  u8 unk_80a[0x80C - 0x80A];                 // 0x80A
  u32 unk_80c;                               // 0x80C
  u32 unk_810;                               // 0x810
  ShadeManAfterimage afterimages[8];         // 0x814
  MainSpriteGfx gfx_b34;                     // 0xB34, SPRITE_DJANGO_SABATA
  MainSprite sprite_b54;                     // 0xB54
  Vec3 unk_bb4;                              // 0xBB4
  u8 unk_bbc;                                // 0xBBC
  u8 unk_bbd;                                // 0xBBD
  u8 unk_bbe;                                // 0xBBE
  u8 unk_bbf;                                // 0xBBF
  u8 shakeAmp;                               // 0xBC0
  u8 unk_bc1;                                // 0xBC1
  u8 shakeAngle;                             // 0xBC2
  u8 unk_bc3;                                // 0xBC3
  Vec3 centerPos;                            // 0xBC4, '.r=0,0,0'
  Vec3 unk_bcc;                              // 0xBCC
  s32 unk_bd4;                               // 0xBD4, centerPos から見た角度の 256 倍
  s32 unk_bd8;                               // 0xBD8
  s32 unk_bdc;                               // 0xBDC
  u32 unk_be0;                               // 0xBE0, centerPos からの距離の 256 倍
  u32 unk_be4;                               // 0xBE4
  u32 unk_be8;                               // 0xBE8
  u16 unk_bec;                               // 0xBEC
  u16 unk_bee;                               // 0xBEE
  PathNode* pathNodes;                       // 0xBF0
  u8 pathIdx;                                // 0xBF4
  u8 pathNodeCount;                          // 0xBF5
  u8 unk_bf6;                                // 0xBF6
  u8 unk_bf7;                                // 0xBF7
  struct Entity0805e67c* entity0805e67c;     // 0xBF8
  struct Entity0805ee80* entity0805ee80;     // 0xBFC
  s32 unk_c00;                               // 0xC00
} ShadeMan;
static_assert(sizeof(ShadeMan) == 3076);

// 点滅をやめて unk_38c の bit8 を立てる
// 残差は命令の並び順だけ (17 対 17), 原典は定数 0x100 を unk_38c のアドレス計算より前に作る
// 0x100 を左に書く形 / AuxSprite_SetFlags 経由 / MainSprite* ローカル / SET_FLAGS は試済
NON_MATCH void FUN_0821bd14(ShadeMan* p) {
#ifdef NONMATCHING_C
  MainSprite_ClearFlags(&p->sprite, SPRFLAG_BLINK_ODD);
  p->unk_38c |= 0x100;
#else
  INCFUNC("asm/func/FUN_0821bd14.inc");
#endif
}

const u8 u8_ARRAY_085affa8[16] = {9, 9, 9, 9, 6, 6, 11, 11, 6, 8, 9, 9, 10, 10, 6, 6};  // 0x085affa8

void FUN_0821ce18(ShadeMan*);
void FUN_0821ce7c(ShadeMan*);
void FUN_0821d074(ShadeMan*);
void FUN_0821d0c8(ShadeMan*);
void FUN_0821d124(ShadeMan*);
void FUN_0821d18c(ShadeMan*);
void FUN_0821d1e0(ShadeMan*);
void FUN_0821d240(ShadeMan*);
void FUN_0821d294(ShadeMan*);
void FUN_0821d2f4(ShadeMan*);
void FUN_0821d348(ShadeMan*);
void FUN_0821d39c(ShadeMan*);
void FUN_0821d3fc(ShadeMan*);

// clang-format off
void (*const PTR_ARRAY_085affb8[13])(ShadeMan*) = {
    FUN_0821ce18,
    FUN_0821ce7c,
    FUN_0821d074,
    FUN_0821d0c8,
    FUN_0821d124,
    FUN_0821d18c,
    FUN_0821d1e0,
    FUN_0821d240,
    FUN_0821d294,
    FUN_0821d2f4,
    FUN_0821d348,
    FUN_0821d39c,
    FUN_0821d3fc,
}; // 0x085affb8
// clang-format on

void FUN_0821d4b4(ShadeMan*);
void FUN_0821d578(ShadeMan*);

void (*const PTR_ARRAY_085affec[2])(ShadeMan*) = {
    FUN_0821d4b4,
    FUN_0821d578,
};  // 0x085affec

void FUN_0821d5a8(ShadeMan*);
void FUN_0821d5d8(ShadeMan*);
void FUN_0821d630(ShadeMan*);
void FUN_0821d660(ShadeMan*);
void FUN_0821d690(ShadeMan*);
void FUN_0821d6c0(ShadeMan*);
void FUN_0821d6f0(ShadeMan*);

// clang-format off
void (*const PTR_ARRAY_085afff4[7])(ShadeMan*) = {
    FUN_0821d5a8,
    FUN_0821d5d8,
    FUN_0821d630,
    FUN_0821d660,
    FUN_0821d690,
    FUN_0821d6c0,
    FUN_0821d6f0,
};  // 0x085afff4
// clang-format on

void FUN_0821d744(ShadeMan*);

void (*const PTR_ARRAY_085b0010[1])(ShadeMan*) = {
    FUN_0821d744,
};  // 0x085b0010

void FUN_0821d760(ShadeMan*);

void (*const PTR_ARRAY_085b0014[1])(ShadeMan*) = {
    FUN_0821d760,
};  // 0x085b0014

void FUN_0821d77c(ShadeMan*);

void (*const PTR_ARRAY_085b0018[1])(ShadeMan*) = {
    FUN_0821d77c,
};  // 0x085b0018

void FUN_0821d798(ShadeMan*);
void FUN_0821d7c8(ShadeMan*);
void FUN_0821d7e4(ShadeMan*);

void (*const PTR_ARRAY_085b001c[3])(ShadeMan*) = {
    FUN_0821d798,
    FUN_0821d7c8,
    FUN_0821d7e4,
};  // 0x085b001c

void FUN_0821deec(ShadeMan*);
void FUN_0821df64(ShadeMan*);
void FUN_0821dfdc(ShadeMan*);
void FUN_0821e0a8(ShadeMan*);
void FUN_0821e220(ShadeMan*);
void FUN_0821e3f0(ShadeMan*);
void FUN_0821e738(ShadeMan*);
void FUN_0821ea6c(ShadeMan*);
void FUN_0821f0e4(ShadeMan*);
void FUN_0821f818(ShadeMan*);
void FUN_0821ff34(ShadeMan*);
void FUN_082201ec(ShadeMan*);
void FUN_08220430(ShadeMan*);
void FUN_082206a8(ShadeMan*);
void FUN_08220758(ShadeMan*);
void FUN_0822098c(ShadeMan*);
void FUN_082209cc(ShadeMan*);
void FUN_08220a68(ShadeMan*);
void FUN_08220b64(ShadeMan*);
void FUN_08220bf0(ShadeMan*);
void FUN_08220cc4(ShadeMan*);
void FUN_08220de0(ShadeMan*);

// clang-format off
void (*const PTR_ARRAY_085b0028[22])(ShadeMan*) = {
    FUN_0821deec,
    FUN_0821df64,
    FUN_0821dfdc,
    FUN_0821e0a8,
    FUN_0821e220,
    FUN_0821e3f0,
    FUN_0821e738,
    FUN_0821ea6c,
    FUN_0821f0e4,
    FUN_0821f818,
    FUN_0821ff34,
    FUN_082201ec,
    FUN_08220430,
    FUN_082206a8,
    FUN_08220758,
    FUN_0822098c,
    FUN_082209cc,
    FUN_08220a68,
    FUN_08220b64,
    FUN_08220bf0,
    FUN_08220cc4,
    FUN_08220de0,
}; // 0x085b0028
// clang-format on

void FUN_0821c918(ShadeMan*);
void ShadeMan_SetMotion(ShadeMan* p, u32 next, bool8 force);
s32 FUN_0807ab64(Player* player, Vec3* pos, Vec3* param_3, s32 param_4, u8 param_5, s32 param_6, s32 param_7, s32 param_8, u32 param_9);
s32 FUN_080dc0a0(Vec3* basePos, Vec3* offset, Vec3* unkRand, Vec3* offsetRand, s32 count, u32 priority);
void FUN_0823b880(s32 n);
DirS32 Player_GetDpadFacing(Player* p);
struct Entity0805e67c* Entity0805e67c_Create(void);
struct Entity0805ee80* Entity0805ee80_Create(s32 param_1);
void FUN_0805e6bc(struct Entity0805e67c* p, Vec3* pos, s32 angle, s32 speed, s32 power, s32 param_6, s32 param_7);
void FUN_0805eee4(struct Entity0805ee80* p, u32 angle, s32 param_3, s32 power, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, Vec3* pos);
void FUN_0805e940(struct Entity0805e67c* p, Vec3* pos, u32 angle, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 count);
void Map_ReadPathNodePos(Vec3* dst, PathNode* nodes, u8 idx);
void FUN_0823b980(s32 n, Vec3* pos);
extern const u16 u16_ARRAY_08252864[16];
extern const u8 u8_ARRAY_08252884[16];
void FUN_08221938(ShadeMan* p);
void ShadeMan_HandleDamage(ShadeMan* p);
void ShadeMan_PollMessages(ShadeMan* p);
s32 Map_FindFarthestPathNode(Vec3* dst, Vec3* pos, s32 pathIdx);
s32 FUN_0805fe7c(HitboxData* hitbox, s32 param_2, s32 param_3, Vec3* pos, Vec3* param_5, s32 param_6);
u32 FUN_0807ac74(Player* p, unknown* param_2, u16 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, u32 param_8);
void ShadeMan_SetSubState0(ShadeMan* p, u32 subState0, u32 subState1, u32 subState2, u32 duration);
void FUN_0822129c(ShadeMan*);
void FUN_0821d800(ShadeMan*);
void ShadeMan_UpdateMotion(ShadeMan*);
void FUN_08221450(ShadeMan*);

void FUN_0821bd3c(void) {
  ShadeMan* p = Boss_Get(BOSS_SHADEMAN);

  if (p != NULL) {
    p->unk_3d9++;
  }
}

// from から見た to の向きと xz 平面上の距離を求める
void FUN_0821bd5c(Vec3* from, Vec3* to, u8* angle, u16* dist) {
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

// 残差は ofs のアドレスの持ち方 (60/60), FUN_0803c454 と同じ
NON_MATCH void FUN_0821bda4(Vec3* dst, Vec3* center, u8 angle, u16 radius) {
#ifdef NONMATCHING_C
  Vec3 ofs;

  Vec3_SetPolar(&ofs, angle, radius);
  Vec3_Sum(dst, center, &ofs);
#else
  INCFUNC("asm/func/FUN_0821bda4.inc");
#endif
}

// centerPos を中心に target まで duration フレームかけて回り込む準備をする
void FUN_0821be24(ShadeMan* p, Vec3* target, u32 duration) {
  u8 angle;
  u16 dist;
  s32 diff;

  p->unk_bcc = *target;
  FUN_0821bd5c(&p->centerPos, &p->unk_bcc, &angle, &dist);
  p->unk_bd8 = angle << 8;
  p->unk_be4 = dist << 8;
  p->unk_bec = 0;
  p->unk_bee = duration;
  diff = p->unk_bd8 - p->unk_bd4;
  if (abs(diff) > 0x8000) {
    if (diff < 0) {
      diff += 0x10000;
    } else {
      diff -= 0x10000;
    }
    p->unk_bd8 = p->unk_bd4 + diff;
  }
  p->unk_bdc = p->unk_bd4;
  p->unk_be8 = p->unk_be0;
}

// 今の位置を centerPos から見た角度と距離で控える
void FUN_0821bef0(ShadeMan* p) {
  u8 angle;
  u16 dist;

  FUN_0821bd5c(&p->centerPos, &p->base.mover.pos, &angle, &dist);
  p->unk_bd4 = angle << 8;
  p->unk_be0 = dist << 8;
}

// 回り込みの角度と距離を 1 フレーム分補間する
void FUN_0821bf34(ShadeMan* p) {
  s32 rest;

  p->unk_bec++;
  rest = p->unk_bee - p->unk_bec;
  p->unk_bd4 = Div(p->unk_bdc * rest + p->unk_bd8 * p->unk_bec, p->unk_bee);
  p->unk_be0 = Div(p->unk_be8 * rest + p->unk_be4 * p->unk_bec, p->unk_bee);
  if (p->unk_bd4 < 0) {
    p->unk_bd4 += 0x10000;
  }
  p->unk_bd4 &= 0xFFFF;
}

// 控えた角度と距離から位置を作り直す
void FUN_0821bfc8(ShadeMan* p) { FUN_0821bda4(&p->base.mover.pos, &p->centerPos, FixToInt(8, p->unk_bd4), p->unk_be0 >> 8); }

// 移動に使う経路を切り替える
void FUN_0821c010(ShadeMan* p, u32 pathIdx) {
  Path* path = Map_GetPath(pathIdx);

  p->pathNodes = Map_GetPathNodes(path);
  p->pathIdx = pathIdx;
  p->pathNodeCount = path->nodeCount;
}

// 今の経路で pos に最も近いノードを dst に入れて番号を返す
s32 FUN_0821c044(ShadeMan* p, Vec3* pos, Vec3* dst) {
  PathNode* node = p->pathNodes;
  s32 best = 100000000;
  s32 ret = 0;
  s32 i;

  for (i = 0; i < p->pathNodeCount; i++) {
    s32 dx = node->x - pos->x;
    s32 dz = node->y - pos->z;
    s32 d = dx * dx + dz * dz;

    if (d < best) {
      best = d;
      ret = i;
      dst->x = node->x;
      dst->z = node->y;
    }
    node++;
  }
  return ret;
}

// 今の経路で pos から最も遠いノードを dst に入れて番号を返す
s32 FUN_0821c0c4(ShadeMan* p, Vec3* pos, Vec3* dst) {
  PathNode* node = p->pathNodes;
  s32 best = 0;
  s32 ret = 0;
  s32 i;

  for (i = 0; i < p->pathNodeCount; i++) {
    s32 dx = node->x - pos->x;
    s32 dz = node->y - pos->z;
    s32 d = dx * dx + dz * dz;

    if (d > best) {
      best = d;
      ret = i;
      dst->x = node->x;
      dst->z = node->y;
    }
    node++;
  }
  return ret;
}

// 原典は unk_38c の番地を r3 に残して最後の判定で使い回す (119/117)
NON_MATCH void FUN_0821c140(ShadeMan* p) {
#ifdef NONMATCHING_C
  MainSprite* sprite = &p->sprite;

  if (TEST_FLAGS(p->base.flags, BOSSFLAG_HIDDEN)) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
  if (TEST_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW)) {
    AuxShadow_Hide(&p->shadow);
  } else {
    AuxShadow_Show(&p->shadow);
  }
  sprite->pos = p->base.mover.pos;
  if (TEST_FLAGS(p->unk_38c, 0x20000)) {
    p->unk_3bc += 2;
    if (p->unk_3bc > 255) {
      p->unk_3bc -= 256;
    }
  }
  sprite->pos.y += POLAR_Z(50, p->unk_3bc + 0xC0) + 50;
  if (!TEST_FLAGS(p->unk_38c, 0x40000)) {
    Boss_AdvanceAnim(&p->base, sprite, &p->gfx);
    p->unk_3ba++;
  }
#else
  INCFUNC("asm/func/FUN_0821c140.inc");
#endif
}

// 残差は mode 7 の片側で pltt の値と格納先を作る順 (47/47), 三項演算子や rgb555* ローカルは試済
NON_MATCH void FUN_0821c238(ShadeMan* p, s32 mode) {
#ifdef NONMATCHING_C
  switch (mode) {
    case 7: {
      if (!p->unk_388) {
        p->sprite.pltt = &gObjPlttData[7 * 16];
      } else {
        p->sprite.pltt = &gObjPlttData[15 * 16];
      }
      break;
    }
    case 0: {
      p->sprite.pltt = p->pltt[0];
      break;
    }
    case 1: {
      p->sprite.pltt = p->pltt_600[0];
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0821c238.inc");
#endif
}

// 残差は to の選び方の並びと to のスタック退避 (158/160)
NON_MATCH void FUN_0821c2a0(ShadeMan* p, s32 mode, s32 t, s32 total) {
#ifdef NONMATCHING_C
  rgb555* dst = p->pltt_600[0];

  if (p->unk_3f0 <= 0) {
    rgb555* src = !p->unk_388 ? &gObjPlttData[7 * 16] : &gObjPlttData[15 * 16];
    rgb555* to;
    s32 rest;
    s32 r2, g2, b2;
    s32 i;

    FUN_0821c238(p, 1);
    t *= 4;
    total *= 4;
    rest = total - t;
    if (mode == 1) {
      to = &gObjPlttData[11 * 16];
    } else if (mode == 2) {
      to = &gObjPlttData[15 * 16];
    } else {
      to = NULL;
    }
    b2 = 0;
    g2 = 0;
    r2 = 0;
    for (i = 0; i < 32; i++) {
      s32 r = *src & 0x1F;
      s32 g = (*src >> 5) & 0x1F;
      s32 b = (*src >> 10) & 0x1F;

      if (to != NULL) {
        r2 = *to & 0x1F;
        g2 = (*to >> 5) & 0x1F;
        b2 = (*to >> 10) & 0x1F;
        to++;
      }
      r = Div(t * r + r2 * rest, total) & 0x1F;
      g = Div(t * g + g2 * rest, total) & 0x1F;
      b = Div(t * b + b2 * rest, total) & 0x1F;
      *dst = r | (b << 10 | g << 5);
      src++;
      dst++;
    }
  }
#else
  INCFUNC("asm/func/FUN_0821c2a0.inc");
#endif
}

// angle から向きを決めて animIdx を再生する, mode で向きの付け方を選ぶ
void ShadeMan_PlayAnim(ShadeMan* p, s32 animIdx, s32 mode, bool8 restart, bool8 once, bool8 flag) {
  Boss* boss = &p->base;
  u32 flags = (restart || p->animIdx != animIdx) ? 4 : 1;
  u32 playMode;

  flags |= flag << 1;
  playMode = once ? 1 : 2;
  p->animIdx = animIdx;
  p->unk_3ba = 0;
  boss->facing = Angle_ToDir4(p->angle);
  boss->dir = Angle_ToDir8(p->angle);
  switch (mode) {
    case 0: {
      Boss_PlayAnimFlip(boss, &p->sprite, &p->gfx, animIdx, playMode, flags);
      break;
    }
    case 1: {
      Boss_PlayAnimFacing(boss, &p->sprite, &p->gfx, animIdx, playMode, mode, flags);
      break;
    }
    case 2: {
      Boss_PlayAnimDir8(boss, &p->sprite, &p->gfx, animIdx, playMode, 1, flags);
      break;
    }
    default: {
      Boss_PlayAnim(boss, &p->sprite, &p->gfx, animIdx, playMode, flags);
      break;
    }
  }
}

// 原典は unk_ab と flags の判定を | でまとめ, 1 つ目と 2 つ目で p の写しを使い分ける
NON_MATCH void FUN_0821c520(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  HitboxData* hitbox;

  if (TEST_FLAGS(p->unk_38c, 0x20)) {
    SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_UNK_19);
  }
  hitbox = &p->hurtbox;
  if (boss->unk_ab || TEST_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX)) {
    Hitbox_SetFlags(hitbox, HBFLAG_HIDDEN);
  } else {
    Hitbox_ClearFlags(hitbox, HBFLAG_HIDDEN);
    Hitbox_SetPos(hitbox, &boss->mover.pos, 0);
    p->hurtbox.angle = p->angle;
  }
  hitbox = &p->hurtbox2;
  if (boss->unk_ab || TEST_FLAGS(boss->flags, BOSSFLAG_UNK_19)) {
    Hitbox_SetFlags(hitbox, HBFLAG_HIDDEN);
  } else {
    Hitbox_ClearFlags(hitbox, HBFLAG_HIDDEN);
    Hitbox_SetPos(hitbox, &boss->mover.pos, 0);
  }
#else
  INCFUNC("asm/func/FUN_0821c520.inc");
#endif
}

// 残差は pos を指す sp の写しを作る位置だけ (110/110), FUN_0821cd9c と同じ
NON_MATCH void FUN_0821c5d4(ShadeMan* p) {
#ifdef NONMATCHING_C
  if (!p->base.unk_ab) {
    u32 angle = p->angle;
    HitboxData* hitbox = &p->hitbox;

    if (!TEST_FLAGS(p->base.flags, BOSSFLAG_NO_HITBOX)) {
      Hitbox_SetPos(hitbox, &p->base.mover.pos, 0);
      p->hitbox.angle = angle;
      Hitbox_Register(hitbox);
    }
    if (TEST_FLAGS(p->unk_38c, 0x10000)) {
      Vec3 pos;

      hitbox = &p->hitbox2;
      Vec3_SetPolar(&pos, angle, 100);
      Vec3_Sum(&pos, &p->base.mover.pos, &pos);
      Hitbox_SetPos(hitbox, &pos, 0);
      hitbox->angle = angle;
      Hitbox_Register(hitbox);
    }
  }
#else
  INCFUNC("asm/func/FUN_0821c5d4.inc");
#endif
}

void ShadeMan_OnHurt(HitboxData* a, HitboxData* b, ShadeMan* p) {
  Boss* boss = &p->base;

  if (!TEST_FLAGS(boss->flags, BOSSFLAG_UNK_19)) {
    Hitbox_ApplyDamage(a, b);
    p->damage = b->damage;
    p->hurtAngle = a->angle;
    Boss_SetWeaponExpMask(boss, a->weakness);
    Boss_SetHurtAttributes(boss, a->attributes);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0);
  if (a->attributes & 1) {
    boss->flags |= BOSSFLAG_VISIBLE;
  }
  if (b->hitResult & 8) {
    SET_FLAGS(boss->flags, BOSSFLAG_HITBOX2);
  }
}

void FUN_0821c740(void) {}

void FUN_0821c744(HitboxData* a, HitboxData* b, ShadeMan* p) { SET_FLAGS(p->unk_38c, 0x1000000); }

// 画面座標の投影と残像の初期化の並びがずれる (206/198)
NON_MATCH void ShadeMan_Init_Helper_0821c758(ShadeMan* p, Vec3* pos, u32 angle) {
#ifdef NONMATCHING_C
  MainSpriteGfxFile* f;
  Vec3 screen;
  s32 x, z, a, b;
  s32 i;

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_SHADEMAN);
  p->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx, f);
  MainSprite_Add(&p->sprite, &p->gfx, 0, 0, 2, 0, 60, pos);
  p->angle = angle;
  ShadeMan_PlayAnim(p, 0, 2, 1, 1, 0);
  p->unk_3bc = 0;
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_DJANGO_SABATA);
  p->gfx_b34 = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx_b34, f);
  x = pos->x >> 1;
  z = pos->z >> 1;
  a = FixToInt(8, (x + z) * 48);
  b = FixToInt(8, pos->y * 24);
  screen.x = FixToInt(8, (x - z) * 48) - gCameraVpCoords.x + 120;
  screen.y = (a - b) - gCameraVpCoords.y + 90;
  screen.z = (a + b) - gCameraVpCoords.z;
  MainSprite_Add(&p->sprite_b54, &p->gfx_b34, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 2, 0, 60, &screen);
  for (i = 0; i < 8; i++) {
    ShadeManAfterimage* a2 = &p->afterimages[i];

    a2->active = FALSE;
    a2->timer = 0;
    MainSprite_Add(&a2->sprite, &p->gfx, 0, SPRFLAG_HIDDEN, 2, 0, 60, pos);
    a2->sprite.flags |= (i & 1) == 0 ? SPRFLAG_BLINK_EVEN : SPRFLAG_BLINK_ODD;
  }
#else
  INCFUNC("asm/func/ShadeMan_Init_Helper_0821c758.inc");
#endif
}

// 本体と残像のスプライトを外す
void FUN_0821c918(ShadeMan* p) {
  s32 i;

  MainSprite_Remove(&p->sprite);
  MainSprite_Remove(&p->sprite_b54);
  for (i = 0; i < 8; i++) {
    MainSprite_Remove(&p->afterimages[i].sprite);
  }
}

void ShadeMan_InitHurtboxes(ShadeMan* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 0x60, 0x80, 0x60);
  VEC3_SET(offset, 0, 0x80, 0);
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &p->base.mover.pos, 0);
  Hitbox_SetHandler(hurtbox, ShadeMan_OnHurt, p);
  Hitbox_SetPowerAndAttributes(hurtbox, power, HBATTR_IMMORTAL | HBATTR_DARK, HBATTR_SOL);
  Hitbox_Register(hurtbox);
  hurtbox = &p->hurtbox2;
  VEC3_SET(halfSize, 0x100, 0x80, 0x100);
  VEC3_SET(offset, 0, 0x80, 0);
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_1 | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &p->base.mover.pos, 0);
  Hitbox_SetHandler(hurtbox, FUN_0821c740, p);
  Hitbox_SetPowerAndAttributes(hurtbox, 0, 0, 0);
  Hitbox_Register(hurtbox);
}

void ShadeMan_InitHitboxes(ShadeMan* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, 0x40, 0x80, 0x40);
  VEC3_SET(offset, 0, 0x80, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &p->base.mover.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_0821c744, p);
  Hitbox_SetAttack(hitbox, p->hitboxPower, p->hitboxKnockback, 0, 0, p->hitboxUnk44);
  hitbox = &p->hitbox2;
  VEC3_SET(halfSize, 0xA0, 0x80, 0xA0);
  VEC3_SET(offset, 0, 0x80, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &p->base.mover.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_0821c744, p);
  Hitbox_SetAttack(hitbox, p->hitbox2Power, p->hitbox2Knockback, 0, HBATTR_17 | HBATTR_18, p->hitbox2Unk44);
}

// 一通り書けたが分岐の並びと番地の作り方がずれる
NON_MATCH void FUN_0821cb90(ShadeMan* p) {
#ifdef NONMATCHING_C
  if (!p->unk_388) {
    switch (u8_ARRAY_085affa8[p->unk_809 * 2]) {
      case 9: {
        ShadeMan_SetSubState0(p, 0, 0, 9, 0);
        break;
      }
      case 6: {
        ShadeMan_SetSubState0(p, 0, 0, 6, 60);
        p->unk_806 = 61;
        break;
      }
      case 10: {
        ShadeMan_SetSubState0(p, 0, 0, 10, 60);
        break;
      }
      case 11: {
        ShadeMan_SetSubState0(p, 0, 0, 11, 0);
        p->unk_806 = 61;
        break;
      }
    }
  } else {
    switch (u8_ARRAY_085affa8[p->unk_809 * 2 + 1]) {
      case 6: {
        ShadeMan_SetSubState0(p, 0, 0, 6, 60);
        p->unk_806 = 45;
        break;
      }
      case 8: {
        ShadeMan_SetSubState0(p, 0, 0, 8, 60);
        p->unk_806 = 45;
        p->unk_80c = 0;
        if (!(p->unk_38c & 0x20)) {
          p->unk_809++;
        } else {
          p->unk_38c &= ~0x20;
        }
        p->unk_3db = 0;
        break;
      }
      case 9: {
        ShadeMan_SetSubState0(p, 0, 0, 9, 0);
        break;
      }
      case 10: {
        ShadeMan_SetSubState0(p, 0, 0, 10, 60);
        break;
      }
      case 11: {
        ShadeMan_SetSubState0(p, 0, 0, 11, 0);
        p->unk_806 = 90;
        break;
      }
    }
    if (p->unk_80c > 1499) {
      ShadeMan_SetSubState0(p, 0, 0, 8, 60);
      p->unk_806 = 57;
      p->unk_80c = 0;
    }
    if (p->unk_810 > 2999) {
      ShadeMan_SetSubState0(p, 0, 0, 7, 60);
      p->unk_80c = 0;
      p->unk_810 = 0;
    }
  }
#else
  INCFUNC("asm/func/FUN_0821cb90.inc");
#endif
}

// 残差は mid を指す sp の写しを作る位置だけ (58/58)
NON_MATCH void FUN_0821cd9c(ShadeMan* p) {
#ifdef NONMATCHING_C
  Vec3 mid;

  Div(p->base.hp * 1000, p->base.maxHP);
  Vec3_Sum(&mid, &p->base.mover.pos, p->base.playerPos[0]);
  mid.x >>= 1;
  mid.y >>= 1;
  mid.z >>= 1;
  Map_FindFarthestPathNode(&p->unk_bcc, &mid, 4);
#else
  INCFUNC("asm/func/FUN_0821cd9c.inc");
#endif
}

void FUN_0821ce18(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 0, TRUE);
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    u32 duration = !p->unk_388 ? 60 : 45;

    ShadeMan_SetSubState0(p, 0, 0, 1, duration);
  }
}

// 原典は case 6 が case 0/1/5 の unk_800 == 0 側に飛び込む形 (198/189)
NON_MATCH void FUN_0821ce7c(ShadeMan* p) {
#ifdef NONMATCHING_C
  if (Boss_EnterSubState(&p->base)) {
    Vec3 node;
    s32 idx;

    switch (p->unk_809) {
      case 2:
      case 4:
      case 7: {
        FUN_0821c010(p, 1);
        idx = FUN_0821c044(p, &p->base.mover.pos, &node);
        if (!(p->unk_390 & 1)) {
          if (--idx < 0) {
            idx = p->pathNodeCount - 1;
          }
        } else {
          if (++idx >= p->pathNodeCount) {
            idx = 0;
          }
        }
        p->unk_bf6 = idx;
        Map_ReadPathNodePos(&p->unk_bcc, p->pathNodes, p->unk_bf6);
        break;
      }
      case 3: {
        FUN_0821c010(p, 10);
        idx = FUN_0821c044(p, p->base.playerPos[0], &node);
        if (idx == p->unk_bf6) {
          p->unk_bf6 = FUN_0821c044(p, &node, &p->unk_bcc);
        } else {
          p->unk_bf6 = idx;
          p->unk_bcc = node;
        }
        break;
      }
      case 6: {
        FUN_0821c010(p, 4);
        idx = FUN_0821c044(p, &p->base.mover.pos, &node);
        if (!(p->unk_390 & 1)) {
          idx += 2;
          if (idx >= p->pathNodeCount) {
            idx -= p->pathNodeCount;
          }
        } else {
          idx -= 2;
          if (idx < 0) {
            idx += p->pathNodeCount;
          }
        }
        p->unk_bf6 = idx;
        Map_ReadPathNodePos(&p->unk_bcc, p->pathNodes, p->unk_bf6);
        break;
      }
      default: {
        p->unk_809 = 0;
      }
      case 0:
      case 1:
      case 5: {
        if (p->unk_800 == 0) {
          FUN_0821c010(p, 4);
          idx = FUN_0821c044(p, &p->base.mover.pos, &node);
          if (!(p->unk_390 & 1)) {
            idx += 2;
            if (idx >= p->pathNodeCount) {
              idx -= p->pathNodeCount;
            }
          } else {
            idx -= 2;
            if (idx < 0) {
              idx += p->pathNodeCount;
            }
          }
          p->unk_bf6 = idx;
          Map_ReadPathNodePos(&p->unk_bcc, p->pathNodes, p->unk_bf6);
        } else {
          p->unk_800 = 0;
          FUN_0821c010(p, 4);
          p->unk_bf6 = 0;
          Map_ReadPathNodePos(&p->unk_bcc, p->pathNodes, 0);
        }
        break;
      }
    }
    ShadeMan_SetMotion(p, 2, TRUE);
  }
  if (p->unk_38c & 0x10) {
    FUN_0821cb90(p);
  }
#else
  INCFUNC("asm/func/FUN_0821ce7c.inc");
#endif
}

void FUN_0821d074(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 3, TRUE);
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    ShadeMan_SetSubState0(p, 0, 0, 0, 61);
  }
}

void FUN_0821d0c8(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    FUN_0821cd9c(p);
    ShadeMan_SetMotion(p, 4, TRUE);
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    ShadeMan_SetSubState0(p, 0, 0, 0, 61);
  }
}

void FUN_0821d124(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 5, TRUE);
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    p->unk_80c = 0;
    p->unk_810 = 0;
    ShadeMan_SetSubState0(p, 0, 0, 0, 31);
  }
}

void FUN_0821d18c(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 6, TRUE);
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    ShadeMan_SetSubState0(p, 0, 0, 0, 61);
  }
}

void FUN_0821d1e0(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 7, TRUE);
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    ShadeMan_SetSubState0(p, 0, 0, 0, p->unk_806);
  }
}

void FUN_0821d240(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 8, TRUE);
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    ShadeMan_SetSubState0(p, 0, 0, 0, 61);
  }
}

void FUN_0821d294(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 9, TRUE);
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    ShadeMan_SetSubState0(p, 0, 0, 0, p->unk_806);
  }
}

void FUN_0821d2f4(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 10, TRUE);
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    ShadeMan_SetSubState0(p, 0, 0, 0, 61);
  }
}

void FUN_0821d348(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 11, TRUE);
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    ShadeMan_SetSubState0(p, 0, 0, 0, 61);
  }
}

void FUN_0821d39c(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 12, TRUE);
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    ShadeMan_SetSubState0(p, 0, 0, 0, p->unk_806);
  }
}

// 残差は p と &unk_bf6 のレジスタが逆, 121 を呼び出し前に r4 へ作る (77/77)
NON_MATCH void FUN_0821d3fc(ShadeMan* p) {
#ifdef NONMATCHING_C
  if (Boss_EnterSubState(&p->base)) {
    Vec3 far;
    s32 idx;

    FUN_0821c010(p, 10);
    idx = FUN_0821c0c4(p, p->base.playerPos[0], &far);
    if (idx == p->unk_bf6) {
      p->unk_bf6 = FUN_0821c044(p, &far, &p->unk_bcc);
    } else {
      p->unk_bf6 = idx;
      p->unk_bcc = far;
    }
    ShadeMan_SetMotion(p, 4, TRUE);
    p->stateDuration = 0;
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    ShadeMan_SetSubState0(p, 0, 0, 11, 0);
    p->unk_806 = 121;
  }
#else
  INCFUNC("asm/func/FUN_0821d3fc.inc");
#endif
}

// 原典は unk_3a8 の番地を case 0 の書き込みで作り直す, こちらは switch の読みと共有して r7 を使う (87/90)
NON_MATCH void FUN_0821d4b4(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss_EnterSubState(&p->base);
  switch (p->unk_3a8) {
    case 0: {
      bool32 entered = TEST_FLAGS(p->unk_38c, 4);

      p->unk_38c &= ~4;
      if (entered) {
        ShadeMan_SetMotion(p, 13, TRUE);
      }
      if (TEST_FLAGS(p->unk_38c, 0x10)) {
        ShadeMan_SetMotion(p, 5, TRUE);
        p->stateDuration = 60;
        p->unk_3a8 = 1;
        p->unk_38c |= 4;
      }
      break;
    }
    case 1: {
      p->unk_38c &= ~4;
      if (p->unk_38c & 0x10) {
        p->unk_80c = 0;
        p->unk_810 = 0;
        ShadeMan_SetSubState0(p, 0, 0, 0, 31);
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0821d4b4.inc");
#endif
}

void FUN_0821d578(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 14, TRUE);
  }
}

void FUN_0821d5a8(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 15, TRUE);
  }
}

void FUN_0821d5d8(ShadeMan* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    p->angle = Angle_FromDir8((u8)p->stateDuration);
    ShadeMan_SetMotion(p, 16, TRUE);
    MsgQueue_EndWait(&boss->msgQueue, 1);
  }
}

void FUN_0821d630(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 17, TRUE);
  }
}

void FUN_0821d660(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 18, TRUE);
  }
}

void FUN_0821d690(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 19, TRUE);
  }
}

void FUN_0821d6c0(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 20, TRUE);
  }
}

void FUN_0821d6f0(ShadeMan* p) {
  if (Boss_EnterSubState(&p->base)) {
    ShadeMan_SetMotion(p, 21, TRUE);
  }
  if (TEST_FLAGS(p->unk_38c, 0x10)) {
    ShadeMan_SetSubState0(p, 0, 0, 4, 30);
  }
}

void FUN_0821d744(ShadeMan* p) { PTR_ARRAY_085affb8[p->base.subState2](p); }

void FUN_0821d760(ShadeMan* p) { PTR_ARRAY_085affec[p->base.subState2](p); }

void FUN_0821d77c(ShadeMan* p) { PTR_ARRAY_085afff4[p->base.subState2](p); }

void FUN_0821d798(ShadeMan* p) {
  if (!TEST_FLAGS(u32_03002bc0[0], FLAG03002BC0_UNK_2)) {
    PTR_ARRAY_085b0010[p->base.subState1](p);
  }
}

void FUN_0821d7c8(ShadeMan* p) { PTR_ARRAY_085b0014[p->base.subState1](p); }

void FUN_0821d7e4(ShadeMan* p) { PTR_ARRAY_085b0018[p->base.subState1](p); }

void FUN_0821d800(ShadeMan* p) {
  p->base.unk_9d = 0;
  PTR_ARRAY_085b001c[p->base.subState0](p);
}

// 下位状態の3段目を差し替えて状態の長さを決める
void ShadeMan_SetSubState2(ShadeMan* p, u32 subState2, u32 duration) {
  Boss_SetSubState2(&p->base, subState2);
  p->stateDuration = duration;
  p->unk_3a8 = 0;
  SET_FLAGS(p->unk_38c, 4);
}

// 下位状態の2段目から下を差し替える
void ShadeMan_SetSubState1(ShadeMan* p, u32 subState1, u32 subState2, u32 duration) {
  p->base.subState1 = subState1;
  ShadeMan_SetSubState2(p, subState2, duration);
}

// 下位状態を3段まとめて差し替える
void ShadeMan_SetSubState0(ShadeMan* p, u32 subState0, u32 subState1, u32 subState2, u32 duration) {
  p->base.subState0 = subState0;
  ShadeMan_SetSubState1(p, subState1, subState2, duration);
}

// 残差は hurtbox と mover.pos の引数を作る順だけ (53/53)
NON_MATCH void ShadeMan_Heal(ShadeMan* p, s32 amount) {
#ifdef NONMATCHING_C
  s32 oldHP = p->base.hp;

  p->base.hp += amount;
  if (p->base.hp > p->base.maxHP) {
    p->base.hp = p->base.maxHP;
  }
  if (oldHP != p->base.hp) {
    Vec3 ofs;

    VEC3_SET(ofs, 0x10, 0, 0x10);
    FUN_0805fe7c(&p->hurtbox, amount, 1, &p->base.mover.pos, &ofs, 1);
  }
#else
  INCFUNC("asm/func/ShadeMan_Heal.inc");
#endif
}

// 原典は base を r4/r5 の 2 語に詰めたまま扱う (113/108)
NON_MATCH void FUN_0821d900(ShadeMan* p) {
#ifdef NONMATCHING_C
  Vec3 base;
  Vec3* pos;
  s32 i;

  if (p->base.facing <= 1) {
    VEC3_SET(base, 0x40, 200, -0x80);
  } else {
    VEC3_SET(base, -0x80, 200, 0x40);
  }
  pos = &p->base.mover.pos;
  for (i = 0; i < 2; i++) {
    Vec3 ofs = base;

    ofs.x += (Random() & 0x7F) - 0x40;
    ofs.z += (Random() & 0x7F) - 0x40;
    FUN_080dc0a0(pos, &ofs, NULL, NULL, 1, 1);
  }
#else
  INCFUNC("asm/func/FUN_0821d900.inc");
#endif
}

// 抱えているプレイヤーの姿を本体の位置と向きに合わせる
// 投影と姿合わせの形は書けたが一時レジスタと並びがずれる (172/177)
NON_MATCH void FUN_0821d9fc(ShadeMan* p) {
#ifdef NONMATCHING_C
  u16 poses[16];
  u8 offsets[16];
  MainSprite* held = &p->sprite_b54;
  Vec3* vp;
  Vec3* pos;
  s32 x, z, a, b, sy, sz;
  u32 idx;

  memcpy(poses, u16_ARRAY_08252864, sizeof(poses));
  memcpy(offsets, u8_ARRAY_08252884, sizeof(offsets));
  vp = &held->pos;
  pos = &p->sprite.pos;
  x = pos->x >> 1;
  z = pos->z >> 1;
  vp->x = FixToInt(8, (x - z) * 48);
  a = FixToInt(8, (x + z) * 48);
  b = FixToInt(8, pos->y * 24);
  sy = a - b;
  sz = a + b;
  vp->x = vp->x - gCameraVpCoords.x + 120;
  vp->y = sy - gCameraVpCoords.y + 90;
  vp->z = sz - gCameraVpCoords.z;
  idx = p->sprite.animCmdIdx;
  MainSprite_SetPose(held, &p->gfx_b34, poses[idx * 2 + (gStat->playerKind != 0)], 1);
  if (!p->base.xflip) {
    held->flags |= SPRFLAG_XFLIP;
    held->pos.x += offsets[idx * 2];
    held->pos.y += (s8)offsets[idx * 2 + 1];
  } else {
    held->flags &= ~SPRFLAG_XFLIP;
    held->pos.x -= offsets[idx * 2];
    held->pos.y += (s8)offsets[idx * 2 + 1];
  }
  held->pltt = gPlayerPtr[0]->unk_359 == 0 ? gPlayerPtr[0]->human.pltt : gPlayerPtr[0]->gfx_114->pltt;
#else
  INCFUNC("asm/func/FUN_0821d9fc.inc");
#endif
}

// 原典は ofs の x と z を分岐ごとに作り, x と y を 1 回の str にまとめる (if 分けや三項演算子の置き場所は試済)
NON_MATCH void FUN_0821db8c(ShadeMan* p) {
#ifdef NONMATCHING_C
  Vec3 ofs;
  s32 x = p->base.xflip ? -32 : 32;

  VEC3_SET(ofs, x, 160, x);
  p->unk_bb4 = *p->base.playerPos[0];
  FUN_0807ab64(gPlayerPtr[0], &p->base.mover.pos, &ofs, 0, 0, 0, 1, 0, 0);
#else
  INCFUNC("asm/func/FUN_0821db8c.inc");
#endif
}

// 原典は ofs の x と z を分岐ごとに作り, x と y を 1 回の str にまとめる (if 分けや三項演算子の置き場所は試済)
NON_MATCH void FUN_0821dc14(ShadeMan* p) {
#ifdef NONMATCHING_C
  Vec3 ofs;
  s32 x;

  MainSprite_Show(&p->sprite_b54);
  FUN_0821d9fc(p);
  x = p->base.xflip ? -32 : 32;
  VEC3_SET(ofs, x, 160, x);
  FUN_0807ab64(gPlayerPtr[0], &p->base.mover.pos, &ofs, 0, 0, 0, 1, 0, 0);
#else
  INCFUNC("asm/func/FUN_0821dc14.inc");
#endif
}

void FUN_0821dca0(ShadeMan* p) {
  Vec3* pos;
  Vec3* target;

  MainSprite_Hide(&p->sprite_b54);
  pos = &p->base.mover.pos;
  target = &p->unk_bb4;
  FUN_0807ac74(gPlayerPtr[0], target, 50, ArcTan2_8(target->x - pos->x, target->z - pos->z), 50, 0, 0, 0);
}

// ofs の x と z を分岐ごとに作る形が FUN_0821db8c と同じく出ない
NON_MATCH void FUN_0821dd00(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  if (p->sprite.animCmdTimer != 0) {
    FUN_0821d9fc(p);
  }
  if (p->sprite.animCmdTimer == 1 && (p->sprite.animCmdIdx == 2 || p->sprite.animCmdIdx == 4 || p->sprite.animCmdIdx == 6)) {
    Vec3 ofs;
    s32 x = boss->xflip ? -32 : 32;
    s32 amount;

    VEC3_SET(ofs, x, 160, x);
    amount = FUN_0807ab64(gPlayerPtr[0], &p->base.mover.pos, &ofs, 0, 0, 0, 1, p->unk_3d0, 2);
    FUN_0821d900(p);
    ShadeMan_Heal(p, amount);
    PlaySound_082406e0(SONG_844);
  }
#else
  INCFUNC("asm/func/FUN_0821dd00.inc");
#endif
}

// 空いている残像に今の姿を写して lifetime フレーム出す
void ShadeMan_SpawnAfterimage(ShadeMan* p, s32 kind, u32 lifetime) {
  Boss* boss = &p->base;
  s32 i;

  for (i = 0; i < 8; i++) {
    ShadeManAfterimage* a = &p->afterimages[i];

    if (a->active != TRUE) {
      MainSprite* sprite;

      a->active = TRUE;
      a->timer = lifetime;
      sprite = &a->sprite;
      sprite->pos = p->sprite.pos;
      MainSprite_SetPose(sprite, &p->gfx, p->sprite.animCmds->poseIdx, 1);
      if (boss->xflip == TRUE) {
        sprite->flags |= SPRFLAG_XFLIP;
      } else {
        sprite->flags &= ~SPRFLAG_XFLIP;
      }
      sprite->flags &= ~SPRFLAG_HIDDEN;
      switch (kind) {
        case 0: {
          sprite->plttID = 0x4100;
          if (!p->unk_388) {
            sprite->pltt = &gObjPlttData[7 * 16];
          } else {
            sprite->pltt = &gObjPlttData[15 * 16];
          }
          break;
        }
        case 1: {
          sprite->plttID = 0x4110;
          sprite->pltt = &gObjPlttData[11 * 16];
          break;
        }
      }
      return;
    }
  }
}

// 残像の寿命を減らして切れたものを隠す
void ShadeMan_UpdateAfterimages(ShadeMan* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    ShadeManAfterimage* a = &p->afterimages[i];

    if (a->active && --a->timer <= 0) {
      MainSprite_Hide(&a->sprite);
      a->active = FALSE;
    }
  }
}

void FUN_0821deec(ShadeMan* p) {
  p->unk_38c &= ~1;
  p->unk_38c |= 0x20000;
  if (p->unk_3a0 == 0) {
    p->unk_38c &= ~2;
    p->angle = p->base.mover.angle;
    ShadeMan_PlayAnim(p, 0, 2, 0, 1, 0);
    if (p->unk_3a4 >= p->stateDuration) {
      SET_FLAGS(p->unk_38c, 0x10);
    }
  }
}

void FUN_0821df64(ShadeMan* p) {
  p->unk_38c &= ~1;
  p->unk_38c |= 0x20000;
  if (p->unk_3a0 == 0) {
    p->unk_38c &= ~2;
    p->angle = p->base.mover.angle;
    ShadeMan_PlayAnim(p, 0, 2, 0, 1, 0);
    if (p->unk_3a4 >= p->stateDuration) {
      SET_FLAGS(p->unk_38c, 0x10);
    }
  }
}

void FUN_0821dfdc(ShadeMan* p) {
  bool32 first = TEST_FLAGS(p->unk_38c, 1);

  p->unk_38c &= ~1;
  if (first) {
    FUN_0821bef0(p);
    FUN_0821be24(p, &p->unk_bcc, 60);
    PlaySound_082406e0(SONG_840);
  }
  SET_FLAGS(p->unk_38c, 0x20000);
  if (p->unk_3a0 == 0) {
    p->unk_38c &= ~2;
    p->angle = p->base.mover.angle;
    ShadeMan_PlayAnim(p, 0, 2, 0, 1, 0);
    if (p->unk_bec < p->unk_bee) {
      FUN_0821bf34(p);
      FUN_0821bfc8(p);
    } else {
      SET_FLAGS(p->unk_38c, 0x10);
    }
    if (Mod(p->unk_3a4, 6) == 0) {
      ShadeMan_SpawnAfterimage(p, 0, 20);
    }
  }
}

// 残差は unk_38c の番地を r8 から写した r5 で最後に使うかどうか (181/179)
NON_MATCH void FUN_0821e0a8(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  bool32 first = TEST_FLAGS(p->unk_38c, 1);

  p->unk_38c &= ~1;
  if (first) {
    Vec3* target;

    p->angle = boss->mover.angle;
    ShadeMan_PlayAnim(p, 9, 1, 0, 1, 0);
    target = boss->playerPos[0];
    Boss_SetTarget(boss, target->x, target->y, target->z);
  }
  if (p->unk_3a0 == 0) {
    p->unk_38c &= ~2;
    Vec3_SetPolar(&boss->mover.delta, p->angle, 40);
    if (p->unk_3a4 >= p->stateDuration) {
      SET_FLAGS(p->unk_38c, 0x10);
    }
  }
  if (Mod(p->unk_3a4, 3) == 0) {
    ShadeMan_SpawnAfterimage(p, 0, 20);
  }
#else
  INCFUNC("asm/func/FUN_0821e0a8.inc");
#endif
}

// case ごとの合流の形がずれる (200/215)
NON_MATCH void FUN_0821e220(ShadeMan* p) {
#ifdef NONMATCHING_C
  p->unk_38c &= ~1;
  p->base.flags |= BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX;
  switch (p->unk_3a0) {
    case 0: {
      bool32 first = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (first) {
        p->unk_3f4 = 15;
        PlaySound_082406e0(SONG_863);
      }
      p->sprite.animCmdTimer = 0;
      if (p->unk_3f4 > 0) {
        p->unk_3f4--;
        FUN_0821c2a0(p, 0, p->unk_3f4, 15);
        return;
      }
      p->unk_3a0 = 1;
      p->unk_3a4 = 0;
      p->unk_38c |= 2;
      break;
    }
    case 1: {
      p->unk_38c &= ~2;
      p->sprite.animCmdTimer = 0;
      p->base.flags |= BOSSFLAG_HIDDEN | BOSSFLAG_NO_SHADOW;
      if (p->unk_3a4 >= p->stateDuration) {
        p->unk_3a0 = 2;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 2: {
      bool32 first = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (first) {
        Vec3* target;

        p->unk_bcc.y = p->unk_3b0;
        p->base.mover.pos = p->unk_bcc;
        target = p->base.playerPos[0];
        p->angle = ArcTan2_8(target->x - p->base.mover.pos.x, target->z - p->base.mover.pos.z);
        ShadeMan_PlayAnim(p, 0, 2, 0, 1, 0);
        p->unk_3bc = 0;
      }
      if (p->unk_3f4 < 15) {
        p->unk_3f4++;
        FUN_0821c2a0(p, 0, p->unk_3f4, 15);
        return;
      }
      p->unk_3a0 = 99;
      p->unk_3a4 = 0;
      p->unk_38c |= 2;
      break;
    }
    case 99: {
      p->unk_38c &= ~2;
      p->unk_38c |= 0x10;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0821e220.inc");
#endif
}

// 一通り書けたが分岐の並びと番地の作り方がずれる
NON_MATCH void FUN_0821e3f0(ShadeMan* p) {
#ifdef NONMATCHING_C
  Vec3* pos = &p->base.mover.pos;

  p->unk_38c &= ~1;
  p->base.flags |= BOSSFLAG_NO_HURTBOX;
  switch (p->unk_3a0) {
    case 0: {
      bool32 first = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (first) {
        ShadeMan_PlayAnim(p, 16, 0, 1, 0, 0);
      }
      if (p->sprite.animCmdIdx == 4 && p->sprite.animCmdTimer == 1) {
        PlaySound_082406e0(SONG_862);
      } else if (p->sprite.animCmdIdx == 6 && p->sprite.animCmdTimer == 1) {
        PlaySound_082406e0(SONG_863);
      }
      if (p->sprite.animEvents & 2) {
        p->unk_3a0 = 1;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 1: {
      p->unk_38c &= ~2;
      p->base.flags |= BOSSFLAG_HIDDEN | BOSSFLAG_NO_HITBOX | BOSSFLAG_NO_SHADOW;
      if (p->unk_3a4 >= p->stateDuration) {
        p->unk_3a0 = 2;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 2: {
      bool32 first = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (first) {
        FUN_0821c010(p, 4);
        p->unk_bf6 = FUN_0821c0c4(p, p->base.playerPos[0], &p->unk_bcc);
        pos->x = p->unk_bcc.x;
        p->base.mover.pos.z = p->unk_bcc.z;
        p->sprite.pos.x = p->unk_bcc.x;
        p->sprite.pos.z = p->unk_bcc.z;
        ShadeMan_PlayAnim(p, 16, 0, 0, 0, 1);
        if (pos->x < 0xAF0) {
          p->sprite.flags = 0;
        } else {
          p->sprite.flags |= SPRFLAG_XFLIP;
        }
      } else if (p->sprite.animEvents & 2) {
        p->unk_38c |= 0x10;
      }
      break;
    }
    case 99: {
      p->unk_38c &= ~2;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0821e3f0.inc");
#endif
}

// 残差は pos の NULL 判定の並びと一時レジスタ (155/158), FUN_0803c6a0 と同じ形
NON_MATCH s32 FUN_0821e5f0(ShadeMan* p) {
#ifdef NONMATCHING_C
  s32 radius;
  Vec3 center, min, max;
  Vec3* pos;
  s32 inside;

  switch (p->motion) {
    case 7: {
      radius = 200;
      break;
    }
    case 9: {
      radius = 128;
      break;
    }
    default: {
      return FALSE;
    }
  }
  Vec3_SetPolar(&center, p->angle, radius);
  Vec3_Add(&center, &p->base.mover.pos);
  min.x = -radius;
  min.z = -radius;
  Vec3_Add(&min, &center);
  max.x = radius;
  max.z = radius;
  Vec3_Add(&max, &center);
  pos = p->base.playerPos[0];
  if (pos == NULL) {
    inside = FALSE;
  } else {
    inside = FALSE;
    if (pos->x >= min.x && pos->x <= max.x && pos->z >= min.z && pos->z <= max.z) {
      inside = TRUE;
    }
  }
  return inside;
#else
  INCFUNC("asm/func/FUN_0821e5f0.inc");
#endif
}

// 一通り書けたが分岐の合流と番地の作り方がずれる (384/383)
NON_MATCH void FUN_0821e738(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  p->unk_38c &= ~1;
  if (p->unk_3a0 < 3) {
    boss->flags |= BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX;
  }
  switch (p->unk_3a0) {
    case 0: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        p->unk_3f4 = 15;
        PlaySound_082406e0(SONG_863);
      }
      p->sprite.animCmdTimer = 0;
      if (p->unk_3f4 > 0) {
        p->unk_3f4--;
        FUN_0821c2a0(p, 0, p->unk_3f4, 15);
        return;
      }
      p->unk_3a0 = 1;
      p->unk_3a4 = 0;
      p->unk_38c |= 2;
      break;
    }
    case 1: {
      p->unk_38c &= ~2;
      p->sprite.animCmdTimer = 0;
      boss->flags |= BOSSFLAG_HIDDEN | BOSSFLAG_NO_SHADOW;
      if (p->unk_3a4 >= p->stateDuration) {
        p->unk_3a0 = 2;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 2: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        u32 angle = p->unk_806 + boss->players[0]->mover.angle;
        Vec3* pos = &boss->mover.pos;
        Vec3* target;

        target = boss->playerPos[0];
        pos->x = target->x + POLAR_X(500, angle);
        boss->mover.pos.y = target->y;
        boss->mover.pos.z = target->z + POLAR_Z(500, angle);
        target = boss->playerPos[0];
        p->angle = ArcTan2_8(target->x - pos->x, target->z - boss->mover.pos.z);
        ShadeMan_PlayAnim(p, 0, 2, 0, 1, 0);
        p->unk_3bc = 0;
      }
      if (p->unk_3f4 < 15) {
        p->unk_3f4++;
        FUN_0821c2a0(p, 0, p->unk_3f4, 15);
        return;
      }
      p->unk_3a0 = 3;
      p->unk_3a4 = 0;
      p->unk_38c |= 2;
      break;
    }
    case 3: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        ShadeMan_PlayAnim(p, 11, 1, 1, 0, 0);
        MainSprite_SetAnimSpeed(&p->sprite, 32);
        PlaySound_082406e0(SE_843);
      }
      if (p->sprite.animCmdIdx == 6) {
        MainSprite_SetAnimSpeed(&p->sprite, 64);
      }
      boss->flags |= BOSSFLAG_NO_HITBOX;
      if (p->sprite.animCmdIdx >= 3 && p->sprite.animCmdIdx <= 6) {
        p->unk_38c |= 0x10000;
      }
      if (p->unk_3a4 < 10) {
        Vec3_SetPolar(&boss->mover.delta, p->angle, (10 - p->unk_3a4) * 4);
      }
      if (p->sprite.animEvents & 2) {
        p->unk_38c |= 0x10;
      }
      break;
    }
    case 99: {
      p->unk_38c &= ~2;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0821e738.inc");
#endif
}

// 一通り書けたが分岐の合流と番地の作り方がずれる (774/767)
NON_MATCH void FUN_0821ea6c(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  p->unk_38c &= ~1;
  switch (p->unk_3a0) {
    case 0: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        p->angle = boss->mover.angle;
        ShadeMan_PlayAnim(p, 17, 1, 1, 0, 0);
      }
      if (p->unk_3bc > 0) {
        if (p->unk_3bc < 128) {
          p->unk_3bc = FixToInt(6, p->unk_3bc * 56);
        } else {
          p->unk_3bc = FixToInt(6, p->unk_3bc * 56 + 0x7F8);
        }
      }
      if (p->unk_3a4 == 25) {
        ShadeMan_PlayAnim(p, 19, 1, 1, 0, 0);
      }
      if (p->unk_3a4 < 45) {
        Vec3_SetPolar(&boss->mover.delta, p->angle + 0x80, (45 - p->unk_3a4) >> 2);
        return;
      }
      p->unk_3bc = 0;
      if (FUN_0821e5f0(p)) {
        p->unk_3a0 = 2;
      } else {
        p->unk_3a0 = 1;
      }
      p->unk_3a4 = 0;
      p->unk_38c |= 2;
      break;
    }
    case 1: {
      bool32 entered = p->unk_38c & 2;
      Vec3 ahead;

      p->unk_38c &= ~2;
      if (entered) {
        Vec3* target;

        p->angle = boss->mover.angle;
        ShadeMan_PlayAnim(p, 9, 1, 1, 1, 0);
        target = boss->playerPos[0];
        Boss_SetTarget(boss, target->x, target->y, target->z);
        PlaySound_082406e0(SE_842);
      }
      Vec3_SetPolar(&boss->mover.delta, p->angle, 40);
      if (FUN_0821e5f0(p)) {
        p->unk_3a0 = 2;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      } else {
        s32 h;

        ahead.x = boss->mover.pos.x + POLAR_X(400, p->angle);
        ahead.z = boss->mover.pos.z + POLAR_Z(400, p->angle);
        h = TileHeightAt(&ahead) - p->unk_3b0;
        if (!(h >= -0x1FF && h <= 0xFF && p->unk_3a4 < p->stateDuration)) {
          p->unk_3a0 = 3;
          p->unk_3a4 = 0;
          p->unk_38c |= 2;
          return;
        }
      }
      if (Mod(p->unk_3a4, 6) == 0) {
        ShadeMan_SpawnAfterimage(p, 0, 20);
      }
      break;
    }
    case 2: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        ShadeMan_PlayAnim(p, 11, 1, 1, 0, 0);
        MainSprite_SetAnimSpeed(&p->sprite, 32);
        PlaySound_082406e0(SE_843);
      }
      if (p->sprite.animCmdIdx == 6) {
        MainSprite_SetAnimSpeed(&p->sprite, 64);
      }
      if (p->sprite.animCmdTimer == 1 && p->sprite.animCmdIdx == 7) {
        if (!(p->unk_38c & 0x20)) {
          p->unk_809++;
        } else {
          p->unk_38c &= ~0x20;
        }
        p->unk_3db = 0;
      }
      boss->flags |= BOSSFLAG_NO_HITBOX;
      if (p->sprite.animCmdIdx >= 3 && p->sprite.animCmdIdx <= 6) {
        p->unk_38c |= 0x10000;
      }
      if (p->unk_3a4 < 10) {
        Vec3_SetPolar(&boss->mover.delta, p->angle, (10 - p->unk_3a4) * 4);
      }
      if (p->sprite.animEvents & 2) {
        p->unk_38c |= 0x10;
      }
      break;
    }
    case 3: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        ShadeMan_PlayAnim(p, 21, 1, 1, 0, 0);
        if (!(p->unk_38c & 0x20)) {
          p->unk_809++;
        } else {
          p->unk_38c &= ~0x20;
        }
        p->unk_3db = 0;
      }
      if (p->unk_3a4 < 50) {
        Vec3_SetPolar(&boss->mover.delta, p->angle, (50 - p->unk_3a4) >> 2);
      } else if (p->unk_3a4 > 79) {
        p->unk_38c |= 0x10;
      }
      if (p->unk_3a4 < 40 && Mod(p->unk_3a4, 20) == 0) {
        ShadeMan_SpawnAfterimage(p, 0, 20);
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0821ea6c.inc");
#endif
}

// 一通り書けたが分岐の合流と番地の作り方がずれる (835/843)
NON_MATCH void FUN_0821f0e4(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  bool32 first = p->unk_38c & 1;

  p->unk_38c &= ~1;
  if (first) {
    FUN_0821c010(p, 4);
    p->unk_bf6 = 0xFF;
    p->unk_3f4 = 30;
    p->unk_3f8 = 0;
    p->unk_3da = 0;
  }
  if (p->unk_3a0 == 3) {
    p->unk_3f8 = 1;
  }
  if (p->unk_3f8 == 0) {
    if (p->unk_3f4 > 0) {
      p->unk_3f4--;
      if (!(p->unk_3f4 & 1)) {
        FUN_0821c2a0(p, 1, p->unk_3f4, 30);
      }
    } else {
      p->unk_3f8 = 1;
    }
  } else if (p->unk_3f8 == 1) {
    if (p->unk_3f4 < 30) {
      p->unk_3f4++;
      if (!(p->unk_3f4 & 1)) {
        FUN_0821c2a0(p, 1, p->unk_3f4, 30);
      }
    } else {
      p->unk_3f8 = 0;
    }
  }
  boss->flags |= BOSSFLAG_NO_HURTBOX | BOSSFLAG_UNK_19;
  switch (p->unk_3a0) {
    case 0: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        p->angle = boss->mover.angle;
        ShadeMan_PlayAnim(p, 17, 1, 1, 0, 0);
      }
      if (p->unk_3bc > 0) {
        if (p->unk_3bc < 128) {
          p->unk_3bc = FixToInt(6, p->unk_3bc * 56);
        } else {
          p->unk_3bc = FixToInt(6, p->unk_3bc * 56 + 0x7F8);
        }
      }
      if (p->unk_3a4 == 25) {
        ShadeMan_PlayAnim(p, 19, 1, 1, 0, 0);
      }
      if (p->unk_3a4 < 45) {
        Vec3_SetPolar(&boss->mover.delta, p->angle + 0x80, (45 - p->unk_3a4) >> 2);
        return;
      }
      p->unk_3bc = 0;
      p->unk_3a0 = 1;
      p->unk_3a4 = 0;
      p->unk_38c |= 2;
      break;
    }
    case 1: {
      bool32 entered = p->unk_38c & 2;
      Vec3 ahead;
      s32 h;

      p->unk_38c &= ~2;
      if (entered) {
        Vec3* target;

        p->angle = boss->mover.angle;
        ShadeMan_PlayAnim(p, 9, 1, 1, 1, 0);
        target = boss->playerPos[0];
        Boss_SetTarget(boss, target->x, target->y, target->z);
        Hitbox_SetAttack(&p->hitbox, p->unk_3ca, p->unk_3cc, 0, HBATTR_17 | HBATTR_18, p->unk_3ce);
        PlaySound_082406e0(SE_842);
      }
      Vec3_SetPolar(&boss->mover.delta, p->angle, 50);
      ahead.x = boss->mover.pos.x + POLAR_X(400, p->angle);
      ahead.z = boss->mover.pos.z + POLAR_Z(400, p->angle);
      h = TileHeightAt(&ahead) - p->unk_3b0;
      if (!(h >= -0x1FF && h <= 0xFF) || p->unk_3a4 >= p->stateDuration) {
        if (++p->unk_3da < 4) {
          p->unk_3a0 = 2;
          p->unk_3a4 = 0;
        } else {
          p->unk_3a0 = 3;
          p->unk_3a4 = 0;
        }
        p->unk_38c |= 2;
        return;
      }
      if (Mod(p->unk_3a4, 6) == 0) {
        ShadeMan_SpawnAfterimage(p, 1, 20);
      }
      break;
    }
    case 2: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        Vec3 node;
        s32 idx = FUN_0821c044(p, &boss->mover.pos, &node);

        if (!(p->unk_3da & 1)) {
          idx += 2;
          if (idx >= p->pathNodeCount) {
            idx -= p->pathNodeCount;
          }
        } else {
          idx -= 2;
          if (idx < 0) {
            idx += p->pathNodeCount;
          }
        }
        p->unk_bf6 = idx;
        Map_ReadPathNodePos(&p->unk_bcc, p->pathNodes, p->unk_bf6);
        FUN_0821bef0(p);
        FUN_0821be24(p, &p->unk_bcc, 30);
        PlaySound_082406e0(SONG_840);
      }
      p->angle = boss->mover.angle;
      ShadeMan_PlayAnim(p, 0, 2, 0, 1, 0);
      if (p->unk_bec < p->unk_bee) {
        FUN_0821bf34(p);
        FUN_0821bfc8(p);
      } else {
        p->unk_3a0 = 1;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      if (Mod(p->unk_3a4, 6) == 0) {
        ShadeMan_SpawnAfterimage(p, 1, 20);
      }
      break;
    }
    case 3: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        ShadeMan_PlayAnim(p, 21, 1, 1, 0, 0);
        Hitbox_SetAttack(&p->hitbox, p->hitboxPower, p->hitboxKnockback, 0, 0, p->hitboxUnk44);
      }
      if (p->unk_3a4 < 50) {
        Vec3_SetPolar(&boss->mover.delta, p->angle, (50 - p->unk_3a4) >> 2);
      } else if (p->unk_3a4 > 79) {
        p->unk_38c |= 0x10;
      }
      if (p->unk_3a4 < 40 && Mod(p->unk_3a4, 20) == 0) {
        ShadeMan_SpawnAfterimage(p, 0, 20);
      }
      break;
    }
    case 99: {
      p->unk_38c &= ~2;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0821f0e4.inc");
#endif
}

// 一通り書けたが分岐の合流と番地の作り方がずれる (804/834)
NON_MATCH void FUN_0821f818(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Player* player;
  bool32 first = p->unk_38c & 1;

  p->unk_38c &= ~1;
  if (first) {
    p->unk_3f4 = 30;
  }
  player = gPlayerPtr[0];
  switch (p->unk_3a0) {
    case 0: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        p->angle = boss->mover.angle;
        ShadeMan_PlayAnim(p, 17, 1, 1, 0, 0);
      }
      if (p->unk_3bc > 0) {
        if (p->unk_3bc < 128) {
          p->unk_3bc = FixToInt(6, p->unk_3bc * 56);
        } else {
          p->unk_3bc = FixToInt(6, p->unk_3bc * 56 + 0x7F8);
        }
      }
      if (p->unk_3a4 == 25) {
        ShadeMan_PlayAnim(p, 19, 1, 1, 0, 0);
      }
      if (p->unk_3a4 < 45) {
        Vec3_SetPolar(&boss->mover.delta, p->angle + 0x80, (45 - p->unk_3a4) >> 2);
        return;
      }
      p->unk_3bc = 0;
      p->unk_3a0 = 1;
      p->unk_3a4 = 0;
      p->unk_38c |= 2;
      break;
    }
    case 1: {
      bool32 entered = p->unk_38c & 2;
      Vec3 ahead;
      s32 h;

      p->unk_38c &= ~2;
      if (entered) {
        Vec3* target;

        p->angle = boss->mover.angle;
        ShadeMan_PlayAnim(p, 9, 1, 0, 1, 0);
        target = boss->playerPos[0];
        Boss_SetTarget(boss, target->x, target->y, target->z);
        PlaySound_082406e0(SE_842);
      }
      Vec3_SetPolar(&boss->mover.delta, p->angle, 40);
      if (gStat->playerKind < 2) {
        if (!(player->flag20 & PFLAG20_UNK_18) && FUN_0821e5f0(p)) {
          FUN_0821db8c(p);
          p->unk_3a0 = 2;
          p->unk_3a4 = 0;
          p->unk_38c |= 2;
          Hitbox_SetFlags(&p->hurtbox, HBFLAG_HIDDEN);
          return;
        }
      } else {
        boss->flags |= BOSSFLAG_NO_HITBOX;
      }
      ahead.x = boss->mover.pos.x + POLAR_X(400, p->angle);
      ahead.z = boss->mover.pos.z + POLAR_Z(400, p->angle);
      h = TileHeightAt(&ahead) - p->unk_3b0;
      if (!(h >= -0x1FF && h <= 0xFF) || p->unk_3a4 >= p->stateDuration) {
        p->unk_3a0 = 3;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
        return;
      }
      if (Mod(p->unk_3a4, 6) == 0) {
        ShadeMan_SpawnAfterimage(p, 1, 20);
      }
      break;
    }
    case 2: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        ShadeMan_PlayAnim(p, 13, 0, 1, 0, 0);
        FUN_0821dc14(p);
        p->unk_bbc = 0;
        p->unk_bbd = 0;
        p->unk_bbe = player->angle_400;
        p->unk_bbf = player->angle_400;
        p->shakeAmp = 0;
        p->unk_bc1 = 0;
      } else {
        FUN_0821dd00(p);
      }
      if (p->unk_bbf != player->angle_400) {
        p->unk_bbf = player->angle_400;
        p->unk_bc1++;
      }
      if (p->unk_bc1 > 3) {
        p->shakeAngle = Angle_FromDir8(Player_GetDpadFacing(player));
        p->shakeAmp = 16;
        p->unk_bc1 = 0;
      }
      boss->flags |= BOSSFLAG_NO_HURTBOX;
      if ((u8)(player->angle_400 - p->unk_bbe) < 16) {
        if (!(p->sprite.animEvents & 1)) {
          return;
        }
        if (gStat->savedHP != 0 && ++p->unk_bbc < 4) {
          p->sprite.animCmdIdx = 2;
          p->sprite.animCmdTimer = 0;
          p->sprite.animCmdDuration = 7;
          return;
        }
      }
      p->unk_3a0 = 99;
      p->unk_3a4 = 0;
      p->unk_38c |= 2;
      break;
    }
    case 3: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        ShadeMan_PlayAnim(p, 21, 1, 1, 0, 0);
      }
      if (p->unk_3a4 < 50) {
        Vec3_SetPolar(&boss->mover.delta, p->angle, (50 - p->unk_3a4) >> 2);
      } else {
        p->unk_38c |= 0x10;
      }
      if (p->unk_3a4 < 40 && Mod(p->unk_3a4, 20) == 0) {
        ShadeMan_SpawnAfterimage(p, 1, 20);
      }
      break;
    }
    case 99: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        FUN_0821dca0(p);
        p->angle = Angle_FromDir4(boss->facing);
        ShadeMan_PlayAnim(p, 0, 2, 0, 1, 0);
      }
      if (p->unk_3a4 > 30) {
        p->unk_38c |= 0x10;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0821f818.inc");
#endif
}

// 一通り書けたが分岐の並びと番地の作り方がずれる (296/300)
NON_MATCH void FUN_0821ff34(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  bool32 first = p->unk_38c & 1;

  p->unk_38c &= ~1;
  if (first) {
    p->angle = boss->mover.angle;
    ShadeMan_PlayAnim(p, 14, 1, 1, 0, 0);
    p->unk_3d8 = 0;
  }
  switch (p->unk_3a0) {
    case 0: {
      s32 t;

      p->unk_38c &= ~2;
      if (p->sprite.animCmdIdx == 7 && p->sprite.animCmdTimer == 1) {
        PlaySound_082406e0(SONG_862);
      }
      t = p->unk_3a4;
      if ((t >= 31 && t <= 49) || (t >= 61 && t <= 79)) {
        if (t == 31) {
          if (!(p->unk_38c & 0x20)) {
            p->unk_809++;
          } else {
            p->unk_38c &= ~0x20;
          }
          p->unk_3db = 0;
          PlaySound_082406e0(NOISE_UNK_128 | NOISE_QUAKE);
        }
        if (Mod(p->unk_3a4, 6) == 0) {
          Vec3 v = boss->mover.pos;
          s32 angle;
          s32 speed;

          v.y += 240;
          if (p->unk_3d8 < 3) {
            angle = boss->mover.angle - 2 - (Random() & 4);
          } else {
            angle = boss->mover.angle + 2 + (Random() & 4);
          }
          speed = !p->unk_388 ? 20 : 30;
          switch (p->unk_3d8) {
            case 1:
            case 4: {
              angle -= 13;
              speed += 4;
              break;
            }
            case 2:
            case 5: {
              angle += 13;
              speed += 4;
              break;
            }
          }
          FUN_0805e6bc(p->entity0805e67c, &v, angle, speed, p->unk_3d2, 30, 8);
          p->unk_3d8++;
        }
      }
      if (p->unk_3a4 > 120 && (p->sprite.animEvents & 2)) {
        p->unk_3a0 = 1;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 1: {
      p->unk_38c &= ~2;
      if (p->unk_3a4 > 31) {
        p->unk_3a0 = 99;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 99: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        ShadeMan_PlayAnim(p, 23, 1, 1, 0, 0);
      }
      if (p->sprite.animEvents & 2) {
        p->unk_38c |= 0x10;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0821ff34.inc");
#endif
}

// 一通り書けたが分岐の並びと番地の作り方がずれる
NON_MATCH void FUN_082201ec(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  bool32 first = p->unk_38c & 1;

  p->unk_38c &= ~1;
  if (first) {
    p->angle = boss->mover.angle;
    ShadeMan_PlayAnim(p, 14, 1, 1, 0, 0);
    p->unk_3d8 = 0;
  }
  if (p->motionTimer > 29) {
    boss->flags |= BOSSFLAG_UNK_18 | BOSSFLAG_UNK_22;
  }
  switch (p->unk_3a0) {
    case 0: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        p->unk_3f4 = 30;
      }
      if (p->sprite.animCmdIdx == 7 && p->sprite.animCmdTimer == 1) {
        PlaySound_082406e0(SONG_862);
      }
      if (p->unk_3f4 > 0) {
        p->unk_3f4--;
        FUN_0821c2a0(p, 1, p->unk_3f4, 30);
      } else if (p->unk_3f4 > -30) {
        s32 t = --p->unk_3f4;

        if (t < 0) {
          t = -t;
        }
        FUN_0821c2a0(p, 1, t, 30);
      }
      if (p->unk_3a4 == 30) {
        s32 n = 15 - p->unk_3d9;

        if (n > 0) {
          Vec3 v = boss->mover.pos;

          v.y += 240;
          FUN_0805e940(p->entity0805e67c, &v, boss->mover.angle, 50, p->unk_3d4, 30, 8, n);
          PlaySound_082406e0(NOISE_UNK_128 | NOISE_QUAKE);
        }
        if (!(p->unk_38c & 0x20)) {
          p->unk_809++;
        } else {
          p->unk_38c &= ~0x20;
        }
        p->unk_3db = 0;
      }
      if (p->unk_3a4 > 150 && (p->sprite.animEvents & 2)) {
        p->unk_3a0 = 1;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 1: {
      p->unk_38c &= ~2;
      if (p->unk_3a4 > 210) {
        p->unk_3a0 = 99;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 99: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        ShadeMan_PlayAnim(p, 23, 1, 1, 0, 0);
      }
      if (p->sprite.animEvents & 2) {
        p->unk_38c |= 0x10;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_082201ec.inc");
#endif
}

// 一通り書けたが分岐の並びと番地の作り方がずれる (274/288)
NON_MATCH void FUN_08220430(ShadeMan* p) {
#ifdef NONMATCHING_C
  bool32 first = p->unk_38c & 1;

  p->unk_38c &= ~1;
  if (first) {
    p->unk_3d8 = 0;
  }
  switch (p->unk_3a0) {
    case 0: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        p->angle = ArcTan2_8(2800 - p->unk_bcc.x, 1900 - p->unk_bcc.z);
        ShadeMan_PlayAnim(p, 16, 0, 1, 0, 0);
      }
      if (p->sprite.animCmdIdx == 4) {
        p->sprite.animCmdTimer = 0;
      }
      if (p->unk_3ba == 18) {
        PlaySound_082406e0(SONG_862);
      }
      if (p->unk_3ba == 18 || p->unk_3ba == 19) {
        if (!p->base.xflip) {
          p->sprite.pos.x -= 10;
        } else {
          p->sprite.pos.z -= 10;
        }
      }
      if (p->unk_3a4 == 30) {
        s32 count;
        s32 a, b;
        s32 i;

        if (!p->unk_388) {
          count = 2;
          a = 2;
          b = 1;
        } else {
          count = 3;
          a = 1;
          b = 3;
        }
        for (i = 0; i < count; i++) {
          Vec3 pos;

          Map_GetPathNodePos(&pos, 9, (p->unk_bf6 != 0 ? 3 : 0) + i);
          pos.y = 0x500;
          FUN_0805eee4(p->entity0805ee80, 10, 16, p->unk_3d6, 60, 60, 30, a, b, &pos);
        }
        if (!(p->unk_38c & 0x20)) {
          p->unk_809++;
        } else {
          p->unk_38c &= ~0x20;
        }
        p->unk_3db = 0;
      } else if (p->unk_3a4 > 80) {
        p->unk_3a0 = 1;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 1: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        ShadeMan_PlayAnim(p, 16, 0, 0, 0, 1);
      }
      if (p->sprite.animEvents & 2) {
        p->unk_3a0 = 99;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 99: {
      p->unk_38c &= ~2;
      if (p->unk_3a4 > 30) {
        p->unk_38c |= 0x10;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08220430.inc");
#endif
}

// 残差は p と &unk_38c のレジスタが逆, 定数 2 を case 0 の頭で作る (82/84)
NON_MATCH void FUN_082206a8(ShadeMan* p) {
#ifdef NONMATCHING_C
  bool32 first = TEST_FLAGS(p->unk_38c, 1);

  p->unk_38c &= ~1;
  if (first) {
    ShadeMan_PlayAnim(p, 5, 1, 1, 0, 0);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_UNK_18);
  p->base.flags |= BOSSFLAG_NO_HURTBOX;
  switch (p->unk_3a0) {
    case 0: {
      p->unk_38c &= ~2;
      if (p->sprite.animEvents & 2) {
        p->unk_3a0 = 99;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 99: {
      p->unk_38c &= ~2;
      if (p->unk_3a4 > 14) {
        p->unk_38c |= 0x10;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_082206a8.inc");
#endif
}

// 一通り書けたが分岐の並びと番地の作り方がずれる
NON_MATCH void FUN_08220758(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Vec3* pos = &boss->mover.pos;
  bool32 first = p->unk_38c & 1;

  p->unk_38c &= ~1;
  if (first) {
    ShadeMan_PlayAnim(p, 5, 1, 1, 0, 0);
    Boss_GiveWeaponExp(boss, p->weaponExp);
    FUN_08022fb8(boss, &p->sprite.pos);
    if (gPlayerPtr[0]->flag20 & PFLAG20_UNK_12) {
      FUN_0821dca0(p);
    }
  }
  boss->flags |= BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX;
  if (!(pos->x >= 2000 && pos->x <= 3700 && pos->z >= 1000 && pos->z <= 2700 && TileHeightAt(pos) == 0x500)) {
    Vec3 v;

    Vec3_SetPolar(&v, ArcTan2_8(2800 - pos->x, 1900 - pos->z), 10);
    boss->mover.delta = v;
  }
  if (p->unk_3a0 == 0) {
    p->unk_38c &= ~2;
    boss->flags |= BOSSFLAG_UNK_17;
    if (p->motionTimer == 256) {
      FUN_08023024(boss, &p->sprite.pos);
      p->unk_3a0 = 99;
      p->unk_3a4 = 0;
      p->unk_38c |= 2;
    }
  } else if (p->unk_3a0 == 99) {
    p->unk_38c &= ~2;
    boss->flags |= BOSSFLAG_NO_SHADOW;
  }
#else
  INCFUNC("asm/func/FUN_08220758.inc");
#endif
}

void FUN_0822098c(ShadeMan* p) {
  p->unk_38c &= ~1;
  SET_FLAGS(p->base.flags, BOSSFLAG_HIDDEN | BOSSFLAG_NO_SHADOW);
  if (p->unk_3a0 == 0) {
    p->unk_38c &= ~2;
  }
}

// 残差は sprite.flags を触る 2 か所の番地と定数の作り方, boss の写しは Boss* ローカルで出る
NON_MATCH void FUN_082209cc(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  bool32 first = TEST_FLAGS(p->unk_38c, 1);

  p->unk_38c &= ~1;
  if (first) {
    if (!(p->unk_38c & 0x100)) {
      p->sprite.flags |= SPRFLAG_BLINK_ODD;
    }
    ShadeMan_PlayAnim(p, 0, 2, 0, 1, 0);
  }
  if (p->sprite.flags & SPRFLAG_BLINK_ODD) {
    SET_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW);
  }
  SET_FLAGS(p->unk_38c, 0x20000);
  if (p->unk_3a0 == 0) {
    p->unk_38c &= ~2;
  }
#else
  INCFUNC("asm/func/FUN_082209cc.inc");
#endif
}

// 原典は sprite.flags を &p->sprite 経由で触り, 定数を読み込みのあとで作る
NON_MATCH void FUN_08220a68(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  bool32 first = TEST_FLAGS(p->unk_38c, 1);

  p->unk_38c &= ~1;
  if (first) {
    MainSprite_SetFlags(&p->sprite, SPRFLAG_BLINK_ODD);
    p->angle = 0x40;
    ShadeMan_PlayAnim(p, 14, 1, 1, 0, 0);
  }
  if (p->sprite.flags & SPRFLAG_BLINK_ODD) {
    SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW);
  }
  switch (p->unk_3a0) {
    case 0: {
      p->unk_38c &= ~2;
      if (p->sprite.animCmdIdx == 7 && p->sprite.animCmdTimer == 1) {
        PlaySound_082406e0(SONG_862);
      }
      if (p->sprite.animEvents & 2) {
        MsgQueue_EndWait(&boss->msgQueue, 1);
        p->unk_3a0 = 99;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 99: {
      p->unk_38c &= ~2;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08220a68.inc");
#endif
}

// 残差は animEvents を試す定数 2 を case 0 の頭で作るかどうか (63/63)
NON_MATCH void FUN_08220b64(ShadeMan* p) {
#ifdef NONMATCHING_C
  bool32 first = TEST_FLAGS(p->unk_38c, 1);

  p->unk_38c &= ~1;
  if (first) {
    ShadeMan_PlayAnim(p, 23, 1, 1, 0, 0);
  }
  switch (p->unk_3a0) {
    case 0: {
      p->unk_38c &= ~2;
      if (p->sprite.animEvents & 2) {
        MsgQueue_EndWait(&p->base.msgQueue, 1);
        ShadeMan_SetMotion(p, 16, TRUE);
      }
      break;
    }
    case 99: {
      p->unk_38c &= ~2;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08220b64.inc");
#endif
}

// 残差は FUN_08220b64 と同じく animEvents を試す定数 2 の位置 (93/93)
NON_MATCH void FUN_08220bf0(ShadeMan* p) {
#ifdef NONMATCHING_C
  bool32 first = TEST_FLAGS(p->unk_38c, 1);

  p->unk_38c &= ~1;
  if (first) {
    MainSprite_SetFlags(&p->sprite, SPRFLAG_BLINK_ODD);
    p->angle = 0x40;
    ShadeMan_PlayAnim(p, 16, 0, 0, 0, 1);
    PlaySound_082406e0(SONG_863);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW);
  if (p->motionTimer == 30) {
    PlaySound_082406e0(SONG_862);
  }
  switch (p->unk_3a0) {
    case 0: {
      p->unk_38c &= ~2;
      if (p->sprite.animEvents & 2) {
        MsgQueue_EndWait(&p->base.msgQueue, 1);
        ShadeMan_SetMotion(p, 16, TRUE);
      }
      break;
    }
    case 99: {
      p->unk_38c &= ~2;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08220bf0.inc");
#endif
}

// 原典は sprite.flags を &p->sprite 経由で触り, 定数を読み込みのあとで作る
NON_MATCH void FUN_08220cc4(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  bool32 first = TEST_FLAGS(p->unk_38c, 1);

  p->unk_38c &= ~1;
  if (first) {
    MainSprite_SetFlags(&p->sprite, SPRFLAG_BLINK_ODD);
    p->angle = 0x40;
    ShadeMan_PlayAnim(p, 16, 0, 1, 0, 0);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_SHADOW);
  switch (p->unk_3a0) {
    case 0: {
      p->unk_38c &= ~2;
      if (p->sprite.animCmdIdx == 4 && p->sprite.animCmdTimer == 1) {
        PlaySound_082406e0(SONG_862);
      } else if (p->sprite.animCmdIdx == 6 && p->sprite.animCmdTimer == 1) {
        PlaySound_082406e0(SONG_863);
      }
      if (p->sprite.animEvents & 2) {
        MsgQueue_EndWait(&boss->msgQueue, 1);
        p->unk_3a0 = 1;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 1: {
      p->unk_38c &= ~2;
      p->base.flags |= BOSSFLAG_HIDDEN;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08220cc4.inc");
#endif
}

// 一通り書けたが乱数の取り方と分岐の合流がずれる (380/367)
NON_MATCH void FUN_08220de0(ShadeMan* p) {
#ifdef NONMATCHING_C
  bool32 first = p->unk_38c & 1;

  p->unk_38c &= ~1;
  if (first) {
    p->unk_3f0 = FixToInt(8, Div(p->unk_3f0 * 0xF00, 10));
    ShadeMan_PlayAnim(p, 5, 1, 1, 0, 0);
    VM_ExecByID(p->scriptID, NULL);
  }
  p->base.flags |= BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX;
  if (p->unk_3a0 < 2) {
    if (p->motionTimer == Div(p->motionTimer, 6) * 6) {
      u16* table = gRandomTable;
      WorldPos pos;
      Vec3 size;

      pos = p->sprite.pos;
      pos.x += (_Random(table) & 0x80) - 0x40;
      pos.y += (_Random(table) & 0x80) + 0x40;
      pos.z += (_Random(table) & 0x80) - 0x40;
      size.x = 0x50, size.y = 0x3C, size.z = 0x3C;
      EmitSmoke(&pos, (_Random(table) & 3) + 1, &size, 0, 4, 20, 2, 1);
      PlaySound_082406e0(SONG_825);
    }
    p->sprite.pos.x += (Random() & 0x30) - 24;
    p->sprite.pos.z += (Random() & 0x30) - 24;
  }
  switch (p->unk_3a0) {
    case 0: {
      p->unk_38c &= ~2;
      if (p->sprite.animEvents & 2) {
        p->unk_3a0 = 1;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 1: {
      p->unk_38c &= ~2;
      if (p->unk_3a4 > 90) {
        p->unk_3a0 = 2;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 2: {
      bool32 entered = p->unk_38c & 2;

      p->unk_38c &= ~2;
      if (entered) {
        p->unk_3f4 = 60;
      }
      if (p->unk_3f4 > 0) {
        p->unk_3f4--;
        FUN_0821c2a0(p, 2, p->unk_3f4, 60);
        return;
      }
      p->unk_388 = 1;
      p->unk_809 = 0;
      VM_ExecByID(p->scriptID2, NULL);
      p->unk_3a0 = 3;
      p->unk_3a4 = 0;
      p->unk_38c |= 2;
      break;
    }
    case 3: {
      p->unk_38c &= ~2;
      if (p->unk_3a4 > 60) {
        p->unk_3a0 = 99;
        p->unk_3a4 = 0;
        p->unk_38c |= 2;
      }
      break;
    }
    case 99: {
      p->unk_38c &= ~2;
      p->unk_38c |= 0x10;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08220de0.inc");
#endif
}

void ShadeMan_ExitMotion(ShadeMan* p) {
  switch (p->motion) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14: {
      break;
    }
    case 8: {
      Hitbox_SetAttack(&p->hitbox, p->hitboxPower, p->hitboxKnockback, 0, 0, p->hitboxUnk44);
      break;
    }
    case 11: {
      p->unk_3d9 = 0;
      break;
    }
  }
}

// 残差は unk_38c などの番地を呼び出しのあとで作り直すかどうか (96/99)
NON_MATCH void ShadeMan_UpdateMotion(ShadeMan* p) {
#ifdef NONMATCHING_C
  if (p->nextMotion != -1) {
    ShadeMan_ExitMotion(p);
    p->motion = p->nextMotion;
    p->motionTimer = 0;
    p->motionCallback = PTR_ARRAY_085b0028[p->motion];
    SET_FLAGS(p->unk_38c, 1);
    p->unk_3a0 = 0;
    p->unk_3a4 = 0;
    SET_FLAGS(p->unk_38c, 2);
    p->nextMotion = -1;
    if (p->motion >= 6 && p->motion <= 12) {
      p->unk_808 = p->motion;
    }
  }
  p->base.flags = 0;
  p->base.subStateDone = FALSE;
  if (!TEST_FLAGS(p->unk_38c, 0x10)) {
    p->motionCallback(p);
    p->motionTimer++;
    if (!(p->unk_38c & 2)) {
      p->unk_3a4++;
    }
  }
#else
  INCFUNC("asm/func/ShadeMan_UpdateMotion.inc");
#endif
}

// 次の motion を予約する, 今と同じなら force のときだけ
void ShadeMan_SetMotion(ShadeMan* p, u32 next, bool8 force) {
  if (force || p->motion != next) {
    p->nextMotion = next;
    CLEAR_FLAGS(p->unk_38c, 0x10);
  }
}

// 一通り書けたが揺れの乱数の読み順などがずれる (198/193)
NON_MATCH void FUN_0822129c(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Vec3* target;

  ShadeMan_PollMessages(p);
  Mover_ApplyMove(&boss->mover);
  FUN_0821c140(p);
  p->unk_38c &= 0xFF00FFFF;
  ShadeMan_HandleDamage(p);
  if (p->unk_3fc > 0) {
    SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
    p->unk_3fc--;
  }
  FUN_0821c520(p);
  FUN_08022e20(boss);
  if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_17)) {
    p->sprite.pos.x += (Random() & 0x20) - 16;
    p->sprite.pos.z += (Random() & 0x20) - 16;
  }
  if (p->shakeAmp != 0) {
    p->shakeAmp--;
    p->sprite.pos.x += Trig_Fix12ToInt(COS(p->shakeAngle) * p->shakeAmp * 4);
    p->sprite.pos.z += Trig_Fix12ToInt(SIN(p->shakeAngle) * p->shakeAmp * 4);
  }
  target = boss->playerPos[0];
  boss->mover.angle = ArcTan2_8(target->x - boss->mover.pos.x, target->z - boss->mover.pos.z);
  if (p->unk_388 == 1 && p->motion != 8 && p->motion != 9) {
    p->unk_80c++;
    p->unk_810++;
  }
#else
  INCFUNC("asm/func/FUN_0822129c.inc");
#endif
}

// 残差は揺れの乱数と座標を読む順 (原典は乱数が先で座標を ldrh で読む) と table の置き場所 (173/173)
NON_MATCH void FUN_08221450(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  FUN_08022ec0(boss);
  FUN_0821c5d4(p);
  if (p->unk_3f0 > 0) {
    u16* table;

    if (--p->unk_3f0 == 0) {
      FUN_0821c238(p, 7);
    }
    table = gRandomTable;
    if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_18)) {
      p->sprite.pos.x = p->sprite.pos.x - 24 + (_Random(table) & 0x30);
      p->sprite.pos.z = p->sprite.pos.z - 24 + (_Random(table) & 0x30);
    } else {
      p->sprite.pos.x = p->sprite.pos.x - 8 + (_Random(table) & 0x10);
      p->sprite.pos.z = p->sprite.pos.z - 8 + (_Random(table) & 0x10);
    }
  }
  ShadeMan_UpdateAfterimages(p);
  p->unk_38c &= 0xFFFFFF;
  if (!boss->unk_ab) {
    if (!TEST_FLAGS(u32_03002bc0[0], FLAG03002BC0_UNK_2)) {
      if (boss->subState0 == 2 || TEST_FLAGS(boss->flags, BOSSFLAG_HIDDEN)) {
        if (p->unk_bc3 == 1) {
          p->unk_bc3 = 0;
          FUN_0823b880(8);
        }
      } else {
        p->unk_bc3 = 1;
        FUN_08221938(p);
      }
    } else if (p->unk_bc3 != 2) {
      p->unk_bc3 = 2;
      FUN_0823b880(32);
    }
  }
  p->unk_390++;
  boss->weaponExpMask = 0;
  boss->hurtAttributes = 0;
#else
  INCFUNC("asm/func/FUN_08221450.inc");
#endif
}

// 一通り書けたが番地の作り方と並びがずれる (350/345)
NON_MATCH void ShadeMan_HandleDamage(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  if (!TEST_FLAGS(boss->flags, BOSSFLAG_UNK_22)) {
    p->unk_3f2 = 0;
    Hitbox_SetPowerAndAttributes(&p->hurtbox, p->hurtboxPower, HBATTR_IMMORTAL | HBATTR_DARK, HBATTR_SOL);
  } else {
    Hitbox_SetPowerAndAttributes(&p->hurtbox, p->hurtboxPower2, HBATTR_IMMORTAL | HBATTR_DARK, HBATTR_SOL);
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_0)) {
    s32 damage = (s16)p->damage;

    p->unk_390++;
    if (!p->unk_388 && !(boss->hurtAttributes & HBATTR_DARK)) {
      damage = 0;
    }
    if (damage <= 0) {
      if (!p->unk_388) {
        if (++p->unk_3db < 3) {
          ShadeMan_SetSubState0(p, 0, 0, 5, 60);
          p->unk_806 = 0;
        } else {
          p->unk_38c |= 0x20;
          ShadeMan_SetSubState0(p, 0, 0, 12, 0);
        }
        p->unk_3fc = 15;
      }
    } else {
      Vec3 ofs;

      VEC3_SET(ofs, 0x10, 0, 0x10);
      FUN_0805fe7c(&p->hurtbox, damage, 0, &boss->mover.pos, &ofs, 1);
      p->unk_3f0 = 10;
      FUN_0821c238(p, 0);
      boss->hp -= damage;
      if (boss->hp <= 0) {
        ShadeMan_SetSubState0(p, 1, 0, 1, 0);
        PlaySound_082406e0(SONG_973);
      } else {
        p->unk_3fc = 15;
        if ((!p->unk_388 && (boss->hurtAttributes & HBATTR_DARK)) || (p->unk_388 == 1 && (boss->hurtAttributes & HBATTR_SOL))) {
          WorldPos pos;
          Vec3 size;

          pos = p->sprite.pos;
          pos.y += 200;
          size.x = 0x50, size.y = 0x3C, size.z = 0x3C;
          EmitSmoke(&pos, (Random() & 3) + 1, &size, p->hurtAngle, 4, 20, 2, 1);
          PlaySound_082406e0(SONG_825);
        }
        if (!TEST_FLAGS(boss->flags, BOSSFLAG_UNK_22)) {
          if (p->unk_388 == 1) {
            p->unk_80c += 100;
            p->unk_810 += 100;
          }
          PlaySound_082406e0(SE_ENEMY_DAMAGED);
        } else {
          p->unk_3f0 = FixToInt(8, Div(p->unk_3f0 * 0xF00, 10));
          if (++p->unk_3f2 > 4) {
            ShadeMan_SetSubState0(p, 1, 0, 0, 0);
          }
          PlaySound_082406e0(SONG_866);
        }
        if (!p->unk_388 && boss->hp <= p->unk_3dc) {
          ShadeMan_SetSubState0(p, 2, 0, 6, 0);
        }
      }
    }
  }
#else
  INCFUNC("asm/func/ShadeMan_HandleDamage.inc");
#endif
}

// entity0805ee80 の要素がひとつでも動いていれば TRUE を返す
s32 FUN_0822190c(ShadeMan* p) {
  Entity0805ee80* e = p->entity0805ee80;
  s32 busy = FALSE;
  s32 i;

  for (i = 0; i < 8; i++) {
    if (e->elems[i].active) {
      busy = TRUE;
    }
  }
  return busy;
}

// 原典はプレイヤーとの差分を Vec3 でなくレジスタに持ち, y の割り算の結果を捨てる (223/189)
NON_MATCH void FUN_08221938(ShadeMan* p) {
#ifdef NONMATCHING_C
  Vec3* pos = &p->base.mover.pos;
  Vec3* target = p->base.playerPos[0];
  s32 dx = target->x - pos->x;
  s32 dz = target->z - pos->z;
  u32 dist = Sqrt(dx * dx + dz * dz);
  s32 scale = Div((2200 - dist) << 16, 2200);
  Vec3 d;
  Vec3 cam;
  u32 len;

  if (scale < 0x1999) {
    scale = 0x1999;
  } else if (scale > 0x8000) {
    scale = 0x8000;
  }
  if (FUN_0822190c(p)) {
    scale = 0x1999;
    p->unk_c00 = 60;
  } else if (p->unk_c00 > 0) {
    scale = 0x1999;
    p->unk_c00--;
  }
  d.x = pos->x - target->x;
  d.y = pos->y - target->y;
  d.z = pos->z - target->z;
  len = Sqrt(d.x * d.x + d.y * d.y + d.z * d.z);
  if (len != 0) {
    d.x = Div(d.x * dist, len);
    d.y = Div(d.y * dist, len);
    d.z = Div(d.z * dist, len);
  }
  cam.x = target->x + FixToInt(16, scale * d.x);
  cam.y = target->y + 120;
  cam.z = target->z + FixToInt(16, scale * d.z);
  FUN_0823b980(8, &cam);
#else
  INCFUNC("asm/func/FUN_08221938.inc");
#endif
}

// 残差は他のボスの PollMessages と同じ gMsgBus の読み直し (133/131)
NON_MATCH void ShadeMan_PollMessages(ShadeMan* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  MsgQueue* queue = &boss->msgQueue;
  s32 i;

  for (i = 0; i < queue->count[gMsgBus->bufIdx]; i++) {
    MsgPacket* msg = queue->msgs[gMsgBus->bufIdx][i];

    MsgQueue_BeginWait(queue, msg);
    switch (msg->cmd) {
      case 0: {
        ShadeMan_SetSubState0(p, 2, 0, 0, 0);
        break;
      }
      case 1: {
        boss->mover.pos.x = msg->args[0];
        boss->mover.pos.y = msg->args[1];
        boss->mover.pos.z = msg->args[2];
        MsgQueue_EndWait(&boss->msgQueue, 1);
        break;
      }
      case 2: {
        ShadeMan_SetSubState0(p, 2, 0, 1, 0);
        p->stateDuration = msg->args[0];
        break;
      }
      case 33: {
        ShadeMan_SetSubState0(p, 2, 0, 4, 0);
        break;
      }
      case 34: {
        ShadeMan_SetSubState0(p, 2, 0, 5, 0);
        break;
      }
      case 35: {
        ShadeMan_SetSubState0(p, 2, 0, 2, 0);
        break;
      }
      case 36: {
        FUN_0821bd14(p);
        MsgQueue_EndWait(&boss->msgQueue, 1);
        break;
      }
      case 37: {
        ShadeMan_SetSubState0(p, 2, 0, 3, 0);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/ShadeMan_PollMessages.inc");
#endif
}

s32 ShadeMan_Update(ShadeMan* p) {
  FUN_0822129c(p);
  FUN_0821d800(p);
  ShadeMan_UpdateMotion(p);
  FUN_08221450(p);
  return 0;
}

s32 ShadeMan_Destroy(ShadeMan* p) {
  FUN_0821c918(p);
  AuxShadow_Remove(&p->shadow);
  Hitbox_Unregister(&p->hurtbox);
  Boss_Destroy(&p->base);
  return 0;
}

// 一通り書けたが VM 引数の受け方とレジスタがずれる (545/541)
NON_MATCH s32 ShadeMan_Init(ShadeMan* p, u32 id) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  BossID bossID = VM_GetNamedArgValue('t', -1);
  Vec3 pos;
  u32 angle;
  s32 hp;
  s32 power;

  Boss_Register(boss, bossID);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    angle = VM_GetValue();
  } else {
    VEC3_SET(pos, 0, 0, 0);
    angle = 0;
  }
  if (VM_SeekToNamedArg('r')) {
    p->centerPos.x = VM_GetValue();
    p->centerPos.y = VM_GetValue();
    p->centerPos.z = VM_GetValue();
  } else {
    p->centerPos.x = 0;
    p->centerPos.y = 0;
    p->centerPos.z = 0;
  }
  p->unk_3b0 = pos.y;
  if (VM_SeekToNamedArg('s')) {
    hp = VM_GetValue();
    power = VM_GetValue();
    p->hurtboxPower2 = VM_GetValue();
  } else {
    hp = 1000;
    power = 999;
    p->hurtboxPower2 = 400;
  }
  p->hurtboxPower = power;
  if (VM_SeekToNamedArg('b')) {
    p->unk_3dc = VM_GetValue();
    p->scriptID = VM_GetValue();
    p->scriptID2 = VM_GetValue();
  } else {
    p->unk_3dc = 500;
    p->scriptID = 0;
    p->scriptID2 = 0;
  }
  Boss_Init(boss, id, bossID, &pos, angle);
  Boss_InitHP(boss, hp, hp, power);
  boss->unk_114 = angle;
  boss->unk_ab = VM_GetNamedArgValue('i', 0);
  p->unk_388 = 0;
  p->unk_38c = 0;
  p->unk_390 = 0;
  p->motion = 0;
  p->nextMotion = -1;
  p->motionTimer = 0;
  p->unk_3a0 = 0;
  p->unk_3a4 = 0;
  p->motionCallback = NULL;
  ShadeMan_Init_Helper_0821c758(p, &pos, angle);
  AuxShadow_Init(&p->shadow, &p->sprite.pos, 0x40, 0x30, 0x40, 0x38, 0x1900, 1, 6, 1, 0);
  AuxShadow_SetSprite(&p->shadow, SPRITE_EFF_1C1B, 7);
  if (VM_SeekToNamedArg('a')) {
    p->hitboxPower = VM_GetValue();
    p->hitboxKnockback = VM_GetValue();
    p->hitboxUnk44 = VM_GetValue();
    p->hitbox2Power = VM_GetValue();
    p->hitbox2Knockback = VM_GetValue();
    p->hitbox2Unk44 = VM_GetValue();
    p->unk_3ca = VM_GetValue();
    p->unk_3cc = VM_GetValue();
    p->unk_3ce = VM_GetValue();
    p->unk_3d0 = VM_GetValue();
    p->unk_3d2 = VM_GetValue();
    p->unk_3d4 = VM_GetValue();
    p->unk_3d6 = VM_GetValue();
  } else {
    p->hitboxPower = 0;
    p->hitboxKnockback = 0;
    p->hitboxUnk44 = 0;
    p->hitbox2Power = 0;
    p->hitbox2Knockback = 0;
    p->hitbox2Unk44 = 0;
    p->unk_3ca = 0;
    p->unk_3cc = 0;
    p->unk_3ce = 0;
    p->unk_3d0 = 0;
    p->unk_3d2 = 0;
    p->unk_3d4 = 0;
    p->unk_3d6 = 0;
  }
  ShadeMan_InitHurtboxes(p, power);
  ShadeMan_InitHitboxes(p);
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
  p->weaponExp = VM_GetNamedArgValue('K', 0);
  if (gPlayerPtr[0] != NULL) {
    boss->players[0] = gPlayerPtr[0];
    boss->playerPos[0] = &gPlayerPtr[0]->mover.pos;
  } else {
    boss->players[0] = NULL;
    boss->playerPos[0] = NULL;
  }
  if (!boss->unk_ab) {
    ShadeMan_SetSubState0(p, 0, 0, 0, 120);
    ShadeMan_SetMotion(p, 0, TRUE);
  } else {
    ShadeMan_SetSubState0(p, 2, 0, 0, 0);
    ShadeMan_SetMotion(p, 15, TRUE);
    boss->flags |= BOSSFLAG_HIDDEN | BOSSFLAG_NO_SHADOW;
  }
  p->damage = 0;
  p->hurtAngle = 0;
  p->unk_3f0 = 0;
  p->unk_3f2 = 0;
  {
    s32 i;

    for (i = 0; i < 16; i++) {
      CpuFill32(0x7FFF7FFF, p->pltt[i], sizeof(p->pltt[i]));
    }
  }
  {
    rgb555* src = &gObjPlttData[7 * 16];
    s32 i;

    p->unk_3f4 = 0;
    for (i = 0; i < 16; i++) {
      CpuCopy32(src, p->pltt_600[i], sizeof(p->pltt_600[i]));
      src += 16;
    }
  }
  p->unk_3d8 = 0;
  p->unk_3d9 = 0;
  p->unk_3da = 0;
  p->unk_3db = 0;
  p->unk_3fc = 0;
  p->unk_bf6 = 0;
  p->unk_800 = 1;
  p->unk_808 = 0;
  p->unk_809 = 0;
  p->unk_80c = 0;
  p->unk_810 = 0;
  p->entity0805e67c = Entity0805e67c_Create();
  p->entity0805ee80 = Entity0805ee80_Create(120);
  p->unk_c00 = 0;
  return 0;
#else
  INCFUNC("asm/func/ShadeMan_Init.inc");
#endif
}

// 0x0623, HashName("シェードマン")
ShadeMan* ShadeMan_Create(u32 id) {
  ShadeMan* p = CreateEntity(ENTITY_UNK_8, sizeof(ShadeMan));
  if (p != NULL) {
    SetEntityRoutine(p, ShadeMan_Update, ShadeMan_Destroy);
    if (ShadeMan_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
