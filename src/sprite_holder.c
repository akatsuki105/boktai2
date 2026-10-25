#include "file.h"
#include "global.h"
#include "sprite.h"

void FUN_08055b58(void) {}

// kind に応じて AuxSprite / MainSprite のアニメを設定する, kind == 0 なら -1
s32 SpriteHolder_SetAnim(SpriteHolder* p, u32 pose, u32 variant, u32 xflip, u32 playMode, u32 auxFlags, u32 mainFlags) {
  if (p->kind == 0) {
    return -1;
  }
  if (p->kind == 1) {
    SpriteHolderAux* aux = &p->u.aux;
    p->variant = variant;
    p->xflip = xflip;
    if (xflip & 1) {
      auxFlags |= ANIM_PLAY_XFLIP;
    }
    p->animID = pose;
    if (aux->animFile != NULL) {
      if (AuxAnim_SetAnim(&aux->anim, aux->animFile, pose, p->variant, auxFlags)) {
        p->animEnded = FALSE;
      }
    }
  } else {
    SpriteHolderMain* main = &p->u.main;
    p->variant = variant;
    p->xflip = xflip;
    p->animID = pose + p->variant;
    MainSprite_SetAnim(&main->sprite, &main->gfx, p->animID, playMode, mainFlags);
    if (!(mainFlags & MAIN_ANIM_KEEP_FRAME)) {
      p->animEnded = FALSE;
    }
    if (p->xflip) {
      main->sprite.flags |= SPRFLAG_XFLIP;
    } else {
      main->sprite.flags &= ~SPRFLAG_XFLIP;
    }
  }
  return 0;
}

// アニメを1フレーム進め, 終わったかを返す
// 残差は AuxAnim 手動送りの定数の使い回しと u8 / u16 の切り詰め, MagicSleeping_Update などと同じ壁, Tier A-C は試済
// コマのフリップと長さを u8 の static inline で読むと 24 から 16 ハンクまで縮むが一致しないので残していない
NON_MATCH s32 SpriteHolder_AdvanceAnim(SpriteHolder* p) {
#ifdef NONMATCHING_C
  if (p->kind == 0) {
    return -1;
  }
  if (p->kind == 1) {
    if (p->u.aux.animFile != NULL) {
      AuxSprite* sprite = &p->u.aux.sprite;
      AuxAnimState* anim = &p->u.aux.anim;
      AuxAnimCmd* cmd = &anim->cmds[anim->cmdIdx];
      bool32 ended;

      sprite->poseIdx = *cmd >> 6;
      if ((anim->flags & ANIM_PLAY_XFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_XFLIP)) {
        sprite->flags |= SPRFLAG_XFLIP;
      } else {
        sprite->flags &= ~SPRFLAG_XFLIP;
      }
      if ((anim->flags & ANIM_PLAY_YFLIP) != (((*cmd & 0x30) >> 4) & ANIM_PLAY_YFLIP)) {
        sprite->flags |= SPRFLAG_YFLIP;
      } else {
        sprite->flags &= ~SPRFLAG_YFLIP;
      }
      anim->tick++;
      if (anim->tick >= anim->wait) {
        anim->tick = 0;
        if (anim->flags & ANIM_PLAY_REVERSE) {
          if (anim->cmdIdx == 0) {
            anim->cmdIdx = anim->cmdCount - 1;
            ended = TRUE;
          } else {
            anim->cmdIdx--;
            ended = FALSE;
          }
        } else {
          anim->cmdIdx++;
          if (anim->cmdIdx < anim->cmdCount) {
            ended = FALSE;
          } else {
            anim->cmdIdx = 0;
            ended = TRUE;
          }
        }
        cmd = &anim->cmds[anim->cmdIdx];
        anim->duration = *cmd & 0xF;
        anim->wait = (anim->duration * anim->speed) >> 6;
        if (anim->wait == 0) {
          anim->wait = 1;
        }
      } else {
        ended = FALSE;
      }
      p->animEnded = ended;
    }
  } else {
    SpriteHolderMain* main = &p->u.main;
    p->animEnded = MainSprite_AdvanceAnim(&main->sprite, &main->gfx);
  }
  return p->animEnded;
#else
  INCFUNC("asm/func/SpriteHolder_AdvanceAnim.inc");
#endif
}

s32 SpriteHolder_IsAnimEnded(SpriteHolder* p) {
  if (p->kind == 1) {
    return p->animEnded;
  }
  {
    MainSprite* sprite = &p->u.main.sprite;
    if (sprite->animEvents & MAIN_ANIM_EVENT_ENDED) {
      return TRUE;
    }
    return FALSE;
  }
}

