#include "bg_pltt.h"
#include "boss.h"
#include "crossover.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "input.h"
#include "menu.h"
#include "player.h"
#include "random.h"
#include "save.h"
#include "sound.h"
#include "sprite_main.h"
#include "text.h"
#include "video.h"
#include "vm.h"

// 通信で送受信する1件, data の中身は kind で決まる
typedef struct {
  u8 unk_00;     // 0x00
  u8 kind;       // 0x01, 0: 体力の割合, 1: 準備完了, 2: オジャマバットとブロッキング, 3: オジャマバットの演出終了, 4: ラウンドの決着, 5: 勝敗
  u8 unk_02[2];  // 0x02
  union {
    u32 word;
    u16 half[2];
  } data;      // 0x04
  u32 unk_08;  // 0x08
} CrossoverBattleMsg;
static_assert(sizeof(CrossoverBattleMsg) == 12);

struct CrossoverMC;

// エグゼ5 とのクロスオーバーバトルの進行役, 通信の同期, ラウンド, オジャマバット, 勝敗判定, クロスオーバーポイントの加算とセーブ
typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_2
  u32 unk_18;                    // 0x018, _Init が 0 を入れる
  u16 roundTimer;                // 0x01C, ラウンドの残りフレーム数, 720 から毎フレーム減る
  u16 round;                     // 0x01E, 今のラウンド, 99 で止まる, 11 以上は MAX MODE
  u32 linkFlags;                 // 0x020, 種別 n の送信済みが 1 << (2n), 受信済みが 1 << (2n + 1)
  u32 stateTimer;                // 0x024, state に入ってからのフレーム数
  u8 state;                      // 0x028, sCrossoverBattleStateFuncs の添字
  bool8 stateBegun;              // 0x029, 立っていると次の更新で state の初期化をする
  bool8 sendPending;             // 0x02A, 送れなかった sendMsg が残っている
  bool8 sent;                    // 0x02B, CrossoverBattle_OnSent が立てる
  bool8 ojamaAnimActive;         // 0x02C, オジャマバットの演出が終わるのを待って種別 3 を送る
  bool8 playerDead;              // 0x02D, ジャンゴが倒れた
  bool8 bossDefeated;            // 0x02E, シェードマンを倒した
  u8 judgeResult;                // 0x02F, 0: 勝ち, 1: 負け, 2: 引き分け
  u8 unk_30;                     // 0x030, FUN_08050d40 が立っていれば 0 に落として 1 を返す
  u8 startDelay;                 // 0x031, START を押してからインターバル画面を抜けるまでのフレーム数
  u8 blocksLeft;                 // 0x032, ブロッキングの残り回数, 初期値 1
  bool8 screenDone;              // 0x033, オジャマバットの画面が終わった
  bool8 resultClosed;            // 0x034, 結果画面が閉じた
  u8 retryCount;                 // 0x035, セーブに失敗してやり直した回数
  bool8 saveResult;              // 0x036, Save_WriteSystemData の戻り値
  bool8 fighting;                // 0x037, StateFight の間 1
  u8 incomingOjama[4];           // 0x038, 次のラウンドで自分が受けるオジャマバットの数
  CrossoverBattleSide sides[2];  // 0x03C, [0] が自分, [1] が相手
  CrossoverBattleMsg sendMsg;    // 0x054, 送信バッファ
  struct CrossoverMC* mc;        // 0x060
  void* unk_64;                  // 0x064, Entity08052ffc
  u32 weaponCount;               // 0x068, weaponIDs に積んだ '.w' の件数
  u32 magicCount;                // 0x06C, magicIDs に積んだ '.m' の件数
  u32 weaponMask;                // 0x070, 対戦用の武器を入れた武器スロットのビット
  u32 magicMask;                 // 0x074, magicIDs の埋まっている添字のビット
  u16 weaponIDs[16];             // 0x078, '.w'
  u16 magicIDs[16];              // 0x098, '.m' を乱数で選んだ添字に置いたもの
  u8* script;                    // 0x0B8, '.s'
  s32 windowID;                  // 0x0BC
  u32 exitRequest;               // 0x0C0, StateExit が立て, 次の _Update で終わる
  u32 exitScript;                // 0x0C4, '.e', 終わるときに実行する
  s32 earnedPoint;               // 0x0C8, この対戦で得たクロスオーバーポイント
  MainSpriteGfx iconGfx;         // 0x0CC, SPRITE_INVENTORY_ICONS
  MainSprite sprites[2];         // 0x0EC, 相手のロックマンとシェードマンの体力アイコン
  u16 unk_1ac;                   // 0x1AC, '.M=11'
  u16 pointTable[4];             // 0x1AE, '.p', 得点, [0] シェードマン撃破, [1] 相手の死亡, [2] オジャマバット1匹, [3] ブロッキング成功
  u8 unk_1b6[2];                 // 0x1B6
  u32 startPressed;              // 0x1B8, インターバル画面で START を押した
} CrossoverBattle;
static_assert(sizeof(CrossoverBattle) == 444);

IWRAM_DATA CrossoverBattle* gCrossoverBattle = NULL;  // 0x030000F0
IWRAM_DATA u8 u8_030000f4[4] = {};
IWRAM_DATA u8 gCrossoverPlayerNames[2][16] = {};  // 0x030000F8, 通信対戦の待合画面で決まった双方のプレイヤー名

