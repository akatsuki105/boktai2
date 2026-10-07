#include "video.h"

#include "camera.h"
#include "entity.h"
#include "file.h"
#include "font.h"
#include "global.h"
#include "particle.h"
#include "sprite.h"

// フレームの描画/反映の入口, 描画リスト, AuxSprite, スプライト資源の読み込み, OBJ タイルの確保と OAM の組み立て
// BG (タイルマップ) 側は src/bg.c, 表示レジスタの退避/復帰と直書きは src/video_reg.c にある

extern u32 gFrameCounter;
extern OamData gOAMBuffer[128];
extern u16 gOAMPrioCounts[4];
extern s32 gOAMCount;
extern s32 gStagedOAMCount;

extern bool32 gDispcntLocked;
extern bool32 gVBlankDone;
extern u16 gStagedDISPCNT;
extern s32 s32_0300446c;
extern u16 gObjPlttLen;

extern u8 gOAMHeightTable[16];
extern u8 gOAMWidthTable[16];

extern u16 gMainSpriteTileCount;
extern u16 gObjTileRequestCount;
extern s16 gObjTileCursor;
extern s16 gParticleFileTileCount;
extern ParticleFile* gParticleFile;  // 0x0300358C

extern Procedure gDrawAuxSprites;
extern Procedure gDrawParticles;
extern Procedure gDrawMainSprites;

// OBJ VRAM への転送待ちのタイルデータ1件, Video_AllocObjTiles が積み CopyObjTileDataToVram が流す
typedef struct {
  u16 tileCount;  // 0x00, 転送するタイル枚数
  u16 tileIdx;    // 0x02, 転送先の OBJ VRAM タイル番号 (積んだ時点の gObjTileCursor)
  void* tiles;    // 0x04, 転送元
} ObjTileRequest;

EWRAM_DATA u8 u8_ARRAY_02036c00[512] = {};                            // 0x02036C00
EWRAM_DATA rgb555 gBgPlttBlendBuffer[256] = {};                       // 0x02036e00, gBgPlttBuffer に明るさとブレンド色を掛けた結果の置き場, 根拠: ApplyBgPlttBlend
EWRAM_DATA u8 gTilemapBuffer[BG_SCREEN_SIZE * 4] = {};                // 0x02037000, BG0, BG1, BG2, BG3 のタイルマップのバッファ
EWRAM_DATA MainSpriteTileRequest gMainSpriteTileRequests[1024] = {};  // 0x02039000, 根拠: CopyMainSpriteTileDataToVram が 8 バイト刻みで読む

IWRAM_DATA Entity gVideoCommit = {};                   // 0x03000258
IWRAM_DATA Entity gVideoRender = {};                   // 0x03000270
IWRAM_DATA ObjTileRequest gObjTileRequests[128] = {};  // 0x03000288, 根拠: Video_AllocObjTiles が 8 バイト刻みで積み、上限を 127 で弾く

void ResetPltt(rgb555* pltt, s32 val);
void Video_ResetObjTileAlloc(void);
void Video_ResetFrameState(u32 clearOam);
void Video_BuildOAM(void);
void ResetObjPlttSlotCursor(void);
void FUN_0822d248(void);
void ApplyBgPlttBlend(void);
void FUN_0822d828(void);
void FUN_0822d8e8(void);
void FUN_0822d98c(void);
void StageBGRegs(void);
void CopyBGTileDataAndTilemapToVram(void);
void CopyObjTileDataToVram(void);
void CopyMainSpriteTileDataToVram(s32 tileIdx);
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
  CopyObjTileDataToVram();
  FUN_0822e73c();
  CopyBGTileDataAndTilemapToVram();
  REG_DISPCNT &= ~(DISPCNT_BG_ALL_ON | DISPCNT_OBJ_ON);
  if (gDispcntLocked == 0) {
    REG_DISPCNT |= gStagedDISPCNT | DISPCNT_OBJ_ON;
  }
  Video_ApplyMosaic();
  gVBlankDone = FALSE;
  return 0;
}

