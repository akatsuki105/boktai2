#include "camera.h"

#include "collision_map.h"
#include "file.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "random.h"
#include "registry.h"
#include "video.h"
#include "vm.h"

COMMON_DATA Vec3 gCameraVpCoords = {};  // 0x030047C8
COMMON_DATA Camera* gCamera = NULL;     // 0x030047D0
COMMON_DATA u8 u8_030047d4[4] = {};     // todo
COMMON_DATA u16 u16_030047d8 = 0;       // 0x030047D8, TextRenderer_PlayCharSound がこのIDのメッセージでは音を鳴らさない
COMMON_DATA u8 u8_030047da[6] = {};     // todo

s32 FUN_082327c0(FileID id);
s32 FUN_082345f8(FileID id);
s32 FUN_08234db8(FileID id);
s32 FUN_082358f4(FileID id);
void FUN_082327f0(CollisionMapTileData* tiledata);
void FUN_08234624(ZoneData* zones);
void FUN_08234ddc(PathData* paths);
void FUN_08235918(NavMesh* navMesh);

// Collision Map File が圧縮されてたら展開して返す、圧縮されてなかったらそのまま返す
CollisionMapFile* OpenCollisionMapFile(void* file) {
  u8* magic = file;

  if (magic[0] == 'H' && magic[1] == 'P') {  // "HP"
    return (CollisionMapFile*)file;
  }
  LZ77UnCompWram(file, gDecompressedCollisionMapHeader);
  return (CollisionMapFile*)gDecompressedCollisionMapFile;
}

// id is HP_XXXX in "include/constants/collision_map.h"
// ヘッダの相対オフセットを絶対アドレスに直して、タイル/ゾーン/パス/ナビメッシュをそれぞれ登録する
s32 Map_LoadCollisionMapFile(s32 id) {
  CollisionMapFile hdr;
  CollisionMapFile* f;
  void* file = GetFile(DIR_COLLISION_MAP, id);

  if (file == NULL) {
    return -1;
  }

  f = OpenCollisionMapFile(file);
  hdr = *f;
  hdr.offsetToTileData += (u32)f;
  hdr.offsetToZones += (u32)f;
  hdr.offsetToPaths += (u32)f;
  if (hdr.offsetToNavmesh != 0) {
    hdr.offsetToNavmesh += (u32)f;
  }

  FUN_082327f0((CollisionMapTileData*)hdr.offsetToTileData);
  FUN_08234624((ZoneData*)hdr.offsetToZones);
  FUN_08234ddc((PathData*)hdr.offsetToPaths);
  FUN_08235918((NavMesh*)hdr.offsetToNavmesh);
  return 0;
}

// 0x30AD
void Map_LoadMapScripted(void) {
  CollisionMapData* cm;
  CollisionMapTileData* td;

  s32 n = VM_GetNamedArgValue('n', 0);  // n は 使わない
  s32 h = VM_GetNamedArgValue('h', 0);
  s32 t = VM_GetNamedArgValue('t', 0);
  s32 r = VM_GetNamedArgValue('r', 0);
  s32 z = VM_GetNamedArgValue('z', 0);
  s32 fileID = VM_GetNamedArgValue('p', 0);
  if (fileID != 0) {
    Map_LoadCollisionMapFile(fileID);
  } else {
    if (h != 0) FUN_082327c0(h);
    if (t != 0) FUN_082345f8(t);
    if (r != 0) FUN_08234db8(r);
    if (z != 0) FUN_082358f4(z);
  }

  // これ以降が Camera_SetTilemapOffset と同じ処理になる
  cm = Registry_Find(0x56C2);
  td = cm->tiledata;
  if (VM_SeekToNamedArg('v')) {
    s32 val = VM_GetValue();
    if (val == 0) {
      Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
      gCameraCoords.tilemapX = td->tilemap_offset_x >> 4;
      gCameraCoords.tilemapY = td->tilemap_offset_y >> 4;
    } else {
      Video_SetDrawPasses(val, FUN_0822de64, FUN_0822ac90, MainSprite_DrawListScreen);
      gCameraCoords.tilemapX = 0;
      gCameraCoords.tilemapY = 0;
    }
  }
}

