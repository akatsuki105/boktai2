#include "camera.h"

#include "global.h"
#include "msgbus.h"
#include "random.h"
#include "vm.h"

Entity2UnkData* FUN_0823b2d0(u16 id);
void* FUN_08230e70(u16 id);
void FUN_0822a448(s32 val, Procedure fn1, Procedure fn2, Procedure fn3);
void FUN_0822db5c(void);
void FUN_0822aaac(void);
void FUN_0822f204(void);
void FUN_0822de64(void);
void FUN_0822ac90(void);
void FUN_0822f224(void);

COMMON_DATA Vec3 gCameraVpCoords = {};  // 0x030047C8
COMMON_DATA Camera* gCamera = NULL;     // 0x030047D0
COMMON_DATA u8 u8_030047d4[12] = {};    // todo

void Camera_SetTilemapOffset(void) {
  s32 kw;
  Unk_0203b000* p;

  kw = VM_GetKeywordValue('v', 0);
  if (kw == 0) {
    p = FUN_08230e70(0x56C2);
    FUN_0822a448(0, FUN_0822db5c, FUN_0822aaac, FUN_0822f204);
    if (p != NULL) {
      if (p->unk_04 != NULL) {
        gCameraCoords.tilemapX = ((s16*)p->unk_04)[4] >> 4;
        gCameraCoords.tilemapY = ((s16*)p->unk_04)[5] >> 4;
        return;
      }
    }
  } else {
    FUN_0822a448(kw, FUN_0822de64, FUN_0822ac90, FUN_0822f224);
  }
  gCameraCoords.tilemapX = 0;
  gCameraCoords.tilemapY = 0;
}

s32 FUN_0823b740(void) { return 0; }

void Camera_0823b744(void) { gCamera = NULL; }

void Camera_ApplyBounds1(Camera* cam, Vec3* pos) {
  s32 half;
  s32 x;
  s32 z;

  half = pos->y >> 1;
  x = pos->x - half;
  z = pos->z - half;
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
  s32 v;
  s32 d;

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
  Camera* cam;

  cam = gCamera;
  if (cam != NULL) {
    if (n < 2) {
      cam->moveMode = 0;
    } else {
      cam->moveTimer = n;
      cam->moveMode = 3;
    }
  }
}

NAKED void FUN_0823b8ac(Vec3* pos) { INCFUNC("asm/func/FUN_0823b8ac.inc"); }

void FUN_0823b980(s32 n, Vec3* pos) {
  Camera* cam;

  cam = gCamera;
  if (cam != NULL) {
    cam->destPos.x = pos->x;
    cam->destPos.y = pos->y;
    cam->destPos.z = pos->z;
    if (n < 2) {
      cam->moveMode = 1;
    } else {
      cam->moveTimer = n;
      cam->moveMode = 2;
    }
  }
}

void FUN_0823b9cc(s32 n) {
  Camera* cam;

  cam = gCamera;
  if (cam != NULL && (gFlag030047a4 & FLAG030047A4_UNK_11) == 0) {
    if (n > cam->shakeAmplitude) {
      cam->shakeAmplitude = n;
    }
  }
}

NON_MATCH void Camera_Translate(void) {
#ifdef NONMATCHING_C
  Camera* cam;
  s32 hx;
  s32 hz;
  s32 a;
  s32 b;

  cam = gCamera;
  if (cam != NULL) {
    gCameraCoords.worldPos.x -= cam->shakeOffsetX;
    gCameraCoords.worldPos.z -= cam->shakeOffsetZ;
    // このアイソメトリック投影のブロックは FUN_0823bac8 / FUN_0823b8ac / Camera_Update / Camera_Init にも同じ形で現れる
    hx = gCameraCoords.worldPos.x >> 1;
    hz = gCameraCoords.worldPos.z >> 1;
    gCameraVpCoords.x = ((hx - hz) * 48) / 256;
    a = ((hx + hz) * 48) / 256;
    b = (gCameraCoords.worldPos.y * 24) / 256;
    gCameraVpCoords.y = a - b;
    gCameraVpCoords.z = a + b;
    cam = gCamera;
    cam->shakeAmplitude = 0;
    cam->shakeOffsetX = 0;
    cam->shakeOffsetZ = 0;
  }
#else
  INCFUNC("asm/func/Camera_Translate.inc");
#endif
}

void FUN_0823baa8(void) {
  Camera* cam;

  cam = gCamera;
  if (cam != NULL) {
    cam->unk_1c = 1;
    cam->lookMode = 0;
    cam->unk_1e = 0;
  }
}

NAKED void FUN_0823bac8(Vec3* pos) { INCFUNC("asm/func/FUN_0823bac8.inc"); }

void FUN_0823bb7c(s32 n, Vec3* pos) {
  Camera* cam;

  cam = gCamera;
  if (cam != NULL) {
    cam->pos_6c.x = pos->x;
    cam->pos_6c.y = pos->y;
    cam->pos_6c.z = pos->z;
    cam->unk_1c = 1;
    if (n < 2) {
      cam->lookMode = 1;
    } else {
      cam->lookTimer = n;
      cam->lookMode = 2;
    }
    gCamera->unk_1e = 0;
  }
}

