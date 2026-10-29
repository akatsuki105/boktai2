#include "camera.h"
#include "camera_inline.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "inline.h"
#include "particle.h"
#include "trig.h"

// 数字を1桁ずつ Particle で表示する枠, 同時に4つまで出せる
typedef struct DamageNumber {
  s32 key;             // 0x00, DamageNumberManager_FindSlotByKey の検索キー
  u8 priority;         // 0x04, 空きがないとき これ以下の枠は奪われる
  u8 stateTimer;       // 0x05, state が変わると 0 に戻る
  u8 state;            // 0x06, PTR_ARRAY_085aba9c の添字
  u8 digitCount;       // 0x07, 使っている digits の数 (0..4), s32_ARRAY_085aba88 の添字でもある
  u16 unk_08;          // 0x08
  s16 unk_0a;          // 0x0A, unk_08 + 6
  WorldPos pos;        // 0x0C, ワールド座標
  Particle digits[4];  // 0x14, 1桁につき1個, こっちの .pos にはスクリーン座標を入れる
} DamageNumber;
static_assert(sizeof(DamageNumber) == 180);

// ダメージ値などの数字を画面に浮かせて出す
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_9
  u32 activeMask;         // 0x018, slots 1つにつき1bit
  ParticleGroup* group;   // 0x01C, PTCL_GROUP_1
  DamageNumber slots[4];  // 0x020
} DamageNumberManager;
static_assert(sizeof(DamageNumberManager) == 752);

void Particle_AddToDrawList(Particle* p, SpriteFlags flags);

static DamageNumberManager* sDamageNumberManager;  // 0x03000130

const s32 s32_ARRAY_085aba88[5] = {0, 0, -3, -6, -9};  // 0x085ABA88

void DamageNumberManager_ClearGlobal(void) { sDamageNumberManager = NULL; }

void DamageNumberManager_SetSlotActive(DamageNumberManager* p, u32 idx) { p->activeMask |= 1 << idx; }

void DamageNumberManager_ClearSlotActive(DamageNumberManager* p, u32 idx) { p->activeMask &= ~(1 << idx); }

u32 DamageNumberManager_IsSlotActive(DamageNumberManager* p, u32 idx) { return p->activeMask & 1 << idx; }

// key の使用中の枠を探す, 無ければ -1
s32 DamageNumberManager_FindSlotByKey(DamageNumberManager* p, s32 key) {
  DamageNumber* slot = p->slots;
  s32 i;

  for (i = 0; i < 4; i++, slot++) {
    if (DamageNumberManager_IsSlotActive(p, i) && slot->key == key) {
      return i;
    }
  }
  return -1;
}

// 空いている枠を探す, 無ければ priority 以下の枠を奪う, それも無ければ -1
s32 DamageNumberManager_FindFreeSlot(DamageNumberManager* p, s32 priority) {
  DamageNumber* slot;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (!DamageNumberManager_IsSlotActive(p, i)) {
      return i;
    }
  }
  slot = p->slots;
  for (i = 0; i < 4; i++, slot++) {
    if (slot->priority <= priority) {
      return i;
    }
  }
  return -1;
}

