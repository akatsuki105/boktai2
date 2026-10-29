#include "entity.h"
#include "global.h"
#include "input.h"
#include "map_inline.h"
#include "mover.h"
#include "player.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

struct Entity7C62;

typedef void(Entity7C62Func)(struct Entity7C62* p);

// プレイヤーが近づくと浮き上がり、A ボタンでその場所へ飛ばす足場 (Mover 付き)
typedef struct Entity7C62 {
  Entity e;                        // 0x000, ENTITY_UNK_9
  u16 id;                          // 0x018, Entity7C62_Init の第2引数, mover の id を兼ねる
  u8 nearState;                    // 0x01A, プレイヤーが近いかを 0/1 で覚え、変わったフレームだけ効果音を鳴らす
  bool8 moverLinked;               // 0x01B, '.h=0', 立っていれば mover を使う
  u8 unk_1c[4];                    // 0x01C, 触られていない
  Mover mover;                     // 0x020
  AuxSprite sprite;                // 0x064, flags に 0x200 が立つ, rise が 0 の間は隠す
  AuxSpriteGfx gfx;                // 0x090, SPRITE_MAGIC_CIRCLE
  Vec3 pos;                        // 0x0AC, '.p', y はタイルの attr から計算し直す, 起動するとプレイヤーをここへ移す
  AuxSprite sprite2;               // 0x0B4, flags に BLINK_EVEN が立つ2枚目
  AuxSpriteGfx gfx2;               // 0x0E0, SPRITE_MAGIC_CIRCLE
  u16 plttID;                      // 0x0FC, 106
  u16 highlight;                   // 0x0FE, 近いと 8 まで増え離れると減る
  u16 rise;                        // 0x100, 近いと 2 ずつ 0x18 まで増え離れると減る, 0 のときは sprite を隠す
  u16 readyTimer;                  // 0x102, 10 を越えていないと A ボタンで起動できない
  u16 scriptArgs[2];               // 0x104, '.A'
  s32 scriptID;                    // 0x108, '.s', 0 なら実行しない
  u16 stateTimer;                  // 0x10C, updateCallback を差し替えるたびに 0 に戻る
  u8 unk_10e[2];                   // 0x10E, 触られていない, padding?
  Entity7C62Func* updateCallback;  // 0x110
} Entity7C62;
static_assert(sizeof(Entity7C62) == 276);

void FUN_080a6e88(bool32 stopSound);
void FUN_0807ba94(Player* p, Vec3* pos, u32 scriptID, DirS32 dir);
void Entity7C62_UpdateActivated(Entity7C62* p);
void Entity7C62_UpdateDone(Entity7C62* p);

// 人型のプレイヤーが pos から 96 以内にいれば TRUE を返す
bool32 Entity7C62_IsPlayerNear(Entity7C62* p) {
  if ((u16)(gStat->playerKind - 2) > 2 && gPlayerPtr[0]->formRequest == 0) {
    s32 dx = gPlayerPtr[0]->mover.pos.x - p->pos.x;
    s32 dz;

    if (dx < 0) {
      dx = -dx;
    }
    dz = gPlayerPtr[0]->mover.pos.z - p->pos.z;
    if (dz < 0) {
      dz = -dz;
    }
    if (dx <= 96 && dz <= 96 && dx * dx + dz * dz <= 96 * 96) {
      return TRUE;
    }
  }
  return FALSE;
}

void Entity7C62_SetUpdateCallback(Entity7C62* p, Entity7C62Func* fn) {
  p->updateCallback = fn;
  p->stateTimer = 0;
}

// プレイヤーが近いと浮き上がって光り, A ボタンでプレイヤーを pos へ飛ばす
void Entity7C62_UpdateIdle(Entity7C62* p) {
  if (!(gGameFlags & FLAG030047A4_UNK_9)) {
    if (p->readyTimer < 10) {
      p->readyTimer++;
    }
  }

  if (Entity7C62_IsPlayerNear(p)) {
    if (p->nearState != 1) {
      PlaySound_082406e0(SONG_408);
      p->nearState = 1;
    }
    if (p->highlight < 8) {
      p->highlight++;
    }
    if (p->rise < 23) {
      p->rise += 2;
    } else {
      p->rise = 24;
    }
    if (TEST_FLAGS(gPlayerStates[0], PMODE_ACTIVE) && (gInput[0].pressed & A_BUTTON) && p->readyTimer > 9) {
      p->highlight = 8;
      FUN_080a6e88(TRUE);
      FUN_0807ba94(gPlayerPtr[0], &p->pos, 0, 4);
      Entity7C62_SetUpdateCallback(p, Entity7C62_UpdateActivated);
    }
  } else {
    if (p->nearState != 0) {
      PlaySound_082406e0(SONG_409);
      p->nearState = 0;
    }
    if (p->highlight != 0) {
      p->highlight--;
    }
    if (p->rise > 2) {
      p->rise -= 2;
    } else {
      p->rise = 0;
    }
  }

  if (p->rise == 0) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->sprite.pos.y = p->pos.y + p->rise;
  }

  if (p->highlight > 7) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 2);
  } else if (p->highlight != 0) {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID + 1);
  } else {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  }
}

