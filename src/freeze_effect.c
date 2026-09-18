#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "random.h"
#include "sound.h"

// FreezeEffect が中心の粒子の周りに出して、中心へ集めていく粒子
typedef struct {
  Particle base;  // 0x00, 根拠: FreezeEffect_InitSubParticles
  u8 q_active;    // 0x28, 0 以外なら FreezeEffect_GatherSubParticles が中心へ近づける
  u8 q_frame;     // 0x29, FreezeEffect_GatherSubParticles で加算, 4 で見た目を切り替え, 6 で消える
  u8 unk_2a[2];
} q_FreezeParticle;
static_assert(sizeof(q_FreezeParticle) == 44);  // 根拠: FreezeEffect_InitSubParticles と FreezeEffect_Destroy のストライド 0x2C

// 魔法"フリーズ"で生成される氷のエフェクト
// 2フレームごとに subPtcls を中心の周りに出して中心へ集め、32フレーム後に FreezeEffect_StateVanish に移って消える
typedef struct {
  Entity e;                      // 0x00, ENTITY_UNK_8
  Vec3 pos;                      // 0x18, 根拠: FreezeEffect_Init
  HitboxData hitbox;             // 0x20, 根拠: FreezeEffect_InitHitbox
  Particle ptcl;                 // 0x70, 中心の粒子, 根拠: FreezeEffect_InitCenterParticle
  ParticleGroup* ptclGroup;      // 0x98, GetParticleGroup(GROUP_0), 根拠: FreezeEffect_InitCenterParticle
  ParticleGroup* subPtclGroup;   // 0x9C, GetParticleGroup(GROUP_2), 根拠: FreezeEffect_InitSubParticles
  q_FreezeParticle subPtcls[8];  // 0xA0, 根拠: FreezeEffect_InitSubParticles
  u8 q_spawnIdx;                 // 0x200, 次に出す subPtcls の添字, 8 で折り返す, 根拠: FreezeEffect_SpawnSubParticle
  u8 q_spawnTimer;               // 0x201, subPtcls を出す間隔のカウンタ, 根拠: FreezeEffect_SpawnSubParticle
  u16 unk_202;                   // 0x202, FreezeEffect_Init で 0
  u16 unk_204;                   // 0x204, FreezeEffect_Create の第5引数 (MagicFreeze_08069710 は 90)
  u16 q_stateTimer;              // 0x206, 状態を切り替えると 0 に戻る, 根拠: FreezeEffect_SetState / FreezeEffect_StateGather
  void* fn_208;                  // 0x208, 現在の状態関数, 根拠: FreezeEffect_SetState
} FreezeEffect;
static_assert(sizeof(FreezeEffect) == 524);

void FUN_0822dafc(Particle* p, ParticleGroup* g, u32 val);

void FreezeEffect_StateVanish(FreezeEffect* p);

void FreezeEffect_SetState(FreezeEffect* p, void* fn) {
  p->fn_208 = fn;
  p->q_stateTimer = 0;
}

// 出ている周りの粒子を中心の粒子へ近づけ、6 フレームで消す
void FreezeEffect_GatherSubParticles(FreezeEffect* p) {
  s32 i;
  s32 n, d;

  for (i = 0; i < 8; i++) {
    if (p->subPtcls[i].q_active) {
      if (++p->subPtcls[i].q_frame > 5) {
        p->subPtcls[i].base.flags |= 1;
        p->subPtcls[i].q_active = 0;
      } else {
        n = 8 - p->subPtcls[i].q_frame;
        d = n + 1;
        p->subPtcls[i].base.pos.x = Div(p->subPtcls[i].base.pos.x * n + p->ptcl.pos.x, d);
        p->subPtcls[i].base.pos.y = Div(p->subPtcls[i].base.pos.y * n + p->ptcl.pos.y, d);
        p->subPtcls[i].base.pos.z = Div(p->subPtcls[i].base.pos.z * n + p->ptcl.pos.z, d);
        if (p->subPtcls[i].q_frame == 4) {
          FUN_0822dafc(&p->subPtcls[i].base, p->subPtclGroup, 9);
        }
      }
    }
  }
}

