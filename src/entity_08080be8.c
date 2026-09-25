#include "definition.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "player.h"
#include "sprite.h"

struct Entity08080be8;
typedef void (*Entity08080be8Func)(struct Entity08080be8* p);

// FUN_080804a0 が1個ずつ撒く粒子。4個を順に使い回す
typedef struct {
  Particle base;   // 0x00, FUN_0822d9f0 や Particle_Remove に Particle* として渡る
  bool8 active;    // 0x28, FUN_080804a0 が 1 にし、Entity08080be8_UpdateParticles が寿命で 0 に戻す。0 の間は動かさない
  s8 angleOffset;  // 0x29, Mod(rand, 0x60) - 0x30。dir から作る8bit角度に足してばらつかせる
  u16 radius;      // 0x2A, (rand >> 3 & 0x7F) + 0x40。gSineTable に掛けて >> 12 したものが base.pos のずれになる
  u16 timer;       // 0x2C, 毎フレーム +1 し 15 で寿命。距離が radius * (0x10 - timer) >> 3 なので中心へ寄っていく
  u8 unk_2e[2];    // 0x2E, padding?
} Entity08080be8Particle;
static_assert(sizeof(Entity08080be8Particle) == 48);

// プレイヤーの周りに粒子を撒きながら当たり判定を出すエフェクト。ENE を消費し、チャージ量で威力と絵が変わる
typedef struct Entity08080be8 {
  Entity e;                           // 0x000, ENTITY_UNK_8
  Player* player;                     // 0x018, Init の第1引数
  AuxSprite sprite;                   // 0x01C
  AuxSpriteGfx gfx;                   // 0x048, SPRITE_210E
  HitboxData hitbox;                  // 0x064, Entity08080be8_SetupHitbox が組み立て、位置は sprite.pos を見る
  Vec3 offset;                        // 0x0B4, FUN_08080204 が offsetRadius から x と z を作り、Entity08080be8_StateImpact が sprite.pos に足す
  u16 heightOffset;                   // 0x0BC, Init の第3引数。FUN_08080204 が sprite.pos.y に足す
  u16 unk_be;                         // 0x0BE, Init の第4引数。FUN_08080204 で gSineTable に掛ける
  u16 unk_c0;                         // 0x0C0, Init の第5引数。unk_be と対で使う
  u16 offsetRadius;                   // 0x0C2, Init の第6引数。offset.x と offset.z の大きさ
  u16 eneCost;                        // 0x0C4, Init の第12引数。Entity08080be8_PayENE が Player_ReduceENE_0807aa60 に渡す
  u8 unk_c6[2];                       // 0x0C6
  u8 dir;                             // 0x0C8, プレイヤーの向きから作る 0..7 の方向。8bit角度の基準になる
  u8 charge;                          // 0x0C9, player の 0xA8F の写し。damage を 1 + charge/2 倍にし、sprite.metaspriteIdx にも入る
  u16 timer;                          // 0x0CA, Entity08080be8_SetState が状態を変えるたび 0 に戻し、各状態が毎フレーム +1 する
  u8 ptclIdx;                         // 0x0CC, 次に撒く ptcls の添字。4 で 0 に戻る
  u8 unk_cd;                          // 0x0CD, Init の第13引数。hitbox のオフセットを変え、0 以外なら damage が 8 固定になる
  u8 unk_ce[2];                       // 0x0CE
  ParticleGroup* group;               // 0x0D0, PTCL_GROUP_2
  Entity08080be8Particle ptcls[4];    // 0x0D4, 根拠: Entity08080be8_SetupParticles / Entity08080be8_ClearParticles / _Destroy の stride 0x30 × 4 のループ
  Entity08080be8Func updateCallback;  // 0x194, _Update が毎フレーム呼ぶ状態関数
} Entity08080be8;
static_assert(sizeof(Entity08080be8) == 408);

void Entity08080be8_StateFly(Entity08080be8* p);
void Entity08080be8_StateImpact(Entity08080be8* p);

// src/player.c
s32 FUN_0806f900(Player* player);
s32 FUN_080d1b04(Player* player);
void Player_ReduceENE_0807aa60(Player* player, s32 amount);

// src/code_082326a0.c
u16 FUN_082328ec(Vec3* pos);

// 状態関数を差し替えて経過フレームを 0 に戻す
void Entity08080be8_SetState(Entity08080be8* p, Entity08080be8Func fn) {
  p->updateCallback = fn;
  p->timer = 0;
}

NAKED void FUN_08080204(Entity08080be8* p) { INCFUNC("asm/func/FUN_08080204.inc"); }

