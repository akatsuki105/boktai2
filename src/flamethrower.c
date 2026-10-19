#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "sprite.h"

typedef struct Entity081eaf6cItem {
  MainSprite sprite;  // 0x000, Entity081eaf6c_Destroy が要素そのものを MainSprite_Remove に渡す
  Mover unk_60;       // 0x060, flags の bit0 が立っていれば _Destroy が FUN_08002a58 に、その後 Mover_Unlink に渡す
  u8 unk_a4[44];      // 0x0A4
  Vec3 hitboxPos;     // 0x0D0, Hitbox_SetPos に渡す位置
  HitboxData hitbox;  // 0x0D8, FUN_081eaa10 が unk_128 が 1 のときだけ登録する
  s16 unk_128;        // 0x128, 1 のときだけヒットボックスを登録する
  u8 unk_12a[8];      // 0x12A
  s16 unk_132;        // 0x132, _Update が s16 として読む
  u16 unk_134;        // 0x134, FUN_081eaa10 が毎フレーム +1 する
  u16 unk_136;        // 0x136, _Init が全要素に 0xFFFF を入れる
  u16 flags;          // 0x138, bit0 が立っていると _Destroy が FUN_08002a58 を呼ぶ
  u8 unk_13a[2];      // 0x13A, padding?
} Entity081eaf6cItem;
static_assert(sizeof(Entity081eaf6cItem) == 316);

// 火炎放射のスプライトを最大4個、ビットマスクで管理するシングルトン
// ゲーム中に火炎放射のギミックが登場するところは色々あるが、これが 汎用の火炎放射管理構造体 なのか 特定のギミック専用のもの なのかはまだ不明
typedef struct {
  Entity e;                       // 0x000, ENTITY_UNK_10
  MainSpriteGfx gfx;              // 0x018, SPRITE_FLAMETHROWER
  MainSpriteGfxFile* spriteFile;  // 0x038, SPRITE_FLAMETHROWER
  Entity081eaf6cItem items[4];    // 0x03C, _Init と _Destroy が 0x13C 刻みで4個走査する
  u32 activeMask;                 // 0x52C, bit i が立っていれば items[i] が使用中, _Init が 0 にする
} Entity081eaf6c;
static_assert(sizeof(Entity081eaf6c) == 1328);

static Entity081eaf6c* gEntity081eaf6c;  // 0x030001C0

const u8 u8_ARRAY_085ae478[18] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // 0x085AE478

void FUN_081ea878(Entity081eaf6cItem* p) {}

NAKED bool8 FUN_081ea87c(Entity081eaf6cItem* item) { INCFUNC("asm/func/FUN_081ea87c.inc"); }

void FUN_081eaa10(Entity081eaf6cItem* item) {
  if (!FUN_081ea87c(item)) {
    if (item->unk_128 == 1) {
      Hitbox_SetPos(&item->hitbox, &item->hitboxPos, 0);
      Hitbox_Register(&item->hitbox);
    }
    item->unk_134++;
  }
}

void FUN_081eaa54(Entity081eaf6cItem* p) {}

// 使用中のスロットのスプライトと Mover を片付けてシングルトンを手放す
// 残差5命令 (54/59): FUN_081eab78 と同じく, 原典は使用中判定を 0/1 に起こしてから cmp で読み直す
NON_MATCH s32 Entity081eaf6c_Destroy(Entity081eaf6c* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 4; i++) {
    if (p->activeMask & (1 << i)) {
      MainSprite_Remove(&p->items[i].sprite);
      if (p->items[i].flags & 1) {
        FUN_08002a58(&p->items[i].unk_60);
      }
      Mover_Unlink(&p->items[i].unk_60);
    }
  }

  gEntity081eaf6c = NULL;
  return 0;
#else
  INCFUNC("asm/func/Entity081eaf6c_Destroy.inc");
#endif
}

void (*const PTR_ARRAY_085ae48c[3])(Entity081eaf6cItem*) = {
    FUN_081ea878,
    FUN_081eaa10,
    FUN_081eaa54,
};  // 0x085AE48C

// 使用中のスロットごとに unk_132 の状態ハンドラを呼ぶ
// 残差5命令 (61/66): FUN_081eab78 と同じく, 原典は使用中判定を 0/1 に起こしてから cmp で読み直す
NON_MATCH s32 Entity081eaf6c_Update(Entity081eaf6c* p) {
#ifdef NONMATCHING_C
  s32 i;

  if (p->activeMask == 0) {
    return 0;
  }
  if ((gFlag030047a4 | u32_030047a0) & FLAG030047A4_GAMEOVER) {
    return 0;
  }
  if (u32_03002bc0[0] & FLAG03002BC0_UNK_2) {
    return 0;
  }

  for (i = 0; i < 4; i++) {
    if (p->activeMask & (1 << i)) {
      PTR_ARRAY_085ae48c[p->items[i].unk_132](&p->items[i]);
    }
  }

  return 0;
#else
  INCFUNC("asm/func/Entity081eaf6c_Update.inc");
#endif
}

// 空いているスロットを1つ確保して返す, 空きがなければ NULL
// 残差6命令 (33/39): 原典は使用中判定を 0/1 に起こしてから cmp で読み直し, 1 << i も再計算する
// Elevator_IsSlotUsed 相当の static inline を挟むと 36 まで戻るが一致はしないので入れていない
NON_MATCH Entity081eaf6cItem* FUN_081eab78(Entity081eaf6c* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 4; i++) {
    if (!(p->activeMask & (1 << i))) {
      p->activeMask |= 1 << i;
      p->items[i].unk_136 = i;
      return &p->items[i];
    }
  }

  return NULL;
#else
  INCFUNC("asm/func/FUN_081eab78.inc");
#endif
}

void FUN_081eabcc(HitboxData* a, HitboxData* b, void* p) {}

const Vec3 vec3_ARRAY_085ae498[3] = {
    {48, 32, 220},
    {48, 32, 276},
    {48, 32, 384}
};  // 0x085AE498

NAKED void FUN_081eabd0(unknown* p) { INCFUNC("asm/func/FUN_081eabd0.inc"); }

NAKED void FUN_081eace8(unknown* p) { INCFUNC("asm/func/FUN_081eace8.inc"); }

NAKED s32 FUN_081ead54(unknown* p) { INCFUNC("asm/func/FUN_081ead54.inc"); }

void FUN_081eaeec(Entity081eaf6c* p) {
  p->spriteFile = GetFile(DIR_MAIN_SPRITE, SPRITE_FLAMETHROWER);
  p->gfx = *(MainSpriteGfx*)p->spriteFile;
  OpenMainSpriteFile(&p->gfx, p->spriteFile);
}

s32 Entity081eaf6c_Init(Entity081eaf6c* p) {
  s32 i;

  gEntity081eaf6c = p;
  FUN_081eaeec(p);
  for (i = 0; i < 4; i++) {
    p->items[i].unk_136 |= 0xFFFF;
  }
  p->activeMask = 0;
  return 0;
}

void Entity081eaf6c_Create(void) {
  if (gEntity081eaf6c == NULL) {
    Entity081eaf6c* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity081eaf6c));
    if (p != NULL) {
      SetEntityRoutine(p, Entity081eaf6c_Update, Entity081eaf6c_Destroy);
      if (Entity081eaf6c_Init(p) < 0) {
        KillEntity((Entity*)p);
      }
    }
  }
}

void FUN_081eafb0(void) { gEntity081eaf6c = NULL; }
