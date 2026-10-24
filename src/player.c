#include "player.h"

#include "armor.h"
#include "camera.h"
#include "coffin.h"
#include "eff_082473e0.h"
#include "emote.h"
#include "enemy_target.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "input.h"
#include "item.h"
#include "magic.h"
#include "random.h"
#include "solar.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "vm.h"

extern u16 u16_03002bf4;
extern u16 u16_03002bd0;
extern u16 u16_03002bb0;
extern u16 u16_ARRAY_03002ba0[3];
extern u16 u16_03002b84;
extern u16 u16_03002bac;
extern u16 u16_03002bf0;

struct Entity080a8ff8* Entity080a8ff8_Create(Player* owner, Vec3* pos, s32 mode);
struct TransEffect* TransEffect_Create(Player* player, u32 param_2, Vec3* pos, u32 param_4, u32 param_5);
struct Entity080abd14* Entity080abd14_Create(void* owner, WorldPos* pos1, WorldPos* pos2, u32 param_4, u32 param_5);
struct FreezeEffect* FreezeEffect_Create(Vec3* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5);
struct HealingEffect* HealingParticles_Create(Player* player, Vec3* pos);
bool32 Entity1DBE_TouchElemNear(WorldPos* pos);
void FUN_08240cf0(s32 x, s32 z, s16 param_3, s32 param_4, u8 param_5, u16 param_6);
struct Entity08080be8* Entity08080be8_Create(Player* player, u32 heightOffset, u32 unk_be, u32 unk_c0, u32 offsetRadius, u32 plttID, u32 hitboxUnk40, u32 attributes, u32 hitboxUnk44, u32 ptclVal, u32 eneCost, u32 unk_cd);
void FUN_08072724(Player* p);
void FUN_080d040c(Player* p);
s32 FUN_08086294(Vec3* pos, u32 elevatorID, u32 b);
void Django_OnHurt(HitboxData* a, HitboxData* b, Player* p);
void FUN_0807bdc8(Player* p, DirS32 dir, s32 param_3, u32 scriptID);
s32 FUN_0805fe7c(HitboxData* hitbox, s32 param_2, s32 param_3, Vec3* pos, Vec3* param_5, s32 param_6);
bool32 FUN_0809df78(Vec3* pos);
s32 FUN_080dc0b8(Vec3* pos, Vec3* param_2, u32 param_3, u32 param_4, u32 param_5);
bool32 FUN_0809e138(Player* p);
void FUN_0809c4f4(void);
magic32_t Player_CheckMagicEnchant(Player* p);
void dark_django_0806f990(HitboxData* a, HitboxData* b, Player* _);
void* Entity080dc44c_Create(void);
struct Judgement* Judgement_Create(Player* p);
s32 MosaicFader_Start(s32 mode, s32 objEnabled, s32 targets, u8* from, u8* to, u16* interval);
void BuildWeaponData(Weapon* w, WeaponData* data);
s32 FUN_0807a6cc(WeaponData* w);
void FUN_08071b14(Player* p);
void FUN_0807e854(Player* p);
void FUN_080ec79c(u8 kind, void* payload);
void FUN_08079f1c(Player* p);
void Camera_LookAt(Vec3* pos);
bool32 MapItemManager_TryOpen(Mover* mover);

COMMON_DATA u16 gGoodCondID = 0;                        // 0x03002B60, 現在の良い状態効果のID (= Player.goodCondID, Player再生成時の退避用, 他のEntityから参照するなどの用途で使用される)
COMMON_DATA u16 ALIGNED(4) gConfusedDir = 0;            // 0x03002B64, 混乱の状態異常のときに動く方向 (エリア移動などで Player を再生成したときにこれを引き継ぐ)
COMMON_DATA u16 ALIGNED(4) u16_03002b68[4] = {};        // 0x03002B68, 多分プレイヤーの moverID
COMMON_DATA u16 u16_03002b70 = 0;                       // 0x03002B70, チェンジウルフの噛みつき回数
COMMON_DATA u16 ALIGNED(4) gSabataDefence = 0;          // 0x03002B74, サバタの防御力
COMMON_DATA u16 ALIGNED(4) gSunGaugeOverrideTimer = 0;  // 0x03002B78, FUN_0807b564 が 0 に戻す
COMMON_DATA u16 ALIGNED(4) u16_03002b7c = 0;            // 0x03002B7C
COMMON_DATA u16 ALIGNED(4) gSunGaugeOverride = 0;       // 0x03002B80, ApplyLxModifiers が 1 なら太陽レベル +4、2 なら日光なしにする
COMMON_DATA u16 ALIGNED(4) u16_03002b84 = 0;            // 0x03002B84, Player_InitEffects が 1 を入れる
COMMON_DATA u16 ALIGNED(4) u16_03002b88 = 0;            // 0x03002B88, チェンジウルフに関連するフラグ
COMMON_DATA u16 ALIGNED(4) gGoodCondTimer = 0;          // 0x03002B8C, Player.goodCondTimer の退避
COMMON_DATA u16 ALIGNED(4) gWindAngle = 0;              // 0x03002B90, Player_InitEffects が 0 に戻す
COMMON_DATA u16 ALIGNED(8) gPlayerCount = 0;            // 0x03002B98, Playerの数, シングルプレイ中は1, 通信対戦中時は参加人数になる
COMMON_DATA u8 u8_03002b9a[6] = {};                     // todo
COMMON_DATA u16 u16_ARRAY_03002ba0[3] = {};             // 0x03002BA0, Player がいないときに FUN_0807b428 が書き込む退避先
COMMON_DATA u8 u8_03002ba6[2] = {};                     // todo
COMMON_DATA Entity5941Node* gChangeWolfTarget = NULL;   // 0x03002BA8, チェンジウルフで噛みつく相手のノード, Player_Destroy が NULL に戻す
COMMON_DATA u16 u16_03002bac = 0;                       // 0x03002BAC, Player_InitEffects が 0 に戻す
COMMON_DATA u8 u8_03002bae[2] = {};                     // todo
COMMON_DATA u16 u16_03002bb0 = 0;                       // 0x03002BB0, Player_GetEquippedMagic がサバタのとき 0 に戻す
COMMON_DATA u8 u8_03002bb2[14] = {};                    // todo
COMMON_DATA u32 u32_03002bc0[4] = {};                   // 0x03002BC0, Playerごとのビットフラグ, FUN_080093f8 が bit0 と bit1-2 を見る
COMMON_DATA u16 u16_03002bd0 = 0;                       // 0x03002BD0, FUN_0807b564 が 0 に戻す
COMMON_DATA u8 u8_03002bd2[14] = {};                    // todo
COMMON_DATA Player* gPlayerPtr[4] = {};                 // 0x03002BE0, 通信対戦時に自分が子機の場合も自キャラが 0 になるかは不明
COMMON_DATA u16 u16_03002bf0 = 0;                       // 0x03002BF0, 0 以外かつ gSunGaugeOverride が 1 のとき Entity0809eb24_Update が unk_29 を立てる
COMMON_DATA u8 u8_03002bf2[2] = {};                     // todo
COMMON_DATA u16 u16_03002bf4 = 0;                       // 0x03002BF4, Player_Destroy が 0 に戻す
COMMON_DATA u8 u8_03002bf6[2] = {};                     // todo

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

static inline EquipBuffs Player_GetFlag378(Player* p, EquipBuffs bits) { return p->equipBuffs & bits; }

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
// Tier A-B は試済 (animIdx + p->animIDOffset と p->animIDOffset + animIdx の両方: gcc がどちらもフィールド先に正規化する). animIDOffset をローカルに受けると第1被演算子は変わるが ldrb が sprite_88 / spriteSet_68 のアドレス計算より前に出てしまう
NON_MATCH bool32 Player_PlayAnim(Player* p, u32 animIdx, s32 animSpeed) {
#ifdef NONMATCHING_C
  MainAnimPlayFlags16 flags = 0;

  if (p->animID == animIdx) {
    flags = MAIN_ANIM_KEEP_FRAME;
  }
  p->animID = animIdx;

  MainSprite_SetAnim(&p->sprite_88, &p->spriteSet_68, animIdx + p->animIDOffset, 1, flags);
  if (p->xflip) {
    p->sprite_88.flags |= SPRFLAG_XFLIP;
  } else {
    p->sprite_88.flags &= ~SPRFLAG_XFLIP;
  }

  MainSprite_SetAnimSpeed(&p->sprite_88, (u16)animSpeed);
  return MainSprite_AdvanceAnim(&p->sprite_88, &p->spriteSet_68);
#else
  INCFUNC("asm/func/Player_PlayAnim.inc");
#endif
}

// 向きと速さから mover.delta を作る, 階段タイルの上では上りで 52/64, 下りで 40/64 に変える
// 残差10命令 (96/106): 原典は p を ip に置いたまま回すのでレジスタ圧が高く, こちらは低位レジスタで足りてしまう
// Tier A/B は試済
NON_MATCH void Player_SetMoveDelta(Player* p, s32 val) {
#ifdef NONMATCHING_C
  s32 angle = ((p->facing + 5) & 7) * 32;
  s32 v;

  v = val * gSineTable[(angle + 0x40) & 0xFF];
  if (v >= 0) {
    p->mover.delta.x = v >> 12;
  } else {
    p->mover.delta.x = -((-v) >> 12);
  }

  v = val * gSineTable[angle];
  if (v >= 0) {
    p->mover.delta.z = v >> 12;
  } else {
    p->mover.delta.z = -((-v) >> 12);
  }

  if (p->tile.stairs[1] == 1) {
    if (p->mover.delta.z < 0) {
      v = p->mover.delta.z * 40;
    } else {
      v = p->mover.delta.z * 52;
    }

    if (v >= 0) {
      p->mover.delta.z = v >> 6;
    } else {
      p->mover.delta.z = -((-v) >> 6);
    }
  } else if (p->tile.stairs[1] == 2) {
    if (p->mover.delta.x < 0) {
      v = p->mover.delta.x * 40;
    } else {
      v = p->mover.delta.x * 52;
    }

    if (v >= 0) {
      p->mover.delta.x = v >> 6;
    } else {
      p->mover.delta.x = -((-v) >> 6);
    }
  }
#else
  INCFUNC("asm/func/Player_SetMoveDelta.inc");
#endif
}

void Player_SetAction(Player* p, u32 action, u32 state) {
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

  p->shadowOffset.x = 0, p->shadowOffset.y = 0, p->shadowOffset.z = 0;
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

// 攻撃側 a から被弾側 b へ向かう向きを 1/3/5/7 の4象限に落として返す
u32 Player_GetHitDirIdx(HitboxData* a, HitboxData* b) {
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
void Player_SetHitDir(Player* p, HitboxData* a, HitboxData* b) {
  b->unk_40 = a->unk_40;
  if (a->unk_40 > 200) {
    b->unk_40 = 200;
  }

  if (Hitbox_TestAttr(a, HBATTR_18)) {
    p->unk_3d2 = 1;
    p->facing = Player_GetHitDirIdx(a, b);
    return;
  }

  if (p->action == 5) {
    b->flags |= HBFLAG_UNK_2;
    b->unk_40 = 0;
    return;
  }

  if (Player_TestFlag20(p, PFLAG20_UNK_15)) {
    if (a->flags & HBFLAG_ANGLE) {
      p->hitDir = ((((a->angle + 0x10) & 0xFF) >> 5) + 3) & 7;
    } else {
      s32 dx = a->center.x - b->center.x;
      s32 dz = a->center.z - b->center.z;

      if (dx == 0 && dz == 0) {
        p->hitDir = p->facing;
      } else {
        p->hitDir = (((((((u16)ArcTan2_8(dx, dz) + 0x10) & 0xFF) >> 5) + 3) & 7) + 4) & 7;
      }
    }

    p->unk_3e6 = b->unk_40;
    b->unk_40 = 0;
    b->flags |= HBFLAG_UNK_2;
    return;
  }

  p->unk_3d2 = 0;
  p->facing = Player_GetHitDirIdx(a, b);
}

bool32 Player_IsNight(Player* p) {
  u32 span;

  if (KAAMOS(p->isSabata) > 0) {
    return TRUE;
  }
  if (Player_TestEquipBuff(p, EBUFF_ALLNIGHT)) {
    return TRUE;
  }

  span = Time_GetSpanOfTime();
  if (span == TIME_UNK4 || span == TIME_UNK5 || span == TIME_NIGHT) {
    return TRUE;
  }
  return FALSE;
}

s32 GetPlayerCoffinID(void) {
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
  if (gFlag030047a4 & FLAG030047A4_UNK_12) {
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

// 足元の判定を1つ出す, コウモリ/ネズミ は小さいものを使う
void Player_EmitBurnSmoke(Player* p) {
  Vec3 size;
  Vec3 pos;

  if (p->kind == PLAYER_BAT || p->kind == PLAYER_MOUSE) {
    pos = p->sprite_e8.pos;
    size.x = 0x20, size.y = 0x20, size.z = 0x20;
  } else {
    pos = p->mover.pos;
    pos.y += 0x50;
    size.x = 0x40, size.y = 0x3C, size.z = 0x40;
  }

  EmitSmoke(&pos, 1, &size, 0, 0, 0xC, 2, 2);
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

  Particle_SetFrame(&p->ptcl_64c.ptcl, p->ptcl_64c.group1, (p->ptcl_64c.timer >> 2) + p->ptcl_64c.frameBase);
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

  Particle_SetFrame(ptcl, p->ptcl_64c.group1, p->ptcl_64c.frameBase);
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
  Particle_SetFrame(ptcl, p->ptcl_64c.group1, 4);
  ptcl->flags |= SPRFLAG_HIDDEN;
  ptcl->priority = 1;
  ptcl->offsetZ = 0x14;
  p->ptcl_64c.active = 0;
  p->ptcl_64c.timer = 0;
}

// 状態異常2が続いている間だけ, 周囲を回るパーティクルを1つ出し続ける
// 残差1命令 (157/156): Y方向の割り算の結果を置くレジスタだけ違う (原典は r0, こちらは r1)
// 代入を枝ごとに書く形は逆に離れた, Tier A/B は試済
NON_MATCH void Player_UpdateBadCondPtcl(Player* p) {
#ifdef NONMATCHING_C
  s32 angle;
  s32 v;
  s32 offset;

  if (p->ptcl_67c.active) {
    if (p->unk_1c != 1 || p->badCondTimer[2] == 0) {
      p->ptcl_67c.ptcl.flags |= SPRFLAG_HIDDEN;
      p->ptcl_67c.active = FALSE;
      return;
    }

    angle = (p->ptcl_67c.timer * 5) & 0xFF;

    v = gSineTable[(angle + 0x40) & 0xFF] * 56;
    if (v >= 0) {
      offset = v >> 12;
    } else {
      offset = -((-v) >> 12);
    }
    p->ptcl_67c.ptcl.pos.x = p->mover.pos.x + offset;

    v = gSineTable[angle] * 70;
    if (v >= 0) {
      offset = v >> 12;
    } else {
      offset = -((-v) >> 12);
    }
    p->ptcl_67c.ptcl.pos.y = offset + 0x15E + p->mover.pos.y;

    v = gSineTable[(angle + 0x40) & 0xFF] * 56;
    if (v >= 0) {
      offset = v >> 12;
    } else {
      offset = -((-v) >> 12);
    }
    p->ptcl_67c.ptcl.pos.z = p->mover.pos.z - offset;

    p->ptcl_67c.timer++;
    return;
  }

  if (p->unk_1c != 1 || p->badCondTimer[2] == 0) {
    return;
  }

  p->ptcl_67c.ptcl.pos = p->mover.pos;
  p->ptcl_67c.ptcl.pos.x += 0x38;
  p->ptcl_67c.ptcl.pos.y += 0x15E;
  p->ptcl_67c.ptcl.flags &= ~SPRFLAG_HIDDEN;
  Particle_SetFrame(&p->ptcl_67c.ptcl, p->ptcl_67c.group1, 0x10);
  p->ptcl_67c.timer = 0;
  p->ptcl_67c.active = TRUE;
#else
  INCFUNC("asm/func/Player_UpdateBadCondPtcl.inc");
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
  Particle_SetFrame(ptcl, p->ptcl_67c.group1, 0x10);
  ptcl->flags |= SPRFLAG_HIDDEN;
  ptcl->priority = 1;
  ptcl->offsetZ = 0x14;
  p->ptcl_67c.active = 0;
  p->ptcl_67c.timer = 0;
}

// 衝撃波のアニメーションを1フレーム進める, 終端まで行くと finished を立てて消す
// 衝撃波のアニメーションを1コマ進める, 末尾まで行ったら消して finished を落とす
// 残差3命令 (153/156): 原典は定数1を r3 に作って r1 へ複写して使い回すが, agbcc は都度作る
// anim のローカル化とガード後の代入で命令数はここまで詰まった, Tier A/B は試済
NON_MATCH void PlayerShockwave_UpdateAnim(PlayerShockwave* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  s32 done;

  if (!p->finished) {
    return;
  }

  anim = &p->anim;
  cmd = &anim->cmds[anim->cmdIdx];
  p->sprite.poseIdx = *cmd >> 6;

  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & 1)) {
    p->sprite.flags |= SPRFLAG_XFLIP;
  } else {
    p->sprite.flags &= ~SPRFLAG_XFLIP;
  }

  if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & 2)) {
    p->sprite.flags |= SPRFLAG_YFLIP;
  } else {
    p->sprite.flags &= ~SPRFLAG_YFLIP;
  }

  anim->tick++;
  if (anim->tick < anim->wait) {
    done = 0;
  } else {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      if (anim->cmdIdx == 0) {
        anim->cmdIdx = anim->cmdCount - 1;
        done = 1;
      } else {
        anim->cmdIdx--;
        done = 0;
      }
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
        done = 1;
      } else {
        done = 0;
      }
    }

    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = anim->duration * anim->speed >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }

  if (done != 0) {
    p->finished = FALSE;
    p->sprite.flags |= SPRFLAG_HIDDEN;
    return;
  }

  p->sprite.pos.x += p->vel.x;
  p->sprite.pos.z += p->vel.z;
#else
  INCFUNC("asm/func/PlayerShockwave_UpdateAnim.inc");
#endif
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
  p->meleeShockwave.gfx.plttID = p->sprite_88.plttID;
  p->meleeShockwave.gfx.pltt = p->sprite_88.pltt;
  AuxSprite_Show(&p->meleeShockwave.sprite);
  p->meleeShockwave.finished = TRUE;
}

// 黒ジャンゴが剣で攻撃する時に1回呼ばれる, 衝撃波を向きに応じてずらして出す
// 残差7命令 (130/123): 原典は idx を r6 に置いたまま回せているが, こちらはレジスタが足りず ip に退避してしまう
// 直接の原因は gSineTable のポインタを `adds r6, r2, #0` で call-saved に写してしまうこと (原典は r2 のまま使い回す)
// sprite ローカルの除去・PlayerShockwave* 化・gSineTable のローカル化はいずれも逆に遠ざかる
// gSineTable のローカル化は原典と逆 (原典は初回参照時に作る) で効かなかった, Tier A/B は試済
NON_MATCH void Player_SpawnSwordShockwave(Player* p, u32 idx, Vec3* pos) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &p->meleeShockwave.sprite;
  s32 angle = ((p->facing + 5) & 7) * 32;
  s32 v;
  s32 offset;
  s32 variant;
  s32 flags;

  sprite->pos = *pos;
  sprite->pos.y += 0xBE;

  v = gSineTable[(angle + 0x40) & 0xFF] * 240;
  if (v >= 0) {
    offset = v >> 12;
  } else {
    offset = -((-v) >> 12);
  }
  sprite->pos.x += offset;

  v = gSineTable[angle] * 240;
  if (v >= 0) {
    offset = v >> 12;
  } else {
    offset = -((-v) >> 12);
  }
  sprite->pos.z += offset;

  v = gSineTable[(angle + 0x40) & 0xFF] * 10;
  if (v >= 0) {
    p->meleeShockwave.vel.x = v >> 12;
  } else {
    p->meleeShockwave.vel.x = -((-v) >> 12);
  }

  v = gSineTable[angle] * 10;
  if (v >= 0) {
    p->meleeShockwave.vel.z = v >> 12;
  } else {
    p->meleeShockwave.vel.z = -((-v) >> 12);
  }

  Player_GetShockwaveDirParams(idx, &variant, &flags);
  AuxAnim_SetAnim(&p->meleeShockwave.anim, p->meleeShockwave.animFile, 0, variant, flags);
  FUN_0806181c(p);
#else
  INCFUNC("asm/func/Player_SpawnSwordShockwave.inc");
#endif
}

