#include "entity.h"
#include "global.h"
#include "msgbus.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

// カットシーン用のブラックホール (HashName("デモブラックホール")), BlackHole_Create の演出用の版
// ロックマンが「じゃあ、ボクは行くね」と言って帰る場面 (カットシーン 78) で, ロックマンが歩いていった先の黒い球
// Scr_0x0B81 が置き, カットシーン 78 のステップ 4 から cmd 6 を受けると縮んで消える
typedef struct CutsceneBlackHole {
  Entity e;                                           // 0x00, ENTITY_UNK_10
  MsgQueue mq;                                        // 0x18, targetID は id, 待ち番号 10
  AuxSprite sprite;                                   // 0x4C
  AuxSpriteGfx gfx;                                   // 0x78, SPRITE_BLACKHOLE
  u16 id;                                             // 0x94, mq.targetID, このゲームでは 0xF378 のみ
  u16 scale;                                          // 0x96, sprite.scaleX / scaleY に毎フレーム入る 6.6 固定小数
  u16 scaleStep;                                      // 0x98, '.s[1]' (既定 2), _UpdateShrink が scale から毎フレーム引く
  u16 scaleStart;                                     // 0x9A, '.s[0]' (既定 0x40), scale の初期値
  u16 frameCounter;                                   // 0x9C, 0..2 を巡回し, 1 を超える間だけ sprite.poseIdx が 1 になる
  bool16 killRequested;                               // 0x9E, 0 以外になると _Update が KillEntity する
  u8 unk_a0[4];                                       // 0xA0
  Vec3 pos;                                           // 0xA4, '.p', sprite.pos の初期値
  void (*updateCallback)(struct CutsceneBlackHole*);  // 0xAC, 初期値 CutsceneBlackHole_UpdateIdle
} CutsceneBlackHole;
static_assert(sizeof(CutsceneBlackHole) == 176);

void CutsceneBlackHole_UpdateIdle(CutsceneBlackHole* _) {}

void CutsceneBlackHole_UpdateShrink(CutsceneBlackHole* p) {
  if (p->scale <= p->scaleStep) {
    p->scale = 1;
    p->killRequested = TRUE;
  } else {
    p->scale -= p->scaleStep;
  }
}

// 溜まったメッセージを受け取り, cmd 6 で縮小開始に切り替える
void CutsceneBlackHole_PollMessages(CutsceneBlackHole* p) {
  MsgQueue* mq = &p->mq;
  s32 i;

  for (i = 0; i < mq->count[gMsgBus->bufIdx]; i++) {
    MsgBus* bus = gMsgBus;
    MsgPacket* msg = mq->msgs[bus->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    if (msg->cmd == 6) {
      p->updateCallback = CutsceneBlackHole_UpdateShrink;
      PlaySound_082406e0(SE_605);
    }
  }
}

// 残差3命令ぶんのアドレッシング違いのみ (54/54, 同数同順): 原典は poseIdx を 0x4C+0x10 に分割して書くが agbcc は 0x5C+0 に畳む
// Tier A-C は試済: 三項演算子は分岐ごとのアドレス再計算が出ず6命令短い, AuxSprite* のローカルは巻き上げられて逆に短くなる
// 分割形は cactus.c のように直前の呼び出しで &sprite がレジスタに載っている場合に出るが, この関数にはその文脈がない
NON_MATCH s32 CutsceneBlackHole_Update(CutsceneBlackHole* p) {
#ifdef NONMATCHING_C
  CutsceneBlackHole_PollMessages(p);
  p->updateCallback(p);
  if (p->frameCounter <= 1) {
    p->sprite.poseIdx = 0;
  } else {
    p->sprite.poseIdx = 1;
  }
  p->sprite.scaleX = p->sprite.scaleY = p->scale;
  p->frameCounter++;
  if (p->frameCounter > 2) {
    p->frameCounter = 0;
  }

  if (p->killRequested) {
    MsgQueue_EndWait(&p->mq, 1);
    KillEntity((Entity*)p);
  }
  return 0;
#else
  INCFUNC("asm/func/CutsceneBlackHole_Update.inc");
#endif
}

s32 CutsceneBlackHole_Destroy(CutsceneBlackHole* p) {
  MsgQueue_Unregister(&p->mq);
  AuxSprite_Remove(&p->sprite);
  return 0;
}

// 受け口を登録し, '.p'/'.R'/'.s' からスプライトの位置・優先度・拡大率を決める
s32 CutsceneBlackHole_Init(CutsceneBlackHole* p, u32 id, u32 _) {
  AuxSprite* spr;
  AuxSpriteGfx* gfx;
  u32 priority;

  p->id = id;
  MsgQueue_Register(&p->mq, p->id, CLS_ETC);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(p->pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(p->pos, 0, 0, 0);
  }

  priority = VM_SeekToNamedArg('R') ? VM_GetValue() : 2;
  if (VM_SeekToNamedArg('s')) {
    p->scaleStart = VM_GetValue();
    p->scaleStep = VM_GetValue();
  } else {
    p->scaleStart = Q6(1);
    p->scaleStep = 2;
  }
  p->scale = p->scaleStart;
  spr = &p->sprite;
  gfx = &p->gfx;
  Video_GetAuxSprite(gfx, SPRITE_BLACKHOLE);
  AuxSprite_Add(spr, gfx, SPRFLAG_AFFINE);
  Video_SetAuxSpritePltt(gfx, 50);
  spr->poseIdx = 0;
  spr->scaleY = spr->scaleX = p->scale;
  p->sprite.flags |= SPRFLAG_AFFINE;
  spr->priority = priority;
  spr->pos = p->pos;
  p->frameCounter = 0;
  p->killRequested = FALSE;
  p->updateCallback = CutsceneBlackHole_UpdateIdle;
  return 0;
}

// 0x3361, HashName("デモブラックホール"), id は 0xF378 のみ
CutsceneBlackHole* CutsceneBlackHole_Create(u32 id, u32 param_2) {
  CutsceneBlackHole* p = CreateEntity(ENTITY_UNK_10, sizeof(CutsceneBlackHole));

  if (p != NULL) {
    SetEntityRoutine(p, CutsceneBlackHole_Update, CutsceneBlackHole_Destroy);
    if (CutsceneBlackHole_Init(p, id, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
