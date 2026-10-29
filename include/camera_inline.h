#ifndef __INCLUDE_CAMERA_INLINE_H__
#define __INCLUDE_CAMERA_INLINE_H__

// グローバル変数を参照する static inline は、 include したファイルのコンパイル結果に影響を与えることがある (たとえその関数を使わないとしても)
// これらは gCameraCoords といったグローバル変数を参照するため、 必要のない include は決してしないこと

#include "camera.h"
#include "gba/gba.h"
#include "inline.h"
#include "types.h"

// ワールド座標をアイソメトリック投影し, カメラを引いてスクリーンにする
static inline void WorldToScreen(Vec3* screen, WorldPos* world) {
  WorldToVp(screen, world);
  screen->x = screen->x - gCameraVpCoords.x + 120;
  screen->y = screen->y - gCameraVpCoords.y + 90;
  screen->z = screen->z - gCameraVpCoords.z;
}

#endif  // __INCLUDE_CAMERA_INLINE_H__
