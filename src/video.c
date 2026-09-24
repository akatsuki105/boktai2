#include "video.h"

#include "camera.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "particle.h"
#include "sprite.h"
#include "tilemap.h"
#include "tilesets.h"

extern u8 gTilemapBuffer[BG_SCREEN_SIZE * 4];
extern u32 gFrameCounter;
extern OamData gOAMBuffer[128];
extern u16 u16_ARRAY_03003a30[4];
extern s32 s32_03003a38;
extern s32 s32_03003a3c;
extern s32 s32_03003e40;
extern s32 gOamDirty;
extern s32 s32_03002ca8;
extern s32 s32_03003500;
extern u16 gStagedDISPCNT;
extern s32 s32_0300446c;
extern u16 gWIN0H;
extern u16 gWIN0V;
extern u16 gWIN1H;
extern u16 gWIN1V;
extern void* gBGTileDataSrcAddrs[4];
extern u16 gBGTileDataTileCounts[4];
extern u16 gBGTileDataVramOffsets[4];
extern u16 gObjPlttLen;

extern u8 gOAMHeightTable[16];
extern u8 gOAMWidthTable[16];
extern u8 gOAMTileWidthTable[16];
extern u8 gOAMTileHeightTable[16];
extern u8 gOAMTileCounts[16];
extern u32 gOAMShapeSizeAttrTable[16];

extern u16 u16_0300357c;
extern s16 gObjTileCursor;
extern s16 gParticleFileTileCount;
extern ParticleFile* gParticleFile;  // 0x0300358C

extern Procedure gDrawAuxSprites;
extern Procedure gDrawParticles;
extern Procedure gDrawMainSprites;

IWRAM_DATA Entity gVideoCommit = {};                      // 0x03000258
IWRAM_DATA Entity gVideoRender = {};                      // 0x03000270
IWRAM_DATA u8 u8_03000288[0x03000688 - 0x03000288] = {};  // おそらく最初の方は gVideoRender の続きが入るが、どこまでが gVideoRender なのかは不明
IWRAM_DATA FileID gCachedTilemapFileID = 0;               // 0x03000688, gTilemapFileBuffer に展開済みの TilemapFile の ID, 同じ ID なら展開し直さない, 根拠: GetTilemapFile
IWRAM_DATA u16 u16_0300068a = 0;                          // 0x0300068A, unused, padding?
IWRAM_DATA u16 gSavedDISPCNT = 0;                         // 0x0300068C
IWRAM_DATA u16 gSavedWIN0H = 0;                           // 0x0300068E
IWRAM_DATA u16 gSavedWIN1H = 0;                           // 0x03000690
IWRAM_DATA u16 gSavedWIN0V = 0;                           // 0x03000692
IWRAM_DATA u16 gSavedWIN1V = 0;                           // 0x03000694
IWRAM_DATA u16 gSavedWININ = 0;                           // 0x03000696, Video_SaveWININOUT が退避した WININ
IWRAM_DATA u16 gSavedWINOUT = 0;                          // 0x03000698, Video_SaveWININOUT が退避した WINOUT

const u8 u8_ARRAY_085b0110[32] = {0};

#define SPRITE_SIZE(widthPixel, heightPixel) ((heightPixel << 8) | widthPixel)

// clang-format off
// idx: SpriteShape
const u16 gSpriteSizeTable[16] = {
// OAM0.14-15:  Square(0)             Horizontal(1)         Vertical(2)           Prohibited(3)
                SPRITE_SIZE( 8,  8),  SPRITE_SIZE(16,  8),  SPRITE_SIZE( 8, 16),  0x0,
                SPRITE_SIZE(16, 16),  SPRITE_SIZE(32,  8),  SPRITE_SIZE( 8, 32),  0x0,
                SPRITE_SIZE(32, 32),  SPRITE_SIZE(32, 16),  SPRITE_SIZE(16, 32),  0x0,
                SPRITE_SIZE(64, 64),  SPRITE_SIZE(64, 32),  SPRITE_SIZE(32, 64),  0x0,
}; // 0x085b0130
// clang-format on

#undef SPRITE_SIZE

