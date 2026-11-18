#include "npc.h"

#include "eff_scatter.h"
#include "emote.h"
#include "entity.h"
#include "global.h"
#include "input.h"
#include "malloc.h"
#include "map_inline.h"
#include "mover.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "time.h"
#include "trig.h"
#include "vec3.h"
#include "vm.h"

COMMON_DATA NPCManager* gNPCManager = NULL;  // 0x03002B50

s32 FUN_080413b8(NPC* npc, u32 pose, u32 param_3, s32 param_4, u32 param_5, u32 param_6);
s32 FUN_08041460(NPC* npc, u32 pose, u32 param_3, u32 param_4, u32 param_5, u32 param_6);
void FUN_080417dc(Mover* mover);
void FUN_08041918(NPCManager* p);
s32 FUN_080411a0(NPCManager* p, NPC* npc);
void FUN_080415cc(NPC* npc, s32 kind, s32 timer, s32 duration);
void Map_ReadPathNodePos(Vec3* dst, PathNode* nodes, u8 idx);
bool8 Map_GetStepToPathNode(PathWalker* w, Vec3* pos, Vec3* out, u8* outAngle, u32 rx, u32 rz, s32 speed);
bool32 FUN_08018a08(void);
WorldPos* Coffin_GetPos(void);
bool32 Player_CanTalk(void);
void Map_StepNavPath(NavAgent* agent, Vec3* pos);
bool32 FUN_0801dfe4(void);
s32 FUN_0801e00c(void);
void PlayForgeStrikeSE(u32 _, s32 kind);
void FUN_0807c7c8(Player* p, s32 mode);

// キャラクターごとのアニメ表, 区切りは sNPCSprites の data が指す位置
// clang-format off
const NPCAnim sNPCAnims[135] = {
    // SPR_DJANGO_SABATA idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   5},

    // SPR_DJANGO_SABATA idx 1
    {dirMode : 3, unk_1 : 1, pose : 414},
    {dirMode : 3, unk_1 : 1, pose : 419},
    {dirMode : 3, unk_1 : 1, pose : 414},
    {dirMode : 3, unk_1 : 1, pose : 419},

    // SPR_MOUSE idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   1},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   1},

    // SPR_SKELETONS idx 0
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   6},
    {dirMode : 2, unk_1 : 1, pose :  30},
    {dirMode : 2, unk_1 : 1, pose :   6},

    // SPR_BOKU_0 idx 0
    {dirMode : 2, unk_1 : 0, pose :   7},
    {dirMode : 2, unk_1 : 0, pose :   8},
    {dirMode : 2, unk_1 : 0, pose :   9},
    {dirMode : 2, unk_1 : 0, pose :   8},

    // SPR_OTENKO_00 idx 0
    {dirMode : 3, unk_1 : 0, pose :   0},
    {dirMode : 3, unk_1 : 0, pose :   0},
    {dirMode : 3, unk_1 : 0, pose :   0},
    {dirMode : 3, unk_1 : 0, pose :   0},
    {dirMode : 0, unk_1 : 0, pose :   1},
    {dirMode : 0, unk_1 : 0, pose :  10},
    {dirMode : 0, unk_1 : 0, pose :   3},
    {dirMode : 0, unk_1 : 0, pose :  19},
    {dirMode : 0, unk_1 : 0, pose :   0},

    // SPR_SMITH_MARCELLO idx 0
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

    // SPR_SHAIAN idx 0
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  14},
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  14},
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  12},
    {dirMode : 1, unk_1 : 1, pose :  40},
    {dirMode : 1, unk_1 : 1, pose :  41},
    {dirMode : 0, unk_1 : 1, pose :   0},

    // SPR_RITA idx 0
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

    // SPR_ZAJI idx 0
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

    // SPR_SUMIRE idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 0, unk_1 : 1, pose :   7},
    {dirMode : 0, unk_1 : 1, pose :   8},
    {dirMode : 0, unk_1 : 1, pose :  10},
    {dirMode : 0, unk_1 : 1, pose :   9},

    // SPR_KURO idx 0
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

    // SPR_KID idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   7},

    // SPR_LADY idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   5},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   7},

    // SPR_COFSELLER_HATENA idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},

    // SPR_ENNIO_LUIS idx 0
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},
    {dirMode : 3, unk_1 : 1, pose :   0},

    // SPR_DAINN idx 0
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 2, unk_1 : 1, pose :   0},
    {dirMode : 1, unk_1 : 1, pose :   3},
    {dirMode : 1, unk_1 : 1, pose :   2},

    // SPR_SMITH_MARCELLO idx 1
    {dirMode : 3, unk_1 : 1, pose :  16},
    {dirMode : 2, unk_1 : 1, pose :  21},
    {dirMode : 3, unk_1 : 1, pose :  16},
    {dirMode : 2, unk_1 : 1, pose :  23},

    // SPR_COFSELLER_HATENA idx 1
    {dirMode : 3, unk_1 : 1, pose :   5},
    {dirMode : 2, unk_1 : 1, pose :  10},
    {dirMode : 3, unk_1 : 1, pose :   5},
    {dirMode : 2, unk_1 : 1, pose :  12},

    // SPR_ENNIO_LUIS idx 1
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  12},
    {dirMode : 3, unk_1 : 1, pose :   7},
    {dirMode : 2, unk_1 : 1, pose :  14},

    // SPR_MEGAMAN idx 0
    {dirMode : 0, unk_1 : 1, pose :   0},
};  // 0x085AAFF4
// clang-format on

typedef struct {
  SpriteID16 id;        // 0x0, NPCのスプライトIDばっかり
  u8 idx;               // 0x2, 1つのグラフィックにn人分のグラフィックデータが入っているときにどのキャラクターかを示すインデックス?
  const NPCAnim* data;  // 0x4, そのキャラのアニメ表の先頭
} NPCSpriteEntry;

const NPCSpriteEntry sNPCSprites[21] = {
    {id : SPR_DJANGO_SABATA,    idx : 0, data : &sNPCAnims[0]  },
    {id : SPR_MOUSE,            idx : 0, data : &sNPCAnims[8]  },
    {id : SPR_SKELETONS,        idx : 0, data : &sNPCAnims[12] },
    {id : SPR_BOKU_0,           idx : 0, data : &sNPCAnims[16] },
    {id : SPR_OTENKO_00,        idx : 0, data : &sNPCAnims[20] },
    {id : SPR_SMITH_MARCELLO,   idx : 0, data : &sNPCAnims[29] },
    {id : SPR_SHAIAN,           idx : 0, data : &sNPCAnims[40] },
    {id : SPR_RITA,             idx : 0, data : &sNPCAnims[49] },
    {id : SPR_ZAJI,             idx : 0, data : &sNPCAnims[60] },
    {id : SPR_SUMIRE,           idx : 0, data : &sNPCAnims[71] },
    {id : SPR_KURO,             idx : 0, data : &sNPCAnims[79] },
    {id : SPR_KID,              idx : 0, data : &sNPCAnims[100]},
    {id : SPR_LADY,             idx : 0, data : &sNPCAnims[104]},
    {id : SPR_COFSELLER_HATENA, idx : 0, data : &sNPCAnims[108]},
    {id : SPR_ENNIO_LUIS,       idx : 0, data : &sNPCAnims[112]},
    {id : SPR_DAINN,            idx : 0, data : &sNPCAnims[116]},
    {id : SPR_DJANGO_SABATA,    idx : 1, data : &sNPCAnims[4]  },
    {id : SPR_SMITH_MARCELLO,   idx : 1, data : &sNPCAnims[122]},
    {id : SPR_COFSELLER_HATENA, idx : 1, data : &sNPCAnims[126]},
    {id : SPR_ENNIO_LUIS,       idx : 1, data : &sNPCAnims[130]},
    {id : SPR_MEGAMAN,          idx : 0, data : &sNPCAnims[134]}
};  // 0x085AB210

