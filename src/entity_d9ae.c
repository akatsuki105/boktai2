#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "sprite_aux.h"
#include "video.h"

// EntityD9AE が count 個まわす1要素, プレイヤーが押せるブロック
typedef struct EntityD9AEElem {
  u8 kind;                                         // 0x000, '.t', 0-6, 1 は押した後も止まるまで滑る
  u8 flags;                                        // 0x001, '.f', bit1: FUN_08002a48 に失敗, bit2: 出現演出あり, bit3: 落下後に壊れる, bit4: ゾーンに所属, bit5: 待機中以外はゾーンイベントを見ない
  u16 timer;                                       // 0x002
  u16 state;                                       // 0x004, 0: 待機, 1: 移動, 2: 移動して落下, 3: 破壊
  u8 unk_6[2];                                     // 0x006
  s32 zone;                                        // 0x008, 0 ならゾーンに属さない
  s16 moveX;                                       // 0x00C
  s16 moveZ;                                       // 0x00E
  u8 dir;                                          // 0x010
  bool8 stateEntered;                              // 0x011
  u16 targetY;                                     // 0x012, 落下先の高さ
  u16 moveFrames;                                  // 0x014, 16 か 64
  s16 hp;                                          // 0x016, '.l=0x80'
  u8 hitCooldown;                                  // 0x018
  u8 phase;                                        // 0x019, 0: 動作中, 2: そのまま解放, 3: 破壊エフェクトを出して解放
  u16 plttID;                                      // 0x01A, '.d=-1'
  u16 flashPlttID;                                 // 0x01C
  bool8 active;                                    // 0x01E, 0 なら空き枠
  u8 flashTimer;                                   // 0x01F
  u8 breakStep;                                    // 0x020
  u8 seCooldown;                                   // 0x021
  u8 unk_22;                                       // 0x022
  u8 unk_23;                                       // 0x023
  bool8 pushLimited;                               // 0x024, kind == 5 なら押せる回数に限りがある
  u8 pushCount;                                    // 0x025, 押せる残り回数
  u8 unk_26[2];                                    // 0x026
  u32 breakScript;                                 // 0x028, '.b', 壊れたときに実行するスクリプト
  Mover mover;                                     // 0x02C
  AuxSpriteGfx gfx;                                // 0x070, '.a'
  AuxSprite sprite;                                // 0x08C
  MapTileOverride tile;                            // 0x0B8
  HitboxData hitbox;                               // 0x0C8
  HitboxData attackHitbox;                         // 0x118
  ZoneEventSource zoneEvents;                      // 0x168
  void (*updateCallback)(struct EntityD9AEElem*);  // 0x198
} EntityD9AEElem;
static_assert(sizeof(EntityD9AEElem) == 412);

// OBJ パレット4行を抱えて、count 個の要素 (1個 412バイト) を回すシングルトン
typedef struct {
  Entity e;               // 0x00, ENTITY_UNK_8
  u16 count;              // 0x18, elems の要素数, _Create が '.m=8' を入れ、0 なら 8 にする
  u8 unk_1a;              // 0x1A, _Init が 0 を入れる
  u8 unk_1b;              // 0x1B, _Init が 0 を入れる
  u16 unk_1c;             // 0x1C, _Init が 0 を入れる
  u8 unk_1e;              // 0x1E, _Init が 0 を入れる
  u8 unk_1f;              // 0x1F, 読み手も書き手も見つかっていない
  rgb555* pltt[4];        // 0x20, &gObjPlttData[0x20/0x30/0x40/0x50] (OBJ パレットの4行)
  rgb555 savedPltt[16];   // 0x30, _Init が pltt[3] の16色をコピーする
  rgb555 unk_50[16];      // 0x50, _Init が pltt[3] の16色をコピーする (savedPltt と同じ内容)
  EntityD9AEElem* elems;  // 0x70, Malloc(count * sizeof(EntityD9AEElem))
} EntityD9AE;
static_assert(sizeof(EntityD9AE) == 116);

IWRAM_DATA EntityD9AE* gEntityD9AE = NULL;  // 0x03000020

const u8 u8_ARRAY_085aa650[8] = {2, 2, 3, 3, 0, 0, 1, 1};  // 0x085AA650

void EntityD9AEElem_BreakEffect0(EntityD9AEElem*);
void EntityD9AEElem_BreakEffect1(EntityD9AEElem*);
void EntityD9AEElem_BreakEffect2(EntityD9AEElem*);

void (*const sEntityD9AEBreakEffects[5])(EntityD9AEElem*) = {
    EntityD9AEElem_BreakEffect0,
    EntityD9AEElem_BreakEffect1,
    EntityD9AEElem_BreakEffect2,
    NULL,
    NULL,
};  // 0x085AA658

void FUN_08003008(void) { gEntityD9AE = NULL; }

NAKED void EntityD9AE_SpawnDust(Vec3* pos, s16 param_2) { INCFUNC("asm/func/EntityD9AE_SpawnDust.inc"); }

