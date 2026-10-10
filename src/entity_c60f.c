#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "player.h"
#include "sound.h"
#include "sprite_aux.h"

// EntityC60FItem.flags
typedef u32 EntityC60FItemFlags;
#define C60FITEM_TILE_OVERRIDE (1 << 5)  // 衝突タイルの上書きを持っている, 落とすときに Map_RemoveTileOverride で取り消す
#define C60FITEM_FIXED_AREA (1 << 7)     // state を回さず unk_10a を gStat->unk_248 と比べる

// EntityC60F が抱える要素
typedef struct {
  AuxSprite sprite;              // 0x000
  u8 unk_2c[28];                 // 0x02C
  Mover unk_48;                  // 0x048
  u8 unk_8c[16];                 // 0x08C
  Vec3 pos;                      // 0x09C, Hitbox_SetPos に渡す
  HitboxData hitbox;             // 0x0A4, FUN_081d6eb8 が組み立てる
  u8 unk_f4[8];                  // 0x0F4
  u16 slotIndex;                 // 0x0FC, 確保時に自分のスロット番号が入る
  s16 state;                     // 0x0FE, PTR_FUN_081D6F60_085AE118[state]
  EntityC60FItemFlags flags;     // 0x100
  u8 unk_104[4];                 // 0x104
  u8 unk_108;                    // 0x108, 0 でないときだけ _Destroy が FUN_08002a58 / Mover_Unlink を呼ぶ
  u8 unk_109;                    // 0x109
  u16 unk_10a;                   // 0x10A, unk_100 の bit7 が立っているとき gStat->unk_248 と比較される
  MapTileOverride tileOverride;  // 0x10C, unk_100 の bit5 が立っているとき _Destroy が Map_RemoveTileOverride に渡す
} EntityC60FItem;
static_assert(sizeof(EntityC60FItem) == 284);

// 最大32個の EntityC60FItem をビットマスクで管理するシングルトン
typedef struct EntityC60F {
  Entity e;                   // 0x00, ENTITY_UNK_10
  AuxAnimFile* anim0;         // 0x18, ANIM_1003
  AuxAnimFile* anim1;         // 0x1C, ANIM_931E
  EntityC60FItem* items[32];  // 0x20
  u32 activeMask;             // 0xA0, bit i が立っていれば items[i] が確保済み
  u8 unk_a4;                  // 0xA4, _Init と _Update が 0xFF を書く, 読み手が見つかっていない
  u8 unk_a5[3];               // 0xA5, padding?
} EntityC60F;
static_assert(sizeof(EntityC60F) == 168);

extern EntityC60F* gEntityC60F;  // 0x0300019C

NAKED void FUN_081d6d28(HitboxData* a, HitboxData* b, EntityC60FItem* p) { INCFUNC("asm/func/FUN_081d6d28.inc"); }

// 種別に応じた大きさで当たり判定を作る
NON_MATCH void FUN_081d6eb8(EntityC60FItem* p) {
#ifdef NONMATCHING_C
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize;
  Vec3 offset;
  s32 radius, height;

  if (p->unk_109 == 1) {
    radius = 0x56, height = 0x80;
  } else {
    radius = 0x60, height = 0x10;
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

// state 0 のハンドラ, 何もしない
void FUN_081d6f60(EntityC60FItem* p) {}

NAKED s32 FUN_081d6f64(unknown* p) { INCFUNC("asm/func/FUN_081d6f64.inc"); }

NAKED void FUN_081d6fd4(unknown* p) { INCFUNC("asm/func/FUN_081d6fd4.inc"); }

NAKED void FUN_081d7358(EntityC60FItem* p) { INCFUNC("asm/func/FUN_081d7358.inc"); }

NAKED void FUN_081d76bc(EntityC60FItem* p) { INCFUNC("asm/func/FUN_081d76bc.inc"); }

// 生成した衝突タイルの上書きを取り消す
NON_MATCH void FUN_081d7814(EntityC60FItem* p) {
#ifdef NONMATCHING_C
  if (p->state == 3 || p->state == 4) {
    if (p->flags & C60FITEM_TILE_OVERRIDE) {
      Map_RemoveTileOverride(&p->tileOverride);
      p->flags &= ~C60FITEM_TILE_OVERRIDE;
    }
  }
#else
  INCFUNC("asm/func/FUN_081d7814.inc");
#endif
}

NAKED void FUN_081d785c(EntityC60FItem* p) { INCFUNC("asm/func/FUN_081d785c.inc"); }

NAKED void FUN_081d7a60(EntityC60FItem* p) { INCFUNC("asm/func/FUN_081d7a60.inc"); }

NAKED void FUN_081d7ca8(unknown* p) { INCFUNC("asm/func/FUN_081d7ca8.inc"); }

void (*const PTR_ARRAY_085ae118[5])(EntityC60FItem*) = {
    FUN_081d6f60,
    FUN_081d7358,
    FUN_081d76bc,
    FUN_081d785c,
    FUN_081d7a60,
};  // 0x085AE118

NAKED s32 EntityC60F_Update(EntityC60F* p) { INCFUNC("asm/func/EntityC60F_Update.inc"); }

NAKED s32 EntityC60F_Destroy(EntityC60F* p) { INCFUNC("asm/func/EntityC60F_Destroy.inc"); }

s32 EntityC60F_Init(EntityC60F* p) {
  p->anim0 = GetFile(DIR_ANIMATION, ANIM_1003);
  p->anim1 = GetFile(DIR_ANIMATION, ANIM_931E);
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
