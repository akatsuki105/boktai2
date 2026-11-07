#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vec3.h"
#include "video.h"

// 1発ぶんのエフェクト
typedef struct {
  AuxSprite sprite;       // 0x00
  AuxAnimState anim;      // 0x2C
  HitboxData hitbox;      // 0x3C, 攻撃判定
  HitboxData hurtbox;     // 0x8C, 食らい判定
  Vec3 vel;               // 0xDC, 1フレームに進む量
  WorldPos basePos;       // 0xE4, 状態 1 に入ったときの位置, y は 1P より 220 上を目指して下がる
  AuxAnimFile* animFile;  // 0xEC
  u16 unk_f0;             // 0xF0, Entity080df420_Spawn の第4引数として子へ渡す
  u8 bobAngle;            // 0xF2, 上下に揺れる位相, 毎フレーム +4
  u8 unk_f3;              // 0xF3, FUN_080df478 が 1 を入れる
  s16 flags;              // 0xF4, FUN_080de344 が bit2 を立てる
  u8 state;               // 0xF6, _Update が 0x085AD354 の関数表の添字として引く
  s8 index;               // 0xF7, Entity080df420_AllocElem が確保したスロット番号を入れる
  u16 timer;              // 0xF8, FUN_080de344 が毎フレーム減らし, 0 になると 3 に戻す
  u8 unk_fa[2];           // 0xFA, まだ未解析, padding?
} Entity080df420Elem;
static_assert(sizeof(Entity080df420Elem) == 252);

typedef struct {
  Entity e;                      // 0x00, ENTITY_UNK_10
  AuxSpriteGfx gfx;              // 0x18, SPRITE_EFF_F422
  u8 unk_34[4];                  // 0x34, まだ未解析
  u32 usedMask;                  // 0x38, elems のどのスロットが使用中か, Entity080df420_AllocElem が立てる
  s16 frame;                     // 0x3C, _Update が毎フレーム 1 足す
  u16 count;                     // 0x3E, Entity080df420_AllocElem が確保のたびに 1 足す
  Entity080df420Elem elems[24];  // 0x40
} Entity080df420;
static_assert(sizeof(Entity080df420) == 6112);

IWRAM_DATA Entity080df420* gEntity080df420 = NULL;  // 0x03000178

static inline void Entity080df420_SetGlobal(Entity080df420* p) { gEntity080df420 = p; }

static inline bool8 Entity080df420_IsUsed(Entity080df420* p, s32 i) {
  if (TEST_FLAGS(p->usedMask, 1 << i)) return TRUE;
  return FALSE;
}

void nop_080de81c(Entity080df420*, Entity080df420Elem*);
void FUN_080de820(Entity080df420*, Entity080df420Elem*);

void (*const sEntity080df420Updates[2])(Entity080df420*, Entity080df420Elem*) = {
    nop_080de81c,
    FUN_080de820,
};  // 0x085AD354

void FUN_080debbc(Entity080df420*, Entity080df420Elem*);
void Entity080df420Elem_OnHit(HitboxData* a, HitboxData* b, Entity080df420Elem* elem);
void Entity080df420Elem_OnHurt(HitboxData* a, HitboxData* b, Entity080df420Elem* elem);
void Entity081ee2a0_SpawnDefault(Vec3* pos, Vec3* vel, s32 lifetime, s32 kind);
void FUN_08240cc4(s16 x, s16 z, s16 param_3, s16 param_4, u8 param_5);
Entity080df420* Entity080df420_Create(void);
void Entity080df420_Spawn(WorldPos* pos, Vec3* vel, s32 kind, s32 unk_f0, s32 invincibleTime, s32 power, s32 knockback, HitboxAttributes attrs, s32 atkInvincibleTime);
void Entity080df420Elem_StateVanish(Entity080df420*, Entity080df420Elem*);

void (*const PTR_ARRAY_085ad35c[2])(Entity080df420*, Entity080df420Elem*) = {
    FUN_080debbc,
    Entity080df420Elem_StateVanish,
};  // 0x085AD35C

Entity080df420Elem* Entity080df420_AllocElem(Entity080df420* p) {
  s32 i;

  for (i = 0; i < 24; i++) {
    if (!Entity080df420_IsUsed(p, i)) {
      Entity080df420Elem* elem = &p->elems[i];

      p->usedMask |= 1 << i;
      p->count++;
      elem->index = i;
      return elem;
    }
  }
  return NULL;
}

