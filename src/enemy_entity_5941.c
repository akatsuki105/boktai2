#include "entity.h"
#include "global.h"
#include "mover.h"

COMMON_DATA Entity5941* gEntity5941 = NULL;  // 0x03002BF8

// 原典はリストを進める node = node->next を書き忘れていて, 先頭が一致しないと無限ループになる
// 残差は23/23命令, 空ループの手前へ原典は定数1を, agbcc は flags の ldr を追い出す (node が r1 でなく r2 になる)
// Tier A-C 試済 (while/do-while, インラインアクセサ)
NON_MATCH Entity5941Node* FUN_0807f478(s32 id) {
#ifdef NONMATCHING_C
  Entity5941Node* node;

  if (gEntity5941 == NULL) {
    return NULL;
  }

  node = gEntity5941->nodes;
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
  INCFUNC("asm/func/FUN_0807f478.inc");
#endif
}

// pos から見て angle±halfAngle の扇形かつ maxDist 以内にいるノードのうち, 最も近いものを返す
Entity5941Node* Entity5941_FindNearestInCone(Vec3* pos, s32 angle, s32 maxDist, s32 halfAngle) {
  Entity5941Node* node;
  Entity5941Node* best;
  s32 bestDistSq;

  if (gEntity5941 == NULL) {
    return NULL;
  }

  node = gEntity5941->nodes;
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
// 残差は28/29命令で1命令, 原典は node->next への書き込みのあと gEntity5941 を読み直すが agbcc はレジスタを使い回す
// (ItemEffect_Solar と同じ型の残差), Tier A-C 試済
NON_MATCH bool32 Entity5941_Register(Entity5941Node* node, void* owner, void* fn) {
#ifdef NONMATCHING_C
  Entity5941Node* cur;

  if (gEntity5941 == NULL) {
    return FALSE;
  }

  node->owner = owner;
  node->fn = fn;

  for (cur = gEntity5941->nodes; cur != NULL; cur = cur->next) {
    if (cur == node) {
      return TRUE;
    }
  }

  node->next = gEntity5941->nodes;
  gEntity5941->nodes = node;
  return TRUE;
#else
  INCFUNC("asm/func/Entity5941_Register.inc");
#endif
}

// 単方向リストからノードを外す
// 残差は23/23命令でブロック配置のみ, 原典は「見つけて外す」ブロックをループの手前に置く
// Tier A-C 試済 (while/for, next ローカル, cur->next 再読みの有無)
NON_MATCH void Entity5941_Unregister(Entity5941Node* node) {
#ifdef NONMATCHING_C
  Entity5941Node* cur;

  if (gEntity5941 == NULL) {
    return;
  }

  cur = gEntity5941->nodes;
  if (cur == node) {
    gEntity5941->nodes = node->next;
    return;
  }

  for (;;) {
    Entity5941Node* next = cur->next;

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
  INCFUNC("asm/func/Entity5941_Unregister.inc");
#endif
}

s32 Entity5941_Update(Entity5941* p) { return 0; }

s32 Entity5941_Destroy(Entity5941* p) {
  gEntity5941 = NULL;
  return 0;
}

s32 Entity5941_Init(Entity5941* p, u32 id, u32 _) {
  p->nodes = NULL;
  p->unk_1c = NULL;
  gEntity5941 = p;
  return 0;
}

Entity5941* Entity5941_Create(u32 id, u32 _) {
  if (gEntity5941 == NULL) {
    Entity5941* p = CreateEntity(ENTITY_UNK_2, sizeof(Entity5941));

    if (p != NULL) {
      SetEntityRoutine(p, Entity5941_Update, Entity5941_Destroy);
      if (Entity5941_Init(p, id, _) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity5941;
}
