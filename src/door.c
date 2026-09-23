#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "vm.h"

void* FUN_08230e70(u16 id);

struct Door;
typedef void (*DoorFunc)(struct Door* p);

// 扉1体。DoorManager.doors が doorMax 体ぶん並べて持つ
typedef struct Door {
  AuxSprite sprite;  // 0x00, DoorManager_Destroy が AuxSprite_Remove に渡す
  void* unk_2c;      // 0x2C, DoorManager_Destroy が NULL でなければ Free する
  DoorFunc fn;       // 0x30, FUN_08020AF8 が FUN_08020B88 を、FUN_08020B24 が別のハンドラを入れる
  u8 unk_34[44];     // 0x34, 0x37/0x39/0x3A/0x3B/0x3E/0x40 に読み書きがあるが、0x38 の ldr とそれらの strb が重なっていて境界が決まらない
  s32 unk_60;        // 0x60, FUN_08020CD8 / FUN_08020D10 が読み書きする
  s32 scriptID;      // 0x64, FUN_08020D10 が Script_ExecById に渡してから 0 を入れる
  u8 unk_68[24];     // 0x68, 0x72 の strh と 0x7A の ldrh がある
  u16 unk_80;        // 0x80, FUN_08020B88 が +0xF、FUN_08020C1C が -0xF する
  s16 unk_82;        // 0x82, FUN_08020D10 が ldrsh で読んで減らす
  u8 unk_84[8];      // 0x84, 0x84 の ldrb と 0x88 の ldrh がある
} Door;
static_assert(sizeof(Door) == 140);

// script 'k' の扉の絵一式を複製して入れる置き場。DoorManager_Init が Malloc(0x8C) で7個作る
typedef struct {
  AuxSpriteGfx gfx[5];
} DoorSpriteSet;
static_assert(sizeof(DoorSpriteSet) == 140);

// AuxSpriteGfx 5枚 x 7 種類の扉グラフィックを持ち、doorMax 体ぶんの扉の実体を管理するシングルトン
// スクリプトのキーワードごとに種類が対応する: 'd'=木の扉 / 'S'=鉄格子 / 'k' / 'b' / 's' / 'u'
typedef struct {
  Entity e;                     // 0x00, ENTITY_UNK_9
  u16 subroutineID;             // 0x18, DoorManager_Update が FUN_08230F94 の検索キーに使う
  u16 unk_1a;                   // 0x1A, DoorManager_Destroy が doors を走査する件数
  u8 unk_1c;                    // 0x1C, DoorManager_Update が unk_1e を走査する件数。走査後 unk_1d へ移して 0 に戻す
  u8 unk_1d;                    // 0x1D, 前フレームの unk_1c
  u16 unk_1e[4];                // 0x1E, _Init が 0x24 から 0x1E へ順に 0 で埋める。_Update が unk_1c 件ぶん走査する
  u8 unk_26[8];                 // 0x26, 読み手も書き手も見つかっていない
  u16 unk_2e;                   // 0x2E, _Init が 0 を入れる
  s32 doorMax;                  // 0x30, VM_GetKeywordValue('m', 16)。doors の要素数
  s32 unk_34;                   // 0x34, VM_GetKeywordValue('e', 1)。0 でなければ 0x410..0x428 も確保する
  ScriptRecord* records;        // 0x38, FUN_08230F94(subroutineID, &records) の出力。_Update が values[0] を命令として分岐する
  AuxSpriteGfx sprites_3c[5];   // 0x3C, script 'd' (既定 DOOR_7ACD)
  AuxSpriteGfx sprites_c8[5];   // 0xC8, script 'S' (既定 DOOR_IRON)
  AuxSpriteGfx sprites_154[5];  // 0x154, script 'k' (既定 DOOR_7AD3)
  AuxSpriteGfx sprites_1e0[5];  // 0x1E0, script 'b' (既定 DOOR_7AD3 / 0x7AEE)、sprites_26c と対で埋める
  AuxSpriteGfx sprites_26c[5];  // 0x26C, script 'b'
  AuxSpriteGfx sprites_2f8[5];  // 0x2F8, script 's' (既定 0x7AF3)
  AuxSpriteGfx sprites_384[5];  // 0x384, script 'u' (既定 0x7AF3)
  DoorSpriteSet* unk_410;       // 0x410, unk_34 が 0 でなければ Malloc(0x8C)。script 'k' の絵を複製して入れる
  DoorSpriteSet* unk_414;       // 0x414
  DoorSpriteSet* unk_418;       // 0x418
  DoorSpriteSet* unk_41c;       // 0x41C
  DoorSpriteSet* unk_420;       // 0x420
  DoorSpriteSet* unk_424;       // 0x424
  DoorSpriteSet* unk_428;       // 0x428
  Door* doors;                  // 0x42C, Malloc(doorMax * 0x8C)
  u8 unk_430[4];                // 0x430, 読み手も書き手も見つかっていない
} DoorManager;
static_assert(sizeof(DoorManager) == 1076);

NAKED void FUN_0801f764(DoorManager* p) { INCFUNC("asm/func/FUN_0801f764.inc"); }

NAKED void FUN_0801f7f4(DoorManager* p) { INCFUNC("asm/func/FUN_0801f7f4.inc"); }

NAKED void FUN_0801f858(DoorManager* p) { INCFUNC("asm/func/FUN_0801f858.inc"); }

