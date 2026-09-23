#include "constants/sprite.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "msgbus.h"
#include "sprite_main.h"

// デモのメッセージ cmd 7 で呼び出され、リンゴを 6 段のアニメーションで見せてからデモの待ちを解く
typedef struct {
  Entity e;              // 0x000, ENTITY_UNK_8
  u32 state;             // 0x018, 0..5 の switch。5 フレームごとに次へ進む
  u32 timer;             // 0x01C, Update の先頭と末尾で +1 されるので毎フレーム +2。4 を超えると state を進めて 0 に戻す
  Vec3 pos;              // 0x020, Init の第2引数。両方の MainSprite が指す
  MainSpriteGfx gfx;     // 0x028, SPRITE_RINGO
  MainSprite sprite;     // 0x048, prio 2。state 5 で animEvents の bit1 を見て終了を待つ
  MainSprite sprite2;    // 0x0A8, prio 3。state 3 で SPRFLAG_HIDDEN を立てて消す
  EntityMsgBox* msgBox;  // 0x108, Init の第3引数。終わったら EntityMsgBox_EndWait(msgBox, 1)
} RingoDemoAnim;
static_assert(sizeof(RingoDemoAnim) == 268);

// 5 フレームおきに次のポーズ対を当てていき、最後のアニメーションが終わったらデモの待ちを解いて消える
s32 RingoDemoAnim_Update(RingoDemoAnim* p) {
  switch (p->state) {
    case 0: {
      p->timer++;
      if (p->timer > 4) {
        MainSprite_SetAnim(&p->sprite, &p->gfx, 0x31, 2, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnim(&p->sprite2, &p->gfx, 0x32, 2, MAIN_ANIM_FORCE_POSE);
        p->state++;
        p->timer = 0;
      }
      break;
    }
    case 1: {
      p->timer++;
      if (p->timer > 4) {
        MainSprite_SetAnim(&p->sprite, &p->gfx, 0x33, 2, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnim(&p->sprite2, &p->gfx, 0x34, 2, MAIN_ANIM_FORCE_POSE);
        p->state++;
        p->timer = 0;
      }
      break;
    }
    case 2: {
      p->timer++;
      if (p->timer > 4) {
        MainSprite_SetAnim(&p->sprite, &p->gfx, 0x35, 2, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnim(&p->sprite2, &p->gfx, 0x36, 2, MAIN_ANIM_FORCE_POSE);
        p->state++;
        p->timer = 0;
      }
      break;
    }
    case 3: {
      MainSprite* sprite2;

      p->timer++;
      if (p->timer > 4) {
        MainSprite_SetAnim(&p->sprite, &p->gfx, 0x37, 2, MAIN_ANIM_FORCE_POSE);
        sprite2 = &p->sprite2;
        sprite2->flags |= SPRFLAG_HIDDEN;
        p->state++;
        p->timer = 0;
      }
      break;
    }
    case 4: {
      p->timer++;
      if (p->timer > 4) {
        MainSprite_SetAnim(&p->sprite, &p->gfx, 0x38, 2, MAIN_ANIM_FORCE_POSE);
        p->state++;
        p->timer = 0;
      }
      break;
    }
    case 5: {
      if (p->sprite.animEvents & MAIN_ANIM_EVENT_ENDED) {
        EntityMsgBox_EndWait(p->msgBox, 1);
        KillEntity((Entity*)p);
      }
      break;
    }
  }
  MainSprite_AdvanceAnim(&p->sprite, &p->gfx);
  MainSprite_AdvanceAnim(&p->sprite2, &p->gfx);
  p->sprite2.pos = p->sprite.pos;
  p->timer++;
  return 0;
}

s32 RingoDemoAnim_Destroy(RingoDemoAnim* p) {
  MainSprite_Remove(&p->sprite);
  MainSprite_Remove(&p->sprite2);
  return 0;
}

// リンゴの絵を読んで 2 枚のスプライトを同じ座標に重ね、1 段目のアニメーションを当てる
s32 RingoDemoAnim_Init(RingoDemoAnim* p, Vec3* pos, EntityMsgBox* msgBox) {
  Vec3* q;
  MainSpriteFile* f;

  p->msgBox = msgBox;
  q = &p->pos;
  *q = *pos;
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_RINGO);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx, f);
  MainSprite_Add(&p->sprite, &p->gfx, 0, 0, 2, 0, 60, q);
  MainSprite_Add(&p->sprite2, &p->gfx, 0, 0, 3, 0, 60, q);
  p->state = 0;
  p->timer = 0;
  MainSprite_SetAnim(&p->sprite, &p->gfx, 47, 2, MAIN_ANIM_FORCE_POSE);
  MainSprite_SetAnim(&p->sprite2, &p->gfx, 48, 2, MAIN_ANIM_FORCE_POSE);
  return 0;
}

RingoDemoAnim* RingoDemoAnim_Create(Vec3* pos, EntityMsgBox* msgBox) {
  RingoDemoAnim* p = CreateEntity(ENTITY_UNK_8, sizeof(RingoDemoAnim));

  if (p != NULL) {
    SetEntityRoutine(p, RingoDemoAnim_Update, RingoDemoAnim_Destroy);
    if (RingoDemoAnim_Init(p, pos, msgBox) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