void FUN_0823bbd4(u32 targetID, Vec3* pos) {
  Camera* cam;

  if (gCamera != NULL) {
    gCamera->lookTargetID = targetID;
    if (FUN_0823b2d0(gCamera->lookTargetID) != NULL) {
      cam = gCamera;
      cam->unk_1c = 1;
      cam->pos_74 = *pos;
      cam->lookMode = 3;
      cam->unk_1e = 0;
    }
  }
}

void FUN_0823bc14(u32 targetID, s32 n, Vec3* pos) {
  Camera* cam;

  if (gCamera != NULL) {
    gCamera->lookTargetID = targetID;
    if (FUN_0823b2d0(gCamera->lookTargetID) != NULL) {
      cam = gCamera;
      cam->unk_1c = 1;
      cam->pos_74 = *pos;
      if (n < 2) {
        cam->lookMode = 3;
      } else {
        cam->lookTimer = n;
        cam->lookMode = 4;
      }
      gCamera->unk_1e = 0;
    }
  }
}

void FUN_0823bc70(s32 n) {
  Camera* cam;

  cam = gCamera;
  if (cam != NULL) {
    cam->unk_1c = 1;
    if (n < 2) {
      cam->lookMode = 0;
    } else {
      cam->lookTimer = n;
      cam->lookMode = 5;
    }
    gCamera->unk_1e = 0;
  }
}

void FUN_0823bca8(s32 n) {
  Camera* cam;

  cam = gCamera;
  if (cam != NULL) {
    if (n < 2) {
      cam->unk_1c = 0;
    } else {
      cam->unk_1c = 1;
      cam->lookMode = 6;
      cam->lookTimer = n;
    }
    gCamera->unk_1e = 0;
  }
}

// Unused?
void FUN_0823bce4(Vec3* pos, s32* enabled) {
  Camera* cam;

  cam = gCamera;
  if (cam != NULL) {
    cam->targetPos = pos;
    cam->unk_a0 = enabled;
    cam->unk_1c = 1;
    cam->lookMode = 7;
    cam->unk_1e = 0;
  }
}

