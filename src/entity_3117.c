#include "entity.h"
#include "file.h"
#include "global.h"
#include "malloc.h"
#include "shadow.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vm.h"

// スクリプトから操る表示要素1個, 位置・パレット・スケールを frames かけて線形補間する
typedef struct {
  u16 id;                      // 0x00, '.n' で要素を引くときの識別子, gfx.plttID = id + 600
  u8 flags;                    // 0x02, bit0 位置補間中, bit1 パレット補間中, bit2 スケール補間中, bit3 アニメ再生中
  AuxAnimPlayFlags animFlags;  // 0x03, '.r', AddEntryScripted では '.f' が入り, 0 以外なら sprite に SPRFLAG_XFLIP を立てる
  u8 optionFlags;              // 0x04, '.A', bit0/bit1 をアニメコマンドの反転ビットと比べて sprite の XFLIP/YFLIP を決める
  u8 unk_05[3];                // 0x05
  rgb555 pltt[16];             // 0x08, パレット補間の書き込み先, gfx.pltt がここを指すように差し替えられる
  AuxSprite sprite;            // 0x28
  AuxSpriteGfx gfx;            // 0x54, ID は固定ではない ('.t')
  Vec3 srcPos;                 // 0x70, 位置補間の始点, 補間開始時の sprite.pos の写し
  Vec3 destPos;                // 0x78, '.p', 位置補間の終点
  u16 moveFrames;              // 0x80, '.f'
  u16 moveTick;                // 0x82, moveFrames に達すると flags bit0 が落ちる
  u16 plttBase;                // 0x84, gObjPlttData のパレット行の基準, gfx.plttID の写し
  u16 plttFrom;                // 0x86, '.s', plttBase からの相対行
  u16 plttTo;                  // 0x88, '.e', plttBase からの相対行
  u16 plttTick;                // 0x8A
  u16 plttFrames;              // 0x8C, '.f', 2未満なら補間せず plttTo の行をそのまま使う
  u16 unk_8e;                  // 0x8E
  u16 scaleFrom;               // 0x90, '.s', 0x40 が等倍の 6.6 固定小数
  u16 scaleTo;                 // 0x92, '.e', 等倍に戻ると sprite の SPRFLAG_AFFINE が落ちる
  u16 scaleTick;               // 0x94
  u16 scaleFrames;             // 0x96, '.f'
  u8 animIdx;                  // 0x98, '.m', animFile 内のアニメーション番号
  u8 animPlayMode;             // 0x99, '.d'
  bool8 runScriptOnAnimEnd;    // 0x9A, '.o', 0 以外ならアニメ終端で flags bit3 を落として scriptID を実行する
  u8 unk_9b;                   // 0x9B
  AuxAnimState anim;           // 0x9C
  AuxAnimFile* animFile;       // 0xAC, ID は固定ではない ('.m')
  u32 scriptID;                // 0xB0, '.e', アニメ終端で VM_ExecByID に渡す
  void* unk_b4;                // 0xB4, Malloc(0x40) の結果
} Entity3117Entry;
static_assert(sizeof(Entity3117Entry) == 184);

typedef struct Entity3117 {
  Entity e;                    // 0x00, ENTITY_UNK_9
  u8 capacity;                 // 0x18, entries の確保数, '.m=8' (0 なら 8)
  u8 count;                    // 0x19, 使用済みの entries 数, AddEntryScripted が capacity を上限に足す
  u8 unk_1a[2];                // 0x1A
  Entity3117Entry entries[1];  // 0x1C, 実際は capacity 個 (可変長)
} Entity3117;

COMMON_DATA Entity3117* gEntity3117 = NULL;  // 0x03002C48

// '.n' と id が一致する要素を返す, 無ければ NULL
Entity3117Entry* Entity3117_FindEntry(void) {
  u32 id;
  s32 i;

  if (gEntity3117 == NULL) {
    return NULL;
  }

  if (!VM_SeekToNamedArg('n')) {
    return NULL;
  }

  id = VM_GetValue();
  for (i = 0; i < gEntity3117->count; i++) {
    if (gEntity3117->entries[i].id == id) {
      return &gEntity3117->entries[i];
    }
  }
  return NULL;
}

NAKED void Entity3117_StartMoveScripted(void) { INCFUNC("asm/func/Entity3117_StartMoveScripted.inc"); }

void Entity3117_SetPoseScripted(void) {
  Entity3117Entry* e = Entity3117_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('p')) {
    e->sprite.poseIdx = VM_GetValue();
  }
}

void Entity3117_HideScripted(void) {
  Entity3117Entry* e = Entity3117_FindEntry();

  if (e != NULL) {
    e->sprite.flags |= SPRFLAG_HIDDEN;
  }
}

void Entity3117_ShowScripted(void) {
  Entity3117Entry* e = Entity3117_FindEntry();

  if (e != NULL) {
    e->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
}

void Entity3117_SetPriorityScripted(void) {
  Entity3117Entry* e = Entity3117_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('p')) {
    e->sprite.priority = VM_GetValue();
  }
}

NAKED void Entity3117_StartPlttFadeScripted(void) { INCFUNC("asm/func/Entity3117_StartPlttFadeScripted.inc"); }

NAKED void Entity3117_StartScaleScripted(void) { INCFUNC("asm/func/Entity3117_StartScaleScripted.inc"); }

NAKED void Entity3117_SetAnimScripted(void) { INCFUNC("asm/func/Entity3117_SetAnimScripted.inc"); }

NAKED void Entity3117_UpdateEntry(Entity3117Entry* e) { INCFUNC("asm/func/Entity3117_UpdateEntry.inc"); }

NAKED void Entity3117_AddEntryScripted(void) { INCFUNC("asm/func/Entity3117_AddEntryScripted.inc"); }

// 残差2命令 (24/26): 原典はループ条件を先頭と末尾の2箇所に持つ (agbcc の loop rotation) が, こちらは末尾だけになる
NON_MATCH s32 Entity3117_Update(Entity3117* p) {
#ifdef NONMATCHING_C
  Entity3117Entry* e;
  s32 i;

  for (i = 0, e = p->entries; i < p->count; i++, e++) {
    if (gEntityDisableFlags == 0 || e->optionFlags != 0) {
      Entity3117_UpdateEntry(e);
    }
  }
  return 0;
#else
  INCFUNC("asm/func/Entity3117_Update.inc");
#endif
}

s32 Entity3117_Destroy(Entity3117* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    AuxSprite_Remove(&p->entries[i].sprite);
    if (p->entries[i].unk_b4 != NULL) {
      ParticleShadow_Remove(p->entries[i].unk_b4);
      Free(p->entries[i].unk_b4);
    }
  }
  gEntity3117 = NULL;
  return 0;
}

s32 Entity3117_Init(Entity3117* p, u32 param_2, u32 param_3, s32 capacity) {
  p->capacity = capacity;
  p->count = 0;
  gEntity3117 = p;
  return 0;
}

Entity3117* Entity3117_Create(u32 param_1, u32 param_2) {
  Entity3117* p;
  s32 capacity;

  if (gEntity3117 != NULL) {
    return gEntity3117;
  }

  if (VM_SeekToNamedArg('m')) {
    capacity = VM_GetValue();
  } else {
    capacity = 1;
  }

  p = CreateEntity(ENTITY_UNK_9, sizeof(Entity3117Entry) * capacity + 0x1C);
  if (p != NULL) {
    SetEntityRoutine(p, Entity3117_Update, Entity3117_Destroy);
    if (Entity3117_Init(p, param_1, param_2, capacity) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
