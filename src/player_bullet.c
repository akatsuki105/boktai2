#include "collision_map.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sprite.h"

// チャージ時のパーティクル
typedef struct {
  Particle base;   // 0x00, Particle_Add や Particle_Remove に Particle* として渡る
  bool8 active;    // 0x28, Bullet_SpawnParticle が 1 にし、Bullet_UpdateParticles が寿命で 0 に戻す, 0 の間は動かさない
  s8 angleOffset;  // 0x29, Mod(rand, 0x60) - 0x30, dir から作る8bit角度に足してばらつかせる
  u16 radius;      // 0x2A, (rand >> 3 & 0x7F) + 0x40, gSineTable に掛けて >> 12 したものが base.pos のずれになる
  u16 timer;       // 0x2C, 毎フレーム +1 し 15 で寿命, 距離が radius * (0x10 - timer) >> 3 なので中心へ寄っていく
  u8 unk_2e[2];    // 0x2E, padding?
} BulletChargePtcl;
static_assert(sizeof(BulletChargePtcl) == 48);

// プレイヤーの使う銃(ガンデルソル,ガンデルヘル,ロックバスター)の弾丸(弾丸は物理的なものではなくエネルギー弾)
typedef struct Bullet {
  Entity e;                                // 0x000, ENTITY_UNK_8
  Player* player;                          // 0x018, Init の第1引数
  AuxSprite sprite;                        // 0x01C
  AuxSpriteGfx gfx;                        // 0x048, SPRITE_EBALL_210E
  HitboxData hitbox;                       // 0x064, Bullet_SetupHitbox が組み立て、位置は sprite.pos を見る
  Vec3 offset;                             // 0x0B4, Bullet_Reposition が offsetRadius から x と z を作り、Bullet_StateImpact が sprite.pos に足す
  u16 heightOffset;                        // 0x0BC, Init の第3引数, Bullet_Reposition が sprite.pos.y に足す
  u16 unk_be;                              // 0x0BE, Init の第4引数, Bullet_Reposition で gSineTable に掛ける
  u16 unk_c0;                              // 0x0C0, Init の第5引数, unk_be と対で使う
  u16 offsetRadius;                        // 0x0C2, Init の第6引数, offset.x と offset.z の大きさ
  u16 eneCost;                             // 0x0C4, Init の第12引数, Bullet_PayENE が Player_ReduceENE に渡す
  u8 unk_c6[2];                            // 0x0C6
  DirU8 dir;                               // 0x0C8, プレイヤーの向きから作る 0..7 の方向, 8bit角度の基準になる
  u8 charge;                               // 0x0C9, player の 0xA8F の写し, damage を 1 + charge/2 倍にし、sprite.poseIdx にも入る
  u16 timer;                               // 0x0CA, Bullet_SetState が状態を変えるたび 0 に戻し、各状態が毎フレーム +1 する
  u8 ptclIdx;                              // 0x0CC, 次に撒く ptcls の添字, 4 で 0 に戻る
  u8 unk_cd;                               // 0x0CD, Init の第13引数, hitbox のオフセットを変え、0 以外なら damage が 8 固定になる
  u8 unk_ce[2];                            // 0x0CE, padding?
  ParticleGroup* group2;                   // 0x0D0, PTCL_GROUP_2
  BulletChargePtcl ptcls[4];               // 0x0D4, チャージ時のパーティクル
  void (*updateCallback)(struct Bullet*);  // 0x194
} Bullet;
static_assert(sizeof(Bullet) == 408);

void Bullet_StateFly(Bullet* p);
void Bullet_StateImpact(Bullet* p);

// 状態関数を差し替えて経過フレームを 0 に戻す
void Bullet_SetState(Bullet* p, void* fn) {
  p->updateCallback = fn;
  p->timer = 0;
}

