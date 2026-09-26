#include "entity.h"
#include "global.h"
#include "sprite.h"

struct EnemyDexModel;

typedef struct EntityC946 {
  Entity e;                           // 0x000, ENTITY_UNK_8
  s32 swayAngle;                      // 0x018, EntityC946_Update が毎フレーム model->swaySpeed を足し、>>5 して sin テーブルの角度にする
  u32 modelID;                        // 0x01C, sEnemyDexModels の添字, FUN_0820fe98 が入れる, _Init は 0x38 を超えていたら 0 に戻す
  u32 stateTimer;                     // 0x020, state に入ってからのフレーム数, FUN_0820f84c などが数え、state が変わると 0 に戻る
  u8 state;                           // 0x024, onLoad / onUpdate を持つ魔物だけが使う演出の段階 (FUN_0820f84c は 0..3)
  bool8 hidden;                       // 0x025, 1 の間は _Update が parts と subSprite を全部隠して何もしない, FUN_0820fea8 が 1、FUN_0820feb0 が 0
  u16 posOverridden;                  // 0x026, 非0なら pos を model->x / model->y で上書きしない, FUN_0820fe94 が入れる
  DexPreview parts[5];                // 0x028, スプライトの器, 単体の魔物は [0] だけ、多関節の魔物は sEnemyDexSegments に沿って5つ使う
  AuxSprite subSprite;                // 0x30C, model->subSprite が非0のときだけ出す重ね絵 (メタスプライト 5/6/7)
  AuxSpriteGfx subSpriteGfx;          // 0x338, _Init が Video_GetAuxSprite(EFF_1C1B) で作る
  Vec3 pos;                           // 0x354, model->x + 64, model->y + 88, FUN_0820feb8 が直接入れることもある
  u8 unk_35c[0x364 - 0x35C];          // 0x35C, 読み手も書き手も見つかっていない
  u16 poseBase;                       // 0x364, model->poseBase の写し, FUN_08055b5c の第2引数になる
  u8 frameIdx;                        // 0x366, FUN_0820efc4 が model->direction から作るコマ番号
  u8 hFlip;                           // 0x367, 同上の左右反転
  bool8 reloadRequested;              // 0x368, FUN_0820fe98 が立て、_Update が読み込み直して 0 に戻す
  u8 unk_369[0x370 - 0x369];          // 0x369, 読み手も書き手も見つかっていない
  const struct EnemyDexModel* model;  // 0x370, &sEnemyDexModels[modelID], 毎フレーム入れ直す
} EntityC946;
static_assert(sizeof(EntityC946) == 884);

INCASM("asm/entity_c946.inc");

NAKED s32 FUN_0820f9dc(EntityC946* p, s32 val) { INCFUNC("asm/func/FUN_0820f9dc.inc"); }

NAKED void FUN_0820fa80(EntityC946* p, s32 val) { INCFUNC("asm/func/FUN_0820fa80.inc"); }

NAKED void EntityC946_Update_Helper_0820fb20(EntityC946* p) { INCFUNC("asm/func/EntityC946_Update_Helper_0820fb20.inc"); }

NAKED s32 EntityC946_Update(EntityC946* p) { INCFUNC("asm/func/EntityC946_Update.inc"); }

NAKED s32 EntityC946_Destroy(EntityC946* p) { INCFUNC("asm/func/EntityC946_Destroy.inc"); }

NAKED s32 EntityC946_Init(EntityC946* p, u32 _) { INCFUNC("asm/func/EntityC946_Init.inc"); }

