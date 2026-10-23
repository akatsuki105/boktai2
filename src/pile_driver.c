#include "pile_driver.h"

#include "bg_pltt.h"
#include "camera.h"
#include "coffin.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "sound.h"
#include "video.h"
#include "vm.h"

// PileDriver の 0x0C6C に載っている一式, FUN_080b09d4 が PTR_ARRAY_085AD054[state] に渡す
typedef struct {
  u8 unk_0[0x67A];            // 0x000, まだ未解析
  u16 timer;                  // 0x67A, 毎フレーム +1 して duration と比べる
  u8 unk_67c[0x68A - 0x67C];  // 0x67C, まだ未解析
  u16 unk_68a;                // 0x68A, 0x10 が入る
  u8 unk_68c[0x690 - 0x68C];  // 0x68C, まだ未解析
  u16 duration;               // 0x690, timer の上限
  u8 unk_692[0x69C - 0x692];  // 0x692, まだ未解析
  Vec3 unk_69c;               // 0x69C, 3成分とも 0xA0
  Vec3 unk_6a4;               // 0x6A4, 当たり判定の広がりらしい値 {0x40, 0x20, 0x40}
  PileDriver* owner;          // 0x6AC
} PileDriverSub;

COMMON_DATA PileDriver* gPileDriver = NULL;  // 0x03002C58

const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_pile_driver_noon1_col_arr_08251d7c[] = "pile_driver_noon1_col_arr";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_pile_driver_even_col_arr_08251d98[] = "pile_driver_even_col_arr";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_pile_driver_night_col_arr_08251db4[] = "pile_driver_night_col_arr";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_ect_08251dd0[] = "ect";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_ect_anm_08251dd4[] = "ect_anm";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char gString_08251ddc[] = "../../skoba/enemy/system/eneinline.h";
const __attribute__((section(".rodata.string"))) ALIGNED(4) char s_ect_08251e04[] = "ect";

const FileID FileID_ARRAY_085ad048[6] = {
    TILEMAP_8446,
    TILEMAP_8546,
    TILEMAP_8646,
    TILEMAP_8746,
    TILEMAP_8846,
    TILEMAP_8946,
};  // 0x085AD048

void FUN_080df478(void);        // src/entity_080df420.c
void FUN_0805b1a0(unknown* p);  // src/code_08052eb8.s
void FUN_08086b18(WorldPos* pos);

void FUN_080ada64(PileDriver*);
void FUN_080ada9c(PileDriver*);
void FUN_080adb90(PileDriver*);
void FUN_080addac(PileDriver*);
void FUN_080add74(PileDriver*);
void FUN_080adca8(PileDriver*);
void FUN_080adc70(PileDriver*);
void FUN_080adc38(PileDriver*);
void FUN_080adc00(PileDriver*);
void FUN_080adbc8(PileDriver*);
void FUN_080adb28(PileDriver*);
void FUN_080adaf0(PileDriver*);
void FUN_080add3c(PileDriver*);

void FUN_080af890(PileDriverSub*);
void FUN_080af8a0(PileDriverSub*);
void FUN_080afa20(PileDriverSub*);
void FUN_080afbd0(PileDriverSub*);
void FUN_080afe18(PileDriverSub*);
void FUN_080affdc(PileDriverSub*);
void FUN_080af97c(PileDriverSub*);
void FUN_080b009c(PileDriverSub*);
void FUN_080b01b4(PileDriverSub*);
void FUN_080b01ec(PileDriverSub*);

void (*const PTR_ARRAY_085ad054[10])(PileDriverSub*) = {
    FUN_080af890,
    FUN_080af8a0,
    FUN_080afa20,
    FUN_080afbd0,
    FUN_080afe18,
    FUN_080affdc,
    FUN_080af97c,
    FUN_080b009c,
    FUN_080b01b4,
    FUN_080b01ec,
};  // 0x085AD054

