#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sound.h"
#include "vm.h"

// TODO: attack_box.c という名前は不適切なのであとで用途が明確になったらリネームする

typedef struct {
  HitboxData hitbox;  // 0x00, AttackBox_Setup が Hitbox_Init / Hitbox_SetAttack / Hitbox_SetHandler に渡す
  Vec3 pos;           // 0x50, Hitbox_SetPos の第2引数, SpawnAttackBox が引数の Vec3 を8バイトまるごと写す
  u16 timer;          // 0x58, AttackBox_Update が毎フレーム +1, 10..15 の間だけ Hitbox_Register し、0x28 を超えると state を 2 にする
  u8 unk_5a[2];       // 0x5A
  u8 kind;            // 0x5C, SpawnAttackBox の第2引数, Cmd_1488 は 2 を入れる
  u8 state;           // 0x5D, PTR_ARRAY_085AD348 の添字, 0: 空き, 1: 判定中, 2: 解放
  s8 slot;            // 0x5E, 自分の添字, Alloc が書き、解放時に activeMask の該当ビットを落として 0xFF にする
  u8 unk_5f;          // 0x5F, padding?
  u32 unk_60;         // 0x60, SpawnAttackBox の第3引数, 0 かどうかで Hitbox_SetAttack の flags が変わる
} AttackBox;
static_assert(sizeof(AttackBox) == 100);

// 敵による爆発攻撃?, 5枠の攻撃判定プール, 敵やスクリプトが SpawnAttackBox で1枠借りる
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_10
  u32 activeMask;     // 0x18, 使用中の pool のビットマスク
  AttackBox pool[5];  // 0x1C, 根拠: _Update の stride 0x64 と AttackBox_Free の ClearMemory(box, 0x64)
} AttackBoxManager;
static_assert(sizeof(AttackBoxManager) == 528);

IWRAM_DATA AttackBoxManager* gAttackBoxManager = NULL;  // 0x03000170

AttackBoxManager* AttackBoxManager_Create(void);

static inline bool8 AttackBoxManager_IsSlotUsed(AttackBoxManager* p, s32 i) {
  if (TEST_FLAGS(p->activeMask, 1 << i)) return TRUE;
  return FALSE;
}

NAKED void FUN_080dd4fc(AttackBox* box) { INCFUNC("asm/func/FUN_080dd4fc.inc"); }

// 通信中でない通常の判定のとき、9〜12フレームごとに1回だけ効果音を鳴らす
void FUN_080dd6f4(AttackBox* box) {
  if (!(gGameFlags & FLAG030047A4_LINK) && box->unk_60 == 0) {
    if (Mod(box->timer, 9 + (Random() & 3)) == 0) {
      PlaySound_082406e0(SONG_825);
    }
  }
}

// 借りた枠に 0x100 角の判定を作って攻撃値を入れる
void AttackBox_Setup(AttackBox* box, s32 power, s32 knockback, s32 invincibleTime, s32 ignoreMask) {
  HitboxData* hitbox = &box->hitbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, Q8(1), Q8(1), Q8(1));
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, ignoreMask, &halfSize, &offset);
  if (box->unk_60 == 0) {
    Hitbox_SetAttack(hitbox, power, knockback, 0x40, HBATTR_INKA | HBATTR_18 | HBATTR_FLAME, invincibleTime);  // 0x40 は武器以外の攻撃
  } else {
    Hitbox_SetAttack(hitbox, power, knockback, 0x40, HBATTR_18, invincibleTime);
  }

  hitbox->id = 0x3246;
  Hitbox_SetPos(hitbox, &box->pos, 0);
  Hitbox_SetHandler(hitbox, NULL, box);
}

// state 0 (空き枠) の更新, 何もしない
void AttackBox_Idle(AttackBoxManager* p, AttackBox* box) {}

// state 1 (判定中) の更新, 10..15 フレームの間だけ判定を登録し、0x28 を超えたら解放へ回す
void AttackBox_Update(AttackBoxManager* p, AttackBox* box) {
  FUN_080dd4fc(box);
  FUN_080dd6f4(box);

  if (box->timer >= 10 && box->timer <= 15) {
    Hitbox_Register(&box->hitbox);
  }

  if (box->timer > 40) {
    box->state = 2;
  } else {
    box->timer++;
  }
}

// 枠を返却する, activeMask のビットを落として中身を消す
void AttackBox_Free(AttackBoxManager* p, AttackBox* box) {
  box->state = 0;
  CLEAR_BIT(p->activeMask, box->slot);
  box->slot = -1;
  ClearMemory(box, sizeof(AttackBox));
}

