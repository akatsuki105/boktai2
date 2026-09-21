#ifndef __INCLUDE_CAMERA_H__
#define __INCLUDE_CAMERA_H__

#include "entity.h"
#include "gba/gba.h"
#include "msgbus.h"
#include "types.h"

typedef struct {
  Entity e;             // 0x00, ENTITY_CAMERA
  u32 unk_18;           // 0x18, マップと対応する何かの値, サンミゲル(屋外や鍛冶屋内)や暗黒街: 0xD23E, n番街: 0x56CB
  u16 unk_1c;           // 0x1C
  u16 unk_1e;           // 0x1E
  EntityMsgBox msgbox;  // 0x20
  u16 moveMode;         // 0x54, 0: プレイヤー追従, 1: destPos へ即座に移動, 2以上: destPos へ moveTimer フレームかけて補間, 根拠: FUN_0823c450 の分岐
  u16 moveTimer;        // 0x56, pos を destPos へ寄せる補間の残りフレーム数, 根拠: FUN_0823c450 が Div の除数に使い毎フレーム減算する
  Vec3 pos;             // 0x58, カメラ自身の現在位置, 根拠: Camera_Update が gCameraWorldCoords にそのまま代入し、Camera_Init が gStat->playerPos から初期化する
  Vec3 destPos;         // 0x60, 移動先の座標, 根拠: FUN_0823b8ac / FUN_0823b980 が外部から書き、FUN_0823c450 が pos をここへ寄せる
  u16 lookMode;         // 0x68, 注視点の決め方 (0-7), 根拠: FUN_0823c620 の switch 対象
  u16 lookTimer;        // 0x6A, 注視点補間の残りフレーム数, 根拠: FUN_0823c620 が Div の除数に使い毎フレーム減算する
  Vec3 pos_6c;          // 0x6C, lookMode が 1/2 のときの注視点
  Vec3 pos_74;          // 0x74, lookMode が 3/4 のときの注視対象からのオフセット
  u16 lookTargetID;     // 0x7C, 注視対象の ID, 根拠: FUN_0823c620 が FUN_0823b2d0(lookTargetID) に渡して Entity2UnkData* を得る
  u16 shakeAmplitude;   // 0x7E, 今フレームの画面揺れの振幅, 根拠: FUN_0823c928 が shakeCurrent から取って毎回0に戻す
  s16 shakeOffsetX;     // 0x80, 画面揺れの X オフセット, 根拠: FUN_0823c928 が gCameraWorldCoords.x に加算する
  s16 shakeOffsetZ;     // 0x82, 画面揺れの Z オフセット, 根拠: FUN_0823c928 が gCameraWorldCoords.z に加算する
  u8 shakeActive;       // 0x84, 0以外なら画面揺れ中, 根拠: FUN_0823bd14 が開始で1/停止で0を書く
  u8 shakeStopOnEnd;    // 0x85, 0以外なら shakeTimer が尽きた時に揺れを完全に止める, 0なら shakeTarget のまま揺れ続ける
  u16 shakeCurrent;     // 0x86, 現在の振幅, 根拠: FUN_0823c928 が shakeTarget へ向けて Div で補間する
  u16 shakeTarget;      // 0x88, 目標の振幅, 根拠: FUN_0823bd14 の第1引数
  u16 shakeTimer;       // 0x8A, 揺れの残りフレーム数, 根拠: FUN_0823bd14 の第2引数を FUN_0823c928 が減算する
  u16 unk_8c;           // 0x8C
  s16 unk_8e;           // 0x8E
  s16 unk_90;           // 0x90
  s16 unk_92;           // 0x92
  s16 unk_94;           // 0x94
  u16 scriptIDType;     // 0x96, scriptID の型 を示す, 0 ならポインタ、 それ以外なら ID(数値)
  s32 scriptID;         // 0x98, scriptIDType が 0 ならポインタ(u8*)、それ以外なら ID(数値)
  Vec3* targetPos;      // 0x9C, lookMode が 7 のときの注視点, 根拠: FUN_0823c620 が指す先から8バイトを gCameraWorldCoords へコピーする
  s32* unk_a0;          // 0xA0, 0以外を指している間だけ targetPos が使われる, 根拠: FUN_0823c620
} Camera;
static_assert(sizeof(Camera) == 164);

extern Camera* gCamera;  // 0x030047D0

// 0x03003540 から 0x03003554 の手前までが1つの構造体
// 根拠: FUN_0822a2a8 / Camera_SetTilemapOffset / Map_LoadMapScripted / Video_SetDrawPasses がいずれも 0x03003540 を単一のプール定数から読み、そこからのオフセットで書く
// 上限の根拠: Video_SetDrawPasses は同一関数内で 0x03003554 / 0x03003534 / 0x03003558 をそれぞれ別のプール定数から読んでいる
typedef struct {
  Vec3 worldPos;  // 0x00, カメラの注視点のワールド座標, 根拠: FUN_0822a2a8 が +0/+2/+4 をクリアする
  s16 tilemapX;   // 0x08, 根拠: Camera_SetTilemapOffset が strh [r1,#0x8] で書く
  s16 tilemapY;   // 0x0A, 根拠: 同上 strh [r1,#0xa]
  s16 unk_0c;     // 0x0C, FUN_0822a2a8 が 1 を書く, 読み手は未特定
  s16 unk_0e;     // 0x0E, 参照が見つかっていない (幅も未確定)
  s16 unk_10;     // 0x10, FUN_0822a2a8 が 0 を書く, 読み手は未特定
  s16 unk_12;     // 0x12, 根拠: Video_SetDrawPasses が strh [r4,#0x12] で書き、FUN_0823b4b8 / Video_GenerateBackgroundMaps / FUN_0823c450 / FUN_0823c620 が読む
} CameraCoords;
static_assert(sizeof(CameraCoords) == 20);

extern CameraCoords gCameraCoords;  // 0x03003540
extern Vec3 gCameraVpCoords;        // 0x030047C8

void Camera_0823b744(void);
void FUN_0823b9cc(s32 n);

#endif  // __INCLUDE_CAMERA_H__
