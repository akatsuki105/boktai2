#ifndef __INCLUDE_NPC_H__
#define __INCLUDE_NPC_H__

#include "collision_map.h"
#include "entity.h"
#include "gba/gba.h"
#include "mover.h"
#include "msgbus.h"
#include "player.h"
#include "shadow.h"
#include "sprite.h"
#include "types.h"

struct NPCManager;
struct NPC;

typedef s32(NPCCb)(struct NPCManager*, struct NPC*);
typedef void(NPCUpdate)(struct NPCManager*, struct NPC*, s32);

// NPC.flags (0x00E)
typedef u16 NPCFlags;
#define NPCFLAG_UNK_8 (1 << 8)      // 0x0100, FUN_08042178 が立てる
#define NPCFLAG_TALKABLE (1 << 11)  // 0x0800, 向かい合って近くにいると立つ, FUN_08041918 が話し相手の候補にする
#define NPCFLAG_UNK_12 (1 << 12)    // 0x1000, FUN_080421bc が立てる

// FUN_08041480 が第2引数を添字にして1件引き, SpriteHolder_SetAnim に渡すアニメを決める
typedef struct {
  u8 dirMode;  // 0x0, 向きからアニメ番号と左右反転を作る方式, 0 は向きを見ない, 1 と 2 は unk_19, 3 は unk_1a を見る
  s8 unk_1;    // 0x1, dirMode が 2 と 3 のときだけ読む
  u16 pose;    // 0x2, SpriteHolder_SetAnim の第2引数
} NPCAnim;
static_assert(sizeof(NPCAnim) == 4);

// スプライトIDとキャラ番号ごとの足音設定, FUN_080414fc がアニメのフレームと突き合わせて鳴らす
typedef struct NPCFootStepSound {
  SpriteID16 id;     // 0x0, NPCのスプライトIDばっかり
  u8 idx;            // 0x2, 1つのグラフィックにn人分のグラフィックデータが入っているときにどのキャラクターかを示すインデックス?
  u8 soundSet;       // 0x3, sFootStepSEs[soundSet] の2つの音を鳴らす
  s8 stepFrames[4];  // 0x4, 足音を鳴らすアニメフレーム, [0][1] がアニメ添字1用, [2][3] が添字3用, -1 なら鳴らさない
} NPCFootStepSound;

// おてんこの NPC.work
typedef struct {
  u16 unk_00;    // 0x00
  u8 unk_02[2];  // 0x02
  u8 unk_04;     // 0x04
  u8 unk_05[3];  // 0x05
  u8 unk_08;     // 0x08
} NPCOtenkoWork;

// リタの NPC.work
typedef struct {
  u8 unk_00[4];  // 0x00
  u8 unk_04;     // 0x04
} NPCRitaWork;

// クロの NPC.work
typedef struct {
  u16 unk_00;    // 0x00, Cmd_D774 は 0, Cmd_82C8 は 1
  u8 unk_02[2];  // 0x02
  u16 unk_04;    // 0x04
  u16 unk_06;    // 0x06
  u32 unk_08;    // 0x08
  u16 unk_0c;    // 0x0C
  u8 unk_0e[8];  // 0x0E
  u16 unk_16;    // 0x16
  u32 unk_18;    // 0x18
  u32 unk_1c;    // 0x1C
} NPCKuroWork;

// スミスが槌を打つときの NPC.work
typedef struct {
  u16 step;      // 0x00, アニメが終わるたびに進む, 0 で打ち, 1 で終える
  u16 timer;     // 0x02, step の中の経過フレーム, step 0 の 3 フレーム目に火花を出す
  u8 voiceWait;  // 0x04, 0 のときだけ掛け声を鳴らし, 1 か 2 に戻す
} NPCSmithWork;

// メッセージで歩かせる NPC の NPC.work
typedef struct {
  u8 unk_00[0x20];   // 0x00
  u32 talkScriptID;  // 0x20, '.t', 話しかけたとき FUN_08041918 が VM_ExecByID で実行する
  u32 talkArgs[4];   // 0x24, 話しかけたときのスクリプトの argv[4..7]
  WorldPos target;   // 0x34, cmd 3 のメッセージの args[0..2], ここへ向かって歩く
} NPCWalkWork;

