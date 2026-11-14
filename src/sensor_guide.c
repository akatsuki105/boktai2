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

// SPRITE_UI_SENSOR_HELP の pose
#define SENSOR_OK 0                      // "⚪︎"
#define SENSOR_NG 1                      // "×"
#define ICON_SUN(step) (2 + (step))      // 太陽, step:0..2
#define ICON_SUNBEAM(step) (5 + (step))  // 太陽からの光, step:0..3
#define GAME_CART(step) (11 + (step))    // このゲームのカートリッジ, step:0..3
#define WHAT_SENSOR 15                   // "太陽センサーとは"
#define SENSOR_EFFECT 16                 // "太陽センサーの効果"
#define SENSOR_WARNING 17                // "太陽センサー使用上の注意"
#define POSE_18 18                       // "太陽センサーの向き・傾き"
#define SENSOR_PLACE 19                  // "太陽センサーと場所"
#define SENSOR_TIME 20                   // "太陽センサーと時間"
#define SENSOR_WEATHER 21                // "太陽センサーと天気"
#define POSE_22 22                       // "炎天下"
#define POSE_23 23                       // "太陽センサーと???"

// SPRITE_UI_SENSOR_HELP の anim
#define ANIM_GAME_CART 0  // カートリッジの通常アニメーション
#define ANIM_HEAT 1       // カートリッジからの熱を表現するアニメーション
#define ANIM_SUN 2        // 太陽のアニメーション
#define ANIM_SUNBEAM 3    // 太陽からの光のアニメーション
#define ANIM_LIGHTBULB 4  // 電球のアニメーション

typedef struct SensorGuide {
  Entity e;                                     // 0x000, ENTITY_UNK_8
  MainSpriteGfx gfx;                            // 0x018, SPRITE_UI_SENSOR_HELP
  MainSprite sprites[5];                        // 0x038
  u8* msgPc;                                    // 0x218, '.r'
  u16 page;                                     // 0x21C, '.i=0', 解説のページ (タイトルデモの場面番号), 0 は導入文
  u16 animTimer;                                // 0x21E, SensorGuide_AnimateSprites が毎フレーム +1
  u16 inputDelay;                               // 0x220, ページを出してからのフレーム数, 16 を超えると START/A で抜けられる
  u8 unk_222[2];                                // 0x222, まだ未解析
  u16 line;                                     // 0x224, '.m[0]', 表示中のメッセージ行
  u16 lastLine;                                 // 0x226, '.m[0]' + '.m[1]' - 1
  u16 lineTimer;                                // 0x228, 行を出してからのフレーム数
  s16 lineFrames;                               // 0x22A, '.c=60', 1行の表示フレーム数
  u16 skipped;                                  // 0x22C, 0: 最後まで見た, 1: START/A で抜けた, scriptID の p0
  u16 fadeTimer;                                // 0x22E, フェードアウトを始めてからのフレーム数, 16 を超えると終わる
  s32 scriptID;                                 // 0x230, '.p=0'
  void (*updateCallback)(struct SensorGuide*);  // 0x234
} SensorGuide;
static_assert(sizeof(SensorGuide) == 568);

void SensorGuide_AnimateSprites(SensorGuide* p) {
  MainSprite_AdvanceAnim(&p->sprites[1], &p->gfx);
  MainSprite_AdvanceAnim(&p->sprites[2], &p->gfx);
  MainSprite_AdvanceAnim(&p->sprites[4], &p->gfx);
  p->animTimer++;
}

// 245/236命令の下書き, 原典は &animTimer を r6 に置き, 段ごとの pos.y と sprites[3] を隠す後半を共通の末尾にまとめる
NON_MATCH void SensorGuide_UpdateCartDrop(SensorGuide* p) {
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
  INCFUNC("asm/func/SensorGuide_UpdateCartDrop.inc");
#endif
}

