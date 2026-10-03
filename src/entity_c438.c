#include "entity.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "sprite.h"
#include "vm.h"

typedef struct {
  Entity e;           // 0x0, ENTITY_UNK_9
  u16 kind;           // 0x18, '.t', ポーズ番号の組を選ぶ, 0 なら +0、1 なら +4
  u16 radius;         // 0x1A, '.I=384', この距離までプレイヤーが近づくと表示する
  MainSprite sprite;  // 0x1C, SPRITE_MARKERS
  Vec3 pos;           // 0x7C
} EntityC438;
static_assert(sizeof(EntityC438) == 132);

// プレイヤーが radius の範囲内にいるか, X と Z を別々に見る
bool32 EntityC438_IsPlayerNear(EntityC438* p) {
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
s32 EntityC438_Update(EntityC438* p) {
  if (!(gFlag030047a4 & FLAG030047A4_UNK_9) && EntityC438_IsPlayerNear(p)) {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
  return 0;
}

s32 EntityC438_Destroy(EntityC438* p) {
  MainSprite_Remove(&p->sprite);
  return 0;
}

// マーカーのスプライトを読み込み、スクリプトの指定した位置とポーズで置く
s32 EntityC438_Init(EntityC438* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_MARKERS);
  MainSpriteGfx gfx;
  Vec3 offset;
  Vec3 pos;
  s32 poseIdx;
  s32 prio;

  gfx = *f;
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
  } else if (EntityC438_IsPlayerNear(p)) {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
  return 0;
}

EntityC438* EntityC438_Create(void) {
  EntityC438* p = CreateEntity(ENTITY_UNK_9, sizeof(EntityC438));
  if (p != NULL) {
    SetEntityRoutine(p, EntityC438_Update, EntityC438_Destroy);
    if (EntityC438_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
