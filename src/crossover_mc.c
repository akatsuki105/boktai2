#include "entity.h"
#include "file.h"
#include "global.h"
#include "random.h"
#include "sound.h"
#include "sprite_main.h"

// クロスオーバー対戦で、画面中央に試合の進行を知らせる文字 (WAIT / ROUND / FIGHT! / FINISH! など) を出すエンティティ
typedef struct CrossoverMC {
  Entity e;               // 0x000, ENTITY_UNK_11
  u32 timer;              // 0x018, state が変わると 0 に戻り毎フレーム +1
  u8 state;               // 0x01C, PTR_ARRAY_085ab70c の添字
  bool8 entered;          // 0x01D, state を変えた直後だけ立つ
  bool8 exitRequest;      // 0x01E, 立つと今の state を抜けて state 0 に戻る, CrossoverMC_RequestExit が立てる
  MainSpriteGfx gfx;      // 0x020, SPRITE_UI_LINK
  MainSprite sprites[4];  // 0x040, pose初期値は 全部 LINK_PUSHSTART
} CrossoverMC;
static_assert(sizeof(CrossoverMC) == 448);

bool32 FUN_0804e59c(void);
s32 FUN_08050de8(void);
s32 FUN_08050dfc(void);

void CrossoverMC_StateHidden(CrossoverMC* p) {
  if (p->entered) {
    MainSprite* spr;
    s32 i;

    p->entered = FALSE;
    spr = p->sprites;
    for (i = 0; i < 4; i++, spr++) {
      MainSprite_Hide(spr);
    }
  }
  if (p->exitRequest) {
    p->exitRequest = FALSE;
  }
}

void CrossoverMC_StateWait(CrossoverMC* p) {
  if (p->entered) {
    p->entered = FALSE;
    MainSprite_SetPose(p->sprites, &p->gfx, LINK_WAIT, 0);
    MainSprite_Show(p->sprites);
  }
  if (p->exitRequest) {
    p->exitRequest = FALSE;
    p->state = 0;
    p->entered = TRUE;
    p->timer = 0;
  } else {
    p->timer++;
  }
}

void CrossoverMC_StateInterval(CrossoverMC* p) {
  MainSprite* spr;

  if (p->entered) {
    p->entered = FALSE;
    spr = p->sprites;
    MainSprite_SetPose(spr, &p->gfx, LINK_INTERVAL, 0);
    MainSprite_Show(spr);
  }
  if ((p->timer & 127) == 63) {
    spr = p->sprites;
    MainSprite_SetPose(spr, &p->gfx, LINK_PUSHSTART, 0);
  } else if ((p->timer & 127) == 127) {
    spr = p->sprites;
    MainSprite_SetPose(spr, &p->gfx, LINK_INTERVAL, 0);
  }
  if (p->exitRequest) {
    p->exitRequest = FALSE;
    p->state = 0;
    p->entered = TRUE;
    p->timer = 0;
  } else {
    p->timer++;
  }
}

void CrossoverMC_StateRound(CrossoverMC* p) {
  MainSprite* spr;

  if (p->entered) {
    s32 n;
    MainSpriteGfx* gfx;

    p->entered = FALSE;
    n = FUN_08050de8();
    if (n == 1) {
      PlaySound_082406e0(VO_READY);
    }
    spr = &p->sprites[0];
    gfx = &p->gfx;
    MainSprite_SetPose(spr, gfx, LINK_ROUND, 0);
    MainSprite_Show(spr);
    spr = &p->sprites[1];
    MainSprite_SetPose(spr, gfx, LINK_NUMBER_L(Div(n, 10)), 0);
    MainSprite_Show(spr);
    spr = &p->sprites[2];
    MainSprite_SetPose(spr, gfx, LINK_NUMBER_L(Mod(n, 10)), 0);
    MainSprite_Show(spr);
    spr->pos.x = 16;
    spr = &p->sprites[3];
    MainSprite_SetPose(spr, gfx, LINK_MAX_MODE, 0);
    if (FUN_08050dfc()) {
      MainSprite_Show(spr);
    } else {
      MainSprite_Hide(spr);
    }
  }
  if (p->timer == 90) {
    spr = &p->sprites[0];
    MainSprite_SetPose(spr, &p->gfx, LINK_FIGHT, 0);
    MainSprite_Show(spr);
    spr = &p->sprites[1];
    MainSprite_Hide(spr);
    spr = &p->sprites[2];
    MainSprite_Hide(spr);
    spr = &p->sprites[3];
    MainSprite_Hide(spr);
    PlaySound_082406e0(VO_FIGHT);
  }
  if (p->timer - 90 < 8) {
    u16* table;

    spr = &p->sprites[0];
    table = gRandomTable;
    spr->pos.x = (_Random(table) & 3) - 2;
    spr->pos.y = (_Random(table) & 3) - 2;
  }
  if (p->timer == 98) {
    spr = &p->sprites[0];
    spr->pos.x = 0;
    spr->pos.y = 0;
  }
  if (p->exitRequest) {
    p->exitRequest = FALSE;
    p->state = 0;
    p->entered = TRUE;
    p->timer = 0;
  } else {
    p->timer++;
  }
}

