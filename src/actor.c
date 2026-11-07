#include "actor.h"

#include "entity.h"
#include "global.h"
#include "malloc.h"
#include "mover.h"
#include "msgbus.h"
#include "player.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "trig.h"
#include "vm.h"

COMMON_DATA ActorManager* gActorManager = NULL;  // 0x03002B50

s32 FUN_080413b8(Actor* actor, u32 pose, u32 param_3, s32 param_4, u32 param_5, u32 param_6);
s32 FUN_08041460(Actor* actor, u32 pose, u32 param_3, u32 param_4, u32 param_5, u32 param_6);
void FUN_080417dc(Mover* mover);
void FUN_08041918(ActorManager* p);
s32 FUN_080411a0(ActorManager* p, Actor* actor);
bool32 FUN_08018a08(void);

// キャラクターごとのアニメ表, 区切りは sActorSprites の data が指す位置
// clang-format off
const ActorAnim sActorAnims[135] = {
    // SPRITE_DJANGO_SABATA idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   5},

    // SPRITE_DJANGO_SABATA idx 1
    {dirMode : 3, unk_1 : 1, pose : 414},
    {dirMode : 3, unk_1 : 1, pose : 419},
    {dirMode : 3, unk_1 : 1, pose : 414},
    {dirMode : 3, unk_1 : 1, pose : 419},

    // SPRITE_MOUSE idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   1},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   1},

    // SPRITE_SKELETONS idx 0
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   6},
    {dirMode : 2, unk_1 : 1, pose :  30},
    {dirMode : 2, unk_1 : 1, pose :   6},

    // SPRITE_BOKU idx 0
    {dirMode : 2, unk_1 : 0, pose :   7},
    {dirMode : 2, unk_1 : 0, pose :   8},
    {dirMode : 2, unk_1 : 0, pose :   9},
    {dirMode : 2, unk_1 : 0, pose :   8},

    // SPRITE_OTENKO_00 idx 0
    {dirMode : 3, unk_1 : 0, pose :   0},
    {dirMode : 3, unk_1 : 0, pose :   0},
    {dirMode : 3, unk_1 : 0, pose :   0},
    {dirMode : 3, unk_1 : 0, pose :   0},
    {dirMode : 0, unk_1 : 0, pose :   1},
    {dirMode : 0, unk_1 : 0, pose :  10},
    {dirMode : 0, unk_1 : 0, pose :   3},
    {dirMode : 0, unk_1 : 0, pose :  19},
    {dirMode : 0, unk_1 : 0, pose :   0},

    // SPRITE_SMITH_MARCELLO idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   7},
    {dirMode : 1, unk_1 : 0, pose :   9},
    {dirMode : 1, unk_1 : 0, pose :  10},
    {dirMode : 1, unk_1 : 0, pose :  11},
    {dirMode : 1, unk_1 : 0, pose :  12},
    {dirMode : 1, unk_1 : 0, pose :  13},
    {dirMode : 1, unk_1 : 0, pose :  14},
    {dirMode : 1, unk_1 : 0, pose :  15},

    // SPRITE_SHAIAN idx 0
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  14},
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  14},
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  12},
    {dirMode : 1, unk_1 : 1, pose :  40},
    {dirMode : 1, unk_1 : 1, pose :  41},
    {dirMode : 0, unk_1 : 1, pose :   0},

    // SPRITE_RITA idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 2, unk_1 : 2, pose :   7},
    {dirMode : 2, unk_1 : 2, pose :  11},
    {dirMode : 2, unk_1 : 2, pose :  12},
    {dirMode : 1, unk_1 : 1, pose :  15},
    {dirMode : 2, unk_1 : 3, pose :  17},
    {dirMode : 2, unk_1 : 3, pose :  18},
    {dirMode : 2, unk_1 : 3, pose :  19},

    // SPRITE_ZAJI idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 2, unk_1 : 2, pose :  10},
    {dirMode : 1, unk_1 : 0, pose :  14},
    {dirMode : 0, unk_1 : 1, pose :   7},
    {dirMode : 0, unk_1 : 1, pose :   8},
    {dirMode : 0, unk_1 : 1, pose :   9},
    {dirMode : 0, unk_1 : 1, pose :  17},
    {dirMode : 0, unk_1 : 1, pose :  16},

    // SPRITE_SUMIRE idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 0, unk_1 : 1, pose :   7},
    {dirMode : 0, unk_1 : 1, pose :   8},
    {dirMode : 0, unk_1 : 1, pose :  10},
    {dirMode : 0, unk_1 : 1, pose :   9},

    // SPRITE_KURO idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 1, unk_1 : 1, pose :   9},
    {dirMode : 2, unk_1 : 1, pose :   7},
    {dirMode : 1, unk_1 : 1, pose :  10},
    {dirMode : 1, unk_1 : 1, pose :  11},
    {dirMode : 1, unk_1 : 1, pose :  12},
    {dirMode : 1, unk_1 : 1, pose :  13},
    {dirMode : 1, unk_1 : 1, pose :  14},
    {dirMode : 1, unk_1 : 1, pose :  15},
    {dirMode : 3, unk_1 : 1, pose :  16},
    {dirMode : 2, unk_1 : 1, pose :  21},
    {dirMode : 1, unk_1 : 1, pose :  25},
    {dirMode : 2, unk_1 : 1, pose :  23},
    {dirMode : 1, unk_1 : 1, pose :  26},
    {dirMode : 1, unk_1 : 1, pose :  27},
    {dirMode : 1, unk_1 : 1, pose :  28},
    {dirMode : 1, unk_1 : 1, pose :  29},
    {dirMode : 1, unk_1 : 1, pose :  30},
    {dirMode : 1, unk_1 : 1, pose :  31},
    {dirMode : 0, unk_1 : 1, pose :  32},

    // SPRITE_KID idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   7},

    // SPRITE_LADY idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   7},

    // SPRITE_COFFINSELLER_UNKNOWN idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},

    // SPRITE_ENNIO_LUIS idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},

    // SPRITE_DAINN idx 0
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 1, unk_1 : 1, pose :   3},
    {dirMode : 1, unk_1 : 1, pose :   2},

    // SPRITE_SMITH_MARCELLO idx 1
    {dirMode : 3, unk_1 : 1, pose :  16},
    {dirMode : 2, unk_1 : 1, pose :  21},
    {dirMode : 3, unk_1 : 1, pose :  16},
    {dirMode : 2, unk_1 : 1, pose :  23},

    // SPRITE_COFFINSELLER_UNKNOWN idx 1
    {dirMode : 3, unk_1 : 1, pose :   5},
    {dirMode : 2, unk_1 : 1, pose :  10},
    {dirMode : 3, unk_1 : 1, pose :   5},
    {dirMode : 2, unk_1 : 1, pose :  12},

    // SPRITE_ENNIO_LUIS idx 1
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  12},
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  14},

    // SPRITE_MEGAMAN idx 0
    {dirMode : 0, unk_1 : 1, pose :   0},
};  // 0x085AAFF4
// clang-format on

