#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

// 持ち主の足元に置く影 (AuxSprite 版), AuxShadowManager がリストで管理して毎フレーム fn を呼ぶ
// 高さが増えるほど scale を小さくする, ParticleShadow と違った"高級"な影
typedef struct AuxShadow {
  u8 active;               // 0x00, AuxShadowManager_Add でリストに入れると 1, AuxShadowManager_Remove で外すと 0
  u8 kind;                 // 0x01, 0 なら fn = AuxShadow_FollowGround (床に追従), それ以外は AuxShadow_UpdateNone
  u8 flags;                // 0x02, bit0: AuxShadow_FollowGround で当たり判定マップでなく pos->y を高さに使う
  u8 unk_03;               // 0x03
  u16 unk_04;              // 0x04, AuxShadow_Init で 0
  u16 unk_06;              // 0x06, AuxShadow_Init で 0
  Vec3* pos;               // 0x08, 持ち主の座標, AuxShadow_FollowGround が x/y/z を読む
  AuxSprite sprite;        // 0x0C, 根拠: FUN_0822a470 / FUN_0822a4e0
  AuxSpriteGfx gfx;        // 0x38, 根拠: Video_GetAuxSprite(EFF_1C1B) / FUN_0822a470
  s8 scale;                // 0x54, AuxShadow_FollowGround が高さから計算して sprite.scaleX/Y に入れる, 1 未満なら 1
  u8 farScale;             // 0x55, 高さが farHeight を超えたときの scale
  u8 baseScale;            // 0x56, 接地時の scale, 高さに応じてここから引く
  u8 unk_57;               // 0x57, AuxShadow_Init の第6引数
  s16 farHeight;           // 0x58
  s16 nearHeight;          // 0x5A
  u16 farShift;            // 0x5C, nearHeight 以上 farHeight 以下のとき baseScale - (高さ >> farShift)
  u16 nearShift;           // 0x5E, nearHeight 未満のとき baseScale - (高さ >> nearShift)
  void* fn;                // 0x60, AuxShadowManager_Update が影を引数にして呼ぶ
  struct AuxShadow* prev;  // 0x64
  struct AuxShadow* next;  // 0x68
} AuxShadow;
static_assert(sizeof(AuxShadow) == 108);  // next (0x68) までは確定, それ以降に続くかは未確認

typedef struct AuxShadowManager {
  Entity e;            // 0x00, ENTITY_UNK_9
  u8 unk_18[4];        // 0x18, 参照なし
  AuxShadow* shadows;  // 0x1C, 影のリストの先頭, Init で 0, AuxShadowManager_Add / AuxShadowManager_Remove / Update
} AuxShadowManager;
static_assert(sizeof(AuxShadowManager) == 32);

extern AuxShadowManager* gAuxShadowManager;  // 0x03000054

void FUN_0822a4fc(AuxSprite* p, AuxSpriteGfx* s);
void AuxShadow_UpdateNone(void);
void AuxShadow_FollowGround(AuxShadow* shadow);

void FUN_08013920(void) { gAuxShadowManager = NULL; }

// 影のリストの先頭に繋ぐ
s32 AuxShadowManager_Add(AuxShadowManager* p, AuxShadow* shadow) {
  AuxShadow* head;

  if (shadow->active != 0) return -1;

  shadow->prev = NULL;
  head = p->shadows;
  shadow->next = head;
  if (head != NULL) {
    head->prev = shadow;
  }
  p->shadows = shadow;
  shadow->active = 1;
  return 0;
}

