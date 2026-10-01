#include "entity.h"
#include "global.h"
#include "particle.h"

struct Player;

// 粒子3枚を1組にした要素, Entity4F5C_ElemFall がプレイヤーの高さまで落とし、Entity4F5C_ElemScatter が円状に散らす
typedef struct {
  u8 state;           // 0x00, PTR_ARRAY_085aa974 の添字, 0 は終了済み
  u8 ptclIdx;         // 0x01, ptcls の添字, 1 と 2 を巡回する
  u8 unk_02;          // 0x02, 0x18 から毎フレーム減るカウンタ, 0x17 と 0x14 で分岐する
  u8 speed;           // 0x03, gSineTable との積が1フレームの移動量になる
  u8 angle;           // 0x04, gSineTable の添字 (散る向き)
  u8 unk_05;          // 0x05, 着地と判定する高さのずれ, Entity4F5C_Init が (rand & 0x1F) - 0x24 を入れる
  u16 timer;          // 0x06, 毎フレーム +1
  Vec3 pos;           // 0x08, ptcls[].pos の基準位置
  u8 animIdx[3];      // 0x10, 粒子ごとのアニメ番号 (0 か 1)
  u8 animTimer[3];    // 0x13, u16_ARRAY_085aa970[animIdx] に達したら animIdx を進める
  u8 unk_16[2];       // 0x16, まだ未解析
  Particle ptcls[3];  // 0x18
} Entity4F5CElem;
static_assert(sizeof(Entity4F5CElem) == 144);

typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_10
  u16 unk_18;               // 0x018, Entity4F5C_Init が 0 を書く, 読み手は未発見
  u16 scriptID;             // 0x01A, '.e' の値, elems が全部終わったら VM_ExecByID に渡す
  Vec3 playerPos;           // 0x01C, player->mover.pos の写し
  ParticleGroup* group1;    // 0x024, PTCL_GROUP_1
  ParticleGroup* group2;    // 0x028, PTCL_GROUP_2
  Entity4F5CElem elems[3];  // 0x02C
  struct Player* player;    // 0x1DC, gPlayerPtr[0]
} Entity4F5C;
static_assert(sizeof(Entity4F5C) == 480);

INCASM("asm/entity_4f5c.inc");

const u16 u16_ARRAY_085aa970[2] = {3, 3};  // 0x085AA970

void nop_0801a170(Entity4F5C*, Entity4F5CElem*);
void Entity4F5C_ElemFall(Entity4F5C*, Entity4F5CElem*);
void Entity4F5C_ElemScatter(Entity4F5C*, Entity4F5CElem*);

void (*const PTR_ARRAY_085aa974[3])(Entity4F5C*, Entity4F5CElem*) = {
    nop_0801a170,
    Entity4F5C_ElemFall,
    Entity4F5C_ElemScatter,
};  // 0x085AA974

const u16 u16_ARRAY_085aa980[3] = {0x0, 0x80, 0x258};  // 0x085AA980

static const u16 padding_085aa986 = 0;  // 後で消す
