#include "bg_pltt.h"
#include "file.h"
#include "global.h"
#include "map_inline.h"
#include "player.h"
#include "save.h"
#include "sprite_common.h"
#include "time.h"
#include "video.h"
#include "vm.h"
#include "weapon.h"

extern s32 gGrayscaleTimer;
extern u16 gSilentCharcode;
extern u32 gSentinel02020400;
extern const u8 u8_ARRAY_08dbd798[6][2];  // 0x08DBD798

COMMON_DATA bool32 gPlayTimeEnabled = FALSE;  // 0x03004788

COMMON_DATA u32 u32_0300478c = 0;  // 0x0300478C, FUN_0823cd04 の一括クリアで 0 になる
COMMON_DATA u32 u32_03004790 = 0;
COMMON_DATA u32 gSystemFrameCounter = 0;
COMMON_DATA u32 gMapChangeFlags = 0;
COMMON_DATA u32 u32_0300479c = 0;

COMMON_DATA u32 gDebugGameFlags = 0;
COMMON_DATA u32 gGameFlags = 0;

COMMON_DATA SystemSaveData* gSystemSaveData = NULL;
COMMON_DATA u32 gMapChanging = 0;
COMMON_DATA u32 u32_030047b0 = 0;
COMMON_DATA bool32 gSaveSucceeded = FALSE;     // 0x030047B4, Save_WriteCore でセーブ成功時に 1 がセットされる
COMMON_DATA bool32 gSoftResetInhibit = FALSE;  // 0x030047B8, 立てたフレームはソフトリセットのコマンド判定を飛ばす, GameSystem_Update が読んで 0 に戻す
COMMON_DATA u32 gUnpausedFrameCounter = 0;     // 0x030047BC, GameSystem_Update が SUSPEND_PAUSE が落ちている間だけ毎フレーム +1 する, 読み手は未発見
COMMON_DATA u32 u32_030047c0 = 0;              // 0x030047C0, GameSystem_Boot と FUN_0823CD04 の一括クリアでしか触られない, 読み手も本来の書き手も未発見
COMMON_DATA u32 u32_030047c4 = 0;              // 0x030047C4, GameSystem_Update が 0 を書くほかは一括クリアのみ, 読み手は未発見

bool8 Save_ReadSystemData(void);
void MapPltt_PushCommand(s32 val, s32 count, u32* args);
void Entity6978_SetRequest(u32 request, s32 count, u32* args);
void* VM_GetValueAtSafe_Proxy(u8* addr);

static inline void SystemSave_SetUnk09(u32 val) { gSystemSaveData->unk_09 = val; }

void FUN_0823cd04(void) {
  gGameFlags = 0;
  gDebugGameFlags = 0;
  u32_0300479c = 0;
  u32_030047c0 = 0;
  u32_0300478c = 0;
  u32_030047c4 = 0;
}

char* GetPlayerName(void) { return gStat->name; }

// 0x0272
void Cmd_SetPlayerName(void) {
  char* name = GetPlayerName();

  CpuFill32(0, name, 16);
  if (VM_SeekToNamedArg('n')) {
    char* str = VM_GetValueAtSafe_Proxy(VM_GetPC());

    if (str != NULL) {
      s32 i;

      for (i = 0; str[i] != '\0' && i < 16; i++) {
        name[i] = str[i];
      }
    }
  } else {
    name[0] = 0x80, name[1] = 0xA2;  // "ジ"
    name[2] = 0x80, name[3] = 0x98;  // "ャ"
    name[4] = 0x80, name[5] = 0x91;  // "ン"
    name[6] = 0x80, name[7] = 0x9F;  // "ゴ"
  }
}

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

