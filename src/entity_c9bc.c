#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "mover.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

// EntityC9BC が count 個まとめて管理する要素
typedef struct {
  bool8 active;  // 0x00, 0 以外なら使用中, FUN_0800cb7c で 0 に戻る
  u8 unk_01;
  u8 unk_02;  // 0x02, 根拠: EntityC9BCElem_SaveState が unk_46 に退避する
  u8 state;   // 0x03, sC9BCElemUpdates の添字
  u32 timer;  // 0x04, state を変えるたびに 0 に戻る
  u8 unk_08[0x1C - 0x08];
  u32 unk_1c;  // 0x1C, FUN_0800cbd0 が被弾時に 1 を入れる
  u32 unk_20;  // 0x20, 被弾させた側の HitboxData.weakness
  u32 unk_24;  // 0x24, 被弾させた側の HitboxData.attributes
  u16 unk_28;  // 0x28, bit0 が立っていると FUN_0800cb7c が FUN_08002a58 を飛ばす
  u16 unk_2a;  // 0x2A, 根拠: EntityC9BCElem_SaveState が 0 に戻し、各 UpdateState 関数がビットを立てる
  u8 unk_2c[0x34 - 0x2C];
  s16 unk_34;  // 0x34, EntityC9BCElem_UpdateState2 が毎フレーム -2 し, 0 以下で state 1 へ戻す
  s16 unk_36;  // 0x36, unk_34 の上限 (bobOffset を足した値)
  u16 unk_38;  // 0x38, FUN_0800cd70 が 0 に戻す
  u8 unk_3a[0x40 - 0x3A];
  u8 unk_40;  // 0x40, 0 以外の間は被弾を受け付けない, FUN_0800cbd0 が 10 を入れる
  u8 unk_41;  // 0x41, FUN_0800cd70 が 10 を入れる
  u8 unk_42[0x44 - 0x42];
  bool8 releaseReq;  // 0x44, 0 以外なら EntityC9BC_Update が FUN_0800cb7c で解放する
  u8 unk_45;         // 0x45, 根拠: EntityC9BCElem_SaveState が state を退避する
  u8 unk_46;         // 0x46, 根拠: EntityC9BCElem_SaveState が unk_02 を退避する
  u8 unk_47;
  Mover obj;         // 0x48, 根拠: FUN_0800cb7c, obj.id は EntityC9BC_FindElemById の検索キー
  AuxSpriteGfx gfx;  // 0x8C, 根拠: FUN_0800ccd0 が Video_SetAuxSpritePltt に渡す
  AuxSprite spr_a8;  // 0xA8, 根拠: FUN_0800cb7c
  u8 unk_d4[0xF0 - 0xD4];
  AuxSprite spr_f0;              // 0xF0, 根拠: FUN_0800cb7c
  MapTileOverride tileOverride;  // 0x11C
  HitboxData hitbox;             // 0x12C, 根拠: FUN_0800cb7c
  u8 unk_17c[0x1FC - 0x17C];
} EntityC9BCElem;
static_assert(sizeof(EntityC9BCElem) == 508);

// count 個の要素を状態関数で動かし、全体をサイン波で上下に揺らしながら、パレット 120 と 121 / 122 の間で色を点滅させる
typedef struct {
  Entity e;               // ENTITY_UNK_9
  u32 unk_18;             // 0x18, EntityC9BC_Init で 0 を入れるだけ
  u32 count;              // 0x1C, '.m=4', 要素数
  s16 bobOffset;          // 0x20, sin(bobAngle) * 16, 各要素の高さに加算される
  u8 bobAngle;            // 0x22, gSineTable の添字, 毎フレーム +2
  u8 fadeDir;             // 0x23, 0 なら fadeLevel を増やし 32 で 1 に, 1 なら減らし 0 で 0 に戻る
  s16 fadeLevel;          // 0x24, 0..32, BlendPltt の混合率
  u8 unk_26[2];           // 0x26, padding?
  rgb555* plttBase;       // 0x28, &gObjPlttData[120 * 16]
  rgb555* plttBlendA;     // 0x2C, &gObjPlttData[121 * 16]
  rgb555* plttBlendB;     // 0x30, &gObjPlttData[122 * 16]
  rgb555 plttBufA[16];    // 0x34, plttBase と plttBlendA の中間色, 要素のパレットが 121 のとき使う
  rgb555 plttBufB[16];    // 0x54, plttBase と plttBlendB の中間色
  EntityC9BCElem* elems;  // 0x74, Malloc(count * sizeof(EntityC9BCElem))
} EntityC9BC;
static_assert(sizeof(EntityC9BC) == 120);

