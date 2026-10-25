#include "camera.h"

#include "collision_map.h"
#include "entity_9a9f.h"
#include "file.h"
#include "global.h"
#include "mover.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "registry.h"
#include "video.h"
#include "vm.h"

// Camera.moveMode
typedef enum {
  FOLLOW_PLAYER = 0,          // プレイヤー追従
  TO_DEST_IMMEDIATE = 1,      // destPos へ即座に移動
  TO_DEST_INTERPOLATE = 2,    // destPos へ moveTimer フレームかけて補間
  TO_PLAYER_INTERPOLATE = 3,  // player へ moveTimer フレームかけて補間
} CameraMoveMode;

typedef struct {
  Entity e;              // 0x00, ENTITY_CAMERA
  u32 id;                // 0x18, メッセージキューの送信先IDとして利用
  bool16 lookEnabled;    // 0x1C, 0 なら Camera_Update が pos をそのまま注視点にする, 1 なら lookMode に従って Camera_StepLook が決める
  u16 completeAction;    // 0x1E, 移動/注視が終わったときの後始末 (0: なし, 1: scriptID を実行, 2: メッセージの待ちを解除), 根拠: Camera_RunCompleteAction
  MsgQueue mq;           // 0x20
  u16 moveMode;          // 0x54, see CameraMoveMode
  u16 moveTimer;         // 0x56, pos を destPos へ寄せる補間の残りフレーム数, 根拠: Camera_StepMove が Div の除数に使い毎フレーム減算する
  Vec3 pos;              // 0x58, カメラ自身の現在位置, 根拠: Camera_Update が gCameraWorldCoords にそのまま代入し、Camera_Init が gStat->playerPos から初期化する
  Vec3 destPos;          // 0x60, 移動先の座標, 根拠: Camera_MoveTo / FUN_0823b980 が外部から書き、Camera_StepMove が pos をここへ寄せる
  u16 lookMode;          // 0x68, 注視点の決め方 (0-7), 根拠: Camera_StepLook の switch 対象
  u16 lookTimer;         // 0x6A, 注視点補間の残りフレーム数, 根拠: Camera_StepLook が Div の除数に使い毎フレーム減算する
  Vec3 pos_6c;           // 0x6C, lookMode が 1/2 のときの注視点
  Vec3 pos_74;           // 0x74, lookMode が 3/4 のときの注視対象からのオフセット
  u16 lookTargetID;      // 0x7C, 注視対象の ID, 根拠: Camera_StepLook が Mover_FindByID_Proxy(lookTargetID) に渡して Mover* を得る
  u16 shakeAmplitude;    // 0x7E, 今フレームの画面揺れの振幅, 根拠: Camera_StepShake が shakeCurrent から取って毎回0に戻す
  s16 shakeOffsetX;      // 0x80, 画面揺れの X オフセット, 根拠: Camera_StepShake が gCameraWorldCoords.x に加算する
  s16 shakeOffsetZ;      // 0x82, 画面揺れの Z オフセット, 根拠: Camera_StepShake が gCameraWorldCoords.z に加算する
  bool8 shakeActive;     // 0x84, 0以外なら画面揺れ中, 根拠: FUN_0823bd14 が開始で1/停止で0を書く
  bool8 shakeStopOnEnd;  // 0x85, 0以外なら shakeTimer が尽きた時に揺れを完全に止める, 0なら shakeTarget のまま揺れ続ける
  u16 shakeCurrent;      // 0x86, 現在の振幅, 根拠: Camera_StepShake が shakeTarget へ向けて Div で補間する
  u16 shakeTarget;       // 0x88, 目標の振幅, 根拠: FUN_0823bd14 の第1引数
  u16 shakeTimer;        // 0x8A, 揺れの残りフレーム数, 根拠: FUN_0823bd14 の第2引数を Camera_StepShake が減算する
  u16 unk_8c;            // 0x8C
  s16 unk_8e;            // 0x8E
  s16 unk_90;            // 0x90
  s16 unk_92;            // 0x92
  s16 unk_94;            // 0x94
  u16 scriptIDType;      // 0x96, scriptID の型 を示す, 0 ならポインタ、 それ以外なら ID(数値)
  s32 scriptID;          // 0x98, scriptIDType が 0 ならポインタ(u8*)、それ以外なら ID(数値)
  Vec3* targetPos;       // 0x9C, lookMode が 7 のときの注視点, 根拠: Camera_StepLook が指す先から8バイトを gCameraWorldCoords へコピーする
  s32* unk_a0;           // 0xA0, 0以外を指している間だけ targetPos が使われる, 根拠: Camera_StepLook
} Camera;
static_assert(sizeof(Camera) == 164);

