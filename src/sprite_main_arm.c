#include "camera.h"
#include "global.h"
#include "sprite.h"

// このファイルの関数はすべてARMステートの関数

NAKED unknown* FUN_0822f650(unknown* param_1, unknown* param_2) { INCFUNC("asm/func/FUN_0822f650.inc"); }

// MainSprite の描画関数
NAKED void MainSprite_DrawInternal(MainSprite* p, s32 x, s32 y, s32 z) { INCFUNC("asm/func/MainSprite_DrawInternal.inc"); }

// 描画リストを走査して、点滅で消える回と画面外のものを除いて MainSprite を描く, 多分メインの描画関数
NON_MATCH void MainSprite_DrawListInternal(void) {
#ifdef NONMATCHING_C
  Vec3 screen;
  MainSprite* p;
  SpriteFlags mask;
  SpriteFlags flags;
  s32 x;
  s32 y;
  s32 z;
  s32 a;
  s32 b;

  if (gFrameCounter & 1) {
    mask = SPRFLAG_BLINK_ODD;
  } else {
    mask = SPRFLAG_BLINK_EVEN;
  }
  mask += SPRFLAG_HIDDEN;

  p = gMainSpriteLists[gSpriteListIdx];
  if (p == NULL) {
    return;
  }
  do {
    flags = p->flags;
    if (!(flags & mask)) {
      if (flags & SPRFLAG_SCREEN_COORD) {
        z = p->pos.z;
        x = p->pos.x;
        y = p->pos.y;
      } else {
        screen.x = (((p->pos.x >> 1) - (p->pos.z >> 1)) * 48) / 256;
        a = (((p->pos.x >> 1) + (p->pos.z >> 1)) * 48) / 256;
        b = (p->pos.y * 24) / 256;
        screen.x = screen.x - gCameraVpCoords.x + 120;
        screen.y = (a - b) - gCameraVpCoords.y + 90;
        screen.z = (a + b) - gCameraVpCoords.z;
        z = screen.z;
        x = screen.x;
        y = screen.y;
      }
      x += p->offsetX;
      y += p->offsetY;
      if (!(flags & SPRFLAG_NO_CLIP) || (x + p->boxLeft >= 0 && y + p->boxTop >= 0 && x + p->boxRight <= 240 && y + p->boxBottom <= 180)) {
        MainSprite_DrawInternal(p, x, y, z);
      }
    }
    p = p->next;
  }
#else
  INCFUNC("asm/func/MainSprite_DrawListInternal.inc");
#endif
}

// MainSprite_DrawListInternal と同じくリストを走査して MainSprite を描くが、カメラを見ず pos をそのままスクリーン座標として扱う
// SPRFLAG_SCREEN_COORD も参照しないので、全てのスプライトがスクリーン座標で置かれる。Camera_SetTilemapOffset が script keyword 'v' で本家と排他に差し替える
NON_MATCH void MainSprite_DrawListScreenInternal(void) {
#ifdef NONMATCHING_C
  MainSprite* p;
  SpriteFlags mask;
  SpriteFlags flags;
  s16 x;
  s16 y;
  s16 z;

  mask = SPRFLAG_BLINK_EVEN;
  if (gFrameCounter & 1) {
    mask = SPRFLAG_BLINK_ODD;
  }
  mask += SPRFLAG_HIDDEN;

  p = gMainSpriteLists[gSpriteListIdx];
  while (p != NULL) {
    flags = p->flags;
    if (!(flags & mask)) {
      x = p->pos.x + p->offsetX;
      y = p->pos.y + p->offsetY;
      z = p->pos.z;
      if ((flags & SPRFLAG_NO_CLIP) || (x + p->boxLeft >= 0 && y + p->boxTop >= 0 && x + p->boxRight <= 240 && y + p->boxBottom <= 180)) {
        MainSprite_DrawInternal(p, x, y, z);
      }
    }
    p = p->next;
  }
#else
  INCFUNC("asm/func/MainSprite_DrawListScreenInternal.inc");
#endif
}

NAKED void FUN_082303c8(void) { INCFUNC("asm/func/FUN_082303c8.inc"); }

NAKED void FUN_08230594(void) { INCFUNC("asm/func/FUN_08230594.inc"); }