// NPC の 0x020 からの領域, NPC の種類ごとに使い方が違う (FUN_08208990 は +8 をワードで使う)
typedef union {
  u16 unk_00;            // FUN_08044a54 系が 0 を入れる
  NPCOtenkoWork otenko;  // おてんこ (SPR_OTENKO_00)
  NPCRitaWork rita;      // リタ (SPR_RITA)
  NPCKuroWork kuro;      // クロ (SPR_KURO)
  NPCWalkWork walk;      // FUN_080441d8 などがメッセージで歩かせるとき
  NPCSmithWork smith;    // FUN_08044a90 が槌を打たせるとき
  u8 raw[60];
} NPCWork;

// NPC 1人 に対応
typedef struct NPC {
  u8 active;                  // 0x000, NPCManager_LinkNPC が 1 を入れ、FUN_0804114c が 0 にして Free する
  u8 kind;                    // 0x001, NPC_Alloc の第2引数
  u8 unk_02;                  // 0x002
  u8 unk_03;                  // 0x003
  u8 state;                   // 0x004, FUN_08044138 / FUN_0804470c が関数テーブルの添字として使う
  u8 unk_05;                  // 0x005, コールバックが 1,2,4,6 などを入れる, FUN_080442d4 は 0
  u8 unk_06;                  // 0x006, まだ未解析
  u8 unk_07;                  // 0x007, unk_08 と一緒に 0 に戻される
  u8 unk_08;                  // 0x008, 0 以外ならコールバックが待ちを解除して 0 に戻す
  u8 unk_09;                  // 0x009, まだ未解析
  u8 unk_0a;                  // 0x00A, FUN_080411d8 が 0 以外のときだけ進み、処理後 0 に戻す
  u8 unk_0b;                  // 0x00B
  u16 unk_0c;                 // 0x00C
  NPCFlags flags;             // 0x00E, 0x100 / 0x200 / 0x1000 のビットで分岐する
  u32 unk_10;                 // 0x010, 根拠: FUN_080441a4 が +1 して元の値を unk_2cc の第3引数に渡す
  u32 timer;                  // 0x014, 多数の関数が 0 に戻し、FUN_08042414 が +1 する
  u8 unk_18;                  // 0x018, まだ未解析
  u8 unk_19;                  // 0x019, FUN_080413b8 が SpriteHolder_SetAnim の第3/第4引数を作るのに見る
  u8 unk_1a;                  // 0x01A, まだ未解析
  u8 unk_1b;                  // 0x01B, FUN_08040f0c が第4引数 (向き) を入れる
  u16 plttID;                 // 0x01C, NPC_SetPltt が書き、NPC_RefreshPltt が再適用する
  u16 curPlttID;              // 0x01E, NPC_ApplyPltt が SpriteHolder_SetPlttID へ渡した値
  NPCWork work;               // 0x020
  Mover mover;                // 0x05C
  ZoneEventSource zoneEvent;  // 0x0A0, id は mover.id の写し, pos は &mover.pos
  SpriteHolder sprite;        // 0x0D0, 0x08055XXX のスプライト API に渡す
  MsgQueue mq;                // 0x164
  PathWalker pathWalker;      // 0x198, Mover_SetPath に渡す
  NavAgent navAgent;          // 0x1A4, FUN_08042f34 がナビメッシュで歩かせる
  u8 unk_1c8[0x1E8 - 0x1C8];  // 0x1C8, まだ未解析
  u8 unk_1e8;                 // 0x1E8, FUN_08042868 が FUN_08041480 の第2引数に渡す
  u8 unk_1e9;                 // 0x1E9, 同じく第3引数
  u16 unk_1ea;                // 0x1EA, Cmd_ConfigureNPC の '.b' の3つ目
  u8 unk_1ec;                 // 0x1EC, FUN_08042cf0 が初回に 1 を入れる
  s8 unk_1ed;                 // 0x1ED, 0 以外なら FUN_08043a24 が棺桶の近さと雨を見る
  u8 unk_1ee;                 // 0x1EE, 根拠: NPC_RemoveMover が 0 以外のときだけ mover を切り離して 0 に戻す
  s8 pathIdx;                 // 0x1EF, Cmd_ConfigureNPC の '.r' の1つ目, 負なら経路なし
  u16 pathSpeed;              // 0x1F0, 経路を歩く速さ, Map_GetStepToPathNode に渡す
  u16 unk_1f2;                // 0x1F2, FUN_08041e10 の '.s' の2つ目 (既定 96)
  u32 unk_1f4;                // 0x1F4, pathSpeed の写し
  u32 unk_1f8;                // 0x1F8, unk_1f2 の写し
  u32 unk_1fc;                // 0x1FC, pathSpeed の2乗
  u32 unk_200;                // 0x200, unk_1f2 の2乗
  s32 walkSpeed;              // 0x204, work.walk.target へ歩くときの1フレームの移動量
  u32 arriveDistSq;           // 0x208, target までの距離の2乗がこれ以下なら着いたとみなす
  u16 pathParam;              // 0x20C, Cmd_ConfigureNPC の '.r' の2つ目, Mover_SetPath の第4引数
  u16 pathDelay;              // 0x20E, 経路の今のノードの待ちフレーム数 (PathNode.delay の下位12bit)
  u16 pathNodeIdx;            // 0x210, Cmd_ConfigureNPC の '.r' の3つ目, 最初に向かうノード番号
  u8 footStep;                // 0x212, 0 以外なら FUN_080414fc が足音を鳴らす
  bool8 pathArrived;          // 0x213, FUN_080428b8 で経路の今のノードに着いたら立つ
  u8 shadowKind;              // 0x214, 1 なら shadow.ptcl, 2 なら shadow.aux
  u8 unk_215;                 // 0x215, FUN_08043bcc が unk_216 のとき unk_1b に写す向き
  u8 unk_216;                 // 0x216, 0 以外なら FUN_08043bcc が離れたとき state 3 へ
  u8 unk_217;                 // 0x217, 0 以外なら次の state を unk_227 から取る
  u8 unk_218[0x21C - 0x218];  // 0x218, まだ未解析
  s32 nearRange;              // 0x21C, プレイヤーがこの距離 (x, z) まで近づいたら反応する
  s32 unk_220;                // 0x220, FUN_08043bcc の近さの判定に使う距離
  u8 unk_224;                 // 0x224, FUN_08042f34 が経路を引いたら 1 にする
  u8 unk_225;                 // 0x225, まだ未解析
  u8 pathDir;                 // 0x226, 経路の方向転換ノードの向き (8方向, PathNode.delay の上位4bit)
  u8 unk_227;                 // 0x227, unk_217 が立っているときの遷移先 state
  s32 talkRange;              // 0x228, FUN_08041e10 の '.w' の1つ目 (既定 256), この距離 (x, z) の内で向かい合うと NPCFLAG_TALKABLE が立つ
  u8 unk_22c[4];              // 0x22C, まだ未解析
  u8 unk_230;                 // 0x230, 0 以外なら FUN_08043a24 が分の切り替わりで時間帯の終わりを見る
  u8 startHour;               // 0x231, FUN_08043da8 が見る時間帯の始まり (時)
  u8 startMinute;             // 0x232, 同じく (分)
  u8 endHour;                 // 0x233, 時間帯の終わり (時)
  u8 endMinute;               // 0x234, 同じく (分)
  u8 unk_235;                 // 0x235, まだ未解析
  u16 waitFrames;             // 0x236, 0 以外の間 FUN_08043da8 が減らすだけで時間帯を見ない
  u8 unk_238;                 // 0x238, Cmd_ConfigureNPC の '.H' の1つ目
  u8 unk_239;                 // 0x239, Cmd_ConfigureNPC の '.H' の2つ目
  u8 unk_23a;                 // 0x23A, まだ未解析
  u8 unk_23b;                 // 0x23B, Cmd_ConfigureNPC が '.H' のとき 0xFF にする
  WorldPos navTarget;         // 0x23C, FUN_08042f34 がナビメッシュで向かう目的地
  union {
    ParticleShadow ptcl;            // shadowKind == 1
    AuxShadow aux;                  // shadowKind == 2
  } shadow;                         // 0x244
  WorldPos unk_2b0;                 // 0x2B0
  const NPCAnim* unk_2b8;           // 0x2B8, このキャラのアニメ表の先頭, FUN_08041480 がここから1件引く
  const NPCFootStepSound* unk_2bc;  // 0x2BC, id と idx で引いた sNPCFootStepSounds の行
  struct Emote* emote;              // 0x2C0, FUN_080415cc が Emote_Show に渡して戻り値を入れ直す
  u32 emoteKind;                    // 0x2C4, 今出している吹き出しの種類, FUN_080415cc の kind 8 が閉じるときに使う
  s16 unk_2c8;                      // 0x2C8, FUN_080411d8 が毎フレーム減らし, 3 以下になると unk_2ca を複写し直すか FUN_080415cc を呼ぶ
  s16 unk_2ca;                      // 0x2CA, FUN_080415cc が書き、FUN_080411d8 が unk_2c8 へ移す
  NPCUpdate* unk_2cc;               // 0x2CC, 根拠: FUN_080441a4 が (p, npc, unk_10) で呼ぶ
  NPCCb* cbs[4];                    // 0x2D0, FUN_080411a0 が 0 以外のものを順に呼ぶ
  NPCCb* onDestroy;                 // 0x2E0, _Destroy が呼ぶ
  s32 (*fn)(struct NPC*);           // 0x2E4, npc だけを渡して呼ぶ
  struct NPC* prev;                 // 0x2E8
  struct NPC* next;                 // 0x2EC
} NPC;
static_assert(sizeof(NPC) == 752);

