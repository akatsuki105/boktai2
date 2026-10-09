#include "pile_driver.h"

#include "bg_pltt.h"
#include "camera.h"
#include "coffin_immortal.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "sound.h"
#include "video.h"
#include "vm.h"

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
void FUN_08086b18(Vec3* pos);
void FUN_0823bca8(s32 n);  // src/camera.c

void FUN_080ada64(EntityCBB0*);
void FUN_080ada9c(EntityCBB0*);
void FUN_080adb90(EntityCBB0*);
void FUN_080addac(EntityCBB0*);
void FUN_080add74(EntityCBB0*);
void FUN_080adca8(EntityCBB0*);
void FUN_080adc70(EntityCBB0*);
void FUN_080adc38(EntityCBB0*);
void FUN_080adc00(EntityCBB0*);
void FUN_080adbc8(EntityCBB0*);
void FUN_080adb28(EntityCBB0*);
void FUN_080adaf0(EntityCBB0*);
void FUN_080add3c(EntityCBB0*);

void FUN_080af890(EntityCBB0*);
void FUN_080af8a0(EntityCBB0*);
void FUN_080afa20(EntityCBB0*);
void FUN_080afbd0(EntityCBB0*);
void FUN_080afe18(EntityCBB0*);
void FUN_080affdc(EntityCBB0*);
void FUN_080af97c(EntityCBB0*);
void FUN_080b009c(EntityCBB0*);
void FUN_080b01b4(EntityCBB0*);
void FUN_080b01ec(EntityCBB0*);

void (*const PTR_ARRAY_085ad054[10])(EntityCBB0*) = {
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

void FUN_080b1174(EntityCBB0*);
void FUN_080b11b4(EntityCBB0*);
void FUN_080b1404(EntityCBB0*);
void FUN_080b1434(EntityCBB0*);
void FUN_080b14b8(EntityCBB0*);
void FUN_080b1574(EntityCBB0*);
void FUN_080b165c(EntityCBB0*);
void FUN_080b1718(EntityCBB0*);
void FUN_080b176c(EntityCBB0*);
void FUN_080b17bc(EntityCBB0*);
void FUN_080b17f4(EntityCBB0*);
void FUN_080b1888(EntityCBB0*);
void FUN_080b18c4(EntityCBB0*);
void FUN_080b19c0(EntityCBB0*);
void FUN_080b1a84(EntityCBB0*);

void (*const PTR_ARRAY_085ad07c[15])(EntityCBB0*) = {
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

void FUN_080ad1ec(EntityCBB0* p, u32 stateID) {
  p->unk_4fc = stateID;
  p->unk_4fe = 0;
}

// 残差は kind のスタック退避が分岐前に出る1命令のみ, Tier A は試済 (引数直接/ブロック内宣言/ローカルコピー), 未: B/C
NON_MATCH void FUN_080ad204(EntityCBB0* p, u32 kind) {
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

NAKED void FUN_080ad23c(EntityCBB0* p) { INCFUNC("asm/func/FUN_080ad23c.inc"); }

NAKED void FUN_080ad2d0(EntityCBB0* p, s32* param_2, SpriteFlags* param_3, u8 param_4, u8 param_5) { INCFUNC("asm/func/FUN_080ad2d0.inc"); }

NAKED void FUN_080ad368(EntityCBB0* p) { INCFUNC("asm/func/FUN_080ad368.inc"); }

NAKED void FUN_080ad388(EntityCBB0* p) { INCFUNC("asm/func/FUN_080ad388.inc"); }

NAKED void FUN_080ad3e8(EntityCBB0* p, u32 param_2) { INCFUNC("asm/func/FUN_080ad3e8.inc"); }

NAKED s32 FUN_080ad4e4(unknown* param_1) { INCFUNC("asm/func/FUN_080ad4e4.inc"); }

NAKED s32 FUN_080ad504(EntityCBB0* p) { INCFUNC("asm/func/FUN_080ad504.inc"); }

NAKED void FUN_080ad544(EntityCBB0* p) { INCFUNC("asm/func/FUN_080ad544.inc"); }

NAKED void FUN_080ad6a8(EntityCBB0* p) { INCFUNC("asm/func/FUN_080ad6a8.inc"); }

NAKED void FUN_080ad96c(EntityCBB0* p) { INCFUNC("asm/func/FUN_080ad96c.inc"); }

void FUN_080ad9d4(EntityCBB0* p, s32 idx, u16 val) {
  p->unk_230[idx] = val;
  p->unk_1428 = TRUE;
}

void EntityCBB0_SetState(EntityCBB0* p, EntityCBB0Func* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

void FUN_080ada0c(EntityCBB0* p) {
  FUN_080ad9d4(p, 2, 2);
  EntityCBB0_SetState(p, NULL);
}

void FUN_080ada28(EntityCBB0* p) {
  FUN_080ad9d4(p, 2, 5);
  EntityCBB0_SetState(p, NULL);
}

void FUN_080ada44(EntityCBB0* p) {
  FUN_080ad9d4(p, 2, 3);
  EntityCBB0_SetState(p, FUN_080ada64);
}

void FUN_080ada64(EntityCBB0* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 4);
    EntityCBB0_SetState(p, FUN_080ada9c);
  }
}

void FUN_080ada9c(EntityCBB0* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 5);
    EntityCBB0_SetState(p, NULL);
  }
}