typedef struct {
  SpriteID16 id;          // 0x0, NPCのスプライトIDばっかり
  u8 idx;                 // 0x2, 1つのグラフィックにn人分のグラフィックデータが入っているときにどのキャラクターかを示すインデックス?
  const ActorAnim* data;  // 0x4, そのキャラのアニメ表の先頭
} ActorSpriteEntry;

const ActorSpriteEntry sActorSprites[21] = {
    {id : SPRITE_DJANGO_SABATA,        idx : 0, data : &sActorAnims[0]  },
    {id : SPRITE_MOUSE,                idx : 0, data : &sActorAnims[8]  },
    {id : SPRITE_SKELETONS,            idx : 0, data : &sActorAnims[12] },
    {id : SPRITE_BOKU,                 idx : 0, data : &sActorAnims[16] },
    {id : SPRITE_OTENKO_00,            idx : 0, data : &sActorAnims[20] },
    {id : SPRITE_SMITH_MARCELLO,       idx : 0, data : &sActorAnims[29] },
    {id : SPRITE_SHAIAN,               idx : 0, data : &sActorAnims[40] },
    {id : SPRITE_RITA,                 idx : 0, data : &sActorAnims[49] },
    {id : SPRITE_ZAJI,                 idx : 0, data : &sActorAnims[60] },
    {id : SPRITE_SUMIRE,               idx : 0, data : &sActorAnims[71] },
    {id : SPRITE_KURO,                 idx : 0, data : &sActorAnims[79] },
    {id : SPRITE_KID,                  idx : 0, data : &sActorAnims[100]},
    {id : SPRITE_LADY,                 idx : 0, data : &sActorAnims[104]},
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 0, data : &sActorAnims[108]},
    {id : SPRITE_ENNIO_LUIS,           idx : 0, data : &sActorAnims[112]},
    {id : SPRITE_DAINN,                idx : 0, data : &sActorAnims[116]},
    {id : SPRITE_DJANGO_SABATA,        idx : 1, data : &sActorAnims[4]  },
    {id : SPRITE_SMITH_MARCELLO,       idx : 1, data : &sActorAnims[122]},
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 1, data : &sActorAnims[126]},
    {id : SPRITE_ENNIO_LUIS,           idx : 1, data : &sActorAnims[130]},
    {id : SPRITE_MEGAMAN,              idx : 0, data : &sActorAnims[134]}
};  // 0x085AB210