// 影のリストから外す
s32 AuxShadowManager_Remove(AuxShadowManager* p, AuxShadow* shadow) {
  AuxShadow* prev = shadow->prev;
  AuxShadow* next = shadow->next;

  if (shadow->active == 0) return -1;

  if (prev != NULL) {
    prev->next = next;
  } else {
    p->shadows = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
  shadow->active = 0;
  return 0;
}

// 影を表示し、床に追従する更新関数に切り替えてすぐ1回呼ぶ
void AuxShadow_Show(AuxShadow* shadow) {
  shadow->sprite.flags &= ~SPRFLAG_HIDDEN;
  shadow->fn = AuxShadow_FollowGround;
  ((void (*)(AuxShadow*))shadow->fn)(shadow);
}

// 影を非表示にし、何もしない更新関数に切り替える
void AuxShadow_Hide(AuxShadow* shadow) {
  shadow->sprite.flags |= SPRFLAG_HIDDEN;
  shadow->fn = AuxShadow_UpdateNone;
}

void AuxShadow_UpdateNone(void) {}

// 持ち主の足元の床の高さに影を置き、持ち主の高さに応じて縮め、床がない・持ち主より高い・特定の床なら非表示にする
NON_MATCH void AuxShadow_FollowGround(AuxShadow* shadow) {
#ifdef NONMATCHING_C
  s32 bx = shadow->pos->x >> 8;
  s32 bz = shadow->pos->z >> 8;
  u16 idx;
  s32 i;
  u8* tile;
  u32 h;
  u32 kind;
  s32 dy;

  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    i = 0;
  } else {
    i = gCollisionMap->q_rowOffsets[bz] + bx;
  }
  idx = i;
  shadow->sprite.q_pos.x = shadow->pos->x;
  if (shadow->flags & 1) {
    shadow->sprite.q_pos.y = shadow->pos->y;
  } else {
    Vec3* pos = shadow->pos;

    tile = (u8*)FUN_08234224(idx, 1);
    if (tile != NULL) {
      tile += 4;
    } else {
      tile = (u8*)&gCollisionMap->tiledata->tiles[idx];
    }
    h = *tile;
    kind = h >> 4;
    h = (h & 0xF) << 8;
    switch (kind) {
      case 1: {
        h -= (u8)pos->z;
        break;
      }
      case 2: {
        h -= (u8)pos->x;
        break;
      }
    }
    shadow->sprite.q_pos.y = h;
  }
  shadow->sprite.q_pos.z = shadow->pos->z;

  dy = shadow->pos->y - shadow->sprite.q_pos.y;
  if (dy <= 0) {
    shadow->scale = shadow->baseScale;
  } else if (dy < shadow->nearHeight) {
    shadow->scale = shadow->baseScale - (dy >> shadow->nearShift);
  } else if (dy > shadow->farHeight) {
    shadow->scale = shadow->farScale;
  } else {
    shadow->scale = shadow->baseScale - (dy >> shadow->farShift);
  }
  if (shadow->scale <= 0) {
    shadow->scale = 1;
  }
  shadow->sprite.scaleX = shadow->scale;
  shadow->sprite.scaleY = shadow->scale;

  if (shadow->pos->y >= shadow->sprite.q_pos.y && shadow->sprite.q_pos.y != 0) {
    tile = (u8*)FUN_08234224(idx, 1);
    if (tile != NULL) {
      tile += 4;
    } else {
      tile = (u8*)&gCollisionMap->tiledata->tiles[idx];
    }
    if (!(((u16*)tile)[1] & 0x20)) {  // 元は読んだ値が r0、0x20 が r1。この形だと逆になる
      goto show;
    }
  }
  shadow->sprite.flags |= 1;
  return;

show:
  shadow->sprite.flags &= ~1;
#else
  INCFUNC("asm/func/AuxShadow_FollowGround.inc");
#endif
}

// 影のリストをたどり、それぞれの更新関数を呼ぶ
s32 AuxShadowManager_Update(AuxShadowManager* p) {
  AuxShadow* shadow;

  for (shadow = p->shadows; shadow != NULL; shadow = shadow->next) {
    ((void (*)(AuxShadow*))shadow->fn)(shadow);
  }
  return 0;
}

s32 AuxShadowManager_Destroy(AuxShadowManager* p) {
  gAuxShadowManager = NULL;
  return 0;
}

s32 AuxShadowManager_Init(AuxShadowManager* p, u32 _) {
  gAuxShadowManager = p;
  p->shadows = NULL;
  return 0;
}