s32 FUN_0804e514(void* param_1);  // src/entity_0804e2c0.c
void FUN_0804e5e8(void);          // src/entity_0804e2c0.c

s32 CrossoverMC_SetState(struct CrossoverMC* p, u32 state);
void CrossoverMC_RequestExit(struct CrossoverMC* p);
void Entity08052ffc_Spawn(void* p, u32 idx, u32 mode, Vec3* pos);
void CrossoverBattle_AddPoint(u32 param_1, u32 param_2);
void FUN_0823ce68(s32 param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5, u32 param_6, s32 param_7);
s32 MainMenu_SetHudMode(s32 mode);
void FUN_0804e604(void);
void* FUN_0804ba3c(void);
void FUN_0803cc70(void);
bool32 FUN_0804e59c(void);
void MosaicFader_Stop(void);
void Player_Lock(Player* p, s32 val);
void FUN_0808e420(void);
void FUN_0808e4f4(void);
s32 FUN_0804e458(void);
s32 CrossoverResult_Setup(u32 param_1, u32 result, s32 framesA, s32 framesB, s32 remain, s32 total, Procedure exitCallback);
bool8 Save_WriteSystemData(void);
void FUN_0803ca14(void);
void* Entity08051b70_Create(u32 id, u32 unused);
void* CrossoverMC_Create();
void* Entity08052ffc_Create(void);
void SignalStrengthIcon_CreateAt(s32 x, s32 y);
const WeaponData* FUN_0823d414(s32 idx);
void SetWeaponData(slot32_t n, const WeaponData* data);
void FUN_0804e4dc(void* param_1, void* param_2, void* param_3, void* param_4);
void FUN_0804f950(void);
void FUN_0804f970(void);

// クロスオーバーポイントの今の値
static inline s32 GetCrossoverPoint(void) { return gSystemSaveData->crossoverPoint; }

// state を切り替え, 次の更新で初期化させる
static inline void CrossoverBattle_SetState(CrossoverBattle* p, u8 state) {
  p->state = state;
  p->stateBegun = TRUE;
  p->stateTimer = 0;
}

CrossoverBattle* CrossoverBattle_Get(void) { return gCrossoverBattle; }

// 相手から届いた通信を種別ごとに sides[1] へ写し, 受信済みビットを linkFlags に立てる
void CrossoverBattle_OnReceive(CrossoverBattleMsg* msg) {
  CrossoverBattle* p = CrossoverBattle_Get();
  CrossoverBattleSide* b;

  if (p == NULL) {
    return;
  }
  b = &p->sides[1];
  switch (msg->kind) {
    case 0: {
      b->playerHP = msg->data.word;
      b->bossHP = msg->data.word >> 8;
      return;
    }
    case 1: {
      SET_FLAGS(p->linkFlags, 2);
      break;
    }
    case 2: {
      s32 shift = 0;
      u16 counts;
      s32 i;

      b->blocking = msg->data.half[1] % 2;
      counts = msg->data.half[0];
      for (i = 0; i < 4; i++, shift += 4) {
        b->ojama[i] = (counts >> shift) & 0xF;
      }
      SET_FLAGS(p->linkFlags, 8);
      break;
    }
    case 3: {
      SET_FLAGS(p->linkFlags, 0x20);
      break;
    }
    case 4: {
      b->clearTime = msg->data.half[0];
      b->outcome = msg->data.half[1] % 4;
      if (b->outcome == 1) {
        b->bossHP = 0;
      } else if (b->outcome == 2) {
        b->playerHP = 0;
      }
      SET_FLAGS(p->linkFlags, 0x80);
      break;
    }
    case 5: {
      if (FUN_0804e458() == 0) {
        p->judgeResult = msg->data.word & 3;
      }
      SET_FLAGS(p->linkFlags, 0x200);
      break;
    }
  }
}

// 送り終えた種別の送信済みビットを linkFlags に立てる
void CrossoverBattle_OnSent(CrossoverBattleMsg* msg) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p == NULL) {
    return;
  }
  switch (msg->kind) {
    case 0: {
      break;
    }
    case 1: {
      SET_FLAGS(p->linkFlags, 1);
      break;
    }
    case 2: {
      SET_FLAGS(p->linkFlags, 4);
      break;
    }
    case 3: {
      SET_FLAGS(p->linkFlags, 0x10);
      break;
    }
    case 4: {
      SET_FLAGS(p->linkFlags, 0x40);
      break;
    }
    case 5: {
      SET_FLAGS(p->linkFlags, 0x100);
      break;
    }
  }
  p->sent = 1;
}

void FUN_0804f950(void) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p != NULL && p->sendMsg.kind != 0) {
    FUN_0804e514(&p->sendMsg);
  }
}

void FUN_0804f970(void) { CrossoverBattle_Get(); }

// 次に受けるオジャマバットを決める, 自分がブロックすれば相手の分は消えて得点になり, 相手がブロックすれば自分の分が返ってくる
void CrossoverBattle_ResolveOjama(CrossoverBattle* p) {
  CrossoverBattleSide* a = &p->sides[0];
  CrossoverBattleSide* b = &p->sides[1];
  s32 sum = 0;
  s32 i;

  if (a->blocking != 0) {
    for (i = 0; i < 4; i++) {
      p->incomingOjama[i] = 0;
      sum += b->ojama[i];
    }
    if (sum > 0) {
      CrossoverBattle_AddPoint(3, 1);
    }
  } else {
    for (i = 0; i < 4; i++) {
      p->incomingOjama[i] = b->ojama[i];
    }
  }
  if (b->blocking != 0) {
    for (i = 0; i < 4; i++) {
      p->incomingOjama[i] += a->ojama[i];
    }
  } else {
    for (i = 0; i < 4; i++) {
    }
  }
  for (i = 0; i < 4; i++) {
  }
}

