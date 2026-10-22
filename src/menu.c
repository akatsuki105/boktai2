#include "armor.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "inventory.h"
#include "item.h"
#include "particle.h"
#include "player.h"
#include "save.h"
#include "sound.h"
#include "sprite.h"
#include "text.h"
#include "tilemap.h"
#include "video.h"
#include "vm.h"

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

struct MainMenu;
typedef void(MainMenuFunc)(struct MainMenu* p);  // _Update が p->fn(p) として呼ぶ

typedef struct {
  MainSprite sprite;  // 0x0000
  s8 unk_60;          // 0x0060, 根拠: MainMenu_ApplyWeapon が ldrsb で読んで配列の添字にする
  u8 unk_61;          // 0x0061
  u8 unk_62[2];       // 0x0062, まだ未解析, padding?
} MMenuSprite100;
static_assert(sizeof(MMenuSprite100) == 100);

typedef struct {
  u8 unk_0[8];  // 0x000, まだ未解析
  struct MMenuPtclNode {
    Particle ptcl;           // 0x00, FUN_0808cacc が Particle_Remove に渡す
    u8 unk_28[0x30 - 0x28];  // 0x28, まだ未解析
    u16 velX;                // 0x30, 毎フレーム ptcl.pos.x に足す
    u16 velY;                // 0x32, 毎フレーム ptcl.pos.y に足す, 4フレームごとに1増える
    u8 unk_34[0x38 - 0x34];  // 0x34, まだ未解析
    u8 unk_38;               // 0x38, 0 になると使い終わり
    u8 unk_39;               // 0x39, 経過フレーム数, 20 で打ち止め
    u8 unk_3a[0x40 - 0x3A];  // 0x3A, まだ未解析
  } nodes[8];                // 0x008
} MMenuPtclSet;
static_assert(sizeof(MMenuPtclSet) == 520);

typedef struct MMenuPtclNode MMenuPtclNode;
static_assert(sizeof(MMenuPtclNode) == 64);

typedef struct {
  Weapon* weapon;     // 0x0000, 根拠: MainMenu_ApplyWeapon が Player_ApplyWeapon の第2引数に渡す
  MainSprite sprite;  // 0x0004
  u8 unk_64;          // 0x0064
  u8 unk_65;          // 0x0065
  u8 unk_66[2];       // 0x0066, まだ未解析, padding?
} MMenuSprite104;
static_assert(sizeof(MMenuSprite104) == 104);

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
  s8 slotmap[36];  // 0x08, colX と rowY のスロット番号, 負の値は選べない枠
} InventoryCursor;
static_assert(sizeof(InventoryCursor) == 44);

// マップ切り替え時に毎回生成される
// Init を強制的に失敗させる(Init の返り値を -1 にする) と (ステータスバー,太陽ゲージ以外の)HUD が表示されなくなり、 STARTを押してもスタートメニューが開かず、SELECTを押してもクイックチェンジができなくなった
// このときにキャラと会話すると、 顔アイコンと文字のタイルは表示されるが、テキストボックスが表示されない (会話自体は正常に処理される)
// 機能としては(今のところ判明してるだけでも) HUD + スタートメニュー + テキストウィンドウ といった感じ
typedef struct MainMenu {
  Entity e;                      // 0x0000, ENTITY_UNK_12
  Tilemaps* tm_18;               // 0x0018, TILEMAP_A413
  Tilemaps* tm_1c;               // 0x001C, TILEMAP_A7D7
  Tilemaps* tm_20;               // 0x0020, TILEMAP_A7E7
  Tilemaps* tm_24;               // 0x0024, TILEMAP_A7F7
  void* unk_28;                  // 0x0028
  TilemapFile* tm_2c;            // 0x002C, TILEMAP_83C0
  rgb555* bgp_30;                // 0x0030, BGP_EFDA
  rgb555* bgp_34;                // 0x0034, BGP_ECBF
  rgb555* bgp_38;                // 0x0038, BGP_5F5E
  rgb555* bgp_3c;                // 0x003C, BGP_EAA8
  u8 unk_40[0x54 - 0x40];        // 0x0040, まだ未解析
  u8* unk_54;                    // 0x0054, FUN_0808f170 が MessageWindow_Start に渡す
  u8* unk_58;                    // 0x0058, 根拠: MainMenu_ShowLineInstant が MessageWindow_Start に渡す
  s32* unk_5c;                   // 0x005C, gStat->lv で引く表, weapon_080993c4 がその10倍を返す
  MainSpriteGfx gfx[9];          // 0x0060
  BgState savedBg1;              // 0x0180
  u16 savedTilemap1[1024];       // 0x01B0
  u16 unk_9b0;                   // 0x09B0
  u8 unk_9b2[0x9B4 - 0x9B2];     // 0x09B2, まだ未解析
  u16 unk_9b4;                   // 0x09B4
  u8 unk_9b6[0x9B8 - 0x9B6];     // 0x09B6, まだ未解析
  u16 unk_9b8;                   // 0x09B8
  u8 unk_9ba[0x9D8 - 0x9BA];     // 0x09BA, まだ未解析
  u16 unk_9d8;                   // 0x09D8
  u16 unk_9da;                   // 0x09DA
  u8 unk_9dc;                    // 0x09DC
  u8 unk_9dd;                    // 0x09DD
  s8 unk_9de;                    // 0x09DE
  u8 playerIdx;                  // 0x09DF, gPlayerPtr の添字
  Player* player;                // 0x09E0
  u8 unk_9e4[0x9EC - 0x9E4];     // 0x09E4, まだ未解析
  u16 unk_9ec;                   // 0x09EC
  u16 unk_9ee;                   // 0x09EE
  MainMenuFunc* updateCallback;  // 0x09F0
  MainMenuFunc* fn;              // 0x09F4
  s8 unk_9f8;                    // 0x09F8
  u8 unk_9f9;                    // 0x09F9, まだ未解析, padding?
  u16 id;                        // 0x09FA
  u16 unk_9fc;                   // 0x09FC
  u8 unk_9fe;                    // 0x09FE
  s8 unk_9ff;                    // 0x09FF, 根拠: FUN_0809c1e8 が ldrsb で読んで負かどうかを見る
  u16 unk_a00;                   // 0x0A00
  u16 unk_a02;                   // 0x0A02
  u16 unk_a04;                   // 0x0A04
  u16 unk_a06;                   // 0x0A06
  u16 unk_a08;                   // 0x0A08
  s16 unk_a0a;                   // 0x0A0A
  u8 unk_a0c;                    // 0x0A0C
  u8 unk_a0d;                    // 0x0A0D
  u16 unk_a0e;                   // 0x0A0E
  u16 unk_a10;                   // 0x0A10
  s16 unk_a12;                   // 0x0A12
  u8 unk_a14;                    // 0x0A14
  u8 unk_a15;                    // 0x0A15
  u16 unk_a16;                   // 0x0A16
  u8 unk_a18[0xA1C - 0xA18];     // 0x0A18, まだ未解析
  s16 unk_a1c;                   // 0x0A1C
  s16 unk_a1e;                   // 0x0A1E
  u16 unk_a20;                   // 0x0A20
  s16 unk_a22;                   // 0x0A22
  u8 unk_a24;                    // 0x0A24
  u8 unk_a25[0xA2A - 0xA25];     // 0x0A25, まだ未解析
  u8 unk_a2a;                    // 0x0A2A
  u8 unk_a2b[0xA2F - 0xA2B];     // 0x0A2B, まだ未解析
  u8 unk_a2f;                    // 0x0A2F
  u8 unk_a30;                    // 0x0A30
  u8 unk_a31;                    // 0x0A31
  u8 unk_a32[0xA34 - 0xA32];     // 0x0A32, まだ未解析
  MainSprite unk_a34;            // 0x0A34
  u8 unk_a94;                    // 0x0A94
  u8 unk_a95;                    // 0x0A95
  u8 unk_a96;                    // 0x0A96
  u8 unk_a97;                    // 0x0A97
  u8 unk_a98;                    // 0x0A98
  u8 unk_a99;                    // 0x0A99
  u8 unk_a9a;                    // 0x0A9A
  u8 unk_a9b;                    // 0x0A9B
  u16* unk_a9c;                  // 0x0A9C
  MainSprite unk_aa0[2];         // 0x0AA0
  AuxSprite sprite_b60;          // 0x0B60, 根拠: MainMenu1P_RemoveSprites が AuxSprite_Remove に渡す
  u8 unk_b8c[0xBB8 - 0xB8C];     // 0x0B8C, まだ未解析
  AuxSprite sprite_bb8;          // 0x0BB8, 根拠: 同上
  AuxSpriteGfx unk_be4;          // 0x0BE4
  u8 unk_c00;                    // 0x0C00
  u8 unk_c01;                    // 0x0C01
  s8 unk_c02;                    // 0x0C02, unk_c0c の1始まりの添字, 負なら選択なし
  u8 unk_c03;                    // 0x0C03
  u32 unk_c04;                   // 0x0C04
  u8 unk_c08;                    // 0x0C08
  u8 unk_c09;                    // 0x0C09
  u8 unk_c0a[0xC0C - 0xC0A];     // 0x0C0A, まだ未解析
  MMenuSprite100 unk_c0c[4];     // 0x0C0C
  u8 unk_d9c;                    // 0x0D9C
  u8 unk_d9d;                    // 0x0D9D
  u8 unk_d9e[0xDA0 - 0xD9E];     // 0x0D9E, まだ未解析
  MMenuSprite104 unk_da0[4];     // 0x0DA0
  u8 unk_f40[0xF56 - 0xF40];     // 0x0F40, まだ未解析
  u8 page;                       // 0x0F56, スタートメニューのページ番号
  u8 unk_f57;                    // 0x0F57, まだ未解析
  u8 slots[10];                  // 0x0F58, 非0 のところだけ選べる, FUN_0809a93c / FUN_0809a978 が前後の非0を循環で探す
  u8 unk_f62[0xF64 - 0xF62];     // 0x0F62, まだ未解析
  MainSprite sprites[116];       // 0x0F64, 根拠: MainMenu1P_RemoveSprites が 116個ぶん MainSprite_Remove に渡す
  u8 unk_3ae4;                   // 0x3AE4, メニューを閉じて効果を実行する要求
  u8 unk_3ae5[0x3AE6 - 0x3AE5];  // 0x3AE5, まだ未解析
  u8 unk_3ae6;                   // 0x3AE6
  u8 unk_3ae7;                   // 0x3AE7
  InventoryCursor cursor;        // 0x3AE8
  u16 unk_3b14;                  // 0x3B14
  u16 unk_3b16;                  // 0x3B16
  u16 unk_3b18;                  // 0x3B18
  u8 unk_3b1a;                   // 0x3B1A
  u8 unk_3b1b;                   // 0x3B1B
  u16 unk_3b1c;                  // 0x3B1C
  u16 unk_3b1e;                  // 0x3B1E
  u16 unk_3b20;                  // 0x3B20
  u16 unk_3b22;                  // 0x3B22
  u8 unk_3b24;                   // 0x3B24
  u8 unk_3b25;                   // 0x3B25
  u8 unk_3b26[0x3B28 - 0x3B26];  // 0x3B26, まだ未解析
  s16 unk_3b28[32];              // 0x3B28
  s16 unk_3b68[2];               // 0x3B68
  u8 unk_3b6c[0x3B70 - 0x3B6C];  // 0x3B6C, まだ未解析
  s16 unk_3b70[2];               // 0x3B70
  u8 unk_3b74[0x3B8C - 0x3B74];  // 0x3B74, まだ未解析
  MMenuPtclSet ptclSets[2];      // 0x3B8C, FUN_0808cacc が2組とも Particle_Remove で片付ける
  bool8 inValuableInventory;     // 0x3F9C
  u8 unk_3f9d;                   // 0x3F9D
  u8 unk_3f9e;                   // 0x3F9E
  u8 unk_3f9f;                   // 0x3F9F
  u8 unk_3fa0[2];                // 0x3FA0
  s16 effectAmount;              // 0x3FA2, アイテム使用時のポップアップに出す効果量, FUN_0809296c が符号付きで読んで FUN_08092868 に渡す
  u8 unk_3fa4[0x3FAC - 0x3FA4];  // 0x3FA4
  u8 unk_3fac;                   // 0x3FAC, 根拠: ItemEffect_Bugs が 1 を入れる
  u8 unk_3fad;                   // 0x3FAD, 根拠: 同上, 引数の値が入る
  u16 unk_3fae;                  // 0x3FAE, 根拠: 同上, 第3引数が入る
  u8 unk_3fb0;                   // 0x3FB0, 根拠: ItemEffect_Warp が 1 を入れる
  u8 unk_3fb1;                   // 0x3FB1, 根拠: 同上, 引数の値が入る
  u8 unk_3fb2[0x3FB8 - 0x3FB2];  // 0x3FB2
  u8 unk_3fb8;                   // 0x3FB8, 根拠: ItemEffect_AOE が 1 を入れる
  u8 unk_3fb9;                   // 0x3FB9, 根拠: 同上, 引数の値が入る
  u8 unk_3fba[0x3FDC - 0x3FBA];  // 0x3FBA
  s8 unk_3fdc;                   // 0x3FDC, unk_3fe0 の添字, この枠だけは選べない
  u8 unk_3fdd[0x3FE0 - 0x3FDD];  // 0x3FDD, まだ未解析
  s8 unk_3fe0[16];               // 0x3FE0, 枠ごとの防具ID, 負なら空き
  s8 unk_3ff0[16];               // 0x3FF0, 根拠: FUN_0809890c / FUN_08098934 が 8..11 と 12..15 を負かどうかで見る
  u16 unk_4000;                  // 0x4000, 残りのステータスポイント, 確定時に gStat->statusPoint へ書き戻す
  u8 unk_4002[0x4008 - 0x4002];  // 0x4002, まだ未解析
  u8 unk_4008[4];                // 0x4008, 画面で振り分けた分, 確定時に gStat->stats へ足す
  u8 unk_400c[0x4018 - 0x400C];  // 0x400C, まだ未解析
  s32 textPanelID;               // 0x4018, TextPanel_Hide に渡す
  u8 unk_401c;                   // 0x401C, まだ未解析
  u8 unk_401d;                   // 0x401D, 根拠: ItemEffect_Loan が 1 を入れる
  u8 unk_401e;                   // 0x401E, 根拠: FUN_0808f95c が FUN_0808f140 の戻り値を入れる
  u8 unk_401f;                   // 0x401F, 根拠: FUN_0808f190 が非0かどうかを見る
  u8 unk_4020[0x4028 - 0x4020];  // 0x4020, まだ未解析
  u32 scriptID;                  // 0x4028, 0 以外なら VM_ExecByID で実行する
  u8 (*unk_402c[3])[16];         // 0x402C, 1件16バイトの表, +0x0F が MessageWindow_ShowLine に渡す行番号
  u8 unk_4038;                   // 0x4038, unk_402c[0] の添字
  u8 unk_4039;                   // 0x4039, 1 なら unk_402c の表に沿って BG1 を差し替える
  u8 unk_403a[2];                // 0x403A, まだ未解析
  u8 unk_403c[20];               // 0x403C
  u16 unk_4050;                  // 0x4050
  u16 unk_4052;                  // 0x4052
  u16 unk_4054;                  // 0x4054
  u16 unk_4056;                  // 0x4056
  u16 unk_4058[2];               // 0x4058
} MainMenu;
static_assert(sizeof(MainMenu) == 16476);

