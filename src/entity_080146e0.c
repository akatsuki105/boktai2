#include "entity.h"
#include "global.h"
#include "particle.h"
#include "vm.h"

// 飛び散って消える粒子1個, 速度と重力で動き、寿命が来ると消える
typedef struct {
  u8 active;          // 0x00, 0 なら処理しない, 寿命が来ると 0 にして Particle_Remove で描画リストから外す
  u8 unk_01;          // 0x01, FUN_08014730 で 1, 読む箇所なし
  u8 age;             // 0x02, 毎フレーム +1, lifetime を超えたら消える
  u8 lifetime;        // 0x03, FUN_08014730 で lifeBase + (rand & lifeRandMask)
  u16 mapIdx;         // 0x04, 当たり判定マップのブロック番号, FUN_08014148 が前フレームの値と比べて跳ね返る向きを決める
  s16 height;         // 0x06, 毎フレーム velY を加算, 床の高さと比較
  s16 velX;           // 0x08, 毎フレーム particle.pos.x に加算
  s16 velY;           // 0x0A, 毎フレーム -1 (重力)
  s16 velZ;           // 0x0C, 毎フレーム particle.pos.z に加算
  u8 unk_0e[2];       // 0x0E
  Particle particle;  // 0x10, 根拠: FUN_0822da70 / Particle_SetOffset / FUN_0822da50 / Particle_Remove
} ScatterParticle;
static_assert(sizeof(ScatterParticle) == 56);  // 根拠: Init / Destroy / FUN_0801442c のストライド 0x38

// FUN_08014730 で一度に出す粒子のまとまり
typedef struct {
  u8 active;                     // 0x00, Update が 0 以外のときだけ処理, FUN_08014730 が空きを探して 1, 全粒子が消えると 0
  u8 count;                      // 0x01, 使う particles の数, FUN_08014730 で最大 8
  u8 kind;                       // 0x02, 9 未満なら FUN_08014148 (床で跳ねる), 0x15 未満なら group1, u32_ARRAY_085aa850 の添字
  u8 priority;                   // 0x03, 各 particle.priority にコピー, FUN_08014730 の kind >> 8 から 1 引いた値 (0 以下なら 2)
  ScatterParticle particles[8];  // 0x04
} Entity080146e0Data;
static_assert(sizeof(Entity080146e0Data) == 452);

typedef struct {
  Entity e;                    // 0x0, ENTITY_UNK_10
  u32 frameCount;              // 0x18, Update で毎フレーム +1, bit0 で床の影と本体を交互に描く (FUN_08014148 / FUN_0801442c)
  ParticleGroup* group1;       // 0x1C, GetParticleGroup(PTCL_GROUP_1)
  ParticleGroup* group2;       // 0x20, GetParticleGroup(PTCL_GROUP_2)
  Entity080146e0Data data[6];  // 0x24, 0x080145cc
} Entity080146e0;
static_assert(sizeof(Entity080146e0) == 2748);

IWRAM_DATA Entity080146e0* gEntity080146e0 = NULL;  // 0x03000058

const u32 u32_ARRAY_085aa850[40] = {
    0x0, 0x0, 0x8, 0x9, 0xF, 0xC, 0xD, 0xE, 0x10, 0x1C, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x12, 0x11, 0x1B, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x5, 0x12, 0xA,
};

NAKED void FUN_08014088(void) { INCFUNC("asm/func/FUN_08014088.inc"); }

NAKED void FUN_08014094(Entity080146e0* p, Entity080146e0Data* data) { INCFUNC("asm/func/FUN_08014094.inc"); }

NAKED void FUN_08014148(Entity080146e0* p, Entity080146e0Data* data) { INCFUNC("asm/func/FUN_08014148.inc"); }

NAKED void FUN_0801442c(Entity080146e0* p, Entity080146e0Data* data) { INCFUNC("asm/func/FUN_0801442c.inc"); }

NAKED s32 Entity080146e0_Update(Entity080146e0* p) { INCFUNC("asm/func/Entity080146e0_Update.inc"); }

NAKED s32 Entity080146e0_Destroy(Entity080146e0* p) { INCFUNC("asm/func/Entity080146e0_Destroy.inc"); }

NAKED s32 Entity080146e0_Init(Entity080146e0* p, u32 _) { INCFUNC("asm/func/Entity080146e0_Init.inc"); }

NAKED Entity080146e0* Entity080146e0_Create(u32 unused1, u32 unused2) { INCFUNC("asm/func/Entity080146e0_Create.inc"); }

NAKED s32 FUN_08014730(s32 count, s32 kind, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask) { INCFUNC("asm/func/FUN_08014730.inc"); }

NAKED s32 FUN_080149dc(s32 param_1, s32 param_2, unknown* param_3, unknown* param_4, unknown* param_5, unknown* param_6, unknown* param_7, unknown* param_8, unknown* param_9, unknown* param_10, unknown* param_11) { INCFUNC("asm/func/FUN_080149dc.inc"); }

NAKED void FUN_08014d24(void) { INCFUNC("asm/func/FUN_08014d24.inc"); }
