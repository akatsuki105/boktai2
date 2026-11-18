#include "bg_pltt.h"
#include "entity.h"
#include "file.h"
#include "game.h"
#include "global.h"
#include "inline.h"
#include "input.h"
#include "link_session.h"
#include "link_shop.h"
#include "menu.h"
#include "save.h"
#include "solar.h"
#include "sound.h"
#include "sprite.h"
#include "sprite_pltt.h"
#include "text.h"
#include "vec3.h"
#include "video.h"
#include "vm.h"
#include "weapon.h"

struct LinkShopScreen;

typedef void(LinkShopScreenFunc)(struct LinkShopScreen* p);

// 通信相手から受け取る情報, まとめて ClearMemory で消す
typedef struct {
  u8 sellable;    // 0x00, 相手の売れる武器の数, 種類 2 のメッセージで受け取る
  u8 freeSlots;   // 0x01, 相手の売れる武器と空きの枠の数, 同上
  u16 bank;       // 0x02, 相手の太陽バンクの残高, 種類 0 のメッセージで受け取る
  char name[12];  // 0x04, 相手の名前, 種類 1 のメッセージで受け取る
} LinkShopPartner;
static_assert(sizeof(LinkShopPartner) == 16);

// 武器の枠, アイコンを並べる関数は先頭を指すポインタからたどる
typedef struct {
  WeaponData weapons[18];       // 0x000, [0..15] は手持ちの武器 (GetWeaponData), [16] と [17] は受け取った武器の写し
  MainSprite icons[18];         // 0x288, weapons のアイコン
  MainSprite iconSprite;        // 0x948, カーソル位置の武器の損傷度アイコン
  MainSpriteGfx iconGfx;        // 0x9A8, SPR_INVENTORY_ICONS
  MainSpriteGfxFile* iconFile;  // 0x9C8, SPR_INVENTORY_ICONS
} LinkShopInventory;
static_assert(sizeof(LinkShopInventory) == 0x9CC);

// 通信販売 (シャイアンの店で2台をつないで武器を売り買いする) の画面 (HashName("武器交換画面")), LinkShopManager に自分を owner として登録する
// セーブ後に移る専用マップ Scr_0x0A3B が EntityA0A6 (通信セッション) と一緒に作り, 終わると Scr_0x0A3C で店に戻る
typedef struct LinkShopScreen {
  Entity e;                            // 0x0000, ENTITY_UNK_11
  LinkShopScreenFunc* updateCallback;  // 0x0018
  TilemapFile* tilemap0;               // 0x001C, MP_CD91, BG2 に敷く
  TilemapFile* tilemap1;               // 0x0020, MP_A413, BG0 に敷く
  rgb555* bgPltt;                      // 0x0024, bg_link_col_arr
  MainSprite sprites[28];              // 0x0028
  MainSpriteGfx gfx0;                  // 0x0AA8, SPR_UI_LINK
  MainSpriteGfx gfx1;                  // 0x0AC8, SPR_UI_START_MENU
  MainSpriteGfxFile* spriteFile0;      // 0x0AE8, SPR_UI_LINK
  MainSpriteGfxFile* spriteFile1;      // 0x0AEC, SPR_UI_START_MENU
  u16 poseIdx[32];                     // 0x0AF0, sprites のポーズ番号
  rgb555 pltt[4][16];                  // 0x0B30, gObjPlttData の写し, sprites[16..19] の pltt がここを指す
  u16 plttTimer;                       // 0x0BB0, pltt の12色目を明滅させる 0..49 のカウンタ
  u8 unk_bb2[2];                       // 0x0BB2, まだ未解析
  LinkShopPartner partner;             // 0x0BB4
  LinkShopInventory inv;               // 0x0BC4
  u8* weaponNames;                     // 0x1590, '.w', 武器名の文字列表
  u32 registeredMask;                  // 0x1594, 登録武器が入っている枠のビット
  u8 registeredCount;                  // 0x1598, 登録武器の数, sprites[22..] の印をこの数だけ出し入れする
  s8 selectedSlot;                     // 0x1599, 選んでいる武器の枠
  u16 moveTimer;                       // 0x159A, inv.icons[17] を moveDest へ寄せるフレーム数
  char statText[8];                    // 0x159C, 武器名の後ろに付ける補正値の文字列
  char weaponName[16];                 // 0x15A4, 相手が出した武器の名前
  Vec3 moveDest;                       // 0x15B4, inv.icons[17] を寄せる先
  LinkTradeWeapon recvWeapon;          // 0x15BC, 相手の武器, 種類 3, 4, 5 のメッセージで3回に分けて受け取る
  u16 recvSeq;                         // 0x15E0, 種類 3 のメッセージの LinkShopMsg.unk_02, 4 と 5 で同じでなければ通信を打ち切る
  u16 price;                           // 0x15E2, 取引の値段, 4桁の数字で出す
  u16 priceInput;                      // 0x15E4, 値段の入力中の値, 決めると price に写す
  u8 digitCursor;                      // 0x15E6, 値段の入力で選んでいる桁, 0 が1の位
  u8 maxDigitCursor;                   // 0x15E7, digitCursor の上限, 3
  u8 digitMax[4];                      // 0x15E8, 各桁の上限, 9
  u8 priceDigits[4];                   // 0x15EC, 入力中の値段の各桁, [0] が1の位
  u8* script;                          // 0x15F0, '.s'
  u8* unk_15f4;                        // 0x15F4, '.Y'
  u8 unk_15f8[0x1600 - 0x15F8];        // 0x15F8, まだ未解析
  s32 panelID[4];                      // 0x1600, MenuMessage のテキストパネル
  u32 flags;                           // 0x1610, LSSFLAG_*
  u8 stateEntered;                     // 0x1614, 状態を切り替えた直後だけ立つ
  u8 menuCursor;                       // 0x1615, 親機の項目選び (状態 0) のカーソル, 0 なら売る, 1 なら買う
  u8 state;                            // 0x1616, 状態番号
  s8 marqueeMsg;                       // 0x1617, Marquee に出しているメッセージ番号, 出し直しを省く, Init で -1
  u8 lastSignal;                       // 0x1618, 最後に送った合図か種類, 送信に失敗したら送り直す
  u8 keyRepeat;                        // 0x1619, 十字キーを押し続けているフレーム数, 12 で押し直し扱いにする
  u8 cursorSlot;                       // 0x161A, 武器の枠のカーソル位置, 4 列で並ぶ
  u8 returnSlot;                       // 0x161B, 左右から出品の枠へ入ったときの元の枠, 抜けるときにその行へ戻す
  u32 sendTag;                         // 0x161C, LinkShopManager_Send に渡す識別子
  s16 recvSignal;                      // 0x1620, 種類 10 のメッセージで受け取った合図の番号
  u8 sendStep;                         // 0x1622, 何回に分けて送るうちの何番目まで送ったか
  u8 yesNoCursor;                      // 0x1623, はい/いいえのカーソル, 0 がはい
  u8 cancelReturn;                     // 0x1624, 取引中止の後の戻り先, 0 なら取引の画面, 1 なら項目選び
  u8 handshakeTimer;                   // 0x1625, 相手の名前が届くまで数え, 120 で通信をあきらめる
  u16 exitScriptID;                    // 0x1626, .e=0, 通信が中断されたときに実行する
  u16 unk_1628;                        // 0x1628, .l=0, FUN_081e5290 が 0 でなければ実行する
  u16 timer;                           // 0x162A, 状態に入ってからのフレーム数
  u16 linkId;                          // 0x162C, 親機は 0, 子機は 1, つなぎ直したときに LinkConnect が渡す番号と比べる
  s16 partnerChoice;                   // 0x162E, 相手が選んだ項目 (0 か 1)
} LinkShopScreen;
static_assert(sizeof(LinkShopScreen) == 5680);

// LinkShopScreen.flags
#define LSSFLAG_MARQUEE (1 << 0)           // 0x00000001, Marquee を開いている
#define LSSFLAG_GOT_NAME (1 << 1)          // 0x00000002, 通信相手の名前を partner.name に受け取った
#define LSSFLAG_GOT_BANK (1 << 2)          // 0x00000004, 相手の太陽バンクの残高を partner.bank に受け取った
#define LSSFLAG_GOT_COUNTS (1 << 3)        // 0x00000008, 相手の武器の数を partner.sellable と partner.freeSlots に受け取った
#define LSSFLAG_NAME_SHOWN (1 << 4)        // 0x00000010, partner.name をパネルに出した
#define LSSFLAG_BANK_SHOWN (1 << 5)        // 0x00000020, partner.bank を数字で出した
#define LSSFLAG_COUNTS_SHOWN (1 << 6)      // 0x00000040, 武器の数を数字で出した
#define LSSFLAG_GOT_SIGNAL (1 << 7)        // 0x00000080, 種類 10 のメッセージで合図を受け取った
#define LSSFLAG_SELL_SCREEN (1 << 8)       // 0x00000100, 売り手の画面 (状態 3) を組んだ
#define LSSFLAG_BUY_SCREEN (1 << 9)        // 0x00000200, 買い手の画面 (状態 4) を組んだ
#define LSSFLAG_GOT_WEAPON (1 << 10)       // 0x00000400, 相手の武器を最後まで受け取った (種類 5)
#define LSSFLAG_GOT_WEAPON_HEAD (1 << 11)  // 0x00000800, 相手の武器の前半を受け取った (種類 3)
#define LSSFLAG_GOT_PRICE (1 << 12)        // 0x00001000, 種類 12 のメッセージで相手の値段を price に受け取った
#define LSSFLAG_GOT_OFFER (1 << 13)        // 0x00002000, 種類 11 のメッセージを受け取った, 買い手が値段を送ってくる合図
#define LSSFLAG_BUYER (1 << 15)            // 0x00008000, 買い手, 状態 4 の側
#define LSSFLAG_SELLER (1 << 16)           // 0x00010000, 売り手, 状態 3 の側
#define LSSFLAG_EDITING (1 << 17)          // 0x00020000, 値段を入力している (状態 7)
#define LSSFLAG_SEND_FAILED (1 << 18)      // 0x00040000, 送信に失敗している間だけ立つ
#define LSSFLAG_SEND2_FAILED (1 << 19)     // 0x00080000, 同上, LinkShopScreen_SendMsg の送信ぶん
#define LSSFLAG_GOT_4 (1 << 20)            // 0x00100000, 合図 4 を受け取った
#define LSSFLAG_MANAGER_KILLED (1 << 21)   // 0x00200000, LinkShopManager を自分で消した, 立っていると通信が終わっても画面を消さない
#define LSSFLAG_SENT (1 << 22)             // 0x00400000, 送信が済むと立ち (onSendDone), 次の送信で落とす
#define LSSFLAG_RESETTABLE (1 << 23)       // 0x00800000, 立っていないとソフトリセットを禁じる

extern u32 gRtcReadInhibit;  // src/time.c

bool8 LinkShopManager_IsFinished(void);  // src/link_shop.c
bool8 LinkShopManager_IsReady(void);
s32 LinkShopManager_IsParent(void);
void LinkShopManager_AllowSoftReset(void);
void LinkShopManager_Abort(void);
void WeaponData_FormatSuffix(WeaponData* w, s8* text);
void LinkShopManager_Kill(void);
bool8 Save_WriteExtraToNextSlot(void);
void RemoveWeapon(slot32_t n);
bool32 AddWeapon(WeaponData* data);
void GetWeaponData(slot32_t n, WeaponData* data);
s32 CountSellableWeapons(void);
s32 CountSellableOrEmptySlots(void);
void LinkShopManager_StopLinkWatch(void);
void* LinkConnect_Create(s32 timeout, s32 cancelable);
void LinkConnect_SetCallbacks(void* owner, void* onSuccess, void* onFailure);
void WeaponData_ShowNameInPanel(s32 panelID, u8* weapon, s8* suffix);
void MainMenu_SetWeaponMarquee(unknown* w, u8* pc);
bool8 LinkShopManager_IsBusy(void);
bool32 IsWeaponSellable(slot32_t n);                       // src/weapon.c
u8 Save_SwitchSlot(void);                                  // src/savedata.c
bool8 LinkShopManager_Send(s32* args, s32 kind, u32 tag);  // src/link_shop.c
void LinkShopManager_SetOwner(void* owner);
void LinkShopManager_SetCallbacks(void (*onRecv)(LinkShopScreen*, LinkShopMsg*), void (*onFinish)(LinkShopScreen*), void (*onSendDone)(LinkShopScreen*));
void LinkShopScreen_StateSaved(LinkShopScreen* p);
void LinkShopScreen_RemoveWeaponIcons(LinkShopScreen* p);
void LinkShopScreen_RemoveSprites(LinkShopScreen* p);
void LinkShopScreen_HideMessages(LinkShopScreen* p);
void LinkShopScreen_StateSaveFailed(LinkShopScreen* p);
void LinkShopScreen_StateLinkMismatch(LinkShopScreen* p);
void FUN_081e5290(LinkShopScreen* p);
void LinkShopScreen_ResetTrade(LinkShopScreen* p);
void LinkShopScreen_StateHandshake(LinkShopScreen* p);
void LinkShopScreen_StateDoneWaitAck(LinkShopScreen* p);
void LinkShopScreen_StateCancelWaitAck(LinkShopScreen* p);
void LinkShopScreen_StateCommitTrade(LinkShopScreen* p);
void LinkShopScreen_OnRestartReconnected(LinkShopScreen* p, u32 linkId);
void LinkShopScreen_OnCommitReconnected(LinkShopScreen* p, u32 linkId);
void LinkShopScreen_OnCommitReconnectFailed(LinkShopScreen* p);
void LinkShopScreen_OnRestartReconnectFailed(LinkShopScreen* p, s32 handle, s32 canceled);
void LinkShopScreen_StateCancel(LinkShopScreen* p);
void LinkShopScreen_StateWaitOffer(LinkShopScreen* p);
void LinkShopScreen_StateCancelWaitButton(LinkShopScreen* p);
void LinkShopScreen_StateExit(LinkShopScreen* p);
void LinkShopScreen_StateBuy(LinkShopScreen* p);
void LinkShopScreen_StateInputPrice(LinkShopScreen* p);
void LinkShopScreen_StateSell(LinkShopScreen* p);
void LinkShopScreen_StateReviewOffer(LinkShopScreen* p);
void LinkShopScreen_StateMenu(LinkShopScreen* p);
void LinkShopScreen_StateWaitPartnerChoice(LinkShopScreen* p);
void LinkShopScreen_StateQuit(LinkShopScreen* p);
void LinkShopScreen_StateInputPrice(LinkShopScreen* p);
void LinkShopScreen_StateSendOffer(LinkShopScreen* p);
s32 LinkShopScreen_MoveCursor(LinkShopScreen* p, Vec3* pos, u32 keys);
void LinkShopScreen_StateWaitPrice(LinkShopScreen* p);
void LinkShopScreen_StateMoveWeaponIcon(LinkShopScreen* p);
void LinkShopScreen_StateSendWeapon(LinkShopScreen* p);
bool8 LinkShopScreen_CanSelectCursorWeapon(LinkShopScreen* p);
void LinkShopScreen_FillBgMap(u32 x, s32 y, s32 width, s32 height, s32 value, u32 bgIdx);
void LinkShopScreen_StateWaitPartnerWeapon(LinkShopScreen* p);
s32 LinkShopScreen_ReadDpad(LinkShopScreen* p);
void LinkShopScreen_ShowCursorWeapon(LinkShopScreen* p);
void LinkShopScreen_StateSendCancel(LinkShopScreen* p);
void LinkShopScreen_StateWaitAnswer(LinkShopScreen* p);
void LinkShopScreen_StateMenu(LinkShopScreen* p);
void LinkShopScreen_StateDoneWaitButton(LinkShopScreen* p);
void LinkShopScreen_StateWaitChoiceAck(LinkShopScreen* p);
void LinkShopScreen_StateAckChoice(LinkShopScreen* p);
void LinkShopScreen_StateDone(LinkShopScreen* p);
void LinkShopScreen_ReturnToTrade(LinkShopScreen* p);
void LinkShopScreen_ReturnToMenu(LinkShopScreen* p);

static inline bool8 LinkShopScreen_TestFlag(LinkShopScreen* p, u32 flag) {
  if (TEST_FLAGS(p->flags, flag)) return TRUE;
  return FALSE;
}

static inline void LinkShopScreen_SetFlag(LinkShopScreen* p, u32 flag) { SET_FLAGS(p->flags, flag); }
static inline void LinkShopScreen_ClearFlag(LinkShopScreen* p, u32 flag) { CLEAR_FLAGS(p->flags, flag); }

// 更新関数を差し替えて状態番号を入れる
static inline void LinkShopScreen_SetState(LinkShopScreen* p, LinkShopScreenFunc* fn, u8 state) {
  p->updateCallback = fn;
  p->stateEntered = 1;
  p->state = state;
}

// 十字キーで移る先の枠, 0..15 は武器の枠, 16 は出品の枠, 17 はその下の枠
typedef struct {
  u8 up;
  u8 down;
  u8 left;
  u8 right;
} LinkShopCursorMove;

