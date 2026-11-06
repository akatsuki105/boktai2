#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

typedef struct {
  Particle base;  // 0x00
  Vec3 offset;    // 0x28, Player + offset が base.pos になる
  u16 unk_30;     // 0x30
  u16 unk_32;     // 0x32
  u16 unk_34;     // 0x34
  u16 unk_36;     // 0x36
  u16 unk_38;     // 0x38
  u16 unk_3a;     // 0x3A
} LevelUpParticle;
static_assert(sizeof(LevelUpParticle) == 60);  // 根拠: LevelUpper_EmitLevelUpEffect

// 現在の経験値を確認して、レベルアップする場合はレベルアップ処理を行う
// またその際のパーティクルやSEなどの演出処理も行う
typedef struct {
  Entity e;                  // 0x00, ENTITY_UNK_9
  AuxSprite sprite;          // 0x18, gfx を指す描画ノード, 根拠: LevelUpper_InitSprite / LevelUpper_Destroy
  AuxSpriteGfx gfx;          // 0x44, 根拠: LevelUpper_InitSprite
  u16 unk_60;                // 0x60, LevelUpper_Update
  u16 unk_62;                // 0x62, LevelUpper_Update
  u16 unk_64;                // 0x64, FUN_080a841c
  u16 unk_66;                // 0x66
  u16 weaponLv[5];           // 0x68, 武器レベル, = GameInfo.weaponExp[n]/100
  u8 unk_72[2];              // 0x72
  u32 nextExp;               // 0x74, 次にレベルアップする総経験値量
  u32* expTable;             // 0x78, 経験値テーブル, gExpTable
  ParticleGroup* group2;     // 0x7C, PTCL_GROUP_2
  LevelUpParticle ptcls[8];  // 0x80
} LevelUpper;
static_assert(sizeof(LevelUpper) == 608);

IWRAM_DATA LevelUpper* gLevelUpper = NULL;  // 0x03000154

// 次のレベルになるために必要な"総"経験値量を返す
static u32 GetNextLvExp(LevelUpper* p, s32 lv) {
  // = return p->expTable[lv] * 10;
  u32* exp = p->expTable;
  exp += lv;
  return 10 * (*exp);
}

// 次のレベルの経験値に達していればレベルを 1 上げてステータスポイントを 3 増やす
NON_MATCH bool32 TryPlayerLevelUp(LevelUpper* p) {
#ifdef NONMATCHING_C
  s16* lv = &gStat->lv;

  if (*lv > 98 || gStat->exp < p->nextExp) {
    return FALSE;
  }
  (*lv)++;
  gStat->statusPoint += 3;
  p->nextExp = GetNextLvExp(p, gStat->lv);
  return TRUE;
#else
  INCFUNC("asm/func/TryPlayerLevelUp.inc");
#endif
}

// 前回記録した武器レベルから変わった武器があれば TRUE を返す
bool32 IsWeaponLevelChanged(LevelUpper* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    u16 lv = p->weaponLv[i];
    if (lv != GetWeaponSkillLevel(i)) {
      return TRUE;
    }
  }
  return FALSE;
}

// 粒子をプレイヤーの周りのランダムな位置に出し直す
void FUN_080a8250(LevelUpParticle* p) {
  u16* table;
  Player* player;

  p->base.flags &= ~SPRFLAG_HIDDEN;
  table = gRandomTable;
  p->offset.x = ((_Random(table) >> 3) & 0x7F) - 63;
  p->offset.y = ((_Random(table) >> 3) & 0x3F) + 64;
  p->offset.z = ((_Random(table) >> 3) & 0x7F) - 63;
  player = gPlayerPtr[0];
  p->base.pos.x = player->mover.pos.x + p->offset.x;
  p->base.pos.y = player->mover.pos.y + p->offset.y;
  p->base.pos.z = player->mover.pos.z + p->offset.z;
  p->unk_30 = 0;
  p->unk_32 = (_Random(table) & 7) + 12;
  p->unk_34 = 0;
  p->unk_3a = 0;
  p->unk_38 = 1;
}

