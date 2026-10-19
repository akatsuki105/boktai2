#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"

// ヨルムンガンドに関係 (ヨルムンガンドのサブエンティティ?)
typedef struct {
  Entity e;                // 0x0000, ENTITY_UNK_8
  u32 flags;               // 0x0018, bit i が立っていれば elems[i] が有効
  u16 unk_1c;              // 0x001C, _Init の第2引数
  u8 unk_1e[0x24 - 0x1E];  // 0x001E, まだ未解析
  u8 elems[8][0x2CC];      // 0x0024, _Init が FUN_08245cfc に1つずつ渡す, 8 * 0x2CC で構造体末尾ぴったり
} Entity082464b8;
static_assert(sizeof(Entity082464b8) == 5764);

const u32 u32_ARRAY_ARRAY_08dbd7d0[6][2] = {
    {0x1,      0x2 },
    {0x2,      0x1 },
    {0x200004, 0x8 },
    {0x400008, 0x4 },
    {0x4010,   0x20},
    {0x8020,   0x10},
};  // 0x08DBD7D0

void FUN_08245cfc(Entity082464b8*, u8*, s32);  // asm/entity_082464b8.inc
s32 FUN_08245e68(Entity082464b8*, u8*, s32);   // asm/entity_082464b8.inc
void FUN_08246090(Entity082464b8*, u8*, s32);
void FUN_0824617c(Entity082464b8*, u8*, s32);
void FUN_082462f4(Entity082464b8*, u8*, s32);
void FUN_082463cc(Entity082464b8*, u8*, s32);

void (*const sEntity082464b8Updates[4])(Entity082464b8*, u8*, s32) = {
    FUN_08246090,
    FUN_0824617c,
    FUN_082462f4,
    FUN_082463cc,
};  // 0x08DBD800

// 空いている枠を返す, 無ければ NULL
u8* FUN_08245c4c(Entity082464b8* p, s32* outIndex) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!(p->flags & 1 << i)) {
      *outIndex = i;
      return p->elems[i];
    }
  }
  return NULL;
}

NAKED void FUN_08245c80(unknown* param_1, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08245c80.inc"); }

void nop_08245cf8(void) {}

NAKED void FUN_08245cfc(Entity082464b8* p, u8* param_2, s32 param_3) { INCFUNC("asm/func/FUN_08245cfc.inc"); }

// 枠のスプライト9枚を外して判定を無効にし, 使用中ビットを落とす
s32 FUN_08245e68(Entity082464b8* p, u8* e, s32 idx) {
  AuxSprite* spr = (AuxSprite*)&e[0x124];
  s32 i;

  for (i = 0; i < 9; i++, spr++) {
    AuxSprite_Remove(spr);
  }

  ((HitboxData*)&e[0xD4])->flags |= HBFLAG_UNK_2;
  p->flags &= ~(1 << idx);
}

NAKED void FUN_08245eac(u8* e) { INCFUNC("asm/func/FUN_08245eac.inc"); }

NAKED void FUN_08245f2c(void* param_1) { INCFUNC("asm/func/FUN_08245f2c.inc"); }

NAKED void FUN_08246038(void* param_1) { INCFUNC("asm/func/FUN_08246038.inc"); }

NAKED void FUN_08246090(Entity082464b8* p, u8* e, s32 param_3) { INCFUNC("asm/func/FUN_08246090.inc"); }

NAKED void FUN_0824617c(Entity082464b8* p, u8* e, s32 param_3) { INCFUNC("asm/func/FUN_0824617c.inc"); }

NAKED void FUN_082462f4(Entity082464b8* p, u8* e, s32 param_3) { INCFUNC("asm/func/FUN_082462f4.inc"); }

// 判定を1フレームだけ有効にしてから寿命を数え, 0x1D を超えたら片付ける
void FUN_082463cc(Entity082464b8* p, u8* e, s32 idx) {
  if (e[0] != 0) {
    e[0] = 0;
    ((HitboxData*)&e[0xD4])->flags |= HBFLAG_UNK_2;
  }

  FUN_08245eac(e);

  if (*(u16*)&e[6] > 0x1D) {
    FUN_08245e68(p, e, idx);
  } else {
    *(u16*)&e[6] += 1;
  }
}

s32 Entity082464b8_Update(Entity082464b8* p) {
  u8* e = p->elems[0];
  s32 i;

  for (i = 0; i < 8; i++, e += 0x2CC) {
    if (p->flags & 1 << i) {
      sEntity082464b8Updates[e[1]](p, e, i);
    }
  }
  return 0;
}

s32 Entity082464b8_Destroy(Entity082464b8* p) {
  u8* e;
  s32 i;

  e = p->elems[0];
  i = 0;
  while (i < 8) {
    if (p->flags & (1 << i)) {
      FUN_08245e68(p, e, i);
    }
    Hitbox_Unregister((HitboxData*)&e[0xD4]);
    i++;
    e += sizeof(p->elems[0]);
  }
  return 0;
}

s32 Entity082464b8_Init(Entity082464b8* p, s32 val) {
  u8* e;
  s32 i;

  p->unk_1c = val;
  e = p->elems[0];
  i = 0;
  while (i < 8) {
    FUN_08245cfc(p, e, i);
    i++;
    e += sizeof(p->elems[0]);
  }
  return 0;
}

Entity082464b8* Entity082464b8_Create(s32 val, s32 _) {
  Entity082464b8* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity082464b8));

  if (p != NULL) {
    SetEntityRoutine(p, Entity082464b8_Update, Entity082464b8_Destroy);
    if (Entity082464b8_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED s32 FUN_082464fc(unknown* p, unknown* param_2, unknown* param_3, u32 param_4, u32 param_5, u32 param_6) { INCFUNC("asm/func/FUN_082464fc.inc"); }

void* FUN_08246624(Entity082464b8* p) {
  u8* e = p->elems[0];
  s32 i;

  for (i = 0; i < 8; i++, e += 0x2CC) {
    if ((p->flags & 1 << i) && e[1] == 0) {
      e[1] = 3;
      e[0] = 1;
      *(u16*)(e + 6) = 0;
    }
  }
}