const ActorFootStepSound sActorFootStepSounds[21] = {
    {id : SPRITE_DJANGO_SABATA,        idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_MOUSE,                idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_SKELETONS,            idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_BOKU,                 idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_OTENKO_00,            idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_SMITH_MARCELLO,       idx : 0, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_SHAIAN,               idx : 0, soundSet : 0, stepFrames : {4, 0, 4, 0}    },
    {id : SPRITE_RITA,                 idx : 0, soundSet : 1, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_ZAJI,                 idx : 0, soundSet : 1, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_SUMIRE,               idx : 0, soundSet : 2, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_KURO,                 idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_KID,                  idx : 0, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_LADY,                 idx : 0, soundSet : 1, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_ENNIO_LUIS,           idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_DAINN,                idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_DJANGO_SABATA,        idx : 1, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPRITE_SMITH_MARCELLO,       idx : 1, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_COFFINSELLER_UNKNOWN, idx : 1, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_ENNIO_LUIS,           idx : 1, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPRITE_MEGAMAN,              idx : 0, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
};  // 0x085AB2B8

const SoundID16 sFootStepSEs[3][2] = {
    {SE_FSTEP_M_0, SE_FSTEP_M_1},
    {SE_FSTEP_F_0, SE_FSTEP_F_1},
    {SE_FSTEP_F_0, SE_FSTEP_F_1},
};  // 0x085AB360

// id と idx の組に対応するデータを表から探す
const ActorAnim* ActorManager_FindSpriteData(SpriteID32 id, s32 idx) {
  s32 i;

  for (i = 0; i < 21; i++) {
    if (sActorSprites[i].id == id && sActorSprites[i].idx == idx) {
      return sActorSprites[i].data;
    }
  }

  return NULL;
}

// スプライトIDとキャラ番号の組に対応する表の行, 無ければ NULL
const ActorFootStepSound* FUN_08040dc0(SpriteID32 id, s32 idx) {
  s32 i;

  for (i = 0; i < 21; i++) {
    if (sActorFootStepSounds[i].id == id && sActorFootStepSounds[i].idx == idx) {
      return &sActorFootStepSounds[i];
    }
  }
  return NULL;
}

s32 FUN_08040df4(ActorManager* p, Actor* actor, SpriteID32 id, s32 idx) {
  actor->unk_2b8 = ActorManager_FindSpriteData(id, idx);

  if (actor->unk_2b8 != NULL) {
    actor->unk_2bc = FUN_08040dc0(id, idx);
    if (actor->unk_2bc != NULL) {
      return 0;
    }
  }
  return -1;
}

// Actor をリストの先頭に繋ぐ
void ActorManager_LinkActor(ActorManager* p, Actor* actor) {
  if (p->head != NULL) {
    p->head->prev = actor;
  }

  actor->prev = NULL;
  actor->next = p->head;
  p->head = actor;
  actor->active = 1;
}

// リンクリストから Actor を外す
void FUN_08040e68(ActorManager* p, Actor* actor) {
  if (actor->prev != NULL) {
    actor->prev->next = actor->next;
  } else {
    p->head = actor->next;
  }
  if (actor->next != NULL) {
    actor->next->prev = actor->prev;
  }
}

// mover.id が id の Actor を探す
Actor* ActorManager_FindActorByMoverID(ActorManager* p, u32 id) {
  Actor* actor = p->head;

  while (actor != NULL) {
    if (actor->mover.id == id) {
      return actor;
    }
    actor = actor->next;
  }

  return NULL;
}

// Actor を1つ確保して種類だけ入れる
Actor* Actor_Alloc(u32 id, u32 kind) {
  Actor* actor;

  if (gActorManager == NULL) {
    return NULL;
  }

  actor = Malloc(sizeof(Actor));
  if (actor == NULL) {
    return NULL;
  }

  ClearMemory(actor, sizeof(Actor));
  actor->kind = kind;
  return actor;
}

// Actor の Mover を初期化して unk_a0 を結び付ける
s32 FUN_08040f0c(Actor* actor, u32 id, Vec3* pos, u32 angle) {
  Mover* mover;

  actor->unk_1b = angle;
  mover = &actor->mover;
  Mover_Init(mover, id, pos, angle, 7, actor);
  FUN_0823b464(mover, (u32)&actor->zoneEvent);
  SET_FLAGS(mover->flags, MOVER_FLAG_2);
}

// spriteType 2 なら MainSprite, それ以外は AuxSprite を用意して mover に結び付け, そのパレットを覚える
s32 FUN_08040f48(Actor* actor, s32 spriteType, SpriteID32 spriteID, u32 animFileID, SpriteFlags flags) {
  SpriteHolder* sprite = &actor->sprite;
  s32 ret;

  if (spriteType == 2) {
    MainSprite* main;

    ret = SpriteHolder_InitMain(sprite, spriteID, flags, &actor->mover.pos);
    main = &actor->sprite.u.main.sprite;
    actor->plttID = main->plttID;
    Mover_SetMainSprite(&actor->mover, main);
  } else {
    AuxSpriteGfx* gfx;

    ret = SpriteHolder_InitAux(sprite, spriteID, animFileID, flags, &actor->mover.pos);
    gfx = &actor->sprite.u.aux.gfx;
    actor->plttID = gfx->plttID;
    Mover_SetAuxSprite(&actor->mover, &actor->sprite.u.aux.sprite);
  }
  actor->curPlttID = actor->plttID;
  SpriteHolder_SetPriority(sprite, 2);
  if (ret < 0) {
    return -1;
  }
}

// 影を用意して表示する, kind 1 なら ParticleShadow, 2 なら大きさ size の AuxShadow
s32 FUN_08040fc0(Actor* actor, Vec3* pos, u32 kind, u32 poseIdx, s32 size) {
  actor->shadowKind = kind;
  if (actor->shadowKind == 1) {
    ParticleShadow_Init(&actor->shadow.ptcl, pos, 1);
    ParticleShadow_Show(&actor->shadow.ptcl);
  } else if (actor->shadowKind == 2) {
    AuxShadow_Init(&actor->shadow.aux, pos, size, size, size, size, 2000, 400, 2, 4, 1);
    AuxShadow_SetSprite(&actor->shadow.aux, SPRITE_EFF_1C1B, poseIdx);
    AuxShadow_Show(&actor->shadow.aux);
  }
  return 0;
}

// 影を描画リストから外す
s32 Actor_RemoveShadow(Actor* actor) {
  if (actor->shadowKind == 1) {
    ParticleShadow_Remove(&actor->shadow.ptcl);
  } else if (actor->shadowKind == 2) {
    AuxShadow_Remove(&actor->shadow.aux);
  }

  return 0;
}

// 影を非表示にする
s32 Actor_HideShadow(Actor* actor) {
  if (actor->shadowKind == 1) {
    ParticleShadow_Hide(&actor->shadow.ptcl);
  } else if (actor->shadowKind == 2) {
    AuxShadow_Hide(&actor->shadow.aux);
  }

  return 0;
}

// 影を表示する
s32 Actor_ShowShadow(Actor* actor) {
  if (actor->shadowKind == 1) {
    ParticleShadow_Show(&actor->shadow.ptcl);
  } else if (actor->shadowKind == 2) {
    AuxShadow_Show(&actor->shadow.aux);
  }

  return 0;
}

s32 FUN_08002a48(Mover*);

s32 FUN_080410cc(Actor* actor) {
  if (FUN_08002a48(&actor->mover) < 0) {
    return -1;
  }
  actor->unk_1ee = 1;
  return 0;
}

// 登録済みなら mover をリストから外す
s32 Actor_RemoveMover(Actor* actor) {
  if (actor->unk_1ee == 0) {
    return -1;
  }

  FUN_08002a58(&actor->mover);
  actor->unk_1ee = 0;
  return 0;
}

s32 Actor_ApplyPltt(Actor* actor, u16 plttID) {
  SpriteHolder* sprite = &actor->sprite;

  actor->curPlttID = plttID;
  return SpriteHolder_SetPlttID(sprite, actor->curPlttID);
}

s32 Actor_SetPltt(Actor* actor, u16 param_2) {
  actor->plttID = param_2;
  return Actor_ApplyPltt(actor, actor->plttID);
}

s32 Actor_RefreshPltt(Actor* actor) { return Actor_ApplyPltt(actor, actor->plttID); }

// Actor を表から外して Free する
s32 FUN_0804114c(Actor* actor) {
  ActorManager* p = gActorManager;

  if (p != NULL && actor->active) {
    FUN_08040e68(p, actor);
    Actor_RemoveMover(actor);
    Mover_Unlink(&actor->mover);
    SpriteHolder_Remove(&actor->sprite);
    Actor_RemoveShadow(actor);
    actor->active = 0;
    Free(actor);
    return 0;
  }
  return -1;
}

// 登録済みのコールバックを順に呼ぶ
s32 FUN_080411a0(ActorManager* p, Actor* actor) {
  s32 i;

  if (!actor->active) {
    return -1;
  }

  for (i = 0; i < 4; i++) {
    if (actor->cbs[i] != NULL) {
      actor->cbs[i](p, actor);
    }
  }
  return 0;
}

NAKED s32 FUN_080411d8(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_080411d8.inc"); }

void FUN_080412f4(void) {}

void FUN_080412f8(void) {}

// ゾーンイベントを更新し, flags の 0x100 なら姿と影を, 0x200 なら影だけを隠す
// 残差: 原典は 0x100 が立っている側 (SpriteHolder_SetFlags) を先に置き, 影を隠す呼び出しを共有する並びになる
NON_MATCH s32 FUN_080412fc(ActorManager* p, Actor* actor) {
#ifdef NONMATCHING_C
  actor->zoneEvent.id = actor->mover.id;
  actor->zoneEvent.pos = &actor->mover.pos;
  Map_UpdateZoneEvents(&actor->zoneEvent);
  if (TEST_FLAGS(actor->flags, ACTORFLAG_UNK_8)) {
    SpriteHolder_SetFlags(&actor->sprite, 1);
  } else {
    SpriteHolder_ClearFlags(&actor->sprite, 1);
    if (!TEST_FLAGS(actor->flags, 0x200)) {
      return Actor_ShowShadow(actor);
    }
  }
  return Actor_HideShadow(actor);
#else
  INCFUNC("asm/func/FUN_080412fc.inc");
#endif
}

// unk_19 から左右反転と向きの番号を作ってアニメを設定する
s32 FUN_0804135c(Actor* actor, u32 pose, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
  SpriteHolder* sprite = &actor->sprite;
  u32 a;
  u32 b;

  if (sprite->kind == 1) {
    if (actor->unk_19 > 1) {
      a = 3 - actor->unk_19;
      b = 1;
    } else {
      a = actor->unk_19;
      b = 0;
    }
  } else {
    a = ((u8)(actor->unk_19 - 1) <= 1) ? param_4 : 0;
    b = actor->unk_19 > 1;
  }
  return SpriteHolder_SetAnim(sprite, pose, a, b, param_3, param_5, param_6);
}

// unk_19 から再生の引数2つを作ってアニメを設定する
// 残差1命令 (34 対 33), 原典は b を r3 (第4引数レジスタ) に直接置くが, こちらは r4 に取るので呼び出し直前に移し替える
// 宣言順 / s32・bool32 / SpriteHolder* ローカル / 呼び出しを2本に分ける形は試済
NON_MATCH s32 FUN_080413b8(Actor* actor, u32 pose, u32 param_3, s32 param_4, u32 param_5, u32 param_6) {
#ifdef NONMATCHING_C
  u32 a;
  u32 b;

  if (actor->sprite.kind == 1) {
    a = actor->unk_19;
    b = a > 1;
  } else {
    a = 0;
    b = actor->unk_19 > 1;
  }
  return SpriteHolder_SetAnim(&actor->sprite, pose, a, b, param_3, param_5, param_6);
#else
  INCFUNC("asm/func/FUN_080413b8.inc");
#endif
}

// unk_1a (8方向) から左右反転と向きの番号を作ってアニメを設定する, 種類が 1 でなければ unk_1a に param_4 を掛ける
s32 FUN_080413fc(Actor* actor, u32 pose, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
  u32 a;
  u32 b;

  if (actor->sprite.kind == 1) {
    if (actor->unk_1a > 4) {
      a = 8 - actor->unk_1a;
      b = 1;
    } else {
      a = actor->unk_1a;
      b = 0;
    }
  } else {
    if (actor->unk_1a > 4) {
      a = 8 - actor->unk_1a;
      b = 1;
    } else {
      a = actor->unk_1a;
      b = 0;
    }
    actor->unk_1a *= param_4;
  }
  return SpriteHolder_SetAnim(&actor->sprite, pose, a, b, param_3, param_5, param_6);
}

s32 FUN_08041460(Actor* actor, u32 pose, u32 param_3, u32 param_4, u32 param_5, u32 param_6) { return SpriteHolder_SetAnim(&actor->sprite, pose, 0, 0, param_3, param_5, param_6); }

// アニメ表の idx 番を引き, 向きの方式 (dirMode) に応じたアニメ設定関数を呼ぶ
s32 FUN_08041480(Actor* actor, s32 idx, s32 param_3, s32 param_4, s32 param_5) {
  const ActorAnim* anim = &actor->unk_2b8[idx];
  s32 ret;

  if (anim->dirMode == 1) {
    ret = FUN_080413b8(actor, anim->pose, param_3, anim->unk_1, param_4, param_5);
  } else if (anim->dirMode == 2) {
    ret = FUN_0804135c(actor, anim->pose, param_3, anim->unk_1, param_4, param_5);
  } else if (anim->dirMode == 3) {
    ret = FUN_080413fc(actor, anim->pose, param_3, anim->unk_1, param_4, param_5);
  } else {
    ret = FUN_08041460(actor, anim->pose, param_3, anim->unk_1, param_4, param_5);
  }
  return ret;
}

// アニメのコマが足音のフレームに来たら足音を鳴らす, animIdx 1 と 3 が歩きのアニメ
// 残差: 命令の並びは一致, 原典は fs を r2, &stepFrames[i] を r3, frame を r1 に置くがこちらは別のレジスタになる
NON_MATCH void FUN_080414fc(Actor* actor, s32 animIdx) {
#ifdef NONMATCHING_C
  u32 frame;
  s32 i;

  if (actor->footStep == 0) {
    return;
  }
  if (animIdx == 1) {
    i = 0;
  } else if (animIdx == 3) {
    i = 2;
  } else {
    return;
  }

  if (SpriteHolder_GetAdvancedCmdIdx(&actor->sprite, &frame)) {
    const ActorFootStepSound* fs = actor->unk_2bc;
    const s8* steps = &fs->stepFrames[i];

    if (steps[0] == frame) {
      PlaySound_082406e0(sFootStepSEs[fs->soundSet][0]);
    } else if (steps[1] == frame) {
      PlaySound_082406e0(sFootStepSEs[fs->soundSet][1]);
    }
  }
#else
  INCFUNC("asm/func/FUN_080414fc.inc");
#endif
}

// 2点が x/z は range 未満, y は 0xFF 以内に収まっているかを返す
bool32 UNUSED FUN_0804157c(Vec3* a, Vec3* b, s32 range) {
  s32 dx, dy, dz;

  dx = abs(b->x - a->x);
  if (dx >= range) {
    return FALSE;
  }
  dy = abs(b->y - a->y);
  if (dy > 0xFF) {
    return FALSE;
  }
  dz = abs(b->z - a->z);
  if (dz >= range) {
    return FALSE;
  }
  return TRUE;
}

NAKED void FUN_080415cc(Actor* actor, s32 param_2, u16 param_3, s16 param_4) { INCFUNC("asm/func/FUN_080415cc.inc"); }

NAKED void FUN_080417dc(Mover* mover) { INCFUNC("asm/func/FUN_080417dc.inc"); }

NAKED void FUN_08041918(ActorManager* p) { INCFUNC("asm/func/FUN_08041918.inc"); }

// 0xDDD0, '.n' / '.k' / '.f' / '.a' / '.p' からメッセージを1件組み立てて送る
s32 Cmd_DDD0(void) {
  ActorManager* p = gActorManager;
  MsgPacket* msg;
  s32 bank;
  u32 count;

  if (p == NULL) {
    return -1;
  }
  bank = p->unk_28;
  count = p->unk_2c[bank];
  if (p->unk_2c[count] > 7) {
    return -1;
  }

  msg = (MsgPacket*)p->msgBufs[bank][count];
  msg->targetID = VM_GetNamedArgValue('n', 0);
  msg->targetClass = VM_GetNamedArgValue('k', 0);
  msg->waitFlag = FALSE;
  msg->unk_4 = VM_GetNamedArgValue('f', 0);
  msg->cmd = VM_GetNamedArgValue('a', 0);
  msg->argc = 0;
  if (VM_SeekToNamedArg('p')) {
    while (VM_GetPC() != NULL) {
      msg->args[msg->argc++] = VM_GetValue();
      if (msg->argc >= 8) {
        break;
      }
    }
  }
  MsgPacket_Send(msg);
  p->unk_2c[p->unk_28]++;
  return 0;
}

// 0x5517
NAKED s32 Cmd_5517(void) { INCFUNC("asm/func/Cmd_5517.inc"); }

// 0x43D6, '.n' の Actor を '.i' が 0 なら state 1, 1 なら state 0 から始め直す, 原典は最後の return を書き忘れている
s32 Cmd_43D6(void) {
  ActorManager* p = gActorManager;
  Actor* actor;
  s32 mode;

  if (p == NULL) {
    return -1;
  }
  actor = ActorManager_FindActorByMoverID(p, VM_GetNamedArgValue('n', 0));
  if (actor == NULL) {
    return -1;
  }

  actor->unk_217 = 0;
  mode = VM_GetNamedArgValue('i', 0);
  switch (mode) {
    case 0: {
      Actor_StartState(actor, 1);
      break;
    }
    case 1: {
      Actor_StartState(actor, 0);
      break;
    }
  }
}

// '.n' の Mover ID の Actor の unk_227 が 13〜15 かどうか
bool32 Cmd_6688(void) {
  ActorManager* p = gActorManager;
  Actor* actor;

  if (p == NULL) {
    return FALSE;
  }

  actor = ActorManager_FindActorByMoverID(p, VM_GetNamedArgValue('n', 0));
  if (actor == NULL) {
    return FALSE;
  }

  if (actor->unk_227 >= 13 && actor->unk_227 <= 15) {
    return TRUE;
  }
  return FALSE;
}

NAKED s32 FUN_08041e10(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08041e10.inc"); }

void FUN_08042178(ActorManager* p, Actor* actor, s32 elapsed) {
  if (actor->unk_09 != 0) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, 0, 2, 0, 4);
  }
  SET_FLAGS(actor->flags, ACTORFLAG_UNK_8);
  actor->fn(actor);
}

void FUN_080421bc(ActorManager* p, Actor* actor, s32 elapsed) {
  if (actor->unk_09 != 0) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, 0, 1, 0, 4);
  }
  SET_FLAGS(actor->flags, ACTORFLAG_UNK_12);
  actor->fn(actor);
}

