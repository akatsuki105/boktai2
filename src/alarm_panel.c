#include "entity.h"
#include "game.h"
#include "global.h"
#include "mover.h"
#include "player.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

// 太陽警報機(太陽ゲージが1以上のときに踏むと警報を出して敵にバレる)
typedef struct {
  Entity e;            // 0x00, ENTITY_UNK_8
  u16 id;              // 0x18
  u16 animTimer;       // 0x1A, 警報中だけ毎フレーム +1, bit1 で sprite2 を反転し 32 フレームごとにエフェクトを出す
  bool16 moverLinked;  // 0x1C, '.h=0', 立っていれば mover を使う
  u16 stateTimer;      // 0x1E, Init が 0 を書く
  Mover mover;         // 0x20, '.p' は mover.pos に直接入る
  AuxSprite sprite;    // 0x64, '.r' があれば flags に SPRFLAG_XFLIP を立てる
  AuxSpriteGfx gfx;    // 0x90, SPRITE_TRAP_FLOOR, パレット 70
  AuxSprite sprite2;   // 0xAC, flags に SPRFLAG_BLINK_ODD|SPRFLAG_HIDDEN が立つ, 位置は x と z が 0x80 手前
  AuxSpriteGfx gfx2;   // 0xD8, SPRITE_TRAP_FLOOR, パレット 69
  u32 scriptID;        // 0xF4, '.R=0'
} AlarmPanel;
static_assert(sizeof(AlarmPanel) == 248);

void FUN_08240cf0(s32 x, s32 z, s16 param_3, s32 param_4, u8 param_5, u16 param_6);

// 太陽ゲージが残っていて、プレイヤーが1タイル以内にいるか
s32 AlarmPanel_IsTriggered(AlarmPanel* p) {
  if (gStat->sunGauge != 0) {
    s32 dx = gPlayerPtr[0]->mover.pos.x - p->mover.pos.x;
    s32 dz = gPlayerPtr[0]->mover.pos.z - p->mover.pos.z;
    if (dx <= 0x7F && dz <= 0x7F && dx * dx + dz * dz <= 0x3FFF) {
      return 1;
    }
  }
  return 0;
}

s32 AlarmPanel_Update(AlarmPanel* p) {
  if (gStat->sunGauge == 0) {
    if (p->stateTimer == 1) {
      sound_08240740(0x237);
      p->stateTimer = 0;
    }
    Video_SetAuxSpritePltt(&p->gfx, 70);
    p->sprite2.flags |= SPRFLAG_HIDDEN;
    p->animTimer = 0;
  } else if (AlarmPanel_IsTriggered(p)) {
    if (p->stateTimer == 0) {
      PlaySound_082406e0(0x237);
      p->stateTimer = 1;
      if (p->scriptID != 0) {
        VM_ExecByID(p->scriptID, NULL);
      }
    }
    Video_SetAuxSpritePltt(&p->gfx, 69);
    p->sprite2.flags &= ~SPRFLAG_HIDDEN;
    if ((p->animTimer >> 1) & 1) {
      p->sprite2.flags |= SPRFLAG_XFLIP;
    } else {
      p->sprite2.flags &= ~SPRFLAG_XFLIP;
    }
    if ((p->animTimer & 0x1F) == 0) {
      FUN_08240cf0(p->sprite.pos.x, p->sprite.pos.z, 0x400, 0, 0x80, 0xB546);
    }
    p->animTimer++;
  } else {
    if (p->stateTimer == 1) {
      sound_08240740(0x237);
      p->stateTimer = 0;
    }
    Video_SetAuxSpritePltt(&p->gfx, 68);
    p->sprite2.flags |= SPRFLAG_HIDDEN;
    p->animTimer = 0;
  }
  return 0;
}

s32 AlarmPanel_Destroy(AlarmPanel* p) {
  if (p->moverLinked) {
    Mover_Unlink(&p->mover);
  }
  AuxSprite_Remove(&p->sprite);
  AuxSprite_Remove(&p->sprite2);
  sound_08240740(0x237);
  return 0;
}

// 残差は末尾1命令のレジスタ割当(値がr1/r2のどちらに乗るか)のみ, Tier A-C は試済
NON_MATCH s32 AlarmPanel_Init(AlarmPanel* p, u32 id) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;
  AuxSpriteGfx* gfx;
  s32 scriptID;
  p->id = id;
  if (VM_SeekToNamedArg('p')) {
    p->mover.pos.x = VM_GetValue();
    p->mover.pos.y = VM_GetValue();
    p->mover.pos.z = VM_GetValue();
  } else {
    p->mover.pos.x = 0;
    p->mover.pos.y = 0;
    p->mover.pos.z = 0;
  }
  sprite = &p->sprite;
  gfx = &p->gfx;
  Video_GetAuxSprite(gfx, SPRITE_TRAP_FLOOR);
  AuxSprite_Add(sprite, gfx, 0);
  sprite->poseIdx = 10;
  sprite->priority = 3;
  Video_SetAuxSpritePltt(gfx, 70);
  if (VM_SeekToNamedArg('r') && VM_GetValue() != 0) {
    sprite->flags |= SPRFLAG_XFLIP;
  }
  p->stateTimer = 0;
  sprite->pos = p->mover.pos;
  if (VM_SeekToNamedArg('h')) {
    p->moverLinked = VM_GetValue();
    if (p->moverLinked) {
      Mover_Init(&p->mover, p->id, &sprite->pos, 0, 7, p);
      FUN_08002a48(&p->mover);
    }
  } else {
    p->moverLinked = 0;
  }
  sprite = &p->sprite2;
  gfx = &p->gfx2;
  Video_GetAuxSprite(gfx, SPRITE_TRAP_FLOOR);
  AuxSprite_Add(sprite, gfx, 0);
  sprite->poseIdx = 11;
  sprite->priority = 1;
  Video_SetAuxSpritePltt(gfx, 69);
  sprite->flags |= SPRFLAG_BLINK_ODD | SPRFLAG_HIDDEN;
  sprite->pos = p->mover.pos;
  sprite->pos.x -= 0x80;
  sprite->pos.z -= 0x80;
  scriptID = VM_SeekToNamedArg('R');
  if (scriptID != 0) {
    scriptID = VM_GetValue();
  }
  p->scriptID = scriptID;
  return scriptID;
#else
  INCFUNC("asm/func/AlarmPanel_Init.inc");
#endif
}

// 0x25F3, HashName("太陽警報機")
AlarmPanel* AlarmPanel_Create(u32 id) {
  AlarmPanel* p = CreateEntity(ENTITY_UNK_8, sizeof(AlarmPanel));
  if (p != NULL) {
    SetEntityRoutine(p, AlarmPanel_Update, AlarmPanel_Destroy);
    if (AlarmPanel_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
