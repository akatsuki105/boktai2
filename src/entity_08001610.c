#include "entity.h"
#include "file.h"
#include "global.h"
#include "video.h"
#include "vm.h"

// Entity08001610 を作るときに渡す引数の塊, VM_Sub9053 がスクリプトの引数から組み立てる
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
  bool32 unk_30;  // 0x30, '.b' があれば 1, Init はこれが 0 以外のとき FUN_0822f178 を呼ぶ
  s32 unk_34;     // 0x34, '.b[0]=16'
  s32 unk_38;     // 0x38, '.b[1]=8'
} Entity08001610Config;
static_assert(sizeof(Entity08001610Config) == 60);

// BG 1枚のスクロールを受け持つ, 0x03000010 のテーブルに bgIdx で自分を登録し、gBgStates[bgIdx] の hofs/vofs を毎フレーム書く
typedef struct Entity08001610 {
  Entity e;           // 0x00, ENTITY_UNK_9 か ENTITY_UNK_11
  u16 unk_18;         // 0x18, Init の第2引数, 読み手は見つかっていない
  u8 flags;           // 0x1A, Init が bit0 と bit1, Update が bit3 を見る
  u8 bgIdx;           // 0x1B, gBgStates と GetTilemapBuffer と 0x03000010 のテーブルの添字
  FileID tilemapID;   // 0x1C, GetTilemapFile に渡す
  s12_4 x;            // 0x1E, 4bit右にずらしたものが gBgStates[].hofs になる
  s12_4 y;            // 0x20, 同じく vofs
  s16 baseX;          // 0x22, offsetX を足す基準点
  s16 baseY;          // 0x24
  s16 stepX;          // 0x26, コマンド1 で Div(targetX - x, unk_48)
  s16 stepY;          // 0x28
  s16 speedX;         // 0x2A, Update が毎フレーム offsetX に足す
  s16 speedY;         // 0x2C
  u8 unk_2e[2];       // 0x2E
  s32 offsetX;        // 0x30, speedX を積む, wrapX * 16 で折り返す
  s32 offsetY;        // 0x34
  s16 targetX;        // 0x38, コマンド1 の引数[1] を 4bit 左にずらした値
  s16 targetY;        // 0x3A
  s16 width;          // 0x3C, Video_SetupBG の第5引数, flags bit0 なら CollisionMapData から取る
  s16 height;         // 0x3E, Video_SetupBG の第6引数
  s16 wrapX;          // 0x40, offsetX の折り返し幅, カメラ追従の Mod の除数
  s16 wrapY;          // 0x42
  u16 unk_44;         // 0x44, コマンド0 で 0, コマンド1 で 1
  u16 unk_46;         // 0x46
  u16 unk_48;         // 0x48, コマンド1 の引数[0], stepX を出す除数
  u16 unk_4a;         // 0x4A, flags bit3 の経路で u16_03002bac と掛ける
  bool8 active;       // 0x4C, 0 だと Update が何もせず戻る, コマンド4 で 0, コマンド5 で 1
  u8 unk_4d;          // 0x4D
  u16 unk_4e;         // 0x4E, コマンド3 で 1, unk_50 が 0 になると戻る
  u16 unk_50;         // 0x50, Update が減らすカウンタ, Div の除数として ldrh で読まれる
  u16 unk_52;         // 0x52, 8bit 右にずらして FUN_0822f178 に渡す
  u16 unk_54;         // 0x54
  u16 unk_56;         // 0x56, コマンド3 が unk_52 を退避する
  u16 unk_58;         // 0x58
  u16 unk_5a;         // 0x5A, コマンド3 の引数[1] を 8bit 左にずらした値
  u16 unk_5c;         // 0x5C
  s16 unk_5e;         // 0x5E, Update が unk_52 に足す量
  s16 unk_60;         // 0x60
  u8 unk_62[2];       // 0x62
  u32 cmdCount;       // 0x64, Entity08001610_PushCmd は 8 未満のときだけ足す
  u16 cmdKinds[8];    // 0x68, Entity08001610_RunCmds の switch の値
  s16 cmdArgs[8][8];  // 0x78, 1件16バイト, VM_SubD285 が最大8語積む
} Entity08001610;
static_assert(sizeof(Entity08001610) == 248);

// 0x03000010, BG ごとの Entity08001610, Init が bgIdx の位置に自分を入れ、Destroy が NULL に戻す
IWRAM_DATA Entity08001610* gEntity08001610[4] = {};

NON_MATCH void Entity08001610_ClearTable(void) {
#ifdef NONMATCHING_C
  Entity08001610** base = gEntity08001610;
  Entity08001610** p = base + 3;

  do {
    *p = NULL;
    p--;
  } while (p >= base);
#else
  INCFUNC("asm/func/Entity08001610_ClearTable.inc");
#endif
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
        p->unk_44 = 0;
        p->unk_46 = 0;
        p->stepX = 0;
        p->stepY = 0;
        break;
      }
      case 1: {
        p->unk_44 = 1;
        p->unk_48 = args[0];
        p->unk_46 = 0;
        p->targetX = args[1] << 4;
        p->targetY = args[2] << 4;
        p->stepX = Div(p->targetX - p->x, p->unk_48);
        p->stepY = Div(p->targetY - p->y, p->unk_48);
        break;
      }
      case 2: {
        FUN_0822f178(p->bgIdx, (s16)args[0], (s16)args[1]);
        break;
      }
      case 3: {
        p->unk_4e = 1;
        p->unk_56 = p->unk_52;
        p->unk_58 = p->unk_54;
        p->unk_50 = args[0];
        p->unk_5a = args[1] << 8;
        p->unk_5c = args[2] << 8;
        p->unk_5e = Div(p->unk_5a - p->unk_56, p->unk_50);
        p->unk_60 = Div(p->unk_5c - p->unk_58, p->unk_50);
        FUN_0822f178(p->bgIdx, p->unk_52 >> 8, p->unk_54 >> 8);
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
NAKED s32 Entity08001610_Update(Entity08001610* p) { INCFUNC("asm/func/Entity08001610_Update.inc"); }

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

NAKED Entity08001610* VM_Sub9053(u16 param_1) { INCFUNC("asm/func/VM_Sub9053.inc"); }

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
void VM_SubD285(void) {
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