NAKED void FUN_08042200(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08042200.inc"); }

// mover の向きを unk_1b へ 1フレーム 8 ずつ近づけ, 合ったら終える
// 残差: 原典は新しい向きを s8 に正規化してから格納し, その値を u16 にして Angle_ToDir8/4 に渡すが, こちらは u8 のまま格納して s8→u16 を1回のシフトで作る (Mover.angle が s8 だった形かもしれない)
NON_MATCH void FUN_0804234c(ActorManager* p, Actor* actor, s32 elapsed) {
#ifdef NONMATCHING_C
  if (actor->unk_09) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, 2, 1, 0, 4);
  }
  SET_FLAGS(actor->flags, ACTORFLAG_UNK_12);
  if ((u8)actor->fn(actor) != 1) {
    s8 angle = actor->mover.angle;
    s8 diff = actor->unk_1b - angle;

    if (diff > 8) {
      angle += 8;
    } else if (diff < -8) {
      angle -= 8;
    } else {
      angle += diff;
    }
    actor->mover.angle = angle;
    actor->unk_1a = Angle_ToDir8(angle);
    actor->unk_19 = Angle_ToDir4(angle);
    FUN_08041480(actor, 2, 1, 0, 1);
    if (actor->mover.angle == actor->unk_1b) {
      actor->unk_07 = 1;
    }
  }
