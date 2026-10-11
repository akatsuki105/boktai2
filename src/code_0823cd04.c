#include "global.h"
#include "save.h"
#include "time.h"
#include "video.h"
#include "vm.h"
#include "weapon.h"

extern s32 s32_0300446c;
extern u16 u16_030047d8;
extern u32 gSentinel02020400;
extern const u8 u8_ARRAY_08dbd798[6][2];  // 0x08DBD798

COMMON_DATA bool32 bool32_03004788 = FALSE;  // 0x03004788

COMMON_DATA u32 u32_0300478c = 0;  // 0x0300478C, FUN_0823cd04 の一括クリアで 0 になる
COMMON_DATA u32 u32_03004790 = 0;
COMMON_DATA u32 u32_03004794 = 0;
COMMON_DATA u32 u32_03004798 = 0;
COMMON_DATA u32 u32_0300479c = 0;

COMMON_DATA u32 u32_030047a0 = 0;
COMMON_DATA u32 gFlag030047a4 = 0;

COMMON_DATA SystemSaveData* gSystemSaveData = NULL;
COMMON_DATA u32 u32_030047ac = 0;
COMMON_DATA u32 u32_030047b0 = 0;
COMMON_DATA bool32 gSaveSucceeded = FALSE;     // 0x030047B4, Save_WriteCore でセーブ成功時に 1 がセットされる
COMMON_DATA bool32 gSoftResetInhibit = FALSE;  // 0x030047B8, 立てたフレームはソフトリセットのコマンド判定を飛ばす, Entity0823acbc_Update が読んで 0 に戻す
COMMON_DATA u32 u32_030047bc = 0;              // 0x030047BC, Entity0823acbc_Update が ENTITY_DISABLE_1 が落ちている間だけ毎フレーム +1 する, 読み手は未発見
COMMON_DATA u32 u32_030047c0 = 0;              // 0x030047C0, FUN_0823ACBC と FUN_0823CD04 の一括クリアでしか触られない, 読み手も本来の書き手も未発見
COMMON_DATA u32 u32_030047c4 = 0;              // 0x030047C4, Entity0823acbc_Update が 0 を書くほかは一括クリアのみ, 読み手は未発見

static inline void SystemSave_SetUnk09(u32 val) { gSystemSaveData->unk_09 = val; }

void FUN_0823cd04(void) {
  gFlag030047a4 = 0;
  u32_030047a0 = 0;
  u32_0300479c = 0;
  u32_030047c0 = 0;
  u32_0300478c = 0;
  u32_030047c4 = 0;
}

char* GetPlayerName(void) { return gStat->name; }

// 0x0272
NAKED void SetPlayerName(void) { INCFUNC("asm/func/SetPlayerName.inc"); }

// key でソート済みの {u16 key; u16 value;} のテーブルを二分探索して value を返す, 見つからなければ 0
// 4バイト1組 {key, value} の表を二分探索して value を返す, 見つからなければ 0
static u32 FUN_0823cdc0(u32 key, const u16* table, s32 lo, s32 hi) {
  while (lo < hi) {
    s32 mid = (lo + hi) >> 1;

    if (table[mid * 2] < key) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }

  if (table[lo * 2] == key) {
    return table[lo * 2 + 1];
  }
  return 0;
}