// 沈みきってプレイヤーが落ち着いたら '.s' のスクリプトを '.A' の2引数で実行する
void Entity7C62_UpdateActivated(Entity7C62* p) {
  if (p->rise > 1) {
    p->rise -= 2;
  } else {
    p->rise = 0;
  }
  p->sprite.pos.y = p->pos.y + p->rise;
  if (p->rise == 0 && gPlayerPtr[0]->action == 0) {
    p->sprite.flags &= ~SPRFLAG_BLINK_ODD;
    p->sprite.priority = 3;
    p->sprite2.flags |= SPRFLAG_HIDDEN;
    Entity7C62_SetUpdateCallback(p, Entity7C62_UpdateDone);
    if (p->scriptID != 0) {
      u32 argv[2];
      ScriptArgs args;

      args.argc = 2;
      args.argv = argv;
      argv[0] = p->scriptArgs[0];
      argv[1] = p->scriptArgs[1];
      VM_ExecByID(p->scriptID, &args);
    }
  }
}

void Entity7C62_UpdateDone(Entity7C62* p) {}

s32 Entity7C62_Update(Entity7C62* p) {
  p->updateCallback(p);
  return 0;
}

s32 Entity7C62_Destroy(Entity7C62* p) {
  AuxSprite_Remove(&p->sprite);
  AuxSprite_Remove(&p->sprite2);
  if (p->moverLinked) {
    Mover_Unlink(&p->mover);
  }
  return 0;
}

s32 Entity7C62_Init(Entity7C62* p, u32 id, u32 param_3) {
  s32 i;

  p->id = id;
  if (VM_SeekToNamedArg('p')) {
    p->pos.x = VM_GetValue();
    p->pos.y = VM_GetValue();
    p->pos.z = VM_GetValue();
    p->pos.y = TileHeightAt(&p->pos);
  } else {
    p->pos.x = 0;
    p->pos.y = 0;
    p->pos.z = 0;
  }

  if (VM_SeekToNamedArg('s')) {
    p->scriptID = VM_GetValue();
  } else {
    p->scriptID = 0;
  }

  if (VM_SeekToNamedArg('A')) {
    for (i = 0; i < 2; i++) {
      p->scriptArgs[i] = VM_GetValue();
    }
  } else {
    for (i = 0; i < 2; i++) {
      p->scriptArgs[i] = 0;
    }
  }

  if (VM_SeekToNamedArg('h')) {
    p->moverLinked = VM_GetValue();
  } else {
    p->moverLinked = 0;
  }
  if (p->moverLinked) {
    Mover_Init(&p->mover, p->id, &p->pos, 0, 7, p);
    FUN_08002a48(&p->mover);
  }

  p->plttID = 106;
  Video_GetAuxSprite(&p->gfx, SPRITE_MAGIC_CIRCLE);
  AuxSprite_Add(&p->sprite, &p->gfx, 0);
  AuxSprite_SetPoseIdx(&p->sprite, 7);
  Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  p->sprite.flags |= SPRFLAG_BLINK_ODD;
  p->sprite.priority = 3;
  p->sprite.pos = p->pos;

  Video_GetAuxSprite(&p->gfx2, SPRITE_MAGIC_CIRCLE);
  AuxSprite_Add(&p->sprite2, &p->gfx2, 0);
  AuxSprite_SetPoseIdx(&p->sprite2, 7);
  Video_SetAuxSpritePltt(&p->gfx2, p->plttID);
  p->sprite2.flags |= SPRFLAG_BLINK_EVEN;
  p->sprite2.priority = 3;
  p->sprite2.pos = p->pos;

  Entity7C62_SetUpdateCallback(p, Entity7C62_UpdateIdle);
  return 0;
}

Entity7C62* Entity7C62_Create(u32 id, u32 param_2) {
  Entity7C62* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity7C62));

  if (p != NULL) {
    SetEntityRoutine(p, Entity7C62_Update, Entity7C62_Destroy);
    if (Entity7C62_Init(p, id, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