IWRAM_DATA MainMenu* gMainMenu = NULL;  // 0x0300013C

extern u16 u16_03002c10;

#define BGMAP_BGP13 (13 << 12)

void SleepGame(void);  // src/code_0823cd04.c

#define INVENTORY_SLOT(p, colX, rowY) ((p)->slotmap[(rowY) + (colX) * 4])  // InventoryCursor で カーソルの位置に対応するスロット番号を取得するマクロ

static inline void DisableEntityFlags(u32 flags) { gEntityDisableFlags |= flags; }
static inline void EnableEntityFlags(u32 flags) { gEntityDisableFlags &= ~flags; }

// 次の描画から BG を消す
static inline void HideBG(u32 bits) { gStagedDISPCNT &= ~bits; }

s32 FUN_08050d64(void);
s32 FUN_08050d7c(void);
void FUN_0809630c(MainMenu* p);
void FUN_0808eef8(MainMenu* p);
void FUN_0808e400(MainMenu* p);
void FUN_08099e70(MainMenu* p);
void FUN_0809a368(MainMenu* p);
void FUN_0809ae0c(MainMenu* p);
bool32 FUN_0808da88(MainMenu* p);
s32 FUN_0809b3b0(MainMenu* p);
void FUN_0808db68(MainMenu* p);
void FUN_08092bf0(MainMenu* p);
void FUN_080931cc(MainMenu* p);
void FUN_08093158(MainMenu* p);

// FUN_0808d200 が参照
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

void FUN_0808a33c(MainMenu* p, MainMenuFunc* fn) {
  p->updateCallback = fn;
  p->unk_9ec = 0;
}

// 状態関数を差し替えて, hide で2枚のスプライトの表示/非表示を切り替える
NAKED void MainMenu_SetState(MainMenu* p, MainMenuFunc* fn, bool32 hide) { INCFUNC("asm/func/MainMenu_SetState.inc"); }

// BG0 をタイルマップで組み直して, パレット行13〜15 を差し替える
void FUN_0808a3c4(MainMenu* p, TilemapFile* tilemap, s16 param_3, s32 layerIdx, const rgb555* pltt) {
  s32 bgIndex = 0;

  Video_SetupBGLayout(0, param_3, tilemap, 0, 0, 1, &bgIndex);
  Video_SetBGLayer(0, tilemap, layerIdx);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  CpuCopy32(pltt, &gBgPlttBuffer[208], 96);
}

static BgMapEntry* MainMenu_GetBgMapAddr(s32 bg, u32 x, u32 y) {
  BgState* s = &gBgStates[bg];
  BgMapEntry* map = s->tilemap;

  return map + (x & 31) + (y & 31) * 32;
}