NAKED s32 EntityD9AEElem_IsSideBlocked(EntityD9AEElem* elem, s32 param_2, s32 param_3) { INCFUNC("asm/func/EntityD9AEElem_IsSideBlocked.inc"); }

NAKED void EntityD9AE_PlayHitWallSound(u32 kind) { INCFUNC("asm/func/EntityD9AE_PlayHitWallSound.inc"); }

NAKED s32 EntityD9AEElem_IsFacingWall(EntityD9AEElem* elem, s32 param_2, s32 param_3) { INCFUNC("asm/func/EntityD9AEElem_IsFacingWall.inc"); }

NAKED s32 EntityD9AEElem_IsEnclosed(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_IsEnclosed.inc"); }

NAKED void EntityD9AEElem_OnLanded(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_OnLanded.inc"); }

NAKED void EntityD9AEElem_OnHitWall(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_OnHitWall.inc"); }

NAKED void EntityD9AE_PlayPushSound(u32 kind) { INCFUNC("asm/func/EntityD9AE_PlayPushSound.inc"); }

NAKED void EntityD9AEElem_OnDamaged(HitboxData* hitbox, s32 param_2, EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_OnDamaged.inc"); }

NAKED void FUN_080035e0(void) { INCFUNC("asm/func/FUN_080035e0.inc"); }

NAKED void EntityD9AEElem_DropUpper(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_DropUpper.inc"); }

NAKED s32 EntityD9AEElem_Release(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_Release.inc"); }

NAKED s32 EntityD9AE_ReleaseAll(void) { INCFUNC("asm/func/EntityD9AE_ReleaseAll.inc"); }

NAKED s32 Cmd_5C0B(void) { INCFUNC("asm/func/Cmd_5C0B.inc"); }

NAKED s32 Cmd_0E76(void) { INCFUNC("asm/func/Cmd_0E76.inc"); }

NAKED void EntityD9AEElem_BreakEffect0(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_BreakEffect0.inc"); }

NAKED void EntityD9AEElem_BreakEffect1(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_BreakEffect1.inc"); }

NAKED void EntityD9AEElem_BreakEffect2(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_BreakEffect2.inc"); }

NAKED void EntityD9AEElem_SpawnMoveDust(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_SpawnMoveDust.inc"); }

NAKED s32 EntityD9AEElem_TryMove(EntityD9AEElem* elem, s32 tileIdx, s32 dir) { INCFUNC("asm/func/EntityD9AEElem_TryMove.inc"); }

NAKED s32 EntityD9AE_PushAt(Vec3* pos, s32 dir) { INCFUNC("asm/func/EntityD9AE_PushAt.inc"); }

NAKED s32 EntityD9AE_PushAtDir8(Vec3* pos, u32 dir) { INCFUNC("asm/func/EntityD9AE_PushAtDir8.inc"); }

NAKED void EntityD9AEElem_UpdateIdle(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_UpdateIdle.inc"); }

NAKED void EntityD9AEElem_UpdateMove(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_UpdateMove.inc"); }

NAKED void EntityD9AEElem_UpdateFall(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_UpdateFall.inc"); }

NAKED void EntityD9AEElem_UpdateBreak(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_UpdateBreak.inc"); }

NAKED void EntityD9AEElem_UpdateAppear(EntityD9AEElem* elem) { INCFUNC("asm/func/EntityD9AEElem_UpdateAppear.inc"); }

NAKED s32 EntityD9AE_Update(EntityD9AE* p) { INCFUNC("asm/func/EntityD9AE_Update.inc"); }

NAKED s32 EntityD9AE_Destroy(EntityD9AE* p) { INCFUNC("asm/func/EntityD9AE_Destroy.inc"); }

NAKED s32 EntityD9AE_Init(EntityD9AE* p, u32 param_2) { INCFUNC("asm/func/EntityD9AE_Init.inc"); }

NAKED EntityD9AE* EntityD9AE_Create(u32 param_1) { INCFUNC("asm/func/EntityD9AE_Create.inc"); }

// 空いている枠を返す, 無ければ NULL
EntityD9AEElem* EntityD9AE_FindFreeElem(EntityD9AE* p) {
  EntityD9AEElem* e = p->elems;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (!e->active) {
      return e;
    }
    e++;
  }
  return NULL;
}

// id が一致する使用中の枠を返す, 無ければ NULL
EntityD9AEElem* EntityD9AE_FindElemByID(EntityD9AE* p, u32 id) {
  EntityD9AEElem* e = p->elems;
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (e->active && e->mover.id == id) {
      return e;
    }
    e++;
  }
  return NULL;
}

NAKED s32 EntityD9AE_SpawnElem(u16 id, s32 kind, s32 flags, Vec3* pos, s32 file, s32 poseIdx) { INCFUNC("asm/func/EntityD9AE_SpawnElem.inc"); }

NAKED s32 Cmd_E02A(void) { INCFUNC("asm/func/Cmd_E02A.inc"); }

NAKED s32 Cmd_B76C(void) { INCFUNC("asm/func/Cmd_B76C.inc"); }
