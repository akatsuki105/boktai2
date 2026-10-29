#include "collision_map.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "global.h"
#include "input.h"
#include "map_inline.h"
#include "player.h"
#include "solar.h"
#include "spirit_bugs.h"
#include "sprite.h"
#include "time.h"
#include "vm.h"

typedef enum {
  DARK_NORMAL = 0,   // チャージなし(正確には太陽光が当たっていない状態, サバタの場合はこれで自然回復する)
  SUN_NORMAL = 1,    // 太陽光で自然回復
  QUICK_CHARGE = 2,  // 急速チャージ
} ChargeSpeed;

// 天窓から差し込む(スポット的な)光, スプライトは SPRITE_SPOTLIGHT
typedef struct {
  Vec3 pos;             // 0x00, '.p', 足元のタイルの高さに合わせてから入る
  AuxSprite sprite[2];  // 0x08
  AuxSpriteGfx gfx[2];  // 0x60
  s16 id;               // 0x98, '.n', 光柱の識別番号, '.n' にこの値を渡して点灯/消灯を切り替える
  bool8 lit;            // 0x9A, 点灯中か, 落ちていると矩形判定もスプライトも無効になる
  u8 unk_9b;            // 0x9B
  u8 unk_9c;            // 0x9C, '.t' の値の4倍
  bool8 active;         // 0x9D
  u16 mapArea;          // 0x9E
  u16 minX;             // 0xA0, 床に落ちる光の矩形, 大きさは '.t', 向きは '.r' で決まる
  u16 minZ;             // 0xA2
  u16 maxX;             // 0xA4
  u16 maxZ;             // 0xA6
} SkylightBeam;
static_assert(sizeof(SkylightBeam) == 168);

// 天窓の光を最大16個持ち、プレイヤーが光の中にいる間 太陽ゲージに応じて ENE を回復させる
// おそらく、太陽光を浴びている状態の判定と浴びている時間に関するEntity, 天窓の情報も管理
typedef struct {
  Entity e;                // 0x000, ENTITY_UNK_9
  Player* player;          // 0x018
  bool16 unk_1c;           // 0x01C
  u16 charge;              // 0x01E, 120 たまるごとに ENE が1回復する
  u16 idleTimer;           // 0x020, 無操作の間 900 まで増える, 900 に達すると charge が増えなくなる
  u16 unk_22;              // 0x022
  u16 pltt;                // 0x024
  u8 count;                // 0x026, beams の使用数
  u8 unk_27;               // 0x027
  bool8 unk_28;            // 0x028
  bool8 unk_29;            // 0x029
  u8 unk_2a[2];            // 0x02A
  SkylightBeam beams[16];  // 0x02C
  u16 charges[4];          // 0xAAC, プレイヤーごとの ENE 回復カウンタ, 120 たまるごとに ENE が1回復する
} Entity5CCC;
static_assert(sizeof(Entity5CCC) == 2740);

IWRAM_DATA Entity5CCC* gEntity5CCC = NULL;  // 0x03000140

extern u16 gRisingSunCount;

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

// まだセッションが無ければ 0
static inline u8 Entity9A9F_GetUnk60(s32 idx) {
  if (gEntity9A9F == NULL) {
    return 0;
  }
  return gEntity9A9F->unk_60[idx];
}

// まだセッションが無ければ 0
static inline u16 Entity9A9F_GetUnk66(void) {
  if (gEntity9A9F == NULL) {
    return 0;
  }
  return gEntity9A9F->unk_66;
}

// 光柱のパレットを設定する (既にそのパレットなら何もしない)
static inline void Entity5CCC_SetPltt(Entity5CCC* p, u16 plttID) {
  s32 i, j;
  if (p->pltt != plttID) {
    p->pltt = plttID;
    for (i = 0; i < p->count; i++) {
      if (p->beams[i].active) {
        for (j = 0; j < 2; j++) {
          Video_SetAuxSpritePltt(&p->beams[i].gfx[j], p->pltt);
        }
      }
    }
  }
}

