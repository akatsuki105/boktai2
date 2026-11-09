#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite.h"

// ドヴァリンの"墨玉"

// 墨玉の弾1発, 何かに当たるか life が尽きると砕けて InkBallPuddle (墨だまり) を残す
typedef struct InkBallShot {
  AuxSprite sprite;     // 0x00, SPRFLAG_HIDDEN が立っていて life が 0 なら空き
  AuxAnimState anim;    // 0x2C, ANIM_38E2 の 2 番
  HitboxData hurtbox;   // 0x3C, 攻撃を受けると InkBallShot_OnHurt で消える
  HitboxData hitbox;    // 0x8C, 当たると InkBallShot_OnHit で砕け始める
  Vec3 vel;             // 0xDC, homing のときは毎フレーム target へ向けて speed の長さに作り直す
  Vec3 target;          // 0xE4
  u16 life;             // 0xEC, 0 でなければ使用中, 飛んでいる間毎フレーム減らし 5 以下で砕ける
  u16 hurtboxDelay;     // 0xEE, 0 になるまで hurtbox に HBFLAG_HIDDEN を立てておく
  u16 puddlePower;      // 0xF0, 砕けたときに残す InkBallPuddle の power
  u16 puddleKnockback;  // 0xF2, 同 knockback
  u16 puddleAttrs;      // 0xF4, 同 attrs
  u16 puddleIframes;    // 0xF6, 同 iframes
  u16 puddleTtl;        // 0xF8, 同 ttl
  u8 state;             // 0xFA, sInkBallShotStates の添字
  u8 stateTimer;        // 0xFB, state に入ってからのフレーム数, 0 のとき最初の更新
  u16 speed;            // 0xFC, homing のときの速さ
  bool8 homing;         // 0xFE, target へ向かって飛ぶなら 1
  u8 unk_ff[5];         // 0xFF, 読み手も書き手も未発見
} InkBallShot;
static_assert(sizeof(InkBallShot) == 260);

typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx;       // 0x018, SPRITE_DVALIN_2E78
  AuxAnimFile* animFile;  // 0x034, ANIM_38E2
  u32 unk_38;             // 0x038, Init が 0 を書くだけで読み手は未発見
  u8 activeCount;         // 0x03C, 使用中の shots の数
  u8 unk_3d[3];           // 0x03D, padding?
  InkBallShot shots[8];   // 0x040
} InkBallShotManager;
static_assert(sizeof(InkBallShotManager) == 2144);

static InkBallShotManager* gInkBallShotManager;  // 0x03000218

void InkBallShot_StateFly(InkBallShotManager* p, InkBallShot* shot);
void InkBallShot_StateBurstStart(InkBallShotManager* p, InkBallShot* shot);
void InkBallShot_StateBurstEnd(InkBallShotManager* p, InkBallShot* shot);

void (*const sInkBallShotStates[3])(InkBallShotManager*, InkBallShot*) = {
    InkBallShot_StateFly,
    InkBallShot_StateBurstStart,
    InkBallShot_StateBurstEnd,
};  // 0x085AE818

NAKED void InkBallShot_SetState(InkBallShot* shot, u32 state) { INCFUNC("asm/func/InkBallShot_SetState.inc"); }

NAKED void InkBallShot_OnHit(HitboxData* a, HitboxData* b, InkBallShot* shot) { INCFUNC("asm/func/InkBallShot_OnHit.inc"); }

NAKED void InkBallShot_OnHurt(HitboxData* a, HitboxData* b, InkBallShot* shot) { INCFUNC("asm/func/InkBallShot_OnHurt.inc"); }

NAKED void InkBallShot_InitHurtbox(InkBallShot* shot) { INCFUNC("asm/func/InkBallShot_InitHurtbox.inc"); }

NAKED void InkBallShot_InitHitbox(InkBallShot* shot, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) { INCFUNC("asm/func/InkBallShot_InitHitbox.inc"); }

NAKED InkBallShot* InkBallShotManager_FindFree(void) { INCFUNC("asm/func/InkBallShotManager_FindFree.inc"); }

NAKED void InkBallShotManager_Add(Vec3* pos, Vec3* vel, Vec3* target, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 life, s32 hurtboxDelay, s32 puddlePower, s32 puddleKnockback, s32 puddleAttrs, s32 puddleIframes, s32 puddleTtl) {
  INCFUNC("asm/func/InkBallShotManager_Add.inc");
}

NAKED void InkBallShotManager_Remove(InkBallShot* shot) { INCFUNC("asm/func/InkBallShotManager_Remove.inc"); }

NAKED void InkBallShot_StateFly(InkBallShotManager* p, InkBallShot* shot) { INCFUNC("asm/func/InkBallShot_StateFly.inc"); }

NAKED void InkBallShot_StateBurstStart(InkBallShotManager* p, InkBallShot* shot) { INCFUNC("asm/func/InkBallShot_StateBurstStart.inc"); }

NAKED void InkBallShot_StateBurstEnd(InkBallShotManager* p, InkBallShot* shot) { INCFUNC("asm/func/InkBallShot_StateBurstEnd.inc"); }

NAKED s32 InkBallShotManager_Update(InkBallShotManager* p) { INCFUNC("asm/func/InkBallShotManager_Update.inc"); }

NAKED s32 InkBallShotManager_Destroy(InkBallShotManager* p) { INCFUNC("asm/func/InkBallShotManager_Destroy.inc"); }

NAKED s32 InkBallShotManager_InitShots(InkBallShotManager* p) { INCFUNC("asm/func/InkBallShotManager_InitShots.inc"); }

NAKED s32 InkBallShotManager_Init(InkBallShotManager* p) { INCFUNC("asm/func/InkBallShotManager_Init.inc"); }

NAKED InkBallShotManager* InkBallShotManager_Create(void) { INCFUNC("asm/func/InkBallShotManager_Create.inc"); }

NAKED s32 InkBallShot_SpawnAngled(Vec3* pos, u32 angle, s32 speed, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 life, s32 hurtboxDelay, s32 puddlePower, s32 puddleKnockback, s32 puddleAttrs, s32 puddleIframes, s32 puddleTtl) {
  INCFUNC("asm/func/InkBallShot_SpawnAngled.inc");
}

NAKED s32 InkBallShot_Spawn(Vec3* pos, Vec3* vel, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 life, s32 hurtboxDelay, s32 puddlePower, s32 puddleKnockback, s32 puddleAttrs, s32 puddleIframes, s32 puddleTtl) { INCFUNC("asm/func/InkBallShot_Spawn.inc"); }

NAKED s32 InkBallShot_SpawnHoming(Vec3* pos, Vec3* target, u32 speed, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 life, s32 hurtboxDelay, s32 puddlePower, s32 puddleKnockback, s32 puddleAttrs, s32 puddleIframes, s32 puddleTtl) {
  INCFUNC("asm/func/InkBallShot_SpawnHoming.inc");
}
