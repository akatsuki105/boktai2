#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "save.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "time.h"
#include "vec3.h"
#include "video.h"
#include "vm.h"

// '.I' が並べる1件, count 個ぶんだけ3つの配列が埋まる
typedef struct {
  s8 id;              // 0x00, -1 なら打ち切り
  s8 count;           // 0x01, 続く3つの配列の要素数
  s16 prefecture[5];  // 0x02, gSystemSaveData->prefecture に書く地域
  s32 longitude[5];   // 0x0C, Time_SetLocation の経度
  s32 latitude[5];    // 0x20, Time_SetLocation の緯度
} EntityA288Entry;
static_assert(sizeof(EntityA288Entry) == 52);

// 地域を選ぶ画面, 関数は先頭へのポインタを持ってから各メンバを引く
typedef struct {
  MainSprite sprite_00;         // 0x000
  MainSprite cursor;            // 0x060, prefIdx * 16 の高さに置く
  EntityA288Entry entries[30];  // 0x0C0, '.I' から読む
  s32 windowIDs[5];             // 0x6D8
  u8* unk_6ec;                  // 0x6EC, '.a'
  u8* unk_6f0;                  // 0x6F0, '.I' の先頭
  s16 areaIdx;                  // 0x6F4, 選んでいる entries の添字 - 1
  s16 entryCount;               // 0x6F6, 読めた entries の個数 - 1
  s16 prefCount;                // 0x6F8, entries[areaIdx + 1].count の控え
  s16 prefIdx;                  // 0x6FA, entries[areaIdx + 1] の中で選んでいる地域の添字
} EntityA288AreaSelect;
static_assert(sizeof(EntityA288AreaSelect) == 0xDBC - 0x6C0);

// サウンドテストの画面 (BGM / SE / ボイスの3つの番号を選んで鳴らす), 関数は先頭へのポインタを持ってから各メンバを引く
typedef struct {
  MainSprite sprites[2];    // 0x000, [0] はカーソル (アニメ 7), [1] は unk_424 行目の見出し
  MainSprite icons[3];      // 0x0C0, BGM / SE / ボイスが鳴っている間だけ出す
  MainSprite digits[2][3];  // 0x1E0, digits[n][2] が n 番目の番号の1の位
  u8* unk_420;              // 0x420, '.b'
  s32 unk_424;              // 0x424, 選んでいる行, 32倍したものが sprites[0] の縦位置, +0x4B が sprites[1] のポーズ番号
  s16 bgmCount;             // 0x428, u16_ARRAY_085afa30 の曲数
  s16 seCount;              // 0x42A, u16_ARRAY_085afaee の効果音数
  s16 voiceCount;           // 0x42C, u16_ARRAY_085afeb2 のボイス数
  s16 unk_42e;              // 0x42E, '.b' の参照先に足す文字列IDのオフセット
  s16 unk_430;              // 0x430, digits[0] に3桁で出す数
  s16 unk_432;              // 0x432, digits[1] に3桁で出す数
  s16 playing[3];           // 0x434, 最後に鳴らした BGM / SE / ボイスの添字
  u8 unk_43a[2];            // 0x43A, まだ未解析
} EntityA288SoundTest;
static_assert(sizeof(EntityA288SoundTest) == 0x12C8 - 0xE8C);

// 文字入力の画面, 関数は先頭へのポインタを持ってから各メンバを引く
typedef struct {
  MainSprite sprites[3];  // 0x000
  u8* unk_120;            // 0x120, '.p' の PC
  u8* unk_124;            // 0x124, '.S'
  u8* unk_128;            // 0x128, '.P' の PC
  u8* unk_12c;            // 0x12C, '.N' の PC
  u8* unk_130;            // 0x130, '.H'
  u8* unk_134;            // 0x134, '.K'
  u8 lines[4][256];       // 0x138, 行ごとに組み立てた文字列
  u8 text[1024];          // 0x538, lines を順に連結したもの
  u8 text_938[32];        // 0x938
  s8 chars[24];           // 0x958, 1文字ずつ積む入力中の文字列
  s16 len;                // 0x970, chars に積んだ文字数, 0x16 を超えると打ち切る
  s16 unk_972;            // 0x972, sprites[2] の横位置を選ぶ添字
  s16 unk_974;            // 0x974, 0 / 1 を切り替えて BG2 のレイヤーにする
  s16 unk_976;            // 0x976, 状態, 0: 初期化 1: 入力中 2: 確定
  s16 unk_978;            // 0x978
  s16 unk_97a;            // 0x97A
} EntityA288TextInput;
static_assert(sizeof(EntityA288TextInput) == 0x1FE8 - 0x166C);

// 0x78 から始まる画面, 関数は先頭へのポインタを持ってから各メンバを引く
typedef struct {
  MainSpriteGfx gfx;  // 0x000
  MainSprite sprite;  // 0x020
  Tilemaps* tilemap;  // 0x080, TILEMAP_A413
  rgb555* bgp;        // 0x084, BGP_EFDA[208]
  s32 windowID;       // 0x088
  s16 unk_8c;         // 0x08C, 1 なら sprite を出す
  s16 unk_8e;         // 0x08E, +4 したものを sprite のアニメ番号にする
  u32 unk_90;         // 0x090
} EntityA288Sub78;
static_assert(sizeof(EntityA288Sub78) == 0x10C - 0x78);

// 0x10C から始まる画面, 関数は先頭へのポインタを持ってから各メンバを引く
typedef struct {
  MainSprite sprites[2];  // 0x000
  u8* unk_c0;             // 0x0C0, '.s'
  u32 unk_c4;             // 0x0C4
  u16 unk_c8;             // 0x0C8
  u16 unk_ca;             // 0x0CA
} EntityA288Sub10C;
static_assert(sizeof(EntityA288Sub10C) == 0x1D8 - 0x10C);

// 0x1D8 から始まる画面, 関数は先頭へのポインタを持ってから各メンバを引く
typedef struct {
  MainSprite sprites[12];  // 0x000
  MainSprite sprite_480;   // 0x480
  s32 year;                // 0x4E0, Time_GetDate の年を10進にしたもの
  u8 month;                // 0x4E4
  u8 day;                  // 0x4E5
  u8 hour;                 // 0x4E6
  u8 minute;               // 0x4E7
} EntityA288Sub1D8;
static_assert(sizeof(EntityA288Sub1D8) == 0x6C0 - 0x1D8);

// 0xDBC から始まる画面, 関数は先頭へのポインタを持ってから各メンバを引く
typedef struct {
  MainSprite sprites[2];  // 0x000
  s32 unk_c0;             // 0x0C0, 24倍して sprites[0] の縦位置にする
  u8* unk_c4;             // 0x0C4, '.X'
  s32 unk_c8;             // 0x0C8, '.X' の参照先に足す文字列IDのオフセット, gStat->unk_944 にも写す
  u32 unk_cc;             // 0x0CC, '.E'
} EntityA288SubDBC;
static_assert(sizeof(EntityA288SubDBC) == 0xE8C - 0xDBC);

// 0x12C8 から始まる画面, 関数は先頭へのポインタを持ってから各メンバを引く
typedef struct {
  MainSpriteGfx gfx;          // 0x000, SPRITE_PORTRAITS
  MainSprite sprite_20;       // 0x020
  MainSprite sprite_80;       // 0x080
  MainSprite sprites_e0[5];   // 0x0E0
  MainSprite sprites_2c0[2];  // 0x2C0
  s32 windowIDs[2];           // 0x380
  u8* unk_388;                // 0x388, '.g'
  u8* unk_38c;                // 0x38C, '.T'
  u8* unk_390;                // 0x390, '.A'
  s16 unk_394;                // 0x394, gStat->unk_93a が 0 なら 1, そうでなければ 0
  s16 unk_396;                // 0x396, FUN_08218e4c が 0 を入れる
  s32 unk_398;                // 0x398, 暗転が終わったあとに移るサブ state
  s32 unk_39c;                // 0x39C, BGM のフェードが終わったあとに移るサブ state
  s32 unk_3a0;                // 0x3A0, 0 ならタイトルの BGM をまだ鳴らしていない
} EntityA288Sub12C8;
static_assert(sizeof(EntityA288Sub12C8) == 0x166C - 0x12C8);

// タイトル画面で、 "GAME START" or "OPTION" を選んだ後に生成される "LINK" は別
typedef struct EntityA288 {
  Entity e;                                    // 0x0000, ENTITY_UNK_11
  MainSpriteGfx gfx;                           // 0x0018, SPRITE_42E2
  Tilemaps* tilemap;                           // 0x0038, TILEMAP_33B2
  rgb555* pltt;                                // 0x003C, BGP_E9C3
  s32 kind;                                    // 0x0040, '.t', 初期 state を選ぶ
  u32 flags;                                   // 0x0044, bit0 / bit1 が立っている間は timer1 / timer2 を止める
  u32 unk_48;                                  // 0x0048, '.f'
  u32 unk_4c;                                  // 0x004C, '.l'
  u32 unk_50;                                  // 0x0050, '.e'
  s32 state;                                   // 0x0054, 0x085AFF84 の関数表の添字
  s32 timer1;                                  // 0x0058, flags bit0 が落ちている間 _Update が 1 足す
  s32 unk_5c;                                  // 0x005C, EntityA288_SetState が 0 に戻す
  s32 timer2;                                  // 0x0060, flags bit1 が落ちている間 _Update が 1 足す
  s32 unk_64;                                  // 0x0064, _Init が -1 を入れる
  s32 unk_68;                                  // 0x0068, _Init が 0 を入れる
  s32 unk_6c;                                  // 0x006C, 上下キーを押し続けたフレーム数, unk_68 の縦版
  s32 fade[2];                                 // 0x0070, FUN_0821b21c の作業領域, [0] が明るさ, [1] が経過フレーム
  EntityA288Sub78 sub78;                       // 0x0078
  EntityA288Sub10C sub10c;                     // 0x010C
  EntityA288Sub1D8 sub1d8;                     // 0x01D8
  EntityA288AreaSelect area;                   // 0x06C0
  EntityA288SubDBC subdbc;                     // 0x0DBC
  EntityA288SoundTest soundTest;               // 0x0E8C
  EntityA288Sub12C8 sub12c8;                   // 0x12C8
  EntityA288TextInput input;                   // 0x166C
  void (*updateCallback)(struct EntityA288*);  // 0x1FE8
} EntityA288;
static_assert(sizeof(EntityA288) == 8172);

const __attribute__((section(".rodata.faraddr"))) u8 u8_ARRAY_08252780[96] = {
    0x30, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x70, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA0, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA8, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x50, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x58, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x88, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
};

const __attribute__((section(".rodata.faraddr"))) u8 u8_ARRAY_082527e0[8] = {0x00, 0x10, 0x20, 0x30, 0x40, 0xFF, 0xFF, 0xFF};
const __attribute__((section(".rodata.faraddr"))) u8 u8_ARRAY_082527e8[8] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0xFF, 0xFF};
const __attribute__((section(".rodata.faraddr"))) u8 u8_ARRAY_082527f0[12] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x70, 0x80, 0x90, 0xA0, 0xB0, 0xC0};
const __attribute__((section(".rodata.faraddr"))) u8 u8_ARRAY_082527fc[8] = {0x02, 0x03, 0x10, 0x03, 0x02, 0x05, 0x10, 0x05};
const __attribute__((section(".rodata.faraddr"))) u8 u8_ARRAY_08252804[8] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70};
const __attribute__((section(".rodata.faraddr"))) u8 u8_ARRAY_0825280c[6] = {0x00, 0x10, 0x20, 0x30, 0x40, 0x50};

const __attribute__((section(".rodata.faraddr"))) u32 u32_ARRAY_08252814[3] = {0, 3, 1};
const __attribute__((section(".rodata.faraddr"))) u8 u8_ARRAY_08252820[36] = {27, 23, 20, 9, 26, 1, 10, 23, 31, 1, 1, 1, 12, 9, 26, 19, 1, 10, 23, 31, 1, 1, 1, 1, 30, 9, 21, 24, 17, 26, 13, 1, 10, 23, 31, 1};  // 0x08252820
const __attribute__((section(".rodata.faraddr"))) char gStringSabata_08252844[10] = _("サバタ");                                                                                                                  // 0x08252844
const __attribute__((section(".rodata.faraddr"))) u32 u32_ARRAY_08252850[5] = {0, 4, 5, 6, 2};                                                                                                                    // 0x08252850

// clang-format off
const SoundID16 u16_ARRAY_085afa30[95] = {
    SONG_163,             SONG_167,        SONG_164,        SONG_179,     SONG_56,
    SONG_18,              SONG_62,         SONG_57,         BGM_PROLOGUE, SONG_19,
    SONG_165,             BGM_TRAP_BATTLE, BGM_COMPLETE,    SONG_59,      SONG_152,
    BGM_15,               SONG_54,         BGM_GAMEOVER,    SONG_156,     SONG_66,
    SONG_154,             SONG_160,        SONG_161,        SONG_162,     SONG_20,
    SONG_68,              SONG_21,         SONG_22,         SONG_23,      SONG_69,
    SONG_24,              SONG_70,         SONG_65,         SONG_150,     SONG_151,
    BGM_PILEDRIVER_POINT, BGM_BOSS_BATTLE, BGM_BOSS_CLIMAX, BGM_10,       SONG_74,
    SONG_170,             SONG_169,        SONG_25,         SONG_26,      SONG_178,
    SONG_71,              SONG_27,         SONG_28,         SONG_60,      SONG_76,
    SONG_81,              SONG_153,        SONG_29,         SONG_77,      SONG_32,
    SONG_30,              SONG_33,         SONG_31,         SONG_80,      SONG_155,
    SONG_82,              SONG_159,        SONG_84,         SONG_157,     BGM_16,
    BGM_14,               SONG_34,         SONG_181,        SONG_35,      SONG_64,
    SONG_36,              SONG_39,         SONG_37,         SONG_83,      SONG_41,
    SONG_42,              SONG_61,         SONG_48,         SONG_17,      SONG_72,
    SONG_43,              SONG_44,         SONG_45,         SONG_46,      SONG_47,
    BGM_SUNMIGUERE,       SONG_88,         SONG_90,         SONG_166,     SONG_168,
    SONG_176,             SONG_177,        SONG_180,        SONG_173,     -1,
};  // 0x085afa30
// clang-format on

// clang-format off
const SoundID16 u16_ARRAY_085afaee[482] = {
    SONG_224,             SONG_223,              SE_CURSOR_MOVE,  SE_SELECT,                SE_CANCEL,
    SE_SAVE_SUCCESS,      SE_UNK_299,            SE_UNK_300,      SE_UNK_301,               SONG_410,
    SE_NG,                SONG_662,              SONG_660,        SONG_677,                 SONG_266,
    SONG_267,             SE_SLOT,               SE_SWAP_SLOT,    SE_HEAL,                  SE_TRASH,
    SE_WEAPON_BREAK,      SE_OPEN_MENU,          SE_CLOSE_MENU,   SE_CHOICE,                SONG_540,
    SE_359,               SONG_225,              SONG_227,        SONG_227,                 SONG_226,
    SONG_570,             SONG_571,              SONG_572,        SONG_573,                 SONG_574,
    SONG_651,             SONG_629,              SONG_630,        SE_FSTEP_M_0,             SE_FSTEP_M_1,
    SE_FSTEP_STAIRS_0,    SE_FSTEP_STAIRS_1,     SONG_354,        SONG_355,                 SONG_403,
    SONG_404,             SONG_199,              SONG_200,        SONG_821,                 SONG_208,
    SONG_219,             SONG_236,              SONG_235,        SONG_203,                 SONG_908,
    SONG_907,             SONG_911,              SONG_909,        SONG_912,                 SONG_910,
    SONG_913,             SE_GUN_FIRE,           SONG_213,        SE_GUN_AIM,               SE_GUN_MISFIRE,
    SE_GUN_CHARGED,       SONG_425,              SONG_426,        SE_ENCHANT,               SE_HEALING,
    SONG_920,             SONG_921,              SONG_922,        SE_TRANSFORM,             SONG_924,
    SE_CHANGE_WOLF,       SE_CHANGE_BAT,         SE_CHANGE_MOUSE, SE_506,                   SONG_507,
    NOISE_SOLAR_CHARGE,   SE_SOLAR_STAND_DENY,   SE_DENY_302,     SONG_357,                 SE_DAMAGE,
    SONG_209,             SONG_680,              SE_SOLIDIFY,    SE_308,                   SE_IGNITE,
    SE_CONFUSE,           SONG_433,              SONG_492,        SONG_493,                 SONG_218,
    SONG_210,             SONG_211,              SONG_682,        SONG_384,                 SONG_385,
    SONG_386,             SONG_494,              SONG_822,        SONG_637,                 SONG_638,
    SONG_639,             SONG_644,              SONG_645,        SONG_601,                 SE_WOOD_DOOR_427,
    SONG_428,             SONG_430,              SONG_431,        SONG_432,                 SONG_636,
    SE_INFO,              SE_UNK_287,            SONG_602,        SE_FSTEP_F_0,             SE_FSTEP_F_1,
    SONG_807,             SONG_513,              SONG_514,        SONG_515,                 SONG_671,
    SONG_516,             SONG_569,              SONG_664,        SONG_925,                 SONG_509,
    SONG_510,             SONG_525,              SONG_527,        SONG_605,                 SONG_526,
    SONG_917,             SONG_541,              SONG_809,        SE_808,                   SONG_542,
    SONG_799,             SONG_800,              SONG_801,        SONG_802,                 SONG_803,
    SE_ENEMY_DAMAGED,     SONG_529,              SONG_316,        SONG_935,                 SONG_936,
    SONG_937,             SONG_938,              SONG_939,        CRY_SKELETON_DEATH,                 SONG_941,
    SONG_942,             SONG_944,              SONG_945,        SONG_946,                 SONG_947,
    CRY_DOG_DETECT,             CRY_DOG_ALERT,              SONG_933,        CRY_DOG_DEATH,                 SONG_959,
    CRY_SLIME_DEATH,             SONG_961,              SONG_962,        SONG_963,                 SONG_964,
    SONG_969,             SONG_966,              SONG_967,        SE_BEE_968,               CRY_BEE_DEATH,
    SONG_971,             SONG_972,              CRY_GHOST_DEATH,        SONG_412,                 CRY_CENTIPEDE_DEATH,
    SONG_982,             SONG_983,              SONG_411,        SONG_985,                 SONG_986,
    SONG_987,             SONG_988,              SONG_994,        SONG_995,                 SONG_421,
    SONG_996,             SONG_998,              SONG_413,        SONG_418,                 SONG_419,
    SONG_990,             SONG_991,              SONG_992,        SONG_993,                 SONG_436,
    SONG_997,             SONG_999,              SONG_414,        SONG_420,                 CRY_BOKU_DAMAGED,
    SONG_237,             SONG_238,              CRY_BOKU_DEATH,        SONG_229,                 SONG_214,
    SONG_242,             CRY_BOKU_DETECT,       CRY_BOKU_ALERT,  CRY_BOKU_QUESTION,        SE_UNK_298,
    SE_669,              SONG_685,              CRY_CURORO_DEATH,        SONG_234,                 SONG_813,
    SONG_264,             CRY_BAT_DEATH,              SONG_246,        SONG_247,                 SONG_265,
    CRY_CROW_DEATH,             CRY_MUMMY_DAMAGED,    SE_UNK_254,      CRY_MUMMY_255,            CRY_MUMMY_DEATH,
    CRY_MUMMY_257,        CRY_MUMMY_DETECT,         CRY_MUMMY_ALERT,   CRY_MUMMY_QUESTION,            CRY_MUMMY_BURN,
    SONG_358,             SONG_405,              SE_UNK_274,      CRY_SPIDER_DEATH,               SE_UNK_276,
    SE_UNK_277,           SONG_361,              SONG_362,        SONG_363,                 SONG_364,
    SONG_365,             SONG_366,              SONG_367,        SONG_368,                 SONG_399,
    SONG_400,             SONG_482,              CRY_GOLEM_DETECT,   CRY_GOLEM_ALERT,          CRY_GOLEM_391,
    SONG_392,             SONG_393,              SONG_394,        SONG_395,                 SONG_397,
    SONG_398,             SONG_434,              SONG_435,        CRY_MIMIC_ALERT,                 CRY_MIMIC_QUESTION,
    CRY_TENTACLE_DEATH,             SONG_472,              SONG_473,        SONG_476,                 SONG_477,
    SONG_478,             SONG_475,              SONG_479,        SONG_480,                 SONG_481,
    SONG_470,             CRY_COCKA_455,              CRY_COCKA_456,        CRY_COCKA_457,                 CRY_COCKA_DEATH,
    SONG_459,             SONG_461,              SONG_462,        SONG_463,                 SONG_464,
    SONG_465,             SONG_468,              SONG_469,        SONG_483,                 SONG_484,
    SONG_485,             SE_511,                SONG_608,        SONG_249,                 SONG_250,
    SE_UNK_294,           SONG_407,              SONG_832,        SONG_831,                 SE_PILEDRIVER_07,
    SE_GENERATOR_ENABLED, SE_GENERATOR_DISABLED, SONG_245,        SONG_243,                 SONG_244,
    SE_UNK_297,           SONG_490,              SONG_491,        SE_OPEN_TREASURE,         SE_PICKUP,
    SE_EQUIP,             SE_UNK_291,            SONG_387,        SONG_623,                 SONG_668,
    SONG_679,             SONG_695,              SE_UNK_290,      SE_SOLAR_INSECT_285,      SONG_696,
    SONG_657,             SONG_658,              SONG_659,        SE_UNK_282,               SE_SPIRIT_BUGS_283,
    SE_SPIRIT_BUGS_284,   SE_WOOD_DOOR_OPEN,              SE_WOOD_DOOR_CLOSE,        SONG_655,                 SONG_388,
    SONG_322,             SE_BLOCK_COLLISION,    SE_326,          SONG_337,                 SONG_347,
    SONG_336,             SONG_330,              SONG_334,        SONG_335,                 SONG_310,
    SONG_348,             SONG_329,              SONG_615,        SONG_532,                 SONG_533,
    SONG_534,             SONG_535,              SE_536,          SE_537,                   SE_538,
    SE_539,               SONG_341,              SONG_338,        SONG_339,                 SONG_340,
    SONG_320,             SONG_321,              SONG_339,        SONG_332,                 SONG_333,
    SONG_370,             SONG_691,              SONG_424,        SONG_806,                 SONG_646,
    SONG_531,             SONG_546,              SONG_344,        SONG_345,                 SONG_609,
    SONG_610,             SONG_611,              SONG_649,        SONG_650,                 SONG_648,
    SONG_642,             SONG_614,              SONG_543,        SONG_544,                 SONG_415,
    SONG_416,             SONG_567,              SONG_681,        SONG_547,                 SONG_350,
    SONG_408,             SONG_409,              SONG_351,        SONG_352,                 SONG_487,
    SONG_815,             SONG_612,              SONG_613,        SONG_641,                 SONG_453,
    SONG_451,             SONG_454,              SONG_452,        SONG_950,                 SONG_951,
    SONG_963,             SONG_952,              SONG_958,        SONG_954,                 SONG_955,
    SONG_957,             SE_838,                SONG_839,        SONG_840,                 SONG_841,
    SE_842,               SE_843,                SONG_844,        SE_846,                   SE_UNK_849,
    SE_UNK_850,           SE_UNK_851,            SE_UNK_852,      SONG_827,                 SONG_835,
    SONG_812,             SONG_837,              SONG_818,        SONG_819,                 SONG_828,
    NOISE_SMOKE,          SONG_973,              SONG_974,        SONG_975,                 SONG_976,
    SONG_977,             SONG_978,              SONG_979,        SONG_327,                 SE_373,
    SE_375,               SONG_376,              SONG_377,        SE_378,                   SE_382,
    SONG_440,             SONG_441,              SONG_442,        SONG_443,                 SONG_444,
    SONG_555,             NOISE_UNK_113,         SONG_445,        SONG_548,                 SONG_549,
    SONG_550,             SONG_551,              SONG_552,        SONG_553,                 SONG_554,
    SONG_555,             SONG_556,              SONG_557,        CRY_JORMY_TONGUE_DAMAGED, SONG_559,
    SONG_560,             SONG_561,              SONG_564,        SONG_562,                 SONG_563,
    NOISE_HEARTBEAT,      SONG_805,              NOISE_UNK_111,   SONG_882,                 SONG_883,
    SONG_508,             SONG_867,              SONG_868,        SONG_101,                 SONG_131,
    NOISE_SIZZLE,         SOUND_103,             NOISE_CHICKEN,   NOISE_CROW,               NOISE_QUAKE,
    SONG_132,             -1,
};  // 0x085afaee
// clang-format on