COMMON_DATA EntityC9BC* gEntityC9BC = NULL;  // 0x03002B38

void EntityC9BCElem_UpdateState0(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void EntityC9BCElem_UpdateState1(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void EntityC9BCElem_UpdateState2(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void EntityC9BCElem_UpdateState3(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void EntityC9BCElem_UpdateState4(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void EntityC9BCElem_UpdateState5(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);
void EntityC9BCElem_UpdateState6(EntityC9BC* p, EntityC9BCElem* elem, u32 idx);

void (*const sC9BCElemUpdates[7])(EntityC9BC*, EntityC9BCElem*, u32) = {
    EntityC9BCElem_UpdateState0,
    EntityC9BCElem_UpdateState1,
    EntityC9BCElem_UpdateState2,
    EntityC9BCElem_UpdateState3,
    EntityC9BCElem_UpdateState4,
    EntityC9BCElem_UpdateState5,
    EntityC9BCElem_UpdateState6,
};  // 0x085aa774

EntityC9BC* GetEntityC9BC(void) { return gEntityC9BC; }

// 枠を片付けて空きに戻す
void FUN_0800cb7c(EntityC9BC* p, EntityC9BCElem* elem) {
  if (elem->active) {
    AuxSprite_Remove(&elem->spr_a8);
    AuxSprite_Remove(&elem->spr_f0);
    Map_RemoveTileOverride(&elem->tileOverride);
    Hitbox_Unregister(&elem->hitbox);
    if (!(elem->unk_28 & 1)) {
      FUN_08002a58(&elem->obj);
    }
    Mover_Unlink(&elem->obj);
    elem->active = FALSE;
  }
}

// 残差0命令 (26/26), レジスタ名だけ違う: 原典は weakness をスクラッチ (r1) に置くが, こちらは r4 に載る
NON_MATCH void FUN_0800cbd0(HitboxData* a, HitboxData* b, EntityC9BCElem* elem) {
#ifdef NONMATCHING_C
  if (a->id != b->id && (a->weakness & 7) && elem->unk_40 == 0) {
    elem->unk_1c = 1;
    elem->unk_20 = a->weakness;
    elem->unk_24 = a->attributes;
    elem->unk_40 = 10;
  }
#else
  INCFUNC("asm/func/FUN_0800cbd0.inc");
#endif
}

void nop_0800cc04(void) {}

NAKED s32 FUN_0800cc08(EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800cc08.inc"); }

NAKED s32 FUN_0800ccd0(EntityC9BC* p, EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800ccd0.inc"); }

// 残差1命令 (31/32): 原典は定数 2 を state 用と unk_02 のビット用に別々に積むが, agbcc は1本に畳む
NON_MATCH s32 FUN_0800cd70(EntityC9BC* p, EntityC9BCElem* elem) {
#ifdef NONMATCHING_C
  if (elem->state == 0) {
    elem->state = 2;
    elem->timer = 0;
    elem->unk_01 = 1;
    elem->unk_02 = (elem->unk_02 | 2) & ~1;
    elem->unk_38 = 0;
    elem->unk_41 = 10;
    Video_SetAuxSpritePltt(&elem->gfx, 306);
    return 1;
  }

  return 0;
#else
  INCFUNC("asm/func/FUN_0800cd70.inc");
#endif
}

NAKED s32 FUN_0800cdb4(EntityC9BC* p, EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800cdb4.inc"); }

NAKED s32 FUN_0800ce24(EntityC9BC* p, EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800ce24.inc"); }

NAKED s32 FUN_0800cf30(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/FUN_0800cf30.inc"); }

NAKED void EntityC9BCElem_UpdateState0(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState0.inc"); }

NAKED void EntityC9BCElem_UpdateState1(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState1.inc"); }

void FUN_08003014(Vec3* pos, s32 param_2);

void EntityC9BCElem_UpdateState2(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) {
  if (elem->unk_01 != 0) {
    elem->unk_01 = 0;
    PlaySound_082406e0(SE_536);
  }
  elem->unk_2a |= 0x10;
  elem->unk_34 -= 2;
  if (elem->unk_34 > 0) {
    return;
  }
  elem->unk_34 = 0;
  elem->state = 1;
  elem->timer = 0;
  elem->unk_01 = 1;
  FUN_08003014(&elem->obj.pos, 0x80);
}

// unk_34 を上限まで毎フレーム +2 で戻し, 届いたら state 0 へ
void EntityC9BCElem_UpdateState3(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) {
  s32 target;

  if (elem->unk_01) {
    elem->unk_01 = 0;
    PlaySound_082406e0(SE_538);
  }

  elem->unk_2a |= 0x10;
  target = elem->unk_36 + p->bobOffset;
  elem->unk_34 += 2;
  if (elem->unk_34 >= target) {
    elem->unk_34 = target;
    elem->state = 0;
    elem->timer = 0;
    elem->unk_01 = 1;
  }
}

NAKED void EntityC9BCElem_UpdateState4(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState4.inc"); }

NAKED void EntityC9BCElem_UpdateState5(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState5.inc"); }

NAKED void EntityC9BCElem_UpdateState6(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState6.inc"); }

// 要素の state と unk_02 を退避して unk_2a を空にする
void EntityC9BCElem_SaveState(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) {
  elem->unk_2a = 0;
  elem->unk_45 = elem->state;
  elem->unk_46 = elem->unk_02;
}

NAKED void FUN_0800d480(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/FUN_0800d480.inc"); }

NAKED s32 EntityC9BC_Update(EntityC9BC* p) { INCFUNC("asm/func/EntityC9BC_Update.inc"); }

s32 EntityC9BC_Destroy(EntityC9BC* p) {
  EntityC9BCElem* elem = p->elems;
  u32 i;

  for (i = 0; i < p->count; i++, elem++) {
    FUN_0800cb7c(p, elem);
  }

  if (p->elems != NULL) {
    Free(p->elems);
    p->elems = NULL;
  }

  gEntityC9BC = NULL;
  return 0;
}

NAKED s32 EntityC9BC_Init(EntityC9BC* p, u32 _) { INCFUNC("asm/func/EntityC9BC_Init.inc"); }

EntityC9BC* EntityC9BC_Create(u32 val) {
  EntityC9BC* p = GetEntityC9BC();

  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_9, sizeof(EntityC9BC));
  if (p != NULL) {
    SetEntityRoutine(p, EntityC9BC_Update, EntityC9BC_Destroy);
    p->count = VM_GetNamedArgValue('m', 4);
    if (EntityC9BC_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}

// 空いている要素を1つ返す, 全部使用中なら NULL
EntityC9BCElem* EntityC9BC_FindFreeElem(EntityC9BC* p) {
  EntityC9BCElem* elem = p->elems;
  u32 i;

  for (i = 0; i < p->count; i++, elem++) {
    if (!elem->active) {
      return elem;
    }
  }

  return NULL;
}

// 使用中の要素から obj.id が一致するものを返す, 無ければ NULL
EntityC9BCElem* EntityC9BC_FindElemById(EntityC9BC* p, u32 id) {
  EntityC9BCElem* elem = p->elems;
  u32 i;

  for (i = 0; i < p->count; i++, elem++) {
    if (elem->active && elem->obj.id == id) {
      return elem;
    }
  }

  return NULL;
}

// 0xA062
NAKED s32 Cmd_A062(void) { INCFUNC("asm/func/Cmd_A062.inc"); }
