#include "player.h"

#include "armor.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "item.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "vm.h"

extern u16 u16_03002b64;
extern u16 u16_03002b74;
extern u16 u16_03002bb0;

s32 FUN_0805fe7c(HitboxData* hitbox, s32 param_2, s32 param_3, Vec3* pos, Vec3* param_5, s32 param_6);
bool32 FUN_0809e138(Player* p);
s32 GetMagicCategory(magic32_t id);
s32 FUN_080ddcc8(Vec3* pos, u8 param_2, Vec3* size, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8);
void FUN_0809c4f4(void);
s32 Eff082473e0Emitter_Init(Eff082473e0Emitter* e, Vec3* pos, s32 kind, s32 unk_4, s32 unk_5);
s32 FUN_082467d0(Eff082473e0Emitter* e, u32 unk_1, u32 param_3, u32* param_4);
magic32_t Player_CheckMagicEnchant(Player* p);
void dark_django_0806f990(HitboxData* a, HitboxData* b, void* _);
void* Entity080dc44c_Create(void);
extern u16 u16_03002b84;
extern u16 u16_03002b90;
extern u16 u16_03002bac;
extern u16 u16_03002bf0;
s32 MosaicFader_Start(s32 mode, s32 objEnabled, s32 targets, u8* from, u8* to, u16* interval);
s32 FUN_080da9c4(s32 param_1, Mover* mover, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8);
void FUN_08242a98(Weapon* w, WeaponData* data);
s32 FUN_0807a6cc(WeaponData* w);
void FUN_08071b14(Player* p);

const u8 u8_ARRAY_085abab4[4] = {3, 4, 6, 0};  // 0x085abab4

// --------------------------------------------

void FUN_0806fedc(Player* p);
void FUN_08070844(Player* p);
void FUN_0807106c(Player* p);
void FUN_080713a8(Player* p);
void gun_080715a0(Player* p);

const PlayerFunc gPlayerAttackUpdates[5] = {
    [WK_SWORD] = FUN_0806fedc,
    [WK_SPEAR] = FUN_08070844,
    [WK_HAMMER] = FUN_0807106c,
    [WK_OTHERS] = FUN_080713a8,
    [WK_GUN] = gun_080715a0,
};  // 0x085abab8

// --------------------------------------------

const u16 gMagicCosts[MAGIC_NUM] = {
    [MAGIC_SOL] = 5,
    [MAGIC_DARK] = 5,
    [MAGIC_FLAME] = 10,
    [MAGIC_FROST] = 10,
    [MAGIC_CLOUD] = 10,
    [MAGIC_EARTH] = 10,
    [MAGIC_TRANSFORM] = 0,
    [MAGIC_RISING_SUN] = 100,
    [MAGIC_UNK_8] = 10,
    [MAGIC_UNK_9] = 100,
    [MAGIC_FREEZE] = 0,
    [MAGIC_DASH] = 0,
    [MAGIC_HEALING] = 0,
    [MAGIC_DYNAMITE] = 0,
    [MAGIC_SLEEPING] = 0,
    [MAGIC_BAT] = 10,
    [MAGIC_RAT] = 10,
    [MAGIC_WOLF] = 10,
};  // 0x085abacc

// GetMagicCost での使い方的にこれも魔法の消費コストっぽいけど、いつ使うかわからん
const u16 gMagicUnkVal[MAGIC_NUM] = {
    [MAGIC_SOL] = 10,
    [MAGIC_DARK] = 0,
    [MAGIC_FLAME] = 5,
    [MAGIC_FROST] = 5,
    [MAGIC_CLOUD] = 5,
    [MAGIC_EARTH] = 5,
    [MAGIC_TRANSFORM] = 0,
    [MAGIC_RISING_SUN] = 0,
    [MAGIC_UNK_8] = 0,
    [MAGIC_UNK_9] = 0,
    [MAGIC_FREEZE] = 0,
    [MAGIC_DASH] = 1,
    [MAGIC_HEALING] = 2,
    [MAGIC_DYNAMITE] = 2,
    [MAGIC_SLEEPING] = 0,
    [MAGIC_BAT] = 0,
    [MAGIC_RAT] = 0,
    [MAGIC_WOLF] = 0,
};  // 0x085ABAF0

void Player_SetAnimFacing(Player* p) {
  u8 v = p->facing;

  if (v > 4) {
    p->animIDOffset = 8 - v;
    p->xflip = 1;
  } else {
    p->animIDOffset = v;
    p->xflip = 0;
  }
}

// sprite_88 に animIdx のアニメを設定して1フレーム進める, 前回と同じIDならコマ番号を引き継ぐ
// 命令数は57で一致, 残差は animIdx + animIDOffset の adds のオペランド順だけ (原典は adds r2, r1, r2)
// Tier A/B と複合代入・オペランド入れ替えは試済
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

