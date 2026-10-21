#include "camera.h"
#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "registry.h"
#include "tilemap.h"
#include "tilesets.h"
#include "video.h"
#include "vm.h"

// BgMapScroller.flags (0x01A)
typedef u8 BgMapScrollerFlags;
#define BGSCROLL_MAP_OFFSET (1 << 0)     // 0x01, Init が unk_50/unk_54 を当たり判定マップの tilemapOffsetX/Y から取る, Update はこれが立っていないときだけその2つを引く
#define BGSCROLL_FOLLOW_CAMERA (1 << 1)  // 0x02, 位置をカメラから取る, Init は初期位置, Update は毎フレーム
#define BGSCROLL_AUTO_SCROLL (1 << 2)    // 0x04, speedX/speedY を offsetX/offsetY に積んで流す
#define BGSCROLL_UNK_4 (1 << 4)          // 0x10, Init が Video_SetupBG の第2引数と gBgStates[].unk_00 に渡す 0/1
#define BGSCROLL_CAMERA_WRAP (1 << 5)    // 0x20, スクロール量にカメラ位置を足し, wrapX/wrapY で折り返す
#define BGSCROLL_BLINK (1 << 6)          // 0x40, frameCount の bit0 で DISPCNT の自分の BG を点滅させる
#define BGSCROLL_UNK_7 (1 << 7)          // 0x80, Update がカメラ位置に unk_58/unk_5c を足す

// BG 1枚を受け持つ, VM コマンド 0xB4B4 (Cmd_CreateBG) が作り, gBgMapScrollers に bgIdx で自分を登録する
// 毎フレーム Video_GenerateBackgroundMaps が位置を決め直して Video_GenerateBGMap で BG マップを作り直し, ブレンドの補間と flags bit6 の点滅も見る
// 位置の決め方は3通り, flags bit1 ならカメラ追従, bit2 なら speedX/speedY で自動スクロール, どちらでもなければ fromX/fromY から targetX/targetY への補間
//
// Entity08001610 とは「BG 1枚を受け持つ」「VM コマンドで作られる」「コマンドキューを持つ」「カメラ追従と Mod での折り返し」
// 「Video_SetBGBlend でのブレンド」「offsetX と wrapX での自動スクロール」まで同じで, 違いは次の3点
//   1. こちらは毎フレーム Video_GenerateBGMap を呼んで BG マップを作り直す (Entity08001610_Update は gBgStates の hofs/vofs を書くだけ)
//      ハードの BG 1枚に収まらない大きさのタイルマップをスクロールできるかどうかの差で, 型名の由来
//   2. こちらは scale と centerX/centerY を持ち, カメラ位置を中心点まわりに scale/128 倍する (視差), Entity08001610 に相当するメンバはない
//   3. 座標が s25_7 (Entity08001610 は s12_4)
typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_9 か ENTITY_UNK_11
  u16 unk_18;                // 0x018, Init の第2引数, 読み手は見つかっていない
  BgMapScrollerFlags flags;  // 0x01A
  u8 bgIdx;                  // 0x01B, 0..3, 0: BG0, 1: BG1, 2: BG2, 3: BG3
  u32 tilemapID;             // 0x01C, TILEMAP_XXXX, 4バイトで書く
  s25_7 x;                   // 0x020
  s25_7 y;                   // 0x024
  s32 baseX;                 // 0x028, offsetX を足す基準点, Init が x と同じ値を入れる
  s32 baseY;                 // 0x02C, 同じく y
  s32 speedX;                // 0x030, config.speedX, flags bit2 なら毎フレーム offsetX に足す
  s32 speedY;                // 0x034, config.speedY, 同じく offsetY
  s32 offsetX;               // 0x038, speedX を積む, wrapX を超えたら折り返す
  s32 offsetY;               // 0x03C, 同じく speedY と wrapY
  s32 targetX;               // 0x040, 補間の終点, Init が x と同じ値を入れる
  s32 targetY;               // 0x044, 同じく y
  s32 fromX;                 // 0x048, 補間の始点, FUN_0800045c が x を入れる
  s32 fromY;                 // 0x04C, 同じく y
  s32 unk_50;                // 0x050, flags bit0 なら CollisionMapData の +8 を 7bit 右にずらした値
  s32 unk_54;                // 0x054, 同じく +10
  s32 unk_58;                // 0x058, config.unk_28, flags bit7 ならカメラ位置に足す
  s32 unk_5c;                // 0x05C, config.unk_2c, 同じく y
  s32 wrapX;                 // 0x060, config.wrapX を 10bit 左にずらした値, offsetX の折り返し幅, 7bit 右に戻したものがカメラ追従の Mod の除数
  s32 wrapY;                 // 0x064, 同じく config.wrapY
  s32 centerX;               // 0x068, config.centerX, scale をかける中心
  s32 centerY;               // 0x06C, config.centerY
  u16 moving;                // 0x070, 1 の間 from から target へ moveFrames 分で補間する
  u16 moveStep;              // 0x072, 補間の経過フレーム数
  u16 moveFrames;            // 0x074, 補間の総フレーム数
  s16 scale;                 // 0x076, config.scale, 128 で等倍, カメラ位置を centerX/centerY 中心に拡縮する視差の係数
  u16 blending;              // 0x078, 1 の間 blendEvb/blendEva に毎フレーム blendStep を足す
  u16 blendFrames;           // 0x07A, blending の残りフレーム数, 0 になると blending を下ろす
  u16 blendEvb;              // 0x07C, REG_BLDALPHA の EVB を 8bit 左にずらした 8.8 固定小数, Video_SetBGBlend には 8bit 右に戻して渡す
  u16 blendEva;              // 0x07E, 同じく EVA
  u16 unk_80;                // 0x080, FUN_0800045c が blendEvb を退避する
  u16 unk_82;                // 0x082, 同じく blendEva
  u16 unk_84;                // 0x084, Init が blendEvb を入れる
  u16 unk_86;                // 0x086, Init が blendEva を入れる
  u16 blendStepEvb;          // 0x088, 毎フレーム blendEvb に足す分, Init は blendEvb を入れる
  u16 blendStepEva;          // 0x08A, 同じく blendEva
  u8 unk_8c[4];              // 0x08C
  u32 cmdCount;              // 0x090, BgMapScroller_PushCmd は 8 未満のときだけ足す
  u16 cmdKinds[8];           // 0x094
  u16 cmdArgs[8][8];         // 0x0A4, 1件16バイト, Cmd_33AA が最大8語積む
  u32 frameCount;            // 0x124, 毎フレーム +1, flags bit6 なら bit0 で BG の表示を点滅させる
} BgMapScroller;
static_assert(sizeof(BgMapScroller) == 296);

