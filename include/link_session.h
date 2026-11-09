#ifndef __INCLUDE_LINK_SESSION_H__
#define __INCLUDE_LINK_SESSION_H__

#include "entity.h"
#include "types.h"

// 交換に出す武器, 並びは WeaponData と同じで特殊効果だけバイト列で持つ
typedef struct {
  u8 id;             // 0x00
  u8 kind;           // 0x01
  u8 rank;           // 0x02
  u8 lv;             // 0x03
  u8 atk;            // 0x04
  u8 durability;     // 0x05
  u16 wear;          // 0x06
  s16 quality;       // 0x08
  u16 price;         // 0x0A
  char PS[12];       // 0x0C
  u8 effects[3][4];  // 0x18, WeaponData.effects をバイトごとに写したもの
} LinkTradeWeapon;
static_assert(sizeof(LinkTradeWeapon) == 36);

// 通信で交換するプレイヤー1人分の記録, 自分の分を self に作って送り, 全員分を records[] に受け取る
typedef struct LinkPlayerRecord {
  char name[16];         // 0x00, プレイヤー名, gStat->name の写し
  u16 randSeed;          // 0x10, 乱数の種, 親機だけが時計から作り, records[0] のものを全員が gRandTableIdx に使う
  u16 unk_12;            // 0x12, 100
  u16 controlUp;         // 0x14, gStat->controlUp の写し
  u8 unk_16;             // 0x16, records[0] のものが LinkSession.unk_38 に写される
  u8 tradeSlot;          // 0x17, 交換に出す武器のスロット, 0xFF ならなし
  u32 unk_18;            // 0x18, 3 未満のレコードがあると Entity08F4 (ルール設定) の選択肢が1つ増える
  LinkTradeWeapon body;  // 0x1C, 交換に出す武器, LinkSession.bodies[] に写される
  u8 unk_40[4];          // 0x40, [0] が 2 なら武器は GUN_DEL_HELL 固定, [1] は通信対戦のステータスの種類
  u8 unk_44;             // 0x44, Time_GetSpanOfTime の値, FUN_080cc618 が 0/4/5 (夜) のどれかかを見る
  u8 unk_45;             // 0x45
  u16 crc;               // 0x46, CalcCRC16 で 0x00..0x45 から作る
} LinkPlayerRecord;
static_assert(sizeof(LinkPlayerRecord) == 72);

// 通信対戦のルール (3項目の選択値) と CRC, 親機が送って全員が受け取る
typedef struct {
  u8 values[3];  // 0x00, Entity08F4 (ルール設定) の3行の選択値, sLinkBattleRuleLimits[i] 以上なら 0 に戻す
  u8 unk_3[3];   // 0x03
  u16 crc;       // 0x06, CalcCRC16(values, 6)
} LinkBattleRules;
static_assert(sizeof(LinkBattleRules) == 8);

