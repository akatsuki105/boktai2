#include "entity.h"
#include "global.h"

struct TextPanel;
struct EntityC946;

// _Init がスクリプトキーワード 't' から4バイトずつ57件読む
typedef struct {
  u8 unk_0;  // 0x00
  u8 unk_1;  // 0x01
  u8 unk_2;  // 0x02
  u8 unk_3;  // 0x03
} EnemyDexEntry;
static_assert(sizeof(EnemyDexEntry) == 4);

// 敵図鑑のメニュー。スクリプトのキーワードから表示内容を組み立てる
typedef struct {
  Entity e;                        // 0x0000, ENTITY_UNK_8
  u8 unk_18[8];                    // 0x0018
  u32 unk_20;                      // 0x0020, _Init が 0
  u8 unk_24;                       // 0x0024, _Init が 0
  u8 unk_25;                       // 0x0025, _Init が 0
  u8 unk_26;                       // 0x0026, _Init が 0
  u8 unk_27;                       // 0x0027
  struct TextPanel* panels[8];     // 0x0028, _Init が TextPanel_Create を8回まわして詰める
  u8 unk_48;                       // 0x0048, _Init が 0
  u8 unk_49;                       // 0x0049, _Init が 0x20
  u8 unk_4a;                       // 0x004A, _Init が 0
  u8 unk_4b[0x110C - 0x4B];        // 0x004B
  u16 unk_110c;                    // 0x110C, _Init が 0
  u16 unk_110e;                    // 0x110E, _Init が 5
  void* scriptN;                   // 0x1110, キーワード 'n'。TextPanel_SetScript に渡す
  u8 unk_1114[57];                 // 0x1114, キーワード 'd' の Script_GetValue を57バイト
  u8 unk_114d[3];                  // 0x114D
  EnemyDexEntry entries[57];       // 0x1150, キーワード 't'
  void* scriptI;                   // 0x1234, キーワード 'i'
  void* scriptP;                   // 0x1238, キーワード 'p'
  void* scriptS;                   // 0x123C, キーワード 's'
  void* scriptW;                   // 0x1240, キーワード 'w'
  void* scriptA_upper;             // 0x1244, キーワード 'A'
  void* scriptA;                   // 0x1248, キーワード 'a'
  void* scriptM;                   // 0x124C, キーワード 'm'
  void* scriptU;                   // 0x1250, キーワード 'u'
  void* scriptT_upper;             // 0x1254, キーワード 'T'
  u32 unk_1258;                    // 0x1258, VM_GetKeywordValue('e', 0)
  struct EntityC946* sub;          // 0x125C, EntityC946_Create(0, 0) の戻り値
} EnemyDexMenu;
static_assert(sizeof(EnemyDexMenu) == 4704);

NAKED s32 FUN_0820d00c(u32 param_1) { INCFUNC("asm/func/FUN_0820d00c.inc"); }

NAKED s32 FUN_0820d04c(u32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_0820d04c.inc"); }

NAKED s32 FUN_0820d084(u32 param_1) { INCFUNC("asm/func/FUN_0820d084.inc"); }

NAKED s32 FUN_0820d0b8(u32 param_1) { INCFUNC("asm/func/FUN_0820d0b8.inc"); }

NAKED bool32 FUN_0820d0ec(void) { INCFUNC("asm/func/FUN_0820d0ec.inc"); }

NAKED void FUN_0820d124(void) { INCFUNC("asm/func/FUN_0820d124.inc"); }

NAKED void FUN_0820d138(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d138.inc"); }

NAKED void FUN_0820d188(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d188.inc"); }

NAKED void FUN_0820d21c(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d21c.inc"); }

NAKED void FUN_0820d250(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d250.inc"); }

NAKED void FUN_0820d5f8(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d5f8.inc"); }

NAKED void FUN_0820d690(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d690.inc"); }

NAKED s32 FUN_0820d6e4(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820d6e4.inc"); }

NAKED s32 FUN_0820dae4(EnemyDexMenu* p, u32 param_2) { INCFUNC("asm/func/FUN_0820dae4.inc"); }

NAKED void FUN_0820db9c(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820db9c.inc"); }

NAKED void FUN_0820e080(EnemyDexMenu* p, u8 param_2) { INCFUNC("asm/func/FUN_0820e080.inc"); }

NAKED s32 EnemyDexMenu_Update(EnemyDexMenu* p) { INCFUNC("asm/func/EnemyDexMenu_Update.inc"); }

NAKED void FUN_0820e75c(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820e75c.inc"); }

NAKED s32 EnemyDexMenu_Destroy(EnemyDexMenu* p) { INCFUNC("asm/func/EnemyDexMenu_Destroy.inc"); }

NAKED s32 EnemyDexMenu_Init(EnemyDexMenu* p, u32 val) { INCFUNC("asm/func/EnemyDexMenu_Init.inc"); }

NAKED EnemyDexMenu* EnemyDexMenu_Create(u32 val) { INCFUNC("asm/func/EnemyDexMenu_Create.inc"); }

NAKED void FUN_0820eb38(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820eb38.inc"); }

NAKED void FUN_0820eb84(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820eb84.inc"); }

NAKED void FUN_0820ec6c(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820ec6c.inc"); }

NAKED void FUN_0820ed04(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820ed04.inc"); }

NAKED void FUN_0820ed38(EnemyDexMenu* p) { INCFUNC("asm/func/FUN_0820ed38.inc"); }

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
