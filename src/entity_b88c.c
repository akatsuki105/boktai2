#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "sprite_main.h"
#include "text.h"
#include "video.h"
#include "vm.h"

s32 FUN_08049f84(void);

extern s32 s32_030000d4;

s32 FUN_08049e30(char* str);
s32 FUN_08049f5c(void);

// 上下で項目を選ぶメニュー
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_11
  u32 params[4];          // 0x018, '.p' の4値, キーワードが無ければ末尾から 0 クリアされる
  u8 state;               // 0x028, PTR_ARRAY_085ab584 の添字
  bool8 stateChanged;     // 0x029, 各ハンドラの入り口で1回だけ行う処理用
  s8 cursor;              // 0x02A, 選択中の項目, 負なら count-1、count 以上なら 0 に折り返す
  u8 prevCursor;          // 0x02B, 前回描画した cursor, 変わったときだけ貼り替える
  u8 count;               // 0x02C, 項目数, gSystemSaveData->unk_10 が 0x369F なら 3、でなければ 2
  u8 unk_2d;              // 0x02D, まだ未解析
  u8 unk_2e;              // 0x02E, まだ未解析
  u8 result;              // 0x02F, A なら cursor、B なら 3 が入る選択結果
  u16* unk_30;            // 0x030, u16_ARRAY_085ab564 が入る
  u32 timer;              // 0x034, 毎フレーム +1, 30 を超えてから A/B を受け付ける
  MainSpriteGfx gfx;      // 0x038, SPRITE_UI_LINK
  MainSprite sprites[3];  // 0x058
  u16 animTimer;          // 0x178, 毎フレーム +1, u16_ARRAY_085ab598[animIdx] に達したら 0 に戻る
  u16 animIdx;            // 0x17A, 0..5 を巡回し、u16_ARRAY_085ab5a4[animIdx] を pltt[12] に書く
  rgb555 pltt[128];       // 0x17C, gObjPlttData + 0x2930 から 0x100 バイトコピー, sprites[].pltt が指す
  s32 panelID;            // 0x27C, TextPanel_Destroy に渡る
  u8* script;             // 0x280, '.r', NULL なら EntityB88C_Init が失敗する
} EntityB88C;
static_assert(sizeof(EntityB88C) == 644);

const u16 u16_ARRAY_085ab564[16] = {
    0x200, 0x100, 0x200, 0x100, 0x200, 0x200, 0x100, 0x100, 0x100, 0x100, 0x200, 0x200, 0x4, 0x8, 0x4, 0x8,
};  // 0x085AB564

void FUN_0804ac7c(EntityB88C* p);
void FUN_0804ad40(EntityB88C* p);
void FUN_0804add8(EntityB88C* p);
void FUN_0804aecc(EntityB88C* p);
void FUN_0804af38(EntityB88C* p);

void (*const PTR_ARRAY_085ab584[5])(EntityB88C*) = {
    FUN_0804ac7c, FUN_0804ad40, FUN_0804add8, FUN_0804aecc, FUN_0804af38,
};  // 0x085AB584

const u16 u16_ARRAY_085ab598[6] = {10, 8, 8, 8, 8, 8};  // 0x085AB598

const u16 u16_ARRAY_085ab5a4[6] = {31, 27, 18, 10, 18, 27};  // 0x085AB5A4

s32 FUN_0804aa30(EntityB88C* p, s32 param_2) {
  s32 bgIndex = param_2;

  Video_SetupBGLayout(1, 0, GetFile(DIR_TILE_MAP, TILEMAP_CD91), 0, 0, 1, &bgIndex);
  Video_GenerateBGMap(2, 0, 0, 0, 0);
  CpuCopy16((u8*)GetFile(DIR_BGPLTT, 0x26BB) + 0x14, gBgPlttBuffer, 512);
  return 0;
}

s32 FUN_0804aa98(EntityB88C* p, s32 param_2) {
  s32 bgIndex = param_2;

  Video_SetupBGLayout(0, 0, GetFile(DIR_TILE_MAP, TILEMAP_A413), 0, 0, 1, &bgIndex);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  CpuCopy16((rgb555*)GetFile(DIR_BGPLTT, 0xEFDA) + 218, &gBgPlttBuffer[208], 96);
  return 0;
}

// count 未満の項目だけ表示する
void FUN_0804ab00(EntityB88C* p) {
  MainSprite* spr = p->sprites;
  s32 i;

  for (i = 0; i < 3; i++, spr++) {
    if (i < p->count) {
      spr->flags &= ~1;
    } else {
      spr->flags |= 1;
    }
  }
}

// A で選択を確定、B で取り消して state 4 へ進める, どちらも押されていなければ 0
NON_MATCH s32 EntityB88C_ConfirmOrCancel(EntityB88C* p) {
#ifdef NONMATCHING_C
  if (gInput[0].pressed & A_BUTTON) {
    s32_030000d4 = p->cursor;
    p->result = p->cursor;
  } else if (gInput[0].pressed & B_BUTTON) {
    p->result = 3;
  } else {
    return 0;
  }

  p->state = 4;
  p->stateChanged = TRUE;
  p->timer = 0;
  return 1;
#else
  INCFUNC("asm/func/EntityB88C_ConfirmOrCancel.inc");
#endif
}

NAKED void EntityB88C_MoveCursor(EntityB88C* p) { INCFUNC("asm/func/EntityB88C_MoveCursor.inc"); }

NAKED void FUN_0804ac7c(EntityB88C* p) { INCFUNC("asm/func/FUN_0804ac7c.inc"); }

NAKED void FUN_0804ad40(EntityB88C* p) { INCFUNC("asm/func/FUN_0804ad40.inc"); }

NAKED void FUN_0804add8(EntityB88C* p) { INCFUNC("asm/func/FUN_0804add8.inc"); }

NON_MATCH void FUN_0804aecc(EntityB88C* p) {
#ifdef NONMATCHING_C
  s32 line;

  if (p->stateChanged) {
    p->stateChanged = FALSE;
    p->count = 3;
    FUN_0804aa30(p, 0);
    line = p->cursor + 1;
    FUN_08049e30(Textbox_LookupString(VM_ParseStringRef(p->script) + line));
    FUN_08049f5c();
    FUN_0804ab00(p);
  }

  if (p->timer > 0x1E) {
    if (EntityB88C_ConfirmOrCancel(p)) {
      return;
    }
  }

  EntityB88C_MoveCursor(p);
  p->timer++;
#else
  INCFUNC("asm/func/FUN_0804aecc.inc");
#endif
}

NAKED void FUN_0804af38(EntityB88C* p) { INCFUNC("asm/func/FUN_0804af38.inc"); }

NAKED s32 EntityB88C_Update(EntityB88C* p) { INCFUNC("asm/func/EntityB88C_Update.inc"); }

s32 EntityB88C_Destroy(EntityB88C* p) {
  MainSprite* spr = p->sprites;
  s32 i;

  for (i = 0; i < 3; i++, spr++) {
    MainSprite_Remove(spr);
  }

  FUN_08049f84();
  TextPanel_Destroy(p->panelID);
  return 0;
}

NAKED s32 EntityB88C_Init(EntityB88C* p) { INCFUNC("asm/func/EntityB88C_Init.inc"); }

EntityB88C* EntityB88C_Create(void) {
  EntityB88C* p = CreateEntity(ENTITY_UNK_11, sizeof(EntityB88C));

  if (p != NULL) {
    SetEntityRoutine(p, EntityB88C_Update, EntityB88C_Destroy);
    if (EntityB88C_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