// プレイヤーの位置と向きから、スプライト・当たり判定・毎フレームの進み幅を作り直す
// 残差は末尾の 0xFF 定数の生成位置と dir 計算のレジスタ割り当てのみ, 末尾の offset は 表 * offsetRadius の順 (POLAR_X/POLAR_Z は順が逆で不可)
// dir を ((angle & 0xFF) / 32 + 3) & 7 にすると 0xFF の位置まで一致し残差は ands r1, r0 の1命令 (原典はマスク付きのマクロかも), Tier A-B は試済, 未: Tier C
NON_MATCH void Bullet_Reposition(Bullet* p) {
#ifdef NONMATCHING_C
  Player* player = p->player;
  u32 angle;
  s32 cosv;
  s32 sinv;

  p->sprite.pos = player->mover.pos;
  p->sprite.pos.y += p->heightOffset;
  angle = ((player->facing + 5) & 7) * 32;
  cosv = COS(angle);
  sinv = SIN(angle);
  if (player->xflip) {
    p->sprite.pos.x += FixToInt(12, cosv * p->unk_be) + FixToInt(12, sinv * p->unk_c0);
    p->sprite.pos.z += FixToInt(12, sinv * p->unk_be) - FixToInt(12, cosv * p->unk_c0);
  } else {
    p->sprite.pos.x += FixToInt(12, cosv * p->unk_be) - FixToInt(12, sinv * p->unk_c0);
    p->sprite.pos.z += FixToInt(12, sinv * p->unk_be) + FixToInt(12, cosv * p->unk_c0);
  }
  p->dir = (angle / 32 + 3) & 7;
  p->offset.x = FixToInt(12, COS(angle) * p->offsetRadius);
  p->offset.z = FixToInt(12, SIN(angle) * p->offsetRadius);
  p->hitbox.angle = angle;
#else
  INCFUNC("asm/func/Bullet_Reposition.inc");
#endif
}

// 撒いた粒子を寿命まで動かす, 距離が毎フレーム縮むので中心へ吸い込まれていく
NON_MATCH void Bullet_UpdateParticles(Bullet* p) {
#ifdef NONMATCHING_C
  s32 dirBase = ((p->dir + 5) & 7) * 32;
  s32 i;

  for (i = 0; i < 4; i++) {
    if (p->ptcls[i].active) {
      p->ptcls[i].timer++;
      if (p->ptcls[i].timer > 14) {
        p->ptcls[i].active = FALSE;
        p->ptcls[i].base.flags |= SPRFLAG_HIDDEN;
      } else {
        s32 dist = p->ptcls[i].radius * (16 - p->ptcls[i].timer) >> 3;
        s32 angle = (dirBase + p->ptcls[i].angleOffset + 0x100) & 0xFF;

        p->ptcls[i].base.pos = p->sprite.pos;
        p->ptcls[i].base.pos.x += dist * COS(angle) / 4096;
        p->ptcls[i].base.pos.z += dist * gSineTable[angle] / 4096;
      }
    }
  }
#else
  INCFUNC("asm/func/Bullet_UpdateParticles.inc");
#endif
}

// 粒子を1個、向きと距離をばらつかせて撒く
NON_MATCH void Bullet_SpawnParticle(Bullet* p) {
#ifdef NONMATCHING_C
  s32 angle;

  p->ptcls[p->ptclIdx].active = TRUE;
  p->ptcls[p->ptclIdx].base.flags &= ~SPRFLAG_HIDDEN;
  p->ptcls[p->ptclIdx].timer = 0;
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  p->ptcls[p->ptclIdx].radius = ((gRandomTable[gRandTableIdx] >> 3) & 0x7F) + 0x40;
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  p->ptcls[p->ptclIdx].angleOffset = Mod(gRandomTable[gRandTableIdx], 0x60) - 0x30;
  angle = (((p->dir + 5) & 7) * 32 + p->ptcls[p->ptclIdx].angleOffset + 0x100) & 0xFF;
  p->ptcls[p->ptclIdx].base.pos = p->sprite.pos;
  p->ptcls[p->ptclIdx].base.pos.x += p->ptcls[p->ptclIdx].radius * COS(angle) / 4096;
  p->ptcls[p->ptclIdx].base.pos.z += p->ptcls[p->ptclIdx].radius * gSineTable[angle] / 4096;
  p->ptclIdx++;
  if (p->ptclIdx > 3) {
    p->ptclIdx = 0;
  }
#else
  INCFUNC("asm/func/Bullet_SpawnParticle.inc");
#endif
}

// 撒いた粒子を全部止めて消す
void Bullet_ClearParticles(Bullet* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    p->ptcls[i].active = FALSE;
    p->ptcls[i].base.flags |= SPRFLAG_HIDDEN;
  }
}

void Bullet_OnHit(HitboxData* a, HitboxData* b, Bullet* p) { Bullet_SetState(p, Bullet_StateImpact); }

