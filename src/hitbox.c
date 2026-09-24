#include "hitbox.h"

#include "entity.h"
#include "global.h"

// 当たり判定を2本のリストで持つ。attacks 側が攻撃する方 (a, attack の頭文字)、 targets 側が攻撃される方 (b, 防御をローマ字で書くと "bougyo" なので b　にした) で、
// Hitbox_CheckAllPairs が attacks × targets の総当たりで重なりを見る
typedef struct {
  Entity e;                   // 0x0, ENTITY_UNK_11
  HitboxData* targets;        // 0x18, &targetSentinel。Hitbox_Register が HBFLAG_UNK_13 なしの Hitbox をここへ繋ぐ。Hitbox_Unregister で外すまで残り続ける
  HitboxData* attacks;        // 0x1C, &attackSentinel。Hitbox_Register が HBFLAG_UNK_13 付きの Hitbox をここへ繋ぐ。HitboxManager_Update が毎フレーム空にするので、攻撃側は毎フレーム登録し直す
  HitboxData* targetsTail;    // 0x20, targets リストの末尾。Hitbox_LinkTarget がここに繋いで更新し、Hitbox_Unregister が末尾を外すときに戻す
  HitboxData* attacksTail;    // 0x24, targetsTail と対になる attacks 側の末尾。Hitbox_LinkAttack が先頭挿入なので誰も読まない
  HitboxData targetSentinel;  // 0x28, targets リストのダミー先頭ノード。next しか使われない
  HitboxData attackSentinel;  // 0x78, attacks リストのダミー先頭ノード。next しか使われない
  u16 targetCount;            // 0xC8
  u16 attackCount;            // 0xCA, 0 なら HitboxManager_Update は判定を丸ごと飛ばす
} HitboxManager;
static_assert(sizeof(HitboxManager) == 204);

IWRAM_DATA HitboxManager* gHitboxManager = NULL;  // 0x03000780

// targets リストの末尾に p を繋ぐ。既に繋がっていれば何もしない
void Hitbox_LinkTarget(HitboxData* p) {
  HitboxData* q;

  if (gHitboxManager == NULL) {
    return;
  }
  q = gHitboxManager->targets;
  while ((q = q->next) != NULL) {
    if (q == p) {
      return;
    }
  }
  gHitboxManager->targetsTail->next = p;
  p->next = NULL;
  gHitboxManager->targetsTail = p;
  gHitboxManager->targetCount++;
}

// attacks リストの先頭に p を繋ぐ。既に繋がっていれば何もしない
// ループに入る前のガード (cmp/beq) が出ない。agbcc が本体先頭の q == p 判定と末尾判定をまとめて rotate してしまう
NON_MATCH void Hitbox_LinkAttack(HitboxData* p) {
#ifdef NONMATCHING_C
  HitboxData* q;

  if (gHitboxManager == NULL) {
    return;
  }
  q = gHitboxManager->attacks->next;
  while (q != NULL) {
    if (q == p) {
      return;
    }
    q = q->next;
  }
  p->next = gHitboxManager->attacks->next;
  gHitboxManager->attacks->next = p;
  gHitboxManager->attackCount++;
#else
  INCFUNC("asm/func/Hitbox_LinkAttack.inc");
#endif
}

void Hitbox_Register(HitboxData* p) {
  if (p->flags & HBFLAG_UNK_13) {
    Hitbox_LinkAttack(p);
  } else {
    Hitbox_LinkTarget(p);
  }
}

// targets リストから p を外す
void Hitbox_Unregister(HitboxData* p) {
  HitboxData* prev;
  HitboxData* q;

  if (gHitboxManager == NULL) {
    return;
  }
  prev = gHitboxManager->targets;
  q = prev->next;
  if (q == NULL) {
    return;
  }
  do {
    if (q == p) {
      if (q == gHitboxManager->targetsTail) {
        gHitboxManager->targetsTail = prev;
      }
      prev->next = q->next;
      gHitboxManager->targetCount--;
      return;
    }
    prev = q;
    q = q->next;
  } while (q != NULL);
}

