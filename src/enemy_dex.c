#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "text.h"
#include "vm.h"

struct EntityC946;

// _Init が '.t' から4バイトずつ57件読む
typedef struct {
  u8 unk_0;  // 0x00
  u8 unk_1;  // 0x01
  u8 unk_2;  // 0x02
  u8 unk_3;  // 0x03
} EnemyDexEntry;
static_assert(sizeof(EnemyDexEntry) == 4);

// 魔物図鑑のメニュー, スクリプトのキーワードから表示内容を組み立てる
typedef struct {
  Entity e;                   // 0x0000, ENTITY_UNK_8
  u8 unk_18[8];               // 0x0018
  u32 unk_20;                 // 0x0020, _Init が 0
  u8 unk_24;                  // 0x0024, _Init が 0
  u8 unk_25;                  // 0x0025, _Init が 0
  u8 unk_26;                  // 0x0026, _Init が 0
  u8 unk_27;                  // 0x0027
  s32 panels[8];              // 0x0028, TextPanel_Create の戻り値 (ID), TextPanel_Hide などに渡す
  u8 unk_48;                  // 0x0048, _Init が 0
  u8 unk_49;                  // 0x0049, _Init が 0x20
  u8 unk_4a;                  // 0x004A, _Init が 0
  u8 unk_4b[0x8E - 0x4B];     // 0x004B
  u16 unk_8e;                 // 0x008E, FUN_0820ed38 が unk_48 * 16 + 8 を書く
  u8 unk_90[0x110C - 0x90];   // 0x0090
  u16 unk_110c;               // 0x110C, _Init が 0
  u16 unk_110e;               // 0x110E, _Init が 5
  void* scriptN;              // 0x1110, '.n', TextPanel_SetScript に渡す
  u8 unk_1114[57];            // 0x1114, '.d' の Script_GetValue を57バイト
  u8 unk_114d[3];             // 0x114D
  EnemyDexEntry entries[57];  // 0x1150, '.t'
  void* scriptI;              // 0x1234, '.i'
  void* scriptP;              // 0x1238, '.p'
  void* scriptS;              // 0x123C, '.s'
  void* scriptW;              // 0x1240, '.w'
  void* scriptA_upper;        // 0x1244, '.A'
  void* scriptA;              // 0x1248, '.a'
  void* scriptM;              // 0x124C, '.m'
  void* scriptU;              // 0x1250, '.u'
  void* scriptT_upper;        // 0x1254, '.T'
  u32 unk_1258;               // 0x1258, '.e=0'
  struct EntityC946* sub;     // 0x125C, EntityC946_Create(0, 0) の戻り値
} EnemyDexMenu;
static_assert(sizeof(EnemyDexMenu) == 4704);

void ClearBGTilemapBuffer(s32 bg);
s32 FUN_0820cbfc(u32 param_1);
s32 FUN_0820cc0c(u32 param_1);

NAKED s32 FUN_0820d00c(u32 param_1) { INCFUNC("asm/func/FUN_0820d00c.inc"); }

NAKED s32 FUN_0820d04c(u32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_0820d04c.inc"); }

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

NAKED bool32 FUN_0820d0ec(void) { INCFUNC("asm/func/FUN_0820d0ec.inc"); }

void FUN_0820d124(void) {
  if (VM_SeekToKeyword('k')) {
    Script_GetValue();
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

NAKED void FUN_0820ed04(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820ed04.inc"); }

void FUN_0820ed38(EnemyDexMenu* p) { p->unk_8e = p->unk_48 * 16 + 8; }

NAKED void FUN_0820ed48(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820ed48.inc"); }

NAKED void FUN_0820ede8(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820ede8.inc"); }

NAKED void FUN_0820ee7c(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820ee7c.inc"); }

NAKED void FUN_0820eeb8(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820eeb8.inc"); }

NAKED void FUN_0820efc4(u8 param_1, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0820efc4.inc"); }

NAKED void FUN_0820f020(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820f020.inc"); }

NAKED void FUN_0820f130(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820f130.inc"); }

NAKED void FUN_0820f1e0(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820f1e0.inc"); }

NAKED void FUN_0820f310(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820f310.inc"); }

NAKED void FUN_0820f3e4(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820f3e4.inc"); }

NAKED void FUN_0820f4b4(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820f4b4.inc"); }

NAKED void FUN_0820f630(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820f630.inc"); }

NAKED void FUN_0820f700(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820f700.inc"); }
