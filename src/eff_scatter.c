#include "eff_scatter.h"

#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "particle.h"
#include "random.h"
#include "vm.h"

// 飛び散って消える粒子1個, 速度と重力で動き、寿命が来ると消える
typedef struct {
  bool8 active;   // 0x00, 0 なら処理しない, 寿命が来ると 0 にして Particle_Remove で描画リストから外す
  u8 unk_01;      // 0x01, ScatterEffect_Spawn で 1, 読む箇所なし
  u8 age;         // 0x02, 毎フレーム +1, lifetime を超えたら消える
  u8 lifetime;    // 0x03, ScatterEffect_Spawn で lifeBase + (rand & lifeRandMask)
  u16 mapIdx;     // 0x04, 当たり判定マップのブロック番号, ScatterEffect_UpdateBouncing が前フレームの値と比べて跳ね返る向きを決める
  s16 height;     // 0x06, 毎フレーム velY を加算, 床の高さと比較
  Vec3 vel;       // 0x08, 速度
  Particle ptcl;  // 0x10
} ScatterParticle;
static_assert(sizeof(ScatterParticle) == 56);

// ScatterEffect_Spawn で一度に出す粒子のまとまり
typedef struct {
  bool8 active;              // 0x00, Update が 0 以外のときだけ処理, ScatterEffect_Spawn が空きを探して 1, 全粒子が消えると 0
  u8 count;                  // 0x01, 使う ptcls の数, ScatterEffect_Spawn で最大 8
  u8 kind;                   // 0x02, 9 未満なら ScatterEffect_UpdateBouncing (床で跳ねる), 0x15 未満なら group1, sScatterTileOffsets の添字
  u8 priority;               // 0x03, 各 ptcl.priority にコピー, ScatterEffect_Spawn の kind >> 8 から 1 引いた値 (0 以下なら 2)
  ScatterParticle ptcls[8];  // 0x04
} ScatterBurst;
static_assert(sizeof(ScatterBurst) == 452);

// 物が壊れたり叩かれたりしたときの破片を撒き散らすエフェクト, ScatterEffect_Spawn / ScatterEffect_SpawnAtAngle で撒き, 1つだけ作られる
typedef struct {
  Entity e;                // 0x0, ENTITY_UNK_10
  u32 frameCount;          // 0x18, Update で毎フレーム +1, bit0 で床の影と本体を交互に描く (ScatterEffect_UpdateBouncing / ScatterEffect_UpdatePaused)
  ParticleGroup* group1;   // 0x1C, PTCL_GROUP_1
  ParticleGroup* group2;   // 0x20, PTCL_GROUP_2
  ScatterBurst bursts[6];  // 0x24
} ScatterEffect;
static_assert(sizeof(ScatterEffect) == 2748);

static ScatterEffect* sScatterEffect;  // 0x03000058