void FUN_0822e8b4(void);
void FUN_0822d014(rgb555* pltt, s32 val);
void Video_GenerateBGMapCore(s32 bg, u32 param_2, u32 param_3, u32 hofs, u32 vofs, unknown* param_6);
void Video_ResetObjTileAlloc(void);
void Video_ResetFrameState(u32 clearOam);
void FUN_0822b470(void);
void FUN_0822d114(void);
void FUN_0822d248(void);
void FUN_0822d630(void);
void FUN_0822d828(void);
void FUN_0822d8e8(void);
void FUN_0822d98c(void);
void StageBGRegs(void);
void CopyBGTileDataAndTilemapToVram(void);
void FUN_0822b308(void);
void FUN_0822e73c(void);
void FUN_0822eef4(void);
void Video_ApplyMosaic(void);
void CommitPalette(void);

typedef Entity VideoCommit;  // Entity と同じサイズ, 他のEntityにある Create, Init, Destroy 関数 はなく Update (VideoCommit_Update) のみ
// VBlank を待って、この 1 フレーム分の OAM・パレット・タイル・レジスタをまとめてハードへ反映する
s32 VideoCommit_Update(VideoCommit* p) {
  StageBGRegs();
  WaitForVBlank();
  FUN_0822eef4();
  if (gOamDirty & 1) {
    DmaCopy32(3, gOAMBuffer, (void*)OAM, OAM_SIZE);
    gOamDirty &= ~1;
  }
  CommitPalette();
  FUN_0822b308();
  FUN_0822e73c();
  CopyBGTileDataAndTilemapToVram();
  REG_DISPCNT &= ~(DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON);
  if (s32_03002ca8 == 0) {
    REG_DISPCNT |= gStagedDISPCNT | DISPCNT_OBJ_ON;
  }
  Video_ApplyMosaic();
  s32_03003500 = 0;
  return 0;
}

typedef Entity VideoRender;  // Entity と同じサイズ, 他のEntityにある Create, Init, Destroy 関数 はなく Update (VideoRender_Update) のみ
// 1 フレーム分の描画処理。登録された 3 つのコールバックを回し、パレットを組み立ててフレーム数を進める
s32 VideoRender_Update(VideoRender* p) {
  FUN_0822d114();
  Video_ResetObjTileAlloc();
  gDrawAuxSprites();
  gDrawMainSprites();
  gDrawParticles();
  FUN_0822b470();
  if (s32_0300446c != 0) {
    FUN_0822d8e8();
    FUN_0822d828();
    if (s32_0300446c > 0) {
      s32_0300446c--;
    }
    if (s32_0300446c == 0) {
      FUN_0822d98c();
    }
  } else {
    FUN_0822d630();
    FUN_0822d248();
  }
  Video_ResetFrameState(0);
  gFrameCounter++;
  return 0;
}

NAKED void FUN_0822a2a8(void) { INCFUNC("asm/func/FUN_0822a2a8.inc"); }

void UNUSED FUN_0822a2f8(AuxSprite* p) { gAuxSpriteLists[gSpriteListIdx] = p; }

void UNUSED FUN_0822a310(Particle* p) { gParticleLists[gSpriteListIdx] = p; }

void UNUSED FUN_0822a328(MainSprite* p) { gMainSpriteLists[gSpriteListIdx] = p; }

// 描画リストの先頭にノードを繋ぐ
s32 Video_AddAuxSpriteIntoDrawList(AuxSprite* p, s32 idx) {
  AuxSprite* head;
  p->listIdx = idx;
  p->active = TRUE;
  p->prev = NULL;
  head = gAuxSpriteLists[idx];
  p->next = head;
  if (head != NULL) {
    head->prev = p;
  }
  gAuxSpriteLists[idx] = p;
  return 0;
}