const NPCFootStepSound sNPCFootStepSounds[21] = {
    {id : SPR_DJANGO_SABATA,    idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPR_MOUSE,            idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPR_SKELETONS,        idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPR_BOKU_0,           idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPR_OTENKO_00,        idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPR_SMITH_MARCELLO,   idx : 0, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPR_SHAIAN,           idx : 0, soundSet : 0, stepFrames : {4, 0, 4, 0}    },
    {id : SPR_RITA,             idx : 0, soundSet : 1, stepFrames : {2, 0, 2, 0}    },
    {id : SPR_ZAJI,             idx : 0, soundSet : 1, stepFrames : {2, 0, 2, 0}    },
    {id : SPR_SUMIRE,           idx : 0, soundSet : 2, stepFrames : {2, 0, 2, 0}    },
    {id : SPR_KURO,             idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPR_KID,              idx : 0, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPR_LADY,             idx : 0, soundSet : 1, stepFrames : {2, 0, 2, 0}    },
    {id : SPR_COFSELLER_HATENA, idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPR_ENNIO_LUIS,       idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPR_DAINN,            idx : 0, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPR_DJANGO_SABATA,    idx : 1, soundSet : 0, stepFrames : {-1, -1, -1, -1}},
    {id : SPR_SMITH_MARCELLO,   idx : 1, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPR_COFSELLER_HATENA, idx : 1, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPR_ENNIO_LUIS,       idx : 1, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
    {id : SPR_MEGAMAN,          idx : 0, soundSet : 0, stepFrames : {2, 0, 2, 0}    },
};  // 0x085AB2B8

const SoundID16 sFootStepSEs[3][2] = {
    {SE_FSTEP_M_0, SE_FSTEP_M_1},
    {SE_FSTEP_F_0, SE_FSTEP_F_1},
    {SE_FSTEP_F_0, SE_FSTEP_F_1},
};  // 0x085AB360

// gMsgBus をこの inline 越しに読むと, メッセージ取り出しのループで原典どおり毎回プールから読み直す形になる
static inline MsgBus* GetMsgBus(void) { return gMsgBus; }

// pos から target を向く 8bit の向き
static inline s32 GetAngleTo(WorldPos* pos, WorldPos* target) { return ArcTan2_8(target->x - pos->x, target->z - pos->z); }

// id と idx の組に対応するデータを表から探す
const NPCAnim* NPCManager_FindSpriteData(SpriteID32 id, s32 idx) {
  s32 i;

  for (i = 0; i < 21; i++) {
    if (sNPCSprites[i].id == id && sNPCSprites[i].idx == idx) {
      return sNPCSprites[i].data;
    }
  }

  return NULL;
}

// スプライトIDとキャラ番号の組に対応する表の行, 無ければ NULL
const NPCFootStepSound* FUN_08040dc0(SpriteID32 id, s32 idx) {
  s32 i;

  for (i = 0; i < 21; i++) {
    if (sNPCFootStepSounds[i].id == id && sNPCFootStepSounds[i].idx == idx) {
      return &sNPCFootStepSounds[i];
    }
  }
  return NULL;
}

s32 FUN_08040df4(NPCManager* p, NPC* npc, SpriteID32 id, s32 idx) {
  npc->unk_2b8 = NPCManager_FindSpriteData(id, idx);

  if (npc->unk_2b8 != NULL) {
    npc->unk_2bc = FUN_08040dc0(id, idx);
    if (npc->unk_2bc != NULL) {
      return 0;
    }
  }
  return -1;
}

// NPC をリストの先頭に繋ぐ
void NPCManager_LinkNPC(NPCManager* p, NPC* npc) {
  if (p->head != NULL) {
    p->head->prev = npc;
  }

  npc->prev = NULL;
  npc->next = p->head;
  p->head = npc;
  npc->active = 1;
}

// リンクリストから NPC を外す
void FUN_08040e68(NPCManager* p, NPC* npc) {
  if (npc->prev != NULL) {
    npc->prev->next = npc->next;
  } else {
    p->head = npc->next;
  }
  if (npc->next != NULL) {
    npc->next->prev = npc->prev;
  }
}

// mover.id が id の NPC を探す
NPC* NPCManager_FindNPCByMoverID(NPCManager* p, u32 id) {
  NPC* npc = p->head;

  while (npc != NULL) {
    if (npc->mover.id == id) {
      return npc;
    }
    npc = npc->next;
  }

  return NULL;
}

// NPC を1つ確保して種類だけ入れる
NPC* NPC_Alloc(u32 id, u32 kind) {
  NPC* npc;

  if (gNPCManager == NULL) {
    return NULL;
  }

  npc = Malloc(sizeof(NPC));
  if (npc == NULL) {
    return NULL;
  }

  ClearMemory(npc, sizeof(NPC));
  npc->kind = kind;
  return npc;
}

// NPC の Mover を初期化して unk_a0 を結び付ける
s32 FUN_08040f0c(NPC* npc, u32 id, Vec3* pos, u32 angle) {
  Mover* mover;

  npc->unk_1b = angle;
  mover = &npc->mover;
  Mover_Init(mover, id, pos, angle, 7, npc);
  FUN_0823b464(mover, (u32)&npc->zoneEvent);
  SET_FLAGS(mover->flags, MOVER_FLAG_2);
}

// spriteType 2 なら MainSprite, それ以外は AuxSprite を用意して mover に結び付け, そのパレットを覚える
s32 FUN_08040f48(NPC* npc, s32 spriteType, SpriteID32 spriteID, u32 animFileID, SpriteFlags flags) {
  SpriteHolder* sprite = &npc->sprite;
  s32 ret;

  if (spriteType == 2) {
    MainSprite* main;

    ret = SpriteHolder_InitMain(sprite, spriteID, flags, &npc->mover.pos);
    main = &npc->sprite.u.main.spr;
    npc->plttID = main->plttID;
    Mover_SetMainSprite(&npc->mover, main);
  } else {
    AuxSpriteGfx* gfx;

    ret = SpriteHolder_InitAux(sprite, spriteID, animFileID, flags, &npc->mover.pos);
    gfx = &npc->sprite.u.aux.gfx;
    npc->plttID = gfx->plttID;
    Mover_SetAuxSprite(&npc->mover, &npc->sprite.u.aux.spr);
  }
  npc->curPlttID = npc->plttID;
  SpriteHolder_SetPriority(sprite, 2);
  if (ret < 0) {
    return -1;
  }
}

// 影を用意して表示する, kind 1 なら ParticleShadow, 2 なら大きさ size の AuxShadow
s32 FUN_08040fc0(NPC* npc, Vec3* pos, u32 kind, u32 poseIdx, s32 size) {
  npc->shadowKind = kind;
  if (npc->shadowKind == 1) {
    ParticleShadow_Init(&npc->shadow.ptcl, pos, 1);
    ParticleShadow_Show(&npc->shadow.ptcl);
  } else if (npc->shadowKind == 2) {
    AuxShadow_Init(&npc->shadow.aux, pos, size, size, size, size, 2000, 400, 2, 4, 1);
    AuxShadow_SetSprite(&npc->shadow.aux, SPR_EFF_1C1B, poseIdx);
    AuxShadow_Show(&npc->shadow.aux);
  }
  return 0;
}

// 影を描画リストから外す
s32 NPC_RemoveShadow(NPC* npc) {
  if (npc->shadowKind == 1) {
    ParticleShadow_Remove(&npc->shadow.ptcl);
  } else if (npc->shadowKind == 2) {
    AuxShadow_Remove(&npc->shadow.aux);
  }

  return 0;
}

// 影を非表示にする
s32 NPC_HideShadow(NPC* npc) {
  if (npc->shadowKind == 1) {
    ParticleShadow_Hide(&npc->shadow.ptcl);
  } else if (npc->shadowKind == 2) {
    AuxShadow_Hide(&npc->shadow.aux);
  }

  return 0;
}

// 影を表示する
s32 NPC_ShowShadow(NPC* npc) {
  if (npc->shadowKind == 1) {
    ParticleShadow_Show(&npc->shadow.ptcl);
  } else if (npc->shadowKind == 2) {
    AuxShadow_Show(&npc->shadow.aux);
  }

  return 0;
}

s32 FUN_08002a48(Mover*);

s32 FUN_080410cc(NPC* npc) {
  if (FUN_08002a48(&npc->mover) < 0) {
    return -1;
  }
  npc->unk_1ee = 1;
  return 0;
}

// 登録済みなら mover をリストから外す
s32 NPC_RemoveMover(NPC* npc) {
  if (npc->unk_1ee == 0) {
    return -1;
  }

  FUN_08002a58(&npc->mover);
  npc->unk_1ee = 0;
  return 0;
}

s32 NPC_ApplyPltt(NPC* npc, u16 plttID) {
  SpriteHolder* sprite = &npc->sprite;

  npc->curPlttID = plttID;
  return SpriteHolder_SetPlttID(sprite, npc->curPlttID);
}

s32 NPC_SetPltt(NPC* npc, u32 param_2) {
  npc->plttID = param_2;
  return NPC_ApplyPltt(npc, npc->plttID);
}

s32 NPC_RefreshPltt(NPC* npc) { return NPC_ApplyPltt(npc, npc->plttID); }

// NPC を表から外して Free する
s32 FUN_0804114c(NPC* npc) {
  NPCManager* p = gNPCManager;

  if (p != NULL && npc->active) {
    FUN_08040e68(p, npc);
    NPC_RemoveMover(npc);
    Mover_Unlink(&npc->mover);
    SpriteHolder_Remove(&npc->sprite);
    NPC_RemoveShadow(npc);
    npc->active = 0;
    Free(npc);
    return 0;
  }
  return -1;
}

// 登録済みのコールバックを順に呼ぶ
s32 FUN_080411a0(NPCManager* p, NPC* npc) {
  s32 i;

  if (!npc->active) {
    return -1;
  }

  for (i = 0; i < 4; i++) {
    if (npc->cbs[i] != NULL) {
      npc->cbs[i](p, npc);
    }
  }
  return 0;
}

// mover を動かして足元の高さに合わせ, スプライトの位置とアニメを進める, unk_2c8 の待ちが切れたら unk_0a に応じて FUN_080415cc を呼ぶ, 原典は最後の return を書き忘れている
s32 FUN_080411d8(NPCManager* p, NPC* npc) {
  Mover* mover = &npc->mover;
  SpriteHolder* sprite = &npc->sprite;

  Mover_ApplyMove(mover);
  if (!TEST_FLAGS(npc->flags, 0x400)) {
    mover->pos.y = TileHeightAt(&npc->mover.pos);
  }
  SpriteHolder_SetPos(sprite, &mover->pos);
  SpriteHolder_AdvanceAnim(sprite);
  if (npc->unk_2c8 > 0 && --npc->unk_2c8 <= 3) {
    if (npc->unk_0a && !(gGameFlags & GAMEFLAG_CUTSCENE)) {
      npc->unk_2c8 = npc->unk_2ca;
    } else {
      npc->unk_2c8 = 0;
      FUN_080415cc(npc, 8, 180, 180);
      npc->unk_0a = 0;
    }
  }
}

void FUN_080412f4(void) {}

void FUN_080412f8(void) {}

// ゾーンイベントを更新し, flags の 0x100 なら姿と影を, 0x200 なら影だけを隠す
// 残差: 原典は 0x100 が立っている側 (SpriteHolder_SetFlags) を先に置き, 影を隠す呼び出しを共有する並びになる
NON_MATCH s32 FUN_080412fc(NPCManager* p, NPC* npc) {
#ifdef NONMATCHING_C
  npc->zoneEvent.id = npc->mover.id;
  npc->zoneEvent.pos = &npc->mover.pos;
  Map_UpdateZoneEvents(&npc->zoneEvent);
  if (TEST_FLAGS(npc->flags, NPCFLAG_UNK_8)) {
    SpriteHolder_SetFlags(&npc->sprite, 1);
  } else {
    SpriteHolder_ClearFlags(&npc->sprite, 1);
    if (!TEST_FLAGS(npc->flags, 0x200)) {
      return NPC_ShowShadow(npc);
    }
  }
  return NPC_HideShadow(npc);
#else
  INCFUNC("asm/func/FUN_080412fc.inc");
#endif
}

// unk_19 から左右反転と向きの番号を作ってアニメを設定する
s32 FUN_0804135c(NPC* npc, u32 pose, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
  SpriteHolder* sprite = &npc->sprite;
  u32 a;
  u32 b;

  if (sprite->kind == 1) {
    if (npc->unk_19 > DIR4_EAST) {
      a = 3 - npc->unk_19;
      b = 1;
    } else {
      a = npc->unk_19;
      b = 0;
    }
  } else {
    a = ((u8)(npc->unk_19 - 1) <= 1) ? param_4 : 0;
    b = npc->unk_19 > DIR4_EAST;
  }
  return SpriteHolder_SetAnim(sprite, pose, a, b, param_3, param_5, param_6);
}

// unk_19 から再生の引数2つを作ってアニメを設定する
// 残差1命令 (34 対 33), 原典は b を r3 (第4引数レジスタ) に直接置くが, こちらは r4 に取るので呼び出し直前に移し替える
// 宣言順 / s32・bool32 / SpriteHolder* ローカル / 呼び出しを2本に分ける形は試済
NON_MATCH s32 FUN_080413b8(NPC* npc, u32 pose, u32 param_3, s32 param_4, u32 param_5, u32 param_6) {
#ifdef NONMATCHING_C
  u32 a;
  u32 b;

  if (npc->sprite.kind == 1) {
    a = npc->unk_19;
    b = a > 1;
  } else {
    a = 0;
    b = npc->unk_19 > DIR4_EAST;
  }
  return SpriteHolder_SetAnim(&npc->sprite, pose, a, b, param_3, param_5, param_6);
#else
  INCFUNC("asm/func/FUN_080413b8.inc");
#endif
}

// unk_1a (8方向) から左右反転と向きの番号を作ってアニメを設定する, 種類が 1 でなければ unk_1a に param_4 を掛ける
s32 FUN_080413fc(NPC* npc, u32 pose, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
  u32 a;
  u32 b;

  if (npc->sprite.kind == 1) {
    if (npc->unk_1a > 4) {
      a = 8 - npc->unk_1a;
      b = 1;
    } else {
      a = npc->unk_1a;
      b = 0;
    }
  } else {
    if (npc->unk_1a > 4) {
      a = 8 - npc->unk_1a;
      b = 1;
    } else {
      a = npc->unk_1a;
      b = 0;
    }
    npc->unk_1a *= param_4;
  }
  return SpriteHolder_SetAnim(&npc->sprite, pose, a, b, param_3, param_5, param_6);
}

s32 FUN_08041460(NPC* npc, u32 pose, u32 param_3, u32 param_4, u32 param_5, u32 param_6) { return SpriteHolder_SetAnim(&npc->sprite, pose, 0, 0, param_3, param_5, param_6); }

// アニメ表の idx 番を引き, 向きの方式 (dirMode) に応じたアニメ設定関数を呼ぶ
s32 FUN_08041480(NPC* npc, s32 idx, s32 param_3, s32 param_4, s32 param_5) {
  const NPCAnim* anim = &npc->unk_2b8[idx];
  s32 ret;

  if (anim->dirMode == 1) {
    ret = FUN_080413b8(npc, anim->pose, param_3, anim->unk_1, param_4, param_5);
  } else if (anim->dirMode == 2) {
    ret = FUN_0804135c(npc, anim->pose, param_3, anim->unk_1, param_4, param_5);
  } else if (anim->dirMode == 3) {
    ret = FUN_080413fc(npc, anim->pose, param_3, anim->unk_1, param_4, param_5);
  } else {
    ret = FUN_08041460(npc, anim->pose, param_3, anim->unk_1, param_4, param_5);
  }
  return ret;
}

// アニメのコマが足音のフレームに来たら足音を鳴らす, animIdx 1 と 3 が歩きのアニメ
// 残差: 命令の並びは一致, 原典は fs を r2, &stepFrames[i] を r3, frame を r1 に置くがこちらは別のレジスタになる
NON_MATCH void FUN_080414fc(NPC* npc, s32 animIdx) {
#ifdef NONMATCHING_C
  u32 frame;
  s32 i;

  if (npc->footStep == 0) {
    return;
  }
  if (animIdx == 1) {
    i = 0;
  } else if (animIdx == 3) {
    i = 2;
  } else {
    return;
  }

  if (SpriteHolder_GetAdvancedCmdIdx(&npc->sprite, &frame)) {
    const NPCFootStepSound* fs = npc->unk_2bc;
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

// 頭上に吹き出しを出す, kind 0..3 は記号と効果音, 4 / 5 は時間つき, 6 / 7 はそのほか, 8 は今の吹き出しを閉じる
void FUN_080415cc(NPC* npc, s32 kind, s32 timer, s32 duration) {
  switch (kind) {
    case 0: {
      npc->emoteKind = 0;
      npc->emote = Emote_Show(npc->emote, &npc->mover, 0, 1, NULL, 0, 0, 100);
      PlaySound_082406e0(SE_CHARA_SUPRISE);
      break;
    }
    case 2: {
      npc->emoteKind = 0;
      npc->emote = Emote_Show(npc->emote, &npc->mover, 0, 0, NULL, 0, 0, 100);
      PlaySound_082406e0(SONG_492);
      break;
    }
    case 1: {
      npc->emoteKind = 0;
      npc->emote = Emote_Show(npc->emote, &npc->mover, 0, 3, NULL, 0, 0, 100);
      PlaySound_082406e0(SONG_492);
      break;
    }
    case 3: {
      npc->emoteKind = 0;
      npc->emote = Emote_Show(npc->emote, &npc->mover, 0, 2, NULL, 0, 0, 100);
      PlaySound_082406e0(SE_CHARA_QUESTION);
      break;
    }
    case 4: {
      npc->emoteKind = 1;
      npc->unk_2c8 = timer;
      npc->unk_2ca = duration;
      npc->emote = Emote_Show(npc->emote, &npc->mover, 1, 0, (u16*)&npc->unk_2c8, npc->unk_2ca, 0, 100);
      break;
    }
    case 5: {
      npc->emoteKind = 3;
      npc->unk_2c8 = timer;
      npc->unk_2ca = duration;
      npc->emote = Emote_Show(npc->emote, &npc->mover, 3, 0, (u16*)&npc->unk_2c8, npc->unk_2ca, 0, 100);
      break;
    }
    case 6: {
      npc->emoteKind = 5;
      npc->emote = Emote_Show(npc->emote, &npc->mover, 5, 0, NULL, 0, 0, 100);
      break;
    }
    case 7: {
      npc->emoteKind = 4;
      npc->emote = Emote_Show(npc->emote, &npc->mover, 4, 0, NULL, 0, 0, 100);
      break;
    }
    case 8: {
      if (npc->emote != NULL) {
        npc->emote = Emote_Show(npc->emote, &npc->mover, npc->emoteKind, 0x7F, NULL, 0, 0, 100);
      }
      break;
    }
  }
}

// flags 0x1000 の NPC に mover が近すぎたら, その NPC から半径 100 の位置まで押し戻す (イベント中は何もしない)
// 下書き (149/147命令): 呼び出しの並びは一致, ループの入り口の判定の置き方とレジスタ割当が違う
NON_MATCH void FUN_080417dc(Mover* mover) {
#ifdef NONMATCHING_C
  NPCManager* p = gNPCManager;
  NPC* npc;

  if (p == NULL || (gGameFlags & GAMEFLAG_CUTSCENE)) {
    return;
  }

  for (npc = p->head; npc != NULL; npc = npc->next) {
    if (npc->flags & NPCFLAG_UNK_12) {
      s32 dx = mover->pos.x - npc->mover.pos.x;
      s32 dz = mover->pos.z - npc->mover.pos.z;

      if (dx * dx + dz * dz <= 9999) {
        Vec3 pos;

        Vec3_SetPolar(&pos, ArcTan2_8(dx, dz), 100);
        Vec3_Add(&pos, &npc->mover.pos);
        mover->delta.x = pos.x - mover->pos.x;
        mover->delta.y = pos.y - mover->pos.y;
        mover->delta.z = pos.z - mover->pos.z;
        if (mover->tile != NULL) {
          Map_MoveBoxAlongWalls(mover->tile, &mover->pos, &mover->delta, mover->sizeX, mover->sizeZ, mover->unk_4);
        }
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_080417dc.inc");
#endif
}

// プレイヤーが話しかけられる状態なら一番近い話し相手 (flags 0x800 で talkScriptID を持つ NPC) に吹き出しを出し, A ボタンでそのスクリプトを実行する
// 下書き (233/247命令): 流れは一致, 原典はプレイヤーの状態の判定を Player_CanTalk と同じ形の inline で 0/1 に起こし, 話し相手の探し方のレジスタ割当も違う
NON_MATCH void FUN_08041918(NPCManager* p) {
#ifdef NONMATCHING_C
  bool32 pressed = gInput[0].pressed & A_BUTTON;
  s32 form;
  NPC* nearest = NULL;
  NPC* npc;

  if (p->player != NULL && !(p->player->kind == PLAYER_BAT || p->player->kind == PLAYER_MOUSE || p->player->kind == PLAYER_SLEEPING) && !p->player->formRequest &&
      !(p->player->goodCondTimer != 0 && (p->player->goodCondID == GOOD_MINI || p->player->goodCondID == GOOD_INVISIBLE)) && (p->player->action <= PACT_WALK || p->player->action == PACT_UNK_7)) {
    if (p->player->kind == PLAYER_RDJANGO) {
      form = 0;
    } else if (p->player->kind == PLAYER_BDJANGO) {
      form = 1;
    } else if (p->player->kind == PLAYER_SABATA) {
      form = 2;
    } else {
      form = 3;
    }
  } else {
    form = 3;
  }

  if (Player_CanTalk()) {
    s32 minDist = 1000000;

    for (npc = p->head; npc != NULL; npc = npc->next) {
      if ((npc->flags & 0x800) && npc->work.walk.talkScriptID != 0) {
        s32 dx = p->playerPos->x - npc->mover.pos.x;
        s32 dz = p->playerPos->z - npc->mover.pos.z;
        s32 dist = dx * dx + dz * dz;

        if (dist < minDist) {
          minDist = dist;
          nearest = npc;
        }
      }
    }
  }

  if (nearest != NULL && !pressed) {
    for (npc = p->head; npc != NULL; npc = npc->next) {
      if (npc == nearest) {
        if (!nearest->unk_0a) {
          FUN_080415cc(nearest, (&nearest->unk_238)[form], 180, 180);
          nearest->unk_0a = 1;
        }
      } else if (npc->unk_0a) {
        FUN_080415cc(npc, 8, 180, 180);
        npc->unk_0a = 0;
      }
    }
  } else {
    for (npc = p->head; npc != NULL; npc = npc->next) {
      if (npc->unk_0a) {
        FUN_080415cc(npc, 8, 180, 180);
        npc->unk_0a = 0;
      }
    }
  }

  if (nearest != NULL && pressed) {
    u32 argv[8];
    s32 i;

    argv[0] = nearest->mover.id;
    argv[1] = nearest->mover.pos.x;
    argv[2] = nearest->mover.pos.y;
    argv[3] = nearest->mover.pos.z;
    for (i = 0; i < 4; i++) {
      argv[4 + i] = nearest->work.walk.talkArgs[i];
    }
    VM_ExecByID(nearest->work.walk.talkScriptID, NULL);
  }
#else
  INCFUNC("asm/func/FUN_08041918.inc");
#endif
}

// 0xDDD0, '.n' / '.k' / '.f' / '.a' / '.p' からメッセージを1件組み立てて送る
s32 Cmd_SendNPCMsg(void) {
  NPCManager* p = gNPCManager;
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

// 0x5517, '.n' の NPC に向き '.d', 経路 '.r', アニメ '.b' などを設定し, 経路があればその最初のノードの state から始め直す
// 残差: 命令列は一致, 最後の NPC_StartState で原典は state を r0, 0 を r1 に置くが, こちらは state を r1 へ写して入れ替わる
NON_MATCH s32 Cmd_ConfigureNPC(void) {
#ifdef NONMATCHING_C
  NPCManager* p = gNPCManager;
  NPC* npc;
  u32 state;

  if (p == NULL) {
    return -1;
  }
  npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
  if (npc == NULL) {
    return -1;
  }

  if (VM_SeekToNamedArg('d')) {
    s32 angle = VM_GetValue();

    npc->mover.angle = angle;
    npc->unk_1a = Angle_ToDir8(angle);
    npc->unk_19 = Angle_ToDir4(angle);
  }
  if (VM_SeekToNamedArg('r')) {
    npc->pathIdx = VM_GetValue();
    npc->pathParam = VM_GetValue();
    npc->pathNodeIdx = VM_GetValue();
    Mover_SetPath(&npc->mover, &npc->pathWalker, npc->pathIdx, npc->pathParam, npc->pathNodeIdx);
    Map_ReadPathNodePos(&npc->mover.pos, npc->pathWalker.node, npc->pathNodeIdx);
  }
  if (VM_SeekToNamedArg('b')) {
    npc->unk_1e8 = VM_GetValue();
    npc->unk_1e9 = VM_GetValue();
    npc->unk_1ea = VM_GetValue();
  }
  if (VM_SeekToNamedArg('t')) {
    npc->work.walk.talkScriptID = VM_GetValue();
  }
  if (VM_SeekToNamedArg('H')) {
    npc->unk_238 = VM_GetValue();
    npc->unk_239 = VM_GetValue();
    npc->unk_23b = 0xFF;
  }
  if (VM_SeekToNamedArg('u')) {
    npc->unk_0b = VM_GetValue();
  }

  if (npc->pathIdx >= 0) {
    state = FUN_08043510(npc);
  } else {
    state = 6;
  }
  NPC_StartState(npc, state);
  npc->unk_217 = 1;
  return 0;
#else
  INCFUNC("asm/func/Cmd_ConfigureNPC.inc");
#endif
}

// 0x43D6, '.n' の NPC を '.i' が 0 なら state 1, 1 なら state 0 から始め直す, 原典は最後の return を書き忘れている
s32 Cmd_RestartNPC(void) {
  NPCManager* p = gNPCManager;
  NPC* npc;
  s32 mode;

  if (p == NULL) {
    return -1;
  }
  npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
  if (npc == NULL) {
    return -1;
  }

  npc->unk_217 = 0;
  mode = VM_GetNamedArgValue('i', 0);
  switch (mode) {
    case 0: {
      NPC_StartState(npc, 1);
      break;
    }
    case 1: {
      NPC_StartState(npc, 0);
      break;
    }
  }
}

// 0x6688, '.n' の NPC が帰宅中 (unk_227 が 13〜15) かどうか, ハテナの会話 (Scr_TalkHatena) で「きたくちゅう」の分岐に使う
bool32 Cmd_IsNPCGoingHome(void) {
  NPCManager* p = gNPCManager;
  NPC* npc;

  if (p == NULL) {
    return FALSE;
  }

  npc = NPCManager_FindNPCByMoverID(p, VM_GetNamedArgValue('n', 0));
  if (npc == NULL) {
    return FALSE;
  }

  if (npc->unk_227 >= 13 && npc->unk_227 <= 15) {
    return TRUE;
  }
  return FALSE;
}

// スクリプトの名前付き引数から NPC の共通の設定 (経路, 時間帯, アニメ, 近さの範囲, 歩く速さなど) を読む
s32 FUN_08041e10(NPCManager* p, NPC* npc) {
  s32 speed;

  if (VM_GetNamedArgValue('C', 1)) {
    FUN_080410cc(npc);
  }
  npc->unk_215 = npc->mover.angle;
  npc->unk_216 = VM_GetNamedArgValue('C', 1);

  if (VM_SeekToNamedArg('r')) {
    npc->pathIdx = VM_GetValue();
    npc->pathParam = VM_GetValue();
    npc->pathNodeIdx = VM_GetValue();
    Mover_SetPath(&npc->mover, &npc->pathWalker, npc->pathIdx, npc->pathParam, npc->pathNodeIdx);
    Map_ReadPathNodePos(&npc->mover.pos, npc->pathWalker.node, npc->pathNodeIdx);
  } else {
    npc->pathIdx = -1;
  }

  if (VM_SeekToNamedArg('h')) {
    npc->unk_1ed = 1;
    npc->navTarget.x = VM_GetValue();
    npc->navTarget.y = VM_GetValue();
    npc->navTarget.z = VM_GetValue();
  } else {
    npc->unk_1ed = 0;
    npc->navTarget = npc->mover.pos;
  }

  if (VM_SeekToNamedArg('T')) {
    npc->unk_230 = 1;
    npc->startHour = VM_GetValue();
    npc->startMinute = VM_GetValue();
    npc->endHour = VM_GetValue();
    npc->endMinute = VM_GetValue();
  } else {
    npc->unk_230 = 0;
    npc->startHour = 9;
    npc->startMinute = 0;
    npc->endHour = 21;
    npc->endMinute = 0;
  }

  if (VM_SeekToNamedArg('b')) {
    npc->unk_1e8 = VM_GetValue();
    npc->unk_1e9 = VM_GetValue();
    npc->unk_1ea = VM_GetValue();
  } else {
    npc->unk_1e8 = 0;
    npc->unk_1e9 = 1;
    npc->unk_1ea = 0;
  }

  if (VM_SeekToNamedArg('w')) {
    npc->talkRange = VM_GetValue();
    npc->nearRange = VM_GetValue();
    npc->unk_220 = VM_GetValue();
  } else {
    npc->talkRange = 256;
    npc->nearRange = 256;
    npc->unk_220 = 512;
  }

  if (VM_SeekToNamedArg('H')) {
    npc->unk_238 = VM_GetValue();
    npc->unk_239 = VM_GetValue();
    npc->unk_23a = 4;
    npc->unk_23b = 0xFF;
  } else {
    npc->unk_238 = 6;
    npc->unk_239 = 6;
    npc->unk_23a = 4;
    npc->unk_23b = 0xFF;
  }
  npc->unk_23a = VM_GetNamedArgValue('B', 4);
  npc->work.walk.talkScriptID = VM_GetNamedArgValue('t', 0);

  if (VM_SeekToNamedArg('s')) {
    s32 a = VM_GetValue();
    s32 b = VM_GetValue();

    npc->pathSpeed = a;
    npc->unk_1f2 = b;
    npc->unk_1f4 = a;
    npc->unk_1f8 = b;
    npc->unk_1fc = a * a;
    npc->unk_200 = b * b;
  } else {
    s32 a = 80;
    s32 b = 96;

    npc->pathSpeed = a;
    npc->unk_1f2 = b;
    npc->unk_1f4 = a;
    npc->unk_1f8 = b;
    npc->unk_1fc = a * a;
    npc->unk_200 = b * b;
  }

  speed = VM_GetNamedArgValue('M', 10);
  npc->walkSpeed = speed;
  npc->arriveDistSq = speed * speed;
  npc->unk_0b = VM_GetNamedArgValue('u', 1);
  npc->footStep = VM_GetNamedArgValue('F', 1);
  return 0;
}

void FUN_08042178(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->unk_09 != 0) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 0, 2, 0, 4);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_8);
  npc->fn(npc);
}

void FUN_080421bc(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->unk_09 != 0) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 0, 1, 0, 4);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  npc->fn(npc);
}

// work.walk.target へ walkSpeed ずつ歩かせ, 距離の2乗が arriveDistSq 以下になったら着いて終える, 歩くあいだ足音を鳴らす
// 下書き (161/158命令): 流れは一致 (FUN_0804478c と同じ形), 原典は pos / target のアドレスを比較の前に高位レジスタへ移し, npc を r5 に置く
NON_MATCH void FUN_08042200(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 1, 1, 0, 4);
  }
  if ((u8)npc->fn(npc) != 1) {
    WorldPos* pos = &npc->mover.pos;
    WorldPos* target = &npc->work.walk.target;
    s32 dx = target->x - pos->x;
    s32 dz = target->z - pos->z;

    if (dx * dx + dz * dz <= npc->arriveDistSq) {
      npc->mover.pos = npc->work.walk.target;
      npc->unk_07 = 1;
    } else {
      Vec3_SetPolar(&npc->mover.delta, npc->mover.angle, npc->walkSpeed);
      npc->unk_1b = ArcTan2_8(target->x - pos->x, target->z - pos->z);
      npc->mover.angle = npc->unk_1b;
      npc->unk_1a = Angle_ToDir8(npc->unk_1b);
      npc->unk_19 = Angle_ToDir4(npc->unk_1b);
      FUN_08041480(npc, 1, 1, 0, 1);
    }
    FUN_080414fc(npc, 1);
  }
#else
  INCFUNC("asm/func/FUN_08042200.inc");
#endif
}