// kind ごとの粒子のタイル番号のずれ, SCATTER_SHADOW は床に描く影
const u32 sScatterTileOffsets[40] = {
    [SCATTER_KIND_0] = PTCL1_0,
    [SCATTER_KIND_1] = PTCL1_0,
    [SCATTER_ICE] = PTCL1_ICE,
    [SCATTER_STONE] = PTCL1_STONE,
    [SCATTER_CLAY] = PTCL1_CLAY,
    [SCATTER_KIND_5] = PTCL1_12,
    [SCATTER_KIND_6] = PTCL1_13,
    [SCATTER_KIND_7] = PTCL1_14,
    [SCATTER_CONFUSE] = PTCL1_CONFUSE,
    [SCATTER_KIND_9] = PTCL1_28,
    [SCATTER_KIND_10] = PTCL1_19,
    [SCATTER_KIND_11] = PTCL1_20,
    [SCATTER_KIND_12] = PTCL1_21,
    [SCATTER_KIND_13] = PTCL1_22,
    [SCATTER_KIND_14] = PTCL1_23,
    [SCATTER_KIND_15] = PTCL1_24,
    [SCATTER_KIND_16] = PTCL1_25,
    [SCATTER_KIND_17] = PTCL1_26,
    [SCATTER_KIND_18] = PTCL1_18,
    [SCATTER_KIND_19] = PTCL1_17,
    [SCATTER_KIND_20] = PTCL1_27,
    //
    [SCATTER_KIND_21] = PTCL2_0,
    [SCATTER_KIND_22] = PTCL2_1,
    [SCATTER_SOL_L] = PTCL2_SOL_L,
    [SCATTER_SOL_S] = PTCL2_SOL_S,
    [SCATTER_DARK_L] = PTCL2_DARK_L,
    [SCATTER_DARK_S] = PTCL2_DARK_S,
    [SCATTER_FLAME_L] = PTCL2_FLAME_L,
    [SCATTER_FLAME_S] = PTCL2_FLAME_S,
    [SCATTER_FROST_L] = PTCL2_FROST_L,
    [SCATTER_FROST_S] = PTCL2_FROST_S,
    [SCATTER_CLOUD_L] = PTCL2_CLOUD_L,
    [SCATTER_CLOUD_S] = PTCL2_CLOUD_S,
    [SCATTER_EARTH_L] = PTCL2_EARTH_L,
    [SCATTER_EARTH_S] = PTCL2_EARTH_S,
    [SCATTER_KIND_35] = PTCL2_14,
    [SCATTER_KIND_36] = PTCL2_15,
    [SCATTER_KIND_37] = PTCL2_DARK_S,
    [SCATTER_KIND_38] = PTCL2_18,
    //
    [SCATTER_SHADOW] = PTCL1_10,
};  // 0x085AA850

void ScatterEffect_ClearGlobal(void) { sScatterEffect = NULL; }

// kind 9 以上の粒子の更新, 床を見ずに速度と重力だけで飛び、寿命が来たものから消える
NON_MATCH void ScatterEffect_UpdateFlying(ScatterEffect* p, ScatterBurst* data) {
#ifdef NONMATCHING_C
  ParticleGroup* group;
  s32 alive;
  s32 i;

  alive = 0;
  for (i = 0; i < data->count; i++) {
    if (data->ptcls[i].active) {
      if (data->kind < 21) {
        group = p->group1;
      } else {
        group = p->group2;
      }
      data->ptcls[i].ptcl.pos.x += data->ptcls[i].vel.x;
      data->ptcls[i].ptcl.pos.z += data->ptcls[i].vel.z;
      data->ptcls[i].height += data->ptcls[i].vel.y;
      data->ptcls[i].vel.y--;
      data->ptcls[i].ptcl.pos.y = data->ptcls[i].height;
      data->ptcls[i].ptcl.tileNum = group->tile + sScatterTileOffsets[data->kind];
      data->ptcls[i].ptcl.priority = data->priority;
      if (data->ptcls[i].age++ >= data->ptcls[i].lifetime) {
        data->ptcls[i].active = FALSE;
        Particle_Remove(&data->ptcls[i].ptcl);
      } else {
        alive++;
      }
    }
  }
  if (alive == 0) {
    data->active = FALSE;
  }
#else
  INCFUNC("asm/func/ScatterEffect_UpdateFlying.inc");
#endif
}

