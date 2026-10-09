#include "armor.h"
#include "camera.h"
#include "coffin_immortal.h"
#include "collision_map.h"
#include "global.h"
#include "input.h"
#include "player.h"
#include "solar.h"
#include "sound.h"
#include "vm.h"
#include "weapon.h"

// player.c とファイルを分けてるのは、ファイルサイズが大きくなりすぎてコードを把握しにくいからで、解析が進んだら整理する予定

void Player_RefreshMagicInfo(Player* p);
extern const u16 u16_ARRAY_085abf4c[3];
extern u16 u16_ARRAY_03002ba0[3];
extern u16 u16_03002b60;
extern u16 u16_03002b64;
extern u16 u16_03002b7c;
extern u16 u16_03002b8c;
void Player_RefreshStats(Player* p);  // src/player.c
bool32 IsMagicUnlocked(magic32_t n);  // src/equip_magic.c
void Player_SetPlttIDs(Player* p);    // src/player.c
void FUN_08079f1c(Player* p);
extern u16 u16_03002b78;
extern u16 u16_03002bd0;
void Player_SpawnFootHitbox(Player* p);
bool32 Player_PlayAnim(Player* p, u32 animID, s32 param_3);
void Player_SetAnimFacing(Player* p);  // facing から animIDOffset と xflip を決める
s32 FUN_08086294(Vec3* pos, u32 a, u32 b);
void Player_StopEneChargeSound(Player* p);
magic32_t Player_CheckMagicEnchant(Player* p);
void FUN_08072724(Player* p);
void FUN_0823bca8(s32 n);
s32 FUN_080da9c4(s32 param_1, Mover* mover, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8);
void FUN_08240cf0(s32 x, s32 z, s16 param_3, s32 param_4, u8 param_5, u16 param_6);
void Player_ShowPtcl64c(Player* p, Vec3* pos, s32 val);
void FUN_0807e854(Player* p);
void FUN_08063220(Player* p);
void Player_ApplyBadCondition(Player* p, s32 badcondID, s32 frames);
void FUN_08063634(Player* p, s32 n);
void FUN_080ec79c(u8 kind, void* payload);
void Player_SetFlag35a(Player* p, u32 val);
bool32 FUN_0809f658(Vec3* pos);
void FUN_080d040c(Player* p);
extern void* ptr_03002ba8;
extern u16 u16_03002bf4;
void EnemyTargetManager_Remove(unknown* node);
void Player_DestroyEffects(Player* p);
void FUN_0807bdc8(Player* p, s32 param_2, s32 param_3, u32 param_4);
void FUN_08060ec8(Player* p, u32 bits);
u32 FUN_08060ed8(Player* p, u32 bits);
bool32 Player_IsMagicAvailableForm(Player* p, magic32_t id);
void CheckHeartJokerEmblem(Player* p);
void FUN_08061294(Player* p);
void Player_InitEffects(Player* p);
void FUN_0807ddbc(Player* p);
void FUN_08066f7c(Player* p);
void FUN_080672b0(Player* p);
void MagicDash_0806734c(Player* p);
bool32 FUN_080674dc(Player* p);
void FUN_08067510(Player* p);
void FUN_08067de8(Player* p);
bool32 FUN_08067f58(Player* p);
void FUN_08067f88(Player* p);
void FUN_08067ffc(Player* p);
bool32 FUN_080682dc(Player* p);
void FUN_0806830c(Player* p);
void FUN_08068624(Player* p);
void MagicRisingSun_08068944(Player* p);
void MagicTransform_0806b92c(Player* p);
void MagicChangeWolf_0806eb40(Player* p);
void MagicChangeBat_0806bc74(Player* p);
void MagicChangeMouse_0806bf18(Player* p);
void MagicSleeping_0806c124(Player* p);
void MagicFreeze_08069710(Player* p);
void MagicHealing_08069928(Player* p);
void MagicDynamite_08069b18(Player* p);
void FUN_08069c8c(Player* p);
void FUN_0806961c(Player* p);
void FUN_08069648(Player* p);
void FUN_080695ec(Player* p);
void FUN_08069218(Player* p);
void FUN_0806a050(Player* p);
void FUN_08069d70(Player* p);
void FUN_08069f60(Player* p);
void FUN_0806a084(Player* p);
void FUN_0806a32c(Player* p);
void FUN_0806a628(Player* p);
void FUN_0806a88c(Player* p);
void FUN_0806abd4(Player* p);
void FUN_0806adc8(Player* p);
void FUN_0806af70(Player* p);
void FUN_0806f1ec(Player* p);
void FUN_0806b06c(Player* p);
void FUN_0806b758(Player* p);
void FUN_0806b374(Player* p);
void FUN_08072014(Player* p);
void FUN_08067510(Player* p);
void FUN_08067de8(Player* p);
void Sabata_BlackSun(Player* p);
void FUN_0806c2dc(Player* p);
void FUN_0806c400(Player* p);
void FUN_0806c6d4(Player* p);
void FUN_0806c868(Player* p);
void FUN_0806c9bc(Player* p);
void FUN_0806cbe8(Player* p);

void Player_EquipArmor(Player* p, const ArmorData* a);
struct Entity08080be8* Entity08080be8_Create(Player* player, u32 heightOffset, u32 unk_be, u32 unk_c0, u32 offsetRadius, u32 plttID, u32 hitboxUnk40, u32 attributes, u32 hitboxUnk44, u32 ptclVal, u32 eneCost, u32 unk_cd);
void FUN_0807e784(HitboxData* a, HitboxData* b, Player* p);
void Player_SetMoveDelta(Player* p, s32 val);
extern u16 u16_03002b74;
void FUN_0823bac8(Vec3* pos);
bool32 FUN_0808626c(s32 idA, u32 flagsA, s32 idB, u32 flagsB);
void Player_UpdateBloodSword(Player* p);

void FUN_08065200(Player* p) {
  if (VM_SeekToNamedArg('i')) {
    p->unk_18 = VM_GetValue();
  } else {
    p->unk_18 = 0;
  }
}