// mover の向きを unk_1b へ 1フレーム 8 ずつ近づけ, 合ったら終える
// 残差: 原典は新しい向きを s8 に正規化してから格納し, その値を u16 にして Angle_ToDir8/4 に渡すが, こちらは u8 のまま格納して s8→u16 を1回のシフトで作る (Mover.angle が s8 だった形かもしれない)
NON_MATCH void FUN_0804234c(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 2, 1, 0, 4);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  if ((u8)npc->fn(npc) != 1) {
    s8 angle = npc->mover.angle;
    s8 diff = npc->unk_1b - angle;

    if (diff > 8) {
      angle += 8;
    } else if (diff < -8) {
      angle -= 8;
    } else {
      angle += diff;
    }
    npc->mover.angle = angle;
    npc->unk_1a = Angle_ToDir8(angle);
    npc->unk_19 = Angle_ToDir4(angle);
    FUN_08041480(npc, 2, 1, 0, 1);
    if (npc->mover.angle == npc->unk_1b) {
      npc->unk_07 = 1;
    }
  }
#else
  INCFUNC("asm/func/FUN_0804234c.inc");
#endif
}

// 細長い姿で上から落とし, 着地したら横に広げながら縦を縮めて元の大きさに戻す, 終わったら unk_07 を立てる
void FUN_08042414(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    SpriteHolder_SetFlags(&npc->sprite, SPRFLAG_AFFINE);
    SpriteHolder_SetAffine(&npc->sprite, 64, 64, 0);
    PlaySound_082406e0(SONG_513);
  }
  if ((u8)npc->fn(npc) == 1) {
    return;
  }

  {
    s32 scaleY = 64;
    s32 offsetY = 0;
    s32 height;

    switch (npc->unk_18) {
      case 0: {
        offsetY = (8 - elapsed) * 200 + 160;
        height = (GetTileAt(npc->sprite.pos)->heightStairs & 0xF) << 8;
        npc->sprite.pos->y = height + offsetY;
        if (elapsed > 7) {
          npc->unk_18++;
        }
        SpriteHolder_SetAffine(&npc->sprite, 1, 128, 0);
        break;
      }
      case 1: {
        s32 scaleX = 64 - (15 - elapsed) * 4;

        if (elapsed > 8) {
          scaleY = (24 - elapsed) * 8;
          offsetY = (15 - elapsed) * 20;
        }
        if (elapsed > 14) {
          npc->unk_18 = 2;
        }
        height = (GetTileAt(npc->sprite.pos)->heightStairs & 0xF) << 8;
        npc->sprite.pos->y = height + offsetY;
        SpriteHolder_SetAffine(&npc->sprite, scaleX, scaleY, 0);
        break;
      }
      case 2: {
        SpriteHolder_ClearFlags(&npc->sprite, SPRFLAG_AFFINE);
        npc->unk_07 = 1;
        break;
      }
    }
  }
  {
    u8 angle = npc->unk_1b;

    npc->mover.angle = angle;
    npc->unk_1a = Angle_ToDir8(angle);
    npc->unk_19 = Angle_ToDir4(angle);
  }
  FUN_08041480(npc, 0, 2, 0, 0);
}

