#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"

// '.I' が並べる1件, count 個ぶんだけ3つの配列が埋まる
typedef struct {
  s8 id;          // 0x00, -1 なら打ち切り
  u8 count;       // 0x01, 続く3つの配列の要素数
  s16 values[5];  // 0x02
  u32 unk_c[5];   // 0x0C
  u32 unk_20[5];  // 0x20
} EntityA288Entry;
static_assert(sizeof(EntityA288Entry) == 52);

typedef struct EntityA288 {
  Entity e;                                    // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx;                           // 0x0018, SPRITE_42E2
  Tilemaps* tilemap;                           // 0x0038, TILEMAP_33B2
  rgb555* pltt;                                // 0x003C, BGP_E9C3
  s32 kind;                                    // 0x0040, '.t', 初期 state を選ぶ
  u32 flags;                                   // 0x0044, bit0 / bit1 が立っている間は timer1 / timer2 を止める
  u32 unk_48;                                  // 0x0048, '.f'
  u32 unk_4c;                                  // 0x004C, '.l'
  u32 unk_50;                                  // 0x0050, '.e'
  s32 state;                                   // 0x0054, 0x085AFF84 の関数表の添字
  s32 timer1;                                  // 0x0058, flags bit0 が落ちている間 _Update が 1 足す
  u32 unk_5c;                                  // 0x005C, EntityA288_SetState が 0 に戻す
  s32 timer2;                                  // 0x0060, flags bit1 が落ちている間 _Update が 1 足す
  s32 unk_64;                                  // 0x0064, _Init が -1 を入れる
  u32 unk_68;                                  // 0x0068, _Init が 0 を入れる
  u8 unk_6c[0x78 - 0x6C];                      // 0x006C, まだ未解析
  MainSpriteGfx gfx_78;                        // 0x0078
  MainSprite sprite_98;                        // 0x0098
  Tilemaps* tilemap2;                          // 0x00F8, TILEMAP_A413
  rgb555* bgp2;                                // 0x00FC, BGP_EFDA[208]
  s32 windowID;                                // 0x0100
  u8 unk_104[0x106 - 0x104];                   // 0x0104, まだ未解析
  u16 unk_106;                                 // 0x0106, +4 したものを sprite_98 のアニメ番号にする
  u8 unk_108[0x10C - 0x108];                   // 0x0108, まだ未解析
  MainSprite sprites_10c[2];                   // 0x010C
  u8* unk_1cc;                                 // 0x01CC, '.s'
  u8 unk_1d0[0x1D8 - 0x1D0];                   // 0x01D0, まだ未解析
  MainSprite sprites_1d8[12];                  // 0x01D8
  MainSprite sprite_658;                       // 0x0658
  u8 unk_6b8[0x6C0 - 0x6B8];                   // 0x06B8, まだ未解析
  MainSprite sprite_6c0;                       // 0x06C0
  MainSprite sprite_720;                       // 0x0720
  EntityA288Entry entries[30];                 // 0x0780, '.I' から読む
  s32 windowIDs[5];                            // 0x0D98
  u8* unk_dac;                                 // 0x0DAC, '.a'
  u8* unk_db0;                                 // 0x0DB0, '.I' の先頭
  u8 unk_db4[2];                               // 0x0DB4, まだ未解析
  s16 entryCount;                              // 0x0DB6, 読めた entries の個数 - 1
  u8 unk_db8[0xDBA - 0xDB8];                   // 0x0DB8, まだ未解析
  s16 unk_dba;                                 // 0x0DBA, 16倍して sprite_720 の縦位置にする
  MainSprite sprites_dbc[2];                   // 0x0DBC
  s32 unk_e7c;                                 // 0x0E7C, 24倍して sprites_dbc[0] の縦位置にする
  u8* unk_e80;                                 // 0x0E80, '.X'
  u8 unk_e84[4];                               // 0x0E84, まだ未解析
  u32 unk_e88;                                 // 0x0E88, '.E'
  u8 unk_e8c[0x12AC - 0xE8C];                  // 0x0E8C, まだ未解析
  u8* unk_12ac;                                // 0x12AC, '.b'
  u8 unk_12b0[0x1650 - 0x12B0];                // 0x12B0, まだ未解析
  u8* unk_1650;                                // 0x1650, '.g'
  u8* unk_1654;                                // 0x1654, '.T'
  u8* unk_1658;                                // 0x1658, '.A'
  u16 unk_165c;                                // 0x165C, gStat->unk_93a が 0 なら 1, そうでなければ 0
  u16 unk_165e;                                // 0x165E, FUN_08218e4c が 0 を入れる
  u8 unk_1660[0x166C - 0x1660];                // 0x1660, まだ未解析
  MainSprite sprites_166c[3];                  // 0x166C
  u8* unk_178c;                                // 0x178C, '.p' の PC
  u8* unk_1790;                                // 0x1790, '.S'
  u8* unk_1794;                                // 0x1794, '.P' の PC
  u8* unk_1798;                                // 0x1798, '.N' の PC
  u8* unk_179c;                                // 0x179C, '.H'
  u8* unk_17a0;                                // 0x17A0, '.K'
  u8 unk_17a4[0x1FE8 - 0x17A4];                // 0x17A4, まだ未解析
  void (*updateCallback)(struct EntityA288*);  // 0x1FE8
} EntityA288;
static_assert(sizeof(EntityA288) == 8172);

