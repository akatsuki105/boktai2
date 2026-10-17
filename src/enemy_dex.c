#include "entity.h"
#include "global.h"
#include "preview_stage.h"
#include "sprite.h"
#include "text.h"
#include "video.h"
#include "vm.h"

// _Init が '.t' から4バイトずつ57件読む
typedef struct {
  u8 unk_0;  // 0x00
  u8 unk_1;  // 0x01
  u8 unk_2;  // 0x02
  u8 unk_3;  // 0x03
} EnemyDexEntry;
static_assert(sizeof(EnemyDexEntry) == 4);

// 魔物図鑑
typedef struct {
  Entity e;                    // 0x0000, ENTITY_UNK_8
  u8 unk_18[8];                // 0x0018
  u32 unk_20;                  // 0x0020, _Init が 0
  u8 unk_24;                   // 0x0024, _Init が 0
  u8 unk_25;                   // 0x0025, _Init が 0
  u8 unk_26;                   // 0x0026, _Init が 0
  u8 unk_27;                   // 0x0027
  s32 panels[8];               // 0x0028, TextPanel_Create の戻り値 (ID), TextPanel_Hide などに渡す
  u8 unk_48;                   // 0x0048, _Init が 0
  u8 unk_49;                   // 0x0049, _Init が 0x20
  u8 unk_4a;                   // 0x004A, _Init が 0
  u8 unk_4b[0x8E - 0x4B];      // 0x004B
  u16 unk_8e;                  // 0x008E, FUN_0820ed38 が unk_48 * 16 + 8 を書く
  u8 unk_90[0x18C - 0x90];     // 0x0090
  MainSprite sprites_18c[5];   // 0x018C, 根拠: FUN_0820d6e4 が5枚ぶん登録し FUN_0820ee7c が5枚ぶん隠す
  MainSprite sprites_36c[3];   // 0x036C, 根拠: FUN_0820ee7c が3枚ぶん隠す
  u8 unk_48c[0xD8C - 0x48C];   // 0x048C
  MainSprite sprites_d8c[4];   // 0x0D8C, 根拠: EnemyDexMenu_HideSprites が 0xD94 と 0xE54 から 0x60 刻みで flags を触る
  u8 unk_f0c[0x110C - 0xF0C];  // 0x0F0C
  u16 unk_110c;                // 0x110C, _Init が 0
  u16 unk_110e;                // 0x110E, _Init が 5
  void* scriptN;               // 0x1110, '.n', TextPanel_SetScript に渡す
  u8 unk_1114[57];             // 0x1114, '.d' の VM_GetValue を57バイト
  u8 unk_114d[3];              // 0x114D
  EnemyDexEntry entries[57];   // 0x1150, '.t'
  void* scriptI;               // 0x1234, '.i'
  void* scriptP;               // 0x1238, '.p'
  void* scriptS;               // 0x123C, '.s'
  void* scriptW;               // 0x1240, '.w'
  void* scriptA_upper;         // 0x1244, '.A'
  void* scriptA;               // 0x1248, '.a'
  void* scriptM;               // 0x124C, '.m'
  void* scriptU;               // 0x1250, '.u'
  void* scriptT_upper;         // 0x1254, '.T'
  u32 unk_1258;                // 0x1258, '.e=0'
  PreviewStage* sub;           // 0x125C, PreviewStage_Create(0, 0) の戻り値
} EnemyDexMenu;
static_assert(sizeof(EnemyDexMenu) == 4704);

s32 FUN_0820cbfc(u32 param_1);
s32 FUN_0820cc0c(u32 param_1);

static const s32 sEnemyDexPageStarts[9] = {0, 7, 14, 21, 27, 34, 41, 48, 50};  // ページの先頭エントリ番号 (sEnemyDexPageEntryCounts の累積和), 0x085AF034
static const s32 sEnemyDexPageEntryCounts[9] = {7, 7, 7, 6, 7, 7, 7, 2, 7};    // ページごとのエントリ数(ビースト1,ビースト2,ビースト3,アンデット,シング1,シング2,ファントム1,ファントム2,イモータル), 合計57, 0x085AF058
static const s32 sEnemyDexCategoryCounts[5] = {21, 6, 14, 9, 7};               // 種族ごとのエントリ数 (ビースト,アンデット,シング,ファントム,イモータル), 0x085AF07C

// 魔物図鑑メニューの UI スプライトのポーズ番号, FUN_0820d6e4 が EnemyDexMenu+0x18C から5枚を登録するループで引く
static const u32 sEnemyDexUIPoses1[5] = {17, 18, 19, 20, 21};  // 0x085AF090

// 同上, EnemyDexMenu+0x36C から3枚
static const u32 sEnemyDexUIPoses2[3] = {1, 2, 3};  // 0x085AF0A4

INCASM("asm/enemy_dex.inc");

// 魔物 bit に出会っているか
// 残差はレジスタ番号の入れ替えのみ (r2/r3 が逆, 命令列は 29 対 29)
NON_MATCH bool32 FUN_0820d00c(s32 bit) {
#ifdef NONMATCHING_C
  u32* seen = gStat->enemyDexSeen;

  if (seen[Div32(bit)] & (1 << (bit & 0x1F))) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_0820d00c.inc");
#endif
}