void Camera_SetTilemapOffset(void) {
  s32 val = VM_GetNamedArgValue('v', 0);
  if (val == 0) {
    CollisionMapData* p = Registry_Find(0x56C2);
    Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
    if (p != NULL) {
      if (p->tiledata != NULL) {
        gCameraCoords.tilemapX = p->tiledata->tilemap_offset_x >> 4;
        gCameraCoords.tilemapY = p->tiledata->tilemap_offset_y >> 4;
        return;
      }
    }
  } else {
    Video_SetDrawPasses(val, FUN_0822de64, FUN_0822ac90, MainSprite_DrawListScreen);
  }
  gCameraCoords.tilemapX = 0;
  gCameraCoords.tilemapY = 0;
}

s32 FUN_0823b740(void) { return 0; }

void Camera_0823b744(void) { gCamera = NULL; }

void Camera_ApplyBounds1(Camera* cam, Vec3* pos) {
  s32 half = pos->y >> 1;
  s32 x = pos->x - half;
  s32 z = pos->z - half;
  if (x < cam->unk_8e) {
    x = cam->unk_8e;
  } else if (x > cam->unk_92) {
    x = cam->unk_92;
  }
  if (z < cam->unk_90) {
    z = cam->unk_90;
  } else if (z > cam->unk_94) {
    z = cam->unk_94;
  }
  pos->x = x + half;
  pos->z = z + half;
}

void Camera_ApplyBounds2(Camera* cam, Vec3* pos) {
  s32 v, d;

  v = pos->z - pos->x;
  if (v < cam->unk_8e) {
    d = (cam->unk_8e - v) >> 1;
    pos->x -= d;
    pos->z += d;
  } else if (v > cam->unk_92) {
    d = (v - cam->unk_92) >> 1;
    pos->x += d;
    pos->z -= d;
  }
  v = pos->z + pos->x - pos->y;
  if (v < cam->unk_90) {
    d = (cam->unk_90 - v) >> 1;
    pos->x += d;
    pos->z += d;
  } else if (v > cam->unk_94) {
    d = (v - cam->unk_94) >> 1;
    pos->x -= d;
    pos->z -= d;
  }
}

void Camera_ApplyBounds(Camera* cam, Vec3* pos) {
  if (cam->unk_8c == 1) {
    Camera_ApplyBounds1(cam, pos);
  } else if (cam->unk_8c == 2) {
    Camera_ApplyBounds2(cam, pos);
  }
}

void FUN_0823b864(void) {
  if (gCamera != NULL) {
    gCamera->moveMode = 0;
  }
}

void FUN_0823b880(s32 n) {
  if (gCamera != NULL) {
    if (n < 2) {
      gCamera->moveMode = 0;
    } else {
      gCamera->moveTimer = n;
      gCamera->moveMode = 3;
    }
  }
}

NAKED void FUN_0823b8ac(Vec3* pos) { INCFUNC("asm/func/FUN_0823b8ac.inc"); }

void FUN_0823b980(s32 n, Vec3* pos) {
  if (gCamera != NULL) {
    gCamera->destPos.x = pos->x;
    gCamera->destPos.y = pos->y;
    gCamera->destPos.z = pos->z;
    if (n < 2) {
      gCamera->moveMode = 1;
    } else {
      gCamera->moveTimer = n;
      gCamera->moveMode = 2;
    }
  }
}

void FUN_0823b9cc(s32 n) {
  if (gCamera != NULL && !(gFlag030047a4 & FLAG030047A4_LINK)) {
    if (n > gCamera->shakeAmplitude) {
      gCamera->shakeAmplitude = n;
    }
  }
}

// 2^8 での符号付き除算, / 256 と結果は同じだが、原典はこの形 (符号を見て shift) を使っている
// アイソメトリック投影の計算に繰り返し現れる
static inline s32 Div256(s32 v) { return v >= 0 ? (v >> 8) : -((-v) >> 8); }

// ワールド座標をアイソメトリック投影して視点座標にする
static inline void WorldToVp(Vec3* vp, Vec3* world) {
  s32 hx = world->x >> 1;
  s32 hz = world->z >> 1;
  s32 a, b;

  vp->x = Div256((hx - hz) * 48);
  a = Div256((hx + hz) * 48);
  b = Div256(world->y * 24);
  vp->y = a - b;
  vp->z = a + b;
}

// カメラのワールド座標に画面ゆれを反映して、投影しなおす
void Camera_Translate(void) {
  if (gCamera != NULL) {
    gCameraCoords.worldPos.x -= gCamera->shakeOffsetX;
    gCameraCoords.worldPos.z -= gCamera->shakeOffsetZ;
    WorldToVp(&gCameraVpCoords, &gCameraCoords.worldPos);
    gCamera->shakeAmplitude = 0;
    gCamera->shakeOffsetX = 0;
    gCamera->shakeOffsetZ = 0;
  }
}