// 粒子をプレイヤーの位置に追従させながら上昇させ、4 フレームごとに見た目を切り替える, 16 フレームで消える
void LevelUpper_UpdateParticle(LevelUpParticle* p, ParticleGroup* g) {
  Player* player;

  if (++p->unk_3a > 15) {
    p->base.flags |= 1;
    p->unk_38 = 0;
  } else {
    p->offset.y += p->unk_32;
    player = gPlayerPtr[0];
    p->base.pos.x = player->mover.pos.x + p->offset.x;
    p->base.pos.y = player->mover.pos.y + p->offset.y;
    p->base.pos.z = player->mover.pos.z + p->offset.z;
    if ((p->unk_3a >> 2) & 1) {
      Particle_SetPose(&p->base, g, PTCL2_SOL_S);
    } else {
      Particle_SetPose(&p->base, g, PTCL2_SOL_L);
    }
  }
}

// レベルアップ演出のスプライトをプレイヤーの頭上に配置し、パーティクル8個を初期化する
void LevelUpper_EmitLevelUpEffect(LevelUpper* p) {
  s32 i;
  AuxSprite_Show(&p->sprite);
  AuxSprite_SetPoseIdx(&p->sprite, 0);
  p->sprite.pos = gPlayerPtr[0]->mover.pos;
  p->sprite.pos.y += 250;
  p->unk_64 = 0;
  p->unk_62 = 1;
  p->unk_60 = 1;
  for (i = 0; i < 8; i++) {
    Particle_SetPose(&p->ptcls[i].base, p->group2, PTCL2_0);
  }
}

// 武器レベルアップ演出のスプライトをプレイヤーの頭上に配置する
void LevelUpper_EmitWeaponLevelUpEffect(LevelUpper* p) {
  AuxSprite_Show(&p->sprite);
  AuxSprite_SetPoseIdx(&p->sprite, 3);
  p->sprite.pos = gPlayerPtr[0]->mover.pos;
  p->sprite.pos.y += 250;
  p->unk_64 = 0;
  p->unk_62 = 1;
  p->unk_60 = 2;
}

// レベルアップ (unk_60 = 1) と武器レベルアップ (unk_60 = 2) の演出をプレイヤーの頭上で進める
// 残差: 213 対 220 命令, 原典は timer < 5 の上昇処理を unk_60 の分岐ごとに持ち, 揺らしと +400 の末尾だけを共有する
NON_MATCH void FUN_080a841c(LevelUpper* p) {
#ifdef NONMATCHING_C
  if (p->unk_62 == 0) {
    return;
  }
  if (p->unk_60 == 1) {
    s32 i;

    for (i = 0; i < 8; i++) {
      if (p->ptcls[i].unk_38 != 0) {
        LevelUpper_UpdateParticle(&p->ptcls[i], p->group2);
      }
    }
    if (p->unk_64 < 64 && (p->unk_64 & 3) == 0) {
      FUN_080a8250(&p->ptcls[(p->unk_64 >> 2) & 7]);
    }
    p->unk_64++;
    p->sprite.pos = gPlayerPtr[0]->mover.pos;
    if (p->unk_64 > 119) {
      if (p->unk_64 < 123) {
        p->sprite.pos.y += 400;
        p->sprite.poseIdx = 1;
        return;
      }
      if (p->unk_64 < 126) {
        p->sprite.pos.y += 400;
        p->sprite.poseIdx = 2;
        return;
      }
      p->sprite.flags |= SPRFLAG_HIDDEN;
      p->unk_62 = 0;
      p->unk_60 = 0;
      return;
    }
    p->sprite.poseIdx = 0;
  } else if (p->unk_60 == 2) {
    p->unk_64++;
    p->sprite.pos = gPlayerPtr[0]->mover.pos;
    if (p->unk_64 > 119) {
      if (p->unk_64 < 123) {
        p->sprite.pos.y += 400;
        p->sprite.poseIdx = 4;
        return;
      }
      if (p->unk_64 < 126) {
        p->sprite.pos.y += 400;
        p->sprite.poseIdx = 2;
        return;
      }
      p->sprite.flags |= SPRFLAG_HIDDEN;
      p->unk_62 = 0;
      p->unk_60 = 0;
      return;
    }
    p->sprite.poseIdx = 3;
  } else {
    p->sprite.flags |= SPRFLAG_HIDDEN;
    p->unk_62 = 0;
    p->unk_60 = 0;
    return;
  }
  if (p->unk_64 < 5) {
    p->sprite.pos.y = p->sprite.pos.y + 250 + p->unk_64 * 30;
  } else {
    if (p->unk_64 < 20) {
      p->sprite.pos.x += -15 + (Random() & 31);
      p->sprite.pos.y += -15 + (Random() & 31);
      p->sprite.pos.z += -15 + (Random() & 31);
    }
    p->sprite.pos.y += 400;
  }
#else
  INCFUNC("asm/func/FUN_080a841c.inc");
#endif
}

