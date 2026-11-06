#include "camera.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "solar.h"
#include "tilemap.h"
#include "trig.h"
#include "video.h"
#include "vm.h"

// BG1 に TILEMAP_0B12 を敷き、 player を中心に angle/dist で回る world 座標へスクロールさせるシングルトン
typedef struct EntityA628 {
  Entity e;             // 0x00, ENTITY_UNK_9
  Tilemaps* tilemap;    // 0x18, TILEMAP_0B12
  u16 unk_1c;           // 0x1C, EntityCreate の第2引数, 読み手が見つかっていない
  u8 playerIdx;         // 0x1E, '.i', 通信中は gEntity9A9F->playerIdx
  bool8 active;         // 0x1F, '.m=1', 0 なら位置更新も BG1 の表示も止まる
  Vec3 destPos;         // 0x20, pos の補間先
  WorldPos pos;         // 0x28, アイソメトリック投影して BG1 のスクロール量にする world 座標
  u16 angle;            // 0x30, gSineTable の添字 (下位8bitのみ), player から見た pos の方角, 初期値は gStat+0x932 の太陽の角度
  s16 dist;             // 0x32, player から pos までの距離, 初期値 300
  u16 blend;            // 0x34, 0〜8 の補間の重み, Div(blend * pos + destPos, blend + 1)
  bool8 followCamera;   // 0x36, 0 以外なら pos を gCameraCoords.worldPos へ寄せる
  bool8 sunOverridden;  // 0x37, gSunGaugeOverride == SUN_OVERRIDE_RISING の間 1, この間は BG1 を隠す
} EntityA628;
static_assert(sizeof(EntityA628) == 56);

COMMON_DATA EntityA628* gEntityA628 = NULL;  // 0x03002C3C

void EntityA628_ResetOrbit(EntityA628*);

static inline bool32 IsSunRising(void) {
  u16 override = gSunGaugeOverride;
  return override == SUN_OVERRIDE_RISING;
}

static inline s32 GetLocalPlayerIdx(void) {
  if (gEntity9A9F == NULL) {
    return -1;
  }
  return gEntity9A9F->playerIdx;
}

static inline u8 GetLinkBGHidden(s32 idx) {
  if (gEntity9A9F == NULL) {
    return 0;
  }
  return gEntity9A9F->unk_60[idx];
}

void EntityA628_StartFollowCamera(void) {
  if (gEntityA628 != NULL) {
    gEntityA628->followCamera = TRUE;
    gEntityA628->blend = 0;
  }
}

void EntityA628_StopFollowCamera(void) {
  if (gEntityA628 != NULL) {
    gEntityA628->followCamera = FALSE;
    gEntityA628->blend = 8;
  }
}

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

// 回る背景が有効か返す, ライジングサン中は常に偽
u32 EntityA628_IsActive(void) {
  if (IsSunRising()) {
    return 0;
  }
  if (gEntityA628 == NULL) {
    return 0;
  }
  return gEntityA628->active;
}

u32 EntityA628_IsActiveScripted(void) { return EntityA628_IsActive(); }

void EntityA628_ResetOrbit(EntityA628* p) {
  p->angle = gStat->sunAngle;
  p->dist = 300;
  p->blend = 0;
}

void EntityA628_UpdateBGVisibility(EntityA628* p) {
  if (gGameFlags & FLAG030047A4_LINK) {
    if (GetLinkBGHidden(GetLocalPlayerIdx())) {
      p->active = FALSE;
    } else if (!p->active) {
      EntityA628_ResetOrbit(p);
      p->active = TRUE;
    }
    if (p->active) {
      SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    } else {
      CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    }
  } else {
    if (IsSunRising()) {
      if (!p->sunOverridden) {
        p->sunOverridden = TRUE;
      }
    } else if (p->sunOverridden) {
      p->sunOverridden = FALSE;
      if (p->active) {
        EntityA628_ResetOrbit(p);
      }
    }
    if (p->active && !p->sunOverridden) {
      SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    } else {
      CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    }
  }
}