u32 FUN_0823cdf8(SpriteID16 id) {
  // {spriteID, obpID}
  static const u16 sObpBlendPlttIDLut[171][2] = {
      {SPRITE_RUBBLE_008A,     0x50          },
      {SPRITE_PILLER_048A,     0x34          },
      {SPRITE_CACTUS,          0x11B         },
      {SPRITE_TOMBSTONE,       OBP_TOMBSTONE },
      {SPRITE_BAMBOO,          0x169         },
      {0x09CA,                 0x2A5         },
      {SPRITE_MAGIC_SQUARE,    0x61          },
      {SPRITE_TOWERCLOCK,      0x286         },
      {SPRITE_WARDEN,          0x289         },
      {SPRITE_SPIRAL_CONSOLE,  0x184         },
      {0x0EBB,                 0x2F0         },
      {0x1120,                 0x7           },
      {0x1314,                 0x138         },
      {SPRITE_OJAMA_BAT,       0xCF          },
      {0x1A84,                 0x2DF         },
      {SPRITE_IRON_BARS_1B59,  0x73          },
      {PTCL_GROUP_0,           0x0           },
      {0x1D09,                 0x291         },
      {SPRITE_1D78,            0x1CC         },
      {SPRITE_WALL_1FBD,       0x70          },
      {SPRITE_SHAIAN_SHOP,     0x22E         },
      {SPRITE_EBALL_210E,      0x2C          },
      {SPRITE_COFFIN_0,        0x207         },
      {SPRITE_PLANT_2567,      0x287         },
      {SPRITE_COIN,            0x56          },
      {SPRITE_TOUCH_SWITCH,    0xD0          },
      {SPRITE_2817,            0x107         },
      {SPRITE_CHANDELIER_2AF0, 0x40          },
      {SPRITE_GRATING,         0x1C          },
      {SPRITE_2C1A,            0x12C         },
      {SPRITE_DRIED_OASIS,     0x1F2         },
      {SPRITE_EFF_2D41,        0x48          },
      {SPRITE_2EC0,            0x252         },
      {0x3356,                 0x59          },
      {SPRITE_WH_SHUTTER,      0x8E          },
      {SPRITE_SPOTLIGHT,       0x19A         },
      {SPRITE_MIMIC,           0x28A         },
      {SPRITE_PINPAD,          0x1B1         },
      {SPRITE_NUTS,            0xB3          },
      {SPRITE_44EE,            0x151         },
      {SPRITE_494E,            0x251         },
      {0x4981,                 0x2E8         },
      {SPRITE_OJISAN,          0x5B          },
      {SPRITE_WALL_4AEE,       0x3D          },
      {0x4BD4,                 0x282         },
      {0x4ED6,                 0x2E7         },
      {SPRITE_LAVA_FLOOR,      OBP_LAVA_FLOOR},
      {SPRITE_DISH,            0x13C         },
      {0x5284,                 0x15E         },
      {0x528E,                 0x132         },
      {SPRITE_SPIDER,          0x8F          },
      {SPRITE_GOLEM,           0x201         },
      {SPRITE_SWORD_AX,        0x12D         },
      {0x5293,                 0x27B         },
      {0x5889,                 0x223         },
      {0x588A,                 0xC3          },
      {0x588B,                 0x272         },
      {0x588C,                 0x2F4         },
      {0x588D,                 0x231         },
      {SPRITE_CROW,            0x14C         },
      {SPRITE_F_WALL_5B54,     0x211         },
      {SPRITE_WINDOW_5B78,     0xD5          },
      {SPRITE_WINDOW_5BA7,     0xEC          },
      {SPRITE_WINDOW_5BB7,     0xEF          },
      {SPRITE_5D7C,            0x152         },
      {SPRITE_MIRROR,          OBP_MIRROR    },
      {SPRITE_TORCH,           0x1D2         },
      {0x654B,                 0x27A         },
      {0x6F61,                 0x29F         },
      {SPRITE_DOOR_WOOD,       0x22F         },
      {0x7ACE,                 0x92          },
      {0x7ACF,                 0xA7          },
      {0x7AD0,                 0x2A          },
      {SPRITE_IRON_BARS_7AD2,  0xAF          },
      {SPRITE_EMBLEM_7C99,     0x1B6         },
      {SPRITE_HIMAWARI,        0x74          },
      {0x836A,                 0x7D          },
      {SPRITE_BLOCK_ICE,       0x241         },
      {0x8637,                 0x113         },
      {0x8820,                 0x155         },
      {0x8C42,                 0x1D          },
      {0x8C43,                 0x121         },
      {SPRITE_BEE,             0xB0          },
      {SPRITE_MONOLITH,        0x1E2         },
      {SPRITE_SIGNBOARD,       0xA6          },
      {SPRITE_OTENKO_00,       0x117         },
      {0x98AD,                 0x2CF         },
      {0x994A,                 0x2ED         },
      {0x994B,                 0x2EF         },
      {0x994C,                 0x2E5         },
      {0x994D,                 0x28F         },
      {0x994E,                 0x292         },
      {0x994F,                 0x29B         },
      {0x9950,                 0x29C         },
      {0x9951,                 0x29E         },
      {0x997A,                 0x2EE         },
      {0x9A1F,                 0xF2          },
      {SPRITE_WALL_9D2D,       0x33          },
      {SPRITE_ROCK_9D3F,       0x1B3         },
      {SPRITE_WOODEN_BOX,      0x1FD         },
      {SPRITE_BLOCK_ROCK,      0x23D         },
      {SPRITE_BLOCK_9D43,      0x4F          },
      {SPRITE_9E08,            0x149         },
      {0x9E1B,                 0x53          },
      {0xA06F,                 0x2E3         },
      {0xA0D5,                 0x3E          },
      {0xA138,                 0x2D3         },
      {SPRITE_TIME_M_SQ,       0x11C         },
      {SPRITE_STAND,           0x13D         },
      {SPRITE_TRAP_FLOOR,      0x42          },
      {SPRITE_UNUSED_A6A0,     0x47          },
      {SPRITE_HINT_PANEL,      0x49          },
      {0xA9D6,                 0x2EA         },
      {SPRITE_LIFT_IRON,       0x1B7         },
      {SPRITE_SWW_B0BC,        0x11F         },
      {SPRITE_LIGHT_BULB,      0x36          },
      {SPRITE_BLOCK_EMBLEM,    0x2           },
      {0xB47B,                 0x2AB         },
      {0xB626,                 0x17C         },
      {SPRITE_B837,            0x153         },
      {0xB96C,                 0x93          },
      {SPRITE_LEVER_SWITCH,    0x139         },
      {SPRITE_PROPERTY_CUBE,   0x78          },
      {SPRITE_GENERATOR,       0x1C3         },
      {SPRITE_C039,            0x188         },
      {SPRITE_DARKGENERATOR,   0x137         },
      {SPRITE_GEN_UNUSED,      0x38          },
      {0xC37B,                 0x2FA         },
      {SPRITE_SOLAR_PLANT,     0x5F          },
      {SPRITE_SOLAR_FLOOR,     0xF3          },
      {0xC918,                 0x293         },
      {0xC93D,                 0x2A2         },
      {0xCB7D,                 0x2C7         },
      {SPRITE_PETAL_CC88,      0x1D3         },
      {SPRITE_MOUSE_BRIDGE,    0xBB          },
      {0xCF7A,                 0x2D5         },
      {SPRITE_CANTERA,         0x17B         },
      {0xD28D,                 0x5C          },
      {SPRITE_CURORO,          0x17          },
      {0xD290,                 0x1FA         },
      {SPRITE_OCTOPUS_0,       0x1BF         },
      {SPRITE_D56D,            0x194         },
      {0xD631,                 0xF7          },
      {SPRITE_DOG,             0x1F5         },
      {SPRITE_WORM,            0x1A1         },
      {SPRITE_GHOST,           0x17D         },
      {SPRITE_DARKROOT,        0xDC          },
      {0xD644,                 0x2B7         },
      {SPRITE_DOOR_SEALED,     0xBC          },
      {SPRITE_BAT,             0x262         },
      {SPRITE_WALL_DB6C,       0x16B         },
      {SPRITE_DC07,            0xF4          },
      {0xDC0E,                 0x2DE         },
      {SPRITE_TREE_SAPLING,    0xB5          },
      {SPRITE_WALL_DD5C,       0x3C          },
      {SPRITE_WINDOW_DDE7,     0x146         },
      {SPRITE_DFCF,            0x183         },
      {SPRITE_BLOCK_IRON,      0x154         },
      {SPRITE_MASK_E1D2,       0x35          },
      {0xE1D5,                 0x2B1         },
      {SPRITE_E7EA,            0x182         },
      {0xE881,                 0x2DC         },
      {0xEB1D,                 0x285         },
      {SPRITE_WATER_SPRING,    0x13B         },
      {0xEF62,                 0x99          },
      {SPRITE_WEDGE,           0x97          },
      {SPRITE_EFF_F422,        0xD8          },
      {SPRITE_KOMAINU,         0x6           },
      {0xF76D,                 0x82          },
      {0xFB4D,                 0x10C         },
      {SPRITE_UNUSED_FDC5,     0xA5          },
  };  // 0x08DBD83C
  return FUN_0823cdc0(id, (const u16*)sObpBlendPlttIDLut, 0, ARRAY_COUNT(sObpBlendPlttIDLut) - 1);
}