// 空いている枠を1つ確保して返す, 全部埋まっていれば NULL
AttackBox* AttackBoxManager_Alloc(AttackBoxManager* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    if (!AttackBoxManager_IsSlotUsed(p, i)) {
      AttackBox* box = &p->pool[i];

      box->slot = i;
      p->activeMask |= 1 << i;
      return box;
    }
  }

  return NULL;
}

// 持ち主のいない判定を1つ出す, マネージャが無ければ作る
s32 SpawnAttackBox(Vec3* pos, u32 kind, u32 unk_60, s32 power, s32 knockback, s32 invincibleTime, s32 ignoreMask) {
  if (pos != NULL) {
    AttackBoxManager* mgr = gAttackBoxManager;
    AttackBox* box;

    if (mgr == NULL) {
      mgr = AttackBoxManager_Create();
      if (mgr == NULL) {
        return 0;
      }
    }

    box = AttackBoxManager_Alloc(mgr);
    if (box != NULL) {
      box->state = 1;
      box->pos = *pos;
      box->timer = 0;
      box->kind = kind;
      box->unk_60 = unk_60;
      AttackBox_Setup(box, power, knockback, invincibleTime, ignoreMask);
    }
  }

  return 0;
}

// 0x1488, スクリプトから判定を1つ出す, '.p' が座標, '.P' が攻撃値4つ
// ダイナマイトを取得するイベントでの爆発で利用していた
void Cmd_1488(void) {
  AttackBoxManager* mgr = gAttackBoxManager;
  AttackBox* box;
  s32 power;
  s32 knockback;
  s32 invincibleTime;
  s32 ignoreMask;

  if (mgr == NULL) {
    mgr = AttackBoxManager_Create();
    if (mgr == NULL) {
      return;
    }
  }

  box = AttackBoxManager_Alloc(mgr);
  if (box == NULL) {
    return;
  }

  if (VM_SeekToNamedArg('p')) {
    box->pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    box->pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    box->pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }

  if (VM_SeekToNamedArg('P')) {
    power = VM_GetPC() != NULL ? (s16)VM_GetValue() : 0;
    knockback = VM_GetPC() != NULL ? (s16)VM_GetValue() : 0;
    invincibleTime = VM_GetPC() != NULL ? (s16)VM_GetValue() : 0;
    ignoreMask = VM_GetPC() != NULL ? (s16)VM_GetValue() : 0;
  } else {
    power = 0;
    knockback = 0;
    invincibleTime = 0;
    ignoreMask = 0;
  }

  box->unk_60 = VM_GetNamedArgValue('c', 0);
  box->state = 1;
  box->timer = 0;
  box->kind = 2;
  AttackBox_Setup(box, power, knockback, invincibleTime, ignoreMask);
}

void (*const sAttackBoxUpdates[3])(AttackBoxManager*, AttackBox*) = {
    AttackBox_Idle,
    AttackBox_Update,
    AttackBox_Free,
};  // 0x085AD348

// 使用中の枠について state ごとの更新関数を呼ぶ
s32 AttackBoxManager_Update(AttackBoxManager* p) {
  if (p->activeMask != 0) {
    s32 i;
    for (i = 0; i < 5; i++) {
      if (AttackBoxManager_IsSlotUsed(p, i)) {
        AttackBox* box = &p->pool[i];
        sAttackBoxUpdates[box->state](p, box);
      }
    }
  }
  return 0;
}

s32 AttackBoxManager_Destroy(AttackBoxManager* p) {
  gAttackBoxManager = NULL;
  return 0;
}

void FUN_080ddab4(AttackBoxManager* p) {}

s32 AttackBoxManager_Init(AttackBoxManager* p, u32 unused1) {
  FUN_080ddab4(p);
  gAttackBoxManager = p;
  return 0;
}

AttackBoxManager* AttackBoxManager_Create(void) {
  if (gAttackBoxManager == NULL) {
    AttackBoxManager* p = CreateEntity(ENTITY_UNK_10, sizeof(AttackBoxManager));
    if (p != NULL) {
      SetEntityRoutine(p, AttackBoxManager_Update, AttackBoxManager_Destroy);
      if (AttackBoxManager_Init(p, 0) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gAttackBoxManager;
}

void FUN_080ddb1c(void) { gAttackBoxManager = NULL; }