// clang-format off
const SoundID16 u16_ARRAY_085afa30[95] = {
    0xA3, 0xA7, 0xA4, 0xB3, 0x38, 0x12, 0x3E, 0x39, 0x1,  0x13, 0xA5,   0xD,
    0xC,  0x3B, 0x98, 0xF,  0x36, 0x2,  0x9C, 0x42, 0x9A, 0xA0, 0xA1,   0xA2,
    0x14, 0x44, 0x15, 0x16, 0x17, 0x45, 0x18, 0x46, 0x41, 0x96, 0x97,   0x9,
    0x3,  0x4,  0xA,  0x4A, 0xAA, 0xA9, 0x19, 0x1A, 0xB2, 0x47, 0x1B,   0x1C,
    0x3C, 0x4C, 0x51, 0x99, 0x1D, 0x4D, 0x20, 0x1E, 0x21, 0x1F, 0x50,   0x9B,
    0x52, 0x9F, 0x54, 0x9D, 0x10, 0xE,  0x22, 0xB5, 0x23, 0x40, 0x24,   0x27,
    0x25, 0x53, 0x29, 0x2A, 0x3D, 0x30, 0x11, 0x48, 0x2B, 0x2C, 0x2D,   0x2E,
    0x2F, 0x9E, 0x58, 0x5A, 0xA6, 0xA8, 0xB0, 0xB1, 0xB4, 0xAD, 0xFFFF,
};  // 0x085afa30
// clang-format on

