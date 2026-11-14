#include "puff.h"

#include "entity.h"
#include "file.h"
#include "global.h"
#include "random.h"
#include "sprite.h"
#include "vm.h"

// 水しぶき・煙・土煙など, パレット違いで使い回す玉状のパーティクル (SPRITE_PUFF_4384, 地下水路の滝の根元などで確認)

// パーティクル1個分, Puff_Spawn で発生させる
typedef struct {
  bool8 active;       // 0x00, 0 でなければ Update/Destroy が処理する, アニメが終わると 0
  u8 kind;            // 0x01, 5/6/7 は別スプライト (SPRITE_DUNEYRR_AUX) と animFiles[1], それ以外はパレット kind + 0x7D
  u16 timer;          // 0x02, 発生からのフレーム数
  s16 speedY;         // 0x04, decayStartY に達したら *= decayY / 256
  s16 speedXZ;        // 0x06, decayStartXZ に達したら *= decayXZ / 256
  u16 decayStartY;    // 0x08
  u16 decayY;         // 0x0A, 8.8 固定小数の倍率, どこでも書き込まれないので常に 0 (decayStartY で止まる)
  u16 decayStartXZ;   // 0x0C
  u16 decayXZ;        // 0x0E, 同上
  Vec3 dir;           // 0x10, 4.12 固定小数の向き, x = COS(angleXZ), y = SIN(angleY), z = SIN(angleXZ)
  Vec3 vel;           // 0x18, dir * speed >> 12, 毎フレーム sprite.pos に加算, SCREEN_COORD なら z は足さない
  AuxSpriteGfx gfx;   // 0x20, SPRITE_PUFF_4384
  AuxSprite sprite;   // 0x3C, ->gfx
  AuxAnimState anim;  // 0x68
} Puff;
static_assert(sizeof(Puff) == 120);

typedef struct {
  Entity e;                   // 0x00, ENTITY_UNK_9
  AuxAnimFile* animFiles[2];  // 0x18, id: sPuffAnimFileIDs[i]
  u32 frameCounter;           // 0x20
  Puff elems[32];             // 0x24
} PuffManager;
static_assert(sizeof(PuffManager) == 3876);

static PuffManager* sPuffManager;  // 0x03000060

void PuffManager_ClearGlobal(void) { sPuffManager = NULL; }

// 使用中の粒子を減速させながら動かし, アニメが一巡したら外す
// 258/254 命令, 原典は elem と sprite の2本だけを歩かせ anim は elem から求めるが, こちらは anim 側もループ外で歩くポインタになる
NON_MATCH s32 PuffManager_Update(PuffManager* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 32; i++) {
    Puff* elem = &p->elems[i];

    if (elem->active) {
      AuxSprite* sprite = &elem->sprite;

      if (elem->timer >= elem->decayStartXZ) {
        elem->speedXZ = FixToInt(8, elem->speedXZ * elem->decayXZ);
        elem->vel.x = FixToInt(12, elem->dir.x * elem->speedXZ);
        elem->vel.z = FixToInt(12, elem->dir.z * elem->speedXZ);
      }
      if (elem->timer >= elem->decayStartY) {
        elem->speedY = FixToInt(8, elem->speedY * elem->decayY);
        elem->vel.y = FixToInt(12, elem->dir.y * elem->speedY);
      }

      sprite->pos.x += elem->vel.x;
      sprite->pos.y += elem->vel.y;
      if (!(sprite->flags & SPRFLAG_SCREEN_COORD)) {
        sprite->pos.z += elem->vel.z;
      }

      if (AuxSprite_AdvanceAnim(sprite, &elem->anim)) {
        elem->active = FALSE;
        AuxSprite_Remove(sprite);
      }
      elem->timer++;
    }
  }

  p->frameCounter++;
  return 0;
#else
  INCFUNC("asm/func/PuffManager_Update.inc");
#endif
}

s32 PuffManager_Destroy(PuffManager* p) {
  s32 i;

  for (i = 0; i < 32; i++) {
    if (p->elems[i].active) {
      AuxSprite_Remove(&p->elems[i].sprite);
    }
  }

  sPuffManager = NULL;
  return 0;
}

