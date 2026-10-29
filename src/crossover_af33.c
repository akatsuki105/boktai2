#include "entity.h"
#include "global.h"
#include "sprite_main.h"
#include "text.h"

// 0x3C から 0xC 刻みで3件, _Init が各回 +4 に {100, 100, 0, 0} と +8 に u32 0 を入れる
typedef struct {
  u8 unk_00[4];  // 0x00, [1] が 0 以外なら FUN_0804e514 に渡す, FUN_0804fb04 が4バイトまとめて 0 にする
  u8 unk_04[4];  // 0x04, _Init が {100, 100, 0, 0} を入れる
  u32 unk_08;    // 0x08, _Init が 0 を入れる
} EntityAF33Slot;
static_assert(sizeof(EntityAF33Slot) == 12);

// クロスオーバーバトルに関係
typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_2
  u32 unk_18;               // 0x018, _Init が 0 を入れる
  u16 unk_1c;               // 0x01C, _Init が 0 を入れる
  u16 unk_1e;               // 0x01E, _Init が 0 を入れる
  u32 unk_20;               // 0x020, _Init が 0 を入れる
  u32 unk_24;               // 0x024, _Init が 0 を入れる
  u8 unk_28;                // 0x028, _Init が 0 を入れる, FUN_08050558 が 9 を入れる
  bool8 unk_29;             // 0x029, _Init が 1 を入れる
  u8 unk_2a[0x2D - 0x2A];   // 0x02A, _Init が 0x2B と 0x2C に 0 を入れる
  u8 unk_2d;                // 0x02D, _Init が 0 を入れる
  u8 unk_2e;                // 0x02E
  u8 unk_2f[0x32 - 0x2F];   // 0x02F, まだ未解析
  u8 unk_32;                // 0x032, _Init が 1 を入れる, FUN_0804fa04 が 0 でなければ減らす
  u8 unk_33;                // 0x033, _Init が 0、FUN_0804fb24 が 1 を入れる
  u8 unk_34;                // 0x034, FUN_0804fbf0 が 1 を入れる
  u8 unk_35[0x38 - 0x35];   // 0x035
  u8 unk_38[4];             // 0x038, _Init が 4バイト 0 クリアする
  EntityAF33Slot slots[3];  // 0x03C, _Init は先頭2件だけ埋める
  void* unk_60;             // 0x060, _Init が Entity08052250_Create() の戻り値を入れる
  void* unk_64;             // 0x064, _Init が Entity08052ffc_Create() の戻り値を入れる
  u32 count78;              // 0x068, unk_78 に積んだ '.w' の件数
  u32 count98;              // 0x06C, unk_98 に積んだ '.m' の件数
  u32 mask70;               // 0x070, unk_78 を配るときに使用済みスロットのビットを立てる
  u32 mask74;               // 0x074, unk_98 を配るときに使用済みスロットのビットを立てる
  u16 unk_78[16];           // 0x078, '.w' の値を最大16個
  u16 unk_98[16];           // 0x098, '.m' の値を最大16個
  u8* script;               // 0x0B8, '.s' の後の VM_GetPC_Proxy() の戻り値, NULL なら _Init が失敗する
  s32 windowID;             // 0x0BC, _Destroy が TextPanel_Destroy に渡す
  u32 unk_c0;               // 0x0C0, 読み手も書き手も見つかっていない
  u32 unk_c4;               // 0x0C4, '.e'
  u32 unk_c8;               // 0x0C8, _Init が 0 を入れる
  MainSpriteGfx iconGfx;    // 0x0CC, SPRITE_INVENTORY_ICONS
  MainSprite sprites[2];    // 0x0EC, _Destroy が MainSprite_Remove に渡す2枚
  u16 unk_1ac;              // 0x1AC, '.M=11'
  u16 unk_1ae[4];           // 0x1AE, '.p'
  u8 unk_1b6[6];            // 0x1B6, 読み手も書き手も見つかっていない
} EntityAF33;
static_assert(sizeof(EntityAF33) == 444);

IWRAM_DATA EntityAF33* gEntityAF33 = NULL;  // 0x030000F0
IWRAM_DATA u8 u8_030000f4[0x118 - 0x0F4] = {};

s32 FUN_0804e514(void* param_1);  // src/entity_0804e2c0.c
void FUN_0804e5e8(void);          // src/entity_0804e2c0.c

void Entity723E_SetState(unknown* p);
void Entity723E_ConsumeStateEntered(unknown* p);

EntityAF33* FUN_0804f820(void) { return gEntityAF33; }

NAKED void FUN_0804f82c(EntityAF33* p) { INCFUNC("asm/func/FUN_0804f82c.inc"); }

NAKED void FUN_0804f8ec(EntityAF33* p) { INCFUNC("asm/func/FUN_0804f8ec.inc"); }

void FUN_0804f950(void) {
  EntityAF33* p = FUN_0804f820();

  if (p != NULL && p->slots[2].unk_00[1] != 0) {
    FUN_0804e514(&p->slots[2]);
  }
}