// 下書き2回で止めた (321/327), 影のタイル番号は sScatterTileOffsets[SCATTER_SHADOW] を先に読んで持つ形にすると退避の並びが近づく
// 原典は粒子の歩きポインタを2本持ち, i も退避枠に置く (Ghidra の pSVar11 / pSVar2 / local_30)
// 床で跳ねる粒子の更新, 床に潜ったら速度を反転し, 1フレームおきに影を描く
NON_MATCH void ScatterEffect_UpdateBouncing(ScatterEffect* p, ScatterBurst* data) {
#ifdef NONMATCHING_C
  u32 shadowTile = sScatterTileOffsets[SCATTER_SHADOW];
  s32 alive = 0;
  s32 i;

  for (i = 0; i < data->count; i++) {
    ScatterParticle* sp = &data->ptcls[i];

    if (sp->active) {
      ParticleGroup* group;
      s32 bx = (s8)(sp->ptcl.pos.x >> 8);
      s32 bz = (s8)(sp->ptcl.pos.z >> 8);
      u16 idx;
      s32 floorY;

      if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
        idx = 0xFFFF;
      } else {
        idx = gCollisionMap->rowOffsets[bz] + bx;
      }
      if (data->kind < 21) {
        group = p->group1;
      } else {
        group = p->group2;
      }
      sp->ptcl.pos.x += sp->vel.x;
      sp->ptcl.pos.z += sp->vel.z;
      sp->height += sp->vel.y;
      sp->vel.y--;

      if (idx == 0xFFFF) {
        floorY = 0xFFFF;
      } else {
        MapTileOverride* ov = Map_FindTileOverride(idx, 1);
        CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];

        floorY = (tile->heightStairs & 0xF) << 8;
        if (sp->height < floorY) {
          if (idx == sp->mapIdx) {
            sp->height = floorY;
          } else {
            s32 diff = idx - sp->mapIdx;

            if (diff < 0) {
              diff = -diff;
            }
            if (diff == 1) {
              sp->vel.x = -FixToInt(6, ((Random() & 7) + 50) * sp->vel.x);
              if (idx - sp->mapIdx < 0) {
                sp->ptcl.pos.x = (sp->ptcl.pos.x & 0xFF00) + 0x100;
              } else {
                sp->ptcl.pos.x = (sp->ptcl.pos.x & 0xFF00) - 1;
              }
            } else {
              sp->vel.z = -FixToInt(6, ((Random() & 7) + 50) * sp->vel.z);
              if (idx - sp->mapIdx < 0) {
                sp->ptcl.pos.z = (sp->ptcl.pos.z & 0xFF00) + 0x100;
              } else {
                sp->ptcl.pos.z = (sp->ptcl.pos.z & 0xFF00) - 1;
              }
            }
          }
          sp->vel.y = -FixToInt(6, ((Random() & 3) + 55) * sp->vel.y);
        }
        ov = Map_FindTileOverride(idx, 1);
        tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
        if (tile->attr & 0x20) {
          floorY = 0xFFFF;
        }
      }
      sp->mapIdx = idx;

      if ((p->frameCount & 1) == (i & 1) && floorY != 0xFFFF) {
        sp->ptcl.pos.y = floorY;
        sp->ptcl.tileNum = group->tile + shadowTile;
        sp->ptcl.priority = 3;
      } else {
        sp->ptcl.pos.y = sp->height;
        sp->ptcl.tileNum = group->tile + sScatterTileOffsets[data->kind];
        sp->ptcl.priority = data->priority;
      }
      if (sp->age++ >= sp->lifetime) {
        sp->active = FALSE;
        Particle_Remove(&sp->ptcl);
      } else {
        alive++;
      }
    }
  }
  if (alive == 0) {
    data->active = FALSE;
  }
#else
  INCFUNC("asm/func/ScatterEffect_UpdateBouncing.inc");
#endif
}

