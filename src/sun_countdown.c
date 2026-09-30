#include "entity.h"
#include "file.h"
#include "global.h"
#include "tilemap.h"
#include "time.h"
#include "video.h"
#include "vm.h"

// BGに "日の入/日の出までの残り時間" を描くシングルトン
typedef struct {
  Entity e;              // 0x00, ENTITY_UNK_9
  u16 unk_18;            // 0x18, SunCountdown_Create の引数, 書き込むだけで読み手が見つかっていない
  u8 unk_1a;             // 0x1A, _Init が '.f' を入れる, 読み手が見つかっていない
  u8 bgNum;              // 0x1B, SetBGPrioDirect / Video_SetupBG / GetTilemapBuffer に渡す BG 番号, _Init が 0 を入れる
  FileID tilemapFileID;  // 0x1C, _Init が 0x596F を入れて GetFile(DIR_TILE_MAP, ...) に渡す
  FileID plttFileID;     // 0x1E, _Init が '.p' を入れて GetFile(DIR_BGPLTT, ...) に渡す
  rgb555* pltt;          // 0x20, &gBgPlttBuffer[0xD0], CpuSet の転送先
  void* plttSrc;         // 0x24, plttFileID のファイル + 0x1B4, CpuSet の転送元
  u16 unk_28;            // 0x28, _Redraw が描画の前に 0xF、後に 0 を入れる, 読み手が見つかっていない
  u8 unk_2a[2];          // 0x2A, 読み手も書き手も見つかっていない
} SunCountdown;
static_assert(sizeof(SunCountdown) == 44);

IWRAM_DATA SunCountdown* gSunCountdown = NULL;  // 0x0300004C

void SunCountdown_ClearPtr(void) { gSunCountdown = NULL; }

// BG のタイルマップ上で (x, y) のエントリを指す
// 残差は命令2つの位置だけ (tilemap のロードが x*2 の前か後か, u16 分の <<1 が y と unk_18 のどちらに乗るか), Tier A-B は試済, 未: Tier C
NON_MATCH u16* SunCountdown_GetTilePtr(s32 bgNum, s32 x, s32 y) {
#ifdef NONMATCHING_C
  BgState* bg = &gBgStates[bgNum];

  return bg->tilemap + x + (bg->unk_18 * 2) * y;
#else
  INCFUNC("asm/func/SunCountdown_GetTilePtr.inc");
#endif
}

// 画面下部に「日の入まであと HH:MM」(夜なら日の出まで) を描く
NAKED void SunCountdown_Draw(SunCountdown* p) { INCFUNC("asm/func/SunCountdown_Draw.inc"); }

void SunCountdown_Redraw(SunCountdown* p) {
  s32 year;
  s32 month;
  s32 day;

  ParseBCDDate(&year, &month, &day, (BCDDate)GetDate());
  p->unk_28 = 15;
  SunCountdown_Draw(p);
  p->unk_28 = 0;
}

s32 SunCountdown_Update(SunCountdown* p) { SunCountdown_Redraw(p); }

s32 SunCountdown_Destroy(SunCountdown* p) { gSunCountdown = NULL; }

// 残差107対114命令, 相違は3点: magic の2バイト比較が ldrh 1発に畳まれる, 原典は p を r6 に置き 0 の共有が1つだけ, 原典は高位レジスタを r8/r9 の2本使う (こちらは r8 のみ)
// Tier A-B は試済, 未: Tier C (レジスタ圧の再構成)
NON_MATCH s32 SunCountdown_Init(SunCountdown* p, u16 n) {
#ifdef NONMATCHING_C
  Tilemaps* tilemap;
  void* plttFile;
  u16* dst;
  s32 x;
  s32 y;

  gSunCountdown = p;
  p->unk_18 = n;
  p->unk_1a = VM_GetKeywordValue('f', 0);
  p->tilemapFileID = 0x596F;
  p->plttFileID = VM_GetKeywordValue('p', 0);
  p->pltt = &gBgPlttBuffer[0xD0];
  p->bgNum = 0;
  tilemap = GetFile(DIR_TILE_MAP, p->tilemapFileID);
  if (tilemap == NULL) {
    return -1;
  }
  plttFile = GetFile(DIR_BGPLTT, p->plttFileID);
  if (plttFile == NULL) {
    return -1;
  }
  if (tilemap->magic[0] == 'M' && tilemap->magic[1] == 'P') {
    SetBGPrioDirect(p->bgNum, 0);
  } else {
    Video_SetupBG(p->bgNum, 0, tilemap, 0, 0, 0, 0, GetTilemapBuffer(0));
  }
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  dst = SunCountdown_GetTilePtr(0, 0, 0);
  for (y = 0; y < 15; y++) {
    for (x = 0; x < gBgStates[0].unk_18 * 2; x++) {
      *dst++ = (13 << 12);
    }
  }
  p->plttSrc = (u8*)plttFile + 0x1B4;
  CpuCopy32(p->plttSrc, p->pltt, 96);
  return 0;
#else
  INCFUNC("asm/func/SunCountdown_Init.inc");
#endif
}

SunCountdown* SunCountdown_Create(s32 n) {
  SunCountdown* p = CreateEntity(ENTITY_UNK_9, sizeof(SunCountdown));

  if (p != NULL) {
    SetEntityRoutine(p, SunCountdown_Update, SunCountdown_Destroy);
    if (SunCountdown_Init(p, n) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
