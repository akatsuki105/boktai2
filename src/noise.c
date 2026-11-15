#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "vm.h"

// 物音を毎フレーム集め, 敵の索敵 (Enemy の音への反応) に渡すシングルトン
// 物音はその場で鳴った位置と範囲で, 鳴らしたフレームの次のフレームで消える (NoiseManager_ExpireNoises)
// quietZones に登録したマップのゾーン (ZoneData) の中で鳴った音は登録しない

// 物音1件
typedef struct {
  Vec3 pos;   // 0x00, 鳴った位置, y は常に 0
  s16 size;   // 0x08, 聞こえる範囲 (正方形の半辺), 負なら空き枠
  u16 unk_a;  // 0x0A, 書くだけで読み手が見つかっていない
  u16 flags;  // 0x0C, NOISE_*, 敵は自分の聞き取るマスク (Enemy.unk_21d) と AND して反応する
  u16 id;     // 0x0E, 鳴らした Mover の id, 自分の鳴らした音には反応しない, 0 なら発生源なし
} Noise;
static_assert(sizeof(Noise) == 16);

typedef struct {
  Entity e;            // 0x00, ENTITY_UNK_5
  Noise noises[8];     // 0x18
  u32 quietZones[16];  // 0x98, 物音を登録しないゾーンの id (Map_IsPosInZoneByID), '.a' と Cmd_AddQuietZones / Cmd_RemoveQuietZones / Cmd_ClearQuietZones で出し入れする, 0 は空き
} NoiseManager;
static_assert(sizeof(NoiseManager) == 216);

#define NOISE_FLAG_0 (1 << 0)  // 敵や爆発が鳴らす普通の物音, Cmd_MakeNoise の '.f' の既定値
#define NOISE_NEW (1 << 2)     // このフレームに鳴った印, 次のフレームの NoiseManager_ExpireNoises で外れ, その次で消える
#define NOISE_GLOBAL (1 << 7)  // 範囲もマスクも見ずに必ず聞こえる (太陽警報機など)

static NoiseManager* sNoiseManager;  // 0x03001700

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

// pos が quietZones のどれかに入っているか
bool8 NoiseManager_IsInQuietZone(Vec3* pos) {
  u32* slot;
  s32 i;

  if (sNoiseManager == NULL) {
    return FALSE;
  }
  for (i = 0, slot = sNoiseManager->quietZones; i < 16; i++) {
    if ((s32)*slot > 0 && Map_IsPosInZoneByID(*slot, pos)) {
      return TRUE;
    }
    slot++;
  }
  return FALSE;
}

// NOISE_NEW が付いているものは印だけ外し, 外れているもの (前のフレームに鳴ったもの) は消す
void NoiseManager_ExpireNoises(void) {
  NoiseManager* p = sNoiseManager;

  if (p != NULL) {
    s32 i;

    for (i = 0; i < 8; i++) {
      if (p->noises[i].flags & NOISE_NEW) {
        p->noises[i].flags &= ~NOISE_NEW;
      } else {
        p->noises[i].size = -1;
        p->noises[i].flags = 0;
      }
    }
  }
}

// idx 番の物音の位置を out に入れ, 鳴らした Mover の id を返す
u16 NoiseManager_GetNoise(Vec3* out, s8 idx) {
  NoiseManager* p = sNoiseManager;
  if (p == NULL) {
    return 0;
  }

  out->x = p->noises[idx].pos.x;
  out->y = 0;
  out->z = p->noises[idx].pos.z;
  return p->noises[idx].id;
}

// (x, z) が quietZones に入っていなければ, 空いている枠に物音を登録する, MPF_LOUD のマップでは範囲を倍にする (MPF_LOUD を立てる処理は見つかっていない)
void NoiseManager_AddNoise(s16 x, s16 z, s16 size, s16 param_4, u8 flags, u16 moverID) {
  NoiseManager* p = sNoiseManager;
  Vec3 pos;

  if (p != NULL) {
    pos.x = x;
    pos.y = 0;
    pos.z = z;
    if (!NoiseManager_IsInQuietZone(&pos)) {
      s32 i;

      for (i = 0; i < 8; i++) {
        if (p->noises[i].size < 0) {
          p->noises[i].pos.x = x;
          p->noises[i].pos.y = 0;
          p->noises[i].pos.z = z;
          p->noises[i].id = moverID;
          if (TestMapFlag(MPF_LOUD)) {
            p->noises[i].size = (s16)size * 2;
          } else {
            p->noises[i].size = size;
          }
          p->noises[i].unk_a = param_4;
          p->noises[i].flags = flags | NOISE_NEW;
          return;
        }
      }
    }
  }
}

void NoiseManager_AddSimpleNoise(s16 x, s16 z, s16 size, s16 param_4) { NoiseManager_AddNoise(x, z, size, param_4, NOISE_FLAG_0, 0); }