// 黒ジャンゴが槍で攻撃する時に1回呼ばれる, n で衝撃波の高さと前に出る距離が変わる
// 残差7命令 (140/133): Player_SpawnSwordShockwave と同じレジスタ圧の差
NON_MATCH void Player_SpawnSpearShockwave(Player* p, u32 idx, Vec3* pos, s32 n) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &p->meleeShockwave.sprite;
  s32 height;
  s32 dist;
  s32 angle;
  s32 v;
  s32 offset;
  s32 variant;
  s32 flags;

  if (n == 0) {
    height = 0xA0;
    dist = 0x1C2;
  } else if (n == 1) {
    height = 0x8C;
    dist = 0x152;
  } else {
    height = 0x78;
    dist = 0xE0;
  }

  angle = ((p->facing + 5) & 7) * 32;

  sprite->pos = *pos;
  sprite->pos.y += height;

  v = dist * gSineTable[(angle + 0x40) & 0xFF];
  if (v >= 0) {
    offset = v >> 12;
  } else {
    offset = -((-v) >> 12);
  }
  sprite->pos.x += offset;

  v = dist * gSineTable[angle];
  if (v >= 0) {
    offset = v >> 12;
  } else {
    offset = -((-v) >> 12);
  }
  sprite->pos.z += offset;

  v = gSineTable[(angle + 0x40) & 0xFF] * 10;
  if (v >= 0) {
    p->meleeShockwave.vel.x = v >> 12;
  } else {
    p->meleeShockwave.vel.x = -((-v) >> 12);
  }

  v = gSineTable[angle] * 10;
  if (v >= 0) {
    p->meleeShockwave.vel.z = v >> 12;
  } else {
    p->meleeShockwave.vel.z = -((-v) >> 12);
  }

  Player_GetShockwaveDirParams(idx, &variant, &flags);
  AuxAnim_SetAnim(&p->meleeShockwave.anim, p->meleeShockwave.animFile, 1, variant, flags);
  FUN_0806181c(p);
#else
  INCFUNC("asm/func/Player_SpawnSpearShockwave.inc");
#endif
}