// このラウンドでオジャマバットのやり取りがあるか, 自分がブロックしていれば残り回数を1つ使う
s32 CrossoverBattle_HasOjamaExchange(CrossoverBattle* p) {
  CrossoverBattleSide* a = &p->sides[0];
  CrossoverBattleSide* b = &p->sides[1];

  if (a->blocking || b->blocking || *(u32*)a->ojama != 0 || *(u32*)b->ojama != 0) {
    if (a->blocking && p->blocksLeft != 0) {
      p->blocksLeft--;
    }
    return 1;
  }

  return 0;
}

// sendMsg に種別と本体を詰めて送信を頼む, 送れなければ sendPending を立てて -1
s32 CrossoverBattle_Send(CrossoverBattle* p, u32 kind, u32* src, s32 wordCount) {
  CrossoverBattleMsg* msg = &p->sendMsg;
  s32 result;

  if (p->sendPending != 0 && msg->kind != 0) {
    return -1;
  }

  msg->kind = kind;
  if (wordCount > 0) {
    u32* dst = &msg->data.word;

    do {
      *dst++ = *src++;
      wordCount--;
    } while (wordCount != 0);
  }

  result = FUN_0804e514(msg);
  if (result < 0 && msg->kind != 0) {
    p->sendPending = 1;
  }
  return result;
}

// 双方の outcome と clearTime を比べて勝敗を決める (0: 勝ち, 1: 負け, 2: 引き分け), 両方撃破なら速い方, 両方死亡なら遅い方の勝ち
// 残差: 原典は CrossoverBattle_AddPoint(1, 1) からの return 0 の塊を2か所で共有して4命令短い, if 連鎖と switch のどちらでも共有されない
NON_MATCH u32 CrossoverBattle_Judge(CrossoverBattle* p) {
#ifdef NONMATCHING_C
  CrossoverBattleSide* a = &p->sides[0];
  CrossoverBattleSide* b = &p->sides[1];

  switch (a->outcome) {
    case 0: {
      if (b->outcome == 1) {
        return 1;
      } else if (b->outcome == 2) {
        CrossoverBattle_AddPoint(1, 1);
        return 0;
      }
      return 2;
    }
    case 1: {
      if (b->outcome == 1) {
        if (a->clearTime < b->clearTime) {
          return 0;
        } else if (a->clearTime > b->clearTime) {
          return 1;
        }
        return 2;
      } else if (b->outcome == 2) {
        CrossoverBattle_AddPoint(1, 1);
      }
      return 0;
    }
    default: {
      if (b->outcome == 1) {
        return 1;
      } else if (b->outcome == 2) {
        CrossoverBattle_AddPoint(1, 1);
        if (a->clearTime < b->clearTime) {
          return 1;
        } else if (a->clearTime > b->clearTime) {
          return 0;
        }
        return 2;
      }
      return 1;
    }
  }
#else
  INCFUNC("asm/func/CrossoverBattle_Judge.inc");
#endif
}

void CrossoverBattle_ClearOjama(CrossoverBattle* p, s32 idx) {
  CrossoverBattleSide* side = &p->sides[idx];
  s32 i;

  side->blocking = 0;
  for (i = 0; i < 4; i++) {
    side->ojama[i] = 0;
  }
}

void CrossoverBattle_OnScreenDone(void) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p != NULL) {
    p->screenDone = 1;
  }
}

void CrossoverBattle_SetOutcome(CrossoverBattle* p) {
  CrossoverBattleSide* side = &p->sides[0];

  if (p->playerDead != 0) {
    side->outcome = 2;
  } else if (p->bossDefeated != 0) {
    side->outcome = 1;
  } else {
    side->outcome = 0;
  }

  side->clearTime = 720 - p->roundTimer;
}

// 背景 TILEMAP_A413 を index の1枚だけで組み, BG パレットを BGP_EFDA にする
void CrossoverBattle_SetupBG(CrossoverBattle* p, s32 index) {
  Video_SetupBGLayout(0, 0, GetFile(DIR_TILE_MAP, TILEMAP_A413), 0, 0, 1, &index);
  Video_GenerateBGMap(0, 0, 0, 0, 0);
  CpuCopy16(GetBgPlttFile(BGP_EFDA)->body, gBgPlttBuffer, 256 * sizeof(rgb555));
}

void CrossoverBattle_SetMCState(CrossoverBattle* p, u32 state) {
  if (p->mc != NULL) {
    CrossoverMC_SetState(p->mc, state);
  }
}

void CrossoverBattle_RequestMCExit(CrossoverBattle* p) {
  if (p->mc != NULL) {
    CrossoverMC_RequestExit(p->mc);
  }
}

void CrossoverBattle_OnResultClosed(void) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p != NULL) {
    p->resultClosed = 1;
  }
}

s32 CrossoverBattle_GetRivalPlayerHP(void);
s32 CrossoverBattle_GetRivalBossHP(void);