void FUN_080b1174(PileDriver*);
void FUN_080b11b4(PileDriver*);
void FUN_080b1404(PileDriver*);
void FUN_080b1434(PileDriver*);
void FUN_080b14b8(PileDriver*);
void FUN_080b1574(PileDriver*);
void FUN_080b165c(PileDriver*);
void FUN_080b1718(PileDriver*);
void FUN_080b176c(PileDriver*);
void FUN_080b17bc(PileDriver*);
void FUN_080b17f4(PileDriver*);
void FUN_080b1888(PileDriver*);
void FUN_080b18c4(PileDriver*);
void FUN_080b19c0(PileDriver*);
void FUN_080b1a84(PileDriver*);

void (*const PTR_ARRAY_085ad07c[15])(PileDriver*) = {
    FUN_080b1174,
    FUN_080b11b4,
    FUN_080b1404,
    FUN_080b1434,
    FUN_080b14b8,
    FUN_080b1574,
    FUN_080b165c,
    FUN_080b1718,
    FUN_080b176c,
    FUN_080b17bc,
    FUN_080b17f4,
    FUN_080b1888,
    FUN_080b18c4,
    FUN_080b19c0,
    FUN_080b1a84,
};  // 0x085AD07C

void FUN_080ad1ec(PileDriver* p, u32 stateID) {
  p->unk_4fc = stateID;
  p->unk_4fe = 0;
}

// 残差は kind のスタック退避が分岐前に出る1命令のみ, Tier A は試済 (引数直接/ブロック内宣言/ローカルコピー), 未: B/C
NON_MATCH void FUN_080ad204(PileDriver* p, u32 kind) {
#ifdef NONMATCHING_C
  ScriptArgs args;
  u32 argv;

  if (p->unk_17a4 != 0) {
    argv = kind;
    args.argc = 1, args.argv = &argv;
    VM_ExecByID(p->unk_17a4, &args);
  }
#else
  INCFUNC("asm/func/FUN_080ad204.inc");
#endif
}

NAKED void FUN_080ad23c(PileDriver* p) { INCFUNC("asm/func/FUN_080ad23c.inc"); }

NAKED void FUN_080ad2d0(PileDriver* p, s32* param_2, SpriteFlags* param_3, u8 param_4, u8 param_5) { INCFUNC("asm/func/FUN_080ad2d0.inc"); }

// PileDriver が 0x0C6C から15件持つ枠
typedef struct {
  AuxSprite spr;          // 0x00, FUN_080b0ab4 が AuxSprite_Remove に渡す
  u8 unk_2c[104 - 0x2C];  // 0x2C, まだ未解析
} PileDriverSprite104;
static_assert(sizeof(PileDriverSprite104) == 104);

// 粒子の枠を32個まとめて外す
void FUN_080ad368(PileDriver* p) {
  s32 i;

  for (i = 0; i < 32; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
}

NAKED void FUN_080ad388(PileDriver* p) { INCFUNC("asm/func/FUN_080ad388.inc"); }

NAKED void FUN_080ad3e8(PileDriver* p, u32 param_2) { INCFUNC("asm/func/FUN_080ad3e8.inc"); }

// 枠が動いていて隠れてもいないかどうか
bool32 FUN_080ad4e4(PileDriverAnimSprite* p) {
  if (p->unk_68 == 0) {
    return FALSE;
  }
  if (p->spr.flags & SPRFLAG_HIDDEN) {
    return FALSE;
  }
  return TRUE;
}

// 129フレーム周期のカウンタから 0, 1, 2, 3, 2, 1 と往復するポーズ番号を返す
s32 FUN_080ad504(PileDriverAnimSprite* p) {
  if (++p->animTimer > 129) {
    p->animTimer = 0;
  }

  if (p->animTimer <= 29) {
    return 0;
  }
  if (p->animTimer <= 39) {
    return 1;
  }
  if (p->animTimer <= 49) {
    return 2;
  }
  if (p->animTimer <= 109) {
    return 3;
  }
  if (p->animTimer <= 119) {
    return 2;
  }
  return 1;
}

NAKED void FUN_080ad544(PileDriver* p) { INCFUNC("asm/func/FUN_080ad544.inc"); }

NAKED void FUN_080ad6a8(PileDriver* p) { INCFUNC("asm/func/FUN_080ad6a8.inc"); }

NAKED void FUN_080ad96c(PileDriver* p) { INCFUNC("asm/func/FUN_080ad96c.inc"); }

void FUN_080ad9d4(PileDriver* p, s32 idx, u16 val) {
  p->unk_230[idx] = val;
  p->unk_1428 = TRUE;
}

void PileDriver_SetState(PileDriver* p, PileDriverFunc* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080ada0c(PileDriver* p) {
  FUN_080ad9d4(p, 2, 2);
  PileDriver_SetState(p, NULL);
}

void FUN_080ada28(PileDriver* p) {
  FUN_080ad9d4(p, 2, 5);
  PileDriver_SetState(p, NULL);
}

void FUN_080ada44(PileDriver* p) {
  FUN_080ad9d4(p, 2, 3);
  PileDriver_SetState(p, FUN_080ada64);
}

void FUN_080ada64(PileDriver* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 4);
    PileDriver_SetState(p, FUN_080ada9c);
  }
}

