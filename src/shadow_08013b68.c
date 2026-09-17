#include "entity.h"
#include "global.h"
#include "sprite_aux.h"

// 持ち主の足元に置く影 (AuxSprite 版), AuxShadowManager がリストで管理して毎フレーム fn を呼ぶ
// 高さが増えるほど scale を小さくする
typedef struct AuxShadow {
  u8 active;               // 0x00, FUN_0801392c でリストに入れると 1, FUN_08013954 で外すと 0
  u8 kind;                 // 0x01, 0 なら fn = FUN_080139b8 (床に追従), それ以外は nop_080139b4
  u8 flags;                // 0x02, bit0: FUN_080139b8 で当たり判定マップでなく pos->y を高さに使う
  u8 unk_03;               // 0x03
  u16 unk_04;              // 0x04, FUN_08013ba8 で 0
  u16 unk_06;              // 0x06, FUN_08013ba8 で 0
  Vec3* pos;               // 0x08, 持ち主の座標, FUN_080139b8 が x/y/z を読む
  AuxSprite sprite;        // 0x0C, 根拠: FUN_0822a470 / FUN_0822a4e0
  AuxSpriteGfx gfx;        // 0x38, 根拠: Video_GetAuxSprite(EFF_1C1B) / FUN_0822a470
  s8 scale;                // 0x54, FUN_080139b8 が高さから計算して sprite.scaleX/Y に入れる, 1 未満なら 1
  u8 farScale;             // 0x55, 高さが farHeight を超えたときの scale
  u8 baseScale;            // 0x56, 接地時の scale, 高さに応じてここから引く
  u8 unk_57;               // 0x57, FUN_08013ba8 の第6引数
  s16 farHeight;           // 0x58
  s16 nearHeight;          // 0x5A
  u16 farShift;            // 0x5C, nearHeight 以上 farHeight 以下のとき baseScale - (高さ >> farShift)
  u16 nearShift;           // 0x5E, nearHeight 未満のとき baseScale - (高さ >> nearShift)
  void* fn;                // 0x60, Entity08013b68_Update が影を引数にして呼ぶ
  struct AuxShadow* prev;  // 0x64
  struct AuxShadow* next;  // 0x68
} AuxShadow;
static_assert(sizeof(AuxShadow) == 108);  // next (0x68) までは確定, それ以降に続くかは未確認

typedef struct AuxShadowManager {
  Entity e;            // 0x00, ENTITY_UNK_9
  u8 unk_18[4];        // 0x18, 参照なし
  AuxShadow* shadows;  // 0x1C, 影のリストの先頭, Init で 0, FUN_0801392c / FUN_08013954 / Update
} AuxShadowManager;
static_assert(sizeof(AuxShadowManager) == 32);

extern AuxShadowManager* gAuxShadowManager;  // 0x03000054

void FUN_08013920(void) { gAuxShadowManager = NULL; }

NAKED s32 FUN_0801392c(AuxShadowManager* p, AuxShadow* shadow) { INCFUNC("asm/func/FUN_0801392c.inc"); }

NAKED s32 FUN_08013954(AuxShadowManager* p, AuxShadow* shadow) { INCFUNC("asm/func/FUN_08013954.inc"); }

NAKED void FUN_08013984(AuxShadow* shadow) { INCFUNC("asm/func/FUN_08013984.inc"); }

NAKED void FUN_080139a0(AuxShadow* shadow) { INCFUNC("asm/func/FUN_080139a0.inc"); }

void nop_080139b4(void) {}

NAKED void FUN_080139b8(AuxShadow* shadow) { INCFUNC("asm/func/FUN_080139b8.inc"); }

NAKED s32 Entity08013b68_Update(AuxShadowManager* p) { INCFUNC("asm/func/Entity08013b68_Update.inc"); }

NAKED s32 Entity08013b68_Destroy(AuxShadowManager* p) { INCFUNC("asm/func/Entity08013b68_Destroy.inc"); }

NAKED s32 Entity08013b68_Init(AuxShadowManager* p, u32 _) { INCFUNC("asm/func/Entity08013b68_Init.inc"); }

NAKED AuxShadowManager* Entity08013b68_Create(u32 unused1, u32 unused2) { INCFUNC("asm/func/Entity08013b68_Create.inc"); }

NAKED s32 FUN_08013ba8(AuxShadow* shadow, Vec3* pos, s8 scale, u8 farScale, u8 baseScale, u8 unk_57, s16 farHeight, s16 nearHeight, u16 farShift, u16 nearShift, u8 kind) { INCFUNC("asm/func/FUN_08013ba8.inc"); }

NAKED s32 FUN_08013c70(AuxShadow* shadow) { INCFUNC("asm/func/FUN_08013c70.inc"); }

NAKED unknown* FUN_08013c94(unknown* p, SpriteID32 id, u32 val) { INCFUNC("asm/func/FUN_08013c94.inc"); }

NAKED void* FUN_08013cb8(unknown* p, u32 param_2) { INCFUNC("asm/func/FUN_08013cb8.inc"); }

NAKED void FUN_08013cd8(unknown* p, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8, u32 param_9) { INCFUNC("asm/func/FUN_08013cd8.inc"); }