// 発射時に ENE を払う
void Bullet_PayENE(Bullet* p) {
  if (gGameFlags & GAMEFLAG_LINK) {
    s32 cost = p->eneCost;

    if (gEntity9A9F != NULL) {
      gEntity9A9F->unk_140 += cost;
    }
  }
  Player_ReduceENE(p->player, p->eneCost);
}

// チャージ量に応じた威力を出す
s32 Bullet_GetDamage(Bullet* p) {
  s32 dmg;

  if (p->unk_cd != 0) {
    return 8;
  }
  if (gGameFlags & GAMEFLAG_LINK) {
    dmg = FUN_080d1b04(p->player);
  } else {
    dmg = FUN_0806f900(p->player);
  }
  return dmg + ((dmg * p->charge) >> 1);
}

// ジャンゴ側の溜め状態, 溜め中は粒子を出しつつ4フレームおきに絵を切り替え、発射で StateFly へ
NON_MATCH void Bullet_StateChargeDjango(Bullet* p) {
#ifdef NONMATCHING_C
  u8 state;

  if (p->player->action != PACT_ATTACK) {
    KillEntity(&p->e);
    return;
  }
  Bullet_Reposition(p);
  if (p->player->state == 5) {
    Bullet_ClearParticles(p);
    AuxSprite_Show(&p->sprite);
    p->sprite.poseIdx = p->charge;
    p->hitbox.power = Bullet_GetDamage(p);
    Bullet_PayENE(p);
    Bullet_SetState(p, Bullet_StateFly);
    return;
  }
  Bullet_UpdateParticles(p);
  state = p->player->state;
  if (state == 2) {
    if ((p->timer & 3) == 3) {
      Bullet_SpawnParticle(p);
    }
  } else if (state == 3) {
    AuxSprite_Show(&p->sprite);
    if ((p->timer & 3) == 3) {
      Bullet_SpawnParticle(p);
    }
  } else if (p->charge != 0) {
    AuxSprite_Show(&p->sprite);
  }
  p->charge = p->player->wpn.charge;
  p->sprite.poseIdx = ((p->timer >> 2) & 1) ? p->charge + 1 : p->charge;
  p->timer++;
#else
  INCFUNC("asm/func/Bullet_StateChargeDjango.inc");
#endif
}

// サバタ側の溜め状態, 溜め中は粒子を出し、発射で StateFly へ、中断なら消える
NON_MATCH void Bullet_StateChargeSabata(Bullet* p) {
#ifdef NONMATCHING_C
  if (p->player->action == PACT_ATTACK) {
    u8 state;

    Bullet_Reposition(p);
    state = p->player->state;
    if (state == 5) {
      Bullet_ClearParticles(p);
      AuxSprite_Show(&p->sprite);
      p->sprite.poseIdx = p->charge + 1;
      p->hitbox.power = Bullet_GetDamage(p);
      Bullet_PayENE(p);
      Bullet_SetState(p, Bullet_StateFly);
      return;
    }
    if (state == 8) {
      Bullet_ClearParticles(p);
      Bullet_PayENE(p);
    } else {
      Bullet_UpdateParticles(p);
      state = p->player->state;
      if (state == 2) {
        if ((p->timer & 3) == 3) {
          Bullet_SpawnParticle(p);
        }
      } else if (state == 3 && (p->timer & 3) == 3) {
        Bullet_SpawnParticle(p);
      }
      p->charge = p->player->wpn.charge;
      p->timer++;
      return;
    }
  }
  KillEntity(&p->e);
#else
  INCFUNC("asm/func/Bullet_StateChargeSabata.inc");
#endif
}

// 前へ進めながら当たり判定を出し、地面より下に潜ったら次の状態へ
void Bullet_StateFly(Bullet* p) {
  p->sprite.pos.x += p->offset.x;
  p->sprite.pos.z += p->offset.z;
  Hitbox_SetPos(&p->hitbox, &p->sprite.pos, 0);
  Hitbox_Register(&p->hitbox);

  Player_SetFlag20(p->player, PFLAG20_UNK_19 | PFLAG20_UNK_1);

  if (Map_GetTileHeightAt(&p->sprite.pos) > p->sprite.pos.y) {
    Bullet_SetState(p, Bullet_StateImpact);
  } else {
    if (++p->timer >= 60) {
      KillEntity(&p->e);
    }
  }
}