// angle に直交する面に沿って6方向へ火の粉を飛ばす
void FUN_080de1cc(Entity080df420Elem* elem, s32 angle) {
  Vec3 vel;
  s32 dir = ((angle + 32) & 0xFF) >> 6;

  if (dir == 0 || dir == 2) {
    VEC3_SET(vel, 0, 0, -30);
  } else {
    VEC3_SET(vel, -30, 0, 0);
  }
  Entity081ee2a0_SpawnDefault(&elem->sprite.pos, &vel, 10, 4);
  if (dir == 0 || dir == 2) {
    VEC3_SET(vel, 0, 15, -15);
  } else {
    VEC3_SET(vel, -15, 15, 0);
  }
  Entity081ee2a0_SpawnDefault(&elem->sprite.pos, &vel, 10, 4);
  if (dir == 0 || dir == 2) {
    VEC3_SET(vel, 0, 15, 15);
  } else {
    VEC3_SET(vel, 15, 15, 0);
  }
  Entity081ee2a0_SpawnDefault(&elem->sprite.pos, &vel, 10, 4);
  if (dir == 0 || dir == 2) {
    VEC3_SET(vel, 0, 0, 30);
  } else {
    VEC3_SET(vel, 30, 0, 0);
  }
  Entity081ee2a0_SpawnDefault(&elem->sprite.pos, &vel, 10, 4);
  if (dir == 0 || dir == 2) {
    VEC3_SET(vel, 0, -15, -15);
  } else {
    VEC3_SET(vel, -15, -15, 0);
  }
  Entity081ee2a0_SpawnDefault(&elem->sprite.pos, &vel, 10, 4);
  if (dir == 0 || dir == 2) {
    VEC3_SET(vel, 0, -15, 15);
  } else {
    VEC3_SET(vel, 15, -15, 0);
  }
  Entity081ee2a0_SpawnDefault(&elem->sprite.pos, &vel, 10, 4);
}

// 待ちが切れた枠を1フレームに6つまで選んで攻撃判定を出させる
void FUN_080de344(Entity080df420* p) {
  Entity080df420Elem* elems = p->elems;

  if (p->count != 0) {
    s32 n = 0;
    s32 i;

    for (i = 0; i < 24; i++) {
      if (Entity080df420_IsUsed(p, i)) {
        if (elems[i].timer != 0) {
          elems[i].timer--;
        } else if (n <= 5) {
          elems[i].timer = 3;
          elems[i].flags |= 4;
          n++;
        }
      }
    }
  }
}

// 攻撃判定が当たったら, 分裂する弾なら6つの小さな弾を散らし, 火の粉と効果音を出して消滅へ移る
// 167/167命令, ループ外へ出す定数の順だけが違う (原典は &gRandTableIdx を半径 5 より先に sb へ置く), 試済: 角度を先にローカルへ
NON_MATCH void Entity080df420Elem_OnHit(HitboxData* a, HitboxData* b, Entity080df420Elem* elem) {
#ifdef NONMATCHING_C
  if (elem->flags & 1) {
    s32 angle = ArcTan2_8(elem->vel.x, elem->vel.z);
    s32 i;

    for (i = 0; i < 6; i++) {
      Vec3 vel;

      Vec3_SetPolar(&vel, angle + (Random() & 0xFF), 5);
      Entity080df420_Spawn(&elem->sprite.pos, &vel, 4, elem->unk_f0, 12, elem->hitbox.power, elem->hitbox.knockbackPower, elem->hitbox.attributes, elem->hitbox.invincibleTime);
    }
  }
  FUN_080de1cc(elem, ArcTan2_8(elem->vel.x, elem->vel.z));
  FUN_08240cc4(elem->sprite.pos.x, elem->sprite.pos.z, 0, 0, 0x80);
  Hitbox_Hide(&elem->hitbox);
  Hitbox_Hide(&elem->hurtbox);
  PlaySound_082406e0(991);
  elem->state = 3;
  elem->unk_f3 = 1;
#else
  INCFUNC("asm/func/Entity080df420Elem_OnHit.inc");
#endif
}

