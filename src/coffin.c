#include "coffin.h"

#include "collision_map.h"
#include "definition.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "inventory.h"
#include "item.h"
#include "particle.h"
#include "random.h"
#include "sound.h"
#include "vm.h"

void nop_0822a4f8(void* _, s32 unused1, s32 unused2);
void FUN_08087528(HitboxData* a, HitboxData* b, Coffin* p);
s32 FUN_080155e4(s32 count, WorldPos* pos, unknown* params);
s32 FUN_080da9c4(s32 param_1, Mover* mover, u32 param_3, u32 param_4, u16* param_5, s32 param_6, s32 param_7, s32 param_8);
s32 FUN_080d99d4(s32 param_1, u32 param_2, u32 param_3);

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

// 残差は gRandomTable 読み出しの r0/r1 入れ替え1箇所のみ (原典は読んだ値を r0, マスク 1 を r1 に置く), 命令列は同数同順
// Tier A-C は試済 (u32 化で bls は解消, ローカル v の有無は無影響), 未: per-TU フラグ
NON_MATCH void FUN_080856f4(Coffin* p) {
#ifdef NONMATCHING_C
  u32 t = p->unk_328 & 0x7F;

  if (t > 0x5F) {
    if (t == 0x60) {
      PlaySound_082406e0(0x2AA);
    }
    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    p->unk_31e = (*(gRandTableIdx + gRandomTable) & 1) * 11 - 5;
    p->unk_322 = -p->unk_31e;
  }
  p->unk_328++;
#else
  INCFUNC("asm/func/FUN_080856f4.inc");
#endif
}

NAKED void FUN_08085764(Coffin* p) { INCFUNC("asm/func/FUN_08085764.inc"); }

NAKED void FUN_08085880(void) { INCFUNC("asm/func/FUN_08085880.inc"); }

NAKED void FUN_0808596c(s32 param_1) { INCFUNC("asm/func/FUN_0808596c.inc"); }

// 残差1命令, 原典は &gRandTableIdx を ip に置いて毎回 [ip] から読み直すが, こちらは値をレジスタに持つため
// callee-saved を1本多く push する, Tier A-C は試済, 未: per-TU フラグ
NON_MATCH void FUN_08085a74(WorldPos* pos, unknown* params) {
#ifdef NONMATCHING_C
  Vec3 v = *pos;

  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  v.x = v.x - 15 + (*(gRandTableIdx + gRandomTable) & 0x1F);
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  v.z = v.z - 15 + (*(gRandTableIdx + gRandomTable) & 0x1F);
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  v.y = v.y - 16 - (*(gRandTableIdx + gRandomTable) & 0x3F);
  FUN_080155e4(1, &v, params);
#else
  INCFUNC("asm/func/FUN_08085a74.inc");
#endif
}