// 2 フレームごとに、周りの粒子を1つ中心から ±127 のランダムな位置に出す
NON_MATCH void FreezeEffect_SpawnSubParticle(FreezeEffect* p) {
#ifdef NONMATCHING_C
  u16* table;
  u32 idx;

  if (++p->q_spawnTimer > 1) {
    p->subPtcls[p->q_spawnIdx].base.flags &= ~1;
    p->subPtcls[p->q_spawnIdx].base.pos = p->ptcl.pos;
    table = gRandomTable;
    idx = (gRandTableIdx + 1) & 0x3FF;
    p->subPtcls[p->q_spawnIdx].base.pos.x += (u8)table[idx] - 127;
    idx = (idx + 1) & 0x3FF;
    p->subPtcls[p->q_spawnIdx].base.pos.y += (u8)table[idx] - 127;
    gRandTableIdx = (idx + 1) & 0x3FF;
    p->subPtcls[p->q_spawnIdx].base.pos.z += (u8)table[gRandTableIdx] - 127;
    p->subPtcls[p->q_spawnIdx].q_active = 1;
    p->subPtcls[p->q_spawnIdx].q_frame = 0;
    if (++p->q_spawnIdx > 7) {
      p->q_spawnIdx = 0;
    }
    p->q_spawnTimer = 0;
  }
#else
  INCFUNC("asm/func/FreezeEffect_SpawnSubParticle.inc");
#endif
}

// 粒子を集める状態: 32 フレーム経ったら中心の粒子を表示して FreezeEffect_StateVanish に移る
void FreezeEffect_StateGather(FreezeEffect* p) {
  FreezeEffect_GatherSubParticles(p);
  FreezeEffect_SpawnSubParticle(p);
  if (++p->q_stateTimer > 31) {
    p->ptcl.flags &= ~1;
    PlaySound_082406e0(0x133);
    FreezeEffect_SetState(p, FreezeEffect_StateVanish);
  }
}

void FUN_08014730(s32 param_1, s32 param_2, Vec3* pos, Vec3* spread, Vec3* speed, s32 param_6, s32 param_7);

// 消える状態: 中心の粒子が床より上にあれば氷の破片を散らしてから消える
NON_MATCH void FreezeEffect_StateVanish(FreezeEffect* p) {
#ifdef NONMATCHING_C
  Vec3* pos;
  s32 y;
  s32 bx, bz, idx;
  u8* tile;
  u32 attr, kind, h;
  u16* table;
  u32 ridx;
  u16 r;
  Vec3 spread, speed;

  FreezeEffect_GatherSubParticles(p);
  FUN_08236400(&p->hitbox);
  if (++p->q_stateTimer > 15) {
    y = p->ptcl.pos.y;
    pos = &p->pos;
    bx = pos->x >> 8;
    bz = pos->z >> 8;
    if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
      idx = 0;
    } else {
      idx = gCollisionMap->q_rowOffsets[bz] + bx;
    }
    tile = (u8*)FUN_08234224(idx, 1);
    if (tile != NULL) {
      tile += 4;
    } else {
      tile = (u8*)&gCollisionMap->tiledata->tiles[idx];
    }
    attr = *tile;
    kind = attr >> 4;
    h = (attr & 0xF) << 8;
    switch (kind) {
      case 1: {
        h -= (u8)pos->z;
        break;
      }
      case 2: {
        h -= (u8)pos->x;
        break;
      }
    }
    if (y > h) {
      table = gRandomTable;
      ridx = (gRandTableIdx + 1) & 0x3FF;
      r = table[ridx];
      spread.x = (r & 0xF) - 7;
      ridx = (ridx + 1) & 0x3FF;
      r = table[ridx];
      spread.y = (r & 0x1F) - 16;
      gRandTableIdx = (ridx + 1) & 0x3FF;
      r = table[gRandTableIdx];
      spread.z = (r & 0xF) - 7;
      speed.x = 5;
      speed.y = 10;
      speed.z = 5;
      FUN_08014730(4, 2, &p->ptcl.pos, &spread, &speed, 60, 60);
    }
    KillEntity((Entity*)p);
  }
