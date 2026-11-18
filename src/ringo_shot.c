#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "sprite_aux.h"
#include "vec3.h"

// リンゴ(BOSS_RINGO) の太陽銃(ソル属性)
// ダーイン(BOSS_DAINN)のダークブラスト(ダーク属性)

// 弾1発
typedef struct {
  u8 kind;             // 0x00, 0 と 2 は state 0, 1 は state 1 で始まる
  bool8 stateEntered;  // 0x01, state が変わると 1, 各 state の最初のフレームで 0 に戻す
  u8 state;            // 0x02, sRingoShotStates の添字 (0: 直進, 1: target を追う, 2: 着弾して消える)
  u8 angle;            // 0x03, 進む向き, gSineTable の添字
  u16 timer;           // 0x04, state に入ってからのフレーム数, state 0 と 1 では 128 を超えると消える
  u16 speed;           // 0x06, 1フレームの移動量, gSineTable との積を 12bit 右シフトして足す
  u8 turnRate;         // 0x08, state 1 で angle を target へ寄せる1フレームの上限, 1 固定
  u8 unk_9[3];         // 0x09
  Vec3* target;        // 0x0C, state 1 で追う座標
  Hitbox hitbox;       // 0x10, 当たると state 2 へ移る
  AuxSprite sprite;    // 0x60, pos が弾の座標, 地面より低くなると state 2 へ移る
} RingoShot;
static_assert(sizeof(RingoShot) == 140);

// 地形か相手に当たるまで直進または追尾する弾を最大16発管理する
typedef struct RingoShotManager {
  Entity e;                      // 0x000, ENTITY_UNK_8
  u32 activeMask;                // 0x018, 1 << i で elems[i] が使用中
  u16 unk_1c;                    // 0x01C, 10 が入るだけ
  u16 unk_1e;                    // 0x01E, 10 が入るだけ
  bool32 isDark;                 // 0x020, 0 ならソル属性でパレット 44, それ以外はダーク属性でパレット 50
  AuxSpriteGfx gfx;              // 0x024, SPR_EBALL_210E
  RingoShot elems[16];  // 0x040
} RingoShotManager;
static_assert(sizeof(RingoShotManager) == 2304);

// pos のタイルの高さを返す, map_inline.h の TileHeightAt と違って u32 で返すので比較が符号なしになる
static inline u32 FloorHeightAt(WorldPos* pos) { return TileHeightAtIndex(GetCollisionTileIdx(pos), pos); }

// 状態を入れ替えて経過フレームを0に戻す
static inline void RingoShot_SetState(RingoShot* elem, u8 state) {
  elem->state = state;
  elem->stateEntered = TRUE;
  elem->timer = 0;
}

// 空いている枠を返し, 添字を *outIdx に入れる, 無ければ NULL
RingoShot* RingoShotManager_AllocShot(RingoShotManager* p, u32* outIdx) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (!(p->activeMask & 1 << i)) {
      *outIdx = i;
      return &p->elems[i];
    }
  }
  return NULL;
}

// 当たったら state 2 (着弾) へ移る
void RingoShot_OnHit(Hitbox* a, Hitbox* b, RingoShot* elem) { RingoShot_SetState(elem, 2); }

// 弾1発分のスプライトと攻撃判定を作る, 原典は return を書き忘れている
// 残差は冒頭の 0 の使い回しだけ (85/85), 原典は state と angle に同じ 0, timer と Vec3_Clear に別の 0 を使うが, こちらは state と timer と Vec3_Clear で共有する
// SetState の展開, state を u32 にする形, angle を先に書く形, CpuFill32 は試済, project_elem_init_zero_wall と同じ壁
NON_MATCH s32 RingoShot_Init(RingoShotManager* p, RingoShot* elem, s32 index) {
#ifdef NONMATCHING_C
  AuxSprite* sprite;
  Vec3* pos;
  Hitbox* hitbox;
  Vec3 size, offset;

  RingoShot_SetState(elem, 0);
  elem->angle = 0;
  sprite = &elem->sprite;
  AuxSprite_Add(sprite, &p->gfx, SPRFLAG_HIDDEN | SPRFLAG_AFFINE);
  sprite->poseIdx = 1;
  sprite->priority = 2;
  pos = &elem->sprite.pos;
  Vec3_Clear(pos);

  hitbox = &elem->hitbox;
  VEC3_SET(size, 30, 240, 30);
  VEC3_SET(offset, 0, 120, 0);
  Hitbox_Init(hitbox, 0, HBF_HITBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetPos(hitbox, pos, 0);
  Hitbox_SetHandler(hitbox, RingoShot_OnHit, elem);
  Hitbox_SetAttack(hitbox, 10, 10, HBSRC_GUN, HBATTR_SOL, 30);
#else
  INCFUNC("asm/func/RingoShot_Init.inc");
#endif
}

// 原典は return を書き忘れている
s32 RingoShot_Destroy(RingoShotManager* p, RingoShot* elem, s32 index) { AuxSprite_Remove(&elem->sprite); }

// 弾を隠して使用中ビットを落とす, 原典は return を書き忘れている
s32 RingoShot_Release(RingoShotManager* p, RingoShot* elem, s32 index) {
  elem->sprite.flags |= SPRFLAG_HIDDEN;
  p->activeMask &= ~(1 << index);
}

// target の方向へ1フレーム turnRate 刻みで向きを寄せる
void RingoShot_TurnToTarget(RingoShot* elem) {
  Vec3* pos = &elem->sprite.pos;
  s8 d = ArcTan2_8(elem->target->x - pos->x, elem->target->z - pos->z) - elem->angle;

  if (d < -elem->turnRate) {
    d = -elem->turnRate;
  } else if (d > elem->turnRate) {
    d = elem->turnRate;
  }
  elem->angle += d;
}

// state 0, angle へまっすぐ進み, 地面に着いたら着弾し, 128 フレーム経ったら消える
void RingoShot_StateMove(RingoShotManager* p, RingoShot* elem, s32 index) {
  AuxSprite* sprite = &elem->sprite;
  Vec3 d;

  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
  }
  Vec3_SetPolar(&d, elem->angle, elem->speed);
  Vec3_Add(&sprite->pos, &d);
  Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
  Hitbox_Register(&elem->hitbox);
  if (sprite->pos.y <= FloorHeightAt(&sprite->pos)) {
    RingoShot_SetState(elem, 2);
  } else if (elem->timer >= 128) {
    RingoShot_Release(p, elem, index);
  } else {
    elem->timer++;
  }
}

