#include "boss/dvalinn.h"

#include "boss.h"
#include "camera.h"
#include "camera_inline.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "msgbus.h"
#include "nested_state.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

// ドヴァリン, ボス戦前の人型のイベント時もこれ使う
typedef struct Dvalinn {
  Boss base;                                 // 0x000
  u8 unk_158;                                // 0x158
  u8 unk_159[3];                             // 0x159
  HitboxData hurtbox;                        // 0x15C, ハンドラは Dvalinn_OnHurt
  HitboxData hitbox;                         // 0x1AC
  NestedState nestedState_1fc;               // 0x1FC
  NestedState nestedState;                   // 0x20C
  MainSpriteGfx gfx;                         // 0x21C, SPRITE_DVALINN
  MainSprite sprites[2];                     // 0x23C
  MainSpriteGfx gfx_2fc;                     // 0x2FC, SPRITE_DJANGO_SABATA
  MainSprite sprite_31c;                     // 0x31C
  AuxSpriteGfx auxGfx;                       // 0x37C
  AuxSprite auxSprite;                       // 0x398
  u16 unk_3c4;                               // 0x3C4
  u16 unk_3c6;                               // 0x3C6
  rgb555 pltt[16][16];                       // 0x3C8, gObjPlttData の同じ16色を16回写す
  rgb555 pltt_5c8[16][16];                   // 0x5C8, BlendPltt で色を混ぜる先
  s8 unk_7c8;                                // 0x7C8
  u8 unk_7c9;                                // 0x7C9
  u16 unk_7ca;                               // 0x7CA
  struct Entity082047f0* entity082047f0;     // 0x7CC
  u8 unk_7d0[0x7D2 - 0x7D0];                 // 0x7D0
  u16 damage;                                // 0x7D2, Dvalinn_OnHurt が受けたダメージを入れる
  u32 unk_7d4;                               // 0x7D4
  u16 unk_7d8;                               // 0x7D8, 下位状態が終わると 1 になり FUN_081fc394 が次の下位状態を選ぶ
  u16 unk_7da;                               // 0x7DA, 戦いの段階, hp が減ると 0 → 1 → 2 と進む
  s16 unk_7dc;                               // 0x7DC, FUN_081fa608 が足し込み FUN_081ff948 が hp から引く
  bool8 unk_7de;                             // 0x7DE, 炎属性の攻撃を受けたら立つ
  u8 unk_7df[0x7E2 - 0x7DF];                 // 0x7DF
  s16 hitboxPower;                           // 0x7E2, '.a[0]=100'
  s16 hitboxKnockback;                       // 0x7E4, '.a[1]=100'
  s16 hitboxUnk44;                           // 0x7E6
  s16 unk_7e8;                               // 0x7E8
  s16 unk_7ea;                               // 0x7EA
  s16 unk_7ec;                               // 0x7EC
  s16 unk_7ee;                               // 0x7EE
  s16 unk_7f0;                               // 0x7F0
  u16 unk_7f2;                               // 0x7F2, '.w[0]=70'
  s16 unk_7f4;                               // 0x7F4, unk_7f2 - '.w[1]'
  u16 unk_7f6;                               // 0x7F6
  u16 unk_7f8;                               // 0x7F8
  u16 unk_7fa;                               // 0x7FA
  s16 unk_7fc;                               // 0x7FC
  u16 unk_7fe;                               // 0x7FE
  s16 unk_800;                               // 0x800
  u16 unk_802;                               // 0x802, 0 でない間 Dvalinn_OnHurt がダメージを受けない
  u16 unk_804;                               // 0x804
  u8 unk_806;                                // 0x806, FUN_081fc890 で移った経路の番号
  u8 unk_807;                                // 0x807, FUN_081fc890 で移った経路のノード番号
  Vec3 unk_808;                              // 0x808, FUN_081fc890 で移る前の位置
  u8 unk_810[8];                             // 0x810
  u8 unk_818[8];                             // 0x818
  Vec3 unk_820[3];                           // 0x820
  u8 unk_838;                                // 0x838
  u8 unk_839[3];                             // 0x839
  struct Entity08202cd8* entity08202cd8[2];  // 0x83C
  s32 weaponExp;                             // 0x844, '.K'
} Dvalinn;
static_assert(sizeof(Dvalinn) == 2120);

COMMON_DATA Dvalinn* gDvalinn = NULL;                      // 0x03002C80
COMMON_DATA u8 u8_03002c84[0x03002C90 - 0x03002C84] = {};  // unused?

void BlendPlttToColor(rgb555* dst, rgb555* src, rgb555 color, s32 t, s32 shift);
void FUN_08203c64(struct Entity082047f0* p, rgb555* pltt);
s32 FUN_081e9f78(Vec3* pos, s32 count, u32 param_3, u32 animIdx, u32 plttIdx);
s32 FUN_081ea524(Mover* from, Mover* target, Vec3* vel, s32 param_4, s32 param_5, s32 param_6, s32 param_7);
s32 DustManager_Emit(s32 count, u32 angle, s32 angleRange, u32 speed, s32 speedRange, u32 delay, u32 power, s32 kind, Vec3* pos);
struct Entity082047f0* Entity082047f0_Create(Mover* mover);
Entity* Entity081ea120_Create(s32 param_1, s32 param_2);
void FUN_08203c4c(struct Entity082047f0* p, u32 param_2);
void FUN_08203c58(struct Entity082047f0* p, u32 param_2);
void FUN_08203d0c(struct Entity082047f0* p, u32 param_2);
void FUN_0820361c(Vec3* pos, Vec3* target, u32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11, s32 param_12, s32 param_13, s32 param_14);
void FUN_08203d38(struct Entity082047f0* p);
void FUN_080df148(WorldPos* pos, Vec3* vel, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9);
void FUN_08204d04(Vec3* pos, u32 param_2);
struct Entity081f26bcElem* Entity081f26bc_Spawn(
    Vec3* pos, Vec3* vel, u32 sprID, u32 animFID, u32 animIdx, SpriteFlags sprFlags, u32 flags, s32 plttID, u32 prio, u32 animVariant, u32 animFlags, u32 life, s32 power, s32 knockback, HitboxAttributes attrs, s32 invincibleTime, s32 ofsX, s32 ofsY);

extern const u32 u32_082526a4[7];

const u16 u16_ARRAY_085ae5fc[8] = {1536, 1536, 1536, 2304, 2304, 2304, 2304, 1536};  // 0x085AE5FC

void FUN_081fc86c(Dvalinn*);
void FUN_081fc890(Dvalinn* p, u32 param_2, u32 param_3);
void FUN_081ff734(Dvalinn*);
s32 FUN_081ff740(Dvalinn*);
void FUN_081ffd9c(Dvalinn*);
void FUN_081ffdb0(Dvalinn*);

void FUN_081fb2d4(Dvalinn*);
void FUN_081fb518(Dvalinn*);
void FUN_081fb664(Dvalinn*);
void FUN_081fbb08(Dvalinn*);
void FUN_081fc0a0(Dvalinn*);
void FUN_081fc1e4(Dvalinn*);
void FUN_081fc294(Dvalinn*);
void FUN_081fc298(Dvalinn*);

// Dvalinn + 0xA6 で引く (FUN_081fc394)
void (*const PTR_ARRAY_085ae60c[8])(Dvalinn*) = {
    FUN_081fb2d4,
    FUN_081fb518,
    FUN_081fb664,
    FUN_081fbb08,
    FUN_081fc0a0,
    FUN_081fc1e4,
    FUN_081fc294,
    FUN_081fc298,
};  // 0x085AE60C

void FUN_081fc394(Dvalinn*);
void FUN_081fc5b8(Dvalinn*);
void FUN_081fc5d4(Dvalinn*);
void FUN_081fc600(Dvalinn*);
void FUN_081fc62c(Dvalinn*);
void FUN_081fc658(Dvalinn*);
void FUN_081fc69c(Dvalinn*);
void FUN_081fc6e0(Dvalinn*);
void FUN_081fc724(Dvalinn*);
void FUN_081fc790(Dvalinn*);
void FUN_081fc808(Dvalinn*);
void FUN_081fc834(Dvalinn*);
void FUN_081fc850(Dvalinn*);

// Dvalinn + 0xA5 で引く (FUN_081fc5b8)
void (*const PTR_ARRAY_085ae62c[1])(Dvalinn*) = {
    FUN_081fc394,
};  // 0x085AE62C

// Dvalinn + 0xA6 で引く (FUN_081fc834)
void (*const PTR_ARRAY_085ae630[9])(Dvalinn*) = {
    FUN_081fc5d4,
    FUN_081fc600,
    FUN_081fc62c,
    FUN_081fc658,
    FUN_081fc69c,
    FUN_081fc6e0,
    FUN_081fc724,
    FUN_081fc790,
    FUN_081fc808,
};  // 0x085AE630

// Dvalinn + 0xA5 で引く (FUN_081fc850)
void (*const PTR_ARRAY_085ae654[1])(Dvalinn*) = {
    FUN_081fc834,
};  // 0x085AE654

// Dvalinn + 0xA4 で引く (FUN_081fc86c)
void (*const PTR_ARRAY_085ae658[2])(Dvalinn*) = {
    FUN_081fc5b8,
    FUN_081fc850,
};  // 0x085AE658

// スプライトの表示位置を時間でずらす表, FUN_081ff148 は 5 番目から 16 組をくり返す
typedef struct {
  u32 duration;  // 0x00, この組を続けるフレーム数
  s16 x;         // 0x04
  s16 y;         // 0x06
} DvalinnSpriteOfs;

void FUN_081fa608(s32 amount) { gDvalinn->unk_7dc += amount; }

u32 FUN_081fa620(Dvalinn* p) { return 561; }