// 残差2命令, pltt[1] への 0 書き込み (case 0) と 0x1F 書き込み (case 2) の strh を原典は共通末尾に畳むが,
// case 0 側が switch の途中にあるため break が b になって畳まれない, Tier A-C は試済
NON_MATCH void FUN_08085b34(Coffin* p) {
#ifdef NONMATCHING_C
  switch (p->unk_32a) {
    case 0: {
      s32 n = p->unk_32c;

      if (n != 0) {
        p->pltt[1] = (n * 31) >> 6;
        p->unk_32c--;
        break;
      }
      p->pltt[1] = 0;
      break;
    }
    case 1: {
      s32 n = p->unk_32c <= 0x3F ? p->unk_32c : 0x80 - p->unk_32c;

      p->pltt[1] = (n * 31) >> 6;
      p->unk_32c++;
      if (p->unk_32c > 0x7F) {
        p->unk_32c = 0;
      }
      break;
    }
    case 2: {
      if (p->unk_32c <= 0x3F) {
        p->pltt[1] = (p->unk_32c * 31) >> 6;
        p->unk_32c++;
      } else {
        p->pltt[1] = 0x1F;
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08085b34.inc");
#endif
}

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

void FUN_08085cec(Coffin* p) {
  if (p->unk_40a != 0 || p->unk_406 != 0) {
    if (p->unk_334 <= 0x3F) {
      p->unk_334++;
    }
  } else if (p->unk_334 != 0) {
    p->unk_334--;
  }

  if (p->unk_330 != 0) {
    if (p->unk_32e != 9) {
      p->unk_32e = 9;
      FUN_08085cb0(p, 9);
    }
    p->unk_330--;
  } else if (p->unk_334 != 0) {
    p->unk_32e = 8;
    FUN_08085bd0(p);
  } else {
    if (p->unk_32e != p->unk_31c) {
      p->unk_32e = p->unk_31c;
      FUN_08085cb0(p, p->unk_32e);
    }
    FUN_08085b34(p);
  }
}

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

// 残差は unk_384 のオフセット定数を 0x3A4 から subs で作ってしまう1命令のみ (原典は movs/lsls で作り直す), Tier A-C は試済
// inline アクセサ経由 (Coffin_ResetSelfMoveTimer) も試したが改善せず, 未: per-TU フラグ
NON_MATCH void FUN_080860cc(Coffin* p) {
#ifdef NONMATCHING_C
  p->selfMoveTimer = p->selfMoveTimerInit;

  if (p->canSelfMove == 0 || p->unk_384 != 0) {
    Coffin_SetState(gCoffin, 0);
  } else if (FUN_0808608c(p)) {
    Coffin_SetState(gCoffin, 3);
  } else {
    Coffin_SetState(gCoffin, 4);
  }
#else
  INCFUNC("asm/func/FUN_080860cc.inc");
#endif
}

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

void FUN_08086638(void) {
  Coffin* p = gCoffin;

  if (p == NULL) {
    return;
  }

  if (VM_SeekToNamedArg('p')) {
    p->destPos.x = VM_GetValue();
    p->destPos.y = VM_GetValue();
    p->destPos.z = VM_GetValue();
  }
  if (VM_SeekToNamedArg('R')) {
    p->unk_3b0 = VM_GetValue();
  }

  if (p->state != 3) {
    return;
  }

  if (Map_FindNavRectAt(&p->mover.pos) == 0xFF) {
    Coffin_SetState(p, 0);
    return;
  }

  Map_InitNavAgent(&p->navAgent, &p->mover.pos);
  if (FUN_08235a84(&p->navAgent, &p->mover.pos, &p->destPos) == 0) {
    Coffin_SetState(p, 0);
    return;
  }
  Coffin_SetState(p, 3);
}

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

bool32 FUN_0808672c(void) {
  Coffin* p = gCoffin;

  if (p == NULL) {
    return FALSE;
  }
  if (p->unk_394 != 0) {
    return FALSE;
  }
  if (p->unk_40a != 0) {
    return FALSE;
  }
  if (p->unk_384 != 0) {
    return FALSE;
  }
  if (p->unk_3b6 != 0) {
    return FALSE;
  }
  if (p->state <= 1) {
    return TRUE;
  }
  if (p->state != 3 && p->state != 4) {
    return FALSE;
  }
  if (p->unk_324 == 0) {
    return FALSE;
  }
  return TRUE;
}

// 残差は定数 0 のレジスタ割当のみ (原典は両分岐で r3 に 0 を作り, unk_418 への strh と第4引数で共有する), 命令列は同数同順
// unk_418 = 0 を両分岐に置くと3命令増えて悪化, Tier A-C は試済, 未: per-TU フラグ
NON_MATCH void FUN_080867a0(void) {
#ifdef NONMATCHING_C
  Coffin* p = gCoffin;

  if (p == NULL) {
    return;
  }

  if (p->state == 1) {
    FUN_08086080(p);
    p->unk_394 = 1;
    p->unk_3b6 = 300;
  } else {
    if (p->state != 0 && p->state != 2) {
      if (p->state != 3 && p->state != 4) {
        return;
      }
      if (p->unk_324 == 0) {
        return;
      }
    }
    FUN_08086080(p);
    FUN_080860cc(p);
    p->unk_3b6 = 600;
  }

  p->unk_418 = 0;
  p->unk_414 = FUN_080da9c4(p->unk_414, &p->mover, 1, 0, &p->unk_418, 200, 250, 330);
#else
  INCFUNC("asm/func/FUN_080867a0.inc");
#endif
}

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

void FUN_08086a4c(Vec3* pos) {
  Coffin* p = gCoffin;

  if (p != NULL) {
    p->pos_1f8 = *pos;
    p->mover.pos = *pos;
    p->sprite.pos = *pos;
    p->sprite.pos.x += p->unk_31e;
    p->sprite.pos.z += p->unk_322;
    p->unk_388 = *pos;
  }
}

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

// 残差は gRandomTable 読み出しの r0/r1 入れ替え1箇所のみ (原典は値を r0, マスク 7 を r1 に置く), 命令列は同数同順
// FUN_080856f4 と同じ残差, 添字形 gRandomTable[i] にすると base の materialize が1命令早まって悪化する
NON_MATCH void FUN_08086b18(WorldPos* pos) {
#ifdef NONMATCHING_C
  if (gCoffin != NULL) {
    s32 dx;
    s32 dz;

    gCoffin->unk_3bc = *pos;
    Coffin_SetState(gCoffin, 14);
    gCoffin->unk_408 = 15;
    dx = gPlayerPtr[0]->mover.pos.x - gCoffin->unk_3bc.x;
    dz = gPlayerPtr[0]->mover.pos.z - gCoffin->unk_3bc.z;
    if (dx != 0 || dz != 0) {
      s32 angle = ((ArcTan2_8(dx, dz) + 0x10) & 0xFF) >> 5;

      gCoffin->unk_404 = (angle + 7) & 7;
    } else {
      gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
      gCoffin->unk_404 = *(gRandTableIdx + gRandomTable) & 7;
    }
    gCoffin->unk_402 = 0x1D;
  }
#else
  INCFUNC("asm/func/FUN_08086b18.inc");
#endif
}

void FUN_08086be0(void) {
  Coffin* p = gCoffin;

  if (p != NULL) {
    u8 desc[8];

    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, p->mover.pos.x);
    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, p->mover.pos.y);
    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, p->mover.pos.z);
    FUN_0823167c(desc);
    FUN_0823206c(desc, 0, p->facing);
  }
}

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

