#ifndef __INCLUDE_ENTITY_286F_H__
#define __INCLUDE_ENTITY_286F_H__

#include "collision_map.h"
#include "entity.h"
#include "gba/gba.h"
#include "mover.h"
#include "msgbus.h"
#include "player.h"
#include "shadow.h"
#include "sprite.h"
#include "types.h"

struct Entity286F;
struct Entity286FNode;

typedef void(Entity286FNodeCb)(struct Entity286F*, struct Entity286FNode*);
typedef void(Entity286FNodeUpdate)(struct Entity286F*, struct Entity286FNode*, s32);

// Entity286FNode.flags (0x00E)
typedef u16 Entity286FNodeFlags;
#define E286FNODE_UNK_8 (1 << 8)    // 0x0100, FUN_08042178 が立てる
#define E286FNODE_UNK_12 (1 << 12)  // 0x1000, FUN_080421bc が立てる

// unk_1a0 が指すレコード, FUN_080434ac が unk_4 の下位12bit と unk_6 の上位4bit を見る
typedef struct {
  u16 x;      // 0x0, mover.pos.x との距離が 0x28 以内かを見る
  u16 y;      // 0x2, mover.pos.z との距離が 0x28 以内かを見る
  u16 unk_4;  // 0x4
  u8 unk_6;   // 0x6, 上位4bit が種別 (1 か 2)
  u8 unk_7;   // 0x7
} Entity286FRecord;

// FUN_08041480 が第2引数を添字にして1件引き, SpriteHolder_SetAnim に渡すアニメを決める
typedef struct {
  u8 dirMode;  // 0x0, 向きからアニメ番号と左右反転を作る方式, 0 は向きを見ない, 1 と 2 は unk_19, 3 は unk_1a を見る
  s8 unk_1;    // 0x1, dirMode が 2 と 3 のときだけ読む
  u16 pose;    // 0x2, SpriteHolder_SetAnim の第2引数
} Entity286FAnim;
static_assert(sizeof(Entity286FAnim) == 4);

// スプライトIDとキャラ番号ごとの足音設定, FUN_080414fc がアニメのフレームと突き合わせて鳴らす
typedef struct NPCFootStepSound {
  SpriteID16 id;     // 0x0, NPCのスプライトIDばっかり
  u8 idx;            // 0x2, 1つのグラフィックにn人分のグラフィックデータが入っているときにどのキャラクターかを示すインデックス?
  u8 soundSet;       // 0x3, sFootStepSEs のペア番号, [soundSet*2] と [soundSet*2+1] が鳴る
  s8 stepFrames[4];  // 0x4, 足音を鳴らすアニメフレーム, [0][1] がアニメ添字1用, [2][3] が添字3用, -1 なら鳴らさない
} NPCFootStepSound;

