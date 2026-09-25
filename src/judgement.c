#include "entity.h"
#include "particle.h"
#include "player.h"
#include "sprite.h"
#include "global.h"

struct JudgementParticle;
typedef void (*JudgementParticleFunc)(struct JudgementParticle* ptcl);
struct Judgement;
typedef void (*JudgementFunc)(struct Judgement* p);

// 演出で飛ばす粒子1個ぶんの枠。8個を使い回す
typedef struct JudgementParticle {
  Particle ptcl;           // 0x00, _Destroy が Particle_Remove に渡す
  u8 unk_28[2];            // 0x28
  u16 active;              // 0x2A, FUN_080a98c0 が 0 の枠を飛ばす
  u8 unk_2c[12];           // 0x2C
  JudgementParticleFunc fn;  // 0x38, FUN_080a98c0 が active な枠について呼ぶ
} JudgementParticle;
static_assert(sizeof(JudgementParticle) == 60);

// "審判のカード" (ITEM_JUDGEMENT, 全回復して復活) の 効果処理 及び 演出
typedef struct Judgement {
  Entity e;                  // 0x000, ENTITY_UNK_11
  Player* player;            // 0x018, _Init の第2引数
  MainSprite sprite;         // 0x01C, _Destroy が MainSprite_Remove に渡す
  u8 unk_7c[8];              // 0x07C
  Vec3 screen;               // 0x084, player->unk_24.pos の y に +0x96 した点を投影した画面座標
  JudgementParticle ptcls[8];  // 0x08C, 根拠: _Destroy の stride 0x3C × 8
  u8 unk_26c[4];             // 0x26C
  u16 timer;                 // 0x270, _Init が 0。各状態関数が +1 する
  u8 unk_272[2];             // 0x272
  JudgementFunc updateCallback;  // 0x274, _Update が毎フレーム呼ぶ
} Judgement;
static_assert(sizeof(Judgement) == 632);

INCASM("asm/judgement.inc");
