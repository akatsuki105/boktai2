#include "entity.h"
#include "global.h"
#include "random.h"
#include "sprite_aux.h"

// ドヴァリンが初登場するときの水泡の演出

// 画面下から湧いて左右に揺れながら上がっていく粒, 32個を使い回す
typedef struct {
  bool8 active;      // 0x00, 立っている枠だけ動かす
  u8 riseSpeed;      // 0x01, (添字 & 1) + 3 + 乱数(0..1), 上昇量に掛かる
  s8 swayAmp;        // 0x02, ((乱数 & 3) + 5 - riseSpeed) >> 2, 左右の振れ幅
  u8 angleStep;      // 0x03, (乱数 & 7) + 1, angle に毎フレーム足す
  s8 angle;          // 0x04, gSineTable の添字, 左右の揺れと上昇量の両方に使う
  u8 unk_5;          // 0x05, 触られていない
  u16 unk_6;         // 0x06, 0 を書くだけ
  AuxSprite sprite;  // 0x08, y が -0x13 を下回ると画面下へ戻して作り直す
} CutsceneBubbleElem;
static_assert(sizeof(CutsceneBubbleElem) == 52);

typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_8
  u8 unk_18[4];                  // 0x018, 触られていない
  AuxSpriteGfx gfx;              // 0x01C, SPRITE_DVALIN_2E7B
  CutsceneBubbleElem elems[32];  // 0x038
} CutsceneBubble;
static_assert(sizeof(CutsceneBubble) == 1720);

const u8 u8_ARRAY_085aa988[4] = {8, 14, 9, 15};  // 0x085AA988

// 粒を画面下に置き直し, 上昇量・振れ幅・揺れの速さを乱数で決め直す
void CutsceneBubbleElem_Respawn(CutsceneBubble* p, CutsceneBubbleElem* elem, s32 index) {
  AuxSprite* sprite = &elem->sprite;
  s32 amp;

  sprite->flags &= ~SPRFLAG_HIDDEN;
  elem->active = TRUE;
  elem->riseSpeed = (index & 1) + 3 + (RandomNext() & 1);
  amp = (RandomNext() & 3) + 5;
  elem->swayAmp = (amp - elem->riseSpeed) >> 2;
  elem->angleStep = (RandomNext() & 7) + 1;
  elem->angle = 0;
  elem->unk_6 = 0;
  sprite->pos.x = (u8)RandomNext() - 16;
  sprite->pos.y = (RandomNext() & 0x7F) + 160;
}

void CutsceneBubbleElem_Init(CutsceneBubble* p, CutsceneBubbleElem* elem, s32 index) {
  AuxSprite* sprite = &elem->sprite;

  AuxSprite_Add(sprite, &p->gfx, SPRFLAG_HIDDEN | SPRFLAG_SCREEN_COORD);
  sprite->poseIdx = u8_ARRAY_085aa988[index & 3];
  sprite->priority = 1;
  CutsceneBubbleElem_Respawn(p, elem, index);
}

void CutsceneBubbleElem_Destroy(CutsceneBubble* p, CutsceneBubbleElem* elem, u32 index) { AuxSprite_Remove(&elem->sprite); }

// 粒を左右に揺らしながら上げ, 画面の上に抜けたら下に置き直す
// 残差はループ外に出す値の選び方だけ (95 対 97), 原典は &gRandTableIdx を退避するがこちらは比較の定数 -20 を退避する
// Random / RandomNext, 掛け算のオペランド順, dx / dy をローカルに出す形, < -19 / <= -20, y を s16 ローカルに出す形は試済
NON_MATCH s32 CutsceneBubble_Update(CutsceneBubble* p) {
#ifdef NONMATCHING_C
  CutsceneBubbleElem* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 32; i++, elem++) {
    if (elem->active) {
      AuxSprite* sprite = &elem->sprite;
      s32 angle, dx, dy;

      elem->angle += elem->angleStep + (Random() & 1);
      angle = abs(elem->angle);
      dx = (COS(angle) * elem->swayAmp) >> 12;
      dy = (((SIN(angle) >> 1) + 0x800) * elem->riseSpeed) >> 12;
      sprite->pos.x += dx;
      sprite->pos.y -= dy;
      if (sprite->pos.y <= -20) {
        CutsceneBubbleElem_Respawn(p, elem, i);
      }
    }
  }
  return 0;
#else
  INCFUNC("asm/func/CutsceneBubble_Update.inc");
#endif
}

s32 CutsceneBubble_Destroy(CutsceneBubble* p) {
  CutsceneBubbleElem* elem = &p->elems[0];
  s32 i;

  for (i = 0; i < 32; i++, elem++) {
    CutsceneBubbleElem_Destroy(p, elem, i);
  }
  return 0;
}

s32 CutsceneBubble_Init(CutsceneBubble* p) {
  CutsceneBubbleElem* elem = &p->elems[0];
  s32 i;

  Video_GetAuxSprite(&p->gfx, SPRITE_DVALIN_2E7B);
  for (i = 0; i < 32; i++, elem++) {
    CutsceneBubbleElem_Init(p, elem, i);
  }
  return 0;
}

// 0x78C9, HashName("デモ泡")
CutsceneBubble* CutsceneBubble_Create(void) {
  CutsceneBubble* p = CreateEntity(ENTITY_UNK_8, sizeof(CutsceneBubble));

  if (p != NULL) {
    SetEntityRoutine(p, CutsceneBubble_Update, CutsceneBubble_Destroy);
    if (CutsceneBubble_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
