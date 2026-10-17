#include "coffin.h"

#include "collision_map.h"
#include "definition.h"
#include "entity.h"
#include "global.h"
#include "inventory.h"
#include "item.h"
#include "particle.h"

void nop_0822a4f8(void* _, s32 unused1, s32 unused2);
s32 FUN_080da9c4(s32 param_1, Mover* mover, u32 param_3, u32 param_4, u16* param_5, s32 param_6, s32 param_7, s32 param_8);

extern u32 u32_03002bc0;

static inline u32 GetFlag03002bc0(u32 bits) { return u32_03002bc0 & bits; }

void Coffin_InitParticles(Coffin* p) {
  Particle* ptcl = p->ptcls;
  s32 i;

  for (i = 0; i < 7; i++, ptcl++) {
    Particle_Add(ptcl, GetParticleGroup(PTCL_GROUP_1), 0);
    Particle_SetOffset(ptcl, -4, -4);
    ptcl->offsetZ = 0xFF;
    Particle_Hide(ptcl);
  }
}

NAKED void FUN_08085408(Coffin* p) { INCFUNC("asm/func/FUN_08085408.inc"); }

static void Coffin_RemoveParticles(Coffin* p) {
  Particle* ptcl = p->ptcls;
  s32 i;

  for (i = 0; i < 7; i++, ptcl++) {
    Particle_Remove(ptcl);
  }
}

// エフェクト用の AuxSprite を1回だけ用意する
void Coffin_CreateEffSprite(Coffin* p) {
  if (p->effSpriteAdded == FALSE) {
    Video_GetAuxSprite(&p->effGfx, SPRITE_EFF_1C1B);
    AuxSprite_Add(&p->effSprite, &p->effGfx, SPRFLAG_BLINK_ODD);
    nop_0822a4f8(&p->effSprite, -8, -8);
    AuxSprite_SetPoseIdx(&p->effSprite, 6);
    p->effSpriteAdded = TRUE;
  }
}

void Coffin_RemoveEffSprite(Coffin* p) {
  if (p->effSpriteAdded == TRUE) {
    AuxSprite_Remove(&p->effSprite);
    p->effSpriteAdded = FALSE;
  }
}

NAKED void FUN_080856f4(Coffin* p) { INCFUNC("asm/func/FUN_080856f4.inc"); }

NAKED void FUN_08085764(Coffin* p) { INCFUNC("asm/func/FUN_08085764.inc"); }

NAKED void FUN_08085880(void) { INCFUNC("asm/func/FUN_08085880.inc"); }

NAKED void FUN_0808596c(s32 param_1) { INCFUNC("asm/func/FUN_0808596c.inc"); }

NAKED void FUN_08085a74(Coffin* p, s32 param_2) { INCFUNC("asm/func/FUN_08085a74.inc"); }

NAKED void FUN_08085b34(Coffin* p) { INCFUNC("asm/func/FUN_08085b34.inc"); }

NAKED void FUN_08085bd0(Coffin* p) { INCFUNC("asm/func/FUN_08085bd0.inc"); }

// 棺桶ごとのパレットを読み, 自前のバッファに複写して gfx をそちらへ向ける
void FUN_08085cb0(Coffin* p, s32 coffinID) {
  rgb555* src;
  s32 i;

  Video_SetAuxSpritePltt(&p->gfx, coffinID + 519);

  src = p->gfx.pltt;
  for (i = 0; i < 16; i++) {
    p->pltt[i] = src[i];
  }
  p->gfx.pltt = p->pltt;
}

NAKED void FUN_08085cec(Coffin* p) { INCFUNC("asm/func/FUN_08085cec.inc"); }

NAKED void FUN_08085da8(Coffin* p) { INCFUNC("asm/func/FUN_08085da8.inc"); }

void FUN_08085ec4(Coffin* p) {
  FUN_08085cec(p);
  FUN_08085da8(p);
  FUN_08085408(p);
}

void Coffin_SetState(Coffin* p, s32 state) {
  p->state = state;
  p->stateTimer = 0;
}