s32 GetTimeOfDayPlttPair(u16* from, u16* to) {
  *from = u8_ARRAY_08dbd798[gClock.spanOfTime][0];
  *to = u8_ARRAY_08dbd798[gClock.spanOfTime][1];
  return 0;
}

static void UNUSED GetTimeOfDayPlttPair2(u16* from, u16* to) {
  *from = u8_ARRAY_08dbd798[gClock.spanOfTime][0];
  *to = u8_ARRAY_08dbd798[gClock.spanOfTime][1];
}

/**
 * @brief BG (MapPltt) と OBJ (Entity6978) に同じフェードを同時にかける
 * @param kind 0: フェード色から元の明るさへ戻す (フェードイン), 1: 元の明るさからフェード色へ寄せる (フェードアウト), 2 / 3: 0 / 1 と同じだがフェード中でも上書きできる版
 * @param durationShift フェードの長さの log2, 1 << durationShift フレームで終わる
 * @param r5 フェード色の R (0..31)
 * @param g5 フェード色の G (0..31)
 * @param b5 フェード色の B (0..31)
 * @param bgRowMask gBgPlttFadeRowMask に入る, bit i が立っている BG パレット行だけフェードする
 * @param objSkipMask gObjPlttFadeSkipMask に入る
 */
void StartBgObjPlttFade(s32 kind, s32 durationShift, s32 r5, s32 g5, s32 b5, u32 bgRowMask, u32 objSkipMask) {
  u32 args[5];
  s32 cmd;
  s32 request;

  switch (kind) {
    case 0: {
      cmd = 2;
      request = 1;
      break;
    }
    case 2: {
      cmd = 4;
      request = 3;
      break;
    }
    case 3: {
      cmd = 5;
      request = 4;
      break;
    }
    case 1:
    default: {
      cmd = 3;
      request = 2;
      break;
    }
  }
  args[0] = durationShift;
  args[1] = r5, args[2] = g5, args[3] = b5;
  args[4] = bgRowMask;
  MapPltt_PushCommand(cmd, 5, args);
  args[4] = objSkipMask;
  Entity6978_SetRequest(request, 5, args);
}

