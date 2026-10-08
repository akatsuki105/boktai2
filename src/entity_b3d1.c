#include "entity.h"
#include "global.h"
#include "player.h"
#include "sprite.h"
#include "vm.h"

struct EntityB3D1;
typedef void(EntityB3D1Func)(struct EntityB3D1*);

// 暗黒ローン関係
typedef struct EntityB3D1 {
  Entity e;                        // 0x000, ENTITY_UNK_8
  u8 unk_18[0x020 - 0x018];        // 0x018, まだ未解析
  AuxSprite sprite0;               // 0x020, _Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx0;               // 0x04C, SPRITE_TREADMILL
  u8 unk_68[0x06C - 0x068];        // 0x068, まだ未解析
  AuxSprite sprite1;               // 0x06C, _Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx1;               // 0x098, SPRITE_TREADMILL
  u16 unk_b4;                      // 0x0B4
  u16 unk_b6;                      // 0x0B6, _Init が '.N' から 1/2/3/4 を入れる
  AuxSprite sprite2;               // 0x0B8
  AuxSpriteGfx gfx2;               // 0x0E4, SPRITE_TREADMILL
  AuxSprite sprites3[7];           // 0x100, _Destroy が stride 0x2C で7枚 AuxSprite_Remove する
  u8 unk_234[0x250 - 0x234];       // 0x234, まだ未解析
  AuxSprite sprites4[6];           // 0x250, _Destroy が stride 0x2C で6枚 AuxSprite_Remove する
  u8 unk_358[0x398 - 0x358];       // 0x358, まだ未解析
  MainSprite mainSprites[5];       // 0x398, _Destroy が stride 0x60 で5枚 MainSprite_Remove する
  u16 unk_578;                     // 0x578, '.p'
  u16 unk_57a;                     // 0x57A
  u16 unk_57c;                     // 0x57C, まだ未解析
  u16 unk_57e;                     // 0x57E, _Init が 0 を入れる
  u8 unk_580[0x588 - 0x580];       // 0x580, まだ未解析
  u16 unk_588;                     // 0x588, _Init が 0 を入れる
  u16 unk_58a;                     // 0x58A, '.t[0]=180'
  u16 unk_58c;                     // 0x58C, '.t[1]=300'
  u16 unk_58e;                     // 0x58E
  u16 unk_590;                     // 0x590
  u8 unk_592[2];                   // 0x592, まだ未解析
  u32 unk_594;                     // 0x594
  u32 unk_598;                     // 0x598
  u32 unk_59c;                     // 0x59C
  u32 unk_5a0;                     // 0x5A0
  u32 unk_5a4;                     // 0x5A4
  u32 unk_5a8;                     // 0x5A8
  u32 unk_5ac;                     // 0x5AC
  u8 unk_5b0[2];                   // 0x5B0, まだ未解析
  u16 unk_5b2;                     // 0x5B2, '.r=300'
  u8 unk_5b4[0x5B6 - 0x5B4];       // 0x5B4, まだ未解析
  u16 stateTimer;                  // 0x5B6
  EntityB3D1Func* updateCallback;  // 0x5B8
} EntityB3D1;
static_assert(sizeof(EntityB3D1) == 1468);

extern EntityB3D1* gEntityB3D1;  // 0x03000158

void FUN_080bfa50(void) { gEntityB3D1 = NULL; }

void EntityB3D1_SetState(EntityB3D1* p, EntityB3D1Func* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

// プレイヤー1の unk_40c と unk_42e を空にする
void FUN_080bfa74(void) {
  s32 i;

  for (i = 0; i < 32; i++) {
    gPlayerPtr[0]->unk_40c[i] = 0;
  }

  gPlayerPtr[0]->unk_42e = 0;
}

NAKED void FUN_080bfaac(EntityB3D1* p) { INCFUNC("asm/func/FUN_080bfaac.inc"); }

// unk_b4 を unk_b6 ずつ進めて, 8 で割った値を sprite1 のコマ番号にする
void FUN_080bfb74(EntityB3D1* p) {
  AuxSprite_SetMetaspriteIdx(&p->sprite1, p->unk_b4 >> 3);
  p->unk_b4 += p->unk_b6;

  if (p->unk_b4 > 23) {
    p->unk_b4 = 0;
  }
}

NAKED void FUN_080bfba4(EntityB3D1* p) { INCFUNC("asm/func/FUN_080bfba4.inc"); }

NAKED void FUN_080bfc60(EntityB3D1* p) { INCFUNC("asm/func/FUN_080bfc60.inc"); }

NAKED void FUN_080bfce4(EntityB3D1* p) { INCFUNC("asm/func/FUN_080bfce4.inc"); }

void FUN_080bfd04(EntityB3D1* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    p->mainSprites[i].flags |= SPRFLAG_HIDDEN;
  }
}