// 対戦用の武器を, 乱数で選んだ位置から順に登録枠へ配る
void CrossoverBattle_DealWeapons(CrossoverBattle* p) {
  if (p->weaponCount != 0) {
    s32 start = Mod(gFrameCounter, p->weaponCount);
    bool32 hasEmpty = FALSE;
    u32 mask = p->weaponMask;
    s32 i;

    for (i = 0; i < 4; i++) {
      s32 j;

      REGISTERED_WEAPON(i) = -1;
      for (j = start; j < start + 16; j++) {
        s32 k = j & 15;

        if (mask & (1 << k)) {
          REGISTERED_WEAPON(i) = k;
          mask &= ~(1 << k);
          start = j;
          break;
        }
      }
      if (REGISTERED_WEAPON(i) < 0) {
        hasEmpty = TRUE;
      }
      start += Random() & 15;
    }
    if (hasEmpty) {
      for (i = 0; i < 4; i++) {
        if (REGISTERED_WEAPON(i) >= 0 && GetWeaponID(REGISTERED_WEAPON(i)) == WEAPON_NONE) {
          REGISTERED_WEAPON(i) = -1;
        }
      }
    }
    gStat->equippedWeaponIdx = 0;
  }
}

// 対戦用の魔法を, 乱数で選んだ位置から順に登録枠へ配る
void CrossoverBattle_DealMagic(CrossoverBattle* p) {
  if (p->magicCount != 0) {
    s32 start = Mod(gFrameCounter, p->magicCount);
    u32 mask = p->magicMask;
    s32 i;

    for (i = 0; i < 4; i++) {
      s32 j;

      *(gStat->registeredMagic + i) = -1;
      for (j = start; j < start + 16; j++) {
        s32 k = j & 15;

        if (mask & (1 << k)) {
          *(gStat->registeredMagic + i) = p->magicIDs[k];
          mask &= ~(1 << k);
          start = j;
          break;
        }
      }
      start += Random() & 15;
    }
  }
}

// 装備中の武器が登録されていればそのスロットの使用済みビットを外す
// 間の空ループは原典のまま, agbcc は -O2 でも体が無いループを消さない
void FUN_0804fe24(CrossoverBattle* p) {
  s32 slot = REGISTERED_WEAPON(gStat->equippedWeaponIdx);
  s32 i;

  if (slot < 0) {
    return;
  }

  for (i = 0; i < 4; i++) {
  }

  if (GetWeaponID(slot) != WEAPON_NONE) {
    p->weaponMask &= ~(1 << slot);
  }
}

// 装備中の魔法と同じIDの枠を使用済みビットから外す
void FUN_0804fe68(CrossoverBattle* p) {
  s32 id = *(gStat->registeredMagic + gStat->equippedMagicIdx);
  s32 i;

  if (id < 0) {
    return;
  }
  for (i = 0; i < 16; i++) {
    if (p->magicIDs[i] == id) {
      p->magicMask &= ~(1 << i);
    }
  }
}

void FUN_0803cb24(void);
void FUN_0803cb4c(u32 val);
void FUN_0803cb6c(u32 val);
void FUN_0803cbb4(u32 val);
void FUN_0803cc54(u32 val);

// 受けるオジャマバットを色ごとにシェードマンへ渡して効果を起こし, 0 に戻す
void CrossoverBattle_ApplyOjama(CrossoverBattle* p) {
  s32 i;

  FUN_0803cb24();

  for (i = 0; i < 4; i++) {
  }

  if (p->incomingOjama[0] != 0) {
    FUN_0803cb4c(p->incomingOjama[0]);
    p->incomingOjama[0] = 0;
  }

  if (p->incomingOjama[1] != 0) {
    FUN_0803cb6c(p->incomingOjama[1]);
    p->incomingOjama[1] = 0;
  }

  if (p->incomingOjama[2] != 0) {
    FUN_0803cbb4(p->incomingOjama[2]);
    p->incomingOjama[2] = 0;
  }

  if (p->incomingOjama[3] != 0) {
    FUN_0803cc54(p->incomingOjama[3]);
    p->incomingOjama[3] = 0;
  }
}

void CrossoverBattle_StateSync(CrossoverBattle* p) {
  if (p->stateBegun) {
    u32 data;

    p->stateBegun = FALSE;
    MosaicFader_Stop();
    CrossoverBattle_ClearOjama(p, 1);
    data = 0;
    CrossoverBattle_Send(p, 1, &data, 1);
    SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
    CrossoverBattle_SetMCState(p, 1);
  }
  if (TEST_FLAGS(p->linkFlags, 0x80)) {
    HUD_RemoveCountdown();
    CrossoverBattle_SetState(p, 6);
    CrossoverBattle_RequestMCExit(p);
  } else if (TEST_FLAGS(p->linkFlags, 3) == 3) {
    p->linkFlags &= ~3;
    CrossoverBattle_SetState(p, 1);
    CrossoverBattle_RequestMCExit(p);
  } else {
    p->stateTimer++;
  }
}

void CrossoverBattle_StateInterval(CrossoverBattle* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    CrossoverBattle_DealWeapons(p);
    CrossoverBattle_DealMagic(p);
    p->startPressed = 0;
    FUN_0808e420();
    Entity08051b70_StartSend(CrossoverBattle_OnScreenDone, &p->sides[0]);
    p->screenDone = 0;
    p->startDelay = 8;
    CrossoverBattle_SetMCState(p, 2);
  }
  if (gInput[0].pressed & START_BUTTON) {
    p->startPressed = 1;
    p->startDelay = 8;
  }
  if (p->screenDone != 0 && p->stateTimer > 16 && p->startPressed != 0) {
    if (p->startDelay == 0) {
      PlaySound_082406e0(SE_SELECT);
      CrossoverBattle_SetState(p, 2);
      FUN_0808e4f4();
      CrossoverBattle_RequestMCExit(p);
      return;
    }
    p->startDelay--;
  }
  p->stateTimer++;
}