// FUN_08042414 の逆, 縦を伸ばしながら横を狭めて上へ消えていく, 終わったら unk_07 を立てる
void FUN_08042638(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    SpriteHolder_SetFlags(&npc->sprite, SPRFLAG_AFFINE);
    SpriteHolder_SetAffine(&npc->sprite, 64, 64, 0);
    if (npc->kind == 14) {
      PlaySound_082406e0(SE_WARP_START);
    } else {
      PlaySound_082406e0(SE_WARP_807);
    }
  }

  {
    s32 scaleY = 64;
    s32 offsetY = 0;
    s32 height;

    switch (npc->unk_18) {
      case 0: {
        s32 scaleX = 64 - elapsed * 4;

        if (elapsed > 8) {
          scaleY = elapsed * 8;
          offsetY = (elapsed - 8) * 20;
        }
        if (elapsed > 14) {
          npc->unk_18 = 1;
        }
        height = (GetTileAt(npc->sprite.pos)->heightStairs & 0xF) << 8;
        npc->sprite.pos->y = height + offsetY;
        SpriteHolder_SetAffine(&npc->sprite, scaleX, scaleY, 0);
        break;
      }
      case 1: {
        offsetY = elapsed * 200 + 160;
        height = (GetTileAt(npc->sprite.pos)->heightStairs & 0xF) << 8;
        npc->sprite.pos->y = height + offsetY;
        if (elapsed > 7) {
          SET_FLAGS(npc->flags, NPCFLAG_UNK_8);
          npc->unk_18++;
        }
        break;
      }
      case 2: {
        npc->unk_07 = 1;
        SET_FLAGS(npc->flags, NPCFLAG_UNK_8);
        SpriteHolder_ClearFlags(&npc->sprite, SPRFLAG_AFFINE);
        break;
      }
    }
  }
  {
    u8 angle = npc->unk_1b;

    npc->mover.angle = angle;
    npc->unk_1a = Angle_ToDir8(angle);
    npc->unk_19 = Angle_ToDir4(angle);
  }
  if (npc->kind != 3) {
    FUN_08041480(npc, 0, 2, 0, 0);
  }
  npc->fn(npc);
}

void FUN_08042868(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->unk_09 != 0) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, npc->unk_1e8, npc->unk_1e9, 0, 4);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  npc->fn(npc);
}

