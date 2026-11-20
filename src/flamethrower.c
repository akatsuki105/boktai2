#include "flamethrower.h"

#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "player.h"
#include "random.h"
#include "vm.h"

// ハッシュが 0x3C20 のもの(X)を見つければ
// X+「マネージャ」= 0x778B（FlamethrowerManager_Create）
// X+「追加」= 0xFD6B（Cmd_AddFlamethrower）
// X+「削除」= 0x9700（Cmd_RemoveFlamethrower）
// で一致する, 公式名称の"噴出火炎口"ではダメ
// このEntityは炎の噴射タイミングなどを管理して、炎 (Flame, flame.c) を生成するだけ

// 噴出火炎口1つ, スクリプトから置かれ, 出した炎が消えると FlamethrowerManager_Update が同じ設定で出し直す
typedef struct {
  Vec3 pos;        // 0x00, '.p'
  Vec3 unk_08;     // 0x08, '.a'
  s16 unk_10;      // 0x10, '.f[1]'..'.f[2]' の乱数, 太陽ゲージが満たないときは (10 - sunGauge) / 10 倍される
  s16 unk_12;      // 0x12, '.t', 同じく太陽ゲージで減る
  u16 unk_14;      // 0x14, '.n'
  u16 unk_16;      // 0x16, '.s' が立っていれば 1, Flame の flags になる
  u8 unk_18;       // 0x18, '.d'
  u8 unk_19;       // 0x19, '.f[0]'
  u16 slotIdx;     // 0x1A, usedMask 上の自分のビット番号
  Flame* spawned;  // 0x1C, 生成物, unk_136 が負 (解放済み) になったら作り直す
} Flamethrower;
static_assert(sizeof(Flamethrower) == 32);

// 噴出火炎口を12個まで抱えるシングルトン, ゲームオーバー中と gPlayerModes の PMODE_DEAD が立っている間は止まる
typedef struct {
  Entity e;                // 0x000, ENTITY_UNK_10
  Flamethrower elems[12];  // 0x018
  u32 usedMask;            // 0x198, elems のどのスロットが使用中かのビットマスク
} FlamethrowerManager;
static_assert(sizeof(FlamethrowerManager) == 412);

static FlamethrowerManager* gFlamethrowerManager;  // 0x03000180

void FlameManager_Create(void);
Flame* Flame_Spawn(Vec3* pos, u32 id, s32 unk_12e, s32 a, s32 b, s32 c, s32 power, s32 knockback, s32 iframes, s32 unk_130, u32 flags);

static inline bool8 FlamethrowerManager_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

// 通信中以外は太陽ゲージが満たないぶんだけ減らす
static inline s32 Flamethrower_ScaleBySun(s32 value) {
  if (gGameFlags & GAMEFLAG_LINK) {
    return value;
  }
  return Div(value * (10 - gStat->sunGauge), 10);
}

static inline void Flamethrower_Fire(Flamethrower* elem) {
  s32 unk_12 = Flamethrower_ScaleBySun(elem->unk_12);
  s32 unk_10 = Flamethrower_ScaleBySun(elem->unk_10);

  elem->spawned = Flame_Spawn(&elem->pos, elem->unk_14, unk_12, elem->unk_18, elem->unk_19, -1, elem->unk_08.x, elem->unk_08.y, elem->unk_08.z, unk_10, elem->unk_16);
}

// unk_14 が id の使用中の火炎放射器を探す, 無ければ NULL
Flamethrower* FlamethrowerManager_FindById(u32 id) {
  FlamethrowerManager* p = gFlamethrowerManager;
  s32 i;

  if (p == NULL) {
    return NULL;
  }
  for (i = 0; i < 12; i++) {
    if (FlamethrowerManager_IsActive(&p->usedMask, i) && p->elems[i].unk_14 == id) {
      return &p->elems[i];
    }
  }
  return NULL;
}

// 空いている枠を確保して返す, 無ければ NULL
Flamethrower* FlamethrowerManager_Alloc(FlamethrowerManager* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!FlamethrowerManager_IsActive(&p->usedMask, i)) {
      p->usedMask |= 1 << i;
      p->elems[i].slotIdx = i;
      return &p->elems[i];
    }
  }
  return NULL;
}