// [今の枠]
const LinkShopCursorMove sLinkShopCursorMoves[18] = {
    {12, 4,  16, 1 },
    {13, 5,  0,  2 },
    {14, 6,  1,  3 },
    {15, 7,  2,  16},
    {0,  8,  16, 5 },
    {1,  9,  4,  6 },
    {2,  10, 5,  7 },
    {3,  11, 6,  16},
    {4,  12, 16, 9 },
    {5,  13, 8,  10},
    {6,  14, 9,  11},
    {7,  15, 10, 16},
    {8,  0,  17, 13},
    {9,  1,  12, 14},
    {10, 2,  13, 15},
    {11, 3,  14, 17},
    {17, 17, 3,  0 },
    {16, 16, 15, 12},
};  // 0x085AE404

// sprites に使うポーズ番号の表を作る
void LinkShopScreen_InitPoseIdx(LinkShopScreen* p) {
  p->poseIdx[0] = 0;
  p->poseIdx[1] = 1;
  p->poseIdx[2] = 2;
  p->poseIdx[3] = 3;
  p->poseIdx[4] = 4;
  p->poseIdx[5] = 5;
  p->poseIdx[6] = 6;
  p->poseIdx[7] = 7;
  p->poseIdx[8] = 8;
  p->poseIdx[9] = 9;
  p->poseIdx[10] = 11;
  p->poseIdx[11] = 12;
  p->poseIdx[12] = 13;
  p->poseIdx[13] = 14;
  p->poseIdx[14] = 15;
  p->poseIdx[15] = 16;
  p->poseIdx[16] = 17;
  p->poseIdx[17] = 18;
  p->poseIdx[18] = 19;
  p->poseIdx[19] = 20;
  p->poseIdx[20] = 22;
  p->poseIdx[21] = 23;
  p->poseIdx[22] = 24;
  p->poseIdx[23] = 25;
  p->poseIdx[31] = 21;
  p->poseIdx[24] = 60;
  p->poseIdx[25] = 65;
  p->poseIdx[26] = 65;
  p->poseIdx[27] = 65;
  p->poseIdx[28] = 65;
  p->poseIdx[29] = 4;
  p->poseIdx[30] = 5;
  p->poseIdx[27] = 64;
}

void LinkShopScreen_SetupBG(LinkShopScreen* p) {
  s32 bgIndices[1];

  p->tilemap0 = GetFile(DIR_TILE_MAP, MP_CD91);
  p->tilemap1 = GetFile(DIR_TILE_MAP, MP_A413);
  bgIndices[0] = 1;
  Video_SetupBGLayout(2, 0, p->tilemap0, 0, 0, 1, bgIndices);
  bgIndices[0] = 3;
  Video_SetupBGLayout(0, 0, p->tilemap1, 0, 0, 1, bgIndices);
  Video_GenerateBGMap(3, 0, 0, 0, 0);
  p->bgPltt = GetBgPlttFile(BOKHASH("bg_link_col_arr"))->body;
  CpuCopy16(p->bgPltt, gBgPlttBuffer, 256 * sizeof(rgb555));
}

// 2つのスプライトファイルを開き, sprites[0..27] を poseIdx のポーズで登録する
void LinkShopScreen_CreateSprites(LinkShopScreen* p) {
  Vec3 pos;
  s32 i;

  p->spriteFile0 = GetFile(DIR_MAIN_SPRITE, SPR_UI_LINK);
  OpenMainSpriteFile(&p->gfx0, p->spriteFile0);
  p->spriteFile1 = GetFile(DIR_MAIN_SPRITE, SPR_UI_START_MENU);
  OpenMainSpriteFile(&p->gfx1, p->spriteFile1);
  Vec3_Clear(&pos);
  for (i = 0; i < 28; i++) {
    MainSpriteGfx* gfx;
    u16 pose;

    if (i < 16) {
      pose = p->poseIdx[0];
      gfx = &p->gfx0;
    } else if (i < 21) {
      switch (i) {
        case 16: {
          pose = p->poseIdx[20];
          break;
        }
        case 17: {
          pose = p->poseIdx[21];
          break;
        }
        case 18: {
          pose = p->poseIdx[22];
          break;
        }
        case 19: {
          pose = p->poseIdx[23];
          break;
        }
        case 20: {
          pose = p->poseIdx[31];
          break;
        }
        default: {
          pose = 0;
          break;
        }
      }
      gfx = &p->gfx0;
    } else if (i < 22) {
      pose = p->poseIdx[i];
      gfx = &p->gfx1;
    } else if (i < 26) {
      pose = p->poseIdx[25];
      gfx = &p->gfx1;
    } else if (i < 27) {
      pose = p->poseIdx[29];
      gfx = &p->gfx1;
    } else if (i < 28) {
      pose = p->poseIdx[27];
      gfx = &p->gfx1;
    } else {
      pose = p->poseIdx[i];
      gfx = &p->gfx0;
    }
    MainSprite_Add(&p->sprites[i], gfx, pose, SPRFLAG_SCREEN_COORD, 0, 0, 0, &pos);
  }
}

// 数字のスプライト sprites[0..15] を画面の決まった位置に並べる
void LinkShopScreen_PlaceDigitSprites(LinkShopScreen* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    switch (i) {
      case 0: {
        p->sprites[i].pos.x = 0x58;
        p->sprites[i].pos.y = 0x38;
        break;
      }
      case 1: {
        p->sprites[i].pos.x = 0x50;
        p->sprites[i].pos.y = 0x38;
        break;
      }
      case 2: {
        p->sprites[i].pos.x = 0x48;
        p->sprites[i].pos.y = 0x38;
        break;
      }
      case 3: {
        p->sprites[i].pos.x = 0x40;
        p->sprites[i].pos.y = 0x38;
        break;
      }
      case 4: {
        p->sprites[i].pos.x = 0xD8;
        p->sprites[i].pos.y = 0x38;
        break;
      }
      case 5: {
        p->sprites[i].pos.x = 0xD0;
        p->sprites[i].pos.y = 0x38;
        break;
      }
      case 6: {
        p->sprites[i].pos.x = 0xC8;
        p->sprites[i].pos.y = 0x38;
        break;
      }
      case 7: {
        p->sprites[i].pos.x = 0xC0;
        p->sprites[i].pos.y = 0x38;
        break;
      }
      case 8: {
        p->sprites[i].pos.x = 0x40;
        p->sprites[i].pos.y = 0x50;
        break;
      }
      case 9: {
        p->sprites[i].pos.x = 0x38;
        p->sprites[i].pos.y = 0x50;
        break;
      }
      case 10: {
        p->sprites[i].pos.x = 0x58;
        p->sprites[i].pos.y = 0x50;
        break;
      }
      case 11: {
        p->sprites[i].pos.x = 0x50;
        p->sprites[i].pos.y = 0x50;
        break;
      }
      case 12: {
        p->sprites[i].pos.x = 0xC0;
        p->sprites[i].pos.y = 0x50;
        break;
      }
      case 13: {
        p->sprites[i].pos.x = 0xB8;
        p->sprites[i].pos.y = 0x50;
        break;
      }
      case 14: {
        p->sprites[i].pos.x = 0xD8;
        p->sprites[i].pos.y = 0x50;
        break;
      }
      case 15: {
        p->sprites[i].pos.x = 0xD0;
        p->sprites[i].pos.y = 0x50;
        break;
      }
    }
  }
}

// 状態表示のスプライト sprites[0..20] とカーソル類 sprites[26..27] をまとめて隠す
void LinkShopScreen_HideSprites(LinkShopScreen* p) {
  p->sprites[0].flags |= SPRFLAG_HIDDEN;
  p->sprites[1].flags |= SPRFLAG_HIDDEN;
  p->sprites[2].flags |= SPRFLAG_HIDDEN;
  p->sprites[3].flags |= SPRFLAG_HIDDEN;
  p->sprites[4].flags |= SPRFLAG_HIDDEN;
  p->sprites[5].flags |= SPRFLAG_HIDDEN;
  p->sprites[6].flags |= SPRFLAG_HIDDEN;
  p->sprites[7].flags |= SPRFLAG_HIDDEN;
  p->sprites[8].flags |= SPRFLAG_HIDDEN;
  p->sprites[9].flags |= SPRFLAG_HIDDEN;
  p->sprites[10].flags |= SPRFLAG_HIDDEN;
  p->sprites[11].flags |= SPRFLAG_HIDDEN;
  p->sprites[12].flags |= SPRFLAG_HIDDEN;
  p->sprites[13].flags |= SPRFLAG_HIDDEN;
  p->sprites[14].flags |= SPRFLAG_HIDDEN;
  p->sprites[15].flags |= SPRFLAG_HIDDEN;
  p->sprites[17].flags |= SPRFLAG_HIDDEN;
  p->sprites[16].flags |= SPRFLAG_HIDDEN;
  p->sprites[18].flags |= SPRFLAG_HIDDEN;
  p->sprites[19].flags |= SPRFLAG_HIDDEN;
  p->sprites[26].flags |= SPRFLAG_HIDDEN;
  p->sprites[20].flags |= SPRFLAG_HIDDEN;
  p->sprites[27].flags |= SPRFLAG_HIDDEN;
}

// 親機の画面で使う sprites[0..16] を見せる
void LinkShopScreen_ShowParentSprites(LinkShopScreen* p) {
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[5].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[6].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[7].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[8].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[9].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[10].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[11].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[12].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[14].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[15].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[16].flags &= ~SPRFLAG_HIDDEN;
}

// 子機の画面で使う sprites[0..15] を見せる
void LinkShopScreen_ShowChildSprites(LinkShopScreen* p) {
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[4].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[5].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[6].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[7].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[8].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[9].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[10].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[11].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[12].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[13].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[14].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[15].flags &= ~SPRFLAG_HIDDEN;
}

void FUN_081e2d98(LinkShopScreen* p) {
  p->sprites[17].flags |= SPRFLAG_HIDDEN;
  p->sprites[18].flags |= SPRFLAG_HIDDEN;
  p->sprites[19].flags |= SPRFLAG_HIDDEN;
  p->sprites[20].flags |= SPRFLAG_HIDDEN;
  p->sprites[27].flags |= SPRFLAG_HIDDEN;
}

void FUN_081e2dd8(LinkShopScreen* p) {
  p->sprites[17].flags |= SPRFLAG_HIDDEN;
  p->sprites[16].flags |= SPRFLAG_HIDDEN;
  p->sprites[18].flags |= SPRFLAG_HIDDEN;
  p->sprites[19].flags |= SPRFLAG_HIDDEN;
  p->sprites[20].flags |= SPRFLAG_HIDDEN;
  p->sprites[27].flags |= SPRFLAG_HIDDEN;
}

// 受け取った武器 (weapons[17]) の名前を weaponName に写す, タグ "<" の手前で止める
// 残差は str を r2 へ写す位置だけ (40/40), 原典は先頭の判定の後に写す
// Tier A 試済 (while の条件順, if + do/while), 未: Tier C
NON_MATCH void LinkShopScreen_CopyWeaponName(LinkShopScreen* p) {
#ifdef NONMATCHING_C
  char* str = GetStringByID(VM_ParseStringRef(p->weaponNames) + p->inv.weapons[17].id);
  s32 i = 0;

  if (*str != '\0' && *str != '<') {
    do {
      p->weaponName[i] = *str;
      str++;
      i++;
    } while (*str != '\0' && i < 16 && *str != '<');
  }
  p->weaponName[i] = '\0';
#else
  INCFUNC("asm/func/LinkShopScreen_CopyWeaponName.inc");
#endif
}

s32 LinkShopScreen_ReadScriptArgs(LinkShopScreen* p) {
  if (VM_SeekToNamedArg('s')) {
    p->script = VM_GetPC_Proxy();
    if (p->script == NULL) {
      return 0;
    }
  }
  if (VM_SeekToNamedArg('w')) {
    p->weaponNames = VM_GetPC_Proxy();
    if (p->weaponNames == NULL) {
      return 0;
    }
  }
  if (VM_SeekToNamedArg('Y')) {
    p->unk_15f4 = VM_GetPC_Proxy();
    if (p->unk_15f4 == NULL) {
      return 0;
    }
  }
  return 1;
}

// 今の状態に合った案内を Marquee に出す, 出しているものと同じなら出し直さない
void LinkShopScreen_UpdateMarquee(LinkShopScreen* p) {
  if (!LinkShopScreen_TestFlag(p, LSSFLAG_MARQUEE)) {
    FUN_08049f5c();
    Marquee_Clear();
    SET_FLAGS(p->flags, LSSFLAG_MARQUEE);
    return;
  }
  if (p->state == 0x16 || p->state == 0x13 || p->state == 10) {
    if (p->marqueeMsg == 10) {
      return;
    }
    Marquee_Clear();
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 10));
    p->marqueeMsg = 10;
    return;
  }
  if (LinkShopManager_IsBusy() || p->state == 2 || p->state == 0x15 || p->state == 8 || p->state == 0x1D || p->state == 5) {
    if (p->marqueeMsg == 7) {
      return;
    }
    Marquee_Clear();
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 7));
    p->marqueeMsg = 7;
    return;
  }
  if (LinkShopManager_IsParent()) {
    if (p->state == 0) {
      if (p->menuCursor == 0) {
        if (p->partner.freeSlots - p->partner.sellable <= 0) {
          if (p->marqueeMsg == 5) {
            return;
          }
          Marquee_Clear();
          Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 5));
          p->marqueeMsg = 5;
        } else if (CountSellableWeapons() <= 0) {
          if (p->marqueeMsg == 20) {
            return;
          }
          Marquee_Clear();
          Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 20));
          p->marqueeMsg = 20;
        } else {
          if (p->marqueeMsg == 3) {
            return;
          }
          Marquee_Clear();
          Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 3));
          p->marqueeMsg = 3;
        }
      } else {
        if (CountSellableOrEmptySlots() - CountSellableWeapons() <= 0) {
          if (p->marqueeMsg == 6) {
            return;
          }
          Marquee_Clear();
          Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 6));
          p->marqueeMsg = 6;
        } else if (p->partner.sellable == 0) {
          if (p->marqueeMsg == 21) {
            return;
          }
          Marquee_Clear();
          Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 21));
          p->marqueeMsg = 21;
        } else {
          if (p->marqueeMsg == 4) {
            return;
          }
          Marquee_Clear();
          Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 4));
          p->marqueeMsg = 4;
        }
      }
    }
  } else if (p->state == 1) {
    if (p->marqueeMsg == 2) {
      return;
    }
    Marquee_Clear();
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 2));
    p->marqueeMsg = 2;
  }
  if (p->state == 10 || p->state == 13) {
    if (p->marqueeMsg == 10) {
      return;
    }
    Marquee_Clear();
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 10));
    p->marqueeMsg = 10;
  } else if (p->state == 3) {
    if (p->marqueeMsg == p->cursorSlot + 25) {
      return;
    }
    LinkShopScreen_ShowCursorWeapon(p);
    p->marqueeMsg = p->cursorSlot + 25;
  } else if (p->state == 4) {
    if (p->cursorSlot == 17) {
      if (p->marqueeMsg == 15) {
        return;
      }
      Marquee_Clear();
      Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 15));
      p->marqueeMsg = 15;
    } else {
      if (p->marqueeMsg == p->cursorSlot + 25) {
        return;
      }
      LinkShopScreen_ShowCursorWeapon(p);
      p->marqueeMsg = p->cursorSlot + 25;
    }
  } else if (p->state == 7) {
    if (gStat->solarBank >= p->priceInput) {
      if (p->marqueeMsg == 16) {
        return;
      }
      Marquee_Clear();
      Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 16));
      p->marqueeMsg = 16;
    } else {
      if (p->marqueeMsg == 17) {
        return;
      }
      Marquee_Clear();
      Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 17));
      p->marqueeMsg = 17;
    }
  }
}

// 相手の太陽バンクの残高を受け取っていれば, 自分と相手の残高を4桁ずつ sprites[0..7] に出す
// 残差は 0 を r6 に持って2桁目以降の d = 0 に写す点だけ (157/161), ShowPrice と同じ形
// Tier A-C 試済 (u16 の d, 桁ごとのブロック, for, 宣言時の初期化), 未: 使われない 0 初期化の変数
NON_MATCH void LinkShopScreen_ShowBanks(LinkShopScreen* p) {
#ifdef NONMATCHING_C
  if (LinkShopScreen_TestFlag(p, LSSFLAG_GOT_BANK)) {
    s32 v = gStat->solarBank;
    s32 d;

    d = 0;
    while (v > 999) {
      d++;
      v -= 1000;
    }
    MainSprite_LoadPose(&p->sprites[3], &p->gfx0, d);
    d = 0;
    while (v > 99) {
      d++;
      v -= 100;
    }
    MainSprite_LoadPose(&p->sprites[2], &p->gfx0, d);
    d = 0;
    while (v > 9) {
      d++;
      v -= 10;
    }
    MainSprite_LoadPose(&p->sprites[1], &p->gfx0, d);
    d = 0;
    while (v > 0) {
      d++;
      v -= 1;
    }
    MainSprite_LoadPose(&p->sprites[0], &p->gfx0, d);
    v = p->partner.bank;
    d = 0;
    while (v > 999) {
      d++;
      v -= 1000;
    }
    MainSprite_LoadPose(&p->sprites[7], &p->gfx0, d);
    d = 0;
    while (v > 99) {
      d++;
      v -= 100;
    }
    MainSprite_LoadPose(&p->sprites[6], &p->gfx0, d);
    d = 0;
    while (v > 9) {
      d++;
      v -= 10;
    }
    MainSprite_LoadPose(&p->sprites[5], &p->gfx0, d);
    d = 0;
    while (v > 0) {
      d++;
      v -= 1;
    }
    MainSprite_LoadPose(&p->sprites[4], &p->gfx0, d);
  }
#else
  INCFUNC("asm/func/LinkShopScreen_ShowBanks.inc");
#endif
}