void FUN_0806521c(Player* p) {
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

void FUN_08078d5c(Player* p);
void FUN_08078d5c(Player* p);
void FUN_080798a4(Player* p);
void FUN_08079b64(Player* p);
void FUN_08079e4c(Player* p);
void FUN_08079138(Player* p);

// プレイヤー生成の後半, kind を決めて更新コールバックと入力を割り当て, 1Pなら前のプレイヤーが残した状態異常の残り時間を引き継ぐ
s32 Player_InitState(Player* p) {
  static const PlayerFunc PTR_ARRAY_085abb14[6] = {
      [PLAYER_SOLAR_DJANGO] = FUN_08078d5c,
      [PLAYER_DARK_DJANGO] = FUN_08078d5c,
      [PLAYER_BAT] = FUN_080798a4,
      [PLAYER_MOUSE] = FUN_08079b64,
      [PLAYER_SLEEPING] = FUN_08079e4c,
      [PLAYER_SABATA] = FUN_08079138,
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
    p->updateCallback = PTR_ARRAY_085abb14[p->kind];
  }

  Player_SetAction(p, 0, 0);
  p->input = &gInput[p->unk_18];
  FUN_0806521c(p);

  if (p->unk_18 == 0) {
    s32 i;

    p->unk_442 = u16_03002b60;
    p->unk_444 = u16_03002b7c;
    p->unk_446 = u16_03002b8c;
    for (i = 0; i < 3; i++) {
      p->badCondTimer[i] = u16_ARRAY_03002ba0[i];
    }
  } else {
    s32 i;

    p->unk_442 = 0;
    p->unk_444 = 0;
    p->unk_446 = 0;
    for (i = 0; i < 3; i++) {
      p->badCondTimer[i] = 0;
    }
  }

  p->controlUp = gStat->controlUp;
  if (p->badCondTimer[2] != 0) {
    p->controlUp = u16_03002b64;
  }
  return 0;
}

NAKED void FUN_0806540c(Player* p) { INCFUNC("asm/func/FUN_0806540c.inc"); }
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
    if (p->unk_18 == 0) {
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
void Player_SetupHitbox(Player* p) {
  HitboxData* hitbox = &p->unk_16c;
  Vec3 halfSize, offset;

  halfSize.x = 50, halfSize.y = 127, halfSize.z = 50;
  offset.x = 0, offset.y = 127, offset.z = 0;
  Hitbox_Init(hitbox, p->mover.id, HBFLAG_UNK_14 | HBFLAG_UNK_12 | HBFLAG_UNK_0, 0, 1 << p->unk_18, &halfSize, &offset);
  if (p->kind == PLAYER_SOLAR_DJANGO) {
    Hitbox_SetPowerAndAttributes(hitbox, 20, HBATTR_SOL, HBATTR_DARK);
  } else {
    Hitbox_SetPowerAndAttributes(hitbox, 20, HBATTR_DARK, HBATTR_SOL);
  }
  Hitbox_SetHandler(hitbox, FUN_0807e784, p);
  Hitbox_SetPos(hitbox, &p->sprite_e8.pos, 0);
  Hitbox_Register(hitbox);
}

NON_MATCH bool32 FUN_08065a98(u32 val) {
#ifdef NONMATCHING_C
  if (val & 0x80) {
    if ((gStat->unk_934 & (SF934_UNK_4 | SF934_UNK_3)) == 0) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_08065a98.inc");
#endif
}

NON_MATCH bool32 FUN_08065ad0(u32 val) {
#ifdef NONMATCHING_C
  if (val & 0x80) {
    if (gStat->unk_934 & SF934_UNK_4) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_08065ad0.inc");
#endif
}

NON_MATCH bool32 FUN_08065b08(u32 val) {
#ifdef NONMATCHING_C
  if (val & 0x80) {
    if (gStat->unk_934 & SF934_UNK_13) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_08065b08.inc");
#endif
}

NON_MATCH bool32 FUN_08065b44(u32 val) {
#ifdef NONMATCHING_C
  if (val & 0x80) {
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
  if (FUN_0809f658(&p->mover.pos) && p->unk_397 == 0) {
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

void FUN_08066794(Player* p) {
  Player_SpawnFootHitbox(p);
  p->unk_376++;
}

// 太陽ゲージから unk_3dc を貯め、100 たまるごとに FUN_08066794 を1回呼ぶ
void FUN_080667b0(Player* p, s32 sungauge) {
  if (p->unk_43a == 0) {
    u16 state = p->unk_446;
    bool32 skip = state != 0 && p->unk_442 == 7;

    if (!skip) {
      p->unk_3dc += sungauge + 2;
      if (p->unk_3dc > 99) {
        FUN_08066794(p);
        p->unk_3dc -= 100;
      }
    }
  }
}

NAKED bool32 FUN_0806680c(Player* p) { INCFUNC("asm/func/FUN_0806680c.inc"); }

NAKED void FUN_0806687c(Player* p) { INCFUNC("asm/func/FUN_0806687c.inc"); }

NAKED void FUN_0806692c(Player* p) { INCFUNC("asm/func/FUN_0806692c.inc"); }

NAKED void FUN_08066a04(Player* p) { INCFUNC("asm/func/FUN_08066a04.inc"); }

NAKED void FUN_08066abc(Player* p) { INCFUNC("asm/func/FUN_08066abc.inc"); }

NAKED void FUN_08066c64(Player* p) { INCFUNC("asm/func/FUN_08066c64.inc"); }

void FUN_08066d10(Player* p) {
  FUN_0823bca8(8);
  p->lookAroundOffset.val = 0;
}

// 残差1命令: 原典は TRUE を返す経路を全部まとめて後ろへ飛ばすが、こちらは途中で合流する
NON_MATCH bool32 FUN_08066d2c(Player* p, s32 val) {
#ifdef NONMATCHING_C
  if (p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) {
    if (val == 0 || val == 3 || val == 6) {
      return TRUE;
    }
    if (val == 4 && p->unk_3bc != 0) {
      return TRUE;
    }
  } else if (p->kind == PLAYER_SLEEPING) {
    if (val == 0) {
      return TRUE;
    }
  } else {
    if (val == 0 || val == 4) {
      return TRUE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/FUN_08066d2c.inc");
#endif
}

void FUN_08066d7c(Player* p, s32 val) {
  if ((p->input->down & R_BUTTON) && FUN_08066d2c(p, val)) {
    if ((p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) && p->action == 4) {
      FUN_08066c64(p);
    } else {
      FUN_08066abc(p);
    }
  } else if (p->lookAroundOffset.val != 0) {
    FUN_08066d10(p);
  }
  p->unk_3d1 = 1;
}

// 自分の座標とカメラの注視点を 1:4 で混ぜた座標を pos_3c0 に作る
// 残差1命令: 原典は y だけ 150 をカメラ側のレジスタに足すが、agbcc の fold は整数の和から定数を必ず最後へ括り出すので和全体に足す形になる
NON_MATCH void FUN_08066df8(Player* p) {
#ifdef NONMATCHING_C
  p->pos_3c0.x = Div(p->mover.pos.x + p->lookAroundOffset.x + gCameraCoords.worldPos.x * 4, 5);
  p->pos_3c0.y = Div(p->mover.pos.y + p->lookAroundOffset.y + gCameraCoords.worldPos.y * 4 + 150, 5);
  p->pos_3c0.z = Div(p->mover.pos.z + p->lookAroundOffset.z + gCameraCoords.worldPos.z * 4, 5);
  FUN_0823bac8(&p->pos_3c0);
#else
  INCFUNC("asm/func/FUN_08066df8.inc");
#endif
}

void FUN_08066e84(void) {
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
  static const u16 sSolarDjangoAnimIdxTable[57] = {
      0, 5, 20, 22, 24, 26, 28, 30, 52, 54, 56, 58, 60, 61, 62, 63, 10, 15, 44, 46, 48, 109, 119, 114, 124, 129, 134, 139, 144, 149, 154, 159, 64, 69, 74, 79, 84, 89, 94, 99, 104, 32, 34, 38, 40, 42, 36, 179, 184, 194, 189, 534, 513, 514, 515, 519, 520,
  };  // 0x085ABB2C
  static const u16 sDarkDjangoAnimIdxTable[57] = {
      199, 204, 219, 221, 223, 225, 227, 229, 251, 253, 255, 257, 259, 260, 261, 262, 209, 214, 243, 245, 247, 308, 318, 313, 323, 328, 333, 338, 343,
      348, 353, 358, 263, 268, 273, 278, 283, 288, 293, 298, 303, 231, 233, 237, 239, 241, 235, 378, 383, 393, 388, 535, 521, 522, 523, 527, 528,
  };  // 0x085ABB9E
  static const u16 sSabataAnimIdxTable[57] = {
      414, 419, 434, 436, 438, 440, 442, 444, 466, 468, 470, 472, 474, 475, 476, 477, 424, 429, 458, 460, 462, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 478, 483, 488, 0, 0, 0, 446, 448, 452, 454, 456, 450, 493, 498, 508, 503, 533, 0, 0, 0, 0, 0,
  };  // 0x085ABC10

  if (playerKind == PLAYER_SOLAR_DJANGO) {
    return sSolarDjangoAnimIdxTable[idx];
  }
  if (playerKind == PLAYER_DARK_DJANGO) {
    return sDarkDjangoAnimIdxTable[idx];
  }
  if (playerKind == PLAYER_SABATA) {
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
  p->unk_20 &= ~1;
  Player_PlayAnim(p, FUN_08066ee4(p->kind, 0), 0x40);
}

// ハヤサと鎧の重さから移動速度を出す, 下限は 2
static s32 CalcMoveSpeed(Player* p) {
  u16 n = p->unk_446;
  bool32 heaviest = FALSE;
  s32 val;

  if (n != 0 && p->unk_442 == 1) {
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
  p->unk_20 &= ~1;
  p->facing = FUN_08067068(p);
  if (p->unk_3a4 == 0) {
    s32 val = CalcMoveSpeed(p);
    bool32 scaled;
    u16 n;

    FUN_080670d4(val);
    n = p->unk_446;
    scaled = FALSE;
    if (n != 0 && p->unk_442 == 5) {
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

NAKED void MagicDash_0806734c(Player* p) { INCFUNC("asm/func/MagicDash_0806734c.inc"); }

// 立っているタイルの中でタイル境界から十分離れているかを見る, unk_3bd が 1/5 のときは X, それ以外は Z で判定する
NON_MATCH bool32 FUN_080674dc(Player* p) {
#ifdef NONMATCHING_C
  u16 pos = (p->unk_3bd == 1 || p->unk_3bd == 5) ? p->mover.pos.x : p->mover.pos.z;
  u32 ofs = pos & 0xFF;

  if (ofs < 31 || ofs > 225) {
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_080674dc.inc");
#endif
}

NAKED void FUN_08067510(Player* p) { INCFUNC("asm/func/FUN_08067510.inc"); }

NAKED void FUN_08067de8(Player* p) { INCFUNC("asm/func/FUN_08067de8.inc"); }

bool32 FUN_08067f58(Player* p) {
  if (Player_TestFlag20(p, 0x10) && p->ene < p->maxEne) {
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
  if (!Player_TestFlag20(p, 0x10) && p->ene < p->maxEne) {
    return TRUE;
  }
  return FALSE;
}

NAKED void FUN_0806830c(Player* p) { INCFUNC("asm/func/FUN_0806830c.inc"); }

NAKED void FUN_08068624(Player* p) { INCFUNC("asm/func/FUN_08068624.inc"); }

NAKED void MagicRisingSun_08068944(Player* p) { INCFUNC("asm/func/MagicRisingSun_08068944.inc"); }

// gImmortalCoffin を動かしている間の移動速度, CalcMoveSpeed にチカラを足して gImmortalCoffin の重さ分を引いたもの
s32 FUN_08068c6c(Player* p) {
  u16 n = p->unk_446;
  bool32 heaviest = FALSE;
  s32 val;

  if (n != 0 && p->unk_442 == 2) {
    heaviest = TRUE;
  }

  if (heaviest) {
    val = 16;
  } else {
    s32 agility = p->stats[STAT_AGILITY];
    s32 over = p->armor.weight - 100;

    val = Div((agility - over + p->stats[STAT_STRENGTH] - gImmortalCoffin->weight) * 12, 100);
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
  p->unk_20 &= ~1;
  if (p->unk_4c4.unk_3 == 0) {
    Player_SetAction(p, 0, 0);
  }
}

NAKED void FUN_08069648(Player* p) { INCFUNC("asm/func/FUN_08069648.inc"); }

NAKED void MagicFreeze_08069710(Player* p) { INCFUNC("asm/func/MagicFreeze_08069710.inc"); }

NAKED void MagicHealing_08069928(Player* p) { INCFUNC("asm/func/MagicHealing_08069928.inc"); }

NAKED void MagicDynamite_08069b18(Player* p) { INCFUNC("asm/func/MagicDynamite_08069b18.inc"); }

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

NAKED void Sabata_BlackSun(Player* p) { INCFUNC("asm/func/Sabata_BlackSun.inc"); }

NAKED void FUN_0806b758(Player* p) { INCFUNC("asm/func/FUN_0806b758.inc"); }

NAKED void MagicTransform_0806b92c(Player* p) { INCFUNC("asm/func/MagicTransform_0806b92c.inc"); }

NAKED void MagicChangeBat_0806bc74(Player* p) { INCFUNC("asm/func/MagicChangeBat_0806bc74.inc"); }

NAKED void MagicChangeMouse_0806bf18(Player* p) { INCFUNC("asm/func/MagicChangeMouse_0806bf18.inc"); }

NAKED void MagicSleeping_0806c124(Player* p) { INCFUNC("asm/func/MagicSleeping_0806c124.inc"); }

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

  p->unk_20 &= ~PFLAG20_UNK_0;
  if (p->coffin == COFFIN_SILVER) {
    p->unk_20 |= PFLAG20_UNK_17;
  }

  anim = &p->anim_33c;
  AuxAnim_SetAnim(anim, p->anim_354, p->coffin, p->animIDOffset, p->xflip);

  spr = &p->sprite_e8;
  cmd = &anim->cmds[anim->cmdIdx];
  spr->metaspriteIdx = *cmd >> 6;

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
    p->unk_990 = 2;
    p->unk_98c = FUN_080da9c4(p->unk_98c, &p->mover, 2, 0, 0, 0, 0x80, 0);
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
      PlaySound_082406e0(0xD5);
    } else {
      if (p->unk_38a == 0) {
        PlaySound_082406e0(0x26B);
        p->unk_38a = 40;
      }
      PlaySound_082406e0(0xCD);
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

NAKED void* FUN_0806ea98(Player* p) { INCFUNC("asm/func/FUN_0806ea98.inc"); }

NAKED void MagicChangeWolf_0806eb40(Player* p) { INCFUNC("asm/func/MagicChangeWolf_0806eb40.inc"); }

void FUN_0806f1ec(Player* p) {
  switch (p->state) {
    case 0: {
      PlaySound_082406e0(0x39E);
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

  if ((s16)p->facingHistory[0] != -1 && p->lookAroundOffset.val == 0) {
    p->facing = FUN_08067068(p);
    turned = TRUE;
  }
  Player_SetAnimFacing(p);
  return turned;
}

void FUN_0806f780(Player* p) {
  p->unk_a8d = Player_CheckMagicEnchant(p);
  if (p->unk_a8d >= 0) {
    p->unk_951 = p->unk_a8d + 1;
  } else {
    p->unk_951 = 0;
  }
}

NAKED void* FUN_0806f7bc(Player* p) { INCFUNC("asm/func/FUN_0806f7bc.inc"); }

static inline PlayerFlag378 Player_GetFlag378(Player* p, PlayerFlag378 bits) { return p->flag378 & bits; }

// 武器の特殊効果コールバックの戻り値を合計する
s32 FUN_0806f900(Player* p) {
  s32 total = (s32)FUN_0806f7bc(p);
  s32 i;

  for (i = 0; i < WEAPON_EFFECT_SLOT_COUNT; i++) {
    if (p->weaponExDamageCb[i] != NULL) {
      total += p->weaponExDamageCb[i](p);
    }
  }
  if (Player_GetFlag378(p, FLAG378_UNK_19)) {
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

NAKED void dark_django_0806f990(HitboxData* a, HitboxData* b, void* _) { INCFUNC("asm/func/dark_django_0806f990.inc"); }

NAKED void FUN_0806fad8(Player* p) { INCFUNC("asm/func/FUN_0806fad8.inc"); }

NAKED void FUN_0806fc20(Player* p, u16* param_2, u32 param_3, s32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_0806fc20.inc"); }

NAKED bool32 FUN_0806fd58(Player* p) { INCFUNC("asm/func/FUN_0806fd58.inc"); }

NAKED void FUN_0806fedc(Player* p) { INCFUNC("asm/func/FUN_0806fedc.inc"); }

// 4.12 固定小数の積を 0 方向に丸めて整数に戻す, `/ 4096` だと agbcc がバイアス加算で割るので一致しない
static inline s32 Fix12ToInt(s32 v) {
  if (v >= 0) {
    return v >> 12;
  }
  return -(-v >> 12);
}

// src から angle の方向へ dist だけずらした座標を dst に書く, 高さはそのまま写す
void FUN_080700a4(Vec3* dst, Vec3* src, s32 angle, s32 dist) {
  dst->x = src->x + Fix12ToInt(gSineTable[(angle + 0x40) & 0xFF] * dist);
  dst->y = src->y;
  dst->z = src->z + Fix12ToInt(gSineTable[angle & 0xFF] * dist);
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
  if (p->unk_4ad != 0) {
    p->unk_4ae++;
    if (p->unk_4ae > 7) {
      Player_SpawnFootHitbox(p);
      p->unk_4ae = 0;
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
Facing32 Player_GetDpadFacing(Player* p) {
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
  if (p->lookAroundOffset.val != 0) {
    FUN_08066d10(p);
  }
}

void FUN_0807856c(Player* p) {
  if (p->lookAroundOffset.val != 0) {
    FUN_08066d10(p);
  }
}

NAKED void FUN_0807858c(Player* p) { INCFUNC("asm/func/FUN_0807858c.inc"); }

NAKED s32 FUN_0807868c(Player* p) { INCFUNC("asm/func/FUN_0807868c.inc"); }

// A ボタンを押していて, 相手が話しかけられる状態で, なおかつ同じエレベータに乗っているか
// 残差2命令: 原典は gImmortalCoffin をアドレスだけ保持して引数作りのところで読み直すが、こちらは1回のロードに畳まれる (agbcc-levers.md 参照)
NON_MATCH s32 FUN_08078844(Player* p) {
#ifdef NONMATCHING_C
  if ((p->input->down & A_BUTTON) && gImmortalCoffin != NULL && (gImmortalCoffin->state == 1 || gImmortalCoffin->state == 0x10) && FUN_0808626c(p->elevatorID, p->unk_390, gImmortalCoffin->elevatorID, gImmortalCoffin->unk_384)) {
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
    MagicDash_0806734c,
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

NAKED void FUN_08078d5c(Player* p) { INCFUNC("asm/func/FUN_08078d5c.inc"); }

NAKED void FUN_08079138(Player* p) { INCFUNC("asm/func/FUN_08079138.inc"); }

NAKED s32 FUN_080794e0(Player* p) { INCFUNC("asm/func/FUN_080794e0.inc"); }

NAKED s32 FUN_080795bc(Player* p) { INCFUNC("asm/func/FUN_080795bc.inc"); }

NAKED void FUN_08079644(Player* p) { INCFUNC("asm/func/FUN_08079644.inc"); }

NAKED void FUN_0807972c(Player* p) { INCFUNC("asm/func/FUN_0807972c.inc"); }

NAKED void FUN_080798a4(Player* p) { INCFUNC("asm/func/FUN_080798a4.inc"); }

NAKED s32 FUN_0807998c(Player* p) { INCFUNC("asm/func/FUN_0807998c.inc"); }

NAKED void FUN_08079a64(Player* p) { INCFUNC("asm/func/FUN_08079a64.inc"); }

NAKED void FUN_08079b64(Player* p) { INCFUNC("asm/func/FUN_08079b64.inc"); }

NAKED s32 FUN_08079c50(Player* p) { INCFUNC("asm/func/FUN_08079c50.inc"); }

NAKED void FUN_08079d40(Player* p) { INCFUNC("asm/func/FUN_08079d40.inc"); }

NAKED void FUN_08079e4c(Player* p) { INCFUNC("asm/func/FUN_08079e4c.inc"); }

NAKED void FUN_08079f1c(Player* p) { INCFUNC("asm/func/FUN_08079f1c.inc"); }

NAKED void FUN_0807a270(Player* p) { INCFUNC("asm/func/FUN_0807a270.inc"); }

NAKED void FUN_0807a334(Player* p) { INCFUNC("asm/func/FUN_0807a334.inc"); }

void FUN_0807a44c(Player* p, s32 dir) {
  Player_SetAction(p, 4, 1);
  p->unk_3bd = dir;
  p->facing = (dir + 4) & 7;
  if (p->unk_3bd > 4) {
    p->animIDOffset = (8 - p->unk_3bd) >> 1;
    p->xflip = 1;
  } else {
    p->animIDOffset = p->unk_3bd >> 1;
    p->xflip = 0;
  }
  p->unk_16c.unk_40 = 0;
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

void FUN_0807a524(Player* p) {}

void FUN_0807a528(Player* p, Vec3* pos, u16 param_3) {
  p->action = 8;
  p->stateTimer = 0;
  p->state = 0;
  p->unk_3f6 = 0;
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
NON_MATCH s32 FUN_0807a6cc(WeaponData* w) {
#ifdef NONMATCHING_C
  if (gStat->armor < 0) {
    return FUN_0807a5d8(w, NULL);
  }
  return FUN_0807a5d8(w, &gArmorDB[GetInventoryArmor(gStat->armor)]);
#else
  INCFUNC("asm/func/FUN_0807a6cc.inc");
#endif
}

// 鎧の効果を乗せたハヤサから派生値を出す, 鎧を渡さなければ素の値, サバタでプレイ中は u16_03002b74 をそのまま返す
s32 FUN_0807a70c(ArmorData* data) {
  s32 val;

  if (gStat->playerKind == PLAYER_SABATA) {
    return u16_03002b74;
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

// 経験値を加算する, サバタでプレイ中は入らず、 FLAG378_TRAININGGEAR が立っていると1.5倍になる
// 残差2命令: 原典は gStat->exp への store ごとに gStat を読み直す (agbcc-levers.md 参照)
NON_MATCH void FUN_0807a798(s32 amount) {
#ifdef NONMATCHING_C
  if (gStat->playerKind == PLAYER_SABATA) {
    return;
  }
  if (gPlayerPtr[0] != NULL && (gPlayerPtr[0]->flag378 & FLAG378_TRAININGGEAR)) {
    amount = (amount * 3) >> 1;
  }
  gStat->exp += amount;
  if (gStat->exp >= 999999) {
    gStat->exp = 999999;
  }
#else
  INCFUNC("asm/func/FUN_0807a798.inc");
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

void FUN_0807a8e0(Player* p) { *(gStat->unk_2c8 + p->isSabata) = 0; }

void FUN_0807a904(Player* p, u32 flag) {
  if (flag == 0) {
    p->speedPenalty++;
  }
}

// 残差2命令: 原典は gStat への3つの strh ごとに gStat を読み直すが、こちらは1回に畳まれる (agbcc-levers.md 参照)
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
void Player_ReduceENE_0807aa60(Player* player, s32 amount) {
  if (player->unk_1c == 1) {
    u16* ene = &player->ene;

    if (*ene < amount) {
      *ene = 0;
    } else {
      *ene -= amount;
    }
  }
}

// 月光虫取得時に呼ばれる(HP回復)
// 精霊の衣を着ていると効果が2倍になる
void Player_ApplyMoonbug(Player* p, s32 amount) {
  PlayerFlag378 mask = FLAG378_FAIRY;

  if (p->flag378 & mask) {
    FUN_0807aa00(p, amount * 2);
  } else {
    FUN_0807aa00(p, amount);
  }
}

// 太陽虫取得時に呼ばれる(Ene回復)
// 精霊の衣を着ていると効果が2倍になる
void Player_ApplySolarbug(Player* p, s32 amount) {
  PlayerFlag378 mask = FLAG378_FAIRY;

  if (p->flag378 & mask) {
    FUN_0807aa30(p, amount * 2);
  } else {
    FUN_0807aa30(p, amount);
  }
}

// 暗黒虫取得時に呼ばれる(Eneが減る)
// 精霊の衣を着ていると効果が2倍になる
void Player_ApplyDarkbug(Player* p, s32 amount) {
  PlayerFlag378 mask = FLAG378_FAIRY;

  if (p->flag378 & mask) {
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
  p->unk_16c.flags |= HBFLAG_UNK_2;
  p->unk_16c.unk_40 = 0;
  p->unk_16c.unk_44 = 0;
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

// '.i' から gPlayerPtr の idx を取得する, なかったら 0 (1P) を返すので、 実質的な '.i=0'
u32 VM_GetPlayerIdx(void) { return VM_SeekToNamedArg('i') ? VM_GetValue() : 0; }

s32 FUN_0807b000(Vec3* pos) {
  if (VM_SeekToNamedArg('p')) {
    pos->x = VM_GetValue();
    pos->y = VM_GetValue();
    pos->z = VM_GetValue();
    return 1;
  }

  return 0;
}

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
    return (p->unk_3bd + 4) & 7;
  }
  return p->facing;
#else
  INCFUNC("asm/func/FUN_0807b0c0.inc");
#endif
}

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

void FUN_0807b15c(void) {
  if (VM_SeekToNamedArg('e')) {
    FUN_0807a798(VM_GetValue());
  }
}

void FUN_0807b174(void) {
  if (VM_SeekToNamedArg('t')) {
    s32 kind = VM_GetValue();

    if (VM_SeekToNamedArg('p')) {
      AddWeaponExp(kind, VM_GetValue());
    }
  }
}

// 残差1命令: 原典は gPlayerPtr[i] を読んだレジスタから写しを作る, FUN_0807b2dc / FUN_0807b66c と同じ類
NON_MATCH s32 FUN_0807b1a4(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p == NULL || !VM_SeekToNamedArg('f')) {
    return 0;
  }
  return p->flag378 & VM_GetValue();
#else
  INCFUNC("asm/func/FUN_0807b1a4.inc");
#endif
}

NAKED void item_0807b1e4(Player* p) { INCFUNC("asm/func/item_0807b1e4.inc"); }

// 残差1命令: 原典は gPlayerPtr[i] を読んだレジスタから別のレジスタへ写してから使う
// ローカルの有無・宣言と代入の分離・gPlayerPtr[i] の直接参照のどれでも写しが出ない
NON_MATCH s32 FUN_0807b2dc(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && p->unk_446 != 0) {
    return p->unk_442;
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
    p->unk_442 = 0;
    p->unk_446 = 0;
    p->unk_444 = 0;
  }
}

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
NON_MATCH s32 FUN_0807b3e0(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('s')) {
    s32 n = VM_GetValue();

    if (n <= 2 && p->badCondTimer[n] != 0) {
      return 1;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_0807b3e0.inc");
#endif
}

void FUN_0807b428(void) {
  if (VM_SeekToNamedArg('s')) {
    s32 n = VM_GetValue();

    if (n <= 2) {
      s32 val = VM_SeekToNamedArg('t') ? VM_GetValue() : u16_ARRAY_085abf4c[n];

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
    FUN_08063634(p, VM_GetValue());
  }
}

void FUN_0807b4b8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 j;

    for (j = 0; j < 3; j++) {
      FUN_08063634(p, j);
    }
  }
}

// 残差1命令: 2つ目の判定の分岐極性が逆 (原典は bgt で 1 を返す側へ飛び、0 を返す側が直列)
// if/return, else 明示, && の直接 return をいずれも試したが極性が変わらない
NON_MATCH s32 FUN_0807b4e4(void) {
#ifdef NONMATCHING_C
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && *(gStat->unk_2c8 + p->isSabata) > 0) {
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_0807b4e4.inc");
#endif
}

void FUN_0807b528(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    *(gStat->unk_2c8 + p->isSabata) = 0;
  }
}

void FUN_0807b564(void) {
  u16_03002bd0 = 0;
  gSunGaugeOverride = 0;
  u16_03002b78 = 0;
}

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

NAKED void FUN_0807b7a4(Player* p) { INCFUNC("asm/func/FUN_0807b7a4.inc"); }

void FUN_0807b890(Player* p, s32 val) {
  p->unk_96c = 1;
  p->plttID_95e = val;
}

void FUN_0807b8a8(Player* p, s32 val) {
  p->unk_96c = 2;
  p->plttID_95e = val;
}

void FUN_0807b8c0(Player* p) { p->unk_96c = 0; }

void FUN_0807b8d0(Player* p, Vec3* src) { p->mover.pos = *src; }

void FUN_0807b8dc(Player* p) {
  FUN_0807b7a4(p);
  Player_SetAction(p, 0, 0);
  p->sprite_88.flags |= SPRFLAG_HIDDEN;
  p->fn_498 = FUN_080726e0;
}

NAKED void FUN_0807b910(Player* p, s32 val) { INCFUNC("asm/func/FUN_0807b910.inc"); }

void FUN_0807b9dc(Player* p, s32 param_2, u32 param_3) {
  p->unk_4a9 = param_2;
  p->scriptID_4b0 = param_3;
  p->fn_498 = FUN_080727d4;
  FUN_0807b7a4(p);
  Player_SetAction(p, 0, 0);
}

void FUN_0807ba14(Player* p, s32 param_2) {
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  FUN_0807b7a4(p);
  Player_SetAction(p, 0, 1);
  p->fn_498 = FUN_08072724;
}

void FUN_0807ba50(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 0, 2);
  p->fn_498 = FUN_08072724;
}

void FUN_0807ba94(Player* p, Vec3* pos, u32 scriptID, s32 facing) {
  p->unk_49c = *pos;
  p->scriptID_4b0 = scriptID;
  p->unk_4a9 = facing;
  if (p->kind == PLAYER_BAT) {
    if (p->unk_4a9 >= 0) {
      p->unk_4a9 = ((p->unk_4a9 >> 1) << 1) + 1;
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
  FUN_0807b7a4(p);
  Player_SetAction(p, 1, 0);
}

void FUN_0807bb3c(Player* p, Vec3* pos, s32 param_3, s32 param_4, u32 scriptID) {
  if (pos == NULL) {
    p->unk_49c = p->mover.pos;
  } else {
    p->unk_49c = *pos;
  }
  p->scriptID_4b0 = scriptID;
  p->unk_4a6 = param_4;
  p->unk_4a9 = param_3;
  p->unk_4a7 = 0x96;
  FUN_0807b7a4(p);
  Player_SetAction(p, 6, 0);
  p->fn_498 = FUN_08072d48;
}

void FUN_0807bbb0(Player* p, s32 param_2, u32 param_3) {
  FUN_0807b910(p, 4);
  p->unk_4a6 = param_2;
  p->scriptID_4b0 = param_3;
  p->facing = FACE_DOWN;
  p->animIDOffset = 1;
  p->xflip = 0;
  FUN_0807b7a4(p);
  Player_SetAction(p, 7, 0);
  p->fn_498 = FUN_0807304c;
}

void FUN_0807bc14(Player* p, s32 param_2, u32 param_3) {
  p->unk_4a6 = param_2;
  p->scriptID_4b0 = param_3;
  p->facing = FACE_UP;
  p->animIDOffset = 0;
  p->xflip = 0;
  FUN_0807b7a4(p);
  Player_SetAction(p, 7, 0);
  p->fn_498 = FUN_0807304c;
}

void FUN_0807bc64(Player* p, u32 scriptID) {
  if (p->unk_1c == 2 && p->action == 7 && p->state != 0) {
    p->scriptID_4b0 = scriptID;
    FUN_0807b7a4(p);
    Player_SetAction(p, 7, 3);
    p->fn_498 = FUN_0807304c;
  }
}

void FUN_0807bcb0(Player* p, s32 param_2, u32 param_3) {
  FUN_0807b7a4(p);
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 18, 0);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bcfc(Player* p, s32 param_2) {
  FUN_0807b7a4(p);
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  PlaySound_082406e0(0xC6);
  FUN_0807b7a4(p);
  Player_SetAction(p, 18, 2);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bd44(Player* p, s32 param_2) {
  FUN_0807b7a4(p);
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  FUN_0807b7a4(p);
  Player_SetAction(p, 18, 1);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bd84(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 18, 3);
  p->fn_498 = FUN_08073574;
}

void FUN_0807bdc8(Player* p, s32 facing, s32 param_3, u32 scriptID) {
  if (facing >= 0) {
    p->facing = facing;
  }
  p->facing |= 1;
  p->scriptID_4b0 = scriptID;
  p->unk_4a6 = param_3;
  p->unk_3f0 = param_3;
  FUN_0807b7a4(p);
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

void FUN_0807be58(Player* p, s32 facing, s32 param_3, u32 scriptID) {
  if (facing >= 0) {
    p->facing = facing;
  }
  p->facing |= 1;
  p->scriptID_4b0 = scriptID;
  FUN_0807b7a4(p);
  p->unk_3f6 = param_3;
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

void FUN_0807bee0(Player* p, s32 facing, s32 param_3, u32 scriptID) {
  if (facing >= 0) {
    p->facing = facing;
  }
  p->facing |= 1;
  if (p->facing > FACE_DOWN) {
    p->animIDOffset = (8 - p->facing) >> 1;
    p->xflip = 1;
  } else {
    p->animIDOffset = p->facing >> 1;
    p->xflip = 0;
  }
  p->unk_4a4 = param_3;
  p->scriptID_4b0 = scriptID;
  FUN_0807b7a4(p);
  Player_SetAction(p, 24, 0);
  if (p->kind == PLAYER_BAT) {
    p->fn_498 = FUN_08075980;
  } else if (p->kind == PLAYER_MOUSE) {
    p->fn_498 = FUN_08076f2c;
  } else {
    p->fn_498 = FUN_080739e0;
  }
}

void FUN_0807bfa4(Player* p, s32 facing, s32 param_3, s32 param_4, u32 scriptID) {
  if (facing >= 0) {
    p->facing = facing;
  }
  p->facing |= 1;
  if (p->facing > FACE_DOWN) {
    p->animIDOffset = (8 - p->facing) >> 1;
    p->xflip = 1;
  } else {
    p->animIDOffset = p->facing >> 1;
    p->xflip = 0;
  }
  p->unk_4a4 = param_3;
  p->unk_4a6 = param_4;
  p->scriptID_4b0 = scriptID;
  FUN_0807b7a4(p);
  Player_SetAction(p, 25, 0);
  p->fn_498 = FUN_08073b3c;
}

void FUN_0807c048(Player* p, s32 scriptID) {
  if (p->unk_1c == 2 && p->action == 25 && p->state == 5) {
    p->scriptID_4b0 = scriptID;
    p->state = 4;
    FUN_0807b7a4(p);
  }
}

void FUN_0807c084(Player* p, s32 facing, s32 param_3, u32 scriptID) {
  if (facing >= 0) {
    p->facing = facing;
  }
  p->facing |= 1;
  if (p->facing > FACE_DOWN) {
    p->animIDOffset = (8 - p->facing) >> 1;
    p->xflip = 1;
  } else {
    p->animIDOffset = p->facing >> 1;
    p->xflip = 0;
  }
  p->unk_4a4 = param_3;
  p->scriptID_4b0 = scriptID;
  FUN_0807b7a4(p);
  Player_SetAction(p, 24, 0);
  p->fn_498 = FUN_08073e18;
}

void FUN_0807c11c(Player* p, s32 facing) {
  u16 animID;

  if (facing >= 0) {
    p->facing = facing;
  }
  p->facing |= 1;
  if (p->facing > FACE_DOWN) {
    p->animIDOffset = (8 - p->facing) >> 1;
    p->xflip = 1;
  } else {
    p->animIDOffset = p->facing >> 1;
    p->xflip = 0;
  }
  FUN_0807b7a4(p);
  animID = p->animIDOffset + FUN_08066ee4(p->kind, 46);
  MainSprite_SetAnim(&p->sprite_88, &p->spriteSet_68, animID, 1, MAIN_ANIM_REVERSE);
  MainSprite_AdvanceAnim(&p->sprite_88, &p->spriteSet_68);
  if (p->xflip != 0) {
    p->sprite_88.flags |= SPRFLAG_XFLIP;
  } else {
    p->sprite_88.flags &= ~SPRFLAG_XFLIP;
  }
  Player_SetAction(p, 24, 2);
  p->fn_498 = FUN_08073e18;
}

void FUN_0807c200(Player* p, s32 facing, u32 scriptID) {
  if (facing >= 0) {
    p->facing = facing;
  }
  p->scriptID_4b0 = scriptID;
  FUN_0807b7a4(p);
  Player_SetAction(p, 7, 0);
  if (p->kind == PLAYER_BAT) {
    p->facing |= 1;
    if (p->facing > FACE_DOWN) {
      p->animIDOffset = (8 - p->facing) >> 1;
      p->xflip = 1;
    } else {
      p->animIDOffset = p->facing >> 1;
      p->xflip = 0;
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
      p->xflip = 0;
      p->fn_498 = FUN_0807317c;
    }
  }
}

void FUN_0807c30c(Player* p, s32 param_2, u32 param_3) {
  if (p->kind >= PLAYER_BAT && p->kind <= PLAYER_SLEEPING) {
    FUN_0807c200(p, param_2, param_3);
  }
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 7, 7);
  p->fn_498 = FUN_0807317c;
}

NAKED void FUN_0807c36c(Player* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0807c36c.inc"); }

void FUN_0807c458(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 3, 0);
  p->fn_498 = FUN_08073f88;
}

void FUN_0807c49c(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 3, 2);
  p->fn_498 = FUN_08073f88;
}

void FUN_0807c4e0(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 3, 0);
  p->fn_498 = FUN_080740b0;
}

void FUN_0807c524(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 3, 2);
  p->fn_498 = FUN_080740b0;
}

void FUN_0807c568(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 3, 0);
  p->fn_498 = FUN_08074244;
}

void FUN_0807c5ac(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 3, 2);
  p->fn_498 = FUN_08074244;
}

void FUN_0807c5f0(Player* p, s32 param_2, u32 param_3) {
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 3, 0);
  p->fn_498 = FUN_08074350;
}

NAKED void FUN_0807c634(Player* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0807c634.inc"); }

void FUN_0807c748(Player* p, s32 param_2, s32 param_3, u32 param_4) {
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  p->scriptID_4b0 = param_4;
  p->unk_4a7 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 3, 0);
  p->fn_498 = FUN_080744bc;
}

void FUN_0807c798(Player* p, s32 scriptID) {
  p->scriptID_4b0 = scriptID;
  FUN_0807b7a4(p);
  Player_SetAction(p, 3, 5);
  p->fn_498 = FUN_080744bc;
}

NAKED void FUN_0807c7c8(Player* p) { INCFUNC("asm/func/FUN_0807c7c8.inc"); }

void FUN_0807c88c(Player* p, Vec3* pos, s32 param_3, u32 param_4) {
  p->unk_49c = *pos;
  p->scriptID_4b0 = param_4;
  p->unk_4a9 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 2, 0);
  p->fn_498 = FUN_080746ec;
}

void FUN_0807c8d4(Player* p, s32 param_2) {
  if (param_2 >= 0) {
    p->facing = param_2;
  }
  Player_SetAnimFacing(p);
  Player_PlayAnim(p, FUN_08066ee4(p->kind, 1), 0x20);
  FUN_0807b7a4(p);
  Player_SetAction(p, 2, 0);
  p->fn_498 = FUN_08074994;
}

void FUN_0807c928(Player* p, s32 val) {
  FUN_0807b7a4(p);
  p->facing = FACE_UP_RIGHT;
  p->animIDOffset = 0;
  p->xflip = 0;
  Player_SetAction(p, 16, 0);
  p->fn_498 = FUN_080749b0;
}

void FUN_0807c968(Player* p, s32 val) {
  FUN_0807b7a4(p);
  p->facing = FACE_UP_RIGHT;
  p->animIDOffset = 0;
  p->xflip = 0;
  Player_SetAction(p, 16, 2);
  p->fn_498 = FUN_080749b0;
}

void FUN_0807c9ac(Player* p, s32 param_2, u32 param_3) {
  if (param_2 != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = 1;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = 0;
  }
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 0, 0);
  p->fn_498 = FUN_080728a8;
}

void FUN_0807ca24(Player* p, s32 param_2, u32 param_3) {
  if (param_2 != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = 1;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = 0;
  }
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 0, 3);
  p->fn_498 = FUN_080728a8;
}

void FUN_0807ca9c(Player* p, s32 param_2, u32 param_3) {
  if (param_2 != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = 1;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = 0;
  }
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 0, 4);
  p->fn_498 = FUN_080728a8;
}

void FUN_0807cb14(Player* p, s32 param_2, u32 param_3) {
  if (param_2 != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = 1;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = 0;
  }
  p->scriptID_4b0 = param_3;
  FUN_0807b7a4(p);
  Player_SetAction(p, 0, 2);
  p->fn_498 = FUN_080728a8;
}

void FUN_0807cb8c(Player* p, s32 facing, u32 scriptID) {
  if (facing >= 0) {
    p->facing = facing;
  }
  p->facing |= 1;
  if (p->facing > FACE_DOWN) {
    p->animIDOffset = (8 - p->facing) >> 1;
    p->xflip = 1;
  } else {
    p->animIDOffset = p->facing >> 1;
    p->xflip = 0;
  }
  p->scriptID_4b0 = scriptID;
  FUN_0807b7a4(p);
  Player_SetAction(p, 0, 0);
  p->fn_498 = FUN_080729e0;
}

void FUN_0807cc14(Player* p, s32 param_2) {
  if (param_2 != 0) {
    p->facing = FACE_DOWN_LEFT;
    p->animIDOffset = 0;
    p->xflip = 1;
  } else {
    p->facing = FACE_DOWN_RIGHT;
    p->animIDOffset = 0;
    p->xflip = 0;
  }
  FUN_0807b7a4(p);
  Player_SetAction(p, 0, 0);
  p->fn_498 = FUN_08072a0c;
}

bool32 FUN_0807cc84(Player* p, u32 scriptID) {
  p->scriptID_4b0 = scriptID;
  if (p->kind <= PLAYER_DARK_DJANGO || p->kind == PLAYER_SABATA) {
    return FALSE;
  }
  if (p->kind == PLAYER_BAT) {
    FUN_0807b7a4(p);
    Player_SetAction(p, 12, 0);
    p->fn_498 = FUN_08075b4c;
  } else if (p->kind == PLAYER_MOUSE) {
    FUN_0807b7a4(p);
    Player_SetAction(p, 13, 0);
    p->fn_498 = FUN_08077100;
  } else if (p->kind == PLAYER_SLEEPING) {
    p->facing = FACE_DOWN;
    Player_SetAnimFacing(p);
    FUN_0807b7a4(p);
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

void FUN_0807d118(Player* p) {
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

s32 FUN_0807d164(void) {
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

void Player_Lock(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807b910(p, FUN_0807d164());
    FUN_08072640(p);
  }
}

void FUN_0807d298(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807b9dc(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d2d0(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807ba14(p, FUN_0807d164());
    FUN_08072640(p);
  }
}

void FUN_0807d300(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807ba50(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void Player_MoveTo(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('p')) {
    Vec3 pos;
    s32 facing;
    u32 scriptID;

    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
    facing = FUN_0807d164();
    scriptID = FUN_0807d180();
    FUN_0807ba94(p, &pos, scriptID, facing);
    FUN_08072640(p);
  }
}

void FUN_0807d3b8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL && VM_SeekToNamedArg('p')) {
    Vec3 pos;
    s32 facing;
    u32 scriptID;

    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
    facing = FUN_0807d164();
    scriptID = FUN_0807d180();
    FUN_0807c88c(p, &pos, facing, scriptID);
    FUN_08072640(p);
  }
}

void FUN_0807d438(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 param_4 = VM_SeekToNamedArg('f') ? VM_GetValue() : 0;
    s32 param_3 = FUN_0807d164();
    u32 scriptID = FUN_0807d180();

    if (VM_SeekToNamedArg('p')) {
      Vec3 pos;

      pos.x = VM_GetValue();
      pos.y = VM_GetValue();
      pos.z = VM_GetValue();
      FUN_0807bb3c(p, &pos, param_3, param_4, scriptID);
    } else {
      FUN_0807bb3c(p, NULL, param_3, param_4, scriptID);
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
      FUN_0807b910(p, 4);
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
    FUN_0807bcb0(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d5c8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bcfc(p, FUN_0807d164());
    FUN_08072640(p);
  }
}

void FUN_0807d5f8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bd44(p, FUN_0807d164());
    FUN_08072640(p);
  }
}

void FUN_0807d628(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807bd84(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d660(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 a = FUN_0807d164();
    u32 b = FUN_0807d180();

    FUN_0807bdc8(p, a, VM_SeekToNamedArg('f') ? VM_GetValue() : 0, b);
  }
}

void FUN_0807d6a8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 a = FUN_0807d164();
    u32 b = FUN_0807d180();

    FUN_0807be58(p, a, VM_SeekToNamedArg('h') ? VM_GetValue() : 1500, b);
    FUN_08072640(p);
  }
}

void FUN_0807d6f8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 n = VM_SeekToNamedArg('f') ? VM_GetValue() : 30;

    FUN_0807bee0(p, FUN_0807d164(), n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d744(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    s32 param_3 = VM_SeekToNamedArg('f') ? VM_GetValue() : 50;
    s32 param_4 = VM_SeekToNamedArg('L') ? VM_GetValue() : 0;
    s32 facing = FUN_0807d164();
    u32 scriptID = FUN_0807d180();

    FUN_0807bfa4(p, facing, param_3, param_4, scriptID);
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

    FUN_0807c084(p, FUN_0807d164(), n, FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d828(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c11c(p, FUN_0807d164());
    FUN_08072640(p);
  }
}

void FUN_0807d858(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c200(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d890(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c36c(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d8c8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c458(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d900(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c49c(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d938(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c4e0(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d970(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c524(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d9a8(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c568(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807d9e0(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c5ac(p, FUN_0807d164(), FUN_0807d180());
    FUN_08072640(p);
  }
}

void FUN_0807da18(void) {
  s32 i = VM_GetPlayerIdx();
  Player* p = gPlayerPtr[i];

  if (p != NULL) {
    FUN_0807c5f0(p, FUN_0807d164(), FUN_0807d180());
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
      a = 0;
      c = 0;
    }
    FUN_0807cec4(p, m, c, a);
  }
}

void Player_Unlock(void) {
  s32 i = VM_GetPlayerIdx();

  if (gPlayerPtr[i] != NULL) {
    FUN_0807d118(gPlayerPtr[i]);
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

NAKED void FUN_0807e2cc(Player* p) { INCFUNC("asm/func/FUN_0807e2cc.inc"); }

// hitboxTimer が残っている間 hitbox_2ec を当たり判定に出し続ける
void FUN_0807e388(Player* p) {
  if (p->hitboxTimer != 0) {
    Hitbox_Register(&p->hitbox_2ec);
    p->hitboxTimer--;
  }
}

NAKED u32 FUN_0807e3b0(Player* p, HitboxData* a, HitboxData* b) { INCFUNC("asm/func/FUN_0807e3b0.inc"); }

void FUN_0807e784(HitboxData* a, HitboxData* b, Player* p) {
  if (p->unk_1c == 1) {
    if (Hitbox_TestFlags(a, HBFLAG_UNK_9)) {
      if ((b->hitState & 1) == 0) {
        return;
      }
      b->hitState &= ~1;
    }
    if (Hitbox_TestFlags(a, HBFLAG_UNK_10)) {
      if (b->hitState & 2) {
        return;
      }
      b->hitState |= 2;
    }
    FUN_0807e3b0(p, a, b);
    if (Player_GetFlag378(p, FLAG378_SPIKE)) {
      FUN_0807e2cc(p);
    }
  }
}

// 一時的な HitboxData を組み立てて自分の当たり判定にぶつける
s32 FUN_0807e7fc(Player* p, s32 power, s32 unk_40, s32 angle, s32 unk_44, HitboxAttributes attrs) {
  if (p->unk_1c == 1) {
    HitboxData* own = &p->unk_16c;
    HitboxData hb;
    s32 n = p->unk_16c.unk_44;

    if (n <= 0) {
      hb.flags = HBFLAG_UNK_13;
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

NAKED bool32 Player_Update_Helper_0807e968(Player* p) { INCFUNC("asm/func/Player_Update_Helper_0807e968.inc"); }

// 残差なし・レジスタ割当のみ不一致 (p と n の r4/r5 が入れ替わる)
NON_MATCH void FUN_0807eca8(Player* p) {
#ifdef NONMATCHING_C
  s32 n = p->unk_16c.unk_44;

  if (n > 0) {
    Player_SetFlag35a(p, PFLAG35A_NO_HITBOX);
    if (p->unk_16c.unk_40 == 0 && p->action != 24 && p->action != 25) {
      n--;
      if (n != 0 && ((n >> 2) & 1)) {
        Player_SetFlag35a(p, PFLAG35A_HIDE_SPRITE | PFLAG35A_HIDE_SHADOW);
      }
      p->unk_16c.unk_44 = n;
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
    p->updateCallback = FUN_080798a4;
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
    p->updateCallback = FUN_08079b64;
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
    p->updateCallback = FUN_08079e4c;
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
    p->updateCallback = FUN_08078d5c;
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

NAKED static s32 Player_Update(Player* p) { INCFUNC("asm/func/Player_Update.inc"); }

static s32 Player_Destroy(Player* p) {
  EnemyTargetManager_Remove(&p->target);
  MainSprite_Remove(&p->sprite_88);
  AuxSprite_Remove(&p->sprite_e8);
  Hitbox_Unregister(&p->unk_16c);
  Mover_Unlink(&p->mover);
  Player_DestroyEffects(p);
  FUN_0807ddd4(p);
  Player_StopEneChargeSound(p);
  ptr_03002ba8 = NULL;
  u16_03002bf4 = 0;
  gPlayerPtr[p->mover.unk_4] = NULL;
  gPlayerCount--;
  return 0;
}

static s32 Player_Init(Player* p, u32 n, void* _) {
  FUN_08065200(p);
  Player_InitState(p);
  FUN_08065744(p, n);
  Player_SetupHitbox(p);
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

// 0xF5EB, エリア移動などでも呼ばれる
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

// clang-format off
const PlayerFunc PTR_ARRAY_085abdb0[27] = {
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

// --------------------------------------------

void FUN_0806ceb0(Player* p);
void FUN_0806d014(Player* p);
void FUN_0806d22c(Player* p);
void FUN_0806dd7c(Player* p);
void FUN_0806d420(Player* p);
void FUN_0806d5b0(Player* p);
void FUN_0806d74c(Player* p);
void FUN_0806da18(Player* p);

// clang-format off
const PlayerFunc PTR_ARRAY_085abe1c[27] = {
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

// --------------------------------------------

void MagicSleeping_Update(Player* p);
void FUN_0806e15c(Player* p);
void FUN_0806e404(Player* p);
void FUN_0806e4b4(Player* p);
void FUN_0806e7dc(Player* p);
void FUN_0806e674(Player* p);

// clang-format off
const PlayerFunc PTR_ARRAY_085abe88[21] = {
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

const u16 u16_ARRAY_085abf4c[3] = {1800, 1800, 900};  // 0x085ABF4C

// --------------------------------------------

void FUN_08081f80(Player* p);
void FUN_08081fb4(Player* p);
void FUN_08082bdc(Player* p);
void FUN_080832b8(Player* p);
void FUN_08082154(Player* p);
void FUN_0808301c(Player* p);
void FUN_08082dac(Player* p);
void FUN_08082970(Player* p);
void FUN_08082a94(Player* p);
void FUN_080835d8(Player* p);
void FUN_08082464(Player* p);
void FUN_08082498(Player* p);
void FUN_08082670(Player* p);

// clang-format off
const PlayerFunc PTR_ARRAY_085abf54[29] = {
    FUN_08081f80,
    FUN_08081fb4,
    FUN_08082bdc,
    FUN_080832b8,
    NULL,
    NULL,
    NULL,
    FUN_08082154,
    FUN_0808301c,
    FUN_08082dac,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    FUN_08082970,
    FUN_08082a94,
    FUN_080835d8,
    FUN_08082464,
    NULL,
    NULL,
    FUN_08082498,
    FUN_08082670,
    NULL,
    NULL,
    NULL,
};  // 0x085ABF54
// clang-format on