s32 FlamethrowerManager_Update(FlamethrowerManager* p) {
  Flamethrower* elems = p->elems;

  if (p->usedMask != 0 && !TEST_FLAGS((gGameFlags | gDebugGameFlags), GAMEFLAG_GAMEOVER) && !TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    Flamethrower* elem = elems;
    s32 i;

    for (i = 0; i < 12; i++) {
      if (elem->spawned != NULL && (s16)elem->spawned->unk_136 < 0) {
        Flamethrower_Fire(elem);
      }
      elem++;
    }
  }
  return 0;
}

s32 FlamethrowerManager_Destroy(FlamethrowerManager* p) {
  gFlamethrowerManager = NULL;
  return 0;
}

s32 FlamethrowerManager_Init(FlamethrowerManager* p, s32 unused) {
  FlameManager_Create();
  gFlamethrowerManager = p;
  return 0;
}

// 0x778B
FlamethrowerManager* FlamethrowerManager_Create(s32 param_1) {
  if (gFlamethrowerManager == NULL) {
    FlamethrowerManager* p = CreateEntity(ENTITY_UNK_10, sizeof(FlamethrowerManager));

    if (p != NULL) {
      SetEntityRoutine(p, FlamethrowerManager_Update, FlamethrowerManager_Destroy);
      if (FlamethrowerManager_Init(p, param_1) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gFlamethrowerManager;
}

// 0xFD6B, 命令列は一致, 残差はレジスタだけ (原典は 0x942 を r6 に載せ, オフセットの定数を r3 に置く)
NON_MATCH void Cmd_AddFlamethrower(void) {
#ifdef NONMATCHING_C
  Flamethrower* elem;

  if (TEST_FLAGS((gGameFlags | gDebugGameFlags), GAMEFLAG_GAMEOVER) || gFlamethrowerManager == NULL) {
    return;
  }
  elem = FlamethrowerManager_Alloc(gFlamethrowerManager);
  if (elem == NULL) {
    return;
  }
  if (VM_SeekToNamedArg('p')) {
    elem->pos.x = VM_GetValue(), elem->pos.y = VM_GetValue(), elem->pos.z = VM_GetValue();
  }
  if (VM_SeekToNamedArg('a')) {
    elem->unk_08.x = VM_GetValue(), elem->unk_08.y = VM_GetValue(), elem->unk_08.z = VM_GetValue();
  }
  if (VM_SeekToNamedArg('f')) {
    s32 min;
    s32 range;

    elem->unk_19 = VM_GetValue();
    min = VM_GetValue();
    range = VM_GetValue() - min;
    if (range == 0) {
      elem->unk_10 = 0;
    } else {
      elem->unk_10 = min + Mod(Random(), range);
    }
  }
  elem->unk_14 = VM_GetNamedArgValue('n', 0);
  elem->unk_18 = VM_GetNamedArgValue('d', 0);
  elem->unk_12 = VM_GetNamedArgValue('t', 0);
  elem->unk_16 = 0;
  if (VM_GetNamedArgValue('s', 0)) {
    elem->unk_16 = 1;
  }
  Flamethrower_Fire(elem);
#else
  INCFUNC("asm/func/Cmd_AddFlamethrower.inc");
#endif
}

void FlamethrowerManager_ClearGlobal(void) { gFlamethrowerManager = NULL; }

// 0x9700, '.n' で指された噴出火炎口を使用中マスクから外して消す
void Cmd_RemoveFlamethrower(void) {
  FlamethrowerManager* p = gFlamethrowerManager;
  Flamethrower* e;
  s32 id;
  s32 slot;

  if (p == NULL) {
    return;
  }
  id = VM_GetNamedArgValue('n', -1);
  if (id < 0) {
    return;
  }

  e = FlamethrowerManager_FindById(id);
  if (e == NULL) {
    return;
  }

  slot = (s16)e->slotIdx;
  p->usedMask &= ~(1 << slot);
  ClearMemory(e, sizeof(Flamethrower));
}
