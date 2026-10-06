#include "entity.h"
#include "global.h"
#include "sprite_main.h"
#include "tilemap.h"

// 3行の選択肢を持つ通信メニュー, 各行は values[i] を counts[i] で巻き戻しながら左右で切り替える
typedef struct Entity08F4 {
  Entity e;                                    // 0x000, ENTITY_UNK_11
  Tilemaps* tilemap;                           // 0x018, TILEMAP_CD91
  rgb555* bgPltt;                              // 0x01C, BGP_26BB
  MainSprite sprites[7];                       // 0x020
  MainSpriteGfx gfx;                           // 0x2C0, SPRITE_UI_LINK
  MainSpriteGfxFile* gfxFile;                  // 0x2E0, SPRITE_UI_LINK
  rgb555 objPltt[16];                          // 0x2E4, FUN_081db32c が gObjPlttData+0x2930 から16色複写し、sprites[0].pltt をここへ向ける
  u16 unk_304;                                 // 0x304, FUN_081db32c が 0 を入れるだけ
  u16 unk_306;                                 // 0x306, 読み手も書き手も見つかっていない
  void (*updateCallback)(struct Entity08F4*);  // 0x308
  u8* scriptPc;                                // 0x30C, Init が FUN_0823d340() を入れる, VM_ParseStringRef / TextPanel_SetScript に渡す
  u32 unk_310;                                 // 0x310, FUN_081db074 が bit0 を落とし、FUN_081db57c が立てる
  s32 panelID0;                                // 0x314, TextPanel_Create(22, 4, 6, 2)
  u32 unk_318;                                 // 0x318, FUN_081db57c が初回だけの初期化を行うための番兵
  s32 panelID1;                                // 0x31C, TextPanel_Create(20, 12, 8, 2)
  u8 unk_320;                                  // 0x320, Init で 0
  u8 repeatTimer;                              // 0x321, 十字キーを押しっぱなしの間 0xC まで数え、離すと 0 に戻る
  u8 values[3];                                // 0x322, 各行の選択値, 左右で counts[i] を上限に巻き戻る
  u8 counts[3];                                // 0x325, 各行の選択肢数, FUN_081daf44 が 1か2, 3, 4 を入れる
  u8 shown[3];                                 // 0x328, 表示済みの values[], 変化した行だけ FUN_081db4b0 が貼り直す
  s8 shownStringIdx;                           // 0x32B, 表示済みの文字列番号, 同じなら FUN_081daff0 は引き直さない
  u8 unk_32c;                                  // 0x32C, Init で 1
  u8 cursor;                                   // 0x32D, 選択中の行 (0..2), 上下で巻き戻り、変わると FUN_081db1e8 がスプライトを動かす
  u16 timer;                                   // 0x32E, 30 未満の間は入力を受け付けない
} Entity08F4;
static_assert(sizeof(Entity08F4) == 816);

INCASM("asm/entity_08f4.inc");
