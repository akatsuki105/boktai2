#include "entity.h"
#include "global.h"
#include "input.h"
#include "msgbus.h"
#include "player.h"
#include "shademan.h"
#include "sound.h"

// 一定間隔で gCamera->shakeAmplitude を上げて NOISE_QUAKE_121 を鳴らすシングルトン, メッセージ (cmd 4/5) で外部からも起こせる
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
} Entity8EC8;
static_assert(sizeof(Entity8EC8) == 128);

NAKED void Entity8EC8_HandleMessages(Entity8EC8* p) { INCFUNC("asm/func/Entity8EC8_HandleMessages.inc"); }

// 残差1命令, 原典は gPlayerPtr[0] のレジスタから写しを作る (FUN_0807b1a4 系と同じ)
NON_MATCH bool32 Entity8EC8_IsStartHeld(void) {
#ifdef NONMATCHING_C
  Player* p = gPlayerPtr[0];

  if ((gInput[0].down & START_BUTTON) && p != NULL && p->unk_1c == 1 && !(p->unk_20 & PFLAG20_UNK_0)) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/Entity8EC8_IsStartHeld.inc");
#endif
}

// 残差1命令, 原典は gPlayerPtr[0] のレジスタから写しを作る (FUN_0807b1a4 系と同じ)
NON_MATCH bool32 Entity8EC8_IsSelectHeld(void) {
#ifdef NONMATCHING_C
  Player* p = gPlayerPtr[0];

  if ((gInput[0].down & SELECT_BUTTON) && p != NULL && p->unk_1c == 1 && !(p->unk_20 & PFLAG20_UNK_0)) {
    return TRUE;
  }
  return FALSE;
#else
  INCFUNC("asm/func/Entity8EC8_IsSelectHeld.inc");
#endif
}

NAKED s32 Entity8EC8_Update(Entity8EC8* p) { INCFUNC("asm/func/Entity8EC8_Update.inc"); }

s32 Entity8EC8_Destroy(Entity8EC8* p) {
  MsgQueue_Unregister(&p->mq);
  sound_08240740(NOISE_QUAKE);
  return 0;
}

NAKED s32 Entity8EC8_Init(Entity8EC8* p, u32 id) { INCFUNC("asm/func/Entity8EC8_Init.inc"); }

Entity8EC8* Entity8EC8_Create(u32 id) {
  Entity8EC8* p = CreateEntity(ENTITY_UNK_4, sizeof(Entity8EC8));

  if (p != NULL) {
    SetEntityRoutine(p, Entity8EC8_Update, Entity8EC8_Destroy);
    if (Entity8EC8_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 点滅をやめて unk_38c の bit8 を立てる
// 残差は命令の並び順だけ (17 対 17), 原典は定数 0x100 を unk_38c のアドレス計算より前に作る
// 0x100 を左に書く形 / AuxSprite_SetFlags 経由 / MainSprite* ローカルは試済
NON_MATCH void FUN_0821bd14(Entity0623* p) {
#ifdef NONMATCHING_C
  MainSprite_ClearFlags(&p->sprite_2bc, SPRFLAG_BLINK_ODD);
  p->unk_38c |= 0x100;
#else
  INCFUNC("asm/func/FUN_0821bd14.inc");
#endif
}