#else
  INCFUNC("asm/func/FUN_0804234c.inc");
#endif
}

NAKED void FUN_08042414(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08042414.inc"); }

NAKED void FUN_08042638(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08042638.inc"); }

void FUN_08042868(ActorManager* p, Actor* actor, s32 elapsed) {
  if (actor->unk_09 != 0) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, actor->unk_1e8, actor->unk_1e9, 0, 4);
  }
  SET_FLAGS(actor->flags, ACTORFLAG_UNK_12);
  actor->fn(actor);
}

NAKED void FUN_080428b8(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_080428b8.inc"); }

NAKED void FUN_08042a48(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08042a48.inc"); }

void FUN_08042cf0(ActorManager* p, Actor* actor, s32 elapsed) {
  if (actor->unk_09) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, 0, 1, 0, 4);
    actor->unk_1ec = 1;
  }
  SET_FLAGS(actor->flags, ACTORFLAG_UNK_12);
  if ((u8)actor->fn(actor) != 1 && elapsed > 7) {
    actor->unk_07 = 1;
  }
}

NAKED void FUN_08042d50(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08042d50.inc"); }

NAKED void FUN_08042f34(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08042f34.inc"); }

NAKED void FUN_08043108(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08043108.inc"); }

NAKED void FUN_08043360(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08043360.inc"); }

// 経路のノードを読む: 待ちフレーム数を入れ, 方向転換ノードで向きが違えば 8, 2 番のノードなら 9, それ以外は 7 を返す
// 残差: 原典は delay の上位4bit を lsl/lsr で, command の上位4bit で分岐する所を符号つきの比較木で取り出す, PathNode の delay / command が4bitのビットフィールドだった形に見える
NON_MATCH s32 FUN_080434ac(Actor* actor, PathNode* node) {
#ifdef NONMATCHING_C
  s32 kind = node->command >> 4;
  u16 delay = node->delay;

  actor->pathDelay = delay & 0xFFF;
  switch (kind) {
    case 1: {
      actor->pathDir = delay >> 12;
      if ((((((actor->mover.angle + 0x10) & 0xFF) >> 5) + 3) & 7) != actor->pathDir) {
        return 8;
      }
      break;
    }
    case 2: {
      return 9;
    }
  }
  return 7;
#else
  INCFUNC("asm/func/FUN_080434ac.inc");
#endif
}

// 経路の今のノードが Q8(0.16) 以内にあるときだけ FUN_080434ac へ進む
s32 FUN_08043510(Actor* actor) {
  PathWalker* walker = &actor->pathWalker;
  PathNode* node = walker->node;
  s32 dx = node->x - actor->mover.pos.x;
  s32 dz;

  if (dx < 0) {
    dx = -dx;
  }
  if (dx > 0x28) {
    return 9;
  }

  dz = node->y - actor->mover.pos.z;
  if (dz < 0) {
    dz = -dz;
  }
  if (dz > 0x28) {
    return 9;
  }

  return FUN_080434ac(actor, node);
}

// 待ちが解除されたら unk_05 を 1 にしてメッセージの待ちを終える
void FUN_0804355c(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }

  actor->timer++;
}

// 待ちが解除されたら unk_05 を 2 にしてメッセージの待ちを終える
void FUN_08043588(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 2;
    MsgQueue_EndWait(&actor->mq, 1);
  }

  actor->timer++;
}

// 待ちが解除されたら unk_05 を 3 にして, unk_07 が立っていたら state 1 に移してメッセージの待ちを終える
void FUN_080435b4(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 3;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 1);
    actor->unk_08 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }

  actor->timer++;
}

// 待ちが解除されたら unk_05 を 4 にして, unk_07 が立っていたら state を移してメッセージの待ちを終える
void FUN_080435f0(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 4;
  }

  if (actor->unk_07) {
    if (actor->unk_217) {
      Actor_SetState(actor, actor->unk_227);
      actor->unk_08 = 1;
    } else {
      Actor_SetState(actor, 1);
      actor->unk_08 = 1;
    }
    MsgQueue_EndWait(&actor->mq, 1);
  }

  actor->timer++;
}

// 待ちが解除されたら unk_05 を 5 にして, unk_07 が立っていたら state 1 に移してメッセージの待ちを終える
void FUN_0804364c(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 5;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 1);
    actor->unk_08 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }

  actor->timer++;
}