// 撒いた粒子を寿命まで動かす。距離が毎フレーム縮むので中心へ吸い込まれていく
NON_MATCH void Entity08080be8_UpdateParticles(Entity08080be8* p) {
#ifdef NONMATCHING_C
  s32 dirBase = ((p->dir + 5) & 7) * 32;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (p->ptcls[i].active != 0) {
      p->ptcls[i].timer++;
      if (p->ptcls[i].timer > 14) {
        p->ptcls[i].active = 0;
        p->ptcls[i].base.flags |= SPRFLAG_HIDDEN;
      } else {
        s32 dist = p->ptcls[i].radius * (16 - p->ptcls[i].timer) >> 3;
        s32 angle = (dirBase + p->ptcls[i].angleOffset + 0x100) & 0xFF;

        p->ptcls[i].base.pos = p->sprite.pos;
        p->ptcls[i].base.pos.x += dist * gSineTable[(angle + 0x40) & 0xFF] / 4096;
        p->ptcls[i].base.pos.z += dist * gSineTable[angle] / 4096;
      }
    }
  }
#else
  INCFUNC("asm/func/Entity08080be8_UpdateParticles.inc");
#endif
}

NAKED void FUN_080804a0(Entity08080be8* p) { INCFUNC("asm/func/FUN_080804a0.inc"); }

// 撒いた粒子を全部止めて消す
void Entity08080be8_ClearParticles(Entity08080be8* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    p->ptcls[i].active = 0;
    p->ptcls[i].base.flags |= SPRFLAG_HIDDEN;
  }
}

void FUN_08080648(HitboxData* a, HitboxData* b, Entity08080be8* p) { Entity08080be8_SetState(p, Entity08080be8_StateImpact); }

// 発動時に ENE を払う
void Entity08080be8_PayENE(Entity08080be8* p) {
  if (gFlag030047a4 & FLAG030047A4_UNK_11) {
    s32 cost = p->eneCost;

    if (gEntity9A9F != NULL) {
      gEntity9A9F->unk_140 += cost;
    }
  }
  Player_ReduceENE_0807aa60(p->player, p->eneCost);
}

// チャージ量に応じた威力を出す
s32 Entity08080be8_GetDamage(Entity08080be8* p) {
  s32 dmg;

  if (p->unk_cd != 0) {
    return 8;
  }
  if (gFlag030047a4 & FLAG030047A4_UNK_11) {
    dmg = FUN_080d1b04(p->player);
  } else {
    dmg = FUN_0806f900(p->player);
  }
  return dmg + ((dmg * p->charge) >> 1);
}

NAKED void FUN_080806ec(Entity08080be8* p) { INCFUNC("asm/func/FUN_080806ec.inc"); }

// サバタ側の溜め状態。溜め中は粒子を出し、発射で StateFly へ、中断なら消える
NON_MATCH void Entity08080be8_StateChargeSabata(Entity08080be8* p) {
#ifdef NONMATCHING_C
  if (p->player->unk_37c == 3) {
    u8 state;

    FUN_08080204(p);
    state = p->player->unk_37d;
    if (state == 5) {
      Entity08080be8_ClearParticles(p);
      AuxSprite_Show(&p->sprite);
      p->sprite.metaspriteIdx = p->charge + 1;
      p->hitbox.power = Entity08080be8_GetDamage(p);
      Entity08080be8_PayENE(p);
      Entity08080be8_SetState(p, Entity08080be8_StateFly);
      return;
    }
    if (state == 8) {
      Entity08080be8_ClearParticles(p);
      Entity08080be8_PayENE(p);
    } else {
      Entity08080be8_UpdateParticles(p);
      state = p->player->unk_37d;
      if (state == 2) {
        if ((p->timer & 3) == 3) {
          FUN_080804a0(p);
        }
      } else if (state == 3 && (p->timer & 3) == 3) {
        FUN_080804a0(p);
      }
      p->charge = p->player->unk_a8f;
      p->timer++;
      return;
    }
  }
  KillEntity(&p->e);
#else
  INCFUNC("asm/func/Entity08080be8_StateChargeSabata.inc");
#endif
}

// 前へ進めながら当たり判定を出し、地面より下に潜ったら次の状態へ
void Entity08080be8_StateFly(Entity08080be8* p) {
  HitboxData* hitbox;
  Vec3* pos;
  u16 groundY;

  p->sprite.pos.x += p->offset.x;
  p->sprite.pos.z += p->offset.z;
  hitbox = &p->hitbox;
  pos = &p->sprite.pos;
  Hitbox_SetPos(hitbox, pos, 0);
  Hitbox_Register(hitbox);
  Player_SetFlag20(p->player, 0x80002);
  groundY = FUN_082328ec(pos);
  if (groundY > p->sprite.pos.y) {
    Entity08080be8_SetState(p, Entity08080be8_StateImpact);
  } else {
    p->timer++;
    if (p->timer > 59) {
      KillEntity(&p->e);
    }
  }
}