// 残差は gStat->coffin の再読み込み1箇所 (原典は gStat ポインタとハーフワードを両方読み直す), Tier A-B は試済
// static inline アクセサ経由にすると値は読み直すがポインタは r1 に残り 39/40 まで, 未: per-TU フラグ
NON_MATCH void Coffin_Init_Helper_08086df8(Coffin* p, u32 id) {
#ifdef NONMATCHING_C
  s32 v;

  p->subroutineID = id;
  gStat->coffin = Coffin_TakeKind();
  p->coffinID = gStat->coffin;
  v = VM_SeekToNamedArg('c');
  if (v) {
    v = VM_GetValue();
  }
  p->unk_1c = v;
  p->weight = sCoffinWeights[p->coffinID];
  if (VM_SeekToNamedArg('a')) {
    Coffin_SetState(p, VM_GetValue());
  } else {
    Coffin_SetState(p, 0);
  }
#else
  INCFUNC("asm/func/Coffin_Init_Helper_08086df8.inc");
#endif
}

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

void Coffin_InitSprite(Coffin* p) {
  rgb555* src;
  s32 i;

  p->unk_31c = p->coffinID;
  Video_GetAuxSprite(&p->gfx, SPRITE_COFFIN);
  AuxSprite_Add(&p->sprite, &p->gfx, 0);
  p->unk_32e = p->unk_31c;
  Video_SetAuxSpritePltt(&p->gfx, p->unk_32e + 519);

  src = p->gfx.pltt;
  for (i = 0; i < 16; i++) {
    p->pltt[i] = src[i];
  }
  p->gfx.pltt = p->pltt;

  if (VM_SeekToNamedArg('d')) {
    p->facing = VM_GetValue();
  } else {
    p->facing = 0;
  }
  p->anim = GetFile(DIR_ANIMATION, ANIM_COFFIN);
  FUN_08086024(p, 0);
  p->unk_31e = 0;
  p->unk_320 = 0;
  p->unk_322 = 0;
}

