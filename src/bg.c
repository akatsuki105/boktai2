#include "camera.h"
#include "file.h"
#include "font.h"
#include "global.h"
#include "sprite.h"
#include "tilemap.h"
#include "tilesets.h"
#include "video.h"

// BG (タイルマップ) 側の処理, src/video.c から分けただけで .text は連続している
// タイルマップバッファ, BG モードと BGnCNT, タイルセットの読み込み, タイルマップへの描画, BG のアフィン変換, タイルマップファイルの取得

extern u8 gTilemapBuffer[BG_SCREEN_SIZE * 4];
extern u16 gStagedDISPCNT;
extern void* gBGTileDataSrcAddrs[4];
extern u16 gBGTileDataTileCounts[4];
extern u16 gBGTileDataVramOffsets[4];
extern u16 u16_03003e8c;
extern s16 gBgAffineMatrix[4];
extern u16 gBgAffineAngle;
extern s16 gBgAffineScaleX;
extern s16 gBgAffineScaleY;
extern s16 gBgAffineCenterX;
extern s16 gBgAffineCenterY;
extern s32 gBgAffineRefX;
extern s32 gBgAffineRefY;
extern s16 gStagedBgAffineMatrix[4];
extern s32 gStagedBgAffineRef[2];
extern u16 gStagedBGOfs[8];

void FUN_08230af8(void* dst, void* src, s32 bytesize);  // src/malloc.c
void Video_GenerateBGMapCore(s32 bg, u32 param_2, u32 param_3, u32 hofs, u32 vofs, unknown* param_6);

// 圧縮されたTilemapFileはここに展開して読み出す, 圧縮されてないならROMから直接読み込むのでここは使われない
EWRAM_DATA u8 gTilemapFileBufferHead[4] = {};  // 0x02021400, 展開先の先頭4バイト, TilemapFile より手前にある, 圧縮のメタデータ(使わない?)
EWRAM_DATA u8 gTilemapFileBuffer[65532] = {};  // 0x02021404, 展開された TilemapFile 本体, 根拠: GetTilemapFile がここを返す

IWRAM_DATA FileID gCachedTilemapFileID = 0;  // 0x03000688, gTilemapFileBuffer に展開済みの TilemapFile の ID, 同じ ID なら展開し直さない, 根拠: GetTilemapFile

const u8 sBlankTile[32] = {0};  // 0x085B0110, Video_ResetBG が BG キャラブロックの先頭タイルを潰すのに使う

BgMapEntry* GetTilemapBuffer(s32 bg) { return (BgMapEntry*)&gTilemapBuffer[BG_SCREEN_SIZE * bg]; }

void ClearTilemapBuffer(void) { ClearMemory(gTilemapBuffer, sizeof(gTilemapBuffer)); }

void ClearBGTilemapBuffer(s32 bg) {
  if (bg == 0) {
    FUN_0822e8b4();
  }
  ClearMemory(GetTilemapBuffer(bg), BG_SCREEN_SIZE);
}

static inline void HideBG(u32 bits) { gStagedDISPCNT &= ~bits; }

// BG のタイルマップと転送待ち状態をすべてクリアし, mode に応じた2通りのうちどちらかで BGnCNT と DISPCNT を設定する
void Video_InitBGMode(s32 mode) {
  s32 i;

  ClearTilemapBuffer();

  for (i = 0; i < 4; i++) {
    gBGTileDataSrcAddrs[i] = NULL;
    gBGTileDataTileCounts[i] = 0;
    gBGTileDataVramOffsets[i] = 0;
  }

  gStagedDISPCNT = 0;
  gBgAffineScaleX = 0x100;
  gBgAffineScaleY = 0x100;
  gBgAffineAngle = 0;
  gBgAffineMatrix[0] = 0x100;
  gBgAffineMatrix[1] = 0;
  gBgAffineMatrix[2] = 0;
  gBgAffineMatrix[3] = 0x100;
  gBgAffineRefX = 0;
  gBgAffineRefY = 0;
  u16_03003e8c = mode;

  switch (mode) {
    case 0: {
      REG_BG0CNT = 0x3F08;
      REG_BG1CNT = 0x3E01;
      REG_BG2CNT = 0x3D03;
      REG_BG3CNT = 0x3C01;
      REG_DISPCNT = 0x7160;
      break;
    }
    case 1: {
      REG_BG0CNT = 0x3F08;
      REG_BG1CNT = 0x3E42;
      REG_BG2CNT = 0x9D81;
      REG_DISPCNT = 0x7161;
      break;
    }
  }

  HideBG(DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_BG3_ON);
}

