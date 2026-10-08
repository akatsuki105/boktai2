#include "entity.h"
#include "global.h"
#include "msgbus.h"

// 一定間隔でカメラを揺らして地震の音を鳴らすシングルトン, メッセージ (cmd 4/5) で外部からも起こせる
typedef struct {
  Entity e;             // 0x00, ENTITY_UNK_4
  u32 id;               // 0x18, mq の targetID と同じ値
  MsgQueue mq;          // 0x1C, targetClass 10
  bool32 disabled;      // 0x50, '.D=0', 0 以外なら自動発生もボタン操作も止まる
  s32 interval;         // 0x54, '.i=0', nextDelay の基準となるフレーム数
  s32 riseDur;          // 0x58, '.t[0]', 揺れが立ち上がるフレーム数
  s32 holdDur;          // 0x5C, '.t[1]', 最大の揺れを保つフレーム数
  s32 fallDur;          // 0x60, '.t[2]', 揺れが収まるフレーム数
  s32 amplitude;        // 0x64, '.l=0', 揺れの最大値
  s32 shakeAmplitude;   // 0x68, 今フレームの揺れ, gCamera->shakeAmplitude へ渡す
  s32 state;            // 0x6C, 0〜7
  s32 stateTimer;       // 0x70, state が変わると 0
  s32 nextDelay;        // 0x74, 次の発生までのフレーム数, interval + (乱数 & 0x7F)
  bool32 stateBegun;    // 0x78, state が変わった最初のフレームだけ 1
  bool32 soundPlaying;  // 0x7C, NOISE_QUAKE_121 を鳴らしている間 1
} Earthquake;
static_assert(sizeof(Earthquake) == 128);

INCASM("asm/entity_8ec8.inc");
