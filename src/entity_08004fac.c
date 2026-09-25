#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "vm.h"

// 衝突マップのノード (MapTileOverride) を id 付きで持つラッパ。id を指定して一括で消したり、 登録を外したり (Entity08004fac_DisableNodesById) 戻したり (同 Enable) できる
typedef struct Entity08004facNode {
  u16 id;                           // 0x00, 一括で操作するためのキー
  bool8 active;                     // 0x02, 1 なら tileOverride を衝突マップへ登録済み
  u8 unk_3;                         // 0x03, Entity08004fac_AddNode の第3引数。SetNodeParamsById が書き換える
  u8 unk_4;                         // 0x04, FUN_08234270 の第3引数
  u8 unk_5;                         // 0x05, FUN_08234270 の第4引数
  u16 unk_6;                        // 0x06, FUN_08234270 の第6引数
  u16 tileIdx;                      // 0x08, gCollisionMap->rowOffsets[y] + x
  u8 unk_a[0x0C - 0x0A];            // 0x0A, padding?
  MapTileOverride tileOverride;     // 0x0C, FUN_08234270 / FUN_082342a8 に渡す
  struct Entity08004facNode* prev;  // 0x1C
  struct Entity08004facNode* next;  // 0x20
} Entity08004facNode;
static_assert(sizeof(Entity08004facNode) == 36);

typedef struct {
  Entity e;                  // 0x00, ENTITY_UNK_8
  Entity08004facNode* head;  // 0x18, ノードの双方向リストの先頭。Init が NULL、LinkNode が先頭挿入する
} Entity08004fac;
static_assert(sizeof(Entity08004fac) == 28);

IWRAM_DATA Entity08004fac* gEntity08004fac = NULL;  // 0x03000024

NAKED s32 FUN_08004668(s32 param_1) { INCFUNC("asm/func/FUN_08004668.inc"); }

NAKED s32 FUN_08004694(s32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_08004694.inc"); }

NAKED s32 FUN_080046c8(u16 param_1, s32 param_2, s32 param_3, unknown* param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/FUN_080046c8.inc"); }

NAKED s32 FUN_08004a04(void) { INCFUNC("asm/func/FUN_08004a04.inc"); }

NAKED s32 FUN_08004ba4(void) { INCFUNC("asm/func/FUN_08004ba4.inc"); }

void FUN_08004c78(void) { gEntity08004fac = NULL; }

NAKED s32 Entity08004fac_LinkNode(Entity08004facNode* node) { INCFUNC("asm/func/Entity08004fac_LinkNode.inc"); }

NAKED s32 Entity08004fac_UnlinkNode(Entity08004facNode* node) { INCFUNC("asm/func/Entity08004fac_UnlinkNode.inc"); }

NAKED s32 Entity08004fac_AddNode(u16 id, s16* pos, u8 param_3, u8 param_4, u16 param_5) { INCFUNC("asm/func/Entity08004fac_AddNode.inc"); }

NAKED s32 Entity08004fac_FreeNode(Entity08004facNode* node) { INCFUNC("asm/func/Entity08004fac_FreeNode.inc"); }

NAKED s32 Entity08004fac_FreeAllNodes(void) { INCFUNC("asm/func/Entity08004fac_FreeAllNodes.inc"); }

NAKED s32 Entity08004fac_FreeNodesById(u16 id) { INCFUNC("asm/func/Entity08004fac_FreeNodesById.inc"); }

NAKED s32 Entity08004fac_DisableNodesById(u16 id) { INCFUNC("asm/func/Entity08004fac_DisableNodesById.inc"); }

NAKED s32 Entity08004fac_EnableNodesById(u16 id) { INCFUNC("asm/func/Entity08004fac_EnableNodesById.inc"); }

NAKED s32 Entity08004fac_SetNodeParamsById(u16 id, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/Entity08004fac_SetNodeParamsById.inc"); }

s32 Entity08004fac_Update(Entity08004fac* p) { return 0; }

s32 Entity08004fac_Destroy(Entity08004fac* p) {
  Entity08004fac_FreeAllNodes();
  gEntity08004fac = NULL;
  return 0;
}

s32 Entity08004fac_Init(Entity08004fac* p, u32 param_2) {
  gEntity08004fac = p;
  p->head = NULL;
  return 0;
}

NAKED Entity08004fac* Entity08004fac_Create(u32 param_1) { INCFUNC("asm/func/Entity08004fac_Create.inc"); }

NAKED s32 VM_Sub3E1F(void) { INCFUNC("asm/func/VM_Sub3E1F.inc"); }

// スクリプトの 'n' が指すノードを衝突マップから外す
s32 FUN_08005004(void) { return Entity08004fac_DisableNodesById(VM_GetKeywordValue('n', 0)); }

// スクリプトの 'n' が指すノードを衝突マップへ戻す
s32 FUN_0800501c(void) { return Entity08004fac_EnableNodesById(VM_GetKeywordValue('n', 0)); }

NAKED s32 FUN_08005034(void) { INCFUNC("asm/func/FUN_08005034.inc"); }

NAKED s32 FUN_0800512c(void) { INCFUNC("asm/func/FUN_0800512c.inc"); }
