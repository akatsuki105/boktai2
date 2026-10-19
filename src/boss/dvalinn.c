#include "boss.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"
#include "sprite_main.h"

// ボス戦前の人型のイベント時もこれ使う
typedef struct Dvalinn {
  Entity e;                                 // 0x000, ENTITY_UNK_8
  u8 unk_18[0x8C - 0x18];                   // 0x018, まだ未解析
  u32 unk_8c;                               // 0x08C
  u8 unk_90[0xA2 - 0x90];                   // 0x090, まだ未解析
  u8 state;                                 // 0x0A2, PTR_ARRAY_085ae768 の添字, FUN_081ff740 がこれで引いて updateCallback に入れる
  u8 unk_a3;                                // 0x0A3
  u8 unk_a4;                                // 0x0A4
  u8 unk_a5;                                // 0x0A5
  u8 unk_a6;                                // 0x0A6
  u8 unk_a7;                                // 0x0A7
  u8 unk_a8;                                // 0x0A8
  u8 unk_a9;                                // 0x0A9
  u8 unk_aa[0xBC - 0xAA];                   // 0x0AA, まだ未解析
  u32 unk_bc;                               // 0x0BC
  u8 unk_c0[0xF8 - 0xC0];                   // 0x0C0, まだ未解析
  void (*updateCallback)(struct Dvalinn*);  // 0x0F8
  u8 unk_fc[0x15C - 0xFC];                  // 0x0FC, まだ未解析
  HitboxData hitbox;                        // 0x15C
  u8 unk_1ac[0x23C - 0x1AC];                // 0x1AC, まだ未解析
  MainSprite sprites[2];                    // 0x23C
  u8 unk_2fc[0x31C - 0x2FC];                // 0x2FC, まだ未解析
  MainSprite sprite_31c;                    // 0x31C
  u8 unk_37c[0x398 - 0x37C];                // 0x37C, まだ未解析
  AuxSprite auxSprite;                      // 0x398
  u8 unk_3c4[2120 - 0x3C4];                 // 0x3C4, まだ未解析
} Dvalinn;
static_assert(sizeof(Dvalinn) == 2120);

extern Dvalinn* gDvalinn;  // 0x03002C80

const u16 u16_ARRAY_085ae5fc[8] = {1536, 1536, 1536, 2304, 2304, 2304, 2304, 1536};  // 0x085AE5FC

void FUN_081fc86c(Dvalinn*);
void FUN_081ff734(Dvalinn*);
void FUN_081ff740(Dvalinn*);
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
void FUN_081fca00(Dvalinn*);
void FUN_081fcb1c(Dvalinn*);
void FUN_081fcf54(Dvalinn*);
void FUN_081fcfb4(Dvalinn*);
void FUN_081fd000(Dvalinn*);
void FUN_081fd20c(Dvalinn*);
void FUN_081fd7fc(Dvalinn*);
void FUN_081fdd18(Dvalinn*);
void FUN_081fe2e0(Dvalinn*);
void FUN_081fea80(Dvalinn*);
void FUN_081febb8(Dvalinn*);
void FUN_081febe4(Dvalinn*);
void FUN_081fec60(Dvalinn*);
void FUN_081fed08(Dvalinn*);
void FUN_081fef30(Dvalinn*);
void FUN_081ff148(Dvalinn*);
void FUN_081ff34c(Dvalinn*);
void FUN_081ff5cc(Dvalinn*);
void FUN_081ff658(Dvalinn*);

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