s32 PuffManager_Init(PuffManager* p, u32 _) {
  static const FileID sPuffAnimFileIDs[2] = {
      ANIM_F62B,
      ANIM_31F4,
  };  // 0x085AA914

  Vec3 pos;
  s32 i;

  sPuffManager = p;

  for (i = 0; i < 2; i++) {
    p->animFiles[i] = GetFile(DIR_ANIMATION, sPuffAnimFileIDs[i]);
  }

  VEC3_SET(pos, 0, 0, 0);

  for (i = 0; i < 32; i++) {
    Puff* elem = &p->elems[i];

    elem->active = FALSE;
    elem->speedY = 0;
    elem->dir.x = 0, elem->dir.y = 0, elem->dir.z = 0;
    if (!Video_GetAuxSprite(&elem->gfx, SPRITE_PUFF_4384)) {
      return -1;
    }
    AuxSprite_Setup(&elem->sprite, &elem->gfx, 0);
    AuxAnim_SetAnim(&elem->anim, p->animFiles[0], 0, 0, 0);
    elem->sprite.priority = 2;
    elem->sprite.pos = pos;
  }

  p->frameCounter = 0;
  return 0;
}

PuffManager* PuffManager_Create(u32 val, u32 _) {
  PuffManager* p = CreateEntity(ENTITY_UNK_9, sizeof(PuffManager));
  if (p != NULL) {
    SetEntityRoutine(p, PuffManager_Update, PuffManager_Destroy);
    if (PuffManager_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// flags の bit12-15 (1〜4) を描画優先度 0〜3 にする, 範囲外は 2
// 13/13 命令, 原典は & 0xF000 の結果を flags 側の r0 に書くが, こちらはマスク側の r1 に書くので直後の asrs / subs のレジスタがずれる
NON_MATCH u32 Puff_GetPriority(s32 flags) {
#ifdef NONMATCHING_C
  u32 n = ((flags & 0xF000) >> 12) - 1;

  n = (n < 4) ? n : 2;
  return n;
#else
  INCFUNC("asm/func/Puff_GetPriority.inc");
#endif
}

// params に従って count 個の粒子を空き枠へ仕込む, 枠が足りなければ -1
// 513/520 命令, 原典は sPuffManager の番地をレジスタに巻き上げるが, agbcc は参照のたびにプールから読み直す. PuffParam の decayY / decayXZ はここでも読まれない
NON_MATCH s32 Puff_Spawn(s32 count, WorldPos* pos, PuffParam* params) {
#ifdef NONMATCHING_C
  s32 i;
  s32 spawned;

  if (sPuffManager == NULL) {
    if (PuffManager_Create(0, 0) == NULL) {
      return -1;
    }
  }

  spawned = 0;
  for (i = 0; i < 32; i++) {
    Puff* elem = &sPuffManager->elems[i];
    s32 angleY;
    s32 angleXZ;

    if (elem->active) {
      continue;
    }

    elem->active = TRUE;
    elem->kind = params->kind;
    elem->timer = 0;
    elem->speedY = params->speedYRand == 0 ? params->speedY : params->speedY + Mod(RandomNext(), params->speedYRand);
    elem->speedXZ = params->speedXZRand == 0 ? params->speedXZ : params->speedXZ + Mod(RandomNext(), params->speedXZRand);
    angleY = params->angleYRand == 0 ? params->angleY : params->angleY + Mod(RandomNext(), params->angleYRand);
    angleXZ = params->angleXZRand == 0 ? params->angleXZ : params->angleXZ + Mod(RandomNext(), params->angleXZRand);
    elem->decayStartY = params->decayStartYRand == 0 ? params->decayStartY : params->decayStartY + Mod(RandomNext(), params->decayStartYRand);
    elem->decayStartXZ = params->decayStartXZRand == 0 ? params->decayStartXZ : params->decayStartXZ + Mod(RandomNext(), params->decayStartXZRand);

    if (params->flags & 1) {
      elem->sprite.flags |= SPRFLAG_BLINK_ODD;
    } else {
      elem->sprite.flags &= ~SPRFLAG_BLINK_ODD;
      elem->sprite.flags &= ~SPRFLAG_BLINK_EVEN;
    }
    if (params->flags & 2) {
      elem->sprite.flags |= SPRFLAG_SCREEN_COORD;
    } else {
      elem->sprite.flags &= ~SPRFLAG_SCREEN_COORD;
    }

    elem->dir.x = COS(angleXZ);
    elem->dir.y = SIN(angleY);
    elem->dir.z = SIN(angleXZ);
    elem->vel.x = FixToInt(12, elem->dir.x * elem->speedXZ);
    elem->vel.y = FixToInt(12, elem->dir.y * elem->speedY);
    elem->vel.z = FixToInt(12, elem->dir.z * elem->speedXZ);

    if (elem->kind == 5) {
      Video_GetAuxSprite(&elem->gfx, SPRITE_DUNEYRR_AUX);
      Video_SetAuxSpritePltt(&elem->gfx, 548);
      elem->sprite.poseIdx = 32;
      AuxAnim_SetAnim(&elem->anim, sPuffManager->animFiles[1], 6, 0, 0);
    } else if (elem->kind == 6) {
      Video_GetAuxSprite(&elem->gfx, SPRITE_DUNEYRR_AUX);
      Video_SetAuxSpritePltt(&elem->gfx, 556);
      elem->sprite.poseIdx = 32;
      AuxAnim_SetAnim(&elem->anim, sPuffManager->animFiles[1], 6, 0, 0);
    } else if (elem->kind == 7) {
      Video_GetAuxSprite(&elem->gfx, SPRITE_DUNEYRR_AUX);
      Video_SetAuxSpritePltt(&elem->gfx, 555);
      elem->sprite.poseIdx = 45;
      AuxAnim_SetAnim(&elem->anim, sPuffManager->animFiles[1], 8, 0, 0);
    } else {
      Video_GetAuxSprite(&elem->gfx, SPRITE_PUFF_4384);
      Video_SetAuxSpritePltt(&elem->gfx, elem->kind + 125);
      AuxAnim_SetAnim(&elem->anim, sPuffManager->animFiles[0], 0, 0, 0);
    }

    AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);

    elem->sprite.pos = *pos;
    elem->sprite.priority = Puff_GetPriority(params->flags);
    AuxAnim_SetAnimSpeed(&elem->anim, params->animSpeed);
    Video_AddAuxSpriteIntoDrawList(&elem->sprite, 0);

    spawned++;
    if (spawned >= count) {
      return 0;
    }
  }

  return -1;
#else
  INCFUNC("asm/func/Puff_Spawn.inc");
#endif
}

// count 個を 256 を等分した向きへ1つずつ発生させる
void Puff_SpawnRadial(WorldPos* pos, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay) {
  PuffParam param;
  s32 step;
  s32 i;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = 0;
  param.speedYRand = 0;
  param.speedXZ = speedXZ;
  param.speedXZRand = 0;
  step = Div(256, count);
  param.angleYRand = 0;
  param.angleY = 0;
  param.decayStartY = decayStart;
  param.decayStartYRand = 0;
  param.decayY = decay;
  param.decayYRand = 0;
  param.decayStartXZ = decayStart;
  param.decayStartXZRand = 0;
  param.decayXZ = decay;
  param.decayXZRand = 0;
  param.angleXZRand = 10;
  param.angleXZ = 0;

  for (i = 0; i < count; i++) {
    Puff_Spawn(1, pos, &param);
    param.angleXZ += step;
  }
}

// base を中心に mask でマスクした乱数ぶんずらした位置へ count 個発生させる
// 125/125 命令, base/mask は Vec3* ではなく u16* (原典は ldrh で読む), 残るのはレジスタ割り当ての入れ替えのみ
NON_MATCH void Puff_SpawnInBox(u16* base, u16* mask, u32 angleXZ, u32 angleXZRand, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay) {
#ifdef NONMATCHING_C
  PuffParam param;
  Vec3 spawnPos;
  s32 i;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = 0;
  param.speedYRand = 0;
  param.speedXZ = speedXZ;
  param.speedXZRand = 0;
  param.angleY = 0;
  param.angleYRand = 0;
  param.angleXZ = angleXZ;
  param.angleXZRand = angleXZRand;
  param.decayStartY = decayStart;
  param.decayStartYRand = 0;
  param.decayY = decay;
  param.decayYRand = 0;
  param.decayStartXZ = decayStart;
  param.decayStartXZRand = 0;
  param.decayXZ = decay;
  param.decayXZRand = 0;

  for (i = 0; i < count; i++) {
    spawnPos.x = (Random() & mask[0]) + base[0];
    spawnPos.y = (Random() & mask[1]) + base[1];
    spawnPos.z = (Random() & mask[2]) + base[2];
    Puff_Spawn(1, &spawnPos, &param);
  }
#else
  INCFUNC("asm/func/Puff_SpawnInBox.inc");
#endif
}

void Puff_SpawnHorizontal(WorldPos* pos, u32 angleXZ, u32 angleXZRand, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay) {
  PuffParam param;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = 0;
  param.speedYRand = 0;
  param.speedXZ = speedXZ;
  param.speedXZRand = 0;
  param.angleY = 0;
  param.angleYRand = 0;
  param.angleXZ = angleXZ;
  param.angleXZRand = angleXZRand;
  param.decayStartY = decayStart;
  param.decayStartYRand = 0;
  param.decayY = decay;
  param.decayYRand = 0;
  param.decayStartXZ = decayStart;
  param.decayStartXZRand = 0;
  param.decayXZ = decay;
  param.decayXZRand = 0;
  Puff_Spawn(count, pos, &param);
}

// 発生パラメータを決め打ちで組んで count 個ぶん発生させる
void Puff_SpawnSpray(s32 count, u32 kind, u32 flags, u32 animSpeed, WorldPos* pos) {
  PuffParam param;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = 12;
  param.speedYRand = 12;
  param.speedXZ = 4;
  param.speedXZRand = 4;
  param.angleY = 60;
  param.angleYRand = 8;
  param.angleXZ = 0;
  param.angleXZRand = 255;
  param.decayStartY = 255;
  param.decayStartYRand = 0;
  param.decayY = 255;
  param.decayYRand = 0;
  param.decayStartXZ = 255;
  param.decayStartXZRand = 0;
  param.decayXZ = 255;
  param.decayXZRand = 0;
  Puff_Spawn(count, pos, &param);
}

void Puff_SpawnSprayEx(s32 count, u32 kind, u32 flags, u32 animSpeed, u32 angleXZ, u32 angleXZRand, u32 speedXZ, s32 speedXZRand, u32 speedY, s32 speedYRand, WorldPos* pos) {
  PuffParam param;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = speedY;
  param.speedYRand = speedYRand;
  param.speedXZ = speedXZ;
  param.speedXZRand = speedXZRand;
  param.angleY = 60;
  param.angleYRand = 8;
  param.angleXZ = angleXZ;
  param.angleXZRand = angleXZRand;
  param.decayStartY = 255;
  param.decayStartYRand = 0;
  param.decayY = 255;
  param.decayYRand = 0;
  param.decayStartXZ = 255;
  param.decayStartXZRand = 0;
  param.decayXZ = 255;
  param.decayXZRand = 0;
  Puff_Spawn(count, pos, &param);
}

void Puff_SpawnSprayOne(WorldPos* pos, u32 kind, u32 flags, u32 animSpeed, u32 speedY, s32 speedYRand, u32 speedXZ, s32 speedXZRand) {
  PuffParam param;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = speedY;
  param.speedYRand = speedYRand;
  param.speedXZ = speedXZ;
  param.speedXZRand = speedXZRand;
  param.angleY = 60;
  param.angleYRand = 8;
  param.angleXZ = 0;
  param.angleXZRand = 255;
  param.decayStartY = 255;
  param.decayStartYRand = 0;
  param.decayY = 255;
  param.decayYRand = 0;
  param.decayStartXZ = 255;
  param.decayStartXZRand = 0;
  param.decayXZ = 255;
  param.decayXZRand = 0;
  Puff_Spawn(1, pos, &param);
}

void UNUSED Puff_SpawnSprayOneEx(WorldPos* pos, u32 kind, u32 flags, u32 animSpeed, u32 speedY, s32 speedYRand, u32 speedXZ, s32 speedXZRand, u32 angleY, u32 angleYRand) {
  PuffParam param;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = speedY;
  param.speedYRand = speedYRand;
  param.speedXZ = speedXZ;
  param.speedXZRand = speedXZRand;
  param.angleY = angleY;
  param.angleYRand = angleYRand;
  param.angleXZ = 0;
  param.angleXZRand = 255;
  param.decayStartY = 255;
  param.decayStartYRand = 0;
  param.decayY = 255;
  param.decayYRand = 0;
  param.decayStartXZ = 255;
  param.decayStartXZRand = 0;
  param.decayXZ = 255;
  param.decayXZRand = 0;
  Puff_Spawn(1, pos, &param);
}

// ランダムな向きへ speedXZ * 40 ぶんずらした位置に1個発生させる
// 命令数・順序とも一致 (108/108) するが &param (sp のコピー) の作り位置が1つ手前にずれる. 原典は乱数テーブルのプール読みの後に作る
// ずらし量は POLAR_X/POLAR_Z(speedXZ * 40, angleXZ + 0x80), agbcc は (speedXZ*40)*table を speedXZ*(40*table) に再結合する
NON_MATCH void UNUSED Puff_SpawnConverging(WorldPos* pos, u32 _, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay) {
#ifdef NONMATCHING_C
  PuffParam param;
  Vec3 spawnPos;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = 0;
  param.speedYRand = 0;
  param.speedXZ = speedXZ;
  param.speedXZRand = 0;
  param.angleXZ = (u8)Random();
  param.angleXZRand = 0;
  param.angleYRand = 0;
  param.angleY = 0;
  param.decayStartY = decayStart;
  param.decayStartYRand = 0;
  param.decayY = decay;
  param.decayYRand = 0;
  param.decayStartXZ = decayStart;
  param.decayStartXZRand = 0;
  param.decayXZ = decay;
  param.decayXZRand = 0;

  spawnPos.x = pos->x + POLAR_X(speedXZ * 40, param.angleXZ + 128);
  spawnPos.y = pos->y;
  spawnPos.z = pos->z + POLAR_Z(speedXZ * 40, param.angleXZ + 128);
  Puff_Spawn(1, &spawnPos, &param);
#else
  INCFUNC("asm/func/Puff_SpawnConverging.inc");
#endif
}

// 0x4383, スクリプトの名前付き引数をそのまま発生パラメータにして発生させる
void Cmd_SpawnPuffs(void) {
  PuffParam param;
  Vec3 pos;
  s32 count = VM_GetNamedArgValue('n', 1);

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }

  param.kind = VM_GetNamedArgValue('t', 0);
  param.flags = VM_GetNamedArgValue('f', 0);
  param.animSpeed = VM_GetNamedArgValue('a', Q6(1));

  if (VM_SeekToNamedArg('s')) {
    param.speedY = VM_GetValue();
    param.speedYRand = VM_GetValue();
    param.speedXZ = VM_GetValue();
    param.speedXZRand = VM_GetValue();
  } else {
    param.speedY = 0;
    param.speedYRand = 0;
    param.speedXZ = 0;
    param.speedXZRand = 0;
  }

  if (VM_SeekToNamedArg('d')) {
    param.angleY = VM_GetValue();
    param.angleYRand = VM_GetValue();
    param.angleXZ = VM_GetValue();
    param.angleXZRand = VM_GetValue();
  } else {
    param.angleY = 0;
    param.angleYRand = 0;
    param.angleXZ = 0;
    param.angleXZRand = 0;
  }

  if (VM_SeekToNamedArg('c')) {
    param.decayStartY = VM_GetValue();
    param.decayStartYRand = VM_GetValue();
    param.decayY = VM_GetValue();
    param.decayYRand = VM_GetValue();
    param.decayStartXZ = VM_GetValue();
    param.decayStartXZRand = VM_GetValue();
    param.decayXZ = VM_GetValue();
    param.decayXZRand = VM_GetValue();
  } else {
    param.decayStartY = 255;
    param.decayStartYRand = 0;
    param.decayY = 255;
    param.decayYRand = 0;
    param.decayStartXZ = 255;
    param.decayStartXZRand = 0;
    param.decayXZ = 255;
    param.decayXZRand = 0;
  }

  Puff_Spawn(count, &pos, &param);
}
