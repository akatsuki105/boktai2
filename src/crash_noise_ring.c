#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"

// 飛んでいく輪っか1つ, 当たると kind の効果かモザイクをかける
typedef struct {
  bool8 active;           // 0x00
  u8 kind;                // 0x01, 0 ならプレイヤーにモザイクをかけ, それ以外はこの値で FUN_0807ad60 を呼ぶ, gfx[0] / gfx[1] の選択にも使う
  u32 timer;              // 0x04, 毎フレーム +1, 6 から lifetime - 31 まで当たり判定を出し, lifetime - 30 から点滅して (lifetime - 15 からは速く) lifetime で消える
  u16 mosaicInterval[4];  // 0x08, MosaicFader_Start の interval
  Vec3 vel;               // 0x10, 毎フレーム sprite.pos に足す, y は 0
  Hitbox hitbox;          // 0x18
  AuxSprite sprite;       // 0x68
} CrashNoiseRing;
static_assert(sizeof(CrashNoiseRing) == 148);

// クラッシュノイズの輪っか (SPR_EFF_5AFE) を最大 12 個まで飛ばす
typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx[2];       // 0x018, SPR_EFF_5AFE, [0] は kind が 0 以外, [1] は kind が 0 の輪っか用
  u32 lifetime;              // 0x050, 輪っかが消えるまでのフレーム数, 60 未満なら 60
  CrashNoiseRing elems[12];  // 0x054
} CrashNoiseRingManager;
static_assert(sizeof(CrashNoiseRingManager) == 1860);

s32 MosaicFader_Start(s32 mode, s32 objEnabled, s32 targets, u8* from, u8* to, u16* interval);

// プレイヤー0の食らい判定に当たったら, kind が 0 ならモザイクをかけ, それ以外は kind を渡して FUN_0807ad60 を呼ぶ
// 41/41命令で原典は player を r3 と r4 の2本に, elem を r5 に写して持つ, こちらは写さない
// 試済: GetPlayer inline (player の写しは揃い 40/41, elem の写しが出ない), 効果部分を elem と player を受ける inline に括る形
NON_MATCH void CrashNoiseRing_OnHit(Hitbox* a, Hitbox* b, CrashNoiseRing* elem) {
#ifdef NONMATCHING_C
  Player* player = gPlayerPtr[0];

  if (player != NULL && player->mover.id == b->id && &player->hurtbox == b) {
    if (elem->kind != 0) {
      FUN_0807ad60(player, elem->kind);
    } else {
      MosaicFader_Start(2, 1, 0x1E, player->mosaicFrom, player->mosaicTo, elem->mosaicInterval);
    }
  }
#else
  INCFUNC("asm/func/CrashNoiseRing_OnHit.inc");
#endif
}

// 輪っか1つ分のスプライトと攻撃判定を作る, 原典は return を書き忘れている
s32 CrashNoiseRing_Init(CrashNoiseRingManager* p, CrashNoiseRing* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;
  Vec3* pos;
  Hitbox* hitbox;
  Vec3 size, offset;

  AuxSprite_Setup(sprite, &p->gfx[0], 1);
  sprite->priority = 1;
  pos = &elem->sprite.pos;
  Vec3_Clear(pos);

  hitbox = &elem->hitbox;
  VEC3_SET(size, 100, 100, 100);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(hitbox, 0, HBF_HITBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetPos(hitbox, pos, 0);
  Hitbox_SetHandler(hitbox, CrashNoiseRing_OnHit, elem);
  Hitbox_SetAttack(hitbox, 50, 30, 0, 0, 30);
}

// 使用中なら輪っかを隠して外し, 枠を空ける
void CrashNoiseRingManager_Remove(CrashNoiseRingManager* p, CrashNoiseRing* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->active) {
    sprite->flags |= SPRFLAG_HIDDEN;
    AuxSprite_Remove(sprite);
    elem->active = FALSE;
  }
}

// 輪っかを飛ばしてポーズを回し, しばらく攻撃判定を出してから (バットには当てない) 点滅して消す
s32 CrashNoiseRingManager_Update(CrashNoiseRingManager* p) {
  CrashNoiseRing* elem = p->elems;
  s32 i;

  for (i = 0; i < 12; i++, elem++) {
    if (elem->active) {
      AuxSprite* sprite = &elem->sprite;
      Hitbox* hitbox = &elem->hitbox;

      if (elem->timer < 20) {
        if (elem->timer == 0) {
          AuxSprite_SetPoseIdx(sprite, 2);
        } else if (elem->timer == 5) {
          AuxSprite_SetPoseIdx(sprite, 1);
        } else if (elem->timer == 10) {
          AuxSprite_SetPoseIdx(sprite, 3);
        } else if (elem->timer == 15) {
          AuxSprite_SetPoseIdx(sprite, 0);
        }
      } else {
        u32 t = (elem->timer - 20) & 7;

        if (t == 3) {
          AuxSprite_SetPoseIdx(sprite, 3);
        } else if (t == 7) {
          AuxSprite_SetPoseIdx(sprite, 0);
        }
      }
      Vec3_Add(&sprite->pos, &elem->vel);
      if (elem->timer < p->lifetime - 30) {
        if (elem->timer > 5 && (gPlayerPtr[0] == NULL || gPlayerPtr[0]->kind != PLAYER_BAT)) {
          Hitbox_SetPos(hitbox, &sprite->pos, 0);
          Hitbox_Register(hitbox);
        }
      } else if (elem->timer < p->lifetime - 15) {
        if ((elem->timer & 3) == 0) {
          AuxSprite_SetFlags(sprite, SPRFLAG_HIDDEN);
        } else {
          AuxSprite_Show(sprite);
        }
      } else if (elem->timer < p->lifetime) {
        if ((elem->timer & 3) <= 1) {
          AuxSprite_SetFlags(sprite, SPRFLAG_HIDDEN);
        } else {
          AuxSprite_Show(sprite);
        }
      } else {
        CrashNoiseRingManager_Remove(p, elem, i);
      }
      elem->timer++;
    }
  }
  return 0;
}