// 0x0CD4, (x, z) のタイルの足元の高さをスクリプトの変数へ書き出して返す
// 残差: 命令列はほぼ一致, 原典は pos を sp+0, desc を sp+8 に置いて desc のアドレスを r5 に持つが, こちらは逆の並びになり pos のアクセスが1命令ずつ増える
NON_MATCH s32 Cmd_0CD4(void) {
#ifdef NONMATCHING_C
  WorldPos pos;
  u8 desc[8];
  s32 height;

  pos.x = VM_GetValue();
  pos.y = 0;
  pos.z = VM_GetValue();
  height = TileHeightAt(&pos);
  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, height);
  return height;
#else
  INCFUNC("asm/func/Cmd_0CD4.inc");
#endif
}

// 0xA39F, (x, z) のタイルの階段の種類をスクリプトの変数へ書き出して返す
// 残差: 命令列はほぼ一致, 原典は pos を sp+0, desc を sp+8 に置いて desc のアドレスを r5 に持つが, こちらは逆の並びになり pos のアクセスが1命令ずつ増える
NON_MATCH s32 Cmd_A39F(void) {
#ifdef NONMATCHING_C
  WorldPos pos;
  u8 desc[8];
  s32 stairs;

  pos.x = VM_GetValue();
  pos.y = 0;
  pos.z = VM_GetValue();
  stairs = GetTileAt(&pos)->heightStairs >> 4;
  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, stairs);
  return stairs;