NAKED s32 FUN_0801f8e8(DoorManager* p, u16 param_2, Vec3* param_3, u32 param_4, u8 param_5, u8 param_6, u8 param_7, u8 param_8, u16 param_9, u32 param_10, u8 param_11, unknown* param_12, u8 param_13) { INCFUNC("asm/func/FUN_0801f8e8.inc"); }

NAKED s32 FUN_0801faa8(DoorManager* p, s16 param_2) { INCFUNC("asm/func/FUN_0801faa8.inc"); }

NAKED s32 FUN_0801fad8(DoorManager* p, s16 param_2) { INCFUNC("asm/func/FUN_0801fad8.inc"); }

NAKED bool32 FUN_0801fb08(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_0801fb08.inc"); }

NAKED s32 FUN_0801fb48(void) { INCFUNC("asm/func/FUN_0801fb48.inc"); }

NAKED void FUN_0801fc88(DoorManager* p, s16 param_2) { INCFUNC("asm/func/FUN_0801fc88.inc"); }

NAKED void FUN_0801fd10(DoorManager* p, s16 param_2) { INCFUNC("asm/func/FUN_0801fd10.inc"); }

NAKED void FUN_0801fd88(DoorManager* p, s16 param_2) { INCFUNC("asm/func/FUN_0801fd88.inc"); }

NAKED void FUN_0801fdf0(DoorManager* p, s16 param_2) { INCFUNC("asm/func/FUN_0801fdf0.inc"); }

NAKED void FUN_0801fe58(DoorManager* p, s16 param_2) { INCFUNC("asm/func/FUN_0801fe58.inc"); }

NAKED void FUN_0801fe98(DoorManager* p, s16 param_2) { INCFUNC("asm/func/FUN_0801fe98.inc"); }

NAKED s32 FUN_0801fedc(void) { INCFUNC("asm/func/FUN_0801fedc.inc"); }

NAKED s32 FUN_0801ff78(void) { INCFUNC("asm/func/FUN_0801ff78.inc"); }

NAKED s32 FUN_08020010(void) { INCFUNC("asm/func/FUN_08020010.inc"); }

NAKED s32 FUN_080200f0(void) { INCFUNC("asm/func/FUN_080200f0.inc"); }

NAKED void FUN_080201c8(void) { INCFUNC("asm/func/FUN_080201c8.inc"); }

NAKED void FUN_08020260(void) { INCFUNC("asm/func/FUN_08020260.inc"); }

void FUN_08020314(void) {
  DoorManager* p = FUN_08230e70(0x85E6);
  if (p == NULL) {
    return;
  }
  if (VM_SeekToKeyword('n') == 0) {
    return;
  }
  p->unk_2e = Script_GetValue();
}

void FUN_0802033c(void) {
  DoorManager* p = FUN_08230e70(0x85E6);
  if (p != NULL) {
    p->unk_2e = 0;
  }
}

NAKED s32 FUN_08020358(u32 param_1) { INCFUNC("asm/func/FUN_08020358.inc"); }

NAKED void FUN_080203a4(DoorManager* p, AuxSprite* sprite) { INCFUNC("asm/func/FUN_080203a4.inc"); }

NAKED void FUN_08020680(DoorManager* p) { INCFUNC("asm/func/FUN_08020680.inc"); }

void FUN_080206b0(void) {}

void FUN_080206b4(void) {}

NAKED void FUN_080206b8(Door* door) { INCFUNC("asm/func/FUN_080206b8.inc"); }

NAKED void FUN_08020734(Door* door) { INCFUNC("asm/func/FUN_08020734.inc"); }

NAKED void FUN_080207b0(DoorManager* p, AuxSprite* sprite) { INCFUNC("asm/func/FUN_080207b0.inc"); }

NAKED void FUN_08020af8(Door* door) { INCFUNC("asm/func/FUN_08020af8.inc"); }

NAKED void FUN_08020b24(Door* door) { INCFUNC("asm/func/FUN_08020b24.inc"); }

NAKED void FUN_08020b88(Door* door) { INCFUNC("asm/func/FUN_08020b88.inc"); }

NAKED void FUN_08020c1c(Door* door) { INCFUNC("asm/func/FUN_08020c1c.inc"); }

NAKED void FUN_08020cd8(Door* door) { INCFUNC("asm/func/FUN_08020cd8.inc"); }

NAKED void FUN_08020d10(Door* door) { INCFUNC("asm/func/FUN_08020d10.inc"); }

NAKED void FUN_08020d44(DoorManager* p, AuxSprite* sprite) { INCFUNC("asm/func/FUN_08020d44.inc"); }

void FUN_0802108c(void) {}

void FUN_08021090(void) {}

NAKED s32 DoorManager_Update(DoorManager* p) { INCFUNC("asm/func/DoorManager_Update.inc"); }

NAKED s32 DoorManager_Destroy(DoorManager* p) { INCFUNC("asm/func/DoorManager_Destroy.inc"); }

NAKED s32 DoorManager_Init(DoorManager* p, u32 subroutineID, unknown* param_3) { INCFUNC("asm/func/DoorManager_Init.inc"); }

NAKED DoorManager* DoorManager_Create(u32 subroutineID, unknown* param_2) { INCFUNC("asm/func/DoorManager_Create.inc"); }