// 経路の今のノードへ pathSpeed で歩かせ, 着いたらアニメの区切りを待って終える, MainSprite のときは足を出すコマでだけ進む
// 下書き (165/184命令): 呼び出しの並びは一致, 着いたかの判定と MainSprite のコマの判定の組み立てが違う
NON_MATCH void FUN_080428b8(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  Mover* mover = &npc->mover;
  PathWalker* walker = &npc->pathWalker;
  WorldPos* pos = &npc->mover.pos;
  SpriteHolder* sprite = &npc->sprite;

  if (npc->unk_09) {
    u16 angle;

    npc->unk_09 = 0;
    npc->unk_07 = 0;
    angle = npc->mover.angle = ArcTan2_8(walker->node->x - pos->x, walker->node->y - pos->z);
    npc->unk_1a = Angle_ToDir8(angle);
    npc->unk_19 = Angle_ToDir4(angle);
    FUN_08041480(npc, 1, 1, 0, 4);
    npc->unk_1ec = 0;
    npc->pathArrived = FALSE;
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  if ((u8)npc->fn(npc) == 1) {
    return;
  }

  if (!npc->pathArrived) {
    if (sprite->kind == 2) {
      MainSprite* ms = &sprite->u.main.spr;

      if (ms->animEvents & 4) {
        u16 speed = (ms->animCmdIdx & 1) ? npc->pathSpeed >> 1 : npc->pathSpeed;

        npc->pathArrived = Map_GetStepToPathNode(walker, &mover->pos, &mover->delta, &mover->angle, speed, speed, speed);
      }
    } else {
      npc->pathArrived = Map_GetStepToPathNode(walker, pos, &npc->mover.delta, &npc->mover.angle, npc->pathSpeed, npc->pathSpeed, npc->pathSpeed);
    }
  }
  if (npc->pathArrived) {
    if (sprite->kind == 2) {
      if (sprite->kind & sprite->u.main.spr.animEvents) {
        npc->unk_07 = 1;
      }
    } else if (SpriteHolder_IsAnimEnded(sprite)) {
      npc->unk_07 = 1;
    }
  }
  FUN_080414fc(npc, 1);
  FUN_08041480(npc, 1, 1, 0, 1);
#else
  INCFUNC("asm/func/FUN_080428b8.inc");
#endif
}

// プレイヤーの方へ 1フレーム 8 ずつ向き, 話しかけられない状態のプレイヤーには吹き出しを出す, 近くで向かい合ったら NPCFLAG_TALKABLE を立てる
// 下書き (283/316命令): 原典は向きの更新を分岐ごとに持ち (inline の展開に見える), 距離の判定とプレイヤーの状態の判定を 0/1 に起こしてから比べる
NON_MATCH void FUN_08042a48(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  Vec3* pos = &npc->mover.pos;
  s32 playerAngle;

  if (p->playerPos != NULL) {
    s8 diff = ArcTan2_8(p->playerPos->x - pos->x, p->playerPos->z - pos->z) - npc->mover.angle;
    u16 angle;

    if (diff > 8) {
      angle = npc->mover.angle + 8;
    } else if (diff < -8) {
      angle = npc->mover.angle - 8;
    } else {
      angle = npc->mover.angle + diff;
    }
    npc->mover.angle = angle;
    npc->unk_1a = Angle_ToDir8(angle);
    npc->unk_19 = Angle_ToDir4(angle);
    playerAngle = p->player->mover.angle;
  } else {
    playerAngle = 0;
  }

  if (npc->unk_09) {
    Player* player;

    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 0, 1, 0, 4);
    npc->unk_1ec = 1;
    npc->unk_225 = npc->mover.angle;
    player = p->player;
    if (player != NULL) {
      if (!(player->kind == PLAYER_BAT || player->kind == PLAYER_MOUSE || player->kind == PLAYER_SLEEPING) && !player->formRequest && !(player->goodCondTimer != 0 && (player->goodCondID == GOOD_MINI || player->goodCondID == GOOD_INVISIBLE)) &&
          (player->action <= PACT_WALK || player->action == PACT_UNK_7)) {
      } else if (!(gGameFlags & GAMEFLAG_CUTSCENE) && npc->unk_0b) {
        if ((p->player->action == PACT_PULL_COFFIN && Coffin_GetPos() != NULL) || TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
          FUN_080415cc(npc, 0, 0, 0);
        } else {
          FUN_080415cc(npc, 3, 0, 0);
        }
      }
    }
  } else {
    FUN_08041480(npc, 0, 1, 0, 1);
  }

  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  if ((u8)npc->fn(npc) == 1) {
    return;
  }
  if (abs(p->playerPos->x - pos->x) < npc->talkRange && abs(p->playerPos->y - pos->y) <= 0xFF && abs(p->playerPos->z - pos->z) < npc->talkRange) {
    s8 toPlayer = ArcTan2_8(pos->x - p->playerPos->x, pos->z - p->playerPos->z);
    s8 facing = playerAngle - toPlayer;
    s8 back = playerAngle - (npc->mover.angle + 0x80);

    if (abs(facing) <= 63 && abs(back) <= 31) {
      SET_FLAGS(npc->flags, NPCFLAG_TALKABLE);
    }
  }
#else
  INCFUNC("asm/func/FUN_08042a48.inc");
#endif
}

void FUN_08042cf0(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 0, 1, 0, 4);
    npc->unk_1ec = 1;
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  if ((u8)npc->fn(npc) != 1 && elapsed > 7) {
    npc->unk_07 = 1;
  }
}

// navTarget へナビメッシュで歩かせ, 目的地に近づいたら終える, MainSprite のコマが進むたびに 32/64 (それ以外は 16) 進む
// 下書き (222/223命令): 命令列はほぼ一致, 残差はレジスタ割当 (定数オフセットの一時レジスタと pos の置き場所), 試済: FUN_08042f34 と同じく waypoint を npc->navAgent 経由で読む (226), Vec3* wp を使う (229)
NON_MATCH void FUN_08042d50(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  Mover* mover = &npc->mover;
  NavAgent* nav = &npc->navAgent;
  SpriteHolder* sprite = &npc->sprite;

  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 3, 1, 0, 4);
    npc->unk_1ec = 1;
    Map_InitNavAgent(nav, &npc->mover.pos);
    Map_TryFindNavRoute(nav, &npc->mover.pos, &npc->navTarget);
    npc->unk_224 = 0;
    FUN_080415cc(npc, 0, 0, 0);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  if ((u8)npc->fn(npc) == 1) {
    return;
  }

  {
    Vec3* pos = &npc->mover.pos;
    Vec3* dest = &nav->dest;
    u32 frame;
    s32 dx = nav->dest.x - mover->pos.x;
    s32 dz = dest->z - pos->z;

    if (dx * dx + dz * dz <= 4355) {
      mover->pos.x = nav->waypoint.x;
      mover->pos.z = nav->waypoint.z;
      npc->unk_07 = 1;
    } else if (SpriteHolder_GetAdvancedCmdIdx(sprite, &frame)) {
      s32 speed;
      Vec3 step;
      s32 angle;

      if (sprite->kind == 2) {
        speed = (frame & 1) ? 32 : 64;
      } else {
        speed = 16;
      }
      angle = ArcTan2_8(nav->waypoint.x - mover->pos.x, nav->waypoint.z - pos->z);
      npc->mover.angle = angle;
      npc->unk_1a = Angle_ToDir8(angle);
      npc->unk_19 = Angle_ToDir4(angle);
      Vec3_SetPolar(&step, mover->angle, speed);
      mover->pos.x += step.x;
      mover->pos.z += step.z;
    }
  }
  Map_StepNavPath(nav, &npc->mover.pos);
  FUN_080414fc(npc, 3);
  FUN_08041480(npc, 3, 1, 0, 1);
#else
  INCFUNC("asm/func/FUN_08042d50.inc");
#endif
}

// navTarget へナビメッシュで歩かせ, 目的地に近づいたら終える, MainSprite の足を出すコマでだけ 48 進む
void FUN_08042f34(NPCManager* p, NPC* npc, s32 elapsed) {
  Mover* mover = &npc->mover;
  NavAgent* nav = &npc->navAgent;
  SpriteHolder* sprite = &npc->sprite;

  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 1, 1, 0, 4);
    npc->unk_1ec = 0;
    Map_InitNavAgent(nav, &npc->mover.pos);
    Map_TryFindNavRoute(nav, &npc->mover.pos, &npc->navTarget);
    npc->unk_224 = 1;
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  if ((u8)npc->fn(npc) == 1) {
    return;
  }

  {
    Vec3* pos = &npc->mover.pos;
    Vec3* dest = &nav->dest;
    s32 dx = nav->dest.x - mover->pos.x;
    s32 dz = dest->z - pos->z;

    if (dx * dx + dz * dz <= 2499) {
      mover->pos.x = npc->navAgent.waypoint.x;
      mover->pos.z = npc->navAgent.waypoint.z;
      npc->unk_07 = 1;
    } else if (sprite->kind == 2) {
      MainSprite* main = &sprite->u.main.spr;

      if (main->animEvents & 4) {
        Vec3 step;
        s32 angle;
        Vec3* wp = &nav->waypoint;

        angle = ArcTan2_8(nav->waypoint.x - mover->pos.x, wp->z - pos->z);
        npc->mover.angle = angle;
        npc->unk_1a = Angle_ToDir8(angle);
        npc->unk_19 = Angle_ToDir4(angle);
        Vec3_SetPolar(&step, mover->angle, 48);
        mover->pos.x += step.x;
        mover->pos.z += step.z;
      }
    }
  }
  Map_StepNavPath(nav, &npc->mover.pos);
  FUN_080414fc(npc, 1);
  FUN_08041480(npc, 1, 1, 0, 1);
}

// 経路の最初のノードへナビメッシュで歩かせ, 近づいたら終える, MainSprite の足を出すコマでだけ 24/48 進む
void FUN_08043108(NPCManager* p, NPC* npc, s32 elapsed) {
  Mover* mover = &npc->mover;
  NavAgent* nav = &npc->navAgent;
  PathWalker* walker = &npc->pathWalker;
  SpriteHolder* sprite = &npc->sprite;

  if (npc->unk_09) {
    Vec3 start;
    Vec3* pos;
    Vec3* wp;
    s32 angle;

    npc->unk_09 = 0;
    npc->unk_07 = 0;
    npc->unk_1ec = 0;
    pos = &npc->mover.pos;
    Map_InitNavAgent(nav, pos);
    Map_InitPathWalker(walker, npc->pathIdx, npc->pathParam, npc->pathNodeIdx);
    Map_ReadPathNodePos(&start, npc->pathWalker.node, 0);
    Map_TryFindNavRoute(nav, pos, &start);
    wp = &nav->waypoint;
    angle = ArcTan2_8(nav->waypoint.x - mover->pos.x, wp->z - pos->z);
    npc->mover.angle = angle;
    npc->unk_1a = Angle_ToDir8(angle);
    npc->unk_19 = Angle_ToDir4(angle);
    FUN_08041480(npc, 1, 1, 0, 4);
  }
  SET_FLAGS(npc->flags, NPCFLAG_UNK_12);
  if ((u8)npc->fn(npc) == 1) {
    return;
  }

  {
    Vec3* pos = &npc->mover.pos;
    Vec3* dest = &nav->dest;
    u32 frame;
    s32 dx = nav->dest.x - mover->pos.x;
    s32 dz = dest->z - pos->z;

    if (dx * dx + dz * dz <= 2499) {
      mover->pos.x = npc->navAgent.waypoint.x;
      mover->pos.z = npc->navAgent.waypoint.z;
      npc->unk_07 = 1;
    } else if (sprite->kind == 2) {
      MainSprite* main = &sprite->u.main.spr;

      if (main->animEvents & 4) {
        s32 speed;
        Vec3 step;
        s32 angle;
        Vec3* wp = &nav->waypoint;

        angle = ArcTan2_8(nav->waypoint.x - mover->pos.x, wp->z - pos->z);
        npc->mover.angle = angle;
        npc->unk_1a = Angle_ToDir8(angle);
        npc->unk_19 = Angle_ToDir4(angle);
        speed = (main->animCmdIdx & 1) ? 24 : 48;
        Vec3_SetPolar(&step, mover->angle, speed);
        mover->pos.x += step.x;
        mover->pos.z += step.z;
      }
    }
  }
  Map_StepNavPath(nav, &npc->mover.pos);
  FUN_080414fc(npc, 1);
  FUN_08041480(npc, 1, 1, 0, 1);
}

// work.walk.target へ walkSpeed ずつ歩かせ, 距離の2乗が arriveDistSq 以下になったら着いて終える, 歩くあいだ足音を鳴らす
// 下書き (161/158命令): 流れは一致 (FUN_0804478c と同じ形), 原典は pos / target のアドレスを比較の前に高位レジスタへ移し, npc を r5 に置く
NON_MATCH void FUN_08043360(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 3, 1, 0, 4);
  }
  if ((u8)npc->fn(npc) != 1) {
    WorldPos* pos = &npc->mover.pos;
    WorldPos* target = &npc->work.walk.target;
    s32 dx = target->x - pos->x;
    s32 dz = target->z - pos->z;

    if (dx * dx + dz * dz <= npc->arriveDistSq) {
      npc->mover.pos = npc->work.walk.target;
      npc->unk_07 = 1;
    } else {
      Vec3_SetPolar(&npc->mover.delta, npc->mover.angle, npc->walkSpeed);
      npc->unk_1b = ArcTan2_8(target->x - pos->x, target->z - pos->z);
      npc->mover.angle = npc->unk_1b;
      npc->unk_1a = Angle_ToDir8(npc->unk_1b);
      npc->unk_19 = Angle_ToDir4(npc->unk_1b);
      FUN_08041480(npc, 3, 1, 0, 1);
    }
    FUN_080414fc(npc, 3);
  }
