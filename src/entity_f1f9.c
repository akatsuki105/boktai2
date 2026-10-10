#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "shadow.h"
#include "sprite_aux.h"

// スプライト・ヒットボックス・影を1つずつ持つ
typedef struct EntityF1F9Item {
  AuxSprite sprite;   // 0x000
  u8 unk_2c[44];      // 0x02C
  HitboxData hitbox;  // 0x058
  AuxShadow shadow;   // 0x0A8, shadowId で管理
  Vec3 basePos;       // 0x114, 揺れの基準位置, sprite.pos へ複写する
  u8 unk_11c[16];     // 0x11C
  s32 unk_12c;        // 0x12C, 1フレーム前の距離の2乗
  s32 unk_130;        // 0x130, プレイヤーとの距離の2乗
  s32 unk_134;        // 0x134, この距離まで近づかれると反応する
  u8 unk_138[2];      // 0x138
  u16 unk_13a;        // 0x13A, 1マスぶんの距離
  u8 unk_13c;         // 0x13C, 全体のマス数
  u8 unk_13d;         // 0x13D, 現在のマス番号
  u8 unk_13e[2];      // 0x13E
  s16 unk_140;        // 0x140, 移動の始点
  s16 unk_142;        // 0x142, 現在位置
  u8 unk_144[4];      // 0x144
  u16 state;          // 0x148, PTR_FUN_081D5D14_085AE104[state]
  u8 unk_14a[2];      // 0x14A
  u16 flags;          // 0x14C, FUN_081d5820 が立て、FUN_081d5834 が落とし、FUN_081d5848 が読む
  s8 shadowId;        // 0x14E, -1 なら影なし
  u8 unk_14f;         // 0x14F
  u16 unk_150;        // 0x150, HitboxData の unk_4 に入れる
  u8 unk_152;         // 0x152
  u8 unk_153;         // 0x153, 0 でない間はパレット 306 を強制して減らす
  u16 unk_154;        // 0x154, FUN_081d5d18 が毎フレーム 1 足すカウンタ
  u8 unk_156;         // 0x156, 立っていると FUN_081d5d18 が状態を初期化して落とす
  u8 unk_157;         // 0x157, 0 でない間はスプライトを ±10 揺らして減らす
} EntityF1F9Item;
static_assert(sizeof(EntityF1F9Item) == 344);

// 最大4個の EntityF1F9Item をビットマスクで管理するシングルトン
typedef struct EntityF1F9 {
  Entity e;                 // 0x000, ENTITY_UNK_10
  AuxAnimFile* anim;        // 0x018, ANIM_74C9
  EntityF1F9Item items[4];  // 0x01C
  u32 activeMask;           // 0x57C, bit i が立っていれば items[i] が使用中, _Init が 0 にする
} EntityF1F9;
static_assert(sizeof(EntityF1F9) == 1408);

extern EntityF1F9* gEntityF1F9;  // 0x03000198

void FUN_081d6444(EntityF1F9Item* item);
void FUN_081d6c24(EntityF1F9Item* item);

void FUN_081d5820(EntityF1F9Item* item, u16 n) { item->flags |= n; }

void FUN_081d5834(EntityF1F9Item* item, u16 n) { item->flags &= ~n; }

bool8 FUN_081d5848(EntityF1F9Item* item, u16 n) {
  if (item->flags & n) {
    return TRUE;
  }
  return FALSE;
}

NAKED s32 FUN_081d5864(EntityF1F9* p) { INCFUNC("asm/func/FUN_081d5864.inc"); }

NAKED s32 FUN_081d58c4(unknown* p) { INCFUNC("asm/func/FUN_081d58c4.inc"); }

NAKED void FUN_081d5924(unknown* p) { INCFUNC("asm/func/FUN_081d5924.inc"); }

// 無敵時間を数えつつ、点滅用のパレットを選ぶ
NON_MATCH void FUN_081d5cac(EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  if (item->hitbox.unk_44 != 0) {
    item->hitbox.flags |= HBFLAG_UNK_2;
    item->hitbox.unk_44--;
  } else {
    item->hitbox.flags &= ~HBFLAG_UNK_2;
  }
  if (item->unk_153 != 0) {
    Video_SetAuxSpritePltt(item->sprite.gfx, 306);
    item->unk_153--;
  } else {
    Video_SetAuxSpritePltt(item->sprite.gfx, 380);
  }
#else
  INCFUNC("asm/func/FUN_081d5cac.inc");
#endif
}

