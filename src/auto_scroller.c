#include "camera.h"
#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "registry.h"
#include "video.h"
#include "vm.h"

// AutoScroller.flags (0x1A)
typedef u8 AutoScrollerFlags;
#define AUTOSCROLL_MAP_OFFSET (1 << 0)     // 0x01, Init が width/height を当たり判定マップの tilemapOffsetX/Y から取る
#define AUTOSCROLL_FOLLOW_CAMERA (1 << 1)  // 0x02, Init が初期位置をカメラから取る
#define AUTOSCROLL_WIND (1 << 3)           // 0x08, Update が風の向きと強さで揺らす, 立っていなければ speedX/speedY で流す

// AutoScroller を作るときに渡す引数の塊, Cmd_CreateAutoScroller がスクリプトの引数から組み立てる
typedef struct {
  AutoScrollerFlags flags;  // 0x00, '.f'
  u8 bgIdx;                 // 0x01, '.i'
  u16 tilemapID;            // 0x02, '.d'
  s32 x;                    // 0x04, '.s[0]', AUTOSCROLL_FOLLOW_CAMERA ならカメラ位置で上書きされる
  s32 y;                    // 0x08, '.s[1]'
  s32 width;                // 0x0C, '.o[0]' を 4bit 左にずらした値, AUTOSCROLL_MAP_OFFSET なら Init が CollisionMapData の値で上書きする
  s32 height;               // 0x10, '.o[1]' を 4bit 左にずらした値
  s32 speedX;               // 0x14, '.m[0]'
  s32 speedY;               // 0x18, '.m[1]'
  s32 windAmp;              // 0x1C, '.r=128', AutoScroller.windAmp になる
  s32 wrapX;                // 0x20, '.l[0]'
  s32 wrapY;                // 0x24, '.l[1]'
  u32 prio;                 // 0x28, '.p'
  s32 unk_2c;               // 0x2C, '.a', 0 以外だと Create が ENTITY_UNK_11 で作る
  bool32 blend;             // 0x30, '.b' があれば 1, Init はこれが 0 以外のとき Video_SetBGBlend を呼ぶ
  s32 blendEvb;             // 0x34, '.b[0]=0', '.b' が無ければ 16
  s32 blendEva;             // 0x38, '.b[1]=8', '.b' が無ければ 16
} AutoScrollerConfig;
static_assert(sizeof(AutoScrollerConfig) == 60);

// BG 1枚を自動でスクロールさせる (霧やもやのタイルマップを半透明で流すのに使われている), gAutoScrollers に bgIdx で自分を登録し、gBgStates[bgIdx] の hofs/vofs を毎フレーム書く
typedef struct {
  Entity e;                 // 0x00, ENTITY_UNK_9 か ENTITY_UNK_11
  u16 id;                   // 0x18, Cmd_CreateAutoScroller の引数, 読み手は見つかっていない
  AutoScrollerFlags flags;  // 0x1A, AUTOSCROLL_*
  u8 bgIdx;                 // 0x1B, gBgStates と GetTilemapBuffer と 0x03000010 のテーブルの添字
  FileID tilemapID;         // 0x1C, GetTilemapFile に渡す
  s12_4 x;                  // 0x1E, 4bit右にずらしたものが gBgStates[].hofs になる
  s12_4 y;                  // 0x20, 同じく vofs
  s16 baseX;                // 0x22, offsetX を足す基準点
  s16 baseY;                // 0x24
  s16 stepX;                // 0x26, コマンド1 で Div(targetX - x, unk_48)
  s16 stepY;                // 0x28
  s16 speedX;               // 0x2A, Update が毎フレーム offsetX に足す
  s16 speedY;               // 0x2C
  u8 unk_2e[2];             // 0x2E
  s32 offsetX;              // 0x30, speedX を積む, wrapX * 16 で折り返す
  s32 offsetY;              // 0x34
  s16 targetX;              // 0x38, コマンド1 の引数[1] を 4bit 左にずらした値
  s16 targetY;              // 0x3A
  s16 width;                // 0x3C, Video_SetupBG の第5引数, AUTOSCROLL_MAP_OFFSET なら CollisionMapData から取る
  s16 height;               // 0x3E, Video_SetupBG の第6引数
  s16 wrapX;                // 0x40, offsetX の折り返し幅, カメラ追従の Mod の除数
  s16 wrapY;                // 0x42
  u16 moving;               // 0x44, コマンド0 で 0, コマンド1 で 1, C 側に読み手は見つかっていない
  u16 unk_46;               // 0x46
  u16 moveFrames;           // 0x48, コマンド1 の引数[0], stepX = (targetX - x) / moveFrames
  s16 windAmp;              // 0x4A, AUTOSCROLL_WIND の経路で風の強さ gWindStrength と掛けて offsetX/offsetY の揺れ幅にする
  bool8 active;             // 0x4C, 0 だと Update が何もせず戻る, コマンド4 で 0, コマンド5 で 1
  u8 unk_4d;                // 0x4D
  u16 blending;             // 0x4E, 1 の間 blendEvb/blendEva に毎フレーム blendStep を足す, コマンド3 で立つ
  u16 blendFrames;          // 0x50, blending の残りフレーム数, コマンド3 の引数[0], 0 になると blending を下ろす
  u16 blendEvb;             // 0x52, REG_BLDALPHA の EVB を 8bit 左にずらした 8.8 固定小数, Video_SetBGBlend には 8bit 右に戻して渡す
  u16 blendEva;             // 0x54, 同じく EVA
  u16 blendFromEvb;         // 0x56, 補間の始点, コマンド3 が blendEvb を複写する
  u16 blendFromEva;         // 0x58, 同じく blendEva
  u16 blendTargetEvb;       // 0x5A, 補間の終点, コマンド3 の引数[1] を 8bit 左にずらした値
  u16 blendTargetEva;       // 0x5C, 同じく引数[2]
  s16 blendStepEvb;         // 0x5E, (blendTargetEvb - blendFromEvb) / blendFrames, Update が毎フレーム blendEvb に足す
  s16 blendStepEva;         // 0x60, 同じく blendEva
  u8 unk_62[2];             // 0x62
  u32 cmdCount;             // 0x64, AutoScroller_PushCmd は 8 未満のときだけ足す
  u16 cmdKinds[8];          // 0x68, AutoScroller_RunCmds の switch の値
  s16 cmdArgs[8][8];        // 0x78, 1件16バイト, Cmd_SendAutoScrollerCommand が最大8語積む
} AutoScroller;
static_assert(sizeof(AutoScroller) == 248);