// 残差: linkFlags の 0xC を落とすところで, 原典は ~0xC を作ってから linkFlags を読み直す (CLEAR_FLAGS だと判定の 0xC と共有されて bics になる)
NON_MATCH void CrossoverBattle_StateExchangeOjama(CrossoverBattle* p) {
#ifdef NONMATCHING_C
  if (p->stateBegun) {
    CrossoverBattleSide* a;
    u32 data;
    s32 shift;
    s32 i;

    p->stateBegun = FALSE;
    a = &p->sides[0];
    shift = 0;
    data = a->blocking << 16;
    for (i = 0; i < 4; i++, shift += 4) {
      data |= a->ojama[i] << shift;
    }
    CrossoverBattle_Send(p, 2, &data, 1);
    CrossoverBattle_SetMCState(p, 1);
    FUN_0804fe24(p);
    FUN_0804fe68(p);
  }
  if (TEST_FLAGS(p->linkFlags, 0xC) == 0xC) {
    CrossoverBattle_ResolveOjama(p);
    p->linkFlags &= ~0xC;
    CrossoverBattle_SetState(p, 3);
    CrossoverBattle_RequestMCExit(p);
  } else {
    p->stateTimer++;
  }
#else
  INCFUNC("asm/func/CrossoverBattle_StateExchangeOjama.inc");
#endif
}

void CrossoverBattle_StateOjamaAnim(CrossoverBattle* p) {
  if (p->stateBegun) {
    s32 result;

    p->stateBegun = FALSE;
    result = CrossoverBattle_HasOjamaExchange(p);
    if (result != 0) {
      p->ojamaAnimActive = 1;
      p->screenDone = 0;
      if (Entity08051b70_StartExchange(CrossoverBattle_OnScreenDone, &p->sides[0], &p->sides[1], p->incomingOjama)) {
        p->screenDone = 1;
      }
    } else {
      u32 data;

      p->ojamaAnimActive = result;
      data = result;
      CrossoverBattle_Send(p, 3, &data, 1);
    }
  }
  if (p->ojamaAnimActive != 0 && p->screenDone != 0) {
    u32 data = 0;

    CrossoverBattle_Send(p, 3, &data, 1);
    p->screenDone = 0;
  }
  if (TEST_FLAGS(p->linkFlags, 0x30) == 0x30) {
    p->linkFlags &= ~0x30;
    CrossoverBattle_SetState(p, 4);
  } else {
    p->stateTimer++;
  }
}

// 相手のロックマンとシェードマンのアイコンを体力の割合に応じて切り替える
void CrossoverBattle_UpdateHPIcons(CrossoverBattle* p) {
  s32 n = CrossoverBattle_GetRivalPlayerHP();
  s32 idx = 0;

  if (n <= 60) {
    idx = 2;
    if (n > 25) {
      idx = 1;
    }
  }
  MainSprite_SetPose(&p->sprites[0], &p->iconGfx, ICON_MEGAMAN(idx), PLAYMODE_PAUSE);

  n = CrossoverBattle_GetRivalBossHP();
  idx = 0;
  if (n <= 60) {
    idx = 2;
    if (n > 25) {
      idx = 1;
    }
  }
  MainSprite_SetPose(&p->sprites[1], &p->iconGfx, ICON_SHADEMAN(idx), PLAYMODE_PAUSE);
}

void CrossoverBattle_StateRoundStart(CrossoverBattle* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    if (++p->round > 98) {
      p->round = 99;
    }
    if (p->round == 11) {
      FUN_0803cc70();
    }
    CrossoverBattle_ClearOjama(p, 0);
    CrossoverBattle_SetMCState(p, 3);
  }
  if (p->round == 11 && p->stateTimer == 20) {
    Sound_FadeOutBGM(4);
  }
  if (p->stateTimer > 89) {
    CrossoverBattle_SetState(p, 5);
    CLEAR_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
    CrossoverBattle_RequestMCExit(p);
  } else {
    p->stateTimer++;
  }
}