// 数字を桁ごとのパーティクルに分けて並べ, 浮き始めの位置に置いて描画リストに入れる, 5 桁目以上は捨てる
// 残差は r8/r9/r10 の割り当て順と slot->digits の番地の置き場所 (257/259命令)
NON_MATCH s32 FUN_0805f774(DamageNumberManager* p, DamageNumber* slot, u32 amount, s32 base, Vec3* vp) {
#ifdef NONMATCHING_C
  Particle* digit;
  s32 i;
  s32 n;

  for (i = 0; i < slot->digitCount; i++) {
    Particle_Remove(&slot->digits[i]);
  }
  slot->digitCount = 0;
  slot->unk_08 = vp->y;
  slot->unk_0a = vp->y + 6;
  digit = slot->digits;

  while (amount >= 10000) {
    amount -= 10000;
  }
  n = 0;
  while (amount >= 1000) {
    n++;
    amount -= 1000;
  }
  Particle_SetPose(&slot->digits[3], p->group, base + n);
  if (n > 0) {
    slot->digitCount = 4;
  }
  n = 0;
  while (amount >= 100) {
    n++;
    amount -= 100;
  }
  Particle_SetPose(&slot->digits[2], p->group, base + n);
  if (slot->digitCount == 0 && n > 0) {
    slot->digitCount = 3;
  }
  n = 0;
  while (amount >= 10) {
    n++;
    amount -= 10;
  }
  Particle_SetPose(&slot->digits[1], p->group, base + n);
  if (slot->digitCount == 0 && n > 0) {
    slot->digitCount = 2;
  }
  n = 0;
  while (amount != 0) {
    n++;
    amount--;
  }
  Particle_SetPose(digit, p->group, base + n);
  if (slot->digitCount == 0) {
    slot->digitCount = 1;
  }

  for (i = 0; i < slot->digitCount; i++, digit++) {
    Vec3 screen;
    s32 angle = slot->stateTimer * 16 + i * 32;

    if (angle > 0x80) {
      angle = 0x80;
    }
    WorldToScreen(&screen, &slot->pos);
    digit->pos.x = screen.x - i * 5 - s32_ARRAY_085aba88[slot->digitCount];
    digit->pos.y = screen.y - FixToInt(12, SIN(angle) * 16);
    Particle_AddToDrawList(digit, 0);
  }
#else
  INCFUNC("asm/func/FUN_0805f774.inc");
#endif
}

// 枠に位置と数字を入れて桁のパーティクルを並べ, 使用中にする
s32 FUN_0805f9a8(DamageNumberManager* p, s32 idx, s32 amount, s32 kind, Vec3* pos, Vec3* offset, s32 key, s32 priority) {
  DamageNumber* slot = &p->slots[idx];
  Vec3 vp;

  slot->key = key;
  slot->priority = priority;
  slot->stateTimer = 0;
  slot->state = 0;
  slot->pos = *pos;
  slot->pos.x += offset->x;
  slot->pos.y += offset->y;
  slot->pos.z += offset->z;
  WorldToScreen(&vp, &slot->pos);
  if (priority == 0 || priority == 2) {
    FUN_0805f774(p, slot, amount, kind == 0 ? 0x20 : 0x2A, &vp);
  } else {
    FUN_0805f774(p, slot, amount, kind == 0 ? 0x34 : 0x3E, &vp);
  }
  DamageNumberManager_SetSlotActive(p, idx);
}

// 枠の桁を全部外して空きにする
void DamageNumberManager_ReleaseSlot(DamageNumberManager* p, s32 idx) {
  DamageNumber* slot = &p->slots[idx];
  s32 i;

  for (i = 0; i < slot->digitCount; i++) {
    Particle_Remove(&slot->digits[i]);
  }
  slot->digitCount = 0;
  DamageNumberManager_ClearSlotActive(p, idx);
}

void DamageNumberManager_NextState(DamageNumber* slot) {
  slot->state++;
  slot->stateTimer = 0;
}

// 桁を1つずつ時間差で浮かせ, 20 フレームで次の状態へ
s32 DamageNumberManager_UpdateSlotRise(DamageNumberManager* p, DamageNumber* slot, s32 idx) {
  Vec3 vp;
  Particle* digit;
  s32 i;

  WorldToScreen(&vp, &slot->pos);
  digit = slot->digits;
  for (i = 0; i < slot->digitCount; i++, digit++) {
    s32 angle = slot->stateTimer * 16 + i * 32;

    if (angle > 0x60) {
      angle = 0x60;
    }
    digit->pos.x = vp.x - i * 5 - s32_ARRAY_085aba88[slot->digitCount];
    digit->pos.y = vp.y - FixToInt(12, SIN(angle) * 16);
  }
  if (++slot->stateTimer >= 20) {
    DamageNumberManager_NextState(slot);
  }
  return 0;
}

