#include "enemy.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"

// Enemy の共通部分?

// EntityD854 のリストにぶら下がるノード。登録側 (Player など) の構造体に埋め込まれている
typedef struct EntityD854Node {
  Entity2UnkData* owner;        // 0x00, FUN_080f8c58 の第2引数. FUN_080f8d60 が owner->id で検索する
  u8 flags;                     // 0x04, bit0=登録済み (FUN_080f8c58 が立てる), bit1=enemy と紐付き中 (FUN_080f8da4 が落とす)
  u8 kindMask;                  // 0x05, FUN_080f8c58 の第3引数. FUN_080f9a38 は & で、FUN_080f8cf0 は == で引く
  s16 timer;                    // 0x06, FUN_080f9b34 が毎フレーム -1. FUN_080f8da4 が 0x78、FUN_080f8e3c が 0xF0 をセット
  Enemy* enemy;                 // 0x08, 紐付いた敵. FUN_080f8da4 が解除時に NULL にする
  struct EntityD854Node* next;  // 0x0C
} EntityD854Node;
static_assert(sizeof(EntityD854Node) == 16);

// gSubroutineTable の 0xD854 から生成されるシングルトン. 実体のポインタは gEntityD854 (0x03000184)
typedef struct {
  Entity e;              // 0x00, ENTITY_UNK_8
  u32 unk_18;            // 0x18, FUN_080f8c10 が 0 でクリアする
  s32 count;             // 0x1C, head のリストの登録数. 6件以上だと FUN_080f8c58 が登録を拒否する
  u32 unk_20;            // 0x20, EntityD854_Update が毎フレーム +1. FUN_080f8da4 は30フレームに1回だけ走る
  u16 unk_24;            // 0x24, EntityD854_Init が引数をそのまま書く
  u16 unk_26;            // 0x26, 読み手も書き手も未発見
  EntityD854Node* head;  // 0x28, 単方向リストの先頭
} EntityD854;
static_assert(sizeof(EntityD854) == 44);

extern EntityD854* gEntityD854;  // 0x03000184

NAKED void FUN_080ef84c(Enemy* p, s32 val1, s32 val2, s32 val3) { INCFUNC("asm/func/FUN_080ef84c.inc"); }

NAKED void FUN_080ef86c(Enemy* p, s32 val1) { INCFUNC("asm/func/FUN_080ef86c.inc"); }

NAKED void FUN_080ef968(Enemy* p, s32 val1, u32 val2) { INCFUNC("asm/func/FUN_080ef968.inc"); }

NAKED void FUN_080efa6c(Enemy* p, s32 val1, u32 val2) { INCFUNC("asm/func/FUN_080efa6c.inc"); }