void CrossoverMC_StateFight(CrossoverMC* p) {
  MainSprite* spr;

  if (p->entered) {
    p->entered = FALSE;
    spr = p->sprites;
    MainSprite_SetPose(spr, &p->gfx, LINK_FIGHT, 0);
    MainSprite_Show(spr);
    PlaySound_082406e0(VO_FIGHT);
  }
  if (p->timer < 8) {
    u16* table;

    spr = p->sprites;
    table = gRandomTable;
    spr->pos.x = (_Random(table) & 3) - 2;
    spr->pos.y = (_Random(table) & 3) - 2;
  }
  if (p->timer == 8) {
    spr = p->sprites;
    spr->pos.x = 0;
    spr->pos.y = 0;
  }
  if (p->exitRequest) {
    p->exitRequest = FALSE;
    p->state = 0;
    p->entered = TRUE;
    p->timer = 0;
  } else {
    p->timer++;
  }
}

void CrossoverMC_StateFinish(CrossoverMC* p) {
  if (p->entered) {
    p->entered = FALSE;
    MainSprite_SetPose(p->sprites, &p->gfx, LINK_FINISH, 0);
    MainSprite_Show(p->sprites);
    PlaySound_082406e0(SE_ANS_WRONG);
  }
  if (p->exitRequest) {
    p->exitRequest = FALSE;
    p->state = 0;
    p->entered = TRUE;
    p->timer = 0;
  } else {
    p->timer++;
  }
}

s32 CrossoverMC_Update(CrossoverMC* p) {
  static void (*const PTR_ARRAY_085ab70c[6])(CrossoverMC*) = {
      CrossoverMC_StateHidden,
      CrossoverMC_StateWait,
      CrossoverMC_StateInterval,
      CrossoverMC_StateRound,
      CrossoverMC_StateFight,
      CrossoverMC_StateFinish,
  };  // 0x085AB70C

  if (FUN_0804e59c() == FALSE) {
    PTR_ARRAY_085ab70c[p->state](p);
  }
  return 0;
}

s32 CrossoverMC_Destroy(CrossoverMC* p) {
  MainSprite* spr = p->sprites;
  s32 i;

  for (i = 0; i < 4; i++, spr++) {
    MainSprite_Remove(spr);
  }
  return 0;
}

s32 CrossoverMC_Init(CrossoverMC* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_LINK);
  MainSprite* spr;
  s32 i;

  if (f == NULL) {
    return -1;
  }
  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  spr = p->sprites;
  for (i = 0; i < 4; i++, spr++) {
    MainSprite_Add(spr, &p->gfx, LINK_PUSHSTART, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 0, 0, 60, NULL);
  }
  p->state = 0;
  p->entered = TRUE;
  p->timer = 0;
  p->exitRequest = FALSE;
  return 0;
}

CrossoverMC* CrossoverMC_Create(u32 id, u32 unused) {
  CrossoverMC* p = CreateEntity(ENTITY_UNK_11, sizeof(CrossoverMC));

  if (p != NULL) {
    SetEntityRoutine(p, CrossoverMC_Update, CrossoverMC_Destroy);
    if (CrossoverMC_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// state を差し替えてスプライト4枚を隠す
s32 CrossoverMC_SetState(CrossoverMC* p, u32 state) {
  MainSprite* spr;
  s32 i;

  p->state = state;
  p->entered = TRUE;
  p->timer = 0;
  p->exitRequest = FALSE;

  spr = p->sprites;
  for (i = 0; i < 4; i++, spr++) {
    spr->flags |= SPRFLAG_HIDDEN;
  }
  return 0;
}

bool32 CrossoverMC_RequestExit(CrossoverMC* p) {
  p->exitRequest = TRUE;
  return FALSE;
}
