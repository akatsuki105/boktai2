#include "entity.h"
#include "global.h"
#include "sprite.h"

// _Init が5つ作り、_Update が FUN_08054960 を、_Destroy が FUN_08054930 を1つずつ呼ぶ, 中身はまだ未解析
typedef struct {
  u8 unk_0[0x0B];         // 0x000
  u8 unk_b;               // 0x00B, _Init が [0] に 1、[1] に 5 を書く
  u8 unk_c;               // 0x00C, _Init が [0] と [1] に 1 を書く
  u8 unk_d[0x18 - 0x0D];  // 0x00D
  u32 unk_18;             // 0x018, _Init が [0] と [1] に 0 を書く
  u8 unk_1c[388 - 0x1C];  // 0x01C
} Entity5645Elem;
static_assert(sizeof(Entity5645Elem) == 388);

// おそらく ゲームの周回数が偶数のときに遊べる ミニゲーム"ブラックパンサー" のシーン用Entity
typedef struct {
  Entity e;                      // 0x0000, ENTITY_UNK_11
  s32 frameCounter;              // 0x0018, _Update が毎フレーム +1
  s32 unk_1c;                    // 0x001C, '.p=0'
  u32 unk_20;                    // 0x0020, _Init が 3
  u32 unk_24;                    // 0x0024, _Init が 200
  u32 unk_28;                    // 0x0028, _Init が 200
  s32 sunGauge;                  // 0x002C, _Update が毎フレーム gStat->sunGauge を写す
  u8 unk_30;                     // 0x0030
  u8 unk_31;                     // 0x0031, _Update が 0 まで減らし、0 になった瞬間 FUN_08054ae4 を呼ぶ
  u8 unk_32[0x3C - 0x32];        // 0x0032
  u32 unk_3c;                    // 0x003C, _Update が下位16bitを gStat+0x3B0 へ写す
  u8 unk_40[0x44 - 0x40];        // 0x0040
  s16 unk_44;                    // 0x0044, 0/1/2, unk_50 の大小で決まり、変わると SE 0x28B が鳴って auxSprites1 の表示が切り替わる
  u16 unk_46;                    // 0x0046, _Init が 0
  u8 unk_48[0x4C - 0x48];        // 0x0048
  u32 unk_4c;                    // 0x004C, _Init が 0
  u32 unk_50;                    // 0x0050, _Update が 30 と 100 と比べて unk_44 を決める
  u32 unk_54;                    // 0x0054, _Update が下位16bitを gStat+0x3B2 へ写す
  u32 unk_58;                    // 0x0058, 1 で画面を明転, 2 で暗転 (gObjBrightness を 4 ずつ動かす), 終わると 0 に戻る
  u32 unk_5c;                    // 0x005C, _Init が 0
  Vec3 pos;                      // 0x0060, '.c', FUN_0823b8ac に渡す
  MainSpriteGfx gfx[7];          // 0x0068, sDAT_085ab750 が 2 の要素だけ
  Entity5645Elem elems[5];       // 0x0148
  u8 unk_8dc[0x17DC - 0x8DC];    // 0x08DC, この family が触らない領域, 残り63関数の担当
  AuxAnimFile* animFiles[4];     // 0x17DC, ANIM_871C / ANIM_5BB7 / ANIM_62C7 / ANIM_6830
  AuxSpriteGfx auxGfx1;          // 0x17EC, SPRITE_EFF_1C1B, plttID に 0x7584 を入れ、パレットを pltt に向ける
  rgb555 pltt[16];               // 0x1808, _Init が全部 0x5294 で埋める
  MainSpriteGfx mainGfx;         // 0x1828, SPRITE_UI_START_MENU
  MainSprite mainSprites1[4];    // 0x1848, metaspriteIdx 30 で登録
  MainSprite mainSprites2[4];    // 0x19C8, 同上だが最初は非表示
  MainSprite mainSprites3[3];    // 0x1B48, 同上
  AuxSpriteGfx auxGfx2;          // 0x1C68, SPRITE_PANTHER_BONUS, ブラックパンサー(ミニゲーム)用
  AuxSprite auxSprites1[6];      // 0x1C84, metaspriteIdx は 3,4,7,8,9,10, unk_44 に応じて表示が切り替わる
  AuxSpriteGfx auxGfx3;          // 0x1D8C, SPRITE_COMBO_SCORE, ブラックパンサー(ミニゲーム)用
  AuxSprite auxSprites2[2];      // 0x1DA8
  u8 unk_1e00[0x1E0C - 0x1E00];  // 0x1E00
  u32 unk_1e0c;                  // 0x1E0C, _Init が 2
  u32 unk_1e10;                  // 0x1E10, _Init が 4
  u32 unk_1e14;                  // 0x1E14, _Init が 6
  u32 unk_1e18;                  // 0x1E18, _Init が 50
  u32 unk_1e1c;                  // 0x1E1C, _Init が 500
} Entity5645;
static_assert(sizeof(Entity5645) == 7712);

void FUN_08055d7c(SpriteHolder* p);

INCRODATA(".rodata", "data/entity_5645.bin");  // ./tools/bin.ts ./baserom.gba 0x085ab748 0x085ab990 ./data/entity_5645.bin

INCRODATA(".rodata", "data/rodata.bin");  // ./tools/bin.ts ./baserom.gba 0x085ab990 0x085ABA70 ./data/rodata.bin

INCASM("asm/entity_5645.inc");