#else
  INCFUNC("asm/func/Cmd_A39F.inc");
#endif
}

// 0x4B41, (x, z) のタイルの attr をスクリプトの変数へ書き出して返す
// 残差: 命令列はほぼ一致, 原典は pos を sp+0, desc を sp+8 に置いて desc のアドレスを r5 に持つが, こちらは逆の並びになり pos のアクセスが1命令ずつ増える
NON_MATCH s32 Cmd_4B41(void) {
#ifdef NONMATCHING_C
  WorldPos pos;
  u8 desc[8];
  TileAttr attr;

  pos.x = VM_GetValue();
  pos.y = 0;
  pos.z = VM_GetValue();
  attr = GetTileAttrAt(&pos);
  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, attr);
  return attr;
#else
  INCFUNC("asm/func/Cmd_4B41.inc");
#endif
}

// 0xAB41, タイル索引の中心の座標 (y は足元の高さ) をスクリプトの変数3つへ書き出す, 範囲外なら全部 0
// 残差: 命令列はほぼ一致, 原典は pos を sp+0, desc を sp+8 に置いて desc のアドレスを r5 に持つが, こちらは逆の並びになり pos のアクセスが1命令ずつ増える
NON_MATCH s32 Cmd_AB41(void) {
#ifdef NONMATCHING_C
  WorldPos pos;
  u8 desc[8];
  s32 idx = VM_GetValue();
  CollisionMapTileData* td = gCollisionMap->tiledata;

  if (td == NULL) {
    return 0;
  }

  if (idx >= td->width * td->height) {
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
  } else {
    pos.x = (Mod(idx, td->width) << 8) + 0x80;
    pos.z = (Div(idx, td->width) << 8) + 0x80;
    pos.y = TileHeightAtIndex(idx, &pos);
  }

  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, pos.x);
  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, pos.y);
  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, pos.z);
  return 0;
#else
  INCFUNC("asm/func/Cmd_AB41.inc");
#endif
}

// 0xEDE2, HashName("BG非表示"), 指定した BG を隠す
void Cmd_HideBG(void) {
  u16 mask = DISPCNT_BG0_ON << (u16)VM_GetValue();

  gStagedDISPCNT &= ~mask;
}

// 0x1500, HashName("BG表示"), 指定した BG を表示する
void Cmd_ShowBG(void) {
  u16 mask = DISPCNT_BG0_ON << (u16)VM_GetValue();

  gStagedDISPCNT |= mask;
}

// 0x138E
void Cmd_SoftReset(void) { GameSystem_SoftReset(); }

// 画面と音を落としてスリープに入り, 復帰したら元に戻す
void SleepGame(void) {
  REG_DISPCNT |= DISPCNT_FORCED_BLANK;
  WaitForVBlank();
  WaitForVBlank();
  REG_KEYCNT = KEY_AND_INTR | KEY_INTR_ENABLE | L_BUTTON | R_BUTTON | SELECT_BUTTON;
  Stop();
  gSaveSucceeded = TRUE;
  REG_DISPCNT &= ~DISPCNT_FORCED_BLANK;
  REG_KEYCNT = 0;
  WaitForVBlank();
}