#else
  INCFUNC("asm/func/FreezeEffect_StateVanish.inc");
#endif
}

s32 FreezeEffect_Update(FreezeEffect* p) {
  ((void (*)(FreezeEffect*))p->fn_208)(p);
  return 0;
}

s32 FreezeEffect_Destroy(FreezeEffect* p) {
  s32 i;

  FUN_0822dabc(&p->ptcl);
  for (i = 0; i < 8; i++) {
    FUN_0822dabc(&p->subPtcls[i].base);
  }
  return 0;
}

// 当たり判定を設定する
void FreezeEffect_InitHitbox(FreezeEffect* p, s32 param_2, s32 param_3, s32 param_4) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 size, offset;

  size.x = 100;
  size.y = 100;
  size.z = 100;
  offset.x = 0;
  offset.y = 0;
  offset.z = 0;
  FUN_0823646c(hitbox, 0, 0x2100, 0, param_2, &size, &offset);
  FUN_082364f8(hitbox, param_3, 0, 0x4000, 0, 0);
  hitbox->unk_42 = param_4;
  FUN_0823651c(hitbox, NULL, p);
  FUN_082364c4(hitbox, &p->ptcl.pos, 0);
}

// 中心の粒子を作る (最初は非表示, FreezeEffect_StateGather で表示される)
void FreezeEffect_InitCenterParticle(FreezeEffect* p) {
  Particle* ptcl = &p->ptcl;

  p->ptclGroup = GetParticleGroup(PTCL_GROUP_0);
  FUN_0822d9f0(ptcl, p->ptclGroup, 1);
  FUN_0822dad4(ptcl, -8, -8);
  FUN_0822dafc(ptcl, p->ptclGroup, 10);
  ptcl->pos = p->pos;
  ptcl->pos.y += 0xD7;
  ptcl->priority = 1;
  ptcl->q_zOffset = 20;
}

// 周りに出す 8 個の粒子を作る
void FreezeEffect_InitSubParticles(FreezeEffect* p) {
  s32 i;

  p->subPtclGroup = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 8; i++) {
    Particle* ptcl = &p->subPtcls[i].base;
    FUN_0822d9f0(ptcl, p->subPtclGroup, 1);
    FUN_0822dad4(ptcl, -4, -4);
    FUN_0822dafc(ptcl, p->subPtclGroup, 8);
    FUN_0822dadc(ptcl, 1);
    ptcl->priority = 2;
    ptcl->q_zOffset = 0xEC;
    p->subPtcls[i].q_active = 0;
    p->subPtcls[i].q_frame = 0;
  }
}

s32 FreezeEffect_Init(FreezeEffect* p, Vec3* pos, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
  p->pos = *pos;
  FreezeEffect_InitCenterParticle(p);
  FreezeEffect_InitSubParticles(p);
  FreezeEffect_InitHitbox(p, param_3, param_4, param_5);
  p->unk_202 = 0;
  p->unk_204 = param_6;
  PlaySound_082406e0(0x398);
  FreezeEffect_SetState(p, FreezeEffect_StateGather);
  return 0;
}

FreezeEffect* FreezeEffect_Create(Vec3* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5) {
  FreezeEffect* p = CreateEntity(ENTITY_UNK_8, sizeof(FreezeEffect));
  if (p != NULL) {
    SetEntityRoutine(p, FreezeEffect_Update, FreezeEffect_Destroy);
    if (FreezeEffect_Init(p, pos, param_2, param_3, param_4, param_5) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