// 推測: {u32, s16, s16} の33組
// clang-format off
const u8 u8_ARRAY_085ae660[264] = {
    0x02, 0x00, 0x00, 0x00, 0xFD, 0xFF, 0x13, 0x00, 0x03, 0x00, 0x00, 0x00, 0xFA, 0xFF, 0x10, 0x00,
    0x04, 0x00, 0x00, 0x00, 0xF2, 0xFF, 0x04, 0x00, 0x06, 0x00, 0x00, 0x00, 0xF2, 0xFF, 0xEC, 0xFF,
    0x06, 0x00, 0x00, 0x00, 0xFA, 0xFF, 0xCC, 0xFF, 0x04, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xBA, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0xBA, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x07, 0x00, 0xBA, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0x0C, 0x00, 0xBE, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x14, 0x00, 0xB5, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0x1D, 0x00, 0xCB, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x21, 0x00, 0xD0, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0x21, 0x00, 0xD8, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x1F, 0x00, 0xDD, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0x13, 0x00, 0xDF, 0xFF, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00, 0xDC, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0xDA, 0xFF, 0x04, 0x00, 0x00, 0x00, 0xF6, 0xFF, 0xD6, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0xF3, 0xFF, 0xD1, 0xFF, 0x04, 0x00, 0x00, 0x00, 0xEE, 0xFF, 0xCB, 0xFF,
    0x04, 0x00, 0x00, 0x00, 0xF3, 0xFF, 0xC0, 0xFF, 0x02, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x15, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x22, 0x00, 0x29, 0x00, 0x01, 0x00, 0x00, 0x00, 0x12, 0x00, 0x31, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x06, 0x00, 0x2D, 0x00, 0x01, 0x00, 0x00, 0x00, 0xFA, 0xFF, 0x29, 0x00,
    0x01, 0x00, 0x00, 0x00, 0xF2, 0xFF, 0x1C, 0x00, 0x02, 0x00, 0x00, 0x00, 0xEC, 0xFF, 0x0C, 0x00,
    0x02, 0x00, 0x00, 0x00, 0xE5, 0xFF, 0xF9, 0xFF, 0x02, 0x00, 0x00, 0x00, 0xE2, 0xFF, 0xE5, 0xFF,
    0x02, 0x00, 0x00, 0x00, 0xE2, 0xFF, 0xD5, 0xFF, 0x02, 0x00, 0x00, 0x00, 0xEE, 0xFF, 0xC6, 0xFF,
    0x02, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xC1, 0xFF,
};  // 0x085AE660
// clang-format on

// FUN_081ff740 が Dvalinn + 0xA2 で引いて 0xF8 のフィールドに入れる
// clang-format off
void (*const PTR_ARRAY_085ae768[20])(Dvalinn*) = {
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

static inline bool32 TestFlag03002bc0(u32 flags) { return (u32_03002bc0[0] & flags) != 0; }

INCASM("asm/dvalinn.inc");

s32 Dvalinn_Update(Dvalinn* p) {
  if (!TestFlag03002bc0(FLAG03002BC0_UNK_2)) {
    FUN_08022e20((Boss*)p);
    FUN_081ffd9c(p);
    FUN_081fc86c(p);
    FUN_081ff740(p);
    FUN_081ff734(p);
    FUN_08022ec0((Boss*)p);
    FUN_081ffdb0(p);
  }
  return 0;
}

s32 Dvalinn_Destroy(Dvalinn* p) {
  Hitbox_Unregister(&p->hitbox);
  MainSprite_Remove(&p->sprites[0]);
  FUN_08022b04((Boss*)p);
  MainSprite_Remove(&p->sprites[1]);
  MainSprite_Remove(&p->sprite_31c);
  AuxSprite_Remove(&p->auxSprite);
  return 0;
}

NAKED s32 Dvalinn_Init(Dvalinn* p, u32 id) { INCFUNC("asm/func/Dvalinn_Init.inc"); }

Dvalinn* Dvalinn_Create(u32 id) {
  Dvalinn* p = FUN_08022a2c(BOSS_DVALINN);
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
// 残差1命令 (30 対 31), 原典は定数 3 を r4 に置いて state と unk_a3 で使い回すが, こちらは2回作り直す
// u8/s32 のローカルに退避する形は試済
NON_MATCH void FUN_08200a6c(void) {
#ifdef NONMATCHING_C
  Dvalinn* p = gDvalinn;

  p->state = 3;
  p->unk_a4 = 0;
  p->unk_a5 = 0;
  p->unk_a6 = 0;
  p->unk_bc = 0;
  p->unk_a8 = 1;
  p->unk_a3 = 3;
  p->updateCallback = FUN_081fcf54;
  p->unk_8c = 0;
  p->unk_a9 = 1;
#else
  INCFUNC("asm/func/FUN_08200a6c.inc");
#endif
}