// 待ちが解除されたら unk_05 を 6 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_08043688(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 6;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 0);
    actor->unk_08 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }

  actor->timer++;
}

// 待ちが解除されたら unk_05 を 2 にしてメッセージの待ちを終える, プレイヤーが近づいたら今の state を覚えて state 10 へ
// 残差: 原典は距離の判定を FUN_0804157c と同じ形の inline で 0/1 に起こし, プレイヤーの有無と合わせてもう一度 0/1 に起こしてから比べる (FUN_08043cf4 と同じ)
NON_MATCH void FUN_080436c4(ActorManager* p, Actor* actor) {
#ifdef NONMATCHING_C
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 2;
    MsgQueue_EndWait(&actor->mq, 1);
  }

  if (p->playerPos != NULL && abs(p->playerPos->x - actor->mover.pos.x) < actor->nearRange && abs(p->playerPos->y - actor->mover.pos.y) <= 0xFF && abs(p->playerPos->z - actor->mover.pos.z) < actor->nearRange) {
    actor->unk_227 = actor->state;
    Actor_SetState(actor, 10);
    actor->unk_08 = 1;
    return;
  }
  actor->timer++;
#else
  INCFUNC("asm/func/FUN_080436c4.inc");
#endif
}

NAKED void FUN_08043774(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08043774.inc"); }

// 経路の向き pathDir を向き, プレイヤーが近づいたら今の state を覚えて state 10 へ, unk_07 が立ったら state 7 へ
// 残差: 原典は距離の判定を FUN_0804157c と同じ形の inline で 0/1 に起こし, プレイヤーの有無と合わせてもう一度 0/1 に起こしてから比べる (FUN_08043cf4 と同じ)
NON_MATCH void FUN_08043960(ActorManager* p, Actor* actor) {
#ifdef NONMATCHING_C
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 4;
    actor->unk_1b = Angle_FromDir8(actor->pathDir);
  }

  if (p->playerPos != NULL && abs(p->playerPos->x - actor->mover.pos.x) < actor->nearRange && abs(p->playerPos->y - actor->mover.pos.y) <= 0xFF && abs(p->playerPos->z - actor->mover.pos.z) < actor->nearRange) {
    actor->unk_227 = actor->state;
    Actor_SetState(actor, 10);
    actor->unk_08 = 1;
  } else if (actor->unk_07) {
    Actor_SetState(actor, 7);
    actor->unk_08 = 1;
  } else {
    actor->timer++;
  }
#else
  INCFUNC("asm/func/FUN_08043960.inc");
#endif
}

NAKED void FUN_08043a24(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08043a24.inc"); }

NAKED void FUN_08043bcc(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08043bcc.inc"); }

// 待ちが解除されたら unk_05 を 10 にして, unk_07 が立っていたら state 12 へ進む
void FUN_08043c94(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 10;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 12);
    actor->unk_08 = 1;
  }

  actor->timer++;
}

// 待ちが解除されたら unk_05 を 11 にして, unk_07 が立っていたら state 14 へ進む
void FUN_08043cc4(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 11;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 14);
    actor->unk_08 = 1;
  }

  actor->timer++;
}

// プレイヤーが近づいたら今の state を覚えて state 10 へ
// 残差: 原典は距離の判定を FUN_0804157c と同じ形の inline で 0/1 に起こし, さらにプレイヤーの有無と合わせてもう一度 0/1 に起こしてから比べる, inline 2段にしても早期の FALSE が外側へ畳まれる
NON_MATCH void FUN_08043cf4(ActorManager* p, Actor* actor) {
#ifdef NONMATCHING_C
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 12;
  }

  if (p->playerPos != NULL && abs(p->playerPos->x - actor->mover.pos.x) < actor->nearRange && abs(p->playerPos->y - actor->mover.pos.y) <= 0xFF && abs(p->playerPos->z - actor->mover.pos.z) < actor->nearRange) {
    actor->unk_227 = actor->state;
    Actor_SetState(actor, 10);
    actor->unk_08 = 1;
    return;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 14);
    actor->unk_08 = 1;
  }
  actor->timer++;
#else
  INCFUNC("asm/func/FUN_08043cf4.inc");
#endif
}

// startHour:startMinute から endHour:endMinute の間に入ったら state 15 へ, waitFrames の間は時刻を見ない
void FUN_08043da8(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }

  if (actor->waitFrames == 0) {
    if (!p->raining && ((p->hour == actor->startHour && p->minute >= actor->startMinute) || (p->hour > actor->startHour && p->hour < actor->endHour) || (p->hour == actor->endHour && p->minute < actor->endMinute))) {
      Actor_SetState(actor, 15);
      actor->unk_08 = 1;
      return;
    }
  } else {
    actor->waitFrames--;
  }
  actor->timer++;
}

// プレイヤーが近づいたら今の state を覚えて state 10 へ
// 残差: 原典は距離の判定を FUN_0804157c と同じ形の inline で 0/1 に起こし, さらにプレイヤーの有無と合わせてもう一度 0/1 に起こしてから比べる, inline 2段にしても早期の FALSE が外側へ畳まれる
NON_MATCH void FUN_08043e54(ActorManager* p, Actor* actor) {
#ifdef NONMATCHING_C
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 13;
  }

  if (p->playerPos != NULL && abs(p->playerPos->x - actor->mover.pos.x) < actor->nearRange && abs(p->playerPos->y - actor->mover.pos.y) <= 0xFF && abs(p->playerPos->z - actor->mover.pos.z) < actor->nearRange) {
    actor->unk_227 = actor->state;
    Actor_SetState(actor, 10);
    actor->unk_08 = 1;
    return;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, FUN_08043510(actor));
    actor->unk_08 = 1;
  }
  actor->timer++;
#else
  INCFUNC("asm/func/FUN_08043e54.inc");
#endif
}

s32 ActorManager_Update(ActorManager* p) {
  Actor* actor;
  Player* player = gPlayerPtr[0];

  p->player = player;
  if (player != NULL) {
    p->playerPos = &player->mover.pos;
  } else {
    p->playerPos = NULL;
  }
  p->raining = FUN_08018a08();
  p->hour = Time_GetHour();
  p->minute = Time_GetMinute();
  if (p->prevMinute != p->minute) {
    p->minuteChanged = TRUE;
  } else {
    p->minuteChanged = FALSE;
  }
  p->prevMinute = p->minute;
  p->unk_28 = 1 - p->unk_28;
  p->unk_2c[p->unk_28] = 0;

  actor = p->head;
  while (actor != NULL) {
    Actor* next = actor->next;

    FUN_080411a0(p, actor);
    actor = next;
  }
  FUN_08041918(p);
  if (p->player != NULL) {
    FUN_080417dc(&p->player->mover);
  }
  p->frameCount++;
  return 0;
}

