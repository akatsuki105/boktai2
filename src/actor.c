#include "actor.h"

#include "entity.h"
#include "global.h"
#include "malloc.h"
#include "mover.h"
#include "msgbus.h"
#include "player.h"
#include "shadow.h"
#include "sprite.h"
#include "vm.h"

COMMON_DATA ActorManager* gActorManager = NULL;  // 0x03002B50

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

const SoundID16 sFootStepSEs[6] = {SE_FSTEP_M_0, SE_FSTEP_M_1, SE_FSTEP_F_0, SE_FSTEP_F_1, SE_FSTEP_F_0, SE_FSTEP_F_1};  // 0x085AB360

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

NAKED s32 FUN_08040f48(Actor* actor, s32 spriteType, SpriteID32 spriteID, u32 animFileID, SpriteFlags flags) { INCFUNC("asm/func/FUN_08040f48.inc"); }

NAKED s32 FUN_08040fc0(Actor* actor, Vec3* pos, s8 param_3, u32 param_4, s8 param_5) { INCFUNC("asm/func/FUN_08040fc0.inc"); }

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

NAKED s32 FUN_080412fc(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_080412fc.inc"); }

NAKED s32 FUN_0804135c(Actor* actor, s32 param_2, u16 param_3, s8 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_0804135c.inc"); }

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

NAKED s32 FUN_080413fc(Actor* actor, s32 param_2, u16 param_3, s8 param_4, u8 param_5, u16 param_6) { INCFUNC("asm/func/FUN_080413fc.inc"); }

s32 FUN_08041460(Actor* actor, u32 pose, u32 param_3, u32 param_4, u32 param_5, u32 param_6) { return SpriteHolder_SetAnim(&actor->sprite, pose, 0, 0, param_3, param_5, param_6); }

NAKED s32 FUN_08041480(Actor* actor, s32 param_2, s32 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08041480.inc"); }

NAKED void FUN_080414fc(Actor* actor, s32 param_2) { INCFUNC("asm/func/FUN_080414fc.inc"); }

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

// 0xDDD0
NAKED s32 Cmd_DDD0(void) { INCFUNC("asm/func/Cmd_DDD0.inc"); }

// 0x5517
NAKED s32 Cmd_5517(void) { INCFUNC("asm/func/Cmd_5517.inc"); }

// 0x43D6
NAKED s32 Cmd_43D6(void) { INCFUNC("asm/func/Cmd_43D6.inc"); }

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

NAKED void FUN_0804234c(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0804234c.inc"); }

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

NAKED void FUN_08042cf0(ActorManager* p, Actor* actor, s32 param_3) { INCFUNC("asm/func/FUN_08042cf0.inc"); }

NAKED void FUN_08042d50(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08042d50.inc"); }

NAKED void FUN_08042f34(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08042f34.inc"); }

NAKED void FUN_08043108(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08043108.inc"); }

NAKED void FUN_08043360(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08043360.inc"); }

NAKED s32 FUN_080434ac(Actor* actor, PathNode* node) { INCFUNC("asm/func/FUN_080434ac.inc"); }

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

NAKED void FUN_080436c4(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_080436c4.inc"); }

NAKED void FUN_08043774(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08043774.inc"); }

NAKED void FUN_08043960(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08043960.inc"); }

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

NAKED void FUN_08043cf4(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08043cf4.inc"); }

NAKED void FUN_08043da8(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08043da8.inc"); }

NAKED void FUN_08043e54(ActorManager* p, Actor* actor) { INCFUNC("asm/func/FUN_08043e54.inc"); }

NAKED s32 ActorManager_Update(ActorManager* p) { INCFUNC("asm/func/ActorManager_Update.inc"); }

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

NAKED void FUN_080441d8(Actor* actor) { INCFUNC("asm/func/FUN_080441d8.inc"); }

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

NAKED void FUN_080448c8(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_080448c8.inc"); }

NAKED void FUN_0804494c(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_0804494c.inc"); }

NAKED void FUN_080449c0(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_080449c0.inc"); }

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

NAKED void FUN_08044dd8(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08044dd8.inc"); }

NAKED void FUN_08044e6c(ActorManager* p, Actor* actor, s32 elapsed) { INCFUNC("asm/func/FUN_08044e6c.inc"); }

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
