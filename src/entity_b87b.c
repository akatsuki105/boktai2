#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "random.h"
#include "sprite.h"
#include "text.h"
#include "video.h"
#include "vm.h"

typedef struct EntityB87B {
  Entity e;                                    // 0x000, ENTITY_UNK_8
  MainSpriteGfx gfx;                           // 0x018
  MainSprite sprites[5];                       // 0x038
  u8* msgPc;                                   // 0x218, '.r' の位置, MessageWindow_Start に渡す
  u16 kind;                                    // 0x21C, '.i=0'
  u16 animTimer;                               // 0x21E, EntityB87B_AdvanceAnims が毎フレーム +1
  u16 unk_220;                                 // 0x220, 0x11 と比べて START/A での送りを許すかを決める
  u8 unk_222[2];                               // 0x222, まだ未解析
  u16 step;                                    // 0x224, unk_226 と一致すると次へ進む数え上げ
  u16 unk_226;                                 // 0x226, step の上限
  u16 unk_228;                                 // 0x228, 終わるとき 0 を書く
  s16 finished;                                // 0x22A, 終わると 1 を書く
  u16 progress;                                // 0x22C, unk_22e と比べて進み具合を見る
  u16 unk_22e;                                 // 0x22E, progress の上限
  s32 scriptID;                                // 0x230, '.p=0'
  void (*updateCallback)(struct EntityB87B*);  // 0x234
} EntityB87B;
static_assert(sizeof(EntityB87B) == 568);

void EntityB87B_UpdateShake(EntityB87B* p);
void EntityB87B_LoadBG(EntityB87B* p);
void EntityB87B_InitSprites(EntityB87B* p);
void EntityB87B_SetupSprites(EntityB87B* p);
void EntityB87B_InitMessage(EntityB87B* p);
void EntityB87B_ClearBG0(void);

void EntityB87B_AdvanceAnims(EntityB87B* p) {
  MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx);
  MainSprite_AdvanceAnim(&p->sprites[2], &p->gfx);
  MainSprite_AdvanceAnim(&p->sprites[4], &p->gfx);
  p->animTimer++;
}

// 245/236命令の下書き, 原典は &animTimer を r6 に置き, 段ごとの pos.y と sprites[3] を隠す後半を共通の末尾にまとめる
NON_MATCH void EntityB87B_UpdateShake(EntityB87B* p) {
#ifdef NONMATCHING_C
  if (p->animTimer < 30) {
    p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[1].pos.x = 60;
    p->sprites[1].pos.y = -30;
    p->sprites[3].flags |= SPRFLAG_HIDDEN;
  } else if (p->animTimer < 45) {
    p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[1].pos.x = 60;
    p->sprites[1].pos.y = p->animTimer * 2 - 90;
    p->sprites[3].flags |= SPRFLAG_HIDDEN;
  } else if (p->animTimer < 50) {
    p->sprites[1].pos.x = Mod(RandomNext(), 5) + 58;
    p->sprites[1].pos.y = (45 - p->animTimer) * 2 + Mod(RandomNext(), 5) - 2;
  } else if (p->animTimer < 55) {
    p->sprites[1].pos.x = Mod(RandomNext(), 5) + 58;
    p->sprites[1].pos.y = (p->animTimer - 55) * 2 + Mod(RandomNext(), 5) - 2;
  } else if (p->animTimer < 60) {
    p->sprites[1].pos.x = Mod(RandomNext(), 5) + 58;
    p->sprites[1].pos.y = Mod(RandomNext(), 5) - 2;
    p->sprites[3].flags |= SPRFLAG_HIDDEN;
  } else if (p->animTimer < 80) {
    p->sprites[1].pos.x = Mod(RandomNext(), 3) + 59;
    p->sprites[1].pos.y = Mod(RandomNext(), 3) - 1;
    p->sprites[3].flags |= SPRFLAG_HIDDEN;
  } else if (p->animTimer < 90) {
    p->sprites[1].pos.x = 60;
    p->sprites[1].pos.y = 0;
  } else if (Div(p->animTimer, 45) & 1) {
    p->sprites[1].flags |= SPRFLAG_HIDDEN;
    p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[3].flags |= SPRFLAG_HIDDEN;
  }
  p->animTimer++;
#else
  INCFUNC("asm/func/EntityB87B_UpdateShake.inc");
#endif
}

