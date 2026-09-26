#include "entity.h"
#include "global.h"

typedef u8 BgPlttBlendFlags;                    // BgPlttBlend.flags
#define BGP_BLEND_INTERPOLATE (1 << 0)          // セットされているなら、書き出し時に補間する, クリアされている場合は単純コピーする
#define BGP_BLEND_STOP_AT_FADEIN_END (1 << 1)   // 往路の終端で止める
#define BGP_BLEND_STOP_AT_FADEOUT_END (1 << 2)  // 復路の終端で止める

// 2枚のパレットの間を補間して書き出すスロット, BgPlttBlender_AddSlotFromScript がスクリプトから1件ずつ積む
typedef struct {
  rgb555* endPltt;         // 0x00, '.s', 補間の終点 (t が最大のときの色)
  rgb555* startPltt;       // 0x04, '.d', 補間の始点, BGP_BLEND_INTERPOLATE がクリアされている場合はこれがそのままコピーされる
  rgb555* outPltt;         // 0x08, '.b', 書き出し先 (常に gBgPlttBuffer 内)
  u8 count;                // 0x0C, '.n=1', 書き出す色数
  u8 timer;                // 0x0D, 毎フレーム +1, t = timer * 32 / 所要フレーム数
  BgPlttBlendFlags flags;  // 0x0E, '.f=0', see BgPlttBlendFlags
  bool8 reverse;           // 0x0F, 0 なら startPltt -> endPltt、 1 なら逆向き
  u8 fadeIn;               // 0x10, '.S=10', 往路のフレーム数
  u8 fadeOut;              // 0x11, '.D=10', 復路のフレーム数
  u8 unk_12[2];            // 0x12, padding
} BgPlttBlend;
static_assert(sizeof(BgPlttBlend) == 20);

// BG パレットの補間スロットを最大16件持ち、毎フレームまとめて更新するシングルトン
typedef struct {
  Entity e;               // 0x00, ENTITY_UNK_12
  u32 count;              // 0x18, 使用中のスロット数, _Init が 0、_AddSlotFromScript が +1 (15 を超えると拒否)
  rgb555 savedPltt[256];  // 0x1C, BgPlttBlender_SavePltt が gBgPlttBuffer 全体 (128 ワード) をコピーする, スロットの参照先にできる
  BgPlttBlend slots[16];  // 0x21C
} BgPlttBlender;
static_assert(sizeof(BgPlttBlender) == 860);

IWRAM_DATA BgPlttBlender* gBgPlttBlender = NULL;  // 0x0300008C

NAKED void BgPlttBlender_SavePltt(BgPlttBlender* p) { INCFUNC("asm/func/BgPlttBlender_SavePltt.inc"); }

NAKED s32 BgPlttBlender_UpdateSlot(BgPlttBlender* p, BgPlttBlend* slot) { INCFUNC("asm/func/BgPlttBlender_UpdateSlot.inc"); }

NAKED s32 BgPlttBlender_Update(BgPlttBlender* p) { INCFUNC("asm/func/BgPlttBlender_Update.inc"); }

s32 BgPlttBlender_Destroy(BgPlttBlender* p) {
  gBgPlttBlender = NULL;
  return 0;
}

s32 BgPlttBlender_Init(BgPlttBlender* p) {
  gBgPlttBlender = p;
  p->count = 0;
  BgPlttBlender_SavePltt(p);
  return 0;
}

NAKED BgPlttBlender* BgPlttBlender_Create(void) { INCFUNC("asm/func/BgPlttBlender_Create.inc"); }

NAKED s32 BgPlttBlender_AddSlotFromScript(void) { INCFUNC("asm/func/BgPlttBlender_AddSlotFromScript.inc"); }