// CollisionMapFile が圧縮されている場合、ここに展開してファイル内容を読み込む, 圧縮されていないならROMから直接読み込むのでここは使われない
EWRAM_DATA u8 gDecompressedCollisionMapHeader[4] = {};    // 0x02031400, 展開先の先頭4バイト, 圧縮処理のメタデータが格納されるが使われてなさそう
EWRAM_DATA u8 gDecompressedCollisionMapFile[16380] = {};  // 0x02031404, 展開された CollisionMapFile 本体, 根拠: OpenCollisionMapFile がここを返す

COMMON_DATA Vec3 gCameraVpCoords = {};  // 0x030047C8
COMMON_DATA Camera* gCamera = NULL;     // 0x030047D0
COMMON_DATA u8 u8_030047d4[4] = {};     // todo
COMMON_DATA u16 u16_030047d8 = 0;       // 0x030047D8, TextRenderer_PlayCharSound がこのIDのメッセージでは音を鳴らさない
COMMON_DATA u8 u8_030047da[6] = {};     // todo

s32 Map_LoadTileData(FileID id);
s32 Map_LoadZones(FileID id);
s32 Map_LoadPaths(FileID id);
s32 Map_LoadNavMesh(FileID id);
void Map_SetTileData(CollisionMapTileData* tiledata);
void Map_SetZones(ZoneData* zones);
void Map_SetPaths(PathData* paths);
void Map_SetNavMesh(NavMesh* navMesh);

// ワールド座標をアイソメトリック投影して視点座標にする
static inline void WorldToVp(Vec3* vp, WorldPos* world) {
  s32 hx = world->x >> 1;
  s32 hz = world->z >> 1;
  s32 a, b;

  vp->x = FixToInt(8, (hx - hz) * 48);
  a = FixToInt(8, (hx + hz) * 48);
  b = FixToInt(8, world->y * 24);
  vp->y = a - b;
  vp->z = a + b;
}

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
  hdr.tileData.offset += (u32)f;
  hdr.zones.offset += (u32)f;
  hdr.paths.offset += (u32)f;
  if (hdr.navMesh.offset != 0) {
    hdr.navMesh.offset += (u32)f;
  }

  Map_SetTileData(hdr.tileData.ptr);
  Map_SetZones(hdr.zones.ptr);
  Map_SetPaths(hdr.paths.ptr);
  Map_SetNavMesh(hdr.navMesh.ptr);
  return 0;
}

// 0x30AD, このゲームでは、 '.n' と '.p' 以外の引数は渡していない
void Map_LoadMapScripted(void) {
  CollisionMapData* cm;
  CollisionMapTileData* td;

  s32 n = VM_GetNamedArgValue('n', 0);  // n は 使わない
  s32 h = VM_GetNamedArgValue('h', 0);  // このゲームではこの引数を渡しているものはない (なので 0)
  s32 t = VM_GetNamedArgValue('t', 0);  // このゲームではこの引数を渡しているものはない (なので 0)
  s32 r = VM_GetNamedArgValue('r', 0);  // このゲームではこの引数を渡しているものはない (なので 0)
  s32 z = VM_GetNamedArgValue('z', 0);  // このゲームではこの引数を渡しているものはない (なので 0)

  s32 fileID = VM_GetNamedArgValue('p', 0);
  if (fileID != 0) {
    Map_LoadCollisionMapFile(fileID);
  } else {
    // '.h', '.t', '.r', '.z' はこのゲーム内の利用箇所で全て 0 なのでこれらは実行されることはない
    if (h != 0) Map_LoadTileData(h);
    if (t != 0) Map_LoadZones(t);
    if (r != 0) Map_LoadPaths(r);
    if (z != 0) Map_LoadNavMesh(z);
  }

  // これ以降が Camera_SetTilemapOffset と同じ処理になる
  cm = Registry_Find(0x56C2);
  td = cm->tiledata;
  if (VM_SeekToNamedArg('v')) {  // このゲームではこの引数を渡しているものはないので、これ以降は実行されない
    s32 val = VM_GetValue();
    if (val == 0) {
      Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
      gCameraCoords.tilemapX = td->tilemapOffsetX >> 4;
      gCameraCoords.tilemapY = td->tilemapOffsetY >> 4;
    } else {
      Video_SetDrawPasses(val, Particle_DrawListScreen, AuxSprite_DrawListScreen, MainSprite_DrawListScreen);
      gCameraCoords.tilemapX = 0;
      gCameraCoords.tilemapY = 0;
    }
  }
}

