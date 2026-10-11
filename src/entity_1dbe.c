#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "sprite_aux.h"

struct Entity1DBEElem;

typedef void(Entity1DBEElemFunc)(struct Entity1DBEElem* elem);

// 太陽エネルギーで state が入れ替わる設置物, 1体の Entity1DBE が最大8個を抱える
// 多分、センサー床 (太陽ゲージが1以上の時に赤く光って、踏むとブザーが鳴って敵に感知される)
typedef struct Entity1DBEElem {
  AuxSprite sprite;                    // 0x000, metaspriteIdx が見た目の段階 (state 0 は 0〜2, state 1 は 3〜5, state 2 は 6〜8)
  AuxSpriteGfx gfx;                    // 0x02C, SPRITE_TRAP_FLOOR
  Mover mover;                         // 0x048, moverLinked が立っているときだけリストに繋がれる
  HitboxData hitbox;                   // 0x08C, 半径 {0x80, 0x32, 0x80}, ignoreMask 0x10
  u8 state;                            // 0x0DC, '.s', 0/1/2 で updateCallback を選ぶ
  u8 lockFlags;                        // 0x0DD, '.f', bit0 が立つと state 2 へ, bit1 が立つと state 1 へ遷移しない
  u8 unk_de;                           // 0x0DE, 読み手も書き手も見つかっていない
  bool8 touched;                       // 0x0DF, 近くに来るか属性なしの攻撃を受けると立つ, state 0 が消費して点滅を始める
  u16 id;                              // 0x0E0, '.n', mover.id と hitbox の id を兼ねる
  u16 unk_e2;                          // 0x0E2, 状態が変わるたび 0x10 が入るが読み手が見つかっていない
  bool8 moverLinked;                   // 0x0E4, '.h', 立っていれば mover を使う
  bool8 flickering;                    // 0x0E5, touched のあと animTimer が 90 になるまで点滅する
  bool8 areaBound;                     // 0x0E6, '.m', 立っていれば areaID が現在のエリアと一致する間だけ更新する
  bool8 unk_e7;                        // 0x0E7, 立っていると状態の振り分けをやり直して 0 に戻る, 書き手が見つかっていない
  u16 areaID;                          // 0x0E8, GetMapAreaAt(sprite.pos) の結果, gStat->unk_248 と比べる
  u8 unk_ea[2];                        // 0x0EA, 読み手も書き手も見つかっていない, padding?
  s16 counter;                         // 0x0EC, 日照で増え暗所で減る, ±300 を越えると state が切り替わる, state 1/2 では復帰までのフレーム数
  u16 animTimer;                       // 0x0EE, 遷移アニメと点滅のコマ送り
  Entity1DBEElemFunc* updateCallback;  // 0x0F0
} Entity1DBEElem;
static_assert(sizeof(Entity1DBEElem) == 244);

typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_9
  u16 count;                // 0x018, 使用中の elems の数, VM_Sub1DBE は 8 未満のときだけ足す
  u8 unk_1a[2];             // 0x01A, padding?
  Entity1DBEElem elems[8];  // 0x01C
} Entity1DBE;
static_assert(sizeof(Entity1DBE) == 1980);

IWRAM_DATA Entity1DBE* gEntity1DBE = NULL;  // 0x03000144

NAKED void FUN_0809f64c(void) { INCFUNC("asm/func/FUN_0809f64c.inc"); }

NAKED bool32 Entity1DBE_TouchElemNear(Vec3* pos) { INCFUNC("asm/func/Entity1DBE_TouchElemNear.inc"); }

NAKED s32 VM_SubB6CE(void) { INCFUNC("asm/func/VM_SubB6CE.inc"); }

NAKED void Entity1DBEElem_SetState(Entity1DBEElem* elem, u8 state, Entity1DBEElemFunc* fn) { INCFUNC("asm/func/Entity1DBEElem_SetState.inc"); }

NAKED void Entity1DBEElem_OnHit(HitboxData* a, HitboxData* b, Entity1DBEElem* owner) { INCFUNC("asm/func/Entity1DBEElem_OnHit.inc"); }

NAKED void FUN_0809f7fc(Entity1DBEElem* elem) { INCFUNC("asm/func/FUN_0809f7fc.inc"); }

NAKED void FUN_0809f840(Entity1DBEElem* elem) { INCFUNC("asm/func/FUN_0809f840.inc"); }

NAKED void FUN_0809f890(Entity1DBEElem* elem) { INCFUNC("asm/func/FUN_0809f890.inc"); }

NAKED void FUN_0809f8e4(Entity1DBEElem* elem) { INCFUNC("asm/func/FUN_0809f8e4.inc"); }

NAKED void FUN_0809f938(Entity1DBEElem* elem) { INCFUNC("asm/func/FUN_0809f938.inc"); }

NAKED void FUN_0809fa80(Entity1DBEElem* elem) { INCFUNC("asm/func/FUN_0809fa80.inc"); }

NAKED void FUN_0809fabc(Entity1DBEElem* elem) { INCFUNC("asm/func/FUN_0809fabc.inc"); }

NAKED void Entity1DBEElem_Update(Entity1DBEElem* elem) { INCFUNC("asm/func/Entity1DBEElem_Update.inc"); }

NAKED void Entity1DBEElem_InitParams(Entity1DBEElem* elem, u16 id, Vec3* pos, u8 state, u8 lockFlags, bool8 areaBound) { INCFUNC("asm/func/Entity1DBEElem_InitParams.inc"); }

NAKED void Entity1DBEElem_InitSprite(Entity1DBEElem* elem, Vec3* pos, bool8 moverLinked) { INCFUNC("asm/func/Entity1DBEElem_InitSprite.inc"); }

NAKED void Entity1DBEElem_InitHitbox(Entity1DBEElem* elem) { INCFUNC("asm/func/Entity1DBEElem_InitHitbox.inc"); }

NAKED void Entity1DBEElem_InitState(Entity1DBEElem* elem) { INCFUNC("asm/func/Entity1DBEElem_InitState.inc"); }

NAKED void Entity1DBE_AddElem(Entity1DBE* p, u16 id, Vec3* pos, u8 state, bool8 moverLinked, u8 lockFlags, bool8 areaBound) { INCFUNC("asm/func/Entity1DBE_AddElem.inc"); }

NAKED s32 Entity1DBE_Update(Entity1DBE* p) { INCFUNC("asm/func/Entity1DBE_Update.inc"); }

NAKED s32 Entity1DBE_Destroy(Entity1DBE* p) { INCFUNC("asm/func/Entity1DBE_Destroy.inc"); }

NAKED s32 Entity1DBE_Init(Entity1DBE* p) { INCFUNC("asm/func/Entity1DBE_Init.inc"); }

NAKED Entity1DBE* Entity1DBE_Create(void) { INCFUNC("asm/func/Entity1DBE_Create.inc"); }

NAKED void VM_Sub1DBE(void) { INCFUNC("asm/func/VM_Sub1DBE.inc"); }
