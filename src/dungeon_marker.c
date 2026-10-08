#include "entity.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "sprite.h"
#include "vm.h"

// ダンジョン入り口に出る "Undead" と "Immortal" (矢印などのマーカーは別)
typedef struct {
  Entity e;           // 0x0, ENTITY_UNK_9
  u16 kind;           // 0x18, '.t', "Undead" と "Immortal" のどっちを表示するか
  u16 radius;         // 0x1A, '.I=384', この距離までプレイヤーが近づくと表示する
  MainSprite sprite;  // 0x1C, SPRITE_MARKERS
  Vec3 pos;           // 0x7C
} DungeonMarker;
static_assert(sizeof(DungeonMarker) == 132);

// プレイヤーが radius の範囲内にいるか, X と Z を別々に見る
static bool32 DungeonMarker_IsPlayerNear(DungeonMarker* p) {
  Player* player = gPlayerPtr[0];
  s32 dx, dz;

  if (player == NULL) {
    return FALSE;
  }

  dx = abs(player->mover.pos.x - p->pos.x);
  dz = abs(player->mover.pos.z - p->pos.z);
  if (dx > p->radius || dz > p->radius) {
    return FALSE;
  }
  return TRUE;
}

// 会話中とマップ切り替え中は隠す
s32 DungeonMarker_Update(DungeonMarker* p) {
  if (!(gFlag030047a4 & FLAG030047A4_UNK_9) && DungeonMarker_IsPlayerNear(p)) {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
  return 0;
}

s32 DungeonMarker_Destroy(DungeonMarker* p) {
  MainSprite_Remove(&p->sprite);
  return 0;
}

// マーカーのスプライトを読み込み、スクリプトの指定した位置とポーズで置く
s32 DungeonMarker_Init(DungeonMarker* p) {
  Vec3 offset, pos;
  s32 poseIdx;
  s32 prio;

  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_MARKERS);
  MainSpriteGfx gfx = *f;
  OpenMainSpriteFile(&gfx, f);

  if (VM_SeekToNamedArg('p')) {
    p->pos.x = VM_GetValue();
    p->pos.y = VM_GetValue();
    p->pos.z = VM_GetValue();
  } else {
    p->pos.x = 0, p->pos.y = 0, p->pos.z = 0;
  }

  if (VM_SeekToNamedArg('o')) {
    offset.x = VM_GetValue();
    offset.y = VM_GetValue();
    offset.z = VM_GetValue();
  } else {
    offset.x = 0, offset.y = 0, offset.z = 0;
  }

  if (VM_SeekToNamedArg('I')) {
    p->radius = VM_GetValue();
  } else {
    p->radius = 384;
  }

  if (VM_SeekToNamedArg('t')) {
    p->kind = VM_GetValue();
  } else {
    p->kind = 0;
  }

  prio = VM_SeekToNamedArg('R') ? VM_GetValue() : 1;

  switch (p->kind) {
    s32 d;
    case 0: {
      d = VM_SeekToNamedArg('d') ? VM_GetValue() : 0;
      poseIdx = d;
      break;
    }
    case 1: {
      d = VM_SeekToNamedArg('d') ? VM_GetValue() : 0;
      poseIdx = d + 4;
      break;
    }
    default: {
      poseIdx = 0;
      break;
    }
  }

  pos.x = offset.x + p->pos.x;
  pos.y = offset.y + p->pos.y;
  pos.z = offset.z + p->pos.z;
  MainSprite_Add(&p->sprite, &gfx, poseIdx, 0, prio, 0, 60, &pos);

  if (gFlag030047a4 & FLAG030047A4_UNK_9) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  } else if (DungeonMarker_IsPlayerNear(p)) {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
  return 0;
}

DungeonMarker* DungeonMarker_Create(u32 _) {
  DungeonMarker* p = CreateEntity(ENTITY_UNK_9, sizeof(DungeonMarker));
  if (p != NULL) {
    SetEntityRoutine(p, DungeonMarker_Update, DungeonMarker_Destroy);
    if (DungeonMarker_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