// 当たり判定1つを作る。属性やダメージ関係は全部 0 に戻す
void Hitbox_Init(HitboxData* p, u32 id, HitboxFlags32 flags, u32 unk_8, u16 ignoreMask, Vec3* halfSize, Vec3* offset) {
  p->flags = flags;
  p->unk_4 = id;
  p->unk_8 = unk_8;
  p->ignoreMask = ignoreMask;
  p->halfSize = *halfSize;
  p->offset = *offset;
  p->hitResult = 0;
  p->damage = 0;
  p->weakness = 0;
  p->attributes = 0;
  p->unk_40 = 0;
  p->fn = NULL;
  p->unk_47 = 1;
}

void Hitbox_SetPos(HitboxData* p, Vec3* pos, u32 unk_8) {
  p->pos.x = pos->x;
  p->pos.y = pos->y;
  p->pos.z = pos->z;
  p->unk_8 = unk_8;
}

void UNUSED Hitbox_SetPosAndOffset(HitboxData* p, Vec3* pos, Vec3* offset, u32 unk_8) {
  p->pos = *pos;
  p->offset = *offset;
  p->unk_8 = unk_8;
}

void Hitbox_SetPower(HitboxData* p, u16 power, u16 unk_40) {
  p->power = power;
  p->unk_40 = unk_40;
}

void Hitbox_SetAttack(HitboxData* p, s32 power, s32 unk_40, s32 weakness, s32 attributes, s32 unk_44) {
  p->power = power;
  p->unk_40 = unk_40;
  p->weakness = weakness;
  p->attributes = attributes;
  p->unk_44 = unk_44;
}

void Hitbox_SetPowerAndAttributes(HitboxData* p, u32 power, u32 attributes, u32 weakness) {
  p->power = power;
  p->attributes = attributes;
  p->weakness = weakness;
}

void Hitbox_SetHandler(HitboxData* p, void* handler, void* owner) {
  p->fn = handler;
  p->owner = owner;
}

// a が b に当たったときのダメージを b->damage に書き、効き具合を b->hitResult に残す
// 命令列はあと1命令 (143 対 142) まで近いが、a->attributes のロード位置とレジスタ割り当てが違う
NON_MATCH void Hitbox_ApplyDamage(HitboxData* a, HitboxData* b) {
#ifdef NONMATCHING_C
  s32 damage;
  s32 atk;
  s32 def;
  s32 weak;
  s32 diff;

  if (b->damage != 0) {
    return;
  }
  if (a->attributes & (1 << 12)) {
    damage = a->power;
  } else {
    damage = a->power - b->power;
  }
  if (damage <= 0) {
    damage = 1;
  }
  if (a->attributes & (1 << 13)) {
    def = 0;
  } else {
    def = b->attributes & 0x7F;
  }
  weak = b->weakness & 0x7F;
  atk = a->attributes & 0x7F;
  if (atk == 0) {
    b->damage = damage;
    b->hitResult = HBRESULT_NORMAL;
  } else if (def == 0) {
    b->damage = damage * 5 >> 2;
    b->hitResult = HBRESULT_NORMAL;
  } else if (def == 0x40) {
    b->damage = damage >> 2;
    b->hitResult = HBRESULT_RESIST;
  } else if (atk == 0x40) {
    b->damage = damage * 5 >> 2;
    b->hitResult = HBRESULT_NORMAL;
  } else if (def & atk) {
    b->damage = damage >> 2;
    b->hitResult = HBRESULT_RESIST;
  } else if (weak & atk) {
    b->damage = damage * 4;
    b->hitResult = HBRESULT_WEAK;
  } else {
    b->damage = damage * 5 >> 2;
    b->hitResult = HBRESULT_NORMAL;
  }
  if ((b->flags & HBFLAG_UNK_8) && (a->flags & HBFLAG_UNK_8)) {
    diff = b->angle - a->angle;
    if (diff < 0) {
      diff = -diff;
    }
    if (diff <= 0x20) {
      b->damage = (u32)b->damage * 3 >> 1;
      b->hitResult |= HBRESULT_BONUS;
    }
  }
  if (b->damage == 0) {
    b->damage = 1;
  }
#else
  INCFUNC("asm/func/Hitbox_ApplyDamage.inc");
#endif
}