// Player_SpawnSwordShockwave のような関数だが、いつ呼ばれるか不明 (武器の攻撃ではない)
// 衝撃波を pos から向きの反対側に少しずらして出す
void Player_SpawnShockwaveBehind(Player* p, u32 idx, Vec3* pos) {
  AuxSprite* sprite = &p->meleeShockwave.sprite;
  s32 angle = ((p->facing + 5) & 7) * 32;
  sprite->pos = *pos;

  sprite->pos.x += COS(angle, 180);
  sprite->pos.z += SIN(angle, 180);

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
  p->meleeShockwave.sprite.rotation = p->gunSpreadAngle;
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
      Particle_SetFrame(&ptcl->base, p->ptcl_718.group, ptcl->frameBase + 1);
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
  Particle_SetFrame(&ptcl->base, p->ptcl_718.group, ptcl->frameBase);
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
// 残差11命令 (139/150): 原典は gSineTable と 0xFF と生存数を r8-r10 に抱えるが, agbcc はループ内で作り直す
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
    s32 v;

    if (!ptcl->active) {
      continue;
    }

    if (abs(ptcl->offset.x) <= 15 && abs(ptcl->offset.z) <= 15) {
      ptcl->base.flags |= SPRFLAG_HIDDEN;
      ptcl->active = FALSE;
      continue;
    }

    angle = ArcTan2_8(ptcl->offset.x, ptcl->offset.z);

    v = gSineTable[(angle + 0x40) & 0xFF] * ptcl->speed;
    if (v >= 0) {
      ptcl->offset.x -= v >> 12;
    } else {
      ptcl->offset.x -= -((-v) >> 12);
    }

    v = gSineTable[angle & 0xFF] * ptcl->speed;
    if (v >= 0) {
      ptcl->offset.z -= v >> 12;
    } else {
      ptcl->offset.z -= -((-v) >> 12);
    }

    ptcl->base.pos.x = ptcl->offset.x + p->pos_930.x;
    ptcl->base.pos.z = ptcl->offset.z + p->pos_930.z;

    ptcl->timer++;
    if (ptcl->timer == 4) {
      Particle_SetFrame(&ptcl->base, p->ptcl_858.group, ptcl->frameBase + 1);
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
// 残差7命令 (155/162): Player_SpawnPtcl858 と同じで, 原典は p と pos を r8/r9 に置くがこちらは r8 だけで足りる
NON_MATCH void Player_SpawnSunPtcl858(Player* p, Vec3* pos) {
#ifdef NONMATCHING_C
  PlayerPtcl858* ptcl;
  u16* table;
  u32 idx;
  s32 angle;
  s32 dist;
  s32 v;

  p->ptcl_858.unk_06 += gStat->sunGauge + 2;
  if (p->ptcl_858.unk_06 <= 0x27) {
    return;
  }

  ptcl = &p->ptcl_858.ptcls[p->ptcl_858.unk_05];
  ptcl->base.flags &= ~SPRFLAG_HIDDEN;
  ptcl->frameBase = 2;
  Particle_SetFrame(&ptcl->base, p->ptcl_858.group, 2);

  table = gRandomTable;
  idx = (gRandTableIdx + 1) & 0x3FF;
  angle = (u8)table[idx];
  gRandTableIdx = (idx + 1) & 0x3FF;
  dist = (table[gRandTableIdx] & 0x3F) + 0x80;

  v = dist * gSineTable[(angle + 0x40) & 0xFF];
  if (v >= 0) {
    ptcl->offset.x = v >> 12;
  } else {
    ptcl->offset.x = -((-v) >> 12);
  }

  v = dist * gSineTable[angle];
  if (v >= 0) {
    ptcl->offset.z = v >> 12;
  } else {
    ptcl->offset.z = -((-v) >> 12);
  }

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
// 残差6命令 (145/151): 原典は p と pos を r8/r9 に置くが, こちらは r8 だけで足りてしまう
NON_MATCH void Player_SpawnPtcl858(Player* p, Vec3* pos) {
#ifdef NONMATCHING_C
  PlayerPtcl858* ptcl;
  u16* table;
  u32 idx;
  s32 angle;
  s32 dist;
  s32 v;

  p->ptcl_858.unk_06++;
  if ((p->ptcl_858.unk_06 & 3) != 0) {
    return;
  }

  ptcl = &p->ptcl_858.ptcls[p->ptcl_858.unk_05];
  ptcl->base.flags &= ~SPRFLAG_HIDDEN;
  ptcl->frameBase = 4;
  Particle_SetFrame(&ptcl->base, p->ptcl_858.group, 4);

  table = gRandomTable;
  idx = (gRandTableIdx + 1) & 0x3FF;
  angle = (u8)table[idx];
  gRandTableIdx = (idx + 1) & 0x3FF;
  dist = (table[gRandTableIdx] & 0x7F) + 0x100;

  v = dist * gSineTable[(angle + 0x40) & 0xFF];
  if (v >= 0) {
    ptcl->offset.x = v >> 12;
  } else {
    ptcl->offset.x = -((-v) >> 12);
  }

  v = dist * gSineTable[angle];
  if (v >= 0) {
    ptcl->offset.z = v >> 12;
  } else {
    ptcl->offset.z = -((-v) >> 12);
  }

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
    if (p->unk_359 == 0) {
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
  } else if (p->unk_359 == 0) {
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
// 残差は屋外判定の 0/1 正規化4命令だけ (29/34), 原典は真偽値を一度レジスタに作ってから 0 と比べている
// マスクを引数に取る `static inline bool32 f(u32 mask) { return (gStat->unk_934 & mask) != 0; }` 経由だと 32/34 まで詰まる
// (定数マスクを直接書くと lsrs のビット抽出になってしまうので, マスクはレジスタに乗る形が必須)
// 残るのは 0/1 の materialize だけ. if/return TRUE/FALSE 形や bool32 ローカルへの代入は agbcc が畳んでしまう
NON_MATCH u32 FUN_0806241c(Player* p) {
#ifdef NONMATCHING_C
  u32 r = 0;

  if (gStat->unk_934 & SF934_OUTDOOR) {
    if (Player_TestFlag20(p, PFLAG20_SUNBATHING)) {
      r = 4;
    }
  } else {
    if (Player_TestFlag20(p, PFLAG20_SUNBATHING)) {
      r = 8;
    }
  }

  return r;
#else
  INCFUNC("asm/func/FUN_0806241c.inc");
#endif
}

// unk_950 ごとに3色ずつ並んだ表から、パレットの5,6,13番を差し替える
void FUN_08062468(Player* p) {
  rgb555* src = &gObjPlttData[0x280];

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
    if (p->unk_359 == 0) {
      p->sprite_88.pltt = p->pltt_2a4;
    } else {
      p->gfx_114->pltt = p->pltt_2a4;
    }
    return;
  }

  if (p->unk_359 == 0) {
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
    p->sprite_88.pltt = &p->pltt_2a4[16];
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
    p->gfx_114->pltt = &p->pltt_2a4[16];
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

  if (p->unk_960 != 0) {
    p->unk_964 = 0;
    if (p->unk_960 > 0x1F) {
      src = &gObjPlttData[p->plttID_95e * 16];
      if (p->unk_359 == 0) {
        for (i = 0; i < 16; i++) {
          if (i == 5 || i == 6 || i == 13) {
            p->pltt_2a4[16 + i] = p->pltt_2a4[i];
          } else {
            p->pltt_2a4[16 + i] = src[i];
          }
        }
        p->sprite_88.pltt = &p->pltt_2a4[16];
      } else {
        for (i = 0; i < 16; i++) {
          p->pltt_2a4[16 + i] = src[i];
        }
        p->gfx_114->pltt = &p->pltt_2a4[16];
      }
    } else {
      src = &gObjPlttData[p->plttID_95e * 16];
      w = p->unk_960;
      Player_BlendPltt(p, src, w, 0x20 - w, 5);
    }

    p->unk_960--;
    return;
  }

  cost = Player_CheckMagicEnchant(p);
  if (cost >= 0) {
    p->unk_962 = cost + 0x121;
    src = &gObjPlttData[p->unk_962 * 16];
    if (p->unk_964 <= 0x1F) {
      w = p->unk_964;
    } else if (p->unk_964 <= 0x2F) {
      w = 0x20;
    } else if (p->unk_964 <= 0x4F) {
      w = 0x50 - p->unk_964;
    } else {
      w = 0;
    }

    Player_BlendPltt(p, src, w, 0x20 - w, 5);
    p->unk_964++;
    if (p->unk_964 > 0x5F) {
      p->unk_964 = 0;
    }
    return;
  }

  if (p->unk_964 >= 1 && p->unk_964 <= 0x4F) {
    src = &gObjPlttData[p->unk_962 * 16];
    if (p->unk_964 >= 0x21 && p->unk_964 <= 0x2F) {
      p->unk_964 = 0x30;
    }

    if (p->unk_964 <= 0x20) {
      w = p->unk_964;
      p->unk_964 = w - 1;
    } else {
      w = 0x50 - p->unk_964;
      p->unk_964++;
      if (p->unk_964 > 0x4F) {
        p->unk_964 = 0;
      }
    }

    Player_BlendPltt(p, src, w, 0x20 - w, 5);
    return;
  }

  p->unk_962 = 0;
  p->unk_964 = 0;
  if (p->unk_359 == 0) {
    p->sprite_88.pltt = p->pltt_2a4;
  } else {
    p->gfx_114->pltt = p->pltt_2a4;
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

    p->unk_964 = 0;
    if (p->unk_960 > 0x1F) {
      src = &gObjPlttData[p->plttID_95e * 16];
      if (p->unk_359 == 0) {
        for (i = 0; i < 16; i++) {
          if (i == 5 || i == 6 || i == 13) {
            p->pltt_2a4[16 + i] = p->pltt_2a4[i];
          } else {
            p->pltt_2a4[16 + i] = src[i];
          }
        }
        p->sprite_88.pltt = &p->pltt_2a4[16];
      } else {
        for (i = 0; i < 16; i++) {
          p->pltt_2a4[16 + i] = src[i];
        }
        p->gfx_114->pltt = &p->pltt_2a4[16];
      }
      return;
    }

    src = &gObjPlttData[p->plttID_95e * 16];
    w = p->unk_960;
    Player_BlendPltt(p, src, w, 0x20 - w, 5);
    p->unk_960++;
    return;
  }

  if (p->unk_96c == 2) {
    rgb555* src;
    s32 w;

    p->unk_964 = 0;
    src = &gObjPlttData[p->plttID_95e * 16];
    if (p->unk_960 <= 0x1F) {
      w = p->unk_960;
    } else if (p->unk_960 <= 0x2F) {
      w = 0x20;
    } else if (p->unk_960 <= 0x4F) {
      w = 0x50 - p->unk_960;
    } else {
      w = 0;
    }

    Player_BlendPltt(p, src, w, 0x20 - w, 5);
    p->unk_960++;
    if (p->unk_960 > 0x5F) {
      p->unk_960 = 0;
    }
    return;
  }

  if (p->unk_960 != 0) {
    rgb555* src;
    s32 w;
    s32 i;

    p->unk_964 = 0;
    if (p->unk_960 > 0x1F) {
      src = &gObjPlttData[p->plttID_95e * 16];
      if (p->unk_359 == 0) {
        for (i = 0; i < 16; i++) {
          if (i == 5 || i == 6 || i == 13) {
            p->pltt_2a4[16 + i] = p->pltt_2a4[i];
          } else {
            p->pltt_2a4[16 + i] = src[i];
          }
        }
        p->sprite_88.pltt = &p->pltt_2a4[16];
      } else {
        for (i = 0; i < 16; i++) {
          p->pltt_2a4[16 + i] = src[i];
        }
        p->gfx_114->pltt = &p->pltt_2a4[16];
      }
    } else {
      src = &gObjPlttData[p->plttID_95e * 16];
      w = p->unk_960;
      Player_BlendPltt(p, src, w, 0x20 - w, 5);
    }

    p->unk_960--;
    return;
  }

  if (p->unk_964 >= 1 && p->unk_964 <= 0x4F) {
    rgb555* src = &gObjPlttData[p->unk_962 * 16];
    s32 w;

    if (p->unk_964 >= 0x21 && p->unk_964 <= 0x2F) {
      p->unk_964 = 0x30;
    }

    if (p->unk_964 <= 0x20) {
      w = p->unk_964;
      p->unk_964 = w - 1;
    } else {
      w = 0x50 - p->unk_964;
      p->unk_964++;
      if (p->unk_964 > 0x4F) {
        p->unk_964 = 0;
      }
    }

    Player_BlendPltt(p, src, w, 0x20 - w, 5);
    return;
  }

  p->unk_964 = 0;
  if (p->unk_359 == 0) {
    p->sprite_88.pltt = p->pltt_2a4;
  } else {
    p->gfx_114->pltt = p->pltt_2a4;
  }
#else
  INCFUNC("asm/func/FUN_080628ec.inc");
#endif
}

void Player_SetBasePlttID(Player* p) {
  if (p->playerIdx == 0) {
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
  p->sprite_88.plttID = p->plttID_94a;
  p->sprite_88.pltt = p->pltt_2a4;
  p->gfx_114->plttID = p->plttID_94a;
  p->gfx_114->pltt = p->pltt_2a4;
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

  if (p->unk_4c4.kind == 1) {
    Eff082473e0Emitter_FadeParticle(&p->unk_4c4);
    return;
  }

  if (p->unk_4c4.kind == 2) {
    PlaySound_082406e0(SE_308);
  } else if (p->unk_4c4.kind == 3) {
    PlaySound_082406e0(SE_308);
  }

  src = p->unk_4c4.pos;
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
  Eff082473e0Emitter_BurstParticle(&p->unk_4c4, 3, &pos, &vel, &velRange, 0x28, 0x28);
#else
  INCFUNC("asm/func/Player_BurstFormEffect.inc");
#endif
}

void FUN_08063220(Player* p) {
  s32 count = p->unk_4c4.unk_3;
  s32 i;

  for (i = 0; i < count; i++) {
    Player_BurstFormEffect(p);
  }
}

void FUN_08063248(Player* p) {
  if (p->unk_4c4.kind == 1) {
    Eff082473e0Emitter_Reset(&p->unk_4c4);
  } else {
    s32 count = p->unk_4c4.unk_3;
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

  if (p->unk_4c4.unk_3 != 0) {
    if (p->unk_4c4.kind != kind) {
      if (p->unk_4c4.kind == 3) {
        return;
      }
      FUN_08063248(p);
    }
  }

  if (p->unk_4c4.unk_3 == 0) {
    p->angle_401 = p->angle_400;
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
  if (FUN_082467d0(&p->unk_4c4, kind, 0xE10, &spread) >= 0) {
    if (p->unk_4c4.kind == 1) {
      PlaySound_082406e0(SE_401);
    } else if (p->unk_4c4.kind == 2) {
      p->damage += 10;
      PlaySound_082406e0(SE_CRASH_307);
    } else if (p->unk_4c4.kind == 3) {
      PlaySound_082406e0(SE_CRASH_307);
    }

    p->badCondTimer[1] = 0;
  }
#else
  INCFUNC("asm/func/Player_StartFormEffect.inc");
#endif
}

s32 FUN_08063478(Player* p) { return (p->angle_400 - p->angle_401 + 0x100) & 0xFF; }

// 姿勢を決める, 変化直後は 0x40 フレームのあいだ 4フレームおきに前の値と交互に返す
u32 Player_ApplyPoseHold(Player* p, u32 n) {
  static const u8 u8_ARRAY_085abab4[4] = {3, 4, 6, 0};  // 0x085ABAB4

  u32 pose = n;

  if (p->unk_4c4.unk_3 != 0) {
    if (p->unk_1c & 1) {
      if (FUN_08063478(p) >= u8_ARRAY_085abab4[p->unk_4c4.kind - 1]) {
        Player_BurstFormEffect(p);
        p->angle_401 = p->angle_400;
      }
    }

    if (p->unk_4c4.unk_3 != 0) {
      if (p->unk_4c4.kind == 1) {
        pose = 3;
      } else if (p->unk_4c4.kind == 2) {
        pose = 4;
      } else if (p->unk_4c4.kind == 3) {
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
// 命令数は76で一致, 残差は 0x03002B64 / gRandTableIdx / gRandomTable のプール定数をロードする順序だけ
// (原典は 0x03002B64 を if の先頭で先に作る), 連鎖代入にすると push が1本減って逆に遠ざかる
NON_MATCH void Player_ApplyBadCondition(Player* p, s32 badcondID, s32 frames) {
#ifdef NONMATCHING_C
  switch (badcondID) {
    case BAD_HARAITA: {
      break;
    }
    case BAD_POISON: {
      if (p->unk_4c4.unk_3 != 0) {
        if (p->unk_4c4.kind == 3) {
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
        gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
        gConfusedDir = (p->controlUp + 1 + Mod(gRandomTable[gRandTableIdx], 7)) & 7;
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
    if (p->unk_1c & 1) {
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
          if (p->unk_1c & 1) {
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
        if (p->badCondTimer[BAD_HARAITA] != 0 && (p->unk_1c & 1)) {
          p->badCondTimer[BAD_HARAITA]--;
          if (p->input->down & DPAD_ANY) {
            MosaicFader_Start(2, 1, 0x1E, p->mosaicFrom, p->unk_980, p->mosaicInterval);
          }
        }
        break;
      }
      case BAD_CONFUSE: {
        if (p->badCondTimer[BAD_CONFUSE] != 0 && (p->unk_1c & 1)) {
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
// 残差は共有された return pose のブロック位置だけ (23/23), Tier A の分岐形 4通りと Tier B は試済, player_sabata.c の LinkPlayer_ApplyFlashPose も同じ残差
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

      p->sprite_88.flags |= SPRFLAG_AFFINE;
      scale = 0x40 - (p->unk_97a >> 1);
      p->sprite_88.scaleX = scale;
      p->sprite_88.scaleY = scale;
      p->flag20 |= 0x50000;
    } else if (p->unk_97a != 0) {
      if (p->unk_3f1 != 0) {
        PlaySound_082406e0(SONG_822);
        p->unk_3f1 = 0;
      }

      p->unk_97a--;
      if (p->unk_97a == 0) {
        p->sprite_88.flags &= ~(SPRFLAG_HIDDEN | SPRFLAG_AFFINE);
        scale = 0x40;
      } else {
        p->sprite_88.flags |= SPRFLAG_AFFINE;
        scale = 0x40 - (p->unk_97a >> 1);
      }
      p->sprite_88.scaleX = scale;
      p->sprite_88.scaleY = scale;
    }

    if (p->goodCondID == GOOD_INVISIBLE) {
      p->sprite_88.flags |= SPRFLAG_BLINK_ODD;
      p->flag20 |= 0x20000;
    } else {
      p->sprite_88.flags &= ~SPRFLAG_BLINK_ODD;
    }

    if (p->unk_1c & 1) {
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
        p->sprite_88.flags &= ~(SPRFLAG_HIDDEN | SPRFLAG_AFFINE);
        scale = 0x40;
      } else {
        p->sprite_88.flags |= SPRFLAG_AFFINE;
        scale = 0x40 - (p->unk_97a >> 1);
      }
      p->sprite_88.scaleX = scale;
      p->sprite_88.scaleY = scale;
    }

    if (p->sprite_88.flags & SPRFLAG_BLINK_ODD) {
      p->sprite_88.flags &= ~SPRFLAG_BLINK_ODD;
    }
  }
#else
  INCFUNC("asm/func/Player_UpdateFormScale.inc");
#endif
}

void FUN_080639d0(Player* p) {
  if (p->input->pressed & (A_BUTTON | B_BUTTON | DPAD_RIGHT | DPAD_LEFT | DPAD_UP | DPAD_DOWN)) {
    p->angle_400++;
  }
}

// Player の毎フレーム更新のうち, 姿勢の決定・パーティクル・影の位置合わせをまとめた部分
void Player_UpdatePoseAndShadow(Player* p) {
  s32 pose = 0;

  if (p->mover.unk_4 == 0) {
    Player_UpdateFormScale(p);
    FUN_080639d0(p);
    pose = Player_TickBadCondTimers(p, 0);
    pose = Player_ApplyPoseHold(p, pose);
    pose = Player_ApplyFlashPose(p, pose);
  } else if (KAAMOS(p->isSabata) > 0) {
    pose = 6;
  }

  if (p->unk_1c == 2) {
    FUN_080628ec(p, pose);
  } else {
    Player_UpdatePltt(p, pose);
  }

  Player_UpdatePtcl64c(p);
  Player_UpdateBadCondPtcl(p);
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
  Eff082473e0Emitter_Destroy(&p->unk_4c4);
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

  if (p->unk_359 == 1) {
    Eff082473e0Emitter_Init(&p->unk_4c4, &p->sprite_e8.pos, 0, 0, 1);
  } else {
    Eff082473e0Emitter_Init(&p->unk_4c4, &p->sprite_88.pos, 0, 0, 1);
  }

  p->shadowPos = p->sprite_88.pos;
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
  u16_03002bac = 0;
  gWindAngle = 0;
  u16_03002b84 = 1;
  u16_03002bf0 = 0;
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
  if (p->unk_4c4.unk_3 != 0) return 10;
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
    return min(n, 10);
  }
  if (Hitbox_TestAttr(b, HBATTR_THING)) {
    s32 n = gStat->killCounts[1] >> 6;
    return min(n, 10);
  }
  if (Hitbox_TestAttr(b, HBATTR_PHANTOM)) {
    s32 n = gStat->killCounts[2] >> 6;
    return min(n, 10);
  }
  if (Hitbox_TestAttr(b, HBATTR_UNDEAD)) {
    s32 n = gStat->killCounts[3] >> 6;
    return min(n, 10);
  }
  if (Hitbox_TestAttr(b, HBATTR_IMMORTAL)) {
    s32 n = gStat->killCounts[4] >> 6;
    return min(n, 10);
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
    return 1 << 19;
  }
  return 0;
}

// ブラッドソードの吸収, 通常状態でジャンゴなら damage を増やし, それ以外なら HP を1回復して判定を出す
void Player_UpdateBloodSword(Player* p) {
  if (p->unk_1c != 1 || !Player_TestEquipBuff(p, EBUFF_BLOOD_SWORD)) {
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
    FUN_0805fe7c(&p->hurtbox, 1, 1, &p->mover.pos, &p->pos_970, p->unk_978);
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
// 残差29命令 (221/250): 原典は各 case で Vec3 の半分ずつを and/or で差し込むが, agbcc は定数同士をまとめて1ワードで書いてしまう
// HitboxData* のローカル化は試済
NON_MATCH void Player_SetWeaponHitbox(Player* p) {
#ifdef NONMATCHING_C
  HitboxData* hitbox = hitbox;
  Vec3 halfSize, offset;
  HitboxAttributes attrs;

  if (p->kind == PLAYER_SABATA) {
    attrs = 0;
    halfSize.x = 0xAA;
    halfSize.y = 0x32;
    halfSize.z = 0xAA;
    offset.x = 0;
    offset.y = 0xFFEC;
    offset.z = 0;
    Hitbox_Init(hitbox, 0, (HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0), 0, (0x10000 << p->mover.unk_4) >> 16, &halfSize, &offset);
    Hitbox_SetAttack(hitbox, 20, 0x32, 0x10, HBATTR_DARK, 0x14);
    Hitbox_SetHandler(hitbox, NULL, p);
    return;
  }

  if (p->weaponKind > 4) {
    return;
  }

  switch (p->weaponKind) {
    case WK_SWORD: {
      halfSize.x = 0x5A;
      halfSize.y = 0x320;
      halfSize.z = 0x5A;
      offset.x = 0;
      offset.y = 0xFFE7;
      offset.z = 0;
      attrs = 1;
      p->unk_a7c = 0x20;
      p->unk_a7e = 0xA;
      break;
    }
    case WK_SPEAR: {
      halfSize.x = 0x3C;
      halfSize.y = 0x640;
      halfSize.z = 0x3C;
      offset.x = 0;
      offset.y = 0;
      offset.z = 0;
      attrs = 2;
      p->unk_a7c = 0x40;
      p->unk_a7e = 0x14;
      break;
    }
    case WK_HAMMER: {
      halfSize.x = 0x50;
      halfSize.y = 0x460;
      halfSize.z = 0x50;
      offset.x = 0;
      offset.y = 0x1E;
      offset.z = 0;
      attrs = 4;
      p->unk_a7c = 0x30;
      p->unk_a7e = 0x14;
      break;
    }
    case WK_OTHERS: {
      halfSize.x = 0x3C;
      halfSize.y = 0x640;
      halfSize.z = 0x3C;
      offset.x = 0;
      offset.y = 0xFFB0;
      offset.z = 0;
      attrs = 8;
      p->unk_a7c = 1;
      p->unk_a7e = 5;
      break;
    }
    case WK_GUN: {
      halfSize.x = 0x3C;
      halfSize.y = 0x320;
      halfSize.z = 0x3C;
      offset.x = 0;
      offset.y = 0xFFE7;
      offset.z = 0;
      attrs = 0x10;
      p->unk_a7c = 0x20;
      p->unk_a7e = 0x14;
      break;
    }
  }

  Hitbox_Init(hitbox, 0, (HBFLAG_HITBOX | HBFLAG_ANGLE | HBFLAG_UNK_0), 0, (0x10000 << p->mover.unk_4) >> 16, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, p->totalAtk_a7a, p->unk_a7c, attrs, 0, p->unk_a7e);
  Hitbox_SetHandler(hitbox, dark_django_0806f990, p);
#else
  INCFUNC("asm/func/Player_SetWeaponHitbox.inc");
#endif
}

void FUN_08064658(Player* p, Weapon* w) { p->weapon = w; }

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
    if (p->weapon == NULL) {
      wd = gWeaponDB[WEAPON_NONE];
    } else {
      BuildWeaponData(p->weapon, &wd);
    }
  } else {
    p->weapon = NULL;
    wd = gWeaponDB[WEAPON_GUN_DEL_HELL];
  }

  p->weaponID = wd.id;
  p->weaponKind = wd.kind;
  p->weaponAtk = wd.atk;
  p->totalAtk_a7a = FUN_0807a6cc(&wd);
  Player_EnableWeaponSpecialEffects(p, &wd);

  if (p->weaponID == WEAPON_MEGA_BUSTER) {
    p->attackCB = FUN_08071b14;
  } else {
    p->attackCB = sPlayerAttackUpdates[p->weaponKind];
  }

  Player_SetWeaponHitbox(p);
  if (p->action == 3) {
    Player_SetAction(p, 0, 0);
  }
}

// HitboxData.damage (Player.unk_a10.damage) が0以外なら Weapon.wear に加算して HitboxData.damage を 0にする, ジャンゴがバットに攻撃を当てると呼ばれる FUN_0813e944 の 0x0813EFFC で加算される (他の敵も同様と思われる)
// 攻撃で与えたダメージの分だけ武器を損傷させる, 限界を超えたら品質か特殊効果を1つ失う
// 残差3命令 (93/96): 原典は unk_a10.damage のアドレスを 0xA10 + 0x3E に分けて作るが agbcc は 0xA4E を1つの定数に畳む
// HitboxData* のローカル化は 89 命令まで減って逆に遠ざかる (r7 まで使い始める), Tier A/B は試済
NON_MATCH void Player_UpdateWeaponWear(Player* p) {
#ifdef NONMATCHING_C
  s32 wear = p->unk_a10.damage;

  if (wear <= 0) {
    return;
  }

  if (Player_TestEquipBuff(p, EBUFF_WEAPONGUARD)) {
    p->unk_a10.damage = 0;
    return;
  }

  if (p->weaponKind <= 2) {
    if (Player_TestEquipBuff(p, EBUFF_WET_DURABILITY)) {
      wear >>= 1;
    }

    if ((s8)p->weapon->quality > 0) {
      p->weapon->wear += wear;
      if (p->weapon->wear >= 200) {
        p->weapon->quality--;
        p->weapon->wear = 0;
        FUN_0809c4f4();
        Player_ApplyWeapon(p, p->weapon);
      }
    } else if (*(u8*)&p->weapon->effects[2] != 0) {
      p->weapon->wear += wear;
      if (p->weapon->wear >= 2000) {
        *(u8*)&p->weapon->effects[2] = 0;
        p->weapon->wear = 0;
        FUN_0809c4f4();
        Player_ApplyWeapon(p, p->weapon);
      }
    } else if (*(u8*)&p->weapon->effects[1] != 0) {
      p->weapon->wear += wear;
      if (p->weapon->wear >= 2000) {
        *(u8*)&p->weapon->effects[1] = 0;
        p->weapon->wear = 0;
        FUN_0809c4f4();
        Player_ApplyWeapon(p, p->weapon);
      }
    }
  }

  p->unk_a10.damage = 0;
#else
  INCFUNC("asm/func/Player_UpdateWeaponWear.inc");
#endif
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

  if (gFlag030047a4 & FLAG030047A4_UNK_12) {
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
    if ((s32)gStat->solarStand < cost) {
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
    if (p->weaponKind != WK_OTHERS && p->weaponKind != WK_GUN) {
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
            p->unk_964 = 0x20;
            p->unk_951 = id + 1;
          }
        }
      } else if (id >= MAGIC_SLEEPING && id <= MAGIC_RAT) {
        if (p->action > 1) {
          return p->action;
        }

        if (id == MAGIC_BAT) {
          if (p->kind != PLAYER_BAT) {
            if (!Player_CheckMagicCost(p)) {
              return p->action;
            }
            p->gfx_114 = &p->gfxForms[0];
            AuxSprite_SetGfx(&p->sprite_e8, p->gfx_114);
            AuxAnim_RestartAnim(&p->anim_33c, p->anim_34c, 0, 0, 1);
            p->unk_382 = 0xBE;
            p->sprite_e8.flags = 1;
            Player_PayMagicCost(p);
          }
          return 0xC;
        }

        if (id == MAGIC_RAT) {
          if (p->kind != PLAYER_MOUSE) {
            if (!Player_CheckMagicCost(p)) {
              return p->action;
            }
            p->gfx_114 = &p->gfxForms[1];
            AuxSprite_SetGfx(&p->sprite_e8, p->gfx_114);
            AuxAnim_RestartAnim(&p->anim_33c, p->anim_350, 0, 0, 1);
            p->sprite_e8.flags = 1;
            Player_PayMagicCost(p);
          }
          return 0xD;
        }

        if (p->kind != PLAYER_SLEEPING) {
          if (!Player_CheckMagicCost(p)) {
            return p->action;
          }
          p->gfx_114 = &p->gfxForms[2];
          AuxSprite_SetGfx(&p->sprite_e8, p->gfx_114);
          AuxAnim_RestartAnim(&p->anim_33c, p->anim_354, 0, 0, 1);
          p->sprite_e8.flags = 1;
          Player_PayMagicCost(p);
        }
        return 0xE;
      } else {
        if (p->action > 1) {
          return p->action;
        }

        if (id == MAGIC_WOLF) {
          if (!Player_CheckMagicCost(p)) {
            return p->action;
          }
          return 0xB;
        }
        if (id == MAGIC_TRANSFORM) {
          return 0xA;
        }
        if (id == MAGIC_RISING_SUN || id == MAGIC_BLACK_SUN) {
          return 9;
        }
        if (id == MAGIC_ZERO_SHIFT) {
          if (!Player_CheckMagicCost(p)) {
            return p->action;
          }
          Player_PayMagicCost(p);
          return 2;
        }
        if (id == MAGIC_DASH) {
          return 2;
        }
        if (id == MAGIC_DYNAMITE) {
          if (p->dynamiteCount != 0) {
            return p->action;
          }
          return 0x11;
        }
        if (id == MAGIC_FREEZE) {
          return 0xF;
        }
        if (id == MAGIC_HEALING) {
          return 0x10;
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
    Player_SetAction(p, 12, 0);
  } else if (p->kind == PLAYER_MOUSE) {
    Player_SetAction(p, 13, 0);
  } else if (p->kind == PLAYER_SLEEPING) {
    Player_SetAction(p, 14, 0);
  }

  m->id = n;
  if ((s8)n < 0) {
    m->enchanted = FALSE;
    m->cat = 0xFF;
    m->availableForm = FALSE;
    m->basicCost = 0;
    p->enchantStarted = 0;
    if (p->unk_962 == 0) {
      p->unk_964 = 0;
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
        p->unk_964 = 0x20;
        p->unk_962 = m->id + 0x121;
        p->unk_951 = m->id + 1;
      }
      return;
    }

    m->enchanted = FALSE;
    p->enchantStarted = 0;
    if (p->unk_962 == 0) {
      p->unk_964 = 0;
    }
  }

  p->unk_951 = p->unk_950;
}

// 使う魔法の番号を返す, サバタは固定の2種から選び、それ以外は登録魔法から引く
s32 Player_GetEquippedMagic(Player* p) {
  if (p->kind != PLAYER_SABATA) {
    return *(gStat->equippedMagicIdx + gStat->registeredMagic);
  }

  u16_03002bb0 = 0;

  if (gStat->sabataMagicIdx == 0) return MAGIC_ZERO_SHIFT;
  return MAGIC_BLACK_SUN;
}

// 装備魔法の情報 (カテゴリ・消費MP・フォームで使えるか・エンチャント中か) を再計算する
void Player_RefreshMagicInfo(Player* p) {
  PlayerMagic* m = &p->magic;

  if (gFlag030047a4 & FLAG030047A4_UNK_12) {
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
  m->enchanted = u16_03002bb0;
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
    p->playerIdx = VM_GetValue();
  } else {
    p->playerIdx = 0;
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

  p->unk_1c = 1;

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

  if (gFlag030047a4 & FLAG030047A4_UNK_12) {
    s32 i;

    for (i = 0; i < 3; i++) {
      u16_ARRAY_03002ba0[i] = 0;
    }
    p->updateCallback = FUN_08079f1c;
  } else {
    p->updateCallback = sPlayerUpdates[p->kind];
  }

  Player_SetAction(p, 0, 0);
  p->input = &gInput[p->playerIdx];
  Player_ClearInputHistory(p);

  if (p->playerIdx == 0) {
    s32 i;

    p->goodCondID = gGoodCondID;
    p->unk_444 = u16_03002b7c;
    p->goodCondTimer = gGoodCondTimer;
    for (i = 0; i < 3; i++) {
      p->badCondTimer[i] = u16_ARRAY_03002ba0[i];
    }
  } else {
    s32 i;

    p->goodCondID = 0;
    p->unk_444 = 0;
    p->goodCondTimer = 0;
    for (i = 0; i < 3; i++) {
      p->badCondTimer[i] = 0;
    }
  }

  p->controlUp = gStat->controlUp;
  if (p->badCondTimer[2] != 0) {
    p->controlUp = gConfusedDir;
  }
  return 0;
}

void Player_InitSprite(Player* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_DJANGO_SABATA);

  if (f != NULL) {
    p->spriteSet_68 = *(MainSpriteGfx*)f;
    OpenMainSpriteFile(&p->spriteSet_68, f);
    MainSprite_Add(&p->sprite_88, &p->spriteSet_68, 0, SPRFLAG_UNK_15 | SPRFLAG_GAMEOVER, 2, 0, 60, &p->mover.pos);

    if (VM_SeekToNamedArg('d')) {
      p->facing = VM_GetValue();
    } else {
      p->facing = FACE_UP;
    }

    if (p->facing > 4) {
      p->animIDOffset = 8 - p->facing;
      p->xflip = TRUE;
    } else {
      p->animIDOffset = p->facing;
      p->xflip = FALSE;
    }

    p->animID = 0;
    MainSprite_SetAnim(&p->sprite_88, &p->spriteSet_68, p->animIDOffset, 1, 0);
    if (p->xflip) {
      p->sprite_88.flags |= SPRFLAG_XFLIP;
    } else {
      p->sprite_88.flags &= ~SPRFLAG_XFLIP;
    }
  }
}

NAKED void FUN_08065514(Player* p) { INCFUNC("asm/func/FUN_08065514.inc"); }

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
    if (p->playerIdx == 0) {
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

  halfSize.x = 50, halfSize.y = 127, halfSize.z = 50;
  offset.x = 0, offset.y = 127, offset.z = 0;
  Hitbox_Init(hurtbox, p->mover.id, HBFLAG_HURTBOX | HBFLAG_UNK_12 | HBFLAG_UNK_0, 0, 1 << p->playerIdx, &halfSize, &offset);
  if (p->kind == PLAYER_SOLAR_DJANGO) {
    Hitbox_SetPowerAndAttributes(hurtbox, 20, HBATTR_SOL, HBATTR_DARK);
  } else {
    Hitbox_SetPowerAndAttributes(hurtbox, 20, HBATTR_DARK, HBATTR_SOL);
  }
  Hitbox_SetHandler(hurtbox, Django_OnHurt, p);
  Hitbox_SetPos(hurtbox, &p->sprite_e8.pos, 0);
  Hitbox_Register(hurtbox);
}

// 生きている溶岩タイルか, 氷結 (SF934_LAVA_FROZEN) も SF934_UNK_3 もかかっていない TATTR_LAVA
// 残差5命令, 原典は gStat->unk_934 の判定を 0/1 に起こしてからもう一度判定する二段形
// bool32 を返す static inline を挟んでも && で繋いでも agbcc は内側の 0/1 を分岐に畳む, LinkShopManager_IsBusy と同じ形
NON_MATCH bool32 Player_IsLiveLava(u32 attr) {
#ifdef NONMATCHING_C
  if (attr & TATTR_LAVA) {
    if ((gStat->unk_934 & (SF934_LAVA_FROZEN | SF934_UNK_3)) == 0) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Player_IsLiveLava.inc");
#endif
}

// 氷結した溶岩タイルか, 読み手は氷タイル (TATTR_ICE) と同じ扱いをする
// 残差5命令, 原典は gStat->unk_934 の判定を 0/1 に起こしてからもう一度判定する二段形
// bool32 を返す static inline を挟んでも && で繋いでも agbcc は内側の 0/1 を分岐に畳む, LinkShopManager_IsBusy と同じ形
NON_MATCH bool32 Player_IsFrozenLava(u32 attr) {
#ifdef NONMATCHING_C
  if (attr & TATTR_LAVA) {
    if (gStat->unk_934 & SF934_LAVA_FROZEN) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Player_IsFrozenLava.inc");
#endif
}

// 残差5命令, 原典は gStat->unk_934 の判定を 0/1 に起こしてからもう一度判定する二段形
// bool32 を返す static inline を挟んでも && で繋いでも agbcc は内側の 0/1 を分岐に畳む, LinkShopManager_IsBusy と同じ形
NON_MATCH bool32 FUN_08065b08(u32 attr) {
#ifdef NONMATCHING_C
  if (attr & TATTR_LAVA) {
    if (gStat->unk_934 & SF934_UNK_13) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_08065b08.inc");
#endif
}

// 残差5命令, 原典は gStat->unk_934 の判定を 0/1 に起こしてからもう一度判定する二段形
// bool32 を返す static inline を挟んでも && で繋いでも agbcc は内側の 0/1 を分岐に畳む, LinkShopManager_IsBusy と同じ形
NON_MATCH bool32 FUN_08065b44(u32 attr) {
#ifdef NONMATCHING_C
  if (attr & TATTR_LAVA) {
    if (gStat->unk_934 & SF934_UNK_3) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_08065b44.inc");
#endif
}

NAKED void FUN_08065b7c(Player* p) { INCFUNC("asm/func/FUN_08065b7c.inc"); }

NAKED s32 FUN_08065cb8(Player* p) { INCFUNC("asm/func/FUN_08065cb8.inc"); }

// 今踏んでいるタイルの中心座標を pos_39c に入れて ptr_398 から参照させる
void FUN_08065dac(Player* p) {
  if (Entity1DBE_TouchElemNear(&p->mover.pos) && p->unk_397 == 0) {
    s32 bx = Mod(p->tile.tileIdx[0], gCollisionMap->tiledata->width);
    s32 bz = Div(p->tile.tileIdx[0], gCollisionMap->tiledata->width);

    p->pos_39c.x = (bx << 8) + 128;
    p->pos_39c.z = (bz << 8) + 128;
    p->ptr_398 = &p->pos_39c;
    p->unk_396 = 1;
  }
}

NAKED s32 FUN_08065e24(Player* p) { INCFUNC("asm/func/FUN_08065e24.inc"); }

NAKED bool32 FUN_08065f34(Player* p, Vec3* pos) { INCFUNC("asm/func/FUN_08065f34.inc"); }

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

// 残差14命令 (33対47), 原典は unk_934 の判定2箇所を 0/1 に起こしてから改めて test する
// player_link.c の4件と player_sabata.c の FUN_08081240 と同じ詰まり方で, != 0 / bool32 の static inline / if-else による明示はいずれも畳まれる
NON_MATCH bool32 Player_IsInRain(Player* p) {
#ifdef NONMATCHING_C
  return (gStat->unk_934 & SF934_RAIN) && p->armor.id != ARMOR_RAIN_COAT && ((gStat->unk_934 & SF934_OUTDOOR) || FUN_0809df78(&p->mover.pos));
#else
  INCFUNC("asm/func/Player_IsInRain.inc");
#endif
}

NAKED void FUN_0806687c(Player* p) { INCFUNC("asm/func/FUN_0806687c.inc"); }

NAKED void FUN_0806692c(Player* p) { INCFUNC("asm/func/FUN_0806692c.inc"); }

NAKED void FUN_08066a04(Player* p) { INCFUNC("asm/func/FUN_08066a04.inc"); }

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
    FUN_08066a04(p);
  }

  if ((s16)p->facingHistory[0] != -1) {
    s32 angle = (((s16)p->facingHistory[0] + 1) & 7) * 32;

    p->lookAroundOffset.x -= COS(angle, 30);
    p->lookAroundOffset.z -= SIN(angle, 30);
    p->unk_3d0 = 0;
    FUN_08066a04(p);
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
// この C はこの関数自体は原典とバイト単位で一致するが, 同じ TU の FUN_0807a270 のレジスタ割当とプール順が動いて ROM が合わなくなる
// (FUN_0807a270 は7個のグローバルのアドレスを r5-r7/ip/r8/r9/sl に先出しする関数で, C が1本増えるだけで r5 の行き先が1番目から7番目にずれる)
// 書き方を変えても (ローカル追加, FUN_0807a270 側の i の分割) 差分は同じ38バイトのままで, こちらからは動かせない
// この C はこの関数自体は原典とバイト単位で一致するが, 同じ TU の FUN_0807a270 のレジスタ割当とプール順が動いて ROM が合わなくなる
// (FUN_0807a270 は7個のグローバルのアドレスを r5-r7/ip/r8/r9/sl に先出しする関数で, C が1本増えるだけで r5 の行き先が1番目から7番目にずれる)
// 書き方を変えても (ローカル追加, FUN_0807a270 側の i の分割) 差分は同じ38バイトのままで, こちらからは動かせない
NON_MATCH void Player_StartLookAround(Player* p) {
#ifdef NONMATCHING_C
  if (p->lookAroundOffset.val == 0) {
    s32 angle = ((p->actionDir + 1) & 7) * 32;

    p->lookAroundOffset.x = -COS(angle, 800);
    p->lookAroundOffset.y = 0;
    p->lookAroundOffset.z = -SIN(angle, 800);
    p->lookAroundOffset.val = 1;
  }
#else
  INCFUNC("asm/func/Player_StartLookAround.inc");
#endif
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
    if ((p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) && p->action == 4) {
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

// 呼び出し元は3つとも r0 に Player を載せるが, この関数自体は使っていない
void FUN_08066e84(Player* p) {
  u16 payload = 6;

  FUN_080ec79c(0x11, &payload);
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

u32 FUN_08066ee4(s32 playerKind, s32 idx) {
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
  if (p->action != 0) {
    Player_SetAction(p, 0, 0);
    p->facing = FUN_08066f18(p);
    Player_SetAnimFacing(p);
  }
  p->flag20 &= ~PFLAG20_UNK_0;
  Player_PlayAnim(p, FUN_08066ee4(p->kind, 0), 0x40);
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

  if (p->unk_4c4.kind == 2 && p->unk_4c4.unk_3 != 0) {
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
  p->action = 1;
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
      val = val * p->sprite_88.scaleX >> 6;
    }
    Player_SetMoveDelta(p, val);
  }
  FUN_080670fc(p, 0);
  Player_SetAnimFacing(p);
  Player_PlayAnim(p, FUN_08066ee4(p->kind, 1), FRACUNIT_6);
}

// 魔法"ダッシュ" 前方に高速で移動する魔法 (太陽ゲージの量に応じて移動速度が変化)
// この関数自体は命令列もプール定数も原典と一致 (160/160), ROM が合わないのは Player_StartLookAround と同じ巻き添えで, 同じ TU の FUN_0807a270 のレジスタ割当とプール順が動く38バイト
// 両方の C を同時に有効にすると差分は27バイトに変わるだけで打ち消さない
NON_MATCH void MagicDash_Update(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != 2) {
    if (Player_HasEnoughSunGauge(p, 1)) {
      PlaySound_082406e0(SONG_914);
      p->dashSpeed = gStat->sunGauge * 2 + 14;
      if (p->dashSpeed > 32) {
        p->dashSpeed = 32;
      }
      p->dashFrames = Div(512, p->dashSpeed);
      Player_SetAction(p, 2, 0);
    } else {
      PlaySound_082406e0(SE_NG);
      Player_SetAction(p, 2, 1);
    }
  }

  switch (p->state) {
    case 0: {
      p->stateTimer++;
      if (p->stateTimer >= p->dashFrames) {
        Player_SetAction(p, 0, 0);
      } else {
        if (p->stateTimer < p->dashFrames - 8) {
          p->plttID_95e = 293;
          p->unk_960 = 0x20;
        }
        if ((s16)p->facingHistory[0] != -1 && p->lookAroundOffset.val == 0) {
          p->facing = FUN_08067068(p);
        }
        Player_SetMoveDelta(p, p->dashSpeed);
        FUN_080670fc(p, 1);
        Player_SetAnimFacing(p);
        Player_PlayAnim(p, FUN_08066ee4(p->kind, 1), 0x20);
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, FUN_08066ee4(p->kind, 0), 0x40);
      p->stateTimer++;
      if (p->stateTimer > 7) {
        Player_SetAction(p, 0, 0);
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/MagicDash_Update.inc");
#endif
}

// 残差1命令 (23対22), 原典は pos & 0xFF の結果をマスク側のレジスタに入れるが (ands r0, r1), こちらは pos 側に入れて r0 へ写すので adds r0, r1, #0 が1本増える
// Tier A-C は試済 (条件の向きを反転, ofs を消して (pos & 0xFF) を2回書く (lsls/lsrs が増えて25命令), ofs を内側のブロックで宣言する). Player_UpdateLookAround と同じマスク側destinationの詰まり
NON_MATCH bool32 Player_IsNearTileCenter(Player* p) {
#ifdef NONMATCHING_C
  u16 pos;
  u32 ofs;

  if (p->actionDir == 1 || p->actionDir == 5) {
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

NAKED void FUN_08067510(Player* p) { INCFUNC("asm/func/FUN_08067510.inc"); }

NAKED void FUN_08067de8(Player* p) { INCFUNC("asm/func/FUN_08067de8.inc"); }

bool32 FUN_08067f58(Player* p) {
  if (Player_TestFlag20(p, PFLAG20_SUNBATHING) && p->ene < p->maxEne) {
    return TRUE;
  }
  return FALSE;
}

void FUN_08067f88(Player* p) {
  p->pos_930 = p->mover.pos;
  if (p->facing == FACE_DOWN) {
    p->pos_930.x -= 20;
    p->pos_930.y += 330;
    p->pos_930.z += 60;
  } else {
    p->pos_930.x += 20;
    p->pos_930.y += 330;
    p->pos_930.z -= 30;
  }
}

NAKED void FUN_08067ffc(Player* p) { INCFUNC("asm/func/FUN_08067ffc.inc"); }

bool32 FUN_080682dc(Player* p) {
  if (!Player_TestFlag20(p, PFLAG20_SUNBATHING) && p->ene < p->maxEne) {
    return TRUE;
  }
  return FALSE;
}

NAKED void FUN_0806830c(Player* p) { INCFUNC("asm/func/FUN_0806830c.inc"); }

NAKED void FUN_08068624(Player* p) { INCFUNC("asm/func/FUN_08068624.inc"); }

NAKED void MagicRisingSun_08068944(Player* p) { INCFUNC("asm/func/MagicRisingSun_08068944.inc"); }

// gCoffin を動かしている間の移動速度, CalcMoveSpeed にチカラを足して gCoffin の重さ分を引いたもの
s32 FUN_08068c6c(Player* p) {
  u16 n = p->goodCondTimer;
  bool32 heaviest = FALSE;
  s32 val;

  if (n != 0 && p->goodCondID == GOOD_POWER) {
    heaviest = TRUE;
  }

  if (heaviest) {
    val = 16;
  } else {
    s32 agility = p->stats[STAT_AGILITY];
    s32 over = p->armor.weight - 100;

    val = Div((agility - over + p->stats[STAT_STRENGTH] - gCoffin->weight) * 12, 100);
    if (val > 16) {
      val = 16;
    } else if (val < 6) {
      val = 6;
    }
  }

  if (p->unk_4c4.kind == 2 && p->unk_4c4.unk_3 != 0) {
    val -= 3;
  }
  if (p->speedPenalty != 0) {
    val -= p->speedPenalty;
  }
  if (val < 2) {
    val = 2;
  }
  return val;
}

NAKED bool32 FUN_08068d18(Player* p, void* param_2) { INCFUNC("asm/func/FUN_08068d18.inc"); }

NAKED void FUN_08068e94(Player* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_08068e94.inc"); }

NAKED void FUN_08069218(Player* p) { INCFUNC("asm/func/FUN_08069218.inc"); }

void FUN_080695ec(Player* p) {
  if (p->action != 3) {
    Player_SetAction(p, 3, 0);
  }
  p->attackCB(p);
}

void FUN_0806961c(Player* p) {
  p->flag20 &= ~PFLAG20_UNK_0;
  if (p->unk_4c4.unk_3 == 0) {
    Player_SetAction(p, 0, 0);
  }
}

NAKED void FUN_08069648(Player* p) { INCFUNC("asm/func/FUN_08069648.inc"); }

// フリーズの魔法, 向いている方向の少し先に氷結エフェクトを出す
void MagicFreeze_08069710(Player* p) {
  if (p->action != 0xF) {
    if (Player_HasEnoughSunGauge(p, 0)) {
      s32 radius;

      WorldPos pos = p->mover.pos;
      s32 angle = ((p->facing + 5) & 7) * 32;
      pos.x += COS(angle, 150);
      pos.z += SIN(angle, 150);
      radius = gStat->sunGauge * 60 + 120;
      FreezeEffect_Create(&pos, 1 << p->mover.unk_4, radius, angle, 90);
      p->magicFired = TRUE;
    } else {
      p->magicFired = FALSE;
    }

    PlaySound_082406e0(VO_DJANGO_MAGIC);
    Player_SetAction(p, 15, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->magicFired) {
        p->plttID_95e = 292;
        p->unk_960 = 0x20;
      }
      if (Player_PlayAnim(p, 164, 0x40)) {
        if (p->magicFired) {
          Player_SetAction(p, 15, 1);
        } else {
          Player_SetAction(p, 15, 2);
        }
      }
      break;
    }
    case 1: {
      p->plttID_95e = 292;
      p->unk_960 = 0x20;
      Player_PlayAnim(p, 174, 0x40);
      p->stateTimer++;
      if (p->stateTimer > 31) {
        Player_SetAction(p, 15, 3);
      }
      break;
    }
    case 2: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }
      Player_PlayAnim(p, 169, 0x40);
      p->stateTimer++;
      if (p->stateTimer > 15) {
        Player_SetAction(p, 15, 3);
      }
      break;
    }
    case 3: {
      if (Player_PlayAnim(p, 164, 0x40)) {
        Player_SetAction(p, 0, 0);
      }
      break;
    }
  }
}

// ヒーリングの魔法, 向いている方向の少し先に回復の粒を出す
void MagicHealing_08069928(Player* p) {
  if (p->action != 0x10) {
    if (Player_HasEnoughSunGauge(p, 2)) {
      WorldPos pos = p->mover.pos;
      s32 angle = ((p->facing + 5) & 7) * 32;
      pos.x += COS(angle, 150);
      pos.z += SIN(angle, 150);
      HealingParticles_Create(p, &pos);
      p->magicFired = TRUE;
    } else {
      p->magicFired = FALSE;
    }

    PlaySound_082406e0(VO_DJANGO_MAGIC);
    Player_SetAction(p, 16, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->magicFired) {
        p->plttID_95e = 294;
        p->unk_960 = 0x20;
      }
      if (Player_PlayAnim(p, 164, 0x40)) {
        if (p->magicFired) {
          Player_SetAction(p, 16, 1);
        } else {
          Player_SetAction(p, 16, 2);
        }
      }
      break;
    }
    case 1: {
      p->plttID_95e = 294;
      p->unk_960 = 0x20;
      Player_PlayAnim(p, 174, 0x40);
      p->stateTimer++;
      if (p->stateTimer > 31) {
        Player_SetAction(p, 16, 3);
      }
      break;
    }
    case 2: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }
      Player_PlayAnim(p, 169, 0x40);
      p->stateTimer++;
      if (p->stateTimer > 15) {
        Player_SetAction(p, 16, 3);
      }
      break;
    }
    case 3: {
      if (Player_PlayAnim(p, 164, 0x40)) {
        Player_SetAction(p, 0, 0);
      }
      break;
    }
  }
}

// ダイナマイトの魔法, 太陽ゲージが足りていれば爆弾を1個出し, 以降は発動したかどうかで演出を振り分ける
void MagicDynamite_08069b18(Player* p) {
  if (p->action != 0x11) {
    if (p->unk_390 != 0) {
      p->magicFired = FALSE;
    } else if (Player_HasEnoughSunGauge(p, 3)) {
      p->magicFired = TRUE;
      Entity080a8ff8_Create(p, &p->mover.pos, 0);
    } else {
      p->magicFired = FALSE;
    }
    Player_SetAction(p, 17, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->magicFired) {
        p->plttID_95e = 291;
        p->unk_960 = 0x20;
      }
      if (Player_PlayAnim(p, 184, 0x40)) {
        if (p->magicFired) {
          Player_SetAction(p, 17, 1);
        } else {
          Player_SetAction(p, 17, 2);
        }
      }
      break;
    }
    case 1: {
      if (p->magicFired) {
        p->plttID_95e = 291;
        p->unk_960 = 0x20;
      }
      p->stateTimer++;
      if (p->stateTimer > 11) {
        Player_SetAction(p, 17, 3);
      }
      break;
    }
    case 2: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }
      Player_PlayAnim(p, 194, 0x40);
      p->stateTimer++;
      if (p->stateTimer > 11) {
        Player_SetAction(p, 17, 3);
      }
      break;
    }
    case 3: {
      if (Player_PlayAnim(p, 189, 0x40)) {
        Player_SetAction(p, 0, 1);
      }
      break;
    }
  }
}

NAKED void FUN_08069c8c(Player* p) { INCFUNC("asm/func/FUN_08069c8c.inc"); }

NAKED void FUN_08069d70(Player* p) { INCFUNC("asm/func/FUN_08069d70.inc"); }

NAKED void FUN_08069f60(Player* p) { INCFUNC("asm/func/FUN_08069f60.inc"); }

void FUN_0806a050(Player* p) {
  if (p->unk_3fe != 0) {
    Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW | PFLAG35A_NO_HITBOX | PFLAG35A_NO_TILE);
  } else {
    Player_SetFlag35a(p, PFLAG35A_HIDE_SPRITE | PFLAG35A_HIDE_SHADOW | PFLAG35A_NO_HITBOX | PFLAG35A_NO_TILE);
  }
  Player_SetFlag20(p, PFLAG20_UNK_12 | PFLAG20_UNK_8);
}

NAKED void FUN_0806a084(Player* p) { INCFUNC("asm/func/FUN_0806a084.inc"); }

NAKED void FUN_0806a32c(Player* p) { INCFUNC("asm/func/FUN_0806a32c.inc"); }

NAKED void FUN_0806a628(Player* p) { INCFUNC("asm/func/FUN_0806a628.inc"); }

NAKED void FUN_0806a88c(Player* p) { INCFUNC("asm/func/FUN_0806a88c.inc"); }

NAKED void FUN_0806abd4(Player* p) { INCFUNC("asm/func/FUN_0806abd4.inc"); }

NAKED void FUN_0806adc8(Player* p) { INCFUNC("asm/func/FUN_0806adc8.inc"); }

NAKED void FUN_0806af70(Player* p) { INCFUNC("asm/func/FUN_0806af70.inc"); }

NAKED void FUN_0806b06c(Player* p) { INCFUNC("asm/func/FUN_0806b06c.inc"); }

NAKED void FUN_0806b374(Player* p) { INCFUNC("asm/func/FUN_0806b374.inc"); }

// サバタの魔法ブラックサン, 真上か真下を向いて暗黒の柱を出す
void Sabata_BlackSun(Player* p) {
  if (p->action != 9) {
    p->unk_951 = 0;
    if (Player_HasEnoughEne(p, 100) && u16_03002bd0 == 0) {
      p->magicFired = TRUE;
    } else {
      p->magicFired = FALSE;
    }
    Player_SetAction(p, 9, 0);
  }

  switch (p->state) {
    case 0: {
      if (p->facing >= FACE_RIGHT && p->facing <= FACE_LEFT) {
        p->facing = FACE_DOWN;
        p->animIDOffset = 4;
        p->xflip = FALSE;
        p->pos_930 = p->mover.pos;
        p->pos_930.x -= 20;
        p->pos_930.y += 330;
        p->pos_930.z += 60;
      } else {
        p->facing = FACE_UP;
        p->animIDOffset = 0;
        p->xflip = FALSE;
        p->pos_930 = p->mover.pos;
        p->pos_930.x += 20;
        p->pos_930.y += 330;
        p->pos_930.z -= 20;
      }

      Player_PlayAnim(p, FUN_08066ee4(p->kind, 0), 0x40);
      if (p->facing == FACE_DOWN) {
        p->animIDOffset = 1;
      } else {
        p->animIDOffset = 0;
      }

      if (p->magicFired) {
        PlaySound_082406e0(VO_SABATA_ANKOKU);
        p->plttID_95e = 290;
        p->unk_960 = 2;
        Entity080abd14_Create(p, &p->mover.pos, &p->pos_930, 1, p->unk_3ba);
      }

      Player_SetAction(p, 9, 1);
      break;
    }
    case 1: {
      if (p->magicFired) {
        p->plttID_95e = 290;
        p->unk_960 += 3;
        if (p->unk_960 > 32) {
          p->unk_960 = 32;
        }
      }

      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, FUN_08066ee4(p->kind, 8), 0x40)) {
        PlaySound_082406e0(SONG_203);
        if (p->magicFired && p->unk_3ba == 0) {
          u16_03002bd0 = 1;
        }
        Player_SetAction(p, 9, 2);
      }
      break;
    }
    case 2: {
      if (p->magicFired) {
        p->plttID_95e = 290;
        p->unk_960 += 3;
        if (p->unk_960 > 32) {
          p->unk_960 = 32;
        }
      } else if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }

      Player_PlayAnim(p, FUN_08066ee4(p->kind, 10), 0x40);
      p->shadowOffset.z = 30;
      p->stateTimer++;
      if (p->stateTimer > 23) {
        Player_SetAction(p, 9, 3);
      }
      break;
    }
    case 3: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, FUN_08066ee4(p->kind, 11), 0x40)) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, 0, 0);
      }
      break;
    }
  }
}

NAKED void FUN_0806b758(Player* p) { INCFUNC("asm/func/FUN_0806b758.inc"); }

// 魔法トランス, 赤ジャンゴと黒ジャンゴを入れ替える
// 残差2命令 (331/333): case 2 の stateTimer の16bit化だけ, 原典は 0xFFFF をレジスタに置いて ands で切るが agbcc は lsls/lsrs を選ぶ
// ands になるのは u32 の中間変数に受けて & 0xFFFF と書いたときだけ (単体で確認), 不自然なので採らない
// stateTimer++ / u16 の中間変数 / (u16) キャスト / > 31 と < 32 の反転はいずれも lsls/lsrs, clamp を static inline にしても変わらない
// Tier A-C 試済, 未: per-TU フラグ
NON_MATCH void MagicTransform_0806b92c(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != 10) {
    if (Player_HasEnoughEne(p, 0)) {
      p->plttID_95e = 295;
      p->unk_960 = 0;
      p->magicFired = TRUE;
    } else {
      p->magicFired = FALSE;
    }
    PlaySound_082406e0(VO_DJANGO_MAGIC);
    Player_SetAction(p, 10, 0);
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

      Player_PlayAnim(p, FUN_08066ee4(p->kind, 0), 0x40);
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

      Player_SetAction(p, 10, 1);
      break;
    }
    case 1: {
      if (p->magicFired) {
        p->unk_960 += 3;
        if (p->unk_960 > 32) {
          p->unk_960 = 32;
        }
      }

      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, FUN_08066ee4(p->kind, 8), 0x40)) {
        if (p->magicFired) {
          Player_SetAction(p, 10, 2);
        } else {
          Player_SetAction(p, 10, 3);
        }
      }
      break;
    }
    case 2: {
      if ((p->stateTimer & 7) < 7 - (p->stateTimer >> 2)) {
        Player_PlayAnim(p, FUN_08066ee4(p->kind, 10), 0x40);
      } else if (p->kind == PLAYER_SOLAR_DJANGO) {
        Player_PlayAnim(p, FUN_08066ee4(PLAYER_DARK_DJANGO, 10), 0x40);
      } else {
        Player_PlayAnim(p, FUN_08066ee4(PLAYER_SOLAR_DJANGO, 10), 0x40);
      }

      p->unk_960 += 3;
      if (p->unk_960 > 32) {
        p->unk_960 = 32;
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
        if (p->unk_444 != 5 && p->unk_444 != 0x22) {
          p->goodCondTimer = 0;
        }

        Player_SetAction(p, 10, 4);
      }
      break;
    }
    case 3: {
      if (p->stateTimer == 0) {
        PlaySound_082406e0(SE_NG);
      }

      Player_PlayAnim(p, FUN_08066ee4(p->kind, 10), 0x40);
      p->shadowOffset.z = 30;
      p->stateTimer++;
      if (p->stateTimer > 15) {
        Player_SetAction(p, 10, 4);
      }
      break;
    }
    case 4: {
      p->shadowOffset.z = 15;
      if (Player_PlayAnim(p, FUN_08066ee4(p->kind, 11), 0x40)) {
        Player_SetAnimFacing(p);
        Player_SetAction(p, 0, 0);
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/MagicTransform_0806b92c.inc");
#endif
}

// 魔法チェンジ・バット, 本体を隠して sprite_e8 のコウモリを点滅させながら出し, 31フレームでバットのフォームへ切り替える
// 残差1命令 (293/294): 反転判定の定数をレジスタに作って両辺で使い回す形, MagicChangeMouse / MagicSleeping_Update / PlayerShockwave_UpdateAnim / MapItem_AdvanceAnim / Entity08203ad0_Update と同じ既知の残差
// 点滅判定は & 7 と >> 2 が原典どおり (% 8 だとマスクを持つレジスタの向きが逆になり, / 4 だと stateTimer を2回読む), Tier A-C 試済
NON_MATCH void MagicChangeBat_0806bc74(Player* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  AuxSprite* spr;

  if (p->action != 12) {
    Player_SetAction(p, 12, 0);
    p->unk_960 = 0;
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
    Player_SetFlag35a(p, PFLAG35A_HIDE_SPRITE | PFLAG35A_SHOW_SPRITE_E8);
    p->sprite_e8.pos = p->mover.pos;
    p->sprite_e8.pos.y += p->unk_382;

    if (p->facing >= FACE_DOWN) {
      p->animIDOffset = (7 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animIDOffset = p->facing >> 1;
      p->xflip = FALSE;
    }
  }

  Player_PlayAnim(p, FUN_08066ee4(p->kind, 0), 0x40);
  p->plttID_95e = 290;
  p->unk_960 += 3;
  if (p->unk_960 > 32) {
    p->unk_960 = 32;
  }

  anim = &p->anim_33c;
  AuxAnim_SetAnim(anim, p->anim_34c, 0, p->animIDOffset, p->xflip);

  spr = &p->sprite_e8;
  cmd = &anim->cmds[anim->cmdIdx];
  spr->poseIdx = *cmd >> 6;

  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    spr->flags |= SPRFLAG_XFLIP;
  } else {
    spr->flags &= ~SPRFLAG_XFLIP;
  }

  if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    spr->flags |= SPRFLAG_YFLIP;
  } else {
    spr->flags &= ~SPRFLAG_YFLIP;
  }

  anim->tick++;
  if (anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      s32 idx = anim->cmdIdx;

      if (idx == 0) {
        idx = anim->cmdCount;
      }
      anim->cmdIdx = idx - 1;
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
      }
    }

    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = anim->duration * anim->speed >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }

  Video_SetAuxSpritePltt(p->gfx_114, 621);
  p->stateTimer++;
  if (p->stateTimer > 31) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_BAT;
    Player_SetAction(p, 0, 0);
  }
#else
  INCFUNC("asm/func/MagicChangeBat_0806bc74.inc");
#endif
}

// 魔法チェンジ・マウス, 点滅が消えている間だけ本体を隠して sprite_e8 のネズミを出し, 31フレームでマウスのフォームへ切り替える
// 残差1命令 (234/235): 反転判定の定数をレジスタに作って両辺で使い回す形, MagicSleeping_Update / PlayerShockwave_UpdateAnim / MapItem_AdvanceAnim / Entity08203ad0_Update と同じ既知の残差
// 点滅判定は & 7 と >> 2 が原典どおり (% 8 だとマスクを持つレジスタの向きが逆になり, / 4 だと stateTimer を2回読む), Tier A-C 試済
NON_MATCH void MagicChangeMouse_0806bf18(Player* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  AuxSprite* spr;

  if (p->action != 13) {
    Player_SetAction(p, 13, 0);
    p->unk_960 = 0;
    FUN_08063220(p);
    FUN_08066e84(p);
    PlaySound_082406e0(SONG_922);
    TransEffect_Create(p, 1, NULL, 32, 56);
  }

  if (p->stateTimer == 16) {
    PlaySound_082406e0(SE_CHANGE_MOUSE);
  }

  if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 2)) {
    Player_SetFlag35a(p, PFLAG35A_HIDE_SPRITE | PFLAG35A_SHOW_SPRITE_E8);
    p->sprite_e8.pos = p->mover.pos;
  }

  Player_PlayAnim(p, FUN_08066ee4(p->kind, 0), 0x40);
  p->plttID_95e = 290;
  p->unk_960 += 3;
  if (p->unk_960 > 32) {
    p->unk_960 = 32;
  }

  anim = &p->anim_33c;
  AuxAnim_SetAnim(anim, p->anim_350, 0, p->animIDOffset, p->xflip);

  spr = &p->sprite_e8;
  cmd = &anim->cmds[anim->cmdIdx];
  spr->poseIdx = *cmd >> 6;

  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    spr->flags |= SPRFLAG_XFLIP;
  } else {
    spr->flags &= ~SPRFLAG_XFLIP;
  }

  if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    spr->flags |= SPRFLAG_YFLIP;
  } else {
    spr->flags &= ~SPRFLAG_YFLIP;
  }

  anim->tick++;
  if (anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      s32 idx = anim->cmdIdx;

      if (idx == 0) {
        idx = anim->cmdCount;
      }
      anim->cmdIdx = idx - 1;
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
      }
    }

    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = anim->duration * anim->speed >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }

  Video_SetAuxSpritePltt(p->gfx_114, 290);
  p->stateTimer++;
  if (p->stateTimer > 31) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_MOUSE;
    Player_SetAction(p, 0, 0);
  }