void FUN_0823baa8(void) {
  if (gCamera != NULL) {
    gCamera->unk_1c = 1;
    gCamera->lookMode = 0;
    gCamera->unk_1e = 0;
  }
}

NAKED void FUN_0823bac8(Vec3* pos) { INCFUNC("asm/func/FUN_0823bac8.inc"); }

void FUN_0823bb7c(s32 n, Vec3* pos) {
  if (gCamera != NULL) {
    gCamera->pos_6c.x = pos->x;
    gCamera->pos_6c.y = pos->y;
    gCamera->pos_6c.z = pos->z;
    gCamera->unk_1c = 1;
    if (n < 2) {
      gCamera->lookMode = 1;
    } else {
      gCamera->lookTimer = n;
      gCamera->lookMode = 2;
    }
    gCamera->unk_1e = 0;
  }
}

void FUN_0823bbd4(u32 targetID, Vec3* pos) {
  if (gCamera != NULL) {
    gCamera->lookTargetID = targetID;
    if (Mover_FindByID_Proxy(gCamera->lookTargetID) != NULL) {
      gCamera->unk_1c = 1;
      gCamera->pos_74 = *pos;
      gCamera->lookMode = 3;
      gCamera->unk_1e = 0;
    }
  }
}

void FUN_0823bc14(u32 targetID, s32 n, Vec3* pos) {
  if (gCamera != NULL) {
    gCamera->lookTargetID = targetID;
    if (Mover_FindByID_Proxy(gCamera->lookTargetID) != NULL) {
      gCamera->unk_1c = 1;
      gCamera->pos_74 = *pos;
      if (n < 2) {
        gCamera->lookMode = 3;
      } else {
        gCamera->lookTimer = n;
        gCamera->lookMode = 4;
      }
      gCamera->unk_1e = 0;
    }
  }
}

void FUN_0823bc70(s32 n) {
  if (gCamera != NULL) {
    gCamera->unk_1c = 1;
    if (n < 2) {
      gCamera->lookMode = 0;
    } else {
      gCamera->lookTimer = n;
      gCamera->lookMode = 5;
    }
    gCamera->unk_1e = 0;
  }
}

void FUN_0823bca8(s32 n) {
  if (gCamera != NULL) {
    if (n < 2) {
      gCamera->unk_1c = 0;
    } else {
      gCamera->unk_1c = 1;
      gCamera->lookMode = 6;
      gCamera->lookTimer = n;
    }
    gCamera->unk_1e = 0;
  }
}

// Unused?
void FUN_0823bce4(Vec3* pos, s32* enabled) {
  if (gCamera != NULL) {
    gCamera->targetPos = pos;
    gCamera->unk_a0 = enabled;
    gCamera->unk_1c = 1;
    gCamera->lookMode = 7;
    gCamera->unk_1e = 0;
  }
}

NON_MATCH void FUN_0823bd14(u32 amplitude, u32 frames, s32 stopOnEnd) {
#ifdef NONMATCHING_C
  if (gCamera != NULL && (gFlag030047a4 & FLAG030047A4_LINK) == 0) {
    if (frames == 0 && stopOnEnd == 1) {
      gCamera->shakeActive = FALSE;
      gCamera->shakeStopOnEnd = FALSE;
      gCamera->shakeCurrent = 0;
      gCamera->shakeTarget = 0;
    } else {
      gCamera->shakeActive = TRUE;
      gCamera->shakeTarget = amplitude;
      gCamera->shakeTimer = frames;
      if ((u16)frames == 0) {
        gCamera->shakeCurrent = gCamera->shakeTarget;
      }
      gCamera->shakeStopOnEnd = stopOnEnd;
    }
    gCamera->unk_1e = 0;
  }
#else
  INCFUNC("asm/func/FUN_0823bd14.inc");
#endif
}

void FUN_0823bd98(Camera* cam) {
  if (cam != NULL) {
    cam->unk_1e = 1;
    if (VM_SeekToNamedArg('e')) {
      s32 type, val;
      VM_DecodeValue(VM_GetPC(), &type, &val);
      cam->scriptID = val;
      cam->scriptIDType = 0;
    } else if (VM_SeekToNamedArg('R')) {
      cam->scriptID = VM_GetValue();
      cam->scriptIDType = 1;
    } else {
      cam->scriptID = 0;
    }
  }
}