s32 ActorManager_Destroy(ActorManager* p) {
  Actor* actor = p->head;

  while (actor != NULL) {
    Actor* next = actor->next;

    if (actor->onDestroy != NULL) {
      actor->onDestroy(p, actor);
    }
    FUN_0804114c(actor);
    actor = next;
  }

  gActorManager = NULL;
  return 0;
}

s32 ActorManager_Init(ActorManager* p) {
  Player* pl;

  gActorManager = p;
  p->frameCount = 0;
  p->head = NULL;
  p->unk_28 = 0;
  p->unk_2c[0] = 0;
  p->unk_2c[1] = 0;
  pl = gPlayerPtr[0];
  p->player = pl;
  if (pl != NULL) {
    p->playerPos = &pl->mover.pos;
  } else {
    p->playerPos = NULL;
  }
  return 0;
}

ActorManager* ActorManager_Create(void) {
  if (gActorManager == NULL) {
    ActorManager* p = CreateEntity(ENTITY_UNK_9, sizeof(ActorManager));

    if (p != NULL) {
      SetEntityRoutine(p, ActorManager_Update, ActorManager_Destroy);
      if (ActorManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gActorManager;
}

void FUN_080440ac(ActorManager* p, Actor* actor) {
  if (actor->unk_08 != 0) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 2;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 3 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_080440d0(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 3;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 0);
    actor->unk_08 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 4 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_08044104(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 4;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 0);
    actor->unk_08 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

void FUN_08044138(ActorManager* p, Actor* actor) {
  static void (*const PTR_ARRAY_085ab36c[3])(ActorManager*, Actor*) = {
      FUN_080440ac,
      FUN_080440d0,
      FUN_08044104,
  };  // 0x085AB36C
  PTR_ARRAY_085ab36c[actor->state](p, actor);
}

void FUN_08044150(ActorManager* p, Actor* actor) { FUN_08044138(p, actor); }

s32 FUN_0804415c(ActorManager* p, Actor* actor) {
  FUN_08044150(p, actor);
  return 0;
}

// unk_05 に対応する更新関数を割り当てて動き出せる状態にする
s32 FUN_08044168(Actor* actor) {
  static void (*const PTR_ARRAY_085ab378[14])(ActorManager*, Actor*, s32) = {
      NULL,
      FUN_08042178,
      FUN_080421bc,
      FUN_08042200,
      FUN_0804234c,
      FUN_08042414,
      FUN_08042638,
  };  // 0x085AB378

  ActorUpdate* fn;

  if (actor->unk_05 == 0 || actor->unk_05 > 14) {  // 本来は >= 14 と書くべきものと思われる...
    return 0;
  }

  fn = PTR_ARRAY_085ab378[actor->unk_05];
  actor->unk_06 = actor->unk_05;
  actor->unk_2cc = fn;
  actor->unk_10 = 0;
  actor->unk_09 = 1;
  actor->unk_18 = 0;
  return 1;
}

// Actor の待ちを解除して unk_2cc を呼ぶ
s32 FUN_080441a4(ActorManager* p, Actor* actor) {
  u32 elapsed;

  actor->flags = 0;
  actor->unk_07 = 0;
  elapsed = actor->unk_10++;

  if (actor->unk_2cc != NULL) {
    actor->unk_2cc(p, actor, elapsed);
  }

  return 0;
}

// 届いたメッセージで向き (cmd 2) か歩き先 (cmd 3) を決めて state を始め直す
// 下書き (109/118命令): メッセージ取り出しのループの残差 (Camera_PollMessages / EntityA8F1_HandleMessages と同じ形), 原典は mq と gMsgBus を条件式で毎回読み直す
NON_MATCH void FUN_080441d8(Actor* actor) {
#ifdef NONMATCHING_C
  MsgQueue* mq = &actor->mq;
  s32 i;

  for (i = 0; i < mq->count[gMsgBus->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[gMsgBus->bufIdx][i];

    if (msg->cmd == 2) {
      actor->unk_1b = Angle_FromDir8(msg->args[0]);
      Actor_StartState(actor, 2);
    } else if (msg->cmd == 3) {
      actor->work.walk.target.x = msg->args[0];
      actor->work.walk.target.y = msg->args[1];
      actor->work.walk.target.z = msg->args[2];
      actor->unk_1b = ArcTan2_8(actor->work.walk.target.x - actor->mover.pos.x, actor->work.walk.target.z - actor->mover.pos.z);
      Actor_StartState(actor, 1);
    }
    MsgQueue_BeginWait(mq, msg);
  }
#else
  INCFUNC("asm/func/FUN_080441d8.inc");
#endif
}

s32 FUN_080442d4(ActorManager* p, Actor* actor) {
  FUN_080441d8(actor);
  FUN_080411d8(p, actor);
  actor->unk_05 = 0;
  return 0;
}

s32 FUN_080442f4(ActorManager* p, Actor* actor) {
  FUN_080412fc(p, actor);
  return 0;
}

s32 FUN_08044300(ActorManager* p, Actor* actor) { return MsgQueue_Unregister(&actor->mq); }

// 0x920F, Unused?
NAKED void Cmd_920F(void) { INCFUNC("asm/func/Cmd_920F.inc"); }

void FUN_0804454c(ActorManager* p, Actor* actor) {
  if (actor->unk_08 != 0) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 2 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_08044570(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 2;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 0);
    actor->unk_08 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 3 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_080445a4(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 3;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 0);
    actor->unk_08 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

void FUN_080445d8(ActorManager* p, Actor* actor) {
  if (actor->unk_08 != 0) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 4;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 5 にして, unk_07 が立っていたら state 5 に移してメッセージの待ちを終える
void FUN_080445fc(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 5;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 5);
    actor->unk_08 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

void FUN_08044634(ActorManager* p, Actor* actor) {
  if (actor->unk_08 != 0) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 6;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 7 にして, unk_07 が立っていたら state 7 に移してメッセージの待ちを終える
void FUN_08044658(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 7;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 7);
    actor->unk_08 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 8 にしてメッセージの待ちを終える
void FUN_08044690(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 8;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 9 にしてメッセージの待ちを終える
void FUN_080446b4(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 9;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 10 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_080446d8(ActorManager* p, Actor* actor) {
  if (actor->unk_08) {
    actor->unk_08 = 0;
    actor->unk_07 = 0;
    actor->unk_05 = 10;
  }

  if (actor->unk_07) {
    Actor_SetState(actor, 0);
    actor->unk_08 = 1;
    MsgQueue_EndWait(&actor->mq, 1);
  }
}

void FUN_0804470c(ActorManager* p, Actor* actor) {
  static void (*const PTR_ARRAY_085ab3b0[10])(ActorManager*, Actor*) = {
      FUN_0804454c,
      FUN_08044570,
      FUN_080445a4,
      FUN_080445d8,
      FUN_080445fc,
      FUN_08044634,
      FUN_08044658,
      FUN_08044690,
      FUN_080446b4,
      FUN_080446d8,
  };  // 0x085AB3B0
  PTR_ARRAY_085ab3b0[actor->state](p, actor);
}

void FUN_08044724(ActorManager* p, Actor* actor) { FUN_0804470c(p, actor); }

s32 FUN_08044730(ActorManager* p, Actor* actor) {
  FUN_08044724(p, actor);
  return 0;
}

void FUN_0804473c(ActorManager* p, Actor* actor, s32 elapsed) {
  if (actor->unk_09 != 0) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, 0, 1, 0, 4);
  }
  if ((u8)actor->fn(actor) != 1) {
    FUN_08041480(actor, 0, 1, 0, 1);
  }
}

NAKED void FUN_0804478c(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0804478c.inc"); }

// mover の向きを unk_1b に合わせて向きのアニメを出し, 合ったら終える
void FUN_080448c8(ActorManager* p, Actor* actor, s32 elapsed) {
  if (actor->unk_09) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, 2, 1, 0, 4);
  }
  if ((u8)actor->fn(actor) != 1) {
    u8 angle = actor->unk_1b;

    actor->mover.angle = angle;
    actor->unk_1a = Angle_ToDir8(angle);
    actor->unk_19 = Angle_ToDir4(angle);
    FUN_08041480(actor, 2, 2, 0, 0);
    if (actor->mover.angle == actor->unk_1b) {
      actor->unk_07 = 1;
    }
  }
}

void FUN_0804494c(ActorManager* p, Actor* actor, s32 elapsed) {
  if (actor->unk_09) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, 4, 2, 0, 4);
    actor->work.unk_00 = 0;
  }
  if ((u8)actor->fn(actor) != 1 && SpriteHolder_IsAnimEnded(&actor->sprite)) {
    switch (actor->work.unk_00) {
      case 0: {
        FUN_08041480(actor, 5, 2, 0, 4);
        break;
      }
      case 1: {
        actor->unk_07 = 1;
        break;
      }
      default: {
        return;
      }
    }
    actor->work.unk_00++;
  }
}

void FUN_080449c0(ActorManager* p, Actor* actor, s32 elapsed) {
  if (actor->unk_09) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, 5, 2, 0, 4);
    actor->work.unk_00 = 0;
  }
  if ((u8)actor->fn(actor) != 1 && SpriteHolder_IsAnimEnded(&actor->sprite)) {
    switch (actor->work.unk_00) {
      case 0: {
        FUN_08041480(actor, 6, 2, 0, 4);
        actor->work.unk_00++;
        break;
      }
      case 1: {
        FUN_08041480(actor, 7, 2, 0, 4);
        actor->work.unk_00++;
        break;
      }
      case 2: {
        actor->unk_07 = 1;
        actor->work.unk_00++;
        break;
      }
    }
  }
}

void FUN_08044a54(ActorManager* p, Actor* actor, s32 _) {
  if (actor->unk_09) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, 7, 2, 0, 1);
    actor->work.unk_00 = 0;
  }
  actor->fn(actor);
}

NAKED void FUN_08044a90(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08044a90.inc"); }

void FUN_08044d9c(ActorManager* p, Actor* actor, s32 _) {
  if (actor->unk_09) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, 7, 2, 0, 4);
    actor->work.unk_00 = 0;
  }

  actor->fn(actor);
}