IWRAM_DATA AutoScroller* gAutoScrollers[4] = {};  // 0x03000010, BG ごとの AutoScroller, Init が bgIdx の位置に自分を入れ、Destroy が NULL に戻す

// s12_4 の座標を整数に変換する
static inline s32 Fix4ToInt(s12_4 v) { return FixToInt(4, v); }

extern u16 gWindAngle;
extern u16 gWindStrength;

// BG ごとの AutoScroller の登録表を NULL で埋める
void AutoScroller_ClearTable(void) {
  s32 i;

  for (i = 0; i < 4; i++) {
    gAutoScrollers[i] = NULL;
  }
}

// 積まれたコマンドを順に処理する
s32 AutoScroller_RunCmds(AutoScroller* p) {
  u32 i;

  for (i = 0; i < p->cmdCount; i++) {
    u16 kind = p->cmdKinds[i];
    s16* args = p->cmdArgs[i];

    switch (kind) {
      case 0: {
        p->moving = 0;
        p->unk_46 = 0;
        p->stepX = 0;
        p->stepY = 0;
        break;
      }
      case 1: {
        p->moving = 1;
        p->moveFrames = args[0];
        p->unk_46 = 0;
        p->targetX = args[1] * 16;
        p->targetY = args[2] * 16;
        p->stepX = Div(p->targetX - p->x, p->moveFrames);
        p->stepY = Div(p->targetY - p->y, p->moveFrames);
        break;
      }
      case 2: {
        Video_SetBGBlend(p->bgIdx, (s16)args[0], (s16)args[1]);
        break;
      }
      case 3: {
        p->blending = 1;
        p->blendFromEvb = p->blendEvb;
        p->blendFromEva = p->blendEva;
        p->blendFrames = args[0];
        p->blendTargetEvb = args[1] << 8;
        p->blendTargetEva = args[2] << 8;
        p->blendStepEvb = Div(p->blendTargetEvb - p->blendFromEvb, p->blendFrames);
        p->blendStepEva = Div(p->blendTargetEva - p->blendFromEva, p->blendFrames);
        Video_SetBGBlend(p->bgIdx, p->blendEvb >> 8, p->blendEva >> 8);
        break;
      }
      case 4: {
        p->active = 0;
        break;
      }
      case 5: {
        p->active = 1;
        break;
      }
    }
  }
  return 0;
}

