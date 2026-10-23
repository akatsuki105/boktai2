#include "camera.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "trig.h"
#include "video.h"
#include "vm.h"

// Entity08001610 を作るときに渡す引数の塊, Cmd_9053 がスクリプトの引数から組み立てる
typedef struct {
  u8 flags;       // 0x00, '.f'
  u8 bgIdx;       // 0x01, '.i'
  u16 tilemapID;  // 0x02, '.d'
  s32 x;          // 0x04, '.s[0]', flags bit1 が立っているとカメラ位置で上書きされる
  s32 y;          // 0x08, '.s[1]'
  s32 width;      // 0x0C, '.o[0]<<4', flags bit0 なら Init が CollisionMapData の値で上書きする
  s32 height;     // 0x10, '.o[1]'
  s32 speedX;     // 0x14, '.m[0]'
  s32 speedY;     // 0x18, '.m[1]'
  s32 unk_1c;     // 0x1C, '.r=128'
  s32 wrapX;      // 0x20, '.l[0]'
  s32 wrapY;      // 0x24, '.l[1]'
  u32 prio;       // 0x28, '.p'
  s32 unk_2c;     // 0x2C, '.a', 0 以外だと Create が ENTITY_UNK_11 で作る
  bool32 unk_30;  // 0x30, '.b' があれば 1, Init はこれが 0 以外のとき Video_SetBGBlend を呼ぶ
  s32 unk_34;     // 0x34, '.b[0]=16'
  s32 unk_38;     // 0x38, '.b[1]=8'
} Entity08001610Config;
static_assert(sizeof(Entity08001610Config) == 60);

// BG 1枚のスクロールを受け持つ, 0x03000010 のテーブルに bgIdx で自分を登録し、gBgStates[bgIdx] の hofs/vofs を毎フレーム書く
typedef struct {
  Entity e;            // 0x00, ENTITY_UNK_9 か ENTITY_UNK_11
  u16 unk_18;          // 0x18, Init の第2引数, 読み手は見つかっていない
  u8 flags;            // 0x1A, Init が bit0 と bit1, Update が bit3 を見る
  u8 bgIdx;            // 0x1B, gBgStates と GetTilemapBuffer と 0x03000010 のテーブルの添字
  FileID tilemapID;    // 0x1C, GetTilemapFile に渡す
  s12_4 x;             // 0x1E, 4bit右にずらしたものが gBgStates[].hofs になる
  s12_4 y;             // 0x20, 同じく vofs
  s16 baseX;           // 0x22, offsetX を足す基準点
  s16 baseY;           // 0x24
  s16 stepX;           // 0x26, コマンド1 で Div(targetX - x, unk_48)
  s16 stepY;           // 0x28
  s16 speedX;          // 0x2A, Update が毎フレーム offsetX に足す
  s16 speedY;          // 0x2C
  u8 unk_2e[2];        // 0x2E
  s32 offsetX;         // 0x30, speedX を積む, wrapX * 16 で折り返す
  s32 offsetY;         // 0x34
  s16 targetX;         // 0x38, コマンド1 の引数[1] を 4bit 左にずらした値
  s16 targetY;         // 0x3A
  s16 width;           // 0x3C, Video_SetupBG の第5引数, flags bit0 なら CollisionMapData から取る
  s16 height;          // 0x3E, Video_SetupBG の第6引数
  s16 wrapX;           // 0x40, offsetX の折り返し幅, カメラ追従の Mod の除数
  s16 wrapY;           // 0x42
  u16 moving;          // 0x44, コマンド0 で 0, コマンド1 で 1, C 側に読み手は見つかっていない
  u16 unk_46;          // 0x46
  u16 moveFrames;      // 0x48, コマンド1 の引数[0], stepX = (targetX - x) / moveFrames
  u16 windAmp;         // 0x4A, flags bit3 の経路で風の強さ u16_03002bac と掛けて offsetX/offsetY の揺れ幅にする
  bool8 active;        // 0x4C, 0 だと Update が何もせず戻る, コマンド4 で 0, コマンド5 で 1
  u8 unk_4d;           // 0x4D
  u16 blending;        // 0x4E, 1 の間 blendEvb/blendEva に毎フレーム blendStep を足す, コマンド3 で立つ
  u16 blendFrames;     // 0x50, blending の残りフレーム数, コマンド3 の引数[0], 0 になると blending を下ろす
  u16 blendEvb;        // 0x52, REG_BLDALPHA の EVB を 8bit 左にずらした 8.8 固定小数, Video_SetBGBlend には 8bit 右に戻して渡す
  u16 blendEva;        // 0x54, 同じく EVA
  u16 blendFromEvb;    // 0x56, 補間の始点, コマンド3 が blendEvb を複写する
  u16 blendFromEva;    // 0x58, 同じく blendEva
  u16 blendTargetEvb;  // 0x5A, 補間の終点, コマンド3 の引数[1] を 8bit 左にずらした値
  u16 blendTargetEva;  // 0x5C, 同じく引数[2]
  s16 blendStepEvb;    // 0x5E, (blendTargetEvb - blendFromEvb) / blendFrames, Update が毎フレーム blendEvb に足す
  s16 blendStepEva;    // 0x60, 同じく blendEva
  u8 unk_62[2];        // 0x62
  u32 cmdCount;        // 0x64, Entity08001610_PushCmd は 8 未満のときだけ足す
  u16 cmdKinds[8];     // 0x68, Entity08001610_RunCmds の switch の値
  s16 cmdArgs[8][8];   // 0x78, 1件16バイト, Cmd_D285 が最大8語積む
} Entity08001610;
static_assert(sizeof(Entity08001610) == 248);

