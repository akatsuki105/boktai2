#include "constants/sprite.h"
#include "eff_scatter.h"
#include "entity.h"
#include "global.h"
#include "sprite_aux.h"
#include "vec3.h"

// SPR_OJAMA_BAT を使うのでオジャマバット用のエンティティ (つまりクロスオーバーのEntity)
// pos に出て 8 フレームかけて横に広がりながら上がり, 20 フレームで消えて粒子を散らす1枚
typedef struct {
  u8 mode;           // 0x00, 1 なら毎フレーム src の位置に付いていく, 0 なら src を持たず出した位置に留まる
  bool8 active;      // 0x01, 0 以外の間だけ _Update が処理する
  u8 unk_02[2];      // 0x02
  u32 timer;         // 0x04, 20 に達すると sprite を隠して active を落とし粒子を出す
  Vec3 pos;          // 0x08, src の写し
  Vec3* src;         // 0x10, 追従する位置
  AuxSprite sprite;  // 0x14, pos.y + timer * 0x40 の高さに出る, scaleX は timer * 2 + 1
} OjamaBatPopup;
static_assert(sizeof(OjamaBatPopup) == 64);

// SPR_OJAMA_BAT を使うのでオジャマバット用のエンティティ (つまりクロスオーバーのEntity)
typedef struct OjamaBatPopupManager {
  Entity e;                     // 0x000, ENTITY_UNK_11
  AuxSpriteGfx gfx;             // 0x018, SPR_OJAMA_BAT
  OjamaBatPopup elems[4];  // 0x034
} OjamaBatPopupManager;
static_assert(sizeof(OjamaBatPopupManager) == 308);

const u8 sOjamaBatPopupScatterKinds[4] = {SCATTER_DARK_S, SCATTER_FROST_L, SCATTER_KIND_18, 33};  // 0x085AB73C, 消えるときに散らす粒子の種類, [0] しか使われない

void OjamaBatPopup_Init(OjamaBatPopupManager* p, OjamaBatPopup* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;

  AuxSprite_Add(sprite, &p->gfx, SPRFLAG_HIDDEN | SPRFLAG_AFFINE);
  sprite->priority = 0;
  Vec3_Clear(&elem->sprite.pos);
}

void OjamaBatPopup_Destroy(OjamaBatPopupManager* p, OjamaBatPopup* elem, s32 idx) { AuxSprite_Remove(&elem->sprite); }

// 8 フレームかけて横に広がりながら上がり, 20 フレーム経ったら消して粒子を散らす
void OjamaBatPopup_Update(OjamaBatPopupManager* p, OjamaBatPopup* elem, s32 idx) {
  AuxSprite* sprite = &elem->sprite;

  if (elem->src != NULL) {
    elem->pos = *elem->src;
  }
  if (elem->timer < 8) {
    sprite->pos.y = elem->timer * 64 + elem->pos.y;
    sprite->scaleX = elem->timer * 2 + 1;
  } else {
    sprite->scaleX = 64;
  }
  if (elem->timer >= 20) {
    sprite->flags |= SPRFLAG_HIDDEN;
    elem->active = FALSE;
    ScatterEffect_SpawnAtAngle(7, sOjamaBatPopupScatterKinds[0], &sprite->pos, 0, 0xFF, 12, 4, 0, 0, 16, 8);
  } else {
    elem->timer++;
  }
}

s32 OjamaBatPopupManager_Update(OjamaBatPopupManager* p) {
  OjamaBatPopup* elem = p->elems;
  s32 i;

  for (i = 0; i < 4; i++, elem++) {
    if (elem->active) {
      OjamaBatPopup_Update(p, elem, i);
    }
  }
  return 0;
}

s32 OjamaBatPopupManager_Destroy(OjamaBatPopupManager* p) {
  OjamaBatPopup* elem = p->elems;
  s32 i;

  for (i = 0; i < 4; i++, elem++) {
    OjamaBatPopup_Destroy(p, elem, i);
  }
  return 0;
}

s32 OjamaBatPopupManager_Init(OjamaBatPopupManager* p) {
  OjamaBatPopup* elem;
  s32 i;

  Video_GetAuxSprite(&p->gfx, SPR_OJAMA_BAT);
  elem = p->elems;
  for (i = 0; i < 4; i++, elem++) {
    OjamaBatPopup_Init(p, elem, i);
  }
  return 0;
}

OjamaBatPopupManager* OjamaBatPopupManager_Create(void) {
  OjamaBatPopupManager* p = CreateEntity(ENTITY_UNK_11, sizeof(OjamaBatPopupManager));

  if (p != NULL) {
    SetEntityRoutine(p, OjamaBatPopupManager_Update, OjamaBatPopupManager_Destroy);
    if (OjamaBatPopupManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// idx 番の枠に idx 番のポーズで1枚出す, mode 1 なら pos を追い, 0 なら出した位置に留まる
void OjamaBatPopupManager_Spawn(OjamaBatPopupManager* p, u32 idx, u32 mode, Vec3* pos) {
  OjamaBatPopup* elem;
  AuxSprite* sprite;

  if (p == NULL) {
    return;
  }
  elem = &p->elems[idx];
  sprite = &elem->sprite;
  elem->mode = mode;
  elem->timer = 0;
  sprite->poseIdx = idx;
  sprite->scaleX = 1;
  sprite->flags &= ~SPRFLAG_HIDDEN;
  if (elem->mode == 0) {
    elem->src = NULL;
  } else if (elem->mode == 1) {
    elem->src = pos;
  }
  elem->pos = *pos;
  sprite->pos = *pos;
  elem->active = TRUE;
}