// param_2 で 0x11 / 0x91 / 0x31 を選んで param_1 に足す
s32 FUN_0808a440(s32 param_1, s32 param_2) {
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
void FUN_0808a458(s32 brightness, s32 color) {
  gBgPlttBlendColor = color;
  gBgPlttFadeRowMask = 0xFFFF;
  gBgBrightness = brightness;
  gObjPlttBlendColor = color;
  gObjPlttFadeSkipMask = 0;
  gObjBrightness = brightness;
}

s32 MinS32(s32 a, s32 b) {
  s32 min = b;
  if (a <= b) {
    min = a;
  }
  return min;
}

NAKED void FUN_0808a4ac(MainMenu* p, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6) { INCFUNC("asm/func/FUN_0808a4ac.inc"); }

// HP を FUN_0808a4ac に渡す
void MainMenu_DrawHP(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) { FUN_0808a4ac(p, param_2, p->player->hp, p->player->maxHP, param_3, param_4); }

// EN を FUN_0808a4ac に渡す
void MainMenu_DrawEne(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) { FUN_0808a4ac(p, param_2, p->player->ene, p->player->maxEne, param_3, param_4); }

NAKED s32 FUN_0808a610(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808a610.inc"); }

NAKED s32 FUN_0808a768(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808a768.inc"); }

void FUN_0808a9a0(void) {}

NAKED void FUN_0808a9a4(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808a9a4.inc"); }

NAKED void FUN_0808abec(MainMenu* p, s32 param_2) { INCFUNC("asm/func/FUN_0808abec.inc"); }

NAKED void FUN_0808ad5c(MainMenu* p) { INCFUNC("asm/func/FUN_0808ad5c.inc"); }

NAKED void FUN_0808afac(MainMenu* p) { INCFUNC("asm/func/FUN_0808afac.inc"); }

NAKED void FUN_0808b11c(MainMenu* p, s32 param_2, u32 param_3) { INCFUNC("asm/func/FUN_0808b11c.inc"); }

NAKED void FUN_0808b1bc(MainMenu* p) { INCFUNC("asm/func/FUN_0808b1bc.inc"); }

// value を place の位から順に10進数のタイルとして BG0 の (x, y) から並べる
// 残差は38/38命令でレジスタ番号のみ (value と map が r5/r6 で逆になる)
NON_MATCH void FUN_0808b30c(s32 value, s32 place, u32 x, u32 y, s32 kind) {
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
  INCFUNC("asm/func/FUN_0808b30c.inc");
#endif
}

// 残差1命令, 原典は 0xF090 のプール定数をループ変数の初期化より前に作る (FUN_0808b97c と同じ)
NON_MATCH void FUN_0808b360(s32 count, u32 x, u32 y) {
#ifdef NONMATCHING_C
  BgMapEntry* entry = MainMenu_GetBgMapAddr(0, x, y);

  if (count > 0) {
    s32 n = count;

    do {
      *entry = 0xF090;
      entry++;
      n--;
    } while (n != 0);
  }
#else
  INCFUNC("asm/func/FUN_0808b360.inc");
#endif
}

NAKED void FUN_0808b38c(MainMenu* p) { INCFUNC("asm/func/FUN_0808b38c.inc"); }

NAKED void FUN_0808b4c0(MainMenu* p) { INCFUNC("asm/func/FUN_0808b4c0.inc"); }

NAKED void FUN_0808b604(MainMenu* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0808b604.inc"); }

// 十字キーの入力を返す, 押しっぱなしのときは10フレームごとに1回だけ返す
// 残差は36/36命令でレジスタ番号のみ (p, gInput, 0xF0 の3つが回る)
NON_MATCH s32 FUN_0808b6a4(MainMenu* p) {
#ifdef NONMATCHING_C
  if (gInput[0].pressed & DPAD_ANY) {
    p->unk_3b24 = 0;
    return gInput[0].pressed;
  }

  if (gInput[0].down & DPAD_ANY) {
    p->unk_3b24++;
    if (p->unk_3b24 > 9) {
      p->unk_3b24 = 0;
      return gInput[0].down;
    }
  }
  return 0;
#else
  INCFUNC("asm/func/FUN_0808b6a4.inc");
#endif
}

// 15番のスプライトを原点に出して, 引数の有無でアニメを選ぶ
void FUN_0808b6fc(MainMenu* p, s32 param_2) {
  s32 anim;

  p->sprites[15].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[15].pos.x = 0;
  p->sprites[15].pos.y = 0;
  p->unk_3b25 = param_2;

  anim = (u8)param_2 != 0 ? 4 : 5;
  MainSprite_SetAnim(&p->sprites[15], p->gfx, anim, 1, 0);
  MainSprite_AdvanceAnim(&p->sprites[15], p->gfx);
}

NAKED s32 FUN_0808b760(MainMenu* p) { INCFUNC("asm/func/FUN_0808b760.inc"); }

// 116枚のスプライトと2枚の AuxSprite を全部隠す
void FUN_0808b82c(MainMenu* p) {
  s32 i;

  for (i = 0; i < 116; i++) {
    p->sprites[i].flags |= SPRFLAG_HIDDEN;
  }
  p->sprite_b60.flags |= SPRFLAG_HIDDEN;
  p->sprite_bb8.flags |= SPRFLAG_HIDDEN;
}

// sprite_f64 を表示してポーズを差し替える
void FUN_0808b86c(MainMenu* p, u32 poseIdx) {
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->sprites[0], p->gfx, poseIdx + 0x29, 1);
}

NAKED void FUN_0808b8a4(MainMenu* p) { INCFUNC("asm/func/FUN_0808b8a4.inc"); }

NAKED void FUN_0808b910(MainMenu* p) { INCFUNC("asm/func/FUN_0808b910.inc"); }

// 命令数は一致 (33/33) だが, 原典は i + 1 を先に作ってから 0xF001 のプール定数を読むのに対し agbcc は逆順でレジスタが入れ替わる
NON_MATCH void FUN_0808b97c(s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < param_4; i++) {
    BgMapEntry* entry = MainMenu_GetBgMapAddr(0, param_1, param_2 + i);

    if (param_3 > 0) {
      s32 n = param_3;

      do {
        *entry = 0xF001;
        entry++;
        n--;
      } while (n != 0);
    }
  }
#else
  INCFUNC("asm/func/FUN_0808b97c.inc");
#endif
}

// 命令数は一致 (33/33) だが, 原典は i + 1 を先に作ってから 0xF002 のプール定数を読むのに対し agbcc は逆順でレジスタが入れ替わる
NON_MATCH void FUN_0808b9c4(s32 param_1, s32 param_2, s32 param_3, s32 param_4) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < param_4; i++) {
    BgMapEntry* entry = MainMenu_GetBgMapAddr(0, param_1, param_2 + i);

    if (param_3 > 0) {
      s32 n = param_3;

      do {
        *entry = 0xF002;
        entry++;
        n--;
      } while (n != 0);
    }
  }
#else
  INCFUNC("asm/func/FUN_0808b9c4.inc");
#endif
}

void MainSprite_SetPltt(MainSprite* p, u16 plttID) {
  p->plttID = plttID;
  p->pltt = &gObjPlttData[p->plttID * 16];
}

// x と y を目標値へ weight : 1 の比で近づける
void FUN_0808ba20(WorldPos* pos, s16* target, s32 weight) {
  pos->x = Div(pos->x * weight + target[0], weight + 1);
  pos->y = Div(pos->y * weight + target[1], weight + 1);
}

// プレイヤーの状態に応じたパレットIDを返す (毒, カーモス, 通常)
s32 FUN_0808ba64(MainMenu* p) {
  s32 i;
  if (p->player->badCondTimer[1] != 0) {  // 毒
    i = 2;
  } else {
    i = (KAAMOS(p->player->isSabata) > 0) ? 6 : 0;
  }
  return p->player->plttIDs[i];
}

NAKED void FUN_0808bac4(MainMenu* p) { INCFUNC("asm/func/FUN_0808bac4.inc"); }

NAKED void FUN_0808c028(MainMenu* p) { INCFUNC("asm/func/FUN_0808c028.inc"); }

NAKED void FUN_0808c164(MainMenu* p, u16 param_2, u16 param_3, u8 param_4) { INCFUNC("asm/func/FUN_0808c164.inc"); }

NAKED bool32 FUN_0808c1cc(MainMenu* p) { INCFUNC("asm/func/FUN_0808c1cc.inc"); }

NAKED void FUN_0808c334(s32 param_1, s32 param_2, u16 param_3, s32 param_4, s16* param_5, s16* param_6, s32 param_7, u16 param_8) { INCFUNC("asm/func/FUN_0808c334.inc"); }

NAKED s32 FUN_0808c434(MainMenu* p, s32 param_2) { INCFUNC("asm/func/FUN_0808c434.inc"); }

// 画面下2行のテキストボックスに1行表示する
void MainMenu_ShowBottomLine(u8* pc, s32 line, s32 playSound) {
  if (playSound) {
    PlaySound_082406e0(SE_CHOICE);
  }

  FUN_08049e5c();
  MessageWindow_Start(pc);
  MessageWindow_SetRect(0, 16, 30, 2);
  MessageWindow_ShowLine(line);
}

NAKED void FUN_0808c548(MainMenu* p) { INCFUNC("asm/func/FUN_0808c548.inc"); }

// 59番と60番のスプライトを同じ x に, y は8ずらして並べる
void FUN_0808c61c(MainMenu* p, s32 x, s32 y) {
  p->sprites[59].pos.x = x;
  p->sprites[59].pos.y = y;
  p->sprites[60].pos.x = x;
  p->sprites[60].pos.y = y + 8;
}

s32 FUN_0808c648(s32 param_1) {
  if (param_1 == 0) {
    return 147;
  }
  return 160 + param_1;
}

NAKED void FUN_0808c658(MainMenu* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0808c658.inc"); }

void FUN_0808c700(MainMenu* p) { FUN_0808c658(p, -1, -1); }

NAKED s32 FUN_0808c710(unknown* param_1, ParticleGroup* param_2) { INCFUNC("asm/func/FUN_0808c710.inc"); }

// 粒を放物線で飛ばす, 20フレーム経ったら隠して使い終わりにする
s32 FUN_0808c770(MMenuPtclNode* p) {
  p->unk_39++;
  if (p->unk_39 > 19) {
    p->ptcl.flags |= SPRFLAG_HIDDEN;
    p->unk_38 = 0;
  } else {
    p->ptcl.pos.x += p->velX;
    p->ptcl.pos.y += p->velY;
    if (!(p->unk_39 & 3)) {
      p->velY++;
    }
  }
  return p->unk_38;
}

NAKED void MainMenu1P_Update_Helper_0808c7c4(MainMenu* p) { INCFUNC("asm/func/MainMenu1P_Update_Helper_0808c7c4.inc"); }

NAKED void UNUSED FUN_0808c834(s32 param_1, s32 param_2, s16 param_3, s16 param_4) { INCFUNC("asm/func/FUN_0808c834.inc"); }

NAKED void FUN_0808c95c(MainMenu* p, s32 param_2, s16 param_3, s16 param_4) { INCFUNC("asm/func/FUN_0808c95c.inc"); }

// 2組のパーティクルを描画リストから全部外す
void FUN_0808cacc(MainMenu* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    s32 j;

    for (j = 0; j < 8; j++) {
      Particle_Remove(&p->ptclSets[i].nodes[j].ptcl);
    }
  }
}

NAKED void MainMenu1P_0808cb00(MainMenu* p) { INCFUNC("asm/func/MainMenu1P_0808cb00.inc"); }

// BG0 の先頭9タイルに 0xA0 からの連番を並べる
void FUN_0808cb90(MainMenu* p) {
  if (!p->unk_a30) {
    BgMapEntry* entry = MainMenu_GetBgMapAddr(0, 0, 0);
    s32 i;

    for (i = 0; i < 9; i++) {
      *entry = (i + 0xA0) | BGMAP_BGP13;
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

NAKED void FUN_0808cc14(MainMenu* p) { INCFUNC("asm/func/FUN_0808cc14.inc"); }

NAKED void FUN_0808cc84(MainMenu* p) { INCFUNC("asm/func/FUN_0808cc84.inc"); }

void FUN_0808ce98(MainMenu* p) {
  if (p->player != NULL && p->unk_9fe != 7 && p->unk_9fe <= 2) {
    FUN_0808a610(p, 0, 3, 1);
    FUN_0808a768(p, 0, 3, 2);
    FUN_0808a9a4(p, 0, 9, 18);
    FUN_0808afac(p);
    if (p->unk_9fe == 0) {
      FUN_0808ad5c(p);
    } else {
      FUN_0808abec(p, p->unk_9fe);
    }
    FUN_0808cc14(p);
    FUN_0808cc84(p);
    FUN_0808b1bc(p);
  }
}

void FUN_0808cf14(MainMenu* p) {
  if (!(gEntityDisableFlags & ENTITY_DISABLE_0)) {
    FUN_0808ce98(p);
    if (FUN_0808da88(p)) {
      PlaySound_082406e0(SE_SLOT);
    } else {
      FUN_0809b3b0(p);
    }
  }
}

void FUN_0808cf50(MainMenu* p) { MainSprite_Remove(&p->unk_a34); }

NAKED void FUN_0808cf64(MainMenu* p) { INCFUNC("asm/func/FUN_0808cf64.inc"); }

void FUN_0808cffc(MainMenu* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->unk_aa0[i]);
  }
}

NAKED void FUN_0808d01c(MainMenu* p) { INCFUNC("asm/func/FUN_0808d01c.inc"); }

NAKED void MainMenu1P_0808d0c0(MainMenu* p) { INCFUNC("asm/func/MainMenu1P_0808d0c0.inc"); }

// クイックチェンジのカーソル点滅処理
void MainMenu_QC_PulseCursor(MainMenu* p) {
  u8 t = p->unk_da0[3].unk_64;
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

  p->unk_da0[3].unk_64++;
  if (p->unk_da0[3].unk_64 >= 50) {
    p->unk_da0[3].unk_64 = 0;
  }
  gBgPlttBuffer[(13 * 16) + 2] = color;  // BGP13.2
}

NAKED void FUN_0808d200(MainMenu* p) { INCFUNC("asm/func/FUN_0808d200.inc"); }

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

NAKED void FUN_0808d2ac(MainMenu* p) { INCFUNC("asm/func/FUN_0808d2ac.inc"); }

// 4組のスプライトを隠す
void MainMenu_HideSprites(MainMenu* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    p->unk_c0c[i].sprite.flags |= SPRFLAG_HIDDEN;
    p->unk_da0[i].sprite.flags |= SPRFLAG_HIDDEN;
  }
}

NAKED void FUN_0808d3d4(MainMenu* p) { INCFUNC("asm/func/FUN_0808d3d4.inc"); }

// スクロール位置から行の表示Y座標を出す, 画面外に出たら1周ぶん下へ回す
NON_MATCH s32 FUN_0808d49c(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) {
#ifdef NONMATCHING_C
  s32 colX = Mod(param_4 + param_2 - param_3, param_4);
  s32 y = 136 - param_5 * 3;

  y -= colX * 24;
  if (y < 136 - (param_4 - 1) * 24) {
    y += param_4 * 24;
  }
  return y;
#else
  INCFUNC("asm/func/FUN_0808d49c.inc");
#endif
}

NAKED void FUN_0808d4dc(MainMenu* p) { INCFUNC("asm/func/FUN_0808d4dc.inc"); }

NAKED void FUN_0808d564(MainMenu* p) { INCFUNC("asm/func/FUN_0808d564.inc"); }

NAKED void FUN_0808d5cc(MainMenu* p) { INCFUNC("asm/func/FUN_0808d5cc.inc"); }

NAKED void FUN_0808d774(MainMenu* p) { INCFUNC("asm/func/FUN_0808d774.inc"); }

void FUN_0808d908(MainMenu* p) {
  FUN_0808d200(p);
  FUN_0808d2ac(p);
  FUN_082408d0();
  DisableEntityFlags(ENTITY_DISABLE_2);
  FUN_0808a33c(p, FUN_0808db68);
}

// 選んでいる魔法をプレイヤーに持たせる, 選択なしなら外す
// 残差は39/39命令で1命令, 原典は p + 添字*100 の加算の被演算子が逆
NON_MATCH void FUN_0808d93c(MainMenu* p) {
#ifdef NONMATCHING_C
  if (p->unk_c02 >= 0 && p->unk_c00 != 0) {
    Player_EquipMagic(p->player, (s8)(&p->unk_c09)[p->unk_c02 * 100]);
  } else {
    Player_EquipMagic(p->player, -1);
  }
#else
  INCFUNC("asm/func/FUN_0808d93c.inc");
#endif
}

// 4つめのスプライトが指す武器を Player に適用する
void MainMenu_ApplyWeapon(MainMenu* p) { Player_ApplyWeapon(p->player, p->unk_da0[p->unk_c0c[3].unk_60].weapon); }

// クイックチェンジ で呼ばれた (武器魔法両方), スタートメニューでの 武器魔法切り替え処理 はここを呼んでいない
void MainMenu_QC_0808d9c8(MainMenu* p) {
  FUN_0808d268();
  MainMenu_ApplyWeapon(p);
  FUN_0808d93c(p);
  p->unk_c03 = 0;
  FUN_0808d3d4(p);
  FUN_082408f4();
  EnableEntityFlags(ENTITY_DISABLE_2);
  FUN_0808a33c(p, FUN_0808cf14);
}

NAKED s32 FUN_0808da14(MainMenu* p) { INCFUNC("asm/func/FUN_0808da14.inc"); }

bool32 FUN_0808da88(MainMenu* p) {
  if (FUN_0808da14(p) != 0) {
    FUN_0808d908(p);
    return TRUE;
  }
  return FALSE;
}

NAKED void FUN_0808daa8(MainMenu* p) { INCFUNC("asm/func/FUN_0808daa8.inc"); }

NAKED void FUN_0808db68(MainMenu* p) { INCFUNC("asm/func/FUN_0808db68.inc"); }

NAKED void FUN_0808dcdc(MainMenu* p) { INCFUNC("asm/func/FUN_0808dcdc.inc"); }

// 4組のスプライトを描画リストから外す
// 残差は adds のオペランド順と pool ロードの位置だけ (命令数は同じ), 原典は (i * 100) + p の順で足している
// 要素ポインタのローカルを挟むとレジスタが1本増えて悪化し, 添字を u32 にしても変わらない
NON_MATCH void FUN_0808dda4(MainMenu* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 4; i++) {
    MainSprite_Remove(&p->unk_c0c[i].sprite);
    MainSprite_Remove(&p->unk_da0[i].sprite);
  }
#else
  INCFUNC("asm/func/FUN_0808dda4.inc");
#endif
}

void MainMenu1P_0808dddc(MainMenu* p) {
  FUN_0808dcdc(p);

  if (p->player != NULL) {
    FUN_0808d5cc(p);
    FUN_0808d774(p);
    FUN_0808d4dc(p);
    FUN_0808d564(p);
    if (gFlag030047a4 & FLAG030047A4_UNK_12) {
      MainMenu_HideSprites(p);
    } else {
      FUN_0808d3d4(p);
    }
  }
}

void FUN_0808de30(MainMenu* p) {
  FUN_0808d5cc(p);
  FUN_0808d4dc(p);
  FUN_0808d3d4(p);
  MainMenu_ApplyWeapon(p);
}

void FUN_0808de50(MainMenu* p) {
  FUN_0808d774(p);
  FUN_0808d564(p);
  FUN_0808d3d4(p);
  FUN_0808d93c(p);
}

NAKED void FUN_0808de70(MainMenu* p) { INCFUNC("asm/func/FUN_0808de70.inc"); }

// 選ばれている武器のスプライトだけを見せる
void FUN_0808df7c(MainMenu* p) {
  MainMenu_HideSprites(p);
  p->unk_da0[p->unk_c0c[3].unk_60].sprite.flags &= ~SPRFLAG_HIDDEN;
  MainSprite_SetPose(&p->unk_da0[p->unk_c0c[3].unk_60].sprite, &p->gfx[2], 0, 1);
}

void FUN_0808dfcc(MainMenu* p) {
  if (!(gEntityDisableFlags & ENTITY_DISABLE_0) && p->unk_9fe <= 2) {
    FUN_0808a610(p, 0, 3, 1);
    FUN_0808daa8(p);
  }
}

NAKED void FUN_0808e008(MainMenu* p) { INCFUNC("asm/func/FUN_0808e008.inc"); }

NAKED void FUN_0808e0e0(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0808e0e0.inc"); }

void FUN_0808e17c(MainMenu* p) {
  BgMapEntry* e = MainMenu_GetBgMapAddr(0, 0x13, 3);

  *e++ = BGMAP_BGP13 | 0x4D;
  e[0] = BGMAP_BGP13 | 0x4E;
  e[1] = BGMAP_BGP13 | 0x5B;
  FUN_0808e0e0(p, 0x16, 3, FUN_08050d64());
}

void FUN_0808e1b8(MainMenu* p) {
  BgMapEntry* e = MainMenu_GetBgMapAddr(0, 0x14, 4);

  *e++ = BGMAP_BGP13 | 0x0F;
  e[0] = BGMAP_BGP13 | 0x10;
  e[1] = BGMAP_BGP13 | 0x5B;
  FUN_0808e0e0(p, 0x17, 4, FUN_08050d7c());
}

// BG0 の (9, 0x11) から2行ぶん 12 タイルを 0xD000 で埋める
void FUN_0808e1f4(void) {
  BgMapEntry* e;
  s32 x, y;

  for (y = 0; y < 2; y++) {
    e = MainMenu_GetBgMapAddr(0, 9, y + 0x11);

    for (x = 0; x < 12; x++) {
      *e = BGMAP_BGP13;
      e++;
    }
  }
}

NAKED void FUN_0808e224(MainMenu* p) { INCFUNC("asm/func/FUN_0808e224.inc"); }

void FUN_0808e400(MainMenu* p) {
  if (!(gEntityDisableFlags & ENTITY_DISABLE_0)) {
    FUN_0808e224(p);
  }
}

NAKED void FUN_0808e420(void) { INCFUNC("asm/func/FUN_0808e420.inc"); }

void FUN_0808e4f4(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL) {
    FUN_0808d268();
    p->unk_a34.flags |= SPRFLAG_HIDDEN;
    MainMenu_ApplyWeapon(p);
    FUN_0808d93c(p);
    FUN_0808d3d4(p);
    FUN_0808a33c(p, FUN_0808e400);
  }
}

NAKED void FUN_0808e53c(MainMenu* p) { INCFUNC("asm/func/FUN_0808e53c.inc"); }

NAKED void FUN_0808e5a8(MainMenu* p) { INCFUNC("asm/func/FUN_0808e5a8.inc"); }

NAKED void FUN_0808e734(MainMenu* p) { INCFUNC("asm/func/FUN_0808e734.inc"); }

NAKED void FUN_0808e83c(MainMenu* p) { INCFUNC("asm/func/FUN_0808e83c.inc"); }