// 魔物 id の種別 kind のフラグが立っているか
// 残差はレジスタ番号の入れ替えのみ (r2/r3 と r1/r2, 命令列は 24 対 24)
NON_MATCH bool32 FUN_0820d04c(u32 id, u32 kind) {
#ifdef NONMATCHING_C
  u32* flags = gStat->enemyDexFlags;
  u32 bit = id * 2 + kind;

  if (flags[bit >> 5] & (1 << (bit & 31))) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_0820d04c.inc");
#endif
}

bool32 FUN_0820d084(u32 param_1) {
  s32 n = FUN_0820cbfc(param_1);
  s32 base = FUN_0820cc0c(param_1);
  s32 i;

  for (i = 0; i < n; i++) {
    if (!FUN_0820d00c(base + i)) {
      return FALSE;
    }
  }
  return TRUE;
}

s32 FUN_0820d0b8(u32 param_1) {
  s32 n = FUN_0820cbfc(param_1);
  s32 base = FUN_0820cc0c(param_1);
  s32 count = 0;
  s32 i;

  for (i = 0; i < n; i++) {
    if (FUN_0820d00c(base + i) == 1) {
      count++;
    }
  }
  return count;
}

// 57体すべてに出会っているか
// 残差はレジスタ番号の入れ替えのみ (大きいオフセットの一時値と加算先が r0/r1 で逆, 命令列は 23 対 23)
NON_MATCH bool32 FUN_0820d0ec(void) {
#ifdef NONMATCHING_C
  if (gStat->enemyDexSeen[0] == -1 && gStat->enemyDexSeen[1] == 0x01FFFFFF) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_0820d0ec.inc");
#endif
}

void FUN_0820d124(void) {
  if (VM_SeekToNamedArg('k')) {
    VM_GetValue();
  }
}

NAKED void FUN_0820d138(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d138.inc"); }

NAKED void FUN_0820d188(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d188.inc"); }

void FUN_0820d21c(EnemyDexMenu* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    TextPanel_Hide(p->panels[i]);
  }
  p->unk_110e |= 1;
  ClearBGTilemapBuffer(0);
}

NAKED void FUN_0820d250(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d250.inc"); }

NAKED void FUN_0820d5f8(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d5f8.inc"); }

NAKED void FUN_0820d690(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d690.inc"); }

NAKED s32 FUN_0820d6e4(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d6e4.inc"); }

NAKED s32 FUN_0820dae4(EnemyDexMenu* p, u32 param_2) { INCFUNC("asm/func/FUN_0820dae4.inc"); }

NAKED void FUN_0820db9c(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820db9c.inc"); }

void FUN_0820e080(EnemyDexMenu* p, u8 param_2) {
  p->unk_24 = param_2;
  p->unk_114d[0] = 0;
  FUN_0820dae4(p, p->unk_24);
  FUN_0820db9c(p);
}

NAKED s32 EnemyDexMenu_Update(EnemyDexMenu* p) { INCFUNC("asm/func/EnemyDexMenu_Update.inc"); }

void FUN_0820e75c(MainSprite* spr) {
  if (spr->active) {
    MainSprite_Remove(spr);
  }
}

NAKED s32 EnemyDexMenu_Destroy(EnemyDexMenu* p) { INCFUNC("asm/func/EnemyDexMenu_Destroy.inc"); }

NAKED s32 EnemyDexMenu_Init(EnemyDexMenu* p, u32 val) { INCFUNC("asm/func/EnemyDexMenu_Init.inc"); }

EnemyDexMenu* EnemyDexMenu_Create(u32 val) {
  EnemyDexMenu* p = CreateEntity(ENTITY_UNK_8, sizeof(EnemyDexMenu));

  if (p != NULL) {
    SetEntityRoutine(p, EnemyDexMenu_Update, EnemyDexMenu_Destroy);
    if (EnemyDexMenu_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED void FUN_0820eb38(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820eb38.inc"); }

NAKED void FUN_0820eb84(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820eb84.inc"); }

NAKED void FUN_0820ec6c(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820ec6c.inc"); }

// sprites_d8c を全部隠す
void EnemyDexMenu_HideSprites(EnemyDexMenu* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    p->sprites_d8c[i].flags |= SPRFLAG_HIDDEN;
    p->sprites_d8c[i + 2].flags |= SPRFLAG_HIDDEN;
  }
}

void FUN_0820ed38(EnemyDexMenu* p) { p->unk_8e = p->unk_48 * 16 + 8; }

NAKED void FUN_0820ed48(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820ed48.inc"); }

NAKED void FUN_0820ede8(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820ede8.inc"); }

// UIスプライトを全部隠す
void FUN_0820ee7c(EnemyDexMenu* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    p->sprites_18c[i].flags |= SPRFLAG_HIDDEN;
  }
  for (i = 0; i < 3; i++) {
    p->sprites_36c[i].flags |= SPRFLAG_HIDDEN;
  }
}

NAKED void FUN_0820eeb8(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820eeb8.inc"); }