// 着弾の短い演出, 4フレーム目に向きに合わせた絵と反転を決め、7フレーム目で消える
NON_MATCH void Bullet_StateImpact(Bullet* p) {
#ifdef NONMATCHING_C
  p->timer++;
  if (p->timer == 1) {
    p->sprite.poseIdx = 4;
    return;
  }
  if (p->timer == 4) {
    s32 dir = p->dir;
    AuxSprite* spr = &p->sprite;

    if (dir & 1) {
      spr->poseIdx = 7;
    } else if ((dir >> 1) & 1) {
      spr->poseIdx = 8;
    } else {
      spr->poseIdx = 6;
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
  INCFUNC("asm/func/Bullet_StateImpact.inc");
#endif
}

s32 Bullet_Update(Bullet* p) {
  p->updateCallback(p);
  return 0;
}

s32 Bullet_Destroy(Bullet* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);
  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->ptcls[i].base);
  }
  return 0;
}

// スプライトを用意して隠したまま登録する
void Bullet_SetupSprite(Bullet* p, s32 plttID) {
  Video_GetAuxSprite(&p->gfx, SPRITE_EBALL_210E);
  AuxSprite_Add(&p->sprite, &p->gfx, SPRFLAG_HIDDEN);
  AuxSprite_SetPoseIdx(&p->sprite, 0);
  Video_SetAuxSpritePltt(&p->gfx, plttID);
}

// 当たり判定を組み立てる, unk_cd が立っているときだけ判定を一段高い位置に置く
void Bullet_SetupHitbox(Bullet* p, u32 knockback, HitboxAttributes attrs, u32 iframes) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 offset, halfSize;

  VEC3_SET(halfSize, Q8(0.12), Q8(0.12), Q8(0.12));
  if (p->unk_cd != 0) {
    VEC3_SET(offset, 0, Q8(0.12), 0);
  } else {
    VEC3_SET(offset, 0, 0, 0);
  }
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, 1 << p->player->mover.unk_4, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, 0, knockback, 1 << WK_GUN, attrs, iframes);
  Hitbox_SetHandler(hitbox, Bullet_OnHit, p);
  Hitbox_SetPos(hitbox, &p->sprite.pos, 0);
}

// 撒く粒子4個をまとめて用意する
void Bullet_SetupParticles(Bullet* p, s32 pose) {
  s32 i;

  p->ptclIdx = 0;
  p->group2 = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 4; i++) {
    Particle_Add(&p->ptcls[i].base, p->group2, SPRFLAG_HIDDEN);
    Particle_SetOffset(&p->ptcls[i].base, -4, -4);
    Particle_SetPose(&p->ptcls[i].base, p->group2, pose);
    Particle_SetPltt(&p->ptcls[i].base, 1);
    p->ptcls[i].active = FALSE;
  }
}

s32 Bullet_Init(Bullet* p, Player* player, u32 heightOffset, u32 unk_be, u32 unk_c0, u32 offsetRadius, u32 plttID, u32 knockback, HitboxAttributes attrs, u32 iframes, u32 pose, u32 cost, u32 unk_cd) {
  p->player = player;
  p->heightOffset = heightOffset;
  p->unk_be = unk_be;
  p->unk_c0 = unk_c0;
  p->offsetRadius = offsetRadius;
  p->eneCost = cost;
  p->charge = 0;
  p->unk_cd = unk_cd;
  Bullet_SetupSprite(p, plttID);
  Bullet_SetupHitbox(p, knockback, attrs, iframes);
  Bullet_Reposition(p);
  Bullet_SetupParticles(p, pose);
  if (p->player->kind != PLAYER_SABATA) {
    Bullet_SetState(p, Bullet_StateChargeDjango);
  } else {
    Bullet_SetState(p, Bullet_StateChargeSabata);
  }
  return 0;
}

Bullet* Bullet_Create(Player* player, u32 heightOffset, u32 unk_be, u32 unk_c0, u32 offsetRadius, u32 plttID, u32 knockback, HitboxAttributes attrs, u32 iframes, u32 pose, u32 cost, u32 unk_cd) {
  Bullet* p = CreateEntity(ENTITY_UNK_8, sizeof(Bullet));

  if (p != NULL) {
    SetEntityRoutine(p, Bullet_Update, Bullet_Destroy);
    if (Bullet_Init(p, player, heightOffset, unk_be, unk_c0, offsetRadius, plttID, knockback, attrs, iframes, pose, cost, unk_cd) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