NAKED void FUN_080efb60(Enemy* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080efb60.inc"); }

NAKED void FUN_080efc44(Enemy* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080efc44.inc"); }

NAKED void FUN_080efd44(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080efd44.inc"); }

NAKED void FUN_080efe38(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080efe38.inc"); }

NAKED void Enemy_080eff14(Enemy* enemy, s32 param_2) { INCFUNC("asm/func/Enemy_080eff14.inc"); }

NAKED void FUN_080f00ec(Enemy* p) { INCFUNC("asm/func/FUN_080f00ec.inc"); }

NAKED s32 FUN_080f0320(Enemy* p) { INCFUNC("asm/func/FUN_080f0320.inc"); }

NAKED s32 FUN_080f0430(Enemy* p) { INCFUNC("asm/func/FUN_080f0430.inc"); }

NAKED void FUN_080f06ac(void) { INCFUNC("asm/func/FUN_080f06ac.inc"); }

NAKED bool32 FUN_080f06b0(Enemy* p) { INCFUNC("asm/func/FUN_080f06b0.inc"); }

NAKED void FUN_080f07d0(Enemy* p) { INCFUNC("asm/func/FUN_080f07d0.inc"); }

NAKED void FUN_080f0868(Enemy* p) { INCFUNC("asm/func/FUN_080f0868.inc"); }

NAKED void FUN_080f0914(Enemy* p) { INCFUNC("asm/func/FUN_080f0914.inc"); }

NAKED void FUN_080f09a4(Enemy* p) { INCFUNC("asm/func/FUN_080f09a4.inc"); }

NAKED void FUN_080f09e0(Enemy* p, u16* param_2) { INCFUNC("asm/func/FUN_080f09e0.inc"); }

NAKED s32 FUN_080f0a0c(Enemy* p) { INCFUNC("asm/func/FUN_080f0a0c.inc"); }

NAKED void FUN_080f0b3c(Enemy* p) { INCFUNC("asm/func/FUN_080f0b3c.inc"); }

NAKED void FUN_080f0e78(Enemy* p) { INCFUNC("asm/func/FUN_080f0e78.inc"); }

NAKED void FUN_080f11d0(Enemy* p) { INCFUNC("asm/func/FUN_080f11d0.inc"); }

NAKED void FUN_080f12c4(Enemy* p) { INCFUNC("asm/func/FUN_080f12c4.inc"); }

NAKED void FUN_080f19cc(Enemy* p) { INCFUNC("asm/func/FUN_080f19cc.inc"); }

NAKED void FUN_080f1c54(Enemy* p) { INCFUNC("asm/func/FUN_080f1c54.inc"); }

NAKED void FUN_080f1cb8(Enemy* p) { INCFUNC("asm/func/FUN_080f1cb8.inc"); }

NAKED void FUN_080f1cf0(Enemy* p) { INCFUNC("asm/func/FUN_080f1cf0.inc"); }

NAKED void FUN_080f1de4(Enemy* p) { INCFUNC("asm/func/FUN_080f1de4.inc"); }

NAKED void FUN_080f1e0c(Enemy* p) { INCFUNC("asm/func/FUN_080f1e0c.inc"); }

NAKED void FUN_080f1e78(Enemy* p) { INCFUNC("asm/func/FUN_080f1e78.inc"); }

NAKED void FUN_080f1ef8(Enemy* p) { INCFUNC("asm/func/FUN_080f1ef8.inc"); }

NAKED void FUN_080f2074(Enemy* p) { INCFUNC("asm/func/FUN_080f2074.inc"); }

NAKED void FUN_080f2160(Enemy* p) { INCFUNC("asm/func/FUN_080f2160.inc"); }

NAKED void FUN_080f2254(Enemy* p) { INCFUNC("asm/func/FUN_080f2254.inc"); }

NAKED void FUN_080f2278(Enemy* p) { INCFUNC("asm/func/FUN_080f2278.inc"); }

NAKED void FUN_080f229c(Enemy* p) { INCFUNC("asm/func/FUN_080f229c.inc"); }

NAKED void FUN_080f22c0(void) { INCFUNC("asm/func/FUN_080f22c0.inc"); }

NAKED void FUN_080f22c4(Enemy* p) { INCFUNC("asm/func/FUN_080f22c4.inc"); }

NAKED void FUN_080f22e8(Enemy* p) { INCFUNC("asm/func/FUN_080f22e8.inc"); }

NAKED void FUN_080f230c(Enemy* p) { INCFUNC("asm/func/FUN_080f230c.inc"); }

NAKED void FUN_080f2330(Enemy* p) { INCFUNC("asm/func/FUN_080f2330.inc"); }

NAKED void FUN_080f2364(Enemy* p) { INCFUNC("asm/func/FUN_080f2364.inc"); }

NAKED void FUN_080f248c(Enemy* p) { INCFUNC("asm/func/FUN_080f248c.inc"); }

NAKED void FUN_080f2644(Enemy* p) { INCFUNC("asm/func/FUN_080f2644.inc"); }

NAKED void FUN_080f2864(Enemy* p) { INCFUNC("asm/func/FUN_080f2864.inc"); }

NAKED void FUN_080f2a40(Enemy* p) { INCFUNC("asm/func/FUN_080f2a40.inc"); }

NAKED void FUN_080f2d04(Enemy* p) { INCFUNC("asm/func/FUN_080f2d04.inc"); }

NAKED void FUN_080f2ec0(Enemy* p) { INCFUNC("asm/func/FUN_080f2ec0.inc"); }

NAKED void FUN_080f31c4(Enemy* p) { INCFUNC("asm/func/FUN_080f31c4.inc"); }

NAKED void FUN_080f33e8(Enemy* p) { INCFUNC("asm/func/FUN_080f33e8.inc"); }

NAKED void FUN_080f34a0(Enemy* p) { INCFUNC("asm/func/FUN_080f34a0.inc"); }

NAKED void FUN_080f34ec(Enemy* p) { INCFUNC("asm/func/FUN_080f34ec.inc"); }

NAKED void FUN_080f3574(Enemy* p) { INCFUNC("asm/func/FUN_080f3574.inc"); }

NAKED void FUN_080f35fc(Enemy* p) { INCFUNC("asm/func/FUN_080f35fc.inc"); }

NAKED void Enemy_Init_080f3680(Enemy* p) { INCFUNC("asm/func/Enemy_Init_080f3680.inc"); }

NAKED s32 FUN_080f3718(Enemy* p) { INCFUNC("asm/func/FUN_080f3718.inc"); }

NAKED void FUN_080f3cdc(Enemy* p) { INCFUNC("asm/func/FUN_080f3cdc.inc"); }

NAKED void FUN_080f3d28(Enemy* p) { INCFUNC("asm/func/FUN_080f3d28.inc"); }

NAKED void FUN_080f410c(Enemy* p) { INCFUNC("asm/func/FUN_080f410c.inc"); }

NAKED void FUN_080f44f4(Enemy* p) { INCFUNC("asm/func/FUN_080f44f4.inc"); }

NAKED void FUN_080f46a4(Enemy* p) { INCFUNC("asm/func/FUN_080f46a4.inc"); }

NAKED void FUN_080f47c8(Enemy* p) { INCFUNC("asm/func/FUN_080f47c8.inc"); }

NAKED bool32 FUN_080f48ac(Enemy* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_080f48ac.inc"); }

NAKED void FUN_080f5208(Enemy* p) { INCFUNC("asm/func/FUN_080f5208.inc"); }

NAKED void FUN_080f54e4(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080f54e4.inc"); }

NAKED void FUN_080f56ec(Enemy* p) { INCFUNC("asm/func/FUN_080f56ec.inc"); }

NAKED void FUN_080f5b34(Enemy* p) { INCFUNC("asm/func/FUN_080f5b34.inc"); }

NAKED void FUN_080f5c0c(Enemy* p) { INCFUNC("asm/func/FUN_080f5c0c.inc"); }

NAKED void FUN_080f5fac(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080f5fac.inc"); }

NAKED void FUN_080f624c(Enemy* p) { INCFUNC("asm/func/FUN_080f624c.inc"); }

NAKED void FUN_080f62a8(void) { INCFUNC("asm/func/FUN_080f62a8.inc"); }

NAKED s32 FUN_080f62ac(void) { INCFUNC("asm/func/FUN_080f62ac.inc"); }

NAKED s32 FUN_080f62b0(Enemy* p) { INCFUNC("asm/func/FUN_080f62b0.inc"); }

NAKED bool32 FUN_080f64f0(Enemy* p) { INCFUNC("asm/func/FUN_080f64f0.inc"); }

NAKED bool32 FUN_080f65a8(Enemy* p) { INCFUNC("asm/func/FUN_080f65a8.inc"); }

NAKED s32 FUN_080f6604(Enemy* p) { INCFUNC("asm/func/FUN_080f6604.inc"); }

NAKED s32 FUN_080f6868(Enemy* p) { INCFUNC("asm/func/FUN_080f6868.inc"); }

NAKED s32 FUN_080f6af0(Enemy* p) { INCFUNC("asm/func/FUN_080f6af0.inc"); }

NAKED Enemy* FUN_080f6bac(Enemy* p) { INCFUNC("asm/func/FUN_080f6bac.inc"); }

NAKED bool32 FUN_080f6c74(Enemy* p) { INCFUNC("asm/func/FUN_080f6c74.inc"); }

NAKED void FUN_080f6e34(Enemy* p) { INCFUNC("asm/func/FUN_080f6e34.inc"); }

NAKED s32 FUN_080f6e64(Enemy* p) { INCFUNC("asm/func/FUN_080f6e64.inc"); }

NAKED bool32 FUN_080f8400(Enemy* p) { INCFUNC("asm/func/FUN_080f8400.inc"); }

NAKED s32 FUN_080f84d4(Enemy* p) { INCFUNC("asm/func/FUN_080f84d4.inc"); }

NAKED void FUN_080f8844(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080f8844.inc"); }

NAKED void FUN_080f897c(unknown* param_1) { INCFUNC("asm/func/FUN_080f897c.inc"); }

NAKED s32 FUN_080f8abc(Enemy* p) { INCFUNC("asm/func/FUN_080f8abc.inc"); }

NAKED void FUN_080f8ae0(Enemy* p) { INCFUNC("asm/func/FUN_080f8ae0.inc"); }

NAKED void FUN_080f8bb8(Entity2UnkData* owner) { INCFUNC("asm/func/FUN_080f8bb8.inc"); }

NAKED void FUN_080f8c10(void) { INCFUNC("asm/func/FUN_080f8c10.inc"); }

NAKED bool32 FUN_080f8c2c(EntityD854Node* node) { INCFUNC("asm/func/FUN_080f8c2c.inc"); }

NAKED bool32 FUN_080f8c58(EntityD854Node* node, Entity2UnkData* owner, u8 kindMask) { INCFUNC("asm/func/FUN_080f8c58.inc"); }

NAKED void FUN_080f8cac(EntityD854Node* node) { INCFUNC("asm/func/FUN_080f8cac.inc"); }

NAKED void FUN_080f8cec(void) { INCFUNC("asm/func/FUN_080f8cec.inc"); }

NAKED EntityD854Node* FUN_080f8cf0(u32 kindMask) { INCFUNC("asm/func/FUN_080f8cf0.inc"); }

NAKED bool32 FUN_080f8d20(EntityD854Node* node) { INCFUNC("asm/func/FUN_080f8d20.inc"); }

NAKED Entity2UnkData* FUN_080f8d60(s16 id) { INCFUNC("asm/func/FUN_080f8d60.inc"); }

NAKED void FUN_080f8da4(void) { INCFUNC("asm/func/FUN_080f8da4.inc"); }

NAKED void FUN_080f8e3c(EntityD854Node* node) { INCFUNC("asm/func/FUN_080f8e3c.inc"); }

NAKED bool32 FUN_080f8e84(Entity2UnkData* owner, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_080f8e84.inc"); }

NAKED bool32 FUN_080f8f04(EntityD854Node* node, Enemy* enemy, unknown* param_3) { INCFUNC("asm/func/FUN_080f8f04.inc"); }

NAKED EntityD854Node* FUN_080f9a38(Enemy* p, u8 kindMask) { INCFUNC("asm/func/FUN_080f9a38.inc"); }

NAKED void FUN_080f9b34(void) { INCFUNC("asm/func/FUN_080f9b34.inc"); }

NAKED s32 EntityD854_Update(EntityD854* p) { INCFUNC("asm/func/EntityD854_Update.inc"); }

NAKED s32 EntityD854_Destroy(EntityD854* p) { INCFUNC("asm/func/EntityD854_Destroy.inc"); }

NAKED s32 EntityD854_Init(EntityD854* p, u16 id) { INCFUNC("asm/func/EntityD854_Init.inc"); }

NAKED EntityD854* EntityD854_Create(u16 id) { INCFUNC("asm/func/EntityD854_Create.inc"); }

NAKED void FUN_080f9bec(void) { INCFUNC("asm/func/FUN_080f9bec.inc"); }

NAKED s32 FUN_080f9bf8(unknown* p, s32 val) { INCFUNC("asm/func/FUN_080f9bf8.inc"); }

NAKED void FUN_080f9bfc(Enemy* p) { INCFUNC("asm/func/FUN_080f9bfc.inc"); }

NAKED void FUN_080f9c20(Enemy* p) { INCFUNC("asm/func/FUN_080f9c20.inc"); }

NAKED void FUN_080f9e34(Enemy* p) { INCFUNC("asm/func/FUN_080f9e34.inc"); }

NAKED void FUN_080f9ee0(Enemy* p) { INCFUNC("asm/func/FUN_080f9ee0.inc"); }

NAKED s32 FUN_080f9f20(Enemy* p) { INCFUNC("asm/func/FUN_080f9f20.inc"); }

NAKED s32 FUN_080fa2ac(Enemy* p, Vec3* pos, u32 param_3) { INCFUNC("asm/func/FUN_080fa2ac.inc"); }

NAKED s32 FUN_080fa354(unknown* param_1, u32 param_2, u8 param_3) { INCFUNC("asm/func/FUN_080fa354.inc"); }

NAKED s32 FUN_080fa384(Enemy* p) { INCFUNC("asm/func/FUN_080fa384.inc"); }

NAKED void FUN_080fa77c(Enemy* p) { INCFUNC("asm/func/FUN_080fa77c.inc"); }

NAKED s32 FUN_080fa7a4(Enemy* p) { INCFUNC("asm/func/FUN_080fa7a4.inc"); }

NAKED s32 FUN_080fa958(Vec3* pos) { INCFUNC("asm/func/FUN_080fa958.inc"); }

NAKED bool32 FUN_080faa98(Enemy* p) { INCFUNC("asm/func/FUN_080faa98.inc"); }

NAKED void FUN_080faad8(Enemy* p) { INCFUNC("asm/func/FUN_080faad8.inc"); }

NAKED void FUN_080fadd4(unknown* param_1, unknown* param_2, Enemy* enemy) { INCFUNC("asm/func/FUN_080fadd4.inc"); }

NAKED void FUN_080fae14(HitboxData* a, HitboxData* b, Enemy* enemy) { INCFUNC("asm/func/FUN_080fae14.inc"); }

NAKED void FUN_080fb4d0(unknown* p) { INCFUNC("asm/func/FUN_080fb4d0.inc"); }

NAKED void FUN_080fba28(Enemy* p) { INCFUNC("asm/func/FUN_080fba28.inc"); }

NAKED void FUN_080fba40(Enemy* p) { INCFUNC("asm/func/FUN_080fba40.inc"); }

NAKED void FUN_080fba64(Enemy* p) { INCFUNC("asm/func/FUN_080fba64.inc"); }

NAKED void FUN_080fc0b8(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc0b8.inc"); }

NAKED void FUN_080fc174(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc174.inc"); }

NAKED void FUN_080fc1e4(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc1e4.inc"); }

NAKED void FUN_080fc28c(Enemy* p) { INCFUNC("asm/func/FUN_080fc28c.inc"); }

NAKED void FUN_080fc4ec(Enemy* p) { INCFUNC("asm/func/FUN_080fc4ec.inc"); }

NAKED void FUN_080fc548(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc548.inc"); }

NAKED void FUN_080fc6f4(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fc6f4.inc"); }

NAKED void FUN_080fd08c(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fd08c.inc"); }

NAKED void FUN_080fe1bc(Enemy* p) { INCFUNC("asm/func/FUN_080fe1bc.inc"); }

NAKED void FUN_080fe274(Enemy* p, s32 param_2) { INCFUNC("asm/func/FUN_080fe274.inc"); }

NAKED void FUN_080fe704(Enemy* p) { INCFUNC("asm/func/FUN_080fe704.inc"); }

NAKED void FUN_080fe7f4(Enemy* p) { INCFUNC("asm/func/FUN_080fe7f4.inc"); }

NAKED void FUN_080ff05c(Enemy* p) { INCFUNC("asm/func/FUN_080ff05c.inc"); }

NAKED void FUN_080ff06c(unknown* p) { INCFUNC("asm/func/FUN_080ff06c.inc"); }

NAKED void FUN_080ff270(unknown* p) { INCFUNC("asm/func/FUN_080ff270.inc"); }
