#include "entity.h"
#include "global.h"

struct Entity8B8E;

typedef void(Entity8B8EFunc)(struct Entity8B8E* p);

// 通信ショップの画面, LinkShopManager に自分を owner として登録する
typedef struct Entity8B8E {
  Entity e;                        // 0x0000, ENTITY_UNK_11
  Entity8B8EFunc* updateCallback;  // 0x0018, Init は FUN_081e80ac を入れる
  u8 unk_1c[0x1610 - 0x1C];        // 0x001C, まだ未解析
  u32 unk_1610;                    // 0x1610, Init が 0 を書く
  u8 unk_1614;                     // 0x1614, Init が 1 を書く
  u8 unk_1615;                     // 0x1615, Init が 0 を書く
  u8 unk_1616;                     // 0x1616, Init が 0x14 を書く
  u8 unk_1617;                     // 0x1617, Init が 0xFF を書く
  u8 unk_1618[0x1626 - 0x1618];    // 0x1618, まだ未解析
  u16 exitScriptID;                // 0x1626, .e=0, 通信が中断されたときに実行する
  s16 unk_1628;                    // 0x1628, .l=0
  u8 unk_162a[5680 - 0x162A];      // 0x162A, まだ未解析
} Entity8B8E;
static_assert(sizeof(Entity8B8E) == 5680);

// 推測: u8[18][4]
const u8 u8_ARRAY_085ae404[72] = {
    0x0C, 0x04, 0x10, 0x01, 0x0D, 0x05, 0x00, 0x02, 0x0E, 0x06, 0x01, 0x03, 0x0F, 0x07, 0x02, 0x10, 0x00, 0x08, 0x10, 0x05, 0x01, 0x09, 0x04, 0x06, 0x02, 0x0A, 0x05, 0x07, 0x03, 0x0B, 0x06, 0x10, 0x04, 0x0C, 0x10, 0x09,
    0x05, 0x0D, 0x08, 0x0A, 0x06, 0x0E, 0x09, 0x0B, 0x07, 0x0F, 0x0A, 0x10, 0x08, 0x00, 0x11, 0x0D, 0x09, 0x01, 0x0C, 0x0E, 0x0A, 0x02, 0x0D, 0x0F, 0x0B, 0x03, 0x0E, 0x11, 0x11, 0x11, 0x03, 0x00, 0x10, 0x10, 0x0F, 0x0C,
};  // 0x085AE404

NAKED void FUN_081e2628(s32 param_1) { INCFUNC("asm/func/FUN_081e2628.inc"); }

NAKED void FUN_081e275c(s32 param_1) { INCFUNC("asm/func/FUN_081e275c.inc"); }

NAKED void FUN_081e27f0(s32 param_1) { INCFUNC("asm/func/FUN_081e27f0.inc"); }

NAKED void FUN_081e2960(s32 param_1) { INCFUNC("asm/func/FUN_081e2960.inc"); }

NAKED void FUN_081e2b08(s32 param_1) { INCFUNC("asm/func/FUN_081e2b08.inc"); }

NAKED void FUN_081e2c14(s32 param_1) { INCFUNC("asm/func/FUN_081e2c14.inc"); }

NAKED void FUN_081e2cdc(s32 param_1) { INCFUNC("asm/func/FUN_081e2cdc.inc"); }

NAKED void FUN_081e2d98(s32 param_1) { INCFUNC("asm/func/FUN_081e2d98.inc"); }

NAKED void FUN_081e2dd8(s32 param_1) { INCFUNC("asm/func/FUN_081e2dd8.inc"); }

NAKED void FUN_081e2e24(s32 param_1) { INCFUNC("asm/func/FUN_081e2e24.inc"); }

NAKED s32 FUN_081e2e84(s32 param_1) { INCFUNC("asm/func/FUN_081e2e84.inc"); }

NAKED void FUN_081e2ee8(s32 param_1) { INCFUNC("asm/func/FUN_081e2ee8.inc"); }

NAKED void FUN_081e32d8(s32 param_1) { INCFUNC("asm/func/FUN_081e32d8.inc"); }

NAKED void FUN_081e3444(s32 param_1) { INCFUNC("asm/func/FUN_081e3444.inc"); }

NAKED void FUN_081e3594(s32 param_1) { INCFUNC("asm/func/FUN_081e3594.inc"); }

NAKED void FUN_081e3680(s32 param_1) { INCFUNC("asm/func/FUN_081e3680.inc"); }

NAKED void FUN_081e36e8(s32 param_1) { INCFUNC("asm/func/FUN_081e36e8.inc"); }

NAKED void FUN_081e3714(s32 param_1) { INCFUNC("asm/func/FUN_081e3714.inc"); }

NAKED s32 FUN_081e3758(s32 param_1) { INCFUNC("asm/func/FUN_081e3758.inc"); }

