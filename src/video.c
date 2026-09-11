#include "entity.h"
#include "file.h"
#include "font.h"
#include "global.h"
#include "malloc.h"
#include "particle.h"
#include "sprite.h"
#include "tilemap.h"
#include "tilesets.h"

extern rgb555* gBGPlttBufferPointer;
extern rgb555 gObjectPlttBuffer[256];
extern s32 gObjPlttSlotCount;
extern u16 gObjPlttSlotIDs[16];
extern s32 s32_03004044;
extern s32 s32_03004450;
extern rgb555 gFastBgPlttBuffer[256];
extern rgb555 gSlowBgPlttBuffer[256];

extern u8 u8_02035400[0x800];
extern u8 u8_ARRAY_02036c00[512];
extern u16 u16_030044b8;
extern u8 gTilemapBuffer[BG_SCREEN_SIZE * 4];
extern u16 gObjPlttLen;
extern rgb555* gObjPlttData;
extern ParticleFile* gParticleFile;  // 0x0300358C

extern u8 gOAMHeightTable[16];
extern u8 gOAMWidthTable[16];
extern u8 gOAMTileWidthTable[16];
extern u8 gOAMTileHeightTable[16];
extern u8 gOAMTileCounts[16];
extern u32 gOAMShapeSizeAttrTable[16];

extern u8* gActorSpriteTiles;
extern ActorSubsprite* gActorSpriteSubsprites;
extern ActorSpritesFile* gActorSpritesFile;

extern u32 u32_03003530;
extern u8 gMosaicTargets;
extern u16 gActorSpriteTileCount;
extern u16 u16_0300357c;
extern u32 gHBlankEffectBG;
extern void* gHBlankEffectTable;
extern s32 gHBlankEffectKind;
extern vu16* gHBlankEffectReg;
extern u16* gHBlankEffectBuffer;
extern u16 u16_03003510;
extern u16 u16_03003514;
extern BgState gBgStates[4];
extern s16 gObjTileCursor;
extern s16 gParticleFileTileCount;
extern u16 gMosaicDirty;
extern u8 gObjMosaicEnabled;
extern u16 gMosaicSize;
extern Particle* PTR_ARRAY_03003570[2];
extern q_SpriteNode44* PTR_ARRAY_03003560[2];
extern SpriteState* PTR_ARRAY_03003568[2];

const u8 u8_ARRAY_085b0110[32] = {0};

#define SPRITE_SIZE(widthPixel, heightPixel) ((heightPixel << 8) | widthPixel)

// clang-format off
// idx: (OAM1.14-15 << 2) | (OAM0.14-15), ie. ((sizeidx << 2) | shape)
const u16 gSpriteSizeTable[16] = {
// OAM0.14-15:  Square(0)             Horizontal(1)         Vertical(2)           Prohibited(3)
                SPRITE_SIZE( 8,  8),  SPRITE_SIZE(16,  8),  SPRITE_SIZE( 8, 16),  0x0,
                SPRITE_SIZE(16, 16),  SPRITE_SIZE(32,  8),  SPRITE_SIZE( 8, 32),  0x0,
                SPRITE_SIZE(32, 32),  SPRITE_SIZE(32, 16),  SPRITE_SIZE(16, 32),  0x0,
                SPRITE_SIZE(64, 64),  SPRITE_SIZE(64, 32),  SPRITE_SIZE(32, 64),  0x0,
}; // 0x085b0130
// clang-format on

#undef SPRITE_SIZE

void FUN_0822a4fc(q_SpriteNode44* p, ActorSpriteState* s);
void FUN_0822e8b4(void);
void FUN_0822d014(rgb555* pltt, s32 val);
void FUN_0822dad4(Particle* p, s32 val1, s32 val2);
void FUN_0822dafc(Particle* p, ParticleGroup* g, u32 val);

// 他のEntityにある Create, Init, Destroy 関数 はなく Update (VideoManager_Update) のみ
typedef Entity VideoManager;  // Entity と同じサイズ(直後に gEntityKind13 が来るので確定)
NAKED s32 VideoManager_Update(VideoManager* p) { INCFUNC("asm/func/VideoManager_Update.inc"); }

// 他のEntityにある Create, Init, Destroy 関数 はなく Update (EntityKind13_Update) のみ
typedef Entity EntityKind13;  // Entity と同じサイズと思われるが、確定ではない
NAKED s32 EntityKind13_Update(EntityKind13* p) { INCFUNC("asm/func/EntityKind13_Update.inc"); }

NAKED void FUN_0822a2a8(void) { INCFUNC("asm/func/FUN_0822a2a8.inc"); }

void UNUSED FUN_0822a2f8(q_SpriteNode44* p) { PTR_ARRAY_03003560[u32_03003530] = p; }

void UNUSED FUN_0822a310(Particle* p) { PTR_ARRAY_03003570[u32_03003530] = p; }

