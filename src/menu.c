#include "menu.h"

#include "armor.h"
#include "bg_pltt.h"
#include "entity.h"
#include "entity_9a9f.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "inventory.h"
#include "item.h"
#include "magic.h"
#include "particle.h"
#include "player.h"
#include "random.h"
#include "save.h"
#include "sound.h"
#include "spirit_bugs.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "time.h"
#include "video.h"
#include "vm.h"

// スタートメニューのページ
#define PAGE_MAP 0
#define PAGE_ITEM 1
#define PAGE_VALUABLE 2
#define PAGE_WEAPON 3
#define PAGE_ARMOR 4
#define PAGE_MAGIC 5
#define PAGE_STATS 6
#define PAGE_CONFIG 7
#define PAGE_SLEEP 8
#define PAGE_SAVE 9
#define PAGE_NUM 10

#define PT_RDJANGO 0  // PLAYER_SOLAR_DJANGO
#define PT_BDJANGO 1  // PLAYER_DARK_DJANGO, PLAYER_BAT, PLAYER_MOUSE, PLAYER_SLEEPING
#define PT_SABATA 2   // PLAYER_SABATA

// コンフィグページの項目, MainMenu.config と configRow の添字
#define CONFIG_CONTROL 0     // 操作 (gStat->controlUp)
#define CONFIG_TEXT_SPEED 1  // 文字速度
#define CONFIG_MARKER 2      // マーカー (gStat->markerEnabled)

struct MainMenu;
typedef void(MainMenuFunc)(struct MainMenu* p);  // _Update が p->fn(p) として呼ぶ

// HUD上のクイックチェンジの魔法アイコン
typedef struct {
  s8 idx;             // 0x00, registeredMagic の添字, 負なら空き枠
  magic8_t id;        // 0x01, 魔法のID, 空き枠は -1
  u8 unk_02[2];       // 0x02, まだ未解析, padding?
  MainSprite sprite;  // 0x0004
} QCMagicSlot;
static_assert(sizeof(QCMagicSlot) == 100);

typedef struct {
  ParticleGroup* group2;  // 0x000, PTCL_GROUP_2
  bool8 active;           // 0x004, nodes のどれかが動いている間 TRUE
  u8 unk_5;               // 0x005
  u8 unk_6[2];            // 0x006, まだ未解析
  struct MMenuPtclNode {
    Particle ptcl;                                         // 0x00, FUN_0808cacc が Particle_Remove に渡す
    u8 unk_28[0x30 - 0x28];                                // 0x28, まだ未解析
    u16 velX;                                              // 0x30, 毎フレーム ptcl.pos.x に足す
    u16 velY;                                              // 0x32, 毎フレーム ptcl.pos.y に足す, 4フレームごとに1増える
    u8 unk_34[0x38 - 0x34];                                // 0x34, まだ未解析
    u8 active;                                             // 0x38, 0 になると使い終わり
    u8 timer;                                              // 0x39, 経過フレーム数, 20 で打ち止め
    u8 unk_3a[2];                                          // 0x3A, まだ未解析
    s32 (*update)(struct MMenuPtclNode*, ParticleGroup*);  // 0x3C, active が立っている間 毎フレーム呼ぶ, 0 を返すと使い終わり
  } nodes[8];                                              // 0x008
} MMenuPtclSet;
static_assert(sizeof(MMenuPtclSet) == 520);

typedef struct MMenuPtclNode MMenuPtclNode;
static_assert(sizeof(MMenuPtclNode) == 64);

// HUD上の武器アイコン
typedef struct {
  u8 registeredIdx;     // 0x0000, registeredWeapon の添字 (0: 剣, 1: 槍, 2: 槌, 3: 銃), 読み手は (s8) を付けて負を空きと見る
  u8 inventorySlotIdx;  // 0x0001, このQCスロットの武器のインベントリ上のスロット番号
  u8 unk_02[2];         // 0x0002, まだ未解析, padding?
  Weapon* weapon;       // 0x0004, 根拠: MainMenu_ApplyWeapon が Player_ApplyWeapon の第2引数に渡す
  MainSprite sprite;    // 0x0008
} QCWeaponSlot;
static_assert(sizeof(QCWeaponSlot) == 104);

// HUD のクイックチェンジ, 左に魔法, 右に武器のアイコンを並べて L/R で回し SELECT を離すと確定する
typedef struct {
  u8 magicCount;            // 0x000, 魔法のスロット数 (= 魔法装備数)
  u8 magicScrollTimer;      // 0x001, L で回すと 8 を入れ, 0 になるまでアイコンを動かす
  s8 magicIdx;              // 0x002, 選択中の魔法 (0..3), 負なら選択なし
  u8 magicBlinkTimer;       // 0x003, 使えない魔法を点滅させるためのカウンタ, 0..59
  s16* equippedMagicIdx;    // 0x004, gStat->equippedMagicIdx (サバタなら sabataMagicIdx) を指す
  QCMagicSlot magics[4];    // 0x008, 魔法アイコン
  s8 weaponIdx;             // 0x198, 選択中の武器 (0..3)
  u8 weaponCrashTimer;      // 0x199, HUD_ShowWeaponCrashEffect が 6 を入れ, 0 になるまで壊れた武器の絵を出す
  u8 unk_19a[2];            // 0x19A, padding?
  QCWeaponSlot weapons[4];  // 0x19C, 武器アイコン
  u8 cursorPulseCounter;    // 0x33C, 魔法と武器で共通のカーソルの点滅カウンタ, 0..49
  bool8 enabled;            // 0x33D, '.q=1', FALSE なら QC を開かない
  u8 unk_33e[2];            // 0x33E, padding?
  u8 weaponCount;           // 0x340, 武器のスロット数
  u8 weaponScrollTimer;     // 0x341, R で回すと 8 を入れ, 0 になるまでアイコンを動かす
  u8 unk_342[2];            // 0x342, padding?
} QuickChange;
static_assert(sizeof(QuickChange) == 836);

// アイテムや装備のアイコンを枠から枠へ飛ばすアニメ, MainMenu_BeginItemMove で始めて MainMenu_UpdateItemMove で毎フレーム進める
typedef struct {
  Vec3 from;     // 0x00, 出発位置
  Vec3 to;       // 0x08, 到着位置
  s16 arcX;      // 0x10, 進行方向と直交する膨らみ, sin で 0 から戻る
  s16 arcY;      // 0x12, 同上
  u8 unk_14[4];  // 0x14, まだ未解析
  u16 timer;     // 0x18, 経過フレーム数
  u16 duration;  // 0x1A, 到着までのフレーム数
  bool8 active;  // 0x1C, 移動中なら TRUE
  u8 unk_1d[3];  // 0x1D, padding?
} MenuItemMove;
static_assert(sizeof(MenuItemMove) == 32);

// スタートメニューのインベントリカーソル(スタートメニューの道具,貴重品,武器,防具,魔法 のインベントリで使用)
typedef struct {
  u8 flags;        // 0x00, bit0: アイテムを選択中, bit3: ???, bit4: ???, bit5: 魔法メニューで0, それ以外でセット
  u8 colX;         // 0x01, カーソルのある列
  u8 rowY;         // 0x02, カーソルのある行
  u8 slot;         // 0x03, 現在のカーソルの場所のスロット番号, .slotmap[colX*4 + rowY] (colX * 4 なのがややこしい, しかも基本的に, rowY*4 + colX と同じ値になる)
  u8 savedCol;     // 0x04, 直前に選択した colX, アイテム入れ替えなどで直前に選択したものが必要になる
  u8 savedRow;     // 0x05, 同じく rowY
  u8 savedSlot;    // 0x06, 同じく slot
  u8 repeatTimer;  // 0x07, 十字キーを押しっぱなしにしている間のフレーム数 (カーソル移動にディレイをつけるためのもの？)
  u8 slotmap[36];  // 0x08, colX と rowY のスロット番号, 読み手は (s8) を付けて負を選べない枠と見る
} InventoryCursor;
static_assert(sizeof(InventoryCursor) == 44);

// マップページのダンジョン地図の1画面 (フロアや区画), ステージごとの表を stageID で引く
typedef struct {
  u8 mapID;          // 0x00, gStat->unlockedMap のビット番号, 立っていれば地図を表示する
  u8 bgLayer;        // 0x01, Video_SetBGLayer に渡すタイルマップの層
  u8 originX;        // 0x02, タイル単位, BG のずらし量
  u8 originY;        // 0x03, 同上
  u8 width;          // 0x04, タイル単位, 画面の 30 タイルを超えた分だけ横にスクロールできる
  u8 height;         // 0x05, タイル単位, 画面の 20 タイルを超えた分だけ縦にスクロールできる
  s8 links[4];       // 0x06, 地図があるときの 上/下/左/右 の隣の画面の添字, -1 はなし
  u8 unk_0a;         // 0x0A, bit i が立っていると i 方向の矢印を点滅させない
  s8 linksNoMap[4];  // 0x0B, 地図がないときの 上/下/左/右 の隣の画面の添字, -1 はなし
  u8 nameLine;       // 0x0F, 画面名のメッセージ行
} MapScreen;
static_assert(sizeof(MapScreen) == 16);

// マップページの現在地の候補, gStat->mapSpot で引く
typedef struct {
  u8 screen;  // 0x00, MapScreen の添字
  u8 x;       // 0x01, 4 ピクセル単位
  u8 y;       // 0x02, 4 ピクセル単位
  u8 unk_3;   // 0x03, padding?
} MapSpot;
static_assert(sizeof(MapSpot) == 4);

// マップページの地図に描くアイコン, gStat->mapIconFlags[stageID] のビットが立っているものだけ描く
typedef struct {
  u8 kind;    // 0x00, 下位4ビットが種類 (0 は終端), 上位4ビットが 0 でなければ別のパレット
  u8 screen;  // 0x01, MapScreen の添字
  u8 x;       // 0x02, タイル単位
  u8 y;       // 0x03, タイル単位
} MapIcon;
static_assert(sizeof(MapIcon) == 4);

// ワールドマップ上のステージの位置, stageID で引く
typedef struct {
  u8 x;         // 0x00, 4 ピクセル単位
  u8 y;         // 0x01, 4 ピクセル単位
  u8 unk_2;     // 0x02
  u8 nameLine;  // 0x03, ステージ名のメッセージ行
} WorldMapStage;
static_assert(sizeof(WorldMapStage) == 4);

// ワールドマップの BG1 に 2x2 タイルで描く目印, gStat->worldMapFlags の flagBit が立っているものだけ描く
typedef struct {
  u8 x;        // 0x00, タイル単位
  u8 y;        // 0x01, タイル単位
  u8 shape;    // 0x02, 0 ならタイル 8 から, 1 ならタイル 12 から並べる
  u8 flagBit;  // 0x03, gStat->worldMapFlags のビット番号
} WorldMapTile;
static_assert(sizeof(WorldMapTile) == 4);

// マップ切り替え時に毎回生成される
// Init を強制的に失敗させる(Init の返り値を -1 にする) と (ステータスバー,太陽ゲージ以外の)HUD が表示されなくなり、 STARTを押してもスタートメニューが開かず、SELECTを押してもクイックチェンジができなくなった
// このときにキャラと会話すると、 顔アイコンと文字のタイルは表示されるが、テキストボックスが表示されない (会話自体は正常に処理される)
// 機能としては(今のところ判明してるだけでも) HUD + スタートメニュー + テキストウィンドウ といった感じ
typedef struct MainMenu {
  Entity e;                      // 0x0000, ENTITY_UNK_12
  Tilemaps* tm_18;               // 0x0018, TILEMAP_A413
  Tilemaps* worldMapTilemap;     // 0x001C, TILEMAP_A7D7
  Tilemaps* dungeonMapTilemap0;  // 0x0020, TILEMAP_A7E7
  Tilemaps* dungeonMapTilemap1;  // 0x0024, TILEMAP_A7F7
  TilemapFile* mapTilemap;       // 0x0028, マップページで使う worldMapTilemap / dungeonMapTilemap0 / dungeonMapTilemap1 のどれか
  TilemapFile* tm_2c;            // 0x002C, TILEMAP_BANK
  rgb555* bgp_30;                // 0x0030, BGP_EFDA
  rgb555* dungeonMapPltt;        // 0x0034, BGP_ECBF
  rgb555* worldMapPltt;          // 0x0038, BGP_5F5E
  rgb555* bgp_3c;                // 0x003C, BGP_BANK
  char* itemNames;               // 0x0040, '.i', String_1608
  char* weaponNames;             // 0x0044, '.w', String_170D
  char* armorNames;              // 0x0048, '.a', String_17B7
  char* magicNames;              // 0x004C, '.m', String_1802
  char* areaNames;               // 0x0050, '.A', String_1826
  char* loanTexts;               // 0x0054, '.l', String_053B, 暗黒カードを使ったに表示されるテキスト
  char* etcTexts;                // 0x0058, '.E', String_1880, その他のテキスト
  u32* expTable;                 // 0x005C, '.e', 経験値テーブル(レベルごとの必要経験値 の 1/10)
  struct {
    MainSpriteGfx smenu;         // SPRITE_UI_START_MENU
    MainSpriteGfx map;           // SPRITE_UI_MAP
    MainSpriteGfx icons;         // SPRITE_INVENTORY_ICONS
    MainSpriteGfx loans;         // SPRITE_UI_DARKLOAN
    MainSpriteGfx portraits;     // SPRITE_PORTRAITS
    MainSpriteGfx player;        // SPRITE_DJANGO_SABATA
    MainSpriteGfx rita;          // SPRITE_RITA
    MainSpriteGfx carmilla;      // SPRITE_CARMILLA
    MainSpriteGfx link;          // SPRITE_UI_LINK
  } gfx;                         // 0x0060
  BgState savedBg1;              // 0x0180
  u16 savedTilemap1[1024];       // 0x01B0
  u16 savedBLDCNT;               // 0x09B0, 開くときの REG_BLDCNT
  u16 savedBgBrightness;         // 0x09B2, メニューを開いたときの gBgBrightness2, 閉じるときに戻す
  u16 savedBG1CNT;               // 0x09B4, 開くときの REG_BG1CNT, 閉じるときに戻す
  u8 unk_9b6[0x9B8 - 0x9B6];     // 0x09B6, まだ未解析
  rgb555 fadePltt[16];           // 0x09B8, パレットを補間した結果
  u16 fadeFromPltt;              // 0x09D8, 補間元の gObjPlttData の行
  u16 fadeToPltt;                // 0x09DA, 補間先の gObjPlttData の行
  u8 fadeStep;                   // 0x09DC, 経過フレーム数
  u8 fadeSteps;                  // 0x09DD, 補間にかけるフレーム数
  bool8 fadeActive;              // 0x09DE, 補間中なら TRUE
  u8 playerIdx;                  // 0x09DF, gPlayerPtr の添字
  Player* player;                // 0x09E0
  u8 unk_9e4[0x9EC - 0x9E4];     // 0x09E4, まだ未解析
  u16 updateTimer;               // 0x09EC, updateCallback を差し替えると 0 に戻り, その関数が毎フレーム +1 する
  u16 stateTimer;                // 0x09EE, fn を差し替えると 0 に戻り, 各状態関数が毎フレーム +1 する
  MainMenuFunc* updateCallback;  // 0x09F0
  MainMenuFunc* fn;              // 0x09F4
  bool8 hidden;                  // 0x09F8, MainMenu_SetState の hide, sprites[1] と sprites[2] を隠しているか
  u8 unk_9f9;                    // 0x09F9, まだ未解析, padding?
  u16 id;                        // 0x09FA
  u16 unk_9fc;                   // 0x09FC
  u8 hudMode;                    // 0x09FE, HUD の表示モード, MainMenu_SetHudMode が書く, 7 は全部隠す, 1 はボスのゲージ
  s8 unk_9ff;                    // 0x09FF, 根拠: FUN_0809c1e8 が ldrsb で読んで負かどうかを見る
  u16 hpBlinkTimer;              // 0x0A00, HP が少ないときに増え, HP ゲージの枠を点滅させる
  u16 eneBlinkTimer;             // 0x0A02, 急速チャージ中に増え, EN ゲージの枠を白く点滅させる
  u16 sunFrameTimer;             // 0x0A04, 日光を浴びている間 0..59 を回し, 太陽ゲージの枠の色を変える
  u16 enemyGaugeHP;              // 0x0A06, 右上に出す敵の HP ゲージ
  u16 enemyGaugeMaxHP;           // 0x0A08
  u16 enemyGaugeTimer;           // 0x0A0A, 180 から減らし, 0 でないあいだ敵のゲージを出す
  u8 enemyGaugeCells;            // 0x0A0C, ゲージのマス数
  u8 enemyGaugeFlash;            // 0x0A0D, 0 でないあいだゲージを白くする, 表示を頼むときに指定すれば 6
  u16 coffinGaugeHP;             // 0x0A0E, 棺桶運搬中の黒ジャンゴの残り HP, 敵のゲージがないときに同じ場所に出す
  u16 coffinGaugeMaxHP;          // 0x0A10
  u16 coffinGaugeTimer;          // 0x0A12, 180 から減らし, 0 でないあいだ棺桶のゲージを出す
  u8 coffinGaugeFlash;           // 0x0A14, 0 でないあいだゲージを白くする
  bool8 enemyGaugeShown;         // 0x0A15, ゲージを BG0 に描いた
  u16 unk_a16;                   // 0x0A16
  u8 unk_a18[0xA1C - 0xA18];     // 0x0A18, まだ未解析
  u16 heatBlinkTimer;            // 0x0A1C, 熱中症が溜まっている間に増え, 太陽ゲージを点滅させて64フレームごとに警告音を鳴らす
  s16 prevBossHP;                // 0x0A1E, 前のフレームのボスの HP, これより増えている間はゲージを点滅させる
  u16 bossBlinkTimer;            // 0x0A20, ボスの HP が増えている間に回す点滅用のカウンタ
  u16 bossFlashTimer;            // 0x0A22, 0 でないあいだボスのゲージを白くする, ダメージを受けたときに 4
  u8 unk_a24;                    // 0x0A24
  u8 unk_a25[0xA2A - 0xA25];     // 0x0A25, まだ未解析
  u8 unk_a2a;                    // 0x0A2A
  u8 unk_a2b[0xA2F - 0xA2B];     // 0x0A2B, まだ未解析
  bool8 solarStandShown;         // 0x0A2F, アストロ武器の装備中に太陽スタンドの貯金を BG0 に描いた
  u8 unk_a30;                    // 0x0A30
  u8 unk_a31;                    // 0x0A31
  u8 unk_a32[0xA34 - 0xA32];     // 0x0A32, まだ未解析
  MainSprite unk_a34;            // 0x0A34
  bool8 condIconShown;           // 0x0A94, HUD 左上の状態アイコンを出しているか
  u8 unk_a95;                    // 0x0A95
  bool8 kaamosShown;             // 0x0A96, カーモスの表示を BG0 に描いた
  u8 unk_a97;                    // 0x0A97
  u8 unk_a98;                    // 0x0A98
  u8 unk_a99;                    // 0x0A99
  u8 unk_a9a;                    // 0x0A9A
  u8 unk_a9b;                    // 0x0A9B
  u16* unk_a9c;                  // 0x0A9C, おそらくカウントダウンの残りフレーム数を指すポインタ
  MainSprite unk_aa0[2];         // 0x0AA0
  AuxSprite sprite_b60;          // 0x0B60, ->gfx_b8c
  AuxSpriteGfx gfx_b8c;          // 0x0B8C, SPRITE_BAT
  AuxAnimState anim_ba8;         // 0x0BA8, sprite_b60 のアニメの再生状態
  AuxSprite stand;               // 0x0BB8, ->standGfx
  AuxSpriteGfx standGfx;         // 0x0BE4, SPRITE_SOLAR_STATION (暗黒カードの太陽スタンド)
  QuickChange qc;                // 0x0C00
  u8 unk_f44[0xF56 - 0xF44];     // 0x0F44, まだ未解析
  u8 page;                       // 0x0F56, スタートメニューのページ番号
  u8 pageCursor;                 // 0x0F57, サイドバーで選んでいるページ, A で page に入る
  bool8 availPages[PAGE_NUM];    // 0x0F58, '.o', スタートメニューで選択可能なページ, 指定がなければ全ページ選択可
  u8 unk_f62[2];                 // 0x0F62, まだ未解析, padding?
  MainSprite sprites[116];       // 0x0F64, MainMenu1P_RemoveSprites で 116回のループを回して処理するので配列と思われる
  u8 unk_3ae4;                   // 0x3AE4, メニューを閉じて効果を実行する要求
  u8 pageRepeatTimer;            // 0x3AE5, L/R を押し続けている間のフレーム数, 10 でページを送る
  u8 moneyKind;                  // 0x3AE6, 画面右上に出す金額の種類, 0: 太陽バンク, 1: 暗黒ローンの返済額, 2: ソーラースタンド
  u8 unk_3ae7;                   // 0x3AE7
  InventoryCursor cursor;        // 0x3AE8
  u16 savedDISPCNT;              // 0x3B14, 開くときの gStagedDISPCNT
  u16 savedMosaicDirty;          // 0x3B16, 開くときの gMosaicDirty
  u16 savedMosaicSize;           // 0x3B18, 開くときの gMosaicSize, 閉じるときに戻す
  u8 savedObjMosaicEnabled;      // 0x3B1A, 開くときの gObjMosaicEnabled, 閉じるときに戻す
  u8 savedMosaicTargets;         // 0x3B1B, 開くときの gMosaicTargets, 閉じるときに戻す
  u16 savedBgPlttBlendColor;     // 0x3B1C, 開くときの gBgPlttBlendColor
  u16 savedBgPlttFadeRowMask;    // 0x3B1E, 開くときの gBgPlttFadeRowMask
  u16 savedObjPlttBlendColor;    // 0x3B20, 開くときの gObjPlttBlendColor
  u16 savedObjPlttFadeSkipMask;  // 0x3B22, 開くときの gObjPlttFadeSkipMask
  u8 dpadRepeatTimer;            // 0x3B24, 十字キーを押しっぱなしにしている間のフレーム数, 10 で 0 に戻る
  u8 yesNoCursor;                // 0x3B25, はい/いいえ の選択, 1: はい, 0: いいえ
  u8 unk_3b26[0x3B28 - 0x3B26];  // 0x3B26, まだ未解析
  MenuItemMove itemMoves[2];     // 0x3B28, 動かすアイコンは sprites[46 + i]
  s16 unk_3b68[2];               // 0x3B68
  u8 unk_3b6c[0x3B70 - 0x3B6C];  // 0x3B6C, まだ未解析
  s16 unk_3b70[2];               // 0x3B70
  u8 unk_3b74[0x3B8C - 0x3B74];  // 0x3B74, まだ未解析
  MMenuPtclSet ptclSets[2];      // 0x3B8C, FUN_0808cacc が2組とも Particle_Remove で片付ける
  bool8 inValuableInventory;     // 0x3F9C
  u8 helperChara;                // 0x3F9D, アイテムを使う演出に出るキャラ, gfx.rita からの添字 (0: リタ, 1: カーミラ), サバタは常に 1, ジャンゴは 20% で 1
  u8 vitaminStat;                // 0x3F9E, IET_VITAMINS で上げるステータス番号, MainMenu_ShowVitaminResult が +255 してメッセージ行IDにする
  u8 vitaminAmount;              // 0x3F9F, IET_VITAMINS で上げる量, 合計99で頭打ちになる前の値
  u8 unk_3fa0;                   // 0x3FA0, '.p'
  u8 unk_3fa1;                   // 0x3FA1
  s16 effectAmount;              // 0x3FA2, アイテム使用時のポップアップに出す効果量, MainMenu_StateItemEffectApply が符号付きで読んで MainMenu_ShowPopupNumber に渡す
  u16 prevHP;                    // 0x3FA4, アイテムを使う前のHP
  u16 targetHP;                  // 0x3FA6, 変化後のHP, MainMenu_StateApproachHPEne が player->hp をここまで少しずつ動かす
  u16 prevEne;                   // 0x3FA8, アイテムを使う前のEne
  u16 targetEne;                 // 0x3FAA, 変化後のEne, 同上
  bool8 pendingBugs;             // 0x3FAC, 閉じたあとにプレイヤーの周りへ虫を出す
  u8 bugsKind;                   // 0x3FAD, 出す虫の種類
  u16 bugsAmount;                // 0x3FAE, 虫の量
  bool8 pendingWarp;             // 0x3FB0, 閉じたあとに warpScriptID を実行する
  u8 warpKind;                   // 0x3FB1, ワープの種類
  u8 unk_3fb2[2];                // 0x3FB2
  u32 warpScriptID;              // 0x3FB4, '.R'
  bool8 pendingAOE;              // 0x3FB8, 閉じたあとに全体攻撃のエフェクトを出す
  u8 aoeKind;                    // 0x3FB9, 全体攻撃の種類
  u8 unk_3fba;                   // 0x3FBA
  u8 pendingCard;                // 0x3FBB, 閉じたあとに cardScriptID を実行する, 1: 吊るされた男, 2: 死神, 引数には 1 を引いて渡す
  u32 cardScriptID;              // 0x3FBC, '.D'
  Weapon weapon;                 // 0x3FC0, WEAPON_GUN_DEL_HELL の内容が入る
  s8 equippedArmorSlot;          // 0x3FDC, 装備中の防具の armorIDs の添字, この枠だけは選べない
  u8 unk_3fdd[0x3FE0 - 0x3FDD];  // 0x3FDD, まだ未解析
  s8 armorIDs[16];               // 0x3FE0, 枠ごとの防具ID, 負なら空き
  u8 magicIDs[16];               // 0x3FF0, 魔法ページの枠ごとの魔法ID, 読み手は (s8) を付けて負を空きと見る, FUN_0809890c / FUN_08098934 が 8..11 と 12..15 を負かどうかで見る
  u16 statusPoint;               // 0x4000, 残りのステータスポイント, 確定時に gStat->statusPoint へ書き戻す
  u8 statRow;                    // 0x4002, ステータスページでカーソルのある行
  s8 pendingLine;                // 0x4003, 次のフレームで MainMenu_ShowLineInstant に渡すメッセージ行, -1 なら何もしない
  u8 shownStats[4];              // 0x4004, 画面に出すステータス, stats に防具の補正を足したもの, 99 で打ち止め
  u8 allocatedStats[4];          // 0x4008, 画面で振り分けた分, 確定時に gStat->stats へ足す
  u8 unk_400c;                   // 0x400C
  u8 configRow;                  // 0x400D, コンフィグのカーソル行, config の添字
  u8 config[3];                  // 0x400E, コンフィグの設定値, 添字は CONFIG_*, 文字速度は 0: 遅い, 1: 普通, 2: 速い (なぜか gStat->textSpeed をそのまま使わない)
  u8 unk_4011[3];                // 0x4011, まだ未解析
  s32 textPanelID_4014;          // 0x4014, 6,4 の位置の 10x2 のテキストパネル
  s32 textPanelID;               // 0x4018, TextPanel_Hide に渡す
  u8 loanMenuRow;                // 0x401C, 暗黒ローンの2択メニューのカーソル, 0 か 1
  u8 unk_401d;                   // 0x401D, 根拠: ItemEffect_Loan が 1 を入れる
  u8 loanRate;                   // 0x401E, 暗黒ローンの倍率, loanEne * loanRate が返済額に足される, 画面を開くときに FUN_0808f140 で決まる
  bool8 unk_401f;                // 0x401F, '.V'
  u8 loanStandPose;              // 0x4020, 量を変えたときの太陽スタンドの絵の先頭, 増やすと 19, 減らすと 22
  u8 loanStandTimer;             // 0x4021, 量を変えたときの太陽スタンドのアニメ, 0..15 を回して 0 で止まる
  u16 loanEne;                   // 0x4022, 借りるエナジーの量, 確定時に player->ene へ足す
  u16 loanLimitTimer;            // 0x4024, 借りられる上限 (返済額 9999) を超えようとすると 60 を入れ, 0 になるまで数字を隠して警告を出す
  u16 loanLimitMsgShown;         // 0x4026, 上限の警告文を出した
  u32 scriptID;                  // 0x4028, '.d'
  const MapScreen* mapScreens;   // 0x402C, sMapScreenTables[stageID]
  const MapSpot* mapSpots;       // 0x4030, sMapSpotTables[stageID]
  const MapIcon* mapIcons;       // 0x4034, sMapIconTables[stageID], NULL ならアイコンなし
  u8 mapScreen;                  // 0x4038, 表示中の画面, mapScreens の添字
  bool8 mapVisible;              // 0x4039, 表示中の画面の地図を持っていれば TRUE, FALSE なら BG1 を塗りつぶす
  u8 unk_403a[2];                // 0x403A, まだ未解析
  s8 mapArrows[4];               // 0x403C, 上/下/左/右 の矢印の行き先, mapScreens の添字, -1 はなし
  s16 mapScrollX;                // 0x4040, ピクセル単位
  s16 mapScrollY;                // 0x4042, ピクセル単位
  s16 mapScrollMinX;             // 0x4044
  s16 mapScrollMinY;             // 0x4046
  s16 mapScrollMaxX;             // 0x4048, (MapScreen.width - 30) * 8
  s16 mapScrollMaxY;             // 0x404A, (MapScreen.height - 20) * 8
  s16 mapOriginX;                // 0x404C, MapScreen.originX * 8
  s16 mapOriginY;                // 0x404E, MapScreen.originY * 8
  u16 playerScreen;              // 0x4050, プレイヤーのいる画面, mapScreens の添字
  u16 playerMapX;                // 0x4052, プレイヤーのマーカーの位置, ピクセル単位
  u16 playerMapY;                // 0x4054, 同上
  u16 coffinScreen;              // 0x4056, 棺桶のある画面, 0xFF なら別のステージ
  u16 coffinMapX;                // 0x4058, 棺桶のマーカーの位置, ピクセル単位
  u16 coffinMapY;                // 0x405A, 同上
} MainMenu;
static_assert(sizeof(MainMenu) == 16476);

IWRAM_DATA MainMenu* gMainMenu = NULL;  // 0x0300013C

COMMON_DATA u16 u16_03002c10 = 0;                              // 0x03002C10, FUN_080916bc がビット単位で読むフラグ
COMMON_DATA u8 u8_03002c12[0x03002C14 - 0x03002C12] = {};      // todo
COMMON_DATA u16 gSavedMenuPage = 0;                            // 0x03002C14, 根拠: MainMenu1P_Destroy が MainMenu.page を書き込む
COMMON_DATA u8 u8_03002c16[0x03002C18 - 0x03002C16] = {};      // todo
COMMON_DATA u16 u16_03002c18 = 0;                              // 0x03002C18, FUN_0809c040 が 1 を入れる
COMMON_DATA u8 u8_03002c1a[0x03002C20 - 0x03002C1A] = {};      // todo
COMMON_DATA char gWeaponPSText[0x03002C3C - 0x03002C20] = {};  // 0x03002C20, 武器説明のマーキーに出す PS の文字列, 末尾に「作」相当の制御列を足す

#define BGMAP_BGP13 (13 << 12)
#define BGMAP_BGP15 (15 << 12)

void SleepGame(void);

#define INVENTORY_SLOT(p, colX, rowY) ((p)->slotmap[(rowY) + (colX) * 4])  // InventoryCursor で カーソルの位置に対応するスロット番号を取得するマクロ

// BGパレットの行13 (色208) 以降を指す
static inline rgb555* BgPlttRow13(BgPlttFile* f) { return &f->body[13 * 16]; }

static inline Player* GetPlayer(s32 idx) { return gPlayerPtr[idx]; }

// 魔法ページでカーソルのある枠の魔法ID, 魔法の枠でないか空きなら負
static inline s32 MainMenu_GetCursorMagicID(MainMenu* p) {
  if (p->cursor.slot > 15) {
    return -1;
  }
  return (s8)p->magicIDs[p->cursor.slot];
}

// 通信中の自分の gPlayerPtr の添字, 通信していなければ -1
static inline s32 GetLinkPlayerIdx(void) {
  if (gEntity9A9F == NULL) {
    return -1;
  }
  return gEntity9A9F->playerIdx;
}

// まだセッションが無ければ 0
static inline u8 Entity9A9F_GetUnk60(s32 idx) {
  if (gEntity9A9F == NULL) {
    return 0;
  }
  return gEntity9A9F->unk_60[idx];
}

// 投げた下駄の回転の速さを 5〜14 の範囲で, 向きも含めてランダムに決める
static inline void SetRandomSpin(u16* spin) {
  u16* table = gRandomTable;

  *spin = Mod(_Random(table), 10) + 5;
  if (_Random(table) & 1) {
    *spin = -*spin;
  }
}

extern u16 gMosaicDirty;
extern u16 gMosaicSize;
extern u8 gObjMosaicEnabled;
extern u8 gMosaicTargets;

s32 CrossoverBattle_GetRivalPlayerHP(void);
s32 CrossoverBattle_GetRivalBossHP(void);
s32 CrossoverBattle_GetBlockCount(void);
s32 CrossoverBattle_GetRound(void);
s32 CrossoverBattle_ToggleBlocking(void);
void BuildWeaponData(Weapon* w, WeaponData* data);
void GetWeaponData(slot32_t n, WeaponData* data);
extern u16 u16_03004864;
void Cmd_4B57(void);
void Cmd_4B39(void);
void RegisterWeapon(slot32_t n, s32 slot);
void RegisterMagic(s32 idx, magic32_t m);
void UnregisterMagic(s32 idx);
void GetRegisteredWeaponData(s32 idx, WeaponData* data);
s32 CalcAttackWithEquippedArmor(WeaponData* w);
struct Entity080aace8* Entity080aace8_Create(Player* player, u32 kind);
s32 CalcAttack(WeaponData* w, const ArmorData* armor);
s32 CalcDefence(const ArmorData* data);
s32 Marquee_SetVarValue(s32 idx, s32 value);
s32 Marquee_SetExtendValue(s32 idx, char* str);
void UncoverChocolate(slot32_t slot);
void Player_EquipArmor(Player* p, const ArmorData* a);
void FUN_0809630c(MainMenu* p);
void MainMenu_StateArmorPage(MainMenu* p);
void MainMenu_ReturnToWeaponPage(MainMenu* p);
void MainMenu_ReturnToArmorPage(MainMenu* p);
void FUN_0809a448(MainMenu* p);
void MainMenu_StateMagicPage(MainMenu* p);
void FUN_0809a324(MainMenu* p);
void FUN_0809a3f4(MainMenu* p);
void FUN_0809aaf4(MainMenu* p);
void FUN_08097604(MainMenu* p);
void FUN_08092bb8(MainMenu* p);
void FUN_0809a4c0(MainMenu* p);
void FUN_0809ab70(MainMenu* p);
void FUN_0808f09c(MainMenu* p);
void MainMenu_StateItemPage(MainMenu* p);
void FUN_08093264(MainMenu* p);
void FUN_0808f774(MainMenu* p);
void MainMenu_StateWeaponPage(MainMenu* p);
void FUN_0809a1a4(MainMenu* p);
void MainMenu_StateWeaponTrashShake(MainMenu* p);
void MainMenu_StateArmorTrashShake(MainMenu* p);
void MainMenu_StateLoanThanks(MainMenu* p);
void FUN_0808f0d8(MainMenu* p);
void FUN_0808eef8(MainMenu* p);
void FUN_0808e400(MainMenu* p);
void MainMenu_UpdateConfig(MainMenu* p);
void FUN_0809a368(MainMenu* p);
void MainMenu_UpdateFadeOut(MainMenu* p);
bool32 MainMenu_QC_TryOpen(MainMenu* p);
s32 FUN_0809b3b0(MainMenu* p);
void MainMenu_QC_Update(MainMenu* p);
void MainMenu_ShowVitaminResult(MainMenu* p);
void FUN_080931cc(MainMenu* p);
void FUN_08093158(MainMenu* p);
void MainMenu_StateApproachHPEne(MainMenu* p);
void FUN_08093710(MainMenu* p);
void FUN_0808eeac(MainMenu* p);
void MainMenu_StateClosing(MainMenu* p);
void FUN_08099f18(MainMenu* p);
void MainMenu_StateLoanMenu(MainMenu* p);
void FUN_080962b0(MainMenu* p);
void FUN_0809611c(MainMenu* p);
void MainMenu_StateSwapWeapon(MainMenu* p);
void MainMenu_StateConfirmStatus(MainMenu* p);
void UnregisterWeapon(s32 n);
void MainMenu_StateConfirmDiscardArmor(MainMenu* p);
void MainMenu_StateEquipArmor(MainMenu* p);
void MainMenu_StateSwapArmor(MainMenu* p);
void MainMenu_StateItemEffectApply(MainMenu* p);
void FUN_08092b3c(MainMenu* p);
void MainMenu_StateItemEffectPopup(MainMenu* p);
void FUN_08093c64(MainMenu* p);
void FUN_08093de8(MainMenu* p);
void FUN_0809458c(MainMenu* p);
void FUN_08093318(MainMenu* p);
void FUN_0808f8bc(MainMenu* p);
void FUN_08093990(MainMenu* p);
void FUN_08093a54(MainMenu* p);
void FUN_08093b20(MainMenu* p);
void FUN_08094d30(s32 param_1, u8* param_2, s8* param_3);
void FUN_0808f7cc(MainMenu* p);
void FUN_080938d0(MainMenu* p);
void MainMenu_StateMagicQuickChange(MainMenu* p);
void MainMenu_StateMagicPickTarget(MainMenu* p);
void FUN_0808f604(MainMenu* p);
void FUN_0809b2b8(MainMenu* p);
void MainMenu_StateRegisterMagic(MainMenu* p);
void MainMenu_StateLoanSelectAmount(MainMenu* p);
void MainMenu_StateWeaponQuickChange(MainMenu* p);
void FUN_080960c8(MainMenu* p);
void MainMenu_StateWeaponPickTarget(MainMenu* p);
void MainMenu_StateConfirmSortItems(MainMenu* p);
void MainMenu_StateItemPickTarget(MainMenu* p);
void FUN_08097530(MainMenu* p);
void MainMenu_StateThrowGeta(MainMenu* p);
void FUN_0809b12c(MainMenu* p);
void FUN_08093580(MainMenu* p);
void FUN_0809455c(MainMenu* p);
void MainMenu_StateSwapItem(MainMenu* p);
void MainMenu_StateArmorPickTarget(MainMenu* p);
void MainMenu_StateUnregisterMagic(MainMenu* p);
void FUN_0808f81c(MainMenu* p);
void MainMenu_UpdateLoanIntro(MainMenu* p);
void FUN_08231d5c(void* statFieldPtr, s32 bytesize);

// MainMenu_QC_DrawFrame が参照
const u16 u16_ARRAY_085ac064[16] = {
    0xD01B,
    0xD000,
    0xD000,
    0xD41B,
    0xD02B,
    0xD000,
    0xD000,
    0xD42B,
    0xD02B,
    0xD000,
    0xD000,
    0xD42B,
    0xD81B,
    0xD000,
    0xD000,
    0xDC1B,
};  // 0x085AC064

// updateCallback を差し替えて updateTimer を 0 に戻す
void MainMenu_SetUpdateCallback(MainMenu* p, MainMenuFunc* fn) {
  p->updateCallback = fn;
  p->updateTimer = 0;
}

// 状態関数を差し替えて, hide で2枚のスプライトの表示/非表示を切り替える
void MainMenu_SetState(MainMenu* p, MainMenuFunc* fn, bool32 hide) {
  p->fn = fn;
  p->stateTimer = 0;
  p->hidden = hide;
  if (p->hidden) {
    p->sprites[1].flags |= SPRFLAG_HIDDEN;
    p->sprites[2].flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  }
}

// BG0 をタイルマップで組み直して, パレット行13〜15 を差し替える
void FUN_0808a3c4(MainMenu* p, TilemapFile* tilemap, s16 param_3, s32 layerIdx, const rgb555* pltt) {
  s32 bgIndex = 0;

  Video_SetupBGLayout(0, param_3, tilemap, 0, 0, 1, &bgIndex);
  Video_SetBGLayer(0, tilemap, layerIdx);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  CpuCopy32(pltt, &gBgPlttBuffer[13 * 16], 48 * sizeof(rgb555));
}

static BgMapEntry* MainMenu_GetBgMapAddr(s32 bg, u32 x, u32 y) {
  BgState* s = &gBgStates[bg];
  BgMapEntry* map = s->tilemap;

  return map + (x & 31) + (y & 31) * 32;
}

// 数字 param_1 の BG タイル番号, param_2 は書体 (0: 0x11〜, 1: 0x91〜, それ以外: 0x31〜)
s32 GetDigitTile(s32 param_1, s32 param_2) {
  s32 off = 0x11;

  if (param_2 != 0) {
    off = 0x31;
    if (param_2 == 1) {
      off = 0x91;
    }
  }

  return param_1 + off;
}

// BG と OBJ の明るさ・ブレンド色をまとめて設定する
void SetScreenBrightness(s32 brightness, s32 color) {
  gBgPlttBlendColor = color;
  gBgPlttFadeRowMask = 0xFFFF;
  gBgBrightness = brightness;
  gObjPlttBlendColor = color;
  gObjPlttFadeSkipMask = 0;
  gObjBrightness = brightness;
}

static s32 MinS32(s32 a, s32 b) {
  s32 min = b;
  if (a <= b) {
    min = a;
  }
  return min;
}

// BG0 に「現在値/最大値」を3桁ずつ描く, param_2 で文字の種類と色を切り替える
void MainMenu_DrawFraction(MainMenu* p, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) {
  s32 cur[3];
  s32 max[3];
  s32 rest;
  BgMapEntry* map;
  s32 blank;
  s32 slash;
  s32 font;
  s32 trailing;
  s32 pltt;
  s32 i;

  cur[0] = Div(param_3, 100);
  rest = param_3 - cur[0] * 100;
  cur[1] = Div(rest, 10);
  cur[2] = rest - cur[1] * 10;
  max[0] = Div(param_4, 100);
  rest = param_4 - max[0] * 100;
  max[1] = Div(rest, 10);
  max[2] = rest - max[1] * 10;

  if (param_2 == 0) {
    blank = 0;
    slash = 28;
    font = 0;
    trailing = 3;
    pltt = 0xD000;
    map = MainMenu_GetBgMapAddr(0, param_5, param_6);
  } else {
    blank = 1;
    slash = 155;
    font = 1;
    trailing = 4;
    pltt = 0xF000;
    map = MainMenu_GetBgMapAddr(0, param_5 - 1, param_6);
  }
  *map++ = pltt | blank;
  for (i = 0; i < 3; i++) {
    *map++ = GetDigitTile(cur[i], font) | pltt;
  }
  *map++ = pltt | slash;
  for (i = 0; i < 3; i++) {
    *map++ = GetDigitTile(max[i], font) | pltt;
  }
  for (i = 0; i < trailing; i++) {
    *map++ = pltt | blank;
  }
}

// HP を MainMenu_DrawFraction に渡す
void MainMenu_DrawHP(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) { MainMenu_DrawFraction(p, param_2, p->player->hp, p->player->maxHP, param_3, param_4); }

// EN を MainMenu_DrawFraction に渡す
void MainMenu_DrawEne(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) { MainMenu_DrawFraction(p, param_2, p->player->ene, p->player->maxEne, param_3, param_4); }

// BG0 に HP ゲージを10マスで描き, 残量で枠の色を変える (少ないと点滅)
// 残差: 150/149 命令, 原典は点滅色の 0x12 を r4 に直接作り, 端数のタイルを bodyTile - (rem - 8) の順に作るが, こちらは別レジスタから移して (bodyTile + 8) - rem に畳む (if で色を作る形は命令数が合うが割り当てが崩れる)
NON_MATCH s32 MainMenu_DrawHPGauge(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) {
#ifdef NONMATCHING_C
  s32 hp = p->player->hp;
  s32 maxHP = p->player->maxHP;
  s32 v;
  s32 full;
  s32 rem;
  s32 bodyTile;
  s32 emptyTile;
  s32 endTile;
  rgb555 color;
  BgMapEntry* map;
  s32 i;

  if (hp == 0) {
    v = 0;
    full = 0;
    rem = 0;
  } else {
    v = Div((hp - 1) * 79, maxHP - 1) + 1;
    full = v >> 3;
    rem = v - (full << 3);
  }

  if (param_2 == 0) {
    bodyTile = 0x43;
    emptyTile = 0x4B;
    endTile = 0x4C;
    if (v > 39) {
      color = 0x3E0;
    } else if (v > 19) {
      color = 0x29F;
    } else {
      color = (p->hpBlinkTimer >> 2) & 1 ? 0x109F : 0x12;
      p->hpBlinkTimer++;
    }
    map = MainMenu_GetBgMapAddr(0, param_3, param_4);
  } else {
    bodyTile = 0x63;
    emptyTile = 0x6B;
    endTile = 0x4BD;
    color = 0x3E0;
    if (v <= 39) {
      color = 0x109F;
      if (v > 19) {
        color = 0x29F;
      }
    }
    map = MainMenu_GetBgMapAddr(0, param_3 - 1, param_4);
    *map++ = 0xD0BD;
  }
  {
    rgb555* pltt = &gBgPlttBuffer[219];

    if (*pltt != color) {
      *pltt = color;
    }
  }
  for (i = 0; i < full; i++) {
    *map++ = bodyTile | 0xD000;
  }
  if (rem != 0) {
    *map++ = (bodyTile - (rem - 8)) | 0xD000;
    i++;
  }
  for (; i < 10; i++) {
    *map++ = emptyTile | 0xD000;
  }
  *map = endTile | 0xD000;
#else
  INCFUNC("asm/func/MainMenu_DrawHPGauge.inc");
#endif
}

// HUD の EN ゲージを描く, アストロ武器を装備していれば太陽スタンドの貯金も出す
// 残差: 252/251 命令, MainMenu_DrawHPGauge と同じく端数のタイルを (bodyTile + 8) - rem に畳んで1命令多く, param_3 を r4 に置く (原典は sl)
NON_MATCH s32 MainMenu_DrawEneGauge(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) {
#ifdef NONMATCHING_C
  s32 ene = p->player->ene;
  s32 maxEne = p->player->maxEne;
  s32 v;
  s32 full;
  s32 rem;
  s32 bodyTile;
  s32 emptyTile;
  s32 endTile;
  rgb555 color;
  BgMapEntry* map;
  s32 i;

  if (ene == 0) {
    full = 0;
    rem = 0;
  } else {
    v = Div((ene - 1) * 79, maxEne - 1) + 1;
    full = v >> 3;
    rem = v - (full << 3);
  }

  color = 0x1F;
  if (p->player->kind != PLAYER_SABATA) {
    color = 0x35F;
  }
  if (param_2 == 0) {
    bodyTile = 0x53;
    emptyTile = 0x4B;
    endTile = 0x4C;
    if (Player_TestFlag20(p->player, PFLAG20_QC | PFLAG20_REFUELING)) {
      if (!((++p->eneBlinkTimer >> 2) & 1)) {
        color = 0x7FFF;
      }
    }
    map = MainMenu_GetBgMapAddr(0, param_3, param_4);
  } else {
    bodyTile = 0x73;
    emptyTile = 0x6B;
    endTile = 0x4BD;
    map = MainMenu_GetBgMapAddr(0, param_3 - 1, param_4);
    *map++ = 0xD0BD;
  }
  {
    rgb555* pltt = &gBgPlttBuffer[220];

    if (*pltt != color) {
      *pltt = color;
    }
  }
  for (i = 0; i < full; i++) {
    *map++ = bodyTile | 0xD000;
  }
  if (rem != 0) {
    *map++ = (bodyTile - (rem - 8)) | 0xD000;
    i++;
  }
  for (; i < 10; i++) {
    *map++ = emptyTile | 0xD000;
  }
  *map = endTile | 0xD000;

  if (!(gGameFlags & GAMEFLAG_CROSSOVER) && param_2 == 0) {
    if (Player_TestEquipBuff(p->player, EBUFF_ASTRO)) {
      s32 digits[4];
      s32 n;

      digits[0] = Div(gStat->solarStand, 1000);
      n = gStat->solarStand - digits[0] * 1000;
      digits[1] = Div(n, 100);
      n -= digits[1] * 100;
      digits[2] = Div(n, 10);
      n -= digits[2] * 10;
      digits[3] = n;
      map = MainMenu_GetBgMapAddr(0, 9, 3);
      for (i = 0; i < 4; i++) {
        *map++ = GetDigitTile(digits[i], 0) | 0xD000;
      }
      p->solarStandShown = TRUE;
    } else if (p->solarStandShown) {
      map = MainMenu_GetBgMapAddr(0, 9, 3);
      for (i = 0; i < 4; i++) {
        *map++ = 0xD000;
      }
      p->solarStandShown = FALSE;
    }
  }
#else
  INCFUNC("asm/func/MainMenu_DrawEneGauge.inc");
#endif
}

void FUN_0808a9a0(void) {}

// HUD の太陽ゲージを描く, 熱中症が溜まると点滅し, カーモス状態ならその表示も出す
// 残差: 240/240 命令, 引数の割り当てだけが違い, 原典は param_2 を r7, param_3/param_4 を r8/r9 に置くが, こちらは param_3/param_4 が r7/r8 で param_2 が r9 になる (ゲージ部分の static inline 化は悪化)
NON_MATCH void MainMenu_DrawSunGauge(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) {
#ifdef NONMATCHING_C
  BgMapEntry* map;
  bool32 hidden;
  s32 i;

  if (p->player->action == PACT_UNK_30) {
    hidden = TRUE;
  } else if (gStat->heatstroke > 2499) {
    if ((p->heatBlinkTimer >> 4) & 1) {
      hidden = FALSE;
    } else {
      hidden = TRUE;
    }
    if ((p->heatBlinkTimer & 0x3F) == 2) {
      PlaySound_082406e0(306);
    }
    p->heatBlinkTimer++;
  } else if (gStat->heatstroke > 0) {
    if ((p->heatBlinkTimer >> 5) & 1) {
      hidden = FALSE;
    } else {
      hidden = TRUE;
    }
    if ((p->heatBlinkTimer & 0x3F) == 2) {
      PlaySound_082406e0(305);
    }
    p->heatBlinkTimer++;
  } else {
    hidden = FALSE;
    p->heatBlinkTimer = 0;
  }
  map = MainMenu_GetBgMapAddr(0, param_3, param_4);
  if (hidden) {
    for (i = 0; i < 12; i++) {
      *map++ = (i + 3) | 0xD000;
    }
  } else {
    rgb555 color;
    s32 n;

    if (param_2 == 1) {
      color = 0x29F;
    } else if (Player_TestFlag20(p->player, PFLAG20_SUNBATHING)) {
      u16 t = p->sunFrameTimer;

      color = 0x29F;
      if (t > 36) {
        color = 0x1FB;
        if (t > 44) {
          if (t <= 52) {
            color = 0x177;
          }
        }
      }
      if (++p->sunFrameTimer > 59) {
        p->sunFrameTimer = 0;
      }
    } else {
      p->sunFrameTimer = 52;
      color = 0x177;
    }
    {
      rgb555* pltt = &gBgPlttBuffer[218];

      if (*pltt != color) {
        *pltt = color;
      }
    }

    n = gStat->sunGauge;
    *map++ = 0xD05C;
    for (i = 0; i < n; i++) {
      *map++ = 0xD05D;
    }
    for (; i < 10; i++) {
      *map++ = 0xD05E;
    }
    *map = 0xD05F;
  }
  if (KAAMOS(p->player->isSabata) > 0) {
    map = MainMenu_GetBgMapAddr(0, 15, 17);
    for (i = 0; i < 5; i++) {
      *map++ = (i + 59) | 0xD000;
    }
    p->kaamosShown = TRUE;
  } else if (p->kaamosShown) {
    map = MainMenu_GetBgMapAddr(0, 15, 17);
    for (i = 0; i < 5; i++) {
      *map++ = 0xD000;
    }
    p->kaamosShown = FALSE;
  }
#else
  INCFUNC("asm/func/MainMenu_DrawSunGauge.inc");
#endif
}

// 画面右上のボスの HP ゲージを右から10マスで描き, 減ったときやボス戦かどうかで枠とゲージの色を変える
void MainMenu_DrawBossGauge(MainMenu* p, s32 param_2) {
  rgb555 frame;
  rgb555 gauge;
  rgb555* pltt;
  s32 full;
  s32 rem;
  BgMapEntry* map;
  s32 i;

  if (param_2 == 1) {
    frame = 0x1F;
    if (p->prevBossHP < gStat->bossHP) {
      if ((++p->bossBlinkTimer >> 2) & 1) {
        gauge = 0x3E0;
      } else {
        gauge = 0x7FFF;
      }
    } else if (p->bossFlashTimer != 0) {
      gauge = 0x7FFF;
      p->bossFlashTimer--;
    } else {
      gauge = 0x3E0;
    }
  } else {
    frame = 0x39CE;
    if (p->bossFlashTimer != 0) {
      gauge = 0x7FFF;
      p->bossFlashTimer--;
    } else {
      gauge = 0x1F;
    }
  }
  pltt = &gBgPlttBuffer[222];
  if (*pltt != frame) {
    *pltt = frame;
  }
  pltt--;
  if (*pltt != gauge) {
    *pltt = gauge;
  }

  p->prevBossHP = gStat->bossHP;
  if (gStat->bossHP <= 0) {
    full = 0;
    rem = 0;
  } else if (gStat->bossHPMax > 1) {
    s32 dots = 10 * 8;

    rem = Div((dots - 1) * (gStat->bossHP - 1), gStat->bossHPMax - 1) + 1;
    full = rem >> 3;
    rem -= full << 3;
  } else {
    full = 10;
    rem = 0;
  }
  map = MainMenu_GetBgMapAddr(0, 29, 1);
  *map-- = 0xD08C;
  *map-- = 0xD08B;
  *map-- = 0xD08A;
  for (i = 0; i < full; i++) {
    *map-- = 0xD089;
  }
  if (rem != 0) {
    *map-- = (rem + 0x81) | 0xD000;
    i++;
  }
  for (; i < 10; i++) {
    *map-- = 0xD081;
  }
  *map = 0xD080;
}

// 右上に敵の HP ゲージ (なければ棺桶運搬中の黒ジャンゴのゲージ) を出し, 時間が切れたら消す
void MainMenu_DrawEnemyGauge(MainMenu* p) {
  bool32 drawn = FALSE;
  s32 full = 0;
  s32 dots = 0;
  s32 len = 0;
  rgb555 gauge = 0;
  rgb555 frame = 0;
  s32 icon = 0;
  BgMapEntry* map;
  s32 i;

  if (p->enemyGaugeTimer) {
    frame = 0x39CE;
    if (p->enemyGaugeFlash) {
      gauge = 0x7FFF;
      p->enemyGaugeFlash--;
    } else {
      gauge = 0x1F;
    }
    len = p->enemyGaugeCells;
    dots = len * 8;
    if (p->enemyGaugeHP == 0) {
      full = 0;
      dots = 0;
    } else {
      dots = Div((dots - 1) * (p->enemyGaugeHP - 1), p->enemyGaugeMaxHP - 1) + 1;
      full = dots >> 3;
      dots -= full << 3;
    }
    icon = 140;
    p->enemyGaugeTimer--;
    p->enemyGaugeShown = TRUE;
    drawn = TRUE;
    if (p->coffinGaugeTimer) {
      p->coffinGaugeTimer--;
    }
  } else if (p->coffinGaugeTimer) {
    frame = 0x1F;
    if (p->coffinGaugeFlash) {
      gauge = 0x7FFF;
      p->coffinGaugeFlash--;
    } else {
      gauge = 0x3E0;
    }
    len = 10;
    dots = len * 8;
    if (p->coffinGaugeHP == 0) {
      full = 0;
      dots = 0;
    } else {
      dots = Div((dots - 1) * (p->coffinGaugeHP - 1), p->coffinGaugeMaxHP - 1) + 1;
      full = dots >> 3;
      dots -= full << 3;
    }
    icon = 66;
    p->enemyGaugeShown = TRUE;
    p->coffinGaugeTimer--;
    drawn = TRUE;
  }

  if (drawn) {
    {
      rgb555* pltt = &gBgPlttBuffer[222];

      if (*pltt != frame) {
        *pltt = frame;
      }
    }
    {
      rgb555* pltt = &gBgPlttBuffer[221];

      if (*pltt != gauge) {
        *pltt = gauge;
      }
    }
    map = MainMenu_GetBgMapAddr(0, 29, 1);
    for (i = 0; i < 3; i++) {
      *map-- = icon | 0xD000;
      icon--;
    }
    for (i = 0; i < full; i++) {
      *map-- = 0xD089;
    }
    if (dots != 0) {
      *map-- = (dots + 0x81) | 0xD000;
      i++;
    }
    for (; i < len; i++) {
      *map-- = 0xD081;
    }
    *map-- = 0xD080;
    for (i++; i <= 10; i++) {
      *map-- = 0xD000;
    }
  } else if (p->enemyGaugeShown) {
    map = MainMenu_GetBgMapAddr(0, 29, 1);
    for (i = 0; i < 14; i++) {
      *map-- = 0xD000;
    }
    p->enemyGaugeShown = FALSE;
  }
}

// HUD 左上の状態アイコン, よいステータス効果の残り秒数か gStat->unk_2b0 の状態を出し, 何もなくなったら消す
void MainMenu_UpdateCondIcon(MainMenu* p) {
  BgMapEntry* map;

  if (p->player->goodCondTimer != 0) {
    s32 sec;
    s32 tens;

    p->unk_a34.flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->unk_a34, &p->gfx.icons, p->player->goodFrom + 104, PLAYMODE_LOOP);
    map = MainMenu_GetBgMapAddr(0, 1, 5);
    sec = Div(p->player->goodCondTimer + 59, 60);
    tens = Div(sec, 10);
    sec -= tens * 10;
    *map++ = GetDigitTile(tens, 0) | 0xD000;
    *map = GetDigitTile(sec, 0) | 0xD000;
    p->condIconShown = 1;
  } else if (gStat->unk_2b0[0] != 0) {
    p->unk_a34.flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->unk_a34, &p->gfx.icons, 131, PLAYMODE_LOOP);
    map = MainMenu_GetBgMapAddr(0, 1, 5);
    map[0] = 0xD000;
    map[1] = 0xD000;
    p->condIconShown = 1;
  } else if (gStat->unk_2b0[1] != 0) {
    p->unk_a34.flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->unk_a34, &p->gfx.icons, 132, PLAYMODE_LOOP);
    map = MainMenu_GetBgMapAddr(0, 1, 5);
    map[0] = 0xD000;
    map[1] = 0xD000;
    p->condIconShown = 1;
  } else if (p->condIconShown) {
    p->unk_a34.flags |= SPRFLAG_HIDDEN;
    map = MainMenu_GetBgMapAddr(0, 1, 5);
    map[0] = 0xD000;
    map[1] = 0xD000;
    p->condIconShown = 0;
  }
}

// カウントダウン HUD の表示が切り替わったときにカウント音を鳴らし, 今の値を覚えておく
void FUN_0808b11c(MainMenu* p, s32 param_2, u32 param_3) {
  if (gGameFlags & GAMEFLAG_CROSSOVER) {
    if (param_2 == 0 && param_3 - 1 < 3 && param_3 != p->unk_a9b) {
      PlaySound_082406e0(SE_COUNTDOWN);
    }
  } else if (!p->unk_a98) {
    if (!p->unk_a99) {
      PlaySound_082406e0(SE_COUNTDOWN);
    }
    p->unk_a98 = 1;
  } else if ((param_2 == 0 || (param_2 == 1 && param_3 == 0)) && param_3 != p->unk_a9b) {
    PlaySound_082406e0(SE_COUNTDOWN);
  }
  p->unk_a9a = param_2;
  p->unk_a9b = param_3;
}

// HUD のカウントダウン (unk_a9c が指す残りフレーム) を秒に直して2桁で描く, 99 秒を超える間は隠す
void MainMenu_UpdateCountdown(MainMenu* p) {
  s32 i;

  if (p->unk_a97) {
    if (p->player == NULL || TEST_FLAGS(gPlayerModes[0], 4)) {
      for (i = 0; i < 2; i++) {
        p->unk_aa0[i].flags |= SPRFLAG_HIDDEN;
      }
      p->unk_a97 = 0;
    } else {
      s32 t = *p->unk_a9c;

      if (t > 5940) {
        for (i = 0; i < 2; i++) {
          p->unk_aa0[i].flags |= SPRFLAG_HIDDEN;
        }
        p->unk_a98 = 0;
      } else {
        s32 tens;

        for (i = 0; i < 2; i++) {
          p->unk_aa0[i].flags &= ~SPRFLAG_HIDDEN;
        }
        if (t > 0) {
          t = Div(t - 1, 60) + 1;
          tens = Div(t, 10);
          t -= tens * 10;
        } else {
          tens = 0;
          t = 0;
        }
        if (tens == 0) {
          MainSprite_SetPose(&p->unk_aa0[0], &p->gfx.smenu, 125, PLAYMODE_LOOP);
          MainSprite_SetPose(&p->unk_aa0[1], &p->gfx.smenu, t + 125, PLAYMODE_LOOP);
        } else {
          MainSprite_SetPose(&p->unk_aa0[0], &p->gfx.smenu, tens + 115, PLAYMODE_LOOP);
          MainSprite_SetPose(&p->unk_aa0[1], &p->gfx.smenu, t + 115, PLAYMODE_LOOP);
        }
        FUN_0808b11c(p, tens, t);
      }
    }
  }
  if (p->unk_a99) {
    p->unk_a99--;
  }
}

// value を place の位から順に10進数のタイルとして BG0 の (x, y) から並べる
// 残差は38/38命令でレジスタ番号のみ (value と map が r5/r6 で逆になる)
NON_MATCH void MainMenu_DrawNumber(s32 value, s32 place, u32 x, u32 y, s32 kind) {
#ifdef NONMATCHING_C
  s32 base = 0x31;
  BgMapEntry* map;

  if (kind == 0) {
    base = 0x91;
  }

  map = MainMenu_GetBgMapAddr(0, x, y);
  while (place > 0) {
    s32 digit = Div(value, place);
    BgMapEntry tile = digit + base;

    *map = tile | 0xF000;
    map++;
    value -= place * digit;
    place = Div(place, 10);
  }
#else
  INCFUNC("asm/func/MainMenu_DrawNumber.inc");
#endif
}

void FUN_0808b360(s32 count, u32 x, u32 y) {
  BgMapEntry* entry = MainMenu_GetBgMapAddr(0, x, y);
  s32 i;

  for (i = 0; i < count; i++) {
    *entry++ = 0xF090;
  }
}

// 画面右上に見出しと金額を描く, moneyKind が 0 なら太陽バンク, 1 なら暗黒ローンの返済額, それ以外はソーラースタンド, 9999 で打ち止める
void MainMenu_DrawMoney(MainMenu* p) {
  BgMapEntry* map = MainMenu_GetBgMapAddr(0, 18, 1);
  s32 kind = p->moneyKind;

  if (kind == 0) {
    *map++ = 0xF023;
    *map++ = 0xF022;
    *map++ = 0xF024;
    *map++ = 0xF09B;
    *map++ = 0xF001;
    if (gStat->solarBank > 9999) {
      gStat->solarBank = 9999;
    }
    MainMenu_DrawNumber(gStat->solarBank, 1000, 23, 1, kind);
  } else if (kind == 1) {
    *map++ = 0xF025;
    *map++ = 0xF026;
    *map++ = 0xF022;
    *map++ = 0xF09B;
    *map++ = 0xF030;
    if (gStat->darkDebts > 9999) {
      gStat->darkDebts = 9999;
    }
    MainMenu_DrawNumber(gStat->darkDebts, 1000, 23, 1, kind);
  } else {
    *map++ = 0xF0B9;
    *map++ = 0xF0BA;
    *map++ = 0xF022;
    *map++ = 0xF0BB;
    *map++ = 0xF09B;
    if (gStat->solarStand > 9999) {
      gStat->solarStand = 9999;
    }
    MainMenu_DrawNumber(gStat->solarStand, 1000, 23, 1, 0);
  }
}

// 道具〜防具とステータスのページで画面上部に時刻を描く, moneyKind に合わせて今の時刻 / 日の出 / 日の入りを出し, SELECT+A で表示を切り替える
void MainMenu_DrawClock(MainMenu* p) {
  BgMapEntry* map;
  s32 kind;

  if (!((p->page >= PAGE_ITEM && p->page <= PAGE_ARMOR) || p->page == PAGE_STATS)) {
    return;
  }
  if (p->hidden && (gInput[0].down & SELECT_BUTTON) && (gInput[0].pressed & A_BUTTON)) {
    if (++p->moneyKind > 2) {
      p->moneyKind = 0;
    }
    p->unk_3ae7 = 0;
    PlaySound_082406e0(SE_CURSOR_MOVE);
    MainMenu_DrawMoney(p);
  }
  map = MainMenu_GetBgMapAddr(0, 18, 0);
  kind = p->moneyKind;
  if (kind == 0) {
    *map++ = 0xF020;
    *map++ = 0xF021;
    *map++ = 0xF022;
    MainMenu_DrawNumber(Time_GetHour(), 10, 22, 0, kind);
    MainMenu_DrawNumber(Time_GetMinute(), 10, 25, 0, kind);
  } else if (kind == 1) {
    *map++ = 0xF027;
    *map++ = 0xF028;
    *map++ = 0xF029;
    MainMenu_DrawNumber(gClock.morning.hour, 10, 22, 0, 0);
    MainMenu_DrawNumber(gClock.morning.minute, 10, 25, 0, 0);
  } else {
    *map++ = 0xF027;
    *map++ = 0xF028;
    *map++ = 0xF02A;
    MainMenu_DrawNumber(gClock.sunset.hour, 10, 22, 0, 0);
    MainMenu_DrawNumber(gClock.sunset.minute, 10, 25, 0, 0);
  }
}

// HP/ENE と, 装備中の武器の攻撃力と防具の防御力を並べて描く
void MainMenu_DrawEquipStats(MainMenu* p, s32 x, s32 y) {
  WeaponData wd;

  MainMenu_DrawHPGauge(p, 1, x, y);
  MainMenu_DrawEneGauge(p, 1, x, y + 1);
  GetRegisteredWeaponData(gStat->equippedWeaponIdx, &wd);
  MainMenu_DrawNumber(CalcAttackWithEquippedArmor(&wd), 100, x + 1, y + 2, 0);
  if (gStat->armor < 0) {
    MainMenu_DrawNumber(CalcDefence(NULL), 100, x + 1, y + 3, 0);
  } else {
    MainMenu_DrawNumber(CalcDefence(&gArmorDB[ARMORS(gStat->armor)]), 100, x + 1, y + 3, 0);
  }
}

// 十字キーの入力を返す, 押しっぱなしのときは10フレームごとに1回だけ返す
s32 MainMenu_GetDpadRepeat(MainMenu* p) {
  if (gInput[0].pressed & DPAD_ANY) {
    p->dpadRepeatTimer = 0;
    return gInput[0].pressed;
  }

  if (gInput[0].down & DPAD_ANY) {
    if (++p->dpadRepeatTimer > 9) {
      p->dpadRepeatTimer = 0;
      return gInput[0].down;
    }
  }
  return 0;
}

// はい/いいえ の選択肢を出す, param_2 が 0 以外なら はい を選んだ状態で始める
void MainMenu_ShowYesNo(MainMenu* p, s32 param_2) {
  s32 anim;

  p->sprites[15].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[15].pos.x = 0;
  p->sprites[15].pos.y = 0;
  p->yesNoCursor = param_2;

  anim = (u8)param_2 != 0 ? 4 : 5;
  MainSprite_SetAnim(&p->sprites[15], &p->gfx.smenu, anim, PLAYMODE_LOOP, 0);
  MainSprite_AdvanceAnim(&p->sprites[15], &p->gfx.smenu);
}

// はい/いいえ の選択を進める, A で選んだ側 (1: はい, 0: いいえ), B で 0, 決まっていなければ -1 を返す
// 残差: 79/82 命令, 右キーの判定を原典は u16 に切り詰めてから rsbs/lsrs #31 で 0/1 にするが, こちらはビット抜き出しか分岐になる (TEST_FLAGS, ?:, !!, (u16) キャストは試済)
NON_MATCH s32 MainMenu_UpdateYesNo(MainMenu* p) {
#ifdef NONMATCHING_C
  bool32 move;

  if (gInput[0].pressed & A_BUTTON) {
    p->sprites[15].flags |= SPRFLAG_HIDDEN;
    return p->yesNoCursor;
  }
  if (gInput[0].pressed & B_BUTTON) {
    p->sprites[15].flags |= SPRFLAG_HIDDEN;
    return 0;
  }

  move = FALSE;
  if (p->yesNoCursor) {
    move = (gInput[0].pressed & DPAD_RIGHT) != 0;
  } else if (gInput[0].pressed & DPAD_LEFT) {
    move = TRUE;
  }
  if (move) {
    PlaySound_082406e0(SE_CURSOR_MOVE);
    p->yesNoCursor = 1 - p->yesNoCursor;
    MainSprite_SetAnim(&p->sprites[15], &p->gfx.smenu, 5 - p->yesNoCursor, PLAYMODE_LOOP, 0);
  }
  MainSprite_AdvanceAnim(&p->sprites[15], &p->gfx.smenu);
  return -1;
#else
  INCFUNC("asm/func/MainMenu_UpdateYesNo.inc");
#endif
}

// 116枚のスプライトと2枚の AuxSprite を全部隠す
void FUN_0808b82c(MainMenu* p) {
  s32 i;

  for (i = 0; i < 116; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
  p->sprite_b60.flags |= SPRFLAG_HIDDEN;
  p->stand.flags |= SPRFLAG_HIDDEN;
}

// 現在のページ名を表示する
void MainMenu_ShowPageName(MainMenu* p, s32 page) {
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[0], &p->gfx.smenu, SMENU_PAGE(page), PLAYMODE_LOOP);
}

void FUN_0808b8a4(MainMenu* p) {
  Vec3 pos;
  s32 i;

  pos.x = 144;
  pos.y = 32;
  pos.z = 0;
  for (i = 0; i < 16; i++) {
    p->sprites[17 + i].pos = pos;
    p->sprites[17 + i].pos.x += (i & 3) * 24;
    p->sprites[17 + i].pos.y += (i >> 2) * 24;
  }
}

void FUN_0808b910(MainMenu* p) {
  Vec3 pos;
  s32 i;

  pos.x = 64;
  pos.y = 76;
  pos.z = 0;
  for (i = 0; i < 4; i++) {
    p->sprites[36 + i].pos = pos;
    p->sprites[36 + i].pos.x += (i & 1) * 24;
    p->sprites[36 + i].pos.y += (i >> 1) * 28;
  }
}

void FUN_0808b97c(s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
  s32 i;

  for (i = 0; i < param_4; i++) {
    BgMapEntry* entry = MainMenu_GetBgMapAddr(0, param_1, param_2 + i);
    s32 j;

    for (j = 0; j < param_3; j++) {
      *entry++ = 0xF001;
    }
  }
}

void FUN_0808b9c4(s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
  s32 i;

  for (i = 0; i < param_4; i++) {
    BgMapEntry* entry = MainMenu_GetBgMapAddr(0, param_1, param_2 + i);
    s32 j;

    for (j = 0; j < param_3; j++) {
      *entry++ = 0xF002;
    }
  }
}

void MainSprite_SetPltt(MainSprite* p, u32 plttID) {
  p->plttID = plttID;
  p->pltt = &gObjPlttData[p->plttID * 16];
}

// x と y を目標値へ weight : 1 の比で近づける
void FUN_0808ba20(WorldPos* pos, s16* target, s32 weight) {
  pos->x = Div(pos->x * weight + target[0], weight + 1);
  pos->y = Div(pos->y * weight + target[1], weight + 1);
}

// プレイヤーの状態に応じたパレットIDを返す (毒, カーモス, 通常)
s32 MainMenu_GetPlayerPlttID(MainMenu* p) {
  s32 i;
  if (p->player->badCondTimer[BAD_POISON] != 0) {  // 毒
    i = 2;
  } else {
    i = (KAAMOS(p->player->isSabata) > 0) ? 6 : 0;
  }
  return p->player->plttIDs[i];
}

// プレイヤーの絵を今の姿 (人型, バット, マウス, 棺桶) に合わせて切り替え, 状態に応じたパレットを fadePltt に写して当てる
void MainMenu_RefreshPlayerFigure(MainMenu* p) {
  rgb555* src = &gObjPlttData[MainMenu_GetPlayerPlttID(p) * 16];
  rgb555* dst = p->fadePltt;
  s32 i;

  for (i = 0; i < 16; i++) {
    *dst++ = *src++;
  }
  p->fadeActive = FALSE;
  switch (p->player->kind) {
    case PLAYER_SOLAR_DJANGO: {
      p->sprites[57].flags &= ~SPRFLAG_HIDDEN;
      p->sprite_b60.flags |= SPRFLAG_HIDDEN;
      p->sprites[57].pltt = p->fadePltt;
      MainSprite_SetAnim(&p->sprites[57], &p->gfx.player, 4, PLAYMODE_LOOP, 0);
      break;
    }
    case PLAYER_DARK_DJANGO: {
      p->sprites[57].flags &= ~SPRFLAG_HIDDEN;
      p->sprite_b60.flags |= SPRFLAG_HIDDEN;
      p->sprites[57].pltt = p->fadePltt;
      MainSprite_SetAnim(&p->sprites[57], &p->gfx.player, 203, PLAYMODE_LOOP, 0);
      break;
    }
    case PLAYER_SABATA: {
      p->sprites[57].flags &= ~SPRFLAG_HIDDEN;
      p->sprite_b60.flags |= SPRFLAG_HIDDEN;
      p->sprites[57].pltt = p->fadePltt;
      MainSprite_SetAnim(&p->sprites[57], &p->gfx.player, 418, PLAYMODE_LOOP, 0);
      break;
    }
    case PLAYER_BAT: {
      Video_GetAuxSprite(&p->gfx_b8c, SPRITE_BAT);
      AuxSprite_SetGfx(&p->sprite_b60, &p->gfx_b8c);
      p->sprite_b60.flags &= ~SPRFLAG_HIDDEN;
      p->sprite_b60.pos.y = 96;
      p->sprites[57].flags |= SPRFLAG_HIDDEN;
      p->gfx_b8c.pltt = p->fadePltt;
      AuxAnim_RestartAnim(&p->anim_ba8, p->player->batAnim, 0, 1, 1);
      AuxSprite_AdvanceAnim(&p->sprite_b60, &p->anim_ba8);
      break;
    }
    case PLAYER_MOUSE: {
      Video_GetAuxSprite(&p->gfx_b8c, SPRITE_MOUSE);
      AuxSprite_SetGfx(&p->sprite_b60, &p->gfx_b8c);
      p->sprite_b60.flags &= ~SPRFLAG_HIDDEN;
      p->sprite_b60.pos.y = 112;
      p->sprites[57].flags |= SPRFLAG_HIDDEN;
      p->gfx_b8c.pltt = p->fadePltt;
      AuxAnim_RestartAnim(&p->anim_ba8, p->player->mouseAnim, 0, 4, 0);
      AuxSprite_AdvanceAnim(&p->sprite_b60, &p->anim_ba8);
      break;
    }
    case PLAYER_SLEEPING: {
      Video_GetAuxSprite(&p->gfx_b8c, SPRITE_COFFIN);
      AuxSprite_SetGfx(&p->sprite_b60, &p->gfx_b8c);
      p->sprite_b60.flags &= ~SPRFLAG_HIDDEN;
      p->sprite_b60.pos.y = 96;
      p->sprites[57].flags |= SPRFLAG_HIDDEN;
      p->gfx_b8c.pltt = p->fadePltt;
      if (p->player->coffin == 5) {
        AuxAnim_RestartAnim(&p->anim_ba8, p->player->coffinAnim, p->player->coffin, 4, 0);
      } else {
        AuxAnim_RestartAnim(&p->anim_ba8, p->player->coffinAnim, p->player->coffin, 0, 0);
      }
      AuxSprite_AdvanceAnim(&p->sprite_b60, &p->anim_ba8);
      break;
    }
  }
}

// プレイヤーの絵のアニメを1コマ進める, 人型は MainSprite, 変身中は sprite_b60
void MainMenu_AnimPlayerFigure(MainMenu* p) {
  switch (p->player->kind) {
    case PLAYER_SOLAR_DJANGO:
    case PLAYER_DARK_DJANGO:
    case PLAYER_SABATA: {
      MainSprite_AdvanceAnim(&p->sprites[57], &p->gfx.player);
      break;
    }
    case PLAYER_BAT:
    case PLAYER_MOUSE:
    case PLAYER_SLEEPING: {
      AuxSprite_AdvanceAnim(&p->sprite_b60, &p->anim_ba8);
      break;
    }
  }
}

// OBJ パレットの補間を始める, param_2 の行から param_3 の行へ param_4 フレームかけて fadePltt を動かす
void MainMenu_StartPlttFade(MainMenu* p, u16 param_2, s32 param_3, s32 param_4) {
  rgb555* src;
  rgb555* dst;
  s32 i;

  p->fadeFromPltt = param_2;
  p->fadeToPltt = param_3;
  src = &gObjPlttData[p->fadeFromPltt * 16];
  dst = p->fadePltt;
  for (i = 0; i < 16; i++) {
    *dst++ = *src++;
  }
  p->fadeSteps = param_4;
  p->fadeStep = 0;
  p->fadeActive = TRUE;
}

// fadePltt を fadeFromPltt から fadeToPltt へ1フレームぶん近づける (5 色目と 13 色目は除く), 終わっていれば TRUE
bool32 MainMenu_UpdatePlttFade(MainMenu* p) {
  rgb555* from;
  rgb555* to;
  s32 rest;
  s32 i;

  if (!p->fadeActive) {
    return TRUE;
  }
  from = &gObjPlttData[p->fadeFromPltt * 16];
  to = &gObjPlttData[p->fadeToPltt * 16];
  if (++p->fadeStep >= p->fadeSteps) {
    for (i = 0; i < 16; i++) {
      p->fadePltt[i] = *to++;
    }
    p->fadeActive = 0;
    return TRUE;
  }
  rest = p->fadeSteps - p->fadeStep;
  for (i = 0; i < 16; i++) {
    if (i != 5 && i != 13) {
      s32 r0 = *from & 0x1F;
      s32 g0 = (*from >> 5) & 0x1F;
      s32 b0 = (*from >> 10) & 0x1F;
      s32 r1 = *to & 0x1F;
      s32 g1 = (*to >> 5) & 0x1F;
      s32 b1 = (*to >> 10) & 0x1F;
      s32 r = Div(r0 * rest + r1 * p->fadeStep, p->fadeSteps);
      s32 g = Div(g0 * rest + g1 * p->fadeStep, p->fadeSteps);
      s32 b = Div(b0 * rest + b1 * p->fadeStep, p->fadeSteps);

      p->fadePltt[i] = (b << 10) | (g << 5) | r;
    }
    from++;
    to++;
  }
  return FALSE;
}

// アイコンを from から to へ飛ばすアニメを始める, arc が 0 以外なら進行方向と直交する向きに膨らませる
// 残差: 115/117 命令, 原典は SIN 側の添字で angle に & 0xFF をもう一度かけるが, こちらは angle が 0..255 と分かっているので消える (u8 の angle, Angle_Diff 経由は試済)
NON_MATCH void MainMenu_BeginItemMove(MainMenu* p, s32 idx, s32 pose, s32 pltt, Vec3* from, Vec3* to, s32 arc, s32 duration) {
#ifdef NONMATCHING_C
  MenuItemMove* m = &p->itemMoves[idx];
  MainSprite* sprite;

  m->from = *from;
  m->to = *to;
  if (arc != 0) {
    s32 angle = (ArcTan2_8(to->x - from->x, to->y - from->y) + 64) & 0xFF;

    m->arcX = POLAR_X(arc, angle);
    m->arcY = POLAR_Z(arc, angle);
  } else {
    m->arcX = 0;
    m->arcY = 0;
  }
  sprite = &p->sprites[46 + idx];
  MainSprite_SetPose(sprite, &p->gfx.icons, pose, PLAYMODE_LOOP);
  MainSprite_SetPltt(sprite, pltt);
  sprite->pos = m->from;
  sprite->flags &= ~SPRFLAG_HIDDEN;
  m->timer = 0;
  m->duration = duration;
  m->active = TRUE;
#else
  INCFUNC("asm/func/MainMenu_BeginItemMove.inc");
#endif
}

s32 MainMenu_UpdateItemMove(MainMenu* p, s32 param_2) {
  MainSprite* sprite = &p->sprites[46 + param_2];
  MenuItemMove* m = &p->itemMoves[param_2];

  if (!m->active) {
    return TRUE;
  }
  if (++m->timer >= m->duration) {
    sprite->pos = m->to;
    m->active = FALSE;
    return TRUE;
  } else {
    s32 rest = m->duration - m->timer;

    sprite->pos.x = Div(m->from.x * rest + m->to.x * m->timer, m->duration);
    sprite->pos.y = Div(m->from.y * rest + m->to.y * m->timer, m->duration);
    if (*(s32*)&m->arcX != 0) {
      s32 sin = SIN(Div(m->timer << 7, m->duration));

      sprite->pos.x += FixToInt(12, m->arcX * sin);
      sprite->pos.y += FixToInt(12, m->arcY * sin);
    }
  }
  return FALSE;
}

// 画面下2行のテキストボックスに1行表示する
void MainMenu_ShowBottomLine(u8* pc, s32 line, s32 playSound) {
  if (playSound) {
    PlaySound_082406e0(SE_TEXT_SHOW);
  }

  Marquee_Clear();
  MessageWindow_Start(pc);
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_ShowLine(line);
}

// cursor.flags の bit4/bit5 で sprites[33], [35] の色を切り替え, bit4 のときは sprites[34] を点滅させる
void FUN_0808c548(MainMenu* p) {
  if (p->cursor.flags & 0x10) {
    MainSprite_SetPltt(&p->sprites[33], 735);
    if (p->stateTimer < 30) {
      p->sprites[34].flags &= ~SPRFLAG_HIDDEN;
    } else {
      p->sprites[34].flags |= SPRFLAG_HIDDEN;
    }
    if (++p->stateTimer > 59) {
      p->stateTimer = 0;
    }
  } else {
    MainSprite_SetPltt(&p->sprites[33], 736);
    p->sprites[34].flags |= SPRFLAG_HIDDEN;
  }
  if (p->cursor.flags & 0x20) {
    MainSprite_SetPltt(&p->sprites[35], 735);
  } else {
    MainSprite_SetPltt(&p->sprites[35], 736);
  }
}

// 59番と60番のスプライトを同じ x に, y は8ずらして並べる
void FUN_0808c61c(MainMenu* p, s32 x, s32 y) {
  p->sprites[59].pos.x = x;
  p->sprites[59].pos.y = y;
  p->sprites[60].pos.x = x;
  p->sprites[60].pos.y = y + 8;
}

// ボタン案内のポーズ番号, 0 は Bもどる, 1 以上は A/R の案内
s32 GetButtonGuidePose(s32 param_1) {
  if (param_1 == 0) {
    return 147;
  }
  return 160 + param_1;
}

// 画面下のボタン案内2枠を設定する, 負の値なら隠す
void MainMenu_SetButtonGuides(MainMenu* p, s32 param_2, s32 param_3) {
  if (param_2 < 0) {
    p->sprites[59].flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprites[59].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[59], &p->gfx.smenu, GetButtonGuidePose(param_2), PLAYMODE_LOOP);
  }
  if (param_3 < 0) {
    p->sprites[60].flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprites[60].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[60], &p->gfx.smenu, GetButtonGuidePose(param_3), PLAYMODE_LOOP);
  }
}

void MainMenu_HideButtonGuides(MainMenu* p) { MainMenu_SetButtonGuides(p, -1, -1); }

// 46/46 命令, node->active の読み出しで &node->active をレジスタに持つ形にならない
NON_MATCH s32 FUN_0808c710(struct MMenuPtclNode* param_1, ParticleGroup* param_2) {
#ifdef NONMATCHING_C
  struct MMenuPtclNode* node = param_1;

  if (++node->timer >= 16) {
    node->ptcl.flags |= SPRFLAG_HIDDEN;
    node->active = 0;
  } else {
    Particle_SetPose(&node->ptcl, param_2, (node->timer >> 3) + 2);
    node->ptcl.pos.x += node->velX;
    node->ptcl.pos.y += node->velY;
    if ((node->timer & 7) == 0) {
      node->velY++;
    }
  }

  return node->active;
#else
  INCFUNC("asm/func/FUN_0808c710.inc");
#endif
}

// 粒を放物線で飛ばす, 20フレーム経ったら隠して使い終わりにする
s32 FUN_0808c770(MMenuPtclNode* p) {
  p->timer++;
  if (p->timer > 19) {
    p->ptcl.flags |= SPRFLAG_HIDDEN;
    p->active = 0;
  } else {
    p->ptcl.pos.x += p->velX;
    p->ptcl.pos.y += p->velY;
    if (!(p->timer & 3)) {
      p->velY++;
    }
  }
  return p->active;
}

// 2組のパーティクルを1フレーム進め, 動いている粒が1つもなくなった組は止める
void MainMenu_UpdateParticles(MainMenu* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    MMenuPtclSet* set = &p->ptclSets[i];

    if (set->active) {
      bool8 active = FALSE;
      s32 j;

      for (j = 0; j < 8; j++) {
        MMenuPtclNode* node = &set->nodes[j];

        if (node->active && node->update(node, set->group2)) {
          active = TRUE;
        }
      }
      set->active = active;
    }
  }
}

// ptclSets[idx] の8粒を (x, y) から放射状に少しばらつかせて飛ばす
// 残差: 130/130 命令, ループ前の 0x3FF と gSineTable の読み込み, x と y の読み戻しでレジスタ番号がずれる (node を使わない形, Random() 直書きは試済)
NON_MATCH void UNUSED MainMenu_BurstParticles(MainMenu* p, s32 idx, s32 x, s32 y) {
#ifdef NONMATCHING_C
  MMenuPtclSet* set = &p->ptclSets[idx];
  u16* table;
  s32 i;

  set->group2 = GetParticleGroup(PTCL_GROUP_2);
  set->active = TRUE;
  for (i = 0; i < 8; i++) {
    MMenuPtclNode* node = &set->nodes[i];
    s32 angle;
    s32 speed;

    node->ptcl.flags &= ~SPRFLAG_HIDDEN;
    node->ptcl.pos.x = x;
    node->ptcl.pos.y = y;
    Particle_SetPose(&node->ptcl, set->group2, 0);
    Particle_SetPltt(&node->ptcl, 1);
    table = gRandomTable;
    angle = ((_Random(table) >> 3) & 15) + i * 32 - 8;
    speed = ((_Random(table) >> 3) & 3) + 4;
    node->velX = POLAR_X(speed, angle);
    node->velY = POLAR_Z(speed, angle);
    node->active = TRUE;
    node->timer = 0;
    node->update = FUN_0808c710;
  }
#else
  INCFUNC("asm/func/MainMenu_BurstParticles.inc");
#endif
}

// ptclSets[idx] の8粒を (x, y) のまわりから少し上向きに放射状に飛ばす, 向きはランダムに左右反転する
// 残差: 157/157 命令, 角度の i * 32 を原典は乱数を読んだ直後に r3 へ作り, 足した値の方を cos 側に使うが, こちらは r2 と r3 が逆になる (足す順, (i << 5) は試済)
NON_MATCH void MainMenu_SparkleParticles(MainMenu* p, s32 idx, s32 x, s32 y) {
#ifdef NONMATCHING_C
  MMenuPtclSet* set = &p->ptclSets[idx];
  u16* table;
  s32 i;

  set->group2 = GetParticleGroup(PTCL_GROUP_1);
  set->active = TRUE;
  for (i = 0; i < 8; i++) {
    MMenuPtclNode* node = &set->nodes[i];
    s32 angle;
    s32 speed;

    node->ptcl.flags &= ~SPRFLAG_HIDDEN;
    if (Random() & 1) {
      node->ptcl.flags |= SPRFLAG_XFLIP;
    } else {
      node->ptcl.flags &= ~SPRFLAG_XFLIP;
    }
    Particle_SetPose(&node->ptcl, set->group2, 21);
    Particle_SetPltt(&node->ptcl, 0);
    table = gRandomTable;
    angle = ((_Random(table) >> 3) & 15) + i * 32 - 8;
    speed = ((_Random(table) >> 3) & 1) + 3;
    node->velX = POLAR_X(speed, angle);
    node->velY = POLAR_Z(speed, angle) - 2;
    node->ptcl.pos.x = node->velX + x;
    node->ptcl.pos.y = node->velY + y;
    node->active = TRUE;
    node->timer = 0;
    node->update = (void*)FUN_0808c770;
  }
#else
  INCFUNC("asm/func/MainMenu_SparkleParticles.inc");
#endif
}

// 2組のパーティクルを描画リストから全部外す
void FUN_0808cacc(MainMenu* p) {
  s32 i, j;

  for (i = 0; i < 2; i++) {
    for (j = 0; j < 8; j++) {
      Particle_Remove(&p->ptclSets[i].nodes[j].ptcl);
    }
  }
}

void MainMenu1P_AddParticles(MainMenu* p) {
  s32 i, j;

  for (i = 0; i < 2; i++) {
    MMenuPtclSet* set = &p->ptclSets[i];
    SpriteFlags flags = SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST;
    if (i == 0) flags = SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD;
    set->group2 = GetParticleGroup(PTCL_GROUP_2);
    set->active = 0;
    set->unk_5 = 0;
    for (j = 0; j < 8; j++) {
      Particle_Add(&set->nodes[j].ptcl, set->group2, flags);
      Particle_SetOffset(&set->nodes[j].ptcl, -4, -4);
      set->nodes[j].ptcl.priority = 0;
      set->nodes[j].active = 0;
    }
  }
}

// BG0 の先頭9タイルに 0xA0 からの連番を並べる
void FUN_0808cb90(MainMenu* p) {
  if (!p->unk_a30) {
    BgMapEntry* entry = MainMenu_GetBgMapAddr(0, 0, 0);
    s32 i;
    for (i = 0; i < 9; i++) {
      *entry = BGMAP_BGP13 | (160 + i);
      entry++;
    }
    p->unk_a30 = 1;
  }
}

void FUN_0808cbd8(MainMenu* p) {
  if (p->unk_a30) {
    BgMapEntry* entry = MainMenu_GetBgMapAddr(0, 0, 0);
    s32 i;

    for (i = 0; i < 9; i++) {
      *entry = BGMAP_BGP13;
      entry++;
    }

    p->unk_a30 = 0;
  }
}

void FUN_0808cc14(MainMenu* p) {
  if (p->player->kind != PLAYER_SABATA) {
    if ((s16)gStat->statusPoint >= 1) {
      if (p->unk_a31 < 30) {
        FUN_0808cbd8(p);
      } else {
        FUN_0808cb90(p);
      }
      if (++p->unk_a31 >= 60) {
        p->unk_a31 = 0;
      }
    } else {
      FUN_0808cbd8(p);
    }
  }
}

// 選択中の魔法と武器のアイコンの絵を, 魔法の点滅・エンチャント・武器の破損に合わせて切り替える
void MainMenu_QC_AnimSelectedIcons(MainMenu* p) {
  if (p->player->magic.id >= 0) {
    if (!p->player->magic.availableForm || p->player->magic.unk_285) {
      if (p->qc.magicBlinkTimer == 0) {
        MainSprite_SetPose(&p->qc.magics[p->qc.magicIdx].sprite, &p->gfx.icons, 200, PLAYMODE_LOOP);
      } else if (p->qc.magicBlinkTimer == 30) {
        MainSprite_SetPose(&p->qc.magics[p->qc.magicIdx].sprite, &p->gfx.icons, (s8)p->qc.magics[p->qc.magicIdx].id + 182, PLAYMODE_LOOP);
      }
      if (++p->qc.magicBlinkTimer > 59) {
        p->qc.magicBlinkTimer = 0;
      }
    } else if (p->player->magic.enchanted) {
      if (++p->stateTimer & 1) {
        MainSprite_SetPose(&p->qc.magics[p->qc.magicIdx].sprite, &p->gfx.icons, (s8)p->qc.magics[p->qc.magicIdx].id + 182, PLAYMODE_LOOP);
      } else {
        MainSprite_SetPose(&p->qc.magics[p->qc.magicIdx].sprite, &p->gfx.icons, 201, PLAYMODE_LOOP);
      }
    } else {
      MainSprite_SetPose(&p->qc.magics[p->qc.magicIdx].sprite, &p->gfx.icons, (s8)p->qc.magics[p->qc.magicIdx].id + 182, PLAYMODE_LOOP);
    }
  }
  if (p->qc.weaponCrashTimer) {
    MainSprite_SetPose(&p->qc.weapons[p->qc.weaponIdx].sprite, &p->gfx.icons, 201, PLAYMODE_LOOP);
    p->qc.weaponCrashTimer--;
  } else if (p->qc.weapons[p->qc.weaponIdx].weapon == NULL) {
    MainSprite_SetPose(&p->qc.weapons[p->qc.weaponIdx].sprite, &p->gfx.icons, 0, PLAYMODE_LOOP);
  } else {
    MainSprite_SetPose(&p->qc.weapons[p->qc.weaponIdx].sprite, &p->gfx.icons, p->qc.weapons[p->qc.weaponIdx].weapon->id, PLAYMODE_LOOP);
  }
}

void FUN_0808ce98(MainMenu* p) {
  if (p->player != NULL && p->hudMode != 7 && p->hudMode <= 2) {
    MainMenu_DrawHPGauge(p, 0, 3, 1);
    MainMenu_DrawEneGauge(p, 0, 3, 2);
    MainMenu_DrawSunGauge(p, 0, 9, 18);
    MainMenu_UpdateCondIcon(p);
    if (p->hudMode == 0) {
      MainMenu_DrawEnemyGauge(p);
    } else {
      MainMenu_DrawBossGauge(p, p->hudMode);
    }
    FUN_0808cc14(p);
    MainMenu_QC_AnimSelectedIcons(p);
    MainMenu_UpdateCountdown(p);
  }
}

void FUN_0808cf14(MainMenu* p) {
  if (!(gEntityDisableFlags & ENTITY_DISABLE_0)) {
    FUN_0808ce98(p);
    if (MainMenu_QC_TryOpen(p)) {
      PlaySound_082406e0(SE_SIDEBAR_TOGGLE);
    } else {
      FUN_0809b3b0(p);
    }
  }
}

void FUN_0808cf50(MainMenu* p) { MainSprite_Remove(&p->unk_a34); }

void FUN_0808cf64(MainMenu* p) {
  Vec3 pos;

  if (gGameFlags & GAMEFLAG_CROSSOVER) {
    VEC3_SET(pos, 0, 0, 0);
    MainSprite_Add(&p->unk_a34, &p->gfx.link, LINK_BLOCK_OFF, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_UNK_16, 0, PLAYMODE_PAUSE, 60, &pos);
  } else {
    VEC3_SET(pos, 8, 24, 0);
    MainSprite_Add(&p->unk_a34, &p->gfx.icons, 104, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_UNK_16, 0, PLAYMODE_PAUSE, 60, &pos);
    p->unk_a95 = 0;
  }
}

void FUN_0808cffc(MainMenu* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->unk_aa0[i]);
  }
}

void FUN_0808d01c(MainMenu* p) {
  Vec3 pos;
  s32 i;

  pos.y = 8;
  pos.z = 0;
  for (i = 0; i < 2; i++) {
    pos.x = (i + 14) * 8;
    MainSprite_Add(&p->unk_aa0[i], &p->gfx.smenu, 115, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_UNK_16, 0, PLAYMODE_PAUSE, 60, &pos);
    p->unk_aa0[i].plttID = 0;
    p->unk_aa0[i].pltt = &gObjPlttData[p->unk_aa0[i].plttID * 16];
  }
}

void MainMenu1P_SetupBg(MainMenu* p) {
  p->tm_18 = GetFile(DIR_TILE_MAP, TILEMAP_A413);
  p->worldMapTilemap = GetFile(DIR_TILE_MAP, TILEMAP_A7D7);
  p->dungeonMapTilemap0 = GetFile(DIR_TILE_MAP, TILEMAP_A7E7);
  p->dungeonMapTilemap1 = GetFile(DIR_TILE_MAP, TILEMAP_A7F7);
  p->tm_2c = GetFile(DIR_TILE_MAP, TILEMAP_BANK);
  p->hudMode = 0;
  p->bgp_30 = BgPlttRow13(GetBgPlttFile(BGP_EFDA));
  p->dungeonMapPltt = BgPlttRow13(GetBgPlttFile(BGP_ECBF));
  p->worldMapPltt = BgPlttRow13(GetBgPlttFile(BGP_5F5E));
  p->bgp_3c = BgPlttRow13(GetBgPlttFile(BGP_BANK));
  FUN_0808a3c4(p, p->tm_18, 0, 0, p->bgp_30);
  p->condIconShown = 0;
  p->unk_a2a = 0;
  FUN_0808cf64(p);
  FUN_0808d01c(p);
}

// クイックチェンジのカーソル点滅処理
void MainMenu_QC_PulseCursor(MainMenu* p) {
  u8 t = p->qc.cursorPulseCounter;
  rgb555 color = RGB(31, 0, 0);

  if (t > 9) {
    color = RGB(27, 0, 0);
    if (t > 17) {
      color = RGB(18, 0, 0);
      if (t > 25) {
        color = RGB(10, 0, 0);
        if (t > 33) {
          color = RGB(27, 0, 0);
          if (t <= 41) {
            color = RGB(18, 0, 0);
          }
        }
      }
    }
  }

  p->qc.cursorPulseCounter++;
  if (p->qc.cursorPulseCounter >= 50) {
    p->qc.cursorPulseCounter = 0;
  }
  gBgPlttBuffer[(13 * 16) + 2] = color;  // BGP13.2
}

// 左右のクイックチェンジの枠を BG0 に描き, カーソルの点滅を最初からにする
void MainMenu_QC_DrawFrame(MainMenu* p) {
  const u16* src = u16_ARRAY_085ac064;
  s32 y;
  s32 x;

  for (y = 0; y < 4; y++) {
    BgMapEntry* left = MainMenu_GetBgMapAddr(0, 0, y + 16);
    BgMapEntry* right = MainMenu_GetBgMapAddr(0, 26, y + 16);

    for (x = 0; x < 4; x++) {
      *left++ = *src;
      *right++ = *src;
      src++;
    }
  }

  p->qc.cursorPulseCounter = 0;
  MainMenu_QC_PulseCursor(p);
}

// 画面左右の縁 (x=0 と x=26 から4列ぶん) の4行を空タイルで塗る
void FUN_0808d268(void) {
  s32 y;

  for (y = 0; y < 4; y++) {
    BgMapEntry* left = MainMenu_GetBgMapAddr(0, 0, y + 16);
    BgMapEntry* right = MainMenu_GetBgMapAddr(0, 26, y + 16);
    s32 i;

    for (i = 0; i < 4; i++) {
      *left++ = BGMAP_BGP13;
      *right++ = BGMAP_BGP13;
    }
  }
}

// QC の魔法と武器のアイコンを枠の数だけ出して絵柄を合わせ, 残りの枠は隠す
void MainMenu_QC_RefreshIcons(MainMenu* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (i < p->qc.magicCount) {
      p->qc.magics[i].sprite.flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetPose(&p->qc.magics[i].sprite, &p->gfx.icons, (s8)p->qc.magics[i].id + 182, PLAYMODE_LOOP);
    } else {
      p->qc.magics[i].sprite.flags |= SPRFLAG_HIDDEN;
    }
    if (i < p->qc.weaponCount) {
      p->qc.weapons[i].sprite.flags &= ~SPRFLAG_HIDDEN;
      if (p->qc.weapons[i].weapon == NULL) {
        MainSprite_SetPose(&p->qc.weapons[i].sprite, &p->gfx.icons, 0, PLAYMODE_LOOP);
      } else {
        MainSprite_SetPose(&p->qc.weapons[i].sprite, &p->gfx.icons, p->qc.weapons[i].weapon->id, PLAYMODE_LOOP);
      }
    } else {
      p->qc.weapons[i].sprite.flags |= SPRFLAG_HIDDEN;
    }
  }
}

// QC用のスプライトを非表示にする
void MainMenu_HideQCIcons(MainMenu* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    p->qc.magics[i].sprite.flags |= SPRFLAG_HIDDEN;
    p->qc.weapons[i].sprite.flags |= SPRFLAG_HIDDEN;
  }
}

// QC を閉じているときの表示, 選択中の魔法と武器のアイコンだけを残して他を隠す
void MainMenu_QC_ShowSelectedOnly(MainMenu* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    if (i < p->qc.magicCount && i == p->qc.magicIdx && (s8)p->qc.magics[i].id >= 0) {
      p->qc.magics[i].sprite.flags &= ~SPRFLAG_HIDDEN;
    } else {
      p->qc.magics[i].sprite.flags |= SPRFLAG_HIDDEN;
    }
    if (i < p->qc.weaponCount && i == p->qc.weaponIdx) {
      p->qc.weapons[i].sprite.flags &= ~SPRFLAG_HIDDEN;
    } else {
      p->qc.weapons[i].sprite.flags |= SPRFLAG_HIDDEN;
    }
  }
}

// スクロール位置から行の表示Y座標を出す, 画面外に出たら1周ぶん下へ回す
NON_MATCH s32 MainMenu_CalcQCIconY(MainMenu* p, s32 i, s32 selectedIdx, s32 iconNums, s32 scrollTimer) {
#ifdef NONMATCHING_C
  s32 col = Mod(iconNums + i - selectedIdx, iconNums);
  s32 y = 136 - scrollTimer * 3;

  y -= col * 24;
  if (y < 136 - (iconNums - 1) * 24) {
    y += iconNums * 24;
  }
  return y;
#else
  INCFUNC("asm/func/MainMenu_CalcQCIconY.inc");
#endif
}

// 各武器アイコンの絵柄を装備中の武器に, 縦位置を選択中インデックスからの並び順に合わせる
void MainMenu_RefreshQCWeaponIcons(MainMenu* p) {
  s32 i;

  for (i = 0; i < p->qc.weaponCount; i++) {
    if (p->qc.weapons[i].weapon == NULL) {
      MainSprite_SetPose(&p->qc.weapons[i].sprite, &p->gfx.icons, 0, PLAYMODE_LOOP);
    } else {
      MainSprite_SetPose(&p->qc.weapons[i].sprite, &p->gfx.icons, ICON_WEAPON(p->qc.weapons[i].weapon->id), PLAYMODE_LOOP);
    }
    p->qc.weapons[i].sprite.pos.y = MainMenu_CalcQCIconY(p, i, p->qc.weaponIdx, p->qc.weaponCount, 0);
  }
}

// 各魔法アイコンの絵柄を登録中の魔法に, 縦位置を選択中インデックスからの並び順に合わせる
void MainMenu_RefreshQCMagicIcons(MainMenu* p) {
  s32 i;

  for (i = 0; i < p->qc.magicCount; i++) {
    QCMagicSlot* slot = &p->qc.magics[i];

    MainSprite_SetPose(&slot->sprite, &p->gfx.icons, ICON_MAGIC(slot->id), PLAYMODE_LOOP);
    slot->sprite.pos.y = MainMenu_CalcQCIconY(p, i, p->qc.magicIdx, p->qc.magicCount, 0);
  }
}

// 残差1箇所2命令 (187/187, 同じ命令が同じ順), 原典は &qc.weapons[n] を添字レジスタ r0 に上書きで作るが, こちらは r1 に作って r0 を残す
// Tier A-C 試済 (分岐順の入替, u8+（s8)キャスト, slot ポインタのローカル化, 宣言順, ブロックローカル化)
NON_MATCH void MainMenu_BuildQCWeaponSlots(MainMenu* p) {
#ifdef NONMATCHING_C
  s32 i;
  s32 n = 0;
  bool32 gunAdded;
  QCWeaponSlot* slot;

  p->qc.weaponIdx = -1;
  gunAdded = FALSE;

  if (p->player->kind != PLAYER_SABATA) {
    for (i = 0; i < 4; i++) {
      bool32 add = FALSE;
      Weapon* w = NULL;
      s32 inventorySlotIdx = -1;

      if (REGISTERED_WEAPON(i) >= 0) {
        w = GetWeapon(REGISTERED_WEAPON(i));
        inventorySlotIdx = REGISTERED_WEAPON(i);
        add = TRUE;
      } else {
        bool32 isGunSlot = FALSE;

        if (gGameFlags & GAMEFLAG_CROSSOVER) {
          if (!gunAdded) {
            isGunSlot = TRUE;
          }
        } else if (i == 3) {
          isGunSlot = TRUE;
        }
        if (isGunSlot) {
          w = NULL;
          gunAdded = TRUE;
          add = TRUE;
        }
      }

      if (add) {
        slot = &p->qc.weapons[n];
        slot->registeredIdx = i;
        slot->inventorySlotIdx = inventorySlotIdx;
        slot->weapon = w;
        if (i == gStat->equippedWeaponIdx) {
          p->qc.weaponIdx = n;
        }
        n++;
      }
    }
  } else {
    slot = p->qc.weapons;
    slot->registeredIdx = 3;
    slot->inventorySlotIdx = 0;
    slot->weapon = &p->weapon;
    p->qc.weaponIdx = 0;
    n = 1;
  }

  p->qc.weaponCount = n;
  if (n < 4) {
    slot = &p->qc.weapons[n];
    do {
      slot->registeredIdx |= 0xFF;
      slot->inventorySlotIdx |= 0xFF;
      slot->weapon = NULL;
      slot++;
      n++;
    } while (n < 4);
  }

  if (!(gGameFlags & GAMEFLAG_CROSSOVER) && p->qc.weaponIdx < 0) {
    s32 idx = 0;

    gStat->equippedWeaponIdx = 3;
    slot = p->qc.weapons;
    for (i = 0; i < p->qc.weaponCount; i++) {
      if ((s8)slot->registeredIdx == 3) {
        p->qc.weaponIdx = idx;
        return;
      }
      if ((s8)slot->registeredIdx >= 0) {
        idx++;
      }
      slot++;
    }
  }
#else
  INCFUNC("asm/func/MainMenu_BuildQCWeaponSlots.inc");
#endif
}

NON_MATCH void MainMenu_BuildQCMagicSlots(MainMenu* p) {
#ifdef NONMATCHING_C
  s32 n = 0;
  s32 i;

  p->qc.magicIdx = -1;

  if (p->player->kind != PLAYER_SABATA) {
    p->qc.equippedMagicIdx = &gStat->equippedMagicIdx;
    for (i = 0; i < 4; i++) {
      if (gStat->registeredMagic[i] >= 0) {
        QCMagicSlot* slot = &p->qc.magics[n];

        slot->idx = i;
        slot->id = gStat->registeredMagic[i];
        if (i == *p->qc.equippedMagicIdx) {
          p->qc.magicIdx = n;
        }
        n++;
      }
    }
  } else {
    p->qc.equippedMagicIdx = &gStat->sabataMagicIdx;
    for (i = 0; i < 2; i++) {
      p->qc.magics[n].idx = i;
      p->qc.magics[n].id = (i == 0) ? MAGIC_ZERO_SHIFT : MAGIC_BLACK_SUN;
      if (i == *p->qc.equippedMagicIdx) {
        p->qc.magicIdx = n;
      }
      n++;
    }
  }

  p->qc.magicCount = n;
  while (n < 4) {
    p->qc.magics[n].idx |= 0xFF;
    p->qc.magics[n].id |= 0xFF;
    n++;
  }

  if (p->qc.magicCount != 0 && p->qc.magicIdx < 0) {
    for (i = 1; i < 4; i++) {
      if (gStat->registeredMagic[(*p->qc.equippedMagicIdx + i) & 3] >= 0) {
        s32 j;

        *p->qc.equippedMagicIdx = (*p->qc.equippedMagicIdx + i) & 3;
        for (j = 0; j < 4; j++) {
          if (p->qc.magics[j].idx == *p->qc.equippedMagicIdx) {
            p->qc.magicIdx = j;
          }
        }
        break;
      }
    }
  }
  p->qc.magicBlinkTimer = 0;
#else
  INCFUNC("asm/func/MainMenu_BuildQCMagicSlots.inc");
#endif
}

void FUN_0808d908(MainMenu* p) {
  MainMenu_QC_DrawFrame(p);
  MainMenu_QC_RefreshIcons(p);
  FUN_082408d0();
  SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
  MainMenu_SetUpdateCallback(p, MainMenu_QC_Update);
}

// 選んでいる魔法をプレイヤーに持たせる, 選択なしなら外す
void FUN_0808d93c(MainMenu* p) {
  if (p->qc.magicIdx >= 0 && p->qc.magicCount != 0) {
    Player_EquipMagic(p->player, p->qc.magics[p->qc.magicIdx].id);
  } else {
    Player_EquipMagic(p->player, -1);
  }
}

// 4つめのスプライトが指す武器を Player に適用する
void MainMenu_ApplyWeapon(MainMenu* p) { Player_ApplyWeapon(p->player, p->qc.weapons[p->qc.weaponIdx].weapon); }

// 選んだ武器と魔法を適用してクイックチェンジを閉じる, スタートメニューでの切り替えからは呼ばれない
void MainMenu_QC_Close(MainMenu* p) {
  FUN_0808d268();
  MainMenu_ApplyWeapon(p);
  FUN_0808d93c(p);
  p->qc.magicBlinkTimer = 0;
  MainMenu_QC_ShowSelectedOnly(p);
  FUN_082408f4();
  CLEAR_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
  MainMenu_SetUpdateCallback(p, FUN_0808cf14);
}

// SELECT が押されていて, プレイヤーが操作できる状態で, '.q' で許されていればクイックチェンジを開ける
s32 MainMenu_QC_CanOpen(MainMenu* p) {
  if (gInput[0].down & SELECT_BUTTON) {
    Player* player = p->player;

    if (player != NULL && player->mode == 1 && !(player->flag20 & 1) && p->qc.enabled != 0 && p->hudMode <= 2 && !TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_EVENT | GAMEFLAG_NO_PAUSE)) {
      return TRUE;
    }
  }

  return FALSE;
}

// 開ける状態ならクイックチェンジを開く, 開いたら TRUE
bool32 MainMenu_QC_TryOpen(MainMenu* p) {
  if (MainMenu_QC_CanOpen(p) != 0) {
    FUN_0808d908(p);
    return TRUE;
  }
  return FALSE;
}

// スクロールタイマーを減らしながら魔法と武器のアイコンを縦に動かす
void MainMenu_QC_ScrollIcons(MainMenu* p) {
  s32 i;

  if (p->qc.magicScrollTimer != 0) {
    p->qc.magicScrollTimer--;
    for (i = 0; i < p->qc.magicCount; i++) {
      p->qc.magics[i].sprite.pos.y = MainMenu_CalcQCIconY(p, i, p->qc.magicIdx, p->qc.magicCount, p->qc.magicScrollTimer);
    }
  }
  if (p->qc.weaponScrollTimer != 0) {
    p->qc.weaponScrollTimer--;
    for (i = 0; i < p->qc.weaponCount; i++) {
      p->qc.weapons[i].sprite.pos.y = MainMenu_CalcQCIconY(p, i, p->qc.weaponIdx, p->qc.weaponCount, p->qc.weaponScrollTimer);
    }
  }
}

// クイックチェンジ中の更新, L で魔法, R で武器を回し, SELECT を離すと確定して閉じる
void MainMenu_QC_Update(MainMenu* p) {
  MainMenu_DrawHP(p, 0, 3, 1);
  MainMenu_DrawEne(p, 0, 3, 2);
  if (!(gInput[0].down & SELECT_BUTTON) && p->qc.magicScrollTimer == 0 && p->qc.weaponScrollTimer == 0) {
    MainMenu_QC_Close(p);
  } else {
    if ((gInput[0].pressed & L_BUTTON) && p->qc.magicScrollTimer == 0 && p->qc.magicCount > 1) {
      if (p->player->magic.unk_285) {
        PlaySound_082406e0(SE_NG);
      } else {
        PlaySound_082406e0(SE_QUICK_CHANGE);
        if (++p->qc.magicIdx >= p->qc.magicCount) {
          p->qc.magicIdx = 0;
        }
        *p->qc.equippedMagicIdx = p->qc.magics[p->qc.magicIdx].idx;
        p->qc.magicScrollTimer = 8;
      }
    }
    if ((gInput[0].pressed & R_BUTTON) && p->qc.weaponScrollTimer == 0 && p->qc.weaponCount > 1) {
      s16* equipped;

      PlaySound_082406e0(SE_QUICK_CHANGE);
      if (++p->qc.weaponIdx >= p->qc.weaponCount) {
        p->qc.weaponIdx = 0;
      }
      equipped = &gStat->equippedWeaponIdx;
      *equipped = (s8)p->qc.weapons[p->qc.weaponIdx].registeredIdx;
      p->qc.weaponScrollTimer = 8;
    }
  }
  MainMenu_QC_ScrollIcons(p);
  MainMenu_QC_PulseCursor(p);
}

// クイックチェンジ用のスプライトを追加する (通信対戦では武器を1つしか使えないので、別処理)
void MainMenu1P_AddQCIcons(MainMenu* p) {
  Vec3 posMagic, posWeapon;
  s32 i;

  posMagic.x = 8, posMagic.y = 136, posMagic.z = 0;       // 左下
  posWeapon.x = 216, posWeapon.y = 136, posWeapon.z = 0;  // 右下
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->qc.magics[i].sprite, &p->gfx.icons, ICON_MAGIC(MAGIC_SOL), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_UNK_16, 0, PLAYMODE_PAUSE, 60, &posMagic);
    MainSprite_SetPltt(&p->qc.magics[i].sprite, 1);
    MainSprite_Add(&p->qc.weapons[i].sprite, &p->gfx.icons, ICON_WEAPON(WEAPON_GRADIUS), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_UNK_16, 0, PLAYMODE_PAUSE, 60, &posWeapon);
  }
}

// QC用のスプライトを削除
void MainMenu_RemoveQCIcons(MainMenu* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    MainSprite_Remove(&p->qc.magics[i].sprite);
    MainSprite_Remove(&p->qc.weapons[i].sprite);
  }
}

void MainMenu1P_0808dddc(MainMenu* p) {
  MainMenu1P_AddQCIcons(p);

  if (p->player != NULL) {
    MainMenu_BuildQCWeaponSlots(p);
    MainMenu_BuildQCMagicSlots(p);
    MainMenu_RefreshQCWeaponIcons(p);
    MainMenu_RefreshQCMagicIcons(p);
    if (gGameFlags & GAMEFLAG_CROSSOVER) {
      MainMenu_HideQCIcons(p);
    } else {
      MainMenu_QC_ShowSelectedOnly(p);
    }
  }
}

void FUN_0808de30(MainMenu* p) {
  MainMenu_BuildQCWeaponSlots(p);
  MainMenu_RefreshQCWeaponIcons(p);
  MainMenu_QC_ShowSelectedOnly(p);
  MainMenu_ApplyWeapon(p);
}

void FUN_0808de50(MainMenu* p) {
  MainMenu_BuildQCMagicSlots(p);
  MainMenu_RefreshQCMagicIcons(p);
  MainMenu_QC_ShowSelectedOnly(p);
  FUN_0808d93c(p);
}

// L で魔法, R で武器の QC を1つ回して装備を切り替え, アイコンのスクロールとカーソルの点滅を進める
void MainMenu_QC_UpdateRotate(MainMenu* p) {
  if ((gInput[0].pressed & L_BUTTON) && p->qc.magicScrollTimer == 0 && p->qc.magicCount > 1) {
    PlaySound_082406e0(SE_QUICK_CHANGE);
    if (++p->qc.magicIdx >= p->qc.magicCount) {
      p->qc.magicIdx = 0;
    }
    *p->qc.equippedMagicIdx = p->qc.magics[p->qc.magicIdx].idx;
    p->qc.magicScrollTimer = 8;
  }
  if ((gInput[0].pressed & R_BUTTON) && p->qc.weaponScrollTimer == 0 && p->qc.weaponCount > 1) {
    s16* equipped;

    PlaySound_082406e0(SE_QUICK_CHANGE);
    if (++p->qc.weaponIdx >= p->qc.weaponCount) {
      p->qc.weaponIdx = 0;
    }
    equipped = &gStat->equippedWeaponIdx;
    *equipped = (s8)p->qc.weapons[p->qc.weaponIdx].registeredIdx;
    p->qc.weaponScrollTimer = 8;
  }
  MainMenu_QC_ScrollIcons(p);
  MainMenu_QC_PulseCursor(p);
}

// 選ばれている武器のスプライトだけを見せる
void FUN_0808df7c(MainMenu* p) {
  MainMenu_HideQCIcons(p);
  p->qc.weapons[p->qc.weaponIdx].sprite.flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->qc.weapons[p->qc.weaponIdx].sprite, &p->gfx.icons, 0, PLAYMODE_LOOP);
}

void FUN_0808dfcc(MainMenu* p) {
  if (!(gEntityDisableFlags & ENTITY_DISABLE_0) && p->hudMode <= 2) {
    MainMenu_DrawHPGauge(p, 0, 3, 1);
    MainMenu_QC_ScrollIcons(p);
  }
}

// サイドバーを開いている間の更新, 64 フレームごとに表示を HP と切り替え, START で FUN_0808dfcc へ, SELECT で sprite a34 の絵を切り替える
void FUN_0808e008(MainMenu* p) {
  if (!(gEntityDisableFlags & ENTITY_DISABLE_0) && p->hudMode <= 2) {
    MainMenu_QC_UpdateRotate(p);
    if (p->unk_a16 < 64) {
      MainMenu_DrawHPGauge(p, 0, 3, 1);
    } else {
      MainMenu_DrawHP(p, 0, 3, 1);
    }
    if (++p->unk_a16 > 127) {
      p->unk_a16 = 0;
    }
    if (gInput[0].pressed & START_BUTTON) {
      MainMenu_SetUpdateCallback(p, FUN_0808dfcc);
    } else if (gInput[0].pressed & SELECT_BUTTON) {
      p->unk_9f9 = CrossoverBattle_ToggleBlocking();
      if (p->unk_9f9) {
        MainSprite_SetPose(&p->unk_a34, &p->gfx.link, LINK_BLOCK_ON, PLAYMODE_LOOP);
      } else {
        MainSprite_SetPose(&p->unk_a34, &p->gfx.link, LINK_BLOCK_OFF, PLAYMODE_LOOP);
      }
    }
  }
}

// 0..999 の値を3桁で BG0 に描いて後ろに記号を付ける, 上の桁の 0 は空白にする
void FUN_0808e0e0(MainMenu* p, s32 x, s32 y, s32 value) {
  s32 digits[3];
  bool32 started;
  BgMapEntry* entry;
  s32 i;

  digits[0] = Div(value, 100);
  value -= digits[0] * 100;
  digits[1] = Div(value, 10);
  value -= digits[1] * 10;
  digits[2] = value;
  started = FALSE;
  entry = MainMenu_GetBgMapAddr(0, x, y);
  for (i = 0; i < 3; i++) {
    if (digits[i] > 0) {
      started = TRUE;
      *entry = GetDigitTile(digits[i], 0) | BGMAP_BGP13;
    } else if (started || i == 2) {
      *entry = GetDigitTile(digits[i], 0) | BGMAP_BGP13;
    } else {
      *entry = BGMAP_BGP13;
    }
    entry++;
  }
  *entry = BGMAP_BGP13 | 0x7B;
}

void FUN_0808e17c(MainMenu* p) {
  BgMapEntry* e = MainMenu_GetBgMapAddr(0, 19, 3);

  *e++ = BGMAP_BGP13 | 0x4D;
  e[0] = BGMAP_BGP13 | 0x4E;
  e[1] = BGMAP_BGP13 | 0x5B;
  FUN_0808e0e0(p, 22, 3, CrossoverBattle_GetRivalPlayerHP());
}

void FUN_0808e1b8(MainMenu* p) {
  BgMapEntry* e = MainMenu_GetBgMapAddr(0, 20, 4);

  *e++ = BGMAP_BGP13 | 0x0F;
  e[0] = BGMAP_BGP13 | 0x10;
  e[1] = BGMAP_BGP13 | 0x5B;
  FUN_0808e0e0(p, 23, 4, CrossoverBattle_GetRivalBossHP());
}

// BG0 の (9, 0x11) から2行ぶん 12 タイルを 0xD000 で埋める
void FUN_0808e1f4(MainMenu* p) {
  BgMapEntry* e;
  s32 x, y;

  for (y = 0; y < 2; y++) {
    e = MainMenu_GetBgMapAddr(0, 9, y + 17);

    for (x = 0; x < 12; x++) {
      *e = BGMAP_BGP13;
      e++;
    }
  }
}

// フィールドの HUD を毎フレーム描き直す, ゲージ類と状態アイコン, 装備中の魔法アイコン (使えない形態なら点滅, エンチャント中は明滅) を更新する
void MainMenu_UpdateHud(MainMenu* p) {
  if (p->player == NULL || p->hudMode > 2) {
    return;
  }
  MainMenu_DrawHPGauge(p, 0, 3, 1);
  MainMenu_DrawEneGauge(p, 0, 3, 2);
  FUN_0808e1f4(p);
  MainMenu_UpdateCondIcon(p);
  MainMenu_DrawBossGauge(p, p->hudMode);
  MainMenu_UpdateCountdown(p);
  FUN_0808e17c(p);
  FUN_0808e1b8(p);
  if (p->player->magic.id < 0) {
    return;
  }
  if (!p->player->magic.availableForm) {
    if (p->qc.magicBlinkTimer == 0) {
      MainSprite_SetPose(&p->qc.magics[p->qc.magicIdx].sprite, &p->gfx.icons, 200, PLAYMODE_LOOP);
    } else if (p->qc.magicBlinkTimer == 30) {
      MainSprite_SetPose(&p->qc.magics[p->qc.magicIdx].sprite, &p->gfx.icons, (s8)p->qc.magics[p->qc.magicIdx].id + 182, PLAYMODE_LOOP);
    }
    if (++p->qc.magicBlinkTimer > 59) {
      p->qc.magicBlinkTimer = 0;
    }
  } else if (p->player->magic.enchanted) {
    if (++p->stateTimer & 1) {
      MainSprite_SetPose(&p->qc.magics[p->qc.magicIdx].sprite, &p->gfx.icons, (s8)p->qc.magics[p->qc.magicIdx].id + 182, PLAYMODE_LOOP);
    } else {
      MainSprite_SetPose(&p->qc.magics[p->qc.magicIdx].sprite, &p->gfx.icons, 201, PLAYMODE_LOOP);
    }
  } else {
    MainSprite_SetPose(&p->qc.magics[p->qc.magicIdx].sprite, &p->gfx.icons, (s8)p->qc.magics[p->qc.magicIdx].id + 182, PLAYMODE_LOOP);
  }
}

void FUN_0808e400(MainMenu* p) {
  if (!(gEntityDisableFlags & ENTITY_DISABLE_0)) {
    MainMenu_UpdateHud(p);
  }
}

// gMainMenu があれば QC を描き直し, ENE を満タンにしてサイドバーを開く
void FUN_0808e420(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL) {
    MainMenu_QC_DrawFrame(p);
    MainMenu_BuildQCWeaponSlots(p);
    MainMenu_RefreshQCWeaponIcons(p);
    MainMenu_BuildQCMagicSlots(p);
    MainMenu_RefreshQCMagicIcons(p);
    MainMenu_QC_RefreshIcons(p);
    p->unk_9f9 = 0;
    if (CrossoverBattle_GetBlockCount()) {
      if (!CrossoverBattle_GetRound()) {
        p->unk_a34.flags |= SPRFLAG_HIDDEN;
      } else {
        p->unk_a34.flags &= ~SPRFLAG_HIDDEN;
        MainSprite_SetPose(&p->unk_a34, &p->gfx.link, LINK_BLOCK_OFF, PLAYMODE_LOOP);
      }
    }
    p->player->ene = p->player->maxEne;
    MainMenu_DrawEneGauge(p, 0, 3, 2);
    PlaySound_082406e0(SE_SIDEBAR_TOGGLE);
    p->unk_a16 = 0;
    MainMenu_SetUpdateCallback(p, FUN_0808e008);
  }
}

void FUN_0808e4f4(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL) {
    FUN_0808d268();
    p->unk_a34.flags |= SPRFLAG_HIDDEN;
    MainMenu_ApplyWeapon(p);
    FUN_0808d93c(p);
    MainMenu_QC_ShowSelectedOnly(p);
    MainMenu_SetUpdateCallback(p, FUN_0808e400);
  }
}

void FUN_0808e53c(MainMenu* p) {
  MainSprite* sprite;
  MainSpriteGfx* gfx;
  s32 i;

  for (i = 0; i < 3; i++) {
    p->sprites[104 + i].flags &= ~SPRFLAG_HIDDEN;
  }
  sprite = &p->sprites[104];
  gfx = &p->gfx.loans;
  MainSprite_SetPose(sprite, gfx, p->loanRate + 7, PLAYMODE_LOOP);
  MainSprite_SetPose(&p->sprites[105], gfx, 8, PLAYMODE_LOOP);
  MainSprite_SetPose(&p->sprites[106], gfx, 8, PLAYMODE_LOOP);
}

// 借りるエナジーの量と, それで増える返済額を4桁ずつ数字のスプライトで出す
void MainMenu_DrawLoanAmounts(MainMenu* p) {
  s32 digits[4];
  s32 v;
  s32 i;

  v = p->loanEne;
  if (v == 0) {
    for (i = 0; i < 4; i++) {
      digits[i] = 0;
    }
  } else {
    digits[0] = Div(v, 1000);
    v -= digits[0] * 1000;
    digits[1] = Div(v, 100);
    v -= digits[1] * 100;
    digits[2] = Div(v, 10);
    digits[3] = v - digits[2] * 10;
  }
  for (i = 0; i < 4; i++) {
    p->sprites[107 + i].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[107 + i], &p->gfx.loans, digits[i] + 8, PLAYMODE_LOOP);
  }
  p->sprites[111].flags &= ~SPRFLAG_HIDDEN;

  v = p->loanEne * p->loanRate;
  if (v == 0) {
    for (i = 0; i < 4; i++) {
      digits[i] = 0;
    }
  } else {
    digits[0] = Div(v, 1000);
    v -= digits[0] * 1000;
    digits[1] = Div(v, 100);
    v -= digits[1] * 100;
    digits[2] = Div(v, 10);
    digits[3] = v - digits[2] * 10;
  }
  for (i = 0; i < 4; i++) {
    p->sprites[112 + i].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[112 + i], &p->gfx.loans, digits[i] + 8, PLAYMODE_LOOP);
  }
}

// 今の量を借りたときの返済額 (darkDebts + loanEne * loanRate) を4桁の数字で出す
void MainMenu_DrawLoanDebt(MainMenu* p) {
  Vec3 pos;
  s32 digits[4];
  s32 total;
  s32 i;

  pos.x = 144, pos.y = 40;
  total = gStat->darkDebts + p->loanEne * p->loanRate;
  digits[0] = Div(total, 1000);
  total -= digits[0] * 1000;
  digits[1] = Div(total, 100);
  total -= digits[1] * 100;
  digits[2] = Div(total, 10);
  total -= digits[2] * 10;
  digits[3] = total;
  for (i = 0; i < 4; i++) {
    p->sprites[48 + i].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[48 + i].pos = pos;
    MainSprite_SetPose(&p->sprites[48 + i], &p->gfx.smenu, digits[i] + 20, PLAYMODE_LOOP);
    pos.x += 8;
  }
}

// 借りる量を足したときの EN の位置に EN ゲージ上の目印 (sprites[68]) を動かす
void MainMenu_ShowLoanEneMarker(MainMenu* p) {
  Player* player = p->player;
  s32 ene = player->ene + p->loanEne;
  s32 maxEne = player->maxEne;
  s32 x;

  if (ene == 0) {
    x = 0;
  } else {
    x = Div((ene - 1) * 79, maxEne - 1) + 1;
  }
  p->sprites[68].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[68].pos.x = x - 152;
  p->sprites[68].pos.y = -40;
}

// 太陽スタンドのアニメのタイマーから 0, 1, 2, 1 のコマを返す
s32 GetLoanStandFrame(s32 param_1) {
  switch (param_1 >> 2) {
    case 0: {
      return 0;
    }
    case 1: {
      return 1;
    }
    case 2: {
      return 2;
    }
    case 3: {
      return 1;
    }
  }
  return 0;
}

// 暗黒ローンの借りる量を左右で増減し, 返済額の上限を超えそうなら警告を出す
void MainMenu_UpdateLoanAmount(MainMenu* p) {
  s32 pose;
  s32 pltt;

  if ((gInput[0].down & DPAD_LEFT) && gStat->darkDebts + (p->loanEne + 1) * p->loanRate <= 9999 && p->player->ene + p->loanEne < p->player->maxEne) {
    p->loanEne++;
    PlaySound_082406e0(0x37D);
    MainMenu_ShowLoanEneMarker(p);
    MainMenu_DrawLoanDebt(p);
    MainMenu_DrawLoanAmounts(p);
    p->loanStandPose = 19;
    pltt = GetLoanStandFrame(p->loanStandTimer);
    pose = p->loanStandPose + pltt;
    if (++p->loanStandTimer > 15) {
      p->loanStandTimer = 0;
    }
  } else if ((gInput[0].down & DPAD_RIGHT) && p->loanEne != 0) {
    p->loanEne--;
    PlaySound_082406e0(0x37D);
    MainMenu_ShowLoanEneMarker(p);
    MainMenu_DrawLoanDebt(p);
    MainMenu_DrawLoanAmounts(p);
    p->loanStandPose = 22;
    pltt = GetLoanStandFrame(p->loanStandTimer);
    pose = p->loanStandPose + pltt;
    if (p->loanLimitTimer) {
      p->loanLimitTimer = 1;
    }
    if (++p->loanStandTimer > 15) {
      p->loanStandTimer = 0;
    }
  } else if (p->loanStandTimer) {
    pltt = GetLoanStandFrame(p->loanStandTimer);
    pose = p->loanStandPose + pltt;
    if (++p->loanStandTimer > 15) {
      p->loanStandTimer = 0;
    }
  } else {
    pltt = 0;
    pose = 18;
  }

  if ((gInput[0].down & DPAD_LEFT) && gStat->darkDebts + (p->loanEne + 1) * p->loanRate > 9999) {
    p->loanLimitTimer = 60;
  }
  if (p->loanLimitTimer) {
    if (--p->loanLimitTimer == 0) {
      MainMenu_DrawLoanAmounts(p);
      MessageWindow_ShowLine(4);
      p->loanLimitMsgShown = 0;
    } else {
      s32 i;

      p->sprites[111].flags |= SPRFLAG_HIDDEN;
      for (i = 0; i < 4; i++) {
        p->sprites[107 + i].flags |= SPRFLAG_HIDDEN;
        p->sprites[112 + i].flags |= SPRFLAG_HIDDEN;
      }
      if (p->loanLimitMsgShown == 0) {
        MessageWindow_ShowLine(6);
        p->loanLimitMsgShown = 1;
      }
    }
  }
  MainSprite_SetPose(&p->sprites[103], &p->gfx.loans, pose, PLAYMODE_LOOP);
  Video_SetAuxSpritePltt(&p->standGfx, pltt + 323);
}

void FUN_0808eb4c(MainMenu* p) {
  FUN_0808b82c(p);
  Video_SetBGLayer(0, p->tm_2c, 3);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  p->sprites[100].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[100].pos.x = 0;
  p->sprites[100].pos.y = 0;
  MainSprite_SetAnim(&p->sprites[100], &p->gfx.loans, 7, PLAYMODE_ONCE_AND_STOP, 0);
  FUN_0808e53c(p);
  MainMenu_ShowYesNo(p, 1);
  p->sprites[15].pos.x = -8;
  p->sprites[15].pos.y = -8;
  MessageWindow_ShowLine(1);
  MainMenu_SetUpdateCallback(p, FUN_0808eeac);
}

// タイルマップを読み込み直して、状態関数を FUN_0808ee50 に切り替える
void FUN_0808ee50(MainMenu* p);

void FUN_0808ebe8(MainMenu* p) {
  FUN_0808a3c4(p, p->tm_2c, 0, 3, p->bgp_3c);
  FUN_0808eb4c(p);
  MainMenu_SetUpdateCallback(p, FUN_0808ee50);
}

// 暗黒ローンで借りる量を選ぶ画面を組み立て, 選択の状態へ移る
void MainMenu_BeginLoanSelectAmount(MainMenu* p) {
  s32 i;

  FUN_0808b82c(p);
  Video_SetBGLayer(0, p->tm_2c, 4);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  p->sprites[100].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[100], &p->gfx.loans, 5, PLAYMODE_LOOP, 0);
  p->loanEne = 0;
  MainMenu_DrawLoanDebt(p);
  MainMenu_ShowLoanEneMarker(p);
  p->stand.flags &= ~SPRFLAG_HIDDEN;
  p->sprites[103].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[103].pos.x = 16;
  p->sprites[103].pos.y = -4;
  MainSprite_SetPose(&p->sprites[103], &p->gfx.loans, 18, PLAYMODE_LOOP);
  p->sprites[111].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[111], &p->gfx.loans, p->loanRate + 7, PLAYMODE_LOOP);
  for (i = 0; i < 4; i++) {
    p->sprites[107 + i].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[112 + i].flags &= ~SPRFLAG_HIDDEN;
  }
  MainMenu_DrawLoanAmounts(p);
  p->loanLimitTimer = 0;
  p->loanLimitMsgShown = 0;
  p->loanStandTimer = 0;
  MainSprite_SetPose(&p->sprites[103], &p->gfx.loans, 18, PLAYMODE_LOOP);
  Video_SetAuxSpritePltt(&p->standGfx, 323);
  MessageWindow_ShowLine(4);
  MainMenu_SetUpdateCallback(p, MainMenu_StateLoanSelectAmount);
}

void MainMenu_ShowLoanThanks(MainMenu* p) {
  FUN_0808b82c(p);
  Video_SetBGLayer(0, p->tm_2c, 5);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  p->sprites[100].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[100], &p->gfx.loans, 6, PLAYMODE_ONCE_AND_STOP, 0);
  MessageWindow_ShowLine(3);
  PlaySound_082406e0(VO_ANKO_THANKS);
  MainMenu_SetUpdateCallback(p, MainMenu_StateLoanThanks);
}

void FUN_0808ede4(MainMenu* p) {
  FUN_0808b82c(p);
  FUN_0808a3c4(p, p->tm_2c, 0, 5, p->bgp_3c);
  p->sprites[100].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[100].pos.x = 0;
  p->sprites[100].pos.y = 0;
  MainSprite_SetAnim(&p->sprites[100], &p->gfx.loans, 6, PLAYMODE_ONCE_AND_STOP, 0);
  MessageWindow_ShowLine(13);
  MainMenu_SetUpdateCallback(p, FUN_0808f0d8);
}

// 16フレームかけて画面を暗くし, 終わったら次の状態へ移る
void FUN_0808ee50(MainMenu* p) {
  if (p->updateTimer <= 0xF) {
    SetScreenBrightness(p->updateTimer * 4, 0);
  } else {
    SetScreenBrightness(0x40, 0);
  }

  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);

  if (p->updateTimer++ > 0xF) {
    MainMenu_SetUpdateCallback(p, FUN_0808eeac);
  }
}

void FUN_0808eeac(MainMenu* p) {
  s32 result;

  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);

  result = MainMenu_UpdateYesNo(p);
  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_SetUpdateCallback(p, FUN_0808eef8);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    MainMenu_BeginLoanSelectAmount(p);
  }
}

void MainMenu_ReturnToLoanMenu(MainMenu* p);

// 16フレームかけて画面を明るく戻し, 終わったら次の状態へ移る
void FUN_0808eef8(MainMenu* p) {
  if (p->updateTimer <= 0xF) {
    SetScreenBrightness((0x10 - p->updateTimer) * 4, 0);
  } else {
    SetScreenBrightness(0, 0);
  }

  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);

  if (p->updateTimer++ > 0xF) {
    MainMenu_ReturnToLoanMenu(p);
  }
}

// 借りる量を決める画面, A で借りて返済額を増やし, B で戻る
void MainMenu_StateLoanSelectAmount(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);
  if (gInput[0].pressed & A_BUTTON) {
    if (p->loanEne == 0) {
      PlaySound_082406e0(SE_CANCEL);
    } else {
      u32* debts;
      s32 total;

      p->player->ene += p->loanEne;
      debts = &gStat->darkDebts;
      *debts += p->loanEne * p->loanRate;
      total = gStat->loan_1d4 + p->loanEne * p->loanRate;
      if (total < 0) {
        total = 0x7FFFFFFF;
      }
      gStat->loan_1d4 = total;
      PlaySound_082406e0(SE_SELECT);
    }
    MainMenu_ShowLoanThanks(p);
  } else if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_0808eb4c(p);
  } else {
    MainMenu_UpdateLoanAmount(p);
  }
}

void MainMenu_StateLoanThanks(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);
  if (++p->updateTimer >= 151) {
    if (p->loanEne != 0) {
      MessageWindow_ShowLine(5);
      if (p->scriptID != 0) {
        VM_ExecByID(p->scriptID, NULL);
      } else {
        MessageWindow_SetVarValue(0, 3);
      }
      MainMenu_SetUpdateCallback(p, FUN_0808f09c);
    } else {
      MainMenu_SetUpdateCallback(p, MainMenu_UpdateFadeOut);
    }
  }
}

void FUN_0808f09c(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);

  p->updateTimer++;
  if (p->updateTimer > 149) {
    MainMenu_SetUpdateCallback(p, MainMenu_UpdateFadeOut);
  }
}

// 最初の16フレームで明るくし, 150フレーム目から暗くして次の状態へ移る
void FUN_0808f0d8(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);

  if (p->updateTimer <= 0xF) {
    SetScreenBrightness(p->updateTimer * 4, 0);
  } else if (p->updateTimer <= 133) {
    SetScreenBrightness(0x40, 0);
  } else {
    SetScreenBrightness((150 - p->updateTimer) * 4, 0);
  }

  if (p->updateTimer++ > 149) {
    MainMenu_ReturnToLoanMenu(p);
  }
}

// 太陽ゲージをメニューの表示段階 (2..9) に直す
s32 FUN_0808f140(void) {
  s32 gauge = gStat->sunGauge;

  if (gauge <= 1) {
    return 9;
  }
  if (gauge > 9) {
    return 2;
  }
  return 11 - gauge;
}

void FUN_0808f170(MainMenu* p) {
  MessageWindow_Close();
  Marquee_Clear();
  Marquee_RequestClose();
  MessageWindow_SetRect(1, 15, 28, 4);
  MessageWindow_Start(p->loanTexts);
  MessageWindow_SetInstant(1);
  if (p->unk_401f) {
    FUN_0808ede4(p);
  } else {
    FUN_0808ebe8(p);
  }
}

// loanMenuRow の段階に合わせて2枚のポーズと矢印の高さを決める
void FUN_0808f1bc(MainMenu* p) {
  MainSprite_SetPose(&p->sprites[101], &p->gfx.loans, p->loanMenuRow + 25, PLAYMODE_LOOP);
  MainSprite_SetPose(&p->sprites[102], &p->gfx.loans, 28 - p->loanMenuRow, PLAYMODE_LOOP);
  p->sprites[103].pos.x = 0;
  p->sprites[103].pos.y = p->loanMenuRow << 5;
}

// 暗黒ローンの画面を組み立て, アンコの登場アニメと最初の台詞を出す
void MainMenu_InitLoanScreen(MainMenu* p) {
  MessageWindow_Close();
  Marquee_Clear();
  Marquee_RequestClose();
  MessageWindow_SetRect(1, 1, 28, 6);
  MessageWindow_Start(p->loanTexts);
  MessageWindow_SetInstant(TRUE);
  FUN_0808a3c4(p, p->tm_18, 0, 2, p->bgp_30);
  FUN_0808b82c(p);
  p->sprites[100].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[100].pos.x = -88;
  p->sprites[100].pos.y = 32;
  MainSprite_SetAnim(&p->sprites[100], &p->gfx.loans, 4, PLAYMODE_ONCE_AND_STOP, 0);
  MainSprite_SetPose(&p->sprites[103], &p->gfx.loans, 29, PLAYMODE_LOOP);
  MainSprite_SetAnim(&p->sprites[103], &p->gfx.loans, 10, PLAYMODE_LOOP, 0);
  MessageWindow_ShowLine(0);
  MainMenu_SetUpdateCallback(p, MainMenu_UpdateLoanIntro);
}

// 暗黒ローンの画面を組み直して, 導入を飛ばして2択メニューに戻る
void MainMenu_ReturnToLoanMenu(MainMenu* p) {
  MessageWindow_Close();
  Marquee_Clear();
  Marquee_RequestClose();
  MessageWindow_SetRect(1, 1, 28, 4);
  MessageWindow_Start(p->loanTexts);
  MessageWindow_SetInstant(TRUE);
  FUN_0808a3c4(p, p->tm_18, 0, 2, p->bgp_30);
  FUN_0808b82c(p);
  p->sprites[100].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[100].pos.x = -28;
  p->sprites[100].pos.y = 32;
  MainSprite_SetAnim(&p->sprites[100], &p->gfx.loans, 7, PLAYMODE_ONCE_AND_STOP, 0);
  p->sprites[101].flags &= ~SPRFLAG_HIDDEN;
  if (p->player->kind != PLAYER_SABATA) {
    p->sprites[102].flags &= ~SPRFLAG_HIDDEN;
  }
  p->sprites[103].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[103], &p->gfx.loans, 29, PLAYMODE_LOOP);
  MainSprite_SetAnim(&p->sprites[103], &p->gfx.loans, 10, PLAYMODE_LOOP, 0);
  FUN_0808f1bc(p);
  MessageWindow_ShowLine(7);
  MainMenu_SetUpdateCallback(p, FUN_0808f604);
}

// 暗黒ローンの契約が済んだ場面を出し, お礼の声を鳴らす
void FUN_0808f3f8(MainMenu* p) {
  FUN_0808b82c(p);
  p->sprites[100].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[100].pos.x = -28;
  p->sprites[100].pos.y = 32;
  MainSprite_SetAnim(&p->sprites[100], &p->gfx.loans, 6, PLAYMODE_ONCE_AND_STOP, 0);
  p->sprites[101].flags &= ~SPRFLAG_HIDDEN;
  if (p->player->kind != PLAYER_SABATA) {
    p->sprites[102].flags &= ~SPRFLAG_HIDDEN;
  }
  p->sprites[103].flags &= ~SPRFLAG_HIDDEN;
  PlaySound_082406e0(VO_ANKO_THANKS);
  MessageWindow_ShowLine(3);
  MainMenu_SetUpdateCallback(p, FUN_0808f8bc);
}

void FUN_0808f4ac(MainMenu* p) {
  FUN_0808b82c(p);
  p->sprites[100].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[100].pos.x = -28;
  p->sprites[100].pos.y = 32;
  MainSprite_SetAnim(&p->sprites[100], &p->gfx.loans, 6, PLAYMODE_ONCE_AND_STOP, 0);
  PlaySound_082406e0(VO_ANKO_THANKS);
  MessageWindow_ShowLine(3);
  MainMenu_SetUpdateCallback(p, FUN_0808f774);
}

// 暗黒ローンの導入, 画面を明るくしながらアンコの挨拶を流し, 117 フレームで選択画面へ移る
void MainMenu_UpdateLoanIntro(MainMenu* p) {
  if (p->updateTimer < 16) {
    SetScreenBrightness(p->updateTimer * 4, 0);
  } else {
    SetScreenBrightness(64, 0);
  }
  if (p->updateTimer == 16) {
    PlaySound_082406e0(VO_ANKO_WELCOME);
  }
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);
  if (p->updateTimer > 104) {
    p->sprites[100].pos.x += 5;
  }
  if (++p->updateTimer > 116) {
    MessageWindow_ShowLine(7);
    p->sprites[100].pos.x = -28;
    p->sprites[103].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[101].flags &= ~SPRFLAG_HIDDEN;
    if (p->player->kind != PLAYER_SABATA) {
      p->sprites[102].flags &= ~SPRFLAG_HIDDEN;
    }
    p->loanMenuRow = 0;
    FUN_0808f1bc(p);
    MainMenu_SetUpdateCallback(p, MainMenu_StateLoanMenu);
  }
}

void MainMenu_StateLoanMenu(MainMenu* p);

// 16フレームかけて明るくしてから次の状態へ移る
void FUN_0808f604(MainMenu* p) {
  if (p->updateTimer < 16) {
    SetScreenBrightness(p->updateTimer * 4, 0);
  } else {
    SetScreenBrightness(0x40, 0);
  }

  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);
  MainSprite_AdvanceAnim(&p->sprites[103], &p->gfx.loans);

  p->updateTimer++;
  if (p->updateTimer >= 16) {
    MainMenu_SetUpdateCallback(p, MainMenu_StateLoanMenu);
  }
}

// 暗黒ローンの2択メニュー, 上下で選び A で決定, B で戻る (サバタは上の項目だけ)
void MainMenu_StateLoanMenu(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);
  MainSprite_AdvanceAnim(&p->sprites[103], &p->gfx.loans);
  if (gInput[0].pressed & A_BUTTON) {
    PlaySound_082406e0(SE_SELECT);
    MainSprite_SetPose(&p->sprites[103], &p->gfx.loans, 29, PLAYMODE_LOOP);
    if (p->loanMenuRow == 0) {
      MessageWindow_ShowLine(8);
      MessageWindow_SetVarValue(0, (p->loanRate - 1) * 50);
      MainMenu_ShowYesNo(p, 0);
      p->sprites[15].pos.x = -8;
      p->sprites[15].pos.y = -104;
      MainMenu_SetUpdateCallback(p, FUN_0808f81c);
    } else {
      MainMenu_SetUpdateCallback(p, FUN_0808f7cc);
    }
  } else if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_0808f4ac(p);
  } else if (p->player->kind != PLAYER_SABATA && (gInput[0].pressed & (DPAD_UP | DPAD_DOWN))) {
    PlaySound_082406e0(SE_CURSOR_MOVE);
    p->loanMenuRow = 1 - p->loanMenuRow;
    FUN_0808f1bc(p);
  }
}

void FUN_0808f774(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);
  if (p->sprites[100].pos.x > -88) {
    p->sprites[100].pos.x -= 5;
  }

  p->updateTimer++;
  if (p->updateTimer >= 150) {
    MainMenu_SetUpdateCallback(p, MainMenu_UpdateFadeOut);
  }
}

// 16フレームかけて画面を明るく戻し, 終わったらメッセージへ進む
void FUN_0808f7cc(MainMenu* p) {
  if (p->updateTimer < 16) {
    SetScreenBrightness((16 - p->updateTimer) * 4, 0);
  } else {
    SetScreenBrightness(0, 0);
  }
  p->updateTimer++;
  if (p->updateTimer >= 16) {
    FUN_0808f170(p);
  }
}

// 暗黒ローンの はい/いいえ を待ち, はい なら返済額に (loanRate - 1) * 50 を足して (9999 まで) 閉じたあとのワープを予約する
void FUN_0808f81c(MainMenu* p) {
  s32 result;

  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);

  result = MainMenu_UpdateYesNo(p);
  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    MessageWindow_ShowLine(7);
    MainMenu_SetUpdateCallback(p, MainMenu_StateLoanMenu);
  } else if (result == 1) {
    s32* debts;

    PlaySound_082406e0(SE_SELECT);
    debts = &gStat->darkDebts;
    *debts += (p->loanRate - 1) * 50;
    if (*debts > 9999) {
      gStat->darkDebts = 9999;
    }
    p->pendingWarp = TRUE;
    p->warpKind = 2;
    FUN_0808f3f8(p);
  }
}

void FUN_0808f920(MainMenu* p);

void FUN_0808f8bc(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);

  p->updateTimer++;
  if (p->updateTimer > 149) {
    MessageWindow_ShowLine(5);
    if (p->scriptID != 0) {
      VM_ExecByID(p->scriptID, NULL);
    } else {
      MessageWindow_SetVarValue(0, 3);
    }
    MainMenu_SetUpdateCallback(p, FUN_0808f920);
  }
}

void FUN_0808f920(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx.loans);

  p->updateTimer++;
  if (p->updateTimer > 149) {
    MainMenu_SetUpdateCallback(p, MainMenu_UpdateFadeOut);
  }
}

void MainMenu_OpenLoanScreen(MainMenu* p) {
  p->loanRate = FUN_0808f140();
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
  MainMenu_InitLoanScreen(p);
}

s32 InventoryCursor_GetSlot(InventoryCursor* p) { return (s8)INVENTORY_SLOT(p, p->colX, p->rowY); }

// 十字キーの入力を返す, 押しっぱなしのときは10フレームごとに1回だけ返す
s32 InventoryCursor_ReadDpad(InventoryCursor* p) {
  if (gInput[0].pressed & DPAD_ANY) {
    p->repeatTimer = 0;
    return gInput[0].pressed;
  }

  if (gInput[0].down & DPAD_ANY) {
    p->repeatTimer++;
    if (p->repeatTimer > 9) {
      p->repeatTimer = 0;
      return gInput[0].down;
    }
  } else {
    p->repeatTimer = 0;
  }
  return 0;
}

// カーソルを1行上に
s32 InventoryCursor_MoveUp(InventoryCursor* p) {
  s32 cur = (s8)INVENTORY_SLOT(p, p->colX, p->rowY);
  u8 rowY = (p->rowY + 3) & 3;

  while (rowY != p->rowY) {
    s32 slot = (s8)INVENTORY_SLOT(p, p->colX, rowY);

    if (slot >= 0 && slot != cur) {
      p->rowY = rowY;
      p->slot = InventoryCursor_GetSlot(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
      return 1;
    }
    rowY = (rowY + 3) & 3;
  }
  return 0;
}

// 同じ行を右へ辿って別のスロットへカーソルを移す
s32 InventoryCursor_MoveDown(InventoryCursor* p) {
  s32 cur = (s8)INVENTORY_SLOT(p, p->colX, p->rowY);
  u8 rowY = (p->rowY + 1) & 3;

  while (rowY != p->rowY) {
    s32 slot = (s8)INVENTORY_SLOT(p, p->colX, rowY);

    if (slot >= 0 && slot != cur) {
      p->rowY = rowY;
      p->slot = InventoryCursor_GetSlot(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
      return 1;
    }
    rowY = (rowY + 1) & 3;
  }
  return 0;
}

// 同じ列を上へ辿って別のスロットへカーソルを移す
s32 InventoryCursor_MoveLeft(InventoryCursor* p) {
  s32 orig = p->colX;
  s32 cur = (s8)INVENTORY_SLOT(p, orig, p->rowY);
  s32 colX = orig - 1;

  if (orig == 0) {
    colX = 8;
  }

  while (colX != orig) {
    s32 slot = (s8)INVENTORY_SLOT(p, colX, p->rowY);

    if (slot >= 0 && slot != cur) {
      p->colX = colX;
      p->slot = InventoryCursor_GetSlot(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
      return 1;
    }
    if (colX == 0) {
      colX = 8;
    } else {
      colX--;
    }
  }
  return 0;
}

// 同じ列を下へ辿って別のスロットへカーソルを移す
s32 InventoryCursor_MoveRight(InventoryCursor* p) {
  s32 orig = p->colX;
  s32 cur = (s8)INVENTORY_SLOT(p, orig, p->rowY);
  s32 colX = orig + 1;

  if (orig == 8) {
    colX = 0;
  }

  while (colX != orig) {
    s32 slot = (s8)INVENTORY_SLOT(p, colX, p->rowY);

    if (slot >= 0 && slot != cur) {
      p->colX = colX;
      p->slot = InventoryCursor_GetSlot(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
      return 1;
    }
    if (colX == 8) {
      colX = 0;
    } else {
      colX++;
    }
  }
  return 0;
}

// 押された方向キーに応じてカーソル移動を振り分ける
s32 InventoryCursor_Move(InventoryCursor* p) {
  s32 keys = InventoryCursor_ReadDpad(p);

  if (keys & DPAD_UP) return InventoryCursor_MoveUp(p);
  if (keys & DPAD_DOWN) return InventoryCursor_MoveDown(p);
  if (keys & DPAD_LEFT) return InventoryCursor_MoveLeft(p);
  if (keys & DPAD_RIGHT) return InventoryCursor_MoveRight(p);
  return 0;
}

// カーソルの位置を退避する, FUN_080b9fd8 と同じ実装
void InventoryCursor_SavePos(InventoryCursor* p) {
  p->savedCol = p->colX;
  p->savedRow = p->rowY;
  p->savedSlot = p->slot;
}

// 退避したカーソルの位置を戻す, FUN_080b9fe8 と同じ実装
void InventoryCursor_RestorePos(InventoryCursor* p) {
  p->colX = p->savedCol;
  p->rowY = p->savedRow;
  p->slot = p->savedSlot;
}

// カーソルを指定の行と列へ動かしてスロット番号を引き直す
void InventoryCursor_SetPos(InventoryCursor* p, u32 x, u32 y) {
  p->colX = x;
  p->rowY = y;
  p->slot = InventoryCursor_GetSlot(p);
  p->repeatTimer = 0;
}

void MainMenu_ShowMapScreenName(MainMenu* p) { MessageWindow_ShowLine(p->mapScreens[p->mapScreen].nameLine); }

// データデカすぎてファイルが読みにくいので一時退避
#include "data/menu.h"

// GetCurrentMapNameLine / MainMenu_InitPage_Map が stageID で引く
const MapScreen* const sMapScreenTables[15] = {
    sTaniMapScreens,
    sCathedralMapScreens,
    sIsekiMapScreens,
    sDarkCityMapScreens,
    sAqueductMapScreens,
    sRasenMapScreens,
    sHenMapScreens,
    sHaikyoMapScreens,
    sArenaMapScreens,
    sForestMapScreens,
    sBotiMapScreens,
    sTimeHouseMapScreens,
    sTreasuryMapScreens,
    sMugenMapScreens,
    sPdBattleMapScreens,
};  // 0x085ACEC8

// GetCurrentMapNameLine / MainMenu_InitPage_Map が stageID で引く, [ST_PD_BATTLE] だけ sWorldMapStages を指していて, 先頭の1件が {0, 0, 0} として読める
const MapSpot* const sMapSpotTables[15] = {
    sTaniMapSpots,
    sCathedralMapSpots,
    sIsekiMapSpots,
    sDarkCityMapSpots,
    sAqueductMapSpots,
    sRasenMapSpots,
    sHenMapSpots,
    sHaikyoMapSpots,
    sArenaMapSpots,
    sForestMapSpots,
    sBotiMapSpots,
    sTimeHouseMapSpots,
    sTreasuryMapSpots,
    sMugenMapSpots,
    (const MapSpot*)sWorldMapStages,
};  // 0x085ACF04

// 現在のステージと '.f' の組からメッセージの行番号を引く
s32 GetCurrentMapNameLine(void) {
  if (gStat->stageID > ST_PD_BATTLE) {
    return gStat->stageID + 0x40;
  }
  {
    const MapScreen* screens = sMapScreenTables[gStat->stageID];
    const MapSpot* spots = sMapSpotTables[gStat->stageID];

    return screens[spots[gStat->mapSpot].screen].nameLine;
  }
}

// 0x82B3
void Cmd_SetStageID(void) {
  if (VM_SeekToNamedArg('s')) {
    gStat->stageID = VM_GetValue();
  }
}

// 0x515D
void Cmd_SetMapSpot(void) {
  if (VM_SeekToNamedArg('f')) {
    gStat->mapSpot = VM_GetValue();
  }
}

// 0x9817
void Cmd_SetCoffinStage(void) {
  if (VM_SeekToNamedArg('s')) {
    gStat->coffinStageID = VM_GetValue();
  }
}

// 0xAA62
void Cmd_SetCoffinMapSpot(void) {
  if (VM_SeekToNamedArg('f')) {
    gStat->coffinMapSpot = VM_GetValue();
  }
}

// 0x54C1, HashName("マップ取得"), VM の i 引数で指定された地図を解放済みにする
void UnlockMap(void) {
  if (VM_SeekToNamedArg('i')) {
    gStat->unlockedMap |= 1 << VM_GetValue();
  }
}

// 地図を取得しているか
u32 IsMapUnlocked(u32 mapIdx) { return gStat->unlockedMap & (1 << mapIdx); }

// 0x7CE7, '.s' のエリア (なければ現在のエリア) のマップアイコンのフラグを返す
s32 Cmd_GetMapIconFlags(void) {
  if (VM_SeekToNamedArg('s')) {
    s32 i = VM_GetValue();

    return MAP_ICON_FLAGS(i);
  }
  return MAP_ICON_FLAGS(gStat->stageID);
}

// 0xA995, '.s' のエリア (なければ現在のエリア) のマップアイコンのフラグを全部落とす
void Cmd_ClearMapIconFlags(void) {
  s32 idx;

  if (VM_SeekToNamedArg('s')) {
    idx = VM_GetValue();
  } else {
    idx = gStat->stageID;
  }

  MAP_ICON_FLAGS(idx) = 0;
}

// 0x0C1B, '.s' のエリア (なければ現在のエリア) のフラグから '.i' のビットを立てる
void Cmd_SetMapIconFlag(void) {
  s32 idx;

  if (VM_SeekToNamedArg('s')) {
    idx = VM_GetValue();
  } else {
    idx = gStat->stageID;
  }

  if (VM_SeekToNamedArg('i')) {
    MAP_ICON_FLAGS(idx) |= 1 << VM_GetValue();
  }
}

// 0x0BFD, '.s' のエリア (なければ現在のエリア) のフラグから '.i' のビットを落とす
void Cmd_ClearMapIconFlag(void) {
  s32 idx;

  if (VM_SeekToNamedArg('s')) {
    idx = VM_GetValue();
  } else {
    idx = gStat->stageID;
  }

  if (VM_SeekToNamedArg('i')) {
    MAP_ICON_FLAGS(idx) &= ~(1 << VM_GetValue());
  }
}

u32 MapIcon_GetType(u32 param_1) { return param_1 & 0xF; }

s32 MapIcon_GetPltt(s32 param_1) { return param_1 >> 4; }

// 表示中の画面にあるマップアイコンのうちフラグの立っているものを BG1 に描く
// 残差: 102/102 命令, 最後の orrs で原典は tile 側のレジスタに結果を作り, プール定数も 0xFFFFE400 / 0xFFFFE000 と符号付きになっている (被演算子の順, if/else と |=, tile を s16 は試済)
NON_MATCH void MainMenu_DrawMapIcons(MainMenu* p, s32 param_2, s32 param_3) {
#ifdef NONMATCHING_C
  s32 i;

  if (p->mapIcons == NULL) {
    return;
  }
  for (i = 0; i < 32; i++) {
    const MapIcon* icon = &p->mapIcons[i];
    s32 type = MapIcon_GetType(icon->kind);

    if (type == 0) {
      break;
    }
    if (icon->screen == p->mapScreen && ((MAP_ICON_FLAGS(gStat->stageID) >> i) & 1)) {
      s32 x = icon->x;
      s32 y = icon->y;

      if (x >= param_2 && x < param_2 + 32 && y >= param_3 && y < param_3 + 32) {
        BgMapEntry* map;
        s32 tile = 0;

        switch (type) {
          case 1: {
            tile = 13;
            break;
          }
          case 2: {
            tile = 15;
            break;
          }
          case 3: {
            tile = 1;
            break;
          }
          case 4: {
            tile = 1;
            break;
          }
          case 5: {
            tile = 1;
            break;
          }
        }
        map = MainMenu_GetBgMapAddr(1, x, y);
        *map = tile | (MapIcon_GetPltt(icon->kind) ? 0xE400 : 0xE000);
      }
    }
  }
#else
  INCFUNC("asm/func/MainMenu_DrawMapIcons.inc");
#endif
}

void MainMenu_SetupMapScroll(MainMenu* p) {
  p->mapScrollMinX = 0;
  p->mapScrollMinY = 0;
  p->mapScrollMaxX = (p->mapScreens[p->mapScreen].width - 30) * 8;
  p->mapScrollMaxY = (p->mapScreens[p->mapScreen].height - 20) * 8;
  p->mapOriginX = p->mapScreens[p->mapScreen].originX * 8;
  p->mapOriginY = p->mapScreens[p->mapScreen].originY * 8;
}

void MainMenu_HideScrollArrows(MainMenu* p) {
  p->sprites[78].flags |= SPRFLAG_HIDDEN;
  p->sprites[79].flags |= SPRFLAG_HIDDEN;
  p->sprites[80].flags |= SPRFLAG_HIDDEN;
  p->sprites[81].flags |= SPRFLAG_HIDDEN;
}

void MainMenu_ClampMapScroll(MainMenu* p) {
  p->sprites[78].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[79].flags &= ~SPRFLAG_HIDDEN;
  if (p->mapScrollX <= p->mapScrollMinX) {
    p->mapScrollX = p->mapScrollMinX;
    p->sprites[78].flags |= SPRFLAG_HIDDEN;
  } else if (p->mapScrollX >= p->mapScrollMaxX) {
    p->mapScrollX = p->mapScrollMaxX;
    p->sprites[79].flags |= SPRFLAG_HIDDEN;
  }

  p->sprites[80].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[81].flags &= ~SPRFLAG_HIDDEN;
  if (p->mapScrollY <= p->mapScrollMinY) {
    p->sprites[80].flags |= SPRFLAG_HIDDEN;
    p->mapScrollY = p->mapScrollMinY;
  } else if (p->mapScrollY >= p->mapScrollMaxY) {
    p->sprites[81].flags |= SPRFLAG_HIDDEN;
    p->mapScrollY = p->mapScrollMaxY;
  }
}

void MainMenu_AnimScrollArrows(MainMenu* p) {
  MainSprite* spr = &p->sprites[78];
  s32 i;

  for (i = 0; i < 4; i++) {
    MainSprite_AdvanceAnim(spr, &p->gfx.map);
    spr++;
  }
}

// 表示中の画面から行ける上下左右の画面を mapArrows に入れて矢印を出す, 地図のない画面では地図なし用のつながりを1方向だけ見る
void MainMenu_UpdateMapArrows(MainMenu* p) {
  const MapScreen* screen;

  p->sprites[82].flags |= SPRFLAG_HIDDEN;
  p->sprites[83].flags |= SPRFLAG_HIDDEN;
  p->sprites[84].flags |= SPRFLAG_HIDDEN;
  p->sprites[85].flags |= SPRFLAG_HIDDEN;
  p->mapArrows[0] = -1;
  p->mapArrows[1] = -1;
  p->mapArrows[2] = -1;
  p->mapArrows[3] = -1;
  screen = &p->mapScreens[p->mapScreen];
  if (p->mapVisible) {
    if (screen->links[0] != -1) {
      if (IsMapUnlocked(p->mapScreens[screen->links[0]].mapID)) {
        p->mapArrows[0] = screen->links[0];
        p->sprites[82].flags &= ~SPRFLAG_HIDDEN;
        if (screen->unk_0a & 1) {
          p->sprites[82].flags &= ~SPRFLAG_BLINK_ODD;
        } else {
          p->sprites[82].flags |= SPRFLAG_BLINK_ODD;
        }
      } else if (p->mapScreen != p->playerScreen && p->mapScreens[screen->links[0]].mapID == p->mapScreens[p->playerScreen].mapID) {
        p->mapArrows[0] = p->playerScreen;
        p->sprites[82].flags &= ~SPRFLAG_HIDDEN;
        if (screen->links[0] == p->playerScreen) {
          p->sprites[82].flags &= ~SPRFLAG_BLINK_ODD;
        } else {
          p->sprites[82].flags |= SPRFLAG_BLINK_ODD;
        }
      }
    }
    if (screen->links[1] != -1) {
      if (IsMapUnlocked(p->mapScreens[screen->links[1]].mapID)) {
        p->mapArrows[1] = screen->links[1];
        p->sprites[83].flags &= ~SPRFLAG_HIDDEN;
        if (screen->unk_0a & 2) {
          p->sprites[83].flags &= ~SPRFLAG_BLINK_ODD;
        } else {
          p->sprites[83].flags |= SPRFLAG_BLINK_ODD;
        }
      } else if (p->mapScreen != p->playerScreen && p->mapScreens[screen->links[1]].mapID == p->mapScreens[p->playerScreen].mapID) {
        p->mapArrows[1] = p->playerScreen;
        p->sprites[83].flags &= ~SPRFLAG_HIDDEN;
        if (screen->links[1] == p->playerScreen) {
          p->sprites[83].flags &= ~SPRFLAG_BLINK_ODD;
        } else {
          p->sprites[83].flags |= SPRFLAG_BLINK_ODD;
        }
      }
    }
    if (screen->links[2] != -1) {
      if (IsMapUnlocked(p->mapScreens[screen->links[2]].mapID)) {
        p->mapArrows[2] = screen->links[2];
        p->sprites[84].flags &= ~SPRFLAG_HIDDEN;
        if (screen->unk_0a & 4) {
          p->sprites[84].flags &= ~SPRFLAG_BLINK_ODD;
        } else {
          p->sprites[84].flags |= SPRFLAG_BLINK_ODD;
        }
      } else if (p->mapScreen != p->playerScreen && p->mapScreens[screen->links[2]].mapID == p->mapScreens[p->playerScreen].mapID) {
        p->mapArrows[2] = p->playerScreen;
        p->sprites[84].flags &= ~SPRFLAG_HIDDEN;
        if (screen->links[2] == p->playerScreen) {
          p->sprites[84].flags &= ~SPRFLAG_BLINK_ODD;
        } else {
          p->sprites[84].flags |= SPRFLAG_BLINK_ODD;
        }
      }
    }
    if (screen->links[3] != -1) {
      if (IsMapUnlocked(p->mapScreens[screen->links[3]].mapID)) {
        p->mapArrows[3] = screen->links[3];
        p->sprites[85].flags &= ~SPRFLAG_HIDDEN;
        if (screen->unk_0a & 8) {
          p->sprites[85].flags &= ~SPRFLAG_BLINK_ODD;
        } else {
          p->sprites[85].flags |= SPRFLAG_BLINK_ODD;
        }
      } else if (p->mapScreen != p->playerScreen && p->mapScreens[screen->links[3]].mapID == p->mapScreens[p->playerScreen].mapID) {
        p->mapArrows[3] = p->playerScreen;
        p->sprites[85].flags &= ~SPRFLAG_HIDDEN;
        if (screen->links[3] == p->playerScreen) {
          p->sprites[85].flags &= ~SPRFLAG_BLINK_ODD;
        } else {
          p->sprites[85].flags |= SPRFLAG_BLINK_ODD;
        }
      }
    }
  } else if (screen->linksNoMap[0] != -1) {
    if (IsMapUnlocked(p->mapScreens[screen->linksNoMap[0]].mapID)) {
      p->mapArrows[0] = screen->linksNoMap[0];
      p->sprites[82].flags &= ~SPRFLAG_HIDDEN;
      if ((screen->unk_0a & 1) && screen->links[0] == screen->linksNoMap[0]) {
        p->sprites[82].flags &= ~SPRFLAG_BLINK_ODD;
      } else {
        p->sprites[82].flags |= SPRFLAG_BLINK_ODD;
      }
    }
  } else if (screen->linksNoMap[1] != -1) {
    if (IsMapUnlocked(p->mapScreens[screen->linksNoMap[1]].mapID)) {
      p->mapArrows[1] = screen->linksNoMap[1];
      p->sprites[83].flags &= ~SPRFLAG_HIDDEN;
      if ((screen->unk_0a & 2) && screen->links[1] == screen->linksNoMap[1]) {
        p->sprites[83].flags &= ~SPRFLAG_BLINK_ODD;
      } else {
        p->sprites[83].flags |= SPRFLAG_BLINK_ODD;
      }
    }
  } else if (screen->linksNoMap[2] != -1) {
    if (IsMapUnlocked(p->mapScreens[screen->linksNoMap[2]].mapID)) {
      p->mapArrows[2] = screen->linksNoMap[2];
      p->sprites[84].flags &= ~SPRFLAG_HIDDEN;
      if ((screen->unk_0a & 4) && screen->links[2] == screen->linksNoMap[2]) {
        p->sprites[84].flags &= ~SPRFLAG_BLINK_ODD;
      } else {
        p->sprites[84].flags |= SPRFLAG_BLINK_ODD;
      }
    }
  } else if (screen->linksNoMap[3] != -1) {
    if (IsMapUnlocked(p->mapScreens[screen->linksNoMap[3]].mapID)) {
      p->mapArrows[3] = screen->linksNoMap[3];
      p->sprites[85].flags &= ~SPRFLAG_HIDDEN;
      if ((screen->unk_0a & 8) && screen->links[3] == screen->linksNoMap[3]) {
        p->sprites[85].flags &= ~SPRFLAG_BLINK_ODD;
      } else {
        p->sprites[85].flags |= SPRFLAG_BLINK_ODD;
      }
    }
  }
}

// BG1 のタイルマップ全面を 0xE002 で埋める
void MainMenu_FillBG1(MainMenu* p) {
  s32 x, y;

  for (y = 0; y < 32; y++) {
    for (x = 0; x < 32; x++) {
      *MainMenu_GetBgMapAddr(1, x, y) = 0xE002;
    }
  }
}

void MainMenu_RefreshMapScreen(MainMenu* p) {
  if (p->mapVisible == TRUE) {
    Video_SetBGLayer(1, p->mapTilemap, p->mapScreens[p->mapScreen].bgLayer);
    MainMenu_SetupMapScroll(p);
    MainMenu_UpdateMapArrows(p);
  } else {
    MainMenu_FillBG1(p);
    MainMenu_HideScrollArrows(p);
    MainMenu_UpdateMapArrows(p);
  }
}

bool32 MainMenu_MoveMapScreen(MainMenu* p) {
  const MapScreen* screens = p->mapScreens;
  s32 next = -1;

  if (gInput[0].pressed & DPAD_UP) {
    if (p->mapArrows[0] != -1) {
      next = p->mapArrows[0];
      if (IsMapUnlocked(screens[next].mapID)) {
        p->mapVisible = TRUE;
      } else {
        p->mapVisible = FALSE;
      }
    }
  } else if (gInput[0].pressed & DPAD_DOWN) {
    if (p->mapArrows[1] != -1) {
      next = p->mapArrows[1];
      if (IsMapUnlocked(screens[next].mapID)) {
        p->mapVisible = TRUE;
      } else {
        p->mapVisible = FALSE;
      }
    }
  } else if (gInput[0].pressed & DPAD_LEFT) {
    if (p->mapArrows[2] != -1) {
      next = p->mapArrows[2];
      if (IsMapUnlocked(screens[next].mapID)) {
        p->mapVisible = TRUE;
      } else {
        p->mapVisible = FALSE;
      }
    }
  } else if (gInput[0].pressed & DPAD_RIGHT) {
    if (p->mapArrows[3] != -1) {
      next = p->mapArrows[3];
      if (IsMapUnlocked(screens[next].mapID)) {
        p->mapVisible = TRUE;
      } else {
        p->mapVisible = FALSE;
      }
    }
  }

  if (next >= 0) {
    p->mapScreen = next;
    MainMenu_RefreshMapScreen(p);
    return TRUE;
  }
  return FALSE;
}

void MainMenu_UpdateDungeonMap(MainMenu* p) {
  bool32 moved = FALSE;

  if (gInput[0].down & A_BUTTON) {
    moved = MainMenu_MoveMapScreen(p);
    if (moved) {
      PlaySound_082406e0(SE_CURSOR_MOVE);
      if (p->mapScreen == p->playerScreen) {
        p->sprites[76].flags &= ~SPRFLAG_HIDDEN;
      } else {
        p->sprites[76].flags |= SPRFLAG_HIDDEN;
      }
      if (p->mapScreen == p->coffinScreen) {
        p->sprites[77].flags &= ~SPRFLAG_HIDDEN;
      } else {
        p->sprites[77].flags |= SPRFLAG_HIDDEN;
      }
      MainMenu_ShowMapScreenName(p);
    }
  } else {
    if (p->mapVisible) {
      if (gInput[0].down & DPAD_LEFT) {
        p->mapScrollX -= 2;
        moved = TRUE;
      } else if (gInput[0].down & DPAD_RIGHT) {
        p->mapScrollX += 2;
        moved = TRUE;
      }
      if (gInput[0].down & DPAD_UP) {
        p->mapScrollY -= 2;
        moved = TRUE;
      } else if (gInput[0].down & DPAD_DOWN) {
        p->mapScrollY += 2;
        moved = TRUE;
      }
    }
  }
  if (p->mapVisible && moved) {
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    MainMenu_ClampMapScroll(p);
    dx = p->mapScrollX - p->mapOriginX;
    dy = p->mapScrollY - p->mapOriginY;
    x = dx >> 3;
    y = (dy >> 3) & ~1;
    Video_GenerateBGMap(1, x, y, dx, dy);
    MainMenu_DrawMapIcons(p, x, y);
    if (!(p->sprites[76].flags & SPRFLAG_HIDDEN)) {
      p->sprites[76].pos.x = p->playerMapX - dx;
      p->sprites[76].pos.y = p->playerMapY - dy;
    }
    if (!(p->sprites[77].flags & SPRFLAG_HIDDEN)) {
      p->sprites[77].pos.x = p->coffinMapX - dx;
      p->sprites[77].pos.y = p->coffinMapY - dy;
    }
  }
  MainMenu_AnimScrollArrows(p);
}

void MainMenu_LoadMapMarkers(MainMenu* p) {
  p->playerScreen = p->mapSpots[gStat->mapSpot].screen;
  p->playerMapX = p->mapSpots[gStat->mapSpot].x * 4;
  p->playerMapY = p->mapSpots[gStat->mapSpot].y * 4;
  if (gStat->stageID == gStat->coffinStageID && gStat->coffin >= 0) {
    p->coffinScreen = p->mapSpots[gStat->coffinMapSpot].screen;
    p->coffinMapX = p->mapSpots[gStat->coffinMapSpot].x * 4;
    p->coffinMapY = p->mapSpots[gStat->coffinMapSpot].y * 4;
    if (gStat->mapSpot == gStat->coffinMapSpot) {
      p->playerMapX -= 4;
      p->coffinMapX += 4;
    }
  } else {
    p->coffinScreen = 0xFF;
  }
}

s32 MainMenu_GetPlayerType(MainMenu* p) {
  if (p->player->kind == PLAYER_SOLAR_DJANGO) {
    return PT_RDJANGO;
  }
  if (p->player->kind == PLAYER_SABATA) {
    return PT_SABATA;
  }
  return PT_BDJANGO;
}

void MainMenu_ShowMapMarkers(MainMenu* p) {
  MainMenu_UpdateMapArrows(p);
  if (*(s32*)p->mapArrows != -1) {
    MainSprite_SetPose(&p->sprites[48], &p->gfx.smenu, 51, PLAYMODE_LOOP);
    p->sprites[48].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[48].pos.x = 0;
    p->sprites[48].pos.y = 0;
    p->sprites[48].pos.z = 0;
  }
  p->sprites[76].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[76], &p->gfx.map, MainMenu_GetPlayerType(p), PLAYMODE_LOOP);
  p->sprites[76].pos.x = p->playerMapX - (p->mapScrollX - p->mapOriginX);
  p->sprites[76].pos.y = p->playerMapY - (p->mapScrollY - p->mapOriginY);
  p->sprites[76].pos.z = 0;
  if (p->coffinScreen == p->playerScreen) {
    p->sprites[77].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[77].pos.x = p->coffinMapX - (p->mapScrollX - p->mapOriginX);
    p->sprites[77].pos.y = p->coffinMapY - (p->mapScrollY - p->mapOriginY);
    p->sprites[77].pos.z = 0;
  }
}

void MainMenu_ShowMapMarkersNoMap(MainMenu* p) {
  MainMenu_UpdateMapArrows(p);
  if (*(s32*)p->mapArrows != -1) {
    MainSprite_SetPose(&p->sprites[48], &p->gfx.smenu, 51, PLAYMODE_LOOP);
    p->sprites[48].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[48].pos.x = 0;
    p->sprites[48].pos.y = 0;
    p->sprites[48].pos.z = 0;
  }
  p->sprites[76].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[76], &p->gfx.map, 8, PLAYMODE_LOOP);
  p->sprites[76].pos.x = 0;
  p->sprites[76].pos.y = 0;
  p->sprites[76].pos.z = 0;
  p->sprites[77].flags |= SPRFLAG_HIDDEN;
}

void MainMenu_InitDungeonMap(MainMenu* p) {
  s32 bgIndex;

  if (gStat->stageID > 6) {
    p->mapTilemap = p->dungeonMapTilemap1;
  } else {
    p->mapTilemap = p->dungeonMapTilemap0;
  }
  MainMenu_LoadMapMarkers(p);
  p->mapScreen = p->playerScreen;
  if (p->mapScreens != NULL && IsMapUnlocked(p->mapScreens[p->mapScreen].mapID)) {
    p->mapVisible = TRUE;
  } else {
    p->mapVisible = FALSE;
  }
  bgIndex = 0;
  Video_SetupBGLayout(6, 2, p->mapTilemap, 0, 0, 1, &bgIndex);
  if (p->mapVisible) {
    s32 dx;
    s32 dy;
    s32 x;
    s32 y;

    MainMenu_SetupMapScroll(p);
    p->mapScrollX = p->playerMapX + p->mapOriginX - 120;
    p->mapScrollY = p->playerMapY + p->mapOriginY - 80;
    MainMenu_ClampMapScroll(p);
    MainMenu_ShowMapMarkers(p);
    Video_SetBGLayer(1, p->mapTilemap, p->mapScreens[p->mapScreen].bgLayer);
    dx = p->mapScrollX - p->mapOriginX;
    dy = p->mapScrollY - p->mapOriginY;
    x = dx >> 3;
    y = (dy >> 3) & ~1;
    Video_GenerateBGMap(1, x, y, dx, dy);
    MainMenu_DrawMapIcons(p, x, y);
  } else {
    MainMenu_FillBG1(p);
    MainMenu_ShowMapMarkersNoMap(p);
  }
  MessageWindow_Start(p->areaNames);
  MessageWindow_SetBgPltt(BGP_EFDA);
  MessageWindow_SetInstant(TRUE);
  MainMenu_ShowMapScreenName(p);
  MainMenu_SetState(p, MainMenu_UpdateDungeonMap, FALSE);
}

// 0xDA19
void Cmd_SetWorldMapFlag(void) {
  if (VM_SeekToNamedArg('i')) {
    s32 bitidx = VM_GetValue();

    gStat->worldMapFlags |= 1 << bitidx;
  }
}

u32 TestWorldMapFlag(u32 bitidx) { return gStat->worldMapFlags & (1 << bitidx); }

// ワールドマップに解放済みの場所の 2x2 タイルを描き, フラグ 14 が立つまでは右下の一画を塞ぐタイルを描く
// 残差: 157/160 命令, 原典は param_2 + 32 をスタックに逃がして i を r7 に置き, 書き込む値を呼び出しの後で r0 に作るが, こちらは i をスタックに置く (タイル番号の三項, ポインタ演算の書き方は試済)
NON_MATCH void MainMenu_DrawWorldMapTiles(MainMenu* p, s32 param_2, s32 param_3) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 10; i++) {
    const WorldMapTile* t = &sWorldMapTiles[i];

    if (TestWorldMapFlag(t->flagBit)) {
      s32 x = t->x;
      s32 y = t->y;
      s32 tile = 8;

      if (t->shape) {
        tile = 12;
      }
      if (x >= param_2 && x < param_2 + 32 && y >= param_3 && y < param_3 + 32) {
        *MainMenu_GetBgMapAddr(1, x, y) = tile | 0xE000;
      }
      if (x + 1 >= param_2 && x + 1 < param_2 + 32 && y >= param_3 && y < param_3 + 32) {
        *MainMenu_GetBgMapAddr(1, x + 1, y) = (tile + 1) | 0xE000;
      }
      if (x >= param_2 && x < param_2 + 32 && y + 1 >= param_3 && y + 1 < param_3 + 32) {
        *MainMenu_GetBgMapAddr(1, x, y + 1) = (tile + 16) | 0xE000;
      }
      if (x + 1 >= param_2 && x + 1 < param_2 + 32 && y + 1 >= param_3 && y + 1 < param_3 + 32) {
        *MainMenu_GetBgMapAddr(1, x + 1, y + 1) = (tile + 17) | 0xE000;
      }
    }
  }

  if (!TestWorldMapFlag(14)) {
    s32 n = 0;
    s32 y;

    for (y = 0; y < 6; y++) {
      s32 x;

      for (x = 0; x < 6; x++) {
        if (y + x > 1 && y + x <= 8 && y - x <= 3) {
          s32 tile = n + 17;

          if (n <= 1) {
            tile = n + 3;
          }
          *MainMenu_GetBgMapAddr(1, x + 43, y + 15) = tile | 0xE000;
          if (++n > 3) {
            n = 0;
          }
        }
      }
    }
  }
#else
  INCFUNC("asm/func/MainMenu_DrawWorldMapTiles.inc");
#endif
}

void MainMenu_UpdateWorldMap(MainMenu* p) {
  bool32 moved = FALSE;
  s32 i;

  if (gInput[0].down & DPAD_LEFT) {
    p->mapScrollX -= 2;
    moved = TRUE;
  } else if (gInput[0].down & DPAD_RIGHT) {
    p->mapScrollX += 2;
    moved = TRUE;
  }
  if (gInput[0].down & DPAD_UP) {
    p->mapScrollY -= 2;
    moved = TRUE;
  } else if (gInput[0].down & DPAD_DOWN) {
    p->mapScrollY += 2;
    moved = TRUE;
  }
  if (moved) {
    MainMenu_ClampMapScroll(p);
    Video_GenerateBGMap(1, p->mapScrollX >> 3, (p->mapScrollY >> 3) & ~1u, p->mapScrollX, p->mapScrollY);
    MainMenu_DrawWorldMapTiles(p, p->mapScrollX >> 3, (p->mapScrollY >> 3) & ~1u);
    p->sprites[76].pos.x = p->playerMapX - p->mapScrollX;
    p->sprites[76].pos.y = p->playerMapY - p->mapScrollY;
    if (!(p->sprites[77].flags & SPRFLAG_HIDDEN)) {
      p->sprites[77].pos.x = p->coffinMapX - p->mapScrollX;
      p->sprites[77].pos.y = p->coffinMapY - p->mapScrollY;
    }
    for (i = 0; i < 6; i++) {
      if (!(p->sprites[86 + i].flags & SPRFLAG_HIDDEN)) {
        p->sprites[86 + i].pos.x = -p->mapScrollX;
        p->sprites[86 + i].pos.y = -p->mapScrollY;
      }
    }
    for (i = 0; i < 8; i++) {
      if (!(p->sprites[92 + i].flags & SPRFLAG_HIDDEN)) {
        p->sprites[92 + i].pos.x = sWorldMapStages[7 + i].x * 4 - p->mapScrollX;
        p->sprites[92 + i].pos.y = sWorldMapStages[7 + i].y * 4 - p->mapScrollY;
      }
    }
  }
  MainMenu_AnimScrollArrows(p);
}

// ワールドマップを開く, プレイヤーと棺桶の位置にマーカーを置き, 解放済みの目印を並べてスクロール位置を決める
void MainMenu_InitWorldMap(MainMenu* p) {
  s32 bgIndex;
  s32 i;

  p->mapTilemap = p->worldMapTilemap;
  bgIndex = 0;
  Video_SetupBGLayout(6, 2, p->mapTilemap, 0, 0, 1, &bgIndex);
  p->playerMapX = sWorldMapStages[gStat->stageID].x * 4;
  p->playerMapY = sWorldMapStages[gStat->stageID].y * 4;
  if (gStat->coffin >= 0) {
    p->coffinMapX = sWorldMapStages[gStat->coffinStageID].x * 4;
    p->coffinMapY = sWorldMapStages[gStat->coffinStageID].y * 4;
    if (gStat->coffinStageID == gStat->stageID) {
      p->playerMapX -= 4;
      p->coffinMapX += 4;
    }
  }
  p->mapScrollMinX = 0;
  p->mapScrollMinY = 0;
  p->mapScrollMaxX = 272;
  p->mapScrollMaxY = 352;
  p->mapScrollX = p->playerMapX - 120;
  p->mapScrollY = p->playerMapY - 80;
  MainMenu_ClampMapScroll(p);
  Video_GenerateBGMap(1, p->mapScrollX >> 3, (p->mapScrollY >> 3) & ~1u, p->mapScrollX, p->mapScrollY);
  p->sprites[76].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[76], &p->gfx.map, MainMenu_GetPlayerType(p), PLAYMODE_LOOP);
  p->sprites[76].pos.x = p->playerMapX - p->mapScrollX;
  p->sprites[76].pos.y = p->playerMapY - p->mapScrollY;
  p->sprites[76].pos.z = 0;
  if (gStat->coffin >= 0) {
    p->sprites[77].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[77].pos.x = p->coffinMapX - p->mapScrollX;
    p->sprites[77].pos.y = p->coffinMapY - p->mapScrollY;
    p->sprites[77].pos.z = 0;
  }
  MainMenu_DrawWorldMapTiles(p, p->mapScrollX >> 3, (p->mapScrollY >> 3) & ~1u);
  for (i = 0; i < 6; i++) {
    if (TestWorldMapFlag(i)) {
      p->sprites[86 + i].flags &= ~SPRFLAG_HIDDEN;
      p->sprites[86 + i].pos.x = -p->mapScrollX;
      p->sprites[86 + i].pos.y = -p->mapScrollY;
      p->sprites[86 + i].pos.z = 0;
    }
  }
  for (i = 0; i < 8; i++) {
    if (TestWorldMapFlag(i + 6)) {
      p->sprites[92 + i].flags &= ~SPRFLAG_HIDDEN;
      p->sprites[92 + i].pos.x = sWorldMapStages[7 + i].x * 4 - p->mapScrollX;
      p->sprites[92 + i].pos.y = sWorldMapStages[7 + i].y * 4 - p->mapScrollY;
      p->sprites[92 + i].pos.z = 0;
    }
  }
  MessageWindow_Start(p->areaNames);
  MessageWindow_SetBgPltt(BGP_EFDA);
  MessageWindow_SetInstant(TRUE);
  MessageWindow_ShowLine(sWorldMapStages[gStat->stageID].nameLine);
  MainMenu_SetState(p, MainMenu_UpdateWorldMap, FALSE);
}

// MainMenu_InitPage_Map が stageID で引く, アイコンのないステージのうち5つは別の表を指すが, 先頭がすぐ終端か存在しない画面になるので何も描かれない
const MapIcon* const sMapIconTables[15] = {
    NULL,
    sCathedralMapIcons,
    sIsekiMapIcons,
    sDarkCityMapIcons,
    sAqueductMapIcons,
    sRasenMapIcons,
    sHenMapIcons,
    sHaikyoMapIcons,
    (const MapIcon*)sForestMapScreens,
    sForestMapIcons,
    (const MapIcon*)sTimeHouseMapScreens,
    sTimeHouseMapIcons,
    (const MapIcon*)sMugenMapScreens,
    (const MapIcon*)sPdBattleMapScreens,
    (const MapIcon*)sWorldMapStages,
};  // 0x085ACF40

void MainMenu_InitPage_Map(MainMenu* p) {
  MessageWindow_Close();
  Marquee_Clear();
  Marquee_CloseGlobal();
  MessageWindow_SetRect(0, 18, 30, 2);
  p->mapScreens = sMapScreenTables[gStat->stageID];
  p->mapSpots = sMapSpotTables[gStat->stageID];
  p->mapIcons = sMapIconTables[gStat->stageID];
  FUN_0808b82c(p);
  MainMenu_ShowPageName(p, p->page);
  FUN_0808c61c(p, 0, 24);
  MainMenu_SetButtonGuides(p, 0, -1);
  if (gStat->stageID > ST_PD_BATTLE) {
    FUN_0808a3c4(p, p->tm_18, 0, 5, p->worldMapPltt);
    MainMenu_InitWorldMap(p);
  } else {
    FUN_0808a3c4(p, p->tm_18, 0, 5, p->dungeonMapPltt);
    MainMenu_InitDungeonMap(p);
  }
}

// '.f' の4つの値を 0/1 のビットに畳んで u16_03002c10 に入れる
void Cmd_9FB7(void) {
  u16_03002c10 = 0;

  if (VM_SeekToNamedArg('f')) {
    s32 i;

    for (i = 0; i < 4; i++) {
      if (VM_GetValue() != 0) {
        u16_03002c10 |= 1 << i;
      }
    }
  }
}

u32 FUN_080916bc(u32 bitidx) { return u16_03002c10 & (1 << bitidx); }

// インベントリカーソルの枠表を作り直す, bit0 なら右側の4列を 16 番に, bit5 なら右下の枠を 21 番にする
// 残差: 80/81 命令, 最初の4x4ループで原典は値 i*4+j も誘導変数として減算で持つがこちらは毎回足す (j の昇順 + 3 - j, j + (i << 2) は試済), slotmap を u8 にして |= 0xFF の ldrb/orrs/strb は再現済
NON_MATCH void InventoryCursor_ResetSlotmap(InventoryCursor* p, u32 flags) {
#ifdef NONMATCHING_C
  s32 i, j;

  p->flags = flags;
  for (i = 0; i < 4; i++) {
    for (j = 3; j >= 0; j--) {
      INVENTORY_SLOT(p, j, i) = i * 4 + j;
    }
  }
  if (flags & 1) {
    for (i = 0; i < 4; i++) {
      for (j = 3; j >= 0; j--) {
        INVENTORY_SLOT(p, j + 4, i) = 16;
      }
    }
  } else {
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        INVENTORY_SLOT(p, j + 4, i) |= 0xFF;
      }
    }
  }
  for (i = 0; i < 3; i++) {
    INVENTORY_SLOT(p, 8, i) |= 0xFF;
  }
  INVENTORY_SLOT(p, 8, 3) = flags & 0x20 ? 21 : -1;
#else
  INCFUNC("asm/func/InventoryCursor_ResetSlotmap.inc");
#endif
}

u32 item_08091774(item32_t n) { return gItemDB[n].unk_00 & 0xF; }

u32 item_08091788(item32_t n) { return (gItemDB[n].unk_00 & 0xF0) >> 4; }

s32 item_0809179c(item32_t n) { return (gItemDB[n].unk_00 & 0x100) >> 8; }

u8 item_080917b4(item32_t n) { return (gItemDB[n].unk_00 & 0x200) >> 9; }

// 0x080917cc
item32_t GetItemID(bool32 isValuable, s32 slot) {
  if (!isValuable) {
    return GetNormalItemID(slot);
  }
  return GetValuableItemID(slot);
}

// maxHP の percent % ぶん回復する, badCondSec が正なら状態異常0を付ける (腐ったアイテム)
void ItemEffect_HP(MainMenu* p, s32 percent, s32 badCondSec) {
  Player* player = p->player;

  if (player != NULL) {
    s32 hp;

    p->effectAmount = Div(percent * player->maxHP, 100);
    hp = player->hp + p->effectAmount;
    if (hp > player->maxHP) {
      p->effectAmount = player->maxHP - player->hp;
      player->hp = player->maxHP;
    } else {
      player->hp = hp;
    }
    MainMenu_DrawHPGauge(p, 1, 5, 3);
    if (badCondSec > 0) {
      Player_ApplyBadCondition(player, BAD_HARAITA, badCondSec * 60);
    }
  }
}

// maxEne の percent % ぶん Ene を回復する, badCondSec が正なら状態異常を付ける (悪いキノコ, 腐った水)
void ItemEffect_MP(MainMenu* p, s32 percent, s32 badCondSec) {
  Player* player = p->player;

  if (player != NULL) {
    s32 ene;

    p->effectAmount = Div(player->maxEne * percent, 100);
    ene = player->ene + Div(player->maxEne * percent, 100);
    if (ene > player->maxEne) {
      p->effectAmount = player->maxEne - player->ene;
      player->ene = player->maxEne;
    } else if (ene < 0) {
      player->ene = 0;
    } else {
      player->ene = ene;
    }
    if (p->effectAmount < 0) {
      p->effectAmount = 0;
    }
    MainMenu_DrawEneGauge(p, 1, 5, 4);
    if (badCondSec > 0) {
      if (GetItemID(p->inValuableInventory, p->cursor.savedSlot) == ITEM_BAD_MUSHROOM) {
        Player_ApplyBadCondition(player, BAD_CONFUSE, badCondSec * 60);
      } else {
        Player_ApplyBadCondition(player, BAD_HARAITA, badCondSec * 60);
      }
    }
  }
}

// cureBits が立っている状態異常を治す (bit0: 腹痛, bit1: 毒, bit2: 混乱, bit3: カーモス)
void ItemEffect_BadStatus(MainMenu* p, s32 cureBits, s32 _) {
  Player* player = p->player;

  if (player != NULL) {
    s32 i;

    p->effectAmount = 0;
    for (i = 0; i < 3; i++) {
      if ((cureBits >> i) & 1) {
        Player_ClearBadCondition(player, i);
      }
    }
    if (cureBits & 8) {
      KAAMOS(player->isSabata) = 0;
    }
  }
}

// goodCondID のよいステータス効果を goodCondSec 秒ぶん付ける
void ItemEffect_Good(MainMenu* p, s32 goodCondID, s32 goodCondSec) {
  Player* player = p->player;

  if (player != NULL) {
    player->goodFrom = GetItemID(p->inValuableInventory, p->cursor.savedSlot);
    player->goodCondID = goodCondID;
    player->goodCondTimer = goodCondSec * 60;
    player->plttID_95e = OBP_ELEMENT(0);
    player->plttFlashTimer = 48;
    p->effectAmount = 0;
    p->unk_a95 = 1;
    p->unk_3ae4 = 1;
  }
}

// IET_VITAMINS, statIdx のステータスのドーピングボーナスを amount 上げる (合計99が上限), statIdx が範囲外ならランダムな1種
void ItemEffect_Vitamins(MainMenu* p, s32 statIdx, s32 amount) {
  Player* player = p->player;

  if (player != NULL) {
    s32 add;
    s32 i;

    if (statIdx < STAT_KINDS) {
      p->vitaminStat = statIdx;
    } else {
      p->vitaminStat = Mod(Random() >> 3, STAT_KINDS);
    }
    p->vitaminAmount = amount;
    add = p->vitaminAmount;
    i = p->vitaminStat;
    if (*(gStat->stats + i) + *(gStat->statBonus + i) + add > 99) {
      add = 99 - *(gStat->stats + i) - *(gStat->statBonus + i);
    }
    *(gStat->statBonus + i) += add;
    Player_RefreshAllStats(player);
    MainMenu_DrawEquipStats(p, 5, 3);
  }
}

/**
 * @brief IET_BUGS, 精霊虫召喚
 * @param kind 精霊虫の種類 (0: 太陽虫, 1: 月光虫, 2: 暗黒虫)
 * @param amount 呼び出す数
 */
void ItemEffect_Bugs(MainMenu* p, s32 kind, s32 amount) {
  Player* player = p->player;

  if (player != NULL) {
    p->bugsKind = kind;
    if (player->kind == PLAYER_SABATA) {
      if ((u8)kind == 0) {
        p->bugsKind = 2;
      } else if ((u8)kind == 2) {
        p->bugsKind = 0;
      }
    }
    p->bugsAmount = amount;
    p->pendingBugs = 1;
    p->unk_3ae4 = 1;
  }
}

/**
 * @brief IET_WARP, 転移の葉, 愚者のカード
 * @param kind 0: 転移の葉, 1: 愚者のカード
 */
void ItemEffect_Warp(MainMenu* p, s32 kind, s32 _) {
  p->pendingWarp = 1;
  p->warpKind = kind;
  p->unk_3ae4 = 1;
}

// IET_SOLAR, 太陽ゲージ操作 (テルテルボーズ、ズーボルテルテ, おてんきゲタ)
void ItemEffect_Solar(MainMenu* p, s32 _, s32 __) {
  if (p->helperChara == 0) {
    SOLAR_CHARM(0) = 1;
    SOLAR_CHARM(1) = 0;
  } else {
    SOLAR_CHARM(0) = 0;
    SOLAR_CHARM(1) = 1;
  }
}

// IET_LOAN, 暗黒カード
void ItemEffect_Loan(MainMenu* p, s32 _, s32 __) {
  p->effectAmount = 0;
  p->unk_401d = 1;
  p->unk_3ae4 = 1;
}

// HP と Ene を targetHP / targetEne に書き換える, HPが0になったら 審判のカード 持ちだけ pendingCard を落とす
void ItemEffect_HPMP(MainMenu* p, s32 _, s32 __) {
  p->player->hp = p->targetHP;
  p->player->ene = p->targetEne;
  if (p->player->hp == 0) {
    p->unk_3ae4 = 1;
    if (CheckItemOwn(ITEM_JUDGEMENT)) {
      p->pendingCard = 0;
    }
  } else {
    p->pendingCard = 0;
  }
}

/**
 * @brief IET_AOE, 画面内の全ての敵にダメージ
 * @param kind 0: 正義のカード, 1: 塔のカード
 */
void ItemEffect_AOE(MainMenu* p, s32 kind, s32 _) {
  p->pendingAOE = 1;
  p->aoeKind = kind;
  p->unk_3ae4 = 1;
}

void ItemEffect_Refresh(MainMenu* p, s32 _, s32 __) {
  s32 i;

  for (i = 0; i < 16; i++) {
    SetRotCount2(i, 0);
  }
}

// 装備中の武器の損傷度をリセットする
void ItemEffect_Repair(MainMenu* p, s32 _, s32 __) { GetWeapon(REGISTERED_WEAPON(gStat->equippedWeaponIdx))->wear = 0; }

// 道具 n を今使って意味があるかを返す, キャラごとの使用可否, 特定の道具のフラグ, 効果の種類 (HP / Ene が減っているか, 状態異常, 武器の修理) で判定する
// 残差: 158/152 命令, 原典は TRUE を返すブロックを1つにまとめて各判定から bne で飛び, FALSE を末尾に置くが, こちらは分岐ごとに TRUE / FALSE のジャンプが残る (return x != 0 の形は 166 命令で更に遠い)
NON_MATCH u32 Item_IsUsableNow(item32_t n) {
#ifdef NONMATCHING_C
  Player* player = gPlayerPtr[0];

  if (player == NULL) {
    return FALSE;
  }
  if (player->kind == PLAYER_SOLAR_DJANGO) {
    if (item_08091774(n) == 1) {
      return FALSE;
    }
  } else if ((u8)(player->kind - 1) <= 3) {
    if (item_08091774(n) == 0) {
      return FALSE;
    }
  }

  if (n == 30) {
    if (FUN_080916bc(0)) {
      return TRUE;
    }
    return FALSE;
  }
  if (n == 31) {
    if (FUN_080916bc(1)) {
      return TRUE;
    }
    return FALSE;
  }
  if (n >= 27 && n <= 29) {
    if (FUN_080916bc(2)) {
      return TRUE;
    }
    return FALSE;
  }
  if (n == 49) {
    if (FUN_080916bc(3)) {
      return TRUE;
    }
    return FALSE;
  }
  if (n == ITEM_SOLAR_NUT && player->kind == PLAYER_SABATA) {
    return TRUE;
  }

  switch (item_08091788(n)) {
    case 1: {
      return TRUE;
    }
    case 2: {
      if (player->hp < player->maxHP) {
        return TRUE;
      }
      return FALSE;
    }
    case 3: {
      if (player->ene < player->maxEne) {
        return TRUE;
      }
      return FALSE;
    }
    case 4: {
      s32 i;

      for (i = 0; i < 3; i++) {
        if (player->badCondTimer[i] != 0 && ((gItemDB[n].value1 >> i) & 1)) {
          return TRUE;
        }
      }
      if (KAAMOS(player->isSabata) <= 0) {
        return FALSE;
      }
      if (gItemDB[n].value1 & 8) {
        return TRUE;
      }
      return FALSE;
    }
    case 5: {
      Weapon* w;

      if (REGISTERED_WEAPON(gStat->equippedWeaponIdx) < 0) {
        return FALSE;
      }
      w = GetWeapon(REGISTERED_WEAPON(gStat->equippedWeaponIdx));
      if (w->quality > 0 || (u8)w->effects[1] != 0) {
        return TRUE;
      }
      if ((u8)w->effects[2] != 0) {
        return TRUE;
      }
      return FALSE;
    }
  }
  return FALSE;
#else
  INCFUNC("asm/func/Item_IsUsableNow.inc");
#endif
}

bool32 FUN_08091e34(item32_t n) {
  if (item_0809179c(n) == 1) {
    return TRUE;
  }
  return FALSE;
}

void MainMenu_ConsumeItem(MainMenu* p, s32 slot) {
  if (!p->inValuableInventory) {
    RemoveItem(slot);
  }
}

// index: ItemEffectType で引くアイテム効果の処理表, MainMenu_ApplyItemEffect が (p, value1, value2) で呼ぶ
void (*const gItemEffectHandlers[15])(MainMenu*, s32, s32) = {
    [IET_NONE] = NULL,
    [IET_HP] = ItemEffect_HP,
    [IET_MP] = ItemEffect_MP,
    [IET_BAD_STATUS] = ItemEffect_BadStatus,
    [IET_VITAMINS] = ItemEffect_Vitamins,
    [IET_GOOD] = ItemEffect_Good,
    [IET_BUGS] = ItemEffect_Bugs,
    [IET_WARP] = ItemEffect_Warp,
    [IET_SOLAR] = ItemEffect_Solar,
    [IET_LOAN] = ItemEffect_Loan,
    [IET_HPMP] = ItemEffect_HPMP,
    [IET_LOVER] = NULL,
    [IET_AOE] = ItemEffect_AOE,
    [IET_REFRESH] = ItemEffect_Refresh,
    [IET_REPAIR] = ItemEffect_Repair,
};  // 0x085ACF7C

// 道具を使った効果を適用して枠から消す, ジャンゴ以外が木の実やキノコを食べると腹痛や混乱になり, 大地の衣は効果を倍にする
// 残差: 190/189 命令, 原典は value1 を r6, value2 を r2 に置いて呼び出しに直接渡すが, こちらは逆になって mov が1つ増える (宣言順の入れ替えは試済)
NON_MATCH void MainMenu_ApplyItemEffect(MainMenu* p, slot32_t slot) {
#ifdef NONMATCHING_C
  u32 id = GetItemID(p->inValuableInventory, slot);
  s32 v1;
  s32 v2;

  if ((u8)(p->player->kind - 1) <= 3) {
    if (id <= ITEM_SOLAR_NUT || id == ITEM_TIPTOE_NUT || id == ITEM_SPEED_NUT || id == ITEM_POWER_NUT || id == ITEM_BEARNUT || id == ITEM_SEE_ALL_NUT || id == ITEM_ROTTEN_NUT || id == ITEM_RED_MUSHROOM || id == ITEM_BLUE_MUSHROOM) {
      s32 frames = 1800;

      if (Player_TestEquipBuff(p->player, EBUFF_EARTHLYROBE)) {
        frames <<= 1;
      }
      Player_ApplyBadCondition(p->player, 0, frames);
      p->effectAmount = 0;
      MainMenu_ConsumeItem(p, slot);
      return;
    }
    if (id == ITEM_BAD_MUSHROOM) {
      s32 frames = 900;

      if (Player_TestEquipBuff(p->player, EBUFF_EARTHLYROBE)) {
        frames <<= 1;
      }
      Player_ApplyBadCondition(p->player, 2, frames);
      p->effectAmount = 0;
      MainMenu_ConsumeItem(p, slot);
      return;
    }
  }

  if (p->player->kind == PLAYER_SOLAR_DJANGO && id == ITEM_TOMATO_JUICE) {
    id = ITEM_ROTTEN_NUT;
    v1 = gItemDB[id].value1;
    v2 = gItemDB[id].value2;
  } else {
    v1 = gItemDB[id].value1;
    v2 = gItemDB[id].value2;
    if (p->player->kind == PLAYER_SABATA && id == ITEM_SOLAR_NUT) {
      v1 = -v1;
    }
    if (Player_TestEquipBuff(p->player, EBUFF_EARTHLYROBE)) {
      if (id <= ITEM_SOLAR_NUT || id == ITEM_ROTTEN_NUT || id == ITEM_BAD_MUSHROOM) {
        v1 <<= 1;
      } else if (id - ITEM_SPEED_NUT <= 2 || id == ITEM_BEARNUT || id == ITEM_SEE_ALL_NUT || id == ITEM_RED_MUSHROOM || id == ITEM_BLUE_MUSHROOM) {
        v2 <<= 1;
      }
    }
  }
  gItemEffectHandlers[gItemDB[id].effectType](p, v1, v2);
  if (id == ITEM_CHOCOLATE_COVERED) {
    UncoverChocolate(slot);
    if (GetItemID(FALSE, slot) == ITEM_CHOCOLATE_COVERED) {
      MainMenu_ConsumeItem(p, slot);
    }
  } else {
    MainMenu_ConsumeItem(p, slot);
  }
#else
  INCFUNC("asm/func/MainMenu_ApplyItemEffect.inc");
#endif
}

// 開いているのが道具欄か貴重品欄かに合わせて2つの枠を入れ替える
void MainMenu_SwapItemSlot(MainMenu* p, s32 slotA, s32 slotB) {
  if (!p->inValuableInventory) {
    SwapNormalItem(slotA, slotB);
  } else {
    SwapValuable(slotA, slotB);
  }
}

// 腐敗の進み具合を 0xD0〜0xD3 の4段階で返す, アイテムが無いか腐らないものなら 0xCF
u32 Item_GetRotStageIcon(s32 slot) {
  item32_t n = GetNormalItemID(slot);
  u16 rotLimit;
  s32 stage;

  if (n < 0) {
    return ICON_TIMER_NONE;
  }

  rotLimit = gItemDB[n].durability;
  if (rotLimit == 0) {
    return ICON_TIMER_NONE;
  }

  stage = Div(GetRotCount2(slot) * 4, rotLimit * 32);
  if (stage > 3) {
    stage = 3;
  }
  return ICON_TIMER_100 + stage;
}

// カーソル位置の道具のアイコンと名前, 説明のマーキーを出す, PET やサバタの太陽の実などは説明を差し替える
void MainMenu_ShowCursorItemInfo(MainMenu* p) {
  s32 id;
  s32 pose;

  if (p->cursor.slot <= 15) {
    id = GetItemID(p->inValuableInventory, p->cursor.slot);
    if (!p->inValuableInventory) {
      pose = Item_GetRotStageIcon(p->cursor.slot);
    } else {
      pose = 207;
    }
  } else {
    id = -1;
    pose = 207;
  }

  if (id < 0) {
    p->sprites[45].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    Marquee_Clear();
  } else {
    s32 base;

    p->sprites[45].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[45], &p->gfx.icons, pose, PLAYMODE_LOOP);
    MessageWindow_SetInstant(TRUE);
    MessageWindow_Start(p->itemNames);
    MessageWindow_SetRect(2, 16, 28, 2);
    MessageWindow_ShowLine(id);
    FUN_08049f5c();
    base = VM_ParseStringRef(p->itemNames);
    if (id == ITEM_PET) {
      base += 235;
      Marquee_SetText(GetStringByID(base + p->unk_3fa0));
    } else if (p->player->kind == PLAYER_SABATA && id == ITEM_SOLAR_NUT) {
      Marquee_SetText(GetStringByID(base + 234));
    } else if (gStat->playerKind == PLAYER_SABATA && id == ITEM_TOMATO_JUICE) {
      Marquee_SetText(GetStringByID(base + 169));
    } else {
      if (p->player->kind == PLAYER_SOLAR_DJANGO || p->player->kind == PLAYER_SABATA) {
        base += 78;
      } else {
        base += 156;
      }
      Marquee_SetText(GetStringByID(base + id));
    }
  }
}

// 選択中のアイテムが HP/Ene 回復アイテムかどうか
bool32 FUN_080921a8(MainMenu* p) {
  item32_t id = GetItemID(p->inValuableInventory, p->cursor.savedSlot);

  if (gItemDB[id].effectType == IET_HP || gItemDB[id].effectType == IET_MP) {
    return TRUE;
  }
  return FALSE;
}

// 防具ページのスロット番号から画面上のカーソル位置を引く
void MainMenu_GetSlotPos(WorldPos* pos, s32 idx) {
  if (idx <= 15) {
    pos->x = (idx & 3) * 24 + 144;
    pos->y = (idx >> 2) * 24 + 32;
  } else if (idx == 21) {
    pos->x = 120;
    pos->y = 104;
  } else if (idx == 20) {
    pos->x = 117;
    pos->y = 70;
  } else if (idx == 16) {
    pos->x = 28;
    pos->y = 88;
  } else {
    pos->x = 144;
    pos->y = 32;
  }
}

// 道具/貴重品ページの16枠のアイコン (sprites[17〜32]) を所持品に合わせて描き直す
void MainMenu_RefreshItemIcons(MainMenu* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    item32_t id = GetItemID(p->inValuableInventory, i);

    if (id < 0) {
      p->sprites[17 + i].flags |= SPRFLAG_HIDDEN;
    } else {
      p->sprites[17 + i].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetPose(&p->sprites[17 + i], &p->gfx.icons, id + 104, PLAYMODE_LOOP);
      if (!p->inValuableInventory) {
        if (Item_IsUsableNow(id)) {
          MainSprite_SetPltt(&p->sprites[17 + i], 735);
        } else {
          MainSprite_SetPltt(&p->sprites[17 + i], 736);
        }
      } else {
        MainSprite_SetPltt(&p->sprites[17 + i], 735);
      }
    }
  }
}

void FUN_08092300(MainMenu* p, s32 idx, s32 param_3, s32 param_4) {
  MainSprite* sprite = &p->sprites[idx + 46];

  sprite->flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(sprite, &p->gfx.icons, GetItemID(p->inValuableInventory, param_3) + 104, PLAYMODE_LOOP);
  MainMenu_GetSlotPos(&sprite->pos, param_3);
  MainMenu_GetSlotPos((Vec3*)&p->unk_3b68[idx * 4], param_4);
  MainSprite_SetPltt(sprite, p->sprites[param_3 + 17].plttID);
}

// カーモス・エフェクト・毒・混乱・腹痛のうちかかっているものを sprites[62〜65] に縦に並べて出す
void MainMenu_ShowCondIcons(MainMenu* p) {
  Vec3 pos;
  s32 n = 0;

  pos.x = 0, pos.y = 0, pos.z = 0;
  if (KAAMOS(p->player->isSabata) > 0) {
    MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 173, PLAYMODE_LOOP);
    p->sprites[62 + n].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[62 + n].pos = pos;
    pos.y += 13;
    n++;
  }
  if (p->player->emitter.unk_3) {
    if (p->player->emitter.kind == 1) {
      MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 171, PLAYMODE_LOOP);
    } else if (p->player->emitter.kind == 2) {
      MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 170, PLAYMODE_LOOP);
    } else {
      MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 172, PLAYMODE_LOOP);
    }
    p->sprites[62 + n].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[62 + n].pos = pos;
    pos.y += 13;
    n++;
  } else if (p->player->badCondTimer[BAD_POISON]) {
    MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 174, PLAYMODE_LOOP);
    p->sprites[62 + n].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[62 + n].pos = pos;
    pos.y += 13;
    n++;
  }
  if (p->player->badCondTimer[2]) {
    MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 175, PLAYMODE_LOOP);
    p->sprites[62 + n].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[62 + n].pos = pos;
    pos.y += 13;
    n++;
  }
  if (p->player->badCondTimer[0]) {
    MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 176, PLAYMODE_LOOP);
    p->sprites[62 + n].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[62 + n].pos = pos;
    n++;
  }
  for (; n < 4; n++) {
    p->sprites[62 + n].flags |= SPRFLAG_HIDDEN;
  }
}

u32 FUN_080925d4(item32_t n) {
  u32 flags;

  if (n < 0) {
    return 0;
  }

  flags = FUN_08091e34(n) ? 0x10 : 0;
  if (Item_IsUsableNow(n)) {
    flags |= 1;
  }
  return flags;
}

// 道具ページのボタン案内を, 入れ替え中かどうかとカーソルの位置で切り替える
void MainMenu_UpdateItemButtonGuides(MainMenu* p, s32 param_2) {
  if (param_2 == 0) {
    if (p->cursor.slot == 21) {
      MainMenu_SetButtonGuides(p, 0, 4);
    } else {
      MainMenu_SetButtonGuides(p, 0, -1);
    }
  } else {
    u8 mode = 0;

    if (GetItemID(p->inValuableInventory, p->cursor.savedSlot) < 0) {
      if (GetItemID(p->inValuableInventory, p->cursor.slot) >= 0) {
        mode = 3;
      }
    } else if (p->cursor.slot == 16) {
      mode = 1;
    } else if (p->cursor.savedSlot == p->cursor.slot) {
      mode = p->cursor.flags & 1;
    } else {
      mode = 3;
    }

    switch (mode) {
      case 1: {
        MainMenu_SetButtonGuides(p, 1, -1);
        break;
      }
      case 3: {
        MainMenu_SetButtonGuides(p, 3, -1);
        break;
      }
      default: {
        MainMenu_SetButtonGuides(p, -1, -1);
        break;
      }
    }
  }
}

s32 MainMenu_GetItemAction(MainMenu* p) {
  if (GetItemID(p->inValuableInventory, p->cursor.savedSlot) < 0) {
    if (GetItemID(p->inValuableInventory, p->cursor.slot) >= 0) {
      return 3;
    }
    return 0;
  }
  if (p->cursor.slot == 20) {
    return 2;
  }
  if (p->cursor.slot == 16) {
    return 1;
  }
  if (p->cursor.savedSlot == p->cursor.slot) {
    if (p->cursor.flags & 1) {
      p->cursor.slot = 16;
      return 1;
    }
    return 0;
  }
  return 3;
}

void MainMenu_ReturnToItemPage(MainMenu* p) {
  p->sprites[14].flags |= SPRFLAG_HIDDEN;
  p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
  MainMenu_RefreshItemIcons(p);
  InventoryCursor_RestorePos(&p->cursor);
  InventoryCursor_ResetSlotmap(&p->cursor, 32);
  MainMenu_GetSlotPos(&p->sprites[13].pos, (u8)p->cursor.slot);
  MainMenu_ShowCursorItemInfo(p);
  MainMenu_ShowCondIcons(p);
  MainMenu_UpdateItemButtonGuides(p, 0);
  MainMenu_SetState(p, MainMenu_StateItemPage, FALSE);
}

// 入れ替え元の道具アイコンを隠し, 代わりのアイコンを入れ替え先まで飛ばす
void MainMenu_StartItemMove(MainMenu* p) {
  Vec3 from, to;

  p->sprites[p->cursor.savedSlot + 17].flags |= SPRFLAG_HIDDEN;
  MainMenu_GetSlotPos(&from, p->cursor.savedSlot);
  MainMenu_GetSlotPos(&to, p->cursor.slot);
  MainMenu_BeginItemMove(p, 0, GetItemID(p->inValuableInventory, p->cursor.savedSlot) + 104, p->sprites[p->cursor.savedSlot + 17].plttID, &from, &to, 24, 16);
  PlaySound_082406e0(SE_SWAP_SLOT);
  MainMenu_SetState(p, MainMenu_StateItemEffectApply, TRUE);
}

// pos の少し上に 1〜3 桁の数字を中央寄せで出す, 0 以下なら何もしない
// 残差: 116/116 命令, ループで原典は sprites[48 + i].pos への格納を flags 用のポインタ (+0x18) から行い, その初期化を先に置くが, こちらはスプライト先頭のポインタ (+0x20) を使う (スプライトのローカル変数は試済)
NON_MATCH void MainMenu_ShowPopupNumber(MainMenu* p, s32 value, Vec3* pos) {
#ifdef NONMATCHING_C
  if (value > 0) {
    s32 digits[3];
    s32 blank;
    s32 rest;
    Vec3 p2;
    s32 i;

    digits[0] = Div(value, 100);
    rest = value - digits[0] * 100;
    digits[1] = Div(rest, 10);
    rest -= digits[1] * 10;
    digits[2] = rest;
    if (digits[0] > 0) {
      blank = 0;
    } else if (digits[1] > 0) {
      blank = 1;
    } else {
      blank = 2;
    }
    p2 = *pos;
    p2.x -= (3 - blank) * 4;
    p2.y -= 4;
    for (i = 0; i < 3; i++) {
      if (i < blank) {
        p->sprites[48 + i].flags |= SPRFLAG_HIDDEN;
      } else {
        p->sprites[48 + i].flags &= ~SPRFLAG_HIDDEN;
        MainSprite_SetPose(&p->sprites[48 + i], &p->gfx.smenu, digits[i] + 10, PLAYMODE_LOOP);
        p->sprites[48 + i].pos = p2;
        p2.x += 8;
      }
    }
  }
#else
  INCFUNC("asm/func/MainMenu_ShowPopupNumber.inc");
#endif
}

// 道具を使う演出の終わりに効果を適用し, 回復音と一緒に効果量をポップアップで出す
void MainMenu_StateItemEffectApply(MainMenu* p) {
  Vec3 pos;

  if (MainMenu_UpdateItemMove(p, 0) && ++p->stateTimer > 7) {
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    MainMenu_ApplyItemEffect(p, p->cursor.savedSlot);
    MainMenu_StartPlttFade(p, 289, MainMenu_GetPlayerPlttID(p), 16);
    pos.x = 36;
    pos.y = 84;
    MainMenu_ShowPopupNumber(p, p->effectAmount, &pos);
    PlaySound_082406e0(SE_HEAL);
    MainMenu_SetState(p, MainMenu_StateItemEffectPopup, TRUE);
  }
}

// 効果量のポップアップを少し浮かせてから消し, パレットの補間が終わったら道具ページに戻す
void MainMenu_StateItemEffectPopup(MainMenu* p) {
  s32 i;

  if (p->stateTimer < 16) {
    if (++p->stateTimer == 16) {
      for (i = 0; i < 3; i++) {
        p->sprites[48 + i].flags |= SPRFLAG_HIDDEN;
      }
    } else if (p->stateTimer <= 8) {
      for (i = 0; i < 3; i++) {
        p->sprites[48 + i].pos.y--;
      }
    }
  } else if (MainMenu_UpdatePlttFade(p)) {
    MainMenu_ReturnToItemPage(p);
  }
}

// メッセージを閉じ, 選んだ道具のアイコンを使用先へ飛ばす
void FUN_08092a94(MainMenu* p) {
  Vec3 from, to;

  MessageWindow_Close();
  Marquee_Clear();
  Marquee_RequestClose();
  p->sprites[p->cursor.savedSlot + 17].flags |= SPRFLAG_HIDDEN;
  MainMenu_GetSlotPos(&from, p->cursor.savedSlot);
  MainMenu_GetSlotPos(&to, p->cursor.slot);
  MainMenu_BeginItemMove(p, 0, GetItemID(p->inValuableInventory, p->cursor.savedSlot) + 104, p->sprites[p->cursor.savedSlot + 17].plttID, &from, &to, 24, 16);
  MainMenu_SetState(p, FUN_08092b3c, TRUE);
}

void FUN_08092b3c(MainMenu* p) {
  if (MainMenu_UpdateItemMove(p, 0) != 0) {
    if (++p->stateTimer >= 8) {
      p->sprites[46].flags |= SPRFLAG_HIDDEN;
      MainMenu_ApplyItemEffect(p, p->cursor.savedSlot);
      MainMenu_StartPlttFade(p, 289, MainMenu_GetPlayerPlttID(p), 16);
      PlaySound_082406e0(SE_HEAL);
      MainMenu_SetState(p, FUN_08092bb8, TRUE);
    }
  }
}

// 16フレーム待ってから次の状態へ進む
void FUN_08092bb8(MainMenu* p) {
  if (p->stateTimer <= 15) {
    p->stateTimer++;
  } else if (MainMenu_UpdatePlttFade(p)) {
    MainMenu_SetState(p, MainMenu_ShowVitaminResult, 1);
  }
}

// ビタミンでどのステータスがいくつ上がったかを表示し, 90 フレーム経つか A で閉じる
void MainMenu_ShowVitaminResult(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    MessageWindow_Start(p->itemNames);
    MessageWindow_SetInstant(TRUE);
    MessageWindow_SetRect(0, 16, 30, 4);
    MessageWindow_ShowLine(p->vitaminStat + 255);
    MessageWindow_SetVarValue(0, p->vitaminAmount);
  }

  ++*timer;
  if (*timer >= 90 || (*timer >= 16 && (gInput[0].pressed & A_BUTTON))) {
    MessageWindow_SetInstant(TRUE);
    MessageWindow_SetRect(0, 16, 30, 2);
    MainMenu_ReturnToItemPage(p);
  }
}

void FUN_08092c7c(MainMenu* p, s32 val) {
  p->helperChara = val;
  MessageWindow_Close();
  Marquee_Clear();
  Marquee_RequestClose();
  MainMenu_SetState(p, FUN_080931cc, 1);
}

// おてんきゲタを投げる演出を始める, アイコンをランダムな向きに飛ばし, 回転の速さを itemMoves[0].timer に入れる
void MainMenu_BeginThrowGeta(MainMenu* p) {
  Vec3 from, to;
  u16* table;
  u16 v;

  p->sprites[p->cursor.savedSlot + 17].flags |= SPRFLAG_HIDDEN;
  MainMenu_GetSlotPos(&from, p->cursor.savedSlot);
  from.x += 8;
  from.y += 8;
  table = gRandomTable;
  to.x = -6 - Mod(_Random(table), 3);
  to.y = -5 - Mod(_Random(table), 5);
  v = Mod(_Random(table), 10) + 5;
  if (_Random(table) & 1) {
    v = -v;
  }
  MainMenu_BeginItemMove(p, 0, GetItemID(p->inValuableInventory, p->cursor.savedSlot) + 104, p->sprites[p->cursor.savedSlot + 17].plttID, &from, &to, 0, 0);
  p->itemMoves[0].timer = v;
  MessageWindow_Close();
  Marquee_Clear();
  Marquee_RequestClose();
  PlaySound_082406e0(SE_GETA_THROW);
  MainMenu_SetState(p, MainMenu_StateThrowGeta, TRUE);
}

// 投げた下駄を跳ねさせながら回し, 地面で止まったら表 (0) か裏 (1) かを返す, 飛んでいる間は -1
s32 MainMenu_UpdateThrownGeta(MainMenu* p) {
  Vec3* pos = &p->itemMoves[0].from;
  Vec3* vel = &p->itemMoves[0].to;
  u16* angle = &p->itemMoves[0].duration;
  u16* spin = &p->itemMoves[0].timer;
  bool32 landed = FALSE;

  pos->x += vel->x;
  pos->y += vel->y;
  vel->y++;
  if ((++p->stateTimer & 15) == 0) {
    if (vel->x > 0) {
      vel->x--;
    } else if (vel->x < 0) {
      vel->x++;
    }
  }

  if (pos->x < 8) {
    pos->x = 8;
    vel->x = FixToInt(1, -vel->x);
    SetRandomSpin(spin);
  } else if (pos->x > 232) {
    pos->x = 232;
    vel->x = FixToInt(1, -vel->x);
    SetRandomSpin(spin);
  }

  if (pos->y > 119) {
    pos->y = 120;
    vel->y = FixToInt(1, -vel->y);
    if (vel->y > -2) {
      vel->x = 0;
      vel->y = 0;
      *spin = 0;
      if ((u16)(*angle - 64) < 128) {
        *angle = 128;
      } else {
        *angle = 0;
      }
      landed = TRUE;
    } else {
      SetRandomSpin(spin);
    }
  }

  if (landed) {
    p->sprites[46].flags &= ~SPRFLAG_AFFINE;
    p->sprites[46].pos.x = pos->x - 8;
    p->sprites[46].pos.y = pos->y - 8;
    p->sprites[46].rotation = *angle;
    if (p->sprites[46].rotation == 0) {
      return 0;
    }
    MainSprite_SetPose(&p->sprites[46], &p->gfx.icons, 206, PLAYMODE_LOOP);
    return 1;
  } else {
    s32 x;
    s32 z;

    *angle = (*angle + 256 + *spin) & 0xFF;
    x = POLAR_X(-8, *angle);
    z = POLAR_Z(-8, *angle);
    p->sprites[46].flags |= SPRFLAG_AFFINE;
    p->sprites[46].pos.x = pos->x + z + x;
    p->sprites[46].pos.y = pos->y + x - z;
    p->sprites[46].rotation = *angle;
    return -1;
  }
}

void MainMenu_StateThrowGeta(MainMenu* p) {
  s32 v = MainMenu_UpdateThrownGeta(p);

  if (v >= 0) {
    p->helperChara = v;
    MainMenu_SetState(p, FUN_08093158, 1);
  }
}

void FUN_08093158(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 16) {
    MessageWindow_Start(p->itemNames);
    MessageWindow_SetInstant(TRUE);
    MessageWindow_SetRect(0, 16, 30, 4);
    MessageWindow_ShowLine(p->helperChara + 251);
  }

  ++*timer;
  if (*timer >= 90 || (*timer >= 16 && (gInput[0].pressed & A_BUTTON))) {
    MessageWindow_Close();
    MainMenu_SetState(p, FUN_08093264, TRUE);
  }
}

void FUN_080931cc(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    MessageWindow_Start(p->itemNames);
    MessageWindow_SetInstant(TRUE);
    MessageWindow_SetRect(0, 16, 30, 4);
    MessageWindow_ShowLine(p->helperChara + 249);
  }

  ++*timer;
  if (*timer >= 90 || (*timer >= 16 && (gInput[0].pressed & A_BUTTON))) {
    p->sprites[17 + p->cursor.savedSlot].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    MainMenu_SetState(p, FUN_08093264, TRUE);
  }
}

void FUN_08093264(MainMenu* p) {
  if (p->stateTimer == 0) {
    MainMenu_ApplyItemEffect(p, p->cursor.savedSlot);
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    if (p->helperChara != 0) {
      PlaySound_082406e0(SE_TONNIAR_RM);
    } else {
      PlaySound_082406e0(SE_MR_RAINNOT);
    }
  }
  if (p->helperChara != 0) {
    SetScreenBrightness(p->stateTimer + 16, RGB(0, 0, 0));
  } else {
    SetScreenBrightness(p->stateTimer + 16, RGB(31, 31, 31));
  }
  if (++p->stateTimer > 48) {
    MainMenu_SetState(p, FUN_08093318, TRUE);
  }
}

void FUN_08093318(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    MessageWindow_Start(p->itemNames);
    MessageWindow_SetInstant(TRUE);
    MessageWindow_SetRect(0, 16, 30, 4);
    MessageWindow_ShowLine(p->helperChara + 253);
  }

  ++*timer;
  if (*timer >= 90 || (*timer >= 16 && (gInput[0].pressed & A_BUTTON))) {
    p->sprites[46].rotation = 0;
    p->sprites[46].flags &= ~SPRFLAG_AFFINE;
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    MessageWindow_SetInstant(TRUE);
    MessageWindow_SetRect(0, 16, 30, 2);
    MainMenu_ReturnToItemPage(p);
  }
}

// 吊るされた男 (param_2 == 0, HP と Ene の割合を入れ替える) と死神 (HP を 0, Ene を満タン) のカードの演出を始める
void MainMenu_BeginHPMPCard(MainMenu* p, s32 param_2) {
  Vec3 from, to;

  p->sprites[p->cursor.savedSlot + 17].flags |= SPRFLAG_HIDDEN;
  MainMenu_GetSlotPos(&from, p->cursor.savedSlot);
  MainMenu_GetSlotPos(&to, p->cursor.slot);
  MainMenu_BeginItemMove(p, 0, GetItemID(p->inValuableInventory, p->cursor.savedSlot) + 104, p->sprites[p->cursor.savedSlot + 17].plttID, &from, &to, 24, 16);
  if (param_2 == 0) {
    p->pendingCard = 1;
    p->prevHP = p->player->hp;
    p->prevEne = p->player->ene;
    p->targetHP = Div(p->player->maxHP * p->prevEne, p->player->maxEne);
    if (p->targetHP == 0 && p->prevEne != 0) {
      p->targetHP = 1;
    }
    p->targetEne = Div(p->player->maxEne * p->prevHP, p->player->maxHP);
    if (p->targetEne == 0 && p->prevHP != 0) {
      p->targetEne = 1;
    }
    p->helperChara = 0;
  } else {
    p->pendingCard = 2;
    p->prevHP = p->player->hp;
    p->prevEne = p->player->ene;
    p->targetHP = 0;
    p->targetEne = p->player->maxEne;
    p->helperChara = 1;
  }
  PlaySound_082406e0(SE_SWAP_SLOT);
  MainMenu_SetState(p, FUN_08093580, TRUE);
}

// 8 フレーム待ってから回復音を鳴らし, HP を目標値まで動かす状態へ移る
void FUN_08093580(MainMenu* p) {
  if (MainMenu_UpdateItemMove(p, 0) && ++p->stateTimer > 7) {
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    MainMenu_StartPlttFade(p, 289, MainMenu_GetPlayerPlttID(p), 16);
    PlaySound_082406e0(SE_HEAL);
    if (p->helperChara == 0) {
      MainMenu_SetState(p, FUN_08093710, TRUE);
    } else {
      MainMenu_SetState(p, MainMenu_StateApproachHPEne, TRUE);
    }
  }
}

// HP と Ene を最大値の 1/120 ずつ targetHP / targetEne へ近づけ, 両方そろったらアイテムの効果を適用して道具ページへ戻る
void MainMenu_StateApproachHPEne(MainMenu* p) {
  u16* timer = &p->stateTimer;
  s32 done;
  s32 step;

  if (*timer == 0) {
    PlaySound_082406e0(SONG_601);
    (*timer)++;
  }

  done = 0;
  step = Div(p->player->maxHP, 120);
  if (step == 0) {
    step = 1;
  }
  if (p->player->hp > p->targetHP + step) {
    p->player->hp -= step;
  } else if (p->player->hp < p->targetHP - step) {
    p->player->hp += step;
  } else {
    p->player->hp = p->targetHP;
    done = 1;
  }

  step = Div(p->player->maxEne, 120);
  if (step == 0) {
    step = 1;
  }
  if (p->player->ene > p->targetEne + step) {
    p->player->ene -= step;
  } else if (p->player->ene < p->targetEne - step) {
    p->player->ene += step;
  } else {
    p->player->ene = p->targetEne;
    done++;
  }

  MainMenu_DrawHPGauge(p, 1, 5, 3);
  MainMenu_DrawEneGauge(p, 1, 5, 4);
  if (done > 1) {
    sound_08240740(SONG_601);
    MainMenu_ApplyItemEffect(p, p->cursor.savedSlot);
    MainMenu_ReturnToItemPage(p);
  }
}

// 使用前と使用後の HP/Ene を交互に見せて点滅させ, 56 フレームでアイテムの効果を適用する
void FUN_08093710(MainMenu* p) {
  if (p->stateTimer > 16) {
    MainMenu_UpdatePlttFade(p);
  }
  if ((p->stateTimer & 7) < 7 - (p->stateTimer >> 3)) {
    p->player->hp = p->prevHP;
    p->player->ene = p->prevEne;
  } else {
    p->player->hp = p->targetHP;
    p->player->ene = p->targetEne;
  }
  MainMenu_DrawHPGauge(p, 1, 5, 3);
  MainMenu_DrawEneGauge(p, 1, 5, 4);
  if (++p->stateTimer > 55) {
    MainMenu_ApplyItemEffect(p, p->cursor.savedSlot);
    MainMenu_ReturnToItemPage(p);
  }
}

// アイテムを使う演出を始める, アイコンを使う先へ飛ばし, 出てくるキャラを決める
void MainMenu_BeginUseItem(MainMenu* p) {
  Vec3 from, to;

  p->sprites[p->cursor.savedSlot + 17].flags |= SPRFLAG_HIDDEN;
  MainMenu_GetSlotPos(&from, p->cursor.savedSlot);
  MainMenu_GetSlotPos(&to, p->cursor.slot);
  MainMenu_BeginItemMove(p, 0, GetItemID(p->inValuableInventory, p->cursor.savedSlot) + 104, p->sprites[p->cursor.savedSlot + 17].plttID, &from, &to, 24, 16);
  PlaySound_082406e0(SE_SWAP_SLOT);
  if (p->player->kind == PLAYER_SABATA) {
    p->helperChara = 1;
  } else if (Mod(Random(), 100) < 20) {
    p->helperChara = 1;
  } else {
    p->helperChara = 0;
  }
  MainMenu_SetState(p, FUN_080938d0, TRUE);
}

void FUN_080938d0(MainMenu* p) {
  if (MainMenu_UpdateItemMove(p, 0) && ++p->stateTimer > 7) {
    u16 animIdx, playMode, pltt;
    MainSprite* sprite;

    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    MainMenu_StartPlttFade(p, 289, MainMenu_GetPlayerPlttID(p), 16);
    if (p->helperChara == 0) {
      animIdx = 13;
      playMode = PLAYMODE_ONCE_AND_STOP;
      pltt = 749;
    } else {
      animIdx = 0;
      playMode = PLAYMODE_LOOP;
      pltt = 750;
    }
    sprite = &p->sprites[58];
    MainSprite_SetAnim(sprite, &(&p->gfx.rita)[p->helperChara], animIdx, playMode, 4);
    MainSprite_SetPltt(sprite, pltt);
    PlaySound_082406e0(SE_HEAL);
    MainMenu_SetState(p, FUN_08093990, TRUE);
  }
}

// sprites[58] のキャラクターを点滅させながらアニメを進め, 56 フレームで FUN_08093a54 へ移る
void FUN_08093990(MainMenu* p) {
  if (p->stateTimer > 7) {
    MainMenu_UpdatePlttFade(p);
  }
  if (p->helperChara == 0) {
    if (p->stateTimer > 9) {
      MainSprite_AdvanceAnim(&p->sprites[58], &(&p->gfx.rita)[p->helperChara]);
    }
  } else {
    MainSprite_AdvanceAnim(&p->sprites[58], &(&p->gfx.rita)[p->helperChara]);
  }
  if ((p->stateTimer & 7) < 7 - (p->stateTimer >> 3)) {
    p->sprites[58].flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprites[58].flags &= ~SPRFLAG_HIDDEN;
  }
  if (++p->stateTimer > 55) {
    MainMenu_SetState(p, FUN_08093a54, TRUE);
  }
}

// Ene を最大値の 1/120 ずつ満タンまで増やし, 満タンになったら FUN_08093b20 へ移る
void FUN_08093a54(MainMenu* p) {
  bool32 done;
  s32 step;
  s32 ene;

  MainSprite_AdvanceAnim(&p->sprites[58], &(&p->gfx.rita)[p->helperChara]);
  done = FALSE;
  step = Div(p->player->maxEne, 120);
  if (step <= 0) {
    step = 1;
  }
  ene = p->player->ene + step;
  if (ene >= p->player->maxEne) {
    p->player->ene = p->player->maxEne;
    done = TRUE;
  } else {
    if (p->stateTimer == 0) {
      PlaySound_082406e0(SONG_601);
      p->stateTimer++;
    }
    p->player->ene = ene;
  }
  MainMenu_DrawEneGauge(p, 1, 5, 4);
  if (done) {
    if (p->stateTimer != 0) {
      sound_08240740(SONG_601);
    }
    MainMenu_SetState(p, FUN_08093b20, TRUE);
  }
}

void FUN_08093b20(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[58], &(&p->gfx.rita)[p->helperChara]);
  if ((p->stateTimer & 7) < 7 - (p->stateTimer >> 3)) {
    p->sprites[58].flags &= ~SPRFLAG_HIDDEN;
  } else {
    p->sprites[58].flags |= SPRFLAG_HIDDEN;
  }
  if (++p->stateTimer > 55) {
    MainMenu_ConsumeItem(p, p->cursor.savedSlot);
    MainMenu_ReturnToItemPage(p);
  }
}

void FUN_08093bb4(MainMenu* p) {
  Vec3 from, to;

  MessageWindow_Close();
  Marquee_Clear();
  Marquee_RequestClose();
  p->sprites[p->cursor.savedSlot + 17].flags |= SPRFLAG_HIDDEN;
  MainMenu_GetSlotPos(&from, p->cursor.savedSlot);
  MainMenu_GetSlotPos(&to, p->cursor.slot);
  MainMenu_BeginItemMove(p, 0, GetItemID(p->inValuableInventory, p->cursor.savedSlot) + 104, p->sprites[p->cursor.savedSlot + 17].plttID, &from, &to, 24, 16);
  PlaySound_082406e0(SE_SWAP_SLOT);
  MainMenu_SetState(p, FUN_08093c64, TRUE);
}

void FUN_08093cc8(MainMenu* p);

void FUN_08093c64(MainMenu* p) {
  if (MainMenu_UpdateItemMove(p, 0)) {
    p->stateTimer++;
    if (p->stateTimer > 7) {
      PlaySound_082406e0(SE_HEAL);
      p->sprites[46].flags |= SPRFLAG_HIDDEN;
      MainMenu_ApplyItemEffect(p, p->cursor.savedSlot);
      MainMenu_SetState(p, FUN_08093cc8, 1);
    }
  }
}

void FUN_08093cc8(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    MessageWindow_Start(p->itemNames);
    MessageWindow_SetInstant(TRUE);
    MessageWindow_SetRect(0, 16, 30, 4);
    MessageWindow_ShowLine(259);
  }

  ++*timer;
  if (*timer >= 90 || (*timer >= 16 && (gInput[0].pressed & A_BUTTON))) {
    MessageWindow_SetRect(0, 16, 30, 2);
    MainMenu_ReturnToItemPage(p);
  }
}

void FUN_08093d38(MainMenu* p) {
  Vec3 from, to;

  MessageWindow_Close();
  Marquee_Clear();
  Marquee_RequestClose();
  p->sprites[p->cursor.savedSlot + 17].flags |= SPRFLAG_HIDDEN;
  MainMenu_GetSlotPos(&from, p->cursor.savedSlot);
  MainMenu_GetSlotPos(&to, p->cursor.slot);
  MainMenu_BeginItemMove(p, 0, GetItemID(p->inValuableInventory, p->cursor.savedSlot) + 104, p->sprites[p->cursor.savedSlot + 17].plttID, &from, &to, 24, 16);
  PlaySound_082406e0(SE_SWAP_SLOT);
  MainMenu_SetState(p, FUN_08093de8, TRUE);
}

void FUN_08093e4c(MainMenu* p);

void FUN_08093de8(MainMenu* p) {
  if (MainMenu_UpdateItemMove(p, 0)) {
    p->stateTimer++;
    if (p->stateTimer > 7) {
      p->sprites[46].flags |= SPRFLAG_HIDDEN;
      MainMenu_ApplyItemEffect(p, p->cursor.savedSlot);
      MainMenu_SetState(p, FUN_08093e4c, 1);
      PlaySound_082406e0(SE_HEAL);
    }
  }
}

// 装備中の武器の欄と道具の説明 260 行目を出し, 90 フレームか A で道具ページへ戻る
void FUN_08093e4c(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    WeaponData w;

    MessageWindow_Close();
    MessageWindow_SetRect(0, 18, 30, 2);
    GetWeaponData(REGISTERED_WEAPON(gStat->equippedWeaponIdx), &w);
    TextPanel_SetRect(p->textPanelID, 0, 16, 30, 2);
    TextPanel_SetScript(p->textPanelID, p->weaponNames);
    FUN_08094d30(p->textPanelID, (u8*)&w, (s8*)p->unk_9e4);
    TextPanel_Start(p->textPanelID);
  }
  if (*timer == 8) {
    MessageWindow_Start(p->itemNames);
    MessageWindow_SetInstant(TRUE);
    MessageWindow_ShowLine(260);
  }
  if (++*timer > 89 || (*timer > 15 && (gInput[0].pressed & A_BUTTON))) {
    TextPanel_Hide(p->textPanelID);
    MessageWindow_SetRect(0, 16, 30, 2);
    MainMenu_ReturnToItemPage(p);
  }
}

// 道具ページで選んだ道具を使う, 効果の種類ごとに演出の状態へ移るか, その場で効果を適用する
// 残差: 86/86 命令, IET_WARP と IET_BUGS/IET_AOE の末尾で &cursor.savedSlot を作るレジスタが r1 と r2 で逆になる (IET_BUGS と IET_AOE を別 case に分けるのは試済)
NON_MATCH void MainMenu_UseItem(MainMenu* p) {
#ifdef NONMATCHING_C
  item32_t id = GetItemID(p->inValuableInventory, p->cursor.savedSlot);

  switch (gItemDB[id].effectType) {
    case IET_HP:
    case IET_MP:
    case IET_BAD_STATUS:
    case IET_GOOD:
    case IET_LOAN: {
      MainMenu_StartItemMove(p);
      break;
    }
    case IET_VITAMINS: {
      PlaySound_082406e0(SE_SWAP_SLOT);
      FUN_08092a94(p);
      break;
    }
    case IET_WARP: {
      PlaySound_082406e0(SE_HEAL);
      if (id == ITEM_WARP_LEAF) {
        PlaySound_082406e0(SONG_386);
      }
      MainMenu_ApplyItemEffect(p, p->cursor.savedSlot);
      MainMenu_ReturnToItemPage(p);
      break;
    }
    case IET_SOLAR: {
      if (gItemDB[id].value1 == 2) {
        MainMenu_BeginThrowGeta(p);
      } else {
        FUN_08092c7c(p, gItemDB[id].value1);
      }
      break;
    }
    case IET_HPMP: {
      MainMenu_BeginHPMPCard(p, gItemDB[id].value1);
      break;
    }
    case IET_LOVER: {
      MainMenu_BeginUseItem(p);
      break;
    }
    case IET_BUGS:
    case IET_AOE: {
      PlaySound_082406e0(SE_HEAL);
      MainMenu_ApplyItemEffect(p, p->cursor.savedSlot);
      MainMenu_ReturnToItemPage(p);
      break;
    }
    case IET_REFRESH: {
      PlaySound_082406e0(SE_SWAP_SLOT);
      FUN_08093bb4(p);
      break;
    }
    case IET_REPAIR: {
      PlaySound_082406e0(SE_SWAP_SLOT);
      FUN_08093d38(p);
      break;
    }
    case IET_UNK15: {
      break;
    }
  }
#else
  INCFUNC("asm/func/MainMenu_UseItem.inc");
#endif
}

// 道具ページの基本状態, SELECT で HP/Ene の数値表示, A で道具を選んで操作の選択へ (枠 21 なら整頓の確認), 十字キーでカーソルを動かす
void MainMenu_StateItemPage(MainMenu* p) {
  u16 select;

  FUN_0808c548(p);
  select = gInput[0].down & SELECT_BUTTON;
  if (select) {
    p->hidden = TRUE;
    MainMenu_HideButtonGuides(p);
    MainSprite_SetPose(&p->sprites[13], &p->gfx.smenu, 56, PLAYMODE_LOOP);
    MainMenu_DrawHP(p, 1, 5, 3);
    MainMenu_DrawEne(p, 1, 5, 4);
  } else {
    p->hidden = FALSE;
    MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
    MainMenu_DrawHPGauge(p, 1, 5, 3);
    MainMenu_DrawEneGauge(p, 1, 5, 4);
    MainMenu_UpdateItemButtonGuides(p, 0);
    if (gInput[0].pressed & A_BUTTON) {
      PlaySound_082406e0(SE_SELECT);
      InventoryCursor_SavePos(&p->cursor);
      p->sprites[14].flags &= ~SPRFLAG_HIDDEN;
      MainMenu_GetSlotPos(&p->sprites[14].pos, p->cursor.savedSlot);
      if (p->cursor.slot == 21) {
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        p->sprites[45].flags |= SPRFLAG_HIDDEN;
        MainMenu_ShowBottomLine(p->etcTexts, 4, 0);
        MainMenu_ShowYesNo(p, 1);
        MainMenu_HideButtonGuides(p);
        MainMenu_SetState(p, MainMenu_StateConfirmSortItems, TRUE);
      } else {
        InventoryCursor_ResetSlotmap(&p->cursor, FUN_080925d4(GetItemID(p->inValuableInventory, p->cursor.savedSlot)));
        MainMenu_UpdateItemButtonGuides(p, 1);
        MainMenu_SetState(p, MainMenu_StateItemPickTarget, TRUE);
      }
    } else if (InventoryCursor_Move(&p->cursor)) {
      MainMenu_GetSlotPos(&p->sprites[13].pos, p->cursor.slot);
      MainMenu_ShowCursorItemInfo(p);
    }
  }
}

// 道具ページで選んだ道具の行き先を選ぶ状態, A で使う / 捨てる / 入れ替えへ, SELECT で捨てる確認, B で戻る
void MainMenu_StateItemPickTarget(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
  FUN_0808c548(p);
  if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_ReturnToItemPage(p);
  } else if ((gInput[0].pressed & SELECT_BUTTON) && (p->cursor.flags & 0x10)) {
    p->sprites[34].flags &= ~SPRFLAG_HIDDEN;
    MainMenu_GetSlotPos(&p->sprites[13].pos, 20);
    MainSprite_SetPose(&p->sprites[13], &p->gfx.smenu, 56, PLAYMODE_LOOP);
    p->sprites[45].flags |= SPRFLAG_HIDDEN;
    MainMenu_ShowBottomLine(p->etcTexts, 2, 1);
    MainMenu_ShowYesNo(p, 0);
    MainMenu_HideButtonGuides(p);
    MainMenu_SetState(p, FUN_0809458c, TRUE);
  } else if (gInput[0].pressed & A_BUTTON) {
    MainMenu_HideButtonGuides(p);
    switch (MainMenu_GetItemAction(p)) {
      case 2: {
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        p->sprites[45].flags |= SPRFLAG_HIDDEN;
        MainMenu_ShowBottomLine(p->etcTexts, 2, 1);
        MainMenu_ShowYesNo(p, 0);
        MainMenu_SetState(p, FUN_0809458c, TRUE);
        break;
      }
      case 1: {
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        p->sprites[45].flags |= SPRFLAG_HIDDEN;
        MainMenu_ShowBottomLine(p->etcTexts, 3, 1);
        MainMenu_ShowYesNo(p, FUN_080921a8(p));
        MainMenu_SetState(p, FUN_0809455c, TRUE);
        break;
      }
      case 3: {
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        PlaySound_082406e0(SE_SWAP_SLOT);
        if (GetItemID(p->inValuableInventory, p->cursor.savedSlot) >= 0) {
          FUN_08092300(p, 0, p->cursor.savedSlot, p->cursor.slot);
        }
        if (GetItemID(p->inValuableInventory, p->cursor.slot) >= 0) {
          FUN_08092300(p, 1, p->cursor.slot, p->cursor.savedSlot);
        }
        p->sprites[17 + p->cursor.savedSlot].flags |= SPRFLAG_HIDDEN;
        p->sprites[17 + p->cursor.slot].flags |= SPRFLAG_HIDDEN;
        MainMenu_SetState(p, MainMenu_StateSwapItem, TRUE);
        break;
      }
      case 0:
      default: {
        PlaySound_082406e0(SE_NG);
        break;
      }
    }
  } else if (InventoryCursor_Move(&p->cursor)) {
    MainMenu_GetSlotPos(&p->sprites[13].pos, p->cursor.slot);
    MainMenu_ShowCursorItemInfo(p);
    MainMenu_UpdateItemButtonGuides(p, 1);
  }
}

void FUN_08094440(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
  p->sprites[34].flags |= SPRFLAG_HIDDEN;
  if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_DRUMROLL);
    MainMenu_GetSlotPos(&p->sprites[13].pos, p->cursor.slot);
    MainMenu_ShowCursorItemInfo(p);
    MainMenu_SetState(p, MainMenu_StateItemPickTarget, TRUE);
  } else if (gInput[0].pressed & A_BUTTON) {
    p->sprites[13].flags |= SPRFLAG_HIDDEN;
    p->sprites[45].flags |= SPRFLAG_HIDDEN;
    MainMenu_ShowBottomLine(p->etcTexts, 2, TRUE);
    MainMenu_ShowYesNo(p, 0);
    MainMenu_SetState(p, FUN_0809458c, TRUE);
  }
}

void MainMenu_StateConfirmSortItems(MainMenu* p) {
  s32 result = MainMenu_UpdateYesNo(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_ReturnToItemPage(p);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    if (!p->inValuableInventory) {
      SortInventory(0);
    } else {
      SortValuable(0);
    }
    p->cursor.savedCol = 0;
    p->cursor.savedRow = 0;
    p->cursor.savedSlot = 0;
    MainMenu_ReturnToItemPage(p);
  }
}

// はい/いいえの選択結果で、決定なら効果音を鳴らして次へ進み、キャンセルならテキストボックスを閉じる
void FUN_0809455c(MainMenu* p) {
  s32 v = MainMenu_UpdateYesNo(p);

  if (v == 0) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_ReturnToItemPage(p);
  } else if (v == 1) {
    MessageWindow_Close();
    MainMenu_UseItem(p);
  }
}

void FUN_080945f4(MainMenu* p);

void FUN_0809458c(MainMenu* p) {
  s32 result = MainMenu_UpdateYesNo(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_ReturnToItemPage(p);
  } else if (result == 1) {
    p->sprites[13].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    FUN_08092300(p, 0, p->cursor.savedSlot, 20);
    MainMenu_ConsumeItem(p, p->cursor.savedSlot);
    MainMenu_RefreshItemIcons(p);
    MainMenu_SetState(p, FUN_080945f4, 1);
  }
}

void MainMenu_StateItemTrashShake(MainMenu* p);

// 12フレームかけて46番のスプライトを退避先へ寄せ, 着いたら隠して次の状態へ移る
void FUN_080945f4(MainMenu* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_SWAP_SLOT);
  }

  p->stateTimer++;
  if (p->stateTimer <= 11) {
    FUN_0808ba20(&p->sprites[46].pos, p->unk_3b68, 12 - p->stateTimer);
  } else {
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    MainMenu_SetState(p, MainMenu_StateItemTrashShake, 1);
  }
}

// 道具を捨てたあと, 捨てる音を鳴らしてゴミ箱 (sprites[33]) を揺らし, 道具ページに戻す
void MainMenu_StateItemTrashShake(MainMenu* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_TRASH);
  }
  if (++p->stateTimer < 12) {
    if ((p->stateTimer >> 1) & 1) {
      p->sprites[33].pos.y = 70;
    } else {
      p->sprites[33].pos.y = 70 - ((20 - p->stateTimer) >> 3);
    }
  } else if (p->stateTimer < 16) {
    p->sprites[33].pos.y = 70;
  } else {
    MainMenu_ReturnToItemPage(p);
  }
}

// 入れ替える2つの道具アイコンを互いの枠へ動かし, 着いたら実際に入れ替える
void MainMenu_StateSwapItem(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    PlaySound_082406e0(SE_SWAP_SLOT);
  }

  if (++*timer < 12) {
    s32 weight = 12 - *timer;

    FUN_0808ba20(&p->sprites[46].pos, p->unk_3b68, weight);
    FUN_0808ba20(&p->sprites[47].pos, p->unk_3b70, weight);
  } else {
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    p->sprites[47].flags |= SPRFLAG_HIDDEN;
    MainMenu_SwapItemSlot(p, p->cursor.savedSlot, p->cursor.slot);
    MainMenu_ReturnToItemPage(p);
  }
}

void FUN_08094780(MainMenu* p) {
  FUN_0808b8a4(p);
  MainMenu_RefreshItemIcons(p);
  if (!p->inValuableInventory) {
    p->sprites[33].flags &= ~SPRFLAG_HIDDEN;
    if (p->cursor.flags & 0x10) {
      MainSprite_SetPltt(&p->sprites[33], 735);
    } else {
      MainSprite_SetPltt(&p->sprites[33], 736);
    }
  }
  p->sprites[35].flags &= ~SPRFLAG_HIDDEN;
  if (p->cursor.flags & 0x20) {
    MainSprite_SetPltt(&p->sprites[35], 735);
  } else {
    MainSprite_SetPltt(&p->sprites[35], 736);
  }
  MainMenu_RefreshPlayerFigure(p);
}

void FUN_08094838(MainMenu* p, s32 _) {
  Vec3* pos;
  u8* slot;

  InventoryCursor_ResetSlotmap(&p->cursor, 32);
  InventoryCursor_SetPos(&p->cursor, 0, 0);
  pos = &p->sprites[13].pos;
  slot = (u8*)&p->cursor.slot;
  MainMenu_GetSlotPos(pos, *slot);
  p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[13], &p->gfx.smenu, 0, PLAYMODE_LOOP, 0);
  MainMenu_GetSlotPos(pos, *slot);
}

void MainMenu_InitPage_Item(MainMenu* p) {
  p->inValuableInventory = FALSE;
  TextPanel_Hide(p->textPanelID_4014);
  TextPanel_Hide(p->textPanelID);
  MessageWindow_SetRect(2, 16, 28, 2);
  FUN_0808a3c4(p, p->tm_18, 0, 6, p->bgp_30);
  MainMenu_DrawEquipStats(p, 5, 3);
  MainMenu_DrawMoney(p);
  FUN_0808b82c(p);
  MainMenu_ShowPageName(p, p->page);
  p->sprites[16].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[16], &p->gfx.smenu, 157, PLAYMODE_LOOP);
  FUN_08094838(p, 0);
  FUN_08094780(p);
  MainMenu_ShowCondIcons(p);
  FUN_08049f5c();
  MainMenu_ShowCursorItemInfo(p);
  FUN_0808c61c(p, 0, 0);
  MainMenu_UpdateItemButtonGuides(p, 0);
  MainMenu_SetState(p, MainMenu_StateItemPage, FALSE);
}

void FUN_08094988(void) {
  s32 i;

  for (i = 0; i < 3; i++) {
    *MainMenu_GetBgMapAddr(0, i + 14, 8) = 0xF001;
  }
}

void MainMenu_InitPage_Valuable(MainMenu* p) {
  TextPanel_Hide(p->textPanelID_4014);
  TextPanel_Hide(p->textPanelID);
  p->inValuableInventory = TRUE;
  MessageWindow_SetRect(2, 16, 28, 2);
  FUN_0808a3c4(p, p->tm_18, 0, 6, p->bgp_30);
  FUN_08094988();
  MainMenu_DrawEquipStats(p, 5, 3);
  MainMenu_DrawMoney(p);
  FUN_0808b82c(p);
  MainMenu_ShowPageName(p, p->page);
  p->sprites[16].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[16], &p->gfx.smenu, 160, PLAYMODE_LOOP);
  FUN_08094838(p, 0);
  FUN_08094780(p);
  FUN_08049f5c();
  MessageWindow_SetBgPltt(BGP_EFDA);
  MainMenu_ShowCursorItemInfo(p);
  FUN_0808c61c(p, 0, 0);
  MainMenu_UpdateItemButtonGuides(p, 0);
  MainMenu_SetState(p, MainMenu_StateItemPage, FALSE);
}

// 武器ページで武器を選んだ後のカーソル枠表を作る, permission の bit0〜3 で装備できる登録枠 16〜19 を右側に並べ, 無い枠は隣の枠で埋める
// 残差: 218/225 命令, InventoryCursor_ResetSlotmap と同じ 4x4 の値の誘導変数の壁に加え, 原典は &cursor や slotmap の各位置をスタックに逃がして持つ
NON_MATCH void MainMenu_ResetWeaponTargetCursor(MainMenu* p, u32 permission) {
#ifdef NONMATCHING_C
  InventoryCursor* c = &p->cursor;
  s32 targets[4];
  s32 i, j, k;

  if (p->player->kind == PLAYER_SABATA) {
    c->flags = 0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 9; j++) {
        INVENTORY_SLOT(c, j, i) |= 0xFF;
      }
    }
    INVENTORY_SLOT(c, 0, 0) = 0;
    return;
  }

  c->flags = permission;
  for (i = 0; i < 4; i++) {
    for (j = 3; j >= 0; j--) {
      INVENTORY_SLOT(c, j, i) = i * 4 + j;
    }
  }
  for (k = 0; k < 4; k++) {
    if ((permission >> k) & 1) {
      targets[k] = k + 16;
    } else {
      targets[k] = -1;
    }
  }
  for (k = 0; k < 4; k++) {
    if (targets[k] >= 0 && targets[(k + 2) & 3] < 0) {
      targets[(k + 2) & 3] = targets[k];
    }
  }
  for (k = 0; k < 4; k++) {
    if (targets[k] >= 0 && targets[(k >> 1) * 2 + ((k + 1) & 1)] < 0) {
      targets[(k >> 1) * 2 + ((k + 1) & 1)] = targets[k];
    }
  }
  for (k = 0; k < 4; k++) {
    s32 start = (k & 1) * 2;

    if (k < 2) {
      for (i = 0; i < 3; i++) {
        for (j = start; j < start + 2; j++) {
          INVENTORY_SLOT(c, j + 4, i) = targets[k];
        }
      }
    } else {
      for (j = start; j < start + 2; j++) {
        INVENTORY_SLOT(c, j + 4, 3) = targets[k];
      }
    }
  }
  for (i = 0; i < 3; i++) {
    INVENTORY_SLOT(c, 8, i) |= 0xFF;
  }
  INVENTORY_SLOT(c, 8, 3) = permission & 0x20 ? 21 : 0xFF;
#else
  INCFUNC("asm/func/MainMenu_ResetWeaponTargetCursor.inc");
#endif
}

// 武器名の後ろに付ける文字列を作る, 品質があれば "+N" か "-N", 特殊効果があれば "SP", どちらもなければ空
void WeaponData_FormatSuffix(WeaponData* w, s8* text) {
  if (w->quality != 0) {
    s32 value;
    s32 tens;
    s32 ones;

    if (w->quality > 0) {
      *text = '+';
    } else {
      *text = '-';
    }
    value = abs(w->quality);
    tens = Div(value, 10);
    ones = value - tens * 10;
    text[1] = tens + '0';
    text[2] = ones + '0';
    text[3] = '\0';
  } else if (*(u8*)&w->effects[0] != 0 || *(u8*)&w->effects[1] != 0 || *(u8*)&w->effects[2] != 0) {
    text[0] = 'S';
    text[1] = 'P';
    text[2] = '\0';
  } else {
    text[0] = '\0';
  }
}

void FUN_08094cdc(s32 usePanel, s32 panelID, u8* param_3, s8* param_4) {
  WeaponData_FormatSuffix((WeaponData*)param_3, param_4);

  if (usePanel) {
    TextPanel_SetMessage(panelID, param_3[0]);
    FUN_0804a40c(panelID, 0, (char*)param_4);
  } else {
    MessageWindow_ShowLine(param_3[0]);
    MessageWindow_SetExtendValue(0, (char*)param_4);
  }
}

void FUN_08094d1c(u8* param_1, s8* param_2) { FUN_08094cdc(0, -1, param_1, param_2); }

void FUN_08094d30(s32 param_1, u8* param_2, s8* param_3) { FUN_08094cdc(1, param_1, param_2, param_3); }

// 武器説明のマーキーを組み立てる, レベルと攻撃力, 武器名, 特殊効果名 (最大3つ), PS の順に並べる
// 残差: 130/128 命令, 原典は効果名の ID を (効果 + 66) + top の順に作るが, こちらは top = base + 66 を見抜かれて base + 132 + 効果 に畳まれ, w と n のレジスタも入れ替わる (top を使わない形, 足す順の入れ替えは試済)
NON_MATCH void MainMenu_SetWeaponMarquee(WeaponData* w, u8* pc) {
#ifdef NONMATCHING_C
  s32 base = VM_ParseStringRef(pc);
  s32 top = base + 66;
  s32 n;
  s32 i;

  if (w->lv != 0) {
    Marquee_SetVarValue(0, w->lv);
  }
  Marquee_SetVarValue(1, w->atk);
  Marquee_SetText(GetStringByID(top + w->id));

  n = 0;
  if ((u8)w->effects[0] != 0) {
    Marquee_SetExtendValue(n, GetStringByID(top + ((u8)w->effects[0] + 66)));
  } else {
    Marquee_SetExtendValue(n, GetStringByID(base + 132));
  }
  n++;
  for (i = 1; i < 3; i++) {
    if ((u8)w->effects[i] != 0) {
      Marquee_SetExtendValue(n, GetStringByID(top + ((u8)w->effects[i] + 66)));
      n++;
    }
  }

  if (w->PS[0] == 0) {
    gWeaponPSText[0] = '\0';
  } else {
    s32 k = 0;

    for (i = 0; i < 12 && w->PS[i] != '\0'; i++) {
      gWeaponPSText[k++] = w->PS[i];
    }
    gWeaponPSText[k++] = 0x81;
    gWeaponPSText[k++] = 0x0F;
    gWeaponPSText[k++] = 0x80;
    gWeaponPSText[k++] = 0x56;
    gWeaponPSText[k] = '\0';
  }
  Marquee_SetExtendValue(n, gWeaponPSText);

  for (i = n + 1; i < 4; i++) {
    Marquee_SetExtendValue(i, GetStringByID(top + 66));
  }
#else
  INCFUNC("asm/func/MainMenu_SetWeaponMarquee.inc");
#endif
}

// 武器アイコンの絵柄番号を損耗度から決める, 特殊効果が付いているものは目減りが遅い
s32 GetWeaponWearPose(WeaponData* w) {
  s32 n;

  if (w->quality > 0) {
    n = Div(w->wear * 4, 200);
    if (n > 3) {
      n = 3;
    }
    return ICON_TIMER_100 + n;
  }

  if (*(u8*)&w->effects[2] != 0 || *(u8*)&w->effects[1] != 0) {
    n = Div(w->wear * 4, 2000);
    if (n > 3) {
      n = 3;
    }
    return ICON_TIMER_100 + n;
  }
  return ICON_TIMER_NONE;
}

void MainMenu_ShowCursorWeaponInfo(MainMenu* p) {
  WeaponData w;

  if (p->cursor.slot > 15) {
    p->sprites[45].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    Marquee_Clear();
  } else {
    if (p->player->kind == PLAYER_SABATA) {
      BuildWeaponData(&p->weapon, &w);
    } else {
      GetWeaponData(p->cursor.slot, &w);
    }
    if (w.id == WEAPON_NONE) {
      p->sprites[45].flags |= SPRFLAG_HIDDEN;
      MessageWindow_Close();
      Marquee_Clear();
    } else {
      p->sprites[45].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetPose(&p->sprites[45], &p->gfx.icons, GetWeaponWearPose(&w), PLAYMODE_LOOP);
      MessageWindow_SetInstant(TRUE);
      MessageWindow_Start(p->weaponNames);
      MessageWindow_SetRect(2, 16, 28, 2);
      FUN_08094d1c((u8*)&w, (s8*)p->unk_9e4);
      MainMenu_SetWeaponMarquee(&w, p->weaponNames);
    }
  }
}

// 武器ページで登録枠4つの攻撃力を出し, カーソルの武器に替えたときに変わる枠だけ上がるか下がるかの色で数字を重ねる
// 残差: 390/382 命令, 原典は桁のスプライトを並べる pos をスタックに置いて色 +10 をループ外で作り, 色と次の i をレジスタに持つが, こちらは pos をレジスタに持って色をスタックへ逃がす (局所変数の宣言順, pos の宣言位置は試済)
NON_MATCH void MainMenu_DrawWeaponPreview(MainMenu* p) {
#ifdef NONMATCHING_C
  WeaponData w;
  s32 i;

  for (i = 0; i < 6; i++) {
    p->sprites[48 + i].flags |= SPRFLAG_HIDDEN;
  }
  if (p->player->kind == PLAYER_SABATA) {
    for (i = 0; i < 4; i++) {
      s32 x = (i & 1) * 6;
      s32 y = (i >> 1) + 5;
      BgMapEntry* map = MainMenu_GetBgMapAddr(0, x + 5, y);

      if (i < 3) {
        s32 j;

        for (j = 0; j < 5; j++) {
          *map++ = 0xF001;
        }
      } else {
        *map = 0xF071;
        MainMenu_DrawNumber(CalcAttackWithEquippedArmor(NULL), 100, x + 7, y, 0);
      }
    }
  } else if (p->cursor.slot > 15) {
    for (i = 0; i < 4; i++) {
      GetRegisteredWeaponData(i, &w);
      if (i == 3 || w.kind != WK_OTHERS) {
        MainMenu_DrawNumber(CalcAttackWithEquippedArmor(&w), 100, (i & 1) * 6 + 7, (i >> 1) + 5, 0);
      } else {
        BgMapEntry* map = MainMenu_GetBgMapAddr(0, (i & 1) * 6 + 5, (i >> 1) + 5);
        s32 j;

        for (j = 0; j < 5; j++) {
          *map++ = 0xF001;
        }
      }
    }
  } else if (GetWeaponID(p->cursor.slot) == WEAPON_NONE) {
    for (i = 0; i < 4; i++) {
      GetRegisteredWeaponData(i, &w);
      if (i == 3 || w.kind != WK_OTHERS) {
        MainMenu_DrawNumber(CalcAttackWithEquippedArmor(&w), 100, (i & 1) * 6 + 7, (i >> 1) + 5, 0);
      } else {
        BgMapEntry* map = MainMenu_GetBgMapAddr(0, (i & 1) * 6 + 5, (i >> 1) + 5);
        s32 j;

        for (j = 0; j < 5; j++) {
          *map++ = 0xF001;
        }
      }
    }
  } else {
    WeaponData reg;
    s32 digits[3];
    s32 atk;
    s32 n;
    s32 target;

    GetWeaponData(p->cursor.slot, &w);
    atk = CalcAttackWithEquippedArmor(&w);
    digits[0] = Div(atk, 100);
    n = atk - digits[0] * 100;
    digits[1] = Div(n, 10);
    n -= digits[1] * 10;
    digits[2] = n;
    switch (w.kind) {
      case WK_SWORD: {
        target = 0;
        break;
      }
      case WK_SPEAR: {
        target = 1;
        break;
      }
      case WK_HAMMER: {
        target = 2;
        break;
      }
      default: {
        target = 3;
        break;
      }
    }
    for (i = 0; i < 4; i++) {
      s32 regAtk;
      s32 x;
      s32 y;
      bool32 changed;
      s32 color;

      GetRegisteredWeaponData(i, &reg);
      regAtk = CalcAttackWithEquippedArmor(&reg);
      x = (i & 1) * 6 + 7;
      y = (i >> 1) + 5;
      MainMenu_DrawNumber(regAtk, 100, x, y, 0);
      if (i == 3) {
        BgMapEntry* map = MainMenu_GetBgMapAddr(0, 11, 6);

        if (reg.kind == WK_GUN) {
          *map = 0xF071;
        } else {
          *map = 0xF070;
        }
      } else if (reg.kind == WK_OTHERS) {
        BgMapEntry* map = MainMenu_GetBgMapAddr(0, (i & 1) * 6 + 5, y);
        s32 j;

        for (j = 0; j < 5; j++) {
          *map++ = 0xF001;
        }
      }
      changed = FALSE;
      color = 0;
      if (i == target && atk != regAtk) {
        changed = TRUE;
        color = 10;
        if (atk > regAtk) {
          color = 0;
        }
      }
      if (changed) {
        Vec3 pos;
        s32 j;

        FUN_0808b97c(x, y, 3, 1);
        pos.x = x * 8;
        pos.y = y * 8;
        for (j = 0; j < 3; j++) {
          p->sprites[48 + j].flags &= ~SPRFLAG_HIDDEN;
          p->sprites[48 + j].pos = pos;
          MainSprite_SetPose(&p->sprites[48 + j], &p->gfx.smenu, digits[j] + color + 10, PLAYMODE_LOOP);
          pos.x += 8;
        }
      }
    }
  }
#else
  INCFUNC("asm/func/MainMenu_DrawWeaponPreview.inc");
#endif
}

// インベントリのスロット番号から画面上のカーソル位置を引く, 0..15 は 4x4 の升目, 16 以降は装備欄
void GetInventorySlotPos(Vec3* pos, s32 slot) {
  if (slot < 16) {
    pos->x = (slot & 3) * 24 + 144;
    pos->y = (slot >> 2) * 24 + 32;
  } else if (slot == 21) {
    pos->x = 120;
    pos->y = 104;
  } else if (slot == 20) {
    pos->x = 117;
    pos->y = 70;
  } else if (slot == 16) {
    pos->x = 64;
    pos->y = 76;
  } else if (slot == 17) {
    pos->x = 88;
    pos->y = 76;
  } else if (slot == 18) {
    pos->x = 64;
    pos->y = 104;
  } else if (slot == 19) {
    pos->x = 88;
    pos->y = 104;
  } else {
    pos->x = 144;
    pos->y = 32;
  }
}

// 武器ページの16枠のアイコンを描き, 装備できない武器 (レベル不足や壊れた銃など) は暗い色にする
void MainMenu_RefreshWeaponIcons(MainMenu* p) {
  s32 i;

  if (p->player->kind == PLAYER_SABATA) {
    p->sprites[17].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[17], &p->gfx.icons, 60, PLAYMODE_LOOP);
    MainSprite_SetPltt(&p->sprites[17], 735);
    for (i = 0; i < 15; i++) {
      p->sprites[18 + i].flags |= SPRFLAG_HIDDEN;
    }
    return;
  }

  for (i = 0; i < 16; i++) {
    weapon32_t id = GetWeaponID(i);

    if (id == WEAPON_NONE) {
      p->sprites[17 + i].flags |= SPRFLAG_HIDDEN;
    } else {
      p->sprites[17 + i].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetPose(&p->sprites[17 + i], &p->gfx.icons, id, PLAYMODE_LOOP);
      MainSprite_SetPltt(&p->sprites[17 + i], 735);
      if (id == WEAPON_BROKEN_GUN || id == WEAPON_STAR_PIECE) {
        MainSprite_SetPltt(&p->sprites[17 + i], 736);
      } else if (gStat->lv >= gWeaponDB[id].lv) {
        MainSprite_SetPltt(&p->sprites[17 + i], 735);
      } else {
        MainSprite_SetPltt(&p->sprites[17 + i], 736);
      }
    }
  }
}

// 登録武器のアイコン (sprites[36〜39]) と所持品側の目印を描き直す, pickingTarget なら置ける枠だけ明るくする
void MainMenu_RefreshRegisteredWeapons(MainMenu* p, bool32 pickingTarget) {
  s32 i;

  p->sprites[40].flags |= SPRFLAG_HIDDEN;
  for (i = 0; i < 4; i++) {
    p->sprites[36 + i].flags |= SPRFLAG_HIDDEN;
    p->sprites[41 + i].flags |= SPRFLAG_HIDDEN;
  }
  for (i = 0; i < 4; i++) {
    s32 reg = (s8)p->qc.weapons[i].registeredIdx;

    if ((s8)p->qc.weapons[i].inventorySlotIdx >= 0) {
      MainSprite* sprite;

      p->sprites[36 + reg].flags &= ~SPRFLAG_HIDDEN;
      sprite = &p->sprites[36 + reg];
      MainSprite_SetPose(sprite, &p->gfx.icons, p->qc.weapons[i].weapon->id, PLAYMODE_LOOP);
      if (pickingTarget) {
        if ((p->cursor.flags >> i) & 1) {
          MainSprite_SetPltt(sprite, 735);
        } else {
          MainSprite_SetPltt(sprite, 736);
        }
      } else {
        MainSprite_SetPltt(sprite, 735);
      }
      p->sprites[41 + i].flags &= ~SPRFLAG_HIDDEN;
      p->sprites[41 + i].pos = p->sprites[17 + (s8)p->qc.weapons[i].inventorySlotIdx].pos;
    } else if (reg == 3) {
      MainSprite* sprite;

      p->sprites[39].flags &= ~SPRFLAG_HIDDEN;
      sprite = &p->sprites[39];
      MainSprite_SetPose(sprite, &p->gfx.icons, 0, PLAYMODE_LOOP);
      if (pickingTarget) {
        if (p->cursor.flags & 8) {
          MainSprite_SetPltt(sprite, 735);
        } else {
          MainSprite_SetPltt(sprite, 736);
        }
      } else {
        MainSprite_SetPltt(sprite, 735);
      }
    }
    if (i == p->qc.weaponIdx) {
      p->sprites[40].flags &= ~SPRFLAG_HIDDEN;
      p->sprites[40].pos = p->sprites[36 + reg].pos;
    }
  }
}

// 枠 param_3 の武器のアイコンを sprites[46 + idx] に出し, 枠 param_4 へ動かす準備をする
void MainMenu_BeginWeaponIconMove(MainMenu* p, s32 idx, s32 param_3, s32 param_4) {
  MainSprite* sprite = &p->sprites[idx + 46];

  sprite->flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(sprite, &p->gfx.icons, GetWeaponID(param_3), PLAYMODE_LOOP);
  GetInventorySlotPos(&sprite->pos, param_3);
  GetInventorySlotPos((Vec3*)&p->unk_3b68[idx * 4], param_4);
  MainSprite_SetPltt(sprite, p->sprites[param_3 + 17].plttID);
}

// 武器でできる操作のビットを返す, 0x10: 売れる (登録中でなく値段がある), 1/2/4/8: レベルが足りていて種類ごとに装備できる
u32 GetWeaponPermission(MainMenu* p, s32 slot) {
  u32 flags = 0;
  u32 kind = GetWeaponKind(slot);
  weapon32_t id;
  bool32 sellable;
  s32 i;

  if (kind == 3) {
    return 0;
  }
  id = GetWeaponID(slot);
  if (id == WEAPON_BROKEN_GUN || id == WEAPON_STAR_PIECE) {
    return 0;
  }

  sellable = TRUE;
  if (gWeaponDB[id].price == 0) {
    sellable = FALSE;
  } else {
    for (i = 0; i < 4; i++) {
      if (REGISTERED_WEAPON(i) == slot) {
        sellable = FALSE;
      }
    }
  }
  if (sellable) {
    flags |= 0x10;
  }
  if (gStat->lv >= gWeaponDB[id].lv) {
    if (kind == 0) {
      flags |= 1;
    } else if (kind == 1) {
      flags |= 2;
    } else if (kind == 2) {
      flags |= 4;
    } else {
      flags |= 8;
    }
  }
  return flags;
}

// 武器ページのボタン案内を, 入れ替え中かどうかとカーソルの位置で切り替える
// 残差: 141/142 命令, 原典はサバタの判定の前に mode = 0 を置いて beq で switch へ飛び, 3 \/ 0 の三項の分岐の並びも違う (mode の初期化を先に置く形は mode が呼び出しをまたいで r5 に乗るので不可)
NON_MATCH void MainMenu_UpdateWeaponButtonGuides(MainMenu* p, s32 param_2) {
#ifdef NONMATCHING_C
  if (param_2 == 0) {
    if (p->cursor.slot == 21) {
      MainMenu_SetButtonGuides(p, 0, 4);
    } else {
      MainMenu_SetButtonGuides(p, 0, -1);
    }
  } else {
    s32 mode;

    if (p->player->kind == PLAYER_SABATA) {
      mode = 0;
    } else {
      if (GetWeaponID(p->cursor.savedSlot) == WEAPON_NONE) {
        if (p->cursor.slot > 15) {
          mode = 4;
        } else {
          mode = GetWeaponID(p->cursor.slot) != WEAPON_NONE ? 3 : 0;
        }
      } else if (p->cursor.slot <= 15) {
        if (p->cursor.savedSlot == p->cursor.slot) {
          s32 reg;
          s32 i;

          GetWeaponKind(p->cursor.savedSlot);
          reg = -1;
          for (i = 0; i < 4; i++) {
            if (REGISTERED_WEAPON(i) == p->cursor.savedSlot) {
              reg = i;
            }
          }
          if (reg >= 0) {
            mode = reg == 3 ? 4 : 0;
          } else {
            for (i = 0; i < 4; i++) {
              if ((p->cursor.flags >> i) & 1) {
                break;
              }
            }
            mode = i < 4 ? 1 : 0;
          }
        } else {
          mode = 3;
        }
      } else {
        mode = 1;
      }
    }

    switch (mode) {
      case 1: {
        MainMenu_SetButtonGuides(p, 5, -1);
        break;
      }
      case 4: {
        MainMenu_SetButtonGuides(p, 2, -1);
        break;
      }
      case 3: {
        MainMenu_SetButtonGuides(p, 3, -1);
        break;
      }
      default: {
        MainMenu_SetButtonGuides(p, -1, -1);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/MainMenu_UpdateWeaponButtonGuides.inc");
#endif
}

// 武器ページで A を押したときの動作を決める, 0: なし, 1: 登録枠への操作, 2: 枠 20 の確認, 3: 入れ替え, 4: 銃の枠への操作
s32 MainMenu_GetWeaponAction(MainMenu* p) {
  if (p->player->kind == PLAYER_SABATA) {
    return 0;
  } else if (GetWeaponID(p->cursor.savedSlot) == WEAPON_NONE) {
    if (p->cursor.slot <= 15) {
      if (GetWeaponID(p->cursor.slot) == WEAPON_NONE) {
        return 0;
      }
      return 3;
    }
    return 4;
  } else if (p->cursor.slot <= 15) {
    if (p->cursor.savedSlot == p->cursor.slot) {
      s32 reg;
      s32 i;

      GetWeaponKind(p->cursor.savedSlot);
      reg = -1;
      for (i = 0; i < 4; i++) {
        if (REGISTERED_WEAPON(i) == p->cursor.savedSlot) {
          reg = i;
        }
      }
      if (reg >= 0) {
        if (reg == 3) {
          p->cursor.slot = 19;
          return 4;
        } else {
          return 0;
        }
      } else {
        for (i = 0; i < 4; i++) {
          if ((p->cursor.flags >> i) & 1) {
            break;
          }
        }
        if (i < 4) {
          p->cursor.slot = i + 16;
          return 1;
        } else {
          return 0;
        }
      }
    } else {
      return 3;
    }
  } else if (p->cursor.slot == 20) {
    return 2;
  } else {
    return 1;
  }
  return 0;
}

// 武器ページの基本状態に戻す
void MainMenu_ReturnToWeaponPage(MainMenu* p) {
  p->sprites[14].flags |= SPRFLAG_HIDDEN;
  FUN_0808de30(p);
  MainMenu_RefreshWeaponIcons(p);
  MainMenu_RefreshRegisteredWeapons(p, 0);
  p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
  InventoryCursor_RestorePos(&p->cursor);
  MainMenu_ResetWeaponTargetCursor(p, 32);
  GetInventorySlotPos(&p->sprites[13].pos, (u8)p->cursor.slot);
  MainMenu_ShowCursorWeaponInfo(p);
  MainMenu_DrawWeaponPreview(p);
  MainMenu_UpdateWeaponButtonGuides(p, 0);
  MainMenu_SetState(p, MainMenu_StateWeaponPage, FALSE);
}

// 武器ページの基本状態, SELECT で QC, A で武器を選んで操作の選択へ (枠 21 なら整頓の確認), 十字キーでカーソルを動かす
void MainMenu_StateWeaponPage(MainMenu* p) {
  u16 select;

  FUN_0808c548(p);
  MainMenu_DrawHPGauge(p, 1, 5, 3);
  MainMenu_DrawEneGauge(p, 1, 5, 4);
  select = gInput[0].down & SELECT_BUTTON;
  if (select) {
    MainMenu_SetButtonGuides(p, 9, -1);
    MainMenu_SetState(p, MainMenu_StateWeaponQuickChange, TRUE);
  } else {
    p->hidden = FALSE;
    MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
    MainSprite_SetPose(&p->sprites[40], &p->gfx.smenu, 64, PLAYMODE_LOOP);
    if (gInput[0].pressed & A_BUTTON) {
      PlaySound_082406e0(SE_SELECT);
      InventoryCursor_SavePos(&p->cursor);
      p->sprites[14].flags &= ~SPRFLAG_HIDDEN;
      GetInventorySlotPos(&p->sprites[14].pos, p->cursor.savedSlot);
      if (p->cursor.slot == 21) {
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        p->sprites[45].flags |= SPRFLAG_HIDDEN;
        MainMenu_ShowBottomLine(p->etcTexts, 4, 0);
        MainMenu_ShowYesNo(p, 1);
        MainMenu_HideButtonGuides(p);
        MainMenu_SetState(p, FUN_080960c8, TRUE);
      } else {
        MainMenu_ResetWeaponTargetCursor(p, GetWeaponPermission(p, p->cursor.savedSlot));
        MainMenu_RefreshRegisteredWeapons(p, 1);
        MainMenu_UpdateWeaponButtonGuides(p, 1);
        MainMenu_SetState(p, MainMenu_StateWeaponPickTarget, TRUE);
      }
    } else if (InventoryCursor_Move(&p->cursor)) {
      GetInventorySlotPos(&p->sprites[13].pos, p->cursor.slot);
      MainMenu_ShowCursorWeaponInfo(p);
      MainMenu_DrawWeaponPreview(p);
      MainMenu_UpdateWeaponButtonGuides(p, 0);
    }
  }
}

// 武器ページで SELECT を押している間の状態, R で装備する登録武器を回し, 離したら MainMenu_StateWeaponPage へ戻る
void MainMenu_StateWeaponQuickChange(MainMenu* p) {
  MainMenu_DrawHP(p, 1, 5, 3);
  MainMenu_DrawEne(p, 1, 5, 4);
  if (gInput[0].down & SELECT_BUTTON) {
    MainSprite_SetPose(&p->sprites[13], &p->gfx.smenu, 56, PLAYMODE_LOOP);
    MainSprite_AdvanceAnim(&p->sprites[40], &p->gfx.smenu);
    if ((gInput[0].pressed & R_BUTTON) && p->qc.weaponScrollTimer == 0 && p->qc.weaponCount > 1) {
      s16* equipped;

      PlaySound_082406e0(SE_QUICK_CHANGE);
      if (++p->qc.weaponIdx >= p->qc.weaponCount) {
        p->qc.weaponIdx = 0;
      }
      equipped = &gStat->equippedWeaponIdx;
      *equipped = (s8)p->qc.weapons[p->qc.weaponIdx].registeredIdx;
      MainMenu_RefreshRegisteredWeapons(p, 0);
      FUN_0808de30(p);
    }
  } else {
    MainMenu_UpdateWeaponButtonGuides(p, 0);
    MainMenu_SetState(p, MainMenu_StateWeaponPage, FALSE);
  }
}

// 武器ページで選んだ武器の行き先を選ぶ状態, A で登録・登録解除・入れ替え, B で戻る
void MainMenu_StateWeaponPickTarget(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
  FUN_0808c548(p);
  if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_ReturnToWeaponPage(p);
  } else if ((gInput[0].pressed & SELECT_BUTTON) && (p->cursor.flags & 0x10)) {
    p->sprites[34].flags &= ~SPRFLAG_HIDDEN;
    MainMenu_GetSlotPos(&p->sprites[13].pos, 20);
    MainSprite_SetPose(&p->sprites[13], &p->gfx.smenu, 56, PLAYMODE_LOOP);
    p->sprites[45].flags |= SPRFLAG_HIDDEN;
    MainMenu_ShowBottomLine(p->etcTexts, 2, TRUE);
    MainMenu_ShowYesNo(p, 0);
    MainMenu_HideButtonGuides(p);
    MainMenu_SetState(p, FUN_080962b0, TRUE);
  } else if (gInput[0].pressed & A_BUTTON) {
    MainMenu_HideButtonGuides(p);
    switch (MainMenu_GetWeaponAction(p)) {
      case 2: {
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        p->sprites[45].flags |= SPRFLAG_HIDDEN;
        MainMenu_ShowBottomLine(p->etcTexts, 2, TRUE);
        MainMenu_ShowYesNo(p, 0);
        MainMenu_SetState(p, FUN_080962b0, TRUE);
        break;
      }
      case 1: {
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        MainMenu_BeginWeaponIconMove(p, 0, p->cursor.savedSlot, p->cursor.slot);
        MainMenu_SetState(p, FUN_0809611c, TRUE);
        break;
      }
      case 4: {
        UnregisterWeapon(p->cursor.slot - 16);
        PlaySound_082406e0(SE_CANCEL);
        MainMenu_ReturnToWeaponPage(p);
        break;
      }
      case 3: {
        s32 i;

        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        if (GetWeaponID(p->cursor.savedSlot) > WEAPON_NONE) {
          MainMenu_BeginWeaponIconMove(p, 0, p->cursor.savedSlot, p->cursor.slot);
        }
        if (GetWeaponID(p->cursor.slot) > WEAPON_NONE) {
          MainMenu_BeginWeaponIconMove(p, 1, p->cursor.slot, p->cursor.savedSlot);
        }
        for (i = 0; i < 4; i++) {
          if (REGISTERED_WEAPON(i) == p->cursor.savedSlot) {
            p->sprites[41 + i].flags |= SPRFLAG_HIDDEN;
          }
          if (REGISTERED_WEAPON(i) == p->cursor.slot) {
            p->sprites[41 + i].flags |= SPRFLAG_HIDDEN;
          }
        }
        p->sprites[17 + p->cursor.savedSlot].flags |= SPRFLAG_HIDDEN;
        p->sprites[17 + p->cursor.slot].flags |= SPRFLAG_HIDDEN;
        MainMenu_SetState(p, MainMenu_StateSwapWeapon, TRUE);
        break;
      }
      case 0:
      default: {
        PlaySound_082406e0(SE_NG);
        break;
      }
    }
  } else if (InventoryCursor_Move(&p->cursor)) {
    GetInventorySlotPos(&p->sprites[13].pos, p->cursor.slot);
    MainMenu_ShowCursorWeaponInfo(p);
    MainMenu_DrawWeaponPreview(p);
    MainMenu_UpdateWeaponButtonGuides(p, 1);
  }
}

void FUN_08096024(MainMenu* p) {
  if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_DRUMROLL);
    GetInventorySlotPos(&p->sprites[13].pos, p->cursor.slot);
    MainMenu_ShowCursorWeaponInfo(p);
    MainMenu_SetState(p, MainMenu_StateWeaponPickTarget, TRUE);
  } else if (gInput[0].pressed & A_BUTTON) {
    p->sprites[13].flags |= SPRFLAG_HIDDEN;
    p->sprites[45].flags |= SPRFLAG_HIDDEN;
    MainMenu_ShowBottomLine(p->etcTexts, 2, TRUE);
    MainMenu_ShowYesNo(p, 0);
    MainMenu_SetState(p, FUN_080962b0, TRUE);
  }
  MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
}

void FUN_080960c8(MainMenu* p) {
  s32 result = MainMenu_UpdateYesNo(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_ReturnToWeaponPage(p);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortWeapons(0);
    p->cursor.savedCol = 0;
    p->cursor.savedRow = 0;
    p->cursor.savedSlot = 0;
    MainMenu_ReturnToWeaponPage(p);
  }
}

void FUN_0809611c(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    PlaySound_082406e0(SE_SWAP_SLOT);
  }

  if (++*timer < 12) {
    FUN_0808ba20(&p->sprites[46].pos, p->unk_3b68, 12 - *timer);
  } else {
    PlaySound_082406e0(SE_EQUIP);
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    RegisterWeapon((u8)p->cursor.savedSlot, p->cursor.slot - 16);
    MainMenu_ReturnToWeaponPage(p);
  }
}

// sprites[33] を8フレームの間上下に揺らしてから武器ページの基本状態に戻す
void FUN_080961a4(MainMenu* p) {
  if (++p->stateTimer < 8) {
    if ((p->stateTimer >> 1) & 1) {
      p->sprites[33].pos.y = 104;
    } else {
      p->sprites[33].pos.y = 104 - ((16 - p->stateTimer) >> 3);
    }
  } else {
    MainMenu_SetState(p, MainMenu_StateWeaponPage, FALSE);
    p->sprites[33].pos.y = 104;
  }
}

// 入れ替える2つの武器アイコンを互いの枠へ動かし, 着いたら実際に入れ替える
void MainMenu_StateSwapWeapon(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    PlaySound_082406e0(SE_SWAP_SLOT);
  }

  if (++*timer < 12) {
    s32 weight = 12 - *timer;

    FUN_0808ba20(&p->sprites[46].pos, p->unk_3b68, weight);
    FUN_0808ba20(&p->sprites[47].pos, p->unk_3b70, weight);
  } else {
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    p->sprites[47].flags |= SPRFLAG_HIDDEN;
    SwapWeaponSlot(p->cursor.savedSlot, p->cursor.slot);
    MainMenu_ReturnToWeaponPage(p);
  }
}

void FUN_080962b0(MainMenu* p) {
  s32 result = MainMenu_UpdateYesNo(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_ReturnToWeaponPage(p);
  } else if (result == 1) {
    MainMenu_BeginWeaponIconMove(p, 0, p->cursor.savedSlot, 20);
    RemoveWeapon(p->cursor.savedSlot);
    MainMenu_RefreshWeaponIcons(p);
    MainMenu_RefreshRegisteredWeapons(p, 1);
    MainMenu_SetState(p, FUN_0809630c, 1);
  }
}

void FUN_0809630c(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    PlaySound_082406e0(SE_SWAP_SLOT);
  }

  if (++*timer < 12) {
    FUN_0808ba20(&p->sprites[46].pos, p->unk_3b68, 12 - *timer);
  } else {
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    MainMenu_SetState(p, MainMenu_StateWeaponTrashShake, FALSE);
  }
}

// 武器を捨てたあと, 捨てる音を鳴らしてゴミ箱 (sprites[33]) を揺らし, 武器ページに戻す
void MainMenu_StateWeaponTrashShake(MainMenu* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_TRASH);
  }
  if (++p->stateTimer < 12) {
    if ((p->stateTimer >> 1) & 1) {
      p->sprites[33].pos.y = 70;
    } else {
      p->sprites[33].pos.y = 70 - ((20 - p->stateTimer) >> 3);
    }
  } else if (p->stateTimer < 16) {
    p->sprites[33].pos.y = 70;
  } else {
    MainMenu_ReturnToWeaponPage(p);
  }
}

void FUN_080963f4(MainMenu* p) {
  FUN_0808b8a4(p);
  MainMenu_RefreshWeaponIcons(p);
  FUN_0808b910(p);
  MainMenu_RefreshRegisteredWeapons(p, 0);
  p->sprites[33].flags &= ~SPRFLAG_HIDDEN;
  if (p->cursor.flags & 0x10) {
    MainSprite_SetPltt(&p->sprites[33], 735);
  } else {
    MainSprite_SetPltt(&p->sprites[33], 736);
  }
  p->sprites[35].flags &= ~SPRFLAG_HIDDEN;
  if (p->cursor.flags & 0x20) {
    MainSprite_SetPltt(&p->sprites[35], 735);
  } else {
    MainSprite_SetPltt(&p->sprites[35], 736);
  }
  MainMenu_RefreshPlayerFigure(p);
}

void FUN_080964ac(MainMenu* p, s32 _) {
  Vec3* pos;
  u8* slot;

  MainMenu_ResetWeaponTargetCursor(p, 32);
  InventoryCursor_SetPos(&p->cursor, 0, 0);
  pos = &p->sprites[13].pos;
  slot = (u8*)&p->cursor.slot;
  GetInventorySlotPos(pos, *slot);
  p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[13], &p->gfx.smenu, 0, PLAYMODE_LOOP, 0);
  GetInventorySlotPos(pos, *slot);
}

void MainMenu_InitPage_Weapon(MainMenu* p) {
  TextPanel_Hide(p->textPanelID_4014);
  TextPanel_Hide(p->textPanelID);
  MessageWindow_SetRect(2, 16, 28, 2);
  FUN_0808a3c4(p, p->tm_18, 0, 7, p->bgp_30);
  if (p->player->kind == PLAYER_SABATA) {
    FUN_0808b9c4(18, 4, 11, 11);
    FUN_0808b9c4(8, 9, 5, 6);
  }
  MainMenu_DrawHPGauge(p, 1, 5, 3);
  MainMenu_DrawEneGauge(p, 1, 5, 4);
  MainMenu_DrawMoney(p);
  FUN_0808b82c(p);
  MainMenu_ShowPageName(p, p->page);
  p->sprites[16].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[16], &p->gfx.smenu, 159, PLAYMODE_LOOP);
  FUN_080964ac(p, 0);
  FUN_080963f4(p);
  MainMenu_DrawWeaponPreview(p);
  FUN_08049f5c();
  MessageWindow_SetBgPltt(BGP_EFDA);
  MainMenu_ShowCursorWeaponInfo(p);
  FUN_0808c61c(p, 0, 0);
  MainMenu_UpdateWeaponButtonGuides(p, 0);
  MainMenu_SetState(p, MainMenu_StateWeaponPage, FALSE);
}

// 防具ページのカーソルの枠表を作り直す, サバタは左上の1枠だけ選べるようにする
// 残差: 117/124 命令, InventoryCursor_ResetSlotmap と同じ本体で, 原典は値 i*4+j を誘導変数として減算で持つ (static inline 化, slotmap の2次元配列化, 値の式の書き換えは試済)
NON_MATCH void MainMenu_ResetArmorCursor(MainMenu* p, u32 flags) {
#ifdef NONMATCHING_C
  InventoryCursor* c = &p->cursor;
  s32 i, j;

  if (p->player->kind == PLAYER_SABATA) {
    c->flags = 0;
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 9; j++) {
        INVENTORY_SLOT(c, j, i) |= 0xFF;
      }
    }
    INVENTORY_SLOT(c, 0, 0) = 0;
    return;
  }

  c->flags = flags;
  for (i = 0; i < 4; i++) {
    for (j = 3; j >= 0; j--) {
      INVENTORY_SLOT(c, j, i) = i * 4 + j;
    }
  }
  if (flags & 1) {
    for (i = 0; i < 4; i++) {
      for (j = 3; j >= 0; j--) {
        INVENTORY_SLOT(c, j + 4, i) = 16;
      }
    }
  } else {
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        INVENTORY_SLOT(c, j + 4, i) |= 0xFF;
      }
    }
  }
  for (i = 0; i < 3; i++) {
    INVENTORY_SLOT(c, 8, i) |= 0xFF;
  }
  INVENTORY_SLOT(c, 8, 3) = flags & 0x20 ? 21 : -1;
#else
  INCFUNC("asm/func/MainMenu_ResetArmorCursor.inc");
#endif
}

// 防具ページの一覧を作る, サバタはメイルオブルナだけで, それ以外はインベントリの防具と装備中の枠を写す
void MainMenu_BuildArmorList(MainMenu* p) {
  s32 i;

  if (p->player->kind != PLAYER_SABATA) {
    for (i = 0; i < 16; i++) {
      p->armorIDs[i] = gStat->armors[i];
    }
    p->equippedArmorSlot = gStat->armor;
  } else {
    p->armorIDs[0] = ARMOR_MAIL_OF_LUNA;
    for (i = 1; i < 16; i++) {
      p->armorIDs[i] = -1;
    }
    p->equippedArmorSlot = 0;
  }
}

// 防具ページでカーソルの防具に替えたときの防御力と攻撃力を出す, 今と違えば上がるか下がるかで色を変える
void MainMenu_DrawArmorPreview(MainMenu* p) {
  bool32 hasCursor = FALSE;
  const ArmorData* data;
  WeaponData w;
  s32 digits[3];
  s32 base;
  s32 value;
  s32 color;
  s32 i;

  if (gStat->armor < 0) {
    data = NULL;
  } else {
    data = &gArmorDB[p->armorIDs[p->equippedArmorSlot]];
  }
  base = CalcDefence(data);
  if (p->cursor.slot > 15 || p->armorIDs[p->cursor.slot] < 0) {
    value = base;
  } else {
    hasCursor = TRUE;
    value = CalcDefence(&gArmorDB[p->armorIDs[p->cursor.slot]]);
  }
  if (value == base) {
    for (i = 0; i < 3; i++) {
      p->sprites[48 + i].flags |= SPRFLAG_HIDDEN;
    }
    MainMenu_DrawNumber(value, 100, 6, 6, 0);
  } else {
    s32 n;

    FUN_0808b97c(6, 6, 3, 1);
    digits[0] = Div(value, 100);
    n = value - digits[0] * 100;
    digits[1] = Div(n, 10);
    n -= digits[1] * 10;
    digits[2] = n;
    color = 20;
    if (value > base) {
      color = 10;
    }
    for (i = 0; i < 3; i++) {
      MainSprite* s = &p->sprites[48 + i];

      s->flags &= ~SPRFLAG_HIDDEN;
      s->pos.x = 48 + i * 8;
      s->pos.y = 48;
      MainSprite_SetPose(s, &p->gfx.smenu, digits[i] + color, PLAYMODE_LOOP);
    }
  }

  GetRegisteredWeaponData(gStat->equippedWeaponIdx, &w);
  base = CalcAttackWithEquippedArmor(&w);
  if (!hasCursor) {
    value = base;
  } else {
    value = CalcAttack(&w, &gArmorDB[p->armorIDs[p->cursor.slot]]);
  }
  if (value == base) {
    for (i = 0; i < 3; i++) {
      p->sprites[51 + i].flags |= SPRFLAG_HIDDEN;
    }
    MainMenu_DrawNumber(value, 100, 6, 5, 0);
  } else {
    s32 n;

    FUN_0808b97c(6, 5, 3, 1);
    digits[0] = Div(value, 100);
    n = value - digits[0] * 100;
    digits[1] = Div(n, 10);
    n -= digits[1] * 10;
    digits[2] = n;
    color = 20;
    if (value > base) {
      color = 10;
    }
    for (i = 0; i < 3; i++) {
      MainSprite* s = &p->sprites[51 + i];

      s->flags &= ~SPRFLAG_HIDDEN;
      s->pos.x = 48 + i * 8;
      s->pos.y = 40;
      MainSprite_SetPose(s, &p->gfx.smenu, digits[i] + color, PLAYMODE_LOOP);
    }
  }
}

// カーソルの枠に防具があればその名前と防御力・重さを添えた説明を出し, なければ消す
void MainMenu_ShowCursorArmorInfo(MainMenu* p) {
  if (p->cursor.slot > 15 || p->armorIDs[p->cursor.slot] < 0) {
    p->sprites[45].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    Marquee_Clear();
  } else {
    s32 id = p->armorIDs[p->cursor.slot];
    s32 descTop;

    p->sprites[45].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[45], &p->gfx.icons, 207, PLAYMODE_LOOP);
    MessageWindow_SetInstant(TRUE);
    MessageWindow_Start(p->armorNames);
    MessageWindow_SetRect(2, 16, 28, 2);
    MessageWindow_ShowLine(id);
    Marquee_SetVarValue(0, gArmorDB[id].defence);
    Marquee_SetVarValue(1, gArmorDB[id].weight);
    descTop = VM_ParseStringRef(p->armorNames) + 37;
    Marquee_SetText(GetStringByID(descTop + id));
  }
}

// 防具ページのスロット番号から画面上のカーソル位置を引く
void GetArmorSlotPos(Vec3* pos, s32 idx) {
  if (idx <= 15) {
    pos->x = (idx & 3) * 24 + 144;
    pos->y = (idx >> 2) * 24 + 32;
  } else if (idx == 21) {
    pos->x = 120;
    pos->y = 104;
  } else if (idx == 20) {
    pos->x = 117;
    pos->y = 70;
  } else if (idx == 16) {
    pos->x = 64;
    pos->y = 76;
  } else {
    pos->x = 144;
    pos->y = 32;
  }
}

void FUN_08096b44(MainMenu* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (p->armorIDs[i] < 0) {
      p->sprites[17 + i].flags |= SPRFLAG_HIDDEN;
    } else {
      p->sprites[17 + i].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetPose(&p->sprites[17 + i], &p->gfx.icons, p->armorIDs[i] + 67, PLAYMODE_LOOP);
      MainSprite_SetPltt(&p->sprites[17 + i], 735);
    }
  }
}

// 装備中の防具のアイコン (sprites[36]) と, その枠に重ねる印 (sprites[41]) を出す
void MainMenu_ShowEquippedArmor(MainMenu* p, s32 param_2) {
  if (p->equippedArmorSlot >= 0) {
    p->sprites[36].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[36], &p->gfx.icons, p->armorIDs[p->equippedArmorSlot] + 67, PLAYMODE_LOOP);
    if (param_2) {
      if (p->cursor.flags & 1) {
        MainSprite_SetPltt(&p->sprites[36], 735);
      } else {
        MainSprite_SetPltt(&p->sprites[36], 736);
      }
    } else {
      MainSprite_SetPltt(&p->sprites[36], 735);
    }
    p->sprites[41].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[41].pos = p->sprites[17 + p->equippedArmorSlot].pos;
  } else {
    p->sprites[36].flags |= SPRFLAG_HIDDEN;
    p->sprites[41].flags |= SPRFLAG_HIDDEN;
  }
}

// 枠 param_3 の防具のアイコンを sprites[46 + idx] に出し, 枠 param_4 へ動かす準備をする
void MainMenu_BeginArmorIconMove(MainMenu* p, s32 idx, s32 param_3, s32 param_4) {
  MainSprite* sprite = &p->sprites[idx + 46];

  sprite->flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(sprite, &p->gfx.icons, p->armorIDs[param_3] + 67, PLAYMODE_LOOP);
  GetArmorSlotPos(&sprite->pos, param_3);
  GetArmorSlotPos((Vec3*)&p->unk_3b68[idx * 4], param_4);
  MainSprite_SetPltt(sprite, p->sprites[param_3 + 17].plttID);
}

// 枠の防具が選べるかどうかを返す, 値段が付いているものは 0x11
s32 FUN_08096d40(MainMenu* p, s32 slot) {
  if (p->armorIDs[slot] < 0 || slot == p->equippedArmorSlot) {
    return 0;
  }

  if (gArmorDB[p->armorIDs[slot]].price == 0) {
    return 1;
  }
  return 0x11;
}

// 防具ページのボタン案内を, 入れ替え中かどうかとカーソルの位置で切り替える
void MainMenu_UpdateArmorButtonGuides(MainMenu* p, s32 param_2) {
  if (param_2 == 0) {
    if (p->cursor.slot == 21) {
      MainMenu_SetButtonGuides(p, 0, 4);
    } else {
      MainMenu_SetButtonGuides(p, 0, -1);
    }
  } else {
    s32 mode = 0;

    if (p->player->kind != PLAYER_SABATA) {
      if (p->armorIDs[p->cursor.savedSlot] < 0) {
        if (p->cursor.slot == 16 && gStat->armor >= 0) {
          mode = 4;
        } else {
          mode = p->armorIDs[p->cursor.slot] >= 0 ? 3 : 0;
        }
      } else if (p->cursor.slot == 20) {
        mode = 2;
      } else if (p->cursor.slot == 16) {
        mode = 1;
      } else if (p->cursor.slot == p->cursor.savedSlot) {
        if (p->cursor.savedSlot == gStat->armor) {
          mode = 4;
        } else {
          p->cursor.slot = 16;
          mode = 1;
        }
      } else {
        mode = 3;
      }
    }

    switch (mode) {
      case 1: {
        MainMenu_SetButtonGuides(p, 5, -1);
        break;
      }
      case 4: {
        MainMenu_SetButtonGuides(p, 2, -1);
        break;
      }
      case 3: {
        MainMenu_SetButtonGuides(p, 3, -1);
        break;
      }
      default: {
        MainMenu_SetButtonGuides(p, -1, -1);
        break;
      }
    }
  }
}

// 防具ページで A を押したときの動作を決める, 0: なし, 1/4: 枠 16 への操作, 2: 枠 20 の確認, 3: 入れ替え
s32 MainMenu_GetArmorAction(MainMenu* p) {
  if (p->player->kind == PLAYER_SABATA) {
    return 0;
  }
  if (p->armorIDs[p->cursor.savedSlot] < 0) {
    if (p->cursor.slot == 16 && gStat->armor >= 0) {
      return 4;
    }
    if (p->armorIDs[p->cursor.slot] >= 0) {
      return 3;
    }
    return 0;
  }
  if (p->cursor.slot == 20) {
    return 2;
  }
  if (p->cursor.slot == 16) {
    return 1;
  }
  if (p->cursor.slot == p->cursor.savedSlot) {
    if (p->cursor.savedSlot == gStat->armor) {
      p->cursor.slot = 16;
      return 4;
    }
    p->cursor.slot = 16;
    return 1;
  }
  return 3;
}

void FUN_08096f90(MainMenu* p) { MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu); }

// 防具ページの基本状態に戻す
void MainMenu_ReturnToArmorPage(MainMenu* p) {
  p->sprites[14].flags |= SPRFLAG_HIDDEN;
  p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
  MainMenu_BuildArmorList(p);
  FUN_08096b44(p);
  MainMenu_ShowEquippedArmor(p, 0);
  InventoryCursor_RestorePos(&p->cursor);
  MainMenu_ResetArmorCursor(p, 32);
  GetArmorSlotPos(&p->sprites[13].pos, (u8)p->cursor.slot);
  MainMenu_ShowCursorArmorInfo(p);
  MainMenu_DrawArmorPreview(p);
  MainMenu_UpdateArmorButtonGuides(p, 0);
  MainMenu_SetState(p, MainMenu_StateArmorPage, FALSE);
}

// 防具ページの基本状態, SELECT で HP/Ene の数値表示, A で防具を選んで操作の選択へ (枠 21 なら整頓の確認), 十字キーでカーソルを動かす
void MainMenu_StateArmorPage(MainMenu* p) {
  u16 select;

  FUN_0808c548(p);
  select = gInput[0].down & SELECT_BUTTON;
  if (select) {
    p->hidden = TRUE;
    MainMenu_HideButtonGuides(p);
    MainSprite_SetPose(&p->sprites[13], &p->gfx.smenu, 56, PLAYMODE_LOOP);
    MainMenu_DrawHP(p, 1, 5, 3);
    MainMenu_DrawEne(p, 1, 5, 4);
  } else {
    p->hidden = FALSE;
    MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
    MainMenu_DrawHPGauge(p, 1, 5, 3);
    MainMenu_DrawEneGauge(p, 1, 5, 4);
    MainMenu_UpdateArmorButtonGuides(p, 0);
    if (gInput[0].pressed & A_BUTTON) {
      PlaySound_082406e0(SE_SELECT);
      InventoryCursor_SavePos(&p->cursor);
      p->sprites[14].flags &= ~SPRFLAG_HIDDEN;
      GetArmorSlotPos(&p->sprites[14].pos, p->cursor.savedSlot);
      if (p->cursor.slot == 21) {
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        p->sprites[45].flags |= SPRFLAG_HIDDEN;
        MainMenu_ShowBottomLine(p->etcTexts, 4, 0);
        MainMenu_ShowYesNo(p, 1);
        MainMenu_HideButtonGuides(p);
        MainMenu_SetState(p, FUN_08097530, TRUE);
      } else {
        MainMenu_ResetArmorCursor(p, FUN_08096d40(p, p->cursor.savedSlot));
        MainMenu_ShowEquippedArmor(p, 1);
        MainMenu_UpdateArmorButtonGuides(p, 1);
        MainMenu_SetState(p, MainMenu_StateArmorPickTarget, TRUE);
      }
    } else if (InventoryCursor_Move(&p->cursor)) {
      GetArmorSlotPos(&p->sprites[13].pos, p->cursor.slot);
      MainMenu_ShowCursorArmorInfo(p);
      MainMenu_DrawArmorPreview(p);
    }
  }
}

// 防具ページで選んだ防具の行き先を選ぶ状態, A で装備・外す・入れ替え, B で戻る
void MainMenu_StateArmorPickTarget(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
  FUN_0808c548(p);
  if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_ReturnToArmorPage(p);
  }
  if ((gInput[0].pressed & SELECT_BUTTON) && (p->cursor.flags & 0x10)) {
    p->sprites[34].flags &= ~SPRFLAG_HIDDEN;
    MainMenu_GetSlotPos(&p->sprites[13].pos, 20);
    MainSprite_SetPose(&p->sprites[13], &p->gfx.smenu, 56, PLAYMODE_LOOP);
    p->sprites[45].flags |= SPRFLAG_HIDDEN;
    MainMenu_ShowBottomLine(p->etcTexts, 2, TRUE);
    MainMenu_ShowYesNo(p, 0);
    MainMenu_HideButtonGuides(p);
    MainMenu_SetState(p, MainMenu_StateConfirmDiscardArmor, TRUE);
  } else if (gInput[0].pressed & A_BUTTON) {
    MainMenu_HideButtonGuides(p);
    switch (MainMenu_GetArmorAction(p)) {
      case 2: {
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        p->sprites[45].flags |= SPRFLAG_HIDDEN;
        MainMenu_ShowBottomLine(p->etcTexts, 2, TRUE);
        MainMenu_ShowYesNo(p, 0);
        MainMenu_SetState(p, MainMenu_StateConfirmDiscardArmor, TRUE);
        break;
      }
      case 1: {
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        MainMenu_BeginArmorIconMove(p, 0, p->cursor.savedSlot, p->cursor.slot);
        MainMenu_SetState(p, MainMenu_StateEquipArmor, TRUE);
        break;
      }
      case 4: {
        s16* armor = &gStat->armor;

        *armor = -1;
        Player_EquipArmor(p->player, NULL);
        MainMenu_RefreshPlayerFigure(p);
        PlaySound_082406e0(SE_CANCEL);
        MainMenu_ReturnToArmorPage(p);
        break;
      }
      case 3: {
        PlaySound_082406e0(SE_SWAP_SLOT);
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        if (p->armorIDs[p->cursor.savedSlot] >= 0) {
          MainMenu_BeginArmorIconMove(p, 0, p->cursor.savedSlot, p->cursor.slot);
        }
        if (p->armorIDs[p->cursor.slot] >= 0) {
          MainMenu_BeginArmorIconMove(p, 1, p->cursor.slot, p->cursor.savedSlot);
        }
        if (gStat->armor == p->cursor.savedSlot || gStat->armor == p->cursor.slot) {
          p->sprites[41].flags |= SPRFLAG_HIDDEN;
        }
        p->sprites[17 + p->cursor.savedSlot].flags |= SPRFLAG_HIDDEN;
        p->sprites[17 + p->cursor.slot].flags |= SPRFLAG_HIDDEN;
        MainMenu_SetState(p, MainMenu_StateSwapArmor, TRUE);
        break;
      }
      case 0:
      default: {
        PlaySound_082406e0(SE_NG);
        break;
      }
    }
  } else if (InventoryCursor_Move(&p->cursor)) {
    GetArmorSlotPos(&p->sprites[13].pos, p->cursor.slot);
    MainMenu_ShowCursorArmorInfo(p);
    MainMenu_DrawArmorPreview(p);
    MainMenu_UpdateArmorButtonGuides(p, 1);
  }
}

void FUN_0809748c(MainMenu* p) {
  if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_DRUMROLL);
    GetArmorSlotPos(&p->sprites[13].pos, p->cursor.slot);
    MainMenu_ShowCursorArmorInfo(p);
    MainMenu_SetState(p, MainMenu_StateArmorPickTarget, TRUE);
  } else if (gInput[0].pressed & A_BUTTON) {
    p->sprites[13].flags |= SPRFLAG_HIDDEN;
    p->sprites[45].flags |= SPRFLAG_HIDDEN;
    MainMenu_ShowBottomLine(p->etcTexts, 2, TRUE);
    MainMenu_ShowYesNo(p, 0);
    MainMenu_SetState(p, MainMenu_StateConfirmDiscardArmor, TRUE);
  }
  MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
}

void FUN_08097530(MainMenu* p) {
  s32 result = MainMenu_UpdateYesNo(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_ReturnToArmorPage(p);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortArmors(0);
    p->cursor.savedCol = 0;
    p->cursor.savedRow = 0;
    p->cursor.savedSlot = 0;
    MainMenu_ReturnToArmorPage(p);
  }
}

// 防具を捨てるかの はい/いいえ を待ち, はい ならアイコンをゴミ箱へ飛ばして所持品から消す
void MainMenu_StateConfirmDiscardArmor(MainMenu* p) {
  u32 result = MainMenu_UpdateYesNo(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_ReturnToArmorPage(p);
  } else if (result == 1) {
    p->sprites[13].flags |= SPRFLAG_HIDDEN;
    MainMenu_BeginArmorIconMove(p, 0, p->cursor.savedSlot, 20);
    ARMORS(p->cursor.savedSlot) = ARMOR_NONE;
    MainMenu_BuildArmorList(p);
    FUN_08096b44(p);
    MainMenu_SetState(p, FUN_08097604, TRUE);
  }
}

void FUN_08097604(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    PlaySound_082406e0(SE_SWAP_SLOT);
  }

  if (++*timer < 12) {
    FUN_0808ba20(&p->sprites[46].pos, p->unk_3b68, 12 - *timer);
  } else {
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    MainMenu_SetState(p, MainMenu_StateArmorTrashShake, TRUE);
  }
}

// 防具を捨てたあと, 捨てる音を鳴らしてゴミ箱 (sprites[33]) を揺らし, 防具ページに戻す
void MainMenu_StateArmorTrashShake(MainMenu* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_TRASH);
  }
  if (++p->stateTimer < 12) {
    if ((p->stateTimer >> 1) & 1) {
      p->sprites[33].pos.y = 70;
    } else {
      p->sprites[33].pos.y = 70 - ((20 - p->stateTimer) >> 3);
    }
  } else if (p->stateTimer < 16) {
    p->sprites[33].pos.y = 70;
  } else {
    MainMenu_ReturnToArmorPage(p);
  }
}

// 選んだ防具のアイコンを装備欄へ動かし, 着いたら装備して表示を作り直す
void MainMenu_StateEquipArmor(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    PlaySound_082406e0(SE_SWAP_SLOT);
  }

  if (++*timer < 12) {
    FUN_0808ba20(&p->sprites[46].pos, p->unk_3b68, 12 - *timer);
  } else {
    s16* armor;

    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    PlaySound_082406e0(SE_EQUIP);
    armor = &gStat->armor;
    *armor = p->cursor.savedSlot;
    Player_EquipArmor(p->player, &gArmorDB[p->armorIDs[gStat->armor]]);
    MainMenu_RefreshPlayerFigure(p);
    MainMenu_ReturnToArmorPage(p);
  }
}

// 防具の入れ替えアニメを進め, 終わったら防具の枠と装備中の番号を入れ替える
void MainMenu_StateSwapArmor(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    PlaySound_082406e0(SE_SWAP_SLOT);
  }

  if (++*timer < 12) {
    s32 weight = 12 - *timer;

    FUN_0808ba20(&p->sprites[46].pos, p->unk_3b68, weight);
    FUN_0808ba20(&p->sprites[47].pos, p->unk_3b70, weight);
  } else {
    s32 tmp;

    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    p->sprites[47].flags |= SPRFLAG_HIDDEN;
    tmp = ARMORS(p->cursor.savedSlot);
    ARMORS(p->cursor.savedSlot) = ARMORS(p->cursor.slot);
    ARMORS(p->cursor.slot) = tmp;
    if (gStat->armor == p->cursor.savedSlot) {
      gStat->armor = p->cursor.slot;
    } else if (gStat->armor == p->cursor.slot) {
      gStat->armor = p->cursor.savedSlot;
    }
    MainMenu_ReturnToArmorPage(p);
  }
}

void FUN_08097888(MainMenu* p) {
  FUN_0808b8a4(p);
  FUN_08096b44(p);
  GetArmorSlotPos(&p->sprites[36].pos, 16);
  MainMenu_ShowEquippedArmor(p, 0);
  p->sprites[33].flags &= ~SPRFLAG_HIDDEN;
  if (p->cursor.flags & 0x10) {
    MainSprite_SetPltt(&p->sprites[33], 735);
  } else {
    MainSprite_SetPltt(&p->sprites[33], 736);
  }
  p->sprites[35].flags &= ~SPRFLAG_HIDDEN;
  if (p->cursor.flags & 0x20) {
    MainSprite_SetPltt(&p->sprites[35], 735);
  } else {
    MainSprite_SetPltt(&p->sprites[35], 736);
  }
  MainMenu_RefreshPlayerFigure(p);
}

void FUN_08097948(MainMenu* p, s32 _) {
  Vec3* pos;
  u8* slot;

  MainMenu_ResetArmorCursor(p, 32);
  InventoryCursor_SetPos(&p->cursor, 0, 0);
  pos = &p->sprites[13].pos;
  slot = (u8*)&p->cursor.slot;
  GetArmorSlotPos(pos, *slot);
  p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[13], &p->gfx.smenu, 0, PLAYMODE_LOOP, 0);
  GetArmorSlotPos(pos, *slot);
}

void MainMenu_InitPage_Armor(MainMenu* p) {
  TextPanel_Hide(p->textPanelID_4014);
  TextPanel_Hide(p->textPanelID);
  MainMenu_BuildArmorList(p);
  MessageWindow_SetRect(2, 16, 28, 2);
  FUN_0808a3c4(p, p->tm_18, 0, 8, p->bgp_30);
  if (p->player->kind == PLAYER_SABATA) {
    FUN_0808b9c4(18, 4, 11, 11);
  }
  MainMenu_DrawEquipStats(p, 5, 3);
  MainMenu_DrawMoney(p);
  FUN_0808b82c(p);
  MainMenu_ShowPageName(p, p->page);
  p->sprites[16].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[16], &p->gfx.smenu, 158, PLAYMODE_LOOP);
  FUN_08097948(p, 0);
  FUN_08097888(p);
  MainMenu_DrawArmorPreview(p);
  FUN_08049f5c();
  MessageWindow_SetBgPltt(BGP_EFDA);
  MainMenu_ShowCursorArmorInfo(p);
  FUN_0808c61c(p, 0, 0);
  MainMenu_UpdateArmorButtonGuides(p, 0);
  MainMenu_SetState(p, MainMenu_StateArmorPage, FALSE);
}

// 魔法ページのカーソルの枠表を作り直す, bit0 なら左の16枠を元の枠に固定して右側を登録枠 16〜19 にする
// 残差: 150/155 命令, 原典は &cursor と &slotmap を最初に callee-saved に取り, 2つ目の4x4のループでも別の誘導変数を持つ (引数の u32 化, k + 16 の先出しまでで止まった)
NON_MATCH void MainMenu_ResetMagicCursor(MainMenu* p, u32 param_2) {
#ifdef NONMATCHING_C
  InventoryCursor* c = &p->cursor;
  s32 i, j, k;

  c->flags = param_2;
  if (!(param_2 & 1)) {
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        if ((s8)p->magicIDs[i * 4 + j] >= 0) {
          INVENTORY_SLOT(c, j, i) = i * 4 + j;
        } else {
          INVENTORY_SLOT(c, j, i) |= 0xFF;
        }
      }
    }
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 5; j++) {
        INVENTORY_SLOT(c, j + 4, i) |= 0xFF;
      }
    }
  } else {
    for (i = 0; i < 4; i++) {
      for (j = 0; j < 4; j++) {
        INVENTORY_SLOT(c, j, i) = c->savedSlot;
      }
    }
    for (k = 0; k < 4; k++) {
      s32 slot = k + 16;
      s32 start = (k & 1) * 2;

      if (k < 2) {
        for (i = 0; i < 3; i++) {
          for (j = start; j < start + 2; j++) {
            INVENTORY_SLOT(c, j + 4, i) = slot;
          }
        }
      } else {
        for (j = start; j < start + 2; j++) {
          INVENTORY_SLOT(c, j + 4, 3) = slot;
        }
      }
    }
    for (i = 0; i < 4; i++) {
      INVENTORY_SLOT(c, 8, i) |= 0xFF;
    }
  }
#else
  INCFUNC("asm/func/MainMenu_ResetMagicCursor.inc");
#endif
}

// カーソルの枠に魔法があればその名前と説明を出し, なければ消す
void MainMenu_ShowCursorMagicInfo(MainMenu* p) {
  s32 id = MainMenu_GetCursorMagicID(p);

  if (id < 0) {
    p->sprites[45].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    Marquee_Clear();
  } else {
    s32 descTop;

    p->sprites[45].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[45], &p->gfx.icons, 207, PLAYMODE_LOOP);
    MessageWindow_SetInstant(TRUE);
    MessageWindow_Start(p->magicNames);
    MessageWindow_SetRect(2, 16, 28, 2);
    MessageWindow_ShowLine(id);
    descTop = VM_ParseStringRef(p->magicNames) + 18;
    Marquee_SetText(GetStringByID(descTop + id));
  }
}

// 魔法ページのスロット番号から画面上のカーソル位置を引く, 0..15 は 4 行の升目で行ごとに隙間がある, 16 以降は装備欄
void GetMagicSlotPos(WorldPos* pos, s32 idx) {
  if (idx < 16) {
    pos->x = (idx & 3) * 24 + 144;
    if (idx < 8) {
      pos->y = (idx >> 2) * 24 + 16;
    } else if (idx < 12) {
      pos->y = (idx >> 2) * 24 + 24;
    } else {
      pos->y = (idx >> 2) * 24 + 32;
    }
  } else if (idx == 16) {
    pos->x = 64;
    pos->y = 76;
  } else if (idx == 17) {
    pos->x = 88;
    pos->y = 76;
  } else if (idx == 18) {
    pos->x = 64;
    pos->y = 104;
  } else if (idx == 19) {
    pos->x = 88;
    pos->y = 104;
  } else {
    pos->x = 144;
    pos->y = 32;
  }
}

// magicIDs から value の位置を探す
s32 MainMenu_FindMagicSlot(MainMenu* p, s32 value) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (value == (s8)p->magicIDs[i]) {
      return i;
    }
  }

  return -1;
}

// 魔法ページの16枠のアイコンを描き, 登録中の魔法の枠に印 (sprites[41〜44]) を重ねる
void MainMenu_RefreshMagicIcons(MainMenu* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if ((s8)p->magicIDs[i] >= 0) {
      p->sprites[17 + i].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetPose(&p->sprites[17 + i], &p->gfx.icons, (s8)p->magicIDs[i] + 182, PLAYMODE_LOOP);
      MainSprite_SetPltt(&p->sprites[17 + i], 1);
    } else {
      p->sprites[17 + i].flags |= SPRFLAG_HIDDEN;
    }
  }
  for (i = 0; i < p->qc.magicCount; i++) {
    s32 slot = MainMenu_FindMagicSlot(p, (s8)p->qc.magics[i].id);

    p->sprites[41 + i].flags &= ~SPRFLAG_HIDDEN;
    GetMagicSlotPos(&p->sprites[41 + i].pos, slot);
  }
  for (; i < 4; i++) {
    p->sprites[41 + i].flags |= SPRFLAG_HIDDEN;
  }
}

// 魔法ページの登録枠 (sprites[36〜39]) に QC の魔法を描き, 装備中の枠に印 (sprites[40]) を重ねる
void MainMenu_RefreshRegisteredMagic(MainMenu* p) {
  s32 i;

  p->sprites[40].flags |= SPRFLAG_HIDDEN;
  for (i = 0; i < 4; i++) {
    p->sprites[36 + i].flags |= SPRFLAG_HIDDEN;
  }
  for (i = 0; i < p->qc.magicCount; i++) {
    s32 idx = p->qc.magics[i].idx;

    p->sprites[36 + idx].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_SetPose(&p->sprites[36 + idx], &p->gfx.icons, (s8)p->qc.magics[i].id + 182, PLAYMODE_LOOP);
    MainSprite_SetPltt(&p->sprites[36 + idx], 1);
    if (idx == *p->qc.equippedMagicIdx) {
      p->sprites[40].flags &= ~SPRFLAG_HIDDEN;
      p->sprites[40].pos = p->sprites[36 + idx].pos;
    }
  }
}

void FUN_08097f48(MainMenu* p, s32 idx, s32 id, s32 param_4, s32 param_5) {
  MainSprite* sprite = &p->sprites[idx + 46];

  sprite->flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(sprite, &p->gfx.icons, id + 182, PLAYMODE_LOOP);
  GetMagicSlotPos(&sprite->pos, param_4);
  GetMagicSlotPos((Vec3*)&p->unk_3b68[idx * 4], param_5);
  MainSprite_SetPltt(sprite, 1);
}

// 魔法ページのボタン案内を, 入れ替え中かどうかとカーソルの位置で切り替える
void MainMenu_UpdateMagicButtonGuides(MainMenu* p, s32 param_2) {
  if (param_2 == 0) {
    MainMenu_SetButtonGuides(p, 0, -1);
  } else {
    s32 mode = 0;

    if (p->player->kind != PLAYER_SABATA) {
      if (p->cursor.savedSlot == p->cursor.slot) {
        if (!p->player->magic.unk_285) {
          s32 reg = -1;
          s32 empty = -1;
          s32 i;

          for (i = 0; i < 4; i++) {
            s32 m = gStat->registeredMagic[i];

            if (m == (s8)p->magicIDs[p->cursor.savedSlot]) {
              reg = i;
            }
            if (empty < 0 && m < 0) {
              empty = i;
            }
          }
          mode = 4;
          if (reg < 0) {
            mode = 1;
          }
        }
      } else if (p->player->magic.unk_285) {
        if (p->cursor.slot != gStat->equippedMagicIdx + 16 && p->cursor.slot > 15) {
          mode = 1;
        }
      } else if (p->cursor.slot > 15) {
        mode = 1;
      }
    }

    switch (mode) {
      case 1: {
        MainMenu_SetButtonGuides(p, 5, -1);
        break;
      }
      case 4: {
        MainMenu_SetButtonGuides(p, 2, -1);
        break;
      }
      default: {
        MainMenu_SetButtonGuides(p, -1, -1);
        break;
      }
    }
  }
}

// 魔法ページで A を押したときの動作を決めて登録枠へカーソルを移す, 0: なし, 1: 登録, 4: 登録解除
// 残差: 150/150 命令, 原典は選んだ魔法の ID を gStat を読んだ後に ldrsb で取り, p->player を r2 に持ったまま進むが, こちらは ID を ldrb + 符号拡張で先に作ってレジスタがずれる (player のローカル変数, ID の先出しは試済)
NON_MATCH s32 MainMenu_GetMagicAction(MainMenu* p) {
#ifdef NONMATCHING_C
  if (p->player->kind == PLAYER_SABATA) {
    return 0;
  }
  if (p->cursor.savedSlot == p->cursor.slot) {
    s32 reg = -1;
    s32 empty = -1;
    s32 id = (s8)p->magicIDs[p->cursor.savedSlot];
    s32 i;

    for (i = 0; i < 4; i++) {
      s32 m = gStat->registeredMagic[i];

      if (m == id) {
        reg = i;
      }
      if (empty < 0 && m < 0) {
        empty = i;
      }
    }
    if (p->player->magic.unk_285) {
      if (reg == gStat->equippedMagicIdx) {
        return 0;
      }
      if (reg >= 0) {
        p->cursor.slot = reg + 16;
        return 4;
      }
      if (empty < 0) {
        return 0;
      }
      p->cursor.slot = empty + 16;
      return 1;
    }
    if (reg >= 0) {
      p->cursor.slot = reg + 16;
      return 4;
    }
    if (empty >= 0) {
      p->cursor.slot = empty + 16;
      return 1;
    }
    p->cursor.slot = gStat->equippedMagicIdx + 16;
    return 1;
  }
  if (p->player->magic.unk_285) {
    if (gStat->registeredMagic[gStat->equippedMagicIdx] == (s8)p->magicIDs[p->cursor.savedSlot]) {
      if (p->cursor.slot == gStat->equippedMagicIdx + 16) {
        return 1;
      }
      return 0;
    }
    if (p->cursor.slot == gStat->equippedMagicIdx + 16) {
      return 0;
    }
  }
  if (p->cursor.slot > 15) {
    return 1;
  }
  return 0;
#else
  INCFUNC("asm/func/MainMenu_GetMagicAction.inc");
#endif
}

void FUN_0809820c(MainMenu* p) {
  p->sprites[14].flags |= SPRFLAG_HIDDEN;
  FUN_0808de50(p);
  MainMenu_RefreshMagicIcons(p);
  MainMenu_RefreshRegisteredMagic(p);
  p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
  InventoryCursor_RestorePos(&p->cursor);
  MainMenu_ResetMagicCursor(p, 0);
  GetMagicSlotPos(&p->sprites[13].pos, (u8)p->cursor.slot);
  MainMenu_ShowCursorMagicInfo(p);
  MainMenu_UpdateMagicButtonGuides(p, 0);
  MainMenu_SetState(p, MainMenu_StateMagicPage, FALSE);
}

// 魔法ページの基本状態, SELECT で QC, A で魔法を選んで入れ替え先の選択へ, 十字キーでカーソルを動かす
void MainMenu_StateMagicPage(MainMenu* p) {
  u16 select;

  MainMenu_DrawHPGauge(p, 1, 5, 3);
  MainMenu_DrawEneGauge(p, 1, 5, 4);
  select = gInput[0].down & SELECT_BUTTON;
  if (select) {
    MainMenu_SetButtonGuides(p, 8, -1);
    MainMenu_SetState(p, MainMenu_StateMagicQuickChange, TRUE);
  } else {
    p->hidden = FALSE;
    MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
    MainSprite_SetPose(&p->sprites[40], &p->gfx.smenu, 64, PLAYMODE_LOOP);
    if (gInput[0].pressed & A_BUTTON) {
      PlaySound_082406e0(SE_SELECT);
      InventoryCursor_SavePos(&p->cursor);
      p->sprites[14].flags &= ~SPRFLAG_HIDDEN;
      GetMagicSlotPos(&p->sprites[14].pos, p->cursor.savedSlot);
      MainMenu_ResetMagicCursor(p, 1);
      MainMenu_UpdateMagicButtonGuides(p, 1);
      MainMenu_SetState(p, MainMenu_StateMagicPickTarget, TRUE);
    } else if (InventoryCursor_Move(&p->cursor)) {
      GetMagicSlotPos(&p->sprites[13].pos, p->cursor.slot);
      MainMenu_ShowCursorMagicInfo(p);
      MainMenu_UpdateMagicButtonGuides(p, 0);
    }
  }
}

// 魔法ページで SELECT を押している間の状態, L で装備する魔法を回し (封じられていれば NG 音), 離したら MainMenu_StateMagicPage へ戻る
void MainMenu_StateMagicQuickChange(MainMenu* p) {
  MainMenu_DrawHP(p, 1, 5, 3);
  MainMenu_DrawEne(p, 1, 5, 4);
  if (gInput[0].down & SELECT_BUTTON) {
    MainSprite_SetPose(&p->sprites[13], &p->gfx.smenu, 56, PLAYMODE_LOOP);
    MainSprite_AdvanceAnim(&p->sprites[40], &p->gfx.smenu);
    if ((gInput[0].pressed & L_BUTTON) && p->qc.magicCount > 1) {
      if (p->player->magic.unk_285) {
        PlaySound_082406e0(SE_NG);
      } else {
        PlaySound_082406e0(SE_QUICK_CHANGE);
        if (++p->qc.magicIdx >= p->qc.magicCount) {
          p->qc.magicIdx = 0;
        }
        *p->qc.equippedMagicIdx = p->qc.magics[p->qc.magicIdx].idx;
        MainMenu_RefreshRegisteredMagic(p);
        FUN_0808de50(p);
      }
    }
  } else {
    MainMenu_UpdateMagicButtonGuides(p, 0);
    MainMenu_SetState(p, MainMenu_StateMagicPage, FALSE);
  }
}

// 魔法ページで選んだ魔法の行き先を選ぶ状態, A で登録か登録解除へ, B で戻る
void MainMenu_StateMagicPickTarget(MainMenu* p) {
  if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_0809820c(p);
  } else if (gInput[0].pressed & A_BUTTON) {
    MainMenu_HideButtonGuides(p);
    switch (MainMenu_GetMagicAction(p)) {
      case 1: {
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        FUN_08097f48(p, 0, (s8)p->magicIDs[p->cursor.savedSlot], p->cursor.savedSlot, p->cursor.slot);
        MainMenu_SetState(p, MainMenu_StateRegisterMagic, TRUE);
        break;
      }
      case 4: {
        PlaySound_082406e0(SE_CANCEL);
        p->sprites[13].flags |= SPRFLAG_HIDDEN;
        FUN_08097f48(p, 0, (s8)p->magicIDs[p->cursor.savedSlot], p->cursor.slot, p->cursor.slot);
        p->sprites[20 + p->cursor.slot].flags |= SPRFLAG_HIDDEN;
        MainMenu_SetState(p, MainMenu_StateUnregisterMagic, TRUE);
        break;
      }
      case 0:
      default: {
        PlaySound_082406e0(SE_NG);
        break;
      }
    }
  } else if (InventoryCursor_Move(&p->cursor)) {
    GetMagicSlotPos(&p->sprites[13].pos, p->cursor.slot);
    MainMenu_ShowCursorMagicInfo(p);
    MainMenu_UpdateMagicButtonGuides(p, 1);
  }
  MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
}

// 選んだ魔法のアイコンを装備欄へ動かし, 着いたら装備音を鳴らして登録する
void MainMenu_StateRegisterMagic(MainMenu* p) {
  u16* timer = &p->stateTimer;

  if (*timer == 0) {
    PlaySound_082406e0(SE_SWAP_SLOT);
  }

  if (++*timer < 12) {
    FUN_0808ba20(&p->sprites[46].pos, p->unk_3b68, 12 - *timer);
  } else {
    PlaySound_082406e0(SE_EQUIP);
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    RegisterMagic(p->cursor.slot - 16, (s8)p->magicIDs[p->cursor.savedSlot]);
    FUN_0809820c(p);
  }
}

// 外す魔法のアイコンを縮めながら少しずつずらし, 消えたら装備欄から外す
void MainMenu_StateUnregisterMagic(MainMenu* p) {
  if (++p->stateTimer < 16) {
    if (p->stateTimer & 1) {
      p->sprites[46].pos.x++;
      p->sprites[46].pos.y++;
    }
    p->sprites[46].flags |= SPRFLAG_AFFINE;
    p->sprites[46].scaleY = p->sprites[46].scaleX = (16 - p->stateTimer) << 2;
  } else {
    p->sprites[46].scaleX = 64;
    p->sprites[46].scaleY = 64;
    p->sprites[46].flags &= ~SPRFLAG_AFFINE;
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    UnregisterMagic(p->cursor.slot - 16);
    FUN_0809820c(p);
  }
}

void FUN_08098734(MainMenu* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    GetMagicSlotPos(&p->sprites[i + 17].pos, i);
  }
}

void FUN_08098758(MainMenu* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    GetMagicSlotPos(&p->sprites[i + 36].pos, i + 0x10);
  }
}

void FUN_0809877c(MainMenu* p) {
  FUN_08098734(p);
  MainMenu_RefreshMagicIcons(p);
  FUN_08098758(p);
  MainMenu_RefreshRegisteredMagic(p);
  MainMenu_RefreshPlayerFigure(p);
}

// 魔法ページの枠に覚えている魔法を詰める, ID 0..9 (8, 9 を除く) を枠 0..7, 10..13 を 8..11, 14..17 を 12..15 へ, 空きは 0xFF, サバタは 8 と 9 だけ
void MainMenu_BuildMagicList(MainMenu* p) {
  s32 i;
  s32 n;

  if (p->player->kind == PLAYER_SABATA) {
    p->magicIDs[0] = 8;
    p->magicIDs[1] = 9;
    for (i = 2; i < 16; i++) {
      p->magicIDs[i] |= 0xFF;
    }
    return;
  }

  n = 0;
  for (i = 0; i < 10; i++) {
    if (i != 8 && i != 9 && IsMagicUnlocked(i)) {
      p->magicIDs[n++] = i;
    }
  }
  for (; n < 8; n++) {
    p->magicIDs[n] |= 0xFF;
  }
  n = 8;
  for (i = 10; i < 14; i++) {
    if (IsMagicUnlocked(i)) {
      p->magicIDs[n++] = i;
    }
  }
  for (; n < 12; n++) {
    p->magicIDs[n] |= 0xFF;
  }
  n = 12;
  for (i = 14; i < 18; i++) {
    if (IsMagicUnlocked(i)) {
      p->magicIDs[n++] = i;
    }
  }
  for (; n < 16; n++) {
    p->magicIDs[n] |= 0xFF;
  }
}

void FUN_0809889c(MainMenu* p, s32 _) {
  Vec3* pos;
  u8* slot;

  MainMenu_ResetMagicCursor(p, 0);
  InventoryCursor_SetPos(&p->cursor, 0, 0);
  pos = &p->sprites[13].pos;
  slot = (u8*)&p->cursor.slot;
  GetMagicSlotPos(pos, *slot);
  p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[13], &p->gfx.smenu, 0, PLAYMODE_LOOP, 0);
  GetMagicSlotPos(pos, *slot);
}

// magicIDs の 8..11 に埋まっているものがあるか
s32 FUN_0809890c(MainMenu* p) {
  s32 i;

  for (i = 8; i < 12; i++) {
    if ((s8)p->magicIDs[i] >= 0) {
      return 1;
    }
  }

  return 0;
}

// magicIDs の 12..15 に埋まっているものがあるか
s32 FUN_08098934(MainMenu* p) {
  s32 i;

  for (i = 12; i < 16; i++) {
    if ((s8)p->magicIDs[i] >= 0) {
      return 1;
    }
  }

  return 0;
}

void FUN_0809895c(MainMenu* p) {
  s32 y;
  s32 x;

  if (FUN_0809890c(p) == 0) {
    for (y = 7; y < 11; y++) {
      BgMapEntry* dst = MainMenu_GetBgMapAddr(0, 18, y);

      for (x = 0; x < 11; x++) {
        *dst++ = 0xF002;
      }
    }
  }

  if (FUN_08098934(p) == 0) {
    for (y = 11; y < 15; y++) {
      BgMapEntry* dst = MainMenu_GetBgMapAddr(0, 18, y);

      for (x = 0; x < 11; x++) {
        *dst++ = 0xF002;
      }
    }
  }
}

void MainMenu_InitPage_Magic(MainMenu* p) {
  TextPanel_Hide(p->textPanelID_4014);
  TextPanel_Hide(p->textPanelID);
  MainMenu_BuildMagicList(p);
  MessageWindow_SetRect(0, 16, 30, 2);
  FUN_0808a3c4(p, p->tm_18, 0, 9, p->bgp_30);
  MainMenu_DrawEquipStats(p, 5, 3);
  if (p->player->kind == PLAYER_SABATA) {
    FUN_0808b9c4(8, 9, 5, 6);
  }
  FUN_0809895c(p);
  FUN_0808b82c(p);
  MainMenu_ShowPageName(p, p->page);
  FUN_0809889c(p, 0);
  FUN_0809877c(p);
  FUN_08049f5c();
  MessageWindow_SetBgPltt(BGP_EFDA);
  MainMenu_ShowCursorMagicInfo(p);
  FUN_0808c61c(p, 0, 0);
  MainMenu_UpdateMagicButtonGuides(p, 0);
  MainMenu_SetState(p, MainMenu_StateMagicPage, FALSE);
}

// 2桁の数値を十の位と一の位のスプライトに出す, 増減の符号で絵柄の組を変える
void FUN_08098a98(s32 base, s32 delta, MainSpriteGfx* gfx, MainSprite* tens, MainSprite* ones) {
  s32 value = base + delta;
  s32 high = Div(value, 10);
  s32 low = value - high * 10;

  s32 poseBase = 10;
  if (delta <= 0) {
    poseBase = (delta < 0) ? 20 : 0;
  }

  MainSprite_SetPose(tens, gfx, poseBase + high, PLAYMODE_LOOP);
  MainSprite_SetPose(ones, gfx, poseBase + low, PLAYMODE_LOOP);
}

// ステータス画面の残りポイントと4種のステータスの数字を描く
void MainMenu_DrawStatusValues(MainMenu* p) {
  s32 i;

  MainMenu_DrawNumber(p->statusPoint, 100, 14, 12, 0);
  for (i = 0; i < 4; i++) {
    if (p->player->kind == PLAYER_SOLAR_DJANGO) {
      p->shownStats[i] = p->player->stats[i] + p->player->armor.bonus[i] + p->player->armor.sideBonus[i];
    } else {
      p->shownStats[i] = p->player->stats[i] + p->player->armor.bonus[i] - p->player->armor.sideBonus[i];
    }
    if (p->shownStats[i] > 99) {
      p->shownStats[i] = 99;
    }
    FUN_08098a98(p->shownStats[i], p->allocatedStats[i], &p->gfx.smenu, &p->sprites[48 + i * 2], &p->sprites[49 + i * 2]);
  }
}

// 2列8枚のスプライトを8ドットずつ下げながら並べて見せる
void FUN_08098bdc(MainMenu* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    p->sprites[i * 2 + 48].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[i * 2 + 48].pos.x = 40;
    p->sprites[i * 2 + 48].pos.y = i * 8 + 104;
    p->sprites[i * 2 + 49].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[i * 2 + 49].pos.x = 48;
    p->sprites[i * 2 + 49].pos.y = i * 8 + 104;
  }
  MainMenu_DrawStatusValues(p);
}

// ステータス画面に振り分け後の最大 HP / Ene と攻撃力, 防御力を描く
// 残差: 156/156 命令, 原典は最大値の掛け算を直接 r3 に作り, 拳の分岐の加算を別に置くが, こちらは r0 を経由して加算も1つにまとまる (掛け算の先出し, 別の変数は試済)
NON_MATCH void MainMenu_DrawStatusPreview(MainMenu* p) {
#ifdef NONMATCHING_C
  WeaponData w;
  s32 v;
  s32 max;
  s32 atk;

  v = p->shownStats[0] + p->allocatedStats[0];
  if (v > 99) {
    v = 99;
  }
  max = v * 10;
  MainMenu_DrawFraction(p, 1, p->player->hp, max, 5, 7);
  v = p->shownStats[1] + p->allocatedStats[1];
  if (v > 99) {
    v = 99;
  }
  max = v * 5 + 100;
  MainMenu_DrawFraction(p, 1, p->player->ene, max, 5, 8);
  GetRegisteredWeaponData(gStat->equippedWeaponIdx, &w);
  if (w.kind == 4) {
    MainMenu_DrawNumber(CalcAttackWithEquippedArmor(&w), 100, 6, 9, 0);
  } else {
    v = p->shownStats[2] + p->allocatedStats[2];
    if (v > 99) {
      v = 99;
    }
    atk = (v + gStat->lv) >> 1;
    if (w.kind == 3) {
      atk += (GetWeaponSkillLevel(3) + gStat->lv) >> 2;
    } else {
      s32 bonus = w.quality + w.atk;

      if (bonus < 0) {
        bonus = 0;
      }
      atk += bonus;
    }
    MainMenu_DrawNumber(atk, 100, 6, 9, 0);
  }
  v = p->shownStats[3] + p->allocatedStats[3];
  if (v > 99) {
    v = 99;
  }
  MainMenu_DrawNumber(((v + gStat->lv) >> 1) + p->player->armor.defence, 100, 6, 10, 0);
#else
  INCFUNC("asm/func/MainMenu_DrawStatusPreview.inc");
#endif
}

// ステータス4種のゲージのスプライトを, 現在値の位置と振り分け分を足した位置に並べる
void MainMenu_ShowStatBars(MainMenu* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    p->sprites[68 + i].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[68 + i].pos.x = p->shownStats[i] - 104;
    p->sprites[68 + i].pos.y = i * 8;
  }
  for (i = 0; i < 4; i++) {
    p->sprites[72 + i].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[72 + i].pos.x = p->sprites[68 + i].pos.x + p->allocatedStats[i];
    p->sprites[72 + i].pos.y = i * 8;
  }
}

// ステータスページのカーソルとバーの絵を statRow の行に合わせる
void MainMenu_MoveStatCursor(MainMenu* p) {
  p->sprites[13].pos.x = 0;
  p->sprites[13].pos.y = p->statRow << 3;
  MainSprite_SetPose(&p->sprites[46], &p->gfx.smenu, SMENU_STATBAR(p->statRow), PLAYMODE_LOOP);
}

// 振り分けたステータスポイントを確定して, 残りポイントも書き戻す
// 画面で振り分けたステータスを gStat に足して確定し, 残りポイントを書き戻す
void MainMenu_CommitStatAllocation(MainMenu* p) {
  s32 i;
  u16* point;

  for (i = 0; i < 4; i++) {
    *(gStat->stats + i) += p->allocatedStats[i];
    p->allocatedStats[i] = 0;
  }
  point = &gStat->statusPoint;
  *point = p->statusPoint;
}

// ステータスの振り分けをやめて, 残りポイントを gStat から読み直す (294 を超えていれば 0 に戻す)
void MainMenu_ResetStatAllocation(MainMenu* p) {
  s32 i;

  if (p->player->kind != PLAYER_SABATA) {
    if ((s16)gStat->statusPoint > 294) {
      gStat->statusPoint = 0;
    }
    p->statusPoint = gStat->statusPoint;
  } else {
    p->statusPoint = 0;
  }

  for (i = 0; i < 4; i++) {
    p->allocatedStats[i] = 0;
  }
}

// line が負ならテキストボックスを閉じ, そうでなければ画面下2行にその行を即時表示する
void MainMenu_ShowLineInstant(MainMenu* p, s32 line) {
  if (line < 0) {
    MessageWindow_Close();
  } else {
    MessageWindow_SetInstant(1);
    MessageWindow_Start(p->etcTexts);
    MessageWindow_SetRect(0, 18, 30, 2);
    MessageWindow_ShowLine(line);
  }
}

void MainMenu_StateStatsPageIdle(MainMenu* p) {
  p->hidden = FALSE;
  if (gInput[0].down & SELECT_BUTTON) {
    p->hidden = TRUE;
    MainMenu_DrawHP(p, 1, 5, 7);
    MainMenu_DrawEne(p, 1, 5, 8);
    MainMenu_HideButtonGuides(p);
  } else {
    MainMenu_DrawHPGauge(p, 1, 5, 7);
    MainMenu_DrawEneGauge(p, 1, 5, 8);
    MainMenu_SetButtonGuides(p, 0, -1);
  }
  p->sprites[66].flags |= SPRFLAG_HIDDEN;
  p->sprites[67].flags |= SPRFLAG_HIDDEN;
}

// ステータスページでポイントを振り分ける状態, 上下で行を選び左右で増減, A で確定の確認, B で振り分けを戻す
void MainMenu_StateAllocateStats(MainMenu* p) {
  bool32 changed;
  s32 i;

  p->hidden = FALSE;
  changed = FALSE;
  for (i = 0; i < 4; i++) {
    if (p->allocatedStats[i]) {
      changed = TRUE;
    }
  }
  if (!changed && (gInput[0].down & SELECT_BUTTON)) {
    p->hidden = TRUE;
    p->sprites[66].flags |= SPRFLAG_HIDDEN;
    p->sprites[67].flags |= SPRFLAG_HIDDEN;
    p->sprites[13].flags |= SPRFLAG_HIDDEN;
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    MainMenu_HideButtonGuides(p);
  } else {
    s32 input;

    p->hidden = changed;
    input = MainMenu_GetDpadRepeat(p);
    if (input & DPAD_UP) {
      p->statRow = (p->statRow + 3) & 3;
      MainMenu_MoveStatCursor(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
      p->pendingLine = p->statRow + 20;
    } else if (input & DPAD_DOWN) {
      p->statRow = (p->statRow + 1) & 3;
      MainMenu_MoveStatCursor(p);
      PlaySound_082406e0(SE_CURSOR_MOVE);
      p->pendingLine = p->statRow + 20;
    } else if (input & DPAD_LEFT) {
      if (p->allocatedStats[p->statRow]) {
        p->allocatedStats[p->statRow]--;
        p->statusPoint++;
        MainMenu_DrawStatusValues(p);
        MainMenu_ShowStatBars(p);
        PlaySound_082406e0(SE_DRUMROLL);
      }
    } else if (input & DPAD_RIGHT) {
      if (p->statusPoint && p->player->stats[p->statRow] + p->allocatedStats[p->statRow] <= 98 && p->shownStats[p->statRow] <= 98) {
        p->allocatedStats[p->statRow]++;
        p->statusPoint--;
        MainMenu_DrawStatusValues(p);
        MainMenu_ShowStatBars(p);
        PlaySound_082406e0(SE_DRUMROLL);
      }
    } else if ((gInput[0].pressed & A_BUTTON) && p->hidden) {
      PlaySound_082406e0(SE_SELECT);
      p->pendingLine = 24;
      MainMenu_ShowYesNo(p, 0);
      MainMenu_SetState(p, MainMenu_StateConfirmStatus, TRUE);
    } else if (gInput[0].pressed & B_BUTTON) {
      PlaySound_082406e0(SE_CANCEL);
      MainMenu_ResetStatAllocation(p);
      MainMenu_DrawStatusValues(p);
      MainMenu_ShowStatBars(p);
    }

    p->sprites[66].flags &= ~SPRFLAG_HIDDEN;
    if (p->hidden) {
      p->sprites[67].flags &= ~SPRFLAG_HIDDEN;
      MainMenu_HideButtonGuides(p);
    } else {
      p->sprites[67].flags |= SPRFLAG_HIDDEN;
      MainMenu_SetButtonGuides(p, 0, -1);
    }
    p->sprites[46].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
    MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
  }
  MainMenu_DrawStatusPreview(p);
  if (p->pendingLine >= 0) {
    MainMenu_ShowLineInstant(p, p->pendingLine);
    p->pendingLine = -1;
  }
}

// ステータス振り分けの はい/いいえ, はい で確定し, ポイントが残っていれば振り分けに戻る
void MainMenu_StateConfirmStatus(MainMenu* p) {
  s32 result = MainMenu_UpdateYesNo(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_ShowLineInstant(p, p->statRow + 20);
    MainMenu_SetButtonGuides(p, 0, -1);
    MainMenu_SetState(p, MainMenu_StateAllocateStats, TRUE);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    MainMenu_CommitStatAllocation(p);
    Player_RefreshAllStats(p->player);
    MainMenu_DrawStatusValues(p);
    MainMenu_ShowStatBars(p);
    MainMenu_DrawEquipStats(p, 5, 7);
    MainMenu_SetButtonGuides(p, 0, -1);
    if (p->statusPoint == 0) {
      p->sprites[13].flags |= SPRFLAG_HIDDEN;
      p->sprites[46].flags |= SPRFLAG_HIDDEN;
      MainMenu_ShowLineInstant(p, -1);
      MainMenu_SetState(p, MainMenu_StateStatsPageIdle, FALSE);
    } else {
      MainMenu_ShowLineInstant(p, p->statRow + 20);
      MainMenu_DrawHP(p, 1, 5, 7);
      MainMenu_DrawEne(p, 1, 5, 8);
      MainMenu_SetState(p, MainMenu_StateAllocateStats, FALSE);
    }
  }
}

// 次のレベルになるために必要な"総"経験値量を返す
static u32 MainMenu_GetNextLvExp(MainMenu* p) {
  u32* exp = p->expTable;
  exp += gStat->lv;
  return 10 * (*exp);
}

// ステータス画面にレベル, 経験値, 次のレベルまでの経験値, 武器ごとの熟練度を描く, サバタはレベル以外を伏せる
void MainMenu_DrawStatusNumbers(MainMenu* p) {
  s32 i;

  if (p->player->kind != PLAYER_SABATA) {
    MainMenu_DrawNumber(MinS32(gStat->lv, 99), 10, 21, 3, 0);
    MainMenu_DrawNumber(MinS32(gStat->exp, 999999), 100000, 23, 4, 0);
    if (gStat->lv > 98) {
      BgMapEntry* map = MainMenu_GetBgMapAddr(0, 23, 5);

      for (i = 0; i < 6; i++) {
        *map++ = 0xF0BC;
      }
    } else {
      MainMenu_DrawNumber(MinS32(MainMenu_GetNextLvExp(p), 999999), 100000, 23, 5, 0);
    }
    for (i = 0; i < 5; i++) {
      bool32 known = FALSE;

      if (i == 0) {
        if (REGISTERED_WEAPON(0) >= 0 && GetWeaponKind(REGISTERED_WEAPON(0)) == 0) {
          known = TRUE;
        }
      } else if (i == 1 || i == 2) {
        if (REGISTERED_WEAPON(i) >= 0) {
          known = TRUE;
        }
      } else {
        known = TRUE;
      }
      if (known) {
        MainMenu_DrawNumber(MinS32(GetWeaponSkillLevel(i), 99), 10, (i & 1) * 5 + 20, (i >> 1) + 8, 0);
      } else {
        BgMapEntry* map = MainMenu_GetBgMapAddr(0, (i & 1) * 5 + 18, (i >> 1) + 8);
        s32 j;

        for (j = 0; j < 2; j++) {
          *map++ = 0xF001;
        }
      }
    }
  } else {
    MainMenu_DrawNumber(MinS32(gStat->lv + 10, 99), 10, 21, 3, 0);
    FUN_0808b360(6, 23, 4);
    FUN_0808b360(6, 23, 5);
    FUN_0808b360(2, 20, 8);
    FUN_0808b360(2, 25, 8);
    FUN_0808b360(2, 20, 9);
    FUN_0808b360(2, 25, 9);
    MainMenu_DrawNumber(99, 10, 20, 10, 0);
  }
}

void MainMenu_ShowStatCursor(MainMenu* p, s32 row) {
  p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetAnim(&p->sprites[13], &p->gfx.smenu, 2, PLAYMODE_LOOP, 0);
  p->sprites[46].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[46], &p->gfx.smenu, 66, PLAYMODE_LOOP);
  p->sprites[46].pos.x = 0;
  p->sprites[46].pos.y = 0;
  p->sprites[46].pos.z = 0;
  MainSprite_SetPltt(&p->sprites[46], 677);
  p->statRow = row;
  MainMenu_MoveStatCursor(p);
}

// PAGE_STATS で使われるプレイヤーの肩書き部分 (56px, 32px) のタイル番号 (専用のタイルフォント, 0x01 が空白タイル)
const u8 sPlayerTitles[3][12] = {
    [PT_RDJANGO] = {0xB4, 0x91, 0xAF, 0xA9, 0xB3, 0x01, 0xAA, 0x91, 0xB8, 0x01, 0x01, 0x01}, // "SOLAR BOY"
    [PT_BDJANGO] = {0xB7, 0xA9, 0xB0, 0xB2, 0xAD, 0xB3, 0xAC, 0x01, 0xAA, 0x91, 0xB8, 0x01}, // "VAMPIRE BOY"
    [PT_SABATA] = {0xAB, 0xA9, 0xB3, 0xAE, 0x01, 0xAA, 0x91, 0xB8, 0x01, 0x01, 0x01, 0x01}, // "DARK BOY"
};  // 0x085ACFB8

// ステータスページにプレイヤーの肩書きを描き, 説明文を出す
void MainMenu_ShowPlayerTitle(MainMenu* p) {
  u8 kind = p->player->kind;
  BgMapEntry* dst;
  s32 idx;
  s32 i;

  idx = PT_RDJANGO;
  if (kind != PLAYER_SOLAR_DJANGO) {
    idx = PT_BDJANGO;
    if (kind == PLAYER_SABATA) {
      idx = PT_SABATA;
    }
  }

  dst = MainMenu_GetBgMapAddr(0, 6, 3);
  for (i = 0; i < 11; i++) {
    *dst++ = sPlayerTitles[idx][i] | BGMAP_BGP15;
  }

  TextPanel_SetScript(p->textPanelID_4014, p->etcTexts);
  if (idx == 2) {
    TextPanel_SetMessage(p->textPanelID_4014, 1);
  } else {
    TextPanel_SetMessage(p->textPanelID_4014, 0);
  }
  TextPanel_Start(p->textPanelID_4014);
}

// ステータスページで, かかっている状態異常 (カーモス・エフェクト・毒・混乱・腹痛) のアイコンを横に並べ, なければ欄を消す
void MainMenu_ShowStatsCondIcons(MainMenu* p) {
  Vec3 pos;
  s32 n = 0;

  pos.x = 0, pos.y = 0, pos.z = 0;
  if (KAAMOS(p->player->isSabata) > 0) {
    MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 180, PLAYMODE_LOOP);
    p->sprites[62 + n].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[62 + n].pos = pos;
    pos.x += 12;
    n++;
  }
  if (p->player->emitter.unk_3) {
    if (p->player->emitter.kind == 1) {
      MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 178, PLAYMODE_LOOP);
    } else if (p->player->emitter.kind == 2) {
      MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 177, PLAYMODE_LOOP);
    } else {
      MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 179, PLAYMODE_LOOP);
    }
    p->sprites[62 + n].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[62 + n].pos = pos;
    pos.x += 12;
    n++;
  } else if (p->player->badCondTimer[BAD_POISON]) {
    MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 181, PLAYMODE_LOOP);
    p->sprites[62 + n].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[62 + n].pos = pos;
    pos.x += 12;
    n++;
  }
  if (p->player->badCondTimer[2]) {
    MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 182, PLAYMODE_LOOP);
    p->sprites[62 + n].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[62 + n].pos = pos;
    pos.x += 12;
    n++;
  }
  if (p->player->badCondTimer[0]) {
    MainSprite_SetPose(&p->sprites[62 + n], &p->gfx.smenu, 183, PLAYMODE_LOOP);
    p->sprites[62 + n].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[62 + n].pos = pos;
    n++;
  }
  if (n == 0) {
    FUN_0808b97c(10, 9, 6, 1);
  }
  for (; n < 4; n++) {
    p->sprites[62 + n].flags |= SPRFLAG_HIDDEN;
  }
}

void MainMenu_InitPage_Stats(MainMenu* p) {
  MessageWindow_Close();
  Marquee_Clear();
  Marquee_RequestClose();
  TextPanel_Hide(p->textPanelID_4014);
  TextPanel_Hide(p->textPanelID);
  FUN_0808a3c4(p, p->tm_18, 0, 10, p->bgp_30);
  MainMenu_DrawStatusNumbers(p);
  MainMenu_DrawEquipStats(p, 5, 7);
  MainMenu_DrawMoney(p);
  FUN_0808b82c(p);
  MainMenu_ShowPageName(p, p->page);
  p->sprites[61].flags &= ~SPRFLAG_HIDDEN;
  if (p->player->kind == PLAYER_SOLAR_DJANGO) {
    MainSprite_SetPose(&p->sprites[61], &p->gfx.portraits, 0, PLAYMODE_LOOP);
  } else if (p->player->kind == PLAYER_SABATA) {
    MainSprite_SetPose(&p->sprites[61], &p->gfx.portraits, 3, PLAYMODE_LOOP);
  } else {
    MainSprite_SetPose(&p->sprites[61], &p->gfx.portraits, 1, PLAYMODE_LOOP);
  }
  MainMenu_ResetStatAllocation(p);
  MainMenu_ShowStatCursor(p, 0);
  FUN_08098bdc(p);
  MainMenu_ShowStatBars(p);
  MainMenu_ShowStatsCondIcons(p);
  MainMenu_ShowPlayerTitle(p);
  FUN_0808c61c(p, -16, 0);
  MainMenu_SetButtonGuides(p, 0, -1);
  if (p->statusPoint == 0) {
    p->sprites[13].flags |= SPRFLAG_HIDDEN;
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    p->pendingLine = -1;
    MainMenu_ShowLineInstant(p, -1);
    MainMenu_SetState(p, MainMenu_StateStatsPageIdle, FALSE);
  } else {
    p->sprites[66].flags &= ~SPRFLAG_HIDDEN;
    MainMenu_DrawHP(p, 1, 5, 7);
    MainMenu_DrawEne(p, 1, 5, 8);
    p->pendingLine = p->statRow + 20;
    MainMenu_ShowLineInstant(p, p->pendingLine);
    MainMenu_SetState(p, MainMenu_StateAllocateStats, FALSE);
  }
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
}

void FUN_08099b3c(s32 param_1) {
  if (param_1 < 0) {
    MessageWindow_Close();
  } else {
    MessageWindow_SetInstant(TRUE);
    MessageWindow_ShowLine(param_1);
  }
}

/**
 * @brief gStat->textSpeed の値を変換して返す (なんでこんなことをするのかは不明)
 * @return 変換後のメッセージ速度の値 (0: 遅い, 1: 普通, 2: 速い), config[CONFIG_TEXT_SPEED] はこの値を保持する
 */
s32 MainMenu_GetTextSpeed(void) {
  if (gStat->textSpeed == 1) return 2;  // 設定で "速い" を選んだ時
  if (gStat->textSpeed == 2) return 1;  // "普通"
  return 0;                             // "遅い"
}

/**
 * @brief menuTextSpeed 形式を gStat->textSpeed 形式に変換して返す (なんでこんなことをするのかは不明)
 * @param n config[CONFIG_TEXT_SPEED] の値 (0: 遅い, 1: 普通, 2: 速い)
 * @return 変換後の gStat->textSpeed の値 (1: 速い, 2: 普通, 4: 遅い)
 */
s32 FUN_08099b84(s32 n) {
  if (n == 0) return 4;  // 設定で "遅い" を選んだ時
  if (n == 1) return 2;  // "普通"
  return 1;              // "速い"
}

// コンフィグページの設定を gStat に書き戻してセーブ対象にし, 混乱中でなければプレイヤーの操作方向にも反映する
void MainMenu_ApplyConfig(MainMenu* p) {
  Player* player;
  s16 speed;
  s16* textSpeed;
  s16* marker;

  gStat->controlUp = p->config[CONFIG_CONTROL];
  speed = FUN_08099b84(p->config[CONFIG_TEXT_SPEED]);
  textSpeed = &gStat->textSpeed;
  *textSpeed = speed;
  marker = &gStat->markerEnabled;
  *marker = p->config[CONFIG_MARKER];
  FUN_08231d5c(&gStat->controlUp, 2);
  FUN_08231d5c(&gStat->textSpeed, 2);
  FUN_08231d5c(&gStat->markerEnabled, 2);
  player = p->player;
  if (player->badCondTimer[2] == 0) {
    player->controlUp = gStat->controlUp;
  }
}

void MainMenu_LoadGameConfig(MainMenu* p) {
  p->configRow = 0;
  p->config[CONFIG_CONTROL] = gStat->controlUp;
  p->config[CONFIG_TEXT_SPEED] = MainMenu_GetTextSpeed();
  p->config[CONFIG_MARKER] = gStat->markerEnabled;
}

// コンフィグの3項目の設定値を描く, param_2 が 0 ならカーソルを隠し, そうでなければ選択中の行を強調する
void MainMenu_ShowConfigOptions(MainMenu* p, s32 param_2) {
  s32 control;
  s32 speed;
  s32 marker;

  if (param_2 == 0) {
    p->sprites[13].flags |= SPRFLAG_HIDDEN;
    control = 79;
    speed = 82;
    marker = 85;
  } else {
    p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[13].pos.y = p->configRow << 4;
    if (p->configRow == 0) {
      control = 87;
      speed = 82;
      marker = 85;
    } else if (p->configRow == 1) {
      control = 79;
      speed = 90;
      marker = 85;
    } else {
      control = 79;
      speed = 82;
      marker = 93;
    }
  }
  MainSprite_SetPose(&p->sprites[36], &p->gfx.smenu, p->config[CONFIG_CONTROL] + control, PLAYMODE_LOOP);
  MainSprite_SetPose(&p->sprites[37], &p->gfx.smenu, p->config[CONFIG_TEXT_SPEED] + speed, PLAYMODE_LOOP);
  MainSprite_SetPose(&p->sprites[38], &p->gfx.smenu, marker + 1 - p->config[CONFIG_MARKER], PLAYMODE_LOOP);
}

// コンフィグページの十字キー, 左右で選択中の項目の値を回し, 上下で行を動かす, 何か動いたら TRUE
s32 MainMenu_HandleConfigInput(MainMenu* p) {
  if (gInput[0].pressed & DPAD_RIGHT) {
    if (p->configRow <= 1) {
      if (p->config[p->configRow] > 1) {
        p->config[p->configRow] = 0;
      } else {
        p->config[p->configRow]++;
      }
    } else {
      p->config[p->configRow] = 1 - p->config[p->configRow];
    }
    PlaySound_082406e0(SE_DRUMROLL);
    return TRUE;
  }
  if (gInput[0].pressed & DPAD_LEFT) {
    if (p->configRow <= 1) {
      if (p->config[p->configRow] == 0) {
        p->config[p->configRow] = 2;
      } else {
        p->config[p->configRow]--;
      }
    } else {
      p->config[p->configRow] = 1 - p->config[p->configRow];
    }
    PlaySound_082406e0(SE_DRUMROLL);
    return TRUE;
  }
  if (gInput[0].pressed & DPAD_UP) {
    if (p->configRow == 0) {
      p->configRow = 2;
    } else {
      p->configRow--;
    }
    PlaySound_082406e0(SE_CURSOR_MOVE);
    return TRUE;
  }
  if (gInput[0].pressed & DPAD_DOWN) {
    if (p->configRow == 2) {
      p->configRow = 0;
    } else {
      p->configRow++;
    }
    PlaySound_082406e0(SE_CURSOR_MOVE);
    return TRUE;
  }
  return FALSE;
}

void FUN_08099e2c(MainMenu* p) {
  if (gInput[0].pressed & A_BUTTON) {
    PlaySound_082406e0(SE_SELECT);
    MainMenu_ShowConfigOptions(p, 1);
    FUN_08099b3c(6);
    MainMenu_HideButtonGuides(p);
    MainMenu_SetState(p, MainMenu_UpdateConfig, 1);
  }
}

// コンフィグページの操作, A で設定を確定し, B で元に戻して抜ける
void MainMenu_UpdateConfig(MainMenu* p) {
  if (gInput[0].pressed & A_BUTTON) {
    PlaySound_082406e0(SE_SELECT);
    MainMenu_ApplyConfig(p);
    MainMenu_ShowConfigOptions(p, 0);
    FUN_08099b3c(7);
    MainMenu_SetState(p, FUN_08099f18, TRUE);
  } else if (gInput[0].pressed & B_BUTTON) {
    PlaySound_082406e0(SE_CANCEL);
    MainMenu_LoadGameConfig(p);
    MainMenu_ShowConfigOptions(p, 0);
    FUN_08099b3c(5);
    MainMenu_SetButtonGuides(p, 0, -1);
    MainMenu_SetState(p, FUN_08099e2c, FALSE);
  } else {
    if (MainMenu_HandleConfigInput(p)) {
      MainMenu_ShowConfigOptions(p, 1);
    }
    MainSprite_AdvanceAnim(&p->sprites[13], &p->gfx.smenu);
  }
}

// 60フレーム待ってから FUN_08099e2c へ戻る
void FUN_08099f18(MainMenu* p) {
  p->stateTimer++;
  if (p->stateTimer > 59) {
    FUN_08099b3c(5);
    MainMenu_SetButtonGuides(p, 0, -1);
    MainMenu_SetState(p, FUN_08099e2c, 0);
  }
}

// コンフィグページの3項目とカーソルのスプライトを用意し, 今の設定を読んで描く
void MainMenu_SetupConfigSprites(MainMenu* p) {
  MainMenu_LoadGameConfig(p);
  p->sprites[36].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[36].pos.x = 0, p->sprites[36].pos.y = 0, p->sprites[36].pos.z = 0;
  MainSprite_SetPltt(&p->sprites[36], 677);
  MainSprite_SetPose(&p->sprites[36], &p->gfx.smenu, 79, PLAYMODE_LOOP);
  p->sprites[37].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[37].pos.x = 0, p->sprites[37].pos.y = 0, p->sprites[37].pos.z = 0;
  MainSprite_SetPltt(&p->sprites[37], 677);
  MainSprite_SetPose(&p->sprites[37], &p->gfx.smenu, 82, PLAYMODE_LOOP);
  p->sprites[38].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[38].pos.x = 0, p->sprites[38].pos.y = 0, p->sprites[38].pos.z = 0;
  MainSprite_SetPltt(&p->sprites[38], 677);
  MainSprite_SetPose(&p->sprites[38], &p->gfx.smenu, 85, PLAYMODE_LOOP);
  p->sprites[13].pos.x = 0, p->sprites[13].pos.y = 0, p->sprites[13].pos.z = 0;
  MainSprite_SetAnim(&p->sprites[13], &p->gfx.smenu, 3, PLAYMODE_LOOP, 0);
  MainMenu_ShowConfigOptions(p, 0);
}

void MainMenu_InitPage_Config(MainMenu* p) {
  MessageWindow_Close();
  Marquee_Clear();
  Marquee_RequestClose();
  TextPanel_Hide(p->textPanelID_4014);
  TextPanel_Hide(p->textPanelID);
  MessageWindow_SetRect(0, 16, 30, 2);
  FUN_0808a3c4(p, p->tm_18, 0, 11, p->bgp_30);
  FUN_0808b82c(p);
  MainMenu_ShowPageName(p, p->page);
  MainMenu_SetupConfigSprites(p);
  MessageWindow_Start(p->etcTexts);
  MessageWindow_SetBgPltt(BGP_EFDA);
  FUN_08099b3c(5);
  FUN_0808c61c(p, 0, -16);
  MainMenu_SetButtonGuides(p, 0, -1);
  MainMenu_SetState(p, FUN_08099e2c, FALSE);
}

void FUN_0809a130(MainMenu* p) {
  if (gInput[0].pressed & A_BUTTON) {
    PlaySound_082406e0(SE_SELECT);
    MainMenu_ShowYesNo(p, 0);
    FUN_08099b3c(18);
    MainMenu_HideButtonGuides(p);
    MainMenu_SetState(p, FUN_0809a1a4, TRUE);
    TextPanel_SetRect(p->textPanelID, 4, 6, 22, 6);
    TextPanel_SetScript(p->textPanelID, p->etcTexts);
    TextPanel_SetMessage(p->textPanelID, 16);
    TextPanel_Start(p->textPanelID);
  }
}

void FUN_0809a20c(MainMenu* p);

void FUN_0809a1a4(MainMenu* p) {
  s32 result = MainMenu_UpdateYesNo(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_08099b3c(17);
    TextPanel_Hide(p->textPanelID);
    MainMenu_SetButtonGuides(p, 0, -1);
    MainMenu_SetState(p, FUN_0809a130, 0);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    FUN_08099b3c(19);
    MainMenu_SetState(p, FUN_0809a20c, 1);
  }
}

void FUN_0809a20c(MainMenu* p) {
  gSoftResetInhibit = TRUE;

  p->stateTimer++;
  if (p->stateTimer > 119) {
    FUN_08099b3c(17);
    TextPanel_Hide(p->textPanelID);
    MainMenu_SetButtonGuides(p, 0, -1);
    MainMenu_SetState(p, FUN_0809a130, 0);
    p->unk_400c = 30;
    SleepGame();
  }
}

void MainMenu_InitPage_Sleep(MainMenu* p) {
  MessageWindow_Close();
  Marquee_Clear();
  Marquee_RequestClose();
  TextPanel_Hide(p->textPanelID_4014);
  TextPanel_Hide(p->textPanelID);
  MessageWindow_SetRect(0, 16, 30, 2);
  FUN_0808a3c4(p, p->tm_18, 0, 11, p->bgp_30);
  FUN_0808b82c(p);
  MainMenu_ShowPageName(p, p->page);
  MessageWindow_Start(p->etcTexts);
  MessageWindow_SetBgPltt(BGP_EFDA);
  FUN_08099b3c(17);
  p->unk_400c = 0;
  FUN_0808c61c(p, 0, -16);
  MainMenu_SetButtonGuides(p, 0, -1);
  MainMenu_SetState(p, FUN_0809a130, FALSE);
}

void FUN_0809a324(MainMenu* p) {
  if (gInput[0].pressed & A_BUTTON) {
    PlaySound_082406e0(SE_SELECT);
    MainMenu_ShowYesNo(p, 1);
    FUN_08099b3c(9);
    MainMenu_HideButtonGuides(p);
    MainMenu_SetState(p, FUN_0809a368, 1);
  }
}

void FUN_0809a368(MainMenu* p) {
  u32 result = MainMenu_UpdateYesNo(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_08099b3c(8);
    MainMenu_SetButtonGuides(p, 0, -1);
    MainMenu_SetState(p, FUN_0809a324, FALSE);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    if (gStat->unk_93a == 0) {
      MainMenu_SetState(p, FUN_0809a448, TRUE);
    } else {
      MainMenu_ShowYesNo(p, 1);
      FUN_08099b3c(10);
      MainMenu_SetState(p, FUN_0809a3f4, TRUE);
    }
  }
}

void FUN_0809a448(MainMenu* p);

void FUN_0809a3f4(MainMenu* p) {
  s32 result = MainMenu_UpdateYesNo(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_08099b3c(8);
    MainMenu_SetButtonGuides(p, 0, -1);
    MainMenu_SetState(p, FUN_0809a324, 0);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    MainMenu_SetState(p, FUN_0809a448, 1);
  }
}

void FUN_0809a448(MainMenu* p) {
  u16* timer;

  gSoftResetInhibit = TRUE;
  timer = &p->stateTimer;
  if (*timer == 0) {
    s32* panel = &p->textPanelID;

    TextPanel_SetRect(*panel, 2, 6, 26, 6);
    TextPanel_SetScript(*panel, p->etcTexts);
    TextPanel_SetMessage(*panel, 13);
    TextPanel_Start(*panel);
    FUN_08099b3c(12);
  }

  if (++*timer >= 60) {
    MainMenu_SetState(p, FUN_0809a4c0, TRUE);
  }
}

void FUN_0809a510(MainMenu* p);
void FUN_0809a574(MainMenu* p);

// セーブを実行し, 成功なら FUN_0809a510、失敗なら FUN_0809a574 へ進む
void FUN_0809a4c0(MainMenu* p) {
  gSoftResetInhibit = TRUE;

  if (Save_WriteToNextSlot()) {
    gStat->unk_93a = 1;
    MainMenu_SetState(p, FUN_0809a510, 1);
  } else {
    MainMenu_SetState(p, FUN_0809a574, 1);
  }
}

void FUN_0809a510(MainMenu* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_SAVE_SUCCESS);
    TextPanel_Hide(p->textPanelID);
    FUN_08099b3c(14);
  }

  p->stateTimer++;
  if (p->stateTimer >= 120) {
    FUN_08099b3c(8);
    MainMenu_SetButtonGuides(p, 0, -1);
    MainMenu_SetState(p, FUN_0809a324, 0);
  }
}

void FUN_0809a574(MainMenu* p) {
  if (p->stateTimer == 0) {
    PlaySound_082406e0(SE_NG);
    TextPanel_Hide(p->textPanelID);
    FUN_08099b3c(15);
  }

  p->stateTimer++;
  if (p->stateTimer >= 120) {
    FUN_08099b3c(8);
    MainMenu_SetButtonGuides(p, 0, -1);
    MainMenu_SetState(p, FUN_0809a324, 0);
  }
}

void MainMenu_InitPage_Save(MainMenu* p) {
  MessageWindow_Close();
  Marquee_Clear();
  Marquee_RequestClose();
  TextPanel_Hide(p->textPanelID_4014);
  TextPanel_Hide(p->textPanelID);
  MessageWindow_SetRect(0, 16, 30, 2);
  FUN_0808a3c4(p, p->tm_18, 0, 11, p->bgp_30);
  FUN_0808b82c(p);
  MainMenu_ShowPageName(p, p->page);
  MessageWindow_Start(p->etcTexts);
  MessageWindow_SetBgPltt(BGP_EFDA);
  FUN_08099b3c(8);
  FUN_0808c61c(p, 0, -16);
  MainMenu_SetButtonGuides(p, 0, -1);
  MainMenu_SetState(p, FUN_0809a324, FALSE);
}

void MainMenu_InitPage(MainMenu* p) {
  static void (*const sPageInitFuncs[10])(MainMenu*) = {
      [PAGE_MAP] = MainMenu_InitPage_Map,
      [PAGE_ITEM] = MainMenu_InitPage_Item,
      [PAGE_VALUABLE] = MainMenu_InitPage_Valuable,
      [PAGE_WEAPON] = MainMenu_InitPage_Weapon,
      [PAGE_ARMOR] = MainMenu_InitPage_Armor,
      [PAGE_MAGIC] = MainMenu_InitPage_Magic,
      [PAGE_STATS] = MainMenu_InitPage_Stats,
      [PAGE_CONFIG] = MainMenu_InitPage_Config,
      [PAGE_SLEEP] = MainMenu_InitPage_Sleep,
      [PAGE_SAVE] = MainMenu_InitPage_Save,
  };  // 0x085ACFDC

  sPageInitFuncs[p->page](p);
  MainMenu_DrawClock(p);
}

// メニューを開くとき, BG1 のタイルマップと状態, BLDCNT / BG1CNT, モザイクの設定を退避してページを初期化する
void MainMenu_SaveBg(MainMenu* p) {
  BgMapEntry* src;
  s32 i;

  p->unk_9fc = 1;
  gSpriteListIdx = 1;
  p->savedDISPCNT = gStagedDISPCNT;
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG0_ON);
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG2_ON);
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG3_ON);
  src = GetTilemapBuffer(1);
  CpuCopy32(src, p->savedTilemap1, sizeof(p->savedTilemap1));
  p->savedBg1 = gBgStates[1];
  p->savedBLDCNT = REG_BLDCNT;
  p->savedBG1CNT = REG_BG1CNT;
  REG_BLDCNT = 0;
  gBgBrightness2 = 64;
  SetBGCharBaseDirect(1, 2);
  SetBGPrioDirect(1, 1);
  p->savedMosaicDirty = gMosaicDirty;
  p->savedMosaicSize = gMosaicSize;
  p->savedObjMosaicEnabled = gObjMosaicEnabled;
  p->savedMosaicTargets = gMosaicTargets;
  Video_ClearMosaic();
  SET_FLAGS(gStagedDISPCNT, DISPCNT_BG0_ON);
  for (i = 0; i < 10; i++) {
    p->sprites[3 + i].flags |= SPRFLAG_HIDDEN;
  }
  p->unk_3ae4 = 0;
  MainMenu_InitPage(p);
  p->pendingLine = -1;
}

void UNUSED FUN_0809a800(void) { LoadParticleFile(GetFile(DIR_PARTICLE, 0x3002)); }

// メニューを閉じるとき, 開くときに退避した BG1 のタイルマップと状態, モザイクの設定を戻す
void MainMenu_RestoreBg(MainMenu* p) {
  BgMapEntry* dst;
  s32* id;
  s32 i;

  p->unk_9fc = 0;
  gSpriteListIdx = 0;
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG0_ON);
  CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
  SetBGCharBaseDirect(1, 0);
  dst = GetTilemapBuffer(1);
  CpuCopy32(p->savedTilemap1, dst, sizeof(p->savedTilemap1));
  gBgStates[1] = p->savedBg1;
  REG_BG1CNT = p->savedBG1CNT;
  gMosaicDirty = 1;
  gMosaicSize = p->savedMosaicSize;
  gObjMosaicEnabled = p->savedObjMosaicEnabled;
  gMosaicTargets = p->savedMosaicTargets;
  MessageWindow_Close();
  Marquee_RequestClose();
  id = &p->textPanelID_4014;
  for (i = 0; i < 2; i++) {
    TextPanel_Hide(*id++);
  }
  SET_FLAGS(gStagedDISPCNT, DISPCNT_BG0_ON);
  FUN_0808a3c4(p, p->tm_18, 0, 0, p->bgp_30);
  p->unk_a30 = 0;
  p->unk_a31 = 0;
  FUN_0808ce98(p);
}

// スタートメニューで引数の page の次のページ番号を返す
s32 MainMenu_GetNextPage(MainMenu* p, s32 page) {
  s32 idx = page + 1;
  s32 i;

  if (idx > PAGE_SAVE) {
    idx = PAGE_MAP;
  }
  for (i = 0; i < PAGE_NUM; i++) {
    if (p->availPages[idx]) {
      return idx;
    }
    idx++;
    if (idx > PAGE_SAVE) {
      idx = PAGE_MAP;
    }
  }
  return page;
}

// スタートメニューで引数の page の前のページ番号を返す
s32 MainMenu_GetPrevPage(MainMenu* p, s32 page) {
  s32 idx = page - 1;
  s32 i;

  if (page == PAGE_MAP) {
    idx = PAGE_SAVE;
  }
  for (i = 0; i < PAGE_NUM; i++) {
    if (p->availPages[idx]) {
      return idx;
    }
    if (idx == 0) {
      idx = PAGE_SAVE;
    } else {
      idx--;
    }
  }
  return page;
}

// サイドバーにページ名のスプライトを並べる, 選べるページを上から詰め, 残りの枠は空欄にする
// 残差: 127/129 命令, 原典は sprites[3 + n] の先頭と flags の2本のポインタを誘導変数に持ち, 先頭側をスタックに逃がすが, こちらは i を r7 に置いて availPages の添字にする (スプライトのポインタ変数, ブロック局所のポインタ, 宣言順は試済)
NON_MATCH void MainMenu_SetupPageSidebar(MainMenu* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 i;
  s32 n;

  n = 0;
  pos.x = -120, pos.y = 0, pos.z = 0;
  for (i = 0; i < PAGE_NUM; i++) {
    if (p->availPages[i]) {
      p->sprites[3 + n].flags &= ~SPRFLAG_HIDDEN;
      MainSprite_SetPose(&p->sprites[3 + n], &p->gfx.smenu, i + 100, PLAYMODE_LOOP);
      pos.y = (n - i) * 16;
      p->sprites[3 + n].pos = pos;
      if (i == p->pageCursor) {
        MainSprite_SetPltt(&p->sprites[3 + n], 677);
      } else {
        MainSprite_SetPltt(&p->sprites[3 + n], 678);
      }
      n++;
    }
  }
  for (; n < PAGE_NUM; n++) {
    p->sprites[3 + n].flags &= ~SPRFLAG_HIDDEN;
    pos.y = n * 16;
    p->sprites[3 + n].pos = pos;
    MainSprite_SetPose(&p->sprites[3 + n], &p->gfx.smenu, 99, PLAYMODE_LOOP);
    MainSprite_SetPltt(&p->sprites[3 + n], 677);
  }
#else
  INCFUNC("asm/func/MainMenu_SetupPageSidebar.inc");
#endif
}

void FUN_0809aaf4(MainMenu* p) {
  u16* timer = &p->updateTimer;

  if (*timer == 1) {
    FUN_082407e0();
  }
  if (*timer == 2) {
    PlaySound_082406e0(SE_OPEN_MENU);
  }
  if (*timer < 16) {
    SetScreenBrightness(64 - *timer * 4, 0x1084);
  } else {
    SetScreenBrightness(0, 0x1084);
  }

  if (++p->updateTimer >= 19) {
    MainMenu_SaveBg(p);
    MainMenu_SetUpdateCallback(p, FUN_0809ab70);
  }
}

void MainMenu_UpdatePage(MainMenu* p);

// 17フレームかけて明るさを上げ, 終わったら次の状態へ移る
void FUN_0809ab70(MainMenu* p) {
  MainMenu_DrawClock(p);
  SetScreenBrightness(p->updateTimer * 4, RGB(4, 4, 4));
  p->updateTimer++;
  if (p->updateTimer > 16) {
    p->hidden = 0;
    MainMenu_SetUpdateCallback(p, MainMenu_UpdatePage);
  }
}

void FUN_0809abbc(void) {
  BgMapEntry* tile;

  if ((*(u32*)gInput & 0x20004) == 0x20004) {
    if (u16_03004864 != 0) {
      Cmd_4B39();
    } else {
      Cmd_4B57();
    }
  }

  tile = MainMenu_GetBgMapAddr(0, 27, 0);
  if (u16_03004864 != 0) {
    *tile++ = 0xF001;
    *tile++ = 0xF091;
    *tile = 0xF0B1;
  } else {
    *tile++ = 0xF091;
    *tile++ = 0xF072;
    *tile = 0xF072;
  }
}

// ページを開いている間の更新, L/R でページを送り, START でサイドバー, B で閉じ, それ以外はページの状態関数 fn を進める
void MainMenu_UpdatePage(MainMenu* p) {
  SetScreenBrightness(64, 0x1084);
  MainMenu_DrawClock(p);
  if (p->unk_3ae4) {
    MainMenu_SetUpdateCallback(p, MainMenu_UpdateFadeOut);
    return;
  }
  if (p->hidden) {
    p->sprites[1].flags |= SPRFLAG_HIDDEN;
    p->sprites[2].flags |= SPRFLAG_HIDDEN;
    p->fn(p);
  } else {
    p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
    if (gInput[0].pressed & B_BUTTON) {
      PlaySound_082406e0(SE_CLOSE_MENU);
      MainMenu_SetUpdateCallback(p, MainMenu_UpdateFadeOut);
      return;
    }
    if (gInput[0].pressed & START_BUTTON) {
      p->pageCursor = p->page;
      MainMenu_SetupPageSidebar(p);
      PlaySound_082406e0(SE_SIDEBAR_TOGGLE);
      MainMenu_SetUpdateCallback(p, FUN_0809b12c);
      return;
    }
    if (p->unk_400c == 0) {
      s32 dir = 0;

      if (gInput[0].pressed & R_BUTTON) {
        p->pageRepeatTimer = 0;
        dir = 1;
      } else if (gInput[0].pressed & L_BUTTON) {
        p->pageRepeatTimer = 0;
        dir = 2;
      } else if (gInput[0].down & R_BUTTON) {
        if (++p->pageRepeatTimer > 9) {
          p->pageRepeatTimer = 0;
          dir = 1;
        }
      } else if (gInput[0].down & L_BUTTON) {
        if (++p->pageRepeatTimer > 9) {
          p->pageRepeatTimer = 0;
          dir = 2;
        }
      }
      if (dir == 1) {
        PlaySound_082406e0(SE_MENU_PAGE);
        p->page = MainMenu_GetNextPage(p, p->page);
        MainMenu_InitPage(p);
        return;
      }
      if (dir == 2) {
        PlaySound_082406e0(SE_MENU_PAGE);
        p->page = MainMenu_GetPrevPage(p, p->page);
        MainMenu_InitPage(p);
        return;
      }
    } else {
      p->unk_400c--;
    }
    p->fn(p);
  }
  MainMenu_AnimPlayerFigure(p);
}

// 18 フレームかけて暗転してからメニューを閉じる
void MainMenu_UpdateFadeOut(MainMenu* p) {
  if (p->updateTimer < 16) {
    SetScreenBrightness(64 - p->updateTimer * 4, RGB(4, 4, 4));
  } else {
    SetScreenBrightness(0, RGB(4, 4, 4));
  }
  if (p->updateTimer == 15) {
    MessageWindow_Close();
    Marquee_Clear();
    Marquee_RequestClose();
  }
  if (++p->updateTimer > 18) {
    if (p->unk_401d) {
      p->unk_401d = 0;
      MainMenu_OpenLoanScreen(p);
    } else {
      MainMenu_RestoreBg(p);
      gBgBrightness2 = p->savedBgBrightness;
      MainMenu_SetUpdateCallback(p, MainMenu_StateClosing);
    }
  }
}

// メニューを閉じたあと画面を明るく戻し, 退避した表示設定を戻して, メニュー中に使った道具の効果 (ワープ・虫・全体攻撃・カード) を実行する
// 残差: 257/259 命令, 最後の '.D' スクリプトの ID を原典は判定のあとで読み直すが, こちらはレジスタに持ったまま渡す (0 の連鎖代入は試済)
NON_MATCH void MainMenu_StateClosing(MainMenu* p) {
#ifdef NONMATCHING_C
  SetScreenBrightness(p->updateTimer * 4, 0x1084);
  if (p->updateTimer == 0) {
    REG_BLDCNT = p->savedBLDCNT;
    if (p->savedDISPCNT & DISPCNT_BG1_ON) {
      SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    }
    if (p->savedDISPCNT & DISPCNT_BG2_ON) {
      SET_FLAGS(gStagedDISPCNT, DISPCNT_BG2_ON);
    }
    if (p->savedDISPCNT & DISPCNT_BG3_ON) {
      SET_FLAGS(gStagedDISPCNT, DISPCNT_BG3_ON);
    }
  }
  if (++p->updateTimer > 16) {
    MainMenu_SetUpdateCallback(p, FUN_0808cf14);
    gBgPlttBlendColor = p->savedBgPlttBlendColor;
    gBgPlttFadeRowMask = p->savedBgPlttFadeRowMask;
    gObjPlttBlendColor = p->savedObjPlttBlendColor;
    gObjPlttFadeSkipMask = p->savedObjPlttFadeSkipMask;
    CLEAR_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
    Sound_Resume();
    if (p->pendingAOE) {
      Entity080aace8_Create(p->player, p->aoeKind);
      p->pendingAOE = 0;
    }
    if (p->pendingWarp) {
      if (p->warpScriptID) {
        u32 argv[1];
        ScriptArgs args;

        args.argc = 1;
        argv[0] = p->warpKind;
        args.argv = argv;
        VM_ExecByID(p->warpScriptID, &args);
      }
      p->warpKind = 0;
      p->pendingWarp = 0;
    }
    if (p->pendingBugs) {
      Vec3 pos;
      Vec3 spread;
      s32 i;

      pos = p->player->mover.pos;
      pos.x -= 512;
      pos.z -= 512;
      pos.y -= 256;
      spread.x = 1024, spread.z = 1024, spread.y = 512;
      for (i = 0; i < 3; i++) {
        SpawnSpiritBugs(4, p->bugsKind, p->bugsAmount, &pos, &spread, 300, 120);
      }
      p->bugsKind = 0;
      p->pendingBugs = 0;
    }
    if (p->pendingCard) {
      if (p->cardScriptID) {
        u32 argv[1];
        ScriptArgs args;

        args.argc = 1;
        argv[0] = p->pendingCard - 1;
        args.argv = argv;
        VM_ExecByID(p->cardScriptID, &args);
      }
      p->pendingCard = 0;
    }
  }
#else
  INCFUNC("asm/func/MainMenu_StateClosing.inc");
#endif
}

void MainMenu_UpdatePageSelect(MainMenu* p);

// フェードの進み具合を9枚のスプライトへ配り, 0 に戻ったら次の状態へ移る
void FUN_0809b12c(MainMenu* p) {
  s32 i;

  SetScreenBrightness(0x40, RGB(4, 4, 4));
  p->sprites[3].pos.x += 15;
  if (p->sprites[3].pos.x >= 0) {
    p->sprites[3].pos.x = 0;
    MainMenu_SetUpdateCallback(p, MainMenu_UpdatePageSelect);
  }

  for (i = 0; i < 9; i++) {
    p->sprites[i + 4].pos.x = p->sprites[3].pos.x;
  }
}

// サイドバーでページを選ぶ, 上下で選び, A でそのページを開き, B か START で閉じる
void MainMenu_UpdatePageSelect(MainMenu* p) {
  SetScreenBrightness(64, 0x1084);
  MainMenu_DrawClock(p);
  if (gInput[0].pressed & (B_BUTTON | START_BUTTON)) {
    PlaySound_082406e0(SE_SIDEBAR_TOGGLE);
    MainMenu_SetUpdateCallback(p, FUN_0809b2b8);
  } else if (gInput[0].pressed & A_BUTTON) {
    s32 i;

    if (p->page != p->pageCursor) {
      p->page = p->pageCursor;
      MainMenu_InitPage(p);
      PlaySound_082406e0(SE_SELECT);
    } else {
      PlaySound_082406e0(SE_CLOSE_MENU);
    }
    for (i = 0; i < 10; i++) {
      p->sprites[3 + i].flags &= ~SPRFLAG_HIDDEN;
    }
    MainMenu_SetUpdateCallback(p, FUN_0809b2b8);
  } else {
    s32 keys = MainMenu_GetDpadRepeat(p);
    bool32 moved = FALSE;

    if (keys & DPAD_UP) {
      p->pageCursor = MainMenu_GetPrevPage(p, p->pageCursor);
      moved = TRUE;
    } else if (keys & DPAD_DOWN) {
      p->pageCursor = MainMenu_GetNextPage(p, p->pageCursor);
      moved = TRUE;
    }
    if (moved) {
      s32 n;
      s32 i;

      PlaySound_082406e0(SE_CURSOR_MOVE);
      n = 0;
      for (i = 0; i < PAGE_NUM; i++) {
        if (p->availPages[i]) {
          if (i == p->pageCursor) {
            MainSprite_SetPltt(&p->sprites[3 + n], 677);
          } else {
            MainSprite_SetPltt(&p->sprites[3 + n], 678);
          }
          n++;
        }
      }
    }
  }
}

// 3..12 番のスプライトを左へ流し出し, 画面外まで出たら隠して次の段階へ移る
void FUN_0809b2b8(MainMenu* p) {
  s32 i;

  SetScreenBrightness(64, 0x1084);
  MainMenu_DrawClock(p);
  if (p->pendingLine >= 0) {
    MainMenu_ShowLineInstant(p, p->pendingLine);
    p->pendingLine = -1;
  }
  p->sprites[3].pos.x -= 15;
  if (p->sprites[3].pos.x <= -120) {
    for (i = 0; i < 10; i++) {
      p->sprites[3 + i].flags |= SPRFLAG_HIDDEN;
    }
    MainMenu_SetUpdateCallback(p, MainMenu_UpdatePage);
  } else {
    for (i = 0; i < 9; i++) {
      p->sprites[4 + i].pos.x = p->sprites[3].pos.x;
    }
  }
}

s32 FUN_0809b348(MainMenu* p) {
  if (gInput[0].pressed & START_BUTTON) {
    Player* player = p->player;

    if (player != NULL && player->mode == 1 && !(player->flag20 & 1) && p->hudMode <= 2 && !TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_EVENT | GAMEFLAG_NO_PAUSE)) {
      return TRUE;
    }
  }

  return FALSE;
}

s32 FUN_0809b3b0(MainMenu* p) {
  s32 brightness;

  if (FUN_0809b348(p)) {
    SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
    brightness = gBgBrightness2;
    p->savedBgBrightness = brightness;
    p->savedBgPlttBlendColor = gBgPlttBlendColor;
    p->savedBgPlttFadeRowMask = gBgPlttFadeRowMask;
    p->savedObjPlttBlendColor = gObjPlttBlendColor;
    p->savedObjPlttFadeSkipMask = gObjPlttFadeSkipMask;
    MainMenu_SetUpdateCallback(p, FUN_0809aaf4);
    return TRUE;
  }

  return FALSE;
}

// スプライトを全部描画リストから外す
void MainMenu1P_RemoveSprites(MainMenu* p) {
  MainSprite* sprite = p->sprites;
  s32 i;

  for (i = 0; i < 116; i++) {
    MainSprite_Remove(sprite);
    sprite++;
  }

  AuxSprite_Remove(&p->sprite_b60);
  AuxSprite_Remove(&p->stand);
}

// 残差はレジスタ割当のみ (935/934 + 末尾のダミー b, 同じ命令が同じ順で並ぶ), 原典は 0 を r1/r4 の2本に持ち, 定数オフセットを既存レジスタから加算で作る (0x100 = 0x70 + 0x90 等) が, こちらは movs/lsls やプール定数で作り直す
// Tier A-C 試済 (Vec3初期化をカンマ/個別文の両方, materialization order の4パターンは該当なし)
NON_MATCH void MainMenu1P_AddSprites(MainMenu* p) {
#ifdef NONMATCHING_C
  Vec3 pos;
  s32 i;

  pos.x = 0, pos.y = 0, pos.z = 0;
  MainSprite_Add(&p->sprites[0], &p->gfx.smenu, SMENU_PAGE(0), SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[1], &p->gfx.smenu, SMENU_L_ICON, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[2], &p->gfx.smenu, SMENU_R_ICON, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[16], &p->gfx.smenu, SMENU_ITEM_BAG, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[14], &p->gfx.smenu, SMENU_SELECTED, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[40], &p->gfx.smenu, SMENU_EQUIP_CURSOR(3), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_SetAnim(&p->sprites[40], &p->gfx.smenu, 1, PLAYMODE_LOOP, 0);
  MainSprite_SetPose(&p->sprites[40], &p->gfx.smenu, SMENU_EQUIP_CURSOR(3), PLAYMODE_LOOP);
  MainSprite_Add(&p->sprites[13], &p->gfx.smenu, SMENU_CURSOR(1), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_SetAnim(&p->sprites[13], &p->gfx.smenu, 0, PLAYMODE_LOOP, 0);
  MainSprite_Add(&p->sprites[59], &p->gfx.smenu, SMENU_BACK, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[60], &p->gfx.smenu, SMENU_BACK, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);

  for (i = 0; i < 16; i++) {
    MainSprite_Add(&p->sprites[17 + i], &p->gfx.icons, ICON_ITEM(ITEM_EARTHLY_NUT), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  }

  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[36 + i], &p->gfx.icons, ICON_ITEM(ITEM_EARTHLY_NUT), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
    MainSprite_Add(&p->sprites[41 + i], &p->gfx.smenu, SMENU_EQUIP_E, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  }

  pos.x = 117, pos.y = 70;
  MainSprite_Add(&p->sprites[33], &p->gfx.icons, ICON_TRASH, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  pos.x = 0, pos.y = 0;
  MainSprite_Add(&p->sprites[34], &p->gfx.smenu, SMENU_SELECT, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  pos.x = 120, pos.y = 104;
  MainSprite_Add(&p->sprites[35], &p->gfx.icons, ICON_SORT, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  pos.x = 0, pos.y = 128;
  MainSprite_Add(&p->sprites[45], &p->gfx.icons, ICON_TIMER_NONE, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);

  for (i = 0; i < 2; i++) {
    MainSprite_Add(&p->sprites[46 + i], &p->gfx.icons, ICON_ITEM(ITEM_EARTHLY_NUT), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  }

  pos.x = 36, pos.y = 112;
  MainSprite_Add(&p->sprites[57], &p->gfx.player, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_SetAnim(&p->sprites[57], &p->gfx.player, 4, PLAYMODE_LOOP, 0);
  Video_GetAuxSprite(&p->gfx_b8c, SPRITE_BAT);
  AuxSprite_Add(&p->sprite_b60, &p->gfx_b8c, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST);
  p->sprite_b60.priority = 0;
  p->sprite_b60.pos.x = 36, p->sprite_b60.pos.y = 112, p->sprite_b60.pos.z = 0;

  pos.x = 52, pos.y = 100;
  MainSprite_Add(&p->sprites[58], &p->gfx.rita, 0, SPRFLAG_XFLIP | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_SetAnim(&p->sprites[58], &p->gfx.rita, 13, PLAYMODE_LOOP, 0);

  pos.x = 0, pos.y = 0;
  for (i = 0; i < 9; i++) {
    MainSprite_Add(&p->sprites[48 + i], &p->gfx.smenu, SMENU_NUM_BLUE(0), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  }

  pos.x = 0, pos.y = 0;
  MainSprite_Add(&p->sprites[15], &p->gfx.smenu, SMENU_YESNO(0), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  pos.x = 8, pos.y = 20;
  MainSprite_Add(&p->sprites[61], &p->gfx.portraits, 0, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = 0, pos.y = 0;
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[62 + i], &p->gfx.smenu, SMENU_BADCOND_NAME(0), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
    pos.y += 13;
  }

  pos.x = 0, pos.y = 0;
  for (i = 0; i < 10; i++) {
    MainSprite_Add(&p->sprites[3 + i], &p->gfx.smenu, SMENU_PAGE_LONG(0), SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  }

  pos.x = 0, pos.y = 0;
  MainSprite_Add(&p->sprites[66], &p->gfx.smenu, SMENU_STAT_ASSIGN, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[67], &p->gfx.smenu, SMENU_STAT_ASSIGN_OK, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = 0, pos.y = 0;
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[68 + i], &p->gfx.smenu, 71, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 1, PLAYMODE_PAUSE, 60, &pos);
    MainSprite_Add(&p->sprites[72 + i], &p->gfx.smenu, 70, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 1, PLAYMODE_PAUSE, 60, &pos);
    pos.y += 8;
  }

  pos.x = 0, pos.y = 0;
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[78 + i], &p->gfx.map, i * 2 + 9, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 1, PLAYMODE_PAUSE, 60, &pos);
    MainSprite_SetAnim(&p->sprites[78 + i], &p->gfx.map, i + 1, PLAYMODE_LOOP, 0);
  }

  MainSprite_Add(&p->sprites[76], &p->gfx.map, 0, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 1, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[77], &p->gfx.map, 3, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 1, PLAYMODE_PAUSE, 60, &pos);

  pos.x = 0, pos.y = 0;
  for (i = 0; i < 6; i++) {
    MainSprite_Add(&p->sprites[86 + i], &p->gfx.map, 18 + i, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 1, PLAYMODE_PAUSE, 60, &pos);
  }

  for (i = 0; i < 8; i++) {
    MainSprite_Add(&p->sprites[92 + i], &p->gfx.map, 17, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST, 1, PLAYMODE_PAUSE, 60, &pos);
  }

  pos.x = 0, pos.y = 0;
  MainSprite_Add(&p->sprites[82], &p->gfx.smenu, SMENU_MAP_SCROLL(2), SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[83], &p->gfx.smenu, SMENU_MAP_SCROLL(3), SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[84], &p->gfx.smenu, SMENU_MAP_SCROLL(0), SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[85], &p->gfx.smenu, SMENU_MAP_SCROLL(1), SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = 0, pos.y = 0;
  MainSprite_Add(&p->sprites[100], &p->gfx.loans, 4, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[101], &p->gfx.loans, 25, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_Add(&p->sprites[102], &p->gfx.loans, 27, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = 0, pos.y = 0;
  for (i = 0; i < 3; i++) {
    MainSprite_Add(&p->sprites[104 + i], &p->gfx.loans, 8, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
    pos.x += 8;
  }

  pos.x = 16, pos.y = -4;
  MainSprite_Add(&p->sprites[103], &p->gfx.loans, 18, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = -56, pos.y = 56;
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[107 + i], &p->gfx.loans, 8, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
    pos.x += 8;
  }

  pos.x = 88, pos.y = 56;
  MainSprite_Add(&p->sprites[111], &p->gfx.loans, 8, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);

  pos.x = -48, pos.y = 72;
  for (i = 0; i < 4; i++) {
    MainSprite_Add(&p->sprites[112 + i], &p->gfx.loans, 8, SPRFLAG_SCREEN_COORD | SPRFLAG_OAM_DIRECT | SPRFLAG_DRAWLIST, 0, PLAYMODE_PAUSE, 60, &pos);
    pos.x += 8;
  }

  Video_GetAuxSprite(&p->standGfx, SPRITE_SOLAR_STATION);
  AuxSprite_Add(&p->stand, &p->standGfx, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD | SPRFLAG_DRAWLIST);
  Video_SetAuxSpritePltt(&p->standGfx, 323);  // 暗黒ローンなので赤色
  p->stand.priority = 0;
  p->stand.pos.x = 160, p->stand.pos.y = 88, p->stand.pos.z = 0;
#else
  INCFUNC("asm/func/MainMenu1P_AddSprites.inc");
#endif
}

void MainMenu_OpenSpriteFiles(MainMenu* p) {
  MainSpriteGfxFile* f;

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
  if (f == NULL) {
    return;
  }
  p->gfx.smenu = *f;
  OpenMainSpriteFile(&p->gfx.smenu, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
  if (f == NULL) {
    return;
  }
  p->gfx.icons = *f;
  OpenMainSpriteFile(&p->gfx.icons, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_MAP);
  if (f == NULL) {
    return;
  }
  p->gfx.map = *f;
  OpenMainSpriteFile(&p->gfx.map, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_DARKLOAN);
  if (f == NULL) {
    return;
  }
  p->gfx.loans = *f;
  OpenMainSpriteFile(&p->gfx.loans, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_DJANGO_SABATA);
  if (f == NULL) {
    return;
  }
  p->gfx.player = *f;
  OpenMainSpriteFile(&p->gfx.player, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_RITA);
  if (f == NULL) {
    return;
  }
  p->gfx.rita = *f;
  OpenMainSpriteFile(&p->gfx.rita, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_CARMILLA);
  if (f == NULL) {
    return;
  }
  p->gfx.carmilla = *f;
  OpenMainSpriteFile(&p->gfx.carmilla, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_PORTRAITS);
  if (f == NULL) {
    return;
  }
  p->gfx.portraits = *f;
  OpenMainSpriteFile(&p->gfx.portraits, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_LINK);
  if (f == NULL) {
    return;
  }
  p->gfx.link = *f;
  OpenMainSpriteFile(&p->gfx.link, f);
}

void MainMenu1P_ReadNamedArgs(MainMenu* p) {
  if (VM_SeekToNamedArg('i')) {
    p->itemNames = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('w')) {
    p->weaponNames = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('a')) {
    p->armorNames = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('m')) {
    p->magicNames = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('A')) {
    p->areaNames = VM_GetPC_Proxy();  // String_1826
  }
  if (VM_SeekToNamedArg('l')) {
    p->loanTexts = VM_GetPC_Proxy();
  }
  if (VM_SeekToNamedArg('E')) {
    p->etcTexts = VM_GetPC_Proxy();  // STR_STARTMENU_MISC
  }
  if (VM_SeekToNamedArg('e')) {
    p->expTable = VM_GetValueSafe2();
  }

  if (VM_SeekToNamedArg('p')) {
    p->unk_3fa0 = VM_GetValue();
  } else {
    p->unk_3fa0 = 0;
  }
}

// '.o' で選択可能なページを受け取り, 今のページが選べないなら選べるページまで進める
void MainMenu_InitAvailPages(MainMenu* p) {
  s32 i;

  if (VM_SeekToNamedArg('o')) {
    for (i = 0; i < PAGE_NUM; i++) {
      p->availPages[i] = VM_GetValue();
    }
  } else {
    for (i = 0; i < PAGE_NUM; i++) {
      p->availPages[i] = TRUE;
    }
  }

  if (!p->availPages[p->page]) {
    for (i = 0; i < PAGE_NUM; i++) {
      if (++p->page >= PAGE_NUM) {
        p->page = 0;
      }
      if (p->availPages[p->page]) {
        return;
      }
    }
    p->page = 0;
  }
}

// '.q=1' を読んでクイックチェンジを使えるかどうかを決める
void MainMenu1P_LoadQCEnabled(MainMenu* p) {
  if (VM_SeekToNamedArg('q')) {
    p->qc.enabled = VM_GetValue();
  } else {
    p->qc.enabled = TRUE;
  }
}

void FUN_0809c040(void) {
  gMainMenu = NULL;
  gSavedMenuPage = PAGE_ITEM;
  u16_03002c10 = 0;
  u16_03002c18 = 1;
}

s32 FUN_0809c068(void) {
  if (gMainMenu == NULL) {
    return -1;
  }
  return gMainMenu->unk_9fc;
}

// フィールドの HUD の表示モードを切り替える, 7 で全部隠し, 0〜2 は QC と通常の HUD, 3 以上は BG0 の層を mode - 2 にする
void MainMenu_SetHudMode(s32 mode) {
  MainMenu* p = gMainMenu;

  if (p == NULL) {
    return;
  }
  p->hudMode = mode;
  if (p->unk_9fc != 0) {
    return;
  }
  if (p->hudMode == 7) {
    MainMenu_HideQCIcons(p);
    p->unk_a34.flags |= SPRFLAG_HIDDEN;
    p->unk_aa0[0].flags |= SPRFLAG_HIDDEN;
    p->unk_aa0[1].flags |= SPRFLAG_HIDDEN;
    p->unk_a31 = 0;
    ClearBGTilemapBuffer(0);
  } else {
    if (p->hudMode <= 2) {
      if (!(gGameFlags & GAMEFLAG_CROSSOVER)) {
        MainMenu_QC_ShowSelectedOnly(p);
      }
      Video_SetBGLayer(0, p->tm_18, 0);
      if (p->hudMode == 1) {
        p->prevBossHP = gStat->bossHP;
      }
    } else {
      MainMenu_HideQCIcons(p);
      p->unk_a34.flags |= SPRFLAG_HIDDEN;
      p->unk_aa0[0].flags |= SPRFLAG_HIDDEN;
      p->unk_aa0[1].flags |= SPRFLAG_HIDDEN;
      Video_SetBGLayer(0, p->tm_18, p->hudMode - 2);
      MessageWindow_SetBgPltt(BGP_EFDA);
      p->unk_a31 = 0;
    }
    Video_GenerateBGMap(0, 0, 0, 0, 0);
  }
  p->unk_a24 = 0;
}

void FUN_0809c1c0(void) {
  if (gMainMenu != NULL) {
    gMainMenu->unk_9ff = gMainMenu->hudMode;
  }
}

void FUN_0809c1e8(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL) {
    if (p->unk_9ff >= 0) {
      MainMenu_SetHudMode(p->unk_9ff);
      p->unk_9ff = -1;
    }
  }
}

void Cmd_DF85(void) { FUN_0809c1c0(); }

void Cmd_CCD9(void) { FUN_0809c1e8(); }

// 0xC6AA
void Textbox_CloseBox(void) {
  if (VM_SeekToNamedArg('m')) {
    MainMenu_SetHudMode(VM_GetValue());
  }
}

void FUN_0809c244(void) {
  if (gMainMenu != NULL) {
    MainMenu_SetHudMode(gMainMenu->hudMode);
  }
}

// 0x2FA0
void Cmd_2FA0(void) {
  if (gMainMenu != NULL && gMainMenu->unk_9fc == 0) {
    MainMenu_InitAvailPages(gMainMenu);
  }
}

void FUN_0809c28c(void) {
  if (gMainMenu != NULL && gMainMenu->player != NULL) {
    MainMenu_BuildQCWeaponSlots(gMainMenu);
    MainMenu_RefreshQCWeaponIcons(gMainMenu);
    if (gMainMenu->hudMode <= 2) {
      MainMenu_QC_ShowSelectedOnly(gMainMenu);
    }
  }
}

void FUN_0809c2d0(void) {
  if (gMainMenu != NULL && gMainMenu->player != NULL) {
    MainMenu_BuildQCMagicSlots(gMainMenu);
    MainMenu_RefreshQCMagicIcons(gMainMenu);
    if (gMainMenu->hudMode <= 2) {
      MainMenu_QC_ShowSelectedOnly(gMainMenu);
    }
  }
}

// '.f' でクイックチェンジを使えるかどうかを切り替える
void Cmd_SetQCEnabled(void) {
  if (gMainMenu != NULL) {
    if (VM_SeekToNamedArg('f')) {
      gMainMenu->qc.enabled = VM_GetValue();
    }
  }
}

void HUD_ShowEnemyGauge(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) {
  MainMenu* p = gMainMenu;

  if (p != NULL && p->hudMode == 0) {
    if (param_2 < 0) {
      p->enemyGaugeHP = 0;
    } else {
      p->enemyGaugeHP = param_2;
    }
    p->enemyGaugeMaxHP = param_3;
    p->enemyGaugeCells = param_4;
    p->enemyGaugeTimer = 180;
    if (param_5 != 0) {
      p->enemyGaugeFlash = 6;
    } else {
      p->enemyGaugeFlash = 0;
    }
  }
}

// HUD上のボスHPゲージ? (ただし、黒ジャンゴのHPのみで呼ばれるだけで、他のボスではこの関数を使わない)
void HUD_ShowCoffinGauge(s32 param_1, s32 param_2, s32 param_3) {
  MainMenu* p = gMainMenu;

  if (p != NULL && p->hudMode == 0) {
    if (param_1 < 0) {
      p->coffinGaugeHP = 0;
    } else {
      p->coffinGaugeHP = param_1;
    }
    p->coffinGaugeMaxHP = param_2;
    p->coffinGaugeTimer = 180;
    if (param_3 != 0) {
      p->coffinGaugeFlash = 6;
    } else {
      p->coffinGaugeFlash = 0;
    }
  }
}

void FUN_0809c430(void) {
  if (gMainMenu != NULL) {
    if (gMainMenu->hudMode == 1 || gMainMenu->hudMode == 2) {
      gMainMenu->bossFlashTimer = 4;
    }
  }
}

void FUN_0809c464(void) {
  if (gMainMenu != NULL) {
    gMainMenu->player = GetPlayer(0);
    if (gMainMenu->player != NULL) {
      MainMenu_BuildQCMagicSlots(gMainMenu);
      MainMenu_RefreshQCMagicIcons(gMainMenu);
      MainMenu_BuildQCWeaponSlots(gMainMenu);
      MainMenu_RefreshQCWeaponIcons(gMainMenu);

      if (gGameFlags & GAMEFLAG_CROSSOVER) {
        if (gMainMenu->hudMode == 0) {
          MainMenu_UpdateHud(gMainMenu);
        }
        MainMenu_HideQCIcons(gMainMenu);
      } else {
        if (gMainMenu->hudMode == 0) {
          MainMenu_QC_ShowSelectedOnly(gMainMenu);
          FUN_0808ce98(gMainMenu);
        }
      }
    }
  }
}

void HUD_ShowWeaponCrashEffect(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL && p->unk_9fc == 0 && p->hudMode <= 2) {
    MainMenu_SparkleParticles(p, 0, 224, 144);
    p->qc.weaponCrashTimer = 6;
    PlaySound_082406e0(SE_WEAPON_BREAK);
  }
}

// カウントダウン系のHUD
void HUD_StartCountdown(u16* remainingTime) {
  MainMenu* p = gMainMenu;

  if (p != NULL) {
    p->unk_a9c = remainingTime;
    p->unk_a97 = 1;
    if (gGameFlags & GAMEFLAG_LINK) {
      p->unk_a98 = 1;
    }
  }
}

// カウントダウン系のHUDに関係?
void HUD_RemoveCountdown(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL) {
    p->unk_a9c = NULL;
    p->unk_aa0[0].flags |= SPRFLAG_HIDDEN;
    p->unk_aa0[1].flags |= SPRFLAG_HIDDEN;
    p->unk_a97 = 0;
    p->unk_a98 = 0;
  }
}

void Cmd_610A(void) {
  if (gMainMenu != NULL) {
    MainMenu_DrawBossGauge(gMainMenu, 2);
  }
}

void Cmd_94EB(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL) {
    p->coffinGaugeMaxHP = 10;
    p->coffinGaugeHP = 10;
    p->coffinGaugeTimer = 180;
    p->coffinGaugeFlash = 0;
    MainMenu_DrawEnemyGauge(p);
  }
}

void Cmd_EFD1(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL && VM_SeekToNamedArg('i')) {
    p->unk_3fa0 = VM_GetValue();
  }
}

// HUD の先頭の魔法と武器のアイコンを今の装備に合わせる, エンチャント中は魔法アイコンを点滅させる
void FUN_0809c668(MainMenu* p) {
  if (p->player->magic.enchanted && (++p->stateTimer & 1)) {
    MainSprite_SetPose(&p->qc.magics[0].sprite, &p->gfx.icons, 201, PLAYMODE_LOOP);
  } else {
    MainSprite_SetPose(&p->qc.magics[0].sprite, &p->gfx.icons, ICON_MAGIC(p->player->magic.id), PLAYMODE_LOOP);
  }
  MainSprite_SetPose(&p->qc.weapons[0].sprite, &p->gfx.icons, ICON_WEAPON(p->player->wpn.weaponID), PLAYMODE_LOOP);
}

void FUN_0809c70c(MainMenu* p) {
  u8* data = gEntity9A9F->unk_118;
  BgMapEntry* tile;
  s32 i;

  if (gEntity9A9F == NULL) {
    data = NULL;
  }
  tile = MainMenu_GetBgMapAddr(0, 25, 2);
  for (i = 0; i < 5; i++) {
    if (*data == 0) {
      *tile = 0xE0C0;
    } else if (*data == 1) {
      *tile = 0xE0C3;
    } else if (*data == 2) {
      *tile = 0xE0C2;
    } else if (*data == 3) {
      *tile = 0xE0C1;
    } else {
      *tile = 0xE0C4;
    }
    tile++;
    data++;
  }
}

// 通信対戦の HUD に 10 マスのゲージを描き, 枠の色を日光の当たり具合で点滅させる
void FUN_0809c780(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) {
  BgMapEntry* map = MainMenu_GetBgMapAddr(0, param_3, param_4);
  rgb555 color;
  s32 n;
  s32 i;

  if (param_2 == 1) {
    color = 0x29F;
  } else if (Player_TestFlag20(p->player, PFLAG20_SUNBATHING)) {
    u16 t = p->sunFrameTimer;

    color = 0x29F;
    if (t > 36) {
      color = 0x1FB;
      if (t > 44) {
        if (t <= 52) {
          color = 0x177;
        }
      }
    }
    if (++p->sunFrameTimer > 59) {
      p->sunFrameTimer = 0;
    }
  } else {
    p->sunFrameTimer = 52;
    color = 0x177;
  }
  {
    rgb555* pltt = &gBgPlttBuffer[218];

    if (*pltt != color) {
      *pltt = color;
    }
  }

  n = Entity9A9F_GetUnk60(p->player->inputIdx);
  *map++ = 0xD05C;
  for (i = 0; i < n; i++) {
    *map++ = 0xD05D;
  }
  for (; i < 10; i++) {
    *map++ = 0xD05E;
  }
  *map = 0xD05F;
}

void MainMenuLink_Update_Internal(MainMenu* p) {
  if (p->player != NULL && p->hudMode != 7 && p->hudMode <= 2) {
    MainMenu_DrawHPGauge(p, 0, 3, 1);
    MainMenu_DrawEneGauge(p, 0, 3, 2);
    FUN_0809c780(p, 0, 9, 18);
    MainMenu_UpdateCondIcon(p);
    MainMenu_DrawEnemyGauge(p);
    FUN_0809c668(p);
    FUN_0809c70c(p);
    MainMenu_UpdateCountdown(p);
  }
}

s32 MainMenuLink_Update(MainMenu* p) {
  if (!(gEntityDisableFlags & ENTITY_DISABLE_0)) {
    p->player = GetPlayer(p->playerIdx);
    MainMenuLink_Update_Internal(p);
  }
  return 0;
}

s32 MainMenuLink_Destroy(MainMenu* p) {
  FUN_0808cf50(p);
  FUN_0808cffc(p);
  MainSprite_Remove(&p->qc.magics[0].sprite);
  MainSprite_Remove(&p->qc.weapons[0].sprite);
  gMainMenu = NULL;
  return 0;
}

void MainMenuLink_AddQCIcons(MainMenu* p) {
  Vec3 pos;
  MainSprite* sprite;
  MainSpriteGfx* gfx;

  VEC3_SET(pos, 8, 136, 0);
  sprite = &p->qc.magics[0].sprite;
  gfx = &p->gfx.icons;
  MainSprite_Add(sprite, gfx, ICON_MAGIC(MAGIC_SOL), SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);
  MainSprite_SetPltt(sprite, 1);
  VEC3_SET(pos, 216, 136, 0);
  MainSprite_Add(&p->qc.weapons[0].sprite, gfx, 0, SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 60, &pos);
}

// 通信対戦用に背景と道具アイコン/メニューのスプライトを読み込み, QC のアイコンを並べる
void MainMenuLink_LoadResources(MainMenu* p) {
  MainSpriteGfxFile* f;

  p->hudMode = 0;
  p->tm_18 = GetFile(DIR_TILE_MAP, TILEMAP_A413);
  p->bgp_30 = BgPlttRow13(GetBgPlttFile(BGP_EFDA));
  FUN_0808a3c4(p, p->tm_18, 0, 0, p->bgp_30);
  p->unk_a2a = 0;

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
  if (f == NULL) {
    return;
  }
  p->gfx.icons = *f;
  OpenMainSpriteFile(&p->gfx.icons, f);

  f = GetFile(DIR_MAIN_SPRITE, SPRITE_UI_START_MENU);
  if (f == NULL) {
    return;
  }
  p->gfx.smenu = *f;
  OpenMainSpriteFile(&p->gfx.smenu, f);

  FUN_0808cf64(p);
  FUN_0808d01c(p);
  MainMenuLink_AddQCIcons(p);
}

s32 MainMenuLink_Init(MainMenu* p, u32 id) {
  SetBGPrioDirect(0, 0);
  p->playerIdx = GetLinkPlayerIdx();
  p->unk_9fc = 0;
  p->player = GetPlayer(p->playerIdx);
  MainMenu_OpenSpriteFiles(p);
  MainMenuLink_LoadResources(p);
  MainMenuLink_Update_Internal(p);
  p->unk_a9a = 0xFF;
  p->unk_a9b = 0xFF;
  p->unk_9ff = -1;
  gMainMenu = p;
  return 0;
}

MainMenu* MainMenuLink_Create(u32 id, u32 _) {
  if (gMainMenu == NULL) {
    MainMenu* p = CreateEntity(ENTITY_UNK_12, sizeof(MainMenu));

    if (p != NULL) {
      SetEntityRoutine(p, MainMenuLink_Update, MainMenuLink_Destroy);
      p->id = id;
      if (MainMenuLink_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gMainMenu;
}

s32 MainMenu1P_Update(MainMenu* p) {
  p->player = GetPlayer(0);
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  MainMenu_UpdateParticles(p);
  return 0;
}

s32 MainMenu1P_Destroy(MainMenu* p) {
  MainMenu_RemoveQCIcons(p);
  FUN_0808cf50(p);
  FUN_0808cacc(p);
  MainMenu1P_RemoveSprites(p);
  FUN_0808cffc(p);
  gSavedMenuPage = p->page;
  gMainMenu = NULL;
  return 0;
}

// HUD とスタートメニューを組み立て, gMainMenu に自分を登録する
s32 MainMenu1P_Init(MainMenu* p, u32 id) {
  SetBGPrioDirect(0, 0);
  p->unk_9fc = 0;
  p->page = gSavedMenuPage;
  p->player = GetPlayer(0);
  BuildWeapon((WeaponData*)&gWeaponDB[WEAPON_GUN_DEL_HELL], &p->weapon);
  MainMenu1P_ReadNamedArgs(p);
  MainMenu_InitAvailPages(p);
  MainMenu1P_LoadQCEnabled(p);
  MainMenu_OpenSpriteFiles(p);
  MainMenu1P_0808dddc(p);
  MainMenu1P_AddSprites(p);
  if (VM_SeekToNamedArg('d')) {
    p->scriptID = VM_GetValue();
  } else {
    p->scriptID = 0;
  }
  if (VM_SeekToNamedArg('V')) {
    p->unk_401f = VM_GetValue();
  } else {
    p->unk_401f = 0;
  }
  if (VM_SeekToNamedArg('R')) {
    p->warpScriptID = VM_GetValue();
  } else {
    p->warpScriptID = 0;
  }
  if (VM_SeekToNamedArg('D')) {
    p->cardScriptID = VM_GetValue();
  } else {
    p->cardScriptID = 0;
  }
  p->textPanelID_4014 = TextPanel_Create(6, 4, 10, 2);
  p->textPanelID = TextPanel_Create(4, 6, 22, 6);
  MainMenu1P_SetupBg(p);
  if (gGameFlags & GAMEFLAG_CROSSOVER) {
    MainMenu_UpdateHud(p);
    MainMenu_SetUpdateCallback(p, FUN_0808e400);
  } else {
    FUN_0808ce98(p);
    MainMenu_SetUpdateCallback(p, FUN_0808cf14);
  }
  MainMenu1P_AddParticles(p);
  p->unk_a99 = 2;
  p->unk_a9a = 0xFF;
  p->unk_a9b = -1;
  p->unk_9ff = -1;
  gMainMenu = p;
  return 0;
}

MainMenu* MainMenu1P_Create(u32 id, u32 _) {
  if (gMainMenu == NULL) {
    MainMenu* p = CreateEntity(ENTITY_UNK_12, sizeof(MainMenu));

    if (p != NULL) {
      SetEntityRoutine(p, MainMenu1P_Update, MainMenu1P_Destroy);
      p->id = id;
      if (MainMenu1P_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gMainMenu;
}

// 0xCC28
MainMenu* MainMenu_Create(u32 id, u32 _) {
  if (gGameFlags & GAMEFLAG_LINK) {
    return MainMenuLink_Create(id, _);
  }
  return MainMenu1P_Create(id, _);
}