#else
  INCFUNC("asm/func/FUN_08043360.inc");
#endif
}

// 経路のノードを読む: 待ちフレーム数を入れ, 方向転換ノードで向きが違えば 8, 2 番のノードなら 9, それ以外は 7 を返す
// 残差: 原典は delay の上位4bit を lsl/lsr で, command の上位4bit で分岐する所を符号つきの比較木で取り出す, PathNode の delay / command が4bitのビットフィールドだった形に見える
NON_MATCH s32 FUN_080434ac(NPC* npc, PathNode* node) {
#ifdef NONMATCHING_C
  s32 kind = node->command >> 4;
  u16 delay = node->delay;

  npc->pathDelay = delay & 0xFFF;
  switch (kind) {
    case 1: {
      npc->pathDir = delay >> 12;
      if (Angle_ToDir8(npc->mover.angle) != npc->pathDir) {
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
s32 FUN_08043510(NPC* npc) {
  PathWalker* walker = &npc->pathWalker;
  PathNode* node = walker->node;
  s32 dx = abs(node->x - npc->mover.pos.x);
  s32 dz;

  if (dx > Q8(0.16)) {
    return 9;
  }

  dz = abs(node->y - npc->mover.pos.z);
  if (dz > Q8(0.16)) {
    return 9;
  }

  return FUN_080434ac(npc, node);
}

// 待ちが解除されたら unk_05 を 1 にしてメッセージの待ちを終える
void FUN_0804355c(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->timer++;
}

// 待ちが解除されたら unk_05 を 2 にしてメッセージの待ちを終える
void FUN_08043588(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 2;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->timer++;
}

// 待ちが解除されたら unk_05 を 3 にして, unk_07 が立っていたら state 1 に移してメッセージの待ちを終える
void FUN_080435b4(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 3;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 1);
    npc->unk_08 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->timer++;
}

// 待ちが解除されたら unk_05 を 4 にして, unk_07 が立っていたら state を移してメッセージの待ちを終える
void FUN_080435f0(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 4;
  }

  if (npc->unk_07) {
    if (npc->unk_217) {
      NPC_SetState(npc, npc->unk_227);
      npc->unk_08 = 1;
    } else {
      NPC_SetState(npc, 1);
      npc->unk_08 = 1;
    }
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->timer++;
}

// 待ちが解除されたら unk_05 を 5 にして, unk_07 が立っていたら state 1 に移してメッセージの待ちを終える
void FUN_0804364c(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 5;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 1);
    npc->unk_08 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->timer++;
}

// 待ちが解除されたら unk_05 を 6 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_08043688(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 6;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 0);
    npc->unk_08 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  npc->timer++;
}

// 待ちが解除されたら unk_05 を 2 にしてメッセージの待ちを終える, プレイヤーが近づいたら今の state を覚えて state 10 へ
// 残差: 原典は距離の判定を FUN_0804157c と同じ形の inline で 0/1 に起こし, プレイヤーの有無と合わせてもう一度 0/1 に起こしてから比べる (FUN_08043cf4 と同じ)
NON_MATCH void FUN_080436c4(NPCManager* p, NPC* npc) {
#ifdef NONMATCHING_C
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 2;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  if (p->playerPos != NULL && abs(p->playerPos->x - npc->mover.pos.x) < npc->nearRange && abs(p->playerPos->y - npc->mover.pos.y) <= 0xFF && abs(p->playerPos->z - npc->mover.pos.z) < npc->nearRange) {
    npc->unk_227 = npc->state;
    NPC_SetState(npc, 10);
    npc->unk_08 = 1;
    return;
  }
  npc->timer++;
#else
  INCFUNC("asm/func/FUN_080436c4.inc");
#endif
}

// 経路のノードで待つ: 16 フレームごとに棺桶や雨や時間帯を見て state 12 / 13 へ, プレイヤーが近づいたら state 10, 待ち時間が切れたら次のノードへ進む
// 下書き (219/223命令): 流れは一致 (FUN_08043a24 と同じ形), 距離の判定と state の設定ブロックの共有のしかたが違う
NON_MATCH void FUN_08043774(NPCManager* p, NPC* npc) {
#ifdef NONMATCHING_C
  PathWalker* walker = &npc->pathWalker;

  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 2;
  }

  if ((npc->timer & 0xF) == 0) {
    if (npc->unk_1ed != 0) {
      Vec3* coffinPos = Coffin_GetPos();
      bool32 near = FALSE;

      if (coffinPos != NULL) {
        s32 dx = npc->mover.pos.x - coffinPos->x;
        s32 dz = npc->mover.pos.z - coffinPos->z;

        if (dx * dx + dz * dz <= 159999) {
          near = TRUE;
        }
      }
      if (near) {
        npc->waitFrames = 1800;
        NPC_SetState(npc, 12);
        npc->unk_08 = 1;
        return;
      }
      if (npc->unk_1ed != 0 && p->raining) {
        npc->waitFrames = 300;
        NPC_SetState(npc, 12);
        npc->unk_08 = 1;
        return;
      }
    }
    if (npc->unk_230 != 0 && p->minuteChanged) {
      if ((p->hour == npc->endHour && p->minute >= npc->endMinute) || (p->hour - 1 == npc->endHour && p->minute <= npc->endMinute)) {
        NPC_SetState(npc, 13);
        npc->unk_08 = 1;
        return;
      }
    }
  }

  if (p->playerPos != NULL && abs(p->playerPos->x - npc->mover.pos.x) < npc->nearRange && abs(p->playerPos->y - npc->mover.pos.y) <= 0xFF && abs(p->playerPos->z - npc->mover.pos.z) < npc->nearRange) {
    npc->unk_227 = npc->state;
    NPC_SetState(npc, 10);
    npc->unk_08 = 1;
    return;
  }

  if (npc->pathIdx >= 0) {
    if (npc->pathDelay == 0) {
      Map_AdvancePathWalker(walker);
      NPC_SetState(npc, FUN_08043510(npc));
      npc->unk_08 = 1;
    } else {
      npc->pathDelay--;
    }
  }
  npc->timer++;
#else
  INCFUNC("asm/func/FUN_08043774.inc");
#endif
}

// 経路の向き pathDir を向き, プレイヤーが近づいたら今の state を覚えて state 10 へ, unk_07 が立ったら state 7 へ
// 残差: 原典は距離の判定を FUN_0804157c と同じ形の inline で 0/1 に起こし, プレイヤーの有無と合わせてもう一度 0/1 に起こしてから比べる (FUN_08043cf4 と同じ)
NON_MATCH void FUN_08043960(NPCManager* p, NPC* npc) {
#ifdef NONMATCHING_C
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 4;
    npc->unk_1b = Angle_FromDir8(npc->pathDir);
  }

  if (p->playerPos != NULL && abs(p->playerPos->x - npc->mover.pos.x) < npc->nearRange && abs(p->playerPos->y - npc->mover.pos.y) <= 0xFF && abs(p->playerPos->z - npc->mover.pos.z) < npc->nearRange) {
    npc->unk_227 = npc->state;
    NPC_SetState(npc, 10);
    npc->unk_08 = 1;
  } else if (npc->unk_07) {
    NPC_SetState(npc, 7);
    npc->unk_08 = 1;
  } else {
    npc->timer++;
  }
#else
  INCFUNC("asm/func/FUN_08043960.inc");
#endif
}

// 16 フレームごとに, 棺桶が近いか雨なら state 12 へ, 時間帯の終わりに来たら state 13 へ, プレイヤーが近づいたら state 10, unk_07 で state 7 へ
// 下書き (199/196命令): 流れは一致, プレイヤーとの距離の判定は FUN_08043cf4 と同じ残差, state 12 / 13 の設定ブロックの共有のしかたも違う
NON_MATCH void FUN_08043a24(NPCManager* p, NPC* npc) {
#ifdef NONMATCHING_C
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 8;
  }

  if ((npc->timer & 0xF) == 0) {
    if (npc->unk_1ed != 0) {
      Vec3* coffinPos = Coffin_GetPos();
      bool32 near = FALSE;

      if (coffinPos != NULL) {
        s32 dx = npc->mover.pos.x - coffinPos->x;
        s32 dz = npc->mover.pos.z - coffinPos->z;

        if (dx * dx + dz * dz <= 159999) {
          near = TRUE;
        }
      }
      if (near) {
        npc->waitFrames = 1800;
        NPC_SetState(npc, 12);
        npc->unk_08 = 1;
        return;
      }
      if (npc->unk_1ed != 0 && p->raining) {
        npc->waitFrames = 300;
        NPC_SetState(npc, 12);
        npc->unk_08 = 1;
        return;
      }
    }
    if (npc->unk_230 != 0 && p->minuteChanged) {
      if ((p->hour == npc->endHour && p->minute >= npc->endMinute) || (p->hour - 1 == npc->endHour && p->minute <= npc->endMinute)) {
        NPC_SetState(npc, 13);
        npc->unk_08 = 1;
        return;
      }
    }
  }

  if (p->playerPos != NULL && abs(p->playerPos->x - npc->mover.pos.x) < npc->nearRange && abs(p->playerPos->y - npc->mover.pos.y) <= 0xFF && abs(p->playerPos->z - npc->mover.pos.z) < npc->nearRange) {
    npc->unk_227 = npc->state;
    NPC_SetState(npc, 10);
    npc->unk_08 = 1;
  } else if (npc->unk_07) {
    NPC_SetState(npc, 7);
    npc->unk_08 = 1;
  } else {
    npc->timer++;
  }
#else
  INCFUNC("asm/func/FUN_08043a24.inc");
#endif
}

// プレイヤーが unk_220 の外へ離れたら, unk_216 なら向き unk_215 で state 3 へ, そうでなければ覚えておいた state へ戻る
// 残差: 原典は距離の判定を FUN_0804157c と同じ形の inline で 0/1 に起こしてから比べる (FUN_08043cf4 と同じ形)
NON_MATCH void FUN_08043bcc(NPCManager* p, NPC* npc) {
#ifdef NONMATCHING_C
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 9;
  }

  if (p->player == NULL || p->playerPos == NULL) {
    return;
  }
  if (abs(p->playerPos->x - npc->mover.pos.x) < npc->unk_220 && abs(p->playerPos->y - npc->mover.pos.y) <= 0xFF && abs(p->playerPos->z - npc->mover.pos.z) < npc->unk_220) {
    npc->timer++;
    return;
  }
  if (npc->unk_216) {
    npc->unk_1b = npc->unk_215;
    NPC_SetState(npc, 3);
  } else {
    NPC_SetState(npc, npc->unk_227);
  }
  npc->unk_08 = 1;
#else
  INCFUNC("asm/func/FUN_08043bcc.inc");
#endif
}

// 待ちが解除されたら unk_05 を 10 にして, unk_07 が立っていたら state 12 へ進む
void FUN_08043c94(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 10;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 12);
    npc->unk_08 = 1;
  }

  npc->timer++;
}

// 待ちが解除されたら unk_05 を 11 にして, unk_07 が立っていたら state 14 へ進む
void FUN_08043cc4(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 11;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 14);
    npc->unk_08 = 1;
  }

  npc->timer++;
}

// プレイヤーが近づいたら今の state を覚えて state 10 へ
// 残差: 原典は距離の判定を FUN_0804157c と同じ形の inline で 0/1 に起こし, さらにプレイヤーの有無と合わせてもう一度 0/1 に起こしてから比べる, inline 2段にしても早期の FALSE が外側へ畳まれる
NON_MATCH void FUN_08043cf4(NPCManager* p, NPC* npc) {
#ifdef NONMATCHING_C
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 12;
  }

  if (p->playerPos != NULL && abs(p->playerPos->x - npc->mover.pos.x) < npc->nearRange && abs(p->playerPos->y - npc->mover.pos.y) <= 0xFF && abs(p->playerPos->z - npc->mover.pos.z) < npc->nearRange) {
    npc->unk_227 = npc->state;
    NPC_SetState(npc, 10);
    npc->unk_08 = 1;
    return;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 14);
    npc->unk_08 = 1;
  }
  npc->timer++;