// 描画リストからノードを外す
void Video_RemoveAuxSpriteFromDrawList(AuxSprite* p, s32 idx) {
  AuxSprite* prev = p->prev;
  AuxSprite* next = p->next;
  p->active = 0;
  if (prev != NULL) {
    prev->next = next;
  } else {
    gAuxSpriteLists[idx] = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
}

// 描画リストの先頭に Particle を繋ぐ
s32 Video_AddParticleIntoDrawList(Particle* p, s32 idx) {
  Particle* head;

  p->listIdx = idx;
  p->active = 1;
  p->prev = NULL;
  head = gParticleLists[idx];
  p->next = head;
  if (head != NULL) {
    head->prev = p;
  }
  gParticleLists[idx] = p;
  return 0;
}

// 描画リストから Particle を外す
void Video_RemoveParticleFromDrawList(Particle* p, s32 idx) {
  Particle* prev = p->prev;
  Particle* next = p->next;
  p->active = 0;
  if (prev != NULL) {
    prev->next = next;
  } else {
    gParticleLists[idx] = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
}

// 描画リストの先頭に MainSprite を繋ぐ
s32 Video_AddMainSpriteIntoDrawList(MainSprite* p, s32 idx) {
  MainSprite* head;

  p->listIdx = idx;
  p->active = 1;
  p->prev = NULL;
  head = gMainSpriteLists[idx];
  p->next = head;
  if (head != NULL) {
    head->prev = p;
  }
  gMainSpriteLists[idx] = p;
  return 0;
}

// 描画リストから MainSprite を外す
void Video_RemoveMainSpriteFromDrawList(MainSprite* p, s32 idx) {
  MainSprite* prev = p->prev;
  MainSprite* next = p->next;
  p->active = 0;
  if (prev != NULL) {
    prev->next = next;
  } else {
    gMainSpriteLists[idx] = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
}

// この場面で使う3つの描画パスを差し替える。引数の順は実行順ではないので注意
void Video_SetDrawPasses(s32 val, Procedure ptclFn, Procedure auxsprFn, Procedure mainsprFn) {
  gCameraCoords.unk_12 = val;
  gDrawParticles = ptclFn;
  gDrawAuxSprites = auxsprFn;
  gDrawMainSprites = mainsprFn;
}

static inline void _AuxSprite_Setup(AuxSprite* p, AuxSpriteGfx* gfx, SpriteFlags flags) {
  p->flags = flags;
  p->unk_05 = 1;
  p->oamAttr = 0;
  p->scaleX = FRACUNIT_6, p->scaleY = FRACUNIT_6;
  p->rotation = 0;
  p->priority = 2;
  FUN_0822a4fc(p, gfx);
}

// ノードを初期化して描画リストに繋ぐ
void AuxSprite_Add(AuxSprite* p, AuxSpriteGfx* gfx, SpriteFlags flags) {
  if (!p->active) {
    u32 mask;
    s32 idx;
    _AuxSprite_Setup(p, gfx, flags);
    mask = SPRFLAG_DRAWLIST;
    idx = (u32)(0 - (flags & mask)) >> 31;
    p->prev = NULL, p->next = NULL;
    Video_AddAuxSpriteIntoDrawList(p, idx);
  }
}

// ノードを初期化する (AuxSprite_Add と違い描画リストには繋がない)
void AuxSprite_Setup(AuxSprite* p, AuxSpriteGfx* gfx, SpriteFlags flags) {
  if (!p->active) {
    _AuxSprite_Setup(p, gfx, flags);
    p->prev = NULL, p->next = NULL;
  }
}

// 描画リストに繋がれていればノードを外す
void AuxSprite_Remove(AuxSprite* p) {
  if (p->active) {
    Video_RemoveAuxSpriteFromDrawList(p, p->listIdx);
  }
}

void nop_0822a4f8(void* _, s32 unused1, s32 unused2) {}

// ノードに AuxSpriteGfx を割り当て、OAM属性のシェイプ/サイズを作り直す
void FUN_0822a4fc(AuxSprite* p, AuxSpriteGfx* gfx) {
  if (gfx != NULL) {
    p->metaspriteIdx = 0;
    p->unk_12 = 0;
    p->plttOffset = 0;
    p->spriteWidth = gOAMWidthTable[gfx->shape];
    p->spriteHeight = gOAMHeightTable[gfx->shape];
    p->offsetX = 0, p->offsetY = 0;
    p->oamAttr = (p->oamAttr & 0x1C00) | (((gfx->shape & 3) << 14) | ((gfx->shape & 0xC) << 28));
    if (gfx->flags & ASGFLAG_BPP8) p->oamAttr |= OAM0_8BPP;
    p->gfx = gfx;
  }
}

void FUN_0822a568(AuxSprite* p, AuxSpriteGfx* gfx) {
  if (gfx != NULL) {
    p->gfx = gfx;
  }
}

NAKED void AuxSprite_DrawInternal(AuxSprite* p, s32 x, s32 y, s32 z) { INCFUNC("asm/func/AuxSprite_DrawInternal.inc"); }

NAKED void FUN_0822aaac(void) { INCFUNC("asm/func/FUN_0822aaac.inc"); }

NAKED void FUN_0822ac90(void) { INCFUNC("asm/func/FUN_0822ac90.inc"); }

NAKED void FUN_0822adac(void) { INCFUNC("asm/func/FUN_0822adac.inc"); }

NAKED void FUN_0822af38(void) { INCFUNC("asm/func/FUN_0822af38.inc"); }

void nop_0822b09c(void) {}

// --------------------------------------------

void InitPltt(void) {
  ObjPlttFile* f = GetFile(DIR_OBJPLTT, 0xC5E9);
  gObjPlttLen = f->length;
  gObjPlttData = f->body;
  FUN_0822d014(gObjPlttData, 8);
}

// パーティクルファイルを覚えて、タイルデータを OBJ VRAM へ流し込む
void LoadParticleFile(ParticleFile* f) {
  gParticleFile = f;
  gParticleFileTileCount = f->tileCount;
  DmaCopy32(3, (u8*)f + f->offsetToTiles, OBJ_VRAM0, f->tileCount << 5);
}

/**
 * @param ptclgroupID PTCL_GROUP_0 or PTCL_GROUP_1 or PTCL_GROUP_2
 */
ParticleGroup* GetParticleGroup(u16 ptclgroupID) {
  ParticleFile* f = gParticleFile;
  ParticleGroup* g;
  s32 i;

  if (f == NULL) {
    return NULL;
  }

  g = f->groups;
  for (i = 0; i < f->groupCount; i++, g++) {
    if (g->id == ptclgroupID) {
      return g;
    }
  }
  return NULL;
}

void LoadAuxSpriteFile(AuxSpriteFile* f) {
  gAuxSpriteFile = f;
  gAuxSubsprites = (AuxSubsprite*)((u8*)f + f->offsetToSubsprites);
  gAuxSpriteTiles = (u8*)f + f->offsetToTiles;
}

// ロード中の AuxSpriteFile から id のアクターを探し、描画に必要な情報を AuxSpriteGfx に詰める
bool32 Video_GetAuxSprite(AuxSpriteGfx* gfx, SpriteID32 id) {
  AuxSpriteFile* f = gAuxSpriteFile;
  u8* tiles;
  u8* metasprites;
  AuxSpriteEntry* a;
  AuxSpritePose* m;
  bool32 found;
  s32 i;

  if (f == NULL) return FALSE;

  tiles = (u8*)f + f->offsetToTiles;
  metasprites = (u8*)f + f->offsetToMetasprites;
  found = FALSE;
  a = f->entries;
  for (i = 0; i < gAuxSpriteFile->actorCount; a++, i++) {
    if (a->id == id) {
      found = TRUE;
      break;
    }
  }
  if (!found) return FALSE;

  m = (AuxSpritePose*)(metasprites + a->spritesOffset);
  gfx->flags = a->flags;
  gfx->shape = 0;
  gfx->unk_2 = 0;
  gfx->pw = a->pw, gfx->ph = a->ph;
  gfx->px = a->px, gfx->py = a->py;
  gfx->subspriteCount = 0;
  gfx->plttID = m->plttID;
  gfx->pltt = &gObjPlttData[gfx->plttID * 16];
  gfx->tiles = tiles + m->tileOffset;
  gfx->metasprites = (AuxSpritePose*)(metasprites + a->spritesOffset);
  return TRUE;
}

void Video_SetAuxSpritePltt(AuxSpriteGfx* gfx, s32 plttID) {
  if (plttID < gObjPlttLen) {
    gfx->plttID = plttID;
    gfx->pltt = &gObjPlttData[gfx->plttID * 16];
  }
}

void FUN_0822b234(AuxSpriteGfx* gfx, u32 val) { gfx->unk_2 = val; }

// OBJ VRAM のタイル確保状態をフレーム先頭に戻す (パーティクル分のタイルは常駐なのでその後ろから再開する)
void Video_ResetObjTileAlloc(void) {
  gAuxSpriteTileCount = 0;
  u16_0300357c = 0;
  gObjTileCursor = 0;
  if (gParticleFile != NULL) {
    gObjTileCursor = gParticleFileTileCount;
  }
}

NAKED u32 FUN_0822b270(unknown* tiledata, s32 param_2) { INCFUNC("asm/func/FUN_0822b270.inc"); }

NAKED void FUN_0822b308(void) { INCFUNC("asm/func/FUN_0822b308.inc"); }

NAKED void FUN_0822b38c(s32 tileIdx) { INCFUNC("asm/func/FUN_0822b38c.inc"); }

// 1 フレーム分の描画状態を空にする。clearOam が 0 以外なら OAM バッファのスプライトも全部隠す
void Video_ResetFrameState(u32 clearOam) {
  s32 i;

  s32_03003a38 = 0;
  for (i = 0; i < 4; i++) {
    u16_ARRAY_03003a30[i] = 0;
  }
  s32_03003a3c = 0;
  s32_03003e40 = 0;
  if (clearOam != 0) {
    OamData* oam = gOAMBuffer;

    for (i = 0; i < 128; i++) {
      *(u32*)oam = ST_OAM_AFFINE_ERASE << 8;
      oam++;
    }
  }
}

NAKED void FUN_0822b470(void) { INCFUNC("asm/func/FUN_0822b470.inc"); }

u16* GetTilemapBuffer(s32 bg) { return (u16*)&gTilemapBuffer[BG_SCREEN_SIZE * bg]; }

void ClearTilemapBuffer(void) { ClearMemory(gTilemapBuffer, sizeof(gTilemapBuffer)); }

void ClearBGTilemapBuffer(s32 bg) {
  if (bg == 0) {
    FUN_0822e8b4();
  }
  ClearMemory(GetTilemapBuffer(bg), BG_SCREEN_SIZE);
}

NAKED void FUN_0822b664(s32 bg) { INCFUNC("asm/func/FUN_0822b664.inc"); }

NAKED void vram_0822b778(void) { INCFUNC("asm/func/vram_0822b778.inc"); }

NAKED void StageBGRegs(void) { INCFUNC("asm/func/StageBGRegs.inc"); }

NAKED void CopyBGTileDataAndTilemapToVram(void) { INCFUNC("asm/func/CopyBGTileDataAndTilemapToVram.inc"); }

// 次の VRAM 転送で BG のタイルデータをどこから何枚どこへ送るかを控えておく
void FUN_0822b9d4(s32 bg, void* src, u32 vramOffset, u32 tileCount) {
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
  v = (*p & ~BGCNT_CHARBASE(3)) | BGCNT_CHARBASE(charbase);
  *p = v;
#else
  INCFUNC("asm/func/SetBGCharBaseDirect.inc");
#endif
}

NAKED void FUN_0822baa4(u32 val1, u32 val2, u32 val3, u16 val4, u32 val5) { INCFUNC("asm/func/FUN_0822baa4.inc"); }

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

NAKED s32 FUN_0822bc44(s32 bg, TileSetFile* f, s32 param_3, s32 param_4, s32 tileidx) { INCFUNC("asm/func/FUN_0822bc44.inc"); }

// BG のタイルマップバッファの (x, y) にエントリ (タイル番号, 反転, パレット) を書く
void FUN_0822bcf4(s32 bg, u32 x8, u32 y8, u32 tileidx, u32 flip, u32 pltt) {
  BgState* s = &gBgStates[bg];

  s->tilemap[(s->unk_18 << 1) * y8 + x8] = tileidx | (flip << 10) | (pltt << 12);
}

// BG のタイルマップバッファの矩形 (x, y, w, h) に、tiles のタイル番号を反転・パレット付きで順に書く
NON_MATCH void FUN_0822bd28(s32 bg, s32 x, s32 y, s32 w, s32 h, u32* tiles, u32 flip, u32 pltt) {
#ifdef NONMATCHING_C
  // 元は pitch と map がスタック、x*2 が sb、bottom が ip に割り当たる (こちらは pitch がレジスタ、bottom がスタック)
  BgState* s = &gBgStates[bg];
  u16* map = s->tilemap;
  s32 pitch = s->unk_18 << 1;
  s32 right = x + w;
  s32 bottom = y + h;
  s32 i, j;

  for (j = y; j < bottom; j++) {
    for (i = x; i < right; i++) {
      map[pitch * j + i] = *tiles++ | (flip << 10) | (pltt << 12);
    }
  }
#else
  INCFUNC("asm/func/FUN_0822bd28.inc");
#endif
}

NAKED void FUN_0822bdb8(s32 bg, s32 x, s32 y, s32 w, s32 h, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_0822bdb8.inc"); }

NAKED void FUN_0822be3c(s32 bg, s32 x, s32 y, u32 param_4, u32 param_5, s32 w, u32 pltt) { INCFUNC("asm/func/FUN_0822be3c.inc"); }

NAKED void* UNUSED FUN_0822bf80(void* dst, u32 val) { INCFUNC("asm/func/FUN_0822bf80.inc"); }

NAKED void Video_SetupBG(s32 bg, u32 param_2, unknown* f, u32 unused, s16 param_5, s16 param_6, u32 prio, u16* tilemap) { INCFUNC("asm/func/Video_SetupBG.inc"); }

NAKED void Video_SetupBGLayout(s32 layout, u32 param_2, unknown* f, u32 param_4, u32 param_5, s32 count, s32* indices) { INCFUNC("asm/func/Video_SetupBGLayout.inc"); }

NAKED void FUN_0822c398(s32 bg, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0822c398.inc"); }

void Video_GenerateBGMap(s32 bg, u32 param_2, u32 param_3, u32 hofs, u32 vofs) { Video_GenerateBGMapCore(bg, param_2, param_3, hofs, vofs, NULL); }

NAKED void Video_GenerateBGMapCore(s32 bg, u32 param_2, u32 param_3, u32 hofs, u32 vofs, unknown* param_6) { INCFUNC("asm/func/Video_GenerateBGMapCore.inc"); }

// TilemapFile が圧縮されてたら展開して返す、圧縮されてなかったらそのまま返す
TilemapHeader* GetTilemapFile(FileID id) {
  u32 fileID = id;

  u8* file = GetFile(DIR_TILE_MAP, fileID);
  if (file == NULL) {
    return NULL;
  }
  if ((file[0] == 'M' && file[1] == 'P') || *(u32*)file == 0x005E8CC5) {  // "MP"
    return (TilemapHeader*)file;
  }
  if (gCachedTilemapFileID != fileID) {
    gCachedTilemapFileID = fileID;
    LZ77UnCompWram(file, gTilemapFileBufferHead);
  }
  return (TilemapHeader*)gTilemapFileBuffer;
}

// ウィンドウ矩形の控えを退避する
void Video_SaveWindowRect(u32 win) {
  if (win == 0) {
    gSavedWIN0H = gWIN0H;
    gSavedWIN0V = gWIN0V;
  } else {
    gSavedWIN1H = gWIN1H;
    gSavedWIN1V = gWIN1V;
  }
}

// 退避しておいたウィンドウ矩形を控えに戻し、WINnH / WINnV にも書き戻す
NON_MATCH void Video_RestoreWindowRect(u32 win) {
#ifdef NONMATCHING_C
  vu16* p;
  u16 h, v;

  if (win == 0) {
    h = gSavedWIN0H;
    gWIN0H = h;
    v = gSavedWIN0V;
    gWIN0V = v;
    p = &REG_WIN0H;
  } else {
    h = gSavedWIN1H;
    gWIN1H = h;
    v = gSavedWIN1V;
    gWIN1V = v;
    p = &REG_WIN1H;
  }
  *p = h;
  p += 2;
  *p = v;
#else
  INCFUNC("asm/func/Video_RestoreWindowRect.inc");
#endif
}

// ウィンドウの矩形を WINnH / WINnV に設定し、同じ値を控えにも残す
void Video_SetWindowRect(s32 win, s32 left, s32 top, s32 right, s32 bottom) {
  if (win == 0) {
    gWIN0H = (left << 8) | right;
    REG_WIN0H = gWIN0H;
    gWIN0V = (top << 8) | bottom;
    REG_WIN0V = gWIN0V;
  } else {
    gWIN1H = (left << 8) | right;
    REG_WIN1H = gWIN1H;
    gWIN1V = (top << 8) | bottom;
    REG_WIN1V = gWIN1V;
  }
}

// ウィンドウ内外の表示対象 (WININ/WINOUT) を設定する
void Video_SetWindowInOut(u32 win0In, u32 win1In, u32 winOut, u32 objWinIn) {
  REG_WININ = (win1In << 8) | win0In;
  REG_WINOUT = (objWinIn << 8) | winOut;
}

void Video_SaveWININOUT(void) {
  gSavedWININ = REG_WININ;
  gSavedWINOUT = REG_WINOUT;
}

void Video_RestoreWININOUT(void) {
  REG_WININ = gSavedWININ;
  REG_WINOUT = gSavedWINOUT;
}

void UNUSED Video_SaveDISPCNT(void) { gSavedDISPCNT = REG_DISPCNT; }

void UNUSED Video_RestoreDISPCNT(void) { REG_DISPCNT = gSavedDISPCNT; }

void Video_SetBLDCNTDirect(u32 effect, u32 target1, u32 target2) { REG_BLDCNT = target1 | (target2 << 8) | (effect << 6); }

void Video_SetBLDALPHADirect(u32 target1, u32 target2) { REG_BLDALPHA = BLDALPHA_BLEND(target1, target2); }

void Video_SetBLDYDirect(u32 bldy) { REG_BLDY = bldy; }

void UNUSED Video_SetBGnOFSDirect(s32 bg, u32 hofs, u32 vofs) {
  vu16* p;

  switch (bg) {
    case 0: {
      p = &REG_BG0HOFS;
      break;
    }
    case 1: {
      p = &REG_BG1HOFS;
      break;
    }
    case 2: {
      p = &REG_BG2HOFS;
      break;
    }
    case 3: {
      p = &REG_BG3HOFS;
      break;
    }
    default: {
      return;
    }
  }
  *p++ = hofs;
  *p = vofs;
}

void UNUSED Video_SetBG23OFSDirect(s32 bg, u32 hofs, u32 vofs) {
  vu16* p;

  switch (bg) {
    case 2: {
      p = &REG_BG2HOFS;
      break;
    }
    case 3: {
      p = &REG_BG3HOFS;
      break;
    }
    case 0:
    case 1:
    default: {
      return;
    }
  }
  *p++ = hofs;
  *p = vofs;
}

void UNUSED Video_SetBgPlttColorDirect(u32 plttIdx, u32 colorIdx, u32 color) { ((rgb555*)BG_PLTT)[plttIdx * 16 + colorIdx] = color; }

void UNUSED Video_SetObjPlttColorDirect(u32 plttIdx, u32 colorIdx, u32 color) { ((rgb555*)OBJ_PLTT)[plttIdx * 16 + colorIdx] = color; }

// gSpriteSizeTable から、OAM の形状・サイズ(0-15)ごとの幅/高さ/タイル数/OAM属性ビットの表を作る
void Video_CreateSpriteLUT(void) {
  s32 i;

  for (i = 0; i < 16; i++) {
    s32 w = (u8)gSpriteSizeTable[i];
    s32 h = gSpriteSizeTable[i] >> 8;
    s32 tw = w >> 3;
    s32 th = h >> 3;
    gOAMWidthTable[i] = w;
    gOAMHeightTable[i] = h;
    gOAMTileWidthTable[i] = tw;
    gOAMTileHeightTable[i] = th;
    gOAMTileCounts[i] = tw * th;
    gOAMShapeSizeAttrTable[i] = ((i & 3) << 14) | ((i & 0xC) << 28);
  }
}