typedef struct Entity286FNode {
  u8 active;                  // 0x000, Entity286F_LinkNode が 1 を入れ、FUN_0804114c が 0 にして Free する
  u8 kind;                    // 0x001, Entity286FNode_Alloc の第2引数
  u8 unk_02[2];               // 0x002, まだ未解析
  u8 state;                   // 0x004, FUN_08044138 / FUN_0804470c が関数テーブルの添字として使う
  u8 unk_05;                  // 0x005, コールバックが 1,2,4,6 などを入れる, FUN_080442d4 は 0
  u8 unk_06;                  // 0x006, まだ未解析
  u8 unk_07;                  // 0x007, unk_08 と一緒に 0 に戻される
  u8 unk_08;                  // 0x008, 0 以外ならコールバックが待ちを解除して 0 に戻す
  u8 unk_09;                  // 0x009, まだ未解析
  u8 unk_0a;                  // 0x00A, FUN_080411d8 が 0 以外のときだけ進み、処理後 0 に戻す
  u8 unk_0b[3];               // 0x00B, まだ未解析
  Entity286FNodeFlags flags;  // 0x00E, 0x100 / 0x200 / 0x1000 のビットで分岐する
  u32 unk_10;                 // 0x010, 根拠: FUN_080441a4 が +1 して元の値を unk_2cc の第3引数に渡す
  u32 timer;                  // 0x014, 多数の関数が 0 に戻し、FUN_08042414 が +1 する
  u8 unk_18;                  // 0x018, まだ未解析
  u8 unk_19;                  // 0x019, FUN_080413b8 が SpriteHolder_SetAnim の第3/第4引数を作るのに見る
  u8 unk_1a;                  // 0x01A, まだ未解析
  u8 unk_1b;                  // 0x01B, FUN_08040f0c が第4引数 (向き) を入れる
  u16 plttID;                 // 0x01C, Entity286FNode_SetPltt が書き、Entity286FNode_RefreshPltt が再適用する
  u16 curPlttID;              // 0x01E, Entity286FNode_ApplyPltt が SpriteHolder_SetPlttID へ渡した値
  u16 unk_20;                 // 0x020, FUN_08044a54 系が 0 を入れる
  u8 unk_22[0x05C - 0x022];   // 0x022, まだ未解析
  Mover mover;                // 0x05C
  ZoneEventSource zoneEvent;  // 0x0A0, id は mover.id の写し, pos は &mover.pos
  SpriteHolder sprite;        // 0x0D0, 0x08055XXX のスプライト API に渡す
  MsgQueue mq;                // 0x164
  u8 unk_198[0x1A0 - 0x198];  // 0x198, まだ未解析
  Entity286FRecord* unk_1a0;  // 0x1A0
  u8 unk_1a4[0x1E8 - 0x1A4];  // 0x1A4, まだ未解析
  u8 unk_1e8;                 // 0x1E8, FUN_08042868 が FUN_08041480 の第2引数に渡す
  u8 unk_1e9;                 // 0x1E9, 同じく第3引数
  u8 unk_1ea[0x1EE - 0x1EA];  // 0x1EA, まだ未解析
  u8 unk_1ee;                 // 0x1EE, 根拠: Entity286FNode_RemoveMover が 0 以外のときだけ mover を切り離して 0 に戻す
  u8 unk_1ef[0x214 - 0x1EF];  // 0x1EF, まだ未解析
  u8 shadowKind;              // 0x214, 1 なら shadow.ptcl, 2 なら shadow.aux
  u8 unk_215[0x217 - 0x215];  // 0x215, まだ未解析
  u8 unk_217;                 // 0x217, 0 以外なら次の state を unk_227 から取る
  u8 unk_218[0x227 - 0x218];  // 0x218, まだ未解析
  u8 unk_227;                 // 0x227, unk_217 が立っているときの遷移先 state
  u8 unk_228[0x244 - 0x228];  // 0x228, まだ未解析
  union {
    ParticleShadow ptcl;              // shadowKind == 1
    AuxShadow aux;                    // shadowKind == 2
  } shadow;                           // 0x244
  u8 unk_2b0[0x2B8 - 0x2B0];          // 0x2B0, まだ未解析
  const Entity286FAnim* unk_2b8;      // 0x2B8, このキャラのアニメ表の先頭, FUN_08041480 がここから1件引く
  const NPCFootStepSound* unk_2bc;    // 0x2BC, id と idx で引いた sNPCFootStepSounds の行
  u8 unk_2c0[0x2C8 - 0x2C0];          // 0x2C0, まだ未解析
  u16 unk_2c8;                        // 0x2C8, FUN_080411d8 が unk_2ca を複写する
  u16 unk_2ca;                        // 0x2CA, FUN_080415cc が書き、FUN_080411d8 が unk_2c8 へ移す
  Entity286FNodeUpdate* unk_2cc;      // 0x2CC, 根拠: FUN_080441a4 が (p, node, unk_10) で呼ぶ
  Entity286FNodeCb* cbs[4];           // 0x2D0, FUN_080411a0 が 0 以外のものを順に呼ぶ
  Entity286FNodeCb* onDestroy;        // 0x2E0, _Destroy が呼ぶ
  s32 (*fn)(struct Entity286FNode*);  // 0x2E4, node だけを渡して呼ぶ
  struct Entity286FNode* prev;        // 0x2E8
  struct Entity286FNode* next;        // 0x2EC
} Entity286FNode;
static_assert(sizeof(Entity286FNode) == 752);

// スクリプトから操作されるキャラクター (NPC, 同行者, イベント中の主人公) を全部まとめて持つマネージャ, 1ノードが1キャラクター
// VM コマンド 0x286F が自分自身を作り, その後 0xBB34 などの別のコマンドがノードを1体ずつ足していく
// スクリプトは Entity286F_FindNodeByMoverID で mover ID から対象キャラを引く
// ノード種別は14種あり, 種別ごとに state テーブルと per-state 更新テーブルを1組ずつ持つ (PTR_ARRAY_085ae83c 以降の28本)
// 毎フレーム更新するのが hour/minute と playerPos/player なので, 時刻とプレイヤー位置でノードの挙動が変わる
typedef struct Entity286F {
  Entity e;                 // 0x000, ENTITY_UNK_9
  u32 frameCount;           // 0x018, _Update が毎フレーム +1
  Entity286FNode* head;     // 0x01C, リストの先頭, 解放は FUN_0804114c
  bool8 minuteChanged;      // 0x020, prevMinute != minute
  u8 prevMinute;            // 0x021, 1フレーム前の minute
  u8 hour;                  // 0x022, Time_GetHour
  u8 minute;                // 0x023, Time_GetMinute
  s8 unk_24;                // 0x024, FUN_08018a08 の戻り値
  u8 unk_25[3];             // 0x025, padding?
  s32 unk_28;               // 0x028, _Update が毎フレーム 1 - x で 0/1 を往復させる, unk_2c の添字
  u32 unk_2c[2];            // 0x02C, _Update が unk_28 の側だけ 0 にする
  u8 unk_34[0x434 - 0x34];  // 0x034, まだ未解析, C/I/U/D のどれからも触らない
  WorldPos* playerPos;      // 0x434, gPlayerPtr[0] があれば &gPlayerPtr[0]->mover.pos
  Player* player;           // 0x438, &gPlayerPtr[0], 毎フレーム更新
} Entity286F;
static_assert(sizeof(Entity286F) == 1084);

extern Entity286F* gEntity286F;

#endif  // __INCLUDE_ENTITY_286F_H__
