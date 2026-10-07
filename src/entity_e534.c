#include "entity.h"
#include "global.h"
#include "msgbus.h"
#include "shadow.h"
#include "sprite_aux.h"
#include "video.h"

typedef struct {
  bool8 active;            // 0x00, EntityE534Elem_Init が 1 を入れる, 各 UpdateState 関数は 0 以外なら状態の入り口の処理をして 0 に落とす
  u8 state;                // 0x01, sElemUpdates の添字, EntityE534Elem_Init が 0 を入れ、各 UpdateState 関数が次の番号を書く
  u8 unk_02[2];            // 0x02, まだ未解析
  u16 unk_04;              // 0x04, EntityE534Elem_Init が 0 を入れる
  s8 angle;                // 0x06, 8bit の向き, 各 UpdateState 関数が ArcTan2_8 の結果を入れ gSineTable の添字にする
  u8 unk_07[0x30 - 0x07];  // 0x07, まだ未解析
  AuxAnimState anim;       // 0x30
  AuxSprite sprite;        // 0x40
  AuxSpriteGfx gfx;        // 0x6C, SPRITE_BAT
  ParticleShadow shadow;   // 0x88, ParticleShadow_Init(&shadow, &sprite.pos, 0) のあと Hide する
} EntityE534Elem;
static_assert(sizeof(EntityE534Elem) == 200);

typedef struct {
  Entity e;                   // 0x000, ENTITY_UNK_11
  u32 unk_18;                 // 0x018, _Init が 0 を入れる
  u8 unk_1c[4];               // 0x01C, まだ未解析
  AuxAnimFile* anim;          // 0x020, ANIM_5BB7
  EntityE534Elem elems[16];   // 0x024
  u8 unk_ca4[2];              // 0xCA4, まだ未解析
  u16 unk_ca6;                // 0xCA6, _Init が 0 を入れる
  rgb555 pltt[16];            // 0xCA8, BlendPltt(&pltt, gObjPlttData+0x2630, gObjPlttData+0x2650, 0x40, 6), elems[i].gfx.pltt がここを指す
  u32 unk_cc8;                // 0xCC8, _Init が 0 を入れる
  u8 unk_ccc[0xCD4 - 0xCCC];  // 0xCCC, まだ未解析
  EntityMsgBox msgbox;        // 0xCD4
} EntityE534;
static_assert(sizeof(EntityE534) == 3336);

// 要素1つ分のスプライトと影を用意して、状態を0番から始める
// 残差は 49 命令 vs 47 命令 で、原典は gfx->pltt を AuxSpriteGfx* 経由の [r4, #0xc] で書く (こちらは e からの [r7, #0x78] になる)
// ポインタのローカルを2本立てると今度はレジスタが1本足りなくなって 54 命令に増える
NON_MATCH s32 EntityE534Elem_Init(EntityE534* p, EntityE534Elem* e) {
#ifdef NONMATCHING_C
  e->state = 0;
  e->active = TRUE;
  e->unk_04 = 0;
  e->angle = 0;

  Video_GetAuxSprite(&e->gfx, SPRITE_BAT);
  Video_SetAuxSpritePltt(&e->gfx, 611);
  e->gfx.pltt = p->pltt;
  AuxSprite_Add(&e->sprite, &e->gfx, SPRFLAG_HIDDEN);
  e->sprite.priority = 2;
  CpuFill32(0, &e->sprite.pos, sizeof(Vec3));
  ParticleShadow_Init(&e->shadow, &e->sprite.pos, 0);
  ParticleShadow_Hide(&e->shadow);
#else
  INCFUNC("asm/func/EntityE534Elem_Init.inc");
#endif
}

// 要素の影とスプライトを描画リストから外す
s32 EntityE534Elem_Destroy(EntityE534* p, EntityE534Elem* e, s32 idx) {
  ParticleShadow_Remove(&e->shadow);
  AuxSprite_Remove(&e->sprite);
}