// 攻撃を食らったら, 分裂する弾なら6つの小さな弾を散らし, 火の粉と効果音を出して消滅へ移る
// 175/175命令, Entity080df420Elem_OnHit と同じループ外の定数の順に加え, スタックに置くポインタの並びが違う
NON_MATCH void Entity080df420Elem_OnHurt(HitboxData* a, HitboxData* b, Entity080df420Elem* elem) {
#ifdef NONMATCHING_C
  if (b->invincibleTime != 0) {
    return;
  }
  if (elem->flags & 1) {
    s32 angle = ArcTan2_8(elem->vel.x, elem->vel.z);
    s32 i;

    for (i = 0; i < 6; i++) {
      Vec3 vel;

      Vec3_SetPolar(&vel, angle + (Random() & 0xFF), 5);
      Entity080df420_Spawn(&elem->sprite.pos, &vel, 4, elem->unk_f0, 12, elem->hitbox.power, elem->hitbox.knockbackPower, elem->hitbox.attributes, elem->hitbox.invincibleTime);
    }
  }
  FUN_080de1cc(elem, a->angle);
  FUN_08240cc4(elem->sprite.pos.x, elem->sprite.pos.z, 0, 0, 0x80);
  Hitbox_Hide(&elem->hitbox);
  Hitbox_Hide(&elem->hurtbox);
  PlaySound_082406e0(991);
  elem->state = 3;
  elem->unk_f3 = 1;
#else
  INCFUNC("asm/func/Entity080df420Elem_OnHurt.inc");
#endif
}

// 攻撃判定と食らい判定を作る
// 96/98命令, 引数を受けるレジスタだけが違う (原典は elem を r6, power を sl, knockback を r7, attrs を r8 に置く), 試済: ローカルの宣言順, 2つ目の判定を hitbox++ で作る
NON_MATCH void Entity080df420Elem_InitHitboxes(Entity080df420Elem* elem, s32 power, s32 knockback, HitboxAttributes attrs, s32 invincibleTime, s32 defPower, HitboxAttributes defAttrs, s32 defWeakness) {
#ifdef NONMATCHING_C
  HitboxData* hitbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 32, 64, 32);
  VEC3_SET(offset, 0, 0, 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_10 | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, power, knockback, 0, attrs, invincibleTime);
  Hitbox_SetHandler(hitbox, Entity080df420Elem_OnHit, elem);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
  hitbox = &elem->hurtbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hitbox, defPower, defAttrs, defWeakness);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, Entity080df420Elem_OnHurt, elem);
  Hitbox_Register(hitbox);
#else
  INCFUNC("asm/func/Entity080df420Elem_InitHitboxes.inc");
#endif
}

// 攻撃判定を出す印が立っていれば判定を表に出して登録し, 立っていなければ隠す
void Entity080df420Elem_UpdateHitboxes(Entity080df420Elem* elem) {
  if (elem->hurtbox.invincibleTime != 0) {
    elem->hurtbox.invincibleTime--;
  }
  if (!(elem->flags & 4)) {
    Hitbox_Hide(&elem->hitbox);
    Hitbox_Hide(&elem->hurtbox);
  } else {
    elem->flags &= ~4;
    Hitbox_ClearFlags(&elem->hitbox, HBFLAG_HIDDEN);
    Hitbox_ClearFlags(&elem->hurtbox, HBFLAG_HIDDEN);
    Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
    Hitbox_SetPos(&elem->hurtbox, &elem->sprite.pos, 0);
    Hitbox_Register(&elem->hitbox);
  }
}

void nop_080de81c(Entity080df420* p, Entity080df420Elem* elem) {}