NAKED s32 FUN_08085ef8(Coffin* p, s32 param_2) { INCFUNC("asm/func/FUN_08085ef8.inc"); }

s32 FUN_08086024(Coffin* p, s32 param_2) { return FUN_08085ef8(p, param_2 + p->coffinID); }

void FUN_08086034(Coffin* p) {
  if (p->unk_324 != 0) {
    p->unk_324 = 0;
    p->unk_326 = 0;
    p->unk_414 = FUN_080da9c4(p->unk_414, &p->mover, 0x7F, 0, NULL, 0, 250, 290);
  }
}

void FUN_08086080(Coffin* p) { FUN_08086034(p); }

// 今いる場所がナビメッシュ上なら NavAgent を初期化して destPos への経路を引く
bool32 FUN_0808608c(Coffin* p) {
  if (Map_FindNavRectAt(&p->mover.pos) == 0xFF) {
    return FALSE;
  }

  Map_InitNavAgent(&p->navAgent, &p->mover.pos);
  if (FUN_08235a84(&p->navAgent, &p->mover.pos, &p->destPos) != 0) {
    return TRUE;
  }
  return FALSE;
}

NAKED void FUN_080860cc(Coffin* p) { INCFUNC("asm/func/FUN_080860cc.inc"); }

NAKED void FUN_0808613c(Coffin* p) { INCFUNC("asm/func/FUN_0808613c.inc"); }

void Coffin_ClearGlobal(void) { gCoffin = NULL; }

// 0xD24B, 不使用?, 装備している棺桶をアイテムとして持ち物に戻し, 装備を外す
// 残差は17/19命令でこちらが短い, 原典は -1 を movs/rsbs で作って別レジスタから写すが agbcc はプール定数1本で済ませる
// Tier A-B 試済 (定数の書き方, 代入順)
NON_MATCH void coffin_0808623c(void) {
#ifdef NONMATCHING_C
  TryAddItem(gStat->coffin + ITEM_OAK_COFFIN, 0);
  gStat->coffin = -1;
#else
  INCFUNC("asm/func/coffin_0808623c.inc");
#endif
}

// プレイヤーと棺桶が同じエレベータに乗っているか, どちらも乗っていなければ TRUE
bool32 FUN_0808626c(u32 playerElevatorID, u32 playerFlags, u32 coffinElevatorID, u32 coffinFlags) {
  if (playerFlags & 4) {
    if ((coffinFlags & 4) == 0) {
      return FALSE;
    }
    if (playerElevatorID != coffinElevatorID) {
      return FALSE;
    }
  } else if (coffinFlags & 4) {
    return FALSE;
  }
  return TRUE;
}

NAKED s32 FUN_08086294(Vec3* pos, u32 elevatorID, u32 b) { INCFUNC("asm/func/FUN_08086294.inc"); }

void FUN_08086590(Vec3* pos, s32 val) {
  if (gCoffin != NULL) {
    gCoffin->unk_388 = *pos;
    gCoffin->unk_388.val = val;
  }
}

WorldPos* Coffin_GetPos(void) {
  if (gCoffin == NULL) {
    return NULL;
  }
  return &gCoffin->mover.pos;
}

bool32 FUN_080865dc(Vec3* out) {
  if (gCoffin == NULL) {
    out->x = 0, out->y = 0, out->z = 0;
    return FALSE;
  }

  *out = gCoffin->unk_40c;
  return TRUE;
}

bool32 Coffin_IsState(s32 state) {
  if (gCoffin == NULL || gCoffin->state != state) {
    return FALSE;
  }
  return TRUE;
}

NAKED void FUN_08086638(void) { INCFUNC("asm/func/FUN_08086638.inc"); }

void FUN_080866e4(void) {
  if (gCoffin != NULL) {
    Coffin_SetState(gCoffin, 0);
    gCoffin->unk_3b4 = 1;
  }
}