// コマが進んだフレームだけ, 今のコマ番号を out に入れて TRUE を返す
s32 SpriteHolder_GetAdvancedCmdIdx(SpriteHolder* p, u32* out) {
  if (p->kind == 2) {
    MainSprite* sprite = &p->u.main.sprite;
    if (sprite->animEvents & MAIN_ANIM_EVENT_ADVANCED) {
      *out = sprite->animCmdIdx;
      return TRUE;
    }
  } else {
    AuxAnimState* anim = &p->u.aux.anim;
    if (anim->tick == 0) {
      *out = anim->cmdIdx;
      return TRUE;
    }
  }
  return FALSE;
}

s32 SpriteHolder_Remove(SpriteHolder* p) {
  if (p->kind == 0) {
    return -1;
  }
  if (p->kind == 1) {
    AuxSprite_Remove(&p->u.aux.sprite);
  } else {
    MainSprite_Remove(&p->u.main.sprite);
  }
  p->kind = 0;
  return 0;
}

s32 SpriteHolder_InitAux(SpriteHolder* p, u32 spriteID, u32 animFileID, SpriteFlags flags, Vec3* pos) {
  SpriteHolderAux* aux;

  if (p->kind != 0) {
    return -1;
  }
  ClearMemory(p, sizeof(SpriteHolder));
  p->kind = 1;
  aux = &p->u.aux;
  if (!Video_GetAuxSprite(&aux->gfx, spriteID)) {
    return -1;
  }
  if (animFileID != 0) {
    aux->animFile = GetFile(DIR_ANIMATION, animFileID);
    if (aux->animFile == NULL) {
      return -1;
    }
  } else {
    aux->animFile = NULL;
  }
  AuxSprite_Add(&aux->sprite, &aux->gfx, flags);
  aux->sprite.pos = *pos;
  p->pos = &aux->sprite.pos;
  p->flags = &aux->sprite.flags;
  return 0;
}

s32 SpriteHolder_InitMain(SpriteHolder* p, u32 spriteID, SpriteFlags flags, Vec3* pos) {
  SpriteHolderMain* main;
  MainSpriteGfxFile* f;

  if (p->kind != 0) {
    return -1;
  }
  ClearMemory(p, sizeof(SpriteHolder));
  p->kind = 2;
  main = &p->u.main;
  f = GetFile(DIR_MAIN_SPRITE, spriteID);
  if (f == NULL) {
    return -1;
  }
  main->gfx = *f;
  OpenMainSpriteFile(&main->gfx, f);
  MainSprite_Add(&main->sprite, &main->gfx, 0, flags, 1, 0, 60, pos);
  p->pos = &main->sprite.pos;
  p->flags = &main->sprite.flags;
}

s32 SpriteHolder_SetPos(SpriteHolder* p, Vec3* pos) {
  if (p->kind == 0) {
    return -1;
  }
  *p->pos = *pos;
}

s32 SpriteHolder_SetFlags(SpriteHolder* p, SpriteFlags flags) {
  if (p->kind == 0) {
    return -1;
  }
  *p->flags |= flags;
  return 0;
}

s32 SpriteHolder_ClearFlags(SpriteHolder* p, SpriteFlags flags) {
  if (p->kind == 0) {
    return -1;
  }
  *p->flags &= ~flags;
  return 0;
}

s32 SpriteHolder_TestFlags(SpriteHolder* p, SpriteFlags mask) {
  if (p->kind == 0) {
    return 0;
  }
  return *p->flags & mask;
}

s32 SpriteHolder_SetPriority(SpriteHolder* p, u32 priority) {
  if (p->kind == 0) {
    return -1;
  }
  if (p->kind == 1) {
    AuxSprite* sprite = &p->u.aux.sprite;
    sprite->priority = priority;
  } else {
    MainSprite* sprite = &p->u.main.sprite;
    sprite->priority = priority;
  }
  return 0;
}

s32 SpriteHolder_SetAffine(SpriteHolder* p, u32 scaleX, u32 scaleY, u32 rotation) {
  if (p->kind == 0) {
    return -1;
  }
  if (p->kind == 1) {
    AuxSprite* sprite = &p->u.aux.sprite;
    sprite->scaleX = scaleX;
    sprite->scaleY = scaleY;
    sprite->rotation = rotation;
  } else {
    MainSprite* sprite = &p->u.main.sprite;
    sprite->scaleX = scaleX;
    sprite->scaleY = scaleY;
    sprite->rotation = rotation;
  }
  return 0;
}

s32 SpriteHolder_SetPlttID(SpriteHolder* p, u32 plttID) {
  if (p->kind == 0) {
    return -1;
  }
  if (p->kind == 1) {
    Video_SetAuxSpritePltt(&p->u.aux.gfx, plttID);
  } else {
    MainSprite_SetPlttID(&p->u.main.sprite, plttID);
  }
  return 0;
}