void FUN_0804f970(void) { FUN_0804f820(); }

NAKED void FUN_0804f97c(EntityAF33* p) { INCFUNC("asm/func/FUN_0804f97c.inc"); }

s32 FUN_0804fa04(EntityAF33* p) {
  EntityAF33Slot* a = &p->slots[0];
  EntityAF33Slot* b = &p->slots[1];

  if (a->unk_04[2] || b->unk_04[2] || *(u32*)a->unk_00 != 0 || *(u32*)b->unk_00 != 0) {
    if (a->unk_04[2] && p->unk_32 != 0) {
      p->unk_32--;
    }
    return 1;
  }

  return 0;
}

// 3件目の枠に種別と本体を詰めて送信を頼む, 送れなければ保留フラグを立てて -1
s32 FUN_0804fa44(EntityAF33* p, u32 kind, u32* src, s32 wordCount) {
  EntityAF33Slot* slot = &p->slots[2];
  s32 result;

  if (p->unk_2a[0] != 0 && slot->unk_00[1] != 0) {
    return -1;
  }

  slot->unk_00[1] = kind;
  if (wordCount > 0) {
    u32* dst = (u32*)slot->unk_04;

    do {
      *dst++ = *src++;
      wordCount--;
    } while (wordCount != 0);
  }

  result = FUN_0804e514((u8*)slot);
  if (result < 0 && slot->unk_00[1] != 0) {
    p->unk_2a[0] = 1;
  }
  return result;
}

NAKED u32 FUN_0804fa94(EntityAF33* p) { INCFUNC("asm/func/FUN_0804fa94.inc"); }

void FUN_0804fb04(EntityAF33* p, s32 idx) {
  EntityAF33Slot* slot = &p->slots[idx];
  s32 i;

  slot->unk_04[2] = 0;
  for (i = 0; i < 4; i++) {
    slot->unk_00[i] = 0;
  }
}

void FUN_0804fb24(void) {
  EntityAF33* p = FUN_0804f820();

  if (p != NULL) {
    p->unk_33 = 1;
  }
}

void FUN_0804fb3c(EntityAF33* p) {
  EntityAF33Slot* slot = &p->slots[0];

  if (p->unk_2d != 0) {
    slot->unk_04[3] = 2;
  } else if (p->unk_2e != 0) {
    slot->unk_04[3] = 1;
  } else {
    slot->unk_04[3] = 0;
  }

  slot->unk_08 = 0x2D0 - p->unk_1c;
}