void FUN_0808670c(s32 n) {
  if (gCoffin != NULL) {
    gCoffin->unk_40a = n;
  }
}

NAKED bool32 FUN_0808672c(void) { INCFUNC("asm/func/FUN_0808672c.inc"); }

NAKED void FUN_080867a0(void) { INCFUNC("asm/func/FUN_080867a0.inc"); }

bool32 Coffin_IsIdle(void) {
  if (gCoffin == NULL || gCoffin->state != 1) {
    return FALSE;
  }
  return TRUE;
}

s32 FUN_08086878(void) {
  if (gCoffin == NULL) {
    return -1;
  }
  return gCoffin->unk_3a0;
}

void FUN_0808689c(s32 val) {
  if (gCoffin != NULL) {
    gCoffin->unk_3a0 = val;
  }
}

void FUN_080868b8(s32 param_1) {
  Coffin* p = gCoffin;

  if (p != NULL) {
    if (param_1 != 0) {
      Coffin_SetState(p, 7);
    } else {
      Coffin_SetState(p, 6);
    }
    if (p->unk_1f4 != FALSE) {
      EnemyTargetManager_Remove(&p->target);
      p->unk_1f4 = FALSE;
    }
    p->unk_320 = 0;
    FUN_08086080(p);
  }
}

// 棺を state 8 に入れ, エフェクトスプライトを棺と同じ位置に出す
void FUN_08086910(void) {
  Coffin* p = gCoffin;

  if (p != NULL) {
    Coffin_SetState(p, 8);
    Coffin_CreateEffSprite(p);
    p->effSprite.pos = p->sprite.pos;
    p->unk_320 = 1500;
    FUN_08086080(p);
  }
}

s32 FUN_08086958(void) {
  if (gCoffin == NULL) {
    return 0;
  }
  return gCoffin->unk_384;
}

bool32 FUN_08086978(u32 mask) {
  if (gCoffin == NULL || (gCoffin->unk_384 & mask) == 0) {
    return FALSE;
  }
  return TRUE;
}

s32 Coffin_GetElevatorID(void) {
  if (gCoffin == NULL) {
    return 0;
  }
  return gCoffin->elevatorID;
}

void FUN_080869c8(u32 flags, u32 value) {
  if (gCoffin != NULL) {
    gCoffin->unk_384 |= flags;
    gCoffin->elevatorID = value;
  }
}

void FUN_080869f8(u32 flags) {
  if (gCoffin != NULL) {
    gCoffin->unk_384 &= ~flags;
    gCoffin->elevatorID = 0;
  }
}

bool32 Coffin_CopyPos(WorldPos* out) {
  if (gCoffin == NULL) {
    return FALSE;
  }

  *out = gCoffin->mover.pos;
  return TRUE;
}

NAKED void FUN_08086a4c(Vec3* pos) { INCFUNC("asm/func/FUN_08086a4c.inc"); }

bool32 FUN_08086ab8(void) {
  if (gCoffin == NULL) {
    return FALSE;
  }
  if (gCoffin->coffinID != COFFIN_SOLAR) {
    return FALSE;
  }
  if (gCoffin->state > 4) {
    return FALSE;
  }

  Coffin_SetState(gCoffin, 9);
  return TRUE;
}

bool32 FUN_08086af0(void) {
  if (gCoffin == NULL) {
    return FALSE;
  }
  if (gCoffin->coffinID != COFFIN_SOLAR) {
    return FALSE;
  }

  Coffin_SetState(gCoffin, 10);
  return TRUE;
}

NAKED void FUN_08086b18(WorldPos* pos) { INCFUNC("asm/func/FUN_08086b18.inc"); }

NAKED void FUN_08086be0(void) { INCFUNC("asm/func/FUN_08086be0.inc"); }

NAKED void FUN_08086c50(void) { INCFUNC("asm/func/FUN_08086c50.inc"); }

void Coffin_RequestKill(void) {
  if (gCoffin != NULL) {
    gCoffin->killRequested = TRUE;
  }
}

