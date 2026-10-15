#include "entity.h"
#include "global.h"
#include "particle.h"

// 地点から上に湧き続ける粒, 8枠を使い回して消えたものから順に湧かし直す
typedef struct {
  bool8 active;   // 0x00, 1 の間だけ上昇する
  u8 randSeed;    // 0x01, 湧くときに乱数表から入れる1バイト
  s16 height;     // 0x02, 毎フレーム riseSpeed だけ増え、maxHeight に届くと消える
  s16 unk_4;      // 0x04, 触られていない
  s16 timer;      // 0x06, 消えている間は湧くまでの残りフレーム, 上昇中はコマ送りの数え上げ
  Particle ptcl;  // 0x08
} Entity99CAElem;
static_assert(sizeof(Entity99CAElem) == 48);

typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_11
  s32 timer;                // 0x018, 毎フレーム +1, lifetime と比べて湧かすのを止める
  s32 lifetime;             // 0x01C, '.t=0x100', 負なら無期限
  u16 riseSpeed;            // 0x020, 0x14, 各枠の height に毎フレーム足す
  u16 maxHeight;            // 0x022, 400, height がここに届いた枠を消す
  u16 count;                // 0x024, '.n=8', 使う枠数
  u16 frame;                // 0x026, '.T' で選ぶ Particle のコマ番号 (0,2,4,...,14)
  ParticleGroup* group;     // 0x028, PTCL_GROUP_2
  Vec3 pos;                 // 0x02C, '.p', y はタイルの attr から計算し直す
  Entity99CAElem elems[8];  // 0x034
} Entity99CA;
static_assert(sizeof(Entity99CA) == 436);

NAKED bool32 Entity99CA_HasActiveElem(Entity99CA* p) { INCFUNC("asm/func/Entity99CA_HasActiveElem.inc"); }

NAKED void Entity99CAElem_TryRespawn(Entity99CA* p, Entity99CAElem* elem) { INCFUNC("asm/func/Entity99CAElem_TryRespawn.inc"); }

NAKED void Entity99CAElem_Update(Entity99CA* p, Entity99CAElem* elem) { INCFUNC("asm/func/Entity99CAElem_Update.inc"); }

NAKED s32 Entity99CA_Update(Entity99CA* p) { INCFUNC("asm/func/Entity99CA_Update.inc"); }

NAKED s32 Entity99CA_Destroy(Entity99CA* p) { INCFUNC("asm/func/Entity99CA_Destroy.inc"); }

NAKED s32 Entity99CA_Init(Entity99CA* p, Vec3* pos, u16 param_3, s32 lifetime, s32 count, s32 kind) { INCFUNC("asm/func/Entity99CA_Init.inc"); }

NAKED Entity99CA* Entity99CA_CreateAt(Vec3* pos, u16 param_2, s32 lifetime, s32 count, s32 kind) { INCFUNC("asm/func/Entity99CA_CreateAt.inc"); }

NAKED Entity99CA* Entity99CA_Create(void) { INCFUNC("asm/func/Entity99CA_Create.inc"); }