// 状態を差し替えて経過フレーム数を 0 に戻す
static inline void NPC_SetState(NPC* npc, u32 state) {
  npc->state = state;
  npc->timer = 0;
}

// unk_02/unk_03 を 0 に戻して状態を差し替え, unk_08 を立てる
static inline void NPC_StartState(NPC* npc, u32 state) {
  npc->unk_02 = 0;
  npc->unk_03 = 0;
  NPC_SetState(npc, state);
  npc->unk_08 = 1;
}

// unk_2cc を差し替えて, 次の呼び出しを初回扱いにする
static inline void NPC_SetUpdate(NPC* npc, NPCUpdate* fn, u32 id) {
  npc->unk_06 = id;
  npc->unk_2cc = fn;
  npc->unk_10 = 0;
  npc->unk_09 = 1;
  npc->unk_18 = 0;
}

static inline void NPC_SetFn(NPC* npc, s32 (*fn)(NPC*)) { npc->fn = fn; }
static inline void NPC_SetCb(NPC* npc, s32 i, NPCCb* cb) { npc->cbs[i] = cb; }
static inline void NPC_SetOnDestroy(NPC* npc, NPCCb* cb) { npc->onDestroy = cb; }

// NPC を全部まとめて持つマネージャ
// NPC = スクリプトから操作されるキャラクター (NPC, 同行者, イベント中の主人公)
// VM コマンド 0x286F が自分自身を作り, その後 0xBB34 などの別のコマンドが NPC を1体ずつ足していく
// スクリプトは NPCManager_FindNPCByMoverID で mover ID から対象キャラを引く
// NPC は14種あり, 種別ごとに state テーブルと per-state 更新テーブルを1組ずつ持つ (PTR_ARRAY_085ae83c 以降の28本)
// 毎フレーム更新するのが hour/minute と playerPos/player なので, 時刻とプレイヤー位置で NPC の挙動が変わる
typedef struct NPCManager {
  Entity e;              // 0x000, ENTITY_UNK_9
  u32 frameCount;        // 0x018, _Update が毎フレーム +1
  NPC* head;             // 0x01C, リストの先頭, 解放は FUN_0804114c
  bool8 minuteChanged;   // 0x020, prevMinute != minute
  u8 prevMinute;         // 0x021, 1フレーム前の minute
  u8 hour;               // 0x022, Time_GetHour
  u8 minute;             // 0x023, Time_GetMinute
  bool8 raining;         // 0x024, FUN_08018a08 (雨が降っているか), 降っている間 FUN_08043da8 は時間帯を見ない
  u8 unk_25[3];          // 0x025, padding?
  s32 unk_28;            // 0x028, _Update が毎フレーム 1 - x で 0/1 を往復させる, unk_2c の添字
  u32 unk_2c[2];         // 0x02C, _Update が unk_28 の側だけ 0 にする
  u8 msgBufs[2][8][64];  // 0x034, Cmd_SendNPCMsg が MsgPacket を組み立てる場所, [unk_28][unk_2c[unk_28]]
  WorldPos* playerPos;   // 0x434, gPlayerPtr[0] があれば &gPlayerPtr[0]->mover.pos
  Player* player;        // 0x438, &gPlayerPtr[0], 毎フレーム更新
} NPCManager;
static_assert(sizeof(NPCManager) == 1084);