// 装備中の棺桶ID, 未装備なら貴重品欄にある棺桶から探す
s32 FUN_08086d7c(void) {
  s32 i;

  if (gStat->coffin >= 0) {
    return gStat->coffin;
  }

  for (i = 0; i < 16; i++) {
    s32 id = GetValuableItemID(i) - ITEM_OAK_COFFIN;

    if ((u32)id < COFFIN_NUM) {
      return id;
    }
  }
  return COFFIN_OAK;
}

// 選択中の棺種別を返す, 未選択なら貴重品の中の棺アイテムを1つ消費してその種別を返す
s32 Coffin_TakeKind(void) {
  s32 i;

  if (gStat->coffin >= 0) {
    return gStat->coffin;
  }

  for (i = 0; i < 16; i++) {
    s32 id = GetValuableItemID(i) - ITEM_OAK_COFFIN;

    if ((u32)id < COFFIN_NUM) {
      RemoveValuable(i);
      return id;
    }
  }
  return COFFIN_OAK;
}

// Coffin.weight, 棺桶の重さ, 運搬時のプレイヤーの移動速度に影響する
static const u16 sCoffinWeights[8] = {
    [COFFIN_OAK] = 50,
    [COFFIN_BRONZE] = 70,
    [COFFIN_IRON] = 90,
    [COFFIN_SILVER] = 60,
    [COFFIN_SOLAR] = 80,
    [COFFIN_ELEFAN] = 90,
    [COFFIN_VAMPIRE] = 60,
    [COFFIN_IRON_MAIDEN] = 90,
};  // 0x085BBFE8

NAKED void Coffin_Init_Helper_08086df8(Coffin* p, u32 id) { INCFUNC("asm/func/Coffin_Init_Helper_08086df8.inc"); }

// 棺桶の封印力, 高いほど棺桶が逃げにくくなる
static const u8 sCoffinPowers[8] = {
    [COFFIN_OAK] = 10,
    [COFFIN_BRONZE] = 15,
    [COFFIN_IRON] = 20,
    [COFFIN_SILVER] = 25,
    [COFFIN_SOLAR] = 15,
    [COFFIN_ELEFAN] = 10,
    [COFFIN_VAMPIRE] = 10,
    [COFFIN_IRON_MAIDEN] = 30,
};  // 0x085ABFF8

NAKED void Coffin_Init_Helper_08086e64(Coffin* p) { INCFUNC("asm/func/Coffin_Init_Helper_08086e64.inc"); }

NAKED void FUN_08086f90(Coffin* p) { INCFUNC("asm/func/FUN_08086f90.inc"); }

NAKED void FUN_08087058(Coffin* p) { INCFUNC("asm/func/FUN_08087058.inc"); }

NAKED void FUN_080871e4(Coffin* p) { INCFUNC("asm/func/FUN_080871e4.inc"); }

NAKED void FUN_08087290(Coffin* p) { INCFUNC("asm/func/FUN_08087290.inc"); }

NAKED void FUN_08087310(Coffin* p) { INCFUNC("asm/func/FUN_08087310.inc"); }

NAKED void FUN_080873b4(Coffin* p, s32 param_2) { INCFUNC("asm/func/FUN_080873b4.inc"); }

void FUN_08087440(Coffin* p) {
  if (p->unk_326 != 0) {
    p->unk_326--;
    if (p->unk_326 == 1) {
      p->unk_324 = 0;
      p->unk_326 = 0;
      p->unk_414 = FUN_080da9c4(p->unk_414, &p->mover, 0x7F, 0, NULL, 0, 250, 290);
    }
  }
}

void FUN_08087494(Coffin* p) {
  if (p->unk_3b6 != 0) {
    if (p->state == 1) {
      if (p->unk_3b6 > 2) {
        p->unk_3b6 -= 2;
      } else {
        p->unk_3b6 = 0;
      }
    } else {
      p->unk_3b6--;
    }
  }
}

NAKED void FUN_080874cc(Coffin* p) { INCFUNC("asm/func/FUN_080874cc.inc"); }