u32 FUN_0823cdf8(u16 key) {
  // {key, obpID}
  static const u16 sObpBlendPlttIDLut[171][2] = {
      {0x8A,   0x50 },
      {0x48A,  0x34 },
      {0x4B3,  0x11B},
      {0x5A2,  0x8B },
      {0x66A,  0x169},
      {0x9CA,  0x2A5},
      {0xBA8,  0x61 },
      {0xC0A,  0x286},
      {0xDDE,  0x289},
      {0xE48,  0x184},
      {0xEBB,  0x2F0},
      {0x1120, 0x7  },
      {0x1314, 0x138},
      {0x18A8, 0xCF },
      {0x1A84, 0x2DF},
      {0x1B59, 0x73 },
      {0x1C1A, 0x0  },
      {0x1D09, 0x291},
      {0x1D78, 0x1CC},
      {0x1FBD, 0x70 },
      {0x2058, 0x22E},
      {0x210E, 0x2C },
      {0x2499, 0x207},
      {0x2567, 0x287},
      {0x2712, 0x56 },
      {0x2769, 0xD0 },
      {0x2817, 0x107},
      {0x2AF0, 0x40 },
      {0x2C12, 0x1C },
      {0x2C1A, 0x12C},
      {0x2C3D, 0x1F2},
      {0x2D41, 0x48 },
      {0x2EC0, 0x252},
      {0x3356, 0x59 },
      {0x34C0, 0x8E },
      {0x3640, 0x19A},
      {0x3876, 0x28A},
      {0x3C13, 0x1B1},
      {0x41B1, 0xB3 },
      {0x44EE, 0x151},
      {0x494E, 0x251},
      {0x4981, 0x2E8},
      {0x4AAE, 0x5B },
      {0x4AEE, 0x3D },
      {0x4BD4, 0x282},
      {0x4ED6, 0x2E7},
      {0x4FDA, 0x213},
      {0x505C, 0x13C},
      {0x5284, 0x15E},
      {0x528E, 0x132},
      {0x528F, 0x8F },
      {0x5290, 0x201},
      {0x5291, 0x12D},
      {0x5293, 0x27B},
      {0x5889, 0x223},
      {0x588A, 0xC3 },
      {0x588B, 0x272},
      {0x588C, 0x2F4},
      {0x588D, 0x231},
      {0x5A6E, 0x14C},
      {0x5B54, 0x211},
      {0x5B78, 0xD5 },
      {0x5BA7, 0xEC },
      {0x5BB7, 0xEF },
      {0x5D7C, 0x152},
      {0x5DC0, 0x57 },
      {0x6154, 0x1D2},
      {0x654B, 0x27A},
      {0x6F61, 0x29F},
      {0x7ACD, 0x22F},
      {0x7ACE, 0x92 },
      {0x7ACF, 0xA7 },
      {0x7AD0, 0x2A },
      {0x7AD2, 0xAF },
      {0x7C99, 0x1B6},
      {0x7E82, 0x74 },
      {0x836A, 0x7D },
      {0x84EE, 0x241},
      {0x8637, 0x113},
      {0x8820, 0x155},
      {0x8C42, 0x1D },
      {0x8C43, 0x121},
      {0x9506, 0xB0 },
      {0x96B5, 0x1E2},
      {0x96F7, 0xA6 },
      {0x97D3, 0x117},
      {0x98AD, 0x2CF},
      {0x994A, 0x2ED},
      {0x994B, 0x2EF},
      {0x994C, 0x2E5},
      {0x994D, 0x28F},
      {0x994E, 0x292},
      {0x994F, 0x29B},
      {0x9950, 0x29C},
      {0x9951, 0x29E},
      {0x997A, 0x2EE},
      {0x9A1F, 0xF2 },
      {0x9D2D, 0x33 },
      {0x9D3F, 0x1B3},
      {0x9D40, 0x1FD},
      {0x9D41, 0x23D},
      {0x9D43, 0x4F },
      {0x9E08, 0x149},
      {0x9E1B, 0x53 },
      {0xA06F, 0x2E3},
      {0xA0D5, 0x3E },
      {0xA138, 0x2D3},
      {0xA152, 0x11C},
      {0xA47C, 0x13D},
      {0xA680, 0x42 },
      {0xA6A0, 0x47 },
      {0xA850, 0x49 },
      {0xA9D6, 0x2EA},
      {0xB019, 0x1B7},
      {0xB0BC, 0x11F},
      {0xB0E2, 0x36 },
      {0xB306, 0x2  },
      {0xB47B, 0x2AB},
      {0xB626, 0x17C},
      {0xB837, 0x153},
      {0xB96C, 0x93 },
      {0xBB68, 0x139},
      {0xBCA8, 0x78 },
      {0xC038, 0x1C3},
      {0xC039, 0x188},
      {0xC046, 0x137},
      {0xC060, 0x38 },
      {0xC37B, 0x2FA},
      {0xC3C3, 0x5F },
      {0xC459, 0xF3 },
      {0xC918, 0x293},
      {0xC93D, 0x2A2},
      {0xCB7D, 0x2C7},
      {0xCC88, 0x1D3},
      {0xCDAB, 0xBB },
      {0xCF7A, 0x2D5},
      {0xD0A3, 0x17B},
      {0xD28D, 0x5C },
      {0xD28E, 0x17 },
      {0xD290, 0x1FA},
      {0xD291, 0x1BF},
      {0xD56D, 0x194},
      {0xD631, 0xF7 },
      {0xD635, 0x1F5},
      {0xD636, 0x1A1},
      {0xD637, 0x17D},
      {0xD638, 0xDC },
      {0xD644, 0x2B7},
      {0xD962, 0xBC },
      {0xDA6D, 0x262},
      {0xDB6C, 0x16B},
      {0xDC07, 0xF4 },
      {0xDC0E, 0x2DE},
      {0xDC8E, 0xB5 },
      {0xDD5C, 0x3C },
      {0xDDE7, 0x146},
      {0xDFCF, 0x183},
      {0xE0C9, 0x154},
      {0xE1D2, 0x35 },
      {0xE1D5, 0x2B1},
      {0xE7EA, 0x182},
      {0xE881, 0x2DC},
      {0xEB1D, 0x285},
      {0xEED8, 0x13B},
      {0xEF62, 0x99 },
      {0xF070, 0x97 },
      {0xF422, 0xD8 },
      {0xF680, 0x6  },
      {0xF76D, 0x82 },
      {0xFB4D, 0x10C},
      {0xFDC5, 0xA5 },
  };  // 0x08DBD83C
  return FUN_0823cdc0(key, (const u16*)sObpBlendPlttIDLut, 0, ARRAY_COUNT(sObpBlendPlttIDLut) - 1);
}