NAKED void FUN_080bfd24(EntityB3D1* p) { INCFUNC("asm/func/FUN_080bfd24.inc"); }

NAKED s32 FUN_080bfd5c(EntityB3D1* p) { INCFUNC("asm/func/FUN_080bfd5c.inc"); }

NAKED void FUN_080bfdac(EntityB3D1* p) { INCFUNC("asm/func/FUN_080bfdac.inc"); }

NAKED void FUN_080bfe50(EntityB3D1* p) { INCFUNC("asm/func/FUN_080bfe50.inc"); }

void FUN_080bfef8(EntityB3D1* p) {
  s32 i;

  for (i = 0; i < 6; i++) {
    p->sprites4[i].flags |= SPRFLAG_HIDDEN;
  }
}

NAKED void FUN_080bff18(EntityB3D1* p) { INCFUNC("asm/func/FUN_080bff18.inc"); }

void FUN_080bff78(EntityB3D1* p) {
  s32 i;

  for (i = 0; i < 7; i++) {
    p->sprites3[i].flags &= ~SPRFLAG_HIDDEN;
  }
}

void FUN_080bff98(EntityB3D1* p) {
  s32 i;

  for (i = 0; i < 7; i++) {
    p->sprites3[i].flags |= SPRFLAG_HIDDEN;
  }
}

void FUN_080bffb8(EntityB3D1* p) {
  FUN_080bfce4(p);
  FUN_080bff78(p);
}

void FUN_080bffcc(EntityB3D1* p) {
  FUN_080bfd04(p);
  FUN_080bfef8(p);
  FUN_080bff98(p);
}

void FUN_080c0248(EntityB3D1* p);

void FUN_080bffe8(EntityB3D1* p) {
  FUN_080bfaac(p);
  FUN_080bffb8(p);
  p->unk_57a = 0x20;
  EntityB3D1_SetState(p, FUN_080c0248);
}

NAKED void FUN_080c0014(EntityB3D1* p) { INCFUNC("asm/func/FUN_080c0014.inc"); }

// unk_5a8 のスクリプトを引数1個で起動する
void FUN_080c0058(EntityB3D1* p) {
  u32 arg;
  ScriptArgs args;

  if (p->unk_5a8 != 0) {
    args.argc = 1, args.argv = &arg;
    VM_ExecByID(p->unk_5a8, &args);
  }
}

NAKED void FUN_080c008c(void) { INCFUNC("asm/func/FUN_080c008c.inc"); }

NAKED s32 FUN_080c00d4(EntityB3D1* p) { INCFUNC("asm/func/FUN_080c00d4.inc"); }

void FUN_080c01a8(void) {}

NAKED void FUN_080c01ac(EntityB3D1* p, s32 param_2) { INCFUNC("asm/func/FUN_080c01ac.inc"); }

NAKED void FUN_080c0248(EntityB3D1* p) { INCFUNC("asm/func/FUN_080c0248.inc"); }

NAKED void FUN_080c04d8(void) { INCFUNC("asm/func/FUN_080c04d8.inc"); }

// 残差は 15 命令 vs 16 命令 で、原典は updateCallback のアドレスを movs/lsls/adds の3命令で作る (こちらはプール定数1本で済んでしまう)
NON_MATCH s32 EntityB3D1_Update(EntityB3D1* p) {
#ifdef NONMATCHING_C
  p->updateCallback(p);
  FUN_080bfb74(p);
  FUN_080c04d8();
  return 0;
#else
  INCFUNC("asm/func/EntityB3D1_Update.inc");
#endif
}

NAKED s32 EntityB3D1_Destroy(EntityB3D1* p) { INCFUNC("asm/func/EntityB3D1_Destroy.inc"); }

NAKED void FUN_080c05cc(EntityB3D1* p) { INCFUNC("asm/func/FUN_080c05cc.inc"); }

NAKED void FUN_080c06e4(EntityB3D1* p) { INCFUNC("asm/func/FUN_080c06e4.inc"); }

NAKED void FUN_080c0770(EntityB3D1* p) { INCFUNC("asm/func/FUN_080c0770.inc"); }

NAKED s32 EntityB3D1_Init(EntityB3D1* p) { INCFUNC("asm/func/EntityB3D1_Init.inc"); }

EntityB3D1* EntityB3D1_Create(void) {
  if (gEntityB3D1 == NULL) {
    EntityB3D1* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityB3D1));

    if (p != NULL) {
      SetEntityRoutine(p, EntityB3D1_Update, EntityB3D1_Destroy);
      if (EntityB3D1_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntityB3D1;
}
