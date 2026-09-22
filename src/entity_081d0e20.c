#include "animation.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "malloc.h"
#include "sound.h"
#include "sprite_aux.h"
#include "struct.h"
#include "vm.h"

// Entity081d0e20 が抱える要素。Malloc(0xC0) で個別に確保され、先頭が AuxSprite になっている, 根拠: Entity081d0e20_AllocElem
// 中身のほとんどは FUN_081d0864 がスクリプトのキーワードから埋める
typedef struct Entity081d0e20Elem {
  AuxSprite sprite;       // 0x00, 根拠: AuxSprite_Remove に渡される (Entity081d0e20_Destroy)
  Entity2UnkData unk_2c;  // 0x2C, 根拠: FUN_08002a58 / FUN_0823b284 に渡される (Entity081d0e20_Destroy)
  AuxAnimState anim;      // 0x70, 根拠: FUN_08236fac に渡される (FUN_081d0864)
  Vec3 pos;               // 0x80, 8バイトまとめて sprite.pos にコピーされる, 根拠: FUN_081d0864
  s16 id;                 // 0x88, Entity081d0e20_FindElem が引数と比較する (ldrsh)。VM_GetKeywordValue('i', 0)
  u16 scriptID_8a;        // 0x8A, VM_GetKeywordValue('R', 0)。flags bit7 が立つと Script_ExecById に渡して0クリアする, 根拠: FUN_081cf944
  u16 scriptID_8c;        // 0x8C, VM_GetKeywordValue('C', 0)。flags bit8 が立つと Script_ExecById に渡して0クリアする, 根拠: FUN_081cf944
  u8 unk_8e[2];           // 0x8E, 未解析
  u32 unk_90[6];          // 0x90, キーワード 'G' の後ろから6個読む
  u32 unk_a8[2];          // 0xA8, キーワード 'A' の後ろから2個読む
  u16 unk_b0;             // 0xB0, VM_GetKeywordValue('T', 0) を4で頭打ち。アニメの variant とパレット選択に使う (ldrh)
  u16 unk_b2;             // 0xB2, VM_GetKeywordValue('o', 0x3C) (ldrh)
  s16 slotIdx;            // 0xB4, Entity081d0e20_AllocElem が確保時にスロット番号を書く
  s16 state;              // 0xB6, PTR_ARRAY_085ae098 の添字, 根拠: Entity081d0e20_Update (ldrsh)
  u16 flags;              // 0xB8, bit9 で Update をスキップ、bit3 で unk_2c を後始末する, 根拠: Entity081d0e20_Update / _Destroy
  u8 unk_ba;              // 0xBA, 生成時に0
  u8 unk_bb;              // 0xBB, 生成時に0。FUN_081d006c が unk_b2 と比較する
  u32 unk_bc;             // 0xBC, FUN_081d0838 が str で0を書く
} Entity081d0e20Elem;
static_assert(sizeof(Entity081d0e20Elem) == 192);

// 要素を12個まで抱えるエンティティ。空きスロットは activeMask のビットで管理する
typedef struct Entity081d0e20 {
  Entity e;                       // 0x00, ENTITY_UNK_8
  AuxAnimFile* anim;              // 0x18, GetFile(DIR_ANIMATION, 0xAE9)
  AuxSpriteGfx gfx;               // 0x1C, SPRITE_PITFALL_A945
  Entity081d0e20Elem* items[12];  // 0x38, 根拠: Entity081d0e20_AllocElem が確保したものを入れる
  u32 activeMask;                 // 0x68, 1 << i で items[i] が使用中, 根拠: Entity081d0e20_AllocElem / _Update / _Destroy
} Entity081d0e20;
static_assert(sizeof(Entity081d0e20) == 108);

extern Entity081d0e20* gEntity081d0e20;  // 0x03000188