// 相手の武器の数を受け取っていれば, 自分と相手の売れる武器の数と空きを含めた数を2桁ずつ sprites[8..15] に出す
// 残差は 0 を r6 に持って2つ目以降の d = 0 に写す点だけ (148/149), ShowBanks と同じ形
// Tier A-C 試済 (使われない 0 の変数, 呼び出し前の d = 0, 2桁の inline, do-while(0) のマクロ)
NON_MATCH void LinkShopScreen_ShowWeaponCounts(LinkShopScreen* p) {
#ifdef NONMATCHING_C
  if (LinkShopScreen_TestFlag(p, LSSFLAG_GOT_COUNTS)) {
    s32 v;
    s32 d;

    v = CountSellableWeapons();
    d = 0;
    while (v > 9) {
      d++;
      v -= 10;
    }
    MainSprite_LoadPose(&p->sprites[9], &p->gfx0, d);
    d = 0;
    while (v > 0) {
      d++;
      v -= 1;
    }
    MainSprite_LoadPose(&p->sprites[8], &p->gfx0, d);
    v = CountSellableOrEmptySlots();
    d = 0;
    while (v > 9) {
      d++;
      v -= 10;
    }
    MainSprite_LoadPose(&p->sprites[11], &p->gfx0, d);
    d = 0;
    while (v > 0) {
      d++;
      v -= 1;
    }
    MainSprite_LoadPose(&p->sprites[10], &p->gfx0, d);
    v = p->partner.sellable;
    d = 0;
    while (v > 9) {
      d++;
      v -= 10;
    }
    MainSprite_LoadPose(&p->sprites[13], &p->gfx0, d);
    d = 0;
    while (v > 0) {
      d++;
      v -= 1;
    }
    MainSprite_LoadPose(&p->sprites[12], &p->gfx0, d);
    v = p->partner.freeSlots;
    d = 0;
    while (v > 9) {
      d++;
      v -= 10;
    }
    MainSprite_LoadPose(&p->sprites[15], &p->gfx0, d);
    d = 0;
    while (v > 0) {
      d++;
      v -= 1;
    }
    MainSprite_LoadPose(&p->sprites[14], &p->gfx0, d);
  }
#else
  INCFUNC("asm/func/LinkShopScreen_ShowWeaponCounts.inc");
#endif
}

// 数字のスプライト sprites[0..15] をすべてポーズ 0 に戻す
void LinkShopScreen_ResetDigitSprites(LinkShopScreen* p) {
  MainSprite_LoadPose(&p->sprites[3], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[2], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[1], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[0], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[7], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[6], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[5], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[4], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[9], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[8], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[11], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[10], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[13], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[12], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[15], &p->gfx0, 0);
  MainSprite_LoadPose(&p->sprites[14], &p->gfx0, 0);
}

// 4桁の数字のスプライト sprites[0..3] を左側に並べて見せる
void LinkShopScreen_ShowDigitsLeft(LinkShopScreen* p) {
  p->sprites[3].pos.x = 0x40;
  p->sprites[3].pos.y = 0x68;
  p->sprites[2].pos.x = 0x48;
  p->sprites[2].pos.y = 0x68;
  p->sprites[1].pos.x = 0x50;
  p->sprites[1].pos.y = 0x68;
  p->sprites[0].pos.x = 0x58;
  p->sprites[0].pos.y = 0x68;
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
}

void FUN_081e36e8(LinkShopScreen* p) {
  LinkShopScreen_ShowDigitsLeft(p);
  p->price = 0;
  ClearMemory(&p->recvWeapon, sizeof(p->recvWeapon));
}

void LinkShopScreen_ResetPriceInput(LinkShopScreen* p) {
  p->maxDigitCursor = 3;
  p->digitMax[0] = 9;
  p->digitMax[1] = 9;
  p->digitMax[2] = 9;
  p->digitMax[3] = 9;
  ClearMemory(p->priceDigits, sizeof(p->priceDigits));
}

// 4桁ぶんの数字を10進の値に組み直す
s32 LinkShopScreen_ComposePrice(LinkShopScreen* p) { return p->priceDigits[0] + p->priceDigits[1] * 10 + p->priceDigits[2] * 100 + p->priceDigits[3] * 1000; }

// value を4桁で sprites[0..3] に出し, 値段の入力中 (状態 7) は選んでいる桁を強調したポーズにする
void LinkShopScreen_ShowPriceInput(LinkShopScreen* p, s32 value) {
  s32 d;

  d = 0;
  while (value > 999) {
    d++;
    value -= 1000;
  }
  if (p->digitCursor == 3 && p->state == 7) {
    MainSprite_LoadPose(&p->sprites[3], &p->gfx0, p->poseIdx[d + 10]);
  } else {
    MainSprite_LoadPose(&p->sprites[3], &p->gfx0, p->poseIdx[d]);
  }
  d = 0;
  while (value > 99) {
    d++;
    value -= 100;
  }
  if (p->digitCursor == 2 && p->state == 7) {
    MainSprite_LoadPose(&p->sprites[2], &p->gfx0, p->poseIdx[d + 10]);
  } else {
    MainSprite_LoadPose(&p->sprites[2], &p->gfx0, p->poseIdx[d]);
  }
  d = 0;
  while (value > 9) {
    d++;
    value -= 10;
  }
  if (p->digitCursor == 1 && p->state == 7) {
    MainSprite_LoadPose(&p->sprites[1], &p->gfx0, p->poseIdx[d + 10]);
  } else {
    MainSprite_LoadPose(&p->sprites[1], &p->gfx0, p->poseIdx[d]);
  }
  d = 0;
  while (value > 0) {
    d++;
    value -= 1;
  }
  if (p->digitCursor == 0 && p->state == 7) {
    MainSprite_LoadPose(&p->sprites[0], &p->gfx0, p->poseIdx[d + 10]);
  } else {
    MainSprite_LoadPose(&p->sprites[0], &p->gfx0, p->poseIdx[d]);
  }
}

// 相手から届いたメッセージを種類ごとに受け取る, 武器は種類 3, 4, 5 の3回に分けて届く
// 残差は種類の比較 (原典は kind を1度読んで比べるたびに u16 へ切り詰め, 結果を 0/1 にしてから分岐する) と効果の書き込みの番地の組み方 (352/372)
// Tier A-C 試済 (u16 / s32 の kind と比較の inline, msg を受ける比較の inline, SetFlag, 効果のポインタ), 未: LinkShopMsg の型の見直し
NON_MATCH void LinkShopScreen_OnRecv(LinkShopScreen* p, LinkShopMsg* msg) {
#ifdef NONMATCHING_C
  if (p != NULL) {
    if (msg->kind == 0) {
      p->partner.bank = msg->data[0];
      SET_FLAGS(p->flags, LSSFLAG_GOT_BANK);
    } else if (msg->kind == 1) {
      char* src = (char*)msg->data;
      s32 i = 0;

      if (*src != '\0') {
        do {
          p->partner.name[i] = *src;
          src++;
          i++;
        } while (*src != '\0' && i < 12);
      }
      p->partner.name[i] = '\0';
      LinkShopScreen_SetFlag(p, LSSFLAG_GOT_NAME);
    } else if (msg->kind == 2) {
      p->partner.sellable = msg->data[0];
      p->partner.freeSlots = msg->data[1];
      SET_FLAGS(p->flags, LSSFLAG_GOT_COUNTS);
    } else if (msg->kind == 10) {
      p->recvSignal = msg->data[0];
      SET_FLAGS(p->flags, LSSFLAG_GOT_SIGNAL);
      if (p->recvSignal == 4) {
        SET_FLAGS(p->flags, LSSFLAG_GOT_4);
      }
    } else if (msg->kind == 3) {
      p->recvWeapon.id = msg->data[0];
      p->recvWeapon.kind = FixToInt(8, msg->data[0]);
      p->recvWeapon.rank = FixToInt(16, msg->data[0]);
      p->recvWeapon.lv = FixToInt(24, msg->data[0]);
      p->recvWeapon.atk = msg->data[1];
      p->recvWeapon.durability = FixToInt(8, msg->data[1]);
      p->recvWeapon.wear = FixToInt(16, msg->data[1]);
      p->recvWeapon.quality = msg->data[2];
      p->recvWeapon.price = FixToInt(16, msg->data[2]);
      p->recvSeq = msg->unk_02;
      SET_FLAGS(p->flags, LSSFLAG_GOT_WEAPON_HEAD);
    } else if (msg->kind == 4) {
      u8* src;
      s32 i;

      if (p->recvSeq != msg->unk_02) {
        LinkShopManager_Abort();
        return;
      }
      src = (u8*)msg->data;
      for (i = 0; i < 12; i++) {
        p->recvWeapon.PS[i] = src[i];
      }
    } else if (msg->kind == 5) {
      u8* src;
      s32 i;

      if (p->recvSeq != msg->unk_02) {
        LinkShopManager_Abort();
        return;
      }
      src = (u8*)msg->data;
      for (i = 0; i < 3; i++) {
        p->recvWeapon.effects[i][0] = *src;
        src++;
        p->recvWeapon.effects[i][1] = *src;
        src++;
        p->recvWeapon.effects[i][2] = *src;
        src++;
        p->recvWeapon.effects[i][3] = *src;
        src++;
      }
      p->inv.weapons[17] = *(WeaponData*)&p->recvWeapon;
      p->inv.weapons[16] = *(WeaponData*)&p->recvWeapon;
      MainSprite_LoadPose(&p->inv.icons[17], &p->inv.iconGfx, p->inv.weapons[17].id);
      p->inv.icons[17].flags &= ~SPRFLAG_HIDDEN;
      p->flags = (p->flags | LSSFLAG_GOT_WEAPON) & ~LSSFLAG_GOT_WEAPON_HEAD;
    } else if (msg->kind == 11) {
      SET_FLAGS(p->flags, LSSFLAG_GOT_OFFER);
    } else if (msg->kind == 12) {
      p->price = msg->data[0];
      SET_FLAGS(p->flags, LSSFLAG_GOT_PRICE);
    }
    msg->kind = 0;
  }
#else
  INCFUNC("asm/func/LinkShopScreen_OnRecv.inc");
#endif
}

void LinkShopScreen_OnSendDone(LinkShopScreen* p) { SET_FLAGS(p->flags, LSSFLAG_SENT); }

// 止めていた太陽センサーと時計の読み取りを再開する
void LinkShopScreen_EnableSensor(LinkShopScreen* p) {
  Taiyo_Enable();
  gRtcReadInhibit = 0;
}

// 相手の名前を受け取っていれば, 上の2枚のパネルに自分と相手の名前を出す
void LinkShopScreen_ShowNames(LinkShopScreen* p) {
  if (LinkShopScreen_TestFlag(p, LSSFLAG_GOT_NAME)) {
    MenuMessage_SetScript(p->panelID[0], p->script);
    MenuMessage_SetMessage(p->panelID[0], 0);
    MenuMessage_SetScript(p->panelID[1], p->script);
    MenuMessage_SetMessage(p->panelID[1], 1);
    FUN_0804a40c(p->panelID[0], 1, gStat->name);
    FUN_0804a40c(p->panelID[1], 2, p->partner.name);
    MenuMessage_Start(p->panelID[0]);
    MenuMessage_Start(p->panelID[1]);
  }
}

void LinkShopScreen_CreatePanels(LinkShopScreen* p) {
  p->panelID[0] = MenuMessage_Create(1, 4, 10, 2);
  p->panelID[1] = MenuMessage_Create(17, 4, 10, 2);
  p->panelID[2] = MenuMessage_Create(2, 16, 28, 2);
  p->panelID[3] = MenuMessage_Create(0, 16, 28, 2);
  ClearMemory(p->partner.name, sizeof(p->partner.name));
  p->partner.name[0] = '\0';
}

// 4枚のパネルを隠して初期の位置と大きさに戻す
void LinkShopScreen_ResetPanels(LinkShopScreen* p) {
  MenuMessage_Hide(p->panelID[0]);
  MenuMessage_Hide(p->panelID[1]);
  MenuMessage_Hide(p->panelID[2]);
  MenuMessage_Hide(p->panelID[3]);
  MenuMessage_SetRect(p->panelID[0], 1, 4, 10, 2);
  MenuMessage_SetRect(p->panelID[1], 17, 4, 10, 2);
  MenuMessage_SetRect(p->panelID[2], 2, 16, 28, 2);
  MenuMessage_SetRect(p->panelID[3], 0, 16, 28, 2);
}

// カーソル位置の武器が, 出品に選んだものとは別の売れる武器かを返す
bool8 LinkShopScreen_CanSelectCursorWeapon(LinkShopScreen* p) {
  if (p->cursorSlot == p->selectedSlot || !IsWeaponSellable(p->cursorSlot)) {
    return FALSE;
  }
  return TRUE;
}

void LinkShopScreen_InitSlotCursor(LinkShopScreen* p) {
  MainSprite* sprite;

  p->cursorSlot = 0;
  p->returnSlot = 0;
  sprite = &p->sprites[21];
  sprite->pos.x = (p->cursorSlot & 3) * 24 + 0x90;
  sprite->pos.y = (p->cursorSlot >> 2) * 24 + 0x20;
  sprite->flags |= SPRFLAG_HIDDEN;
  MainSprite_SetAnim(sprite, &p->gfx1, 0, 1, 0);
}

// 登録武器の入っている枠に印のスプライトを置き, 枠のビットと数を数える
void LinkShopScreen_InitRegisteredMarks(LinkShopScreen* p) {
  s32 i;

  p->registeredMask = 0;
  p->registeredCount = 0;
  for (i = 0; i < 4; i++) {
    MainSprite* sprite = &p->sprites[22 + i];
    s32 slot = REGISTERED_WEAPON(i);

    if (slot >= 0) {
      sprite->pos.x = (slot & 3) * 24 + 0x90;
      sprite->pos.y = (slot >> 2) * 24 + 0x20;
      p->registeredMask |= 1 << slot;
      p->registeredCount++;
    }
    sprite->flags |= SPRFLAG_HIDDEN;
  }
}

void LinkShopScreen_ShowRegisteredMarks(LinkShopScreen* p) {
  s32 i;

  for (i = 0; i < p->registeredCount; i++) {
    p->sprites[i + 22].flags &= ~SPRFLAG_HIDDEN;
  }
}

void LinkShopScreen_HideRegisteredMarks(LinkShopScreen* p) {
  s32 i;

  for (i = 0; i < p->registeredCount; i++) {
    p->sprites[i + 22].flags |= SPRFLAG_HIDDEN;
  }
}

s32 LinkShopScreen_CreateIconSprite(LinkShopScreen* p) {
  Vec3 pos;

  VEC3_SET(pos, 0, 0x80, 0);
  return MainSprite_Add(&p->inv.iconSprite, &p->inv.iconGfx, 0xD0, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD, 0, PLAYMODE_PAUSE, 0, &pos);
}

// 武器のアイコンのファイルを開き, 手持ちの武器を inv.weapons に読んでアイコンを並べる
void LinkShopScreen_CreateWeaponIcons(LinkShopScreen* p) {
  LinkShopInventory* inv = &p->inv;
  Vec3 pos;
  MainSpriteGfxFile* f;
  s32 i;

  Vec3_Clear(&pos);
  f = GetFile(DIR_MAIN_SPRITE, SPR_INVENTORY_ICONS);
  if (f != NULL) {
    inv->iconFile = f;
    OpenMainSpriteFile(&inv->iconGfx, f);
    for (i = 0; i < 16; i++) {
      pos.x = (i & 3) * 24 + 0x90;
      pos.y = (i >> 2) * 24 + 0x20;
      GetWeaponData(i, &inv->weapons[i]);
      MainSprite_Add(&inv->icons[i], &inv->iconGfx, inv->weapons[i].id, SPRFLAG_SCREEN_COORD, 1, PLAYMODE_PAUSE, 0, &pos);
      if (!IsWeaponSellable(i)) {
        inv->icons[i].plttID = 736;
        inv->icons[i].pltt = &gObjPlttData[736 * 16];
      } else {
        inv->icons[i].plttID = 735;
        inv->icons[i].pltt = &gObjPlttData[735 * 16];
      }
      inv->icons[i].flags |= SPRFLAG_HIDDEN;
    }
    pos.x = 0x30;
    pos.y = 0x48;
    for (i = 16; i < 18; i++) {
      MainSprite_Add(&inv->icons[i], &inv->iconGfx, 0, SPRFLAG_SCREEN_COORD, 1, PLAYMODE_PAUSE, 0, &pos);
      inv->icons[i].flags |= SPRFLAG_HIDDEN;
    }
    LinkShopScreen_CreateIconSprite(p);
  }
}