// clang-format off
const SoundID16 u16_ARRAY_085afeb2[99] = {
    SONG_700,             SONG_708,              SONG_709,              SONG_710,                   SONG_711,
    VO_RDJANGO_TAIYO_296, SONG_776,              SONG_231,              VO_DJANGO_773,              SONG_576,
    SONG_582,             VO_DJANGO_MAGIC,       VO_DARK_DJANGO_SCREAM, VO_DJANGO_BOKURANO,         SONG_777,
    SONG_699,             SONG_712,              SONG_713,              SONG_714,                   SONG_715,
    VO_SABATA_ANKOKU,     VO_SABATA_SMIRK,       VO_SABATA_LAUGH,       VO_SABATA_DOKE,             VO_SABATA_IMADA,
    VO_SABATA_TAKETHIS,   VO_SABATA_749,         VO_SABATA_STUN,        SONG_874,                   SONG_875,
    VO_SABATA_DEATH,      VO_OTENKO_OTNK,        SONG_349,              VO_OTENKO_TAIYO_TO_TOMO_NI, VO_OTENKO_ASU_MO,
    SONG_706,             SONG_707,              SONG_790,              SONG_793,                   VO_LITA_WELCOME,
    VO_LADY_WELCOME,      SONG_738,              VO_KID_WELCOME,        VO_ENNIO,                   SONG_728,
    SONG_729,             SONG_730,              SONG_731,              SONG_720,                   SONG_721,
    SONG_722,             SONG_723,              SONG_724,              SONG_725,                   SONG_726,
    VO_CHEYENNE_727,      VO_SUMIRE_ONIICHAN1,   VO_SUMIRE_ONIICHAN2,   VO_SMITH_WELCOME,           SONG_734,
    SONG_735,             SONG_736,              SONG_737,              VO_COFFIN_SHOP,             SONG_704,
    SONG_705,             SONG_701,              SONG_587,              SONG_594,                   SONG_854,
    SONG_855,             SONG_856,              SONG_857,              VO_RINGO_DEFEATED,          SONG_858,
    SONG_859,             VO_RINGO_860,          SONG_847,              SONG_848,                   SONG_719,
    SONG_716,             VO_DURATHROR_YAHH_717, VO_DURATHROR_YAHH_718, SONG_577,                   SONG_583,
    SONG_596,             SONG_590,              SONG_597,              SONG_778,                   VO_DAINN_779,
    VO_DAINN_780,         VO_DAINN_LAUGH,        SONG_783,              SE_DAINN_STUN_BY_RINGO_BAT, SONG_579,
    VO_DAINN_DEATH,       SONG_618,              SONG_619,              -1,
};  // 0x085afeb2
// clang-format on

bool8 Save_WriteSystemData(void);
bool8 Save_ReadCurrentSlot(void);
bool8 Save_ReadFromNextSlot(void);
void Save_BackupStatAndWorld(void);
void RestoreGameState(void);
extern u32 gRtcReadInhibit;
bool32 FUN_0821b21c(s32* p, s32 val1, s32 val2, u16 val3);

bool32 sound_08240960(SoundID32 id);
char* GetPlayerName(void);
s32 FUN_0808fc14(void);
bool32 Taiyo_CalibrateSensor(void);
bool32 SetGameDateTime(s32 year, s32 month, s32 day, s32 hour, s32 minute, s32 second, bool32 writeRTC);
s32 Time_GetDaysInMonth(s32 year, s32 month);
void FUN_08214274(EntityA288* p);
void FUN_08214334(EntityA288* p);
void Video_SetBGTile(s32 bg, u32 x8, u32 y8, u32 tileidx, u32 flip, u32 pltt);
s32 FUN_08011584(char* password, u8* charTablePc, u8* nameTablePc, u8* name);
void FUN_082152ec(EntityA288* p);
void FUN_0821722c(EntityA288* p);
void FUN_08217440(EntityA288* p);
void FUN_08217648(EntityA288* p);
void FUN_0821785c(EntityA288* p);
void FUN_0821813c(EntityA288* p);
void FUN_082183e0(EntityA288* p);
void FUN_0821869c(EntityA288* p);
void FUN_08218910(EntityA288* p);
void FUN_08218b20(u8* dst);
void FUN_08218b34(EntityA288* p, u8* name);
s32 FUN_0821660c(EntityA288* p);
void FUN_08216894(EntityA288* p);
void FUN_082164e4(EntityA288* p);
void FUN_08216730(EntityA288* p);
void FUN_082167dc(EntityA288* p);
void FUN_08219d98(EntityA288* p);
void EntityA288_SetState(EntityA288* p, s32 state);
void FUN_082156bc(EntityA288* p);
void FUN_082143c0(EntityA288* p);
void FUN_082151d8(EntityA288* p);
void FUN_082152c0(EntityA288* p);
void FUN_082158a0(EntityA288* p);
void FUN_082158e4(EntityA288* p);
void FUN_082158fc(EntityA288* p);

void FUN_08213880(EntityA288* p) { p->sub78.tilemap = GetFile(DIR_TILE_MAP, TILEMAP_A413); }

void EntityA288_LoadBgPltt(EntityA288* p) {
  p->sub78.bgp = &GetBgPlttFile(BGP_EFDA)->body[208];
  CpuCopy32(p->sub78.bgp, &gBgPlttBuffer[208], 48 * sizeof(rgb555));
}

// スタートメニューの UI スプライトとテキストパネルを用意する
void FUN_082138d4(EntityA288* p) {
  Vec3 pos;
  EntityA288Sub78* s = &p->sub78;
  MainSpriteGfxFile* f;

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
  s->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&s->gfx, f);
  Vec3_Clear(&pos);
  pos.x = -8;
  pos.y = -64;
  MainSprite_Add(&s->sprite, &s->gfx, 148, 0x10, 0, 0, 60, &pos);
  s->sprite.flags |= SPRFLAG_HIDDEN;
  s->windowID = TextPanel_Create(3, 10, 24, 2);
}

void FUN_08213960(EntityA288* p) {
  MainSprite_Remove(&p->sub78.sprite);
  TextPanel_Destroy(p->sub78.windowID);
}

// sprite を unk_8e + 4 番のアニメで表示する
void FUN_0821397c(EntityA288* p) {
  EntityA288Sub78* s = &p->sub78;

  MainSprite_SetAnim(&s->sprite, &s->gfx, s->unk_8e + 4, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
  s->sprite.flags &= ~SPRFLAG_HIDDEN;
}

// BG0 を敷き直し, kind が 1 なら sprite を出す
void FUN_082139b4(EntityA288* p, s32 kind) {
  EntityA288Sub78* s = &p->sub78;
  s32 indices[1];

  indices[0] = 4;
  Video_SetupBGLayout(0, 0, s->tilemap, 0, 0, 1, indices);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  s->unk_8c = kind;
  if (s->unk_8c == 1) {
    s->unk_8e = 0;
    MainSprite_SetPose(&s->sprite, &s->gfx, 148, PLAYMODE_LOOP);
    s->sprite.pos.x = -8;
    s->sprite.pos.y = -64;
    FUN_0821397c(p);
  } else {
    s->sprite.flags |= SPRFLAG_HIDDEN;
  }
  s->unk_90 = 0;
}

void FUN_08213a50(EntityA288* p) {
  p->sub78.sprite.flags |= SPRFLAG_HIDDEN;
  MessageWindow_Close();
}

// unk_8c が 1 なら左右で unk_8e を切り替えて A / B を受け付け, そうでなければ A / B で 1 を返す
s32 FUN_08213a64(EntityA288* p) {
  EntityA288Sub78* s = &p->sub78;

  if (s->unk_8c == 1) {
    if (gInput[0].pressed & A_BUTTON) {
      PlaySound_082406e0(SE_SELECT);
      return s->unk_8e == 0 ? 1 : 2;
    }
    if (gInput[0].pressed & B_BUTTON) {
      PlaySound_082406e0(SE_CANCEL);
      return 3;
    }
    if (((gInput[0].pressed & DPAD_LEFT) && s->unk_8e == 1) || ((gInput[0].pressed & DPAD_RIGHT) && s->unk_8e == 0)) {
      s->unk_8e = 1 - s->unk_8e;
      FUN_0821397c(p);
      PlaySound_082406e0(SONG_892);
    }
    MainSprite_AdvanceAnim(&s->sprite, &s->gfx);
  } else if (gInput[0].pressed & (A_BUTTON | B_BUTTON)) {
    return 1;
  }
  s->unk_90++;
  return 0;
}

// プレイヤー名と, flags bit5 が立っていれば括弧付きの文字列を描き, sprite を出し直す
void FUN_08213b30(EntityA288* p) {
  EntityA288Sub78* s = &p->sub78;

  Video_ClearTextRect(9, 5, 16, 2);
  Video_DrawText(9, 5, GetPlayerName());
  if (TEST_FLAGS(p->flags, 0x20)) {
    u8 buf[32];
    u8* d;
    char* str;

    Video_ClearTextRect(3, 8, 24, 4);
    Video_DrawText(4, 8, GetStringByID(VM_ParseStringRef(p->sub12c8.unk_388) + 7));
    CpuFill32(0, buf, sizeof(buf));
    str = GetStringByID(VM_ParseStringRef(p->sub12c8.unk_38c) + gStat->unk_00e);
    d = buf;
    d[0] = 0x80;
    d[1] = 0xB9;
    d += 2;
    while (*str != 0) {
      *d = *str;
      str++;
      d++;
    }
    d[0] = 0x80;
    d[1] = 0xBA;
    Video_DrawText(3, 10, buf);
  }

  s->unk_8e = 0;
  MainSprite_SetPose(&s->sprite, &s->gfx, 148, PLAYMODE_LOOP);
  s->sprite.pos.x = -32;
  s->sprite.pos.y = -24;
  FUN_0821397c(p);
  s->unk_90 = 0;
}

// 左右で unk_8e を切り替え, A なら unk_8e に応じて 1 か 2, B なら 3 を返す
s32 FUN_08213c24(EntityA288* p) {
  EntityA288Sub78* s = &p->sub78;

  if (gInput[0].pressed & A_BUTTON) {
    if (s->unk_8e == 0) {
      PlaySound_082406e0(SE_SELECT);
      MainSprite_SetPose(&s->sprite, &s->gfx, 148, PLAYMODE_LOOP);
      return 1;
    }
    PlaySound_082406e0(SE_CANCEL);
    return 2;
  }
  if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    return 3;
  }
  if (((gInput[0].pressed & DPAD_LEFT) && s->unk_8e == 1) || ((gInput[0].pressed & DPAD_RIGHT) && s->unk_8e == 0)) {
    s->unk_8e = 1 - s->unk_8e;
    FUN_0821397c(p);
    PlaySound_082406e0(SONG_892);
  }
  MainSprite_AdvanceAnim(&s->sprite, &s->gfx);
  s->unk_90++;
  return 0;
}

// sprites の2枚を隠した状態で置いてカウンタを 0 に戻す
void FUN_08213ce4(EntityA288* p) {
  Vec3 pos;
  EntityA288Sub10C* s = &p->sub10c;

  Vec3_Clear(&pos);
  MainSprite_Add(&s->sprites[0], &p->gfx, 69, 0x30, 0, 0, 60, &pos);
  MainSprite_Add(&s->sprites[1], &p->gfx, 70, 0x30, 0, 0, 60, &pos);
  s->sprites[0].flags |= SPRFLAG_HIDDEN;
  s->sprites[1].flags |= SPRFLAG_HIDDEN;
  s->unk_c4 = 0;
  s->unk_c8 = 0;
  s->unk_ca = 0;
}

void FUN_08213d70(EntityA288* p) {
  MainSprite_Remove(&p->sub10c.sprites[0]);
  MainSprite_Remove(&p->sub10c.sprites[1]);
}

// 上半分のテキストボックスを BGP_C486 で開いて1行目を即時表示する
void EntityA288_ShowText(EntityA288* p) {
  MessageWindow_SetBgPltt(BGP_C486);
  MessageWindow_Start(p->sub10c.unk_c0);
  MessageWindow_ShowLine(0);
  MessageWindow_SetRect(2, 3, 32, 6);
  MessageWindow_SetInstant(1);
}

