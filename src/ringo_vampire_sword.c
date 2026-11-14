#include "constants/sprite.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "sound.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vec3.h"

// src/boss/ringo.c の "ヴァンパイアソード", 小さい剣を何本か自分の周りに浮かべて次々に飛ばす攻撃

typedef struct {
  u8 kind;             // 0x000, Spawn の kind, 2 未満なら狙い定め中に target の方へ向き直す
  bool8 stateEntered;  // 0x001, state を変えるたびに 1 を書く
  u8 state;            // 0x002, sVampireSwordStates の添字
  u8 plttState;        // 0x003, いま設定してあるパレットの種別
  u8 plttWanted;       // 0x004, 0 で 301, 1 で 304, 2 で 305 にする
  u8 unk_5[3];         // 0x005, まだ未解析
  u16 timer;           // 0x008, state を変えるたびに 0 に戻る
  u16 duration;        // 0x00A, timer がここに届くと state 1 へ移る
  u8 moveAngle;        // 0x00C, 進む向き, target への ArcTan2_8, 跳ね返りで反転する
  s8 angle;            // 0x00D, 見た目の向き, sprite.rotation に -(angle + 0x60) として入れる
  u16 speed;           // 0x00E, 1 フレームに進む距離, 飛ぶときは 40, 跳ね返りは 10
  Vec3 basePos;        // 0x010, 出現と跳ね返りの動きの基準点, sprite.pos の写し
  Vec3* target;        // 0x018, Spawn の target, 狙う先の座標
  HitboxData hitbox;   // 0x01C, flags 0x2001, ignoreMask 0x10, 攻撃側
  HitboxData hurtbox;  // 0x06C, flags 0x4005, ignoreMask 0x10, 被弾側
  AuxSprite sprite;    // 0x0BC, AFFINE|UNK_0, +0x1C の Vec3 を両方の Hitbox_SetPos に渡す
  AuxSpriteGfx gfx;    // 0x0E8, SPRITE_SLAVE_SWORD_AX
} VampireSword;
static_assert(sizeof(VampireSword) == 260);

typedef struct VampireSwordManager {
  Entity e;               // 0x000, ENTITY_UNK_8
  u32 activeMask;         // 0x018, 立っているビットの枠だけ Update が回す
  u16 attackID;           // 0x01C, Init の第2引数, 各枠の Hitbox_SetAttack に渡す
  u16 power;              // 0x01E, 10, 各枠の Hitbox_SetPowerAndAttributes に渡す
  VampireSword elems[8];  // 0x020
} VampireSwordManager;
static_assert(sizeof(VampireSwordManager) == 2112);

// pos のタイルの高さを返す, map_inline.h の TileHeightAt と違って u32 で返すので比較が符号なしになる
static inline u32 FloorHeightAt(WorldPos* pos) { return TileHeightAtIndex(GetCollisionTileIdx(pos), pos); }

// 状態を入れ替えて経過フレームを0に戻す
static inline void VampireSword_SetState(VampireSword* p, u8 state) {
  p->state = state;
  p->stateEntered = TRUE;
  p->timer = 0;
}

void VampireSword_StateWait(VampireSwordManager*, VampireSword*, s32);
void VampireSword_StateAppear(VampireSwordManager*, VampireSword*, s32);
void VampireSword_StateAim(VampireSwordManager*, VampireSword*, s32);
void VampireSword_StateFly(VampireSwordManager*, VampireSword*, s32);
void VampireSword_StateVanish(VampireSwordManager*, VampireSword*, s32);
void VampireSword_StateBounce(VampireSwordManager*, VampireSword*, s32);

// VampireSwordManager_Update が引く
void (*const sVampireSwordStates[6])(VampireSwordManager*, VampireSword*, s32) = {
    VampireSword_StateWait,
    VampireSword_StateAppear,
    VampireSword_StateAim,
    VampireSword_StateFly,
    VampireSword_StateVanish,
    VampireSword_StateBounce,
};  // 0x085AB9EC

// 空いている枠を先頭から探して添字も返す
VampireSword* VampireSwordManager_FindFree(VampireSwordManager* p, u32* outIndex) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!(p->activeMask & (1 << i))) {
      *outIndex = i;
      return &p->elems[i];
    }
  }
  return NULL;
}

