#include "entity.h"
#include "file.h"
#include "global.h"
#include "malloc.h"
#include "mover.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

// 落とし穴, 上に誰かが乗ると '.o' フレーム後に開く
typedef struct {
  AuxSprite sprite;   // 0x00
  Mover mover;        // 0x2C
  AuxAnimState anim;  // 0x70
  Vec3 pos;           // 0x80
  s16 id;             // 0x88, '.i=0'
  u16 scriptID_8a;    // 0x8A, '.R=0', flags bit7 が立つと VM_ExecByID に渡して0クリアする
  u16 scriptID_8c;    // 0x8C, '.C=0', flags bit8 が立つと VM_ExecByID に渡して0クリアする
  u8 unk_8e[2];       // 0x8E, padding?
  u32 unk_90[6];      // 0x90, '.G' の後ろから6個読む
  u32 unk_a8[2];      // 0xA8, '.A' の後ろから2個読む
  u16 unk_b0;         // 0xB0, '.T=0' を4で頭打ち, アニメの variant とパレット選択に使う
  u16 unk_b2;         // 0xB2, '.o=60',
  s16 slotIdx;        // 0xB4, pits の idx
  s16 state;          // 0xB6, sPitfallUpdates の添字
  u16 flags;          // 0xB8, bit9 で Update をスキップ, bit3 で mover を後始末する
  u8 unk_ba;          // 0xBA, 生成時に0
  u8 unk_bb;          // 0xBB, 生成時に0, Pitfall_UpdateState2 が unk_b2 と比較する
  u32 unk_bc;         // 0xBC
} Pitfall;
static_assert(sizeof(Pitfall) == 192);

// 落とし穴を12個まで抱えるエンティティ, 空きスロットは activeMask のビットで管理する
typedef struct {
  Entity e;                       // 0x00, ENTITY_UNK_8
  AuxAnimFile* anim;              // 0x18, ANIM_0AE9
  AuxSpriteGfx gfx;               // 0x1C, SPRITE_PITFALL_A945
  Pitfall* pits[12];  // 0x38
  u32 activeMask;                 // 0x68, 1 << i で pits[i] が使用中
} PitfallManager;
static_assert(sizeof(PitfallManager) == 108);

static PitfallManager* sPitfallManager;  // 0x03000188

struct PitfallWarning* PitfallWarning_Spawn(Vec3* pos);
struct Player* FUN_080e11a8(Vec3* pos, Vec3* size, s32 idx);
struct Enemy* FUN_080e1100(Vec3* pos, Vec3* size, u32* id);
PitfallManager* PitfallManager_Create(void);

static inline bool8 PitfallManager_IsPitUsed(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void FUN_081cf944(Pitfall* p) {
  u32 args[8];
  ScriptArgs sa;

  if (p->flags & (1 << 8)) {
    ClearMemory(args, sizeof(args));
    if (p->scriptID_8c != 0) {
      args[0] = p->id;
      sa.argc = 1;
      sa.argv = args;
      VM_ExecByID(p->scriptID_8c, &sa);
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
      VM_ExecByID(p->scriptID_8a, &sa);
      p->scriptID_8a = 0;
    }
  }
  p->flags &= 0xFA7F;
}

NAKED void FUN_081cfa24(Pitfall* p) { INCFUNC("asm/func/FUN_081cfa24.inc"); }

// 空きスロットを1つ確保して要素を作る
Pitfall* PitfallManager_AllocPit(PitfallManager* p) {
  Pitfall* pit;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!PitfallManager_IsPitUsed(&p->activeMask, i)) {
      pit = Malloc(sizeof(Pitfall));
      ClearMemory(pit, sizeof(Pitfall));
      p->activeMask |= 1 << i;
      pit->slotIdx = i;
      p->pits[i] = pit;
      return pit;
    }
  }
  return NULL;
}

NAKED s32 FUN_081cfcb8(Pitfall* p) { INCFUNC("asm/func/FUN_081cfcb8.inc"); }

void Pitfall_UpdateState0(Pitfall* _) {}