AuxShadowManager* AuxShadowManager_Create(u32 unused1, u32 unused2) {
  AuxShadowManager* p = CreateEntity(ENTITY_UNK_9, sizeof(AuxShadowManager));
  if (p != NULL) {
    SetEntityRoutine(p, AuxShadowManager_Update, AuxShadowManager_Destroy);
    if (AuxShadowManager_Init(p, unused1) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 影を初期化して描画リストと影のリストに繋ぐ (管理エンティティがなければ作る)
s32 AuxShadow_Init(AuxShadow* shadow, Vec3* pos, s32 scale, s32 farScale, s32 baseScale, s32 unk_57, s32 farHeight, s32 nearHeight, s32 farShift, s32 nearShift, s32 kind) {
  AuxShadowManager* mgr = gAuxShadowManager;
  AuxSpriteGfx* gfx;
  AuxSprite* sprite;

  if (mgr == NULL && (mgr = AuxShadowManager_Create(0, 0)) == NULL) return -1;

  shadow->active = 0;
  shadow->pos = pos;
  shadow->kind = kind;
  shadow->flags = 0;
  shadow->unk_04 = 0;
  shadow->unk_06 = 0;
  shadow->scale = scale;
  shadow->farScale = farScale;
  shadow->baseScale = baseScale;
  shadow->unk_57 = unk_57;
  shadow->farHeight = farHeight;
  shadow->nearHeight = nearHeight;
  shadow->farShift = farShift;
  shadow->nearShift = nearShift;
  if (shadow->kind == 0) {
    shadow->fn = AuxShadow_FollowGround;
  } else {
    shadow->fn = AuxShadow_UpdateNone;
  }
  gfx = &shadow->gfx;
  Video_GetAuxSprite(gfx, SPRITE_EFF_1C1B);
  sprite = &shadow->sprite;
  FUN_0822a470(sprite, gfx, SPRFLAG_BLINK_ODD | SPRFLAG_AFFINE);
  sprite->q_metaspriteIdx = 5;
  shadow->sprite.priority = 2;
  AuxShadowManager_Add(mgr, shadow);
  return 0;
}

// 影を描画リストと影のリストから外す
s32 AuxShadow_Remove(AuxShadow* shadow) {
  FUN_0822a4e0(&shadow->sprite);
  if (gAuxShadowManager != NULL) {
    AuxShadowManager_Remove(gAuxShadowManager, shadow);
  }
  return 0;
}

// 影の絵を別の AuxSprite に差し替え、ポーズ番号を設定する
s32 AuxShadow_SetSprite(AuxShadow* shadow, SpriteID32 id, s32 poseIdx) {
  AuxSpriteGfx* gfx = &shadow->gfx;
  AuxSprite* sprite;

  Video_GetAuxSprite(gfx, id);
  sprite = &shadow->sprite;
  FUN_0822a4fc(sprite, gfx);
  sprite->q_metaspriteIdx = poseIdx;
  // 戻り値のある宣言だが return なし
}

s32 AuxShadow_SetAffine(AuxShadow* shadow, u32 enable) {
  if (enable) {
    shadow->sprite.flags |= SPRFLAG_AFFINE;
  } else {
    shadow->sprite.flags &= ~SPRFLAG_AFFINE;
  }
  // 戻り値のある宣言だが return なし
}

// 影の縮小パラメータをまとめて設定する
void AuxShadow_SetScaleParams(AuxShadow* shadow, s32 scale, s32 farScale, s32 baseScale, s32 unk_57, s32 farHeight, s32 nearHeight, s32 farShift, s32 nearShift) {
  shadow->scale = scale;
  shadow->farScale = farScale;
  shadow->baseScale = baseScale;
  shadow->unk_57 = unk_57;
  shadow->farHeight = farHeight;
  shadow->nearHeight = nearHeight;
  shadow->farShift = farShift;
  shadow->nearShift = nearShift;
}
