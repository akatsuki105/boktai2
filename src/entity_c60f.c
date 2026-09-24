#include "collision_map.h"
#include "entity.h"
#include "entity_f1f9.h"
#include "file.h"
#include "global.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "struct.h"

// src/entity_f1f9.c
void FUN_081d5820(EntityF1F9Item* item, u16 n);
bool8 FUN_081d5848(EntityF1F9Item* item, u16 n);

// EntityC60FItem.flags
typedef u32 EntityC60FItemFlags;
#define C60FITEM_TILE_OVERRIDE (1 << 5)  // 衝突タイルの上書きを持っている。落とすときに FUN_082342a8 で取り消す
#define C60FITEM_FIXED_AREA (1 << 7)     // state を回さず unk_10a を gStat->unk_248 と比べる

// EntityC60F が抱える要素。Malloc(0x11C) で確保され、空きスロットに入る
typedef struct EntityC60FItem {
  AuxSprite sprite;              // 0x000, EntityC60F_Destroy が要素そのものを AuxSprite_Remove に渡す
  u8 unk_2c[28];                 // 0x02C
  Entity2UnkData unk_48;         // 0x048, _Destroy が FUN_08002a58(&unk_48) と FUN_0823b284(&unk_48) に渡す
  u8 unk_8c[16];                 // 0x08C
  Vec3 pos;                      // 0x09C, Hitbox_SetPos に渡す
  HitboxData hitbox;             // 0x0A4, FUN_081d6eb8 が組み立てる
  u8 unk_f4[8];                  // 0x0F4
  u16 slotIndex;                 // 0x0FC, 確保時に自分のスロット番号が入る
  s16 state;                     // 0x0FE, _Update が PTR_FUN_081D6F60_085AE118[state](item) を呼ぶ
  EntityC60FItemFlags flags;     // 0x100
  u8 unk_104[4];                 // 0x104
  u8 unk_108;                    // 0x108, 0 でないときだけ _Destroy が FUN_08002a58 / FUN_0823b284 を呼ぶ
  u8 unk_109;                    // 0x109
  u16 unk_10a;                   // 0x10A, unk_100 の bit7 が立っているとき gStat->unk_248 と比較される
  MapTileOverride tileOverride;  // 0x10C, unk_100 の bit5 が立っているとき _Destroy が FUN_082342a8 に渡す
} EntityC60FItem;
static_assert(sizeof(EntityC60FItem) == 284);

// 最大32個の EntityC60FItem をビットマスクで管理するシングルトン
typedef struct EntityC60F {
  Entity e;                   // 0x00, ENTITY_UNK_10
  void* animFile0;            // 0x18, GetFile(DIR_ANIMATION, 0x1003)
  void* animFile1;            // 0x1C, GetFile(DIR_ANIMATION, 0x931E)
  EntityC60FItem* items[32];  // 0x20, _Update と _Destroy が32スロットを走査する
  u32 activeMask;             // 0xA0, bit i が立っていれば items[i] が確保済み
  u8 unk_a4;                  // 0xA4, _Init と _Update が 0xFF を書く。読み手が見つかっていない
  u8 unk_a5[3];               // 0xA5
} EntityC60F;
static_assert(sizeof(EntityC60F) == 168);

extern EntityC60F* gEntityC60F;  // 0x0300019C

// 被弾中はスプライトを基準位置から ±10 の範囲で揺らす
void FUN_081d6444(EntityF1F9Item* item) {
  if (item->unk_157 == 0) {
    item->sprite.pos = item->basePos;
  } else {
    u16* table = gRandomTable;

    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    item->sprite.pos.x = item->basePos.x + Mod(table[gRandTableIdx], 20) - 10;
    gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
    item->sprite.pos.z = item->basePos.z + Mod(table[gRandTableIdx], 20) - 10;
    item->unk_157--;
  }
}

NAKED void FUN_081d64d4(unknown* p) { INCFUNC("asm/func/FUN_081d64d4.inc"); }

NAKED void FUN_081d65e8(unknown* p) { INCFUNC("asm/func/FUN_081d65e8.inc"); }

void FUN_081d66c0(EntityF1F9Item* item, u32 power, u32 attributes, u32 weakness) {
  HitboxData* hitbox = &item->hitbox;
  Vec3 offset;
  Vec3 halfSize;

  offset.x = 0, offset.y = 0x50, offset.z = 0;
  halfSize.x = 0x40, halfSize.y = 0x50, halfSize.z = 0x40;
  hitbox->unk_4 = item->unk_150;
  Hitbox_Init(hitbox, 0, HBFLAG_UNK_14 | HBFLAG_UNK_12 | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hitbox, power, attributes, weakness);
  Hitbox_SetPos(hitbox, &item->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_081d64d4, item);
  Hitbox_Register(hitbox);
}

NAKED void FUN_081d6764(unknown* p) { INCFUNC("asm/func/FUN_081d6764.inc"); }

NAKED void FUN_081d6ae8(EntityF1F9Item* item, s32 n) { INCFUNC("asm/func/FUN_081d6ae8.inc"); }

// 終端まで動いたら状態を切り替える
void FUN_081d6bc0(EntityF1F9Item* item) {
  if (item->unk_13d > item->unk_13c) {
    s32 d = item->unk_142 - item->unk_140;

    if (!FUN_081d5848(item, 1)) {
      FUN_081d6ae8(item, 2);
    }
    if (d >= item->unk_13a * (item->unk_13c - 1)) {
      FUN_081d6ae8(item, 1);
    }
  }
}

