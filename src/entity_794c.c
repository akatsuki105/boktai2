#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "vm.h"

// 物音やそれを使った索敵に関係？

typedef struct {
  Vec3 pos;   // 0x00
  s16 size;   // 0x08, 判定の半径, 負なら空き枠
  u16 unk_a;  // 0x0A
  u16 flags;  // 0x0C, bit2 は今のフレームに積まれた印(FLAG_2), 残りは探すときのマスク
  u16 id;     // 0x0E, moverID
} Entity794CData;
static_assert(sizeof(Entity794CData) == 16);

typedef struct {
  Entity e;                // 0x00, ENTITY_UNK_5
  Entity794CData data[8];  // 0x18
  u32 slots[16];           // 0x98, FUN_08240f20 が線形探索し Cmd_79EC が全部 0 に戻す
} Entity794C;
static_assert(sizeof(Entity794C) == 216);

#define FLAG_0 (1 << 0)
#define FLAG_2 (1 << 2)  // 今のフレームに積まれた印
#define FLAG_7 (1 << 7)

static Entity794C* sEntity794C;  // 0x03001700

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

// 2点が size1 + size2 の正方範囲に収まっているか
static bool8 BoxesOverlap(s32 x1, s32 y1, s32 size1, s32 x2, s32 y2, s32 size2) {
  s32 dx = abs(x1 - x2);
  s32 dy = abs(y1 - y2);
  s32 limit = size1 + size2;
  if (dx < limit && dy < limit) {
    return TRUE;
  }
  return FALSE;
}

bool8 FUN_08240b00(Vec3* pos) {
  u32* slot;
  s32 i;

  if (sEntity794C == NULL) {
    return FALSE;
  }
  for (i = 0, slot = sEntity794C->slots; i < 16; i++) {
    if ((s32)*slot > 0 && Map_IsPosInZoneByID(*slot, pos)) {
      return TRUE;
    }
    slot++;
  }
  return FALSE;
}

void FUN_08240b44(void) {
  Entity794C* p = sEntity794C;

  if (p != NULL) {
    s32 i;

    for (i = 0; i < 8; i++) {
      if (p->data[i].flags & FLAG_2) {
        p->data[i].flags &= ~FLAG_2;
      } else {
        p->data[i].size = -1;
        p->data[i].flags = 0;
      }
    }
  }
}

u16 FUN_08240b98(Vec3* out, s8 idx) {
  Entity794C* p = sEntity794C;
  if (p == NULL) {
    return 0;
  }

  out->x = p->data[idx].pos.x;
  out->y = 0;
  out->z = p->data[idx].pos.z;
  return p->data[idx].id;
}