#else
  INCFUNC("asm/func/MagicChangeMouse_0806bf18.inc");
#endif
}

// 魔法スリーピング, 棺桶の絵を sprite_e8 に出して8フレームでスリーピングのフォームへ切り替える
// 残差1命令 (195/196): 反転判定の定数をレジスタに作って両辺で使い回す形, MagicChangeBat / MagicChangeMouse / MagicSleeping_Update / PlayerShockwave_UpdateAnim / MapItem_AdvanceAnim / Entity08203ad0_Update と同じ既知の残差
// AuxAnimPlayFlags を返す static inline を挟むとコマ側の抽出が CSE されて 193/196 と逆に遠のく, Tier A-C 試済
NON_MATCH void MagicSleeping_0806c124(Player* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  AuxSprite* spr;

  if (p->action != 14) {
    p->coffin = GetPlayerCoffinID();
    FUN_08063220(p);
    FUN_08066e84(p);
    Player_SetAction(p, 14, 0);
  }

  Player_PlayAnim(p, FUN_08066ee4(p->kind, 0), 0x40);
  Player_SetFlag35a(p, PFLAG35A_SHOW_SPRITE_E8);
  p->sprite_e8.pos = p->mover.pos;

  anim = &p->anim_33c;
  AuxAnim_SetAnim(anim, p->anim_354, p->coffin + 24, 0, 0);

  spr = &p->sprite_e8;
  cmd = &anim->cmds[anim->cmdIdx];
  spr->poseIdx = *cmd >> 6;

  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    spr->flags |= SPRFLAG_XFLIP;
  } else {
    spr->flags &= ~SPRFLAG_XFLIP;
  }

  if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    spr->flags |= SPRFLAG_YFLIP;
  } else {
    spr->flags &= ~SPRFLAG_YFLIP;
  }

  anim->tick++;
  if (anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      s32 idx = anim->cmdIdx;

      if (idx == 0) {
        idx = anim->cmdCount;
      }
      anim->cmdIdx = idx - 1;
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
      }
    }

    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = anim->duration * anim->speed >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }

  Video_SetAuxSpritePltt(p->gfx_114, p->coffin + 519);
  p->stateTimer++;
  if (p->stateTimer > 7) {
    p->formRequest = TRUE;
    p->formRequestKind = PLAYER_SLEEPING;
    Player_SetAction(p, 4, 0);
  }
