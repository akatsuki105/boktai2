#include "entity.h"
#include "global.h"
#include "item.h"
#include "vm.h"

// おいしい水の効果時間を数え、0 になったらアイテムを消してスクリプトを実行するシングルトン
typedef struct EntityBA36 {
  Entity e;      // 0x00, ENTITY_UNK_8
  u16 timer;     // 0x18, '.c=1800', 残りフレーム数, _Update が毎フレーム -1. アドレスを FUN_0809c544 に渡して画面に出す
  u8 unk_1a[2];  // 0x1A, このモジュールは触らない, Entity4063 では同じ位置が bool16 cancelled
  u32 scriptID;  // 0x1C, '.p=0', timer が 0 になったとき VM_ExecByID に渡す, 0 なら何も実行しない
} EntityBA36;
static_assert(sizeof(EntityBA36) == 32);

extern EntityBA36* gEntityBA36;  // 0x03002C40

bool32 TryAddItem(item32_t n, s32 rotCount);
void FUN_0809c544(void* param_1);
void FUN_0809c58c(void);

static inline void Stat_SetFlag934(u16 bit) { gStat->unk_934 |= bit; }
static inline void Stat_ClearFlag934(u16 bit) { gStat->unk_934 &= ~bit; }

// 残りフレーム数を '.c' で入れ直し、おいしい水と画面のカウントダウンを揃える
void EntityBA36_SetRemaining(void) {
  s32 timer = VM_SeekToNamedArg('c') ? VM_GetValue() : 1800;

  gEntityBA36->timer = timer;
  if (gEntityBA36->timer != 0) {
    if (!CheckItemOwn(ITEM_TASTY_WATER)) {
      TryAddItem(ITEM_TASTY_WATER, 0);
    }
    FUN_0809c544(&gEntityBA36->timer);
  }
}

// 残りフレーム数を返す, Entity がいなければ 0
s32 EntityBA36_GetRemaining(void) {
  if (gEntityBA36 == NULL) {
    return 0;
  }
  return gEntityBA36->timer;
}

// 残り時間を1フレーム減らし、0 になったらおいしい水を回収してスクリプトを実行する
s32 EntityBA36_Update(EntityBA36* p) {
  if (p->timer == 0) {
    Stat_SetFlag934(SF934_UNK_12);
  } else {
    Stat_ClearFlag934(SF934_UNK_12);
    p->timer--;
    if (p->timer == 0) {
      if (CheckItemOwn(ITEM_TASTY_WATER)) {
        RemoveSpecifiedItem(ITEM_TASTY_WATER);
      }
      FUN_0809c58c();
      if (p->scriptID != 0) {
        VM_ExecByID(p->scriptID, NULL);
      }
    }
  }
  return 0;
}

// 効果が切れていなくてもおいしい水を回収する
s32 EntityBA36_Destroy(EntityBA36* p) {
  if (CheckItemOwn(ITEM_TASTY_WATER)) {
    RemoveSpecifiedItem(ITEM_TASTY_WATER);
  }
  gEntityBA36 = NULL;
  return 0;
}

s32 EntityBA36_Init(EntityBA36* p, u32 param_2, u32 param_3) {
  s32 v = VM_SeekToNamedArg('c');

  if (v != 0) {
    v = VM_GetValue();
  } else {
    v = 1800;
  }
  p->timer = v;

  v = VM_SeekToNamedArg('p');
  if (v != 0) {
    v = VM_GetValue();
  }
  p->scriptID = v;

  if (p->timer != 0) {
    if (!CheckItemOwn(ITEM_TASTY_WATER)) {
      TryAddItem(ITEM_TASTY_WATER, 0);
    }
    FUN_0809c544(&p->timer);
  }
  gEntityBA36 = p;
  return 0;
}

EntityBA36* EntityBA36_Create(u32 param_1, u32 param_2) {
  if (gEntityBA36 == NULL) {
    EntityBA36* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityBA36));
    if (p != NULL) {
      SetEntityRoutine(p, EntityBA36_Update, EntityBA36_Destroy);
      if (EntityBA36_Init(p, param_1, param_2) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntityBA36;
}