void FUN_0809df6c(void) { gEntity5CCC = NULL; }

// pos が有効な光柱の矩形の中にあるか
bool32 FUN_0809df78(Vec3* pos) {
  Entity5CCC* p = gEntity5CCC;
  s32 i;

  if (p == NULL) {
    return FALSE;
  }

  for (i = 0; i < p->count; i++) {
    if (p->beams[i].lit && pos->x >= p->beams[i].minX && pos->z >= p->beams[i].minZ && pos->x <= p->beams[i].maxX && pos->z <= p->beams[i].maxZ) {
      return TRUE;
    }
  }

  return FALSE;
}

// 指定エリアに有効な光柱があるか
// 残差3命令, 原典は count != 0 のガードと i < count の判定を両方出し mapArea を r4 に置くが
// agbcc はガードを1つに畳んで r5 まで使う (count != 0 を明示的に書くと逆に5命令増える)
NON_MATCH bool32 FUN_0809dfec(s32 mapArea) {
#ifdef NONMATCHING_C
  Entity5CCC* p = gEntity5CCC;
  SkylightBeam* beam;
  s32 i;

  if (p == NULL) {
    return FALSE;
  }
  beam = p->beams;
  for (i = 0; i < p->count; i++, beam++) {
    if (beam->lit && beam->mapArea == mapArea) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_0809dfec.inc");
#endif
}

// 太陽ゲージに比例した量を返す, 0 にはならない
s32 FUN_0809e034(s32 coef) {
  s32 n = Div(gStat->sunGauge * coef, 10);
  if (n < 1) {
    n = 1;
  }
  return n;
}

// 引数の座標が天窓の下にあるかどうかを判定
// pos が入っている有効な光柱の添字を返す, 無ければ -1
s32 FUN_0809e05c(Vec3* pos) {
  Entity5CCC* p = gEntity5CCC;
  s32 i;

  if (p == NULL) {
    return -1;
  }

  for (i = 0; i < p->count; i++) {
    if (p->beams[i].lit && pos->x >= p->beams[i].minX && pos->z >= p->beams[i].minZ && pos->x <= p->beams[i].maxX && pos->z <= p->beams[i].maxZ) {
      return i;
    }
  }

  return -1;
}

// 引数の座標が太陽光を受けているかを判定 (敵用?, 敵には太陽光でダメージを受けるものがいるのでその辺に関係)
s32 FUN_0809e0d4(Vec3* pos, s32 coef) {
  if (gStat->sunGauge == 0) {
    return 0;
  }
  if (!TestMapFlag(MPF_OUTDOOR) && FUN_0809e05c(pos) < 0 && gEntity5CCC->unk_29 == 0) {
    return 0;
  }
  return FUN_0809e034(coef);
}

// プレイヤーが太陽光を受けているかを判定
bool32 FUN_0809e138(Player* p) {
  if (gStat->sunGauge == 0) {
    return FALSE;
  }
  if (!TestMapFlag(MPF_OUTDOOR) && (gEntity5CCC == NULL || FUN_0809e05c(&p->mover.pos) < 0)) {
    return FALSE;
  }
  return TRUE;
}

// pos を中心に sizeIdx 番の大きさで光の矩形を作る, shape で X と Z の半径が入れ替わる
void FUN_0809e198(SkylightBeam* beam, s32 sizeIdx, Vec3* pos, s32 shape) {
  static const u16 u16_ARRAY_085ad004[4] = {Q8(0.391), Q8(0.391), Q8(0.44), Q8(0.44)};  // 0x085AD004
  static const u16 u16_ARRAY_085ad00c[4] = {Q8(0.500), Q8(0.391), Q8(0.44), Q8(0.44)};  // 0x085AD00C

  u16 halfX, halfZ;
  if (shape != 0) {
    halfX = u16_ARRAY_085ad004[sizeIdx];
    halfZ = u16_ARRAY_085ad00c[sizeIdx];
  } else {
    halfX = u16_ARRAY_085ad00c[sizeIdx];
    halfZ = u16_ARRAY_085ad004[sizeIdx];
  }

  beam->minX = pos->x - halfX;
  beam->minZ = pos->z - halfZ;
  beam->maxX = halfX + pos->x;
  beam->maxZ = halfZ + pos->z;
}

void FUN_0809e1f8(void) {
  Entity5CCC* p = gEntity5CCC;

  if (p == NULL) {
    return;
  }
  if (VM_SeekToNamedArg('t')) {
    p->unk_27 = VM_GetValue();
  } else {
    p->unk_27 = 0;
  }
}

// 光柱1本を pos に立ち上げる
// 残差5命令 (66/71). 原典は pos をスタックへ退避するほどレジスタが足りていないが, agbcc は r10 に収めてしまう
NON_MATCH void FUN_0809e22c(SkylightBeam* beam, s32 kind, Vec3* pos, u32 shape, s32 pltt) {
#ifdef NONMATCHING_C
  SpriteFlags flags;

  beam->pos = *pos;
  flags = shape != 0 ? SPRFLAG_XFLIP : 0;
  beam->unk_9c = kind * 4;
  Video_GetAuxSprite(&beam->gfx[0], SPRITE_SPOTLIGHT);
  AuxSprite_Add(&beam->sprite[0], &beam->gfx[0], flags);
  beam->sprite[0].poseIdx = beam->unk_9c;
  Video_SetAuxSpritePltt(&beam->gfx[0], pltt);
  beam->sprite[0].pos = beam->pos;
  beam->sprite[0].priority = 3;
  beam->active = TRUE;
  FUN_0809e198(beam, kind, pos, shape);
  beam->mapArea = GetZoneAt(&beam->pos);
#else
  INCFUNC("asm/func/FUN_0809e22c.inc");
#endif
}

// 0xD25F, '.n' と '.a' から矩形だけの光柱 (スプライトなし) を1本登録する
void Entity5CCC_AddLightAreaScripted(void) {
  Entity5CCC* p = gEntity5CCC;
  Vec3 pos;

  if (p == NULL) {
    return;
  }
  if (p->count >= 16) {
    return;
  }

  if (VM_SeekToNamedArg('n')) {
    p->beams[p->count].id = VM_GetValue();
  } else {
    p->beams[p->count].id = 0;
  }

  if (VM_SeekToNamedArg('a')) {
    p->beams[p->count].minX = VM_GetValue();
    p->beams[p->count].minZ = VM_GetValue();
    p->beams[p->count].maxX = VM_GetValue();
    p->beams[p->count].maxZ = VM_GetValue();
    pos.x = p->beams[p->count].minX;
    pos.y = 0;
    pos.z = p->beams[p->count].minZ;
    p->beams[p->count].mapArea = GetZoneAt(&pos);
    p->beams[p->count].lit = TRUE;
    p->count++;
  }
}

// 0x320C, '.p' のタイルの高さに合わせて光柱を1本立てる
void Entity5CCC_AddBeamScripted(void) {
  Entity5CCC* p = gEntity5CCC;
  Vec3 pos;
  s32 size;
  s32 dir;

  if (p == NULL) {
    return;
  }
  if (p->count >= 16) {
    return;
  }

  if (VM_SeekToNamedArg('n')) {
    p->beams[p->count].id = VM_GetValue();
  } else {
    p->beams[p->count].id = 0;
  }

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  pos.y = TileHeightAt(&pos);

  size = VM_SeekToNamedArg('t') ? VM_GetValue() : 0;
  dir = VM_SeekToNamedArg('r') ? VM_GetValue() : 0;

  FUN_0809e22c(&p->beams[p->count], size, &pos, dir, p->pltt);
  p->beams[p->count].lit = TRUE;
  if (p->unk_28 == 0) {
    p->beams[p->count].sprite[0].flags |= SPRFLAG_HIDDEN;
  }
  p->count++;
}

// '.n' が指す光柱を見せる
// 残差1命令 (57/56). Cmd_815C と同じく '.n' の値が ip へ追い出されて mov が1つ増える
NON_MATCH void Cmd_EB42(void) {
#ifdef NONMATCHING_C
  Entity5CCC* p = gEntity5CCC;
  s32 id;
  s32 i;

  if (p == NULL) {
    return;
  }
  if (!VM_SeekToNamedArg('n')) {
    return;
  }

  id = VM_GetValue();
  for (i = 0; i < p->count; i++) {
    if (p->beams[i].id != 0 && p->beams[i].id == id) {
      p->beams[i].lit = TRUE;
      if (p->beams[i].active && p->unk_28) {
        p->beams[i].sprite[0].flags &= ~SPRFLAG_HIDDEN;
      }
      return;
    }
  }
#else
  INCFUNC("asm/func/Cmd_EB42.inc");
#endif
}

// '.n' が指す光柱を消す
// 残差1命令 (51/50). 原典は '.n' の値を r7 に置くが agbcc は ip へ追い出して mov を1つ増やす
NON_MATCH void Cmd_815C(void) {
#ifdef NONMATCHING_C
  Entity5CCC* p = gEntity5CCC;
  s32 id;
  s32 i;

  if (p == NULL) {
    return;
  }
  if (!VM_SeekToNamedArg('n')) {
    return;
  }

  id = VM_GetValue();
  for (i = 0; i < p->count; i++) {
    if (p->beams[i].id != 0 && p->beams[i].id == id) {
      p->beams[i].lit = FALSE;
      if (p->beams[i].active) {
        p->beams[i].sprite[0].flags |= SPRFLAG_HIDDEN;
      }
      return;
    }
  }
#else
  INCFUNC("asm/func/Cmd_815C.inc");
#endif
}

// 日光 (サバタは日陰) を浴びている量を積み, 120 たまるごとに ENE を1回復させる
void Entity5CCC_AddEneCharge(Entity5CCC* p, s32 light) {
  s32 heal;

  if (gGameFlags & FLAG030047A4_UNK_8) {
    p->idleTimer = 0;
  } else if (gInput[0].down != 0) {
    p->idleTimer = 0;
  } else if (p->idleTimer < 900) {
    p->idleTimer++;
  }

  if ((gGameFlags & (FLAG030047A4_UNK_8 | FLAG030047A4_UNK_9)) == FLAG030047A4_UNK_9) {
    return;
  }
  if (TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    return;
  }

  if (p->player->kind == PLAYER_SABATA) {
    if (light == QUICK_CHARGE) {
      p->charge += 40;
    } else if (light == DARK_NORMAL && p->idleTimer < 900) {
      p->charge += 5;
    }
  } else {
    if (light == QUICK_CHARGE) {
      p->charge += gStat->sunGauge * 8;
    } else if (light == SUN_NORMAL && p->idleTimer < 900) {
      s32 sun = gStat->sunGauge;
      p->charge += sun;
    }
  }

  heal = 0;
  while (p->charge >= 120) {
    p->charge -= 120;
    heal++;
  }
  if (heal > 0) {
    Player_AddENE(p->player, heal);
  }
}

void FUN_0809e734(Entity5CCC* p) {
  Player* player = p->player;

  u32 chargeSpeed;
  if (TEST_FLAGS(player->flag20, PFLAG20_QC)) {
    chargeSpeed = QUICK_CHARGE;
  } else if (TEST_FLAGS(player->flag20, PFLAG20_SUNBATHING)) {
    chargeSpeed = SUN_NORMAL;
  } else {
    chargeSpeed = DARK_NORMAL;
  }
  Entity5CCC_AddEneCharge(p, chargeSpeed);
}

// 光柱のパレットを 412 に切り替える (既にそうなっていれば何もしない)
void FUN_0809e75c(Entity5CCC* p) { Entity5CCC_SetPltt(p, 412); }

// 有効な光柱を見せ, プレイヤーの状態に応じて Entity5CCC_AddEneCharge を呼ぶ
void FUN_0809e7c4(Entity5CCC* p) {
  Player* player;
  u32 chargeSpeed;

  if (!p->unk_28) {
    s32 i;

    p->unk_28 = TRUE;
    for (i = 0; i < p->count; i++) {
      if (p->beams[i].active && p->beams[i].lit) {
        p->beams[i].sprite[0].flags &= ~SPRFLAG_HIDDEN;
      }
    }
  }

  FUN_0809e75c(p);
  player = p->player;
  if (TEST_FLAGS(player->flag20, PFLAG20_QC)) {
    chargeSpeed = QUICK_CHARGE;
  } else if (TEST_FLAGS(player->flag20, PFLAG20_SUNBATHING)) {
    chargeSpeed = SUN_NORMAL;
  } else {
    chargeSpeed = DARK_NORMAL;
  }
  Entity5CCC_AddEneCharge(p, chargeSpeed);
}

// unk_28 が立っていたら有効な光柱を一旦隠し, プレイヤーの状態に応じて Entity5CCC_AddEneCharge を呼ぶ
void FUN_0809e840(Entity5CCC* p) {
  if (p->unk_28 == 1) {
    s32 i;

    p->unk_28 = FALSE;
    for (i = 0; i < p->count; i++) {
      if (p->beams[i].active) {
        p->beams[i].sprite[0].flags |= SPRFLAG_HIDDEN;
      }
    }
  }

  Entity5CCC_AddEneCharge(p, Player_TestFlag20(p->player, PFLAG20_QC) ? 2 : 0);
}

// 夜の更新, 光柱を見せたままにし, プレイヤーが action 7 / state 3 の間だけホタルを8フレームごとに出す
// 残差1命令 (140/141). 原典は天窓判定の 0/1 を分岐で作り置きしてから cmp するが, agbcc は mvns + lsrs #31 の値計算に畳む (s32/bool8/bool32/u16, 戻り値をローカルに受ける, 代入先を定数にする, いずれも変わらない)
NON_MATCH void Entity5CCC_UpdateNight(Entity5CCC* p) {
#ifdef NONMATCHING_C
  bool32 found;

  if (!p->unk_28) {
    s32 i;

    p->unk_28 = TRUE;
    for (i = 0; i < p->count; i++) {
      if (p->beams[i].lit) {
        p->beams[i].sprite[0].flags &= ~SPRFLAG_HIDDEN;
      }
    }
  }

  found = FALSE;
  if (!(gStat->mapFlags & MPF_OUTDOOR)) {
    if (FUN_0809e05c(&p->player->mover.pos) >= 0) {
      found = TRUE;
    }
    if (found == 0) {
      p->unk_22 = 0;
      FUN_0809e75c(p);
      return;
    }
  }

  if (p->player->action == PACT_UNK_7 && p->player->state <= 3) {
    if (p->player->state == 3 && p->unk_22 <= 62) {
      if ((p->unk_22 & 7) == 0) {
        Vec3 pos, spread;
        pos = p->player->mover.pos;
        pos.x -= Q8(0.391);
        pos.z -= Q8(0.391);
        pos.y += Q8(1);
        VEC3_SET(spread, Q8(1), 0, Q8(1));
        SpawnSpiritBugs(1, MOONBUG, 25, &pos, &spread, 180, 60);
      }
      p->unk_22++;
    }
  } else {
    p->unk_22 = 0;
  }

  FUN_0809e75c(p);
#else
  INCFUNC("asm/func/Entity5CCC_UpdateNight.inc");
#endif
}

bool32 FUN_0809e9d0(Entity5CCC* p) {
  if (p->unk_1c) {
    u32 span = Time_GetSpanOfTime();

    if (span < TIME_MORNING || span > TIME_SUNSET) {
      return TRUE;
    }
  }
  return FALSE;
}

// 日光の有無と屋内外で毎フレームの処理を振り分ける
s32 Entity0809eb24_Update(Entity5CCC* p) {
  if (p->unk_29 != 0) {
    p->unk_29 = 0;
  }

  p->player = gPlayerPtr[0];
  if (gPlayerPtr[0] != NULL) {
    u16 override;
    bool32 forced;

    if (gStat->lx == 0) {  // 太陽光が0 (ライジングサンなども含めたもの)
      if (FUN_0809e9d0(p)) {
        Entity5CCC_UpdateNight(p);
      } else {
        FUN_0809e840(p);
      }
    } else if (gStat->mapFlags & MPF_OUTDOOR) {  // 太陽光がある場合は、屋外と屋内で処理を分ける
      FUN_0809e734(p);                           // 屋外
    } else {
      FUN_0809e7c4(p);  // 屋内
    }

    override = gSunGaugeOverride;
    forced = (override == 1) ? TRUE : FALSE;
    if (forced && gRisingSunCount != 0) {
      p->unk_29 = 1;
    }
  }
  return 0;
}

s32 Entity0809eb24_Destroy(Entity5CCC* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (p->beams[i].active) {
      AuxSprite_Remove(p->beams[i].sprite);
    }
  }
  gEntity5CCC = NULL;
  return 0;
}

