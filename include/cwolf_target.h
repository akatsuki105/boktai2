#ifndef __INCLUDE_CWOLF_TARGET_H__
#define __INCLUDE_CWOLF_TARGET_H__

#include "entity.h"
#include "gba/gba.h"
#include "types.h"

struct Mover;

// ノードの持ち主に用件を伝えるコールバック, 根拠: EntityF41A_OnMessage が CWolfTargetManager_Register の第3引数に渡る
typedef bool32 CWolfTargetCallback(struct Mover* owner, s32 msg, s32 value);

// gCWolfTargetManager の単方向リストのノード, 敵は _Init で CWolfTargetManager_Register、_Destroy で CWolfTargetManager_Unregister を呼んで出入りする
typedef struct CWolfTargetNode {
  struct Mover* owner;           // 0x00, CWolfTargetManager_Register の第2引数 (敵の Mover)
  u32 flags;                     // 0x04, bit0 が立っていると Player_FindCWolfTarget の対象から外れる, 敵が倒されたときなどに立つ
  CWolfTargetCallback* fn;       // 0x08, CWolfTargetManager_Register の第3引数
  struct CWolfTargetNode* next;  // 0x0C
} CWolfTargetNode;
static_assert(sizeof(CWolfTargetNode) == 16);

// チェンジウルフで噛みつける相手のリストを持つ, 敵は _Init で CWolfTargetManager_Register、_Destroy で CWolfTargetManager_Unregister を呼んで出入りする (28種)
// nodes が単方向リストの先頭, ノードは敵の構造体に埋め込まれている (EnemyBat なら +0x7C)
// リストを読むのは player.c の Player_FindCWolfTarget だけで, CWolfTargetManager_FindNearestInCone はどこからも呼ばれない
typedef struct {
  Entity e;                // 0x0, ENTITY_UNK_2
  CWolfTargetNode* nodes;  // 0x18, 登録済みノードのリスト先頭, 根拠: CWolfTargetManager_Register / CWolfTargetManager_Unregister
  void* unk_1c;            // 0x1C
} CWolfTargetManager;
static_assert(sizeof(CWolfTargetManager) == 32);

extern CWolfTargetManager* gCWolfTargetManager;  // 0x03002BF8

bool32 CWolfTargetManager_Register(CWolfTargetNode* node, void* owner, void* fn);
void CWolfTargetManager_Unregister(CWolfTargetNode* node);

#endif  // __INCLUDE_CWOLF_TARGET_H__