void Pitfall_UpdateState1(Pitfall* p) {
  Vec3 size;
  u32 hit;
  s32 i;

  p->sprite.flags |= SPRFLAG_HIDDEN;
  size.z = Q8(0.5), size.x = Q8(0.5), size.y = Q8(0.063);  // なぜか z, x, y の順番
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

NAKED void FUN_081cfdb8(Pitfall* p) { INCFUNC("asm/func/FUN_081cfdb8.inc"); }

void Pitfall_UpdateState2(Pitfall* p) {
  PitfallManager* mgr = sPitfallManager;

  if (p->unk_bb >= p->unk_b2) {
    FUN_081cfdb8(p);
    AuxAnim_SetAnim(&p->anim, mgr->anim, 0, p->unk_b0, 0);
    p->state = 4;
    p->unk_bb = 0;
    switch (p->unk_b0) {
      case 0:
      case 1: {
        if (gGameFlags & GAMEFLAG_LINK) {
          PlaySound_082406e0(SE_WOOD_DOOR_621);
        } else {
          PlaySound_082406e0(SE_OPEN_427);
        }
        break;
      }
    }
  } else {
    p->unk_bb++;
  }
}

NAKED void Pitfall_UpdateState3(Pitfall* p) { INCFUNC("asm/func/Pitfall_UpdateState3.inc"); }

NAKED void Pitfall_UpdateState4(Pitfall* p) { INCFUNC("asm/func/Pitfall_UpdateState4.inc"); }

NAKED void Pitfall_UpdateState5(Pitfall* p) { INCFUNC("asm/func/Pitfall_UpdateState5.inc"); }

NAKED void Pitfall_UpdateState6(Pitfall* p) { INCFUNC("asm/func/Pitfall_UpdateState6.inc"); }

void Pitfall_UpdateState7(Pitfall* p) { FUN_081cf944(p); }

// アニメ 0 の2コマ目から再生を始めて1コマ進め, state 6 へ移る
void FUN_081d0718(PitfallManager* p, Pitfall* pit) {
  AuxAnimState* anim;

  pit->sprite.flags &= ~SPRFLAG_HIDDEN;
  anim = &pit->anim;
  AuxAnim_SetAnim(anim, p->anim, 0, pit->unk_b0, 0);
  pit->anim.cmdIdx = 1;
  AuxSprite_AdvanceAnim(&pit->sprite, anim);
  pit->state = 6;
  pit->flags = (pit->flags & ~0x20) | 2;
}

void FUN_081d0838(PitfallManager* p, Pitfall* pit) {
  pit->sprite.flags |= SPRFLAG_HIDDEN;
  pit->state = 3;
  pit->unk_bc = 0;
  pit->flags &= ~0x42;
}

// 0x2FA5, スクリプトの引数から要素を1つ生成する
NON_MATCH void Cmd_2FA5(void) {
#ifdef NONMATCHING_C
  PitfallManager* p = sPitfallManager;
  Pitfall* pit;
  AuxSpriteGfx* gfx;
  AuxAnimState* anim;
  u32* dst;
  u16* cmd;
  Vec3 pos;
  s32 i;
  s32 val;
  u32 t;

  if ((p != NULL || (p = PitfallManager_Create()) != NULL) && (pit = PitfallManager_AllocPit(p)) != NULL) {
    pit->state = 1;
    if (VM_SeekToNamedArg('p')) {
      VEC3_SET(pit->pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    }
    pit->id = VM_GetNamedArgValue('i', 0);
    pit->scriptID_8a = VM_GetNamedArgValue('R', 0);
    if (VM_SeekToNamedArg('G')) {
      dst = pit->unk_90;
      for (i = 0; i < 6; i++) {
        *dst = (VM_GetPC() == NULL) ? 0 : VM_GetValue();
        dst++;
      }
    }
    pit->scriptID_8c = VM_GetNamedArgValue('C', 0);
    if (VM_SeekToNamedArg('A')) {
      dst = pit->unk_a8;
      for (i = 0; i < 2; i++) {
        *dst = (VM_GetPC() == NULL) ? 0 : VM_GetValue();
        dst++;
      }
    }
    gfx = &p->gfx;
    anim = &pit->anim;
    t = VM_GetNamedArgValue('T', 0);
    pit->unk_b0 = t;
    if ((u16)t > 4) {
      pit->unk_b0 = 4;
    }
    pit->sprite.pos = pit->pos;
    pit->sprite.pos.x -= 0x100;
    if (pit->unk_b0 == 0) {
      Video_SetAuxSpritePltt(gfx, 642);
    } else if (pit->unk_b0 == 1) {
      Video_SetAuxSpritePltt(gfx, 643);
    }
    AuxSprite_Add(&pit->sprite, gfx, 0);
    AuxAnim_SetAnim(anim, p->anim, 0, pit->unk_b0, 0);
    cmd = &anim->cmds[anim->cmdIdx];
    pit->sprite.poseIdx = *cmd >> 6;
    if ((anim->flags & ANIM_PLAY_XFLIP) == (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
      pit->sprite.flags &= ~SPRFLAG_XFLIP;
    } else {
      pit->sprite.flags |= SPRFLAG_XFLIP;
    }
    if ((anim->flags & ANIM_PLAY_YFLIP) == (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
      pit->sprite.flags &= ~SPRFLAG_YFLIP;
    } else {
      pit->sprite.flags |= SPRFLAG_YFLIP;
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
    pit->sprite.flags |= SPRFLAG_HIDDEN;
    pit->sprite.priority = 2;
    pit->unk_bb = 0;
    pit->unk_ba = 0;
    pit->flags = 1;
    pit->unk_b2 = VM_GetNamedArgValue('o', 60);
    if (VM_GetNamedArgValue('m', 0) != 0) {
      pit->flags |= 0x10;
      val = VM_GetNamedArgValue('S', 0);
      if (val == 0) {
        FUN_081d0838(p, pit);
      } else if (val == 1) {
        FUN_081d0718(p, pit);
      }
    }
    pos = pit->pos;
    PitfallWarning_Spawn(&pos);
    if (VM_GetNamedArgValue('s', 0) != 0) {
      pit->flags |= 8;
      Mover_Init(&pit->mover, pit->id, &pit->pos, 0, 7, pit);
      Mover_SetAuxSprite(&pit->mover, &pit->sprite);
      FUN_08002a48(&pit->mover);
    }
  }
#else
  INCFUNC("asm/func/Cmd_2FA5.inc");
#endif
}

NAKED Pitfall* PitfallManager_FindPitById(s32 id) { INCFUNC("asm/func/PitfallManager_FindPitById.inc"); }

void Cmd_0EE4(void) {
  s32 id = VM_GetNamedArgValue('i', -1);
  if (id >= 0) {
    s32 val = VM_GetNamedArgValue('s', 0);
    Pitfall* pit = PitfallManager_FindPitById(id);
    if (pit != NULL) {
      if (val == 1) {
        pit->flags |= (1 << 9);
        pit->sprite.flags |= SPRFLAG_HIDDEN;
      } else {
        pit->flags &= ~(1 << 9);
        pit->state = 1;
      }
    }
  }
}

// 0x3215
s32 Cmd_3215(void) {
  s32 key = VM_GetNamedArgValue('i', -1);
  Pitfall* pit;

  if (key < 0 || (pit = PitfallManager_FindPitById(key)) == NULL || (pit->flags & 0x180) != 0x180) {
    return 0;
  }
  return 1;
}

// 0x779F, '.i', '.s'
void Cmd_779F(void) {
  s32 val = VM_GetNamedArgValue('s', 0);
  Pitfall* pit = PitfallManager_FindPitById(VM_GetNamedArgValue('i', 0));

  if (pit != NULL) {
    switch (val) {
      case 0: {
        if (!(pit->flags & (1 << 6))) {
          pit->flags |= (1 << 6);
          pit->flags &= ~(1 << 5);
          pit->state = 6;
          pit->unk_ba = 1;
        }
        break;
      }
      case 1: {
        if (!(pit->flags & (1 << 5))) {
          pit->flags |= (1 << 5);
          pit->flags &= ~(1 << 6);
          pit->state = 3;
          pit->unk_ba = 1;
        }
        break;
      }
    }
  }
}

void (*const sPitfallUpdates[8])(Pitfall*) = {
    Pitfall_UpdateState0,
    Pitfall_UpdateState1,
    Pitfall_UpdateState2,
    Pitfall_UpdateState3,
    Pitfall_UpdateState4,
    Pitfall_UpdateState5,
    Pitfall_UpdateState6,
    Pitfall_UpdateState7,
};  // 0x085AE098

NAKED s32 PitfallManager_Update(PitfallManager* p) { INCFUNC("asm/func/PitfallManager_Update.inc"); }

s32 PitfallManager_Destroy(PitfallManager* p) {
  Pitfall* pit;
  s32 i;

  for (i = 0; i < 12; i++) {
    if (PitfallManager_IsPitUsed(&p->activeMask, i)) {
      pit = p->pits[i];
      AuxSprite_Remove(&pit->sprite);
      if (pit->flags & (1 << 3)) {
        Mover* mover = &pit->mover;
        FUN_08002a58(mover);
        Mover_Unlink(mover);
      }
      Free(pit);
    }
  }
  sPitfallManager = NULL;
  return 0;
}

s32 PitfallManager_Init(PitfallManager* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_PITFALL_A945);
  p->anim = GetFile(DIR_ANIMATION, ANIM_0AE9);
  sPitfallManager = p;
  p->activeMask = 0;
  return 0;
}

// 0xC419
PitfallManager* PitfallManager_Create(void) {
  if (sPitfallManager == NULL) {
    PitfallManager* p = CreateEntity(ENTITY_UNK_8, sizeof(PitfallManager));
    if (p != NULL) {
      SetEntityRoutine(p, PitfallManager_Update, PitfallManager_Destroy);
      if (PitfallManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return sPitfallManager;
}

void PitfallManager_ClearGlobal(void) { sPitfallManager = NULL; }