// Hitbox_ApplyDamage とほぼ同じダメージ計算。gFlag030047a4 の bit11/bit14 が立っているときだけ使われる (FUN_0813e944)
NAKED void Hitbox_ApplyDamageAlt(HitboxData* a, HitboxData* b) { INCFUNC("asm/func/Hitbox_ApplyDamageAlt.inc"); }

// a->angle の象限から、a を b の外へ押し出す方向を out に入れる
void Hitbox_GetPushDir(HitboxData* a, HitboxData* b, Vec3* out) {
  s32 quadrant = ((a->angle + 0x20) & 0xFF) >> 6;

  if (quadrant == 0) {
    out->x = (a->center.x + a->halfSize.x) + b->halfSize.x - b->center.x;
    out->y = 0;
    out->z = 0;
  } else if (quadrant == 1) {
    out->x = 0;
    out->y = 0;
    out->z = (a->center.z + a->halfSize.z) + b->halfSize.z - b->center.z;
  } else if (quadrant == 2) {
    out->x = a->center.x - a->halfSize.x - b->halfSize.x - b->center.x;
    out->y = 0;
    out->z = 0;
  } else {
    out->x = 0;
    out->y = 0;
    out->z = a->center.z - a->halfSize.z - b->halfSize.z - b->center.z;
  }
}

NAKED void FUN_082367e4(void* a, void* b, void* c) { INCFUNC("asm/func/FUN_082367e4.inc"); }

NAKED bool32 FUN_082368d4(Vec3* a, Vec3* b, Vec3* center, Vec3* halfSize, Vec3* out) { INCFUNC("asm/func/FUN_082368d4.inc"); }

NAKED bool32 FUN_082369cc(Vec3* a, Vec3* b, Vec3* center, Vec3* halfSize, Vec3* out) { INCFUNC("asm/func/FUN_082369cc.inc"); }

NAKED bool32 FUN_08236ac4(Vec3* a, Vec3* b, Vec3* center, Vec3* halfSize, Vec3* out) { INCFUNC("asm/func/FUN_08236ac4.inc"); }

// 線分 a-b が p の判定の直方体と交わるかを3通りの向きで試す
bool32 FUN_08236bbc(Vec3* a, Vec3* b, HitboxData* p, Vec3* out) {
  Vec3* center = &p->center;
  Vec3* halfSize = &p->halfSize;
  if (FUN_082368d4(a, b, center, halfSize, out)) return TRUE;
  if (FUN_082369cc(a, b, center, halfSize, out)) return TRUE;
  if (FUN_08236ac4(a, b, center, halfSize, out)) return TRUE;
  return FALSE;
}

NAKED bool32 UNUSED FUN_08236c18(void* a, void* b) { INCFUNC("asm/func/FUN_08236c18.inc"); }

// 各 Hitbox の判定範囲を pos + offset で更新する。targets 側は HBFLAG_UNK_2 が立っていれば飛ばす
void Hitbox_UpdateBoxes(u32 attackCount, u32 targetCount, HitboxData* attacks, HitboxData* targets) {
  HitboxData *a, *b;

  a = attacks->next;
  while (a != NULL) {
    HitboxData* p = a;
    a = a->next;
    p->center.x = p->pos.x + p->offset.x;
    p->center.y = p->pos.y + p->offset.y;
    p->center.z = p->pos.z + p->offset.z;
  }

  b = targets->next;
  while (b != NULL) {
    HitboxData* p = b;
    b = b->next;
    if (!(p->flags & HBFLAG_UNK_2)) {
      p->center.x = p->pos.x + p->offset.x;
      p->center.y = p->pos.y + p->offset.y;
      p->center.z = p->pos.z + p->offset.z;
    }
  }
}