NON_MATCH void FUN_0823bd14(u32 amplitude, u32 frames, s32 stopOnEnd) {
#ifdef NONMATCHING_C
  if (gCamera != NULL && (gFlag030047a4 & FLAG030047A4_UNK_11) == 0) {
    if (frames == 0 && stopOnEnd == 1) {
      gCamera->shakeActive = 0;
      gCamera->shakeStopOnEnd = 0;
      gCamera->shakeCurrent = 0;
      gCamera->shakeTarget = 0;
    } else {
      gCamera->shakeActive = 1;
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
  s32 type;
  s32 val;

  if (cam != NULL) {
    cam->unk_1e = 1;
    if (VM_SeekToKeyword('e')) {
      VM_DecodeValue(VM_GetPC(), &type, &val);
      cam->scriptID = val;
      cam->unk_96 = 0;
    } else if (VM_SeekToKeyword('R')) {
      cam->scriptID = Script_GetValue();
      cam->unk_96 = 1;
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
  Vec3 pos;

  if (VM_SeekToKeyword('p')) {
    pos.x = Script_GetValue();
    pos.y = Script_GetValue();
    pos.z = Script_GetValue();
    FUN_0823bac8(&pos);
    FUN_0823bd98(gCamera);
  }
}

void Camera_PanTo(void) {
  Vec3 pos;
  s32 n;

  if (VM_SeekToKeyword('f')) {
    n = Script_GetValue();
    if (VM_SeekToKeyword('p')) {
      pos.x = Script_GetValue();
      pos.y = Script_GetValue();
      pos.z = Script_GetValue();
      FUN_0823bb7c(n, &pos);
      FUN_0823bd98(gCamera);
    }
  }
}

void FUN_0823bee8(void) {
  Vec3 pos;
  s32 targetID;

  if (VM_SeekToKeyword('n')) {
    targetID = Script_GetValue();
    if (VM_SeekToKeyword('o')) {
      pos.x = Script_GetValue();
      pos.y = Script_GetValue();
      pos.z = Script_GetValue();
    } else {
      pos.x = 0;
      pos.y = 0;
      pos.z = 0;
    }
    FUN_0823bbd4(targetID, &pos);
    FUN_0823bd98(gCamera);
  }
}

void FUN_0823bf70(void) {
  Vec3 pos;
  s32 n;
  s32 targetID;

  if (VM_SeekToKeyword('f')) {
    n = Script_GetValue();
    if (VM_SeekToKeyword('n')) {
      targetID = Script_GetValue();
      if (VM_SeekToKeyword('o')) {
        pos.x = Script_GetValue();
        pos.y = Script_GetValue();
        pos.z = Script_GetValue();
      } else {
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
      }
      FUN_0823bc14(targetID, n, &pos);
      FUN_0823bd98(gCamera);
    }
  }
}

void FUN_0823c008(void) {
  if (VM_SeekToKeyword('f')) {
    FUN_0823bc70(Script_GetValue());
    FUN_0823bd98(gCamera);
  }
}

void Camera_Reset(void) {
  if (VM_SeekToKeyword('f')) {
    FUN_0823bca8(Script_GetValue());
    FUN_0823bd98(gCamera);
  }
}

void FUN_0823c050(void) {
  s32 amplitude;
  s32 frames;
  s32 stopOnEnd;

  if (VM_SeekToKeyword('w')) {
    amplitude = Script_GetValue();
    if (VM_SeekToKeyword('f')) {
      frames = Script_GetValue();
    } else {
      frames = 1;
    }
    if (VM_SeekToKeyword('N')) {
      stopOnEnd = Script_GetValue();
    } else {
      stopOnEnd = 0;
    }
    FUN_0823bd14(amplitude, frames, stopOnEnd);
    FUN_0823bd98(gCamera);
  }
}

void FUN_0823c0a4(Camera* cam) { cam->unk_1e = 2; }

void FUN_0823c0ac(Camera* cam) { EntityMsgBox_EndWait(&cam->unk_20, 1); }

NAKED void FUN_0823c0bc(Camera* cam) { INCFUNC("asm/func/FUN_0823c0bc.inc"); }

void FUN_0823c1f8(Camera* cam) {
  s32 scriptID;

  scriptID = cam->scriptID;
  if (scriptID != 0) {
    if (cam->unk_96 == 0) {
      cam->scriptID = 0;
      Script_ExecByPointer((u8*)scriptID, NULL);
    } else {
      cam->scriptID = 0;
      Script_ExecById(scriptID, NULL);
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
  Camera* cam;

  cam = gCamera;
  if (cam != NULL) {
    cam->unk_8e = min->x - (min->y >> 1);
    cam->unk_90 = min->z - (min->y >> 1);
    cam->unk_92 = max->x - (max->y >> 1);
    cam->unk_94 = max->z - (max->y >> 1);
    cam->unk_8c = 1;
    Camera_ApplyBounds(cam, &gCameraCoords.worldPos);
  }
}

void Camera_ConnectToTilemap(void) {
  Vec3 min;
  Vec3 max;

  if (VM_SeekToKeyword('I')) {
    min.x = Script_GetValue();
    min.y = Script_GetValue();
    min.z = Script_GetValue();
    if (VM_SeekToKeyword('A')) {
      max.x = Script_GetValue();
      max.y = Script_GetValue();
      max.z = Script_GetValue();
      FUN_0823c260(&min, &max);
    }
  }
}

void FUN_0823c35c(Vec3* min, Vec3* max) {
  Camera* cam;

  cam = gCamera;
  if (cam != NULL) {
    cam->unk_8e = min->z - min->x;
    cam->unk_90 = min->z + min->x - min->y;
    cam->unk_92 = max->z - max->x;
    cam->unk_94 = max->z + max->x - max->y;
    cam->unk_8c = 2;
    Camera_ApplyBounds(cam, &gCameraCoords.worldPos);
  }
}

void Camera_SetBoundsType2Scripted(void) {
  Vec3 min;
  Vec3 max;

  if (VM_SeekToKeyword('I')) {
    min.x = Script_GetValue();
    min.y = Script_GetValue();
    min.z = Script_GetValue();
    if (VM_SeekToKeyword('A')) {
      max.x = Script_GetValue();
      max.y = Script_GetValue();
      max.z = Script_GetValue();
      FUN_0823c35c(&min, &max);
    }
  }
}

NAKED void FUN_0823c450(Camera* cam) { INCFUNC("asm/func/FUN_0823c450.inc"); }

NAKED void FUN_0823c620(Camera* cam) { INCFUNC("asm/func/FUN_0823c620.inc"); }

// 画面揺れを1フレーム進め、worldPos に揺れのオフセットを足す
NON_MATCH void* FUN_0823c928(Camera* cam) {
#ifdef NONMATCHING_C
  s32 v;

  if (cam->shakeActive != 0) {
    if (cam->shakeTimer != 0) {
      v = Div(cam->shakeTimer * cam->shakeCurrent + cam->shakeTarget, cam->shakeTimer + 1);
      cam->shakeCurrent = v;
      cam->shakeAmplitude = v;
      if (--cam->shakeTimer == 0) {
        if (cam->shakeStopOnEnd != 0) {
          cam->shakeActive = 0;
          cam->shakeStopOnEnd = 0;
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
  if ((gFlag030047a4 & FLAG030047A4_UNK_11) == 0) {
    EntityMsgBus_Unregister(&cam->unk_20);
  }
  gCamera = NULL;
  return 0;
}

NAKED s32 Camera_Init(Camera* cam, u32 val) { INCFUNC("asm/func/Camera_Init.inc"); }

Camera* Camera_Create(u32 val) {
  Camera* cam;
  if (gCamera == NULL) {
    cam = CreateEntity(ENTITY_CAMERA, sizeof(Camera));
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
