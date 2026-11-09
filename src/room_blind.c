#include "camera.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "link_session.h"
#include "player.h"
#include "solar.h"
#include "tilemap.h"
#include "trig.h"
#include "video.h"
#include "vm.h"

// 暗い部屋で BG1 にブラインドを重ね, プレイヤーのまわりだけを見せる
// ライジングサン発動中は問答無用で明るくする, 天窓のある部屋で太陽ゲージ 1以上の時に明るくする処理は、ここではなくスクリプト側で行う
typedef struct RoomBlind {
  Entity e;               // 0x00, ENTITY_UNK_9
  Tilemaps* tilemap;      // 0x18, TILEMAP_BLIND, プレイヤーの周辺しか見えないようにするためのブラインド
  u16 unk_1c;             // 0x1C, EntityCreate の第2引数, 読み手が見つかっていない
  u8 playerIdx;           // 0x1E, '.i', 通信中は gLinkSession->playerIdx
  bool8 isDim;            // 0x1F, '.m=1', 部屋が暗いかどうかのフラグ
  Vec3 destPos;           // 0x20, pos の補間先
  WorldPos pos;           // 0x28, アイソメトリック投影して BG1 のスクロール量にする world 座標
  u16 angle;              // 0x30, gSineTable の添字 (下位8bitのみ), player から見た pos の方角, 初期値は gStat+0x932 の太陽の角度
  s16 dist;               // 0x32, player から pos までの距離, 初期値 300
  u16 blend;              // 0x34, 0〜8 の補間の重み, Div(blend * pos + destPos, blend + 1)
  bool8 followCamera;     // 0x36, 0 以外なら pos を gCameraCoords.worldPos へ寄せる
  bool8 risingSunActive;  // 0x37, ライジングサン発動中は TRUE, この間は暗い部屋でも BG1 を隠す
} RoomBlind;
static_assert(sizeof(RoomBlind) == 56);

COMMON_DATA RoomBlind* gRoomBlind = NULL;  // 0x03002C3C

void RoomBlind_ResetOrbit(RoomBlind*);

// ライジングサン発動中は暗い部屋でも問答無用で明るくする
static inline bool32 IsRisingSunActive(void) {
  u16 override = gSunGaugeOverride;
  return override == SUN_OVERRIDE_RISING;
}

static inline s32 GetLocalPlayerIdx(void) {
  if (gLinkSession == NULL) {
    return -1;
  }
  return gLinkSession->playerIdx;
}

static inline u8 GetLinkBGHidden(s32 idx) {
  if (gLinkSession == NULL) {
    return 0;
  }
  return gLinkSession->luxGauge[idx];
}

void RoomBlind_StartFollowCamera(void) {
  if (gRoomBlind != NULL) {
    gRoomBlind->followCamera = TRUE;
    gRoomBlind->blend = 0;
  }
}

void RoomBlind_StopFollowCamera(void) {
  if (gRoomBlind != NULL) {
    gRoomBlind->followCamera = FALSE;
    gRoomBlind->blend = 8;
  }
}

// 0xDDF8
void Cmd_StartRoomBlindFollowCamera(void) { RoomBlind_StartFollowCamera(); }

// 0x2924
void Cmd_StopRoomBlindFollowCamera(void) { RoomBlind_StopFollowCamera(); }

// 0xEF19, 部屋を暗くする, 窓のある部屋ではスクリプトが太陽ゲージ 0 のときに呼ぶ
void Cmd_DimRoom(void) {
  RoomBlind* p = gRoomBlind;

  if (p != NULL && !p->isDim) {
    RoomBlind_ResetOrbit(p);
    p->isDim = TRUE;
  }
}

// 部屋を明るくする, 窓のある部屋ではスクリプトが太陽ゲージ 1 以上のときに呼ぶ
void Cmd_BrightenRoom(void) {
  if (gRoomBlind != NULL) {
    gRoomBlind->isDim = FALSE;
  }
}

// 部屋が暗いかどうかを返す
u32 RoomBlind_IsDim(void) {
  if (IsRisingSunActive()) {  // ライジングサン発動中は問答無用で明るくなる
    return 0;
  }
  if (gRoomBlind == NULL) {
    return 0;
  }
  return gRoomBlind->isDim;
}