NAKED void FUN_08087528(Coffin* p) { INCFUNC("asm/func/FUN_08087528.inc"); }

NAKED void FUN_080875e8(Coffin* p) { INCFUNC("asm/func/FUN_080875e8.inc"); }

NAKED void FUN_0808766c(Coffin* p) { INCFUNC("asm/func/FUN_0808766c.inc"); }

NAKED s32 FUN_08087818(Coffin* p) { INCFUNC("asm/func/FUN_08087818.inc"); }

NAKED s32 FUN_08087970(Coffin* p) { INCFUNC("asm/func/FUN_08087970.inc"); }

NAKED void FUN_08087a5c(Coffin* p) { INCFUNC("asm/func/FUN_08087a5c.inc"); }

void FUN_08087bac(Coffin* p) {
  if (gFlag030047a4 & FLAG030047A4_UNK_9) {
    return;
  }
  if (p->canSelfMove == 0) {
    return;
  }
  if (p->unk_3b4 != 0) {
    return;
  }
  if (p->unk_384 != 0) {
    return;
  }

  if (p->selfMoveTimer != 0) {
    p->selfMoveTimer--;
  } else {
    FUN_080860cc(p);
  }
}

NAKED void FUN_08087c04(Coffin* p) { INCFUNC("asm/func/FUN_08087c04.inc"); }

NAKED void FUN_08087cbc(s32 param_1) { INCFUNC("asm/func/FUN_08087cbc.inc"); }

NAKED void FUN_08087f7c(s32 param_1) { INCFUNC("asm/func/FUN_08087f7c.inc"); }

void FUN_080880fc(Coffin* p) {
  if (p->unk_384 == 0) {
    if (p->unk_390 != 0) {
      p->unk_390--;
    } else {
      p->unk_390 = p->unk_392;
      p->unk_394 = 1;
      p->unk_396 = 0;
    }
  }
}

NAKED void FUN_08088148(Coffin* p) { INCFUNC("asm/func/FUN_08088148.inc"); }