#else
  INCFUNC("asm/func/FUN_08043cf4.inc");
#endif
}

// startHour:startMinute から endHour:endMinute の間に入ったら state 15 へ, waitFrames の間は時刻を見ない
void FUN_08043da8(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }

  if (npc->waitFrames == 0) {
    if (!p->raining && ((p->hour == npc->startHour && p->minute >= npc->startMinute) || (p->hour > npc->startHour && p->hour < npc->endHour) || (p->hour == npc->endHour && p->minute < npc->endMinute))) {
      NPC_SetState(npc, 15);
      npc->unk_08 = 1;
      return;
    }
  } else {
    npc->waitFrames--;
  }
  npc->timer++;
}

// プレイヤーが近づいたら今の state を覚えて state 10 へ
// 残差: 原典は距離の判定を FUN_0804157c と同じ形の inline で 0/1 に起こし, さらにプレイヤーの有無と合わせてもう一度 0/1 に起こしてから比べる, inline 2段にしても早期の FALSE が外側へ畳まれる
NON_MATCH void FUN_08043e54(NPCManager* p, NPC* npc) {
#ifdef NONMATCHING_C
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 13;
  }

  if (p->playerPos != NULL && abs(p->playerPos->x - npc->mover.pos.x) < npc->nearRange && abs(p->playerPos->y - npc->mover.pos.y) <= 0xFF && abs(p->playerPos->z - npc->mover.pos.z) < npc->nearRange) {
    npc->unk_227 = npc->state;
    NPC_SetState(npc, 10);
    npc->unk_08 = 1;
    return;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, FUN_08043510(npc));
    npc->unk_08 = 1;
  }
  npc->timer++;
#else
  INCFUNC("asm/func/FUN_08043e54.inc");
#endif
}

s32 NPCManager_Update(NPCManager* p) {
  NPC* npc;
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

  npc = p->head;
  while (npc != NULL) {
    NPC* next = npc->next;

    FUN_080411a0(p, npc);
    npc = next;
  }
  FUN_08041918(p);
  if (p->player != NULL) {
    FUN_080417dc(&p->player->mover);
  }
  p->frameCount++;
  return 0;
}

s32 NPCManager_Destroy(NPCManager* p) {
  NPC* npc = p->head;

  while (npc != NULL) {
    NPC* next = npc->next;

    if (npc->onDestroy != NULL) {
      npc->onDestroy(p, npc);
    }
    FUN_0804114c(npc);
    npc = next;
  }

  gNPCManager = NULL;
  return 0;
}

s32 NPCManager_Init(NPCManager* p) {
  Player* pl;

  gNPCManager = p;
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

// 0x286F, HashName("ＮＰＣマネージャ")
NPCManager* NPCManager_Create(void) {
  if (gNPCManager == NULL) {
    NPCManager* p = CreateEntity(ENTITY_UNK_9, sizeof(NPCManager));

    if (p != NULL) {
      SetEntityRoutine(p, NPCManager_Update, NPCManager_Destroy);
      if (NPCManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gNPCManager;
}

void FUN_080440ac(NPCManager* p, NPC* npc) {
  if (npc->unk_08 != 0) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 2;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 3 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_080440d0(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 3;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 0);
    npc->unk_08 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 4 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_08044104(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 4;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 0);
    npc->unk_08 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_08044138(NPCManager* p, NPC* npc) {
  static void (*const PTR_ARRAY_085ab36c[3])(NPCManager*, NPC*) = {
      FUN_080440ac,
      FUN_080440d0,
      FUN_08044104,
  };  // 0x085AB36C
  PTR_ARRAY_085ab36c[npc->state](p, npc);
}

void FUN_08044150(NPCManager* p, NPC* npc) { FUN_08044138(p, npc); }

s32 FUN_0804415c(NPCManager* p, NPC* npc) {
  FUN_08044150(p, npc);
  return 0;
}

// unk_05 に対応する更新関数を割り当てて動き出せる状態にする
s32 FUN_08044168(NPC* npc) {
  static void (*const PTR_ARRAY_085ab378[14])(NPCManager*, NPC*, s32) = {
      NULL,
      FUN_08042178,
      FUN_080421bc,
      FUN_08042200,
      FUN_0804234c,
      FUN_08042414,
      FUN_08042638,
  };  // 0x085AB378

  NPCUpdate* fn;

  if (npc->unk_05 == 0 || npc->unk_05 > 14) {  // 本来は >= 14 と書くべきものと思われる...
    return 0;
  }

  fn = PTR_ARRAY_085ab378[npc->unk_05];
  npc->unk_06 = npc->unk_05;
  npc->unk_2cc = fn;
  npc->unk_10 = 0;
  npc->unk_09 = 1;
  npc->unk_18 = 0;
  return 1;
}

// NPC の待ちを解除して unk_2cc を呼ぶ
s32 FUN_080441a4(NPCManager* p, NPC* npc) {
  u32 elapsed;

  npc->flags = 0;
  npc->unk_07 = 0;
  elapsed = npc->unk_10++;

  if (npc->unk_2cc != NULL) {
    npc->unk_2cc(p, npc, elapsed);
  }

  return 0;
}

// 届いたメッセージで向き (cmd 2) か歩き先 (cmd 3) を決めて state を始め直す
void FUN_080441d8(NPC* npc) {
  MsgQueue* mq = &npc->mq;
  s32 i;

  for (i = 0; i < mq->count[GetMsgBus()->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[GetMsgBus()->bufIdx][i];

    switch (msg->cmd) {
      case 3: {
        npc->work.walk.target.x = msg->args[0];
        npc->work.walk.target.y = msg->args[1];
        npc->work.walk.target.z = msg->args[2];
        npc->unk_1b = GetAngleTo(&npc->mover.pos, &npc->work.walk.target);
        NPC_StartState(npc, 1);
        break;
      }
      case 2: {
        npc->unk_1b = Angle_FromDir8((u8)msg->args[0]);
        NPC_StartState(npc, 2);
        break;
      }
    }
    MsgQueue_BeginWait(mq, msg);
  }
}

s32 FUN_080442d4(NPCManager* p, NPC* npc) {
  FUN_080441d8(npc);
  FUN_080411d8(p, npc);
  npc->unk_05 = 0;
  return 0;
}

s32 FUN_080442f4(NPCManager* p, NPC* npc) {
  FUN_080412fc(p, npc);
  return 0;
}

s32 FUN_08044300(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0x920F, HashName("ＮＰＣサンプル生成")?, '.n' / '.k' / '.p' / '.d' / '.o' / '.t' / '.m' / '.c' から NPC を1体作り, state 0 から始める (使われていない?)
void Cmd_CreateNPC(void) {
  s32 spriteType;
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  WorldPos pos;
  u32 angle;
  SpriteID32 spriteID;
  SpriteFlags flags;
  s32 plttID;
  NPC* npc;

  if (p == NULL) {
    return;
  }

  id = VM_GetNamedArgValue('n', 0);
  kind = VM_GetNamedArgValue('k', 0);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  angle = VM_GetNamedArgValue('d', 0);
  spriteType = VM_GetNamedArgValue('o', 2);
  spriteID = VM_GetNamedArgValue('t', SPR_DJANGO_SABATA);
  flags = VM_GetNamedArgValue('m', 0);
  plttID = VM_GetNamedArgValue('c', -1);

  npc = NPC_Alloc(id, kind);
  if (npc == NULL) {
    return;
  }
  if (FUN_08040f0c(npc, id, &pos, angle) < 0) {
    return;
  }
  if (FUN_08040f48(npc, spriteType, spriteID, flags, 0) < 0) {
    return;
  }
  if (plttID >= 0) {
    NPC_SetPltt(npc, plttID);
  }

  FUN_08040fc0(npc, npc->sprite.pos, 1, 0, 64);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->unk_1a = Angle_ToDir8(angle);
  npc->unk_19 = Angle_ToDir4(angle);
  NPC_SetFn(npc, FUN_08044168);
  NPC_SetCb(npc, 0, FUN_080442d4);
  NPC_SetCb(npc, 1, FUN_0804415c);
  NPC_SetCb(npc, 2, FUN_080441a4);
  NPC_SetCb(npc, 3, FUN_080442f4);
  NPC_SetOnDestroy(npc, FUN_08044300);
  NPC_StartState(npc, 0);
  NPC_SetUpdate(npc, FUN_080421bc, 2);
  npc->unk_2b8 = NPCManager_FindSpriteData(spriteID, 0);
  npc->unk_2bc = FUN_08040dc0(spriteID, 0);
  if (VM_SeekToNamedArg('b')) {
    npc->unk_1e8 = VM_GetValue();
    npc->unk_1e9 = VM_GetValue();
    npc->unk_1ea = VM_GetValue();
  } else {
    npc->unk_1e8 = 0;
    npc->unk_1e9 = 1;
    npc->unk_1ea = 0;
  }
  NPCManager_LinkNPC(p, npc);
}

void FUN_0804454c(NPCManager* p, NPC* npc) {
  if (npc->unk_08 != 0) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 2 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_08044570(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 2;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 0);
    npc->unk_08 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 3 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_080445a4(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 3;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 0);
    npc->unk_08 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_080445d8(NPCManager* p, NPC* npc) {
  if (npc->unk_08 != 0) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 4;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 5 にして, unk_07 が立っていたら state 5 に移してメッセージの待ちを終える
void FUN_080445fc(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 5;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 5);
    npc->unk_08 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_08044634(NPCManager* p, NPC* npc) {
  if (npc->unk_08 != 0) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 6;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 7 にして, unk_07 が立っていたら state 7 に移してメッセージの待ちを終える
void FUN_08044658(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 7;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 7);
    npc->unk_08 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 8 にしてメッセージの待ちを終える
void FUN_08044690(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 8;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 9 にしてメッセージの待ちを終える
void FUN_080446b4(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 9;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

// 待ちが解除されたら unk_05 を 10 にして, unk_07 が立っていたら state 0 に戻してメッセージの待ちを終える
void FUN_080446d8(NPCManager* p, NPC* npc) {
  if (npc->unk_08) {
    npc->unk_08 = 0;
    npc->unk_07 = 0;
    npc->unk_05 = 10;
  }

  if (npc->unk_07) {
    NPC_SetState(npc, 0);
    npc->unk_08 = 1;
    MsgQueue_EndWait(&npc->mq, 1);
  }
}

void FUN_0804470c(NPCManager* p, NPC* npc) {
  static void (*const PTR_ARRAY_085ab3b0[10])(NPCManager*, NPC*) = {
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
  PTR_ARRAY_085ab3b0[npc->state](p, npc);
}

void FUN_08044724(NPCManager* p, NPC* npc) { FUN_0804470c(p, npc); }

s32 FUN_08044730(NPCManager* p, NPC* npc) {
  FUN_08044724(p, npc);
  return 0;
}

void FUN_0804473c(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->unk_09 != 0) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 0, 1, 0, 4);
  }
  if ((u8)npc->fn(npc) != 1) {
    FUN_08041480(npc, 0, 1, 0, 1);
  }
}

// work.walk.target へ 1フレーム 5 ずつ歩かせ, 着いたら終える
// 下書き (149/151命令): 呼び出しの並びは一致, 着いたときの判定と速度の組み立ての順が違う
NON_MATCH void FUN_0804478c(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 1, 1, 0, 4);
  }
  if ((u8)npc->fn(npc) != 1) {
    WorldPos* pos = &npc->mover.pos;
    WorldPos* target = &npc->work.walk.target;
    s32 dx = target->x - pos->x;
    s32 dz = target->z - pos->z;

    if (dx * dx + dz * dz <= 100) {
      npc->mover.pos = npc->work.walk.target;
      npc->unk_07 = 1;
    } else {
      Vec3_SetPolar(&npc->mover.delta, npc->mover.angle, 5);
      npc->unk_1b = ArcTan2_8(target->x - pos->x, target->z - pos->z);
      npc->mover.angle = npc->unk_1b;
      npc->unk_1a = Angle_ToDir8(npc->unk_1b);
      npc->unk_19 = Angle_ToDir4(npc->unk_1b);
      FUN_08041480(npc, 1, 1, 0, 5);
    }
  }
#else
  INCFUNC("asm/func/FUN_0804478c.inc");
#endif
}

// mover の向きを unk_1b に合わせて向きのアニメを出し, 合ったら終える
void FUN_080448c8(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 2, 1, 0, 4);
  }
  if ((u8)npc->fn(npc) != 1) {
    u8 angle = npc->unk_1b;

    npc->mover.angle = angle;
    npc->unk_1a = Angle_ToDir8(angle);
    npc->unk_19 = Angle_ToDir4(angle);
    FUN_08041480(npc, 2, 2, 0, 0);
    if (npc->mover.angle == npc->unk_1b) {
      npc->unk_07 = 1;
    }
  }
}

void FUN_0804494c(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 4, 2, 0, 4);
    npc->work.unk_00 = 0;
  }
  if ((u8)npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    switch (npc->work.unk_00) {
      case 0: {
        FUN_08041480(npc, 5, 2, 0, 4);
        break;
      }
      case 1: {
        npc->unk_07 = 1;
        break;
      }
      default: {
        return;
      }
    }
    npc->work.unk_00++;
  }
}

void FUN_080449c0(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 5, 2, 0, 4);
    npc->work.unk_00 = 0;
  }
  if ((u8)npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    switch (npc->work.unk_00) {
      case 0: {
        FUN_08041480(npc, 6, 2, 0, 4);
        npc->work.unk_00++;
        break;
      }
      case 1: {
        FUN_08041480(npc, 7, 2, 0, 4);
        npc->work.unk_00++;
        break;
      }
      case 2: {
        npc->unk_07 = 1;
        npc->work.unk_00++;
        break;
      }
    }
  }
}

void FUN_08044a54(NPCManager* p, NPC* npc, s32 _) {
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 7, 2, 0, 1);
    npc->work.unk_00 = 0;
  }
  npc->fn(npc);
}