void FUN_08044dd8(ActorManager* p, Actor* actor, s32 elapsed) {
  if (actor->unk_09) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, 7, 2, 0, 4);
    actor->work.unk_00 = 0;
  }
  if ((u8)actor->fn(actor) != 1 && SpriteHolder_IsAnimEnded(&actor->sprite)) {
    switch (actor->work.unk_00) {
      case 0: {
        FUN_08041480(actor, 6, 2, 0, 4);
        actor->work.unk_00++;
        break;
      }
      case 1: {
        FUN_08041480(actor, 5, 2, 0, 4);
        actor->work.unk_00++;
        break;
      }
      case 2: {
        actor->unk_07 = 1;
        actor->work.unk_00++;
        break;
      }
    }
  }
}

void FUN_08044e6c(ActorManager* p, Actor* actor, s32 elapsed) {
  if (actor->unk_09) {
    actor->unk_09 = 0;
    actor->unk_07 = 0;
    FUN_08041480(actor, 5, 2, 0, 4);
    actor->work.unk_00 = 0;
  }
  if ((u8)actor->fn(actor) != 1 && SpriteHolder_IsAnimEnded(&actor->sprite)) {
    switch (actor->work.unk_00) {
      case 0: {
        FUN_08041480(actor, 0, 1, 0, 4);
        break;
      }
      case 1: {
        actor->unk_07 = 1;
        break;
      }
      default: {
        return;
      }
    }
    actor->work.unk_00++;
  }
}

// unk_05 に対応する更新関数を割り当てて動き出せる状態にする
s32 FUN_08044ee0(Actor* actor) {
  static void (*const PTR_ARRAY_085ab3d8[11])(ActorManager*, Actor*, s32) = {
      NULL,
      FUN_0804473c,
      FUN_0804478c,
      FUN_080448c8,
      FUN_0804494c,
      FUN_080449c0,
      FUN_08044a54,
      FUN_08044a90,
      FUN_08044d9c,
      FUN_08044dd8,
      FUN_08044e6c,
  };  // 0x085AB3D8

  ActorUpdate* fn;

  if (actor->unk_05 == 0 || actor->unk_05 > 11) {  // 本来は >= 11 と書くべきものと思われる...
    return 0;
  }

  fn = PTR_ARRAY_085ab3d8[actor->unk_05];
  actor->unk_06 = actor->unk_05;
  actor->unk_2cc = fn;
  actor->unk_10 = 0;
  actor->unk_09 = 1;
  actor->unk_18 = 0;
  return 1;
}

// Actor の待ちを解除して unk_2cc を呼ぶ
s32 FUN_08044f1c(ActorManager* p, Actor* actor) {
  s32 elapsed;

  actor->flags = 0;
  actor->unk_07 = 0;
  elapsed = actor->unk_10++;

  if (actor->unk_2cc != NULL) {
    actor->unk_2cc(p, actor, elapsed);
  }

  return 0;
}

NAKED void FUN_08044f50(Actor* actor) { INCFUNC("asm/func/FUN_08044f50.inc"); }

s32 FUN_08045088(ActorManager* p, Actor* actor) {
  FUN_08044f50(actor);
  FUN_080411d8(p, actor);
  actor->unk_05 = 0;
  return 0;
}

s32 FUN_080450a8(ActorManager* p, Actor* actor) {
  FUN_080412fc(p, actor);
  return 0;
}

s32 FUN_080450b4(ActorManager* p, Actor* actor) { return MsgQueue_Unregister(&actor->mq); }

// 0x0E7C
NAKED void Cmd_0E7C(void) { INCFUNC("asm/func/Cmd_0E7C.inc"); }