// clang-format off
const SoundID16 u16_ARRAY_085afaee[482] = {
    0xE0,  0xDF,   0xDC,  0xDD,  0xDE,  0x2AE, 0x12B, 0x12C, 0x12D, 0x19A,
    0x192, 0x296,  0x294, 0x2A5, 0x10A, 0x10B, 0x10C, 0x38A, 0x10D, 0x10E,
    0x382, 0x118,  0x119, 0x107, 0x21C, 0x167, 0xE1,  0xE3,  0xE3,  0xE2,
    0x23A, 0x23B,  0x23C, 0x23D, 0x23E, 0x28B, 0x275, 0x276, 0xC9,  0xCA,
    0x28D, 0x28E,  0x162, 0x163, 0x193, 0x194, 0xC7,  0xC8,  0x335, 0xD0,
    0xDB,  0xEC,   0xEB,  0xCB,  0x38C, 0x38B, 0x38F, 0x38D, 0x390, 0x38E,
    0x391, 0xCD,   0xD5,  0x1F7, 0x1F8, 0x1F9, 0x1A9, 0x1AA, 0x393, 0x397,
    0x398, 0x399,  0x39A, 0x39B, 0x39C, 0x39E, 0x3A0, 0x3A1, 0x1FA, 0x1FB,
    0xD8,  0x124,  0x12E, 0x165, 0xE6,  0xD1,  0x2A8, 0x133, 0x134, 0x191,
    0x138, 0x1B1,  0x1EC, 0x1ED, 0xDA,  0xD2,  0xD3,  0x2AA, 0x180, 0x181,
    0x182, 0x1EE,  0x336, 0x27D, 0x27E, 0x27F, 0x284, 0x285, 0x259, 0x1AB,
    0x1AC, 0x1AE,  0x1AF, 0x1B0, 0x27C, 0x11E, 0x11F, 0x25A, 0x25B, 0x25C,
    0x327, 0x201,  0x202, 0x203, 0x29F, 0x204, 0x239, 0x298, 0x39D, 0x1FD,
    0x1FE, 0x20D,  0x20F, 0x25D, 0x20E, 0x395, 0x21D, 0x329, 0x328, 0x21E,
    0x31F, 0x320,  0x321, 0x322, 0x323, 0x13E, 0x211, 0x13C, 0x3A7, 0x3A8,
    0x3A9, 0x3AA,  0x3AB, 0x3AC, 0x3AD, 0x3AE, 0x3B0, 0x3B1, 0x3B2, 0x3B3,
    0x3A3, 0x3A4,  0x3A5, 0x3A2, 0x3BF, 0x3C0, 0x3C1, 0x3C2, 0x3C3, 0x3C4,
    0x3C9, 0x3C6,  0x3C7, 0x3C8, 0x3C5, 0x3CB, 0x3CC, 0x3CA, 0x19C, 0x3D5,
    0x3D6, 0x3D7,  0x19B, 0x3D9, 0x3DA, 0x3DB, 0x3DC, 0x3E2, 0x3E3, 0x1A5,
    0x3E4, 0x3E6,  0x19D, 0x1A2, 0x1A3, 0x3DE, 0x3DF, 0x3E0, 0x3E1, 0x1B4,
    0x3E5, 0x3E7,  0x19E, 0x1A4, 0xD4,  0xED,  0xEE,  0xD7,  0xE5,  0xD6,
    0xF2,  0xEF,   0xF0,  0xF1,  0x12A, 0x29D, 0x2AD, 0xE4,  0xEA,  0x32D,
    0x108, 0xE8,   0xF6,  0xF7,  0x109, 0xF8,  0xFD,  0xFE,  0xFF,  0x100,
    0x101, 0x102,  0x103, 0x104, 0x121, 0x166, 0x195, 0x112, 0x113, 0x114,
    0x115, 0x169,  0x16A, 0x16B, 0x16C, 0x16D, 0x16E, 0x16F, 0x170, 0x18F,
    0x190, 0x1E2,  0x185, 0x186, 0x187, 0x188, 0x189, 0x18A, 0x18B, 0x18D,
    0x18E, 0x1B2,  0x1B3, 0x271, 0x272, 0x1D7, 0x1D8, 0x1D9, 0x1DC, 0x1DD,
    0x1DE, 0x1DB,  0x1DF, 0x1E0, 0x1E1, 0x1D6, 0x1C7, 0x1C8, 0x1C9, 0x1CA,
    0x1CB, 0x1CD,  0x1CE, 0x1CF, 0x1D0, 0x1D1, 0x1D4, 0x1D5, 0x1E3, 0x1E4,
    0x1E5, 0x1FF,  0x260, 0xF9,  0xFA,  0x126, 0x197, 0x340, 0x33F, 0x7,
    0xFB,  0xFC,   0xF5,  0xF3,  0xF4,  0x129, 0x1EA, 0x1EB, 0x10F, 0x110,
    0x111, 0x123,  0x183, 0x26F, 0x29C, 0x2A7, 0x2B7, 0x122, 0x11D, 0x2B8,
    0x291, 0x292,  0x293, 0x11A, 0x11B, 0x11C, 0xCE,  0xCF,  0x28F, 0x184,
    0x142, 0x143,  0x146, 0x151, 0x15B, 0x150, 0x14A, 0x14E, 0x14F, 0x136,
    0x15C, 0x149,  0x267, 0x214, 0x215, 0x216, 0x217, 0x218, 0x219, 0x21A,
    0x21B, 0x155,  0x152, 0x153, 0x154, 0x140, 0x141, 0x153, 0x14C, 0x14D,
    0x172, 0x2B3,  0x1A8, 0x326, 0x286, 0x213, 0x222, 0x158, 0x159, 0x261,
    0x262, 0x263,  0x289, 0x28A, 0x288, 0x282, 0x266, 0x21F, 0x220, 0x19F,
    0x1A0, 0x237,  0x2A9, 0x223, 0x15E, 0x198, 0x199, 0x15F, 0x160, 0x1E7,
    0x32F, 0x264,  0x265, 0x281, 0x1C5, 0x1C3, 0x1C6, 0x1C4, 0x3B6, 0x3B7,
    0x3C3, 0x3B8,  0x3BE, 0x3BA, 0x3BB, 0x3BD, 0x346, 0x347, 0x348, 0x349,
    0x34A, 0x34B,  0x34C, 0x34E, 0x351, 0x352, 0x353, 0x354, 0x33B, 0x343,
    0x32C, 0x345,  0x332, 0x333, 0x33C, 0x70,  0x3CD, 0x3CE, 0x3CF, 0x3D0,
    0x3D1, 0x3D2,  0x3D3, 0x147, 0x175, 0x177, 0x178, 0x179, 0x17A, 0x17E,
    0x1B8, 0x1B9,  0x1BA, 0x1BB, 0x1BC, 0x22B, 0x71,  0x1BD, 0x224, 0x225,
    0x226, 0x227,  0x228, 0x229, 0x22A, 0x22B, 0x22C, 0x22D, 0x22E, 0x22F,
    0x230, 0x231,  0x234, 0x232, 0x233, 0x6E,  0x325, 0x6F,  0x372, 0x373,
    0x1FC, 0x363,  0x364, 0x65,  0x83,  0x6D,  0x67,  0x68,  0x69,  0x6A,
    0x84,  0xFFFF,
};  // 0x085afaee
// clang-format on