s32 FUN_0823ce10(u16* param_1, u16* param_2) {
  *param_1 = u8_ARRAY_08dbd798[gClock.spanOfTime][0];
  *param_2 = u8_ARRAY_08dbd798[gClock.spanOfTime][1];
  return 0;
}

void FUN_0823ce3c(u16* param_1, u16* param_2) {
  *param_1 = u8_ARRAY_08dbd798[gClock.spanOfTime][0];
  *param_2 = u8_ARRAY_08dbd798[gClock.spanOfTime][1];
}

NAKED void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7) { INCFUNC("asm/func/FUN_0823ce68.inc"); }

NAKED s32 FUN_0823cecc(void) { INCFUNC("asm/func/FUN_0823cecc.inc"); }

NAKED s32 FUN_0823cf90(void) { INCFUNC("asm/func/FUN_0823cf90.inc"); }

NAKED s32 FUN_0823d03c(void) { INCFUNC("asm/func/FUN_0823d03c.inc"); }

NAKED s32 FUN_0823d0e8(void) { INCFUNC("asm/func/FUN_0823d0e8.inc"); }

// 0xEDE2, 指定した BG を隠す
void FUN_0823d1d8(void) {
  u16 mask = DISPCNT_BG0_ON << (u16)VM_GetValue();

  gStagedDISPCNT &= ~mask;
}

// 0x1500, 指定した BG を表示する
void FUN_0823d1fc(void) {
  u16 mask = DISPCNT_BG0_ON << (u16)VM_GetValue();

  gStagedDISPCNT |= mask;
}

// 0x138E
void UNUSED SoftResetScripted(void) { SoftReset_0823a928(); }

NAKED void FUN_0823d22c(void) { INCFUNC("asm/func/FUN_0823d22c.inc"); }

NAKED void FUN_0823d280(void) { INCFUNC("asm/func/FUN_0823d280.inc"); }

void FUN_0823d2bc(void) { s32_0300446c = VM_GetNamedArgValue('t', 0); }

void FUN_0823d2d4(void) { s32_0300446c = 0; }

void FUN_0823d2e0(s32 idx) {
  if (*(idx + gStat->unk_948) < 9999) {
    (*(idx + gStat->unk_948))++;
  }
}

