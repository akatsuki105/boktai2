#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

// '.I' が並べる1件, count 個ぶんだけ3つの配列が埋まる
typedef struct {
  s8 id;          // 0x00, -1 なら打ち切り
  u8 count;       // 0x01, 続く3つの配列の要素数
  s16 values[5];  // 0x02
  u32 unk_c[5];   // 0x0C
  u32 unk_20[5];  // 0x20
} EntityA288Entry;
static_assert(sizeof(EntityA288Entry) == 52);

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
  u32 unk_5c;                                  // 0x005C, EntityA288_SetState が 0 に戻す
  s32 timer2;                                  // 0x0060, flags bit1 が落ちている間 _Update が 1 足す
  s32 unk_64;                                  // 0x0064, _Init が -1 を入れる
  u32 unk_68;                                  // 0x0068, _Init が 0 を入れる
  u8 unk_6c[0x78 - 0x6C];                      // 0x006C, まだ未解析
  MainSpriteGfx gfx_78;                        // 0x0078
  MainSprite sprite_98;                        // 0x0098
  Tilemaps* tilemap2;                          // 0x00F8, TILEMAP_A413
  rgb555* bgp2;                                // 0x00FC, BGP_EFDA[208]
  s32 windowID;                                // 0x0100
  u8 unk_104[0x106 - 0x104];                   // 0x0104, まだ未解析
  u16 unk_106;                                 // 0x0106, +4 したものを sprite_98 のアニメ番号にする
  u8 unk_108[0x10C - 0x108];                   // 0x0108, まだ未解析
  MainSprite sprites_10c[2];                   // 0x010C
  u8* unk_1cc;                                 // 0x01CC, '.s'
  u8 unk_1d0[0x1D8 - 0x1D0];                   // 0x01D0, まだ未解析
  MainSprite sprites_1d8[12];                  // 0x01D8
  MainSprite sprite_658;                       // 0x0658
  u8 unk_6b8[0x6C0 - 0x6B8];                   // 0x06B8, まだ未解析
  MainSprite sprite_6c0;                       // 0x06C0
  MainSprite sprite_720;                       // 0x0720
  EntityA288Entry entries[30];                 // 0x0780, '.I' から読む
  s32 windowIDs[5];                            // 0x0D98
  u8* unk_dac;                                 // 0x0DAC, '.a'
  u8* unk_db0;                                 // 0x0DB0, '.I' の先頭
  u8 unk_db4[2];                               // 0x0DB4, まだ未解析
  s16 entryCount;                              // 0x0DB6, 読めた entries の個数 - 1
  u8 unk_db8[0xDBA - 0xDB8];                   // 0x0DB8, まだ未解析
  s16 unk_dba;                                 // 0x0DBA, 16倍して sprite_720 の縦位置にする
  MainSprite sprites_dbc[2];                   // 0x0DBC
  s32 unk_e7c;                                 // 0x0E7C, 24倍して sprites_dbc[0] の縦位置にする
  u8* unk_e80;                                 // 0x0E80, '.X'
  s32 unk_e84;                                 // 0x0E84, '.X' の参照先に足す文字列IDのオフセット, gStat->unk_944 にも写す
  u32 unk_e88;                                 // 0x0E88, '.E'
  MainSprite sprites_e8c[2];                   // 0x0E8C
  MainSprite sprites_f4c[3][3];                // 0x0F4C
  u8* unk_12ac;                                // 0x12AC, '.b'
  u32 unk_12b0;                                // 0x12B0, 32倍したものが sprite_e8c の縦位置, +0x4B が sprite_eec のポーズ番号
  u8 unk_12b4[0x12BA - 0x12B4];                // 0x12B4, まだ未解析
  s16 unk_12ba;                                // 0x12BA, '.b' の参照先に足す文字列IDのオフセット
  u8 unk_12bc[0x1650 - 0x12BC];                // 0x12BC, まだ未解析
  u8* unk_1650;                                // 0x1650, '.g'
  u8* unk_1654;                                // 0x1654, '.T'
  u8* unk_1658;                                // 0x1658, '.A'
  u16 unk_165c;                                // 0x165C, gStat->unk_93a が 0 なら 1, そうでなければ 0
  u16 unk_165e;                                // 0x165E, FUN_08218e4c が 0 を入れる
  u8 unk_1660[0x166C - 0x1660];                // 0x1660, まだ未解析
  MainSprite sprites_166c[3];                  // 0x166C
  u8* unk_178c;                                // 0x178C, '.p' の PC
  u8* unk_1790;                                // 0x1790, '.S'
  u8* unk_1794;                                // 0x1794, '.P' の PC
  u8* unk_1798;                                // 0x1798, '.N' の PC
  u8* unk_179c;                                // 0x179C, '.H'
  u8* unk_17a0;                                // 0x17A0, '.K'
  u8 lines[4][256];                            // 0x17A4, 行ごとに組み立てた文字列
  u8 text[1024];                               // 0x1BA4, lines を順に連結したもの
  u8 unk_1fa4[0x1FC4 - 0x1FA4];                // 0x1FA4, まだ未解析
  u8 text_1fc4[24];                            // 0x1FC4, 1文字ずつ積む入力中の文字列
  s16 len_1fdc;                                // 0x1FDC, text_1fc4 に積んだ文字数, 0x16 を超えると打ち切る
  u8 unk_1fde[0x1FE2 - 0x1FDE];                // 0x1FDE, まだ未解析
  u16 unk_1fe2;                                // 0x1FE2
  u16 unk_1fe4;                                // 0x1FE4
  u16 unk_1fe6;                                // 0x1FE6
  void (*updateCallback)(struct EntityA288*);  // 0x1FE8
} EntityA288;
static_assert(sizeof(EntityA288) == 8172);

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
    SONG_158,             SONG_88,         SONG_90,         SONG_166,     SONG_168,
    SONG_176,             SONG_177,        SONG_180,        SONG_173,     -1,
};  // 0x085afa30
// clang-format on