// 0x3062
u32 Cmd_IsRoomDim(void) { return RoomBlind_IsDim(); }

void RoomBlind_ResetOrbit(RoomBlind* p) {
  p->angle = gStat->sunAngle;
  p->dist = 300;
  p->blend = 0;
}

void RoomBlind_UpdateBGVisibility(RoomBlind* p) {
  if (gGameFlags & GAMEFLAG_LINK) {
    if (GetLinkBGHidden(GetLocalPlayerIdx())) {
      p->isDim = FALSE;
    } else if (!p->isDim) {
      RoomBlind_ResetOrbit(p);
      p->isDim = TRUE;
    }
    if (p->isDim) {
      SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    } else {
      CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    }
  } else {
    if (IsRisingSunActive()) {
      if (!p->risingSunActive) {
        p->risingSunActive = TRUE;
      }
    } else if (p->risingSunActive) {
      p->risingSunActive = FALSE;
      if (p->isDim) {
        RoomBlind_ResetOrbit(p);
      }
    }
    if (p->isDim && !p->risingSunActive) {
      SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    } else {
      CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    }
  }
}

void RoomBlind_UpdatePos(RoomBlind* p) {
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

s32 RoomBlind_Update(RoomBlind* p) {
  RoomBlind_UpdateBGVisibility(p);
  if (p->isDim) {
    Vec3 vp;
    s32 x, y;

    RoomBlind_UpdatePos(p);
    WorldToVp(&vp, &p->pos);
    x = gCameraVpCoords.x - vp.x + 128;
    y = gCameraVpCoords.y - vp.y + 128;
    Video_GenerateBGMap(1, FixToInt(3, x - 128), FixToInt(3, y - 128) & ~1, x - 120, y - 90);
  }
  return 0;
}

s32 RoomBlind_Destroy(RoomBlind* p) {
  gRoomBlind = NULL;
  return 0;
}

void RoomBlind_SetupBG(RoomBlind* p) {
  s32 idx;

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_BLIND);
  idx = 0;
  Video_SetupBGLayout(3, 2, p->tilemap, 0, 0, 1, &idx);
  SetBGPrioDirect(1, 1);
  if (IsRisingSunActive()) {
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    p->risingSunActive = TRUE;
  } else {
    if (p->isDim) {
      SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    } else {
      CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    }
    p->risingSunActive = FALSE;
  }
}

s32 RoomBlind_Init(RoomBlind* p, u32 param_2, u32 playerIdx, u32 isDim) {
  p->unk_1c = param_2;
  p->playerIdx = playerIdx;
  p->isDim = isDim;
  RoomBlind_SetupBG(p);
  RoomBlind_ResetOrbit(p);
  p->pos.x = gPlayerPtr[p->playerIdx]->mover.pos.x - FixToInt(12, COS(p->angle) * p->dist);
  p->pos.y = (((0x80 - gPlayerPtr[p->playerIdx]->unk_97a) * 150) >> 7) + gPlayerPtr[p->playerIdx]->mover.pos.y;
  p->pos.z = gPlayerPtr[p->playerIdx]->mover.pos.z - FixToInt(12, SIN(p->angle) * p->dist);
  RoomBlind_Update(p);
  gRoomBlind = p;
  return 0;
}

RoomBlind* RoomBlind_Create(u32 param_1, u32 playerIdx, u32 isDim) {
  RoomBlind* p = gRoomBlind;

  if (p == NULL) {
    p = CreateEntity(ENTITY_UNK_9, sizeof(RoomBlind));
    if (p != NULL) {
      SetEntityRoutine(p, RoomBlind_Update, RoomBlind_Destroy);
      if (RoomBlind_Init(p, param_1, playerIdx, isDim) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
  }
  return p;
}

// 0xA628
s32 Cmd_CreateRoomBlind(u32 param_1) {
  s32 playerIdx;
  u32 isDim;

  if (gGameFlags & GAMEFLAG_LINK) {
    playerIdx = GetLocalPlayerIdx();
  } else if (VM_SeekToNamedArg('i')) {
    playerIdx = VM_GetValue();
  } else {
    playerIdx = 0;
  }
  if (VM_SeekToNamedArg('m')) {
    isDim = VM_GetValue();
  } else {
    isDim = TRUE;
  }
  return (s32)RoomBlind_Create(param_1, playerIdx, isDim);
}