// 0x7539
void Camera_SetTilemapOffset(void) {
  s32 val = VM_GetNamedArgValue('v', 0);
  if (val == 0) {
    CollisionMapData* p = Registry_Find(0x56C2);
    Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
    if (p != NULL) {
      if (p->tiledata != NULL) {
        gCameraCoords.tilemapX = p->tiledata->tilemapOffsetX >> 4;
        gCameraCoords.tilemapY = p->tiledata->tilemapOffsetY >> 4;
        return;
      }
    }
  } else {
    Video_SetDrawPasses(val, Particle_DrawListScreen, AuxSprite_DrawListScreen, MainSprite_DrawListScreen);
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
    gCamera->moveMode = FOLLOW_PLAYER;
  }
}

void FUN_0823b880(s32 n) {
  if (gCamera != NULL) {
    if (n < 2) {
      gCamera->moveMode = FOLLOW_PLAYER;
    } else {
      gCamera->moveTimer = n;
      gCamera->moveMode = TO_PLAYER_INTERPOLATE;
    }
  }
}

// 移動先を指定して即座に移動させる, 補間中でなければその場で投影までやりなおす
void Camera_MoveTo(Vec3* pos) {
  if (gCamera != NULL) {
    VEC3_SET(gCamera->destPos, pos->x, pos->y, pos->z);
    Camera_ApplyBounds(gCamera, &gCamera->destPos);
    gCamera->moveMode = TO_DEST_IMMEDIATE;
    if (!gCamera->lookEnabled) {
      gCameraCoords.worldPos.x = gCamera->destPos.x + gCamera->shakeOffsetX;
      gCameraCoords.worldPos.y = gCamera->destPos.y;
      gCameraCoords.worldPos.z = gCamera->destPos.z + gCamera->shakeOffsetZ;
      WorldToVp(&gCameraVpCoords, &gCameraCoords.worldPos);
    }
  }
}