void UNUSED FUN_0822a328(SpriteState* p) { PTR_ARRAY_03003568[u32_03003530] = p; }

// 描画リストの先頭にノードを繋ぐ
s32 FUN_0822a340(q_SpriteNode44* p, s32 idx) {
  q_SpriteNode44* head;

  p->q_listIdx = idx;
  p->q_active = 1;
  p->prev = NULL;
  head = PTR_ARRAY_03003560[idx];
  p->next = head;
  if (head != NULL) {
    head->prev = p;
  }
  PTR_ARRAY_03003560[idx] = p;
  return 0;
}

// 描画リストからノードを外す
void FUN_0822a36c(q_SpriteNode44* p, s32 idx) {
  q_SpriteNode44* prev;
  q_SpriteNode44* next;

  prev = p->prev;
  next = p->next;
  p->q_active = 0;
  if (prev != NULL) {
    prev->next = next;
  } else {
    PTR_ARRAY_03003560[idx] = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
}

// 描画リストの先頭に Particle を繋ぐ
s32 FUN_0822a398(Particle* p, s32 idx) {
  Particle* head;

  p->listIdx = idx;
  p->active = 1;
  p->prev = NULL;
  head = PTR_ARRAY_03003570[idx];
  p->next = head;
  if (head != NULL) {
    head->prev = p;
  }
  PTR_ARRAY_03003570[idx] = p;
  return 0;
}

// 描画リストから Particle を外す
void FUN_0822a3c4(Particle* p, s32 idx) {
  Particle* prev;
  Particle* next;

  prev = p->prev;
  next = p->next;
  p->active = 0;
  if (prev != NULL) {
    prev->next = next;
  } else {
    PTR_ARRAY_03003570[idx] = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
}

// 描画リストの先頭に SpriteState を繋ぐ
s32 FUN_0822a3f0(SpriteState* p, s32 idx) {
  SpriteState* head;

  p->listIdx = idx;
  p->active = 1;
  p->prev = NULL;
  head = PTR_ARRAY_03003568[idx];
  p->next = head;
  if (head != NULL) {
    head->prev = p;
  }
  PTR_ARRAY_03003568[idx] = p;
  return 0;
}

// 描画リストから SpriteState を外す
void FUN_0822a41c(SpriteState* p, s32 idx) {
  SpriteState* prev;
  SpriteState* next;

  prev = p->prev;
  next = p->next;
  p->active = 0;
  if (prev != NULL) {
    prev->next = next;
  } else {
    PTR_ARRAY_03003568[idx] = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
}

NAKED void FUN_0822a448(s32 val, Procedure* fn1, Procedure* fn2, Procedure* fn3) { INCFUNC("asm/func/FUN_0822a448.inc"); }

// ノードを初期化して描画リストに繋ぐ
void FUN_0822a470(q_SpriteNode44* p, ActorSpriteState* s, SpriteFlags flags) {
  u32 mask;
  s32 idx;

  if (p->q_active == 0) {
    p->flags = flags;
    p->unk_05 = 1;
    p->q_oamAttr = 0;
    p->q_scaleX = 0x40;
    p->q_scaleY = 0x40;
    p->q_rotation = 0;
    p->priority = 2;
    FUN_0822a4fc(p, s);
    mask = SPRFLAG_UNK_7;
    idx = (u32)(0 - (flags & mask)) >> 31;
    p->prev = NULL;
    p->next = NULL;
    FUN_0822a340(p, idx);
  }
}

// ノードを初期化する (FUN_0822a470 と違い描画リストには繋がない)
void FUN_0822a4b0(q_SpriteNode44* p, ActorSpriteState* s, SpriteFlags flags) {
  if (p->q_active == 0) {
    p->flags = flags;
    p->unk_05 = 1;
    p->q_oamAttr = 0;
    p->q_scaleX = 0x40;
    p->q_scaleY = 0x40;
    p->q_rotation = 0;
    p->priority = 2;
    FUN_0822a4fc(p, s);
    p->prev = NULL;
    p->next = NULL;
  }
}

// 描画リストに繋がれていればノードを外す
void FUN_0822a4e0(q_SpriteNode44* p) {
  if (p->q_active != 0) {
    FUN_0822a36c(p, p->q_listIdx);
  }
}

void nop_0822a4f8(void* _, s32 unused1, s32 unused2) {}

// ノードに ActorSpriteState を割り当て、OAM属性のシェイプ/サイズを作り直す
void FUN_0822a4fc(q_SpriteNode44* p, ActorSpriteState* s) {
  u32 attr;

  if (s != NULL) {
    p->q_metaspriteIdx = 0;
    p->unk_12 = 0;
    p->q_plttOffset = 0;
    p->q_spriteWidth = gOAMWidthTable[s->unk_1];
    p->q_spriteHeight = gOAMHeightTable[s->unk_1];
    p->q_offsetX = 0;
    p->q_offsetY = 0;
    attr = (p->q_oamAttr & 0x1C00) | (((s->unk_1 & 3) << 14) | ((s->unk_1 & 0xC) << 28));
    p->q_oamAttr = attr;
    if (s->unk_0 & 0x10) {
      p->q_oamAttr = attr | 0x2000;
    }
    p->q_sprite = s;
  }
}

void FUN_0822a568(q_SpriteNode44* p, ActorSpriteState* s) {
  if (s != NULL) {
    p->q_sprite = s;
  }
}

NAKED void DrawSprite_0822a574(q_SpriteNode44* p, s32 x, s32 y, s32 z) { INCFUNC("asm/func/DrawSprite_0822a574.inc"); }

NAKED void FUN_0822aaac(void) { INCFUNC("asm/func/FUN_0822aaac.inc"); }

NAKED void FUN_0822ac90(void) { INCFUNC("asm/func/FUN_0822ac90.inc"); }

NAKED void FUN_0822adac(void) { INCFUNC("asm/func/FUN_0822adac.inc"); }

NAKED void FUN_0822af38(void) { INCFUNC("asm/func/FUN_0822af38.inc"); }

void nop_0822b09c(void) {}

void InitPltt(void) {
  ObjPlttFile* f = GetFile(DIR_OBJPLTT, 0xC5E9);
  gObjPlttLen = f->length;
  gObjPlttData = f->body;
  FUN_0822d014(gObjPlttData, 8);
}

NAKED void LoadParticleFile(ParticleFile* f) { INCFUNC("asm/func/LoadParticleFile.inc"); }

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

void LoadActorSpritesFile(ActorSpritesFile* f) {
  gActorSpritesFile = f;
  gActorSpriteSubsprites = (ActorSubsprite*)((u8*)f + f->offsetToSubsprites);
  gActorSpriteTiles = (u8*)f + f->offsetToTiles;
}

// ロード中の ActorSpritesFile から id のアクターを探し、描画に必要な情報を ActorSpriteState に詰める
bool32 Video_GetActorSprite(ActorSpriteState* p, ActorSpriteID32 id) {
  ActorSpritesFile* f = gActorSpritesFile;
  u8* tiles;
  u8* metasprites;
  ActorSpritesActor* a;
  ActorMetasprite* m;
  bool32 found;
  s32 i;

  if (f == NULL) return FALSE;

  tiles = (u8*)f + f->offsetToTiles;
  metasprites = (u8*)f + f->offsetToMetasprites;
  found = FALSE;
  a = f->actors;
  for (i = 0; i < gActorSpritesFile->actorCount; a++, i++) {
    if (a->id == id) {
      found = TRUE;
      break;
    }
  }
  if (!found) return FALSE;

  m = (ActorMetasprite*)(metasprites + a->spritesOffset);
  p->unk_0 = a->unk_02;
  p->unk_1 = 0;
  p->unk_2 = 0;
  p->pw = a->pw;
  p->ph = a->ph;
  p->px = a->px;
  p->py = a->py;
  p->subspriteCount = 0;
  p->plttID = m->plttID;
  p->pltt = &gObjPlttData[p->plttID * 16];
  p->tiles = tiles + m->tileOffset;
  p->metasprites = (ActorMetasprite*)(metasprites + a->spritesOffset);
  return TRUE;
}

void Video_SetActorSpritePltt(ActorSpriteState* p, s32 plttID) {
  if (plttID < gObjPlttLen) {
    p->plttID = plttID;
    p->pltt = &gObjPlttData[p->plttID * 16];
  }
}

void FUN_0822b234(ActorSpriteState* p, u32 val) { p->unk_2 = val; }

// OBJ VRAM のタイル確保状態をフレーム先頭に戻す (パーティクル分のタイルは常駐なのでその後ろから再開する)
void Video_ResetObjTileAlloc(void) {
  gActorSpriteTileCount = 0;
  u16_0300357c = 0;
  gObjTileCursor = 0;
  if (gParticleFile != NULL) {
    gObjTileCursor = gParticleFileTileCount;
  }
}

NAKED u32 FUN_0822b270(unknown* p, unknown* q) { INCFUNC("asm/func/FUN_0822b270.inc"); }

NAKED void FUN_0822b308(void) { INCFUNC("asm/func/FUN_0822b308.inc"); }

NAKED void FUN_0822b38c(s32 tileIdx) { INCFUNC("asm/func/FUN_0822b38c.inc"); }

NAKED void FUN_0822b41c(u32 val) { INCFUNC("asm/func/FUN_0822b41c.inc"); }

NAKED void FUN_0822b470(void) { INCFUNC("asm/func/FUN_0822b470.inc"); }

u8* GetTilemapBuffer(s32 bg) { return &gTilemapBuffer[BG_SCREEN_SIZE * bg]; }

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

NAKED void FUN_0822b9d4(s32 bg, void* base, u32 tilecount, u32 offset) { INCFUNC("asm/func/FUN_0822b9d4.inc"); }

NAKED void SetBGPrioDirect(s32 bg, u32 prio) { INCFUNC("asm/func/SetBGPrioDirect.inc"); }

NAKED void SetBGCharBaseDirect(s32 bg, u32 charbase) { INCFUNC("asm/func/SetBGCharBaseDirect.inc"); }

NAKED void FUN_0822baa4(u32 val1, u32 val2, u32 val3, u16 val4, u32 val5) { INCFUNC("asm/func/FUN_0822baa4.inc"); }

NAKED unknown* FUN_0822bc18(unknown* p, u16 val) { INCFUNC("asm/func/FUN_0822bc18.inc"); }

NAKED s32 FUN_0822bc44(s32 bg, TileSetFile* f, s32 param_3, s32 param_4, s32 tileidx) { INCFUNC("asm/func/FUN_0822bc44.inc"); }

// BG のタイルマップバッファの (x, y) にエントリ (タイル番号, 反転, パレット) を書く
void FUN_0822bcf4(s32 bg, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
  BgState* s = &gBgStates[bg];

  s->q_tilemap[(s->unk_18 << 1) * param_3 + param_2] = param_4 | (param_5 << 10) | (param_6 << 12);
}

// BG のタイルマップバッファの矩形 (x, y, w, h) に、tiles のタイル番号を反転・パレット付きで順に書く
NON_MATCH void FUN_0822bd28(s32 bg, s32 x, s32 y, s32 w, s32 h, u32* tiles, u32 flip, u32 pltt) {
#ifdef NONMATCHING_C
  // 元は pitch と map がスタック、x*2 が sb、bottom が ip に割り当たる (こちらは pitch がレジスタ、bottom がスタック)
  BgState* s = &gBgStates[bg];
  u16* map = s->q_tilemap;
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

INCASM("asm/video.inc");

NAKED void FUN_0822c398(s32 bg, u32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0822c398.inc"); }

NAKED void Video_GenerateBGMap(s32 bg, u32 param_2, u32 param_3, u32 hofs, u32 vofs) { INCFUNC("asm/func/Video_GenerateBGMap.inc"); }

NAKED void Video_GenerateBGMapCore(s32 bg, u32 param_2, u32 param_3, u32 hofs, u32 vofs, unknown* param_6) { INCFUNC("asm/func/Video_GenerateBGMapCore.inc"); }

NAKED TilemapHeader* GetTilemapFile(FileID id) { INCFUNC("asm/func/GetTilemapFile.inc"); }

NAKED void FUN_0822cd24(u32 param_1) { INCFUNC("asm/func/FUN_0822cd24.inc"); }

NAKED void FUN_0822cd6c(u32 param_1) { INCFUNC("asm/func/FUN_0822cd6c.inc"); }

NAKED void FUN_0822cdcc(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5) { INCFUNC("asm/func/FUN_0822cdcc.inc"); }

// ウィンドウ内外の表示対象 (WININ/WINOUT) を設定する
void Video_SetWindowInOut(u32 win0In, u32 win1In, u32 winOut, u32 objWinIn) {
  REG_WININ = (win1In << 8) | win0In;
  REG_WINOUT = (objWinIn << 8) | winOut;
}

NAKED void FUN_0822ce50(void) { INCFUNC("asm/func/FUN_0822ce50.inc"); }

NAKED void FUN_0822ce74(void) { INCFUNC("asm/func/FUN_0822ce74.inc"); }

NAKED void FUN_0822ce94(void) { INCFUNC("asm/func/FUN_0822ce94.inc"); }

NAKED void FUN_0822cea4(void) { INCFUNC("asm/func/FUN_0822cea4.inc"); }

NAKED void Video_SetBLDCNTDirect(u32 param_1, u32 param_2, u32 param_3) { INCFUNC("asm/func/Video_SetBLDCNTDirect.inc"); }

void Video_SetBLDALPHADirect(u32 target1, u32 target2) { REG_BLDALPHA = BLDALPHA_BLEND(target1, target2); }

void Video_SetBLDYDirect(u32 bldy) { REG_BLDY = bldy; }

NAKED void UNUSED FUN_0822cee4(s32 bg, u32 x, u32 y) { INCFUNC("asm/func/FUN_0822cee4.inc"); }

NAKED void UNUSED FUN_0822cf28(s32 bg, u32 x, u32 y) { INCFUNC("asm/func/FUN_0822cf28.inc"); }

NAKED void UNUSED FUN_0822cf50(u32 plttIdx, u32 colorIdx, u32 color) { INCFUNC("asm/func/FUN_0822cf50.inc"); }

NAKED void UNUSED FUN_0822cf60(u32 plttIdx, u32 colorIdx, u32 color) { INCFUNC("asm/func/FUN_0822cf60.inc"); }

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

rgb555* FUN_0822d00c(void) { return gSlowBgPlttBuffer; }

NAKED void FUN_0822d014(rgb555* pltt, s32 val) { INCFUNC("asm/func/FUN_0822d014.inc"); }

// FUN_0822d12c 用の OBJ パレットスロット(2 個)を空にする
void FUN_0822d0e4(void) {
  s32 i;

  gObjPlttSlotCount = 0;
  for (i = 0; i < 2; i++) {
    gObjPlttSlotIDs[i] |= 0xFFFF;
  }
}

void FUN_0822d114(void) {
  s32_03004044 = s32_03004450 + 2;
  s32_03004450 = 0;
}

// パレット ID に OBJ パレットスロットを割り当てて番号を返す (登録済みならそのスロット、空きがなければ 0)
s32 FUN_0822d12c(u32 plttID, rgb555* pltt) {
  s32 i;

  for (i = 0; i < gObjPlttSlotCount; i++) {
    if (gObjPlttSlotIDs[i] == plttID) return i;
  }
  if (gObjPlttSlotCount > 1) return 0;

  gObjPlttSlotIDs[gObjPlttSlotCount] = plttID;
  CpuFastCopy(pltt, &gObjectPlttBuffer[gObjPlttSlotCount * 16], 16 * sizeof(rgb555));
  return gObjPlttSlotCount++;
}

// FUN_0822d12c の 16 スロット版
s32 FUN_0822d190(u32 plttID, rgb555* pltt) {
  s32 i;

  for (i = 0; i < s32_03004044; i++) {
    if (gObjPlttSlotIDs[i] == plttID) return i;
  }
  if (s32_03004044 > 15) return 0;

  gObjPlttSlotIDs[s32_03004044] = plttID;
  CpuFastCopy(pltt, &gObjectPlttBuffer[s32_03004044 * 16], 16 * sizeof(rgb555));
  return s32_03004044++;
}

NAKED void CommitPalette(void) { INCFUNC("asm/func/CommitPalette.inc"); }

void FUN_0822d22c(rgb555* src) { DmaCopy32(3, src, &gFastBgPlttBuffer[208], 96); }

NAKED void FUN_0822d248(void) { INCFUNC("asm/func/FUN_0822d248.inc"); }

NAKED void FUN_0822d630(void) { INCFUNC("asm/func/FUN_0822d630.inc"); }

NAKED void FUN_0822d828(void) { INCFUNC("asm/func/FUN_0822d828.inc"); }

NAKED void FUN_0822d8e8(void) { INCFUNC("asm/func/FUN_0822d8e8.inc"); }

NAKED void FUN_0822d98c(void) { INCFUNC("asm/func/FUN_0822d98c.inc"); }

// Particle を ParticleGroup の先頭フレームで初期化し、描画リストに繋ぐ
void FUN_0822d9f0(Particle* p, ParticleGroup* g, u32 flags) {
  u32 mask;
  s32 idx;

  if (p->active == 0) {
    p->flags = flags;
    p->oamAttr01 = 0;
    p->priority = 2;
    p->q_zOffset = 0;
    p->q_rotation = 0;
    p->q_scaleX = 0x40;
    p->q_scaleY = 0x40;
    FUN_0822dad4(p, 0, 0);
    FUN_0822dafc(p, g, 0);
    p->plttSlot = FUN_0822d12c(g->plttID, &gObjPlttData[g->plttID * 16]);
    mask = 0x80;
    idx = (u32)(0 - (flags & mask)) >> 31;
    p->prev = NULL;
    p->next = NULL;
    FUN_0822a398(p, idx);
  }
}

// 描画リストに繋がれていなければ、flags の bit7 で選んだリストに Particle を繋ぐ
void FUN_0822da50(Particle* p, u32 flags) {
  u32 mask;

  if (p->active == 0) {
    mask = 0x80;
    FUN_0822a398(p, (flags & mask) != 0);
  }
}

// Particle を ParticleGroup の先頭フレームで初期化する (描画リストには繋がない)
void FUN_0822da70(Particle* p, ParticleGroup* g, u32 flags) {
  if (p->active == 0) {
    p->flags = flags;
    p->oamAttr01 = 0;
    p->priority = 1;
    p->q_zOffset = 0;
    FUN_0822dad4(p, -8, -8);
    FUN_0822dafc(p, g, 0);
    p->plttSlot = FUN_0822d12c(g->plttID, &gObjPlttData[g->plttID * 16]);
    p->prev = NULL;
    p->next = NULL;
  }
}

// 描画リストに繋がれていれば Particle を外す
void FUN_0822dabc(Particle* p) {
  if (p->active != 0) {
    FUN_0822a3c4(p, p->listIdx);
  }
}

void FUN_0822dad4(Particle* p, s32 val1, s32 val2) {
  p->q_offsetX = val1;
  p->q_offsetY = val2;
}

// パーティクルに OBJ パレット plttID を割り当て、確保されたパレットスロット番号を記録する
void FUN_0822dadc(Particle* p, s32 plttID) { p->plttSlot = FUN_0822d12c(plttID, &gObjPlttData[plttID * 16]); }

// ParticleGroup の形状からパーティクルのサイズ・OAM 属性・タイル番号(val 番目のフレーム)を設定する
void FUN_0822dafc(Particle* p, ParticleGroup* g, u32 val) {
  p->spriteWidth = gSpriteSizeTable[g->shape];
  p->spriteHeight = gSpriteSizeTable[g->shape] >> 8;
  p->oamAttr01 = ((g->shape & 3) << 14) | ((g->shape & 0xC) << 28);
  if (g->flags & PGFLAG_BPP8) {
    p->oamAttr01 |= 0x2000;  // OAM0.13: 8bpp
  }
  p->tileNum = val * ((p->spriteWidth >> 3) * (p->spriteHeight >> 3)) + g->tile;
}

NAKED void FUN_0822db5c(void) { INCFUNC("asm/func/FUN_0822db5c.inc"); }

NAKED void FUN_0822de64(void) { INCFUNC("asm/func/FUN_0822de64.inc"); }

NAKED void FUN_0822e110(void) { INCFUNC("asm/func/FUN_0822e110.inc"); }

NAKED void FUN_0822e424(void) { INCFUNC("asm/func/FUN_0822e424.inc"); }

void nop_0822e738(void) {}

// --------------------------------------------

// 多分、バッファのフォントのタイルデータをVRAMに転送する関数
NAKED void FUN_0822e73c(void) { INCFUNC("asm/func/FUN_0822e73c.inc"); }

NAKED void FUN_0822e794(s32 val, u8* src) { INCFUNC("asm/func/FUN_0822e794.inc"); }

void FUN_0822e7cc(void) { gFontInfo = NULL; }

FontInfo* FUN_0822e7d8(void) { return gFontInfo; }

NAKED s32 FUN_0822e7e4(void) { INCFUNC("asm/func/FUN_0822e7e4.inc"); }

u32 Video_GetHankakuCharCount(void) {
  if (gFontInfo == NULL) {
    return 0;
  }
  return gFontInfo->narrowCharCount;
}

u32 Video_GetZenkakuCharCount(void) {
  if (gFontInfo == NULL) {
    return 0;
  }
  return gFontInfo->wideCharCount;
}

u8* Video_GetHankakuTiles(void) {
  if (gFontInfo == NULL) {
    return NULL;
  }
  return gFontInfo->narrowChars;
}

u8* Video_GetZenkakuTiles(void) {
  if (gFontInfo == NULL) {
    return NULL;
  }
  return gFontInfo->wideChars;
}

void FUN_0822e8b4(void) { ClearMemory(u8_02035400, sizeof(u8_02035400)); }

void* FUN_0822e8c8(void) { return u8_02035400; }

// u8_02035400 の先頭256エントリ(u32)から、キーが一致する使用中のもの(上位8bitが非0)を探す
s32 FUN_0822e8d0(u32 val1, u32 val2, u32 val3, u32 val4) {
  u32* p;
  s32 i;
  u32 key = (val1 | (val2 << 16) | (val3 << 18) | (val4 << 20)) & 0x3FFFFF;

  p = FUN_0822e8c8();
  for (i = 0; i <= 0xFF; p++, i++) {
    if (((*p & 0x3FFFFF) == key) && (*p & (0xFF << 22))) {
      return i;
    }
  }
  return -1;
}

NON_MATCH s32 FUN_0822e920(void* tiledata, u32 val2, u32 val3, u32 val4, u32 val5) {
#ifdef NONMATCHING_C
  u32 buf[8];
  u32 hi, lo;
  s32 i;
  u32* p = FUN_0822e8c8();
  s32 idx = FUN_0822e8d0(val2, val3, val4, val5);

  if (idx >= 0) {
    u32 count = p[idx] & (0xFF << 22);
    p[idx] = (p[idx] & ~(0xFF << 22)) | (count + (1 << 22));
    return idx;
  }

  for (i = 0; i <= 0xFF; p++, i++) {
    if (!(*p & (0xFF << 22))) break;
  }
  if (i == 0x100) return -1;

  idx = i;
  *p = val2 | (val3 << 16) | (val4 << 18) | (val5 << 20) | (1 << 22);
  hi = (val4 * 0x01010101) << 6;
  lo = (val4 * 0x01010101) << 2;
  for (i = 0; i < 8; i++) {
    u32 w = ((u32*)tiledata)[i];
    buf[i] = (((w & 0xF0F0F0F0) | hi) & 0xF0F0F0F0) | (((w & 0x0F0F0F0F) | lo) & 0x0F0F0F0F);
  }
  FUN_0822e794(idx, (u8*)buf);
  return idx;
#else
  INCFUNC("asm/func/FUN_0822e920.inc");
#endif
}

// 参照カウント(上位8bit)を1減らし、0になったらエントリごと解放する
bool32 FUN_0822ea10(u32 tileidx) {
  u32* base = FUN_0822e8c8();

  tileidx -= 0x100;
  if (tileidx <= 0xFF) {
    u32 entry = base[tileidx];
    s32 count = (entry & (0xFF << 22)) >> 22;
    if (count > 0) {
      count--;
      if (count <= 0) {
        base[tileidx] = 0;
      } else {
        base[tileidx] = (entry & ~(0xFF << 22)) | (count << 22);
      }
      return TRUE;
    }
  }
  return FALSE;
}

// タイルマップ上の矩形 (x8, y8, w8, h8) を走査し、各タイルの下位10bit(タイル番号)を FUN_0822ea10 に渡して参照カウントを解放し、成功したら 0xF001 で塗り潰す
NON_MATCH void FUN_0822ea60(u32 x8, u32 y8, u32 w8, u32 h8) {
#ifdef NONMATCHING_C
  u16* map = (u16*)GetTilemapBuffer(0);
  u32 x;
  u32 right = x8 + w8;
  u32 bottom = y8 + h8;

  for (; y8 < bottom; y8++) {
    for (x = x8; x < right; x++) {
      if (FUN_0822ea10(map[y8 * 32 + x] & 0x3FF)) {
        map[y8 * 32 + x] = 0xF001;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_0822ea60.inc");
#endif
}

NAKED void FUN_0822eadc(u32 x8, u32 y8, u32 w8, u32 h8) { INCFUNC("asm/func/FUN_0822eadc.inc"); }

NAKED void Video_DrawCharNarrow(u16 charcode, s32 x8, s32 y8, unknown* param_4) { INCFUNC("asm/func/Video_DrawCharNarrow.inc"); }

NAKED void Video_DrawCharWide(u16 charcode, s32 x8, s32 y8, unknown* param_4) { INCFUNC("asm/func/Video_DrawCharWide.inc"); }

void nop_0822ec58(void) {}

// 多分、フォントのタイルデータをクリアする関数
void FUN_0822ec5c(void) { CpuFastFill(0x44444444, (void*)(VRAM + 0xA000), 0x2000); }

// --------------------------------------------

NAKED void FUN_0822ec80(s32 val) { INCFUNC("asm/func/FUN_0822ec80.inc"); }

// モザイクの設定を初期化する (I/O には反映しない)
void Video_ResetMosaic(void) {
  gMosaicDirty = 0;
  gMosaicSize = 0;
  gObjMosaicEnabled = 0;
  gMosaicTargets = 0;
}

void Video_SetMosaic(s32 size, s32 objEnabled, s32 targets) {
  gMosaicDirty = 1;
  gMosaicSize = size;
  gObjMosaicEnabled = objEnabled;
  gMosaicTargets = targets;
}

// 次の Video_ApplyMosaic でモザイクを解除させる
void Video_ClearMosaic(void) {
  gMosaicDirty = 1;
  gMosaicSize = 0;
  gObjMosaicEnabled = 0;
  gMosaicTargets = 0;
}

// 要求されていればモザイクの設定を I/O レジスタに反映する
void Video_ApplyMosaic(void) {
  if (gMosaicDirty != 0) {
    if (gMosaicTargets & (1 << 0)) {
      REG_BG0CNT |= BGCNT_MOSAIC;
    } else {
      REG_BG0CNT &= ~BGCNT_MOSAIC;
    }
    if (gMosaicTargets & (1 << 1)) {
      REG_BG1CNT |= BGCNT_MOSAIC;
    } else {
      REG_BG1CNT &= ~BGCNT_MOSAIC;
    }
    if (gMosaicTargets & (1 << 2)) {
      REG_BG2CNT |= BGCNT_MOSAIC;
    } else {
      REG_BG2CNT &= ~BGCNT_MOSAIC;
    }
    if (gMosaicTargets & (1 << 3)) {
      REG_BG3CNT |= BGCNT_MOSAIC;
    } else {
      REG_BG3CNT &= ~BGCNT_MOSAIC;
    }
    if ((gMosaicTargets & (1 << 4)) == 0) {
      REG_MOSAIC = (u8)gMosaicSize;
    } else {
      REG_MOSAIC = gMosaicSize;
    }
    gMosaicDirty = 0;
  }
}

void Video_ResetHBlankEffect(void) {
  gHBlankEffectBG = 2;
  gHBlankEffectKind = 0;
  gHBlankEffectTable = NULL;
}

// スキャンライン毎に I/O レジスタへ転送する値のテーブルを設定する
void Video_SetHBlankEffect(s32 bg, s32 kind, unknown* table) {
  gHBlankEffectBG = bg;
  gHBlankEffectKind = kind;
  gHBlankEffectTable = table;
}

void* FUN_0822ee74(void) { return u8_ARRAY_02036c00; }

vu16* Video_GetBGnHOFS(s32 bg) {
  switch (bg) {
    case 0:
      return &REG_BG0HOFS;
    case 1:
      return &REG_BG1HOFS;
    case 2:
      return &REG_BG2HOFS;
    default:
      return &REG_BG3HOFS;
  }
}

vu16* Video_GetBGnVOFS(s32 bg) {
  switch (bg) {
    case 0:
      return &REG_BG0VOFS;
    case 1:
      return &REG_BG1VOFS;
    case 2:
      return &REG_BG2VOFS;
    default:
      return &REG_BG3VOFS;
  }
}

// 設定された HBlank エフェクトのテーブルから、ライン毎に I/O レジスタへ書く値のバッファを作る
void FUN_0822eef4(void) {
  u16* buf;
  vu16* reg;
  s32 i;
  u32 base;

  if (gHBlankEffectTable == NULL) return;

  buf = FUN_0822ee74();
  reg = &REG_BG3HOFS;
  switch (gHBlankEffectKind) {
    case 0: {
      reg = Video_GetBGnHOFS(gHBlankEffectBG);
      base = gBgStates[gHBlankEffectBG].hofs & 0x1FF;
      for (i = 0; i < DISPLAY_HEIGHT; i++) {
        buf[i] = (((u16*)gHBlankEffectTable)[i] + base) & 0x1FF;
      }
      break;
    }
    case 1: {
      reg = Video_GetBGnVOFS(gHBlankEffectBG);
      base = gBgStates[gHBlankEffectBG].vofs & 0x1FF;
      for (i = 0; i < DISPLAY_HEIGHT; i++) {
        buf[i] = (((u16*)gHBlankEffectTable)[i] + base) & 0x1FF;
      }
      break;
    }
    case 2: {
      reg = &REG_MOSAIC;
      for (i = 0; i < DISPLAY_HEIGHT; i++) {
        buf[i] = ((u16*)gHBlankEffectTable)[i];
      }
      break;
    }
    case 3: {
      REG_BLDALPHA = BLDALPHA_BLEND(16, 8);
      REG_BLDCNT = 0x0EDE;
      reg = &REG_BLDY;
      for (i = 0; i < DISPLAY_HEIGHT; i++) {
        buf[i] = ((u16*)gHBlankEffectTable)[i] & 0x1F;
      }
      break;
    }
  }
  gHBlankEffectBuffer = buf;
  gHBlankEffectReg = reg;
  u16_03003510 = 1;
  u16_03003514 = 1;
  gHBlankEffectTable = NULL;
}

// HBlank エフェクト用のバッファを空にし、エフェクト種類に応じた転送先レジスタを設定する
void FUN_0822f0d8(void) {
  u16* buf = FUN_0822ee74();
  vu16* reg;

  ClearMemory(buf, DISPLAY_HEIGHT * sizeof(u16));
  reg = &REG_BG3HOFS;
  switch (gHBlankEffectKind) {
    case 0: {
      reg = Video_GetBGnHOFS(gHBlankEffectBG);
      break;
    }
    case 1: {
      reg = Video_GetBGnVOFS(gHBlankEffectBG);
      break;
    }
    case 2: {
      Video_ClearMosaic();
      reg = &REG_MOSAIC;
      break;
    }
    case 3: {
      reg = &REG_BLDY;
      break;
    }
  }
  gHBlankEffectBuffer = buf;
  gHBlankEffectReg = reg;
  u16_03003510 = 1;
  u16_03003514 = 0;
  gHBlankEffectTable = NULL;
}

void FUN_0822f178(s32 idx, u32 evb, u32 eva) {
  static const u16 u16_ARRAY_085b0150[4] = {
      (BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD) | BLDCNT_TGT1_BG0,
      (BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD) | BLDCNT_TGT1_BG1,
      (BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD) | BLDCNT_TGT1_BG2,
      (BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD) | BLDCNT_TGT1_BG3,
  };  // 0x085b0150
  REG_BLDCNT = u16_ARRAY_085b0150[idx] | BLDCNT_EFFECT_BLEND;
  REG_BLDALPHA = BLDALPHA_BLEND(eva, evb);
  REG_BLDY = 0;
}

s32 FUN_0822f1b0(void) {
  u16_030044b8 = 0;
  return 0;
}

void FUN_0822f1c0(SpriteState* p) {
  if (p->active != 0) {
    FUN_0822a41c(p, p->listIdx);
  }
}

// 描画リストに繋がれている SpriteState を全て外す
void FUN_0822f1d8(void) {
  SpriteState* p;
  SpriteState* next;

  p = PTR_ARRAY_03003568[u32_03003530];
  while (p != NULL) {
    next = p->next;
    FUN_0822f1c0(p);
    p = next;
  }
}