s32 FUN_0808e8b8(s32 param_1) {
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

NAKED void FUN_0808e8dc(MainMenu* p) { INCFUNC("asm/func/FUN_0808e8dc.inc"); }

NAKED void FUN_0808eb4c(MainMenu* p) { INCFUNC("asm/func/FUN_0808eb4c.inc"); }

// タイルマップを読み込み直して、状態関数を FUN_0808ee50 に切り替える
void FUN_0808ee50(MainMenu* p);

void FUN_0808ebe8(MainMenu* p) {
  FUN_0808a3c4(p, p->tm_2c, 0, 3, p->bgp_3c);
  FUN_0808eb4c(p);
  FUN_0808a33c(p, FUN_0808ee50);
}

NAKED void FUN_0808ec18(MainMenu* p) { INCFUNC("asm/func/FUN_0808ec18.inc"); }

NAKED void FUN_0808ed74(MainMenu* p) { INCFUNC("asm/func/FUN_0808ed74.inc"); }

NAKED void FUN_0808ede4(MainMenu* p) { INCFUNC("asm/func/FUN_0808ede4.inc"); }

void FUN_0808eeac(MainMenu* p);

// 16フレームかけて画面を暗くし, 終わったら次の状態へ移る
void FUN_0808ee50(MainMenu* p) {
  if (p->unk_9ec <= 0xF) {
    FUN_0808a458(p->unk_9ec * 4, 0);
  } else {
    FUN_0808a458(0x40, 0);
  }

  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx[3]);

  if (p->unk_9ec++ > 0xF) {
    FUN_0808a33c(p, FUN_0808eeac);
  }
}

void FUN_0808eeac(MainMenu* p) {
  s32 result;

  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx[3]);

  result = FUN_0808b760(p);
  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_0808a33c(p, FUN_0808eef8);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    FUN_0808ec18(p);
  }
}

void FUN_0808f2f0(MainMenu* p);

// 16フレームかけて画面を明るく戻し, 終わったら次の状態へ移る
void FUN_0808eef8(MainMenu* p) {
  if (p->unk_9ec <= 0xF) {
    FUN_0808a458((0x10 - p->unk_9ec) * 4, 0);
  } else {
    FUN_0808a458(0, 0);
  }

  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx[3]);

  if (p->unk_9ec++ > 0xF) {
    FUN_0808f2f0(p);
  }
}

NAKED void FUN_0808ef58(MainMenu* p) { INCFUNC("asm/func/FUN_0808ef58.inc"); }

NAKED void FUN_0808f01c(MainMenu* p) { INCFUNC("asm/func/FUN_0808f01c.inc"); }

void FUN_0808f09c(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx[3]);

  p->unk_9ec++;
  if (p->unk_9ec > 149) {
    FUN_0808a33c(p, FUN_0809ae0c);
  }
}

// 最初の16フレームで明るくし, 150フレーム目から暗くして次の状態へ移る
void FUN_0808f0d8(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx[3]);

  if (p->unk_9ec <= 0xF) {
    FUN_0808a458(p->unk_9ec * 4, 0);
  } else if (p->unk_9ec <= 133) {
    FUN_0808a458(0x40, 0);
  } else {
    FUN_0808a458((150 - p->unk_9ec) * 4, 0);
  }

  if (p->unk_9ec++ > 149) {
    FUN_0808f2f0(p);
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
  FUN_08049e5c();
  FUN_08049f84();
  MessageWindow_SetRect(1, 15, 28, 4);
  MessageWindow_Start(p->unk_54);
  MessageWindow_SetInstant(1);

  if (p->unk_401f != 0) {
    FUN_0808ede4(p);
  } else {
    FUN_0808ebe8(p);
  }
}

// unk_401c の段階に合わせて2枚のポーズと矢印の高さを決める
void FUN_0808f1bc(MainMenu* p) {
  MainSprite_SetPose(&p->sprites[101], &p->gfx[3], p->unk_401c + 25, 1);
  MainSprite_SetPose(&p->sprites[102], &p->gfx[3], 28 - p->unk_401c, 1);
  p->sprites[103].pos.x = 0;
  p->sprites[103].pos.y = p->unk_401c << 5;
}

NAKED void FUN_0808f21c(MainMenu* p) { INCFUNC("asm/func/FUN_0808f21c.inc"); }

NAKED void FUN_0808f2f0(MainMenu* p) { INCFUNC("asm/func/FUN_0808f2f0.inc"); }

NAKED void FUN_0808f3f8(MainMenu* p) { INCFUNC("asm/func/FUN_0808f3f8.inc"); }

NAKED void FUN_0808f4ac(MainMenu* p) { INCFUNC("asm/func/FUN_0808f4ac.inc"); }

NAKED void FUN_0808f520(MainMenu* p) { INCFUNC("asm/func/FUN_0808f520.inc"); }

void FUN_0808f670(MainMenu* p);

// 16フレームかけて明るくしてから次の状態へ移る
void FUN_0808f604(MainMenu* p) {
  if (p->unk_9ec <= 0xF) {
    FUN_0808a458(p->unk_9ec * 4, 0);
  } else {
    FUN_0808a458(0x40, 0);
  }

  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx[3]);
  MainSprite_AdvanceAnim(&p->sprites[103], &p->gfx[3]);

  p->unk_9ec++;
  if (p->unk_9ec > 0xF) {
    FUN_0808a33c(p, FUN_0808f670);
  }
}

NAKED void FUN_0808f670(MainMenu* p) { INCFUNC("asm/func/FUN_0808f670.inc"); }

void FUN_0808f774(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx[3]);

  if (p->sprites[100].pos.x > -88) {
    p->sprites[100].pos.x -= 5;
  }

  p->unk_9ec++;
  if (p->unk_9ec > 149) {
    FUN_0808a33c(p, FUN_0809ae0c);
  }
}

// 16フレームかけて画面を明るく戻し, 終わったらメッセージへ進む
void FUN_0808f7cc(MainMenu* p) {
  if (p->unk_9ec <= 0xF) {
    FUN_0808a458((0x10 - p->unk_9ec) * 4, 0);
  } else {
    FUN_0808a458(0, 0);
  }
  p->unk_9ec++;
  if (p->unk_9ec > 0xF) {
    FUN_0808f170(p);
  }
}

NAKED void FUN_0808f81c(MainMenu* p) { INCFUNC("asm/func/FUN_0808f81c.inc"); }

void FUN_0808f920(MainMenu* p);

void FUN_0808f8bc(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx[3]);

  p->unk_9ec++;
  if (p->unk_9ec > 149) {
    MessageWindow_ShowLine(5);
    if (p->scriptID != 0) {
      VM_ExecByID(p->scriptID, NULL);
    } else {
      MessageWindow_SetVarValue(0, 3);
    }
    FUN_0808a33c(p, FUN_0808f920);
  }
}

void FUN_0808f920(MainMenu* p) {
  MainSprite_AdvanceAnim(&p->sprites[100], &p->gfx[3]);

  p->unk_9ec++;
  if (p->unk_9ec > 149) {
    FUN_0808a33c(p, FUN_0809ae0c);
  }
}

void FUN_0808f95c(MainMenu* p) {
  p->unk_401e = FUN_0808f140();
  HideBG(DISPCNT_BG1_ON);
  FUN_0808f21c(p);
}

