#include "entity.h"
#include "global.h"
#include "tilemap.h"
#include "vm.h"

// BG1 に TILEMAP_0B12 を敷き、 player を中心に angle/dist で回る world 座標へスクロールさせるシングルトン
typedef struct EntityA628 {
  Entity e;             // 0x00, ENTITY_UNK_9
  Tilemaps* tilemap;    // 0x18, TILEMAP_0B12
  u16 unk_1c;           // 0x1C, EntityCreate の第2引数, 読み手が見つかっていない
  u8 playerIdx;         // 0x1E, '.i', 通信中は gEntity9A9F->playerIdx
  bool8 active;         // 0x1F, '.m=1', 0 なら位置更新も BG1 の表示も止まる
  Vec3 destPos;         // 0x20, pos の補間先
  Vec3 pos;             // 0x28, アイソメトリック投影して BG1 のスクロール量にする world 座標
  u16 angle;            // 0x30, gSineTable の添字 (下位8bitのみ), player から見た pos の方角, 初期値は gStat+0x932 の太陽の角度
  s16 dist;             // 0x32, player から pos までの距離, 初期値 300
  u16 blend;            // 0x34, 0〜8 の補間の重み, Div(blend * pos + destPos, blend + 1)
  bool8 followCamera;   // 0x36, 0 以外なら pos を gCameraCoords.worldPos へ寄せる
  bool8 sunOverridden;  // 0x37, gSunGaugeOverride == SUN_OVERRIDE_RISING の間 1, この間は BG1 を隠す
} EntityA628;
static_assert(sizeof(EntityA628) == 56);

extern EntityA628* gEntityA628;  // 0x03002C3C

void EntityA628_ResetOrbit(EntityA628*);

void EntityA628_StartFollowCamera(void) {
  if (gEntityA628 != NULL) {
    gEntityA628->followCamera = TRUE;
    gEntityA628->blend = 0;
  }
}

NAKED void EntityA628_StopFollowCamera(void) { INCFUNC("asm/func/EntityA628_StopFollowCamera.inc"); }

void EntityA628_StartFollowCameraScripted(void) { EntityA628_StartFollowCamera(); }

void EntityA628_StopFollowCameraScripted(void) { EntityA628_StopFollowCamera(); }

void EntityA628_ActivateScripted(void) {
  EntityA628* p = gEntityA628;

  if (p != NULL && !p->active) {
    EntityA628_ResetOrbit(p);
    p->active = TRUE;
  }
}

void EntityA628_DeactivateScripted(void) {
  if (gEntityA628 != NULL) {
    gEntityA628->active = FALSE;
  }
}

NAKED u32 EntityA628_IsActive(void) { INCFUNC("asm/func/EntityA628_IsActive.inc"); }

u32 EntityA628_IsActiveScripted(void) { return EntityA628_IsActive(); }

NAKED void EntityA628_ResetOrbit(EntityA628* p) { INCFUNC("asm/func/EntityA628_ResetOrbit.inc"); }

NAKED void EntityA628_UpdateBGVisibility(EntityA628* p) { INCFUNC("asm/func/EntityA628_UpdateBGVisibility.inc"); }

NAKED void EntityA628_UpdatePos(EntityA628* p) { INCFUNC("asm/func/EntityA628_UpdatePos.inc"); }

NAKED s32 EntityA628_Update(EntityA628* p) { INCFUNC("asm/func/EntityA628_Update.inc"); }

s32 EntityA628_Destroy(EntityA628* p) {
  gEntityA628 = NULL;
  return 0;
}

NAKED void EntityA628_SetupBG(EntityA628* p) { INCFUNC("asm/func/EntityA628_SetupBG.inc"); }

NAKED s32 EntityA628_Init(EntityA628* p, u16 param_2, u8 playerIdx, bool8 active) { INCFUNC("asm/func/EntityA628_Init.inc"); }

NAKED EntityA628* EntityA628_Create(u16 param_1, u8 playerIdx, bool8 active) { INCFUNC("asm/func/EntityA628_Create.inc"); }

NAKED s32 EntityA628_CreateScripted(u16 param_1) { INCFUNC("asm/func/EntityA628_CreateScripted.inc"); }
