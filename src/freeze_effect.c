#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"

// FreezeEffect が中心の粒子の周りに出して、中心へ集めていく粒子
typedef struct {
  Particle base;  // 0x00, 根拠: FUN_080a8080
  u8 q_active;    // 0x28, 0 以外なら FUN_080a7b80 が中心へ近づける
  u8 q_frame;     // 0x29, FUN_080a7b80 で加算, 4 で見た目を切り替え, 6 で消える
  u8 unk_2a[2];
} q_FreezeParticle;
static_assert(sizeof(q_FreezeParticle) == 44);  // 根拠: FUN_080a8080 と FreezeEffect_Destroy のストライド 0x2C

// 魔法"フリーズ"で生成される氷のエフェクト
// 2フレームごとに subPtcls を中心の周りに出して中心へ集め、32フレーム後に FUN_080a7dc4 に移って消える
typedef struct {
  Entity e;                      // 0x00, ENTITY_UNK_8
  Vec3 pos;                      // 0x18, 根拠: FreezeEffect_Init
  HitboxData hitbox;             // 0x20, 根拠: FUN_080a7f88
  Particle ptcl;                 // 0x70, 中心の粒子, 根拠: FUN_080a802c
  ParticleGroup* ptclGroup;      // 0x98, GetParticleGroup(GROUP_0), 根拠: FUN_080a802c
  ParticleGroup* subPtclGroup;   // 0x9C, GetParticleGroup(GROUP_2), 根拠: FUN_080a8080
  q_FreezeParticle subPtcls[8];  // 0xA0, 根拠: FUN_080a8080
  u8 q_spawnIdx;                 // 0x200, 次に出す subPtcls の添字, 8 で折り返す, 根拠: FUN_080a7c64
  u8 q_spawnTimer;               // 0x201, subPtcls を出す間隔のカウンタ, 根拠: FUN_080a7c64
  u16 unk_202;                   // 0x202, FreezeEffect_Init で 0
  u16 unk_204;                   // 0x204, FreezeEffect_Create の第5引数 (MagicFreeze_08069710 は 90)
  u16 q_stateTimer;              // 0x206, 状態を切り替えると 0 に戻る, 根拠: FUN_080a7b68 / FUN_080a7d78
  void* fn_208;                  // 0x208, 現在の状態関数, 根拠: FUN_080a7b68
} FreezeEffect;
static_assert(sizeof(FreezeEffect) == 524);

void FUN_080a7b68(FreezeEffect* p, void* fn) {
  p->fn_208 = fn;
  p->q_stateTimer = 0;
}

NAKED void FUN_080a7b80(FreezeEffect* p) { INCFUNC("asm/func/FUN_080a7b80.inc"); }

NAKED void FUN_080a7c64(FreezeEffect* p) { INCFUNC("asm/func/FUN_080a7c64.inc"); }

NAKED void FUN_080a7d78(FreezeEffect* p) { INCFUNC("asm/func/FUN_080a7d78.inc"); }

NAKED void FUN_080a7dc4(FreezeEffect* p) { INCFUNC("asm/func/FUN_080a7dc4.inc"); }

NAKED s32 FreezeEffect_Update(FreezeEffect* p) { INCFUNC("asm/func/FreezeEffect_Update.inc"); }

NAKED s32 FreezeEffect_Destroy(FreezeEffect* p) { INCFUNC("asm/func/FreezeEffect_Destroy.inc"); }

NAKED void FUN_080a7f88(FreezeEffect* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080a7f88.inc"); }

NAKED void FUN_080a802c(FreezeEffect* p) { INCFUNC("asm/func/FUN_080a802c.inc"); }

NAKED void FUN_080a8080(FreezeEffect* p) { INCFUNC("asm/func/FUN_080a8080.inc"); }

NAKED s32 FreezeEffect_Init(FreezeEffect* p, Vec3* pos, s32 param_3, s32 param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/FreezeEffect_Init.inc"); }

NAKED FreezeEffect* FreezeEffect_Create(Vec3* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FreezeEffect_Create.inc"); }
