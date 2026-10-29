#include "entity.h"
#include "file.h"
#include "global.h"
#include "random.h"
#include "sprite.h"
#include "vm.h"

// スクリプトが出すマーカーのスプライト, 寿命が尽きるとスクリプトを起動して自分を消す
// スクリプトが出す "TRAP", "MISSION COMPLETED", "PURIFICATION COMPLETED" "MISSION FAILED" のどれか
typedef struct MissionMarker {
  Entity e;                                       // 0x00, ENTITY_UNK_9
  MainSpriteGfx gfx;                              // 0x18, SPRITE_MARKERS
  MainSprite sprite;                              // 0x38
  u8 unk_98[0x9A - 0x98];                         // 0x98, padding?
  u16 timer;                                      // 0x9A, MissionMarker_Update が毎フレーム +1 して lifetime と比べる
  u16 lifetime;                                   // 0x9C, '.I=60'
  u8 unk_9e[0xA0 - 0x9E];                         // 0x9E, padding?
  Vec3 pos;                                       // 0xA0, MainSprite_Add に渡す位置, Init が x/y/z を 0 で埋める
  u32 scriptID;                                   // 0xA8, '.p'
  void (*updateCallback)(struct MissionMarker*);  // 0xAC, Init は MissionMarker_Shake を入れる
} MissionMarker;
static_assert(sizeof(MissionMarker) == 176);

// 出現から6フレームだけ左右に揺らす
void MissionMarker_Shake(MissionMarker* p) {
  if (p->timer <= 5) {
    p->sprite.pos.x = ((Random() >> 4) & 0xF) - 7;
  } else {
    p->sprite.pos.x = 0;
    p->sprite.pos.y = 0;
  }
}

s32 MissionMarker_Update(MissionMarker* p) {
  p->updateCallback(p);
  p->timer++;
  if (p->timer >= p->lifetime) {
    if (p->scriptID != 0) {
      VM_ExecByID(p->scriptID, NULL);
    }
    KillEntity(&p->e);
  }
}

s32 MissionMarker_Destroy(MissionMarker* p) {
  MainSprite_Remove(&p->sprite);
  return 0;
}

// マーカーのスプライトを読み込み、スクリプトの指定に従って表示する
s32 MissionMarker_Init(MissionMarker* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_MARKERS);
  s32 idx;

  if (f == NULL) {
    return -1;
  }
  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  idx = VM_SeekToNamedArg('t') ? VM_GetValue() : 0;  // 0: "TRAP", 1: "MISSION COMPLETED", 2: "PURIFICATION COMPLETED", 3: "MISSION FAILED"
  if (VM_SeekToNamedArg('I')) {
    p->lifetime = VM_GetValue();
  } else {
    p->lifetime = 60;
  }
  p->updateCallback = MissionMarker_Shake;
  VEC3_SET(p->pos, 0, 0, 0);
  MainSprite_Add(&p->sprite, &p->gfx, idx + 11, SPRFLAG_SCREEN_COORD, 1, PLAYMODE_PAUSE, 60, &p->pos);
  if (VM_SeekToNamedArg('p')) {
    p->scriptID = VM_GetValue();
  } else {
    p->scriptID = 0;
  }
  return 0;
}

MissionMarker* MissionMarker_Create(void) {
  MissionMarker* p = CreateEntity(ENTITY_UNK_9, sizeof(MissionMarker));

  if (p != NULL) {
    SetEntityRoutine(p, MissionMarker_Update, MissionMarker_Destroy);
    if (MissionMarker_Init(p) != 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
