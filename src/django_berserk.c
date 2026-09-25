#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "player.h"
#include "sprite.h"

struct DjangoBerserk;
typedef void (*DjangoBerserkFunc)(struct DjangoBerserk* p);

// プレイヤーの周りを旋回する粒子1個ぶんの枠,16個を使い回す
typedef struct {
  Particle ptcl;  // 0x00, Particle_Remove / FUN_0822dafc に Particle* として渡る
  bool8 active;   // 0x28, FUN_0807f8d0 が 0 の枠を飛ばし、lifetime が尽きると 0 に戻す
  u8 angle;       // 0x29, FUN_0807f650 が毎フレーム angleStep を足し、gSineTable の8bit索引にする
  u8 riseSpeed;   // 0x2A, FUN_0807f650 が ptcl.pos.y に足す
  u8 startDelay;  // 0x2B, frameCounter がこれを超えるまで radius の伸びが 1/フレームに抑えられる
  u8 animTimer;   // 0x2C, 0..7 を巡回,0 で anim 4、4 で anim 5 に差し替える
  u8 angleStep;   // 0x2D, angle に足す量,8フレームごとに 2 まで減衰する
  u8 lifetime;    // 0x2E, FUN_0807f8d0 が毎フレーム -1,0 で ptcl を隠して active を落とす
  u8 mode;        // 0x2F, 0 なら FUN_0807f650 (旋回)、それ以外なら FUN_0807f750 (直進)
  u16 radius;     // 0x30, 旋回半径,startDelay 経過後は毎フレーム +6、手前は +1
  u8 unk_32[2];   // 0x32, padding?
  Vec3 vel;       // 0x34, FUN_0807f750 が ptcl.pos.x と .z に足す (y は読まれない)
} DjangoBerserkParticle;
static_assert(sizeof(DjangoBerserkParticle) == 60);

// 黒ジャンゴが暴走する処理(暴走: プレイヤーのHPが半分になるが、画面上の全ての敵にダメージ)
typedef struct DjangoBerserk {
  Entity e;                          // 0x000, ENTITY_UNK_11
  Player* player;                    // 0x018, Init の第1引数
  MainSpriteGfx gfx;                 // 0x01C
  MainSprite sprite;                 // 0x03C
  HitboxData hitbox;                 // 0x09C, FUN_0807fdac が Hitbox_Register に渡す
  u8 unk_ec[2];                      // 0x0EC
  u16 timer;                         // 0x0EE, SetState が状態を差し替えるたび 0 に戻す
  u16 hpDrainStep;                   // 0x0F0, Init: (player->hp - hpTarget) / 0x48 + 1,毎フレーム player->hp から引く量
  u16 hpTarget;                      // 0x0F2, Init: player->hp >> 1 (0 なら 1),ここまで削って止める
  ParticleGroup* group;              // 0x0F4, FUN_0822dafc の第2引数
  DjangoBerserkParticle ptcls[16];   // 0x0F8, 根拠: _Destroy が stride 0x3C で 16回 Particle_Remove する
  u16 frameCounter;                  // 0x4B8, FUN_0807f8d0 が毎フレーム +1,リセットされない,ptcls[].startDelay と比較される
  u8 unk_4ba[6];                     // 0x4BA
  DjangoBerserkFunc updateCallback;  // 0x4C0, _Update が毎フレーム呼ぶ状態関数
} DjangoBerserk;
static_assert(sizeof(DjangoBerserk) == 1220);

// 状態関数を差し替えて経過フレームを 0 に戻す
void DjangoBerserk_SetState(DjangoBerserk* p, DjangoBerserkFunc fn) {
  p->updateCallback = fn;
  p->timer = 0;
}

NAKED void FUN_0807f650(DjangoBerserk* p, DjangoBerserkParticle* ptcl) { INCFUNC("asm/func/FUN_0807f650.inc"); }

NAKED void FUN_0807f750(DjangoBerserk* p, DjangoBerserkParticle* ptcl) { INCFUNC("asm/func/FUN_0807f750.inc"); }

NAKED void FUN_0807f78c(DjangoBerserk* p, Vec3* pos, u32 angle) { INCFUNC("asm/func/FUN_0807f78c.inc"); }

NAKED void FUN_0807f8d0(DjangoBerserk* p) { INCFUNC("asm/func/FUN_0807f8d0.inc"); }

NAKED void FUN_0807f94c(DjangoBerserk* p) { INCFUNC("asm/func/FUN_0807f94c.inc"); }

NAKED void FUN_0807f9d8(DjangoBerserk* p) { INCFUNC("asm/func/FUN_0807f9d8.inc"); }

NAKED void FUN_0807fd1c(DjangoBerserk* p) { INCFUNC("asm/func/FUN_0807fd1c.inc"); }

NAKED void FUN_0807fdac(DjangoBerserk* p) { INCFUNC("asm/func/FUN_0807fdac.inc"); }

s32 DjangoBerserk_Update(DjangoBerserk* p) {
  FUN_0807f8d0(p);
  p->updateCallback(p);
  return 0;
}

NAKED s32 DjangoBerserk_Destroy(DjangoBerserk* p) { INCFUNC("asm/func/DjangoBerserk_Destroy.inc"); }

NAKED void LoadPlayerSprite_0807fe48(DjangoBerserk* p) { INCFUNC("asm/func/LoadPlayerSprite_0807fe48.inc"); }

NAKED void FUN_0807fed0(DjangoBerserk* p) { INCFUNC("asm/func/FUN_0807fed0.inc"); }

NAKED void FUN_0807ff78(DjangoBerserk* p) { INCFUNC("asm/func/FUN_0807ff78.inc"); }

NAKED s32 DjangoBerserk_Init(DjangoBerserk* p, Player* player) { INCFUNC("asm/func/DjangoBerserk_Init.inc"); }

NAKED DjangoBerserk* DjangoBerserk_Create(Player* player) { INCFUNC("asm/func/DjangoBerserk_Create.inc"); }