// 手持ちの武器を inv.weapons に読み直し, アイコンとパレットを合わせて隠す
void LinkShopScreen_ReloadWeapons(LinkShopScreen* p) {
  LinkShopInventory* inv = &p->inv;
  Vec3 pos;
  MainSpriteGfxFile* f;
  s32 i;

  Vec3_Clear(&pos);
  f = GetFile(DIR_MAIN_SPRITE, SPR_INVENTORY_ICONS);
  if (f != NULL) {
    inv->iconFile = f;
    OpenMainSpriteFile(&inv->iconGfx, f);
    for (i = 0; i < 16; i++) {
      pos.x = (i & 3) * 24 + 0x90;
      pos.y = (i >> 2) * 24 + 0x20;
      GetWeaponData(i, &inv->weapons[i]);
      MainSprite_LoadPose(&inv->icons[i], &inv->iconGfx, inv->weapons[i].id);
      if (!IsWeaponSellable(i)) {
        inv->icons[i].plttID = 736;
        inv->icons[i].pltt = &gObjPlttData[736 * 16];
      } else {
        inv->icons[i].plttID = 735;
        inv->icons[i].pltt = &gObjPlttData[735 * 16];
      }
      inv->icons[i].flags |= SPRFLAG_HIDDEN;
    }
    pos.x = 0x30;
    pos.y = 0x48;
    for (i = 16; i < 18; i++) {
      MainSprite_LoadPose(&inv->icons[i], &inv->iconGfx, 0);
      inv->icons[i].flags |= SPRFLAG_HIDDEN;
      inv->icons[i].pos.x = pos.x;
      inv->icons[i].pos.y = pos.y;
    }
  }
}

// 立っている枠のスプライトだけ見せる
void LinkShopScreen_ShowWeaponIcons(LinkShopScreen* p) {
  s32 i;

  for (i = 0; i < 16; i++) {
    if (p->inv.weapons[i].id) {
      p->inv.icons[i].flags &= ~SPRFLAG_HIDDEN;
    }
  }
}

// 売れるかどうかで武器のアイコンのパレットを替えて隠し, 受け取った武器の2枚も隠す
void LinkShopScreen_RefreshWeaponIcons(LinkShopScreen* p) {
  LinkShopInventory* inv = &p->inv;
  s32 i;

  for (i = 0; i < 16; i++) {
    if (!IsWeaponSellable(i)) {
      p->inv.icons[i].plttID = 736;
      p->inv.icons[i].pltt = &gObjPlttData[736 * 16];
    } else {
      p->inv.icons[i].plttID = 735;
      p->inv.icons[i].pltt = &gObjPlttData[735 * 16];
    }
    inv->icons[i].flags |= SPRFLAG_HIDDEN;
  }
  for (i = 16; i < 18; i++) {
    p->inv.icons[i].pos.x = 0x30;
    p->inv.icons[i].pos.y = 0x48;
    p->inv.icons[i].flags |= SPRFLAG_HIDDEN;
  }
}

void LinkShopScreen_HideWeaponIcons(LinkShopScreen* p) {
  s32 i;

  for (i = 0; i < 18; i++) {
    p->inv.icons[i].flags |= SPRFLAG_HIDDEN;
  }
  p->sprites[27].flags |= SPRFLAG_HIDDEN;
}

void LinkShopScreen_RemoveWeaponIcons(LinkShopScreen* p) {
  s32 i;

  for (i = 0; i < (s32)ARRAY_COUNT(p->inv.icons); i++) {
    MainSprite_Remove(&p->inv.icons[i]);
  }
  MainSprite_Remove(&p->inv.iconSprite);
}

void LinkShopScreen_RemoveSprites(LinkShopScreen* p) {
  s32 i;

  for (i = 0; i < (s32)ARRAY_COUNT(p->sprites); i++) {
    MainSprite_Remove(&p->sprites[i]);
  }
}

void LinkShopScreen_HideMessages(LinkShopScreen* p) {
  MenuMessage_Hide(p->panelID[0]);
  MenuMessage_Hide(p->panelID[1]);
  MenuMessage_Hide(p->panelID[2]);
  MenuMessage_Hide(p->panelID[3]);
  if (LinkShopScreen_TestFlag(p, LSSFLAG_MARQUEE)) {
    Marquee_CloseGlobal();
    CLEAR_FLAGS(p->flags, LSSFLAG_MARQUEE);
  }
}

// カーソル位置の武器の名前と説明を出し, 損傷度アイコンを合わせる
void LinkShopScreen_ShowCursorWeapon(LinkShopScreen* p) {
  WeaponData* w = &p->inv.weapons[p->cursorSlot];

  WeaponData_ShowNameInPanel(p->panelID[2], (u8*)w, (s8*)p->statText);
  if (w->id != WEAPON_NONE) {
    s32 pose;

    FUN_08049f5c();
    Marquee_Clear();
    MainMenu_SetWeaponMarquee(w, p->weaponNames);
    pose = GetWeaponWearPose(w);
    MainSprite_Show(&p->inv.iconSprite);
    MainSprite_SetPose(&p->inv.iconSprite, &p->inv.iconGfx, pose, PLAYMODE_PAUSE);
  } else {
    Marquee_Clear();
    MainSprite_Hide(&p->inv.iconSprite);
  }
}

// BG の (x, y) にあたるタイルマップのエントリを返す
BgMapEntry* LinkShopScreen_GetBgMapEntry(s32 bg, u32 x, u32 y) {
  BgState* st = &gBgStates[bg];
  BgMapEntry* map = st->tilemap;

  return map + (x & 0x1F) + (y & 0x1F) * 32;
}

// value を divisor から順に10進の桁へ分解して BG3 の (x, y) から書き出す
// 残差は value / divisor / entry に割り当たるレジスタの入れ替わりだけ (28/28)
// Tier A-C 試済 (5番目の引数を足す, for 形, base を定数に), 未: 引数の受け方
NON_MATCH void LinkShopScreen_DrawNumber(s32 value, s32 divisor, u32 x, u32 y, s32 unused) {
#ifdef NONMATCHING_C
  s32 base = 3;
  BgMapEntry* entry = LinkShopScreen_GetBgMapEntry(base, x, y);

  while (divisor > 0) {
    s32 digit = Div(value, divisor);

    *entry = digit + base;
    entry++;
    value -= divisor * digit;
    divisor = Div(divisor, 10);
  }
#else
  INCFUNC("asm/func/LinkShopScreen_DrawNumber.inc");
#endif
}

// 指定BGのタイルマップの (x, y) から width × height を value で塗る
void LinkShopScreen_FillBgMap(u32 x, s32 y, s32 width, s32 height, s32 value, u32 bgIdx) {
  s32 i;

  for (i = 0; i < height; i++) {
    BgMapEntry* dst = LinkShopScreen_GetBgMapEntry(bgIdx, x, y + i);
    s32 j;

    for (j = 0; j < width; j++) {
      *dst = value;
      dst++;
    }
  }
}

// 十字キーの入力 keys でカーソルの移る先の枠を決めて pos をその位置にし, 枠の番号を返す
s32 LinkShopScreen_MoveCursor(LinkShopScreen* p, Vec3* pos, u32 keys) {
  bool32 fromOffer = FALSE;
  s32 next;

  if (keys & 1) {
    next = sLinkShopCursorMoves[p->cursorSlot].up;
    if (next == 16) {
      p->returnSlot = 0;
    }
  } else if (keys & 2) {
    next = sLinkShopCursorMoves[p->cursorSlot].down;
    if (next == 16) {
      p->returnSlot = 0;
    }
  } else if (keys & 4) {
    next = sLinkShopCursorMoves[p->cursorSlot].left;
    if (next == 16) {
      p->returnSlot = p->cursorSlot;
    }
    if (p->cursorSlot == 16) {
      fromOffer = TRUE;
    }
  } else if (keys & 8) {
    next = sLinkShopCursorMoves[p->cursorSlot].right;
    if (next == 16) {
      p->returnSlot = p->cursorSlot;
    }
    if (p->cursorSlot == 16) {
      fromOffer = TRUE;
    }
  } else {
    return p->cursorSlot;
  }
  if (next == 16) {
    pos->x = 0x30;
    pos->y = 0x48;
  } else if (next == 17) {
    pos->x = 0x38;
    pos->y = 0x68;
  } else {
    if (fromOffer && p->returnSlot != 0) {
      switch (p->returnSlot) {
        case 4:
        case 7: {
          if (next == 0) {
            next = 4;
          } else {
            next = 7;
          }
          break;
        }
        case 8:
        case 11: {
          if (next == 0) {
            next = 8;
          } else {
            next = 11;
          }
          break;
        }
      }
    }
    pos->x = (next & 3) * 24 + 0x90;
    pos->y = (next >> 2) * 24 + 0x20;
  }
  return next;
}

// 4桁の数字のスプライト sprites[0..3] を右側に並べて見せる
void LinkShopScreen_ShowDigitsRight(LinkShopScreen* p) {
  p->sprites[3].pos.x = 0x98;
  p->sprites[3].pos.y = 0x68;
  p->sprites[2].pos.x = 0xA0;
  p->sprites[2].pos.y = 0x68;
  p->sprites[1].pos.x = 0xA8;
  p->sprites[1].pos.y = 0x68;
  p->sprites[0].pos.x = 0xB0;
  p->sprites[0].pos.y = 0x68;
  p->sprites[0].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[1].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[2].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[3].flags &= ~SPRFLAG_HIDDEN;
  p->priceInput = 0;
}

// price を4桁の数字のスプライトに出し, 上の桁の 0 は隠す
// 残差は 0 を r7 に持って n の初期化と比較に使う点だけ (114/115)
// Tier A-C 試済 (桁ごとの変数, 桁を数える inline, 宣言順), 未: 最後の桁の shown >= 0 の書き方
NON_MATCH void LinkShopScreen_ShowPrice(LinkShopScreen* p) {
#ifdef NONMATCHING_C
  s32 v = p->price;
  s32 shown = 0;
  s32 n;

  n = 0;
  while (v > 999) {
    n++;
    v -= 1000;
  }
  if (n > 0 || shown > 0) {
    MainSprite_LoadPose(&p->sprites[3], &p->gfx0, n);
    shown++;
  } else {
    p->sprites[3].flags |= SPRFLAG_HIDDEN;
  }
  n = 0;
  while (v > 99) {
    n++;
    v -= 100;
  }
  if (n > 0 || shown > 0) {
    MainSprite_LoadPose(&p->sprites[2], &p->gfx0, n);
    shown++;
  } else {
    p->sprites[2].flags |= SPRFLAG_HIDDEN;
  }
  n = 0;
  while (v > 9) {
    n++;
    v -= 10;
  }
  if (n > 0 || shown > 0) {
    MainSprite_LoadPose(&p->sprites[1], &p->gfx0, n);
    shown++;
  } else {
    p->sprites[1].flags |= SPRFLAG_HIDDEN;
  }
  n = 0;
  while (v > 0) {
    n++;
    v--;
  }
  if (n > 0 || shown >= 0) {
    MainSprite_LoadPose(&p->sprites[0], &p->gfx0, n);
  } else {
    p->sprites[0].flags |= SPRFLAG_HIDDEN;
  }
#else
  INCFUNC("asm/func/LinkShopScreen_ShowPrice.inc");
#endif
}

void LinkShopScreen_ResetCursor(LinkShopScreen* p) {
  p->sprites[26].flags &= ~SPRFLAG_HIDDEN;
  p->sprites[26].pos.x = 0;
  p->sprites[26].pos.y = 0;
  MainSprite_SetAnim(&p->sprites[26], &p->gfx1, p->poseIdx[29], 1, 0);
  p->yesNoCursor = 0;
}

// 明滅用に OBJ パレットを pltt へ写し, sprites[16..19] にそれを使わせる
void LinkShopScreen_InitPltt(LinkShopScreen* p) {
  s32 i;

  for (i = 0; i < 4; i++) {
    rgb555* src = i == 3 ? &gObjPlttData[660 * 16] : &gObjPlttData[659 * 16];
    s32 j;

    for (j = 0; j < 16; j++) {
      p->pltt[i][j] = src[j];
    }
  }
  p->pltt[1][1] = p->pltt[1][9];
  p->pltt[1][2] = p->pltt[1][10];
  p->pltt[1][3] = p->pltt[1][11];
  p->sprites[18].pltt = p->pltt[0];
  p->sprites[19].pltt = p->pltt[0];
  p->sprites[16].pltt = p->pltt[2];
  p->sprites[17].pltt = p->pltt[2];
  p->plttTimer = 0;
}

// pltt[0] と pltt[2] の12色目を50フレーム周期で明滅させる
void LinkShopScreen_BlinkPltt(LinkShopScreen* p) {
  u16 c;

  if (p->plttTimer < 10) {
    c = 31;
  } else if (p->plttTimer < 18) {
    c = 27;
  } else if (p->plttTimer < 26) {
    c = 18;
  } else if (p->plttTimer < 34) {
    c = 10;
  } else if (p->plttTimer < 42) {
    c = 18;
  } else {
    c = 27;
  }
  if (++p->plttTimer >= 50) {
    p->plttTimer = 0;
  }
  p->pltt[0][12] = c;
  p->pltt[2][12] = c;
}

// 十字キーの入力を 1=上 2=下 4=左 8=右 のビットで返す, 押し続けると12フレームごとに繰り返す
s32 LinkShopScreen_ReadDpad(LinkShopScreen* p) {
  s32 keys = 0;

  if (gInput[0].pressed & DPAD_UP) {
    keys = 1;
  } else if (gInput[0].pressed & DPAD_DOWN) {
    keys = 2;
  } else if (gInput[0].pressed & DPAD_LEFT) {
    keys = 4;
  } else if (gInput[0].pressed & DPAD_RIGHT) {
    keys = 8;
  }
  if (gInput[0].down & DPAD_ANY) {
    if (p->keyRepeat >= 12) {
      if (gInput[0].down & DPAD_UP) {
        keys |= 1;
      } else if (gInput[0].down & DPAD_DOWN) {
        keys |= 2;
      }
      if (gInput[0].down & DPAD_LEFT) {
        keys |= 4;
      } else if (gInput[0].down & DPAD_RIGHT) {
        keys |= 8;
      }
      p->keyRepeat = 0;
    } else {
      p->keyRepeat++;
    }
  } else {
    p->keyRepeat = 0;
  }
  return keys;
}

// 取引の後につなぎ直せたときに呼ばれ, 親子が前と同じでセーブ枠を切り替えられたら保存できた状態へ, だめなら失敗の状態へ進む
void LinkShopScreen_OnCommitReconnected(LinkShopScreen* p, u32 linkId) {
  if (p->linkId == linkId && Save_SwitchSlot()) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateSaved, 0x18);
  } else {
    LinkShopScreen_SetState(p, LinkShopScreen_StateSaveFailed, 0x19);
  }
}

void LinkShopScreen_OnCommitReconnectFailed(LinkShopScreen* p) { LinkShopScreen_SetState(p, LinkShopScreen_StateSaveFailed, 0x19); }

// 保存の後につなぎ直せたときに呼ばれ, 親子が前と同じなら通信ショップの受け手を自分に戻して取引をやり直し, 違えば状態 0x1C へ進む
void LinkShopScreen_OnRestartReconnected(LinkShopScreen* p, u32 linkId) {
  if (p->linkId != linkId) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateLinkMismatch, 0x1C);
  } else {
    FUN_081e5290(p);
    LinkShopManager_SetOwner(p);
    LinkShopManager_SetCallbacks(LinkShopScreen_OnRecv, LinkShopScreen_EnableSensor, LinkShopScreen_OnSendDone);
    LinkShopScreen_ResetTrade(p);
  }
}

void LinkShopScreen_OnRestartReconnectFailed(LinkShopScreen* p, s32 handle, s32 canceled) { LinkShopScreen_SetState(p, LinkShopScreen_StateLinkMismatch, 0x1C); }

// param_2 を種類 10 の通信メッセージとして送り, 失敗したら LSSFLAG_SEND_FAILED を立てる
void LinkShopScreen_SendSignal(LinkShopScreen* p, s32 param_2) {
  s32 payload = param_2;

  CLEAR_FLAGS(p->flags, LSSFLAG_SENT);
  if (!LinkShopManager_Send(&payload, 10, gFrameCounter)) {
    SET_FLAGS(p->flags, LSSFLAG_SEND_FAILED);
  } else {
    CLEAR_FLAGS(p->flags, LSSFLAG_SEND_FAILED);
  }
}