bool32 FUN_0809eacc(void) {
  if (gGameFlags & FLAG030047A4_UNK_8) {
    return FALSE;
  }
  if (Time_GetMoonPhase() == 4) {  // 満月
    return TRUE;
  }
  return FALSE;
}

s32 Entity0809eb24_Init(Entity5CCC* p, u32 id, u32 _) {
  p->unk_1c = FUN_0809eacc();
  p->count = 0;
  p->pltt = 410;
  p->unk_28 = 0;
  gEntity5CCC = p;
  return 0;
}

// 1人プレイ
Entity5CCC* Entity0809eb24_Create(u32 id, u32 _) {
  Entity5CCC* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity5CCC));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0809eb24_Update, Entity0809eb24_Destroy);
    if (Entity0809eb24_Init(p, id, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

s32 FUN_0809eb6c(s32 param_1) { return Div(param_1 * Entity9A9F_GetUnk66(), 140); }

// 屋外か天窓の光の中にいるときだけ param_2 に応じた値を返す
s32 FUN_0809eb94(Vec3* pos, s32 param_2) {
  if (Entity9A9F_GetUnk66() == 0) {
    return 0;
  }
  if (!TestMapFlag(MPF_OUTDOOR) && FUN_0809e05c(pos) < 0) {
    return 0;
  }
  return FUN_0809eb6c(param_2);
}

// このプレイヤーが日光を浴びられる状況か (屋外, または天窓の光の中)
bool32 FUN_0809ebf4(Player* p) {
  if (Entity9A9F_GetUnk60(p->inputIdx) == 0) {
    return FALSE;
  }
  if (!TestMapFlag(MPF_OUTDOOR) && (gEntity5CCC == NULL || FUN_0809e05c(&p->mover.pos) < 0)) {
    return FALSE;
  }
  return TRUE;
}

// 日光 (サバタは日陰) を浴びている量をプレイヤーごとに積み, 120 たまるごとに ENE を1回復させる
// 残差9命令 (119/110). light の 0/1 は FUN_0809e734 と同じ if/else + TEST_FLAGS で原典どおり rsbs + lsrs #31 になった
// 残りは i が r3 でなく r5 に乗って p と p+0xAAC に r8/r9 を使う割り当てと, 非サバタ側で unk_60 の値を charges[i] の読みより先に作る順序. GetPlayer / Entity9A9F_GetUnk60 の inline, ローカルを関数スコープに出すのは試済 (119-120)
NON_MATCH void Entity5CCC_UpdateEneRecovery(Entity5CCC* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 4; i++) {
    Player* player = gPlayerPtr[i];
    u32 chargeSpeed;
    s32 heal;

    if (player == NULL) {
      continue;
    }
    if (player->mode != PMODE_ACTIVE) {
      continue;
    }

    if (TEST_FLAGS(player->flag20, PFLAG20_QC)) {
      chargeSpeed = QUICK_CHARGE;
    } else if (TEST_FLAGS(player->flag20, PFLAG20_SUNBATHING)) {
      chargeSpeed = SUN_NORMAL;
    } else {
      chargeSpeed = DARK_NORMAL;
    }

    if (player->kind == PLAYER_SABATA) {
      if (chargeSpeed == QUICK_CHARGE) {
        p->charges[i] += 40;
      } else if (chargeSpeed == DARK_NORMAL) {
        p->charges[i] += 5;
      }
    } else {
      if (chargeSpeed == QUICK_CHARGE) {
        p->charges[i] += (gEntity9A9F != NULL ? gEntity9A9F->unk_60[i] : 0) * 8;
      } else if (chargeSpeed == SUN_NORMAL) {
        p->charges[i] += gEntity9A9F != NULL ? gEntity9A9F->unk_60[i] : 0;
      }
    }

    heal = 0;
    while (p->charges[i] >= 120) {
      p->charges[i] -= 120;
      heal++;
    }
    if (heal > 0) {
      Player_AddENE(player, heal);
    }
  }
#else
  INCFUNC("asm/func/Entity5CCC_UpdateEneRecovery.inc");
#endif
}

void FUN_0809ed54(Entity5CCC* p) {}

// セッション側の許可に合わせて光柱をまとめて見せる/隠す
// 残差4命令 (89/93). 原典は gEntity9A9F の NULL 判定を2回出す (playerIdx 取得用と unk_60 取得用で別々の static inline を通している形) が, agbcc は1回に畳む
// ファイル先頭の Entity9A9F_GetUnk66 と同形の inline 2本で再現できるが, 一致しないので入れない
NON_MATCH void FUN_0809ed58(Entity5CCC* p) {
#ifdef NONMATCHING_C
  s32 playerIdx = gEntity9A9F != NULL ? gEntity9A9F->playerIdx : -1;
  u8 allowed = gEntity9A9F != NULL ? gEntity9A9F->unk_60[playerIdx] : 0;
  s32 i;

  if (allowed != 0) {
    if (p->unk_28 != 0) {
      return;
    }

    p->unk_28 = TRUE;
    for (i = 0; i < p->count; i++) {
      if (p->beams[i].active && p->beams[i].lit) {
        p->beams[i].sprite[0].flags &= ~SPRFLAG_HIDDEN;
      }
    }
  } else {
    if (p->unk_28 != 1) {
      return;
    }

    p->unk_28 = FALSE;
    for (i = 0; i < p->count; i++) {
      if (p->beams[i].active) {
        p->beams[i].sprite[0].flags |= SPRFLAG_HIDDEN;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_0809ed58.inc");
#endif
}

s32 Entity0809eeb4_Update(Entity5CCC* p) {
  if (gStat->mapFlags & MPF_OUTDOOR) {
    FUN_0809ed54(p);
  } else {
    FUN_0809ed58(p);
  }
  Entity5CCC_UpdateEneRecovery(p);
  return 0;
}

s32 Entity0809eeb4_Destroy(Entity5CCC* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (p->beams[i].active) {
      AuxSprite_Remove(p->beams[i].sprite);
    }
  }
  gEntity5CCC = NULL;
  return 0;
}

s32 Entity0809eeb4_Init(Entity5CCC* p, u32 id, u32 _) {
  p->count = 0;
  p->pltt = 410;
  p->unk_28 = 0;
  gEntity5CCC = p;
  return 0;
}

// 通信時
Entity5CCC* Entity0809eeb4_Create(u32 id, u32 _) {
  Entity5CCC* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity5CCC));

  if (p != NULL) {
    SetEntityRoutine(p, Entity0809eeb4_Update, Entity0809eeb4_Destroy);
    if (Entity0809eeb4_Init(p, id, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 0x5CCC, 天窓の光の管理エンティティを1つだけ作る, 既にあればそれを返す
Entity5CCC* Cmd_5CCC(u32 id, u32 _) {
  if (gEntity5CCC != NULL) {
    return gEntity5CCC;
  }
  if (gGameFlags & FLAG030047A4_LINK) {
    return Entity0809eeb4_Create(id, _);
  } else {
    return Entity0809eb24_Create(id, _);
  }
}