s32 EntityB87B_Update(EntityB87B* p) {
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  if (p->unk_22e != 0) {
    if (++p->unk_22e > 16) {
      if (p->scriptID != 0) {
        u32 argv[1];
        ScriptArgs sa;

        sa.argc = 1;
        sa.argv = argv;
        argv[0] = p->progress;
        VM_ExecByID(p->scriptID, &sa);
      }
      KillEntity(&p->e);
    }
  } else {
    if (p->step == p->unk_226 && p->unk_228 == (u16)p->finished - 16) {
      StartBgObjPlttFade(1, 4, 4, 4, 4, 0xFFFF, 0);
      p->progress = 0;
      p->unk_22e = 1;
    } else if (p->unk_220 > 16 && (gInput[0].pressed & (START_BUTTON | A_BUTTON))) {
      StartBgObjPlttFade(1, 4, 4, 4, 4, 0xFFFF, 0);
      p->progress = 1;
      p->unk_22e = 1;
    } else if (p->unk_228 >= (u16)p->finished) {
      p->step++;
      if (p->kind == 1) {
        MainSprite_SetAnim(&p->sprites[2], &p->gfx, 4, 1, 0);
        MainSprite_SetPose(&p->sprites[3], &p->gfx, 1, 1);
        p->sprites[4].flags |= SPRFLAG_HIDDEN;
      } else if (p->kind == 3) {
        p->updateCallback = EntityB87B_UpdateShake;
        p->animTimer = 0;
      }
      p->unk_228 = 0;
      MessageWindow_SetInstant(1);
      MessageWindow_ShowLine(p->step);
    }
    p->unk_220++;
    p->unk_228++;
  }
}

s32 EntityB87B_Destroy(EntityB87B* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
  return 0;
}

// BG0 のタイルマップを全面 0xF001 で塗る
void EntityB87B_ClearBG0(void) {
  BgMapEntry* dst = gBgStates[0].tilemap;
  s32 i;
  s32 j;

  for (i = 0; i < 32; i++) {
    for (j = 0; j < 32; j++) {
      *dst++ = 0xF001;
    }
  }
}

// 66/66命令, 残差はパレット転送のループの i を r1/r2 のどちらに置くかと i + 1 の位置だけ, dst のローカルの位置は試済
NON_MATCH void EntityB87B_LoadBG(EntityB87B* p) {
#ifdef NONMATCHING_C
  TilemapFile* f;
  BgPlttFile* pf;
  u32 mapID, plttID;
  s32 layer, idx, i, j;
  rgb555* src;
  rgb555* dst;

  if (p->kind == 0) {
    mapID = TILEMAP_CFE1;
    plttID = BGP_ACBD;
    layer = 0;
  } else {
    mapID = TILEMAP_A413;
    plttID = BGP_EFDA;
    layer = 12;
  }
  f = GetFile(DIR_TILE_MAP, mapID);
  idx = 0;
  Video_SetupBGLayout(0, 0, f, 0, 0, 1, &idx);
  Video_SetBGLayer(0, f, layer);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  pf = GetBgPlttFile(plttID);
  src = &pf->body[13 * 16];
  for (i = 13; i < 16; i++) {
    dst = &gBgPlttBuffer[i * 16];
    for (j = 0; j < 16; j++) {
      *dst++ = *src++;
    }
  }
#else
  INCFUNC("asm/func/EntityB87B_LoadBG.inc");
#endif
}