// 対戦中, 1 秒ごとに自分側のジャンゴとシェードマンの体力の割合を送り, 決着か時間切れで次の state へ移る
void CrossoverBattle_StateFight(CrossoverBattle* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    p->roundTimer = 720;
    HUD_StartCountdown(&p->roundTimer);
    CrossoverBattle_SetMCState(p, 4);
    CrossoverBattle_ApplyOjama(p);
    if (p->round == 11) {
      sound_08240264(BGM_MMBN5);
    } else if (p->round == 1) {
      sound_08240264(BGM_SHADEMAN);
    }
    p->fighting = 1;
  }
  CrossoverBattle_UpdateHPIcons(p);
  if (p->stateTimer == 30) {
    CrossoverBattle_RequestMCExit(p);
  }
  if (Mod(p->stateTimer, 60) == 0) {
    Player* player = gPlayerPtr[0];
    Boss* boss = Boss_Get(BOSS_SHADEMAN_CROSSOVER);
    s32 playerRate;
    s32 bossRate;
    u32 data;

    playerRate = (player != NULL && player->maxHP != 0) ? Div(player->hp * 100, player->maxHP) : 0;
    if (playerRate == 0 && player->hp != 0) {
      playerRate = 1;
    }
    bossRate = (boss != NULL && boss->maxHP > 0) ? Div(boss->hp * 100, boss->maxHP) : 0;
    if (bossRate == 0 && boss->hp > 0) {
      bossRate = 1;
    }
    data = (bossRate << 8) | playerRate;
    CrossoverBattle_Send(p, 0, &data, 1);
  }
  // playerDead か bossDefeated が立った
  if ((*(u32*)&p->ojamaAnimActive & 0xFFFF00) != 0 || TEST_FLAGS(p->linkFlags, 0x80)) {
    HUD_RemoveCountdown();
    CrossoverBattle_SetState(p, 6);
  } else if (--p->roundTimer == 0) {
    FUN_0803ca14();
    HUD_RemoveCountdown();
    PlaySound_082406e0(SE_882);
    CrossoverBattle_SetState(p, 0);
    SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
    p->fighting = 0;
  } else {
    p->stateTimer++;
  }
}

void CrossoverBattle_StateSendResult(CrossoverBattle* p) {
  if (p->stateBegun) {
    CrossoverBattleSide* a;
    u32 data;

    p->stateBegun = FALSE;
    MosaicFader_Stop();
    CrossoverBattle_SetOutcome(p);
    a = &p->sides[0];
    data = (u16)a->clearTime | ((a->outcome & 3) << 16);
    CrossoverBattle_Send(p, 4, &data, 1);
    CrossoverBattle_SetMCState(p, 5);
    Sound_FadeOutBGM(4);
    if (!TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
      Player_Lock(gPlayerPtr[0], -1);
    }
  }
  if (p->stateTimer > 29 && TEST_FLAGS(p->linkFlags, 0xC0) == 0xC0) {
    p->linkFlags &= ~0xC0;
    CrossoverBattle_SetState(p, 7);
  } else {
    p->stateTimer++;
  }
}

void CrossoverBattle_StateJudge(CrossoverBattle* p) {
  if (p->stateBegun) {
    u32 result;

    p->stateBegun = FALSE;
    p->judgeResult = CrossoverBattle_Judge(p);
    result = p->judgeResult;
    CrossoverBattle_Send(p, 5, &result, 1);
    SET_FLAGS(gEntityDisableFlags, ENTITY_DISABLE_2);
  }
  if (TEST_FLAGS(p->linkFlags, 0x300) == 0x300) {
    p->linkFlags &= ~0x300;
    CrossoverBattle_SetState(p, 8);
  } else {
    p->stateTimer++;
  }
}

// 120 フレーム待ってから state 9 へ移り, CrossoverBattle_RequestMCExit を呼ぶ
void CrossoverBattle_StateWait(CrossoverBattle* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
  }
  if (p->stateTimer > 119) {
    FUN_0804e5e8();
    CrossoverBattle_SetState(p, 9);
    CrossoverBattle_RequestMCExit(p);
  } else {
    p->stateTimer++;
  }
}

void CrossoverBattle_StateResult(CrossoverBattle* p) {
  if (p->stateBegun) {
    s32 base;
    s32 framesA;
    s32 framesB;
    s32 i;

    p->stateBegun = FALSE;
    p->resultClosed = 0;
    base = (p->round - 1) * 720;
    framesA = base + p->sides[0].clearTime;
    framesB = base + p->sides[1].clearTime;
    CrossoverResult_Setup(FUN_0804e458(), p->judgeResult, framesA, framesB, p->earnedPoint, GetCrossoverPoint(), CrossoverBattle_OnResultClosed);
    for (i = 0; i < 2; i++) {
      p->sprites[i].flags |= SPRFLAG_HIDDEN;
    }
  }
  if (p->resultClosed != 0) {
    s32* windowID = &p->windowID;

    CrossoverBattle_SetState(p, 10);
    p->retryCount = 0;
    CrossoverBattle_SetupBG(p, 3);
    *windowID = TextPanel_Create(1, 7, 28, 6);
    if (*windowID >= 0) {
      TextPanel_SetScript(*windowID, p->script);
      TextPanel_SetMessage(*windowID, 11);
      TextPanel_Start(*windowID);
    }
  }
}

// 獲得ポイントを足してセーブし, 結果のメッセージを出す, 失敗したら2回までやり直す
void CrossoverBattle_StateSave(CrossoverBattle* p) {
  s32* windowID = &p->windowID;

  if (p->stateBegun) {
    s32 point;

    p->stateBegun = FALSE;
    point = GetCrossoverPoint() + p->earnedPoint;
    if (point > 9999) {
      point = 9999;
    } else if (point < 0) {
      point = 0;
    }
    gSystemSaveData->crossoverPoint = point;
  }
  if (p->stateTimer == 60) {
    p->saveResult = Save_WriteSystemData();
    if (p->saveResult == TRUE) {
      TextPanel_SetMessage(*windowID, 14);
      PlaySound_082406e0(SE_SAVE_SUCCESS);
    } else {
      TextPanel_SetMessage(*windowID, 15);
      PlaySound_082406e0(SE_NG);
    }
  }
  if (p->stateTimer == 180) {
    if (p->saveResult == TRUE || ++p->retryCount > 2) {
      CrossoverBattle_SetState(p, 11);
    } else {
      TextPanel_SetMessage(*windowID, 11);
      CrossoverBattle_SetState(p, 10);
    }
  } else {
    p->stateTimer++;
  }
}