NAKED s32 FUN_080882e4(s32 param_1, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080882e4.inc"); }

NAKED s32 FUN_08088430(Coffin* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08088430.inc"); }

bool32 FUN_080884f4(s32 dx, s32 dz) {
  if (abs(dx) > 0x20) {
    return FALSE;
  }
  if (abs(dz) > 0x20) {
    return FALSE;
  }
  return TRUE;
}

NAKED void FUN_08088514(Coffin* p) { INCFUNC("asm/func/FUN_08088514.inc"); }

NAKED void FUN_08088718(Coffin* p) { INCFUNC("asm/func/FUN_08088718.inc"); }

NAKED void FUN_0808890c(Coffin* p) { INCFUNC("asm/func/FUN_0808890c.inc"); }

NAKED void FUN_08088bbc(Coffin* p) { INCFUNC("asm/func/FUN_08088bbc.inc"); }

NAKED void FUN_08088c54(Coffin* p) { INCFUNC("asm/func/FUN_08088c54.inc"); }

NAKED void FUN_08088d44(Coffin* p) { INCFUNC("asm/func/FUN_08088d44.inc"); }

NAKED void FUN_08088fbc(Coffin* p) { INCFUNC("asm/func/FUN_08088fbc.inc"); }

NAKED void FUN_08089088(Coffin* p) { INCFUNC("asm/func/FUN_08089088.inc"); }

NAKED void FUN_08089144(Coffin* p) { INCFUNC("asm/func/FUN_08089144.inc"); }

void FUN_080892a8(Coffin* p) {
  if (p->state != 11) {
    Coffin_SetState(p, 11);
  }
  p->unk_32a = 0;
  p->unk_394 = 0;
  p->hitbox.flags |= HBFLAG_UNK_2;
  p->unk_200 = 0;
  FUN_08086024(p, 0);
}

void FUN_080892f8(Coffin* p) {
  if (p->state != 13) {
    Coffin_SetState(p, 13);
  }
  p->hitbox.flags |= HBFLAG_UNK_2;
  p->unk_200 = 0;
  if (FUN_08086024(p, 8) != 0) {
    Coffin_SetState(p, 12);
  }
}

NAKED void FUN_08089344(Coffin* p) { INCFUNC("asm/func/FUN_08089344.inc"); }

void FUN_080893c0(Coffin* p) {
  if (p->state != 14) {
    Coffin_SetState(p, 14);
  }
  p->hitbox.flags |= HBFLAG_UNK_2;
  p->unk_200 = 0;
  if (FUN_08086024(p, 16) != 0) {
    Coffin_SetState(p, p->unk_408);
  }
}

NAKED void FUN_08089410(Coffin* p) { INCFUNC("asm/func/FUN_08089410.inc"); }

NAKED void FUN_08089548(Coffin* p) { INCFUNC("asm/func/FUN_08089548.inc"); }

NAKED void FUN_080895d0(Coffin* p) { INCFUNC("asm/func/FUN_080895d0.inc"); }

NAKED void FUN_08089720(Coffin* p) { INCFUNC("asm/func/FUN_08089720.inc"); }

static void (*const sCoffinUpdates[17])(Coffin*) = {
    FUN_08087c04,
    FUN_08088148,
    FUN_0808890c,
    FUN_08088514,
    FUN_08088718,
    FUN_08088d44,
    FUN_08088fbc,
    FUN_08089088,
    FUN_08089144,
    FUN_08088bbc,
    FUN_08088c54,
    FUN_080892a8,
    FUN_08089344,
    FUN_080892f8,
    FUN_080893c0,
    FUN_08089548,
    FUN_08089720,
};  // 0x085AC000

s32 Coffin_Update(Coffin* p) {
  s32 idx;

  p->unk_406 = 0;

  if (GetFlag03002bc0(4)) {
    FUN_08085408(p);
    return 0;
  }

  if (p->killRequested != FALSE) {
    KillEntity((Entity*)p);
    return 0;
  }

  p->unk_31e = 0;
  p->unk_322 = 0;
  p->unk_33a = 0;

  idx = FUN_08087970(p);
  sCoffinUpdates[idx](p);
  FUN_0808766c(p);
  FUN_080874cc(p);
  FUN_08085ec4(p);

  p->zoneEvent.pos = &p->mover.pos;
  FUN_08234660(&p->zoneEvent);

  if (p->killRequested != FALSE) {
    KillEntity((Entity*)p);
  }
  return 0;
}

s32 Coffin_Destroy(Coffin* p) {
  if (p->unk_1f4 != FALSE) {
    EnemyTargetManager_Remove(&p->target);
  }

  Mover_Unlink(&p->mover);
  AuxSprite_Remove(&p->sprite);
  Hitbox_Unregister(&p->hitbox);
  Coffin_RemoveParticles(p);
  Coffin_RemoveEffSprite(p);
  gCoffin = NULL;
  return 0;
}

s32 Coffin_Init(Coffin* p, u32 id, u32 _) {
  Coffin_Init_Helper_08086df8(p, id);
  FUN_08086f90(p);
  FUN_08087058(p);
  Coffin_Init_Helper_08086e64(p);
  FUN_080871e4(p);
  FUN_08087290(p);
  Coffin_InitParticles(p);
  FUN_08087310(p);

  p->unk_32a = 0;
  p->unk_32c = 0;
  p->unk_332 = 0;
  p->unk_3a0 = -1;
  p->killRequested = FALSE;
  p->unk_40a = 0;
  gCoffin = p;
  return 0;
}

// 0x0B50, HashName("棺桶")
Coffin* Coffin_Create(u32 id, u32 _) {
  if (gCoffin == NULL) {
    Coffin* p = CreateEntity(ENTITY_UNK_9, sizeof(Coffin));

    if (p != NULL) {
      SetEntityRoutine(p, Coffin_Update, Coffin_Destroy);
      if (Coffin_Init(p, id, _) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gCoffin;
}
