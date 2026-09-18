#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

typedef struct {
  Particle base;  // 0x00
  Vec3 offset;    // 0x28, Player + offset が base.pos になる
  u16 unk_30;     // 0x30
  u16 unk_32;     // 0x32
  u8 unk_34[0x38 - 0x34];
  u16 unk_38;  // 0x38
  u16 unk_3a;  // 0x3A
} LevelUpParticle;
static_assert(sizeof(LevelUpParticle) == 60);  // 根拠: LevelUpper_EmitLevelUpEffect

// 現在の経験値を確認して、レベルアップする場合はレベルアップ処理を行う。
// またその際のパーティクルやSEなどの演出処理も行う。
typedef struct LevelUpper {
  Entity e;                  // 0x00, ENTITY_UNK_9
  AuxSprite q_node;          // 0x18, sprite を指す描画ノード, 根拠: LevelUpper_InitSprite / LevelUpper_Destroy
  AuxSpriteGfx sprite;       // 0x44, 根拠: LevelUpper_InitSprite
  u16 unk_60;                // 0x60, LevelUpper_Update
  u16 unk_62;                // 0x62, LevelUpper_Update
  u16 unk_64;                // 0x64, FUN_080a841c
  u16 unk_66;                // 0x66
  u16 weaponLv[5];           // 0x68, 武器レベル, = GameInfo.weaponExp[n]/100
  u8 unk_72[2];              // 0x72
  u32 nextExp;               // 0x74, 次にレベルアップする総経験値量
  u32* expTable;             // 0x78, 経験値テーブルの先頭アドレス, 常に 0x08D09FE8
  ParticleGroup* p_7c;       // 0x7C, 根拠: LevelUpper_EmitLevelUpEffect で FUN_0822dafc に渡される
  LevelUpParticle ptcls[8];  // 0x80
} LevelUpper;
static_assert(sizeof(LevelUpper) == 608);

extern LevelUpper* gLevelUpper;  // 0x03000154

void FUN_0822dafc(Particle* p, ParticleGroup* g, u32 val);
s32 GetWeaponSkillLevel(s32 idx);

// 次のレベルになるために必要な"総"経験値量を返す
u32 GetNextLvExp(LevelUpper* p, s32 lv) {
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
  u16 lv;

  for (i = 0; i < 5; i++) {
    lv = p->weaponLv[i];
    if (lv != GetWeaponSkillLevel(i)) {
      return TRUE;
    }
  }
  return FALSE;
}

NAKED void FUN_080a8250(LevelUpParticle* p) { INCFUNC("asm/func/FUN_080a8250.inc"); }

// 粒子をプレイヤーの位置に追従させながら上昇させ、4 フレームごとに見た目を切り替える, 16 フレームで消える
void LevelUpper_UpdateParticle(LevelUpParticle* p, ParticleGroup* g) {
  Player* player;

  if (++p->unk_3a > 15) {
    p->base.flags |= 1;
    p->unk_38 = 0;
  } else {
    p->offset.y += p->unk_32;
    player = gPlayerPtr[0];
    p->base.pos.x = player->unk_24.pos.x + p->offset.x;
    p->base.pos.y = player->unk_24.pos.y + p->offset.y;
    p->base.pos.z = player->unk_24.pos.z + p->offset.z;
    if ((p->unk_3a >> 2) & 1) {
      FUN_0822dafc(&p->base, g, 3);
    } else {
      FUN_0822dafc(&p->base, g, 2);
    }
  }
}

// レベルアップ演出のスプライトをプレイヤーの頭上に配置し、パーティクル8個を初期化する
void LevelUpper_EmitLevelUpEffect(LevelUpper* p) {
  s32 i;
  p->q_node.flags &= ~1;
  p->q_node.q_metaspriteIdx = 0;
  p->q_node.q_pos = gPlayerPtr[0]->unk_24.pos;
  p->q_node.q_pos.y += 250;
  p->unk_64 = 0;
  p->unk_62 = 1;
  p->unk_60 = 1;
  for (i = 0; i < 8; i++) {
    FUN_0822dafc(&p->ptcls[i].base, p->p_7c, 0);
  }
}

// 武器レベルアップ演出のスプライトをプレイヤーの頭上に配置する
NON_MATCH void LevelUpper_EmitWeaponLevelUpEffect(LevelUpper* p) {
#ifdef NONMATCHING_C
  p->q_node.flags &= ~1;
  p->q_node.q_metaspriteIdx = 3;
  p->q_node.q_pos = gPlayerPtr[0]->unk_24.pos;
  p->q_node.q_pos.y += 250;
  p->unk_64 = 0;
  p->unk_62 = 1;
  p->unk_60 = 2;
#else
  INCFUNC("asm/func/LevelUpper_EmitWeaponLevelUpEffect.inc");
#endif
}

NAKED void FUN_080a841c(LevelUpper* p) { INCFUNC("asm/func/FUN_080a841c.inc"); }

s32 LevelUpper_Update(LevelUpper* p) {
  s32 i, j;

  if (gPlayerPtr[0] != NULL) {
    if (gPlayerPtr[0]->unk_1c == 4) {
      if (p->unk_62 == 1) {
        p->q_node.flags |= 1;
        p->unk_62 = 0;
        for (j = 0; j < 8; j++) {
          p->ptcls[j].base.flags |= 1;
          p->ptcls[j].unk_38 = 0;
        }
      }
    } else {
      FUN_080a841c(p);
      if (TryPlayerLevelUp(p)) {
        LevelUpper_EmitLevelUpEffect(p);
        PlaySound_082406e0(0x388);
      } else if (p->unk_60 == 0 && IsWeaponLevelChanged(p)) {
        LevelUpper_EmitWeaponLevelUpEffect(p);
        PlaySound_082406e0(0x381);
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

  FUN_0822a4e0(&p->q_node);
  for (i = 0; i < 8; i++) {
    FUN_0822dabc(&p->ptcls[i].base);
  }
  gLevelUpper = NULL;
  return 0;
}

// 演出用のスプライトを読み込み、非表示のまま描画ノードに登録する
void LevelUpper_InitSprite(LevelUpper* p) {
  AuxSpriteGfx* sprite = &p->sprite;

  Video_GetAuxSprite(sprite, SPRITE_LVUP_INDICATOR);
  FUN_0822a470(&p->q_node, sprite, 0);
  Video_SetAuxSpritePltt(sprite, 1);
  p->q_node.flags |= 1;
  p->q_node.priority = 1;
}

// 演出用の粒子 8 個を非表示のまま作る
void LevelUpper_InitParticles(LevelUpper* p) {
  s32 i;

  p->p_7c = GetParticleGroup(PTCL_GROUP_2);
  for (i = 0; i < 8; i++) {
    FUN_0822d9f0(&p->ptcls[i].base, p->p_7c, 1);
    FUN_0822dafc(&p->ptcls[i].base, p->p_7c, 0);
    FUN_0822dad4(&p->ptcls[i].base, -4, -4);
    FUN_0822dadc(&p->ptcls[i].base, 1);
  }
}

s32 LevelUpper_Init(LevelUpper* p) {
  s32 i;

  if (VM_SeekToKeyword('e')) {
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
