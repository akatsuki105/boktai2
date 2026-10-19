#include "entity.h"
#include "global.h"
#include "particle.h"

// 粒子1個, vel で流れながら lifetime を減らし, 尽きると state 2 (解放) に移る
typedef struct {
  Particle ptcl;    // 0x00, pos は _SpawnElem の第1引数の写し
  Vec3 vel;         // 0x28, 毎フレーム x と z だけ ptcl.pos に足される
  u16 unk_30;       // 0x30
  u8 state;         // 0x32, PTR_ARRAY_085ae5f0 の添字 (0:待機 1:移動 2:解放)
  s8 slotIdx;       // 0x33, usedMask 上の自分のビット番号, 空きは -1
  bool8 needsShow;  // 0x34, 立っている間に _UpdateMove が ptcl の SPRFLAG_HIDDEN を落とす
  u8 unk_35;        // 0x35, 初期値 0x1E
  u8 animTimer;     // 0x36, 0 になると animDelay を再読込して次のコマへ
  u8 animFlip;      // 0x37, 0/1 を交互に取り baseFrame に足される
  u16 lifetime;     // 0x38, 0 になると state 2 へ移る
  u8 unk_3a[2];     // 0x3A
  u8 baseFrame;     // 0x3C, Particle_SetFrame に渡すコマ番号の基準, kind * 2
  u8 unk_3d;        // 0x3D
  u16 animDelay;    // 0x3E, animTimer の再読込値 (初期値 3)
} Entity081fa164Elem;
static_assert(sizeof(Entity081fa164Elem) == 64);

// 粒子を26個まで同時に流すシングルトン
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_10
  ParticleGroup* group;          // 0x018, PTCL_GROUP_2
  Entity081fa164Elem elems[26];  // 0x01C
  u32 usedMask;                  // 0x69C, elems のどのスロットが使用中かのビットマスク
} Entity081fa164;
static_assert(sizeof(Entity081fa164) == 1696);

static Entity081fa164* gEntity081fa164;  // 0x03000214

void Entity081fa164_UpdateIdle(Entity081fa164*, Entity081fa164Elem*);
void Entity081fa164_UpdateMove(Entity081fa164*, Entity081fa164Elem*);
void Entity081fa164_UpdateRelease(Entity081fa164*, Entity081fa164Elem*);

void (*const PTR_ARRAY_085ae5f0[3])(Entity081fa164*, Entity081fa164Elem*) = {
    Entity081fa164_UpdateIdle,
    Entity081fa164_UpdateMove,
    Entity081fa164_UpdateRelease,
};  // 0x085AE5F0

INCASM("asm/entity_081fa164.inc");