// clang-format off
const SoundID16 u16_ARRAY_085afeb2[99] = {
    0x2BC, 0x2C4, 0x2C5, 0x2C6, 0x2C7, 0x128, 0x308, 0xE7,  0x305,  0x240,
    0x246, 0x306, 0x303, 0x307, 0x309, 0x2BB, 0x2C8, 0x2C9, 0x2CA,  0x2CB,
    0x2E4, 0x2E6, 0x2E7, 0x2E5, 0x2E8, 0x2E9, 0x2ED, 0x2EA, 0x36A,  0x36B,
    0x2EB, 0x120, 0x15D, 0x2F9, 0x2FA, 0x2C2, 0x2C3, 0x316, 0x319,  0x317,
    0x2E3, 0x2E2, 0x2F2, 0x2F3, 0x2D8, 0x2D9, 0x2DA, 0x2DB, 0x2D0,  0x2D1,
    0x2D2, 0x2D3, 0x2D4, 0x2D5, 0x2D6, 0x2D7, 0x2F4, 0x2F5, 0x2DD,  0x2DE,
    0x2DF, 0x2E0, 0x2E1, 0x2F6, 0x2C0, 0x2C1, 0x2BD, 0x24B, 0x252,  0x356,
    0x357, 0x358, 0x359, 0x355, 0x35A, 0x35B, 0x35C, 0x34F, 0x350,  0x2CF,
    0x2CC, 0x2CD, 0x2CE, 0x241, 0x247, 0x254, 0x24E, 0x255, 0x30A,  0x30B,
    0x30C, 0x30E, 0x30F, 0x30D, 0x243, 0x311, 0x26A, 0x26B, 0xFFFF,
};  // 0x085afeb2
// clang-format on

const u8 gStringDjango_085aff78[] = _("ジャンゴ");

static inline void EntityA288_SetFlags(EntityA288* p, u32 bits) { p->flags |= bits; }

void FUN_08213880(EntityA288* p) { p->tilemap2 = GetFile(DIR_TILE_MAP, TILEMAP_A413); }

