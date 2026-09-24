#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite.h"
#include "video.h"

// ゲームクリア時のリザルト画面
typedef struct GameResult {
  Entity e;           // 0x000, ENTITY_UNK_11
  MainSpriteGfx gfx;  // 0x018, SPRITE_42E2
  void* tilemapfile;  // 0x038
  rgb555* pltt;       // 0x03C
  u32 unk_40;         // 0x040, なんかのbitfield?
  u32 scriptID_44;    // 0x044, 0x08222954
  s32 unk_48;         // 0x048, sUpdates の idx (このゲームでは常に 0)
  s32 unk_4c;         // 0x04C
  s32 unk_50;         // 0x050
  s32 unk_54;         // 0x054
  u8 unk_58[0x76 - 0x58];
  char unk_76[2];                              // 0x076, 0x08222c2a
  MainSprite sprites[8];                       // 0x078, 0x082226a6 で 8回ループ処理してるので長さは8
  bool32 unk_378;                              // 0x378
  void (*updateCallback)(struct GameResult*);  // 0x37C, GameResult_Update で呼ばれる
} GameResult;
static_assert(sizeof(GameResult) == 896);

// 8枚のスプライトを横一列に並べて隠しておく
NON_MATCH void FUN_08222270(GameResult* p) {
#ifdef NONMATCHING_C
  u8 xs[8] = {0x90, 0x98, 0xA8, 0xB0, 0xB8, 0xC8, 0xD0, 0xD8};
  Vec3 pos;
  MainSprite* spr;
  s32 i;

  pos.y = 56, pos.z = 0;
  spr = p->sprites;
  for (i = 0; i < 8; spr++, i++) {
    pos.x = xs[i];
    MainSprite_Add(spr, &p->gfx, 0, 0x30, 0, 0, 60, &pos);
    spr->flags |= SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/FUN_08222270.inc");
#endif
}

void FUN_082222f0(GameResult* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

void FUN_0822230c(GameResult* p) {
  s32 i;

  for (i = 0; i < 8; i++) {
    MainSprite_Hide(&p->sprites[i]);
  }
}

NAKED static void _GameResult_Update(GameResult* p) { INCFUNC("asm/func/_GameResult_Update.inc"); }

// BG11 にリザルト画面のタイルマップを敷く
void FUN_082229ac(GameResult* p) {
  s32 bgIndices[1];
  p->tilemapfile = GetFile(DIR_TILE_MAP, 0x33B2);
  bgIndices[0] = 11;
  Video_SetupBGLayout(1, 0, p->tilemapfile, 0, 0, 1, bgIndices);
}

// 背景パレットを読み込んで作業用バッファへ流す
void FUN_082229e8(GameResult* p) {
  p->pltt = GetBgPlttFile(0xE9C3)->body;
  CpuCopy32(p->pltt, gBgPlttBuffer, 160);
}

// リザルト画面のスプライトファイルを開く
void FUN_08222a18(GameResult* p) {
  MainSpriteFile* file = GetFile(DIR_MAIN_SPRITE, SPRITE_42E2);

  p->gfx = *(MainSpriteGfx*)file;
  OpenMainSpriteFile(&p->gfx, file);
  FUN_08222270(p);
}

void FUN_08222a54(GameResult* p, s32 idx) {
  static void (*const sUpdates[1])(GameResult*) = {
      _GameResult_Update,
  };  // 0x085B0080

  p->unk_48 = idx;
  p->unk_4c = 0;
  p->updateCallback = sUpdates[idx];
  {
    u32 unk_40 = 1;
    p->unk_40 |= unk_40;
  }
  p->unk_50 = 0;
  p->unk_54 = 0;
  p->unk_40 |= (1 << 1);
}

s32 GameResult_Update(GameResult* p) {
  if ((p->unk_40 & (1 << 0)) == 0) p->unk_4c++;
  if ((p->unk_40 & (1 << 1)) == 0) p->unk_54++;
  p->updateCallback(p);  // このゲームでは常に _GameResult_Update
  return 0;
}

s32 GameResult_Destroy(GameResult* p) {
  FUN_082222f0(p);
  return 0;
}

NAKED s32 GameResult_Init(GameResult* p) { INCFUNC("asm/func/GameResult_Init.inc"); }

GameResult* GameResult_Create(void) {
  GameResult* p = CreateEntity(ENTITY_UNK_11, sizeof(GameResult));

  if (p != NULL) {
    SetEntityRoutine(p, GameResult_Update, GameResult_Destroy);
    if (GameResult_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