// args を種類 kind の通信メッセージとして送り, 失敗したら LSSFLAG_SEND2_FAILED を立てる
void LinkShopScreen_SendMsg(LinkShopScreen* p, s32* args, s32 kind) {
  CLEAR_FLAGS(p->flags, LSSFLAG_SENT);
  if (!LinkShopManager_Send(args, kind, p->sendTag)) {
    SET_FLAGS(p->flags, LSSFLAG_SEND2_FAILED);
  } else {
    CLEAR_FLAGS(p->flags, LSSFLAG_SEND2_FAILED);
  }
}

// 画面と取引の状態を初めに戻して状態 2 からやり直す
void LinkShopScreen_ResetTrade(LinkShopScreen* p) {
  ClearBGTilemapBuffer(0);
  ClearBGTilemapBuffer(3);
  LinkShopScreen_PlaceDigitSprites(p);
  LinkShopScreen_ResetPanels(p);
  ClearMemory(&p->partner, sizeof(p->partner));
  LinkShopScreen_ResetDigitSprites(p);
  Video_SetBGLayer(3, p->tilemap0, 1);
  Video_GenerateBGMap(3, 0, 0, 0, 0);
  if (LinkShopManager_IsParent()) {
    FUN_081e2d98(p);
    LinkShopScreen_ShowParentSprites(p);
  } else {
    LinkShopScreen_ShowChildSprites(p);
  }
  p->menuCursor = 0;
  p->flags = 0;
  ClearMemory(&p->recvWeapon, 0x34);  // recvWeapon から priceDigits まで
  ClearMemory(&p->inv.weapons[16], sizeof(WeaponData));
  ClearMemory(&p->inv.weapons[17], sizeof(WeaponData));
  LinkShopScreen_InitSlotCursor(p);
  LinkShopScreen_ReloadWeapons(p);
  LinkShopScreen_SetState(p, LinkShopScreen_StateHandshake, 2);
}

// 画面を組み直して, 親機は項目選び (状態 0), 子機は相手の選択待ち (状態 1) に戻る
void LinkShopScreen_ReturnToMenu(LinkShopScreen* p) {
  ClearBGTilemapBuffer(0);
  ClearBGTilemapBuffer(3);
  LinkShopScreen_PlaceDigitSprites(p);
  LinkShopScreen_ResetPanels(p);
  LinkShopScreen_ShowNames(p);
  LinkShopScreen_ShowBanks(p);
  LinkShopScreen_ShowWeaponCounts(p);
  Video_SetBGLayer(3, p->tilemap0, 1);
  Video_GenerateBGMap(3, 0, 0, 0, 0);
  if (LinkShopManager_IsParent()) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateMenu, 0);
    FUN_081e2d98(p);
    LinkShopScreen_ShowParentSprites(p);
  } else {
    LinkShopScreen_SetState(p, LinkShopScreen_StateWaitPartnerChoice, 1);
    LinkShopScreen_ShowChildSprites(p);
  }
  p->menuCursor = 0;
  p->flags = 0x3E;
  ClearMemory(&p->recvWeapon, 0x34);  // recvWeapon から priceDigits まで
  ClearMemory(&p->inv.weapons[16], sizeof(WeaponData));
  ClearMemory(&p->inv.weapons[17], sizeof(WeaponData));
  LinkShopScreen_InitSlotCursor(p);
  LinkShopScreen_RefreshWeaponIcons(p);
  LinkShopScreen_InitPltt(p);
}

// 取引中止の後, 買い手は状態 4, 売り手は状態 3 の画面を組み直してやり直す
void LinkShopScreen_ReturnToTrade(LinkShopScreen* p) {
  ClearBGTilemapBuffer(0);
  ClearBGTilemapBuffer(3);
  LinkShopScreen_PlaceDigitSprites(p);
  LinkShopScreen_ResetPanels(p);
  if (LinkShopScreen_TestFlag(p, LSSFLAG_BUYER)) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateBuy, 4);
    MenuMessage_Hide(p->panelID[0]);
    MenuMessage_Hide(p->panelID[1]);
    FUN_0804a40c(p->panelID[0], 1, p->partner.name);
    FUN_0804a40c(p->panelID[1], 2, gStat->name);
    Video_SetBGLayer(3, p->tilemap0, 2);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    LinkShopScreen_InitSlotCursor(p);
    p->sprites[21].flags &= ~SPRFLAG_HIDDEN;
    p->keyRepeat = 0;
    p->returnSlot = 17;
    LinkShopScreen_ShowRegisteredMarks(p);
    LinkShopScreen_ShowWeaponIcons(p);
    p->inv.icons[17].flags |= SPRFLAG_HIDDEN;
    p->inv.icons[17].pos.x = 0x30;
    p->inv.icons[17].pos.y = 0x48;
    ClearMemory(&p->inv.weapons[17], sizeof(WeaponData));
    ClearMemory(&p->inv.weapons[16], sizeof(WeaponData));
    LinkShopScreen_DrawNumber(gStat->solarBank, 1000, 22, 1, 0);
    LinkShopScreen_DrawNumber(gStat->lv, 10, 21, 0, 0);
    MenuMessage_SetScript(p->panelID[0], p->script);
    MenuMessage_SetMessage(p->panelID[0], 0);
    MenuMessage_Start(p->panelID[0]);
    LinkShopScreen_ShowDigitsLeft(p);
    LinkShopScreen_ShowPriceInput(p, p->price);
    p->cursorSlot = 17;
    MenuMessage_SetScript(p->panelID[2], p->weaponNames);
    FUN_08049f5c();
    LinkShopScreen_SetFlag(p, LSSFLAG_MARQUEE);
    Marquee_Clear();
    Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 15));
    p->marqueeMsg = 15;
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->sprites[21].flags |= SPRFLAG_HIDDEN;
    p->sprites[18].flags &= ~SPRFLAG_HIDDEN;
    LinkShopScreen_InitPltt(p);
    p->flags = LSSFLAG_BUYER | LSSFLAG_GOT_WEAPON | LSSFLAG_BUY_SCREEN | LSSFLAG_GOT_COUNTS | LSSFLAG_GOT_BANK | LSSFLAG_GOT_NAME;
  } else {
    LinkShopScreen_SetState(p, LinkShopScreen_StateSell, 3);
    Marquee_Clear();
    Marquee_CloseGlobal();
    LinkShopScreen_ClearFlag(p, LSSFLAG_MARQUEE);
    MenuMessage_Hide(p->panelID[0]);
    MenuMessage_Hide(p->panelID[1]);
    Video_SetBGLayer(3, p->tilemap0, 3);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    LinkShopScreen_InitSlotCursor(p);
    p->sprites[21].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[27].flags &= ~SPRFLAG_HIDDEN;
    p->keyRepeat = 0;
    LinkShopScreen_ShowRegisteredMarks(p);
    LinkShopScreen_ShowWeaponIcons(p);
    p->inv.icons[17].flags &= ~SPRFLAG_HIDDEN;
    p->inv.icons[17].pos.x = 0x30;
    p->inv.icons[17].pos.y = 0x48;
    p->cursorSlot = 0;
    MenuMessage_SetScript(p->panelID[2], p->weaponNames);
    MenuMessage_Start(p->panelID[2]);
    LinkShopScreen_ShowCursorWeapon(p);
    p->marqueeMsg = p->cursorSlot;
    LinkShopScreen_DrawNumber(gStat->solarBank, 1000, 22, 1, 0);
    LinkShopScreen_DrawNumber(gStat->lv, 10, 21, 0, 0);
    MenuMessage_SetScript(p->panelID[0], p->script);
    MenuMessage_SetMessage(p->panelID[0], 0);
    MenuMessage_Start(p->panelID[0]);
    p->flags = LSSFLAG_SELLER | LSSFLAG_SELL_SCREEN | LSSFLAG_GOT_COUNTS | LSSFLAG_GOT_BANK | LSSFLAG_GOT_NAME;
  }
}

void FUN_081e5290(LinkShopScreen* p) {
  if (p->unk_1628 != 0) {
    VM_ExecByID(p->unk_1628, NULL);
  }
}

// 選んだ武器のアイコンを写した inv.icons[17] を (0x30, 0x48) へ12フレームで動かし, 状態 3 へ戻る
void LinkShopScreen_StateMoveWeaponIcon(LinkShopScreen* p) {
  MainSprite* sprite = &p->inv.icons[17];

  if (p->stateEntered) {
    FUN_0822f588(sprite, &p->inv.icons[p->selectedSlot], 13);
    sprite->flags &= ~SPRFLAG_HIDDEN;
    p->inv.icons[p->selectedSlot].plttID = 736;
    p->inv.icons[p->selectedSlot].pltt = &gObjPlttData[736 * 16];
    p->moveDest.x = 0x30;
    p->moveDest.y = 0x48;
    p->moveTimer = 0;
    PlaySound_082406e0(SE_SWAP_SLOT);
    p->stateEntered = FALSE;
  }
  LerpVec3(&p->inv.icons[17].pos, &p->inv.icons[17].pos, &p->moveDest, p->moveTimer, 5);
  if (p->moveTimer >= 12) {
    sprite->pos.x = 0x30;
    sprite->pos.y = 0x48;
    LinkShopScreen_SetState(p, LinkShopScreen_StateSell, 3);
    PlaySound_082406e0(SE_EQUIP);
  } else {
    MainSprite_AdvanceAnim(&p->sprites[21], &p->gfx1);
    p->moveTimer++;
  }
}

// 選んだ武器を inv.weapons[17] に写して種類 3, 4, 5 の3回に分けて送り, 送り終えたら相手の提示待ちへ進む, 合図 10 なら取引中止へ
void LinkShopScreen_StateSendWeapon(LinkShopScreen* p) {
  if (p->recvSignal == 10) {
    p->sprites[21].flags |= SPRFLAG_HIDDEN;
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->cancelReturn = 1;
    p->inv.icons[17].flags |= SPRFLAG_HIDDEN;
    LinkShopScreen_SetState(p, LinkShopScreen_StateCancel, 0x11);
  } else if (p->stateEntered) {
    MenuMessage_Hide(p->panelID[2]);
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->sprites[21].flags |= SPRFLAG_HIDDEN;
    p->sprites[27].flags |= SPRFLAG_HIDDEN;
    p->sendTag = gFrameCounter;
    p->inv.weapons[17] = p->inv.weapons[p->selectedSlot];
    LinkShopScreen_SendMsg(p, (s32*)&p->inv.weapons[17], 3);
    p->sendStep = 1;
    p->stateEntered = FALSE;
  } else {
    LinkShopScreen_UpdateMarquee(p);
    if (!LinkShopManager_IsBusy()) {
      switch (p->sendStep) {
        case 1: {
          if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND2_FAILED)) {
            LinkShopScreen_SendMsg(p, (s32*)&p->inv.weapons[17], 3);
          } else {
            LinkShopScreen_SendMsg(p, (s32*)&p->inv.weapons[17], 4);
            p->sendStep = 2;
          }
          break;
        }
        case 2: {
          if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND2_FAILED)) {
            LinkShopScreen_SendMsg(p, (s32*)&p->inv.weapons[17], 4);
          } else {
            LinkShopScreen_SendMsg(p, (s32*)&p->inv.weapons[17], 5);
            p->sendStep = 3;
          }
          break;
        }
        case 3: {
          if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND2_FAILED)) {
            LinkShopScreen_SendMsg(p, (s32*)&p->inv.weapons[17], 5);
          } else if (LinkShopScreen_TestFlag(p, LSSFLAG_SENT) && !LinkShopManager_IsBusy()) {
            LinkShopScreen_SetState(p, LinkShopScreen_StateWaitOffer, 10);
          }
          break;
        }
      }
    }
  }
}

// 合図 11 と値段 (種類 12) を送り, 送り終えたら相手の提示待ちへ進む, 合図 10 が届いたら取引中止へ
void LinkShopScreen_StateSendOffer(LinkShopScreen* p) {
  if (p->recvSignal == 10) {
    p->sprites[21].flags |= SPRFLAG_HIDDEN;
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->sprites[18].flags |= SPRFLAG_HIDDEN;
    p->inv.icons[17].flags |= SPRFLAG_HIDDEN;
    p->cancelReturn = 1;
    LinkShopScreen_SetState(p, LinkShopScreen_StateCancel, 0x11);
  } else if (p->stateEntered) {
    MenuMessage_Hide(p->panelID[2]);
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->sprites[21].flags |= SPRFLAG_HIDDEN;
    p->sprites[18].flags |= SPRFLAG_HIDDEN;
    p->sendTag = gFrameCounter;
    LinkShopScreen_SendMsg(p, NULL, 11);
    p->lastSignal = 11;
    p->sendStep = 1;
    p->stateEntered = FALSE;
  } else {
    LinkShopScreen_UpdateMarquee(p);
    if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND2_FAILED)) {
      LinkShopScreen_SendMsg(p, (s32*)&p->price, p->lastSignal);
    } else if (p->sendStep == 1) {
      LinkShopScreen_SendMsg(p, (s32*)&p->price, 12);
      p->lastSignal = 12;
      p->sendStep = 2;
    } else if (LinkShopScreen_TestFlag(p, LSSFLAG_SENT) && !LinkShopManager_IsBusy()) {
      LinkShopScreen_SetState(p, LinkShopScreen_StateWaitOffer, 10);
    }
  }
}

// 合図 4 を送り, 相手からも 4 が届いたら相手の提示を見る画面へ, 10 が届いたら取引中止へ進む
void LinkShopScreen_StateWaitOffer(LinkShopScreen* p) {
  if (p->stateEntered) {
    LinkShopScreen_SendSignal(p, 4);
    p->stateEntered = FALSE;
  }
  if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND_FAILED)) {
    LinkShopScreen_SendSignal(p, 4);
  } else if (p->recvSignal == 10) {
    p->cancelReturn = 1;
    LinkShopScreen_SetState(p, LinkShopScreen_StateCancel, 0x11);
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_SENT) && (p->recvSignal == 4 || LinkShopScreen_TestFlag(p, LSSFLAG_GOT_4)) && !LinkShopManager_IsBusy()) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateReviewOffer, 0xC);
  } else {
    LinkShopScreen_UpdateMarquee(p);
  }
}

// 相手が出した武器と値段を見せ, はい なら合図 3 で応じ, いいえ か B なら合図 9 で断る
void LinkShopScreen_StateReviewOffer(LinkShopScreen* p) {
  if (p->stateEntered) {
    Marquee_Clear();
    Marquee_RequestClose();
    CLEAR_FLAGS(p->flags, LSSFLAG_MARQUEE);
    LinkShopScreen_HideRegisteredMarks(p);
    LinkShopScreen_HideWeaponIcons(p);
    Video_FillBGRect(0, 0, 0, 30, 20, 0, 0, 0);
    LinkShopScreen_ShowDigitsRight(p);
    LinkShopScreen_ShowPrice(p);
    Video_SetBGLayer(3, p->tilemap0, 4);
    Video_GenerateBGMap(3, 0, 0, 0, 0);
    MenuMessage_SetRect(p->panelID[0], 13, 4, 10, 2);
    MenuMessage_SetScript(p->panelID[0], p->script);
    MenuMessage_SetMessage(p->panelID[0], 0);
    MenuMessage_Start(p->panelID[0]);
    MenuMessage_SetRect(p->panelID[1], 13, 10, 10, 2);
    MenuMessage_SetScript(p->panelID[1], p->script);
    MenuMessage_SetMessage(p->panelID[1], 1);
    MenuMessage_Start(p->panelID[1]);
    MenuMessage_SetRect(p->panelID[2], 8, 7, 28, 2);
    MenuMessage_SetScript(p->panelID[2], p->weaponNames);
    WeaponData_ShowNameInPanel(p->panelID[2], (u8*)&p->inv.weapons[17], (s8*)p->statText);
    MenuMessage_Start(p->panelID[2]);
    MainSprite_LoadPose(&p->inv.icons[17], &p->inv.iconGfx, p->inv.weapons[17].id);
    p->inv.icons[17].pos.x = 0x20;
    p->inv.icons[17].pos.y = 0x38;
    p->inv.icons[17].flags &= ~SPRFLAG_HIDDEN;
    MenuMessage_SetScript(p->panelID[3], p->script);
    MenuMessage_SetMessage(p->panelID[3], 11);
    MenuMessage_Start(p->panelID[3]);
    LinkShopScreen_ResetCursor(p);
    p->recvSignal = 0;
    p->timer = 0;
    p->stateEntered = FALSE;
  }
  MainSprite_AdvanceAnim(&p->sprites[26], &p->gfx1);
  if (p->timer < 30) {
    p->timer++;
  } else if (gInput[0].pressed & B_BUTTON) {
    LinkShopScreen_SendSignal(p, 9);
    p->lastSignal = 9;
    p->cancelReturn = 0;
    LinkShopScreen_SetState(p, LinkShopScreen_StateSendCancel, 0x10);
  } else {
    if (p->yesNoCursor == 0) {
      if (gInput[0].pressed & DPAD_RIGHT) {
        MainSprite_SetAnim(&p->sprites[26], &p->gfx1, p->poseIdx[30], 1, 0);
        p->yesNoCursor = 1;
        PlaySound_082406e0(SE_CURSOR_MOVE);
      } else if (gInput[0].pressed & A_BUTTON) {
        LinkShopScreen_SendSignal(p, 3);
        LinkShopScreen_SetState(p, LinkShopScreen_StateWaitAnswer, 0xD);
        p->sprites[26].flags |= SPRFLAG_HIDDEN;
        PlaySound_082406e0(SE_SELECT);
        return;
      }
    } else {
      if (gInput[0].pressed & DPAD_LEFT) {
        MainSprite_SetAnim(&p->sprites[26], &p->gfx1, p->poseIdx[29], 1, 0);
        p->yesNoCursor = 0;
        PlaySound_082406e0(SE_CURSOR_MOVE);
      } else if (gInput[0].pressed & A_BUTTON) {
        LinkShopScreen_SendSignal(p, 9);
        p->lastSignal = 9;
        p->cancelReturn = 0;
        p->sprites[26].flags |= SPRFLAG_HIDDEN;
        LinkShopScreen_SetState(p, LinkShopScreen_StateSendCancel, 0x10);
        return;
      }
    }
    if (p->recvSignal == 9) {
      p->cancelReturn = 0;
      LinkShopScreen_SetState(p, LinkShopScreen_StateCancel, 0x11);
      p->sprites[26].flags |= SPRFLAG_HIDDEN;
    }
  }
}

