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
  MainSpriteGfx gfx[7];          // 0x0068, Entity5645Entry.unk_08 が 2 の要素だけ
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

IWRAM_DATA Entity5645* gEntity5645 = NULL;  // 0x03000120

void FUN_08055d7c(SpriteHolder* p);

// 0x085AB748 の8件のテーブル, FUN_08054848 が 0x38 刻みで引く
typedef struct {
  SpriteID32 id;                                  // 0x00, Entity286F_FindSpriteData の第1引数
  s32 idx;                                        // 0x04, Entity286F_FindSpriteData の第2引数
  u32 unk_08;                                     // 0x08, FUN_080533ec に渡す, 2 の要素だけ Entity5645.gfx[] に入る
  u32 unk_0c;                                     // 0x0C, FUN_080533ec に渡す, SPRITE_MOUSE の要素だけ ANIM_AF44
  void (*fns[10])(Entity5645*, Entity5645Elem*);  // 0x10, FUN_08054960 が Entity5645Elem + 0x0D で引く
} Entity5645Entry;
static_assert(sizeof(Entity5645Entry) == 56);

void FUN_08053dac(Entity5645* p, Entity5645Elem* elem);
void FUN_08053dcc(Entity5645* p, Entity5645Elem* elem);
void FUN_08053dfc(Entity5645* p, Entity5645Elem* elem);
void FUN_08053e2c(Entity5645* p, Entity5645Elem* elem);
void FUN_08053e64(Entity5645* p, Entity5645Elem* elem);
void FUN_08053f44(Entity5645* p, Entity5645Elem* elem);
void FUN_08053fd0(Entity5645* p, Entity5645Elem* elem);
void FUN_08054054(Entity5645* p, Entity5645Elem* elem);
void FUN_080540d4(Entity5645* p, Entity5645Elem* elem);
void FUN_08054130(Entity5645* p, Entity5645Elem* elem);
void FUN_08054170(Entity5645* p, Entity5645Elem* elem);
void FUN_080541cc(Entity5645* p, Entity5645Elem* elem);
void FUN_080541fc(Entity5645* p, Entity5645Elem* elem);
void FUN_08054290(Entity5645* p, Entity5645Elem* elem);
void FUN_080542ac(Entity5645* p, Entity5645Elem* elem);
void FUN_0805431c(Entity5645* p, Entity5645Elem* elem);
void FUN_08054444(Entity5645* p, Entity5645Elem* elem);
void FUN_08054490(Entity5645* p, Entity5645Elem* elem);
void FUN_080544b4(Entity5645* p, Entity5645Elem* elem);
void FUN_08054520(Entity5645* p, Entity5645Elem* elem);
void FUN_08054670(Entity5645* p, Entity5645Elem* elem);
void FUN_08054698(Entity5645* p, Entity5645Elem* elem);
void FUN_08054700(Entity5645* p, Entity5645Elem* elem);
void FUN_0805474c(Entity5645* p, Entity5645Elem* elem);
void FUN_080547a8(Entity5645* p, Entity5645Elem* elem);
void FUN_080547f4(Entity5645* p, Entity5645Elem* elem);

// clang-format off
const Entity5645Entry Entity5645Entry_ARRAY_085ab748[8] = {
    {
        .id = SPRITE_KURO,
        .idx = 0,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {FUN_08053dac, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, FUN_08053e64, FUN_08053f44, FUN_08053fd0, FUN_080540d4, FUN_08054130, FUN_08054130},
    },
    {
        .id = SPRITE_DJANGO_SABATA,
        .idx = 0,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {FUN_08053dac, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, FUN_08053e64, FUN_08053f44, FUN_08053dcc, FUN_08053dac, FUN_08053dac, FUN_080541cc},
    },
    {
        .id = SPRITE_DJANGO_SABATA,
        .idx = 1,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {FUN_08053dac, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, FUN_08053e64, FUN_08053f44, FUN_08053dcc, FUN_08053dac, FUN_08053dac, FUN_080541fc},
    },
    {
        .id = SPRITE_RITA,
        .idx = 0,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {FUN_08053dac, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, FUN_08053e64, FUN_08053f44, FUN_08053dcc, FUN_08053dac, FUN_08053dac, FUN_080541fc},
    },
    {
        .id = SPRITE_ZAJI,
        .idx = 0,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {FUN_08053dac, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, FUN_08053e64, FUN_08053f44, FUN_08053dcc, FUN_08053dac, FUN_08053dac, FUN_080541fc},
    },
    {
        .id = SPRITE_SUMIRE,
        .idx = 0,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {FUN_08053dac, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, FUN_08053e64, FUN_08053f44, FUN_08053dcc, FUN_08053dac, FUN_08054170, FUN_080541fc},
    },
    {
        .id = SPRITE_LADY,
        .idx = 0,
        .unk_08 = 2,
        .unk_0c = 0,
        .fns = {FUN_08053dac, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, FUN_08053e64, FUN_08053f44, FUN_08053dcc, FUN_08053dac, FUN_08053dac, FUN_080541fc},
    },
    {
        .id = SPRITE_MOUSE,
        .idx = 0,
        .unk_08 = 1,
        .unk_0c = ANIM_AF44,
        .fns = {FUN_08053dac, FUN_08053dcc, FUN_08053dfc, FUN_08053e2c, FUN_08053e64, FUN_08053f44, FUN_08054054, FUN_08053dac, FUN_08053dac, FUN_08053dac},
    },
};  // 0x085AB748
// clang-format on

// 何かのIDの並びに見えるが特定できていない
const u16 u16_ARRAY_085ab908[5] = {0x6BDC, 0xF450, 0x094D, 0x6530, 0x2803};  // 0x085AB908

// FUN_08054848 が Entity5645Entry_ARRAY_085ab748 と同じ添字で引く, 9件目は未使用
const u16 u16_ARRAY_085ab912[9] = {250, 350, 350, 350, 350, 300, 350, 250, 0};  // 0x085AB912

// 推測: {u8, u8, u16} の12組
const u8 u8_ARRAY_085ab924[48] = {
    0x01, 0x00, 0x20, 0x00, 0x01, 0x00, 0x1B, 0x00, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x10, 0x00, 0x01, 0x00, 0x0A, 0x00, 0x01, 0x00, 0x07, 0x00,
    0x03, 0x01, 0x89, 0x01, 0x02, 0x01, 0x13, 0x02, 0x02, 0x01, 0x0B, 0x00, 0x01, 0x00, 0x07, 0x00, 0x01, 0x00, 0x0A, 0x00, 0x02, 0x01, 0x02, 0x00,
};  // 0x085AB924

const u16 u16_ARRAY_085ab954[4] = {SPRITE_BOMB, SPRITE_BAT, SPRITE_BEE, 0};  // 0x085AB954

// FUN_08054960 が Entity5645Elem + 0x0B で引く
void (*const PTR_ARRAY_085ab95c[13])(Entity5645*, Entity5645Elem*) = {
    FUN_08054290,
    FUN_080542ac,
    FUN_0805431c,
    FUN_08054444,
    FUN_08054490,
    FUN_080544b4,
    FUN_08054520,
    FUN_08054670,
    FUN_08054698,
    FUN_08054700,
    FUN_0805474c,
    FUN_080547a8,
    FUN_080547f4,
};  // 0x085AB95C

INCASM("asm/entity_5645.inc");
