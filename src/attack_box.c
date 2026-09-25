#include "entity.h"
#include "hitbox.h"

#include "global.h"

// 持ち主のいない単発の攻撃判定。AttackBoxManager が5個を貸し出す
typedef struct {
  HitboxData hitbox;  // 0x00, AttackBox_Setup が Hitbox_Init / Hitbox_SetAttack / Hitbox_SetHandler に渡す
  Vec3 pos;           // 0x50, Hitbox_SetPos の第2引数。SpawnAttackBox が引数の Vec3 を8バイトまるごと写す
  u16 timer;          // 0x58, AttackBox_Update が毎フレーム +1。10..15 の間だけ Hitbox_Register し、0x28 を超えると state を 2 にする
  u8 unk_5a[2];       // 0x5A
  u8 kind;            // 0x5C, SpawnAttackBox の第2引数。FUN_080dd93c は 2 を入れる
  u8 state;           // 0x5D, PTR_ARRAY_085AD348 の添字。0: 空き, 1: 判定中, 2: 解放
  u8 slot;            // 0x5E, 自分の添字。Alloc が書き、解放時に activeMask の該当ビットを落として 0xFF にする
  u8 unk_5f;          // 0x5F
  u32 unk_60;         // 0x60, SpawnAttackBox の第3引数。0 かどうかで Hitbox_SetAttack の flags が変わる
} AttackBox;
static_assert(sizeof(AttackBox) == 100);

// 5枠の攻撃判定プール。敵やスクリプトが SpawnAttackBox で1枠借りる
typedef struct AttackBoxManager {
  Entity e;           // 0x00, ENTITY_UNK_10
  u32 activeMask;     // 0x18, 使用中の boxes のビットマスク
  AttackBox boxes[5]; // 0x1C, 根拠: _Update の stride 0x64 と AttackBox_Free の ClearMemory(box, 0x64)
} AttackBoxManager;
static_assert(sizeof(AttackBoxManager) == 528);

extern AttackBoxManager* gAttackBoxManager;  // 0x03000170

NAKED s32 FUN_080dd324(unknown* p) { INCFUNC("asm/func/FUN_080dd324.inc"); }

NAKED void FUN_080dd364(void) { INCFUNC("asm/func/FUN_080dd364.inc"); }

NAKED void FUN_080dd4fc(AttackBox* box) { INCFUNC("asm/func/FUN_080dd4fc.inc"); }

NAKED void FUN_080dd6f4(AttackBox* box) { INCFUNC("asm/func/FUN_080dd6f4.inc"); }

NAKED void AttackBox_Setup(AttackBox* box, s32 power, s32 unk_40, s32 unk_44, u16 ignoreMask) { INCFUNC("asm/func/AttackBox_Setup.inc"); }

NAKED void AttackBox_Idle(AttackBoxManager* p, AttackBox* box) { INCFUNC("asm/func/AttackBox_Idle.inc"); }

NAKED void AttackBox_Update(AttackBoxManager* p, AttackBox* box) { INCFUNC("asm/func/AttackBox_Update.inc"); }

NAKED void AttackBox_Free(AttackBoxManager* p, AttackBox* box) { INCFUNC("asm/func/AttackBox_Free.inc"); }

NAKED AttackBox* AttackBoxManager_Alloc(AttackBoxManager* p) { INCFUNC("asm/func/AttackBoxManager_Alloc.inc"); }

NAKED s32 SpawnAttackBox(Vec3* pos, u8 kind, u32 unk_60, s32 power, s32 unk_40, s32 unk_44, u16 ignoreMask) { INCFUNC("asm/func/SpawnAttackBox.inc"); }

NAKED void FUN_080dd93c(void) { INCFUNC("asm/func/FUN_080dd93c.inc"); }

NAKED s32 AttackBoxManager_Update(AttackBoxManager* p) { INCFUNC("asm/func/AttackBoxManager_Update.inc"); }

NAKED s32 AttackBoxManager_Destroy(AttackBoxManager* p) { INCFUNC("asm/func/AttackBoxManager_Destroy.inc"); }

NAKED void FUN_080ddab4(AttackBoxManager* p) { INCFUNC("asm/func/FUN_080ddab4.inc"); }

NAKED s32 AttackBoxManager_Init(AttackBoxManager* p, u32 unused1) { INCFUNC("asm/func/AttackBoxManager_Init.inc"); }

NAKED AttackBoxManager* AttackBoxManager_Create(void) { INCFUNC("asm/func/AttackBoxManager_Create.inc"); }

NAKED void FUN_080ddb1c(void) { INCFUNC("asm/func/FUN_080ddb1c.inc"); }