// 当たったら状態5 (被弾) へ入れ直して効果音を鳴らす
void VampireSword_OnHurt(HitboxData* a, HitboxData* b, VampireSword* owner) {
  VampireSword_SetState(owner, 5);
  PlaySound_082406e0(SONG_368);
}

void VampireSword_OnHit(void) {}

// 原典は return を書き忘れている
// 残差は先頭で角度の 0 を r1 に別に作り elem を sl の写しから書く点と, それにつられた r0/r1/r2 の番号の違い (136/137命令)
// hitbox ローカル1本の使い回しで elem=sl は揃った, Tier A-C は試済 (連鎖代入, SetState の展開)
NON_MATCH s32 VampireSword_Init(VampireSwordManager* p, VampireSword* elem, s32 index) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;
  AuxSpriteGfx* gfx;
  Vec3* pos;
  HitboxData* hitbox;
  Vec3 halfSize, offset;

  VampireSword_SetState(elem, 1);
  elem->angle = 0;
  elem->moveAngle = 0;
  sprite = &elem->sprite;
  gfx = &elem->gfx;
  Video_GetAuxSprite(gfx, SPRITE_SLAVE_SWORD_AX);
  AuxSprite_Add(sprite, gfx, SPRFLAG_HIDDEN | SPRFLAG_AFFINE);
  sprite->poseIdx = 3;
  sprite->priority = 2;
  pos = &elem->sprite.pos;
  Vec3_Clear(pos);

  hitbox = &elem->hurtbox;
  VEC3_SET(halfSize, 64, 240, 64);
  VEC3_SET(offset, 0, 120, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HURTBOX | HBFLAG_HIDDEN | HBFLAG_UNK_0, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetPos(hitbox, pos, 0);
  Hitbox_SetHandler(hitbox, VampireSword_OnHurt, elem);
  Hitbox_SetPowerAndAttributes(hitbox, p->power, 0, 0);
  Hitbox_Register(hitbox);

  hitbox = &elem->hitbox;
  VEC3_SET(halfSize, 32, 240, 32);
  VEC3_SET(offset, 0, 120, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, HIM_4, &halfSize, &offset);
  Hitbox_SetPos(hitbox, pos, 0);
  Hitbox_SetHandler(hitbox, VampireSword_OnHit, elem);
  Hitbox_SetAttack(hitbox, p->attackID, 30, 0, HBATTR_17, 5);
#else
  INCFUNC("asm/func/VampireSword_Init.inc");
#endif
}

// 原典は return を書き忘れている
s32 VampireSword_Destroy(VampireSwordManager* p, VampireSword* elem, s32 index) {
  Hitbox_Unregister(&elem->hurtbox);
  AuxSprite_Remove(&elem->sprite);
}

// 枠を片付けて使用中ビットを落とす, 原典は return を書き忘れている
s32 VampireSword_Release(VampireSwordManager* p, VampireSword* elem, s32 index) {
  HitboxData* hitbox;

  elem->sprite.flags |= SPRFLAG_HIDDEN;
  hitbox = &elem->hurtbox;
  hitbox->flags |= HBFLAG_HIDDEN;
  p->activeMask &= ~(1 << index);
}

// duration まで待ってから state 1 へ移る
void VampireSword_StateWait(VampireSwordManager* p, VampireSword* elem, s32 index) {
  if (elem->stateEntered != 0) {
    elem->stateEntered = FALSE;
  }
  if (elem->timer >= elem->duration) {
    VampireSword_SetState(elem, 1);
    PlaySound_082406e0(SONG_365);
  }
  elem->timer++;
}

