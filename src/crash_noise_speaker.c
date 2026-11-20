#include "boss/shademan.h"
#include "entity.h"
#include "global.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "vec3.h"

void AuxSprite_SetGfxPtr(AuxSprite* p, AuxSpriteGfx* gfx);
struct CrashNoiseRingManager* CrashNoiseRingManager_Create(u32 lifetime);
s32 CrashNoiseRingManager_Spawn(struct CrashNoiseRingManager* p, s32 angle, s32 speed, s32 power, s32 knockback, s32 iframes, s32 kind, s32 mosaicInterval, Vec3* pos);

// state を切り替える, 次の更新で新しい state の初期化をする
static inline void CrashNoiseSpeaker_SetState(CrashNoiseSpeaker* elem, s32 state) {
  elem->state = state;
  elem->stateBegun = TRUE;
  elem->timer = 0;
}

// スピーカー1つ分のスプライトを作り, 空き枠にしておく, 原典は return を書き忘れている
s32 CrashNoiseSpeaker_Init(CrashNoiseSpeakerManager* p, CrashNoiseSpeaker* elem, s32 idx) {
  AuxSprite* sprite;

  elem->state = 0;
  elem->stateBegun = TRUE;
  elem->timer = 0;
  sprite = &elem->sprite;
  AuxSprite_Setup(sprite, &p->gfx[0], 1);
  sprite->priority = 3;
  Vec3_Clear(&elem->sprite.pos);
}

// 使用中ならスピーカーを隠して外し, 枠を空ける
void CrashNoiseSpeakerManager_Remove(CrashNoiseSpeakerManager* p, CrashNoiseSpeaker* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->active) {
    elem->state = 0;
    elem->stateBegun = TRUE;
    elem->timer = 0;
    sprite->flags |= SPRFLAG_HIDDEN;
    AuxSprite_Remove(sprite);
    elem->active = FALSE;
  }
}

void CrashNoiseSpeaker_StateIdle(CrashNoiseSpeakerManager* p, CrashNoiseSpeaker* elem, s32 idx) {}

// パレットを点滅させながら開くポーズを順に見せて現れ, 30 フレームで震えに移る
void CrashNoiseSpeaker_StateAppear(CrashNoiseSpeakerManager* p, CrashNoiseSpeaker* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    sprite->poseIdx = 2;
    PlaySound_082406e0(SONG_864);
  }
  if (elem->timer == 5) {
    sprite->poseIdx = 1;
  } else if (elem->timer == 10) {
    sprite->poseIdx = 0;
  }
  if (elem->timer < 10) {
    if ((elem->timer & 3) == 0) {
      AuxSprite_SetGfxPtr(sprite, &p->gfx[1]);
    } else {
      AuxSprite_SetGfxPtr(sprite, &p->gfx[0]);
    }
  } else if (elem->timer < 20) {
    if ((elem->timer & 3) < 2) {
      AuxSprite_SetGfxPtr(sprite, &p->gfx[1]);
    } else {
      AuxSprite_SetGfxPtr(sprite, &p->gfx[0]);
    }
  } else {
    AuxSprite_SetGfxPtr(sprite, &p->gfx[1]);
  }
  if (elem->timer > 29) {
    AuxSprite_SetGfxPtr(sprite, &p->gfx[0]);
    CrashNoiseSpeaker_SetState(elem, 3);
  } else {
    elem->timer++;
  }
}

// 次に撃つまで 50 フレーム待ち, 震えに移る
void CrashNoiseSpeaker_StateWait(CrashNoiseSpeakerManager* p, CrashNoiseSpeaker* elem, s32 idx) {
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
  }
  if (elem->timer == 50) {
    CrashNoiseSpeaker_SetState(elem, 3);
  } else {
    elem->timer++;
  }
}

// 10 フレームの間 pos の周りで小刻みに震え, 40 フレームで撃ち始める
void CrashNoiseSpeaker_StateShake(CrashNoiseSpeakerManager* p, CrashNoiseSpeaker* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
  }
  if (elem->timer < 10) {
    sprite->pos = elem->pos;
    sprite->pos.x += (RandomNext() & 7) - 4;
    sprite->pos.z += (RandomNext() & 7) - 4;
  } else if (elem->timer == 10) {
    sprite->pos = elem->pos;
  }
  if (elem->timer == 40) {
    CrashNoiseSpeaker_SetState(elem, 4);
  } else {
    elem->timer++;
  }
}

// 入ったときに 1P への向きを決めて 16 フレームごとに輪っかを撃ち, shotsPerVolley 発撃ったら待ちに戻る, volleyMax 回撃ったら消える
// 93/93命令, 残差は乱数表と angle と volleyMax を載せるレジスタ番号だけ (原典は r2/r3/r2, こちらは r1/r2/r3)
// Tier A-C 試済 (式の順, 条件の入れ子と rings ローカル, angle ローカル, state 選択の三項演算子), 未: Random の別形
NON_MATCH void CrashNoiseSpeaker_StateFire(CrashNoiseSpeakerManager* p, CrashNoiseSpeaker* elem, s32 idx) {
#ifdef NONMATCHING_C
  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    if (gPlayerPtr[0] != NULL) {
      elem->angle = ArcTan2_8(gPlayerPtr[0]->mover.pos.x - elem->pos.x, gPlayerPtr[0]->mover.pos.z - elem->pos.z);
    }
  }
  if ((elem->timer & 15) == 15 && p->rings != NULL) {
    CrashNoiseRingManager_Spawn(p->rings, (Random() & 15) + elem->angle - 8, elem->speed, elem->power, elem->knockback, elem->iframes, elem->kind, 0, &elem->pos);
  }
  if (elem->timer == elem->shotsPerVolley * 16) {
    if (++elem->volleyCount < elem->volleyMax) {
      CrashNoiseSpeaker_SetState(elem, 2);
    } else {
      CrashNoiseSpeaker_SetState(elem, 5);
    }
  } else {
    elem->timer++;
  }