void EntityA288_LoadBgPltt(EntityA288* p) {
  p->bgp2 = &GetBgPlttFile(BGP_EFDA)->body[208];
  CpuCopy32(p->bgp2, &gBgPlttBuffer[208], 48 * sizeof(rgb555));
}

NAKED void FUN_082138d4(EntityA288* p) { INCFUNC("asm/func/FUN_082138d4.inc"); }

void FUN_08213960(EntityA288* p) {
  MainSprite_Remove(&p->sprite_98);
  TextPanel_Destroy(p->windowID);
}

// 残差1命令, 原典は gfx_78 のアドレスを callee-saved に残して p を使い捨てるが agbcc は逆に割り当てる, MainSpriteGfx* ローカルは試済
NON_MATCH void FUN_0821397c(EntityA288* p) {
#ifdef NONMATCHING_C
  MainSprite_SetAnim(&p->sprite_98, &p->gfx_78, p->unk_106 + 4, 1, 4);
  p->sprite_98.flags &= ~SPRFLAG_HIDDEN;
#else
  INCFUNC("asm/func/FUN_0821397c.inc");
#endif
}

NAKED void FUN_082139b4(EntityA288* p, s16 param_2) { INCFUNC("asm/func/FUN_082139b4.inc"); }

void FUN_08213a50(EntityA288* p) {
  p->sprite_98.flags |= SPRFLAG_HIDDEN;
  TextBox_Close();
}

NAKED s32 FUN_08213a64(EntityA288* p) { INCFUNC("asm/func/FUN_08213a64.inc"); }

NAKED void FUN_08213b30(EntityA288* p) { INCFUNC("asm/func/FUN_08213b30.inc"); }

NAKED s32 FUN_08213c24(EntityA288* p) { INCFUNC("asm/func/FUN_08213c24.inc"); }

NAKED void FUN_08213ce4(EntityA288* p) { INCFUNC("asm/func/FUN_08213ce4.inc"); }

void FUN_08213d70(EntityA288* p) {
  MainSprite_Remove(&p->sprites_10c[0]);
  MainSprite_Remove(&p->sprites_10c[1]);
}

// 上半分のテキストボックスを BGP_C486 で開いて1行目を即時表示する
void EntityA288_ShowText(EntityA288* p) {
  TextBox_SetBgPltt(BGP_C486);
  TextBox_Start(p->unk_1cc);
  TextBox_ShowLine(0);
  TextBox_SetRect(2, 3, 32, 6);
  TextBox_SetInstant(1);
}

NAKED void FUN_08213dc8(EntityA288* p) { INCFUNC("asm/func/FUN_08213dc8.inc"); }

NAKED void FUN_08214160(EntityA288* p) { INCFUNC("asm/func/FUN_08214160.inc"); }

void FUN_08214248(EntityA288* p) {
  MainSprite* sprite = p->sprites_1d8;
  s32 i;

  for (i = 0; i < 12; i++) {
    MainSprite_Remove(sprite);
    sprite++;
  }

  MainSprite_Remove(&p->sprite_658);
}

NAKED void FUN_08214274(EntityA288* p) { INCFUNC("asm/func/FUN_08214274.inc"); }

NAKED void FUN_08214334(EntityA288* p) { INCFUNC("asm/func/FUN_08214334.inc"); }

// 残差2命令, 原典は sprites_1d8 の先頭アドレスを別レジスタに残して sprite_658.flags をそこからの +0x488 で引く, MainSprite* ローカルと sprites_1d8[13] 化は試済
NON_MATCH void FUN_082143c0(EntityA288* p) {
#ifdef NONMATCHING_C
  MainSprite* sprite = p->sprites_1d8;
  s32 i;

  for (i = 0; i < 12; i++) {
    sprite[i].flags |= SPRFLAG_HIDDEN;
  }

  p->sprite_658.flags |= SPRFLAG_HIDDEN;
#else
  INCFUNC("asm/func/FUN_082143c0.inc");
#endif
}