NAKED void FUN_0804fb6c(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_0804fb6c.inc"); }

void FUN_0804fbd0(EntityAF33* p) {
  if (p->unk_60 != NULL) {
    Entity723E_SetState(p->unk_60);
  }
}

void FUN_0804fbe0(EntityAF33* p) {
  if (p->unk_60 != NULL) {
    Entity723E_ConsumeStateEntered(p->unk_60);
  }
}

void FUN_0804fbf0(void) {
  EntityAF33* p = FUN_0804f820();

  if (p != NULL) {
    p->unk_34 = 1;
  }
}

s32 FUN_08050d64(void);
s32 FUN_08050d7c(void);

NAKED void FUN_0804fc08(EntityAF33* p) { INCFUNC("asm/func/FUN_0804fc08.inc"); }

NAKED void FUN_0804fd3c(EntityAF33* p) { INCFUNC("asm/func/FUN_0804fd3c.inc"); }

// 装備中の武器が登録されていればそのスロットの使用済みビットを外す
// 間の空ループは原典のまま, agbcc は -O2 でも体が無いループを消さない
void FUN_0804fe24(EntityAF33* p) {
  s32 slot = REGISTERED_WEAPON(gStat->equippedWeaponIdx);
  s32 i;

  if (slot < 0) {
    return;
  }

  for (i = 0; i < 4; i++) {
  }

  if (GetWeaponID(slot) != WEAPON_NONE) {
    p->mask70 &= ~(1 << slot);
  }
}

// 装備中の魔法と同じIDの枠を使用済みビットから外す
// 残差1命令, 原典は gStat + idx*2 を先に作ってから +0x68 するが agbcc は +0x68 を先に足す
// Tier A-B 試済: 添字をローカルに退避 / 配列の先頭をローカルに退避
NON_MATCH void FUN_0804fe68(EntityAF33* p) {
#ifdef NONMATCHING_C
  s16 id = gStat->registeredMagic[gStat->equippedMagicIdx];
  s32 i;

  if (id < 0) {
    return;
  }

  for (i = 0; i < 16; i++) {
    if (p->unk_98[i] == id) {
      p->mask74 &= ~(1 << i);
    }
  }
#else
  INCFUNC("asm/func/FUN_0804fe68.inc");
#endif
}

void FUN_0803cb24(void);
void FUN_0803cb4c(u32 val);
void FUN_0803cb6c(u32 val);
void FUN_0803cbb4(u32 val);
void FUN_0803cc54(u32 val);

// 溜めてあった4つの値をそれぞれの受け取り手に流してから捨てる
void FUN_0804feb0(EntityAF33* p) {
  s32 i;

  FUN_0803cb24();

  for (i = 0; i < 4; i++) {
  }

  if (p->unk_38[0] != 0) {
    FUN_0803cb4c(p->unk_38[0]);
    p->unk_38[0] = 0;
  }

  if (p->unk_38[1] != 0) {
    FUN_0803cb6c(p->unk_38[1]);
    p->unk_38[1] = 0;
  }

  if (p->unk_38[2] != 0) {
    FUN_0803cbb4(p->unk_38[2]);
    p->unk_38[2] = 0;
  }

  if (p->unk_38[3] != 0) {
    FUN_0803cc54(p->unk_38[3]);
    p->unk_38[3] = 0;
  }
}

NAKED void FUN_0804ff10(EntityAF33* p) { INCFUNC("asm/func/FUN_0804ff10.inc"); }

NAKED void FUN_0804ffa8(EntityAF33* p) { INCFUNC("asm/func/FUN_0804ffa8.inc"); }

NAKED void FUN_08050070(EntityAF33* p) { INCFUNC("asm/func/FUN_08050070.inc"); }

NAKED void FUN_0805010c(EntityAF33* p) { INCFUNC("asm/func/FUN_0805010c.inc"); }

// クロスオーバーバトルで、 自分（ロックマン) と 相手（シェードマン) のアイコンをHPに応じて切り替える
void FUN_080501c8(EntityAF33* p) {
  s32 n = FUN_08050d64();
  s32 idx = 0;

  if (n <= 60) {
    idx = 2;
    if (n > 25) {
      idx = 1;
    }
  }
  MainSprite_SetPose(&p->sprites[0], &p->iconGfx, ICON_MEGAMAN(idx), PLAYMODE_PAUSE);

  n = FUN_08050d7c();
  idx = 0;
  if (n <= 60) {
    idx = 2;
    if (n > 25) {
      idx = 1;
    }
  }
  MainSprite_SetPose(&p->sprites[1], &p->iconGfx, ICON_SHADEMAN(idx), PLAYMODE_PAUSE);
}

NAKED void FUN_08050218(EntityAF33* p) { INCFUNC("asm/func/FUN_08050218.inc"); }

NAKED void FUN_080502a8(EntityAF33* p) { INCFUNC("asm/func/FUN_080502a8.inc"); }

NAKED void FUN_0805043c(EntityAF33* p) { INCFUNC("asm/func/FUN_0805043c.inc"); }

NAKED void FUN_080504e0(EntityAF33* p) { INCFUNC("asm/func/FUN_080504e0.inc"); }

// 120フレームごとに unk_28 を 9 にして FUN_0804fbe0 を呼ぶ
// 残差1命令, 原典は定数 9 を unk_28 のアドレス計算より前に作るが agbcc はアドレスを先に作る (命令列は 29 対 29)
NON_MATCH void FUN_08050558(EntityAF33* p) {
#ifdef NONMATCHING_C
  if (p->unk_29) {
    p->unk_29 = FALSE;
  }

  if (p->unk_24 > 0x77) {
    FUN_0804e5e8();
    p->unk_28 = 9;
    p->unk_29 = TRUE;
    p->unk_24 = 0;
    FUN_0804fbe0(p);
  } else {
    p->unk_24++;
  }
#else
  INCFUNC("asm/func/FUN_08050558.inc");
#endif
}

NAKED void FUN_08050598(EntityAF33* p) { INCFUNC("asm/func/FUN_08050598.inc"); }

NAKED void FUN_08050674(EntityAF33* p) { INCFUNC("asm/func/FUN_08050674.inc"); }

NAKED void FUN_08050754(EntityAF33* p) { INCFUNC("asm/func/FUN_08050754.inc"); }

void (*const PTR_ARRAY_085ab6a4[12])(EntityAF33*) = {
    FUN_0804ff10,
    FUN_0804ffa8,
    FUN_08050070,
    FUN_0805010c,
    FUN_08050218,
    FUN_080502a8,
    FUN_0805043c,
    FUN_080504e0,
    FUN_08050558,
    FUN_08050598,
    FUN_08050674,
    FUN_08050754,
};  // 0x085AB6A4

NAKED s32 EntityAF33_Update(EntityAF33* p) { INCFUNC("asm/func/EntityAF33_Update.inc"); }

s32 EntityAF33_Destroy(EntityAF33* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }

  TextPanel_Destroy(p->windowID);
  gEntityAF33 = NULL;
  return 0;
}

NAKED s32 EntityAF33_Init(EntityAF33* p) { INCFUNC("asm/func/EntityAF33_Init.inc"); }

EntityAF33* EntityAF33_Create(void) {
  EntityAF33* p = CreateEntity(ENTITY_UNK_2, sizeof(EntityAF33));
  if (p != NULL) {
    SetEntityRoutine(p, EntityAF33_Update, EntityAF33_Destroy);
    if (EntityAF33_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
