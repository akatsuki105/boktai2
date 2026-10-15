#include "entity.h"
#include "global.h"
#include "sprite.h"

// スクリプトから足せる飾りのスプライト1枚, 位置の補間とマーカー設定への追従を持つ
typedef struct {
  u8 unk_0[24];        // 0x00, どの関数も触っていない
  MainSpriteGfx gfx;   // 0x18, '.i' で指定したスプライトファイル
  MainSprite sprite;   // 0x38
  u16 id;              // 0x98, '.n', スクリプトから枠を引くときの番号
  s16 moving;          // 0x9A, 0 以外なら pos を fromPos から toPos へ補間する
  s16 markerGated;     // 0x9C, 0 以外なら gStat->markerEnabled に従って表示を切り替える
  s16 hiddenByScript;  // 0x9E, スクリプトから隠されているか
  u16 elapsed;         // 0xA0, 補間の経過フレーム
  u16 duration;        // 0xA2, 補間の全体フレーム数
  Vec3 pos;            // 0xA4, 現在位置
  Vec3 fromPos;        // 0xAC, 補間の始点
  Vec3 toPos;          // 0xB4, 補間の終点
} Entity8AF6Entry;
static_assert(sizeof(Entity8AF6Entry) == 188);

typedef struct {
  Entity e;                    // 0x00, ENTITY_UNK_9
  u8 count;                    // 0x18, '.m=1', 確保した枠数
  u8 used;                     // 0x19, 使用中の枠数, Update と Destroy はここまでしか回さない
  u8 unk_1a[2];                // 0x1A, 詰め物
  Entity8AF6Entry entries[1];  // 0x1C, 実際は count 個 (可変長)
} Entity8AF6;                  // Entity8AF6 はサイズが可変
static_assert(sizeof(Entity8AF6) == 216);

extern Entity8AF6* gEntity8AF6;  // 0x03002C4C

NAKED Entity8AF6Entry* Entity8AF6_FindEntry(void) { INCFUNC("asm/func/Entity8AF6_FindEntry.inc"); }

NAKED void Entity8AF6_SetPoseScripted(void) { INCFUNC("asm/func/Entity8AF6_SetPoseScripted.inc"); }

NAKED void FUN_080a59e0(void) { INCFUNC("asm/func/FUN_080a59e0.inc"); }

NAKED void Entity8AF6_HideScripted(void) { INCFUNC("asm/func/Entity8AF6_HideScripted.inc"); }

NAKED void Entity8AF6_ShowScripted(void) { INCFUNC("asm/func/Entity8AF6_ShowScripted.inc"); }

NAKED void FUN_080a5a6c(void) { INCFUNC("asm/func/FUN_080a5a6c.inc"); }

NAKED void Entity8AF6_MoveToScripted(void) { INCFUNC("asm/func/Entity8AF6_MoveToScripted.inc"); }

NAKED void Entity8AF6Entry_Update(Entity8AF6Entry* p) { INCFUNC("asm/func/Entity8AF6Entry_Update.inc"); }

NAKED void Entity8AF6_AddEntryScripted(void) { INCFUNC("asm/func/Entity8AF6_AddEntryScripted.inc"); }

NAKED s32 Entity8AF6_Update(Entity8AF6* p) { INCFUNC("asm/func/Entity8AF6_Update.inc"); }

NAKED s32 Entity8AF6_Destroy(Entity8AF6* p) { INCFUNC("asm/func/Entity8AF6_Destroy.inc"); }

NAKED s32 Entity8AF6_Init(Entity8AF6* p, u32 param_2, u32 param_3, u8 count) { INCFUNC("asm/func/Entity8AF6_Init.inc"); }

NAKED Entity8AF6* Entity8AF6_Create(u32 param_1, u32 param_2) { INCFUNC("asm/func/Entity8AF6_Create.inc"); }