// BG のタイルマップ・モザイク・ブレンドと転送待ちを落とし, 各 BG キャラブロックの先頭タイルを空にする
void Video_ResetBG(void) {
  s32 i;

  gStagedDISPCNT = 0;
  ClearBGTilemapBuffer(0);
  ClearBGTilemapBuffer(1);
  ClearBGTilemapBuffer(2);
  ClearBGTilemapBuffer(3);
  REG_BG0CNT &= ~BGCNT_MOSAIC;
  REG_BG1CNT &= ~BGCNT_MOSAIC;
  REG_BG2CNT &= ~BGCNT_MOSAIC;
  REG_BG3CNT &= ~BGCNT_MOSAIC;
  REG_BLDCNT = 0;
  REG_BLDALPHA = 0;
  REG_BLDY = 0;

  for (i = 0; i < 4; i++) {
    gBGTileDataSrcAddrs[i] = NULL;
    gBGTileDataTileCounts[i] = 0;
    gBGTileDataVramOffsets[i] = 0;
    DmaCopy32(3, sBlankTile, BG_CHAR_ADDR(i), sizeof(sBlankTile));
  }
}

// gBgStates のスクロール値を BGnHOFS/BGnVOFS の控えに積む, u16_03003e8c が立っている間は BG2/BG3 の代わりに別の控えを書き戻す
void StageBGRegs(void) {
  gStagedBGOfs[0] = gBgStates[0].hofs & 0xFF;
  gStagedBGOfs[1] = gBgStates[0].vofs & 0xFF;
  gStagedBGOfs[2] = gBgStates[1].hofs & 0xFF;
  gStagedBGOfs[3] = gBgStates[1].vofs & 0xFF;

  if (u16_03003e8c == 0) {
    gStagedBGOfs[4] = gBgStates[2].hofs & 0xFF;
    gStagedBGOfs[5] = gBgStates[2].vofs & 0xFF;
    gStagedBGOfs[6] = gBgStates[3].hofs & 0xFF;
    gStagedBGOfs[7] = gBgStates[3].vofs & 0xFF;
  } else {
    gStagedBgAffineMatrix[0] = gBgAffineMatrix[0];
    gStagedBgAffineMatrix[1] = gBgAffineMatrix[1];
    gStagedBgAffineMatrix[2] = gBgAffineMatrix[2];
    gStagedBgAffineMatrix[3] = gBgAffineMatrix[3];
    gStagedBgAffineRef[0] = gBgAffineRefX;
    gStagedBgAffineRef[1] = gBgAffineRefY;
  }
}

void CopyBGTileDataAndTilemapToVram(void) {
  s32 i;

  if (gStagedDISPCNT & DISPCNT_BG0_ON) {
    DmaCopy32(3, GetTilemapBuffer(0), BG_SCREEN_ADDR(31), BG_SCREEN_SIZE);
  }
  if (gStagedDISPCNT & DISPCNT_BG1_ON) {
    DmaCopy32(3, GetTilemapBuffer(1), BG_SCREEN_ADDR(30), BG_SCREEN_SIZE);
  }
  if (gStagedDISPCNT & DISPCNT_BG2_ON) {
    DmaCopy32(3, GetTilemapBuffer(2), BG_SCREEN_ADDR(29), BG_SCREEN_SIZE);
  }
  if (gStagedDISPCNT & DISPCNT_BG3_ON) {
    DmaCopy32(3, GetTilemapBuffer(3), BG_SCREEN_ADDR(28), BG_SCREEN_SIZE);
  }

  for (i = 0; i < 4; i++) {
    if (gBGTileDataSrcAddrs[i] != NULL) {
      FUN_08230af8(gBGTileDataSrcAddrs[i], (void*)(BG_VRAM + gBGTileDataVramOffsets[i]), gBGTileDataTileCounts[i] * 32);
      gBGTileDataSrcAddrs[i] = NULL;
    }
  }
}

// 次の VRAM 転送で BG のタイルデータをどこから何枚どこへ送るかを控えておく
void Video_RequestBGTileData(s32 bg, void* src, u32 vramOffset, u32 tileCount) {
  gBGTileDataSrcAddrs[bg] = src;
  gBGTileDataTileCounts[bg] = tileCount;
  gBGTileDataVramOffsets[bg] = vramOffset;
}