// 合図 3 を送り, 相手の返事が 3 なら取引成立へ, 9 なら取引中止へ進む
void LinkShopScreen_StateWaitAnswer(LinkShopScreen* p) {
  if (p->stateEntered) {
    p->sprites[26].flags |= SPRFLAG_HIDDEN;
    MenuMessage_Hide(p->panelID[3]);
    p->stateEntered = FALSE;
  }
  LinkShopScreen_UpdateMarquee(p);
  if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND_FAILED)) {
    LinkShopScreen_SendSignal(p, 3);
  } else if (!LinkShopManager_IsBusy() && LinkShopScreen_TestFlag(p, LSSFLAG_SENT)) {
    if (p->recvSignal == 3) {
      LinkShopScreen_SetState(p, LinkShopScreen_StateDone, 0xE);
    } else if (p->recvSignal == 9) {
      p->cancelReturn = 0;
      LinkShopScreen_SetState(p, LinkShopScreen_StateCancel, 0x11);
    }
  }
}

// カーソルとパネルを隠し, 合図を送り終えたら取引中止の画面へ進む
void LinkShopScreen_StateSendCancel(LinkShopScreen* p) {
  if (p->stateEntered) {
    p->sprites[26].flags |= SPRFLAG_HIDDEN;
    MenuMessage_Hide(p->panelID[3]);
    p->stateEntered = FALSE;
  }
  LinkShopScreen_UpdateMarquee(p);
  if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND_FAILED)) {
    LinkShopScreen_SendSignal(p, p->lastSignal);
  } else if (!LinkShopManager_IsBusy() && LinkShopScreen_TestFlag(p, LSSFLAG_SENT)) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateCancel, 0x11);
  }
}

// 取引成立の画面, 相手の名前と武器と値段を入れたメッセージを出し, 合図 7 を送り合ったらボタン待ちへ進む
void LinkShopScreen_StateDone(LinkShopScreen* p) {
  if (p->stateEntered) {
    Marquee_Clear();
    Marquee_RequestClose();
    LinkShopScreen_ClearFlag(p, LSSFLAG_MARQUEE);
    LinkShopScreen_HideRegisteredMarks(p);
    LinkShopScreen_HideWeaponIcons(p);
    LinkShopScreen_HideSprites(p);
    MenuMessage_Hide(p->panelID[0]);
    MenuMessage_Hide(p->panelID[1]);
    MenuMessage_Hide(p->panelID[2]);
    MenuMessage_Hide(p->panelID[3]);
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(3);
    Video_SetBGLayer(0, p->tilemap1, 4);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    MenuMessage_SetRect(p->panelID[3], 1, 6, 28, 6);
    MenuMessage_SetScript(p->panelID[3], p->script);
    LinkShopScreen_CopyWeaponName(p);
    WeaponData_FormatSuffix(&p->inv.weapons[17], (s8*)p->statText);
    FUN_0804a3e4(p->panelID[3], 0, p->price);
    FUN_0804a40c(p->panelID[3], 3, p->weaponName);
    FUN_0804a40c(p->panelID[3], 4, p->statText);
    FUN_0804a40c(p->panelID[3], 2, p->partner.name);
    MenuMessage_SetRect(p->panelID[2], 0, 15, 30, 2);
    MenuMessage_SetScript(p->panelID[2], p->script);
    MenuMessage_SetMessage(p->panelID[2], 18);
    MenuMessage_Start(p->panelID[2]);
    if (LinkShopScreen_TestFlag(p, LSSFLAG_SELLER)) {
      if (p->price != 0) {
        MenuMessage_SetMessage(p->panelID[3], 12);
      } else {
        MenuMessage_SetMessage(p->panelID[3], 23);
      }
    } else if (p->price != 0) {
      MenuMessage_SetMessage(p->panelID[3], 13);
    } else {
      MenuMessage_SetMessage(p->panelID[3], 24);
    }
    MenuMessage_Start(p->panelID[3]);
    LinkShopScreen_SendSignal(p, 7);
    PlaySound_082406e0(SE_GAIN_VALUABLE);
    p->stateEntered = FALSE;
  }
  if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND_FAILED)) {
    LinkShopScreen_SendSignal(p, 7);
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_SENT) && p->recvSignal == 7 && !LinkShopManager_IsBusy()) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateDoneWaitButton, 0xF);
  }
}

// 取引成立の画面で30フレーム待ち, ボタンが押されたら相手に合図 8 を送って返事を待つ
void LinkShopScreen_StateDoneWaitButton(LinkShopScreen* p) {
  if (p->stateEntered) {
    p->timer = 0;
    p->stateEntered = FALSE;
  }
  if (p->timer < 30) {
    p->timer++;
  } else if (gInput[0].pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON)) {
    LinkShopScreen_SendSignal(p, 8);
    MenuMessage_Hide(p->panelID[2]);
    LinkShopScreen_SetState(p, LinkShopScreen_StateDoneWaitAck, 0x16);
    PlaySound_082406e0(SE_SELECT);
  }
}

// 合図 8 が相手に届いて同じ合図が返ってくるまで待ち, そろったら状態 0x17 へ進む
void LinkShopScreen_StateDoneWaitAck(LinkShopScreen* p) {
  if (p->stateEntered) {
    p->marqueeMsg = 0;
    p->stateEntered = FALSE;
  }
  LinkShopScreen_UpdateMarquee(p);
  if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND_FAILED)) {
    LinkShopScreen_SendSignal(p, 8);
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_SENT) && p->recvSignal == 8 && !LinkShopManager_IsBusy()) {
    MenuMessage_Hide(p->panelID[3]);
    LinkShopScreen_SetState(p, LinkShopScreen_StateCommitTrade, 0x17);
  }
}

// 取引を確定する, 買い手は武器を受け取って値段を払い, 売り手は武器を渡して値段を受け取り, セーブして通信をつなぎ直す
// 残差は値段を足し引きした後に gStat を読み直す所と符号付きの差の置き場だけ (192/194)
// Tier A-C 試済 (分岐の向き, *(&gStat->x) 形, 回数を指すポインタ), 未: 9999 打ち止めのマクロ化
NON_MATCH void LinkShopScreen_StateCommitTrade(LinkShopScreen* p) {
#ifdef NONMATCHING_C
  if (p->stateEntered) {
    Marquee_Clear();
    Marquee_CloseGlobal();
    CLEAR_FLAGS(p->flags, LSSFLAG_MARQUEE);
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(3);
    Video_SetBGLayer(0, p->tilemap1, 3);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    MenuMessage_Hide(p->panelID[3]);
    MenuMessage_SetRect(p->panelID[3], 1, 7, 28, 6);
    MenuMessage_SetScript(p->panelID[3], p->unk_15f4);
    MenuMessage_SetMessage(p->panelID[3], 6);
    MenuMessage_Start(p->panelID[3]);
    LinkShopManager_StopLinkWatch();
    Sound_FadeOutBGM(1);
    p->timer = 0;
    p->stateEntered = FALSE;
  }
  if (p->timer == 59) {
    LinkShopManager_Kill();
    SET_FLAGS(p->flags, LSSFLAG_MANAGER_KILLED);
  }
  if (p->timer == 60) {
    s32 v;

    if (LinkShopScreen_TestFlag(p, LSSFLAG_BUYER)) {
      AddWeapon(&p->inv.weapons[17]);
      v = gStat->solarBank - p->price;
      if (v < 0) {
        v = 0;
      }
      gStat->solarBank = v;
      v = gStat->linkBuyCount + 1;
      if (v > 9999) {
        v = 9999;
      }
      gStat->linkBuyCount = v;
    } else {
      RemoveWeapon(p->selectedSlot);
      v = gStat->solarBank + p->price;
      if (v > 9999) {
        v = 9999;
      }
      gStat->solarBank = v;
      v = gStat->linkSellCount + 1;
      if (v > 9999) {
        v = 9999;
      }
      gStat->linkSellCount = v;
    }
    if (!Save_WriteExtraToNextSlot()) {
      LinkShopScreen_SetState(p, LinkShopScreen_StateSaveFailed, 0x19);
      return;
    }
    if (LinkConnect_Create(600, 0) == NULL) {
      LinkShopScreen_SetState(p, LinkShopScreen_StateSaveFailed, 0x19);
      return;
    }
    LinkConnect_SetCallbacks(p, LinkShopScreen_OnCommitReconnected, LinkShopScreen_OnCommitReconnectFailed);
  }
  p->timer++;
#else
  INCFUNC("asm/func/LinkShopScreen_StateCommitTrade.inc");
#endif
}

// セーブできたことを知らせ, 通信をつなぎ直して相手のセーブ枠を確かめに行く
void LinkShopScreen_StateSaved(LinkShopScreen* p) {
  if (p->stateEntered) {
    if (LinkShopScreen_TestFlag(p, LSSFLAG_MARQUEE)) {
      Marquee_Clear();
      Marquee_RequestClose();
      LinkShopScreen_ClearFlag(p, LSSFLAG_MARQUEE);
    }
    MenuMessage_SetScript(p->panelID[3], p->unk_15f4);
    MenuMessage_SetMessage(p->panelID[3], 7);
    PlaySound_082406e0(SE_SAVE_SUCCESS);
    p->timer = 0;
    p->stateEntered = FALSE;
  } else if (p->timer == 0) {
    if (LinkConnect_Create(400, 0) == NULL) {
      LinkShopScreen_OnRestartReconnectFailed(p, 0, 0);
    } else {
      LinkConnect_SetCallbacks(p, LinkShopScreen_OnRestartReconnected, LinkShopScreen_OnRestartReconnectFailed);
      p->timer++;
    }
  }
}

// セーブに失敗したことを知らせ, 60フレーム後にソフトリセットを許す
void LinkShopScreen_StateSaveFailed(LinkShopScreen* p) {
  if (p->stateEntered) {
    MenuMessage_SetScript(p->panelID[3], p->unk_15f4);
    MenuMessage_SetMessage(p->panelID[3], 5);
    p->timer = 0;
    p->stateEntered = FALSE;
    LinkShopManager_AllowSoftReset();
    PlaySound_082406e0(SE_NG);
  }
  if (p->timer < 60) {
    p->timer++;
  } else {
    SET_FLAGS(p->flags, LSSFLAG_RESETTABLE);
  }
}

// つなぎ直した相手と親子が食い違ったことを知らせ, 60フレーム後にソフトリセットを許す
void LinkShopScreen_StateLinkMismatch(LinkShopScreen* p) {
  if (p->stateEntered) {
    MenuMessage_SetScript(p->panelID[3], p->unk_15f4);
    MenuMessage_SetMessage(p->panelID[3], 2);
    MenuMessage_Start(p->panelID[3]);
    p->timer = 0;
    p->stateEntered = FALSE;
    LinkShopManager_AllowSoftReset();
  }
  if (p->timer < 60) {
    p->timer++;
  } else {
    SET_FLAGS(p->flags, LSSFLAG_RESETTABLE);
  }
}

// 画面を片付けて取引中止のメッセージを出し, 合図 5 を送り合ったらボタン待ちへ進む
void LinkShopScreen_StateCancel(LinkShopScreen* p) {
  if (p->stateEntered) {
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(3);
    Video_SetBGLayer(0, p->tilemap1, 4);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    if (LinkShopScreen_TestFlag(p, LSSFLAG_MARQUEE)) {
      Marquee_Clear();
      Marquee_RequestClose();
      CLEAR_FLAGS(p->flags, LSSFLAG_MARQUEE);
    }
    LinkShopScreen_HideRegisteredMarks(p);
    LinkShopScreen_HideWeaponIcons(p);
    LinkShopScreen_HideSprites(p);
    MenuMessage_Hide(p->panelID[0]);
    MenuMessage_Hide(p->panelID[1]);
    MenuMessage_Hide(p->panelID[2]);
    MenuMessage_Hide(p->panelID[3]);
    MenuMessage_SetRect(p->panelID[3], 1, 6, 28, 6);
    MenuMessage_SetScript(p->panelID[3], p->script);
    MenuMessage_SetMessage(p->panelID[3], 14);
    MenuMessage_Start(p->panelID[3]);
    MenuMessage_SetRect(p->panelID[2], 0, 15, 30, 2);
    MenuMessage_SetScript(p->panelID[2], p->script);
    MenuMessage_SetMessage(p->panelID[2], 18);
    MenuMessage_Start(p->panelID[2]);
    PlaySound_082406e0(SE_CANCEL);
    LinkShopScreen_SendSignal(p, 5);
    p->stateEntered = FALSE;
  }
  if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND_FAILED)) {
    LinkShopScreen_SendSignal(p, 5);
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_SENT) && p->recvSignal == 5 && !LinkShopManager_IsBusy()) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateCancelWaitButton, 0x12);
  }
}

// 取引中止の画面で30フレーム待ち, ボタンが押されたら相手に合図 6 を送って返事を待つ
void LinkShopScreen_StateCancelWaitButton(LinkShopScreen* p) {
  if (p->stateEntered) {
    p->timer = 0;
    p->stateEntered = FALSE;
  }
  if (p->timer < 30) {
    p->timer++;
  } else if (gInput[0].pressed & (A_BUTTON | B_BUTTON | SELECT_BUTTON | START_BUTTON | R_BUTTON | L_BUTTON)) {
    LinkShopScreen_SendSignal(p, 6);
    MenuMessage_Hide(p->panelID[2]);
    LinkShopScreen_SetState(p, LinkShopScreen_StateCancelWaitAck, 0x13);
    PlaySound_082406e0(SE_SELECT);
  }
}

// 合図 6 が相手に届いて同じ合図が返ってくるまで待ち, そろったら cancelReturn に応じて次へ進む
void LinkShopScreen_StateCancelWaitAck(LinkShopScreen* p) {
  if (p->stateEntered) {
    p->marqueeMsg = 0;
    p->stateEntered = FALSE;
  }
  LinkShopScreen_UpdateMarquee(p);
  if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND_FAILED)) {
    LinkShopScreen_SendSignal(p, 6);
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_SENT) && p->recvSignal == 6 && !LinkShopManager_IsBusy()) {
    switch (p->cancelReturn) {
      case 1: {
        LinkShopScreen_ReturnToMenu(p);
        break;
      }
      case 0: {
        LinkShopScreen_ReturnToTrade(p);
        break;
      }
    }
  }
}

// 相手の武器と合図 4 が届くのを待ち, 届いたら状態 4 か, 太陽バンクと priceInput を比べて状態 7 へ進む, 合図 10 なら取引中止へ
void LinkShopScreen_StateWaitPartnerWeapon(LinkShopScreen* p) {
  if (p->stateEntered) {
    MenuMessage_Hide(p->panelID[2]);
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->stateEntered = FALSE;
  }
  if (p->recvSignal == 10) {
    p->sprites[21].flags |= SPRFLAG_HIDDEN;
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->sprites[18].flags |= SPRFLAG_HIDDEN;
    p->inv.icons[17].flags |= SPRFLAG_HIDDEN;
    p->cancelReturn = 1;
    LinkShopScreen_SetState(p, LinkShopScreen_StateCancel, 0x11);
  } else {
    LinkShopScreen_UpdateMarquee(p);
    MainSprite_AdvanceAnim(&p->sprites[21], &p->gfx1);
    if (!LinkShopManager_IsBusy() && LinkShopScreen_TestFlag(p, LSSFLAG_GOT_WEAPON) && p->recvSignal == 4) {
      if (LinkShopScreen_TestFlag(p, LSSFLAG_EDITING)) {
        if (gStat->solarBank >= p->priceInput) {
          if (p->marqueeMsg == 16) {
            return;
          }
          Marquee_Clear();
          Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 16));
          p->marqueeMsg = 16;
        } else {
          if (p->marqueeMsg == 17) {
            return;
          }
          Marquee_Clear();
          Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 17));
          p->marqueeMsg = 17;
        }
        LinkShopScreen_SetState(p, LinkShopScreen_StateInputPrice, 7);
      } else {
        Marquee_Clear();
        if (p->cursorSlot != 17) {
          LinkShopScreen_ShowCursorWeapon(p);
          p->marqueeMsg = p->cursorSlot + 25;
          MenuMessage_Start(p->panelID[2]);
          if (p->inv.weapons[p->cursorSlot].id) {
            p->inv.iconSprite.flags &= ~SPRFLAG_HIDDEN;
          }
        }
        LinkShopScreen_SetState(p, LinkShopScreen_StateBuy, 4);
      }
    }
  }
}