#else
  INCFUNC("asm/func/MagicSleeping_0806c124.inc");
#endif
}

NAKED void FUN_0806c2dc(Player* p) { INCFUNC("asm/func/FUN_0806c2dc.inc"); }

NAKED void FUN_0806c400(Player* p) { INCFUNC("asm/func/FUN_0806c400.inc"); }

NAKED void FUN_0806c6d4(Player* p) { INCFUNC("asm/func/FUN_0806c6d4.inc"); }

NAKED void FUN_0806c868(Player* p) { INCFUNC("asm/func/FUN_0806c868.inc"); }

NAKED void FUN_0806c9bc(Player* p) { INCFUNC("asm/func/FUN_0806c9bc.inc"); }

NAKED void FUN_0806cbe8(Player* p) { INCFUNC("asm/func/FUN_0806cbe8.inc"); }

NAKED void FUN_0806ceb0(Player* p) { INCFUNC("asm/func/FUN_0806ceb0.inc"); }

s32 FUN_0806cfd4(Player* p) {
  s32 n = 12;

  if (p->unk_4c4.kind == 2 && p->unk_4c4.unk_3 != 0) {
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

NAKED void FUN_0806d014(Player* p) { INCFUNC("asm/func/FUN_0806d014.inc"); }

NAKED void FUN_0806d22c(Player* p) { INCFUNC("asm/func/FUN_0806d22c.inc"); }

NAKED void FUN_0806d420(Player* p) { INCFUNC("asm/func/FUN_0806d420.inc"); }

NAKED void FUN_0806d5b0(Player* p) { INCFUNC("asm/func/FUN_0806d5b0.inc"); }

NAKED void FUN_0806d74c(Player* p) { INCFUNC("asm/func/FUN_0806d74c.inc"); }

NAKED void FUN_0806da18(Player* p) { INCFUNC("asm/func/FUN_0806da18.inc"); }

NAKED void FUN_0806dd7c(Player* p) { INCFUNC("asm/func/FUN_0806dd7c.inc"); }

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
// 残差2命令 (211/213): 原典は反転判定の定数を1つのレジスタに作って両辺で使い回し, u16 の切り詰めも `& 0xFFFF` の定数で書くが, こちらは定数を都度作り lsls/lsrs で切り詰める, Tier A-C は試済
// コマ側を AuxAnimPlayFlags に型付けする static inline を挟むと定数の使い回しと ldrh の幅は再現できる (209/213) が一致しないので残していない, 同じ AuxAnim 手動送りを持つ PlayerShockwave_UpdateAnim / MapItem_AdvanceAnim / Entity08203ad0_Update も同じ残差で止まっている
NON_MATCH void MagicSleeping_Update(Player* p) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;
  AuxSprite* spr;

  if (p->action != 0) {
    Player_SetAction(p, 0, 0);
  }

  p->flag20 &= ~PFLAG20_UNK_0;
  if (p->coffin == COFFIN_SILVER) {
    p->flag20 |= PFLAG20_UNK_17;
  }

  anim = &p->anim_33c;
  AuxAnim_SetAnim(anim, p->anim_354, p->coffin, p->animIDOffset, p->xflip);

  spr = &p->sprite_e8;
  cmd = &anim->cmds[anim->cmdIdx];
  spr->poseIdx = *cmd >> 6;

  if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    spr->flags |= SPRFLAG_XFLIP;
  } else {
    spr->flags &= ~SPRFLAG_XFLIP;
  }

  if ((u8)(anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    spr->flags |= SPRFLAG_YFLIP;
  } else {
    spr->flags &= ~SPRFLAG_YFLIP;
  }

  anim->tick++;
  if (anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      s32 idx = anim->cmdIdx;

      if (idx == 0) {
        idx = anim->cmdCount;
      }
      anim->cmdIdx = idx - 1;
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = 0;
      }
    }

    cmd = &anim->cmds[anim->cmdIdx];
    anim->duration = *cmd & 0xF;
    anim->wait = anim->duration * anim->speed >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }

  if (p->ene >= p->maxEne) {
    return;
  }

  p->eneAccum += u8_ARRAY_085abc82[p->coffin];
  if (p->eneAccum > 0x7F) {
    p->ene++;
    p->eneAccum -= 0x80;
  }

  p->stateTimer++;
  if (p->stateTimer > 0x45) {
    p->emoteKind = EMOTE_2;
    p->emote = Emote_Show(p->emote, &p->mover, EMOTE_2, 0, 0, 0, 0x80, 0);
    p->stateTimer = 0;
  }
#else
  INCFUNC("asm/func/MagicSleeping_Update.inc");
#endif
}

NAKED void FUN_0806e15c(Player* p) { INCFUNC("asm/func/FUN_0806e15c.inc"); }

// 銃を撃つ, エナジーが 10 未満なら空撃ちの音だけ鳴らす
void FUN_0806e404(Player* p) {
  if (p->action != 3) {
    Player_SetAction(p, 3, 5);
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
    Player_SetAction(p, 0, 0);
  }
}

NAKED void FUN_0806e4b4(Player* p) { INCFUNC("asm/func/FUN_0806e4b4.inc"); }

NAKED void FUN_0806e674(Player* p) { INCFUNC("asm/func/FUN_0806e674.inc"); }

NAKED void FUN_0806e7dc(Player* p) { INCFUNC("asm/func/FUN_0806e7dc.inc"); }

NAKED Entity5941Node* FUN_0806ea98(Player* p) { INCFUNC("asm/func/FUN_0806ea98.inc"); }

// チェンジウルフ(Cウルフ, 敵の背後をとっているときに使用すると相手に噛みついてライフを吸収する)
// 残差1命令, p->hurtbox.unk_44 = 0 で原典は値の 0 を先に作ってからアドレスを組むが, こちらはアドレスが先なので値とアドレスのレジスタが入れ替わる
NON_MATCH void MagicChangeWolf_0806eb40(Player* p) {
#ifdef NONMATCHING_C
  if (p->action != 11) {
    u16_03002b70 = 0;
    u16_03002b88 = 0;
    u16_03002bf4 = 0;
    p->hurtbox.unk_44 = 0;
    gChangeWolfTarget = FUN_0806ea98(p);
    if (gChangeWolfTarget == NULL) {
      Player_SetAction(p, 11, 3);
    } else {
      p->plttID_95e = 290;
      p->unk_960 = 32;
      Player_SetAction(p, 11, 1);
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
        Player_PlayAnim(p, FUN_08066ee4(p->kind, 0), FRACUNIT_6);
      } else {
        Player_PlayAnim(p, 403, FRACUNIT_6);
      }

      p->stateTimer++;
      if (p->stateTimer > 55) {
        gChangeWolfTarget = FUN_0806ea98(p);
        if (gChangeWolfTarget == NULL) {
          Player_SetAction(p, 11, 3);
          break;
        }
        Player_SetAction(p, 11, 1);
      }
      break;
    }
    case 1: {
      s32 dx = gChangeWolfTarget->owner->pos.x - p->mover.pos.x;
      s32 dz = gChangeWolfTarget->owner->pos.z - p->mover.pos.z;
      s32 angle = ArcTan2_8(dx, dz);
      s32 angleDiff = (angle - gChangeWolfTarget->owner->angle + 0x100) & 0xFF;

      // 相手の背後 ±45度 に回り込めているなら
      if (angleDiff < 0x21 || angleDiff > 0xDF) {
        Player_SetFlag35a(p, PFLAG35A_NO_HITBOX);
      }

      if (dx * dx + dz * dz <= 2303) {
        bool32 bitten;
        s32 quad;

        if (gChangeWolfTarget->flags & 1) {
          gChangeWolfTarget = NULL;
          Player_SetAction(p, 11, 3);
          break;
        }

        bitten = gChangeWolfTarget->fn(gChangeWolfTarget->owner, 0, 0);
        u16_03002bf4 = 1;
        if (!bitten) {
          gChangeWolfTarget = NULL;
          Player_SetAction(p, 11, 3);
          break;
        }

        p->facing = ((((angle + 0x20) & 0xFF) >> 6) * 2 + 3) & 7;
        gChangeWolfTarget->owner->angle = ((p->facing + 5) & 7) << 5;  // 噛みつかれた側を背中合わせの向きに揃える
        quad = ((angle + 0x60) & 0xFF) >> 6;
        if (quad > 1) {
          p->animIDOffset = 3 - quad;
          p->xflip = TRUE;
        } else {
          p->animIDOffset = quad;
          p->xflip = FALSE;
        }
        Player_PlayAnim(p, 410, FRACUNIT_6);
        Player_SetAction(p, 11, 2);
      } else {
        s32 quad;

        p->mover.delta.x = COS(angle, 24);
        p->mover.delta.z = SIN(angle, 24);
        p->facing = ((((angle + 0x20) & 0xFF) >> 6) * 2 + 3) & 7;
        quad = ((angle + 0x60) & 0xFF) >> 6;
        if (quad > 1) {
          p->animIDOffset = 3 - quad;
          p->xflip = TRUE;
        } else {
          p->animIDOffset = quad;
          p->xflip = FALSE;
        }
        Player_PlayAnim(p, 408, FRACUNIT_6);
        FUN_080670fc(p, 0);
        p->stateTimer++;
        if (p->stateTimer <= 89) {
          break;
        }
        Player_SetAction(p, 11, 4);
      }
      break;
    }
    case 2: {
      bool32 done;

      if (gChangeWolfTarget->flags & 1) {
        gChangeWolfTarget = NULL;
        Player_SetAnimFacing(p);
        Player_PlayAnim(p, 403, FRACUNIT_6);
        Player_SetAction(p, 11, 4);
        break;
      }

      // Lボタンを押しておくと, 1回の変身で4回まで噛みつき直せる
      if (u16_03002b70 < 4 && Player_CheckMagicCost(p) && (p->input->pressed & L_BUTTON)) {
        u16_03002b88 = 1;
      }

      done = Player_PlayAnim(p, 410, FRACUNIT_6);
      if (p->sprite_88.animCmdIdx == 5 && p->sprite_88.animCmdTimer == 0) {
        s32 heal = (p->stats[STAT_VITALITY] + p->stats[STAT_STRENGTH]) >> 1;

        if (!gChangeWolfTarget->fn(gChangeWolfTarget->owner, 0, heal)) {
          gChangeWolfTarget = NULL;
          Player_SetAnimFacing(p);
          Player_SetAction(p, 11, 4);
          break;
        }

        {
          Vec3 v;
          s32 angle;

          PlaySound_082406e0(SONG_927);
          angle = ((p->facing + 5) & 7) * 32;
          v.x = COS(angle, 64), v.y = 230;
          v.z = SIN(angle, 64);
          FUN_080dc0b8(&p->mover.pos, &v, 0, 0, 1);
        }

        p->hp += heal;
        if (p->hp >= p->maxHP) {
          heal = p->maxHP - p->hp;
          p->hp = p->maxHP;
        }
        if (heal > 0) {
          FUN_0805fe7c(&p->hurtbox, heal, 1, &p->mover.pos, &p->pos_970, 0);
        }
        u16_03002b70++;
        break;
      }

      if (done) {
        if (u16_03002b88) {
          Player_SetAction(p, 11, 2);
        } else {
          Player_SetFlag35a(p, PFLAG35A_NO_HITBOX);
          gChangeWolfTarget->fn(gChangeWolfTarget->owner, 1, 60);
          gChangeWolfTarget = NULL;
          Player_SetAction(p, 11, 4);
        }
        u16_03002b88 = 0;
      }
      break;
    }
    case 3: {
      p->plttID_95e = 290;
      p->unk_960 = 32;
      Player_SetAnimFacing(p);
      Player_PlayAnim(p, 403, FRACUNIT_6);
      p->stateTimer++;
      if (p->stateTimer > 31) {
        Player_SetAction(p, 0, 0);
      }
      break;
    }
    case 4: {
      s32 angle;

      Player_SetFlag35a(p, PFLAG35A_NO_HITBOX);
      if (p->stateTimer == 0) {
        p->plttID_95e = 290;
        p->unk_960 = 32;
      }
      Player_SetAnimFacing(p);
      Player_PlayAnim(p, 403, FRACUNIT_6);
      angle = ((p->facing + 5) & 7) * 32;
      p->mover.delta.x = -COS(angle, 16);  // 噛みついた相手から後ろへ跳ぶ
      p->mover.delta.z = -SIN(angle, 16);
      p->floatHeight = SIN((p->stateTimer + 4) * 8, 64);
      p->stateTimer++;
      if (p->stateTimer > 11) {
        p->floatHeight = 0;
        PlaySound_082406e0(SONG_432);
        Player_SetAction(p, 11, 5);
      }
      break;
    }
    case 5: {
      if (Player_PlayAnim(p, 388, FRACUNIT_6)) {
        Player_SetAction(p, 0, 0);
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
      Player_PlayAnim(p, 403, FRACUNIT_6);
      Player_SetAction(p, 31, 1);
      break;
    }
    case 1: {
      return;
    }
    case 2: {
      if ((p->stateTimer & 7) >= 7 - (p->stateTimer >> 3)) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_SPRITE | PFLAG35A_HIDE_SHADOW);
      }
      p->stateTimer++;
      if (p->stateTimer > 55) {
        Player_SetAction(p, 31, 3);
      }
      break;
    }
    case 3: {
      Player_SetFlag35a(p, PFLAG35A_HIDE_SPRITE | PFLAG35A_HIDE_SHADOW);
      break;
    }
  }
}

NAKED void FUN_0806f284(Player* p) { INCFUNC("asm/func/FUN_0806f284.inc"); }

