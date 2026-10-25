#include "entity.h"
#include "global.h"
#include "msgbus.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

// デモのメッセージを待ち受けるスプライト1枚, cmd 6 を受けると縮んで消える
typedef struct Entity3361 {
  Entity e;                                    // 0x00, ENTITY_UNK_10
  MsgQueue msgQueue;                           // 0x18, targetID は id, 待ち番号 10
  AuxSprite sprite;                            // 0x4C
  AuxSpriteGfx gfx;                            // 0x78, SPRITE_3641
  u16 id;                                      // 0x94, _Create の第1引数, msgQueue.targetID になる
  u16 scale;                                   // 0x96, sprite.scaleX / scaleY に毎フレーム入る 6.6 固定小数
  u16 scaleStep;                               // 0x98, '.s[1]' (既定 2), _UpdateShrink が scale から毎フレーム引く
  u16 scaleStart;                              // 0x9A, '.s[0]' (既定 0x40), scale の初期値
  u16 frameCounter;                            // 0x9C, 0..2 を巡回し, 1 を超える間だけ sprite.poseIdx が 1 になる
  bool16 killRequested;                        // 0x9E, 0 以外になると _Update が KillEntity する
  u8 unk_a0[4];                                // 0xA0
  Vec3 pos;                                    // 0xA4, '.p', sprite.pos の初期値
  void (*updateCallback)(struct Entity3361*);  // 0xAC, 初期値 Entity3361_UpdateIdle
} Entity3361;
static_assert(sizeof(Entity3361) == 176);

void Entity3361_UpdateIdle(Entity3361* _) {}

void Entity3361_UpdateShrink(Entity3361* p) {
  if (p->scale <= p->scaleStep) {
    p->scale = 1;
    p->killRequested = TRUE;
  } else {
    p->scale -= p->scaleStep;
  }
}

// 溜まったメッセージを受け取り, cmd 6 で縮小開始に切り替える
void Entity3361_PollMessages(Entity3361* p) {
  MsgQueue* mq = &p->msgQueue;
  s32 i;

  for (i = 0; i < mq->count[gMsgBus->bufIdx]; i++) {
    MsgBus* bus = gMsgBus;
    MsgPacket* msg = mq->msgs[bus->bufIdx][i];

    MsgQueue_BeginWait(mq, msg);
    if (msg->cmd == 6) {
      p->updateCallback = Entity3361_UpdateShrink;
      PlaySound_082406e0(SONG_605);
    }
  }
}

// 残差3命令ぶんのアドレッシング違いのみ (54/54, 同数同順): 原典は poseIdx を 0x4C+0x10 に分割して書くが agbcc は 0x5C+0 に畳む
// Tier A-C は試済: 三項演算子は分岐ごとのアドレス再計算が出ず6命令短い, AuxSprite* のローカルは巻き上げられて逆に短くなる
// 分割形は cactus.c のように直前の呼び出しで &sprite がレジスタに載っている場合に出るが, この関数にはその文脈がない
NON_MATCH s32 Entity3361_Update(Entity3361* p) {
#ifdef NONMATCHING_C
  Entity3361_PollMessages(p);
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
    MsgQueue_EndWait(&p->msgQueue, 1);
    KillEntity((Entity*)p);
  }
  return 0;
#else
  INCFUNC("asm/func/Entity3361_Update.inc");
#endif
}

s32 Entity3361_Destroy(Entity3361* p) {
  MsgQueue_Unregister(&p->msgQueue);
  AuxSprite_Remove(&p->sprite);
  return 0;
}

// 受け口を登録し, '.p'/'.R'/'.s' からスプライトの位置・優先度・拡大率を決める
s32 Entity3361_Init(Entity3361* p, u32 id, u32 _) {
  AuxSprite* spr;
  AuxSpriteGfx* gfx;
  u32 priority;

  p->id = id;
  MsgQueue_Register(&p->msgQueue, p->id, 10);
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
    p->scaleStart = 0x40;
    p->scaleStep = 2;
  }
  p->scale = p->scaleStart;
  spr = &p->sprite;
  gfx = &p->gfx;
  Video_GetAuxSprite(gfx, SPRITE_3641);
  AuxSprite_Add(spr, gfx, 2);
  Video_SetAuxSpritePltt(gfx, 50);
  spr->poseIdx = 0;
  spr->scaleY = spr->scaleX = p->scale;
  p->sprite.flags |= SPRFLAG_AFFINE;
  spr->priority = priority;
  spr->pos = p->pos;
  p->frameCounter = 0;
  p->killRequested = FALSE;
  p->updateCallback = Entity3361_UpdateIdle;
  return 0;
}

Entity3361* Entity3361_Create(u32 id, u32 param_2) {
  Entity3361* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity3361));

  if (p != NULL) {
    SetEntityRoutine(p, Entity3361_Update, Entity3361_Destroy);
    if (Entity3361_Init(p, id, param_2) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