#else
  INCFUNC("asm/func/CrashNoiseSpeaker_StateFire.inc");
#endif
}

// 縮むポーズを順に見せてから枠を空ける
void CrashNoiseSpeaker_StateDisappear(CrashNoiseSpeakerManager* p, CrashNoiseSpeaker* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->stateBegun) {
    elem->stateBegun = FALSE;
    sprite->poseIdx = 0;
  }
  switch (elem->timer) {
    case 10: {
      sprite->poseIdx = 2;
      CrashNoiseSpeakerManager_Remove(p, elem, idx);
      return;
    }
    case 5: {
      sprite->poseIdx = 1;
      break;
    }
  }
  elem->timer++;
}

s32 CrashNoiseSpeakerManager_Update(CrashNoiseSpeakerManager* p) {
  static void (*const sCrashNoiseSpeakerStates[6])(CrashNoiseSpeakerManager*, CrashNoiseSpeaker*, s32) = {
      CrashNoiseSpeaker_StateIdle,
      CrashNoiseSpeaker_StateAppear,
      CrashNoiseSpeaker_StateWait,
      CrashNoiseSpeaker_StateShake,
      CrashNoiseSpeaker_StateFire,
      CrashNoiseSpeaker_StateDisappear,
  };  // 0x085ABA70

  CrashNoiseSpeaker* elem = p->elems;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    if (elem->active) {
      sCrashNoiseSpeakerStates[elem->state](p, elem, i);
    }
  }
  return 0;
}

s32 CrashNoiseSpeakerManager_Destroy(CrashNoiseSpeakerManager* p) {
  CrashNoiseSpeaker* elem = p->elems;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    CrashNoiseSpeakerManager_Remove(p, elem, i);
  }
  return 0;
}

s32 CrashNoiseSpeakerManager_Init(CrashNoiseSpeakerManager* p, u32 ringLifetime) {
  CrashNoiseSpeaker* elem;
  s32 i;

  p->ringLifetime = ringLifetime;
  for (i = 0; i < 2; i++) {
    Video_GetAuxSprite(&p->gfx[i], SPR_SPEAKER);
  }
  Video_SetAuxSpritePltt(&p->gfx[0], 9);
  Video_SetAuxSpritePltt(&p->gfx[1], 10);
  elem = p->elems;
  for (i = 0; i < 8; i++, elem++) {
    CrashNoiseSpeaker_Init(p, elem, i);
  }
  p->rings = CrashNoiseRingManager_Create(p->ringLifetime);
  return 0;
}

CrashNoiseSpeakerManager* CrashNoiseSpeakerManager_Create(u32 ringLifetime) {
  CrashNoiseSpeakerManager* p = CreateEntity(ENTITY_UNK_8, sizeof(CrashNoiseSpeakerManager));

  if (p != NULL) {
    SetEntityRoutine(p, CrashNoiseSpeakerManager_Update, CrashNoiseSpeakerManager_Destroy);
    if (CrashNoiseSpeakerManager_Init(p, ringLifetime) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

CrashNoiseSpeaker* CrashNoiseSpeakerManager_FindFree(CrashNoiseSpeakerManager* p) {
  CrashNoiseSpeaker* elem = p->elems;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    if (!elem->active) {
      return elem;
    }
  }
  return NULL;
}

// 空き枠にスピーカーを pos に置き, 1P へ向けて輪っかを volleyMax 回撃たせる, 置けなければ -1, angle は使わない
s32 CrashNoiseSpeaker_Spawn(CrashNoiseSpeakerManager* p, u32 angle, s32 speed, s32 power, s32 knockback, s32 iframes, s32 kind, s32 shotsPerVolley, s32 volleyMax, Vec3* pos) {
  if (p != NULL) {
    CrashNoiseSpeaker* elem = CrashNoiseSpeakerManager_FindFree(p);

    if (elem != NULL) {
      AuxSprite* sprite = &elem->sprite;

      CrashNoiseSpeaker_SetState(elem, 1);
      AuxSprite_SetPoseIdx(sprite, 2);
      elem->pos = *pos;
      elem->sprite.pos = *pos;
      sprite->flags &= ~SPRFLAG_HIDDEN;
      Video_AddAuxSpriteIntoDrawList(sprite, 0);
      elem->speed = speed;
      elem->power = power;
      elem->knockback = knockback;
      elem->iframes = iframes;
      elem->kind = kind;
      elem->shotsPerVolley = shotsPerVolley;
      elem->volleyMax = volleyMax;
      elem->volleyCount = 0;
      elem->active = TRUE;
      return 0;
    }
  }
  return -1;
}

// スピーカーを置かずに pos から輪っかを1つ飛ばす, 輪っかの管理エンティティがなければ -1
s32 CrashNoiseSpeakerManager_SpawnRing(CrashNoiseSpeakerManager* p, u32 angle, s32 speed, s32 power, s32 knockback, s32 iframes, s32 kind, s32 mosaicInterval, Vec3* pos) {
  if (p != NULL && p->rings != NULL) {
    CrashNoiseRingManager_Spawn(p->rings, angle, speed, power, knockback, iframes, kind, mosaicInterval, pos);
    return 0;
  }
  return -1;
}