// 回りながら basePos へ渦を巻いて寄り, 32 フレームかけて縦に伸びて現れる
void VampireSword_StateAppear(VampireSwordManager* p, VampireSword* elem, s32 index) {
  AuxSprite* sprite = &elem->sprite;
  Vec3 ofs;
  u32 angle;

  if (elem->stateEntered != 0) {
    elem->stateEntered = FALSE;
    sprite->flags &= ~SPRFLAG_HIDDEN;
    sprite->scaleY = 1;
    elem->basePos = sprite->pos;
    elem->plttWanted = 1;
  }
  if ((elem->timer & 1) == 0) {
    elem->angle += 0x20;
  }
  angle = elem->timer * 8 + (elem->timer & 1) * 128;
  Vec3_SetPolar(&ofs, angle, (32 - elem->timer) * 8);
  Vec3_Sum(&sprite->pos, &ofs, &elem->basePos);
  if (elem->timer != 0) {
    sprite->scaleY = elem->timer * 2;
  } else {
    sprite->scaleY = 1;
  }
  if (elem->timer >= 32) {
    sprite->scaleY = 0x40;
    VampireSword_SetState(elem, 2);
  }
  elem->timer++;
}

// 前半 32 フレームは点滅しながら target の方へ向き直し, 64 フレーム経ったら飛ぶ
void VampireSword_StateAim(VampireSwordManager* p, VampireSword* elem, s32 index) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->stateEntered != 0) {
    HitboxData* hitbox;

    elem->stateEntered = FALSE;
    elem->angle = elem->moveAngle;
    hitbox = &elem->hurtbox;
    CLEAR_FLAGS(hitbox->flags, HBFLAG_HIDDEN);
  }
  if (elem->timer < 32) {
    if ((elem->timer & 7) < 4) {
      elem->plttWanted = 1;
    } else {
      elem->plttWanted = 0;
    }
    if (elem->kind < 2) {
      elem->angle = elem->moveAngle = ArcTan2_8(elem->target->x - sprite->pos.x, elem->target->z - sprite->pos.z);
    }
  }
  if (elem->timer >= 64) {
    elem->plttWanted = 0;
    VampireSword_SetState(elem, 3);
  }
  elem->timer++;
}

// moveAngle へまっすぐ飛び, 床に当たったら弾かれ, 128 フレーム経ったら消える
void VampireSword_StateFly(VampireSwordManager* p, VampireSword* elem, s32 index) {
  AuxSprite* sprite = &elem->sprite;
  Vec3 ofs;

  if (elem->stateEntered != 0) {
    HitboxData* hitbox;

    elem->stateEntered = FALSE;
    elem->angle = elem->moveAngle;
    elem->speed = 40;
    hitbox = &elem->hurtbox;
    CLEAR_FLAGS(hitbox->flags, HBFLAG_HIDDEN);
    PlaySound_082406e0(SONG_362);
  }
  Vec3_SetPolar(&ofs, elem->moveAngle, elem->speed);
  Vec3_Add(&sprite->pos, &ofs);
  Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
  Hitbox_Register(&elem->hitbox);
  Hitbox_SetPos(&elem->hurtbox, &elem->sprite.pos, 0);
  if (sprite->pos.y <= FloorHeightAt(&sprite->pos)) {
    VampireSword_SetState(elem, 5);
  } else if (elem->timer >= 128) {
    VampireSword_SetState(elem, 4);
  } else {
    elem->timer++;
  }
}

// 0x20 フレーム経ったら枠を片付ける
void VampireSword_StateVanish(VampireSwordManager* p, VampireSword* elem, s32 index) {
  if (elem->stateEntered != 0) {
    HitboxData* hitbox;

    elem->stateEntered = FALSE;
    hitbox = &elem->hurtbox;
    hitbox->flags |= HBFLAG_HIDDEN;
    elem->plttWanted = 0;
  }
  if (elem->timer >= 32) {
    VampireSword_Release(p, elem, index);
  } else {
    elem->timer++;
  }
}