IWRAM_DATA Entity08001610* gEntity08001610[4] = {};  // 0x03000010, BG ごとの Entity08001610, Init が bgIdx の位置に自分を入れ、Destroy が NULL に戻す

extern u16 gWindAngle;
extern u16 u16_03002bac;

// BG ごとの Entity08001610 の登録表を NULL で埋める
void Entity08001610_ClearTable(void) {
  s32 i;

  for (i = 0; i < 4; i++) {
    gEntity08001610[i] = NULL;
  }
}

// 積まれたコマンドを順に処理する
NON_MATCH void Entity08001610_RunCmds(Entity08001610* p) {
#ifdef NONMATCHING_C
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
        p->targetX = args[1] << 4;
        p->targetY = args[2] << 4;
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
#else
  INCFUNC("asm/func/Entity08001610_RunCmds.inc");
#endif
}

// BG のスクロール位置を毎フレーム決めて gBgStates の hofs/vofs に書く, flags bit3 なら風で揺らし, それ以外は speedX/speedY で流す
// 残差15命令 (293 対 278, ハンク23件), 原典は limX/limY を r12 とスタックに置いて各腕で複写するが, こちらは低レジスタに収まってしまう
// Tier A-B は試済 (gSineTable * amp の掛ける順, angle を使うたびにマスク, 折り返しを cmn になる < -limX で書く), 未: Tier C
// 試して悪化したもの: angle を u8 に (298/49), angle を amp より先に宣言 (294/30), limX をローカルにせず p->wrapX * 16 を直書き (289/43)
NON_MATCH s32 Entity08001610_Update(Entity08001610* p) {
#ifdef NONMATCHING_C
  BgState* bgState = &gBgStates[p->bgIdx];
  s32 limX;
  s32 limY;

  Entity08001610_RunCmds(p);
  if (p->active == 0) {
    return 0;
  }

  limX = p->wrapX * 16;
  limY = p->wrapY * 16;

  if (p->flags & 8) {
    s32 amp = (s16)p->windAmp * u16_03002bac;
    s32 angle = gWindAngle + 0xA0;
    s32 vx;
    s32 vy;

    // SIN/COS は FixToInt(12, ...) を内側に畳んでいるが, 原典は生の積を offsetX に積んで最後に 18bit 分まとめて落とすので使えない
    p->offsetX += gSineTable[(angle + 0x40) & 0xFF] * amp;
    p->offsetY += gSineTable[angle & 0xFF] * amp;
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
    bgState->hofs = FixToInt(4, p->x);
    bgState->vofs = FixToInt(4, p->y);
  }

  if (p->wrapX == 0) {
    bgState->hofs += gCameraVpCoords.x + gCameraCoords.tilemapX - 120;
  } else {
    bgState->hofs += Mod(gCameraVpCoords.x + gCameraCoords.tilemapX - 120, p->wrapX);
  }

  if (p->wrapY == 0) {
    bgState->vofs += gCameraVpCoords.y + gCameraCoords.tilemapY - 90;
  } else {
    bgState->vofs += Mod(gCameraVpCoords.y + gCameraCoords.tilemapY - 90, p->wrapY);
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
#else
  INCFUNC("asm/func/Entity08001610_Update.inc");
#endif
}

s32 Entity08001610_Destroy(Entity08001610* p) { gEntity08001610[p->bgIdx] = NULL; }

NAKED s32 Entity08001610_Init(Entity08001610* p, u16 param_2, Entity08001610Config* cfg) { INCFUNC("asm/func/Entity08001610_Init.inc"); }

Entity08001610* Entity08001610_Create(u16 param_1, Entity08001610Config* cfg) {
  Entity08001610* p;

  if (cfg->unk_2c == 0) {
    p = CreateEntity(ENTITY_UNK_9, sizeof(Entity08001610));
  } else {
    p = CreateEntity(ENTITY_UNK_11, sizeof(Entity08001610));
  }

  if (p != NULL) {
    SetEntityRoutine(p, Entity08001610_Update, Entity08001610_Destroy);
    if (Entity08001610_Init(p, param_1, cfg) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED Entity08001610* Cmd_9053(u16 param_1) { INCFUNC("asm/func/Cmd_9053.inc"); }

// BG のコマンドキューに1件積む, 8件たまっていたら捨てる
void Entity08001610_PushCmd(s32 bgIdx, s32 kind, s32 argc, u32* argv) {
  Entity08001610* p = gEntity08001610[bgIdx];

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
void Cmd_D285(void) {
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
  Entity08001610_PushCmd(bgIdx, kind, argc, argv);
}
