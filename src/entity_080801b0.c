#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "player.h"
#include "sprite.h"

struct DarkDjangoEffect;
typedef void (*DarkDjangoEffectFunc)(struct DarkDjangoEffect* p);

// プレイヤーの周りを旋回する粒子1個ぶんの枠。16個を使い回す
typedef struct {
  Particle ptcl;  // 0x00, Particle_Remove / FUN_0822dafc に Particle* として渡る
  bool8 active;   // 0x28, FUN_0807f8d0 が 0 の枠を飛ばし、lifetime が尽きると 0 に戻す
  u8 angle;       // 0x29, FUN_0807f650 が毎フレーム angleStep を足し、gSineTable の8bit索引にする
  u8 riseSpeed;   // 0x2A, FUN_0807f650 が ptcl.pos.y に足す
  u8 startDelay;  // 0x2B, frameCounter がこれを超えるまで radius の伸びが 1/フレームに抑えられる
  u8 animTimer;   // 0x2C, 0..7 を巡回。0 で anim 4、4 で anim 5 に差し替える
  u8 angleStep;   // 0x2D, angle に足す量。8フレームごとに 2 まで減衰する
  u8 lifetime;    // 0x2E, FUN_0807f8d0 が毎フレーム -1。0 で ptcl を隠して active を落とす
  u8 mode;        // 0x2F, 0 なら FUN_0807f650 (旋回)、それ以外なら FUN_0807f750 (直進)
  u16 radius;     // 0x30, 旋回半径。startDelay 経過後は毎フレーム +6、手前は +1
  u8 unk_32[2];   // 0x32
  Vec3 vel;       // 0x34, FUN_0807f750 が ptcl.pos.x と .z に足す (y は読まれない)
} DarkDjangoEffectParticle;
static_assert(sizeof(DarkDjangoEffectParticle) == 60);

// ダーク・ジャンゴへの変身エフェクト。プレイヤーの HP を半分まで削りながら粒子を旋回させる
typedef struct DarkDjangoEffect {
  Entity e;                             // 0x000, ENTITY_UNK_11
  Player* player;                       // 0x018, Init の第1引数
  MainSpriteGfx gfx;                    // 0x01C
  MainSprite sprite;                    // 0x03C
  HitboxData hitbox;                    // 0x09C, FUN_0807fdac が Hitbox_Register に渡す
  u8 unk_ec[2];                         // 0x0EC
  u16 timer;                            // 0x0EE, SetState が状態を差し替えるたび 0 に戻す
  u16 hpDrainStep;                      // 0x0F0, Init: (player->hp - hpTarget) / 0x48 + 1。毎フレーム player->hp から引く量
  u16 hpTarget;                         // 0x0F2, Init: player->hp >> 1 (0 なら 1)。ここまで削って止める
  ParticleGroup* group;                 // 0x0F4, FUN_0822dafc の第2引数
  DarkDjangoEffectParticle ptcls[16];   // 0x0F8, 根拠: _Destroy が stride 0x3C で 16回 Particle_Remove する
  u16 frameCounter;                     // 0x4B8, FUN_0807f8d0 が毎フレーム +1。リセットされない。ptcls[].startDelay と比較される
  u8 unk_4ba[6];                        // 0x4BA
  DarkDjangoEffectFunc updateCallback;  // 0x4C0, _Update が毎フレーム呼ぶ状態関数
} DarkDjangoEffect;
static_assert(sizeof(DarkDjangoEffect) == 1220);

INCASM("asm/entity_080801b0.inc");

NAKED void LoadPlayerSprite_0807fe48(DarkDjangoEffect* p) { INCFUNC("asm/func/LoadPlayerSprite_0807fe48.inc"); }

NAKED void FUN_0807fed0(DarkDjangoEffect* p) { INCFUNC("asm/func/FUN_0807fed0.inc"); }

NAKED void FUN_0807ff78(DarkDjangoEffect* p) { INCFUNC("asm/func/FUN_0807ff78.inc"); }

NAKED s32 DarkDjangoEffect_Init(DarkDjangoEffect* p, Player* player) { INCFUNC("asm/func/DarkDjangoEffect_Init.inc"); }

NAKED DarkDjangoEffect* DarkDjangoEffect_Create(Player* player) { INCFUNC("asm/func/DarkDjangoEffect_Create.inc"); }