// 原典は spawn を Vec3* を受ける inline で書き, mode 1 の sin 側の添字に & 0xFF が付かない
NON_MATCH void FUN_081fa628(Dvalinn* p, s32 mode) {
#ifdef NONMATCHING_C
  Vec3 vel;
  Vec3 base;
  Vec3 spawn;
  s32 i;

  CpuFill32(0, &vel, sizeof(vel));
  switch (mode) {
    case 0: {
      Vec3* pos;

      Vec3_SetPolar(&base, p->base.mover.angle, -256);
      pos = &p->base.mover.pos;
      Vec3_Add(&base, pos);
      base.y = (GetTileAt(&base)->heightStairs & 0xF) << 8;
      for (i = 0; i < 1; i++) {
        u8 angle = Random() & 0xFF;

        spawn.x = base.x + SIN(angle);
        spawn.y = base.y;
        spawn.z = base.z + COS(angle);
        Entity081f26bc_Spawn(&spawn, &vel, SPRITE_DVALIN_2E78, ANIM_38E2, 3, 0, 9, 0xDA, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      }
      break;
    }
    case 1: {
      Vec3* pos;

      Vec3_SetPolar(&base, p->base.mover.angle, -30);
      pos = &p->base.mover.pos;
      Vec3_Add(&base, pos);
      base.y = (GetTileAt(&base)->heightStairs & 0xF) << 8;
      for (i = 0; i < 4; i++) {
        u32 angle = i * 64 + (Random() & 0xF);

        spawn.x = base.x + POLAR_Z(256, angle);
        spawn.y = base.y;
        spawn.z = base.z + POLAR_X(256, angle);
        Entity081f26bc_Spawn(&spawn, &vel, SPRITE_EFF_F422, ANIM_121B, 6, 0, 9, 0x237, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      }
      Vec3_SetPolar(&base, p->base.mover.angle, -300);
      Vec3_Add(&base, pos);
      base.y = (GetTileAt(&base)->heightStairs & 0xF) << 8;
      for (i = 0; i < 4; i++) {
        u32 angle = i * 64 + (Random() & 0x1F);

        spawn.x = base.x + POLAR_Z(256, angle);
        spawn.y = base.y;
        spawn.z = base.z + POLAR_X(256, angle);
        Entity081f26bc_Spawn(&spawn, &vel, SPRITE_EFF_F422, ANIM_121B, 6, 0, 9, 0x237, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_081fa628.inc");
#endif
}

// 残差は CpuFill32 の 0 を書く位置だけ (191/191), FUN_081fae7c と同じ
NON_MATCH void FUN_081fabc0(Dvalinn* p, s32 radius) {
#ifdef NONMATCHING_C
  Vec3 vel;
  Vec3 pos;
  u8 angle;

  CpuFill32(0, &vel, sizeof(vel));
  Vec3_SetPolar(&pos, p->base.mover.angle, -90);
  Vec3_Add(&pos, &p->base.mover.pos);
  angle = Random();
  pos.x += POLAR_Z(radius, angle);
  pos.z += POLAR_X(radius, angle);
  if (!(gFrameCounter & 1)) {
    Entity081f26bc_Spawn(&pos, &vel, SPRITE_DVALIN_2E78, ANIM_38E2, 3, 0x200, 9, 0x232, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  } else {
    Entity081f26bc_Spawn(&pos, &vel, SPRITE_DVALIN_2E78, ANIM_38E2, 3, 0x400, 9, 0x232, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  }
#else
  INCFUNC("asm/func/FUN_081fabc0.inc");
#endif
}

void FUN_081fad7c(Dvalinn* p, s32 radius) {
  Vec3 pos;
  u8 angle;

  Vec3_SetPolar(&pos, p->base.mover.angle, -90);
  Vec3_Add(&pos, &p->base.mover.pos);
  angle = Random();
  pos.x += POLAR_Z(radius, angle);
  pos.z += POLAR_X(radius, angle);
  FUN_08204d04(&pos, 1);
}

// 残差は CpuFill32 の 0 を書く位置と p の写し方, 原典は Vec3* と 3 つの値を受ける inline で p を作る形 (FUN_081fc890 と同じ, 139/140 まで寄る)
NON_MATCH void FUN_081fae7c(Vec3* pos) {
#ifdef NONMATCHING_C
  u32 kinds[4];
  Vec3 vel;
  Vec3 p;
  u32 blink;
  u8 angle;
  u8 radius;
  u16* table;

  memcpy(kinds, u32_082526a4, sizeof(kinds));
  CpuFill32(0, &vel, sizeof(vel));
  blink = gFrameCounter & 1;
  table = gRandomTable;
  angle = _Random(table);
  radius = _Random(table);
  p.x = pos->x;
  p.y = pos->y;
  p.z = pos->z;
  p.x += Trig_Fix12ToInt(SIN(angle) * radius);
  p.z += Trig_Fix12ToInt(COS(angle) * radius);
  Entity081f26bc_Spawn(&p, &vel, SPRITE_DVALIN_2E78, ANIM_38E2, kinds[Random() & 3], blink == 0 ? 0x200 : 0x400, 9, 0x232, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
#else
  INCFUNC("asm/func/FUN_081fae7c.inc");
#endif
}

// 乱数テーブルの番地が巻き上げられて src がスタックに退避される
NON_MATCH void FUN_081fafd4(void) {
#ifdef NONMATCHING_C
  Vec3 vel;
  Vec3 pos;
  const u16* src;
  s32 i;

  CpuFill32(0, &vel, sizeof(vel));
  src = u16_ARRAY_085ae5fc;
  for (i = 0; i < 4; i++) {
    s32 r;

    pos.x = src[0];
    pos.z = src[1];
    if (i < 2) {
      r = Mod(Random(), 384);
      pos.x += r < 0 ? -r : r;
    } else {
      r = Mod(Random(), 384);
      pos.x -= r < 0 ? -r : r;
    }
    pos.y = (GetTileAt(&pos)->heightStairs & 0xF) << 8;
    if ((u8)Random() < 128) {
      FUN_08204d04(&pos, 1);
    } else {
      Entity081f26bc_Spawn(&pos, &vel, SPRITE_DVALIN_2E78, ANIM_38E2, 3, 0, 9, 0x232, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }

    pos.x = src[0];
    pos.z = src[1];
    if (i == 0 || i == 3) {
      r = Mod(Random(), 384);
      pos.z += r < 0 ? -r : r;
    } else {
      r = Mod(Random(), 384);
      pos.z -= r < 0 ? -r : r;
    }
    pos.y = (GetTileAt(&pos)->heightStairs & 0xF) << 8;
    if ((u8)Random() < 128) {
      FUN_08204d04(&pos, 1);
    } else {
      Entity081f26bc_Spawn(&pos, &vel, SPRITE_DVALIN_2E78, ANIM_38E2, 3, 0, 9, 0x232, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
    src += 2;
  }
#else
  INCFUNC("asm/func/FUN_081fafd4.inc");
#endif
}

// 残差は 1 命令だけ (227/227), 原典は 2 つ目の Map_PickRandomPathNode に渡す &b をループの外で作った r8 から渡す
NON_MATCH void FUN_081fb2d4(Dvalinn* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState_1fc;

  if (Boss_EnterSubState(&p->base)) {
    NestedState_Reset0(ns);
    Boss_RequestState(boss, 4);
  }
  switch (ns->state0) {
    case 0: {
      if (ns->timer0 == 0) {
        Vec3 a;
        Vec3 b;
        s32 node;

        do {
          node = Map_PickRandomPathNode(&a, 0);
        } while (node == Map_PickRandomPathNode(&b, 0));
        FUN_08201054(p->entity08202cd8[0], &a);
        FUN_08201054(p->entity08202cd8[1], &b);
        FUN_082010b4(p->entity08202cd8[0]);
        FUN_082010b4(p->entity08202cd8[1]);
        ns->timer0 = 1;
      } else {
        ns->timer0++;
      }
      switch (ns->timer0 & 3) {
        case 0: {
          FUN_081fae7c(&p->entity08202cd8[0]->pos);
          break;
        }
        case 2: {
          FUN_081fae7c(&p->entity08202cd8[1]->pos);
          break;
        }
      }
      if (ns->timer0 > 30) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 1: {
      if (ns->timer0 == 0) {
        p->entity08202cd8[0]->unk_6db = 1;
        p->entity08202cd8[1]->unk_6db = 1;
        ns->timer0 = 1;
      } else {
        ns->timer0++;
      }
      if (ns->timer0 > 10 && p->entity08202cd8[0]->unk_6d9 && p->entity08202cd8[1]->unk_6d9) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 2: {
      if (ns->timer0 == 0) {
        p->entity08202cd8[0]->unk_6db = 2;
        p->entity08202cd8[1]->unk_6db = 2;
      }
      if (++ns->timer0 > 140) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 3: {
      if (ns->timer0 == 0) {
        p->entity08202cd8[0]->unk_6db = 3;
      }
      if (++ns->timer0 > 30) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 4: {
      if (ns->timer0 == 0) {
        p->entity08202cd8[1]->unk_6db = 3;
      }
      if (++ns->timer0 > 30) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 5: {
      if (++ns->timer0 > 60) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 6: {
      if (ns->timer0 == 0) {
        p->entity08202cd8[0]->unk_6db = 5;
        p->entity08202cd8[1]->unk_6db = 5;
      }
      if (p->entity08202cd8[0]->unk_6d9 && p->entity08202cd8[1]->unk_6d9) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 7: {
      p->unk_7d8 = 1;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_081fb2d4.inc");
#endif
}

void FUN_081fb518(Dvalinn* p) {
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState_1fc;

  if (Boss_EnterSubState(&p->base)) {
    NestedState_Reset0(ns);
  }
  if (ns->state0 != 0 && ns->state0 != 4 && ns->state0 != 5 && boss->curState == 5) {
    NestedState_Set0(ns, 4);
  }
  switch (ns->state0) {
    case 0: {
      if (ns->timer0 == 0) {
        FUN_081fc890(p, 6, Random() & 3);
        Boss_RequestState(boss, 1);
        ns->timer0 = 1;
      } else if (boss->subStateDone) {
        NestedState_Set0(ns, 1);
      }
      break;
    }
    case 1: {
      if (ns->timer0 == 0) {
        Boss_RequestState(boss, 6);
        ns->timer0 = 1;
      } else if (boss->subStateDone) {
        NestedState_Set0(ns, 3);
      }
      break;
    }
    case 3: {
      if (++ns->timer0 > 1) {
        NestedState_Set0(ns, 2);
      }
      break;
    }
    case 2: {
      if (ns->timer0 == 0) {
        Boss_RequestState(boss, 3);
      }
      NestedState_Set0(ns, 5);
      break;
    }
    case 4: {
      if (boss->subStateDone || boss->curState == 3) {
        NestedState_Set0(ns, 5);
      }
      break;
    }
    case 5: {
      p->unk_7d8 = 1;
      break;
    }
  }
}

// case 1 と 3 の局所変数が原典では別のスタック領域に置かれ, p が上位レジスタに乗る
NON_MATCH void FUN_081fb664(Dvalinn* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState_1fc;

  if (Boss_EnterSubState(boss)) {
    NestedState_Reset0(ns);
  }
  if (boss->curState == 5 && boss->subStateDone) {
    Boss_RequestState(boss, 3);
  }
  switch (ns->state0) {
    case 0: {
      if (ns->timer0 == 0) {
        s32 i;

        if ((u8)Random() < 128) {
          FUN_081fc890(p, 2, 0);
        } else {
          FUN_081fc890(p, 5, 0);
        }
        Boss_RequestState(boss, 1);
        for (i = 0; i < 8; i++) {
          p->unk_810[i] = 0;
          p->unk_818[i] = i;
        }
      }
      NestedState_Set0(ns, 1);
      break;
    }
    case 1: {
      if (Mod(++ns->timer0, 16) == 0) {
        Mover from;
        Vec3 pos;
        Vec3 vel;
        Mover* target;

        Map_PickRandomPathNode(&pos, 0);
        pos.y = (GetTileAt(&pos)->heightStairs & 0xF) << 8;
        target = &gPlayerPtr[0]->mover;
        from.pos = pos;
        FUN_081e9f78(&pos, 1, 1, 0, 0x237);
        pos.y += 32;
        vel.x = target->pos.x - from.pos.x;
        vel.z = target->pos.z - from.pos.z;
        vel.x = Div(vel.x, 60);
        vel.z = Div(vel.z, 60);
        vel.y = 30;
        if (vel.x > 48) {
          vel.x = 48;
        }
        if (vel.x < -48) {
          vel.x = -48;
        }
        if (vel.z > 48) {
          vel.z = 48;
        }
        if (vel.z < -48) {
          vel.z = -48;
        }
        FUN_081ea524(&from, target, &vel, p->unk_7f0, 30, 0, 10);
        ns->timer1++;
      }
      if (ns->timer1 > 3) {
        NestedState_Set0(ns, 2);
      }
      break;
    }
    case 2: {
      if (++ns->timer0 > 90) {
        NestedState_Set0(ns, 3);
      }
      break;
    }
    case 3: {
      if (Mod(++ns->timer0, 16) == 0) {
        Mover from;
        Vec3 pos;
        Vec3 vel;
        Mover* target;

        Map_PickRandomPathNode(&pos, 0);
        pos.y = (GetTileAt(&pos)->heightStairs & 0xF) << 8;
        target = &gPlayerPtr[0]->mover;
        from.pos = pos;
        FUN_081e9f78(&pos, 1, 1, 0, 0x237);
        pos.y += 32;
        vel.x = target->pos.x - from.pos.x;
        vel.z = target->pos.z - from.pos.z;
        vel.x = Div(vel.x, 60);
        vel.z = Div(vel.z, 60);
        vel.y = 30;
        if (vel.x > 48) {
          vel.x = 48;
        }
        if (vel.x < -48) {
          vel.x = -48;
        }
        if (vel.z > 48) {
          vel.z = 48;
        }
        if (vel.z < -48) {
          vel.z = -48;
        }
        FUN_081ea524(&from, target, &vel, p->unk_7f0, 30, 0, 10);
        ns->timer1++;
      }
      if (ns->timer1 > 3) {
        NestedState_Set0(ns, 4);
      }
      break;
    }
    case 4: {
      if (++ns->timer0 > 20) {
        NestedState_Set0(ns, 5);
      }
      break;
    }
    case 5: {
      NestedState_Set0(ns, 6);
      break;
    }
    case 6: {
      p->unk_7d8 = 1;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_081fb664.inc");
#endif
}

// レジスタ割り当てと Vec3 のスタック配置が全体的にずれる (587/595)
NON_MATCH void FUN_081fbb08(Dvalinn* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState_1fc;

  if (Boss_EnterSubState(boss)) {
    u16* table;
    s32 i;
    s32 node;

    NestedState_Reset0(ns);
    table = gRandomTable;
    node = _Random(table) & 1;
    for (i = 0; i < 8; i++) {
      p->unk_810[i] = 0;
      p->unk_818[i] = node;
      node++;
      if (node < i + 5 && (_Random(table) & 3)) {
        node++;
      }
    }
    for (i = 0; i < 8; i++) {
      s32 a, b;
      s8 tmp;

      do {
        a = Mod(Random(), 8);
        b = Mod(Random(), 8);
      } while (a == b);
      tmp = p->unk_818[a];
      p->unk_818[a] = p->unk_818[b];
      p->unk_818[b] = tmp;
      tmp = p->unk_810[a];
      p->unk_810[a] = p->unk_810[b];
      p->unk_810[b] = tmp;
    }
    p->unk_838 = 0;
  }
  switch (ns->state0) {
    case 0: {
      if (ns->timer0 == 0) {
        s32 i;

        for (i = 0; i < 2; i++) {
          Vec3 pos;

          Map_GetPathNodePos(&pos, p->unk_810[i], p->unk_818[i]);
          pos.y = (GetTileAt(&pos)->heightStairs & 0xF) << 8;
          FUN_08201054(p->entity08202cd8[i], &pos);
          FUN_082010b4(p->entity08202cd8[i]);
        }
        ns->timer0 = 1;
      } else {
        ns->timer0++;
      }
      if (ns->timer0 > 150) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 1: {
      if (ns->timer0 == 0) {
        p->entity08202cd8[0]->unk_6db = 1;
        p->entity08202cd8[1]->unk_6db = 1;
        ns->timer0 = 1;
      } else {
        ns->timer0++;
      }
      if (p->entity08202cd8[0]->unk_6d9 && p->entity08202cd8[1]->unk_6d9) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 2: {
      if (ns->timer0 == 0) {
        p->entity08202cd8[0]->unk_6db = 2;
        p->entity08202cd8[1]->unk_6db = 2;
      }
      if (++ns->timer0 > 20) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 3: {
      switch (ns->state1) {
        case 0: {
          if (ns->timer1 == 0) {
            p->entity08202cd8[0]->unk_6db = 2;
            p->entity08202cd8[1]->unk_6db = 2;
            NestedState_Advance1(ns);
          }
          break;
        }
        case 1: {
          s32 done;
          bool32 waiting;
          s32 i;

          if (ns->timer1 == 0) {
            ns->timer1 = 1;
            p->unk_838 = 2;
            ns->timer0 = 31;
          }
          done = 0;
          waiting = FALSE;
          for (i = 0; i < 2; i++) {
            Entity08202cd8* e = p->entity08202cd8[i];

            if (!e->unk_6d9) {
              continue;
            }
            switch (e->unk_6dc) {
              case 1: {
                e->unk_6db = 2;
                break;
              }
              case 2: {
                if (!waiting && ++ns->timer0 > 30) {
                  e->unk_6db = 3;
                  ns->timer0 = 0;
                }
                waiting = TRUE;
                break;
              }
              case 3: {
                if (p->unk_838 < 8) {
                  e->unk_6db = 5;
                } else {
                  done++;
                }
                break;
              }
              case 5: {
                if (p->unk_838 < 8) {
                  Vec3 pos;

                  Map_GetPathNodePos(&pos, p->unk_810[p->unk_838], p->unk_818[p->unk_838]);
                  pos.y = (GetTileAt(&pos)->heightStairs & 0xF) << 8;
                  FUN_08201054(e, &pos);
                  p->entity08202cd8[i]->unk_6db = 1;
                  p->unk_838++;
                }
                break;
              }
            }
          }
          if ((p->unk_838 >= 8 && done >= 2) || TEST_FLAGS(boss->flags, BOSSFLAG_UNK_19)) {
            NestedState_Set1(ns, 2);
          }
          break;
        }
        case 2: {
          if (ns->timer1 == 0) {
            p->entity08202cd8[0]->unk_6db = 5;
            p->entity08202cd8[1]->unk_6db = 5;
          }
          if (++ns->timer1 > 30) {
            NestedState_Advance1(ns);
          }
          break;
        }
        case 3: {
          NestedState_Advance0(ns);
          break;
        }
      }
      break;
    }
    case 4: {
      if (++ns->timer0 > 60) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 5: {
      if (ns->timer0 == 0) {
        p->entity08202cd8[0]->unk_6db = 5;
        p->entity08202cd8[1]->unk_6db = 5;
      }
      if (p->entity08202cd8[0]->unk_6d9 && p->entity08202cd8[1]->unk_6d9) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 6: {
      p->unk_7d8 = 1;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_081fbb08.inc");
#endif
}

void FUN_081fc0a0(Dvalinn* p) {
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState_1fc;

  if (Boss_EnterSubState(&p->base)) {
    NestedState_Reset0(ns);
  }
  switch (ns->state0) {
    case 0: {
      if (ns->timer0 == 0) {
        if (Random() & 1) {
          FUN_081fc890(p, 2, 1);
        } else {
          FUN_081fc890(p, 5, 1);
        }
        Boss_RequestState(boss, 1);
        ns->timer0 = 1;
      } else {
        ns->timer0++;
        if (boss->subStateDone == TRUE) {
          NestedState_Set0(ns, 1);
        }
      }
      break;
    }
    case 1: {
      if (ns->timer0 == 0) {
        if ((u8)Random() > 128) {
          Boss_RequestState(boss, 7);
        } else {
          Boss_RequestState(boss, 8);
        }
        ns->timer0 = 1;
      } else {
        ns->timer0++;
        if (boss->subStateDone == TRUE) {
          NestedState_Set0(ns, 2);
        }
      }
      break;
    }
    case 2: {
      if (ns->timer0 == 0) {
        Boss_RequestState(boss, 3);
      }
      if (++ns->timer0 > 30) {
        NestedState_Set0(ns, 3);
      }
      break;
    }
    case 3: {
      if (++ns->timer0 > 60) {
        p->unk_7d8 = 1;
      }
      break;
    }
  }
}

void FUN_081fc1e4(Dvalinn* p) {
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState_1fc;

  if (Boss_EnterSubState(&p->base)) {
    NestedState_Reset0(ns);
  }
  switch (ns->state0) {
    case 0: {
      NestedState_Set0(ns, 1);
      break;
    }
    case 1: {
      if (ns->timer0 == 0) {
        Boss_RequestState(boss, 9);
      }
      if (++ns->timer0 > 10 && boss->subStateDone) {
        NestedState_Set0(ns, 2);
      }
      break;
    }
    case 2: {
      if (ns->timer0 == 0) {
        Boss_RequestState(boss, 3);
      }
      if (++ns->timer0 > 20) {
        NestedState_Set0(ns, 3);
      }
      break;
    }
    case 3: {
      p->unk_7d8 = 1;
      break;
    }
  }
}

void FUN_081fc294(Dvalinn* p) {}

void FUN_081fc298(Dvalinn* p) {
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState_1fc;

  if (Boss_EnterSubState(&p->base)) {
    s32 i;

    NestedState_Reset0(ns);
    if (!TEST_FLAGS(boss->flags, BOSSFLAG_HIDDEN) && boss->curState != 3 && boss->curState != 4) {
      Boss_RequestState(boss, 3);
    }
    for (i = 0; i < 2; i++) {
      if (p->entity08202cd8[i]->unk_6dc != 5 && p->entity08202cd8[i]->unk_6dc != 7) {
        p->entity08202cd8[i]->unk_6db = 5;
      }
    }
  }
  switch (ns->state0) {
    case 0: {
      if (TEST_FLAGS(boss->flags, BOSSFLAG_HIDDEN) && p->entity08202cd8[0]->unk_6dc == 7 && p->entity08202cd8[1]->unk_6dc == 7) {
        NestedState_Set0(ns, 1);
      }
      break;
    }
    case 1: {
      p->unk_7d8 = 1;
      break;
    }
  }
}

// 残差は乱数表を置くレジスタだけ (227/227)
NON_MATCH void FUN_081fc394(Dvalinn* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  p->unk_7d8 = 0;
  PTR_ARRAY_085ae60c[boss->subState2](p);
  if (p->unk_7d8 == 0) {
    return;
  }
  switch (p->unk_7da) {
    case 0: {
      if (boss->hp < Div(boss->maxHP, 10) * 7) {
        if (boss->subState2 != 7) {
          Boss_SetSubState2(boss, 7);
        } else {
          p->unk_7da = 1;
          Boss_SetSubState2(boss, 0);
        }
      } else {
        switch (boss->subState2) {
          case 0: {
            Boss_SetSubState2(boss, 2);
            break;
          }
          case 2: {
            Boss_SetSubState2(boss, 5);
            break;
          }
          case 5: {
            Boss_SetSubState2(boss, 0);
            break;
          }
        }
      }
      break;
    }
    case 1: {
      if (boss->hp < boss->maxHP >> 2) {
        if (boss->subState2 != 7) {
          Boss_SetSubState2(boss, 7);
        } else {
          p->unk_7da = 2;
          Boss_SetSubState2(boss, 3);
        }
      } else {
        switch (boss->subState2) {
          case 0: {
            if ((u8)Random() > 127) {
              Boss_SetSubState2(boss, 4);
            } else {
              Boss_SetSubState2(boss, 1);
            }
            break;
          }
          case 1: {
            Boss_SetSubState2(boss, 2);
            break;
          }
          case 4: {
            Boss_SetSubState2(boss, 2);
            break;
          }
          case 2: {
            Boss_SetSubState2(boss, 5);
            break;
          }
          case 5: {
            Boss_SetSubState2(boss, 0);
            break;
          }
        }
      }
      break;
    }
    case 2: {
      switch (boss->subState2) {
        case 3: {
          if ((u8)Random() < 128) {
            Boss_SetSubState2(boss, 1);
          } else {
            Boss_SetSubState2(boss, 4);
          }
          break;
        }
        case 1: {
          Boss_SetSubState2(boss, 2);
          break;
        }
        case 4: {
          Boss_SetSubState2(boss, 2);
          break;
        }
        case 2: {
          Boss_SetSubState2(boss, 5);
          break;
        }
        case 5: {
          Boss_SetSubState2(boss, 3);
          break;
        }
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_081fc394.inc");
#endif
}

void FUN_081fc5b8(Dvalinn* p) { PTR_ARRAY_085ae62c[p->base.subState1](p); }

void FUN_081fc5d4(Dvalinn* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 11);
  }
}

void FUN_081fc600(Dvalinn* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 12);
  }
}

void FUN_081fc62c(Dvalinn* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 13);
  }
}

void FUN_081fc658(Dvalinn* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 14);
  }
  if (p->base.subStateDone) {
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
}

void FUN_081fc69c(Dvalinn* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 15);
  }
  if (p->base.subStateDone) {
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
}

void FUN_081fc6e0(Dvalinn* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 17);
  }
  if (p->base.subStateDone) {
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
}

void FUN_081fc724(Dvalinn* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    FUN_081fc890(p, 5, 0);
    Boss_RequestState(boss, 1);
  }
  MainSprite_Hide(&p->sprites[1]);
  AuxSprite_Hide(&p->auxSprite);
  if (boss->subStateDone) {
    MsgQueue_EndWait(&boss->msgQueue, 1);
  }
}

void FUN_081fc790(Dvalinn* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    FUN_081fc890(p, 5, 0);
    Boss_RequestState(boss, 18);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
  MainSprite_Hide(&p->sprites[1]);
  AuxSprite_Hide(&p->auxSprite);
  if (boss->subStateDone) {
    MsgQueue_EndWait(&boss->msgQueue, 1);
  }
}

void FUN_081fc808(Dvalinn* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 19);
  }
}

void FUN_081fc834(Dvalinn* p) { PTR_ARRAY_085ae630[p->base.subState2](p); }

void FUN_081fc850(Dvalinn* p) { PTR_ARRAY_085ae654[p->base.subState1](p); }

void FUN_081fc86c(Dvalinn* p) {
  p->base.unk_9d = 0;
  PTR_ARRAY_085ae658[p->base.subState0](p);
}

// 残差は p と pos のレジスタ, 原典は center を 1 要素ずつ strh で書く (Vec3* を受ける inline の形, 155/156 まで寄る)
NON_MATCH void FUN_081fc890(Dvalinn* p, u32 pathIdx, u32 nodeIdx) {
#ifdef NONMATCHING_C
  Mover* mover = &p->base.mover;
  Vec3* pos = &p->base.mover.pos;
  Vec3 center;

  p->unk_808 = *pos;
  p->unk_806 = pathIdx;
  p->unk_807 = nodeIdx;
  Map_GetPathNodePos(pos, p->unk_806, p->unk_807);
  pos->y = (GetTileAt(pos)->heightStairs & 0xF) << 8;
  VEC3_SET(center, Q8(7.5), 0, Q8(7.5));
  center.y = (GetTileAt(&center)->heightStairs & 0xF) << 8;
  Boss_SetAngle(&p->base, ArcTan2_8(center.x - mover->pos.x, center.z - mover->pos.z));
#else
  INCFUNC("asm/func/FUN_081fc890.inc");
#endif
}

// 残差は p と boss のレジスタが逆 (127/127), FUN_081fed08 と同じ
NON_MATCH void FUN_081fca00(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 0, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  }
  boss->damageCallback(boss);
  if (Mod(timer, 10) == 0) {
    Vec3 pos;

    Vec3_SetPolar(&pos, boss->mover.angle, -90);
    Vec3_Add(&pos, &boss->mover.pos);
    Random();
    if ((u8)Random() > 128) {
      FUN_081fad7c(p, 180);
    } else {
      FUN_081fabc0(p, 150);
    }
  }
  Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
  boss->subStateDone = TRUE;
#else
  INCFUNC("asm/func/FUN_081fca00.inc");
#endif
}

// 原典は inline (目標への向き, 接地, 長さ合わせ) 経由らしく, p が上位レジスタに乗り乱数の & 0xFF が ldrb にならない
NON_MATCH void FUN_081fcb1c(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState;

  if (boss->stateEntered) {
    Vec3 center;

    boss->stateEntered = FALSE;
    SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_HIDDEN);
    VEC3_SET(center, Q8(7.5), 0, Q8(7.5));
    center.y = (GetTileAt(&center)->heightStairs & 0xF) << 8;
    Boss_SetAngle(boss, ArcTan2_8(center.x - boss->mover.pos.x, center.z - boss->mover.pos.z));
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 0, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
    NestedState_Reset0(ns);
    NestedState_Set0(ns, 1);
  }
  switch (ns->state0) {
    case 0: {
      Vec3 d;
      s32 distSq;
      u32 len;

      SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_HIDDEN);
      d.x = boss->mover.pos.x - p->unk_808.x;
      d.y = boss->mover.pos.y - p->unk_808.y;
      d.z = boss->mover.pos.z - p->unk_808.z;
      distSq = d.x * d.x + d.y * d.y + d.z * d.z;
      len = Sqrt(distSq);
      if (len == 0) {
        distSq = -1;
      } else {
        d.x = Div(d.x * 30, len);
        d.y = Div(d.y * 30, len);
        d.z = Div(d.z * 30, len);
      }
      if (distSq < 0x38C) {
        NestedState_Set0(ns, 1);
      } else if (ns->timer0 & 1) {
        Vec3_Add(&p->unk_808, &d);
        if ((u8)Random() > 128) {
          FUN_081fae7c(&p->unk_808);
        } else {
          Vec3 vel;
          Vec3 pos;
          u16* table;
          u32 angle;
          s32 radius;

          CpuFill32(0, &vel, sizeof(vel));
          table = gRandomTable;
          angle = _Random(table) & 0xFF;
          radius = _Random(table) & 0xFF;
          pos = p->unk_808;
          pos.x += Trig_Fix12ToInt(SIN(angle) * radius);
          pos.z += Trig_Fix12ToInt(SIN(angle) * radius);
          Entity081f26bc_Spawn(&pos, &vel, SPRITE_DVALIN_2E78, ANIM_38E2, 3, 0, 9, 0x232, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        }
      }
      ns->timer0++;
      break;
    }
    case 1: {
      if (++ns->timer0 > 120) {
        NestedState_Set0(ns, 2);
      }
      if (ns->timer0 > 90 && (ns->timer0 & 15) == 0) {
        if ((u8)Random() > 128) {
          FUN_081fad7c(p, 180);
        } else {
          FUN_081fabc0(p, 80);
        }
      }
      if (ns->timer0 & 1) {
        FUN_081fae7c(&boss->mover.pos);
      }
      SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_HIDDEN);
      break;
    }
    case 2: {
      if (ns->timer0 == 0) {
        FUN_081fa628(p, 1);
        boss->flags &= ~BOSSFLAG_HIDDEN;
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 0, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
        PlaySound_082406e0(SONG_439);
      }
      SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
      NestedState_Set0(ns, 3);
      break;
    }
    case 3: {
      boss->subStateDone = TRUE;
      Boss_SetState(boss, FUN_081fca00, 2);
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_081fcb1c.inc");
#endif
}

void FUN_081fcf54(Dvalinn* p, s32 timer) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    FUN_081fa628(p, 1);
    p->unk_7fc = p->unk_7fa;
    FUN_08203d38(p->entity082047f0);
    PlaySound_082406e0(SONG_439);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_HIDDEN);
  p->base.subStateDone = TRUE;
}

void FUN_081fcfb4(Dvalinn* p, s32 timer) {
  if (p->base.stateEntered) {
    p->base.stateEntered = FALSE;
    p->unk_7fc = p->unk_7fa;
    FUN_08203d38(p->entity082047f0);
  }
  SET_FLAGS(p->base.flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_HIDDEN);
  p->base.subStateDone = TRUE;
}

// 残差は pltt の格納先を各分岐で作るかどうか (224/226)
NON_MATCH void FUN_081fd000(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState;

  if (boss->stateEntered) {
    u32 plttIdx;

    boss->stateEntered = FALSE;
    NestedState_Reset0(ns);
    NestedState_Set0(ns, 0);
    FUN_08203d38(p->entity082047f0);
    p->unk_7fc = p->unk_7fa;
    p->unk_7c9 = 0;
    p->unk_7c8 = 0;
    p->unk_7ca = FUN_081fa620(p);
    plttIdx = FUN_081fa620(p);
    p->sprites[0].pltt = plttIdx == 0 ? p->pltt[0] : &gObjPlttData[plttIdx * 16];
  }
  switch (ns->state0) {
    case 0: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 10, PLAYMODE_ONCE_AND_STOP, 1, 0);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 2, PLAYMODE_ONCE_AND_STOP, 1, 0);
        NestedState_Set0(ns, 1);
      }
      if ((Random() & 3) >> 1) {
        FUN_081fa628(p, 0);
      }
      break;
    }
    case 1: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 12, PLAYMODE_ONCE_AND_STOP, 1, 0);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 0, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
        NestedState_Set0(ns, 2);
      }
      break;
    }
    case 2: {
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      boss->subStateDone = TRUE;
      Boss_SetState(boss, FUN_081fcf54, 3);
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_081fd000.inc");
#endif
}

// Vec3* を受ける inline (Set, 接地, Diff, Sub, 目標へ向く) で書くと 673/673, 残り 8 hunk は一時レジスタの番号だけ
NON_MATCH void FUN_081fd20c(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    NestedState_Reset0(ns);
    Boss_SetAngle(boss, ArcTan2_8(gPlayerPtr[0]->mover.pos.x - boss->mover.pos.x, gPlayerPtr[0]->mover.pos.z - boss->mover.pos.z));
    FUN_08203d0c(p->entity082047f0, 2);
  }
  boss->damageCallback(boss);
  switch (ns->state0) {
    case 0: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 2, PLAYMODE_LOOP, 1, 0);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 1: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 4, PLAYMODE_LOOP, 1, 0);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 2: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 6, PLAYMODE_LOOP, 1, 0);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 3: {
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      switch (ns->state1) {
        case 0: {
          Vec3 ofs;
          Vec3 shift;
          Vec3 center;
          u32 angle1 = (((u8)(boss->mover.angle - 64) - 32) & ~63) + 64;
          u32 angle2 = ((boss->mover.angle - 32) & ~63) + 64;
          s32 i;

          Vec3_SetPolar(&ofs, angle1, 256);
          Vec3_SetPolar(&shift, angle2, 256);
          VEC3_SET(center, Q8(7.5), 0, Q8(7.5));
          center.y = (GetTileAt(&center)->heightStairs & 0xF) << 8;
          Vec3_Sum(&p->unk_820[0], &center, &ofs);
          p->unk_820[1] = center;
          p->unk_820[2].x = center.x - ofs.x;
          p->unk_820[2].y = center.y - ofs.y;
          p->unk_820[2].z = center.z - ofs.z;
          for (i = 0; i < 3; i++) {
            switch (Mod(Random(), 3)) {
              case 0: {
                Vec3_Add(&p->unk_820[i], &shift);
                break;
              }
              case 1: {
                p->unk_820[i].x -= shift.x;
                p->unk_820[i].y -= shift.y;
                p->unk_820[i].z -= shift.z;
                break;
              }
              case 2: {
                break;
              }
            }
          }
          NestedState_Advance1(ns);
          break;
        }
        case 1: {
          FUN_0820361c(&boss->mover.pos, &p->unk_820[ns->timer0], p->unk_7f6, p->unk_7ec, 15, 2, 10, 3000, 18, p->unk_7ee, 5, 2, 10, 600);
          PlaySound_082406e0(SONG_440);
          ns->timer0++;
          NestedState_Advance1(ns);
          FUN_08203c4c(p->entity082047f0, 1);
          break;
        }
        case 2: {
          Vec3 v;
          u32 t;

          FUN_08203c4c(p->entity082047f0, 1);
          t = ++ns->timer1;
          if (t > p->unk_7f8) {
            FUN_08203c58(p->entity082047f0, 1);
            if (ns->timer0 > 2) {
              NestedState_Advance0(ns);
            } else {
              NestedState_Set1(ns, 1);
            }
          } else if (t == 1) {
            Vec3_SetPolar(&v, Angle_FromDir4(boss->facing), -60);
            Vec3_Add(&boss->mover.pos, &v);
          } else if (t < 10) {
            Vec3_SetPolar(&v, Angle_FromDir4(boss->facing), 6);
            Vec3_Add(&boss->mover.pos, &v);
          }
          break;
        }
      }
      break;
    }
    case 4: {
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (++ns->timer0 > 100) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 5: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 4, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_REVERSE);
        ns->timer0 = 1;
        FUN_08203d38(p->entity082047f0);
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 6: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 2, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_REVERSE);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 7: {
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 8: {
      boss->subStateDone = TRUE;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_081fd20c.inc");
#endif
}

// 原典の入口は Vec3* を受ける inline (中心座標を作る, 接地, 向きを合わせる) の形, ns が上位レジスタに乗る
NON_MATCH void FUN_081fd7fc(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState;

  if (boss->stateEntered) {
    Vec3 center;

    boss->stateEntered = FALSE;
    VEC3_SET(center, Q8(7.5), 0, Q8(7.5));
    center.y = (GetTileAt(&center)->heightStairs & 0xF) << 8;
    Boss_SetAngle(boss, ArcTan2_8(center.x - boss->mover.pos.x, center.z - boss->mover.pos.z));
    NestedState_Reset0(&p->nestedState);
  }
  boss->damageCallback(boss);
  switch (ns->state0) {
    case 0: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 2, PLAYMODE_LOOP, 1, 0);
        ns->timer0 = 1;
        FUN_08203d0c(p->entity082047f0, 1);
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 1: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 4, PLAYMODE_LOOP, 1, 0);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Set0(ns, 2);
      }
      break;
    }
    case 2: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFlip(boss, &p->sprites[0], &p->gfx, 8, PLAYMODE_LOOP, 0);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 3: {
      Vec3 vel;
      Vec3* pos;
      u32 angle;

      if (ns->timer0 == 0) {
        Boss_PlayAnimFlip(boss, &p->sprites[0], &p->gfx, 9, PLAYMODE_LOOP, 0);
        ns->timer0 = 1;
        PlaySound_082406e0(SONG_441);
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      pos = &boss->mover.pos;
      angle = ArcTan2_8(gPlayerPtr[0]->mover.pos.x - pos->x, gPlayerPtr[0]->mover.pos.z - pos->z) - 31;
      angle += Random() & 0x3F;
      Vec3_SetPolar(&vel, angle, 10);
      if (gFrameCounter & 1) {
        Vec3 spawn;
        u8 rnd = Random();

        Vec3_SetPolar(&spawn, boss->mover.angle, 80);
        spawn.x -= 32;
        spawn.y += 32;
        spawn.z -= 32;
        Vec3_Add(&spawn, pos);
        if (rnd < 128) {
          FUN_080df148(&spawn, &vel, 4, 300, 10, p->unk_7e8, 5, 8, 10);
        } else {
          FUN_080df148(&spawn, &vel, 8, 300, 10, p->unk_7e8, 5, 8, 10);
        }
        ns->timer0++;
      }
      if (ns->timer0 > 30) {
        NestedState_Set0(ns, 4);
      }
      break;
    }
    case 4: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 8, PLAYMODE_LOOP, 1, MAIN_ANIM_REVERSE);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (++ns->timer0 > 100) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 5: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 4, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_REVERSE);
        ns->timer0 = 1;
        FUN_08203d38(p->entity082047f0);
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 6: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 2, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_REVERSE);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 7: {
      FUN_081fa628(p, 1);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 8: {
      boss->subStateDone = TRUE;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_081fd7fc.inc");
#endif
}

static inline void Dvalinn_SetUnk7c8(Dvalinn* p, s32 mode, u32 unk_7ca) {
  p->unk_7c8 = mode;
  p->unk_7ca = unk_7ca;
  switch (p->unk_7c8) {
    case 1: {
      p->unk_7c9 = 0;
      p->unk_7ca = FUN_081fa620(p);
      break;
    }
    case 2: {
      p->unk_7c9 = 0;
      p->unk_7ca = unk_7ca;
      break;
    }
    case 3: {
      p->unk_7c9 = 0;
      p->unk_7ca = unk_7ca;
      break;
    }
    default: {
      p->unk_7c9 = 0;
      break;
    }
  }
}

// 入口が FUN_081fd7fc と同じ形で残り, 一時レジスタの番号がずれる
NON_MATCH void FUN_081fdd18(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState;

  if (boss->stateEntered) {
    Vec3 center;

    boss->stateEntered = FALSE;
    VEC3_SET(center, Q8(7.5), 0, Q8(7.5));
    center.y = (GetTileAt(&center)->heightStairs & 0xF) << 8;
    Boss_SetAngle(boss, ArcTan2_8(center.x - boss->mover.pos.x, center.z - boss->mover.pos.z));
    NestedState_Reset0(&p->nestedState);
  }
  boss->damageCallback(boss);
  switch (ns->state0) {
    case 0: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 2, PLAYMODE_ONCE_AND_STOP, 1, 0);
        ns->timer0 = 1;
        Dvalinn_SetUnk7c8(p, 1, 0);
        PlaySound_082406e0(SONG_442);
        FUN_08203d0c(p->entity082047f0, 1);
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 1: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 4, PLAYMODE_ONCE_AND_STOP, 1, 0);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Set0(ns, 2);
      }
      break;
    }
    case 2: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFlip(boss, &p->sprites[0], &p->gfx, 8, PLAYMODE_LOOP, 0);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (++ns->timer0 > 60) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 3:
    case 5:
    case 7: {
      if (ns->timer0 == 0) {
        PlaySound_082406e0(SONG_441);
      }
      if (!(ns->timer0 & 1)) {
        Vec3 pos;
        Vec3* bossPos;
        u8 rnd = Random();

        Vec3_SetPolar(&pos, boss->mover.angle, 80);
        pos.x -= 32;
        pos.y += 32;
        pos.z -= 32;
        pos.x += Trig_Fix12ToInt(SIN(rnd) * 64);
        pos.z += Trig_Fix12ToInt(COS(rnd) * 64);
        bossPos = &boss->mover.pos;
        Vec3_Add(&pos, bossPos);
        DustManager_Emit(1, ArcTan2_8(gPlayerPtr[0]->mover.pos.x - bossPos->x, gPlayerPtr[0]->mover.pos.z - bossPos->z), 0, 16, 8, 32, p->unk_7ea, 2, &pos);
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (++ns->timer0 > 60) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 4:
    case 6: {
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (++ns->timer0 > 30) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 8: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 8, PLAYMODE_LOOP, 1, MAIN_ANIM_REVERSE);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (++ns->timer0 > 100) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 9: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 4, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_REVERSE);
        ns->timer0 = 1;
        FUN_08203d38(p->entity082047f0);
        Dvalinn_SetUnk7c8(p, 2, 0x233);
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 10: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 2, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_REVERSE);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 11: {
      FUN_081fa628(p, 1);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 12: {
      boss->subStateDone = TRUE;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_081fdd18.inc");
#endif
}

// 移動ベクトルの正規化と目標への向きが原典では inline 経由らしく全体に崩れる (899/835)
NON_MATCH void FUN_081fe2e0(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  NestedState* ns = &p->nestedState;

  if (boss->stateEntered) {
    u8 angle;

    boss->stateEntered = FALSE;
    angle = ArcTan2_8(gPlayerPtr[0]->mover.pos.x - boss->mover.pos.x, gPlayerPtr[0]->mover.pos.z - boss->mover.pos.z);
    Boss_SetAngle(boss, ((angle - 32) & ~63) + 64);
    NestedState_Reset0(ns);
  }
  if (boss->damageCallback(boss)) {
    return;
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_0) && ns->state0 < 3) {
    Boss_SetState(boss, FUN_081fd000, 5);
    return;
  }
  switch (ns->state0) {
    case 0: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 2, PLAYMODE_ONCE_AND_STOP, 1, 0);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 1: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 4, PLAYMODE_ONCE_AND_STOP, 1, 0);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 2: {
      u32 phase;

      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 6, PLAYMODE_ONCE_AND_STOP, 1, 0);
        FUN_08203d0c(p->entity082047f0, 3);
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (ns->timer0 > p->unk_7f4) {
        Vec3 v;

        Vec3_SetPolar(&v, boss->mover.angle, -5);
        Vec3_Add(&boss->mover.pos, &v);
      }
      phase = ns->timer0 & 7;
      if (phase == 0 || phase == 3) {
        if ((u8)Random() < 128) {
          FUN_081fad7c(p, 400);
        } else {
          FUN_081fabc0(p, 350);
        }
      }
      if (++ns->timer0 > p->unk_7f2) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 3: {
      Vec3* target = &boss->targetPos;
      Vec3* pos;
      Vec3 d;
      s32 distSq;
      u32 dist;

      if (ns->timer0 == 0) {
        p->unk_807 = 1;
        Map_GetPathNodePos(target, p->unk_806, 1);
        target->y = (GetTileAt(target)->heightStairs & 0xF) << 8;
      }
      pos = &boss->mover.pos;
      d.x = target->x - pos->x;
      d.y = 0;
      d.z = target->z - pos->z;
      distSq = d.x * d.x + d.y * d.y + d.z * d.z;
      dist = (u16)Sqrt(distSq);
      if (dist == 0) {
        distSq = -1;
      } else {
        d.x = Div(d.x * 80, dist);
        d.y = Div(d.y * 80, dist);
        d.z = Div(d.z * 80, dist);
      }
      if (distSq <= 6400) {
        boss->mover.pos = *target;
        SET_FLAGS(boss->flags, BOSSFLAG_UNK_18);
        PlaySound_082406e0(SONG_555);
        FUN_081fafd4();
        NestedState_Advance0(ns);
      } else {
        Vec3_Add(pos, &d);
      }
      pos->y = (GetTileAt(pos)->heightStairs & 0xF) << 8;
      if ((ns->timer0 & 15) == 0) {
        if ((u8)Random() > 128) {
          FUN_081fad7c(p, 250);
        } else {
          FUN_081fabc0(p, 250);
        }
      }
      ns->timer0++;
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      break;
    }
    case 4: {
      FUN_08022c24(boss, 20, 150);
      if ((ns->timer0 & 3) == 0) {
        FUN_081fafd4();
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (++ns->timer0 > 10) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 5: {
      Vec3* target = &boss->targetPos;
      Vec3* pos;
      Vec3 d;
      s32 distSq;
      u32 dist;

      if (ns->timer0 == 0) {
        p->unk_807 = 0;
        Map_GetPathNodePos(target, p->unk_806, 0);
        target->y = (GetTileAt(target)->heightStairs & 0xF) << 8;
      }
      ns->timer0++;
      pos = &boss->mover.pos;
      d.x = target->x - pos->x;
      d.y = 0;
      d.z = target->z - pos->z;
      distSq = d.x * d.x + d.y * d.y + d.z * d.z;
      dist = (u16)Sqrt(distSq);
      if (dist == 0) {
        distSq = -1;
      } else {
        d.x = Div(d.x * 80, dist);
        d.y = Div(d.y * 80, dist);
        d.z = Div(d.z * 80, dist);
      }
      if (distSq <= 6400 || ns->timer0 > 10) {
        boss->mover.pos = *target;
        NestedState_Advance0(ns);
      } else {
        Vec3_Add(pos, &d);
      }
      pos->y = (GetTileAt(pos)->heightStairs & 0xF) << 8;
      break;
    }
    case 6: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 4, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_REVERSE);
        ns->timer0 = 1;
        FUN_08203d38(p->entity082047f0);
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 7: {
      if (ns->timer0 == 0) {
        Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 2, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_REVERSE);
        ns->timer0 = 1;
      }
      Boss_AdvanceAnim(boss, &p->sprites[0], &p->gfx);
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 8: {
      if (boss->animDone) {
        NestedState_Advance0(ns);
      }
      break;
    }
    case 9: {
      boss->subStateDone = TRUE;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_081fe2e0.inc");
#endif
}

// 残差は p と boss のレジスタが逆 (140/140), FUN_081fed08 と同じ
NON_MATCH void FUN_081fea80(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprites[0], &p->gfx, 10, PLAYMODE_ONCE_AND_STOP, 1, 0);
    Boss_GiveWeaponExp(boss, p->weaponExp);
    FUN_08022fb8(boss, &p->sprites[0].pos);
    MainSprite_SetAnim(&p->sprites[1], &p->gfx, 15, PLAYMODE_PAUSE, MAIN_ANIM_FORCE_POSE);
    p->sprites[1].pos = p->sprites[0].pos;
    MainSprite_Hide(&p->sprites[1]);
    FUN_08203d38(p->entity082047f0);
  }
  p->unk_804 = 15;
  p->unk_800 = 0;
  p->unk_7c8 = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HITBOX);
  MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx);
  if (timer < 218) {
    if (boss->unk_155) {
      if ((boss->frameCount & 3) < 2) {
        MainSprite_Show(&p->sprites[1]);
      } else {
        MainSprite_Hide(&p->sprites[1]);
      }
    }
    FUN_081fa628(p, 0);
  } else {
    MainSprite_Hide(&p->sprites[1]);
  }
  if (timer == 128) {
    FUN_08023024(boss, &p->sprites[0].pos);
  }
#else
  INCFUNC("asm/func/FUN_081fea80.inc");
#endif
}

void FUN_081febb8(Dvalinn* p, s32 timer) {
  Boss* boss = &p->base;

  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_HIDDEN);
  MainSprite_Hide(&p->sprites[1]);
  MainSprite_Hide(&p->sprite_31c);
}

void FUN_081febe4(Dvalinn* p, s32 timer) {
  Boss* boss = &p->base;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    MainSprite_SetAnim(&p->sprites[1], &p->gfx, 14, PLAYMODE_PAUSE, MAIN_ANIM_FORCE_POSE);
    p->sprites[1].pos = p->sprites[0].pos;
    NestedState_Reset0(&p->nestedState);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_HIDDEN);
  MainSprite_Show(&p->sprites[1]);
  MainSprite_Hide(&p->sprite_31c);
}

void FUN_081fec60(Dvalinn* p, s32 timer) {
  Boss* boss = &p->base;

  if (boss->stateEntered) {
    MainSprite* sprite;

    boss->stateEntered = FALSE;
    sprite = &p->sprites[1];
    MainSprite_SetAnim(sprite, &p->gfx, 14, PLAYMODE_PAUSE, MAIN_ANIM_FORCE_POSE);
    p->sprites[1].pos = p->sprites[0].pos;
    NestedState_Reset0(&p->nestedState);
    sprite->flags |= SPRFLAG_AFFINE;
  }
  if (++p->sprites[1].scaleY > 127) {
    p->sprites[1].scaleY = 127;
  }
  p->sprites[1].scaleX = p->sprites[1].scaleY;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_HIDDEN);
  MainSprite_Show(&p->sprites[1]);
  MainSprite_Hide(&p->sprite_31c);
}

