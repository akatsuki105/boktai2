#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "player.h"
#include "sprite.h"

struct Entity08080be8;
typedef void (*Entity08080be8Func)(struct Entity08080be8* p);

// FUN_080804a0 が1個ずつ撒く粒子。4個を順に使い回す
typedef struct {
  Particle base;   // 0x00, FUN_0822d9f0 や Particle_Remove に Particle* として渡る
  bool8 active;    // 0x28, FUN_080804a0 が 1 にし、FUN_080803b4 が寿命で 0 に戻す。0 の間は動かさない
  s8 angleOffset;  // 0x29, Mod(rand, 0x60) - 0x30。dir から作る8bit角度に足してばらつかせる
  u16 radius;      // 0x2A, (rand >> 3 & 0x7F) + 0x40。gSineTable に掛けて >> 12 したものが base.pos のずれになる
  u16 timer;       // 0x2C, 毎フレーム +1 し 15 で寿命。距離が radius * (0x10 - timer) >> 3 なので中心へ寄っていく
  u8 unk_2e[2];    // 0x2E, padding?
} Entity08080be8Particle;
static_assert(sizeof(Entity08080be8Particle) == 48);

// プレイヤーの周りに粒子を撒きながら当たり判定を出すエフェクト。ENE を消費し、チャージ量で威力と絵が変わる
typedef struct Entity08080be8 {
  Entity e;                           // 0x000, ENTITY_UNK_8
  Player* player;                     // 0x018, Init の第1引数
  AuxSprite sprite;                   // 0x01C
  AuxSpriteGfx gfx;                   // 0x048, SPRITE_210E
  HitboxData hitbox;                  // 0x064, FUN_08080a44 が組み立て、位置は sprite.pos を見る
  Vec3 offset;                        // 0x0B4, FUN_08080204 が offsetRadius から x と z を作り、FUN_0808094c が sprite.pos に足す
  u16 heightOffset;                   // 0x0BC, Init の第3引数。FUN_08080204 が sprite.pos.y に足す
  u16 unk_be;                         // 0x0BE, Init の第4引数。FUN_08080204 で gSineTable に掛ける
  u16 unk_c0;                         // 0x0C0, Init の第5引数。unk_be と対で使う
  u16 offsetRadius;                   // 0x0C2, Init の第6引数。offset.x と offset.z の大きさ
  u16 eneCost;                        // 0x0C4, Init の第12引数。FUN_0808065c が Player_ReduceENE_0807aa60 に渡す
  u8 unk_c6[2];                       // 0x0C6
  u8 dir;                             // 0x0C8, プレイヤーの向きから作る 0..7 の方向。8bit角度の基準になる
  u8 charge;                          // 0x0C9, player の 0xA8F の写し。damage を 1 + charge/2 倍にし、sprite.metaspriteIdx にも入る
  u16 timer;                          // 0x0CA, Entity08080be8_SetState が状態を変えるたび 0 に戻し、各状態が毎フレーム +1 する
  u8 ptclIdx;                         // 0x0CC, 次に撒く ptcls の添字。4 で 0 に戻る
  u8 unk_cd;                          // 0x0CD, Init の第13引数。hitbox のオフセットを変え、0 以外なら damage が 8 固定になる
  u8 unk_ce[2];                       // 0x0CE
  ParticleGroup* group;               // 0x0D0, PTCL_GROUP_2
  Entity08080be8Particle ptcls[4];    // 0x0D4, 根拠: FUN_08080af4 / Entity08080be8_ClearParticles / _Destroy の stride 0x30 × 4 のループ
  Entity08080be8Func updateCallback;  // 0x194, _Update が毎フレーム呼ぶ状態関数
} Entity08080be8;
static_assert(sizeof(Entity08080be8) == 408);

void FUN_0808094c(Entity08080be8* p);

// 状態関数を差し替えて経過フレームを 0 に戻す
void Entity08080be8_SetState(Entity08080be8* p, Entity08080be8Func fn) {
  p->updateCallback = fn;
  p->timer = 0;
}

NAKED void FUN_08080204(Entity08080be8* p) { INCFUNC("asm/func/FUN_08080204.inc"); }

NAKED void FUN_080803b4(Entity08080be8* p) { INCFUNC("asm/func/FUN_080803b4.inc"); }

NAKED void FUN_080804a0(Entity08080be8* p) { INCFUNC("asm/func/FUN_080804a0.inc"); }

// 撒いた粒子を全部止めて消す
void Entity08080be8_ClearParticles(Entity08080be8* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    p->ptcls[i].active = 0;
    p->ptcls[i].base.flags |= SPRFLAG_HIDDEN;
  }
}

void FUN_08080648(HitboxData* a, HitboxData* b, Entity08080be8* p) { Entity08080be8_SetState(p, FUN_0808094c); }

NAKED void FUN_0808065c(Entity08080be8* p) { INCFUNC("asm/func/FUN_0808065c.inc"); }

NAKED u32 FUN_080806a4(Entity08080be8* p) { INCFUNC("asm/func/FUN_080806a4.inc"); }

NAKED void FUN_080806ec(Entity08080be8* p) { INCFUNC("asm/func/FUN_080806ec.inc"); }

NAKED void FUN_080807f4(Entity08080be8* p) { INCFUNC("asm/func/FUN_080807f4.inc"); }

NAKED void FUN_080808cc(Entity08080be8* p) { INCFUNC("asm/func/FUN_080808cc.inc"); }

NAKED void FUN_0808094c(Entity08080be8* p) { INCFUNC("asm/func/FUN_0808094c.inc"); }

s32 Entity08080be8_Update(Entity08080be8* p) {
  p->updateCallback(p);
  return 0;
}

s32 Entity08080be8_Destroy(Entity08080be8* p) {
  s32 i;

  AuxSprite_Remove(&p->sprite);
  for (i = 0; i < 4; i++) {
    Particle_Remove(&p->ptcls[i].base);
  }
  return 0;
}

NAKED void FUN_08080a10(Entity08080be8* p, s32 plttID) { INCFUNC("asm/func/FUN_08080a10.inc"); }

NAKED void FUN_08080a44(Entity08080be8* p, u32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_08080a44.inc"); }

NAKED void FUN_08080af4(Entity08080be8* p, s32 val) { INCFUNC("asm/func/FUN_08080af4.inc"); }

NAKED s32 Entity08080be8_Init(Entity08080be8* p, Player* player, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9, u32 param_10, u32 param_11, u32 param_12, u32 param_13) { INCFUNC("asm/func/Entity08080be8_Init.inc"); }

NAKED Entity08080be8* Entity08080be8_Create(Player* player, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9, u32 param_10, u32 param_11, u32 param_12) { INCFUNC("asm/func/Entity08080be8_Create.inc"); }