// 行動を始める前のフラグ初期化, 日光と武器効果を見て unk_20 を組み立て直し各種タイマを 0 に戻す
// 残差1命令 (61/62): 原典は 0x2C8 を movs/lsls で作るが agbcc が 0x38E のレジスタから引き算で作ってしまう
// unk_2c8 の読み出しを「添字を引数に取る static inline」経由にすると 62/62 まで詰まり, 残差は r0/r1 の入れ替えと
// (gStat + idx*4) + 0x2C8 vs (gStat + 0x2C8) + idx*4 の結合順だけになる (名前の根拠がないので inline は入れていない)
// Tier A-C は試済
NON_MATCH void Player_BeginAction(Player* p) {
#ifdef NONMATCHING_C
  p->unk_20 = PFLAG20_UNK_0;
  if (gStat->unk_2c8[p->isSabata] == 0 && FUN_0809e138(p)) {
    Player_SetFlag20(p, PFLAG20_UNK_4);
  }
  if (Player_TestFlag378(p, FLAG378_SKULLSUIT)) {
    Player_SetFlag20(p, PFLAG20_UNK_16);
  }

  p->shadowOffset.x = 0, p->shadowOffset.y = 0, p->shadowOffset.z = 0;
  p->flag35a = 0;
  p->unk_16c.hitState &= ~2;
#else
  INCFUNC("asm/func/Player_BeginAction.inc");
#endif
}

void Player_SetFlag35a(Player* p, u32 val) { p->flag35a |= val; }

u32 Player_TestFlag35a(Player* p, u32 mask) { return p->flag35a & mask; }

// エネルギーチャージ音を止める
void Player_StopEneChargeSound(Player* p) {
  if (p->kind != PLAYER_SABATA) {
    sound_08240740(0xD8);
    return;
  }
  sound_08240740(0x239);
  sound_08240740(0x202);
  sound_08240740(0x366);
}