// 残差は p と boss のレジスタが逆 (101/101)
NON_MATCH void FUN_081fed08(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    MainSprite_SetAnim(&p->sprites[1], &p->gfx, 16, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    p->sprites[1].pos = p->base.mover.pos;
    NestedState_Reset0(&p->nestedState);
  }
  if ((timer & 15) == 0) {
    if ((u8)Random() > 128) {
      FUN_081fad7c(p, 0x40);
    } else {
      FUN_081fabc0(p, 0x40);
    }
  }
  MainSprite_Show(&p->sprites[1]);
  if (MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx)) {
    MainSprite_SetAnim(&p->sprites[1], &p->gfx, 17, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    boss->subStateDone = TRUE;
  }
  SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
  MainSprite_Hide(&p->sprite_31c);
#else
  INCFUNC("asm/func/FUN_081fed08.inc");
#endif
}

void FUN_081fedec(Dvalinn* p, s32 timer) {
  if (gPlayerPtr[0]->kind == PLAYER_SOLAR_DJANGO) {
    MainSprite_SetPlttID(&p->sprite_31c, 0x1D);
    if ((timer & 15) == 0) {
      switch ((timer >> 4) & 3) {
        case 0: {
          MainSprite_SetAnim(&p->sprite_31c, &p->gfx_2fc, 0x30, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
          break;
        }
        case 1: {
          MainSprite_SetAnim(&p->sprite_31c, &p->gfx_2fc, 0x31, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
          break;
        }
        case 2: {
          MainSprite_SetAnim(&p->sprite_31c, &p->gfx_2fc, 0x32, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
          break;
        }
        case 3: {
          MainSprite_SetAnim(&p->sprite_31c, &p->gfx_2fc, 0x33, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
          break;
        }
      }
    }
    MainSprite_AdvanceAnim(&p->sprite_31c, &p->gfx_2fc);
  } else {
    MainSprite_SetPlttID(&p->sprite_31c, 0x26);
    if ((timer & 15) == 0) {
      switch ((timer >> 4) & 3) {
        case 0: {
          MainSprite_SetAnim(&p->sprite_31c, &p->gfx_2fc, 0xF7, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
          break;
        }
        case 1: {
          MainSprite_SetAnim(&p->sprite_31c, &p->gfx_2fc, 0xF8, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
          break;
        }
        case 2: {
          MainSprite_SetAnim(&p->sprite_31c, &p->gfx_2fc, 0xF9, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
          break;
        }
        case 3: {
          MainSprite_SetAnim(&p->sprite_31c, &p->gfx_2fc, 0xFA, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
          break;
        }
      }
    }
    MainSprite_AdvanceAnim(&p->sprite_31c, &p->gfx_2fc);
  }
}

// clang-format off
const DvalinnSpriteOfs DvalinnSpriteOfs_ARRAY_085ae660[33] = {
    {2, -3, 19},
    {3, -6, 16},
    {4, -14, 4},
    {6, -14, -20},
    {6, -6, -52},
    {4, -4, -70},
    {4, 1, -70},
    {4, 7, -70},
    {4, 12, -66},
    {4, 20, -75},
    {4, 29, -53},
    {4, 33, -48},
    {4, 33, -40},
    {4, 31, -35},
    {4, 19, -33},
    {4, 8, -36},
    {4, 0, -38},
    {4, -10, -42},
    {4, -13, -47},
    {4, -18, -53},
    {4, -13, -64},
    {2, 42, 21},
    {1, 34, 41},
    {1, 18, 49},
    {1, 6, 45},
    {1, -6, 41},
    {1, -14, 28},
    {2, -20, 12},
    {2, -27, -7},
    {2, -30, -27},
    {2, -30, -43},
    {2, -18, -58},
    {2, -8, -63},
};  // 0x085AE660
// clang-format on

void FUN_081ff148(Dvalinn*, s32);

// 1 回目で打ち切り (244/241)
NON_MATCH void FUN_081fef30(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    MainSprite_SetAnim(&p->sprites[1], &p->gfx, 18, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    p->sprites[1].pos = boss->mover.pos;
    NestedState_Reset0(&p->nestedState);
    p->unk_3c4 = 0;
    p->unk_3c6 = 0;
  }
  if ((timer & 15) == 0) {
    if ((u8)Random() > 128) {
      FUN_081fad7c(p, 0x40);
    } else {
      FUN_081fabc0(p, 0x40);
    }
  }
  MainSprite_Show(&p->sprites[1]);
  if (MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx)) {
    boss->subStateDone = TRUE;
    Boss_SetState(boss, FUN_081ff148, 16);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
  if (timer > 13) {
    const DvalinnSpriteOfs* ofs = &DvalinnSpriteOfs_ARRAY_085ae660[p->unk_3c6 + 21];
    Vec3* pos;
    Vec3* vp;
    s32 x, z, a, b;

    if (++p->unk_3c4 >= ofs->duration) {
      p->unk_3c4 = 0;
      if (++p->unk_3c6 > 12) {
        p->unk_3c6 = 0;
      }
    }
    vp = &p->sprite_31c.pos;
    pos = &boss->mover.pos;
    x = pos->x >> 1;
    z = pos->z >> 1;
    vp->x = FixToInt(8, (x - z) * 48);
    a = FixToInt(8, (x + z) * 48);
    b = FixToInt(8, pos->y * 24);
    vp->x = vp->x - gCameraVpCoords.x + 120;
    vp->y = (a - b) - gCameraVpCoords.y + 90;
    vp->z = (a + b) - gCameraVpCoords.z;
    p->sprite_31c.pos.x += ofs->x;
    p->sprite_31c.pos.y += ofs->y;
    p->auxSprite.pos = p->sprite_31c.pos;
    FUN_081fedec(p, timer);
    MainSprite_Show(&p->sprite_31c);
    AuxSprite_Show(&p->auxSprite);
  }
#else
  INCFUNC("asm/func/FUN_081fef30.inc");
#endif
}

// 1 回目で打ち切り (236/235)
NON_MATCH void FUN_081ff148(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  const DvalinnSpriteOfs* ofs;
  bool32 done;
  Vec3* pos;
  Vec3* vp;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    MainSprite_SetAnim(&p->sprites[1], &p->gfx, 17, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    p->sprites[1].pos = boss->mover.pos;
    NestedState_Reset0(&p->nestedState);
    p->unk_3c4 = 1;
    p->unk_3c6 = 0;
  }
  MainSprite_Show(&p->sprites[1]);
  done = MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx);
  if ((timer & 15) == 0) {
    if ((u8)Random() > 128) {
      FUN_081fad7c(p, 0x40);
    } else {
      FUN_081fabc0(p, 0x40);
    }
  }
  if (done) {
    p->unk_3c4 = 0;
    p->unk_3c6 = 0;
    boss->subStateDone = TRUE;
  }
  SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
  ofs = &DvalinnSpriteOfs_ARRAY_085ae660[p->unk_3c6 + 5];
  if (++p->unk_3c4 >= ofs->duration) {
    p->unk_3c4 = 0;
    if (++p->unk_3c6 > 15) {
      p->unk_3c6 = 0;
    }
  }
  vp = &p->sprite_31c.pos;
  pos = &boss->mover.pos;
  WorldToScreen(vp, pos);
  p->sprite_31c.pos.x += ofs->x;
  p->sprite_31c.pos.y += ofs->y;
  MainSprite_Show(&p->sprite_31c);
  AuxSprite_Show(&p->auxSprite);
  p->auxSprite.pos = p->sprite_31c.pos;
  FUN_081fedec(p, timer);
#else
  INCFUNC("asm/func/FUN_081ff148.inc");
#endif
}

// p と boss のレジスタ役割が入れ替わる
NON_MATCH void FUN_081ff34c(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  const DvalinnSpriteOfs* ofs;
  bool32 done;
  Vec3* pos;
  Vec3* vp;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    MainSprite_SetAnim(&p->sprites[1], &p->gfx, 16, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_REVERSE | MAIN_ANIM_FORCE_POSE);
    p->sprites[1].pos = boss->mover.pos;
    NestedState_Reset0(&p->nestedState);
    p->unk_3c4 = 0;
    p->unk_3c6 = 4;
  }
  MainSprite_Show(&p->sprites[1]);
  done = MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx);
  SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
  ofs = &DvalinnSpriteOfs_ARRAY_085ae660[p->unk_3c6];
  p->unk_3c4++;
  if (p->unk_3c4 > ofs->duration) {
    p->unk_3c4 = 0;
    if (p->unk_3c6 != 0) {
      p->unk_3c6--;
    }
  }
  vp = &p->sprite_31c.pos;
  pos = &boss->mover.pos;
  WorldToScreen(vp, pos);
  p->sprite_31c.pos.x += ofs->x;
  p->sprite_31c.pos.y += ofs->y;
  p->auxSprite.pos = p->sprite_31c.pos;
  MainSprite_Show(&p->sprite_31c);
  AuxSprite_Show(&p->auxSprite);
  FUN_081fedec(p, timer);
  if (done) {
    Vec3 vel;

    boss->subStateDone = TRUE;
    MainSprite_Hide(&p->sprites[1]);
    MainSprite_Hide(&p->sprite_31c);
    AuxSprite_Hide(&p->auxSprite);
    Boss_SetState(boss, FUN_081febb8, 11);
    CpuFill32(0, &vel, sizeof(vel));
    Entity081f26bc_Spawn(&p->sprites[1].pos, &vel, SPRITE_EFF_F422, ANIM_121B, 6, 0, 9, 0x237, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0);
  } else if ((timer & 15) == 0) {
    if ((u8)Random() > 128) {
      FUN_081fad7c(p, 0x40);
    } else {
      FUN_081fabc0(p, 0x40);
    }
  }
#else
  INCFUNC("asm/func/FUN_081ff34c.inc");
#endif
}

// 残差は乱数の 0xFF の持ち方 (54/57), 原典は 2 つ目の乱数を ldrh と 0xFF の and で読む
NON_MATCH void FUN_081ff5cc(Dvalinn* p, s32 timer) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  if (Mod(timer, 8) == 0) {
    if ((u8)Random() < 240) {
      FUN_081fae7c(&boss->mover.pos);
    } else {
      FUN_081fad7c(p, Random() & 0xFF);
    }
  }
  MainSprite_Hide(&p->sprites[1]);
  AuxSprite_Hide(&p->auxSprite);
  SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
#else
  INCFUNC("asm/func/FUN_081ff5cc.inc");
#endif
}

void FUN_081ff658(Dvalinn* p, s32 timer) {
  Boss* boss = &p->base;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    MainSprite_SetAnim(&p->sprites[1], &p->gfx, 14, PLAYMODE_PAUSE, MAIN_ANIM_FORCE_POSE);
    p->sprites[1].pos = p->sprites[0].pos;
    Dvalinn_SetUnk7c8(p, 3, 0x239);
  }
  MainSprite_Show(&p->sprites[1]);
  AuxSprite_Hide(&p->auxSprite);
  SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
}

void FUN_081ff734(Dvalinn* p) { Boss_UpdateState(&p->base); }

s32 FUN_081ff740(Dvalinn* p) {
  // clang-format off
  static void (*const PTR_ARRAY_085ae768[20])(Dvalinn*, s32) = {
      NULL,
      FUN_081fcb1c,
      FUN_081fca00,
      FUN_081fcf54,
      FUN_081fcfb4,
      FUN_081fd000,
      FUN_081fd20c,
      FUN_081fd7fc,
      FUN_081fdd18,
      FUN_081fe2e0,
      FUN_081fea80,
      FUN_081febb8,
      FUN_081febe4,
      FUN_081fec60,
      FUN_081fed08,
      FUN_081fef30,
      FUN_081ff148,
      FUN_081ff34c,
      FUN_081ff5cc,
      FUN_081ff658,
  };  // 0x085AE768
  // clang-format on

  if (p->base.state == 0 || p->base.state > 20) {
    return FALSE;
  } else {
    Boss_SetState(&p->base, PTR_ARRAY_085ae768[p->base.state], p->base.state);
    return TRUE;
  }
}

// 残差は p を 2 本目のレジスタに写して unk_7de を書くところ (42/43), ((Dvalinn*)boss)->unk_7de と書くと一致する
NON_MATCH void Dvalinn_OnHurt(HitboxData* a, HitboxData* b, Dvalinn* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;

  if (!TEST_FLAGS(boss->flags, BOSSFLAG_HIDDEN)) {
    if (p->unk_802 == 0) {
      Hitbox_ApplyDamage(a, b);
      p->damage = b->damage;
      Boss_SetWeaponExpMask(boss, a->weakness);
      Boss_SetHurtAttributes(boss, a->attributes);
    }
    if (TEST_FLAGS(a->attributes, HBATTR_FLAME)) {
      p->unk_7de = TRUE;
    }
  }
#else
  INCFUNC("asm/func/Dvalinn_OnHurt.inc");
#endif
}

void FUN_081ff7e8(HitboxData* a, HitboxData* b, Dvalinn* p) {
  b->damage = 0;
  p->unk_7d4 = 1;
}

void Dvalinn_InitHitbox(Dvalinn* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(1), Q8(1), Q8(1));
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &p->sprites[0].pos, 0);
  Hitbox_SetHandler(hitbox, FUN_081ff7e8, p);
  Hitbox_SetAttack(hitbox, p->hitboxPower, p->hitboxKnockback, 0, HBATTR_18, p->hitboxUnk44);
}

void Dvalinn_InitHurtbox(Dvalinn* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(1), Q8(1), Q8(1));
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &p->sprites[0].pos, 0);
  Hitbox_SetHandler(hurtbox, Dvalinn_OnHurt, p);
  Hitbox_SetPowerAndAttributes(hurtbox, power, HBATTR_IMMORTAL | HBATTR_FROST, HBATTR_FLAME);
  Hitbox_Register(hurtbox);
}

