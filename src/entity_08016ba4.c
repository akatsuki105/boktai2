#include "animation.h"
#include "entity.h"
#include "global.h"
#include "particle.h"

// 1発ぶんの破片, 速度を持って飛びながらアニメを進める
typedef struct {
  bool8 active;       // 0x00, FUN_080166ac が 1 を入れる
  u8 life;            // 0x01, FUN_08016878 が毎フレーム 1 減らし, 0 で particle を隠す
  s16 speed;          // 0x02, velX / velZ に掛けて >>12 してから pos に足す
  s16 velX;           // 0x04, gSineTable[angle + 0x40]
  s16 velY;           // 0x06, FUN_08016878 が毎フレーム 2 減らす
  s16 velZ;           // 0x08, gSineTable[angle]
  u8 unk_a[2];        // 0x0A, まだ未解析
  Particle particle;  // 0x0C, FUN_0822da70 で確保し Particle_Remove で返す
  AuxAnimState anim;  // 0x34, AuxAnim_SetAnim が初期化し AuxAnim_SetAnimSpeed が進める
} Entity08016ba4Piece;
static_assert(sizeof(Entity08016ba4Piece) == 68);

// 1回の発生ぶん, 同じ位置から最大8個の破片をまとめて飛ばす
typedef struct {
  bool8 active;                   // 0x000, FUN_080166ac が空き枠に 1 を入れ, pieces が尽きると FUN_08016878 が 0 に戻す
  u8 count;                       // 0x001, 使う pieces の数, 8 で頭打ち
  u8 unk_2[2];                    // 0x002, まだ未解析
  Entity08016ba4Piece pieces[8];  // 0x004
} Entity08016ba4Burst;
static_assert(sizeof(Entity08016ba4Burst) == 548);

typedef struct {
  Entity e;                       // 0x0000, ENTITY_UNK_10
  s32 frame;                      // 0x0018, _Update が毎フレーム 1 足す
  ParticleGroup* group;           // 0x001C, GetParticleGroup(GROUP_0)
  AuxAnimFile* anim;              // 0x0020, GetFile(DIR_ANIMATION, 0xD1B8)
  Entity08016ba4Burst bursts[6];  // 0x0024, FUN_080166ac が空いている枠を先頭から探す
} Entity08016ba4;
static_assert(sizeof(Entity08016ba4) == 3324);

IWRAM_DATA Entity08016ba4* gEntity08016ba4 = NULL;  // 0x03000064

void FUN_080166a0(void) { gEntity08016ba4 = NULL; }

INCASM("asm/entity_08016ba4.inc");
