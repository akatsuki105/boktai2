#include "player.h"

#include "armor.h"
#include "camera.h"
#include "coffin.h"
#include "eff_082473e0.h"
#include "emote.h"
#include "enemy.h"
#include "enemy_target.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "input.h"
#include "item.h"
#include "magic.h"
#include "map_inline.h"
#include "menu.h"
#include "random.h"
#include "solar.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "vm.h"

extern u16 gChangeWolfBiting;
extern u16 gSunMagicUsed;
extern u16 gSavedMagicEnchanted;
extern u16 gWindPushThreshold;
extern u16 gWindStrength;
extern u16 gRisingSunCount;

struct Entity080a8ff8* Entity080a8ff8_Create(Player* owner, Vec3* pos, s32 mode);
struct TransEffect* TransEffect_Create(Player* player, u32 param_2, Vec3* pos, u32 param_4, u32 param_5);
struct Entity080abd14* Entity080abd14_Create(void* owner, WorldPos* pos1, WorldPos* pos2, u32 param_4, u32 param_5);
struct FreezeEffect* FreezeEffect_Create(Vec3* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5);
struct HealingEffect* HealingParticles_Create(Player* player, Vec3* pos);
void Entity080acd4c_Spawn(Vec3* pos);
void FUN_08050d10(void);
s32 FUN_08020358(u32 id);
s32 FUN_080dbcec(Vec3* pos, Vec3* param_2, Vec3* param_3, u32 param_4, u32 param_5, u32 param_6);
bool32 Entity1DBE_TouchElemNear(WorldPos* pos);
void FUN_08240cf0(s32 x, s32 z, s16 param_3, s32 param_4, u8 param_5, u16 param_6);
struct Entity08080be8* Entity08080be8_Create(Player* player, u32 heightOffset, u32 unk_be, u32 unk_c0, u32 offsetRadius, u32 plttID, u32 hitboxUnk40, u32 attributes, u32 hitboxUnk44, u32 ptclVal, u32 eneCost, u32 unk_cd);
void FUN_08072724(Player* p);
void FUN_080d040c(Player* p);
s32 FUN_08086294(Vec3* pos, u32 elevatorID, u32 b);
void Django_OnHurt(HitboxData* a, HitboxData* b, Player* p);
void FUN_0807bdc8(Player* p, DirS32 dir, s32 param_3, u32 scriptID);
bool32 FUN_0809df78(Vec3* pos);
s32 FUN_080dc0b8(Vec3* pos, Vec3* param_2, u32 param_3, u32 param_4, u32 param_5);
void FUN_080dab9c(s32 idx);
bool32 FUN_0809e138(Player* p);
magic32_t Player_CheckMagicEnchant(Player* p);
void dark_django_0806f990(HitboxData* a, HitboxData* b, Player* _);
void* Entity080dc44c_Create(void);
struct Judgement* Judgement_Create(Player* p);
struct DjangoBerserk* DjangoBerserk_Create(Player* player);
s32 MosaicFader_Start(s32 mode, s32 objEnabled, s32 targets, u8* from, u8* to, u16* interval);
void BuildWeaponData(Weapon* w, WeaponData* data);
s32 FUN_0807a6cc(WeaponData* w);
void FUN_08071b14(Player* p);
void FUN_08079f1c(Player* p);
void Camera_LookAt(Vec3* pos);
bool8 MapItemManager_TryOpen(Mover* mover);
Vec3* Elevator_GetPosByID(s32 id);
struct ElevatorUnkData* Elevator_FindAtPos(Vec3* pos);
void FUN_080417dc(Mover* mover);
s32 FUN_08003f24(Vec3* pos, u32 dir);
s32 FUN_08086958(void);
s32 FUN_08016110(u32 val1, u32 val2, u32 val3, u32 val4, Vec3* pos);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
struct Entity080c0fa0* Entity080c0fa0_Create(Vec3* pos, SpriteID32 pltt, s32 poseIdx, s32 dir, s32 speed, s32 delay, s32 param_7);

COMMON_DATA u16 gGoodCondID = 0;                        // 0x03002B60, 現在の良い状態効果のID (= Player.goodCondID, Player再生成時の退避用, 他のEntityから参照するなどの用途で使用される)
COMMON_DATA u16 ALIGNED(4) gConfusedDir = 0;            // 0x03002B64, 混乱の状態異常のときに動く方向 (エリア移動などで Player を再生成したときにこれを引き継ぐ)
COMMON_DATA u16 ALIGNED(4) gPlayerMoverIDs[4] = {};     // 0x03002B68, 多分プレイヤーの moverID
COMMON_DATA u16 gChangeWolfBiteCount = 0;               // 0x03002B70, チェンジウルフの噛みつき回数
COMMON_DATA u16 ALIGNED(4) gSabataDefence = 0;          // 0x03002B74, サバタの防御力
COMMON_DATA u16 ALIGNED(4) gSunGaugeOverrideTimer = 0;  // 0x03002B78, Cmd_898D が 0 に戻す
COMMON_DATA u16 ALIGNED(4) gGoodFrom = 0;               // 0x03002B7C
COMMON_DATA u16 ALIGNED(4) gSunGaugeOverride = 0;       // 0x03002B80, ApplyLxModifiers が 1 なら太陽レベル +4、2 なら日光なしにする
COMMON_DATA u16 ALIGNED(4) gWindPushThreshold = 0;      // 0x03002B84, Player_InitEffects が 1 を入れる
COMMON_DATA u16 ALIGNED(4) gChangeWolfRebite = 0;       // 0x03002B88, チェンジウルフに関連するフラグ
COMMON_DATA u16 ALIGNED(4) gGoodCondTimer = 0;          // 0x03002B8C, Player.goodCondTimer の退避
COMMON_DATA u16 ALIGNED(4) gWindAngle = 0;              // 0x03002B90, Player_InitEffects が 0 に戻す
COMMON_DATA u16 ALIGNED(8) gPlayerCount = 0;            // 0x03002B98, Playerの数, シングルプレイ中は1, 通信対戦中時は参加人数になる
COMMON_DATA u8 u8_03002b9a[6] = {};                     // todo
COMMON_DATA u16 gBadCondTimer[3] = {};                  // 0x03002BA0, Player がいないときに Cmd_650B が書き込む退避先
COMMON_DATA u8 u8_03002ba6[2] = {};                     // todo
COMMON_DATA Entity5941Node* gCWolfTarget = NULL;        // 0x03002BA8, チェンジウルフで噛みつく相手のノード, Player_Destroy が NULL に戻す
COMMON_DATA u16 gWindStrength = 0;                      // 0x03002BAC, Player_InitEffects が 0 に戻す
COMMON_DATA u8 u8_03002bae[2] = {};                     // todo
COMMON_DATA u16 gSavedMagicEnchanted = 0;               // 0x03002BB0, Player.magic.enchanted の退避, Player_SaveState が写し Player_RefreshMagicInfo が戻す, Player_GetEquippedMagic がサバタのとき 0 に戻す
COMMON_DATA u8 u8_03002bb2[14] = {};                    // todo
COMMON_DATA u32 gPlayerStates[4] = {};                  // 0x03002BC0, Playerごとのビットフラグ, FUN_080093f8 が bit0 と bit1-2 を見る
COMMON_DATA u16 gSunMagicUsed = 0;                      // 0x03002BD0, Cmd_898D が 0 に戻す
COMMON_DATA u8 u8_03002bd2[14] = {};                    // todo
COMMON_DATA Player* gPlayerPtr[4] = {};                 // 0x03002BE0, 通信対戦時に自分が子機の場合も自キャラが 0 になるかは不明
COMMON_DATA u16 gRisingSunCount = 0;                    // 0x03002BF0, 0 以外かつ gSunGaugeOverride が 1 のとき Entity0809eb24_Update が unk_29 を立てる
COMMON_DATA u8 u8_03002bf2[2] = {};                     // todo
COMMON_DATA u16 gChangeWolfBiting = 0;                  // 0x03002BF4, Player_Destroy が 0 に戻す
COMMON_DATA u8 u8_03002bf6[2] = {};                     // todo

static void Player_SetAction(Player* p, u32 action, u32 state);

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

static inline bool32 HasGoodCond(Player* p, u32 id) {
  if (p->goodCondTimer != 0 && p->goodCondID == id) {
    return TRUE;
  }
  return FALSE;
}

// 食らい判定の無敵時間を設定する
static inline void Player_SetInvincibleTime(Player* p, u16 time) { p->hurtbox.invincibleTime = time; }

// pos のブロックのコリジョンタイルを引く, 差し替えがあればそちら, マップ外なら tiles[0]
// Map_GetTileHeightAt (src/collision_map.c) の前半と同じ処理だが, 原典ではこの関数の中に2回展開されているのでインラインで持つ
static inline CollisionMapTile* Player_GetTileAt(Vec3* pos) {
  MapTileOverride* ov;
  s32 bx;
  s32 bz;
  s32 idx;

  bx = (s8)(pos->x >> 8);
  bz = (s8)(pos->z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }

  ov = Map_FindTileOverride(idx, 1);
  if (ov != NULL) {
    return &ov->tile;
  }
  return &gCollisionMap->tiledata->tiles[idx];
}

void Player_SetAnimFacing(Player* p) {
  u8 v = p->facing;

  if (v > 4) {
    p->animIDOffset = 8 - v;
    p->xflip = TRUE;
  } else {
    p->animIDOffset = v;
    p->xflip = FALSE;
  }
}

// 残差1命令ぶんのレジスタ順だけ (57対57), 原典は adds r2, r1, r2 (引数の animIdx が第1被演算子) だが, こちらは adds r2, r2, r1 で animIDOffset が先に来る
// Tier A-B は試済 (animIdx + p->animIDOffset と p->animIDOffset + animIdx の両方: gcc がどちらもフィールド先に正規化する). animIDOffset をローカルに受けると第1被演算子は変わるが ldrb が human / humanGfx のアドレス計算より前に出てしまう
NON_MATCH bool32 Player_PlayAnim(Player* p, u32 animIdx, s32 animSpeed) {
#ifdef NONMATCHING_C
  MainAnimPlayFlags16 flags = 0;

  if (p->animID == animIdx) {
    flags = MAIN_ANIM_KEEP_FRAME;
  }
  p->animID = animIdx;

  MainSprite_SetAnim(&p->human, &p->humanGfx, animIdx + p->animIDOffset, PLAYMODE_LOOP, flags);
  if (p->xflip) {
    p->human.flags |= SPRFLAG_XFLIP;
  } else {
    p->human.flags &= ~SPRFLAG_XFLIP;
  }

  MainSprite_SetAnimSpeed(&p->human, (u16)animSpeed);
  return MainSprite_AdvanceAnim(&p->human, &p->humanGfx);
#else
  INCFUNC("asm/func/Player_PlayAnim.inc");
#endif
}

// 向きと速さから mover.delta を作る, 階段タイルの上では上りで 52/64, 下りで 40/64 に変える
// 残差4命令 (102/106): 原典は p を ip に置いたまま回すのでレジスタ圧が高く, こちらは低位レジスタで足りてしまう
// Tier A/B は試済
NON_MATCH void Player_SetMoveDelta(Player* p, s32 val) {
#ifdef NONMATCHING_C
  s32 angle = ((p->facing + 5) & 7) * 32;

  p->mover.delta.x = POLAR_X(val, angle);
  p->mover.delta.z = POLAR_Z(val, angle);

  if (p->tile.stairs[1] == 1) {
    s32 v;

    if (p->mover.delta.z < 0) {
      v = p->mover.delta.z * 40;
    } else {
      v = p->mover.delta.z * 52;
    }
    p->mover.delta.z = FixToInt(6, v);
  } else if (p->tile.stairs[1] == 2) {
    s32 v;

    if (p->mover.delta.x < 0) {
      v = p->mover.delta.x * 40;
    } else {
      v = p->mover.delta.x * 52;
    }
    p->mover.delta.x = FixToInt(6, v);
  }
#else
  INCFUNC("asm/func/Player_SetMoveDelta.inc");
#endif
}

static void Player_SetAction(Player* p, u32 action, u32 state) {
  p->action = action;
  p->state = state;
  p->stateTimer = 0;
}

// 行動を始める前のフラグ初期化, 日光と武器効果を見て flag20 を組み立て直し各種タイマを 0 に戻す
void Player_BeginAction(Player* p) {
  p->flag20 = PFLAG20_UNK_0;
  if (KAAMOS(p->isSabata) == 0 && FUN_0809e138(p)) {
    Player_SetFlag20(p, PFLAG20_SUNBATHING);
  }
  if (Player_TestEquipBuff(p, EBUFF_SKULLSUIT)) {
    Player_SetFlag20(p, PFLAG20_SNEAKING);
  }

  VEC3_SET(p->shadowOffset, 0, 0, 0);
  p->flag35a = 0;
  p->hurtbox.hitState &= ~HBHITSTATE_UNK_1;
}

void Player_SetFlag35a(Player* p, u32 val) { p->flag35a |= val; }

u32 Player_TestFlag35a(Player* p, u32 mask) { return p->flag35a & mask; }

// エネルギーチャージ音を止める
void Player_StopEneChargeSound(Player* p) {
  if (p->kind != PLAYER_SABATA) {
    sound_08240740(NOISE_SOLAR_CHARGE);
    return;
  }
  sound_08240740(SONG_569);
  sound_08240740(SONG_514);
  sound_08240740(SONG_870);
}

// 被弾側 b から攻撃側 a を向く向きを 1/3/5/7 の斜め4方向に丸めて返す, 同じ位置なら b->angle から作る
u32 Player_GetDirToAttacker(HitboxData* a, HitboxData* b) {
  s32 angle;
  s32 dx;
  s32 dz;

  if (a->flags & HBFLAG_ANGLE) {
    angle = a->angle + 0xE0;
    return ((angle & 0xFF) >> 6) * 2 + 1;
  }

  dx = a->center.x - b->center.x;
  dz = a->center.z - b->center.z;
  if (dx == 0 && dz == 0) {
    angle = b->angle + 0xE0;
    return ((angle & 0xFF) >> 6) * 2 + 1;
  }

  angle = ArcTan2_8(dx, dz) + 0x60;
  return ((angle & 0xFF) >> 6) * 2 + 1;
}

// 被弾したときの向きと退避処理, 攻撃側 a のダメージを被弾側 b に移してから向きを決める
void Player_SetupKnockback(Player* p, HitboxData* a, HitboxData* b) {
  b->knockbackPower = a->knockbackPower;
  if (a->knockbackPower > 200) {
    b->knockbackPower = 200;
  }

  if (Hitbox_TestAttr(a, HBATTR_18)) {
    p->blownAway = 1;
    p->facing = Player_GetDirToAttacker(a, b);
    return;
  }

  if (p->action == PACT_UNK_5) {
    b->flags |= HBFLAG_HIDDEN;
    b->knockbackPower = 0;
    return;
  }

  if (Player_TestFlag20(p, PFLAG20_UNK_15)) {
    if (a->flags & HBFLAG_ANGLE) {
      p->knockbackDir = ((((a->angle + 0x10) & 0xFF) >> 5) + 3) & 7;
    } else {
      s32 dx = a->center.x - b->center.x;
      s32 dz = a->center.z - b->center.z;

      if (dx == 0 && dz == 0) {
        p->knockbackDir = p->facing;
      } else {
        p->knockbackDir = (((((((u16)ArcTan2_8(dx, dz) + 0x10) & 0xFF) >> 5) + 3) & 7) + 4) & 7;
      }
    }

    p->knockbackSpeed = b->knockbackPower;
    b->knockbackPower = 0;
    b->flags |= HBFLAG_HIDDEN;
    return;
  }

  p->blownAway = 0;
  p->facing = Player_GetDirToAttacker(a, b);
}

// 夜の間に効果を発揮するものの判定に利用
bool32 Player_IsNight(Player* p) {
  u32 span;

  if (KAAMOS(p->isSabata) > 0) return TRUE;
  if (Player_TestEquipBuff(p, EBUFF_ALLNIGHT)) return TRUE;

  span = Time_GetSpanOfTime();
  if (span == TIME_UNK4 || span == TIME_UNK5 || span == TIME_NIGHT) {
    return TRUE;
  }
  return FALSE;
}

static s32 GetPlayerCoffinID(void) {
  s32 slot;
  for (slot = 0; slot < VALUABLE_CAP; slot++) {
    u32 itemID = GetValuableItemID(slot);
    if ((itemID - ITEM_OAK_COFFIN) < COFFIN_NUM) {
      return itemID - ITEM_OAK_COFFIN;
    }
  }
  return COFFIN_OAK;
}

void FUN_08060e90(Player* p, u32 val) {
  if (p->scriptID_9c4 != 0) {
    ScriptArgs args;
    u32 argv;
    args.argc = 1;
    argv = val;
    args.argv = &argv;
    VM_ExecByID(p->scriptID_9c4, &args);
  }
}

void FUN_08060ec8(Player* p, u32 val) { p->unk_9bc |= val; }

u32 FUN_08060ed8(Player* p, u32 mask) { return p->unk_9bc & mask; }

void FUN_08060ee8(Player* p) {
  if (p->scriptID_9c0 != 0) {
    VM_ExecByID(p->scriptID_9c0, NULL);
  }
}

// ステータス値を割り振りとドーピングから作り直す, サバタはレベルから4つに均等割りする
// 残差3命令 (79/76): p が r6 に入るため (原典は r5) &p->stats を kind (0x358) のレジスタ +4 で作れず 0x35C を組み直す
// Tier A-C は試済
NON_MATCH void Player_RefreshStats(Player* p) {
#ifdef NONMATCHING_C
  s32 i;

  if (p->kind != PLAYER_SABATA) {
    for (i = 0; i < STAT_KINDS; i++) {
      p->stats[i] = gStat->stats[i] + gStat->statBonus[i];
      if (p->stats[i] > 99) {
        p->stats[i] = 99;
      }
    }
  } else {
    s32 lv = gStat->lv + 10;
    s32 total;
    s32 base;
    s32 rem;

    if (lv > 99) {
      lv = 99;
    }

    total = (lv - 1) * 3;
    base = Div(total, 4);
    rem = total - base * 4;
    base += 10;

    for (i = 0; i < STAT_KINDS; i++) {
      p->stats[i] = gStat->statBonus[i] + base;
      if (rem > 0) {
        p->stats[i]++;
        rem--;
      }
      if (p->stats[i] > 99) {
        p->stats[i] = 99;
      }
    }
  }
#else
  INCFUNC("asm/func/Player_RefreshStats.inc");
#endif
}

static s32 CalcMaxHP(Player* p) {
  s32 val;
  PlayerArmor* armor = &p->armor;
  if (p->kind == PLAYER_SOLAR_DJANGO) {
    val = (p->stats[STAT_VITALITY] + armor->bonus[STAT_VITALITY]) + armor->sideBonus[STAT_VITALITY];
  } else {
    val = (p->stats[STAT_VITALITY] + armor->bonus[STAT_VITALITY]) - armor->sideBonus[STAT_VITALITY];
  }
  if (99 < val) {
    val = 99;
  }
  return val * 10;
}

static s32 CalcMaxEne(Player* p) {
  s32 val;
  PlayerArmor* armor = &p->armor;
  if (gGameFlags & FLAG030047A4_UNK_12) {
    return 10;
  }

  if (p->kind == PLAYER_SOLAR_DJANGO) {
    val = (p->stats[STAT_SPIRIT] + armor->bonus[STAT_SPIRIT]) + armor->sideBonus[STAT_SPIRIT];
  } else {
    val = (p->stats[STAT_SPIRIT] + armor->bonus[STAT_SPIRIT]) - armor->sideBonus[STAT_SPIRIT];
  }
  if (99 < val) {
    val = 99;
  }
  return val * 5 + 100;
}

static void UpdateMaxHPEne(Player* p) {
  p->maxHP = CalcMaxHP(p);
  if (p->hp > p->maxHP) p->hp = p->maxHP;

  p->maxEne = CalcMaxEne(p);
  if (p->ene > p->maxEne) p->ene = p->maxEne;
}

// HP/Ene の最大値を計算し直し, セーブ値 (スクリプトが指定していれば満タン) を入れて上限で丸める
void Player_RefreshHpEne(Player* p) {
  p->maxHP = CalcMaxHP(p);
  if (VM_GetNamedArgValue('l', 0) != 0) {
    p->hp = p->maxHP;
  } else if (p->kind == PLAYER_SABATA) {
    p->hp = gStat->sabataHP;
  } else {
    p->hp = gStat->savedHP;
  }

  if (p->hp == 0) {
    p->hp = 1;
  } else if (p->hp > p->maxHP) {
    p->hp = p->maxHP;
  }

  p->maxEne = CalcMaxEne(p);
  if (VM_GetNamedArgValue('e', 0) != 0) {
    p->ene = p->maxEne;
  } else if (p->kind == PLAYER_SABATA) {
    p->ene = gStat->sabataEne;
  } else {
    p->ene = gStat->savedEne;
  }

  if (p->ene > p->maxEne) {
    p->ene = p->maxEne;
  }
}

// 防御力と属性を当たり判定に設定する, レベルとハヤサの平均に鎧の値を足した値が防御力になる
// 命令数は107で一致, 残差はレジスタ割当だけ: 原典は armor を r5, lv を r4, special を r3 (caller-saved) に置くが
// こちらは armor を r4, special を call-saved の r5 に取る. PlayerArmor を 0x27A まで広げて命令数は揃った, Tier A/B は試済
NON_MATCH void Player_RefreshDefence(Player* p) {
#ifdef NONMATCHING_C
  PlayerArmor* armor = &p->armor;
  s32 lv;
  s32 power;
  HitboxAttributes attrs;
  u32 weakness;
  bool32 isEmperor;  // 皇帝のカード(全属性に耐性)の効果発動中かどうか

  if (p->kind == PLAYER_SABATA) {  // サバタの場合、常にジャンゴのレベル+10　
    lv = gStat->lv + 10;
    if (lv > 99) {
      lv = 99;
    }
    power = p->stats[3];
    attrs = p->hbattrs | HBATTR_DARK;
    weakness = HBATTR_SOL;
  } else {
    lv = gStat->lv;
    if (p->kind == PLAYER_SOLAR_DJANGO) {
      power = p->stats[STAT_AGILITY] + armor->bonus[STAT_AGILITY] + armor->sideBonus[STAT_AGILITY];
      attrs = p->hbattrs | HBATTR_SOL;
      weakness = HBATTR_DARK;
    } else {
      power = p->stats[STAT_AGILITY] + armor->bonus[STAT_AGILITY] - armor->sideBonus[STAT_AGILITY];
      attrs = p->hbattrs | HBATTR_DARK;
      weakness = HBATTR_SOL;
    }
  }

  isEmperor = FALSE;
  if (p->goodCondTimer != 0 && p->goodCondID == GOOD_EMPEROR) {
    isEmperor = TRUE;
  }
  if (isEmperor || p->hbattrs == HBATTR_ALL) {
    attrs = HBATTR_ALL;
  }

  if (power > 99) {
    power = 99;
  }
  power = ((power + lv) >> 1) + armor->defence;
  if (p->kind == PLAYER_SABATA) {
    gSabataDefence = power;
  }

  Hitbox_SetPowerAndAttributes(&p->hurtbox, power, attrs, weakness);
#else
  INCFUNC("asm/func/Player_RefreshDefence.inc");
#endif
}

void FUN_08061294(Player* p) {
  Player_RefreshHpEne(p);
  Player_RefreshDefence(p);
}

void FUN_080612a8(Player* p) {
  UpdateMaxHPEne(p);
  Player_RefreshDefence(p);
}

// プレイヤーの全パラメータを再計算する
void Player_RefreshAllStats(Player* p) {
  Player_RefreshStats(p);
  UpdateMaxHPEne(p);
  Player_RefreshDefence(p);
}

// プレイヤーが太陽に焼かれているときの煙を出す
void Player_EmitBurnSmoke(Player* p) {
  Vec3 size, pos;

  if (p->kind == PLAYER_BAT || p->kind == PLAYER_MOUSE) {
    pos = p->beast.pos;
    VEC3_SET(size, Q8(0.125), Q8(0.125), Q8(0.125));
  } else {
    pos = p->mover.pos;
    pos.y += Q8(0.313);
    VEC3_SET(size, Q8(0.25), Q8(0.235), Q8(0.25));
  }

  EmitSmoke(&pos, 1, &size, 0, 0, Q8(0.05), 2, 2);
}

// 0x64C のパーティクルを1フレーム進める, 4フレームごとにパレットを1段ずらし6フレーム過ぎたら消す
// 残差1命令 (42/43): 原典は `adds r4, r0, #1` と加算先を別レジスタにするが, こちらは `adds r1, #1` で上書きする
// u8 の一時変数に取る形だと切り捨てが strb の前に出てしまい逆に遠ざかる, Tier A/B と C のローカル化は試済
NON_MATCH void Player_UpdatePtcl64c(Player* p) {
#ifdef NONMATCHING_C
  if (p->ptcl_64c.active == 0) {
    return;
  }

  p->ptcl_64c.timer++;
  if (p->ptcl_64c.timer > 5) {
    p->ptcl_64c.ptcl.flags |= SPRFLAG_HIDDEN;
    p->ptcl_64c.active = 0;
    return;
  }

  Particle_SetPose(&p->ptcl_64c.ptcl, p->ptcl_64c.group1, (p->ptcl_64c.timer >> 2) + p->ptcl_64c.frameBase);
#else
  INCFUNC("asm/func/Player_UpdatePtcl64c.inc");
#endif
}

// 0x64C のパーティクルを pos に出す, big なら別のパレットを使う
void Player_ShowPtcl64c(Player* p, Vec3* pos, s32 big) {
  Particle* ptcl = &p->ptcl_64c.ptcl;

  if (big) {
    p->ptcl_64c.frameBase = 0x48;
  } else {
    p->ptcl_64c.frameBase = 4;
  }

  Particle_SetPose(ptcl, p->ptcl_64c.group1, p->ptcl_64c.frameBase);
  ptcl->pos = *pos;
  ptcl->flags &= ~SPRFLAG_HIDDEN;
  p->ptcl_64c.active = TRUE;
  p->ptcl_64c.timer = 0;
}

// 0x64C のパーティクルを確保して隠した状態で初期化する
void FUN_08061458(Player* p) {
  ParticleGroup* group = GetParticleGroup(PTCL_GROUP_1);
  Particle* ptcl;

  p->ptcl_64c.group1 = group;
  ptcl = &p->ptcl_64c.ptcl;
  Particle_Add(ptcl, group, 0);
  Particle_SetOffset(ptcl, -4, -4);
  Particle_SetPose(ptcl, p->ptcl_64c.group1, 4);
  ptcl->flags |= SPRFLAG_HIDDEN;
  ptcl->priority = 1;
  ptcl->offsetZ = 0x14;
  p->ptcl_64c.active = 0;
  p->ptcl_64c.timer = 0;
}

// 混乱時に、周囲を回るパーティクルを1つ出し続ける
// 残差1命令 (157/156): Y方向の割り算の結果を置くレジスタだけ違う (原典は r0, こちらは r1)
// 代入を枝ごとに書く形は逆に離れた, Tier A/B は試済
NON_MATCH void Player_UpdateConfusePtcl(Player* p) {
#ifdef NONMATCHING_C
  s32 angle;

  if (p->ptcl_67c.active) {
    if (p->mode != PMODE_ACTIVE || p->badCondTimer[BAD_CONFUSE] == 0) {
      p->ptcl_67c.ptcl.flags |= SPRFLAG_HIDDEN;
      p->ptcl_67c.active = FALSE;
      return;
    }

    angle = (p->ptcl_67c.timer * 5) & 0xFF;

    p->ptcl_67c.ptcl.pos.x = p->mover.pos.x + POLAR_X(Q8(0.22), angle);
    p->ptcl_67c.ptcl.pos.y = POLAR_Z(Q8(0.274), angle) + Q8(1.37) + p->mover.pos.y;
    p->ptcl_67c.ptcl.pos.z = p->mover.pos.z - POLAR_X(Q8(0.22), angle);

    p->ptcl_67c.timer++;
    return;
  }

  if (p->mode != PMODE_ACTIVE || p->badCondTimer[BAD_CONFUSE] == 0) {
    return;
  }

  p->ptcl_67c.ptcl.pos = p->mover.pos;
  p->ptcl_67c.ptcl.pos.x += Q8(0.22);
  p->ptcl_67c.ptcl.pos.y += Q8(1.37);
  p->ptcl_67c.ptcl.flags &= ~SPRFLAG_HIDDEN;
  Particle_SetPose(&p->ptcl_67c.ptcl, p->ptcl_67c.group1, 0x10);
  p->ptcl_67c.timer = 0;
  p->ptcl_67c.active = TRUE;
#else
  INCFUNC("asm/func/Player_UpdateConfusePtcl.inc");
#endif
}

// 0x67C のパーティクルを確保して隠した状態で初期化する
void FUN_0806161c(Player* p) {
  ParticleGroup* group = GetParticleGroup(PTCL_GROUP_1);
  Particle* ptcl;

  p->ptcl_67c.group1 = group;
  ptcl = &p->ptcl_67c.ptcl;
  Particle_Add(ptcl, group, 0);
  Particle_SetOffset(ptcl, -4, -4);
  Particle_SetPose(ptcl, p->ptcl_67c.group1, 0x10);
  ptcl->flags |= SPRFLAG_HIDDEN;
  ptcl->priority = 1;
  ptcl->offsetZ = 0x14;
  p->ptcl_67c.active = 0;
  p->ptcl_67c.timer = 0;
}

// 衝撃波のアニメーションを1フレーム進める, 終端まで行くと finished を立てて消す
// 衝撃波のアニメーションを1コマ進める, 末尾まで行ったら消して finished を落とす
void PlayerShockwave_UpdateAnim(PlayerShockwave* p) {
  if (!p->finished) {
    return;
  }

  if (AuxSprite_AdvanceAnim(&p->sprite, &p->anim)) {
    p->finished = FALSE;
    p->sprite.flags |= SPRFLAG_HIDDEN;
    return;
  }

  p->sprite.pos.x += p->vel.x;
  p->sprite.pos.z += p->vel.z;
}

// finished が立っていれば下ろし, 立っていなければ衝撃波を消す
void PlayerShockwave_UpdateFlash(PlayerShockwave* p) {
  if (p->finished) {
    p->finished = FALSE;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
}

// 攻撃の向き dir から衝撃波スプライトのパラメータ2つを決める
void Player_GetShockwaveDirParams(u32 dir, s32* result1, s32* result2) {
  s32 axis = dir & 3;

  switch (axis) {
    case 0: {
      *result1 = 0;
      break;
    }
    case 1: {
      *result1 = 1;
      break;
    }
    case 2: {
      *result1 = 2;
      break;
    }
    default: {
      *result1 = 1;
      break;
    }
  }

  if (dir <= 2) {
    *result2 = 0;
  } else if (dir == 3 || dir == 4) {
    *result2 = 2;
  } else if (dir == 5) {
    *result2 = 3;
  } else {
    *result2 = 1;
  }
}

// 衝撃波のスプライトに本体と同じパレットを渡して表示する
void FUN_0806181c(Player* p) {
  p->meleeShockwave.gfx.plttID = p->human.plttID;
  p->meleeShockwave.gfx.pltt = p->human.pltt;
  AuxSprite_Show(&p->meleeShockwave.sprite);
  p->meleeShockwave.finished = TRUE;
}

// 黒ジャンゴが剣で攻撃する時に1回呼ばれる, 衝撃波を向きに応じてずらして出す
void Player_SpawnSwordShockwave(Player* p, u32 idx, Vec3* pos) {
  AuxSprite* sprite = &p->meleeShockwave.sprite;
  s32 angle = ((p->facing + 5) & 7) * 32;
  s32 variant;
  s32 flags;

  sprite->pos = *pos;
  sprite->pos.y += Q8(0.743);
  sprite->pos.x += POLAR_X(Q8(0.94), angle);
  sprite->pos.z += POLAR_Z(Q8(0.94), angle);
  p->meleeShockwave.vel.x = POLAR_X(Q8(0.04), angle);
  p->meleeShockwave.vel.z = POLAR_Z(Q8(0.04), angle);

  Player_GetShockwaveDirParams(idx, &variant, &flags);
  AuxAnim_SetAnim(&p->meleeShockwave.anim, p->meleeShockwave.animFile, 0, variant, flags);
  FUN_0806181c(p);
}

// 黒ジャンゴが槍で攻撃する時に1回呼ばれる, n で衝撃波の高さと前に出る距離が変わる
void Player_SpawnSpearShockwave(Player* p, u32 idx, Vec3* pos, s32 n) {
  AuxSprite* sprite = &p->meleeShockwave.sprite;
  s32 height;
  s32 dist;
  s32 angle;
  s32 variant;
  s32 flags;

  if (n == 0) {
    height = Q8(0.625);
    dist = Q8(1.76);
  } else if (n == 1) {
    height = Q8(0.55);
    dist = Q8(1.321);
  } else {
    height = Q8(0.47);
    dist = Q8(0.875);
  }

  angle = ((p->facing + 5) & 7) * 32;

  sprite->pos = *pos;
  sprite->pos.y += height;
  sprite->pos.x += POLAR_X(dist, angle);
  sprite->pos.z += POLAR_Z(dist, angle);
  p->meleeShockwave.vel.x = POLAR_X(Q8(0.04), angle);
  p->meleeShockwave.vel.z = POLAR_Z(Q8(0.04), angle);

  Player_GetShockwaveDirParams(idx, &variant, &flags);
  AuxAnim_SetAnim(&p->meleeShockwave.anim, p->meleeShockwave.animFile, 1, variant, flags);
  FUN_0806181c(p);
}

// Player_SpawnSwordShockwave のような関数だが、いつ呼ばれるか不明 (武器の攻撃ではない)
// 衝撃波を pos から向きの反対側に少しずらして出す
void Player_SpawnShockwaveBehind(Player* p, u32 idx, Vec3* pos) {
  AuxSprite* sprite = &p->meleeShockwave.sprite;
  s32 angle = ((p->facing + 5) & 7) * 32;
  sprite->pos = *pos;

  sprite->pos.x += POLAR_X(180, angle);
  sprite->pos.z += POLAR_Z(180, angle);

  p->meleeShockwave.vel.x = 0;
  p->meleeShockwave.vel.z = 0;
  AuxAnim_SetAnim(&p->meleeShockwave.anim, p->meleeShockwave.animFile, 2, 0, 0);
  FUN_0806181c(p);
}

// 多分、サバタが攻撃する時に呼ばれる
// サバタの攻撃時に散弾スプライトを pos の少し上に置いて表示する
void Player_ShowGunSpread(Player* p, u32 _, Vec3* pos) {
  p->meleeShockwave.sprite.flags &= ~SPRFLAG_HIDDEN;
  p->meleeShockwave.sprite.pos = *pos;
  p->meleeShockwave.sprite.pos.y += 0xE6;
  p->meleeShockwave.sprite.rotation = p->wpn.gunSpreadAngle;
  p->meleeShockwave.finished = TRUE;
}

void FUN_08061b98(Player* p) { AuxSprite_Remove(&(p->meleeShockwave).sprite); }

// 衝撃波スプライトを用意する, サバタは散弾の1枚絵, それ以外はアニメーション付き
void Player_InitShockwave(Player* p) {
  AuxSprite* sprite = &p->meleeShockwave.sprite;
  AuxSpriteGfx* gfx = &p->meleeShockwave.gfx;

  if (p->kind == PLAYER_SABATA) {
    Video_GetAuxSprite(gfx, SPRITE_GUN_SPREAD);
    AuxSprite_Add(sprite, gfx, SPRFLAG_NO_CLIP | SPRFLAG_AFFINE | SPRFLAG_HIDDEN);
    sprite->poseIdx = 4;
    Video_SetAuxSpritePltt(gfx, 50);
    sprite->priority = 1;
    sprite->scaleY = 0x7F;
    sprite->scaleX = 0x7F;
    sprite->pos = p->mover.pos;
    p->meleeShockwave.update = PlayerShockwave_UpdateFlash;
  } else {
    Video_GetAuxSprite(gfx, SPRITE_MELEE_SHOCKWAVE);
    AuxSprite_Add(sprite, gfx, SPRFLAG_HIDDEN);
    Video_SetAuxSpritePltt(gfx, 29);
    p->meleeShockwave.animFile = GetFile(DIR_ANIMATION, ANIM_0837);
    p->meleeShockwave.update = PlayerShockwave_UpdateAnim;
  }

  p->meleeShockwave.finished = FALSE;
}

// 0x718 のパーティクルを1フレーム進める, 12フレームで消え 6フレーム目でパレットを1段進める
// 残差10命令 (76/86): 原典は生存数を高位レジスタ r8 に置き (push が1組増える), 要素のアドレスを r3/r4 の2本に複写している
// Tier A/B は試済, ローカルを増やして原典のレジスタ圧を再現する形は未発見
NON_MATCH void Player_UpdatePtcl718(Player* p) {
#ifdef NONMATCHING_C
  s32 alive;
  s32 i;

  if (!p->ptcl_718.active) {
    return;
  }

  alive = 0;
  for (i = 0; i < 6; i++) {
    Particle52* ptcl;

    if (!p->ptcl_718.ptcls[i].active) {
      continue;
    }

    ptcl = &p->ptcl_718.ptcls[i];
    ptcl->unk_31++;
    if (ptcl->unk_31 > 0xB) {
      ptcl->base.flags |= SPRFLAG_HIDDEN;
      ptcl->active = FALSE;
      continue;
    }

    if (ptcl->unk_31 == 6) {
      Particle_SetPose(&ptcl->base, p->ptcl_718.group, ptcl->frameBase + 1);
    }

    ptcl->base.pos.x += ptcl->vel.x;
    ptcl->base.pos.y += ptcl->vel.y;
    ptcl->base.pos.z += ptcl->vel.z;
    alive++;
  }

  if (alive == 0) {
    p->ptcl_718.active = FALSE;
  }
#else
  INCFUNC("asm/func/Player_UpdatePtcl718.inc");
#endif
}

// 0x718 のパーティクルを1つ使って pos / vel を入れて出す, 使う番号は 0..5 を巡回する
void Player_SpawnPtcl718(Player* p, Vec3* pos, Vec3* vel, s32 frameStep) {
  Particle52* ptcl = &p->ptcl_718.ptcls[p->ptcl_718.next];

  ptcl->base.flags &= ~SPRFLAG_HIDDEN;
  ptcl->frameBase = frameStep * 2 + 2;
  Particle_SetPose(&ptcl->base, p->ptcl_718.group, ptcl->frameBase);
  ptcl->base.pos = *pos;
  ptcl->vel = *vel;
  ptcl->unk_31 = 0;
  ptcl->active = TRUE;
  p->ptcl_718.active = TRUE;
  p->ptcl_718.next++;
  if (p->ptcl_718.next > 5) {
    p->ptcl_718.next = 0;
  }
}

void FUN_08061db4(Player* p) {
  s32 i;

  for (i = 0; i < 6; i++) {
    Particle_Remove(&p->ptcl_718.ptcls[i].base);
  }
}

// 0x718 のパーティクル6個を確保して初期化する
void Player_InitPtcl718(Player* p) {
  PlayerParticleState718* st = &p->ptcl_718;
  s32 i;

  st->group = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 6; i++) {
    Particle52* ptcl = &st->ptcls[i];

    Particle_Add(&ptcl->base, st->group, SPRFLAG_HIDDEN);
    Particle_SetOffset(&ptcl->base, -4, -4);
    Particle_SetPltt(&ptcl->base, 1);
    ptcl->base.priority = 2;
  }

  st->active = FALSE;
  st->next = 0;
}

// 0x858 のパーティクルを pos_930 へ寄せながら1フレーム進める, 寄り切ったものは消す
// 残差9命令 (141/150): 原典は gSineTable と 0xFF と生存数を r8-r10 に抱えるが, agbcc はループ内で作り直す
// Tier A/B は試済
NON_MATCH void Player_UpdatePtcl858(Player* p) {
#ifdef NONMATCHING_C
  s32 alive;
  s32 i;

  if (!p->ptcl_858.active) {
    return;
  }

  alive = 0;
  for (i = 0; i < 4; i++) {
    PlayerPtcl858* ptcl = &p->ptcl_858.ptcls[i];
    s32 angle;

    if (!ptcl->active) {
      continue;
    }

    if (abs(ptcl->offset.x) <= 15 && abs(ptcl->offset.z) <= 15) {
      ptcl->base.flags |= SPRFLAG_HIDDEN;
      ptcl->active = FALSE;
      continue;
    }

    angle = ArcTan2_8(ptcl->offset.x, ptcl->offset.z);

    ptcl->offset.x -= POLAR_X(ptcl->speed, angle);
    ptcl->offset.z -= POLAR_Z(ptcl->speed, angle);

    ptcl->base.pos.x = ptcl->offset.x + p->pos_930.x;
    ptcl->base.pos.z = ptcl->offset.z + p->pos_930.z;

    ptcl->timer++;
    if (ptcl->timer == 4) {
      Particle_SetPose(&ptcl->base, p->ptcl_858.group, ptcl->frameBase + 1);
    }

    alive++;
  }

  if (alive == 0) {
    p->ptcl_858.active = FALSE;
  }
#else
  INCFUNC("asm/func/Player_UpdatePtcl858.inc");
#endif
}

// 太陽ゲージのぶんカウンタを溜め, 0x27 を超えたら 0x858 のパーティクルを1つ出す
// 残差9命令 (153/162): Player_SpawnPtcl858 と同じで, 原典は p と pos を r8/r9 に置くがこちらは r8 だけで足りる
NON_MATCH void Player_SpawnSunPtcl858(Player* p, Vec3* pos) {
#ifdef NONMATCHING_C
  PlayerPtcl858* ptcl;
  u16* table;
  u32 idx;
  s32 angle;
  s32 dist;

  p->ptcl_858.unk_06 += gStat->sunGauge + 2;
  if (p->ptcl_858.unk_06 <= 0x27) {
    return;
  }

  ptcl = &p->ptcl_858.ptcls[p->ptcl_858.unk_05];
  ptcl->base.flags &= ~SPRFLAG_HIDDEN;
  ptcl->frameBase = 2;
  Particle_SetPose(&ptcl->base, p->ptcl_858.group, 2);

  table = gRandomTable;
  idx = (gRandTableIdx + 1) & 0x3FF;
  angle = (u8)table[idx];
  gRandTableIdx = (idx + 1) & 0x3FF;
  dist = (table[gRandTableIdx] & 0x3F) + 0x80;

  ptcl->offset.x = POLAR_X(dist, angle);
  ptcl->offset.z = POLAR_Z(dist, angle);

  ptcl->base.pos = *pos;
  ptcl->base.pos.x += ptcl->offset.x;
  ptcl->base.pos.z += ptcl->offset.z;

  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  ptcl->speed = (gRandomTable[gRandTableIdx] & 3) + 0xE;
  ptcl->timer = 0;
  ptcl->active = TRUE;
  p->ptcl_858.unk_05++;
  if (p->ptcl_858.unk_05 > 3) {
    p->ptcl_858.unk_05 = 0;
  }

  p->ptcl_858.unk_06 -= 0x28;
  p->ptcl_858.active = TRUE;
#else
  INCFUNC("asm/func/Player_SpawnSunPtcl858.inc");
#endif
}

// 4フレームごとに 0x858 のパーティクルを1つ, pos からランダムな向き・距離だけ離して置く
// 残差7命令 (144/151): 原典は p と pos を r8/r9 に置くが, こちらは r8 だけで足りてしまう
NON_MATCH void Player_SpawnPtcl858(Player* p, Vec3* pos) {
#ifdef NONMATCHING_C
  PlayerPtcl858* ptcl;
  u16* table;
  u32 idx;
  s32 angle;
  s32 dist;

  p->ptcl_858.unk_06++;
  if ((p->ptcl_858.unk_06 & 3) != 0) {
    return;
  }

  ptcl = &p->ptcl_858.ptcls[p->ptcl_858.unk_05];
  ptcl->base.flags &= ~SPRFLAG_HIDDEN;
  ptcl->frameBase = 4;
  Particle_SetPose(&ptcl->base, p->ptcl_858.group, 4);

  table = gRandomTable;
  idx = (gRandTableIdx + 1) & 0x3FF;
  angle = (u8)table[idx];
  gRandTableIdx = (idx + 1) & 0x3FF;
  dist = (table[gRandTableIdx] & 0x7F) + 0x100;

  ptcl->offset.x = POLAR_X(dist, angle);
  ptcl->offset.z = POLAR_Z(dist, angle);

  ptcl->base.pos = *pos;
  ptcl->base.pos.x += ptcl->offset.x;
  ptcl->base.pos.z += ptcl->offset.z;

  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  ptcl->speed = (gRandomTable[gRandTableIdx] & 7) + 0x1C;
  ptcl->timer = 0;
  ptcl->active = TRUE;
  p->ptcl_858.active = TRUE;
  p->ptcl_858.unk_05++;
  if (p->ptcl_858.unk_05 > 3) {
    p->ptcl_858.unk_05 = 0;
  }
#else
  INCFUNC("asm/func/Player_SpawnPtcl858.inc");
#endif
}

void FUN_08062258(Player* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->ptcl_858.ptcls[i].base);
  }
}

// 0x858 のパーティクル4個を確保して初期化する
void Player_InitPtcl858(Player* p) {
  PlayerParticleState858* st = &p->ptcl_858;
  s32 i;

  st->group = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 4; i++) {
    PlayerPtcl858* ptcl = &st->ptcls[i];

    Particle_Add(&ptcl->base, st->group, SPRFLAG_HIDDEN);
    Particle_SetOffset(&ptcl->base, -4, -4);
    Particle_SetPltt(&ptcl->base, 1);
    ptcl->base.priority = 2;
  }

  st->unk_05 = 0;
  st->unk_06 = 0;
}

// 自前のパレット pltt_2a4 を作る, unk_94e のぶん全チャンネルを明るくし, unk_359 が 0 なら色5/6/13 は触らない
// 残差5命令 (159/154): 原典は高位レジスタを r8 の1本で済ませているが, こちらは r9 も使ってしまう
// Tier A/B と dst のローカル化有無は試済
NON_MATCH void Player_BuildPltt(Player* p) {
#ifdef NONMATCHING_C
  rgb555* src = &gObjPlttData[p->plttIDs[p->unk_94c] * 16];
  s32 i;

  if (p->unk_94e == 0) {
    if (p->useAuxSprite == 0) {
      for (i = 0; i < 16; i++) {
        if (i != 5 && i != 6 && i != 13) {
          p->pltt_2a4[i] = src[i];
        }
      }
    } else {
      for (i = 0; i < 16; i++) {
        p->pltt_2a4[i] = src[i];
      }
    }
  } else if (p->useAuxSprite == 0) {
    for (i = 0; i < 16; i++) {
      if (i != 5 && i != 6 && i != 13) {
        u16 c = src[i];
        s32 r = (c & 0x1F) + p->unk_94e;
        s32 g;
        s32 b;

        if (r > 0x1F) {
          r = 0x1F;
        }
        g = ((c >> 5) & 0x1F) + p->unk_94e;
        if (g > 0x1F) {
          g = 0x1F;
        }
        b = ((c >> 10) & 0x1F) + p->unk_94e;
        if (b > 0x1F) {
          b = 0x1F;
        }
        p->pltt_2a4[i] = (b << 10) | (g << 5) | r;
      }
    }
  } else {
    for (i = 0; i < 16; i++) {
      u16 c = src[i];
      s32 r = (c & 0x1F) + p->unk_94e;
      s32 g;
      s32 b;

      if (r > 0x1F) {
        r = 0x1F;
      }
      g = ((c >> 5) & 0x1F) + p->unk_94e;
      if (g > 0x1F) {
        g = 0x1F;
      }
      b = ((c >> 10) & 0x1F) + p->unk_94e;
      if (b > 0x1F) {
        b = 0x1F;
      }
      p->pltt_2a4[i] = (b << 10) | (g << 5) | r;
    }
  }
#else
  INCFUNC("asm/func/Player_BuildPltt.inc");
#endif
}

// 屋外かどうかと PFLAG20 の 0x10 で 0 / 4 / 8 を返す
u32 FUN_0806241c(Player* p) {
  u32 r = 0;

  if (!TestMapFlag(MPF_OUTDOOR)) {
    if (p->flag20 & PFLAG20_SUNBATHING) {
      r = 8;
    }
  } else {
    if (p->flag20 & PFLAG20_SUNBATHING) {
      r = 4;
    }
  }

  return r;
}

// unk_950 ごとに3色ずつ並んだ表から、パレットの5,6,13番を差し替える
void FUN_08062468(Player* p) {
  rgb555* src = &gObjPlttData[40 * 16];

  src += p->unk_950 * 3;

  p->pltt_2a4[5] = *src++;
  p->pltt_2a4[6] = src[0];
  p->pltt_2a4[13] = src[1];
}

// src と pltt_2a4 を wSrc:wBase の比で混ぜて pltt_2a4[16..31] に作り, スプライトのパレットをそこへ向ける
// unk_359 が 0 なら色5/6/13 は混ぜずにそのまま写す
// 残差2命令 (227/225): レジスタ割当とスタック使用量だけ (原典は p を sl, wSrc を ip に置いて 0x14 で足りている)
// 添字でなくカーソル (src++/base++) にすると命令数はここまで詰まった, Tier A/B は試済
NON_MATCH void Player_BlendPltt(Player* p, u16* src, s32 wSrc, s32 wBase, u32 shift) {
#ifdef NONMATCHING_C
  rgb555* base;
  s32 i;

  if (wSrc == 0) {
    if (p->useAuxSprite == 0) {
      p->human.pltt = p->pltt_2a4;
    } else {
      p->beastGfx->pltt = p->pltt_2a4;
    }
    return;
  }

  if (p->useAuxSprite == 0) {
    base = p->pltt_2a4;
    for (i = 0; i < 16; i++) {
      if (i == 5 || i == 6 || i == 13) {
        base[16] = base[0];
      } else {
        u16 c = src[0];
        u16 d;
        s32 r = (c & 0x1F) + p->unk_94e;
        s32 g;
        s32 b;

        if (r > 0x1F) {
          r = 0x1F;
        }
        g = ((c >> 5) & 0x1F) + p->unk_94e;
        if (g > 0x1F) {
          g = 0x1F;
        }
        b = ((c >> 10) & 0x1F) + p->unk_94e;
        if (b > 0x1F) {
          b = 0x1F;
        }

        d = base[0];
        base[16] = ((((b * wSrc) + (((d >> 10) & 0x1F) * wBase)) >> shift) << 10) | ((((g * wSrc) + (((d >> 5) & 0x1F) * wBase)) >> shift) << 5) | (((r * wSrc) + ((d & 0x1F) * wBase)) >> shift);
      }

      src++;
      base++;
    }
    p->human.pltt = &p->pltt_2a4[16];
  } else {
    base = p->pltt_2a4;
    for (i = 0; i < 16; i++) {
      u16 c = src[0];
      u16 d;
      s32 r = (c & 0x1F) + p->unk_94e;
      s32 g;
      s32 b;

      if (r > 0x1F) {
        r = 0x1F;
      }
      g = ((c >> 5) & 0x1F) + p->unk_94e;
      if (g > 0x1F) {
        g = 0x1F;
      }
      b = ((c >> 10) & 0x1F) + p->unk_94e;
      if (b > 0x1F) {
        b = 0x1F;
      }

      d = base[0];
      base[16] = ((((b * wSrc) + (((d >> 10) & 0x1F) * wBase)) >> shift) << 10) | ((((g * wSrc) + (((d >> 5) & 0x1F) * wBase)) >> shift) << 5) | (((r * wSrc) + ((d & 0x1F) * wBase)) >> shift);

      src++;
      base++;
    }
    p->beastGfx->pltt = &p->pltt_2a4[16];
  }
#else
  INCFUNC("asm/func/Player_BlendPltt.inc");
#endif
}

// 毎フレームのパレット更新, エンチャントの色と変身の色をクロスフェードさせる
// 残差1命令 (259/258): p と n のレジスタが入れ替わっているだけ (原典は p が r5)
// Player_CheckMagicEnchant の宣言を外すと streamdiff は完全一致する (Player_GetMagicAction と同じ現象)
NON_MATCH void Player_UpdatePltt(Player* p, u32 n) {
#ifdef NONMATCHING_C
  u32 bright;
  s32 w;
  rgb555* src;
  s32 cost;
  s32 i;

  if (p->unk_951 != p->unk_950) {
    p->unk_950 = p->unk_951;
    FUN_08062468(p);
  }

  bright = FUN_0806241c(p);
  if (p->unk_94c != n || p->unk_94e != bright) {
    p->unk_94c = n;
    p->unk_94e = bright;
    Player_BuildPltt(p);
  }

  if (p->plttFlashTimer != 0) {
    p->enchantPlttTimer = 0;
    if (p->plttFlashTimer > 31) {
      src = &gObjPlttData[p->plttID_95e * 16];
      if (p->useAuxSprite == 0) {
        for (i = 0; i < 16; i++) {
          if (i == 5 || i == 6 || i == 13) {
            p->pltt_2a4[16 + i] = p->pltt_2a4[i];
          } else {
            p->pltt_2a4[16 + i] = src[i];
          }
        }
        p->human.pltt = &p->pltt_2a4[16];
      } else {
        for (i = 0; i < 16; i++) {
          p->pltt_2a4[16 + i] = src[i];
        }
        p->beastGfx->pltt = &p->pltt_2a4[16];
      }
    } else {
      src = &gObjPlttData[p->plttID_95e * 16];
      w = p->plttFlashTimer;
      Player_BlendPltt(p, src, w, 0x20 - w, 5);
    }

    p->plttFlashTimer--;
    return;
  }

  cost = Player_CheckMagicEnchant(p);
  if (cost >= 0) {
    p->enchantPlttID = cost + 0x121;
    src = &gObjPlttData[p->enchantPlttID * 16];
    if (p->enchantPlttTimer <= 0x1F) {
      w = p->enchantPlttTimer;
    } else if (p->enchantPlttTimer <= 0x2F) {
      w = 0x20;
    } else if (p->enchantPlttTimer <= 0x4F) {
      w = 0x50 - p->enchantPlttTimer;
    } else {
      w = 0;
    }

    Player_BlendPltt(p, src, w, 0x20 - w, 5);
    p->enchantPlttTimer++;
    if (p->enchantPlttTimer > 0x5F) {
      p->enchantPlttTimer = 0;
    }
    return;
  }

  if (p->enchantPlttTimer >= 1 && p->enchantPlttTimer <= 0x4F) {
    src = &gObjPlttData[p->enchantPlttID * 16];
    if (p->enchantPlttTimer >= 0x21 && p->enchantPlttTimer <= 0x2F) {
      p->enchantPlttTimer = 0x30;
    }

    if (p->enchantPlttTimer <= 0x20) {
      w = p->enchantPlttTimer;
      p->enchantPlttTimer = w - 1;
    } else {
      w = 0x50 - p->enchantPlttTimer;
      p->enchantPlttTimer++;
      if (p->enchantPlttTimer > 0x4F) {
        p->enchantPlttTimer = 0;
      }
    }

    Player_BlendPltt(p, src, w, 0x20 - w, 5);
    return;
  }

  p->enchantPlttID = 0;
  p->enchantPlttTimer = 0;
  if (p->useAuxSprite == 0) {
    p->human.pltt = p->pltt_2a4;
  } else {
    p->beastGfx->pltt = p->pltt_2a4;
  }
#else
  INCFUNC("asm/func/Player_UpdatePltt.inc");
#endif
}

// 魔法エンチャント中のパレット更新, unk_96c で演出の段階 (1: フェードイン, 2: 点滅) を切り替える
// 残差2命令 (350/348): p が r4 に入る割当差だけ (原典は r5), Player_UpdatePltt と同じ現象でコピー経路が2つあるぶん src の退避が2命令余る
// Tier A-C は試済 (ローカルのスコープ最小化で4命令→2命令, n の符号付け替えは無効)
NON_MATCH void FUN_080628ec(Player* p, u32 n) {
#ifdef NONMATCHING_C
  u32 bright;

  if (p->unk_951 != p->unk_950) {
    p->unk_950 = p->unk_951;
    FUN_08062468(p);
  }

  bright = FUN_0806241c(p);
  if (p->unk_94c != n || p->unk_94e != bright) {
    p->unk_94c = n;
    p->unk_94e = bright;
    Player_BuildPltt(p);
  }

  if (p->unk_96c == 1) {
    rgb555* src;
    s32 w;
    s32 i;

    p->enchantPlttTimer = 0;
    if (p->plttFlashTimer > 31) {
      src = &gObjPlttData[p->plttID_95e * 16];
      if (p->useAuxSprite == 0) {
        for (i = 0; i < 16; i++) {
          if (i == 5 || i == 6 || i == 13) {
            p->pltt_2a4[16 + i] = p->pltt_2a4[i];
          } else {
            p->pltt_2a4[16 + i] = src[i];
          }
        }
        p->human.pltt = &p->pltt_2a4[16];
      } else {
        for (i = 0; i < 16; i++) {
          p->pltt_2a4[16 + i] = src[i];
        }
        p->beastGfx->pltt = &p->pltt_2a4[16];
      }
      return;
    }

    src = &gObjPlttData[p->plttID_95e * 16];
    w = p->plttFlashTimer;
    Player_BlendPltt(p, src, w, 0x20 - w, 5);
    p->plttFlashTimer++;
    return;
  }

  if (p->unk_96c == 2) {
    rgb555* src;
    s32 w;

    p->enchantPlttTimer = 0;
    src = &gObjPlttData[p->plttID_95e * 16];
    if (p->plttFlashTimer <= 31) {
      w = p->plttFlashTimer;
    } else if (p->plttFlashTimer <= 47) {
      w = 0x20;
    } else if (p->plttFlashTimer <= 79) {
      w = 80 - p->plttFlashTimer;
    } else {
      w = 0;
    }

    Player_BlendPltt(p, src, w, 0x20 - w, 5);
    p->plttFlashTimer++;
    if (p->plttFlashTimer > 95) {
      p->plttFlashTimer = 0;
    }
    return;
  }

  if (p->plttFlashTimer != 0) {
    rgb555* src;
    s32 w;
    s32 i;

    p->enchantPlttTimer = 0;
    if (p->plttFlashTimer > 31) {
      src = &gObjPlttData[p->plttID_95e * 16];
      if (p->useAuxSprite == 0) {
        for (i = 0; i < 16; i++) {
          if (i == 5 || i == 6 || i == 13) {
            p->pltt_2a4[16 + i] = p->pltt_2a4[i];
          } else {
            p->pltt_2a4[16 + i] = src[i];
          }
        }
        p->human.pltt = &p->pltt_2a4[16];
      } else {
        for (i = 0; i < 16; i++) {
          p->pltt_2a4[16 + i] = src[i];
        }
        p->beastGfx->pltt = &p->pltt_2a4[16];
      }
    } else {
      src = &gObjPlttData[p->plttID_95e * 16];
      w = p->plttFlashTimer;
      Player_BlendPltt(p, src, w, 0x20 - w, 5);
    }

    p->plttFlashTimer--;
    return;
  }

  if (p->enchantPlttTimer >= 1 && p->enchantPlttTimer <= 0x4F) {
    rgb555* src = &gObjPlttData[p->enchantPlttID * 16];
    s32 w;

    if (p->enchantPlttTimer >= 0x21 && p->enchantPlttTimer <= 0x2F) {
      p->enchantPlttTimer = 0x30;
    }

    if (p->enchantPlttTimer <= 0x20) {
      w = p->enchantPlttTimer;
      p->enchantPlttTimer = w - 1;
    } else {
      w = 0x50 - p->enchantPlttTimer;
      p->enchantPlttTimer++;
      if (p->enchantPlttTimer > 0x4F) {
        p->enchantPlttTimer = 0;
      }
    }

    Player_BlendPltt(p, src, w, 0x20 - w, 5);
    return;
  }

  p->enchantPlttTimer = 0;
  if (p->useAuxSprite == 0) {
    p->human.pltt = p->pltt_2a4;
  } else {
    p->beastGfx->pltt = p->pltt_2a4;
  }
#else
  INCFUNC("asm/func/FUN_080628ec.inc");
#endif
}

void Player_SetBasePlttID(Player* p) {
  if (p->inputIdx == 0) {
    p->plttID_94a = 29;
  } else {
    p->plttID_94a = 40;
  }
}

// ロックマンコラボの鎧を装備すると、プレイヤーのパレットIDが対応するものに変更される
// 例: ロックパワー(EBUFF_MEGAPOWER) は ロックマンと同じ青色
void Player_SetPlttIDs(Player* p) {
  switch (p->kind) {
    case PLAYER_SOLAR_DJANGO: {
      if (Player_TestEquipBuff(p, EBUFF_MEGAPOWER)) {
        p->plttIDs[0] = 296;
      } else if (Player_TestEquipBuff(p, EBUFF_GUTSPOWER)) {
        p->plttIDs[0] = 297;
      } else if (Player_TestEquipBuff(p, EBUFF_PROTOPOWER)) {
        p->plttIDs[0] = 298;
      } else if (Player_TestEquipBuff(p, EBUFF_TOADPOWER)) {
        p->plttIDs[0] = 299;
      } else {
        p->plttIDs[0] = 29;
      }
      p->plttIDs[1] = 289, p->plttIDs[2] = 32, p->plttIDs[3] = 291, p->plttIDs[4] = 292, p->plttIDs[5] = 31, p->plttIDs[6] = 33, p->plttIDs[7] = 30;
      break;
    }
    case PLAYER_DARK_DJANGO: {
      if (Player_TestEquipBuff(p, EBUFF_MEGAPOWER)) {
        p->plttIDs[0] = 296;
      } else if (Player_TestEquipBuff(p, EBUFF_GUTSPOWER)) {
        p->plttIDs[0] = 297;
      } else if (Player_TestEquipBuff(p, EBUFF_PROTOPOWER)) {
        p->plttIDs[0] = 298;
      } else if (Player_TestEquipBuff(p, EBUFF_TOADPOWER)) {
        p->plttIDs[0] = 299;
      } else {
        p->plttIDs[0] = 38;
      }
      p->plttIDs[1] = 289, p->plttIDs[2] = 32, p->plttIDs[3] = 291, p->plttIDs[4] = 292, p->plttIDs[5] = 31, p->plttIDs[6] = 33, p->plttIDs[7] = 30;
      break;
    }
    case PLAYER_BAT: {
      if (Player_TestEquipBuff(p, EBUFF_MEGAPOWER)) {
        p->plttIDs[0] = 623;
      } else if (Player_TestEquipBuff(p, EBUFF_GUTSPOWER)) {
        p->plttIDs[0] = 624;
      } else if (Player_TestEquipBuff(p, EBUFF_PROTOPOWER)) {
        p->plttIDs[0] = 622;
      } else if (Player_TestEquipBuff(p, EBUFF_TOADPOWER)) {
        p->plttIDs[0] = 625;
      } else {
        p->plttIDs[0] = 614;
      }
      p->plttIDs[1] = 621, p->plttIDs[2] = 619, p->plttIDs[3] = 616, p->plttIDs[4] = 617, p->plttIDs[5] = 618, p->plttIDs[6] = 620, p->plttIDs[7] = 615;
      break;
    }
    case PLAYER_MOUSE: {
      if (Player_TestEquipBuff(p, EBUFF_MEGAPOWER)) {
        p->plttIDs[0] = 296;
      } else if (Player_TestEquipBuff(p, EBUFF_GUTSPOWER)) {
        p->plttIDs[0] = 297;
      } else if (Player_TestEquipBuff(p, EBUFF_PROTOPOWER)) {
        p->plttIDs[0] = 298;
      } else if (Player_TestEquipBuff(p, EBUFF_TOADPOWER)) {
        p->plttIDs[0] = 299;
      } else {
        p->plttIDs[0] = 29;
      }
      p->plttIDs[1] = 289, p->plttIDs[2] = 32, p->plttIDs[3] = 291, p->plttIDs[4] = 292, p->plttIDs[5] = 31, p->plttIDs[6] = 33, p->plttIDs[7] = 30;
      break;
    }
    case PLAYER_SLEEPING: {
      p->plttIDs[0] = 519 + p->coffin;
      p->plttIDs[1] = 527;
      p->plttIDs[2] = 519 + p->coffin;
      p->plttIDs[3] = 519 + p->coffin;
      p->plttIDs[4] = 519 + p->coffin;
      p->plttIDs[5] = 519 + p->coffin;
      p->plttIDs[6] = 519 + p->coffin;
      p->plttIDs[7] = 519 + p->coffin;
      break;
    }
    case PLAYER_SABATA: {
      p->plttIDs[0] = 39;
      p->plttIDs[1] = 289;
      p->plttIDs[2] = 32;
      p->plttIDs[3] = 291;
      p->plttIDs[4] = 292;
      p->plttIDs[5] = 31;
      p->plttIDs[6] = 33;
      p->plttIDs[7] = 30;
      break;
    }
  }
}

// スプライトのパレットを自前の pltt_2a4 に差し替えて初期状態に戻す
void Player_ResetPltt(Player* p) {
  Player_SetBasePlttID(p);
  Player_SetPlttIDs(p);
  p->unk_94c = 0xFFFF;
  p->unk_950 = 0xFF;
  p->human.plttID = p->plttID_94a;
  p->human.pltt = p->pltt_2a4;
  p->beastGfx->plttID = p->plttID_94a;
  p->beastGfx->pltt = p->pltt_2a4;
  Player_UpdatePltt(p, 0);
}

// 変身エフェクトの粒を弾けさせる, kind 1 なら消えかけさせるだけ
// 残差2命令 (134/132): 原典は高位レジスタを r8-r10 の3本使うが, プロトタイプありで呼ぶと2本で足りてしまう
// Eff082473e0Emitter_BurstParticle の宣言を外すと streamdiff は完全一致する (暗黙宣言のときだけ原典のレジスタ圧になる)
NON_MATCH void Player_BurstFormEffect(Player* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  Vec3 vel;
  Vec3 velRange;
  Vec3* src;
  u16* table;
  u32 idx;

  if (p->emitter.kind == 1) {
    Eff082473e0Emitter_FadeParticle(&p->emitter);
    return;
  }

  if (p->emitter.kind == 2) {
    PlaySound_082406e0(SE_308);
  } else if (p->emitter.kind == 3) {
    PlaySound_082406e0(SE_308);
  }

  src = p->emitter.pos;
  pos.x = src->x;
  pos.y = src->y + 0x80;
  pos.z = src->z;

  table = gRandomTable;
  idx = (gRandTableIdx + 1) & 0x3FF;
  vel.x = (table[idx] & 0xF) - 7;
  idx = (idx + 1) & 0x3FF;
  vel.y = (table[idx] & 0x1F) - 0x10;
  gRandTableIdx = (idx + 1) & 0x3FF;
  vel.z = (table[gRandTableIdx] & 0xF) - 7;

  velRange.x = 5, velRange.y = 0xA, velRange.z = 5;
  Eff082473e0Emitter_BurstParticle(&p->emitter, 3, &pos, &vel, &velRange, 0x28, 0x28);
#else
  INCFUNC("asm/func/Player_BurstFormEffect.inc");
#endif
}

void FUN_08063220(Player* p) {
  s32 count = p->emitter.unk_3;
  s32 i;

  for (i = 0; i < count; i++) {
    Player_BurstFormEffect(p);
  }
}

void FUN_08063248(Player* p) {
  if (p->emitter.kind == 1) {
    Eff082473e0Emitter_Reset(&p->emitter);
  } else {
    s32 count = p->emitter.unk_3;
    s32 i;

    for (i = 0; i < count; i++) {
      Player_BurstFormEffect(p);
    }
  }
}

// 変身エフェクトを kind で開始する, 変身の種類ごとに粒のばらけ方と効果音を変える
// 残差3命令 (187/190): 原典は p と kind を r8/r9 に置くが, こちらは r8 だけで足りてしまう
NON_MATCH void Player_StartFormEffect(Player* p, u32 kind) {
#ifdef NONMATCHING_C
  Vec3 spread;
  u16* table;
  u32 idx;

  if (p->emitter.unk_3 != 0) {
    if (p->emitter.kind != kind) {
      if (p->emitter.kind == 3) {
        return;
      }
      FUN_08063248(p);
    }
  }

  if (p->emitter.unk_3 == 0) {
    p->mashCountBase = p->mashCount;
    p->unk_3da = 0;
  }

  if (p->kind == PLAYER_BAT) {
    table = gRandomTable;
    idx = (gRandTableIdx + 1) & 0x3FF;
    spread.x = (table[idx] & 7) - 3;
    gRandTableIdx = (idx + 1) & 0x3FF;
    spread.y = (table[gRandTableIdx] & 7) - 5;
  } else if (p->kind == PLAYER_MOUSE) {
    table = gRandomTable;
    idx = (gRandTableIdx + 1) & 0x3FF;
    spread.x = (table[idx] & 7) - 3;
    gRandTableIdx = (idx + 1) & 0x3FF;
    spread.y = (table[gRandTableIdx] & 7) - 3;
  } else {
    table = gRandomTable;
    idx = (gRandTableIdx + 1) & 0x3FF;
    spread.x = (table[idx] & 0xF) - 7;
    gRandTableIdx = (idx + 1) & 0x3FF;
    spread.y = -(table[gRandTableIdx] & 0x1F);
  }

  spread.z = 0;
  if (FUN_082467d0(&p->emitter, kind, 0xE10, &spread) >= 0) {
    if (p->emitter.kind == 1) {
      PlaySound_082406e0(SE_IGNITE);
    } else if (p->emitter.kind == 2) {
      p->damage += 10;
      PlaySound_082406e0(SE_SOLIDIFY);
    } else if (p->emitter.kind == 3) {
      PlaySound_082406e0(SE_SOLIDIFY);
    }

    p->badCondTimer[1] = 0;
  }
#else
  INCFUNC("asm/func/Player_StartFormEffect.inc");
#endif
}

s32 Player_GetMashCount(Player* p) { return (p->mashCount - p->mashCountBase + 0x100) & 0xFF; }

// 姿勢を決める, 変化直後は 0x40 フレームのあいだ 4フレームおきに前の値と交互に返す
u32 Player_ApplyPoseHold(Player* p, u32 n) {
  static const u8 u8_ARRAY_085abab4[4] = {3, 4, 6, 0};  // 0x085ABAB4

  u32 pose = n;

  if (p->emitter.unk_3 != 0) {
    if (p->mode & PMODE_ACTIVE) {
      if (Player_GetMashCount(p) >= u8_ARRAY_085abab4[p->emitter.kind - 1]) {
        Player_BurstFormEffect(p);
        p->mashCountBase = p->mashCount;
      }
    }

    if (p->emitter.unk_3 != 0) {
      if (p->emitter.kind == 1) {
        pose = 3;
      } else if (p->emitter.kind == 2) {
        pose = 4;
      } else if (p->emitter.kind == 3) {
        pose = 5;
      }
    }
  }

  if (p->speedPenalty != 0) {
    pose = 7;
  }

  if (pose == n) {
    if (p->altPoseTimer != 0) {
      if ((p->altPoseTimer >> 2) & 1) {
        pose = p->altPose;
      }
      p->altPoseTimer--;
    }
  } else {
    p->altPose = pose;
    p->altPoseTimer = 0x40;
  }

  return pose;
}

// 状態異常 badcondID を frames フレームかける, 1 は変身を解き 2 は向きをランダムに変える
// 残差1命令 (76/76), gRandomTable のアドレスを原典は r2 に置くがこちらは r1, Random() で書くと gConfusedDir のアドレスを先に作る順序は一致した
// Tier A-C は試済 (加算の順序, % 8, Mod の結果をローカルへ, _Random(table), 連鎖代入はいずれも悪化)
NON_MATCH void Player_ApplyBadCondition(Player* p, s32 badcondID, s32 frames) {
#ifdef NONMATCHING_C
  switch (badcondID) {
    case BAD_HARAITA: {
      break;
    }
    case BAD_POISON: {
      if (p->emitter.unk_3 != 0) {
        if (p->emitter.kind == 3) {
          break;
        }
        FUN_08063220(p);
      }
      if (p->badCondTimer[BAD_POISON] == 0) {
        p->poisonTick = 0;
      }
      break;
    }
    case BAD_CONFUSE: {
      if (p->badCondTimer[BAD_CONFUSE] == 0) {
        gConfusedDir = (p->controlUp + 1 + Mod(Random(), 7)) & 7;
        p->controlUp = gConfusedDir;
        PlaySound_082406e0(SE_CONFUSE);
      }
      break;
    }
    default: {
      return;
    }
  }

  p->badCondTimer[badcondID] = frames;
#else
  INCFUNC("asm/func/Player_ApplyBadCondition.inc");
#endif
}

void Player_ClearBadCondition(Player* p, s32 badcondID) {
  p->badCondTimer[badcondID] = 0;
  if (badcondID == BAD_CONFUSE) {
    p->controlUp = gStat->controlUp;
  }
}

// 太陽ゲージの消費と状態異常の残り時間を1フレーム進め, その結果で姿勢番号を上書きして返す
u32 Player_TickBadCondTimers(Player* p, u32 n) {
  s32 i;

  if (KAAMOS(p->isSabata) > 0) {
    if (p->mode & PMODE_ACTIVE) {
      if (KAAMOS(p->isSabata) <= gStat->sunGauge) {
        KAAMOS(p->isSabata) = 0;
      } else {
        KAAMOS(p->isSabata) -= gStat->sunGauge;
      }
    }
    n = 6;
    p->sunDrainBlinkTimer = 64;
  } else if (p->sunDrainBlinkTimer != 0) {
    if ((p->sunDrainBlinkTimer >> 2) & 1) {
      n = 6;
    }
    p->sunDrainBlinkTimer--;
  }

  for (i = 0; i < 3; i++) {
    switch (i) {
      case BAD_POISON: {
        if (p->badCondTimer[BAD_POISON] != 0) {
          if (p->mode & PMODE_ACTIVE) {
            p->badCondTimer[BAD_POISON]--;
          }
          n = 2;
          p->badCondBlinkTimer = 64;
        } else if (p->badCondBlinkTimer != 0) {
          if ((p->badCondBlinkTimer >> 2) & 1) {
            n = 2;
          }
          p->badCondBlinkTimer--;
        }
        break;
      }
      case BAD_HARAITA: {
        if (p->badCondTimer[BAD_HARAITA] != 0 && (p->mode & PMODE_ACTIVE)) {
          p->badCondTimer[BAD_HARAITA]--;
          if (p->input->down & DPAD_ANY) {
            MosaicFader_Start(2, 1, 0x1E, p->mosaicFrom, p->unk_980, p->mosaicInterval);
          }
        }
        break;
      }
      case BAD_CONFUSE: {
        if (p->badCondTimer[BAD_CONFUSE] != 0 && (p->mode & PMODE_ACTIVE)) {
          p->badCondTimer[BAD_CONFUSE]--;
          if (p->badCondTimer[BAD_CONFUSE] == 0) {
            p->controlUp = gStat->controlUp;
          }
        }
        break;
      }
    }
  }

  return n;
}

// flashTimer が動いている間, 4フレームごとに pose を flashPose と入れ替える (点滅)
// 残差は共有された return pose のブロック位置だけ (23/23), Tier A の分岐形 4通りと Tier B は試済, sabata.c の LinkPlayer_ApplyFlashPose も同じ残差
NON_MATCH u32 Player_ApplyFlashPose(Player* p, u32 pose) {
#ifdef NONMATCHING_C
  if (p->flashTimer != 0) {
    p->flashTimer--;
    if ((p->flashTimer >> 2) & 1) {
      return p->flashPose;
    }
  }

  return pose;
#else
  INCFUNC("asm/func/Player_ApplyFlashPose.inc");
#endif
}

// 変身の拡縮演出を1フレーム進める, goodCondID が GOOD_MINI の間は縮み, それ以外では元の大きさへ戻る
// 残差4命令 (186/190): レジスタ割当 (原典は p を r4) と定数の作り直し
// 分岐の並び (goodCondTimer != 0 を先) は原典と一致した, Tier A/B は試済
NON_MATCH void Player_UpdateFormScale(Player* p) {
#ifdef NONMATCHING_C
  s32 scale;

  if (p->goodCondTimer != 0) {
    if (p->goodCondID == GOOD_MINI) {
      if (p->unk_97a <= 0x3F) {
        if (p->unk_97a == 0) {
          PlaySound_082406e0(SONG_494);
          p->unk_3f1 = 1;
        }
        p->unk_97a++;
      }

      p->human.flags |= SPRFLAG_AFFINE;
      scale = 0x40 - (p->unk_97a >> 1);
      p->human.scaleX = scale;
      p->human.scaleY = scale;
      p->flag20 |= (PFLAG20_SNEAKING | PFLAG20_UNK_18);
    } else if (p->unk_97a != 0) {
      if (p->unk_3f1 != 0) {
        PlaySound_082406e0(SONG_822);
        p->unk_3f1 = 0;
      }

      p->unk_97a--;
      if (p->unk_97a == 0) {
        p->human.flags &= ~(SPRFLAG_HIDDEN | SPRFLAG_AFFINE);
        scale = Q6(1);
      } else {
        p->human.flags |= SPRFLAG_AFFINE;
        scale = Q6(1) - (p->unk_97a >> 1);
      }
      p->human.scaleX = scale;
      p->human.scaleY = scale;
    }

    if (p->goodCondID == GOOD_INVISIBLE) {
      p->human.flags |= SPRFLAG_BLINK_ODD;
      p->flag20 |= PFLAG20_INVISIBLE;
    } else {
      p->human.flags &= ~SPRFLAG_BLINK_ODD;
    }

    if (p->mode & PMODE_ACTIVE) {
      p->goodCondTimer--;
    }
  } else {
    if (p->unk_97a != 0) {
      if (p->unk_3f1 != 0) {
        PlaySound_082406e0(SONG_822);
        p->unk_3f1 = 0;
      }

      p->unk_97a--;
      if (p->unk_97a == 0) {
        p->human.flags &= ~(SPRFLAG_HIDDEN | SPRFLAG_AFFINE);
        scale = Q6(1);
      } else {
        p->human.flags |= SPRFLAG_AFFINE;
        scale = Q6(1) - (p->unk_97a >> 1);
      }
      p->human.scaleX = scale;
      p->human.scaleY = scale;
    }

    if (p->human.flags & SPRFLAG_BLINK_ODD) {
      p->human.flags &= ~SPRFLAG_BLINK_ODD;
    }
  }
#else
  INCFUNC("asm/func/Player_UpdateFormScale.inc");
#endif
}

void Player_CountMash(Player* p) {
  if (p->input->pressed & (A_BUTTON | B_BUTTON | DPAD_RIGHT | DPAD_LEFT | DPAD_UP | DPAD_DOWN)) {
    p->mashCount++;
  }
}

// Player の毎フレーム更新のうち, 姿勢の決定・パーティクル・影の位置合わせをまとめた部分
void Player_UpdatePoseAndShadow(Player* p) {
  s32 pose = 0;

  if (p->mover.unk_4 == 0) {
    Player_UpdateFormScale(p);
    Player_CountMash(p);
    pose = Player_TickBadCondTimers(p, 0);
    pose = Player_ApplyPoseHold(p, pose);
    pose = Player_ApplyFlashPose(p, pose);
  } else if (KAAMOS(p->isSabata) > 0) {
    pose = 6;
  }

  if (p->mode == PMODE_LOCKED) {
    FUN_080628ec(p, pose);
  } else {
    Player_UpdatePltt(p, pose);
  }

  Player_UpdatePtcl64c(p);
  Player_UpdateConfusePtcl(p);
  Player_UpdatePtcl718(p);
  Player_UpdatePtcl858(p);
  p->meleeShockwave.update(&p->meleeShockwave);

  if (p->unk_992 != 0) {
    p->unk_992--;
    if (p->unk_992 == 0) {
      p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 0x7F, 0, 0, 0, 0x50);
    }
  }

  p->shadowPos.x = p->mover.pos.x + p->shadowOffset.x;
  p->shadowPos.y = p->mover.pos.y + p->shadowOffset.y;
  p->shadowPos.z = p->mover.pos.z + p->shadowOffset.z;
}

// Player が抱えているエフェクト・影・パーティクル・衝撃波をまとめて片付ける
void Player_DestroyEffects(Player* p) {
  Eff082473e0Emitter_Destroy(&p->emitter);
  ParticleShadow_Remove(&p->shadow);
  Particle_Remove(&p->ptcl_64c.ptcl);
  Particle_Remove(&p->ptcl_67c.ptcl);
  FUN_08061db4(p);
  FUN_08062258(p);
  FUN_08061b98(p);
}

// Player の生成直後にエフェクト・影・パーティクル・モザイクの初期値をまとめて入れる
// 残差3行 (153/153): 判定を bool32 のローカルに入れると命令数は一致する
// 残るのは movs r1,#0 の位置だけで, 原典は 0x446 のプール定数に使った r1 をそのまま結果に使い回す (こちらは別レジスタを取る)
NON_MATCH void Player_InitEffects(Player* p) {
#ifdef NONMATCHING_C
  bool32 valid;

  if (p->useAuxSprite == 1) {
    Eff082473e0Emitter_Init(&p->emitter, &p->beast.pos, 0, 0, 1);
  } else {
    Eff082473e0Emitter_Init(&p->emitter, &p->human.pos, 0, 0, 1);
  }

  p->shadowPos = p->human.pos;
  p->shadowOffset.x = 0, p->shadowOffset.y = 0, p->shadowOffset.z = 0;
  ParticleShadow_Init(&p->shadow, &p->shadowPos, 0);
  Entity080dc44c_Create();

  valid = p->goodCondTimer != 0 && p->goodCondID == 5;
  if (valid) {
    p->unk_97a = 0x40;
    p->unk_3f1 = 1;
  }

  Player_ResetPltt(p);
  FUN_08061458(p);
  FUN_0806161c(p);
  Player_InitPtcl718(p);
  Player_InitPtcl858(p);
  Player_InitShockwave(p);

  p->mosaicFrom[0] = 4;
  p->mosaicFrom[1] = 4;
  p->mosaicFrom[2] = 4;
  p->mosaicFrom[3] = 4;
  p->unk_980[0] = 0;
  p->unk_980[1] = 0;
  p->unk_980[2] = 0;
  p->unk_980[3] = 0;
  p->mosaicInterval[0] = 4;
  p->mosaicInterval[1] = 4;
  p->mosaicInterval[2] = 4;
  p->mosaicInterval[3] = 4;
  p->unk_978 = 0;
  p->pos_970.x = 0;
  p->pos_970.y = 0;
  p->pos_970.z = 0;
  gWindStrength = 0;
  gWindAngle = 0;
  gWindPushThreshold = 1;
  gRisingSunCount = 0;
  p->unk_3ff = 0xFF;
#else
  INCFUNC("asm/func/Player_InitEffects.inc");
#endif
}

u32 Player_WeaponEffectSol(Player* p) { return gStat->sunGauge; }

// 状態異常中や太陽光を浴びている間だけ追加ダメージ 10
u32 Player_WeaponEffectStatCond(Player* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    if (p->badCondTimer[i] != 0) return 10;
  }
  if (KAAMOS(p->isSabata) != 0) return 10;
  if (p->emitter.unk_3 != 0) return 10;
  return 0;
}

u32 Player_WeaponEffectNight(Player* p) {
  if (Player_IsNight(p)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAgility(Player* p) { return p->stats[STAT_AGILITY] >> 3; }

u32 Player_WeaponEffectVitality(Player* p) { return p->stats[STAT_VITALITY] >> 3; }

u32 Player_WeaponEffectSpirit(Player* p) { return p->stats[STAT_SPIRIT] >> 3; }

u32 Player_WeaponEffectENE(Player* p) { return Div(p->ene * 10, p->maxEne); }

u32 Player_WeaponEffectHP(Player* p) { return Div(p->hp * 10, p->maxHP); }

// 火事場: HP が減っているほど強くなる
u32 Player_WeaponEffectKajiba(Player* p) { return Div((p->maxHP - p->hp) * 20, p->maxHP); }

// 逆火事場: HP が減っているほど弱くなる
u32 Player_WeaponEffectGyakuKajiba(Player* p) { return -Div((p->maxHP - p->hp) * 40, p->maxHP); }

// 同じ種族の敵をたくさん倒しているほど威力が上がる, 相手の系統に応じた撃破数ボーナス (撃破数/64, 最大10) を返す, 系統が付いていなければ 0
u32 Player_WeaponEffectKillCount(Player* p, HitboxData* _, HitboxData* b) {
  if (Hitbox_TestAttr(b, HBATTR_BEAST)) {
    s32 n = gStat->killCounts[0] >> 6;
    return (n < 10) ? n : 10;
  }
  if (Hitbox_TestAttr(b, HBATTR_THING)) {
    s32 n = gStat->killCounts[1] >> 6;
    return (n < 10) ? n : 10;
  }
  if (Hitbox_TestAttr(b, HBATTR_PHANTOM)) {
    s32 n = gStat->killCounts[2] >> 6;
    return (n < 10) ? n : 10;
  }
  if (Hitbox_TestAttr(b, HBATTR_UNDEAD)) {
    s32 n = gStat->killCounts[3] >> 6;
    return (n < 10) ? n : 10;
  }
  if (Hitbox_TestAttr(b, HBATTR_IMMORTAL)) {
    s32 n = gStat->killCounts[4] >> 6;
    return (n < 10) ? n : 10;
  }
  return 0;
}

// 一定確率で追加ダメージ 10
u32 Player_WeaponEffectRandom(Player* p, HitboxData* a, HitboxData* b) {
  if (Mod(Random(), 100) <= 10) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiBeast(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttr(b, HBATTR_BEAST)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiThing(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttr(b, HBATTR_THING)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiPhantom(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttr(b, HBATTR_PHANTOM)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiUndead(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttr(b, HBATTR_UNDEAD)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiImmortal(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttr(b, HBATTR_IMMORTAL)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectFlame(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttr(a, HBATTR_FLAME)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectFrost(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttr(a, HBATTR_FROST)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectCloud(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttr(a, HBATTR_CLOUD)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectEarth(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttr(a, HBATTR_EARTH)) {
    return 10;
  }
  return 0;
}

// 一定確率で防御無視(なまくら系の特殊効果)
u32 CheckNamakuraProc(Player* p) {
  if (Mod(Random(), 100) <= 10) {
    return HBATTR_NAMAKURA;
  }
  return 0;
}

// 一定確率で麻痺
u32 CheckParalyzeProc(Player* p) {
  if (Mod(Random(), 100) <= 10) {
    return HBATTR_19;
  }
  return 0;
}

// ブラッドソードの吸収, 通常状態でジャンゴなら damage を増やし, それ以外なら HP を1回復して判定を出す
void Player_UpdateBloodSword(Player* p) {
  if (p->mode != PMODE_ACTIVE || !Player_TestEquipBuff(p, EBUFF_BLOOD_SWORD)) {
    return;
  }

  if (p->kind == PLAYER_SOLAR_DJANGO) {
    if (p->hp <= 1) {
      return;
    }
    p->damage++;
  } else {
    if (p->hp >= p->maxHP) {
      return;
    }
    p->hp++;
    CreateDamageNumber(&p->hurtbox, 1, 1, &p->mover.pos, &p->pos_970, p->unk_978);
  }
}

// 装備した武器の特殊効果に応じて, ダメージ計算時に呼ばれるコールバックとフラグを登録する
// 残差1命令 (215/214): agbcc が &w->effects[0] をループ外に括り出す, 原典は ldrb [w + i*4, #0x18] のまま
// Tier A-C は試済 (ループ変数の分離, 効果ID読み出しの inline 化も効果なし)
NON_MATCH void Player_EnableWeaponSpecialEffects(Player* p, WeaponData* w) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
    p->weaponExDamageCb[i] = NULL;
    p->weaponEffectCb2[i] = NULL;
    p->weaponEffectCb3[i] = NULL;
  }
  Player_ClearEquipBuff(p, EBUFF_WET_DURABILITY | EBUFF_WET_ENE_COST | EBUFF_BLOOD_SWORD | EBUFF_ASTRO);

  for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
    switch ((u8)w->effects[i]) {
      case WET_GUN_DEL_SOL:
      case WET_SOL: {
        p->weaponExDamageCb[i] = Player_WeaponEffectSol;
        break;
      }
      case WET_STATCOND: {
        p->weaponExDamageCb[i] = Player_WeaponEffectStatCond;
        break;
      }
      case WET_GUN_DEL_HELL:
      case WET_NIGHT: {
        p->weaponExDamageCb[i] = Player_WeaponEffectNight;
        break;
      }
      case WET_AGILITY: {
        p->weaponExDamageCb[i] = Player_WeaponEffectAgility;
        break;
      }
      case WET_VITALITY: {
        p->weaponExDamageCb[i] = Player_WeaponEffectVitality;
        break;
      }
      case WET_SPIRIT: {
        p->weaponExDamageCb[i] = Player_WeaponEffectSpirit;
        break;
      }
      case WET_ENE: {
        p->weaponExDamageCb[i] = Player_WeaponEffectENE;
        break;
      }
      case WET_HP: {
        p->weaponExDamageCb[i] = Player_WeaponEffectHP;
        break;
      }
      case WET_KAJIBA: {
        p->weaponExDamageCb[i] = Player_WeaponEffectKajiba;
        break;
      }
      case WET_GYAKU_KAJIBA: {
        p->weaponExDamageCb[i] = Player_WeaponEffectGyakuKajiba;
        break;
      }
      case WET_KILLCOUNT: {
        p->weaponEffectCb3[i] = Player_WeaponEffectKillCount;
        break;
      }
      case WET_RANDOM: {
        p->weaponEffectCb3[i] = Player_WeaponEffectRandom;
        break;
      }
      case WET_ANTI_BEAST: {
        p->weaponEffectCb3[i] = Player_WeaponEffectAntiBeast;
        break;
      }
      case WET_ANTI_THING: {
        p->weaponEffectCb3[i] = Player_WeaponEffectAntiThing;
        break;
      }
      case WET_ANTI_PHANTOM: {
        p->weaponEffectCb3[i] = Player_WeaponEffectAntiPhantom;
        break;
      }
      case WET_ANTI_UNDEAD: {
        p->weaponEffectCb3[i] = Player_WeaponEffectAntiUndead;
        break;
      }
      case WET_ANTI_IMMORTAL: {
        p->weaponEffectCb3[i] = Player_WeaponEffectAntiImmortal;
        break;
      }
      case WET_FLAME: {
        p->weaponEffectCb3[i] = Player_WeaponEffectFlame;
        break;
      }
      case WET_FROST: {
        p->weaponEffectCb3[i] = Player_WeaponEffectFrost;
        break;
      }
      case WET_CLOUD: {
        p->weaponEffectCb3[i] = Player_WeaponEffectCloud;
        break;
      }
      case WET_EARTH: {
        p->weaponEffectCb3[i] = Player_WeaponEffectEarth;
        break;
      }
      case WET_NAMAKURA: {
        p->weaponEffectCb2[i] = CheckNamakuraProc;
        break;
      }
      case WET_PARALYZE: {
        p->weaponEffectCb2[i] = CheckParalyzeProc;
        break;
      }
      case WET_DURABILITY: {
        Player_SetEquipBuff(p, EBUFF_WET_DURABILITY);
        break;
      }
      case WET_ENE_COST: {
        Player_SetEquipBuff(p, EBUFF_WET_ENE_COST);
        break;
      }
      case WET_BLOOD_SWORD: {
        Player_SetEquipBuff(p, EBUFF_BLOOD_SWORD);
        break;
      }
      case WET_ASTRO_SWORD: {
        Player_SetEquipBuff(p, EBUFF_ASTRO);
        p->unk_a95 = 0;
        break;
      }
      case WET_ASTRO_SPEAR: {
        Player_SetEquipBuff(p, EBUFF_ASTRO);
        p->unk_a95 = 4;
        break;
      }
      case WET_ASTRO_HAMMER: {
        Player_SetEquipBuff(p, EBUFF_ASTRO);
        p->unk_a95 = 8;
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/Player_EnableWeaponSpecialEffects.inc");
#endif
}

// 武器種ごとに当たり判定の大きさ・位置・属性を設定する, サバタは固定値
// 残差25命令 (224/249): 原典は各 case で Vec3 の半分ずつを and/or で差し込むが, agbcc は定数同士をまとめて1ワードで書いてしまう
// HitboxData* のローカル化は試済
NON_MATCH void Player_SetWeaponHitbox(Player* p) {
#ifdef NONMATCHING_C
  HitboxData* hitbox = &p->wpn.hitbox;
  Vec3 halfSize, offset;
  HitboxAttributes attrs;

  if (p->kind == PLAYER_SABATA) {
    attrs = 0;
    VEC3_SET(halfSize, Q8(0.665), Q8(0.196), Q8(0.665));
    VEC3_SET(offset, 0, Q8(-0.08), 0);
    Hitbox_Init(hitbox, 0, (HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0), 0, 1 << p->mover.unk_4, &halfSize, &offset);
    Hitbox_SetAttack(hitbox, 20, 0x32, 0x10, HBATTR_DARK, 0x14);
    Hitbox_SetHandler(hitbox, NULL, p);
    return;
  }

  if (p->wpn.weaponKind > WK_GUN) {
    return;
  }

  switch (p->wpn.weaponKind) {
    case WK_SWORD: {
      VEC3_SET(halfSize, Q8(0.352), Q8(3.125), Q8(0.352));
      VEC3_SET(offset, 0, Q8(-0.1), 0);
      attrs = 1;
      p->wpn.knockbackPower = 32;
      p->wpn.atkInvincibleTime = 10;
      break;
    }
    case WK_SPEAR: {
      VEC3_SET(halfSize, Q8(0.235), Q8(6.25), Q8(0.235));
      VEC3_SET(offset, 0, 0, 0);
      attrs = 2;
      p->wpn.knockbackPower = 64;
      p->wpn.atkInvincibleTime = 20;
      break;
    }
    case WK_HAMMER: {
      VEC3_SET(halfSize, Q8(0.313), Q8(4.375), Q8(0.313));
      VEC3_SET(offset, 0, Q8(0.12), 0);
      attrs = 4;
      p->wpn.knockbackPower = 48;
      p->wpn.atkInvincibleTime = 20;
      break;
    }
    case WK_OTHERS: {
      VEC3_SET(halfSize, Q8(0.235), Q8(6.25), Q8(0.235));
      VEC3_SET(offset, 0, Q8(-0.313), 0);
      attrs = 8;
      p->wpn.knockbackPower = 1;
      p->wpn.atkInvincibleTime = 5;
      break;
    }
    case WK_GUN: {
      VEC3_SET(halfSize, Q8(0.235), Q8(3.125), Q8(0.235));
      VEC3_SET(offset, 0, Q8(-0.1), 0);
      attrs = 0x10;
      p->wpn.knockbackPower = 32;
      p->wpn.atkInvincibleTime = 20;
      break;
    }
  }

  Hitbox_Init(hitbox, 0, (HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0), 0, 1 << p->mover.unk_4, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, p->wpn.atkPower, p->wpn.knockbackPower, attrs, 0, p->wpn.atkInvincibleTime);
  Hitbox_SetHandler(hitbox, dark_django_0806f990, p);
#else
  INCFUNC("asm/func/Player_SetWeaponHitbox.inc");
#endif
}

void FUN_08064658(Player* p, Weapon* w) { p->wpn.weapon = w; }

void FUN_0806fedc(Player* p);
void FUN_08070844(Player* p);
void FUN_0807106c(Player* p);
void FUN_080713a8(Player* p);
void gun_080715a0(Player* p);

// 装備中の武器の情報を Player に展開する, サバタはガンデルヘル (WEAPON_GUN_DEL_HELL) 固定
void Player_ApplyWeapon(Player* p, Weapon* w) {
  static const PlayerFunc sPlayerAttackUpdates[5] = {
      [WK_SWORD] = FUN_0806fedc,
      [WK_SPEAR] = FUN_08070844,
      [WK_HAMMER] = FUN_0807106c,
      [WK_OTHERS] = FUN_080713a8,
      [WK_GUN] = gun_080715a0,
  };  // 0x085ABAB8

  WeaponData wd;

  if (p->kind != PLAYER_SABATA) {
    FUN_08064658(p, w);
    if (p->wpn.weapon == NULL) {
      wd = gWeaponDB[WEAPON_NONE];
    } else {
      BuildWeaponData(p->wpn.weapon, &wd);
    }
  } else {
    p->wpn.weapon = NULL;
    wd = gWeaponDB[WEAPON_GUN_DEL_HELL];
  }

  p->wpn.weaponID = wd.id;
  p->wpn.weaponKind = wd.kind;
  p->wpn.weaponAtk = wd.atk;
  p->wpn.atkPower = FUN_0807a6cc(&wd);
  Player_EnableWeaponSpecialEffects(p, &wd);

  if (p->wpn.weaponID == WEAPON_MEGA_BUSTER) {
    p->attackCB = FUN_08071b14;
  } else {
    p->attackCB = sPlayerAttackUpdates[p->wpn.weaponKind];
  }

  Player_SetWeaponHitbox(p);
  if (p->action == PACT_ATTACK) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// 攻撃で与えたダメージの分だけ武器を損傷させる, 限界を超えたら品質か特殊効果を1つ失う
// ダメージはジャンゴがバットに攻撃を当てると呼ばれる FUN_0813e944 の 0x0813EFFC で wpn.hitbox.damage に加算される (他の敵も同様と思われる)
void Player_UpdateWeaponWear(Player* p) {
  s32 wear = Hitbox_GetDamage(&p->wpn.hitbox);

  if (wear <= 0) {
    return;
  }

  if (Player_TestEquipBuff(p, EBUFF_WEAPONGUARD)) {
    Hitbox_ClearDamage(&p->wpn.hitbox);
    return;
  }

  if (p->wpn.weaponKind <= WK_HAMMER) {
    if (Player_TestEquipBuff(p, EBUFF_WET_DURABILITY)) {
      wear >>= 1;
    }

    if (p->wpn.weapon->quality > 0) {  // "+N"
      if ((p->wpn.weapon->wear += wear) >= 200) {
        p->wpn.weapon->quality--;
        p->wpn.weapon->wear = 0;
        HUD_ShowWeaponCrashEffect();
        Player_ApplyWeapon(p, p->wpn.weapon);
      }
    } else if (*(u8*)&p->wpn.weapon->effects[2] != 0) {
      if ((p->wpn.weapon->wear += wear) >= 2000) {
        *(u8*)&p->wpn.weapon->effects[2] = 0;
        p->wpn.weapon->wear = 0;
        HUD_ShowWeaponCrashEffect();
        Player_ApplyWeapon(p, p->wpn.weapon);
      }
    } else if (*(u8*)&p->wpn.weapon->effects[1] != 0) {
      if ((p->wpn.weapon->wear += wear) >= 2000) {
        *(u8*)&p->wpn.weapon->effects[1] = 0;
        p->wpn.weapon->wear = 0;
        HUD_ShowWeaponCrashEffect();
        Player_ApplyWeapon(p, p->wpn.weapon);
      }
    }
  }

  Hitbox_ClearDamage(&p->wpn.hitbox);
}

// 鎧の特殊効果を Player に展開する, 補正値をいったん全部消してから effectType ごとの効果を入れる
// 残差10命令 (201/191): レジスタ割当 (原典は a を r3 に置いたまま回す) と case ごとの定数の作り方
// equipBuffs のアドレスをローカルに持つのが効いている (持たないと 270 命令), Tier A/B は試済
NON_MATCH void Player_ApplyArmorEffect(Player* p, const ArmorData* a) {
#ifdef NONMATCHING_C
  EquipBuffs* flags = &p->equipBuffs;
  s32 i;

  p->hbattrs = 0;
  for (i = 0; i < STAT_KINDS; i++) {
    p->armor.bonus[i] = 0;
    p->armor.sideBonus[i] = 0;
  }
  *flags &= ~0x0FFFFFF0;

  if (a == NULL) {
    Player_SetPlttIDs(p);
    p->unk_94c = 0xFFFF;
    return;
  }

  switch (a->effectType) {
    case AET_SILVER_CHAIN: {
      for (i = 0; i < STAT_KINDS; i++) {
        p->armor.sideBonus[i] = a->value;
      }
      break;
    }
    case AET_BLOOD_CAPE: {
      for (i = 0; i < STAT_KINDS; i++) {
        p->armor.sideBonus[i] = -a->value;
      }
      break;
    }
    case AET_STR: {
      p->armor.bonus[STAT_STRENGTH] = a->value;
      break;
    }
    case AET_SOLAR_WIND: {
      *flags |= EBUFF_SOLAR_WIND;
      break;
    }
    case AET_RES_SOL: {
      p->hbattrs = HBATTR_SOL;
      *flags |= EBUFF_AET_RES_SOL;
      break;
    }
    case AET_RES_DARK: {
      p->hbattrs = HBATTR_DARK;
      break;
    }
    case AET_RES_FLAME: {
      p->hbattrs = HBATTR_FLAME;
      break;
    }
    case AET_RES_FROST: {
      p->hbattrs = HBATTR_FROST;
      break;
    }
    case AET_RES_CLOUD: {
      p->hbattrs = HBATTR_CLOUD;
      break;
    }
    case AET_RES_EARTH: {
      p->hbattrs = HBATTR_EARTH;
      break;
    }
    case AET_DRAGON_SCALE: {
      p->hbattrs = (HBATTR_FLAME | HBATTR_FROST | HBATTR_CLOUD | HBATTR_EARTH);
      break;
    }
    case AET_RES_ALL: {
      p->hbattrs = HBATTR_ALL;
      break;
    }
    case AET_FAIRY_ROBE: {
      *flags |= EBUFF_FAIRY;
      break;
    }
    case AET_EARTHLY_ROBE: {
      *flags |= EBUFF_EARTHLYROBE;
      break;
    }
    case AET_RAIN_COAT: {
      break;
    }
    case AET_SUNLIGHT: {
      *flags |= EBUFF_AET_SUNLIGHT;
      break;
    }
    case AET_ALLNIGHT: {
      *flags |= EBUFF_ALLNIGHT;
      break;
    }
    case AET_MAGIC_COST: {
      *flags |= EBUFF_MAGICROBE;
      break;
    }
    case AET_SKULL_SUIT: {
      *flags |= EBUFF_SKULLSUIT;
      break;
    }
    case AET_EXP_BOOST: {
      *flags |= EBUFF_TRAININGGEAR;
      break;
    }
    case AET_NORMAL_DROP: {
      *flags |= EBUFF_AET_NORMAL_DROP;
      break;
    }
    case AET_RARE_DROP: {
      *flags |= EBUFF_AET_RARE_DROP;
      break;
    }
    case AET_IMMUNE_POISON: {
      *flags |= EBUFF_IMMUNEPOISON;
      break;
    }
    case AET_WEAPON_GUARD: {
      *flags |= EBUFF_WEAPONGUARD;
      break;
    }
    case AET_PARADE: {
      *flags |= EBUFF_PARADE;
      break;
    }
    case AET_AGILITY: {
      p->armor.bonus[STAT_AGILITY] = a->value;
      break;
    }
    case AET_SPIKE: {
      *flags |= EBUFF_SPIKE;
      break;
    }
    case AET_BLACK_ARMOR: {
      *flags |= EBUFF_BLACKARMOR;
      break;
    }
    case AET_MEGA_POWER: {
      *flags |= EBUFF_MEGAPOWER;
      break;
    }
    case AET_GUTS_POWER: {
      *flags |= EBUFF_GUTSPOWER;
      break;
    }
    case AET_PROTO_POWER: {
      *flags |= EBUFF_PROTOPOWER;
      break;
    }
    case AET_TOAD_POWER: {
      *flags |= EBUFF_TOADPOWER;
      break;
    }
  }

  Player_SetPlttIDs(p);
  p->unk_94c = 0xFFFF;
#else
  INCFUNC("asm/func/Player_ApplyArmorEffect.inc");
#endif
}

// 鎧を装備する, a が NULL なら素手の値に戻す
void Player_EquipArmor(Player* p, const ArmorData* a) {
  if (a == NULL) {
    p->armor.id = 0xFFFF;
    p->armor.defence = 0;
    p->armor.weight = 0;
  } else {
    p->armor.id = a->id;
    p->armor.defence = a->defence;
    p->armor.weight = a->weight;
  }

  Player_ApplyArmorEffect(p, a);
  Player_RefreshAllStats(p);
}

void CheckHeartJokerEmblem(Player* p) {
  if (CheckItemOwn(ITEM_HEART_EMBLEM)) {
    Player_SetEquipBuff(p, EBUFF_HEART);
  }

  if (CheckItemOwn(ITEM_JOKER_EMBLEM)) {
    Player_SetEquipBuff(p, EBUFF_JOKER);
  }
}

static s32 GetMagicCost(magic32_t id) {
  static const u16 sMagicCosts[MAGIC_NUM] = {
      [MAGIC_SOL] = 5,
      [MAGIC_DARK] = 5,
      [MAGIC_FLAME] = 10,
      [MAGIC_FROST] = 10,
      [MAGIC_CLOUD] = 10,
      [MAGIC_EARTH] = 10,
      [MAGIC_TRANSFORM] = 0,
      [MAGIC_RISING_SUN] = 100,
      [MAGIC_ZERO_SHIFT] = 10,
      [MAGIC_BLACK_SUN] = 100,
      [MAGIC_FREEZE] = 0,
      [MAGIC_DASH] = 0,
      [MAGIC_HEALING] = 0,
      [MAGIC_DYNAMITE] = 0,
      [MAGIC_SLEEPING] = 0,
      [MAGIC_BAT] = 10,
      [MAGIC_RAT] = 10,
      [MAGIC_WOLF] = 10,
  };  // 0x085ABACC

  static const u16 sMagicUnkVal[MAGIC_NUM] = {
      [MAGIC_SOL] = 10,
      [MAGIC_DARK] = 0,
      [MAGIC_FLAME] = 5,
      [MAGIC_FROST] = 5,
      [MAGIC_CLOUD] = 5,
      [MAGIC_EARTH] = 5,
      [MAGIC_TRANSFORM] = 0,
      [MAGIC_RISING_SUN] = 0,
      [MAGIC_ZERO_SHIFT] = 0,
      [MAGIC_BLACK_SUN] = 0,
      [MAGIC_FREEZE] = 0,
      [MAGIC_DASH] = 1,
      [MAGIC_HEALING] = 2,
      [MAGIC_DYNAMITE] = 2,
      [MAGIC_SLEEPING] = 0,
      [MAGIC_BAT] = 0,
      [MAGIC_RAT] = 0,
      [MAGIC_WOLF] = 0,
  };  // 0x085ABAF0, いつ使うかわからん

  if (gGameFlags & FLAG030047A4_UNK_12) {
    return sMagicUnkVal[id];
  } else {
    return sMagicCosts[id];
  }
}

// 装備している魔法の消費 Ene を計算する, 装備していなければ 0
static s32 CalcMagicCost(Player* p) {
  s32 cost;
  s32 pct;

  if (p->magic.id < 0) {
    return 0;
  }

  cost = GetMagicCost(p->magic.id);
  pct = 100;
  if (Player_TestEquipBuff(p, EBUFF_MAGICROBE)) {  // マジックローブ装備時
    pct = 80;                                      // 本来は ArmorData.value の値を見るのが正しい処理と思われるが 20% 削減で固定されている
  }
  if (p->magic.id <= MAGIC_EARTH && Player_TestEquipBuff(p, EBUFF_WET_ENE_COST)) {
    pct -= 20;
  }

  if (pct < 100) {
    cost = Div(cost * pct, 100);
  }
  return cost;
}

// 装備中の魔法のコストを払えるか, アストロ武器なら太陽スタンドから、そうでなければ ENE から払う
bool32 Player_CheckMagicCost(Player* p) {
  s32 cost = CalcMagicCost(p);
  s32 avail;

  if (p->magic.id <= MAGIC_EARTH && Player_TestEquipBuff(p, EBUFF_ASTRO)) {
    avail = gStat->solarStand;
  } else {
    avail = p->ene;
  }

  if (avail >= cost) return TRUE;

  return FALSE;
}

// 魔法の消費分を支払う, 0〜5番の魔法でアストロ武器を装備しているときは Ene ではなく太陽スタンドから引く
void Player_PayMagicCost(Player* p) {
  s32 cost = CalcMagicCost(p);

  if (p->magic.id <= MAGIC_EARTH && Player_TestEquipBuff(p, EBUFF_ASTRO)) {
    if (gStat->solarStand < cost) {
      gStat->solarStand = 0;
    } else {
      gStat->solarStand -= cost;
    }
  } else {
    if (p->ene < cost) {
      p->ene = 0;
    } else {
      p->ene -= cost;
    }
  }
}

// 今のフォームで魔法 id が使えるかを返す (magic.availableForm の中身)
// 残差4命令 (84/88): 原典は共有された return FALSE のブロックを関数の中央に置いて前後から飛ぶが, agbcc は末尾にまとめる
// Tier A/B は試済 (FUN_08060ed8 を両枝で呼ぶ形は原典と一致した)
NON_MATCH bool32 Player_IsMagicAvailableForm(Player* p, magic32_t id) {
#ifdef NONMATCHING_C
  s32 cat;

  if (id < 0) {
    return FALSE;
  }

  cat = GetMagicCategory(id);
  if (id <= MAGIC_EARTH) {
    if (FUN_08060ed8(p, 2) != 0) {
      return FALSE;
    }
  } else {
    if (FUN_08060ed8(p, 4 << (id - MAGIC_TRANSFORM)) != 0) {
      return FALSE;
    }
  }

  if (p->kind == PLAYER_SOLAR_DJANGO) {
    if (cat == MC_LUNA) {
      if (id == MAGIC_DARK) {
        return FALSE;
      }
      return TRUE;
    }
    if (cat == MC_SOL) {
      return TRUE;
    }
    if (cat == MC_DARK) {
      return FALSE;
    }
    return FALSE;
  }

  if (p->kind == PLAYER_DARK_DJANGO) {
    if (cat == MC_LUNA) {
      if (id == MAGIC_SOL || id == MAGIC_FLAME || id == MAGIC_FROST || id == MAGIC_CLOUD || id == MAGIC_EARTH) {
        return FALSE;
      }
      return TRUE;
    }
    if (cat == MC_SOL) {
      return FALSE;
    }
    if (cat == MC_DARK) {
      if (id != MAGIC_SLEEPING) {
        return TRUE;
      }
      if (gStat->coffin >= 0) {
        return FALSE;
      }
      return TRUE;
    }
    return FALSE;
  }

  if (p->kind == PLAYER_SABATA) {
    return TRUE;
  }
  if (p->kind == PLAYER_BAT) {
    if (id == MAGIC_BAT) {
      return TRUE;
    }
    return FALSE;
  }
  if (p->kind == PLAYER_MOUSE) {
    if (id == MAGIC_RAT) {
      return TRUE;
    }
    return FALSE;
  }

  if (id == MAGIC_SLEEPING) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/Player_IsMagicAvailableForm.inc");
#endif
}

// エンチャント中で、コストも払えて、武器種が銃でも拳でもなければ その魔法の ID を返す
magic32_t Player_CheckMagicEnchant(Player* p) {
  if (p->magic.enchanted && p->magic.id <= MAGIC_EARTH && Player_CheckMagicCost(p)) {
    if (p->wpn.weaponKind != WK_OTHERS && p->wpn.weaponKind != WK_GUN) {
      return p->magic.id;
    }
  }

  return MAGIC_NONE;
}

bool32 Player_HasEnoughEne(Player* p, s32 ene) {
  if (p->ene < ene) return FALSE;
  return TRUE;
}

bool32 Player_HasEnoughSunGauge(Player* p, s32 sunGauge) {
  if (KAAMOS(p->isSabata) > 0) return FALSE;
  if (gStat->sunGauge < sunGauge) return FALSE;

  return TRUE;
}

// 魔法ボタンを押したときに実行する行動番号を返す, 使えないときは今の行動をそのまま返す
// 残差9命令 (258/249): AuxAnim_RestartAnim の宣言を外すと streamdiff は完全一致する (暗黙宣言のときだけ原典のコードになる)
// Player_BurstFormEffect と同じ現象, 宣言を () にしてもプロトタイプありと同じコードになる
NON_MATCH u32 Player_GetMagicAction(Player* p) {
#ifdef NONMATCHING_C
  PlayerMagic* m = &p->magic;
  magic32_t id = m->id;

  if (id >= 0) {
    if (!m->availableForm) {
      return p->action;
    }

    if (m->unk_285 == 0) {
      if (id <= MAGIC_EARTH) {
        if (m->enchanted) {
          m->enchanted = FALSE;
          p->unk_951 = 0;
        } else {
          m->enchanted = TRUE;
          if (Player_CheckMagicEnchant(p) >= 0) {
            p->enchantStarted = 1;
            p->enchantPlttTimer = 0x20;
            p->unk_951 = id + 1;
          }
        }
      } else if (id >= MAGIC_SLEEPING && id <= MAGIC_RAT) {
        if (p->action > PACT_WALK) {
          return p->action;
        }

        if (id == MAGIC_BAT) {
          if (p->kind != PLAYER_BAT) {
            if (!Player_CheckMagicCost(p)) {
              return p->action;
            }
            p->beastGfx = &p->beastGfxs[0];
            AuxSprite_SetGfx(&p->beast, p->beastGfx);
            AuxAnim_RestartAnim(&p->beastAnim, p->batAnim, 0, 0, ANIM_PLAY_XFLIP);
            p->unk_382 = 0xBE;
            p->beast.flags = SPRFLAG_HIDDEN;
            Player_PayMagicCost(p);
          }
          return PACT_CBAT;
        }

        if (id == MAGIC_RAT) {
          if (p->kind != PLAYER_MOUSE) {
            if (!Player_CheckMagicCost(p)) {
              return p->action;
            }
            p->beastGfx = &p->beastGfxs[1];
            AuxSprite_SetGfx(&p->beast, p->beastGfx);
            AuxAnim_RestartAnim(&p->beastAnim, p->mouseAnim, 0, 0, ANIM_PLAY_XFLIP);
            p->beast.flags = SPRFLAG_HIDDEN;
            Player_PayMagicCost(p);
          }
          return PACT_CMOUSE;
        }

        if (p->kind != PLAYER_SLEEPING) {
          if (!Player_CheckMagicCost(p)) {
            return p->action;
          }
          p->beastGfx = &p->beastGfxs[2];
          AuxSprite_SetGfx(&p->beast, p->beastGfx);
          AuxAnim_RestartAnim(&p->beastAnim, p->coffinAnim, 0, 0, ANIM_PLAY_XFLIP);
          p->beast.flags = SPRFLAG_HIDDEN;
          Player_PayMagicCost(p);
        }
        return PACT_SLEEPING;
      } else {
        if (p->action > PACT_WALK) {
          return p->action;
        }

        if (id == MAGIC_WOLF) {
          if (!Player_CheckMagicCost(p)) {
            return p->action;
          }
          return PACT_CWOLF;
        }
        if (id == MAGIC_TRANSFORM) {
          return PACT_TRANSFORM;
        }
        if (id == MAGIC_RISING_SUN || id == MAGIC_BLACK_SUN) {
          return PACT_SUN_MAGIC;
        }
        if (id == MAGIC_ZERO_SHIFT) {
          if (!Player_CheckMagicCost(p)) {
            return p->action;
          }
          Player_PayMagicCost(p);
          return PACT_DASH;
        }
        if (id == MAGIC_DASH) {
          return PACT_DASH;
        }
        if (id == MAGIC_DYNAMITE) {
          if (p->dynamiteCount != 0) {
            return p->action;
          }
          return PACT_DYNAMITE;
        }
        if (id == MAGIC_FREEZE) {
          return PACT_FREEZE;
        }
        if (id == MAGIC_HEALING) {
          return PACT_HEALING;
        }
        return p->action;
      }
    }
  }

  return p->action;
#else
  INCFUNC("asm/func/Player_GetMagicAction.inc");
#endif
}

// 装備魔法を n に変える, 変身中なら戻す行動に入り, エンチャント系なら即かけ直す
void Player_EquipMagic(Player* p, magic32_t n) {
  PlayerMagic* m = &p->magic;

  if (m->id == n) {
    return;
  }

  if (m->enchanted) {
    m->enchanted = FALSE;
    p->unk_951 = 0;
  }

  if (p->kind == PLAYER_BAT) {
    Player_SetAction(p, PACT_CBAT, 0);
  } else if (p->kind == PLAYER_MOUSE) {
    Player_SetAction(p, PACT_CMOUSE, 0);
  } else if (p->kind == PLAYER_SLEEPING) {
    Player_SetAction(p, PACT_SLEEPING, 0);
  }

  m->id = n;
  if ((s8)n < 0) {
    m->enchanted = FALSE;
    m->cat = 0xFF;
    m->availableForm = FALSE;
    m->basicCost = 0;
    p->enchantStarted = 0;
    if (p->enchantPlttID == 0) {
      p->enchantPlttTimer = 0;
    }
  } else {
    m->cat = GetMagicCategory(m->id);
    m->availableForm = Player_IsMagicAvailableForm(p, m->id);
    m->basicCost = GetMagicCost(m->id);
    if (!m->availableForm) {
      return;
    }

    if (m->id <= MAGIC_EARTH) {
      m->enchanted = TRUE;
      if (Player_CheckMagicEnchant(p) >= 0) {
        p->enchantStarted = 1;
        p->enchantPlttTimer = 0x20;
        p->enchantPlttID = m->id + 0x121;
        p->unk_951 = m->id + 1;
      }
      return;
    }

    m->enchanted = FALSE;
    p->enchantStarted = 0;
    if (p->enchantPlttID == 0) {
      p->enchantPlttTimer = 0;
    }
  }

  p->unk_951 = p->unk_950;
}

// 使う魔法の番号を返す, サバタは固定の2種から選び、それ以外は登録魔法から引く
s32 Player_GetEquippedMagic(Player* p) {
  if (p->kind != PLAYER_SABATA) {
    return *(gStat->equippedMagicIdx + gStat->registeredMagic);
  }

  gSavedMagicEnchanted = 0;

  if (gStat->sabataMagicIdx == 0) return MAGIC_ZERO_SHIFT;
  return MAGIC_BLACK_SUN;
}

// 装備魔法の情報 (カテゴリ・消費MP・フォームで使えるか・エンチャント中か) を再計算する
void Player_RefreshMagicInfo(Player* p) {
  PlayerMagic* m = &p->magic;

  if (gGameFlags & FLAG030047A4_UNK_12) {
    m->id = MAGIC_NONE;
  } else {
    m->id = Player_GetEquippedMagic(p);
  }

  if (m->id < 0) {
    m->cat = 0xFF;
    m->basicCost = 0;
    m->availableForm = FALSE;
    m->enchanted = FALSE;
    return;
  }

  m->cat = GetMagicCategory(m->id);
  m->basicCost = GetMagicCost(m->id);
  m->availableForm = Player_IsMagicAvailableForm(p, m->id);
  m->enchanted = gSavedMagicEnchanted;
  if (!m->availableForm) {
    m->enchanted = FALSE;
    return;
  }

  if (!m->enchanted) {
    return;
  }
  if (m->id > MAGIC_EARTH) {
    return;
  }
  p->unk_951 = m->id + 1;
}

void FUN_08065200(Player* p) {
  if (VM_SeekToNamedArg('i')) {
    p->inputIdx = VM_GetValue();
  } else {
    p->inputIdx = 0;
  }
}

void Player_ClearInputHistory(Player* p) {
  s32 i;

  for (i = 0; i < 10; i++) {
    p->facingHistory[i] |= 0xFFFF;
  }
}

void FUN_08065240(Player* p) {
  if (VM_SeekToNamedArg('R')) {
    p->scriptID_9c4 = VM_GetValue();
  } else {
    p->scriptID_9c4 = 0;
  }
}

void Player_UpdateDjango(Player* p);
void Player_UpdateBat(Player* p);
void Player_UpdateMouse(Player* p);
void Player_UpdateSleeping(Player* p);
void Player_UpdateSabata(Player* p);

// プレイヤー生成の後半, kind を決めて更新コールバックと入力を割り当て, 1Pなら前のプレイヤーが残した状態異常の残り時間を引き継ぐ
s32 Player_InitState(Player* p) {
  static const PlayerFunc sPlayerUpdates[6] = {
      [PLAYER_SOLAR_DJANGO] = Player_UpdateDjango,
      [PLAYER_DARK_DJANGO] = Player_UpdateDjango,
      [PLAYER_BAT] = Player_UpdateBat,
      [PLAYER_MOUSE] = Player_UpdateMouse,
      [PLAYER_SLEEPING] = Player_UpdateSleeping,
      [PLAYER_SABATA] = Player_UpdateSabata,
  };  // 0x085ABB14

  p->mode = PMODE_ACTIVE;

  if (VM_SeekToNamedArg('k')) {
    p->kind = VM_GetValue();
  } else {
    p->kind = gStat->playerKind;
  }

  if (p->kind == PLAYER_SABATA) {
    p->isSabata = TRUE;
  } else {
    p->isSabata = FALSE;
  }

  Player_RefreshStats(p);

  if (gGameFlags & FLAG030047A4_UNK_12) {
    s32 i;

    for (i = 0; i < 3; i++) {
      gBadCondTimer[i] = 0;
    }
    p->updateCallback = FUN_08079f1c;
  } else {
    p->updateCallback = sPlayerUpdates[p->kind];
  }

  Player_SetAction(p, PACT_IDLE, 0);
  p->input = &gInput[p->inputIdx];
  Player_ClearInputHistory(p);

  if (p->inputIdx == 0) {
    s32 i;

    p->goodCondID = gGoodCondID;
    p->goodFrom = gGoodFrom;
    p->goodCondTimer = gGoodCondTimer;
    for (i = 0; i < 3; i++) {
      p->badCondTimer[i] = gBadCondTimer[i];
    }
  } else {
    s32 i;

    p->goodCondID = 0;
    p->goodFrom = 0;
    p->goodCondTimer = 0;
    for (i = 0; i < 3; i++) {
      p->badCondTimer[i] = 0;
    }
  }

  p->controlUp = gStat->controlUp;
  if (p->badCondTimer[BAD_CONFUSE] != 0) {
    p->controlUp = gConfusedDir;
  }
  return 0;
}

void Player_InitSprite(Player* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_DJANGO_SABATA);

  if (f != NULL) {
    p->humanGfx = *(MainSpriteGfx*)f;
    OpenMainSpriteFile(&p->humanGfx, f);
    MainSprite_Add(&p->human, &p->humanGfx, 0, SPRFLAG_UNK_15 | SPRFLAG_GAMEOVER, 2, PLAYMODE_PAUSE, 60, &p->mover.pos);

    if (VM_SeekToNamedArg('d')) {
      p->facing = VM_GetValue();
    } else {
      p->facing = FACE_UP;
    }

    PLAYER_SET_ANIM_DIR(p, p->facing);

    p->animID = 0;
    MainSprite_SetAnim(&p->human, &p->humanGfx, p->animIDOffset, PLAYMODE_LOOP, 0);
    if (p->xflip) {
      p->human.flags |= SPRFLAG_XFLIP;
    } else {
      p->human.flags &= ~SPRFLAG_XFLIP;
    }
  }
}

// 変身用の3種のスプライトとアニメを読み込み, 今の kind に合った beast スプライトを出して最初のコマを当てる
void Player_InitBeastSprite(Player* p) {
  AuxSprite* sprite;
  AuxAnimState* anim;
  AuxAnimFile* file;
  u32 animIdx;

  Video_GetAuxSprite(&p->beastGfxs[0], SPRITE_BAT);
  Video_GetAuxSprite(&p->beastGfxs[1], SPRITE_MOUSE);
  Video_GetAuxSprite(&p->beastGfxs[2], SPRITE_COFFIN);
  p->batAnim = GetFile(DIR_ANIMATION, ANIM_BAT);
  p->mouseAnim = GetFile(DIR_ANIMATION, ANIM_MOUSE);
  p->coffinAnim = GetFile(DIR_ANIMATION, ANIM_COFFIN);

  sprite = &p->beast;
  if (p->kind == PLAYER_MOUSE) {
    p->beastGfx = &p->beastGfxs[1];
    file = p->mouseAnim;
    animIdx = 0;
  } else if (p->kind == PLAYER_SLEEPING) {
    p->beastGfx = &p->beastGfxs[2];
    file = p->coffinAnim;
    p->coffin = GetPlayerCoffinID();
    animIdx = p->coffin;
  } else {
    p->beastGfx = &p->beastGfxs[0];
    file = p->batAnim;
    animIdx = 0;
  }

  AuxSprite_Add(sprite, p->beastGfx, SPRFLAG_GAMEOVER | SPRFLAG_HIDDEN);
  p->beast.pos.x = p->mover.pos.x;
  p->beast.pos.y = p->mover.pos.y;
  p->beast.pos.z = p->mover.pos.z;
  p->floatHeight = 0;

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, file, animIdx, p->animIDOffset, p->xflip);

  AuxSprite_AdvanceAnim(sprite, anim);

  p->unk_382 = 0xBE;
}

NAKED bool32 FUN_08065744(Player* p, u32 n) { INCFUNC("asm/func/FUN_08065744.inc"); }

void Player_InitWeapon(Player* p) {
  if (p->kind != PLAYER_SABATA) {
    if (REGISTERED_WEAPON(gStat->equippedWeaponIdx) >= 0) {
      Player_ApplyWeapon(p, GetWeapon(REGISTERED_WEAPON(gStat->equippedWeaponIdx)));
    } else {
      Player_ApplyWeapon(p, NULL);
    }
  } else {
    Player_ApplyWeapon(p, NULL);
    if (p->inputIdx == 0) {
      SetWeaponFoundFlag(WEAPON_GUN_DEL_HELL);
    }
  }
}

// 現在装備している防具の効果をプレイヤーに反映させる, Player_Init時に呼ばれる
void Player_InitArmor(Player* p) {
  const ArmorData* a;

  if (p->kind != PLAYER_SABATA) {
    if (gStat->armor < 0) {
      a = NULL;
    } else {
      a = &gArmorDB[ARMORS(gStat->armor)];
    }
  } else {
    SetArmorFoundFlag(ARMOR_MAIL_OF_LUNA);
    a = &gArmorDB[ARMOR_MAIL_OF_LUNA];
  }

  Player_EquipArmor(p, a);
}

// 本体の当たり判定を組み立てる, 赤ジャンゴは属性がソル・弱点がダークで、それ以外は逆になる
void Player_SetupHurtbox(Player* p) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.196), Q8(0.497), Q8(0.196));
  VEC3_SET(offset, 0, Q8(0.497), 0);
  Hitbox_Init(hurtbox, p->mover.id, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_UNK_0, 0, 1 << p->inputIdx, &halfSize, &offset);
  if (p->kind == PLAYER_SOLAR_DJANGO) {
    Hitbox_SetPowerAndAttributes(hurtbox, 20, HBATTR_SOL, HBATTR_DARK);
  } else {
    Hitbox_SetPowerAndAttributes(hurtbox, 20, HBATTR_DARK, HBATTR_SOL);
  }
  Hitbox_SetHandler(hurtbox, Django_OnHurt, p);
  Hitbox_SetPos(hurtbox, &p->beast.pos, 0);
  Hitbox_Register(hurtbox);
}

// 岩? (名前は暫定)
bool32 Player_IsOnRock(u32 attr) {
  if ((attr & TATTR_SPECIAL) && !TestMapFlag(MPF_HOT | MPF_COLD)) {
    return TRUE;
  }
  return FALSE;
}

// 溶岩ブロックか
bool32 Player_IsInLava(u32 attr) {
  if ((attr & TATTR_SPECIAL) && TestMapFlag(MPF_HOT)) {
    return TRUE;
  }
  return FALSE;
}

bool32 UNUSED FUN_08065b08(u32 attr) {
  if ((attr & TATTR_SPECIAL) && TestMapFlag(MPF_UNK_13)) {
    return TRUE;
  }
  return FALSE;
}

// ツルツルすべる氷の上にいるか
bool32 Player_IsOnIce(u32 attr) {
  if ((attr & TATTR_SPECIAL) && TestMapFlag(MPF_COLD)) {
    return TRUE;
  }
  return FALSE;
}

// 溶岩タイルに乗ったら, そのタイルの中心を knockbackOrigin にして位置をタイルの内側に収め, 被弾を保留する (エレベーター上と吹き飛ばし中は除く)
void FUN_08065b7c(Player* p) {
  if (Player_IsInLava(GetTileAttrAt(&p->mover.pos)) && p->unk_390 == 0 && !p->originKnockback && !Elevator_FindAtPos(&p->mover.pos)) {
    s32 bx = Mod(p->tile.tileIdx[0], gCollisionMap->tiledata->width);
    s32 bz = Div(p->tile.tileIdx[0], gCollisionMap->tiledata->width);
    s32 minX, maxX, minZ, maxZ;

    p->knockbackTileCenter.x = (bx << 8) + 128;
    p->knockbackTileCenter.z = (bz << 8) + 128;
    p->knockbackOrigin = &p->knockbackTileCenter;
    minX = (bx << 8) + 1;
    maxX = (bx << 8) + 255;
    minZ = (bz << 8) + 1;
    maxZ = (bz << 8) + 255;
    if (p->mover.pos.x < minX) {
      p->mover.pos.x = minX;
    } else if (p->mover.pos.x > maxX) {
      p->mover.pos.x = maxX;
    }
    if (p->mover.pos.z < minZ) {
      p->mover.pos.z = minZ;
    } else if (p->mover.pos.z > maxZ) {
      p->mover.pos.z = maxZ;
    }
    p->beast.pos = p->mover.pos;
    p->human.pos = p->mover.pos;
    p->originHitPending = TRUE;
  }
}

// knockbackOrigin の位置から弾かれたときの被弾処理, 向きを knockbackOrigin から見た方向に合わせて吹き飛ばしを設定し, 受けるダメージ 10 を返す
s32 FUN_08065cb8(Player* p) {
  if (p->kind == PLAYER_SLEEPING) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
  }
  p->originKnockback = TRUE;
  p->hurtbox.knockbackPower = 50;
  Player_SetInvincibleTime(p, 60);
  p->blownAway = 0;
  p->floatHeight = 0;
  p->facing = (Angle_ToDir4(ArcTan2_8(p->mover.pos.x - p->knockbackOrigin->x, p->mover.pos.z - p->knockbackOrigin->z)) << 1) + 1;
  PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
  p->hurtSound = SE_IGNITE;
  p->originHitPending = FALSE;
  return 10;
}

// 今踏んでいるタイルの中心座標を knockbackTileCenter に入れて knockbackOrigin から参照させる
void Player_CheckTileHit(Player* p) {
  if (Entity1DBE_TouchElemNear(&p->mover.pos) && p->tileKnockback == 0) {
    s32 bx = Mod(p->tile.tileIdx[0], gCollisionMap->tiledata->width);
    s32 bz = Div(p->tile.tileIdx[0], gCollisionMap->tiledata->width);

    p->knockbackTileCenter.x = (bx << 8) + 128;
    p->knockbackTileCenter.z = (bz << 8) + 128;
    p->knockbackOrigin = &p->knockbackTileCenter;
    p->tileHitPending = TRUE;
  }
}

// 今いるタイルから見た knockbackOrigin の方向に向きを合わせ, ノックバック 50 を設定して受けるダメージ 10 を返す (FUN_08065cb8 の別版)
// 残差は knockbackOrigin->x - 0x80 の畳み方のみ, 原典はブロック座標 << 8 を先に作ってから knockbackOrigin->x - 0x80 を引くが, agbcc は + 0x80 を結果側へ畳む (Angle_Diff と同じ壁)
// Tier A-C 試済: static inline s32 Diff(s32 a, s32 b) { return a - b; } に (bx << 8, p->knockbackOrigin->x - 0x80) を渡すと ROM まで一致するが, 意味のない inline なので採っていない, ローカルに切り出すと順序が崩れる
NON_MATCH s32 FUN_08065e24(Player* p) {
#ifdef NONMATCHING_C
  s32 bx, bz;

  p->tileKnockback = TRUE;
  p->hurtbox.knockbackPower = 50;
  p->blownAway = 0;
  p->floatHeight = 0;
  bx = Mod(p->tile.tileIdx[1], gCollisionMap->tiledata->width);
  bz = Div(p->tile.tileIdx[1], gCollisionMap->tiledata->width);
  p->facing = (Angle_ToDir4(ArcTan2_8((bx << 8) - (p->knockbackOrigin->x - 0x80), (bz << 8) - (p->knockbackOrigin->z - 0x80))) << 1) + 1;
  if (p->facing > 4) {
    p->animIDOffset = (8 - p->facing) >> 1;
    p->xflip = TRUE;
  } else {
    p->animIDOffset = p->facing >> 1;
    p->xflip = FALSE;
  }
  p->hurtSound = SE_IGNITE;
  p->tileHitPending = FALSE;
  return 10;
#else
  INCFUNC("asm/func/FUN_08065e24.inc");
#endif
}

// pos のタイルの高さが p の足元の高さと違うか, タイルに TATTR_UNK_0 が立っていれば真
bool32 FUN_08065f34(Player* p, Vec3* pos) {
  if (TileHeightAt(pos) != p->mover.pos.y) {
    return TRUE;
  }
  if (GetTileAttrAt(pos) & TATTR_UNK_0) {
    return TRUE;
  }
  return FALSE;
}

NAKED s32 FUN_08066040(Player* p) { INCFUNC("asm/func/FUN_08066040.inc"); }

NAKED void FUN_0806623c(Player* p) { INCFUNC("asm/func/FUN_0806623c.inc"); }

NAKED void FUN_08066408(Player* p) { INCFUNC("asm/func/FUN_08066408.inc"); }

void Player_TakeSunburnDamage(Player* p) {
  Player_EmitBurnSmoke(p);
  p->damage++;
}

// 黒ジャンゴ, バット, マウス が太陽にあたっているときのダメージ処理
// 太陽ゲージから sunburn を貯め、100 たまるごとに Player_TakeSunburnDamage を1回呼ぶ
void Player_StepSunburn(Player* p, s32 sungauge) {
  if (p->unk_43a == 0) {
    u16 state = p->goodCondTimer;
    bool32 skip = state != 0 && p->goodCondID == GOOD_UVCUT;

    if (!skip) {
      p->sunburn += sungauge + 2;
      if (p->sunburn > 99) {
        Player_TakeSunburnDamage(p);
        p->sunburn -= 100;
      }
    }
  }
}

bool32 Player_IsInRain(Player* p) {
  if (!TestMapFlag(MPF_RAIN) || p->armor.id == ARMOR_RAIN_COAT) {
    return FALSE;
  }
  if (!TestMapFlag(MPF_OUTDOOR) && !FUN_0809df78(&p->mover.pos)) {
    return FALSE;
  }
  return TRUE;
}

// 雨に当たっている間の処理, カーモスの進行を進めて10分たったらカーモス状態にし, トードパワー装備中は15フレームごとに ENE を1回復する
void FUN_0806687c(Player* p) {
  if (KAAMOS(p->isSabata) == 0) {
    if (++*(gStat->kaamosProgress + p->isSabata) >= SECOND(600)) {
      *(gStat->kaamosProgress + p->isSabata) = 0;
      KAAMOS(p->isSabata) = SECOND(3000);
      FUN_08060e90(p, 0);
    }
  }
  if (TEST_FLAGS(p->equipBuffs, EBUFF_TOADPOWER)) {
    if (++p->unk_38f >= 15) {
      if (++p->ene >= p->maxEne) {
        p->ene = p->maxEne;
      }
      p->unk_38f = 0;
    }
  }
}

// 雨に当たっている間, 15フレームごとに煙を出してダメージを1増やす
void FUN_0806692c(Player* p) {
  if (++p->rainTick >= 15) {
    Vec3 size;
    WorldPos pos;

    if (p->kind == PLAYER_BAT || p->kind == PLAYER_MOUSE) {
      pos = p->beast.pos;
      size.x = 32, size.y = 32, size.z = 32;
    } else {
      pos = p->mover.pos;
      pos.y += 160;
      size.x = 64, size.y = 60, size.z = 64;
    }
    EmitSmoke(&pos, 1, &size, 0, 0, 12, 2, 2);
    p->damage++;
    p->rainTick = 0;
  }
}

// 見回しのオフセットを, y の半分を引いた x / z が |z - x| <= 800 かつ |z + x| <= 800 のひし形に収まるよう押し戻す
// 残差はレジスタ割当のみ (84/84), 原典は half を r2, x のアドレスを r1, z の値を r5 に置くが, こちらは half が r1 で z の値がその後を継ぐ
// Tier A-C は試済 (宣言順, Vec3* / s16* ローカル, / 2), 未: 前半と後半を別の変数で持つ形
NON_MATCH void Player_ClampLookAround(Player* p) {
#ifdef NONMATCHING_C
  s32 x, z, d, delta;
  s32 half = p->lookAroundOffset.y >> 1;

  x = p->lookAroundOffset.x - half;
  z = p->lookAroundOffset.z - half;
  d = z - x;

  if (d > 800) {
    delta = (d - 800) >> 1;
    p->lookAroundOffset.x += delta;
    p->lookAroundOffset.z -= delta;
  } else if (d < -800) {
    delta = (-800 - d) >> 1;
    p->lookAroundOffset.x -= delta;
    p->lookAroundOffset.z += delta;
  }
  d = z + x;
  if (d > 800) {
    delta = (d - 800) >> 1;
    p->lookAroundOffset.x -= delta;
    p->lookAroundOffset.z -= delta;
  }
  if (d < -800) {
    delta = (-800 - d) >> 1;
    p->lookAroundOffset.x += delta;
    p->lookAroundOffset.z += delta;
  }
#else
  INCFUNC("asm/func/Player_ClampLookAround.inc");
#endif
}

// 見回しモードを始める (行動4 以外), 注視点からプレイヤーへのオフセットを作り, 入力方向があればその分ずらす
// 残差はレジスタ2本の入れ替えだけ (189対189), 原典は facing の & 7 の結果をマスク側のレジスタに入れてアドレスに r0 を回すが, こちらは値が r0 でアドレスが r1 になる
// Tier A-C は試済 (値を s32/DirU8 のローカルに置く, static inline の引数経由にする). アドレスのオフセットは直前の z アクセスの定数レジスタを subs で使い回したもので, C 側から作り直せない
NON_MATCH void Player_UpdateLookAround(Player* p) {
#ifdef NONMATCHING_C
  if (p->lookAroundOffset.val == 0) {
    p->lookAroundOffset.x = gCameraCoords.worldPos.x - p->mover.pos.x;
    p->lookAroundOffset.y = gCameraCoords.worldPos.y - p->mover.pos.y - 150;
    p->lookAroundOffset.z = gCameraCoords.worldPos.z - p->mover.pos.z;
    p->lookAroundOffset.val = 1;
    p->unk_3d0 = 1;
    Player_ClampLookAround(p);
  }

  if ((s16)p->facingHistory[0] != -1) {
    s32 angle = (((s16)p->facingHistory[0] + 1) & 7) * 32;

    p->lookAroundOffset.x -= POLAR_X(30, angle);
    p->lookAroundOffset.z -= POLAR_Z(30, angle);
    p->unk_3d0 = 0;
    Player_ClampLookAround(p);
  }

  if (p->lookAroundOffset.x != 0 || p->lookAroundOffset.z != 0) {
    if (p->unk_3d1 != 0) {
      u16 angle = ArcTan2_8(p->lookAroundOffset.x, p->lookAroundOffset.z);
      p->facing = ((((angle + 0x10) & 0xFF) >> 5) + 3) & 7;
      if (p->kind == PLAYER_BAT) {
        s32 quad = ((((angle + 0x20) & 0xFF) >> 6) + 1) & 3;

        if (quad > 1) {
          p->animIDOffset = 3 - quad;
          p->xflip = TRUE;
        } else {
          p->animIDOffset = quad;
          p->xflip = FALSE;
        }
      } else if (p->kind != PLAYER_SLEEPING || p->coffin == 5) {
        Player_SetAnimFacing(p);
      }
    }
  }
#else
  INCFUNC("asm/func/Player_UpdateLookAround.inc");
#endif
}

// 見回しモードを始める, 注視点からプレイヤーへのオフセットを actionDir の向きの反対側に取る
void Player_StartLookAround(Player* p) {
  if (p->lookAroundOffset.val == 0) {
    s32 angle = ((p->actionDir + 1) & 7) * 32;

    p->lookAroundOffset.x = -POLAR_X(800, angle);
    p->lookAroundOffset.y = 0;
    p->lookAroundOffset.z = -POLAR_Z(800, angle);
    p->lookAroundOffset.val = 1;
  }
}

// 見回しモードを終了する
void Player_EndLookAround(Player* p) {
  FUN_0823bca8(8);
  p->lookAroundOffset.val = FALSE;
}

// 残差1命令 (38対39), 原典は TRUE を返す 1 ブロックを関数の末尾に置いて全経路から前方へ飛ばすが,
// agbcc はクロスジャンプで残す側を最初のグループの直後にしてしまい, 後ろのグループが後方へ飛ぶぶん末尾の b が1本減る
// Tier A は試済 (return TRUE の if を分ける/まとめる, 3つの return <論理式> にする (これは 0 の作り置きが出て42命令に悪化))
NON_MATCH bool32 FUN_08066d2c(Player* p, s32 val) {
#ifdef NONMATCHING_C
  if (p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) {
    if (val == 0 || val == 3 || val == 6 || (val == 4 && p->unk_3bc != 0)) {
      return TRUE;
    }
  } else if (p->kind == PLAYER_SLEEPING) {
    if (val == 0) {
      return TRUE;
    }
  } else if (val == 0 || val == 4) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_08066d2c.inc");
#endif
}

void FUN_08066d7c(Player* p, s32 val) {
  if ((p->input->down & R_BUTTON) && FUN_08066d2c(p, val)) {
    if ((p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) && p->action == PACT_UNK_4) {
      Player_StartLookAround(p);
    } else {
      Player_UpdateLookAround(p);
    }
  } else if (p->lookAroundOffset.val) {
    Player_EndLookAround(p);
  }
  p->unk_3d1 = 1;
}

// 自分の座標とカメラの注視点を 1:4 で混ぜた座標を pos_3c0 に作る
// 残差は y の +150 を置く位置だけ (60対60), 原典は gCameraCoords.worldPos.y * 4 の側のレジスタに足すが, gcc は和の木から定数を括り出して累算器に足してしまう
// Tier A-B は試済 (camera 項を括る, 両辺を括る, (cam+37)*4+2 と書き換える (これは命令が1本増えて定数の位置も合わない)). 150 を素の整数定数で書く限り associate_trees が同じ形に畳む
NON_MATCH void Player_UpdateCameraLookAt(Player* p) {
#ifdef NONMATCHING_C
  p->pos_3c0.x = Div(p->mover.pos.x + p->lookAroundOffset.x + gCameraCoords.worldPos.x * 4, 5);
  p->pos_3c0.y = Div(p->mover.pos.y + p->lookAroundOffset.y + gCameraCoords.worldPos.y * 4 + 150, 5);
  p->pos_3c0.z = Div(p->mover.pos.z + p->lookAroundOffset.z + gCameraCoords.worldPos.z * 4, 5);
  Camera_LookAt(&p->pos_3c0);
#else
  INCFUNC("asm/func/Player_UpdateCameraLookAt.inc");
#endif
}

void FUN_08066e84(Player* _) {
  u16 payload = 6;

  FUN_080ec79c(ENEK_CURORO, &payload);
}

void FUN_08066e9c(Player* p, Vec3* pos1, s32 param_3, s32 param_4, Vec3* pos2, s32 param_6, SoundID32 soundID) {
  FUN_08240cf0(pos1->x, pos1->z, param_3, 0, param_4, p->mover.id);
  if (pos2 != NULL) {
    Player_ShowPtcl64c(p, pos2, param_6);
  }
  if (soundID != 0) {
    PlaySound_082406e0(soundID);
  }
}

// プレイヤーの種類ごとのアニメ番号表から idx 番目のアニメ番号を引く
u32 Player_GetAnimIdx(s32 playerKind, s32 idx) {
  if (playerKind == PLAYER_SOLAR_DJANGO) {
    static const u16 sSolarDjangoAnimIdxTable[57] = {
        0, 5, 20, 22, 24, 26, 28, 30, 52, 54, 56, 58, 60, 61, 62, 63, 10, 15, 44, 46, 48, 109, 119, 114, 124, 129, 134, 139, 144, 149, 154, 159, 64, 69, 74, 79, 84, 89, 94, 99, 104, 32, 34, 38, 40, 42, 36, 179, 184, 194, 189, 534, 513, 514, 515, 519, 520,
    };  // 0x085ABB2C
    return sSolarDjangoAnimIdxTable[idx];
  }

  if (playerKind == PLAYER_DARK_DJANGO) {
    static const u16 sDarkDjangoAnimIdxTable[57] = {
        199, 204, 219, 221, 223, 225, 227, 229, 251, 253, 255, 257, 259, 260, 261, 262, 209, 214, 243, 245, 247, 308, 318, 313, 323, 328, 333, 338, 343,
        348, 353, 358, 263, 268, 273, 278, 283, 288, 293, 298, 303, 231, 233, 237, 239, 241, 235, 378, 383, 393, 388, 535, 521, 522, 523, 527, 528,
    };  // 0x085ABB9E
    return sDarkDjangoAnimIdxTable[idx];
  }

  if (playerKind == PLAYER_SABATA) {
    static const u16 sSabataAnimIdxTable[57] = {
        414, 419, 434, 436, 438, 440, 442, 444, 466, 468, 470, 472, 474, 475, 476, 477, 424, 429, 458, 460, 462, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 478, 483, 488, 0, 0, 0, 446, 448, 452, 454, 456, 450, 493, 498, 508, 503, 533, 0, 0, 0, 0, 0,
    };  // 0x085ABC10
    return sSabataAnimIdxTable[idx];
  }
  return 0;
}

// 直前の入力方向の履歴から向き直す先を選ぶ, 履歴が斜めなら即採用、それ以外は隣の方向が来るまで遡る
// 残差なし・レジスタ割当のみ不一致 (原典は p を ip に置く)
NON_MATCH u32 FUN_08066f18(Player* p) {
#ifdef NONMATCHING_C
  s32 dir = (s16)p->facingHistory[1];

  if (dir != -1) {
    s32 next;
    s32 prev;
    s32 i;

    if (dir & 1) {
      return dir;
    }
    next = (dir + 1) & 7;
    prev = (dir + 7) & 7;
    for (i = 2; i < 10; i++) {
      s32 d = (s16)p->facingHistory[i];

      if (d != -1) {
        if (d == next || d == prev) {
          return d;
        }
        if (d != dir) {
          return dir;
        }
      }
    }
  }
  return p->facing;
#else
  INCFUNC("asm/func/FUN_08066f18.inc");
#endif
}

void FUN_08066f7c(Player* p) {
  if (p->action != PACT_IDLE) {
    Player_SetAction(p, PACT_IDLE, 0);
    p->facing = FUN_08066f18(p);
    Player_SetAnimFacing(p);
  }
  p->flag20 &= ~PFLAG20_UNK_0;
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
}

// ハヤサと鎧の重さから移動速度を出す, 下限は 2
static s32 CalcMoveSpeed(Player* p) {
  u16 n = p->goodCondTimer;
  bool32 heaviest = FALSE;
  s32 val;

  if (n != 0 && p->goodCondID == GOOD_SPEED) {
    heaviest = TRUE;
  }

  if (heaviest) {
    val = 16;
  } else {
    s32 agility = p->stats[STAT_AGILITY];
    s32 over = p->armor.weight - 100;

    val = Div((agility - over) * 12, 100);
    if (val > 16) {
      val = 16;
    } else if (val < 9) {
      val = 9;
    }
  }

  if (p->emitter.kind == 2 && p->emitter.unk_3 != 0) {
    val -= 4;
  }
  if (p->speedPenalty != 0) {
    val -= p->speedPenalty;
  }
  if (val < 2) {
    return 2;
  }
  return val;
}

// 入力履歴の直近4件から隣の方向への向き直しを探す
// 残差1命令・レジスタ割当のみ不一致 (原典は d を早めに戻り値レジスタへ写す)
NON_MATCH u32 FUN_08067068(Player* p) {
#ifdef NONMATCHING_C
  s32 dir = (s16)p->facingHistory[0];
  s32 next;
  s32 prev;
  s32 i;

  if (dir & 1) {
    return dir;
  }
  next = (dir + 1) & 7;
  prev = (dir + 7) & 7;
  for (i = 1; i < 5; i++) {
    s32 d = (s16)p->facingHistory[i];

    if (d != -1) {
      if (d == next || d == prev) {
        return d;
      }
      if (d != (s16)p->facingHistory[0]) {
        return dir;
      }
    }
  }
  return dir;
#else
  INCFUNC("asm/func/FUN_08067068.inc");
#endif
}

s32 FUN_080670d4(s32 val) {
  if (val == 12) {
    return 64;
  }
  if (val <= 11) {
    return (12 - val) * 8 + 64;
  } else {
    return 64 - (val - 12) * 4;
  }
}

NAKED void FUN_080670fc(Player* p, u32 val) { INCFUNC("asm/func/FUN_080670fc.inc"); }

// 歩き始めるときの初期化, 移動速度とアニメを設定する
void FUN_080672b0(Player* p) {
  p->action = PACT_WALK;
  p->flag20 &= ~PFLAG20_UNK_0;
  p->facing = FUN_08067068(p);
  if (p->useForcedDelta == 0) {
    s32 val = CalcMoveSpeed(p);
    bool32 scaled;
    u16 n;

    FUN_080670d4(val);
    n = p->goodCondTimer;
    scaled = FALSE;
    if (n != 0 && p->goodCondID == GOOD_MINI) {
      scaled = TRUE;
    }
    if (scaled) {
      val = val * p->human.scaleX >> 6;
    }
    Player_SetMoveDelta(p, val);
  }
  FUN_080670fc(p, 0);
  Player_SetAnimFacing(p);
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(1));
}

// 魔法"ダッシュ" 前方に高速で移動する魔法 (太陽ゲージの量に応じて移動速度が変化)
void MagicDash_Update(Player* p) {
  if (p->action != PACT_DASH) {
    if (Player_HasEnoughSunGauge(p, 1)) {
      PlaySound_082406e0(SE_MAGIC_DASH);
      p->dashSpeed = gStat->sunGauge * 2 + 14;
      if (p->dashSpeed > 32) {
        p->dashSpeed = 32;
      }
      p->dashFrames = Div(512, p->dashSpeed);
      Player_SetAction(p, PACT_DASH, 0);
    } else {
      PlaySound_082406e0(SE_NG);
      Player_SetAction(p, PACT_DASH, 1);
    }
  }

  switch (p->state) {
    case 0: {
      p->stateTimer++;
      if (p->stateTimer >= p->dashFrames) {
        Player_SetAction(p, PACT_IDLE, 0);
      } else {
        if (p->stateTimer < p->dashFrames - 8) {
          p->plttID_95e = 293;
          p->plttFlashTimer = 32;
        }
        if ((s16)p->facingHistory[0] != -1 && p->lookAroundOffset.val == 0) {
          p->facing = FUN_08067068(p);
        }
        Player_SetMoveDelta(p, p->dashSpeed);
        FUN_080670fc(p, 1);
        Player_SetAnimFacing(p);
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(0.5));
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 7) {
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 残差1命令 (23対22), 原典は pos & 0xFF の結果をマスク側のレジスタに入れるが (ands r0, r1), こちらは pos 側に入れて r0 へ写すので adds r0, r1, #0 が1本増える
// Tier A-C は試済 (条件の向きを反転, ofs を消して (pos & 0xFF) を2回書く (lsls/lsrs が増えて25命令), ofs を内側のブロックで宣言する). Player_UpdateLookAround と同じマスク側destinationの詰まり
NON_MATCH bool32 Player_IsNearTileCenter(Player* p) {
#ifdef NONMATCHING_C
  u16 pos;
  u32 ofs;

  if (p->actionDir == FACE_UP_RIGHT || p->actionDir == FACE_DOWN_LEFT) {
    pos = p->mover.pos.x;
  } else {
    pos = p->mover.pos.z;
  }
  ofs = pos & 0xFF;
  if (ofs < 31 || ofs > 225) {
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/Player_IsNearTileCenter.inc");
#endif
}

// 壁に張り付く (PACT_UNK_4), state 1 で壁沿いに横歩きし, 壁の上へ登れる所では登り, A で壁を叩いて音を出す
// 残差3命令 (983/980), 横歩きで GetCollisionTileIdx の結果を受ける idx が原典は r6 に直接入るが, こちらは r0 で作って r6 へ写す (それで分岐先が1つずつずれる)
// Tier A-C 試済 (分岐の向き, + 8 を畳ませない分割, dir の使い回しで & 0xFF を残す, case 2 を if 連鎖, angle ローカル)
NON_MATCH void FUN_08067510(Player* p) {
#ifdef NONMATCHING_C
  u32 animIdx;

  p->action = PACT_UNK_4;
  if (p->state == 1 && (p->input->pressed & A_BUTTON)) {
    Player_SetAction(p, PACT_UNK_4, 2);
  }

  switch (p->state) {
    case 0: {
      Player_SetFlag20(p, PFLAG20_UNK_2);
      animIdx = Player_GetAnimIdx(p->kind, 2);
      if (p->animID != animIdx) {
        PlaySound_082406e0(SONG_208);
        p->facing = (p->actionDir + 4) & 7;
        PLAYER_SET_ANIM_DIR_HALF(p, p->actionDir);
      }
      if (Player_PlayAnim(p, animIdx, Q6(1))) {
        Player_SetAction(p, PACT_UNK_4, 1);
      }
      break;
    }
    case 1: {
      s32 dir;
      s32 left;
      s32 right;

      Player_SetFlag20(p, PFLAG20_UNK_3);
      p->unk_3bc = 1;
      dir = (s16)p->facingHistory[0];
      left = (p->actionDir + 7) & 7;
      right = (p->actionDir + 1) & 7;
      animIdx = Player_GetAnimIdx(p->kind, 3);
      if (dir != left && dir != right) {
        if (Player_IsNearTileCenter(p) && FUN_08003f24(&p->mover.pos, p->facing) > 0) {
          if (HasGoodCond(p, GOOD_POWER)) {
            Player_SetAction(p, PACT_IDLE, 0);
          } else {
            Player_SetAction(p, PACT_UNK_5, 0);
            p->unk_3bc = 0;
          }
        }
      } else {
        s32 turn = (dir - p->actionDir) * 2 + 8;
        Vec3 pos;
        s32 idx;
        s32 height;

        dir = (((p->actionDir + turn) & 7) + 1) & 7;
        pos = p->mover.pos;
        pos.x -= POLAR_X(50, dir << 5);
        pos.z -= POLAR_Z(50, dir << 5);
        idx = GetCollisionTileIdx(&pos);
        height = TileHeightAt(&pos);
        if (height > p->mover.pos.y - 128 && height < p->mover.pos.y + 128) {
          MapTileOverride* ov = Map_FindTileOverride(idx, 1);
          CollisionMapTile* tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];

          if (!Player_IsOnIce(tile->attr)) {
            pos.x -= POLAR_X(50, ((p->actionDir + 1) & 7) << 5);
            pos.z -= POLAR_Z(50, ((p->actionDir + 1) & 7) << 5);
            if (TileHeightAt(&pos) >= height + 200 && !(GetTileAttrAt(&pos) & TATTR_UNK_2)) {
              s32 speed;

              animIdx = Player_GetAnimIdx(p->kind, 4);
              if (p->human.animCmdIdx == 0) {
                speed = 0;
              } else if (p->human.animCmdIdx == 2) {
                speed = 6;
              } else {
                speed = 3;
              }
              p->mover.delta.x = -FixToInt(12, COS(dir << 5) * speed);
              p->mover.delta.z = -FixToInt(12, SIN(dir << 5) * speed);
            }
          }
        }
      }
      Player_PlayAnim(p, animIdx, Q6(1));
      if (p->animID == Player_GetAnimIdx(p->kind, 4) && p->human.animCmdIdx == 0 && p->human.animCmdTimer == 1) {
        PlaySound_082406e0(SONG_219);
      }
      break;
    }
    case 2: {
      Player_SetFlag20(p, PFLAG20_UNK_3);
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 5), Q6(1))) {
        Vec3 effectPos = p->mover.pos;
        Vec3 doorPos = p->mover.pos;
        Vec3 wallPos;

        if (p->actionDir == FACE_UP_RIGHT) {
          effectPos.x += 28, effectPos.y += 44, effectPos.z -= 76;
          doorPos.x += 64, doorPos.z -= 128;
        } else if (p->actionDir == FACE_DOWN_RIGHT) {
          effectPos.x -= 52, effectPos.y += 0, effectPos.z += 0;
          doorPos.x += 128, doorPos.z += 64;
        } else if (p->actionDir == FACE_DOWN_LEFT) {
          effectPos.x += 12, effectPos.y += 44, effectPos.z -= 32;
          doorPos.x += 64, doorPos.z += 128;
        } else if (p->actionDir == FACE_UP_LEFT) {
          effectPos.x -= 64, effectPos.y += 68, effectPos.z += 44;
          doorPos.x -= 128, doorPos.z += 64;
        }
        wallPos = p->mover.pos;
        wallPos.x -= POLAR_X(50, ((p->actionDir + 1) & 7) << 5);
        wallPos.z -= POLAR_Z(50, ((p->actionDir + 1) & 7) << 5);
        if (GetTileAttrAt(&wallPos) & TATTR_UNK_8) {
          FUN_08066e9c(p, &p->mover.pos, 256, 1, &effectPos, 1, SONG_235);
        } else {
          FUN_08066e9c(p, &p->mover.pos, 256, 1, &effectPos, 0, SONG_236);
        }
        if (FUN_08020358(GetCollisionTileIdx(&doorPos))) {
          PlaySound_082406e0(SONG_388);
        }
        Player_SetAction(p, PACT_UNK_4, 1);
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08067510.inc");
#endif
}

// ブロックを押す (PACT_UNK_5), actionDir へ 64 フレーム押し進め, 押し続けていて先へ進めるならもう一度, ちからの実が効いていれば素立ちに戻る
void FUN_08067de8(Player* p) {
  switch (p->state) {
    case 0: {
      s32 angle = ((p->actionDir + 5) & 7) * 32;
      p->mover.delta.x = POLAR_X(4, angle);
      p->mover.delta.z = POLAR_Z(4, angle);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 6), Q6(1));
      if (++p->stateTimer > 63) {
        Player_SetAction(p, PACT_UNK_5, 1);
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 6), Q6(1));
      if ((s16)p->facingHistory[0] == p->actionDir && FUN_08003f24(&p->mover.pos, p->facing) > 0) {
        if (HasGoodCond(p, GOOD_POWER)) {
          Player_SetAction(p, PACT_IDLE, 0);
        } else {
          Player_SetAction(p, PACT_UNK_5, 0);
        }
      } else {
        Player_SetAction(p, PACT_UNK_5, 2);
      }
      break;
    }
    case 2: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 7), Q6(1))) {
        Player_SetAction(p, PACT_UNK_4, 1);
        p->unk_3bc = 0;
      }
      break;
    }
  }
}

bool32 FUN_08067f58(Player* p) {
  if (Player_TestFlag20(p, PFLAG20_SUNBATHING) && p->ene < p->maxEne) {
    return TRUE;
  }
  return FALSE;
}

void FUN_08067f88(Player* p) {
  p->pos_930 = p->mover.pos;
  if (p->facing == FACE_DOWN) {
    p->pos_930.x -= Q8(0.08);
    p->pos_930.y += Q8(1.29);
    p->pos_930.z += Q8(0.235);
  } else {
    p->pos_930.x += Q8(0.08);
    p->pos_930.y += Q8(1.29);
    p->pos_930.z -= Q8(0.12);
  }
}

// 太陽チャージ (PACT_UNK_7), 構えたあと A を押し続けている間, 日光が当たっていて ENE が満タンでなければチャージ音を鳴らして光の粒を出す
void Player_UpdateSolarCharge(Player* p) {
  if (p->action != PACT_UNK_7) {
    Player_SetAction(p, PACT_UNK_7, 0);
    p->unk_951 = 0;
  }

  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      Player_SetAction(p, PACT_UNK_7, 1);
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        if (p->facing >= 2 && p->facing <= 6) {
          p->facing = FACE_DOWN;
          p->animIDOffset = 1;
          p->xflip = FALSE;
        } else {
          p->facing = 0;
          p->animIDOffset = 0;
          p->xflip = FALSE;
        }
        FUN_08067f88(p);
        p->stateTimer++;
      }
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        PlaySound_082406e0(SONG_203);
        if (!(p->input->down & A_BUTTON)) {
          Player_SetAction(p, PACT_UNK_7, 4);
        } else if (FUN_08067f58(p)) {
          PlaySound_082406e0(NOISE_SOLAR_CHARGE);
          p->unk_409 = 1;
          p->unk_404 = 0;
          Player_SetAction(p, PACT_UNK_7, 2);
        } else {
          p->unk_404 = 0;
          Player_SetAction(p, PACT_UNK_7, 3);
        }
      }
      break;
    }
    case 2: {
      Player_SetFlag20(p, PFLAG20_QC | PFLAG20_UNK_7);
      if (p->unk_404 < 5) {
        if (++p->unk_404 == 5) {
          if (p->kind == PLAYER_DARK_DJANGO) {
            PlaySound_082406e0(SONG_776);
          } else {
            PlaySound_082406e0(VO_RDJANGO_TAIYO_296);
          }
        }
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 9), Q6(1));
      p->shadowOffset.z = 30;
      FUN_08067f88(p);
      Player_SpawnSunPtcl858(p, &p->pos_930);
      if (!(p->input->down & A_BUTTON)) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->unk_409 = 0;
        Player_SetAction(p, PACT_UNK_7, 4);
      } else if (!FUN_08067f58(p)) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->unk_409 = 0;
        Player_SetAction(p, PACT_UNK_7, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag20(p, PFLAG20_UNK_7);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      p->shadowOffset.z = 30;
      if (!(p->input->down & A_BUTTON)) {
        Player_SetAction(p, PACT_UNK_7, 4);
      } else if (FUN_08067f58(p)) {
        PlaySound_082406e0(NOISE_SOLAR_CHARGE);
        p->unk_409 = 1;
        p->unk_404 = 0;
        Player_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 4: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        p->animIDOffset = p->facing;
        p->xflip = FALSE;
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

bool32 FUN_080682dc(Player* p) {
  if (!Player_TestFlag20(p, PFLAG20_SUNBATHING) && p->ene < p->maxEne) {
    return TRUE;
  }
  return FALSE;
}

// サバタの暗黒チャージ (PACT_UNK_7), 構えたあと A を押し続けている間, 日光が当たっていなくて ENE が満タンでなければチャージ音を鳴らして闇の粒を出す
void Player_UpdateDarkCharge(Player* p) {
  if (p->action != PACT_UNK_7) {
    Player_SetAction(p, PACT_UNK_7, 0);
  }

  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      Player_SetAction(p, PACT_UNK_7, 1);
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        if (p->facing >= 2 && p->facing <= 6) {
          p->facing = FACE_DOWN;
          p->animIDOffset = 1;
          p->xflip = FALSE;
        } else {
          p->facing = 0;
          p->animIDOffset = 0;
          p->xflip = FALSE;
        }
        FUN_08067f88(p);
        p->stateTimer++;
      }
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        PlaySound_082406e0(SONG_203);
        if (!(p->input->down & A_BUTTON)) {
          Player_SetAction(p, PACT_UNK_7, 4);
        } else if (FUN_080682dc(p)) {
          PlaySound_082406e0(VO_SABATA_ANKOKU);
          p->unk_409 = 1;
          p->unk_404 = 0;
          Player_SetAction(p, PACT_UNK_7, 2);
        } else {
          p->unk_404 = 0;
          Player_SetAction(p, PACT_UNK_7, 3);
        }
      }
      break;
    }
    case 2: {
      Player_SetFlag20(p, PFLAG20_QC | PFLAG20_UNK_7);
      if (p->unk_404 < 5) {
        if (++p->unk_404 == 5) {
          PlaySound_082406e0(SONG_569);
        }
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 9), Q6(1));
      p->shadowOffset.z = 30;
      FUN_08067f88(p);
      Player_SpawnPtcl858(p, &p->pos_930);
      p->plttID_95e = 290;
      if (p->stateTimer < 32) {
        p->plttFlashTimer = p->stateTimer;
      } else {
        p->plttFlashTimer = 64 - p->stateTimer;
      }
      if (++p->stateTimer > 64) {
        p->stateTimer = 0;
      }
      if (!(p->input->down & A_BUTTON)) {
        sound_08240740(SONG_569);
        p->unk_409 = 0;
        Player_SetAction(p, PACT_UNK_7, 4);
      } else if (!FUN_080682dc(p)) {
        sound_08240740(SONG_569);
        p->unk_409 = 0;
        Player_SetAction(p, PACT_UNK_7, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag20(p, PFLAG20_UNK_7);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      p->shadowOffset.z = 30;
      if (!(p->input->down & A_BUTTON)) {
        Player_SetAction(p, PACT_UNK_7, 4);
      } else if (FUN_080682dc(p)) {
        PlaySound_082406e0(SONG_569);
        p->unk_409 = 1;
        p->unk_404 = 0;
        Player_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 4: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        p->animIDOffset = p->facing;
        p->xflip = FALSE;
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 太陽スタンドを使う (PACT_UNK_8), unk_3b0 まで歩いて unk_3b8 を向き, A を押している間スタンドの貯金から ENE を受け取る
void Player_UpdateSolarStand(Player* p) {
  switch (p->state) {
    case 0: {
      s32 dx = p->unk_3b0.x - p->mover.pos.x;
      s32 dz = p->unk_3b0.z - p->mover.pos.z;
      s32 speed = CalcMoveSpeed(p);

      p->unk_951 = 0;
      if (dx * dx + dz * dz <= speed * speed) {
        p->mover.delta.x = dx;
        p->mover.delta.z = dz;
        p->facing = p->unk_3b8;
        Player_SetAnimFacing(p);
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
        if (p->facing > 4) {
          p->animIDOffset = 0;
          p->xflip = TRUE;
        } else {
          p->animIDOffset = 0;
          p->xflip = FALSE;
        }
        Player_SetAction(p, PACT_UNK_8, 1);
      } else {
        s32 angle = ArcTan2_8(dx, dz);

        p->mover.delta.x = POLAR_X(speed, angle);
        p->mover.delta.z = POLAR_Z(speed, angle);
        p->facing = Angle_ToDir8(angle);
        Player_SetAnimFacing(p);
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(1));
      }
      break;
    }
    case 1: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 12), Q6(1))) {
        PlaySound_082406e0(SONG_203);
        if (!(p->input->down & A_BUTTON)) {
          Player_SetAction(p, PACT_UNK_8, 4);
        } else if (p->kind == PLAYER_SABATA) {
          PlaySound_082406e0(SE_SOLAR_STAND_DENY);
          Player_SetAction(p, PACT_UNK_8, 3);
        } else if (p->ene >= p->maxEne) {
          PlaySound_082406e0(SE_DENY_302);
          Player_SetAction(p, PACT_UNK_8, 3);
        } else if (gStat->solarStand > 0) {
          PlaySound_082406e0(NOISE_SOLAR_CHARGE);
          p->unk_409 = 1;
          Player_SetAction(p, PACT_UNK_8, 2);
        } else {
          PlaySound_082406e0(SE_SOLAR_STAND_DENY);
          Player_SetAction(p, PACT_UNK_8, 3);
        }
      }
      break;
    }
    case 2: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 13), Q6(1));
      if (!(p->input->down & A_BUTTON)) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->unk_409 = 0;
        Player_SetAction(p, PACT_UNK_8, 4);
      } else if (p->ene >= p->maxEne) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->unk_409 = 0;
        PlaySound_082406e0(SE_DENY_302);
        Player_SetAction(p, PACT_UNK_8, 3);
      } else if (gStat->solarStand <= 0) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->unk_409 = 0;
        PlaySound_082406e0(SE_SOLAR_STAND_DENY);
        Player_SetAction(p, PACT_UNK_8, 3);
      } else {
        Player_SetFlag20(p, PFLAG20_UNK_6);
      }
      break;
    }
    case 3: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 14), Q6(1));
      if (!(p->input->down & A_BUTTON)) {
        Player_SetAction(p, PACT_UNK_8, 4);
      }
      break;
    }
    case 4: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 15), Q6(1))) {
        Player_SetAction(p, PACT_IDLE, 0);
        Player_SetAnimFacing(p);
      }
      break;
    }
  }
}

// 魔法ライジングサン, 真上か真下を向いて太陽の柱を出す
void MagicRisingSun_08068944(Player* p) {
  if (p->action != PACT_SUN_MAGIC) {
    p->unk_951 = 0;
    if (Player_HasEnoughEne(p, 100) && gSunMagicUsed == 0) {
      p->magicFired = TRUE;
    } else {
      p->magicFired = FALSE;
    }
    Player_SetAction(p, PACT_SUN_MAGIC, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->facing >= FACE_RIGHT && p->facing <= FACE_LEFT) {
        p->facing = FACE_DOWN;
        p->animIDOffset = 4;
        p->xflip = FALSE;
        p->pos_930 = p->mover.pos;
        p->pos_930.x -= Q8(0.08);
        p->pos_930.y += Q8(1.29);
        p->pos_930.z += Q8(0.235);
      } else {
        p->facing = FACE_UP;
        p->animIDOffset = 0;
        p->xflip = FALSE;
        p->pos_930 = p->mover.pos;
        p->pos_930.x += Q8(0.08);
        p->pos_930.y += Q8(1.29);
        p->pos_930.z -= Q8(0.08);
      }

      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      if (p->facing == FACE_DOWN) {
        p->animIDOffset = 1;
      } else {
        p->animIDOffset = 0;
      }

      if (p->magicFired) {
        PlaySound_082406e0(VO_RDJANGO_TAIYO_296);
        p->plttID_95e = 289;
        p->plttFlashTimer = 2;
        Entity080abd14_Create(p, &p->mover.pos, &p->pos_930, 0, p->unk_3ba);
      }

      Player_SetAction(p, PACT_SUN_MAGIC, 1);
      break;
    }
    case 1: {
      if (p->magicFired) {
        p->plttID_95e = 289;
        p->plttFlashTimer += 3;
        if (p->plttFlashTimer > 32) {
          p->plttFlashTimer = 32;
        }
      }

      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        PlaySound_082406e0(SONG_203);
        if (p->magicFired && p->unk_3ba == 0) {
          gSunMagicUsed = 1;
        }
        Player_SetAction(p, PACT_SUN_MAGIC, 2);
      }
      break;
    }
    case 2: {
      if (p->magicFired) {
        p->plttID_95e = 289;
        p->plttFlashTimer += 3;
        if (p->plttFlashTimer > 32) {
          p->plttFlashTimer = 32;
        }
      } else if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }

      p->shadowOffset.z = 30;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      if (++p->stateTimer > 23) {
        Player_SetAction(p, PACT_SUN_MAGIC, 3);
      }
      break;
    }
    case 3: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// gCoffin を動かしている間の移動速度, CalcMoveSpeed にチカラを足して gCoffin の重さ分を引いたもの
s32 Player_CalcCoffinMoveSpeed(Player* p) {
  s32 speed;
  if (HasGoodCond(p, GOOD_POWER)) {
    speed = 16;
  } else {
    s32 agility = p->stats[STAT_AGILITY];
    s32 over = p->armor.weight - 100;

    speed = Div((agility - over + p->stats[STAT_STRENGTH] - gCoffin->weight) * 12, 100);
    if (speed > 16) {
      speed = 16;
    } else if (speed < 6) {
      speed = 6;
    }
  }
  if (p->emitter.kind == 2 && p->emitter.unk_3 != 0) speed -= 3;
  if (p->speedPenalty != 0) speed -= p->speedPenalty;

  if (speed < 2) {
    speed = 2;
  }
  return speed;
}

// pos のタイルへ移れるか (壁でない, 溶岩や水でない, 段差が1ブロック未満), TATTR_UNK_11 のタイルなら pos を棺桶の位置に差し替え, 棺桶から離れていれば立ち止まる
bool32 FUN_08068d18(Player* p, Vec3* pos) {
  TileAttr attr = GetTileAttrAt(pos);
  WorldPos* coffin;

  if (attr & TATTR_UNK_0) {
    return FALSE;
  }
  if (!FUN_08086958() && (Player_IsInLava(attr) || (attr & TATTR_UNK_6))) {
    return FALSE;
  }
  if (abs(TileHeightAt(pos) - p->mover.pos.y) > 255) {
    return FALSE;
  }
  if (!(attr & TATTR_UNK_11)) {
    return TRUE;
  }
  coffin = Coffin_GetPos();
  if (abs(coffin->x - p->mover.pos.x) > 255 || abs(coffin->z - p->mover.pos.z) > 255) {
    PlaySound_082406e0(SONG_218);
    Player_SetAction(p, PACT_IDLE, 0);
  }
  *pos = *coffin;
  return TRUE;
}

NAKED void FUN_08068e94(Player* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_08068e94.inc"); }

// 棺桶を引いて歩く (PACT_PULL_COFFIN), 入力が無ければ止まって引く姿勢だけ取り, あれば重さに応じた速さで動いて足音を鳴らす
void Player_UpdatePullCoffin(Player* p) {
  s32 animSpeed;
  bool32 moving;
  u32 animIdx;
  s32 cos;
  s32 sin;

  if (p->action != PACT_PULL_COFFIN) {
    Player_SetAction(p, PACT_PULL_COFFIN, 0);
  }
  p->flag20 &= ~PFLAG20_UNK_0;
  if ((s16)p->facingHistory[0] < 0 || p->lookAroundOffset.val != 0) {
    s32 angle;

    animIdx = Player_GetAnimIdx(p->kind, 16);
    angle = (((p->useForcedDelta ? p->dir_3a7 : p->facing) + 1) & 7) << 5;
    cos = COS(angle);
    sin = SIN(angle);
    moving = FALSE;
    animSpeed = Q6(1);
  } else {
    s32 speed;
    s32 angle;

    animIdx = Player_GetAnimIdx(p->kind, 17);
    speed = Player_CalcCoffinMoveSpeed(p);
    moving = TRUE;
    p->facing = FUN_08067068(p);
    Player_SetAnimFacing(p);
    if (p->useForcedDelta) {
      animSpeed = Q6(0.5);
      angle = ((p->dir_3a7 + 1) & 7) << 5;
      cos = COS(angle);
      sin = SIN(angle);
    } else {
      if (speed == 8) {
        animSpeed = Q6(1);
      } else if (speed < 8) {
        animSpeed = (8 - speed) * 8 + 64;
      } else {
        animSpeed = 64 - (speed - 8) * 4;
      }
      angle = ((p->facing + 1) & 7) << 5;
      cos = COS(angle);
      sin = SIN(angle);
      if (p->human.animCmdIdx & 3) {
        p->mover.delta.x = -FixToInt(12, cos * speed);
        p->mover.delta.z = -FixToInt(12, sin * speed);
        if (p->tile.stairs[1] == 1) {
          if (p->mover.delta.z < 0) {
            p->mover.delta.z = FixToInt(6, p->mover.delta.z * 40);
          } else {
            p->mover.delta.z = FixToInt(6, p->mover.delta.z * 52);
          }
        } else if (p->tile.stairs[1] == 2) {
          if (p->mover.delta.x < 0) {
            p->mover.delta.x = FixToInt(6, p->mover.delta.x * 40);
          } else {
            p->mover.delta.x = FixToInt(6, p->mover.delta.x * 52);
          }
        }
      }
    }
  }

  if (moving && (s16)p->facingHistory[1] >= 0 && !(p->human.animCmdIdx & 3) && p->human.animCmdTimer == 0 && !HasGoodCond(p, GOOD_NINJA)) {
    if (Entity1DBE_TouchElemNear(&p->mover.pos)) {
      if (p->human.animCmdIdx == 0) {
        FUN_08066e9c(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SONG_355);
      } else {
        FUN_08066e9c(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SONG_354);
      }
    } else if (Player_IsOnRock(p->tile.attr[1]) && !HasGoodCond(p, GOOD_MINI)) {
      if (p->human.animCmdIdx == 0) {
        FUN_08066e9c(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SONG_404);
      } else {
        FUN_08066e9c(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SONG_403);
      }
    } else {
      if (p->unk_390 != 0 || p->tile.stairs[1] == 0) {
        if (p->human.animCmdIdx == 0) {
          PlaySound_082406e0(SE_FSTEP_M_1);
        } else {
          PlaySound_082406e0(SE_FSTEP_M_0);
        }
      } else {
        if (p->human.animCmdIdx == 0) {
          PlaySound_082406e0(SE_FSTEP_STAIRS_1);
        } else {
          PlaySound_082406e0(SE_FSTEP_STAIRS_0);
        }
      }
      if (TestMapFlag(MPF_UNK_0)) {
        FUN_08066e9c(p, &p->mover.pos, 1, 2, NULL, 0, SONG_NONE);
      }
    }
  }
  Player_PlayAnim(p, animIdx, animSpeed);
  if (moving || p->useForcedDelta) {
    FUN_08068e94(p, cos, sin, 150);
  }
}

void FUN_080695ec(Player* p) {
  if (p->action != PACT_ATTACK) {
    Player_SetAction(p, PACT_ATTACK, 0);
  }
  p->attackCB(p);
}

void FUN_0806961c(Player* p) {
  p->flag20 &= ~PFLAG20_UNK_0;
  if (p->emitter.unk_3 == 0) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// 行動 PACT_UNK_20, 入力方向へ向き直るたびに連打カウンタに応じて効果音を鳴らし, unk_3ff が空けば素立ちに戻る
void FUN_08069648(Player* p) {
  if ((s16)p->facingHistory[0] >= 0 && p->facing != (s16)p->facingHistory[0]) {
    if (p->mashCount & 1) {
      if ((p->mashCount >> 1) & 1) {
        FUN_08066e9c(p, &p->mover.pos, 1, 1, NULL, 0, SE_UNK_278);
      } else {
        FUN_08066e9c(p, &p->mover.pos, 1, 1, NULL, 0, SE_UNK_279);
      }
    }
    p->facing = p->facingHistory[0];
    Player_SetAnimFacing(p);
  }
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
  if (p->unk_3ff < 0) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// フリーズの魔法, 向いている方向の少し先に氷結エフェクトを出す
void MagicFreeze_08069710(Player* p) {
  if (p->action != PACT_FREEZE) {
    if (Player_HasEnoughSunGauge(p, 0)) {
      s32 radius;

      WorldPos pos = p->mover.pos;
      s32 angle = ((p->facing + 5) & 7) * 32;
      pos.x += POLAR_X(150, angle);
      pos.z += POLAR_Z(150, angle);
      radius = gStat->sunGauge * 60 + 120;
      FreezeEffect_Create(&pos, 1 << p->mover.unk_4, radius, angle, 90);
      p->magicFired = TRUE;
    } else {
      p->magicFired = FALSE;
    }

    PlaySound_082406e0(VO_DJANGO_MAGIC);
    Player_SetAction(p, PACT_FREEZE, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->magicFired) {
        p->plttID_95e = 292;
        p->plttFlashTimer = 32;
      }
      if (Player_PlayAnim(p, 164, Q6(1))) {
        if (p->magicFired) {
          Player_SetAction(p, PACT_FREEZE, 1);
        } else {
          Player_SetAction(p, PACT_FREEZE, 2);
        }
      }
      break;
    }
    case 1: {
      p->plttID_95e = 292;
      p->plttFlashTimer = 32;
      Player_PlayAnim(p, 174, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 31) {
        Player_SetAction(p, PACT_FREEZE, 3);
      }
      break;
    }
    case 2: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }
      Player_PlayAnim(p, 169, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 15) {
        Player_SetAction(p, PACT_FREEZE, 3);
      }
      break;
    }
    case 3: {
      if (Player_PlayAnim(p, 164, Q6(1))) {
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// ヒーリングの魔法, 向いている方向の少し先に回復の粒を出す
void MagicHealing_08069928(Player* p) {
  if (p->action != PACT_HEALING) {
    if (Player_HasEnoughSunGauge(p, 2)) {
      WorldPos pos = p->mover.pos;
      s32 angle = ((p->facing + 5) & 7) * 32;
      pos.x += POLAR_X(Q8(0.586), angle);
      pos.z += POLAR_Z(Q8(0.586), angle);
      HealingParticles_Create(p, &pos);
      p->magicFired = TRUE;
    } else {
      p->magicFired = FALSE;
    }

    PlaySound_082406e0(VO_DJANGO_MAGIC);
    Player_SetAction(p, PACT_HEALING, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->magicFired) {
        p->plttID_95e = 294;
        p->plttFlashTimer = 32;
      }
      if (Player_PlayAnim(p, 164, Q6(1))) {
        if (p->magicFired) {
          Player_SetAction(p, PACT_HEALING, 1);
        } else {
          Player_SetAction(p, PACT_HEALING, 2);
        }
      }
      break;
    }
    case 1: {
      p->plttID_95e = 294;
      p->plttFlashTimer = 32;
      Player_PlayAnim(p, 174, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 31) {
        Player_SetAction(p, PACT_HEALING, 3);
      }
      break;
    }
    case 2: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }
      Player_PlayAnim(p, 169, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 15) {
        Player_SetAction(p, PACT_HEALING, 3);
      }
      break;
    }
    case 3: {
      if (Player_PlayAnim(p, 164, Q6(1))) {
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// ダイナマイトの魔法, 太陽ゲージが足りていれば爆弾を1個出し, 以降は発動したかどうかで演出を振り分ける
void MagicDynamite_08069b18(Player* p) {
  if (p->action != PACT_DYNAMITE) {
    if (p->unk_390 != 0) {
      p->magicFired = FALSE;
    } else if (Player_HasEnoughSunGauge(p, 3)) {
      p->magicFired = TRUE;
      Entity080a8ff8_Create(p, &p->mover.pos, 0);
    } else {
      p->magicFired = FALSE;
    }
    Player_SetAction(p, PACT_DYNAMITE, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->magicFired) {
        p->plttID_95e = 291;
        p->plttFlashTimer = 32;
      }
      if (Player_PlayAnim(p, 184, Q6(1))) {
        if (p->magicFired) {
          Player_SetAction(p, PACT_DYNAMITE, 1);
        } else {
          Player_SetAction(p, PACT_DYNAMITE, 2);
        }
      }
      break;
    }
    case 1: {
      if (p->magicFired) {
        p->plttID_95e = 291;
        p->plttFlashTimer = 32;
      }
      p->stateTimer++;
      if (p->stateTimer > 11) {
        Player_SetAction(p, PACT_DYNAMITE, 3);
      }
      break;
    }
    case 2: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }
      Player_PlayAnim(p, 194, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 11) {
        Player_SetAction(p, PACT_DYNAMITE, 3);
      }
      break;
    }
    case 3: {
      if (Player_PlayAnim(p, 189, Q6(1))) {
        Player_SetAction(p, PACT_IDLE, 1);
      }
      break;
    }
  }
}

// PACT_UNK_18 の行動, ボタン連打で unk_3EC を減らし, 0 になったら終わりのアニメを経て PACT_IDLE に戻る
void FUN_08069c8c(Player* p) {
  if (p->action != PACT_UNK_18) {
    Player_StopEneChargeSound(p);
    Player_SetAction(p, PACT_UNK_18, 0);
  }
  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 48), Q6(1))) {
        Player_SetAction(p, PACT_UNK_18, 1);
      }
      break;
    }
    case 1: {
      s32 n;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 49), Q6(1));
      n = 1;
      if (p->input->pressed & (A_BUTTON | B_BUTTON | DPAD_RIGHT | DPAD_LEFT | DPAD_UP | DPAD_DOWN)) {
        n = 2;
      }
      if (p->unk_3ec > n) {
        p->unk_3ec -= n;
      } else {
        p->unk_3ec = 0;
        Player_SetAction(p, PACT_UNK_18, 2);
      }
      break;
    }
    case 2: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 50), Q6(1))) {
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 人型の落下 (PACT_UNK_22), カメラを上に向けて落下アニメを当て, 6フレーム後に沈み始めて途中で声を上げ, 30 フレームで消える
void Player_UpdateFall(Player* p) {
  Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
  switch (p->state) {
    case 0: {
      Vec3 pos = p->mover.pos;

      pos.y += 150;
      Camera_LookAt(&pos);
      if (p->unk_3f0 != 0) {
        FUN_0823ce68(3, 3, 4, 4, 4, 0x1FFF, 16);
      } else {
        FUN_0823ce68(3, 3, 4, 4, 4, 0x1FFF, 1);
      }
      PlaySound_082406e0(SONG_429);
      PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
      Player_SetAction(p, PACT_UNK_22, 1);
      p->floatHeight = 0;
      break;
    }
    case 1: {
      if (++p->stateTimer > 5) {
        Player_SetAction(p, PACT_UNK_22, 2);
        p->floatHeight = 0;
        p->beast.priority = 1;
        PlaySound_082406e0(SONG_430);
      }
      break;
    }
    case 2: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 18), Q6(1));
      p->floatHeight -= 60;
      if (p->stateTimer == 4) {
        if (p->kind == PLAYER_SABATA) {
          PlaySound_082406e0(VO_SABATA_749);
        } else {
          PlaySound_082406e0(VO_DJANGO_773);
        }
      }
      if (++p->stateTimer > 29) {
        Player_SetAction(p, PACT_UNK_22, 3);
      }
      break;
    }
    case 3: {
      p->floatHeight = 0;
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
      break;
    }
  }
}

// PACT_UNK_23 の行動, heightAboveTile を毎フレーム 30 ずつ減らして落下し, 着地したら着地アニメを経て PACT_IDLE に戻る
void FUN_08069f60(Player* p) {
  Player_SetFlag35a(p, 8);
  switch (p->state) {
    case 0: {
      if (p->animID != 0x2C) {
        p->facing |= 1;
        PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 18), Q6(1));
      if ((u16)p->heightAboveTile <= 30) {
        p->heightAboveTile = 0;
        PlaySound_082406e0(SONG_432);
        Player_SetAction(p, PACT_UNK_23, 1);
      } else {
        p->heightAboveTile -= 30;
      }
      break;
    }
    case 1: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 19), Q6(1))) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

void FUN_0806a050(Player* p) {
  if (p->unk_3fe != 0) {
    Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW | PFLAG35A_NO_HURTBOX | PFLAG35A_NO_TILE);
  } else {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW | PFLAG35A_NO_HURTBOX | PFLAG35A_NO_TILE);
  }
  Player_SetFlag20(p, PFLAG20_UNK_12 | PFLAG20_UNK_8);
}

// 被弾 (PACT_DAMAGED), 吹き飛びながら knockbackOrigin やタイルから弾かれたときはそちらへ寄せて炎か煙を出し, 止まったら起き上がって PACT_UNK_19 か PACT_IDLE に戻る
void Player_UpdateHurt(Player* p) {
  if (p->action != PACT_DAMAGED) {
    Player_SetAction(p, PACT_DAMAGED, 0);
    PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
    Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
    p->floatHeight = 0;
    if (p->hurtSound != SONG_NONE) {
      PlaySound_082406e0(p->hurtSound);
      p->hurtSound = SONG_NONE;
    }
  }
  if (p->hurtbox.knockbackPower != 0) {
    if (p->originKnockback) {
      s32 dx = p->knockbackOrigin->x - p->mover.pos.x;
      s32 dz = p->knockbackOrigin->z - p->mover.pos.z;

      p->mover.delta.x = FixToInt(3, dx);
      p->mover.delta.z = FixToInt(3, dz);
      if (p->stateTimer <= 5) {
        if (!(p->stateTimer & 1)) {
          PlaySound_082406e0(SE_IGNITE);
          Entity080acd4c_Spawn(&p->mover.pos);
        }
        p->stateTimer++;
      }
    } else if (p->tileKnockback) {
      s32 dx = p->knockbackOrigin->x - p->mover.pos.x;
      s32 dz = p->knockbackOrigin->z - p->mover.pos.z;

      p->mover.delta.x = FixToInt(3, dx);
      p->mover.delta.z = FixToInt(3, dz);
      if (p->stateTimer <= 5) {
        if (!(p->stateTimer & 1)) {
          PlaySound_082406e0(SE_IGNITE);
          EmitSmoke(&p->mover.pos, 1, NULL, 0, 0, 12, 2, 2);
        }
        p->stateTimer++;
      }
    } else {
      s32 angle = ((p->facing + 5) & 7) * 32;

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockbackPower);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockbackPower);
    }
    Camera_Shake(p->hurtbox.knockbackPower);
    p->hurtbox.knockbackPower = (p->hurtbox.knockbackPower * 3) >> 2;
  } else {
    p->hurtbox.knockbackPower = 0;
    p->originKnockback = FALSE;
    p->tileKnockback = FALSE;
    if (p->emitter.kind == 3 && p->emitter.unk_3 != 0) {
      Player_SetAction(p, PACT_UNK_19, 0);
    } else if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 42), Q6(1))) {
      Player_SetAnimFacing(p);
      Player_SetAction(p, PACT_IDLE, 0);
    }
  }
}

// 吹き飛ばされる被弾 (PACT_BLOWN_AWAY), 宙に浮いて後ろへ飛び, 着地して倒れたあと起き上がって PACT_IDLE に戻る
void Player_UpdateBlownAway(Player* p) {
  if (p->action != PACT_BLOWN_AWAY) {
    Player_SetAction(p, PACT_BLOWN_AWAY, 0);
    PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
    if (p->hurtSound != SONG_NONE) {
      PlaySound_082406e0(p->hurtSound);
      p->hurtSound = SONG_NONE;
    }
  }

  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
      if (++p->stateTimer > 2) {
        Player_SetAction(p, PACT_BLOWN_AWAY, 1);
      }
      break;
    }
    case 1: {
      s32 angle;

      if (p->stateTimer == 0) {
        p->floatHeight = 300;
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 43), Q6(1));
      angle = ((p->facing + 5) & 7) << 5;
      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockbackPower);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockbackPower);
      p->hurtbox.knockbackPower = (p->hurtbox.knockbackPower * 3) >> 2;
      if (p->stateTimer > 3) {
        if (p->floatHeight >= p->stateTimer * 8) {
          p->floatHeight -= p->stateTimer * 8;
        } else {
          p->floatHeight = 0;
        }
      }
      p->stateTimer++;
      if (p->hurtbox.knockbackPower < 20 && p->floatHeight == 0) {
        p->floatHeight = 0;
        PlaySound_082406e0(SONG_680);
        Player_SetAction(p, PACT_BLOWN_AWAY, 2);
      }
      break;
    }
    case 2: {
      s32 angle = ((p->facing + 5) & 7) << 5;

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockbackPower);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockbackPower);
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 44), Q6(1))) {
        p->hurtbox.knockbackPower = 0;
        Player_SetAction(p, PACT_BLOWN_AWAY, 3);
      }
      break;
    }
    case 3: {
      if (++p->stateTimer > 19) {
        Player_SetAction(p, PACT_BLOWN_AWAY, 4);
      }
      break;
    }
    case 4: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 45), Q6(1))) {
        p->blownAway = 0;
        Player_SetAnimFacing(p);
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 倒れて死ぬ (PACT_UNK_26), 吹き飛びが収まるまで後ろへ流され, 倒れるアニメのあとゲームオーバーへ移って点滅しながら消える
void Player_UpdateDeath(Player* p) {
  if (p->action != PACT_UNK_26) {
    Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
    p->knockbackTimer = 0;
    PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
    Player_SetAction(p, PACT_UNK_26, 0);
    if (p->kind == PLAYER_SABATA) {
      PlaySound_082406e0(VO_SABATA_DEATH);
    } else {
      PlaySound_082406e0(SONG_231);
    }
    PlaySound_082406e0(SE_DAMAGE);
    if (gGameFlags & FLAG030047A4_UNK_12) {
      FUN_08050d10();
    }
  }

  switch (p->state) {
    case 0: {
      s32 angle = ((p->facing + 1) & 7) << 5;

      p->mover.delta.x = FixToInt(12, COS(angle) * p->hurtbox.knockbackPower);
      p->mover.delta.z = FixToInt(12, SIN(angle) * p->hurtbox.knockbackPower);
      p->hurtbox.knockbackPower = (p->hurtbox.knockbackPower * 3) >> 2;
      if (p->hurtbox.knockbackPower == 0) {
        Player_SetAction(p, PACT_UNK_26, 1);
      }
      break;
    }
    case 1: {
      if (p->human.animCmdIdx == 3 && p->human.animCmdTimer == 0) {
        PlaySound_082406e0(SONG_209);
      }
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 46), Q6(1))) {
        if (!(gGameFlags & FLAG030047A4_UNK_12)) {
          Player_SetAction(p, PACT_UNK_26, 2);
        } else {
          Player_SetAction(p, PACT_UNK_26, 3);
        }
      }
      break;
    }
    case 2: {
      if (++p->stateTimer > 15) {
        gGameFlags |= FLAG030047A4_GAMEOVER;
        Player_SetAction(p, PACT_UNK_26, 3);
      }
      break;
    }
    case 3: {
      if (++p->stateTimer > 15) {
        p->human.priority = 1;
      }
      break;
    }
    case 4: {
      if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 3)) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 55) {
        Player_SetAction(p, PACT_UNK_26, 5);
      }
      break;
    }
    case 5: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      break;
    }
  }
}

// 吹き飛ばされて死ぬ (PACT_UNK_27), 宙に浮いて後ろへ飛び, 着地して倒れたあとゲームオーバーへ移って点滅しながら消える
void Player_UpdateBlownAwayDeath(Player* p) {
  if (p->action != PACT_UNK_27) {
    Player_SetAction(p, PACT_UNK_27, 0);
    PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
    if (p->kind == PLAYER_SABATA) {
      PlaySound_082406e0(VO_SABATA_DEATH);
    } else {
      PlaySound_082406e0(SONG_231);
    }
    PlaySound_082406e0(SE_DAMAGE);
    if (gGameFlags & FLAG030047A4_UNK_12) {
      FUN_08050d10();
    }
  }

  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
      if (++p->stateTimer > 3) {
        Player_SetAction(p, PACT_UNK_27, 1);
        p->floatHeight = 300;
      }
      break;
    }
    case 1: {
      s32 angle;

      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 43), Q6(1));
      angle = ((p->facing + 5) & 7) << 5;
      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockbackPower);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockbackPower);
      p->hurtbox.knockbackPower = (p->hurtbox.knockbackPower * 3) >> 2;
      if (p->floatHeight > 14) {
        p->floatHeight -= 15;
      } else {
        p->floatHeight = 0;
      }
      if (p->hurtbox.knockbackPower < 20) {
        Player_SetAction(p, PACT_UNK_27, 2);
        p->floatHeight = 0;
        PlaySound_082406e0(SONG_680);
      }
      break;
    }
    case 2: {
      s32 angle = ((p->facing + 5) & 7) << 5;

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockbackPower);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockbackPower);
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 44), Q6(1))) {
        p->hurtbox.knockbackPower = 0;
        if (!(gGameFlags & FLAG030047A4_UNK_12)) {
          Player_SetAction(p, PACT_UNK_27, 3);
        } else {
          Player_SetAction(p, PACT_UNK_27, 4);
        }
      }
      break;
    }
    case 3: {
      if (++p->stateTimer > 19) {
        gGameFlags |= FLAG030047A4_GAMEOVER;
        Player_SetAction(p, PACT_UNK_27, 4);
      }
      break;
    }
    case 4: {
      if (++p->stateTimer > 15) {
        p->human.priority = 1;
      }
      break;
    }
    case 5: {
      if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 3)) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 55) {
        Player_SetAction(p, PACT_UNK_27, 6);
      }
      break;
    }
    case 6: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      break;
    }
  }
}

// 落下して死ぬ (PACT_UNK_28), 沈みながら点滅して消え, 1秒後にゲームオーバーへ移る
void Player_UpdateFallDeath(Player* p) {
  Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
      PlaySound_082406e0(SONG_429);
      p->beast.priority = 1;
      Player_SetAction(p, PACT_UNK_28, 1);
      p->floatHeight = 0;
      p->mover.tile = NULL;
      break;
    }
    case 1: {
      if (++p->stateTimer > 14) {
        FUN_0823ce68(3, 5, 4, 4, 4, 0x1FFF, 2);
        p->floatHeight = 0;
        Player_SetAction(p, PACT_UNK_28, 2);
      }
      break;
    }
    case 2: {
      if (p->stateTimer == 9) {
        if (p->kind == PLAYER_SABATA) {
          PlaySound_082406e0(SONG_748);
        } else {
          PlaySound_082406e0(VO_SOLAR_DJANGO_SCREAM);
        }
      }
      if (++p->stateTimer > 14) {
        Player_SetAction(p, PACT_UNK_28, 3);
        p->floatHeight = 0;
        PlaySound_082406e0(SONG_431);
      }
      break;
    }
    case 3: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 18), Q6(1));
      p->floatHeight -= 30;
      if (++p->stateTimer > 39) {
        p->hp = 0;
        Player_SetAction(p, PACT_UNK_28, 4);
      } else {
        Sprite_UpdateVanishBlink(&p->beast.flags, p->stateTimer, 10, 20);
      }
      break;
    }
    case 4: {
      p->floatHeight = 0;
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
      if (++p->stateTimer > 59) {
        Player_SetAction(p, PACT_UNK_28, 5);
        gGameFlags |= FLAG030047A4_GAMEOVER;
      }
      break;
    }
    case 5: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
      break;
    }
  }
}

// PACT_FALLDEATH の行動, 足元の TATTR_UNK_6 に落ちて沈み (MPF_UNK_13 のマップ), HP を 0 にして画面を暗転させゲームオーバーにする
void FUN_0806adc8(Player* p) {
  Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
      PlaySound_082406e0(SONG_429);
      p->beast.priority = 1;
      Player_SetAction(p, PACT_FALLDEATH, 1);
      p->floatHeight = 0;
      p->mover.tile = NULL;
      break;
    }
    case 1: {
      if (++p->stateTimer > 14) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
        PlaySound_082406e0(SONG_430);
        Player_SetAction(p, PACT_FALLDEATH, 2);
      }
      break;
    }
    case 2: {
      p->floatHeight -= 30;
      if (++p->stateTimer > 3) {
        FUN_08016110(1, 0, 0, 30, &p->mover.pos);
        PlaySound_082406e0(SONG_325);
        p->hp = 0;
        Player_SetAction(p, PACT_FALLDEATH, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
      if (++p->stateTimer > 29) {
        FUN_0823ce68(3, 5, 4, 4, 4, 0x1FFF, 2);
        Player_SetAction(p, PACT_FALLDEATH, 4);
      }
      break;
    }
    case 4: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
      if (++p->stateTimer > 29) {
        Player_SetAction(p, PACT_FALLDEATH, 5);
        gGameFlags |= FLAG030047A4_GAMEOVER;
      }
      break;
    }
    case 5: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
      break;
    }
  }
}

// PACT_UNK_30 の行動, 声を出して 0x2E のアニメを4コマごとに効果音付きで流し, 終わって15フレーム後に FUN_08060e90(p, 1) を呼ぶ
void FUN_0806af70(Player* p) {
  switch (p->state) {
    case 0: {
      if (p->stateTimer == 0) {
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
        if (p->kind == PLAYER_SABATA) {
          PlaySound_082406e0(SONG_750);
        } else {
          PlaySound_082406e0(SONG_769);
        }
      }
      if (++p->stateTimer > 5) {
        Player_SetAction(p, PACT_UNK_30, 1);
      }
      break;
    }
    case 1: {
      if (!(p->human.animCmdIdx & 3) && p->human.animCmdTimer == 0) {
        PlaySound_082406e0(SONG_209);
      }
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 46), Q6(1))) {
        Player_SetAction(p, PACT_UNK_30, 2);
      }
      break;
    }
    case 2: {
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_UNK_30, 3);
        FUN_08060e90(p, 1);
      }
      break;
    }
  }
}

// PACT_UNK_32, state 0 は mashKeys の連打の多さに応じた速さで歩くアニメを回し, state 1 以降は落下して消える
// 残差1命令 (306/307), 原典は mashHits を読んだレジスタを r1 に複写して比較に使い計算は元の r0 で行うが, こちらは複写せず r0 だけで済ませる
// Tier A-C 試済 (n を u16/s32/u32, 計算だけ p->mashHits 直読み, 0 の分岐を先に書く)
NON_MATCH void FUN_0806b06c(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != PACT_UNK_32) {
    Player_SetAction(p, PACT_UNK_32, 0);
  }

  switch (p->state) {
    case 0: {
      s32 i;
      u16 n;

      p->facing = FACE_UP_LEFT;
      p->animIDOffset = 1;
      p->xflip = TRUE;
      p->mashHits = 0;
      for (i = 31; i > 0; i--) {
        if (p->mashHistory[i - 1]) {
          p->mashHits++;
        }
        p->mashHistory[i] = p->mashHistory[i - 1];
      }
      if (p->input->pressed & p->mashKeys) {
        p->mashHistory[0] = TRUE;
        p->mashHits++;
      } else {
        p->mashHistory[0] = FALSE;
      }

      n = p->mashHits;
      if (n != 0) {
        if (n <= 3) {
          p->mashAnimSpeed = 128 - n * 16;
        } else if (n <= 5) {
          p->mashAnimSpeed = 64 - (n - 2) * 8;
        } else if (n <= 7) {
          p->mashAnimSpeed = 32 - (n - 4) * 4;
        } else {
          p->mashAnimSpeed = 16;
        }
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), p->mashAnimSpeed);
        if (p->human.animCmdTimer == 0) {
          if (p->human.animCmdIdx == 0) {
            PlaySound_082406e0(SE_FSTEP_STAIRS_1);
          } else if (p->human.animCmdIdx == 3) {
            PlaySound_082406e0(SE_FSTEP_STAIRS_0);
          }
        }
      } else {
        p->mashAnimSpeed = 0;
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), p->mashAnimSpeed);
      }
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        p->facing = FACE_UP_LEFT;
        p->animIDOffset = 0;
        p->xflip = TRUE;
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
        PlaySound_082406e0(SONG_429);
        p->floatHeight = 0;
      }
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      if (++p->stateTimer > 5) {
        PlaySound_082406e0(SONG_430);
        if (p->kind == PLAYER_SABATA) {
          PlaySound_082406e0(SONG_748);
        } else {
          PlaySound_082406e0(VO_SOLAR_DJANGO_SCREAM);
        }
        Player_SetAction(p, PACT_UNK_32, 2);
      }
      break;
    }
    case 2: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 18), Q6(1));
      p->floatHeight -= 60;
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      if (++p->stateTimer > 29) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
        p->floatHeight = 1500;
        Player_SetAction(p, PACT_UNK_32, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      p->stateTimer++;
      break;
    }
    case 4: {
      p->facing = FACE_UP_LEFT;
      p->animIDOffset = 1;
      p->xflip = TRUE;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      p->floatHeight = 0;
      p->stateTimer++;
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_0806b06c.inc");
#endif
}

// サバタのダッシュ, 16フレームの間 食らい判定を消して点滅しながら前へ進む
void Magic_ZeroShift(Player* p) {
  if (p->action != PACT_DASH) {
    Player_SetAction(p, PACT_DASH, 0);
    PlaySound_082406e0(SONG_836);
  }
  Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
  if (++p->stateTimer >= 16) {
    Player_SetAction(p, PACT_IDLE, 0);
  } else {
    Player_SetFlag35a(p, PFLAG35A_BLINK);
    if (p->stateTimer >= 5 && p->stateTimer <= 12) {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
    }
    Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
    p->plttID_95e = 295;
    p->plttFlashTimer = 24;
    if (!p->useForcedDelta) {
      Player_SetMoveDelta(p, 32);
    }
    Player_SetAnimFacing(p);
    Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(1));
  }
}

// サバタの魔法ブラックサン, 真上か真下を向いて暗黒の柱を出す
void Sabata_BlackSun(Player* p) {
  if (p->action != PACT_SUN_MAGIC) {
    p->unk_951 = 0;
    if (Player_HasEnoughEne(p, 100) && gSunMagicUsed == 0) {
      p->magicFired = TRUE;
    } else {
      p->magicFired = FALSE;
    }
    Player_SetAction(p, PACT_SUN_MAGIC, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->facing >= FACE_RIGHT && p->facing <= FACE_LEFT) {
        p->facing = FACE_DOWN;
        p->animIDOffset = 4;
        p->xflip = FALSE;
        p->pos_930 = p->mover.pos;
        p->pos_930.x -= Q8(0.08);
        p->pos_930.y += Q8(1.29);
        p->pos_930.z += Q8(0.235);
      } else {
        p->facing = FACE_UP;
        p->animIDOffset = 0;
        p->xflip = FALSE;
        p->pos_930 = p->mover.pos;
        p->pos_930.x += Q8(0.08);
        p->pos_930.y += Q8(1.29);
        p->pos_930.z -= Q8(0.08);
      }

      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      if (p->facing == FACE_DOWN) {
        p->animIDOffset = 1;
      } else {
        p->animIDOffset = 0;
      }

      if (p->magicFired) {
        PlaySound_082406e0(VO_SABATA_ANKOKU);
        p->plttID_95e = 290;
        p->plttFlashTimer = 2;
        Entity080abd14_Create(p, &p->mover.pos, &p->pos_930, 1, p->unk_3ba);
      }

      Player_SetAction(p, PACT_SUN_MAGIC, 1);
      break;
    }
    case 1: {
      if (p->magicFired) {
        p->plttID_95e = 290;
        p->plttFlashTimer += 3;
        if (p->plttFlashTimer > 32) {
          p->plttFlashTimer = 32;
        }
      }

      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        PlaySound_082406e0(SONG_203);
        if (p->magicFired && p->unk_3ba == 0) {
          gSunMagicUsed = 1;
        }
        Player_SetAction(p, PACT_SUN_MAGIC, 2);
      }
      break;
    }
    case 2: {
      if (p->magicFired) {
        p->plttID_95e = 290;
        p->plttFlashTimer += 3;
        if (p->plttFlashTimer > 32) {
          p->plttFlashTimer = 32;
        }
      } else if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }

      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      p->shadowOffset.z = 30;
      p->stateTimer++;
      if (p->stateTimer > 23) {
        Player_SetAction(p, PACT_SUN_MAGIC, 3);
      }
      break;
    }
    case 3: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// サバタの PACT_UNK_31, 白い "!" を出して棺桶の方を向き, 倒れたあとゲームオーバーへ移って点滅しながら消える
void FUN_0806b758(Player* p) {
  switch (p->state) {
    case 0: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SONG_231);
        p->emoteKind = EMOTE_0;
        p->unk_992 = 0;
        p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 1, NULL, 0, 0, 80);
        PlaySound_082406e0(SONG_433);
        if (gCoffin != NULL) {
          p->facing = Angle_ToDir8(ArcTan2_8(gCoffin->mover.pos.x - p->mover.pos.x, gCoffin->mover.pos.z - p->mover.pos.z));
          Player_SetAnimFacing(p);
        }
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      if (++p->stateTimer > 89) {
        PlaySound_082406e0(SONG_208);
        Player_SetAction(p, PACT_UNK_31, 1);
      }
      break;
    }
    case 1: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 48), Q6(1))) {
        Player_SetAction(p, PACT_UNK_31, 2);
      }
      break;
    }
    case 2: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 49), Q6(1));
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_UNK_31, 3);
        gGameFlags |= FLAG030047A4_GAMEOVER;
      }
      break;
    }
    case 3: {
      break;
    }
    case 4: {
      if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 3)) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 55) {
        Player_SetAction(p, PACT_UNK_31, 5);
      }
      break;
    }
    case 5: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      break;
    }
  }
}

// 魔法トランス, 赤ジャンゴと黒ジャンゴを入れ替える
// 残差2命令 (331/333): case 2 の stateTimer の16bit化だけ, 原典は 0xFFFF をレジスタに置いて ands で切るが agbcc は lsls/lsrs を選ぶ
// ands になるのは u32 の中間変数に受けて & 0xFFFF と書いたときだけ (単体で確認), 不自然なので採らない
// stateTimer++ / u16 の中間変数 / (u16) キャスト / > 31 と < 32 の反転はいずれも lsls/lsrs, clamp を static inline にしても変わらない
// Tier A-C 試済, 未: per-TU フラグ
NON_MATCH void MagicTransform_0806b92c(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != PACT_TRANSFORM) {
    if (Player_HasEnoughEne(p, 0)) {
      p->plttID_95e = 295;
      p->plttFlashTimer = 0;
      p->magicFired = TRUE;
    } else {
      p->magicFired = FALSE;
    }
    PlaySound_082406e0(VO_DJANGO_MAGIC);
    Player_SetAction(p, PACT_TRANSFORM, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->facing >= FACE_RIGHT && p->facing <= FACE_LEFT) {
        p->facing = FACE_DOWN;
        p->animIDOffset = 4;
        p->xflip = FALSE;
      } else {
        p->facing = FACE_UP;
        p->animIDOffset = 0;
        p->xflip = FALSE;
      }

      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      p->animIDOffset >>= 2;

      if (p->magicFired) {
        Vec3 pos;

        pos.x = 0, pos.y = 0, pos.z = 15;
        if (p->kind == PLAYER_SOLAR_DJANGO) {
          TransEffect_Create(p, 7, &pos, 50, 69);
        } else {
          TransEffect_Create(p, 7, &pos, 50, 69);
        }
        PlaySound_082406e0(SE_TRANSFORM);
      }

      Player_SetAction(p, PACT_TRANSFORM, 1);
      break;
    }
    case 1: {
      if (p->magicFired) {
        p->plttFlashTimer += 3;
        if (p->plttFlashTimer > 32) {
          p->plttFlashTimer = 32;
        }
      }

      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        if (p->magicFired) {
          Player_SetAction(p, PACT_TRANSFORM, 2);
        } else {
          Player_SetAction(p, PACT_TRANSFORM, 3);
        }
      }
      break;
    }
    case 2: {
      if ((p->stateTimer & 7) < 7 - (p->stateTimer >> 2)) {
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      } else if (p->kind == PLAYER_SOLAR_DJANGO) {
        Player_PlayAnim(p, Player_GetAnimIdx(PLAYER_DARK_DJANGO, 10), Q6(1));
      } else {
        Player_PlayAnim(p, Player_GetAnimIdx(PLAYER_SOLAR_DJANGO, 10), Q6(1));
      }

      p->plttFlashTimer += 3;
      if (p->plttFlashTimer > 32) {
        p->plttFlashTimer = 32;
      }

      p->shadowOffset.z = 30;
      p->stateTimer++;
      if (p->stateTimer > 31) {
        if (p->kind == PLAYER_SOLAR_DJANGO) {
          p->kind = PLAYER_DARK_DJANGO;
        } else {
          p->kind = PLAYER_SOLAR_DJANGO;
        }

        Player_SetPlttIDs(p);
        p->unk_94c = -1;
        if (p->goodFrom != ITEM_CHOCOLATE_BANANA && p->goodFrom != ITEM_THE_EMPEROR) {
          p->goodCondTimer = 0;
        }

        Player_SetAction(p, PACT_TRANSFORM, 4);
      }
      break;
    }
    case 3: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }

      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      p->shadowOffset.z = 30;
      p->stateTimer++;
      if (p->stateTimer > 15) {
        Player_SetAction(p, PACT_TRANSFORM, 4);
      }
      break;
    }
    case 4: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/MagicTransform_0806b92c.inc");
#endif
}

// 魔法チェンジ・バット, 本体を隠して beast のコウモリを点滅させながら出し, 31フレームでバットのフォームへ切り替える
void MagicChangeBat_0806bc74(Player* p) {
  AuxAnimState* anim;

  if (p->action != PACT_CBAT) {
    Player_SetAction(p, PACT_CBAT, 0);
    p->plttFlashTimer = 0;
    FUN_08063220(p);
    FUN_08066e84(p);
    PlaySound_082406e0(SONG_922);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if (p->stateTimer == 16) {
    PlaySound_082406e0(SE_CHANGE_BAT);
  }

  if ((p->stateTimer & 7) < 7 - (p->stateTimer >> 2)) {
    if (p->facing >= FACE_DOWN_LEFT) {
      p->animIDOffset = 8 - p->facing;
      p->xflip = TRUE;
    } else {
      p->animIDOffset = p->facing;
      p->xflip = FALSE;
    }
  } else {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->beast.pos = p->mover.pos;
    p->beast.pos.y += p->unk_382;

    if (p->facing >= FACE_DOWN) {
      p->animIDOffset = (7 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animIDOffset = p->facing >> 1;
      p->xflip = FALSE;
    }
  }

  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
  p->plttID_95e = 290;
  p->plttFlashTimer += 3;
  if (p->plttFlashTimer > 32) {
    p->plttFlashTimer = 32;
  }

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->batAnim, 0, p->animIDOffset, p->xflip);

  AuxSprite_AdvanceAnim(&p->beast, anim);

  Video_SetAuxSpritePltt(p->beastGfx, 621);
  p->stateTimer++;
  if (p->stateTimer > 31) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_BAT;
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// 魔法チェンジ・マウス, 点滅が消えている間だけ本体を隠して beast のネズミを出し, 31フレームでマウスのフォームへ切り替える
void MagicChangeMouse_0806bf18(Player* p) {
  AuxAnimState* anim;

  if (p->action != PACT_CMOUSE) {
    Player_SetAction(p, PACT_CMOUSE, 0);
    p->plttFlashTimer = 0;
    FUN_08063220(p);
    FUN_08066e84(p);
    PlaySound_082406e0(SONG_922);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if (p->stateTimer == 16) {
    PlaySound_082406e0(SE_CHANGE_MOUSE);
  }

  if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 2)) {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->beast.pos = p->mover.pos;
  }

  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
  p->plttID_95e = 290;
  p->plttFlashTimer += 3;
  if (p->plttFlashTimer > 32) {
    p->plttFlashTimer = 32;
  }

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->mouseAnim, 0, p->animIDOffset, p->xflip);

  AuxSprite_AdvanceAnim(&p->beast, anim);

  Video_SetAuxSpritePltt(p->beastGfx, 290);
  p->stateTimer++;
  if (p->stateTimer > 31) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_MOUSE;
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// 魔法スリーピング, 棺桶の絵を beast に出して8フレームでスリーピングのフォームへ切り替える
void MagicSleeping_0806c124(Player* p) {
  AuxAnimState* anim;

  if (p->action != PACT_SLEEPING) {
    p->coffin = GetPlayerCoffinID();
    FUN_08063220(p);
    FUN_08066e84(p);
    Player_SetAction(p, PACT_SLEEPING, 0);
  }

  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
  Player_SetFlag35a(p, PFLAG35A_SHOW_OTHER);
  p->beast.pos = p->mover.pos;

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->coffinAnim, p->coffin + 24, 0, 0);

  AuxSprite_AdvanceAnim(&p->beast, anim);

  Video_SetAuxSpritePltt(p->beastGfx, p->coffin + 519);
  p->stateTimer++;
  if (p->stateTimer > 7) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_SLEEPING;
    Player_SetAction(p, PACT_UNK_4, 0);
  }
}

// バットの待機 (PACT_IDLE), バットのアニメを向きに合わせて1コマ進める
void FUN_0806c2dc(Player* p) {
  if (p->action != PACT_IDLE) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
  p->flag20 &= ~PFLAG20_UNK_0;

  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
}

// バットの歩き (PACT_WALK), unk_383[2] フレームごとに入力方向から乱数でふらつく向きを決め直し, アニメ 0 を進める
// 残差はレジスタ割当 (314/314, 34 hunk), 2回目の Random() でこちらは gRandomTable のアドレスを r7 に持ち越して callee-saved が1本増えるが, 原典は読み直す
// dir の使い回し, 宣言位置, 乱数の分岐を dir += / 共通の代入にする形は試済
NON_MATCH void Player_UpdateBatWalk(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != PACT_WALK) {
    Player_SetAction(p, PACT_WALK, 0);
    p->unk_383[2] = 0;
  }
  p->flag20 &= ~PFLAG20_UNK_0;
  if (p->unk_383[2] == 0) {
    s32 dir = FUN_08067068(p);
    s32 r;

    if (dir & 1) {
      if (dir > 4) {
        p->animIDOffset = (8 - dir) >> 1;
        p->xflip = TRUE;
      } else {
        p->animIDOffset = dir >> 1;
        p->xflip = FALSE;
      }
      r = Random() & 7;
      if (r < 6) {
        p->facing = dir;
        p->unk_383[2] = 9;
      } else {
        if (r < 7) {
          p->facing = (dir + 7) & 7;
        } else {
          p->facing = (dir + 9) & 7;
        }
        p->unk_383[2] = 3;
      }
    } else {
      r = Random() & 7;
      if (r < 6) {
        p->facing = dir;
        p->unk_383[2] = 9;
      } else {
        if (r < 7) {
          p->facing = (dir + 7) & 7;
        } else {
          p->facing = (dir + 9) & 7;
        }
        p->unk_383[2] = 3;
      }
      if (!(p->facing & 1)) {
        dir = (p->facing + (Random() & 1) * 2 + 7) & 7;
      } else {
        dir = p->facing;
      }
      if (dir > 4) {
        p->animIDOffset = (8 - dir) >> 1;
        p->xflip = TRUE;
      } else {
        p->animIDOffset = dir >> 1;
        p->xflip = FALSE;
      }
    }
  } else {
    p->unk_383[2]--;
  }
  Player_SetMoveDelta(p, 9);
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
#else
  INCFUNC("asm/func/Player_UpdateBatWalk.inc");
#endif
}

// バットの PACT_UNK_20, 方向入力に向きを合わせてアニメ 1 を1コマ進め, unk_3ff が空いたら PACT_IDLE に戻る
// 残差は p と cmd のレジスタ (r6/r7) の入れ替わりと, facing への代入でアドレスを値より先に作る点 (186/186), 手動送りは AuxSprite_AdvanceAnim で一致
// facing の式の書き方 (& ~1, | 1, シフト, u8 キャスト), &p->facing をポインタに取る形は試済
NON_MATCH void FUN_0806c6d4(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != PACT_UNK_20) {
    Player_SetAction(p, PACT_UNK_20, 0);
  }
  if ((s16)p->facingHistory[0] >= 0) {
    p->facing = (p->facingHistory[0] & 0xFE) + 1;
    if (p->facing > 4) {
      p->animIDOffset = (8 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animIDOffset = p->facing >> 1;
      p->xflip = FALSE;
    }
  }
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 1, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->unk_3ff < 0) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
#else
  INCFUNC("asm/func/FUN_0806c6d4.inc");
#endif
}

// バットの石化 (PACT_UNK_19), unk_382 を 60 ずつ減らしながら石化のアニメを1コマ進め, 状態異常が切れたら PACT_IDLE に戻る
void FUN_0806c868(Player* p) {
  AuxAnimState* anim;

  if (p->action != PACT_UNK_19) {
    Player_SetAction(p, PACT_UNK_19, 0);
  }
  if (p->unk_382 >= 60) {
    p->unk_382 -= 60;
  } else {
    p->flag20 &= ~PFLAG20_UNK_0;
    p->unk_382 = 0;
  }

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->batAnim, 1, p->animIDOffset, p->xflip);

  AuxSprite_AdvanceAnim(&p->beast, anim);

  if (p->emitter.unk_3 == 0) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// バットの被弾 (PACT_DAMAGED), アニメ 1 を進めながら knockbackPower の速さで向きの反対へ押し出し毎フレーム 3/4 に減速, 止まったら emitter が kind 3 で残っていれば PACT_UNK_19, そうでなければ PACT_IDLE に戻る
void Player_UpdateBatHurt(Player* p) {
  if (p->action != PACT_DAMAGED) {
    PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
    if (p->hurtSound != SONG_NONE) {
      PlaySound_082406e0(p->hurtSound);
      p->hurtSound = SONG_NONE;
    }
    Player_SetAction(p, PACT_DAMAGED, 0);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 1, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->hurtbox.knockbackPower != 0) {
    s32 angle = ((p->facing + 5) & 7) * 32;

    p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockbackPower);
    p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockbackPower);
    p->hurtbox.knockbackPower = (p->hurtbox.knockbackPower * 3) >> 2;
  } else if (p->emitter.kind == 3 && p->emitter.unk_3 != 0) {
    Player_SetAction(p, PACT_UNK_19, 0);
  } else {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// バットのままチェンジ・バットを使ったとき (PACT_CBAT), 点滅させながら human を出し, 31フレームで黒ジャンゴのフォームへ戻す
void Player_UndoChangeBat(Player* p) {
  if (p->action != PACT_CBAT || p->stateTimer == 0) {
    Player_SetAction(p, PACT_CBAT, 0);
    if (p->xflip) {
      p->facing = 7 - p->animIDOffset * 2;
    } else {
      p->facing = p->animIDOffset * 2 + 1;
    }
    p->plttFlashTimer = 0;
    FUN_08063220(p);
    FUN_08066e84(p);
    PlaySound_082406e0(SONG_922);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if ((p->stateTimer & 7) < 7 - (p->stateTimer >> 2)) {
    if (p->facing > 3) {
      p->animIDOffset = (7 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animIDOffset = p->facing >> 1;
      p->xflip = FALSE;
    }
  } else {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->human.pos = p->mover.pos;
    PLAYER_SET_ANIM_DIR(p, p->facing);
  }

  Player_PlayAnim(p, 199, Q6(1));
  p->human.plttID = 290;
  p->human.pltt = &gObjPlttData[p->human.plttID * 16];
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  p->plttID_95e = 621;
  if ((p->plttFlashTimer += 3) > 32) {
    p->plttFlashTimer = 32;
  }
  if (++p->stateTimer > 31) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
    Player_SetAnimFacing(p);
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// マウスの待機 (PACT_IDLE), マウスのアニメを向きに合わせて1コマ進める
void FUN_0806ceb0(Player* p) {
  p->flag20 &= ~PFLAG20_UNK_0;
  if (p->action != PACT_IDLE) {
    Player_SetAction(p, PACT_IDLE, 0);
  }

  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
}

s32 FUN_0806cfd4(Player* p) {
  s32 n = 12;

  if (p->emitter.kind == 2 && p->emitter.unk_3 != 0) {
    n = 8;
  }
  if (p->speedPenalty != 0) {
    n -= p->speedPenalty;
  }
  if (n <= 1) {
    return 2;
  } else {
    return n;
  }
}

// マウスの歩き (PACT_WALK), 入力方向へ向きと移動量を合わせてアニメ 1 を進め, 2コマ目の頭で左右交互の足音を鳴らす
void Player_UpdateMouseWalk(Player* p) {
  if (p->action != PACT_WALK) {
    p->unk_383[3] = 0;
    Player_SetAction(p, PACT_WALK, 0);
  }
  p->flag20 &= ~PFLAG20_UNK_0;
  p->facing = FUN_08067068(p);
  Player_SetMoveDelta(p, FUN_0806cfd4(p));
  Player_SetAnimFacing(p);
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 1, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->beastAnim.cmdIdx == 2 && p->beastAnim.tick == 0) {
    if (Entity1DBE_TouchElemNear(&p->mover.pos)) {
      if (p->unk_383[3]) {
        p->unk_383[3] = 0;
        FUN_08066e9c(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SONG_355);
      } else {
        p->unk_383[3] = 1;
        FUN_08066e9c(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SONG_354);
      }
    } else {
      if (p->unk_383[3]) {
        p->unk_383[3] = 0;
        PlaySound_082406e0(SONG_199);
      } else {
        p->unk_383[3] = 1;
        PlaySound_082406e0(SONG_200);
      }
      if (TestMapFlag(MPF_UNK_0)) {
        FUN_08066e9c(p, &p->mover.pos, 1, 2, NULL, 0, SONG_NONE);
      }
    }
  }
}

// マウスの PACT_UNK_4, 入った瞬間に前方 64 上方 64 の位置へ FUN_08066e9c で SE_CHANGE_MOUSE の演出を出し, アニメ 0 を進めて 16 フレームで PACT_IDLE に戻る
void FUN_0806d22c(Player* p) {
  if (p->action != PACT_UNK_4) {
    Vec3 pos = p->mover.pos;
    s32 angle = ((p->facing + 5) & 7) * 32;

    pos.x += POLAR_X(64, angle);
    pos.y += 64;
    pos.z += POLAR_Z(64, angle);
    Player_SetAction(p, PACT_UNK_4, 0);
    FUN_08066e9c(p, &p->mover.pos, 1, 1, &pos, 0, SE_CHANGE_MOUSE);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  p->stateTimer++;
  if (p->stateTimer > 15) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// マウスの石化 (PACT_UNK_19), 石化のアニメを1コマ進め, 状態異常が切れたら向きを戻して PACT_IDLE に戻る
void FUN_0806d420(Player* p) {
  AuxAnimState* anim;

  if (p->action != PACT_UNK_19) {
    Player_SetAction(p, PACT_UNK_19, 0);
    PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
  }
  p->flag20 &= ~PFLAG20_UNK_0;

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->mouseAnim, 2, p->animIDOffset, p->xflip);

  AuxSprite_AdvanceAnim(&p->beast, anim);

  if (p->emitter.unk_3 == 0) {
    Player_SetAnimFacing(p);
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// マウスの PACT_UNK_20, 方向入力に向きを合わせてアニメ 2 を1コマ進め, unk_3ff が空いたら PACT_IDLE に戻る
// 残差は facing への代入の順だけ (188/188), 原典は &p->facing を先に作ってから & 0xFE / + 1 を計算するが, こちらは値を先に作る (バット版 FUN_0806c6d4 と逆向き), 手動送りは AuxSprite_AdvanceAnim で一致
// 向きの式 (| 1, 1 + ..., (u8) キャスト, s16 ローカル) は試済
NON_MATCH void FUN_0806d5b0(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != PACT_UNK_20) {
    Player_SetAction(p, PACT_UNK_20, 0);
  }
  if ((s16)p->facingHistory[0] >= 0) {
    p->facing = (p->facingHistory[0] & 0xFE) + 1;
    PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->unk_3ff < 0) {
    Player_SetAnimFacing(p);
    Player_SetAction(p, PACT_IDLE, 0);
  }
#else
  INCFUNC("asm/func/FUN_0806d5b0.inc");
#endif
}

// マウスの PACT_UNK_23, heightAboveTile を毎フレーム 30 ずつ減らして落下し, 着地したらアニメ 3 を一巡させて PACT_IDLE に戻る
void FUN_0806d74c(Player* p) {
  Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
  switch (p->state) {
    case 0: {
      p->facing |= 1;
      PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animIDOffset, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      if ((u16)p->heightAboveTile <= 30) {
        p->heightAboveTile = 0;
        PlaySound_082406e0(SONG_432);
        p->state = 1;
      } else {
        p->heightAboveTile -= 30;
      }
      break;
    }
    case 1: {
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 3, p->animIDOffset, p->xflip);
      if (AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim)) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// マウスの被弾 (PACT_DAMAGED), アニメ 2 を進めながら吹き飛び, knockbackOrigin やタイルから弾かれたときはそちらへ寄せながら炎か煙を出し, 止まったら PACT_UNK_19 か PACT_IDLE に戻る
void Player_UpdateMouseHurt(Player* p) {
  if (p->action != PACT_DAMAGED) {
    PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
    if (p->hurtSound != SONG_NONE) {
      PlaySound_082406e0(p->hurtSound);
      p->hurtSound = SONG_NONE;
    }
    Player_SetAction(p, PACT_DAMAGED, 0);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->hurtbox.knockbackPower != 0) {
    if (p->originKnockback) {
      s32 dx = p->knockbackOrigin->x - p->mover.pos.x;
      s32 dz = p->knockbackOrigin->z - p->mover.pos.z;

      p->mover.delta.x = FixToInt(3, dx);
      p->mover.delta.z = FixToInt(3, dz);
      if (p->stateTimer <= 5) {
        if (!(p->stateTimer & 1)) {
          PlaySound_082406e0(SE_IGNITE);
          Entity080acd4c_Spawn(&p->mover.pos);
        }
        p->stateTimer++;
      }
    } else if (p->tileKnockback) {
      s32 dx = p->knockbackOrigin->x - p->mover.pos.x;
      s32 dz = p->knockbackOrigin->z - p->mover.pos.z;

      p->mover.delta.x = FixToInt(3, dx);
      p->mover.delta.z = FixToInt(3, dz);
      if (p->stateTimer <= 5) {
        if (!(p->stateTimer & 1)) {
          PlaySound_082406e0(SE_IGNITE);
          EmitSmoke(&p->mover.pos, 1, NULL, 0, 0, 12, 2, 2);
        }
        p->stateTimer++;
      }
    } else {
      s32 angle = ((p->facing + 5) & 7) * 32;

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockbackPower);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockbackPower);
    }
    Camera_Shake(p->hurtbox.knockbackPower);
    p->hurtbox.knockbackPower = (p->hurtbox.knockbackPower * 3) >> 2;
  } else {
    p->hurtbox.knockbackPower = 0;
    p->originKnockback = FALSE;
    p->tileKnockback = FALSE;
    if (p->emitter.kind == 3 && p->emitter.unk_3 != 0) {
      Player_SetAction(p, PACT_UNK_19, 0);
    } else {
      Player_SetAnimFacing(p);
      Player_SetAction(p, PACT_IDLE, 0);
    }
  }
}

// マウスのままチェンジ・マウスを使ったとき (PACT_CMOUSE), 点滅させながら human を出し, 31フレームで黒ジャンゴのフォームへ戻す
void Player_UndoChangeMouse(Player* p) {
  if (p->action != PACT_CMOUSE || p->stateTimer == 0) {
    Player_SetAction(p, PACT_CMOUSE, 0);
    p->plttFlashTimer = 0;
    FUN_08063220(p);
    FUN_08066e84(p);
    PlaySound_082406e0(SONG_922);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 2)) {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->human.pos = p->mover.pos;
  }

  Player_PlayAnim(p, 199, Q6(1));
  p->human.plttID = 290;
  p->human.pltt = &gObjPlttData[p->human.plttID * 16];
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  p->plttID_95e = 290;
  if ((p->plttFlashTimer += 3) > 32) {
    p->plttFlashTimer = 32;
  }
  if (++p->stateTimer > 31) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// おそらく、棺桶での"寝心地"(寝心地がいいほど、魔法スリーピングでのENEの回復が速い)
const u8 u8_ARRAY_085abc82[8] = {
    [COFFIN_OAK] = 4,
    [COFFIN_BRONZE] = 2,
    [COFFIN_IRON] = 2,
    [COFFIN_SILVER] = 1,
    [COFFIN_SOLAR] = 1,
    [COFFIN_ELEFAN] = 2,
    [COFFIN_VAMPIRE] = 8,
    [COFFIN_IRON_MAIDEN] = 0,
};  // 0x085ABC82

// 棺桶で寝ている間の処理, 棺桶のアニメを1コマ進めつつ寝心地に応じて ENE を回復し, 一定間隔で寝息を出す
void MagicSleeping_Update(Player* p) {
  AuxAnimState* anim;

  if (p->action != PACT_IDLE) {
    Player_SetAction(p, PACT_IDLE, 0);
  }

  p->flag20 &= ~PFLAG20_UNK_0;
  if (p->coffin == COFFIN_SILVER) {
    p->flag20 |= PFLAG20_INVISIBLE;
  }

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->coffinAnim, p->coffin, p->animIDOffset, p->xflip);

  AuxSprite_AdvanceAnim(&p->beast, anim);

  if (p->ene >= p->maxEne) {
    return;
  }

  if ((p->eneAccum += u8_ARRAY_085abc82[p->coffin]) > 0x7F) {
    p->ene++;
    p->eneAccum -= 0x80;
  }

  if (++p->stateTimer > 0x45) {
    p->emoteKind = EMOTE_2;
    p->emote = Emote_Show(p->emote, &p->mover, EMOTE_2, 0, 0, 0, 0x80, 0);
    p->stateTimer = 0;
  }
}

// スリーピングの歩き (PACT_WALK), unk_388 フレームごとに SONG_618 を鳴らし, 入力方向へ動かして棺桶のアニメ 32 を進め, 偶数コマの頭で床に合わせた足音を鳴らす
// 残差は2回目の Random() で gRandomTable のアドレスを置くレジスタ (r1 / r2) の1か所のみ (293/293), 手動送りは AuxSprite_AdvanceAnim で一致
// 加算の順, 減算の書き方, 乱数の取り直しを inline にまとめる形は試済
NON_MATCH void Player_UpdateSleepingWalk(Player* p) {
#ifdef NONMATCHING_C
  bool32 walking = TRUE;

  if (p->action != PACT_WALK) {
    PlaySound_082406e0(SONG_618);
    p->unk_388 = (Random() & 0x3F) + 64;
    Player_SetAction(p, PACT_WALK, 0);
    walking = FALSE;
  }
  if (p->unk_388 == 0) {
    PlaySound_082406e0(SONG_618);
    p->unk_388 = (Random() & 0x3F) + 64;
  } else {
    p->unk_388--;
  }
  p->facing = FUN_08067068(p);
  Player_SetAnimFacing(p);
  Player_SetMoveDelta(p, 6);
  AuxAnim_SetAnim(&p->beastAnim, p->coffinAnim, 32, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (walking && !(p->beastAnim.cmdIdx & 1) && p->beastAnim.tick == 0) {
    if (Entity1DBE_TouchElemNear(&p->mover.pos)) {
      if (p->beastAnim.cmdIdx == 0) {
        FUN_08066e9c(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SONG_355);
      } else if (p->beastAnim.cmdIdx == 2) {
        FUN_08066e9c(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SONG_355);
      }
    } else if (Player_IsOnRock(p->tile.attr[1])) {
      if (p->beastAnim.cmdIdx == 0) {
        FUN_08066e9c(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SONG_404);
      } else if (p->beastAnim.cmdIdx == 2) {
        FUN_08066e9c(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SONG_403);
      }
    } else {
      if (p->beastAnim.cmdIdx == 0) {
        PlaySound_082406e0(SONG_617);
      } else if (p->beastAnim.cmdIdx == 2) {
        PlaySound_082406e0(SONG_616);
      }
      if (TestMapFlag(MPF_UNK_0)) {
        FUN_08066e9c(p, &p->mover.pos, 1, 2, NULL, 0, SONG_NONE);
      }
    }
  }
#else
  INCFUNC("asm/func/Player_UpdateSleepingWalk.inc");
#endif
}

// 銃を撃つ, エナジーが 10 未満なら空撃ちの音だけ鳴らす
void FUN_0806e404(Player* p) {
  if (p->action != PACT_ATTACK) {
    Player_SetAction(p, PACT_ATTACK, 5);
  }
  if (p->stateTimer == 0) {
    if (p->ene < 10) {
      PlaySound_082406e0(SONG_213);
    } else {
      if (p->unk_38a == 0) {
        PlaySound_082406e0(SONG_619);
        p->unk_38a = 40;
      }
      PlaySound_082406e0(SE_GUN_FIRE);
      Entity08080be8_Create(p, 20, 180, 0, 32, 44, 32, HBATTR_SOL, 20, 3, 10, 1);
    }
  }
  p->stateTimer++;
  if (p->stateTimer > 7) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// スリーピングの PACT_UNK_4, 10フレームの間は棺桶のアニメ coffin + 16 を進め, 18フレームまで乱数で揺らし, 24フレームで向きを戻して PACT_IDLE に戻る
void FUN_0806e4b4(Player* p) {
  if (p->action != PACT_UNK_4) {
    Player_SetAction(p, PACT_UNK_4, 0);
  }
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SONG_491);
  }
  if (p->stateTimer <= 9) {
    AuxAnim_SetAnim(&p->beastAnim, p->coffinAnim, p->coffin + 16, 0, 0);
    AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  } else if (p->stateTimer <= 17) {
    s32 shake = (Random() & 0xF) - 7;

    p->unk_4bc = shake;
    p->unk_4c0 = -shake;
  }
  if (++p->stateTimer > 23) {
    p->eneAccum = 0;
    p->facing = FACE_UP;
    p->animIDOffset = 0;
    p->xflip = FALSE;
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// スリーピング時の PACT_UNK_20, 棺桶のアニメを1コマ進め, エレファンなら方向入力に向きを合わせる, unk_3ff が空いたら PACT_IDLE に戻る
void FUN_0806e674(Player* p) {
  AuxAnimState* anim;

  if (p->action != PACT_UNK_20) {
    Player_SetAction(p, PACT_UNK_20, 0);
  }
  if (p->coffin == COFFIN_ELEFAN && (s16)p->facingHistory[0] >= 0) {
    p->facing = p->facingHistory[0];
    Player_SetAnimFacing(p);
  }

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->coffinAnim, p->coffin, p->animIDOffset, p->xflip);

  AuxSprite_AdvanceAnim(&p->beast, anim);

  if (p->unk_3ff < 0) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// スリーピングのままスリーピングを使ったとき (PACT_SLEEPING), 下を向いてエモートを出し, 棺桶のアニメ coffin + 8 を進めた後は点滅しながら human を出して 40 フレームで黒ジャンゴのフォームへ戻す
void Player_UndoSleeping(Player* p) {
  if (p->action != PACT_SLEEPING || p->stateTimer == 0) {
    Player_SetAction(p, PACT_SLEEPING, 0);
    p->facing = FACE_DOWN;
    Player_SetAnimFacing(p);
    p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 127, NULL, 0, 0, 0);
    PlaySound_082406e0(SONG_490);
    if (p->badCondTimer[BAD_POISON] != 0) {
      p->human.plttID = 32;
    } else if (KAAMOS(p->isSabata) > 0) {
      p->human.plttID = 33;
    } else if (Player_TestEquipBuff(p, EBUFF_MEGAPOWER)) {
      p->human.plttID = 296;
    } else if (Player_TestEquipBuff(p, EBUFF_GUTSPOWER)) {
      p->human.plttID = 297;
    } else if (Player_TestEquipBuff(p, EBUFF_PROTOPOWER)) {
      p->human.plttID = 298;
    } else if (Player_TestEquipBuff(p, EBUFF_TOADPOWER)) {
      p->human.plttID = 299;
    } else {
      p->human.plttID = 38;
    }
  }

  Player_SetFlag35a(p, PFLAG35A_SHOW_OTHER);
  Player_PlayAnim(p, 199, Q6(1));
  p->human.pltt = &gObjPlttData[p->human.plttID * 16];
  p->human.pos = p->mover.pos;
  if (p->stateTimer < 10) {
    AuxAnim_SetAnim(&p->beastAnim, p->coffinAnim, p->coffin + 8, 0, 0);
    AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  } else if ((p->stateTimer >> 2) & 1) {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
  }
  if (++p->stateTimer > 39) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
    p->facing = FACE_DOWN;
    Player_SetAnimFacing(p);
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// 1P の向きの前方 ±32 (1/8 周) かつ 2 タイル以内にいる敵ノードのうち, 最も近いものを返す
Entity5941Node* Player_FindCWolfTarget(Player* p) {
  s32 bestDistSq = 0x40000;
  s32 angle = ((p->facing + 5) & 7) << 5;
  Entity5941Node* node;
  Entity5941Node* best;

  if (gEntity5941 == NULL) {
    return NULL;
  }
  node = gEntity5941->nodes;
  best = NULL;
  while (node != NULL) {
    if (!(node->flags & 1)) {
      s32 dx = node->owner->pos.x - p->mover.pos.x;
      s32 dz = node->owner->pos.z - p->mover.pos.z;
      s32 d = Angle_Diff(ArcTan2_8(dx, dz), angle - 0x100);

      if (d <= 32 || d >= 224) {
        s32 distSq = dx * dx + dz * dz;

        if (distSq < bestDistSq) {
          bestDistSq = distSq;
          best = node;
        }
      }
    }
    node = node->next;
  }
  return best;
}

// チェンジウルフ(Cウルフ, 敵の背後をとっているときに使用すると相手に噛みついてライフを吸収する)
// 残差1命令, p->hurtbox.invincibleTime = 0 で原典は値の 0 を先に作ってからアドレスを組むが, こちらはアドレスが先なので値とアドレスのレジスタが入れ替わる (FUN_08065cb8 で効いた Player_SetInvincibleTime 経由は 0 だと変わらない)
NON_MATCH void MagicChangeWolf_0806eb40(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != PACT_CWOLF) {
    gChangeWolfBiteCount = 0;
    gChangeWolfRebite = 0;
    gChangeWolfBiting = 0;
    p->hurtbox.invincibleTime = 0;
    gCWolfTarget = Player_FindCWolfTarget(p);
    if (gCWolfTarget == NULL) {
      Player_SetAction(p, PACT_CWOLF, 3);
    } else {
      p->plttID_95e = 290;
      p->plttFlashTimer = 32;
      Player_SetAction(p, PACT_CWOLF, 1);
    }
    Player_PayMagicCost(p);
    PlaySound_082406e0(SE_CHANGE_WOLF);
  }

  switch (p->state) {
    case 0: {
      s32 frame = p->stateTimer & 7;   // 8フレーム周期の中での位置
      s32 cycle = p->stateTimer >> 3;  // 何周期目か

      // 周期が進むごとに狼の姿を見せるフレームが増えていき, 人の姿と入れ替わる
      if (frame < 7 - cycle) {
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      } else {
        Player_PlayAnim(p, 403, Q6(1));
      }

      p->stateTimer++;
      if (p->stateTimer > 55) {
        gCWolfTarget = Player_FindCWolfTarget(p);
        if (gCWolfTarget == NULL) {
          Player_SetAction(p, PACT_CWOLF, 3);
          break;
        }
        Player_SetAction(p, PACT_CWOLF, 1);
      }
      break;
    }
    case 1: {
      s32 dx = gCWolfTarget->owner->pos.x - p->mover.pos.x;
      s32 dz = gCWolfTarget->owner->pos.z - p->mover.pos.z;
      s32 angle = ArcTan2_8(dx, dz);
      s32 angleDiff = (angle - gCWolfTarget->owner->angle + 0x100) & 0xFF;

      // 相手の背後 ±45度 に回り込めているなら
      if (angleDiff < 0x21 || angleDiff > 0xDF) {
        Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      }

      if (dx * dx + dz * dz <= 2303) {
        bool32 bitten;
        s32 quad;

        if (gCWolfTarget->flags & 1) {
          gCWolfTarget = NULL;
          Player_SetAction(p, PACT_CWOLF, 3);
          break;
        }

        bitten = gCWolfTarget->fn(gCWolfTarget->owner, 0, 0);
        gChangeWolfBiting = 1;
        if (!bitten) {
          gCWolfTarget = NULL;
          Player_SetAction(p, PACT_CWOLF, 3);
          break;
        }

        p->facing = ((((angle + 0x20) & 0xFF) >> 6) * 2 + 3) & 7;
        gCWolfTarget->owner->angle = ((p->facing + 5) & 7) << 5;  // 噛みつかれた側を背中合わせの向きに揃える
        quad = ((angle + 0x60) & 0xFF) >> 6;
        if (quad > 1) {
          p->animIDOffset = 3 - quad;
          p->xflip = TRUE;
        } else {
          p->animIDOffset = quad;
          p->xflip = FALSE;
        }
        Player_PlayAnim(p, 410, Q6(1));
        Player_SetAction(p, PACT_CWOLF, 2);
      } else {
        s32 quad;

        p->mover.delta.x = POLAR_X(24, angle);
        p->mover.delta.z = POLAR_Z(24, angle);
        p->facing = ((((angle + 0x20) & 0xFF) >> 6) * 2 + 3) & 7;
        quad = ((angle + 0x60) & 0xFF) >> 6;
        if (quad > 1) {
          p->animIDOffset = 3 - quad;
          p->xflip = TRUE;
        } else {
          p->animIDOffset = quad;
          p->xflip = FALSE;
        }
        Player_PlayAnim(p, 408, Q6(1));
        FUN_080670fc(p, 0);
        p->stateTimer++;
        if (p->stateTimer <= 89) {
          break;
        }
        Player_SetAction(p, PACT_CWOLF, 4);
      }
      break;
    }
    case 2: {
      bool32 done;

      if (gCWolfTarget->flags & 1) {
        gCWolfTarget = NULL;
        Player_SetAnimFacing(p);
        Player_PlayAnim(p, 403, Q6(1));
        Player_SetAction(p, PACT_CWOLF, 4);
        break;
      }

      // Lボタンを押しておくと, 1回の変身で4回まで噛みつき直せる
      if (gChangeWolfBiteCount < 4 && Player_CheckMagicCost(p) && (p->input->pressed & L_BUTTON)) {
        gChangeWolfRebite = 1;
      }

      done = Player_PlayAnim(p, 410, Q6(1));
      if (p->human.animCmdIdx == 5 && p->human.animCmdTimer == 0) {
        s32 heal = (p->stats[STAT_VITALITY] + p->stats[STAT_STRENGTH]) >> 1;

        if (!gCWolfTarget->fn(gCWolfTarget->owner, 0, heal)) {
          gCWolfTarget = NULL;
          Player_SetAnimFacing(p);
          Player_SetAction(p, PACT_CWOLF, 4);
          break;
        }

        {
          Vec3 v;
          s32 angle;

          PlaySound_082406e0(SONG_927);
          angle = ((p->facing + 5) & 7) * 32;
          v.x = POLAR_X(64, angle), v.y = 230;
          v.z = POLAR_Z(64, angle);
          FUN_080dc0b8(&p->mover.pos, &v, 0, 0, 1);
        }

        p->hp += heal;
        if (p->hp >= p->maxHP) {
          heal = p->maxHP - p->hp;
          p->hp = p->maxHP;
        }
        if (heal > 0) {
          CreateDamageNumber(&p->hurtbox, heal, 1, &p->mover.pos, &p->pos_970, 0);
        }
        gChangeWolfBiteCount++;
        break;
      }

      if (done) {
        if (gChangeWolfRebite) {
          Player_SetAction(p, PACT_CWOLF, 2);
        } else {
          Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
          gCWolfTarget->fn(gCWolfTarget->owner, 1, 60);
          gCWolfTarget = NULL;
          Player_SetAction(p, PACT_CWOLF, 4);
        }
        gChangeWolfRebite = 0;
      }
      break;
    }
    case 3: {
      p->plttID_95e = 290;
      p->plttFlashTimer = 32;
      Player_SetAnimFacing(p);
      Player_PlayAnim(p, 403, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 31) {
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
    case 4: {
      s32 angle;

      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      if (p->stateTimer == 0) {
        p->plttID_95e = 290;
        p->plttFlashTimer = 32;
      }
      Player_SetAnimFacing(p);
      Player_PlayAnim(p, 403, Q6(1));
      angle = ((p->facing + 5) & 7) * 32;
      p->mover.delta.x = -POLAR_X(16, angle);  // 噛みついた相手から後ろへ跳ぶ
      p->mover.delta.z = -POLAR_Z(16, angle);
      p->floatHeight = POLAR_Z(64, (p->stateTimer + 4) * 8);
      p->stateTimer++;
      if (p->stateTimer > 11) {
        p->floatHeight = 0;
        PlaySound_082406e0(SONG_432);
        Player_SetAction(p, PACT_CWOLF, 5);
      }
      break;
    }
    case 5: {
      if (Player_PlayAnim(p, 388, Q6(1))) {
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/MagicChangeWolf_0806eb40.inc");
#endif
}

void FUN_0806f1ec(Player* p) {
  switch (p->state) {
    case 0: {
      PlaySound_082406e0(SE_CHANGE_WOLF);
      Player_PlayAnim(p, 403, Q6(1));
      Player_SetAction(p, PACT_UNK_31, 1);
      break;
    }
    case 1: {
      return;
    }
    case 2: {
      if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 3)) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      }
      p->stateTimer++;
      if (p->stateTimer > 55) {
        Player_SetAction(p, PACT_UNK_31, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      break;
    }
  }
}

// FLAG030047A4_UNK_12 のダッシュ, Ene を1消費して16フレーム前へ進む, Ene が無ければ NG 音を鳴らして8フレーム立ち止まる
void FUN_0806f284(Player* p) {
  if (p->action != PACT_DASH) {
    if (p->ene != 0) {
      PlaySound_082406e0(SE_MAGIC_DASH);
      p->ene--;
      Player_SetAction(p, PACT_DASH, 0);
    } else {
      PlaySound_082406e0(SE_NG);
      Player_SetAction(p, PACT_DASH, 1);
    }
  }

  switch (p->state) {
    case 0: {
      if (++p->stateTimer >= 16) {
        Player_SetAction(p, PACT_IDLE, 0);
      } else {
        if (p->stateTimer < 8) {
          p->plttID_95e = 293;
          p->plttFlashTimer = 32;
        }
        if (!p->useForcedDelta) {
          Player_SetMoveDelta(p, 32);
        }
        Player_SetAnimFacing(p);
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(1));
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      if (++p->stateTimer >= 8) {
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 魔法ヒーリング, ENE を 2 使って HP を 40 回復する, ENE が足りなければ空振りの音だけ鳴らす
void MagicHealing_0806f3a0(Player* p) {
  if (p->action != PACT_HEALING) {
    if (p->facing >= FACE_RIGHT && p->facing <= FACE_LEFT) {
      p->facing = FACE_DOWN;
      p->animIDOffset = 1;
      p->xflip = FALSE;
    } else {
      p->facing = FACE_UP;
      p->animIDOffset = 0;
      p->xflip = FALSE;
    }
    if (p->ene > 1) {
      HealingParticles_Create(p, &p->mover.pos);
      p->magicFired = TRUE;
      if (p->hp < p->maxHP) {
        s32 hp = p->hp + 40;

        if (hp >= p->maxHP) {
          hp = p->maxHP;
        }
        CreateDamageNumber(&p->hurtbox, hp - p->hp, 1, &p->mover.pos, &p->pos_970, 0);
        p->hp = hp;
      }
      p->ene -= 2;
    } else {
      p->magicFired = FALSE;
    }
    PlaySound_082406e0(VO_DJANGO_MAGIC);
    Player_SetAction(p, PACT_HEALING, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->magicFired) {
        p->plttID_95e = 294;
        p->plttFlashTimer = 32;
      }
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        if (p->magicFired) {
          Player_SetAction(p, PACT_HEALING, 1);
        } else {
          Player_SetAction(p, PACT_HEALING, 2);
        }
      }
      break;
    }
    case 1: {
      p->plttID_95e = 294;
      p->plttFlashTimer = 32;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 9), Q6(1));
      if (++p->stateTimer > 23) {
        Player_SetAction(p, PACT_HEALING, 3);
      }
      break;
    }
    case 2: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_HEALING, 3);
      }
      break;
    }
    case 3: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// スリーピング時のダイナマイト, Ene を2消費して爆弾を1個出す (MagicDynamite_08069b18 のスリーピング版)
void FUN_0806f5d8(Player* p) {
  if (p->action != PACT_DYNAMITE) {
    if (p->ene >= 2) {
      p->magicFired = TRUE;
      Entity080a8ff8_Create(p, &p->mover.pos, 1);
      p->ene -= 2;
    } else {
      p->magicFired = FALSE;
    }
    Player_SetAction(p, PACT_DYNAMITE, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->magicFired) {
        p->plttID_95e = 291;
        p->plttFlashTimer = 32;
      }
      if (Player_PlayAnim(p, 184, Q6(1))) {
        if (p->magicFired) {
          Player_SetAction(p, PACT_DYNAMITE, 1);
        } else {
          Player_SetAction(p, PACT_DYNAMITE, 2);
        }
      }
      break;
    }
    case 1: {
      if (p->magicFired) {
        p->plttID_95e = 291;
        p->plttFlashTimer = 32;
      }
      p->stateTimer++;
      if (p->stateTimer > 11) {
        Player_SetAction(p, PACT_DYNAMITE, 3);
      }
      break;
    }
    case 2: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }
      Player_PlayAnim(p, 194, Q6(1));
      p->stateTimer++;
      if (p->stateTimer > 11) {
        Player_SetAction(p, PACT_DYNAMITE, 3);
      }
      break;
    }
    case 3: {
      if (Player_PlayAnim(p, 189, Q6(1))) {
        Player_SetAction(p, PACT_IDLE, 1);
      }
      break;
    }
  }
}

// 入力方向が来ていて見回しモード中でなければ向きを入力方向に合わせる, 向きを変えたら TRUE
bool32 FUN_0806f738(Player* p) {
  bool32 turned = FALSE;

  if ((s16)p->facingHistory[0] != -1 && !p->lookAroundOffset.val) {
    p->facing = FUN_08067068(p);
    turned = TRUE;
  }
  Player_SetAnimFacing(p);
  return turned;
}

void FUN_0806f780(Player* p) {
  p->wpn.enchantIdx = Player_CheckMagicEnchant(p);
  if (p->wpn.enchantIdx >= 0) {
    p->unk_951 = p->wpn.enchantIdx + 1;
  } else {
    p->unk_951 = 0;
  }
}

// 装備中の武器の攻撃力を出す, 剣/槍/槌はチカラとレベルに武器の値 (アストロ武器はレベル依存), その他は熟練度 (ハートの紋章で減った HP に応じて加算), 銃は熟練度と武器の攻撃力だけ
s32 FUN_0806f7bc(Player* p) {
  PlayerArmor* armor = &p->armor;
  s32 str;
  s32 atk;

  if (p->kind == PLAYER_SOLAR_DJANGO) {
    str = p->stats[STAT_STRENGTH] + armor->bonus[STAT_STRENGTH] + armor->sideBonus[STAT_STRENGTH];
  } else {
    str = p->stats[STAT_STRENGTH] + armor->bonus[STAT_STRENGTH] - armor->sideBonus[STAT_STRENGTH];
  }
  str = (str + gStat->lv) >> 1;

  switch (p->wpn.weaponKind) {
    case WK_SWORD:
    case WK_SPEAR:
    case WK_HAMMER: {
      if (TEST_FLAGS(p->equipBuffs, EBUFF_ASTRO)) {
        s32 lv = gStat->lv;
        s32 bonus;
        if (lv > 60) {
          lv = 60;
        }
        bonus = Div(lv * p->wpn.weaponKind, 6) + 5;
        atk = lv + bonus;
      } else {
        atk = p->wpn.weaponAtk + p->wpn.weapon->quality;
        if (atk < 0) {
          atk = 0;
        }
      }
      return str + atk;
    }
    case WK_OTHERS: {
      atk = str + ((GetWeaponSkillLevel(WK_OTHERS) + gStat->lv) >> 2);
      if (TEST_FLAGS(p->equipBuffs, EBUFF_HEART)) {
        atk += Div((p->maxHP - p->hp) * 20, p->maxHP);
      }
      return atk;
    }
    case WK_GUN: {
      if (GetWeaponSkillLevel(WK_GUN) > 98) {
        return (p->wpn.weaponAtk + 10) * 2;
      }
      atk = p->wpn.weaponAtk + (Div(GetWeaponSkillLevel(WK_GUN), 10) - 8) * 5;
      return atk * 2;
    }
  }
}

// 武器の特殊効果コールバックの戻り値を合計する
s32 FUN_0806f900(Player* p) {
  s32 total = FUN_0806f7bc(p);
  s32 i;

  for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
    if (p->weaponExDamageCb[i] != NULL) {
      total += p->weaponExDamageCb[i](p);
    }
  }
  if (TEST_FLAGS(p->equipBuffs, EBUFF_BLACKARMOR)) {  // 黒の鎧
    total += Div(p->hp * 20, p->maxHP);
  }
  return total;
}

s32 FUN_0806f960(Player* p) {
  s32 result = 0;
  s32 i;

  for (i = 0; i < 3; i++) {
    if (p->weaponEffectCb2[i] != NULL) {
      result |= p->weaponEffectCb2[i](p);
    }
  }
  return result;
}

// ジャンゴの武器の攻撃判定が当たったときのハンドラ, 特効系の追加ダメージを足し, 黒ジャンゴは夜の闇エンチャントで 1.5 倍, 種族持ちの敵に当てるたびにバーサークの攻撃回数を数える
// 残差は gStat->darkDjangoAtkCounter++ の後 (139/142), 原典は格納のあと gStat とカウンタを読み直して比べるが, agbcc は書いた値と gStat をレジスタに残したまま使う
// Tier A-C 試済 (++ / += 1 / 前置 ++ / 代入式), 1.5 倍は (u32) にすると lsrs が揃う, 未: 読み直しの再現
NON_MATCH void dark_django_0806f990(HitboxData* a, HitboxData* b, Player* _) {
#ifdef NONMATCHING_C
  Player* p;
  s32 i;

  if (!TEST_FLAGS(b->ignoreMask, 0x10)) {
    return;
  }

  p = a->owner;
  Hitbox_ApplyDamage(a, b);
  for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
    if (p->weaponEffectCb3[i] != NULL) {
      b->damage += p->weaponEffectCb3[i](p, a, b);
    }
  }

  if (p->kind != PLAYER_DARK_DJANGO) {
    return;
  }

  if (p->wpn.enchantIdx == 1 && Player_IsNight(p) && !(b->hitResult & HBRESULT_BONUS)) {
    b->damage = (u32)(b->damage * 3) >> 1;
    if (b->flags & HBFLAG_ANGLE) {
      b->hitResult |= HBRESULT_BONUS;
    }
  }

  if (!TEST_FLAGS(b->attributes, HBATTR_BEAST | HBATTR_THING | HBATTR_PHANTOM | HBATTR_UNDEAD | HBATTR_IMMORTAL)) {
    return;
  }
  if (p->unk_448[0] != 0) {
    return;
  }

  gStat->darkDjangoAtkCounter++;
  if (gStat->darkDjangoAtkCounter == (gStat->unk_2ac * 3) >> 2) {
    PlaySound_082406e0(VO_DARK_DJANGO_UGH_770);
    p->plttID_95e = 290;
    p->plttFlashTimer = 64;
    p->unk_448[3] = 64;
  } else if (gStat->darkDjangoAtkCounter == gStat->unk_2ac >> 1) {
    PlaySound_082406e0(VO_DARK_DJANGO_UGH_770);
    p->plttID_95e = 290;
    p->plttFlashTimer = 32;
    p->unk_448[3] = 32;
  }
  p->unk_448[0] = 1;
#else
  INCFUNC("asm/func/dark_django_0806f990.inc");
#endif
}

// 向いている方向へ武器の攻撃判定を出す準備をする, 黒ジャンゴとブルースパワー装備中は unk_b8 の値が変わり, エンチャント中は属性を足して魔法のコストを払う
void FUN_0806fad8(Player* p) {
  PlayerWeapon* wpn = &p->wpn;
  s32 power;
  HitboxAttributes attrs;
  u16 invincibleTime;

  p->wpn.basePos = p->mover.pos;
  p->wpn.basePos.y += 230;
  p->wpn.angle = ((p->facing + 5) & 7) << 5;
  power = FUN_0806f900(p);
  attrs = FUN_0806f960(p);
  invincibleTime = p->wpn.atkInvincibleTime;
  if (p->kind == PLAYER_DARK_DJANGO) {
    p->wpn.unk_b8[0] = 12;
    p->wpn.unk_b8[2] = 5;
    p->wpn.unk_b8[4] = 3;
    attrs |= HBATTR_18;
  } else if (TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
    p->wpn.unk_b8[0] = 12;
    p->wpn.unk_b8[2] = 5;
    p->wpn.unk_b8[4] = 3;
  } else {
    p->wpn.unk_b8[0] = 8;
    p->wpn.unk_b8[2] = 8;
    p->wpn.unk_b8[4] = 4;
  }
  if (wpn->enchantIdx >= 0) {
    attrs |= 1 << wpn->enchantIdx;
    Player_PayMagicCost(p);
  }
  Hitbox_SetAttack(&wpn->hitbox, power, wpn->knockbackPower, 1, attrs, invincibleTime);
  wpn->hitbox.angle = wpn->angle;
  wpn->gunSpreadAngle = 0;
  p->unk_448[0] = 0;
}

// pos から angle の向きに 112-239 離れた位置に, angle と直交する向き (flip で反対) に速さ 6 で飛ぶ粒子 (ptcl718) を出す
void FUN_0806fc20(Player* p, Vec3* pos, s32 angle, bool32 flip, s32 frameStep) {
  Vec3 spawn, vel;
  s32 r = (Random() & 0x7F) + 112;

  spawn.x = pos->x + POLAR_X(r, angle);
  spawn.y = pos->y;
  spawn.z = pos->z + POLAR_Z(r, angle);
  vel.x = POLAR_Z(6, angle);
  vel.y = 0;
  vel.z = -POLAR_X(6, angle);
  if (flip) {
    vel.x = -vel.x;
    vel.z = -vel.z;
  }
  Player_SpawnPtcl718(p, &spawn, &vel, frameStep);
}

// 剣を振る間, 毎フレーム攻撃判定を basePos から半径 160 の弧に沿って unk_b8[0] ずつ回し, unk_b8[2] フレームで終える, エンチャント中は1フレームおきに粒子を出す
// 残差は xflip でない側の角度の足し算 (176/176) と p / angle のレジスタ, 原典は &wpn->angle を先に作ってから n * k + 0x100 + angle - 0x20 の順に足す
// Tier A-C 試済 (戻り値の変数化, 分岐の向き, 足す順と括弧を6通り, 原典どおりの順に書くと演算は揃うが angle のアドレスが後になる), 未: アドレスを先に作る書き方
NON_MATCH bool32 FUN_0806fd58(Player* p) {
#ifdef NONMATCHING_C
  PlayerWeapon* wpn = &p->wpn;

  if (p->wpn.gunSpreadAngle == 0) {
    if (p->kind == PLAYER_SOLAR_DJANGO) {
      PlaySound_082406e0(SONG_908);
    } else {
      PlaySound_082406e0(SONG_907);
    }
  }
  if (++wpn->gunSpreadAngle <= wpn->unk_b8[2]) {
    u32 angle;
    if (p->xflip) {
      angle = wpn->angle + 0x20 - wpn->gunSpreadAngle * wpn->unk_b8[0] + 0x100;
    } else {
      angle = wpn->angle - 0x20 + wpn->gunSpreadAngle * wpn->unk_b8[0] + 0x100;
    }
    angle &= 0xFF;
    wpn->atkPos.x = wpn->basePos.x + POLAR_X(160, angle);
    wpn->atkPos.y = wpn->basePos.y;
    wpn->atkPos.z = wpn->basePos.z + POLAR_Z(160, angle);
    Hitbox_SetPos(&wpn->hitbox, &wpn->atkPos, 0);
    Hitbox_Register(&wpn->hitbox);
    if (wpn->enchantIdx >= 0) {
      p->flag20 |= PFLAG20_UNK_19;
      if (wpn->gunSpreadAngle & 1) {
        FUN_0806fc20(p, &wpn->basePos, angle, p->xflip, wpn->enchantIdx);
      }
    }
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_0806fd58.inc");
#endif
}

NAKED void FUN_0806fedc(Player* p) { INCFUNC("asm/func/FUN_0806fedc.inc"); }

// src から angle の方向へ dist だけずらした座標を dst に書く, 高さはそのまま写す
void FUN_080700a4(Vec3* dst, Vec3* src, s32 angle, s32 dist) {
  dst->x = src->x + POLAR_X(dist, angle);
  dst->y = src->y;
  dst->z = src->z + POLAR_Z(dist, angle);
}

s32 FUN_08070104(u8* src, u8* base) {
  s32 v = (*src & 0xF) << 8;

  switch (*src >> 4) {
    case 1: {
      v -= base[4];
      break;
    }
    case 2: {
      v -= base[0];
      break;
    }
  }
  return v;
}

// pos から angle の方向へ dist 進んだ位置のタイルが足元より高いか, 1 なら元のタイル, 2 なら差し替えタイルが高い, 0 は高くない
s32 FUN_0807012c(Vec3* pos, s32 angle, s32 dist) {
  Vec3 dst;
  s32 bx, bz, idx;
  CollisionMapTile* tile;
  MapTileOverride* ov;

  FUN_080700a4(&dst, pos, angle, dist);
  bx = (s8)(dst.x >> 8);
  bz = (s8)(dst.z >> 8);
  if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
    idx = 0;
  } else {
    idx = gCollisionMap->rowOffsets[bz] + bx;
  }
  if (gCollisionMap->tiledata == NULL) {
    tile = NULL;
  } else {
    tile = &gCollisionMap->tiledata->tiles[idx];
  }
  if (FUN_08070104((u8*)tile, (u8*)&dst) > dst.y) {
    return 1;
  }
  ov = Map_FindTileOverride(idx, 1);
  if (ov != NULL && FUN_08070104((u8*)&ov->tile, (u8*)&dst) > dst.y) {
    return 2;
  }
  return 0;
}

NAKED void FUN_080701e0(Player* p) { INCFUNC("asm/func/FUN_080701e0.inc"); }

// pos の周り ±15 の位置から angle の反対向きに速さ 3-6 で飛ぶ粒子 (ptcl718) を出す
// 残差は pos の各成分の読み方 (137/134), 原典は ldrh で読んで乱数と足すが, こちらは ldrsh で先に読みレジスタが1本ずつ余計に生きる, vel.y = 0 は兄弟の FUN_0806fc20 で一致に効いたので入れてある
// Tier A-C 試済 (足す順, 括弧の付け方), pos を u16* として pos[0..2] で読むとレジスタ割り当てだけの差になるが, wpn.atkPos (Vec3) を u16 で読むのは不自然なので採っていない
NON_MATCH void FUN_080704d8(Player* p, Vec3* pos, s32 angle, s32 frameStep) {
#ifdef NONMATCHING_C
  u16* table = gRandomTable;
  Vec3 spawn, vel;
  s32 speed;

  spawn.x = pos->x + (_Random(table) & 0x1F) - 15;
  spawn.y = pos->y + (_Random(table) & 0x1F) - 15;
  spawn.z = pos->z + (_Random(table) & 0x1F) - 15;
  speed = (_Random(table) & 3) + 3;
  vel.x = -POLAR_X(speed, angle);
  vel.y = 0;
  vel.z = -POLAR_Z(speed, angle);
  Player_SpawnPtcl718(p, &spawn, &vel, frameStep);
#else
  INCFUNC("asm/func/FUN_080704d8.inc");
#endif
}

NAKED s32 FUN_08070604(Player* p) { INCFUNC("asm/func/FUN_08070604.inc"); }

NAKED void FUN_08070844(Player* p) { INCFUNC("asm/func/FUN_08070844.inc"); }

// 向いている方向へ武器の攻撃判定を出す準備をする (FUN_0806fad8 の別の値の版, 判定の種類は 4)
void FUN_08070adc(Player* p) {
  PlayerWeapon* wpn = &p->wpn;
  s32 power;
  HitboxAttributes attrs;

  p->wpn.basePos = p->mover.pos;
  p->wpn.basePos.y += 230;
  p->wpn.angle = ((p->facing + 5) & 7) << 5;
  power = FUN_0806f900(p);
  attrs = FUN_0806f960(p);
  if (p->kind == PLAYER_DARK_DJANGO) {
    p->wpn.unk_b8[0] = 29;
    p->wpn.unk_b8[4] = 7;
    p->wpn.unk_b8[2] = 4;
    p->wpn.unk_b8[3] = 6;
    attrs |= HBATTR_18;
  } else if (TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
    p->wpn.unk_b8[0] = 29;
    p->wpn.unk_b8[4] = 7;
    p->wpn.unk_b8[2] = 4;
    p->wpn.unk_b8[3] = 6;
  } else {
    p->wpn.unk_b8[0] = 19;
    p->wpn.unk_b8[4] = 11;
    p->wpn.unk_b8[2] = 6;
    p->wpn.unk_b8[3] = 9;
  }
  if (wpn->enchantIdx >= 0) {
    attrs |= 1 << wpn->enchantIdx;
    Player_PayMagicCost(p);
  }
  Hitbox_SetAttack(&wpn->hitbox, power, wpn->knockbackPower, 4, attrs, wpn->atkInvincibleTime);
  wpn->hitbox.angle = wpn->angle;
  wpn->gunSpreadAngle = 0;
  p->unk_448[0] = 0;
}

// pos の周り ±15 の位置から, yaw / pitch の向きに速さ 5-8 で飛ぶ粒子 (ptcl718) を出す (FUN_080704d8 の別版)
// 残差は pos の各成分の読み方 (175/175), 原典は ldrh で読んで乱数と足すが, こちらは ldrsh になり, レジスタが1本足りず yaw をスタックへ退避する, FUN_080704d8 と同じ壁
// Tier A-C 試済 (添字ローカルで gRandTableIdx を最後に1回書く形, _Random(table), pos を u16* にすると 165/175 で別の形になる)
NON_MATCH void FUN_08070c2c(Player* p, Vec3* pos, s32 yaw, s32 pitch, s32 frameStep) {
#ifdef NONMATCHING_C
  u16* table = gRandomTable;
  Vec3 spawn, vel;
  s32 speed, h, v;

  spawn.x = (_Random(table) & 0x1F) + pos->x - 15;
  spawn.y = (_Random(table) & 0x1F) + pos->y - 15;
  spawn.z = (_Random(table) & 0x1F) + pos->z - 15;
  speed = (_Random(table) & 3) + 5;
  h = POLAR_X(speed, yaw);
  v = POLAR_Z(speed, yaw);
  vel.x = POLAR_X(-v, pitch);
  vel.y = h;
  vel.z = POLAR_Z(-v, pitch);
  Player_SpawnPtcl718(p, &spawn, &vel, frameStep);
#else
  INCFUNC("asm/func/FUN_08070c2c.inc");
#endif
}

NAKED s32 FUN_08070db4(Player* p) { INCFUNC("asm/func/FUN_08070db4.inc"); }

NAKED void FUN_0807106c(Player* p) { INCFUNC("asm/func/FUN_0807106c.inc"); }

// 向いている方向へ武器の攻撃判定を出す準備をする, 判定の向きと威力を決め, 出した位置を wpn.basePos に残す
void FUN_08071218(Player* p) {
  s32 power;

  p->wpn.basePos = p->mover.pos;
  p->wpn.basePos.y += 230;
  p->wpn.angle = ((p->facing + 5) & 7) << 5;
  power = FUN_0806f900(p);
  Video_SetAuxSpritePltt(&p->wpn.gfx, 45);
  Hitbox_SetAttack(&p->wpn.hitbox, power, p->wpn.knockbackPower, 8, 0, p->wpn.atkInvincibleTime);
  p->wpn.hitbox.angle = p->wpn.angle;
  p->wpn.gunSpreadAngle = 0;
  p->unk_448[0] = 0;
}

// 武器の攻撃判定を wpn.basePos から wpn.angle の向きへ 100 進めた位置に置いて6フレーム出し続ける, 出し終えたら 1 を返す
s32 FUN_080712d4(Player* p) {
  PlayerWeapon* wpn = &p->wpn;
  if (p->wpn.gunSpreadAngle == 0) {
    PlaySound_082406e0(SONG_913);
  }
  if (++p->wpn.gunSpreadAngle <= 5) {
    wpn->atkPos.x = wpn->basePos.x + POLAR_X(100, wpn->angle);
    wpn->atkPos.y = wpn->basePos.y;
    wpn->atkPos.z = wpn->basePos.z + POLAR_Z(100, wpn->angle);
    Hitbox_SetPos(&p->wpn.hitbox, &p->wpn.atkPos, 0);
    Hitbox_Register(&p->wpn.hitbox);
    return 0;
  }
  p->wpn.gunSpreadAngle = 0;
  return 1;
}

NAKED void FUN_080713a8(Player* p) { INCFUNC("asm/func/FUN_080713a8.inc"); }

NAKED void gun_080715a0(Player* p) { INCFUNC("asm/func/gun_080715a0.inc"); }

NAKED void FUN_08071b14(Player* p) { INCFUNC("asm/func/FUN_08071b14.inc"); }

// サバタの攻撃 (PACT_ATTACK), B を押している間暗黒銃をチャージし, 離すとチャージ段階に応じた長さだけ散弾を撃つ
void Player_UpdateSabataAttack(Player* p) {
  if (p->action != PACT_ATTACK) {
    Player_SetAction(p, PACT_ATTACK, 0);
  }

  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 35), Q6(1))) {
        p->chargeStepTime = 30;
        Player_SetAction(p, PACT_ATTACK, 1);
      }
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_GUN_AIM);
      }
      FUN_0806f738(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (++p->stateTimer > 6) {
        p->wpn.charge = 0;
        if (p->ene <= 4) {
          PlaySound_082406e0(SONG_213);
          Player_SetAction(p, PACT_ATTACK, 5);
        } else {
          if (!(p->input->down & B_BUTTON)) {
            PlaySound_082406e0(SONG_515);
            Player_SetAction(p, PACT_ATTACK, 5);
          } else {
            Player_SetAction(p, PACT_ATTACK, 2);
          }
          Entity08080be8_Create(p, 230, 170, 0, 32, 50, 32, HBATTR_DARK, 20, 5, 5, 0);
        }
      }
      break;
    }
    case 2: {
      FUN_0806f738(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (p->stateTimer == 6) {
        PlaySound_082406e0(SE_GUN_MISFIRE);
      }
      if (!(p->input->down & B_BUTTON)) {
        PlaySound_082406e0(SONG_515);
        Player_SetAction(p, PACT_ATTACK, 5);
      } else if (++p->stateTimer >= p->chargeStepTime) {
        p->wpn.charge = 1;
        p->plttID_95e = 290;
        p->plttFlashTimer = 36;
        PlaySound_082406e0(SE_GUN_MISFIRE);
        Player_SetAction(p, PACT_ATTACK, 3);
      }
      break;
    }
    case 3: {
      FUN_0806f738(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (p->input->down & B_BUTTON) {
        if (++p->stateTimer >= p->chargeStepTime) {
          p->wpn.charge = 2;
          p->plttID_95e = 290;
          p->plttFlashTimer = 36;
          PlaySound_082406e0(SE_GUN_CHARGED);
          Player_SetAction(p, PACT_ATTACK, 4);
        }
      } else {
        PlaySound_082406e0(VO_SABATA_TAKETHIS);
        p->wpn.gunSpreadAngle = ((8 - p->facing) & 7) << 5;
        Hitbox_SetAttack(&p->wpn.hitbox, FUN_0806f900(p), 32, 16, HBATTR_DARK, 20);
        PlaySound_082406e0(SONG_514);
        Player_SetAction(p, PACT_ATTACK, 8);
      }
      break;
    }
    case 4: {
      FUN_0806f738(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (!(p->input->down & B_BUTTON)) {
        PlaySound_082406e0(VO_SABATA_TAKETHIS);
        p->wpn.gunSpreadAngle = ((8 - p->facing) & 7) << 5;
        Hitbox_SetAttack(&p->wpn.hitbox, FUN_0806f900(p), 32, 16, HBATTR_DARK, 20);
        PlaySound_082406e0(SONG_514);
        Player_SetAction(p, PACT_ATTACK, 8);
      }
      break;
    }
    case 5: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 37), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (++p->stateTimer > 4) {
        Player_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 6: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->wpn.unk_ae[0]) {
        p->wpn.unk_ae[0] = 0;
        p->state = 1;
      } else if (++p->stateTimer > 14) {
        p->wpn.unk_ae[0] = 0;
        Player_SetAction(p, PACT_ATTACK, 7);
      }
      break;
    }
    case 7: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 35), Q6(1));
      if (++p->stateTimer > 4) {
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
    case 8: {
      Vec3 pos;
      s32 angle;

      p->unk_3d1 = 0;
      if (FUN_0806f738(p)) {
        Player_SetMoveDelta(p, 6);
      }
      if (!(p->stateTimer & 3)) {
        Vec3 ofs;
        Vec3 size;

        VEC3_SET(ofs, 0, 0, 0);
        VEC3_SET(size, 32, 0, 32);
        FUN_080dbcec(&p->mover.pos, &ofs, &size, 1, 2, 4);
      }
      p->wpn.gunSpreadAngle = (p->wpn.gunSpreadAngle + 16) & 0xFF;
      Player_ShowGunSpread(p, p->wpn.gunSpreadAngle, &p->mover.pos);
      pos = p->mover.pos;
      angle = (416 - p->wpn.gunSpreadAngle) & 0xFF;
      pos.x += POLAR_X(170, angle);
      pos.y += 230;
      pos.z += POLAR_Z(170, angle);
      Hitbox_SetPos(&p->wpn.hitbox, &pos, 0);
      p->wpn.hitbox.angle = angle;
      Hitbox_Register(&p->wpn.hitbox);
      p->facing = ((271 - p->wpn.gunSpreadAngle) & 0xFF) >> 5;
      Player_SetAnimFacing(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 37), Q6(1));
      if (!(p->stateTimer & 15)) {
        PlaySound_082406e0(SONG_516);
      }
      if (++p->stateTimer >= p->wpn.charge << 5) {
        sound_08240740(SONG_514);
        Player_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
  }
  p->unk_951 = 9;
}

void FUN_08072620(Player* p) {
  Player_SetAction(p, PACT_IDLE, 0);
  p->fn_498 = FUN_08072724;
}

void FUN_08072640(Player* p) { p->unk_4aa = 1; }

void FUN_08072650(Player* p) {
  if (p->scriptID_4b0 != 0) {
    s32 id = p->scriptID_4b0;

    p->scriptID_4b0 = 0;
    VM_ExecByID(id, NULL);
  }
}

void FUN_08072670(Player* p) {
  p->unk_4aa = 2;
  p->unk_4ab = 1;
}

void FUN_0807268c(Player* p) {
  if (p->unk_4ab != 0) {
    MsgQueue_EndWait(&p->mq, 1);
    p->unk_4ab = 0;
  }
}

void FUN_080726b4(Player* p) {
  if (p->unk_4aa == 1) {
    FUN_08072650(p);
  } else if (p->unk_4aa == 2) {
    FUN_0807268c(p);
  }
}

void FUN_080726e0(Player* p) { Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW); }

void FUN_080726ec(Player* p) {
  if (p->footHitboxOn != 0) {
    p->footHitboxTimer++;
    if (p->footHitboxTimer > 7) {
      Player_EmitBurnSmoke(p);
      p->footHitboxTimer = 0;
    }
  }
}

// 残差2命令: 原典は case 0 と case 2 の FUN_080726b4 の呼び出しを2つ持つが、agbcc は同じ末尾なので cross-jump で1つに畳む
NON_MATCH void FUN_08072724(Player* p) {
#ifdef NONMATCHING_C
  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      if (p->unk_4af != 0) {
        p->unk_4af = 0;
        FUN_080726b4(p);
      }
      break;
    }
    case 2: {
      p->stateTimer++;
      if (p->stateTimer > 19) {
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
        FUN_08072620(p);
        FUN_080726b4(p);
        break;
      }
    }
    case 1: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 47), Q6(1));
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08072724.inc");
#endif
}

// 3フレームに1回 dir_4a9 の方へ向きを1段ずつ回し, 向き終わったら FUN_08072620 / FUN_080726b4 を呼ぶ
// 残差は向き差の計算 (85/85), 原典は facing - 8 を先に作り dir_4a9 を ldrsb で読んで引くが, こちらは + 8 が畳まれて dir_4a9 が ldrb + シフトになる, FUN_08082a94 (sabata.c) と同じ壁
// Tier A-B は試済 (dir - facing + 8 / dir - (facing - 8), inline 化), 未: 向き差を別の変数で持つ形
NON_MATCH void FUN_080727d4(Player* p) {
#ifdef NONMATCHING_C
  if (p->stateTimer >= 2) {
    if (((p->dir_4a9 - p->facing + 8) & 7) > 4) {
      p->facing = (p->facing + 7) & 7;
    } else {
      p->facing = (p->facing + 1) & 7;
    }
    if (p->facing > 4) {
      p->animIDOffset = 8 - p->facing;
      p->xflip = TRUE;
    } else {
      p->animIDOffset = p->facing;
      p->xflip = FALSE;
    }
    p->stateTimer = 0;
  } else {
    p->stateTimer++;
  }
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
  if (p->facing == p->dir_4a9) {
    FUN_08072620(p);
    FUN_080726b4(p);
  }
#else
  INCFUNC("asm/func/FUN_080727d4.inc");
#endif
}

// 操作不能中に fn_498 から回すアニメ 0x211 / 0x212 の演出, state 3 は点滅しながら現れ, 4 は点滅しながら消えて隠れたまま (FUN_080726e0) になる
void FUN_080728a8(Player* p) {
  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, 529, Q6(1))) {
        p->state = 1;
        FUN_080726b4(p);
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, 530, Q6(1));
      break;
    }
    case 2: {
      if (Player_PlayAnim(p, 529, Q6(1))) {
        Player_SetAnimFacing(p);
        FUN_08072620(p);
        FUN_080726b4(p);
      }
      break;
    }
    case 3: {
      Player_PlayAnim(p, 530, Q6(1));
      if ((p->stateTimer & 7) < 7 - (p->stateTimer >> 3)) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 55) {
        Player_SetAction(p, PACT_IDLE, 1);
        FUN_080726b4(p);
      }
      break;
    }
    case 4: {
      Player_PlayAnim(p, 530, Q6(1));
      if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 3)) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 55) {
        Player_SetAction(p, PACT_IDLE, 0);
        p->fn_498 = FUN_080726e0;
        FUN_080726b4(p);
      }
      break;
    }
  }
}

void FUN_080729e0(Player* p) {
  if (Player_PlayAnim(p, 531, Q6(1))) {
    Player_SetAnimFacing(p);
    FUN_08072620(p);
    FUN_080726b4(p);
  }
}

void FUN_08072a0c(Player* p) {
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 51), Q6(1));
  Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
}

NAKED void FUN_08072a38(Player* p) { INCFUNC("asm/func/FUN_08072a38.inc"); }

NAKED void FUN_08072d48(Player* p) { INCFUNC("asm/func/FUN_08072d48.inc"); }

// 操作不能中に fn_498 から回す PACT_UNK_7 (太陽チャージなど) の構え, 構えたら unk_4a6 で 2 種の待ちアニメに分かれ, state 3 で構えを解いて元の処理に戻す
void FUN_0807304c(Player* p) {
  switch (p->state) {
    case 0: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        PlaySound_082406e0(SONG_203);
        if (p->unk_4a6) {
          p->state = 1;
        } else {
          p->state = 2;
        }
        p->unk_4a6 = 0;
        p->stateTimer = 0;
      }
      break;
    }
    case 1: {
      p->shadowOffset.z = 30;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 9), Q6(1));
      FUN_080726b4(p);
      break;
    }
    case 2: {
      p->shadowOffset.z = 30;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      FUN_080726b4(p);
      break;
    }
    case 3: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        PLAYER_SET_ANIM_DIR(p, p->facing);
        FUN_08072620(p);
        FUN_080726b4(p);
      }
      break;
    }
  }
}

NAKED void FUN_0807317c(Player* p) { INCFUNC("asm/func/FUN_0807317c.inc"); }

// 操作不能中に fn_498 から回す PACT_UNK_18 の演出 (FUN_0807bcb0 が据える), state 4 は点滅しながら消え, 5 で隠れたままになる
void FUN_08073574(Player* p) {
  switch (p->state) {
    case 0: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SONG_208);
      }
      if (p->stateTimer == 8) {
        PlaySound_082406e0(SONG_219);
      }
      p->stateTimer++;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 48), Q6(1))) {
        Player_SetAction(p, PACT_UNK_18, 1);
        FUN_080726b4(p);
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 49), Q6(1));
      break;
    }
    case 2: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 50), Q6(1));
      break;
    }
    case 3: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SONG_208);
      }
      if (++p->stateTimer <= 4) {
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 50), Q6(1));
      } else {
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
        FUN_08072620(p);
        FUN_080726b4(p);
      }
      break;
    }
    case 4: {
      if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 3)) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 55) {
        Player_SetAction(p, PACT_UNK_18, 5);
      }
      break;
    }
    case 5: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      break;
    }
  }
}

NAKED void FUN_080736b8(Player* p) { INCFUNC("asm/func/FUN_080736b8.inc"); }

// 操作不能中に fn_498 から回す落下, floatHeight を毎フレーム 30 ずつ減らし, 着地アニメが終わったら向きを戻して元の処理に戻す (FUN_08069f60 の操作不能版)
void FUN_080738b4(Player* p) {
  switch (p->state) {
    case 0: {
      if (p->stateTimer == 0) {
        PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
        p->stateTimer++;
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 18), Q6(1));
      if (p->floatHeight > 30) {
        p->floatHeight -= 30;
      } else {
        p->floatHeight = 0;
        PlaySound_082406e0(SONG_432);
        Player_SetAction(p, PACT_UNK_23, 1);
      }
      break;
    }
    case 1: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 19), Q6(1))) {
        PLAYER_SET_ANIM_DIR(p, p->facing);
        FUN_08072620(p);
        FUN_080726b4(p);
      }
      break;
    }
  }
}

// 操作不能中に fn_498 から回す被弾の吹き飛び, 向きの反対へ knockbackSpeed_4a4 の速さで押し出し毎フレーム 3/4 に減速, 止まったら起き上がって元の処理に戻す
void FUN_080739e0(Player* p) {
  switch (p->state) {
    case 0: {
      s32 angle;
      if (p->stateTimer == 0) {
        PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
        PlaySound_082406e0(SE_DAMAGE);
        p->stateTimer++;
      }
      angle = ((p->facing + 5) & 7) * 32;
      p->mover.delta.x = -FixToInt(12, COS(angle) * p->knockbackSpeed_4a4);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->knockbackSpeed_4a4);
      p->knockbackSpeed_4a4 = (p->knockbackSpeed_4a4 * 3) >> 2;
      if (p->knockbackSpeed_4a4 == 0) {
        Player_SetAction(p, PACT_DAMAGED, 1);
      }
      break;
    }
    case 1: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 42), Q6(1))) {
        Player_SetAnimFacing(p);
        FUN_08072620(p);
        FUN_080726b4(p);
      }
      break;
    }
  }
}

NAKED void FUN_08073b3c(Player* p) { INCFUNC("asm/func/FUN_08073b3c.inc"); }

// 操作不能中に fn_498 から回す被弾の吹き飛び (FUN_080739e0 の別版), 止まったら倒れたアニメから起き上がる
void FUN_08073e18(Player* p) {
  switch (p->state) {
    case 0: {
      s32 angle;
      if (p->stateTimer == 0) {
        PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
        if (p->kind != PLAYER_SABATA) {
          PlaySound_082406e0(SONG_231);
        }
      }
      angle = ((p->facing + 5) & 7) * 32;
      p->mover.delta.x = -FixToInt(12, COS(angle) * p->knockbackSpeed_4a4);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->knockbackSpeed_4a4);
      p->knockbackSpeed_4a4 = (p->knockbackSpeed_4a4 * 3) >> 2;
      if (p->knockbackSpeed_4a4 == 0) {
        Player_SetAction(p, PACT_DAMAGED, 1);
      }
      break;
    }
    case 1: {
      if (p->human.animCmdIdx == 3 && p->human.animCmdTimer == 0) {
        PlaySound_082406e0(SONG_209);
      }
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 46), Q6(1))) {
        Player_SetAction(p, PACT_DAMAGED, 2);
        FUN_080726b4(p);
      }
      break;
    }
    case 2: {
      // 起き上がり終えたら fn_498 が差し替わるまで何もしない
      break;
    }
  }
}

// 操作不能中に fn_498 から回す剣の攻撃モーション, 振り始めにジャンゴごとの効果音, 黒ジャンゴは剣の衝撃波も出す (FUN_08074244 の剣版)
void FUN_08073f88(Player* p) {
  s32 speed = p->kind == PLAYER_DARK_DJANGO ? Q6(0.75) : Q6(1);

  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 21), speed)) {
        Player_SetAction(p, PACT_ATTACK, 1);
        FUN_080726b4(p);
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 22), Q6(1));
      break;
    }
    case 2: {
      bool32 done;
      if (p->stateTimer == 0) {
        if (p->kind == PLAYER_SOLAR_DJANGO) {
          PlaySound_082406e0(SONG_908);
        } else {
          PlaySound_082406e0(SONG_907);
        }
        p->stateTimer++;
      }
      done = Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 23), speed);
      if (p->kind == PLAYER_DARK_DJANGO && p->human.animCmdIdx == 2 && p->human.animCmdTimer == 0) {
        Player_SpawnSwordShockwave(p, p->facing, &p->mover.pos);
      }
      if (done) {
        Player_SetAction(p, PACT_ATTACK, 3);
      }
      break;
    }
    case 3: {
      if (++p->stateTimer > 3) {
        FUN_08072620(p);
        FUN_080726b4(p);
      }
      break;
    }
  }
}

// 操作不能中に fn_498 から回す槍の攻撃モーション, 黒ジャンゴとブルースパワー中は 3/4 倍速で, 黒ジャンゴは槍の衝撃波も出す (FUN_08073f88 の槍版)
void FUN_080740b0(Player* p) {
  s32 speed;

  if (p->kind == PLAYER_DARK_DJANGO || TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
    speed = Q6(0.75);
  } else {
    speed = Q6(1);
  }

  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 24), speed)) {
        Player_SetAction(p, PACT_ATTACK, 1);
        FUN_080726b4(p);
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 25), Q6(1));
      break;
    }
    case 2: {
      bool32 done;
      if (p->stateTimer == 0) {
        if (p->kind == PLAYER_SOLAR_DJANGO) {
          PlaySound_082406e0(SONG_911);
        } else {
          PlaySound_082406e0(SONG_909);
        }
        p->stateTimer++;
      }
      done = Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 28), speed);
      if (p->kind == PLAYER_DARK_DJANGO && p->human.animCmdIdx == 1 && p->human.animCmdTimer == 0) {
        Player_SpawnSpearShockwave(p, p->facing, &p->mover.pos, 0);
      }
      if (done) {
        Player_SetAction(p, PACT_ATTACK, 3);
      }
      break;
    }
    case 3: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 24), speed)) {
        Player_SetAction(p, PACT_ATTACK, 4);
      }
      break;
    }
    case 4: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 25), speed)) {
        FUN_08072620(p);
        FUN_080726b4(p);
      }
      break;
    }
  }
}

// 操作不能中に fn_498 から回す攻撃モーション (FUN_0807c568 / FUN_0807c5ac が据える), 振りの途中でジャンゴごとの効果音, 黒ジャンゴは衝撃波も出す
void FUN_08074244(Player* p) {
  s32 speed = p->kind == PLAYER_DARK_DJANGO ? Q6(0.75) : Q6(1);

  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 29), speed)) {
        Player_SetAction(p, PACT_ATTACK, 1);
        FUN_080726b4(p);
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 30), speed);
      break;
    }
    case 2: {
      bool32 done;
      if (p->kind == PLAYER_SOLAR_DJANGO) {
        if (p->stateTimer == 17) {
          PlaySound_082406e0(SONG_912);
        }
      } else if (p->stateTimer == 11) {
        PlaySound_082406e0(SONG_910);
      }
      p->stateTimer++;
      done = Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 31), speed);
      if (p->kind == PLAYER_DARK_DJANGO && p->human.animCmdIdx == 5 && p->human.animCmdTimer == 0) {
        Player_SpawnShockwaveBehind(p, p->facing, &p->mover.pos);
      }
      if (done) {
        FUN_08072620(p);
        FUN_080726b4(p);
      }
      break;
    }
  }
}

// 操作不能中に fn_498 から回す銃の構え (FUN_0807c634 が据える), 構えて狙い, 撃って戻す
void FUN_08074350(Player* p) {
  if (p->kind == PLAYER_SABATA) {
    p->unk_951 = 9;
  } else {
    p->unk_951 = 8;
  }

  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 35), Q6(1))) {
        PlaySound_082406e0(SE_GUN_AIM);
        Player_SetAction(p, PACT_ATTACK, 1);
        FUN_080726b4(p);
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      break;
    }
    case 2: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1))) {
        Player_SetAction(p, PACT_ATTACK, 3);
      }
      break;
    }
    case 3: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 37), Q6(1))) {
        Player_SetAction(p, PACT_ATTACK, 4);
      }
      break;
    }
    case 4: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (++p->stateTimer > 14) {
        Player_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 5: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 35), Q6(1))) {
        FUN_08072620(p);
        FUN_080726b4(p);
      }
      break;
    }
  }
}

NAKED void FUN_080744bc(Player* p) { INCFUNC("asm/func/FUN_080744bc.inc"); }

NAKED void FUN_080746ec(Player* p) { INCFUNC("asm/func/FUN_080746ec.inc"); }

void FUN_08074994(Player* p) {
  p->plttID_95e = 295;
  p->plttFlashTimer = 24;
}

void FUN_080749b0(Player* p) {
  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, 536, Q6(1))) {
        Player_SetAction(p, PACT_HEALING, 1);
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, 538, Q6(1));
      if (p->stateTimer == 0) {
        FUN_080726b4(p);
        p->stateTimer++;
      }
      break;
    }
    case 2: {
      if (Player_PlayAnim(p, 536, Q6(1))) {
        Player_SetAnimFacing(p);
        FUN_08072620(p);
        FUN_080726b4(p);
      }
      break;
    }
  }
}

NAKED void FUN_08074a40(Player* p) { INCFUNC("asm/func/FUN_08074a40.inc"); }

// バットのアニメを向きに合わせて1コマ進める
void FUN_08074d90(Player* p) {
  AuxAnimState* anim = &p->beastAnim;

  AuxAnim_SetAnim(anim, p->batAnim, 0, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, anim);
}

// 操作不能中に fn_498 から回すバットの移動, unk_49c へ速さ 9 で飛び, 着いたら dir_4a9 (無ければ進んできた向き) を向いて PACT_IDLE に戻し fn_498 を FUN_08074d90 にする
// 残差1命令 (302/301), 原典は向きの | 1 を格納先のアドレスより先に作り, dir_4a9 = -1 と facing の strb を1つに畳むが, こちらは | 1 がアドレス計算の後に来て畳まれない
// 向きをローカルに出す形, 丸めを static inline にする形, 1 | を先に書く形は試済, Angle_ToDir8(angle) | 1 は u16 引数の切り詰めが入って 304 命令
NON_MATCH void Player_UpdateBatMoveTo(Player* p) {
#ifdef NONMATCHING_C
  s32 dx = p->unk_49c.x - p->mover.pos.x;
  s32 dz = p->unk_49c.z - p->mover.pos.z;
  s32 angle = ArcTan2_8(dx, dz);

  if (dx * dx + dz * dz < 82) {
    p->mover.pos.x = p->unk_49c.x;
    p->mover.pos.z = p->unk_49c.z;
    if (p->dir_4a9 >= 0) {
      p->facing = p->dir_4a9;
      p->dir_4a9 = -1;
    } else {
      p->facing = (((((angle + 0x10) & 0xFF) >> 5) + 3) & 7) | 1;
    }
    if (p->facing > 4) {
      p->animIDOffset = (8 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animIDOffset = p->facing >> 1;
      p->xflip = FALSE;
    }
    Player_SetAction(p, PACT_IDLE, 0);
    p->fn_498 = FUN_08074d90;
    FUN_080726b4(p);
  } else {
    p->mover.delta.x = POLAR_X(9, angle);
    p->mover.delta.z = POLAR_Z(9, angle);
    p->facing = (((((angle + 0x10) & 0xFF) >> 5) + 3) & 7) | 1;
    if (p->facing > 4) {
      p->animIDOffset = (8 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animIDOffset = p->facing >> 1;
      p->xflip = FALSE;
    }
  }
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
#else
  INCFUNC("asm/func/Player_UpdateBatMoveTo.inc");
#endif
}

NAKED void FUN_08075134(Player* p) { INCFUNC("asm/func/FUN_08075134.inc"); }

// バットの被弾の吹き飛び, アニメ 1 を進めながら向きの反対へ knockbackSpeed_4a4 の速さで押し出し毎フレーム 3/4 に減速, 止まったら PACT_IDLE に戻して fn_498 を FUN_08074d90 にする
void Player_UpdateBatKnockback(Player* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_DAMAGE);
    p->stateTimer++;
  }
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 1, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->knockbackSpeed_4a4 != 0) {
    s32 angle = ((p->facing + 5) & 7) * 32;

    p->mover.delta.x = -FixToInt(12, COS(angle) * p->knockbackSpeed_4a4);
    p->mover.delta.z = -FixToInt(12, SIN(angle) * p->knockbackSpeed_4a4);
    p->knockbackSpeed_4a4 = (p->knockbackSpeed_4a4 * 3) >> 2;
  } else {
    p->knockbackSpeed_4a4 = 0;
    Player_SetAction(p, PACT_IDLE, 0);
    p->fn_498 = FUN_08074d90;
    FUN_080726b4(p);
  }
}

// バットから黒ジャンゴへ戻る変身, 点滅させながら human を出し, 31フレームで黒ジャンゴのフォームへ切り替える
void Player_RevertBatToDarkDjango(Player* p) {
  if (p->stateTimer == 0) {
    if (p->xflip) {
      p->facing = 7 - p->animIDOffset * 2;
    } else {
      p->facing = p->animIDOffset * 2 + 1;
    }
    p->plttFlashTimer = 0;
    PlaySound_082406e0(SONG_895);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if ((p->stateTimer & 7) < 7 - (p->stateTimer >> 2)) {
    if (p->facing > 3) {
      p->animIDOffset = (7 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animIDOffset = p->facing >> 1;
      p->xflip = FALSE;
    }
  } else {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->human.pos = p->mover.pos;
    PLAYER_SET_ANIM_DIR(p, p->facing);
  }

  Player_PlayAnim(p, 199, Q6(1));
  p->human.plttID = 290;
  p->human.pltt = &gObjPlttData[p->human.plttID * 16];
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  p->plttID_95e = 621;
  if ((p->plttFlashTimer += 3) > 32) {
    p->plttFlashTimer = 32;
  }
  if (++p->stateTimer > 31) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
    Player_SetAnimFacing(p);
    FUN_08072620(p);
    p->unk_4af = TRUE;
  }
}

// マウスのアニメを向きに合わせて1コマ進める
void FUN_08075df8(Player* p) {
  AuxAnimState* anim = &p->beastAnim;

  AuxAnim_SetAnim(anim, p->mouseAnim, 0, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, anim);
}

// 操作不能中に fn_498 から回すマウスの移動, unk_49c へ速さ 12 で歩き (階段では補正), 着いたら dir_4a9 (無ければ進んできた向き) を向いて PACT_IDLE に戻し fn_498 を FUN_08075df8 にする
void Player_UpdateMouseMoveTo(Player* p) {
  s32 dx = p->unk_49c.x - p->mover.pos.x;
  s32 dz = p->unk_49c.z - p->mover.pos.z;
  s32 angle = ArcTan2_8(dx, dz);

  if (dx * dx + dz * dz <= 144) {
    p->mover.pos.x = p->unk_49c.x;
    p->mover.pos.z = p->unk_49c.z;
    if (p->dir_4a9 >= 0) {
      p->facing = p->dir_4a9;
      p->dir_4a9 = -1;
    } else {
      p->facing = Angle_ToDir8(angle);
    }
    PLAYER_SET_ANIM_DIR(p, p->facing);
    AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animIDOffset, p->xflip);
    AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
    Player_SetAction(p, PACT_IDLE, 0);
    p->fn_498 = FUN_08075df8;
    FUN_080726b4(p);
  } else {
    p->mover.delta.x = POLAR_X(12, angle);
    p->mover.delta.z = POLAR_Z(12, angle);
    if (p->tile.stairs[1] == 1) {
      if (p->mover.delta.z < 0) {
        p->mover.delta.z = FixToInt(6, p->mover.delta.z * 40);
      } else {
        p->mover.delta.z = FixToInt(6, p->mover.delta.z * 52);
      }
    } else if (p->tile.stairs[1] == 2) {
      if (p->mover.delta.x < 0) {
        p->mover.delta.x = FixToInt(6, p->mover.delta.x * 40);
      } else {
        p->mover.delta.x = FixToInt(6, p->mover.delta.x * 52);
      }
    }
    p->facing = Angle_ToDir8(angle);
    PLAYER_SET_ANIM_DIR(p, p->facing);
    AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 1, p->animIDOffset, p->xflip);
    AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  }
}

// マウスの落下 (PACT_UNK_22), カメラを上に向けてアニメ 2 を1コマ当て, 6フレーム後に沈み始めて 30 フレームで消える
void Player_UpdateMouseFall(Player* p) {
  switch (p->state) {
    case 0: {
      Vec3 pos;

      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      pos = p->mover.pos;
      pos.y += 150;
      Camera_LookAt(&pos);
      if (p->unk_3f0 < 2) {
        if (p->unk_3f0 != 0) {
          FUN_0823ce68(3, 3, 4, 4, 4, 0x1FFF, 16);
        } else {
          FUN_0823ce68(3, 3, 4, 4, 4, 0x1FFF, 1);
        }
      }
      PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animIDOffset, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      PlaySound_082406e0(SONG_429);
      Player_SetAction(p, PACT_UNK_22, 1);
      p->floatHeight = 0;
      break;
    }
    case 1: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      if (++p->stateTimer > 5) {
        p->floatHeight = 0;
        p->beast.priority = 1;
        PlaySound_082406e0(SONG_430);
        Player_SetAction(p, PACT_UNK_22, 2);
      }
      break;
    }
    case 2: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      p->floatHeight -= 60;
      if (++p->stateTimer > 29) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
        Player_SetAction(p, PACT_UNK_22, 3);
        FUN_080726b4(p);
      }
      break;
    }
    case 3: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      break;
    }
  }
}

// 操作不能中に fn_498 から回すマウスの着地 (PACT_UNK_23), state 0 は floatHeight を 30 ずつ下げてアニメ 2 を進め, 着地したら state 1 でアニメ 3 を一巡させて fn_498 を FUN_08075df8 に戻す
void Player_UpdateMouseLand(Player* p) {
  switch (p->state) {
    case 0: {
      if (p->stateTimer == 0) {
        PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
        p->stateTimer++;
      }
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animIDOffset, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      if (p->floatHeight > 30) {
        p->floatHeight -= 30;
      } else {
        p->floatHeight = 0;
        PlaySound_082406e0(SONG_432);
        Player_SetAction(p, PACT_UNK_23, 1);
      }
      break;
    }
    case 1: {
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 3, p->animIDOffset, p->xflip);
      if (AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim)) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, PACT_IDLE, 0);
        p->fn_498 = FUN_08075df8;
        FUN_080726b4(p);
      }
      break;
    }
  }
}

NAKED void FUN_0807688c(Player* p) { INCFUNC("asm/func/FUN_0807688c.inc"); }

// マウスの被弾の吹き飛び, アニメ 2 を進めながら Player_UpdateBatKnockback と同じく押し出し, 止まったら向きを合わせ直して PACT_IDLE に戻し fn_498 を FUN_08075df8 にする
void Player_UpdateMouseKnockback(Player* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_DAMAGE);
    p->stateTimer++;
  }
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->knockbackSpeed_4a4 != 0) {
    s32 angle = ((p->facing + 5) & 7) * 32;

    p->mover.delta.x = -FixToInt(12, COS(angle) * p->knockbackSpeed_4a4);
    p->mover.delta.z = -FixToInt(12, SIN(angle) * p->knockbackSpeed_4a4);
    p->knockbackSpeed_4a4 = (p->knockbackSpeed_4a4 * 3) >> 2;
  } else {
    p->knockbackSpeed_4a4 = 0;
    Player_SetAnimFacing(p);
    Player_SetAction(p, PACT_IDLE, 0);
    p->fn_498 = FUN_08075df8;
    FUN_080726b4(p);
  }
}

// マウスから黒ジャンゴへ戻る変身, 点滅させながら human を出し, 31フレームで黒ジャンゴのフォームへ切り替える
void Player_RevertMouseToDarkDjango(Player* p) {
  if (p->stateTimer == 0) {
    p->plttFlashTimer = 0;
    PlaySound_082406e0(SONG_895);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 2)) {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->human.pos = p->mover.pos;
  }

  Player_PlayAnim(p, 199, Q6(1));
  p->human.plttID = 290;
  p->human.pltt = &gObjPlttData[p->human.plttID * 16];
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animIDOffset, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  p->plttID_95e = 290;
  if ((p->plttFlashTimer += 3) > 32) {
    p->plttFlashTimer = 32;
  }
  if (++p->stateTimer > 31) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
    FUN_08072620(p);
    p->unk_4af = TRUE;
  }
}

// 棺桶 (スリーピング) のアニメを coffin 番目に合わせて1コマ進める
void FUN_080772ec(Player* p) {
  AuxAnimState* anim = &p->beastAnim;

  AuxAnim_SetAnim(anim, p->coffinAnim, p->coffin, 0, 0);
  AuxSprite_AdvanceAnim(&p->beast, anim);
}

NAKED void FUN_080773f0(Player* p) { INCFUNC("asm/func/FUN_080773f0.inc"); }

// スリーピングから黒ジャンゴへ戻る変身, 10フレームは棺桶のアニメ coffin + 8 を進め, その後は点滅しながら human を出して 40 フレームで黒ジャンゴのフォームへ切り替える
void Player_RevertSleepingToDarkDjango(Player* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SONG_490);
    if (p->badCondTimer[BAD_POISON] != 0) {
      p->human.plttID = 32;
    } else if (KAAMOS(p->isSabata) > 0) {
      p->human.plttID = 33;
    } else if (Player_TestEquipBuff(p, EBUFF_MEGAPOWER)) {
      p->human.plttID = 296;
    } else if (Player_TestEquipBuff(p, EBUFF_GUTSPOWER)) {
      p->human.plttID = 297;
    } else if (Player_TestEquipBuff(p, EBUFF_PROTOPOWER)) {
      p->human.plttID = 298;
    } else if (Player_TestEquipBuff(p, EBUFF_TOADPOWER)) {
      p->human.plttID = 299;
    } else {
      p->human.plttID = 38;
    }
  }

  Player_SetFlag35a(p, PFLAG35A_SHOW_OTHER);
  Player_PlayAnim(p, 199, Q6(1));
  p->human.pos = p->mover.pos;
  p->human.pltt = &gObjPlttData[p->human.plttID * 16];
  if (p->stateTimer < 10) {
    AuxAnim_SetAnim(&p->beastAnim, p->coffinAnim, p->coffin + 8, 0, 0);
    AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  } else if ((p->stateTimer >> 2) & 1) {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
  }
  if (++p->stateTimer > 39) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
    FUN_08072620(p);
    p->unk_4af = TRUE;
  }
}

NAKED void FUN_08077cbc(Player* p) { INCFUNC("asm/func/FUN_08077cbc.inc"); }

NAKED void FUN_08078060(Player* p) { INCFUNC("asm/func/FUN_08078060.inc"); }

// 十字キーの押下状態を 4bit に畳んで方向番号に引き直す, どれも押していない or ありえない組み合わせは -1
DirS32 Player_GetDpadFacing(Player* p) {
  static const s16 sDpadFacingTable[17] = {
      [0] = -1,
      [1] = FACE_UP,           // ↑
      [2] = FACE_DOWN,         // ↓
      [3] = -1,                // ↑+↓ (invalid)
      [4] = FACE_LEFT,         // ←
      [5] = FACE_UP_LEFT,      // ←+↑
      [6] = FACE_DOWN_LEFT,    // ←+↓
      [7] = -1,                // ↑+←+↓ (invalid)
      [8] = FACE_RIGHT,        // →
      [9] = FACE_UP_RIGHT,     // →+↑
      [10] = FACE_DOWN_RIGHT,  // →+↓
      [11] = -1,               // ↑+↓+→ (invalid)
      [12] = -1,               // ←+→ (invalid)
      [13] = -1,               // ←+↑+→ (invalid)
      [14] = -1,               // ↓+←+→ (invalid)
      [15] = -1,               // ↑+↓+←+→ (invalid)
      [16] = 0,
  };  // 0x085ABC8A

  s16 idx = 0;
  if (p->input->down & DPAD_UP) idx |= (1 << 0);
  if (p->input->down & DPAD_DOWN) idx |= (1 << 1);
  if (p->input->down & DPAD_LEFT) idx |= (1 << 2);
  if (p->input->down & DPAD_RIGHT) idx |= (1 << 3);
  return sDpadFacingTable[idx];
}

void FUN_080784fc(Player* p) {
  s32 i;

  for (i = 9; i > 0; i--) {
    p->facingHistory[i] = p->facingHistory[i - 1];
  }

  p->facingHistory[0] = Player_GetDpadFacing(p);
  if ((s16)p->facingHistory[0] >= 0) {
    p->facingHistory[0] = ((s16)p->facingHistory[0] + p->controlUp + 7) & 7;
  }
}

void FUN_08078548(Player* p) {
  Player_StopEneChargeSound(p);
  if (p->lookAroundOffset.val) {
    Player_EndLookAround(p);
  }
}

void FUN_0807856c(Player* p) {
  if (p->lookAroundOffset.val) {
    Player_EndLookAround(p);
  }
}

// 熱中症が溜まっている間, heatstrokeTick が 15 を超えるたびに体から煙を出す (2500 以上は倍速)
void FUN_0807858c(Player* p) {
  if (gStat->heatstroke != 0) {
    if (gStat->heatstroke < 2500) {
      p->heatstrokeTick++;
    } else {
      p->heatstrokeTick += 2;
    }
    if (p->heatstrokeTick > 15) {
      Vec3 size;
      WorldPos pos;

      if (p->kind == PLAYER_BAT || p->kind == PLAYER_MOUSE) {
        pos = p->beast.pos;
        size.x = 32, size.y = 32, size.z = 32;
      } else {
        pos = p->mover.pos;
        pos.y += 360;
        size.x = 32, size.y = 32, size.z = 32;
      }
      EmitSmoke(&pos, 1, &size, 0, 0, 6, 3, 2);
      p->heatstrokeTick = 0;
    }
  }
}

NAKED s32 FUN_0807868c(Player* p) { INCFUNC("asm/func/FUN_0807868c.inc"); }

// A ボタンを押していて, 相手が話しかけられる状態で, なおかつ同じエレベータに乗っているか
// 残差2命令: 原典は gCoffin をアドレスだけ保持して引数作りのところで読み直すが、こちらは1回のロードに畳まれる (agbcc-levers.md 参照)
NON_MATCH s32 FUN_08078844(Player* p) {
#ifdef NONMATCHING_C
  if ((p->input->down & A_BUTTON) && gCoffin != NULL && (gCoffin->state == 1 || gCoffin->state == 0x10) && FUN_0808626c(p->elevatorID, p->unk_390, gCoffin->elevatorID, gCoffin->unk_384)) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_08078844.inc");
#endif
}

s32 FUN_080788b0(Player* p) { return FUN_08086294(&p->mover.pos, p->elevatorID, p->unk_390); }

NAKED s32 FUN_080788d0(Player* p) { INCFUNC("asm/func/FUN_080788d0.inc"); }

// 人型 (ジャンゴ / サバタ) の毎フレームの後処理, 移動と表示・食らい判定のフラグを反映して human を mover の位置に置き, unk_448[3] の間は human を揺らす
void Player_PostUpdateHuman(Player* p) {
  if (p->unk_390 == 0) {
    if (Player_TestFlag35a(p, PFLAG35A_NO_TILE)) {
      p->mover.tile = NULL;
    } else if (p->mover.tile == NULL) {
      Map_InitMoverTile(&p->tile, &p->mover.pos);
      p->mover.tile = &p->tile;
    }
  }
  Mover_ApplyMove(&p->mover);
  FUN_080417dc(&p->mover);

  if (Player_TestFlag35a(p, PFLAG35A_NO_HURTBOX)) {
    p->hurtbox.flags |= HBFLAG_HIDDEN;
  } else {
    p->hurtbox.flags &= ~HBFLAG_HIDDEN;
    Hitbox_SetPos(&p->hurtbox, &p->mover.pos, 0);
  }

  if (Player_TestFlag35a(p, PFLAG35A_HIDE_BODY)) {
    p->human.flags |= SPRFLAG_HIDDEN;
  } else {
    p->human.flags &= ~SPRFLAG_HIDDEN;
  }

  if (Player_TestFlag35a(p, PFLAG35A_BLINK)) {
    p->human.flags |= SPRFLAG_BLINK_ODD;
  } else {
    p->human.flags &= ~SPRFLAG_BLINK_ODD;
  }

  if (Player_TestFlag35a(p, PFLAG35A_SHOW_OTHER)) {
    p->beast.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->beast.flags |= SPRFLAG_HIDDEN;
  }

  if (Player_TestFlag35a(p, PFLAG35A_HIDE_SHADOW)) {
    ParticleShadow_Hide(&p->shadow);
  } else {
    ParticleShadow_Show(&p->shadow);
  }

  p->mover.pos.y += p->heightAboveTile;
  p->human.pos = p->mover.pos;
  p->human.pos.y += p->floatHeight;
  if (p->unk_448[3] != 0) {
    s32 shake = (Random() & 0xF) - 7;
    p->human.pos.x += shake;
    p->human.pos.z -= shake;
    p->unk_448[3]--;
  }
}

// clang-format off
static const PlayerFunc sDjangoActionFuncs[33] = {
    [PACT_IDLE] = FUN_08066f7c,
    [PACT_WALK] = FUN_080672b0,
    [PACT_DASH] = MagicDash_Update,
    [PACT_ATTACK] = FUN_080695ec,
    [PACT_UNK_4] = FUN_08067510,
    [PACT_UNK_5] = FUN_08067de8,
    [PACT_PULL_COFFIN] = Player_UpdatePullCoffin,
    [PACT_UNK_7] = Player_UpdateSolarCharge,
    [PACT_UNK_8] = Player_UpdateSolarStand,
    [PACT_SUN_MAGIC] = MagicRisingSun_08068944,
    [PACT_TRANSFORM] = MagicTransform_0806b92c,
    [PACT_CWOLF] = MagicChangeWolf_0806eb40,
    [PACT_CBAT] = MagicChangeBat_0806bc74,
    [PACT_CMOUSE] = MagicChangeMouse_0806bf18,
    [PACT_SLEEPING] = MagicSleeping_0806c124,
    [PACT_FREEZE] = MagicFreeze_08069710,
    [PACT_HEALING] = MagicHealing_08069928,
    [PACT_DYNAMITE] = MagicDynamite_08069b18,
    [PACT_UNK_18] = FUN_08069c8c,
    [PACT_UNK_19] = FUN_0806961c,
    [PACT_UNK_20] = FUN_08069648,
    [PACT_GRABBED] = FUN_0806a050,
    [PACT_UNK_22] = Player_UpdateFall,
    [PACT_UNK_23] = FUN_08069f60,
    [PACT_DAMAGED] = Player_UpdateHurt,
    [PACT_BLOWN_AWAY] = Player_UpdateBlownAway,
    [PACT_UNK_26] = Player_UpdateDeath,
    [PACT_UNK_27] = Player_UpdateBlownAwayDeath,
    [PACT_UNK_28] = Player_UpdateFallDeath,
    [PACT_FALLDEATH] = FUN_0806adc8,
    [PACT_UNK_30] = FUN_0806af70,
    [PACT_UNK_31] = FUN_0806f1ec,
    [PACT_UNK_32] = FUN_0806b06c,
};  // 0x085ABCAC
// clang-format on

// プレイヤーの毎フレーム更新本体, unk_1c の状態ごとに行動関数を呼び, 通常状態では段差を登れるかも見る
// 命令数は414で一致, 残差30箇所はほぼレジスタ割当, 原典は sp のコピーを r6 に持つがこちらは持たず, unk_3be = 0 のブロックが原典では関数末尾に出る
// Player_GetTileAt は一致していないので本来なら消す規約だが, 展開すると gcc が2つの同一ブロックを畳んで 397/414 まで遠くなるため残している
// Tier A-C 試済, 効いたもの: POLAR_Z/POLAR_X マクロ (乗算の項順), Player_SetFlag20 (定数の materialize 順), attr を s32 ローカルへ (u16 切り詰めの除去)
NON_MATCH void Player_UpdateDjango(Player* p) {
#ifdef NONMATCHING_C
  Player_SetFlag20(p, PFLAG20_UNK_14);

  switch (p->mode) {
    case PMODE_ACTIVE: {
      CollisionMapTile* tile;
      Vec3 pos;
      s32 action;
      s32 angle;
      s32 height;
      s32 attr;
      bool32 busy;
      bool32 canStep;

      FUN_0807858c(p);
      if (p->kind == PLAYER_SOLAR_DJANGO) {
        if (Player_IsInRain(p)) {
          FUN_0806687c(p);
        }
      } else {
        if (p->flag20 & PFLAG20_SUNBATHING) {
          Player_StepSunburn(p, gStat->sunGauge);
        }
        if (Player_IsInRain(p)) {
          FUN_0806687c(p);
          FUN_0806692c(p);
        }
      }

      FUN_080784fc(p);
      action = FUN_080788d0(p);
      FUN_08066d7c(p, action);
      sDjangoActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      } else {
        FUN_08066408(p);
      }

      Player_PostUpdateHuman(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      FUN_08065b7c(p);
      if (p->kind == PLAYER_DARK_DJANGO) {
        Player_CheckTileHit(p);
      }
      FUN_0806623c(p);

      busy = p->goodCondTimer != 0 && p->goodCondID == GOOD_MINI;
      if (busy) {
        return;
      }

      canStep = !Player_IsOnIce(p->tile.attr[1]) && p->action == PACT_WALK && (p->tile.unk_0[0] & 1) && (p->facing & 1);
      if (!canStep) {
        p->unk_3be = 0;
        return;
      }

      p->unk_3be++;
      if (p->unk_3be != 5) {
        return;
      }

      pos = p->mover.pos;
      angle = ((p->facing + 5) & 7) * 32;
      pos.x += POLAR_X(50, angle);
      pos.z += POLAR_Z(50, angle);

      tile = Player_GetTileAt(&pos);
      height = (tile->heightStairs & 0xF) << 8;
      switch (tile->heightStairs >> 4) {
        case STAIRS_VERTICAL: {
          height -= (u8)pos.z;
          break;
        }
        case STAIRS_HORIZONTAL: {
          height -= (u8)pos.x;
          break;
        }
      }
      if ((u32)height < (u32)(p->mover.pos.y + 200)) {
        return;
      }

      tile = Player_GetTileAt(&pos);
      attr = tile->attr;
      if (attr & TATTR_UNK_2) {
        return;
      }

      p->actionDir = p->facing;
      p->unk_3bc = 0;
      Player_SetAction(p, PACT_UNK_4, 0);
      break;
    }
    case PMODE_LOCKED: {
      p->flag20 |= PFLAG20_UNK_18;
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->fn_498(p);
      Player_PostUpdateHuman(p);
      FUN_080726ec(p);
      break;
    }
    case PMODE_DEAD: {
      s32 n;

      p->flag20 |= PFLAG20_UNK_18;
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      if (p->action >= PACT_UNK_28 && p->action <= PACT_UNK_31) {
        n = p->action;
      } else {
        n = (p->blownAway != 0) ? PACT_UNK_27 : PACT_UNK_26;
      }
      sDjangoActionFuncs[n](p);
      Player_PostUpdateHuman(p);
      break;
    }
  }
#else
  INCFUNC("asm/func/Player_UpdateDjango.inc");
#endif
}

// clang-format off
static const PlayerFunc sSabataActionFuncs[32] = {
    [PACT_IDLE] = FUN_08066f7c,
    [PACT_WALK] = FUN_080672b0,
    [PACT_DASH] = Magic_ZeroShift,
    [PACT_ATTACK] = Player_UpdateSabataAttack,
    [PACT_UNK_4] = FUN_08067510,
    [PACT_UNK_5] = FUN_08067de8,
    [PACT_PULL_COFFIN] = Player_UpdatePullCoffin,
    [PACT_UNK_7] = Player_UpdateDarkCharge,
    [PACT_UNK_8] = Player_UpdateSolarStand,
    [PACT_SUN_MAGIC] = Sabata_BlackSun,
    [PACT_UNK_19] = FUN_0806961c,
    [PACT_UNK_20] = FUN_08069648,
    [PACT_GRABBED] = FUN_0806a050,
    [PACT_UNK_22] = Player_UpdateFall,
    [PACT_UNK_23] = FUN_08069f60,
    [PACT_DAMAGED] = Player_UpdateHurt,
    [PACT_BLOWN_AWAY] = Player_UpdateBlownAway,
    [PACT_UNK_26] = Player_UpdateDeath,
    [PACT_UNK_27] = Player_UpdateBlownAwayDeath,
    [PACT_UNK_28] = Player_UpdateFallDeath,
    [PACT_FALLDEATH] = FUN_0806adc8,
    [PACT_UNK_30] = FUN_0806af70,
    [PACT_UNK_31] = FUN_0806b758,
};  // 0x085ABD30
// clang-format on

NAKED void Player_UpdateSabata(Player* p) { INCFUNC("asm/func/Player_UpdateSabata.inc"); }

// バット時の次の行動を入力から決める, 吹き飛ばし中は PACT_DAMAGED, 方向入力があり R を押していなければ PACT_WALK
s32 Player_GetBatAction(Player* p) {
  u32 action;
  if (p->action != PACT_UNK_20 && p->unk_3ff >= 0) {
    p->knockbackTimer = 0;
    p->hurtbox.knockbackPower = 0;
    p->floatHeight = 0;
    Player_SetAction(p, PACT_UNK_20, 0);
  }
  action = p->action;
  if (p->input->pressed & L_BUTTON) {
    action = Player_GetMagicAction(p);
  }
  if (p->hurtbox.knockbackPower != 0) {
    action = PACT_DAMAGED;
  } else if (action != PACT_DAMAGED && action != PACT_UNK_20 && action != PACT_UNK_19 && action != PACT_CBAT) {
    if ((p->input->pressed & A_BUTTON) && MapItemManager_TryOpen(&p->mover)) {
      action = PACT_IDLE;
    } else if ((s16)p->facingHistory[0] == -1 || (p->input->down & R_BUTTON)) {
      action = PACT_IDLE;
    } else {
      action = PACT_WALK;
    }
  }
  return action;
}

// pos のタイルが滑る床か, 氷タイルか氷結した溶岩タイルなら真
bool32 Player_IsIcyTileAt(Vec3* pos) {
  TileAttr attr = GetTileAttrAt(pos);
  if (attr & TATTR_UNK_6) {
    return TRUE;
  }
  if (Player_IsInLava(attr)) {
    return TRUE;
  }
  return FALSE;
}

// 移動先がエレベーターの中心から ±100 を出ないように mover.delta を詰める, エレベーター外で滑る床なら delta を 0 にする
void FUN_08079644(Player* p) {
  Vec3 pos;

  pos.x = p->mover.pos.x + p->mover.delta.x;
  pos.z = p->mover.pos.z + p->mover.delta.z;
  if (p->unk_390 & 4) {
    Vec3* center = Elevator_GetPosByID(p->elevatorID);
    if (pos.x <= center->x - 100) {
      pos.x = center->x - 100;
    } else if (pos.x >= center->x + 100) {
      pos.x = center->x + 100;
    }
    if (pos.z <= center->z - 100) {
      pos.z = center->z - 100;
    } else if (pos.z >= center->z + 100) {
      pos.z = center->z + 100;
    }
    p->mover.delta.x = pos.x - p->mover.pos.x;
    p->mover.delta.z = pos.z - p->mover.pos.z;
  } else if (Player_IsIcyTileAt(&pos)) {
    p->mover.delta.x = 0;
    p->mover.delta.z = 0;
  }
}

// バット時の毎フレームの後処理, 移動を反映し, 浮遊の高さ unk_382 を 16 フレームごとに引き直す目標 unk_383[0] へ寄せ, 表示と食らい判定のフラグを反映する
// 残差は reload の一時レジスタ 2 か所のみ (154/154), 原典は乱数表のアドレスを r3, 0x383 のオフセットを r2 に置くが, こちらは r1 / r3
// Tier A-C 試済 (_Random(table), >> 3 と / 8, 足す順, unk_382 のポインタ), 未: reload の巡回をずらす手
NON_MATCH void Player_PostUpdateBat(Player* p) {
#ifdef NONMATCHING_C
  FUN_08079644(p);
  Mover_ApplyMove(&p->mover);
  FUN_080417dc(&p->mover);

  if (p->action <= PACT_WALK) {
    if (p->unk_383[1] == 0) {
      p->unk_383[0] = Mod(Random() >> 3, 100) + 140;
      p->unk_383[1] = 16;
    } else {
      p->unk_383[1]--;
    }
    if (p->unk_382 <= p->unk_383[0] - 4) {
      p->unk_382 += 4;
    } else if (p->unk_382 >= p->unk_383[0] + 8) {
      p->unk_382 -= 8;
    } else {
      p->unk_382 = p->unk_383[0];
    }
  }
  p->beast.pos.y = p->mover.pos.y + p->unk_382 + p->floatHeight;

  if (Player_TestFlag35a(p, PFLAG35A_NO_HURTBOX)) {
    p->hurtbox.flags |= HBFLAG_HIDDEN;
  } else {
    p->hurtbox.flags &= ~HBFLAG_HIDDEN;
    Hitbox_SetPos(&p->hurtbox, &p->mover.pos, 0);
  }

  if (Player_TestFlag35a(p, PFLAG35A_HIDE_BODY)) {
    p->beast.flags |= SPRFLAG_HIDDEN;
  } else {
    p->beast.flags &= ~SPRFLAG_HIDDEN;
  }

  if (Player_TestFlag35a(p, PFLAG35A_SHOW_OTHER)) {
    p->human.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->human.flags |= SPRFLAG_HIDDEN;
  }

  if (Player_TestFlag35a(p, PFLAG35A_HIDE_SHADOW)) {
    ParticleShadow_Hide(&p->shadow);
  } else {
    ParticleShadow_Show(&p->shadow);
  }
#else
  INCFUNC("asm/func/Player_PostUpdateBat.inc");
#endif
}

// コウモリ形態の毎フレーム更新, unk_1c の状態ごとに行動関数を呼ぶ
void Player_UpdateBat(Player* p) {
  // clang-format off
  static const PlayerFunc sBatActionFuncs[27] = {
      [PACT_IDLE] = FUN_0806c2dc,
      [PACT_WALK] = Player_UpdateBatWalk,
      [PACT_CBAT] = Player_UndoChangeBat,
      [PACT_UNK_19] = FUN_0806c868,
      [PACT_UNK_20] = FUN_0806c6d4,
      [PACT_DAMAGED] = Player_UpdateBatHurt,
  };  // 0x085ABDB0
  // clang-format on

  Player_SetFlag20(p, PFLAG20_UNK_18);

  switch (p->mode) {
    case PMODE_ACTIVE: {
      s32 action;

      if (p->flag20 & PFLAG20_SUNBATHING) {
        Player_StepSunburn(p, gStat->sunGauge);
      }
      if (Player_IsInRain(p)) {
        FUN_0806687c(p);
        FUN_0806692c(p);
      }

      FUN_080784fc(p);
      action = Player_GetBatAction(p);
      FUN_08066d7c(p, action);
      sBatActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      }

      FUN_08066408(p);
      Player_PostUpdateBat(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      FUN_0806623c(p);
      break;
    }
    case PMODE_LOCKED: {
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->fn_498(p);
      Player_PostUpdateBat(p);
      FUN_080726ec(p);
      break;
    }
  }
}

// --------------------------------------------

// マウス時の次の行動を入力から決める, Player_GetBatAction の別版, A で何も開けられなければ PACT_UNK_4 に, PACT_UNK_23 / PACT_UNK_4 / PACT_CMOUSE 中も行動を据え置く
s32 Player_GetMouseAction(Player* p) {
  u32 action;
  if (p->action != PACT_UNK_20 && p->unk_3ff >= 0) {
    p->knockbackTimer = 0;
    p->hurtbox.knockbackPower = 0;
    p->floatHeight = 0;
    Player_SetAction(p, PACT_UNK_20, 0);
  }
  action = p->action;
  if (p->input->pressed & L_BUTTON) {
    action = Player_GetMagicAction(p);
  }
  if (p->hurtbox.knockbackPower != 0) {
    action = PACT_DAMAGED;
  } else if (action != PACT_DAMAGED && action != PACT_UNK_20 && action != PACT_UNK_19 && action != PACT_UNK_23 && action != PACT_UNK_4 && action != PACT_CMOUSE) {
    struct Input* input = p->input;
    if (input->pressed & A_BUTTON) {
      if (MapItemManager_TryOpen(&p->mover)) {
        action = PACT_IDLE;
      } else {
        action = PACT_UNK_4;
      }
    } else if ((s16)p->facingHistory[0] == -1 || (input->down & R_BUTTON)) {
      action = PACT_IDLE;
    } else {
      action = PACT_WALK;
    }
  }
  return action;
}

// マウス時の毎フレームの後処理, 移動と食らい判定を反映し beast を mover の位置に置く
void Player_PostUpdateMouse(Player* p) {
  Mover_ApplyMove(&p->mover);
  FUN_080417dc(&p->mover);

  if (Player_TestFlag35a(p, PFLAG35A_NO_HURTBOX)) {
    p->hurtbox.flags |= HBFLAG_HIDDEN;
  } else {
    p->hurtbox.flags &= ~HBFLAG_HIDDEN;
    Hitbox_SetPos(&p->hurtbox, &p->mover.pos, 0);
  }

  if (Player_TestFlag35a(p, PFLAG35A_HIDE_BODY)) {
    p->beast.flags |= SPRFLAG_HIDDEN;
  } else {
    p->beast.flags &= ~SPRFLAG_HIDDEN;
  }

  if (Player_TestFlag35a(p, PFLAG35A_SHOW_OTHER)) {
    p->human.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->human.flags |= SPRFLAG_HIDDEN;
  }

  if (Player_TestFlag35a(p, PFLAG35A_HIDE_SHADOW)) {
    ParticleShadow_Hide(&p->shadow);
  } else {
    ParticleShadow_Show(&p->shadow);
  }

  p->mover.pos.y += p->heightAboveTile;
  p->beast.pos = p->mover.pos;
  p->beast.pos.y += p->floatHeight;
}

// (Cマウスによる)ネズミ形態の毎フレーム更新, unk_1c の状態ごとに行動関数を呼ぶ
void Player_UpdateMouse(Player* p) {
  // clang-format off
  static const PlayerFunc sMouseActionFuncs[27] = {
      [PACT_IDLE] = FUN_0806ceb0,
      [PACT_WALK] = Player_UpdateMouseWalk,
      [PACT_UNK_4] = FUN_0806d22c,
      [PACT_CMOUSE] = Player_UndoChangeMouse,
      [PACT_UNK_19] = FUN_0806d420,
      [PACT_UNK_20] = FUN_0806d5b0,
      [PACT_UNK_23] = FUN_0806d74c,
      [PACT_DAMAGED] = Player_UpdateMouseHurt,
  };  // 0x085ABE1C
  // clang-format on

  Player_SetFlag20(p, PFLAG20_UNK_14 | PFLAG20_SNEAKING | PFLAG20_UNK_18);

  switch (p->mode) {
    case PMODE_ACTIVE: {
      s32 action;

      if (p->flag20 & PFLAG20_SUNBATHING) {
        Player_StepSunburn(p, gStat->sunGauge);
      }
      if (Player_IsInRain(p)) {
        FUN_0806687c(p);
        FUN_0806692c(p);
      }

      FUN_080784fc(p);
      action = Player_GetMouseAction(p);
      FUN_08066d7c(p, action);
      sMouseActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      }

      Player_PostUpdateMouse(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      FUN_08065b7c(p);
      Player_CheckTileHit(p);
      FUN_0806623c(p);
      break;
    }
    case PMODE_LOCKED: {
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->fn_498(p);
      Player_PostUpdateMouse(p);
      FUN_080726ec(p);
      break;
    }
  }
}

// --------------------------------------------

// スリーピング時の次の行動を入力から決める, エレファン運搬中だけ歩けて B で PACT_ATTACK, それ以外は A で宝箱を開けるだけ
s32 Player_GetSleepingAction(Player* p) {
  u32 action;
  if (p->action != PACT_UNK_20 && p->unk_3ff >= 0) {
    p->knockbackTimer = 0;
    p->hurtbox.knockbackPower = 0;
    p->floatHeight = 0;
    Player_SetAction(p, PACT_UNK_20, 0);
  }
  action = p->action;
  if (p->input->pressed & L_BUTTON) {
    action = Player_GetMagicAction(p);
  }
  if (p->coffin == COFFIN_ELEFAN) {
    if (action <= PACT_WALK) {
      if (p->input->pressed & B_BUTTON) {
        action = PACT_ATTACK;
      } else if ((p->input->pressed & A_BUTTON) && MapItemManager_TryOpen(&p->mover)) {
        action = PACT_IDLE;
      } else if ((s16)p->facingHistory[0] == -1 || (p->input->down & R_BUTTON)) {
        action = PACT_IDLE;
      } else {
        action = PACT_WALK;
      }
    }
  } else if (action == PACT_IDLE && (p->input->pressed & A_BUTTON)) {
    MapItemManager_TryOpen(&p->mover);
  }
  return action;
}

// スリーピング時の毎フレームの後処理, 移動を反映して beast を揺れ (unk_4bc / unk_4c0) と浮きの分ずらし, 表示と食らい判定のフラグを反映する
void Player_PostUpdateSleeping(Player* p) {
  Mover_ApplyMove(&p->mover);
  FUN_080417dc(&p->mover);

  p->beast.pos.x += p->unk_4bc;
  p->beast.pos.y += p->floatHeight;
  p->beast.pos.z += p->unk_4c0;

  if (Player_TestFlag35a(p, PFLAG35A_HIDE_BODY)) {
    p->beast.flags |= SPRFLAG_HIDDEN;
  } else {
    p->beast.flags &= ~SPRFLAG_HIDDEN;
  }

  if (Player_TestFlag35a(p, PFLAG35A_SHOW_OTHER)) {
    p->human.flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->human.flags |= SPRFLAG_HIDDEN;
  }

  if (Player_TestFlag35a(p, PFLAG35A_HIDE_SHADOW)) {
    ParticleShadow_Hide(&p->shadow);
  } else {
    ParticleShadow_Show(&p->shadow);
  }

  if (Player_TestFlag35a(p, PFLAG35A_NO_HURTBOX)) {
    p->hurtbox.flags |= HBFLAG_HIDDEN;
  } else {
    p->hurtbox.flags &= ~HBFLAG_HIDDEN;
    Hitbox_SetPos(&p->hurtbox, &p->mover.pos, 0);
  }
}

// 棺桶で寝ている間の毎フレーム更新, unk_1c の状態ごとに行動関数を呼ぶ
void Player_UpdateSleeping(Player* p) {
  // clang-format off
  static const PlayerFunc sSleepingActionFuncs[21] = {
      [PACT_IDLE] = MagicSleeping_Update,
      [PACT_WALK] = Player_UpdateSleepingWalk,
      [PACT_ATTACK] = FUN_0806e404,
      [PACT_UNK_4] = FUN_0806e4b4,
      [PACT_SLEEPING] = Player_UndoSleeping,
      [PACT_UNK_20] = FUN_0806e674,
  };  // 0x085ABE88
  // clang-format on

  Player_SetFlag20(p, PFLAG20_UNK_14 | PFLAG20_UNK_18);
  p->unk_4bc = 0;
  p->unk_4c0 = 0;
  if (p->unk_38a != 0) {
    p->unk_38a--;
  }

  switch (p->mode) {
    case PMODE_ACTIVE: {
      s32 action;

      FUN_080784fc(p);
      action = Player_GetSleepingAction(p);
      FUN_08066d7c(p, action);
      sSleepingActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      }

      Player_PostUpdateSleeping(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      FUN_08065b7c(p);
      FUN_0806623c(p);
      break;
    }
    case PMODE_LOCKED: {
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->fn_498(p);
      Player_PostUpdateSleeping(p);
      break;
    }
  }
}

// FLAG030047A4_UNK_12 が立っているときの updateCallback (ただし、 FLAG030047A4_UNK_12 の用途がわからないので、この関数の正確な役割もまだ不明, 不使用かも?)
void FUN_08079f1c(Player* p) {
  // clang-format off
  static const PlayerFunc PTR_ARRAY_085abedc[28] = {
      [PACT_IDLE] = FUN_08066f7c,
      [PACT_WALK] = FUN_080672b0,
      [PACT_DASH] = FUN_0806f284,
      [PACT_ATTACK] = FUN_080695ec,
      [PACT_UNK_4] = FUN_08067510,
      [PACT_UNK_5] = FUN_08067de8,
      [PACT_PULL_COFFIN] = Player_UpdatePullCoffin,
      [PACT_UNK_7] = Player_UpdateSolarCharge,
      [PACT_UNK_8] = Player_UpdateSolarStand,
      [PACT_SUN_MAGIC] = MagicRisingSun_08068944,
      [PACT_TRANSFORM] = MagicTransform_0806b92c,
      [PACT_CWOLF] = MagicChangeWolf_0806eb40,
      [PACT_CBAT] = MagicChangeBat_0806bc74,
      [PACT_CMOUSE] = MagicChangeMouse_0806bf18,
      [PACT_SLEEPING] = MagicSleeping_0806c124,
      [PACT_FREEZE] = MagicFreeze_08069710,
      [PACT_HEALING] = MagicHealing_0806f3a0,
      [PACT_DYNAMITE] = FUN_0806f5d8,
      [PACT_UNK_18] = FUN_08069c8c,
      [PACT_UNK_19] = FUN_0806961c,
      [PACT_UNK_20] = FUN_08069648,
      [PACT_GRABBED] = FUN_0806a050,
      [PACT_UNK_22] = Player_UpdateFall,
      [PACT_UNK_23] = FUN_08069f60,
      [PACT_DAMAGED] = Player_UpdateHurt,
      [PACT_BLOWN_AWAY] = Player_UpdateBlownAway,
      [PACT_UNK_26] = Player_UpdateDeath,
      [PACT_UNK_27] = Player_UpdateBlownAwayDeath,
  };  // 0x085ABEDC
  // clang-format on

  s32 action;

  Player_SetFlag20(p, PFLAG20_UNK_14);

  switch (p->mode) {
    case PMODE_ACTIVE: {
      Vec3 pos;
      s32 angle;
      s32 height;
      s32 attr;
      bool32 busy;
      u16 n;
      bool32 canStep;

      FUN_080784fc(p);
      action = FUN_080788d0(p);
      FUN_08066d7c(p, action);
      PTR_ARRAY_085abedc[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      } else {
        FUN_08066408(p);
      }

      Player_PostUpdateHuman(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      FUN_08065b7c(p);
      FUN_0806623c(p);

      n = p->goodCondTimer;
      busy = FALSE;
      if (n != 0 && p->goodCondID == GOOD_MINI) {
        busy = TRUE;
      }
      if (busy) {
        return;
      }

      canStep = !Player_IsOnIce(p->tile.attr[1]) && p->action == PACT_WALK && (p->tile.unk_0[0] & 1) && (p->facing & 1);
      if (canStep) {
        if (++p->unk_3be == 5) {
          pos = p->mover.pos;
          angle = ((p->facing + 5) & 7) * 32;
          pos.x += POLAR_X(50, angle);
          pos.z += POLAR_Z(50, angle);

          height = TileHeightAt(&pos);
          if ((u32)height >= (u32)(p->mover.pos.y + 200)) {
            attr = GetTileAttrAt(&pos);
            if (!(attr & TATTR_UNK_2)) {
              p->actionDir = p->facing;
              p->unk_3bc = 0;
              Player_SetAction(p, PACT_UNK_4, 0);
            }
          }
        }
      } else {
        p->unk_3be = 0;
      }
      break;
    }
    case PMODE_DEAD: {
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      if (p->action >= PACT_UNK_28 && p->action <= PACT_UNK_30) {
        action = p->action;
      } else {
        action = (p->blownAway != 0) ? PACT_UNK_27 : PACT_UNK_26;
      }
      PTR_ARRAY_085abedc[action](p);
      Player_PostUpdateHuman(p);
      break;
    }
    case PMODE_LOCKED: {
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->fn_498(p);
      Player_PostUpdateHuman(p);
      break;
    }
  }
}

// Player の登録表と関連するグローバルをまとめて 0 に戻す
// 単体ではバイト一致するが, 同じ TU の前の関数の .LC 数でレジスタ割当が変わる (agbcc-internals.md §10), 前の関数を C にするたびに壊れるので INCFUNC に戻している
NON_MATCH void UNUSED FUN_0807a270(Player* p) {
#ifdef NONMATCHING_C
  s32 i;

  gPlayerCount = 0;
  for (i = 0; i < 4; i++) {
    gPlayerPtr[i] = NULL;
    gPlayerMoverIDs[i] = 0;
    gPlayerStates[i] = 0;
  }

  gGoodCondID = 0;
  gGoodFrom = 0;
  gGoodCondTimer = 0;
  gRisingSunCount = 0;
  gSunMagicUsed = 0;
  gSunGaugeOverride = 0;
  gSunGaugeOverrideTimer = 0;

  for (i = 0; i < 3; i++) {
    gBadCondTimer[i] = 0;
  }

  gWindPushThreshold = 0;
  gWindStrength = 0;
  gWindAngle = 0;
  gSavedMagicEnchanted = 0;
#else
  INCFUNC("asm/func/FUN_0807a270.inc");
#endif
}

// action 23 に入り, 足元タイルの高さから見た現在の高さを控えて向きのアニメを合わせる
void FUN_0807a334(Player* p) {
  u8 dir;

  if (p->kind == PLAYER_SLEEPING) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
  }
  Player_SetAction(p, PACT_UNK_23, 0);
  p->floatHeight = 0;

  p->heightAboveTile = p->mover.pos.y - TileHeightAt(&p->mover.pos);

  dir = p->facing;
  PLAYER_SET_ANIM_DIR(p, dir);
  p->hurtbox.knockbackPower = 0;
}

void FUN_0807a44c(Player* p, s32 dir) {
  Player_SetAction(p, PACT_UNK_4, 1);
  p->actionDir = dir;
  p->facing = (dir + 4) & 7;
  PLAYER_SET_ANIM_DIR_HALF(p, p->actionDir);
  p->hurtbox.knockbackPower = 0;
}

// プレイヤーが乗っているタイルの索引を返す, MoverTile の控えがあればそれ、無ければ座標から引く
s32 FUN_0807a4c4(s32 n) {
  Player* p = gPlayerPtr[n];

  if (p->mover.tile != NULL) {
    return p->mover.tile->tileIdx[1];
  } else {
    return GetCollisionTileIdx(&p->mover.pos);
  }
}

void FUN_0807a524(Vec3* pos) {}

void FUN_0807a528(Player* p, Vec3* pos, u16 param_3) {
  p->action = PACT_UNK_8;
  p->stateTimer = 0;
  p->state = 0;
  p->floatHeight = 0;
  p->unk_3b0 = *pos;
  p->unk_3b8 = param_3;
}

bool32 FUN_0807a570(Player* p, s32 param_2) {
  bool32 ret;

  if (gGameFlags & FLAG030047A4_LINK) {
    FUN_080d040c(p);
    Player_SetAction(p, PACT_UNK_28, 0);
    return FALSE;
  }
  if (p->action == PACT_PULL_COFFIN) {
    ret = TRUE;
    FUN_0807bdc8(p, p->facing, 1, 0);
  } else {
    ret = FALSE;
    FUN_0807bdc8(p, p->facing, param_2, 0);
  }
  return ret;
}

// 武器 w と鎧 armor から攻撃力を出す, 銃は銃の熟練度と武器の攻撃力だけ, それ以外は鎧の効果を乗せたチカラとレベルに武器の値を足す, サバタはガン・デル・ヘル固定
s32 FUN_0807a5d8(WeaponData* w, const ArmorData* armor) {
  s32 val;
  s32 bonus;

  if (gStat->playerKind == PLAYER_SABATA) {
    return (gWeaponDB[WEAPON_GUN_DEL_HELL].atk + 10) * 2;
  }

  if (w->kind == WK_GUN) {
    if (GetWeaponSkillLevel(WK_GUN) > 98) {
      return (w->atk + 10) * 2;
    }
    return ((Div(GetWeaponSkillLevel(WK_GUN), 10) - 8) * 5 + w->atk) * 2;
  }

  val = gStat->stats[STAT_STRENGTH] + gStat->stats[STAT_KINDS + STAT_STRENGTH];
  if (armor != NULL) {
    switch (armor->effectType) {
      case AET_SILVER_CHAIN: {
        if (gStat->playerKind == PLAYER_SOLAR_DJANGO) {
          val += armor->value;
        } else {
          val -= armor->value;
        }
        break;
      }
      case AET_BLOOD_CAPE: {
        if (gStat->playerKind == PLAYER_SOLAR_DJANGO) {
          val -= armor->value;
        } else {
          val += armor->value;
        }
        break;
      }
      case AET_STR: {
        val += armor->value;
        break;
      }
    }
  }

  if (val > 99) {
    val = 99;
  }
  val = (val + gStat->lv) >> 1;
  if (w->kind == WK_OTHERS) {
    bonus = (GetWeaponSkillLevel(WK_OTHERS) + gStat->lv) >> 2;
  } else {
    bonus = w->quality + w->atk;
    if (bonus < 0) {
      bonus = 0;
    }
  }
  return val + bonus;
}

// 装備中の鎧を添えて FUN_0807a5d8 に渡す, 鎧を装備していなければ NULL を渡す
// 残差2命令 (22対24), 原典は &gStat->armor を adds r1, r0, #0 / add r1, #0x5c で別レジスタに組んでオフセット0で1回読むが, こちらは r0 を直接進める形になり, if/else の落ち方も逆になる
// Tier A-C は試済: gStat->armor を2回書くとアドレスの組み方は一致するが ldrsh が2本になる (25命令). ローカルに受けると1回読みだがアドレスが縮む. 両立する自然な綴りが見つからない
NON_MATCH s32 FUN_0807a6cc(WeaponData* w) {
#ifdef NONMATCHING_C
  s16 armor = gStat->armor;

  if (armor >= 0) {
    return FUN_0807a5d8(w, &gArmorDB[GetInventoryArmor(armor)]);
  } else {
    return FUN_0807a5d8(w, NULL);
  }
#else
  INCFUNC("asm/func/FUN_0807a6cc.inc");
#endif
}

// 鎧の効果を乗せたハヤサから派生値を出す, 鎧を渡さなければ素の値, サバタでプレイ中は gSabataDefence をそのまま返す
s32 FUN_0807a70c(ArmorData* data) {
  s32 val;

  if (gStat->playerKind == PLAYER_SABATA) {
    return gSabataDefence;
  }

  val = gStat->stats[STAT_AGILITY] + gStat->stats[STAT_KINDS + STAT_AGILITY];
  if (data == NULL) {
    return (val + gStat->lv) >> 1;
  }

  switch (data->effectType) {
    case AET_SILVER_CHAIN: {
      if (gStat->playerKind == PLAYER_SOLAR_DJANGO) {
        val += data->value;
      } else {
        val -= data->value;
      }
      break;
    }
    case AET_BLOOD_CAPE: {
      if (gStat->playerKind == PLAYER_SOLAR_DJANGO) {
        val -= data->value;
      } else {
        val += data->value;
      }
      break;
    }
    case AET_AGILITY: {
      val += data->value;
      break;
    }
  }

  if (val > 99) {
    val = 99;
  }
  return ((val + gStat->lv) >> 1) + data->defence;
}

// 経験値を加算する, サバタでプレイ中は入らず、 EBUFF_TRAININGGEAR が立っていると1.5倍になる
NON_MATCH void AddPlayerExp(s32 amount) {
#ifdef NONMATCHING_C
  if (gStat->playerKind != PLAYER_SABATA) {
    if (gPlayerPtr[0] != NULL && Player_TestEquipBuff(gPlayerPtr[0], EBUFF_TRAININGGEAR)) {
      amount = (amount * 3) >> 1;  // 1.5倍
    }
    gStat->exp += amount;
    if (gStat->exp >= 999999) {
      gStat->exp = 999999;
    }
  }
#else
  INCFUNC("asm/func/AddPlayerExp.inc");
#endif
}

// 残差はレジスタの割り当てのみ (命令数 30 対 30): 原典は kind を退避するが、こちらは amount を退避する
NON_MATCH void AddWeaponExp(s32 kind, s32 amount) {
#ifdef NONMATCHING_C
  if (gStat->playerKind != PLAYER_SABATA && kind < 5) {
    gStat->weaponExp[kind] += amount;
    if (gStat->weaponExp[kind] >= 9900) {
      gStat->weaponExp[kind] = 9900;
    }
  }
#else
  INCFUNC("asm/func/AddWeaponExp.inc");
#endif
}

// 当たった武器のビットから該当する武器に経験値を入れる, 剣/槍/ハンマーのときだけ装備の状態を作り直す
void Player_AddWeaponExp(u32 mask, s32 amount) {
  bool32 refresh = FALSE;

  if (mask & (1 << WK_SWORD)) {
    AddWeaponExp(WK_SWORD, amount);
    refresh = TRUE;
  } else if (mask & (1 << WK_SPEAR)) {
    AddWeaponExp(WK_SPEAR, amount);
    refresh = TRUE;
  } else if (mask & (1 << WK_HAMMER)) {
    AddWeaponExp(WK_HAMMER, amount);
    refresh = TRUE;
  } else if (mask & (1 << WK_OTHERS)) {
    AddWeaponExp(WK_OTHERS, amount);
  } else if (mask & (1 << WK_GUN)) {
    AddWeaponExp(WK_GUN, amount);
  }

  if (refresh && gPlayerPtr[0] != NULL) {
    Player_UpdateBloodSword(gPlayerPtr[0]);
  }
}

// 武器の経験値をそのまま返す
static s32 UNUSED GetWeaponSkillExp(s32 kind) { return *(gStat->weaponExp + kind); }

// 武器の経験値をレベルに直す, 100 たまると1レベル
s32 GetWeaponSkillLevel(s32 kind) { return Div(*(gStat->weaponExp + kind), 100); }

void Player_RemoveKaamos(Player* p) { KAAMOS(p->isSabata) = 0; }

void FUN_0807a904(Player* p, u32 flag) {
  if (flag == 0) {
    p->speedPenalty++;
  }
}

// 残差2命令 (24対26), 原典は3つの gStat->playerX/Y/Z の代入ごとに gStat を読み直すが (ldr r3, [r2] が3回), こちらは1回読んで r2 に保持する
// 差は gStat のポインタロードを3つのストアを跨いで CSE するかどうかだけで, 同じ3文のソースから書き分けられない (エイリアス解析の結果). Tier D のフラグ差の可能性あり
NON_MATCH void FUN_0807a91c(Player* p, Vec3* pos) {
#ifdef NONMATCHING_C
  p->mover.pos = *pos;
  p->beast.pos = *pos;
  p->human.pos = *pos;
  gStat->playerX = pos->x;
  gStat->playerY = pos->y;
  gStat->playerZ = pos->z;
#else
  INCFUNC("asm/func/FUN_0807a91c.inc");
#endif
}

bool32 FUN_0807a954(Player* p, u32 mask) {
  if (p->unk_390 & mask) {
    return TRUE;
  }
  return FALSE;
}

u32 Player_GetElevatorID(Player* p) { return p->elevatorID; }

void FUN_0807a97c(Player* p, u32 flags, u32 value) {
  p->unk_390 |= flags;
  p->elevatorID = value;
}

void FUN_0807a99c(Player* p, u32 flags) {
  p->unk_390 &= ~flags;
  p->elevatorID = 0;
}

void Player_SetKnockbackOrigin(Player* p, Vec3* origin) {
  p->knockbackOrigin = origin;
  p->originHitPending = TRUE;
}

bool32 FUN_0807a9d0(Player* p) {
  if (!(p->mode & PMODE_ACTIVE)) {
    return FALSE;
  }
  if (p->action > PACT_WALK && p->action != PACT_ATTACK && (p->action != PACT_UNK_7 || p->state != 0)) {
    return FALSE;
  }
  return TRUE;
}

static void Player_AddHP(Player* p, s32 amount) {
  if (p->mode == PMODE_ACTIVE) {
    p->hp += amount;
    if (p->hp >= p->maxHP) {
      p->hp = p->maxHP;
    }
  }
}

void Player_AddENE(Player* p, s32 amount) {
  if (p->mode == PMODE_ACTIVE) {
    p->ene += amount;
    if (p->ene >= p->maxEne) {
      p->ene = p->maxEne;
    }
  }
}

// ENE を減らす, 0 未満にはならない
void Player_ReduceENE(Player* p, s32 amount) {
  if (p->mode == PMODE_ACTIVE) {
    u16* ene = &p->ene;

    if (*ene < amount) {
      *ene = 0;
    } else {
      *ene -= amount;
    }
  }
}

// 月光虫取得時に呼ばれる(HP回復), 精霊の衣を着ていると効果が2倍になる
void Player_ApplyMoonbug(Player* p, s32 amount) {
  if (TEST_FLAGS(p->equipBuffs, EBUFF_FAIRY)) {
    Player_AddHP(p, amount * 2);
  } else {
    Player_AddHP(p, amount);
  }
}

// 太陽虫取得時に呼ばれる(Ene回復), 精霊の衣を着ていると効果が2倍になる
void Player_ApplySolarbug(Player* p, s32 amount) {
  if (TEST_FLAGS(p->equipBuffs, EBUFF_FAIRY)) {
    Player_AddENE(p, amount * 2);
  } else {
    Player_AddENE(p, amount);
  }
}

// 暗黒虫取得時に呼ばれる(Eneが減る), 精霊の衣を着ていると効果が2倍になる
void Player_ApplyDarkbug(Player* p, s32 amount) {
  if (TEST_FLAGS(p->equipBuffs, EBUFF_FAIRY)) {
    Player_ReduceENE(p, amount * 2);
  } else {
    Player_ReduceENE(p, amount);
  }
}

void Player_EnterGrabbed(Player* p) {
  Player_SetFlag20(p, PFLAG20_UNK_12);
  p->formRequest = FALSE;
  p->animIDOffset = 0;
  FUN_08063220(p);
  p->hurtbox.flags |= HBFLAG_HIDDEN;
  p->hurtbox.knockbackPower = 0;
  p->hurtbox.invincibleTime = 0;
  Player_SetAction(p, PACT_GRABBED, 0);
}

// pos に拘束 (PACT_GRABBED) して固定する, hidden なら姿を隠し, そうでなければ拘束アニメを流す, power > 0 ならダメージを与える, 拘束できなければ -1
s32 Player_HoldGrabbed(Player* p, Vec3* pos, Vec3* hitPos, s32 animOffset, s32 xflip, s32 flashPose, bool32 hidden, s32 power, HitboxAttributes attrs) {
  if (p->mode != PMODE_ACTIVE || TEST_FLAGS(p->flag20, PFLAG20_UNK_18)) {
    return -1;
  }
  if (p->action != PACT_GRABBED) {
    Player_EnterGrabbed(p);
  }
  p->mover.pos = *pos;
  p->human.pos = p->mover.pos;
  if (hidden) {
    p->human.flags |= SPRFLAG_HIDDEN;
    p->unk_3fe = 0;
  } else {
    p->human.flags &= ~SPRFLAG_HIDDEN;
    p->unk_3fe = 1;
    p->xflip = xflip;
    Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 20) + animOffset, Q6(1));
  }
  if (flashPose > 0) {
    p->flashPose = flashPose;
    p->flashTimer = 64;
  }
  if (power > 0) {
    s32 ret = Player_TakeInstantHit(p, power, 0, 0, 0, attrs);
    if (p->mover.unk_4 == 0 && hitPos != NULL) {
      p->pos_970 = *hitPos;
    }
    return ret;
  }
  return 0;
}

// PACT_GRABBED (拘束中) なら pos へ移して angle の向きへ吹き飛ばし, power > 0 ならダメージも与える, 拘束中でなければ -1
// 残差はレジスタ割り当てのみ (103/103), 原典は mode を r2, pos を r5, invincibleTime を r6 に置き, 0x2E8 のオフセットを r7 に残して xflip の格納で subs r7, #1 と使い回す
// Tier A-C 試済 (条件の入れ子と結果変数, 末尾の if/else, angle の再代入, facing のスコープ), 未: 割り当て順を動かす手
NON_MATCH s32 Player_ReleaseGrabbed(Player* p, Vec3* pos, s32 knockbackPower, s32 angle, s32 invincibleTime, s32 flashPose, s32 power, HitboxAttributes attrs) {
#ifdef NONMATCHING_C
  u32 facing;
  s32 ret;
  if (p->mode != PMODE_ACTIVE || p->action != PACT_GRABBED) {
    return -1;
  }
  if (flashPose > 0) {
    p->flashPose = flashPose;
    p->flashTimer = 64;
  }
  if (invincibleTime > 0) {
    p->hurtbox.invincibleTime = invincibleTime;
  }
  p->mover.pos = *pos;
  facing = (((angle + 0xE0) & 0xFF) >> 6) * 2 + 1;
  p->facing = facing;
  if (facing > 4) {
    p->animIDOffset = 8 - facing;
    p->xflip = TRUE;
  } else {
    p->animIDOffset = facing;
    p->xflip = FALSE;
  }
  p->hurtbox.knockbackPower = knockbackPower;
  p->blownAway = 1;
  PlaySound_082406e0(SE_DAMAGE);
  if (p->unk_3ec != 0) {
    p->unk_3ec = 0;
  }
  if (power <= 0) {
    ret = 0;
  } else {
    ret = Player_TakeInstantHit(p, power, 0, 0, 0, attrs);
  }
  return ret;
#else
  INCFUNC("asm/func/Player_ReleaseGrabbed.inc");
#endif
}

bool32 FUN_0807ad60(Player* p, s32 param_2) {
  if (p->mode != PMODE_ACTIVE || p->kind == PLAYER_BAT) {
    return FALSE;
  }
  if (p->unk_3ec != 0) {
    p->unk_3ea = 1;
    return FALSE;
  }
  if (p->kind == PLAYER_MOUSE || p->kind == PLAYER_SLEEPING) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
  }
  p->unk_3ec = param_2;
  p->unk_3ea = 1;
  return TRUE;
}

// 残差2命令: 原典は 0x1A と 0x1F の Player_SetAction(p, X, 4) の末尾を cross-jump で共有するが、こちらは別々に出る
NON_MATCH void FUN_0807adc0(Player* p) {
#ifdef NONMATCHING_C
  if (p->action == PACT_UNK_26) {
    if (p->state == 3) {
      Player_SetAction(p, PACT_UNK_26, 4);
    }
  } else if (p->action == PACT_UNK_27) {
    if (p->state == 4) {
      Player_SetAction(p, PACT_UNK_27, 5);
    }
  } else if (p->action == PACT_UNK_31) {
    if (p->kind == PLAYER_SABATA) {
      if (p->state == 3) {
        Player_SetAction(p, PACT_UNK_31, 4);
      }
    } else if (p->state == 1) {
      Player_SetAction(p, PACT_UNK_31, 2);
    }
  } else if (p->mode == PMODE_LOCKED && p->action == PACT_UNK_18 && p->state == 1) {
    Player_SetAction(p, PACT_UNK_18, 4);
  }
#else
  INCFUNC("asm/func/FUN_0807adc0.inc");
#endif
}

// 体にまとわりつく粒子 (emitter) を kind で count 個出す, 種類が違えば今のを消して出し直し, 出せたら種類ごとに音とダメージ (2: +10, 3: 小さく弾かれる) を与える
void FUN_0807ae6c(Player* p, u32 kind, s32 count) {
  u16* table;
  Vec3 spread;
  bool32 spawned;
  s32 i;

  if (!(gGameFlags & FLAG030047A4_UNK_12)) {
    return;
  }
  if (p->emitter.unk_3 != 0 && p->emitter.kind != kind) {
    if (p->emitter.kind == 3) {
      return;
    }
    FUN_08063248(p);
  }
  if (p->emitter.unk_3 == 0) {
    p->mashCountBase = p->mashCount;
    p->unk_3da = 0;
  }

  table = gRandomTable;
  spread.x = (_Random(table) & 0xF) - 7;
  spread.y = -(_Random(table) & 0x1F);
  spread.z = 0;
  spawned = FALSE;
  for (i = 0; i < count; i++) {
    if (FUN_082467d0(&p->emitter, kind, 3600, &spread) >= 0) {
      spawned = TRUE;
    }
  }

  if (spawned) {
    if (p->emitter.kind == 1) {
      PlaySound_082406e0(SE_IGNITE);
    } else if (p->emitter.kind == 2) {
      p->damage += 10;
      PlaySound_082406e0(SE_SOLIDIFY);
    } else if (p->emitter.kind == 3) {
      PlaySound_082406e0(SE_SOLIDIFY);
      p->hurtbox.knockbackPower = 10;
      if (p->hurtbox.invincibleTime == 0) {
        p->hurtbox.invincibleTime = 1;
      }
      p->blownAway = 0;
    }
  }
  p->badCondTimer[BAD_POISON] = 0;
}

// '.i' から gPlayerPtr の idx を取得する, なかったら 0 (1P) を返す
u32 VM_GetPlayerIdx(void) { return VM_SeekToNamedArg('i') ? VM_GetValue() : 0; }

static bool32 FUN_0807b000(Vec3* pos) {
  if (VM_SeekToNamedArg('p')) {
    pos->x = VM_GetValue(), pos->y = VM_GetValue(), pos->z = VM_GetValue();
    return TRUE;
  }
  return FALSE;
}

// 0xE14B
void Cmd_E14B(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && FUN_0807b000(&p->mover.pos)) {
    if (VM_SeekToNamedArg('d')) {
      p->facing = VM_GetValue();
      if (p->facing > FACE_DOWN) {
        p->animIDOffset = 8 - p->facing;
        p->xflip = TRUE;
      } else {
        p->animIDOffset = p->facing;
        p->xflip = FALSE;
      }
    }
    Map_InitMoverTile(&p->tile, &p->mover.pos);
    Player_SetAction(p, PACT_IDLE, 0);
    Player_StopEneChargeSound(p);
  }
}

// 0x7017
NON_MATCH s32 Cmd_7017(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p == NULL) {
    return gStat->playerFacing;
  }
  if (p->action == PACT_UNK_4 || p->action == PACT_UNK_5) {
    return (p->actionDir + 4) & 7;
  }
  return p->facing;
#else
  INCFUNC("asm/func/Cmd_7017.inc");
#endif
}

// 0x5986
bool32 Cmd_5986(void) {
  if (gPlayerPtr[0] == NULL || gPlayerPtr[0]->mode != PMODE_DEAD) {
    return FALSE;
  }
  return TRUE;
}

// 0xE756
s32 Cmd_E756(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] == NULL) {
    return 0;
  }
  return FUN_0807a9d0(gPlayerPtr[i]);
}

// 0x1BEE
void Cmd_AddPlayerExp(void) {
  if (VM_SeekToNamedArg('e')) {
    AddPlayerExp(VM_GetValue());
  }
}

// 0xD4B5, 鍛治による武器経験値取得
void Cmd_AddForgeExp(void) {
  if (VM_SeekToNamedArg('t')) {
    s32 kind = VM_GetValue();

    if (VM_SeekToNamedArg('p')) {
      AddWeaponExp(kind, VM_GetValue());
    }
  }
}

// 0x440F
// 残差1命令 (24対25), 原典は gPlayerPtr[i] を ldr r0, [r0] で読んでから adds r4, r0, #0 で写すが, こちらは ldr r4, [r0] と直接読む
// VM_GetValue() をローカルに受けて & の被演算子順を固定したぶんは解消済み. 残りは Cmd_GetGoodCond と同一の詰まりで, そちらで Tier A-C を試済
NON_MATCH s32 Cmd_TestEquipBuff(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  EquipBuffs bits;

  if (p == NULL || !VM_SeekToNamedArg('f')) {
    return 0;
  }
  bits = VM_GetValue();
  return p->equipBuffs & bits;
#else
  INCFUNC("asm/func/Cmd_TestEquipBuff.inc");
#endif
}

// 0xEA00, '.E' のアイテムの効果を Player に直接かける, IET_GOOD は '.t' (既定は value2 秒) だけよい状態にし, IET_HP は回復量を表示する
void Cmd_EA00(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('E')) {
    s32 id = VM_GetValue();
    if (gItemDB[id].effectType == IET_GOOD) {
      s32 timer = VM_SeekToNamedArg('t') ? VM_GetValue() : gItemDB[id].value2 * 60;
      p->goodCondID = gItemDB[id].value1;
      p->goodCondTimer = timer;
      p->goodFrom = id;
      p->plttID_95e = 289;
      p->plttFlashTimer = 48;
    } else if (gItemDB[id].effectType == IET_HP) {
      s32 amount = Div(p->maxHP * gItemDB[id].value1, 100);
      s32 hp = p->hp + amount;
      if (hp > p->maxHP) {
        amount = p->maxHP - p->hp;
        p->hp = p->maxHP;
      } else {
        p->hp = hp;
      }
      if (amount > 0) {
        CreateDamageNumber(&p->hurtbox, amount, 1, &p->mover.pos, &p->pos_970, 0);
      }
      p->plttID_95e = 289;
      p->plttFlashTimer = 48;
    }
  }
}

// 0x0E15
// 残差1命令 (21対22), 原典は gPlayerPtr[i] を ldr r0, [r0] で読んでから adds r1, r0, #0 で写すが, こちらは ldr r1, [r0] と直接読むぶん1本短い
// Tier A-C は試済 (&& と入れ子 if, 宣言と代入の分離, gPlayerPtr[VM_GetPlayerIdx()] の1ローカル化 (これは push {r4, lr} になって悪化)). 直下の Cmd_RemoveGoodCond は同じ前置きで一致しているので前置きの書き方ではない
NON_MATCH s32 Cmd_GetGoodCond(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && p->goodCondTimer != 0) {
    return p->goodCondID;
  }
  return -1;
#else
  INCFUNC("asm/func/Cmd_GetGoodCond.inc");
#endif
}

// 0x5FDA
void Cmd_RemoveGoodCond(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    p->goodCondID = 0;
    p->goodCondTimer = 0;
    p->goodFrom = 0;
  }
}

// 0xCD57
// 残差1命令: 原典は読み込んだ Player* をもう1本のレジスタに写す (agbcc-levers.md 参照)
NON_MATCH void Cmd_CD57(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('f')) {
    FUN_08060ec8(p, VM_GetValue());
    if (FUN_08060ed8(p, 0x3FFE)) {
      p->magic.availableForm = Player_IsMagicAvailableForm(p, p->magic.id);
    }
    if (VM_SeekToNamedArg('p')) {
      p->scriptID_9c0 = VM_GetValue();
    }
  }
#else
  INCFUNC("asm/func/Cmd_CD57.inc");
#endif
}

// 0x2B68
void Cmd_2B68(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    FUN_08063220(gPlayerPtr[i]);
  }
}

// 0xDD0E
// 残差は分岐の配置のみ (命令数 28 対 28): 原典は return 0 のブロックが先に出て、成功側が後ろに置かれる
NON_MATCH bool32 Cmd_DD0E(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('s')) {
    s32 n = VM_GetValue();

    if (n <= 2 && p->badCondTimer[n] != 0) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Cmd_DD0E.inc");
#endif
}

// 0x650B
void Cmd_650B(void) {
  static const u16 sBadCondFrames[3] = {SECOND(30), SECOND(30), SECOND(15)};  // 0x085ABF4C
  if (VM_SeekToNamedArg('s')) {
    s32 n = VM_GetValue();

    if (n < (s32)ARRAY_COUNT(sBadCondFrames)) {
      s32 val = VM_SeekToNamedArg('t') ? VM_GetValue() : sBadCondFrames[n];

      if (gPlayerPtr[0] != NULL) {
        Player_ApplyBadCondition(gPlayerPtr[0], n, val);
      } else {
        gBadCondTimer[n] = val;
      }
    }
  }
}

// 0x89C6
void Cmd_89C6(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('s')) {
    Player_ClearBadCondition(p, VM_GetValue());
  }
}

// 0xB603
void Cmd_B603(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 j;

    for (j = 0; j < 3; j++) {
      Player_ClearBadCondition(p, j);
    }
  }
}

// 0x4A8D
bool32 Cmd_IsKaamos(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p == NULL) {
    return FALSE;
  }

  if (KAAMOS(p->isSabata) > 0) {
    return TRUE;
  } else {
    return FALSE;
  }
}

// 0xD9B7
void Cmd_RemoveKaamos(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    KAAMOS(p->isSabata) = 0;
  }
}

// 0x898D
void Cmd_898D(void) {
  gSunMagicUsed = 0;
  gSunGaugeOverride = 0;
  gSunGaugeOverrideTimer = 0;
}

// 0xFD12
void Cmd_FD12(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    gPlayerPtr[i]->unk_43a = 1;
  }
}

// 0xE9E2
void Cmd_E9E2(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    gPlayerPtr[i]->unk_3ba = 1;
  }
}

// 0x41D3
void Cmd_41D3(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    gPlayerPtr[i]->magic.unk_285 = 1;
  }
}

// 0x8CFE
void Cmd_8CFE(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    gPlayerPtr[i]->magic.unk_285 = 0;
  }
}

// 0x237A, スクリプトが指すプレイヤーの武器種を返す
s32 Cmd_GetWeaponKind(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] == NULL) {
    return 0;
  }
  return gPlayerPtr[i]->wpn.weaponKind;
}

// 0x0353
void Cmd_0353(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    Player_EnterDeadState(gPlayerPtr[i]);
  }
}

// 残差1命令: 原典は gPlayerPtr[i] を読んだあと別レジスタへ写し、後半の呼び出しはそちらを使う
// Cmd_GetGoodCond と同じ「読んだポインタの写し」が出ない類, ローカル1個・gPlayerPtr[i] 直接・両者の混在を試済
NON_MATCH void Cmd_D8DF(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_EnterDeadState(p);
    if (VM_SeekToNamedArg('d')) {
      p->facing = VM_GetValue();
    }
    Player_SetAnimFacing(p);
    Player_SetAction(p, PACT_UNK_31, 0);
  }
#else
  INCFUNC("asm/func/Cmd_D8DF.inc");
#endif
}

// Cウルフ中に '.p' の座標が前方 ±32 かつ 2 タイル以内にあり, '.d' の向きも前方 ±32 以内なら真
// 残差は p の複写のみ, 原典は p を r8 と r9 に持ち facing だけ r9 から読む
// Tier A-C 試済 (向きの角度を Player* を受ける inline で取る, 添字ローカルを外す, facing を gPlayerPtr[i] から読み直す, 全部 gPlayerPtr[i] で読む), 未: p の複写の再現
NON_MATCH s32 Cmd_7117(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && p->action == PACT_CWOLF && VM_SeekToNamedArg('p')) {
    Vec3 pos;
    s32 dx, dz;
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    dx = pos.x - p->mover.pos.x;
    dz = pos.z - p->mover.pos.z;
    if (dx * dx + dz * dz <= 0x40000) {
      s32 angle = ((p->facing + 5) & 7) << 5;
      s32 d = Angle_Diff(ArcTan2_8(dx, dz), angle - 0x100);
      if ((d <= 32 || d >= 224) && VM_SeekToNamedArg('d')) {
        d = Angle_Diff(VM_GetValue(), angle - 0x100);
        if (d <= 32 || d >= 224) {
          return TRUE;
        }
      }
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Cmd_7117.inc");
#endif
}

// 操作不能 (PMODE_LOCKED) に移す, Cウルフの噛みつきを解き, 食らい判定を外して見回しも終える
void Player_EnterLockedState(Player* p) {
  if (p->mode != PMODE_LOCKED) {
    p->unk_992 = 0;
    p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 0x7F, 0, 0, 0, 0x50);
  }
  p->mode = PMODE_LOCKED;
  p->unk_4aa = 0;
  p->unk_4a8 = 1;
  p->floatHeight = 0;
  p->heightAboveTile = 0;
  if (gCWolfTarget != NULL && gChangeWolfBiting) {
    if (!(gCWolfTarget->flags & 1)) {
      gCWolfTarget->fn(gCWolfTarget->owner, 1, 60);
    }
    gCWolfTarget = NULL;
    gChangeWolfBiting = 0;
  }
  Player_StopEneChargeSound(p);
  p->hurtbox.knockbackPower = 0;
  p->hurtbox.flags |= HBFLAG_HIDDEN;
  p->hurtbox.invincibleTime = 0;
  if (p->lookAroundOffset.val != 0) {
    Player_EndLookAround(p);
  }
  Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
  Player_SetFlag20(p, PFLAG20_UNK_18);
}

void FUN_0807b890(Player* p, s32 plttID) {
  p->unk_96c = 1;
  p->plttID_95e = plttID;
}

void FUN_0807b8a8(Player* p, s32 plttID) {
  p->unk_96c = 2;
  p->plttID_95e = plttID;
}

void FUN_0807b8c0(Player* p) { p->unk_96c = 0; }

void Player_SetPos(Player* p, WorldPos* src) { p->mover.pos = *src; }

void FUN_0807b8dc(Player* p) {
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 0);
  p->human.flags |= SPRFLAG_HIDDEN;
  p->fn_498 = FUN_080726e0;
}

// 向き (負なら据え置き) を指定して素立ちにし, 操作不能状態に移す (Cmd_LockPlayer から, イベント前の整え)
// フォームは変えず, 今の kind の待機ルーチンを fn_498 に据える, バットは向きが4方向しかないので奇数に丸めて animIDOffset / xflip を自前で作る
void Player_Lock(Player* p, s32 val) {
  if (val >= 0) {
    p->facing = val;
  }

  if (p->kind == PLAYER_BAT) {
    p->facing |= 1;
    PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
    p->fn_498 = FUN_08074d90;
  } else {
    Player_SetAnimFacing(p);
    if (p->kind == PLAYER_MOUSE) {
      p->fn_498 = FUN_08075df8;
    } else if (p->kind == PLAYER_SLEEPING) {
      p->fn_498 = FUN_080772ec;
    } else {
      p->fn_498 = FUN_08072724;
    }
  }

  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 0);
}

void FUN_0807b9dc(Player* p, DirS32 dir, u32 scriptID) {
  p->dir_4a9 = dir;
  p->scriptID_4b0 = scriptID;
  p->fn_498 = FUN_080727d4;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 0);
}

void FUN_0807ba14(Player* p, DirS32 dir) {
  if (dir >= 0) {
    p->facing = dir;
  }
  Player_SetAnimFacing(p);
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 1);
  p->fn_498 = FUN_08072724;
}

void FUN_0807ba50(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) {
    p->facing = dir;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 2);
  p->fn_498 = FUN_08072724;
}

void FUN_0807ba94(Player* p, Vec3* pos, u32 scriptID, DirS32 dir) {
  p->unk_49c = *pos;
  p->scriptID_4b0 = scriptID;
  p->dir_4a9 = dir;
  if (p->kind == PLAYER_BAT) {
    if (p->dir_4a9 >= 0) {
      p->dir_4a9 = ((p->dir_4a9 >> 1) << 1) + 1;
    }
    p->fn_498 = Player_UpdateBatMoveTo;
  } else if (p->kind == PLAYER_MOUSE) {
    p->fn_498 = Player_UpdateMouseMoveTo;
  } else {
    if (p->kind == PLAYER_SLEEPING) {
      p->formRequest = TRUE;
      p->formRequestKind = PLAYER_DARK_DJANGO;
      p->fn_498 = FUN_08072a38;
    } else {
      p->fn_498 = FUN_08072a38;
    }
  }
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_WALK, 0);
}

void FUN_0807bb3c(Player* p, Vec3* pos, DirS32 dir, s32 param_4, u32 scriptID) {
  if (pos == NULL) {
    p->unk_49c = p->mover.pos;
  } else {
    p->unk_49c = *pos;
  }
  p->scriptID_4b0 = scriptID;
  p->unk_4a6 = param_4;
  p->dir_4a9 = dir;
  p->unk_4a7 = 0x96;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_PULL_COFFIN, 0);
  p->fn_498 = FUN_08072d48;
}

void FUN_0807bbb0(Player* p, s32 param_2, u32 scriptID) {
  Player_Lock(p, 4);
  p->unk_4a6 = param_2;
  p->scriptID_4b0 = scriptID;
  p->facing = FACE_DOWN;
  p->animIDOffset = 1;
  p->xflip = 0;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_7, 0);
  p->fn_498 = FUN_0807304c;
}

void FUN_0807bc14(Player* p, s32 param_2, u32 scriptID) {
  p->unk_4a6 = param_2;
  p->scriptID_4b0 = scriptID;
  p->facing = FACE_UP;
  p->animIDOffset = 0;
  p->xflip = 0;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_7, 0);
  p->fn_498 = FUN_0807304c;
}

void FUN_0807bc64(Player* p, u32 scriptID) {
  if (p->mode == PMODE_LOCKED && p->action == PACT_UNK_7 && p->state != 0) {
    p->scriptID_4b0 = scriptID;
    Player_EnterLockedState(p);
    Player_SetAction(p, PACT_UNK_7, 3);
    p->fn_498 = FUN_0807304c;
  }
}

void FUN_0807bcb0(Player* p, DirS32 dir, u32 scriptID) {
  Player_EnterLockedState(p);
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_18, 0);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bcfc(Player* p, DirS32 dir) {
  Player_EnterLockedState(p);
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  PlaySound_082406e0(SONG_198);
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_18, 2);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bd44(Player* p, DirS32 dir) {
  Player_EnterLockedState(p);
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_18, 1);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bd84(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_18, 3);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bdc8(Player* p, DirS32 dir, s32 param_3, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  p->scriptID_4b0 = scriptID;
  p->unk_4a6 = param_3;
  p->unk_3f0 = param_3;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_22, 0);
  if (p->kind == PLAYER_MOUSE) {
    p->fn_498 = Player_UpdateMouseFall;
  } else {
    if (p->kind == PLAYER_SLEEPING) {
      p->formRequest = TRUE;
      p->formRequestKind = PLAYER_DARK_DJANGO;
    }
    p->fn_498 = FUN_080736b8;
  }
}

void FUN_0807be58(Player* p, DirS32 dir, s32 param_3, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  p->floatHeight = param_3;
  Player_SetAction(p, PACT_UNK_23, 0);
  if (p->kind == PLAYER_MOUSE) {
    p->fn_498 = Player_UpdateMouseLand;
  } else {
    if (p->kind == PLAYER_SLEEPING) {
      p->formRequest = TRUE;
      p->formRequestKind = PLAYER_DARK_DJANGO;
    }
    p->fn_498 = FUN_080738b4;
  }
}

void FUN_0807bee0(Player* p, DirS32 dir, s32 param_3, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  if (p->facing > FACE_DOWN) {
    p->animIDOffset = (8 - p->facing) >> 1;
    p->xflip = TRUE;
  } else {
    p->animIDOffset = p->facing >> 1;
    p->xflip = FALSE;
  }
  p->knockbackSpeed_4a4 = param_3;
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_DAMAGED, 0);
  if (p->kind == PLAYER_BAT) {
    p->fn_498 = Player_UpdateBatKnockback;
  } else if (p->kind == PLAYER_MOUSE) {
    p->fn_498 = Player_UpdateMouseKnockback;
  } else {
    p->fn_498 = FUN_080739e0;
  }
}

void FUN_0807bfa4(Player* p, DirS32 dir, s32 param_3, s32 param_4, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  if (p->facing > FACE_DOWN) {
    p->animIDOffset = (8 - p->facing) >> 1;
    p->xflip = TRUE;
  } else {
    p->animIDOffset = p->facing >> 1;
    p->xflip = FALSE;
  }
  p->knockbackSpeed_4a4 = param_3;
  p->unk_4a6 = param_4;
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_BLOWN_AWAY, 0);
  p->fn_498 = FUN_08073b3c;
}

void FUN_0807c048(Player* p, s32 scriptID) {
  if (p->mode == PMODE_LOCKED && p->action == PACT_BLOWN_AWAY && p->state == 5) {
    p->scriptID_4b0 = scriptID;
    p->state = 4;
    Player_EnterLockedState(p);
  }
}

void FUN_0807c084(Player* p, DirS32 dir, s32 param_3, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  if (p->facing > FACE_DOWN) {
    p->animIDOffset = (8 - p->facing) >> 1;
    p->xflip = TRUE;
  } else {
    p->animIDOffset = p->facing >> 1;
    p->xflip = FALSE;
  }
  p->knockbackSpeed_4a4 = param_3;
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_DAMAGED, 0);
  p->fn_498 = FUN_08073e18;
}

void FUN_0807c11c(Player* p, DirS32 dir) {
  u16 animID;

  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  if (p->facing > FACE_DOWN) {
    p->animIDOffset = (8 - p->facing) >> 1;
    p->xflip = TRUE;
  } else {
    p->animIDOffset = p->facing >> 1;
    p->xflip = FALSE;
  }
  Player_EnterLockedState(p);
  animID = p->animIDOffset + Player_GetAnimIdx(p->kind, 46);
  MainSprite_SetAnim(&p->human, &p->humanGfx, animID, PLAYMODE_LOOP, MAIN_ANIM_REVERSE);
  MainSprite_AdvanceAnim(&p->human, &p->humanGfx);
  if (p->xflip) {
    p->human.flags |= SPRFLAG_XFLIP;
  } else {
    p->human.flags &= ~SPRFLAG_XFLIP;
  }
  Player_SetAction(p, PACT_DAMAGED, 2);
  p->fn_498 = FUN_08073e18;
}

void FUN_0807c200(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_7, 0);
  if (p->kind == PLAYER_BAT) {
    p->facing |= 1;
    if (p->facing > FACE_DOWN) {
      p->animIDOffset = (8 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animIDOffset = p->facing >> 1;
      p->xflip = FALSE;
    }
    p->fn_498 = FUN_08075134;
  } else {
    if (p->facing >= FACE_RIGHT && p->facing <= FACE_LEFT) {
      p->facing = FACE_DOWN;
    } else {
      p->facing = FACE_UP;
    }
    Player_SetAnimFacing(p);
    if (p->kind == PLAYER_MOUSE) {
      p->fn_498 = FUN_0807688c;
    } else if (p->kind == PLAYER_SLEEPING) {
      p->fn_498 = FUN_080773f0;
    } else {
      p->animIDOffset >>= 2;
      p->xflip = FALSE;
      p->fn_498 = FUN_0807317c;
    }
  }
}

void FUN_0807c30c(Player* p, DirS32 dir, u32 scriptID) {
  if (p->kind >= PLAYER_BAT && p->kind <= PLAYER_SLEEPING) {
    FUN_0807c200(p, dir, scriptID);
  }
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_7, 7);
  p->fn_498 = FUN_0807317c;
}

// 向きとスクリプトを指定して操作不能状態に移し, フォームごとの PACT_UNK_7 の処理を fn_498 に据える (Cmd_EA96 から)
void FUN_0807c36c(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  if (p->kind == PLAYER_BAT) {
    p->facing |= 1;
    PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
    Player_SetAction(p, PACT_UNK_7, 3);
    p->fn_498 = FUN_08075134;
  } else {
    Player_SetAnimFacing(p);
    if (p->kind == PLAYER_MOUSE) {
      Player_SetAction(p, PACT_UNK_7, 3);
      p->fn_498 = FUN_0807688c;
    } else if (p->kind == PLAYER_SLEEPING) {
      Player_SetAction(p, PACT_UNK_7, 3);
      p->fn_498 = FUN_080773f0;
    } else {
      Player_SetAction(p, PACT_UNK_7, 4);
      p->fn_498 = FUN_0807317c;
    }
  }
}

void FUN_0807c458(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 0);
  p->fn_498 = FUN_08073f88;
}

void FUN_0807c49c(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 2);
  p->fn_498 = FUN_08073f88;
}

void FUN_0807c4e0(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 0);
  p->fn_498 = FUN_080740b0;
}

void FUN_0807c524(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 2);
  p->fn_498 = FUN_080740b0;
}

void FUN_0807c568(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 0);
  p->fn_498 = FUN_08074244;
}

void FUN_0807c5ac(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 2);
  p->fn_498 = FUN_08074244;
}

void FUN_0807c5f0(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 0);
  p->fn_498 = FUN_08074350;
}

// イベント中に銃を撃つ (Cmd_1F3B から), 向きの前方 150 / 高さ 230 に弾 (Entity080c0fa0) を出して操作不能の攻撃モーションに入る
void FUN_0807c634(Player* p, s32 param_2, u32 scriptID) {
  Vec3 pos = p->mover.pos;
  s32 angle = ((p->facing + 5) & 7) * 32;
  SpriteID32 pltt;

  pos.x += POLAR_X(150, angle);
  pos.y += 230;
  pos.z += POLAR_Z(150, angle);
  if (p->kind == PLAYER_SABATA) {
    PlaySound_082406e0(SONG_515);
    pltt = 0x32;
  } else {
    PlaySound_082406e0(SE_GUN_FIRE);
    pltt = 0x2C;
  }
  Entity080c0fa0_Create(&pos, pltt, 0, p->facing, 32, 0, param_2);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 2);
  p->fn_498 = FUN_08074350;
}

void FUN_0807c748(Player* p, DirS32 dir, s32 param_3, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  p->unk_4a7 = param_3;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 0);
  p->fn_498 = FUN_080744bc;
}

void FUN_0807c798(Player* p, s32 scriptID) {
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 5);
  p->fn_498 = FUN_080744bc;
}

// mode ごとに向きを決めて PACT_UNK_7 の行動に入れ, 操作不能状態にする, mode が 0..3 以外なら何もしない
void FUN_0807c7c8(Player* p, s32 mode) {
  if (mode == 0) {
    p->dir_4a9 = 1;
    Player_SetAnimFacing(p);
    p->animIDOffset--;
    p->state = 0;
  } else if (mode == 1) {
    p->dir_4a9 = 5;
    Player_SetAnimFacing(p);
    p->animIDOffset--;
    p->state = 0;
  } else if (mode == 2) {
    p->unk_4a7 = 0;
    p->state = 5;
  } else if (mode == 3) {
    p->dir_4a9 = 3;
    Player_SetAnimFacing(p);
    p->animIDOffset--;
    p->state = 0;
  } else {
    return;
  }
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_7, p->state);
  p->fn_498 = FUN_08074a40;
}

void FUN_0807c88c(Player* p, Vec3* pos, DirS32 dir, u32 scriptID) {
  p->unk_49c = *pos;
  p->scriptID_4b0 = scriptID;
  p->dir_4a9 = dir;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_DASH, 0);
  p->fn_498 = FUN_080746ec;
}

void FUN_0807c8d4(Player* p, DirS32 dir) {
  if (dir >= 0) {
    p->facing = dir;
  }
  Player_SetAnimFacing(p);
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(0.5));
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_DASH, 0);
  p->fn_498 = FUN_08074994;
}

void FUN_0807c928(Player* p, s32 val) {
  Player_EnterLockedState(p);
  p->facing = FACE_UP_RIGHT;
  p->animIDOffset = 0;
  p->xflip = 0;
  Player_SetAction(p, PACT_HEALING, 0);
  p->fn_498 = FUN_080749b0;
}

void FUN_0807c968(Player* p, s32 val) {
  Player_EnterLockedState(p);
  p->facing = FACE_UP_RIGHT;
  p->animIDOffset = 0;
  p->xflip = 0;
  Player_SetAction(p, PACT_HEALING, 2);
  p->fn_498 = FUN_080749b0;
}

void FUN_0807c9ac(Player* p, s32 xflip, u32 scriptID) {
  if (xflip != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = TRUE;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = FALSE;
  }
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 0);
  p->fn_498 = FUN_080728a8;
}

void FUN_0807ca24(Player* p, s32 xflip, u32 scriptID) {
  if (xflip != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = TRUE;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = FALSE;
  }
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 3);
  p->fn_498 = FUN_080728a8;
}

void FUN_0807ca9c(Player* p, s32 xflip, u32 scriptID) {
  if (xflip != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = TRUE;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = FALSE;
  }
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 4);
  p->fn_498 = FUN_080728a8;
}

void FUN_0807cb14(Player* p, s32 xflip, u32 scriptID) {
  if (xflip != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = TRUE;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = FALSE;
  }
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 2);
  p->fn_498 = FUN_080728a8;
}

void FUN_0807cb8c(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) {
    p->facing = dir;
  }
  p->facing |= 1;
  if (p->facing > FACE_DOWN) {
    p->animIDOffset = (8 - p->facing) >> 1;
    p->xflip = TRUE;
  } else {
    p->animIDOffset = p->facing >> 1;
    p->xflip = FALSE;
  }
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 0);
  p->fn_498 = FUN_080729e0;
}

void FUN_0807cc14(Player* p, s32 xflip) {
  if (xflip != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = TRUE;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = FALSE;
  }
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 0);
  p->fn_498 = FUN_08072a0c;
}

bool32 FUN_0807cc84(Player* p, u32 scriptID) {
  p->scriptID_4b0 = scriptID;
  if (p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) {
    return FALSE;
  }
  if (p->kind == PLAYER_BAT) {
    Player_EnterLockedState(p);
    Player_SetAction(p, PACT_CBAT, 0);
    p->fn_498 = Player_RevertBatToDarkDjango;
  } else if (p->kind == PLAYER_MOUSE) {
    Player_EnterLockedState(p);
    Player_SetAction(p, PACT_CMOUSE, 0);
    p->fn_498 = Player_RevertMouseToDarkDjango;
  } else if (p->kind == PLAYER_SLEEPING) {
    p->facing = FACE_DOWN;
    Player_SetAnimFacing(p);
    Player_EnterLockedState(p);
    Player_SetAction(p, PACT_SLEEPING, 0);
    p->fn_498 = Player_RevertSleepingToDarkDjango;
  } else {
    return FALSE;
  }
  return TRUE;
}

// 体にまとわりつく粒子 (emitter) を kind で1個出す, 広がりの乱数はフォームで変わり, 出せたら種類ごとの音を鳴らす (Player_StartFormEffect の後半と同じ)
// 残差は乱数の添字の組み方と定数 7 を置くレジスタ (153/154), 原典は gRandTableIdx を読んでその場で +1 / & 0x3FF し, 7 を r4 に作って x と y の両方で使い回す, Player_StartFormEffect と同じ書き方で同じ残差
// Tier A-C 試済 (_Random(table) を分岐ごと / 関数先頭, Random() 直書き, idx ローカル)
NON_MATCH void FUN_0807cd24(Player* p, u32 kind) {
#ifdef NONMATCHING_C
  u16* table;
  u32 idx;
  Vec3 spread;

  if (p->kind == PLAYER_BAT) {
    table = gRandomTable;
    idx = (gRandTableIdx + 1) & 0x3FF;
    spread.x = (table[idx] & 7) - 3;
    gRandTableIdx = (idx + 1) & 0x3FF;
    spread.y = (table[gRandTableIdx] & 7) - 5;
  } else if (p->kind == PLAYER_MOUSE) {
    table = gRandomTable;
    idx = (gRandTableIdx + 1) & 0x3FF;
    spread.x = (table[idx] & 7) - 3;
    gRandTableIdx = (idx + 1) & 0x3FF;
    spread.y = (table[gRandTableIdx] & 7) - 3;
  } else {
    table = gRandomTable;
    idx = (gRandTableIdx + 1) & 0x3FF;
    spread.x = (table[idx] & 0xF) - 7;
    gRandTableIdx = (idx + 1) & 0x3FF;
    spread.y = -(table[gRandTableIdx] & 0x1F);
  }
  spread.z = 0;
  if (FUN_082467d0(&p->emitter, kind, 3600, &spread) >= 0) {
    if (p->emitter.kind == 1) {
      PlaySound_082406e0(SE_IGNITE);
    } else if (p->emitter.kind == 2) {
      PlaySound_082406e0(SE_SOLIDIFY);
    } else if (p->emitter.kind == 3) {
      PlaySound_082406e0(SE_SOLIDIFY);
    }
  }
  p->badCondTimer[BAD_POISON] = 0;
#else
  INCFUNC("asm/func/FUN_0807cd24.inc");
#endif
}

void FUN_0807ceb8(Player* p) { FUN_08063220(p); }

NAKED void FUN_0807cec4(Player* p, s32 kind, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0807cec4.inc"); }

void Player_Unlock(Player* p) {
  if (p->action != PACT_PULL_COFFIN) {
    p->action = PACT_IDLE;
  }
  p->state = 0;
  p->stateTimer = 0;
  if (p->unk_4a8 != 0) {
    p->unk_4a8 = 0;
  }
  p->mode = PMODE_ACTIVE;
  p->originKnockback = FALSE;
}

// コマンドのヘルパーで、 '.d' で渡されたプレイヤーの向きを取得する
DirS32 Player_GetCmdArgDir(void) {
  if (VM_SeekToNamedArg('d')) {
    return VM_GetValue();
  }
  return -1;
}

// コマンドのヘルパーで, '.e' で渡されたスクリプトIDを取得する, 無ければ 0
u32 Player_GetCmdArgScript(void) { return VM_SeekToNamedArg('e') ? VM_GetValue() : 0; }

// 0xEFE6
void Cmd_EFE6(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807b8dc(p);
    FUN_08072640(p);
  }
}

// 0x8FA3
void Cmd_8FA3(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('p')) {
    FUN_0807b890(p, VM_GetValue() + 289);
    FUN_08072640(p);
  }
}

// 0xC12D
void Cmd_C12D(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('p')) {
    FUN_0807b8a8(p, VM_GetValue() + 289);
    FUN_08072640(p);
  }
}

// 0x6F85
void Cmd_6F85(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807b8c0(p);
    FUN_08072640(p);
  }
}

// 0x3613
void Cmd_LockPlayer(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_Lock(p, Player_GetCmdArgDir());
    FUN_08072640(p);
  }
}

// 0x9FFD
void Cmd_9FFD(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807b9dc(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x061E
void Cmd_061E(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807ba14(p, Player_GetCmdArgDir());
    FUN_08072640(p);
  }
}

// 0x6E7D
void Cmd_6E7D(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807ba50(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x933C
void Player_MoveTo(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('p')) {
    Vec3 pos;
    DirS32 dir;
    u32 scriptID;

    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    dir = Player_GetCmdArgDir();
    scriptID = Player_GetCmdArgScript();
    FUN_0807ba94(p, &pos, scriptID, dir);
    FUN_08072640(p);
  }
}

// 0xE990
void Cmd_E990(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('p')) {
    Vec3 pos;
    DirS32 dir;
    u32 scriptID;

    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    dir = Player_GetCmdArgDir();
    scriptID = Player_GetCmdArgScript();
    FUN_0807c88c(p, &pos, dir, scriptID);
    FUN_08072640(p);
  }
}

// 0x9763
void Cmd_9763(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 param_4 = VM_SeekToNamedArg('f') ? VM_GetValue() : 0;
    DirS32 dir = Player_GetCmdArgDir();
    u32 scriptID = Player_GetCmdArgScript();

    if (VM_SeekToNamedArg('p')) {
      Vec3 pos;
      VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
      FUN_0807bb3c(p, &pos, dir, param_4, scriptID);
    } else {
      FUN_0807bb3c(p, NULL, dir, param_4, scriptID);
    }
    FUN_08072640(p);
  }
}

// 0xBB01, エリアの初めからやり直す(暗黒ローンによる"やり直し", 愚者のカード(ITEM_THE_FOOL))
void Cmd_Retry(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    u32 scriptID = Player_GetCmdArgScript();

    if (p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) {
      FUN_0807bbb0(p, VM_SeekToNamedArg('f') ? VM_GetValue() : 0, scriptID);
      FUN_08072640(p);
    } else {
      p->scriptID_4b0 = scriptID;
      Player_Lock(p, 4);
      FUN_08072640(p);
      FUN_08072650(p);
    }
  }
}

// 0xB83E
void Cmd_B83E(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bc64(p, Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x7843
void Cmd_7843(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bcb0(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0xE4A3
void Cmd_E4A3(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bcfc(p, Player_GetCmdArgDir());
    FUN_08072640(p);
  }
}

// 0x409D
void Cmd_409D(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bd44(p, Player_GetCmdArgDir());
    FUN_08072640(p);
  }
}

// 0x40D7
void Cmd_40D7(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bd84(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x58D7
void Cmd_58D7(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    DirS32 dir = Player_GetCmdArgDir();
    u32 b = Player_GetCmdArgScript();

    FUN_0807bdc8(p, dir, VM_SeekToNamedArg('f') ? VM_GetValue() : 0, b);
  }
}

// 0x3705
void Cmd_3705(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    DirS32 dir = Player_GetCmdArgDir();
    u32 b = Player_GetCmdArgScript();

    FUN_0807be58(p, dir, VM_SeekToNamedArg('h') ? VM_GetValue() : 1500, b);
    FUN_08072640(p);
  }
}

// 0x7A25
void Cmd_7A25(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('f') ? VM_GetValue() : 30;

    FUN_0807bee0(p, Player_GetCmdArgDir(), n, Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x172D
void Cmd_172D(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 param_3 = VM_SeekToNamedArg('f') ? VM_GetValue() : 50;
    s32 param_4 = VM_SeekToNamedArg('L') ? VM_GetValue() : 0;
    DirS32 dir = Player_GetCmdArgDir();
    u32 scriptID = Player_GetCmdArgScript();

    FUN_0807bfa4(p, dir, param_3, param_4, scriptID);
    FUN_08072640(p);
  }
}

// 0x4127
void Cmd_4127(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c048(p, Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x1343
void Cmd_1343(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('f') ? VM_GetValue() : 50;

    FUN_0807c084(p, Player_GetCmdArgDir(), n, Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x2593
void Cmd_2593(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c11c(p, Player_GetCmdArgDir());
    FUN_08072640(p);
  }
}

// 0xA2E1, 転移の葉(ITEM_WARP_LEAF) を使用時に呼ばれた
void Cmd_Riremito(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c200(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0xEA96
void Cmd_EA96(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c36c(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0xCAFE
void Cmd_CAFE(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c458(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0xAF43
void Cmd_AF43(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c49c(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0xDDEE
void Cmd_DDEE(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c4e0(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0xC233
void Cmd_C233(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c524(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0xB683
void Cmd_B683(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c568(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x9AC8
void Cmd_9AC8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c5ac(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0xD40E
void Cmd_D40E(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c5f0(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x1F3B
void Cmd_1F3B(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('l') ? VM_GetValue() : 32;

    FUN_0807c634(p, n, Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x490F
void Cmd_490F(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    bool32 done = FUN_0807cc84(p, Player_GetCmdArgScript());

    FUN_08072640(p);
    if (!done) {
      FUN_08072650(p);
    }
  }
}

// 0xF982
void Cmd_F982(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('r') ? VM_GetValue() : 0;

    FUN_0807c9ac(p, n, Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x05E2
void Cmd_05E2(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('r') ? VM_GetValue() : 0;

    FUN_0807ca24(p, n, Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x546C
void Cmd_546C(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('r') ? VM_GetValue() : 0;

    FUN_0807ca9c(p, n, Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x75B9
void Cmd_75B9(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('r') ? VM_GetValue() : 0;

    FUN_0807cb14(p, n, Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x3C3E
void Cmd_3C3E(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('d') ? VM_GetValue() : 0;

    FUN_0807cb8c(p, n, Player_GetCmdArgScript());
    FUN_08072640(p);
  }
}

// 0x827A
void Cmd_827A(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807cc14(p, VM_SeekToNamedArg('r') ? VM_GetValue() : 0);
    FUN_08072640(p);
  }
}

// 0x4CDD
void Cmd_4CDD(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('m')) {
    s32 m = VM_GetValue();
    s32 c;
    s32 a;

    if (m == 4 || m == 5) {
      c = VM_SeekToNamedArg('c') ? VM_GetValue() : 120;
      a = VM_SeekToNamedArg('A') ? VM_GetValue() : 120;
    } else {
      c = a = 0;
    }
    FUN_0807cec4(p, m, c, a);
  }
}

// 0x4C4D
void Cmd_UnlockPlayer(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    Player_Unlock(gPlayerPtr[i]);
  }
}

// 0x30CC
void Cmd_30CC(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    if (VM_SeekToNamedArg('t')) {
      p->countdown = VM_GetValue();
    } else {
      p->countdown = 600;
    }
    HUD_StartCountdown(&p->countdown);
    if (VM_SeekToNamedArg('c')) {
      p->unk_438 = VM_GetValue();
    } else {
      p->unk_438 = 720;
    }
    p->unk_436 = 0;
    p->scriptID_4b0 = Player_GetCmdArgScript();
    p->facing = FACE_DOWN;
    Player_SetAnimFacing(p);
    Player_EnterLockedState(p);
    Player_SetAction(p, PACT_UNK_7, 0);
    if (p->kind == PLAYER_SABATA) {
      p->fn_498 = FUN_08078060;
    } else {
      p->fn_498 = FUN_08077cbc;
    }
  }
}

void Player_RegisterMsgQueue(Player* p) { MsgQueue_Register(&p->mq, p->mover.id, CLS_PLAYER); }

void Player_UnregisterMsgQueue(Player* p) { MsgQueue_Unregister(&p->mq); }

NAKED void Player_Update_Helper_0807dde4(Player* p) { INCFUNC("asm/func/Player_Update_Helper_0807dde4.inc"); }

// 自分宛ての targetClass 2 のメッセージを1件組み立てて送る
void FUN_0807e278(Player* p, s32 cmd, s32 argc, s16* args) {
  MsgPacket* msg = &p->msg_994;

  msg->targetID = p->mover.id;
  msg->targetClass = 2;
  msg->waitFlag = FALSE;
  msg->unk_4 = 0;
  msg->cmd = cmd;
  msg->argc = argc;
  if (args != NULL) {
    s32 i;

    for (i = 0; i < argc; i++) {
      msg->args[i] = args[i];
    }
  }
  MsgPacket_Send(msg);
}

// スパイクメイル(攻撃を受けると、周囲の敵にダメージを与える) の攻撃判定 を作る
void Django_Spike(Player* p) {
  HitboxData* hitbox = &p->hitbox_2ec;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 120, 120, 120);
  VEC3_SET(offset, 0, 120, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 1 << p->mover.unk_4, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, 10, 40, 0, HBATTR_18, 10);
  Hitbox_SetHandler(hitbox, NULL, p);
  Hitbox_SetPos(hitbox, &p->mover.pos, 0);
  p->hitboxTimer = 6;
  p->hitbox_2ec.angle = ((p->facing + 1) & 7) << 5;
}

// hitboxTimer が残っている間 hitbox_2ec を当たり判定に出し続ける
void FUN_0807e388(Player* p) {
  if (p->hitboxTimer != 0) {
    Hitbox_Register(&p->hitbox_2ec);
    p->hitboxTimer--;
  }
}

// 被弾1回分を処理する, ダメージ・状態異常・ノックバックを反映し、p->damage に足した量を返す
// 残差9か所, a->power > 0 が原典は ldrh + ble (agbcc は beq に畳む, (s16) だと ldrsh になる) と HasGoodCond 周りのレジスタ割り当て
// 効いたもの: shift の三項演算子, GAMAN を if/else で1つの return に, attributes は Hitbox_TestAttr, goodCond 判定は static inline, Tier A-B は試済, 未: Tier C
NON_MATCH u32 Player_TakeHit(Player* p, HitboxData* a, HitboxData* b) {
#ifdef NONMATCHING_C
  s32 shift;
  u32 dmg;
  bool32 valid;

  if (p->kind == PLAYER_SLEEPING) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
  }
  if (a->power > 0) {
    Hitbox_ApplyDamage(a, b);
  } else {
    b->damage = 0;
  }
  b->invincibleTime = a->invincibleTime;

  shift = Player_TestEquipBuff(p, EBUFF_GUTSPOWER) ? -1 : 0;

  if (a->knockbackPower == 0) {
    p->hurtSound = SONG_NONE;
  } else {
    p->hurtSound = SE_DAMAGE;
    if ((p->kind == PLAYER_BAT && p->action == PACT_CBAT) || (p->kind == PLAYER_MOUSE && p->action == PACT_CMOUSE)) {
      p->formRequest = TRUE;
      p->formRequestKind = PLAYER_DARK_DJANGO;
    }
    if (p->unk_3ff >= 0) {
      FUN_080dab9c(p->unk_3ff);
    }
    valid = HasGoodCond(p, GOOD_INVISIBLE);
    if (valid) {
      p->goodCondID = 0;
      p->goodCondTimer = 0;
      p->beast.flags &= ~SPRFLAG_BLINK_EVEN;
    }
    if (p->unk_3ea == 0 && p->unk_3ec != 0) {
      p->unk_3ec = 0;
    }
    if (p->action == PACT_UNK_19 && !Hitbox_TestAttr(a, HBATTR_14)) {
      FUN_08063220(p);
      shift++;
    }
    Player_SetupKnockback(p, a, b);
    if (p->kind == PLAYER_DARK_DJANGO) {
      p->unk_448[1] = 1;
    }
  }

  valid = HasGoodCond(p, GOOD_GAMAN);
  if (valid) {
    b->damage = 0;
    dmg = 0;
    if (Hitbox_TestAttr(a, HBATTR_18)) {
      FUN_08063220(p);
    }
  } else {
    valid = HasGoodCond(p, GOOD_MINI);
    if (valid || p->action == PACT_DASH || p->kind == PLAYER_BAT || p->kind == PLAYER_MOUSE) {
      shift++;
    }

    if (Hitbox_TestAttr(a, HBATTR_INKA)) {
      if (!(b->hitResult & HBRESULT_RESIST)) {
        if (p->blownAway == 0) {
          p->hurtSound = SE_IGNITE;
        }
        Player_StartFormEffect(p, 1);
      }
    } else if (Hitbox_TestAttr(a, HBATTR_HYOKETU)) {
      if (!(b->hitResult & HBRESULT_RESIST)) {
        if (p->blownAway == 0) {
          p->hurtSound = SE_SOLIDIFY;
        }
        Player_StartFormEffect(p, 2);
      }
    } else if (Hitbox_TestAttr(a, HBATTR_14)) {
      p->hurtSound = SE_SOLIDIFY;
      Player_StartFormEffect(p, 3);
      p->blownAway = 0;
    } else if (Hitbox_TestAttr(a, HBATTR_18)) {
      FUN_08063220(p);
    }

    if (Hitbox_TestAttr(a, HBATTR_POISON) && !Player_TestEquipBuff(p, EBUFF_IMMUNEPOISON)) {
      Player_ApplyBadCondition(p, BAD_POISON, SECOND(30));
    }
    if (Hitbox_TestAttr(a, HBATTR_CONFUSE)) {
      Player_ApplyBadCondition(p, BAD_CONFUSE, SECOND(15));
    }
    if (Hitbox_TestAttr(a, HBATTR_17)) {
      Vec3 v;
      u32 angle = ((p->facing + 5) & 7) * 32;

      v.x = POLAR_X(Q8(0.313), angle), v.y = Q8(0.782), v.z = POLAR_Z(Q8(0.313), angle);
      FUN_080dc0b8(&p->mover.pos, &v, 0, 0, 1);
    }

    if (shift >= 0) {
      dmg = b->damage << shift;
    } else {
      dmg = b->damage >> -shift;
      if (b->damage != 0 && dmg == 0) {
        dmg = 1;
      }
    }
    b->damage = 0;
    p->damage += dmg;
  }
  return dmg;
#else
  INCFUNC("asm/func/Player_TakeHit.inc");
#endif
}

void Django_OnHurt(HitboxData* a, HitboxData* b, Player* p) {
  if (p->mode == PMODE_ACTIVE) {
    if (Hitbox_TestFlags(a, HBFLAG_UNK_9)) {
      if ((b->hitState & HBHITSTATE_UNK_0) == 0) {
        return;
      }
      b->hitState &= ~HBHITSTATE_UNK_0;
    }
    if (Hitbox_TestFlags(a, HBFLAG_UNK_10)) {
      if (b->hitState & HBHITSTATE_UNK_1) {
        return;
      }
      b->hitState |= HBHITSTATE_UNK_1;
    }
    Player_TakeHit(p, a, b);
    if (TEST_FLAGS(p->equipBuffs, EBUFF_SPIKE)) {
      Django_Spike(p);
    }
  }
}

// プレイヤーにダメージを与える関数 (内部的には即席の Hitbox を用意して自分の食らい判定にぶつける)
s32 Player_TakeInstantHit(Player* p, s32 power, s32 knockbackPower, s32 angle, s32 invincibleTime, HitboxAttributes attrs) {
  if (p->mode == PMODE_ACTIVE) {
    HitboxData* hurtbox = &p->hurtbox;
    s32 iframes = hurtbox->invincibleTime;

    if (iframes <= 0) {
      HitboxData hb;
      hb.flags = HBFLAG_HITBOX;
      hb.power = power;
      hb.knockbackPower = knockbackPower;
      hb.angle = angle;
      hb.attributes = attrs;
      hb.invincibleTime = invincibleTime;
      return Player_TakeHit(p, &hb, hurtbox);
    }
  }
  return 0;
}

// HP が尽きたときに死亡状態 (PMODE_DEAD) に移す, 変身を解き, よい / 悪い状態効果や太陽ゲージの上書きをすべて消す
void Player_EnterDeadState(Player* p) {
  s32 i;

  if (p->kind >= PLAYER_BAT && p->kind <= PLAYER_SLEEPING) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
  }
  p->facing |= 1;
  PLAYER_SET_ANIM_DIR_HALF(p, p->facing);
  p->mode = PMODE_DEAD;
  p->state = 0;
  p->stateTimer = 0;
  p->hurtbox.invincibleTime = 0;
  p->magic.enchanted = FALSE;
  gSunMagicUsed = 0;
  gSunGaugeOverride = 0;
  gSunGaugeOverrideTimer = 0;
  FUN_08063220(p);
  p->goodCondID = 0;
  p->goodFrom = 0;
  p->goodCondTimer = 0;
  for (i = 0; i < 3; i++) {
    p->badCondTimer[i] = 0;
  }
  Player_StopEneChargeSound(p);
  if (p->lookAroundOffset.val != 0) {
    Player_EndLookAround(p);
  }
}

// 残差9命令 (341/350), 3箇所 (MPF_UNK_13 / MPF_DESERT / EBUFF_BLACKARMOR) で原典はマスクをレジスタに作ってから AND し, 真偽値を 0/1 に materialize してから cmp する
// FUN_0806241c と同じ壁で, マスクを引数に取る static inline にするとマスクはレジスタに乗るが 0/1 の materialize は agbcc が畳む
// 他は PFLAG20_UNK_9 の |= のマスク順と unk_3da のカウンタ順の1命令
// 3箇所の判定を bool8 を返す static inline (TestMapFlag と equipBuffs 用) にすると 0/1 の作り置きは出るが, 他の場所で 356/350 に広がる
NON_MATCH bool32 Player_UpdateDamage(Player* p) {
#ifdef NONMATCHING_C
  CollisionMapTile* tile = Player_GetTileAt(&p->mover.pos);

  if ((tile->attr & TATTR_UNK_6) && p->unk_390 == 0) {
    if (gStat->mapFlags & MPF_UNK_13) {
      Player_SetAction(p, PACT_FALLDEATH, 0);
    } else {
      Player_SetAction(p, PACT_UNK_28, 0);
    }
    return TRUE;
  }

  if (gStat->heatstroke >= 5000) {
    Player_SetAction(p, PACT_UNK_30, 0);
    return TRUE;
  }

  if (p->originHitPending) {
    p->damage += FUN_08065cb8(p);
  } else if (p->tileHitPending) {
    p->damage += FUN_08065e24(p);
  }

  if (p->hurtbox.invincibleTime == 0) {
    if (p->badCondTimer[1] != 0) {
      p->poisonTick++;
      if (p->poisonTick >= SECOND(1)) {
        p->damage++;
        p->poisonTick = 0;
      }
    }
    if (p->emitter.kind == 1 && p->emitter.unk_3 != 0) {
      u16 t;

      p->flag20 |= PFLAG20_UNK_9;
      p->unk_3da++;
      t = p->unk_3da;
      if (t >= Div(60, p->emitter.unk_3)) {
        p->damage += 10;
        p->unk_3da = 0;
      }
    }
    if (gStat->mapFlags & MPF_DESERT) {
      p->desertTimer++;
      if (p->desertTimer >= SECOND(2)) {
        p->damage++;
        p->desertTimer = 0;
      }
    } else {
      p->desertTimer = SECOND(2);
    }
    if (p->equipBuffs & EBUFF_BLACKARMOR) {
      p->blackArmorTimer++;
      if (p->blackArmorTimer > 14) {
        p->damage++;
        p->blackArmorTimer = 0;
      }
    }
  }

  if (p->damage != 0) {
    u16 state = p->goodCondTimer;
    bool32 skip = state != 0 && p->goodCondID == GOOD_GAMAN;

    if (!skip) {
      CreateDamageNumber(&p->hurtbox, p->damage, 0, &p->mover.pos, &p->pos_970, 0);
      if (p->hp < p->damage) {
        p->hp = 0;
      } else {
        p->hp -= p->damage;
      }
    }
  }

  p->damage = 0;
  p->pos_970.x = 0, p->pos_970.y = 0, p->pos_970.z = 0;

  if (p->action == PACT_GRABBED || p->hp != 0) {
    return FALSE;
  }
  if (gGameFlags & FLAG030047A4_UNK_12) {
    return TRUE;
  }
  if (!CheckItemOwn(ITEM_JUDGEMENT)) {
    return TRUE;
  }

  p->hurtSound = SONG_NONE;
  if (p->hurtbox.knockbackPower == 0) {
    p->facing |= 1;
    p->hurtbox.knockbackPower = 1;
  }
  RemoveSpecifiedItem(ITEM_JUDGEMENT);
  Judgement_Create(p);
  return FALSE;
#else
  INCFUNC("asm/func/Player_UpdateDamage.inc");
#endif
}

// 残差なし・レジスタ割当のみ不一致 (p と n の r4/r5 が入れ替わる)
NON_MATCH void FUN_0807eca8(Player* p) {
#ifdef NONMATCHING_C
  s32 n = p->hurtbox.invincibleTime;

  if (n > 0) {
    Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
    if (p->hurtbox.knockbackPower == 0 && p->action != PACT_DAMAGED && p->action != PACT_BLOWN_AWAY) {
      n--;
      if (n != 0 && ((n >> 2) & 1)) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      }
      p->hurtbox.invincibleTime = n;
    }
  }
#else
  INCFUNC("asm/func/FUN_0807eca8.inc");
#endif
}

// プレイヤーの位置・向き・HP/ENE・状態異常などを gStat と退避用のグローバルに書き出す
// 残差14命令 (124/138), 原典は gStat への store ごとに gStat を読み直し, sunAngle も書いた直後に読み直す (2回目は ldrsh)
// agbcc-levers.md の A cached global pointer と同じ壁 (FUN_0807a91c), sunAngle の s16 化は効果なし, 未: Tier D
NON_MATCH void Player_SaveState(Player* p) {
#ifdef NONMATCHING_C
  s32 i;

  gStat->playerX = p->mover.pos.x;
  gStat->playerY = p->mover.pos.y;
  gStat->playerZ = p->mover.pos.z;
  gStat->playerFacing = p->facing;
  gStat->sunAngle = ((p->facing + 5) & 7) << 5;
  p->mover.angle = gStat->sunAngle;
  p->hurtbox.angle = gStat->sunAngle;
  gStat->playerKind = p->kind;
  gStat->playerAction = p->action;
  if (p->kind == PLAYER_SABATA) {
    gStat->sabataHP = p->hp;
    gStat->sabataEne = p->ene;
  } else {
    gStat->savedHP = p->hp;
    gStat->savedEne = p->ene;
  }
  gStat->savedMaxHP = p->maxHP;
  gStat->savedMaxEne = p->maxEne;
  gGoodCondID = p->goodCondID;
  gGoodFrom = p->goodFrom;
  gGoodCondTimer = p->goodCondTimer;
  for (i = 0; i < 3; i++) {
    gBadCondTimer[i] = p->badCondTimer[i];
  }
  gPlayerStates[p->mover.unk_4] = p->mode;
  gSavedMagicEnchanted = p->magic.enchanted;
#else
  INCFUNC("asm/func/Player_SaveState.inc");
#endif
}

// 変身の要求 (formRequest) を実際のフォーム切り替えに反映する, 使うスプライトと更新関数とパレットを差し替える
void Player_ApplyFormRequest(Player* p) {
  if (!p->formRequest) {
    return;
  }

  if (p->formRequestKind == PLAYER_BAT) {
    p->kind = PLAYER_BAT;
    p->updateCallback = Player_UpdateBat;
    p->useAuxSprite = 1;
    p->mover.mainSprite = NULL, p->mover.auxSprite = &p->beast;
    p->emitter.pos = &p->beast.pos;
    Player_SetPlttIDs(p);
    p->unk_94c = 0xFFFF;
    p->beastGfx->plttID = p->plttID_94a;
    p->plttID_95e = 621;
    p->plttFlashTimer = 32;
  } else if (p->formRequestKind == PLAYER_MOUSE) {
    p->kind = PLAYER_MOUSE;
    p->updateCallback = Player_UpdateMouse;
    p->useAuxSprite = 1;
    p->mover.mainSprite = NULL, p->mover.auxSprite = &p->beast;
    p->emitter.pos = &p->beast.pos;
    Player_SetPlttIDs(p);
    p->unk_94c = 0xFFFF;
    p->beastGfx->plttID = p->plttID_94a;
    p->plttID_95e = 290;
    p->plttFlashTimer = 32;

  } else if (p->formRequestKind == PLAYER_SLEEPING) {
    p->kind = PLAYER_SLEEPING;
    p->updateCallback = Player_UpdateSleeping;
    p->useAuxSprite = 1;
    p->mover.mainSprite = NULL, p->mover.auxSprite = &p->beast;
    p->emitter.pos = &p->beast.pos;
    Player_SetPlttIDs(p);
    p->unk_94c = 0xFFFF;
    p->beastGfx->plttID = p->plttID_94a;
    p->unk_388 = 0;
    p->unk_38a = 0;
    p->facing = FACE_UP;
    p->animIDOffset = 0;
    p->xflip = 0;

  } else {
    s32 enchant;
    if (p->kind != PLAYER_SLEEPING) {
      p->plttID_95e = 290;
      p->plttFlashTimer = 32;
    }
    p->kind = PLAYER_DARK_DJANGO;
    p->updateCallback = Player_UpdateDjango;
    p->useAuxSprite = 0;
    p->mover.mainSprite = &p->human, p->mover.auxSprite = NULL;
    p->emitter.pos = &p->human.pos;
    Player_SetPlttIDs(p);
    p->unk_94c = 0xFFFF;

    enchant = Player_CheckMagicEnchant(p) + 1;
    p->unk_951 = enchant;
    p->unk_950 = enchant + 1;
  }

  p->human.plttID = p->plttID_94a;
  p->magic.availableForm = Player_IsMagicAvailableForm(p, p->magic.id);
  p->formRequest = FALSE;
}

// ボタンを押している間, プレイスタイルの集計カウンタを進める (どれも 0x7FFFFFFF で止まる)
// 残差はレジスタ番号 r1/r2 の入れ替えのみ (命令列は55命令で完全一致), Tier A-C は試済
// ポインタのローカルを3箇所で使い回す形までは追い込めたが, 先頭の定数 0x358 が原典では r1, こちらでは r2 に入る
NON_MATCH void Player_CountStyleFrames(Player* p) {
#ifdef NONMATCHING_C
  s32* frames;

  if (p->input->down == 0) {
    return;
  }

  if (IsMagicUnlocked(MAGIC_TRANSFORM)) {
    if (p->kind == PLAYER_SOLAR_DJANGO) {
      frames = &gStat->solarFormFrames;
      if (*frames <= 0x7FFFFFFE) {
        (*frames)++;
      }
    } else if (p->kind != PLAYER_SABATA) {
      frames = &gStat->darkFormFrames;
      if (*frames <= 0x7FFFFFFE) {
        (*frames)++;
      }
    }
  }

  frames = &gStat->weaponFrames[p->wpn.weaponKind];
  if (*frames <= 0x7FFFFFFE) {
    (*frames)++;
  }
#else
  INCFUNC("asm/func/Player_CountStyleFrames.inc");
#endif
}

// 暗黒ジャンゴの攻撃回数がしきい値に届いていればバーサークの準備をし, 準備ができていて素立ちか歩きならバーサークに入る
// 残差は乱数表の基点を入れるレジスタ1つ (84/84), 原典は r2 だがこちらは r1
// Tier A-C は試済 (Random / _Random / 添字直書き, 加算順, 比較の書き方, Mod の結果の受け方)
NON_MATCH void DarkDjango_UpdateBerserk(Player* p) {
#ifdef NONMATCHING_C
  if (p->kind == PLAYER_DARK_DJANGO) {
    if (gStat->darkDjangoAtkCounter >= gStat->unk_2ac) {
      if (p->unk_448[2]) {
        if (p->action <= PACT_WALK) {
          gStat->darkDjangoAtkCounter = 0;
          gStat->unk_2ac = Mod(Random(), 100) + 200;
          p->unk_448[2] = 0;
          FUN_08060e90(p, 2);
          DjangoBerserk_Create(p);
        }
      } else if (p->unk_448[1]) {
        p->unk_448[2] = 1;
        p->unk_448[1] = 0;
      }
    } else {
      p->unk_448[1] = 0;
    }
  } else {
    p->unk_448[2] = 0;
    p->unk_448[1] = 0;
  }
#else
  INCFUNC("asm/func/DarkDjango_UpdateBerserk.inc");
#endif
}

// unk_1c の状態ごとに更新を振り分け, 共通の後処理と範囲イベントの拾い上げまでを毎フレーム回す
static s32 Player_Update(Player* p) {
  Player_Update_Helper_0807dde4(p);
  Player_BeginAction(p);

  if (p->mode == PMODE_ACTIVE) {
    Player_CountStyleFrames(p);
    Player_UpdateWeaponWear(p);
    FUN_0807e388(p);

    if (gSunGaugeOverride != 0) {
      if (gSunGaugeOverrideTimer != 0) {
        gSunGaugeOverrideTimer--;
      } else {
        gSunGaugeOverride = 0;
      }
    }

    if (Player_UpdateDamage(p)) {
      Player_EnterDeadState(p);
    } else {
      FUN_0807eca8(p);
      DarkDjango_UpdateBerserk(p);
    }
  } else if (p->mode == PMODE_LOCKED) {
    s32 n;

    Player_ClearInputHistory(p);
    if (p->hp == 0) {
      p->hp = 1;
    }
    p->damage = 0;
    p->hurtbox.knockbackPower = 0;
    n = p->hurtbox.invincibleTime;
    if (n > 0) {
      p->hurtbox.invincibleTime = 0;
    }
  }

  Player_ApplyFormRequest(p);
  if (p->enchantStarted) {
    PlaySound_082406e0(SE_ENCHANT);
    p->enchantStarted = FALSE;
  }

  p->updateCallback(p);
  Player_UpdatePoseAndShadow(p);
  FUN_080612a8(p);
  p->unk_3ea = 0;
  if (p->mover.unk_4 == 0) {
    Player_SaveState(p);
  }

  if (p->mode != PMODE_DEAD) {
    p->zoneEvents.pos = &p->mover.pos;
    FUN_08234660(&p->zoneEvents);
  }
  return 0;
}

static s32 Player_Destroy(Player* p) {
  EnemyTargetManager_Remove(&p->target);
  MainSprite_Remove(&p->human);
  AuxSprite_Remove(&p->beast);
  Hitbox_Unregister(&p->hurtbox);
  Mover_Unlink(&p->mover);
  Player_DestroyEffects(p);
  Player_UnregisterMsgQueue(p);
  Player_StopEneChargeSound(p);
  gCWolfTarget = NULL;
  gChangeWolfBiting = 0;
  gPlayerPtr[p->mover.unk_4] = NULL;
  gPlayerCount--;
  return 0;
}

static s32 Player_Init(Player* p, u32 n, void* _) {
  FUN_08065200(p);
  Player_InitState(p);
  FUN_08065744(p, n);
  Player_SetupHurtbox(p);
  Player_RefreshMagicInfo(p);
  Player_InitWeapon(p);
  Player_InitArmor(p);
  CheckHeartJokerEmblem(p);
  FUN_08061294(p);
  Player_InitEffects(p);
  Player_RegisterMsgQueue(p);
  FUN_08065240(p);
  gPlayerPtr[(p->mover).unk_4] = p;
  gPlayerCount++;
  if ((p->mover).unk_4 == 0) {
    Player_SaveState(p);
    FUN_0809c464();
  }
  return 0;
}

// 0xF5EB, HashName("プレイヤー"), エリア移動などでも毎回作り直す
Player* CreatePlayer(u32 n, void* _) {
  Player* p = CreateEntity(ENTITY_PLAYER, sizeof(Player));

  if (p != NULL) {
    SetEntityRoutine(p, Player_Update, Player_Destroy);
    if (Player_Init(p, n, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