s32 SensorGuide_Update(SensorGuide* p) {
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  if (p->fadeTimer != 0) {
    if (++p->fadeTimer > 16) {
      if (p->scriptID != 0) {
        u32 argv[1];
        ScriptArgs sa;

        sa.argc = 1;
        sa.argv = argv;
        argv[0] = p->skipped;
        VM_ExecByID(p->scriptID, &sa);
      }
      KillEntity(&p->e);
    }
  } else {
    if (p->line == p->lastLine && p->lineTimer == (u16)p->lineFrames - 16) {
      StartBgObjPlttFade(1, 4, 4, 4, 4, 0xFFFF, 0);
      p->skipped = 0;
      p->fadeTimer = 1;
    } else if (p->inputDelay > 16 && (gInput[0].pressed & (START_BUTTON | A_BUTTON))) {
      StartBgObjPlttFade(1, 4, 4, 4, 4, 0xFFFF, 0);
      p->skipped = 1;
      p->fadeTimer = 1;
    } else if (p->lineTimer >= (u16)p->lineFrames) {
      p->line++;
      if (p->page == 1) {
        MainSprite_SetAnim(&p->sprites[2], &p->gfx, ANIM_LIGHTBULB, 1, 0);
        MainSprite_SetPose(&p->sprites[3], &p->gfx, SENSOR_NG, 1);
        p->sprites[4].flags |= SPRFLAG_HIDDEN;
      } else if (p->page == 3) {
        p->updateCallback = SensorGuide_UpdateCartDrop;
        p->animTimer = 0;
      }
      p->lineTimer = 0;
      MessageWindow_SetInstant(1);
      MessageWindow_ShowLine(p->line);
    }
    p->inputDelay++;
    p->lineTimer++;
  }
}

s32 SensorGuide_Destroy(SensorGuide* p) {
  s32 i;

  for (i = 0; i < 5; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
  return 0;
}

// BG0 のタイルマップを全面 0xF001 で塗る
void SensorGuide_ClearBG0(void) {
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
NON_MATCH void SensorGuide_LoadBG(SensorGuide* p) {
#ifdef NONMATCHING_C
  TilemapFile* f;
  BgPlttFile* pf;
  u32 mapID, plttID;
  s32 layer, idx, i, j;
  rgb555* src;
  rgb555* dst;

  if (p->page == 0) {
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
  INCFUNC("asm/func/SensorGuide_LoadBG.inc");
#endif
}

void SensorGuide_InitSprites(SensorGuide* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_SENSOR_HELP);
  Vec3 pos;

  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  VEC3_SET(pos, 0, 0, 0);
  MainSprite_Add(&p->sprites[0], &p->gfx, WHAT_SENSOR, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
  MainSprite_Add(&p->sprites[1], &p->gfx, GAME_CART(0), SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
  MainSprite_Add(&p->sprites[2], &p->gfx, ICON_SUN(0), SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
  MainSprite_Add(&p->sprites[4], &p->gfx, ICON_SUNBEAM(0), SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
  MainSprite_Add(&p->sprites[3], &p->gfx, SENSOR_OK, SPRFLAG_OAM_DIRECT | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
}

// ページごとに見出しのポーズと動かすスプライトを決める
void SensorGuide_SetupPage(SensorGuide* p) {
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  switch (p->page) {
    case 0: {
      p->sprites[0].flags |= SPRFLAG_HIDDEN;
      break;
    }
    case 1: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, WHAT_SENSOR, 1);
      break;
    }
    case 2: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, SENSOR_EFFECT, 1);
      break;
    }
    case 3:
    case 4: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, SENSOR_WARNING, 1);
      break;
    }
    case 5: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, POSE_18, 1);
      break;
    }
    case 6: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, SENSOR_PLACE, 1);
      break;
    }
    case 7:
    case 8: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, SENSOR_TIME, 1);
      break;
    }
    case 9:
    case 10:
    case 11: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, SENSOR_WEATHER, 1);
      break;
    }
    case 12: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, POSE_22, 1);
      break;
    }
    case 13: {
      MainSprite_SetPose(&p->sprites[0], &p->gfx, POSE_23, 1);
      break;
    }
    default: {
      p->sprites[0].flags |= SPRFLAG_HIDDEN;
      break;
    }
  }

  switch (p->page) {
    case 0: {
      p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[1], &p->gfx, ANIM_GAME_CART, 1, 0);
      p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[2], &p->gfx, ANIM_SUN, 1, 0);
      p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[4], &p->gfx, ANIM_SUNBEAM, 1, 0);
      p->sprites[3].flags |= SPRFLAG_HIDDEN;
      p->updateCallback = SensorGuide_AnimateSprites;
      break;
    }
    case 1: {
      p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[1], &p->gfx, ANIM_GAME_CART, 1, 0);
      p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[2], &p->gfx, ANIM_SUN, 1, 0);
      p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[4], &p->gfx, ANIM_SUNBEAM, 1, 0);
      p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetPose(&p->sprites[3], &p->gfx, SENSOR_OK, 1);
      p->updateCallback = SensorGuide_AnimateSprites;
      break;
    }
    case 4:
    case 12: {
      p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[1], &p->gfx, ANIM_HEAT, 1, 0);
      p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[2], &p->gfx, ANIM_SUN, 1, 0);
      p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[4], &p->gfx, ANIM_SUNBEAM, 1, 0);
      p->sprites[3].flags |= SPRFLAG_HIDDEN;
      p->updateCallback = SensorGuide_AnimateSprites;
      break;
    }
    case 2:
    case 9: {
      p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[1], &p->gfx, ANIM_GAME_CART, 1, 0);
      p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[2], &p->gfx, ANIM_SUN, 1, 0);
      p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[4], &p->gfx, ANIM_SUNBEAM, 1, 0);
      p->sprites[3].flags |= SPRFLAG_HIDDEN;
      p->updateCallback = SensorGuide_AnimateSprites;
      break;
    }
    case 3: {
      p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetAnim(&p->sprites[1], &p->gfx, ANIM_GAME_CART, 1, 0);
      p->sprites[1].pos.x = 60;
      p->sprites[1].pos.y = -30;
      p->sprites[2].flags |= SPRFLAG_HIDDEN;
      p->sprites[4].flags |= SPRFLAG_HIDDEN;
      MainSprite_SetPose(&p->sprites[3], &p->gfx, SENSOR_NG, 1);
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
      SensorGuide_ClearBG0();
      p->updateCallback = NULL;
      break;
    }
  }
  p->inputDelay = 0;
}

