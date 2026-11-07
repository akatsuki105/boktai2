#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "map_inline.h"
#include "mover.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"
#include "sprite_pltt.h"
#include "trig.h"
#include "vec3.h"
#include "vm.h"

// EntityC9BC が count 個まとめて管理する要素
typedef struct {
  bool8 active;                  // 0x00, 0 以外なら使用中, FUN_0800cb7c で 0 に戻る
  u8 unk_01;                     // 0x01
  u8 unk_02;                     // 0x02, unk_46 に退避される
  u8 state;                      // 0x03, sC9BCElemUpdates の添字
  u32 timer;                     // 0x04, state を変えるたびに 0 に戻る
  u8 unk_08[0x1C - 0x08];        // 0x08, まだ未解析
  u32 unk_1c;                    // 0x1C, FUN_0800cbd0 が被弾時に 1 を入れる
  u32 unk_20;                    // 0x20, 被弾させた側の HitboxData.weakness
  u32 unk_24;                    // 0x24, 被弾させた側の HitboxData.attributes
  u16 unk_28;                    // 0x28, bit0 が立っていると FUN_0800cb7c が FUN_08002a58 を飛ばす
  u16 unk_2a;                    // 0x2A, 状態関数がビットを立てる, 退避時に 0 に戻る
  u16 zone;                      // 0x2C, '.m' が 0 以外なら置いた位置の GetZoneAt
  u16 plttIdx;                   // 0x2E, 120..124, unk_02 のビットで選ぶ
  s8 slideTiles;                 // 0x30, 風で押されて滑る残りタイル数, 弱点 bit1 なら 2 マス
  u8 slideAngle;                 // 0x31, 滑る向き (8bit 角度)
  s16 groundY;                   // 0x32, 落下先の高さ (<< 8)
  s16 unk_34;                    // 0x34, EntityC9BCElem_UpdateState2 が毎フレーム -2 し, 0 以下で state 1 へ戻す
  s16 unk_36;                    // 0x36, unk_34 の上限 (bobOffset を足した値)
  u16 unk_38;                    // 0x38, FUN_0800cd70 が 0 に戻す
  u16 shakeTimer;                // 0x3A, 0 以外の間は毎フレーム減らしながら揺らす
  u16 shakePower;                // 0x3C, 揺れ幅, shakeTimer の写し
  s16 hp;                        // 0x3E, '.l=1', 地属性で被弾するたび減り 0 以下で砕ける
  u8 unk_40;                     // 0x40, 0 以外の間は被弾を受け付けない, FUN_0800cbd0 が 10 を入れる
  u8 unk_41;                     // 0x41, FUN_0800cd70 が 10 を入れる
  u16 unk_42;                    // 0x42, '.F=-1', 炎属性で被弾すると unk_38 に写される
  bool8 releaseReq;              // 0x44, 0 以外なら EntityC9BC_Update が FUN_0800cb7c で解放する
  u8 unk_45;                     // 0x45, state の退避先
  u8 unk_46;                     // 0x46, unk_02 の退避先
  u8 unk_47;                     // 0x47
  Mover obj;                     // 0x48, obj.id は EntityC9BC_FindElemById の検索キー
  AuxSpriteGfx gfx;              // 0x8C, SPRITE_BCA8
  AuxSprite spr_a8;              // 0xA8
  AuxSpriteGfx gfx2;             // 0xD4, SPRITE_BCA8
  AuxSprite spr_f0;              // 0xF0
  MapTileOverride tileOverride;  // 0x11C
  HitboxData hurtbox;            // 0x12C
  HitboxData hitbox;             // 0x17C
  u8 unk_1cc[0x1FC - 0x1CC];     // 0x1CC, まだ未解析
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

void EntityD9AE_SpawnDust(Vec3* pos, s32 param_2);
void Entity99CA_CreateAt(Vec3* pos, s32 radius, s32 lifetime, s32 count, s32 kind);

// state を切り替えて timer を 0 に戻す
static inline void EntityC9BCElem_SetState(EntityC9BCElem* elem, u8 state) {
  elem->state = state;
  elem->timer = 0;
  elem->unk_01 = 1;
}

// unk_02 のビットから要素のパレット番号を選ぶ
static inline u16 EntityC9BCElem_GetPlttIdx(EntityC9BCElem* elem) {
  if (elem->unk_02 == 0) {
    return 120;
  }
  if (elem->unk_02 & 8) {
    return 123;
  }
  if (elem->unk_02 & 4) {
    return 124;
  }
  return (elem->unk_02 & 1) ? 121 : 122;
}

EntityC9BC* GetEntityC9BC(void) { return gEntityC9BC; }

// 枠を片付けて空きに戻す
void FUN_0800cb7c(EntityC9BC* p, EntityC9BCElem* elem) {
  if (elem->active) {
    AuxSprite_Remove(&elem->spr_a8);
    AuxSprite_Remove(&elem->spr_f0);
    Map_RemoveTileOverride(&elem->tileOverride);
    Hitbox_Unregister(&elem->hurtbox);
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
  if (a->id != b->id && (a->weakness & ((1 << WK_SWORD) | (1 << WK_SPEAR) | (1 << WK_HAMMER))) && elem->unk_40 == 0) {
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

// slideAngle の向きの隣のタイルが, 階段でなく今より低く TATTR_UNK_3 も無ければ 1 を返す
// 残差: 命令の並びはほぼ一致しレジスタ割当が違う, 原典は r6 まで使い & 3 の定数を gCollisionMap の読み込みより前に積む
NON_MATCH s32 FUN_0800cc08(EntityC9BCElem* elem) {
#ifdef NONMATCHING_C
  CollisionMapTile* self = &elem->tileOverride.tile;
  s32 dir = Angle_ToDir4(elem->slideAngle);
  s32 step = gCollisionMap->neighborOffsets[dir];
  s32 idx = GetCollisionTileIdx(&elem->obj.pos) + step;
  CollisionMapTile* tile = TileAtIndex(idx);

  if (tile != NULL && (tile->heightStairs >> 4) == 0 && (tile->heightStairs & 0xF) < (self->heightStairs & 0xF) && !(tile->attr & TATTR_UNK_3)) {
    return 1;
  }

  return 0;
#else
  INCFUNC("asm/func/FUN_0800cc08.inc");
#endif
}

// 炎属性で被弾したら炎の状態にする, state 1 なら state 3 へ移る
s32 FUN_0800ccd0(EntityC9BC* p, EntityC9BCElem* elem) {
  if (elem->state == 1) {
    if (elem->unk_02 == 0) {
      PlaySound_082406e0(SE_537);
    }
    elem->unk_02 |= 1;
    CLEAR_FLAGS(elem->unk_02, 2);
    elem->unk_38 = elem->unk_42;
    elem->state = 3;
    elem->timer = 0;
    elem->unk_01 = 1;
    elem->unk_41 = 10;
    Video_SetAuxSpritePltt(&elem->gfx, 306);
    return 1;
  }

  if (!TEST_FLAGS(elem->unk_02, 1)) {
    if (elem->unk_02 == 0) {
      PlaySound_082406e0(SE_537);
    }
    elem->unk_02 |= 1;
    CLEAR_FLAGS(elem->unk_02, 2);
    elem->unk_38 = elem->unk_42;
    elem->unk_41 = 10;
    Video_SetAuxSpritePltt(&elem->gfx, 306);
  }

  return 0;
}

// 氷属性で被弾したら, state 0 のとき凍らせて沈む state 2 へ移る
s32 FUN_0800cd70(EntityC9BC* p, EntityC9BCElem* elem) {
  if (elem->state == 0) {
    EntityC9BCElem_SetState(elem, 2);
    elem->unk_02 |= 2;
    CLEAR_FLAGS(elem->unk_02, 1);
    elem->unk_38 = 0;
    elem->unk_41 = 10;
    Video_SetAuxSpritePltt(&elem->gfx, 306);
    return 1;
  }

  return 0;
}

// 地属性で被弾したら hp を減らして揺らし, 尽きたら砕ける state 6 へ移る
s32 FUN_0800cdb4(EntityC9BC* p, EntityC9BCElem* elem) {
  elem->hp--;
  elem->shakeTimer = 10;
  if (elem->hp <= 0) {
    elem->hp = 0;
    if (elem->state <= 1) {
      elem->unk_02 |= 8;
      elem->state = 6;
      elem->timer = 0;
      elem->unk_01 = 1;
      elem->unk_41 = 10;
      Video_SetAuxSpritePltt(&elem->gfx, 306);
      PlaySound_082406e0(SONG_532);
      return 1;
    }
  } else {
    elem->unk_41 = 10;
    Video_SetAuxSpritePltt(&elem->gfx, 306);
    PlaySound_082406e0(SONG_535);
  }

  return 0;
}

NAKED s32 FUN_0800ce24(EntityC9BC* p, EntityC9BCElem* elem) { INCFUNC("asm/func/FUN_0800ce24.inc"); }

// 足元のタイルより 1 段以上浮いていたら, そこへ落ちる state 5 へ移る
// 残差: 原典は足元タイルが浮いていない側 (return 0) を成功側より前に置く, 戻り値ブロックの並びが再現できない
NON_MATCH s32 FUN_0800cf30(EntityC9BC* p, EntityC9BCElem* elem, s32 idx) {
#ifdef NONMATCHING_C
  if (idx < 0 || (idx & 1) == (elem->timer & 1)) {
    Mover* obj = &elem->obj;
    MapTileOverride* self = &elem->tileOverride;
    u16 tileIdx = self->tileIdx;
    MapTileOverride* ov = Map_FindTileOverride(tileIdx, 3);
    CollisionMapTile* tile = (ov != NULL) ? &ov->tile : &gCollisionMap->tiledata->tiles[tileIdx];
    s32 height = (tile->heightStairs & 0xF) << 8;

    if (obj->pos.y - height > 0xFF) {
      elem->groundY = height;
      elem->state = 5;
      elem->timer = 0;
      elem->unk_01 = 1;
      return 1;
    }
  }

  return 0;
#else
  INCFUNC("asm/func/FUN_0800cf30.inc");
#endif
}

NAKED void EntityC9BCElem_UpdateState0(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState0.inc"); }

NAKED void EntityC9BCElem_UpdateState1(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/EntityC9BCElem_UpdateState1.inc"); }

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
  EntityD9AE_SpawnDust(&elem->obj.pos, 0x80);
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

// groundY まで毎フレーム 16 ずつ落とし, 着地したらタイルの高さを積み直す
// 残差2命令: 原典は unk_02 & 2 を32bitのまま 0 と比べ else 側の timer にその 0 を流用するが, こちらは u8 に切り詰める lsls/lsrs が付く
NON_MATCH void EntityC9BCElem_UpdateState5(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) {
#ifdef NONMATCHING_C
  MapTileOverride* ov = &elem->tileOverride;
  Mover* obj = &elem->obj;
  s16 groundY;

  if (elem->unk_01) {
    elem->unk_01 = 0;
  }

  elem->unk_2a |= 0x10;
  obj->pos.y -= 16;
  groundY = elem->groundY;
  if (obj->pos.y < groundY) {
    s32 height;

    obj->pos.y = groundY;
    height = ((groundY >> 8) & 0xF) + 1;
    if (height > 15) {
      height = 15;
    }
    ov->tile.heightStairs = (ov->tile.heightStairs & 0xF0) | height;
    if (elem->unk_02 & 2) {
      elem->state = 1;
      elem->timer = 0;
      elem->unk_01 = 1;
      EntityD9AE_SpawnDust(&elem->obj.pos, 0x80);
      PlaySound_082406e0(SE_BLOCK_COLLISION);
    } else {
      elem->state = 0;
      elem->timer = 0;
      elem->unk_01 = 1;
      PlaySound_082406e0(SE_539);
    }
  }
#else
  INCFUNC("asm/func/EntityC9BCElem_UpdateState5.inc");
#endif
}

// 砕けて破片を散らし, 点滅させてから 32 フレームで解放を求める
void EntityC9BCElem_UpdateState6(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) {
  if (elem->unk_01) {
    Vec3 pos;
    Vec3* v;

    elem->unk_01 = 0;
    v = &pos;
    *v = elem->obj.pos;
    v->x += 0x40;
    v->z += 0x40;
    Entity99CA_CreateAt(v, 144, 40, 8, 7);
  }

  elem->unk_2a |= 0x10;
  if (elem->timer < 16) {
    if ((elem->timer & 7) == 4) {
      elem->unk_2a |= 0xC;
    }
  } else if ((elem->timer & 3) == 2) {
    elem->unk_2a |= 0xC;
  }

  if (elem->timer >= 32) {
    elem->releaseReq = TRUE;
  }
}

// 要素の state と unk_02 を退避して unk_2a を空にする
void EntityC9BCElem_SaveState(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) {
  elem->unk_2a = 0;
  elem->unk_45 = elem->state;
  elem->unk_46 = elem->unk_02;
}

NAKED void FUN_0800d480(EntityC9BC* p, EntityC9BCElem* elem, u32 idx) { INCFUNC("asm/func/FUN_0800d480.inc"); }

void (*const sC9BCElemUpdates[7])(EntityC9BC*, EntityC9BCElem*, u32) = {
    EntityC9BCElem_UpdateState0,
    EntityC9BCElem_UpdateState1,
    EntityC9BCElem_UpdateState2,
    EntityC9BCElem_UpdateState3,
    EntityC9BCElem_UpdateState4,
    EntityC9BCElem_UpdateState5,
    EntityC9BCElem_UpdateState6,
};  // 0x085AA774

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

s32 EntityC9BC_Init(EntityC9BC* p, u32 _) {
  EntityC9BCElem* elem;
  u32 i;

  gEntityC9BC = p;
  p->unk_18 = 0;
  p->elems = Malloc(p->count * sizeof(EntityC9BCElem));
  if (p->elems == NULL) {
    return -1;
  }

  ClearMemory(p->elems, p->count * sizeof(EntityC9BCElem));
  p->fadeDir = 0;
  p->fadeLevel = 0;
  p->plttBase = &gObjPlttData[120 * 16];
  p->plttBlendA = &gObjPlttData[121 * 16];
  p->plttBlendB = &gObjPlttData[122 * 16];
  CpuCopy32(p->plttBase, p->plttBufA, sizeof(p->plttBufA));
  CpuCopy32(p->plttBase, p->plttBufB, sizeof(p->plttBufB));

  elem = p->elems;
  for (i = 0; i < p->count; i++, elem++) {
    elem->active = FALSE;
  }

  return 0;
}

// 0xC9BC
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