// セーブデータを読み直し, 成功したらメッセージ速度と太陽センサーのキャリブレーションを既定値に戻す
// 残差2命令, 原典は戻り値の u8 マスクを r2 に残して 0 の store に使い回すが
// agbcc は lsls のフラグだけ使って別に movs r2, #0 を作る (戻り値型 s32/u8 と局所変数 s32/u8 の4通り試済)
NON_MATCH void FUN_0823d280(void) {
#ifdef NONMATCHING_C
  if (gSystemSaveData != NULL) {
    u8 err = Save_ReadSystemData();

    if (err == 0) {
      gStat->textSpeed = 5;
      gSystemSaveData->calibration = 0xE6;
      gSystemSaveData->currentSlot = 0;
      gSystemSaveData->unk_09 = 0;
      gSystemSaveData->unk_0a = 0;
    }
  }
#else
  INCFUNC("asm/func/FUN_0823d280.inc");
#endif
}

// 0x6487
void Cmd_6487(void) { gGrayscaleTimer = VM_GetNamedArgValue('t', 0); }

// 0x686E
void Cmd_686E(void) { gGrayscaleTimer = 0; }

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

static void UNUSED nop_0823d33c(void) {}

u8* VM_GetPC_Proxy(void) { return VM_GetPC(); }

void* VM_GetValueSafe2_Proxy(void) { return VM_GetValueSafe2(); }

// 0x81C4, スクリプトの変数へフレームカウンタを書き出す
void Cmd_81C4(void) {
  u8 desc[8];

  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, gSystemSaveData->frameCounter);
}

// 0x4CCD, プレイ時間の時と分をスクリプトの変数へ書き出す (先頭は 0)
void Cmd_4CCD(void) {
  u8 desc[8];
  s32 t;
  s32 min;

  t = Div(gSystemSaveData->frameCounter, 60);
  Mod(t, 60);
  t = Div(t, 60);
  min = Mod(t, 60);
  t = Div(t, 60);
  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, 0);
  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, t);
  VM_GetMemoryRef(desc);
  VM_StoreMemoryRef(desc, 0, min);
}

// 0xAE4E
void Cmd_AE4E(void) { SystemSave_SetUnk09(1); }

// 0x3C48
u32 Cmd_3C48(void) { return gSystemSaveData->unk_09; }

// 0x3E93
u32 Cmd_3E93(void) { return gSystemSaveData->unk_0a; }

const WeaponData* ReadWeaponDB(weapon32_t weaponID) { return &gWeaponDB[weaponID]; }

// 0x7806
void Cmd_7806(void) {
  s32 tilemapID = VM_GetNamedArgValue('b', 0);
  s32 bgIndices[1];
  s32 plttID;

  bgIndices[0] = VM_GetNamedArgValue('i', 0);
  plttID = VM_GetNamedArgValue('p', 0);
  Video_SetupBGLayout(0, 0, GetFile(DIR_TILE_MAP, tilemapID), 0, 0, 1, bgIndices);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  if (plttID != 0) {
    CpuCopy16(&GetBgPlttFile(plttID)->body[208], &gBgPlttBuffer[208], 96);
  }
}

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

// 赤と黒のフォームで過ごしたフレーム数の比から side を決めて返す
s32 UpdateSolDarkSide(void) {
  s32 total;
  s32 ratio;
  s32 side;

  if (gStat->solarFormFrames == 0) {
    gStat->solarFormFrames = 1;
  }
  if (gStat->darkFormFrames == 0) {
    gStat->darkFormFrames = 1;
  }
  total = gStat->darkFormFrames + gStat->solarFormFrames;
  if (total == 0) {
    total = 1;
  }
  ratio = Div(gStat->solarFormFrames << 7, total);
  if (ratio > 70) {
    side = 0;
  } else if (ratio > 58) {
    side = 2;
  } else {
    side = 1;
  }

  gStat->side = side;
  return side;
}