void FUN_080adad0(EntityCBB0* p) {
  FUN_080ad9d4(p, 2, 4);
  EntityCBB0_SetState(p, FUN_080adaf0);
}

void FUN_080adaf0(EntityCBB0* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 3);
    EntityCBB0_SetState(p, FUN_080adb28);
  }
}

void FUN_080adb28(EntityCBB0* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 2);
    EntityCBB0_SetState(p, NULL);
  }
}

void FUN_080adb5c(EntityCBB0* p) {
  FUN_080ad9d4(p, 2, 6);
  EntityCBB0_SetState(p, FUN_080adb90);
  p->unk_1420 = 0;
  p->stateTimer = 0;
}

void FUN_080adb90(EntityCBB0* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 7);
    EntityCBB0_SetState(p, FUN_080adbc8);
  }
}

void FUN_080adbc8(EntityCBB0* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 8);
    EntityCBB0_SetState(p, FUN_080adc00);
  }
}

void FUN_080adc00(EntityCBB0* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 9);
    EntityCBB0_SetState(p, FUN_080adc38);
  }
}

void FUN_080adc38(EntityCBB0* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 10);
    EntityCBB0_SetState(p, FUN_080adc70);
  }
}

void FUN_080adc70(EntityCBB0* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 11);
    EntityCBB0_SetState(p, FUN_080adca8);
  }
}

void FUN_080adca8(EntityCBB0* p) {
  if (++p->stateTimer > 5) {
    FUN_080ad9d4(p, 2, 2);
    EntityCBB0_SetState(p, NULL);
    p->unk_1420 = 1;
  }
}

void FUN_080adce4(EntityCBB0* p) {
  FUN_080ad9d4(p, 2, 12);
  EntityCBB0_SetState(p, FUN_080add3c);
}

void FUN_080add04(EntityCBB0* p) {
  if (++p->stateTimer > 37) {
    FUN_080ad9d4(p, 2, 12);
    EntityCBB0_SetState(p, FUN_080add3c);
  }
}

void FUN_080add3c(EntityCBB0* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 13);
    EntityCBB0_SetState(p, FUN_080add74);
  }
}

void FUN_080add74(EntityCBB0* p) {
  if (++p->stateTimer > 37) {
    FUN_080ad9d4(p, 2, 12);
    EntityCBB0_SetState(p, FUN_080addac);
  }
}

void FUN_080addac(EntityCBB0* p) {
  if (++p->stateTimer > 7) {
    FUN_080ad9d4(p, 2, 2);
    EntityCBB0_SetState(p, FUN_080add04);
  }
}

