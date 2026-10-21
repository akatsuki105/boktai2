#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "vm.h"

// スクリプトから足せる飾りのスプライト1枚, 位置の補間とマーカー設定への追従を持つ
typedef struct {
  u8 unk_0[24];        // 0x00, どの関数も触っていない
  MainSpriteGfx gfx;   // 0x18, '.d' で指定したスプライトファイル (e.g. SPRITE_DJANGO_LARGE, SPRITE_E89F, SPRITE_UI_SOLARBANK)
  MainSprite sprite;   // 0x38
  u16 id;              // 0x98, '.n', スクリプトから枠を引くときの番号
  s16 moving;          // 0x9A, 0 以外なら pos を fromPos から toPos へ補間する
  bool16 markerGated;  // 0x9C, 0 以外なら gStat->markerEnabled に従って表示を切り替える
  s16 hiddenByScript;  // 0x9E, スクリプトから隠されているか
  u16 elapsed;         // 0xA0, 補間の経過フレーム
  u16 duration;        // 0xA2, 補間の全体フレーム数
  Vec3 pos;            // 0xA4, 現在位置
  Vec3 fromPos;        // 0xAC, 補間の始点
  Vec3 toPos;          // 0xB4, 補間の終点
} Entity8AF6Entry;
static_assert(sizeof(Entity8AF6Entry) == 188);

typedef struct {
  Entity e;                    // 0x00, ENTITY_UNK_9
  u8 count;                    // 0x18, '.m=1', 確保した枠数
  u8 used;                     // 0x19, 使用中の枠数, Update と Destroy はここまでしか回さない
  u8 unk_1a[2];                // 0x1A, 詰め物
  Entity8AF6Entry entries[1];  // 0x1C, 実際は count 個 (可変長)
} Entity8AF6;                  // Entity8AF6 はサイズが可変
static_assert(sizeof(Entity8AF6) == 216);

extern Entity8AF6* gEntity8AF6;  // 0x03002C4C

// '.n' と id が一致する枠を返す, 無ければ NULL
Entity8AF6Entry* Entity8AF6_FindEntry(void) {
  u32 id;
  s32 i;

  if (gEntity8AF6 == NULL) {
    return NULL;
  }

  if (!VM_SeekToNamedArg('n')) {
    return NULL;
  }

  id = VM_GetValue();
  for (i = 0; i < gEntity8AF6->used; i++) {
    if (gEntity8AF6->entries[i].id == id) {
      return &gEntity8AF6->entries[i];
    }
  }
  return NULL;
}

void Entity8AF6_SetPoseScripted(void) {
  Entity8AF6Entry* e = Entity8AF6_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('p')) {
    MainSprite_SetPose(&e->sprite, &e->gfx, VM_GetValue(), 0);
  }
}

// '.f' で左右反転を切り替える
void FUN_080a59e0(void) {
  Entity8AF6Entry* e = Entity8AF6_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('f')) {
    if (VM_GetValue()) {
      e->sprite.flags |= SPRFLAG_XFLIP;
    } else {
      e->sprite.flags &= ~SPRFLAG_XFLIP;
    }
  }
}

void Entity8AF6_HideScripted(void) {
  Entity8AF6Entry* e = Entity8AF6_FindEntry();

  if (e != NULL) {
    e->sprite.flags |= SPRFLAG_HIDDEN;
    if (e->markerGated != 0) {
      e->hiddenByScript = 1;
    }
  }
}

void Entity8AF6_ShowScripted(void) {
  Entity8AF6Entry* e = Entity8AF6_FindEntry();

  if (e != NULL) {
    e->sprite.flags &= ~SPRFLAG_HIDDEN;
    if (e->markerGated != 0) {
      e->hiddenByScript = 0;
    }
  }
}

void FUN_080a5a6c(void) {
  Entity8AF6Entry* e = Entity8AF6_FindEntry();

  if (e != NULL && VM_SeekToNamedArg('p')) {
    e->sprite.priority = VM_GetValue();
  }
}

NAKED void Entity8AF6_MoveToScripted(void) { INCFUNC("asm/func/Entity8AF6_MoveToScripted.inc"); }

NAKED void Entity8AF6Entry_Update(Entity8AF6Entry* p) { INCFUNC("asm/func/Entity8AF6Entry_Update.inc"); }

// 0xEAB4
NAKED void Entity8AF6_AddEntryScripted(void) { INCFUNC("asm/func/Entity8AF6_AddEntryScripted.inc"); }

s32 Entity8AF6_Update(Entity8AF6* p) {
  s32 i;

  for (i = 0; i < p->used; i++) {
    Entity8AF6Entry_Update(&p->entries[i]);
  }
  return 0;
}

s32 Entity8AF6_Destroy(Entity8AF6* p) {
  s32 i;

  for (i = 0; i < p->used; i++) {
    MainSprite_Remove(&p->entries[i].sprite);
  }
  gEntity8AF6 = NULL;
  return 0;
}

s32 Entity8AF6_Init(Entity8AF6* p, u32 param_2, u32 param_3, u8 count) {
  p->count = count;
  p->used = 0;
  gEntity8AF6 = p;
  return 0;
}

NAKED Entity8AF6* Entity8AF6_Create(u32 param_1, u32 param_2) { INCFUNC("asm/func/Entity8AF6_Create.inc"); }