void SensorGuide_InitMessage(SensorGuide* p) {
  if (p->page == 0) {
    p->line = 0;
    p->lastLine = 0;
  } else {
    if (!VM_SeekToNamedArg('r')) {
      return;
    }
    p->msgPc = VM_GetPC_Proxy();
    if (!VM_SeekToNamedArg('m')) {
      return;
    }
    p->line = VM_GetValue();
    p->lastLine = p->line + VM_GetValue() - 1;
    MessageWindow_SetBgPltt(BGP_EFDA);
    MessageWindow_Start(p->msgPc);
    MessageWindow_SetInstant(1);
    MessageWindow_ShowLine((u16)p->line);
  }
  if (VM_SeekToNamedArg('c')) {
    p->lineFrames = VM_GetValue();
  } else {
    p->lineFrames = 60;
  }
  p->lineTimer = 0;
}

s32 SensorGuide_Init(SensorGuide* p) {
  if (VM_SeekToNamedArg('i')) {
    p->page = VM_GetValue();
  } else {
    p->page = 0;
  }
  if (VM_SeekToNamedArg('p')) {
    p->scriptID = VM_GetValue();
  } else {
    p->scriptID = 0;
  }
  SensorGuide_LoadBG(p);
  SensorGuide_InitSprites(p);
  SensorGuide_SetupPage(p);
  SensorGuide_InitMessage(p);
  StartBgObjPlttFade(0, 4, 4, 4, 4, 0xFFFF, 0);
}

// 0xB87B, タイトルデモで流れる太陽センサーの解説ページ
SensorGuide* SensorGuide_Create(void) {
  SensorGuide* p = CreateEntity(ENTITY_UNK_8, sizeof(SensorGuide));

  if (p != NULL) {
    SetEntityRoutine(p, SensorGuide_Update, SensorGuide_Destroy);
    if (SensorGuide_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