// 相手の値段と合図 4 が届くのを待って状態 3 へ進む, 合図 10 なら取引中止へ
void LinkShopScreen_StateWaitPrice(LinkShopScreen* p) {
  if (p->stateEntered) {
    MenuMessage_Hide(p->panelID[2]);
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->stateEntered = FALSE;
  }
  if (p->recvSignal == 10) {
    p->sprites[21].flags |= SPRFLAG_HIDDEN;
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->cancelReturn = 1;
    p->inv.icons[17].flags |= SPRFLAG_HIDDEN;
    LinkShopScreen_SetState(p, LinkShopScreen_StateCancel, 0x11);
  } else {
    LinkShopScreen_UpdateMarquee(p);
    MainSprite_AdvanceAnim(&p->sprites[21], &p->gfx1);
    if (!LinkShopManager_IsBusy() && LinkShopScreen_TestFlag(p, LSSFLAG_GOT_PRICE) && p->recvSignal == 4) {
      Marquee_Clear();
      LinkShopScreen_ShowCursorWeapon(p);
      p->marqueeMsg = p->cursorSlot + 25;
      MenuMessage_Start(p->panelID[2]);
      LinkShopScreen_SetState(p, LinkShopScreen_StateSell, 3);
    }
  }
}

// 買い手の値段の入力, 上下で桁の数字を, 左右で桁を変え, A で太陽バンクの残高以内なら値段を決め, B で入力前に戻す
void LinkShopScreen_StateInputPrice(LinkShopScreen* p) {
  s32 keys;
  u32 prev;

  if (p->stateEntered) {
    if (!LinkShopScreen_TestFlag(p, LSSFLAG_EDITING)) {
      s32 v;
      s32 d;

      p->sprites[19].flags &= ~SPRFLAG_HIDDEN;
      p->sprites[19].pos.x = 24;
      p->sprites[19].pos.y = 0;
      p->digitCursor = 0;
      LinkShopScreen_ShowPriceInput(p, p->price);
      p->priceInput = p->price;
      p->keyRepeat = 0;
      LinkShopScreen_SetFlag(p, LSSFLAG_EDITING);
      v = p->price;
      d = 0;
      while (v > 999) {
        d++;
        v -= 1000;
      }
      p->priceDigits[3] = d;
      d = 0;
      while (v > 99) {
        d++;
        v -= 100;
      }
      p->priceDigits[2] = d;
      d = 0;
      while (v > 9) {
        d++;
        v -= 10;
      }
      p->priceDigits[1] = d;
      d = 0;
      while (v > 0) {
        d++;
        v -= 1;
      }
      p->priceDigits[0] = d;
    }
    p->stateEntered = FALSE;
  }
  if (p->recvSignal == 10) {
    p->sprites[21].flags |= SPRFLAG_HIDDEN;
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->sprites[18].flags |= SPRFLAG_HIDDEN;
    p->inv.icons[17].flags |= SPRFLAG_HIDDEN;
    p->cancelReturn = 1;
    LinkShopScreen_SetState(p, LinkShopScreen_StateCancel, 0x11);
    return;
  }
  if (LinkShopScreen_TestFlag(p, LSSFLAG_GOT_WEAPON_HEAD)) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateWaitPartnerWeapon, 0x15);
    LinkShopScreen_ClearFlag(p, LSSFLAG_GOT_WEAPON_HEAD);
    return;
  }
  keys = LinkShopScreen_ReadDpad(p);
  prev = p->digitCursor;
  if (keys & 1) {
    if (p->priceDigits[prev] >= p->digitMax[prev]) {
      p->priceDigits[prev] = 0;
    } else {
      p->priceDigits[prev]++;
    }
    p->priceInput = LinkShopScreen_ComposePrice(p);
    LinkShopScreen_ShowPriceInput(p, p->priceInput);
    PlaySound_082406e0(SE_CURSOR_MOVE);
  } else if (keys & 2) {
    if (p->priceDigits[prev] == 0) {
      p->priceDigits[prev] = p->digitMax[prev];
    } else {
      p->priceDigits[prev]--;
    }
    p->priceInput = LinkShopScreen_ComposePrice(p);
    LinkShopScreen_ShowPriceInput(p, p->priceInput);
    PlaySound_082406e0(SE_CURSOR_MOVE);
  } else if (keys & 4) {
    if (prev >= p->maxDigitCursor) {
      p->digitCursor = 0;
    } else {
      p->digitCursor = prev + 1;
    }
  } else if (keys & 8) {
    if (prev == 0) {
      p->digitCursor = 3;
    } else {
      p->digitCursor = prev - 1;
    }
  }
  if (p->digitCursor != prev) {
    p->sprites[19].pos.x = 24 - p->digitCursor * 8;
    p->sprites[19].pos.y = 0;
    LinkShopScreen_ShowPriceInput(p, p->priceInput);
    PlaySound_082406e0(SE_CURSOR_MOVE);
  }
  if ((gInput[0].pressed & A_BUTTON) || (gInput[0].pressed & START_BUTTON)) {
    if (gStat->solarBank >= p->priceInput) {
      LinkShopScreen_SetState(p, LinkShopScreen_StateBuy, 4);
      p->sprites[19].flags |= SPRFLAG_HIDDEN;
      p->price = p->priceInput;
      LinkShopScreen_ShowPriceInput(p, p->price);
      LinkShopScreen_ClearFlag(p, LSSFLAG_EDITING);
      PlaySound_082406e0(SE_SELECT);
      return;
    }
    PlaySound_082406e0(SE_NG);
  } else if (gInput[0].pressed & B_BUTTON) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateBuy, 4);
    p->sprites[19].flags |= SPRFLAG_HIDDEN;
    LinkShopScreen_ShowPriceInput(p, p->price);
    p->priceInput = p->price;
    LinkShopScreen_ClearFlag(p, LSSFLAG_EDITING);
    PlaySound_082406e0(SE_CANCEL);
    return;
  }
  LinkShopScreen_UpdateMarquee(p);
  LinkShopScreen_BlinkPltt(p);
}

// 売り手の画面, カーソルで出す武器を選び (A), START で送り, B で取引をやめる, 買い手が値段を決めたら値段待ちへ進む
void LinkShopScreen_StateSell(LinkShopScreen* p) {
  s32 cursor;
  s32 keys;

  if (p->stateEntered) {
    if (!LinkShopScreen_TestFlag(p, LSSFLAG_SELL_SCREEN)) {
      LinkShopScreen_HideSprites(p);
      Video_FillBGRect(0, 0, 0, 30, 20, 0, 0, 0);
      Video_SetBGLayer(3, p->tilemap0, 3);
      Video_GenerateBGMap(3, 0, 0, 0, 0);
      p->sprites[21].flags &= ~SPRFLAG_HIDDEN;
      LinkShopScreen_ShowRegisteredMarks(p);
      LinkShopScreen_ShowWeaponIcons(p);
      p->cursorSlot = 0;
      MenuMessage_SetScript(p->panelID[2], p->weaponNames);
      MenuMessage_Start(p->panelID[2]);
      LinkShopScreen_ShowCursorWeapon(p);
      LinkShopScreen_DrawNumber(gStat->solarBank > 9999 ? 9999 : gStat->solarBank, 1000, 22, 1, 0);
      LinkShopScreen_DrawNumber(gStat->lv > 99 ? 99 : gStat->lv, 10, 21, 0, 0);
      MenuMessage_SetScript(p->panelID[0], p->script);
      MenuMessage_SetMessage(p->panelID[0], 0);
      MenuMessage_Start(p->panelID[0]);
      p->selectedSlot = -1;
      p->keyRepeat = 0;
      LinkShopScreen_SetFlag(p, LSSFLAG_SELL_SCREEN);
    }
    if (p->selectedSlot >= 0) {
      p->sprites[20].flags &= ~SPRFLAG_HIDDEN;
    }
    p->marqueeMsg = 0;
    LinkShopScreen_UpdateMarquee(p);
    p->timer = 0;
    p->stateEntered = FALSE;
  }
  if (p->recvSignal == 10) {
    p->sprites[21].flags |= SPRFLAG_HIDDEN;
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->cancelReturn = 1;
    p->inv.icons[17].flags |= SPRFLAG_HIDDEN;
    LinkShopScreen_SetState(p, LinkShopScreen_StateCancel, 0x11);
    return;
  }
  if (LinkShopScreen_TestFlag(p, LSSFLAG_GOT_OFFER)) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateWaitPrice, 8);
    LinkShopScreen_ClearFlag(p, LSSFLAG_GOT_OFFER | LSSFLAG_GOT_PRICE);
    return;
  }
  LinkShopScreen_UpdateMarquee(p);
  MainSprite_AdvanceAnim(&p->sprites[21], &p->gfx1);
  if (p->timer > 30) {
    p->timer++;
    return;
  }
  cursor = p->cursorSlot;
  keys = LinkShopScreen_ReadDpad(p);
  if (keys & 1) {
    if ((cursor >> 2) == 0) {
      cursor = (cursor & 3) + 12;
    } else {
      cursor -= 4;
    }
    p->keyRepeat = 0;
  } else if (keys & 2) {
    if ((cursor >> 2) == 3) {
      cursor &= 3;
    } else {
      cursor += 4;
    }
    p->keyRepeat = 0;
  } else if (keys & 4) {
    if ((cursor & 3) == 0) {
      cursor = (cursor & 0xFC) + 3;
    } else {
      cursor--;
    }
    p->keyRepeat = 0;
  } else if (keys & 8) {
    if ((cursor & 3) == 3) {
      cursor &= 0xFC;
    } else {
      cursor++;
    }
    p->keyRepeat = 0;
  }
  if (cursor != p->cursorSlot) {
    p->sprites[21].pos.x = (cursor & 3) * 24 + 0x90;
    p->sprites[21].pos.y = (cursor >> 2) * 24 + 0x20;
    p->cursorSlot = cursor;
    PlaySound_082406e0(SE_CURSOR_MOVE);
    return;
  }
  if (gInput[0].pressed & A_BUTTON) {
    if (!LinkShopScreen_CanSelectCursorWeapon(p)) {
      PlaySound_082406e0(SE_NG);
      return;
    }
    if (p->selectedSlot >= 0) {
      p->inv.icons[p->selectedSlot].plttID = 735;
      p->inv.icons[p->selectedSlot].pltt = &gObjPlttData[735 * 16];
    }
    p->selectedSlot = p->cursorSlot;
    p->sprites[20].flags &= ~SPRFLAG_HIDDEN;
    p->sprites[27].pos.x = (cursor & 3) * 24 + 0x90;
    p->sprites[27].pos.y = (cursor >> 2) * 24 + 0x20;
    p->sprites[27].flags &= ~SPRFLAG_HIDDEN;
    LinkShopScreen_SetState(p, LinkShopScreen_StateMoveWeaponIcon, 6);
  } else if (gInput[0].pressed & B_BUTTON) {
    LinkShopScreen_SendSignal(p, 10);
    p->lastSignal = 10;
    p->sprites[21].flags |= SPRFLAG_HIDDEN;
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->inv.icons[17].flags |= SPRFLAG_HIDDEN;
    p->cancelReturn = 1;
    LinkShopScreen_SetState(p, LinkShopScreen_StateSendCancel, 0x10);
  } else if (gInput[0].pressed & START_BUTTON) {
    if (p->selectedSlot < 0) {
      PlaySound_082406e0(SE_NG);
      return;
    }
    p->sprites[20].flags |= SPRFLAG_HIDDEN;
    LinkShopScreen_FillBgMap(25, 16, 5, 1, 1, 3);
    LinkShopScreen_SetState(p, LinkShopScreen_StateSendWeapon, 9);
    PlaySound_082406e0(SE_SELECT);
  }
}

// 買い手の画面, カーソルで武器を見て回り, 値段の枠で A なら値段の入力, START で値段を送り, B で取引をやめる
void LinkShopScreen_StateBuy(LinkShopScreen* p) {
  Vec3 pos;
  s32 next;

  if (p->stateEntered) {
    if (!LinkShopScreen_TestFlag(p, LSSFLAG_BUY_SCREEN)) {
      LinkShopScreen_HideSprites(p);
      Video_FillBGRect(0, 0, 0, 30, 20, 0, 0, 0);
      Video_SetBGLayer(3, p->tilemap0, 2);
      Video_GenerateBGMap(3, 0, 0, 0, 0);
      p->sprites[21].flags &= ~SPRFLAG_HIDDEN;
      LinkShopScreen_ShowRegisteredMarks(p);
      LinkShopScreen_ShowWeaponIcons(p);
      LinkShopScreen_DrawNumber(gStat->solarBank, 1000, 22, 1, 0);
      LinkShopScreen_DrawNumber(gStat->lv, 10, 21, 0, 0);
      MenuMessage_SetScript(p->panelID[0], p->script);
      MenuMessage_SetMessage(p->panelID[0], 0);
      MenuMessage_Start(p->panelID[0]);
      LinkShopScreen_ShowPriceInput(p, p->price);
      FUN_081e36e8(p);
      LinkShopScreen_ResetPriceInput(p);
      LinkShopScreen_InitPltt(p);
      p->selectedSlot = -1;
      p->keyRepeat = 0;
      p->returnSlot = 0;
      p->recvSignal = -1;
      p->cursorSlot = 17;
      MenuMessage_SetScript(p->panelID[2], p->weaponNames);
      Marquee_Clear();
      Marquee_SetText(GetStringByID(VM_ParseStringRef(p->script) + 15));
      p->marqueeMsg = 15;
      p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
      p->sprites[21].flags |= SPRFLAG_HIDDEN;
      p->sprites[18].flags &= ~SPRFLAG_HIDDEN;
      LinkShopScreen_SetFlag(p, LSSFLAG_BUY_SCREEN);
    }
    p->sprites[20].flags &= ~SPRFLAG_HIDDEN;
    p->timer = 0;
    p->stateEntered = FALSE;
    p->marqueeMsg = 0;
    LinkShopScreen_UpdateMarquee(p);
  }
  if (p->recvSignal == 10) {
    p->sprites[21].flags |= SPRFLAG_HIDDEN;
    p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
    p->sprites[18].flags |= SPRFLAG_HIDDEN;
    p->inv.icons[17].flags |= SPRFLAG_HIDDEN;
    p->cancelReturn = 1;
    LinkShopScreen_SetState(p, LinkShopScreen_StateCancel, 0x11);
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_GOT_WEAPON_HEAD)) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateWaitPartnerWeapon, 0x15);
    LinkShopScreen_ClearFlag(p, LSSFLAG_GOT_WEAPON_HEAD);
  } else {
    LinkShopScreen_UpdateMarquee(p);
    MainSprite_AdvanceAnim(&p->sprites[21], &p->gfx1);
    LinkShopScreen_BlinkPltt(p);
    if (p->timer > 30) {
      p->timer++;
    } else {
      next = LinkShopScreen_MoveCursor(p, &pos, LinkShopScreen_ReadDpad(p));
      if (next != p->cursorSlot) {
        p->cursorSlot = next;
        if (p->cursorSlot == 17) {
          MenuMessage_Hide(p->panelID[2]);
          p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
          p->sprites[21].flags |= SPRFLAG_HIDDEN;
          p->sprites[18].flags &= ~SPRFLAG_HIDDEN;
        } else {
          MenuMessage_Start(p->panelID[2]);
          if (p->inv.weapons[p->cursorSlot].id) {
            p->inv.iconSprite.flags &= ~SPRFLAG_HIDDEN;
          }
          p->sprites[21].flags &= ~SPRFLAG_HIDDEN;
          p->sprites[18].flags |= SPRFLAG_HIDDEN;
          p->sprites[21].pos = pos;
          LinkShopScreen_UpdateMarquee(p);
        }
        PlaySound_082406e0(SE_CURSOR_MOVE);
      } else if (gInput[0].pressed & A_BUTTON) {
        if ((u8)next == 17) {
          LinkShopScreen_SetState(p, LinkShopScreen_StateInputPrice, 7);
          PlaySound_082406e0(SE_SELECT);
        }
      } else if (gInput[0].pressed & B_BUTTON) {
        LinkShopScreen_SendSignal(p, 10);
        p->lastSignal = 10;
        p->sprites[21].flags |= SPRFLAG_HIDDEN;
        p->inv.iconSprite.flags |= SPRFLAG_HIDDEN;
        p->inv.icons[17].flags |= SPRFLAG_HIDDEN;
        p->sprites[18].flags |= SPRFLAG_HIDDEN;
        p->cancelReturn = 1;
        LinkShopScreen_SetState(p, LinkShopScreen_StateSendCancel, 0x10);
      } else if (gInput[0].pressed & START_BUTTON) {
        p->sprites[20].flags |= SPRFLAG_HIDDEN;
        LinkShopScreen_FillBgMap(25, 16, 5, 1, 1, 3);
        LinkShopScreen_SetState(p, LinkShopScreen_StateSendOffer, 0xB);
        PlaySound_082406e0(SE_SELECT);
      }
    }
  }
}

