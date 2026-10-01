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
IWRAM_DATA u8 u8_030000dc = 0;

const u8 u8_ARRAY_085ab5b0[8] = {0x67, 0x8E, 0xAA, 0x8F, 0xE0, 0x90, 0xD6, 0x8F};  // 0x085AB5B0

void FUN_0804b474(EntityFB53* p);
void FUN_0804b530(EntityFB53* p);
void FUN_0804b5f0(EntityFB53* p);
void FUN_0804b65c(EntityFB53* p);
void FUN_0804b6bc(EntityFB53* p);
void FUN_0804b71c(EntityFB53* p);
void FUN_0804b774(EntityFB53* p);
void FUN_0804b7d0(EntityFB53* p);
void FUN_0804b83c(EntityFB53* p);
void FUN_0804b870(EntityFB53* p);

void (*const PTR_ARRAY_085ab5b8[10])(EntityFB53*) = {
    FUN_0804b474, FUN_0804b530, FUN_0804b5f0, FUN_0804b65c, FUN_0804b6bc, FUN_0804b71c, FUN_0804b774, FUN_0804b7d0, FUN_0804b83c, FUN_0804b870,
};  // 0x085AB5B8

void FUN_0804c3cc(unknown*);
void FUN_0804c3e4(unknown*);
void FUN_0804c438(unknown*);
void FUN_0804c57c(unknown*);
void FUN_0804c5c0(unknown*);
void FUN_0804c5d8(unknown*);
void FUN_0804c650(unknown*);
void FUN_0804c6ac(unknown*);
void FUN_0804c7c8(unknown*);
void FUN_0804c888(unknown*);
void FUN_0804c8bc(unknown*);
void FUN_0804c8f4(unknown*);
void FUN_0804c940(unknown*);
void FUN_0804c978(unknown*);
void FUN_0804c9a8(unknown*);
void FUN_0804cb6c(unknown*);
void FUN_0804cb84(unknown*);
void FUN_0804cb9c(unknown*);
void FUN_0804cbb4(unknown*);
void FUN_0804d698(unknown*);
void FUN_0804d6d0(unknown*);
void FUN_0804da50(unknown*);
void FUN_0804de18(unknown*);
void FUN_0804da78(unknown*);
void FUN_0804de40(unknown*);
void FUN_0804dae4(unknown*);
void FUN_0804de58(unknown*);
void FUN_0804cbcc(unknown*);
void FUN_0804cbfc(unknown*);
void FUN_0804cc38(unknown*);
void FUN_0804cc7c(unknown*);
void FUN_0804cc98(unknown*);
void FUN_0804ccbc(unknown*);

void (*const PTR_ARRAY_085ab5e0[33])(unknown*) = {
    FUN_0804c3cc, FUN_0804c3e4, FUN_0804c438, FUN_0804c57c, FUN_0804c5c0, FUN_0804c5d8, FUN_0804c650, FUN_0804c6ac, FUN_0804c7c8, FUN_0804c888, FUN_0804c8bc, FUN_0804c8f4, FUN_0804c940, FUN_0804c978, FUN_0804c9a8, FUN_0804cb6c, FUN_0804cb84, FUN_0804cb9c, FUN_0804cbb4, FUN_0804d698, FUN_0804d6d0, FUN_0804da50, FUN_0804de18, FUN_0804da78, FUN_0804de40, FUN_0804dae4, FUN_0804de58, FUN_0804cbcc, FUN_0804cbfc, FUN_0804cc38, FUN_0804cc7c, FUN_0804cc98, FUN_0804ccbc,
};  // 0x085AB5E0

INCASM("asm/entity_fb53.inc");
