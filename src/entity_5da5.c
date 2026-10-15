#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite.h"

// 4本の腕を持つシャンデリア, 炎で点き氷で消え、全部点くとスクリプトが走る
typedef struct {
  u8 index;            // 0x00, 0〜3, 親のビットマスクの位置とアニメ番号 index+2 を兼ねる
  u8 state;            // 0x01, 0 消灯, 1 点灯
  bool8 stateEntered;  // 0x02, state を変えた直後だけ立つ
  u8 unk_3;            // 0x03, 0 を書くだけ
  s32 timer;           // 0x04, state を変えるたびに 0 に戻る
  HitboxData hitbox;   // 0x08, flags 0x4001, ignoreMask 0x10, 半径は index 1,2 が {0x18, 0x100, 0x60} で他が {0x60, 0x100, 0x18}
  MainSprite sprite;   // 0x58
} Entity5DA5Elem;
static_assert(sizeof(Entity5DA5Elem) == 184);

typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_10
  u16 unk_18;               // 0x018, Entity5DA5_Create の引数が入る, 読み手が見つかっていない
  u16 scriptID;             // 0x01A, '.p=0', 全点灯か全消灯になったときに実行する
  u16 litMask;              // 0x01C, 点灯中の要素のビット, 下位4bit
  u8 unk_1e;                // 0x01E, 0 を書くだけ
  u8 unk_1f;                // 0x01F, 0 を書くだけ
  u32 unk_20;               // 0x020, 0 を書くだけ
  u32 scriptArgs[4];        // 0x024, '.a'
  u16 litBits;              // 0x034, 点いた要素のビット
  u16 unlitBits;            // 0x036, 消えた要素のビット
  u16 changedBits;          // 0x038, 点灯と消灯のどちらでも立つ変化したビット
  u8 unk_3a[2];             // 0x03A, 触られていない
  Vec3 pos;                 // 0x03C, '.P', 判定の基準位置
  Vec3 screenPos;           // 0x044, pos を等角投影してカメラ分を引いた画面座標
  MainSpriteGfx gfx;        // 0x04C, SPRITE_CHANDELIER
  MainSprite sprite;        // 0x06C, 土台, アニメ 6
  Entity5DA5Elem elems[4];  // 0x0CC
} Entity5DA5;
static_assert(sizeof(Entity5DA5) == 940);

IWRAM_DATA Entity5DA5* gEntity5DA5 = NULL;  // 0x03000038

const u16 u16_ARRAY_085aa690[8] = {0x0, 0x80, 0xFF80, 0x0, 0xFF80, 0x0, 0x0, 0x80};  // 0x085aa690

void Entity5DA5Elem_UpdateUnlit(Entity5DA5*, Entity5DA5Elem*);
void Entity5DA5Elem_UpdateLit(Entity5DA5*, Entity5DA5Elem*);

void (*const PTR_ARRAY_085aa6a0[2])(Entity5DA5*, Entity5DA5Elem*) = {
    Entity5DA5Elem_UpdateUnlit,
    Entity5DA5Elem_UpdateLit,
};  // 0x085aa6a0

const u8 u8_ARRAY_085aa6a8[4] = {11, 12, 11, 10};  // 0x085aa6a8

NAKED void Entity5DA5Elem_SetState(Entity5DA5Elem* p, u8 state) { INCFUNC("asm/func/Entity5DA5Elem_SetState.inc"); }

NAKED bool32 Entity5DA5Elem_ConsumeStateEntered(Entity5DA5Elem* p) { INCFUNC("asm/func/Entity5DA5Elem_ConsumeStateEntered.inc"); }

NAKED void Entity5DA5Elem_OnHit(HitboxData* a, HitboxData* b, Entity5DA5Elem* owner) { INCFUNC("asm/func/Entity5DA5Elem_OnHit.inc"); }

NAKED s32 Entity5DA5Elem_Init(Entity5DA5* p, Entity5DA5Elem* elem, s32 index) { INCFUNC("asm/func/Entity5DA5Elem_Init.inc"); }

NAKED void Entity5DA5_RunScript(Entity5DA5* p, s32 param_2, u32 index) { INCFUNC("asm/func/Entity5DA5_RunScript.inc"); }

NAKED void Entity5DA5Elem_UpdateUnlit(Entity5DA5* p, Entity5DA5Elem* elem) { INCFUNC("asm/func/Entity5DA5Elem_UpdateUnlit.inc"); }

NAKED void Entity5DA5Elem_UpdateLit(Entity5DA5* p, Entity5DA5Elem* elem) { INCFUNC("asm/func/Entity5DA5Elem_UpdateLit.inc"); }

NAKED s32 Entity5DA5_Update(Entity5DA5* p) { INCFUNC("asm/func/Entity5DA5_Update.inc"); }

NAKED s32 Entity5DA5_Destroy(Entity5DA5* p) { INCFUNC("asm/func/Entity5DA5_Destroy.inc"); }

NAKED s32 Entity5DA5_Init(Entity5DA5* p, u16 param_2) { INCFUNC("asm/func/Entity5DA5_Init.inc"); }

NAKED Entity5DA5* Entity5DA5_Create(u16 param_1) { INCFUNC("asm/func/Entity5DA5_Create.inc"); }

NAKED s32 Entity5DA5_SetState(s32 index, u8 state, s32 param_3) { INCFUNC("asm/func/Entity5DA5_SetState.inc"); }

NAKED s32 Entity5DA5_SetStateScripted(void) { INCFUNC("asm/func/Entity5DA5_SetStateScripted.inc"); }

NAKED s32 Entity5DA5_AreAllLit(void) { INCFUNC("asm/func/Entity5DA5_AreAllLit.inc"); }

NAKED s32 Entity5DA5_AreAllUnlit(void) { INCFUNC("asm/func/Entity5DA5_AreAllUnlit.inc"); }