// 残差は A で次へ進むところのサブ state 遷移が他の遷移と合流するかどうかと, それに伴う分岐距離だけ (424/423)
// flags の bit は読んで bool32 にしてから落とす inline で包んだ形で比べた, SET_FLAGS にする形と layer ローカルは試済
// 太陽センサーの調整画面の state, A で調整して結果を出し, 終われば次の state へ移る
NON_MATCH void FUN_08213dc8(EntityA288* p) {
#ifdef NONMATCHING_C
  EntityA288Sub10C* s = &p->sub10c;

  if (p->flags & 1) {
    s32 layer;

    p->flags &= ~1;
    ClearBGTilemapBuffer(0);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    ClearBGTilemapBuffer(2);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    ClearBGTilemapBuffer(3);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    layer = 6;
    Video_SetBGLayer(2, p->tilemap, layer);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    p->unk_64 = layer;
    s->unk_c4 = 0;
    s->unk_c8 = 0;
    s->unk_ca = 0;
  }

  switch (p->unk_5c) {
    case 0: {
      if (p->flags & 2) {
        p->flags &= ~2;
        EntityA288_ShowText(p);
      }
      if (Mod(s->unk_ca, 30) == 0) {
        if (s->sprites[s->unk_c4].flags & SPRFLAG_HIDDEN) {
          s->sprites[s->unk_c4].flags &= ~SPRFLAG_HIDDEN;
        } else {
          s->sprites[s->unk_c4].flags |= SPRFLAG_HIDDEN;
        }
      }
      if (Mod(s->unk_c8, 180) == 0) {
        if (p->unk_64 == 6) {
          s32 layer = 7;

          Video_SetBGLayer(2, p->tilemap, layer);
          Video_GenerateBGMap(2, 0, 0, 0, 0);
          p->unk_64 = layer;
          s->unk_c4 = 1 - s->unk_c4;
          s->sprites[0].flags |= SPRFLAG_HIDDEN;
          s->sprites[1].flags &= ~SPRFLAG_HIDDEN;
        } else {
          s32 layer = 6;

          Video_SetBGLayer(2, p->tilemap, layer);
          Video_GenerateBGMap(2, 0, 0, 0, 0);
          p->unk_64 = layer;
          s->unk_c4 = 1 - s->unk_c4;
          s->sprites[0].flags &= ~SPRFLAG_HIDDEN;
          s->sprites[1].flags |= SPRFLAG_HIDDEN;
        }
      }
      s->unk_c8++;
      s->unk_ca++;
      if ((gInput[0].pressed & A_BUTTON) && p->timer2 > 15) {
        p->unk_5c = 1;
        p->timer2 = 0;
        p->flags |= 2;
        return;
      }
      if ((gInput[0].pressed & B_BUTTON) && p->kind == 1) {
        PlaySound_082406e0(SE_CANCEL);
        p->unk_5c = 99;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 1: {
      if (p->flags & 2) {
        p->flags &= ~2;
        s->sprites[s->unk_c4].flags &= ~SPRFLAG_HIDDEN;
      }
      if (p->timer2 < 60) {
        if (!Taiyo_CalibrateSensor()) {
          return;
        }
        if (p->kind != 0) {
          Save_WriteSystemData();
        }
        p->unk_5c = 2;
      } else {
        p->unk_5c = 3;
      }
      p->timer2 = 0;
      p->flags |= 2;
      break;
    }
    case 2: {
      if (p->flags & 2) {
        p->flags &= ~2;
        ClearBGTilemapBuffer(0);
        Video_GenerateBGMap(0, 0, 0, 0, 0);
        MessageWindow_Close();
        MessageWindow_ShowLine(1);
        MessageWindow_SetRect(40, 5, 24, 2);
        PlaySound_082406e0(SE_SELECT);
      }
      p->unk_5c = 4;
      p->timer2 = 0;
      p->flags |= 2;
      break;
    }
    case 3: {
      if (p->flags & 2) {
        p->flags &= ~2;
        ClearBGTilemapBuffer(0);
        Video_GenerateBGMap(0, 0, 0, 0, 0);
        MessageWindow_Close();
        MessageWindow_ShowLine(2);
        MessageWindow_SetRect(38, 5, 24, 2);
        PlaySound_082406e0(SE_NG);
      }
      p->unk_5c = 4;
      p->timer2 = 0;
      p->flags |= 2;
      break;
    }
    case 4: {
      p->flags &= ~2;
      if (p->timer2 >= 60) {
        p->unk_5c = 99;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 99: {
      if (p->flags & 2) {
        p->flags &= ~2;
        ClearBGTilemapBuffer(0);
        Video_GenerateBGMap(0, 0, 0, 0, 0);
        MessageWindow_Close();
      }
      s->sprites[0].flags |= SPRFLAG_HIDDEN;
      s->sprites[1].flags |= SPRFLAG_HIDDEN;
      if (p->kind == 0) {
        EntityA288_SetState(p, 1);
      } else {
        EntityA288_SetState(p, 4);
      }
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_08213dc8.inc");
#endif
}

// 日付設定のスプライトを並べて隠し, 日時を 0 に戻す
void FUN_08214160(EntityA288* p) {
  Vec3 positions[12];
  Vec3 pos;
  EntityA288Sub1D8* s;
  s32 i;

  memcpy(positions, u8_ARRAY_08252780, sizeof(positions));
  s = &p->sub1d8;
  for (i = 0; i < 12; i++) {
    MainSprite_Add(&s->sprites[i], &p->gfx, 0, 0x30, 0, 0, 60, &positions[i]);
    s->sprites[i].flags |= SPRFLAG_HIDDEN;
  }

  Vec3_Clear(&pos);
  MainSprite_Add(&s->sprite_480, &p->gfx, 54, 0x30, 0, 0, 60, &pos);
  s->sprite_480.flags |= SPRFLAG_HIDDEN;
  s->year = 0;
  s->month = 0;
  s->day = 0;
  s->hour = 0;
  s->minute = 0;
}

void FUN_08214248(EntityA288* p) {
  MainSprite* sprite = p->sub1d8.sprites;
  s32 i;

  for (i = 0; i < 12; i++) {
    MainSprite_Remove(sprite);
    sprite++;
  }

  MainSprite_Remove(&p->sub1d8.sprite_480);
}

// 今の日時を BCD から10進にして控え, 日付設定のスプライトを出す
void FUN_08214274(EntityA288* p) {
  EntityA288Sub1D8* s = &p->sub1d8;
  u32 bcd;
  s32 i;

  bcd = (s16)(Time_GetDate() >> 16);
  s->year = (bcd >> 12) * 1000 + ((bcd & 0xF00) >> 8) * 100 + ((bcd & 0xF0) >> 4) * 10 + (bcd & 0xF);
  bcd = ((s32)Time_GetDate() & 0xFF00) >> 8;
  s->month = (bcd >> 4) * 10 + (bcd & 0xF);
  bcd = Time_GetDate() & 0xFF;
  s->day = (bcd >> 4) * 10 + (bcd & 0xF);
  s->hour = Time_GetHour();
  s->minute = Time_GetMinute();
  for (i = 0; i < 12; i++) {
    s->sprites[i].flags &= ~SPRFLAG_HIDDEN;
  }
}

// unk_5c に応じて sprite_480 の位置とアニメを決める
void FUN_08214334(EntityA288* p) {
  MainSprite* sprite = &p->sub1d8.sprite_480;
  u16 anim = 5;

  sprite->flags &= ~SPRFLAG_HIDDEN;
  switch (p->unk_5c) {
    case 0: {
      anim = 5;
      sprite->pos.x = 0;
      sprite->pos.y = 0;
      break;
    }
    case 1: {
      anim = 6;
      sprite->pos.x = 0;
      sprite->pos.y = 0;
      break;
    }
    case 2: {
      anim = 6;
      sprite->pos.x = 48;
      sprite->pos.y = 0;
      break;
    }
    case 3: {
      anim = 6;
      sprite->pos.x = -32;
      sprite->pos.y = 32;
      break;
    }
    case 4: {
      anim = 6;
      sprite->pos.x = 16;
      sprite->pos.y = 32;
      break;
    }
  }
  MainSprite_SetAnim(sprite, &p->gfx, anim, PLAYMODE_LOOP, 0);
}

// sprites と sprite_480 をまとめて隠す
void FUN_082143c0(EntityA288* p) {
  EntityA288Sub1D8* s = &p->sub1d8;
  s32 i;

  for (i = 0; i < 12; i++) {
    s->sprites[i].flags |= SPRFLAG_HIDDEN;
  }

  s->sprite_480.flags |= SPRFLAG_HIDDEN;
}

// 下書き1回で止めた (664/699), 原典は各サブ state の入口で flags の bit1 を読んで落とす形と, 増減後の PlaySound への合流 (cross jump) で命令が多い
// 表示の更新 (年4桁と月日時分2桁ずつ) と START / 左右のサブ state 遷移は Ghidra の形どおり
// 日時設定画面の state, 左右で項目を選び上下で増減, START で RTC に書き込む
NON_MATCH void FUN_082143f4(EntityA288* p) {
#ifdef NONMATCHING_C
  EntityA288Sub1D8* s = &p->sub1d8;
  s32 dir = 0;
  s32 oldYear = s->year;
  s32 oldMonth = s->month;
  s32 oldDay = s->day;
  s32 oldHour = s->hour;
  s32 oldMinute = s->minute;
  s32 i, n;

  if (p->flags & 1) {
    s32 layer;

    p->flags &= ~1;
    ClearBGTilemapBuffer(0);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    ClearBGTilemapBuffer(2);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    ClearBGTilemapBuffer(3);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    layer = 2;
    Video_SetBGLayer(2, p->tilemap, layer);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    p->unk_64 = layer;
    FUN_08214274(p);
    p->unk_68 = 0;
  }

  if (p->unk_5c < 5) {
    if (gInput[0].pressed & DPAD_LEFT) {
      p->unk_5c = p->unk_5c < 1 ? 4 : p->unk_5c - 1;
      p->timer2 = 0;
      p->flags |= 2;
      PlaySound_082406e0(SE_CURSOR_MOVE);
    } else if (gInput[0].pressed & DPAD_RIGHT) {
      p->unk_5c = p->unk_5c < 4 ? p->unk_5c + 1 : 0;
      p->timer2 = 0;
      p->flags |= 2;
      PlaySound_082406e0(SE_CURSOR_MOVE);
    }
    if (gInput[0].pressed & START_BUTTON) {
      p->unk_5c = 5;
      p->timer2 = 0;
      p->flags |= 2;
    }
    if (gInput[0].pressed & DPAD_UP) {
      dir = 1;
    } else if (gInput[0].pressed & DPAD_DOWN) {
      dir = 2;
    } else if (gInput[0].down & (DPAD_UP | DPAD_DOWN)) {
      p->unk_68++;
      if (p->unk_68 > 14 && Mod(p->unk_68, 5) == 0) {
        dir = (gInput[0].down & DPAD_UP) ? 1 : 2;
      }
    } else {
      p->unk_68 = 0;
    }
  }

  switch (p->unk_5c) {
    case 0: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08214334(p);
        p->unk_68 = 0;
        dir = 0;
      }
      if (dir == 1) {
        if (s->year > 2098) {
          break;
        }
        s->year++;
      } else if (dir == 2) {
        if (s->year < 2001) {
          break;
        }
        s->year--;
      } else {
        break;
      }
      PlaySound_082406e0(SONG_410);
      break;
    }
    case 1: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08214334(p);
        p->unk_68 = 0;
        dir = 0;
      }
      if (dir == 1) {
        s->month = s->month > 11 ? 1 : s->month + 1;
      } else if (dir == 2) {
        s->month = s->month < 2 ? 12 : s->month - 1;
      } else {
        break;
      }
      PlaySound_082406e0(SONG_410);
      break;
    }
    case 2: {
      s32 days;

      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08214334(p);
        p->unk_68 = 0;
        dir = 0;
      }
      days = Time_GetDaysInMonth(s->year, s->month);
      if (dir == 1) {
        s->day = s->day >= days ? 1 : s->day + 1;
      } else if (dir == 2) {
        s->day = s->day < 2 ? days : s->day - 1;
      } else {
        break;
      }
      PlaySound_082406e0(SONG_410);
      break;
    }
    case 3: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08214334(p);
        p->unk_68 = 0;
        dir = 0;
      }
      if (dir == 1) {
        s->hour = s->hour < 23 ? s->hour + 1 : 0;
      } else if (dir == 2) {
        s->hour = s->hour == 0 ? 23 : s->hour - 1;
      } else {
        break;
      }
      PlaySound_082406e0(SONG_410);
      break;
    }
    case 4: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08214334(p);
        p->unk_68 = 0;
        dir = 0;
      }
      if (dir == 1) {
        s->minute = s->minute < 59 ? s->minute + 1 : 0;
      } else if (dir == 2) {
        s->minute = s->minute == 0 ? 59 : s->minute - 1;
      } else {
        break;
      }
      PlaySound_082406e0(SONG_410);
      break;
    }
    case 5: {
      if (p->flags & 2) {
        p->flags &= ~2;
        PlaySound_082406e0(SE_SELECT);
        SetGameDateTime(s->year, s->month, s->day, s->hour, s->minute, 0, TRUE);
        Time_SetLocation(0x23A666, 0x8BC000, 0);
        gClock.rtcStatus = 0;
      }
      if (p->timer2 > 59) {
        p->unk_5c = 99;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 99: {
      p->flags &= ~2;
      EntityA288_SetState(p, 3);
      break;
    }
  }

  if (s->year != oldYear) {
    n = s->year;
    for (i = 0; i < 4; i++) {
      MainSprite_SetPose(&s->sprites[3 - i], &p->gfx, Mod(n, 10), PLAYMODE_LOOP);
      n = Div(n, 10);
    }
  }
  if (s->month != oldMonth) {
    n = s->month;
    for (i = 0; i < 2; i++) {
      MainSprite_SetPose(&s->sprites[4 + (1 - i)], &p->gfx, Mod(n, 10), PLAYMODE_LOOP);
      n = Div(n, 10);
    }
  }
  if (s->year != oldYear || s->month != oldMonth) {
    s32 days = Time_GetDaysInMonth(s->year, s->month);

    if (s->day > days) {
      s->day = days;
    }
  }
  if (s->day != oldDay) {
    n = s->day;
    for (i = 0; i < 2; i++) {
      MainSprite_SetPose(&s->sprites[6 + (1 - i)], &p->gfx, Mod(n, 10), PLAYMODE_LOOP);
      n = Div(n, 10);
    }
  }
  if (s->hour != oldHour) {
    n = s->hour;
    for (i = 0; i < 2; i++) {
      MainSprite_SetPose(&s->sprites[8 + (1 - i)], &p->gfx, Mod(n, 10), PLAYMODE_LOOP);
      n = Div(n, 10);
    }
  }
  if (s->minute != oldMinute) {
    n = s->minute;
    for (i = 0; i < 2; i++) {
      MainSprite_SetPose(&s->sprites[10 + (1 - i)], &p->gfx, Mod(n, 10), PLAYMODE_LOOP);
      n = Div(n, 10);
    }
  }

  if (p->unk_5c < 5) {
    MainSprite_AdvanceAnim(&s->sprite_480, &p->gfx);
  }
#else
  INCFUNC("asm/func/FUN_082143f4.inc");
#endif
}

// FUN_082143f4 と同じ形の下書き1回で止めた (718/756), 違いは入口と確定後の暗転 (fade), 終わりに '.e' のスクリプトへ抜ける点
// 残差の性質も FUN_082143f4 と同じ (各サブ state の入口の bit1 の読み方と PlaySound への合流)
// 日時設定画面の state (ゲーム開始時版), 確定すると暗転して '.e' のスクリプトへ抜ける
NON_MATCH void FUN_08214a24(EntityA288* p) {
#ifdef NONMATCHING_C
  EntityA288Sub1D8* s = &p->sub1d8;
  s32 dir = 0;
  s32 oldYear = s->year;
  s32 oldMonth = s->month;
  s32 oldDay = s->day;
  s32 oldHour = s->hour;
  s32 oldMinute = s->minute;
  s32 i, n;

  if (p->flags & 1) {
    s32 layer;

    p->flags &= ~1;
    ClearBGTilemapBuffer(0);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    ClearBGTilemapBuffer(2);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    ClearBGTilemapBuffer(3);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    layer = 2;
    Video_SetBGLayer(2, p->tilemap, layer);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    p->unk_64 = layer;
    FUN_08214274(p);
    p->unk_68 = 0;
    p->fade[1] = 0;
    FUN_0821b21c(p->fade, 0, 1, 0xFFFF);
  }

  if (p->unk_5c < 5) {
    if (gInput[0].pressed & DPAD_LEFT) {
      p->unk_5c = p->unk_5c < 1 ? 4 : p->unk_5c - 1;
      p->timer2 = 0;
      p->flags |= 2;
      PlaySound_082406e0(SE_CURSOR_MOVE);
    } else if (gInput[0].pressed & DPAD_RIGHT) {
      p->unk_5c = p->unk_5c < 4 ? p->unk_5c + 1 : 0;
      p->timer2 = 0;
      p->flags |= 2;
      PlaySound_082406e0(SE_CURSOR_MOVE);
    }
    if (gInput[0].pressed & START_BUTTON) {
      p->unk_5c = 5;
      p->timer2 = 0;
      p->flags |= 2;
    }
    if (gInput[0].pressed & DPAD_UP) {
      dir = 1;
    } else if (gInput[0].pressed & DPAD_DOWN) {
      dir = 2;
    } else if (gInput[0].down & (DPAD_UP | DPAD_DOWN)) {
      p->unk_68++;
      if (p->unk_68 > 14 && Mod(p->unk_68, 5) == 0) {
        dir = (gInput[0].down & DPAD_UP) ? 1 : 2;
      }
    } else {
      p->unk_68 = 0;
    }
  }

  switch (p->unk_5c) {
    case 0: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08214334(p);
        p->unk_68 = 0;
        dir = 0;
      }
      if (dir == 1) {
        if (s->year > 2098) {
          break;
        }
        s->year++;
      } else if (dir == 2) {
        if (s->year < 2001) {
          break;
        }
        s->year--;
      } else {
        break;
      }
      PlaySound_082406e0(SONG_410);
      break;
    }
    case 1: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08214334(p);
        p->unk_68 = 0;
        dir = 0;
      }
      if (dir == 1) {
        s->month = s->month > 11 ? 1 : s->month + 1;
      } else if (dir == 2) {
        s->month = s->month < 2 ? 12 : s->month - 1;
      } else {
        break;
      }
      PlaySound_082406e0(SONG_410);
      break;
    }
    case 2: {
      s32 days;

      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08214334(p);
        p->unk_68 = 0;
        dir = 0;
      }
      days = Time_GetDaysInMonth(s->year, s->month);
      if (dir == 1) {
        s->day = s->day >= days ? 1 : s->day + 1;
      } else if (dir == 2) {
        s->day = s->day < 2 ? days : s->day - 1;
      } else {
        break;
      }
      PlaySound_082406e0(SONG_410);
      break;
    }
    case 3: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08214334(p);
        p->unk_68 = 0;
        dir = 0;
      }
      if (dir == 1) {
        s->hour = s->hour < 23 ? s->hour + 1 : 0;
      } else if (dir == 2) {
        s->hour = s->hour == 0 ? 23 : s->hour - 1;
      } else {
        break;
      }
      PlaySound_082406e0(SONG_410);
      break;
    }
    case 4: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08214334(p);
        p->unk_68 = 0;
        dir = 0;
      }
      if (dir == 1) {
        s->minute = s->minute < 59 ? s->minute + 1 : 0;
      } else if (dir == 2) {
        s->minute = s->minute == 0 ? 59 : s->minute - 1;
      } else {
        break;
      }
      PlaySound_082406e0(SONG_410);
      break;
    }
    case 5: {
      if (p->flags & 2) {
        p->flags &= ~2;
        PlaySound_082406e0(SE_SELECT);
        SetGameDateTime(s->year, s->month, s->day, s->hour, s->minute, 0, TRUE);
        Time_SetLocation(gClock.latitude, gClock.longitude, gClock.tz);
        gClock.rtcStatus = 0;
        p->fade[1] = 30;
      }
      if (p->timer2 > 59 && FUN_0821b21c(p->fade, 1, 30, 0xFFFF)) {
        p->unk_5c = 99;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 99: {
      p->flags &= ~2;
      VM_ExecByID(p->unk_50, NULL);
      ClearBGTilemapBuffer(0);
      Video_GenerateBGMap(0, 0, 0, 0, 0);
      ClearBGTilemapBuffer(2);
      Video_GenerateBGMap(2, 0, 0, 0, 0);
      ClearBGTilemapBuffer(3);
      Video_GenerateBGMap(3, 0, 0, 0, 0);
      gStat->unk_93e = p->subdbc.unk_c0;
      KillEntity(&p->e);
      return;
    }
  }

  if (s->year != oldYear) {
    n = s->year;
    for (i = 0; i < 4; i++) {
      MainSprite_SetPose(&s->sprites[3 - i], &p->gfx, Mod(n, 10), PLAYMODE_LOOP);
      n = Div(n, 10);
    }
  }
  if (s->month != oldMonth) {
    n = s->month;
    for (i = 0; i < 2; i++) {
      MainSprite_SetPose(&s->sprites[4 + (1 - i)], &p->gfx, Mod(n, 10), PLAYMODE_LOOP);
      n = Div(n, 10);
    }
  }
  if (s->year != oldYear || s->month != oldMonth) {
    s32 days = Time_GetDaysInMonth(s->year, s->month);

    if (s->day > days) {
      s->day = days;
    }
  }
  if (s->day != oldDay) {
    n = s->day;
    for (i = 0; i < 2; i++) {
      MainSprite_SetPose(&s->sprites[6 + (1 - i)], &p->gfx, Mod(n, 10), PLAYMODE_LOOP);
      n = Div(n, 10);
    }
  }
  if (s->hour != oldHour) {
    n = s->hour;
    for (i = 0; i < 2; i++) {
      MainSprite_SetPose(&s->sprites[8 + (1 - i)], &p->gfx, Mod(n, 10), PLAYMODE_LOOP);
      n = Div(n, 10);
    }
  }
  if (s->minute != oldMinute) {
    n = s->minute;
    for (i = 0; i < 2; i++) {
      MainSprite_SetPose(&s->sprites[10 + (1 - i)], &p->gfx, Mod(n, 10), PLAYMODE_LOOP);
      n = Div(n, 10);
    }
  }

  if (p->unk_5c < 5) {
    MainSprite_AdvanceAnim(&s->sprite_480, &p->gfx);
  }
#else
  INCFUNC("asm/func/FUN_08214a24.inc");
#endif
}