// BG のスクロール位置を毎フレーム決めて gBgStates の hofs/vofs に書く, AUTOSCROLL_WIND なら風で揺らし, それ以外は speedX/speedY で流す
s32 AutoScroller_Update(AutoScroller* p) {
  BgState* bgState = &gBgStates[p->bgIdx];
  s32 limX;
  s32 limY;
  s32 camX;
  s32 camY;

  AutoScroller_RunCmds(p);
  if (p->active == 0) {
    return 0;
  }

  limX = p->wrapX * 16;
  limY = p->wrapY * 16;

  if (p->flags & AUTOSCROLL_WIND) {
    s32 amp = gWindStrength * p->windAmp;
    s32 angle = (gWindAngle + 0xA0) & 0xFF;
    s32 vx;
    s32 vy;

    // 生の積を offsetX に積んで最後に 18bit 分まとめて落とすので POLAR_X/POLAR_Z は使えない
    p->offsetX += COS(angle) * amp;
    p->offsetY += SIN(angle) * amp;
    vx = FixToInt(18, p->offsetX);
    vy = FixToInt(18, p->offsetY);

    if (vx > limX) {
      vx -= limX;
    } else if (vx < -limX) {
      vx += limX;
    }

    if (vy > limY) {
      vy -= limY;
    } else if (vy < -limY) {
      vy += limY;
    }

    p->x = p->baseX + vx;
    p->y = p->baseY + vy;
    bgState->hofs = p->x;
    bgState->vofs = p->y;
  } else {
    p->offsetX += p->speedX;
    if (p->offsetX > limX) {
      p->offsetX -= limX;
    } else if (p->offsetX < -limX) {
      p->offsetX += limX;
    }

    p->offsetY += p->speedY;
    if (p->offsetY > limY) {
      p->offsetY -= limY;
    } else if (p->offsetY < -limY) {
      p->offsetY += limY;
    }

    p->x = p->offsetX + p->baseX;
    p->y = p->offsetY + p->baseY;
    bgState->hofs = Fix4ToInt(p->x);
    bgState->vofs = Fix4ToInt(p->y);
  }

  camX = gCameraVpCoords.x + gCameraCoords.tilemapX;
  camY = gCameraVpCoords.y + gCameraCoords.tilemapY;
  if (p->wrapX != 0) {
    bgState->hofs += Mod(camX - 120, p->wrapX);
  } else {
    bgState->hofs -= 120;
    bgState->hofs += camX;
  }

  if (p->wrapY != 0) {
    bgState->vofs += Mod(camY - 90, p->wrapY);
  } else {
    bgState->vofs -= 90;
    bgState->vofs += camY;
  }

  if (p->blending == 1) {
    p->blendEvb += p->blendStepEvb;
    p->blendEva += p->blendStepEva;
    Video_SetBGBlend(p->bgIdx, p->blendEvb >> 8, p->blendEva >> 8);
    p->blendFrames--;
    if (p->blendFrames == 0) {
      p->blending = 0;
    }
  }
}

s32 AutoScroller_Destroy(AutoScroller* p) { gAutoScrollers[p->bgIdx] = NULL; }

// 設定を写して BG を読み込み, 初期位置の BG マップを作る
s32 AutoScroller_Init(AutoScroller* p, u16 id, AutoScrollerConfig* cfg) {
  s32 x;
  s32 y;
  s32 windAmp;
  BgState* bgState;
  TilemapFile* f;
  BgMapEntry* buf;

  gAutoScrollers[cfg->bgIdx] = p;
  p->id = id;
  p->flags = cfg->flags;
  p->bgIdx = cfg->bgIdx;
  bgState = &gBgStates[p->bgIdx];
  p->tilemapID = cfg->tilemapID;
  f = GetTilemapFile(p->tilemapID);

  if (p->flags & AUTOSCROLL_MAP_OFFSET) {
    CollisionMapData* cm = Registry_Find(0x56C2);

    cfg->width = cm->tiledata->tilemapOffsetX;
    cfg->height = cm->tiledata->tilemapOffsetY;
  }

  if (p->flags & AUTOSCROLL_FOLLOW_CAMERA) {
    x = gCameraVpCoords.x + gCameraCoords.tilemapX;
    y = gCameraVpCoords.y + gCameraCoords.tilemapY;
    windAmp = cfg->windAmp;
  } else {
    x = cfg->x;
    y = cfg->y;
    windAmp = cfg->windAmp;
  }

  p->x = x << 4;
  p->y = y << 4;
  p->baseX = x << 4;
  p->baseY = y << 4;
  p->targetX = x << 4;
  p->targetY = y << 4;
  p->speedX = cfg->speedX;
  p->speedY = cfg->speedY;
  p->offsetX = 0;
  p->offsetY = 0;
  p->width = cfg->width;
  p->height = cfg->height;
  p->wrapX = cfg->wrapX << 3;
  p->wrapY = cfg->wrapY << 3;
  p->moving = 0;
  p->moveFrames = 0;
  p->unk_46 = 0;
  p->active = TRUE;

  buf = GetTilemapBuffer(p->bgIdx);
  if (*f->magic == 'M' && *(f->magic + 1) == 'P') {
    bgState->unk_00 = 1;
    SetBGPrioDirect(p->bgIdx, cfg->prio);
  } else {
    Video_SetupBG(p->bgIdx, 1, f, 0, cfg->width, cfg->height, cfg->prio, buf);
  }
  p->windAmp = windAmp;

  {
    s32 hofs = p->x >> 4;
    s32 vofs = p->y >> 4;

    Video_GenerateBGMap(p->bgIdx, Div(hofs - 128, 8), Div(vofs - 128, 8) & ~1, hofs, vofs);
  }

  p->blending = 0;
  p->blendEvb = cfg->blendEvb << 8;
  p->blendEva = cfg->blendEva << 8;
  p->blendStepEvb = 0;
  p->blendStepEva = 0;
  p->blendTargetEvb = p->blendEvb;
  p->blendTargetEva = p->blendEva;
  p->blendStepEvb = p->blendEvb;
  p->blendStepEva = p->blendEva;
  if (cfg->blend) {
    Video_SetBGBlend(p->bgIdx, cfg->blendEvb, cfg->blendEva);
  }
  return 0;
}