// state 1, 上下に揺れながら vel で飛び, 地形の無いところに出たら跳ね返って分裂する弾なら散らばり, アニメが一巡したら state 2 へ移る
// 442/429命令, 1回目の下書き (呼び出し列は一致), 残差は散らばる弾のループの外へ出すアドレスと乱数表の置き場所, こちらは bobAngle などのアドレスを分岐の前に作ってしまう
NON_MATCH void FUN_080de820(Entity080df420* p, Entity080df420Elem* elem) {
#ifdef NONMATCHING_C
  WorldPos next;
  s32 idx;
  CollisionMapTile* tile;
  s32 height;

  if (elem->unk_f3) {
    elem->basePos = elem->sprite.pos;
    elem->unk_f3 = 0;
  }
  Vec3_Sum(&next, &elem->vel, &elem->sprite.pos);
  idx = GetCollisionTileIdx(&next);
  tile = TileAtIndex(idx);
  height = TileHeightAtIndex(idx, &next);
  if (height <= 0) {
    elem->vel.x = -elem->vel.x;
    elem->vel.z = -elem->vel.z;
    if (elem->flags & 1) {
      s32 angle = ArcTan2_8(elem->vel.x, elem->vel.z);
      s32 i;

      for (i = 0; i < 6; i++) {
        Vec3 vel;
        u16* table = gRandomTable;
        s32 a = angle + (_Random(table) & 0xFF);
        s32 speed = (_Random(table) & 7) + 5;

        Vec3_SetPolar(&vel, a, speed);
        Entity080df420_Spawn(&elem->sprite.pos, &vel, 4, elem->unk_f0, 12, elem->hitbox.power, elem->hitbox.knockbackPower, elem->hitbox.attributes, elem->hitbox.invincibleTime);
      }
      elem->state = 3;
      elem->unk_f3 = 1;
    }
  } else {
    elem->sprite.pos = next;
  }
  elem->sprite.pos.y = elem->basePos.y + POLAR_Z(10, elem->bobAngle);
  elem->basePos.y = gPlayerPtr[0]->mover.pos.y + 220 < elem->basePos.y ? elem->basePos.y - 4 : gPlayerPtr[0]->mover.pos.y + 220;
  elem->bobAngle += 4;
  Entity080df420Elem_UpdateHitboxes(elem);
  if (AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim)) {
    AuxAnim_SetAnim(&elem->anim, elem->animFile, 2, 0, 0);
    elem->state = 2;
    elem->unk_f3 = 1;
  }
#else
  INCFUNC("asm/func/FUN_080de820.inc");
#endif
}

// 分裂した小さな弾, 上下に揺れながら vel で飛び, 地形の無いところに出たら乱数の向きへ跳ね返り, 寿命が尽きたら消滅へ移る
// 501/479命令, 1回目の下書き (呼び出し列は一致), FUN_080de820 と同じくループの外へ出すアドレスと乱数表の置き場所が違う
NON_MATCH void FUN_080debbc(Entity080df420* p, Entity080df420Elem* elem) {
#ifdef NONMATCHING_C
  WorldPos next;
  s32 idx;
  CollisionMapTile* tile;
  s32 height;

  if (elem->unk_f3) {
    elem->basePos = elem->sprite.pos;
    elem->sprite.flags &= ~SPRFLAG_AFFINE;
    elem->unk_f3 = 0;
  }
  Vec3_Sum(&next, &elem->vel, &elem->sprite.pos);
  idx = GetCollisionTileIdx(&next);
  tile = TileAtIndex(idx);
  height = TileHeightAtIndex(idx, &next);
  if (height <= 0) {
    s32 angle = ArcTan2_8(elem->vel.x, elem->vel.z);
    u16* table = gRandomTable;
    s32 a = angle + (_Random(table) & 31) + 63;
    s32 speed = (_Random(table) & 15) + 8;

    Vec3_SetPolar(&elem->vel, a, speed);
    if (elem->flags & 1) {
      s32 i;

      angle = ArcTan2_8(elem->vel.x, elem->vel.z);
      for (i = 0; i < 6; i++) {
        Vec3 vel;

        table = gRandomTable;
        a = (_Random(table) & 0xFF) + angle;
        speed = (_Random(table) & 1) + 4;
        Vec3_SetPolar(&vel, a, speed);
        Entity080df420_Spawn(&elem->sprite.pos, &vel, 4, elem->unk_f0, 12, elem->hitbox.power, elem->hitbox.knockbackPower, elem->hitbox.attributes, elem->hitbox.invincibleTime);
      }
      elem->state = 3;
      elem->unk_f3 = 1;
    }
  } else {
    elem->sprite.pos = next;
  }
  elem->sprite.pos.y = elem->basePos.y + POLAR_Z(10, elem->bobAngle);
  elem->basePos.y = gPlayerPtr[0]->mover.pos.y + 220 < elem->basePos.y ? elem->basePos.y - 4 : gPlayerPtr[0]->mover.pos.y + 220;
  elem->bobAngle += 4;
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  Entity080df420Elem_UpdateHitboxes(elem);
  if (elem->unk_f0 == 0) {
    elem->state = 3;
    elem->unk_f3 = 1;
  } else {
    elem->unk_f0--;
  }
#else
  INCFUNC("asm/func/FUN_080debbc.inc");
#endif
}