// スミスに槌を打たせる, 打ち始めに掛け声を鳴らし, 3 フレーム目に火花を散らして打撃音を鳴らす
// 下書き (356/344命令): 原典は npc を r10, work を r7 に置く (こちらは逆), pos.x への加算は *dst = *src; dst->x += 200; と &pos を先に取る形なら strh になり 351 命令
NON_MATCH void FUN_08044a90(NPCManager* p, NPC* npc, s32 elapsed) {
#ifdef NONMATCHING_C
  NPCSmithWork* work = &npc->work.smith;

  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 8, 2, 0, 4);
    npc->work.smith.step = 0;
    work->timer = 0;
    if (work->voiceWait == 0) {
      s32 r = (u8)Random();

      if (r <= 84) {
        PlaySound_082406e0(VO_SMITH_FORGE1);
      } else if (r <= 169) {
        PlaySound_082406e0(VO_SMITH_FORGE2);
      } else {
        PlaySound_082406e0(VO_SMITH_FORGE3);
      }
      work->voiceWait = (Random() & 1) + 1;
    } else {
      work->voiceWait--;
    }
  }
  if ((u8)npc->fn(npc) == 1) {
    return;
  }

  if (work->step == 0 && work->timer == 3) {
    Vec3 pos;

    pos = npc->mover.pos;
    pos.x += 200;
    ScatterEffect_SpawnAtAngle(4, SCATTER_KIND_38, &pos, 0, Random() & 0x3F, 12, 10, 5, 8, 8, 5);
    ScatterEffect_SpawnAtAngle(4, SCATTER_KIND_38, &pos, 64, Random() & 0x3F, 12, 10, 5, 8, 8, 5);
    ScatterEffect_SpawnAtAngle(4, SCATTER_KIND_38, &pos, 128, Random() & 0x3F, 12, 10, 5, 8, 8, 5);
    ScatterEffect_SpawnAtAngle(4, SCATTER_KIND_38, &pos, 192, Random() & 0x3F, 12, 10, 5, 8, 8, 5);
    ScatterEffect_SpawnAtAngle(2, SCATTER_KIND_38, &pos, 0, Random() & 0x3F, 10, 4, 4, 4, 14, 4);
    ScatterEffect_SpawnAtAngle(2, SCATTER_KIND_38, &pos, 64, Random() & 0x3F, 10, 4, 4, 4, 14, 4);
    ScatterEffect_SpawnAtAngle(2, SCATTER_KIND_38, &pos, 128, Random() & 0x3F, 10, 4, 4, 4, 14, 4);
    ScatterEffect_SpawnAtAngle(2, SCATTER_KIND_38, &pos, 192, Random() & 0x3F, 10, 4, 4, 4, 14, 4);
    PlayForgeStrikeSE(FUN_0801dfe4(), FUN_0801e00c());
    FUN_0807c7c8(gPlayerPtr[0], 2);
  }
  work->timer++;
  if (SpriteHolder_IsAnimEnded(&npc->sprite)) {
    switch (work->step) {
      case 0: {
        FUN_08041480(npc, 6, 2, 0, 4);
        break;
      }
      case 1: {
        npc->unk_07 = 1;
        break;
      }
      default: {
        return;
      }
    }
    work->step++;
    work->timer = 0;
  }
#else
  INCFUNC("asm/func/FUN_08044a90.inc");
#endif
}

void FUN_08044d9c(NPCManager* p, NPC* npc, s32 _) {
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 7, 2, 0, 4);
    npc->work.unk_00 = 0;
  }

  npc->fn(npc);
}

void FUN_08044dd8(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 7, 2, 0, 4);
    npc->work.unk_00 = 0;
  }
  if ((u8)npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    switch (npc->work.unk_00) {
      case 0: {
        FUN_08041480(npc, 6, 2, 0, 4);
        npc->work.unk_00++;
        break;
      }
      case 1: {
        FUN_08041480(npc, 5, 2, 0, 4);
        npc->work.unk_00++;
        break;
      }
      case 2: {
        npc->unk_07 = 1;
        npc->work.unk_00++;
        break;
      }
    }
  }
}

void FUN_08044e6c(NPCManager* p, NPC* npc, s32 elapsed) {
  if (npc->unk_09) {
    npc->unk_09 = 0;
    npc->unk_07 = 0;
    FUN_08041480(npc, 5, 2, 0, 4);
    npc->work.unk_00 = 0;
  }
  if ((u8)npc->fn(npc) != 1 && SpriteHolder_IsAnimEnded(&npc->sprite)) {
    switch (npc->work.unk_00) {
      case 0: {
        FUN_08041480(npc, 0, 1, 0, 4);
        break;
      }
      case 1: {
        npc->unk_07 = 1;
        break;
      }
      default: {
        return;
      }
    }
    npc->work.unk_00++;
  }
}

// unk_05 に対応する更新関数を割り当てて動き出せる状態にする
s32 FUN_08044ee0(NPC* npc) {
  static void (*const PTR_ARRAY_085ab3d8[11])(NPCManager*, NPC*, s32) = {
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

  NPCUpdate* fn;

  if (npc->unk_05 == 0 || npc->unk_05 > 11) {  // 本来は >= 11 と書くべきものと思われる...
    return 0;
  }

  fn = PTR_ARRAY_085ab3d8[npc->unk_05];
  npc->unk_06 = npc->unk_05;
  npc->unk_2cc = fn;
  npc->unk_10 = 0;
  npc->unk_09 = 1;
  npc->unk_18 = 0;
  return 1;
}

// NPC の待ちを解除して unk_2cc を呼ぶ
s32 FUN_08044f1c(NPCManager* p, NPC* npc) {
  s32 elapsed;

  npc->flags = 0;
  npc->unk_07 = 0;
  elapsed = npc->unk_10++;

  if (npc->unk_2cc != NULL) {
    npc->unk_2cc(p, npc, elapsed);
  }

  return 0;
}

// 届いたメッセージで state を決める: cmd 1 は向き, cmd 2 は歩き先, cmd 3..9 はその番号の state
void FUN_08044f50(NPC* npc) {
  MsgQueue* mq = &npc->mq;
  s32 i;

  for (i = 0; i < mq->count[GetMsgBus()->bufIdx]; i++) {
    MsgPacket* msg = mq->msgs[GetMsgBus()->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    switch (msg->cmd) {
      case 2: {
        npc->work.walk.target.x = msg->args[0];
        npc->work.walk.target.y = msg->args[1];
        npc->work.walk.target.z = msg->args[2];
        npc->unk_1b = GetAngleTo(&npc->mover.pos, &npc->work.walk.target);
        NPC_StartState(npc, 1);
        break;
      }
      case 1: {
        npc->unk_1b = Angle_FromDir8((u8)msg->args[0]);
        NPC_StartState(npc, 2);
        break;
      }
      case 3: {
        NPC_StartState(npc, 3);
        break;
      }
      case 4: {
        NPC_StartState(npc, 4);
        break;
      }
      case 5: {
        NPC_StartState(npc, 5);
        break;
      }
      case 6: {
        NPC_StartState(npc, 6);
        break;
      }
      case 7: {
        NPC_StartState(npc, 7);
        break;
      }
      case 8: {
        NPC_StartState(npc, 8);
        break;
      }
      case 9: {
        NPC_StartState(npc, 9);
        break;
      }
    }
  }
}

s32 FUN_08045088(NPCManager* p, NPC* npc) {
  FUN_08044f50(npc);
  FUN_080411d8(p, npc);
  npc->unk_05 = 0;
  return 0;
}

s32 FUN_080450a8(NPCManager* p, NPC* npc) {
  FUN_080412fc(p, npc);
  return 0;
}

s32 FUN_080450b4(NPCManager* p, NPC* npc) { return MsgQueue_Unregister(&npc->mq); }

// 0x0E7C, HashName("ＮＰＣスミス生成"), '.n' / '.k' / '.p' / '.d' からスミス (マルチェロ) の NPC を1体作り, メッセージで動く state 0 から始める
void Cmd_CreateSmithNPC(void) {
  NPCManager* p = gNPCManager;
  u32 id;
  u32 kind;
  WorldPos pos;
  u32 angle;
  SpriteID32 spriteID;
  SpriteFlags flags;
  NPC* npc;

  if (p == NULL) {
    return;
  }

  id = VM_GetNamedArgValue('n', 0);
  kind = VM_GetNamedArgValue('k', 0);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  angle = VM_GetNamedArgValue('d', 0);
  spriteID = SPR_SMITH_MARCELLO;
  flags = 0;

  npc = NPC_Alloc(id, kind);
  if (npc == NULL) {
    return;
  }
  if (FUN_08040f0c(npc, id, &pos, angle) < 0) {
    return;
  }
  if (FUN_08040f48(npc, 2, spriteID, 0, flags) < 0) {
    return;
  }

  FUN_08040fc0(npc, npc->sprite.pos, 2, 7, 32);
  MsgQueue_Register(&npc->mq, id, 5);
  npc->mover.angle = angle;
  npc->unk_1a = Angle_ToDir8(angle);
  npc->unk_19 = Angle_ToDir4(angle);
  NPC_SetFn(npc, FUN_08044ee0);
  NPC_SetCb(npc, 0, FUN_08045088);
  NPC_SetCb(npc, 1, FUN_08044730);
  NPC_SetCb(npc, 2, FUN_08044f1c);
  NPC_SetCb(npc, 3, FUN_080450a8);
  NPC_SetOnDestroy(npc, FUN_080450b4);
  NPC_StartState(npc, 0);
  NPC_SetUpdate(npc, FUN_0804473c, 1);
  npc->unk_2b8 = NPCManager_FindSpriteData(spriteID, 0);
  npc->unk_2bc = FUN_08040dc0(spriteID, 0);
  if (VM_SeekToNamedArg('b')) {
    npc->unk_1e8 = VM_GetValue();
    npc->unk_1e9 = VM_GetValue();
    npc->unk_1ea = VM_GetValue();
  } else {
    npc->unk_1e8 = 0;
    npc->unk_1e9 = 1;
    npc->unk_1ea = 0;
  }
  NPCManager_LinkNPC(p, npc);
}