NAKED void FUN_08087058(Coffin* p) { INCFUNC("asm/func/FUN_08087058.inc"); }

void Coffin_InitHitbox(Coffin* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 size;
  Vec3 offset;
  s32 ignoreMask;

  size.x = 90, size.y = 32, size.z = 90;
  offset.x = 100, offset.y = 200, offset.z = 100;
  if (p->coffinID != COFFIN_SILVER) {
    s32 kind = p->unk_1c;

    ignoreMask = 2;
    if (kind == 0) {
      ignoreMask = 0x10;
    }
  } else {
    ignoreMask = 0x10;
  }
  Hitbox_Init(hitbox, p->subroutineID, HBFLAG_UNK_14 | HBFLAG_UNK_7 | HBFLAG_UNK_0, 0, ignoreMask, &size, &offset);
  Hitbox_SetPowerAndAttributes(hitbox, 0, 0, 0);
  Hitbox_SetHandler(hitbox, FUN_08087528, p);
  Hitbox_SetPos(hitbox, &p->mover.pos, 0);
  Hitbox_Register(hitbox);
}

void FUN_08087290(Coffin* p) {
  HitboxData* hitbox = &p->attackHitbox;
  Vec3 size;
  Vec3 offset;

  size.x = 0x80, size.y = 0x20, size.z = 0x80;
  offset.x = 0, offset.y = 0x20, offset.z = 0;
  Hitbox_Init(hitbox, p->subroutineID, HBFLAG_UNK_13 | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
  Hitbox_SetAttack(hitbox, 50, 50, 0, HBATTR_18, 30);
  Hitbox_SetHandler(hitbox, NULL, p);
}

void FUN_08087310(Coffin* p) {
  p->unk_3d4 = 2;
  p->unk_3d6 = 0;
  p->unk_3da = 0x40;
  p->unk_3dc = 3;
  p->unk_3de = 6;
  p->unk_3e0 = 2;
  p->unk_3e2 = 2;
  p->unk_3e4 = 60;
  p->unk_3e6 = 8;
  p->unk_3e8 = 0;
  p->unk_3ea = 0xFF;
  p->unk_3ec = 0xFF;
  p->unk_3ee = 0;
  p->unk_3f0 = 0xFF;
  p->unk_3f2 = 0;
  p->unk_3f4 = 0xFF;
  p->unk_3f6 = 0;
  p->unk_3f8 = 0xFF;
  p->unk_3fa = 0;
}

void FUN_080873b4(Coffin* p, s32 delta) {
  p->unk_326 += delta;

  if (p->unk_324 == 0) {
    if (p->unk_326 > 1200) {
      p->unk_326 = 1200;
      if (p->unk_394 == 0 && p->state != 2) {
        p->unk_324 = 1;
        p->unk_414 = FUN_080da9c4(p->unk_414, &p->mover, 1, 0, &p->unk_326, 1200, 250, 290);
      }
    }
  } else if (p->unk_326 > 1200) {
    p->unk_326 = 1200;
  }
}

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

void FUN_080874cc(Coffin* p) {
  if (gFlag030047a4 & FLAG030047A4_UNK_9) {
    return;
  }

  FUN_08087440(p);
  FUN_08087494(p);

  if (p->unk_332 != 0) {
    p->hitbox.flags |= HBFLAG_UNK_2;
    p->unk_332--;
  } else {
    p->hitbox.flags &= ~HBFLAG_UNK_2;
  }
}

// 残差9命令, 原典は unk_1c != 0 を 0/1 のフラグ (r2) に落としてから || の残りを見る bool diamond 形
// && の早期 return では materialize が消えて短くなる, Tier A-B は試済, 未: bool diamond の再現方法
NON_MATCH void FUN_08087528(HitboxData* a, HitboxData* b, Coffin* p) {
#ifdef NONMATCHING_C
  s32 damage;
  s32 timer;

  if (a->flags & HBFLAG_UNK_11) {
    return;
  }
  if (p->unk_1b == 1) {
    return;
  }
  if (p->unk_1c == 0 && (a->ignoreMask & 1) == 0 && (a->attributes & HBATTR_6) == 0) {
    return;
  }
  if (p->unk_332 != 0) {
    return;
  }
  if (a->power == 0) {
    return;
  }

  timer = 8;
  if (a->attributes & HBATTR_SOL) {
    damage = 200;
  } else if (a->attributes & HBATTR_DARK) {
    damage = 300;
    timer = 12;
  } else if (a->attributes & HBATTR_FLAME) {
    damage = 500;
  } else if (a->attributes & HBATTR_FROST) {
    damage = 150;
  } else if (a->attributes & HBATTR_CLOUD) {
    damage = 500;
  } else {
    damage = 400;
  }
  FUN_080873b4(p, damage);
  p->unk_330 = 4;
  p->unk_332 = timer;
#else
  INCFUNC("asm/func/FUN_08087528.inc");
#endif
}

void FUN_080875e8(Coffin* p) {
  s32 angle;

  p->unk_40c = p->mover.pos;
  angle = ((p->facing + 1) & 7) << 5;
  p->unk_40c.x += COS(angle, 0x80);
  p->unk_40c.z += SIN(angle, 0x80);
}

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

void FUN_08087c04(Coffin* p) {
  if (p->state != 0) {
    Coffin_SetState(p, 0);
  }
  p->hitbox.flags &= ~HBFLAG_UNK_2;
  p->unk_32a = 0;
  FUN_08086024(p, 0);

  if (gFlag030047a4 & FLAG030047A4_UNK_9) {
    return;
  }

  if (p->unk_394 != 0) {
    FUN_08087a5c(p);
  } else if (p->unk_324 != 0) {
    FUN_080856f4(p);
  } else if (p->unk_40a != 0) {
    p->unk_390 = p->unk_392;
    p->selfMoveTimer = p->selfMoveTimerInit;
    p->unk_394 = 0;
  } else {
    FUN_08087bac(p);
  }
}

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

void FUN_08088bbc(Coffin* p) {
  p->facing = 0;
  p->hitbox.flags |= HBFLAG_UNK_2;
  p->stateTimer++;
  FUN_08086024(p, 0);

  if (p->stateTimer <= 0x1B) {
    return;
  }

  if (p->stateTimer <= 0x2B) {
    s32 t = p->stateTimer;
    s32 n = t - 0x1C;

    p->sprite.flags |= SPRFLAG_AFFINE;
    p->sprite.scaleX = 0x40 - (n << 2);
    if (n > 8) {
      p->sprite.scaleY = n << 3;
      p->unk_320 = (t - 0x24) * 30;
    }
  } else if (p->stateTimer <= 0x33) {
    p->unk_320 = (p->stateTimer - 0x2C) * 200 + 240;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
}

NAKED void FUN_08088c54(Coffin* p) { INCFUNC("asm/func/FUN_08088c54.inc"); }

NAKED void FUN_08088d44(Coffin* p) { INCFUNC("asm/func/FUN_08088d44.inc"); }

// 残差4命令, FUN_08089088 と同じ stateTimer の u16 切り詰めの作り直し, Tier A-C は試済
NON_MATCH void FUN_08088fbc(Coffin* p) {
#ifdef NONMATCHING_C
  if (p->state != 6) {
    Coffin_SetState(p, 6);
  }

  if (gFlag030047a4 & FLAG030047A4_UNK_9) {
    return;
  }

  p->unk_32a = 0;
  p->stateTimer++;

  if (p->stateTimer <= 5) {
    if (p->stateTimer == 1) {
      p->unk_418 = 0;
      p->unk_414 = FUN_080da9c4(p->unk_414, &p->mover, 1, 0, &p->unk_418, 200, 250, 290);
    }
    return;
  }

  if (p->stateTimer == 6) {
    p->unk_414 = FUN_080d99d4(p->unk_414, 1, p->mover.id);
  }
  p->unk_320 -= 30;
  if (p->stateTimer > 8) {
    p->killRequested = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_08088fbc.inc");
#endif
}

// 残差3命令, 原典は stateTimer の u16 への切り詰め (lsls/lsrs #16) を比較ごとに作り直すが, こちらは1回で済ませてしまう
// u16 ローカル経由も試したが同じ, Tier A-C は試済, 未: per-TU フラグ
NON_MATCH void FUN_08089088(Coffin* p) {
#ifdef NONMATCHING_C
  if (p->state != 7) {
    Coffin_SetState(p, 7);
  }
  p->unk_32a = 0;
  p->stateTimer++;

  if (p->stateTimer <= 5) {
    if (p->stateTimer == 1) {
      p->unk_418 = 0;
      p->unk_414 = FUN_080da9c4(p->unk_414, &p->mover, 1, 0, &p->unk_418, 200, 250, 290);
    }
    return;
  }

  if (p->stateTimer == 6) {
    p->unk_414 = FUN_080d99d4(p->unk_414, 1, p->mover.id);
  }
  p->unk_320 -= 60;
  if (p->stateTimer > 0x1D) {
    p->killRequested = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_08089088.inc");
#endif
}

NAKED void FUN_08089144(Coffin* p) { INCFUNC("asm/func/FUN_08089144.inc"); }

void FUN_080892a8(Coffin* p) {
  if (p->state != 11) {
    Coffin_SetState(p, 11);
  }
  p->unk_32a = 0;
  p->unk_394 = 0;
  p->hitbox.flags |= HBFLAG_UNK_2;
  p->facing = 0;
  FUN_08086024(p, 0);
}

void FUN_080892f8(Coffin* p) {
  if (p->state != 13) {
    Coffin_SetState(p, 13);
  }
  p->hitbox.flags |= HBFLAG_UNK_2;
  p->facing = 0;
  if (FUN_08086024(p, 8) != 0) {
    Coffin_SetState(p, 12);
  }
}

void FUN_08089344(Coffin* p) {
  if (p->state != 12) {
    Coffin_SetState(p, 12);
  }

  if (p->coffinID == COFFIN_VAMPIRE) {
    p->unk_32a = 1;
  } else if (p->coffinID == COFFIN_IRON_MAIDEN) {
    p->unk_406 = 1;
    p->unk_32a = 0;
  } else {
    p->unk_32a = 0;
  }

  p->hitbox.flags |= HBFLAG_UNK_2;
  p->facing = 0;
  FUN_08086024(p, 24);
}

void FUN_080893c0(Coffin* p) {
  if (p->state != 14) {
    Coffin_SetState(p, 14);
  }
  p->hitbox.flags |= HBFLAG_UNK_2;
  p->facing = 0;
  if (FUN_08086024(p, 16) != 0) {
    Coffin_SetState(p, p->unk_408);
  }
}

NAKED void FUN_08089410(Coffin* p) { INCFUNC("asm/func/FUN_08089410.inc"); }

void FUN_08089548(Coffin* p) {
  if (p->state != 15) {
    Coffin_SetState(p, 15);
  }
  p->hitbox.flags &= ~HBFLAG_UNK_2;
  p->unk_32a = 1;
  FUN_08086024(p, 0);

  if (gFlag030047a4 & FLAG030047A4_UNK_9) {
    return;
  }

  if (p->unk_394 != 0) {
    FUN_08087a5c(p);
  } else if (p->unk_324 != 0) {
    p->unk_32a = 0;
    FUN_080856f4(p);
  } else {
    FUN_08089410(p);
  }
}

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
  Coffin_InitSprite(p);
  FUN_08087058(p);
  Coffin_Init_Helper_08086e64(p);
  Coffin_InitHitbox(p);
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