// ヘッダのない外部関数 (実体は src/entity_b8b9.c ほか)
s32 FUN_0823b400(Entity2UnkData* p, u16 id, Vec3* pos, u32 unk_5, u32 unk_4, void* owner);
bool32 FUN_0823b46c(Entity2UnkData* p, AuxSprite* unk_28);
s32 FUN_08002a48(Entity2UnkData* p);
unknown* FUN_081ee9bc(Vec3* pos);
s32 FUN_08002a58(Entity2UnkData* p);
s32 FUN_0823b284(Entity2UnkData* p);
s32 FUN_080e11a8(Vec3* pos, Vec3* size, s32 idx);
s32 FUN_080e1100(Vec3* pos, Vec3* size, u32* out);

Entity081d0e20* Entity081d0e20_Create(void);
Entity081d0e20Elem* Entity081d0e20_AllocElem(Entity081d0e20* p);

void FUN_081cf944(Entity081d0e20Elem* p) {
  u32 args[8];
  ScriptArgs sa;

  if (p->flags & (1 << 8)) {
    ClearMemory(args, sizeof(args));
    if (p->scriptID_8c != 0) {
      args[0] = p->id;
      sa.argc = 1;
      sa.argv = args;
      Script_ExecById(p->scriptID_8c, &sa);
      p->scriptID_8c = 0;
    }
  }
  if (p->flags & (1 << 7)) {
    ClearMemory(args, sizeof(args));
    if (p->scriptID_8a != 0) {
      args[0] = p->id;
      args[1] = p->unk_90[0];
      args[2] = p->unk_90[1];
      args[3] = p->unk_90[2];
      args[4] = p->unk_90[3];
      args[5] = p->unk_90[4];
      args[6] = p->unk_90[5];
      args[7] = (p->flags >> 10) & 1;
      sa.argc = 8;
      sa.argv = args;
      Script_ExecById(p->scriptID_8a, &sa);
      p->scriptID_8a = 0;
    }
  }
  p->flags &= 0xFA7F;
}

NAKED void FUN_081cfa24(Entity081d0e20Elem* p) { INCFUNC("asm/func/FUN_081cfa24.inc"); }