void SetBGPrioDirect(s32 bg, u32 prio) {
  vu16* p;
  u16 v;

  switch (bg) {
    case 0: {
      p = &REG_BG0CNT;
      break;
    }
    case 1: {
      p = &REG_BG1CNT;
      break;
    }
    case 2: {
      p = &REG_BG2CNT;
      break;
    }
    case 3: {
      p = &REG_BG3CNT;
      break;
    }
    default: {
      return;
    }
  }
  v = (*p & 0xFFFC) | prio;
  *p = v;
}

// 残差は ands/orrs に使う r0 と r1 が入れ替わっているだけ (命令列は一致), Tier A-C は試済
NON_MATCH void SetBGCharBaseDirect(s32 bg, u32 charbase) {
#ifdef NONMATCHING_C
  vu16* p;
  u16 v;

  switch (bg) {
    case 0: {
      p = &REG_BG0CNT;
      break;
    }
    case 1: {
      p = &REG_BG1CNT;
      break;
    }
    case 2: {
      p = &REG_BG2CNT;
      break;
    }
    case 3: {
      p = &REG_BG3CNT;
      break;
    }
    default: {
      return;
    }
  }
  v = (*p & 0xFFF3) | BGCNT_CHARBASE(charbase);
  *p = v;
#else
  INCFUNC("asm/func/SetBGCharBaseDirect.inc");
#endif
}

// BG のアフィン変換の控えを作る, (centerX, centerY) を画面の (120, 80) に合わせたまま angle 回転・1/scale 倍する
// 残差は 152 命令 vs 164 命令 で、原典は 0x10000/scale の除算を4回とも実行しているのに対しこちらは X と Y で 1 回ずつに CSE されてしまう
NON_MATCH void Video_SetBGAffine(s32 centerX, s32 centerY, s32 angle, u16 scaleX, s32 scaleY) {
#ifdef NONMATCHING_C
  gBgAffineCenterX = centerX;
  gBgAffineCenterY = centerY;
  gBgAffineAngle = angle;
  gBgAffineScaleX = scaleX;
  gBgAffineScaleY = scaleY;

  gBgAffineMatrix[0] = (s16)(0x10000 / gBgAffineScaleX) * (gSineTable[(gBgAffineAngle + 0x40) & 0xFF] >> 4) / 256;
  gBgAffineMatrix[1] = (s16)(0x10000 / gBgAffineScaleX) * (gSineTable[gBgAffineAngle & 0xFF] >> 4) / 256;
  gBgAffineMatrix[2] = (s16)(0x10000 / gBgAffineScaleY) * (-gSineTable[gBgAffineAngle & 0xFF] >> 4) / 256;
  gBgAffineMatrix[3] = (s16)(0x10000 / gBgAffineScaleY) * (gSineTable[(gBgAffineAngle + 0x40) & 0xFF] >> 4) / 256;

  gBgAffineRefX = ((120 - gBgAffineCenterX) << 8) - gBgAffineMatrix[0] * 120 - gBgAffineMatrix[1] * 80;
  gBgAffineRefY = ((120 - gBgAffineCenterY) << 8) - gBgAffineMatrix[2] * 120 - gBgAffineMatrix[3] * 80;
#else
  INCFUNC("asm/func/Video_SetBGAffine.inc");
#endif
}

// タイルセットの部品表から ID の一致する TileSetPart を探す
TileSetPart* TileSet_FindPart(TileSet* p, u16 id) {
  TileSetPart* part = p->parts;
  s32 i;

  for (i = 0; i < p->partCount; i++) {
    if (part->id == id) {
      return part;
    }
    part++;
  }
  return NULL;
}