// Cmd_CreateBG が VM の名前付き引数から組み立てて BgMapScroller_Create に渡す
typedef struct {
  BgMapScrollerFlags flags;  // 0x00, '.f', BgMapScroller.flags になる
  u8 bgIdx;                  // 0x01, '.i', BG番号, gBgMapScrollers の添字
  u16 tilemapID;             // 0x02, '.d', TILEMAP_XXXX
  s32 x;                     // 0x04, '.s[0]', 初期位置, flags bit1 ならカメラから取るのでこれは使われない
  s32 y;                     // 0x08, '.s[1]'
  s32 speedX;                // 0x0C, '.m[0]', BgMapScroller.speedX になる
  s32 speedY;                // 0x10, '.m[1]', 同じく speedY
  s32 scale;                 // 0x14, '.r=128', BgMapScroller.scale になる, 128 で等倍
  s32 wrapX;                 // 0x18, '.l[0]', 10bit左シフトして BgMapScroller.wrapX になる
  s32 wrapY;                 // 0x1C, '.l[1]', 同じく wrapY
  s32 centerX;               // 0x20, '.c[0]=120', BgMapScroller.centerX になる, 既定値は画面中央の x
  s32 centerY;               // 0x24, '.c[1]=90', 同じく centerY と画面中央の y
  s32 unk_28;                // 0x28, '.A[0]', unk_58 になる
  s32 unk_2c;                // 0x2C, '.A[1]', 同じく unk_5c
  s32 prio;                  // 0x30, '.p', BGの優先度, 既定値は BG番号ごとに 0/1/3/1
  s32 unk_34;                // 0x34, '.a', 0 以外なら ENTITY_UNK_11 で作る
  s32 blendEvb;              // 0x38, '.b[0]=0', Video_SetBGBlend の第2引数, BgMapScroller.blendEvb になる
  s32 blendEva;              // 0x3C, '.b[1]=8', 同じく第3引数と BgMapScroller.blendEva
} BgMapScrollerConfig;
static_assert(sizeof(BgMapScrollerConfig) == 64);