void FUN_0823bdf8(void) {
  FUN_0823baa8();
  FUN_0823bd98(gCamera);
}

void FUN_0823be10(void) {
  if (VM_SeekToNamedArg('p')) {
    Vec3 pos;
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
    FUN_0823bac8(&pos);
    FUN_0823bd98(gCamera);
  }
}

void Camera_PanTo(void) {
  if (VM_SeekToNamedArg('f')) {
    Vec3 pos;
    s32 n = VM_GetValue();
    if (VM_SeekToNamedArg('p')) {
      pos.x = VM_GetValue();
      pos.y = VM_GetValue();
      pos.z = VM_GetValue();
      FUN_0823bb7c(n, &pos);
      FUN_0823bd98(gCamera);
    }
  }
}

void FUN_0823bee8(void) {
  if (VM_SeekToNamedArg('n')) {
    Vec3 pos;
    s32 targetID = VM_GetValue();
    if (VM_SeekToNamedArg('o')) {
      pos.x = VM_GetValue();
      pos.y = VM_GetValue();
      pos.z = VM_GetValue();
    } else {
      pos.x = 0, pos.y = 0, pos.z = 0;
    }
    FUN_0823bbd4(targetID, &pos);
    FUN_0823bd98(gCamera);
  }
}

void FUN_0823bf70(void) {
  if (VM_SeekToNamedArg('f')) {
    s32 n = VM_GetValue();
    if (VM_SeekToNamedArg('n')) {
      Vec3 pos;
      s32 targetID = VM_GetValue();
      if (VM_SeekToNamedArg('o')) {
        pos.x = VM_GetValue();
        pos.y = VM_GetValue();
        pos.z = VM_GetValue();
      } else {
        pos.x = 0, pos.y = 0, pos.z = 0;
      }
      FUN_0823bc14(targetID, n, &pos);
      FUN_0823bd98(gCamera);
    }
  }
}

void FUN_0823c008(void) {
  if (VM_SeekToNamedArg('f')) {
    FUN_0823bc70(VM_GetValue());
    FUN_0823bd98(gCamera);
  }
}

void Camera_Reset(void) {
  if (VM_SeekToNamedArg('f')) {
    FUN_0823bca8(VM_GetValue());
    FUN_0823bd98(gCamera);
  }
}

void FUN_0823c050(void) {
  if (VM_SeekToNamedArg('w')) {
    s32 amplitude = VM_GetValue();
    s32 frames = VM_SeekToNamedArg('f') ? VM_GetValue() : 1;
    s32 stopOnEnd = VM_SeekToNamedArg('N') ? VM_GetValue() : 0;
    FUN_0823bd14(amplitude, frames, stopOnEnd);
    FUN_0823bd98(gCamera);
  }
}

void FUN_0823c0a4(Camera* cam) { cam->unk_1e = 2; }

void FUN_0823c0ac(Camera* cam) { EntityMsgBox_EndWait(&cam->msgbox, 1); }

NAKED void FUN_0823c0bc(Camera* cam) { INCFUNC("asm/func/FUN_0823c0bc.inc"); }

void FUN_0823c1f8(Camera* cam) {
  s32 scriptID = cam->scriptID;
  if (scriptID != 0) {
    if (cam->scriptIDType == 0) {
      cam->scriptID = 0;
      VM_ExecByPointer((u8*)scriptID, NULL);
    } else {
      cam->scriptID = 0;
      VM_ExecByID(scriptID, NULL);
    }
  }
}

void FUN_0823c228(Camera* cam) {
  if (cam->unk_1e == 1) {
    FUN_0823c1f8(cam);
  } else if (cam->unk_1e == 2) {
    FUN_0823c0ac(cam);
  }
}

void FUN_0823c244(void) {
  if (gCamera != NULL) {
    gCamera->unk_8c = 0;
  }
}

void FUN_0823c260(Vec3* min, Vec3* max) {
  if (gCamera != NULL) {
    gCamera->unk_8e = min->x - (min->y >> 1);
    gCamera->unk_90 = min->z - (min->y >> 1);
    gCamera->unk_92 = max->x - (max->y >> 1);
    gCamera->unk_94 = max->z - (max->y >> 1);
    gCamera->unk_8c = 1;
    Camera_ApplyBounds(gCamera, &gCameraCoords.worldPos);
  }
}

