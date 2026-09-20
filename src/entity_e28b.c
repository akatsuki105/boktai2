#include "entity.h"
#include "global.h"

// EntityE28B はサイズが固定じゃないのでまだ構造体を定義していない
// また "mask_test_00" という文字列を使っているため、デバッグ用途の可能性もある

const ALIGNED(4) char s_mask_test_00[] = "mask_test_00";  // 0x08251B2C

INCASM("asm/entity_e28b.inc");