// 0x03000000, BG ごとの BgMapScroller, Init が bgIdx の位置に自分を入れ、Destroy が NULL に戻す
// ここからの32バイトは rfu_MBOOT_CHILD_inheritanceLinkStatus が RFU_LINK_STATUS として使う領域と union になっている
IWRAM_DATA BgMapScroller* gBgMapScrollers[4] = {};

s32 Video_LoadTileSetParts(s32 bg, TileSetFile* f, s32 count, u16* ids, s32 tileidx);

// BG ごとの BgMapScroller の登録表を NULL で埋める
void BgMapScroller_ClearTable(void) {
  s32 i;

  for (i = 0; i < 4; i++) {
    gBgMapScrollers[i] = NULL;
  }
}

NAKED s32 FUN_0800045c(BgMapScroller* p) { INCFUNC("asm/func/FUN_0800045c.inc"); }

// BG の表示位置を毎フレーム決め直して BG マップを作り直す, flags bit1 ならカメラ追従, bit2 なら speed で自動スクロール, どちらでもなければ target への補間
// 残差14命令 (356 対 370, ハンク29件), 原典側に余分なレジスタ複写が多く, 形と並びはほぼ一致している
// Tier A-B は試済 (FixToInt, 折り返しを cmn になる < -wrapX で書く), 未: Tier C の r8 経由の共通化
// scale の分岐は hofs を両辺に書いて中心の減算を2つ先に出すと 359 対 370 まで詰まるが, コードが汚くなるので採っていない
NON_MATCH s32 Video_GenerateBackgroundMaps(BgMapScroller* p) {
#ifdef NONMATCHING_C
  s32 x;
  s32 y;
  s32 hofs;
  s32 vofs;
  s32 hTile;
  s32 vTile;

  FUN_0800045c(p);

  if (p->flags & BGSCROLL_FOLLOW_CAMERA) {
    if (!gCameraCoords.drawMode) {
      // DRAW_ISOMETRIC
      x = gCameraVpCoords.x + gCameraCoords.tilemapX;
      y = gCameraVpCoords.y + gCameraCoords.tilemapY;
    } else {
      // DRAW_SCREEN
      x = gCameraCoords.worldPos.x >> 3;
      y = gCameraCoords.worldPos.y >> 3;
    }

    if (!(p->flags & BGSCROLL_MAP_OFFSET)) {
      x -= p->unk_50;
      y -= p->unk_54;
    }

    if (p->flags & BGSCROLL_UNK_7) {
      x += p->unk_58;
      y += p->unk_5c;
    }

    if (p->scale != 128) {
      x = FixToInt(7, (x - p->centerX) * p->scale) + p->centerX;
      y = FixToInt(7, (y - p->centerY) * p->scale) + p->centerY;
    }

    hofs = x - 120;
    vofs = y - 90;
    hTile = FixToInt(3, x - 128);
    vTile = FixToInt(3, y - 128);
  } else {
    if (p->flags & BGSCROLL_AUTO_SCROLL) {
      p->offsetX += p->speedX;
      if (p->offsetX > p->wrapX) {
        p->offsetX -= p->wrapX;
      } else if (p->offsetX < -p->wrapX) {
        p->offsetX += p->wrapX;
      }

      p->offsetY += p->speedY;
      if (p->offsetY > p->wrapY) {
        p->offsetY -= p->wrapY;
      } else if (p->offsetY < -p->wrapY) {
        p->offsetY += p->wrapY;
      }

      p->x = p->offsetX + p->baseX;
      p->y = p->offsetY + p->baseY;
    } else if (p->moving == 1) {
      s32 rest = p->moveFrames - p->moveStep;

      p->x = Div(rest * p->fromX + p->moveStep * p->targetX, p->moveFrames);
      p->y = Div(rest * p->fromY + p->moveStep * p->targetY, p->moveFrames);
      p->moveStep++;
      if (p->moveStep >= p->moveFrames) {
        p->moving = 0;
        p->moveStep = 0;
        p->x = p->targetX;
        p->y = p->targetY;
      }
    }

    hofs = FixToInt(7, p->x);
    vofs = FixToInt(7, p->y);

    if (p->flags & BGSCROLL_CAMERA_WRAP) {
      s32 wx = p->wrapX >> 7;
      s32 wy = p->wrapY >> 7;

      hofs += gCameraVpCoords.x + gCameraCoords.tilemapX;
      vofs += gCameraVpCoords.y + gCameraCoords.tilemapY;
      if (wx != 0) {
        hofs = Mod(hofs, wx);
      }
      if (wy != 0) {
        vofs = Mod(vofs, wy);
      }
    }

    if (hofs < 0) {
      hTile = ~(-hofs >> 3);
    } else {
      hTile = hofs >> 3;
    }

    if (vofs < 0) {
      vTile = ~(-vofs >> 3);
    } else {
      vTile = vofs >> 3;
    }
  }

  Video_GenerateBGMap(p->bgIdx, hTile, vTile & ~1, hofs, vofs);

  if (p->blending == 1) {
    p->blendEvb += p->blendStepEvb;
    p->blendEva += p->blendStepEva;
    Video_SetBGBlend(p->bgIdx, p->blendEvb >> 8, p->blendEva >> 8);
    p->blendFrames--;
    if (p->blendFrames == 0) {
      p->blending = 0;
    }
  }

  if (p->flags & BGSCROLL_BLINK) {
    if (p->frameCount & 1) {
      gStagedDISPCNT |= DISPCNT_BG0_ON << p->bgIdx;
    } else {
      gStagedDISPCNT &= ~(DISPCNT_BG0_ON << p->bgIdx);
    }
  }

  p->frameCount++;
  return 0;
#else
  INCFUNC("asm/func/Video_GenerateBackgroundMaps.inc");
#endif
}

