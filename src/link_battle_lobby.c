#include "entity.h"
#include "global.h"
#include "sprite.h"
#include "tilemap.h"

// 通信の参加者一覧画面,4人分の枠に UI_LINK のアイコンと DJANGO_SABATA の立ち絵を並べ、gEntity9A9F の進行状況を表示する

typedef struct {
  u8 status;    // 0x0, gEntity9A9F->unk_68[i] の写し,2 未満なら未参加で立ち絵は出ない
  u8 unk_1[3];  // 0x1, 読み手も書き手も見つかっていない
} LinkBattleLobbySlot;
static_assert(sizeof(LinkBattleLobbySlot) == 4);

typedef struct LinkBattleLobby {
  Entity e;                        // 0x000, ENTITY_UNK_11
  TilemapHeader* tilemap;          // 0x018, FUN_081db9f4 が GetFile(DIR_TILE_MAP, 0xCD91) を入れ、Video_SetupBGLayout / FUN_0822c398 に渡す
  rgb555* bgPltt;                  // 0x01C, FUN_081db9f4 が GetFile(DIR_BGPLTT, 0x26BB) + 0x14 を入れ、gBgPlttBuffer へ 256色転送する
  MainSprite sprites[8];           // 0x020, FUN_081dbd74 が 0..3 に立ち絵を、FUN_081dbc60 が 4..7 にアイコンを登録する
  MainSpriteGfx uiGfx;             // 0x320, sprites[4..7] 用,FUN_081dbc60 が uiSpriteFile から開く
  MainSpriteGfx charGfx;           // 0x340, sprites[0..3] 用,FUN_081dbd74 が charSpriteFile から開く
  u16 animID[8];                   // 0x360, FUN_081dbc14 が 4,4,4,4,0x3A,0x3B,0x3C,0x3D を入れ、FUN_081dbea0 が状態に応じて差し替える
  s16 shownAnimID[8];              // 0x370, 表示済みの animID,初期値 -1,違うときだけ FUN_081dbea0 が貼り直す
  MainSpriteFile* uiSpriteFile;    // 0x380, SPRITE_UI_LINK
  MainSpriteFile* charSpriteFile;  // 0x384, SPRITE_DJANGO_SABATA
  rgb555 pltt[16];                 // 0x388, FUN_081dba54 が bgPltt+0x40 から複写,FUN_081dba78 が点滅させて gBgPlttBuffer のバンク2へ送る
  u16 blinkTimer;                  // 0x3A8, FUN_081dba78 が 0..0x31 で回し、選択中の枠の色を決める
  u8 unk_3aa[2];                   // 0x3AA, 読み手も書き手も見つかっていない
  LinkBattleLobbySlot slots[4];    // 0x3AC, 4人分,FUN_081dc38c が毎フレーム gEntity9A9F から埋める
  EntityFunc fn;                   // 0x3BC, LinkBattleLobby_Update が呼ぶ,Init は FUN_081dc38c、キャンセルすると FUN_081dc350
  u8* scriptPc;                    // 0x3C0, '.s' の後の FUN_0823d340(), FUN_081dc100 が VM_ParseStringRef に渡す
  u8 unk_3c4[4];                   // 0x3C4, 読み手も書き手も見つかっていない
  s32 playerIdx;                   // 0x3C8, FUN_081dc38c が FUN_0823812c() を入れる,負なら通信していない
  u32 recordCount;                 // 0x3CC, FUN_081dc38c が gEntity9A9F->recordCount を入れる,セッションが無ければ -1
  u8 unk_3d0;                      // 0x3D0, Init が 0、B でキャンセルすると 1,読む箇所なし
  s8 shownStringIdx;               // 0x3D1, 表示済みの文字列番号,同じなら FUN_081dc100 は引き直さない
  u8 shownRecordCount;             // 0x3D2, recordCount の下位バイトの控え,FUN_081dc100 が変化を見る
  u8 unk_3d3;                      // 0x3D3, 読み手も書き手も見つかっていない
  bool8 needsInit;                 // 0x3D4, Init が 1 を入れ、FUN_081dc38c / FUN_081dc350 が初回だけの処理をして 0 に戻す
  u8 unk_3d5;                      // 0x3D5, 読み手も書き手も見つかっていない
  u16 timer;                       // 0x3D6, FUN_081dc38c は 0x3C 未満の間 入力を受け付けない,FUN_081dc350 は 10 で FUN_081dc2e0 を呼ぶ
  u16 unk_3d8;                     // 0x3D8, FUN_081dc32c が Script_ExecById に渡す,書き手が見つかっていない
  u16 exitScriptID;                // 0x3DA, '.e=0', FUN_081dc2e0 がこれを実行して自分を消す
} LinkBattleLobby;
static_assert(sizeof(LinkBattleLobby) == 988);

extern LinkBattleLobby* gLinkBattleLobby;  // 0x030001A8

INCASM("asm/link_battle_lobby.inc");