extern NPCManager* gNPCManager;

// --------------------------------------------

NPC* NPC_Alloc(u32 id, u32 kind);
s32 FUN_08040f48(NPC* npc, s32 spriteType, SpriteID32 spriteID, u32 animFileID, SpriteFlags flags);
void NPCManager_LinkNPC(NPCManager* p, NPC* npc);  //  NPC をリストの先頭に繋ぐ
s32 FUN_08040df4(NPCManager* p, NPC* npc, SpriteID32 id, s32 idx);
s32 NPC_HideShadow(NPC* npc);
NPC* NPCManager_FindNPCByMoverID(NPCManager* p, u32 id);
s32 FUN_08040fc0(NPC* npc, Vec3* pos, u32 kind, u32 poseIdx, s32 size);
s32 FUN_08041e10(NPCManager* p, NPC* npc);
s32 FUN_0804135c(NPC* npc, u32 pose, u32 param_3, u32 param_4, u32 param_5, u32 param_6);
s32 FUN_08040f0c(NPC* npc, u32 id, Vec3* pos, u32 angle);
s32 FUN_080412fc(NPCManager* p, NPC* npc);
s32 FUN_08043510(NPC* npc);

// --------------------------------------------

void FUN_0804355c(NPCManager*, NPC*);
void FUN_08043588(NPCManager*, NPC*);
void FUN_080435b4(NPCManager*, NPC*);
void FUN_080435f0(NPCManager*, NPC*);
void FUN_0804364c(NPCManager*, NPC*);
void FUN_08043688(NPCManager*, NPC*);
void FUN_080436c4(NPCManager*, NPC*);
void FUN_08043774(NPCManager*, NPC*);
void FUN_08043960(NPCManager*, NPC*);
void FUN_08043a24(NPCManager*, NPC*);
void FUN_08043bcc(NPCManager*, NPC*);
void FUN_08043c94(NPCManager*, NPC*);
void FUN_08043cc4(NPCManager*, NPC*);
void FUN_08043cf4(NPCManager*, NPC*);
void FUN_08043da8(NPCManager*, NPC*);
void FUN_08043e54(NPCManager*, NPC*);

// --------------------------------------------

void FUN_08042178(NPCManager*, NPC*, s32);
void FUN_080421bc(NPCManager*, NPC*, s32);
void FUN_08042200(NPCManager*, NPC*, s32);
void FUN_0804234c(NPCManager*, NPC*, s32);
void FUN_08042414(NPCManager*, NPC*, s32);
void FUN_08042638(NPCManager*, NPC*, s32);
void FUN_08042868(NPCManager*, NPC*, s32);
void FUN_080428b8(NPCManager*, NPC*, s32);
void FUN_08042a48(NPCManager*, NPC*, s32);
void FUN_08042cf0(NPCManager*, NPC*, s32);
void FUN_08042d50(NPCManager*, NPC*, s32);
void FUN_08042f34(NPCManager*, NPC*, s32);
void FUN_08043108(NPCManager*, NPC*, s32);
void FUN_08043360(NPCManager*, NPC*, s32);

#endif  // __INCLUDE_NPC_H__
