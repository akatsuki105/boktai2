#include "player.h"

#include "armor.h"
#include "camera.h"
#include "coffin.h"
#include "cwolf_target.h"
#include "dust.h"
#include "eff_elemcond.h"
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

// Player.doneNotify
typedef enum {
  PDONE_NONE = 0,        // 何もしない, Player_EnterLockedState が入れる
  PDONE_RUN_SCRIPT = 1,  // doneScriptID を実行する
  PDONE_END_WAIT = 2     // doneWaitPending ならメッセージの待ちを解く
} PlayerDoneNotify;

struct DynamiteEffect* DynamiteEffect_Create(Player* owner, Vec3* pos, s32 mode);
struct TransEffect* TransEffect_Create(Player* player, u32 param_2, Vec3* pos, u32 param_4, u32 param_5);
struct RisingSunEffect* RisingSunEffect_Create(void* owner, WorldPos* pos1, WorldPos* pos2, u32 param_4, u32 param_5);
struct FreezeEffect* FreezeEffect_Create(Vec3* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5);
struct HealingEffect* HealingEffect_Create(Player* player, Vec3* pos);
void Entity080acd4c_Spawn(Vec3* pos);
void CrossoverBattle_NotifyPlayerDead(void);
s32 FUN_08020358(u32 id);
bool32 IsInPuddle(WorldPos* pos);
void* Entity080c1abc_Create(u32 param_1, u32 param_2, u32 param_3);
struct Bullet* Bullet_Create(Player* player, u32 heightOffset, u32 unk_be, u32 unk_c0, u32 offsetRadius, u32 plttID, u32 knockback, HitboxAttributes attrs, u32 iframes, u32 pose, u32 cost, bool32 elefan);
void Player_UpdateLockedIdle(Player* p);
void FUN_080d040c(Player* p);
void Django_OnHurt(HitboxData* a, HitboxData* b, Player* p);
void Player_LockFall(Player* p, Dir8S32 dir, s32 param_3, u32 scriptID);
bool32 FUN_0809df78(Vec3* pos);
s32 SpawnBlood(Vec3* pos, Vec3* param_2, u32 param_3, u32 param_4, u32 param_5);
void FUN_080dab9c(s32 idx);
bool32 FUN_0809e138(Player* p);
void Django_OnWeaponHit(HitboxData* a, HitboxData* b, Player* _);
void* BloodEmitter_Create(void);
struct Judgement* Judgement_Create(Player* p);
struct DjangoBerserk* DjangoBerserk_Create(Player* player);
s32 MosaicFader_Start(s32 mode, s32 objEnabled, s32 targets, u8* from, u8* to, u16* interval);
void BuildWeaponData(Weapon* w, WeaponData* data);
s32 CalcAttackWithEquippedArmor(WeaponData* w);
void Player_UpdateMegaBusterAttack(Player* p);
void Player_UpdateCrossoverDjango(Player* p);
void Camera_LookAt(Vec3* pos);
bool8 MapItemManager_TryOpen(Mover* mover);
Vec3* Elevator_GetPosByID(s32 id);
struct Elevator* Elevator_FindAtPos(Vec3* pos);
void FUN_080417dc(Mover* mover);
s32 MovableBlock_PushAtDir8(Vec3* pos, u32 dir);
s32 FUN_08086958(void);
void FUN_08086590(Vec3* pos, s32 val);
s32 FUN_08016110(u32 val1, u32 val2, u32 val3, u32 val4, Vec3* pos);
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
COMMON_DATA u16 gBadCondTimer[3] = {};                  // 0x03002BA0, Player がいないときに Cmd_ApplyBadCond が書き込む退避先
COMMON_DATA u8 u8_03002ba6[2] = {};                     // todo
COMMON_DATA CWolfTargetNode* gCWolfTarget = NULL;       // 0x03002BA8, チェンジウルフで噛みつく相手のノード, Player_Destroy が NULL に戻す
COMMON_DATA u16 gWindStrength = 0;                      // 0x03002BAC, Player_InitEffects が 0 に戻す
COMMON_DATA u8 u8_03002bae[2] = {};                     // todo
COMMON_DATA u16 gSavedMagicEnchanted = 0;               // 0x03002BB0, Player.magic.enchanted の退避, Player_SaveState が写し Player_RefreshMagicInfo が戻す, Player_GetEquippedMagic がサバタのとき 0 に戻す
COMMON_DATA u8 u8_03002bb2[14] = {};                    // todo
COMMON_DATA PlayerMode gPlayerModes[4] = {};            // 0x03002BC0, Playerごとの Player.mode の写し
COMMON_DATA u16 gSunMagicUsed = 0;                      // 0x03002BD0, Cmd_898D が 0 に戻す
COMMON_DATA u8 u8_03002bd2[14] = {};                    // todo
COMMON_DATA Player* gPlayerPtr[4] = {};                 // 0x03002BE0, 通信対戦時に自分が子機の場合も自キャラが 0 になるかは不明
COMMON_DATA u16 gRisingSunCount = 0;                    // 0x03002BF0, 0 以外かつ gSunGaugeOverride が 1 のとき Entity0809eb24_Update が unk_29 を立てる
COMMON_DATA u8 u8_03002bf2[2] = {};                     // todo
COMMON_DATA u16 gChangeWolfBiting = 0;                  // 0x03002BF4, Player_Destroy が 0 に戻す
COMMON_DATA u8 u8_03002bf6[2] = {};                     // todo

static magic32_t Player_CheckMagicEnchant(Player* p);
static void Player_SetAction(Player* p, u32 action, u32 state);

// 5bit ずつの r / g / b から色を作る, 値は RGB と同じだが b << 10 から順に組み立てる
static inline rgb555 MakeRgb555(s32 r, s32 g, s32 b) { return (b << 10) | (g << 5) | r; }

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

static inline Player* GetPlayer(s32 idx) { return gPlayerPtr[idx]; }

static inline bool32 HasGoodCond(Player* p, u32 id) {
  if (p->goodCondTimer != 0 && p->goodCondID == id) {
    return TRUE;
  }
  return FALSE;
}

// 食らい判定の無敵時間を設定する
static inline void Player_SetIframes(Player* p, u16 time) { p->hurtbox.iframes = time; }

// 食らい判定の残りの無敵時間を返す
static inline s32 Player_GetIframes(Player* p) { return p->hurtbox.iframes; }

// 今の行動 (PACT_*) を返す
static inline s32 Player_GetAction(Player* p) { return p->action; }

// 当たり判定の向きを入れる
static inline void Hitbox_SetAngle(HitboxData* p, s32 angle) { p->angle = angle; }

// gMsgBus をこの inline 越しに読むと, メッセージ取り出しのループで原典どおり毎回プールから読み直す形になる
static inline MsgBus* GetMsgBus(void) { return gMsgBus; }

void Player_SetAnimFacing(Player* p) {
  u8 dir8 = p->facing;

  if (IS_8DIR_LEFT(dir8)) {
    p->animDir = 8 - dir8;
    p->xflip = TRUE;
  } else {
    p->animDir = dir8;
    p->xflip = FALSE;
  }
}

// animIdx のアニメを向きのオフセット込みで流し, 同じアニメなら続きから再生する, 1コマ進めて一巡したら TRUE
bool32 Player_PlayAnim(Player* p, u32 animIdx, s32 animSpeed) {
  MainAnimPlayFlags16 flags = 0;

  if (p->animID == animIdx) {
    flags = MAIN_ANIM_KEEP_FRAME;
  }
  p->animID = animIdx;

  MainSprite_SetAnim(&p->human, &p->humanGfx, p->animID + p->animDir, PLAYMODE_LOOP, flags);
  if (p->xflip) {
    p->human.flags |= SPRFLAG_XFLIP;
  } else {
    p->human.flags &= ~SPRFLAG_XFLIP;
  }

  MainSprite_SetAnimSpeed(&p->human, (u16)animSpeed);
  return MainSprite_AdvanceAnim(&p->human, &p->humanGfx);
}

// 向きと速さから mover.delta を作る, 階段タイルの上では上りで 52/64, 下りで 40/64 に変える
void Player_SetMoveDelta(Player* p, s32 val) {
  s32 angle = ((p->facing + 5) & 7) * 32;

  p->mover.delta.x = POLAR_X(val, angle);
  p->mover.delta.z = POLAR_Z(val, angle);

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

static void Player_SetAction(Player* p, u32 action, u32 state) {
  p->action = action;
  p->state = state;
  p->stateTimer = 0;
}

// 行動を始める前のフラグ初期化, 日光と武器効果を見て flag20 を組み立て直し各種タイマを 0 に戻す
void Player_BeginAction(Player* p) {
  p->flag20 = PFLAG20_BUSY;
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
  sound_08240740(NOISE_DARK_CHARGE);
  sound_08240740(SE_GUN_SPREAD);
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
  b->knockback = a->knockback;
  if (a->knockback > 200) {
    b->knockback = 200;
  }

  if (Hitbox_TestAttr(a, HBATTR_18)) {
    p->blownAway = 1;
    p->facing = Player_GetDirToAttacker(a, b);
    return;
  }

  if (p->action == PACT_PUSH) {
    b->flags |= HBFLAG_HIDDEN;
    b->knockback = 0;
    return;
  }

  if (Player_TestFlag20(p, PFLAG20_UNK_15)) {
    if (a->flags & HBFLAG_ANGLE) {
      p->knockbackDir = ANGLE_TO_DIR8(a->angle + 0x10);
    } else {
      s32 dx = a->center.x - b->center.x;
      s32 dz = a->center.z - b->center.z;

      if (dx == 0 && dz == 0) {
        p->knockbackDir = p->facing;
      } else {
        p->knockbackDir = (ANGLE_TO_DIR8(((u16)ArcTan2_8(dx, dz) + 0x10)) + 4) & 7;
      }
    }

    p->knockbackSpeed = b->knockback;
    b->knockback = 0;
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
  if (span == TIME_NIGHT_DUSK || span == TIME_NIGHT_MID || span == TIME_NIGHT_DAWN) {
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

/**
 * @param kind 0: カーモス, 1: ???, 2: 黒ジャンゴ暴走
 */
void Player_ExecEventScript(Player* p, u32 kind) {
  if (p->eventScriptID != 0) {
    ScriptArgs args;
    u32 argv;
    args.argc = 1;
    argv = kind;
    args.argv = &argv;
    VM_ExecByID(p->eventScriptID, &args);
  }
}

// 禁止フラグ (forbidFlags) を立てる
void Player_SetForbidFlags(Player* p, u32 val) { p->forbidFlags |= val; }

// 禁止フラグ (forbidFlags) のうち mask のものが立っているかを返す
u32 Player_TestForbidFlags(Player* p, u32 mask) { return p->forbidFlags & mask; }

// 攻撃が禁止されているときに B を押すと forbidScriptID のスクリプトを実行する
void Player_ExecForbidScript(Player* p) {
  if (p->forbidScriptID != 0) {
    VM_ExecByID(p->forbidScriptID, NULL);
  }
}

// ステータス値を割り振りとドーピングから作り直す, サバタはレベルから4つに均等割りする
void Player_RefreshStats(Player* p) {
  s32 i;

  if (p->kind != PLAYER_SABATA) {
    for (i = 0; i < STAT_KINDS; i++) {
      p->stats[i] = STATS(i) + STAT_BONUS(i);
      if (p->stats[i] > 99) {
        p->stats[i] = 99;
      }
    }
  } else {
    s32 lv = gStat->lv + 10;
    s32 total;
    s32 base;
    s32 quot;
    s32 rem;

    if (lv > 99) {
      lv = 99;
    }

    total = (lv - 1) * 3;
    quot = Div(total, 4);
    rem = total - quot * 4;
    base = quot + 10;

    for (i = 0; i < STAT_KINDS; i++) {
      p->stats[i] = STAT_BONUS(i) + base;
      if (rem > 0) {
        p->stats[i]++;
        rem--;
      }
      if (p->stats[i] > 99) {
        p->stats[i] = 99;
      }
    }
  }
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
  if (gGameFlags & GAMEFLAG_CROSSOVER) {
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

// 最大 HP/ENE を再計算し、現在値を丸める
static void Player_RefreshMaxHPEne(Player* p) {
  p->maxHP = CalcMaxHP(p);
  if (p->hp > p->maxHP) p->hp = p->maxHP;

  p->maxEne = CalcMaxEne(p);
  if (p->ene > p->maxEne) p->ene = p->maxEne;
}

// HP/Ene の最大値を計算し直し, セーブ値 (スクリプトが指定していれば満タン) を入れて上限で丸める
void Player_LoadHPEne(Player* p) {
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
void Player_RefreshHurtbox(Player* p) {
  PlayerArmor* armor = &p->armor;
  s32 lv;
  s32 defence;
  HitboxAttributes attrs;
  u32 weakness;

  if (p->kind == PLAYER_SABATA) {  // サバタの場合、常にジャンゴのレベル+10　
    lv = gStat->lv + 10;
    if (lv > 99) lv = 99;
    defence = p->stats[STAT_AGILITY];
    attrs = p->hbattrs | HBATTR_DARK;
    weakness = HBATTR_SOL;
  } else {
    lv = gStat->lv;
    if (p->kind == PLAYER_SOLAR_DJANGO) {
      defence = p->stats[STAT_AGILITY] + armor->bonus[STAT_AGILITY] + armor->sideBonus[STAT_AGILITY];
      attrs = p->hbattrs | HBATTR_SOL;
      weakness = HBATTR_DARK;
    } else {
      defence = p->stats[STAT_AGILITY] + armor->bonus[STAT_AGILITY] - armor->sideBonus[STAT_AGILITY];
      attrs = p->hbattrs | HBATTR_DARK;
      weakness = HBATTR_SOL;
    }
  }

  // 皇帝のカード (全属性に耐性) の効果中は全属性
  if (HasGoodCond(p, GOOD_EMPEROR) || p->hbattrs == HBATTR_ALL) {
    attrs = HBATTR_ALL;
  }

  if (defence > 99) {
    defence = 99;
  }
  defence = ((defence + lv) >> 1) + armor->defence;
  if (p->kind == PLAYER_SABATA) {
    gSabataDefence = defence;
  }

  Hitbox_SetPowerAndAttributes(&p->hurtbox, defence, attrs, weakness);
}

// 生成時に, ステータスと鎧から HP/ENE と食らい判定を作り, HP/ENE はセーブ値を読み込む
void Player_InitDerivedStats(Player* p) {
  Player_LoadHPEne(p);
  Player_RefreshHurtbox(p);
}

// ステータスと鎧から最大 HP/ENE と食らい判定を作り直す, 毎フレーム呼ばれる
void Player_RefreshDerivedStats(Player* p) {
  Player_RefreshMaxHPEne(p);
  Player_RefreshHurtbox(p);
}

// プレイヤーの全パラメータを再計算する, Player_EquipArmor 時に呼ばれる
void Player_RefreshAllStats(Player* p) {
  Player_RefreshStats(p);
  Player_RefreshMaxHPEne(p);
  Player_RefreshHurtbox(p);
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

// 物音の漫符のパーティクルを1フレーム進める, 4フレームごとにパレットを1段ずらし6フレーム過ぎたら消す
void Player_UpdateNoisePtcl(Player* p) {
  if (p->noise.active == 0) {
    return;
  }

  if (++p->noise.timer > 5) {
    p->noise.ptcl.flags |= SPRFLAG_HIDDEN;
    p->noise.active = 0;
    return;
  }

  Particle_SetPose(&p->noise.ptcl, p->noise.group1, p->noise.poseIdx + (p->noise.timer >> 2));
}

// 物音の漫符のパーティクルを pos に出す, 傷んだ壁を叩いたときは専用の漫符にする
void Player_ShowNoisePtcl(Player* p, Vec3* pos, bool32 isFragileWallKnock) {
  Particle* ptcl = &p->noise.ptcl;

  if (isFragileWallKnock) {
    p->noise.poseIdx = PTCL1_FRAGILE_KNOCK_S;
  } else {
    p->noise.poseIdx = PTCL1_NOISE_S;
  }

  Particle_SetPose(ptcl, p->noise.group1, p->noise.poseIdx);
  ptcl->pos = *pos;
  ptcl->flags &= ~SPRFLAG_HIDDEN;
  p->noise.active = TRUE;
  p->noise.timer = 0;
}

// 物音の漫符のパーティクルを確保して隠した状態で初期化する
void Player_InitNoisePtcl(Player* p) {
  ParticleGroup* group = GetParticleGroup(PTCL_GROUP_1);
  Particle* ptcl;

  p->noise.group1 = group;
  ptcl = &p->noise.ptcl;
  Particle_Add(ptcl, group, 0);
  Particle_SetOffset(ptcl, -4, -4);
  Particle_SetPose(ptcl, p->noise.group1, PTCL1_NOISE_S);
  ptcl->flags |= SPRFLAG_HIDDEN;
  ptcl->priority = 1;
  ptcl->offsetZ = 0x14;
  p->noise.active = 0;
  p->noise.timer = 0;
}

// 混乱時に、周囲を回るパーティクルを1つ出し続ける
void Player_UpdateConfusePtcl(Player* p) {
  s32 angle;

  if (p->spurl.active) {
    if (p->mode != PMODE_ACTIVE || p->badCondTimer[BAD_CONFUSE] == 0) {
      p->spurl.ptcl.flags |= SPRFLAG_HIDDEN;
      p->spurl.active = FALSE;
      return;
    }

    angle = (p->spurl.timer * 5) & 0xFF;

    p->spurl.ptcl.pos.x = p->mover.pos.x + POLAR_X(Q8(0.22), angle);
    p->spurl.ptcl.pos.y = p->mover.pos.y + Q8(1.37) + POLAR_Z(Q8(0.274), angle);
    p->spurl.ptcl.pos.z = p->mover.pos.z - POLAR_X(Q8(0.22), angle);

    p->spurl.timer++;
    return;
  }

  if (p->mode != PMODE_ACTIVE || p->badCondTimer[BAD_CONFUSE] == 0) {
    return;
  }

  p->spurl.ptcl.pos = p->mover.pos;
  p->spurl.ptcl.pos.x += Q8(0.22);
  p->spurl.ptcl.pos.y += Q8(1.37);
  p->spurl.ptcl.flags &= ~SPRFLAG_HIDDEN;
  Particle_SetPose(&p->spurl.ptcl, p->spurl.group1, PTCL1_CONFUSE);
  p->spurl.timer = 0;
  p->spurl.active = TRUE;
}

// 混乱のパーティクルを確保して隠した状態で初期化する
void Player_InitConfusePtcl(Player* p) {
  ParticleGroup* group = GetParticleGroup(PTCL_GROUP_1);
  Particle* ptcl;

  p->spurl.group1 = group;
  ptcl = &p->spurl.ptcl;
  Particle_Add(ptcl, group, 0);
  Particle_SetOffset(ptcl, -4, -4);
  Particle_SetPose(ptcl, p->spurl.group1, PTCL1_CONFUSE);
  ptcl->flags |= SPRFLAG_HIDDEN;
  ptcl->priority = 1;
  ptcl->offsetZ = 0x14;
  p->spurl.active = 0;
  p->spurl.timer = 0;
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
void Player_ShowShockwave(Player* p) {
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
  Player_ShowShockwave(p);
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
  Player_ShowShockwave(p);
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
  Player_ShowShockwave(p);
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

// 衝撃波のスプライトを消す
void Player_RemoveShockwave(Player* p) { AuxSprite_Remove(&(p->meleeShockwave).sprite); }

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
    Video_SetAuxSpritePltt(gfx, OBP_RDJANGO);
    p->meleeShockwave.animFile = GetFile(DIR_ANIMATION, ANIM_0837);
    p->meleeShockwave.update = PlayerShockwave_UpdateAnim;
  }

  p->meleeShockwave.finished = FALSE;
}

// エンチャントの粒を1フレーム進める, 12フレームで消え 6フレーム目で小さいコマに変える
void Player_UpdateEnchantPtcls(Player* p) {
  s32 alive;
  s32 i;

  if (!p->enchantPtcls.active) {
    return;
  }

  alive = 0;
  for (i = 0; i < 6; i++) {
    EnchantPtcl* ptcl;
    Particle* base;

    if (!p->enchantPtcls.ptcls[i].active) {
      continue;
    }

    ptcl = &p->enchantPtcls.ptcls[i];
    base = &ptcl->base;
    if (++ptcl->timer > 11) {
      base->flags |= SPRFLAG_HIDDEN;
      ptcl->active = FALSE;
      continue;
    }

    if (ptcl->timer == 6) {
      Particle_SetPose(&ptcl->base, p->enchantPtcls.group2, ptcl->poseIdx + 1);
    }

    base->pos.x += ptcl->vel.x;
    base->pos.y += ptcl->vel.y;
    base->pos.z += ptcl->vel.z;
    alive++;
  }

  if (alive == 0) {
    p->enchantPtcls.active = FALSE;
  }
}

// エンチャントの粒を1つ使って pos / vel を入れて出す, 使う番号は 0..5 を巡回する
void Player_SpawnEnchantPtcl(Player* p, Vec3* pos, Vec3* vel, s32 element) {
  EnchantPtcl* ptcl = &p->enchantPtcls.ptcls[p->enchantPtcls.next];

  ptcl->base.flags &= ~SPRFLAG_HIDDEN;
  ptcl->poseIdx = element * 2 + 2;
  Particle_SetPose(&ptcl->base, p->enchantPtcls.group2, ptcl->poseIdx);
  ptcl->base.pos = *pos;
  ptcl->vel = *vel;
  ptcl->timer = 0;
  ptcl->active = TRUE;
  p->enchantPtcls.active = TRUE;
  p->enchantPtcls.next++;
  if (p->enchantPtcls.next > 5) {
    p->enchantPtcls.next = 0;
  }
}

void Player_RemoveEnchantPtcls(Player* p) {
  s32 i;

  for (i = 0; i < 6; i++) {
    Particle_Remove(&p->enchantPtcls.ptcls[i].base);
  }
}

// エンチャントの粒6個を確保して初期化する
void Player_InitEnchantPtcls(Player* p) {
  PlayerEnchantPtcls* st = &p->enchantPtcls;
  s32 i;

  st->group2 = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 6; i++) {
    EnchantPtcl* ptcl = &st->ptcls[i];

    Particle_Add(&ptcl->base, st->group2, SPRFLAG_HIDDEN);
    Particle_SetOffset(&ptcl->base, -4, -4);
    Particle_SetPltt(&ptcl->base, 1);
    ptcl->base.priority = 2;
  }

  st->active = FALSE;
  st->next = 0;
}

// チャージの粒を chargePos へ寄せながら1フレーム進める, 寄り切ったものは消す
// 残差 149/150: 原典は p を r6, 要素を r4, その写し (&ptcl->base) を r5 に置くが, こちらは写しをスタックへ逃がす
// 効いたもの: ++timer を条件内に, Particle* base を取ってフラグと pos を書く (141→149), 試済: 到着判定と位置合わせの inline, 宣言位置
NON_MATCH void Player_UpdateChargePtcls(Player* p) {
#ifdef NONMATCHING_C
  s32 alive;
  s32 i;

  if (!p->chargePtcls.active) {
    return;
  }

  alive = 0;
  for (i = 0; i < 4; i++) {
    ChargePtcl* ptcl = &p->chargePtcls.ptcls[i];
    Particle* base;
    s32 angle;

    if (!ptcl->active) {
      continue;
    }

    base = &ptcl->base;

    if (abs(ptcl->offset.x) <= 15 && abs(ptcl->offset.z) <= 15) {
      base->flags |= SPRFLAG_HIDDEN;
      ptcl->active = FALSE;
      continue;
    }

    angle = ArcTan2_8(ptcl->offset.x, ptcl->offset.z);

    ptcl->offset.x -= POLAR_X(ptcl->speed, angle);
    ptcl->offset.z -= POLAR_Z(ptcl->speed, angle);

    base->pos.x = ptcl->offset.x + p->chargePos.x;
    base->pos.z = ptcl->offset.z + p->chargePos.z;

    if (++ptcl->timer == 4) {
      Particle_SetPose(&ptcl->base, p->chargePtcls.group2, ptcl->poseIdx + 1);
    }

    alive++;
  }

  if (alive == 0) {
    p->chargePtcls.active = FALSE;
  }
#else
  INCFUNC("asm/func/Player_UpdateChargePtcls.inc");
#endif
}

// 太陽ゲージのぶんカウンタを溜め, 0x27 を超えたら太陽チャージの粒を1つ出す
// 残差 157/162: Player_SpawnDarkChargePtcl と同じで, 原典は p を r7 / pos を r9 / 要素の写しを r8 に置くが, こちらは高位レジスタを1本しか使わない
// 効いたもの: 加算した値をそのまま条件に使う, Particle* base を別に取って pos を書く, 試済: 右辺を先に足す並び, 宣言順
NON_MATCH void Player_SpawnSolarChargePtcl(Player* p, Vec3* pos) {
#ifdef NONMATCHING_C
  ChargePtcl* ptcl;
  Particle* base;
  u16* table;
  u32 idx;
  s32 angle;
  s32 dist;

  if ((p->chargePtcls.spawnTimer += gStat->sunGauge + 2) <= 0x27) {
    return;
  }

  ptcl = &p->chargePtcls.ptcls[p->chargePtcls.next];
  base = &ptcl->base;
  ptcl->base.flags &= ~SPRFLAG_HIDDEN;
  ptcl->poseIdx = PTCL2_SOL_L;
  Particle_SetPose(&ptcl->base, p->chargePtcls.group2, PTCL2_SOL_L);

  table = gRandomTable;
  idx = (gRandTableIdx + 1) & 0x3FF;
  angle = (u8)table[idx];
  gRandTableIdx = (idx + 1) & 0x3FF;
  dist = (table[gRandTableIdx] & 0x3F) + 0x80;

  ptcl->offset.x = POLAR_X(dist, angle);
  ptcl->offset.z = POLAR_Z(dist, angle);

  base->pos = *pos;
  base->pos.x += ptcl->offset.x;
  base->pos.z += ptcl->offset.z;

  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  ptcl->speed = (gRandomTable[gRandTableIdx] & 3) + 0xE;
  ptcl->timer = 0;
  ptcl->active = TRUE;
  p->chargePtcls.next++;
  if (p->chargePtcls.next > 3) {
    p->chargePtcls.next = 0;
  }

  p->chargePtcls.spawnTimer -= 0x28;
  p->chargePtcls.active = TRUE;
#else
  INCFUNC("asm/func/Player_SpawnSolarChargePtcl.inc");
#endif
}

// 4フレームごとに暗黒チャージの粒を1つ, pos からランダムな向き・距離だけ離して置く
// 残差 149/151: 原典は p と pos を r8/r9 に置く (こちらは p が r7), 要素を r6 に作って &ptcl->base を r7 に写し pos の書き込みだけ r7 で行う
// 効いたもの: ++spawnTimer を条件内に, Particle* base を別に取って pos を書く, 試済: RandomNext 書き換え (143), 要素を受ける inline (147), 宣言順
NON_MATCH void Player_SpawnDarkChargePtcl(Player* p, Vec3* pos) {
#ifdef NONMATCHING_C
  ChargePtcl* ptcl;
  Particle* base;
  u16* table;
  u32 idx;
  s32 angle;
  s32 dist;

  if ((++p->chargePtcls.spawnTimer & 3) != 0) {
    return;
  }

  ptcl = &p->chargePtcls.ptcls[p->chargePtcls.next];
  base = &ptcl->base;
  ptcl->base.flags &= ~SPRFLAG_HIDDEN;
  ptcl->poseIdx = PTCL2_DARK_L;
  Particle_SetPose(&ptcl->base, p->chargePtcls.group2, PTCL2_DARK_L);

  table = gRandomTable;
  idx = (gRandTableIdx + 1) & 0x3FF;
  angle = (u8)table[idx];
  gRandTableIdx = (idx + 1) & 0x3FF;
  dist = (table[gRandTableIdx] & 0x7F) + 0x100;

  ptcl->offset.x = POLAR_X(dist, angle);
  ptcl->offset.z = POLAR_Z(dist, angle);

  base->pos = *pos;
  base->pos.x += ptcl->offset.x;
  base->pos.z += ptcl->offset.z;

  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  ptcl->speed = (gRandomTable[gRandTableIdx] & 7) + 0x1C;
  ptcl->timer = 0;
  ptcl->active = TRUE;
  p->chargePtcls.active = TRUE;
  p->chargePtcls.next++;
  if (p->chargePtcls.next > 3) {
    p->chargePtcls.next = 0;
  }
#else
  INCFUNC("asm/func/Player_SpawnDarkChargePtcl.inc");
#endif
}

void Player_RemoveChargePtcls(Player* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->chargePtcls.ptcls[i].base);
  }
}

// チャージの粒4個を確保して初期化する
void Player_InitChargePtcls(Player* p) {
  PlayerChargePtcls* st = &p->chargePtcls;
  s32 i;

  st->group2 = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 4; i++) {
    ChargePtcl* ptcl = &st->ptcls[i];

    Particle_Add(&ptcl->base, st->group2, SPRFLAG_HIDDEN);
    Particle_SetOffset(&ptcl->base, -4, -4);
    Particle_SetPltt(&ptcl->base, 1);
    ptcl->base.priority = 2;
  }

  st->next = 0;
  st->spawnTimer = 0;
}

// 自前のパレット pltt を作る, plttBrightness のぶん全チャンネルを明るくし, unk_359 が 0 なら色5/6/13 は触らない
// 残差5命令 (159/154): 原典は高位レジスタを r8 の1本で済ませているが, こちらは r9 も使ってしまう
// Tier A/B と dst のローカル化有無は試済
NON_MATCH void Player_BuildPltt(Player* p) {
#ifdef NONMATCHING_C
  rgb555* src = &gObjPlttData[p->plttIDs[p->plttIdx] * 16];
  s32 i;

  if (p->plttBrightness == 0) {
    if (p->useAuxSprite == 0) {
      for (i = 0; i < 16; i++) {
        if (i != 5 && i != 6 && i != 13) {
          p->pltt[i] = src[i];
        }
      }
    } else {
      for (i = 0; i < 16; i++) {
        p->pltt[i] = src[i];
      }
    }
  } else if (p->useAuxSprite == 0) {
    for (i = 0; i < 16; i++) {
      if (i != 5 && i != 6 && i != 13) {
        u16 c = src[i];
        s32 r = (c & 0x1F) + p->plttBrightness;
        s32 g;
        s32 b;

        if (r > 0x1F) {
          r = 0x1F;
        }
        g = ((c >> 5) & 0x1F) + p->plttBrightness;
        if (g > 0x1F) {
          g = 0x1F;
        }
        b = ((c >> 10) & 0x1F) + p->plttBrightness;
        if (b > 0x1F) {
          b = 0x1F;
        }
        p->pltt[i] = (b << 10) | (g << 5) | r;
      }
    }
  } else {
    for (i = 0; i < 16; i++) {
      u16 c = src[i];
      s32 r = (c & 0x1F) + p->plttBrightness;
      s32 g;
      s32 b;

      if (r > 0x1F) {
        r = 0x1F;
      }
      g = ((c >> 5) & 0x1F) + p->plttBrightness;
      if (g > 0x1F) {
        g = 0x1F;
      }
      b = ((c >> 10) & 0x1F) + p->plttBrightness;
      if (b > 0x1F) {
        b = 0x1F;
      }
      p->pltt[i] = (b << 10) | (g << 5) | r;
    }
  }
#else
  INCFUNC("asm/func/Player_BuildPltt.inc");
#endif
}

// 屋外かどうかと PFLAG20 の 0x10 で 0 / 4 / 8 を返す
u32 Player_GetSunbathBrightness(Player* p) {
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

// enchantColorIdx ごとに3色ずつ並んだ表から、パレットの5,6,13番を差し替える
void Player_ApplyEnchantColors(Player* p) {
  rgb555* src = &gObjPlttData[40 * 16];

  src += p->enchantColorIdx * 3;

  p->pltt[5] = *src++;
  p->pltt[6] = src[0];
  p->pltt[13] = src[1];
}

// src と pltt を wSrc:wBase の比で混ぜて pltt[16..31] に作り, スプライトのパレットをそこへ向ける
// unk_359 が 0 なら色5/6/13 は混ぜずにそのまま写す
// 残差2命令 (227/225): レジスタ割当とスタック使用量だけ (原典は p を sl, wSrc を ip に置いて 0x14 で足りている)
// 添字でなくカーソル (src++/base++) にすると命令数はここまで詰まった, Tier A/B は試済
NON_MATCH void Player_BlendPltt(Player* p, u16* src, s32 wSrc, s32 wBase, u32 shift) {
#ifdef NONMATCHING_C
  rgb555* base;
  s32 i;

  if (wSrc == 0) {
    if (p->useAuxSprite == 0) {
      p->human.pltt = p->pltt;
    } else {
      p->beastGfx->pltt = p->pltt;
    }
    return;
  }

  if (p->useAuxSprite == 0) {
    base = p->pltt;
    for (i = 0; i < 16; i++) {
      if (i == 5 || i == 6 || i == 13) {
        base[16] = base[0];
      } else {
        u16 c = src[0];
        u16 d;
        s32 r = (c & 0x1F) + p->plttBrightness;
        s32 g;
        s32 b;

        if (r > 0x1F) {
          r = 0x1F;
        }
        g = ((c >> 5) & 0x1F) + p->plttBrightness;
        if (g > 0x1F) {
          g = 0x1F;
        }
        b = ((c >> 10) & 0x1F) + p->plttBrightness;
        if (b > 0x1F) {
          b = 0x1F;
        }

        d = base[0];
        base[16] = ((((b * wSrc) + (((d >> 10) & 0x1F) * wBase)) >> shift) << 10) | ((((g * wSrc) + (((d >> 5) & 0x1F) * wBase)) >> shift) << 5) | (((r * wSrc) + ((d & 0x1F) * wBase)) >> shift);
      }

      src++;
      base++;
    }
    p->human.pltt = &p->pltt[16];
  } else {
    base = p->pltt;
    for (i = 0; i < 16; i++) {
      u16 c = src[0];
      u16 d;
      s32 r = (c & 0x1F) + p->plttBrightness;
      s32 g;
      s32 b;

      if (r > 0x1F) {
        r = 0x1F;
      }
      g = ((c >> 5) & 0x1F) + p->plttBrightness;
      if (g > 0x1F) {
        g = 0x1F;
      }
      b = ((c >> 10) & 0x1F) + p->plttBrightness;
      if (b > 0x1F) {
        b = 0x1F;
      }

      d = base[0];
      base[16] = ((((b * wSrc) + (((d >> 10) & 0x1F) * wBase)) >> shift) << 10) | ((((g * wSrc) + (((d >> 5) & 0x1F) * wBase)) >> shift) << 5) | (((r * wSrc) + ((d & 0x1F) * wBase)) >> shift);

      src++;
      base++;
    }
    p->beastGfx->pltt = &p->pltt[16];
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
  magic32_t mid;
  s32 i;

  if (p->nextEnchantColorIdx != p->enchantColorIdx) {
    p->enchantColorIdx = p->nextEnchantColorIdx;
    Player_ApplyEnchantColors(p);
  }

  bright = Player_GetSunbathBrightness(p);
  if (p->plttIdx != n || p->plttBrightness != bright) {
    p->plttIdx = n;
    p->plttBrightness = bright;
    Player_BuildPltt(p);
  }

  if (p->plttFlashTimer != 0) {
    p->enchantPlttTimer = 0;
    if (p->plttFlashTimer > 31) {
      src = &gObjPlttData[p->flashPlttID * 16];
      if (p->useAuxSprite == 0) {
        for (i = 0; i < 16; i++) {
          if (i == 5 || i == 6 || i == 13) {
            p->pltt[16 + i] = p->pltt[i];
          } else {
            p->pltt[16 + i] = src[i];
          }
        }
        p->human.pltt = &p->pltt[16];
      } else {
        for (i = 0; i < 16; i++) {
          p->pltt[16 + i] = src[i];
        }
        p->beastGfx->pltt = &p->pltt[16];
      }
    } else {
      src = &gObjPlttData[p->flashPlttID * 16];
      w = p->plttFlashTimer;
      Player_BlendPltt(p, src, w, 0x20 - w, 5);
    }

    p->plttFlashTimer--;
    return;
  }

  mid = Player_CheckMagicEnchant(p);
  if (mid >= 0) {
    p->enchantPlttID = OBP_ELEMENT(mid);
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
    p->human.pltt = p->pltt;
  } else {
    p->beastGfx->pltt = p->pltt;
  }
#else
  INCFUNC("asm/func/Player_UpdatePltt.inc");
#endif
}

// 操作不能 (PMODE_LOCKED) 中のパレット更新, lockedPlttFx で演出の段階 (1: フェードイン, 2: 点滅) を切り替える
// 残差2命令 (350/348): p が r4 に入る割当差だけ (原典は r5), Player_UpdatePltt と同じ現象でコピー経路が2つあるぶん src の退避が2命令余る
// Tier A-C は試済 (ローカルのスコープ最小化で4命令→2命令, n の符号付け替えは無効)
NON_MATCH void Player_UpdateLockedPltt(Player* p, u32 n) {
#ifdef NONMATCHING_C
  u32 bright;

  if (p->nextEnchantColorIdx != p->enchantColorIdx) {
    p->enchantColorIdx = p->nextEnchantColorIdx;
    Player_ApplyEnchantColors(p);
  }

  bright = Player_GetSunbathBrightness(p);
  if (p->plttIdx != n || p->plttBrightness != bright) {
    p->plttIdx = n;
    p->plttBrightness = bright;
    Player_BuildPltt(p);
  }

  if (p->lockedPlttFx == 1) {
    rgb555* src;
    s32 w;
    s32 i;

    p->enchantPlttTimer = 0;
    if (p->plttFlashTimer > 31) {
      src = &gObjPlttData[p->flashPlttID * 16];
      if (p->useAuxSprite == 0) {
        for (i = 0; i < 16; i++) {
          if (i == 5 || i == 6 || i == 13) {
            p->pltt[16 + i] = p->pltt[i];
          } else {
            p->pltt[16 + i] = src[i];
          }
        }
        p->human.pltt = &p->pltt[16];
      } else {
        for (i = 0; i < 16; i++) {
          p->pltt[16 + i] = src[i];
        }
        p->beastGfx->pltt = &p->pltt[16];
      }
      return;
    }

    src = &gObjPlttData[p->flashPlttID * 16];
    w = p->plttFlashTimer;
    Player_BlendPltt(p, src, w, 0x20 - w, 5);
    p->plttFlashTimer++;
    return;
  }

  if (p->lockedPlttFx == 2) {
    rgb555* src;
    s32 w;

    p->enchantPlttTimer = 0;
    src = &gObjPlttData[p->flashPlttID * 16];
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
      src = &gObjPlttData[p->flashPlttID * 16];
      if (p->useAuxSprite == 0) {
        for (i = 0; i < 16; i++) {
          if (i == 5 || i == 6 || i == 13) {
            p->pltt[16 + i] = p->pltt[i];
          } else {
            p->pltt[16 + i] = src[i];
          }
        }
        p->human.pltt = &p->pltt[16];
      } else {
        for (i = 0; i < 16; i++) {
          p->pltt[16 + i] = src[i];
        }
        p->beastGfx->pltt = &p->pltt[16];
      }
    } else {
      src = &gObjPlttData[p->flashPlttID * 16];
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
    p->human.pltt = p->pltt;
  } else {
    p->beastGfx->pltt = p->pltt;
  }
#else
  INCFUNC("asm/func/Player_UpdateLockedPltt.inc");
#endif
}

void Player_SetBasePlttID(Player* p) {
  if (p->inputIdx == 0) {
    p->basePlttID = 29;
  } else {
    p->basePlttID = 40;
  }
}

// ロックマンコラボの鎧を装備すると、プレイヤーのパレットIDが対応するものに変更される
// 例: ロックパワー(EBUFF_MEGAPOWER) は ロックマンと同じ青色
void Player_SetPlttIDs(Player* p) {
  switch (p->kind) {
    case PLAYER_SOLAR_DJANGO: {
      if (Player_TestEquipBuff(p, EBUFF_MEGAPOWER)) {
        p->plttIDs[0] = OBP_MEGAPOWER;
      } else if (Player_TestEquipBuff(p, EBUFF_GUTSPOWER)) {
        p->plttIDs[0] = OBP_GUTSPOWER;
      } else if (Player_TestEquipBuff(p, EBUFF_PROTOPOWER)) {
        p->plttIDs[0] = OBP_PROTOPOWER;
      } else if (Player_TestEquipBuff(p, EBUFF_TOADPOWER)) {
        p->plttIDs[0] = OBP_TOADPOWER;
      } else {
        p->plttIDs[0] = OBP_RDJANGO;
      }
      p->plttIDs[1] = OBP_ELEMENT(0), p->plttIDs[2] = 32, p->plttIDs[3] = 291, p->plttIDs[4] = 292, p->plttIDs[5] = 31, p->plttIDs[6] = 33, p->plttIDs[7] = 30;
      break;
    }
    case PLAYER_DARK_DJANGO: {
      if (Player_TestEquipBuff(p, EBUFF_MEGAPOWER)) {
        p->plttIDs[0] = OBP_MEGAPOWER;
      } else if (Player_TestEquipBuff(p, EBUFF_GUTSPOWER)) {
        p->plttIDs[0] = OBP_GUTSPOWER;
      } else if (Player_TestEquipBuff(p, EBUFF_PROTOPOWER)) {
        p->plttIDs[0] = OBP_PROTOPOWER;
      } else if (Player_TestEquipBuff(p, EBUFF_TOADPOWER)) {
        p->plttIDs[0] = OBP_TOADPOWER;
      } else {
        p->plttIDs[0] = OBP_BDJANGO;
      }
      p->plttIDs[1] = OBP_ELEMENT(0), p->plttIDs[2] = 32, p->plttIDs[3] = 291, p->plttIDs[4] = 292, p->plttIDs[5] = 31, p->plttIDs[6] = 33, p->plttIDs[7] = 30;
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
        p->plttIDs[0] = OBP_MEGAPOWER;
      } else if (Player_TestEquipBuff(p, EBUFF_GUTSPOWER)) {
        p->plttIDs[0] = OBP_GUTSPOWER;
      } else if (Player_TestEquipBuff(p, EBUFF_PROTOPOWER)) {
        p->plttIDs[0] = OBP_PROTOPOWER;
      } else if (Player_TestEquipBuff(p, EBUFF_TOADPOWER)) {
        p->plttIDs[0] = OBP_TOADPOWER;
      } else {
        p->plttIDs[0] = OBP_RDJANGO;
      }
      p->plttIDs[1] = OBP_ELEMENT(0), p->plttIDs[2] = 32, p->plttIDs[3] = 291, p->plttIDs[4] = 292, p->plttIDs[5] = 31, p->plttIDs[6] = 33, p->plttIDs[7] = 30;
      break;
    }
    case PLAYER_SLEEPING: {
      p->plttIDs[0] = OBP_COFFIN(p->coffin);
      p->plttIDs[1] = 527;
      p->plttIDs[2] = OBP_COFFIN(p->coffin);
      p->plttIDs[3] = OBP_COFFIN(p->coffin);
      p->plttIDs[4] = OBP_COFFIN(p->coffin);
      p->plttIDs[5] = OBP_COFFIN(p->coffin);
      p->plttIDs[6] = OBP_COFFIN(p->coffin);
      p->plttIDs[7] = OBP_COFFIN(p->coffin);
      break;
    }
    case PLAYER_SABATA: {
      p->plttIDs[0] = OBP_SABATA;
      p->plttIDs[1] = OBP_ELEMENT(0), p->plttIDs[2] = 32, p->plttIDs[3] = 291, p->plttIDs[4] = 292, p->plttIDs[5] = 31, p->plttIDs[6] = 33, p->plttIDs[7] = 30;
      break;
    }
  }
}

// スプライトのパレットを自前の pltt に差し替えて初期状態に戻す
void Player_ResetPltt(Player* p) {
  Player_SetBasePlttID(p);
  Player_SetPlttIDs(p);
  p->plttIdx = 0xFFFF;
  p->enchantColorIdx = 0xFF;
  p->human.plttID = p->basePlttID;
  p->human.pltt = p->pltt;
  p->beastGfx->plttID = p->basePlttID;
  p->beastGfx->pltt = p->pltt;
  Player_UpdatePltt(p, 0);
}

// 状態異常の粒をひとつ弾けさせて1段階解く, 引火なら消えかけさせるだけ
// 残差2命令 (134/132): 原典は高位レジスタを r8-r10 の3本使うが, プロトタイプありで呼ぶと2本で足りてしまう
// ElementalCondEmitter_BurstParticle の宣言を外すと streamdiff は完全一致する (暗黙宣言のときだけ原典のレジスタ圧になる)
NON_MATCH void Player_BurstElementalCond(Player* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  Vec3 vel;
  Vec3 velRange;
  Vec3* src;
  u16* table;
  u32 idx;

  if (p->emitter.kind == ELEMCOND_INKA) {
    ElementalCondEmitter_FadeParticle(&p->emitter);
    return;
  }

  if (p->emitter.kind == ELEMCOND_HYOKETU) {
    PlaySound_082406e0(SE_END_SOLIDIFY);
  } else if (p->emitter.kind == ELEMCOND_SEKIKA) {
    PlaySound_082406e0(SE_END_SOLIDIFY);
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
  ElementalCondEmitter_BurstParticle(&p->emitter, 3, &pos, &vel, &velRange, 0x28, 0x28);
#else
  INCFUNC("asm/func/Player_BurstElementalCond.inc");
#endif
}

// かかっている状態異常の粒を全部弾けさせて解く
void Player_ClearElementalCond(Player* p) {
  s32 count = p->emitter.aliveCount;
  s32 i;

  for (i = 0; i < count; i++) {
    Player_BurstElementalCond(p);
  }
}

// 状態異常の粒を消す, 引火はエミッタをリセットし, それ以外は全部弾けさせる
void Player_ResetElementalCond(Player* p) {
  if (p->emitter.kind == ELEMCOND_INKA) {
    ElementalCondEmitter_Reset(&p->emitter);
  } else {
    s32 count = p->emitter.aliveCount;
    s32 i;

    for (i = 0; i < count; i++) {
      Player_BurstElementalCond(p);
    }
  }
}

// 状態異常 (kind 1: 引火, 2: 氷結, 3: 石化) の粒をひとつ足す, 粒のばらけ方はフォームで変わり, 出せたら種類ごとの効果音を鳴らす
// 残差3命令 (187/190): 原典は p と kind を r8/r9 に置くが, こちらは r8 だけで足りてしまう
NON_MATCH void Player_InflictElementalCond(Player* p, u32 kind) {
#ifdef NONMATCHING_C
  Vec3 spread;
  u16* table;
  u32 idx;

  if (p->emitter.aliveCount != 0) {
    if (p->emitter.kind != kind) {
      if (p->emitter.kind == ELEMCOND_SEKIKA) {
        return;
      }
      Player_ResetElementalCond(p);
    }
  }

  if (p->emitter.aliveCount == 0) {
    p->mashCountBase = p->mashCount;
    p->inkaTick = 0;
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
  if (ElementalCondEmitter_AddParticle(&p->emitter, kind, 0xE10, &spread) >= 0) {
    if (p->emitter.kind == ELEMCOND_INKA) {
      PlaySound_082406e0(SE_IGNITE);
    } else if (p->emitter.kind == ELEMCOND_HYOKETU) {
      p->damage += 10;
      PlaySound_082406e0(SE_SOLIDIFY);
    } else if (p->emitter.kind == ELEMCOND_SEKIKA) {
      PlaySound_082406e0(SE_SOLIDIFY);
    }
    p->badCondTimer[BAD_POISON] = 0;
  }
#else
  INCFUNC("asm/func/Player_InflictElementalCond.inc");
#endif
}

s32 Player_GetMashCount(Player* p) { return (p->mashCount - p->mashCountBase + 0x100) & 0xFF; }

// 姿勢を決める, 変化直後は 0x40 フレームのあいだ 4フレームおきに前の値と交互に返す
u32 Player_ApplyPoseHold(Player* p, u32 n) {
  static const u8 u8_ARRAY_085abab4[4] = {3, 4, 6, 0};  // 0x085ABAB4

  u32 pose = n;

  if (p->emitter.aliveCount != 0) {
    if (p->mode & PMODE_ACTIVE) {
      if (Player_GetMashCount(p) >= u8_ARRAY_085abab4[p->emitter.kind - 1]) {
        Player_BurstElementalCond(p);
        p->mashCountBase = p->mashCount;
      }
    }

    if (p->emitter.aliveCount != 0) {
      if (p->emitter.kind == ELEMCOND_INKA) {
        pose = 3;
      } else if (p->emitter.kind == ELEMCOND_HYOKETU) {
        pose = 4;
      } else if (p->emitter.kind == ELEMCOND_SEKIKA) {
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
      if (p->emitter.aliveCount != 0) {
        if (p->emitter.kind == ELEMCOND_SEKIKA) {
          break;
        }
        Player_ClearElementalCond(p);
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
            MosaicFader_Start(2, 1, 0x1E, p->mosaicFrom, p->mosaicTo, p->mosaicInterval);
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
u32 Player_ApplyFlashPose(Player* p, u32 pose) {
  if (p->flashTimer == 0) {
    return pose;
  } else if ((--p->flashTimer >> 2) & 1) {
    return p->flashPose;
  } else {
    return pose;
  }
}

// 変身の拡縮演出を1フレーム進める, goodCondID が GOOD_MINI の間は縮み, それ以外では元の大きさへ戻る
// 残差4命令 (186/190): レジスタ割当 (原典は p を r4) と定数の作り直し
// 分岐の並び (goodCondTimer != 0 を先) は原典と一致した, Tier A/B は試済
// 元に戻すときに消すのは SPRFLAG_AFFINE だけ (原典は ~2 で and, HIDDEN も消していたのを直した), 原典は goodCondTimer を r8 に残して isMiniHuman = FALSE の格納に使い回し, &isMiniHuman も r7 に持ち越す
// isMiniHuman の読みを getter の static inline にすると 22 hunk まで縮む (setter も足すと悪化), 戻すブロックを static inline にまとめる形は 29
NON_MATCH void Player_UpdateFormScale(Player* p) {
#ifdef NONMATCHING_C
  s32 scale;

  if (p->goodCondTimer != 0) {
    if (p->goodCondID == GOOD_MINI) {
      if (p->shrink <= 0x3F) {
        if (p->shrink == 0) {
          PlaySound_082406e0(SE_PLAYER_SHRINK);
          p->isMiniHuman = TRUE;
        }
        p->shrink++;
      }

      p->human.flags |= SPRFLAG_AFFINE;
      scale = 0x40 - (p->shrink >> 1);
      p->human.scaleX = scale;
      p->human.scaleY = scale;
      p->flag20 |= (PFLAG20_SNEAKING | PFLAG20_UNK_18);
    } else if (p->shrink != 0) {
      if (p->isMiniHuman) {
        PlaySound_082406e0(SE_PLAYER_SHRINK_END);
        p->isMiniHuman = FALSE;
      }

      p->shrink--;
      if (p->shrink == 0) {
        p->human.flags &= ~SPRFLAG_AFFINE;
        scale = Q6(1);
      } else {
        p->human.flags |= SPRFLAG_AFFINE;
        scale = Q6(1) - (p->shrink >> 1);
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
    if (p->shrink != 0) {
      if (p->isMiniHuman) {
        PlaySound_082406e0(SE_PLAYER_SHRINK_END);
        p->isMiniHuman = FALSE;
      }

      p->shrink--;
      if (p->shrink == 0) {
        p->human.flags &= ~SPRFLAG_AFFINE;
        scale = Q6(1);
      } else {
        p->human.flags |= SPRFLAG_AFFINE;
        scale = Q6(1) - (p->shrink >> 1);
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
    Player_UpdateLockedPltt(p, pose);
  } else {
    Player_UpdatePltt(p, pose);
  }

  Player_UpdateNoisePtcl(p);
  Player_UpdateConfusePtcl(p);
  Player_UpdateEnchantPtcls(p);
  Player_UpdateChargePtcls(p);
  p->meleeShockwave.update(&p->meleeShockwave);

  if (p->emoteTimer != 0) {
    p->emoteTimer--;
    if (p->emoteTimer == 0) {
      p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 0x7F, 0, 0, 0, 0x50);
    }
  }

  p->shadowPos.x = p->mover.pos.x + p->shadowOffset.x;
  p->shadowPos.y = p->mover.pos.y + p->shadowOffset.y;
  p->shadowPos.z = p->mover.pos.z + p->shadowOffset.z;
}

// Player が抱えているエフェクト・影・パーティクル・衝撃波をまとめて片付ける
void Player_DestroyEffects(Player* p) {
  ElementalCondEmitter_Destroy(&p->emitter);
  ParticleShadow_Remove(&p->shadow);
  Particle_Remove(&p->noise.ptcl);
  Particle_Remove(&p->spurl.ptcl);
  Player_RemoveEnchantPtcls(p);
  Player_RemoveChargePtcls(p);
  Player_RemoveShockwave(p);
}

// Player の生成直後にエフェクト・影・パーティクル・モザイクの初期値をまとめて入れる
void Player_InitEffects(Player* p) {
  if (p->useAuxSprite == 1) {
    ElementalCondEmitter_Init(&p->emitter, &p->beast.pos, ELEMCOND_NONE, 0, 1);
  } else {
    ElementalCondEmitter_Init(&p->emitter, &p->human.pos, ELEMCOND_NONE, 0, 1);
  }

  p->shadowPos = p->human.pos;
  p->shadowOffset.x = 0, p->shadowOffset.y = 0, p->shadowOffset.z = 0;
  ParticleShadow_Init(&p->shadow, &p->shadowPos, 0);
  BloodEmitter_Create();

  if (HasGoodCond(p, GOOD_MINI)) {
    p->shrink = 0x40;
    p->isMiniHuman = TRUE;
  }

  Player_ResetPltt(p);
  Player_InitNoisePtcl(p);
  Player_InitConfusePtcl(p);
  Player_InitEnchantPtcls(p);
  Player_InitChargePtcls(p);
  Player_InitShockwave(p);

  p->mosaicFrom[0] = 4;
  p->mosaicFrom[1] = 4;
  p->mosaicFrom[2] = 4;
  p->mosaicFrom[3] = 4;
  p->mosaicTo[0] = 0;
  p->mosaicTo[1] = 0;
  p->mosaicTo[2] = 0;
  p->mosaicTo[3] = 0;
  p->mosaicInterval[0] = 4;
  p->mosaicInterval[1] = 4;
  p->mosaicInterval[2] = 4;
  p->mosaicInterval[3] = 4;
  p->unk_978 = 0;
  p->damageNumOffset.x = 0;
  p->damageNumOffset.y = 0;
  p->damageNumOffset.z = 0;
  gWindStrength = 0;
  gWindAngle = 0;
  gWindPushThreshold = 1;
  gRisingSunCount = 0;
  p->spiderWebIdx = 0xFF;
}

u32 Player_WeaponEffectSol(Player* p) { return gStat->sunGauge; }

// 状態異常中や太陽光を浴びている間だけ追加ダメージ 10
u32 Player_WeaponEffectStatCond(Player* p) {
  s32 i;

  for (i = 0; i < 3; i++) {
    if (p->badCondTimer[i] != 0) return 10;
  }
  if (KAAMOS(p->isSabata) != 0) return 10;
  if (p->emitter.aliveCount != 0) return 10;
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
    CreateDamageNumber(&p->hurtbox, 1, 1, &p->mover.pos, &p->damageNumOffset, p->unk_978);
  }
}

// 装備した武器の特殊効果に応じて, ダメージ計算時に呼ばれるコールバックとフラグを登録する
// 残差は w + i*4 の adds のオペランド順だけ (214/214): 原典は adds r1, r6(w), r0(i*4), こちらは i*4 が先
// 効果IDは *(u8*)&w->effects[i] で ldrb [w + i*4, #0x18] の形まで寄った ((u8) キャストや & 0xFF だと &w->effects[0] がループ外に括り出される), 添字の書き換え3通りは試済
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
    switch (*(u8*)&w->effects[i]) {
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

// 武器種ごとに当たり判定の大きさ・位置・攻撃元の種別を設定する, サバタは固定値
void Player_SetWeaponHitbox(Player* p) {
  HitboxData* hitbox = &p->wpn.hitbox;
  Vec3 halfSize, offset;
  u32 weakness;

  if (p->kind != PLAYER_SABATA) {
    switch (p->wpn.weaponKind) {
      case WK_SWORD: {
        VEC3_SET(halfSize, Q8(0.352), Q8(0.196), Q8(0.352));
        VEC3_SET(offset, 0, Q8(-0.1), 0);
        weakness = 1 << WK_SWORD;
        p->wpn.knockback = 32;
        p->wpn.iframes = 10;
        break;
      }
      case WK_SPEAR: {
        VEC3_SET(halfSize, Q8(0.235), Q8(0.391), Q8(0.235));
        VEC3_SET(offset, 0, 0, 0);
        weakness = 1 << WK_SPEAR;
        p->wpn.knockback = 64;
        p->wpn.iframes = 20;
        break;
      }
      case WK_HAMMER: {
        VEC3_SET(halfSize, Q8(0.313), Q8(0.274), Q8(0.313));
        VEC3_SET(offset, 0, Q8(0.12), 0);
        weakness = 1 << WK_HAMMER;
        p->wpn.knockback = 48;
        p->wpn.iframes = 20;
        break;
      }
      case WK_OTHERS: {
        VEC3_SET(halfSize, Q8(0.235), Q8(0.391), Q8(0.235));
        VEC3_SET(offset, 0, Q8(-0.313), 0);
        weakness = 1 << WK_OTHERS;
        p->wpn.knockback = 1;
        p->wpn.iframes = 5;
        break;
      }
      case WK_GUN: {
        VEC3_SET(halfSize, Q8(0.235), Q8(0.196), Q8(0.235));
        VEC3_SET(offset, 0, Q8(-0.1), 0);
        weakness = 1 << WK_GUN;
        p->wpn.knockback = 32;
        p->wpn.iframes = 20;
        break;
      }
      default: {
        return;
      }
    }

    Hitbox_Init(hitbox, 0, (HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0), 0, 1 << p->mover.unk_4, &halfSize, &offset);
    Hitbox_SetAttack(hitbox, p->wpn.atkPower, p->wpn.knockback, weakness, 0, p->wpn.iframes);
    Hitbox_SetHandler(hitbox, Django_OnWeaponHit, p);
  } else {
    VEC3_SET(halfSize, Q8(0.665), Q8(0.196), Q8(0.665));
    VEC3_SET(offset, 0, Q8(-0.08), 0);
    Hitbox_Init(hitbox, 0, (HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0), 0, 1 << p->mover.unk_4, &halfSize, &offset);
    Hitbox_SetAttack(hitbox, 20, 0x32, 1 << WK_GUN, HBATTR_DARK, 0x14);
    Hitbox_SetHandler(hitbox, NULL, p);
  }
}

// 装備中の武器を w にする
void Player_SetWeapon(Player* p, Weapon* w) { p->wpn.weapon = w; }

void Player_UpdateSwordAttack(Player* p);
void Player_UpdateSpearAttack(Player* p);
void Player_UpdateHammerAttack(Player* p);
void Player_UpdateFistAttack(Player* p);
void Player_UpdateSolarGunAttack(Player* p);

// 装備中の武器の情報を Player に展開する, サバタはガンデルヘル (WEAPON_GUN_DEL_HELL) 固定
void Player_ApplyWeapon(Player* p, Weapon* w) {
  static const PlayerFunc sPlayerAttackUpdates[5] = {
      [WK_SWORD] = Player_UpdateSwordAttack,
      [WK_SPEAR] = Player_UpdateSpearAttack,
      [WK_HAMMER] = Player_UpdateHammerAttack,
      [WK_OTHERS] = Player_UpdateFistAttack,
      [WK_GUN] = Player_UpdateSolarGunAttack,
  };  // 0x085ABAB8

  WeaponData wd;

  if (p->kind != PLAYER_SABATA) {
    Player_SetWeapon(p, w);
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
  p->wpn.atkPower = CalcAttackWithEquippedArmor(&wd);
  Player_EnableWeaponSpecialEffects(p, &wd);

  if (p->wpn.weaponID == WEAPON_MEGA_BUSTER) {
    p->attackCB = Player_UpdateMegaBusterAttack;
  } else {
    p->attackCB = sPlayerAttackUpdates[p->wpn.weaponKind];
  }

  Player_SetWeaponHitbox(p);
  if (p->action == PACT_ATTACK) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// 攻撃で与えたダメージの分だけ武器を損傷させる, 限界を超えたら品質か特殊効果を1つ失う
// ダメージはジャンゴがバットに攻撃を当てると呼ばれる EnemyBat_OnHurt の 0x0813EFFC で wpn.hitbox.damage に加算される (他の敵も同様と思われる)
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
void Player_ApplyArmorEffect(Player* p, const ArmorData* a) {
  s32 i;

  p->hbattrs = 0;
  for (i = 0; i < STAT_KINDS; i++) {
    p->armor.bonus[i] = 0;
    p->armor.sideBonus[i] = 0;
  }
  Player_ClearEquipBuff(p, 0x0FFFFFF0);

  if (a == NULL) {
    Player_SetPlttIDs(p);
    p->plttIdx = 0xFFFF;
    return;
  }

  switch (a->effectType) {
    case AET_RES_SOL: {
      p->hbattrs = HBATTR_SOL;
      Player_SetEquipBuff(p, EBUFF_AET_RES_SOL);
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
    case AET_AGILITY: {
      p->armor.bonus[STAT_AGILITY] = a->value;
      break;
    }
    case AET_SOLAR_WIND: {
      Player_SetEquipBuff(p, EBUFF_SOLAR_WIND);
      break;
    }
    case AET_FAIRY_ROBE: {
      Player_SetEquipBuff(p, EBUFF_FAIRY);
      break;
    }
    case AET_EARTHLY_ROBE: {
      Player_SetEquipBuff(p, EBUFF_EARTHLYROBE);
      break;
    }
    case AET_ALLNIGHT: {
      Player_SetEquipBuff(p, EBUFF_ALLNIGHT);
      break;
    }
    case AET_MAGIC_COST: {
      Player_SetEquipBuff(p, EBUFF_MAGICROBE);
      break;
    }
    case AET_SKULL_SUIT: {
      Player_SetEquipBuff(p, EBUFF_SKULLSUIT);
      break;
    }
    case AET_EXP_BOOST: {
      Player_SetEquipBuff(p, EBUFF_TRAININGGEAR);
      break;
    }
    case AET_IMMUNE_POISON: {
      Player_SetEquipBuff(p, EBUFF_IMMUNEPOISON);
      break;
    }
    case AET_WEAPON_GUARD: {
      Player_SetEquipBuff(p, EBUFF_WEAPONGUARD);
      break;
    }
    case AET_SUNLIGHT: {
      Player_SetEquipBuff(p, EBUFF_AET_SUNLIGHT);
      break;
    }
    case AET_NORMAL_DROP: {
      Player_SetEquipBuff(p, EBUFF_AET_NORMAL_DROP);
      break;
    }
    case AET_RARE_DROP: {
      Player_SetEquipBuff(p, EBUFF_AET_RARE_DROP);
      break;
    }
    case AET_PARADE: {
      Player_SetEquipBuff(p, EBUFF_PARADE);
      break;
    }
    case AET_SPIKE: {
      Player_SetEquipBuff(p, EBUFF_SPIKE);
      break;
    }
    case AET_BLACK_ARMOR: {
      Player_SetEquipBuff(p, EBUFF_BLACKARMOR);
      break;
    }
    case AET_MEGA_POWER: {
      Player_SetEquipBuff(p, EBUFF_MEGAPOWER);
      break;
    }
    case AET_GUTS_POWER: {
      Player_SetEquipBuff(p, EBUFF_GUTSPOWER);
      break;
    }
    case AET_PROTO_POWER: {
      Player_SetEquipBuff(p, EBUFF_PROTOPOWER);
      break;
    }
    case AET_TOAD_POWER: {
      Player_SetEquipBuff(p, EBUFF_TOADPOWER);
      break;
    }
    case AET_RAIN_COAT: {
      break;
    }
  }

  Player_SetPlttIDs(p);
  p->plttIdx = 0xFFFF;
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
  if (CheckItemOwn(ITEM_HEART_EMBLEM)) Player_SetEquipBuff(p, EBUFF_HEART);
  if (CheckItemOwn(ITEM_JOKER_EMBLEM)) Player_SetEquipBuff(p, EBUFF_JOKER);
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

  static const u16 sMagicCostsOnCrossOver[MAGIC_NUM] = {
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
  };  // 0x085ABAF0

  if (gGameFlags & GAMEFLAG_CROSSOVER) {
    return sMagicCostsOnCrossOver[id];
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
// Tier A/B は試済 (Player_TestForbidFlags を両枝で呼ぶ形は原典と一致した)
// 原典は TestForbidFlags の結果を r1 に写して判定し, 元の r0 (== 0) を赤ジャンゴの最後の return FALSE にそのまま使う, 追試: switch (p->kind) と return 式 (16 hunk), 末尾を return id == X にする形 (88/88, 16 hunk)
NON_MATCH bool32 Player_IsMagicAvailableForm(Player* p, magic32_t id) {
#ifdef NONMATCHING_C
  s32 cat;

  if (id < 0) {
    return FALSE;
  }

  cat = GetMagicCategory(id);
  if (id <= MAGIC_EARTH) {
    if (Player_TestForbidFlags(p, 2) != 0) {
      return FALSE;
    }
  } else {
    if (Player_TestForbidFlags(p, 4 << (id - MAGIC_TRANSFORM)) != 0) {
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
static magic32_t Player_CheckMagicEnchant(Player* p) {
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
// Player_BurstElementalCond と同じ現象, 宣言を () にしてもプロトタイプありと同じコードになる
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
          p->nextEnchantColorIdx = 0;
        } else {
          m->enchanted = TRUE;
          if (Player_CheckMagicEnchant(p) >= 0) {
            p->enchantStarted = 1;
            p->enchantPlttTimer = 0x20;
            p->nextEnchantColorIdx = id + 1;
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
            p->batHeight = 0xBE;
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
    p->nextEnchantColorIdx = 0;
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
        p->enchantPlttTimer = 32;
        p->enchantPlttID = OBP_ELEMENT(m->id);
        p->nextEnchantColorIdx = m->id + 1;
      }
      return;
    }

    m->enchanted = FALSE;
    p->enchantStarted = 0;
    if (p->enchantPlttID == 0) {
      p->enchantPlttTimer = 0;
    }
  }

  p->nextEnchantColorIdx = p->enchantColorIdx;
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

  if (gGameFlags & GAMEFLAG_CROSSOVER) {
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
  p->nextEnchantColorIdx = m->id + 1;
}

// 生成スクリプトの名前付き引数 'i' を inputIdx に読み込む, 無ければ 0
void Player_ReadInputIdxArg(Player* p) {
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

// 生成スクリプトの名前付き引数 'R' を eventScriptID に読み込む, 無ければ 0
void Player_ReadEventScriptArg(Player* p) {
  if (VM_SeekToNamedArg('R')) {
    p->eventScriptID = VM_GetValue();
  } else {
    p->eventScriptID = 0;
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

  if (gGameFlags & GAMEFLAG_CROSSOVER) {
    s32 i;

    for (i = 0; i < 3; i++) {
      gBadCondTimer[i] = 0;
    }
    p->updateCallback = Player_UpdateCrossoverDjango;
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
      p->facing = DIR8_UP;
    }

    PLAYER_SET_ANIM_8DIR(p, p->facing);

    p->animID = 0;
    MainSprite_SetAnim(&p->human, &p->humanGfx, p->animDir, PLAYMODE_LOOP, 0);
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
  Video_GetAuxSprite(&p->beastGfxs[2], SPRITE_COFFIN_0);
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
  AuxAnim_SetAnim(anim, file, animIdx, p->animDir, p->xflip);

  AuxSprite_AdvanceAnim(sprite, anim);

  p->batHeight = 0xBE;
}

bool32 Player_InitMover(Player* p, u32 moverID) {
  Vec3 pos;
  Vec3 offset;
  Mover* mover;
  s32 kind;
  bool32 result;

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, gStat->playerX, gStat->playerY, gStat->playerZ);
  }
  pos.y = TileHeightAt(&pos);
  Mover_Init(&p->mover, moverID, &pos, 0, (u8)p->inputIdx, p);

  Player_InitSprite(p);
  Player_InitBeastSprite(p);
  kind = p->kind;
  mover = &p->mover;
  switch (kind) {
    case PLAYER_SOLAR_DJANGO:
    case PLAYER_DARK_DJANGO:
    case PLAYER_SABATA: {
      p->useAuxSprite = FALSE;
      Mover_SetMainSprite(mover, &p->human);
      break;
    }
    default: {
      p->useAuxSprite = TRUE;
      Mover_SetAuxSprite(mover, &p->beast);
      break;
    }
  }
  Map_InitMoverTile(&p->tile, &pos);
  Mover_SetCollision(mover, &p->tile, 30, 30);
  offset.x = 0, offset.y = 300, offset.z = 0;
  FUN_0823b47c(mover, &offset);
  p->zoneEvents.id = p->mover.id;
  result = EnemyTargetManager_Add(&p->target, mover, 2);
  gPlayerMoverIDs[p->mover.unk_4] = p->mover.id;
  return result;
}

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

// 鳴り床の上にいるか
bool32 Player_IsOnSoundFloor(u32 attr) {
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

static bool32 UNUSED FUN_08065b08(u32 attr) {
  if ((attr & TATTR_SPECIAL) && TestMapFlag(MPF_WATERFRONT)) {
    return TRUE;
  }
  return FALSE;
}

// すべり床(ツルツルすべる氷)の上にいるか
bool32 Player_IsOnIce(u32 attr) {
  if ((attr & TATTR_SPECIAL) && TestMapFlag(MPF_COLD)) {
    return TRUE;
  }
  return FALSE;
}

// 溶岩タイルに乗ったら, そのタイルの中心を knockbackOrigin にして位置をタイルの内側に収め, 被弾を保留する (エレベーター上と吹き飛ばし中は除く)
void Player_CheckLavaHurt(Player* p) {
  if (Player_IsInLava(GetTileAttrAt(&p->mover.pos)) && p->elevatorFlags == 0 && !p->originKnockback && !Elevator_FindAtPos(&p->mover.pos)) {
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
s32 Player_ApplyOriginHit(Player* p) {
  if (p->kind == PLAYER_SLEEPING) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
  }
  p->originKnockback = TRUE;
  p->hurtbox.knockback = 50;
  Player_SetIframes(p, 60);
  p->blownAway = 0;
  p->floatHeight = 0;
  p->facing = (Angle_ToDir4(ArcTan2_8(p->mover.pos.x - p->knockbackOrigin->x, p->mover.pos.z - p->knockbackOrigin->z)) << 1) + 1;
  PLAYER_SET_ANIM_4DIR(p, p->facing);
  p->hurtSound = SE_IGNITE;
  p->originHitPending = FALSE;
  return 10;
}

// 黒ジャンゴ or Cマウス は水溜まりに触るとダメージを受けてノックバックする
void Player_CheckPuddleHurt(Player* p) {
  if (IsInPuddle(&p->mover.pos) && p->tileKnockback == 0) {
    s32 bx = Mod(p->tile.tileIdx[0], gCollisionMap->tiledata->width);
    s32 bz = Div(p->tile.tileIdx[0], gCollisionMap->tiledata->width);

    p->knockbackTileCenter.x = (bx << 8) + 128;
    p->knockbackTileCenter.z = (bz << 8) + 128;
    p->knockbackOrigin = &p->knockbackTileCenter;
    p->tileHitPending = TRUE;
  }
}

// 今いるタイルから見た knockbackOrigin の方向に向きを合わせ, ノックバック 50 を設定して受けるダメージ 10 を返す (Player_ApplyOriginHit の別版)
// 残差は knockbackOrigin->x - 0x80 の畳み方のみ, 原典はブロック座標 << 8 を先に作ってから knockbackOrigin->x - 0x80 を引くが, agbcc は + 0x80 を結果側へ畳む (Angle_Diff と同じ壁)
// Tier A-C 試済: static inline s32 Diff(s32 a, s32 b) { return a - b; } に (bx << 8, p->knockbackOrigin->x - 0x80) を渡すと ROM まで一致するが, 意味のない inline なので採っていない, ローカルに切り出すと順序が崩れる
NON_MATCH s32 Player_ApplyTileHit(Player* p) {
#ifdef NONMATCHING_C
  s32 bx, bz;

  p->tileKnockback = TRUE;
  p->hurtbox.knockback = 50;
  p->blownAway = 0;
  p->floatHeight = 0;
  bx = Mod(p->tile.tileIdx[1], gCollisionMap->tiledata->width);
  bz = Div(p->tile.tileIdx[1], gCollisionMap->tiledata->width);
  p->facing = (Angle_ToDir4(ArcTan2_8((bx << 8) - (p->knockbackOrigin->x - 0x80), (bz << 8) - (p->knockbackOrigin->z - 0x80))) << 1) + 1;
  PLAYER_SET_ANIM_4DIR(p, p->facing);
  p->hurtSound = SE_IGNITE;
  p->tileHitPending = FALSE;
  return 10;
#else
  INCFUNC("asm/func/Player_ApplyTileHit.inc");
#endif
}

// pos のタイルの高さが p の足元の高さと違うか, タイルに TATTR_UNK_0 が立っていれば真
bool32 Player_IsTileBlockedAt(Player* p, Vec3* pos) {
  if (TileHeightAt(pos) != p->mover.pos.y) {
    return TRUE;
  }
  if (GetTileAttrAt(pos) & TATTR_UNK_0) {
    return TRUE;
  }
  return FALSE;
}

// slideDir が斜めのとき, 進む先の両脇のタイルが段差か壁かを調べて, 塞がっていない側の方向 (1/3/5/7) を返す, 斜めでなければ -1
s32 Player_GetSlideDeflectDir(Player* p) {
  Vec3 pos;

  switch (p->slideDir) {
    case 0: {
      pos = p->mover.pos;
      pos.x -= 30;
      pos.z -= 30;
      pos.x -= 100;
      if (Player_IsTileBlockedAt(p, &pos)) {
        return 1;
      }
      pos.x += 100;
      pos.z -= 100;
      if (Player_IsTileBlockedAt(p, &pos)) {
        return 7;
      }
      pos = p->mover.pos;
      pos.x -= 100;
      if (Player_IsTileBlockedAt(p, &pos)) {
        return 1;
      }
      return 7;
    }
    case 2: {
      pos = p->mover.pos;
      pos.x += 30;
      pos.z -= 30;
      pos.x += 100;
      if (Player_IsTileBlockedAt(p, &pos)) {
        return 1;
      }
      pos.x -= 100;
      pos.z -= 100;
      if (Player_IsTileBlockedAt(p, &pos)) {
        return 3;
      }
      pos = p->mover.pos;
      pos.x += 100;
      if (Player_IsTileBlockedAt(p, &pos)) {
        return 1;
      }
      return 3;
    }
    case 4: {
      pos = p->mover.pos;
      pos.x += 30;
      pos.z += 30;
      pos.x += 100;
      if (Player_IsTileBlockedAt(p, &pos)) {
        return 5;
      }
      pos.x -= 100;
      pos.z += 100;
      if (Player_IsTileBlockedAt(p, &pos)) {
        return 3;
      }
      pos = p->mover.pos;
      pos.x += 100;
      if (Player_IsTileBlockedAt(p, &pos)) {
        return 5;
      }
      return 3;
    }
    case 6: {
      pos = p->mover.pos;
      pos.x -= 30;
      pos.z += 30;
      pos.x -= 100;
      if (Player_IsTileBlockedAt(p, &pos)) {
        return 5;
      }
      pos.x += 100;
      pos.z += 100;
      if (Player_IsTileBlockedAt(p, &pos)) {
        return 7;
      }
      pos = p->mover.pos;
      pos.x -= 100;
      if (Player_IsTileBlockedAt(p, &pos)) {
        return 5;
      }
      return 7;
    }
  }
  return -1;
}

// 氷の床で滑る処理, 歩き・ダッシュ・棺桶引きで氷に乗ると facing の向きに forcedDelta で滑り出し, 氷から出たら止める
void Player_UpdateIceSlide(Player* p) {
  u8* flag = &p->useForcedDelta;

  if (*flag != 0) {
    bool32 onIce = Player_IsOnIce(p->tile.attr[1]);

    if (onIce == FALSE) {
      p->slip_3a5[0] = 0;
      p->slip_3a5[1] = 0;
      *flag = 0;
    } else if (p->tile.unk_0[0] & 1) {
      Dir8U8* dir = &p->slideDir;

      if (*dir & 1) {
        p->slip_3a5[0] = 0;
        p->slip_3a5[1] = 0;
        *flag = 0;
      } else {
        u32 angle;

        *dir = Player_GetSlideDeflectDir(p);
        angle = ((*dir + 5) & 7) << 5;
        p->forcedDelta.x = POLAR_X(10, angle);
        p->forcedDelta.z = POLAR_Z(10, angle);
      }
    } else if (p->slip_3a5[0] == 0) {
      if (p->slip_3a5[1] != 0) {
        PlaySound_082406e0(SE_PLAYER_SLIP);
        p->slip_3a5[0] = 1;
      } else {
        p->slip_3a5[1]++;
      }
    }
  } else {
    u32 angle;

    if (!Player_IsOnIce(p->tile.attr[1])) {
      return;
    }
    if (p->action != PACT_WALK && p->action != PACT_DASH) {
      if (p->action != PACT_PULL_COFFIN) {
        return;
      }
      if ((s16)p->facingHistory[0] < 0) {
        return;
      }
    }
    *flag = 1;
    p->slideDir = p->facing;
    angle = ((p->slideDir + 5) & 7) << 5;
    p->forcedDelta.x = POLAR_X(10, angle);
    p->forcedDelta.z = POLAR_Z(10, angle);
  }
}

// 風に押される, 風下のタイルが足元より高くなければ風の強さぶん mover.delta から引く, 斜め向きは足元の位置で隣のどちらのタイルを見るか選び直す
// 残差はレジスタ割当 (392/392 命令, 49 hunk), タイルは map_inline.h の TileAtIndex で引いて高さを比べる式に直接書くと命令数が揃う, 残りは dir が r4 でなく r6, ofs が r6 でなく r5 に入る点, 宣言順は効かない
NON_MATCH void Player_ApplyWindPush(Player* p) {
#ifdef NONMATCHING_C
  s32 ofs;
  s32 dir;
  s32 cos, sin;

  if (p->action == PACT_WALL) {
    return;
  }
  if (HasGoodCond(p, GOOD_MINI)) {
    return;
  }
  if (Player_TestEquipBuff(p, EBUFF_SOLAR_WIND)) {
    return;
  }
  if (gWindStrength < gWindPushThreshold) {
    return;
  }

  dir = ((gWindAngle + 0x70) & 0xFF) >> 5;
  ofs = 0;
  if (dir & 1) {
    if (dir == 1) {
      ofs = gCollisionMap->tiledata->width;
    } else if (dir == 3) {
      ofs = -1;
    } else if (dir == 5) {
      ofs = -gCollisionMap->tiledata->width;
    } else if (dir == 7) {
      ofs = 1;
    }
    if ((TileAtIndex(p->tile.tileIdx[1])->heightStairs & 0xF) < (TileAtIndex(p->tile.tileIdx[1] + ofs)->heightStairs & 0xF)) {
      return;
    }
    cos = COS((dir + 1) * 32);
    sin = SIN((dir + 1) * 32);
    p->mover.delta.x -= FixToInt(12, gWindStrength * cos);
    p->mover.delta.z -= FixToInt(12, gWindStrength * sin);
  } else {
    s32 x, z;

    if (dir == 0) {
      ofs = gCollisionMap->tiledata->width + 1;
    } else if (dir == 2) {
      ofs = gCollisionMap->tiledata->width - 1;
    } else if (dir == 4) {
      ofs = -gCollisionMap->tiledata->width - 1;
    } else if (dir == 6) {
      ofs = -gCollisionMap->tiledata->width + 1;
    }
    if ((TileAtIndex(p->tile.tileIdx[1])->heightStairs & 0xF) < (TileAtIndex(p->tile.tileIdx[1] + ofs)->heightStairs & 0xF)) {
      return;
    }
    x = p->mover.pos.x & 0xFF;
    z = p->mover.pos.z & 0xFF;
    if (dir == 0) {
      if (x <= z) {
        ofs = gCollisionMap->tiledata->width;
      } else {
        ofs = 1;
      }
    } else if (dir == 2) {
      if (x + z > 256) {
        ofs = gCollisionMap->tiledata->width;
      } else {
        ofs = -1;
      }
    } else if (dir == 4) {
      if (x > z) {
        ofs = -gCollisionMap->tiledata->width;
      } else {
        ofs = -1;
      }
    } else if (dir == 6) {
      if (x + z > 256) {
        ofs = 1;
      } else {
        ofs = -gCollisionMap->tiledata->width;
      }
    }
    if ((TileAtIndex(p->tile.tileIdx[1])->heightStairs & 0xF) < (TileAtIndex(p->tile.tileIdx[1] + ofs)->heightStairs & 0xF)) {
      return;
    }
    cos = COS((dir + 1) * 32);
    sin = SIN((dir + 1) * 32);
    p->mover.delta.x -= FixToInt(12, gWindStrength * cos);
    p->mover.delta.z -= FixToInt(12, gWindStrength * sin);
  }
#else
  INCFUNC("asm/func/Player_ApplyWindPush.inc");
#endif
}

void Player_TakeSunburnDamage(Player* p) {
  Player_EmitBurnSmoke(p);
  p->damage++;
}

// 黒ジャンゴ, バット, マウス が太陽にあたっているときのダメージ処理
// 太陽ゲージから sunburn を貯め、100 たまるごとに Player_TakeSunburnDamage を1回呼ぶ
void Player_StepSunburn(Player* p, s32 sungauge) {
  if (p->noSunburn == 0) {
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
void Player_StepRain(Player* p) {
  if (KAAMOS(p->isSabata) == 0) {
    if (++KAAMOS_PROGRESS(p->isSabata) >= SECOND(600)) {
      KAAMOS_PROGRESS(p->isSabata) = 0;
      KAAMOS(p->isSabata) = SECOND(3000);
      Player_ExecEventScript(p, 0);
    }
  }
  if (TEST_FLAGS(p->equipBuffs, EBUFF_TOADPOWER)) {
    if (++p->toadTick >= 15) {
      p->ene++;
      if (p->ene >= p->maxEne) p->ene = p->maxEne;
      p->toadTick = 0;
    }
  }
}

// 赤ジャンゴ以外(=雨でダメージを受けるもの)が雨に当たっている間、15フレームごとに煙を出してダメージを1増やす
void Player_StepRainDamage(Player* p) {
  if (++p->rainTick >= 15) {
    Vec3 size;
    WorldPos pos;

    if (p->kind == PLAYER_BAT || p->kind == PLAYER_MOUSE) {
      pos = p->beast.pos;
      size.x = Q8(0.125), size.y = Q8(0.125), size.z = Q8(0.125);
    } else {
      pos = p->mover.pos;
      pos.y += Q8(0.625);
      size.x = Q8(0.25), size.y = Q8(0.235), size.z = Q8(0.25);
    }
    EmitSmoke(&pos, 1, &size, 0, 0, 12, 2, 2);
    p->damage++;
    p->rainTick = 0;
  }
}

// 見回しのオフセットを, y の半分を引いた x / z が |z - x| <= 800 かつ |z + x| <= 800 のひし形に収まるよう押し戻す
// 残差はレジスタ割当のみ (84/84), 原典は half を r2, x のアドレスを r1, z の値を r5 に置くが, こちらは half が r1 で z の値がその後を継ぐ
// Tier A-C は試済 (宣言順, Vec3* / s16* ローカル, / 2), 未: 前半と後半を別の変数で持つ形
// 追試: 前半と後半を diff / sum の別変数にする (10 hunk), y を getter inline で読む, x + z の順, x / z のポインタのローカル (71 命令) は不一致
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

// 見回しモードを始める (PACT_WALL 以外), 注視点からプレイヤーへのオフセットを作り, 入力方向があればその分ずらす
void Player_UpdateLookAround(Player* p) {
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
      p->facing = Angle_ToDir8(angle);
      if (p->kind == PLAYER_BAT) {
        s32 quad = Angle_ToDir4(angle);
        if (quad > DIR4_EAST) {
          p->animDir = 3 - quad;
          p->xflip = TRUE;
        } else {
          p->animDir = quad;
          p->xflip = FALSE;
        }
      } else if (p->kind != PLAYER_SLEEPING || p->coffin == 5) {
        Player_SetAnimFacing(p);
      }
    }
  }
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

// 次の行動 val で R の見回しができるかを返す
bool32 Player_CanLookAround(Player* p, s32 val) {
  if (p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) {
    if (val == 0 || val == 3 || val == 6 || (val == 4 && p->wallSidling != 0)) {
      return TRUE;
    }
    return FALSE;
  }
  if (p->kind == PLAYER_SLEEPING) {
    if (val == 0) {
      return TRUE;
    }
    return FALSE;
  }
  if (val == 0 || val == 4) {
    return TRUE;
  }
  return FALSE;
}

// R を押していて見回しできる行動なら見回しを始める・続け, 離したら終える
void Player_HandleLookAround(Player* p, s32 val) {
  if ((p->input->down & R_BUTTON) && Player_CanLookAround(p, val)) {
    if ((p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) && p->action == PACT_WALL) {
      Player_StartLookAround(p);
    } else {
      Player_UpdateLookAround(p);
    }
  } else if (p->lookAroundOffset.val) {
    Player_EndLookAround(p);
  }
  p->unk_3d1 = 1;
}

// 自分の座標とカメラの注視点を 1:4 で混ぜた座標を cameraLookAt に作る
// 残差は y の +150 を置く位置だけ (60対60), 原典は gCameraCoords.worldPos.y * 4 の側のレジスタに足すが, gcc は和の木から定数を括り出して累算器に足してしまう
// Tier A-B は試済 (camera 項を括る, 両辺を括る, (cam+37)*4+2 と書き換える (これは命令が1本増えて定数の位置も合わない)). 150 を素の整数定数で書く限り associate_trees が同じ形に畳む
// << 2, (s16) キャスト, 150 を先頭に置く形, カメラ項をローカルや static inline の引数に出す形も試済 (後の2つはレジスタが崩れる)
NON_MATCH void Player_UpdateCameraLookAt(Player* p) {
#ifdef NONMATCHING_C
  p->cameraLookAt.x = Div(p->mover.pos.x + p->lookAroundOffset.x + gCameraCoords.worldPos.x * 4, 5);
  p->cameraLookAt.y = Div(p->mover.pos.y + p->lookAroundOffset.y + gCameraCoords.worldPos.y * 4 + 150, 5);
  p->cameraLookAt.z = Div(p->mover.pos.z + p->lookAroundOffset.z + gCameraCoords.worldPos.z * 4, 5);
  Camera_LookAt(&p->cameraLookAt);
#else
  INCFUNC("asm/func/Player_UpdateCameraLookAt.inc");
#endif
}

// まとわりついているクロロホルルンを離す (メッセージ 6 を送る)
void Player_ReleaseCuroro(Player* _) {
  u16 payload = 6;

  Enemy_SendMsgByKind(ENEK_CURORO, &payload);
}

// pos に物音を登録し, pos2 があれば音のパーティクルを出して soundID を鳴らす
void Player_MakeNoise(Player* p, Vec3* pos1, s32 param_3, s32 param_4, Vec3* pos2, bool32 fragileWall, SoundID32 soundID) {
  FUN_08240cf0(pos1->x, pos1->z, param_3, 0, param_4, p->mover.id);
  if (pos2 != NULL) {
    Player_ShowNoisePtcl(p, pos2, fragileWall);
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
u32 Player_ResolveStopFacing(Player* p) {
  s32 dir = (s16)p->facingHistory[1];
  s32 next;
  s32 prev;
  s32 i;

  if (dir == -1) {
    return p->facing;
  }
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
  return p->facing;
}

// 立ち止まる (PACT_IDLE), 素立ちのアニメを流す
void Player_UpdateIdle(Player* p) {
  if (p->action != PACT_IDLE) {
    Player_SetAction(p, PACT_IDLE, 0);
    p->facing = Player_ResolveStopFacing(p);
    Player_SetAnimFacing(p);
  }
  p->flag20 &= ~PFLAG20_BUSY;
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

  if (p->emitter.kind == ELEMCOND_HYOKETU && p->emitter.aliveCount != 0) {
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
// 追試: 兄弟の Player_ResolveStopFacing を一致させた早期 return の形, -1 を continue で飛ばす形, next / prev を別の if にする形は不一致
NON_MATCH u32 Player_ResolveInputFacing(Player* p) {
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
  INCFUNC("asm/func/Player_ResolveInputFacing.inc");
#endif
}

// 移動速度から歩きアニメの速さ (Q6, 大きいほど遅い) を出す, 12 で等速
s32 Player_CalcWalkAnimSpeed(s32 val) {
  if (val == 12) {
    return Q6(1);
  }
  if (val <= 11) {
    return (12 - val) * 8 + Q6(1);
  } else {
    return Q6(1) - (val - 12) * 4;
  }
}

// 足音を鳴らす, 水たまり・音の鳴る床では物音も出し, 小さい時・階段で音を変える
void Player_PlayFootstep(Player* p, u32 val) {
  if ((p->human.animCmdIdx & 3) != 0 || p->human.animCmdTimer != 0) {
    return;
  }

  if (HasGoodCond(p, GOOD_NINJA)) {
    return;
  }

  if (IsInPuddle(&p->mover.pos)) {
    if (p->human.animCmdIdx == 0) {
      Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_PUDDLE_1);
    } else {
      Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_PUDDLE_0);
    }
    return;
  }

  if (Player_IsOnSoundFloor(p->tile.attr[1]) && !HasGoodCond(p, GOOD_MINI)) {
    if (p->human.animCmdIdx == 0) {
      Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_NOISE_1);
    } else {
      Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_NOISE_0);
    }
    return;
  }

  if (val == 0) {
    if (HasGoodCond(p, GOOD_MINI)) {
      if (p->human.animCmdIdx == 0) {
        PlaySound_082406e0(SE_FSTEP_MINI_1);
      } else {
        PlaySound_082406e0(SE_FSTEP_MINI_0);
      }
    } else if (p->elevatorFlags != 0 || p->tile.stairs[1] == 0) {
      if (p->human.animCmdIdx == 0) {
        PlaySound_082406e0(SE_FSTEP_M_1);
      } else {
        PlaySound_082406e0(SE_FSTEP_M_0);
      }
    } else if (p->human.animCmdIdx == 0) {
      PlaySound_082406e0(SE_FSTEP_STAIRS_1);
    } else {
      PlaySound_082406e0(SE_FSTEP_STAIRS_0);
    }
  }

  if (TestMapFlag(MPF_UNK_0)) {
    Player_MakeNoise(p, &p->mover.pos, 1, 2, NULL, 0, SONG_NONE);
  }
}

// 歩き始めるときの初期化, 移動速度とアニメを設定する
void Player_UpdateWalk(Player* p) {
  p->action = PACT_WALK;
  p->flag20 &= ~PFLAG20_BUSY;
  p->facing = Player_ResolveInputFacing(p);
  if (p->useForcedDelta == 0) {
    s32 val = CalcMoveSpeed(p);
    bool32 scaled;
    u16 n;

    Player_CalcWalkAnimSpeed(val);
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
  Player_PlayFootstep(p, 0);
  Player_SetAnimFacing(p);
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(1));
}

// 魔法"ダッシュ" 前方に高速で移動する魔法 (太陽ゲージの量に応じて移動速度が変化)
void MagicDash_Update(Player* p) {
  if (p->action != PACT_DASH) {
    if (Player_HasEnoughSunGauge(p, 1)) {
      PlaySound_082406e0(SE_M_DASH);
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
          p->flashPlttID = 293;
          p->plttFlashTimer = 32;
        }
        if ((s16)p->facingHistory[0] != -1 && p->lookAroundOffset.val == 0) {
          p->facing = Player_ResolveInputFacing(p);
        }
        Player_SetMoveDelta(p, p->dashSpeed);
        Player_PlayFootstep(p, 1);
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
// 追試: u32 で受けて &= 0xFF, 分岐の中で & 0xFF, 三項演算子, (u8)pos で比べる (22命令だが ands が消える) はいずれも不一致
NON_MATCH bool32 Player_IsNearTileCenter(Player* p) {
#ifdef NONMATCHING_C
  u16 pos;
  u32 ofs;

  if (p->actionDir == DIR8_UP_RIGHT || p->actionDir == DIR8_DOWN_LEFT) {
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

// 壁に張り付く (PACT_WALL), state 1 で壁沿いに横歩きし, 壁の上へ登れる所では登り, A で壁を叩いて音を出す
void Player_UpdateWall(Player* p) {
  u32 animIdx;

  p->action = PACT_WALL;
  if (p->state == 1 && (p->input->pressed & A_BUTTON)) {
    Player_SetAction(p, PACT_WALL, 2);
  }

  switch (p->state) {
    case 0: {
      Player_SetFlag20(p, PFLAG20_UNK_2);
      animIdx = Player_GetAnimIdx(p->kind, 2);
      if (p->animID != animIdx) {
        PlaySound_082406e0(SE_COVER);
        p->facing = (p->actionDir + 4) & 7;
        PLAYER_SET_ANIM_4DIR(p, p->actionDir);
      }
      if (Player_PlayAnim(p, animIdx, Q6(1))) {
        Player_SetAction(p, PACT_WALL, 1);
      }
      break;
    }
    case 1: {
      s32 dir;
      s32 left;
      s32 right;

      Player_SetFlag20(p, PFLAG20_WALL_COVER);
      p->wallSidling = 1;
      dir = (s16)p->facingHistory[0];
      left = (p->actionDir + 7) & 7;
      right = (p->actionDir + 1) & 7;
      animIdx = Player_GetAnimIdx(p->kind, 3);
      if (dir != left && dir != right) {
        if (Player_IsNearTileCenter(p) && MovableBlock_PushAtDir8(&p->mover.pos, p->facing) > 0) {
          if (HasGoodCond(p, GOOD_POWER)) {
            Player_SetAction(p, PACT_IDLE, 0);
          } else {
            Player_SetAction(p, PACT_PUSH, 0);
            p->wallSidling = 0;
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
        if (height > p->mover.pos.y - Q8(0.5) && height < p->mover.pos.y + Q8(0.5)) {
          MapTileOverride* ov = Map_FindTileOverride(idx, 1);
          CollisionMapTile* tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[idx];

          if (!Player_IsOnIce(tile->attr)) {
            pos.x -= POLAR_X(50, ((p->actionDir + 1) & 7) << 5);
            pos.z -= POLAR_Z(50, ((p->actionDir + 1) & 7) << 5);
            if (TileHeightAt(&pos) >= height + Q8(0.782) && !(GetTileAttrAt(&pos) & TATTR_UNK_2)) {
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
        PlaySound_082406e0(SE_WALL_SLIDE);
      }
      break;
    }
    case 2: {
      Player_SetFlag20(p, PFLAG20_WALL_COVER);
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 5), Q6(1))) {
        Vec3 effectPos = p->mover.pos;
        Vec3 doorPos = p->mover.pos;
        Vec3 wallPos;

        if (p->actionDir == DIR8_UP_RIGHT) {
          effectPos.x += 28, effectPos.y += 44, effectPos.z -= 76;
          doorPos.x += 64, doorPos.z -= 128;
        } else if (p->actionDir == DIR8_DOWN_RIGHT) {
          effectPos.x -= 52, effectPos.y += 0, effectPos.z += 0;
          doorPos.x += 128, doorPos.z += 64;
        } else if (p->actionDir == DIR8_DOWN_LEFT) {
          effectPos.x += 12, effectPos.y += 44, effectPos.z -= 32;
          doorPos.x += 64, doorPos.z += 128;
        } else if (p->actionDir == DIR8_UP_LEFT) {
          effectPos.x -= 64, effectPos.y += 68, effectPos.z += 44;
          doorPos.x -= 128, doorPos.z += 64;
        }
        wallPos = p->mover.pos;
        wallPos.x -= POLAR_X(50, ((p->actionDir + 1) & 7) << 5);
        wallPos.z -= POLAR_Z(50, ((p->actionDir + 1) & 7) << 5);
        if (GetTileAttrAt(&wallPos) & TATTR_FRAGILE) {
          Player_MakeNoise(p, &p->mover.pos, 256, 1, &effectPos, 1, SE_WALL_KNOCK_FRAGILE);
        } else {
          Player_MakeNoise(p, &p->mover.pos, 256, 1, &effectPos, 0, SE_WALL_KNOCK);
        }
        if (FUN_08020358(GetCollisionTileIdx(&doorPos))) {
          PlaySound_082406e0(SE_DOOR_LOCKED);
        }
        Player_SetAction(p, PACT_WALL, 1);
      }
      break;
    }
  }
}

// ブロックを押す (PACT_PUSH), actionDir へ 64 フレーム押し進め, 押し続けていて先へ進めるならもう一度, ちからの実が効いていれば素立ちに戻る
void Player_UpdatePush(Player* p) {
  switch (p->state) {
    case 0: {
      s32 angle = ((p->actionDir + 5) & 7) * 32;
      p->mover.delta.x = POLAR_X(4, angle);
      p->mover.delta.z = POLAR_Z(4, angle);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 6), Q6(1));
      if (++p->stateTimer > 63) {
        Player_SetAction(p, PACT_PUSH, 1);
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 6), Q6(1));
      if ((s16)p->facingHistory[0] == p->actionDir && MovableBlock_PushAtDir8(&p->mover.pos, p->facing) > 0) {
        if (HasGoodCond(p, GOOD_POWER)) {
          Player_SetAction(p, PACT_IDLE, 0);
        } else {
          Player_SetAction(p, PACT_PUSH, 0);
        }
      } else {
        Player_SetAction(p, PACT_PUSH, 2);
      }
      break;
    }
    case 2: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 7), Q6(1))) {
        Player_SetAction(p, PACT_WALL, 1);
        p->wallSidling = 0;
      }
      break;
    }
  }
}

// 日光に当たっていて ENE が満タンでなければ TRUE
bool32 Player_CanSolarCharge(Player* p) {
  if (Player_TestFlag20(p, PFLAG20_SUNBATHING) && p->ene < p->maxEne) {
    return TRUE;
  }
  return FALSE;
}

void Player_SetChargePos(Player* p) {
  p->chargePos = p->mover.pos;
  if (p->facing == DIR8_DOWN) {
    p->chargePos.x -= Q8(0.08);
    p->chargePos.y += Q8(1.29);
    p->chargePos.z += Q8(0.235);
  } else {
    p->chargePos.x += Q8(0.08);
    p->chargePos.y += Q8(1.29);
    p->chargePos.z -= Q8(0.12);
  }
}

// 太陽チャージ (PACT_UNK_7), 構えたあと A を押し続けている間, 日光が当たっていて ENE が満タンでなければチャージ音を鳴らして光の粒を出す
void Player_UpdateSolarCharge(Player* p) {
  if (p->action != PACT_UNK_7) {
    Player_SetAction(p, PACT_UNK_7, 0);
    p->nextEnchantColorIdx = 0;
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
          p->facing = DIR8_DOWN;
          p->animDir = 1;
          p->xflip = FALSE;
        } else {
          p->facing = 0;
          p->animDir = 0;
          p->xflip = FALSE;
        }
        Player_SetChargePos(p);
        p->stateTimer++;
      }
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        PlaySound_082406e0(SE_PALM);
        if (!(p->input->down & A_BUTTON)) {
          Player_SetAction(p, PACT_UNK_7, 4);
        } else if (Player_CanSolarCharge(p)) {
          PlaySound_082406e0(NOISE_SOLAR_CHARGE);
          p->chargeSoundOn = 1;
          p->chargeVoiceTimer = 0;
          Player_SetAction(p, PACT_UNK_7, 2);
        } else {
          p->chargeVoiceTimer = 0;
          Player_SetAction(p, PACT_UNK_7, 3);
        }
      }
      break;
    }
    case 2: {
      Player_SetFlag20(p, PFLAG20_QC | PFLAG20_PALM_UP);
      if (p->chargeVoiceTimer < 5) {
        if (++p->chargeVoiceTimer == 5) {
          if (p->kind == PLAYER_DARK_DJANGO) {
            PlaySound_082406e0(VO_BDJANGO_TAIYO);
          } else {
            PlaySound_082406e0(VO_RDJANGO_TAIYO);
          }
        }
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 9), Q6(1));
      p->shadowOffset.z = 30;
      Player_SetChargePos(p);
      Player_SpawnSolarChargePtcl(p, &p->chargePos);
      if (!(p->input->down & A_BUTTON)) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->chargeSoundOn = 0;
        Player_SetAction(p, PACT_UNK_7, 4);
      } else if (!Player_CanSolarCharge(p)) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->chargeSoundOn = 0;
        Player_SetAction(p, PACT_UNK_7, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag20(p, PFLAG20_PALM_UP);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      p->shadowOffset.z = 30;
      if (!(p->input->down & A_BUTTON)) {
        Player_SetAction(p, PACT_UNK_7, 4);
      } else if (Player_CanSolarCharge(p)) {
        PlaySound_082406e0(NOISE_SOLAR_CHARGE);
        p->chargeSoundOn = 1;
        p->chargeVoiceTimer = 0;
        Player_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 4: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        p->animDir = p->facing;
        p->xflip = FALSE;
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 日光に当たっておらず ENE が満タンでなければ TRUE
bool32 Player_CanDarkCharge(Player* p) {
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
          p->facing = DIR8_DOWN;
          p->animDir = 1;
          p->xflip = FALSE;
        } else {
          p->facing = 0;
          p->animDir = 0;
          p->xflip = FALSE;
        }
        Player_SetChargePos(p);
        p->stateTimer++;
      }
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        PlaySound_082406e0(SE_PALM);
        if (!(p->input->down & A_BUTTON)) {
          Player_SetAction(p, PACT_UNK_7, 4);
        } else if (Player_CanDarkCharge(p)) {
          PlaySound_082406e0(VO_SABATA_ANKOKU);
          p->chargeSoundOn = 1;
          p->chargeVoiceTimer = 0;
          Player_SetAction(p, PACT_UNK_7, 2);
        } else {
          p->chargeVoiceTimer = 0;
          Player_SetAction(p, PACT_UNK_7, 3);
        }
      }
      break;
    }
    case 2: {
      Player_SetFlag20(p, PFLAG20_QC | PFLAG20_PALM_UP);
      if (p->chargeVoiceTimer < 5) {
        if (++p->chargeVoiceTimer == 5) {
          PlaySound_082406e0(NOISE_DARK_CHARGE);
        }
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 9), Q6(1));
      p->shadowOffset.z = 30;
      Player_SetChargePos(p);
      Player_SpawnDarkChargePtcl(p, &p->chargePos);
      p->flashPlttID = OBP_ELEMENT(1);
      if (p->stateTimer < 32) {
        p->plttFlashTimer = p->stateTimer;
      } else {
        p->plttFlashTimer = 64 - p->stateTimer;
      }
      if (++p->stateTimer > 64) {
        p->stateTimer = 0;
      }
      if (!(p->input->down & A_BUTTON)) {
        sound_08240740(NOISE_DARK_CHARGE);
        p->chargeSoundOn = 0;
        Player_SetAction(p, PACT_UNK_7, 4);
      } else if (!Player_CanDarkCharge(p)) {
        sound_08240740(NOISE_DARK_CHARGE);
        p->chargeSoundOn = 0;
        Player_SetAction(p, PACT_UNK_7, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag20(p, PFLAG20_PALM_UP);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      p->shadowOffset.z = 30;
      if (!(p->input->down & A_BUTTON)) {
        Player_SetAction(p, PACT_UNK_7, 4);
      } else if (Player_CanDarkCharge(p)) {
        PlaySound_082406e0(NOISE_DARK_CHARGE);
        p->chargeSoundOn = 1;
        p->chargeVoiceTimer = 0;
        Player_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 4: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        p->animDir = p->facing;
        p->xflip = FALSE;
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 太陽スタンドを使う (PACT_REFUELING), refuelPos まで歩いて refuelFacing を向き, A を押している間スタンドの貯金から ENE を受け取る
void Player_UpdateSolarStand(Player* p) {
  switch (p->state) {
    case 0: {
      s32 dx = p->refuelPos.x - p->mover.pos.x;
      s32 dz = p->refuelPos.z - p->mover.pos.z;
      s32 speed = CalcMoveSpeed(p);

      p->nextEnchantColorIdx = 0;
      if (dx * dx + dz * dz <= speed * speed) {
        p->mover.delta.x = dx;
        p->mover.delta.z = dz;
        p->facing = p->refuelFacing;
        Player_SetAnimFacing(p);
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
        if (IS_8DIR_LEFT(p->facing)) {
          p->animDir = 0;
          p->xflip = TRUE;
        } else {
          p->animDir = 0;
          p->xflip = FALSE;
        }
        Player_SetAction(p, PACT_REFUELING, 1);
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
        PlaySound_082406e0(SE_PALM);
        if (!(p->input->down & A_BUTTON)) {
          Player_SetAction(p, PACT_REFUELING, 4);
        } else if (p->kind == PLAYER_SABATA) {
          PlaySound_082406e0(SE_SOLAR_STAND_DENY);
          Player_SetAction(p, PACT_REFUELING, 3);
        } else if (p->ene >= p->maxEne) {
          PlaySound_082406e0(SE_DENY_302);
          Player_SetAction(p, PACT_REFUELING, 3);
        } else if (gStat->solarStand > 0) {
          PlaySound_082406e0(NOISE_SOLAR_CHARGE);
          p->chargeSoundOn = 1;
          Player_SetAction(p, PACT_REFUELING, 2);
        } else {
          PlaySound_082406e0(SE_SOLAR_STAND_DENY);
          Player_SetAction(p, PACT_REFUELING, 3);
        }
      }
      break;
    }
    case 2: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 13), Q6(1));
      if (!(p->input->down & A_BUTTON)) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->chargeSoundOn = 0;
        Player_SetAction(p, PACT_REFUELING, 4);
      } else if (p->ene >= p->maxEne) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->chargeSoundOn = 0;
        PlaySound_082406e0(SE_DENY_302);
        Player_SetAction(p, PACT_REFUELING, 3);
      } else if (gStat->solarStand <= 0) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->chargeSoundOn = 0;
        PlaySound_082406e0(SE_SOLAR_STAND_DENY);
        Player_SetAction(p, PACT_REFUELING, 3);
      } else {
        Player_SetFlag20(p, PFLAG20_REFUELING);
      }
      break;
    }
    case 3: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 14), Q6(1));
      if (!(p->input->down & A_BUTTON)) {
        Player_SetAction(p, PACT_REFUELING, 4);
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
    p->nextEnchantColorIdx = 0;
    if (Player_HasEnoughEne(p, 100) && gSunMagicUsed == 0) {
      p->magicFired = TRUE;
    } else {
      p->magicFired = FALSE;
    }
    Player_SetAction(p, PACT_SUN_MAGIC, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->facing >= DIR8_RIGHT && p->facing <= DIR8_LEFT) {
        p->facing = DIR8_DOWN;
        p->animDir = 4;
        p->xflip = FALSE;
        p->chargePos = p->mover.pos;
        p->chargePos.x -= Q8(0.08);
        p->chargePos.y += Q8(1.29);
        p->chargePos.z += Q8(0.235);
      } else {
        p->facing = DIR8_UP;
        p->animDir = 0;
        p->xflip = FALSE;
        p->chargePos = p->mover.pos;
        p->chargePos.x += Q8(0.08);
        p->chargePos.y += Q8(1.29);
        p->chargePos.z -= Q8(0.08);
      }

      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      if (p->facing == DIR8_DOWN) {
        p->animDir = 1;
      } else {
        p->animDir = 0;
      }

      if (p->magicFired) {
        PlaySound_082406e0(VO_RDJANGO_TAIYO);
        p->flashPlttID = OBP_ELEMENT(0);
        p->plttFlashTimer = 2;
        RisingSunEffect_Create(p, &p->mover.pos, &p->chargePos, 0, p->unk_3ba);
      }

      Player_SetAction(p, PACT_SUN_MAGIC, 1);
      break;
    }
    case 1: {
      if (p->magicFired) {
        p->flashPlttID = OBP_ELEMENT(0);
        p->plttFlashTimer += 3;
        if (p->plttFlashTimer > 32) {
          p->plttFlashTimer = 32;
        }
      }

      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        PlaySound_082406e0(SE_PALM);
        if (p->magicFired && p->unk_3ba == 0) {
          gSunMagicUsed = 1;
        }
        Player_SetAction(p, PACT_SUN_MAGIC, 2);
      }
      break;
    }
    case 2: {
      if (p->magicFired) {
        p->flashPlttID = OBP_ELEMENT(0);
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
  if (p->emitter.kind == ELEMCOND_HYOKETU && p->emitter.aliveCount != 0) speed -= 3;
  if (p->speedPenalty != 0) speed -= p->speedPenalty;

  if (speed < 2) {
    speed = 2;
  }
  return speed;
}

// pos のタイルへ移れるか (壁でない, 溶岩や水でない, 段差が1ブロック未満), TATTR_UNK_11 のタイルなら pos を棺桶の位置に差し替え, 棺桶から離れていれば立ち止まる
bool32 Player_CanPullCoffinTo(Player* p, Vec3* pos) {
  TileAttr attr = GetTileAttrAt(pos);
  WorldPos* coffin;

  if (attr & TATTR_UNK_0) {
    return FALSE;
  }
  if (!FUN_08086958() && (Player_IsInLava(attr) || (attr & TATTR_FALLDEATH))) {
    return FALSE;
  }
  if (abs(TileHeightAt(pos) - p->mover.pos.y) >= Q8(1)) {
    return FALSE;
  }
  if (!(attr & TATTR_UNK_11)) {
    return TRUE;
  }
  coffin = Coffin_GetPos();
  if (abs(coffin->x - p->mover.pos.x) >= Q8(1) || abs(coffin->z - p->mover.pos.z) >= Q8(1)) {
    PlaySound_082406e0(SE_COFFIN_CHAIN);
    Player_SetAction(p, PACT_IDLE, 0);
  }
  *pos = *coffin;
  return TRUE;
}

// 棺桶を引く間, 棺桶とのあいだが半径 param_4 を超えたら棺桶を引き寄せる位置を決める, 移れないタイルなら今のタイルの縁に寄せ, 高さを合わせて FUN_08086590 に渡す
void Player_UpdateCoffinTarget(Player* p, s32 cos, s32 sin, s32 param_4) {
  s32 ox = FixToInt(12, cos * 70);
  s32 oz = FixToInt(12, sin * 70);
  WorldPos* coffin = Coffin_GetPos();
  s32 dx = coffin->x - p->mover.pos.x - ox;
  s32 dz = coffin->z - p->mover.pos.z - oz;
  Vec3 pos;
  s32 angle;
  u16 dir;

  if (dx * dx + dz * dz <= param_4 * param_4) {
    return;
  }
  angle = ArcTan2_8(dx, dz);
  pos.x = p->mover.pos.x + POLAR_X(param_4, angle) + ox;
  pos.z = p->mover.pos.z + POLAR_Z(param_4, angle) + oz;
  pos.x = (coffin->x * 3 + pos.x) >> 2;
  pos.z = (coffin->z * 3 + pos.z) >> 2;
  if (!Player_CanPullCoffinTo(p, &pos)) {
    s32 cur = GetCollisionTileIdx(&p->mover.pos);
    s32 dst = GetCollisionTileIdx(&pos);

    if (cur == dst + 1) {
      pos.x = (s8)(p->mover.pos.x >> 8) * Q8(1) + 2;
    } else if (cur == dst - 1) {
      pos.x = ((s8)(p->mover.pos.x >> 8) + 1) * Q8(1) - 2;
    } else if (cur == dst + gCollisionMap->tiledata->width) {
      pos.z = (s8)(p->mover.pos.z >> 8) * Q8(1) + 2;
    } else if (cur == dst - gCollisionMap->tiledata->width) {
      pos.z = ((s8)(p->mover.pos.z >> 8) + 1) * Q8(1) - 2;
    } else {
      pos.x = p->mover.pos.x;
      pos.z = p->mover.pos.z;
    }
    if (!FUN_08086958()) {
      pos.y = TileHeightAt(&pos);
    }
  } else {
    if (!FUN_08086958()) {
      pos.y = TileHeightAt(&pos);
    }
  }
  dx = p->mover.pos.x - pos.x;
  dz = p->mover.pos.z - pos.z;
  dir = ArcTan2_8(dx, dz);
  FUN_08086590(&pos, Angle_ToDir8(dir));
}

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
  p->flag20 &= ~PFLAG20_BUSY;
  if ((s16)p->facingHistory[0] < 0 || p->lookAroundOffset.val != 0) {
    s32 angle;

    animIdx = Player_GetAnimIdx(p->kind, 16);
    angle = (((p->useForcedDelta ? p->slideDir : p->facing) + 1) & 7) << 5;
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
    p->facing = Player_ResolveInputFacing(p);
    Player_SetAnimFacing(p);
    if (p->useForcedDelta) {
      animSpeed = Q6(0.5);
      angle = ((p->slideDir + 1) & 7) << 5;
      cos = COS(angle);
      sin = SIN(angle);
    } else {
      if (speed == 8) {
        animSpeed = Q6(1);
      } else if (speed < 8) {
        animSpeed = (8 - speed) * 8 + Q6(1);
      } else {
        animSpeed = Q6(1) - (speed - 8) * 4;
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
    if (IsInPuddle(&p->mover.pos)) {
      if (p->human.animCmdIdx == 0) {
        Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_PUDDLE_1);
      } else {
        Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_PUDDLE_0);
      }
    } else if (Player_IsOnSoundFloor(p->tile.attr[1]) && !HasGoodCond(p, GOOD_MINI)) {
      if (p->human.animCmdIdx == 0) {
        Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_NOISE_1);
      } else {
        Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_NOISE_0);
      }
    } else {
      if (p->elevatorFlags != 0 || p->tile.stairs[1] == 0) {
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
        Player_MakeNoise(p, &p->mover.pos, 1, 2, NULL, 0, SONG_NONE);
      }
    }
  }
  Player_PlayAnim(p, animIdx, animSpeed);
  if (moving || p->useForcedDelta) {
    Player_UpdateCoffinTarget(p, cos, sin, 150);
  }
}

// ジャンゴの攻撃 (PACT_ATTACK), 武器ごとの attackCB を呼ぶ
void Player_UpdateDjangoAttack(Player* p) {
  if (p->action != PACT_ATTACK) {
    Player_SetAction(p, PACT_ATTACK, 0);
  }
  p->attackCB(p);
}

// 石化 (PACT_SEKIKA), 石化の粒が消えたら PACT_IDLE に戻る
void Player_UpdatePetrified(Player* p) {
  p->flag20 &= ~PFLAG20_BUSY;
  if (p->emitter.aliveCount == 0) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// クモの巣に捕まっている間 (PACT_SPIDER_WEB), 入力方向へ向き直るたびに連打カウンタに応じて効果音を鳴らし, spiderWebIdx が空けば素立ちに戻る
void Player_UpdateSpiderWeb(Player* p) {
  if ((s16)p->facingHistory[0] >= 0 && p->facing != (s16)p->facingHistory[0]) {
    if (p->mashCount & 1) {
      if ((p->mashCount >> 1) & 1) {
        Player_MakeNoise(p, &p->mover.pos, 1, 1, NULL, 0, SE_SPIDER_WEB_STRUGGLE_0);
      } else {
        Player_MakeNoise(p, &p->mover.pos, 1, 1, NULL, 0, SE_SPIDER_WEB_STRUGGLE_1);
      }
    }
    p->facing = p->facingHistory[0];
    Player_SetAnimFacing(p);
  }
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
  if (p->spiderWebIdx < 0) {
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
        p->flashPlttID = 292;
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
      p->flashPlttID = 292;
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
      HealingEffect_Create(p, &pos);
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
        p->flashPlttID = 294;
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
      p->flashPlttID = 294;
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
    if (p->elevatorFlags != 0) {
      p->magicFired = FALSE;
    } else if (Player_HasEnoughSunGauge(p, 3)) {
      p->magicFired = TRUE;
      DynamiteEffect_Create(p, &p->mover.pos, 0);
    } else {
      p->magicFired = FALSE;
    }
    Player_SetAction(p, PACT_DYNAMITE, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->magicFired) {
        p->flashPlttID = 291;
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
        p->flashPlttID = 291;
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
      if (p->mashRecoverTimer > n) {
        p->mashRecoverTimer -= n;
      } else {
        p->mashRecoverTimer = 0;
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

// 人型の落下 (PACT_FALL), カメラを上に向けて落下アニメを当て, 6フレーム後に沈み始めて途中で声を上げ, 30 フレームで消える
void Player_UpdateFall(Player* p) {
  Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
  switch (p->state) {
    case 0: {
      Vec3 pos = p->mover.pos;

      pos.y += 150;
      Camera_LookAt(&pos);
      if (p->fallFadeMode != 0) {
        StartBgObjPlttFade(3, 3, 4, 4, 4, 0x1FFF, 16);
      } else {
        StartBgObjPlttFade(3, 3, 4, 4, 4, 0x1FFF, 1);
      }
      PlaySound_082406e0(SE_FALL_SURPRISE);
      PLAYER_SET_ANIM_4DIR(p, p->facing);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
      Player_SetAction(p, PACT_FALL, 1);
      p->floatHeight = 0;
      break;
    }
    case 1: {
      if (++p->stateTimer > 5) {
        Player_SetAction(p, PACT_FALL, 2);
        p->floatHeight = 0;
        p->beast.priority = 1;
        PlaySound_082406e0(SE_FALL_430);
      }
      break;
    }
    case 2: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 18), Q6(1));
      p->floatHeight -= 60;
      if (p->stateTimer == 4) {
        if (p->kind == PLAYER_SABATA) {
          PlaySound_082406e0(VO_SABATA_PITFALL);
        } else {
          PlaySound_082406e0(VO_DJANGO_PITFALL);
        }
      }
      if (++p->stateTimer > 29) {
        Player_SetAction(p, PACT_FALL, 3);
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

// PACT_LANDING の行動, heightAboveTile を毎フレーム 30 ずつ減らして落下し, 着地したら着地アニメを経て PACT_IDLE に戻る
void Player_UpdateLanding(Player* p) {
  Player_SetFlag35a(p, 8);
  switch (p->state) {
    case 0: {
      if (p->animID != 44) {
        p->facing |= 1;
        PLAYER_SET_ANIM_4DIR(p, p->facing);
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 18), Q6(1));
      if ((u16)p->heightAboveTile <= 30) {
        p->heightAboveTile = 0;
        PlaySound_082406e0(SE_LANDING);
        Player_SetAction(p, PACT_LANDING, 1);
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

// PACT_GRABBED
void Player_UpdateGrabbed(Player* p) {
  if (p->grabbedVisible != 0) {
    Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW | PFLAG35A_NO_HURTBOX | PFLAG35A_NO_TILE);
  } else {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW | PFLAG35A_NO_HURTBOX | PFLAG35A_NO_TILE);
  }
  Player_SetFlag20(p, PFLAG20_UNK_12 | PFLAG20_UNK_8);
}

// PACT_DAMAGED, 吹き飛びながら knockbackOrigin やタイルから弾かれたときはそちらへ寄せて炎か煙を出し, 止まったら起き上がって PACT_SEKIKA か PACT_IDLE に戻る
void Player_UpdateHurt(Player* p) {
  if (p->action != PACT_DAMAGED) {
    Player_SetAction(p, PACT_DAMAGED, 0);
    PLAYER_SET_ANIM_4DIR(p, p->facing);
    Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
    p->floatHeight = 0;
    if (p->hurtSound != SONG_NONE) {
      PlaySound_082406e0(p->hurtSound);
      p->hurtSound = SONG_NONE;
    }
  }
  if (p->hurtbox.knockback != 0) {
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

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockback);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockback);
    }
    Camera_Shake(p->hurtbox.knockback);
    p->hurtbox.knockback = (p->hurtbox.knockback * 3) >> 2;
  } else {
    p->hurtbox.knockback = 0;
    p->originKnockback = FALSE;
    p->tileKnockback = FALSE;
    if (p->emitter.kind == ELEMCOND_SEKIKA && p->emitter.aliveCount != 0) {
      Player_SetAction(p, PACT_SEKIKA, 0);
    } else if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 42), Q6(1))) {
      Player_SetAnimFacing(p);
      Player_SetAction(p, PACT_IDLE, 0);
    }
  }
}

// PACT_BLOWN_AWAY, 宙に浮いて後ろへ飛び, 着地して倒れたあと起き上がって PACT_IDLE に戻る
void Player_UpdateBlownAway(Player* p) {
  if (p->action != PACT_BLOWN_AWAY) {
    Player_SetAction(p, PACT_BLOWN_AWAY, 0);
    PLAYER_SET_ANIM_4DIR(p, p->facing);
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
      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockback);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockback);
      p->hurtbox.knockback = (p->hurtbox.knockback * 3) >> 2;
      if (p->stateTimer > 3) {
        if (p->floatHeight >= p->stateTimer * 8) {
          p->floatHeight -= p->stateTimer * 8;
        } else {
          p->floatHeight = 0;
        }
      }
      p->stateTimer++;
      if (p->hurtbox.knockback < 20 && p->floatHeight == 0) {
        p->floatHeight = 0;
        PlaySound_082406e0(SONG_680);
        Player_SetAction(p, PACT_BLOWN_AWAY, 2);
      }
      break;
    }
    case 2: {
      s32 angle = ((p->facing + 5) & 7) << 5;

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockback);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockback);
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 44), Q6(1))) {
        p->hurtbox.knockback = 0;
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

// 倒れて死ぬ (PACT_DEATH_PRONE), ノックバックが収まるまで後ろへ流され, 倒れるアニメのあとゲームオーバーへ移って点滅しながら消える
void Player_UpdateDeath(Player* p) {
  if (p->action != PACT_DEATH_PRONE) {
    Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
    p->knockbackTimer = 0;
    PLAYER_SET_ANIM_4DIR(p, p->facing);
    Player_SetAction(p, PACT_DEATH_PRONE, 0);
    if (p->kind == PLAYER_SABATA) {
      PlaySound_082406e0(VO_SABATA_DEATH);
    } else {
      PlaySound_082406e0(VO_DJANGO_DEATH);
    }
    PlaySound_082406e0(SE_DAMAGE);
    if (gGameFlags & GAMEFLAG_CROSSOVER) CrossoverBattle_NotifyPlayerDead();
  }

  switch (p->state) {
    case 0: {
      s32 angle = ((p->facing + 1) & 7) << 5;

      p->mover.delta.x = FixToInt(12, COS(angle) * p->hurtbox.knockback);
      p->mover.delta.z = FixToInt(12, SIN(angle) * p->hurtbox.knockback);
      p->hurtbox.knockback = (p->hurtbox.knockback * 3) >> 2;
      if (p->hurtbox.knockback == 0) {
        Player_SetAction(p, PACT_DEATH_PRONE, 1);
      }
      break;
    }
    case 1: {
      if (p->human.animCmdIdx == 3 && p->human.animCmdTimer == 0) {
        PlaySound_082406e0(SONG_209);
      }
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 46), Q6(1))) {
        if (!(gGameFlags & GAMEFLAG_CROSSOVER)) {
          Player_SetAction(p, PACT_DEATH_PRONE, 2);
        } else {
          Player_SetAction(p, PACT_DEATH_PRONE, 3);
        }
      }
      break;
    }
    case 2: {
      if (++p->stateTimer > 15) {
        gGameFlags |= GAMEFLAG_GAMEOVER;
        Player_SetAction(p, PACT_DEATH_PRONE, 3);
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
        Player_SetAction(p, PACT_DEATH_PRONE, 5);
      }
      break;
    }
    case 5: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      break;
    }
  }
}

// 吹き飛ばされて死ぬ (PACT_DEATH_SUPINE), 宙に浮いて後ろへ飛び, 着地して倒れたあとゲームオーバーへ移って点滅しながら消える
void Player_UpdateBlownAwayDeath(Player* p) {
  if (p->action != PACT_DEATH_SUPINE) {
    Player_SetAction(p, PACT_DEATH_SUPINE, 0);
    PLAYER_SET_ANIM_4DIR(p, p->facing);
    if (p->kind == PLAYER_SABATA) {
      PlaySound_082406e0(VO_SABATA_DEATH);
    } else {
      PlaySound_082406e0(VO_DJANGO_DEATH);
    }
    PlaySound_082406e0(SE_DAMAGE);
    if (gGameFlags & GAMEFLAG_CROSSOVER) {
      CrossoverBattle_NotifyPlayerDead();
    }
  }

  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
      if (++p->stateTimer > 3) {
        Player_SetAction(p, PACT_DEATH_SUPINE, 1);
        p->floatHeight = 300;
      }
      break;
    }
    case 1: {
      s32 angle;

      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 43), Q6(1));
      angle = ((p->facing + 5) & 7) << 5;
      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockback);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockback);
      p->hurtbox.knockback = (p->hurtbox.knockback * 3) >> 2;
      if (p->floatHeight > 14) {
        p->floatHeight -= 15;
      } else {
        p->floatHeight = 0;
      }
      if (p->hurtbox.knockback < 20) {
        Player_SetAction(p, PACT_DEATH_SUPINE, 2);
        p->floatHeight = 0;
        PlaySound_082406e0(SONG_680);
      }
      break;
    }
    case 2: {
      s32 angle = ((p->facing + 5) & 7) << 5;

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockback);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockback);
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 44), Q6(1))) {
        p->hurtbox.knockback = 0;
        if (!(gGameFlags & GAMEFLAG_CROSSOVER)) {
          Player_SetAction(p, PACT_DEATH_SUPINE, 3);
        } else {
          Player_SetAction(p, PACT_DEATH_SUPINE, 4);
        }
      }
      break;
    }
    case 3: {
      if (++p->stateTimer > 19) {
        gGameFlags |= GAMEFLAG_GAMEOVER;
        Player_SetAction(p, PACT_DEATH_SUPINE, 4);
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
        Player_SetAction(p, PACT_DEATH_SUPINE, 6);
      }
      break;
    }
    case 6: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      break;
    }
  }
}

// 落下して死ぬ (PACT_FALLDEATH), 沈みながら点滅して消え, 1秒後にゲームオーバーへ移る
void Player_UpdateFallDeath(Player* p) {
  Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
      PlaySound_082406e0(SE_FALL_SURPRISE);
      p->beast.priority = 1;
      Player_SetAction(p, PACT_FALLDEATH, 1);
      p->floatHeight = 0;
      p->mover.tile = NULL;
      break;
    }
    case 1: {
      if (++p->stateTimer > 14) {
        StartBgObjPlttFade(3, 5, 4, 4, 4, 0x1FFF, 2);
        p->floatHeight = 0;
        Player_SetAction(p, PACT_FALLDEATH, 2);
      }
      break;
    }
    case 2: {
      if (p->stateTimer == 9) {
        if (p->kind == PLAYER_SABATA) {
          PlaySound_082406e0(SONG_748);
        } else {
          PlaySound_082406e0(VO_DJANGO_SCREAM);
        }
      }
      if (++p->stateTimer > 14) {
        Player_SetAction(p, PACT_FALLDEATH, 3);
        p->floatHeight = 0;
        PlaySound_082406e0(SE_FALL_431);
      }
      break;
    }
    case 3: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 18), Q6(1));
      p->floatHeight -= 30;
      if (++p->stateTimer > 39) {
        p->hp = 0;
        Player_SetAction(p, PACT_FALLDEATH, 4);
      } else {
        Sprite_UpdateVanishBlink(&p->beast.flags, p->stateTimer, 10, 20);
      }
      break;
    }
    case 4: {
      p->floatHeight = 0;
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
      if (++p->stateTimer > 59) {
        Player_SetAction(p, PACT_FALLDEATH, 5);
        gGameFlags |= GAMEFLAG_GAMEOVER;
      }
      break;
    }
    case 5: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
      break;
    }
  }
}

// PACT_DROWNING の行動, Player_UpdateFallDeath 水辺ばーじょん
void Player_UpdateDrowning(Player* p) {
  Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
      PlaySound_082406e0(SE_FALL_SURPRISE);
      p->beast.priority = 1;
      Player_SetAction(p, PACT_DROWNING, 1);
      p->floatHeight = 0;
      p->mover.tile = NULL;
      break;
    }
    case 1: {
      if (++p->stateTimer > 14) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
        PlaySound_082406e0(SE_FALL_430);
        Player_SetAction(p, PACT_DROWNING, 2);
      }
      break;
    }
    case 2: {
      p->floatHeight -= 30;
      if (++p->stateTimer > 3) {
        FUN_08016110(1, 0, 0, 30, &p->mover.pos);
        PlaySound_082406e0(SONG_325);
        p->hp = 0;
        Player_SetAction(p, PACT_DROWNING, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
      if (++p->stateTimer > 29) {
        StartBgObjPlttFade(3, 5, 4, 4, 4, 0x1FFF, 2);
        Player_SetAction(p, PACT_DROWNING, 4);
      }
      break;
    }
    case 4: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
      if (++p->stateTimer > 29) {
        Player_SetAction(p, PACT_DROWNING, 5);
        gGameFlags |= GAMEFLAG_GAMEOVER;
      }
      break;
    }
    case 5: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
      break;
    }
  }
}

// PACT_HEATSTROKE の行動, 声を出して 46 のアニメを4コマごとに効果音付きで流し, 終わって15フレーム後に Player_ExecEventScript(p, 1) を呼ぶ
void Player_UpdateHeatstroke(Player* p) {
  switch (p->state) {
    case 0: {
      if (p->stateTimer == 0) {
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
        if (p->kind == PLAYER_SABATA) {
          PlaySound_082406e0(SONG_750);
        } else {
          PlaySound_082406e0(VO_DJANGO_UGH_769);
        }
      }
      if (++p->stateTimer > 5) {
        Player_SetAction(p, PACT_HEATSTROKE, 1);
      }
      break;
    }
    case 1: {
      if (!(p->human.animCmdIdx & 3) && p->human.animCmdTimer == 0) {
        PlaySound_082406e0(SONG_209);
      }
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 46), Q6(1))) {
        Player_SetAction(p, PACT_HEATSTROKE, 2);
      }
      break;
    }
    case 2: {
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_HEATSTROKE, 3);
        Player_ExecEventScript(p, 1);
      }
      break;
    }
  }
}

// PACT_UNK_32, state 0 は mashKeys の連打の多さに応じた速さで歩くアニメを回し, state 1 以降は落下して消える
// 残差1命令 (306/307), 原典は mashHits を読んだレジスタを r1 に複写して比較に使い計算は元の r0 で行うが, こちらは複写せず r0 だけで済ませる
// Tier A-C 試済 (n を u16/s32/u32, 計算だけ p->mashHits 直読み, 0 の分岐を先に書く)
// 追試: mashHits を getter の static inline で読む形 (戻り値 s32/u16/u32, n を u16/s32) は 12-13 hunk に悪化
NON_MATCH void FUN_0806b06c(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != PACT_UNK_32) {
    Player_SetAction(p, PACT_UNK_32, 0);
  }

  switch (p->state) {
    case 0: {
      s32 i;
      u16 n;

      p->facing = DIR8_UP_LEFT;
      p->animDir = 1;
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
        p->facing = DIR8_UP_LEFT;
        p->animDir = 0;
        p->xflip = TRUE;
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
        PlaySound_082406e0(SE_FALL_SURPRISE);
        p->floatHeight = 0;
      }
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      if (++p->stateTimer > 5) {
        PlaySound_082406e0(SE_FALL_430);
        if (p->kind == PLAYER_SABATA) {
          PlaySound_082406e0(SONG_748);
        } else {
          PlaySound_082406e0(VO_DJANGO_SCREAM);
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
      p->facing = DIR8_UP_LEFT;
      p->animDir = 1;
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

// サバタのゼロシフト, 16フレームの間 食らい判定を消して点滅しながら前へ進む
void Magic_ZeroShift(Player* p) {
  if (p->action != PACT_DASH) {
    Player_SetAction(p, PACT_DASH, 0);
    PlaySound_082406e0(SE_M_ZEROSHIFT);
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
    p->flashPlttID = OBP_ELEMENT(6);
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
    p->nextEnchantColorIdx = 0;
    if (Player_HasEnoughEne(p, 100) && gSunMagicUsed == 0) {
      p->magicFired = TRUE;
    } else {
      p->magicFired = FALSE;
    }
    Player_SetAction(p, PACT_SUN_MAGIC, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->facing >= DIR8_RIGHT && p->facing <= DIR8_LEFT) {
        p->facing = DIR8_DOWN;
        p->animDir = 4;
        p->xflip = FALSE;
        p->chargePos = p->mover.pos;
        p->chargePos.x -= Q8(0.08);
        p->chargePos.y += Q8(1.29);
        p->chargePos.z += Q8(0.235);
      } else {
        p->facing = DIR8_UP;
        p->animDir = 0;
        p->xflip = FALSE;
        p->chargePos = p->mover.pos;
        p->chargePos.x += Q8(0.08);
        p->chargePos.y += Q8(1.29);
        p->chargePos.z -= Q8(0.08);
      }

      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      if (p->facing == DIR8_DOWN) {
        p->animDir = 1;
      } else {
        p->animDir = 0;
      }

      if (p->magicFired) {
        PlaySound_082406e0(VO_SABATA_ANKOKU);
        p->flashPlttID = OBP_ELEMENT(1);
        p->plttFlashTimer = 2;
        RisingSunEffect_Create(p, &p->mover.pos, &p->chargePos, 1, p->unk_3ba);
      }

      Player_SetAction(p, PACT_SUN_MAGIC, 1);
      break;
    }
    case 1: {
      if (p->magicFired) {
        p->flashPlttID = OBP_ELEMENT(1);
        p->plttFlashTimer += 3;
        if (p->plttFlashTimer > 32) {
          p->plttFlashTimer = 32;
        }
      }

      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        PlaySound_082406e0(SE_PALM);
        if (p->magicFired && p->unk_3ba == 0) {
          gSunMagicUsed = 1;
        }
        Player_SetAction(p, PACT_SUN_MAGIC, 2);
      }
      break;
    }
    case 2: {
      if (p->magicFired) {
        p->flashPlttID = 290;
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

// サバタの PACT_SPECIALDEATH, 白い "!" を出して棺桶の方を向き, 倒れたあとゲームオーバーへ移って点滅しながら消える
void Player_UpdateSabataSpecialDeath(Player* p) {
  switch (p->state) {
    case 0: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(VO_DJANGO_DEATH);
        p->emoteKind = EMOTE_0;
        p->emoteTimer = 0;
        p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 1, NULL, 0, 0, 80);
        PlaySound_082406e0(SE_CHARA_SUPRISE);
        if (gCoffin != NULL) {
          p->facing = Angle_ToDir8(ArcTan2_8(gCoffin->mover.pos.x - p->mover.pos.x, gCoffin->mover.pos.z - p->mover.pos.z));
          Player_SetAnimFacing(p);
        }
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      if (++p->stateTimer > 89) {
        PlaySound_082406e0(SE_COVER);
        Player_SetAction(p, PACT_SPECIALDEATH, 1);
      }
      break;
    }
    case 1: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 48), Q6(1))) {
        Player_SetAction(p, PACT_SPECIALDEATH, 2);
      }
      break;
    }
    case 2: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 49), Q6(1));
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_SPECIALDEATH, 3);
        gGameFlags |= GAMEFLAG_GAMEOVER;
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
        Player_SetAction(p, PACT_SPECIALDEATH, 5);
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
      p->flashPlttID = 295;
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
      if (p->facing >= DIR8_RIGHT && p->facing <= DIR8_LEFT) {
        p->facing = DIR8_DOWN;
        p->animDir = 4;
        p->xflip = FALSE;
      } else {
        p->facing = DIR8_UP;
        p->animDir = 0;
        p->xflip = FALSE;
      }

      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      p->animDir >>= 2;

      if (p->magicFired) {
        Vec3 pos;

        pos.x = 0, pos.y = 0, pos.z = 15;
        if (p->kind == PLAYER_SOLAR_DJANGO) {
          TransEffect_Create(p, 7, &pos, 50, 69);
        } else {
          TransEffect_Create(p, 7, &pos, 50, 69);
        }
        PlaySound_082406e0(SE_M_TRANS);
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
        p->plttIdx = -1;
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
    Player_ClearElementalCond(p);
    Player_ReleaseCuroro(p);
    PlaySound_082406e0(SE_M_CHANGE);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if (p->stateTimer == 16) {
    PlaySound_082406e0(SE_M_CBAT);
  }

  if ((p->stateTimer & 7) < 7 - (p->stateTimer >> 2)) {
    if (p->facing >= DIR8_DOWN_LEFT) {
      p->animDir = 8 - p->facing;
      p->xflip = TRUE;
    } else {
      p->animDir = p->facing;
      p->xflip = FALSE;
    }
  } else {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->beast.pos = p->mover.pos;
    p->beast.pos.y += p->batHeight;

    if (p->facing >= DIR8_DOWN) {
      p->animDir = (7 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animDir = p->facing >> 1;
      p->xflip = FALSE;
    }
  }

  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
  p->flashPlttID = 290;
  p->plttFlashTimer += 3;
  if (p->plttFlashTimer > 32) {
    p->plttFlashTimer = 32;
  }

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->batAnim, 0, p->animDir, p->xflip);

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
    Player_ClearElementalCond(p);
    Player_ReleaseCuroro(p);
    PlaySound_082406e0(SE_M_CHANGE);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if (p->stateTimer == 16) {
    PlaySound_082406e0(SE_M_CMOUSE);
  }

  if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 2)) {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->beast.pos = p->mover.pos;
  }

  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
  p->flashPlttID = 290;
  p->plttFlashTimer += 3;
  if (p->plttFlashTimer > 32) {
    p->plttFlashTimer = 32;
  }

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->mouseAnim, 0, p->animDir, p->xflip);

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
    Player_ClearElementalCond(p);
    Player_ReleaseCuroro(p);
    Player_SetAction(p, PACT_SLEEPING, 0);
  }

  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
  Player_SetFlag35a(p, PFLAG35A_SHOW_OTHER);
  p->beast.pos = p->mover.pos;

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->coffinAnim, p->coffin + 24, 0, 0);

  AuxSprite_AdvanceAnim(&p->beast, anim);

  Video_SetAuxSpritePltt(p->beastGfx, OBP_COFFIN(p->coffin));
  p->stateTimer++;
  if (p->stateTimer > 7) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_SLEEPING;
    Player_SetAction(p, PACT_WALL, 0);
  }
}

// バットの待機 (PACT_IDLE), バットのアニメを向きに合わせて1コマ進める
void Player_UpdateBatIdle(Player* p) {
  if (p->action != PACT_IDLE) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
  p->flag20 &= ~PFLAG20_BUSY;

  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
}

// バットの歩き (PACT_WALK), batWanderTimer フレームごとに入力方向から乱数でふらつく向きを決め直し, アニメ 0 を進める
// 残差はレジスタ割当 (314/314, 34 hunk), 2回目の Random() でこちらは gRandomTable のアドレスを r7 に持ち越して callee-saved が1本増えるが, 原典は読み直す
// dir の使い回し, 宣言位置, 乱数の分岐を dir += / 共通の代入にする形は試済
// 追試: RandomNext に替える (どちらか / 両方), 2回目の乱数をローカルに受ける, ふらつきの塊を static inline にまとめる形 (312) は不一致
NON_MATCH void Player_UpdateBatWalk(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != PACT_WALK) {
    Player_SetAction(p, PACT_WALK, 0);
    p->batWanderTimer = 0;
  }
  p->flag20 &= ~PFLAG20_BUSY;
  if (p->batWanderTimer == 0) {
    s32 dir = Player_ResolveInputFacing(p);
    s32 r;

    if (dir & 1) {
      PLAYER_SET_ANIM_4DIR(p, dir);
      r = Random() & 7;
      if (r < 6) {
        p->facing = dir;
        p->batWanderTimer = 9;
      } else {
        if (r < 7) {
          p->facing = (dir + 7) & 7;
        } else {
          p->facing = (dir + 9) & 7;
        }
        p->batWanderTimer = 3;
      }
    } else {
      r = Random() & 7;
      if (r < 6) {
        p->facing = dir;
        p->batWanderTimer = 9;
      } else {
        if (r < 7) {
          p->facing = (dir + 7) & 7;
        } else {
          p->facing = (dir + 9) & 7;
        }
        p->batWanderTimer = 3;
      }
      if (!(p->facing & 1)) {
        dir = (p->facing + (Random() & 1) * 2 + 7) & 7;
      } else {
        dir = p->facing;
      }
      PLAYER_SET_ANIM_4DIR(p, dir);
    }
  } else {
    p->batWanderTimer--;
  }
  Player_SetMoveDelta(p, 9);
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
#else
  INCFUNC("asm/func/Player_UpdateBatWalk.inc");
#endif
}

// バットの PACT_SPIDER_WEB, 方向入力に向きを合わせてアニメ 1 を1コマ進め, spiderWebIdx が空いたら PACT_IDLE に戻る
void Player_UpdateBatSpiderWeb(Player* p) {
  if (Player_GetAction(p) != PACT_SPIDER_WEB) {
    Player_SetAction(p, PACT_SPIDER_WEB, 0);
  }
  if ((s16)p->facingHistory[0] >= 0) {
    p->facing = p->facingHistory[0];
    p->facing = (p->facing & 0xFE) + 1;
    PLAYER_SET_ANIM_4DIR(p, p->facing);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 1, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->spiderWebIdx < 0) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// バットの石化 (PACT_SEKIKA), batHeight を 60 ずつ減らしながら石化のアニメを1コマ進め, 状態異常が切れたら PACT_IDLE に戻る
void Player_UpdateBatPetrified(Player* p) {
  AuxAnimState* anim;

  if (p->action != PACT_SEKIKA) {
    Player_SetAction(p, PACT_SEKIKA, 0);
  }
  if (p->batHeight >= 60) {
    p->batHeight -= 60;
  } else {
    p->flag20 &= ~PFLAG20_BUSY;
    p->batHeight = 0;
  }

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->batAnim, 1, p->animDir, p->xflip);

  AuxSprite_AdvanceAnim(&p->beast, anim);

  if (p->emitter.aliveCount == 0) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// バットの被弾 (PACT_DAMAGED), アニメ 1 を進めながら knockback の速さで向きの反対へ押し出し毎フレーム 3/4 に減速, 止まったら emitter が kind 3 で残っていれば PACT_SEKIKA, そうでなければ PACT_IDLE に戻る
void Player_UpdateBatHurt(Player* p) {
  if (p->action != PACT_DAMAGED) {
    PLAYER_SET_ANIM_4DIR(p, p->facing);
    if (p->hurtSound != SONG_NONE) {
      PlaySound_082406e0(p->hurtSound);
      p->hurtSound = SONG_NONE;
    }
    Player_SetAction(p, PACT_DAMAGED, 0);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 1, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->hurtbox.knockback != 0) {
    s32 angle = ((p->facing + 5) & 7) * 32;

    p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockback);
    p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockback);
    p->hurtbox.knockback = (p->hurtbox.knockback * 3) >> 2;
  } else if (p->emitter.kind == ELEMCOND_SEKIKA && p->emitter.aliveCount != 0) {
    Player_SetAction(p, PACT_SEKIKA, 0);
  } else {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// バットのままチェンジ・バットを使ったとき (PACT_CBAT), 点滅させながら human を出し, 31フレームで黒ジャンゴのフォームへ戻す
void Player_UndoChangeBat(Player* p) {
  if (p->action != PACT_CBAT || p->stateTimer == 0) {
    Player_SetAction(p, PACT_CBAT, 0);
    if (p->xflip) {
      p->facing = 7 - p->animDir * 2;
    } else {
      p->facing = p->animDir * 2 + 1;
    }
    p->plttFlashTimer = 0;
    Player_ClearElementalCond(p);
    Player_ReleaseCuroro(p);
    PlaySound_082406e0(SE_M_CHANGE);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if ((p->stateTimer & 7) < 7 - (p->stateTimer >> 2)) {
    if (p->facing > 3) {
      p->animDir = (7 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animDir = p->facing >> 1;
      p->xflip = FALSE;
    }
  } else {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->human.pos = p->mover.pos;
    PLAYER_SET_ANIM_8DIR(p, p->facing);
  }

  Player_PlayAnim(p, 199, Q6(1));
  p->human.plttID = 290;
  p->human.pltt = &gObjPlttData[p->human.plttID * 16];
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  p->flashPlttID = 621;
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
void Player_UpdateMouseIdle(Player* p) {
  p->flag20 &= ~PFLAG20_BUSY;
  if (p->action != PACT_IDLE) {
    Player_SetAction(p, PACT_IDLE, 0);
  }

  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
}

// マウスの歩く速さ, 通常 12 で氷結中は 8, speedPenalty を引いて最低 2
s32 Player_GetMouseWalkSpeed(Player* p) {
  s32 n = 12;

  if (p->emitter.kind == ELEMCOND_HYOKETU && p->emitter.aliveCount != 0) {
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
    p->mouseStepAlt = 0;
    Player_SetAction(p, PACT_WALK, 0);
  }
  p->flag20 &= ~PFLAG20_BUSY;
  p->facing = Player_ResolveInputFacing(p);
  Player_SetMoveDelta(p, Player_GetMouseWalkSpeed(p));
  Player_SetAnimFacing(p);
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 1, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->beastAnim.cmdIdx == 2 && p->beastAnim.tick == 0) {
    if (IsInPuddle(&p->mover.pos)) {
      if (p->mouseStepAlt) {
        p->mouseStepAlt = 0;
        Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_PUDDLE_1);
      } else {
        p->mouseStepAlt = 1;
        Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_PUDDLE_0);
      }
    } else {
      if (p->mouseStepAlt) {
        p->mouseStepAlt = 0;
        PlaySound_082406e0(SE_FSTEP_MINI_0);
      } else {
        p->mouseStepAlt = 1;
        PlaySound_082406e0(SE_FSTEP_MINI_1);
      }
      if (TestMapFlag(MPF_UNK_0)) {
        Player_MakeNoise(p, &p->mover.pos, 1, 2, NULL, 0, SONG_NONE);
      }
    }
  }
}

// マウスの PACT_WALL, 入った瞬間に前方 64 上方 64 の位置へ Player_MakeNoise で SE_M_CMOUSE の演出を出し, アニメ 0 を進めて 16 フレームで PACT_IDLE に戻る
void Player_UpdateMouseMakeNoise(Player* p) {
  if (p->action != PACT_WALL) {
    Vec3 pos = p->mover.pos;
    s32 angle = ((p->facing + 5) & 7) * 32;

    pos.x += POLAR_X(64, angle);
    pos.y += 64;
    pos.z += POLAR_Z(64, angle);
    Player_SetAction(p, PACT_WALL, 0);
    Player_MakeNoise(p, &p->mover.pos, 1, 1, &pos, 0, SE_M_CMOUSE);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  p->stateTimer++;
  if (p->stateTimer > 15) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// マウスの石化 (PACT_SEKIKA), 石化のアニメを1コマ進め, 状態異常が切れたら向きを戻して PACT_IDLE に戻る
void Player_UpdateMousePetrified(Player* p) {
  AuxAnimState* anim;

  if (p->action != PACT_SEKIKA) {
    Player_SetAction(p, PACT_SEKIKA, 0);
    PLAYER_SET_ANIM_4DIR(p, p->facing);
  }
  p->flag20 &= ~PFLAG20_BUSY;

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->mouseAnim, 2, p->animDir, p->xflip);

  AuxSprite_AdvanceAnim(&p->beast, anim);

  if (p->emitter.aliveCount == 0) {
    Player_SetAnimFacing(p);
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// マウスの PACT_SPIDER_WEB, 方向入力に向きを合わせてアニメ 2 を1コマ進め, spiderWebIdx が空いたら PACT_IDLE に戻る
void Player_UpdateMouseSpiderWeb(Player* p) {
  if (p->action != PACT_SPIDER_WEB) {
    Player_SetAction(p, PACT_SPIDER_WEB, 0);
  }
  if ((s16)p->facingHistory[0] >= 0) {
    p->facing = p->facingHistory[0];
    p->facing = (p->facing & 0xFE) + 1;
    PLAYER_SET_ANIM_4DIR(p, p->facing);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->spiderWebIdx < 0) {
    Player_SetAnimFacing(p);
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// マウスの PACT_LANDING, heightAboveTile を毎フレーム 30 ずつ減らして落下し, 着地したらアニメ 3 を一巡させて PACT_IDLE に戻る
void Player_UpdateMouseLanding(Player* p) {
  Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
  switch (p->state) {
    case 0: {
      p->facing |= 1;
      PLAYER_SET_ANIM_4DIR(p, p->facing);
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      if ((u16)p->heightAboveTile <= 30) {
        p->heightAboveTile = 0;
        PlaySound_082406e0(SE_LANDING);
        p->state = 1;
      } else {
        p->heightAboveTile -= 30;
      }
      break;
    }
    case 1: {
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 3, p->animDir, p->xflip);
      if (AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim)) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// マウスの被弾 (PACT_DAMAGED), アニメ 2 を進めながら吹き飛び, knockbackOrigin やタイルから弾かれたときはそちらへ寄せながら炎か煙を出し, 止まったら PACT_SEKIKA か PACT_IDLE に戻る
void Player_UpdateMouseHurt(Player* p) {
  if (p->action != PACT_DAMAGED) {
    PLAYER_SET_ANIM_4DIR(p, p->facing);
    if (p->hurtSound != SONG_NONE) {
      PlaySound_082406e0(p->hurtSound);
      p->hurtSound = SONG_NONE;
    }
    Player_SetAction(p, PACT_DAMAGED, 0);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->hurtbox.knockback != 0) {
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

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->hurtbox.knockback);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->hurtbox.knockback);
    }
    Camera_Shake(p->hurtbox.knockback);
    p->hurtbox.knockback = (p->hurtbox.knockback * 3) >> 2;
  } else {
    p->hurtbox.knockback = 0;
    p->originKnockback = FALSE;
    p->tileKnockback = FALSE;
    if (p->emitter.kind == ELEMCOND_SEKIKA && p->emitter.aliveCount != 0) {
      Player_SetAction(p, PACT_SEKIKA, 0);
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
    Player_ClearElementalCond(p);
    Player_ReleaseCuroro(p);
    PlaySound_082406e0(SE_M_CHANGE);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 2)) {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->human.pos = p->mover.pos;
  }

  Player_PlayAnim(p, 199, Q6(1));
  p->human.plttID = 290;
  p->human.pltt = &gObjPlttData[p->human.plttID * 16];
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  p->flashPlttID = 290;
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

  p->flag20 &= ~PFLAG20_BUSY;
  if (p->coffin == COFFIN_SILVER) {
    p->flag20 |= PFLAG20_INVISIBLE;
  }

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->coffinAnim, p->coffin, p->animDir, p->xflip);

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

// 棺桶獣エレファンでスリーピングしたときの歩き (PACT_WALK), walkVoiceTimer フレームごとに VO_ELEFAN_WALK を鳴らし, 入力方向へ動かして棺桶のアニメ 32 を進め, 偶数コマの頭で床に合わせた足音を鳴らす
// 残差は2回目の Random() で gRandomTable のアドレスを置くレジスタ (r1 / r2) の1か所のみ (293/293), 手動送りは AuxSprite_AdvanceAnim で一致
// 加算の順, 減算の書き方, 乱数の取り直しを inline にまとめる形は試済
NON_MATCH void Player_UpdateSleepingWalk(Player* p) {
#ifdef NONMATCHING_C
  bool32 walking = TRUE;

  if (p->action != PACT_WALK) {
    PlaySound_082406e0(VO_ELEFAN_WALK);
    p->walkVoiceTimer = (Random() & 0x3F) + 64;
    Player_SetAction(p, PACT_WALK, 0);
    walking = FALSE;
  }
  if (p->walkVoiceTimer == 0) {
    PlaySound_082406e0(VO_ELEFAN_WALK);
    p->walkVoiceTimer = (Random() & 0x3F) + 64;
  } else {
    p->walkVoiceTimer--;
  }
  p->facing = Player_ResolveInputFacing(p);
  Player_SetAnimFacing(p);
  Player_SetMoveDelta(p, 6);
  AuxAnim_SetAnim(&p->beastAnim, p->coffinAnim, 32, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (walking && !(p->beastAnim.cmdIdx & 1) && p->beastAnim.tick == 0) {
    if (IsInPuddle(&p->mover.pos)) {
      if (p->beastAnim.cmdIdx == 0) {
        Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_PUDDLE_1);
      } else if (p->beastAnim.cmdIdx == 2) {
        Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_PUDDLE_1);
      }
    } else if (Player_IsOnSoundFloor(p->tile.attr[1])) {
      if (p->beastAnim.cmdIdx == 0) {
        Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_NOISE_1);
      } else if (p->beastAnim.cmdIdx == 2) {
        Player_MakeNoise(p, &p->mover.pos, 1, 1, &p->mover.pos, 0, SE_FSTEP_NOISE_0);
      }
    } else {
      if (p->beastAnim.cmdIdx == 0) {
        PlaySound_082406e0(SONG_617);
      } else if (p->beastAnim.cmdIdx == 2) {
        PlaySound_082406e0(SONG_616);
      }
      if (TestMapFlag(MPF_UNK_0)) {
        Player_MakeNoise(p, &p->mover.pos, 1, 2, NULL, 0, SONG_NONE);
      }
    }
  }
#else
  INCFUNC("asm/func/Player_UpdateSleepingWalk.inc");
#endif
}

// 棺桶獣エレファンで銃を撃つ, エナジーが 10 未満なら空撃ちの音だけ鳴らす
void Player_UpdateSleepingAttack(Player* p) {
  if (p->action != PACT_ATTACK) {
    Player_SetAction(p, PACT_ATTACK, 5);
  }
  if (p->stateTimer == 0) {
    if (p->ene < 10) {
      PlaySound_082406e0(SE_GUN_MISFIRE);
    } else {
      if (p->attackVoiceCooldown == 0) {
        PlaySound_082406e0(VO_ELEFAN_ATTACK);
        p->attackVoiceCooldown = 40;
      }
      PlaySound_082406e0(SE_GUN_FIRE);
      Bullet_Create(p, 20, 180, 0, 32, 44, 32, HBATTR_SOL, 20, 3, 10, TRUE);
    }
  }
  p->stateTimer++;
  if (p->stateTimer > 7) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// スリーピングの PACT_WALL, 10フレームの間は棺桶のアニメ coffin + 16 を進め, 18フレームまで乱数で揺らし, 24フレームで向きを戻して PACT_IDLE に戻る
void Player_UpdateSleepingCloseLid(Player* p) {
  if (p->action != PACT_WALL) {
    Player_SetAction(p, PACT_WALL, 0);
  }
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_COFFIN_CLOSE);
  }
  if (p->stateTimer <= 9) {
    AuxAnim_SetAnim(&p->beastAnim, p->coffinAnim, p->coffin + 16, 0, 0);
    AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  } else if (p->stateTimer <= 17) {
    s32 shake = (Random() & 0xF) - 7;

    p->coffinShake.x = shake;
    p->coffinShake.z = -shake;
  }
  if (++p->stateTimer > 23) {
    p->eneAccum = 0;
    p->facing = DIR8_UP;
    p->animDir = 0;
    p->xflip = FALSE;
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// スリーピング時のクモの巣 (PACT_SPIDER_WEB), 棺桶のアニメを1コマ進め, エレファンなら方向入力に向きを合わせる, spiderWebIdx が空いたら PACT_IDLE に戻る
void Player_UpdateSleepingSpiderWeb(Player* p) {
  AuxAnimState* anim;

  if (p->action != PACT_SPIDER_WEB) {
    Player_SetAction(p, PACT_SPIDER_WEB, 0);
  }
  if (p->coffin == COFFIN_ELEFAN && (s16)p->facingHistory[0] >= 0) {
    p->facing = p->facingHistory[0];
    Player_SetAnimFacing(p);
  }

  anim = &p->beastAnim;
  AuxAnim_SetAnim(anim, p->coffinAnim, p->coffin, p->animDir, p->xflip);

  AuxSprite_AdvanceAnim(&p->beast, anim);

  if (p->spiderWebIdx < 0) {
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// スリーピングのままスリーピングを使ったとき (PACT_SLEEPING), 下を向いてエモートを出し, 棺桶のアニメ coffin + 8 を進めた後は点滅しながら human を出して 40 フレームで黒ジャンゴのフォームへ戻す
void Player_UndoSleeping(Player* p) {
  if (p->action != PACT_SLEEPING || p->stateTimer == 0) {
    Player_SetAction(p, PACT_SLEEPING, 0);
    p->facing = DIR8_DOWN;
    Player_SetAnimFacing(p);
    p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 127, NULL, 0, 0, 0);
    PlaySound_082406e0(SE_COFFIN_OPEN);
    if (p->badCondTimer[BAD_POISON] != 0) {
      p->human.plttID = OBP_POISON;
    } else if (KAAMOS(p->isSabata) > 0) {
      p->human.plttID = OBP_KAAMOS;
    } else if (Player_TestEquipBuff(p, EBUFF_MEGAPOWER)) {
      p->human.plttID = OBP_MEGAPOWER;
    } else if (Player_TestEquipBuff(p, EBUFF_GUTSPOWER)) {
      p->human.plttID = OBP_GUTSPOWER;
    } else if (Player_TestEquipBuff(p, EBUFF_PROTOPOWER)) {
      p->human.plttID = OBP_PROTOPOWER;
    } else if (Player_TestEquipBuff(p, EBUFF_TOADPOWER)) {
      p->human.plttID = OBP_TOADPOWER;
    } else {
      p->human.plttID = OBP_BDJANGO;
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
    p->facing = DIR8_DOWN;
    Player_SetAnimFacing(p);
    Player_SetAction(p, PACT_IDLE, 0);
  }
}

// 1P の向きの前方 ±32 (1/8 周) かつ 2 タイル以内にいる敵ノードのうち, 最も近いものを返す
CWolfTargetNode* Player_FindCWolfTarget(Player* p) {
  s32 bestDistSq = Q8(2) * Q8(2);
  s32 angle = ((p->facing + 5) & 7) << 5;
  CWolfTargetNode* node;
  CWolfTargetNode* best;

  if (gCWolfTargetManager == NULL) {
    return NULL;
  }
  node = gCWolfTargetManager->nodes;
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
// 残差1命令, p->hurtbox.iframes = 0 で原典は値の 0 を先に作ってからアドレスを組むが, こちらはアドレスが先なので値とアドレスのレジスタが入れ替わる (Player_ApplyOriginHit で効いた Player_SetIframes 経由は 0 だと変わらない)
NON_MATCH void MagicChangeWolf_0806eb40(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != PACT_CWOLF) {
    gChangeWolfBiteCount = 0;
    gChangeWolfRebite = 0;
    gChangeWolfBiting = 0;
    p->hurtbox.iframes = 0;
    gCWolfTarget = Player_FindCWolfTarget(p);
    if (gCWolfTarget == NULL) {
      Player_SetAction(p, PACT_CWOLF, 3);
    } else {
      p->flashPlttID = 290;
      p->plttFlashTimer = 32;
      Player_SetAction(p, PACT_CWOLF, 1);
    }
    Player_PayMagicCost(p);
    PlaySound_082406e0(SE_M_CWOLF);
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
          p->animDir = 3 - quad;
          p->xflip = TRUE;
        } else {
          p->animDir = quad;
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
          p->animDir = 3 - quad;
          p->xflip = TRUE;
        } else {
          p->animDir = quad;
          p->xflip = FALSE;
        }
        Player_PlayAnim(p, 408, Q6(1));
        Player_PlayFootstep(p, 0);
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

          PlaySound_082406e0(SE_M_CWOLF_BITE);
          angle = ((p->facing + 5) & 7) * 32;
          v.x = POLAR_X(64, angle), v.y = 230;
          v.z = POLAR_Z(64, angle);
          SpawnBlood(&p->mover.pos, &v, 0, 0, 1);
        }

        p->hp += heal;
        if (p->hp >= p->maxHP) {
          heal = p->maxHP - p->hp;
          p->hp = p->maxHP;
        }
        if (heal > 0) {
          CreateDamageNumber(&p->hurtbox, heal, 1, &p->mover.pos, &p->damageNumOffset, 0);
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
      p->flashPlttID = 290;
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
        p->flashPlttID = 290;
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
        PlaySound_082406e0(SE_LANDING);
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

// ウルフイベント
void Player_UpdateDjangoSpecialDeath(Player* p) {
  switch (p->state) {
    case 0: {
      PlaySound_082406e0(SE_M_CWOLF);
      Player_PlayAnim(p, 403, Q6(1));
      Player_SetAction(p, PACT_SPECIALDEATH, 1);
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
        Player_SetAction(p, PACT_SPECIALDEATH, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      break;
    }
  }
}

// GAMEFLAG_CROSSOVER のダッシュ, Ene を1消費して16フレーム前へ進む, Ene が無ければ NG 音を鳴らして8フレーム立ち止まる
void Player_UpdateCrossoverDash(Player* p) {
  if (p->action != PACT_DASH) {
    if (p->ene != 0) {
      PlaySound_082406e0(SE_M_DASH);
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
          p->flashPlttID = 293;
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
    if (p->facing >= DIR8_RIGHT && p->facing <= DIR8_LEFT) {
      p->facing = DIR8_DOWN;
      p->animDir = 1;
      p->xflip = FALSE;
    } else {
      p->facing = DIR8_UP;
      p->animDir = 0;
      p->xflip = FALSE;
    }
    if (p->ene > 1) {
      HealingEffect_Create(p, &p->mover.pos);
      p->magicFired = TRUE;
      if (p->hp < p->maxHP) {
        s32 hp = p->hp + 40;

        if (hp >= p->maxHP) {
          hp = p->maxHP;
        }
        CreateDamageNumber(&p->hurtbox, hp - p->hp, 1, &p->mover.pos, &p->damageNumOffset, 0);
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
        p->flashPlttID = 294;
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
      p->flashPlttID = 294;
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

// GAMEFLAG_CROSSOVER のダイナマイト, ENE を 2 使って爆弾を出し, 足りなければ NG 音を鳴らす
void Player_UpdateCrossoverDynamite(Player* p) {
  if (p->action != PACT_DYNAMITE) {
    if (p->ene >= 2) {
      p->magicFired = TRUE;
      DynamiteEffect_Create(p, &p->mover.pos, 1);
      p->ene -= 2;
    } else {
      p->magicFired = FALSE;
    }
    Player_SetAction(p, PACT_DYNAMITE, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->magicFired) {
        p->flashPlttID = 291;
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
        p->flashPlttID = 291;
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
bool32 Player_FaceInputDir(Player* p) {
  bool32 turned = FALSE;

  if ((s16)p->facingHistory[0] != -1 && !p->lookAroundOffset.val) {
    p->facing = Player_ResolveInputFacing(p);
    turned = TRUE;
  }
  Player_SetAnimFacing(p);
  return turned;
}

// エンチャントの有無を確かめ, wpn.enchantIdx と nextEnchantColorIdx (enchantIdx + 1, なしは 0) を更新する
void Player_RefreshEnchant(Player* p) {
  p->wpn.enchantIdx = Player_CheckMagicEnchant(p);
  if (p->wpn.enchantIdx >= 0) {
    p->nextEnchantColorIdx = p->wpn.enchantIdx + 1;
  } else {
    p->nextEnchantColorIdx = 0;
  }
}

// 装備中の武器の攻撃力を出す, 剣/槍/槌はチカラとレベルに武器の値 (アストロ武器はレベル依存), その他は熟練度 (ハートの紋章で減った HP に応じて加算), 銃は熟練度と武器の攻撃力だけ
s32 Player_GetWeaponPower(Player* p) {
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
s32 Player_GetAttackPower(Player* p) {
  s32 total = Player_GetWeaponPower(p);
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

// 状態を参照しない武器の特殊効果コールバックの戻り値を OR して攻撃属性にする
s32 Player_GetWeaponEffectAttrs(Player* p) {
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
void Django_OnWeaponHit(HitboxData* a, HitboxData* b, Player* _) {
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
  if (p->berserkHitCounted != 0) {
    return;
  }

  BERSERK_COUNTER++;
  if (BERSERK_COUNTER == (gStat->berserkThresh * 3) >> 2) {
    PlaySound_082406e0(VO_DARK_DJANGO_UGH_770);
    p->flashPlttID = 290;
    p->plttFlashTimer = 64;
    p->shakeTimer = 64;
  } else if (BERSERK_COUNTER == gStat->berserkThresh >> 1) {
    PlaySound_082406e0(VO_DARK_DJANGO_UGH_770);
    p->flashPlttID = 290;
    p->plttFlashTimer = 32;
    p->shakeTimer = 32;
  }
  p->berserkHitCounted = 1;
}

// 向いている方向へ武器の攻撃判定を出す準備をする, 黒ジャンゴとブルースパワー装備中は unk_b8 の値が変わり, エンチャント中は属性を足して魔法のコストを払う
void Player_SetupSwordAttack(Player* p) {
  PlayerWeapon* wpn = &p->wpn;
  s32 power;
  HitboxAttributes attrs;
  u16 iframes;

  p->wpn.basePos = p->mover.pos;
  p->wpn.basePos.y += 230;
  p->wpn.angle = ((p->facing + 5) & 7) << 5;
  power = Player_GetAttackPower(p);
  attrs = Player_GetWeaponEffectAttrs(p);
  iframes = p->wpn.iframes;
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
  Hitbox_SetAttack(&wpn->hitbox, power, wpn->knockback, 1 << WK_SWORD, attrs, iframes);
  wpn->hitbox.angle = wpn->angle;
  wpn->gunSpreadAngle = 0;
  p->berserkHitCounted = 0;
}

// pos から angle の向きに 112-239 離れた位置に, angle と直交する向き (flip で反対) に速さ 6 で飛ぶエンチャントの粒を出す
void Player_SpawnSwordEnchantPtcl(Player* p, Vec3* pos, s32 angle, bool32 flip, s32 element) {
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
  Player_SpawnEnchantPtcl(p, &spawn, &vel, element);
}

// 剣を振る間, 毎フレーム攻撃判定を basePos から半径 160 の弧に沿って unk_b8[0] ずつ回し, unk_b8[2] フレームで終える, エンチャント中は1フレームおきに粒子を出す
// 残差は xflip でない側の角度の足し算 (176/176) と p / angle のレジスタ, 原典は &wpn->angle を先に作ってから n * k + 0x100 + angle - 0x20 の順に足す
// Tier A-C 試済 (戻り値の変数化, 分岐の向き, 足す順と括弧を6通り, 原典どおりの順に書くと演算は揃うが angle のアドレスが後になる), 未: アドレスを先に作る書き方
// 追試: wpn->angle を型名の違うポインタ越し / *(&) / (u8) で読む形も不一致 (16-17 hunk)
NON_MATCH bool32 Player_UpdateSwordSwing(Player* p) {
#ifdef NONMATCHING_C
  PlayerWeapon* wpn = &p->wpn;

  if (p->wpn.gunSpreadAngle == 0) {
    if (p->kind == PLAYER_SOLAR_DJANGO) {
      PlaySound_082406e0(SE_SWORD_ATK_R);
    } else {
      PlaySound_082406e0(SE_SWORD_ATK_B);
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
        Player_SpawnSwordEnchantPtcl(p, &wpn->basePos, angle, p->xflip, wpn->enchantIdx);
      }
    }
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/Player_UpdateSwordSwing.inc");
#endif
}

// 剣の攻撃 (PACT_ATTACK), B を離すと振り, 振りの間に B を押せば続けて振る
void Player_UpdateSwordAttack(Player* p) {
  s32 animSpeed;

  if (p->kind == PLAYER_DARK_DJANGO || TEST_FLAGS(p->equipBuffs, 0x400000)) {
    animSpeed = Q6(0.75);
  } else {
    animSpeed = Q6(1);
  }

  switch (p->state) {
    case 0: {
      Player_RefreshEnchant(p);
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 21), animSpeed)) {
        Player_SetAction(p, PACT_ATTACK, 1);
      }
      break;
    }
    case 1: {
      Player_RefreshEnchant(p);
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 22), Q6(1));
      if (!(p->input->down & B_BUTTON)) {
        Player_SetupSwordAttack(p);
        Player_SetAction(p, PACT_ATTACK, 4);
      } else {
        p->stateTimer++;
      }
      break;
    }
    case 4: {
      p->unk_3d1 = 0;
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 23), animSpeed);
      if (p->kind == PLAYER_DARK_DJANGO && p->human.animCmdIdx == 2 && p->human.animCmdTimer == 0) {
        Player_SpawnSwordShockwave(p, p->facing, &p->mover.pos);
      }
      if (Player_UpdateSwordSwing(p)) {
        Player_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 6: {
      p->unk_3d1 = 0;
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->wpn.unk_ae[0] != 0) {
        p->wpn.unk_ae[0] = 0;
        p->state = 0;
      } else if (++p->stateTimer >= p->wpn.unk_b8[4]) {
        p->wpn.unk_ae[0] = 0;
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// src から angle の方向へ dist だけずらした座標を dst に書く, 高さはそのまま写す
void Vec3_CopyOffsetPolar(Vec3* dst, Vec3* src, s32 angle, s32 dist) {
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
s32 CheckTileHigherAhead(Vec3* pos, s32 angle, s32 dist) {
  Vec3 dst;
  s32 bx, bz, idx;
  CollisionMapTile* tile;
  MapTileOverride* ov;

  Vec3_CopyOffsetPolar(&dst, pos, angle, dist);
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

// 槍の攻撃判定を構える, 前方の段差の高さで振り方 (unk_b8[1] のアニメ) と振りの段数を選び, エンチャント中は属性を足して魔法のコストを払う
void Player_SetupSpearAttack(Player* p) {
  PlayerWeapon* wpn = &p->wpn;
  s32 power;
  HitboxAttributes attrs;
  u16 knockback;
  s32 r;

  p->wpn.basePos = p->mover.pos;
  p->wpn.basePos.y += 150;
  wpn->angle = ((p->facing + 5) & 7) << 5;
  wpn->atkPos.x = wpn->basePos.x + POLAR_X(204, wpn->angle);
  wpn->atkPos.y = wpn->basePos.y;
  wpn->atkPos.z = wpn->basePos.z + POLAR_Z(204, wpn->angle);
  power = Player_GetAttackPower(p);
  attrs = Player_GetWeaponEffectAttrs(p);
  if (p->kind == PLAYER_DARK_DJANGO) {
    attrs |= HBATTR_18;
  }
  knockback = wpn->knockback;
  r = CheckTileHigherAhead(&wpn->basePos, wpn->angle, 224);
  if (r != 0) {
    if ((wpn->enchantIdx == 2 || wpn->enchantIdx == 4) && r == 2) {
      wpn->unk_b8[1] = 27;
      if (p->kind == PLAYER_DARK_DJANGO || TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
        wpn->unk_b8[0] = 56;
        wpn->unk_b8[2] = 0;
        wpn->unk_b8[3] = 2;
        wpn->unk_b8[4] = 3;
      } else {
        wpn->unk_b8[0] = 56;
        wpn->unk_b8[2] = 0;
        wpn->unk_b8[3] = 3;
        wpn->unk_b8[4] = 6;
      }
    } else {
      wpn->unk_b8[1] = 26;
      if (p->kind == PLAYER_DARK_DJANGO || TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
        wpn->unk_b8[0] = 56;
        wpn->unk_b8[2] = 0;
        wpn->unk_b8[3] = 2;
        wpn->unk_b8[4] = 0;
      } else {
        wpn->unk_b8[0] = 56;
        wpn->unk_b8[2] = 0;
        wpn->unk_b8[3] = 3;
        wpn->unk_b8[4] = 0;
      }
    }
  } else if (CheckTileHigherAhead(&wpn->basePos, wpn->angle, 336)) {
    wpn->unk_b8[1] = 27;
    if (p->kind == PLAYER_DARK_DJANGO || TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
      wpn->unk_b8[0] = 56;
      wpn->unk_b8[2] = 2;
      wpn->unk_b8[3] = 3;
      wpn->unk_b8[4] = 0;
    } else {
      wpn->unk_b8[0] = 56;
      wpn->unk_b8[2] = 2;
      wpn->unk_b8[3] = 7;
      wpn->unk_b8[4] = 0;
    }
  } else {
    wpn->unk_b8[1] = 28;
    if (p->kind == PLAYER_DARK_DJANGO || TEST_FLAGS(p->equipBuffs, EBUFF_PROTOPOWER)) {
      wpn->unk_b8[0] = 56;
      wpn->unk_b8[2] = 4;
      wpn->unk_b8[3] = 4;
      wpn->unk_b8[4] = 1;
    } else {
      wpn->unk_b8[0] = 56;
      wpn->unk_b8[2] = 4;
      wpn->unk_b8[3] = 7;
      wpn->unk_b8[4] = 5;
    }
  }
  if (wpn->enchantIdx >= 0) {
    attrs |= 1 << wpn->enchantIdx;
    Player_PayMagicCost(p);
  }
  Hitbox_SetAttack(&wpn->hitbox, power, knockback, 1 << WK_SPEAR, attrs, wpn->iframes);
  wpn->hitbox.angle = wpn->angle;
  wpn->gunSpreadAngle = 0;
  p->berserkHitCounted = 0;
}

// pos の周り ±15 の位置から angle の反対向きに速さ 3-6 で飛ぶエンチャントの粒を出す
void Player_SpawnSpearEnchantPtcl(Player* p, Vec3* pos, s32 angle, s32 element) {
  Vec3 spawn, vel;
  s32 speed;

  spawn.x = pos->x + (RandomNext() & 0x1F) - 15;
  spawn.y = pos->y + (RandomNext() & 0x1F) - 15;
  spawn.z = pos->z + (RandomNext() & 0x1F) - 15;
  speed = (RandomNext() & 3) + 3;
  vel.x = -POLAR_X(speed, angle);
  vel.y = 0;
  vel.z = -POLAR_Z(speed, angle);
  Player_SpawnEnchantPtcl(p, &spawn, &vel, element);
}

// 槍の突きを1フレーム進める, unk_b8[2] フレームかけて攻撃判定を前へ伸ばし, unk_b8[3] フレーム留めて, unk_b8[4] フレーム待つと終わり (TRUE)
s32 Player_UpdateSpearThrust(Player* p) {
  PlayerWeapon* w = &p->wpn;

  if (w->gunSpreadAngle == 0) {
    if (p->kind == PLAYER_SOLAR_DJANGO) {
      PlaySound_082406e0(SE_SPEAR_ATK_R);
    } else {
      PlaySound_082406e0(SE_SPEAR_ATK_B);
    }
  }
  if (w->gunSpreadAngle < w->unk_b8[2]) {
    s32 r = w->unk_b8[0] * w->gunSpreadAngle + 204;

    w->atkPos.x = w->basePos.x + POLAR_X(r, w->angle);
    w->atkPos.y = w->basePos.y;
    w->atkPos.z = w->basePos.z + POLAR_Z(r, w->angle);
    Hitbox_SetPos(&w->hitbox, &w->atkPos, 0);
    Hitbox_Register(&w->hitbox);
    if (w->enchantIdx >= 0) {
      SET_FLAGS(p->flag20, PFLAG20_UNK_19);
      Player_SpawnSpearEnchantPtcl(p, &w->atkPos, w->angle, w->enchantIdx);
    }
  } else if (w->gunSpreadAngle < w->unk_b8[2] + w->unk_b8[3]) {
    s32 r = w->unk_b8[0] * w->unk_b8[2] + 204;

    w->atkPos.x = w->basePos.x + POLAR_X(r, w->angle);
    w->atkPos.y = w->basePos.y;
    w->atkPos.z = w->basePos.z + POLAR_Z(r, w->angle);
    Hitbox_SetPos(&w->hitbox, &w->atkPos, 0);
    Hitbox_Register(&w->hitbox);
    if (w->enchantIdx >= 0) {
      SET_FLAGS(p->flag20, PFLAG20_UNK_19);
      if (!(w->gunSpreadAngle & 1)) {
        Player_SpawnSpearEnchantPtcl(p, &w->atkPos, w->angle, w->enchantIdx);
      }
    }
  }
  if (++w->gunSpreadAngle >= w->unk_b8[2] + w->unk_b8[3] + w->unk_b8[4]) {
    w->gunSpreadAngle = 0;
    return TRUE;
  }
  return FALSE;
}

// 槍の攻撃 (PACT_ATTACK), 7 フレーム以上構えて B を離すと突き, 黒ジャンゴは槍の衝撃波を出す
void Player_UpdateSpearAttack(Player* p) {
  s32 animSpeed;
  u16* kind;
  u8* playerKind;
  u8 idx;

  if (p->kind == PLAYER_DARK_DJANGO || TEST_FLAGS(p->equipBuffs, 0x400000)) {
    animSpeed = Q6(0.75);
  } else {
    animSpeed = Q6(1);
  }

  switch (p->state) {
    case 0: {
      Player_RefreshEnchant(p);
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 24), animSpeed)) {
        Player_SetAction(p, PACT_ATTACK, 1);
      }
      break;
    }
    case 1: {
      Player_RefreshEnchant(p);
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 25), Q6(1));
      if (p->stateTimer > 6 && !(p->input->down & B_BUTTON)) {
        Player_SetupSpearAttack(p);
        Player_SetAction(p, PACT_ATTACK, 4);
      } else {
        p->stateTimer++;
      }
      break;
    }
    case 4: {
      p->unk_3d1 = 0;
      playerKind = &p->kind;
      idx = *playerKind;
      kind = &p->wpn.unk_b8[1];
      Player_PlayAnim(p, Player_GetAnimIdx(idx, *kind), animSpeed);
      if (*playerKind == PLAYER_DARK_DJANGO) {
        if (*kind == 28) {
          if (p->human.animCmdIdx == 1 && p->human.animCmdTimer == 0) {
            Player_SpawnSpearShockwave(p, p->facing, &p->mover.pos, 0);
          }
        } else if (*kind == 27) {
          if (p->human.animCmdIdx == 1 && p->human.animCmdTimer == 0) {
            Player_SpawnSpearShockwave(p, p->facing, &p->mover.pos, 1);
          }
        } else if (*kind == 26 && p->human.animCmdIdx == 0 && p->human.animCmdTimer == 1) {
          Player_SpawnSpearShockwave(p, p->facing, &p->mover.pos, 2);
        }
      }
      if (Player_UpdateSpearThrust(p)) {
        Player_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 5: {
      p->unk_3d1 = 0;
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 24), animSpeed)) {
        Player_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 6: {
      p->unk_3d1 = 0;
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->wpn.unk_ae[0] != 0) {
        p->wpn.unk_ae[0] = 0;
        p->state = 0;
      } else if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 25), animSpeed)) {
        p->wpn.unk_ae[0] = 0;
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 向いている方向へ武器の攻撃判定を出す準備をする (Player_SetupSwordAttack の別の値の版, 判定の種類は 4)
void Player_SetupHammerAttack(Player* p) {
  PlayerWeapon* wpn = &p->wpn;
  s32 power;
  HitboxAttributes attrs;

  p->wpn.basePos = p->mover.pos;
  p->wpn.basePos.y += 230;
  p->wpn.angle = ((p->facing + 5) & 7) << 5;
  power = Player_GetAttackPower(p);
  attrs = Player_GetWeaponEffectAttrs(p);
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
  Hitbox_SetAttack(&wpn->hitbox, power, wpn->knockback, 1 << WK_HAMMER, attrs, wpn->iframes);
  wpn->hitbox.angle = wpn->angle;
  wpn->gunSpreadAngle = 0;
  p->berserkHitCounted = 0;
}

// pos の周り ±15 の位置から, yaw / pitch の向きに速さ 5-8 で飛ぶエンチャントの粒を出す (Player_SpawnSpearEnchantPtcl の別版)
void Player_SpawnHammerEnchantPtcl(Player* p, Vec3* pos, s32 yaw, s32 pitch, s32 element) {
  Vec3 spawn, vel;
  s32 speed, v;

  spawn.x = pos->x + (RandomNext() & 0x1F) - 15;
  spawn.y = pos->y + (RandomNext() & 0x1F) - 15;
  spawn.z = pos->z + (RandomNext() & 0x1F) - 15;
  speed = (RandomNext() & 3) + 5;
  vel.y = POLAR_X(speed, yaw);
  v = -POLAR_Z(speed, yaw);
  vel.x = POLAR_X(v, pitch);
  vel.z = POLAR_Z(v, pitch);
  Player_SpawnEnchantPtcl(p, &spawn, &vel, element);
}

// 槌の振り下ろしを1フレーム進める, unk_b8[4] フレーム溜めてから unk_b8[2] フレームで頭上から前へ弧を描き, 振り下ろしの終わりに足元へ判定を出して unk_b8[3] フレーム残すと終わり (TRUE)
s32 Player_UpdateHammerSwing(Player* p) {
  PlayerWeapon* w = &p->wpn;

  if (++w->gunSpreadAngle <= w->unk_b8[4]) {
    return FALSE;
  }
  if (w->gunSpreadAngle <= w->unk_b8[4] + w->unk_b8[2]) {
    s32 pitch;
    s32 v;

    if (w->gunSpreadAngle == w->unk_b8[4] + w->unk_b8[2]) {
      if (p->kind == PLAYER_SOLAR_DJANGO) {
        PlaySound_082406e0(SE_HAMMER_ATK_R);
      } else {
        PlaySound_082406e0(SE_HAMMER_ATK_B);
      }
    }
    pitch = (336 - (w->gunSpreadAngle - w->unk_b8[4]) * w->unk_b8[0]) & 0xFF;
    w->atkPos.y = w->basePos.y + POLAR_Z(250, pitch);
    v = POLAR_X(250, pitch);
    w->atkPos.x = w->basePos.x + POLAR_X(v, w->angle);
    w->atkPos.z = w->basePos.z + POLAR_Z(v, w->angle);
    if (w->gunSpreadAngle > w->unk_b8[4] + 2 && w->enchantIdx >= 0) {
      Player_SpawnHammerEnchantPtcl(p, &w->atkPos, pitch, w->angle, w->enchantIdx);
    }
    if (w->gunSpreadAngle > w->unk_b8[4] + w->unk_b8[2] - 2) {
      Vec3 pos;
      s32 radius = 170;

      pos.x = w->basePos.x + POLAR_X(radius, w->angle);
      pos.y = (w->unk_b8[4] + w->unk_b8[2] - w->gunSpreadAngle + 1) * 90 + w->basePos.y - 260;
      pos.z = w->basePos.z + POLAR_Z(radius, w->angle);
      if (w->enchantIdx >= 0) {
        SET_FLAGS(p->flag20, PFLAG20_UNK_19);
      }
      Hitbox_SetPos(&p->wpn.hitbox, &pos, 0);
      Hitbox_Register(&w->hitbox);
    }
    return FALSE;
  }
  if (w->gunSpreadAngle <= w->unk_b8[4] + w->unk_b8[2] + w->unk_b8[3]) {
    if (w->enchantIdx >= 0) {
      SET_FLAGS(p->flag20, PFLAG20_UNK_19);
    }
    Hitbox_Register(&p->wpn.hitbox);
    return FALSE;
  }
  w->gunSpreadAngle = 0;
  return TRUE;
}

// 槌の攻撃 (PACT_ATTACK), B を離すと振り下ろし, 黒ジャンゴは後ろへ衝撃波を出す
void Player_UpdateHammerAttack(Player* p) {
  s32 animSpeed;

  if (p->kind == PLAYER_DARK_DJANGO || TEST_FLAGS(p->equipBuffs, 0x400000)) {
    animSpeed = Q6(0.75);
  } else {
    animSpeed = Q6(1);
  }

  switch (p->state) {
    case 0: {
      Player_RefreshEnchant(p);
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 29), animSpeed)) {
        Player_SetAction(p, PACT_ATTACK, 1);
      }
      break;
    }
    case 1: {
      Player_RefreshEnchant(p);
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 30), animSpeed);
      if (!(p->input->down & B_BUTTON)) {
        Player_SetupHammerAttack(p);
        Player_SetAction(p, PACT_ATTACK, 4);
      } else {
        p->stateTimer++;
      }
      break;
    }
    case 4: {
      p->unk_3d1 = 0;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 31), animSpeed);
      if (Player_UpdateHammerSwing(p)) {
        Player_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 5: {
      p->unk_3d1 = 0;
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->kind == PLAYER_DARK_DJANGO && p->human.animCmdIdx == 5 && p->human.animCmdTimer == 0) {
        Player_SpawnShockwaveBehind(p, p->facing, &p->mover.pos);
      }
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 31), animSpeed)) {
        if (p->wpn.unk_ae[0] != 0) {
          p->wpn.unk_ae[0] = 0;
          Player_SetAction(p, PACT_ATTACK, 1);
        } else {
          p->wpn.unk_ae[0] = 0;
          Player_SetAction(p, PACT_IDLE, 0);
        }
      }
      break;
    }
  }
}

// 向いている方向へ武器の攻撃判定を出す準備をする, 判定の向きと威力を決め, 出した位置を wpn.basePos に残す
void Player_SetupFistAttack(Player* p) {
  s32 power;

  p->wpn.basePos = p->mover.pos;
  p->wpn.basePos.y += 230;
  p->wpn.angle = ((p->facing + 5) & 7) << 5;
  power = Player_GetAttackPower(p);
  Video_SetAuxSpritePltt(&p->wpn.gfx, 45);
  Hitbox_SetAttack(&p->wpn.hitbox, power, p->wpn.knockback, 1 << WK_OTHERS, 0, p->wpn.iframes);
  p->wpn.hitbox.angle = p->wpn.angle;
  p->wpn.gunSpreadAngle = 0;
  p->berserkHitCounted = 0;
}

// 武器の攻撃判定を wpn.basePos から wpn.angle の向きへ 100 進めた位置に置いて6フレーム出し続ける, 出し終えたら 1 を返す
s32 Player_UpdateFistPunch(Player* p) {
  PlayerWeapon* wpn = &p->wpn;
  if (p->wpn.gunSpreadAngle == 0) {
    PlaySound_082406e0(SE_FIST_ATK);
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

// 拳の攻撃 (PACT_ATTACK), B を離すと突き, 突きの間に B を押せば続けて突く
void Player_UpdateFistAttack(Player* p) {
  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 32), Q6(1))) {
        if (p->input->down & B_BUTTON) {
          Player_SetAction(p, PACT_ATTACK, 1);
        } else {
          Player_SetupFistAttack(p);
          Player_SetAction(p, PACT_ATTACK, 4);
        }
      }
      break;
    }
    case 1: {
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 33), Q6(1));
      if (!(p->input->down & B_BUTTON)) {
        Player_SetupFistAttack(p);
        Player_SetAction(p, PACT_ATTACK, 4);
      } else {
        p->stateTimer++;
      }
      break;
    }
    case 4: {
      p->unk_3d1 = 0;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 34), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (Player_UpdateFistPunch(p)) {
        Player_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 5: {
      p->unk_3d1 = 0;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 33), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->wpn.unk_ae[0] != 0) {
        p->wpn.unk_ae[0] = 0;
        p->state = 1;
      } else if (++p->stateTimer >= 10) {
        p->wpn.unk_ae[0] = 0;
        Player_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 6: {
      p->unk_3d1 = 0;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 32), Q6(1));
      if (++p->stateTimer >= 5) {
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
}

// 太陽銃の攻撃 (PACT_ATTACK), ENE を払って撃ち B を押し続けるとチャージする, 撃っている間 solarGunTime を数え黒ジャンゴは日焼けする
void Player_UpdateSolarGunAttack(Player* p) {
  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 35), Q6(1))) {
        if (TEST_FLAGS(p->equipBuffs, EBUFF_JOKER)) {
          p->chargeStepTime = 30;
        } else {
          p->chargeStepTime = 60;
        }
        p->berserkHitCounted = 0;
        Player_SetAction(p, PACT_ATTACK, 1);
      }
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_GUN_AIM);
      }
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (++p->stateTimer > 6) {
        s32 cost = (gStat->stageID == 0) ? 1 : 50;

        p->wpn.charge = 0;
        p->knockbackSpeed = 0;
        if (p->ene < cost) {
          PlaySound_082406e0(SE_GUN_MISFIRE);
          Player_SetAction(p, PACT_ATTACK, 5);
        } else {
          p->solarGunTime = 15;
          if (!(p->input->down & B_BUTTON)) {
            PlaySound_082406e0(SE_GUN_FIRE);
            Player_SetAction(p, PACT_ATTACK, 5);
          } else if (gStat->stageID == 0) {
            Player_SetAction(p, PACT_ATTACK, 4);
          } else {
            Player_SetAction(p, PACT_ATTACK, 2);
          }
          Bullet_Create(p, 230, 180, 0, 32, 44, 32, HBATTR_SOL, 20, 3, cost, FALSE);
        }
      }
      break;
    }
    case 2: {
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      p->solarGunTime++;
      if (p->stateTimer == 6) {
        PlaySound_082406e0(SE_GUN_CHARGING);
      }
      if (!(p->input->down & B_BUTTON)) {
        PlaySound_082406e0(SE_GUN_FIRE);
        Player_SetAction(p, PACT_ATTACK, 5);
      } else if (++p->stateTimer >= p->chargeStepTime) {
        p->wpn.charge = 1;
        p->knockbackSpeed = 30;
        p->flashPlttID = 289;
        p->plttFlashTimer = 36;
        if (GetWeaponSkillLevel(WK_GUN) > 98) {
          PlaySound_082406e0(SE_GUN_CHARGING);
          Player_SetAction(p, PACT_ATTACK, 3);
        } else {
          PlaySound_082406e0(SE_GUN_CHARGED);
          Player_SetAction(p, PACT_ATTACK, 4);
        }
      }
      break;
    }
    case 3: {
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      p->solarGunTime++;
      if (p->input->down & B_BUTTON) {
        if (++p->stateTimer >= p->chargeStepTime) {
          p->wpn.charge = 2;
          p->knockbackSpeed = 60;
          p->flashPlttID = 289;
          p->plttFlashTimer = 36;
          PlaySound_082406e0(SE_GUN_CHARGED);
          Player_SetAction(p, PACT_ATTACK, 4);
        }
      } else {
        PlaySound_082406e0(SE_GUN_FIRE);
        Player_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 4: {
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      p->solarGunTime++;
      if (!(p->input->down & B_BUTTON)) {
        PlaySound_082406e0(SE_GUN_FIRE);
        Player_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 5: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 37), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->knockbackSpeed != 0) {
        s32 angle;

        if (p->knockbackSpeed > 5) {
          Vec3 ofs;
          Vec3 size;

          VEC3_SET(ofs, 0, 0, 0);
          VEC3_SET(size, 32, 32, 32);
          DustManager_SpawnNoPause(&p->mover.pos, &ofs, &size, 1, 3, 4);
        }
        angle = ((p->facing + 5) & 7) * 32;
        p->mover.delta.x = -POLAR_X(p->knockbackSpeed, angle);
        p->mover.delta.z = -POLAR_Z(p->knockbackSpeed, angle);
        p->knockbackSpeed = (p->knockbackSpeed * 3) >> 2;
      } else if (++p->stateTimer > 4) {
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
  }
  if (p->solarGunTime > 14) {
    if (p->kind == PLAYER_DARK_DJANGO) {
      Player_TakeSunburnDamage(p);
    }
    p->solarGunTime = 0;
  }
  p->nextEnchantColorIdx = 8;
}

// ロックバスターの攻撃 (PACT_ATTACK), 撃ちながら B を押し続けるとチャージし, チャージ段階に応じた反動で後ろへ滑る
void Player_UpdateMegaBusterAttack(Player* p) {
  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 38), Q6(1))) {
        if (TEST_FLAGS(p->equipBuffs, EBUFF_JOKER)) {
          p->chargeStepTime = 30;
        } else {
          p->chargeStepTime = 60;
        }
        p->berserkHitCounted = 0;
        Player_SetAction(p, PACT_ATTACK, 1);
      }
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_GUN_AIM);
      }
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      if (++p->stateTimer > 6) {
        p->wpn.charge = 0;
        p->knockbackSpeed = 0;
        if (p->ene <= 19) {
          PlaySound_082406e0(SE_GUN_MISFIRE);
          Player_SetAction(p, PACT_ATTACK, 5);
        } else {
          if (!(p->input->down & B_BUTTON)) {
            PlaySound_082406e0(SE_ROCKBUSTER_FIRE);
            Player_SetAction(p, PACT_ATTACK, 5);
          } else if (!TEST_FLAGS(p->equipBuffs, EBUFF_MEGAPOWER)) {
            Player_SetAction(p, PACT_ATTACK, 4);
          } else {
            Player_SetAction(p, PACT_ATTACK, 2);
          }
          Bullet_Create(p, 200, 170, 8, 32, 46, 32, 0, 20, 17, 20, FALSE);
        }
      }
      break;
    }
    case 2: {
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      if (p->stateTimer == 6) {
        PlaySound_082406e0(SONG_500);
      }
      if (!(p->input->down & B_BUTTON)) {
        PlaySound_082406e0(SE_ROCKBUSTER_FIRE);
        Player_SetAction(p, PACT_ATTACK, 5);
      } else if (++p->stateTimer >= p->chargeStepTime) {
        p->wpn.charge = 1;
        p->knockbackSpeed = 30;
        p->flashPlttID = 289;
        p->plttFlashTimer = 36;
        if (GetWeaponSkillLevel(WK_GUN) > 98) {
          Player_SetAction(p, PACT_ATTACK, 3);
        } else {
          PlaySound_082406e0(SONG_501);
          Player_SetAction(p, PACT_ATTACK, 4);
        }
      }
      break;
    }
    case 3: {
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      if (p->input->down & B_BUTTON) {
        if (++p->stateTimer >= p->chargeStepTime) {
          p->wpn.charge = 2;
          p->knockbackSpeed = 60;
          p->flashPlttID = 289;
          p->plttFlashTimer = 36;
          PlaySound_082406e0(SONG_501);
          Player_SetAction(p, PACT_ATTACK, 4);
        }
      } else {
        PlaySound_082406e0(SE_ROCKBUSTER_FIRE);
        Player_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 4: {
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      if (!(p->input->down & B_BUTTON)) {
        PlaySound_082406e0(SE_ROCKBUSTER_FIRE);
        Player_SetAction(p, PACT_ATTACK, 5);
      }
      break;
    }
    case 5: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 40), Q6(1));
      if (p->input->pressed & B_BUTTON) {
        p->wpn.unk_ae[0] = 1;
      }
      if (p->knockbackSpeed != 0) {
        s32 angle;

        if (p->knockbackSpeed > 5) {
          Vec3 ofs;
          Vec3 size;

          VEC3_SET(ofs, 0, 0, 0);
          VEC3_SET(size, 32, 32, 32);
          DustManager_SpawnNoPause(&p->mover.pos, &ofs, &size, 1, 3, 4);
        }
        angle = ((p->facing + 5) & 7) * 32;
        p->mover.delta.x = -POLAR_X(p->knockbackSpeed, angle);
        p->mover.delta.z = -POLAR_Z(p->knockbackSpeed, angle);
        p->knockbackSpeed = (p->knockbackSpeed * 3) >> 2;
      } else if (++p->stateTimer > 4) {
        Player_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 6: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
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
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 38), Q6(1));
      if (++p->stateTimer > 4) {
        Player_SetAction(p, PACT_IDLE, 0);
      }
      break;
    }
  }
  p->nextEnchantColorIdx = 4;
}

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
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (++p->stateTimer > 6) {
        p->wpn.charge = 0;
        if (p->ene <= 4) {
          PlaySound_082406e0(SE_GUN_MISFIRE);
          Player_SetAction(p, PACT_ATTACK, 5);
        } else {
          if (!(p->input->down & B_BUTTON)) {
            PlaySound_082406e0(SE_SABATA_FIRE);
            Player_SetAction(p, PACT_ATTACK, 5);
          } else {
            Player_SetAction(p, PACT_ATTACK, 2);
          }
          Bullet_Create(p, 230, 170, 0, 32, 50, 32, HBATTR_DARK, 20, 5, 5, FALSE);
        }
      }
      break;
    }
    case 2: {
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (p->stateTimer == 6) {
        PlaySound_082406e0(SE_GUN_CHARGING);
      }
      if (!(p->input->down & B_BUTTON)) {
        PlaySound_082406e0(SE_SABATA_FIRE);
        Player_SetAction(p, PACT_ATTACK, 5);
      } else if (++p->stateTimer >= p->chargeStepTime) {
        p->wpn.charge = 1;
        p->flashPlttID = 290;
        p->plttFlashTimer = 36;
        PlaySound_082406e0(SE_GUN_CHARGING);
        Player_SetAction(p, PACT_ATTACK, 3);
      }
      break;
    }
    case 3: {
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (p->input->down & B_BUTTON) {
        if (++p->stateTimer >= p->chargeStepTime) {
          p->wpn.charge = 2;
          p->flashPlttID = 290;
          p->plttFlashTimer = 36;
          PlaySound_082406e0(SE_GUN_CHARGED);
          Player_SetAction(p, PACT_ATTACK, 4);
        }
      } else {
        PlaySound_082406e0(VO_SABATA_TAKETHIS);
        p->wpn.gunSpreadAngle = ((8 - p->facing) & 7) << 5;
        Hitbox_SetAttack(&p->wpn.hitbox, Player_GetAttackPower(p), 32, 1 << WK_GUN, HBATTR_DARK, 20);
        PlaySound_082406e0(SE_GUN_SPREAD);
        Player_SetAction(p, PACT_ATTACK, 8);
      }
      break;
    }
    case 4: {
      Player_FaceInputDir(p);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 36), Q6(1));
      if (!(p->input->down & B_BUTTON)) {
        PlaySound_082406e0(VO_SABATA_TAKETHIS);
        p->wpn.gunSpreadAngle = ((8 - p->facing) & 7) << 5;
        Hitbox_SetAttack(&p->wpn.hitbox, Player_GetAttackPower(p), 32, 1 << WK_GUN, HBATTR_DARK, 20);
        PlaySound_082406e0(SE_GUN_SPREAD);
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
      if (Player_FaceInputDir(p)) {
        Player_SetMoveDelta(p, 6);
      }
      if (!(p->stateTimer & 3)) {
        Vec3 ofs;
        Vec3 size;

        VEC3_SET(ofs, 0, 0, 0);
        VEC3_SET(size, 32, 0, 32);
        DustManager_Spawn(&p->mover.pos, &ofs, &size, 1, 2, 4);
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
        PlaySound_082406e0(SE_SABATA_SPIN);
      }
      if (++p->stateTimer >= p->wpn.charge << 5) {
        sound_08240740(SE_GUN_SPREAD);
        Player_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
  }
  p->nextEnchantColorIdx = 9;
}

void Player_ReturnToLockedIdle(Player* p) {
  Player_SetAction(p, PACT_IDLE, 0);
  p->lockedUpdate = Player_UpdateLockedIdle;
}

void Player_SetDoneRunScript(Player* p) { p->doneNotify = PDONE_RUN_SCRIPT; }

void Player_RunDoneScript(Player* p) {
  if (p->doneScriptID != 0) {
    s32 id = p->doneScriptID;

    p->doneScriptID = 0;
    VM_ExecByID(id, NULL);
  }
}

void Player_SetDoneEndWait(Player* p) {
  p->doneNotify = PDONE_END_WAIT;
  p->doneWaitPending = TRUE;
}

void Player_EndDoneWait(Player* p) {
  if (p->doneWaitPending) {
    MsgQueue_EndWait(&p->mq, 1);
    p->doneWaitPending = FALSE;
  }
}

void Player_NotifyLockedDone(Player* p) {
  if (p->doneNotify == PDONE_RUN_SCRIPT) {
    Player_RunDoneScript(p);
  } else if (p->doneNotify == PDONE_END_WAIT) {
    Player_EndDoneWait(p);
  }
}

// 操作不能中に姿と影を隠したままにする lockedUpdate
void Player_UpdateLockedHidden(Player* p) { Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW); }

// 操作不能中, footHitboxOn なら 8 フレームごとに焼かれる煙を出す
void Player_StepBurnSmoke(Player* p) {
  if (p->footHitboxOn != 0) {
    p->footHitboxTimer++;
    if (p->footHitboxTimer > 7) {
      Player_EmitBurnSmoke(p);
      p->footHitboxTimer = 0;
    }
  }
}

// 操作不能中の待機 (lockedUpdate), state 0 は素立ちで黒ジャンゴに戻った知らせを返し, 1 は待機アニメ 47, 2 は 20 フレーム待機アニメを流してから素立ちに戻して完了を知らせる
void Player_UpdateLockedIdle(Player* p) {
  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      if (p->revertNotifyPending != 0) {
        p->revertNotifyPending = 0;
        Player_NotifyLockedDone(p);
      }
      return;
    }
    case 2: {
      if (++p->stateTimer > 19) {
        break;
      }
    }
    case 1: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 47), Q6(1));
      return;
    }
    default: {
      return;
    }
  }

  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
  Player_ReturnToLockedIdle(p);
  Player_NotifyLockedDone(p);
}

// 3フレームに1回 targetDir の方へ向きを1段ずつ回し, 向き終わったら Player_ReturnToLockedIdle / Player_NotifyLockedDone を呼ぶ
void Player_UpdateLockedTurn(Player* p) {
  if (p->stateTimer >= 2) {
    s32 dir = p->targetDir;
    s32 back = p->facing - 8;

    if (((dir - back) & 7) > 4) {
      p->facing = (p->facing + 7) & 7;
    } else {
      p->facing = (p->facing + 1) & 7;
    }
    PLAYER_SET_ANIM_8DIR(p, p->facing);
    p->stateTimer = 0;
  } else {
    p->stateTimer++;
  }
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
  if (p->facing == p->targetDir) {
    Player_ReturnToLockedIdle(p);
    Player_NotifyLockedDone(p);
  }
}

// 操作不能中に lockedUpdate から回すアニメ 0x211 / 0x212 の演出, state 3 は点滅しながら現れ, 4 は点滅しながら消えて隠れたまま (Player_UpdateLockedHidden) になる
void FUN_080728a8(Player* p) {
  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, 529, Q6(1))) {
        p->state = 1;
        Player_NotifyLockedDone(p);
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
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
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
        Player_NotifyLockedDone(p);
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
        p->lockedUpdate = Player_UpdateLockedHidden;
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

void FUN_080729e0(Player* p) {
  if (Player_PlayAnim(p, 531, Q6(1))) {
    Player_SetAnimFacing(p);
    Player_ReturnToLockedIdle(p);
    Player_NotifyLockedDone(p);
  }
}

void FUN_08072a0c(Player* p) {
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 51), Q6(1));
  Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
}

// 操作不能中に moveTarget へ歩かせる, 着いたら targetDir (なければ進んだ向き) を向いて元の処理に戻す, 歩いている間は足音を鳴らす
void Player_UpdateMoveTo(Player* p) {
  s32 dx = p->moveTarget.x - p->mover.pos.x;
  s32 dz = p->moveTarget.z - p->mover.pos.z;
  s32 angle = ArcTan2_8(dx, dz);
  s32 speed = 12;

  Player_CalcWalkAnimSpeed(speed);
  if (HasGoodCond(p, GOOD_MINI)) {
    speed = speed * p->human.scaleX >> 6;
  }
  if (dx * dx + dz * dz <= speed * speed) {
    p->mover.pos.x = p->moveTarget.x;
    p->mover.pos.z = p->moveTarget.z;
    if (p->targetDir >= 0) {
      p->facing = p->targetDir;
      p->targetDir = -1;
    } else {
      p->facing = Angle_ToDir8(angle);
    }
    PLAYER_SET_ANIM_8DIR(p, p->facing);
    Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
    Player_ReturnToLockedIdle(p);
    Player_NotifyLockedDone(p);
    return;
  }
  p->mover.delta.x = POLAR_X(speed, angle);
  p->mover.delta.z = POLAR_Z(speed, angle);
  if (p->tile.stairs[1] == STAIRS_VERTICAL) {
    if (p->mover.delta.z < 0) {
      p->mover.delta.z = FixToInt(6, p->mover.delta.z * 40);
    } else {
      p->mover.delta.z = FixToInt(6, p->mover.delta.z * 52);
    }
  } else if (p->tile.stairs[1] == STAIRS_HORIZONTAL) {
    if (p->mover.delta.x < 0) {
      p->mover.delta.x = FixToInt(6, p->mover.delta.x * 40);
    } else {
      p->mover.delta.x = FixToInt(6, p->mover.delta.x * 52);
    }
  }
  {
    u32 dir = ((((angle + 16) & 0xFF) >> 5) + 3) & 7;

    p->facing = dir;
    PLAYER_SET_ANIM_8DIR(p, dir);
  }
  if ((p->human.animCmdIdx & 3) == 0 && p->human.animCmdTimer == 0 && !HasGoodCond(p, GOOD_NINJA)) {
    if (HasGoodCond(p, GOOD_MINI)) {
      if (p->human.animCmdIdx == 0) {
        PlaySound_082406e0(SE_FSTEP_MINI_1);
      } else {
        PlaySound_082406e0(SE_FSTEP_MINI_0);
      }
    } else if (p->elevatorFlags != 0 || p->tile.stairs[1] == 0) {
      if (p->human.animCmdIdx == 0) {
        PlaySound_082406e0(SE_FSTEP_M_1);
      } else {
        PlaySound_082406e0(SE_FSTEP_M_0);
      }
    } else if (p->human.animCmdIdx == 0) {
      PlaySound_082406e0(SE_FSTEP_STAIRS_1);
    } else {
      PlaySound_082406e0(SE_FSTEP_STAIRS_0);
    }
  }
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(1));
}

// 棺桶を引きながら moveTarget まで後ろ向きに歩かせる, 着いたら targetDir を向き, unk_4a6 があれば unk_4a7 を減らしながら引き続け, 止まったら doneScriptID を実行する
// 残差: 338/341 命令, 原典は sin 側の 8 倍を muls で掛け, 向きの値を別レジスタに写してから比べるが, こちらは両方シフトに畳まれて写しも出ない
// 追試: PLAYER_SET_ANIM_8DIR を static inline にして向きを引数で渡す形は 21-22 hunk で変わらず, 半径の muls は Player_UpdateDashTo と同じ壁
NON_MATCH void Player_UpdatePullCoffinTo(Player* p) {
#ifdef NONMATCHING_C
  s32 dx = p->moveTarget.x - p->mover.pos.x;
  s32 dz = p->moveTarget.z - p->mover.pos.z;
  s32 dist2 = dx * dx + dz * dz;
  s32 cosv = 0;
  s32 sinv = 0;
  bool32 moving;
  u32 anim;

  if (dist2 == 0) {
    anim = Player_GetAnimIdx(p->kind, 16);
    if (p->targetDir >= 0) {
      p->facing = p->targetDir;
      p->targetDir = -1;
      PLAYER_SET_ANIM_8DIR(p, p->facing);
    }
    if (p->unk_4a6) {
      if (p->unk_4a7) {
        s32 angle;

        moving = TRUE;
        angle = ((p->facing + 1) & 7) << 5;
        cosv = COS(angle);
        sinv = SIN(angle);
        p->unk_4a7 = (p->unk_4a7 * 7) >> 3;
      } else {
        moving = FALSE;
        if (p->doneScriptID != 0) {
          s32 id = p->doneScriptID;

          p->doneScriptID = 0;
          VM_ExecByID(id, NULL);
        }
        p->unk_4a6 = moving;
      }
    } else {
      moving = FALSE;
      if (p->doneScriptID != 0) {
        s32 id = p->doneScriptID;

        p->doneScriptID = 0;
        VM_ExecByID(id, NULL);
      }
    }
  } else {
    s32 angle;
    u32 dir;

    anim = Player_GetAnimIdx(p->kind, 17);
    moving = TRUE;
    dir = Angle_ToDir8(ArcTan2_8(dx, dz));
    p->facing = dir;
    PLAYER_SET_ANIM_8DIR(p, dir);
    angle = ((p->facing + 1) & 7) << 5;
    cosv = COS(angle);
    sinv = SIN(angle);
    if (p->human.animCmdIdx & 3) {
      if (dist2 <= 64) {
        p->mover.pos.x = p->moveTarget.x;
        p->mover.pos.z = p->moveTarget.z;
      } else {
        p->mover.delta.x = -FixToInt(12, cosv * 8);
        p->mover.delta.z = -FixToInt(12, sinv * 8);
        if (p->tile.stairs[1] == STAIRS_VERTICAL) {
          if (p->mover.delta.z < 0) {
            p->mover.delta.z = FixToInt(6, p->mover.delta.z * 40);
          } else {
            p->mover.delta.z = FixToInt(6, p->mover.delta.z * 52);
          }
        } else if (p->tile.stairs[1] == STAIRS_HORIZONTAL) {
          if (p->mover.delta.x < 0) {
            p->mover.delta.x = FixToInt(6, p->mover.delta.x * 40);
          } else {
            p->mover.delta.x = FixToInt(6, p->mover.delta.x * 52);
          }
        }
      }
      if (p->unk_4a6 && p->unk_4a7 <= 0x95) {
        p->unk_4a7 = (p->unk_4a7 * 15) >> 4;
      }
    }
  }
  Player_PlayAnim(p, anim, Q6(1));
  if (moving) {
    Player_UpdateCoffinTarget(p, cosv, sinv, p->unk_4a7);
  }
#else
  INCFUNC("asm/func/Player_UpdatePullCoffinTo.inc");
#endif
}

// 操作不能中に lockedUpdate から回す PACT_UNK_7 (太陽チャージなど) の構え, 構えたら unk_4a6 で 2 種の待ちアニメに分かれ, state 3 で構えを解いて元の処理に戻す
void FUN_0807304c(Player* p) {
  switch (p->state) {
    case 0: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        PlaySound_082406e0(SE_PALM);
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
      Player_NotifyLockedDone(p);
      break;
    }
    case 2: {
      p->shadowOffset.z = 30;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      Player_NotifyLockedDone(p);
      break;
    }
    case 3: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        PLAYER_SET_ANIM_8DIR(p, p->facing);
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// 人型のワープ演出 (lockedUpdate), 縦に伸びて浮き上がり消える (state 0-3, 7-8), 上から縮みながら降りて現れる (state 4-6)
void Player_UpdateWarp(Player* p) {
  switch (p->state) {
    case 0: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        Player_SetAction(p, PACT_UNK_7, 1);
      }
      break;
    }
    case 1: {
      p->shadowOffset.z = 30;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 2: {
      if (p->kind == PLAYER_SABATA && p->stateTimer == 0) {
        PlaySound_082406e0(SE_WARP_807);
      }
      p->shadowOffset.z = 30;
      p->human.flags |= SPRFLAG_AFFINE;
      p->human.scaleX = 64 - (u8)p->stateTimer * 4;
      if (p->stateTimer > 8) {
        p->human.scaleY = p->stateTimer * 8;
        p->floatHeight = (p->stateTimer - 8) * 20;
        Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_UNK_7, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      p->floatHeight = p->stateTimer * 200 + 160;
      if (++p->stateTimer > 7) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
        Player_SetAction(p, PACT_IDLE, 0);
        p->lockedUpdate = Player_UpdateLockedHidden;
        Player_NotifyLockedDone(p);
      }
      break;
    }
    case 4: {
      if (p->kind == PLAYER_SABATA && p->stateTimer == 0) {
        PlaySound_082406e0(SONG_513);
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      p->human.flags |= SPRFLAG_AFFINE;
      p->human.scaleX = 4;
      p->human.scaleY = 120;
      p->floatHeight = (8 - p->stateTimer) * 200 + 160;
      if (++p->stateTimer > 7) {
        Player_SetAction(p, PACT_UNK_7, 5);
      }
      break;
    }
    case 5: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      p->human.flags |= SPRFLAG_AFFINE;
      p->human.scaleX = 64 - (15 - (u8)p->stateTimer) * 4;
      if (p->stateTimer < 8) {
        p->human.scaleY = (15 - p->stateTimer) * 8;
        p->floatHeight = (8 - p->stateTimer) * 20;
      } else {
        p->human.scaleY = 64;
        p->floatHeight = 0;
        Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_UNK_7, 6);
      }
      break;
    }
    case 6: {
      p->human.flags &= ~SPRFLAG_AFFINE;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      if (++p->stateTimer > 3) {
        Player_SetAnimFacing(p);
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
      }
      break;
    }
    case 7: {
      if (p->kind == PLAYER_SABATA && p->stateTimer == 0) {
        PlaySound_082406e0(SE_WARP_807);
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      p->human.flags |= SPRFLAG_AFFINE;
      p->human.scaleX = 64 - (u8)p->stateTimer * 4;
      if (p->stateTimer > 8) {
        p->human.scaleY = p->stateTimer * 8;
        p->floatHeight = (p->stateTimer - 8) * 20;
        Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_UNK_7, 3);
      }
      break;
    }
    case 8: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      p->floatHeight = p->stateTimer * 200 + 160;
      if (++p->stateTimer > 7) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
        Player_SetAction(p, PACT_IDLE, 0);
        p->lockedUpdate = Player_UpdateLockedHidden;
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// 操作不能中に lockedUpdate から回す PACT_UNK_18 の演出 (FUN_0807bcb0 が据える), state 4 は点滅しながら消え, 5 で隠れたままになる
void FUN_08073574(Player* p) {
  switch (p->state) {
    case 0: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_COVER);
      }
      if (p->stateTimer == 8) {
        PlaySound_082406e0(SE_WALL_SLIDE);
      }
      p->stateTimer++;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 48), Q6(1))) {
        Player_SetAction(p, PACT_UNK_18, 1);
        Player_NotifyLockedDone(p);
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
        PlaySound_082406e0(SE_COVER);
      }
      if (++p->stateTimer <= 4) {
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 50), Q6(1));
      } else {
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
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

// 操作不能中の落下 (PACT_FALL), 声を上げて沈み 30 フレームで消える (Player_UpdateFall の操作不能版)
void Player_UpdateLockedFall(Player* p) {
  switch (p->state) {
    case 0: {
      Vec3 pos;

      Player_SetFlag35a(p, 4);
      pos = p->mover.pos;
      pos.y += 150;
      Camera_LookAt(&pos);
      if (p->fallFadeMode < 2) {
        if (p->fallFadeMode != 0) {
          StartBgObjPlttFade(3, 3, 4, 4, 4, 0x1FFF, 16);
        } else {
          StartBgObjPlttFade(3, 3, 4, 4, 4, 0x1FFF, 1);
        }
      }
      PLAYER_SET_ANIM_4DIR(p, p->facing);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
      PlaySound_082406e0(SE_FALL_SURPRISE);
      if (p->kind == PLAYER_SABATA) {
        PlaySound_082406e0(VO_SABATA_PITFALL);
      } else {
        PlaySound_082406e0(VO_DJANGO_PITFALL);
      }
      p->floatHeight = 0;
      Player_SetAction(p, PACT_FALL, 1);
      break;
    }
    case 1: {
      Player_SetFlag35a(p, 4);
      if (++p->stateTimer >= 6) {
        p->floatHeight = 0;
        p->human.priority = 1;
        PlaySound_082406e0(SE_FALL_430);
        Player_SetAction(p, PACT_FALL, 2);
      }
      break;
    }
    case 2: {
      u16* height;

      Player_SetFlag35a(p, 4);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 18), Q6(1));
      height = &p->floatHeight;
      *height -= 60;
      if (++p->stateTimer >= 30) {
        Player_SetFlag35a(p, 1);
        *height = 0;
        Player_SetAction(p, PACT_FALL, 3);
        Player_NotifyLockedDone(p);
      }
      break;
    }
    case 3: {
      Player_SetFlag35a(p, 5);
      break;
    }
  }
}

// 操作不能中に lockedUpdate から回す落下, floatHeight を毎フレーム 30 ずつ減らし, 着地アニメが終わったら向きを戻して元の処理に戻す (Player_UpdateLanding の操作不能版)
void Player_UpdateLockedLand(Player* p) {
  switch (p->state) {
    case 0: {
      if (p->stateTimer == 0) {
        PLAYER_SET_ANIM_4DIR(p, p->facing);
        p->stateTimer++;
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 18), Q6(1));
      if (p->floatHeight > 30) {
        p->floatHeight -= 30;
      } else {
        p->floatHeight = 0;
        PlaySound_082406e0(SE_LANDING);
        Player_SetAction(p, PACT_LANDING, 1);
      }
      break;
    }
    case 1: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 19), Q6(1))) {
        PLAYER_SET_ANIM_8DIR(p, p->facing);
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// 操作不能中に lockedUpdate から回す被弾の吹き飛び, 向きの反対へ knockbackSpeed_4a4 の速さで押し出し毎フレーム 3/4 に減速, 止まったら起き上がって元の処理に戻す
void Player_UpdateLockedKnockback(Player* p) {
  switch (p->state) {
    case 0: {
      s32 angle;
      if (p->stateTimer == 0) {
        PLAYER_SET_ANIM_4DIR(p, p->facing);
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
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// 操作不能中の吹き飛び (PACT_BLOWN_AWAY), knockbackSpeed_4a4 の速さで後ろへ飛んで倒れ, 起き上がったら元の処理に戻す (Player_UpdateBlownAway の操作不能版)
void Player_UpdateLockedBlownAway(Player* p) {
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
      p->mover.delta.x = -FixToInt(12, COS(angle) * p->knockbackSpeed_4a4);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->knockbackSpeed_4a4);
      p->knockbackSpeed_4a4 = (p->knockbackSpeed_4a4 * 3) >> 2;
      if (p->stateTimer > 3) {
        if (p->floatHeight >= p->stateTimer * 8) {
          p->floatHeight -= p->stateTimer * 8;
        } else {
          p->floatHeight = 0;
        }
      }
      p->stateTimer++;
      if (p->knockbackSpeed_4a4 < 20 && p->floatHeight == 0) {
        p->floatHeight = 0;
        PlaySound_082406e0(SONG_680);
        Player_SetAction(p, PACT_BLOWN_AWAY, 2);
      }
      break;
    }
    case 2: {
      s32 angle = ((p->facing + 5) & 7) << 5;

      p->mover.delta.x = -FixToInt(12, COS(angle) * p->knockbackSpeed_4a4);
      p->mover.delta.z = -FixToInt(12, SIN(angle) * p->knockbackSpeed_4a4);
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 44), Q6(1))) {
        p->knockbackSpeed_4a4 = 0;
        Player_SetAction(p, PACT_BLOWN_AWAY, 3);
      }
      break;
    }
    case 3: {
      if (++p->stateTimer > 19) {
        if (p->unk_4a6) {
          p->unk_4a6 = 0;
          Player_SetAction(p, PACT_BLOWN_AWAY, 5);
          Player_NotifyLockedDone(p);
        } else {
          Player_SetAction(p, PACT_BLOWN_AWAY, 4);
        }
      }
      break;
    }
    case 4: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_WALL_SLIDE);
        p->stateTimer++;
      }
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 45), Q6(1))) {
        PlaySound_082406e0(SE_COVER);
        Player_SetAnimFacing(p);
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
      }
      break;
    }
    case 5: {
      break;
    }
  }
}

// 操作不能中の被弾, 向きの反対へ押し出され, 止まったら倒れるアニメ (46) を流して倒れたままになる (Player_UpdateLockedKnockback の別版)
void Player_UpdateLockedCollapse(Player* p) {
  switch (p->state) {
    case 0: {
      s32 angle;
      if (p->stateTimer == 0) {
        PLAYER_SET_ANIM_4DIR(p, p->facing);
        Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 41), Q6(1));
        if (p->kind != PLAYER_SABATA) {
          PlaySound_082406e0(VO_DJANGO_DEATH);
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
        Player_NotifyLockedDone(p);
      }
      break;
    }
    case 2: {
      // 起き上がり終えたら lockedUpdate が差し替わるまで何もしない
      break;
    }
  }
}

// 操作不能中に lockedUpdate から回す剣の攻撃モーション, 振り始めにジャンゴごとの効果音, 黒ジャンゴは剣の衝撃波も出す (Player_UpdateLockedHammerAttack の剣版)
void Player_UpdateLockedSwordAttack(Player* p) {
  s32 speed = p->kind == PLAYER_DARK_DJANGO ? Q6(0.75) : Q6(1);

  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 21), speed)) {
        Player_SetAction(p, PACT_ATTACK, 1);
        Player_NotifyLockedDone(p);
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
          PlaySound_082406e0(SE_SWORD_ATK_R);
        } else {
          PlaySound_082406e0(SE_SWORD_ATK_B);
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
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// 操作不能中に lockedUpdate から回す槍の攻撃モーション, 黒ジャンゴとブルースパワー中は 3/4 倍速で, 黒ジャンゴは槍の衝撃波も出す (Player_UpdateLockedSwordAttack の槍版)
void Player_UpdateLockedSpearAttack(Player* p) {
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
        Player_NotifyLockedDone(p);
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
          PlaySound_082406e0(SE_SPEAR_ATK_R);
        } else {
          PlaySound_082406e0(SE_SPEAR_ATK_B);
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
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// 操作不能中に lockedUpdate から回す槌の攻撃モーション (Player_LockHammerReady / Player_LockHammerSwing が据える), 振りの途中でジャンゴごとの効果音, 黒ジャンゴは衝撃波も出す
void Player_UpdateLockedHammerAttack(Player* p) {
  s32 speed = p->kind == PLAYER_DARK_DJANGO ? Q6(0.75) : Q6(1);

  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 29), speed)) {
        Player_SetAction(p, PACT_ATTACK, 1);
        Player_NotifyLockedDone(p);
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
          PlaySound_082406e0(SE_HAMMER_ATK_R);
        }
      } else if (p->stateTimer == 11) {
        PlaySound_082406e0(SE_HAMMER_ATK_B);
      }
      p->stateTimer++;
      done = Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 31), speed);
      if (p->kind == PLAYER_DARK_DJANGO && p->human.animCmdIdx == 5 && p->human.animCmdTimer == 0) {
        Player_SpawnShockwaveBehind(p, p->facing, &p->mover.pos);
      }
      if (done) {
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// 操作不能中に lockedUpdate から回す銃の構え (Player_LockFireGun が据える), 構えて狙い, 撃って戻す
void Player_UpdateLockedGunAttack(Player* p) {
  if (p->kind == PLAYER_SABATA) {
    p->nextEnchantColorIdx = 9;
  } else {
    p->nextEnchantColorIdx = 8;
  }

  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 35), Q6(1))) {
        PlaySound_082406e0(SE_GUN_AIM);
        Player_SetAction(p, PACT_ATTACK, 1);
        Player_NotifyLockedDone(p);
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
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// 操作不能中のロックバスター, 構えてチャージし, 撃って構えを解く
void Player_UpdateLockedRockBuster(Player* p) {
  p->nextEnchantColorIdx = 4;

  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 38), Q6(1))) {
        PlaySound_082406e0(SE_GUN_AIM);
        Player_SetAction(p, PACT_ATTACK, 1);
        Player_NotifyLockedDone(p);
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      if (++p->stateTimer >= 6) {
        Player_SetAction(p, PACT_ATTACK, 2);
        Entity080c1abc_Create((u32)p, 32, p->unk_4a7);
      }
      break;
    }
    case 2: {
      u16* timer;

      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      timer = &p->stateTimer;
      if (*timer == 6) {
        PlaySound_082406e0(SE_ROCKBUSTER_CHARGING);
      }
      if (++*timer >= 60) {
        PlaySound_082406e0(SE_ROCKBUSTER_CHARGED);
        Player_SetAction(p, PACT_ATTACK, 3);
      }
      break;
    }
    case 3: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      if (++p->stateTimer >= 8) {
        Player_SetAction(p, PACT_ATTACK, 4);
        Player_NotifyLockedDone(p);
      }
      break;
    }
    case 4: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      break;
    }
    case 5: {
      u16* timer = &p->stateTimer;

      if (*timer == 0) {
        PlaySound_082406e0(SE_ROCKBUSTER_FIRE);
        ++*timer;
      }
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 40), Q6(1))) {
        Player_SetAction(p, PACT_ATTACK, 6);
      }
      break;
    }
    case 6: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 39), Q6(1));
      if (++p->stateTimer >= 15) {
        Player_SetAction(p, PACT_ATTACK, 7);
      }
      break;
    }
    case 7: {
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 38), Q6(1))) {
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// 操作不能中に moveTarget へ歩かせる, 着いたら targetDir (なければ進んだ向き) を向いて元の処理に戻す, 遠いうちは姿を点滅させる
// 残差 9 hunk (294/293): 点滅の分岐は dist2 <= 0x4000 を先に書くと SetFlag35a(p, 2) が1つに畳まれて揃った, 残りは delta の POLAR の半径 32 を原典は muls で掛けるがこちらはシフトに畳む
// 移動量と階段補正を Player_SetMoveDelta と同じ中身の static inline にすると z 側だけ muls になる (295, 13 hunk), 引数の型 / 半径のローカル / COS * val の順は効かない
NON_MATCH void Player_UpdateDashTo(Player* p) {
#ifdef NONMATCHING_C
  s32 dx;
  s32 dz;
  s32 angle;
  s32 dist2;

  if (p->stateTimer == 0) {
    PlaySound_082406e0(SONG_664);
  }
  dx = p->moveTarget.x - p->mover.pos.x;
  dz = p->moveTarget.z - p->mover.pos.z;
  angle = ArcTan2_8(dx, dz);
  dist2 = dx * dx + dz * dz;
  if (dist2 <= 1024) {
    p->mover.pos.x = p->moveTarget.x;
    p->mover.pos.z = p->moveTarget.z;
    if (p->targetDir >= 0) {
      p->facing = p->targetDir;
      p->targetDir = -1;
    } else {
      p->facing = Angle_ToDir8(angle);
    }
    PLAYER_SET_ANIM_8DIR(p, p->facing);
    Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
    Player_ReturnToLockedIdle(p);
    Player_NotifyLockedDone(p);
    return;
  }
  Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
  if (p->stateTimer <= 3) {
    p->flashPlttID = 0x127;
    p->plttFlashTimer = 24;
    Player_SetFlag35a(p, PFLAG35A_BLINK);
  } else if (dist2 <= 0x4000) {
    Player_SetFlag35a(p, PFLAG35A_BLINK);
  } else {
    p->flashPlttID = 0x127;
    p->plttFlashTimer = 24;
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
  }
  p->stateTimer++;
  p->mover.delta.x = POLAR_X(32, angle);
  p->mover.delta.z = POLAR_Z(32, angle);
  if (p->tile.stairs[1] == STAIRS_VERTICAL) {
    if (p->mover.delta.z < 0) {
      p->mover.delta.z = FixToInt(6, p->mover.delta.z * 40);
    } else {
      p->mover.delta.z = FixToInt(6, p->mover.delta.z * 52);
    }
  } else if (p->tile.stairs[1] == STAIRS_HORIZONTAL) {
    if (p->mover.delta.x < 0) {
      p->mover.delta.x = FixToInt(6, p->mover.delta.x * 40);
    } else {
      p->mover.delta.x = FixToInt(6, p->mover.delta.x * 52);
    }
  }
  p->facing = Angle_ToDir8(angle);
  PLAYER_SET_ANIM_8DIR(p, p->facing);
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(0.5));
#else
  INCFUNC("asm/func/Player_UpdateDashTo.inc");
#endif
}

void FUN_08074994(Player* p) {
  p->flashPlttID = OBP_ELEMENT(6);
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
        Player_NotifyLockedDone(p);
        p->stateTimer++;
      }
      break;
    }
    case 2: {
      if (Player_PlayAnim(p, 536, Q6(1))) {
        Player_SetAnimFacing(p);
        Player_ReturnToLockedIdle(p);
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// 操作不能中の演出 (lockedUpdate), state ごとに向き直りとアニメを流し, パレットの色 5 / 6 / 13 を明滅させる
void FUN_08074a40(Player* p) {
  s32 a, b;
  s32 r, g;

  switch (p->state) {
    case 0: {
      if (p->stateTimer > 1) {
        if (p->targetDir < p->facing) {
          p->facing = (p->facing - 1) & 7;
        } else {
          p->facing = (p->facing + 1) & 7;
        }
        Player_SetAnimFacing(p);
        p->animDir--;
        p->stateTimer = 0;
      } else {
        p->stateTimer++;
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 54), Q6(1));
      if (p->facing == p->targetDir) {
        if (p->facing == 1) {
          p->state = 1;
        } else if (p->facing == 3) {
          p->state = 6;
        } else {
          p->state = 4;
        }
      }
      break;
    }
    case 1: {
      p->animDir = 0;
      p->xflip = FALSE;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 52), Q6(1))) {
        p->state = 2;
      }
      break;
    }
    case 2: {
      p->animDir = 0;
      p->xflip = FALSE;
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 53), Q6(1));
      break;
    }
    case 3: {
      p->animDir = 0;
      p->xflip = FALSE;
      if (Player_PlayAnim(p, 0x201, Q6(1))) {
        Player_SetAnimFacing(p);
        p->animDir--;
        p->state = 0;
        p->stateTimer = 0;
      }
      break;
    }
    case 4: {
      p->animDir = 0;
      p->xflip = TRUE;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 55), Q6(1))) {
        p->state = 7;
      }
      break;
    }
    case 5: {
      p->animDir = 0;
      p->xflip = TRUE;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 56), Q6(1))) {
        if (++p->unk_4a7 > 1) {
          p->state = 7;
        }
      }
      break;
    }
    case 6: {
      p->animDir = 0;
      p->xflip = FALSE;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 55), Q6(1))) {
        p->state = 7;
      }
      break;
    }
    case 7: {
      break;
    }
  }

  if (p->plttPulsePhase < 8) {
    a = p->plttPulsePhase;
    b = 8 - a;
  } else {
    a = 16 - p->plttPulsePhase;
    b = p->plttPulsePhase - 8;
  }
  r = (a * 30 + b * 19) >> 3;
  g = (a * 13 + b * 12) >> 3;
  p->pltt[5] = MakeRgb555(r, g, 11);
  r = (a * 31 + b * 25) >> 3;
  g = (a * 18 + b * 12) >> 3;
  p->pltt[6] = MakeRgb555(r, g, 11);
  r = ((a + b) * 31) >> 3;
  g = (a * 22 + b * 13) >> 3;
  p->pltt[13] = MakeRgb555(r, g, 11);
  if (++p->plttPulsePhase > 15) {
    p->plttPulsePhase = 0;
  }
  if (gSunGaugeOverride != 0) {
    if (gSunGaugeOverrideTimer != 0) {
      gSunGaugeOverrideTimer--;
    } else {
      gSunGaugeOverride = 0;
    }
  }
}

// バットのアニメを向きに合わせて1コマ進める
void Player_UpdateBatLockedIdle(Player* p) {
  AuxAnimState* anim = &p->beastAnim;

  AuxAnim_SetAnim(anim, p->batAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, anim);
}

// 操作不能中に lockedUpdate から回すバットの移動, moveTarget へ速さ 9 で飛び, 着いたら targetDir (無ければ進んできた向き) を向いて PACT_IDLE に戻し lockedUpdate を Player_UpdateBatLockedIdle にする
// 残差1命令 (302/301), 原典は向きの | 1 を格納先のアドレスより先に作り, targetDir = -1 と facing の strb を1つに畳むが, こちらは | 1 がアドレス計算の後に来て畳まれない
// 向きをローカルに出す形, 丸めを static inline にする形, 1 | を先に書く形は試済, Angle_ToDir8(angle) | 1 は u16 引数の切り詰めが入って 304 命令
// 追試: 2文に分けて |= 1 (303), 向きをローカルに受けて facing への格納を1つにまとめる形 (293-294) も不一致
NON_MATCH void Player_UpdateBatMoveTo(Player* p) {
#ifdef NONMATCHING_C
  s32 dx = p->moveTarget.x - p->mover.pos.x;
  s32 dz = p->moveTarget.z - p->mover.pos.z;
  s32 angle = ArcTan2_8(dx, dz);

  if (dx * dx + dz * dz < 82) {
    p->mover.pos.x = p->moveTarget.x;
    p->mover.pos.z = p->moveTarget.z;
    if (p->targetDir >= 0) {
      p->facing = p->targetDir;
      p->targetDir = -1;
    } else {
      p->facing = (((((angle + 0x10) & 0xFF) >> 5) + 3) & 7) | 1;
    }
    PLAYER_SET_ANIM_4DIR(p, p->facing);
    Player_SetAction(p, PACT_IDLE, 0);
    p->lockedUpdate = Player_UpdateBatLockedIdle;
    Player_NotifyLockedDone(p);
  } else {
    p->mover.delta.x = POLAR_X(9, angle);
    p->mover.delta.z = POLAR_Z(9, angle);
    p->facing = (((((angle + 0x10) & 0xFF) >> 5) + 3) & 7) | 1;
    PLAYER_SET_ANIM_4DIR(p, p->facing);
  }
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
#else
  INCFUNC("asm/func/Player_UpdateBatMoveTo.inc");
#endif
}

// バットのワープ演出 (lockedUpdate), バットのアニメを送りながら縦に伸びて消え (state 0-2), 縮みながら降りて現れる (state 3-5)
void Player_UpdateBatWarp(Player* p) {
  switch (p->state) {
    case 0: {
      AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      if (++p->stateTimer > 27) {
        Player_SetAction(p, PACT_UNK_7, 1);
      }
      break;
    }
    case 1: {
      AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      p->beast.flags |= SPRFLAG_AFFINE;
      p->beast.scaleX = 64 - (u8)p->stateTimer * 4;
      if (p->stateTimer > 8) {
        p->beast.scaleY = p->stateTimer * 8;
        p->floatHeight = (p->stateTimer - 8) * 20;
        Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 2: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      p->floatHeight = p->stateTimer * 200 + 160;
      if (++p->stateTimer > 7) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
        Player_SetAction(p, PACT_IDLE, 0);
        p->lockedUpdate = Player_UpdateLockedHidden;
        Player_NotifyLockedDone(p);
      }
      break;
    }
    case 3: {
      AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      p->beast.flags |= SPRFLAG_AFFINE;
      p->beast.scaleX = 4;
      p->beast.scaleY = 120;
      p->floatHeight = (8 - p->stateTimer) * 200 + 160;
      if (++p->stateTimer > 7) {
        Player_SetAction(p, PACT_UNK_7, 4);
      }
      break;
    }
    case 4: {
      AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      p->beast.flags |= SPRFLAG_AFFINE;
      p->beast.scaleX = 64 - (15 - (u8)p->stateTimer) * 4;
      if (p->stateTimer < 8) {
        p->beast.scaleY = (15 - p->stateTimer) * 8;
        p->floatHeight = (8 - p->stateTimer) * 20;
      } else {
        p->beast.scaleY = 64;
        p->floatHeight = 0;
        Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_UNK_7, 5);
      }
      break;
    }
    case 5: {
      p->beast.flags &= ~SPRFLAG_AFFINE;
      AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      if (++p->stateTimer > 3) {
        Player_ReturnToLockedIdle(p);
        p->lockedUpdate = Player_UpdateBatLockedIdle;
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// バットの被弾の吹き飛び, アニメ 1 を進めながら向きの反対へ knockbackSpeed_4a4 の速さで押し出し毎フレーム 3/4 に減速, 止まったら PACT_IDLE に戻して lockedUpdate を Player_UpdateBatLockedIdle にする
void Player_UpdateBatKnockback(Player* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_DAMAGE);
    p->stateTimer++;
  }
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 1, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  if (p->knockbackSpeed_4a4 != 0) {
    s32 angle = ((p->facing + 5) & 7) * 32;

    p->mover.delta.x = -FixToInt(12, COS(angle) * p->knockbackSpeed_4a4);
    p->mover.delta.z = -FixToInt(12, SIN(angle) * p->knockbackSpeed_4a4);
    p->knockbackSpeed_4a4 = (p->knockbackSpeed_4a4 * 3) >> 2;
  } else {
    p->knockbackSpeed_4a4 = 0;
    Player_SetAction(p, PACT_IDLE, 0);
    p->lockedUpdate = Player_UpdateBatLockedIdle;
    Player_NotifyLockedDone(p);
  }
}

// バットから黒ジャンゴへ戻る変身, 点滅させながら human を出し, 31フレームで黒ジャンゴのフォームへ切り替える
void Player_RevertBatToDarkDjango(Player* p) {
  if (p->stateTimer == 0) {
    if (p->xflip) {
      p->facing = 7 - p->animDir * 2;
    } else {
      p->facing = p->animDir * 2 + 1;
    }
    p->plttFlashTimer = 0;
    PlaySound_082406e0(SONG_895);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if ((p->stateTimer & 7) < 7 - (p->stateTimer >> 2)) {
    if (p->facing > 3) {
      p->animDir = (7 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animDir = p->facing >> 1;
      p->xflip = FALSE;
    }
  } else {
    Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_SHOW_OTHER);
    p->human.pos = p->mover.pos;
    PLAYER_SET_ANIM_8DIR(p, p->facing);
  }

  Player_PlayAnim(p, 199, Q6(1));
  p->human.plttID = 290;
  p->human.pltt = &gObjPlttData[p->human.plttID * 16];
  AuxAnim_SetAnim(&p->beastAnim, p->batAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  p->flashPlttID = 621;
  if ((p->plttFlashTimer += 3) > 32) {
    p->plttFlashTimer = 32;
  }
  if (++p->stateTimer > 31) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
    Player_SetAnimFacing(p);
    Player_ReturnToLockedIdle(p);
    p->revertNotifyPending = TRUE;
  }
}

// マウスのアニメを向きに合わせて1コマ進める
void Player_AdvanceMouseAnim(Player* p) {
  AuxAnimState* anim = &p->beastAnim;

  AuxAnim_SetAnim(anim, p->mouseAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, anim);
}

// 操作不能中に lockedUpdate から回すマウスの移動, moveTarget へ速さ 12 で歩き (階段では補正), 着いたら targetDir (無ければ進んできた向き) を向いて PACT_IDLE に戻し lockedUpdate を Player_AdvanceMouseAnim にする
void Player_UpdateMouseMoveTo(Player* p) {
  s32 dx = p->moveTarget.x - p->mover.pos.x;
  s32 dz = p->moveTarget.z - p->mover.pos.z;
  s32 angle = ArcTan2_8(dx, dz);

  if (dx * dx + dz * dz <= 144) {
    p->mover.pos.x = p->moveTarget.x;
    p->mover.pos.z = p->moveTarget.z;
    if (p->targetDir >= 0) {
      p->facing = p->targetDir;
      p->targetDir = -1;
    } else {
      p->facing = Angle_ToDir8(angle);
    }
    PLAYER_SET_ANIM_8DIR(p, p->facing);
    AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animDir, p->xflip);
    AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
    Player_SetAction(p, PACT_IDLE, 0);
    p->lockedUpdate = Player_AdvanceMouseAnim;
    Player_NotifyLockedDone(p);
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
    PLAYER_SET_ANIM_8DIR(p, p->facing);
    AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 1, p->animDir, p->xflip);
    AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  }
}

// マウスの落下 (PACT_FALL), カメラを上に向けてアニメ 2 を1コマ当て, 6フレーム後に沈み始めて 30 フレームで消える
void Player_UpdateMouseFall(Player* p) {
  switch (p->state) {
    case 0: {
      Vec3 pos;

      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      pos = p->mover.pos;
      pos.y += 150;
      Camera_LookAt(&pos);
      if (p->fallFadeMode < 2) {
        if (p->fallFadeMode != 0) {
          StartBgObjPlttFade(3, 3, 4, 4, 4, 0x1FFF, 16);
        } else {
          StartBgObjPlttFade(3, 3, 4, 4, 4, 0x1FFF, 1);
        }
      }
      PLAYER_SET_ANIM_4DIR(p, p->facing);
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      PlaySound_082406e0(SE_FALL_SURPRISE);
      Player_SetAction(p, PACT_FALL, 1);
      p->floatHeight = 0;
      break;
    }
    case 1: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      if (++p->stateTimer > 5) {
        p->floatHeight = 0;
        p->beast.priority = 1;
        PlaySound_082406e0(SE_FALL_430);
        Player_SetAction(p, PACT_FALL, 2);
      }
      break;
    }
    case 2: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      p->floatHeight -= 60;
      if (++p->stateTimer > 29) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
        Player_SetAction(p, PACT_FALL, 3);
        Player_NotifyLockedDone(p);
      }
      break;
    }
    case 3: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      break;
    }
  }
}

// 操作不能中に lockedUpdate から回すマウスの着地 (PACT_LANDING), state 0 は floatHeight を 30 ずつ下げてアニメ 2 を進め, 着地したら state 1 でアニメ 3 を一巡させて lockedUpdate を Player_AdvanceMouseAnim に戻す
void Player_UpdateMouseLand(Player* p) {
  switch (p->state) {
    case 0: {
      if (p->stateTimer == 0) {
        PLAYER_SET_ANIM_4DIR(p, p->facing);
        p->stateTimer++;
      }
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      if (p->floatHeight > 30) {
        p->floatHeight -= 30;
      } else {
        p->floatHeight = 0;
        PlaySound_082406e0(SE_LANDING);
        Player_SetAction(p, PACT_LANDING, 1);
      }
      break;
    }
    case 1: {
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 3, p->animDir, p->xflip);
      if (AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim)) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, PACT_IDLE, 0);
        p->lockedUpdate = Player_AdvanceMouseAnim;
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// マウスのワープ演出 (lockedUpdate), マウスのアニメを送りながら縦に伸びて消え (state 0-2), 縮みながら降りて現れる (state 3-5)
void Player_UpdateMouseWarp(Player* p) {
  switch (p->state) {
    case 0: {
      if (p->stateTimer == 0) {
        p->facing = DIR8_DOWN;
        Player_SetAnimFacing(p);
      }
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      if (++p->stateTimer > 27) {
        Player_SetAction(p, PACT_UNK_7, 1);
      }
      break;
    }
    case 1: {
      p->beast.flags |= SPRFLAG_AFFINE;
      p->beast.scaleX = 64 - (u8)p->stateTimer * 4;
      if (p->stateTimer > 8) {
        p->beast.scaleY = p->stateTimer * 8;
        p->floatHeight = (p->stateTimer - 8) * 20;
        Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 2: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      p->floatHeight = p->stateTimer * 200 + 160;
      if (++p->stateTimer > 7) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
        Player_SetAction(p, PACT_IDLE, 0);
        p->lockedUpdate = Player_UpdateLockedHidden;
        Player_NotifyLockedDone(p);
      }
      break;
    }
    case 3: {
      if (p->stateTimer == 0) {
        p->facing = DIR8_DOWN;
        Player_SetAnimFacing(p);
      }
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      p->beast.flags |= SPRFLAG_AFFINE;
      p->beast.scaleX = 4;
      p->beast.scaleY = 120;
      p->floatHeight = (8 - p->stateTimer) * 200 + 160;
      if (++p->stateTimer > 7) {
        Player_SetAction(p, PACT_UNK_7, 4);
      }
      break;
    }
    case 4: {
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      p->beast.flags |= SPRFLAG_AFFINE;
      p->beast.scaleX = 64 - (15 - (u8)p->stateTimer) * 4;
      if (p->stateTimer < 8) {
        p->beast.scaleY = (15 - p->stateTimer) * 8;
        p->floatHeight = (8 - p->stateTimer) * 20;
      } else {
        p->beast.scaleY = 64;
        p->floatHeight = 0;
        Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_UNK_7, 5);
      }
      break;
    }
    case 5: {
      p->beast.flags &= ~SPRFLAG_AFFINE;
      AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animDir, p->xflip);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      if (++p->stateTimer > 3) {
        Player_SetAnimFacing(p);
        Player_ReturnToLockedIdle(p);
        p->lockedUpdate = Player_AdvanceMouseAnim;
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// マウスの被弾の吹き飛び, アニメ 2 を進めながら Player_UpdateBatKnockback と同じく押し出し, 止まったら向きを合わせ直して PACT_IDLE に戻し lockedUpdate を Player_AdvanceMouseAnim にする
void Player_UpdateMouseKnockback(Player* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_DAMAGE);
    p->stateTimer++;
  }
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 2, p->animDir, p->xflip);
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
    p->lockedUpdate = Player_AdvanceMouseAnim;
    Player_NotifyLockedDone(p);
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
  AuxAnim_SetAnim(&p->beastAnim, p->mouseAnim, 0, p->animDir, p->xflip);
  AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
  p->flashPlttID = 290;
  if ((p->plttFlashTimer += 3) > 32) {
    p->plttFlashTimer = 32;
  }
  if (++p->stateTimer > 31) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
    Player_ReturnToLockedIdle(p);
    p->revertNotifyPending = TRUE;
  }
}

// 棺桶 (スリーピング) のアニメを coffin 番目に合わせて1コマ進める
void Player_AdvanceCoffinAnim(Player* p) {
  AuxAnimState* anim = &p->beastAnim;

  AuxAnim_SetAnim(anim, p->coffinAnim, p->coffin, 0, 0);
  AuxSprite_AdvanceAnim(&p->beast, anim);
}

// スリーピング (棺桶獣) のワープ演出 (lockedUpdate), 棺桶のアニメを送りながら縦に伸びて消え (state 0-2), 縮みながら降りて現れる (state 3-5)
void Player_UpdateSleepingWarp(Player* p) {
  switch (p->state) {
    case 0: {
      AuxAnim_SetAnim(&p->beastAnim, p->coffinAnim, p->coffin, 0, 0);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      if (++p->stateTimer > 27) {
        Player_SetAction(p, PACT_UNK_7, 1);
      }
      break;
    }
    case 1: {
      p->beast.flags |= SPRFLAG_AFFINE;
      p->beast.scaleX = 64 - (u8)p->stateTimer * 4;
      if (p->stateTimer > 8) {
        p->beast.scaleY = p->stateTimer * 8;
        p->floatHeight = (p->stateTimer - 8) * 20;
        Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 2: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      p->floatHeight = p->stateTimer * 200 + 160;
      if (++p->stateTimer > 7) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY);
        Player_SetAction(p, PACT_IDLE, 0);
        p->lockedUpdate = Player_UpdateLockedHidden;
        Player_NotifyLockedDone(p);
      }
      break;
    }
    case 3: {
      if (p->stateTimer == 0) {
        p->facing = DIR8_DOWN;
        Player_SetAnimFacing(p);
      }
      AuxAnim_SetAnim(&p->beastAnim, p->coffinAnim, p->coffin, 0, 0);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      p->beast.flags |= SPRFLAG_AFFINE;
      p->beast.scaleX = 4;
      p->beast.scaleY = 120;
      p->floatHeight = (8 - p->stateTimer) * 200 + 160;
      if (++p->stateTimer > 7) {
        Player_SetAction(p, PACT_UNK_7, 4);
      }
      break;
    }
    case 4: {
      AuxAnim_SetAnim(&p->beastAnim, p->coffinAnim, p->coffin, 0, 0);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      p->beast.flags |= SPRFLAG_AFFINE;
      p->beast.scaleX = 64 - (15 - (u8)p->stateTimer) * 4;
      if (p->stateTimer < 8) {
        p->beast.scaleY = (15 - p->stateTimer) * 8;
        p->floatHeight = (8 - p->stateTimer) * 20;
      } else {
        p->beast.scaleY = 64;
        p->floatHeight = 0;
        Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
      }
      if (++p->stateTimer > 15) {
        Player_SetAction(p, PACT_UNK_7, 5);
      }
      break;
    }
    case 5: {
      p->beast.flags &= ~SPRFLAG_AFFINE;
      AuxAnim_SetAnim(&p->beastAnim, p->coffinAnim, p->coffin, 0, 0);
      AuxSprite_AdvanceAnim(&p->beast, &p->beastAnim);
      if (++p->stateTimer > 3) {
        Player_SetAnimFacing(p);
        Player_ReturnToLockedIdle(p);
        p->lockedUpdate = Player_AdvanceCoffinAnim;
        Player_NotifyLockedDone(p);
      }
      break;
    }
  }
}

// スリーピングから黒ジャンゴへ戻る変身, 10フレームは棺桶のアニメ coffin + 8 を進め, その後は点滅しながら human を出して 40 フレームで黒ジャンゴのフォームへ切り替える
void Player_RevertSleepingToDarkDjango(Player* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_COFFIN_OPEN);
    if (p->badCondTimer[BAD_POISON] != 0) {
      p->human.plttID = OBP_POISON;
    } else if (KAAMOS(p->isSabata) > 0) {
      p->human.plttID = OBP_KAAMOS;
    } else if (Player_TestEquipBuff(p, EBUFF_MEGAPOWER)) {
      p->human.plttID = OBP_MEGAPOWER;
    } else if (Player_TestEquipBuff(p, EBUFF_GUTSPOWER)) {
      p->human.plttID = OBP_GUTSPOWER;
    } else if (Player_TestEquipBuff(p, EBUFF_PROTOPOWER)) {
      p->human.plttID = OBP_PROTOPOWER;
    } else if (Player_TestEquipBuff(p, EBUFF_TOADPOWER)) {
      p->human.plttID = OBP_TOADPOWER;
    } else {
      p->human.plttID = OBP_BDJANGO;
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
    Player_ReturnToLockedIdle(p);
    p->revertNotifyPending = TRUE;
  }
}

// 制限時間つきの太陽チャージ (lockedUpdate), 日光を浴びて太陽ゲージぶん timedCharge を貯め timedChargeGoal に届けば doneScriptID を引数 1 で, 時間切れなら引数 0 で実行する
void Player_UpdateTimedSolarCharge(Player* p) {
  Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);

  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      if (p->input->pressed & A_BUTTON) {
        Player_SetAction(p, PACT_UNK_7, 1);
      }
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        p->facing = DIR8_DOWN;
        p->animDir = 1;
        p->xflip = FALSE;
        Player_SetChargePos(p);
        p->stateTimer++;
      }
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        PlaySound_082406e0(SE_PALM);
        if (!(p->input->down & A_BUTTON)) {
          Player_SetAction(p, PACT_UNK_7, 4);
        } else if (Player_TestFlag20(p, PFLAG20_SUNBATHING)) {
          PlaySound_082406e0(NOISE_SOLAR_CHARGE);
          p->chargeSoundOn = 1;
          p->chargeVoiceTimer = 0;
          Player_SetAction(p, PACT_UNK_7, 2);
        } else {
          p->chargeVoiceTimer = 0;
          Player_SetAction(p, PACT_UNK_7, 3);
        }
      }
      break;
    }
    case 2: {
      Player_SetFlag20(p, PFLAG20_QC | PFLAG20_PALM_UP);
      if (p->chargeVoiceTimer < 5) {
        if (++p->chargeVoiceTimer == 5 && p->kind == PLAYER_SOLAR_DJANGO) {
          PlaySound_082406e0(VO_RDJANGO_TAIYO);
        }
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 9), Q6(1));
      p->shadowOffset.z = 30;
      Player_SpawnSolarChargePtcl(p, &p->chargePos);
      if (!(p->input->down & A_BUTTON)) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->chargeSoundOn = 0;
        Player_SetAction(p, PACT_UNK_7, 4);
      } else if (!Player_TestFlag20(p, PFLAG20_SUNBATHING)) {
        sound_08240740(NOISE_SOLAR_CHARGE);
        p->chargeSoundOn = 0;
        Player_SetAction(p, PACT_UNK_7, 3);
      } else {
        s32 sun = gStat->sunGauge;

        p->timedCharge += sun;
        if (p->timedCharge >= p->timedChargeGoal) {
          HUD_RemoveCountdown();
          Player_SetAction(p, PACT_UNK_7, 5);
          if (p->doneScriptID != 0) {
            s32 id = p->doneScriptID;
            ScriptArgs args;
            u32 argv;

            args.argc = 1;
            args.argv = &argv;
            argv = 1;
            p->doneScriptID = 0;
            VM_ExecByID(id, &args);
          }
        }
      }
      break;
    }
    case 3: {
      Player_SetFlag20(p, PFLAG20_PALM_UP);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      p->shadowOffset.z = 30;
      if (!(p->input->down & A_BUTTON)) {
        Player_SetAction(p, PACT_UNK_7, 4);
      } else if (Player_TestFlag20(p, PFLAG20_SUNBATHING)) {
        PlaySound_082406e0(NOISE_SOLAR_CHARGE);
        p->chargeSoundOn = 1;
        p->chargeVoiceTimer = 0;
        Player_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 4: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, PACT_UNK_7, 0);
      }
      break;
    }
    case 5: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 9), Q6(1));
      p->shadowOffset.z = 30;
      Player_SpawnSolarChargePtcl(p, &p->chargePos);
      break;
    }
  }

  if (p->state != 5) {
    if (--p->countdown == 0) {
      HUD_RemoveCountdown();
      sound_08240740(NOISE_SOLAR_CHARGE);
      Player_SetAnimFacing(p);
      Player_ReturnToLockedIdle(p);
      if (p->doneScriptID != 0) {
        s32 id = p->doneScriptID;
        ScriptArgs args;
        u32 argv;

        args.argc = 1;
        args.argv = &argv;
        argv = 0;
        p->doneScriptID = 0;
        VM_ExecByID(id, &args);
      }
    }
  }
}

// サバタ版の制限時間つき暗黒チャージ (lockedUpdate), 日光を浴びずにいると timedCharge が 4 ずつ貯まり timedChargeGoal に届けば doneScriptID を引数 1 で, 時間切れなら引数 0 で実行する
// 残差 418 対 426 命令, 原典は 0 / 1 / 0xFFFF を r5 / r6 / r7 / r2 に持って複数の case で使い回し, timedCharge の比較を ands 0xFFFF で切るが, こちらはレジスタの持ち方が違い case 1 と case 3 の末尾が深く合流し plttFlashTimer の格納先も共有される, 兄弟の Player_UpdateTimedSolarCharge は一致済み, 試済: 状態5への移行を Player_SetAction にする (原典は呼ばない)
NON_MATCH void Player_UpdateTimedDarkCharge(Player* p) {
#ifdef NONMATCHING_C
  Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);

  switch (p->state) {
    case 0: {
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 0), Q6(1));
      if (p->input->pressed & A_BUTTON) {
        Player_SetAction(p, PACT_UNK_7, 1);
      }
      break;
    }
    case 1: {
      if (p->stateTimer == 0) {
        p->facing = DIR8_DOWN;
        p->animDir = 1;
        p->xflip = FALSE;
        Player_SetChargePos(p);
        p->stateTimer++;
      }
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 8), Q6(1))) {
        PlaySound_082406e0(SE_PALM);
        if (!(p->input->down & A_BUTTON)) {
          Player_SetAction(p, PACT_UNK_7, 4);
        } else if (!Player_TestFlag20(p, PFLAG20_SUNBATHING)) {
          PlaySound_082406e0(VO_SABATA_ANKOKU);
          p->chargeSoundOn = 1;
          p->chargeVoiceTimer = 0;
          Player_SetAction(p, PACT_UNK_7, 2);
        } else {
          p->chargeVoiceTimer = 0;
          Player_SetAction(p, PACT_UNK_7, 3);
        }
      }
      break;
    }
    case 2: {
      Player_SetFlag20(p, PFLAG20_QC | PFLAG20_PALM_UP);
      if (p->chargeVoiceTimer < 5) {
        if (++p->chargeVoiceTimer == 5) {
          PlaySound_082406e0(NOISE_DARK_CHARGE);
        }
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 9), Q6(1));
      p->shadowOffset.z = 30;
      Player_SpawnDarkChargePtcl(p, &p->chargePos);
      p->flashPlttID = 290;
      if (p->stateTimer < 32) {
        p->plttFlashTimer = p->stateTimer;
      } else {
        p->plttFlashTimer = 64 - p->stateTimer;
      }
      if (++p->stateTimer > 64) {
        p->stateTimer = 0;
      }
      if (!(p->input->down & A_BUTTON)) {
        sound_08240740(NOISE_DARK_CHARGE);
        p->chargeSoundOn = 0;
        Player_SetAction(p, PACT_UNK_7, 4);
      } else if (Player_TestFlag20(p, PFLAG20_SUNBATHING)) {
        sound_08240740(NOISE_DARK_CHARGE);
        p->chargeSoundOn = 0;
        Player_SetAction(p, PACT_UNK_7, 3);
      } else {
        p->timedCharge += 4;
        if (p->timedCharge >= p->timedChargeGoal) {
          HUD_RemoveCountdown();
          p->state = 5;
          if (p->doneScriptID != 0) {
            s32 id = p->doneScriptID;
            ScriptArgs args;
            u32 argv;

            args.argc = 1;
            args.argv = &argv;
            argv = 1;
            p->doneScriptID = 0;
            VM_ExecByID(id, &args);
          }
        }
      }
      break;
    }
    case 3: {
      Player_SetFlag20(p, PFLAG20_PALM_UP);
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 10), Q6(1));
      p->shadowOffset.z = 30;
      if (!(p->input->down & A_BUTTON)) {
        Player_SetAction(p, PACT_UNK_7, 4);
      } else if (!Player_TestFlag20(p, PFLAG20_SUNBATHING)) {
        PlaySound_082406e0(NOISE_DARK_CHARGE);
        p->chargeSoundOn = 1;
        p->chargeVoiceTimer = 0;
        Player_SetAction(p, PACT_UNK_7, 2);
      }
      break;
    }
    case 4: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 11), Q6(1))) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, PACT_UNK_7, 0);
      }
      break;
    }
    case 5: {
      p->flashPlttID = 290;
      if (p->stateTimer < 32) {
        p->plttFlashTimer = p->stateTimer;
      } else {
        p->plttFlashTimer = 64 - p->stateTimer;
      }
      if (++p->stateTimer > 64) {
        p->stateTimer = 0;
      }
      Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 9), Q6(1));
      p->shadowOffset.z = 30;
      Player_SpawnDarkChargePtcl(p, &p->chargePos);
      break;
    }
  }

  if (p->state != 5) {
    if (--p->countdown == 0) {
      HUD_RemoveCountdown();
      sound_08240740(NOISE_DARK_CHARGE);
      Player_SetAnimFacing(p);
      Player_ReturnToLockedIdle(p);
      if (p->doneScriptID != 0) {
        s32 id = p->doneScriptID;
        ScriptArgs args;
        u32 argv;

        args.argc = 1;
        args.argv = &argv;
        argv = 0;
        p->doneScriptID = 0;
        VM_ExecByID(id, &args);
      }
    }
  }
#else
  INCFUNC("asm/func/Player_UpdateTimedDarkCharge.inc");
#endif
}

// 十字キーの押下状態を 4bit に畳んで方向番号に引き直す, どれも押していない or ありえない組み合わせは -1
Dir8S32 Player_GetDpadFacing(Player* p) {
  static const s16 sDpadFacingTable[17] = {
      [0] = -1,
      [1] = DIR8_UP,           // ↑
      [2] = DIR8_DOWN,         // ↓
      [3] = -1,                // ↑+↓ (invalid)
      [4] = DIR8_LEFT,         // ←
      [5] = DIR8_UP_LEFT,      // ←+↑
      [6] = DIR8_DOWN_LEFT,    // ←+↓
      [7] = -1,                // ↑+←+↓ (invalid)
      [8] = DIR8_RIGHT,        // →
      [9] = DIR8_UP_RIGHT,     // →+↑
      [10] = DIR8_DOWN_RIGHT,  // →+↓
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

void Player_PushFacingHistory(Player* p) {
  s32 i;

  for (i = 9; i > 0; i--) {
    p->facingHistory[i] = p->facingHistory[i - 1];
  }

  p->facingHistory[0] = Player_GetDpadFacing(p);
  if ((s16)p->facingHistory[0] >= 0) {
    p->facingHistory[0] = ((s16)p->facingHistory[0] + p->controlUp + 7) & 7;
  }
}

// エネチャージ音を止め, 見回し中なら見回しを終える
void Player_StopChargeAndLookAround(Player* p) {
  Player_StopEneChargeSound(p);
  if (p->lookAroundOffset.val) {
    Player_EndLookAround(p);
  }
}

// 見回し中なら見回しを終える
void Player_StopLookAround(Player* p) {
  if (p->lookAroundOffset.val) {
    Player_EndLookAround(p);
  }
}

// 熱中症が溜まっている間, heatstrokeTick が 15 を超えるたびに体から煙を出す (2500 以上は倍速)
void Player_UpdateHeatstrokeSmoke(Player* p) {
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

// 壁張り付きを続けるか, 壁の方 (actionDir とその両隣) へ入力していて壁側のタイルが 200 以上高ければ TRUE, そうでなければ壁から離れる向きにして PACT_IDLE に戻す
s32 Player_CanKeepWall(Player* p) {
  s32 dir;
  s32 left;
  s32 right;

  if (p->wallLockCount != 0) {
    return TRUE;
  }
  dir = p->actionDir;
  left = (dir + 7) & 7;
  right = (dir + 9) & 7;
  if ((s16)p->facingHistory[0] == dir || (s16)p->facingHistory[0] == left || (s16)p->facingHistory[0] == right) {
    s32 angle = ((p->actionDir + 1) & 7) << 5;
    WorldPos pos = p->mover.pos;
    u32 height;

    pos.x -= POLAR_X(50, angle);
    pos.z -= POLAR_Z(50, angle);
    height = TileHeightAt(&pos);
    if (height >= p->mover.pos.y + 200) {
      return TRUE;
    }
    p->facing = (p->actionDir + 4) & 7;
    Player_SetAnimFacing(p);
    p->action = PACT_IDLE;
  } else {
    p->facing = (dir + 4) & 7;
    Player_SetAnimFacing(p);
    p->action = PACT_IDLE;
  }
  return FALSE;
}

// 棺桶を引き続けるか, A を押していて, 棺桶が掴める state (1 / 0x10) で, 同じエレベーターで動いているか
s32 Player_CanKeepPullCoffin(Player* p) {
  if (!(p->input->down & A_BUTTON)) {
    return FALSE;
  }
  if (gCoffin == NULL) {
    return FALSE;
  }
  if (gCoffin->state != 1 && gCoffin->state != 0x10) {
    return FALSE;
  }
  if (!FUN_0808626c(p->elevatorID, p->elevatorFlags, gCoffin->elevatorID, gCoffin->unk_384)) {
    return FALSE;
  }
  return TRUE;
}

bool32 Player_CanGrabCoffin(Player* p) { return Coffin_CanGrabFrom(&p->mover.pos, p->elevatorID, p->elevatorFlags); }

// 入力と状態から次の行動を決める, 被弾中は吹き飛びの種類, L で魔法, B で攻撃, A で調べる/拾う, 十字キーで移動, 何もなければ 0
s32 Player_DecideAction(Player* p) {
  s32 action;

  if (p->action != PACT_SPIDER_WEB && p->spiderWebIdx >= 0) {
    p->knockbackTimer = 0;
    p->hurtbox.knockback = 0;
    p->floatHeight = 0;
    Player_SetAction(p, PACT_SPIDER_WEB, 0);
  }
  if (p->action != PACT_WALL && p->wallLockCount != 0) {
    Player_EnterWall(p, p->actionDir);
  }
  action = p->action;
  if (!HasGoodCond(p, GOOD_MINI) && (p->input->pressed & L_BUTTON)) {
    action = Player_GetMagicAction(p);
  }
  if (p->hurtbox.knockback != 0) {
    action = p->blownAway ? PACT_BLOWN_AWAY : 24;
    if (gCWolfTarget != NULL && gChangeWolfBiting != 0) {
      if (!(gCWolfTarget->flags & 1)) {
        gCWolfTarget->fn(gCWolfTarget->owner, 1, 60);
      }
      gCWolfTarget = NULL;
      gChangeWolfBiting = 0;
    }
    Player_StopChargeAndLookAround(p);
    return action;
  }
  if (!(action == PACT_DAMAGED || action == PACT_BLOWN_AWAY || action == PACT_FALL || action == PACT_LANDING || action == PACT_GRABBED || action == PACT_SPIDER_WEB || action == PACT_SEKIKA) && p->mashRecoverTimer != 0) {
    action = PACT_UNK_18;
  }
  switch (action) {
    case PACT_WALL: {
      if (!Player_CanKeepWall(p)) {
        action = PACT_IDLE;
      }
      break;
    }
    case PACT_PULL_COFFIN: {
      if (!Player_CanKeepPullCoffin(p)) {
        PlaySound_082406e0(SE_COFFIN_CHAIN);
        action = PACT_IDLE;
      }
      break;
    }
    case PACT_DASH:
    case PACT_ATTACK:
    case PACT_PUSH:
    case PACT_UNK_7:
    case PACT_REFUELING:
    case PACT_SUN_MAGIC:
    case PACT_TRANSFORM:
    case PACT_CWOLF:
    case PACT_CBAT:
    case PACT_CMOUSE:
    case PACT_SLEEPING:
    case PACT_FREEZE:
    case PACT_HEALING:
    case PACT_DYNAMITE:
    case PACT_UNK_18:
    case PACT_SEKIKA:
    case PACT_SPIDER_WEB:
    case PACT_GRABBED:
    case PACT_FALL:
    case PACT_LANDING:
    case PACT_DAMAGED:
    case PACT_BLOWN_AWAY:
    case PACT_UNK_32: {
      break;
    }
    default: {
      if (HasGoodCond(p, GOOD_MINI)) {
        if ((p->input->pressed & A_BUTTON) && MapItemManager_TryOpen(&p->mover)) {
          action = PACT_IDLE;
        } else if ((s16)p->facingHistory[0] == -1 || (p->input->down & R_BUTTON)) {
          action = PACT_IDLE;
        } else {
          action = PACT_WALK;
        }
      } else if (p->input->pressed & B_BUTTON) {
        if (Player_TestForbidFlags(p, 0x4000) || (Player_TestForbidFlags(p, 1) && p->wpn.weaponKind != WK_OTHERS)) {
          action = PACT_IDLE;
          Player_ExecForbidScript(p);
        } else {
          action = PACT_ATTACK;
        }
      } else if (p->input->pressed & A_BUTTON) {
        if (Player_CanGrabCoffin(p)) {
          PlaySound_082406e0(SE_COFFIN_CHAIN);
          action = PACT_PULL_COFFIN;
        } else if (MapItemManager_TryOpen(&p->mover)) {
          action = PACT_IDLE;
        } else {
          action = PACT_UNK_7;
        }
      } else if ((s16)p->facingHistory[0] == -1 || (p->input->down & R_BUTTON)) {
        action = PACT_IDLE;
      } else {
        action = PACT_WALK;
      }
      break;
    }
  }
  return action;
}

// 人型 (ジャンゴ / サバタ) の毎フレームの後処理, 移動と表示・食らい判定のフラグを反映して human を mover の位置に置き, shakeTimer の間は human を揺らす
void Player_PostUpdateHuman(Player* p) {
  if (p->elevatorFlags == 0) {
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
  if (p->shakeTimer != 0) {
    s32 shake = (Random() & 0xF) - 7;
    p->human.pos.x += shake;
    p->human.pos.z -= shake;
    p->shakeTimer--;
  }
}

// プレイヤーの毎フレーム更新本体, unk_1c の状態ごとに行動関数を呼び, 通常状態では段差を登れるかも見る
void Player_UpdateDjango(Player* p) {
  // clang-format off
  static const PlayerFunc sDjangoActionFuncs[33] = {
      [PACT_IDLE] = Player_UpdateIdle,
      [PACT_WALK] = Player_UpdateWalk,
      [PACT_DASH] = MagicDash_Update,
      [PACT_ATTACK] = Player_UpdateDjangoAttack,
      [PACT_WALL] = Player_UpdateWall,
      [PACT_PUSH] = Player_UpdatePush,
      [PACT_PULL_COFFIN] = Player_UpdatePullCoffin,
      [PACT_UNK_7] = Player_UpdateSolarCharge,
      [PACT_REFUELING] = Player_UpdateSolarStand,
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
      [PACT_SEKIKA] = Player_UpdatePetrified,
      [PACT_SPIDER_WEB] = Player_UpdateSpiderWeb,
      [PACT_GRABBED] = Player_UpdateGrabbed,
      [PACT_FALL] = Player_UpdateFall,
      [PACT_LANDING] = Player_UpdateLanding,
      [PACT_DAMAGED] = Player_UpdateHurt,
      [PACT_BLOWN_AWAY] = Player_UpdateBlownAway,
      [PACT_DEATH_PRONE] = Player_UpdateDeath,
      [PACT_DEATH_SUPINE] = Player_UpdateBlownAwayDeath,
      [PACT_FALLDEATH] = Player_UpdateFallDeath,
      [PACT_DROWNING] = Player_UpdateDrowning,
      [PACT_HEATSTROKE] = Player_UpdateHeatstroke,
      [PACT_SPECIALDEATH] = Player_UpdateDjangoSpecialDeath,
      [PACT_UNK_32] = FUN_0806b06c,
  };  // 0x085ABCAC
  // clang-format on
  s32 action;

  Player_SetFlag20(p, PFLAG20_UPDATED);

  switch (p->mode) {
    case PMODE_ACTIVE: {
      Player_UpdateHeatstrokeSmoke(p);
      if (p->kind == PLAYER_SOLAR_DJANGO) {
        if (Player_IsInRain(p)) {
          Player_StepRain(p);
        }
      } else {
        if (p->flag20 & PFLAG20_SUNBATHING) {
          Player_StepSunburn(p, gStat->sunGauge);
        }
        if (Player_IsInRain(p)) {
          Player_StepRain(p);
          Player_StepRainDamage(p);
        }
      }

      Player_PushFacingHistory(p);
      action = Player_DecideAction(p);
      Player_HandleLookAround(p, action);
      sDjangoActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      } else {
        Player_ApplyWindPush(p);
      }

      Player_PostUpdateHuman(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      Player_CheckLavaHurt(p);
      if (p->kind == PLAYER_DARK_DJANGO) {
        Player_CheckPuddleHurt(p);
      }
      Player_UpdateIceSlide(p);

      if (!HasGoodCond(p, GOOD_MINI)) {
        bool32 canStep = !Player_IsOnIce(p->tile.attr[1]) && p->action == PACT_WALK && (p->tile.unk_0[0] & 1) && (p->facing & 1);
        if (canStep) {
          if (++p->wallPressTimer == 5) {
            Vec3 pos = p->mover.pos;
            s32 angle = ((p->facing + 5) & 7) * 32;
            pos.x += POLAR_X(50, angle);
            pos.z += POLAR_Z(50, angle);

            if ((u32)TileHeightAt(&pos) >= (u32)(p->mover.pos.y + Q8(0.782))) {
              s32 attr = GetTileAttrAt(&pos);
              if (!(attr & TATTR_UNK_2)) {
                p->actionDir = p->facing;
                p->wallSidling = 0;
                Player_SetAction(p, PACT_WALL, 0);
              }
            }
          }
        } else {
          p->wallPressTimer = 0;
        }
      }
      break;
    }
    case PMODE_DEAD: {
      p->flag20 |= PFLAG20_UNK_18;
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      if (p->action >= PACT_FALLDEATH && p->action <= PACT_SPECIALDEATH) {
        action = p->action;
      } else {
        action = (p->blownAway != 0) ? PACT_DEATH_SUPINE : PACT_DEATH_PRONE;
      }
      sDjangoActionFuncs[action](p);
      Player_PostUpdateHuman(p);
      break;
    }
    case PMODE_LOCKED: {
      p->flag20 |= PFLAG20_UNK_18;
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->lockedUpdate(p);
      Player_PostUpdateHuman(p);
      Player_StepBurnSmoke(p);
      break;
    }
  }
}

// サバタの毎フレーム更新本体, 状態ごとに行動関数を呼び, 日光を浴びると太陽ゲージの半分だけ焼け, 通常状態では段差を登れるかも見る
void Player_UpdateSabata(Player* p) {
  // clang-format off
  static const PlayerFunc sSabataActionFuncs[32] = {
      [PACT_IDLE] = Player_UpdateIdle,
      [PACT_WALK] = Player_UpdateWalk,
      [PACT_DASH] = Magic_ZeroShift,
      [PACT_ATTACK] = Player_UpdateSabataAttack,
      [PACT_WALL] = Player_UpdateWall,
      [PACT_PUSH] = Player_UpdatePush,
      [PACT_PULL_COFFIN] = Player_UpdatePullCoffin,
      [PACT_UNK_7] = Player_UpdateDarkCharge,
      [PACT_REFUELING] = Player_UpdateSolarStand,
      [PACT_SUN_MAGIC] = Sabata_BlackSun,
      [PACT_SEKIKA] = Player_UpdatePetrified,
      [PACT_SPIDER_WEB] = Player_UpdateSpiderWeb,
      [PACT_GRABBED] = Player_UpdateGrabbed,
      [PACT_FALL] = Player_UpdateFall,
      [PACT_LANDING] = Player_UpdateLanding,
      [PACT_DAMAGED] = Player_UpdateHurt,
      [PACT_BLOWN_AWAY] = Player_UpdateBlownAway,
      [PACT_DEATH_PRONE] = Player_UpdateDeath,
      [PACT_DEATH_SUPINE] = Player_UpdateBlownAwayDeath,
      [PACT_FALLDEATH] = Player_UpdateFallDeath,
      [PACT_DROWNING] = Player_UpdateDrowning,
      [PACT_HEATSTROKE] = Player_UpdateHeatstroke,
      [PACT_SPECIALDEATH] = Player_UpdateSabataSpecialDeath,
  };  // 0x085ABD30
  // clang-format on

  s32 action;

  Player_SetFlag20(p, PFLAG20_UPDATED);

  switch (p->mode) {
    case PMODE_ACTIVE: {
      Vec3 pos;
      s32 angle;
      s32 attr;
      bool32 canStep;

      Player_UpdateHeatstrokeSmoke(p);
      if (p->flag20 & PFLAG20_SUNBATHING) {
        s32 sun = gStat->sunGauge;

        Player_StepSunburn(p, sun >> 1);
      }
      if (Player_IsInRain(p)) {
        Player_StepRain(p);
      }

      Player_PushFacingHistory(p);
      action = Player_DecideAction(p);
      Player_HandleLookAround(p, action);
      sSabataActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      } else {
        Player_ApplyWindPush(p);
      }

      Player_PostUpdateHuman(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      Player_CheckLavaHurt(p);
      Player_UpdateIceSlide(p);

      if (!HasGoodCond(p, GOOD_MINI)) {
        canStep = !Player_IsOnIce(p->tile.attr[1]) && p->action == PACT_WALK && (p->tile.unk_0[0] & 1) && (p->facing & 1);
        if (canStep) {
          if (++p->wallPressTimer == 5) {
            pos = p->mover.pos;
            angle = ((p->facing + 5) & 7) * 32;
            pos.x += POLAR_X(50, angle);
            pos.z += POLAR_Z(50, angle);

            if ((u32)TileHeightAt(&pos) >= (u32)(p->mover.pos.y + Q8(0.782))) {
              attr = GetTileAttrAt(&pos);
              if (!(attr & TATTR_UNK_2)) {
                p->actionDir = p->facing;
                p->wallSidling = 0;
                Player_SetAction(p, PACT_WALL, 0);
              }
            }
          }
        } else {
          p->wallPressTimer = 0;
        }
      }
      break;
    }
    case PMODE_DEAD: {
      p->flag20 |= PFLAG20_UNK_18;
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      if (p->action >= PACT_FALLDEATH && p->action <= PACT_SPECIALDEATH) {
        action = p->action;
      } else {
        action = (p->blownAway != 0) ? PACT_DEATH_SUPINE : PACT_DEATH_PRONE;
      }
      sSabataActionFuncs[action](p);
      Player_PostUpdateHuman(p);
      break;
    }
    case PMODE_LOCKED: {
      p->flag20 |= PFLAG20_UNK_18;
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->lockedUpdate(p);
      Player_PostUpdateHuman(p);
      Player_StepBurnSmoke(p);
      break;
    }
  }
}

// バット時の次の行動を入力から決める, 吹き飛ばし中は PACT_DAMAGED, 方向入力があり R を押していなければ PACT_WALK
s32 Player_GetBatAction(Player* p) {
  u32 action;
  if (p->action != PACT_SPIDER_WEB && p->spiderWebIdx >= 0) {
    p->knockbackTimer = 0;
    p->hurtbox.knockback = 0;
    p->floatHeight = 0;
    Player_SetAction(p, PACT_SPIDER_WEB, 0);
  }
  action = p->action;
  if (p->input->pressed & L_BUTTON) {
    action = Player_GetMagicAction(p);
  }
  if (p->hurtbox.knockback != 0) {
    action = PACT_DAMAGED;
  } else if (action != PACT_DAMAGED && action != PACT_SPIDER_WEB && action != PACT_SEKIKA && action != PACT_CBAT) {
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
  if (attr & TATTR_FALLDEATH) {
    return TRUE;
  }
  if (Player_IsInLava(attr)) {
    return TRUE;
  }
  return FALSE;
}

// 移動先がエレベーターの中心から ±100 を出ないように mover.delta を詰める, エレベーター外で滑る床なら delta を 0 にする
void Player_ClampElevatorMove(Player* p) {
  Vec3 pos;

  pos.x = p->mover.pos.x + p->mover.delta.x;
  pos.z = p->mover.pos.z + p->mover.delta.z;
  if (p->elevatorFlags & ELEV_MOVING) {
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

// バット時の毎フレームの後処理, 移動を反映し, 浮遊の高さ batHeight を 16 フレームごとに引き直す目標 batHeightTarget へ寄せ, 表示と食らい判定のフラグを反映する
// 残差は reload の一時レジスタ 2 か所のみ (154/154), 原典は乱数表のアドレスを r3, 0x383 のオフセットを r2 に置くが, こちらは r1 / r3
// Tier A-C 試済 (_Random(table), >> 3 と / 8, 足す順, batHeight のポインタ), 未: reload の巡回をずらす手
NON_MATCH void Player_PostUpdateBat(Player* p) {
#ifdef NONMATCHING_C
  Player_ClampElevatorMove(p);
  Mover_ApplyMove(&p->mover);
  FUN_080417dc(&p->mover);

  if (p->action <= PACT_WALK) {
    if (p->batHeightTimer == 0) {
      p->batHeightTarget = Mod(Random() >> 3, 100) + 140;
      p->batHeightTimer = 16;
    } else {
      p->batHeightTimer--;
    }
    if (p->batHeight <= p->batHeightTarget - 4) {
      p->batHeight += 4;
    } else if (p->batHeight >= p->batHeightTarget + 8) {
      p->batHeight -= 8;
    } else {
      p->batHeight = p->batHeightTarget;
    }
  }
  p->beast.pos.y = p->mover.pos.y + p->batHeight + p->floatHeight;

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
      [PACT_IDLE] = Player_UpdateBatIdle,
      [PACT_WALK] = Player_UpdateBatWalk,
      [PACT_CBAT] = Player_UndoChangeBat,
      [PACT_SEKIKA] = Player_UpdateBatPetrified,
      [PACT_SPIDER_WEB] = Player_UpdateBatSpiderWeb,
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
        Player_StepRain(p);
        Player_StepRainDamage(p);
      }

      Player_PushFacingHistory(p);
      action = Player_GetBatAction(p);
      Player_HandleLookAround(p, action);
      sBatActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      }

      Player_ApplyWindPush(p);
      Player_PostUpdateBat(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      Player_UpdateIceSlide(p);
      break;
    }
    case PMODE_LOCKED: {
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->lockedUpdate(p);
      Player_PostUpdateBat(p);
      Player_StepBurnSmoke(p);
      break;
    }
  }
}

// --------------------------------------------

// マウス時の次の行動を入力から決める, Player_GetBatAction の別版, A で何も開けられなければ PACT_WALL に, PACT_LANDING / PACT_WALL / PACT_CMOUSE 中も行動を据え置く
s32 Player_GetMouseAction(Player* p) {
  u32 action;
  if (p->action != PACT_SPIDER_WEB && p->spiderWebIdx >= 0) {
    p->knockbackTimer = 0;
    p->hurtbox.knockback = 0;
    p->floatHeight = 0;
    Player_SetAction(p, PACT_SPIDER_WEB, 0);
  }
  action = p->action;
  if (p->input->pressed & L_BUTTON) {
    action = Player_GetMagicAction(p);
  }
  if (p->hurtbox.knockback != 0) {
    action = PACT_DAMAGED;
  } else if (action != PACT_DAMAGED && action != PACT_SPIDER_WEB && action != PACT_SEKIKA && action != PACT_LANDING && action != PACT_WALL && action != PACT_CMOUSE) {
    struct Input* input = p->input;
    if (input->pressed & A_BUTTON) {
      if (MapItemManager_TryOpen(&p->mover)) {
        action = PACT_IDLE;
      } else {
        action = PACT_WALL;
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
      [PACT_IDLE] = Player_UpdateMouseIdle,
      [PACT_WALK] = Player_UpdateMouseWalk,
      [PACT_WALL] = Player_UpdateMouseMakeNoise,
      [PACT_CMOUSE] = Player_UndoChangeMouse,
      [PACT_SEKIKA] = Player_UpdateMousePetrified,
      [PACT_SPIDER_WEB] = Player_UpdateMouseSpiderWeb,
      [PACT_LANDING] = Player_UpdateMouseLanding,
      [PACT_DAMAGED] = Player_UpdateMouseHurt,
  };  // 0x085ABE1C
  // clang-format on

  Player_SetFlag20(p, PFLAG20_UPDATED | PFLAG20_SNEAKING | PFLAG20_UNK_18);

  switch (p->mode) {
    case PMODE_ACTIVE: {
      s32 action;

      if (p->flag20 & PFLAG20_SUNBATHING) {
        Player_StepSunburn(p, gStat->sunGauge);
      }
      if (Player_IsInRain(p)) {
        Player_StepRain(p);
        Player_StepRainDamage(p);
      }

      Player_PushFacingHistory(p);
      action = Player_GetMouseAction(p);
      Player_HandleLookAround(p, action);
      sMouseActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      }

      Player_PostUpdateMouse(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      Player_CheckLavaHurt(p);
      Player_CheckPuddleHurt(p);
      Player_UpdateIceSlide(p);
      break;
    }
    case PMODE_LOCKED: {
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->lockedUpdate(p);
      Player_PostUpdateMouse(p);
      Player_StepBurnSmoke(p);
      break;
    }
  }
}

// --------------------------------------------

// スリーピング時の次の行動を入力から決める, エレファン運搬中だけ歩けて B で PACT_ATTACK, それ以外は A で宝箱を開けるだけ
s32 Player_GetSleepingAction(Player* p) {
  u32 action;
  if (p->action != PACT_SPIDER_WEB && p->spiderWebIdx >= 0) {
    p->knockbackTimer = 0;
    p->hurtbox.knockback = 0;
    p->floatHeight = 0;
    Player_SetAction(p, PACT_SPIDER_WEB, 0);
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

// スリーピング時の毎フレームの後処理, 移動を反映して beast を揺れ (coffinShake) と浮きの分ずらし, 表示と食らい判定のフラグを反映する
void Player_PostUpdateSleeping(Player* p) {
  Mover_ApplyMove(&p->mover);
  FUN_080417dc(&p->mover);

  p->beast.pos.x += p->coffinShake.x;
  p->beast.pos.y += p->floatHeight;
  p->beast.pos.z += p->coffinShake.z;

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
      [PACT_ATTACK] = Player_UpdateSleepingAttack,
      [PACT_WALL] = Player_UpdateSleepingCloseLid,
      [PACT_SLEEPING] = Player_UndoSleeping,
      [PACT_SPIDER_WEB] = Player_UpdateSleepingSpiderWeb,
  };  // 0x085ABE88
  // clang-format on

  Player_SetFlag20(p, PFLAG20_UPDATED | PFLAG20_UNK_18);
  p->coffinShake.x = 0;
  p->coffinShake.z = 0;
  if (p->attackVoiceCooldown != 0) {
    p->attackVoiceCooldown--;
  }

  switch (p->mode) {
    case PMODE_ACTIVE: {
      s32 action;

      Player_PushFacingHistory(p);
      action = Player_GetSleepingAction(p);
      Player_HandleLookAround(p, action);
      sSleepingActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      }

      Player_PostUpdateSleeping(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      Player_CheckLavaHurt(p);
      Player_UpdateIceSlide(p);
      break;
    }
    case PMODE_LOCKED: {
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->lockedUpdate(p);
      Player_PostUpdateSleeping(p);
      break;
    }
  }
}

// GAMEFLAG_CROSSOVER が立っているときの updateCallback
void Player_UpdateCrossoverDjango(Player* p) {
  // clang-format off
  static const PlayerFunc sCrossoverDjangoActionFuncs[28] = {
      [PACT_IDLE] = Player_UpdateIdle,
      [PACT_WALK] = Player_UpdateWalk,
      [PACT_DASH] = Player_UpdateCrossoverDash,
      [PACT_ATTACK] = Player_UpdateDjangoAttack,
      [PACT_WALL] = Player_UpdateWall,
      [PACT_PUSH] = Player_UpdatePush,
      [PACT_PULL_COFFIN] = Player_UpdatePullCoffin,
      [PACT_UNK_7] = Player_UpdateSolarCharge,
      [PACT_REFUELING] = Player_UpdateSolarStand,
      [PACT_SUN_MAGIC] = MagicRisingSun_08068944,
      [PACT_TRANSFORM] = MagicTransform_0806b92c,
      [PACT_CWOLF] = MagicChangeWolf_0806eb40,
      [PACT_CBAT] = MagicChangeBat_0806bc74,
      [PACT_CMOUSE] = MagicChangeMouse_0806bf18,
      [PACT_SLEEPING] = MagicSleeping_0806c124,
      [PACT_FREEZE] = MagicFreeze_08069710,
      [PACT_HEALING] = MagicHealing_0806f3a0,
      [PACT_DYNAMITE] = Player_UpdateCrossoverDynamite,
      [PACT_UNK_18] = FUN_08069c8c,
      [PACT_SEKIKA] = Player_UpdatePetrified,
      [PACT_SPIDER_WEB] = Player_UpdateSpiderWeb,
      [PACT_GRABBED] = Player_UpdateGrabbed,
      [PACT_FALL] = Player_UpdateFall,
      [PACT_LANDING] = Player_UpdateLanding,
      [PACT_DAMAGED] = Player_UpdateHurt,
      [PACT_BLOWN_AWAY] = Player_UpdateBlownAway,
      [PACT_DEATH_PRONE] = Player_UpdateDeath,
      [PACT_DEATH_SUPINE] = Player_UpdateBlownAwayDeath,
  };  // 0x085ABEDC
  // clang-format on

  s32 action;

  Player_SetFlag20(p, PFLAG20_UPDATED);

  switch (p->mode) {
    case PMODE_ACTIVE: {
      Vec3 pos;
      s32 angle;
      s32 height;
      s32 attr;
      bool32 busy;
      u16 n;
      bool32 canStep;

      Player_PushFacingHistory(p);
      action = Player_DecideAction(p);
      Player_HandleLookAround(p, action);
      sCrossoverDjangoActionFuncs[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      } else {
        Player_ApplyWindPush(p);
      }

      Player_PostUpdateHuman(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      Player_CheckLavaHurt(p);
      Player_UpdateIceSlide(p);

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
        if (++p->wallPressTimer == 5) {
          pos = p->mover.pos;
          angle = ((p->facing + 5) & 7) * 32;
          pos.x += POLAR_X(50, angle);
          pos.z += POLAR_Z(50, angle);

          height = TileHeightAt(&pos);
          if ((u32)height >= (u32)(p->mover.pos.y + Q8(0.782))) {
            attr = GetTileAttrAt(&pos);
            if (!(attr & TATTR_UNK_2)) {
              p->actionDir = p->facing;
              p->wallSidling = 0;
              Player_SetAction(p, PACT_WALL, 0);
            }
          }
        }
      } else {
        p->wallPressTimer = 0;
      }
      break;
    }
    case PMODE_DEAD: {
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      if (p->action >= PACT_FALLDEATH && p->action <= PACT_HEATSTROKE) {
        action = p->action;
      } else {
        action = (p->blownAway != 0) ? PACT_DEATH_SUPINE : PACT_DEATH_PRONE;
      }
      sCrossoverDjangoActionFuncs[action](p);
      Player_PostUpdateHuman(p);
      break;
    }
    case PMODE_LOCKED: {
      Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
      p->lockedUpdate(p);
      Player_PostUpdateHuman(p);
      break;
    }
  }
}

// Player の登録表と関連するグローバルをまとめて 0 に戻す
// 単体ではバイト一致するが, 同じ TU の前の関数の .LC 数でレジスタ割当が変わる (agbcc-internals.md §10), 前の関数を C にするたびに壊れるので INCFUNC に戻している
NON_MATCH void UNUSED Player_ResetGlobals(Player* p) {
#ifdef NONMATCHING_C
  s32 i;

  gPlayerCount = 0;
  for (i = 0; i < 4; i++) {
    gPlayerPtr[i] = NULL;
    gPlayerMoverIDs[i] = 0;
    gPlayerModes[i] = 0;
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
  INCFUNC("asm/func/Player_ResetGlobals.inc");
#endif
}

// PACT_LANDING に入り, 足元タイルの高さから見た現在の高さを控えて向きのアニメを合わせる
void Player_EnterLanding(Player* p) {
  u8 dir;

  if (p->kind == PLAYER_SLEEPING) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
  }
  Player_SetAction(p, PACT_LANDING, 0);
  p->floatHeight = 0;

  p->heightAboveTile = p->mover.pos.y - TileHeightAt(&p->mover.pos);

  dir = p->facing;
  PLAYER_SET_ANIM_8DIR(p, dir);
  p->hurtbox.knockback = 0;
}

// 壁張り付き (PACT_WALL) に入る, actionDir を dir にして反対を向く
void Player_EnterWall(Player* p, Dir8S32 dir) {
  Player_SetAction(p, PACT_WALL, 1);
  p->actionDir = dir;
  p->facing = (dir + 4) & 7;
  PLAYER_SET_ANIM_4DIR(p, p->actionDir);
  p->hurtbox.knockback = 0;
}

// プレイヤーが乗っているタイルの索引を返す, MoverTile の控えがあればそれ、無ければ座標から引く
s32 GetPlayerTileIdx(s32 n) {
  Player* p = gPlayerPtr[n];

  if (p->mover.tile != NULL) {
    return p->mover.tile->tileIdx[1];
  } else {
    return GetCollisionTileIdx(&p->mover.pos);
  }
}

void FUN_0807a524(Vec3* pos) {}

// 太陽スタンドの使用 (PACT_REFUELING) に入る, スタンドの座標 pos と param_3 を控える
void Player_EnterRefueling(Player* p, Vec3* pos, u16 param_3) {
  p->action = PACT_REFUELING;
  p->stateTimer = 0;
  p->state = 0;
  p->floatHeight = 0;
  p->refuelPos = *pos;
  p->refuelFacing = param_3;
}

bool32 FUN_0807a570(Player* p, s32 param_2) {
  bool32 ret;

  if (gGameFlags & GAMEFLAG_LINK) {
    FUN_080d040c(p);
    Player_SetAction(p, PACT_FALLDEATH, 0);
    return FALSE;
  }
  if (p->action == PACT_PULL_COFFIN) {
    ret = TRUE;
    Player_LockFall(p, p->facing, 1, 0);
  } else {
    ret = FALSE;
    Player_LockFall(p, p->facing, param_2, 0);
  }
  return ret;
}

// 武器 w と鎧 armor から攻撃力を出す, 銃は銃の熟練度と武器の攻撃力だけ, それ以外は鎧の効果を乗せたチカラとレベルに武器の値を足す, サバタはガン・デル・ヘル固定
s32 CalcAttack(WeaponData* w, const ArmorData* armor) {
  s32 val;
  s32 bonus;

  if (gStat->playerKind == PLAYER_SABATA) {
    return (gWeaponDB[WEAPON_GUN_DEL_HELL].atk + 10) * 2;
  }

  if (w->kind == WK_GUN) {
    if (GetWeaponSkillLevel(WK_GUN) >= 99) {
      return (w->atk + 10) * 2;
    }
    return ((Div(GetWeaponSkillLevel(WK_GUN), 10) - 8) * 5 + w->atk) * 2;
  }

  val = STATS(STAT_STRENGTH) + STAT_BONUS(STAT_STRENGTH);
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
  if (w->kind == WK_OTHERS) {  // 素手
    bonus = (GetWeaponSkillLevel(WK_OTHERS) + gStat->lv) >> 2;
  } else {
    bonus = w->quality + w->atk;
    if (bonus < 0) {
      bonus = 0;
    }
  }
  return val + bonus;
}

// 装備中の鎧を添えて CalcAttack に渡す, 鎧を装備していなければ NULL を渡す
s32 CalcAttackWithEquippedArmor(WeaponData* w) {
  s32 atk;

  if (EQUIPPED_ARMOR >= 0) {
    atk = CalcAttack(w, &gArmorDB[GetInventoryArmor(EQUIPPED_ARMOR)]);
  } else {
    atk = CalcAttack(w, NULL);
  }
  return atk;
}

// 鎧の効果を乗せたハヤサから派生値を出す, 鎧を渡さなければ素の値, サバタでプレイ中は gSabataDefence をそのまま返す
s32 CalcDefence(ArmorData* data) {
  s32 val;

  if (gStat->playerKind == PLAYER_SABATA) {
    return gSabataDefence;
  }

  val = STATS(STAT_AGILITY) + STAT_BONUS(STAT_AGILITY);
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
void AddPlayerExp(s32 amount) {
  if (gStat->playerKind != PLAYER_SABATA) {
    s32 exp;

    if (gPlayerPtr[0] != NULL && Player_TestEquipBuff(gPlayerPtr[0], EBUFF_TRAININGGEAR)) {
      amount = (amount * 3) >> 1;  // 1.5倍
    }
    exp = PLAYER_EXP + amount;
    PLAYER_EXP = exp;
    if (exp >= 999999) {
      PLAYER_EXP = 999999;
    }
  }
}

// 武器種 kind の経験値を amount 増やす, サバタでは増えず 9900 で止まる
void AddWeaponExp(s32 kind, s32 amount) {
  if (gStat->playerKind != PLAYER_SABATA && kind < 5) {
    WEAPON_EXP(kind) += amount;
    if (WEAPON_EXP(kind) >= 9900) {
      WEAPON_EXP(kind) = 9900;
    }
  }
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

// flag が 0 なら移動速度の減り speedPenalty を 1 増やす
void Player_AddSpeedPenalty(Player* p, u32 flag) {
  if (flag == 0) {
    p->speedPenalty++;
  }
}

// 座標を pos にし (mover / beast / human), gStat の保存座標にも書く
void Player_SetPosAndSave(Player* p, Vec3* pos) {
  p->mover.pos = *pos;
  p->beast.pos = *pos;
  p->human.pos = *pos;
  PLAYER_X = pos->x;
  PLAYER_Y = pos->y;
  PLAYER_Z = pos->z;
}

bool32 Player_TestElevatorFlags(Player* p, ElevatorFlagsU16 mask) {
  if (p->elevatorFlags & mask) {
    return TRUE;
  }
  return FALSE;
}

u32 Player_GetElevatorID(Player* p) { return p->elevatorID; }

void Player_SetElevatorFlags(Player* p, u32 flags, u32 elevatorID) {
  p->elevatorFlags |= flags;
  p->elevatorID = elevatorID;
}

void Player_ClearElevatorFlags(Player* p, u32 flags) {
  p->elevatorFlags &= ~flags;
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
  p->animDir = 0;
  Player_ClearElementalCond(p);
  p->hurtbox.flags |= HBFLAG_HIDDEN;
  p->hurtbox.knockback = 0;
  p->hurtbox.iframes = 0;
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
    p->grabbedVisible = 0;
  } else {
    p->human.flags &= ~SPRFLAG_HIDDEN;
    p->grabbedVisible = 1;
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
      p->damageNumOffset = *hitPos;
    }
    return ret;
  }
  return 0;
}

// PACT_GRABBED (拘束中) なら pos へ移して angle の向きへ吹き飛ばし, power > 0 ならダメージも与える, 拘束中でなければ -1
// 残差はレジスタ割り当てのみ (103/103), 原典は mode を r2, pos を r5, iframes を r6 に置き, 0x2E8 のオフセットを r7 に残して xflip の格納で subs r7, #1 と使い回す
// Tier A-C 試済 (条件の入れ子と結果変数, 末尾の if/else, angle の再代入, facing のスコープ), 未: 割り当て順を動かす手
// 原典は mode を読んだ r2 (== 1) を xflip = TRUE の格納に使い回す, 追試: Player_SetIframes 経由, 早期 return の形 (102 命令), mode を getter inline で読む形は不一致
NON_MATCH s32 Player_ReleaseGrabbed(Player* p, Vec3* pos, s32 knockback, s32 angle, s32 iframes, s32 flashPose, s32 power, HitboxAttributes attrs) {
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
  if (iframes > 0) {
    p->hurtbox.iframes = iframes;
  }
  p->mover.pos = *pos;
  facing = (((angle + 0xE0) & 0xFF) >> 6) * 2 + 1;
  p->facing = facing;
  if (facing > 4) {
    p->animDir = 8 - facing;
    p->xflip = TRUE;
  } else {
    p->animDir = facing;
    p->xflip = FALSE;
  }
  p->hurtbox.knockback = knockback;
  p->blownAway = 1;
  PlaySound_082406e0(SE_DAMAGE);
  if (p->mashRecoverTimer != 0) {
    p->mashRecoverTimer = 0;
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
  if (p->mashRecoverTimer != 0) {
    p->unk_3ea = 1;
    return FALSE;
  }
  if (p->kind == PLAYER_MOUSE || p->kind == PLAYER_SLEEPING) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
  }
  p->mashRecoverTimer = param_2;
  p->unk_3ea = 1;
  return TRUE;
}

// 倒れて待っている死亡の行動 (と PACT_UNK_18 の state 1) を, 点滅しながら消える state へ進める
void Player_StartDeathVanish(Player* p) {
  s32 action = p->action;

  if (action == PACT_DEATH_PRONE) {
    if (p->state == 3) {
      Player_SetAction(p, PACT_DEATH_PRONE, 4);
    }
  } else if (action == PACT_DEATH_SUPINE) {
    if (p->state == 4) {
      Player_SetAction(p, PACT_DEATH_SUPINE, 5);
    }
  } else if (action == PACT_SPECIALDEATH) {
    if (p->kind == PLAYER_SABATA) {
      if (p->state == 3) {
        Player_SetAction(p, PACT_SPECIALDEATH, 4);
      }
    } else if (p->state == 1) {
      Player_SetAction(p, PACT_SPECIALDEATH, 2);
    }
  } else if (p->mode == PMODE_LOCKED && action == PACT_UNK_18 && p->state == 1) {
    Player_SetAction(p, PACT_UNK_18, 4);
  }
}

// 体にまとわりつく粒子 (emitter) を kind で count 個出す, 種類が違えば今のを消して出し直し, 出せたら種類ごとに音とダメージ (2: +10, 3: 小さく弾かれる) を与える
void Player_InflictCrossoverElementalCond(Player* p, u32 kind, s32 count) {
  Vec3 spread;
  bool32 spawned;
  s32 i;

  if (!(gGameFlags & GAMEFLAG_CROSSOVER)) {
    return;
  }
  if (p->emitter.aliveCount != 0 && p->emitter.kind != kind) {
    if (p->emitter.kind == ELEMCOND_SEKIKA) {
      return;
    }
    Player_ResetElementalCond(p);
  }
  if (p->emitter.aliveCount == 0) {
    p->mashCountBase = p->mashCount;
    p->inkaTick = 0;
  }

  spread.x = (RandomNext() & 0xF) - 7;
  spread.y = -(RandomNext() & 0x1F);
  spread.z = 0;
  spawned = FALSE;
  for (i = 0; i < count; i++) {
    if (ElementalCondEmitter_AddParticle(&p->emitter, kind, 3600, &spread) >= 0) {
      spawned = TRUE;
    }
  }

  if (spawned) {
    if (p->emitter.kind == ELEMCOND_INKA) {
      PlaySound_082406e0(SE_IGNITE);
    } else if (p->emitter.kind == ELEMCOND_HYOKETU) {
      p->damage += 10;
      PlaySound_082406e0(SE_SOLIDIFY);
    } else if (p->emitter.kind == ELEMCOND_SEKIKA) {
      PlaySound_082406e0(SE_SOLIDIFY);
      p->hurtbox.knockback = 10;
      if (p->hurtbox.iframes == 0) {
        p->hurtbox.iframes = 1;
      }
      p->blownAway = 0;
    }
  }
  p->badCondTimer[BAD_POISON] = 0;
}

// '.i' から gPlayerPtr の idx を取得する, なかったら 0 (1P) を返す
u32 VM_GetPlayerIdx(void) { return VM_SeekToNamedArg('i') ? VM_GetValue() : 0; }

// '.p' があれば x, y, z を pos に読み込んで TRUE を返す
static bool32 VM_GetPosArg(Vec3* pos) {
  if (VM_SeekToNamedArg('p')) {
    pos->x = VM_GetValue(), pos->y = VM_GetValue(), pos->z = VM_GetValue();
    return TRUE;
  }
  return FALSE;
}

// 0xE14B
void Cmd_SetPlayerPos(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_GetPosArg(&p->mover.pos)) {
    if (VM_SeekToNamedArg('d')) {
      p->facing = VM_GetValue();
      if (p->facing > DIR8_DOWN) {
        p->animDir = 8 - p->facing;
        p->xflip = TRUE;
      } else {
        p->animDir = p->facing;
        p->xflip = FALSE;
      }
    }
    Map_InitMoverTile(&p->tile, &p->mover.pos);
    Player_SetAction(p, PACT_IDLE, 0);
    Player_StopEneChargeSound(p);
  }
}

// 0x7017, プレイヤーの向き取得
s32 Cmd_GetPlayerDir(void) {
  Player* p = GetPlayer(VM_GetPlayerIdx());

  if (p == NULL) {
    return gStat->playerDir;
  }
  if (p->action == PACT_WALL || p->action == PACT_PUSH) {  // 壁に背を向けている場合は背中が向いている方 (壁の方向)
    return (p->actionDir + 4) & 7;
  }
  return p->facing;
}

// 0x5986
bool32 Cmd_IsPlayerDead(void) {
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

// 0xD4B5, 鍛冶による武器経験値取得
void Cmd_AddForgeExp(void) {
  if (VM_SeekToNamedArg('t')) {
    s32 kind = VM_GetValue();

    if (VM_SeekToNamedArg('p')) {
      AddWeaponExp(kind, VM_GetValue());
    }
  }
}

// 0x440F, プレイヤーの装備効果に '.f' のビットが立っているかを返す
s32 Cmd_TestEquipBuff(void) {
  Player* p = GetPlayer(VM_GetPlayerIdx());
  EquipBuffs bits;

  if (p == NULL) {
    return 0;
  }
  if (VM_SeekToNamedArg('f')) {
    bits = VM_GetValue();
    return p->equipBuffs & bits;
  }
  return 0;
}

// 0xEA00, '.E' のアイテムの効果を Player に直接かける, IET_GOOD は '.t' (既定は value2 秒) だけよい状態にし, IET_HP は回復量を表示する
void Cmd_ApplyItemEffect(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('E')) {
    s32 id = VM_GetValue();
    if (gItemDB[id].effectType == IET_GOOD) {
      s32 timer = VM_SeekToNamedArg('t') ? VM_GetValue() : gItemDB[id].value2 * 60;
      p->goodCondID = gItemDB[id].value1;
      p->goodCondTimer = timer;
      p->goodFrom = id;
      p->flashPlttID = OBP_ELEMENT(0);
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
        CreateDamageNumber(&p->hurtbox, amount, 1, &p->mover.pos, &p->damageNumOffset, 0);
      }
      p->flashPlttID = OBP_ELEMENT(0);
      p->plttFlashTimer = 48;
    }
  }
}

// 0x0E15, プレイヤーに効いている良い状態の ID を返す, 無ければ -1
s32 Cmd_GetGoodCond(void) {
  Player* p = GetPlayer(VM_GetPlayerIdx());

  if (p == NULL) {
    return -1;
  }
  if (p->goodCondTimer == 0) {
    return -1;
  }
  return p->goodCondID;
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
void Cmd_SetPlayerForbidFlags(void) {
  Player* p = GetPlayer(VM_GetPlayerIdx());

  if (p != NULL && VM_SeekToNamedArg('f')) {
    Player_SetForbidFlags(p, VM_GetValue());
    if (Player_TestForbidFlags(p, 0x3FFE)) {
      p->magic.availableForm = Player_IsMagicAvailableForm(p, p->magic.id);
    }
    if (VM_SeekToNamedArg('p')) {
      p->forbidScriptID = VM_GetValue();
    }
  }
}

// 0x2B68
void Cmd_ClearElementalCond(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    Player_ClearElementalCond(gPlayerPtr[i]);
  }
}

// 0xDD0E
// 残差は最後の判定だけ (28/28): if (n <= 2) { return ... != 0; } の形で分岐の配置は一致したが, != 0 が rsbs/orrs/lsrs の値になる, 原典は cmp/beq で return 0 のブロックへ戻り movs r0, #1
// != 0 を if で書く形 (入れ子, &&, == 0 で早期 return), 三項演算子, > 0, static inline の判定, switch は return 0 の置き場が末尾へ移る
NON_MATCH bool32 Cmd_HasBadCond(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];
  s32 n;

  if (p == NULL || !VM_SeekToNamedArg('s')) {
    return FALSE;
  }
  n = VM_GetValue();
  if (n <= 2) {
    return p->badCondTimer[n] != 0;
  }
  return FALSE;
#else
  INCFUNC("asm/func/Cmd_HasBadCond.inc");
#endif
}

// 0x650B
void Cmd_ApplyBadCond(void) {
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
void Cmd_ClearBadCond(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('s')) {
    Player_ClearBadCondition(p, VM_GetValue());
  }
}

// 0xB603
void Cmd_ClearAllBadConds(void) {
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
    gPlayerPtr[i]->noSunburn = 1;
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
void Cmd_SetPlayerDead(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    Player_EnterDeadState(gPlayerPtr[i]);
  }
}

// 0xD8DF
void Cmd_PlayerSpecialDeath(void) {
  Player* p = GetPlayer(VM_GetPlayerIdx());

  if (p != NULL) {
    Player_EnterDeadState(p);
    if (VM_SeekToNamedArg('d')) {
      p->facing = VM_GetValue();
    }
    Player_SetAnimFacing(p);
    Player_SetAction(p, PACT_SPECIALDEATH, 0);
  }
}

// Cウルフ中に '.p' の座標が前方 ±32 かつ 2 タイル以内にあり, '.d' の向きも前方 ±32 以内なら真
// 残差は p の複写のみ, 原典は p を r8 と r9 に持ち facing だけ r9 から読む
// Tier A-C 試済 (向きの角度を Player* を受ける inline で取る, 添字ローカルを外す, facing を gPlayerPtr[i] から読み直す, 全部 gPlayerPtr[i] で読む), 未: p の複写の再現
// 追試: GetPlayer(VM_GetPlayerIdx()) と NULL の早期 return, p のフィールドごとの getter inline は p の複写を作らない
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
    p->emoteTimer = 0;
    p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 0x7F, 0, 0, 0, 0x50);
  }
  p->mode = PMODE_LOCKED;
  p->doneNotify = PDONE_NONE;
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
  p->hurtbox.knockback = 0;
  p->hurtbox.flags |= HBFLAG_HIDDEN;
  p->hurtbox.iframes = 0;
  if (p->lookAroundOffset.val != 0) {
    Player_EndLookAround(p);
  }
  Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
  Player_SetFlag20(p, PFLAG20_UNK_18);
}

// plttID のパレットへフェードインしてそのまま保つ演出を始める
void Player_StartPlttFadeIn(Player* p, s32 plttID) {
  p->lockedPlttFx = 1;
  p->flashPlttID = plttID;
}

// plttID のパレットへの点滅 (寄せて戻すのを繰り返す) を始める
void Player_StartPlttPulse(Player* p, s32 plttID) {
  p->lockedPlttFx = 2;
  p->flashPlttID = plttID;
}

// パレット演出 (lockedPlttFx) を止める
void Player_StopPlttEffect(Player* p) { p->lockedPlttFx = 0; }

void Player_SetPos(Player* p, WorldPos* src) { p->mover.pos = *src; }

// 操作不能の素立ちにして姿と影を隠したままにする
void Player_LockHidden(Player* p) {
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 0);
  p->human.flags |= SPRFLAG_HIDDEN;
  p->lockedUpdate = Player_UpdateLockedHidden;
}

// 向き (負なら据え置き) を指定して素立ちにし, 操作不能状態に移す (Cmd_LockPlayer から, イベント前の整え)
// フォームは変えず, 今の kind の待機ルーチンを lockedUpdate に据える, バットは向きが4方向しかないので奇数に丸めて animDir / xflip を自前で作る
void Player_Lock(Player* p, Dir8S32 dir8) {
  if (dir8 >= 0) {
    p->facing = dir8;
  }

  if (p->kind == PLAYER_BAT) {
    p->facing |= 1;
    PLAYER_SET_ANIM_4DIR(p, p->facing);
    p->lockedUpdate = Player_UpdateBatLockedIdle;
  } else {
    Player_SetAnimFacing(p);
    if (p->kind == PLAYER_MOUSE) {
      p->lockedUpdate = Player_AdvanceMouseAnim;
    } else if (p->kind == PLAYER_SLEEPING) {
      p->lockedUpdate = Player_AdvanceCoffinAnim;
    } else {
      p->lockedUpdate = Player_UpdateLockedIdle;
    }
  }

  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 0);
}

// 操作不能にして dir へ振り向かせ, 終わったら scriptID を実行する
void Player_LockTurnTo(Player* p, Dir8S32 dir, u32 scriptID) {
  p->targetDir = dir;
  p->doneScriptID = scriptID;
  p->lockedUpdate = Player_UpdateLockedTurn;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 0);
}

void FUN_0807ba14(Player* p, Dir8S32 dir) {
  if (dir >= 0) {
    p->facing = dir;
  }
  Player_SetAnimFacing(p);
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 1);
  p->lockedUpdate = Player_UpdateLockedIdle;
}

void FUN_0807ba50(Player* p, Dir8S32 dir, u32 scriptID) {
  if (dir >= 0) {
    p->facing = dir;
  }
  Player_SetAnimFacing(p);
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 2);
  p->lockedUpdate = Player_UpdateLockedIdle;
}

// 操作不能にして pos へ移動させる, フォームごとの移動ルーチンを lockedUpdate に据え, 着いたら dir を向く, scriptID は終わったときに実行するスクリプト
void Player_MoveTo(Player* p, Vec3* pos, u32 scriptID, Dir8S32 dir) {
  p->moveTarget = *pos;
  p->doneScriptID = scriptID;
  p->targetDir = dir;
  if (p->kind == PLAYER_BAT) {
    if (p->targetDir >= 0) {
      p->targetDir = ((p->targetDir >> 1) << 1) + 1;
    }
    p->lockedUpdate = Player_UpdateBatMoveTo;
  } else if (p->kind == PLAYER_MOUSE) {
    p->lockedUpdate = Player_UpdateMouseMoveTo;
  } else {
    if (p->kind == PLAYER_SLEEPING) {
      p->formRequest = TRUE;
      p->formRequestKind = PLAYER_DARK_DJANGO;
      p->lockedUpdate = Player_UpdateMoveTo;
    } else {
      p->lockedUpdate = Player_UpdateMoveTo;
    }
  }
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_WALK, 0);
}

// 操作不能にして棺桶を引きながら pos (NULL なら今の位置) まで歩かせ, 着いたら dir を向いて scriptID を実行する
void Player_LockPullCoffinTo(Player* p, Vec3* pos, Dir8S32 dir, s32 param_4, u32 scriptID) {
  if (pos == NULL) {
    p->moveTarget = p->mover.pos;
  } else {
    p->moveTarget = *pos;
  }
  p->doneScriptID = scriptID;
  p->unk_4a6 = param_4;
  p->targetDir = dir;
  p->unk_4a7 = 0x96;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_PULL_COFFIN, 0);
  p->lockedUpdate = Player_UpdatePullCoffinTo;
}

void FUN_0807bbb0(Player* p, s32 param_2, u32 scriptID) {
  Player_Lock(p, DIR8_DOWN);
  p->unk_4a6 = param_2;
  p->doneScriptID = scriptID;
  p->facing = DIR8_DOWN;
  p->animDir = 1;
  p->xflip = 0;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_7, 0);
  p->lockedUpdate = FUN_0807304c;
}

void FUN_0807bc14(Player* p, s32 param_2, u32 scriptID) {
  p->unk_4a6 = param_2;
  p->doneScriptID = scriptID;
  p->facing = DIR8_UP;
  p->animDir = 0;
  p->xflip = 0;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_7, 0);
  p->lockedUpdate = FUN_0807304c;
}

void FUN_0807bc64(Player* p, u32 scriptID) {
  if (p->mode == PMODE_LOCKED && p->action == PACT_UNK_7 && p->state != 0) {
    p->doneScriptID = scriptID;
    Player_EnterLockedState(p);
    Player_SetAction(p, PACT_UNK_7, 3);
    p->lockedUpdate = FUN_0807304c;
  }
}

void FUN_0807bcb0(Player* p, Dir8S32 dir, u32 scriptID) {
  Player_EnterLockedState(p);
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_18, 0);
  p->lockedUpdate = FUN_08073574;
}

void FUN_0807bcfc(Player* p, Dir8S32 dir) {
  Player_EnterLockedState(p);
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  PlaySound_082406e0(SONG_198);
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_18, 2);
  p->lockedUpdate = FUN_08073574;
}

void FUN_0807bd44(Player* p, Dir8S32 dir) {
  Player_EnterLockedState(p);
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_18, 1);
  p->lockedUpdate = FUN_08073574;
}

void FUN_0807bd84(Player* p, Dir8S32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_18, 3);
  p->lockedUpdate = FUN_08073574;
}

// 操作不能にして落とし穴の落下 (PACT_FALL) に入れる, param_3 を unk_4a6 / fallFadeMode に控える
void Player_LockFall(Player* p, Dir8S32 dir, s32 param_3, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  p->doneScriptID = scriptID;
  p->unk_4a6 = param_3;
  p->fallFadeMode = param_3;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_FALL, 0);
  if (p->kind == PLAYER_MOUSE) {
    p->lockedUpdate = Player_UpdateMouseFall;
  } else {
    if (p->kind == PLAYER_SLEEPING) {
      p->formRequest = TRUE;
      p->formRequestKind = PLAYER_DARK_DJANGO;
    }
    p->lockedUpdate = Player_UpdateLockedFall;
  }
}

// 操作不能にして floatHeight の高さから着地 (PACT_LANDING) させる
void Player_LockLanding(Player* p, Dir8S32 dir, s32 floatHeight, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  p->floatHeight = floatHeight;
  Player_SetAction(p, PACT_LANDING, 0);
  if (p->kind == PLAYER_MOUSE) {
    p->lockedUpdate = Player_UpdateMouseLand;
  } else {
    if (p->kind == PLAYER_SLEEPING) {
      p->formRequest = TRUE;
      p->formRequestKind = PLAYER_DARK_DJANGO;
    }
    p->lockedUpdate = Player_UpdateLockedLand;
  }
}

// 操作不能にして knockbackSpeed の速さで吹き飛ばす (PACT_DAMAGED)
void Player_LockKnockback(Player* p, Dir8S32 dir, s32 param_3, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  if (p->facing > DIR8_DOWN) {
    p->animDir = (8 - p->facing) >> 1;
    p->xflip = TRUE;
  } else {
    p->animDir = p->facing >> 1;
    p->xflip = FALSE;
  }
  p->knockbackSpeed_4a4 = param_3;
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_DAMAGED, 0);
  if (p->kind == PLAYER_BAT) {
    p->lockedUpdate = Player_UpdateBatKnockback;
  } else if (p->kind == PLAYER_MOUSE) {
    p->lockedUpdate = Player_UpdateMouseKnockback;
  } else {
    p->lockedUpdate = Player_UpdateLockedKnockback;
  }
}

// 操作不能にして吹き飛ばして倒す (PACT_BLOWN_AWAY), param_4 が 0 以外なら倒れたまま待つ
void Player_LockBlownAway(Player* p, Dir8S32 dir, s32 param_3, s32 param_4, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  if (p->facing > DIR8_DOWN) {
    p->animDir = (8 - p->facing) >> 1;
    p->xflip = TRUE;
  } else {
    p->animDir = p->facing >> 1;
    p->xflip = FALSE;
  }
  p->knockbackSpeed_4a4 = param_3;
  p->unk_4a6 = param_4;
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_BLOWN_AWAY, 0);
  p->lockedUpdate = Player_UpdateLockedBlownAway;
}

// 操作不能の吹き飛びで倒れたまま待っている (state 5) なら起き上がらせる
void Player_GetUpFromBlownAway(Player* p, s32 scriptID) {
  if (p->mode == PMODE_LOCKED && p->action == PACT_BLOWN_AWAY && p->state == 5) {
    p->doneScriptID = scriptID;
    p->state = 4;
    Player_EnterLockedState(p);
  }
}

// 操作不能にして dir の反対へ押し出し, 止まったら倒れてうつ伏せのまま待つ (Player_LockProne の倒れる途中から始める版)
void Player_LockKnockProne(Player* p, Dir8S32 dir, s32 param_3, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  if (p->facing > DIR8_DOWN) {
    p->animDir = (8 - p->facing) >> 1;
    p->xflip = TRUE;
  } else {
    p->animDir = p->facing >> 1;
    p->xflip = FALSE;
  }
  p->knockbackSpeed_4a4 = param_3;
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_DAMAGED, 0);
  p->lockedUpdate = Player_UpdateLockedCollapse;
}

// 操作不能にして dir を向いたうつ伏せに倒れた姿にする, 倒れるアニメ (46) を逆再生で最後のコマに置き, 倒れたまま待つ state 2 に入れる
void Player_LockProne(Player* p, Dir8S32 dir) {
  u16 animID;

  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  if (p->facing > DIR8_DOWN) {
    p->animDir = (8 - p->facing) >> 1;
    p->xflip = TRUE;
  } else {
    p->animDir = p->facing >> 1;
    p->xflip = FALSE;
  }
  Player_EnterLockedState(p);
  animID = p->animDir + Player_GetAnimIdx(p->kind, 46);
  MainSprite_SetAnim(&p->human, &p->humanGfx, animID, PLAYMODE_LOOP, MAIN_ANIM_REVERSE);
  MainSprite_AdvanceAnim(&p->human, &p->humanGfx);
  if (p->xflip) {
    p->human.flags |= SPRFLAG_XFLIP;
  } else {
    p->human.flags &= ~SPRFLAG_XFLIP;
  }
  Player_SetAction(p, PACT_DAMAGED, 2);
  p->lockedUpdate = Player_UpdateLockedCollapse;
}

// 操作不能にしてワープで消える演出 (PACT_UNK_7 の state 0) をフォームごとに始める
void Player_LockWarpOut(Player* p, Dir8S32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_7, 0);
  if (p->kind == PLAYER_BAT) {
    p->facing |= 1;
    if (p->facing > DIR8_DOWN) {
      p->animDir = (8 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animDir = p->facing >> 1;
      p->xflip = FALSE;
    }
    p->lockedUpdate = Player_UpdateBatWarp;
  } else {
    if (p->facing >= DIR8_RIGHT && p->facing <= DIR8_LEFT) {
      p->facing = DIR8_DOWN;
    } else {
      p->facing = DIR8_UP;
    }
    Player_SetAnimFacing(p);
    if (p->kind == PLAYER_MOUSE) {
      p->lockedUpdate = Player_UpdateMouseWarp;
    } else if (p->kind == PLAYER_SLEEPING) {
      p->lockedUpdate = Player_UpdateSleepingWarp;
    } else {
      p->animDir >>= 2;
      p->xflip = FALSE;
      p->lockedUpdate = Player_UpdateWarp;
    }
  }
}

void FUN_0807c30c(Player* p, Dir8S32 dir, u32 scriptID) {
  if (p->kind >= PLAYER_BAT && p->kind <= PLAYER_SLEEPING) {
    Player_LockWarpOut(p, dir, scriptID);
  }
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_7, 7);
  p->lockedUpdate = Player_UpdateWarp;
}

// 向きとスクリプトを指定して操作不能状態に移し, フォームごとの PACT_UNK_7 の処理を lockedUpdate に据える (Cmd_WarpInPlayer から)
void Player_LockWarpIn(Player* p, Dir8S32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  if (p->kind == PLAYER_BAT) {
    p->facing |= 1;
    PLAYER_SET_ANIM_4DIR(p, p->facing);
    Player_SetAction(p, PACT_UNK_7, 3);
    p->lockedUpdate = Player_UpdateBatWarp;
  } else {
    Player_SetAnimFacing(p);
    if (p->kind == PLAYER_MOUSE) {
      Player_SetAction(p, PACT_UNK_7, 3);
      p->lockedUpdate = Player_UpdateMouseWarp;
    } else if (p->kind == PLAYER_SLEEPING) {
      Player_SetAction(p, PACT_UNK_7, 3);
      p->lockedUpdate = Player_UpdateSleepingWarp;
    } else {
      Player_SetAction(p, PACT_UNK_7, 4);
      p->lockedUpdate = Player_UpdateWarp;
    }
  }
}

// 操作不能にして剣を振りかぶり, 構えたまま待つ
void Player_LockSwordReady(Player* p, Dir8S32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 0);
  p->lockedUpdate = Player_UpdateLockedSwordAttack;
}

// 操作不能にして剣を振り下ろす
void Player_LockSwordSwing(Player* p, Dir8S32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 2);
  p->lockedUpdate = Player_UpdateLockedSwordAttack;
}

// 操作不能にして槍を構え, 構えたまま待つ
void Player_LockSpearReady(Player* p, Dir8S32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 0);
  p->lockedUpdate = Player_UpdateLockedSpearAttack;
}

// 操作不能にして槍を突く
void Player_LockSpearSwing(Player* p, Dir8S32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 2);
  p->lockedUpdate = Player_UpdateLockedSpearAttack;
}

// 操作不能にして槌を振りかぶり, 構えたまま待つ
void Player_LockHammerReady(Player* p, Dir8S32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 0);
  p->lockedUpdate = Player_UpdateLockedHammerAttack;
}

// 操作不能にして槌を振り下ろす
void Player_LockHammerSwing(Player* p, Dir8S32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 2);
  p->lockedUpdate = Player_UpdateLockedHammerAttack;
}

// 操作不能にして銃を構える
void Player_LockGunReady(Player* p, Dir8S32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 0);
  p->lockedUpdate = Player_UpdateLockedGunAttack;
}

// イベント中に銃を撃つ (Cmd_PlayerFireGun から), 向きの前方 150 / 高さ 230 に弾 (Entity080c0fa0) を出して操作不能の攻撃モーションに入る
void Player_LockFireGun(Player* p, s32 param_2, u32 scriptID) {
  Vec3 pos = p->mover.pos;
  s32 angle = ((p->facing + 5) & 7) * 32;
  SpriteID32 pltt;

  pos.x += POLAR_X(Q8(0.586), angle);
  pos.y += Q8(0.9);
  pos.z += POLAR_Z(Q8(0.586), angle);
  if (p->kind == PLAYER_SABATA) {
    PlaySound_082406e0(SE_SABATA_FIRE);
    pltt = 50;
  } else {
    PlaySound_082406e0(SE_GUN_FIRE);
    pltt = 44;
  }
  Entity080c0fa0_Create(&pos, pltt, 0, p->facing, 32, 0, param_2);
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 2);
  p->lockedUpdate = Player_UpdateLockedGunAttack;
}

void FUN_0807c748(Player* p, Dir8S32 dir, s32 param_3, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->doneScriptID = scriptID;
  p->unk_4a7 = param_3;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 0);
  p->lockedUpdate = Player_UpdateLockedRockBuster;
}

void FUN_0807c798(Player* p, s32 scriptID) {
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_ATTACK, 5);
  p->lockedUpdate = Player_UpdateLockedRockBuster;
}

// mode ごとに向きを決めて PACT_UNK_7 の行動に入れ, 操作不能状態にする, mode が 0..3 以外なら何もしない
void FUN_0807c7c8(Player* p, s32 mode) {
  if (mode == 0) {
    p->targetDir = 1;
    Player_SetAnimFacing(p);
    p->animDir--;
    p->state = 0;
  } else if (mode == 1) {
    p->targetDir = 5;
    Player_SetAnimFacing(p);
    p->animDir--;
    p->state = 0;
  } else if (mode == 2) {
    p->unk_4a7 = 0;
    p->state = 5;
  } else if (mode == 3) {
    p->targetDir = 3;
    Player_SetAnimFacing(p);
    p->animDir--;
    p->state = 0;
  } else {
    return;
  }
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_UNK_7, p->state);
  p->lockedUpdate = FUN_08074a40;
}

// 操作不能にして pos へダッシュ (PACT_DASH) で移動させ, 着いたら dir を向いて scriptID を実行する
void Player_LockDashTo(Player* p, Vec3* pos, Dir8S32 dir, u32 scriptID) {
  p->moveTarget = *pos;
  p->doneScriptID = scriptID;
  p->targetDir = dir;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_DASH, 0);
  p->lockedUpdate = Player_UpdateDashTo;
}

void FUN_0807c8d4(Player* p, Dir8S32 dir) {
  if (dir >= 0) {
    p->facing = dir;
  }
  Player_SetAnimFacing(p);
  Player_PlayAnim(p, Player_GetAnimIdx(p->kind, 1), Q6(0.5));
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_DASH, 0);
  p->lockedUpdate = FUN_08074994;
}

void FUN_0807c928(Player* p, s32 val) {
  Player_EnterLockedState(p);
  p->facing = DIR8_UP_RIGHT;
  p->animDir = 0;
  p->xflip = 0;
  Player_SetAction(p, PACT_HEALING, 0);
  p->lockedUpdate = FUN_080749b0;
}

void FUN_0807c968(Player* p, s32 val) {
  Player_EnterLockedState(p);
  p->facing = DIR8_UP_RIGHT;
  p->animDir = 0;
  p->xflip = 0;
  Player_SetAction(p, PACT_HEALING, 2);
  p->lockedUpdate = FUN_080749b0;
}

void FUN_0807c9ac(Player* p, s32 xflip, u32 scriptID) {
  if (xflip != 0) {
    p->facing = DIR8_DOWN_LEFT;
    p->animDir = 0;
    p->xflip = TRUE;
  } else {
    p->facing = DIR8_DOWN_RIGHT;
    p->animDir = 0;
    p->xflip = FALSE;
  }
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 0);
  p->lockedUpdate = FUN_080728a8;
}

void FUN_0807ca24(Player* p, s32 xflip, u32 scriptID) {
  if (xflip != 0) {
    p->facing = DIR8_DOWN_LEFT;
    p->animDir = 0;
    p->xflip = TRUE;
  } else {
    p->facing = DIR8_DOWN_RIGHT;
    p->animDir = 0;
    p->xflip = FALSE;
  }
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 3);
  p->lockedUpdate = FUN_080728a8;
}

void FUN_0807ca9c(Player* p, s32 xflip, u32 scriptID) {
  if (xflip != 0) {
    p->facing = DIR8_DOWN_LEFT;
    p->animDir = 0;
    p->xflip = TRUE;
  } else {
    p->facing = DIR8_DOWN_RIGHT;
    p->animDir = 0;
    p->xflip = FALSE;
  }
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 4);
  p->lockedUpdate = FUN_080728a8;
}

void FUN_0807cb14(Player* p, bool32 xflip, u32 scriptID) {
  if (xflip) {
    p->facing = DIR8_DOWN_LEFT;
    p->animDir = 0;
    p->xflip = TRUE;
  } else {
    p->facing = DIR8_DOWN_RIGHT;
    p->animDir = 0;
    p->xflip = FALSE;
  }
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 2);
  p->lockedUpdate = FUN_080728a8;
}

void FUN_0807cb8c(Player* p, Dir8S32 dir, u32 scriptID) {
  if (dir >= 0) {
    p->facing = dir;
  }
  p->facing |= 1;
  if (p->facing > DIR8_DOWN) {
    p->animDir = (8 - p->facing) >> 1;
    p->xflip = TRUE;
  } else {
    p->animDir = p->facing >> 1;
    p->xflip = FALSE;
  }
  p->doneScriptID = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 0);
  p->lockedUpdate = FUN_080729e0;
}

void FUN_0807cc14(Player* p, s32 xflip) {
  if (xflip != 0) {
    p->facing = DIR8_DOWN_LEFT;
    p->animDir = 0;
    p->xflip = TRUE;
  } else {
    p->facing = DIR8_DOWN_RIGHT;
    p->animDir = 0;
    p->xflip = FALSE;
  }
  Player_EnterLockedState(p);
  Player_SetAction(p, PACT_IDLE, 0);
  p->lockedUpdate = FUN_08072a0c;
}

// バット / マウス / スリーピングなら操作不能にして黒ジャンゴへ戻す演出を据えて TRUE, それ以外は FALSE
bool32 Player_LockRevertToDarkDjango(Player* p, u32 scriptID) {
  p->doneScriptID = scriptID;
  if (p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) {
    return FALSE;
  }
  if (p->kind == PLAYER_BAT) {
    Player_EnterLockedState(p);
    Player_SetAction(p, PACT_CBAT, 0);
    p->lockedUpdate = Player_RevertBatToDarkDjango;
  } else if (p->kind == PLAYER_MOUSE) {
    Player_EnterLockedState(p);
    Player_SetAction(p, PACT_CMOUSE, 0);
    p->lockedUpdate = Player_RevertMouseToDarkDjango;
  } else if (p->kind == PLAYER_SLEEPING) {
    p->facing = DIR8_DOWN;
    Player_SetAnimFacing(p);
    Player_EnterLockedState(p);
    Player_SetAction(p, PACT_SLEEPING, 0);
    p->lockedUpdate = Player_RevertSleepingToDarkDjango;
  } else {
    return FALSE;
  }
  return TRUE;
}

// 体にまとわりつく粒子 (emitter) を kind で1個出す, 広がりの乱数はフォームで変わり, 出せたら種類ごとの音を鳴らす (Player_InflictElementalCond の後半と同じ)
// 残差は乱数の添字の組み方と定数 7 を置くレジスタ (153/154), 原典は gRandTableIdx を読んでその場で +1 / & 0x3FF し, 7 を r4 に作って x と y の両方で使い回す, Player_InflictElementalCond と同じ書き方で同じ残差
// Tier A-C 試済 (_Random(table) を分岐ごと / 関数先頭, Random() 直書き, idx ローカル)
// 追試: idx を s32 に, 宣言順, 2つ目の添字をローカルに受けてから gRandTableIdx に書く形も同じ 11 hunk
NON_MATCH void Player_AddElementalParticle(Player* p, u32 kind) {
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
  if (ElementalCondEmitter_AddParticle(&p->emitter, kind, 3600, &spread) >= 0) {
    if (p->emitter.kind == ELEMCOND_INKA) {
      PlaySound_082406e0(SE_IGNITE);
    } else if (p->emitter.kind == ELEMCOND_HYOKETU) {
      PlaySound_082406e0(SE_SOLIDIFY);
    } else if (p->emitter.kind == ELEMCOND_SEKIKA) {
      PlaySound_082406e0(SE_SOLIDIFY);
    }
  }
  p->badCondTimer[BAD_POISON] = 0;
#else
  INCFUNC("asm/func/Player_AddElementalParticle.inc");
#endif
}

void FUN_0807ceb8(Player* p) { Player_ClearElementalCond(p); }

// Boss_ShowEmote と同形
// kind は EmoteKind ではない
void Player_ShowEmote(Player* p, s32 kind, s32 param_3, s32 param_4) {
  switch (kind) {
    case 0: {
      p->emoteKind = EMOTE_0;
      p->emoteTimer = 0;
      p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, EM0_BANG_WHITE, NULL, 0, 0, 80);
      PlaySound_082406e0(SE_CHARA_SUPRISE);
      break;
    }
    case 1: {
      p->emoteKind = EMOTE_0;
      p->emoteTimer = 0;
      p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, EM0_BANG_BLUE, NULL, 0, 0, 80);
      PlaySound_082406e0(SONG_492);
      break;
    }
    case 2: {
      p->emoteKind = EMOTE_0;
      p->emoteTimer = 0;
      p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, EM0_BANG_RED, NULL, 0, 0, 80);
      PlaySound_082406e0(SONG_492);
      break;
    }
    case 3: {
      p->emoteKind = EMOTE_0;
      p->emoteTimer = 0;
      p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, EM0_BANG_QUESTION, NULL, 0, 0, 80);
      PlaySound_082406e0(SE_CHARA_QUESTION);
      break;
    }
    case 4: {
      p->emoteKind = EMOTE_1;
      p->emoteTimer = param_3;
      p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 0, &p->emoteTimer, param_4, 150, 230);
      break;
    }
    case 5: {
      p->emoteKind = EMOTE_3;
      p->emoteTimer = param_3;
      p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 0, &p->emoteTimer, param_4, 150, 230);
      break;
    }
    case 6: {
      p->emoteKind = EMOTE_5;
      p->emoteTimer = 0;
      p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 0, NULL, 0, 150, 230);
      break;
    }
    case 7: {
      p->emoteKind = EMOTE_4;
      p->emoteTimer = 0;
      p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 0, NULL, 0, 150, 230);
      break;
    }
    case 8: {
      p->emoteTimer = 0;
      p->emote = Emote_Show(p->emote, &p->mover, p->emoteKind, 127, NULL, 0, 0, 80);
      break;
    }
  }
}

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
Dir8S32 Player_GetCmdArgDir(void) {
  if (VM_SeekToNamedArg('d')) {
    return VM_GetValue();
  }
  return -1;
}

// コマンドのヘルパーで, '.e' で渡されたスクリプトIDを取得する, 無ければ 0
u32 Player_GetCmdArgScript(void) { return VM_SeekToNamedArg('e') ? VM_GetValue() : 0; }

// 0xEFE6
void Cmd_HidePlayer(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_LockHidden(p);
    Player_SetDoneRunScript(p);
  }
}

// 0x8FA3
void Cmd_StartPlayerPlttFadeIn(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('p')) {
    Player_StartPlttFadeIn(p, OBP_ELEMENT(VM_GetValue()));
    Player_SetDoneRunScript(p);
  }
}

// 0xC12D
void Cmd_StartPlayerPlttPulse(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('p')) {
    Player_StartPlttPulse(p, OBP_ELEMENT(VM_GetValue()));
    Player_SetDoneRunScript(p);
  }
}

// 0x6F85
void Cmd_StopPlayerPlttEffect(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_StopPlttEffect(p);
    Player_SetDoneRunScript(p);
  }
}

// 0x3613
void Cmd_LockPlayer(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_Lock(p, Player_GetCmdArgDir());
    Player_SetDoneRunScript(p);
  }
}

// 0x9FFD
void Cmd_TurnPlayerTo(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_LockTurnTo(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x061E
void Cmd_061E(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807ba14(p, Player_GetCmdArgDir());
    Player_SetDoneRunScript(p);
  }
}

// 0x6E7D
void Cmd_6E7D(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807ba50(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x933C, プレイヤーを `.p` まで移動させる
void Cmd_MovePlayerTo(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('p')) {
    Vec3 pos;
    Dir8S32 dir;
    u32 scriptID;

    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    dir = Player_GetCmdArgDir();
    scriptID = Player_GetCmdArgScript();
    Player_MoveTo(p, &pos, scriptID, dir);
    Player_SetDoneRunScript(p);
  }
}

// 0xE990
void Cmd_DashPlayerTo(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('p')) {
    Vec3 pos;
    Dir8S32 dir;
    u32 scriptID;

    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    dir = Player_GetCmdArgDir();
    scriptID = Player_GetCmdArgScript();
    Player_LockDashTo(p, &pos, dir, scriptID);
    Player_SetDoneRunScript(p);
  }
}

// 0x9763
void Cmd_PullCoffinTo(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 param_4 = VM_SeekToNamedArg('f') ? VM_GetValue() : 0;
    Dir8S32 dir = Player_GetCmdArgDir();
    u32 scriptID = Player_GetCmdArgScript();

    if (VM_SeekToNamedArg('p')) {
      Vec3 pos;
      VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
      Player_LockPullCoffinTo(p, &pos, dir, param_4, scriptID);
    } else {
      Player_LockPullCoffinTo(p, NULL, dir, param_4, scriptID);
    }
    Player_SetDoneRunScript(p);
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
      Player_SetDoneRunScript(p);
    } else {
      p->doneScriptID = scriptID;
      Player_Lock(p, DIR8_DOWN);
      Player_SetDoneRunScript(p);
      Player_RunDoneScript(p);
    }
  }
}

// 0xB83E
void Cmd_B83E(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bc64(p, Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x7843
void Cmd_7843(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bcb0(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0xE4A3
void Cmd_E4A3(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bcfc(p, Player_GetCmdArgDir());
    Player_SetDoneRunScript(p);
  }
}

// 0x409D
void Cmd_409D(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bd44(p, Player_GetCmdArgDir());
    Player_SetDoneRunScript(p);
  }
}

// 0x40D7
void Cmd_40D7(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bd84(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x58D7
void Cmd_PlayerFall(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Dir8S32 dir = Player_GetCmdArgDir();
    u32 b = Player_GetCmdArgScript();

    Player_LockFall(p, dir, VM_SeekToNamedArg('f') ? VM_GetValue() : 0, b);
  }
}

// 0x3705
void Cmd_PlayerLand(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Dir8S32 dir = Player_GetCmdArgDir();
    u32 b = Player_GetCmdArgScript();

    Player_LockLanding(p, dir, VM_SeekToNamedArg('h') ? VM_GetValue() : 1500, b);
    Player_SetDoneRunScript(p);
  }
}

// 0x7A25
void Cmd_KnockbackPlayer(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('f') ? VM_GetValue() : 30;

    Player_LockKnockback(p, Player_GetCmdArgDir(), n, Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x172D
void Cmd_BlowAwayPlayer(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 param_3 = VM_SeekToNamedArg('f') ? VM_GetValue() : 50;
    s32 param_4 = VM_SeekToNamedArg('L') ? VM_GetValue() : 0;
    Dir8S32 dir = Player_GetCmdArgDir();
    u32 scriptID = Player_GetCmdArgScript();

    Player_LockBlownAway(p, dir, param_3, param_4, scriptID);
    Player_SetDoneRunScript(p);
  }
}

// 0x4127
void Cmd_PlayerGetUp(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_GetUpFromBlownAway(p, Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x1343
void Cmd_KnockPlayerProne(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('f') ? VM_GetValue() : 50;

    Player_LockKnockProne(p, Player_GetCmdArgDir(), n, Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x2593, プレイヤーを '.d' の向きでうつ伏せに倒れた状態にする
void Cmd_SetPlayerProne(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_LockProne(p, Player_GetCmdArgDir());
    Player_SetDoneRunScript(p);
  }
}

// 0xA2E1, 転移の葉(ITEM_WARP_LEAF) を使用時に呼ばれた
void Cmd_Riremito(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_LockWarpOut(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0xEA96
void Cmd_WarpInPlayer(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_LockWarpIn(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0xCAFE
void Cmd_PlayerSwordReady(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_LockSwordReady(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0xAF43
void Cmd_PlayerSwordSwing(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_LockSwordSwing(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0xDDEE
void Cmd_PlayerSpearReady(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_LockSpearReady(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0xC233
void Cmd_PlayerSpearSwing(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_LockSpearSwing(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0xB683
void Cmd_PlayerHammerReady(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_LockHammerReady(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x9AC8
void Cmd_PlayerHammerSwing(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_LockHammerSwing(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0xD40E
void Cmd_PlayerGunReady(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    Player_LockGunReady(p, Player_GetCmdArgDir(), Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x1F3B (不使用?)
void Cmd_PlayerFireGun(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('l') ? VM_GetValue() : 32;

    Player_LockFireGun(p, n, Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x490F
void Cmd_RevertToDarkDjango(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    bool32 done = Player_LockRevertToDarkDjango(p, Player_GetCmdArgScript());

    Player_SetDoneRunScript(p);
    if (!done) {
      Player_RunDoneScript(p);
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
    Player_SetDoneRunScript(p);
  }
}

// 0x05E2
void Cmd_05E2(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('r') ? VM_GetValue() : 0;

    FUN_0807ca24(p, n, Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x546C
void Cmd_546C(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('r') ? VM_GetValue() : 0;

    FUN_0807ca9c(p, n, Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x75B9
void Cmd_75B9(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('r') ? VM_GetValue() : 0;

    FUN_0807cb14(p, n, Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x3C3E
void Cmd_3C3E(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('d') ? VM_GetValue() : 0;

    FUN_0807cb8c(p, n, Player_GetCmdArgScript());
    Player_SetDoneRunScript(p);
  }
}

// 0x827A
void Cmd_827A(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807cc14(p, VM_SeekToNamedArg('r') ? VM_GetValue() : 0);
    Player_SetDoneRunScript(p);
  }
}

// 0x4CDD
void Cmd_ShowPlayerEmote(void) {
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
    Player_ShowEmote(p, m, c, a);
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
      p->timedChargeGoal = VM_GetValue();
    } else {
      p->timedChargeGoal = 720;
    }
    p->timedCharge = 0;
    p->doneScriptID = Player_GetCmdArgScript();
    p->facing = DIR8_DOWN;
    Player_SetAnimFacing(p);
    Player_EnterLockedState(p);
    Player_SetAction(p, PACT_UNK_7, 0);
    if (p->kind == PLAYER_SABATA) {
      p->lockedUpdate = Player_UpdateTimedDarkCharge;
    } else {
      p->lockedUpdate = Player_UpdateTimedSolarCharge;
    }
  }
}

void Player_RegisterMsgQueue(Player* p) { MsgQueue_Register(&p->mq, p->mover.id, CLS_PLAYER); }

void Player_UnregisterMsgQueue(Player* p) { MsgQueue_Unregister(&p->mq); }

// 溜まったメッセージを受け取り, cmd ごとにカットシーン用の操作 (移動, 向き, 操作不能化, 感情表現など) を振り分ける
void Player_HandleMessages(Player* p) {
  MsgQueue* mq = &p->mq;
  s32 i;

  for (i = 0; i < mq->count[GetMsgBus()->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[GetMsgBus()->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    switch (msg->cmd) {
      case 0: {
        Player_LockHidden(p);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 1: {
        Vec3 pos;

        pos.x = msg->args[0];
        pos.y = msg->args[1];
        pos.z = msg->args[2];
        Player_SetPos(p, &pos);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 2: {
        Player_Lock(p, msg->args[0]);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 3: {
        Player_LockTurnTo(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 4: {
        FUN_0807ba14(p, msg->args[0]);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 5: {
        FUN_0807ba50(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 6: {
        Vec3 pos;

        pos.x = msg->args[0];
        pos.y = msg->args[1];
        pos.z = msg->args[2];
        Player_MoveTo(p, &pos, 0, -1);
        Player_SetDoneEndWait(p);
        break;
      }
      case 7: {
        FUN_0807bbb0(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 8: {
        FUN_0807bc14(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 9: {
        FUN_0807bc64(p, 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 10: {
        FUN_0807bcb0(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 11: {
        FUN_0807bd44(p, msg->args[0]);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 12: {
        FUN_0807bcfc(p, msg->args[0]);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 13: {
        FUN_0807bd84(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 14: {
        Player_LockPullCoffinTo(p, NULL, msg->args[0], 0, 0);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 15: {
        Player_LockKnockback(p, msg->args[0], msg->args[1], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 16: {
        Player_LockBlownAway(p, msg->args[0], msg->args[1], msg->args[2], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 17: {
        Player_GetUpFromBlownAway(p, 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 18: {
        Player_LockKnockProne(p, msg->args[0], msg->args[1], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 19: {
        Player_LockWarpOut(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 21: {
        Player_LockWarpIn(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 20: {
        FUN_0807c30c(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 22: {
        Player_LockGunReady(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 23: {
        Player_LockFireGun(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 24: {
        FUN_0807c748(p, msg->args[0], msg->args[1], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 25: {
        FUN_0807c798(p, 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 27: {
        bool32 busy = Player_LockRevertToDarkDjango(p, 0);

        Player_SetDoneEndWait(p);
        if (!busy) {
          Player_EndDoneWait(p);
        }
        break;
      }
      case 29: {
        Vec3 pos;

        pos.x = msg->args[0];
        pos.y = msg->args[1];
        pos.z = msg->args[2];
        Player_LockDashTo(p, &pos, -1, 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 30: {
        FUN_0807c8d4(p, msg->args[0]);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 31: {
        FUN_0807c9ac(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 33: {
        FUN_0807ca24(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 34: {
        FUN_0807ca9c(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 32: {
        FUN_0807cb14(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 35: {
        FUN_0807cb8c(p, msg->args[0], 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 26: {
        FUN_0807cc14(p, msg->args[0]);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 36: {
        FUN_0807c928(p, 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 37: {
        FUN_0807c968(p, 0);
        Player_SetDoneEndWait(p);
        break;
      }
      case 38: {
        Player_AddElementalParticle(p, ELEMCOND_HYOKETU);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 39: {
        FUN_0807ceb8(p);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 43: {
        Player_StartPlttFadeIn(p, msg->args[0] + 0x121);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 42: {
        Player_StartPlttPulse(p, msg->args[0] + 0x121);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 44: {
        Player_StopPlttEffect(p);
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 40: {
        p->footHitboxOn = TRUE;
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 41: {
        p->footHitboxOn = FALSE;
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
      case 28: {
        switch (msg->args[0]) {
          case 0:
          case 1:
          case 2:
          case 3:
          case 6:
          case 7:
          case 8: {
            Player_ShowEmote(p, msg->args[0], 0, 0);
            break;
          }
          case 4:
          case 5: {
            Player_ShowEmote(p, msg->args[0], msg->args[1], msg->args[2]);
            break;
          }
        }
        Player_SetDoneEndWait(p);
        Player_EndDoneWait(p);
        break;
      }
    }
  }
}

// 自分宛ての targetClass 2 のメッセージを1件組み立てて送る
void Player_SendMsgToSelf(Player* p, s32 cmd, s32 argc, s16* args) {
  MsgPacket* msg = &p->selfMsg;

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
  HitboxData* hitbox = &p->spikeHitbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, Q8(0.47), Q8(0.47), Q8(0.47));
  VEC3_SET(offset, 0, Q8(0.47), 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 1 << p->mover.unk_4, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, 10, 40, 0, HBATTR_18, 10);
  Hitbox_SetHandler(hitbox, NULL, p);
  Hitbox_SetPos(hitbox, &p->mover.pos, 0);
  p->hitboxTimer = 6;
  p->spikeHitbox.angle = ((p->facing + 1) & 7) << 5;
}

// hitboxTimer が残っている間 spikeHitbox を当たり判定に出し続ける
void Player_UpdateSpikeHitbox(Player* p) {
  if (p->hitboxTimer != 0) {
    Hitbox_Register(&p->spikeHitbox);
    p->hitboxTimer--;
  }
}

// 被弾1回分を処理する, ダメージ・状態異常・ノックバックを反映し、p->damage に足した量を返す
u32 Player_TakeHit(Player* p, HitboxData* a, HitboxData* b) {
  s32 shift;
  u32 dmg;
  s32 power;

  if (p->kind == PLAYER_SLEEPING) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_DARK_DJANGO;
  }
  power = a->power;
  if (power > 0) {
    Hitbox_ApplyDamage(a, b);
  } else {
    b->damage = 0;
  }
  b->iframes = a->iframes;

  shift = Player_TestEquipBuff(p, EBUFF_GUTSPOWER) ? -1 : 0;

  if (a->knockback == 0) {
    p->hurtSound = SONG_NONE;
  } else {
    p->hurtSound = SE_DAMAGE;
    if ((p->kind == PLAYER_BAT && p->action == PACT_CBAT) || (p->kind == PLAYER_MOUSE && p->action == PACT_CMOUSE)) {
      p->formRequest = TRUE;
      p->formRequestKind = PLAYER_DARK_DJANGO;
    }
    if (p->spiderWebIdx >= 0) {
      FUN_080dab9c(p->spiderWebIdx);
    }
    if (HasGoodCond(p, GOOD_INVISIBLE)) {
      p->goodCondID = 0;
      p->goodCondTimer = 0;
      p->beast.flags &= ~SPRFLAG_BLINK_EVEN;
    }
    if (p->unk_3ea == 0 && p->mashRecoverTimer != 0) {
      p->mashRecoverTimer = 0;
    }
    if (p->action == PACT_SEKIKA && !Hitbox_TestAttr(a, HBATTR_SEKIKA)) {
      Player_ClearElementalCond(p);
      shift++;
    }
    Player_SetupKnockback(p, a, b);
    if (p->kind == PLAYER_DARK_DJANGO) {
      p->berserkHurt = 1;
    }
  }

  if (HasGoodCond(p, GOOD_GAMAN)) {
    b->damage = 0;
    dmg = 0;
    if (Hitbox_TestAttr(a, HBATTR_18)) {
      Player_ClearElementalCond(p);
    }
  } else {
    if (HasGoodCond(p, GOOD_MINI) || p->action == PACT_DASH || p->kind == PLAYER_BAT || p->kind == PLAYER_MOUSE) {
      shift++;
    }

    if (Hitbox_TestAttr(a, HBATTR_INKA)) {
      if (!(b->hitResult & HBRESULT_RESIST)) {
        if (!p->blownAway) p->hurtSound = SE_IGNITE;
        Player_InflictElementalCond(p, ELEMCOND_INKA);
      }
    } else if (Hitbox_TestAttr(a, HBATTR_HYOKETU)) {
      if (!(b->hitResult & HBRESULT_RESIST)) {
        if (!p->blownAway) p->hurtSound = SE_SOLIDIFY;
        Player_InflictElementalCond(p, ELEMCOND_HYOKETU);
      }
    } else if (Hitbox_TestAttr(a, HBATTR_SEKIKA)) {
      p->hurtSound = SE_SOLIDIFY;
      Player_InflictElementalCond(p, ELEMCOND_SEKIKA);
      p->blownAway = FALSE;
    } else if (Hitbox_TestAttr(a, HBATTR_18)) {
      Player_ClearElementalCond(p);
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
      v.x = POLAR_X(Q8(0.313), angle);
      v.y = Q8(0.782);
      v.z = POLAR_Z(Q8(0.313), angle);
      SpawnBlood(&p->mover.pos, &v, 0, 0, 1);
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
s32 Player_TakeInstantHit(Player* p, s32 power, s32 knockback, s32 angle, s32 iframes, HitboxAttributes attrs) {
  if (p->mode == PMODE_ACTIVE) {
    HitboxData* hurtbox = &p->hurtbox;
    s32 remaining = hurtbox->iframes;

    if (remaining <= 0) {
      HitboxData hb;
      hb.flags = HBFLAG_HITBOX;
      hb.power = power;
      hb.knockback = knockback;
      hb.angle = angle;
      hb.attributes = attrs;
      hb.iframes = iframes;
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
  PLAYER_SET_ANIM_4DIR(p, p->facing);
  p->mode = PMODE_DEAD;
  p->state = 0;
  p->stateTimer = 0;
  p->hurtbox.iframes = 0;
  p->magic.enchanted = FALSE;
  gSunMagicUsed = 0;
  gSunGaugeOverride = 0;
  gSunGaugeOverrideTimer = 0;
  Player_ClearElementalCond(p);
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

// 落下死・熱中症・毒・引火・砂漠・黒の鎧のダメージを HP に反映し, 倒れる行動に入ったら TRUE を返す, HP が尽きてもジャッジメントがあれば身代わりにして FALSE
bool32 Player_UpdateDamage(Player* p) {
  if ((GetTileAttrAt(&p->mover.pos) & TATTR_FALLDEATH) && p->elevatorFlags == 0) {  // 落下死タイル属性 & 移動床の上にいない
    if (TestMapFlag(MPF_WATERFRONT)) {
      Player_SetAction(p, PACT_DROWNING, 0);
      return TRUE;
    }
    Player_SetAction(p, PACT_FALLDEATH, 0);
    return TRUE;
  }

  if (gStat->heatstroke >= 5000) {
    Player_SetAction(p, PACT_HEATSTROKE, 0);
    return TRUE;
  }

  if (p->originHitPending) {
    p->damage += Player_ApplyOriginHit(p);
  } else if (p->tileHitPending) {
    p->damage += Player_ApplyTileHit(p);
  }

  if (p->hurtbox.iframes == 0) {
    if (p->badCondTimer[BAD_POISON] != 0) {
      p->poisonTick++;
      if (p->poisonTick >= SECOND(1)) {
        p->damage++;
        p->poisonTick = 0;
      }
    }
    if (p->emitter.kind == ELEMCOND_INKA && p->emitter.aliveCount != 0) {
      Player_SetFlag20(p, PFLAG20_INKA);
      if (++p->inkaTick >= Div(60, p->emitter.aliveCount)) {  // 引火数に応じてダメージ速度が速くなる
        p->damage += 10;
        p->inkaTick = 0;
      }
    }
    if (TestMapFlag(MPF_DESERT)) {
      p->desertTimer++;
      if (p->desertTimer >= SECOND(2)) {
        p->damage++;
        p->desertTimer = 0;
      }
    } else {
      p->desertTimer = SECOND(2);
    }
    if (Player_TestEquipBuff(p, EBUFF_BLACKARMOR)) {
      p->blackArmorTimer++;
      if (p->blackArmorTimer > 14) {
        p->damage++;
        p->blackArmorTimer = 0;
      }
    }
  }

  if (p->damage != 0) {
    if (!HasGoodCond(p, GOOD_GAMAN)) {
      CreateDamageNumber(&p->hurtbox, p->damage, 0, &p->mover.pos, &p->damageNumOffset, 0);
      if (p->hp < p->damage) {
        p->hp = 0;
      } else {
        p->hp -= p->damage;
      }
    }
  }

  p->damage = 0;
  p->damageNumOffset.x = 0, p->damageNumOffset.y = 0, p->damageNumOffset.z = 0;

  if (p->action == PACT_GRABBED || p->hp != 0) {
    return FALSE;
  }
  if (gGameFlags & GAMEFLAG_CROSSOVER) {
    return TRUE;
  }
  if (!CheckItemOwn(ITEM_JUDGEMENT)) {
    return TRUE;
  }

  p->hurtSound = SONG_NONE;
  if (p->hurtbox.knockback == 0) {
    p->facing |= 1;
    p->hurtbox.knockback = 1;
  }
  RemoveSpecifiedItem(ITEM_JUDGEMENT);
  Judgement_Create(p);
  return FALSE;
}

// 無敵時間中は食らい判定を消し, 吹き飛ばされていなければ1減らして4フレームおきに点滅させる
void Player_UpdateIframes(Player* p) {
  s32 n = Player_GetIframes(p);

  if (n > 0) {
    Player_SetFlag35a(p, PFLAG35A_NO_HURTBOX);
    if (p->hurtbox.knockback == 0 && p->action != PACT_DAMAGED && p->action != PACT_BLOWN_AWAY) {
      n--;
      if (n != 0 && ((n >> 2) & 1)) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_BODY | PFLAG35A_HIDE_SHADOW);
      }
      p->hurtbox.iframes = n;
    }
  }
}

// プレイヤーの位置・向き・HP/ENE・状態異常などを gStat と退避用のグローバルに書き出す
void Player_SaveState(Player* p) {
  s32 i;

  PLAYER_X = p->mover.pos.x;
  PLAYER_Y = p->mover.pos.y;
  PLAYER_Z = p->mover.pos.z;
  PLAYER_DIR = p->facing;
  SUN_ANGLE = ((p->facing + 5) & 7) << 5;
  p->mover.angle = SUN_ANGLE;
  Hitbox_SetAngle(&p->hurtbox, SUN_ANGLE);
  PLAYER_KIND = p->kind;
  PLAYER_ACTION = p->action;
  if (p->kind == PLAYER_SABATA) {
    SABATA_HP = p->hp;
    SABATA_ENE = p->ene;
  } else {
    SAVED_HP = p->hp;
    SAVED_ENE = p->ene;
  }
  SAVED_MAX_HP = p->maxHP;
  SAVED_MAX_ENE = p->maxEne;
  gGoodCondID = p->goodCondID;
  gGoodFrom = p->goodFrom;
  gGoodCondTimer = p->goodCondTimer;
  for (i = 0; i < 3; i++) {
    gBadCondTimer[i] = p->badCondTimer[i];
  }
  gPlayerModes[p->mover.unk_4] = p->mode;
  gSavedMagicEnchanted = p->magic.enchanted;
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
    p->plttIdx = 0xFFFF;
    p->beastGfx->plttID = p->basePlttID;
    p->flashPlttID = 621;
    p->plttFlashTimer = 32;
  } else if (p->formRequestKind == PLAYER_MOUSE) {
    p->kind = PLAYER_MOUSE;
    p->updateCallback = Player_UpdateMouse;
    p->useAuxSprite = 1;
    p->mover.mainSprite = NULL, p->mover.auxSprite = &p->beast;
    p->emitter.pos = &p->beast.pos;
    Player_SetPlttIDs(p);
    p->plttIdx = 0xFFFF;
    p->beastGfx->plttID = p->basePlttID;
    p->flashPlttID = 290;
    p->plttFlashTimer = 32;

  } else if (p->formRequestKind == PLAYER_SLEEPING) {
    p->kind = PLAYER_SLEEPING;
    p->updateCallback = Player_UpdateSleeping;
    p->useAuxSprite = 1;
    p->mover.mainSprite = NULL, p->mover.auxSprite = &p->beast;
    p->emitter.pos = &p->beast.pos;
    Player_SetPlttIDs(p);
    p->plttIdx = 0xFFFF;
    p->beastGfx->plttID = p->basePlttID;
    p->walkVoiceTimer = 0;
    p->attackVoiceCooldown = 0;
    p->facing = DIR8_UP;
    p->animDir = 0;
    p->xflip = 0;

  } else {
    s32 enchant;
    if (p->kind != PLAYER_SLEEPING) {
      p->flashPlttID = 290;
      p->plttFlashTimer = 32;
    }
    p->kind = PLAYER_DARK_DJANGO;
    p->updateCallback = Player_UpdateDjango;
    p->useAuxSprite = 0;
    p->mover.mainSprite = &p->human, p->mover.auxSprite = NULL;
    p->emitter.pos = &p->human.pos;
    Player_SetPlttIDs(p);
    p->plttIdx = 0xFFFF;

    enchant = Player_CheckMagicEnchant(p) + 1;
    p->nextEnchantColorIdx = enchant;
    p->enchantColorIdx = enchant + 1;
  }

  p->human.plttID = p->basePlttID;
  p->magic.availableForm = Player_IsMagicAvailableForm(p, p->magic.id);
  p->formRequest = FALSE;
}

// ボタンを押している間, プレイスタイルの集計カウンタを進める (どれも 0x7FFFFFFF で止まる)
// 残差はレジスタ番号 r1/r2 の入れ替えのみ (命令列は55命令で完全一致), Tier A-C は試済
// ポインタのローカルを3箇所で使い回す形までは追い込めたが, 先頭の定数 0x358 が原典では r1, こちらでは r2 に入る
// 飽和加算を static inline にすると前半の共通末尾は揃うが, weaponFrames のアドレスで gStat の読みとシフトの順が逆になり 5 hunk (添字のローカル, 添字を inline の引数にする形も不一致)
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
    if (gStat->berserkCounter >= gStat->berserkThresh) {
      if (p->berserkReady) {
        if (p->action <= PACT_WALK) {
          gStat->berserkCounter = 0;
          gStat->berserkThresh = Mod(Random(), 100) + 200;
          p->berserkReady = 0;
          Player_ExecEventScript(p, 2);
          DjangoBerserk_Create(p);
        }
      } else if (p->berserkHurt) {
        p->berserkReady = 1;
        p->berserkHurt = 0;
      }
    } else {
      p->berserkHurt = 0;
    }
  } else {
    p->berserkReady = 0;
    p->berserkHurt = 0;
  }
#else
  INCFUNC("asm/func/DarkDjango_UpdateBerserk.inc");
#endif
}

// unk_1c の状態ごとに更新を振り分け, 共通の後処理と範囲イベントの拾い上げまでを毎フレーム回す
static s32 Player_Update(Player* p) {
  Player_HandleMessages(p);
  Player_BeginAction(p);

  if (p->mode == PMODE_ACTIVE) {
    Player_CountStyleFrames(p);
    Player_UpdateWeaponWear(p);
    Player_UpdateSpikeHitbox(p);

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
      Player_UpdateIframes(p);
      DarkDjango_UpdateBerserk(p);
    }
  } else if (p->mode == PMODE_LOCKED) {
    s32 n;

    Player_ClearInputHistory(p);
    if (p->hp == 0) {
      p->hp = 1;
    }
    p->damage = 0;
    p->hurtbox.knockback = 0;
    n = p->hurtbox.iframes;
    if (n > 0) {
      p->hurtbox.iframes = 0;
    }
  }

  Player_ApplyFormRequest(p);
  if (p->enchantStarted) {
    PlaySound_082406e0(SE_M_ENCHANT);
    p->enchantStarted = FALSE;
  }

  p->updateCallback(p);
  Player_UpdatePoseAndShadow(p);
  Player_RefreshDerivedStats(p);
  p->unk_3ea = 0;
  if (p->mover.unk_4 == 0) {
    Player_SaveState(p);
  }

  if (p->mode != PMODE_DEAD) {
    p->zoneEvents.pos = &p->mover.pos;
    Map_UpdateZoneEvents(&p->zoneEvents);
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

static s32 Player_Init(Player* p, u32 id, void* _) {
  Player_ReadInputIdxArg(p);
  Player_InitState(p);
  Player_InitMover(p, id);
  Player_SetupHurtbox(p);
  Player_RefreshMagicInfo(p);
  Player_InitWeapon(p);
  Player_InitArmor(p);
  CheckHeartJokerEmblem(p);
  Player_InitDerivedStats(p);
  Player_InitEffects(p);
  Player_RegisterMsgQueue(p);
  Player_ReadEventScriptArg(p);
  gPlayerPtr[(p->mover).unk_4] = p;
  gPlayerCount++;
  if ((p->mover).unk_4 == 0) {
    Player_SaveState(p);
    QC_Rebuild();
  }
  return 0;
}

// 0xF5EB, HashName("プレイヤー"), エリア移動などでも毎回作り直す
Player* Player_Create(u32 id, void* _) {
  Player* p = CreateEntity(ENTITY_PLAYER, sizeof(Player));

  if (p != NULL) {
    SetEntityRoutine(p, Player_Update, Player_Destroy);
    if (Player_Init(p, id, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