typedef Entity VideoRender;  // Entity と同じサイズ, 他のEntityにある Create, Init, Destroy 関数 はなく Update (VideoRender_Update) のみ

// 1 フレーム分の描画処理, 登録された 3 つのコールバックを回し、パレットを組み立ててフレーム数を進める
s32 VideoRender_Update(VideoRender* p) {
  ResetObjPlttSlotCursor();
  Video_ResetObjTileAlloc();
  gDrawAuxSprites();
  gDrawMainSprites();
  gDrawParticles();
  Video_BuildOAM();
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
    ApplyBgPlttBlend();
    FUN_0822d248();
  }
  Video_ResetFrameState(0);
  gFrameCounter++;
  return 0;
}

// カメラの注視点と3種の描画リストをクリアし, OBJタイル割り当てとフレーム状態も初期化する
void Video_Reset(void) {
  s32 i;

  gCameraCoords.worldPos.x = 0, gCameraCoords.worldPos.y = 0, gCameraCoords.worldPos.z = 0;
  gCameraCoords.unk_0c = 1;
  gCameraCoords.unk_10 = 0;
  gSpriteListIdx = 0;

  for (i = 0; i < 2; i++) {
    gAuxSpriteLists[i] = NULL;
    gParticleLists[i] = NULL;
    gMainSpriteLists[i] = NULL;
  }

  Video_ResetObjTileAlloc();
  Video_ResetFrameState(1);
}

void UNUSED Video_SetAuxSpriteDrawListHead(AuxSprite* p) { gAuxSpriteLists[gSpriteListIdx] = p; }

void UNUSED Video_SetParticleDrawListHead(Particle* p) { gParticleLists[gSpriteListIdx] = p; }

void UNUSED Video_SetMainSpriteDrawListHead(MainSprite* p) { gMainSpriteLists[gSpriteListIdx] = p; }

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