// 太陽ゲージに応じた BGP_313A のパレット行を返す
s32 FUN_080adde4(EntityCBB0* p) {
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

// BGP_313A
void EntityCBB0_LoadBgPltt(EntityCBB0* p) {
  rgb555* bgp = GetBgPlttFile(BGP_313A)->body;
  CpuCopy32(&bgp[FUN_080adde4(p) * 16], gBgPlttBuffer, 32 * sizeof(rgb555));
}

NAKED void FUN_080ade88(EntityCBB0* p) { INCFUNC("asm/func/FUN_080ade88.inc"); }

void FUN_080adf50(EntityCBB0* p) { p->unk_1324 = 48; }

void FUN_080adf60(void) {
  if (gEntityCBB0 != NULL) {
    gEntityCBB0->unk_1324 = 64;
    gEntityCBB0->unk_1326 = 0;
    gEntityCBB0->unk_1374 = TRUE;
    PlaySound_082406e0(0x129);
  }
}

NAKED void FUN_080adfa0(EntityCBB0* p, s32 param_2, s32 param_3, u32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_080adfa0.inc"); }

NAKED void FUN_080ae394(EntityCBB0* p) { INCFUNC("asm/func/FUN_080ae394.inc"); }

NAKED void FUN_080ae428(EntityCBB0* p) { INCFUNC("asm/func/FUN_080ae428.inc"); }

NAKED void FUN_080ae478(s32 param_1, s32 param_2, s32 param_3, u16 param_4, u16 param_5) { INCFUNC("asm/func/FUN_080ae478.inc"); }

NAKED void FUN_080ae8a4(EntityCBB0* p) { INCFUNC("asm/func/FUN_080ae8a4.inc"); }

NAKED void FUN_080ae928(EntityCBB0* p) { INCFUNC("asm/func/FUN_080ae928.inc"); }

NAKED void FUN_080aead8(EntityCBB0* p) { INCFUNC("asm/func/FUN_080aead8.inc"); }

NAKED void FUN_080aeb98(EntityCBB0* p) { INCFUNC("asm/func/FUN_080aeb98.inc"); }

NAKED void FUN_080aee18(EntityCBB0* p) { INCFUNC("asm/func/FUN_080aee18.inc"); }

NAKED void FUN_080aefe8(EntityCBB0* p) { INCFUNC("asm/func/FUN_080aefe8.inc"); }

void FUN_080af0ac(EntityCBB0* p) {
  if (p->unk_135c != NULL) {
    p->unk_135c(p);
  }
}

void FUN_080af0c8(EntityCBB0* p) {
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

NAKED void FUN_080af0f8(EntityCBB0* p) { INCFUNC("asm/func/FUN_080af0f8.inc"); }

NAKED void FUN_080af200(EntityCBB0* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080af200.inc"); }

NAKED void FUN_080af2f4(EntityCBB0* p) { INCFUNC("asm/func/FUN_080af2f4.inc"); }

NAKED void FUN_080af334(EntityCBB0* p) { INCFUNC("asm/func/FUN_080af334.inc"); }

NAKED void FUN_080af374(unknown* p, s32 param_2) { INCFUNC("asm/func/FUN_080af374.inc"); }

NAKED void FUN_080af400(EntityCBB0* p) { INCFUNC("asm/func/FUN_080af400.inc"); }

s32 FUN_080af4a4(EntityCBB0* p, s32 idx, u32 state) {
  if (p->unk_6ac->generators[idx]->state == state) {
    return 1;
  }
  return 0;
}

void FUN_080af4d4(EntityCBB0* p, s32 idx, s32 state) { Generator_SetState(p->unk_6ac->generators[idx], state); }

u8 FUN_080af4f8(EntityCBB0* p) { return p->unk_6ac->unk_1f; }

u8 FUN_080af508(EntityCBB0* p) { return p->unk_6ac->unk_c10; }

void FUN_080af51c(EntityCBB0* p, s32 idx) { p->unk_6ac->generators[idx]->unk_e2 = 1; }

NAKED s32 FUN_080af53c(EntityCBB0* p) { INCFUNC("asm/func/FUN_080af53c.inc"); }

NAKED void FUN_080af5b8(EntityCBB0* p) { INCFUNC("asm/func/FUN_080af5b8.inc"); }

NAKED void FUN_080af6c4(EntityCBB0* p) { INCFUNC("asm/func/FUN_080af6c4.inc"); }

void FUN_080af890(EntityCBB0* p) { p->unk_68a = 0x10; }

NAKED void FUN_080af8a0(EntityCBB0* p) { INCFUNC("asm/func/FUN_080af8a0.inc"); }

NAKED void FUN_080af97c(EntityCBB0* p) { INCFUNC("asm/func/FUN_080af97c.inc"); }

NAKED void FUN_080afa20(EntityCBB0* p) { INCFUNC("asm/func/FUN_080afa20.inc"); }

NAKED void FUN_080afbd0(EntityCBB0* p) { INCFUNC("asm/func/FUN_080afbd0.inc"); }

NAKED void FUN_080afe18(EntityCBB0* p) { INCFUNC("asm/func/FUN_080afe18.inc"); }

NAKED void FUN_080affdc(EntityCBB0* p) { INCFUNC("asm/func/FUN_080affdc.inc"); }

NAKED void FUN_080b009c(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b009c.inc"); }

// unk_690 フレーム経ったら次へ進む
void FUN_080b01b4(EntityCBB0* p) {
  p->unk_67a++;

  if (p->unk_67a >= p->unk_690) {
    FUN_080af5b8(p);
    FUN_080af374(p, 3);
  }
}

NAKED void FUN_080b01ec(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b01ec.inc"); }

NAKED void FUN_080b02e0(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b02e0.inc"); }

NAKED void FUN_080b0398(EntityCBB0* p, s32 param_2) { INCFUNC("asm/func/FUN_080b0398.inc"); }

NAKED void FUN_080b05b0(EntityCBB0* p, s32 param_2) { INCFUNC("asm/func/FUN_080b05b0.inc"); }

NAKED void FUN_080b087c(EntityCBB0* p, s32 param_2) { INCFUNC("asm/func/FUN_080b087c.inc"); }

NAKED void FUN_080b09d4(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b09d4.inc"); }

NAKED void FUN_080b0ab4(unknown* param_1) { INCFUNC("asm/func/FUN_080b0ab4.inc"); }

NAKED void FUN_080b0aec(EntityCBB0* p, u32 param_2) { INCFUNC("asm/func/FUN_080b0aec.inc"); }

NAKED void FUN_080b0b7c(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b0b7c.inc"); }

NAKED void FUN_080b0bf4(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b0bf4.inc"); }

NAKED void FUN_080b0d28(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b0d28.inc"); }

void FUN_080b0e3c(EntityCBB0* p) {
  FUN_080b0b7c(p);
  FUN_080b0bf4(p);
  FUN_080b0d28(p);
}

void FUN_080b0e58(EntityCBB0* p) {
  p->unk_69c.x = 0xA0, p->unk_69c.y = 0xA0, p->unk_69c.z = 0xA0;
  p->unk_6a4.x = 0x40, p->unk_6a4.y = 0x20, p->unk_6a4.z = 0x40;
}

NAKED void FUN_080b0e98(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b0e98.inc"); }

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

s32 FUN_080b1078(EntityCBB0* p) {
  if (gImmortalCoffin != NULL && gPlayerPtr[0]->unk_1c == 1 && gPlayerPtr[0]->action == 6 && FUN_080b1038(&gImmortalCoffin->mover.pos, &p->pos_510, 70)) {
    return 1;
  }
  return 0;
}

s32 FUN_080b10c4(EntityCBB0* p) {
  s32 i;

  for (i = 0; i < p->unk_1e; i++) {
    if (p->generators[i]->state != 2) {
      return 0;
    }
  }
  return 1;
}

s32 FUN_080b10f8(EntityCBB0* p) {
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

// gImmortalCoffin が 800 以内にいなければ 1
s32 FUN_080b1148(EntityCBB0* p) {
  if (FUN_080b1038(&gImmortalCoffin->mover.pos, &p->pos_510, 800)) {
    return 0;
  }
  return 1;
}

void FUN_080b1174(EntityCBB0* p) {
  if (FUN_080b1078(p)) {
    FUN_0807bb3c(gPlayerPtr[0], NULL, -1, 0, 0);
    p->unk_c16 = 0;
    FUN_080ad1ec(p, 1);
  }
}

NAKED void FUN_080b11b4(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b11b4.inc"); }

void FUN_080b1404(EntityCBB0* p) {
  if (FUN_080b10c4(p)) {
    FUN_0807d118(gPlayerPtr[0]);
    FUN_080ad1ec(p, 3);
    FUN_080ad204(p, 0);
  }
}

NAKED void FUN_080b1434(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b1434.inc"); }

NAKED void FUN_080b14b8(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b14b8.inc"); }

NAKED void FUN_080b1574(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b1574.inc"); }

void FUN_080b165c(EntityCBB0* p) {
  p->unk_4fe++;
  if (p->unk_4fe == 30) {
    s32 i;

    for (i = 0; i < p->unk_1e; i++) {
      if (p->generators[i]->state == 4) {
        Generator_SetState(p->generators[i], 5);
      }
    }
    EntityCBB0_SetState(p, FUN_080adb5c);
    Sound_FadeOutBGM(4);
  } else if (p->unk_4fe == 90) {
    FUN_0823bca8(16);
    FUN_0807bc64(gPlayerPtr[0], 0);
  } else if (p->unk_4fe > 105) {
    if (gPlayerPtr[0]->action == 0) {
      FUN_0807d118(gPlayerPtr[0]);
      FUN_080ad1ec(p, 3);
      p->unk_1332 = 0;
      FUN_080ad204(p, 2);
    }
  }
}

void FUN_080b1718(EntityCBB0* p) {
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

void FUN_080b176c(EntityCBB0* p) {
  if (p->unk_4fe <= 29) {
    p->unk_4fe++;
  } else if (!p->unk_c12) {
    PlaySound_082406e0(0x1EA);
    gImmortalCoffin->state = 13;
    FUN_080ad1ec(p, 9);
  }
}

void FUN_080b17bc(EntityCBB0* p) {
  if (gImmortalCoffin->state == 12) {
    FUN_080af374(p->unk_c6c, 1);
    FUN_080ad1ec(p, 10);
  }
}

NAKED void FUN_080b17f4(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b17f4.inc"); }

void FUN_080b1888(EntityCBB0* p) {
  if (p->unk_12e4 == 0) {
    PlaySound_082406e0(0x1EB);
    FUN_08086b18(&p->pos_510);
    FUN_080ad1ec(p, 12);
    FUN_080ad204(p, 5);
  }
}

NAKED void FUN_080b18c4(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b18c4.inc"); }

NAKED void FUN_080b19c0(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b19c0.inc"); }

void FUN_080b1a84(EntityCBB0* p) {}

NAKED void FUN_080b1a88(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b1a88.inc"); }

NAKED void FUN_080b1b1c(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b1b1c.inc"); }

NAKED void FUN_080b1b74(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b1b74.inc"); }

NAKED void FUN_080b1d5c(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b1d5c.inc"); }

void FUN_080b1de8(EntityCBB0* p) {
  if (VM_SeekToNamedArg('p')) {
    p->unk_17a4 = VM_GetValue();
  } else {
    p->unk_17a4 = 0;
  }
}

NAKED void FUN_080b1e18(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b1e18.inc"); }

s32 FUN_080b2060(EntityCBB0* p) {
  s32 i;

  for (i = 0; i < p->unk_1e; i++) {
    if (p->generators[i]->state != 0) {
      return 0;
    }
  }
  return 1;
}

NAKED void FUN_080b2094(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b2094.inc"); }

void FUN_080b21d8(EntityCBB0* p) {
  u32 val = VM_SeekToNamedArg('m');

  if (val) {
    val = VM_GetValue();
  }
  p->unk_1a = val;
}

void FUN_080b21f4(void) {
  if (gEntityCBB0 != NULL) {
    gEntityCBB0->unk_c0f = 1;
    gEntityCBB0->unk_c11 = gEntityCBB0->unk_c10;
  }
}

NAKED void FUN_080b2224(void) { INCFUNC("asm/func/FUN_080b2224.inc"); }

void FUN_080b22e8(void) {
  if (gEntityCBB0 != NULL) {
    gEntityCBB0->unk_1333 = TRUE;
    gEntityCBB0->unk_1334 = 0;
  }
}

void FUN_080b2314(void) {
  if (gEntityCBB0 != NULL) {
    gEntityCBB0->unk_c12 = TRUE;
  }
}

void FUN_080b2334(void) {
  if (gEntityCBB0 != NULL) {
    gEntityCBB0->unk_c12 = FALSE;
  }
}

NAKED void FUN_080b2354(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b2354.inc"); }

void FUN_080b23fc(EntityCBB0* p) { MsgQueue_Unregister(&p->mq); }

void FUN_080b2410(EntityCBB0* p) { MsgQueue_Register(&p->mq, p->subroutineID, 9); }

s32 FUN_080b2428(void) {
  gEntityCBB0 = NULL;
  return 0;
}

void FUN_080b2434(EntityCBB0* p) {
  s32 val;

  if (p->unk_c0f == 0) {
    val = gStat->sunGauge;
  } else {
    val = p->unk_c11;
  }
  p->unk_c10 = val;
}

// state が 4 のジェネレーターの数
u32 FUN_080b2474(EntityCBB0* p) {
  s32 i;
  u32 count = 0;

  for (i = 0; i < p->unk_1e; i++) {
    if (p->generators[i]->state == 4) {
      count++;
    }
  }
  return count;
}

NAKED void FUN_080b24a4(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b24a4.inc"); }

NAKED void FUN_080b252c(EntityCBB0* p) { INCFUNC("asm/func/FUN_080b252c.inc"); }

NAKED s32 EntityCBB0_Update(EntityCBB0* p) { INCFUNC("asm/func/EntityCBB0_Update.inc"); }

NAKED s32 EntityCBB0_Destroy(EntityCBB0* p) { INCFUNC("asm/func/EntityCBB0_Destroy.inc"); }

NAKED s32 EntityCBB0_Init(EntityCBB0* p) { INCFUNC("asm/func/EntityCBB0_Init.inc"); }

EntityCBB0* EntityCBB0_Create(u32 subroutineID) {
  EntityCBB0* p;

  if (gEntityCBB0 != NULL) {
    return gEntityCBB0;
  }

  p = CreateEntity(ENTITY_UNK_9, sizeof(EntityCBB0));
  if (p != NULL) {
    SetEntityRoutine(p, EntityCBB0_Update, EntityCBB0_Destroy);
    p->subroutineID = subroutineID;
    if (EntityCBB0_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
