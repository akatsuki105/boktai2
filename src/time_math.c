#include "global.h"
#include "time.h"

// 多分、緯度経度に基づいた計算処理 (f64 を多用する, asm直書きの関数もあるかも)
// FUN_082401e8 が gClock に書き込みをしているので時間関連であることは確か

INCASM("asm/time_math.inc");