void CrossoverBattle_StateExit(CrossoverBattle* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    FUN_0823ce68(3, 3, 0, 0, 0, 0xFFFF, 0);
  }
  if (p->stateTimer == 10) {
    MainMenu_SetHudMode(7);
  } else if (p->stateTimer > 20) {
    if (p->stateTimer == 40) {
      FUN_0804e604();
    }
    if (FUN_0804ba3c() == NULL) {
      p->exitRequest = 1;
      return;
    }
  }
  p->stateTimer++;
}

s32 CrossoverBattle_Update(CrossoverBattle* p) {
  static void (*const sCrossoverBattleStateFuncs[12])(CrossoverBattle*) = {
      CrossoverBattle_StateSync,
      CrossoverBattle_StateInterval,
      CrossoverBattle_StateExchangeOjama,
      CrossoverBattle_StateOjamaAnim,
      CrossoverBattle_StateRoundStart,
      CrossoverBattle_StateFight,
      CrossoverBattle_StateSendResult,
      CrossoverBattle_StateJudge,
      CrossoverBattle_StateWait,
      CrossoverBattle_StateResult,
      CrossoverBattle_StateSave,
      CrossoverBattle_StateExit,
  };  // 0x085AB6A4

  if (p->exitRequest != 0) {
    p->exitRequest = 0;
    MainMenu_SetHudMode(7);
    Video_SetDrawPasses(0, Particle_DrawList, AuxSprite_DrawList, MainSprite_DrawList);
    if (p->exitScript != 0) {
      VM_ExecByID(p->exitScript, NULL);
    }
    KillEntity(&p->e);
  } else {
    s32 busy = FUN_0804e59c();

    if (busy == 0) {
      sCrossoverBattleStateFuncs[p->state](p);
      if (p->sendPending != 0 && FUN_0804e514(&p->sendMsg) >= 0) {
        p->sendPending = busy;
      }
    }
  }
  return 0;
}

s32 CrossoverBattle_Destroy(CrossoverBattle* p) {
  s32 i;

  for (i = 0; i < 2; i++) {
    MainSprite_Remove(&p->sprites[i]);
  }

  TextPanel_Destroy(p->windowID);
  gCrossoverBattle = NULL;
  return 0;
}

// 残差: 471 対 446 命令, 原典は後半で0を書くフィールドのアドレスを最初のループの前に作ってスタックへ逃がす, ループの形も未調整
NON_MATCH s32 CrossoverBattle_Init(CrossoverBattle* p) {
#ifdef NONMATCHING_C
  u8 magic[16];
  Vec3 pos;
  MainSpriteGfxFile* f;
  s32 i;

  gCrossoverBattle = p;
  p->exitScript = VM_GetNamedArgValue('e', 0);
  p->weaponCount = 0;
  p->weaponMask = 0;
  if (VM_SeekToNamedArg('w')) {
    for (i = 0; i < 16; i++) {
      if (VM_GetPC() != NULL) {
        p->weaponIDs[i] = VM_GetValue();
        p->weaponCount++;
      } else {
        p->weaponIDs[i] = 0;
      }
    }
  } else {
    for (i = 15; i >= 0; i--) {
      p->weaponIDs[i] = 0;
    }
  }
  if (p->weaponCount != 0) {
    u8 r = gFrameCounter;
    u32 n;

    for (n = 0; n < p->weaponCount; n++) {
      s32 k = r & 15;

      while (p->weaponMask & (1 << k)) {
        k = r & 15;
        r++;
      }
      p->weaponMask |= 1 << k;
      SetWeaponData(k, FUN_0823d414(p->weaponIDs[n]));
      r += Random() & 0xFF;
    }
  }
  p->magicCount = 0;
  p->magicMask = 0;
  if (VM_SeekToNamedArg('m')) {
    for (i = 0; i < 16; i++) {
      if (VM_GetPC() != NULL) {
        magic[i] = VM_GetValue();
        p->magicCount++;
      } else {
        magic[i] = 0;
      }
    }
  } else {
    for (i = 15; i >= 0; i--) {
      magic[i] = 0;
    }
  }
  if (p->magicCount != 0) {
    u8 r = gFrameCounter;
    u32 n;

    for (n = 0; n < p->magicCount; n++) {
      s32 k = r & 15;

      while (p->magicMask & (1 << k)) {
        k = r & 15;
        r++;
      }
      p->magicMask |= 1 << k;
      p->magicIDs[k] = magic[n];
      r += Random() & 0xFF;
    }
  }
  p->unk_18 = 0;
  p->roundTimer = 0;
  p->round = 0;
  p->linkFlags = 0;
  p->sent = 0;
  p->ojamaAnimActive = 0;
  p->playerDead = 0;
  p->screenDone = 0;
  p->blocksLeft = 1;
  p->state = 0;
  p->stateBegun = TRUE;
  p->stateTimer = 0;
  FUN_0804e4dc(CrossoverBattle_OnSent, CrossoverBattle_OnReceive, FUN_0804f950, FUN_0804f970);
  for (i = 0; i < 2; i++) {
    s32 j;

    for (j = 3; j >= 0; j--) {
      p->sides[i].ojama[j] = 0;
    }
    p->sides[i].playerHP = 100;
    p->sides[i].bossHP = 100;
    p->sides[i].blocking = 0;
    p->sides[i].outcome = 0;
    p->sides[i].clearTime = 0;
  }
  for (i = 3; i >= 0; i--) {
    p->incomingOjama[i] = 0;
  }
  CrossoverBattle_ClearOjama(p, 0);
  CrossoverBattle_ClearOjama(p, 1);
  Entity08051b70_Create(0, 0);
  p->mc = CrossoverMC_Create();
  p->unk_64 = Entity08052ffc_Create();
  SignalStrengthIcon_CreateAt(4, 24);
  if (!VM_SeekToNamedArg('s')) {
    return -1;
  }
  p->script = VM_GetPC_Proxy();
  if (p->script == NULL) {
    return -1;
  }
  p->earnedPoint = 0;
  p->unk_1ac = VM_GetNamedArgValue('M', 11);
  if (!VM_SeekToNamedArg('p')) {
    return -1;
  }
  for (i = 0; i < 4; i++) {
    p->pointTable[i] = VM_GetValue();
  }
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_INVENTORY_ICONS);
  if (f == NULL) {
    return -1;
  }
  p->iconGfx = *f;
  OpenMainSpriteFile(&p->iconGfx, f);
  for (i = 0; i < 2; i++) {
    u16 pose;

    if (i == 0) {
      pos.x = 132;
      pose = 0xD4;
    } else {
      pos.x = 220;
      pose = 0xD7;
    }
    pos.y = 24;
    pos.z = 0;
    MainSprite_Add(&p->sprites[i], &p->iconGfx, pose, SPRFLAG_UNK_16 | SPRFLAG_SCREEN_COORD, 0, 0, 60, &pos);
  }
  return 0;