void FUN_080ada9c(PileDriver* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 5);
    PileDriver_SetState(p, NULL);
  }
}

void FUN_080adad0(PileDriver* p) {
  FUN_080ad9d4(p, 2, 4);
  PileDriver_SetState(p, FUN_080adaf0);
}

void FUN_080adaf0(PileDriver* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 3);
    PileDriver_SetState(p, FUN_080adb28);
  }
}

void FUN_080adb28(PileDriver* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 2);
    PileDriver_SetState(p, NULL);
  }
}

void FUN_080adb5c(PileDriver* p) {
  FUN_080ad9d4(p, 2, 6);
  PileDriver_SetState(p, FUN_080adb90);
  p->unk_1420 = 0;
  p->stateTimer = 0;
}

void FUN_080adb90(PileDriver* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 7);
    PileDriver_SetState(p, FUN_080adbc8);
  }
}

void FUN_080adbc8(PileDriver* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 8);
    PileDriver_SetState(p, FUN_080adc00);
  }
}

void FUN_080adc00(PileDriver* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 9);
    PileDriver_SetState(p, FUN_080adc38);
  }
}

void FUN_080adc38(PileDriver* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 10);
    PileDriver_SetState(p, FUN_080adc70);
  }
}

void FUN_080adc70(PileDriver* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 11);
    PileDriver_SetState(p, FUN_080adca8);
  }
}

void FUN_080adca8(PileDriver* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 2);
    PileDriver_SetState(p, NULL);
    p->unk_1420 = 1;
  }
}

void FUN_080adce4(PileDriver* p) {
  FUN_080ad9d4(p, 2, 12);
  PileDriver_SetState(p, FUN_080add3c);
}

void FUN_080add04(PileDriver* p) {
  if (++p->stateTimer > 37) {
    FUN_080ad9d4(p, 2, 12);
    PileDriver_SetState(p, FUN_080add3c);
  }
}

void FUN_080add3c(PileDriver* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 13);
    PileDriver_SetState(p, FUN_080add74);
  }
}

void FUN_080add74(PileDriver* p) {
  if (++p->stateTimer > 37) {
    FUN_080ad9d4(p, 2, 12);
    PileDriver_SetState(p, FUN_080addac);
  }
}

void FUN_080addac(PileDriver* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 2);
    PileDriver_SetState(p, FUN_080add04);
  }
}

// 太陽ゲージに応じた BGP_PD のパレット行を返す
s32 FUN_080adde4(PileDriver* p) {
  switch (p->unk_c10) {
    case 0: {
      return 8;
    }
    case 1:
    case 2: {
      return 6;
    }
    case 3: {
      return 4;
    }
    case 4: {
      return 2;
    }
    case 7:
    case 8: {
      return 10;
    }
    case 9:
    case 10: {
      return 12;
    }
    default: {
      return 0;
    }
  }
}