// 残差は最後の kind < 9 の判定で, 原典は各分岐の後で読み直した kind を u8 の1本にまとめて (lsls 24) 比べる, それに伴う分岐距離 (151/152)
// idx が 0xFFFF でない側を then にする形と attr 判定の向きは試済
// 停止中の貼り直し, 床の上の粒子は1フレームおきに影として床の高さへ描く
NON_MATCH void ScatterEffect_UpdatePaused(ScatterEffect* p, ScatterBurst* data) {
#ifdef NONMATCHING_C
  u32 shadowTile = data->kind < 9 ? sScatterTileOffsets[SCATTER_SHADOW] : sScatterTileOffsets[data->kind];
  ScatterParticle* sp = data->ptcls;
  s32 i;

  for (i = 0; i < 8; i++) {
    ParticleGroup* group = data->kind < 21 ? p->group1 : p->group2;

    if (!(sp->ptcl.flags & SPRFLAG_HIDDEN)) {
      s32 bx = (s8)(sp->ptcl.pos.x >> 8);
      s32 bz = (s8)(sp->ptcl.pos.z >> 8);
      u16 idx;
      s16 floorY;

      if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
        idx = 0xFFFF;
      } else {
        idx = gCollisionMap->rowOffsets[bz] + bx;
      }
      if (idx != 0xFFFF) {
        MapTileOverride* ov = Map_FindTileOverride(idx, 1);
        CollisionMapTile* tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];

        if (tile->attr & 0x20) {
          floorY = -1;
        } else {
          ov = Map_FindTileOverride(idx, 1);
          tile = ov != NULL ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];
          floorY = (tile->heightStairs & 0xF) << 8;
        }
      } else {
        floorY = -1;
      }
      if (data->kind < 9 && (p->frameCount & 1) && floorY != -1) {
        sp->ptcl.pos.y = floorY;
        sp->ptcl.tileNum = group->tile + shadowTile;
      } else {
        sp->ptcl.pos.y = sp->height;
        sp->ptcl.tileNum = group->tile + sScatterTileOffsets[data->kind];
      }
    }
    sp++;
  }
#else
  INCFUNC("asm/func/ScatterEffect_UpdatePaused.inc");
#endif
}

// 停止中はスプライトの貼り直しだけ、動作中は kind 別の更新に振り分ける
s32 ScatterEffect_Update(ScatterEffect* p) {
  ScatterBurst* data;
  s32 i;

  if (gSuspendFlags != 0) {
    data = p->bursts;
    for (i = 0; i < 6; i++) {
      if (data->active) {
        ScatterEffect_UpdatePaused(p, data);
      }
      data++;
    }
  } else {
    data = p->bursts;
    for (i = 0; i < 6; i++) {
      if (data->active) {
        if (data->kind < 9) {
          ScatterEffect_UpdateBouncing(p, data);
        } else {
          ScatterEffect_UpdateFlying(p, data);
        }
      }
      data++;
    }
  }
  p->frameCount++;
  return 0;
}

s32 ScatterEffect_Destroy(ScatterEffect* p) {
  s32 i, j;

  for (i = 0; i < 6; i++) {
    ScatterBurst* data = &p->bursts[i];
    if (data->active) {
      for (j = 0; j < 8; j++) {
        if (data->ptcls[j].active) {
          Particle_Remove(&data->ptcls[j].ptcl);
        }
      }
    }
  }
  sScatterEffect = NULL;
  return 0;
}

s32 ScatterEffect_Init(ScatterEffect* p, u32 _) {
  s32 i, j;

  sScatterEffect = p;
  p->group1 = GetParticleGroup(PTCL_GROUP_1);
  p->group2 = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 6; i++) {
    p->bursts[i].active = FALSE;
    for (j = 0; j < 8; j++) {
      Particle_Setup(&p->bursts[i].ptcls[j].ptcl, p->group1, SPRFLAG_HIDDEN);
      Particle_SetOffset(&p->bursts[i].ptcls[j].ptcl, -4, -4);
    }
  }
  p->frameCount = 0;
  return 0;
}

