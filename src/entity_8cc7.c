#include "entity.h"
#include "file.h"
#include "global.h"
#include "shadow.h"
#include "sprite_aux.h"

typedef struct {
  AuxSprite sprite;        // 0x00
  u8 unk_2c[0x6E - 0x2C];  // 0x2C, まだ未解析
  u16 flags;               // 0x6E, 根拠: Entity8CC7Elem_SetFlags / _ClearFlags / _TestFlags
  u8 unk_70[0x79 - 0x70];  // 0x70, まだ未解析
  u8 noShadow;             // 0x79, 0 なら _Destroy が ParticleShadow_Remove を呼ぶ
  u8 unk_7a[2];            // 0x7A, まだ未解析
  ParticleShadow shadow;   // 0x7C, noShadow が 0 のとき生きている影
} Entity8CC7Elem;
static_assert(sizeof(Entity8CC7Elem) == 188);

typedef struct Entity8CC7 {
  Entity e;                  // 0x000, ENTITY_UNK_9
  AuxAnimFile* anim;         // 0x018, ANIM_7B03
  Entity8CC7Elem elems[20];  // 0x01C, usedMask のビットが立っている要素だけ _Destroy が片付ける
  u32 usedMask;              // 0xECC, elems[i] が使用中なら bit i が立つ, _Init が 0 クリアする
  u32 unk_ed0;               // 0xED0, _Init が 0xE10 (3600) を入れる
} Entity8CC7;
static_assert(sizeof(Entity8CC7) == 3796);

extern Entity8CC7* gEntity8CC7;  // 0x030001A4

void Entity8CC7Elem_SetFlags(Entity8CC7Elem* e, u16 bits) { e->flags |= bits; }

void Entity8CC7Elem_ClearFlags(Entity8CC7Elem* e, u16 bits) { e->flags &= ~bits; }

// 残差は 7 命令 vs 11 命令 で、原典は 0/1 を分岐で作る (!= 0 も ?1:0 もビット演算に畳まれる)
NON_MATCH bool32 Entity8CC7Elem_TestFlags(Entity8CC7Elem* e, u16 bits) {
#ifdef NONMATCHING_C
  return (e->flags & bits) != 0;
#else
  INCFUNC("asm/func/Entity8CC7Elem_TestFlags.inc");
#endif
}

NAKED Entity8CC7Elem* Entity8CC7_AllocElem(Entity8CC7* p) { INCFUNC("asm/func/Entity8CC7_AllocElem.inc"); }

NAKED void FUN_081d8a98(void) { INCFUNC("asm/func/FUN_081d8a98.inc"); }

// 8bit の向きを4方位に丸めて, 左右反転するかどうかと一緒に返す
void FUN_081d8c80(u32 angle, u8* out1, u8* out2) {
  s32 dir = (((((u16)angle + 0x20) & 0xFF) >> 6) + 1) & 3;

  if (dir > 1) {
    *out2 = 1;
    *out1 = 3 - dir;
  } else {
    *out2 = 0;
    *out1 = dir;
  }
}

NAKED s32 FUN_081d8cb0(Entity8CC7Elem* e) { INCFUNC("asm/func/FUN_081d8cb0.inc"); }

NAKED s32 FUN_081d8d20(Entity8CC7Elem* e) { INCFUNC("asm/func/FUN_081d8d20.inc"); }

// 3600フレームごとに, 時間帯が 2 より後なら TRUE を返す
// 残差5命令, 原典は != 0 側 (デクリメント) を fall-through に置くが, agbcc は if/else をどちら向きに書いても == 0 側を先に並べる
NON_MATCH bool32 FUN_081d8d90(Entity8CC7* p) {
#ifdef NONMATCHING_C
  if (p->unk_ed0 != 0) {
    p->unk_ed0--;
    return FALSE;
  }

  p->unk_ed0 = 3600;
  if (Time_GetSpanOfTime() <= 2) {
    return FALSE;
  }

  return TRUE;
#else
  INCFUNC("asm/func/FUN_081d8d90.inc");
#endif
}

void nop_081d8dc0(Entity8CC7* p, Entity8CC7Elem* e) {}

NAKED void FUN_081d8dc4(Entity8CC7* p, Entity8CC7Elem* e) { INCFUNC("asm/func/FUN_081d8dc4.inc"); }

NAKED void FUN_081d919c(Entity8CC7* p, Entity8CC7Elem* e) { INCFUNC("asm/func/FUN_081d919c.inc"); }

NAKED void FUN_081d93b0(Entity8CC7* p, Entity8CC7Elem* e) { INCFUNC("asm/func/FUN_081d93b0.inc"); }

NAKED void FUN_081d96b8(Entity8CC7* p, Entity8CC7Elem* e) { INCFUNC("asm/func/FUN_081d96b8.inc"); }

NAKED void FUN_081d98a0(Entity8CC7* p, Entity8CC7Elem* e) { INCFUNC("asm/func/FUN_081d98a0.inc"); }

void (*const PTR_ARRAY_085ae12c[6])(Entity8CC7*, Entity8CC7Elem*) = {
    nop_081d8dc0,
    FUN_081d919c,
    FUN_081d8dc4,
    FUN_081d93b0,
    FUN_081d96b8,
    FUN_081d98a0,
};  // 0x085AE12C

NAKED s32 Entity8CC7_Update(Entity8CC7* p) { INCFUNC("asm/func/Entity8CC7_Update.inc"); }

NAKED s32 Entity8CC7_Destroy(Entity8CC7* p) { INCFUNC("asm/func/Entity8CC7_Destroy.inc"); }

s32 Entity8CC7_Init(Entity8CC7* p) {
  p->anim = GetFile(DIR_ANIMATION, ANIM_7B03);
  gEntity8CC7 = p;
  p->usedMask = 0;
  p->unk_ed0 = 3600;
  return 0;
}

Entity8CC7* Entity8CC7_Create(u32 id) {
  if (gEntity8CC7 == NULL) {
    Entity8CC7* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity8CC7));

    if (p != NULL) {
      SetEntityRoutine(p, Entity8CC7_Update, Entity8CC7_Destroy);
      if (Entity8CC7_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity8CC7;
}

void ClearEntity8CC7(void) { gEntity8CC7 = NULL; }