// 通信プレイ1回分のセッション, 接続, 記録とルールの交換, 対戦中のキー入力と太陽センサーの値の同期, 得点の集計を受け持つ, 進行は state と updateCallback の組を LinkSession_SetState で切り替える
typedef struct LinkSession {
  Entity e;                                     // 0x000, ENTITY_UNK_1
  s16 playerIdx;                                // 0x018, 自分のプレイヤー番号 (gPlayerPtr の添字), -1 なら未確定
  u16 recordCount;                              // 0x01A, 参加人数, records[] の有効数, 切断で 0 に戻る
  u8 state;                                     // 0x01C
  u8 sioID;                                     // 0x01D, Sio_Connect が返した自分の番号, 0 なら親機
  u8 killRequested;                             // 0x01E, 立つと LinkSession_Update が KillEntity して exitScriptID を実行する
  u8 retryTimer;                                // 0x01F, recvResult == -3 が続いたフレーム数, 0xFF で止まる, 14 を超えると切断する
  u8 prevState;                                 // 0x020, 切断したときの state
  u8 unk_21;                                    // 0x021
  u8 stateBegun;                                // 0x022, 状態に入った直後だけ立ち, 一度読まれると 0 に戻る
  u8 unk_23;                                    // 0x023
  s8 unk_24;                                    // 0x024, -1 でなし, 0 以上なら FUN_081df014 がキー 0x2C00 | unk_24 を送る
  s8 unk_25;                                    // 0x025, 立っていれば FUN_081df0f8 が確認のメッセージを出す
  u8 unk_26;                                    // 0x026
  u8 unk_27;                                    // 0x027, unk_29 が立っている間のフレーム数, 60 を超えるとキー 0x1001 を送る
  u8 unk_28;                                    // 0x028
  u8 unk_29;                                    // 0x029
  u8 unk_2a;                                    // 0x02A
  u8 unk_2b;                                    // 0x02B
  u8 unk_2c[2];                                 // 0x02C
  u16 retryFrames;                              // 0x02E, 接続待ちのフレーム数, 30 に達すると切断して state 2 からやり直す
  u16 timeLimit;                                // 0x030, 対戦の制限時間 (フレーム), 7200
  s16 timeLeft;                                 // 0x032, 対戦の残りフレーム, ルールに応じて sLinkTimeLimits から入れて毎フレーム減らす
  u32 stateTimer;                               // 0x034, 状態に入ってからのフレーム数
  u16 unk_38;                                   // 0x038, startScriptID の第2引数, rules.values[2] (3 以上なら 0..2 の乱数) か records[0].unk_16
  u16 unk_3a;                                   // 0x03A, startScriptID の第3引数
  s32 unk_3c;                                   // 0x03C, '.L=5000'
  u8 unk_40[2];                                 // 0x040
  u16 sendKey;                                  // 0x042, 次に送るキー
  u16* recvKeys;                                // 0x044, 各プレイヤーから受け取ったキー, recvKeyBuf を指す
  s32 sendResult;                               // 0x048, Sio_SetSendData の戻り値
  s32 recvResult;                               // 0x04C, Sio_GetRecvData の戻り値, -3 なら受信できていない
  u8 luxRecvSide;                               // 0x050, lux[] の受信側の添字, luxReadSide と交互に入れ替わる
  u8 luxReadSide;                               // 0x051, lux[] の読み出し側の添字
  u8 luxRecvBit;                                // 0x052, 受信キーから lux を組み立てる次のビット位置
  u8 luxSendBit;                                // 0x053, 自分の lux (unk_54[0]) を送る次のビット位置, 0..7
  u8 unk_54[4];                                 // 0x054, [0] は送る自分の lux, [1] はメッセージを開いたら立つ
  u8 lux[2][4];                                 // 0x058, 各プレイヤーの太陽センサーの値, [luxReadSide] が読み出し側
  u8 luxGauge[4];                               // 0x060, lux を Taiyo_LxToGauge で直したゲージ
  u16 luxSum;                                   // 0x064, lux の合計
  u16 luxAverage;                               // 0x066, lux の平均
  u8 connStatus[4];                             // 0x068, 各プレイヤーの接続の状況, 0 で未接続, 120 フレーム応答が無いと 0 に戻る
  u16 recvKeyBuf[4];                            // 0x06C, 0xFFFF はデータなし
  u8 unk_74[0x78 - 0x74];                       // 0x074
  u8 noReplyFrames[0x7E - 0x78];                // 0x078, 各プレイヤーの応答が無いフレーム数, 0xFF で止まる
  u16 dataSendPos;                              // 0x07E, データ送信で次に送るバイトの位置
  u16 dataRecvPos[4];                           // 0x080, 各プレイヤーからのデータ受信の位置
  LinkTradeWeapon bodies[4];                    // 0x088, records[i].body の写し
  s8 coinOwners[5];                             // 0x118, 各コインの持ち主のプレイヤー番号, -1 は空き, 持ち数が得点になる
  u8 unk_11d[3];                                // 0x11D
  u16 kills[4];                                 // 0x120, 各プレイヤーが相手を倒した数, 得点は1回 9点
  u16 deaths[4];                                // 0x128, 各プレイヤーが倒された数, 得点は1回 -4点
  s16 roundScores[4];                           // 0x130, この回の得点 (0..9999), 不参加は 0xFFFF
  s16 totalScores[4];                           // 0x138, 得点の累計 (0..9999)
  u32 eneSpent;                                 // 0x140, この回に銃で使った ENE の合計, 順位ボーナスの倍率になる
  s32 rankPoints[4];                            // 0x144, 順位で決まる点の累計
  s16 rankPointTable[4];                        // 0x154, 順位ごとの点, '.e' があればそこから、無ければ {2, 1, -1, -2}
  LinkPlayerRecord self;                        // 0x15C, 自分の記録, 相手に送る
  LinkPlayerRecord records[4];                  // 0x1A4, 受け取った全員の記録
  LinkBattleRules rulesOut;                     // 0x2C4, 親機が送るルール, Entity08F4 (ルール設定) の選択値の写し
  LinkBattleRules rules;                        // 0x2CC, 受け取ったルール
  void (*updateCallback)(struct LinkSession*);  // 0x2D4
  s32 windowID;                                 // 0x2D8, TextPanel_Create の戻り値
  u16 startScriptID;                            // 0x2DC, '.l=0', ルールが決まって回を始めるときに recordCount, unk_38, unk_3a を引数にして実行するスクリプト ID
  u16 unk_2de;                                  // 0x2DE, '.R=0', 0 以外なら FUN_081df0f8 が実行するスクリプト ID
  u16 unk_2e0;                                  // 0x2E0, '.v=0', 0 以外なら FUN_081df460 が実行するスクリプト ID
  u16 unk_2e2;                                  // 0x2E2, '.r=0', FUN_081df014 が実行するスクリプト ID
  u16 unk_2e4;                                  // 0x2E4, '.b=0', FUN_081df9ac が実行するスクリプト ID
  u16 exitScriptID;                             // 0x2E6, '.E=0', 終了時に実行するスクリプト ID, 0 ならソフトリセット
  u16 unk_2e8;                                  // 0x2E8, '.Y=0', FUN_081de844 が実行するスクリプト ID
  u16 unk_2ea;                                  // 0x2EA, '.U=0', FUN_081de844 が実行するスクリプト ID
  u8* messageScript;                            // 0x2EC, '.s' の後の VM_GetPC_Proxy(), メッセージを開いたときに TextPanel_SetScript へ渡す
  u8* unk_2f0;                                  // 0x2F0, '.S' の後の VM_GetPC_Proxy()
} LinkSession;
static_assert(sizeof(LinkSession) == 756);

extern LinkSession* gLinkSession;  // 0x03002C68

void ClearLinkSession(void);
s32 LinkSession_ReleaseAllCoins(unknown* param_1, s32 val);
s32 LinkSession_ReleaseCoin(unknown* param_1, s32 val);
s32 LinkSession_AddCoin(s32 val);
s32 LinkSession_AddKill(s32 idx);
s32 LinkSession_AddDeath(s32 idx);
void FUN_081df8a0(s32 val);
void FUN_081df8d4(void);
void FUN_081df8f0(s32 val);
void FUN_081df908(void);
void FUN_081df924(void);
void FUN_081df940(void);
void FUN_081df95c(s32 val);
void LinkSession_RequestKill(void);
void FUN_081df9ac(Vec3* pos, s32 val);
s32 FUN_081dfa04(void);
void FUN_081dfa20(s32 kind, s32* strength, s32* vitality, s32* spirit, s32* agility);
void FUN_081dfe5c(void);

#endif  // __INCLUDE_LINK_SESSION_H__