// state 1, target へ向きを寄せながら進み, 地面に着いたら着弾し, 128 フレーム経ったら消える
void RingoShot_StateHoming(RingoShotManager* p, RingoShot* elem, s32 index) {
  AuxSprite* sprite = &elem->sprite;
  Vec3 d;

  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
  }
  RingoShot_TurnToTarget(elem);
  Vec3_SetPolar(&d, elem->angle, elem->speed);
  Vec3_Add(&sprite->pos, &d);
  Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
  Hitbox_Register(&elem->hitbox);
  if (sprite->pos.y <= FloorHeightAt(&sprite->pos)) {
    RingoShot_SetState(elem, 2);
  } else if (elem->timer >= 128) {
    RingoShot_Release(p, elem, index);
  } else {
    elem->timer++;
  }
}

// state 2, 着弾したら 3 フレーム目に進む向きの8方向でポーズと反転を決め, 6 フレームで消える
void RingoShot_StateImpact(RingoShotManager* p, RingoShot* elem, s32 index) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    sprite->poseIdx = 4;
  }
  if (elem->timer == 3) {
    s32 dir = Angle_ToDir8(elem->angle);

    if (dir & 1) {
      sprite->poseIdx = 7;
    } else if ((dir >> 1) & 1) {
      sprite->poseIdx = 8;
    } else {
      sprite->poseIdx = 6;
    }
    if (dir <= 2) {
      sprite->flags &= ~(SPRFLAG_XFLIP | SPRFLAG_YFLIP);
    } else if (dir <= 4) {
      sprite->flags &= ~SPRFLAG_XFLIP;
      sprite->flags |= SPRFLAG_YFLIP;
    } else if (dir <= 5) {
      sprite->flags |= SPRFLAG_XFLIP | SPRFLAG_YFLIP;
    } else {
      sprite->flags |= SPRFLAG_XFLIP;
      sprite->flags &= ~SPRFLAG_YFLIP;
    }
  } else if (elem->timer > 5) {
    RingoShot_Release(p, elem, index);
    return;
  }
  elem->timer++;
}

void (*const sRingoShotStates[3])(RingoShotManager*, RingoShot*, s32) = {
    RingoShot_StateMove,
    RingoShot_StateHoming,
    RingoShot_StateImpact,
};  // 0x085ABA20

s32 RingoShotManager_Update(RingoShotManager* p) {
  RingoShot* elem = p->elems;
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    if (p->activeMask & 1 << i) {
      sRingoShotStates[elem->state](p, elem, i);
    }
  }
  return 0;
}

s32 RingoShotManager_Destroy(RingoShotManager* p) {
  RingoShot* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 16; i++, elem++) {
    RingoShot_Destroy(p, elem, i);
  }
  return 0;
}

s32 RingoShotManager_Init(RingoShotManager* p, bool32 isDark) {
  RingoShot* elem;
  s32 i;

  p->unk_1c = 10;
  p->unk_1e = 10;
  Video_GetAuxSprite(&p->gfx, SPR_EBALL_210E);
  p->isDark = isDark;
  Video_SetAuxSpritePltt(&p->gfx, isDark == FALSE ? 44 : 50);
  elem = &p->elems[0];
  for (i = 0; i < 16; i++, elem++) {
    RingoShot_Init(p, elem, i);
  }
  return 0;
}

RingoShotManager* RingoShotManager_Create(bool32 isDark) {
  RingoShotManager* p = CreateEntity(ENTITY_UNK_8, sizeof(RingoShotManager));

  if (p != NULL) {
    SetEntityRoutine(p, RingoShotManager_Update, RingoShotManager_Destroy);
    if (RingoShotManager_Init(p, isDark) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 空いている枠に弾を1発出す, pos から angle の向きへ飛ばし, kind 1 なら target を追わせる, 枠がなければ -1
s32 RingoShotManager_Spawn(RingoShotManager* p, Vec3* pos, Vec3* target, u32 kind, u32 angle, s32 speed, s32 power, s32 knockback) {
  u32 index;
  RingoShot* elem = RingoShotManager_AllocShot(p, &index);
  AuxSprite* sprite;

  if (elem == NULL) {
    return -1;
  }
  sprite = &elem->sprite;
  elem->kind = kind;
  switch (elem->kind) {
    case 0: {
      RingoShot_SetState(elem, 0);
      break;
    }
    case 1: {
      RingoShot_SetState(elem, 1);
      break;
    }
    case 2: {
      RingoShot_SetState(elem, 0);
      break;
    }
  }
  elem->speed = speed;
  elem->angle = angle;
  elem->turnRate = 1;
  elem->target = target;
  Hitbox_SetAttack(&elem->hitbox, power, knockback, HBSRC_GUN, p->isDark == FALSE ? HBATTR_SOL : HBATTR_DARK, 30);
  sprite->pos = *pos;
  sprite->flags &= ~SPRFLAG_HIDDEN;
  sprite->poseIdx = 1;
  Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
  p->activeMask |= 1 << index;
  return 0;
}
