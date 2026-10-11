#include "entity.h"
#include "file.h"
#include "global.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

// BG 1枚を受け持つ, Entity08001610 と同じ形だが座標を 25.7 固定小数の s32 で持つ
typedef struct {
  Entity e;           // 0x000, ENTITY_UNK_9 か ENTITY_UNK_11
  u16 unk_18;         // 0x018, Init の第2引数, 読み手は見つかっていない
  u8 flags;           // 0x01A, Init が bit0 と bit1 と bit4 を見る
  u8 bgIdx;           // 0x01B, gBgStates と GetTilemapBuffer と gEntity08000a94 の添字
  u32 tilemapID;      // 0x01C, TILEMAP_XXXX, 4バイトで書く
  s25_7 x;            // 0x020
  s25_7 y;            // 0x024
  s32 unk_28;         // 0x028, Init が x と同じ値を入れる
  s32 unk_2c;         // 0x02C, Init が y と同じ値を入れる
  s32 width;          // 0x030, 設定構造体の +0x0C
  s32 height;         // 0x034, 設定構造体の +0x10
  s32 unk_38;         // 0x038, Init が 0 を入れる
  s32 unk_3c;         // 0x03C, Init が 0 を入れる
  s32 unk_40;         // 0x040, Init が x と同じ値を入れる
  s32 unk_44;         // 0x044, Init が y と同じ値を入れる
  s32 unk_48;         // 0x048, FUN_0800045c が x を入れ, unk_40 との間を unk_7a で割って補間する
  s32 unk_4c;         // 0x04C, 同じく y と unk_44
  s32 unk_50;         // 0x050, flags bit0 なら CollisionMapData の +8 を 7bit 右にずらした値
  s32 unk_54;         // 0x054, 同じく +10
  s32 unk_58;         // 0x058, 設定構造体の +0x28
  s32 unk_5c;         // 0x05C, 設定構造体の +0x2C
  s32 unk_60;         // 0x060, 設定構造体の +0x18 を 10bit 左にずらした値
  s32 unk_64;         // 0x064, 設定構造体の +0x1C を 10bit 左にずらした値
  s32 unk_68;         // 0x068, 設定構造体の +0x20
  s32 unk_6c;         // 0x06C, 設定構造体の +0x24
  u16 unk_70;         // 0x070, Init が 0 を入れる
  u16 unk_72;         // 0x072, Init が 0 を入れる
  u16 unk_74;         // 0x074, Init が 0 を入れる
  s16 unk_76;         // 0x076, 設定構造体の +0x14
  u16 unk_78;         // 0x078, Init が 0 を入れる
  s16 unk_7a;         // 0x07A, Update が毎フレーム減らす, 補間の残りフレーム数
  u16 unk_7c;         // 0x07C, 設定構造体の +0x38 を 8bit 左にずらした値
  u16 unk_7e;         // 0x07E, 設定構造体の +0x3C を 8bit 左にずらした値
  u16 unk_80;         // 0x080, FUN_0800045c が unk_7c を退避する
  u16 unk_82;         // 0x082, 同じく unk_7e
  u16 unk_84;         // 0x084, Init が unk_7c を入れる
  u16 unk_86;         // 0x086, Init が unk_7e を入れる
  u16 unk_88;         // 0x088, Init が unk_7c を入れる
  u16 unk_8a;         // 0x08A, Init が unk_7e を入れる
  u8 unk_8c[4];       // 0x08C
  u32 cmdCount;       // 0x090, Entity08000a94_PushCmd は 8 未満のときだけ足す
  u16 cmdKinds[8];    // 0x094
  u16 cmdArgs[8][8];  // 0x0A4, 1件16バイト, VM_Sub33AA が最大8語積む
  u32 unk_124;        // 0x124, Update が 1 ずつ増やし bit0 を見る
} Entity08000a94;
static_assert(sizeof(Entity08000a94) == 296);

// 0x03000000, BG ごとの Entity08000a94, Init が bgIdx の位置に自分を入れ、Destroy が NULL に戻す
// ここからの32バイトは rfu_MBOOT_CHILD_inheritanceLinkStatus が RFU_LINK_STATUS として使う領域と union になっている
IWRAM_DATA Entity08000a94* gEntity08000a94[4] = {};

// BG ごとの Entity08000a94 の登録表を後ろから NULL で埋める
// 残差は movs r2, #0 の位置と, 比較が bcs になる点の2箇所, 原典は符号付きの bge で比べているが C のポインタ比較は符号なしになる
// 添字ループ (for (i = 3; i >= 0; i--)) にすると bge になる代わりにカウンタが残って1命令増える
NON_MATCH void Entity08000a94_ClearTable(void) {
#ifdef NONMATCHING_C
  Entity08000a94** head = gEntity08000a94;
  Entity08000a94** p = head + 3;

  do {
    *p = NULL;
    p--;
  } while (p >= head);
#else
  INCFUNC("asm/func/Entity08000a94_ClearTable.inc");
#endif
}

NAKED s32 FUN_0800045c(Entity08000a94* p) { INCFUNC("asm/func/FUN_0800045c.inc"); }

NAKED s32 Video_GenerateBackgroundMaps(Entity08000a94* p) { INCFUNC("asm/func/Video_GenerateBackgroundMaps.inc"); }

s32 Entity08000a94_Destroy(Entity08000a94* p) {
  gEntity08000a94[p->bgIdx] = NULL;
  return 0;
}

NAKED s32 Entity08000a94_Init(Entity08000a94* p, u16 param_2, u8* param_3) { INCFUNC("asm/func/Entity08000a94_Init.inc"); }

// Update は Video_GenerateBackgroundMaps, Destroy は Entity08000a94_Destroy
NAKED Entity08000a94* Entity08000a94_Create(u16 param_1, unknown* param_2) { INCFUNC("asm/func/Entity08000a94_Create.inc"); }

// 0xB4B4
NAKED unknown* VM_SubB4B4(u32 param_1) { INCFUNC("asm/func/VM_SubB4B4.inc"); }

// id が一致するレイヤの添字を返す, 無ければ 0
NON_MATCH s32 FUN_08000c84(Tilemaps* f, u16 id) {
#ifdef NONMATCHING_C
  TilemapLayer* layer = f->layers;
  s32 i;

  for (i = 0; i < f->layerCount; i++, layer++) {
    if (layer->id == id) {
      return i;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_08000c84.inc");
#endif
}

NAKED s32 Video_LoadTileMap(void) { INCFUNC("asm/func/Video_LoadTileMap.inc"); }

NAKED s32 VM_SubE4B1(void) { INCFUNC("asm/func/VM_SubE4B1.inc"); }

NAKED s32 FUN_08000e8c(s32 param_1, FileID param_2, s32 param_3, u32 param_4) { INCFUNC("asm/func/FUN_08000e8c.inc"); }

NAKED s32 Video_LoadTileSet(void) { INCFUNC("asm/func/Video_LoadTileSet.inc"); }

// BG のコマンドキューに1件積む, 8件たまっていたら捨てる
void Entity08000a94_PushCmd(s32 bgIdx, s32 kind, s32 argc, u32* argv) {
  Entity08000a94* p = gEntity08000a94[bgIdx];

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
void VM_Sub33AA(void) {
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
  Entity08000a94_PushCmd(bgIdx, kind, argc, argv);
}
