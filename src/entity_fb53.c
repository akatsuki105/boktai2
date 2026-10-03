#include "entity.h"
#include "global.h"

// GBAワイヤレスアダプタで相手を探して接続するエンティティ
typedef struct {
  Entity e;             // 0x00, ENTITY_UNK_2
  u8 state;             // 0x18, PTR_ARRAY_085ab5b8 の添字
  bool8 stateChanged;   // 0x19, 各ハンドラが入り口で1回だけ処理して 0 に戻す
  u8 linkError;         // 0x1A, EntityFB53_WatchLink が bit0、EntityFB53_SetLinkError が 理由 | 0xF0 を立てる, 非0 なら state が 9 になる
  bool8 partnerFound;   // 0x1B, Rfu_FindPartnerRecord が見つけたら 1
  u16 watchLinkResult;  // 0x1C, rfu_REQBN_watchLink の戻り値
  u8 retryCount;        // 0x1E, 3 未満なら state 5 へ戻し、以上なら state 8 へ進める
  u8 saveResult;        // 0x1F, Save_WriteSystemData の戻り値
  u8 partnerGameIdx;    // 0x20, EntityFB53_FindGameIdx の戻り値, TextPanel_SetMessage の添字として +3 される
  u8 unk_21[3];         // 0x21, まだ未解析
  u32 timer;            // 0x24, 毎フレーム +1, state を変えるとき 0 に戻る
  u8* scriptM;          // 0x28, '.m'
  u8* scriptS;          // 0x2C, '.s'
  s32 panelID;          // 0x30, TextPanel_Create(1, 7, 0x1C, 6) の戻り値, 負なら未作成
  s32 scriptID;         // 0x34, '.e' の値, 読み手は未発見
  u8 unk_38;            // 0x38, まだ未解析
  u8 linkLossSlot;      // 0x39, rfu_REQBN_watchLink の bmLinkLossSlot
  u8 linkLossReason;    // 0x3A, rfu_REQBN_watchLink の linkLossReason
  u8 linkRecoverySlot;  // 0x3B, rfu_REQBN_watchLink の parentBmLinkRecoverySlot
  u8 partnerRecord[8];  // 0x3C, Rfu_FindPartnerRecord の dst, 先頭2バイトを EntityFB53_FindGameIdx が u8_ARRAY_085ab5b0 の4つのIDと比べる
  u8 unk_44[8];         // 0x44, Rfu_FindPartnerRecord の buf
} EntityFB53;
static_assert(sizeof(EntityFB53) == 76);

IWRAM_DATA s32 s32_030000d4 = 0;            // 0x030000D4
IWRAM_DATA EntityFB53* gEntityFB53 = NULL;  // 0x030000D8

const u8 u8_ARRAY_085ab5b0[8] = {0x67, 0x8E, 0xAA, 0x8F, 0xE0, 0x90, 0xD6, 0x8F};  // 0x085AB5B0

void FUN_0804b474(EntityFB53*);
void FUN_0804b530(EntityFB53*);
void FUN_0804b5f0(EntityFB53*);
void FUN_0804b65c(EntityFB53*);
void FUN_0804b6bc(EntityFB53*);
void FUN_0804b71c(EntityFB53*);
void FUN_0804b774(EntityFB53*);
void FUN_0804b7d0(EntityFB53*);
void FUN_0804b83c(EntityFB53*);
void FUN_0804b870(EntityFB53*);

void (*const PTR_ARRAY_085ab5b8[10])(EntityFB53*) = {
    FUN_0804b474, FUN_0804b530, FUN_0804b5f0, FUN_0804b65c, FUN_0804b6bc, FUN_0804b71c, FUN_0804b774, FUN_0804b7d0, FUN_0804b83c, FUN_0804b870,
};  // 0x085AB5B8

NAKED s32 EntityFB53_IsActive(void) { INCFUNC("asm/func/EntityFB53_IsActive.inc"); }

NAKED void EntityFB53_WatchLink(void) { INCFUNC("asm/func/EntityFB53_WatchLink.inc"); }

NAKED void EntityFB53_SetLinkError(EntityFB53* p, s16 reason) { INCFUNC("asm/func/EntityFB53_SetLinkError.inc"); }

NAKED s32 FUN_0804b2dc(void) { INCFUNC("asm/func/FUN_0804b2dc.inc"); }

NAKED void EntityFB53_Disconnect(void) { INCFUNC("asm/func/EntityFB53_Disconnect.inc"); }

NAKED void EntityFB53_SetupBG(EntityFB53* p, s32 param_2) { INCFUNC("asm/func/EntityFB53_SetupBG.inc"); }

NAKED void FUN_0804b3f8(EntityFB53* p) { INCFUNC("asm/func/FUN_0804b3f8.inc"); }

NAKED void FUN_0804b474(EntityFB53* p) { INCFUNC("asm/func/FUN_0804b474.inc"); }

NAKED s32 EntityFB53_FindGameIdx(u8* record) { INCFUNC("asm/func/EntityFB53_FindGameIdx.inc"); }

NAKED void FUN_0804b500(s32 param_1) { INCFUNC("asm/func/FUN_0804b500.inc"); }

NAKED void FUN_0804b530(EntityFB53* p) { INCFUNC("asm/func/FUN_0804b530.inc"); }

NAKED void FUN_0804b5f0(EntityFB53* p) { INCFUNC("asm/func/FUN_0804b5f0.inc"); }

NAKED void FUN_0804b65c(EntityFB53* p) { INCFUNC("asm/func/FUN_0804b65c.inc"); }

NAKED void FUN_0804b6bc(EntityFB53* p) { INCFUNC("asm/func/FUN_0804b6bc.inc"); }

NAKED void FUN_0804b71c(EntityFB53* p) { INCFUNC("asm/func/FUN_0804b71c.inc"); }

NAKED void FUN_0804b774(EntityFB53* p) { INCFUNC("asm/func/FUN_0804b774.inc"); }

NAKED void FUN_0804b7d0(EntityFB53* p) { INCFUNC("asm/func/FUN_0804b7d0.inc"); }

NAKED void FUN_0804b83c(EntityFB53* p) { INCFUNC("asm/func/FUN_0804b83c.inc"); }

NAKED void FUN_0804b870(EntityFB53* p) { INCFUNC("asm/func/FUN_0804b870.inc"); }

NAKED s32 EntityFB53_Update(EntityFB53* p) { INCFUNC("asm/func/EntityFB53_Update.inc"); }

NAKED s32 EntityFB53_Destroy(EntityFB53* p) { INCFUNC("asm/func/EntityFB53_Destroy.inc"); }

NAKED s32 EntityFB53_Init(EntityFB53* p) { INCFUNC("asm/func/EntityFB53_Init.inc"); }

NAKED EntityFB53* EntityFB53_Create(void) { INCFUNC("asm/func/EntityFB53_Create.inc"); }