NAKED void FUN_081e37a0(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_081e37a0.inc"); }

NAKED void FUN_081e3958(s32 param_1, unknown* param_2) { INCFUNC("asm/func/FUN_081e3958.inc"); }

NAKED void FUN_081e3cc0(s32 param_1) { INCFUNC("asm/func/FUN_081e3cc0.inc"); }

NAKED void FUN_081e3cd4(void) { INCFUNC("asm/func/FUN_081e3cd4.inc"); }

NAKED void FUN_081e3ce8(s32 param_1) { INCFUNC("asm/func/FUN_081e3ce8.inc"); }

NAKED void FUN_081e3d78(s32 param_1) { INCFUNC("asm/func/FUN_081e3d78.inc"); }

NAKED void FUN_081e3dec(s32 param_1) { INCFUNC("asm/func/FUN_081e3dec.inc"); }

NAKED s32 FUN_081e3e78(s32 param_1) { INCFUNC("asm/func/FUN_081e3e78.inc"); }

NAKED void FUN_081e3ea8(s32 param_1) { INCFUNC("asm/func/FUN_081e3ea8.inc"); }

NAKED void FUN_081e3f0c(s32 param_1) { INCFUNC("asm/func/FUN_081e3f0c.inc"); }

NAKED void FUN_081e3fac(s32 param_1) { INCFUNC("asm/func/FUN_081e3fac.inc"); }

NAKED void FUN_081e3fe0(s32 param_1) { INCFUNC("asm/func/FUN_081e3fe0.inc"); }

NAKED s32 FUN_081e4014(s32 param_1) { INCFUNC("asm/func/FUN_081e4014.inc"); }

NAKED void FUN_081e4054(s32 param_1) { INCFUNC("asm/func/FUN_081e4054.inc"); }

NAKED void FUN_081e41e4(s32 param_1) { INCFUNC("asm/func/FUN_081e41e4.inc"); }

NAKED void FUN_081e4354(s32 param_1) { INCFUNC("asm/func/FUN_081e4354.inc"); }

NAKED void FUN_081e4388(s32 param_1) { INCFUNC("asm/func/FUN_081e4388.inc"); }

NAKED void FUN_081e4450(s32 param_1) { INCFUNC("asm/func/FUN_081e4450.inc"); }

NAKED void FUN_081e4484(s32 param_1) { INCFUNC("asm/func/FUN_081e4484.inc"); }

NAKED void FUN_081e44b4(s32 param_1) { INCFUNC("asm/func/FUN_081e44b4.inc"); }

NAKED void FUN_081e44d0(s32 param_1) { INCFUNC("asm/func/FUN_081e44d0.inc"); }

NAKED void FUN_081e4544(s32 param_1) { INCFUNC("asm/func/FUN_081e4544.inc"); }

NAKED s32 FUN_081e45e4(s32 param_1, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_081e45e4.inc"); }

NAKED void FUN_081e4604(s32 param_1, s32 param_2, u32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_081e4604.inc"); }

NAKED void FUN_081e4644(u32 param_1, s32 param_2, s32 param_3, s32 param_4, u16 param_5, u32 param_6) { INCFUNC("asm/func/FUN_081e4644.inc"); }

NAKED s32 FUN_081e468c(s32 param_1, unknown* param_2, u32 param_3) { INCFUNC("asm/func/FUN_081e468c.inc"); }

NAKED void FUN_081e47c4(s32 param_1) { INCFUNC("asm/func/FUN_081e47c4.inc"); }

NAKED void FUN_081e4838(s32 param_1) { INCFUNC("asm/func/FUN_081e4838.inc"); }

NAKED void FUN_081e4948(s32 param_1) { INCFUNC("asm/func/FUN_081e4948.inc"); }

NAKED void FUN_081e49a8(s32 param_1) { INCFUNC("asm/func/FUN_081e49a8.inc"); }

NAKED void FUN_081e4a60(s32 param_1) { INCFUNC("asm/func/FUN_081e4a60.inc"); }

NAKED s32 FUN_081e4ab8(s32 param_1) { INCFUNC("asm/func/FUN_081e4ab8.inc"); }

NAKED void FUN_081e4b68(s32 param_1, u32 param_2) { INCFUNC("asm/func/FUN_081e4b68.inc"); }

NAKED void FUN_081e4bb8(s32 param_1) { INCFUNC("asm/func/FUN_081e4bb8.inc"); }

NAKED void FUN_081e4bdc(unknown* param_1, u32 param_2) { INCFUNC("asm/func/FUN_081e4bdc.inc"); }

NAKED void FUN_081e4c40(s32 param_1) { INCFUNC("asm/func/FUN_081e4c40.inc"); }

NAKED void FUN_081e4c64(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_081e4c64.inc"); }

NAKED void FUN_081e4cb4(s32 param_1, unknown* param_2, s32 param_3) { INCFUNC("asm/func/FUN_081e4cb4.inc"); }

NAKED void FUN_081e4d04(s32 param_1) { INCFUNC("asm/func/FUN_081e4d04.inc"); }

NAKED void FUN_081e4de0(s32 param_1) { INCFUNC("asm/func/FUN_081e4de0.inc"); }

NAKED void FUN_081e4edc(s32 param_1) { INCFUNC("asm/func/FUN_081e4edc.inc"); }

NAKED void FUN_081e5290(s32 param_1) { INCFUNC("asm/func/FUN_081e5290.inc"); }

NAKED void FUN_081e52ac(s32 param_1) { INCFUNC("asm/func/FUN_081e52ac.inc"); }

NAKED void FUN_081e53e8(s32 param_1) { INCFUNC("asm/func/FUN_081e53e8.inc"); }

NAKED void FUN_081e564c(s32 param_1) { INCFUNC("asm/func/FUN_081e564c.inc"); }

NAKED void FUN_081e57f4(s32 param_1) { INCFUNC("asm/func/FUN_081e57f4.inc"); }

NAKED void FUN_081e58dc(s32 param_1) { INCFUNC("asm/func/FUN_081e58dc.inc"); }

NAKED void FUN_081e5c40(s32 param_1) { INCFUNC("asm/func/FUN_081e5c40.inc"); }

NAKED void FUN_081e5d14(s32 param_1) { INCFUNC("asm/func/FUN_081e5d14.inc"); }

NAKED void FUN_081e5dc8(s32 param_1) { INCFUNC("asm/func/FUN_081e5dc8.inc"); }

NAKED void FUN_081e603c(s32 param_1) { INCFUNC("asm/func/FUN_081e603c.inc"); }

NAKED void FUN_081e60c8(s32 param_1) { INCFUNC("asm/func/FUN_081e60c8.inc"); }

NAKED void FUN_081e617c(unknown* param_1) { INCFUNC("asm/func/FUN_081e617c.inc"); }

NAKED void FUN_081e6388(unknown* param_1) { INCFUNC("asm/func/FUN_081e6388.inc"); }

NAKED void FUN_081e6458(s32 param_1) { INCFUNC("asm/func/FUN_081e6458.inc"); }

NAKED void FUN_081e64cc(s32 param_1) { INCFUNC("asm/func/FUN_081e64cc.inc"); }

NAKED void FUN_081e653c(s32 param_1) { INCFUNC("asm/func/FUN_081e653c.inc"); }

NAKED void FUN_081e66e0(s32 param_1) { INCFUNC("asm/func/FUN_081e66e0.inc"); }

NAKED void FUN_081e676c(s32 param_1) { INCFUNC("asm/func/FUN_081e676c.inc"); }

NAKED void FUN_081e6810(s32 param_1) { INCFUNC("asm/func/FUN_081e6810.inc"); }

NAKED void FUN_081e6a2c(s32 param_1) { INCFUNC("asm/func/FUN_081e6a2c.inc"); }

NAKED void FUN_081e6b5c(s32 param_1) { INCFUNC("asm/func/FUN_081e6b5c.inc"); }

NAKED void FUN_081e6f28(s32 param_1) { INCFUNC("asm/func/FUN_081e6f28.inc"); }

NAKED void FUN_081e7414(s32 param_1) { INCFUNC("asm/func/FUN_081e7414.inc"); }

NAKED void FUN_081e78d0(s32 param_1) { INCFUNC("asm/func/FUN_081e78d0.inc"); }

NAKED void FUN_081e7a38(unknown* param_1) { INCFUNC("asm/func/FUN_081e7a38.inc"); }

NAKED void FUN_081e7ac4(s32 param_1) { INCFUNC("asm/func/FUN_081e7ac4.inc"); }

NAKED void FUN_081e7bfc(s32 param_1) { INCFUNC("asm/func/FUN_081e7bfc.inc"); }

NAKED void FUN_081e7db4(s32 param_1) { INCFUNC("asm/func/FUN_081e7db4.inc"); }

NAKED void FUN_081e7fd0(s32 param_1) { INCFUNC("asm/func/FUN_081e7fd0.inc"); }

NAKED void FUN_081e80ac(s32 param_1) { INCFUNC("asm/func/FUN_081e80ac.inc"); }

NAKED void FUN_081e8110(unknown* param_1) { INCFUNC("asm/func/FUN_081e8110.inc"); }

NAKED s32 Entity8B8E_Update(Entity8B8E* p) { INCFUNC("asm/func/Entity8B8E_Update.inc"); }

NAKED s32 Entity8B8E_Destroy(Entity8B8E* p) { INCFUNC("asm/func/Entity8B8E_Destroy.inc"); }

NAKED s32 Entity8B8E_Init(Entity8B8E* p) { INCFUNC("asm/func/Entity8B8E_Init.inc"); }

NAKED Entity8B8E* Entity8B8E_Create(void) { INCFUNC("asm/func/Entity8B8E_Create.inc"); }