EntityC946* EntityC946_Create(u32 arg, u32 _) {
  EntityC946* p = CreateEntity(ENTITY_UNK_8, sizeof(EntityC946));
  if (p != NULL) {
    SetEntityRoutine(p, EntityC946_Update, EntityC946_Destroy);
    if (EntityC946_Init(p, arg) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

void FUN_0820fe94(EntityC946* p, u32 val) { p->posOverridden = val; }

// 多関節の魔物1体ぶんの、5枚のスプライトの並べ方
typedef struct {
  s8 offset[5][2];  // 0x00, [i][0] を pos.x に、[i][1] を pos.y に足して i 番目の器の座標にする
  u16 pose[5];      // 0x0A, i 番目の器に渡す FUN_08055b5c の第2引数, i == 0 だけ direction 由来の向きを伴う
} EnemyDexSegments;
static_assert(sizeof(EnemyDexSegments) == 20);

static const s32 sEnemyDexPageStarts[9] = {0, 7, 14, 21, 27, 34, 41, 48, 50};  // ページの先頭エントリ番号 (sEnemyDexPageEntryCounts の累積和), 0x085AF034
static const s32 sEnemyDexPageEntryCounts[9] = {7, 7, 7, 6, 7, 7, 7, 2, 7};    // ページごとのエントリ数(ビースト1,ビースト2,ビースト3,アンデット,シング1,シング2,ファントム1,ファントム2,イモータル), 合計57, 0x085AF058
static const s32 sEnemyDexCategoryCounts[5] = {21, 6, 14, 9, 7};               // 種族ごとのエントリ数 (ビースト,アンデット,シング,ファントム,イモータル), 0x085AF07C

// 魔物図鑑メニューの UI スプライトのポーズ番号, FUN_0820d6e4 が EnemyDexMenu+0x18C から5枚を登録するループで引く
static const u32 sEnemyDexUIPoses1[5] = {17, 18, 19, 20, 21};  // 0x085AF090

// 同上, EnemyDexMenu+0x36C から3枚
static const u32 sEnemyDexUIPoses2[3] = {1, 2, 3};  // 0x085AF0A4

// 多関節の魔物の節の並べ方, EnemyDexModel の 9 / 19 / 20 番の onLoad / onUpdate がそれぞれ [0] / [1] / [2] を名指しする
static const EnemyDexSegments sEnemyDexSegments[3] = {
    // 0x085AF0B0
    {{{0, -12}, {6, -10}, {12, -2}, {8, 6}, {0, 15}},    {0, 2, 2, 2, 1}},
    {{{-12, 0}, {0, -10}, {10, -1}, {16, 12}, {16, 27}}, {5, 6, 6, 6, 6}},
    {{{-12, 0}, {0, -10}, {10, 0}, {16, 15}, {16, 29}},  {8, 9, 9, 9, 9}},
};

typedef void EnemyDexModelFunc(EntityC946* p);

// EnemyDexModel.flags
typedef u8 EnemyDexModelFlags;
#define DEXFLAG_NO_ANIM (1 << 0)     // 0x01, animID を FUN_08055fbc に渡さない, 立っている件は animID も 0
#define DEXFLAG_SWAY (1 << 1)        // 0x02, swayAmplitude / swaySpeed で上下にゆれる
#define DEXFLAG_NO_REFRESH (1 << 2)  // 0x04, EntityC946_Update が毎フレームの向き・ポーズ更新をしない

// onLoad / onUpdate から呼ばれる, リンク順の都合で本体は enemy_dex.c 側にある
void FUN_0820f020(EntityC946* p);
void FUN_0820f130(EntityC946* p);
void FUN_0820f1e0(EntityC946* p);
void FUN_0820f310(EntityC946* p);
void FUN_0820f3e4(EntityC946* p);
void FUN_0820f4b4(EntityC946* p);
void FUN_0820f630(EntityC946* p);
void FUN_0820f700(EntityC946* p);

// 本体はこのファイルの INCASM の中にある
void FUN_0820f840(EntityC946* p);
void FUN_0820f84c(EntityC946* p);

// 魔物図鑑に1体を表示するための定義, EntityC946 が unk_1c 番目を引く
typedef struct EnemyDexModel {
  SpriteID16 id;                // 0x00
  u16 animFileID;               // 0x02, FUN_08055dac の第3引数, kind == 2 では常に 0 (MainSprite は 自身にアニメーションを持つので、animFileID は不要)
  u16 kind;                     // 0x04, 1: AuxSprite+AuxAnimState, 2: MainSprite
  u16 poseBase;                 // 0x06, EntityC946.poseBase に控え、FUN_08055b5c の第2引数になる
  u16 animID;                   // 0x08, FUN_08055fbc に渡す
  u8 direction;                 // 0x0A, FUN_0820efc4 が (コマ番号, 左右反転) に展開する向き
  EnemyDexModelFlags flags;     // 0x0B, see EnemyDexModelFlags
  EnemyDexModelFunc* onLoad;    // 0x0C, 非0なら既定のロード (FUN_0820f9dc) の代わりに呼ぶ
  EnemyDexModelFunc* onUpdate;  // 0x10, 非0なら毎フレーム呼ぶ
  s8 x;                         // 0x14, 表示位置, +64 して pos.x に入る
  s8 y;                         // 0x15, 表示位置, +88 して pos.y に入る
  u8 swayAmplitude;             // 0x16, ゆれの振幅, sin テーブルとの積を >>13 して y に足す
  u8 swaySpeed;                 // 0x17, ゆれの角速度, 毎フレーム swayAngle に積算し >>5 して角度にする
  s8 subX;                      // 0x18, 追加スプライトの x ずらし, FUN_0820fa80 のみ読む
  s8 subY;                      // 0x19, 追加スプライトの y ずらし, 同上
  u2_6 scaleX;                  // 0x1A, 2.6 固定小数 (64 が等倍)
  u2_6 scaleY;                  // 0x1B, 同上, 全70件で scaleX と同値
  u8 subSprite;                 // 0x1C, 0: 追加スプライトなし, 1/2/3 でメタスプライト 5/6/7 を重ねる
  u8 unused[3];                 // 0x1D, padding?
} EnemyDexModel;
static_assert(sizeof(EnemyDexModel) == 32);

// エンディングのスタッフロールでは クレジットと一緒にゲーム中に登場したキャラクター(主人公,NPC,ボス,雑魚)が表示されるが、ここに魔物図鑑での魔物表示と同じ処理を使っているのかもしれない
// それならば、0..56 までは魔物図鑑とスタッフロール共用で、 57以降はスタッフロールのためのものかも
static const EnemyDexModel sEnemyDexModels[70] = {
    {SPRITE_SPIDER,         0xB6EE, 1, 3,   143, 3,  0,                                    NULL,         NULL,         0,  0,   0,  0,  0,  4,  50, 50, 0}, // 0
    {SPRITE_SPIDER,         0xB6EE, 1, 3,   144, 3,  0,                                    NULL,         NULL,         0,  0,   0,  0,  0,  4,  50, 50, 0}, // 1
    {SPRITE_BEE,            0x62C7, 1, 1,   176, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 2
    {SPRITE_BEE,            0x62C7, 1, 1,   178, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 3
    {SPRITE_BEE,            0x62C7, 1, 1,   177, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 4
    {SPRITE_BAT,            0x5BB7, 1, 0,   610, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 5
    {SPRITE_BAT,            0x5BB7, 1, 0,   611, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 6
    {SPRITE_CROW,           0x7B03, 1, 0,   332, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 7
    {SPRITE_CROW,           0x7B03, 1, 0,   333, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   10, 32, 0,  16, 32, 32, 1}, // 8
    {SPRITE_WORM,           0xC102, 1, 0,   417, 10, DEXFLAG_NO_REFRESH,                   FUN_0820f1e0, FUN_0820f310, 0,  0,   0,  0,  0,  16, 64, 64, 0}, // 9
    {SPRITE_DOG,            0xF6E7, 1, 3,   501, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  0,  64, 64, 1}, // 10
    {SPRITE_DOG,            0xF6E7, 1, 3,   503, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  0,  64, 64, 1}, // 11
    {SPRITE_DOG,            0xF6E7, 1, 3,   502, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  0,  64, 64, 1}, // 12
    {SPRITE_DOG,            0xF6E7, 1, 3,   505, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  0,  64, 64, 1}, // 13
    {SPRITE_ROD,            0x99DD, 1, 0,   220, 0,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  0,  0,  0}, // 14
    {SPRITE_SHAIAN,         0x0000, 2, 12,  626, 3,  0,                                    NULL,         NULL,         8,  24,  0,  0,  -2, -3, 64, 64, 2}, // 15
    {SPRITE_OCTOPUS,        0xDCEB, 1, 0,   447, 0,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  0,  0,  0}, // 16
    {SPRITE_COCKATRICE,     0xDA5E, 1, 2,   506, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  6,  64, 64, 1}, // 17
    {SPRITE_COCKATRICE,     0xDA5E, 1, 8,   507, 3,  DEXFLAG_SWAY,                         NULL,         NULL,         4,  0,   10, 64, 0,  16, 64, 64, 1}, // 18
    {SPRITE_WORM,           0xC102, 1, 5,   418, 10, 0,                                    FUN_0820f3e4, FUN_0820f4b4, 0,  0,   0,  0,  0,  32, 64, 64, 0}, // 19
    {SPRITE_WORM,           0xC102, 1, 8,   419, 10, 0,                                    FUN_0820f630, FUN_0820f700, 0,  0,   0,  0,  0,  0,  0,  0,  0}, // 20
    {SPRITE_BOKU,           0x1DF8, 1, 8,   307, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  64, 64, 1}, // 21
    {SPRITE_BOKU,           0x1DF8, 1, 8,   308, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  64, 64, 1}, // 22
    {SPRITE_BOKU,           0x1DF8, 1, 8,   309, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  64, 64, 1}, // 23
    {SPRITE_MUMMY,          0xA4B2, 1, 1,   23,  3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  64, 64, 1}, // 24
    {SPRITE_MUMMY,          0xA4B2, 1, 1,   24,  3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  64, 64, 1}, // 25
    {SPRITE_MUMMY,          0xA4B2, 1, 1,   25,  3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  0,  64, 64, 1}, // 26
    {SPRITE_SKELETONS,      0x0000, 2, 6,   247, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  1,  64, 64, 1}, // 27
    {SPRITE_SKELETONS,      0x0000, 2, 8,   247, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  1,  64, 64, 1}, // 28
    {SPRITE_SKELETONS,      0x0000, 2, 10,  247, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  1,  64, 64, 1}, // 29
    {SPRITE_SKELETONS,      0x0000, 2, 6,   252, 3,  0,                                    NULL,         NULL,         0,  16,  0,  0,  0,  1,  64, 64, 1}, // 30
    {SPRITE_SKELETONS,      0x0000, 2, 26,  249, 3,  0,                                    NULL,         NULL,         8,  16,  0,  0,  0,  1,  64, 64, 1}, // 31
    {SPRITE_SKELETONS,      0x0000, 2, 26,  255, 3,  0,                                    NULL,         NULL,         8,  16,  0,  0,  0,  1,  64, 64, 1}, // 32
    {SPRITE_GOLEM,          0x1E38, 1, 1,   513, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  4,  64, 64, 1}, // 33
    {SPRITE_GOLEM,          0x1E38, 1, 1,   514, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  4,  64, 64, 1}, // 34
    {SPRITE_GOLEM,          0x1E38, 1, 1,   516, 3,  0,                                    NULL,         NULL,         0,  8,   0,  0,  0,  4,  64, 64, 1}, // 35
    {SPRITE_MIMIC,          0x9AF2, 1, 1,   650, 4,  DEXFLAG_NO_REFRESH,                   FUN_0820f840, FUN_0820f84c, 0,  16,  0,  0,  0,  4,  64, 64, 1}, // 36
    {SPRITE_SWORD_AX,       0x3F72, 1, 0,   301, 0,  DEXFLAG_SWAY | DEXFLAG_NO_REFRESH,    NULL,         NULL,         0,  2,   8,  40, 0,  28, 32, 32, 1}, // 37
    {SPRITE_SWORD_AX,       0x3F72, 1, 0,   302, 0,  DEXFLAG_SWAY | DEXFLAG_NO_REFRESH,    NULL,         NULL,         0,  2,   8,  40, 0,  28, 32, 32, 1}, // 38
    {SPRITE_SWORD_AX,       0x3F72, 1, 1,   301, 0,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  8,   10, 40, 0,  24, 32, 32, 1}, // 39
    {SPRITE_SWORD_AX,       0x3F72, 1, 1,   302, 0,  DEXFLAG_SWAY,                         NULL,         NULL,         0,  8,   10, 40, 0,  24, 32, 32, 1}, // 40
    {SPRITE_CURORO,         0x9607, 1, 0,   92,  10, DEXFLAG_SWAY,                         NULL,         NULL,         0,  -8,  20, 32, 0,  24, 32, 32, 1}, // 41
    {SPRITE_CURORO,         0x9607, 1, 0,   93,  10, DEXFLAG_SWAY,                         NULL,         NULL,         0,  -8,  20, 32, 0,  24, 32, 32, 1}, // 42
    {SPRITE_CURORO,         0x9607, 1, 0,   94,  10, DEXFLAG_SWAY,                         NULL,         NULL,         0,  -8,  20, 32, 0,  24, 32, 32, 1}, // 43
    {SPRITE_SLIME,          0xA929, 1, 1,   147, 3,  DEXFLAG_NO_REFRESH,                   NULL,         FUN_0820f130, 0,  8,   0,  0,  0,  8,  32, 32, 0}, // 44
    {SPRITE_SLIME,          0xA929, 1, 1,   148, 3,  DEXFLAG_NO_REFRESH,                   NULL,         FUN_0820f130, 0,  8,   0,  0,  0,  8,  32, 32, 0}, // 45
    {SPRITE_SLIME,          0xA929, 1, 1,   149, 3,  DEXFLAG_NO_REFRESH,                   NULL,         FUN_0820f130, 0,  8,   0,  0,  0,  8,  32, 32, 0}, // 46
    {SPRITE_SLIME,          0xA929, 1, 1,   150, 3,  DEXFLAG_NO_REFRESH,                   NULL,         FUN_0820f130, 0,  8,   0,  0,  0,  8,  32, 32, 0}, // 47
    {SPRITE_GHOST,          0x29FB, 1, 0,   381, 10, DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   20, 32, 0,  24, 64, 64, 1}, // 48
    {SPRITE_GHOST,          0x29FB, 1, 0,   382, 10, DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   20, 32, 0,  24, 64, 64, 1}, // 49
    {SPRITE_DUNEYRR,        0x0000, 2, 0,   0,   0,  DEXFLAG_NO_ANIM | DEXFLAG_SWAY,       NULL,         NULL,         0,  0,   8,  32, 0,  0,  0,  0,  0}, // 50
    {SPRITE_RINGO,          0x0000, 2, 3,   0,   4,  DEXFLAG_NO_ANIM | DEXFLAG_SWAY,       NULL,         NULL,         4,  16,  8,  32, 0,  8,  64, 64, 2}, // 51
    {SPRITE_DURATHROR,      0x0000, 2, 0,   0,   0,  DEXFLAG_NO_ANIM | DEXFLAG_NO_REFRESH, NULL,         FUN_0820f020, 0,  16,  0,  0,  0,  0,  0,  0,  0}, // 52
    {SPRITE_DVALINN,        0x0000, 2, 0,   0,   3,  DEXFLAG_NO_ANIM | DEXFLAG_SWAY,       NULL,         NULL,         0,  15,  8,  32, 0,  0,  0,  0,  0}, // 53
    {SPRITE_RINGO,          0x0000, 2, 8,   0,   4,  DEXFLAG_NO_ANIM | DEXFLAG_SWAY,       NULL,         NULL,         4,  16,  8,  32, 0,  8,  64, 64, 2}, // 54
    {SPRITE_JORMUNGANDR,    0x0000, 2, 0,   0,   0,  DEXFLAG_NO_ANIM | DEXFLAG_SWAY,       NULL,         NULL,         24, -24, 8,  32, 0,  0,  0,  0,  0}, // 55
    {SPRITE_SHADEMAN,       0x0000, 2, 0,   0,   10, DEXFLAG_NO_ANIM | DEXFLAG_SWAY,       NULL,         NULL,         0,  16,  8,  32, 0,  8,  64, 64, 2}, // 56
    {SPRITE_DJANGO_SABATA,  0x0000, 2, 5,   29,  10, 0,                                    NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 57
    {SPRITE_OTNK,           0xC6A0, 1, 0,   0,   10, DEXFLAG_NO_ANIM | DEXFLAG_SWAY,       NULL,         NULL,         0,  0,   8,  32, 0,  8,  64, 64, 1}, // 58
    {SPRITE_DJANGO_SABATA,  0x0000, 2, 419, 39,  10, 0,                                    NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 59
    {SPRITE_RITA,           0x0000, 2, 5,   0,   3,  DEXFLAG_NO_ANIM,                      NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 60
    {SPRITE_ZAJI,           0x0000, 2, 5,   0,   3,  DEXFLAG_NO_ANIM,                      NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 61
    {SPRITE_SHAIAN,         0x0000, 2, 14,  0,   3,  DEXFLAG_NO_ANIM,                      NULL,         NULL,         8,  24,  0,  0,  -2, -3, 64, 64, 2}, // 62
    {SPRITE_LADY,           0x0000, 2, 7,   0,   3,  DEXFLAG_NO_ANIM,                      NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 63
    {SPRITE_COFFIN,         0x3D95, 1, 32,  524, 10, 0,                                    NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 64
    {SPRITE_SHADEMAN,       0x0000, 2, 0,   15,  10, DEXFLAG_SWAY,                         NULL,         NULL,         0,  0,   8,  32, 0,  8,  64, 64, 2}, // 65
    {SPRITE_KID,            0x0000, 2, 7,   0,   3,  DEXFLAG_NO_ANIM,                      NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 66
    {SPRITE_SUMIRE,         0x0000, 2, 5,   0,   3,  DEXFLAG_NO_ANIM,                      NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 67
    {SPRITE_SMITH_MARCELLO, 0x0000, 2, 7,   0,   3,  DEXFLAG_NO_ANIM,                      NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 68
    {SPRITE_DJANGO_SABATA,  0x0000, 2, 204, 38,  10, 0,                                    NULL,         NULL,         0,  0,   0,  0,  0,  2,  64, 64, 1}, // 69
};