s32 BgMapScroller_Destroy(BgMapScroller* p) {
  gBgMapScrollers[p->bgIdx] = NULL;
  return 0;
}

// 残差8命令 (188 対 196), 命令列は1対1で一致していて, 違いは原典が f をスタックに追い出して ox/oy を r8/r9 に置くぶんの mov だけ
// agbcc-internals 4.3 の優先度の3入力 (参照回数, 生存区間, 生成順) はこちらと同じなので, ソース側に動かす余地が見つかっていない
// 試して変わらなかったもの: ローカルの宣言順, ox/oy を if の前で 0 初期化 (186/38 で悪化)
NON_MATCH s32 BgMapScroller_Init(BgMapScroller* p, u16 param_2, BgMapScrollerConfig* config) {
#ifdef NONMATCHING_C
  s32 ox;
  s32 oy;
  s32 x;
  s32 y;
  s32 v;
  BgState* bgState;
  TilemapFile* f;

  gBgMapScrollers[config->bgIdx] = p;
  p->unk_18 = param_2;
  p->flags = config->flags;
  p->bgIdx = config->bgIdx;
  bgState = &gBgStates[p->bgIdx];
  p->tilemapID = config->tilemapID;
  f = GetTilemapFile(config->tilemapID);

  if (p->flags & BGSCROLL_MAP_OFFSET) {
    CollisionMapData* cm = Registry_Find(0x56C2);

    ox = cm->tiledata->tilemapOffsetX;
    oy = cm->tiledata->tilemapOffsetY;
  } else {
    ox = 0;
    oy = 0;
  }

  if (p->flags & BGSCROLL_FOLLOW_CAMERA) {
    x = gCameraVpCoords.x + gCameraCoords.tilemapX;
    y = gCameraVpCoords.y + gCameraCoords.tilemapY;
  } else {
    x = config->x;
    y = config->y;
  }

  p->scale = config->scale;
  bgState->hofs = x - 120;
  bgState->vofs = y - 90;

  x <<= 7;
  y <<= 7;
  p->x = x;
  p->y = y;
  p->baseX = x;
  p->baseY = y;
  p->targetX = x;
  p->targetY = y;
  p->speedX = config->speedX;
  p->speedY = config->speedY;
  p->offsetX = 0;
  p->offsetY = 0;
  p->unk_50 = ox >> 7;
  p->unk_54 = oy >> 7;
  p->unk_58 = config->unk_28;
  p->unk_5c = config->unk_2c;
  p->wrapX = config->wrapX << 10;
  p->wrapY = config->wrapY << 10;
  p->centerX = config->centerX;
  p->centerY = config->centerY;
  p->moving = 0;
  p->moveFrames = 0;
  p->moveStep = 0;
  p->blending = 0;
  p->blendEvb = config->blendEvb << 8;
  p->blendEva = config->blendEva << 8;
  p->blendStepEvb = 0;
  p->blendStepEva = 0;
  p->unk_84 = p->blendEvb;
  p->unk_86 = p->blendEva;
  p->blendStepEvb = p->blendEvb;
  p->blendStepEva = p->blendEva;

  v = (p->flags & BGSCROLL_UNK_4) != 0;

  if (f->magic[0] == 'M' && f->magic[1] == 'P') {
    bgState->unk_00 = v;
    SetBGPrioDirect(p->bgIdx, config->prio);
  } else {
    Video_SetupBG(p->bgIdx, v, f, 0, ox, oy, config->prio, GetTilemapBuffer(p->bgIdx));
  }

  return 0;
#else
  INCFUNC("asm/func/BgMapScroller_Init.inc");
#endif
}