void FUN_081ff948(Dvalinn* p) {
  if (p->unk_7dc > 0) {
    s32 hp = p->base.hp - p->unk_7dc;

    if (hp > 1) {
      p->base.hp = hp;
    } else {
      p->base.hp = 1;
      SET_FLAGS(p->base.flags, BOSSFLAG_UNK_19);
    }
  }
}

// 1 回目で打ち切り (221/220), 原典は 0 と 0x7D2 をレジスタに残して使い回す
NON_MATCH s32 FUN_081ff988(Dvalinn* p) {
#ifdef NONMATCHING_C
  s32 damage = (s16)p->damage;

  p->damage = 0;
  if (damage > 0) {
    Vec3 ofs;

    p->unk_7fc -= p->unk_7fe + damage;
    p->base.hp -= damage;
    p->unk_802 = 15;
    p->unk_800 = 10;
    p->sprites[0].pltt = p->pltt[0];
    VEC3_SET(ofs, Q8(0.063), 0, Q8(0.063));
    CreateDamageNumber(&p->hurtbox, damage, 0, &p->base.mover.pos, &ofs, 1);
    if (p->unk_7de == TRUE) {
      Vec3 size;

      VEC3_SET(size, Q8(0.641), Q8(0.063), Q8(0.641));
      EmitSmoke(&p->sprites[0].pos, 3, &size, (u8)Random(), (Random() & 3) + 2, (Random() & 3) + 20, 2, 2);
    }
    if (p->base.hp <= 0) {
      PlaySound_082406e0(SONG_450);
      p->base.hp = 0;
      SET_FLAGS(p->base.flags, BOSSFLAG_UNK_1);
      Boss_SetSubStates(&p->base, 0, 0, 6);
      Boss_SetState(&p->base, FUN_081fea80, 10);
      return TRUE;
    }
    p->unk_804 = 15;
    PlaySound_082406e0(SONG_449);
    if (p->unk_7fc <= 0) {
      SET_FLAGS(p->base.flags, BOSSFLAG_UNK_0);
      if (p->base.curState == 9) {
        Boss_SetState(&p->base, FUN_081fd000, 5);
      }
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_081ff988.inc");
#endif
}

// 残差は gMsgBus の読み直し (152/153), Duneyrr_PollMessages と同じ壁
NON_MATCH void Dvalinn_PollMessages(Dvalinn* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  MsgQueue* queue = &boss->msgQueue;
  s32 i;

  for (i = 0; i < queue->count[gMsgBus->bufIdx]; i++) {
    MsgPacket* msg = queue->msgs[gMsgBus->bufIdx][i];

    MsgQueue_BeginWait(queue, msg);
    switch (msg->cmd) {
      case 0: {
        Boss_SetSubStates(boss, 1, 0, 0);
        break;
      }
      case 1: {
        boss->mover.pos.x = msg->args[0];
        boss->mover.pos.y = msg->args[1];
        boss->mover.pos.z = msg->args[2];
        p->sprites[0].pos.x = boss->mover.pos.x;
        p->sprites[0].pos.y = boss->mover.pos.y;
        p->sprites[0].pos.z = boss->mover.pos.z;
        MsgQueue_EndWait(&boss->msgQueue, 1);
        break;
      }
      case 10: {
        Boss_SetSubStates(boss, 1, 0, 1);
        break;
      }
      case 51: {
        Boss_SetSubStates(boss, 1, 0, 8);
        break;
      }
      case 48: {
        Boss_SetSubStates(boss, 1, 0, 2);
        break;
      }
      case 49: {
        Boss_SetSubStates(boss, 1, 0, 6);
        break;
      }
      case 50: {
        Boss_SetSubStates(boss, 1, 0, 7);
        break;
      }
      case 45: {
        Boss_SetSubStates(boss, 1, 0, 3);
        break;
      }
      case 46: {
        Boss_SetSubStates(boss, 1, 0, 4);
        break;
      }
      case 47: {
        Boss_SetSubStates(boss, 1, 0, 5);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/Dvalinn_PollMessages.inc");
#endif
}

void FUN_081ffd9c(Dvalinn* p) {
  p->base.state = 0;
  Dvalinn_PollMessages(p);
}

// 揺れの加算が ldrsh になり, mover と &flags のレジスタが入れ替わる
NON_MATCH void FUN_081ffdb0(Dvalinn* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  Mover* mover;
  HitboxData* hitbox;

  p->sprites[0].pos = boss->mover.pos;
  if (p->unk_804 != 0) {
    u16* table;

    p->unk_804--;
    table = gRandomTable;
    p->sprites[0].pos.x += (_Random(table) & 0x1F) - 15;
    p->sprites[0].pos.y += (_Random(table) & 0x1F) - 15;
    p->sprites[0].pos.z += (_Random(table) & 0x1F) - 15;
  }
  mover = &boss->mover;
  if (p->unk_802 != 0) {
    SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
    if (--p->unk_802 == 0) {
      boss->flags &= ~BOSSFLAG_NO_HURTBOX;
    }
  }
  hitbox = &p->hurtbox;
  if (TEST_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX)) {
    Hitbox_SetFlags(hitbox, HBFLAG_HIDDEN);
  } else {
    Vec3 pos;
    u32 angle;

    Hitbox_ClearFlags(hitbox, HBFLAG_HIDDEN);
    angle = ((mover->angle - 32) & ~63) + 64;
    Vec3_SetPolar(&pos, angle, -160);
    Vec3_Add(&pos, &mover->pos);
    Hitbox_SetPos(hitbox, &pos, 0);
    hitbox->angle = mover->angle;
  }
  hitbox = &p->hitbox;
  if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_18) && gPlayerPtr[0]->kind != PLAYER_BAT) {
    hitbox->halfSize.x = 0x800, hitbox->halfSize.y = 0x800, hitbox->halfSize.z = 0x800;
    Hitbox_SetPos(hitbox, &mover->pos, 0);
    hitbox->angle = mover->angle;
    Hitbox_Register(hitbox);
  } else {
    hitbox->halfSize.x = 0x100, hitbox->halfSize.y = 0x100, hitbox->halfSize.z = 0x100;
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_HIDDEN)) {
    MainSprite_Hide(&p->sprites[0]);
  } else {
    MainSprite_Show(&p->sprites[0]);
  }
  if (p->unk_800 > 0) {
    if (--p->unk_800 == 0) {
      p->sprites[0].pltt = &gObjPlttData[0x231 * 16];
    }
  } else {
    switch (p->unk_7c8) {
      case 1: {
        p->unk_7ca = 0x233;
        BlendPltt(p->pltt_5c8[0], &gObjPlttData[FUN_081fa620(p) * 16], &gObjPlttData[p->unk_7ca * 16], p->unk_7c9, 7);
        p->sprites[0].pltt = p->pltt_5c8[0];
        FUN_08203c64(p->entity082047f0, p->pltt_5c8[0]);
        if (++p->unk_7c9 > 126) {
          p->unk_7c9 = 127;
          p->unk_7c8 = 0;
        }
        break;
      }
      case 2: {
        rgb555* from;

        p->unk_7ca = 0x231;
        from = &gObjPlttData[p->unk_7ca * 16];
        BlendPltt(p->pltt_5c8[0], from, &gObjPlttData[FUN_081fa620(p) * 16], p->unk_7c9, 7);
        p->sprites[0].pltt = p->pltt_5c8[0];
        FUN_08203c64(p->entity082047f0, p->pltt_5c8[0]);
        if (++p->unk_7c9 > 126) {
          p->unk_7c9 = 127;
          p->unk_7c8 = 0;
        }
        break;
      }
      case 3: {
        BlendPlttToColor(p->pltt_5c8[8], &gObjPlttData[0x239 * 16], 0, 128 - p->unk_7c9, 7);
        p->sprites[1].pltt = p->pltt_5c8[0];
        if (++p->unk_7c9 > 126) {
          p->unk_7c9 = 127;
        }
        break;
      }
    }
  }
  FUN_081ff948(p);
  p->damage = 0;
  p->unk_7dc = 0;
  p->unk_7de = FALSE;
  boss->frameCount++;
  boss->weaponExpMask = 0;
  boss->hurtAttributes = 0;
#else
  INCFUNC("asm/func/FUN_081ffdb0.inc");
#endif
}

s32 Dvalinn_Update(Dvalinn* p) {
  if (!TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    FUN_08022e20(&p->base);
    FUN_081ffd9c(p);
    FUN_081fc86c(p);
    FUN_081ff740(p);
    FUN_081ff734(p);
    FUN_08022ec0(&p->base);
    FUN_081ffdb0(p);
  }
  return 0;
}

s32 Dvalinn_Destroy(Dvalinn* p) {
  Hitbox_Unregister(&p->hurtbox);
  MainSprite_Remove(&p->sprites[0]);
  Boss_Destroy(&p->base);
  MainSprite_Remove(&p->sprites[1]);
  MainSprite_Remove(&p->sprite_31c);
  AuxSprite_Remove(&p->auxSprite);
  return 0;
}

// スタックが 4 バイト多く, コールバック代入の値と番地の順や auxSprite のポインタの持ち方がずれる (826/821)
NON_MATCH s32 Dvalinn_Init(Dvalinn* p, u32 id) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  BossID bossID = VM_GetNamedArgValue('t', BOSS_DVALINN);
  MainSpriteGfxFile* f;
  Vec3 pos;
  u32 angle;
  s32 hp;
  s32 power;
  s32 entityArg1;
  s32 entityArg2;
  u32 plttIdx;

  Boss_Register(boss, bossID);
  if (gPlayerPtr[0] != NULL) {
    boss->players[0] = gPlayerPtr[0];
    boss->playerPos[0] = &gPlayerPtr[0]->mover.pos;
  } else {
    boss->players[0] = NULL;
    boss->playerPos[0] = NULL;
  }
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_DVALINN);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx, f);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    angle = VM_GetValue();
    pos.y = (GetTileAt(&pos)->heightStairs & 0xF) << 8;
  } else {
    VEC3_SET(pos, gStat->playerX, gStat->playerY, gStat->playerZ);
    angle = 0x40;
  }
  if (VM_SeekToNamedArg('s')) {
    hp = VM_GetValue();
    power = VM_GetValue();
    entityArg1 = VM_GetValue();
  } else {
    hp = 2000;
    power = 100;
    entityArg1 = 100;
  }
  if (VM_SeekToNamedArg('a')) {
    p->hitboxPower = VM_GetValue();
    p->hitboxKnockback = VM_GetValue();
    p->hitboxUnk44 = VM_GetValue();
    entityArg2 = VM_GetValue();
    p->unk_7e8 = VM_GetValue();
    p->unk_7ea = VM_GetValue();
    p->unk_7ec = VM_GetValue();
    p->unk_7ee = VM_GetValue();
    p->unk_7f0 = VM_GetValue();
  } else {
    p->hitboxPower = 100;
    p->hitboxKnockback = 100;
    p->hitboxUnk44 = 100;
    entityArg2 = 100;
    p->unk_7e8 = 100;
    p->unk_7ea = 100;
    p->unk_7ec = 100;
    p->unk_7ee = 100;
    p->unk_7f0 = 100;
  }
  if (VM_SeekToNamedArg('w')) {
    p->unk_7f2 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->unk_7f4 = p->unk_7f2 - (VM_GetPC() != NULL ? VM_GetValue() : 0);
    p->unk_7f6 = VM_GetPC() != NULL ? VM_GetValue() : 0;
    p->unk_7f8 = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    p->unk_7f2 = 70;
    p->unk_7f4 = 50;
    p->unk_7f6 = 300;
    p->unk_7f8 = 300;
  }
  Boss_Init(boss, id, bossID, &pos, angle);
  boss->destAngle = angle;
  boss->isDemo = VM_GetNamedArgValue('i', 0);
  boss->damageCallback = (BossCheckFunc)FUN_081ff988;
  boss->stateRequestCallback = (BossCheckFunc)FUN_081ff740;
  Boss_InitHP(boss, hp, hp, power);
  Dvalinn_InitHurtbox(p, power);
  Dvalinn_InitHitbox(p);
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
  if (VM_SeekToNamedArg('j')) {
    p->unk_7fa = VM_GetValue();
    p->unk_7fe = VM_GetValue();
  } else {
    p->unk_7fa = 30;
    p->unk_7fe = 5;
  }
  p->unk_7fc = p->unk_7fa;
  MainSprite_Add(&p->sprites[0], &p->gfx, 0, 0, 2, PLAYMODE_PAUSE, 60, &pos);
  Boss_PlayAnim(boss, &p->sprites[0], &p->gfx, 1, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
  MainSprite_Hide(&p->sprites[0]);
  SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
  Video_GetAuxSprite(&p->auxGfx, SPRITE_DVALIN_2E7B);
  AuxSprite_Add(&p->auxSprite, &p->auxGfx, 0);
  p->auxSprite.poseIdx = 2;
  p->auxSprite.flags |= SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN;
  p->auxSprite.priority = 0;
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_DJANGO_SABATA);
  if (f == NULL) {
    return -1;
  }
  p->gfx_2fc = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx_2fc, f);
  MainSprite_Add(&p->sprite_31c, &p->gfx_2fc, 0, 0, 2, PLAYMODE_PAUSE, 60, &pos);
  p->sprite_31c.flags |= SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN;
  MainSprite_Add(&p->sprites[1], &p->gfx, 0, 0, 2, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_SetAnim(&p->sprites[1], &p->gfx, 15, PLAYMODE_PAUSE, MAIN_ANIM_REVERSE);
  MainSprite_Hide(&p->sprites[1]);
  if (!boss->isDemo) {
    Boss_SetSubStates(boss, 1, 0, 0);
    Boss_SetState(boss, FUN_081febb8, 11);
  } else {
    switch (VM_GetNamedArgValue('D', 0)) {
      case 0: {
        Boss_SetSubStates(boss, 1, 0, 0);
        Boss_SetState(boss, FUN_081febb8, 11);
        break;
      }
      case 1: {
        Boss_SetSubStates(boss, 1, 0, 0);
        Boss_SetState(boss, FUN_081febb8, 11);
        break;
      }
    }
  }
  {
    rgb555* src = &gObjPlttData[0x132 * 16];
    s32 i;

    for (i = 0; i < 16; i++) {
      CpuCopy32(src, p->pltt[i], sizeof(p->pltt[i]));
    }
  }
  {
    rgb555* src = &gObjPlttData[FUN_081fa620(p) * 16];
    s32 i;

    for (i = 0; i < 16; i++) {
      CpuCopy32(src, p->pltt_5c8[i], sizeof(p->pltt_5c8[i]));
      src += 16;
    }
  }
  plttIdx = FUN_081fa620(p);
  p->sprites[0].pltt = plttIdx == 0 ? p->pltt[0] : &gObjPlttData[plttIdx * 16];
  SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
  p->unk_7c8 = 0;
  p->unk_7c9 = 0;
  p->unk_7ca = 0x231;
  p->unk_158 = 0;
  p->unk_7d8 = 0;
  p->unk_7da = 0;
  p->unk_804 = 0;
  p->unk_802 = 0;
  p->unk_800 = 0;
  p->unk_7dc = 0;
  p->unk_7de = FALSE;
  p->unk_806 = 0;
  p->unk_807 = 0;
  CpuFill32(0, &p->unk_808, sizeof(p->unk_808));
  {
    s32 i;

    for (i = 0; i < 8; i++) {
      p->unk_810[i] = 0;
      p->unk_818[i] = 0;
    }
    for (i = 0; i < 3; i++) {
      CpuFill32(0, &p->unk_820[i], sizeof(p->unk_820[i]));
    }
  }
  pos.x = 800;
  pos.y = 200;
  pos.z = 1000;
  pos.val = 0;
  p->entity08202cd8[0] = Entity08202cd8_Create(&pos, entityArg1, entityArg2);
  pos.x = 1300;
  pos.y = 200;
  pos.z = 2500;
  pos.val = 0;
  p->entity08202cd8[1] = Entity08202cd8_Create(&pos, entityArg1, entityArg2);
  p->entity082047f0 = Entity082047f0_Create(&boss->mover);
  Entity081ea120_Create(0, 0);
  return 0;
#else
  INCFUNC("asm/func/Dvalinn_Init.inc");
#endif
}

Dvalinn* Dvalinn_Create(u32 id) {
  Dvalinn* p = Boss_Get(BOSS_DVALINN);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Dvalinn));
  if (p != NULL) {
    SetEntityRoutine(p, Dvalinn_Update, Dvalinn_Destroy);
    if (Dvalinn_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  gDvalinn = p;
  return p;
}

// state 3 の処理へ切り替える
void Cmd_15A9(void) {
  Dvalinn* p = gDvalinn;
  Boss_RequestState(&p->base, 3);
  Boss_SetSubStates(&p->base, 0, 0, 0);
  Boss_SetState(&p->base, FUN_081fcf54, 3);
}
