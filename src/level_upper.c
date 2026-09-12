#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "sprite.h"

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
  q_SpriteNode44 q_node;     // 0x18, sprite を指す描画ノード, 根拠: LevelUpper_Init_Helper_080a86cc / LevelUpper_Destroy
  ActorSpriteState sprite;   // 0x44, 根拠: LevelUpper_Init_Helper_080a86cc
  u16 unk_60;                // 0x60, LevelUpper_Update
  u16 unk_62;                // 0x62, LevelUpper_Update
  u16 unk_64;                // 0x64, FUN_080a841c
  u16 unk_66;                // 0x66
  s16 weaponLv[5];           // 0x68, 武器レベル, = GameInfo.weaponExp[n]/100
  u8 unk_72[2];              // 0x72
  u32 nextExp;               // 0x74, 次にレベルアップする総経験値量
  u32* expTable;             // 0x78, 経験値テーブルの先頭アドレス, 常に 0x08D09FE8
  ParticleGroup* p_7c;       // 0x7C, 根拠: LevelUpper_EmitLevelUpEffect で FUN_0822dafc に渡される
  LevelUpParticle ptcls[8];  // 0x80
} LevelUpper;
static_assert(sizeof(LevelUpper) == 608);

extern LevelUpper* gLevelUpper;  // 0x03000154

// 次のレベルになるために必要な"総"経験値量を返す
u32 GetNextLvExp(LevelUpper* p, s32 lv) {
  // = return p->expTable[lv] * 10;
  u32* exp = p->expTable;
  exp += lv;
  return 10 * (*exp);
}

NAKED bool32 TryPlayerLevelUp(LevelUpper* p) { INCFUNC("asm/func/TryPlayerLevelUp.inc"); }

NAKED bool32 IsWeaponLevelChanged(LevelUpper* p) { INCFUNC("asm/func/IsWeaponLevelChanged.inc"); }

NAKED void FUN_080a8250(LevelUpParticle* p) { INCFUNC("asm/func/FUN_080a8250.inc"); }

NAKED void FUN_080a8314(LevelUpParticle* p, unknown* param_2) { INCFUNC("asm/func/FUN_080a8314.inc"); }

void FUN_0822dafc(Particle* p, ParticleGroup* g, u32 val);

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

NAKED void FUN_080a83dc(LevelUpper* p) { INCFUNC("asm/func/FUN_080a83dc.inc"); }

NAKED void FUN_080a841c(LevelUpper* p) { INCFUNC("asm/func/FUN_080a841c.inc"); }

NAKED s32 LevelUpper_Update(LevelUpper* p) { INCFUNC("asm/func/LevelUpper_Update.inc"); }

NAKED s32 LevelUpper_Destroy(LevelUpper* p) { INCFUNC("asm/func/LevelUpper_Destroy.inc"); }

NAKED void LevelUpper_Init_Helper_080a86cc(LevelUpper* p) { INCFUNC("asm/func/LevelUpper_Init_Helper_080a86cc.inc"); }

NAKED void LevelUpper_Init_Helper_080a8704(LevelUpper* p) { INCFUNC("asm/func/LevelUpper_Init_Helper_080a8704.inc"); }

NAKED s32 LevelUpper_Init(LevelUpper* p) { INCFUNC("asm/func/LevelUpper_Init.inc"); }

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