// 空きスロットを1つ確保して要素を作る
NON_MATCH Entity081d0e20Elem* Entity081d0e20_AllocElem(Entity081d0e20* p) {
#ifdef NONMATCHING_C
  Entity081d0e20Elem* elem;
  s32 i;

  for (i = 0; i < 12; i++) {
    bool32 used = (p->activeMask & (1 << i)) ? TRUE : FALSE;

    if (!used) {
      elem = Malloc(sizeof(Entity081d0e20Elem));
      ClearMemory(elem, sizeof(Entity081d0e20Elem));
      p->activeMask |= 1 << i;
      elem->slotIdx = i;
      p->items[i] = elem;
      return elem;
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/Entity081d0e20_AllocElem.inc");
#endif
}

NAKED s32 FUN_081cfcb8(Entity081d0e20Elem* p) { INCFUNC("asm/func/FUN_081cfcb8.inc"); }

void FUN_081cfd3c(void) {}

void FUN_081cfd40(Entity081d0e20Elem* p) {
  Vec3 size;
  u32 hit;
  s32 i;

  p->sprite.flags |= SPRFLAG_HIDDEN;
  size.z = 0x80, size.x = 0x80, size.y = 0x10;
  for (i = 0; i < 4; i++) {
    if (FUN_080e11a8(&p->pos, &size, i) != 0) {
      goto blocked;
    }
  }
  if ((u8)FUN_081cfcb8(p) == 0) {
    hit = 0;
    if (FUN_080e1100(&p->pos, &size, &hit) == 0) {
      return;
    }
  }
blocked:
  p->state = 2;
  p->unk_bb = 0;
}

NAKED void FUN_081cfdb8(Entity081d0e20Elem* p) { INCFUNC("asm/func/FUN_081cfdb8.inc"); }

void FUN_081d006c(Entity081d0e20Elem* p) {
  Entity081d0e20* mgr = gEntity081d0e20;

  if (p->unk_bb >= p->unk_b2) {
    FUN_081cfdb8(p);
    FUN_08236fac(&p->anim, mgr->anim, 0, p->unk_b0, 0);
    p->state = 4;
    p->unk_bb = 0;
    switch (p->unk_b0) {
      case 0:
      case 1: {
        if (gFlag030047a4 & FLAG030047A4_UNK_11) {
          PlaySound_082406e0(0x26D);
        } else {
          PlaySound_082406e0(0x1AB);
        }
        break;
      }
    }
  } else {
    p->unk_bb++;
  }
}

NAKED void FUN_081d00f0(Entity081d0e20Elem* p) { INCFUNC("asm/func/FUN_081d00f0.inc"); }

NAKED void FUN_081d02bc(Entity081d0e20Elem* p) { INCFUNC("asm/func/FUN_081d02bc.inc"); }

NAKED void FUN_081d03fc(Entity081d0e20Elem* p) { INCFUNC("asm/func/FUN_081d03fc.inc"); }

NAKED void FUN_081d0578(Entity081d0e20Elem* p) { INCFUNC("asm/func/FUN_081d0578.inc"); }

void FUN_081d070c(Entity081d0e20Elem* p) { FUN_081cf944(p); }

NON_MATCH void FUN_081d0718(Entity081d0e20* p, Entity081d0e20Elem* elem) {
#ifdef NONMATCHING_C
  AuxAnimState* anim;
  AuxAnimCmd* cmd;

  elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  anim = &elem->anim;
  FUN_08236fac(anim, p->anim, 0, elem->unk_b0, 0);
  anim->cmdIdx = 1;
  cmd = &anim->cmds[anim->cmdIdx];
  elem->sprite.metaspriteIdx = *cmd >> 6;
  if ((anim->flags & ANIM_PLAY_XFLIP) == (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
    elem->sprite.flags &= ~SPRFLAG_XFLIP;
  } else {
    elem->sprite.flags |= SPRFLAG_XFLIP;
  }
  if ((anim->flags & ANIM_PLAY_YFLIP) == (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
    elem->sprite.flags &= ~SPRFLAG_YFLIP;
  } else {
    elem->sprite.flags |= SPRFLAG_YFLIP;
  }
  anim->tick++;
  if (anim->tick >= anim->wait) {
    anim->tick = 0;
    if (anim->flags & ANIM_PLAY_REVERSE) {
      if (anim->cmdIdx == 0) {
        anim->cmdIdx = anim->cmdCount;
      }
      anim->cmdIdx--;
    } else {
      anim->cmdIdx++;
      if (anim->cmdIdx >= anim->cmdCount) {
        anim->cmdIdx = anim->flags & 4;
      }
    }
    anim->duration = anim->cmds[anim->cmdIdx] & 0xF;
    anim->wait = (anim->duration * anim->speed) >> 6;
    if (anim->wait == 0) {
      anim->wait = 1;
    }
  }
  elem->flags = (elem->flags & ~0x20) | 2;
#else
  INCFUNC("asm/func/FUN_081d0718.inc");
#endif
}

void FUN_081d0838(Entity081d0e20* p, Entity081d0e20Elem* elem) {
  elem->sprite.flags |= SPRFLAG_HIDDEN;
  elem->state = 3;
  elem->unk_bc = 0;
  elem->flags &= ~0x42;
}

// スクリプトのキーワードから要素を1つ生成する
NON_MATCH void FUN_081d0864(void) {
#ifdef NONMATCHING_C
  Entity081d0e20* p = gEntity081d0e20;
  Entity081d0e20Elem* elem;
  AuxSpriteGfx* gfx;
  AuxAnimState* anim;
  u32* dst;
  u16* cmd;
  Vec3 pos;
  s32 i;
  s32 val;
  u32 t;

  if ((p != NULL || (p = Entity081d0e20_Create()) != NULL) && (elem = Entity081d0e20_AllocElem(p)) != NULL) {
    elem->state = 1;
    if (VM_SeekToKeyword('p')) {
      elem->pos.x = Script_GetValue();
      elem->pos.y = Script_GetValue();
      elem->pos.z = Script_GetValue();
    }
    elem->id = VM_GetKeywordValue('i', 0);
    elem->scriptID_8a = VM_GetKeywordValue('R', 0);
    if (VM_SeekToKeyword('G')) {
      dst = elem->unk_90;
      for (i = 5; i >= 0; i--) {
        *dst = (VM_GetPC() == NULL) ? 0 : Script_GetValue();
        dst++;
      }
    }
    elem->scriptID_8c = VM_GetKeywordValue('C', 0);
    if (VM_SeekToKeyword('A')) {
      dst = elem->unk_a8;
      for (i = 1; i >= 0; i--) {
        *dst = (VM_GetPC() == NULL) ? 0 : Script_GetValue();
        dst++;
      }
    }
    gfx = &p->gfx;
    anim = &elem->anim;
    t = VM_GetKeywordValue('T', 0);
    elem->unk_b0 = t;
    if ((u16)t > 4) {
      elem->unk_b0 = 4;
    }
    elem->sprite.pos = elem->pos;
    elem->sprite.pos.x -= 0x100;
    if (elem->unk_b0 == 0) {
      Video_SetAuxSpritePltt(gfx, 0x282);
    } else if (elem->unk_b0 == 1) {
      Video_SetAuxSpritePltt(gfx, 0x283);
    }
    AuxSprite_Add(&elem->sprite, gfx, 0);
    FUN_08236fac(anim, p->anim, 0, elem->unk_b0, 0);
    cmd = &anim->cmds[anim->cmdIdx];
    elem->sprite.metaspriteIdx = *cmd >> 6;
    if ((anim->flags & ANIM_PLAY_XFLIP) == (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
      elem->sprite.flags &= ~SPRFLAG_XFLIP;
    } else {
      elem->sprite.flags |= SPRFLAG_XFLIP;
    }
    if ((anim->flags & ANIM_PLAY_YFLIP) == (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
      elem->sprite.flags &= ~SPRFLAG_YFLIP;
    } else {
      elem->sprite.flags |= SPRFLAG_YFLIP;
    }
    anim->tick++;
    if (anim->tick >= anim->wait) {
      anim->tick = 0;
      if (anim->flags & ANIM_PLAY_REVERSE) {
        if (anim->cmdIdx == 0) {
          anim->cmdIdx = anim->cmdCount;
        }
        anim->cmdIdx--;
      } else {
        anim->cmdIdx++;
        if (anim->cmdIdx >= anim->cmdCount) {
          anim->cmdIdx = anim->flags & 4;
        }
      }
      anim->duration = anim->cmds[anim->cmdIdx] & 0xF;
      anim->wait = (anim->duration * anim->speed) >> 6;
      if (anim->wait == 0) {
        anim->wait = 1;
      }
    }
    elem->sprite.flags |= SPRFLAG_HIDDEN;
    elem->sprite.priority = 2;
    elem->unk_bb = 0;
    elem->unk_ba = 0;
    elem->flags = 1;
    elem->unk_b2 = VM_GetKeywordValue('o', 0x3C);
    if (VM_GetKeywordValue('m', 0) != 0) {
      elem->flags |= 0x10;
      val = VM_GetKeywordValue('S', 0);
      if (val == 0) {
        FUN_081d0838(p, elem);
      } else if (val == 1) {
        FUN_081d0718(p, elem);
      }
    }
    pos = elem->pos;
    FUN_081ee9bc(&pos);
    if (VM_GetKeywordValue('s', 0) != 0) {
      elem->flags |= 8;
      FUN_0823b400(&elem->unk_2c, elem->id, &elem->pos, 0, 7, elem);
      FUN_0823b46c(&elem->unk_2c, &elem->sprite);
      FUN_08002a48(&elem->unk_2c);
    }
  }
#else
  INCFUNC("asm/func/FUN_081d0864.inc");
#endif
}

NAKED Entity081d0e20Elem* Entity081d0e20_FindElem(s32 key) { INCFUNC("asm/func/Entity081d0e20_FindElem.inc"); }

void FUN_081d0bd4(void) {
  s32 key = VM_GetKeywordValue('i', -1);
  s32 val;
  Entity081d0e20Elem* elem;

  if (key >= 0) {
    val = VM_GetKeywordValue('s', 0);
    elem = Entity081d0e20_FindElem(key);
    if (elem != NULL) {
      if (val == 1) {
        elem->flags |= 0x200;
        elem->sprite.flags |= SPRFLAG_HIDDEN;
      } else {
        elem->flags &= ~0x200;
        elem->state = 1;
      }
    }
  }
}

s32 FUN_081d0c38(void) {
  s32 key = VM_GetKeywordValue('i', -1);
  Entity081d0e20Elem* elem;

  if (key < 0 || (elem = Entity081d0e20_FindElem(key)) == NULL || (elem->flags & 0x180) != 0x180) {
    return 0;
  }
  return 1;
}

NON_MATCH void FUN_081d0c6c(void) {
#ifdef NONMATCHING_C
  s32 val = VM_GetKeywordValue('s', 0);
  Entity081d0e20Elem* elem = Entity081d0e20_FindElem(VM_GetKeywordValue('i', 0));

  if (elem != NULL) {
    switch (val) {
      case 0: {
        if (!(elem->flags & 0x40)) {
          elem->flags = (elem->flags | 0x40) & ~0x20;
          elem->state = 6;
          elem->unk_ba = 1;
        }
        break;
      }
      case 1: {
        if (!(elem->flags & 0x20)) {
          elem->flags = (elem->flags | 0x20) & ~0x40;
          elem->state = 3;
          elem->unk_ba = val;
        }
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_081d0c6c.inc");
#endif
}

NAKED s32 Entity081d0e20_Update(Entity081d0e20* p) { INCFUNC("asm/func/Entity081d0e20_Update.inc"); }

NON_MATCH s32 Entity081d0e20_Destroy(Entity081d0e20* p) {
#ifdef NONMATCHING_C
  Entity081d0e20Elem* elem;
  Entity2UnkData* unk;
  bool32 used;
  s32 i;

  for (i = 0; i < 12; i++) {
    used = (p->activeMask & (1 << i)) != 0;
    if (used) {
      elem = p->items[i];
      AuxSprite_Remove(&elem->sprite);
      if (elem->flags & 8) {
        unk = &elem->unk_2c;
        FUN_08002a58(unk);
        FUN_0823b284(unk);
      }
      Free(elem);
    }
  }
  gEntity081d0e20 = NULL;
  return 0;
#else
  INCFUNC("asm/func/Entity081d0e20_Destroy.inc");
#endif
}

s32 Entity081d0e20_Init(Entity081d0e20* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_PITFALL_A945);
  p->anim = GetFile(DIR_ANIMATION, 0xAE9);
  gEntity081d0e20 = p;
  p->activeMask = 0;
  return 0;
}

Entity081d0e20* Entity081d0e20_Create(void) {
  Entity081d0e20* p;

  if (gEntity081d0e20 != NULL) {
    return gEntity081d0e20;
  }
  p = CreateEntity(ENTITY_UNK_8, sizeof(Entity081d0e20));
  if (p != NULL) {
    SetEntityRoutine(p, Entity081d0e20_Update, Entity081d0e20_Destroy);
    if (Entity081d0e20_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void Entity081d0e20_ClearGlobal(void) { gEntity081d0e20 = NULL; }