s32 CrashNoiseRingManager_Destroy(CrashNoiseRingManager* p) {
  CrashNoiseRing* elem = p->elems;
  s32 i;

  for (i = 0; i < 12; i++, elem++) {
    CrashNoiseRingManager_Remove(p, elem, i);
  }
  return 0;
}

s32 CrashNoiseRingManager_Init(CrashNoiseRingManager* p, u32 lifetime) {
  CrashNoiseRing* elem;
  s32 i;

  p->lifetime = lifetime;
  if (lifetime < 60) {
    p->lifetime = 60;
  }
  for (i = 0; i < 2; i++) {
    Video_GetAuxSprite(&p->gfx[i], SPR_EFF_5AFE);
  }
  Video_SetAuxSpritePltt(&p->gfx[0], 9);
  Video_SetAuxSpritePltt(&p->gfx[1], 17);
  elem = p->elems;
  for (i = 0; i < 12; i++, elem++) {
    CrashNoiseRing_Init(p, elem, i);
  }
  return 0;
}

// 使われていない輪っかを先頭から探す, 無ければ NULL
CrashNoiseRing* CrashNoiseRingManager_FindFree(CrashNoiseRingManager* p) {
  CrashNoiseRing* elem = p->elems;
  s32 i;

  for (i = 0; i < 12; i++, elem++) {
    if (!elem->active) {
      return elem;
    }
  }
  return NULL;
}

CrashNoiseRingManager* CrashNoiseRingManager_Create(u32 lifetime) {
  CrashNoiseRingManager* p = CreateEntity(ENTITY_UNK_8, sizeof(CrashNoiseRingManager));

  if (p != NULL) {
    SetEntityRoutine(p, CrashNoiseRingManager_Update, CrashNoiseRingManager_Destroy);
    if (CrashNoiseRingManager_Init(p, lifetime) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 空いている枠に輪っかを1つ出し, pos から angle の向きへ speed で飛ばす, 枠がなければ -1, 原典は最後の return を書き忘れている
// 132/132命令, 残差は p を r7 へ写す命令の位置だけ, 原典は speed と power を写した後, こちらは先頭で写す
// 試済: !p, null 判定を入れ子にする形, sprite と hitbox を取る順, 効いた手: 引数は s32 のまま, gfx の選択は elem->kind で判定
NON_MATCH s32 CrashNoiseRingManager_Spawn(CrashNoiseRingManager* p, s32 angle, s32 speed, s32 power, s32 knockback, s32 iframes, s32 kind, s32 mosaicInterval, Vec3* pos) {
#ifdef NONMATCHING_C
  CrashNoiseRing* elem;
  AuxSprite* sprite;
  Hitbox* hitbox;

  if (p == NULL) {
    return -1;
  }
  elem = CrashNoiseRingManager_FindFree(p);
  sprite = &elem->sprite;
  hitbox = &elem->hitbox;
  if (elem == NULL) {
    return -1;
  }
  Vec3_SetPolar(&elem->vel, angle, speed);
  sprite->poseIdx = 2;
  sprite->pos = *pos;
  sprite->flags &= ~SPRFLAG_HIDDEN;
  Video_AddAuxSpriteIntoDrawList(sprite, 0);
  Hitbox_SetAttack(hitbox, power, knockback, 0, 0, iframes);
  elem->kind = kind;
  elem->mosaicInterval[0] = mosaicInterval;
  elem->mosaicInterval[1] = mosaicInterval;
  elem->mosaicInterval[2] = mosaicInterval;
  elem->mosaicInterval[3] = mosaicInterval;
  if (elem->kind != 0) {
    AuxSprite_SetGfx(sprite, &p->gfx[0]);
  } else {
    AuxSprite_SetGfx(sprite, &p->gfx[1]);
  }
  elem->timer = 0;
  elem->active = TRUE;
  PlaySound_082406e0(SONG_865);
#else
  INCFUNC("asm/func/CrashNoiseRingManager_Spawn.inc");
#endif
}
