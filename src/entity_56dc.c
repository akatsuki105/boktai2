#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "sprite.h"

// デバッグ用で未使用っぽい, L/R でスプライトの拡大率を、十字キーで unk_24 / unk_28 を動かすだけの動作確認用に見える
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  u32 frameCounter;   // 0x18, _Update が毎フレーム +1, 下位バイトが 0x81 以上の間だけ sprite に XFLIP を立てる
  s32 scaleX;         // 0x1C, L で -1、R で +1, 0x10..0x7F に丸めて sprite.scaleX に入れる
  s32 scaleY;         // 0x20, 同上で sprite.scaleY へ
  s32 unk_24;         // 0x24, 十字キー左右で ±1、±0x100 に丸める, 読み手が見つかっていない
  s32 unk_28;         // 0x28, 十字キー上下で ±1、±0x100 に丸める, 読み手が見つかっていない
  s32 unk_2c;         // 0x2C, _Init が 0 を書くだけ
  s32 unk_30;         // 0x30, _Init が 0 を書くだけ
  MainSpriteGfx gfx;  // 0x34, SPRITE_2117
  MainSprite sprite;  // 0x54, _Init が (120, 80) にポーズ1で登録する
} Entity56DC;
static_assert(sizeof(Entity56DC) == 180);

s32 Entity56DC_Update(Entity56DC* p) {
  if (gInput[0].down & L_BUTTON) {
    p->scaleX--;
    p->scaleY--;
  }
  if (gInput[0].down & R_BUTTON) {
    p->scaleX++;
    p->scaleY++;
  }
  if (p->scaleX <= 16) {
    p->scaleX = 16;
  }
  if (p->scaleX >= 127) {
    p->scaleX = 127;
  }
  if (p->scaleY <= 16) {
    p->scaleY = 16;
  }
  if (p->scaleY >= 127) {
    p->scaleY = 127;
  }
  if (gInput[0].down & DPAD_UP) {
    p->unk_28--;
  } else if (gInput[0].down & DPAD_DOWN) {
    p->unk_28++;
  }
  if (gInput[0].down & DPAD_LEFT) {
    p->unk_24--;
  } else if (gInput[0].down & DPAD_RIGHT) {
    p->unk_24++;
  }
  if (p->unk_24 < -256) {
    p->unk_24 = -256;
  } else if (p->unk_24 > 256) {
    p->unk_24 = 256;
  }
  if (p->unk_28 < -256) {
    p->unk_28 = -256;
  } else if (p->unk_28 > 256) {
    p->unk_28 = 256;
  }
  p->sprite.scaleX = p->scaleX;
  p->sprite.scaleY = p->scaleY;
  if ((u8)p->frameCounter > 128) {
    p->sprite.flags |= SPRFLAG_XFLIP;
  } else {
    p->sprite.flags &= ~SPRFLAG_XFLIP;
  }
  p->frameCounter++;
  return 0;
}

s32 Entity56DC_Destroy(Entity56DC* p) { return 0; }

s32 Entity56DC_Init(Entity56DC* p, unknown* param_2, unknown* param_3) {
  Vec3 pos;
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_2117);

  if (f == NULL) {
    return -1;
  }
  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  p->frameCounter = 0;
  p->unk_24 = 0;
  p->unk_28 = 0;
  p->scaleX = 64;
  p->scaleY = 64;
  p->unk_2c = 0;
  p->unk_30 = 0;
  pos.x = 120, pos.y = 80, pos.z = 0;
  MainSprite_Add(&p->sprite, &p->gfx, 1, SPRFLAG_AFFINE | SPRFLAG_SCREEN_COORD, 2, 0, 60, &pos);
  p->sprite.scaleX = p->scaleX;
  p->sprite.scaleY = p->scaleY;
  return 0;
}

Entity56DC* Entity56DC_Create(unknown* param_1, unknown* param_2) {
  Entity56DC* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity56DC));
  if (p != NULL) {
    SetEntityRoutine(p, Entity56DC_Update, Entity56DC_Destroy);
    if (Entity56DC_Init(p, param_1, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