s32 InventoryCursor_GetSlot(InventoryCursor* p) { return INVENTORY_SLOT(p, p->colX, p->rowY); }

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
  s32 cur = INVENTORY_SLOT(p, p->colX, p->rowY);
  u8 rowY = (p->rowY + 3) & 3;

  while (rowY != p->rowY) {
    s32 slot = INVENTORY_SLOT(p, p->colX, rowY);

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
  s32 cur = INVENTORY_SLOT(p, p->colX, p->rowY);
  u8 rowY = (p->rowY + 1) & 3;

  while (rowY != p->rowY) {
    s32 slot = INVENTORY_SLOT(p, p->colX, rowY);

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
  s32 cur = INVENTORY_SLOT(p, orig, p->rowY);
  s32 colX = orig - 1;

  if (orig == 0) {
    colX = 8;
  }

  while (colX != orig) {
    s32 slot = INVENTORY_SLOT(p, colX, p->rowY);

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
  s32 cur = INVENTORY_SLOT(p, orig, p->rowY);
  s32 colX = orig + 1;

  if (orig == 8) {
    colX = 0;
  }

  while (colX != orig) {
    s32 slot = INVENTORY_SLOT(p, colX, p->rowY);

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

// ShopCursor の位置を退避する, FUN_080b9fd8 と同じ実装
void FUN_0808fbbc(InventoryCursor* p) {
  p->savedCol = p->colX;
  p->savedRow = p->rowY;
  p->savedSlot = p->slot;
}

// 退避した ShopCursor の位置を戻す, FUN_080b9fe8 と同じ実装
void FUN_0808fbcc(InventoryCursor* p) {
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

void FUN_0808fbf4(MainMenu* p) { MessageWindow_ShowLine(p->unk_402c[0][p->unk_4038][0xF]); }

// データデカすぎてファイルが読みにくいので一時退避
#include "data/menu.h"

// FUN_0808fc14 / MainMenu_InitPage_Map が引く
const u8 (*const PTR_ARRAY_085acec8[15])[16] = {
    u8_ARRAY_085ac084,
    u8_ARRAY_085ac0d8,
    u8_ARRAY_085ac210,
    u8_ARRAY_085ac390,
    u8_ARRAY_085ac5cc,
    u8_ARRAY_085ac68c,
    u8_ARRAY_085ac894,
    u8_ARRAY_085aca1c,
    u8_ARRAY_085acb34,
    u8_ARRAY_085acb48,
    u8_ARRAY_085acc10,
    u8_ARRAY_085acc80,
    u8_ARRAY_085acda4,
    u8_ARRAY_085ace18,
    u8_ARRAY_085ace2c,
};  // 0x085ACEC8

// FUN_0808fc14 / MainMenu_InitPage_Map が引く
const u8 (*const PTR_ARRAY_085acf04[15])[4] = {
    u8_ARRAY_085ac0a4,
    u8_ARRAY_085ac138,
    u8_ARRAY_085ac280,
    u8_ARRAY_085ac400,
    u8_ARRAY_085ac62c,
    u8_ARRAY_085ac75c,
    u8_ARRAY_085ac8f4,
    u8_ARRAY_085aca6c,
    u8_ARRAY_085acb44,
    u8_ARRAY_085acb78,
    u8_ARRAY_085acc30,
    u8_ARRAY_085accc0,
    u8_ARRAY_085acdb4,
    u8_ARRAY_085ace28,
    u8_ARRAY_085ace3c,
};  // 0x085ACF04

// 現在のエリアと '.f' の組からメッセージの行番号を引く
s32 FUN_0808fc14(void) {
  if (gStat->areaID > 14) {
    return gStat->areaID + 0x40;
  }
  {
    const u8(*records)[16] = PTR_ARRAY_085acec8[gStat->areaID];
    const u8(*index)[4] = PTR_ARRAY_085acf04[gStat->areaID];

    return records[index[gStat->unk_256][0]][15];
  }
}

// 0x82B3
void FUN_0808fc68(void) {
  if (VM_SeekToNamedArg('s')) {
    gStat->areaID = VM_GetValue();
  }
}

// 0x515D
void FUN_0808fc8c(void) {
  if (VM_SeekToNamedArg('f')) {
    gStat->unk_256 = VM_GetValue();
  }
}

// 0x9817
void FUN_0808fcb4(void) {
  if (VM_SeekToNamedArg('s')) {
    gStat->unk_258 = VM_GetValue();
  }
}

// 0xAA62
void FUN_0808fcd8(void) {
  if (VM_SeekToNamedArg('f')) {
    gStat->unk_25a = VM_GetValue();
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

// 0x7CE7, '.s' があればその番号, なければ現在のエリアの unk_268 を返す
// 残差1命令, gStat を入れるレジスタと添字の一時値が r1/r2 で逆になり, コピーが1つ増える
NON_MATCH s32 FUN_0808fd44(void) {
#ifdef NONMATCHING_C
  if (VM_SeekToNamedArg('s')) {
    s32 i = VM_GetValue();

    return gStat->unk_268[i];
  }
  return gStat->unk_268[gStat->areaID];
#else
  INCFUNC("asm/func/FUN_0808fd44.inc");
#endif
}

// 0xA995, 残差は26/26命令でレジスタ番号のみ (idx が r2 ではなく r1 に入る), ローカルの初期化形は試済
NON_MATCH void FUN_0808fd8c(void) {
#ifdef NONMATCHING_C
  s32 idx;

  if (VM_SeekToNamedArg('s')) {
    idx = VM_GetValue();
  } else {
    idx = gStat->areaID;
  }

  gStat->unk_268[idx] = 0;
#else
  INCFUNC("asm/func/FUN_0808fd8c.inc");
#endif
}

// 0x0C1B, '.s' のエリア (なければ現在のエリア) のフラグから '.i' のビットを立てる
// 残差は35/35命令でレジスタ番号のみ, FUN_0808fd8c と同じ
NON_MATCH void FUN_0808fdc8(void) {
#ifdef NONMATCHING_C
  s32 idx;

  if (VM_SeekToNamedArg('s')) {
    idx = VM_GetValue();
  } else {
    idx = gStat->areaID;
  }

  if (VM_SeekToNamedArg('i')) {
    gStat->unk_268[idx] |= 1 << VM_GetValue();
  }
#else
  INCFUNC("asm/func/FUN_0808fdc8.inc");
#endif
}

// 0x0BFD, '.s' のエリア (なければ現在のエリア) のフラグから '.i' のビットを落とす
// 残差は35/35命令でレジスタ番号のみ, FUN_0808fd8c と同じ
NON_MATCH void FUN_0808fe1c(void) {
#ifdef NONMATCHING_C
  s32 idx;

  if (VM_SeekToNamedArg('s')) {
    idx = VM_GetValue();
  } else {
    idx = gStat->areaID;
  }

  if (VM_SeekToNamedArg('i')) {
    gStat->unk_268[idx] &= ~(1 << VM_GetValue());
  }
#else
  INCFUNC("asm/func/FUN_0808fe1c.inc");
#endif
}

u32 FUN_0808fe70(u32 param_1) { return param_1 & 0xF; }

s32 FUN_0808fe78(s32 param_1) { return param_1 >> 4; }

NAKED void FUN_0808fe7c(MainMenu* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0808fe7c.inc"); }

NAKED void FUN_0808ff84(MainMenu* p) { INCFUNC("asm/func/FUN_0808ff84.inc"); }

void FUN_08090004(MainMenu* p) {
  p->sprites[78].flags |= SPRFLAG_HIDDEN;
  p->sprites[79].flags |= SPRFLAG_HIDDEN;
  p->sprites[80].flags |= SPRFLAG_HIDDEN;
  p->sprites[81].flags |= SPRFLAG_HIDDEN;
}

NAKED void FUN_08090040(MainMenu* p) { INCFUNC("asm/func/FUN_08090040.inc"); }

void FUN_08090120(MainMenu* p) {
  MainSprite* spr = &p->sprites[78];
  s32 i;

  for (i = 0; i < 4; i++) {
    MainSprite_AdvanceAnim(spr, &p->gfx[1]);
    spr++;
  }
}

NAKED void FUN_08090148(MainMenu* p) { INCFUNC("asm/func/FUN_08090148.inc"); }

// BG1 のタイルマップ全面を 0xE002 で埋める
void MainMenu_FillBG1(MainMenu* p) {
  s32 x, y;

  for (y = 0; y < 32; y++) {
    for (x = 0; x < 32; x++) {
      *MainMenu_GetBgMapAddr(1, x, y) = 0xE002;
    }
  }
}

void FUN_080906c8(MainMenu* p) {
  if (p->unk_4039 == 1) {
    Video_SetBGLayer(1, p->unk_28, p->unk_402c[0][p->unk_4038][1]);
    FUN_0808ff84(p);
    FUN_08090148(p);
  } else {
    MainMenu_FillBG1(p);
    FUN_08090004(p);
    FUN_08090148(p);
  }
}

NAKED bool32 FUN_08090724(MainMenu* p) { INCFUNC("asm/func/FUN_08090724.inc"); }

NAKED void FUN_080907f0(MainMenu* p) { INCFUNC("asm/func/FUN_080907f0.inc"); }

NAKED void FUN_08090a00(MainMenu* p) { INCFUNC("asm/func/FUN_08090a00.inc"); }

s32 FUN_08090b10(MainMenu* p) {
  u8 kind = p->player->kind;

  if (kind == PLAYER_SOLAR_DJANGO) return 0;
  if (kind == PLAYER_SABATA) return 2;

  return 1;
}

NAKED void FUN_08090b38(MainMenu* p) { INCFUNC("asm/func/FUN_08090b38.inc"); }

NAKED void FUN_08090ca4(MainMenu* p) { INCFUNC("asm/func/FUN_08090ca4.inc"); }

NAKED void FUN_08090d54(MainMenu* p) { INCFUNC("asm/func/FUN_08090d54.inc"); }

void FUN_08090ee0(void) {
  if (VM_SeekToNamedArg('i')) {
    s32 bitidx = VM_GetValue();

    gStat->unk_264 |= 1 << bitidx;
  }
}

u32 FUN_08090f0c(u32 bitidx) { return gStat->unk_264 & (1 << bitidx); }

NAKED void FUN_08090f24(MainMenu* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_08090f24.inc"); }

NAKED void FUN_0809107c(MainMenu* p) { INCFUNC("asm/func/FUN_0809107c.inc"); }

NAKED void FUN_08091270(MainMenu* p) { INCFUNC("asm/func/FUN_08091270.inc"); }

// MainMenu_InitPage_Map が引く, 4件だけ16バイトレコードの配列を指している
const u8 (*const PTR_ARRAY_085acf40[15])[4] = {
    NULL,
    u8_ARRAY_085ac1d8,
    u8_ARRAY_085ac370,
    u8_ARRAY_085ac5a0,
    u8_ARRAY_085ac680,
    u8_ARRAY_085ac850,
    u8_ARRAY_085ac9ec,
    u8_ARRAY_085acb1c,
    (void*)u8_ARRAY_085acb48,
    u8_ARRAY_085acc04,
    (void*)u8_ARRAY_085acc80,
    u8_ARRAY_085acd7c,
    (void*)u8_ARRAY_085ace18,
    (void*)u8_ARRAY_085ace2c,
    u8_ARRAY_085ace3c,
};  // 0x085ACF40

NAKED void MainMenu_InitPage_Map(MainMenu* p) { INCFUNC("asm/func/MainMenu_InitPage_Map.inc"); }

// '.f' の4つの値を 0/1 のビットに畳んで u16_03002c10 に入れる
void FUN_08091684(void) {
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

extern u16 u16_03002c14;  // src/iwram2.c
extern u16 u16_03002c18;  // src/iwram2.c

u32 FUN_080916bc(u32 bitidx) { return u16_03002c10 & (1 << bitidx); }

NAKED void FUN_080916d0(u8* param_1, u32 param_2) { INCFUNC("asm/func/FUN_080916d0.inc"); }

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
    FUN_0808a610(p, 1, 5, 3);
    if (badCondSec > 0) {
      Player_ApplyBadCondition(player, 0, badCondSec * 60);
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
    FUN_0808a768(p, 1, 5, 4);
    if (badCondSec > 0) {
      if (GetItemID(p->inValuableInventory, p->cursor.savedSlot) == ITEM_BAD_MUSHROOM) {
        Player_ApplyBadCondition(player, 2, badCondSec * 60);
      } else {
        Player_ApplyBadCondition(player, 0, badCondSec * 60);
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
    player->unk_444 = GetItemID(p->inValuableInventory, p->cursor.savedSlot);
    player->goodCondID = goodCondID;
    player->goodCondTimer = goodCondSec * 60;
    player->plttID_95e = 289;
    player->unk_960 = 0x30;
    p->effectAmount = 0;
    p->unk_a95 = 1;
    p->unk_3ae4 = 1;
  }
}

NAKED void ItemEffect_Vitamins(MainMenu* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/ItemEffect_Vitamins.inc"); }

// 精霊虫召喚
void ItemEffect_Bugs(MainMenu* p, s32 param_2, s32 param_3) {
  Player* player = p->player;

  if (player != NULL) {
    p->unk_3fad = param_2;
    if (player->kind == PLAYER_SABATA) {
      if ((u8)param_2 == 0) {
        p->unk_3fad = 2;
      } else if ((u8)param_2 == 2) {
        p->unk_3fad = 0;
      }
    }
    p->unk_3fae = param_3;
    p->unk_3fac = 1;
    p->unk_3ae4 = 1;
  }
}

// IET_WARP
void ItemEffect_Warp(MainMenu* p, s32 val, s32 _) {
  p->unk_3fb0 = 1;
  p->unk_3fb1 = val;
  p->unk_3ae4 = 1;
}

// IET_SOLAR
// 残差は30/32命令, 原典は1つ目の書き込みの後で gStat を読み直す
NON_MATCH void ItemEffect_Solar(MainMenu* p, s32 _, s32 __) {
#ifdef NONMATCHING_C
  if (p->unk_3f9d == 0) {
    gStat->unk_2b0[0] = 1;
    gStat->unk_2b0[1] = 0;
  } else {
    gStat->unk_2b0[0] = 0;
    gStat->unk_2b0[1] = 1;
  }
#else
  INCFUNC("asm/func/ItemEffect_Solar.inc");
#endif
}

void ItemEffect_Loan(MainMenu* p, s32 _, s32 __) {
  p->effectAmount = 0;
  p->unk_401d = 1;
  p->unk_3ae4 = 1;
}

NAKED void ItemEffect_HPMP(MainMenu* p, s32 param_2, s32 param_3) { INCFUNC("asm/func/ItemEffect_HPMP.inc"); }

void ItemEffect_AOE(MainMenu* p, s32 val, s32 _) {
  p->unk_3fb8 = 1;
  p->unk_3fb9 = val;
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

NAKED u32 FUN_08091cb8(item32_t n) { INCFUNC("asm/func/FUN_08091cb8.inc"); }

bool32 FUN_08091e34(item32_t n) {
  if (item_0809179c(n) == 1) {
    return TRUE;
  }
  return FALSE;
}

void FUN_08091e48(MainMenu* p, s32 slot) {
  if (!p->inValuableInventory) {
    RemoveItem(slot);
  }
}

// index: ItemEffectType で引くアイテム効果の処理表, FUN_08091e64 が (p, value1, value2) で呼ぶ
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

NAKED void FUN_08091e64(MainMenu* p, slot32_t slot) { INCFUNC("asm/func/FUN_08091e64.inc"); }

void FUN_0809200c(MainMenu* p, s32 slotA, s32 slotB) {
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

NAKED void FUN_08092070(MainMenu* p) { INCFUNC("asm/func/FUN_08092070.inc"); }

// 選択中のアイテムが HP/Ene 回復アイテムかどうか
bool32 FUN_080921a8(MainMenu* p) {
  item32_t id = GetItemID(p->inValuableInventory, p->cursor.savedSlot);

  if (gItemDB[id].effectType == IET_HP || gItemDB[id].effectType == IET_MP) {
    return TRUE;
  }
  return FALSE;
}

// 枠番号から画面上の表示位置を出す
void FUN_080921e8(WorldPos* pos, s32 idx) {
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

NAKED void FUN_0809223c(MainMenu* p) { INCFUNC("asm/func/FUN_0809223c.inc"); }

NAKED void FUN_08092300(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_08092300.inc"); }

NAKED void FUN_080923a0(MainMenu* p) { INCFUNC("asm/func/FUN_080923a0.inc"); }

u32 FUN_080925d4(item32_t n) {
  u32 flags;

  if (n < 0) {
    return 0;
  }

  flags = FUN_08091e34(n) ? 0x10 : 0;
  if (FUN_08091cb8(n)) {
    flags |= 1;
  }
  return flags;
}

NAKED void FUN_08092608(MainMenu* p, s32 param_2) { INCFUNC("asm/func/FUN_08092608.inc"); }

// 残差は50/50命令で return 0 と return 3 の基本ブロックの並びだけ, 原典は両方を末尾の共通ブロックにして 0 を先に置く, 条件の反転と末尾のネスト化は試済
NON_MATCH s32 FUN_080926c4(MainMenu* p) {
#ifdef NONMATCHING_C
  if (GetItemID(p->inValuableInventory, p->cursor.savedSlot) < 0) {
    if (GetItemID(p->inValuableInventory, p->cursor.slot) < 0) {
      return 0;
    }
    return 3;
  }

  if (p->cursor.slot == 20) {
    return 2;
  }

  if (p->cursor.slot == 16) {
    return 1;
  }

  if (p->cursor.savedSlot != p->cursor.slot) {
    return 3;
  }

  if (!(p->cursor.flags & 1)) {
    return 0;
  }

  p->cursor.slot = 16;
  return 1;
#else
  INCFUNC("asm/func/FUN_080926c4.inc");
#endif
}

NAKED void FUN_08092744(MainMenu* p) { INCFUNC("asm/func/FUN_08092744.inc"); }

NAKED void FUN_080927c4(MainMenu* p) { INCFUNC("asm/func/FUN_080927c4.inc"); }

NAKED void FUN_08092868(MainMenu* p, s32 param_2, u32* param_3) { INCFUNC("asm/func/FUN_08092868.inc"); }

NAKED void FUN_0809296c(MainMenu* p) { INCFUNC("asm/func/FUN_0809296c.inc"); }

NAKED void FUN_08092a1c(MainMenu* p) { INCFUNC("asm/func/FUN_08092a1c.inc"); }

NAKED void FUN_08092a94(MainMenu* p) { INCFUNC("asm/func/FUN_08092a94.inc"); }

NAKED void FUN_08092b3c(MainMenu* p) { INCFUNC("asm/func/FUN_08092b3c.inc"); }

// 16フレーム待ってから次の状態へ進む
void FUN_08092bb8(MainMenu* p) {
  if (p->unk_9ee <= 15) {
    p->unk_9ee++;
  } else if (FUN_0808c1cc(p)) {
    MainMenu_SetState(p, FUN_08092bf0, 1);
  }
}

NAKED void FUN_08092bf0(MainMenu* p) { INCFUNC("asm/func/FUN_08092bf0.inc"); }

void FUN_08092c7c(MainMenu* p, u8 val) {
  p->unk_3f9d = val;
  MessageWindow_Close();
  FUN_08049e5c();
  FUN_08049f84();
  MainMenu_SetState(p, FUN_080931cc, 1);
}

NAKED void FUN_08092cac(MainMenu* p) { INCFUNC("asm/func/FUN_08092cac.inc"); }

NAKED s32 FUN_08092e20(MainMenu* p) { INCFUNC("asm/func/FUN_08092e20.inc"); }

void FUN_0809312c(MainMenu* p) {
  s32 v = FUN_08092e20(p);

  if (v >= 0) {
    p->unk_3f9d = v;
    MainMenu_SetState(p, FUN_08093158, 1);
  }
}

NAKED void FUN_08093158(MainMenu* p) { INCFUNC("asm/func/FUN_08093158.inc"); }

NAKED void FUN_080931cc(MainMenu* p) { INCFUNC("asm/func/FUN_080931cc.inc"); }

NAKED void FUN_08093264(MainMenu* p) { INCFUNC("asm/func/FUN_08093264.inc"); }

NAKED void FUN_08093318(MainMenu* p) { INCFUNC("asm/func/FUN_08093318.inc"); }

NAKED void FUN_080933b4(MainMenu* p, s32 param_2) { INCFUNC("asm/func/FUN_080933b4.inc"); }

NAKED void FUN_08093580(MainMenu* p) { INCFUNC("asm/func/FUN_08093580.inc"); }

NAKED void FUN_08093608(MainMenu* p) { INCFUNC("asm/func/FUN_08093608.inc"); }

NAKED void FUN_08093710(MainMenu* p) { INCFUNC("asm/func/FUN_08093710.inc"); }

NAKED void FUN_080937d4(MainMenu* p) { INCFUNC("asm/func/FUN_080937d4.inc"); }

NAKED void FUN_080938d0(MainMenu* p) { INCFUNC("asm/func/FUN_080938d0.inc"); }

NAKED void FUN_08093990(MainMenu* p) { INCFUNC("asm/func/FUN_08093990.inc"); }

NAKED void FUN_08093a54(MainMenu* p) { INCFUNC("asm/func/FUN_08093a54.inc"); }

NAKED void FUN_08093b20(MainMenu* p) { INCFUNC("asm/func/FUN_08093b20.inc"); }

NAKED void FUN_08093bb4(MainMenu* p) { INCFUNC("asm/func/FUN_08093bb4.inc"); }

void FUN_08093cc8(MainMenu* p);

void FUN_08093c64(MainMenu* p) {
  if (FUN_0808c434(p, 0)) {
    p->unk_9ee++;
    if (p->unk_9ee > 7) {
      PlaySound_082406e0(SE_HEAL);
      p->sprites[46].flags |= SPRFLAG_HIDDEN;
      FUN_08091e64(p, p->cursor.savedSlot);
      MainMenu_SetState(p, FUN_08093cc8, 1);
    }
  }
}

NAKED void FUN_08093cc8(MainMenu* p) { INCFUNC("asm/func/FUN_08093cc8.inc"); }

NAKED void FUN_08093d38(MainMenu* p) { INCFUNC("asm/func/FUN_08093d38.inc"); }

void FUN_08093e4c(MainMenu* p);

void FUN_08093de8(MainMenu* p) {
  if (FUN_0808c434(p, 0)) {
    p->unk_9ee++;
    if (p->unk_9ee > 7) {
      p->sprites[46].flags |= SPRFLAG_HIDDEN;
      FUN_08091e64(p, p->cursor.savedSlot);
      MainMenu_SetState(p, FUN_08093e4c, 1);
      PlaySound_082406e0(SE_HEAL);
    }
  }
}

NAKED void FUN_08093e4c(MainMenu* p) { INCFUNC("asm/func/FUN_08093e4c.inc"); }

NAKED void FUN_08093f28(MainMenu* p) { INCFUNC("asm/func/FUN_08093f28.inc"); }

NAKED void FUN_08094070(MainMenu* p) { INCFUNC("asm/func/FUN_08094070.inc"); }

NAKED void FUN_08094200(MainMenu* p) { INCFUNC("asm/func/FUN_08094200.inc"); }

NAKED void FUN_08094440(MainMenu* p) { INCFUNC("asm/func/FUN_08094440.inc"); }

void FUN_080944f4(MainMenu* p) {
  s32 result = FUN_0808b760(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_08092744(p);
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
    FUN_08092744(p);
  }
}

// はい/いいえの選択結果で、決定なら効果音を鳴らして次へ進み、キャンセルならテキストボックスを閉じる
void FUN_0809455c(MainMenu* p) {
  s32 v = FUN_0808b760(p);

  if (v == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_08092744(p);
  } else if (v == 1) {
    MessageWindow_Close();
    FUN_08093f28(p);
  }
}

void FUN_080945f4(MainMenu* p);

void FUN_0809458c(MainMenu* p) {
  s32 result = FUN_0808b760(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_08092744(p);
  } else if (result == 1) {
    p->sprites[13].flags |= SPRFLAG_HIDDEN;
    MessageWindow_Close();
    FUN_08092300(p, 0, p->cursor.savedSlot, 20);
    FUN_08091e48(p, p->cursor.savedSlot);
    FUN_0809223c(p);
    MainMenu_SetState(p, FUN_080945f4, 1);
  }
}

void FUN_08094660(MainMenu* p);

// 12フレームかけて46番のスプライトを退避先へ寄せ, 着いたら隠して次の状態へ移る
void FUN_080945f4(MainMenu* p) {
  if (p->unk_9ee == 0) {
    PlaySound_082406e0(SE_SWAP_SLOT);
  }

  p->unk_9ee++;
  if (p->unk_9ee <= 11) {
    FUN_0808ba20(&p->sprites[46].pos, p->unk_3b68, 12 - p->unk_9ee);
  } else {
    p->sprites[46].flags |= SPRFLAG_HIDDEN;
    MainMenu_SetState(p, FUN_08094660, 1);
  }
}

NAKED void FUN_08094660(MainMenu* p) { INCFUNC("asm/func/FUN_08094660.inc"); }

NAKED void FUN_080946dc(MainMenu* p) { INCFUNC("asm/func/FUN_080946dc.inc"); }

NAKED void FUN_08094780(MainMenu* p) { INCFUNC("asm/func/FUN_08094780.inc"); }

NAKED void FUN_08094838(MainMenu* p) { INCFUNC("asm/func/FUN_08094838.inc"); }

NAKED void MainMenu_InitPage_Item(MainMenu* p) { INCFUNC("asm/func/MainMenu_InitPage_Item.inc"); }

void FUN_08094988(void) {
  s32 i;

  for (i = 0; i < 3; i++) {
    *MainMenu_GetBgMapAddr(0, i + 14, 8) = 0xF001;
  }
}

NAKED void MainMenu_InitPage_Valuable(MainMenu* p) { INCFUNC("asm/func/MainMenu_InitPage_Valuable.inc"); }

NAKED void FUN_08094a94(MainMenu* p, u32 permission) { INCFUNC("asm/func/FUN_08094a94.inc"); }

NAKED void FUN_08094c6c(u8* param_1, s8* param_2) { INCFUNC("asm/func/FUN_08094c6c.inc"); }

void FUN_08094cdc(s32 usePanel, s32 panelID, u8* param_3, s8* param_4) {
  FUN_08094c6c(param_3, param_4);

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

NAKED void FUN_08094d48(unknown* w, u8* pc) { INCFUNC("asm/func/FUN_08094d48.inc"); }

// 武器アイコンの絵柄番号を損耗度から決める, 特殊効果が付いているものは目減りが遅い
s32 GetWeaponWearPose(WeaponData* w) {
  s32 n;

  if ((s16)w->quality > 0) {
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

NAKED void FUN_08094eb0(MainMenu* p) { INCFUNC("asm/func/FUN_08094eb0.inc"); }

NAKED void weapon_08094f88(MainMenu* p) { INCFUNC("asm/func/weapon_08094f88.inc"); }

NAKED void FUN_080952f4(unknown* param_1, s32 param_2) { INCFUNC("asm/func/FUN_080952f4.inc"); }

NAKED void FUN_0809536c(MainMenu* p) { INCFUNC("asm/func/FUN_0809536c.inc"); }

NAKED void FUN_080954a8(MainMenu* p, u32 param_2) { INCFUNC("asm/func/FUN_080954a8.inc"); }

NAKED void FUN_080956c4(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_080956c4.inc"); }

NAKED u32 GetWeaponPermission(MainMenu* p, s32 slot) { INCFUNC("asm/func/GetWeaponPermission.inc"); }

NAKED void weapon_08095820(MainMenu* p, s32 param_2) { INCFUNC("asm/func/weapon_08095820.inc"); }

NAKED s32 FUN_0809596c(MainMenu* p) { INCFUNC("asm/func/FUN_0809596c.inc"); }

NAKED void FUN_08095a5c(MainMenu* p) { INCFUNC("asm/func/FUN_08095a5c.inc"); }

NAKED void FUN_08095ae8(MainMenu* p) { INCFUNC("asm/func/FUN_08095ae8.inc"); }

NAKED void FUN_08095c60(MainMenu* p) { INCFUNC("asm/func/FUN_08095c60.inc"); }

NAKED void weapon_08095d4c(MainMenu* p) { INCFUNC("asm/func/weapon_08095d4c.inc"); }

NAKED void FUN_08096024(MainMenu* p) { INCFUNC("asm/func/FUN_08096024.inc"); }

void FUN_080960c8(MainMenu* p) {
  s32 result = FUN_0808b760(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_08095a5c(p);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortWeapons(0);
    p->cursor.savedCol = 0;
    p->cursor.savedRow = 0;
    p->cursor.savedSlot = 0;
    FUN_08095a5c(p);
  }
}

NAKED void FUN_0809611c(MainMenu* p) { INCFUNC("asm/func/FUN_0809611c.inc"); }

NAKED void FUN_080961a4(MainMenu* p) { INCFUNC("asm/func/FUN_080961a4.inc"); }

NAKED void FUN_0809620c(MainMenu* p) { INCFUNC("asm/func/FUN_0809620c.inc"); }

void FUN_080962b0(MainMenu* p) {
  s32 result = FUN_0808b760(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_08095a5c(p);
  } else if (result == 1) {
    FUN_080956c4(p, 0, p->cursor.savedSlot, 20);
    RemoveWeapon(p->cursor.savedSlot);
    FUN_0809536c(p);
    FUN_080954a8(p, 1);
    MainMenu_SetState(p, FUN_0809630c, 1);
  }
}

NAKED void FUN_0809630c(MainMenu* p) { INCFUNC("asm/func/FUN_0809630c.inc"); }

NAKED void FUN_08096378(MainMenu* p) { INCFUNC("asm/func/FUN_08096378.inc"); }

NAKED void FUN_080963f4(MainMenu* p) { INCFUNC("asm/func/FUN_080963f4.inc"); }

NAKED void FUN_080964ac(MainMenu* p) { INCFUNC("asm/func/FUN_080964ac.inc"); }

NAKED void MainMenu_InitPage_Weapon(MainMenu* p) { INCFUNC("asm/func/MainMenu_InitPage_Weapon.inc"); }

NAKED void FUN_08096630(MainMenu* p, u8 param_2) { INCFUNC("asm/func/FUN_08096630.inc"); }

NAKED void FUN_0809673c(MainMenu* p) { INCFUNC("asm/func/FUN_0809673c.inc"); }

NAKED void FUN_080967c0(MainMenu* p) { INCFUNC("asm/func/FUN_080967c0.inc"); }

NAKED void FUN_08096a34(MainMenu* p) { INCFUNC("asm/func/FUN_08096a34.inc"); }

// 枠番号から画面上の表示位置を出す
void FUN_08096af0(Vec3* pos, s32 idx) {
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

NAKED void FUN_08096b44(MainMenu* p) { INCFUNC("asm/func/FUN_08096b44.inc"); }

NAKED void FUN_08096bb8(MainMenu* p, s32 param_2) { INCFUNC("asm/func/FUN_08096bb8.inc"); }

NAKED void FUN_08096cac(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_08096cac.inc"); }

// 枠の防具が選べるかどうかを返す, 値段が付いているものは 0x11
s32 FUN_08096d40(MainMenu* p, s32 slot) {
  if (p->unk_3fe0[slot] < 0 || slot == p->unk_3fdc) {
    return 0;
  }

  if (gArmorDB[p->unk_3fe0[slot]].price == 0) {
    return 1;
  }
  return 0x11;
}

NAKED void FUN_08096d90(MainMenu* p, s32 param_2) { INCFUNC("asm/func/FUN_08096d90.inc"); }

NAKED s32 FUN_08096ec4(MainMenu* p) { INCFUNC("asm/func/FUN_08096ec4.inc"); }

void FUN_08096f90(MainMenu* p) { MainSprite_AdvanceAnim(&p->sprites[13], p->gfx); }

NAKED void FUN_08096fa8(MainMenu* p) { INCFUNC("asm/func/FUN_08096fa8.inc"); }

NAKED void FUN_08097034(MainMenu* p) { INCFUNC("asm/func/FUN_08097034.inc"); }

NAKED void FUN_080971c4(MainMenu* p) { INCFUNC("asm/func/FUN_080971c4.inc"); }

NAKED void FUN_0809748c(MainMenu* p) { INCFUNC("asm/func/FUN_0809748c.inc"); }

void FUN_08097530(MainMenu* p) {
  s32 result = FUN_0808b760(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_08096fa8(p);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    SortArmors(0);
    p->cursor.savedCol = 0;
    p->cursor.savedRow = 0;
    p->cursor.savedSlot = 0;
    FUN_08096fa8(p);
  }
}

NAKED void FUN_08097584(MainMenu* p) { INCFUNC("asm/func/FUN_08097584.inc"); }

NAKED void FUN_08097604(MainMenu* p) { INCFUNC("asm/func/FUN_08097604.inc"); }

NAKED void FUN_08097670(MainMenu* p) { INCFUNC("asm/func/FUN_08097670.inc"); }

NAKED void FUN_080976ec(MainMenu* p) { INCFUNC("asm/func/FUN_080976ec.inc"); }

NAKED void FUN_080977a4(MainMenu* p) { INCFUNC("asm/func/FUN_080977a4.inc"); }

NAKED void FUN_08097888(MainMenu* p) { INCFUNC("asm/func/FUN_08097888.inc"); }

NAKED void FUN_08097948(MainMenu* p) { INCFUNC("asm/func/FUN_08097948.inc"); }

NAKED void MainMenu_InitPage_Armor(MainMenu* p) { INCFUNC("asm/func/MainMenu_InitPage_Armor.inc"); }

NAKED void FUN_08097ab8(MainMenu* p, u8 param_2) { INCFUNC("asm/func/FUN_08097ab8.inc"); }

NAKED void FUN_08097c04(MainMenu* p) { INCFUNC("asm/func/FUN_08097c04.inc"); }

NAKED void FUN_08097ca0(WorldPos* pos, s32 idx) { INCFUNC("asm/func/FUN_08097ca0.inc"); }

// unk_3ff0 から value の位置を探す
s32 FUN_08097d20(MainMenu* p, s32 value) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (value == p->unk_3ff0[i]) {
      return i;
    }
  }

  return -1;
}

NAKED void FUN_08097d4c(MainMenu* p) { INCFUNC("asm/func/FUN_08097d4c.inc"); }

NAKED void FUN_08097e3c(MainMenu* p) { INCFUNC("asm/func/FUN_08097e3c.inc"); }

NAKED void FUN_08097f48(s32 param_1, s32 param_2, s16 param_3, s32 param_4, s32 param_5) { INCFUNC("asm/func/FUN_08097f48.inc"); }

NAKED void FUN_08097fb4(MainMenu* p, s32 param_2) { INCFUNC("asm/func/FUN_08097fb4.inc"); }

NAKED s32 FUN_080980a8(MainMenu* p) { INCFUNC("asm/func/FUN_080980a8.inc"); }

NAKED void FUN_0809820c(MainMenu* p) { INCFUNC("asm/func/FUN_0809820c.inc"); }

NAKED void FUN_08098290(MainMenu* p) { INCFUNC("asm/func/FUN_08098290.inc"); }

NAKED void FUN_080983a4(MainMenu* p) { INCFUNC("asm/func/FUN_080983a4.inc"); }

NAKED void FUN_080984a0(MainMenu* p) { INCFUNC("asm/func/FUN_080984a0.inc"); }

NAKED void FUN_080985ec(unknown* p) { INCFUNC("asm/func/FUN_080985ec.inc"); }

NAKED void FUN_08098684(MainMenu* p) { INCFUNC("asm/func/FUN_08098684.inc"); }

void FUN_08098734(MainMenu* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    FUN_08097ca0(&p->sprites[i + 17].pos, i);
  }
}

void FUN_08098758(MainMenu* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    FUN_08097ca0(&p->sprites[i + 36].pos, i + 0x10);
  }
}

void FUN_0809877c(MainMenu* p) {
  FUN_08098734(p);
  FUN_08097d4c(p);
  FUN_08098758(p);
  FUN_08097e3c(p);
  FUN_0808bac4(p);
}

NAKED void FUN_080987a4(MainMenu* p) { INCFUNC("asm/func/FUN_080987a4.inc"); }

NAKED void FUN_0809889c(MainMenu* p) { INCFUNC("asm/func/FUN_0809889c.inc"); }

// unk_3ff0 の 8..11 に埋まっているものがあるか
s32 FUN_0809890c(MainMenu* p) {
  s32 i;

  for (i = 8; i < 12; i++) {
    if (p->unk_3ff0[i] >= 0) {
      return 1;
    }
  }

  return 0;
}

// unk_3ff0 の 12..15 に埋まっているものがあるか
s32 FUN_08098934(MainMenu* p) {
  s32 i;

  for (i = 12; i < 16; i++) {
    if (p->unk_3ff0[i] >= 0) {
      return 1;
    }
  }

  return 0;
}

NAKED void FUN_0809895c(s32 param_1) { INCFUNC("asm/func/FUN_0809895c.inc"); }

NAKED void MainMenu_InitPage_Magic(MainMenu* p) { INCFUNC("asm/func/MainMenu_InitPage_Magic.inc"); }

// 2桁の数値を十の位と一の位のスプライトに出す, 増減の符号で絵柄の組を変える
void FUN_08098a98(s32 base, s32 delta, MainSpriteGfx* gfx, MainSprite* tens, MainSprite* ones) {
  s32 value = base + delta;
  s32 high = Div(value, 10);
  s32 low = value - high * 10;

  s32 poseBase = 10;
  if (delta <= 0) {
    poseBase = (delta < 0) ? 20 : 0;
  }

  MainSprite_SetPose(tens, gfx, poseBase + high, 1);
  MainSprite_SetPose(ones, gfx, poseBase + low, 1);
}

NAKED void FUN_08098af4(MainMenu* p) { INCFUNC("asm/func/FUN_08098af4.inc"); }

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
  FUN_08098af4(p);
}

NAKED void FUN_08098c24(MainMenu* p) { INCFUNC("asm/func/FUN_08098c24.inc"); }

NAKED void FUN_08098d98(MainMenu* p) { INCFUNC("asm/func/FUN_08098d98.inc"); }

// 46番のスプライトにポーズを入れ, 13番の y を unk_4002[0] の8倍に合わせる
void FUN_08098e48(MainMenu* p) {
  p->sprites[13].pos.x = 0;
  p->sprites[13].pos.y = p->unk_4002[0] << 3;
  MainSprite_SetPose(&p->sprites[46], p->gfx, p->unk_4002[0] + 0x42, 1);
}

// 振り分けたステータスポイントを確定して, 残りポイントも書き戻す
// 残差は38/37命令, 原典は gStat + i*2 を作ってから 0x18 を変位として残す
NON_MATCH void FUN_08098e88(MainMenu* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 4; i++) {
    gStat->stats[i] += p->unk_4008[i];
    p->unk_4008[i] = 0;
  }
  gStat->statusPoint = p->unk_4000;
#else
  INCFUNC("asm/func/FUN_08098e88.inc");
#endif
}

NAKED void FUN_08098edc(MainMenu* p) { INCFUNC("asm/func/FUN_08098edc.inc"); }

// line が負ならテキストボックスを閉じ, そうでなければ画面下2行にその行を即時表示する
void MainMenu_ShowLineInstant(MainMenu* p, s32 line) {
  if (line < 0) {
    MessageWindow_Close();
  } else {
    MessageWindow_SetInstant(1);
    MessageWindow_Start(p->unk_58);
    MessageWindow_SetRect(0, 18, 30, 2);
    MessageWindow_ShowLine(line);
  }
}

NAKED void FUN_08098f7c(MainMenu* p) { INCFUNC("asm/func/FUN_08098f7c.inc"); }

NAKED void FUN_08099008(MainMenu* p) { INCFUNC("asm/func/FUN_08099008.inc"); }

NAKED void FUN_080992c0(MainMenu* p) { INCFUNC("asm/func/FUN_080992c0.inc"); }

// 武器のレベル別の値を10倍して返す
// 残差1命令, 原典は table + idx の和を r1 に作る (こちらは r0) だけの違い
NON_MATCH s32 weapon_080993c4(MainMenu* p) {
#ifdef NONMATCHING_C
  s32* table = p->unk_5c;

  return table[gStat->lv] * 10;
#else
  INCFUNC("asm/func/weapon_080993c4.inc");
#endif
}

NAKED void weapon_080993e4(MainMenu* p) { INCFUNC("asm/func/weapon_080993e4.inc"); }

NAKED void FUN_080995b0(MainMenu* p, u8 param_2) { INCFUNC("asm/func/FUN_080995b0.inc"); }

// 推測: 12バイト×3組, どの組も `0xAA 0x91 0xB8 0x01` を含む, charmap.txt の範囲外なので文字コードは不明
// FUN_08099650
const u8 u8_ARRAY_085acfb8[3][12] = {
    {0xB4, 0x91, 0xAF, 0xA9, 0xB3, 0x01, 0xAA, 0x91, 0xB8, 0x01, 0x01, 0x01},
    {0xB7, 0xA9, 0xB0, 0xB2, 0xAD, 0xB3, 0xAC, 0x01, 0xAA, 0x91, 0xB8, 0x01},
    {0xAB, 0xA9, 0xB3, 0xAE, 0x01, 0xAA, 0x91, 0xB8, 0x01, 0x01, 0x01, 0x01},
};  // 0x085ACFB8

NAKED void FUN_08099650(MainMenu* p) { INCFUNC("asm/func/FUN_08099650.inc"); }

NAKED void FUN_080996e0(MainMenu* p) { INCFUNC("asm/func/FUN_080996e0.inc"); }

NAKED void MainMenu_InitPage_Stats(MainMenu* p) { INCFUNC("asm/func/MainMenu_InitPage_Stats.inc"); }

void FUN_08099b3c(s32 param_1) {
  if (param_1 < 0) {
    MessageWindow_Close();
  } else {
    MessageWindow_SetInstant(TRUE);
    MessageWindow_ShowLine(param_1);
  }
}

// メッセージ速度の設定値を 1 と 2 で入れ替えて返す
s32 FUN_08099b5c(void) {
  if (gStat->textSpeed == 1) return 2;  // 設定で "速い" を選んだ時
  if (gStat->textSpeed == 2) return 1;  // "普通"
  return 0;                             // "遅い"
}

s32 FUN_08099b84(s32 n) {
  if (n == 0) return 4;  // 設定で "遅い" を選んだ時
  if (n == 1) return 2;  // "普通"
  return 1;              // "速い"
}

NAKED void FUN_08099b9c(MainMenu* p) { INCFUNC("asm/func/FUN_08099b9c.inc"); }

void FUN_08099c1c(MainMenu* p) {
  p->unk_400c[1] = 0;
  p->unk_400c[2] = gStat->controlUp;
  p->unk_400c[3] = FUN_08099b5c();
  p->unk_400c[4] = gStat->markerEnabled;
}

NAKED void FUN_08099c64(MainMenu* p, s32 param_2) { INCFUNC("asm/func/FUN_08099c64.inc"); }

NAKED s32 FUN_08099d2c(MainMenu* p) { INCFUNC("asm/func/FUN_08099d2c.inc"); }

void FUN_08099e2c(MainMenu* p) {
  if (gInput[0].pressed & A_BUTTON) {
    PlaySound_082406e0(SE_SELECT);
    FUN_08099c64(p, 1);
    FUN_08099b3c(6);
    FUN_0808c700(p);
    MainMenu_SetState(p, FUN_08099e70, 1);
  }
}

NAKED void FUN_08099e70(MainMenu* p) { INCFUNC("asm/func/FUN_08099e70.inc"); }

// 60フレーム待ってから FUN_08099e2c へ戻る
void FUN_08099f18(MainMenu* p) {
  p->unk_9ee++;
  if (p->unk_9ee > 59) {
    FUN_08099b3c(5);
    FUN_0808c658(p, 0, -1);
    MainMenu_SetState(p, FUN_08099e2c, 0);
  }
}

NAKED void FUN_08099f58(MainMenu* p) { INCFUNC("asm/func/FUN_08099f58.inc"); }

NAKED void MainMenu_InitPage_Config(MainMenu* p) { INCFUNC("asm/func/MainMenu_InitPage_Config.inc"); }

NAKED void FUN_0809a130(MainMenu* p) { INCFUNC("asm/func/FUN_0809a130.inc"); }

void FUN_0809a20c(MainMenu* p);

void FUN_0809a1a4(MainMenu* p) {
  s32 result = FUN_0808b760(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_08099b3c(17);
    TextPanel_Hide(p->textPanelID);
    FUN_0808c658(p, 0, -1);
    MainMenu_SetState(p, FUN_0809a130, 0);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    FUN_08099b3c(19);
    MainMenu_SetState(p, FUN_0809a20c, 1);
  }
}

void FUN_0809a20c(MainMenu* p) {
  gSoftResetInhibit = TRUE;

  p->unk_9ee++;
  if (p->unk_9ee > 119) {
    FUN_08099b3c(17);
    TextPanel_Hide(p->textPanelID);
    FUN_0808c658(p, 0, -1);
    MainMenu_SetState(p, FUN_0809a130, 0);
    p->unk_400c[0] = 30;
    SleepGame();
  }
}

NAKED void MainMenu_InitPage_Sleep(MainMenu* p) { INCFUNC("asm/func/MainMenu_InitPage_Sleep.inc"); }

void FUN_0809a324(MainMenu* p) {
  if (gInput[0].pressed & A_BUTTON) {
    PlaySound_082406e0(SE_SELECT);
    FUN_0808b6fc(p, 1);
    FUN_08099b3c(9);
    FUN_0808c700(p);
    MainMenu_SetState(p, FUN_0809a368, 1);
  }
}

NAKED void FUN_0809a368(MainMenu* p) { INCFUNC("asm/func/FUN_0809a368.inc"); }

void FUN_0809a448(MainMenu* p);

void FUN_0809a3f4(MainMenu* p) {
  s32 result = FUN_0808b760(p);

  if (result == 0) {
    PlaySound_082406e0(SE_CANCEL);
    FUN_08099b3c(8);
    FUN_0808c658(p, 0, -1);
    MainMenu_SetState(p, FUN_0809a324, 0);
  } else if (result == 1) {
    PlaySound_082406e0(SE_SELECT);
    MainMenu_SetState(p, FUN_0809a448, 1);
  }
}

NAKED void FUN_0809a448(MainMenu* p) { INCFUNC("asm/func/FUN_0809a448.inc"); }

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
  if (p->unk_9ee == 0) {
    PlaySound_082406e0(SE_SAVE_SUCCESS);
    TextPanel_Hide(p->textPanelID);
    FUN_08099b3c(14);
  }

  p->unk_9ee++;
  if (p->unk_9ee >= 120) {
    FUN_08099b3c(8);
    FUN_0808c658(p, 0, -1);
    MainMenu_SetState(p, FUN_0809a324, 0);
  }
}

void FUN_0809a574(MainMenu* p) {
  if (p->unk_9ee == 0) {
    PlaySound_082406e0(SE_NG);
    TextPanel_Hide(p->textPanelID);
    FUN_08099b3c(15);
  }

  p->unk_9ee++;
  if (p->unk_9ee >= 120) {
    FUN_08099b3c(8);
    FUN_0808c658(p, 0, -1);
    MainMenu_SetState(p, FUN_0809a324, 0);
  }
}

NAKED void MainMenu_InitPage_Save(MainMenu* p) { INCFUNC("asm/func/MainMenu_InitPage_Save.inc"); }

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
  FUN_0808b4c0(p);
}

NAKED void FUN_0809a6a8(MainMenu* p) { INCFUNC("asm/func/FUN_0809a6a8.inc"); }

void UNUSED FUN_0809a800(void) { LoadParticleFile(GetFile(DIR_PARTICLE, 0x3002)); }

NAKED void FUN_0809a81c(MainMenu* p) { INCFUNC("asm/func/FUN_0809a81c.inc"); }

// cur の次から循環で非0の slots を探す, 無ければ cur のまま
s32 FUN_0809a93c(MainMenu* p, s32 cur) {
  s32 idx = cur + 1;
  s32 i;

  if (idx > 9) {
    idx = 0;
  }
  for (i = 0; i < 10; i++) {
    if (p->slots[idx] != 0) {
      return idx;
    }
    idx++;
    if (idx > 9) {
      idx = 0;
    }
  }
  return cur;
}

// cur の手前から循環で非0の slots を探す, 無ければ cur のまま
s32 FUN_0809a978(MainMenu* p, s32 cur) {
  s32 idx = cur - 1;
  s32 i;

  if (cur == 0) {
    idx = 9;
  }
  for (i = 0; i < 10; i++) {
    if (p->slots[idx] != 0) {
      return idx;
    }
    if (idx == 0) {
      idx = 9;
    } else {
      idx--;
    }
  }
  return cur;
}

NAKED void FUN_0809a9b0(MainMenu* p) { INCFUNC("asm/func/FUN_0809a9b0.inc"); }

NAKED void FUN_0809aaf4(MainMenu* p) { INCFUNC("asm/func/FUN_0809aaf4.inc"); }

void FUN_0809ac30(MainMenu* p);

// 17フレームかけて明るさを上げ, 終わったら次の状態へ移る
void FUN_0809ab70(MainMenu* p) {
  FUN_0808b4c0(p);
  FUN_0808a458(p->unk_9ec * 4, RGB(4, 4, 4));
  p->unk_9ec++;
  if (p->unk_9ec > 16) {
    p->unk_9f8 = 0;
    FUN_0808a33c(p, FUN_0809ac30);
  }
}

NAKED void FUN_0809abbc(void) { INCFUNC("asm/func/FUN_0809abbc.inc"); }

NAKED void FUN_0809ac30(MainMenu* p) { INCFUNC("asm/func/FUN_0809ac30.inc"); }

NAKED void FUN_0809ae0c(MainMenu* p) { INCFUNC("asm/func/FUN_0809ae0c.inc"); }

NAKED void FUN_0809aeb0(MainMenu* p) { INCFUNC("asm/func/FUN_0809aeb0.inc"); }

void FUN_0809b180(MainMenu* p);

// フェードの進み具合を9枚のスプライトへ配り, 0 に戻ったら次の状態へ移る
void FUN_0809b12c(MainMenu* p) {
  s32 i;

  FUN_0808a458(0x40, RGB(4, 4, 4));
  p->sprites[3].pos.x += 15;
  if (p->sprites[3].pos.x >= 0) {
    p->sprites[3].pos.x = 0;
    FUN_0808a33c(p, FUN_0809b180);
  }

  for (i = 0; i < 9; i++) {
    p->sprites[i + 4].pos.x = p->sprites[3].pos.x;
  }
}

NAKED void FUN_0809b180(MainMenu* p) { INCFUNC("asm/func/FUN_0809b180.inc"); }

NAKED void FUN_0809b2b8(MainMenu* p) { INCFUNC("asm/func/FUN_0809b2b8.inc"); }

NAKED s32 FUN_0809b348(MainMenu* p) { INCFUNC("asm/func/FUN_0809b348.inc"); }

NAKED s32 FUN_0809b3b0(MainMenu* p) { INCFUNC("asm/func/FUN_0809b3b0.inc"); }

// スプライトを全部描画リストから外す
void MainMenu1P_RemoveSprites(MainMenu* p) {
  MainSprite* sprite = p->sprites;
  s32 i;

  for (i = 0; i < 116; i++) {
    MainSprite_Remove(sprite);
    sprite++;
  }

  AuxSprite_Remove(&p->sprite_b60);
  AuxSprite_Remove(&p->sprite_bb8);
}

NAKED void MainMenu1P_0809b468(MainMenu* p) { INCFUNC("asm/func/MainMenu1P_0809b468.inc"); }

NAKED void FUN_0809bd14(MainMenu* p) { INCFUNC("asm/func/FUN_0809bd14.inc"); }

NAKED void MainMenu1P_0809bed8(MainMenu* p) { INCFUNC("asm/func/MainMenu1P_0809bed8.inc"); }

NAKED void FUN_0809bf88(MainMenu* p) { INCFUNC("asm/func/FUN_0809bf88.inc"); }

// VM の q 引数があればその値を, なければ 1 を unk_da0[3] に書き込む
void MainMenu1P_0809c010(MainMenu* p) {
  if (VM_SeekToNamedArg('q')) {
    p->unk_da0[3].unk_65 = VM_GetValue();
  } else {
    p->unk_da0[3].unk_65 = 1;
  }
}

void FUN_0809c040(void) {
  gMainMenu = NULL;
  u16_03002c14 = 1;
  u16_03002c10 = 0;
  u16_03002c18 = 1;
}

s32 FUN_0809c068(void) {
  if (gMainMenu == NULL) {
    return -1;
  }
  return gMainMenu->unk_9fc;
}

NAKED s32 FUN_0809c08c(s32 mode) { INCFUNC("asm/func/FUN_0809c08c.inc"); }

void FUN_0809c1c0(void) {
  if (gMainMenu != NULL) {
    gMainMenu->unk_9ff = gMainMenu->unk_9fe;
  }
}

void FUN_0809c1e8(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL) {
    if (p->unk_9ff >= 0) {
      FUN_0809c08c(p->unk_9ff);
      p->unk_9ff = -1;
    }
  }
}

void FUN_0809c214(void) { FUN_0809c1c0(); }

void FUN_0809c220(void) { FUN_0809c1e8(); }

// 0xC6AA
void Textbox_CloseBox(void) {
  if (VM_SeekToNamedArg('m')) {
    FUN_0809c08c(VM_GetValue());
  }
}

void FUN_0809c244(void) {
  if (gMainMenu != NULL) {
    FUN_0809c08c(gMainMenu->unk_9fe);
  }
}

// 0x2FA0
void FUN_0809c264(void) {
  if (gMainMenu != NULL && gMainMenu->unk_9fc == 0) {
    FUN_0809bf88(gMainMenu);
  }
}

void FUN_0809c28c(void) {
  if (gMainMenu != NULL && gMainMenu->player != NULL) {
    FUN_0808d5cc(gMainMenu);
    FUN_0808d4dc(gMainMenu);
    if (gMainMenu->unk_9fe <= 2) {
      FUN_0808d3d4(gMainMenu);
    }
  }
}

void FUN_0809c2d0(void) {
  if (gMainMenu != NULL && gMainMenu->player != NULL) {
    FUN_0808d774(gMainMenu);
    FUN_0808d564(gMainMenu);
    if (gMainMenu->unk_9fe <= 2) {
      FUN_0808d3d4(gMainMenu);
    }
  }
}

// VM の f 引数を unk_da0[3] に書き込む
void FUN_0809c314(void) {
  if (gMainMenu != NULL) {
    if (VM_SeekToNamedArg('f')) {
      gMainMenu->unk_da0[3].unk_65 = VM_GetValue();
    }
  }
}

NAKED void FUN_0809c344(s32 param_1, s32 param_2, u16 param_3, u8 param_4, s32 param_5) { INCFUNC("asm/func/FUN_0809c344.inc"); }

NAKED void FUN_0809c3c0(s32 param_1, s32 param_2, s32 param_3) { INCFUNC("asm/func/FUN_0809c3c0.inc"); }

void FUN_0809c430(void) {
  if (gMainMenu != NULL) {
    if (gMainMenu->unk_9fe == 1 || gMainMenu->unk_9fe == 2) {
      gMainMenu->unk_a22 = 4;
    }
  }
}

void FUN_0809c464(void) {
  if (gMainMenu != NULL) {
    Player* player = gPlayerPtr[0];

    gMainMenu->player = player;
    if (player != NULL) {
      FUN_0808d774(gMainMenu);
      FUN_0808d564(gMainMenu);
      FUN_0808d5cc(gMainMenu);
      FUN_0808d4dc(gMainMenu);

      if (gFlag030047a4 & FLAG030047A4_UNK_12) {
        if (gMainMenu->unk_9fe == 0) {
          FUN_0808e224(gMainMenu);
        }
        MainMenu_HideSprites(gMainMenu);
      } else {
        if (gMainMenu->unk_9fe == 0) {
          FUN_0808d3d4(gMainMenu);
          FUN_0808ce98(gMainMenu);
        }
      }
    }
  }
}

void FUN_0809c4f4(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL && p->unk_9fc == 0 && p->unk_9fe <= 2) {
    FUN_0808c95c(p, 0, 0xE0, 0x90);
    p->unk_c0c[3].unk_61 = 6;
    PlaySound_082406e0(SE_BREAK_898);
  }
}

void FUN_0809c544(u16* param_1) {
  MainMenu* p = gMainMenu;

  if (p != NULL) {
    p->unk_a9c = param_1;
    p->unk_a97 = 1;
    if (gFlag030047a4 & FLAG030047A4_LINK) {
      p->unk_a98 = 1;
    }
  }
}

void FUN_0809c58c(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL) {
    p->unk_a9c = NULL;
    p->unk_aa0[0].flags |= SPRFLAG_HIDDEN;
    p->unk_aa0[1].flags |= SPRFLAG_HIDDEN;
    p->unk_a97 = 0;
    p->unk_a98 = 0;
  }
}

void FUN_0809c5dc(void) {
  if (gMainMenu != NULL) {
    FUN_0808abec(gMainMenu, 2);
  }
}

void FUN_0809c5f4(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL) {
    p->unk_a10 = 10;
    p->unk_a0e = 10;
    p->unk_a12 = 180;
    p->unk_a14 = 0;
    FUN_0808ad5c(p);
  }
}

void FUN_0809c63c(void) {
  MainMenu* p = gMainMenu;

  if (p != NULL && VM_SeekToNamedArg('i')) {
    p->unk_3fa0[0] = VM_GetValue();
  }
}

NAKED void FUN_0809c668(MainMenu* p) { INCFUNC("asm/func/FUN_0809c668.inc"); }

NAKED void FUN_0809c70c(MainMenu* p) { INCFUNC("asm/func/FUN_0809c70c.inc"); }

NAKED void FUN_0809c780(MainMenu* p, s32 param_2, s32 param_3, s32 param_4) { INCFUNC("asm/func/FUN_0809c780.inc"); }

void MainMenuLink_Update_Internal(MainMenu* p) {
  if (p->player != NULL && p->unk_9fe != 7 && p->unk_9fe <= 2) {
    FUN_0808a610(p, 0, 3, 1);
    FUN_0808a768(p, 0, 3, 2);
    FUN_0809c780(p, 0, 9, 18);
    FUN_0808afac(p);
    FUN_0808ad5c(p);
    FUN_0809c668(p);
    FUN_0809c70c(p);
    FUN_0808b1bc(p);
  }
}

// 残差1命令, 原典は 0x9DF と 0x9E0 のオフセットを別々に作るが agbcc は前者を使い回して add #1 に畳む, ローカル分割 (Player* / 添字) は試済
NON_MATCH s32 MainMenuLink_Update(MainMenu* p) {
#ifdef NONMATCHING_C
  if (!(gEntityDisableFlags & ENTITY_DISABLE_0)) {
    Player* player = gPlayerPtr[p->playerIdx];

    p->player = player;
    MainMenuLink_Update_Internal(p);
  }
  return 0;
#else
  INCFUNC("asm/func/MainMenuLink_Update.inc");
#endif
}

s32 MainMenuLink_Destroy(MainMenu* p) {
  FUN_0808cf50(p);
  FUN_0808cffc(p);
  MainSprite_Remove(&p->unk_c0c[0].sprite);
  MainSprite_Remove(&p->unk_da0[0].sprite);
  gMainMenu = NULL;
  return 0;
}

NAKED void FUN_0809c960(MainMenu* p) { INCFUNC("asm/func/FUN_0809c960.inc"); }

NAKED void MainMenuLink_0809ca08(MainMenu* p) { INCFUNC("asm/func/MainMenuLink_0809ca08.inc"); }

NAKED s32 MainMenuLink_Init(MainMenu* p, u32 val) { INCFUNC("asm/func/MainMenuLink_Init.inc"); }

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
  Player* player = gPlayerPtr[0];

  p->player = player;
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  MainMenu1P_Update_Helper_0808c7c4(p);
  return 0;
}

s32 MainMenu1P_Destroy(MainMenu* p) {
  FUN_0808dda4(p);
  FUN_0808cf50(p);
  FUN_0808cacc(p);
  MainMenu1P_RemoveSprites(p);
  FUN_0808cffc(p);
  u16_03002c14 = p->page;
  gMainMenu = NULL;
  return 0;
}

NAKED s32 MainMenu1P_Init(MainMenu* p, u32 id) { INCFUNC("asm/func/MainMenu1P_Init.inc"); }

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
  if (gFlag030047a4 & FLAG030047A4_LINK) {
    return MainMenuLink_Create(id, _);
  }
  return MainMenu1P_Create(id, _);
}