// 着弾の短い演出。4フレーム目に向きに合わせた絵と反転を決め、7フレーム目で消える
NON_MATCH void Entity08080be8_StateImpact(Entity08080be8* p) {
#ifdef NONMATCHING_C
  p->timer++;
  if (p->timer == 1) {
    p->sprite.metaspriteIdx = 4;
    return;
  }
  if (p->timer == 4) {
    s32 dir = p->dir;
    AuxSprite* spr = &p->sprite;

    if (dir & 1) {
      spr->metaspriteIdx = 7;
    } else if ((dir >> 1) & 1) {
      spr->metaspriteIdx = 8;
    } else {
      spr->metaspriteIdx = 6;
    }
    if (dir <= 2) {
      spr->flags &= ~(SPRFLAG_XFLIP | SPRFLAG_YFLIP);
    } else if (dir <= 4) {
      spr->flags = (spr->flags & ~SPRFLAG_XFLIP) | SPRFLAG_YFLIP;
    } else if (dir <= 5) {
      spr->flags |= SPRFLAG_XFLIP | SPRFLAG_YFLIP;
    } else {
      spr->flags = (spr->flags | SPRFLAG_XFLIP) & ~SPRFLAG_YFLIP;
    }
  } else if (p->timer > 6) {
    KillEntity(&p->e);
  }
#else
  INCFUNC("asm/func/Entity08080be8_StateImpact.inc");
#endif
}

s32 Entity08080be8_Update(Entity08080be8* p) {
  p->updateCallback(p);
  return 0;
}

s32 Entity08080be8_Destroy(Entity08080be8* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);
  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->ptcls[i].base);
  }
  return 0;
}

// スプライトを用意して隠したまま登録する
void Entity08080be8_SetupSprite(Entity08080be8* p, s32 plttID) {
  AuxSpriteGfx* gfx = &p->gfx;

  Video_GetAuxSprite(gfx, SPRITE_210E);
  AuxSprite_Add(&p->sprite, gfx, SPRFLAG_HIDDEN);
  AuxSprite_SetPoseIdx(&p->sprite, 0);
  Video_SetAuxSpritePltt(gfx, plttID);
}

// 当たり判定を組み立てる。unk_cd が立っているときだけ判定を一段高い位置に置く
void Entity08080be8_SetupHitbox(Entity08080be8* p, u32 hitboxUnk40, u32 attributes, u32 hitboxUnk44) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 offset;
  Vec3 halfSize;

  halfSize.x = 30, halfSize.y = 30, halfSize.z = 30;
  if (p->unk_cd != 0) {
    offset.x = 0, offset.y = 30, offset.z = 0;
  } else {
    offset.x = 0, offset.y = 0, offset.z = 0;
  }
  Hitbox_Init(hitbox, 0, HBFLAG_UNK_13 | HBFLAG_UNK_8 | HBFLAG_UNK_0, 0, 1 << p->player->unk_24.unk_4, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, 0, hitboxUnk40, 0x10, attributes, hitboxUnk44);
  Hitbox_SetHandler(hitbox, FUN_08080648, p);
  Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
}

// 撒く粒子4個をまとめて用意する
void Entity08080be8_SetupParticles(Entity08080be8* p, s32 val) {
  s32 i;

  p->ptclIdx = 0;
  p->group = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 4; i++) {
    FUN_0822d9f0(&p->ptcls[i].base, p->group, SPRFLAG_HIDDEN);
    Particle_SetOffset(&p->ptcls[i].base, -4, -4);
    FUN_0822dafc(&p->ptcls[i].base, p->group, val);
    FUN_0822dadc(&p->ptcls[i].base, 1);
    p->ptcls[i].active = 0;
  }
}

s32 Entity08080be8_Init(Entity08080be8* p, Player* player, u32 heightOffset, u32 unk_be, u32 unk_c0, u32 offsetRadius, u32 plttID, u32 hitboxUnk40, u32 attributes, u32 hitboxUnk44, u32 ptclVal, u32 eneCost, u32 unk_cd) {
  p->player = player;
  p->heightOffset = heightOffset;
  p->unk_be = unk_be;
  p->unk_c0 = unk_c0;
  p->offsetRadius = offsetRadius;
  p->eneCost = eneCost;
  p->charge = 0;
  p->unk_cd = unk_cd;
  Entity08080be8_SetupSprite(p, plttID);
  Entity08080be8_SetupHitbox(p, hitboxUnk40, attributes, hitboxUnk44);
  FUN_08080204(p);
  Entity08080be8_SetupParticles(p, ptclVal);
  if (p->player->kind != PLAYER_SABATA) {
    Entity08080be8_SetState(p, FUN_080806ec);
  } else {
    Entity08080be8_SetState(p, Entity08080be8_StateChargeSabata);
  }
  return 0;
}

Entity08080be8* Entity08080be8_Create(Player* player, u32 heightOffset, u32 unk_be, u32 unk_c0, u32 offsetRadius, u32 plttID, u32 hitboxUnk40, u32 attributes, u32 hitboxUnk44, u32 ptclVal, u32 eneCost, u32 unk_cd) {
  Entity08080be8* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity08080be8));

  if (p != NULL) {
    SetEntityRoutine(p, Entity08080be8_Update, Entity08080be8_Destroy);
    if (Entity08080be8_Init(p, player, heightOffset, unk_be, unk_c0, offsetRadius, plttID, hitboxUnk40, attributes, hitboxUnk44, ptclVal, eneCost, unk_cd) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