NAKED void MagicHealing_0806f3a0(Player* p) { INCFUNC("asm/func/MagicHealing_0806f3a0.inc"); }

NAKED void FUN_0806f5d8(Player* p) { INCFUNC("asm/func/FUN_0806f5d8.inc"); }

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
  p->enchantIdx = Player_CheckMagicEnchant(p);
  if (p->enchantIdx >= 0) {
    p->unk_951 = p->enchantIdx + 1;
  } else {
    p->unk_951 = 0;
  }
}

NAKED void* FUN_0806f7bc(Player* p) { INCFUNC("asm/func/FUN_0806f7bc.inc"); }

// 武器の特殊効果コールバックの戻り値を合計する
s32 FUN_0806f900(Player* p) {
  s32 total = (s32)FUN_0806f7bc(p);
  s32 i;

  for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
    if (p->weaponExDamageCb[i] != NULL) {
      total += p->weaponExDamageCb[i](p);
    }
  }
  if (Player_GetFlag378(p, EBUFF_BLACKARMOR)) {  // 黒の鎧
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

NAKED void dark_django_0806f990(HitboxData* a, HitboxData* b, Player* _) { INCFUNC("asm/func/dark_django_0806f990.inc"); }

NAKED void FUN_0806fad8(Player* p) { INCFUNC("asm/func/FUN_0806fad8.inc"); }

NAKED void FUN_0806fc20(Player* p, u16* param_2, u32 param_3, s32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_0806fc20.inc"); }

NAKED bool32 FUN_0806fd58(Player* p) { INCFUNC("asm/func/FUN_0806fd58.inc"); }

NAKED void FUN_0806fedc(Player* p) { INCFUNC("asm/func/FUN_0806fedc.inc"); }

// src から angle の方向へ dist だけずらした座標を dst に書く, 高さはそのまま写す
void FUN_080700a4(Vec3* dst, Vec3* src, s32 angle, s32 dist) {
  dst->x = src->x + COS(angle, dist);
  dst->y = src->y;
  dst->z = src->z + SIN(angle, dist);
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

NAKED s32 FUN_0807012c(Player* p) { INCFUNC("asm/func/FUN_0807012c.inc"); }

NAKED void FUN_080701e0(Player* p) { INCFUNC("asm/func/FUN_080701e0.inc"); }

NAKED void FUN_080704d8(Player* p, u16* param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_080704d8.inc"); }

NAKED s32 FUN_08070604(Player* p) { INCFUNC("asm/func/FUN_08070604.inc"); }

NAKED void FUN_08070844(Player* p) { INCFUNC("asm/func/FUN_08070844.inc"); }

NAKED void FUN_08070adc(Player* p) { INCFUNC("asm/func/FUN_08070adc.inc"); }

NAKED void FUN_08070c2c(Player* p) { INCFUNC("asm/func/FUN_08070c2c.inc"); }

NAKED s32 FUN_08070db4(Player* p) { INCFUNC("asm/func/FUN_08070db4.inc"); }

NAKED void FUN_0807106c(Player* p) { INCFUNC("asm/func/FUN_0807106c.inc"); }

NAKED void FUN_08071218(Player* p) { INCFUNC("asm/func/FUN_08071218.inc"); }

NAKED s32 FUN_080712d4(Player* p) { INCFUNC("asm/func/FUN_080712d4.inc"); }

NAKED void FUN_080713a8(Player* p) { INCFUNC("asm/func/FUN_080713a8.inc"); }

NAKED void gun_080715a0(Player* p) { INCFUNC("asm/func/gun_080715a0.inc"); }

NAKED void FUN_08071b14(Player* p) { INCFUNC("asm/func/FUN_08071b14.inc"); }

NAKED void FUN_08072014(Player* p) { INCFUNC("asm/func/FUN_08072014.inc"); }

void FUN_08072620(Player* p) {
  Player_SetAction(p, 0, 0);
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

void FUN_080726e0(Player* p) { Player_SetFlag35a(p, PFLAG35A_HIDE_SPRITE | PFLAG35A_HIDE_SHADOW); }

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
      Player_PlayAnim(p, FUN_08066ee4(p->kind, 0), FRACUNIT_6);
      if (p->unk_4af != 0) {
        p->unk_4af = 0;
        FUN_080726b4(p);
      }
      break;
    }
    case 2: {
      p->stateTimer++;
      if (p->stateTimer > 19) {
        Player_PlayAnim(p, FUN_08066ee4(p->kind, 0), FRACUNIT_6);
        FUN_08072620(p);
        FUN_080726b4(p);
        break;
      }
    }
    case 1: {
      Player_PlayAnim(p, FUN_08066ee4(p->kind, 47), FRACUNIT_6);
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08072724.inc");
#endif
}

NAKED void FUN_080727d4(Player* p) { INCFUNC("asm/func/FUN_080727d4.inc"); }

NAKED void FUN_080728a8(Player* p) { INCFUNC("asm/func/FUN_080728a8.inc"); }

void FUN_080729e0(Player* p) {
  if (Player_PlayAnim(p, 531, FRACUNIT_6)) {
    Player_SetAnimFacing(p);
    FUN_08072620(p);
    FUN_080726b4(p);
  }
}

void FUN_08072a0c(Player* p) {
  Player_PlayAnim(p, FUN_08066ee4(p->kind, 51), FRACUNIT_6);
  Player_SetFlag35a(p, PFLAG35A_HIDE_SHADOW);
}

NAKED void FUN_08072a38(Player* p) { INCFUNC("asm/func/FUN_08072a38.inc"); }

NAKED void FUN_08072d48(Player* p) { INCFUNC("asm/func/FUN_08072d48.inc"); }

NAKED void FUN_0807304c(Player* p) { INCFUNC("asm/func/FUN_0807304c.inc"); }

NAKED void FUN_0807317c(Player* p) { INCFUNC("asm/func/FUN_0807317c.inc"); }

NAKED void FUN_08073574(Player* p) { INCFUNC("asm/func/FUN_08073574.inc"); }

NAKED void FUN_080736b8(Player* p) { INCFUNC("asm/func/FUN_080736b8.inc"); }

NAKED void FUN_080738b4(Player* p) { INCFUNC("asm/func/FUN_080738b4.inc"); }

NAKED void FUN_080739e0(Player* p) { INCFUNC("asm/func/FUN_080739e0.inc"); }

NAKED void FUN_08073b3c(Player* p) { INCFUNC("asm/func/FUN_08073b3c.inc"); }

NAKED void FUN_08073e18(Player* p) { INCFUNC("asm/func/FUN_08073e18.inc"); }

NAKED void FUN_08073f88(Player* p) { INCFUNC("asm/func/FUN_08073f88.inc"); }

NAKED void FUN_080740b0(Player* p) { INCFUNC("asm/func/FUN_080740b0.inc"); }

NAKED void FUN_08074244(Player* p) { INCFUNC("asm/func/FUN_08074244.inc"); }

NAKED void FUN_08074350(Player* p) { INCFUNC("asm/func/FUN_08074350.inc"); }

NAKED void FUN_080744bc(Player* p) { INCFUNC("asm/func/FUN_080744bc.inc"); }

NAKED void FUN_080746ec(Player* p) { INCFUNC("asm/func/FUN_080746ec.inc"); }

void FUN_08074994(Player* p) {
  p->plttID_95e = 295;
  p->unk_960 = 24;
}

void FUN_080749b0(Player* p) {
  switch (p->state) {
    case 0: {
      if (Player_PlayAnim(p, 536, FRACUNIT_6)) {
        Player_SetAction(p, 16, 1);
      }
      break;
    }
    case 1: {
      Player_PlayAnim(p, 538, FRACUNIT_6);
      if (p->stateTimer == 0) {
        FUN_080726b4(p);
        p->stateTimer++;
      }
      break;
    }
    case 2: {
      if (Player_PlayAnim(p, 536, FRACUNIT_6)) {
        Player_SetAnimFacing(p);
        FUN_08072620(p);
        FUN_080726b4(p);
      }
      break;
    }
  }
}

NAKED void FUN_08074a40(Player* p) { INCFUNC("asm/func/FUN_08074a40.inc"); }

NAKED void FUN_08074d90(Player* p) { INCFUNC("asm/func/FUN_08074d90.inc"); }

NAKED void FUN_08074e98(Player* p) { INCFUNC("asm/func/FUN_08074e98.inc"); }

NAKED void FUN_08075134(Player* p) { INCFUNC("asm/func/FUN_08075134.inc"); }

NAKED void FUN_08075980(Player* p) { INCFUNC("asm/func/FUN_08075980.inc"); }

NAKED void FUN_08075b4c(Player* p) { INCFUNC("asm/func/FUN_08075b4c.inc"); }

NAKED void FUN_08075df8(Player* p) { INCFUNC("asm/func/FUN_08075df8.inc"); }

NAKED void FUN_08075f00(Player* p) { INCFUNC("asm/func/FUN_08075f00.inc"); }

NAKED void FUN_080762fc(Player* p) { INCFUNC("asm/func/FUN_080762fc.inc"); }

NAKED void FUN_080765a0(Player* p) { INCFUNC("asm/func/FUN_080765a0.inc"); }

NAKED void FUN_0807688c(Player* p) { INCFUNC("asm/func/FUN_0807688c.inc"); }

NAKED void FUN_08076f2c(Player* p) { INCFUNC("asm/func/FUN_08076f2c.inc"); }

NAKED void FUN_08077100(Player* p) { INCFUNC("asm/func/FUN_08077100.inc"); }

NAKED void FUN_080772ec(Player* p) { INCFUNC("asm/func/FUN_080772ec.inc"); }

NAKED void FUN_080773f0(Player* p) { INCFUNC("asm/func/FUN_080773f0.inc"); }

NAKED void FUN_08077a5c(Player* p) { INCFUNC("asm/func/FUN_08077a5c.inc"); }

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

NAKED void FUN_0807858c(Player* p) { INCFUNC("asm/func/FUN_0807858c.inc"); }

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

NAKED void FUN_08078bc0(Player* p) { INCFUNC("asm/func/FUN_08078bc0.inc"); }

// clang-format off
const PlayerFunc PTR_ARRAY_085abcac[33] = {
    FUN_08066f7c,
    FUN_080672b0,
    MagicDash_Update,
    FUN_080695ec,
    FUN_08067510,
    FUN_08067de8,
    FUN_08069218,
    FUN_08067ffc,
    FUN_08068624,
    MagicRisingSun_08068944,
    MagicTransform_0806b92c,
    MagicChangeWolf_0806eb40,
    MagicChangeBat_0806bc74,
    MagicChangeMouse_0806bf18,
    MagicSleeping_0806c124,
    MagicFreeze_08069710,
    MagicHealing_08069928,
    MagicDynamite_08069b18,
    FUN_08069c8c,
    FUN_0806961c,
    FUN_08069648,
    FUN_0806a050,
    FUN_08069d70,
    FUN_08069f60,
    FUN_0806a084,
    FUN_0806a32c,
    FUN_0806a628,
    FUN_0806a88c,
    FUN_0806abd4,
    FUN_0806adc8,
    FUN_0806af70,
    FUN_0806f1ec,
    FUN_0806b06c,
};  // 0x085ABCAC
// clang-format on

// プレイヤーの毎フレーム更新本体, unk_1c の状態ごとに行動関数を呼び, 通常状態では段差を登れるかも見る
// 命令数は414で一致, 残差30箇所はほぼレジスタ割当, 原典は sp のコピーを r6 に持つがこちらは持たず, unk_3be = 0 のブロックが原典では関数末尾に出る
// Player_GetTileAt は一致していないので本来なら消す規約だが, 展開すると gcc が2つの同一ブロックを畳んで 397/414 まで遠くなるため残している
// Tier A-C 試済, 効いたもの: SIN/COS マクロ (乗算の項順), Player_SetFlag20 (定数の materialize 順), attr を s32 ローカルへ (u16 切り詰めの除去)
NON_MATCH void Player_UpdateDjango(Player* p) {
#ifdef NONMATCHING_C
  Player_SetFlag20(p, PFLAG20_UNK_14);

  switch (p->unk_1c) {
    case 1: {
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
      PTR_ARRAY_085abcac[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      } else {
        FUN_08066408(p);
      }

      FUN_08078bc0(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      FUN_08065b7c(p);
      if (p->kind == PLAYER_DARK_DJANGO) {
        FUN_08065dac(p);
      }
      FUN_0806623c(p);

      busy = p->goodCondTimer != 0 && p->goodCondID == GOOD_MINI;
      if (busy) {
        return;
      }

      canStep = !FUN_08065b44(p->tile.attr[1]) && p->action == 1 && (p->tile.unk_0[0] & 1) && (p->facing & 1);
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
      pos.x += COS(angle, 50);
      pos.z += SIN(angle, 50);

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
      Player_SetAction(p, 4, 0);
      break;
    }
    case 2: {
      p->flag20 |= PFLAG20_UNK_18;
      Player_SetFlag35a(p, PFLAG35A_NO_HITBOX);
      p->fn_498(p);
      FUN_08078bc0(p);
      FUN_080726ec(p);
      break;
    }
    case 4: {
      s32 n;

      p->flag20 |= PFLAG20_UNK_18;
      Player_SetFlag35a(p, PFLAG35A_NO_HITBOX);
      if (p->action >= 28 && p->action <= 31) {
        n = p->action;
      } else {
        n = (p->unk_3d2 != 0) ? 27 : 26;
      }
      PTR_ARRAY_085abcac[n](p);
      FUN_08078bc0(p);
      break;
    }
  }
#else
  INCFUNC("asm/func/Player_UpdateDjango.inc");
#endif
}

// clang-format off
const PlayerFunc PTR_ARRAY_085abd30[32] = {
    FUN_08066f7c,
    FUN_080672b0,
    FUN_0806b374,
    FUN_08072014,
    FUN_08067510,
    FUN_08067de8,
    FUN_08069218,
    FUN_0806830c,
    FUN_08068624,
    Sabata_BlackSun,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_0806961c,
    FUN_08069648,
    FUN_0806a050,
    FUN_08069d70,
    FUN_08069f60,
    FUN_0806a084,
    FUN_0806a32c,
    FUN_0806a628,
    FUN_0806a88c,
    FUN_0806abd4,
    FUN_0806adc8,
    FUN_0806af70,
    FUN_0806b758,
};  // 0x085ABD30
// clang-format on

NAKED void Player_UpdateSabata(Player* p) { INCFUNC("asm/func/Player_UpdateSabata.inc"); }

NAKED s32 FUN_080794e0(Player* p) { INCFUNC("asm/func/FUN_080794e0.inc"); }

// pos のタイルが滑る床か, 氷タイルか氷結した溶岩タイルなら真
bool32 Player_IsIcyTileAt(Vec3* pos) {
  TileAttr attr = Player_GetTileAt(pos)->attr;

  if (attr & TATTR_ICE) {
    return TRUE;
  }
  if (Player_IsFrozenLava(attr)) {
    return TRUE;
  }
  return FALSE;
}

NAKED void FUN_08079644(Player* p) { INCFUNC("asm/func/FUN_08079644.inc"); }

NAKED void FUN_0807972c(Player* p) { INCFUNC("asm/func/FUN_0807972c.inc"); }

// コウモリ形態の毎フレーム更新, unk_1c の状態ごとに行動関数を呼ぶ
void Player_UpdateBat(Player* p) {
  // clang-format off
  static const PlayerFunc sPlayerBatUpdates[27] = {
      FUN_0806c2dc,
      FUN_0806c400,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      FUN_0806cbe8,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      FUN_0806c868,
      FUN_0806c6d4,
      NULL,
      NULL,
      NULL,
      FUN_0806c9bc,
      NULL,
      NULL,
  };  // 0x085ABDB0
  // clang-format on

  Player_SetFlag20(p, PFLAG20_UNK_18);

  switch (p->unk_1c) {
    case 1: {
      s32 action;

      if (p->flag20 & PFLAG20_SUNBATHING) {
        Player_StepSunburn(p, gStat->sunGauge);
      }
      if (Player_IsInRain(p)) {
        FUN_0806687c(p);
        FUN_0806692c(p);
      }

      FUN_080784fc(p);
      action = FUN_080794e0(p);
      FUN_08066d7c(p, action);
      sPlayerBatUpdates[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      }

      FUN_08066408(p);
      FUN_0807972c(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      FUN_0806623c(p);
      break;
    }
    case 2: {
      Player_SetFlag35a(p, 8);
      p->fn_498(p);
      FUN_0807972c(p);
      FUN_080726ec(p);
      break;
    }
  }
}

// --------------------------------------------

NAKED s32 FUN_0807998c(Player* p) { INCFUNC("asm/func/FUN_0807998c.inc"); }

NAKED void FUN_08079a64(Player* p) { INCFUNC("asm/func/FUN_08079a64.inc"); }

// (Cマウスによる)ネズミ形態の毎フレーム更新, unk_1c の状態ごとに行動関数を呼ぶ
void Player_UpdateMouse(Player* p) {
  // clang-format off
  static const PlayerFunc sPlayerMouseUpdates[27] = {
      FUN_0806ceb0,
      FUN_0806d014,
      NULL,
      NULL,
      FUN_0806d22c,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      FUN_0806dd7c,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      FUN_0806d420,
      FUN_0806d5b0,
      NULL,
      NULL,
      FUN_0806d74c,
      FUN_0806da18,
      NULL,
      NULL,
  };  // 0x085ABE1C
  // clang-format on

  Player_SetFlag20(p, PFLAG20_UNK_14 | PFLAG20_SNEAKING | PFLAG20_UNK_18);

  switch (p->unk_1c) {
    case 1: {
      s32 action;

      if (p->flag20 & PFLAG20_SUNBATHING) {
        Player_StepSunburn(p, gStat->sunGauge);
      }
      if (Player_IsInRain(p)) {
        FUN_0806687c(p);
        FUN_0806692c(p);
      }

      FUN_080784fc(p);
      action = FUN_0807998c(p);
      FUN_08066d7c(p, action);
      sPlayerMouseUpdates[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      }

      FUN_08079a64(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      FUN_08065b7c(p);
      FUN_08065dac(p);
      FUN_0806623c(p);
      break;
    }
    case 2: {
      Player_SetFlag35a(p, PFLAG35A_NO_HITBOX);
      p->fn_498(p);
      FUN_08079a64(p);
      FUN_080726ec(p);
      break;
    }
  }
}

// --------------------------------------------

NAKED s32 FUN_08079c50(Player* p) { INCFUNC("asm/func/FUN_08079c50.inc"); }

NAKED void FUN_08079d40(Player* p) { INCFUNC("asm/func/FUN_08079d40.inc"); }

// 棺桶で寝ている間の毎フレーム更新, unk_1c の状態ごとに行動関数を呼ぶ
void Player_UpdateSleeping(Player* p) {
  // clang-format off
  static const PlayerFunc sPlayerSleepingUpdates[21] = {
      MagicSleeping_Update,
      FUN_0806e15c,
      NULL,
      FUN_0806e404,
      FUN_0806e4b4,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      FUN_0806e7dc,
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
      FUN_0806e674,
  };  // 0x085ABE88
  // clang-format on

  Player_SetFlag20(p, PFLAG20_UNK_14 | PFLAG20_UNK_18);
  p->unk_4bc = 0;
  p->unk_4c0 = 0;
  if (p->unk_38a != 0) {
    p->unk_38a--;
  }

  switch (p->unk_1c) {
    case 1: {
      s32 action;

      FUN_080784fc(p);
      action = FUN_08079c50(p);
      FUN_08066d7c(p, action);
      sPlayerSleepingUpdates[action](p);

      if (p->useForcedDelta != 0) {
        p->mover.delta = p->forcedDelta;
      }

      FUN_08079d40(p);
      if (p->lookAroundOffset.val) {
        Player_UpdateCameraLookAt(p);
      }
      FUN_08065b7c(p);
      FUN_0806623c(p);
      break;
    }
    case 2: {
      Player_SetFlag35a(p, 8);
      p->fn_498(p);
      FUN_08079d40(p);
      break;
    }
  }
}

// --------------------------------------------

void FUN_08066f7c(Player* p);
void FUN_080672b0(Player* p);
void FUN_0806f284(Player* p);
void FUN_080695ec(Player* p);
void FUN_08067510(Player* p);
void FUN_08067de8(Player* p);
void FUN_08069218(Player* p);
void FUN_08067ffc(Player* p);
void FUN_08068624(Player* p);
void MagicRisingSun_08068944(Player* p);
void MagicTransform_0806b92c(Player* p);
void MagicChangeWolf_0806eb40(Player* p);
void MagicChangeBat_0806bc74(Player* p);
void MagicChangeMouse_0806bf18(Player* p);
void MagicSleeping_0806c124(Player* p);
void MagicFreeze_08069710(Player* p);
void MagicHealing_0806f3a0(Player* p);
void FUN_0806f5d8(Player* p);
void FUN_08069c8c(Player* p);
void FUN_0806961c(Player* p);
void FUN_08069648(Player* p);
void FUN_0806a050(Player* p);
void FUN_08069d70(Player* p);
void FUN_08069f60(Player* p);
void FUN_0806a084(Player* p);
void FUN_0806a32c(Player* p);
void FUN_0806a628(Player* p);
void FUN_0806a88c(Player* p);

// clang-format off
const PlayerFunc PTR_ARRAY_085abedc[28] = {
    FUN_08066f7c,
    FUN_080672b0,
    FUN_0806f284,
    FUN_080695ec,
    FUN_08067510,
    FUN_08067de8,
    FUN_08069218,
    FUN_08067ffc,
    FUN_08068624,
    MagicRisingSun_08068944,
    MagicTransform_0806b92c,
    MagicChangeWolf_0806eb40,
    MagicChangeBat_0806bc74,
    MagicChangeMouse_0806bf18,
    MagicSleeping_0806c124,
    MagicFreeze_08069710,
    MagicHealing_0806f3a0,
    FUN_0806f5d8,
    FUN_08069c8c,
    FUN_0806961c,
    FUN_08069648,
    FUN_0806a050,
    FUN_08069d70,
    FUN_08069f60,
    FUN_0806a084,
    FUN_0806a32c,
    FUN_0806a628,
    FUN_0806a88c,
};  // 0x085ABEDC
// clang-format on

NAKED void FUN_08079f1c(Player* p) { INCFUNC("asm/func/FUN_08079f1c.inc"); }

// Player の登録表と関連するグローバルをまとめて 0 に戻す
void UNUSED FUN_0807a270(Player* p) {
  s32 i;

  gPlayerCount = 0;
  for (i = 0; i < 4; i++) {
    gPlayerPtr[i] = NULL;
    u16_03002b68[i] = 0;
    u32_03002bc0[i] = 0;
  }

  gGoodCondID = 0;
  u16_03002b7c = 0;
  gGoodCondTimer = 0;
  u16_03002bf0 = 0;
  u16_03002bd0 = 0;
  gSunGaugeOverride = 0;
  gSunGaugeOverrideTimer = 0;

  for (i = 0; i < 3; i++) {
    u16_ARRAY_03002ba0[i] = 0;
  }

  u16_03002b84 = 0;
  u16_03002bac = 0;
  gWindAngle = 0;
  u16_03002bb0 = 0;
}

// action 23 に入り, 足元タイルの高さから見た現在の高さを控えて向きのアニメを合わせる
void FUN_0807a334(Player* p) {
  Vec3* pos;
  CollisionMapTile* tile;
  s32 stairs;
  s32 height;
  u8 v;

  if (p->kind == PLAYER_SLEEPING) {
    p->formRequest = TRUE;
    p->formRequestKind = 1;
  }
  Player_SetAction(p, 23, 0);
  p->floatHeight = 0;

  pos = &p->mover.pos;
  tile = Player_GetTileAt(pos);
  stairs = tile->heightStairs >> 4;
  height = (tile->heightStairs & 0xF) << 8;
  switch (stairs) {
    case STAIRS_VERTICAL: {
      height -= (u8)pos->z;
      break;
    }
    case STAIRS_HORIZONTAL: {
      height -= (u8)pos->x;
      break;
    }
  }
  p->heightAboveTile = p->mover.pos.y - height;

  v = p->facing;
  if (v > 4) {
    p->animIDOffset = 8 - v;
    p->xflip = TRUE;
  } else {
    p->animIDOffset = v;
    p->xflip = FALSE;
  }
  p->hurtbox.unk_40 = 0;
}

void FUN_0807a44c(Player* p, s32 dir) {
  Player_SetAction(p, 4, 1);
  p->actionDir = dir;
  p->facing = (dir + 4) & 7;
  if (p->actionDir > 4) {
    p->animIDOffset = (8 - p->actionDir) >> 1;
    p->xflip = TRUE;
  } else {
    p->animIDOffset = p->actionDir >> 1;
    p->xflip = FALSE;
  }
  p->hurtbox.unk_40 = 0;
}

// プレイヤーが乗っているタイルの索引を返す, MoverTile の控えがあればそれ、無ければ座標から引く
s32 FUN_0807a4c4(s32 n) {
  Player* p = gPlayerPtr[n];

  if (p->mover.tile != NULL) {
    return p->mover.tile->tileIdx[1];
  } else {
    s32 bx = p->mover.pos.x >> 8;
    s32 bz = p->mover.pos.z >> 8;

    if (bx < 0 || bz < 0 || (u32)bx >= (u32)gMapBlockW || (u32)bz >= (u32)gMapBlockH) {
      return 0;
    }
    return gCollisionMap->rowOffsets[bz] + bx;
  }
}

void FUN_0807a524(Vec3* pos) {}

void FUN_0807a528(Player* p, Vec3* pos, u16 param_3) {
  p->action = 8;
  p->stateTimer = 0;
  p->state = 0;
  p->floatHeight = 0;
  p->unk_3b0 = *pos;
  p->unk_3b8 = param_3;
}

bool32 FUN_0807a570(Player* p, s32 param_2) {
  bool32 ret;

  if (gFlag030047a4 & FLAG030047A4_LINK) {
    FUN_080d040c(p);
    Player_SetAction(p, 28, 0);
    return FALSE;
  }
  if (p->action == 6) {
    ret = TRUE;
    FUN_0807bdc8(p, p->facing, 1, 0);
  } else {
    ret = FALSE;
    FUN_0807bdc8(p, p->facing, param_2, 0);
  }
  return ret;
}

NAKED s32 FUN_0807a5d8(WeaponData* w, const ArmorData* armor) { INCFUNC("asm/func/FUN_0807a5d8.inc"); }

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
// 残差2命令: 原典は gStat->exp への store ごとに gStat を読み直す (agbcc-levers.md 参照)
NON_MATCH void AddPlayerExp(s32 amount) {
#ifdef NONMATCHING_C
  if (gStat->playerKind == PLAYER_SABATA) {
    return;
  }
  if (gPlayerPtr[0] != NULL && (gPlayerPtr[0]->equipBuffs & EBUFF_TRAININGGEAR)) {
    amount = (amount * 3) >> 1;
  }
  gStat->exp += amount;
  if (gStat->exp >= 999999) {
    gStat->exp = 999999;
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
s32 FUN_0807a8ac(s32 kind) { return *(gStat->weaponExp + kind); }

// 武器の経験値をレベルに直す, 100 たまると1レベル
s32 GetWeaponSkillLevel(s32 kind) { return Div(*(gStat->weaponExp + kind), 100); }

void FUN_0807a8e0(Player* p) { KAAMOS(p->isSabata) = 0; }

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
  p->sprite_e8.pos = *pos;
  p->sprite_88.pos = *pos;
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

void FUN_0807a9b8(Player* p, void* val) {
  p->ptr_398 = val;
  p->unk_394 = 1;
}

bool32 FUN_0807a9d0(Player* p) {
  if (!(p->unk_1c & 1)) {
    return FALSE;
  }
  if (p->action > 1 && p->action != 3 && (p->action != 7 || p->state != 0)) {
    return FALSE;
  }
  return TRUE;
}

void FUN_0807aa00(Player* p, s32 amount) {
  if (p->unk_1c == 1) {
    p->hp += amount;
    if (p->hp >= p->maxHP) {
      p->hp = p->maxHP;
    }
  }
}

void FUN_0807aa30(Player* p, s32 amount) {
  if (p->unk_1c == 1) {
    p->ene += amount;
    if (p->ene >= p->maxEne) {
      p->ene = p->maxEne;
    }
  }
}

// ENE を減らす, 0 未満にはならない
void Player_ReduceENE_0807aa60(Player* p, s32 amount) {
  if (p->unk_1c == 1) {
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
  EquipBuffs mask = EBUFF_FAIRY;

  if (p->equipBuffs & mask) {
    FUN_0807aa00(p, amount * 2);
  } else {
    FUN_0807aa00(p, amount);
  }
}

// 太陽虫取得時に呼ばれる(Ene回復), 精霊の衣を着ていると効果が2倍になる
void Player_ApplySolarbug(Player* p, s32 amount) {
  EquipBuffs mask = EBUFF_FAIRY;

  if (p->equipBuffs & mask) {
    FUN_0807aa30(p, amount * 2);
  } else {
    FUN_0807aa30(p, amount);
  }
}

// 暗黒虫取得時に呼ばれる(Eneが減る), 精霊の衣を着ていると効果が2倍になる
void Player_ApplyDarkbug(Player* p, s32 amount) {
  EquipBuffs mask = EBUFF_FAIRY;

  if (p->equipBuffs & mask) {
    Player_ReduceENE_0807aa60(p, amount * 2);
  } else {
    Player_ReduceENE_0807aa60(p, amount);
  }
}

void FUN_0807ab14(Player* p) {
  Player_SetFlag20(p, PFLAG20_UNK_12);
  p->formRequest = FALSE;
  p->animIDOffset = 0;
  FUN_08063220(p);
  p->hurtbox.flags |= HBFLAG_UNK_2;
  p->hurtbox.unk_40 = 0;
  p->hurtbox.unk_44 = 0;
  Player_SetAction(p, 21, 0);
}

NAKED s32 FUN_0807ab64(Player* param_1, PlayerFunc** param_2, unknown* param_3, s32 param_4, u8 param_5, s32 param_6, s32 param_7, s32 param_8, u32 param_9) { INCFUNC("asm/func/FUN_0807ab64.inc"); }

NAKED u32 FUN_0807ac74(Player* p, unknown* param_2, u16 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_0807ac74.inc"); }

bool32 FUN_0807ad60(Player* p, s32 param_2) {
  if (p->unk_1c != 1 || p->kind == PLAYER_BAT) {
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
  if (p->action == 26) {
    if (p->state == 3) {
      Player_SetAction(p, 26, 4);
    }
  } else if (p->action == 27) {
    if (p->state == 4) {
      Player_SetAction(p, 27, 5);
    }
  } else if (p->action == 31) {
    if (p->kind == PLAYER_SABATA) {
      if (p->state == 3) {
        Player_SetAction(p, 31, 4);
      }
    } else if (p->state == 1) {
      Player_SetAction(p, 31, 2);
    }
  } else if (p->unk_1c == 2 && p->action == 18 && p->state == 1) {
    Player_SetAction(p, 18, 4);
  }
#else
  INCFUNC("asm/func/FUN_0807adc0.inc");
#endif
}

NAKED void FUN_0807ae6c(Player* p, u32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0807ae6c.inc"); }

// '.i' から gPlayerPtr の idx を取得する, なかったら 0 (1P) を返す
u32 VM_GetPlayerIdx(void) { return VM_SeekToNamedArg('i') ? VM_GetValue() : 0; }

static s32 FUN_0807b000(Vec3* pos) {
  if (VM_SeekToNamedArg('p')) {
    pos->x = VM_GetValue();
    pos->y = VM_GetValue();
    pos->z = VM_GetValue();
    return 1;
  }
  return 0;
}

// 0xE14B
void FUN_0807b02c(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && FUN_0807b000(&p->mover.pos)) {
    if (VM_SeekToNamedArg('d')) {
      s32 dir = VM_GetValue();

      p->facing = dir;
      if (p->facing > FACE_DOWN) {
        p->animIDOffset = 8 - dir;
        p->xflip = 1;
      } else {
        p->animIDOffset = dir;
        p->xflip = 0;
      }
    }
    Map_InitMoverTile(&p->tile, &p->mover.pos);
    Player_SetAction(p, 0, 0);
    Player_StopEneChargeSound(p);
  }
}

NON_MATCH s32 FUN_0807b0c0(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p == NULL) {
    return gStat->playerFacing;
  }
  if (p->action == 4 || p->action == 5) {
    return (p->actionDir + 4) & 7;
  }
  return p->facing;
#else
  INCFUNC("asm/func/FUN_0807b0c0.inc");
#endif
}

// 0x5986
bool32 FUN_0807b118(void) {
  if (gPlayerPtr[0] == NULL || gPlayerPtr[0]->unk_1c != 4) {
    return FALSE;
  }
  return TRUE;
}

s32 FUN_0807b138(void) {
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

// 残差1命令 (24対25), 原典は gPlayerPtr[i] を ldr r0, [r0] で読んでから adds r4, r0, #0 で写すが, こちらは ldr r4, [r0] と直接読む
// VM_GetValue() をローカルに受けて & の被演算子順を固定したぶんは解消済み. 残りは FUN_0807b2dc と同一の詰まりで, そちらで Tier A-C を試済
NON_MATCH s32 FUN_0807b1a4(void) {
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
  INCFUNC("asm/func/FUN_0807b1a4.inc");
#endif
}

NAKED void item_0807b1e4(Player* p) { INCFUNC("asm/func/item_0807b1e4.inc"); }

// 残差1命令 (21対22), 原典は gPlayerPtr[i] を ldr r0, [r0] で読んでから adds r1, r0, #0 で写すが, こちらは ldr r1, [r0] と直接読むぶん1本短い
// Tier A-C は試済 (&& と入れ子 if, 宣言と代入の分離, gPlayerPtr[VM_GetPlayerIdx()] の1ローカル化 (これは push {r4, lr} になって悪化)). 直下の FUN_0807b314 は同じ前置きで一致しているので前置きの書き方ではない
NON_MATCH s32 FUN_0807b2dc(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && p->goodCondTimer != 0) {
    return p->goodCondID;
  }
  return -1;
#else
  INCFUNC("asm/func/FUN_0807b2dc.inc");
#endif
}

void FUN_0807b314(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    p->goodCondID = 0;
    p->goodCondTimer = 0;
    p->unk_444 = 0;
  }
}

// 0xCD57
// 残差1命令: 原典は読み込んだ Player* をもう1本のレジスタに写す (agbcc-levers.md 参照)
NON_MATCH void FUN_0807b34c(void) {
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
  INCFUNC("asm/func/FUN_0807b34c.inc");
#endif
}

void FUN_0807b3c0(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    FUN_08063220(gPlayerPtr[i]);
  }
}

// 0xDD0E
// 残差は分岐の配置のみ (命令数 28 対 28): 原典は return 0 のブロックが先に出て、成功側が後ろに置かれる
NON_MATCH bool32 FUN_0807b3e0(void) {
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
  INCFUNC("asm/func/FUN_0807b3e0.inc");
#endif
}

// 0x650B
void FUN_0807b428(void) {
  static const u16 sBadCondFrames[3] = {30 * 60, 30 * 60, 15 * 60};  // 0x085ABF4C
  if (VM_SeekToNamedArg('s')) {
    s32 n = VM_GetValue();

    if (n < (s32)ARRAY_COUNT(sBadCondFrames)) {
      s32 val = VM_SeekToNamedArg('t') ? VM_GetValue() : sBadCondFrames[n];

      if (gPlayerPtr[0] != NULL) {
        Player_ApplyBadCondition(gPlayerPtr[0], n, val);
      } else {
        u16_ARRAY_03002ba0[n] = val;
      }
    }
  }
}

void FUN_0807b484(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('s')) {
    Player_ClearBadCondition(p, VM_GetValue());
  }
}

void FUN_0807b4b8(void) {
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
bool32 FUN_0807b4e4(void) {
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
void FUN_0807b528(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    KAAMOS(p->isSabata) = 0;
  }
}

void FUN_0807b564(void) {
  u16_03002bd0 = 0;
  gSunGaugeOverride = 0;
  gSunGaugeOverrideTimer = 0;
}

// 0xFD12
void FUN_0807b580(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    gPlayerPtr[i]->unk_43a = 1;
  }
}

void FUN_0807b5a8(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    gPlayerPtr[i]->unk_3ba = 1;
  }
}

void FUN_0807b5d0(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    gPlayerPtr[i]->magic.unk_285 = 1;
  }
}

void FUN_0807b5f8(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    gPlayerPtr[i]->magic.unk_285 = 0;
  }
}

// スクリプトが指すプレイヤーの武器種を返す
s32 FUN_0807b620(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] == NULL) {
    return 0;
  }
  return gPlayerPtr[i]->weaponKind;
}

void FUN_0807b64c(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    FUN_0807e854(gPlayerPtr[i]);
  }
}

// 残差1命令: 原典は gPlayerPtr[i] を読んだあと別レジスタへ写し、後半の呼び出しはそちらを使う
// FUN_0807b2dc と同じ「読んだポインタの写し」が出ない類, ローカル1個・gPlayerPtr[i] 直接・両者の混在を試済
NON_MATCH void FUN_0807b66c(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807e854(p);
    if (VM_SeekToNamedArg('d')) {
      p->facing = VM_GetValue();
    }
    Player_SetAnimFacing(p);
    Player_SetAction(p, 31, 0);
  }
#else
  INCFUNC("asm/func/FUN_0807b66c.inc");
#endif
}

NAKED s32 FUN_0807b6b8(Player* p) { INCFUNC("asm/func/FUN_0807b6b8.inc"); }

NAKED void Player_EnterLockedState(Player* p) { INCFUNC("asm/func/Player_EnterLockedState.inc"); }

void FUN_0807b890(Player* p, s32 val) {
  p->unk_96c = 1;
  p->plttID_95e = val;
}

void FUN_0807b8a8(Player* p, s32 val) {
  p->unk_96c = 2;
  p->plttID_95e = val;
}

void FUN_0807b8c0(Player* p) { p->unk_96c = 0; }

void Player_SetPos(Player* p, WorldPos* src) { p->mover.pos = *src; }

void FUN_0807b8dc(Player* p) {
  Player_EnterLockedState(p);
  Player_SetAction(p, 0, 0);
  p->sprite_88.flags |= SPRFLAG_HIDDEN;
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
    if (p->facing > 4) {
      p->animIDOffset = (8 - p->facing) >> 1;
      p->xflip = TRUE;
    } else {
      p->animIDOffset = p->facing >> 1;
      p->xflip = FALSE;
    }
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
  Player_SetAction(p, 0, 0);
}

void FUN_0807b9dc(Player* p, DirS32 dir, u32 scriptID) {
  p->dir_4a9 = dir;
  p->scriptID_4b0 = scriptID;
  p->fn_498 = FUN_080727d4;
  Player_EnterLockedState(p);
  Player_SetAction(p, 0, 0);
}

void FUN_0807ba14(Player* p, DirS32 dir) {
  if (dir >= 0) {
    p->facing = dir;
  }
  Player_SetAnimFacing(p);
  Player_EnterLockedState(p);
  Player_SetAction(p, 0, 1);
  p->fn_498 = FUN_08072724;
}

void FUN_0807ba50(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) {
    p->facing = dir;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 0, 2);
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
    p->fn_498 = FUN_08074e98;
  } else if (p->kind == PLAYER_MOUSE) {
    p->fn_498 = FUN_08075f00;
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
  Player_SetAction(p, 1, 0);
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
  Player_SetAction(p, 6, 0);
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
  Player_SetAction(p, 7, 0);
  p->fn_498 = FUN_0807304c;
}

