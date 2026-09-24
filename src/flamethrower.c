#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "sprite.h"

// Entity081eaf6c が抱える要素
typedef struct Entity081eaf6cItem {
  MainSprite sprite;      // 0x000, Entity081eaf6c_Destroy が要素そのものを MainSprite_Remove に渡す
  Entity2UnkData unk_60;  // 0x060, flags の bit0 が立っていれば _Destroy が FUN_08002a58 に、その後 FUN_0823b284 に渡す
  u8 unk_a4[44];          // 0x0A4
  Vec3 hitboxPos;         // 0x0D0, Hitbox_SetPos に渡す位置
  HitboxData hitbox;      // 0x0D8, FUN_081eaa10 が unk_128 が 1 のときだけ登録する
  s16 unk_128;            // 0x128, 1 のときだけヒットボックスを登録する
  u8 unk_12a[8];          // 0x12A
  s16 unk_132;            // 0x132, _Update が s16 として読む
  u16 unk_134;            // 0x134, FUN_081eaa10 が毎フレーム +1 する
  u16 unk_136;            // 0x136, _Init が全要素に 0xFFFF を入れる
  u16 flags;              // 0x138, bit0 が立っていると _Destroy が FUN_08002a58 を呼ぶ
  u8 unk_13a[2];          // 0x13A, padding?
} Entity081eaf6cItem;
static_assert(sizeof(Entity081eaf6cItem) == 316);

// 火炎放射のスプライトを最大4個、ビットマスクで管理するシングルトン
// ゲーム中に火炎放射のギミックが登場するところは色々あるが、これが 汎用の火炎放射管理構造体 なのか 特定のギミック専用のもの なのかはまだ不明
typedef struct Entity081eaf6c {
  Entity e;                     // 0x000, ENTITY_UNK_10
  MainSpriteGfx gfx;            // 0x018, SPRITE_FLAMETHROWER
  MainSpriteFile* spriteFile;   // 0x038, SPRITE_FLAMETHROWER
  Entity081eaf6cItem items[4];  // 0x03C, _Init と _Destroy が 0x13C 刻みで4個走査する
  u32 activeMask;               // 0x52C, bit i が立っていれば items[i] が使用中。_Init が 0 にする
} Entity081eaf6c;
static_assert(sizeof(Entity081eaf6c) == 1328);

extern Entity081eaf6c* gEntity081eaf6c;  // 0x030001C0

void FUN_081ea878(unknown* p) {}

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

void FUN_081eaa54(unknown* p) {}

NAKED s32 Entity081eaf6c_Destroy(Entity081eaf6c* p) { INCFUNC("asm/func/Entity081eaf6c_Destroy.inc"); }

NAKED s32 Entity081eaf6c_Update(Entity081eaf6c* p) { INCFUNC("asm/func/Entity081eaf6c_Update.inc"); }

NAKED s32 FUN_081eab78(unknown* p) { INCFUNC("asm/func/FUN_081eab78.inc"); }

void FUN_081eabcc(unknown* p) {}

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