void PileDriver_LoadBgPltt(PileDriver* p) {
  rgb555* bgp = GetBgPlttFile(BGP_PD)->body;
  CpuCopy32(&bgp[FUN_080adde4(p) * 16], gBgPlttBuffer, 32 * sizeof(rgb555));
}

NAKED void FUN_080ade88(PileDriver* p) { INCFUNC("asm/func/FUN_080ade88.inc"); }

void FUN_080adf50(PileDriver* p) { p->unk_1324 = 48; }

void FUN_080adf60(void) {
  if (gPileDriver != NULL) {
    gPileDriver->unk_1324 = 64;
    gPileDriver->unk_1326 = 0;
    gPileDriver->unk_1374 = TRUE;
    PlaySound_082406e0(SE_UNK_297);
  }
}

NAKED void FUN_080adfa0(PileDriver* p, s32 param_2, s32 param_3, u32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080adfa0.inc"); }

NAKED void FUN_080ae394(PileDriver* p) { INCFUNC("asm/func/FUN_080ae394.inc"); }

// 2フレームごとに plttSrc の4組を順に BG パレットの11行目へ送る
// 残差4命令, 原典は plttTimer の u16 切り捨て (0xFFFF) をプール定数で別に作ってから & 1 するが, agbcc はこれを & 1 に畳む
// Tier A-B 試済: u16 ローカルに退避 (レジスタが1本増える)
NON_MATCH void FUN_080ae428(PileDriver* p) {
#ifdef NONMATCHING_C
  p->plttTimer++;
  if (p->plttTimer & 1) {
    CpuCopy32(&p->plttSrc[((p->plttTimer >> 1) & 3) * 16], &gBgPlttBuffer[176], 32);
  }
#else
  INCFUNC("asm/func/FUN_080ae428.inc");
#endif
}

NAKED void FUN_080ae478(s32 param_1, s32 param_2, s32 param_3, u16 param_4, u16 param_5) { INCFUNC("asm/func/FUN_080ae478.inc"); }

NAKED void FUN_080ae8a4(PileDriver* p) { INCFUNC("asm/func/FUN_080ae8a4.inc"); }

NAKED void FUN_080ae928(PileDriver* p) { INCFUNC("asm/func/FUN_080ae928.inc"); }

NAKED void FUN_080aead8(PileDriver* p) { INCFUNC("asm/func/FUN_080aead8.inc"); }

NAKED void FUN_080aeb98(PileDriver* p) { INCFUNC("asm/func/FUN_080aeb98.inc"); }

NAKED void FUN_080aee18(PileDriver* p) { INCFUNC("asm/func/FUN_080aee18.inc"); }

NAKED void FUN_080aefe8(PileDriver* p) { INCFUNC("asm/func/FUN_080aefe8.inc"); }

void FUN_080af0ac(PileDriver* p) {
  if (p->unk_135c != NULL) {
    p->unk_135c(p);
  }
}

void FUN_080af0c8(PileDriver* p) {
  switch (p->tilemapIdx) {
    case 3: {
      FUN_080df478();
      break;
    }
    case 4: {
      FUN_0805b1a0(p->unk_1360);
      break;
    }
  }
}

NAKED void FUN_080af0f8(PileDriver* p) { INCFUNC("asm/func/FUN_080af0f8.inc"); }

NAKED void FUN_080af200(PileDriver* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080af200.inc"); }

// 15枚をまとめて隠す
// 残差2命令ぶんの位置ずれ (32 対 32), 原典はループ不変の 1 を elem の初期化より前に作る
// 直接代入 / AuxSprite_Hide / AuxSprite_SetFlags / 添字形 / 宣言順の入れ替えはいずれも同じ並び
NON_MATCH void FUN_080af2f4(PileDriverSprite104* elems) {
#ifdef NONMATCHING_C
  s32 i;
  PileDriverSprite104* elem;

  elems->spr.flags |= SPRFLAG_HIDDEN;

  elem = &elems[1];
  for (i = 0; i < 8; i++) {
    elem->spr.flags |= SPRFLAG_HIDDEN;
    elem++;
  }

  elem = &elems[9];
  for (i = 0; i < 6; i++) {
    elem->spr.flags |= SPRFLAG_HIDDEN;
    elem++;
  }
#else
  INCFUNC("asm/func/FUN_080af2f4.inc");
#endif
}

// 15枚をまとめて出す
// 残差は2つめのループだけ (32 対 32), 原典は ~1 を base より先に作る, FUN_080af2f4 と同じ形
NON_MATCH void FUN_080af334(PileDriverSprite104* elems) {
#ifdef NONMATCHING_C
  s32 i;
  PileDriverSprite104* elem;

  elems->spr.flags &= ~SPRFLAG_HIDDEN;

  elem = &elems[1];
  for (i = 0; i < 8; i++) {
    elem->spr.flags &= ~SPRFLAG_HIDDEN;
    elem++;
  }

  elem = &elems[9];
  for (i = 0; i < 6; i++) {
    elem->spr.flags &= ~SPRFLAG_HIDDEN;
    elem++;
  }
#else
  INCFUNC("asm/func/FUN_080af334.inc");
#endif
}

NAKED void FUN_080af374(unknown* p, s32 param_2) { INCFUNC("asm/func/FUN_080af374.inc"); }

NAKED void FUN_080af400(PileDriver* p) { INCFUNC("asm/func/FUN_080af400.inc"); }

s32 FUN_080af4a4(PileDriverSub* p, s32 idx, u32 state) {
  if (p->owner->generators[idx]->state == state) {
    return 1;
  }
  return 0;
}

void FUN_080af4d4(PileDriverSub* p, s32 idx, s32 state) { Generator_SetState(p->owner->generators[idx], state); }

u8 FUN_080af4f8(PileDriverSub* p) { return p->owner->unk_1f; }

u8 FUN_080af508(PileDriverSub* p) { return p->owner->unk_c10; }

void FUN_080af51c(PileDriverSub* p, s32 idx) { p->owner->generators[idx]->unk_e2 = 1; }

NAKED s32 FUN_080af53c(PileDriver* p) { INCFUNC("asm/func/FUN_080af53c.inc"); }

NAKED void FUN_080af5b8(PileDriverSub* p) { INCFUNC("asm/func/FUN_080af5b8.inc"); }

NAKED void FUN_080af6c4(PileDriver* p) { INCFUNC("asm/func/FUN_080af6c4.inc"); }

void FUN_080af890(PileDriverSub* p) { p->unk_68a = 0x10; }

NAKED void FUN_080af8a0(PileDriverSub* p) { INCFUNC("asm/func/FUN_080af8a0.inc"); }

NAKED void FUN_080af97c(PileDriverSub* p) { INCFUNC("asm/func/FUN_080af97c.inc"); }

NAKED void FUN_080afa20(PileDriverSub* p) { INCFUNC("asm/func/FUN_080afa20.inc"); }

NAKED void FUN_080afbd0(PileDriverSub* p) { INCFUNC("asm/func/FUN_080afbd0.inc"); }

NAKED void FUN_080afe18(PileDriverSub* p) { INCFUNC("asm/func/FUN_080afe18.inc"); }

NAKED void FUN_080affdc(PileDriverSub* p) { INCFUNC("asm/func/FUN_080affdc.inc"); }

NAKED void FUN_080b009c(PileDriverSub* p) { INCFUNC("asm/func/FUN_080b009c.inc"); }

// duration フレーム経ったら次へ進む
void FUN_080b01b4(PileDriverSub* p) {
  p->timer++;

  if (p->timer >= p->duration) {
    FUN_080af5b8(p);
    FUN_080af374(p, 3);
  }
}

NAKED void FUN_080b01ec(PileDriverSub* p) { INCFUNC("asm/func/FUN_080b01ec.inc"); }

NAKED void FUN_080b02e0(PileDriver* p) { INCFUNC("asm/func/FUN_080b02e0.inc"); }

NAKED void FUN_080b0398(PileDriver* p, s32 param_2) { INCFUNC("asm/func/FUN_080b0398.inc"); }

NAKED void FUN_080b05b0(PileDriver* p, s32 param_2) { INCFUNC("asm/func/FUN_080b05b0.inc"); }

NAKED void FUN_080b087c(PileDriver* p, s32 param_2) { INCFUNC("asm/func/FUN_080b087c.inc"); }

NAKED void FUN_080b09d4(PileDriver* p) { INCFUNC("asm/func/FUN_080b09d4.inc"); }

void FUN_080b0ab4(PileDriverSprite104* elems) {
  PileDriverSprite104* elem;
  s32 i;

  AuxSprite_Remove(&elems->spr);

  elem = &elems[1];
  for (i = 0; i < 8; i++) {
    AuxSprite_Remove(&elem->spr);
    elem++;
  }

  elem = &elems[9];
  for (i = 0; i < 6; i++) {
    AuxSprite_Remove(&elem->spr);
    elem++;
  }
}

NAKED void FUN_080b0aec(PileDriver* p, u32 param_2) { INCFUNC("asm/func/FUN_080b0aec.inc"); }

NAKED void FUN_080b0b7c(PileDriver* p) { INCFUNC("asm/func/FUN_080b0b7c.inc"); }

NAKED void FUN_080b0bf4(PileDriver* p) { INCFUNC("asm/func/FUN_080b0bf4.inc"); }

NAKED void FUN_080b0d28(PileDriver* p) { INCFUNC("asm/func/FUN_080b0d28.inc"); }

void FUN_080b0e3c(PileDriver* p) {
  FUN_080b0b7c(p);
  FUN_080b0bf4(p);
  FUN_080b0d28(p);
}

void FUN_080b0e58(PileDriverSub* p) {
  p->unk_69c.x = 0xA0, p->unk_69c.y = 0xA0, p->unk_69c.z = 0xA0;
  p->unk_6a4.x = 0x40, p->unk_6a4.y = 0x20, p->unk_6a4.z = 0x40;
}

NAKED void FUN_080b0e98(PileDriver* p) { INCFUNC("asm/func/FUN_080b0e98.inc"); }

// a と b の水平距離が radius 以内かどうか
bool32 FUN_080b1038(Vec3* a, Vec3* b, s32 radius) {
  s32 dx = a->x - b->x;
  s32 dz = a->z - b->z;

  if (dx > radius || dz > radius) {
    return FALSE;
  }
  if (dx * dx + dz * dz <= radius * radius) {
    return TRUE;
  }
  return FALSE;
}

s32 FUN_080b1078(PileDriver* p) {
  if (gCoffin != NULL && gPlayerPtr[0]->unk_1c == 1 && gPlayerPtr[0]->action == 6 && FUN_080b1038(&gCoffin->mover.pos, &p->pos_510, 70)) {
    return 1;
  }
  return 0;
}

s32 FUN_080b10c4(PileDriver* p) {
  s32 i;

  for (i = 0; i < p->unk_1e; i++) {
    if (p->generators[i]->state != 2) {
      return 0;
    }
  }
  return 1;
}

s32 FUN_080b10f8(PileDriver* p) {
  Player* player = gPlayerPtr[0];

  if (player->unk_1c != 1) {
    return 0;
  }
  if (player->kind >= PLAYER_BAT && player->kind <= PLAYER_SLEEPING) {
    return 0;
  }
  if (player->action != 7) {
    return 0;
  }
  if (!FUN_080b1038(&player->mover.pos, &p->unk_508, 100)) {
    return 0;
  }
  return 1;
}

// gCoffin が 800 以内にいなければ 1
s32 FUN_080b1148(PileDriver* p) {
  if (FUN_080b1038(&gCoffin->mover.pos, &p->pos_510, 800)) {
    return 0;
  }
  return 1;
}

void FUN_080b1174(PileDriver* p) {
  if (FUN_080b1078(p)) {
    FUN_0807bb3c(gPlayerPtr[0], NULL, -1, 0, 0);
    p->unk_c16 = 0;
    FUN_080ad1ec(p, 1);
  }
}

NAKED void FUN_080b11b4(PileDriver* p) { INCFUNC("asm/func/FUN_080b11b4.inc"); }

void FUN_080b1404(PileDriver* p) {
  if (FUN_080b10c4(p)) {
    Player_Unlock(gPlayerPtr[0]);
    FUN_080ad1ec(p, 3);
    FUN_080ad204(p, 0);
  }
}

NAKED void FUN_080b1434(PileDriver* p) { INCFUNC("asm/func/FUN_080b1434.inc"); }

NAKED void FUN_080b14b8(PileDriver* p) { INCFUNC("asm/func/FUN_080b14b8.inc"); }

NAKED void FUN_080b1574(PileDriver* p) { INCFUNC("asm/func/FUN_080b1574.inc"); }

void FUN_080b165c(PileDriver* p) {
  p->unk_4fe++;
  if (p->unk_4fe == 30) {
    s32 i;

    for (i = 0; i < p->unk_1e; i++) {
      if (p->generators[i]->state == 4) {
        Generator_SetState(p->generators[i], 5);
      }
    }
    PileDriver_SetState(p, FUN_080adb5c);
    Sound_FadeOutBGM(4);
  } else if (p->unk_4fe == 90) {
    FUN_0823bca8(16);
    FUN_0807bc64(gPlayerPtr[0], 0);
  } else if (p->unk_4fe > 105) {
    if (gPlayerPtr[0]->action == 0) {
      Player_Unlock(gPlayerPtr[0]);
      FUN_080ad1ec(p, 3);
      p->unk_1332 = 0;
      FUN_080ad204(p, 2);
    }
  }
}

void FUN_080b1718(PileDriver* p) {
  if (p->unk_4fe <= 69) {
    p->unk_4fe++;
    if (p->unk_4fe == 70) {
      FUN_080ad204(p, 3);
    }
  }
  if (p->unk_1333) {
    if (p->unk_1334 <= 59) {
      p->unk_1334++;
    }
    FUN_0823b9cc(p->unk_1334 >> 1);
  }
}

void FUN_080b176c(PileDriver* p) {
  if (p->unk_4fe <= 29) {
    p->unk_4fe++;
  } else if (!p->unk_c12) {
    PlaySound_082406e0(SONG_490);
    gCoffin->state = 13;
    FUN_080ad1ec(p, 9);
  }
}

void FUN_080b17bc(PileDriver* p) {
  if (gCoffin->state == 12) {
    FUN_080af374(p->unk_c6c, 1);
    FUN_080ad1ec(p, 10);
  }
}

NAKED void FUN_080b17f4(PileDriver* p) { INCFUNC("asm/func/FUN_080b17f4.inc"); }

void FUN_080b1888(PileDriver* p) {
  if (p->unk_12e4 == 0) {
    PlaySound_082406e0(SONG_491);
    FUN_08086b18(&p->pos_510);
    FUN_080ad1ec(p, 12);
    FUN_080ad204(p, 5);
  }
}

NAKED void FUN_080b18c4(PileDriver* p) { INCFUNC("asm/func/FUN_080b18c4.inc"); }

NAKED void FUN_080b19c0(PileDriver* p) { INCFUNC("asm/func/FUN_080b19c0.inc"); }

void FUN_080b1a84(PileDriver* p) {}

NAKED void FUN_080b1a88(PileDriver* p) { INCFUNC("asm/func/FUN_080b1a88.inc"); }

NAKED void FUN_080b1b1c(PileDriver* p) { INCFUNC("asm/func/FUN_080b1b1c.inc"); }

NAKED void FUN_080b1b74(PileDriver* p) { INCFUNC("asm/func/FUN_080b1b74.inc"); }

NAKED void FUN_080b1d5c(PileDriver* p) { INCFUNC("asm/func/FUN_080b1d5c.inc"); }

void FUN_080b1de8(PileDriver* p) {
  if (VM_SeekToNamedArg('p')) {
    p->unk_17a4 = VM_GetValue();
  } else {
    p->unk_17a4 = 0;
  }
}

NAKED void FUN_080b1e18(PileDriver* p) { INCFUNC("asm/func/FUN_080b1e18.inc"); }

s32 FUN_080b2060(PileDriver* p) {
  s32 i;

  for (i = 0; i < p->unk_1e; i++) {
    if (p->generators[i]->state != 0) {
      return 0;
    }
  }
  return 1;
}

NAKED void FUN_080b2094(PileDriver* p) { INCFUNC("asm/func/FUN_080b2094.inc"); }

void FUN_080b21d8(PileDriver* p) {
  u32 val = VM_SeekToNamedArg('m');

  if (val) {
    val = VM_GetValue();
  }
  p->unk_1a = val;
}

void FUN_080b21f4(void) {
  if (gPileDriver != NULL) {
    gPileDriver->unk_c0f = 1;
    gPileDriver->unk_c11 = gPileDriver->unk_c10;
  }
}

NAKED void FUN_080b2224(void) { INCFUNC("asm/func/FUN_080b2224.inc"); }

void FUN_080b22e8(void) {
  if (gPileDriver != NULL) {
    gPileDriver->unk_1333 = TRUE;
    gPileDriver->unk_1334 = 0;
  }
}

void FUN_080b2314(void) {
  if (gPileDriver != NULL) {
    gPileDriver->unk_c12 = TRUE;
  }
}

void FUN_080b2334(void) {
  if (gPileDriver != NULL) {
    gPileDriver->unk_c12 = FALSE;
  }
}

NAKED void FUN_080b2354(PileDriver* p) { INCFUNC("asm/func/FUN_080b2354.inc"); }

void FUN_080b23fc(PileDriver* p) { MsgQueue_Unregister(&p->mq); }

void FUN_080b2410(PileDriver* p) { MsgQueue_Register(&p->mq, p->subroutineID, 9); }

s32 FUN_080b2428(void) {
  gPileDriver = NULL;
  return 0;
}

void FUN_080b2434(PileDriver* p) {
  s32 val;

  if (p->unk_c0f == 0) {
    val = gStat->sunGauge;
  } else {
    val = p->unk_c11;
  }
  p->unk_c10 = val;
}

// state が 4 のジェネレーターの数
u32 FUN_080b2474(PileDriver* p) {
  s32 i;
  u32 count = 0;

  for (i = 0; i < p->unk_1e; i++) {
    if (p->generators[i]->state == 4) {
      count++;
    }
  }
  return count;
}

NAKED void FUN_080b24a4(PileDriver* p) { INCFUNC("asm/func/FUN_080b24a4.inc"); }

NAKED void FUN_080b252c(PileDriver* p) { INCFUNC("asm/func/FUN_080b252c.inc"); }

NAKED s32 PileDriver_Update(PileDriver* p) { INCFUNC("asm/func/PileDriver_Update.inc"); }

s32 PileDriver_Destroy(PileDriver* p) {
  if (p->unk_1a == 0) {
    if (p->sprite_254.unk_68 != 0) {
      AuxSprite_Remove(&p->sprite_254.spr);
    }
  } else {
    FUN_080b0ab4((PileDriverSprite104*)p->unk_c6c);
    AuxSprite_Remove(&p->sprite_518);
    SetBGPrioDirect(1, 1);
  }

  FUN_080ad368(p);
  FUN_080b23fc(p);
  gPileDriver = NULL;
  return 0;
}

NAKED s32 PileDriver_Init(PileDriver* p) { INCFUNC("asm/func/PileDriver_Init.inc"); }

PileDriver* PileDriver_Create(u32 subroutineID) {
  PileDriver* p;

  if (gPileDriver != NULL) {
    return gPileDriver;
  }

  p = CreateEntity(ENTITY_UNK_9, sizeof(PileDriver));
  if (p != NULL) {
    SetEntityRoutine(p, PileDriver_Update, PileDriver_Destroy);
    p->subroutineID = subroutineID;
    if (PileDriver_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