ScatterEffect* ScatterEffect_Create(u32 unused1, u32 unused2) {
  if (sScatterEffect == NULL) {
    ScatterEffect* p = CreateEntity(ENTITY_UNK_10, sizeof(ScatterEffect));
    if (p != NULL) {
      SetEntityRoutine(p, ScatterEffect_Update, ScatterEffect_Destroy);
      if (ScatterEffect_Init(p, unused1) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return sScatterEffect;
}

// 下書き1回で止めた (292/306), 原典は data と粒子の歩きポインタを2本ずつ持ち (Ghidra の local_28 / pSVar9), kind を退避枠に置く
// 粒子の初期化の中身 (寿命, マップ番号, 速度の乱数, 左右反転) は Ghidra の形どおり
// 空いたまとまりに count 個の粒子を pos から乱数つきの速度で撒く
NON_MATCH s32 ScatterEffect_Spawn(s32 count, s32 kind, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask) {
#ifdef NONMATCHING_C
  ScatterEffect* p = sScatterEffect;
  ParticleGroup* group;
  ScatterBurst* data;
  s32 i, j;

  if (p == NULL) {
    p = ScatterEffect_Create(0, 0);
    if (p == NULL) {
      return -1;
    }
  }
  if (count > 8) {
    count = 8;
  }
  if ((u8)kind < 21) {
    group = p->group1;
  } else {
    group = p->group2;
  }

  data = p->bursts;
  for (i = 0; i < 6; i++) {
    if (!data->active) {
      data->active = TRUE;
      data->kind = kind;
      data->count = count;
      data->priority = (kind >> 8) < 1 ? 2 : (kind >> 8) - 1;
      for (j = 0; j < count; j++) {
        ScatterParticle* sp = &data->ptcls[j];
        s32 bx, bz;

        sp->active = TRUE;
        sp->unk_01 = 1;
        sp->age = 0;
        sp->lifetime = lifeBase + ((u8)Random() & lifeRandMask);
        bx = (s8)(pos->x >> 8);
        bz = (s8)(pos->z >> 8);
        if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
          sp->mapIdx = 0xFFFF;
        } else {
          sp->mapIdx = gCollisionMap->rowOffsets[bz] + bx;
        }
        sp->height = pos->y;
        if (velRange->x == 0) {
          sp->vel.x = vel->x;
        } else {
          sp->vel.x = vel->x + Mod(Random(), velRange->x);
        }
        if (velRange->y == 0) {
          sp->vel.y = vel->y;
        } else {
          sp->vel.y = vel->y + Mod(Random(), velRange->y);
        }
        if (velRange->z == 0) {
          sp->vel.z = vel->z;
        } else {
          sp->vel.z = vel->z + Mod(Random(), velRange->z);
        }
        if ((Random() & 0xF) < 8) {
          sp->ptcl.flags |= SPRFLAG_XFLIP;
        } else {
          sp->ptcl.flags &= ~SPRFLAG_XFLIP;
        }
        sp->ptcl.flags &= ~SPRFLAG_HIDDEN;
        sp->ptcl.pos = *pos;
        sp->ptcl.tileNum = group->tile + sScatterTileOffsets[(u8)kind];
        sp->ptcl.priority = data->priority;
        Particle_AddToDrawList(&sp->ptcl, 0);
      }
      for (; j < 8; j++) {
        data->ptcls[j].active = FALSE;
        data->ptcls[j].ptcl.flags |= SPRFLAG_HIDDEN;
      }
      return 0;
    }
    data++;
  }
  return 0;
#else
  INCFUNC("asm/func/ScatterEffect_Spawn.inc");
#endif
}

// 下書き1回で止めた (351/370), ScatterEffect_Spawn と同じ骨組みで, 残差の性質も同じ (歩きポインタの本数と kind / count の退避)
// 原典は速度を Vec3 の y に一度 0 を書いてから velY で上書きする
// 空いたまとまりに count 個の粒子を angle を中心とした扇の向きへ撒く
NON_MATCH s32 ScatterEffect_SpawnAtAngle(s32 count, s32 kind, Vec3* pos, s32 angle, s32 angleRange, s32 speed, s32 speedRange, s32 velY, s32 velYRange, s32 lifeBase, s32 lifeRandMask) {
#ifdef NONMATCHING_C
  ScatterEffect* p = sScatterEffect;
  ParticleGroup* group;
  ScatterBurst* data;
  u8 plttSlot;
  s32 i, j;

  if (p == NULL) {
    p = ScatterEffect_Create(0, 0);
    if (p == NULL) {
      return -1;
    }
  }
  if (count > 8) {
    count = 8;
  }
  if ((u8)kind < 21) {
    group = p->group1;
    plttSlot = group->plttID;
  } else {
    group = p->group2;
    plttSlot = group->plttID + 1;
  }

  data = p->bursts;
  for (i = 0; i < 6; i++) {
    if (!data->active) {
      data->active = TRUE;
      data->kind = kind;
      data->count = count;
      data->priority = (kind >> 8) < 1 ? 2 : (kind >> 8) - 1;
      for (j = 0; j < count; j++) {
        ScatterParticle* sp = &data->ptcls[j];
        s32 bx, bz;
        s32 spd;

        sp->active = TRUE;
        sp->unk_01 = 1;
        sp->age = 0;
        sp->lifetime = lifeBase + ((u8)Random() & lifeRandMask);
        bx = (s8)(pos->x >> 8);
        bz = (s8)(pos->z >> 8);
        if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
          sp->mapIdx = 0xFFFF;
        } else {
          sp->mapIdx = gCollisionMap->rowOffsets[bz] + bx;
        }
        sp->height = pos->y;
        spd = speed;
        if (speedRange != 0) {
          spd = speed + Mod(Random(), speedRange);
        }
        if (angleRange == 0) {
          sp->vel.x = FixToInt(12, spd * COS(angle));
          sp->vel.y = 0;
          sp->vel.z = FixToInt(12, spd * SIN(angle));
        } else {
          u32 a = angle - (angleRange >> 1) + Mod(Random(), angleRange);

          sp->vel.x = FixToInt(12, spd * COS(a));
          sp->vel.y = 0;
          sp->vel.z = FixToInt(12, spd * SIN(a));
        }
        sp->vel.y = velY;
        if (velYRange != 0) {
          sp->vel.y = velY + Mod(Random(), velYRange);
        }
        if ((Random() & 0xF) < 8) {
          sp->ptcl.flags |= SPRFLAG_XFLIP;
        } else {
          sp->ptcl.flags &= ~SPRFLAG_XFLIP;
        }
        sp->ptcl.flags &= ~SPRFLAG_HIDDEN;
        sp->ptcl.pos = *pos;
        sp->ptcl.plttSlot = plttSlot;
        sp->ptcl.tileNum = group->tile + sScatterTileOffsets[(u8)kind];
        sp->ptcl.priority = data->priority;
        Particle_AddToDrawList(&sp->ptcl, 0);
      }
      for (; j < 8; j++) {
        data->ptcls[j].active = FALSE;
        data->ptcls[j].ptcl.flags |= SPRFLAG_HIDDEN;
      }
      return 0;
    }
    data++;
  }
  return 0;
#else
  INCFUNC("asm/func/ScatterEffect_SpawnAtAngle.inc");
#endif
}

// 出ている粒子を全部消して、まとまりも空きに戻す, 呼び出し元は見つかっていない
NON_MATCH void ScatterEffect_RemoveAll(void) {
#ifdef NONMATCHING_C
  ScatterEffect* p = sScatterEffect;
  ScatterBurst* data;
  s32 i, j;

  if (p == NULL) {
    return;
  }
  for (i = 0; i < 6; i++) {
    data = &p->bursts[i];
    if (data->active) {
      for (j = 0; j < 8; j++) {
        if (data->ptcls[j].active) {
          Particle_Remove(&data->ptcls[j].ptcl);
          data->ptcls[j].active = FALSE;
        }
      }
      data->active = FALSE;
    }
  }
#else
  INCFUNC("asm/func/ScatterEffect_RemoveAll.inc");
#endif
}