void FUN_0807bc14(Player* p, s32 param_2, u32 scriptID) {
  p->unk_4a6 = param_2;
  p->scriptID_4b0 = scriptID;
  p->facing = FACE_UP;
  p->animIDOffset = 0;
  p->xflip = 0;
  Player_EnterLockedState(p);
  Player_SetAction(p, 7, 0);
  p->fn_498 = FUN_0807304c;
}

void FUN_0807bc64(Player* p, u32 scriptID) {
  if (p->unk_1c == 2 && p->action == 7 && p->state != 0) {
    p->scriptID_4b0 = scriptID;
    Player_EnterLockedState(p);
    Player_SetAction(p, 7, 3);
    p->fn_498 = FUN_0807304c;
  }
}

void FUN_0807bcb0(Player* p, DirS32 dir, u32 scriptID) {
  Player_EnterLockedState(p);
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 18, 0);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bcfc(Player* p, DirS32 dir) {
  Player_EnterLockedState(p);
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  PlaySound_082406e0(SONG_198);
  Player_EnterLockedState(p);
  Player_SetAction(p, 18, 2);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bd44(Player* p, DirS32 dir) {
  Player_EnterLockedState(p);
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  Player_EnterLockedState(p);
  Player_SetAction(p, 18, 1);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bd84(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 18, 3);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bdc8(Player* p, DirS32 dir, s32 param_3, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->facing |= 1;
  p->scriptID_4b0 = scriptID;
  p->unk_4a6 = param_3;
  p->unk_3f0 = param_3;
  Player_EnterLockedState(p);
  Player_SetAction(p, 22, 0);
  if (p->kind == PLAYER_MOUSE) {
    p->fn_498 = FUN_080762fc;
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
  Player_SetAction(p, 23, 0);
  if (p->kind == PLAYER_MOUSE) {
    p->fn_498 = FUN_080765a0;
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
  p->unk_4a4 = param_3;
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 24, 0);
  if (p->kind == PLAYER_BAT) {
    p->fn_498 = FUN_08075980;
  } else if (p->kind == PLAYER_MOUSE) {
    p->fn_498 = FUN_08076f2c;
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
  p->unk_4a4 = param_3;
  p->unk_4a6 = param_4;
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 25, 0);
  p->fn_498 = FUN_08073b3c;
}

void FUN_0807c048(Player* p, s32 scriptID) {
  if (p->unk_1c == 2 && p->action == 25 && p->state == 5) {
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
  p->unk_4a4 = param_3;
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 24, 0);
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
  animID = p->animIDOffset + FUN_08066ee4(p->kind, 46);
  MainSprite_SetAnim(&p->sprite_88, &p->spriteSet_68, animID, 1, MAIN_ANIM_REVERSE);
  MainSprite_AdvanceAnim(&p->sprite_88, &p->spriteSet_68);
  if (p->xflip) {
    p->sprite_88.flags |= SPRFLAG_XFLIP;
  } else {
    p->sprite_88.flags &= ~SPRFLAG_XFLIP;
  }
  Player_SetAction(p, 24, 2);
  p->fn_498 = FUN_08073e18;
}

void FUN_0807c200(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 7, 0);
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
  Player_SetAction(p, 7, 7);
  p->fn_498 = FUN_0807317c;
}

NAKED void FUN_0807c36c(Player* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0807c36c.inc"); }

void FUN_0807c458(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 3, 0);
  p->fn_498 = FUN_08073f88;
}

void FUN_0807c49c(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 3, 2);
  p->fn_498 = FUN_08073f88;
}

void FUN_0807c4e0(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 3, 0);
  p->fn_498 = FUN_080740b0;
}