NAKED void FUN_082143f4(EntityA288* p) { INCFUNC("asm/func/FUN_082143f4.inc"); }

NAKED void FUN_08214a24(EntityA288* p) { INCFUNC("asm/func/FUN_08214a24.inc"); }

NAKED void FUN_082150e8(EntityA288* p) { INCFUNC("asm/func/FUN_082150e8.inc"); }

// スプライトとテキストパネルを片付ける
void EntityA288_DestroyPanels(EntityA288* p) {
  s32 i;

  MainSprite_Remove(&p->sprite_6c0);
  MainSprite_Remove(&p->sprite_720);

  for (i = 0; i < 5; i++) {
    TextPanel_Destroy(p->windowIDs[i]);
  }
}

NAKED void FUN_082151d8(EntityA288* p) { INCFUNC("asm/func/FUN_082151d8.inc"); }

void FUN_082152c0(EntityA288* p) {
  MainSprite_Show(&p->sprite_720);
  MainSprite_SetAnim(&p->sprite_720, &p->gfx, 4, 1, 0);
}

void FUN_082152ec(EntityA288* p) {
  MainSprite* sprite = &p->sprite_720;

  sprite->pos.y = p->unk_dba * 16;
}

NAKED void FUN_08215304(EntityA288* p) { INCFUNC("asm/func/FUN_08215304.inc"); }

NAKED void FUN_082156bc(EntityA288* p) { INCFUNC("asm/func/FUN_082156bc.inc"); }

NAKED void FUN_0821572c(EntityA288* p) { INCFUNC("asm/func/FUN_0821572c.inc"); }

NAKED void FUN_082157d4(EntityA288* p) { INCFUNC("asm/func/FUN_082157d4.inc"); }

void FUN_0821587c(EntityA288* p) {
  MainSprite_Remove(&p->sprites_dbc[0]);
  MainSprite_Remove(&p->sprites_dbc[1]);
}

NAKED void FUN_082158a0(EntityA288* p) { INCFUNC("asm/func/FUN_082158a0.inc"); }

void FUN_082158e4(EntityA288* p) {
  MainSprite* sprite = &p->sprites_dbc[0];

  sprite->pos.y = p->unk_e7c * 24;
}

NAKED void FUN_082158fc(EntityA288* p) { INCFUNC("asm/func/FUN_082158fc.inc"); }

NAKED void FUN_08215950(EntityA288* p) { INCFUNC("asm/func/FUN_08215950.inc"); }

NAKED void FUN_08215d24(EntityA288* p) { INCFUNC("asm/func/FUN_08215d24.inc"); }

NAKED void FUN_08215db4(EntityA288* p) { INCFUNC("asm/func/FUN_08215db4.inc"); }

NAKED void FUN_08215f3c(EntityA288* p) { INCFUNC("asm/func/FUN_08215f3c.inc"); }

NAKED void FUN_08215f98(EntityA288* p) { INCFUNC("asm/func/FUN_08215f98.inc"); }

NAKED void FUN_08216000(EntityA288* p) { INCFUNC("asm/func/FUN_08216000.inc"); }

NAKED void FUN_0821605c(EntityA288* p) { INCFUNC("asm/func/FUN_0821605c.inc"); }

NAKED void FUN_082160d8(EntityA288* p) { INCFUNC("asm/func/FUN_082160d8.inc"); }

NAKED void FUN_08216154(EntityA288* p) { INCFUNC("asm/func/FUN_08216154.inc"); }

NAKED void FUN_0821619c(EntityA288* p) { INCFUNC("asm/func/FUN_0821619c.inc"); }

NAKED void FUN_082164e4(EntityA288* p) { INCFUNC("asm/func/FUN_082164e4.inc"); }

NAKED s32 FUN_0821660c(EntityA288* p) { INCFUNC("asm/func/FUN_0821660c.inc"); }

NAKED void FUN_08216730(EntityA288* p) { INCFUNC("asm/func/FUN_08216730.inc"); }

NAKED void FUN_082167dc(EntityA288* p) { INCFUNC("asm/func/FUN_082167dc.inc"); }