static inline void Vec3_Sub(Vec3* out, Vec3* a, Vec3* b) {
  out->x = a->x - b->x;
  out->y = a->y - b->y;
  out->z = a->z - b->z;
}

// プレイヤーが一定距離まで近づいたら起動する
NON_MATCH void FUN_081d6c24(EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  if (!FUN_081d5848(item, 1)) {
    Vec3 d;
    s32 dist2;

    Vec3_Sub(&d, &gPlayerPtr[0]->unk_24.pos, &item->sprite.pos);
    dist2 = d.x * d.x + d.z * d.z;
    item->unk_130 = dist2;
    if (dist2 < item->unk_134) {
      FUN_081d6ae8(item, 2);
      FUN_081d5820(item, 1);
      PlaySound_082406e0(0x3C7);
    }
  }
#else
  INCFUNC("asm/func/FUN_081d6c24.inc");
#endif
}

// プレイヤーとの距離を測り直し、反応する距離まで近づいていれば 1 を返す
NON_MATCH s32 FUN_081d6cb0(EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  Vec3 d;
  s32 dist2;

  Vec3_Sub(&d, &gPlayerPtr[0]->unk_24.pos, &item->basePos);
  item->unk_12c = item->unk_130;
  dist2 = d.x * d.x + d.z * d.z;
  item->unk_130 = dist2;
  if (dist2 < item->unk_134) {
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081d6cb0.inc");
#endif
}

NAKED void FUN_081d6d28(unknown* p) { INCFUNC("asm/func/FUN_081d6d28.inc"); }

// 種別に応じた大きさで当たり判定を作る
NON_MATCH void FUN_081d6eb8(EntityC60FItem* p) {
#ifdef NONMATCHING_C
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize;
  Vec3 offset;
  s32 radius;
  s32 height;

  if (p->unk_109 == 1) {
    radius = 0x56;
    height = 0x80;
  } else {
    radius = 0x60;
    height = 0x10;
  }
  halfSize.x = radius, halfSize.y = height, halfSize.z = radius;
  offset.x = 0, offset.y = height, offset.z = 0;
  Hitbox_Init(hitbox, 0, HBFLAG_UNK_14 | HBFLAG_UNK_1 | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &p->pos, 0);
  Hitbox_SetHandler(hitbox, FUN_081d6d28, p);
  Hitbox_Register(hitbox);
#else
  INCFUNC("asm/func/FUN_081d6eb8.inc");
#endif
}

// state 0 のハンドラ。何もしない
void FUN_081d6f60(EntityC60FItem* p) {}

NAKED s32 FUN_081d6f64(unknown* p) { INCFUNC("asm/func/FUN_081d6f64.inc"); }

NAKED void FUN_081d6fd4(unknown* p) { INCFUNC("asm/func/FUN_081d6fd4.inc"); }

NAKED void FUN_081d7358(EntityC60FItem* p) { INCFUNC("asm/func/FUN_081d7358.inc"); }

NAKED void FUN_081d76bc(EntityC60FItem* p) { INCFUNC("asm/func/FUN_081d76bc.inc"); }

static inline bool32 EntityC60FItem_TestFlags(EntityC60FItem* p, EntityC60FItemFlags n) {
  if (p->flags & n) {
    return TRUE;
  }
  return FALSE;
}

static inline void EntityC60FItem_ClearFlags(EntityC60FItem* p, EntityC60FItemFlags n) { p->flags &= ~n; }

// 生成した衝突タイルの上書きを取り消す
NON_MATCH void FUN_081d7814(EntityC60FItem* p) {
#ifdef NONMATCHING_C
  if (p->state == 3 || p->state == 4) {
    if (EntityC60FItem_TestFlags(p, C60FITEM_TILE_OVERRIDE)) {
      FUN_082342a8(&p->tileOverride);
      EntityC60FItem_ClearFlags(p, C60FITEM_TILE_OVERRIDE);
    }
  }
#else
  INCFUNC("asm/func/FUN_081d7814.inc");
#endif
}

NAKED void FUN_081d785c(EntityC60FItem* p) { INCFUNC("asm/func/FUN_081d785c.inc"); }

NAKED void FUN_081d7a60(EntityC60FItem* p) { INCFUNC("asm/func/FUN_081d7a60.inc"); }

NAKED void FUN_081d7ca8(unknown* p) { INCFUNC("asm/func/FUN_081d7ca8.inc"); }

NAKED s32 EntityC60F_Update(EntityC60F* p) { INCFUNC("asm/func/EntityC60F_Update.inc"); }

NAKED s32 EntityC60F_Destroy(EntityC60F* p) { INCFUNC("asm/func/EntityC60F_Destroy.inc"); }

s32 EntityC60F_Init(EntityC60F* p) {
  p->animFile0 = GetFile(DIR_ANIMATION, 0x1003);
  p->animFile1 = GetFile(DIR_ANIMATION, 0x931E);
  gEntityC60F = p;
  p->activeMask = 0;
  p->unk_a4 = 255;
  return 0;
}

EntityC60F* EntityC60F_Create(void) {
  EntityC60F* p = CreateEntity(ENTITY_UNK_10, sizeof(EntityC60F));

  if (p != NULL) {
    SetEntityRoutine(p, EntityC60F_Update, EntityC60F_Destroy);
    if (EntityC60F_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_081d81b8(void) { gEntityC60F = NULL; }