// 桁を浮かせ切った高さで止めて表示し, 10 フレームで枠を空ける
// 桁を浮かせ切った高さで止めて表示し, 10 フレームで枠を空ける
// x を i * 5 で引く形にすると (UpdateSlotRise はこれで一致) 125/123 命令, 残差は SIN(0x60) をループ外へ出して高位レジスタを1本余計に使うこと
NON_MATCH s32 DamageNumberManager_UpdateSlotHold(DamageNumberManager* p, DamageNumber* slot, s32 idx) {
#ifdef NONMATCHING_C
  Vec3 vp;
  Particle* digit;
  s32 i;

  WorldToScreen(&vp, &slot->pos);
  digit = slot->digits;
  for (i = 0; i < slot->digitCount; i++, digit++) {
    digit->pos.x = vp.x - i * 5 - s32_ARRAY_085aba88[slot->digitCount];
    digit->pos.y = vp.y - FixToInt(12, SIN(0x60) * 16);
  }
  if (++slot->stateTimer >= 10) {
    DamageNumberManager_ReleaseSlot(p, idx);
  }
  return 0;
#else
  INCFUNC("asm/func/DamageNumberManager_UpdateSlotHold.inc");
#endif
}

s32 (*const PTR_ARRAY_085aba9c[2])(DamageNumberManager*, DamageNumber*, s32) = {
    DamageNumberManager_UpdateSlotRise,
    DamageNumberManager_UpdateSlotHold,
};  // 0x085ABA9C

s32 DamageNumberManager_Update(DamageNumberManager* p) {
  DamageNumber* slot = p->slots;
  s32 i;

  for (i = 0; i < 4; i++, slot++) {
    if (DamageNumberManager_IsSlotActive(p, i)) {
      PTR_ARRAY_085aba9c[slot->state](p, slot, i);
    }
  }
  return 0;
}

s32 DamageNumberManager_Destroy(DamageNumberManager* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    DamageNumberManager_ReleaseSlot(p, i);
  }
  sDamageNumberManager = NULL;
  return 0;
}

s32 DamageNumberManager_Init(DamageNumberManager* p) {
  DamageNumber* slot;
  s32 i;

  sDamageNumberManager = p;
  p->group = GetParticleGroup(PTCL_GROUP_1);
  p->activeMask = 0;
  slot = p->slots;
  for (i = 0; i < 4; i++, slot++) {
    Particle* digit = slot->digits;
    s32 j;

    for (j = 0; j < 4; j++, digit++) {
      Particle_Setup(digit, p->group, SPRFLAG_UNK_16 | SPRFLAG_SCREEN_COORD);
      Particle_SetOffset(digit, -4, -4);
      Particle_SetPose(digit, p->group, PTCL1_NUM_WHITE(0));
      digit->priority = 1;
    }
    slot->priority = 3;
    slot->digitCount = 0;
  }
  return 0;
}

DamageNumberManager* DamageNumberManager_Create(void) {
  DamageNumberManager* p;

  if (sDamageNumberManager != NULL) {
    return sDamageNumberManager;
  }
  p = CreateEntity(ENTITY_UNK_9, sizeof(DamageNumberManager));
  if (p != NULL) {
    SetEntityRoutine(p, DamageNumberManager_Update, DamageNumberManager_Destroy);
    if (DamageNumberManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// hitbox ごとに枠を 1 つ割り当てて数字を出す, 同じ hitbox なら同じ枠を使い直す, kind は 0 = ダメージ, 1 = 回復 (未確定)
s32 CreateDamageNumber(HitboxData* hitbox, s32 amount, s32 kind, Vec3* pos, Vec3* param_5, s32 priority) {
  DamageNumberManager* p = sDamageNumberManager;
  s32 key;
  s32 idx;

  if (p == NULL) {
    p = DamageNumberManager_Create();
    if (p == NULL) {
      return -1;
    }
  }
  key = (s32)hitbox << 16 | hitbox->id;
  idx = DamageNumberManager_FindSlotByKey(p, key);
  if (idx < 0) {
    idx = DamageNumberManager_FindFreeSlot(p, priority);
    if (idx < 0) {
      return -1;
    }
  } else if (priority < p->slots[idx].priority) {
    return -1;
  }
  return FUN_0805f9a8(p, idx, amount, kind, pos, param_5, key, priority);
}
