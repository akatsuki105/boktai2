#ifndef GUARD_MAP_PLTT_H
#define GUARD_MAP_PLTT_H

#include "entity.h"
#include "file.h"
#include "global.h"
#include "types.h"

// 時間帯連動 (MAPPLTT_TIMEOFDAY) か, 行単位の往復混合 (MAPPLTT_OSCILLATE) か, 単純転送かを選ぶ
typedef u8 MapPlttFlags;
#define MAPPLTT_TIMEOFDAY (1 << 0)  // 0x1, 時間帯の2枚を混ぜ続ける, 天候による減光もこの経路
#define MAPPLTT_OSCILLATE (1 << 1)  // 0x2, 混合比を 0..0x40 で往復させながら行単位に流す

// マップ切り替え時に毎回生成される(時間帯によるマップのパレット処理と思われる)
typedef struct {
  Entity e;                      // ENTITY_UNK_11
  u16 id;                        // 0x018
  MapPlttFlags flags;            // 0x01A, '.f', see MapPlttFlags
  u8 state;                      // 0x01B, sMapPlttStates の idx, 4 以上はフェード中で新規コマンドを 4/5 しか受け付けない
  u8 crossfadeLevel;             // 0x01C, MapPltt_StepCrossfade が BlendPltt2 に渡す混合比, 0x40 を超えたら srcPltt2 へ乗り換える
  u8 crossfadeRow;               // 0x01D, 次に混合するパレット行, 0xC を超えたら 0 に戻る
  u8 crossfadeLevelStep;         // 0x01E, 1周ごとの crossfadeLevel の増分, 既定 7
  u8 crossfadeRowStep;           // 0x01F, 1回に進めるパレット行数, 既定 4
  u8 unk_20;                     // 0x020, dstPltt を書いたら 1, _Update の先頭で 0, 読み手は未発見
  u8 unk_21[0x24 - 0x21];        // 0x021, padding?
  const rgb555* srcPltt1;        // 0x024
  const rgb555* srcPltt2;        // 0x028
  rgb555* dstPltt;               // 0x02C, gBgPlttBuffer
  rgb555* curPltt;               // 0x030, いま dstPltt へ転送する元, plttTimeBlend か plttWeatherBlend を指す
  rgb555 plttTimeBlend[256];     // 0x034, srcPltt1 と srcPltt2 を timeBlendLevel で混ぜたもの
  rgb555 plttWeatherBlend[256];  // 0x234, plttTimeBlend と plttWeather を weatherLevel で混ぜたもの
  rgb555 plttWeather[256];       // 0x434, bgpIDs[2] を 50/64 に落としたもの, 天候用
  FileID bgpIDs[4];              // 0x634, '.p' の並び, _Init が最大4個積む
  u16 fadeTimer;                 // 0x63C, フェードの経過フレーム, (1 << fadeShift) に達したら終わり
  u16 fadeShift;                 // 0x63E, フェードの長さの log2, gBgBrightness = fadeTimer << 6 >> fadeShift
  u8 timeBlendLevel;             // 0x640, 時間帯の2枚の混合比, MapPltt_StepBlend が 0x40 まで進める
  u8 prevTimeBlendLevel;         // 0x641, 前フレームの timeBlendLevel の控え, 読み手は未発見
  u8 weatherLevel;               // 0x642, 天候による減光の強さ, sMapPlttWeatherSteps の4つが動かす
  u8 prevWeatherLevel;           // 0x643, 前フレームの weatherLevel, 変化したときだけ混合をやり直す
  u8 weatherState;               // 0x644, sMapPlttWeatherSteps の idx
  u16 unk_648;                   // 0x648, _Init と時間帯の変わり目で 0 を入れるだけ, 読み手は未発見
  u16 unk_64a;                   // 0x64A, 0 のときだけ weatherState の処理を回す, 非0 を入れる箇所は未発見
  u16 spanOfTime;                // 0x64C
  u16 unk_64e;                   // 0x64E, gClock.unk_0f
  u16 oscTimer;                  // 0x650, oscPeriod に達すると oscLevel を1段動かす
  u16 unk_652;                   // 0x652, '.a[0]=4', 読み手は未発見
  u16 oscLevel;                  // 0x654, 往復する混合比, MapPltt_BlendRows が s16 として読み >>1 して使う
  u16 oscPeriod;                 // 0x656, '.a[1]=2', oscTimer の上限
  u8 oscRow;                     // 0x658, MapPltt_BlendRows の開始パレット行
  u8 oscRowStep;                 // 0x659, '.a[2]=8', 1回に進めるパレット行数
  bool8 oscActive;               // 0x65A, 0 以外なら Entity4AE5_Update が MapPltt_BlendRows を呼ぶ
  u8 unk_65b;                    // 0x65B
  u16 oscRowMask;                // 0x65C, '.a[3]=0xFFFF', 混合するパレット行のビットマスク
  u16 oscWait;                   // 0x65E, 折り返しで止まっている間のカウントダウン
  u16 oscStep;                   // 0x660, '.a[4]=0x20', oscLevel の増分, 折り返しで符号が反転する
  u16 oscWaitLength;             // 0x662, '.a[5]=0', 上限側で折り返すときの待ち時間
  s32 cmdCount;                  // 0x664, cmds に積まれた件数, 最大8
  u16 cmds[8];                   // 0x668, MapPltt_PushCommand が積むコマンド番号
  u16 cmdArgs[8][8];             // 0x678, コマンド1件につき引数8個
} Entity4AE5;
static_assert(sizeof(Entity4AE5) == 1784);

extern Entity4AE5* gEntity4AE5;

#endif  // GUARD_MAP_PLTT_H