void FUN_0807c524(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 3, 2);
  p->fn_498 = FUN_080740b0;
}

void FUN_0807c568(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 3, 0);
  p->fn_498 = FUN_08074244;
}

void FUN_0807c5ac(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 3, 2);
  p->fn_498 = FUN_08074244;
}

void FUN_0807c5f0(Player* p, DirS32 dir, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 3, 0);
  p->fn_498 = FUN_08074350;
}

NAKED void FUN_0807c634(Player* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0807c634.inc"); }

void FUN_0807c748(Player* p, DirS32 dir, s32 param_3, u32 scriptID) {
  if (dir >= 0) p->facing = dir;
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = scriptID;
  p->unk_4a7 = param_3;
  Player_EnterLockedState(p);
  Player_SetAction(p, 3, 0);
  p->fn_498 = FUN_080744bc;
}

void FUN_0807c798(Player* p, s32 scriptID) {
  p->scriptID_4b0 = scriptID;
  Player_EnterLockedState(p);
  Player_SetAction(p, 3, 5);
  p->fn_498 = FUN_080744bc;
}

NAKED void FUN_0807c7c8(Player* p) { INCFUNC("asm/func/FUN_0807c7c8.inc"); }

void FUN_0807c88c(Player* p, Vec3* pos, DirS32 dir, u32 scriptID) {
  p->unk_49c = *pos;
  p->scriptID_4b0 = scriptID;
  p->dir_4a9 = dir;
  Player_EnterLockedState(p);
  Player_SetAction(p, 2, 0);
  p->fn_498 = FUN_080746ec;
}

void FUN_0807c8d4(Player* p, DirS32 dir) {
  if (dir >= 0) {
    p->facing = dir;
  }
  Player_SetAnimFacing(p);
  Player_PlayAnim(p, FUN_08066ee4(p->kind, 1), 0x20);
  Player_EnterLockedState(p);
  Player_SetAction(p, 2, 0);
  p->fn_498 = FUN_08074994;
}

void FUN_0807c928(Player* p, s32 val) {
  Player_EnterLockedState(p);
  p->facing = FACE_UP_RIGHT;
  p->animIDOffset = 0;
  p->xflip = 0;
  Player_SetAction(p, 16, 0);
  p->fn_498 = FUN_080749b0;
}

void FUN_0807c968(Player* p, s32 val) {
  Player_EnterLockedState(p);
  p->facing = FACE_UP_RIGHT;
  p->animIDOffset = 0;
  p->xflip = 0;
  Player_SetAction(p, 16, 2);
  p->fn_498 = FUN_080749b0;
}

void FUN_0807c9ac(Player* p, s32 xflip, u32 param_3) {
  if (xflip != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = TRUE;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = FALSE;
  }
  p->scriptID_4b0 = param_3;
  Player_EnterLockedState(p);
  Player_SetAction(p, 0, 0);
  p->fn_498 = FUN_080728a8;
}

void FUN_0807ca24(Player* p, s32 xflip, u32 param_3) {
  if (xflip != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = TRUE;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = FALSE;
  }
  p->scriptID_4b0 = param_3;
  Player_EnterLockedState(p);
  Player_SetAction(p, 0, 3);
  p->fn_498 = FUN_080728a8;
}

void FUN_0807ca9c(Player* p, s32 xflip, u32 param_3) {
  if (xflip != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = TRUE;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = FALSE;
  }
  p->scriptID_4b0 = param_3;
  Player_EnterLockedState(p);
  Player_SetAction(p, 0, 4);
  p->fn_498 = FUN_080728a8;
}

void FUN_0807cb14(Player* p, s32 xflip, u32 param_3) {
  if (xflip != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = TRUE;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = FALSE;
  }
  p->scriptID_4b0 = param_3;
  Player_EnterLockedState(p);
  Player_SetAction(p, 0, 2);
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
  Player_SetAction(p, 0, 0);
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
  Player_SetAction(p, 0, 0);
  p->fn_498 = FUN_08072a0c;
}

bool32 FUN_0807cc84(Player* p, u32 scriptID) {
  p->scriptID_4b0 = scriptID;
  if (p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) {
    return FALSE;
  }
  if (p->kind == PLAYER_BAT) {
    Player_EnterLockedState(p);
    Player_SetAction(p, 12, 0);
    p->fn_498 = FUN_08075b4c;
  } else if (p->kind == PLAYER_MOUSE) {
    Player_EnterLockedState(p);
    Player_SetAction(p, 13, 0);
    p->fn_498 = FUN_08077100;
  } else if (p->kind == PLAYER_SLEEPING) {
    p->facing = FACE_DOWN;
    Player_SetAnimFacing(p);
    Player_EnterLockedState(p);
    Player_SetAction(p, 14, 0);
    p->fn_498 = FUN_08077a5c;
  } else {
    return FALSE;
  }
  return TRUE;
}

NAKED void FUN_0807cd24(Player* p, u32 param_2) { INCFUNC("asm/func/FUN_0807cd24.inc"); }

void FUN_0807ceb8(Player* p) { FUN_08063220(p); }

NAKED void FUN_0807cec4(Player* p, s32 kind, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0807cec4.inc"); }

void Player_Unlock(Player* p) {
  if (p->action != 6) {
    p->action = 0;
  }
  p->state = 0;
  p->stateTimer = 0;
  if (p->unk_4a8 != 0) {
    p->unk_4a8 = 0;
  }
  p->unk_1c = 1;
  p->unk_395 = 0;
}

// コマンドのヘルパーで、 '.d' で渡されたプレイヤーの向きを取得する
DirS32 Player_GetCmdArgDir(void) {
  if (VM_SeekToNamedArg('d')) {
    return VM_GetValue();
  }
  return -1;
}

u32 FUN_0807d180(void) { return VM_SeekToNamedArg('e') ? VM_GetValue() : 0; }

void FUN_0807d198(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807b8dc(p);
    FUN_08072640(p);
  }
}

void FUN_0807d1c0(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('p')) {
    FUN_0807b890(p, VM_GetValue() + 0x121);
    FUN_08072640(p);
  }
}

void FUN_0807d200(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('p')) {
    FUN_0807b8a8(p, VM_GetValue() + 0x121);
    FUN_08072640(p);
  }
}

void FUN_0807d240(void) {
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
    FUN_0807b9dc(p, Player_GetCmdArgDir(), FUN_0807d180());
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
    FUN_0807ba50(p, Player_GetCmdArgDir(), FUN_0807d180());
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

    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
    dir = Player_GetCmdArgDir();
    scriptID = FUN_0807d180();
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

    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
    dir = Player_GetCmdArgDir();
    scriptID = FUN_0807d180();
    FUN_0807c88c(p, &pos, dir, scriptID);
    FUN_08072640(p);
  }
}

void FUN_0807d438(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 param_4 = VM_SeekToNamedArg('f') ? VM_GetValue() : 0;
    DirS32 dir = Player_GetCmdArgDir();
    u32 scriptID = FUN_0807d180();

    if (VM_SeekToNamedArg('p')) {
      Vec3 pos;
      pos.x = VM_GetValue();
      pos.y = VM_GetValue();
      pos.z = VM_GetValue();
      FUN_0807bb3c(p, &pos, dir, param_4, scriptID);
    } else {
      FUN_0807bb3c(p, NULL, dir, param_4, scriptID);
    }
    FUN_08072640(p);
  }
}

void FUN_0807d4ec(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    u32 scriptID = FUN_0807d180();

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

void FUN_0807d560(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bc64(p, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d590(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bcb0(p, Player_GetCmdArgDir(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d5c8(void) {
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
    FUN_0807bd84(p, Player_GetCmdArgDir(), FUN_0807d180());
    FUN_08072640(p);
  }
}

// 0x58D7
void Cmd_58D7(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    DirS32 dir = Player_GetCmdArgDir();
    u32 b = FUN_0807d180();

    FUN_0807bdc8(p, dir, VM_SeekToNamedArg('f') ? VM_GetValue() : 0, b);
  }
}

// 0x3705
void Cmd_3705(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    DirS32 dir = Player_GetCmdArgDir();
    u32 b = FUN_0807d180();

    FUN_0807be58(p, dir, VM_SeekToNamedArg('h') ? VM_GetValue() : 1500, b);
    FUN_08072640(p);
  }
}

void FUN_0807d6f8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('f') ? VM_GetValue() : 30;

    FUN_0807bee0(p, Player_GetCmdArgDir(), n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d744(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 param_3 = VM_SeekToNamedArg('f') ? VM_GetValue() : 50;
    s32 param_4 = VM_SeekToNamedArg('L') ? VM_GetValue() : 0;
    DirS32 dir = Player_GetCmdArgDir();
    u32 scriptID = FUN_0807d180();

    FUN_0807bfa4(p, dir, param_3, param_4, scriptID);
    FUN_08072640(p);
  }
}

void FUN_0807d7ac(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c048(p, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d7dc(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('f') ? VM_GetValue() : 50;

    FUN_0807c084(p, Player_GetCmdArgDir(), n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d828(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c11c(p, Player_GetCmdArgDir());
    FUN_08072640(p);
  }
}

void FUN_0807d858(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c200(p, Player_GetCmdArgDir(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d890(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c36c(p, Player_GetCmdArgDir(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d8c8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c458(p, Player_GetCmdArgDir(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d900(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c49c(p, Player_GetCmdArgDir(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d938(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c4e0(p, Player_GetCmdArgDir(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d970(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c524(p, Player_GetCmdArgDir(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d9a8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c568(p, Player_GetCmdArgDir(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d9e0(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c5ac(p, Player_GetCmdArgDir(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807da18(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c5f0(p, Player_GetCmdArgDir(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807da50(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('l') ? VM_GetValue() : 32;

    FUN_0807c634(p, n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807da94(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    bool32 done = FUN_0807cc84(p, FUN_0807d180());

    FUN_08072640(p);
    if (!done) {
      FUN_08072650(p);
    }
  }
}

void FUN_0807dad0(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('r') ? VM_GetValue() : 0;

    FUN_0807c9ac(p, n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807db14(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('r') ? VM_GetValue() : 0;

    FUN_0807ca24(p, n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807db58(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('r') ? VM_GetValue() : 0;

    FUN_0807ca9c(p, n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807db9c(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('r') ? VM_GetValue() : 0;

    FUN_0807cb14(p, n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807dbe0(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('d') ? VM_GetValue() : 0;

    FUN_0807cb8c(p, n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807dc24(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807cc14(p, VM_SeekToNamedArg('r') ? VM_GetValue() : 0);
    FUN_08072640(p);
  }
}

void FUN_0807dc60(void) {
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

NAKED void FUN_0807dcec(Player* p) { INCFUNC("asm/func/FUN_0807dcec.inc"); }

void FUN_0807ddbc(Player* p) { MsgQueue_Register(&p->mq, p->mover.id, 2); }

void FUN_0807ddd4(Player* p) { MsgQueue_Unregister(&p->mq); }

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
NAKED void Django_Spike(Player* p) { INCFUNC("asm/func/Django_Spike.inc"); }

// hitboxTimer が残っている間 hitbox_2ec を当たり判定に出し続ける
void FUN_0807e388(Player* p) {
  if (p->hitboxTimer != 0) {
    Hitbox_Register(&p->hitbox_2ec);
    p->hitboxTimer--;
  }
}

NAKED u32 FUN_0807e3b0(Player* p, HitboxData* a, HitboxData* b) { INCFUNC("asm/func/FUN_0807e3b0.inc"); }

void Django_OnHurt(HitboxData* a, HitboxData* b, Player* p) {
  if (p->unk_1c == 1) {
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
    FUN_0807e3b0(p, a, b);
    if (Player_GetFlag378(p, EBUFF_SPIKE)) {
      Django_Spike(p);
    }
  }
}

// 一時的な HitboxData を組み立てて自分の当たり判定にぶつける
s32 FUN_0807e7fc(Player* p, s32 power, s32 unk_40, s32 angle, s32 unk_44, HitboxAttributes attrs) {
  if (p->unk_1c == 1) {
    HitboxData* own = &p->hurtbox;
    s32 n = own->unk_44;

    if (n <= 0) {
      HitboxData hb;
      hb.flags = HBFLAG_HITBOX;
      hb.power = power;
      hb.unk_40 = unk_40;
      hb.angle = angle;
      hb.attributes = attrs;
      hb.unk_44 = unk_44;
      return FUN_0807e3b0(p, &hb, own);
    }
  }
  return 0;
}

NAKED void FUN_0807e854(Player* p) { INCFUNC("asm/func/FUN_0807e854.inc"); }

// 残差9命令 (341/350), 3箇所 (SF934_UNK_13 / SF934_DESERT / EBUFF_BLACKARMOR) で原典はマスクをレジスタに作ってから AND し, 真偽値を 0/1 に materialize してから cmp する
// FUN_0806241c と同じ壁で, マスクを引数に取る static inline にするとマスクはレジスタに乗るが 0/1 の materialize は agbcc が畳む
// 他は PFLAG20_UNK_9 の |= のマスク順と unk_3da のカウンタ順の1命令
NON_MATCH bool32 Player_UpdateDamage(Player* p) {
#ifdef NONMATCHING_C
  CollisionMapTile* tile = Player_GetTileAt(&p->mover.pos);

  if ((tile->attr & TATTR_ICE) && p->unk_390 == 0) {
    if (gStat->unk_934 & SF934_UNK_13) {
      Player_SetAction(p, 0x1D, 0);
    } else {
      Player_SetAction(p, 0x1C, 0);
    }
    return TRUE;
  }

  if (gStat->heatstroke > 4999) {
    Player_SetAction(p, 0x1E, 0);
    return TRUE;
  }

  if (p->unk_394) {
    p->damage += FUN_08065cb8(p);
  } else if (p->unk_396) {
    p->damage += FUN_08065e24(p);
  }

  if (p->hurtbox.unk_44 == 0) {
    if (p->badCondTimer[1] != 0) {
      p->poisonTick++;
      if (p->poisonTick > 59) {
        p->damage++;
        p->poisonTick = 0;
      }
    }
    if (p->unk_4c4.kind == 1 && p->unk_4c4.unk_3 != 0) {
      u16 t;

      p->flag20 |= PFLAG20_UNK_9;
      p->unk_3da++;
      t = p->unk_3da;
      if (t >= Div(60, p->unk_4c4.unk_3)) {
        p->damage += 10;
        p->unk_3da = 0;
      }
    }
    if (gStat->unk_934 & SF934_DESERT) {
      p->desertTimer++;
      if (p->desertTimer > 119) {
        p->damage++;
        p->desertTimer = 0;
      }
    } else {
      p->desertTimer = 120;
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
      FUN_0805fe7c(&p->hurtbox, p->damage, 0, &p->mover.pos, &p->pos_970, 0);
      if (p->hp < p->damage) {
        p->hp = 0;
      } else {
        p->hp -= p->damage;
      }
    }
  }

  p->damage = 0;
  p->pos_970.x = 0, p->pos_970.y = 0, p->pos_970.z = 0;

  if (p->action == 0x15 || p->hp != 0) {
    return FALSE;
  }
  if (gFlag030047a4 & FLAG030047A4_UNK_12) {
    return TRUE;
  }
  if (!CheckItemOwn(ITEM_JUDGEMENT)) {
    return TRUE;
  }

  p->unk_3d6 = 0;
  if (p->hurtbox.unk_40 == 0) {
    p->facing |= 1;
    p->hurtbox.unk_40 = 1;
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
  s32 n = p->hurtbox.unk_44;

  if (n > 0) {
    Player_SetFlag35a(p, PFLAG35A_NO_HITBOX);
    if (p->hurtbox.unk_40 == 0 && p->action != 24 && p->action != 25) {
      n--;
      if (n != 0 && ((n >> 2) & 1)) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_SPRITE | PFLAG35A_HIDE_SHADOW);
      }
      p->hurtbox.unk_44 = n;
    }
  }
#else
  INCFUNC("asm/func/FUN_0807eca8.inc");
#endif
}

NAKED void FUN_0807ed04(Player* p) { INCFUNC("asm/func/FUN_0807ed04.inc"); }

// 変身の要求 (formRequest) を実際のフォーム切り替えに反映する, 使うスプライトと更新関数とパレットを差し替える
void Player_ApplyFormRequest(Player* p) {
  if (!p->formRequest) {
    return;
  }

  if (p->formRequestKind == PLAYER_BAT) {
    p->kind = PLAYER_BAT;
    p->updateCallback = Player_UpdateBat;
    p->unk_359 = 1;
    p->mover.mainSprite = NULL, p->mover.auxSprite = &p->sprite_e8;
    p->unk_4c4.pos = &p->sprite_e8.pos;
    Player_SetPlttIDs(p);
    p->unk_94c = 0xFFFF;
    p->gfx_114->plttID = p->plttID_94a;
    p->plttID_95e = 621;
    p->unk_960 = 0x20;
  } else if (p->formRequestKind == PLAYER_MOUSE) {
    p->kind = PLAYER_MOUSE;
    p->updateCallback = Player_UpdateMouse;
    p->unk_359 = 1;
    p->mover.mainSprite = NULL, p->mover.auxSprite = &p->sprite_e8;
    p->unk_4c4.pos = &p->sprite_e8.pos;
    Player_SetPlttIDs(p);
    p->unk_94c = 0xFFFF;
    p->gfx_114->plttID = p->plttID_94a;
    p->plttID_95e = 290;
    p->unk_960 = 0x20;

  } else if (p->formRequestKind == PLAYER_SLEEPING) {
    p->kind = PLAYER_SLEEPING;
    p->updateCallback = Player_UpdateSleeping;
    p->unk_359 = 1;
    p->mover.mainSprite = NULL, p->mover.auxSprite = &p->sprite_e8;
    p->unk_4c4.pos = &p->sprite_e8.pos;
    Player_SetPlttIDs(p);
    p->unk_94c = 0xFFFF;
    p->gfx_114->plttID = p->plttID_94a;
    p->unk_388 = 0;
    p->unk_38a = 0;
    p->facing = 0;
    p->animIDOffset = 0;
    p->xflip = 0;

  } else {
    s32 enchant;
    if (p->kind != PLAYER_SLEEPING) {
      p->plttID_95e = 290;
      p->unk_960 = 0x20;
    }
    p->kind = PLAYER_DARK_DJANGO;
    p->updateCallback = Player_UpdateDjango;
    p->unk_359 = 0;
    p->mover.mainSprite = &p->sprite_88, p->mover.auxSprite = NULL;
    p->unk_4c4.pos = &p->sprite_88.pos;
    Player_SetPlttIDs(p);
    p->unk_94c = 0xFFFF;

    enchant = Player_CheckMagicEnchant(p) + 1;
    p->unk_951 = enchant;
    p->unk_950 = enchant + 1;
  }

  p->sprite_88.plttID = p->plttID_94a;
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

  frames = &gStat->weaponFrames[p->weaponKind];
  if (*frames <= 0x7FFFFFFE) {
    (*frames)++;
  }
#else
  INCFUNC("asm/func/Player_CountStyleFrames.inc");
#endif
}

NAKED void dark_django_0807f13c(Player* p) { INCFUNC("asm/func/dark_django_0807f13c.inc"); }

// unk_1c の状態ごとに更新を振り分け, 共通の後処理と範囲イベントの拾い上げまでを毎フレーム回す
static s32 Player_Update(Player* p) {
  Player_Update_Helper_0807dde4(p);
  Player_BeginAction(p);

  if (p->unk_1c == 1) {
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
      FUN_0807e854(p);
    } else {
      FUN_0807eca8(p);
      dark_django_0807f13c(p);
    }
  } else if (p->unk_1c == 2) {
    s32 n;

    Player_ClearInputHistory(p);
    if (p->hp == 0) {
      p->hp = 1;
    }
    p->damage = 0;
    p->hurtbox.unk_40 = 0;
    n = p->hurtbox.unk_44;
    if (n > 0) {
      p->hurtbox.unk_44 = 0;
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
    FUN_0807ed04(p);
  }

  if (p->unk_1c != 4) {
    p->zoneEvents.pos = &p->mover.pos;
    FUN_08234660(&p->zoneEvents);
  }
  return 0;
}

static s32 Player_Destroy(Player* p) {
  EnemyTargetManager_Remove(&p->target);
  MainSprite_Remove(&p->sprite_88);
  AuxSprite_Remove(&p->sprite_e8);
  Hitbox_Unregister(&p->hurtbox);
  Mover_Unlink(&p->mover);
  Player_DestroyEffects(p);
  FUN_0807ddd4(p);
  Player_StopEneChargeSound(p);
  gChangeWolfTarget = NULL;
  u16_03002bf4 = 0;
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
  FUN_0807ddbc(p);
  FUN_08065240(p);
  gPlayerPtr[(p->mover).unk_4] = p;
  gPlayerCount++;
  if ((p->mover).unk_4 == 0) {
    FUN_0807ed04(p);
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
