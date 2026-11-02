#include "cwolf_target.h"

#include "entity.h"
#include "global.h"
#include "mover.h"

// Cウルフのターゲット

COMMON_DATA CWolfTargetManager* gCWolfTargetManager = NULL;  // 0x03002BF8

// 原典はリストを進める node = node->next を書き忘れていて, 先頭が一致しないと無限ループになる
// 残差は23/23命令, 空ループの手前へ原典は定数1を, agbcc は flags の ldr を追い出す (node が r1 でなく r2 になる)
// Tier A-C 試済 (while/do-while, インラインアクセサ)
NON_MATCH CWolfTargetNode* UNUSED CWolfTargetManager_FindByID(s32 id) {
#ifdef NONMATCHING_C
  CWolfTargetNode* node;

  if (gCWolfTargetManager == NULL) {
    return NULL;
  }

  node = gCWolfTargetManager->nodes;
  if (node == NULL) {
    return NULL;
  }

  while (node->owner->id != id) {
  }

  if (node->flags & 1) {
    return NULL;
  }
  return node;
#else
  INCFUNC("asm/func/CWolfTargetManager_FindByID.inc");
#endif
}

// pos から見て angle±halfAngle の扇形かつ maxDist 以内にいるノードのうち, 最も近いものを返す
CWolfTargetNode* CWolfTargetManager_FindNearestInCone(Vec3* pos, s32 angle, s32 maxDist, s32 halfAngle) {
  CWolfTargetNode* node;
  CWolfTargetNode* best;
  s32 bestDistSq;

  if (gCWolfTargetManager == NULL) {
    return NULL;
  }

  node = gCWolfTargetManager->nodes;
  best = NULL;
  bestDistSq = maxDist * maxDist;

  while (node != NULL) {
    s32 limit = 0x100 - halfAngle;

    if (node->flags & 1) {
      Mover* owner = node->owner;
      s32 dx = owner->pos.x - pos->x;
      s32 dz = owner->pos.z - pos->z;
      s32 d = Angle_Diff(ArcTan2_8(dx, dz), angle - 0x100);

      if (d <= halfAngle || d >= limit) {
        s32 distSq = dx * dx + dz * dz;

        if (distSq < bestDistSq) {
          bestDistSq = distSq;
          best = node;
        }
      }
    }
    node = node->next;
  }
  return best;
}

// ノードをリスト先頭に繋ぐ, 既に繋がっていれば何もしない
// 残差は28/29命令で1命令, 原典は node->next への書き込みのあと gCWolfTargetManager を読み直すが agbcc はレジスタを使い回す
// (ItemEffect_Solar と同じ型の残差), Tier A-C 試済
NON_MATCH bool32 CWolfTargetManager_Register(CWolfTargetNode* node, void* owner, void* fn) {
#ifdef NONMATCHING_C
  CWolfTargetNode* cur;

  if (gCWolfTargetManager == NULL) {
    return FALSE;
  }

  node->owner = owner;
  node->fn = fn;

  for (cur = gCWolfTargetManager->nodes; cur != NULL; cur = cur->next) {
    if (cur == node) {
      return TRUE;
    }
  }

  node->next = gCWolfTargetManager->nodes;
  gCWolfTargetManager->nodes = node;
  return TRUE;
#else
  INCFUNC("asm/func/CWolfTargetManager_Register.inc");
#endif
}

// 単方向リストからノードを外す
// 残差は23/23命令でブロック配置のみ, 原典は「見つけて外す」ブロックをループの手前に置く
// Tier A-C 試済 (while/for, next ローカル, cur->next 再読みの有無)
NON_MATCH void CWolfTargetManager_Unregister(CWolfTargetNode* node) {
#ifdef NONMATCHING_C
  CWolfTargetNode* cur;

  if (gCWolfTargetManager == NULL) {
    return;
  }

  cur = gCWolfTargetManager->nodes;
  if (cur == node) {
    gCWolfTargetManager->nodes = node->next;
    return;
  }

  for (;;) {
    CWolfTargetNode* next = cur->next;

    if (next == NULL) {
      return;
    }
    if (next == node) {
      cur->next = next->next;
      return;
    }
    cur = cur->next;
  }
#else
  INCFUNC("asm/func/CWolfTargetManager_Unregister.inc");
#endif
}

s32 CWolfTargetManager_Update(CWolfTargetManager* p) { return 0; }

s32 CWolfTargetManager_Destroy(CWolfTargetManager* p) {
  gCWolfTargetManager = NULL;
  return 0;
}

s32 CWolfTargetManager_Init(CWolfTargetManager* p, u32 id, u32 _) {
  p->nodes = NULL;
  p->unk_1c = NULL;
  gCWolfTargetManager = p;
  return 0;
}

// 0x5941
CWolfTargetManager* CWolfTargetManager_Create(u32 id, u32 _) {
  if (gCWolfTargetManager == NULL) {
    CWolfTargetManager* p = CreateEntity(ENTITY_UNK_2, sizeof(CWolfTargetManager));

    if (p != NULL) {
      SetEntityRoutine(p, CWolfTargetManager_Update, CWolfTargetManager_Destroy);
      if (CWolfTargetManager_Init(p, id, _) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gCWolfTargetManager;
}
