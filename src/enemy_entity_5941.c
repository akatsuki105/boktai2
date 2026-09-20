#include "entity.h"
#include "global.h"

// 敵の索敵範囲を管理する? 敵は _Init で Entity5941_Register、_Destroy で FUN_0807f598 を呼んで出入りする (28種)
// unk_18 が単方向リストの先頭。ノードは敵の構造体に埋め込まれている (Bat なら +0x7C)
// ノードの中身: 0x0 敵自身へのポインタ / 0x4 フラグ(bit0 が立っているものだけ検索対象) / 0x8 関数ポインタ / 0xC next
// 用途は Entity5941_FindNearestInCone (扇形の中で最も近いノードを返す) だが、これを呼ぶコードは見つかっていない
typedef struct Entity5941 {
  Entity e;      // 0x0, ENTITY_UNK_2
  void* unk_18;  // 0x18, 登録済みノードのリスト先頭, 根拠: Entity5941_Register / FUN_0807f598
  void* unk_1c;  // 0x1C
} Entity5941;
static_assert(sizeof(Entity5941) == 32);

extern Entity5941* gEntity5941;  // 0x03002BF8

NAKED unknown* FUN_0807f478(unknown* p) { INCFUNC("asm/func/FUN_0807f478.inc"); }

NAKED unknown* Entity5941_FindNearestInCone(unknown* p, s32 angle, s32 maxDist, s32 halfAngle) { INCFUNC("asm/func/Entity5941_FindNearestInCone.inc"); }

NAKED bool32 Entity5941_Register(unknown* node, unknown* owner, void* fn) { INCFUNC("asm/func/Entity5941_Register.inc"); }

NAKED void FUN_0807f598(void* p) { INCFUNC("asm/func/FUN_0807f598.inc"); }

s32 Entity5941_Update(Entity5941* p) { return 0; }

s32 Entity5941_Destroy(Entity5941* p) {
  gEntity5941 = NULL;
  return 0;
}

s32 Entity5941_Init(Entity5941* p, u32 unused1, u32 unused2) {
  p->unk_18 = NULL;
  p->unk_1c = NULL;
  gEntity5941 = p;
  return 0;
}

NAKED Entity5941* Entity5941_Create(u32 id, u32 _) { INCFUNC("asm/func/Entity5941_Create.inc"); }