// ids の TileSetPart を順に引いて、その参照先のタイルを BG VRAM の tileidx 以降へ 1 枚ずつ DMA で流す
// 残差は vramOffset をループ用に1本複写する命令 (adds r7, r4, #0) が出ないことだけ, 三項演算子にすると悪化する, Tier A-B は試済
NON_MATCH s32 Video_LoadTileSetParts(s32 bg, TileSetFile* f, s32 count, u16* ids, s32 tileidx) {
#ifdef NONMATCHING_C
  TileSet hdr;
  s32 vramOffset;
  s32 i, j;

  // 相対オフセットをROMアドレスに変換する
  hdr = *f;
  hdr.parts = (TileSetPart*)((u32)hdr.parts + (u32)f);
  hdr.refs = (u16*)((u32)hdr.refs + (u32)f);
  hdr.tiles = (u8*)((u32)hdr.tiles + (u32)f);

  vramOffset = tileidx * 32;
  if (bg == 0) {
    vramOffset = 0x8000;
  }

  for (i = 0; i < count; i++) {
    TileSetPart* part = TileSet_FindPart(&hdr, ids[i]);
    u16* refs = (u16*)((u32)hdr.refs + part->startIndex);

    for (j = 0; j < part->tileCount; j++) {
      DmaCopy32(3, hdr.tiles + *refs * 32, (void*)(BG_VRAM + vramOffset), 32);
      refs++;
      vramOffset += 32;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/Video_LoadTileSetParts.inc");
#endif
}

// BG のタイルマップバッファの (x, y) にエントリ (タイル番号, 反転, パレット) を書く
void Video_SetBGTile(s32 bg, u32 x8, u32 y8, u32 tileidx, u32 flip, u32 pltt) {
  BgState* s = &gBgStates[bg];

  s->tilemap[(s->width16 << 1) * y8 + x8] = tileidx | (flip << 10) | (pltt << 12);
}

// BG のタイルマップバッファの矩形 (x, y, w, h) に、tiles のタイル番号を反転・パレット付きで順に書く
// 命令数は一致, 残差は pitch と map のどちらをスタックに退避するかだけ (元は両方), 双子の Video_FillBGRect と同じ残差で Tier A-C は試済
NON_MATCH void Video_DrawBGRect(s32 bg, s32 x, s32 y, s32 w, s32 h, u32* tiles, u32 flip, u32 pltt) {
#ifdef NONMATCHING_C
  BgState* s = &gBgStates[bg];
  BgMapEntry* map = s->tilemap;
  s32 pitch = s->width16 << 1;
  s32 right = x + w;
  s32 bottom = y + h;
  s32 i, j;

  for (j = y; j < bottom; j++) {
    for (i = x; i < right; i++) {
      map[pitch * j + i] = *tiles++ | (flip << 10) | (pltt << 12);
    }
  }
#else
  INCFUNC("asm/func/Video_DrawBGRect.inc");
#endif
}

// BG のタイルマップバッファの矩形 (x, y, w, h) を、同じタイル番号で反転・パレット付きで塗る
// 命令数は一致, 残差は map と bottom のどちらをスタックに退避するかだけ (元は map), Tier A-C は試済
NON_MATCH void Video_FillBGRect(s32 bg, s32 x, s32 y, s32 w, s32 h, u32 tileidx, u32 flip, u32 pltt) {
#ifdef NONMATCHING_C
  BgState* s = &gBgStates[bg];
  BgMapEntry* map = s->tilemap;
  s32 pitch = s->width16 << 1;
  s32 right = x + w;
  s32 bottom = y + h;
  s32 i, j;

  for (j = y; j < bottom; j++) {
    for (i = x; i < right; i++) {
      map[pitch * j + i] = tileidx | (flip << 10) | (pltt << 12);
    }
  }
#else
  INCFUNC("asm/func/Video_FillBGRect.inc");
#endif
}

// 10進数 n を digitCount 桁の右詰めで BG のタイルマップに書く, baseTile が数字 0 のタイル番号
void Video_DrawBGNumber(s32 bg, s32 x, s32 y, u32 n, u32 baseTile, s32 digitCount, u32 pltt) {
  u32 digits[8];
  s32 i, first;
  u32 t;

  if (digitCount > 8) {
    digitCount = 8;
  }

  // 上の位から順に繰り返し減算で1桁取り出してタイル番号に直す
#define PUT_DIGIT(pow) \
  t = baseTile;        \
  while (n >= (pow)) { \
    t++;               \
    n -= (pow);        \
  }                    \
  digits[i++] = t

  i = 0;
  PUT_DIGIT(10000000);
  PUT_DIGIT(1000000);
  PUT_DIGIT(100000);
  PUT_DIGIT(10000);
  PUT_DIGIT(1000);
  PUT_DIGIT(100);
  PUT_DIGIT(10);
  PUT_DIGIT(1);

#undef PUT_DIGIT

  first = i - digitCount;
  Video_DrawBGRect(bg, x, y, digitCount, 1, &digits[first], 0, pltt);
}

// Video_SetupBG と FUN_0822bf80 だけが読む 0x40 バイトのタイルマップファイルのヘッダで、ROM 内にこの形式のファイルは存在しない
// Video_SetupBG の呼び出し元は sun_countdown.c の1箇所だけだが TILEMAP_596F は "MP" で始まるので、そこを呼ぶ else 側は通らない
// FUN_0822bf80 は呼び出し元なし, GetTilemapFile がもう一方のマジックとして見ている 0x005E8CC5 で始まるファイルも ROM に無い
// Tilemaps と同じく、ポインタのメンバは ROM では &ファイル先頭からのオフセットが入っている
typedef struct {
  u8 unk_00[12];         // 0x00
  void* unk_0c;          // 0x0C
  s16 tileCount;         // 0x10, Video_RequestBGTileData に渡すタイル数
  s16 loadOffset;        // 0x12, タイルデータのコピー先 (VRAMのタイル単位オフセット)
  u8* tiles;             // 0x14, GBAタイル
  u8 unk_18[4];          // 0x18
  void* unk_1c;          // 0x1C, gBgStates[].unk_24 に入る
  u8 unk_20[4];          // 0x20
  MetatileIdx16* mtmap;  // 0x24, gBgStates[].mtmap に入る
  u8 unk_28[4];          // 0x28
  u32 pitch;             // 0x2C, FUN_0822bf80 が行送りに使う
  u8 unk_30[8];          // 0x30
  u32 width;             // 0x38, gBgStates[].width16 に入る
  u32 height;            // 0x3C, gBgStates[].height16 に入る
} UnusedTilemapFile;
static_assert(sizeof(UnusedTilemapFile) == 64);

NAKED void* UNUSED FUN_0822bf80(void* dst, u32 val) { INCFUNC("asm/func/FUN_0822bf80.inc"); }

// UnusedTilemapFile を BG に設定する, 到達しないので f の型も呼び出し元 (Tilemaps* を渡している) と食い違ったままになっている
NAKED void Video_SetupBG(s32 bg, u32 param_2, unknown* f, u32 unused, s16 param_5, s16 param_6, u32 prio, BgMapEntry* tilemap) { INCFUNC("asm/func/Video_SetupBG.inc"); }

NAKED void Video_SetupBGLayout(s32 layout, u32 param_2, TilemapFile* f, u32 param_4, u32 param_5, s32 count, s32* indices) { INCFUNC("asm/func/Video_SetupBGLayout.inc"); }

// タイルマップファイルの指定レイヤを (オフセットをアドレスに直してから) gBgStates に割り当てる
void Video_SetBGLayer(s32 bg, TilemapFile* f, s32 layerIdx) {
  Tilemaps hdr;
  TilemapLayer layer;
  BgState* s;
  u16 w, h;

  if (bg == 0) {
    FUN_0822e8b4();
  }

  // 相対オフセットをROMアドレスに変換する
  hdr = *f;
  hdr.layers = (TilemapLayer*)((u32)hdr.layers + (u32)f);
  hdr.tiles = (u8*)((u32)hdr.tiles + (u32)f);
  hdr.metatiles = (BgMapEntry*)((u32)hdr.metatiles + (u32)f);

  s = &gBgStates[bg];
  layer = hdr.layers[layerIdx];
  layer.mtmap = (u16*)((u32)layer.mtmap + (u32)f);

  s->unk_10 = 0x1000;
  s->unk_12 = 0x1000;
  s->mtmap = layer.mtmap;
  w = layer.width;
  s->width16 = w;
  h = layer.height;
  s->height16 = h;
  s->unk_1c = w;
  s->unk_1e = h;
}

void Video_GenerateBGMap(s32 bg, u32 param_2, u32 param_3, u32 hofs, u32 vofs) { Video_GenerateBGMapCore(bg, param_2, param_3, hofs, vofs, NULL); }

NAKED void Video_GenerateBGMapCore(s32 bg, u32 param_2, u32 param_3, u32 hofs, u32 vofs, unknown* param_6) { INCFUNC("asm/func/Video_GenerateBGMapCore.inc"); }

// TilemapFile が圧縮されてたら展開して返す、圧縮されてなかったらそのまま返す
TilemapFile* GetTilemapFile(FileID id) {
  u32 fileID = id;

  u8* file = GetFile(DIR_TILE_MAP, fileID);
  if (file == NULL) {
    return NULL;
  }
  if ((file[0] == 'M' && file[1] == 'P') || *(u32*)file == 0x005E8CC5) {  // "MP"
    return (TilemapFile*)file;
  }
  if (gCachedTilemapFileID != fileID) {
    gCachedTilemapFileID = fileID;
    LZ77UnCompWram(file, gTilemapFileBufferHead);
  }
  return (TilemapFile*)gTilemapFileBuffer;
}