#else
  INCFUNC("asm/func/CrossoverBattle_Init.inc");
#endif
}

// 0xAF33
CrossoverBattle* CrossoverBattle_Create(void) {
  CrossoverBattle* p = CreateEntity(ENTITY_UNK_2, sizeof(CrossoverBattle));
  if (p != NULL) {
    SetEntityRoutine(p, CrossoverBattle_Update, CrossoverBattle_Destroy);
    if (CrossoverBattle_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// kind 色のオジャマバットを1匹増やして pos に出す, 1色5匹・合計10匹まで
void CrossoverBattle_AddOjama(Vec3* pos, u32 kind) {
  CrossoverBattle* p = CrossoverBattle_Get();
  u8* counts;
  s32 sum;
  s32 i;

  if (p == NULL) {
    return;
  }
  counts = p->sides[0].ojama;
  if (counts[kind] > 4) {
    return;
  }
  sum = 0;
  for (i = 0; i < 4; i++) {
    sum += counts[i];
  }
  if (sum > 9) {
    return;
  }
  Entity08051b70_SpawnCollected(pos, kind, 1);
  counts[kind]++;
  CrossoverBattle_AddPoint(2, 1);
  PlaySound_082406e0(SONG_885);
}

void CrossoverBattle_NotifyPlayerDead(void) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p != NULL) {
    p->playerDead = 1;
  }
}

void CrossoverBattle_NotifyBossDefeated(void) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p != NULL) {
    p->bossDefeated = 1;
  }
}

s32 FUN_08050d40(void) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p == NULL || p->unk_30 == 0) {
    return FALSE;
  }
  p->unk_30 = 0;
  return TRUE;
}

s32 CrossoverBattle_GetRivalPlayerHP(void) {
  CrossoverBattle* p = CrossoverBattle_Get();
  CrossoverBattleSide* side;

  if (p == NULL) {
    return 0;
  }
  side = &p->sides[1];
  return side->playerHP;
}

s32 CrossoverBattle_GetRivalBossHP(void) {
  CrossoverBattle* p = CrossoverBattle_Get();
  CrossoverBattleSide* side;

  if (p == NULL) {
    return 0;
  }
  side = &p->sides[1];
  return side->bossHP;
}

s32 CrossoverBattle_GetBlockCount(void) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p == NULL) {
    return 0;
  }
  return p->blocksLeft;
}

s32 CrossoverBattle_ToggleBlocking(void) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p != NULL && p->round != 0 && p->blocksLeft != 0) {
    CrossoverBattleSide* side = &p->sides[0];

    side->blocking = 1 - side->blocking;
    PlaySound_082406e0(SE_QUICK_CHANGE);
    return side->blocking;
  }
  return 0;
}

s32 CrossoverBattle_GetRound(void) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p == NULL) {
    return 0;
  }
  return p->round;
}

s32 CrossoverBattle_IsMaxMode(void) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p == NULL || p->round <= 10) {
    return FALSE;
  }
  return TRUE;
}

// 0x877F
void Cmd_877F(void) { gGameFlags |= FLAG030047A4_UNK_12; }

void FUN_08050e2c(u32 idx, u32 mode, Vec3* pos) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p != NULL) {
    Entity08052ffc_Spawn(p->unk_64, idx, mode, pos);
  }
}

void CrossoverBattle_AddPoint(u32 param_1, u32 param_2) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p != NULL) {
    p->earnedPoint += p->pointTable[param_1] * param_2;
  }
}

s32 CrossoverBattle_IsFighting(void) {
  CrossoverBattle* p = CrossoverBattle_Get();

  if (p == NULL || p->state != 5) {
    return FALSE;
  }
  return TRUE;
}