NAKED void FUN_08216894(EntityA288* p) { INCFUNC("asm/func/FUN_08216894.inc"); }

NAKED void FUN_08216968(EntityA288* p, unknown* param_2) { INCFUNC("asm/func/FUN_08216968.inc"); }

NAKED void FUN_082169a0(EntityA288* p) { INCFUNC("asm/func/FUN_082169a0.inc"); }

void FUN_08216a60(EntityA288* p) {
  MainSprite_Remove(&p->sprites_166c[0]);
  MainSprite_Remove(&p->sprites_166c[1]);
  MainSprite_Remove(&p->sprites_166c[2]);
}

NAKED void FUN_08216a90(EntityA288* p) { INCFUNC("asm/func/FUN_08216a90.inc"); }

NAKED void FUN_08216bdc(EntityA288* p) { INCFUNC("asm/func/FUN_08216bdc.inc"); }

// sprites_166c[1] を 78 番のポーズで表示する
void FUN_08216c88(EntityA288* p) {
  MainSprite* sprites = p->sprites_166c;

  FUN_08216a90(p);
  MainSprite_SetPose(&sprites[1], &p->gfx, 78, 1);
  sprites[1].flags &= ~SPRFLAG_HIDDEN;
  FUN_08216bdc(p);
}

void FUN_08216cc4(EntityA288* p) {
  p->sprites_166c[0].flags |= SPRFLAG_HIDDEN;
  p->sprites_166c[1].flags |= SPRFLAG_HIDDEN;
  p->sprites_166c[2].flags |= SPRFLAG_HIDDEN;
}

NAKED void FUN_08216cf4(EntityA288* p, s32 param_2) { INCFUNC("asm/func/FUN_08216cf4.inc"); }

NAKED void FUN_08216dd8(EntityA288* p, s32 param_2) { INCFUNC("asm/func/FUN_08216dd8.inc"); }

NAKED s32 FUN_08216e60(EntityA288* p, u8 param_2) { INCFUNC("asm/func/FUN_08216e60.inc"); }

NAKED s32 FUN_08216ea8(EntityA288* p) { INCFUNC("asm/func/FUN_08216ea8.inc"); }

NAKED s32 FUN_08216f0c(EntityA288* p) { INCFUNC("asm/func/FUN_08216f0c.inc"); }

NAKED void FUN_0821722c(EntityA288* p) { INCFUNC("asm/func/FUN_0821722c.inc"); }

NAKED void FUN_08217440(EntityA288* p) { INCFUNC("asm/func/FUN_08217440.inc"); }

NAKED void FUN_08217648(EntityA288* p) { INCFUNC("asm/func/FUN_08217648.inc"); }

NAKED void FUN_0821785c(EntityA288* p) { INCFUNC("asm/func/FUN_0821785c.inc"); }

NAKED void FUN_08217a10(EntityA288* p) { INCFUNC("asm/func/FUN_08217a10.inc"); }

NAKED void FUN_08217b48(EntityA288* p) { INCFUNC("asm/func/FUN_08217b48.inc"); }

void FUN_08217bb8(EntityA288* p) {
  FUN_08217a10(p);
  FUN_08217b48(p);
}

void FUN_08217bcc(EntityA288* p) {
  p->sprites_166c[0].flags |= SPRFLAG_HIDDEN;
  p->sprites_166c[1].flags |= SPRFLAG_HIDDEN;
  p->sprites_166c[2].flags |= SPRFLAG_HIDDEN;
}

NAKED void FUN_08217bfc(EntityA288* p) { INCFUNC("asm/func/FUN_08217bfc.inc"); }

NAKED void FUN_08217c6c(EntityA288* p) { INCFUNC("asm/func/FUN_08217c6c.inc"); }

NAKED s32 FUN_08217cd0(EntityA288* p, s32 param_2) { INCFUNC("asm/func/FUN_08217cd0.inc"); }

NAKED s32 FUN_08217d5c(EntityA288* p) { INCFUNC("asm/func/FUN_08217d5c.inc"); }

NAKED s32 FUN_08217e00(EntityA288* p) { INCFUNC("asm/func/FUN_08217e00.inc"); }

