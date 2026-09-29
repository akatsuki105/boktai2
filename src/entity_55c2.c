#include "entity.h"
#include "global.h"
#include "hitbox.h"

// ヒットボックスを1つ持ち、当たったら VM キーワードで指定された条件を見て反応するエンティティ
typedef struct {
  Entity e;           // 0x00, ENTITY_UNK_8
  HitboxData hitbox;  // 0x18, _Destroy が Hitbox_Unregister に渡す
  u16 id;             // 0x68, _Create / _Init の引数, Hitbox_Init の第2引数にもなる
  u16 unk_6a;         // 0x6A, _Init が '.l=100' を入れる (unk_6c と同じ値)
  u16 unk_6c;         // 0x6C, _Init が '.l=100' を入れる
  u16 flags;          // 0x6E, _Init が '.f' を入れ、'.w' が無ければ bit3、'.a' が無ければ bit4 を足す
  u32 unk_70;         // 0x70, _Init が '.w' を入れる, 無ければ 0 で flags bit3
  u32 unk_74;         // 0x74, _Init が '.a' を入れる, 無ければ 0 で flags bit4
  u32 unk_78;         // 0x78, _Init が '.S=0x10' を入れ、Hitbox_Init の第5引数に渡す
  u16 unk_7c;         // 0x7C, _Init が 0 を入れる
  u16 unk_7e;         // 0x7E, _Init が '.i' を入れる
  u16 unk_80;         // 0x80, _Init が '.D' を入れる
  u16 unk_82;         // 0x82, _Init が '.d' を入れる
  Vec3 hitPos;        // 0x84, _OnHit が当たったヒットボックスの pos を写す
} Entity55C2;
static_assert(sizeof(Entity55C2) == 140);

INCASM("asm/entity_55c2.inc");