// 消滅のアニメを流し, 流し終えたら片付ける
void Entity080df420Elem_StateVanish(Entity080df420* p, Entity080df420Elem* elem) {
  if (elem->unk_f3) {
    if (elem->flags & 1) {
      AuxAnim_SetAnim(&elem->anim, elem->animFile, 3, 0, 0);
    } else {
      AuxAnim_SetAnim(&elem->anim, elem->animFile, 5, 0, 0);
    }
    Hitbox_Unregister(&elem->hurtbox);
    elem->unk_f3 = 0;
  }
  if (AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim)) {
    AuxSprite_Remove(&elem->sprite);
    CLEAR_BIT(p->usedMask, elem->index);
    p->count--;
    elem->index = -1;
    elem->state = 0;
  }
}

// 弾を1発出す, kind が 8 なら分裂する弾, 4 なら分裂しない弾
void Entity080df420_Spawn(WorldPos* pos, Vec3* vel, s32 kind, s32 unk_f0, s32 invincibleTime, s32 power, s32 knockback, HitboxAttributes attrs, s32 atkInvincibleTime) {
  Entity080df420* p = gEntity080df420;
  Entity080df420Elem* elem;
  AuxSprite* spr;

  if (p == NULL) {
    p = Entity080df420_Create();
    if (p == NULL) {
      return;
    }
  }
  elem = Entity080df420_AllocElem(p);
  if (elem == NULL) {
    return;
  }
  elem->unk_f0 = unk_f0;
  elem->flags = 0;
  elem->timer = 0;
  elem->vel = *vel;
  elem->unk_f3 = 1;
  if (kind == 8) {
    elem->state = 1;
    elem->flags |= 1;
  } else if (kind == 4) {
    elem->state = 2;
    elem->flags |= 2;
  }
  spr = &elem->sprite;
  elem->sprite.pos = *pos;
  elem->animFile = GetFile(DIR_ANIMATION, ANIM_121B);
  AuxSprite_Add(&elem->sprite, &p->gfx, 0);
  Video_SetAuxSpritePltt(elem->sprite.gfx, 0xDA);
  AuxAnim_SetAnim(&elem->anim, elem->animFile, kind, 0, 0);
  AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
  spr->priority = 1;
  Entity080df420Elem_InitHitboxes(elem, power, knockback, attrs, atkInvincibleTime, 0, 0, 0);
  elem->hurtbox.invincibleTime = invincibleTime;
}

s32 Entity080df420_Update(Entity080df420* p) {
  Entity080df420Elem* elems = p->elems;
  s32 i;

  if (p->usedMask != 0 && !TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER) && !TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    FUN_080de344(p);
    for (i = 0; i < 24; i++) {
      if (Entity080df420_IsUsed(p, i)) {
        sEntity080df420Updates[elems[i].state](p, &elems[i]);
      }
    }
    p->frame++;
  }
  return 0;
}

s32 Entity080df420_Destroy(Entity080df420* p) {
  s32 i;
  Entity080df420Elem* e;

  for (i = 0, e = p->elems; i < 24; e++, i++) {
    if (Entity080df420_IsUsed(p, i)) {
      AuxSprite_Remove(&e->sprite);
    }
  }
  Entity080df420_SetGlobal(NULL);
  return 0;
}

s32 Entity080df420_Init(Entity080df420* p) {
  p->usedMask = 0;
  p->frame = 0;
  p->count = 0;
  Video_GetAuxSprite(&p->gfx, SPRITE_EFF_F422);
  Entity080df420_SetGlobal(p);
  return 0;
}

Entity080df420* Entity080df420_Create(void) {
  Entity080df420* p;

  if (gEntity080df420 != NULL) {
    return gEntity080df420;
  }

  p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080df420));
  if (p != NULL) {
    SetEntityRoutine(p, Entity080df420_Update, Entity080df420_Destroy);
    if (Entity080df420_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

void FUN_080df46c(void) { gEntity080df420 = NULL; }

// 使用中の枠を全部 state 3 へ移す
void FUN_080df478(void) {
  Entity080df420* p = gEntity080df420;
  Entity080df420Elem* e;
  s32 i;

  if (p == NULL) {
    return;
  }
  if (p->usedMask == 0) {
    return;
  }

  for (i = 0; i < 24; i++) {
    e = &p->elems[i];
    if (Entity080df420_IsUsed(p, i)) {
      e->state = 3;
      e->unk_f3 = 1;
    }
  }
}