NAKED void FUN_0821813c(EntityA288* p) { INCFUNC("asm/func/FUN_0821813c.inc"); }

NAKED void FUN_082183e0(EntityA288* p) { INCFUNC("asm/func/FUN_082183e0.inc"); }

NAKED void FUN_0821869c(EntityA288* p) { INCFUNC("asm/func/FUN_0821869c.inc"); }

NAKED void FUN_08218910(EntityA288* p) { INCFUNC("asm/func/FUN_08218910.inc"); }

NAKED void FUN_08218b20(EntityA288* p) { INCFUNC("asm/func/FUN_08218b20.inc"); }

NAKED void FUN_08218b34(EntityA288* p, unknown* param_2) { INCFUNC("asm/func/FUN_08218b34.inc"); }

NAKED void FUN_08218c30(EntityA288* p) { INCFUNC("asm/func/FUN_08218c30.inc"); }

NAKED void FUN_08218ddc(EntityA288* p) { INCFUNC("asm/func/FUN_08218ddc.inc"); }

void FUN_08218e4c(EntityA288* p) {
  if (gStat->unk_93a != 0) {
    p->unk_165c = 0;
  } else {
    p->unk_165c = 1;
  }

  p->unk_165e = 0;
}

NAKED void FUN_08218e90(EntityA288* p) { INCFUNC("asm/func/FUN_08218e90.inc"); }

NAKED void FUN_08219238(EntityA288* p) { INCFUNC("asm/func/FUN_08219238.inc"); }

NAKED void FUN_082192f4(EntityA288* p) { INCFUNC("asm/func/FUN_082192f4.inc"); }

NAKED void FUN_08219d98(EntityA288* p) { INCFUNC("asm/func/FUN_08219d98.inc"); }

void FUN_08219e5c(EntityA288* p) {
  s32 indices[1];

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_33B2);
  indices[0] = 0;
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, indices);
  FUN_08213880(p);
}

void FUN_08219e9c(EntityA288* p) {
  p->pltt = GetBgPlttFile(BGP_E9C3)->body;
  CpuCopy32(p->pltt, gBgPlttBuffer, 80 * sizeof(rgb555));
  EntityA288_LoadBgPltt(p);
}

NAKED void FUN_08219ed0(EntityA288* p) { INCFUNC("asm/func/FUN_08219ed0.inc"); }

void (*const sEntityA288StateFns[7])(EntityA288*) = {
    FUN_08213dc8,
    FUN_082143f4,
    FUN_08214a24,
    FUN_08215304,
    FUN_08215950,
    FUN_082192f4,
    FUN_0821619c,
};  // 0x085AFF84

// 状態を切り替えてタイマーを止める
void EntityA288_SetState(EntityA288* p, s32 state) {
  p->state = state;
  p->timer1 = 0;
  p->updateCallback = sEntityA288StateFns[state];
  EntityA288_SetFlags(p, 1);
  p->unk_5c = 0;
  p->timer2 = 0;
  EntityA288_SetFlags(p, 2);
}

s32 EntityA288_Update(EntityA288* p) {
  if (!(p->flags & 1)) {
    p->timer1++;
  }

  if (!(p->flags & 2)) {
    p->timer2++;
  }

  p->updateCallback(p);
  return 0;
}

s32 EntityA288_Destroy(EntityA288* p) {
  FUN_08213960(p);
  FUN_08213d70(p);
  FUN_08214248(p);
  EntityA288_DestroyPanels(p);
  FUN_0821587c(p);
  FUN_08215f3c(p);
  FUN_08218ddc(p);
  FUN_08216a60(p);
  return 0;
}

NAKED s32 EntityA288_Init(EntityA288* p) { INCFUNC("asm/func/EntityA288_Init.inc"); }

EntityA288* EntityA288_Create(void) {
  EntityA288* p = CreateEntity(ENTITY_UNK_11, sizeof(EntityA288));

  if (p != NULL) {
    SetEntityRoutine(p, EntityA288_Update, EntityA288_Destroy);
    if (EntityA288_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