// state 0 のハンドラ, 何もしない
void FUN_081d5d14(EntityF1F9* p, EntityF1F9Item* item) {}

// state 1 のハンドラ
void FUN_081d5d18(EntityF1F9* p, EntityF1F9Item* item) {
  if (item->unk_156 != 0) {
    item->unk_154 = 0;
    AuxSprite_Show(&item->sprite);
    item->unk_156 = 0;
  }
  FUN_081d5cac(item);
  FUN_081d6444(item);
  if (item->unk_154 & 1) {
    FUN_081d6c24(item);
  }
  item->unk_154++;
}

NAKED void FUN_081d5d70(EntityF1F9* p, EntityF1F9Item* item) { INCFUNC("asm/func/FUN_081d5d70.inc"); }

NAKED void FUN_081d5f54(unknown* p) { INCFUNC("asm/func/FUN_081d5f54.inc"); }

NAKED void FUN_081d60c8(EntityF1F9* p, EntityF1F9Item* item) { INCFUNC("asm/func/FUN_081d60c8.inc"); }

NAKED void FUN_081d6200(EntityF1F9* p, EntityF1F9Item* item) { INCFUNC("asm/func/FUN_081d6200.inc"); }

void (*const PTR_ARRAY_085ae104[5])(EntityF1F9*, EntityF1F9Item*) = {
    FUN_081d5d14,
    FUN_081d5d18,
    FUN_081d5d70,
    FUN_081d60c8,
    FUN_081d6200,
};  // 0x085AE104

NAKED s32 EntityF1F9_Update(EntityF1F9* p) { INCFUNC("asm/func/EntityF1F9_Update.inc"); }

NAKED s32 EntityF1F9_Destroy(EntityF1F9* p) { INCFUNC("asm/func/EntityF1F9_Destroy.inc"); }

s32 EntityF1F9_Init(EntityF1F9* p) {
  p->anim = GetFile(DIR_ANIMATION, ANIM_74C9);
  gEntityF1F9 = p;
  p->activeMask = 0;
  return 0;
}

EntityF1F9* EntityF1F9_Create(void) {
  EntityF1F9* p;

  if (gEntityF1F9 != NULL) {
    return gEntityF1F9;
  }
  p = CreateEntity(ENTITY_UNK_10, sizeof(EntityF1F9));
  if (p != NULL) {
    SetEntityRoutine(p, EntityF1F9_Update, EntityF1F9_Destroy);
    if (EntityF1F9_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_081d6438(void) { gEntityF1F9 = NULL; }

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

NAKED void FUN_081d64d4(HitboxData* a, HitboxData* b, EntityF1F9Item* p) { INCFUNC("asm/func/FUN_081d64d4.inc"); }

NAKED void FUN_081d65e8(unknown* p) { INCFUNC("asm/func/FUN_081d65e8.inc"); }

void FUN_081d66c0(EntityF1F9Item* item, u32 power, u32 attributes, u32 weakness) {
  HitboxData* hitbox = &item->hitbox;
  Vec3 offset, halfSize;

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

// プレイヤーが一定距離まで近づいたら起動する
NON_MATCH void FUN_081d6c24(EntityF1F9Item* item) {
#ifdef NONMATCHING_C
  if (!FUN_081d5848(item, 1)) {
    Vec3 d;
    d.x = gPlayerPtr[0]->mover.pos.x - item->sprite.pos.x;
    d.y = gPlayerPtr[0]->mover.pos.y - item->sprite.pos.y;
    d.z = gPlayerPtr[0]->mover.pos.z - item->sprite.pos.z;

    item->unk_130 = d.x * d.x + d.z * d.z;
    if (item->unk_130 < item->unk_134) {
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
  d.x = gPlayerPtr[0]->mover.pos.x - item->basePos.x;
  d.y = gPlayerPtr[0]->mover.pos.y - item->basePos.y;
  d.z = gPlayerPtr[0]->mover.pos.z - item->basePos.z;

  item->unk_12c = item->unk_130;

  item->unk_130 = d.x * d.x + d.z * d.z;
  if (item->unk_130 < item->unk_134) {
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_081d6cb0.inc");
#endif
}