// 地域選択のスプライトと5行分のテキストパネルを用意する
void FUN_082150e8(EntityA288* p) {
  Vec3 pos;
  EntityA288AreaSelect* s = &p->area;
  s32 i;
  s32 y;

  Vec3_Clear(&pos);
  MainSprite_Add(&s->sprite_00, &p->gfx, 42, 0x30, 0, 0, 60, &pos);
  s->sprite_00.flags |= SPRFLAG_HIDDEN;
  MainSprite_Add(&s->cursor, &p->gfx, 37, 0x30, 0, 0, 60, &pos);
  s->cursor.flags |= SPRFLAG_HIDDEN;
  s->areaIdx = 1;
  s->prefIdx = 0;
  y = 7;
  for (i = 0; i < 5; i++) {
    s->windowIDs[i] = TextPanel_Create(4, y, 16, 2);
    y += 2;
  }
}

// スプライトとテキストパネルを片付ける
void EntityA288_DestroyPanels(EntityA288* p) {
  s32 i;

  MainSprite_Remove(&p->area.sprite_00);
  MainSprite_Remove(&p->area.cursor);

  for (i = 0; i < 5; i++) {
    TextPanel_Destroy(p->area.windowIDs[i]);
  }
}

// 選んだ地方の見出しを出し, その地方の地域名を並べ直す
void FUN_082151d8(EntityA288* p) {
  EntityA288AreaSelect* s = &p->area;
  EntityA288Entry* e;
  s32 i;
  s32 y;

  MainSprite_SetPose(&s->sprite_00, &p->gfx, s->areaIdx + 41, PLAYMODE_LOOP);
  s->sprite_00.flags &= ~SPRFLAG_HIDDEN;
  e = &s->entries[s->areaIdx + 1];
  ClearBGTilemapBuffer(0);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  for (i = 0; i < 5; i++) {
    TextPanel_Hide(s->windowIDs[i]);
  }

  Video_ClearTextRect(4, 7, 16, 10);
  y = 7;
  for (i = 0; i < e->count; i++) {
    Video_DrawText(4, y, GetStringByID(VM_ParseStringRef(s->unk_6ec) + e->prefecture[i]));
    y += 2;
  }

  s->prefCount = e->count;
  if (s->prefIdx >= s->prefCount) {
    s->prefIdx = s->prefCount - 1;
    FUN_082152ec(p);
  }
}

void FUN_082152c0(EntityA288* p) {
  MainSprite_Show(&p->area.cursor);
  MainSprite_SetAnim(&p->area.cursor, &p->gfx, 4, PLAYMODE_LOOP, 0);
}

void FUN_082152ec(EntityA288* p) {
  MainSprite* sprite = &p->area.cursor;

  sprite->pos.y = p->area.prefIdx * 16;
}