// clang-format off
const SoundID16 u16_ARRAY_085afaee[482] = {
    SONG_224,             SONG_223,              SE_CURSOR_MOVE,  SE_SELECT,                SE_CANCEL,
    SE_SAVE_SUCCESS,      SE_UNK_299,            SE_UNK_300,      SE_UNK_301,               SONG_410,
    SE_NG,                SONG_662,              SONG_660,        SONG_677,                 SONG_266,
    SONG_267,             SE_SLOT,               SE_SWAP_SLOT,    SE_HEAL,                  SE_TRASH,
    SE_BREAK_898,         SE_OPEN_MENU,          SE_CLOSE_MENU,   SE_CHOICE,                SONG_540,
    SE_359,               SONG_225,              SONG_227,        SONG_227,                 SONG_226,
    SONG_570,             SONG_571,              SONG_572,        SONG_573,                 SONG_574,
    SONG_651,             SONG_629,              SONG_630,        SONG_201,                 SONG_202,
    SONG_653,             SONG_654,              SONG_354,        SONG_355,                 SONG_403,
    SONG_404,             SONG_199,              SONG_200,        SONG_821,                 SONG_208,
    SONG_219,             SONG_236,              SONG_235,        SONG_203,                 SONG_908,
    SONG_907,             SONG_911,              SONG_909,        SONG_912,                 SONG_910,
    SONG_913,             SE_GUN_FIRE,           SONG_213,        SE_GUN_AIM,               SE_GUN_MISFIRE,
    SE_GUN_CHARGED,       SONG_425,              SONG_426,        SE_ENCHANT,               SE_HEALING,
    SONG_920,             SONG_921,              SONG_922,        SE_TRANSFORM,             SONG_924,
    SE_CHANGE_WOLF,       SE_CHANGE_BAT,         SE_CHANGE_MOUSE, SE_506,                   SONG_507,
    NOISE_SOLAR_CHARGE,   SE_SOLAR_STAND_DENY,   SE_DENY_302,     SONG_357,                 SE_DAMAGE,
    SONG_209,             SONG_680,              SE_CRASH_307,    SE_308,                   SE_401,
    SE_CONFUSE,           SONG_433,              SONG_492,        SONG_493,                 SONG_218,
    SONG_210,             SONG_211,              SONG_682,        SONG_384,                 SONG_385,
    SONG_386,             SONG_494,              SONG_822,        SONG_637,                 SONG_638,
    SONG_639,             SONG_644,              SONG_645,        SONG_601,                 SE_WOOD_DOOR_427,
    SONG_428,             SONG_430,              SONG_431,        SONG_432,                 SONG_636,
    SE_INFO,              SE_UNK_287,            SONG_602,        SONG_603,                 SONG_604,
    SONG_807,             SONG_513,              SONG_514,        SONG_515,                 SONG_671,
    SONG_516,             SONG_569,              SONG_664,        SONG_925,                 SONG_509,
    SONG_510,             SONG_525,              SONG_527,        SONG_605,                 SONG_526,
    SONG_917,             SONG_541,              SONG_809,        SE_808,                   SONG_542,
    SONG_799,             SONG_800,              SONG_801,        SONG_802,                 SONG_803,
    SE_ENEMY_DAMAGED,     SONG_529,              SONG_316,        SONG_935,                 SONG_936,
    SONG_937,             SONG_938,              SONG_939,        SONG_940,                 SONG_941,
    SONG_942,             SONG_944,              SONG_945,        SONG_946,                 SONG_947,
    SONG_931,             SONG_932,              SONG_933,        SONG_930,                 SONG_959,
    SONG_960,             SONG_961,              SONG_962,        SONG_963,                 SONG_964,
    SONG_969,             SONG_966,              SONG_967,        SE_BEE_968,               SONG_965,
    SONG_971,             SONG_972,              SONG_970,        SONG_412,                 SONG_981,
    SONG_982,             SONG_983,              SONG_411,        SONG_985,                 SONG_986,
    SONG_987,             SONG_988,              SONG_994,        SONG_995,                 SONG_421,
    SONG_996,             SONG_998,              SONG_413,        SONG_418,                 SONG_419,
    SONG_990,             SONG_991,              SONG_992,        SONG_993,                 SONG_436,
    SONG_997,             SONG_999,              SONG_414,        SONG_420,                 SONG_212,
    SONG_237,             SONG_238,              SONG_215,        SONG_229,                 SONG_214,
    SONG_242,             CRY_BOKU_NOTICE,       CRY_BOKU_ALERT,  CRY_BOKU_QUESTION,        SE_UNK_298,
    SE_x29D,              SONG_685,              SONG_228,        SONG_234,                 SONG_813,
    SONG_264,             SONG_232,              SONG_246,        SONG_247,                 SONG_265,
    SONG_248,             SE_UNK_ENEMY_VOICE,    SE_UNK_254,      CRY_MUMMY_255,            CRY_MUMMY_DEATH,
    CRY_MUMMY_257,        CRY_MUMMY_258,         CRY_MUMMY_259,   CRY_MUMMY_260,            CRY_MUMMY_BURN,
    SONG_358,             SONG_405,              SE_UNK_274,      SE_UNK_275,               SE_UNK_276,
    SE_UNK_277,           SONG_361,              SONG_362,        SONG_363,                 SONG_364,
    SONG_365,             SONG_366,              SONG_367,        SONG_368,                 SONG_399,
    SONG_400,             SONG_482,              CRY_GOLEM_389,   CRY_GOLEM_ALERT,          CRY_GOLEM_391,
    SONG_392,             SONG_393,              SONG_394,        SONG_395,                 SONG_397,
    SONG_398,             SONG_434,              SONG_435,        SONG_625,                 SONG_626,
    SONG_471,             SONG_472,              SONG_473,        SONG_476,                 SONG_477,
    SONG_478,             SONG_475,              SONG_479,        SONG_480,                 SONG_481,
    SONG_470,             SONG_455,              SONG_456,        SONG_457,                 SONG_458,
    SONG_459,             SONG_461,              SONG_462,        SONG_463,                 SONG_464,
    SONG_465,             SONG_468,              SONG_469,        SONG_483,                 SONG_484,
    SONG_485,             SE_511,                SONG_608,        SONG_249,                 SONG_250,
    SE_UNK_294,           SONG_407,              SONG_832,        SONG_831,                 SE_PILEDRIVER_07,
    SE_GENERATOR_ENABLED, SE_GENERATOR_DISABLED, SONG_245,        SONG_243,                 SONG_244,
    SE_UNK_297,           SONG_490,              SONG_491,        SE_OPEN_TREASURE,         SE_PICKUP,
    SE_EQUIP,             SE_UNK_291,            SONG_387,        SONG_623,                 SONG_668,
    SONG_679,             SONG_695,              SE_UNK_290,      SE_SOLAR_INSECT_285,      SONG_696,
    SONG_657,             SONG_658,              SONG_659,        SE_UNK_282,               SE_SPIRIT_BUGS_283,
    SE_SPIRIT_BUGS_284,   SONG_206,              SONG_207,        SONG_655,                 SONG_388,
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
    VO_SABATA_TAKETHIS,   SONG_749,              VO_SABATA_STUN,        SONG_874,                   SONG_875,
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

void FUN_0821b28c(u32 x8, u32 y8, u32 w8, u32 h8);
void Video_DrawText(s32 x8, s32 y8, char* s);

static inline void EntityA288_SetFlags(EntityA288* p, u32 bits) { p->flags |= bits; }

void FUN_08213880(EntityA288* p) { p->tilemap2 = GetFile(DIR_TILE_MAP, TILEMAP_A413); }

void EntityA288_LoadBgPltt(EntityA288* p) {
  p->bgp2 = &GetBgPlttFile(BGP_EFDA)->body[208];
  CpuCopy32(p->bgp2, &gBgPlttBuffer[208], 48 * sizeof(rgb555));
}

NAKED void FUN_082138d4(EntityA288* p) { INCFUNC("asm/func/FUN_082138d4.inc"); }

void FUN_08213960(EntityA288* p) {
  MainSprite_Remove(&p->sprite_98);
  TextPanel_Destroy(p->windowID);
}

// 残差1命令, 原典は gfx_78 のアドレスを callee-saved に残して p を使い捨てるが agbcc は逆に割り当てる, MainSpriteGfx* ローカルは試済
NON_MATCH void FUN_0821397c(EntityA288* p) {
#ifdef NONMATCHING_C
  MainSprite_SetAnim(&p->sprite_98, &p->gfx_78, p->unk_106 + 4, 1, 4);
  p->sprite_98.flags &= ~SPRFLAG_HIDDEN;
#else
  INCFUNC("asm/func/FUN_0821397c.inc");
#endif
}

NAKED void FUN_082139b4(EntityA288* p, s16 param_2) { INCFUNC("asm/func/FUN_082139b4.inc"); }

void FUN_08213a50(EntityA288* p) {
  p->sprite_98.flags |= SPRFLAG_HIDDEN;
  MessageWindow_Close();
}

NAKED s32 FUN_08213a64(EntityA288* p) { INCFUNC("asm/func/FUN_08213a64.inc"); }

NAKED void FUN_08213b30(EntityA288* p) { INCFUNC("asm/func/FUN_08213b30.inc"); }

NAKED s32 FUN_08213c24(EntityA288* p) { INCFUNC("asm/func/FUN_08213c24.inc"); }

NAKED void FUN_08213ce4(EntityA288* p) { INCFUNC("asm/func/FUN_08213ce4.inc"); }

void FUN_08213d70(EntityA288* p) {
  MainSprite_Remove(&p->sprites_10c[0]);
  MainSprite_Remove(&p->sprites_10c[1]);
}

// 上半分のテキストボックスを BGP_C486 で開いて1行目を即時表示する
void EntityA288_ShowText(EntityA288* p) {
  MessageWindow_SetBgPltt(BGP_C486);
  MessageWindow_Start(p->unk_1cc);
  MessageWindow_ShowLine(0);
  MessageWindow_SetRect(2, 3, 32, 6);
  MessageWindow_SetInstant(1);
}

NAKED void FUN_08213dc8(EntityA288* p) { INCFUNC("asm/func/FUN_08213dc8.inc"); }

NAKED void FUN_08214160(EntityA288* p) { INCFUNC("asm/func/FUN_08214160.inc"); }

void FUN_08214248(EntityA288* p) {
  MainSprite* sprite = p->sprites_1d8;
  s32 i;

  for (i = 0; i < 12; i++) {
    MainSprite_Remove(sprite);
    sprite++;
  }

  MainSprite_Remove(&p->sprite_658);
}

NAKED void FUN_08214274(EntityA288* p) { INCFUNC("asm/func/FUN_08214274.inc"); }

NAKED void FUN_08214334(EntityA288* p) { INCFUNC("asm/func/FUN_08214334.inc"); }

// 残差2命令, 原典は sprites_1d8 の先頭アドレスを別レジスタに残して sprite_658.flags をそこからの +0x488 で引く, MainSprite* ローカルと sprites_1d8[13] 化は試済
NON_MATCH void FUN_082143c0(EntityA288* p) {
#ifdef NONMATCHING_C
  MainSprite* sprite = p->sprites_1d8;
  s32 i;

  for (i = 0; i < 12; i++) {
    sprite[i].flags |= SPRFLAG_HIDDEN;
  }

  p->sprite_658.flags |= SPRFLAG_HIDDEN;
#else
  INCFUNC("asm/func/FUN_082143c0.inc");
#endif
}

NAKED void FUN_082143f4(EntityA288* p) { INCFUNC("asm/func/FUN_082143f4.inc"); }

NAKED void FUN_08214a24(EntityA288* p) { INCFUNC("asm/func/FUN_08214a24.inc"); }

NAKED void FUN_082150e8(EntityA288* p) { INCFUNC("asm/func/FUN_082150e8.inc"); }

// スプライトとテキストパネルを片付ける
void EntityA288_DestroyPanels(EntityA288* p) {
  s32 i;

  MainSprite_Remove(&p->sprite_6c0);
  MainSprite_Remove(&p->sprite_720);

  for (i = 0; i < 5; i++) {
    TextPanel_Destroy(p->windowIDs[i]);
  }
}

NAKED void FUN_082151d8(EntityA288* p) { INCFUNC("asm/func/FUN_082151d8.inc"); }

void FUN_082152c0(EntityA288* p) {
  MainSprite_Show(&p->sprite_720);
  MainSprite_SetAnim(&p->sprite_720, &p->gfx, 4, 1, 0);
}

void FUN_082152ec(EntityA288* p) {
  MainSprite* sprite = &p->sprite_720;

  sprite->pos.y = p->unk_dba * 16;
}

NAKED void FUN_08215304(EntityA288* p) { INCFUNC("asm/func/FUN_08215304.inc"); }

NAKED void FUN_082156bc(EntityA288* p) { INCFUNC("asm/func/FUN_082156bc.inc"); }

NAKED void FUN_0821572c(EntityA288* p) { INCFUNC("asm/func/FUN_0821572c.inc"); }

NAKED void FUN_082157d4(EntityA288* p) { INCFUNC("asm/func/FUN_082157d4.inc"); }

void FUN_0821587c(EntityA288* p) {
  MainSprite_Remove(&p->sprites_dbc[0]);
  MainSprite_Remove(&p->sprites_dbc[1]);
}

// カーソルのスプライトを出して unk_e7c 行目の高さに置く
void FUN_082158a0(EntityA288* p) {
  MainSprite* spr = &p->sprites_dbc[0];

  spr->flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(spr, &p->gfx, 7, 1, 0);
  spr->pos.y = p->unk_e7c * 24;
}

void FUN_082158e4(EntityA288* p) {
  MainSprite* sprite = &p->sprites_dbc[0];

  sprite->pos.y = p->unk_e7c * 24;
}

// 残差0命令 (31/31), レジスタ名だけ違う: 0xE84 のプール定数が原典は r1, こちらは r2 に載る
NON_MATCH void FUN_082158fc(EntityA288* p) {
#ifdef NONMATCHING_C
  char* text = Textbox_LookupString(VM_ParseStringRef(p->unk_e80) + p->unk_e84);

  FUN_0821b28c(9, 10, 0x12, 2);
  Video_DrawText(9, 10, text);
  gStat->unk_944 = p->unk_e84;
#else
  INCFUNC("asm/func/FUN_082158fc.inc");
#endif
}

NAKED void FUN_08215950(EntityA288* p) { INCFUNC("asm/func/FUN_08215950.inc"); }

NAKED void FUN_08215d24(EntityA288* p) { INCFUNC("asm/func/FUN_08215d24.inc"); }

NAKED void FUN_08215db4(EntityA288* p) { INCFUNC("asm/func/FUN_08215db4.inc"); }

// 追加分のスプライト11枚をまとめて外す
void FUN_08215f3c(EntityA288* p) {
  s32 i;

  MainSprite_Remove(&p->sprites_e8c[0]);
  MainSprite_Remove(&p->sprites_e8c[1]);
  for (i = 0; i < 3; i++) {
    MainSprite_Remove(&p->sprites_f4c[0][i]);
    MainSprite_Remove(&p->sprites_f4c[1][i]);
    MainSprite_Remove(&p->sprites_f4c[2][i]);
  }
}

NAKED void FUN_08215f98(EntityA288* p) { INCFUNC("asm/func/FUN_08215f98.inc"); }

// BG を消してから '.b' の文字列を (10, 4) に描く
void FUN_08216000(EntityA288* p) {
  char* str;

  ClearBGTilemapBuffer(0);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  str = Textbox_LookupString(VM_ParseStringRef(p->unk_12ac) + p->unk_12ba);
  FUN_0821b28c(10, 4, 16, 2);
  Video_DrawText(10, 4, str);
}

NAKED void FUN_0821605c(EntityA288* p) { INCFUNC("asm/func/FUN_0821605c.inc"); }

NAKED void FUN_082160d8(EntityA288* p) { INCFUNC("asm/func/FUN_082160d8.inc"); }

// unk_12b0 行目にカーソルを置いてポーズを当て直す
void FUN_08216154(EntityA288* p) {
  MainSprite* spr = p->sprites_e8c;

  spr[0].pos.y = p->unk_12b0 * 32;
  MainSprite_SetPose(&spr[1], &p->gfx, p->unk_12b0 + 0x4B, 1);
  spr[1].flags &= ~SPRFLAG_HIDDEN;
  p->unk_68 = 0;
}

NAKED void FUN_0821619c(EntityA288* p) { INCFUNC("asm/func/FUN_0821619c.inc"); }

NAKED void FUN_082164e4(EntityA288* p) { INCFUNC("asm/func/FUN_082164e4.inc"); }

NAKED s32 FUN_0821660c(EntityA288* p) { INCFUNC("asm/func/FUN_0821660c.inc"); }

NAKED void FUN_08216730(EntityA288* p) { INCFUNC("asm/func/FUN_08216730.inc"); }

NAKED void FUN_082167dc(EntityA288* p) { INCFUNC("asm/func/FUN_082167dc.inc"); }

NAKED void FUN_08216894(EntityA288* p) { INCFUNC("asm/func/FUN_08216894.inc"); }

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

NAKED void FUN_082169a0(EntityA288* p) { INCFUNC("asm/func/FUN_082169a0.inc"); }

void FUN_08216a60(EntityA288* p) {
  MainSprite_Remove(&p->sprites_166c[0]);
  MainSprite_Remove(&p->sprites_166c[1]);
  MainSprite_Remove(&p->sprites_166c[2]);
}

NAKED void FUN_08216a90(EntityA288* p) { INCFUNC("asm/func/FUN_08216a90.inc"); }

NAKED void FUN_08216bdc(EntityA288* p) { INCFUNC("asm/func/FUN_08216bdc.inc"); }

// sprites_166c[1] を 78 番のポーズで表示する
void FUN_08216c88(EntityA288* p) {
  MainSprite* sprites = p->sprites_166c;

  FUN_08216a90(p);
  MainSprite_SetPose(&sprites[1], &p->gfx, 78, 1);
  sprites[1].flags &= ~SPRFLAG_HIDDEN;
  FUN_08216bdc(p);
}

void FUN_08216cc4(EntityA288* p) {
  p->sprites_166c[0].flags |= SPRFLAG_HIDDEN;
  p->sprites_166c[1].flags |= SPRFLAG_HIDDEN;
  p->sprites_166c[2].flags |= SPRFLAG_HIDDEN;
}

NAKED void FUN_08216cf4(EntityA288* p, s32 param_2) { INCFUNC("asm/func/FUN_08216cf4.inc"); }

NAKED void FUN_08216dd8(EntityA288* p, s32 param_2) { INCFUNC("asm/func/FUN_08216dd8.inc"); }

// 文字を1つ積む, 入りきらなければ 1 を返す
// 残差はレジスタ割当だけ (29 対 29), 原典は添字の 0 オフセット用スクラッチに後で full が入る r5 を使い回すが, こちらは r2 を取る
// 宣言順 / bool32 / 引数の型 / len を直読みする形は試済
NON_MATCH s32 FUN_08216e60(EntityA288* p, u8 c) {
#ifdef NONMATCHING_C
  s32 len;
  s32 full;

  p->text_1fc4[p->len_1fdc] = c;
  len = p->len_1fdc;
  if (p->len_1fdc <= 0x16) {
    p->len_1fdc++;
    full = 0;
  } else {
    full = 1;
  }

  FUN_08216dd8(p, len);
  FUN_08216bdc(p);
  return full;
#else
  INCFUNC("asm/func/FUN_08216e60.inc");
#endif
}

NAKED s32 FUN_08216ea8(EntityA288* p) { INCFUNC("asm/func/FUN_08216ea8.inc"); }

NAKED s32 FUN_08216f0c(EntityA288* p) { INCFUNC("asm/func/FUN_08216f0c.inc"); }

NAKED void FUN_0821722c(EntityA288* p) { INCFUNC("asm/func/FUN_0821722c.inc"); }

NAKED void FUN_08217440(EntityA288* p) { INCFUNC("asm/func/FUN_08217440.inc"); }

NAKED void FUN_08217648(EntityA288* p) { INCFUNC("asm/func/FUN_08217648.inc"); }

NAKED void FUN_0821785c(EntityA288* p) { INCFUNC("asm/func/FUN_0821785c.inc"); }

NAKED void FUN_08217a10(EntityA288* p) { INCFUNC("asm/func/FUN_08217a10.inc"); }

NAKED void FUN_08217b48(EntityA288* p) { INCFUNC("asm/func/FUN_08217b48.inc"); }

void FUN_08217bb8(EntityA288* p) {
  FUN_08217a10(p);
  FUN_08217b48(p);
}

void FUN_08217bcc(EntityA288* p) {
  p->sprites_166c[0].flags |= SPRFLAG_HIDDEN;
  p->sprites_166c[1].flags |= SPRFLAG_HIDDEN;
  p->sprites_166c[2].flags |= SPRFLAG_HIDDEN;
}

NAKED void FUN_08217bfc(EntityA288* p) { INCFUNC("asm/func/FUN_08217bfc.inc"); }

NAKED void FUN_08217c6c(EntityA288* p) { INCFUNC("asm/func/FUN_08217c6c.inc"); }

NAKED s32 FUN_08217cd0(EntityA288* p, s32 param_2) { INCFUNC("asm/func/FUN_08217cd0.inc"); }

NAKED s32 FUN_08217d5c(EntityA288* p) { INCFUNC("asm/func/FUN_08217d5c.inc"); }

NAKED s32 FUN_08217e00(EntityA288* p) { INCFUNC("asm/func/FUN_08217e00.inc"); }

NAKED void FUN_0821813c(EntityA288* p) { INCFUNC("asm/func/FUN_0821813c.inc"); }

NAKED void FUN_082183e0(EntityA288* p) { INCFUNC("asm/func/FUN_082183e0.inc"); }

NAKED void FUN_0821869c(EntityA288* p) { INCFUNC("asm/func/FUN_0821869c.inc"); }

NAKED void FUN_08218910(EntityA288* p) { INCFUNC("asm/func/FUN_08218910.inc"); }

const u8 gStringDjango_085aff78[] = _("ジャンゴ");

// 名前欄に "ジャンゴ" を書き込む, 転送量は文字列の長さではなく名前欄の 10 バイト
void FUN_08218b20(u8* dst) { CpuCopy16(gStringDjango_085aff78, dst, 10); }

NAKED void FUN_08218b34(EntityA288* p, unknown* param_2) { INCFUNC("asm/func/FUN_08218b34.inc"); }

NAKED void FUN_08218c30(EntityA288* p) { INCFUNC("asm/func/FUN_08218c30.inc"); }

NAKED void FUN_08218ddc(EntityA288* p) { INCFUNC("asm/func/FUN_08218ddc.inc"); }

void FUN_08218e4c(EntityA288* p) {
  if (gStat->unk_93a != 0) {
    p->unk_165c = 0;
  } else {
    p->unk_165c = 1;
  }

  p->unk_165e = 0;
}

NAKED void FUN_08218e90(EntityA288* p) { INCFUNC("asm/func/FUN_08218e90.inc"); }

NAKED void FUN_08219238(EntityA288* p) { INCFUNC("asm/func/FUN_08219238.inc"); }

NAKED void FUN_082192f4(EntityA288* p) { INCFUNC("asm/func/FUN_082192f4.inc"); }

NAKED void FUN_08219d98(EntityA288* p) { INCFUNC("asm/func/FUN_08219d98.inc"); }

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
  EntityA288_SetFlags(p, 1);
  p->unk_5c = 0;
  p->timer2 = 0;
  EntityA288_SetFlags(p, 2);
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

NAKED s32 EntityA288_Init(EntityA288* p) { INCFUNC("asm/func/EntityA288_Init.inc"); }

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