// 弾かれて後ろへ下がりながら上下に揺れ, 点滅して 32 フレームで消える
void VampireSword_StateBounce(VampireSwordManager* p, VampireSword* elem, s32 index) {
  AuxSprite* sprite = &elem->sprite;
  Vec3 ofs;

  if (elem->stateEntered != 0) {
    HitboxData* hitbox;

    elem->stateEntered = FALSE;
    elem->speed = 10;
    elem->moveAngle += 0x80;
    elem->basePos = sprite->pos;
    hitbox = &elem->hurtbox;
    hitbox->flags |= HBFLAG_HIDDEN;
    elem->plttWanted = 0;
  }
  Vec3_SetPolar(&ofs, elem->moveAngle, elem->speed);
  Vec3_Add(&sprite->pos, &ofs);
  sprite->pos.y = elem->basePos.y + FixToInt(12, SIN(elem->timer * 4) * 256);
  elem->angle += 0x10;
  if (elem->timer < 16) {
    if (elem->timer & 1) {
      AuxSprite_Hide(sprite);
    } else {
      AuxSprite_Show(sprite);
    }
  } else {
    if ((elem->timer & 3) < 2) {
      AuxSprite_Hide(sprite);
    } else {
      AuxSprite_Show(sprite);
    }
  }
  if (elem->timer >= 32) {
    VampireSword_Release(p, elem, index);
  } else {
    elem->timer++;
  }
}

// 使用中の枠ごとに状態関数を回し, 向きとパレットの切り替えを sprite に反映する
s32 VampireSwordManager_Update(VampireSwordManager* p) {
  VampireSword* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    if (p->activeMask & (1 << i)) {
      AuxSprite* sprite;

      sVampireSwordStates[elem->state](p, elem, i);
      sprite = &elem->sprite;
      sprite->rotation = -(elem->angle + 0x60);
      if (elem->plttState != elem->plttWanted) {
        elem->plttState = elem->plttWanted;
        switch (elem->plttState) {
          case 0: {
            Video_SetAuxSpritePltt(&elem->gfx, 301);
            break;
          }
          case 1: {
            Video_SetAuxSpritePltt(&elem->gfx, 304);
            break;
          }
          case 2: {
            Video_SetAuxSpritePltt(&elem->gfx, 305);
            break;
          }
        }
      }
    }
  }
  return 0;
}

s32 VampireSwordManager_Destroy(VampireSwordManager* p) {
  VampireSword* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    VampireSword_Destroy(p, elem, i);
  }
  return 0;
}

s32 VampireSwordManager_Init(VampireSwordManager* p, u32 attackID) {
  VampireSword* elem;
  s32 i;

  p->attackID = attackID;
  p->power = 10;
  elem = &p->elems[0];
  for (i = 0; i < 8; i++, elem++) {
    VampireSword_Init(p, elem, i);
  }
  return 0;
}

VampireSwordManager* VampireSwordManager_Create(u32 attackID) {
  VampireSwordManager* p = CreateEntity(ENTITY_UNK_8, sizeof(VampireSwordManager));

  if (p != NULL) {
    SetEntityRoutine(p, VampireSwordManager_Update, VampireSwordManager_Destroy);
    if (VampireSwordManager_Init(p, attackID) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 空いている枠に剣を1本出す, pos に置いて target へ向け, delay フレーム待ってから現れる, 枠がなければ -1
s32 VampireSwordManager_Spawn(VampireSwordManager* p, Vec3* pos, u32 kind, Vec3* target, u32 speed, u32 delay) {
  u32 index;
  VampireSword* elem = VampireSwordManager_FindFree(p, &index);
  s32 angle;
  AuxSprite* sprite;
  HitboxData* hurtbox;

  if (elem == NULL) {
    return -1;
  }
  elem->target = target;
  angle = ArcTan2_8(target->x - pos->x, target->z - pos->z);
  sprite = &elem->sprite;
  elem->kind = kind;
  switch (elem->kind) {
    case 0: {
      VampireSword_SetState(elem, 0);
      break;
    }
    case 1: {
      VampireSword_SetState(elem, 0);
      break;
    }
    case 2: {
      VampireSword_SetState(elem, 0);
      break;
    }
  }
  elem->moveAngle = angle;
  elem->angle = angle;
  elem->speed = speed;
  sprite->pos = *pos;
  sprite->rotation = -(elem->angle + 0x60);
  sprite->flags |= SPRFLAG_HIDDEN;
  sprite->scaleY = 1;
  Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
  hurtbox = &elem->hurtbox;
  Hitbox_SetPos(hurtbox, &elem->sprite.pos, 0);
  hurtbox->flags |= HBFLAG_HIDDEN;
  elem->plttState = 0;
  elem->plttWanted = 0;
  elem->duration = delay;
  p->activeMask |= 1 << index;
  return 0;
}