// Update は Video_GenerateBackgroundMaps, Destroy は BgMapScroller_Destroy
BgMapScroller* BgMapScroller_Create(u16 param_1, BgMapScrollerConfig* config) {
  BgMapScroller* p;

  if (config->unk_34 == 0) {
    p = CreateEntity(ENTITY_UNK_9, sizeof(BgMapScroller));
  } else {
    p = CreateEntity(ENTITY_UNK_11, sizeof(BgMapScroller));
  }

  if (p != NULL) {
    SetEntityRoutine(p, Video_GenerateBackgroundMaps, BgMapScroller_Destroy);
    if (BgMapScroller_Init(p, param_1, config) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 0xB4B4
BgMapScroller* Cmd_CreateBG(u32 param_1) {
  BgMapScrollerConfig cfg;
  u8* pc;

  cfg.flags = VM_GetNamedArgValue('f', 0);
  cfg.bgIdx = VM_GetNamedArgValue('i', 0);
  cfg.tilemapID = VM_GetNamedArgValue('d', 0);
  cfg.scale = VM_GetNamedArgValue('r', 128);

  switch (cfg.bgIdx) {
    case 0: {
      cfg.prio = VM_GetNamedArgValue('p', 0);
      break;
    }
    case 1: {
      cfg.prio = VM_GetNamedArgValue('p', 1);
      break;
    }
    case 2: {
      cfg.prio = VM_GetNamedArgValue('p', 3);
      break;
    }
    case 3: {
      cfg.prio = VM_GetNamedArgValue('p', 1);
      break;
    }
  }

  cfg.unk_34 = VM_GetNamedArgValue('a', 0);

  if (VM_SeekToNamedArg('s')) {
    pc = VM_GetPC();
    cfg.x = (pc != NULL) ? VM_GetValueAt(pc) : 0;
    pc = VM_GetPC();
    cfg.y = (pc != NULL) ? VM_GetValueAt(pc) : 0;
  } else {
    cfg.x = 0;
    cfg.y = 0;
  }

  if (VM_SeekToNamedArg('m')) {
    pc = VM_GetPC();
    cfg.speedX = (pc != NULL) ? VM_GetValueAt(pc) : 0;
    pc = VM_GetPC();
    cfg.speedY = (pc != NULL) ? VM_GetValueAt(pc) : 0;
  } else {
    cfg.speedX = 0;
    cfg.speedY = 0;
  }

  if (VM_SeekToNamedArg('l')) {
    pc = VM_GetPC();
    cfg.wrapX = (pc != NULL) ? VM_GetValueAt(pc) : 0;
    pc = VM_GetPC();
    cfg.wrapY = (pc != NULL) ? VM_GetValueAt(pc) : 0;
  } else {
    cfg.wrapX = 0;
    cfg.wrapY = 0;
  }

  if (VM_SeekToNamedArg('c')) {
    pc = VM_GetPC();
    cfg.centerX = (pc != NULL) ? VM_GetValueAt(pc) : 120;
    pc = VM_GetPC();
    cfg.centerY = (pc != NULL) ? VM_GetValueAt(pc) : 90;
  } else {
    cfg.centerX = 120;
    cfg.centerY = 90;
  }

  if (VM_SeekToNamedArg('A')) {
    pc = VM_GetPC();
    cfg.unk_28 = (pc != NULL) ? VM_GetValueAt(pc) : 0;
    pc = VM_GetPC();
    cfg.unk_2c = (pc != NULL) ? VM_GetValueAt(pc) : 0;
  } else {
    cfg.unk_28 = 0;
    cfg.unk_2c = 0;
  }

  if (VM_SeekToNamedArg('b')) {
    s32 evb;
    s32 eva;

    pc = VM_GetPC();
    evb = (pc != NULL) ? VM_GetValueAt(pc) : 0;
    pc = VM_GetPC();
    eva = (pc != NULL) ? VM_GetValueAt(pc) : 8;
    cfg.blendEvb = evb;
    cfg.blendEva = eva;
    Video_SetBGBlend(cfg.bgIdx, evb, eva);
  }

  return BgMapScroller_Create(param_1, &cfg);
}

// id のレイヤが何番目かを返す, 見つからなければ 0
// 残差は layer と i のレジスタが入れ替わるのみ (命令列は 22 対 22 で一致)
NON_MATCH s32 FUN_08000c84(Tilemaps* f, u16 id) {
#ifdef NONMATCHING_C
  TilemapLayer* layer = f->layers;
  s32 i;

  for (i = 0; i < f->layerCount; i++) {
    if (layer->id == id) {
      return i;
    }
    layer++;
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_08000c84.inc");
#endif
}

// 0x7A27, 'd' のタイルマップを 't' の BG 構成に流す, レイヤの並びは 'i' なら直接指定, 'c' ならレイヤIDから引く
s32 Cmd_LoadTileMap(void) {
  s32 indices[4];
  TilemapFile* f = GetTilemapFile(VM_GetNamedArgValue('d', 0));
  Tilemaps tm = *f;
  s32 layout;
  s32 hofs;
  s32 vofs;
  s32 count;
  bool32 hasIndices;
  s32 j;

  // 相対オフセットをアドレスに変換
  tm.layers = (TilemapLayer*)((u32)tm.layers + (u32)f);
  tm.tiles = (u8*)((u32)tm.tiles + (u32)f);
  tm.metatiles = (BgMapEntry*)((u32)tm.metatiles + (u32)f);

  layout = VM_GetNamedArgValue('t', 1);

  if (VM_SeekToNamedArg('o')) {
    u8* pc;

    pc = VM_GetPC();
    hofs = (pc != NULL) ? (VM_GetValueAt(pc) << 7) : 0;

    pc = VM_GetPC();
    vofs = (pc != NULL) ? (VM_GetValueAt(pc) << 7) : 0;
  } else {
    hofs = 0, vofs = 0;
  }

  count = VM_GetNamedArgValue('n', 1);
  hasIndices = FALSE;

  if (VM_SeekToNamedArg('i')) {
    u8* pc = VM_GetPC();

    hasIndices = TRUE;
    for (j = 0; j < 4; j++) {
      if (pc != NULL) {
        indices[j] = VM_GetValueAt(pc);
        pc = VM_GetPC();
      } else {
        indices[j] = 0;
      }
    }
  } else {
    for (j = 0; j < 4; j++) {
      indices[j] = j;
    }
  }

  if (!hasIndices && VM_SeekToNamedArg('c')) {
    u8* pc = VM_GetPC();

    for (j = 0; j < 4; j++) {
      if (pc != NULL) {
        indices[j] = FUN_08000c84(&tm, VM_GetValueAt(pc));
        pc = VM_GetPC();
      }
    }
  }

  if (f->magic[0] == 'M') {
    if (f->magic[1] == 'P') {
      Video_SetupBGLayout(layout, 0, f, (s16)hofs, (s16)vofs, count, indices);
    }
  }
}

// 0xE4B1
// 'd' のタイルマップの1レイヤを 'p' の BG に割り当てる, レイヤは 'i' なら添字を直接, 'c' ならレイヤIDから引く
// 残差は else 側に残るフラグの作り置き3命令 (movs/cmp/bne) のみ, こちらは agbcc が畳んで消してしまう, Tier A-B は試済 (フラグの位置と順序と型, if/else で両辺代入)
NON_MATCH s32 Cmd_SetBGLayer(void) {
#ifdef NONMATCHING_C
  Tilemaps tm;
  u16 bg = VM_GetNamedArgValue('p', 0);
  u16 fileID = VM_GetNamedArgValue('d', 0);
  TilemapFile* f = GetTilemapFile(fileID);
  u16 layerIdx;
  bool32 found;
  u8* pc;

  tm = *f;
  tm.layers = (TilemapLayer*)((u32)tm.layers + (u32)f);
  tm.tiles = (u8*)((u32)tm.tiles + (u32)f);
  tm.metatiles = (BgMapEntry*)((u32)tm.metatiles + (u32)f);

  if (VM_SeekToNamedArg('i') && (pc = VM_GetPC()) != NULL) {
    layerIdx = VM_GetValueAt(pc);
    found = TRUE;
  } else {
    layerIdx = 0;
    found = FALSE;
  }

  if (!found && VM_SeekToNamedArg('c') && (pc = VM_GetPC()) != NULL) {
    layerIdx = FUN_08000c84(&tm, VM_GetValueAt(pc));
  }

  Video_SetBGLayer(bg, f, layerIdx);
  return layerIdx;
#else
  INCFUNC("asm/func/Cmd_SetBGLayer.inc");
#endif
}

NAKED s32 UNUSED FUN_08000e8c(s32 param_1, FileID param_2, s32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_08000e8c.inc"); }

// 0x11D4, 't' の BG へ 'd' のタイルセットから 'c' で並べた TileSetPart を読み込む, 'm' があればコピー先をそのタイルマップの loadOffset にする
// 残差は引数ループが bottom-test に回転される1命令のみ (原典は top-test + b で戻る形), Tier A は試済 (for / while(TRUE)+break / 複合条件)
NON_MATCH s32 Cmd_LoadTileSet(void) {
#ifdef NONMATCHING_C
  u16 ids[64];
  u16 bg = VM_GetNamedArgValue('t', 0);
  u16 fileID = VM_GetNamedArgValue('d', 0);
  u16 tileidx = VM_GetNamedArgValue('s', 0);
  TileSetFile* f = GetFile(DIR_TILESET, fileID);
  s32 count = 0;
  s32 i;

  if (VM_SeekToNamedArg('c')) {
    for (i = 0; i <= 63; i++) {
      u8* pc = VM_GetPC();

      if (pc == NULL) {
        break;
      }
      ids[i] = VM_GetValueAt(pc);
      count++;
    }
  } else {
    for (i = 0; i < 64; i++) {
      ids[i] = 0;
    }
  }

  if (VM_SeekToNamedArg('m')) {
    TilemapFile tm = *GetTilemapFile(VM_GetValue());
    tileidx = tm.loadOffset;
  }

  Video_LoadTileSetParts(bg, f, count, ids, tileidx);
  return 0;
#else
  INCFUNC("asm/func/Cmd_LoadTileSet.inc");
#endif
}

// BG のコマンドキューに1件積む, 8件たまっていたら捨てる
void BgMapScroller_PushCmd(s32 bgIdx, s32 kind, s32 argc, u32* argv) {
  BgMapScroller* p = gBgMapScrollers[bgIdx];

  if (p != NULL && p->cmdCount <= 7) {
    s32 i;

    p->cmdKinds[p->cmdCount] = kind;
    for (i = 0; i < argc; i++) {
      p->cmdArgs[p->cmdCount][i] = argv[i];
    }
    p->cmdCount++;
  }
}

// 0x33AA, スクリプトから BG のコマンドを1件積む
void Cmd_33AA(void) {
  u32 argv[8];
  s32 argc;
  u32* dst;
  s32 bgIdx = VM_GetNamedArgValue('t', 1);
  s32 kind = VM_GetNamedArgValue('r', 0);

  argc = 0;
  if (VM_SeekToNamedArg('p')) {
    dst = argv;
    while (VM_GetPC() != NULL && argc <= 7) {
      *dst++ = VM_GetValue();
      argc++;
    }
  }
  BgMapScroller_PushCmd(bgIdx, kind, argc, argv);
}