// 地域選択画面の state, A で地域を確定して '.e' のスクリプトへ抜け, B で前の state へ戻る
// 残差は 99 番の後始末で gStat->unk_93e へ写すところの命令順だけ (400/400), 原典は書き込み先の gStat + 0x93E を値より先に作る
// entries を歩くループはブロック内の EntityA288Entry* ローカルで一致, サブ state の遷移は SET_FLAGS でないと定数の位置が合わない
// flags の bit0 / bit1 は「読んで bool32 にしてから落とす」static inline で包むと読み捨ての ands まで揃うが, 一致しないので展開してある
NON_MATCH void FUN_08215304(EntityA288* p) {
#ifdef NONMATCHING_C
  EntityA288AreaSelect* s = &p->area;

  if (p->flags & 1) {
    s32 layer;

    p->flags &= ~1;
    if (p->kind == 0) {
      FUN_082143c0(p);
    }
    ClearBGTilemapBuffer(0);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    ClearBGTilemapBuffer(2);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    ClearBGTilemapBuffer(3);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    layer = 3;
    Video_SetBGLayer(2, p->tilemap, layer);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    p->unk_64 = layer;
    if (p->kind == 0) {
      p->area.areaIdx = 1;
      p->area.prefIdx = 0;
    } else if (gSystemSaveData->prefecture == 0) {
      p->area.areaIdx = 1;
      p->area.prefIdx = 0;
    } else {
      s32 n = gSystemSaveData->prefecture - 1;
      s32 i;

      for (i = 0; i < p->area.entryCount; i++) {
        EntityA288Entry* e = &p->area.entries[i + 1];
        s32 rest = n - e->count;

        if (rest < 0) {
          s->areaIdx = i;
          s->prefIdx = n;
          break;
        }
        n = rest;
      }
    }
    FUN_082151d8(p);
    FUN_082152c0(p);
    FUN_082152ec(p);
  }

  if (p->unk_5c <= 0) {
    if (gInput[0].pressed & A_BUTTON) {
      p->unk_5c = 1;
      p->timer2 = 0;
      SET_FLAGS(p->flags, 2);
    } else if (gInput[0].pressed & B_BUTTON) {
      p->unk_5c = 2;
      p->timer2 = 0;
      SET_FLAGS(p->flags, 2);
    }
  }

  switch (p->unk_5c) {
    case 0: {
      p->flags &= ~2;
      if (gInput[0].pressed & (L_BUTTON | DPAD_LEFT)) {
        if (--s->areaIdx < 0) {
          s->areaIdx = s->entryCount - 1;
        }
        FUN_082151d8(p);
        PlaySound_082406e0(SE_CURSOR_MOVE);
      } else if (gInput[0].pressed & (R_BUTTON | DPAD_RIGHT)) {
        if (++s->areaIdx >= s->entryCount) {
          s->areaIdx = 0;
        }
        FUN_082151d8(p);
        PlaySound_082406e0(SE_CURSOR_MOVE);
      }
      if (gInput[0].pressed & DPAD_UP) {
        if (--s->prefIdx < 0) {
          s->prefIdx = s->prefCount - 1;
        }
      } else if (gInput[0].pressed & DPAD_DOWN) {
        if (++s->prefIdx >= s->prefCount) {
          s->prefIdx = 0;
        }
      } else {
        break;
      }
      FUN_082152ec(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
      break;
    }
    case 1: {
      if (p->flags & 2) {
        p->flags &= ~2;
        PlaySound_082406e0(SE_SELECT);
        FUN_082156bc(p);
      }
      if (p->timer2 > 29) {
        p->unk_5c = 99;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 2: {
      if (p->flags & 2) {
        p->flags &= ~2;
        PlaySound_082406e0(SE_CANCEL);
      }
      s->sprite_00.flags |= SPRFLAG_HIDDEN;
      s->cursor.flags |= SPRFLAG_HIDDEN;
      if (p->kind == 0) {
        EntityA288_SetState(p, 1);
      } else {
        EntityA288_SetState(p, 4);
      }
      break;
    }
    case 99: {
      p->flags &= ~2;
      s->sprite_00.flags |= SPRFLAG_HIDDEN;
      s->cursor.flags |= SPRFLAG_HIDDEN;
      if (p->kind == 0) {
        VM_ExecByID(p->unk_50, NULL);
        ClearBGTilemapBuffer(0);
        Video_GenerateBGMap(0, 0, 0, 0, 0);
        ClearBGTilemapBuffer(2);
        Video_GenerateBGMap(2, 0, 0, 0, 0);
        ClearBGTilemapBuffer(3);
        Video_GenerateBGMap(3, 0, 0, 0, 0);
        gStat->unk_93e = p->subdbc.unk_c0;
        KillEntity(&p->e);
        return;
      }
      EntityA288_SetState(p, 4);
      break;
    }
  }

  if (p->unk_5c <= 0) {
    MainSprite_AdvanceAnim(&s->cursor, &p->gfx);
  }
#else
  INCFUNC("asm/func/FUN_08215304.inc");
#endif
}

// 選んだ地域の緯度経度を時計に入れて, 地域をシステムセーブに書く
void FUN_082156bc(EntityA288* p) {
  EntityA288AreaSelect* s = &p->area;
  EntityA288Entry* e = &s->entries[s->areaIdx + 1];
  s32 prefecture;

  Time_SetLocation(e->latitude[s->prefIdx], e->longitude[s->prefIdx], 0);
  gClock.rtcStatus = 0;
  prefecture = e->prefecture[s->prefIdx];
  gSystemSaveData->prefecture = prefecture;
  Save_WriteSystemData();
}

// システムセーブの地域から entries 上の位置を探し, その緯度経度を時計に入れる
// 残差は前半のループの準備だけ, 原典は p をコピーした r1 から DB4/DB6/DBA/0x7B4 の番地をループの前で作り, entries の歩きポインタはガードの後に置く
// 前半を p->area 直書きにする形 (68/69) と entries[i + 1] の添字にする形は試済, 後半の Time_SetLocation 以降は一致
NON_MATCH void FUN_0821572c(EntityA288* p) {
#ifdef NONMATCHING_C
  EntityA288AreaSelect* s = &p->area;
  EntityA288Entry* e;
  s32 n = gSystemSaveData->prefecture - 1;
  s32 i;

  for (i = 0, e = &s->entries[1]; i < s->entryCount; i++) {
    s32 rest = n - e->count;

    if (rest < 0) {
      s->areaIdx = i;
      s->prefIdx = n;
      break;
    }
    n = rest;
    e++;
  }

  e = &s->entries[s->areaIdx + 1];
  Time_SetLocation(e->latitude[s->prefIdx], e->longitude[s->prefIdx], 0);
  gClock.rtcStatus = 0;
#else
  INCFUNC("asm/func/FUN_0821572c.inc");
#endif
}

// sprites を隠した状態で置き, unk_c0 を gStat から取る
void FUN_082157d4(EntityA288* p) {
  Vec3 pos;
  EntityA288SubDBC* s = &p->subdbc;

  Vec3_Clear(&pos);
  MainSprite_Add(&s->sprites[0], &p->gfx, 63, 0x30, 0, 0, 60, &pos);
  s->sprites[0].flags |= SPRFLAG_HIDDEN;
  MainSprite_Add(&s->sprites[1], &p->gfx, 67, 0x30, 0, 0, 60, &pos);
  s->sprites[1].flags |= SPRFLAG_HIDDEN;
  s->unk_c0 = gStat->unk_93e;
}

void FUN_0821587c(EntityA288* p) {
  MainSprite_Remove(&p->subdbc.sprites[0]);
  MainSprite_Remove(&p->subdbc.sprites[1]);
}

// カーソルのスプライトを出して unk_e7c 行目の高さに置く
void FUN_082158a0(EntityA288* p) {
  MainSprite* spr = &p->subdbc.sprites[0];

  spr->flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(spr, &p->gfx, 7, PLAYMODE_LOOP, 0);
  spr->pos.y = p->subdbc.unk_c0 * 24;
}

void FUN_082158e4(EntityA288* p) {
  MainSprite* sprite = &p->subdbc.sprites[0];

  sprite->pos.y = p->subdbc.unk_c0 * 24;
}

// 残差0命令 (31/31), レジスタ名だけ違う: unk_c8 のプール定数が原典は r1, こちらは r2 に載る
// EntityA288SubDBC* ローカルを持つ形は試済 (一致しない)
NON_MATCH void FUN_082158fc(EntityA288* p) {
#ifdef NONMATCHING_C
  char* text = GetStringByID(VM_ParseStringRef(p->subdbc.unk_c4) + p->subdbc.unk_c8);

  Video_ClearTextRect(9, 10, 18, 2);
  Video_DrawText(9, 10, text);
  gStat->unk_944 = p->subdbc.unk_c8;
#else
  INCFUNC("asm/func/FUN_082158fc.inc");
#endif
}

// 3択メニューの state, 3行目では左右で '.X' の番号を選び, A でそれぞれの行き先へ移る
// 残差は fade と定数 1 の高位レジスタ (r8 / r9) の入れ替わり, それに gStat->unk_93e / unk_944 へ書くところの命令順 (408/411)
// 宣言順の入れ替えは試済, FUN_08215304 / FUN_0821619c と同じく gStat へ写す命令順だけが揃わない
// flags の bit0 / bit1 は「読んで bool32 にしてから落とす」static inline で包むと読み捨ての ands まで揃うが, 一致しないので展開してある
NON_MATCH void FUN_08215950(EntityA288* p) {
#ifdef NONMATCHING_C
  s32* fade = p->fade;
  EntityA288SubDBC* s = &p->subdbc;

  if (p->flags & 1) {
    s32 layer;

    p->flags &= ~1;
    ClearBGTilemapBuffer(0);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    ClearBGTilemapBuffer(2);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    ClearBGTilemapBuffer(3);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    layer = 9;
    Video_SetBGLayer(2, p->tilemap, layer);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    p->unk_64 = layer;
    FUN_082158a0(p);
    p->subdbc.unk_c8 = gStat->unk_944;
    FUN_082158fc(p);
  }

  switch (p->unk_5c) {
    case 0: {
      p->flags &= ~2;
      if (gInput[0].pressed & B_BUTTON) {
        p->unk_5c = 1;
        p->timer2 = 0;
        p->flags |= 2;
        PlaySound_082406e0(SE_CANCEL);
        break;
      }
      if (gInput[0].pressed & A_BUTTON) {
        PlaySound_082406e0(SE_SELECT);
        switch (p->subdbc.unk_c0) {
          case 0: {
            EntityA288_SetState(p, 0);
            s->sprites[0].flags |= SPRFLAG_HIDDEN;
            break;
          }
          case 1: {
            EntityA288_SetState(p, 3);
            s->sprites[0].flags |= SPRFLAG_HIDDEN;
            break;
          }
          case 2: {
            ScriptArgs args;

            args.argc = 1;
            args.argv = (u32*)&s->unk_c8;
            VM_ExecByID(s->unk_cc, &args);
            s->sprites[0].flags |= SPRFLAG_HIDDEN;
            s->sprites[1].flags |= SPRFLAG_HIDDEN;
            ClearBGTilemapBuffer(0);
            Video_GenerateBGMap(0, 0, 0, 0, 0);
            ClearBGTilemapBuffer(2);
            Video_GenerateBGMap(2, 0, 0, 0, 0);
            ClearBGTilemapBuffer(3);
            Video_GenerateBGMap(3, 0, 0, 0, 0);
            gStat->unk_93e = p->subdbc.unk_c0;
            KillEntity(&p->e);
            return;
          }
        }
        break;
      }
      if (gInput[0].pressed & DPAD_UP) {
        if (--p->subdbc.unk_c0 < 0) {
          p->subdbc.unk_c0 = 2;
        }
        FUN_082158e4(p);
        PlaySound_082406e0(SE_CURSOR_MOVE);
      } else if (gInput[0].pressed & DPAD_DOWN) {
        if (++p->subdbc.unk_c0 > 2) {
          p->subdbc.unk_c0 = 0;
        }
        FUN_082158e4(p);
        PlaySound_082406e0(SE_CURSOR_MOVE);
      }
      if (s->unk_c0 == 2) {
        MainSprite_SetPose(&s->sprites[1], &p->gfx, 67, PLAYMODE_LOOP);
        s->sprites[1].flags &= ~SPRFLAG_HIDDEN;
        if (gInput[0].pressed & DPAD_LEFT) {
          if (s->unk_c8 == 0) {
            s->unk_c8 = 9;
          }
          s->unk_c8--;
        } else if (gInput[0].pressed & DPAD_RIGHT) {
          if (++s->unk_c8 > 8) {
            s->unk_c8 = 0;
          }
        } else {
          break;
        }
        FUN_082158fc(p);
        PlaySound_082406e0(SONG_410);
      } else {
        s->sprites[1].flags |= SPRFLAG_HIDDEN;
      }
      break;
    }
    case 1: {
      if (p->flags & 2) {
        p->flags &= ~2;
        fade[1] = 30;
      }
      if (FUN_0821b21c(fade, 1, 30, 0xFFFF)) {
        p->unk_5c = 2;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 2: {
      p->flags &= ~2;
      if (p->timer2 > 59) {
        p->unk_5c = 99;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 99: {
      p->flags &= ~2;
      gStat->unk_944 = 0;
      s->sprites[0].flags |= SPRFLAG_HIDDEN;
      s->sprites[1].flags |= SPRFLAG_HIDDEN;
      VM_ExecByID(p->unk_50, NULL);
      ClearBGTilemapBuffer(0);
      Video_GenerateBGMap(0, 0, 0, 0, 0);
      ClearBGTilemapBuffer(2);
      Video_GenerateBGMap(2, 0, 0, 0, 0);
      ClearBGTilemapBuffer(3);
      Video_GenerateBGMap(3, 0, 0, 0, 0);
      gStat->unk_93e = p->subdbc.unk_c0;
      KillEntity(&p->e);
      return;
    }
  }

  if (p->unk_5c <= 0) {
    MainSprite_AdvanceAnim(&s->sprites[0], &p->gfx);
  }
#else
  INCFUNC("asm/func/FUN_08215950.inc");
#endif
}

// BGM / SE / ボイスの表の長さをそれぞれ数える
void FUN_08215d24(EntityA288* p) {
  EntityA288SoundTest* s = &p->soundTest;
  const SoundID16* t;
  s32 n;

  t = u16_ARRAY_085afa30;
  n = 0;
  while ((s16)*t != -1) {
    t++;
    n++;
  }
  s->bgmCount = n;

  t = u16_ARRAY_085afaee;
  n = 0;
  while ((s16)*t != -1) {
    t++;
    n++;
  }
  s->seCount = n;

  t = u16_ARRAY_085afeb2;
  n = 0;
  while ((s16)*t != -1) {
    t++;
    n++;
  }
  s->voiceCount = n;
}

// サウンドテストのカーソル, アイコン, 数字スプライトを隠した状態で並べる
void FUN_08215db4(EntityA288* p) {
  EntityA288SoundTest* s = &p->soundTest;
  Vec3 pos;
  s32 i;

  Vec3_Clear(&pos);
  MainSprite_Add(&s->sprites[0], &p->gfx, 63, 0x30, 0, 0, 60, &pos);
  s->sprites[0].flags |= SPRFLAG_HIDDEN;
  MainSprite_Add(&s->sprites[1], &p->gfx, 75, 0x30, 0, 0, 60, &pos);
  s->sprites[1].flags |= SPRFLAG_HIDDEN;
  for (i = 0; i < 3; i++) {
    MainSprite_Add(&s->icons[i], &p->gfx, 71, 0x30, 0, 0, 60, &pos);
    s->icons[i].flags |= SPRFLAG_HIDDEN;
    pos.y += 32;
  }

  pos.x = 184;
  pos.y = 64;
  for (i = 0; i < 3; i++) {
    MainSprite_Add(&s->digits[0][i], &p->gfx, 0, 0x30, 0, 0, 60, &pos);
    s->digits[0][i].flags |= SPRFLAG_HIDDEN;
    pos.x += 8;
  }

  pos.x = 184;
  pos.y = 96;
  for (i = 0; i < 3; i++) {
    MainSprite_Add(&s->digits[1][i], &p->gfx, 0, 0x30, 0, 0, 60, &pos);
    s->digits[1][i].flags |= SPRFLAG_HIDDEN;
    pos.x += 8;
  }

  s->unk_424 = 0;
}

// 追加分のスプライト11枚をまとめて外す
void FUN_08215f3c(EntityA288* p) {
  s32 i;

  MainSprite_Remove(&p->soundTest.sprites[0]);
  MainSprite_Remove(&p->soundTest.sprites[1]);
  for (i = 0; i < 3; i++) {
    MainSprite_Remove(&p->soundTest.icons[i]);
    MainSprite_Remove(&p->soundTest.digits[0][i]);
    MainSprite_Remove(&p->soundTest.digits[1][i]);
  }
}

// カーソルを出して unk_424 行目のポーズを当て直す
void FUN_08215f98(EntityA288* p) {
  MainSprite* spr = p->soundTest.sprites;

  spr[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&spr[0], &p->gfx, 7, PLAYMODE_LOOP, 0);
  MainSprite_SetPose(&spr[1], &p->gfx, p->soundTest.unk_424 + 0x4B, PLAYMODE_LOOP);
  spr[1].flags &= ~SPRFLAG_HIDDEN;
}

// BG を消してから '.b' の文字列を (10, 4) に描く
void FUN_08216000(EntityA288* p) {
  char* str;

  ClearBGTilemapBuffer(0);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  str = GetStringByID(VM_ParseStringRef(p->soundTest.unk_420) + p->soundTest.unk_42e);
  Video_ClearTextRect(10, 4, 16, 2);
  Video_DrawText(10, 4, str);
}

// unk_430 を3桁の数字スプライトで出す
void FUN_0821605c(EntityA288* p) {
  EntityA288SoundTest* s = &p->soundTest;
  s32 n = p->soundTest.unk_430;
  s32 i;

  for (i = 0; i < 3; i++) {
    MainSprite_SetPose(&s->digits[0][2 - i], &p->gfx, Mod(n, 10), PLAYMODE_LOOP);
    s->digits[0][2 - i].flags &= ~SPRFLAG_HIDDEN;
    n = Div(n, 10);
  }
}

// unk_432 を3桁の数字スプライトで出す
void FUN_082160d8(EntityA288* p) {
  EntityA288SoundTest* s = &p->soundTest;
  s32 n = p->soundTest.unk_432;
  s32 i;

  for (i = 0; i < 3; i++) {
    MainSprite_SetPose(&s->digits[1][2 - i], &p->gfx, Mod(n, 10), PLAYMODE_LOOP);
    s->digits[1][2 - i].flags &= ~SPRFLAG_HIDDEN;
    n = Div(n, 10);
  }
}

// unk_424 行目にカーソルを置いてポーズを当て直す
void FUN_08216154(EntityA288* p) {
  MainSprite* spr = p->soundTest.sprites;

  spr[0].pos.y = p->soundTest.unk_424 * 32;
  MainSprite_SetPose(&spr[1], &p->gfx, p->soundTest.unk_424 + 0x4B, PLAYMODE_LOOP);
  spr[1].flags &= ~SPRFLAG_HIDDEN;
  p->unk_68 = 0;
}

// サウンドテスト画面の state, B で音が止まっていれば暗転して '.e' のスクリプトへ抜ける
// 残差は 99 番の後始末で gStat に写す subdbc.unk_c0 の番地だけ, 原典はループの前に p+0xE7C を r7 に作って最後に [r7] で読む (357/356)
// EntityA288SubDBC* ローカルを経由する形は試済
// flags の bit0 / bit1 は「読んで bool32 にしてから落とす」static inline で包むと読み捨ての ands まで揃うが, 一致しないので展開してある
NON_MATCH void FUN_0821619c(EntityA288* p) {
#ifdef NONMATCHING_C
  s32* fade = p->fade;
  EntityA288SoundTest* s = &p->soundTest;

  if (p->flags & 1) {
    s32 layer;

    p->flags &= ~1;
    ClearBGTilemapBuffer(0);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    ClearBGTilemapBuffer(2);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    ClearBGTilemapBuffer(3);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    layer = 10;
    Video_SetBGLayer(2, p->tilemap, layer);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    p->unk_64 = layer;
    FUN_08215f98(p);
    FUN_08215d24(p);
    FUN_08216000(p);
    FUN_0821605c(p);
    FUN_082160d8(p);
    p->unk_68 = 0;
  }

  switch (p->unk_5c) {
    case 0: {
      s32 h;
      s32 div;

      p->flags &= ~2;
      if ((gInput[0].pressed & B_BUTTON) && FUN_0821660c(p)) {
        p->unk_5c = 1;
        p->timer2 = 0;
        p->flags |= 2;
        PlaySound_082406e0(SE_CANCEL);
        break;
      }
      FUN_08216894(p);
      if (gInput[0].pressed & A_BUTTON) {
        FUN_082164e4(p);
      }
      if (gInput[0].pressed & DPAD_UP) {
        if (--s->unk_424 < 0) {
          s->unk_424 = 2;
        }
        FUN_08216154(p);
        PlaySound_082406e0(SONG_892);
      } else if (gInput[0].pressed & DPAD_DOWN) {
        if (++s->unk_424 > 2) {
          s->unk_424 = 0;
        }
        FUN_08216154(p);
        PlaySound_082406e0(SONG_892);
      }

      h = 0;
      div = 5;
      if (gInput[0].pressed & DPAD_LEFT) {
        h = 1;
      } else if (gInput[0].pressed & DPAD_RIGHT) {
        h = 2;
      } else if (gInput[0].down & (DPAD_LEFT | DPAD_RIGHT)) {
        p->unk_68++;
        if (p->unk_68 > 14) {
          if (p->unk_68 > 199) {
            div = 2;
          }
          if (Mod(p->unk_68, div) == 0) {
            h = (gInput[0].down & DPAD_LEFT) ? 1 : 2;
          }
        }
      } else {
        p->unk_68 = 0;
      }
      if (h == 1) {
        FUN_08216730(p);
      } else if (h == 2) {
        FUN_082167dc(p);
      }
      break;
    }
    case 1: {
      if (p->flags & 2) {
        p->flags &= ~2;
        fade[1] = 30;
      }
      if (FUN_0821b21c(fade, 1, 30, 0xFFFF)) {
        p->unk_5c = 2;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 2: {
      p->flags &= ~2;
      if (p->timer2 > 59) {
        p->unk_5c = 99;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 99: {
      s32 i;

      p->flags &= ~2;
      s->sprites[0].flags |= SPRFLAG_HIDDEN;
      s->sprites[1].flags |= SPRFLAG_HIDDEN;
      for (i = 0; i < 3; i++) {
        s->icons[i].flags |= SPRFLAG_HIDDEN;
        s->digits[0][i].flags |= SPRFLAG_HIDDEN;
        s->digits[1][i].flags |= SPRFLAG_HIDDEN;
      }
      Sound_StopAll();
      VM_ExecByID(p->unk_50, NULL);
      ClearBGTilemapBuffer(0);
      Video_GenerateBGMap(0, 0, 0, 0, 0);
      ClearBGTilemapBuffer(2);
      Video_GenerateBGMap(2, 0, 0, 0, 0);
      ClearBGTilemapBuffer(3);
      Video_GenerateBGMap(3, 0, 0, 0, 0);
      gStat->unk_93e = p->subdbc.unk_c0;
      KillEntity(&p->e);
      return;
    }
  }

  if (p->unk_5c <= 0) {
    MainSprite_AdvanceAnim(&s->sprites[0], &p->gfx);
  }
#else
  INCFUNC("asm/func/FUN_0821619c.inc");
#endif
}

// 選んでいる行の番号の音を鳴らし直してアイコンを出す
void FUN_082164e4(EntityA288* p) {
  EntityA288SoundTest* s = &p->soundTest;

  switch (p->soundTest.unk_424) {
    case 0: {
      if (sound_08240960((s16)u16_ARRAY_085afa30[p->soundTest.playing[0]])) {
        sound_08240740((s16)u16_ARRAY_085afa30[p->soundTest.playing[0]]);
      }
      PlaySound_082406e0((s16)u16_ARRAY_085afa30[p->soundTest.unk_42e]);
      p->soundTest.playing[0] = p->soundTest.unk_42e;
      break;
    }
    case 1: {
      if (sound_08240960((s16)u16_ARRAY_085afaee[p->soundTest.playing[1]])) {
        sound_08240740((s16)u16_ARRAY_085afaee[p->soundTest.playing[1]]);
      }
      PlaySound_082406e0((s16)u16_ARRAY_085afaee[p->soundTest.unk_430]);
      p->soundTest.playing[1] = p->soundTest.unk_430;
      break;
    }
    case 2: {
      if (sound_08240960((s16)u16_ARRAY_085afeb2[p->soundTest.playing[2]])) {
        sound_08240740((s16)u16_ARRAY_085afeb2[p->soundTest.playing[2]]);
      }
      PlaySound_082406e0((s16)u16_ARRAY_085afeb2[p->soundTest.unk_432]);
      p->soundTest.playing[2] = p->soundTest.unk_432;
      break;
    }
  }
  MainSprite_SetAnim(&s->icons[s->unk_424], &p->gfx, 8, PLAYMODE_LOOP, 0);
}

// 選んでいる行の音を止める, 何も鳴っていなければアイコンを消して 1 を返す
s32 FUN_0821660c(EntityA288* p) {
  EntityA288SoundTest* s = &p->soundTest;

  if (!sound_08240960((s16)u16_ARRAY_085afa30[p->soundTest.playing[0]]) && !sound_08240960((s16)u16_ARRAY_085afaee[p->soundTest.playing[1]]) && !sound_08240960((s16)u16_ARRAY_085afeb2[p->soundTest.playing[2]])) {
    p->soundTest.icons[0].flags |= SPRFLAG_HIDDEN;
    p->soundTest.icons[1].flags |= SPRFLAG_HIDDEN;
    p->soundTest.icons[2].flags |= SPRFLAG_HIDDEN;
    PlaySound_082406e0(SE_CANCEL);
    return 1;
  }

  switch (s->unk_424) {
    case 0: {
      sound_08240740(u16_ARRAY_085afa30[s->playing[0]]);
      break;
    }
    case 1: {
      sound_08240740(u16_ARRAY_085afaee[s->playing[1]]);
      break;
    }
    case 2: {
      sound_08240740(u16_ARRAY_085afeb2[s->playing[2]]);
      break;
    }
    default: {
      return 0;
    }
  }
  s->icons[s->unk_424].flags |= SPRFLAG_HIDDEN;
  return 0;
}

// 選んでいる行の番号を1つ戻して描き直す
void FUN_08216730(EntityA288* p) {
  switch (p->soundTest.unk_424) {
    case 0: {
      if (--p->soundTest.unk_42e < 0) {
        p->soundTest.unk_42e = p->soundTest.bgmCount - 1;
      }
      FUN_08216000(p);
      break;
    }
    case 1: {
      if (--p->soundTest.unk_430 < 0) {
        p->soundTest.unk_430 = p->soundTest.seCount - 1;
      }
      FUN_0821605c(p);
      break;
    }
    case 2: {
      if (--p->soundTest.unk_432 < 0) {
        p->soundTest.unk_432 = p->soundTest.voiceCount - 1;
      }
      FUN_082160d8(p);
      break;
    }
  }
  PlaySound_082406e0(SONG_893);
}

// 選んでいる行の番号を1つ進めて描き直す
void FUN_082167dc(EntityA288* p) {
  switch (p->soundTest.unk_424) {
    case 0: {
      if (++p->soundTest.unk_42e >= p->soundTest.bgmCount) {
        p->soundTest.unk_42e = 0;
      }
      FUN_08216000(p);
      break;
    }
    case 1: {
      if (++p->soundTest.unk_430 >= p->soundTest.seCount) {
        p->soundTest.unk_430 = 0;
      }
      FUN_0821605c(p);
      break;
    }
    case 2: {
      if (++p->soundTest.unk_432 >= p->soundTest.voiceCount) {
        p->soundTest.unk_432 = 0;
      }
      FUN_082160d8(p);
      break;
    }
  }
  PlaySound_082406e0(SONG_893);
}

// 鳴っている BGM / SE / ボイスのアイコンを出し, 止まったら1回再生して消す
// 残差は icons[i] の歩きポインタと定数 1 のレジスタ (r5/r6) の入れ替わりだけ (85/85)
// 歩きポインタを for に持たせる形 (82 命令) と宣言順の入れ替えは試済, id を s32 にして (s16) で表を読むと ldrsh になる
NON_MATCH void FUN_08216894(EntityA288* p) {
#ifdef NONMATCHING_C
  EntityA288SoundTest* s = &p->soundTest;
  s32 i;

  for (i = 0; i < 3; i++) {
    MainSprite* icon = &s->icons[i];
    s32 id;

    switch (i) {
      case 0: {
        id = (s16)u16_ARRAY_085afa30[s->playing[0]];
        break;
      }
      case 1: {
        id = (s16)u16_ARRAY_085afaee[s->playing[1]];
        break;
      }
      case 2: {
        id = (s16)u16_ARRAY_085afeb2[s->playing[2]];
        break;
      }
      default: {
        return;
      }
    }

    if (sound_08240960(id)) {
      icon->flags &= ~SPRFLAG_HIDDEN;
      MainSprite_AdvanceAnim(icon, &p->gfx);
    } else if (!(icon->flags & SPRFLAG_HIDDEN)) {
      icon->playMode = PLAYMODE_ONCE_AND_STOP;
      if (MainSprite_AdvanceAnim(icon, &p->gfx)) {
        icon->flags |= SPRFLAG_HIDDEN;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_08216894.inc");
#endif
}

// lines の4行を順に out へ連結する, 1行は 256 文字で打ち切る
void FUN_08216968(u8 lines[4][256], u8* out) {
  s32 i;

  for (i = 0; i < 4; i++) {
    u8* src = lines[i];
    s32 n = 0;

    while (n <= 255 && *src != 0) {
      *out++ = *src++;
      n++;
    }
  }
  *out = 0;
}

// 文字入力のスプライト3枚を隠した状態で置く
void FUN_082169a0(EntityA288* p) {
  Vec3 pos;
  EntityA288TextInput* in = &p->input;

  Vec3_Clear(&pos);
  MainSprite_Add(&in->sprites[0], &p->gfx, 21, 0x30, 0, 0, 60, &pos);
  in->sprites[0].flags |= SPRFLAG_HIDDEN;
  MainSprite_Add(&in->sprites[1], &p->gfx, 78, 0x30, 0, 0, 60, &pos);
  in->sprites[1].flags |= SPRFLAG_HIDDEN;
  MainSprite_Add(&in->sprites[2], &p->gfx, 33, 0x30, 0, 0, 60, &pos);
  in->sprites[2].flags |= SPRFLAG_HIDDEN;
  in->len = 0;
}

void FUN_08216a60(EntityA288* p) {
  MainSprite_Remove(&p->input.sprites[0]);
  MainSprite_Remove(&p->input.sprites[1]);
  MainSprite_Remove(&p->input.sprites[2]);
}

// 文字盤の unk_978 番目のマスにカーソル (sprites[0]) を置く
void FUN_08216a90(EntityA288* p) {
  u8 xs[8];
  u8 ys[8];
  EntityA288TextInput* in;

  memcpy(xs, u8_ARRAY_082527e0, sizeof(xs));
  memcpy(ys, u8_ARRAY_082527e8, sizeof(ys));
  in = &p->input;
  if (in->unk_978 < 60) {
    s16 col = Mod(in->unk_978, 5);
    s16 row;

    if (in->unk_978 < 30) {
      row = Div(in->unk_978, 5);
      in->sprites[0].pos.x = xs[col];
      in->sprites[0].pos.y = ys[row];
    } else {
      row = Div(in->unk_978 - 30, 5);
      in->sprites[0].pos.x = xs[col] + 88;
      in->sprites[0].pos.y = ys[row];
    }
  } else {
    switch ((s16)(in->unk_978 - 60)) {
      case 0: {
        in->sprites[0].pos.x = 176;
        in->sprites[0].pos.y = 0;
        break;
      }
      case 1: {
        in->sprites[0].pos.x = 192;
        in->sprites[0].pos.y = 0;
        break;
      }
      case 2: {
        in->sprites[0].pos.x = 176;
        in->sprites[0].pos.y = 16;
        break;
      }
      case 3: {
        in->sprites[0].pos.x = 192;
        in->sprites[0].pos.y = 16;
        break;
      }
      case 4: {
        in->sprites[0].pos.x = 176;
        in->sprites[0].pos.y = 32;
        break;
      }
      case 5: {
        in->sprites[0].pos.x = 0;
        in->sprites[0].pos.y = 0;
        break;
      }
    }
  }

  if (in->unk_978 == 65) {
    MainSprite_SetAnim(&in->sprites[0], &p->gfx, 9, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
  } else {
    in->sprites[0].pos.y += 32;
    MainSprite_SetAnim(&in->sprites[0], &p->gfx, 1, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
  }
  in->sprites[0].flags &= ~SPRFLAG_HIDDEN;
}

// 入力位置にカーソル (sprites[2]) を置く
void FUN_08216bdc(EntityA288* p) {
  u8 xs[12];
  EntityA288TextInput* in;

  memcpy(xs, u8_ARRAY_082527f0, sizeof(xs));
  in = &p->input;
  if (in->len <= 11) {
    in->sprites[2].pos.x = xs[in->len];
    in->sprites[2].pos.y = 0;
  } else {
    in->sprites[2].pos.x = xs[in->len - 12];
    in->sprites[2].pos.y = 16;
  }
  in->sprites[2].pos.x -= 128;
  in->sprites[2].pos.y += 16;
  in->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&in->sprites[2], &p->gfx, 0, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
}

// sprites[1] を 78 番のポーズで表示する
void FUN_08216c88(EntityA288* p) {
  MainSprite* sprites = p->input.sprites;

  FUN_08216a90(p);
  MainSprite_SetPose(&sprites[1], &p->gfx, 78, PLAYMODE_LOOP);
  sprites[1].flags &= ~SPRFLAG_HIDDEN;
  FUN_08216bdc(p);
}

void FUN_08216cc4(EntityA288* p) {
  p->input.sprites[0].flags |= SPRFLAG_HIDDEN;
  p->input.sprites[1].flags |= SPRFLAG_HIDDEN;
  p->input.sprites[2].flags |= SPRFLAG_HIDDEN;
}

// 入力中の文字を6文字ずつ lines に組み立て, draw なら4行を描く
void FUN_08216cf4(EntityA288* p, s32 draw) {
  EntityA288TextInput* in = &p->input;
  u8* dst = in->lines[0];
  s32 i;

  for (i = 0; i < 24; i++) {
    s32 c = in->chars[i];
    char* s;

    switch (i) {
      case 0: {
        dst = in->lines[0];
        break;
      }
      case 6: {
        dst = in->lines[1];
        break;
      }
      case 12: {
        dst = in->lines[2];
        break;
      }
      case 18: {
        dst = in->lines[3];
        break;
      }
    }

    s = GetStringByID(VM_ParseStringRef(in->unk_124) + c);
    while (*s != 0) {
      *dst = *s;
      dst++;
      s++;
    }
    *dst = 0;
  }

  if (draw) {
    Video_ClearTextRect(2, 3, 26, 4);
    Video_DrawText(2, 3, in->lines[0]);
    Video_DrawText(16, 3, in->lines[1]);
    Video_DrawText(2, 5, in->lines[2]);
    Video_DrawText(16, 5, in->lines[3]);
  }
}

// 入力欄の idx 文字目を描き直す
void FUN_08216dd8(EntityA288* p, s32 idx) {
  u8 pos[4][2];
  s32 row;
  s32 x, y;
  char* s;

  memcpy(pos, u8_ARRAY_082527fc, sizeof(pos));
  row = Div(idx, 6);
  x = (idx - row * 6) * 2 + pos[row][0];
  y = pos[row][1];
  s = GetStringByID(VM_ParseStringRef(p->input.unk_124) + p->input.chars[idx]);
  Video_ClearTextRect(x, y, 2, 2);
  Video_DrawText(x, y, s);
}

// 文字を1つ積む, 入りきらなければ 1 を返す
s32 FUN_08216e60(EntityA288* p, s32 c) {
  s32 len;
  s32 full;

  p->input.chars[p->input.len] = c;
  len = p->input.len;
  if (p->input.len <= 0x16) {
    p->input.len++;
    full = 0;
  } else {
    full = 1;
  }

  FUN_08216dd8(p, len);
  FUN_08216bdc(p);
  return full;
}

// 入力中の文字を1つ消す ('A' に戻す), 先頭で消すものがなければ 1 を返す
s32 FUN_08216ea8(EntityA288* p) {
  EntityA288TextInput* in = &p->input;
  s32 ret = 0;

  if (in->chars[in->len] == 'A') {
    if (in->len == 0) {
      ret = 1;
    } else {
      in->len--;
      in->chars[in->len] = 'A';
    }
  } else {
    in->chars[in->len] = 'A';
  }

  FUN_08216dd8(p, in->len);
  FUN_08216bdc(p);
  return ret;
}

// パスワード入力画面の1フレーム, 確定で 1 (成功) か 2 (失敗), 先頭で B なら 3 を返す
s32 FUN_08216f0c(EntityA288* p) {
  EntityA288TextInput* in = &p->input;

  switch (in->unk_976) {
    case 0: {
      if (!TEST_FLAGS(p->flags, 0x10)) {
        in->unk_978 = 0;
        CpuFill32(0x41414141, in->chars, sizeof(in->chars));
      } else {
        p->flags &= ~0x10;
        FUN_08216cf4(p, 1);
        if (TEST_FLAGS(p->flags, 0x20)) {
          p->flags &= ~0x20;
          in->len = 23;
        }
        in->unk_978 = 65;
      }
      FUN_08216a90(p);
      FUN_08216bdc(p);
      p->unk_68 = 0;
      p->unk_6c = 0;
      in->unk_976 = 1;
      break;
    }
    case 1: {
      s32 h, v;

      if (gInput[0].pressed & B_BUTTON) {
        PlaySound_082406e0(SE_CANCEL);
        if (FUN_08216ea8(p)) {
          return 3;
        }
      } else if (gInput[0].pressed & A_BUTTON) {
        if (in->unk_978 != 65) {
          PlaySound_082406e0(SE_SELECT);
          if (FUN_08216e60(p, in->unk_978)) {
            in->unk_978 = 65;
            FUN_08216a90(p);
          }
        } else {
          in->unk_976 = 2;
        }
      } else if (gInput[0].pressed & START_BUTTON) {
        if (in->unk_978 != 65) {
          PlaySound_082406e0(SE_CURSOR_MOVE);
          in->unk_978 = 65;
          FUN_08216a90(p);
        } else {
          in->unk_976 = 2;
        }
      } else if (gInput[0].pressed & L_BUTTON) {
        if (in->len > 0) {
          in->len--;
        }
        FUN_08216bdc(p);
        PlaySound_082406e0(SE_CURSOR_MOVE);
      } else if (gInput[0].pressed & R_BUTTON) {
        if (in->len < 23) {
          in->len++;
        }
        FUN_08216bdc(p);
        PlaySound_082406e0(SE_CURSOR_MOVE);
      } else {
        h = 0;
        v = 0;
        if (gInput[0].pressed & DPAD_LEFT) {
          h = 1;
        } else if (gInput[0].pressed & DPAD_RIGHT) {
          h = 2;
        } else if (gInput[0].down & (DPAD_LEFT | DPAD_RIGHT)) {
          p->unk_68++;
          if (p->unk_68 > 14 && Mod(p->unk_68, 5) == 0) {
            h = (gInput[0].down & DPAD_LEFT) ? 1 : 2;
          }
        } else {
          p->unk_68 = 0;
        }
        if (gInput[0].pressed & DPAD_UP) {
          v = 1;
        } else if (gInput[0].pressed & DPAD_DOWN) {
          v = 2;
        } else if (gInput[0].down & (DPAD_UP | DPAD_DOWN)) {
          p->unk_6c++;
          if (p->unk_6c > 14 && Mod(p->unk_6c, 5) == 0) {
            v = (gInput[0].down & DPAD_UP) ? 1 : 2;
          }
        } else {
          p->unk_6c = 0;
        }

        if (h == 1) {
          FUN_0821722c(p);
        } else if (h == 2) {
          FUN_08217440(p);
        }
        if (v == 1) {
          FUN_08217648(p);
        } else if (v == 2) {
          FUN_0821785c(p);
        }
      }
      break;
    }
    case 2: {
      s32 ret;
      u8* name;
      s32 i;

      SET_FLAGS(p->flags, 0x10);
      FUN_08216cf4(p, 0);
      FUN_08216968(in->lines, in->text);
      ret = FUN_08011584(in->text, in->unk_128, in->unk_12c, GetPlayerName());
      name = GetPlayerName();
      for (i = 0; i < 10; i++) {
        if (*name == 0 && i < 9) {
          name[1] = 0;
        }
        name++;
      }
      if (ret == 0) {
        PlaySound_082406e0(SONG_662);
        SET_FLAGS(p->flags, 0x20);
        return 1;
      }
      PlaySound_082406e0(SE_NG);
      return 2;
    }
  }

  MainSprite_AdvanceAnim(&in->sprites[2], &p->gfx);
  MainSprite_AdvanceAnim(&in->sprites[0], &p->gfx);
  return 0;
}

// 文字盤のカーソルを1マス左へ動かす, 左端からは決まったマスへ飛ばす
void FUN_0821722c(EntityA288* p) {
  EntityA288TextInput* in = &p->input;

  switch (in->unk_978) {
    case 0: {
      in->unk_978 = 61;
      break;
    }
    case 5: {
      in->unk_978 = 63;
      break;
    }
    case 10: {
      in->unk_978 = 64;
      break;
    }
    case 15: {
      in->unk_978 = 65;
      break;
    }
    case 20: {
      in->unk_978 = 65;
      break;
    }
    case 25: {
      in->unk_978 = 65;
      break;
    }
    case 30: {
      in->unk_978 = 4;
      break;
    }
    case 35: {
      in->unk_978 = 9;
      break;
    }
    case 40: {
      in->unk_978 = 14;
      break;
    }
    case 45: {
      in->unk_978 = 19;
      break;
    }
    case 50: {
      in->unk_978 = 24;
      break;
    }
    case 55: {
      in->unk_978 = 29;
      break;
    }
    case 60: {
      in->unk_978 = 34;
      break;
    }
    case 62: {
      in->unk_978 = 39;
      break;
    }
    case 64: {
      in->unk_978 = 44;
      break;
    }
    case 65: {
      in->unk_978 = 49;
      break;
    }
    default: {
      in->unk_978--;
      break;
    }
  }
  FUN_08216a90(p);
  PlaySound_082406e0(SE_CURSOR_MOVE);
}

// 文字盤のカーソルを1マス右へ動かす, 右端からは決まったマスへ飛ばす
void FUN_08217440(EntityA288* p) {
  EntityA288TextInput* in = &p->input;

  switch ((s16)(in->unk_978 - 4)) {
    case 0: {
      in->unk_978 = 30;
      break;
    }
    case 5: {
      in->unk_978 = 35;
      break;
    }
    case 10: {
      in->unk_978 = 40;
      break;
    }
    case 15: {
      in->unk_978 = 45;
      break;
    }
    case 20: {
      in->unk_978 = 50;
      break;
    }
    case 25: {
      in->unk_978 = 55;
      break;
    }
    case 30: {
      in->unk_978 = 60;
      break;
    }
    case 35: {
      in->unk_978 = 62;
      break;
    }
    case 40: {
      in->unk_978 = 64;
      break;
    }
    case 45: {
      in->unk_978 = 65;
      break;
    }
    case 50: {
      in->unk_978 = 65;
      break;
    }
    case 55: {
      in->unk_978 = 65;
      break;
    }
    case 57: {
      in->unk_978 = 0;
      break;
    }
    case 59: {
      in->unk_978 = 5;
      break;
    }
    case 60: {
      in->unk_978 = 63;
      break;
    }
    case 61: {
      in->unk_978 = 15;
      break;
    }
    default: {
      in->unk_978++;
      break;
    }
  }
  FUN_08216a90(p);
  PlaySound_082406e0(SE_CURSOR_MOVE);
}

// 文字盤のカーソルを1行上へ動かす, 上端からは決まったマスへ飛ばす
void FUN_08217648(EntityA288* p) {
  EntityA288TextInput* in = &p->input;

  switch (in->unk_978) {
    case 0: {
      in->unk_978 = 25;
      break;
    }
    case 1: {
      in->unk_978 = 26;
      break;
    }
    case 2: {
      in->unk_978 = 27;
      break;
    }
    case 3: {
      in->unk_978 = 28;
      break;
    }
    case 4: {
      in->unk_978 = 29;
      break;
    }
    case 30: {
      in->unk_978 = 55;
      break;
    }
    case 31: {
      in->unk_978 = 56;
      break;
    }
    case 32: {
      in->unk_978 = 57;
      break;
    }
    case 33: {
      in->unk_978 = 58;
      break;
    }
    case 34: {
      in->unk_978 = 59;
      break;
    }
    case 60: {
      in->unk_978 = 65;
      break;
    }
    case 61: {
      in->unk_978 = 65;
      break;
    }
    case 62: {
      in->unk_978 = 60;
      break;
    }
    case 63: {
      in->unk_978 = 61;
      break;
    }
    case 64: {
      in->unk_978 = 62;
      break;
    }
    case 65: {
      in->unk_978 = 64;
      break;
    }
    default: {
      in->unk_978 -= 5;
      break;
    }
  }
  FUN_08216a90(p);
  PlaySound_082406e0(SE_CURSOR_MOVE);
}

// 文字盤のカーソルを1行下へ動かす, 端から外れる行は決まったマスへ飛ばす
void FUN_0821785c(EntityA288* p) {
  EntityA288TextInput* in = &p->input;

  switch ((s16)(in->unk_978 - 25)) {
    case 0: {
      in->unk_978 = 0;
      break;
    }
    case 1: {
      in->unk_978 = 1;
      break;
    }
    case 2: {
      in->unk_978 = 2;
      break;
    }
    case 3: {
      in->unk_978 = 3;
      break;
    }
    case 4: {
      in->unk_978 = 4;
      break;
    }
    case 30: {
      in->unk_978 = 30;
      break;
    }
    case 31: {
      in->unk_978 = 31;
      break;
    }
    case 32: {
      in->unk_978 = 32;
      break;
    }
    case 33: {
      in->unk_978 = 33;
      break;
    }
    case 34: {
      in->unk_978 = 34;
      break;
    }
    case 35: {
      in->unk_978 = 62;
      break;
    }
    case 36: {
      in->unk_978 = 63;
      break;
    }
    case 37: {
      in->unk_978 = 64;
      break;
    }
    case 38: {
      in->unk_978 = 64;
      break;
    }
    case 39: {
      in->unk_978 = 65;
      break;
    }
    case 40: {
      in->unk_978 = 60;
      break;
    }
    default: {
      in->unk_978 += 5;
      break;
    }
  }
  FUN_08216a90(p);
  PlaySound_082406e0(SE_CURSOR_MOVE);
}

// 文字盤の unk_97a 番目のマスにカーソル (sprites[0]) を置く
void FUN_08217a10(EntityA288* p) {
  u8 xs[8];
  u8 ys[8];
  EntityA288TextInput* in;
  s32 anim;

  memcpy(xs, u8_ARRAY_082527e0, sizeof(xs));
  memcpy(ys, u8_ARRAY_08252804, sizeof(ys));
  in = &p->input;
  anim = 1;
  if (in->unk_97a < 80) {
    s16 col = Mod(in->unk_97a, 5);
    s16 row;

    if (in->unk_97a < 40) {
      row = Div(in->unk_97a, 5);
      in->sprites[0].pos.x = xs[col];
      in->sprites[0].pos.y = ys[row];
    } else {
      row = Div(in->unk_97a - 40, 5);
      in->sprites[0].pos.x = xs[col] + 88;
      in->sprites[0].pos.y = ys[row];
    }
  } else {
    switch ((s16)(in->unk_97a - 80)) {
      case 0: {
        in->sprites[0].pos.x = 176;
        in->sprites[0].pos.y = 0;
        break;
      }
      case 1: {
        in->sprites[0].pos.x = 192;
        in->sprites[0].pos.y = 0;
        break;
      }
      case 2: {
        in->sprites[0].pos.x = 176;
        in->sprites[0].pos.y = 16;
        break;
      }
      case 3: {
        in->sprites[0].pos.x = 192;
        in->sprites[0].pos.y = 16;
        break;
      }
      case 4: {
        in->sprites[0].pos.x = 0;
        in->sprites[0].pos.y = -16;
        anim = 2;
        break;
      }
      case 5: {
        in->sprites[0].pos.x = 0;
        in->sprites[0].pos.y = 0;
        anim = 2;
        break;
      }
      case 6: {
        in->sprites[0].pos.x = 0;
        in->sprites[0].pos.y = 0;
        anim = 3;
        break;
      }
    }
  }

  MainSprite_SetAnim(&in->sprites[0], &p->gfx, anim, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
  in->sprites[0].flags &= ~SPRFLAG_HIDDEN;
}

// sprites[2] を unk_972 番目の横位置に出す
void FUN_08217b48(EntityA288* p) {
  u8 xs[6];

  memcpy(xs, u8_ARRAY_0825280c, sizeof(xs));
  p->input.sprites[2].pos.x = xs[p->input.unk_972];
  p->input.sprites[2].pos.y = 0;
  p->input.sprites[2].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->input.sprites[2], &p->gfx, 0, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
}

void FUN_08217bb8(EntityA288* p) {
  FUN_08217a10(p);
  FUN_08217b48(p);
}

void FUN_08217bcc(EntityA288* p) {
  p->input.sprites[0].flags |= SPRFLAG_HIDDEN;
  p->input.sprites[1].flags |= SPRFLAG_HIDDEN;
  p->input.sprites[2].flags |= SPRFLAG_HIDDEN;
}

// text_938 の空きを既定の文字で埋めて描く
void FUN_08217bfc(EntityA288* p) {
  EntityA288TextInput* in = &p->input;
  u8 buf[32];
  u8* c;
  s32 i;

  CpuCopy32(in->text_938, buf, sizeof(buf));
  c = buf;
  for (i = 0; i < 5; i++) {
    if (c[0] == 0 && c[1] == 0) {
      char* s = GetStringByID(VM_ParseStringRef(in->unk_134) + 0x54);

      c[0] = s[0];
      c[1] = s[1];
    }
    c += 2;
  }

  Video_ClearTextRect(18, 1, 10, 2);
  Video_DrawText(18, 1, buf);
}

// BG2 のレイヤーを表裏で切り替えて決定音を鳴らす
void FUN_08217c6c(EntityA288* p) {
  s32 layer;

  p->input.unk_974 = 1 - p->input.unk_974;
  layer = p->input.unk_974;
  Video_SetBGLayer(2, p->tilemap, layer);
  Video_GenerateBGMap(2, 0, 0, 0, 0);
  p->unk_64 = layer;
  if (p->input.unk_974 == 1 && p->input.unk_97a == 79) {
    p->input.unk_97a = 78;
    FUN_08217a10(p);
  }
  PlaySound_082406e0(SE_SELECT);
}

// 入力欄に文字を1つ足す, 5文字目まで埋まっていたら 1 を返す
s32 FUN_08217cd0(EntityA288* p, s32 ofs) {
  EntityA288TextInput* in = &p->input;
  u8* dst = &in->text_938[in->unk_972 * 2];
  char* s;
  s32 ret;

  s = GetStringByID(VM_ParseStringRef(in->unk_974 == 0 ? in->unk_134 : in->unk_130) + ofs);
  dst[0] = s[0];
  dst[1] = s[1];
  if (in->unk_972 <= 3) {
    in->unk_972++;
    ret = 0;
  } else {
    ret = 1;
  }

  FUN_08217bfc(p);
  FUN_08217b48(p);
  return ret;
}

// 入力欄の文字を1つ消す, 先頭で消すものがなければ 1 を返す
s32 FUN_08217d5c(EntityA288* p) {
  EntityA288TextInput* in = &p->input;
  u8* c = &in->text_938[in->unk_972 * 2];
  char* blank = GetStringByID(VM_ParseStringRef(in->unk_134) + 0x54);
  s32 ret = 0;

  if ((c[0] == 0 && c[1] == 0) || (c[0] == blank[0] && c[1] == blank[1])) {
    if (in->unk_972 == 0) {
      ret = 1;
    } else {
      in->unk_972--;
      c = &in->text_938[in->unk_972 * 2];
      c[0] = 0;
      c[1] = 0;
    }
  } else {
    c[0] = 0;
    c[1] = 0;
  }

  FUN_08217bfc(p);
  FUN_08217b48(p);
  return ret;
}

// 名前入力画面の1フレーム, 確定で 1, 先頭で B なら 2 を返す
// 残差は case 0 の文字数を数えるループ (336/343), 原典は 0x938 をレジスタに置いて in + (0x938 + n * 2) で引き, こちらは text_938 の歩きポインタに畳まれる
// while + break / do-while / flags の読み順 (TEST_FLAGS とローカル) は試済, 入力処理の case 1 と case 2 は FUN_08216f0c と同じ形
NON_MATCH s32 FUN_08217e00(EntityA288* p) {
#ifdef NONMATCHING_C
  EntityA288TextInput* in = &p->input;

  switch (in->unk_976) {
    case 0: {
      SpriteFlags flags = p->flags;
      s32 n;

      if (!TEST_FLAGS(flags, 0x200)) {
        if (!(flags & 0x20)) {
          FUN_08218b20(GetPlayerName());
        }
        in->unk_97a = 0;
      } else {
        p->flags = flags & ~0x200;
        in->unk_97a = 86;
      }
      CpuFill32(0, in->text_938, sizeof(in->text_938));
      CpuCopy16(GetPlayerName(), in->text_938, 10);
      for (n = 0; n < 5 && in->text_938[n * 2] != 0; n++) {
      }
      in->unk_972 = n == 5 ? 4 : n;
      Video_SetBGLayer(2, p->tilemap, 0);
      Video_GenerateBGMap(2, 0, 0, 0, 0);
      p->unk_64 = 0;
      in->unk_974 = 0;
      FUN_08217bfc(p);
      FUN_08217a10(p);
      FUN_08217b48(p);
      p->unk_68 = 0;
      p->unk_6c = 0;
      in->unk_976 = 1;
      break;
    }
    case 1: {
      s32 h, v;

      if (gInput[0].pressed & B_BUTTON) {
        PlaySound_082406e0(SE_CANCEL);
        if (FUN_08217d5c(p)) {
          return 2;
        }
      } else if (gInput[0].pressed & A_BUTTON) {
        if (in->unk_97a == 85) {
          FUN_08217c6c(p);
        } else if (in->unk_97a != 86) {
          PlaySound_082406e0(SE_SELECT);
          if (FUN_08217cd0(p, in->unk_97a)) {
            in->unk_97a = 86;
            FUN_08217a10(p);
          }
        } else {
          in->unk_976 = 2;
        }
      } else if (gInput[0].pressed & START_BUTTON) {
        if (in->unk_97a != 86) {
          PlaySound_082406e0(SE_CURSOR_MOVE);
          in->unk_97a = 86;
          FUN_08217a10(p);
        } else {
          in->unk_976 = 2;
        }
      } else if (gInput[0].pressed & SELECT_BUTTON) {
        FUN_08217c6c(p);
      } else if (gInput[0].pressed & L_BUTTON) {
        if (in->unk_972 > 0) {
          in->unk_972--;
        }
        FUN_08217b48(p);
        PlaySound_082406e0(SE_CURSOR_MOVE);
      } else if (gInput[0].pressed & R_BUTTON) {
        if (in->unk_972 < 4) {
          in->unk_972++;
        }
        FUN_08217b48(p);
        PlaySound_082406e0(SE_CURSOR_MOVE);
      } else {
        h = 0;
        v = 0;
        if (gInput[0].pressed & DPAD_LEFT) {
          h = 1;
        } else if (gInput[0].pressed & DPAD_RIGHT) {
          h = 2;
        } else if (gInput[0].down & (DPAD_LEFT | DPAD_RIGHT)) {
          p->unk_68++;
          if (p->unk_68 > 14 && Mod(p->unk_68, 5) == 0) {
            h = (gInput[0].down & DPAD_LEFT) ? 1 : 2;
          }
        } else {
          p->unk_68 = 0;
        }
        if (gInput[0].pressed & DPAD_UP) {
          v = 1;
        } else if (gInput[0].pressed & DPAD_DOWN) {
          v = 2;
        } else if (gInput[0].down & (DPAD_UP | DPAD_DOWN)) {
          p->unk_6c++;
          if (p->unk_6c > 14 && Mod(p->unk_6c, 5) == 0) {
            v = (gInput[0].down & DPAD_UP) ? 1 : 2;
          }
        } else {
          p->unk_6c = 0;
        }

        if (h == 1) {
          FUN_0821813c(p);
        } else if (h == 2) {
          FUN_082183e0(p);
        }
        if (v == 1) {
          FUN_0821869c(p);
        } else if (v == 2) {
          FUN_08218910(p);
        }
      }
      break;
    }
    case 2: {
      SET_FLAGS(p->flags, 0x200);
      FUN_08218b34(p, in->text_938);
      CpuCopy16(in->text_938, GetPlayerName(), 10);
      PlaySound_082406e0(SE_SELECT);
      return 1;
    }
  }

  MainSprite_AdvanceAnim(&in->sprites[2], &p->gfx);
  MainSprite_AdvanceAnim(&in->sprites[0], &p->gfx);
  return 0;
#else
  INCFUNC("asm/func/FUN_08217e00.inc");
#endif
}

// unk_97a 側の文字盤のカーソルを1マス左へ動かす, 左端からは決まったマスへ飛ばす
void FUN_0821813c(EntityA288* p) {
  EntityA288TextInput* in = &p->input;

  switch (in->unk_97a) {
    case 0: {
      in->unk_97a = 81;
      break;
    }
    case 5: {
      in->unk_97a = 83;
      break;
    }
    case 10: {
      in->unk_97a = 84;
      break;
    }
    case 15: {
      in->unk_97a = 85;
      break;
    }
    case 20: {
      in->unk_97a = 86;
      break;
    }
    case 25: {
      in->unk_97a = 86;
      break;
    }
    case 30: {
      in->unk_97a = 86;
      break;
    }
    case 35: {
      in->unk_97a = 86;
      break;
    }
    case 40: {
      in->unk_97a = 4;
      break;
    }
    case 45: {
      in->unk_97a = 9;
      break;
    }
    case 50: {
      in->unk_97a = 14;
      break;
    }
    case 55: {
      in->unk_97a = 19;
      break;
    }
    case 60: {
      in->unk_97a = 24;
      break;
    }
    case 65: {
      in->unk_97a = 29;
      break;
    }
    case 70: {
      in->unk_97a = 34;
      break;
    }
    case 75: {
      in->unk_97a = 39;
      break;
    }
    case 80: {
      in->unk_97a = 44;
      break;
    }
    case 82: {
      in->unk_97a = 49;
      break;
    }
    case 84: {
      in->unk_97a = 54;
      break;
    }
    case 85: {
      in->unk_97a = 59;
      break;
    }
    case 86: {
      in->unk_97a = 64;
      break;
    }
    default: {
      in->unk_97a--;
      break;
    }
  }
  FUN_08217a10(p);
  PlaySound_082406e0(SE_CURSOR_MOVE);
}

// unk_97a 側の文字盤のカーソルを1マス右へ動かす, 右端からは決まったマスへ飛ばす
void FUN_082183e0(EntityA288* p) {
  EntityA288TextInput* in = &p->input;

  switch ((s16)(in->unk_97a - 4)) {
    case 0: {
      in->unk_97a = 40;
      break;
    }
    case 5: {
      in->unk_97a = 45;
      break;
    }
    case 10: {
      in->unk_97a = 50;
      break;
    }
    case 15: {
      in->unk_97a = 55;
      break;
    }
    case 20: {
      in->unk_97a = 60;
      break;
    }
    case 25: {
      in->unk_97a = 65;
      break;
    }
    case 30: {
      in->unk_97a = 70;
      break;
    }
    case 35: {
      in->unk_97a = 75;
      break;
    }
    case 40: {
      in->unk_97a = 80;
      break;
    }
    case 45: {
      in->unk_97a = 82;
      break;
    }
    case 50: {
      in->unk_97a = 84;
      break;
    }
    case 55: {
      in->unk_97a = 85;
      break;
    }
    case 60: {
      in->unk_97a = 86;
      break;
    }
    case 65: {
      in->unk_97a = 86;
      break;
    }
    case 70: {
      in->unk_97a = 86;
      break;
    }
    case 75: {
      in->unk_97a = 86;
      break;
    }
    case 77: {
      in->unk_97a = 0;
      break;
    }
    case 79: {
      in->unk_97a = 5;
      break;
    }
    case 80: {
      in->unk_97a = 10;
      break;
    }
    case 81: {
      in->unk_97a = 15;
      break;
    }
    case 82: {
      in->unk_97a = 20;
      break;
    }
    default: {
      if (in->unk_974 == 1 && in->unk_97a == 78) {
        in->unk_97a = 74;
      } else {
        in->unk_97a++;
      }
      break;
    }
  }
  FUN_08217a10(p);
  PlaySound_082406e0(SE_CURSOR_MOVE);
}

// unk_97a 側の文字盤のカーソルを1行上へ動かす, 上端からは決まったマスへ飛ばす
void FUN_0821869c(EntityA288* p) {
  EntityA288TextInput* in = &p->input;

  switch (in->unk_97a) {
    case 0: {
      in->unk_97a = 35;
      break;
    }
    case 1: {
      in->unk_97a = 36;
      break;
    }
    case 2: {
      in->unk_97a = 37;
      break;
    }
    case 3: {
      in->unk_97a = 38;
      break;
    }
    case 4: {
      in->unk_97a = 39;
      break;
    }
    case 40: {
      in->unk_97a = 75;
      break;
    }
    case 41: {
      in->unk_97a = 76;
      break;
    }
    case 42: {
      in->unk_97a = 77;
      break;
    }
    case 43: {
      in->unk_97a = 78;
      break;
    }
    case 44: {
      in->unk_97a = 79;
      break;
    }
    case 80: {
      in->unk_97a = 86;
      break;
    }
    case 81: {
      in->unk_97a = 86;
      break;
    }
    case 82: {
      in->unk_97a = 80;
      break;
    }
    case 83: {
      in->unk_97a = 81;
      break;
    }
    case 84: {
      in->unk_97a = 82;
      break;
    }
    case 85: {
      in->unk_97a = 84;
      break;
    }
    case 86: {
      in->unk_97a = 85;
      break;
    }
    default: {
      in->unk_97a -= 5;
      break;
    }
  }
  FUN_08217a10(p);
  PlaySound_082406e0(SE_CURSOR_MOVE);
}

// unk_97a 側の文字盤のカーソルを1行下へ動かす, 端から外れる行は決まったマスへ飛ばす
void FUN_08218910(EntityA288* p) {
  EntityA288TextInput* in = &p->input;

  switch ((s16)(in->unk_97a - 35)) {
    case 0: {
      in->unk_97a = 0;
      break;
    }
    case 1: {
      in->unk_97a = 1;
      break;
    }
    case 2: {
      in->unk_97a = 2;
      break;
    }
    case 3: {
      in->unk_97a = 3;
      break;
    }
    case 4: {
      in->unk_97a = 4;
      break;
    }
    case 40: {
      in->unk_97a = 40;
      break;
    }
    case 41: {
      in->unk_97a = 41;
      break;
    }
    case 42: {
      in->unk_97a = 42;
      break;
    }
    case 43: {
      in->unk_97a = 43;
      break;
    }
    case 44: {
      in->unk_97a = 44;
      break;
    }
    case 45: {
      in->unk_97a = 82;
      break;
    }
    case 46: {
      in->unk_97a = 83;
      break;
    }
    case 47: {
      in->unk_97a = 84;
      break;
    }
    case 48: {
      in->unk_97a = 84;
      break;
    }
    case 49: {
      in->unk_97a = 85;
      break;
    }
    case 50: {
      in->unk_97a = 86;
      break;
    }
    case 51: {
      in->unk_97a = 80;
      break;
    }
    default: {
      if (in->unk_974 == 1 && in->unk_97a == 74) {
        in->unk_97a = 78;
      } else {
        in->unk_97a += 5;
      }
      break;
    }
  }
  FUN_08217a10(p);
  PlaySound_082406e0(SE_CURSOR_MOVE);
}

const u8 gStringDjango_085aff78[] = _("ジャンゴ");

// 名前欄に "ジャンゴ" を書き込む, 転送量は文字列の長さではなく名前欄の 10 バイト
void FUN_08218b20(u8* dst) { CpuCopy16(gStringDjango_085aff78, dst, 10); }

// 名前の空白を詰め直す, 全部空白なら既定の名前を入れる
// 残差は最後の書き戻しループだけ, 原典は i を ip に残したまま buf[0] で先に判定し, ループ末尾で i > 4 を src より先に見る
// while + i++ / for の条件に i < 5 を入れる形 / 添字で書く形は試済, 前半の空白詰めは一致
NON_MATCH void FUN_08218b34(EntityA288* p, u8* name) {
#ifdef NONMATCHING_C
  u8 buf[32];
  char* blank;
  u8* src;
  u8* dst;
  s32 i, j;

  CpuCopy32(name, buf, sizeof(buf));
  blank = GetStringByID(VM_ParseStringRef(p->input.unk_134) + 0x54);
  for (i = 0; i < 5; i++) {
    u8* c = &buf[i * 2];

    if ((c[0] == 0 && c[1] == 0) || (c[0] == blank[0] && c[1] == blank[1])) {
      c[0] = c[1] = 0;
      for (j = i + 1; j < 5; j++) {
        u8* d = &buf[j * 2];

        if (!((d[0] == 0 && d[1] == 0) || (d[0] == blank[0] && d[1] == blank[1]))) {
          c[0] = blank[0];
          c[1] = blank[1];
          break;
        }
        if (i == 0 && j == 4) {
          FUN_08218b20(name);
          return;
        }
      }
    }
  }

  CpuFill32(0, name, sizeof(buf));
  src = buf;
  dst = name;
  for (i = 0; i < 5 && *src != 0; i++) {
    dst[0] = src[0];
    dst[1] = src[1];
    src += 2;
    dst += 2;
  }
#else
  INCFUNC("asm/func/FUN_08218b34.inc");
#endif
}

// 顔アイコンのファイルを開き, スプライトとテキストパネルを用意する
void FUN_08218c30(EntityA288* p) {
  Vec3 pos;
  EntityA288Sub12C8* s = &p->sub12c8;
  MainSpriteGfxFile* f;
  s32 i;

  Vec3_Clear(&pos);
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_PORTRAITS);
  s->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&s->gfx, f);
  pos.x = 24;
  pos.y = 40;
  MainSprite_Add(&s->sprite_20, &s->gfx, 0, 0x30, 1, 0, 60, &pos);
  s->sprite_20.flags |= SPRFLAG_HIDDEN;
  pos.x = 0;
  pos.y = -32;
  MainSprite_Add(&s->sprite_80, &p->gfx, 62, 0x30, 1, 0, 60, &pos);
  s->sprite_80.flags |= SPRFLAG_HIDDEN;

  pos.x = 168;
  pos.y = 40;
  for (i = 0; i < 5; i++) {
    MainSprite_Add(&s->sprites_e0[i], &p->gfx, i == 2 ? 20 : 0, 0x30, 1, 0, 60, &pos);
    s->sprites_e0[i].pos.x += i * 8;
    s->sprites_e0[i].flags |= SPRFLAG_HIDDEN;
  }

  pos.x = 192;
  pos.y = 56;
  for (i = 0; i < 2; i++) {
    MainSprite_Add(&s->sprites_2c0[i], &p->gfx, 0, 0x30, 1, 0, 60, &pos);
    s->sprites_2c0[i].pos.x += i * 8;
    s->sprites_2c0[i].flags |= SPRFLAG_HIDDEN;
  }

  s->windowIDs[0] = TextPanel_Create(8, 7, 12, 2);
  s->windowIDs[1] = TextPanel_Create(3, 10, 24, 2);
}

// スプライトとテキストパネルを片付ける
void FUN_08218ddc(EntityA288* p) {
  MainSprite* sprite;
  s32 i;

  MainSprite_Remove(&p->sub12c8.sprite_20);
  MainSprite_Remove(&p->sub12c8.sprite_80);

  sprite = p->sub12c8.sprites_e0;
  for (i = 0; i < 5; i++) {
    MainSprite_Remove(sprite);
    sprite++;
  }

  sprite = p->sub12c8.sprites_2c0;
  for (i = 0; i < 2; i++) {
    MainSprite_Remove(sprite);
    sprite++;
  }

  TextPanel_Destroy(p->sub12c8.windowIDs[0]);
  TextPanel_Destroy(p->sub12c8.windowIDs[1]);
}

void FUN_08218e4c(EntityA288* p) {
  if (gStat->unk_93a != 0) {
    p->sub12c8.unk_394 = 0;
  } else {
    p->sub12c8.unk_394 = 1;
  }

  p->sub12c8.unk_396 = 0;
}

// 残差はスタックの退避枠 (原典 0x80, こちら 0x70) と gStat / sub12c8 を持つ高位レジスタの割り当て (411/404)
// buf / poses / tiles / sabata を関数の先頭で宣言する順は原典の sp 配置と一致, playerKind の分岐を if/else にする形も試済
// セーブデータの情報 (名前, 顔, 称号, 周回, プレイ時間, レベル) を描く
NON_MATCH void FUN_08218e90(EntityA288* p) {
#ifdef NONMATCHING_C
  u8 buf[32];
  u32 poses[3];
  u8 tiles[36];
  char sabata[10];
  EntityA288Sub12C8* s;
  s32 i;

  memcpy(poses, u32_ARRAY_08252814, sizeof(poses));
  memcpy(tiles, u8_ARRAY_08252820, sizeof(tiles));
  s = &p->sub12c8;
  ClearBGTilemapBuffer(0);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  if (gStat->unk_93a != 0) {
    char* str;
    u8* d;
    s32 k;
    s32 hours, minutes, lv;

    memcpy(sabata, gStringSabata_08252844, sizeof(sabata));
    if (gStat->playerKind == 5) {
      str = sabata;
    } else {
      str = GetPlayerName();
    }
    Video_ClearTextRect(8, 7, 12, 2);
    Video_DrawText(8, 7, str);
    if (gStat->playerKind == 0) {
      k = 0;
    } else if (gStat->playerKind == 5) {
      k = 1;
    } else {
      k = 2;
    }
    MainSprite_SetPose(&s->sprite_20, &s->gfx, poses[k], PLAYMODE_LOOP);
    s->sprite_20.flags &= ~SPRFLAG_HIDDEN;
    for (i = 0; i < 12; i++) {
      Video_SetBGTile(2, i + 8, 6, tiles[k * 12 + i], 0, 2);
    }

    Video_ClearTextRect(3, 10, 24, 2);
    CpuFill32(0, buf, sizeof(buf));
    str = GetStringByID(VM_ParseStringRef(s->unk_390) + FUN_0808fc14());
    buf[0] = 0x80;
    buf[1] = 0xB9;
    d = &buf[2];
    while (*str != 0) {
      *d = *str;
      str++;
      d++;
    }
    d[0] = 0x80;
    d[1] = 0xBA;
    Video_DrawText(3, 10, buf);

    if (gStat->lap > 0) {
      s->sprite_80.flags &= ~SPRFLAG_HIDDEN;
    }

    hours = Div(gStat->playTime, 60 * 60 * 60);
    minutes = Div(gStat->playTime, 60 * 60) - hours * 60;
    if (hours > 99) {
      hours = 99;
      minutes = 59;
    }
    MainSprite_SetPose(&s->sprites_e0[1], &p->gfx, Mod(hours, 10), PLAYMODE_LOOP);
    MainSprite_SetPose(&s->sprites_e0[0], &p->gfx, Mod(Div(hours, 10), 10), PLAYMODE_LOOP);
    s->sprites_e0[0].flags &= ~SPRFLAG_HIDDEN;
    s->sprites_e0[1].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&s->sprites_e0[4], &p->gfx, Mod(minutes, 10), PLAYMODE_LOOP);
    MainSprite_SetPose(&s->sprites_e0[3], &p->gfx, Mod(Div(minutes, 10), 10), PLAYMODE_LOOP);
    s->sprites_e0[3].flags &= ~SPRFLAG_HIDDEN;
    s->sprites_e0[4].flags &= ~SPRFLAG_HIDDEN;
    s->sprites_e0[2].flags &= ~SPRFLAG_HIDDEN;

    if (gStat->playerKind == 5) {
      lv = gStat->lv + 10;
      if (lv > 99) {
        lv = 99;
      }
    } else {
      lv = gStat->lv;
    }
    MainSprite_SetPose(&s->sprites_2c0[1], &p->gfx, Mod(lv, 10), PLAYMODE_LOOP);
    MainSprite_SetPose(&s->sprites_2c0[0], &p->gfx, Mod(Div(lv, 10), 10), PLAYMODE_LOOP);
    s->sprites_2c0[0].flags &= ~SPRFLAG_HIDDEN;
    s->sprites_2c0[1].flags &= ~SPRFLAG_HIDDEN;

    str = GetStringByID(VM_ParseStringRef(s->unk_388) + 3);
    Video_ClearTextRect(21, 7, 3, 2);
    Video_DrawText(21, 7, str);
  } else {
    char* str;

    for (i = 0; i < 9; i++) {
      Video_SetBGTile(2, i + 8, 6, 1, 0, 2);
    }
    str = GetStringByID(VM_ParseStringRef(s->unk_388) + 2);
    Video_ClearTextRect(8, 6, 18, 2);
    Video_DrawText(8, 6, str);
  }
#else
  INCFUNC("asm/func/FUN_08218e90.inc");
#endif
}

// BG を消してスプライトとテキストパネルを隠す
void FUN_08219238(EntityA288* p) {
  s32 i;

  ClearBGTilemapBuffer(0);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  ClearBGTilemapBuffer(2);
  Video_GenerateBGMap(2, 0, 0, 0, 0);
  ClearBGTilemapBuffer(3);
  Video_GenerateBGMap(3, 0, 0, 0, 0);

  p->sub12c8.sprite_20.flags |= SPRFLAG_HIDDEN;
  p->sub12c8.sprite_80.flags |= SPRFLAG_HIDDEN;
  for (i = 0; i < 5; i++) {
    p->sub12c8.sprites_e0[i].flags |= SPRFLAG_HIDDEN;
  }
  for (i = 0; i < 2; i++) {
    p->sub12c8.sprites_2c0[i].flags |= SPRFLAG_HIDDEN;
  }

  TextPanel_Hide(p->sub12c8.windowIDs[0]);
  TextPanel_Hide(p->sub12c8.windowIDs[1]);
}

// 下書き1回で止めた (994/983), 14 個のサブ state の流れは asm から起こした, 残差は他の state と同じく flags の bit の読み方と遷移の合流
// Ghidra はジャンプテーブルを復元できないので case の中身は asm を直接読んだ
// タイトルのセーブ選択の state, つづきから / はじめから / パスワード / 名前入力 を行き来する
NON_MATCH void FUN_082192f4(EntityA288* p) {
#ifdef NONMATCHING_C
  s32* fade = p->fade;
  EntityA288Sub12C8* s = &p->sub12c8;

  if (p->flags & 1) {
    p->flags &= ~1;
    ClearBGTilemapBuffer(0);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    ClearBGTilemapBuffer(2);
    Video_GenerateBGMap(2, 0, 0, 0, 0);
    ClearBGTilemapBuffer(3);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    if (Save_ReadCurrentSlot()) {
      gStat->unk_93a = 1;
      p->unk_5c = 1;
      p->timer2 = 0;
    } else if (Save_ReadFromNextSlot()) {
      gStat->unk_93a = 1;
      p->unk_5c = 0;
      p->timer2 = 0;
    } else {
      gStat->unk_93a = 0;
      p->unk_5c = 1;
      p->timer2 = 0;
    }
    SET_FLAGS(p->flags, 2);
    if (gStat->unk_93a != 0) {
      Save_BackupStatAndWorld();
    }
    FUN_08218e4c(p);
    s->unk_3a0 = 0;
  }

  switch (p->unk_5c) {
    case 0: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08219238(p);
        FUN_082139b4(p, 0);
        MessageWindow_Start(s->unk_388);
        MessageWindow_ShowLine(1);
        MessageWindow_SetRect(1, 7, 28, 4);
        MessageWindow_SetInstant(1);
      }
      p->flags &= ~2;
      if (p->timer2 > 29 && FUN_08213a64(p) == 1) {
        p->unk_5c = 1;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 1: {
      if (p->flags & 2) {
        s32 layer;

        p->flags &= ~2;
        FUN_08213a50(p);
        layer = 4;
        Video_SetBGLayer(2, p->tilemap, layer);
        Video_GenerateBGMap(2, 0, 0, 0, 0);
        p->unk_64 = layer;
        if (gStat->unk_93a != 0) {
          RestoreGameState();
        }
        FUN_08218e90(p);
        s->unk_396 = 0;
        if (s->unk_3a0 == 0) {
          PlaySound_082406e0(SONG_179);
          s->unk_3a0 = 1;
        }
      }
      p->flags &= ~2;
      FUN_08219d98(p);
      if (gInput[0].pressed & B_BUTTON) {
        s->unk_398 = 10;
        s->unk_39c = 9;
        p->unk_5c = 8;
        p->timer2 = 0;
        p->flags |= 2;
        PlaySound_082406e0(SE_CANCEL);
      } else if (gInput[0].pressed & A_BUTTON) {
        if (s->unk_394 == 0) {
          s->unk_39c = 11;
          p->unk_5c = 8;
          p->timer2 = 0;
          p->flags |= 2;
          s->unk_396 = 0;
          FUN_08219d98(p);
          PlaySound_082406e0(SONG_224);
        } else {
          p->unk_5c = 2;
          p->timer2 = 0;
          p->flags |= 2;
          PlaySound_082406e0(SE_SELECT);
        }
      } else if (gStat->unk_93a != 0) {
        if (gInput[0].pressed & DPAD_UP) {
          if (--s->unk_394 < 0) {
            s->unk_394 = 1;
          }
          s->unk_396 = 0;
          PlaySound_082406e0(SONG_892);
        } else if (gInput[0].pressed & DPAD_DOWN) {
          if (++s->unk_394 > 1) {
            s->unk_394 = 0;
          }
          s->unk_396 = 0;
          PlaySound_082406e0(SONG_892);
        }
      }
      break;
    }
    case 2: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08219238(p);
        FUN_08216cc4(p);
        FUN_082139b4(p, 1);
        MessageWindow_Start(s->unk_388);
        MessageWindow_ShowLine(4);
        MessageWindow_SetRect(1, 6, 28, 4);
        MessageWindow_SetInstant(1);
        gStat->unk_008 = 0;
        gStat->unk_00a = 0;
        gStat->unk_00e = 0;
      }
      p->flags &= ~2;
      if (p->timer2 > 9) {
        switch (FUN_08213a64(p)) {
          case 1: {
            p->unk_5c = 3;
            p->timer2 = 0;
            p->flags |= 2;
            break;
          }
          case 2: {
            p->unk_5c = 6;
            p->timer2 = 0;
            p->flags |= 2;
            break;
          }
          case 3: {
            p->unk_5c = 1;
            p->timer2 = 0;
            p->flags |= 2;
            break;
          }
        }
      }
      break;
    }
    case 3: {
      if (p->flags & 2) {
        s32 layer;

        p->flags &= ~2;
        FUN_08217bcc(p);
        ClearBGTilemapBuffer(0);
        Video_GenerateBGMap(0, 0, 0, 0, 0);
        ClearBGTilemapBuffer(2);
        Video_GenerateBGMap(2, 0, 0, 0, 0);
        ClearBGTilemapBuffer(3);
        Video_GenerateBGMap(3, 0, 0, 0, 0);
        FUN_08213a50(p);
        layer = 8;
        Video_SetBGLayer(2, p->tilemap, layer);
        Video_GenerateBGMap(2, 0, 0, 0, 0);
        p->unk_64 = layer;
        FUN_08216c88(p);
        p->input.unk_976 = 0;
      }
      p->flags &= ~2;
      switch (FUN_08216f0c(p)) {
        case 1: {
          p->unk_5c = 4;
          break;
        }
        case 2: {
          p->unk_5c = 5;
          break;
        }
        case 3: {
          p->unk_5c = 2;
          break;
        }
        default: {
          return;
        }
      }
      p->timer2 = 0;
      p->flags |= 2;
      break;
    }
    case 4: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08219238(p);
        FUN_08216cc4(p);
        FUN_082139b4(p, 0);
        MessageWindow_Start(s->unk_388);
        MessageWindow_ShowLine(5);
        MessageWindow_SetRect(3, 7, 28, 4);
        MessageWindow_SetInstant(1);
      }
      p->flags &= ~2;
      if (p->timer2 > 29 && FUN_08213a64(p) == 1) {
        p->unk_5c = 6;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 5: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_08219238(p);
        FUN_08216cc4(p);
        FUN_082139b4(p, 0);
        MessageWindow_Start(s->unk_388);
        MessageWindow_ShowLine(6);
        MessageWindow_SetRect(1, 8, 28, 4);
        MessageWindow_SetInstant(1);
      }
      p->flags &= ~2;
      if (p->timer2 > 29 && FUN_08213a64(p) == 1) {
        p->unk_5c = 3;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 6: {
      s32 ret;

      if (p->flags & 2) {
        p->flags &= ~2;
        ClearBGTilemapBuffer(0);
        Video_GenerateBGMap(0, 0, 0, 0, 0);
        ClearBGTilemapBuffer(2);
        Video_GenerateBGMap(2, 0, 0, 0, 0);
        ClearBGTilemapBuffer(3);
        Video_GenerateBGMap(3, 0, 0, 0, 0);
        FUN_08213a50(p);
        FUN_08217bb8(p);
        p->input.unk_976 = 0;
      }
      p->flags &= ~2;
      ret = FUN_08217e00(p);
      if (ret == 1) {
        p->unk_5c = 7;
        p->timer2 = 0;
        p->flags |= 2;
      } else if (ret == 2) {
        p->unk_5c = (p->flags & 0x10) ? 3 : 2;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 7: {
      if (p->flags & 2) {
        s32 layer;

        p->flags &= ~2;
        FUN_08217bcc(p);
        ClearBGTilemapBuffer(0);
        Video_GenerateBGMap(0, 0, 0, 0, 0);
        ClearBGTilemapBuffer(2);
        Video_GenerateBGMap(2, 0, 0, 0, 0);
        ClearBGTilemapBuffer(3);
        Video_GenerateBGMap(3, 0, 0, 0, 0);
        layer = 5;
        Video_SetBGLayer(2, p->tilemap, layer);
        Video_GenerateBGMap(2, 0, 0, 0, 0);
        p->unk_64 = layer;
        FUN_08213b30(p);
      }
      p->flags &= ~2;
      switch (FUN_08213c24(p)) {
        case 1: {
          if (p->flags & 0x20) {
            gStat->unk_008 = 1;
          }
          s->unk_39c = 12;
          p->unk_5c = 8;
          p->timer2 = 0;
          p->flags |= 2;
          break;
        }
        case 2: {
          p->unk_5c = 6;
          p->timer2 = 0;
          p->flags |= 2;
          break;
        }
        case 3: {
          p->unk_5c = 6;
          p->timer2 = 0;
          p->flags |= 2;
          break;
        }
      }
      break;
    }
    case 8: {
      if (p->flags & 2) {
        p->flags &= ~2;
        Sound_FadeOutBGMTemporarily(2);
      }
      p->flags &= ~2;
      if (p->timer2 > 31) {
        s->unk_3a0 = 0;
        p->unk_5c = s->unk_39c;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 9: {
      if (p->flags & 2) {
        p->flags &= ~2;
        fade[1] = 30;
      }
      p->flags &= ~2;
      if (FUN_0821b21c(p->fade, 1, 30, 0xFFFF)) {
        p->unk_5c = s->unk_398;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 10: {
      p->flags &= ~2;
      if (p->timer2 > 59) {
        p->unk_5c = 99;
        p->timer2 = 0;
        p->flags |= 2;
      }
      break;
    }
    case 11: {
      p->flags &= ~2;
      if (p->timer2 == 30) {
        FUN_08219238(p);
        if (gStat->mapInitScriptID != 0) {
          FUN_0821572c(p);
          gRtcReadInhibit = 0;
          if (p->unk_4c != 0) {
            VM_ExecByID(p->unk_4c, NULL);
          }
          gEntityDisableFlags = 0;
          gMapChangeFlags = 0x11;
          SetMapInitScriptID((s16)gStat->mapInitScriptID);
        }
      }
      break;
    }
    case 12: {
      if (p->flags & 2) {
        p->flags &= ~2;
        FUN_0821572c(p);
        gRtcReadInhibit = 0;
        VM_ExecByID(p->unk_48, NULL);
      }
      p->flags &= ~2;
      if (p->timer2 == 30) {
        ClearBGTilemapBuffer(0);
        Video_GenerateBGMap(0, 0, 0, 0, 0);
        ClearBGTilemapBuffer(2);
        Video_GenerateBGMap(2, 0, 0, 0, 0);
        ClearBGTilemapBuffer(3);
        Video_GenerateBGMap(3, 0, 0, 0, 0);
        FUN_08213a50(p);
      }
      break;
    }
    case 99: {
      p->flags &= ~2;
      VM_ExecByID(p->unk_50, NULL);
      ClearBGTilemapBuffer(0);
      Video_GenerateBGMap(0, 0, 0, 0, 0);
      ClearBGTilemapBuffer(2);
      Video_GenerateBGMap(2, 0, 0, 0, 0);
      ClearBGTilemapBuffer(3);
      Video_GenerateBGMap(3, 0, 0, 0, 0);
      gStat->unk_93e = p->subdbc.unk_c0;
      KillEntity(&p->e);
      break;
    }
  }
#else
  INCFUNC("asm/func/FUN_082192f4.inc");
#endif
}

// unk_396 を数えて BG パレットの 44 / 45 番の赤を明滅させる
void FUN_08219d98(EntityA288* p) {
  EntityA288Sub12C8* s = &p->sub12c8;
  rgb555 color0, color1;
  rgb555* dst;
  s32 start;

  color0 = 0;
  color1 = 0;
  start = 10;
  switch (p->sub12c8.unk_394) {
    case 0: {
      dst = &color0;
      break;
    }
    case 1: {
      dst = &color1;
      break;
    }
    default: {
      return;
    }
  }

  if (s->unk_396 < start) {
    *dst = 31;
  } else if (s->unk_396 < start + 10) {
    *dst = 31;
  } else if (s->unk_396 < start + 18) {
    *dst = 27;
  } else if (s->unk_396 < start + 26) {
    *dst = 18;
  } else if (s->unk_396 < start + 34) {
    *dst = 10;
  } else if (s->unk_396 < start + 42) {
    *dst = 18;
  } else {
    *dst = 27;
  }
  if (++s->unk_396 >= start + 50) {
    s->unk_396 = start;
  }
  gBgPlttBuffer[45] = color0;
  gBgPlttBuffer[44] = color1;
}

void FUN_08219e5c(EntityA288* p) {
  s32 indices[1];

  p->tilemap = GetFile(DIR_TILE_MAP, TILEMAP_33B2);
  indices[0] = 0;
  Video_SetupBGLayout(1, 0, p->tilemap, 0, 0, 1, indices);
  FUN_08213880(p);
}

void FUN_08219e9c(EntityA288* p) {
  p->pltt = GetBgPlttFile(BGP_E9C3)->body;
  CpuCopy32(p->pltt, gBgPlttBuffer, 80 * sizeof(rgb555));
  EntityA288_LoadBgPltt(p);
}

// スプライトを読み込んで各パーツを順に初期化する
void FUN_08219ed0(EntityA288* p) {
  MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, SPRITE_42E2);

  p->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx, f);
  FUN_082138d4(p);
  FUN_08213ce4(p);
  FUN_08214160(p);
  FUN_082150e8(p);
  FUN_082157d4(p);
  FUN_08215db4(p);
  FUN_08218c30(p);
  FUN_082169a0(p);
}

void (*const sEntityA288StateFns[7])(EntityA288*) = {
    FUN_08213dc8,
    FUN_082143f4,
    FUN_08214a24,
    FUN_08215304,
    FUN_08215950,
    FUN_082192f4,
    FUN_0821619c,
};  // 0x085AFF84

// 状態を切り替えてタイマーを止める
void EntityA288_SetState(EntityA288* p, s32 state) {
  p->state = state;
  p->timer1 = 0;
  p->updateCallback = sEntityA288StateFns[state];
  SET_FLAGS(p->flags, 1);
  p->unk_5c = 0;
  p->timer2 = 0;
  SET_FLAGS(p->flags, 2);
}

s32 EntityA288_Update(EntityA288* p) {
  if (!(p->flags & (1 << 0))) {
    p->timer1++;
  }
  if (!(p->flags & (1 << 1))) {
    p->timer2++;
  }
  p->updateCallback(p);
  return 0;
}

s32 EntityA288_Destroy(EntityA288* p) {
  FUN_08213960(p);
  FUN_08213d70(p);
  FUN_08214248(p);
  EntityA288_DestroyPanels(p);
  FUN_0821587c(p);
  FUN_08215f3c(p);
  FUN_08218ddc(p);
  FUN_08216a60(p);
  return 0;
}

// 残差は '.I' の読み込みで i * 52 を受けるレジスタの割り当て (r4 / r5) だけ (257/257), prefecture 用と経度緯度用の2本の添字のどちらが積を持つかが逆
// VM_GetPC をループ条件で代入する形 / j の宣言位置 / entries の初期化順は試済, 状態表は memcpy で ldm/stm になる
NON_MATCH s32 EntityA288_Init(EntityA288* p) {
#ifdef NONMATCHING_C
  s32 states[5];
  s32 i;

  if (VM_SeekToNamedArg('t')) {
    p->kind = VM_GetValue();
  }
  if (VM_SeekToNamedArg('s')) {
    p->sub10c.unk_c0 = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('a')) {
    p->area.unk_6ec = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('I')) {
    EntityA288AreaSelect* s = &p->area;
    EntityA288Entry* e;

    p->area.unk_6f0 = VM_GetValueSafe2();
    VM_SetPC(p->area.unk_6f0);
    for (i = 0, e = p->area.entries; i < 30; i++) {
      s32 j;

      e->id = VM_GetValue();
      e->count = VM_GetValue();
      for (j = 0; j < e->count; j++) {
        u8* pc = VM_GetPC();

        if (pc == NULL) {
          break;
        }
        s->entries[i].prefecture[j] = VM_GetValueAt(pc);
        s->entries[i].longitude[j] = VM_GetValue();
        s->entries[i].latitude[j] = VM_GetValue();
      }
      if (e->id == -1) {
        s->entryCount = i - 1;
        break;
      }
      e++;
    }
  }
  if (VM_SeekToNamedArg('b')) {
    p->soundTest.unk_420 = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('g')) {
    p->sub12c8.unk_388 = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('p')) {
    p->input.unk_120 = VM_GetPC();
  }
  if (VM_SeekToNamedArg('S')) {
    p->input.unk_124 = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('P')) {
    p->input.unk_128 = VM_GetPC();
  }
  if (VM_SeekToNamedArg('N')) {
    p->input.unk_12c = VM_GetPC();
  }
  if (VM_SeekToNamedArg('H')) {
    p->input.unk_130 = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('K')) {
    p->input.unk_134 = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('T')) {
    p->sub12c8.unk_38c = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('A')) {
    p->sub12c8.unk_390 = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('X')) {
    p->subdbc.unk_c4 = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('E')) {
    p->subdbc.unk_cc = VM_GetValue();
  }
  if (VM_SeekToNamedArg('f')) {
    p->unk_48 = VM_GetValue();
  }
  if (VM_SeekToNamedArg('l')) {
    p->unk_4c = VM_GetValue();
  }
  if (VM_SeekToNamedArg('e')) {
    p->unk_50 = VM_GetValue();
  }

  p->flags = 0;
  p->state = 0;
  p->timer1 = 0;
  p->unk_5c = 0;
  p->timer2 = 0;
  p->unk_64 = -1;
  p->unk_68 = 0;
  FUN_08219e5c(p);
  FUN_08219e9c(p);
  FUN_08219ed0(p);
  memcpy(states, u32_ARRAY_08252850, sizeof(states));
  EntityA288_SetState(p, states[p->kind]);
  return 0;
#else
  INCFUNC("asm/func/EntityA288_Init.inc");
#endif
}

// 0xA288
EntityA288* EntityA288_Create(void) {
  EntityA288* p = CreateEntity(ENTITY_UNK_11, sizeof(EntityA288));

  if (p != NULL) {
    SetEntityRoutine(p, EntityA288_Update, EntityA288_Destroy);
    if (EntityA288_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