// 攻撃側 a から被弾側 b へ向かう向きを 1/3/5/7 の4象限に落として返す
u32 Player_GetHitDirIdx(HitboxData* a, HitboxData* b) {
  s32 angle;
  s32 dx;
  s32 dz;

  if (a->flags & HBFLAG_UNK_8) {
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

  if (Hitbox_TestAttribute(a, HBATTR_18)) {
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
    if (a->flags & HBFLAG_UNK_8) {
      p->unk_3e8 = ((((a->angle + 0x10) & 0xFF) >> 5) + 3) & 7;
    } else {
      s32 dx = a->center.x - b->center.x;
      s32 dz = a->center.z - b->center.z;

      if (dx == 0 && dz == 0) {
        p->unk_3e8 = p->facing;
      } else {
        p->unk_3e8 = (((((((u16)ArcTan2_8(dx, dz) + 0x10) & 0xFF) >> 5) + 3) & 7) + 4) & 7;
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

bool32 FUN_08060e1c(Player* p) {
  u32 span;

  if (*(p->isSabata + gStat->unk_2c8) > 0) return TRUE;
  if (Player_TestFlag378(p, FLAG378_ALLNIGHT)) return TRUE;

  span = Time_GetSpanOfTime();
  if (span >= TIME_UNK4 && span <= TIME_UNK5) return TRUE;
  if (span != TIME_NIGHT) return FALSE;

  return TRUE;
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

void FUN_08060ec8(Player* p, u32 r1) { p->unk_9bc |= r1; }

u32 FUN_08060ed8(Player* p, u32 r1) { return p->unk_9bc & r1; }

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
      p->stats[i] = gStat->stats[i] + gStat->stats[i + STAT_KINDS];
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
      p->stats[i] = gStat->stats[i + STAT_KINDS] + base;
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

s32 CalcMaxHP(Player* p) {
  s32 val;
  PlayerArmor* armor = &p->armor;
  if (p->kind == PLAYER_SOLAR_DJANGO) {
    val = (p->stats[STAT_VITALITY] + armor->bonus[STAT_VITALITY]) + armor->bonus2[STAT_VITALITY];
  } else {
    val = (p->stats[STAT_VITALITY] + armor->bonus[STAT_VITALITY]) - armor->bonus2[STAT_VITALITY];
  }
  if (99 < val) {
    val = 99;
  }
  return val * 10;
}

s32 CalcMaxEne(Player* p) {
  s32 val;
  PlayerArmor* armor = &p->armor;
  if (gFlag030047a4 & FLAG030047A4_UNK_12) {
    return 10;
  }

  if (p->kind == PLAYER_SOLAR_DJANGO) {
    val = (p->stats[STAT_SPIRIT] + armor->bonus[STAT_SPIRIT]) + armor->bonus2[STAT_SPIRIT];
  } else {
    val = (p->stats[STAT_SPIRIT] + armor->bonus[STAT_SPIRIT]) - armor->bonus2[STAT_SPIRIT];
  }
  if (99 < val) {
    val = 99;
  }
  return val * 5 + 100;
}

void UpdateMaxHPEne(Player* p) {
  s32 maxHP, maxEne;

  maxHP = CalcMaxHP(p);
  p->maxHP = maxHP;
  if (p->hp > (u16)maxHP) p->hp = maxHP;

  maxEne = CalcMaxEne(p);
  p->maxEne = maxEne;
  if (p->ene > (u16)maxEne) p->ene = maxEne;
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

// 攻撃力と属性を当たり判定に設定する, レベルとチカラの平均に鎧の値を足した値が攻撃力になる
// 命令数は107で一致, 残差はレジスタ割当だけ: 原典は armor を r5, lv を r4, special を r3 (caller-saved) に置くが
// こちらは armor を r4, special を call-saved の r5 に取る. PlayerArmor を 0x27A まで広げて命令数は揃った, Tier A/B は試済
NON_MATCH void Player_RefreshAttackPower(Player* p) {
#ifdef NONMATCHING_C
  PlayerArmor* armor = &p->armor;
  s32 lv;
  s32 power;
  HitboxAttributes attrs;
  u32 weakness;
  bool32 special;

  if (p->kind == PLAYER_SABATA) {
    lv = gStat->lv + 10;
    if (lv > 99) {
      lv = 99;
    }
    power = p->stats[3];
    attrs = p->hbattrs | HBATTR_DARK;
    weakness = 1;
  } else {
    lv = gStat->lv;
    if (p->kind == PLAYER_SOLAR_DJANGO) {
      power = p->stats[3] + armor->bonus[3] + armor->bonus2[3];
      attrs = p->hbattrs | HBATTR_SOL;
      weakness = 2;
    } else {
      power = p->stats[3] + armor->bonus[3] - armor->bonus2[3];
      attrs = p->hbattrs | HBATTR_DARK;
      weakness = 1;
    }
  }

  special = FALSE;
  if (p->unk_446 != 0 && p->unk_442 == 8) {
    special = TRUE;
  }
  if (special || p->hbattrs == HBATTR_6) {
    attrs = HBATTR_6;
  }

  if (power > 99) {
    power = 99;
  }
  power = ((power + lv) >> 1) + armor->defence;
  if (p->kind == PLAYER_SABATA) {
    u16_03002b74 = power;
  }

  Hitbox_SetPowerAndAttributes(&p->unk_16c, power, attrs, weakness);
#else
  INCFUNC("asm/func/Player_RefreshAttackPower.inc");
#endif
}

void FUN_08061294(Player* p) {
  Player_RefreshHpEne(p);
  Player_RefreshAttackPower(p);
}

void FUN_080612a8(Player* p) {
  UpdateMaxHPEne(p);
  Player_RefreshAttackPower(p);
}

void FUN_080612bc(Player* p) {
  Player_RefreshStats(p);
  UpdateMaxHPEne(p);
  Player_RefreshAttackPower(p);
}

// 足元の判定を1つ出す, コウモリ/ネズミ姿は補助スプライトの位置と小さめの大きさを使う
void Player_SpawnFootHitbox(Player* p) {
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

  FUN_080ddcc8(&pos, 1, &size, 0, 0, 0xC, 2, 2);
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
  p->sprite.metaspriteIdx = *cmd >> 6;

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

// 黒ジャンゴが剣で攻撃する時に1回呼ばれる, idx はプレイヤーの向きで変わる (多分、 衝撃波 を出す処理)
// 黒ジャンゴが剣で攻撃する時に1回呼ばれる, 衝撃波を向きに応じてずらして出す
// 残差7命令 (130/123): 原典は idx を r6 に置いたまま回せているが, こちらはレジスタが足りず ip に退避してしまう
// 直接の原因は gSineTable のポインタを `adds r6, r2, #0` で call-saved に写してしまうこと (原典は r2 のまま使い回す)
// sprite ローカルの除去・PlayerShockwave* 化・gSineTable のローカル化はいずれも逆に遠ざかる
// gSineTable のローカル化は原典と逆 (原典は初回参照時に作る) で効かなかった, Tier A/B は試済
NON_MATCH void Player_SpawnSwordShockwave(Player* p, u32 idx, Vec3* pos) {
  AuxSprite* sprite = &p->meleeShockwave.sprite;
  s32 angle = ((p->facing + 5) & 7) * 32;
  s32 v;
  s32 offset;
  s32 variant;
  s32 flags;

#ifdef NONMATCHING_C
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

// 黒ジャンゴが槍で攻撃する時に1回呼ばれる, idx はプレイヤーの向きで変わる (多分、 衝撃波 を出す処理)
// 黒ジャンゴが槍で攻撃する時に1回呼ばれる, n で衝撃波の高さと前に出る距離が変わる
// 残差7命令 (140/133): Player_SpawnSwordShockwave と同じレジスタ圧の差
NON_MATCH void Player_SpawnSpearShockwave(Player* p, u32 idx, Vec3* pos, s32 n) {
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
#ifdef NONMATCHING_C
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
  s32 sin;
  s32 offset;

  sprite->pos = *pos;

  sin = gSineTable[(angle + 0x40) & 0xFF] * 180;
  if (sin >= 0) {
    offset = sin >> 12;
  } else {
    offset = -((-sin) >> 12);
  }
  sprite->pos.x += offset;

  sin = gSineTable[angle] * 180;
  if (sin >= 0) {
    offset = sin >> 12;
  } else {
    offset = -((-sin) >> 12);
  }
  sprite->pos.z += offset;

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
  p->meleeShockwave.sprite.rotation = p->unk_a8a;
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
    sprite->metaspriteIdx = 4;
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

    Particle_Add(&ptcl->base, st->group, 1);
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

    Particle_Add(&ptcl->base, st->group, 1);
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
    if (Player_TestFlag20(p, PFLAG20_UNK_4)) {
      r = 4;
    }
  } else {
    if (Player_TestFlag20(p, PFLAG20_UNK_4)) {
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
      src = &gObjPlttData[p->unk_95e * 16];
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
      src = &gObjPlttData[p->unk_95e * 16];
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
      src = &gObjPlttData[p->unk_95e * 16];
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

    src = &gObjPlttData[p->unk_95e * 16];
    w = p->unk_960;
    Player_BlendPltt(p, src, w, 0x20 - w, 5);
    p->unk_960++;
    return;
  }

  if (p->unk_96c == 2) {
    rgb555* src;
    s32 w;

    p->unk_964 = 0;
    src = &gObjPlttData[p->unk_95e * 16];
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
      src = &gObjPlttData[p->unk_95e * 16];
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
      src = &gObjPlttData[p->unk_95e * 16];
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
  if (p->unk_18 == 0) {
    p->plttID_94a = 29;
  } else {
    p->plttID_94a = 40;
  }
}

// ロックマンコラボの鎧を装備すると、プレイヤーのパレットIDが対応するものに変更される
// 例: ロックパワー(FLAG378_MEGAPOWER) は ロックマンと同じ青色
void Player_SetPlttIDs(Player* p) {
  switch (p->kind) {
    case PLAYER_SOLAR_DJANGO: {
      if (Player_TestFlag378(p, FLAG378_MEGAPOWER)) {
        p->plttIDs[0] = 296;
      } else if (Player_TestFlag378(p, FLAG378_GUTSPOWER)) {
        p->plttIDs[0] = 297;
      } else if (Player_TestFlag378(p, FLAG378_PROTOPOWER)) {
        p->plttIDs[0] = 298;
      } else if (Player_TestFlag378(p, FLAG378_TOADPOWER)) {
        p->plttIDs[0] = 299;
      } else {
        p->plttIDs[0] = 29;
      }
      p->plttIDs[1] = 289, p->plttIDs[2] = 32, p->plttIDs[3] = 291, p->plttIDs[4] = 292, p->plttIDs[5] = 31, p->plttIDs[6] = 33, p->plttIDs[7] = 30;
      break;
    }
    case PLAYER_DARK_DJANGO: {
      if (Player_TestFlag378(p, FLAG378_MEGAPOWER)) {
        p->plttIDs[0] = 296;
      } else if (Player_TestFlag378(p, FLAG378_GUTSPOWER)) {
        p->plttIDs[0] = 297;
      } else if (Player_TestFlag378(p, FLAG378_PROTOPOWER)) {
        p->plttIDs[0] = 298;
      } else if (Player_TestFlag378(p, FLAG378_TOADPOWER)) {
        p->plttIDs[0] = 299;
      } else {
        p->plttIDs[0] = 38;
      }
      p->plttIDs[1] = 289, p->plttIDs[2] = 32, p->plttIDs[3] = 291, p->plttIDs[4] = 292, p->plttIDs[5] = 31, p->plttIDs[6] = 33, p->plttIDs[7] = 30;
      break;
    }
    case PLAYER_BAT: {
      if (Player_TestFlag378(p, FLAG378_MEGAPOWER)) {
        p->plttIDs[0] = 623;
      } else if (Player_TestFlag378(p, FLAG378_GUTSPOWER)) {
        p->plttIDs[0] = 624;
      } else if (Player_TestFlag378(p, FLAG378_PROTOPOWER)) {
        p->plttIDs[0] = 622;
      } else if (Player_TestFlag378(p, FLAG378_TOADPOWER)) {
        p->plttIDs[0] = 625;
      } else {
        p->plttIDs[0] = 614;
      }
      p->plttIDs[1] = 621, p->plttIDs[2] = 619, p->plttIDs[3] = 616, p->plttIDs[4] = 617, p->plttIDs[5] = 618, p->plttIDs[6] = 620, p->plttIDs[7] = 615;
      break;
    }
    case PLAYER_MOUSE: {
      if (Player_TestFlag378(p, FLAG378_MEGAPOWER)) {
        p->plttIDs[0] = 296;
      } else if (Player_TestFlag378(p, FLAG378_GUTSPOWER)) {
        p->plttIDs[0] = 297;
      } else if (Player_TestFlag378(p, FLAG378_PROTOPOWER)) {
        p->plttIDs[0] = 298;
      } else if (Player_TestFlag378(p, FLAG378_TOADPOWER)) {
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
    PlaySound_082406e0(0x134);
  } else if (p->unk_4c4.kind == 3) {
    PlaySound_082406e0(0x134);
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
  if (FUN_082467d0(&p->unk_4c4, kind, 0xE10, (u32*)&spread) >= 0) {
    if (p->unk_4c4.kind == 1) {
      PlaySound_082406e0(0x191);
    } else if (p->unk_4c4.kind == 2) {
      p->unk_376 += 10;
      PlaySound_082406e0(0x133);
    } else if (p->unk_4c4.kind == 3) {
      PlaySound_082406e0(0x133);
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
    case 0: {
      break;
    }
    case 1: {
      if (p->unk_4c4.unk_3 != 0) {
        if (p->unk_4c4.kind == 3) {
          break;
        }
        FUN_08063220(p);
      }
      if (p->badCondTimer[1] == 0) {
        p->unk_3d8 = 0;
      }
      break;
    }
    case 2: {
      if (p->badCondTimer[2] == 0) {
        gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
        u16_03002b64 = (p->controlUp + 1 + Mod(gRandomTable[gRandTableIdx], 7)) & 7;
        p->controlUp = u16_03002b64;
        PlaySound_082406e0(0x138);
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

void FUN_08063634(Player* p, s32 n) {
  p->badCondTimer[n] = 0;
  if (n == 2) {
    p->controlUp = gStat->controlUp;
  }
}

// 太陽ゲージの消費と状態異常の残り時間を1フレーム進め, その結果で姿勢番号を上書きして返す
// 残差6命令 (166/160): gStat の読み出しと isSabata のオフセット計算の順序 (Player_BeginAction と同じ系統)
NON_MATCH u32 Player_TickBadCondTimers(Player* p, u32 n) {
#ifdef NONMATCHING_C
  s32 i;

  if (gStat->unk_2c8[p->isSabata] > 0) {
    if (p->unk_1c & 1) {
      if (gStat->unk_2c8[p->isSabata] > gStat->sunGauge) {
        gStat->unk_2c8[p->isSabata] -= gStat->sunGauge;
      } else {
        gStat->unk_2c8[p->isSabata] = 0;
      }
    }
    n = 6;
    p->unk_958 = 0x40;
  } else if (p->unk_958 != 0) {
    if ((p->unk_958 >> 2) & 1) {
      n = 6;
    }
    p->unk_958--;
  }

  for (i = 0; i < 3; i++) {
    switch (i) {
      case 0: {
        if (p->badCondTimer[0] != 0 && (p->unk_1c & 1)) {
          p->badCondTimer[0]--;
          if (p->input->down & 0xF0) {
            MosaicFader_Start(2, 1, 0x1E, p->unk_97c, p->unk_980, p->unk_984);
          }
        }
        break;
      }
      case 1: {
        if (p->badCondTimer[1] != 0) {
          if (p->unk_1c & 1) {
            p->badCondTimer[1]--;
          }
          n = 2;
          p->unk_956 = 0x40;
        } else if (p->unk_956 != 0) {
          if ((p->unk_956 >> 2) & 1) {
            n = 2;
          }
          p->unk_956--;
        }
        break;
      }
      case 2: {
        if (p->badCondTimer[2] != 0 && (p->unk_1c & 1)) {
          p->badCondTimer[2]--;
          if (p->badCondTimer[2] == 0) {
            p->controlUp = gStat->controlUp;
          }
        }
        break;
      }
    }
  }

  return n;
#else
  INCFUNC("asm/func/Player_TickBadCondTimers.inc");
#endif
}

// flashTimer が動いている間, 4フレームごとに pose を flashPose と入れ替える (点滅)
// 残差は共有された return pose のブロック位置だけ (23/23), Tier A の分岐形 4通りと Tier B は試済, player_link.c の LinkPlayer_ApplyFlashPose も同じ残差
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

// 変身の拡縮演出を1フレーム進める, unk_442 が 5 の間は縮み, それ以外では元の大きさへ戻る
// 残差4命令 (186/190): レジスタ割当 (原典は p を r4) と定数の作り直し
// 分岐の並び (unk_446 != 0 を先) は原典と一致した, Tier A/B は試済
NON_MATCH void Player_UpdateFormScale(Player* p) {
#ifdef NONMATCHING_C
  s32 scale;

  if (p->unk_446 != 0) {
    if (p->unk_442 == 5) {
      if (p->unk_97a <= 0x3F) {
        if (p->unk_97a == 0) {
          PlaySound_082406e0(0x1EE);
          p->unk_3f1[0] = 1;
        }
        p->unk_97a++;
      }

      p->sprite_88.flags |= SPRFLAG_AFFINE;
      scale = 0x40 - (p->unk_97a >> 1);
      p->sprite_88.scaleX = scale;
      p->sprite_88.scaleY = scale;
      p->unk_20 |= 0x50000;
    } else if (p->unk_97a != 0) {
      if (p->unk_3f1[0] != 0) {
        PlaySound_082406e0(0x336);
        p->unk_3f1[0] = 0;
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

    if (p->unk_442 == 6) {
      p->sprite_88.flags |= SPRFLAG_BLINK_ODD;
      p->unk_20 |= 0x20000;
    } else {
      p->sprite_88.flags &= ~SPRFLAG_BLINK_ODD;
    }

    if (p->unk_1c & 1) {
      p->unk_446--;
    }
  } else {
    if (p->unk_97a != 0) {
      if (p->unk_3f1[0] != 0) {
        PlaySound_082406e0(0x336);
        p->unk_3f1[0] = 0;
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
// 命令数は119で一致, 残差は gStat->unk_2c8[isSabata] のアドレス計算の順序だけ (Player_BeginAction と同じ系統)
// 添字を引数に取る static inline 経由にすると ldrb が先に出る形までは揃うが, +0x2C8 の結合順が残る
NON_MATCH void Player_UpdatePoseAndShadow(Player* p) {
#ifdef NONMATCHING_C
  s32 pose = 0;

  if (p->mover.unk_4 == 0) {
    Player_UpdateFormScale(p);
    FUN_080639d0(p);
    pose = Player_TickBadCondTimers(p, 0);
    pose = Player_ApplyPoseHold(p, pose);
    pose = Player_ApplyFlashPose(p, pose);
  } else if (gStat->unk_2c8[p->isSabata] > 0) {
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
      p->unk_98c = FUN_080da9c4(p->unk_98c, &p->mover, p->unk_990, 0x7F, 0, 0, 0, 0x50);
    }
  }

  p->shadowPos.x = p->shadowOffset.x + p->mover.pos.x;
  p->shadowPos.y = p->shadowOffset.y + p->mover.pos.y;
  p->shadowPos.z = p->shadowOffset.z + p->mover.pos.z;
#else
  INCFUNC("asm/func/Player_UpdatePoseAndShadow.inc");
#endif
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

  valid = p->unk_446 != 0 && p->unk_442 == 5;
  if (valid) {
    p->unk_97a = 0x40;
    p->unk_3f1[0] = 1;
  }

  Player_ResetPltt(p);
  FUN_08061458(p);
  FUN_0806161c(p);
  Player_InitPtcl718(p);
  Player_InitPtcl858(p);
  Player_InitShockwave(p);

  p->unk_97c[0] = 4;
  p->unk_97c[1] = 4;
  p->unk_97c[2] = 4;
  p->unk_97c[3] = 4;
  p->unk_980[0] = 0;
  p->unk_980[1] = 0;
  p->unk_980[2] = 0;
  p->unk_980[3] = 0;
  p->unk_984[0] = 4;
  p->unk_984[1] = 4;
  p->unk_984[2] = 4;
  p->unk_984[3] = 4;
  p->unk_978 = 0;
  p->pos_970.x = 0;
  p->pos_970.y = 0;
  p->pos_970.z = 0;
  u16_03002bac = 0;
  u16_03002b90 = 0;
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

  if (*(p->isSabata + gStat->unk_2c8) != 0) return 10;
  if (p->unk_4c4.unk_3 != 0) return 10;

  return 0;
}

u32 Player_WeaponEffectNight(Player* p) {
  if (FUN_08060e1c(p)) {
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

// 同じ種族の敵をたくさん倒しているほど威力が上がる
// 相手の系統に応じた撃破数ボーナス (撃破数/64, 最大10) を返す, 系統が付いていなければ 0
u32 Player_WeaponEffectKillCount(Player* p, HitboxData* a, HitboxData* b) {
  s32 n;

  if (Hitbox_TestAttribute(b, HBATTR_BEAST)) {
    n = (s16)gStat->killCounts[0] >> 6;
    if (n > 10) {
      n = 10;
    }
    return n;
  }
  if (Hitbox_TestAttribute(b, HBATTR_THING)) {
    n = (s16)gStat->killCounts[1] >> 6;
    if (n > 10) {
      n = 10;
    }
    return n;
  }
  if (Hitbox_TestAttribute(b, HBATTR_PHANTOM)) {
    n = (s16)gStat->killCounts[2] >> 6;
    if (n > 10) {
      n = 10;
    }
    return n;
  }
  if (Hitbox_TestAttribute(b, HBATTR_UNDEAD)) {
    n = (s16)gStat->killCounts[3] >> 6;
    if (n > 10) {
      n = 10;
    }
    return n;
  }
  if (Hitbox_TestAttribute(b, HBATTR_IMMORTAL)) {
    n = (s16)gStat->killCounts[4] >> 6;
    if (n > 10) {
      n = 10;
    }
    return n;
  }

  return 0;
}

// 一定確率で追加ダメージ 10
u32 Player_WeaponEffectRandom(Player* p, HitboxData* a, HitboxData* b) {
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  if (Mod(*(gRandomTable + gRandTableIdx), 100) <= 10) {
    return 10;
  }

  return 0;
}

u32 Player_WeaponEffectAntiBeast(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(b, HBATTR_BEAST)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiThing(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(b, HBATTR_THING)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiPhantom(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(b, HBATTR_PHANTOM)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiUndead(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(b, HBATTR_UNDEAD)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectAntiImmortal(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(b, HBATTR_IMMORTAL)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectFlame(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(a, HBATTR_FLAME)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectFrost(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(a, HBATTR_FROST)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectCloud(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(a, HBATTR_CLOUD)) {
    return 10;
  }
  return 0;
}

u32 Player_WeaponEffectEarth(Player* p, HitboxData* a, HitboxData* b) {
  if (Hitbox_TestAttribute(a, HBATTR_EARTH)) {
    return 10;
  }
  return 0;
}

// 一定確率で防御無視(なまくら系の特殊効果)
u32 CheckNamakuraProc(Player* p) {
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  if (Mod(*(gRandomTable + gRandTableIdx), 100) <= 10) {
    return 1 << 12;
  }
  return 0;
}

// 一定確率で麻痺
u32 CheckParalyzeProc(Player* p) {
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  if (Mod(*(gRandomTable + gRandTableIdx), 100) <= 10) {
    return 1 << 19;
  }
  return 0;
}

// ブラッドソードの吸収, 通常状態でジャンゴなら unk_376 を増やし, それ以外なら HP を1回復して判定を出す
void Player_UpdateBloodSword(Player* p) {
  if (p->unk_1c != 1 || !Player_TestFlag378(p, FLAG378_BLOOD_SWORD)) {
    return;
  }

  if (p->kind == PLAYER_SOLAR_DJANGO) {
    if (p->hp <= 1) {
      return;
    }
    p->unk_376++;
  } else {
    if (p->hp >= p->maxHP) {
      return;
    }
    p->hp++;
    FUN_0805fe7c(&p->unk_16c, 1, 1, &p->mover.pos, &p->pos_970, p->unk_978);
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
  Player_ClearFlag378(p, FLAG378_WET_DURABILITY | FLAG378_WET_ENE_COST | FLAG378_BLOOD_SWORD | FLAG378_ASTRO);

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
        Player_SetFlag378(p, FLAG378_WET_DURABILITY);
        break;
      }
      case WET_ENE_COST: {
        Player_SetFlag378(p, FLAG378_WET_ENE_COST);
        break;
      }
      case WET_BLOOD_SWORD: {
        Player_SetFlag378(p, FLAG378_BLOOD_SWORD);
        break;
      }
      case WET_ASTRO_SWORD: {
        Player_SetFlag378(p, FLAG378_ASTRO);
        p->unk_a95 = 0;
        break;
      }
      case WET_ASTRO_SPEAR: {
        Player_SetFlag378(p, FLAG378_ASTRO);
        p->unk_a95 = 4;
        break;
      }
      case WET_ASTRO_HAMMER: {
        Player_SetFlag378(p, FLAG378_ASTRO);
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
    Hitbox_Init(hitbox, 0, 0x2101, 0, (0x10000 << p->mover.unk_4) >> 16, &halfSize, &offset);
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

  Hitbox_Init(hitbox, 0, 0x2101, 0, (0x10000 << p->mover.unk_4) >> 16, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, p->totalAtk_a7a, p->unk_a7c, attrs, 0, p->unk_a7e);
  Hitbox_SetHandler(hitbox, dark_django_0806f990, p);
#else
  INCFUNC("asm/func/Player_SetWeaponHitbox.inc");
#endif
}

void FUN_08064658(Player* p, Weapon* w) { p->weapon_a70 = w; }

// 装備中の武器の情報を Player に展開する, サバタはガンデルヘル (WEAPON_GUN_DEL_HELL) 固定
void Player_ApplyWeapon(Player* p, Weapon* w) {
  WeaponData wd;

  if (p->kind != PLAYER_SABATA) {
    FUN_08064658(p, w);
    if (p->weapon_a70 == NULL) {
      wd = gWeaponDB[WEAPON_NONE];
    } else {
      FUN_08242a98(p->weapon_a70, &wd);
    }
  } else {
    p->weapon_a70 = NULL;
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
    p->attackCB = gPlayerAttackUpdates[p->weaponKind];
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

  if (Player_TestFlag378(p, FLAG378_WEAPONGUARD)) {
    p->unk_a10.damage = 0;
    return;
  }

  if (p->weaponKind <= 2) {
    if (Player_TestFlag378(p, FLAG378_WET_DURABILITY)) {
      wear >>= 1;
    }

    if ((s8)p->weapon_a70->quality > 0) {
      p->weapon_a70->wear += wear;
      if (p->weapon_a70->wear >= 200) {
        p->weapon_a70->quality--;
        p->weapon_a70->wear = 0;
        FUN_0809c4f4();
        Player_ApplyWeapon(p, p->weapon_a70);
      }
    } else if (*(u8*)&p->weapon_a70->effects[2] != 0) {
      p->weapon_a70->wear += wear;
      if (p->weapon_a70->wear >= 2000) {
        *(u8*)&p->weapon_a70->effects[2] = 0;
        p->weapon_a70->wear = 0;
        FUN_0809c4f4();
        Player_ApplyWeapon(p, p->weapon_a70);
      }
    } else if (*(u8*)&p->weapon_a70->effects[1] != 0) {
      p->weapon_a70->wear += wear;
      if (p->weapon_a70->wear >= 2000) {
        *(u8*)&p->weapon_a70->effects[1] = 0;
        p->weapon_a70->wear = 0;
        FUN_0809c4f4();
        Player_ApplyWeapon(p, p->weapon_a70);
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
// flag378 のアドレスをローカルに持つのが効いている (持たないと 270 命令), Tier A/B は試済
NON_MATCH void Player_ApplyArmorEffect(Player* p, const ArmorData* a) {
#ifdef NONMATCHING_C
  PlayerFlag378* flags = &p->flag378;
  s32 i;

  p->hbattrs = 0;
  for (i = 0; i < STAT_KINDS; i++) {
    p->armor.bonus[i] = 0;
    p->armor.bonus2[i] = 0;
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
        p->armor.bonus2[i] = a->value;
      }
      break;
    }
    case AET_BLOOD_CAPE: {
      for (i = 0; i < STAT_KINDS; i++) {
        p->armor.bonus2[i] = -a->value;
      }
      break;
    }
    case AET_STR: {
      p->armor.bonus[STAT_STRENGTH] = a->value;
      break;
    }
    case AET_SOLAR_WIND: {
      *flags |= FLAG378_SOLAR_WIND;
      break;
    }
    case AET_RES_SOL: {
      p->hbattrs = HBATTR_SOL;
      *flags |= FLAG378_AET_RES_SOL;
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
      p->hbattrs = HBATTR_6;
      break;
    }
    case AET_FAIRY_ROBE: {
      *flags |= FLAG378_FAIRY;
      break;
    }
    case AET_EARTHLY_ROBE: {
      *flags |= FLAG378_EARTHLYROBE;
      break;
    }
    case AET_RAIN_COAT: {
      break;
    }
    case AET_SUNLIGHT: {
      *flags |= FLAG378_AET_SUNLIGHT;
      break;
    }
    case AET_ALLNIGHT: {
      *flags |= FLAG378_ALLNIGHT;
      break;
    }
    case AET_MAGIC_COST: {
      *flags |= FLAG378_MAGICROBE;
      break;
    }
    case AET_SKULL_SUIT: {
      *flags |= FLAG378_SKULLSUIT;
      break;
    }
    case AET_EXP_BOOST: {
      *flags |= FLAG378_TRAININGGEAR;
      break;
    }
    case AET_NORMAL_DROP: {
      *flags |= FLAG378_AET_NORMAL_DROP;
      break;
    }
    case AET_RARE_DROP: {
      *flags |= FLAG378_AET_RARE_DROP;
      break;
    }
    case AET_IMMUNE_POISON: {
      *flags |= FLAG378_IMMUNEPOISON;
      break;
    }
    case AET_WEAPON_GUARD: {
      *flags |= FLAG378_WEAPONGUARD;
      break;
    }
    case AET_PARADE: {
      *flags |= FLAG378_PARADE;
      break;
    }
    case AET_AGILITY: {
      p->armor.bonus[STAT_AGILITY] = a->value;
      break;
    }
    case AET_SPIKE: {
      *flags |= FLAG378_SPIKE;
      break;
    }
    case AET_BLACK_ARMOR: {
      *flags |= FLAG378_UNK_19;
      break;
    }
    case AET_MEGA_POWER: {
      *flags |= FLAG378_MEGAPOWER;
      break;
    }
    case AET_GUTS_POWER: {
      *flags |= FLAG378_GUTSPOWER;
      break;
    }
    case AET_PROTO_POWER: {
      *flags |= FLAG378_PROTOPOWER;
      break;
    }
    case AET_TOAD_POWER: {
      *flags |= FLAG378_TOADPOWER;
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
  FUN_080612bc(p);
}

void CheckHeartJokerEmblem(Player* p) {
  if (CheckItemOwn(ITEM_HEART_EMBLEM)) {
    Player_SetFlag378(p, FLAG378_HEART);
  }

  if (CheckItemOwn(ITEM_JOKER_EMBLEM)) {
    Player_SetFlag378(p, FLAG378_JOKER);
  }
}

static s32 GetMagicCost(magic32_t id) {
  if (gFlag030047a4 & FLAG030047A4_UNK_12) {
    return gMagicUnkVal[id];
  } else {
    return gMagicCosts[id];
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
  if (Player_TestFlag378(p, FLAG378_MAGICROBE)) {  // マジックローブ装備時
    pct = 80;                                      // 本来は ArmorData.value の値を見るのが正しい処理と思われるが 20% 削減で固定されている
  }
  if (p->magic.id <= MAGIC_EARTH && Player_TestFlag378(p, FLAG378_WET_ENE_COST)) {
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

  if (p->magic.id <= MAGIC_EARTH && Player_TestFlag378(p, FLAG378_ASTRO)) {
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

  if (p->magic.id <= MAGIC_EARTH && Player_TestFlag378(p, FLAG378_ASTRO)) {
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

bool32 FUN_08064d6c(Player* p, s32 val) {
  if (*(p->isSabata + gStat->unk_2c8) > 0) return FALSE;
  if (gStat->sunGauge < val) return FALSE;

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
            p->unk_979 = 1;
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
        if (id == MAGIC_RISING_SUN || id == MAGIC_UNK_9) {
          return 9;
        }
        if (id == MAGIC_UNK_8) {
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
    p->unk_979 = 0;
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
        p->unk_979 = 1;
        p->unk_964 = 0x20;
        p->unk_962 = m->id + 0x121;
        p->unk_951 = m->id + 1;
      }
      return;
    }

    m->enchanted = FALSE;
    p->unk_979 = 0;
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
  if (gStat->unk_5e == 0) return MAGIC_UNK_8;

  return MAGIC_UNK_9;
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