void FUN_0823b980(s32 n, Vec3* pos) {
  if (gCamera != NULL) {
    VEC3_SET(gCamera->destPos, pos->x, pos->y, pos->z);
    if (n < 2) {
      gCamera->moveMode = TO_DEST_IMMEDIATE;
    } else {
      gCamera->moveTimer = n;
      gCamera->moveMode = TO_DEST_INTERPOLATE;
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
    gCamera->lookEnabled = TRUE;
    gCamera->lookMode = 0;
    gCamera->completeAction = 0;
  }
}

// 注視点を指定座標に固定して, すぐに投影しなおす
void Camera_LookAt(Vec3* pos) {
  if (gCamera != NULL) {
    VEC3_SET(gCamera->pos_6c, pos->x, pos->y, pos->z);
    VEC3_SET(gCameraCoords.worldPos, gCamera->pos_6c.x, gCamera->pos_6c.y, gCamera->pos_6c.z);
    WorldToVp(&gCameraVpCoords, &gCameraCoords.worldPos);
    gCamera->lookEnabled = TRUE;
    gCamera->lookMode = 1;
    gCamera->completeAction = 0;
  }
}

void FUN_0823bb7c(s32 n, Vec3* pos) {
  if (gCamera != NULL) {
    VEC3_SET(gCamera->pos_6c, pos->x, pos->y, pos->z);
    gCamera->lookEnabled = TRUE;
    if (n < 2) {
      gCamera->lookMode = 1;
    } else {
      gCamera->lookTimer = n;
      gCamera->lookMode = 2;
    }
    gCamera->completeAction = 0;
  }
}

void FUN_0823bbd4(u32 targetID, Vec3* pos) {
  if (gCamera != NULL) {
    gCamera->lookTargetID = targetID;
    if (Mover_FindByID_Proxy(gCamera->lookTargetID) != NULL) {
      gCamera->lookEnabled = TRUE;
      gCamera->pos_74 = *pos;
      gCamera->lookMode = 3;
      gCamera->completeAction = 0;
    }
  }
}

void FUN_0823bc14(u32 targetID, s32 n, Vec3* pos) {
  if (gCamera != NULL) {
    gCamera->lookTargetID = targetID;
    if (Mover_FindByID_Proxy(gCamera->lookTargetID) != NULL) {
      gCamera->lookEnabled = TRUE;
      gCamera->pos_74 = *pos;
      if (n < 2) {
        gCamera->lookMode = 3;
      } else {
        gCamera->lookTimer = n;
        gCamera->lookMode = 4;
      }
      gCamera->completeAction = 0;
    }
  }
}

void FUN_0823bc70(s32 n) {
  if (gCamera != NULL) {
    gCamera->lookEnabled = TRUE;
    if (n < 2) {
      gCamera->lookMode = 0;
    } else {
      gCamera->lookTimer = n;
      gCamera->lookMode = 5;
    }
    gCamera->completeAction = 0;
  }
}

void FUN_0823bca8(s32 n) {
  if (gCamera != NULL) {
    if (n < 2) {
      gCamera->lookEnabled = FALSE;
    } else {
      gCamera->lookEnabled = TRUE;
      gCamera->lookMode = 6;
      gCamera->lookTimer = n;
    }
    gCamera->completeAction = 0;
  }
}

// Unused?
void FUN_0823bce4(Vec3* pos, s32* enabled) {
  if (gCamera != NULL) {
    gCamera->targetPos = pos;
    gCamera->unk_a0 = enabled;
    gCamera->lookEnabled = TRUE;
    gCamera->lookMode = 7;
    gCamera->completeAction = 0;
  }
}

// 画面ゆれを開始する, frames が 0 で stopOnEnd が 1 のときは即座に止める
// 残差0命令 (60/60), レジスタ名だけ違う: 原典は frames を r3, gCamera を r2, &gCamera を r4 に割り当てるが, こちらは &gCamera が r2 を取る
// Tier A-C は試済: 早期 return 形, shakeTimer 経由の 0 判定 (これで命令数は一致した)
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
      if (gCamera->shakeTimer == 0) {
        gCamera->shakeCurrent = gCamera->shakeTarget;
      }
      gCamera->shakeStopOnEnd = stopOnEnd;
    }
    gCamera->completeAction = 0;
  }
#else
  INCFUNC("asm/func/FUN_0823bd14.inc");
#endif
}

void FUN_0823bd98(Camera* cam) {
  if (cam != NULL) {
    cam->completeAction = 1;
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
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    Camera_LookAt(&pos);
    FUN_0823bd98(gCamera);
  }
}