AutoScroller* AutoScroller_Create(u16 id, AutoScrollerConfig* cfg) {
  AutoScroller* p;

  if (cfg->unk_2c == 0) {
    p = CreateEntity(ENTITY_UNK_9, sizeof(AutoScroller));
  } else {
    p = CreateEntity(ENTITY_UNK_11, sizeof(AutoScroller));
  }

  if (p != NULL) {
    SetEntityRoutine(p, AutoScroller_Update, AutoScroller_Destroy);
    if (AutoScroller_Init(p, id, cfg) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// スクリプトの名前付き引数から AutoScrollerConfig を組み立てて AutoScroller を作る
AutoScroller* Cmd_CreateAutoScroller(u32 id) {
  AutoScrollerConfig cfg;
  u8* pc;

  cfg.flags = VM_GetNamedArgValue('f', 0);
  cfg.bgIdx = VM_GetNamedArgValue('i', 0);
  cfg.tilemapID = VM_GetNamedArgValue('d', 0);
  cfg.windAmp = VM_GetNamedArgValue('r', 128);
  cfg.unk_2c = VM_GetNamedArgValue('a', 0);

  if (VM_SeekToNamedArg('s')) {
    pc = VM_GetPC();
    cfg.x = (pc != NULL) ? VM_GetValueAt(pc) : 0;
    pc = VM_GetPC();
    cfg.y = (pc != NULL) ? VM_GetValueAt(pc) : 0;
  } else {
    cfg.x = 0;
    cfg.y = 0;
  }

  if (VM_SeekToNamedArg('o')) {
    pc = VM_GetPC();
    cfg.width = (pc != NULL) ? VM_GetValueAt(pc) << 4 : 0;
    pc = VM_GetPC();
    cfg.height = (pc != NULL) ? VM_GetValueAt(pc) << 4 : 0;
  } else {
    cfg.width = 0;
    cfg.height = 0;
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

  if (VM_SeekToNamedArg('b')) {
    s32 evb;
    s32 eva;

    pc = VM_GetPC();
    evb = (pc != NULL) ? VM_GetValueAt(pc) : 0;
    pc = VM_GetPC();
    eva = (pc != NULL) ? VM_GetValueAt(pc) : 8;
    cfg.blendEvb = evb;
    cfg.blendEva = eva;
    cfg.blend = TRUE;
  } else {
    cfg.blendEvb = 16;
    cfg.blendEva = 16;
    cfg.blend = FALSE;
  }

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

  return AutoScroller_Create(id, &cfg);
}

// BG のコマンドキューに1件積む, 8件たまっていたら捨てる
void AutoScroller_PushCmd(s32 bgIdx, s32 kind, s32 argc, u32* argv) {
  AutoScroller* p = gAutoScrollers[bgIdx];

  if (p != NULL && p->cmdCount <= 7) {
    s32 i;

    p->cmdKinds[p->cmdCount] = kind;
    for (i = 0; i < argc; i++) {
      p->cmdArgs[p->cmdCount][i] = argv[i];
    }
    p->cmdCount++;
  }
}

// スクリプトから BG のコマンドを1件積む
void Cmd_SendAutoScrollerCommand(void) {
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
  AutoScroller_PushCmd(bgIdx, kind, argc, argv);
}
