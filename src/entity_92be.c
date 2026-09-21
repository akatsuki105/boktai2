#include "constants/sprite.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "random.h"
#include "sprite_main.h"
#include "vm.h"

// スクリプトが出すマーカーのスプライト。寿命が尽きるとスクリプトを起動して自分を消す
typedef struct Entity92BE {
  Entity e;                                    // 0x00, ENTITY_UNK_9
  MainSpriteGfx gfx;                           // 0x18, SPRITE_SETS の MARKERS を読み込む
  MainSprite sprite;                           // 0x38
  u8 unk_98[0x9A - 0x98];                      // 0x98
  u16 timer;                                   // 0x9A, Entity92BE_Update が毎フレーム +1 して lifetime と比べる
  u16 lifetime;                                // 0x9C, VM キーワード 'I' の値。既定は 60
  u8 unk_9e[0xA0 - 0x9E];                      // 0x9E
  Vec3 pos;                                    // 0xA0, MainSprite_Add に渡す位置。Init が x/y/z を 0 で埋める
  u32 scriptID;                                // 0xA8, VM キーワード 'p' の値。寿命が尽きたときに起動する
  void (*updateCallback)(struct Entity92BE*);  // 0xAC, Entity92BE_Update が毎フレーム呼ぶ。Init は Entity92BE_Shake を入れる
} Entity92BE;
static_assert(sizeof(Entity92BE) == 176);

// 出現から6フレームだけ左右に揺らす
void Entity92BE_Shake(Entity92BE* p) {
  s32 r;

  if (p->timer <= 5) {
    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    r = *(gRandomTable + gRandTableIdx);
    p->sprite.pos.x = ((r >> 4) & 0xF) - 7;
  } else {
    p->sprite.pos.x = 0;
    p->sprite.pos.y = 0;
  }
}

s32 Entity92BE_Update(Entity92BE* p) {
  p->updateCallback(p);
  p->timer++;
  if (p->timer >= p->lifetime) {
    if (p->scriptID != 0) {
      Script_ExecById(p->scriptID, NULL);
    }
    KillEntity(&p->e);
  }
}

s32 Entity92BE_Destroy(Entity92BE* p) {
  MainSprite_Remove(&p->sprite);
  return 0;
}

// マーカーのスプライトを読み込み、スクリプトの指定に従って表示する
s32 Entity92BE_Init(Entity92BE* p) {
  MainSpriteFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_MARKERS);
  s32 idx;

  if (f == NULL) {
    return -1;
  }
  p->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx, f);
  if (VM_SeekToKeyword('t')) {
    idx = Script_GetValue();
  } else {
    idx = 0;
  }
  if (VM_SeekToKeyword('I')) {
    p->lifetime = Script_GetValue();
  } else {
    p->lifetime = 60;
  }
  p->updateCallback = Entity92BE_Shake;
  p->pos.x = 0, p->pos.y = 0, p->pos.z = 0;
  MainSprite_Add(&p->sprite, &p->gfx, idx + 11, SPRFLAG_SCREEN_COORD, 1, 0, 60, &p->pos);
  if (VM_SeekToKeyword('p')) {
    p->scriptID = Script_GetValue();
  } else {
    p->scriptID = 0;
  }
  return 0;
}

Entity92BE* Entity92BE_Create(void) {
  Entity92BE* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity92BE));

  if (p != NULL) {
    SetEntityRoutine(p, Entity92BE_Update, Entity92BE_Destroy);
    if (Entity92BE_Init(p) != 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
