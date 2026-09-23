#include "entity.h"
#include "global.h"
#include "text.h"

// TextRenderer を1つ持ち、offset を毎フレーム進めて DAT_03002CE8 に流すシングルトン
typedef struct {
  Entity e;              // 0x000, ENTITY_UNK_3
  TextRenderer renderer; // 0x018, EntityDFC6_Init が FUN_0804967C(&renderer, 0, 0x12, 2, 2) で初期化する
  bool8 active;          // 0x178, FUN_08049C3C が立てて DAT_03003520 も 1 にする。FUN_08049C78 が両方戻す
  bool8 openReq;         // 0x179, _Update が FUN_08049C3C を呼んでから 0 に戻す
  bool8 closeReq;        // 0x17A, _Update が FUN_08049C78 を呼んでから 0 に戻す
  bool8 manualScroll;    // 0x17B, 0 なら offset を 8 単位で進める。0 以外なら delay と SELECT で進める
  u8 delay;              // 0x17C, FUN_0804990C が 30 を入れ、FUN_0804996C が手動側で減らす
  u8 unk_17d;            // 0x17D, FUN_0804990C が 0 を入れる
  u8 unk_17e[2];         // 0x17E, 読み手も書き手も見つかっていない
  s32 timer;             // 0x180, active の間 _Update が毎フレーム +1
  s32 offset;            // 0x184, _Update が DAT_03002CE8 へ写し、VBlankIntr が 0x03003508 へ転送する
  u32 unk_188;           // 0x188, _Init と FUN_0804990C が 0 を入れる
  u32 unk_18c;           // 0x18C, 同上
  u32 unk_190;           // 0x190, FUN_0804990C が 0 を入れる
  u32* unk_194;          // 0x194, _Init が u32_ARRAY_085AB548 を入れ、FUN_0804990C が renderer+0x1C へ複写する
} EntityDFC6;
static_assert(sizeof(EntityDFC6) == 408);

IWRAM_DATA EntityDFC6* gEntityDFC6 = NULL;  // 0x030000C8

NAKED void FUN_08048934(unknown* param_1, u8 param_2) { INCFUNC("asm/func/FUN_08048934.inc"); }

NAKED void FUN_08048964(unknown* param_1) { INCFUNC("asm/func/FUN_08048964.inc"); }

NAKED void FUN_0804898c(unknown* param_1) { INCFUNC("asm/func/FUN_0804898c.inc"); }

NAKED s32 FUN_08048998(u8* param_1, s32 param_2) { INCFUNC("asm/func/FUN_08048998.inc"); }

NAKED void FUN_080489c4(unknown* param_1, u32 param_2) { INCFUNC("asm/func/FUN_080489c4.inc"); }

NAKED s32 FUN_08048a20(u8* param_1, u16 param_2) { INCFUNC("asm/func/FUN_08048a20.inc"); }

NAKED s32 FUN_08048a4c(u8* param_1, u16 param_2) { INCFUNC("asm/func/FUN_08048a4c.inc"); }

