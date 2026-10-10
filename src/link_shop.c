#include "entity.h"
#include "global.h"

// _Create が EntityA0A6_Create と Entity92ED_Create の 2種類ある (_Init, _Update, _Destory は共通)
// "通信販売"(というアイテム交換機能) の 文字列を使っていたので、 LinkShopManager という名前にしたが、 "通信販売" のロジックではなく、"通信販売"のセッション管理だけかもしれない (もしそうなら、適切な名前に変える)
typedef struct LinkShopManager {
  Entity e;  // ENTITY_UNK_2
  u8 unk_18[132 - 0x18];
} LinkShopManager;
static_assert(sizeof(LinkShopManager) == 132);

extern LinkShopManager* gLinkShopManager;  // 0x03002C6C, 0 以外なら SoftReset_0823a928 が Sio_Stop を呼ぶ, FUN_081e21dc が書き FUN_081e21c4 が 0 に戻す

INCASM("asm/link_shop.inc");