s32 LevelUpper_Update(LevelUpper* p) {
  s32 i, j;

  if (gPlayerPtr[0] != NULL) {
    if (gPlayerPtr[0]->mode == PMODE_DEAD) {
      if (p->unk_62 == 1) {
        p->sprite.flags |= SPRFLAG_HIDDEN;
        p->unk_62 = 0;
        for (j = 0; j < 8; j++) {
          p->ptcls[j].base.flags |= SPRFLAG_HIDDEN;
          p->ptcls[j].unk_38 = 0;
        }
      }
    } else {
      FUN_080a841c(p);
      if (TryPlayerLevelUp(p)) {
        LevelUpper_EmitLevelUpEffect(p);
        PlaySound_082406e0(SE_LEVEL_UP);
      } else if (p->unk_60 == 0 && IsWeaponLevelChanged(p)) {
        LevelUpper_EmitWeaponLevelUpEffect(p);
        PlaySound_082406e0(SE_WEAPON_LV_UP);
      }
      for (i = 0; i < 5; i++) {
        p->weaponLv[i] = GetWeaponSkillLevel(i);
      }
    }
  }
  return 0;
}

s32 LevelUpper_Destroy(LevelUpper* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);
  for (i = 0; i < 8; i++) {
    Particle_Remove(&p->ptcls[i].base);
  }
  gLevelUpper = NULL;
  return 0;
}

// 演出用のスプライトを読み込み、非表示のまま描画ノードに登録する
void LevelUpper_InitSprite(LevelUpper* p) {
  AuxSpriteGfx* gfx = &p->gfx;

  Video_GetAuxSprite(gfx, SPRITE_LVUP_INDICATOR);
  AuxSprite_Add(&p->sprite, gfx, 0);
  Video_SetAuxSpritePltt(gfx, 1);
  p->sprite.flags |= SPRFLAG_HIDDEN;
  p->sprite.priority = 1;
}

// 演出用の粒子 8 個を非表示のまま作る
void LevelUpper_InitParticles(LevelUpper* p) {
  s32 i;

  p->group2 = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 8; i++) {
    Particle_Add(&p->ptcls[i].base, p->group2, SPRFLAG_HIDDEN);
    Particle_SetPose(&p->ptcls[i].base, p->group2, PTCL2_0);
    Particle_SetOffset(&p->ptcls[i].base, -4, -4);
    Particle_SetPltt(&p->ptcls[i].base, 1);
  }
}

s32 LevelUpper_Init(LevelUpper* p) {
  s32 i;

  if (VM_SeekToNamedArg('e')) {
    p->expTable = VM_GetValueSafe2();
  }
  if (gStat->lv <= 98) {
    p->nextExp = GetNextLvExp(p, gStat->lv);
  }
  for (i = 0; i < 5; i++) {
    p->weaponLv[i] = GetWeaponSkillLevel(i);
  }
  LevelUpper_InitSprite(p);
  LevelUpper_InitParticles(p);
  gLevelUpper = p;
  return 0;
}

LevelUpper* LevelUpper_Create(u32 _) {
  LevelUpper* p;
  if (gLevelUpper == NULL) {
    p = CreateEntity(ENTITY_UNK_9, sizeof(LevelUpper));
    if (p != NULL) {
      SetEntityRoutine(p, LevelUpper_Update, LevelUpper_Destroy);
      if (LevelUpper_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gLevelUpper;
}
