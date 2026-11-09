#include "file.h"
#include "global.h"
#include "sprite.h"

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
    MainSprite_SetAnim(&main->spr, &main->gfx, p->animID, playMode, mainFlags);
    if (!(mainFlags & MAIN_ANIM_KEEP_FRAME)) {
      p->animEnded = FALSE;
    }
    if (p->xflip) {
      main->spr.flags |= SPRFLAG_XFLIP;
    } else {
      main->spr.flags &= ~SPRFLAG_XFLIP;
    }
  }
  return 0;
}

// アニメを1フレーム進め, 終わったかを返す
s32 SpriteHolder_AdvanceAnim(SpriteHolder* p) {
  if (p->kind == 0) {
    return -1;
  }
  if (p->kind == 1) {
    if (p->u.aux.animFile != NULL) {
      p->animEnded = AuxSprite_AdvanceAnim(&p->u.aux.spr, &p->u.aux.anim);
    }
  } else {
    SpriteHolderMain* main = &p->u.main;
    p->animEnded = MainSprite_AdvanceAnim(&main->spr, &main->gfx);
  }
  return p->animEnded;
}

s32 SpriteHolder_IsAnimEnded(SpriteHolder* p) {
  if (p->kind == 1) {
    return p->animEnded;
  }
  {
    MainSprite* sprite = &p->u.main.spr;
    if (sprite->animEvents & MAIN_ANIM_EVENT_ENDED) {
      return TRUE;
    }
    return FALSE;
  }
}

// コマが進んだフレームだけ, 今のコマ番号を out に入れて TRUE を返す
s32 SpriteHolder_GetAdvancedCmdIdx(SpriteHolder* p, u32* out) {
  if (p->kind == 2) {
    MainSprite* sprite = &p->u.main.spr;
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
    AuxSprite_Remove(&p->u.aux.spr);
  } else {
    MainSprite_Remove(&p->u.main.spr);
  }
  p->kind = 0;
  return 0;
}

s32 SpriteHolder_InitAux(SpriteHolder* p, SpriteID32 id, u32 animFileID, SpriteFlags flags, Vec3* pos) {
  SpriteHolderAux* aux;

  if (p->kind != 0) {
    return -1;
  }
  ClearMemory(p, sizeof(SpriteHolder));
  p->kind = 1;
  aux = &p->u.aux;
  if (!Video_GetAuxSprite(&aux->gfx, id)) {
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
  AuxSprite_Add(&aux->spr, &aux->gfx, flags);
  aux->spr.pos = *pos;
  p->pos = &aux->spr.pos;
  p->flags = &aux->spr.flags;
  return 0;
}

s32 SpriteHolder_InitMain(SpriteHolder* p, SpriteID32 id, SpriteFlags flags, Vec3* pos) {
  SpriteHolderMain* main;
  MainSpriteGfxFile* f;

  if (p->kind != 0) {
    return -1;
  }
  ClearMemory(p, sizeof(SpriteHolder));
  p->kind = 2;
  main = &p->u.main;
  f = GetFile(DIR_MAIN_SPRITE, id);
  if (f == NULL) {
    return -1;
  }
  main->gfx = *f;
  OpenMainSpriteFile(&main->gfx, f);
  MainSprite_Add(&main->spr, &main->gfx, 0, flags, 1, PLAYMODE_PAUSE, 60, pos);
  p->pos = &main->spr.pos;
  p->flags = &main->spr.flags;
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
    AuxSprite* sprite = &p->u.aux.spr;
    sprite->priority = priority;
  } else {
    MainSprite* sprite = &p->u.main.spr;
    sprite->priority = priority;
  }
  return 0;
}

s32 SpriteHolder_SetAffine(SpriteHolder* p, u32 scaleX, u32 scaleY, u32 rotation) {
  if (p->kind == 0) {
    return -1;
  }
  if (p->kind == 1) {
    AuxSprite* sprite = &p->u.aux.spr;
    sprite->scaleX = scaleX;
    sprite->scaleY = scaleY;
    sprite->rotation = rotation;
  } else {
    MainSprite* sprite = &p->u.main.spr;
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
    MainSprite_SetPlttID(&p->u.main.spr, plttID);
  }
  return 0;
}
