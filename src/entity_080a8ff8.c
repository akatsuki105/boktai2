#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "sprite_aux.h"

// FUN_080a8dd8 が 8個ばらまく粒子。Particle に角度と半径を足しただけ
typedef struct {
  Particle base;  // 0x00, FUN_0822d9f0 などに Particle* として渡る
  u16 angle;      // 0x28, gSineTable[(angle + 0x40) & 0xFF] と gSineTable[angle & 0xFF] で x/z のオフセットを作る
  u16 radius;     // 0x2A, 上の sin に掛けて >> 12 する
} Entity080a8ff8Particle;
static_assert(sizeof(Entity080a8ff8Particle) == 44);

typedef struct {
  Entity e;                             // 0x000, ENTITY_UNK_8
  Player* owner;                        // 0x018, Init の第2引数。owner->unk_3fb がこのエンティティの生存数カウンタ
  AuxSprite sprite;                     // 0x01C, 根拠: AuxSprite_Add に AuxSprite* として渡る
  AuxSpriteGfx gfx;                     // 0x048, 根拠: Video_GetActorSprite(&gfx, BOMB)
  Vec3 pos;                             // 0x064, Init が引数の Vec3 をまるごと写す
  Entity080a8ff8Particle particles[8];  // 0x06C, 根拠: FUN_080a8dd8 の i=0..7 / stride 0x2C のループ
  ParticleGroup* group;                 // 0x1CC, GetParticleGroup(GROUP_2) の戻り値
  s16 mode;                             // 0x1D0, Init の第4引数。0 かどうかで fuseTimer の減り方と timeoutTimer の有無が変わる
  u16 phaseLen;                         // 0x1D2, fuseTimer の初期値 / 3。カウントダウンを3段階に分けてスプライト番号を変える
  u16 fuseTimer;                        // 0x1D4, Init が 0xB4/0x5A/0x78 を入れる。0 で爆発して KillEntity
  u16 timeoutTimer;                     // 0x1D6, Init が 900。mode == 0 のときだけ減り、0 で爆発せずに KillEntity
  u8 unk_1d8[2];                        // 0x1D8, 読み書きするコードが見つかっていない
  u16 stateTimer;                       // 0x1DA, Entity080a8ff8_SetState が 0 に戻し、各状態が毎フレーム +1 する
  void* fn;                             // 0x1DC, Entity080a8ff8_Update が p->fn(p) として呼ぶ状態関数
} Entity080a8ff8;
static_assert(sizeof(Entity080a8ff8) == 480);

NAKED void Entity080a8ff8_SetState(Entity080a8ff8* p, void* fn) { INCFUNC("asm/func/Entity080a8ff8_SetState.inc"); }

NAKED void FUN_080a881c(Entity080a8ff8* p) { INCFUNC("asm/func/FUN_080a881c.inc"); }

NAKED void FUN_080a8950(Entity080a8ff8* p) { INCFUNC("asm/func/FUN_080a8950.inc"); }

NAKED void FUN_080a8cfc(Entity080a8ff8* p) { INCFUNC("asm/func/FUN_080a8cfc.inc"); }

NAKED s32 Entity080a8ff8_Update(Entity080a8ff8* p) { INCFUNC("asm/func/Entity080a8ff8_Update.inc"); }

NAKED s32 Entity080a8ff8_Destroy(Entity080a8ff8* p) { INCFUNC("asm/func/Entity080a8ff8_Destroy.inc"); }

NAKED void FUN_080a8d78(Entity080a8ff8* p) { INCFUNC("asm/func/FUN_080a8d78.inc"); }

NAKED void FUN_080a8dd8(Entity080a8ff8* p) { INCFUNC("asm/func/FUN_080a8dd8.inc"); }

NAKED s32 Entity080a8ff8_Init(Entity080a8ff8* p, Player* owner, Vec3* pos, s16 mode) { INCFUNC("asm/func/Entity080a8ff8_Init.inc"); }

NAKED Entity080a8ff8* Entity080a8ff8_Create(Player* owner, Vec3* pos, s16 mode) { INCFUNC("asm/func/Entity080a8ff8_Create.inc"); }