NAKED void Hitbox_CheckAllPairs(u32 attackCount, u32 targetCount, HitboxData* attacks, HitboxData* targets) { INCFUNC("asm/func/Hitbox_CheckAllPairs.inc"); }

// 溜まっている攻撃側の Hitbox を targets 側と総当たりし、終わったら attacks リストを空に戻す
s32 HitboxManager_Update(HitboxManager* p) {
  if (p->attackCount != 0) {
    if (gEntityDisableFlags != 0) {
      p->attackCount = 0;
      p->attacks->next = NULL;
      p->attacksTail = p->attacks;
    } else {
      if (p->targetCount != 0) {
        Hitbox_CheckAllPairs(p->attackCount, p->targetCount, p->attacks, p->targets);
      }
      p->attackCount = 0;
      p->attacks->next = NULL;
      p->attacksTail = p->attacks;
    }
  }
  return 0;
}

s32 HitboxManager_Destroy(HitboxManager* p) {
  gHitboxManager = NULL;
  return 0;
}

// なぜかこの Entity だけ 他の Entity_Init 関数とシグネチャが違う
void HitboxManager_Init(void) {
  HitboxManager* p = gHitboxManager;

  if (p != NULL) {
    p->targets = &p->targetSentinel;
    p->attacks = &p->attackSentinel;
    p->targetSentinel.next = NULL;
    p->attackSentinel.next = NULL;
    p->targetsTail = &p->targetSentinel;
    p->attacksTail = &p->attackSentinel;
    p->targetCount = 0;
    p->attackCount = 0;
  }
}

HitboxManager* HitboxManager_Create(void) {
  HitboxManager* p;

  if (gHitboxManager == NULL) {
    p = CreateEntity(ENTITY_UNK_11, sizeof(HitboxManager));
    if (p != NULL) {
      SetEntityRoutine(p, HitboxManager_Update, HitboxManager_Destroy);
      gHitboxManager = p;
      HitboxManager_Init();
    }
    return p;
  }
  return gHitboxManager;
}

HitboxManager* GetHitboxManager(void) { return gHitboxManager; }

// 2つの判定の直方体が重なっているかを軸ごとに見る
// 命令列は一致するがレジスタ割り当てだけが違う。b が r5 でなく r6 に、hit が r6 でなく r3 に入る
NON_MATCH bool32 Hitbox_CheckOverlap(HitboxData* a, HitboxData* b) {
#ifdef NONMATCHING_C
  bool32 ret;
  bool32 hit;
  s32 sum;

  ret = FALSE;
  hit = FALSE;
  sum = a->halfSize.x + b->halfSize.x;
  if (a->center.x - (s16)sum <= b->center.x && b->center.x - (s16)sum <= a->center.x) {
    hit = TRUE;
  }
  if (hit) {
    hit = FALSE;
    sum = a->halfSize.y + b->halfSize.y;
    if (a->center.y - (s16)sum <= b->center.y && b->center.y - (s16)sum <= a->center.y) {
      hit = TRUE;
    }
    if (hit) {
      hit = FALSE;
      sum = a->halfSize.z + b->halfSize.z;
      if (a->center.z - (s16)sum <= b->center.z && b->center.z - (s16)sum <= a->center.z) {
        hit = TRUE;
      }
      if (hit) {
        ret = TRUE;
      }
    }
  }
  return ret;
#else
  INCFUNC("asm/func/Hitbox_CheckOverlap.inc");
#endif
}
