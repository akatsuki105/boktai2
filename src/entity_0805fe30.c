#include "entity.h"
#include "global.h"
#include "particle.h"

// 数字を1桁ずつ Particle で表示する枠, 同時に4つまで出せる
typedef struct Entity0805fe30Slot {
  s32 key;            // 0x00, Entity0805fe30_FindSlotByKey の検索キー
  u8 priority;        // 0x04, 空きがないとき これ以下の枠は奪われる
  u8 stateTimer;      // 0x05, state が変わると 0 に戻る
  u8 state;           // 0x06, PTR_ARRAY_085aba9c の添字
  u8 digitCount;      // 0x07, 使っている ptcls の数 (0..4), s32_ARRAY_085aba88 の添字でもある
  u16 unk_08;         // 0x08
  s16 unk_0a;         // 0x0A, unk_08 + 6
  Vec3 pos;           // 0x0C, ワールド座標, アイソメトリック投影してスクリーン座標にする
  Particle ptcls[4];  // 0x14, 1桁につき1個
} Entity0805fe30Slot;
static_assert(sizeof(Entity0805fe30Slot) == 180);

// ダメージ値などの数字を画面に浮かせて出す
typedef struct Entity0805fe30 {
  Entity e;                     // 0x000, ENTITY_UNK_9
  u32 activeMask;               // 0x018, slots 1つにつき1bit
  ParticleGroup* group;         // 0x01C, PTCL_GROUP_1
  Entity0805fe30Slot slots[4];  // 0x020
} Entity0805fe30;
static_assert(sizeof(Entity0805fe30) == 752);

extern Entity0805fe30* gEntity0805fe30;  // 0x03000130

const s32 s32_ARRAY_085aba88[5] = {0, 0, -3, -6, -9};  // 0x085ABA88

void Entity0805fe30_UpdateSlotRise(unknown*, unknown*, s32);
void Entity0805fe30_UpdateSlotHold(unknown*, unknown*, s32);

void (*const PTR_ARRAY_085aba9c[2])(unknown*, unknown*, s32) = {
    Entity0805fe30_UpdateSlotRise,
    Entity0805fe30_UpdateSlotHold,
};  // 0x085ABA9C

INCASM("asm/entity_0805fe30.inc");