void NoiseManager_AddNoiseWithFlags(s16 x, s16 z, s16 size, s16 param_4, u8 flags) { NoiseManager_AddNoise(x, z, size, param_4, flags, 0); }

void NoiseManager_AddMoverNoise(s16 x, s16 z, s16 size, s16 param_4, u8 flags, u16 moverID) { NoiseManager_AddNoise(x, z, size, param_4, flags, moverID); }

// (x, z) の周り size の範囲で聞こえる物音を start 番から探して添字を返す, mask と合わない音・このフレームに鳴った音・moverID 自身の音は除く, 無ければ -1
s8 NoiseManager_FindHeardNoise(s32 x, s32 y, s32 size, u8 mask, u16 moverID, s32 start) {
  NoiseManager* p = sNoiseManager;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  for (i = start; i < 8; i++) {
    Noise* data = &p->noises[i];

    if (!(data->flags & NOISE_NEW) && (data->id == 0 || data->id != moverID)) {
      if (data->flags & NOISE_GLOBAL) {
        return i;
      }
      if (data->size >= 0 && (data->flags & mask) && BoxesOverlap(data->pos.x, data->pos.z, data->size, x, y, size)) {
        return i;
      }
    }
  }
  return -1;
}

s8 NoiseManager_FindFirstHeardNoise(s32 x, s32 y, s32 size, u8 mask, u16 moverID) { return NoiseManager_FindHeardNoise(x, y, size, mask, moverID, 0); }

s8 NoiseManager_FindNextHeardNoise(s32 x, s32 y, s32 size, u8 mask, u16 moverID, s32 start) { return NoiseManager_FindHeardNoise(x, y, size, mask, moverID, start); }

s32 NoiseManager_Update(NoiseManager* p) {
  NoiseManager_ExpireNoises();
  return 1;
}

s32 NoiseManager_Destroy(NoiseManager* p) { sNoiseManager = NULL; }

s32 NoiseManager_Init(NoiseManager* p, u32 param_2, u32 param_3) {
  if (VM_SeekToNamedArg('a')) {
    u32* slot = p->quietZones;

    while (VM_GetPC() != NULL) {
      *slot++ = VM_GetValue();
    }
  }
  NoiseManager_ExpireNoises();
  sNoiseManager = p;
  return 1;
}

// 0x794C, HashName("ノイズマネージャ")
NoiseManager* NoiseManager_Create(u32 param_1, u32 param_2) {
  NoiseManager* p = CreateEntity(ENTITY_UNK_5, sizeof(NoiseManager));

  if (p != NULL) {
    SetEntityRoutine(p, NoiseManager_Update, NoiseManager_Destroy);
    if (NoiseManager_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 0x1693, HashName("ノイズセット"), '.p' の (x, z) に範囲 '.r', フラグ '.f' の物音を鳴らす
// 残差は 1 命令, 第 4 引数と第 6 引数の 0 を 1 本の r3 で共有する形
NON_MATCH void Cmd_MakeNoise(void) {
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
  NoiseManager_AddNoise(x, z, size, 0, flags, 0);
#else
  INCFUNC("asm/func/Cmd_MakeNoise.inc");
#endif
}

// quietZones から val を探して添字を返す, 無ければ空き枠の添字を負にして返す (空きも無ければ -16)
s32 NoiseManager_FindQuietZone(NoiseManager* p, u32 val) {
  s32 free = 16;
  s32 i;

  for (i = 0; i < 16; i++) {
    if (p->quietZones[i] == val) {
      return i;
    }
    if (p->quietZones[i] == 0) {
      free = i;
    }
  }
  return -free;
}

// 0x1422, '.a' のゾーン id を quietZones の空き枠に積む (登録済みなら何もしない)
void Cmd_AddQuietZones(void) {
  NoiseManager* p = sNoiseManager;

  if (p == NULL) {
    return;
  }
  if (!VM_SeekToNamedArg('a')) {
    return;
  }

  while (VM_GetPC() != NULL) {
    u32 val = VM_GetValue();
    s32 idx = NoiseManager_FindQuietZone(p, val);

    if (idx < 0) {
      p->quietZones[-idx] = val;
    }
  }
}

// 0xADB6, '.a' のゾーン id を quietZones から外す
void Cmd_RemoveQuietZones(void) {
  NoiseManager* p = sNoiseManager;

  if (p == NULL) {
    return;
  }
  if (!VM_SeekToNamedArg('a')) {
    return;
  }

  while (VM_GetPC() != NULL) {
    s32 idx = NoiseManager_FindQuietZone(p, VM_GetValue());

    if (idx >= 0) {
      p->quietZones[idx] = 0;
    }
  }
}

// 0x79EC, quietZones を全部空ける
void Cmd_ClearQuietZones(void) {
  NoiseManager* p = sNoiseManager;
  s32 i;

  if (p == NULL) {
    return;
  }

  for (i = 0; i < 16; i++) {
    p->quietZones[i] = 0;
  }
}

void FUN_08241000(void) { sNoiseManager = NULL; }
