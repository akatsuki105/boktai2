#ifndef __INCLUDE_CAMERA_H__
#define __INCLUDE_CAMERA_H__

#include "entity.h"
#include "gba/gba.h"
#include "msgbus.h"
#include "types.h"

// CameraCoords.drawMode, Video_SetDrawPasses が描画パス3本とまとめて差し替える
#define DRAW_ISOMETRIC 0  // アイソメのワールド空間
#define DRAW_SCREEN 1     // スクリーン空間

// 0x03003540 から 0x03003554 の手前までが1つの構造体
// 根拠: Video_Reset / Camera_SetTilemapOffset / Map_LoadMapScripted / Video_SetDrawPasses がいずれも 0x03003540 を単一のプール定数から読み、そこからのオフセットで書く
// 上限の根拠: Video_SetDrawPasses は同一関数内で 0x03003554 / 0x03003534 / 0x03003558 をそれぞれ別のプール定数から読んでいる
typedef struct {
  WorldPos worldPos;  // 0x00, カメラの注視点のワールド座標, 根拠: Video_Reset が +0/+2/+4 をクリアする
  s16 tilemapX;       // 0x08, 根拠: Camera_SetTilemapOffset が strh [r1,#0x8] で書く
  s16 tilemapY;       // 0x0A, 根拠: 同上 strh [r1,#0xa]
  s16 unk_0c;         // 0x0C, Video_Reset が 1 を書く, 読み手は未特定
  s16 unk_0e;         // 0x0E, 参照が見つかっていない (幅も未確定)
  s16 unk_10;         // 0x10, Video_Reset が 0 を書く, 読み手は未特定
  s16 drawMode;       // 0x12, 0 ならアイソメのワールド空間, 1 ならスクリーン空間, Video_SetDrawPasses が描画パス3本とまとめて差し替える
} CameraCoords;
static_assert(sizeof(CameraCoords) == 20);

extern CameraCoords gCameraCoords;  // 0x03003540
extern Vec3 gCameraVpCoords;        // 0x030047C8

void Camera_0823b744(void);
void Camera_MoveTo(Vec3* pos);
void Camera_Shake(s32 n);
void FUN_0823bca8(s32 n);

#endif  // __INCLUDE_CAMERA_H__