void FUN_0823d310(s32 idx) {
  if (*(idx + gStat->unk_950) < 9999) {
    (*(idx + gStat->unk_950))++;
  }
}

void UNUSED nop_0823d33c(void) {}

u8* FUN_0823d340(void) { return VM_GetPC(); }

void* FUN_0823d34c(void) { return VM_GetValueSafe2(); }

// スクリプトの変数へフレームカウンタを書き出す
void FUN_0823d358(void) {
  u8 desc[8];

  FUN_0823167c(desc);
  FUN_0823206c(desc, 0, gSystemSaveData->frameCounter);
}

NAKED void FUN_0823d37c(void) { INCFUNC("asm/func/FUN_0823d37c.inc"); }

void FUN_0823d3ec(void) { SystemSave_SetUnk09(1); }

u32 FUN_0823d3fc(void) { return gSystemSaveData->unk_09; }

u32 FUN_0823d408(void) { return gSystemSaveData->unk_0a; }

const WeaponData* FUN_0823d414(s32 idx) { return &gWeaponDB[idx]; }

NAKED void FUN_0823d428(void) { INCFUNC("asm/func/FUN_0823d428.inc"); }

void FUN_0823d4ac(void) {
  if (gSentinel02020400 != 0x516B92EE) {
    gSentinel02020400 = 0x516B92EE;
  }
}

bool32 FUN_0823d4c8(void) {
  if (gSentinel02020400 == 0x516B92EE) {
    return TRUE;
  }
  return FALSE;
}

NAKED s32 UpdateSolDarkSide(void) { INCFUNC("asm/func/UpdateSolDarkSide.inc"); }

NAKED s32 UpdateWeaponStyle(void) { INCFUNC("asm/func/UpdateWeaponStyle.inc"); }

// unk_2fe が一番大きい添字を返す
s32 FUN_0823d5b8(void) {
  s32 best = 0;
  s32 bestVal = -100;
  s32 i;

  for (i = 0; i < 5; i++) {
    if (gStat->unk_2fe[i] > bestVal) {
      bestVal = gStat->unk_2fe[i];
      best = i;
    }
  }

  return best;
}

NAKED bool32 FUN_0823d5f0(void) { INCFUNC("asm/func/FUN_0823d5f0.inc"); }

// 0xDAA4
u32 GetPrefecture(void) { return gSystemSaveData->prefecture; }

// 0xED2E, クロスオーバーバトルが解放されているか
// タイトル画面 -> "LINK" -> "通信対戦"にカーソルを当てて、 L,R,L,R,L,L,R,R,R,R,L,L,SELECT,START,SELECT,START と入力するとクロスオーバーバトルが解放される
bool32 IsCrossoverUnlocked(void) {
  if (gSystemSaveData->crossoverUnlocked == 0x369F) {
    return TRUE;
  }
  return FALSE;
}

// 0xB45F
s32 GetCrossoverPoint(void) { return gSystemSaveData->crossoverPoint; }

// 0x904B
s32 SetCrossoverPoint(void) {
  s32 point = VM_GetNamedArgValue('p', gSystemSaveData->crossoverPoint);

  if (point < 0) {
    point = 0;
  } else if (point > 9999) {
    point = 9999;
  }

  gSystemSaveData->crossoverPoint = point;
  return point;
}

// 0x2354
u16 GetCrossoverBattleCount(void) { return gSystemSaveData->crossoverCount; }

// 0x3F3B
u16 GetCrossoverBattleWins(void) { return gSystemSaveData->crossoverWins; }

// 0x058D, '.s' の文字列のIDを覚えておく
void FUN_0823d70c(void) {
  if (VM_SeekToNamedArg('s')) {
    u8* pc = VM_GetPC();

    if (pc != NULL) {
      char* str = Textbox_LookupString(VM_ParseStringRef(pc));

      u16_030047d8 = (str[1] | (str[0] << 8)) & 0xFFF;
    }
  }
}

// 0x5CC4
void FUN_0823d748(void) { gStat->mapInitScriptID = VM_GetValue(); }