// 要素の向きから象限を出して、アニメーションの variant と flags をそれで決めて再生を始める
// 残差は 38 命令 vs 48 命令 で、原典は variant と flags に sp+4 / sp+5 のスタック枠を与えて呼び出し直前に読み直す (こちらはレジスタに残る)
NON_MATCH void EntityE534Elem_SetAnim(EntityE534* p, EntityE534Elem* e, s32 animIdx) {
#ifdef NONMATCHING_C
  u16 angle = e->angle;
  s32 q = ((((angle + 0x20) & 0xFF) >> 6) + 1) & 3;
  u8 variant = ((u8)(q - 1) <= 1) ? 1 : 0;
  AuxAnimPlayFlags flags = (q > 1) ? 1 : 0;

  AuxAnim_SetAnim(&e->anim, p->anim, animIdx, variant, flags);
#else
  INCFUNC("asm/func/EntityE534Elem_SetAnim.inc");
#endif
}

NAKED void EntityE534Elem_UpdateSprite(EntityE534Elem* e) { INCFUNC("asm/func/EntityE534Elem_UpdateSprite.inc"); }

NAKED s32 EntityE534_HandleCmd0(EntityE534* p, EntityMsgBox* box, EntityMsg* msg) { INCFUNC("asm/func/EntityE534_HandleCmd0.inc"); }

NAKED s32 EntityE534_HandleCmd1(EntityE534* p, EntityMsgBox* box, EntityMsg* msg) { INCFUNC("asm/func/EntityE534_HandleCmd1.inc"); }

NAKED s32 EntityE534_HandleCmd2(EntityE534* p, EntityMsgBox* box, EntityMsg* msg) { INCFUNC("asm/func/EntityE534_HandleCmd2.inc"); }

NAKED s32 EntityE534_HandleMsgs(EntityE534* p) { INCFUNC("asm/func/EntityE534_HandleMsgs.inc"); }

NAKED void EntityE534Elem_UpdateState0(EntityE534* p, EntityE534Elem* e, s32 idx) { INCFUNC("asm/func/EntityE534Elem_UpdateState0.inc"); }

NAKED void EntityE534Elem_UpdateState2(EntityE534* p, EntityE534Elem* e, s32 idx) { INCFUNC("asm/func/EntityE534Elem_UpdateState2.inc"); }

NAKED void EntityE534Elem_UpdateState1(EntityE534* p, EntityE534Elem* e, s32 idx) { INCFUNC("asm/func/EntityE534Elem_UpdateState1.inc"); }

NAKED void EntityE534Elem_UpdateState3(EntityE534* p, EntityE534Elem* e, s32 idx) { INCFUNC("asm/func/EntityE534Elem_UpdateState3.inc"); }

NAKED void EntityE534Elem_UpdateState4(EntityE534* p, EntityE534Elem* e, s32 idx) { INCFUNC("asm/func/EntityE534Elem_UpdateState4.inc"); }

NAKED void EntityE534Elem_UpdateState5(EntityE534* p, EntityE534Elem* e, s32 idx) { INCFUNC("asm/func/EntityE534Elem_UpdateState5.inc"); }

NAKED void EntityE534Elem_UpdateState6(EntityE534* p, EntityE534Elem* e, s32 idx) { INCFUNC("asm/func/EntityE534Elem_UpdateState6.inc"); }

static void (*const sElemUpdates[7])(EntityE534*, EntityE534Elem*, s32) = {
    EntityE534Elem_UpdateState0, EntityE534Elem_UpdateState1, EntityE534Elem_UpdateState2, EntityE534Elem_UpdateState3, EntityE534Elem_UpdateState4, EntityE534Elem_UpdateState5, EntityE534Elem_UpdateState6,
};  // 0x085AA81C

NAKED s32 EntityE534_Update(EntityE534* p) { INCFUNC("asm/func/EntityE534_Update.inc"); }

s32 EntityE534_Destroy(EntityE534* p) {
  EntityE534Elem* e = p->elems;
  s32 i;

  for (i = 0; i < 16; i++, e++) {
    EntityE534Elem_Destroy(p, e, i);
  }

  EntityMsgBus_Unregister(&p->msgbox);
  return 0;
}

NAKED s32 EntityE534_Init(EntityE534* p, u32 id) { INCFUNC("asm/func/EntityE534_Init.inc"); }

EntityE534* EntityE534_Create(u32 id) {
  EntityE534* p = CreateEntity(ENTITY_UNK_11, sizeof(EntityE534));

  if (p != NULL) {
    SetEntityRoutine(p, EntityE534_Update, EntityE534_Destroy);
    if (EntityE534_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