void EntityA628_UpdatePos(EntityA628* p) {
  if (p->followCamera) {
    if (p->blend <= 6) {
      s32 k, n;

      p->blend++;
      k = 8 - p->blend;
      n = k + 1;
      p->pos.x = Div(p->pos.x * k + gCameraCoords.worldPos.x, n);
      p->pos.y = Div(p->pos.y * k + gCameraCoords.worldPos.y, n);
      p->pos.z = Div(p->pos.z * k + gCameraCoords.worldPos.z, n);
    } else {
      p->blend = 8;
      p->pos.x = gCameraCoords.worldPos.x;
      p->pos.y = gCameraCoords.worldPos.y;
      p->pos.z = gCameraCoords.worldPos.z;
    }
  } else if (gPlayerPtr[p->playerIdx]->lookAroundOffset.val != 0) {
    if (gPlayerPtr[p->playerIdx]->action == PACT_WALL) {
      p->angle = (gStat->sunAngle + 128) & 0xFF;
    } else {
      p->angle = gStat->sunAngle;
    }
    if (p->blend <= 6) {
      s32 k, n;

      p->blend++;
      k = 8 - p->blend;
      n = k + 1;
      p->pos.x = Div(p->pos.x * k + gPlayerPtr[p->playerIdx]->pos_3c0.x, n);
      p->pos.y = Div(p->pos.y * k + gPlayerPtr[p->playerIdx]->pos_3c0.y, n);
      p->pos.z = Div(p->pos.z * k + gPlayerPtr[p->playerIdx]->pos_3c0.z, n);
    } else {
      p->blend = 8;
      p->pos.x = gPlayerPtr[p->playerIdx]->pos_3c0.x;
      p->pos.y = gPlayerPtr[p->playerIdx]->pos_3c0.y;
      p->pos.z = gPlayerPtr[p->playerIdx]->pos_3c0.z;
    }
  } else {
    s32 diff = Angle_Diff((s16)gStat->sunAngle, p->angle - 256);
    s32 d = 128 - diff;
    s32 step;

    if ((d < 0 ? -d : d) <= 16) {
      if (diff != 128) {
        if (diff < 128) {
          step = (d >> 2) + 1;
          p->angle = (p->angle + step) & 0xFF;
        } else {
          p->angle = (p->angle - ((diff - 128) >> 2) + 255) & 0xFF;
        }
      }
      p->dist = (p->dist * 3 - 300) >> 2;
      if (p->dist < 0) {
        p->dist = -p->dist;
        p->angle = gStat->sunAngle;
      }
    } else {
      if (diff != 0) {
        if (diff < 128) {
          step = (diff >> 2) + 1;
          p->angle = (p->angle + step) & 0xFF;
        } else {
          step = ((256 - diff) >> 2) + 1;
          p->angle = (p->angle + 256 - step) & 0xFF;
        }
      }
      if (p->dist < 300) {
        p->dist = (p->dist * 3 + 300) >> 2;
      }
    }
    if (p->blend > 1) {
      s32 n;

      p->destPos.x = gPlayerPtr[p->playerIdx]->mover.pos.x + FixToInt(12, COS(p->angle) * p->dist);
      p->destPos.y = (((0x80 - gPlayerPtr[p->playerIdx]->unk_97a) * 150) >> 7) + gPlayerPtr[p->playerIdx]->mover.pos.y;
      p->destPos.z = gPlayerPtr[p->playerIdx]->mover.pos.z + FixToInt(12, SIN(p->angle) * p->dist);
      p->blend--;
      n = p->blend + 1;
      p->pos.x = Div(p->pos.x * p->blend + p->destPos.x, n);
      p->pos.y = Div(p->pos.y * p->blend + p->destPos.y, n);
      p->pos.z = Div(p->pos.z * p->blend + p->destPos.z, n);
    } else {
      p->blend = 0;
      p->pos.x = gPlayerPtr[p->playerIdx]->mover.pos.x + FixToInt(12, COS(p->angle) * p->dist);
      p->pos.y = (((0x80 - gPlayerPtr[p->playerIdx]->unk_97a) * 150) >> 7) + gPlayerPtr[p->playerIdx]->mover.pos.y;
      p->pos.z = gPlayerPtr[p->playerIdx]->mover.pos.z + FixToInt(12, SIN(p->angle) * p->dist);
    }
  }
}

s32 EntityA628_Update(EntityA628* p) {
  EntityA628_UpdateBGVisibility(p);
  if (p->active) {
    Vec3 vp;
    s32 x, y;

    EntityA628_UpdatePos(p);
    WorldToVp(&vp, &p->pos);
    x = gCameraVpCoords.x - vp.x + 128;
    y = gCameraVpCoords.y - vp.y + 128;
    Video_GenerateBGMap(1, FixToInt(3, x - 128), FixToInt(3, y - 128) & ~1, x - 120, y - 90);
  }
  return 0;
}

s32 EntityA628_Destroy(EntityA628* p) {
  gEntityA628 = NULL;
  return 0;
}

void EntityA628_SetupBG(EntityA628* p) {
  s32 idx;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_0B12);
  idx = 0;
  Video_SetupBGLayout(3, 2, p->tilemap, 0, 0, 1, &idx);
  SetBGPrioDirect(1, 1);
  if (IsSunRising()) {
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    p->sunOverridden = TRUE;
  } else {
    if (p->active) {
      SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    } else {
      CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    }
    p->sunOverridden = FALSE;
  }
}

s32 EntityA628_Init(EntityA628* p, u32 param_2, u32 playerIdx, u32 active) {
  p->unk_1c = param_2;
  p->playerIdx = playerIdx;
  p->active = active;
  EntityA628_SetupBG(p);
  EntityA628_ResetOrbit(p);
  p->pos.x = gPlayerPtr[p->playerIdx]->mover.pos.x - FixToInt(12, COS(p->angle) * p->dist);
  p->pos.y = (((0x80 - gPlayerPtr[p->playerIdx]->unk_97a) * 150) >> 7) + gPlayerPtr[p->playerIdx]->mover.pos.y;
  p->pos.z = gPlayerPtr[p->playerIdx]->mover.pos.z - FixToInt(12, SIN(p->angle) * p->dist);
  EntityA628_Update(p);
  gEntityA628 = p;
  return 0;
}

EntityA628* EntityA628_Create(u32 param_1, u32 playerIdx, u32 active) {
  EntityA628* p = gEntityA628;

  if (p == NULL) {
    p = CreateEntity(ENTITY_UNK_9, sizeof(EntityA628));
    if (p != NULL) {
      SetEntityRoutine(p, EntityA628_Update, EntityA628_Destroy);
      if (EntityA628_Init(p, param_1, playerIdx, active) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
  }
  return p;
}

// 0xA628
s32 Cmd_CreateEntityA628(u32 param_1) {
  s32 playerIdx;
  u32 active;

  if (gGameFlags & FLAG030047A4_LINK) {
    playerIdx = GetLocalPlayerIdx();
  } else if (VM_SeekToNamedArg('i')) {
    playerIdx = VM_GetValue();
  } else {
    playerIdx = 0;
  }
  if (VM_SeekToNamedArg('m')) {
    active = VM_GetValue();
  } else {
    active = TRUE;
  }
  return (s32)EntityA628_Create(param_1, playerIdx, active);
}