// 画面を片付けて終わりのメッセージを出し, 合図 11 を送り合ったら終了状態へ進む
void LinkShopScreen_StateQuit(LinkShopScreen* p) {
  if (p->stateEntered) {
    Marquee_Clear();
    Marquee_CloseGlobal();
    CLEAR_FLAGS(p->flags, LSSFLAG_MARQUEE);
    LinkShopScreen_HideRegisteredMarks(p);
    LinkShopScreen_HideWeaponIcons(p);
    LinkShopScreen_HideSprites(p);
    MenuMessage_Hide(p->panelID[0]);
    MenuMessage_Hide(p->panelID[1]);
    MenuMessage_Hide(p->panelID[2]);
    MenuMessage_Hide(p->panelID[3]);
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(3);
    Video_SetBGLayer(0, p->tilemap1, 3);
    Video_GenerateBGMap(0, 0, 0, 0, 0);
    MenuMessage_SetRect(p->panelID[3], 1, 7, 28, 6);
    MenuMessage_SetScript(p->panelID[3], p->script);
    MenuMessage_SetMessage(p->panelID[3], 22);
    MenuMessage_Start(p->panelID[3]);
    LinkShopScreen_SendSignal(p, 11);
    Sound_FadeOutBGM(1);
    p->timer = 0;
    p->stateEntered = FALSE;
  }
  if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND_FAILED)) {
    LinkShopScreen_SendSignal(p, 11);
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_SENT) && p->recvSignal == 11 && !LinkShopManager_IsBusy()) {
    LinkShopManager_StopLinkWatch();
    LinkShopScreen_SetState(p, LinkShopScreen_StateExit, 0x1B);
  }
}

// 終了状態, 36フレーム目からフェードアウトし, 60フレームを過ぎて通信が落ち着いたら自分を消す
void LinkShopScreen_StateExit(LinkShopScreen* p) {
  if (p->stateEntered) {
    p->timer = 0;
    p->stateEntered = FALSE;
  }
  if (p->timer == 36) {
    StartBgObjPlttFade(3, 4, 4, 4, 4, 0xFFFF, 0);
  }
  if (p->timer > 60) {
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(1);
    ClearBGTilemapBuffer(2);
    ClearBGTilemapBuffer(3);
    if (!LinkShopManager_IsBusy()) {
      LinkShopScreen_EnableSensor(p);
      KillEntity(&p->e);
    }
  } else {
    p->timer++;
  }
}

// 選んだ項目を合図で送り, 相手から 13 が返ったら状態 3 か 4 へ進む, 11 なら抜ける
void LinkShopScreen_StateWaitChoiceAck(LinkShopScreen* p) {
  if (p->stateEntered) {
    p->timer = 0;
    LinkShopScreen_SendSignal(p, p->lastSignal);
    p->stateEntered = FALSE;
  }
  LinkShopScreen_UpdateMarquee(p);
  if (p->recvSignal == 11) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateQuit, 0x1A);
    PlaySound_082406e0(SE_CANCEL);
  } else {
    LinkShopScreen_BlinkPltt(p);
    if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND_FAILED)) {
      LinkShopScreen_SendSignal(p, p->lastSignal);
    } else if (p->recvSignal == 13 && LinkShopScreen_TestFlag(p, LSSFLAG_SENT) && !LinkShopManager_IsBusy()) {
      MenuMessage_Hide(p->panelID[0]);
      MenuMessage_Hide(p->panelID[1]);
      if (LinkShopScreen_TestFlag(p, LSSFLAG_SELLER)) {
        LinkShopScreen_SetState(p, LinkShopScreen_StateSell, 3);
      } else {
        LinkShopScreen_SetState(p, LinkShopScreen_StateBuy, 4);
      }
      PlaySound_082406e0(SE_SELECT);
    }
  }
}

// 相手の選んだ項目に合図 13 で応え, 届いたら 0 なら状態 4, 1 なら状態 3 へ進む
void LinkShopScreen_StateAckChoice(LinkShopScreen* p) {
  if (p->stateEntered) {
    p->timer = 0;
    LinkShopScreen_SendSignal(p, p->lastSignal);
    p->stateEntered = FALSE;
  }
  LinkShopScreen_UpdateMarquee(p);
  if (p->recvSignal == 11) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateQuit, 0x1A);
    PlaySound_082406e0(SE_CANCEL);
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND_FAILED)) {
    LinkShopScreen_SendSignal(p, p->lastSignal);
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_SENT) && !LinkShopManager_IsBusy()) {
    if (p->partnerChoice == 0) {
      LinkShopScreen_SetState(p, LinkShopScreen_StateBuy, 4);
      Marquee_Clear();
      Marquee_RequestClose();
      LinkShopScreen_ClearFlag(p, LSSFLAG_MARQUEE);
      MenuMessage_Hide(p->panelID[0]);
      MenuMessage_Hide(p->panelID[1]);
      FUN_0804a40c(p->panelID[0], 1, p->partner.name);
      FUN_0804a40c(p->panelID[1], 2, gStat->name);
      LinkShopScreen_SetFlag(p, LSSFLAG_BUYER);
      PlaySound_082406e0(SE_SELECT);
    } else if (p->partnerChoice == 1) {
      LinkShopScreen_SetState(p, LinkShopScreen_StateSell, 3);
      Marquee_Clear();
      Marquee_RequestClose();
      LinkShopScreen_ClearFlag(p, LSSFLAG_MARQUEE);
      MenuMessage_Hide(p->panelID[0]);
      MenuMessage_Hide(p->panelID[1]);
      LinkShopScreen_SetFlag(p, LSSFLAG_SELLER);
      PlaySound_082406e0(SE_SELECT);
    }
  }
}

// 親機の項目選び, 左右で「売る」と「買う」を切り替え, A で決めて合図を送り, B で抜ける
void LinkShopScreen_StateMenu(LinkShopScreen* p) {
  if (p->stateEntered) {
    p->timer = 0;
    p->stateEntered = FALSE;
  }
  LinkShopScreen_ShowBanks(p);
  LinkShopScreen_UpdateMarquee(p);
  LinkShopScreen_BlinkPltt(p);
  if (p->timer < 30) {
    p->timer++;
    if (p->recvSignal == 11) {
      LinkShopScreen_SetState(p, LinkShopScreen_StateQuit, 0x1A);
      PlaySound_082406e0(SE_CANCEL);
    }
  } else if ((gInput[0].pressed & B_BUTTON) || p->recvSignal == 11) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateQuit, 0x1A);
    PlaySound_082406e0(SE_CANCEL);
  } else if (p->menuCursor == 0) {
    if (gInput[0].pressed & (DPAD_LEFT | DPAD_RIGHT)) {
      p->sprites[16].flags |= SPRFLAG_HIDDEN;
      p->sprites[17].flags &= ~SPRFLAG_HIDDEN;
      p->menuCursor = 1;
      PlaySound_082406e0(SE_CURSOR_MOVE);
    } else if (gInput[0].pressed & A_BUTTON) {
      if (p->partner.freeSlots - p->partner.sellable > 0 && CountSellableWeapons() > 0) {
        Marquee_Clear();
        p->lastSignal = 0;
        SET_FLAGS(p->flags, LSSFLAG_SELLER);
        LinkShopScreen_SetState(p, LinkShopScreen_StateWaitChoiceAck, 5);
      } else {
        PlaySound_082406e0(SE_NG);
      }
    }
  } else {
    if (gInput[0].pressed & (DPAD_LEFT | DPAD_RIGHT)) {
      p->sprites[16].flags &= ~SPRFLAG_HIDDEN;
      p->sprites[17].flags |= SPRFLAG_HIDDEN;
      p->menuCursor = 0;
      PlaySound_082406e0(SE_CURSOR_MOVE);
    } else if (gInput[0].pressed & A_BUTTON) {
      if (CountSellableOrEmptySlots() - CountSellableWeapons() <= 0 || p->partner.sellable == 0) {
        PlaySound_082406e0(SE_NG);
      } else {
        Marquee_Clear();
        FUN_0804a40c(p->panelID[0], 1, p->partner.name);
        FUN_0804a40c(p->panelID[1], 2, gStat->name);
        p->lastSignal = 1;
        SET_FLAGS(p->flags, LSSFLAG_BUYER);
        LinkShopScreen_SetState(p, LinkShopScreen_StateWaitChoiceAck, 5);
      }
    }
  }
}

// 相手が項目を選ぶのを待つ, 0 か 1 が届いたら合図 13 で応え, 11 が届くか B で抜ける
void LinkShopScreen_StateWaitPartnerChoice(LinkShopScreen* p) {
  if (p->stateEntered) {
    Sound_FadeOutBGM(1);
    p->timer = 0;
    p->stateEntered = FALSE;
  }
  LinkShopScreen_UpdateMarquee(p);
  if (p->timer < 30) {
    p->timer++;
    if (p->recvSignal == 11) {
      LinkShopScreen_SetState(p, LinkShopScreen_StateQuit, 0x1A);
      PlaySound_082406e0(SE_CANCEL);
    }
  } else if ((gInput[0].pressed & B_BUTTON) || p->recvSignal == 11) {
    LinkShopScreen_SetState(p, LinkShopScreen_StateQuit, 0x1A);
    PlaySound_082406e0(SE_CANCEL);
  } else if (p->recvSignal == 0 || p->recvSignal == 1) {
    p->partnerChoice = p->recvSignal;
    Marquee_Clear();
    p->lastSignal = 13;
    LinkShopScreen_SetState(p, LinkShopScreen_StateAckChoice, 0x1D);
  }
}

// 通信の準備ができるまで待ち, 親子それぞれの画面を組んで状態 2 へ進む
void LinkShopScreen_StateWaitReady(LinkShopScreen* p) {
  if (p->stateEntered) {
    p->stateEntered = FALSE;
  }
  if (LinkShopManager_IsReady()) {
    if (LinkShopManager_IsParent()) {
      LinkShopScreen_ShowParentSprites(p);
    } else {
      LinkShopScreen_ShowChildSprites(p);
    }
    LinkShopScreen_SetState(p, LinkShopScreen_StateHandshake, 2);
    LinkShopScreen_SetupBG(p);
  }
}

// つないだ直後のやりとり, 名前と太陽バンクの残高と武器の数を送り合って画面に出し, 合図 12 がそろったら親機は項目選び, 子機は選択待ちへ進む
void LinkShopScreen_StateHandshake(LinkShopScreen* p) {
  if (p->stateEntered) {
    LinkShopScreen_PlaceDigitSprites(p);
    LinkShopScreen_SendMsg(p, NULL, 6);
    p->lastSignal = 6;
    CLEAR_FLAGS(p->flags, LSSFLAG_GOT_SIGNAL);
    p->recvSignal = -1;
    p->handshakeTimer = 0;
    if (LinkShopManager_IsParent() && !sound_08240960(BGM_LINK_SELECT)) {
      sound_08240264(BGM_LINK_SELECT);
    }
    LinkShopScreen_InitPltt(p);
    p->stateEntered = FALSE;
  }
  LinkShopScreen_UpdateMarquee(p);
  LinkShopScreen_BlinkPltt(p);
  if (LinkShopScreen_TestFlag(p, LSSFLAG_GOT_NAME)) {
    if (!LinkShopScreen_TestFlag(p, LSSFLAG_NAME_SHOWN)) {
      LinkShopScreen_ShowNames(p);
      LinkShopScreen_SetFlag(p, LSSFLAG_NAME_SHOWN);
      LinkShopScreen_SendMsg(p, NULL, 7);
      p->lastSignal = 7;
      p->handshakeTimer = 0;
      return;
    }
  } else if (++p->handshakeTimer >= 120) {
    LinkShopManager_Abort();
    LinkShopScreen_HideMessages(p);
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(3);
    KillEntity(&p->e);
    return;
  }
  if (LinkShopScreen_TestFlag(p, LSSFLAG_GOT_BANK) && !LinkShopScreen_TestFlag(p, LSSFLAG_BANK_SHOWN)) {
    LinkShopScreen_ShowBanks(p);
    LinkShopScreen_SetFlag(p, LSSFLAG_BANK_SHOWN);
    LinkShopScreen_SendMsg(p, NULL, 8);
    p->lastSignal = 8;
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_GOT_COUNTS) && !LinkShopScreen_TestFlag(p, LSSFLAG_COUNTS_SHOWN)) {
    LinkShopScreen_ShowWeaponCounts(p);
    LinkShopScreen_SetFlag(p, LSSFLAG_COUNTS_SHOWN);
    LinkShopScreen_SendSignal(p, 12);
    p->lastSignal = 12;
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND_FAILED)) {
    LinkShopScreen_SendSignal(p, p->lastSignal);
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_SEND2_FAILED)) {
    LinkShopScreen_SendMsg(p, NULL, p->lastSignal);
  } else if (LinkShopScreen_TestFlag(p, LSSFLAG_NAME_SHOWN) && LinkShopScreen_TestFlag(p, LSSFLAG_BANK_SHOWN) && LinkShopScreen_TestFlag(p, LSSFLAG_COUNTS_SHOWN) && p->recvSignal == 12 && LinkShopScreen_TestFlag(p, LSSFLAG_SENT) && !LinkShopManager_IsBusy()) {
    if (LinkShopManager_IsParent()) {
      LinkShopScreen_SetState(p, LinkShopScreen_StateMenu, 0);
      FUN_081e2d98(p);
      p->linkId = 0;
    } else {
      LinkShopScreen_SetState(p, LinkShopScreen_StateWaitPartnerChoice, 1);
      FUN_081e2dd8(p);
      p->linkId = 1;
    }
  }
}

s32 LinkShopScreen_Update(LinkShopScreen* p) {
  if (!LinkShopScreen_TestFlag(p, LSSFLAG_RESETTABLE)) {
    gSoftResetInhibit = TRUE;
  }
  if (LinkShopManager_IsFinished() && !LinkShopScreen_TestFlag(p, LSSFLAG_MANAGER_KILLED)) {
    LinkShopScreen_HideMessages(p);
    KillEntity(&p->e);
    return -1;
  }
  if (p->updateCallback != NULL) {
    p->updateCallback(p);
  }
  return 1;
}

s32 LinkShopScreen_Destroy(LinkShopScreen* p) {
  bool8 finished;

  LinkShopScreen_HideMessages(p);
  LinkShopScreen_RemoveSprites(p);
  LinkShopScreen_RemoveWeaponIcons(p);
  finished = LinkShopManager_IsFinished();
  if (finished == 0) {
    ClearBGTilemapBuffer(0);
    ClearBGTilemapBuffer(3);
    Taiyo_Enable();
    gRtcReadInhibit = 0;
    if (p->exitScriptID != 0) {
      VM_ExecByID(p->exitScriptID, NULL);
    }
  }
  return 1;
}

s32 LinkShopScreen_Init(LinkShopScreen* p) {
  LinkShopScreen_InitPoseIdx(p);
  LinkShopScreen_CreateSprites(p);
  LinkShopScreen_PlaceDigitSprites(p);
  LinkShopScreen_InitSlotCursor(p);
  LinkShopScreen_InitRegisteredMarks(p);
  LinkShopScreen_CreateWeaponIcons(p);
  p->menuCursor = 0;
  p->flags = 0;
  p->marqueeMsg = 0xFF;
  LinkShopScreen_ReadScriptArgs(p);
  p->unk_1628 = VM_GetNamedArgValue('l', 0);
  p->exitScriptID = VM_GetNamedArgValue('e', 0);
  LinkShopManager_SetOwner(p);
  LinkShopManager_SetCallbacks(LinkShopScreen_OnRecv, LinkShopScreen_EnableSensor, LinkShopScreen_OnSendDone);
  LinkShopScreen_CreatePanels(p);
  LinkShopScreen_HideSprites(p);
  LinkShopScreen_SetState(p, LinkShopScreen_StateWaitReady, 0x14);
  return 1;
}

// 0x8B8E, HashName("武器交換画面")
LinkShopScreen* LinkShopScreen_Create(void) {
  LinkShopScreen* p = CreateEntity(ENTITY_UNK_11, sizeof(LinkShopScreen));

  if (p != NULL) {
    SetEntityRoutine(p, LinkShopScreen_Update, LinkShopScreen_Destroy);
    if (LinkShopScreen_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
