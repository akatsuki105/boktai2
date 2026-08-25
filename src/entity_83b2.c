#include "global.h"
#include "player.h"

// おそらくこれが、ヒントパネルやATMに対応
typedef struct {
  u8 unk_0[2];
  u8 unk_2;  // 0x02
  u8 unk_3;
  u8 unk_4;     // 0x04
  u8 state;     // 0x05, 0: 範囲外, 1: インタラクト可能(プレイヤーが範囲内でそのオブジェクトを向いている), 2: インタラクト中(ヒントパネルなら読んでいる時, ATMなら操作中)
  bool8 unk_6;  // 0x06
  u8 unk_7;     // 0x07
  s32 id_8;     // 0x08, GameInfo.unk_248 と比較して等しくない場合は、オブジェクトが消えた(消えた後でも等しくなると復活した)
  u16 unk_c;    // 0x0C
  u16 unk_e;    // 0x0E
  u8 unk_10[108 - 0x10];
} Entity83B2Data;
static_assert(sizeof(Entity83B2Data) == 108);

// 銀行に入る時に Entity83B2_Create が Entity83B2_Init を呼ぶが、その際に返り値を -1 にして Entity83B2_Init が失敗したことにすると、
// ヒントパネルが消滅し、 銀行のATMはインタラクトできなくなった(ATMのグラ自体はある), ただし、太陽スタンドには何も影響がなかった
// なので、インタラクト可能なオブジェクトの管理用の構造体だと思われる
typedef struct Entity83B2 {
  Entity e;              // 0x00, ENTITY_UNK_8
  u8 length;             // 0x18, list の要素数, 銀行だと3だった
  s8 unk_19;             // 0x19
  s8 unk_1a;             // 0x1A
  u32 unk_1c;            // 0x1C
  Entity83B2Data* list;  // 0x20, Malloc で確保した Entity83B2Data[length], これがインタラクト可能なオブジェクトのリストになっていると思われる
  Player* player;        // 0x24, gPlayerPtr[0]
  Vec3 pos;              // 0x28, Player.pos
} Entity83B2;
static_assert(sizeof(Entity83B2) == 48);

s32 FUN_080093f8(Entity83B2* p, Entity83B2Data* q, s32 idx);
s32 FUN_080094ac(Entity83B2* p, Entity83B2Data* q, s32 idx);
s32 FUN_0800959c(Entity83B2* p, Entity83B2Data* q, s32 idx);

INCASM("asm/entity_83b2.inc");

NAKED Entity83B2* Entity83B2_Create(void* _) { INCFUNC("asm/func/Entity83B2_Create.inc"); }

// マップ切り替わり時に (多分 Entity83B2 の数だけ)　呼ばれた (銀行に入ると3回呼ばれた, 多分 ヒントパネル1個 + ATM2個 で3回と思われる)
NAKED s32 VM_Sub883A(void) { INCFUNC("asm/func/VM_Sub883A.inc"); }

// ヒントパネルを閉じると呼ばれる, ATMを終了しても呼ばれない
NAKED s32 VM_Sub2740(void) { INCFUNC("asm/func/VM_Sub2740.inc"); }

s32 (*const PTR_ARRAY_085aa6ac[3])(Entity83B2*, Entity83B2Data*, s32) = {
    FUN_080093f8,
    FUN_080094ac,
    FUN_0800959c,
};  // 0x085aa6ac
