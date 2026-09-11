#include "global.h"
#include "sprite.h"

// ここから ARMステートの関数だったのでファイルを分割した
// WARNING: Makefile の CFLAGS は src/lib/librfu_intr.c のをコピペしただけなので CFLAGS が適切でない可能性アリ。コンパイル結果がどうしても一致しない場合は、CFLAGS を調整すること。

NAKED unknown* FUN_0822f650(unknown* param_1, unknown* param_2) { INCFUNC("asm/func/FUN_0822f650.inc"); }

// SpriteState の描画関数
NAKED void DrawSprite_0822f6fc(SpriteState* p, s32 x, s32 y, s32 z) { INCFUNC("asm/func/DrawSprite_0822f6fc.inc"); }

NAKED void FUN_08230134(void) { INCFUNC("asm/func/FUN_08230134.inc"); }

NAKED void FUN_082302e8(void) { INCFUNC("asm/func/FUN_082302e8.inc"); }

NAKED void FUN_082303c8(void) { INCFUNC("asm/func/FUN_082303c8.inc"); }

NAKED void FUN_08230594(void) { INCFUNC("asm/func/FUN_08230594.inc"); }