void Cmd_CameraPanTo(void) {
  if (VM_SeekToNamedArg('f')) {
    Vec3 pos;
    s32 n = VM_GetValue();
    if (VM_SeekToNamedArg('p')) {
      VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
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
      VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    } else {
      VEC3_SET(pos, 0, 0, 0);
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
        VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
      } else {
        VEC3_SET(pos, 0, 0, 0);
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

void FUN_0823c0a4(Camera* cam) { cam->completeAction = 2; }

void FUN_0823c0ac(Camera* cam) { MsgQueue_EndWait(&cam->mq, 1); }

// 溜まったメッセージを受け取り, 注視点・移動・画面ゆれの指示を振り分ける
// 残差2命令 (114/117): 原典は gMsgBus のプール定数を r0 に載せてループ内で読み直すが, こちらは cam が r0 に残るぶん r2 に載って使い回される
// Tier A-C は試済: mq ローカルの有無/宣言順, bus ローカルの追加, 条件式のベースを cam->mq にする形
NON_MATCH void Camera_PollMessages(Camera* cam) {
#ifdef NONMATCHING_C
  MsgQueue* mq = &cam->mq;
  s32 i;

  for (i = 0; i < mq->count[gMsgBus->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[gMsgBus->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    switch (msg->cmd) {
      case 0: {
        FUN_0823baa8();
        FUN_0823c0a4(cam);
        FUN_0823c0ac(cam);
        break;
      }
      case 1: {
        Vec3 pos;
        pos.x = msg->args[0];
        pos.y = msg->args[1];
        pos.z = msg->args[2];
        Camera_LookAt(&pos);
        FUN_0823c0a4(cam);
        FUN_0823c0ac(cam);
        break;
      }
      case 2: {
        Vec3 pos;
        pos.x = msg->args[0];
        pos.y = msg->args[1];
        pos.z = msg->args[2];
        FUN_0823bb7c(msg->args[3], &pos);
        FUN_0823c0a4(cam);
        break;
      }
      case 3: {
        FUN_0823bc70(msg->args[0]);
        FUN_0823c0a4(cam);
        break;
      }
      case 4: {
        FUN_0823bd14(msg->args[0], msg->args[1], msg->args[2]);
        FUN_0823c0a4(cam);
        break;
      }
      case 5: {
        FUN_0823bca8(msg->args[0]);
        FUN_0823c0a4(cam);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/Camera_PollMessages.inc");
#endif
}

void Camera_RunScript(Camera* cam) {
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

void Camera_RunCompleteAction(Camera* cam) {
  if (cam->completeAction == 1) {
    Camera_RunScript(cam);
  } else if (cam->completeAction == 2) {
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
    VEC3_SET(min, VM_GetValue(), VM_GetValue(), VM_GetValue());
    if (VM_SeekToNamedArg('A')) {
      VEC3_SET(max, VM_GetValue(), VM_GetValue(), VM_GetValue());
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
    VEC3_SET(min, VM_GetValue(), VM_GetValue(), VM_GetValue());
    if (VM_SeekToNamedArg('A')) {
      VEC3_SET(max, VM_GetValue(), VM_GetValue(), VM_GetValue());
      FUN_0823c35c(&min, &max);
    }
  }
}

// moveMode に従ってカメラ自身の位置を1フレーム分進める
void Camera_StepMove(Camera* cam) {
  switch (cam->moveMode) {
    case FOLLOW_PLAYER: {
      if (gFlag030047a4 & FLAG030047A4_LINK) {
        if (gEntity9A9F != NULL) {
          s32 idx = gEntity9A9F->playerIdx;

          if (idx >= 0 && gPlayerPtr[idx] != NULL) {
            cam->pos.x = gPlayerPtr[idx]->mover.pos.x;
            cam->pos.y = gPlayerPtr[idx]->mover.pos.y + 0x96;
            cam->pos.z = gPlayerPtr[idx]->mover.pos.z;
          }
        }
      } else if (!gCameraCoords.drawMode) {
        // DRAW_ISOMETRIC
        cam->pos.x = gStat->playerX;
        cam->pos.y = gStat->playerY + 0x96;
        cam->pos.z = gStat->playerZ;
      } else {
        // DRAW_SCREEN
        cam->pos.x = gStat->playerX;
        cam->pos.y = gStat->playerY - 0x96;
        cam->pos.z = gStat->playerZ;
      }
      break;
    }
    case TO_DEST_IMMEDIATE: {
      VEC3_SET(cam->pos, cam->destPos.x, cam->destPos.y, cam->destPos.z);
      break;
    }
    case TO_DEST_INTERPOLATE: {
      cam->pos.x = Div(cam->pos.x * (cam->moveTimer - 1) + cam->destPos.x, cam->moveTimer);
      cam->pos.y = Div(cam->pos.y * (cam->moveTimer - 1) + cam->destPos.y, cam->moveTimer);
      cam->pos.z = Div(cam->pos.z * (cam->moveTimer - 1) + cam->destPos.z, cam->moveTimer);
      cam->moveTimer--;
      if (cam->moveTimer <= 1) {
        cam->moveMode = 1;
      }
      break;
    }
    case TO_PLAYER_INTERPOLATE: {
      cam->pos.x = Div(cam->pos.x * (cam->moveTimer - 1) + gStat->playerX, cam->moveTimer);
      cam->pos.y = Div(cam->pos.y * (cam->moveTimer - 1) + gStat->playerY + 0x96, cam->moveTimer);
      cam->pos.z = Div(cam->pos.z * (cam->moveTimer - 1) + gStat->playerZ, cam->moveTimer);
      cam->moveTimer--;
      if (cam->moveTimer <= 1) {
        cam->moveMode = 0;
      }
      break;
    }
  }
}

// lookMode に従って注視点 (gCameraCoords.worldPos) を1フレーム分進める
void Camera_StepLook(Camera* cam) {
  Mover* target;

  switch (cam->lookMode) {
    case 0: {
      if (!gCameraCoords.drawMode) {
        // DRAW_ISOMETRIC
        gCameraCoords.worldPos.x = gStat->playerX;
        gCameraCoords.worldPos.y = gStat->playerY + 0x96;
        gCameraCoords.worldPos.z = gStat->playerZ;
      } else {
        // DRAW_SCREEN
        gCameraCoords.worldPos.x = gStat->playerX;
        gCameraCoords.worldPos.y = gStat->playerY - 0x96;
        gCameraCoords.worldPos.z = gStat->playerZ;
      }
      break;
    }
    case 1: {
      VEC3_SET(gCameraCoords.worldPos, cam->pos_6c.x, cam->pos_6c.y, cam->pos_6c.z);
      break;
    }
    case 2: {
      gCameraCoords.worldPos.x = Div(gCameraCoords.worldPos.x * (cam->lookTimer - 1) + cam->pos_6c.x, cam->lookTimer);
      gCameraCoords.worldPos.y = Div(gCameraCoords.worldPos.y * (cam->lookTimer - 1) + cam->pos_6c.y, cam->lookTimer);
      gCameraCoords.worldPos.z = Div(gCameraCoords.worldPos.z * (cam->lookTimer - 1) + cam->pos_6c.z, cam->lookTimer);
      cam->lookTimer--;
      if (cam->lookTimer <= 1) {
        cam->lookMode = 1;
        Camera_RunCompleteAction(cam);
      }
      break;
    }
    case 3: {
      target = Mover_FindByID_Proxy(cam->lookTargetID);
      if (target != NULL) {
        gCameraCoords.worldPos.x = target->pos.x + cam->pos_74.x;
        gCameraCoords.worldPos.y = target->pos.y + cam->pos_74.y;
        gCameraCoords.worldPos.z = target->pos.z + cam->pos_74.z;
      }
      break;
    }
    case 4: {
      target = Mover_FindByID_Proxy(cam->lookTargetID);
      if (target != NULL) {
        gCameraCoords.worldPos.x = Div(gCameraCoords.worldPos.x * (cam->lookTimer - 1) + (target->pos.x + cam->pos_74.x), cam->lookTimer);
        gCameraCoords.worldPos.y = Div(gCameraCoords.worldPos.y * (cam->lookTimer - 1) + (target->pos.y + cam->pos_74.y), cam->lookTimer);
        gCameraCoords.worldPos.z = Div(gCameraCoords.worldPos.z * (cam->lookTimer - 1) + (target->pos.z + cam->pos_74.z), cam->lookTimer);
        cam->lookTimer--;
        if (cam->lookTimer <= 1) {
          cam->lookMode = 3;
          Camera_RunCompleteAction(cam);
        }
      }
      break;
    }
    case 5: {
      gCameraCoords.worldPos.x = Div(gCameraCoords.worldPos.x * (cam->lookTimer - 1) + gStat->playerX, cam->lookTimer);
      gCameraCoords.worldPos.y = Div(gCameraCoords.worldPos.y * (cam->lookTimer - 1) + gStat->playerY + 0x96, cam->lookTimer);
      gCameraCoords.worldPos.z = Div(gCameraCoords.worldPos.z * (cam->lookTimer - 1) + gStat->playerZ, cam->lookTimer);
      cam->lookTimer--;
      if (cam->lookTimer <= 1) {
        cam->lookMode = 0;
        Camera_RunCompleteAction(cam);
      }
      break;
    }
    case 6: {
      gCameraCoords.worldPos.x = Div(gCameraCoords.worldPos.x * (cam->lookTimer - 1) + cam->pos.x, cam->lookTimer);
      gCameraCoords.worldPos.y = Div(gCameraCoords.worldPos.y * (cam->lookTimer - 1) + cam->pos.y, cam->lookTimer);
      gCameraCoords.worldPos.z = Div(gCameraCoords.worldPos.z * (cam->lookTimer - 1) + cam->pos.z, cam->lookTimer);
      cam->lookTimer--;
      if (cam->lookTimer <= 1) {
        cam->lookEnabled = FALSE;
        Camera_RunCompleteAction(cam);
      }
      break;
    }
    case 7: {
      if (*cam->unk_a0 != 0) {
        gCameraCoords.worldPos = *cam->targetPos;
      }
      break;
    }
  }
}

// 画面揺れを1フレーム進め、worldPos に揺れのオフセットを足す
// 画面ゆれを1フレーム分進め, 振幅ぶんの乱数オフセットをカメラ座標に反映する
// 残差2命令 (131/129): 原典は gRandomTable のアドレスを r8 に巻き上げて 2回の Random() で共有するが, こちらは r8 が &shakeOffsetX に取られてテーブルを毎回ロードしなおす
NON_MATCH void* Camera_StepShake(Camera* cam) {
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
        Camera_RunCompleteAction(cam);
      }
    } else {
      cam->shakeAmplitude = cam->shakeCurrent;
    }
  }
  if (cam->shakeAmplitude != 0) {
    cam->shakeOffsetX = ModArm(cam->shakeAmplitude, Random()) - (cam->shakeAmplitude >> 1);
    cam->shakeOffsetZ = ModArm(cam->shakeAmplitude, Random()) - (cam->shakeAmplitude >> 1);
    gCameraCoords.worldPos.x += cam->shakeOffsetX;
    gCameraCoords.worldPos.z += cam->shakeOffsetZ;
    cam->shakeAmplitude = 0;
  } else {
    cam->shakeOffsetX = 0;
    cam->shakeOffsetZ = 0;
  }
#else
  INCFUNC("asm/func/Camera_StepShake.inc");
#endif
}

s32 Camera_Update(Camera* cam) {
  if (!(gFlag030047a4 & FLAG030047A4_LINK)) {
    Camera_PollMessages(cam);
  }

  if (!(gEntityDisableFlags & ENTITY_DISABLE_2)) {
    Camera_StepMove(cam);
    if (!cam->lookEnabled) {
      VEC3_SET(gCameraCoords.worldPos, cam->pos.x, cam->pos.y, cam->pos.z);
    } else {
      Camera_StepLook(cam);
    }
    Camera_StepShake(cam);
    Camera_ApplyBounds(cam, &gCameraCoords.worldPos);
  }
  WorldToVp(&gCameraVpCoords, &gCameraCoords.worldPos);
  return 0;
}

s32 Camera_Destroy(Camera* cam) {
  if (!(gFlag030047a4 & FLAG030047A4_LINK)) {
    MsgQueue_Unregister(&cam->mq);
  }
  gCamera = NULL;
  return 0;
}

s32 Camera_Init(Camera* cam, u32 id) {
  cam->id = id;
  cam->lookEnabled = FALSE;
  cam->moveMode = 0;
  cam->pos.x = gStat->playerX;
  cam->pos.y = gStat->playerY + 0x96;
  cam->pos.z = gStat->playerZ;
  cam->unk_8c = 0;
  VEC3_SET(gCameraCoords.worldPos, cam->pos.x, cam->pos.y, cam->pos.z);
  WorldToVp(&gCameraVpCoords, &gCameraCoords.worldPos);
  cam->shakeActive = FALSE;
  cam->shakeStopOnEnd = FALSE;
  cam->shakeCurrent = 0;
  cam->shakeTarget = 0;
  cam->shakeAmplitude = 0;
  cam->shakeOffsetX = 0;
  cam->shakeOffsetZ = 0;
  cam->scriptID = 0;
  WorldToVp(&gCameraVpCoords, &gCameraCoords.worldPos);
  if (!(gFlag030047a4 & FLAG030047A4_LINK)) {
    MsgQueue_Register(&cam->mq, cam->id, 6);
  }
  gCamera = cam;
  return 0;
}

// 0xC0B0
Camera* Camera_Create(u32 id) {
  if (gCamera == NULL) {
    Camera* cam = CreateEntity(ENTITY_CAMERA, sizeof(Camera));
    if (cam != NULL) {
      SetEntityRoutine(cam, Camera_Update, Camera_Destroy);
      if (Camera_Init(cam, id) < 0) {
        KillEntity((Entity*)cam);
        return NULL;
      }
    }
    return cam;
  }
  return gCamera;
}
