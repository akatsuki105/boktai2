#include "entity.h"
#include "file.h"
#include "global.h"
#include "video.h"

// 画面の BG に時計 (gClock の 日の入/日の出までの残り時間) を描くシングルトン
typedef struct {
  Entity e;              // 0x00, ENTITY_UNK_9
  u16 unk_18;            // 0x18, Entity95F8_Create の引数, 書き込むだけで読み手が見つかっていない
  u8 unk_1a;             // 0x1A, _Init が '.f' を入れる, 読み手が見つかっていない
  u8 bgNum;              // 0x1B, SetBGPrioDirect / Video_SetupBG / GetTilemapBuffer に渡す BG 番号, _Init が 0 を入れる
  FileID tilemapFileID;  // 0x1C, _Init が 0x596F を入れて GetFile(DIR_TILE_MAP, ...) に渡す
  FileID plttFileID;     // 0x1E, _Init が '.p' を入れて GetFile(DIR_BGPLTT, ...) に渡す
  rgb555* pltt;          // 0x20, &gBgPlttBuffer[0xD0], CpuSet の転送先
  void* plttSrc;         // 0x24, plttFileID のファイル + 0x1B4, CpuSet の転送元
  u16 unk_28;            // 0x28, _Redraw が描画の前に 0xF、後に 0 を入れる, 読み手が見つかっていない
  u8 unk_2a[2];          // 0x2A, 読み手も書き手も見つかっていない
} Entity95F8;
static_assert(sizeof(Entity95F8) == 44);

IWRAM_DATA Entity95F8* gEntity95F8 = NULL;  // 0x0300004C

INCASM("asm/entity_95f8.inc");