// 原典はプロトタイプなしの K&R 定義 (呼び出し側は s16 のまま渡し, ここで u16 に切り詰める), その形で命令は 97/94, 残差は z が r7 に載らずスタックへ逃げる割当
NON_MATCH void FUN_08240bcc(s16 x, s16 z, s16 param_3, s16 param_4, u8 flags, u16 moverID) {
#ifdef NONMATCHING_C
  Entity794C* p = sEntity794C;
  Vec3 pos;

  if (p != NULL) {
    pos.x = x;
    pos.y = 0;
    pos.z = z;
    if (!FUN_08240b00(&pos)) {
      s32 i;

      for (i = 0; i < 8; i++) {
        if (p->data[i].size < 0) {
          p->data[i].pos.x = x;
          p->data[i].pos.y = 0;
          p->data[i].pos.z = z;
          p->data[i].id = moverID;
          if (TestMapFlag(MPF_UNK_7)) {
            p->data[i].size = (s16)param_3 * 2;
          } else {
            p->data[i].size = param_3;
          }
          p->data[i].unk_a = param_4;
          p->data[i].flags = flags | FLAG_2;
          return;
        }
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_08240bcc.inc");
#endif
}

void FUN_08240c9c(s16 x, s16 z, s16 param_3, s16 param_4) { FUN_08240bcc(x, z, param_3, param_4, FLAG_0, 0); }

void FUN_08240cc4(s16 x, s16 z, s16 param_3, s16 param_4, u8 flags) { FUN_08240bcc(x, z, param_3, param_4, flags, 0); }

void FUN_08240cf0(s16 x, s16 z, s16 param_3, s16 param_4, u8 flags, u16 moverID) { FUN_08240bcc(x, z, param_3, param_4, flags, moverID); }

s8 FUN_08240d20(s32 x, s32 y, s32 size, u8 mask, u16 moverID, s32 start) {
  Entity794C* p = sEntity794C;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  for (i = start; i < 8; i++) {
    Entity794CData* data = &p->data[i];

    if (!(data->flags & FLAG_2) && (data->id == 0 || data->id != moverID)) {
      if (data->flags & FLAG_7) {
        return i;
      }
      if (data->size >= 0 && (data->flags & mask) && BoxesOverlap(data->pos.x, data->pos.z, data->size, x, y, size)) {
        return i;
      }
    }
  }
  return -1;
}

s8 FUN_08240dc8(s32 x, s32 y, s32 size, u8 mask, u16 moverID) { return FUN_08240d20(x, y, size, mask, moverID, 0); }

s8 FUN_08240dec(s32 x, s32 y, s32 size, u8 mask, u16 moverID, s32 start) { return FUN_08240d20(x, y, size, mask, moverID, start); }

s32 Entity794C_Update(Entity794C* p) {
  FUN_08240b44();
  return 1;
}

s32 Entity794C_Destroy(Entity794C* p) { sEntity794C = NULL; }

s32 Entity794C_Init(Entity794C* p, u32 param_2, u32 param_3) {
  if (VM_SeekToNamedArg('a')) {
    u32* slot = p->slots;

    while (VM_GetPC() != NULL) {
      *slot++ = VM_GetValue();
    }
  }
  FUN_08240b44();
  sEntity794C = p;
  return 1;
}

Entity794C* Entity794C_Create(u32 param_1, u32 param_2) {
  Entity794C* p = CreateEntity(ENTITY_UNK_5, sizeof(Entity794C));

  if (p != NULL) {
    SetEntityRoutine(p, Entity794C_Update, Entity794C_Destroy);
    if (Entity794C_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 残差は 1 命令, 第 4 引数と第 6 引数の 0 を 1 本の r3 で共有する形
NON_MATCH void Cmd_1693(void) {
#ifdef NONMATCHING_C
  u16 x;
  u16 z;
  u16 size;
  u8 flags;

  if (VM_SeekToNamedArg('p')) {
    x = (VM_GetPC() != NULL) ? VM_GetValue() : 0;
    z = (VM_GetPC() != NULL) ? VM_GetValue() : 0;
  } else {
    x = 0;
    z = 0;
  }
  size = VM_GetNamedArgValue('r', 0);
  flags = VM_GetNamedArgValue('f', 1);
  FUN_08240bcc(x, z, size, 0, flags, 0);
#else
  INCFUNC("asm/func/Cmd_1693.inc");
#endif
}

s32 FUN_08240f20(Entity794C* p, u32 val) {
  s32 free = 16;
  s32 i;

  for (i = 0; i < 16; i++) {
    if (p->slots[i] == val) {
      return i;
    }
    if (p->slots[i] == 0) {
      free = i;
    }
  }
  return -free;
}

// 0x1422, '.a' の値を空き枠に積む
void Cmd_1422(void) {
  Entity794C* p = sEntity794C;

  if (p == NULL) {
    return;
  }
  if (!VM_SeekToNamedArg('a')) {
    return;
  }

  while (VM_GetPC() != NULL) {
    u32 val = VM_GetValue();
    s32 idx = FUN_08240f20(p, val);

    if (idx < 0) {
      p->slots[-idx] = val;
    }
  }
}

// 0xADB6,'.a' の値が入っている枠を空ける
void Cmd_ADB6(void) {
  Entity794C* p = sEntity794C;

  if (p == NULL) {
    return;
  }
  if (!VM_SeekToNamedArg('a')) {
    return;
  }

  while (VM_GetPC() != NULL) {
    s32 idx = FUN_08240f20(p, VM_GetValue());

    if (idx >= 0) {
      p->slots[idx] = 0;
    }
  }
}

// 0x79EC, 枠を全部空ける
void Cmd_79EC(void) {
  Entity794C* p = sEntity794C;
  s32 i;

  if (p == NULL) {
    return;
  }

  for (i = 0; i < 16; i++) {
    p->slots[i] = 0;
  }
}

void FUN_08241000(void) { sEntity794C = NULL; }