// この場面で使う3つの描画パスを差し替える, 引数の順は実行順ではないので注意
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
  AuxSprite_SetGfx(p, gfx);
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
void AuxSprite_SetGfx(AuxSprite* p, AuxSpriteGfx* gfx) {
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

void AuxSprite_SetGfxPtr(AuxSprite* p, AuxSpriteGfx* gfx) {
  if (gfx != NULL) {
    p->gfx = gfx;
  }
}

NAKED void AuxSprite_DrawInternal(AuxSprite* p, s32 x, s32 y, s32 z) { INCFUNC("asm/func/AuxSprite_DrawInternal.inc"); }

// 汎用の AuxSprite 描画パス (ほとんどの場面で使われる)
// 描画リストの AuxSprite を全部描くメインのパス, AuxSprite.scaleX/scaleY が入っているものは当たり判定の矩形も同じ倍率で縮めてから画面外判定する
NAKED void AuxSprite_DrawList(void) { INCFUNC("asm/func/AuxSprite_DrawList.inc"); }

// 描画リストの AuxSprite を順に描く, 点滅で消える回と画面外のものは落とす
// MainSprite_DrawListScreen / Particle_DrawListScreen と同じ組で Video_SetDrawPasses に差し替えられる側 ('v' 引数を渡す VM スクリプトがないので実際には動かない)
// ただし本家と違ってカメラからの相対座標を 1/8 にして描くので、こちらは縮小表示のパスとみられる
// 残差は x/8 の展開形で、元は -((-x) >> 3), `/ 8` と書くと (x+7) >> 3 になる (116 命令 vs 128 命令)
NON_MATCH void AuxSprite_DrawListScreen(void) {
#ifdef NONMATCHING_C
  SpriteFlags skipMask = (gFrameCounter & 1) ? (SPRFLAG_HIDDEN | SPRFLAG_BLINK_ODD) : (SPRFLAG_HIDDEN | SPRFLAG_BLINK_EVEN);
  AuxSprite* p;

  for (p = gAuxSpriteLists[gSpriteListIdx]; p != NULL; p = p->next) {
    SpriteFlags flags = p->flags;
    AuxSpriteGfx* gfx;
    s32 x, y, z;

    if (flags & skipMask) {
      continue;
    }

    gfx = p->gfx;
    x = (p->pos.x - gCameraCoords.worldPos.x) / 8 + 120;
    y = (p->pos.y - gCameraCoords.worldPos.y) / 8 + 90;
    z = p->pos.z - gCameraCoords.worldPos.z;

    if (!(flags & SPRFLAG_NO_CLIP)) {
      s32 left, top, w, h;

      if (flags & SPRFLAG_XFLIP) {
        left = x + gfx->px - gfx->pw;
        w = gfx->pw;
      } else {
        left = x - gfx->px;
        w = gfx->pw;
      }
      if (flags & SPRFLAG_YFLIP) {
        top = y + gfx->py - gfx->ph;
        h = gfx->ph;
      } else {
        top = y - gfx->py;
        h = gfx->ph;
      }
      if (left > 240 || top > 180 || left + w < 0 || top + h < 0) {
        continue;
      }
    }

    AuxSprite_DrawInternal(p, x, y, z);
  }
#else
  INCFUNC("asm/func/AuxSprite_DrawListScreen.inc");
#endif
}

// ゲームオーバー時の AuxSprite 描画パス (SPRFLAG_GAMEOVER がセットされた AuxSprite のみ描画)
// SPRFLAG_GAMEOVER の立った AuxSprite だけを描くパス, ゲームオーバー中は Video_SetDrawPasses がこちらに差し替える
// 残差は 196 命令 vs 183 命令 で、AuxSprite_DrawListUnk13 と同じく点滅マスクがレジスタに残らず高位レジスタを1本余計に使う
NON_MATCH void AuxSprite_DrawListGameover(void) {
#ifdef NONMATCHING_C
  SpriteFlags skipMask = (gFrameCounter & 1) ? (SPRFLAG_HIDDEN | SPRFLAG_BLINK_ODD) : (SPRFLAG_HIDDEN | SPRFLAG_BLINK_EVEN);
  AuxSprite* p;
  Vec3 screen;

  for (p = gAuxSpriteLists[gSpriteListIdx]; p != NULL; p = p->next) {
    SpriteFlags flags = p->flags;
    AuxSpriteGfx* gfx;
    s32 x, y, z;

    if (flags & skipMask) {
      continue;
    }
    if (!(flags & SPRFLAG_GAMEOVER)) {
      continue;
    }

    gfx = p->gfx;
    if (flags & SPRFLAG_SCREEN_COORD) {
      x = p->pos.x;
      y = p->pos.y;
      z = p->pos.z;
    } else {
      s32 a, b;

      screen.x = (((p->pos.x >> 1) - (p->pos.z >> 1)) * 48) / 256;
      a = (((p->pos.x >> 1) + (p->pos.z >> 1)) * 48) / 256;
      b = (p->pos.y * 24) / 256;
      screen.x = screen.x - gCameraVpCoords.x + 120;
      screen.y = (a - b) - gCameraVpCoords.y + 90;
      screen.z = (a + b) - gCameraVpCoords.z;
      x = screen.x;
      y = screen.y;
      z = screen.z;
    }

    flags = p->flags;
    if (!(flags & SPRFLAG_NO_CLIP)) {
      s32 left, top, w, h;

      if (flags & SPRFLAG_XFLIP) {
        left = x + gfx->px - gfx->pw;
        w = gfx->pw;
      } else {
        left = x - gfx->px;
        w = gfx->pw;
      }
      if (flags & SPRFLAG_YFLIP) {
        top = y + gfx->py - gfx->ph;
        h = gfx->ph;
      } else {
        top = y - gfx->py;
        h = gfx->ph;
      }
      if (left > 240 || top > 180 || left + w < 0 || top + h < 0) {
        continue;
      }
    }

    AuxSprite_DrawInternal(p, x, y, z);
  }
#else
  INCFUNC("asm/func/AuxSprite_DrawListGameover.inc");
#endif
}

// SPRFLAG_UNK_13 の立った AuxSprite だけを描くパス, SPRFLAG_GAMEOVER に対する AuxSprite_DrawListGameover と同じ関係
// 残差は 169 命令 vs 163 命令 で、点滅マスクがレジスタに残らずスタックに退避される
// 投影を static inline void f(Vec3* pos, Vec3* screen) に切り出すと screen がスタック常駐になり 155 命令まで寄るので、原典はそうした関数を通していたとみられる (ただし &screen がループ外に巻き上げられて一致はしない)
NON_MATCH void AuxSprite_DrawListUnk13(void) {
#ifdef NONMATCHING_C
  SpriteFlags skipMask = (gFrameCounter & 1) ? (SPRFLAG_HIDDEN | SPRFLAG_BLINK_ODD) : (SPRFLAG_HIDDEN | SPRFLAG_BLINK_EVEN);
  AuxSprite* p;
  Vec3 screen;

  for (p = gAuxSpriteLists[gSpriteListIdx]; p != NULL; p = p->next) {
    SpriteFlags flags = p->flags;
    AuxSpriteGfx* gfx;
    s32 x, y, z;

    if (flags & skipMask) {
      continue;
    }
    if (!(flags & SPRFLAG_UNK_13)) {
      continue;
    }

    gfx = p->gfx;
    if (flags & SPRFLAG_SCREEN_COORD) {
      x = p->pos.x;
      y = p->pos.y;
      z = p->pos.z;
    } else {
      s32 a, b;

      screen.x = (((p->pos.x >> 1) - (p->pos.z >> 1)) * 48) / 256;
      a = (((p->pos.x >> 1) + (p->pos.z >> 1)) * 48) / 256;
      b = (p->pos.y * 24) / 256;
      screen.x = screen.x - gCameraVpCoords.x + 120;
      screen.y = (a - b) - gCameraVpCoords.y + 90;
      screen.z = (a + b) - gCameraVpCoords.z;
      x = screen.x;
      y = screen.y;
      z = screen.z;
    }

    if (!(p->flags & SPRFLAG_NO_CLIP)) {
      s32 left = x - gfx->px;
      s32 top = y - gfx->py;

      if (left > 240 || top > 180 || left + gfx->pw < 0 || top + gfx->ph < 0) {
        continue;
      }
    }

    AuxSprite_DrawInternal(p, x, y, z);
  }
#else
  INCFUNC("asm/func/AuxSprite_DrawListUnk13.inc");
#endif
}

void nop_0822b09c(void) {}

// --------------------------------------------

void InitPltt(void) {
  ObjPlttFile* f = GetFile(DIR_OBJPLTT, 0xC5E9);
  gObjPlttLen = f->length;
  gObjPlttData = f->body;
  ResetPltt(gObjPlttData, 8);
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
  gMainSpriteTileCount = 0;
  gObjTileCursor = 0;
  if (gParticleFile != NULL) {
    gObjTileCursor = gParticleFileTileCount;
  }
}

// タイルデータの転送要求を積んで割り当てた OBJ VRAM のタイル番号を返す, 既に積んであれば積み直さずその番号を返す
// この C は単体では原典とバイト一致するが、同じ TU の Video_ResetFrameState の2つの store の順序が入れ替わって ROM が合わなくなる (あちらの文の順序を入れ替えても出力は変わらない)
NON_MATCH s32 Video_AllocObjTiles(void* tiles, s32 tileCount) {
#ifdef NONMATCHING_C
  ObjTileRequest* req;
  ObjTileRequest* newReq;
  s32 i;

  if (gObjTileRequestCount > 127) {
    return gParticleFileTileCount;
  }
  if (gObjTileCursor + tileCount > 1023) {
    return gParticleFileTileCount;
  }

  req = gObjTileRequests;
  for (i = 0; i < gObjTileRequestCount; i++, req++) {
    if (req->tiles == tiles) {
      return req->tileIdx;
    }
  }

  newReq = &gObjTileRequests[gObjTileRequestCount];
  newReq->tileCount = tileCount;
  newReq->tileIdx = gObjTileCursor;
  newReq->tiles = tiles;
  gObjTileCursor += tileCount;
  gAuxSpriteTileCount += tileCount;
  gObjTileRequestCount++;
  return newReq->tileIdx;
#else
  INCFUNC("asm/func/Video_AllocObjTiles.inc");
#endif
}

// 積まれた転送要求を順に OBJ VRAM へ流す, 転送先はパーティクルのタイルの直後から詰めていく
// 残差は size を r2 から r4 に複写する1命令と, それで溢れた高位レジスタ1本の退避/復帰のみ, Tier A-C は試済
NON_MATCH void CopyObjTileDataToVram(void) {
#ifdef NONMATCHING_C
  u8* dst = (u8*)OBJ_VRAM0 + gParticleFileTileCount * 32;
  ObjTileRequest* req = gObjTileRequests;
  s32 i;

  for (i = gObjTileRequestCount; i != 0; i--) {
    s32 size = req->tileCount * 32;

    DmaCopy32(3, req->tiles, dst, size);
    dst += size;
    req++;
  }

  gObjTileRequestCount = 0;
  CopyMainSpriteTileDataToVram(gParticleFileTileCount + gAuxSpriteTileCount);
#else
  INCFUNC("asm/func/CopyObjTileDataToVram.inc");
#endif
}

// 積まれた MainSprite のタイルを OBJ VRAM の tileIdx 以降に詰めて流す
// 命令数は一致, 残差は内側ループをまたぐ i と req+1 のどちらをスタックに退避するかだけ (元は i), Tier A-C は試済
NON_MATCH void CopyMainSpriteTileDataToVram(s32 tileIdx) {
#ifdef NONMATCHING_C
  MainSpriteTileRequest* req = gMainSpriteTileRequests;
  u8* dst = (u8*)OBJ_VRAM0 + tileIdx * 32;
  u32 i;
  s32 j;

  for (i = 0; i < gMainSpriteTileRequestCount; i++) {
    u8* src = req->src;

    for (j = 0; j < req->count; j++) {
      DmaCopy32(3, src, dst, req->size);
      src += 0x200;
      dst += req->size;
    }
    req++;
  }

  gMainSpriteTileRequestCount = 0;
#else
  INCFUNC("asm/func/CopyMainSpriteTileDataToVram.inc");
#endif
}

// 1 フレーム分の描画状態を空にする, clearOam が 0 以外なら OAM バッファのスプライトも全部隠す
void Video_ResetFrameState(u32 clearOam) {
  s32 i;

  gOAMCount = 0;
  for (i = 0; i < 4; i++) {
    gOAMPrioCounts[i] = 0;
  }
  gStagedOAMCount = 0;
  gObjAffineCount = 0;
  if (clearOam != 0) {
    OamData* oam = gOAMBuffer;

    for (i = 0; i < 128; i++) {
      *(u32*)oam = ST_OAM_AFFINE_ERASE << 8;
      oam++;
    }
  }
}

// gStagedOAMBuffer のスプライトを優先度順に gOAMBuffer へ並べ替え、続く領域に OAM のアフィン行列を組んで gOamDirty を立てる
// 優先度ごとのバケットは attr3 の上位バイトを鍵、下位バイトを次要素の添字とした連結リストで、スタック上の 256 バイトが各バケットの先頭を持つ
NAKED void Video_BuildOAM(void) { INCFUNC("asm/func/Video_BuildOAM.inc"); }