// 武器ごとの使用フレーム数から一番多い攻撃種別を style に入れて返す, 同数で並んだら 5
s32 UpdateWeaponStyle(void) {
  s32 i;
  s32 counts[5];
  s32 max;
  s32 style;

  for (i = 0; i < 5; i++) {
    counts[i] = Div(WEAPON_FRAMES(i), 54000);
  }

  max = 0;
  style = 5;
  for (i = 0; i < 5; i++) {
    if (counts[i] > max) {
      max = counts[i];
      style = i;
    } else if (counts[i] == max) {
      style = 5;
    }
  }

  gStat->style = style;
  return style;
}

// 0xA285, friendship が一番大きい添字を返す
s32 Cmd_GetBestFriend(void) {
  s32 best = 0;
  s32 bestVal = -100;
  s32 i;

  for (i = 0; i < 5; i++) {
    if (gStat->friendship[i] > bestVal) {
      bestVal = gStat->friendship[i];
      best = i;
    }
  }

  return best;
}

// プレイヤーが通常の操作を受け付ける状態か (イベント中でなく, 変身中や特殊なステータス中でなく, 立ち止まり / 歩き / 太陽チャージ中)
// 残差: 原典は最後の action の判定を 0/1 の値に起こしてから比べ直し, オフセットの定数を r1 に積んで 0x446 から 0x442 を subs で作る
NON_MATCH bool32 Player_CanTalk(void) {
#ifdef NONMATCHING_C
  Player* player = gPlayerPtr[0];

  if (player == NULL) {
    return FALSE;
  }
  if (gGameFlags & GAMEFLAG_EVENT) {
    return FALSE;
  }
  if (!TEST_FLAGS(gPlayerModes[0], PMODE_ACTIVE)) {
    return FALSE;
  }
  if (player->kind == PLAYER_BAT || player->kind == PLAYER_MOUSE || player->kind == PLAYER_SLEEPING) {
    return FALSE;
  }
  if (player->formRequest) {
    return FALSE;
  }
  if (player->goodCondTimer != 0 && (player->goodCondID == GOOD_MINI || player->goodCondID == GOOD_INVISIBLE)) {
    return FALSE;
  }
  if (player->action <= PACT_WALK || player->action == PACT_UNK_7) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/Player_CanTalk.inc");
#endif
}

// 0xDAA4
u32 Cmd_GetPrefecture(void) { return gSystemSaveData->prefecture; }

// 0xED2E, クロスオーバーバトルが解放されているか
// タイトル画面 -> "LINK" -> "通信対戦"にカーソルを当てて、 L,R,L,R,L,L,R,R,R,R,L,L,SELECT,START,SELECT,START と入力するとクロスオーバーバトルが解放される
bool32 Cmd_IsCrossoverUnlocked(void) {
  if (gSystemSaveData->crossoverUnlocked == 0x369F) {
    return TRUE;
  }
  return FALSE;
}

// 0xB45F
s32 Cmd_GetCrossoverPoint(void) { return gSystemSaveData->crossoverPoint; }

// 0x904B
s32 Cmd_SetCrossoverPoint(void) {
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
u16 Cmd_GetCrossoverBattleCount(void) { return gSystemSaveData->crossoverCount; }

// 0x3F3B
u16 Cmd_GetCrossoverBattleWins(void) { return gSystemSaveData->crossoverWins; }

// 0x058D, '.s' の文字列のIDを覚えておく
void Cmd_058D(void) {
  if (VM_SeekToNamedArg('s')) {
    u8* pc = VM_GetPC();

    if (pc != NULL) {
      char* str = GetStringByID(VM_ParseStringRef(pc));

      gSilentCharcode = (str[1] | (str[0] << 8)) & 0xFFF;
    }
  }
}

// 0x5CC4
void Cmd_5CC4(void) { gStat->mapInitScriptID = VM_GetValue(); }