NAKED s32 FUN_08048a78(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_08048a78.inc"); }

NAKED s32 FUN_08048a98(char* param_1, u8* param_2, u8* param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08048a98.inc"); }

NAKED s32 FUN_08048afc(s32 param_1) { INCFUNC("asm/func/FUN_08048afc.inc"); }

NAKED void FUN_08048b28(char* param_1, s32 param_2) { INCFUNC("asm/func/FUN_08048b28.inc"); }

NAKED s32 TextBox_StrNCmp(u8* s, const char* lit, s32 n) { INCFUNC("asm/func/TextBox_StrNCmp.inc"); }

NAKED s32 TextBox_ParseDecimal(u8* s, s32 len) { INCFUNC("asm/func/TextBox_ParseDecimal.inc"); }

NAKED s32 FUN_08048c58(TextRenderer* p) { INCFUNC("asm/func/FUN_08048c58.inc"); }

NAKED u8* TextBox_FindChar(u8* s, u8 c) { INCFUNC("asm/func/TextBox_FindChar.inc"); }

NAKED s32 FUN_08048ce0(TextRenderer* p, char* text) { INCFUNC("asm/func/FUN_08048ce0.inc"); }

NAKED s32 FUN_08048d40(void) { INCFUNC("asm/func/FUN_08048d40.inc"); }

NAKED s32 FUN_08048d78(void) { INCFUNC("asm/func/FUN_08048d78.inc"); }

NAKED s32 FUN_08048da4(TextRenderer* p, u8* s) { INCFUNC("asm/func/FUN_08048da4.inc"); }

NAKED s32 FUN_08049488(TextRenderer* p, u8* s) { INCFUNC("asm/func/FUN_08049488.inc"); }

NAKED s32 TextRenderer_Advance(TextRenderer* p) { INCFUNC("asm/func/TextRenderer_Advance.inc"); }

NAKED s32 FUN_0804960c(TextRenderer* p) { INCFUNC("asm/func/FUN_0804960c.inc"); }

NAKED void FUN_08049640(TextRenderer* p) { INCFUNC("asm/func/FUN_08049640.inc"); }

NAKED void TextRenderer_SetRect(TextRenderer* p, u8 x, u8 y, u8 width, u8 height) { INCFUNC("asm/func/TextRenderer_SetRect.inc"); }

NAKED void FUN_08049668(TextRenderer* p) { INCFUNC("asm/func/FUN_08049668.inc"); }

NAKED void TextRenderer_Init(TextRenderer* p, u8 x, u8 y, u8 width, u8 height) { INCFUNC("asm/func/TextRenderer_Init.inc"); }

NAKED void TextRenderer_SetVar(TextRenderer* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/TextRenderer_SetVar.inc"); }

NAKED s32 TextRenderer_SetExtend(TextRenderer* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/TextRenderer_SetExtend.inc"); }

NAKED s32 TextRenderer_SetScriptIds(TextRenderer* p, s32 param_2, u32* param_3) { INCFUNC("asm/func/TextRenderer_SetScriptIds.inc"); }

NAKED s32 TextRenderer_GetVarWidth(TextRenderer* p, s32 param_2) { INCFUNC("asm/func/TextRenderer_GetVarWidth.inc"); }

NAKED s32 TextRenderer_GetExtendWidth(TextRenderer* p, s32 param_2) { INCFUNC("asm/func/TextRenderer_GetExtendWidth.inc"); }

NAKED void TextRenderer_ClearPending(TextRenderer* p) { INCFUNC("asm/func/TextRenderer_ClearPending.inc"); }

NAKED void TextRenderer_RunPending(TextRenderer* p) { INCFUNC("asm/func/TextRenderer_RunPending.inc"); }

NAKED void FUN_080498c8(void) { INCFUNC("asm/func/FUN_080498c8.inc"); }

NAKED void FUN_080498d4(void) { INCFUNC("asm/func/FUN_080498d4.inc"); }

NAKED s32 FUN_0804990c(EntityDFC6* p, bool32 reset) { INCFUNC("asm/func/FUN_0804990c.inc"); }

NAKED void FUN_0804996c(EntityDFC6* p) { INCFUNC("asm/func/FUN_0804996c.inc"); }

NAKED s32 FUN_08049c3c(EntityDFC6* p) { INCFUNC("asm/func/FUN_08049c3c.inc"); }

NAKED s32 FUN_08049c78(EntityDFC6* p) { INCFUNC("asm/func/FUN_08049c78.inc"); }

NAKED s32 EntityDFC6_Update(EntityDFC6* p) { INCFUNC("asm/func/EntityDFC6_Update.inc"); }

NAKED s32 EntityDFC6_Destroy(EntityDFC6* p) { INCFUNC("asm/func/EntityDFC6_Destroy.inc"); }

NAKED s32 EntityDFC6_Init(EntityDFC6* p) { INCFUNC("asm/func/EntityDFC6_Init.inc"); }

NAKED EntityDFC6* EntityDFC6_Create(void) { INCFUNC("asm/func/EntityDFC6_Create.inc"); }

NAKED s32 FUN_08049e30(u32* param_1) { INCFUNC("asm/func/FUN_08049e30.inc"); }

NAKED s32 FUN_08049e5c(void) { INCFUNC("asm/func/FUN_08049e5c.inc"); }

NAKED s32 FUN_08049e6c(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_08049e6c.inc"); }

NAKED s32 FUN_08049e94(void) { INCFUNC("asm/func/FUN_08049e94.inc"); }

NAKED s32 FUN_08049eb0(s32 param_1, s32 param_2) { INCFUNC("asm/func/FUN_08049eb0.inc"); }

NAKED s32 FUN_08049ed4(void) { INCFUNC("asm/func/FUN_08049ed4.inc"); }

NAKED s32 FUN_08049ef0(void) { INCFUNC("asm/func/FUN_08049ef0.inc"); }

NAKED s32 FUN_08049f0c(void) { INCFUNC("asm/func/FUN_08049f0c.inc"); }

NAKED s32 FUN_08049f5c(void) { INCFUNC("asm/func/FUN_08049f5c.inc"); }

NAKED s32 FUN_08049f84(void) { INCFUNC("asm/func/FUN_08049f84.inc"); }

NAKED s32 FUN_08049fa8(void) { INCFUNC("asm/func/FUN_08049fa8.inc"); }