void EntityB87B_InitSprites(EntityB87B* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_SOLAR_SENSOR_HELP);
  Vec3 pos;

  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  VEC3_SET(pos, 0, 0, 0);
  MainSprite_Add(&p->sprites[0], &p->gfx, 15, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
  MainSprite_Add(&p->sprites[1], &p->gfx, 11, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
  MainSprite_Add(&p->sprites[2], &p->gfx, 2, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
  MainSprite_Add(&p->sprites[4], &p->gfx, 5, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
  MainSprite_Add(&p->sprites[3], &p->gfx, 0, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
}

// kind ごとに見出しのポーズと動かすスプライトを決める
void EntityB87B_SetupSprites(EntityB87B* p) {
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  switch (p->kind) {
    case 0: {
      p->sprites[0].flags |= SPRFLAG_HIDDEN;
      break;
    }
    case 1: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, 15, 1);
      break;
    }
    case 2: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, 16, 1);
      break;
    }
    case 3:
    case 4: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, 17, 1);
      break;
    }
    case 5: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, 18, 1);
      break;
    }
    case 6: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, 19, 1);
      break;
    }
    case 7:
    case 8: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, 20, 1);
      break;
    }
    case 9:
    case 10:
    case 11: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, 21, 1);
      break;
    }
    case 12: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, 22, 1);
      break;
    }
    case 13: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, 23, 1);
      break;
    }
    default: {
      p->sprites[0].flags |= SPRFLAG_HIDDEN;
      break;
    }
  }

  switch (p->kind) {
    case 0: {
      p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[1], &p->gfx, 0, 1, 0);
      p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[2], &p->gfx, 2, 1, 0);
      p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[4], &p->gfx, 3, 1, 0);
      p->sprites[3].flags |= SPRFLAG_HIDDEN;
      p->updateCallback = EntityB87B_AdvanceAnims;
      break;
    }
    case 1: {
      p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[1], &p->gfx, 0, 1, 0);
      p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[2], &p->gfx, 2, 1, 0);
      p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[4], &p->gfx, 3, 1, 0);
      p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetPose(&p->sprites[3], &p->gfx, 0, 1);
      p->updateCallback = EntityB87B_AdvanceAnims;
      break;
    }
    case 4:
    case 12: {
      p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[1], &p->gfx, 1, 1, 0);
      p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[2], &p->gfx, 2, 1, 0);
      p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[4], &p->gfx, 3, 1, 0);
      p->sprites[3].flags |= SPRFLAG_HIDDEN;
      p->updateCallback = EntityB87B_AdvanceAnims;
      break;
    }
    case 2:
    case 9: {
      p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[1], &p->gfx, 0, 1, 0);
      p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[2], &p->gfx, 2, 1, 0);
      p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[4], &p->gfx, 3, 1, 0);
      p->sprites[3].flags |= SPRFLAG_HIDDEN;
      p->updateCallback = EntityB87B_AdvanceAnims;
      break;
    }
    case 3: {
      p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[1], &p->gfx, 0, 1, 0);
      p->sprites[1].pos.x = 60;
      p->sprites[1].pos.y = -30;
      p->sprites[2].flags |= SPRFLAG_HIDDEN;
      p->sprites[4].flags |= SPRFLAG_HIDDEN;
      MainSprite_SetPose(&p->sprites[3], &p->gfx, 1, 1);
      p->sprites[3].pos.x = -65;
      p->sprites[3].pos.y = 40;
      p->sprites[3].flags |= SPRFLAG_HIDDEN;
      p->updateCallback = NULL;
      break;
    }
    default: {
      p->sprites[1].flags |= SPRFLAG_HIDDEN;
      p->sprites[2].flags |= SPRFLAG_HIDDEN;
      p->sprites[4].flags |= SPRFLAG_HIDDEN;
      p->sprites[3].flags |= SPRFLAG_HIDDEN;
      EntityB87B_ClearBG0();
      p->updateCallback = NULL;
      break;
    }
  }
  p->unk_220 = 0;
}

void EntityB87B_InitMessage(EntityB87B* p) {
  if (p->kind == 0) {
    p->step = 0;
    p->unk_226 = 0;
  } else {
    if (!VM_SeekToNamedArg('r')) {
      return;
    }
    p->msgPc = VM_GetPC_Proxy();
    if (!VM_SeekToNamedArg('m')) {
      return;
    }
    p->step = VM_GetValue();
    p->unk_226 = p->step + VM_GetValue() - 1;
    MessageWindow_SetBgPltt(BGP_EFDA);
    MessageWindow_Start(p->msgPc);
    MessageWindow_SetInstant(1);
    MessageWindow_ShowLine((u16)p->step);
  }
  if (VM_SeekToNamedArg('c')) {
    p->finished = VM_GetValue();
  } else {
    p->finished = 60;
  }
  p->unk_228 = 0;
}

s32 EntityB87B_Init(EntityB87B* p) {
  if (VM_SeekToNamedArg('i')) {
    p->kind = VM_GetValue();
  } else {
    p->kind = 0;
  }
  if (VM_SeekToNamedArg('p')) {
    p->scriptID = VM_GetValue();
  } else {
    p->scriptID = 0;
  }
  EntityB87B_LoadBG(p);
  EntityB87B_InitSprites(p);
  EntityB87B_SetupSprites(p);
  EntityB87B_InitMessage(p);
  StartBgObjPlttFade(0, 4, 4, 4, 4, 0xFFFF, 0);
}

// 0xB87B
EntityB87B* EntityB87B_Create(void) {
  EntityB87B* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityB87B));

  if (p != NULL) {
    SetEntityRoutine(p, EntityB87B_Update, EntityB87B_Destroy);
    if (EntityB87B_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