void Camera_ConnectToTilemap(void) {
  if (VM_SeekToNamedArg('I')) {
    Vec3 min, max;
    min.x = VM_GetValue(), min.y = VM_GetValue(), min.z = VM_GetValue();
    if (VM_SeekToNamedArg('A')) {
      max.x = VM_GetValue(), max.y = VM_GetValue(), max.z = VM_GetValue();
      FUN_0823c260(&min, &max);
    }
  }
}

void FUN_0823c35c(Vec3* min, Vec3* max) {
  if (gCamera != NULL) {
    gCamera->unk_8e = min->z - min->x;
    gCamera->unk_90 = min->z + min->x - min->y;
    gCamera->unk_92 = max->z - max->x;
    gCamera->unk_94 = max->z + max->x - max->y;
    gCamera->unk_8c = 2;
    Camera_ApplyBounds(gCamera, &gCameraCoords.worldPos);
  }
}

void Camera_SetBoundsType2Scripted(void) {
  if (VM_SeekToNamedArg('I')) {
    Vec3 min, max;
    min.x = VM_GetValue(), min.y = VM_GetValue(), min.z = VM_GetValue();
    if (VM_SeekToNamedArg('A')) {
      max.x = VM_GetValue(), max.y = VM_GetValue(), max.z = VM_GetValue();
      FUN_0823c35c(&min, &max);
    }
  }
}

NAKED void FUN_0823c450(Camera* cam) { INCFUNC("asm/func/FUN_0823c450.inc"); }

NAKED void FUN_0823c620(Camera* cam) { INCFUNC("asm/func/FUN_0823c620.inc"); }

// 画面揺れを1フレーム進め、worldPos に揺れのオフセットを足す
NON_MATCH void* FUN_0823c928(Camera* cam) {
#ifdef NONMATCHING_C
  if (cam->shakeActive) {
    if (cam->shakeTimer != 0) {
      s32 v = Div(cam->shakeTimer * cam->shakeCurrent + cam->shakeTarget, cam->shakeTimer + 1);
      cam->shakeCurrent = v;
      cam->shakeAmplitude = v;
      if (--cam->shakeTimer == 0) {
        if (cam->shakeStopOnEnd) {
          cam->shakeActive = FALSE;
          cam->shakeStopOnEnd = FALSE;
          cam->shakeCurrent = 0;
          cam->shakeTarget = 0;
        } else {
          cam->shakeCurrent = cam->shakeTarget;
        }
        FUN_0823c228(cam);
      }
    } else {
      cam->shakeAmplitude = cam->shakeCurrent;
    }
  }
  if (cam->shakeAmplitude != 0) {
    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    cam->shakeOffsetX = ModArm(cam->shakeAmplitude, gRandomTable[gRandTableIdx]) - (cam->shakeAmplitude >> 1);
    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    cam->shakeOffsetZ = ModArm(cam->shakeAmplitude, gRandomTable[gRandTableIdx]) - (cam->shakeAmplitude >> 1);
    gCameraCoords.worldPos.x += cam->shakeOffsetX;
    gCameraCoords.worldPos.z += cam->shakeOffsetZ;
    cam->shakeAmplitude = 0;
  } else {
    cam->shakeOffsetX = 0;
    cam->shakeOffsetZ = 0;
  }
#else
  INCFUNC("asm/func/FUN_0823c928.inc");
#endif
}

NAKED s32 Camera_Update(Camera* cam) { INCFUNC("asm/func/Camera_Update.inc"); }

s32 Camera_Destroy(Camera* cam) {
  if (!(gFlag030047a4 & FLAG030047A4_LINK)) {
    EntityMsgBus_Unregister(&cam->msgbox);
  }
  gCamera = NULL;
  return 0;
}

NAKED s32 Camera_Init(Camera* cam, u32 val) { INCFUNC("asm/func/Camera_Init.inc"); }

Camera* Camera_Create(u32 val) {
  if (gCamera == NULL) {
    Camera* cam = CreateEntity(ENTITY_CAMERA, sizeof(Camera));
    if (cam != NULL) {
      SetEntityRoutine(cam, Camera_Update, Camera_Destroy);
      if (Camera_Init(cam, val) < 0) {
        KillEntity((Entity*)cam);
        return NULL;
      }
    }
    return cam;
  }
  return gCamera;
}
