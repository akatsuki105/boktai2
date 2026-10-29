#include "camera.h"
#include "camera_inline.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "sound.h"
#include "sprite.h"
#include "video.h"
#include "vm.h"

// 燭台のロウソク, エンチャントフレイム or 点火用のレバースイッチを叩くと点火する
typedef struct {
  u8 index;            // 0x00, 0〜3, 親のビットマスクの位置とアニメ番号 index+2 を兼ねる
  u8 state;            // 0x01, 0 消灯, 1 点灯
  bool8 stateEntered;  // 0x02, state を変えた直後だけ立つ
  u8 hideTimer;        // 0x03, 0 でない間 hitbox を隠し, 0 になったら戻す
  s32 timer;           // 0x04, state を変えるたびに 0 に戻る
  HitboxData hitbox;   // 0x08, flags 0x4001, ignoreMask 0x10, 半径は index 1,2 が {0x18, 0x100, 0x60} で他が {0x60, 0x100, 0x18}
  MainSprite sprite;   // 0x58
} Entity5DA5Elem;
static_assert(sizeof(Entity5DA5Elem) == 184);

// ドゥネイル戦の燭台 (4本の腕を持つシャンデリア, 4本全部点くとスクリプトが走る)
typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_10
  u16 id;                   // 0x018
  u16 scriptID;             // 0x01A, '.p=0', 全点灯か全消灯になったときに実行する
  u16 litMask;              // 0x01C, 点灯中の要素のビット, 下位4bit
  u8 unk_1e;                // 0x01E, 0 を書くだけ
  u8 unk_1f;                // 0x01F, 0 を書くだけ
  u32 unk_20;               // 0x020, 0 を書くだけ
  u32 scriptArgs[4];        // 0x024, '.a'
  u16 litBits;              // 0x034, 点いた要素のビット
  u16 unlitBits;            // 0x036, 消えた要素のビット
  u16 changedBits;          // 0x038, 点灯と消灯のどちらでも立つ変化したビット
  u8 unk_3a[2];             // 0x03A, 触られていない
  Vec3 pos;                 // 0x03C, '.P', 判定の基準位置
  Vec3 screenPos;           // 0x044, pos を等角投影してカメラ分を引いた画面座標
  MainSpriteGfx gfx;        // 0x04C, SPRITE_CHANDELIER
  MainSprite sprite;        // 0x06C, ->gfx
  Entity5DA5Elem elems[4];  // 0x0CC
} Entity5DA5;
static_assert(sizeof(Entity5DA5) == 940);

static Entity5DA5* gEntity5DA5;  // 0x03000038

void FUN_08015ce0(s32 count, u32 kind, u32 flags, u32 animSpeed, u32 angleXZ, u32 angleXZRand, u32 speedXZ, s32 speedXZRand, u32 speedY, s32 speedYRand, WorldPos* pos);

// 要素ごとのロウソクの位置の x と z のずれ
void BgMapScroller_PushCmd(s32 bgIdx, s32 kind, s32 argc, u32* argv);
s32 Entity5DA5_SetState(s32 index, s32 state, s32 notify);

const s16 s16_ARRAY_085aa690[4] = {0, 128, -128, 0};  // 0x085aa690
const s16 s16_ARRAY_085aa698[4] = {-128, 0, 0, 128};  // 0x085aa698

void Entity5DA5Elem_SetState(Entity5DA5Elem* p, u32 state) {
  p->state = state;
  p->timer = 0;
  p->stateEntered = TRUE;
}

bool32 Entity5DA5Elem_ConsumeStateEntered(Entity5DA5Elem* p) {
  if (p->stateEntered != 0) {
    p->stateEntered = FALSE;
    return TRUE;
  }
  return FALSE;
}

// 炎で点け, 氷で消す
void Entity5DA5Elem_OnHit(HitboxData* a, HitboxData* b, Entity5DA5Elem* owner) {
  Entity5DA5* p = gEntity5DA5;

  if (p == NULL) {
    return;
  }
  if (owner->state == 0) {
    if (Hitbox_TestAttr(a, HBATTR_FLAME)) {
      Entity5DA5Elem_SetState(owner, 1);
      p->litBits |= 1 << owner->index;
      p->changedBits |= 1 << owner->index;
    }
  } else if (owner->state == 1) {
    if (Hitbox_TestAttr(a, HBATTR_FROST)) {
      Entity5DA5Elem_SetState(owner, 0);
      p->unlitBits |= 1 << owner->index;
      p->changedBits |= 1 << owner->index;
    }
  }
}

// 原典は sprite のポインタから 0x50 引いて hitbox を作り同じレジスタを使い回す, 退避レジスタが 1 本少ない (6 hunk)
NON_MATCH s32 Entity5DA5Elem_Init(Entity5DA5* p, Entity5DA5Elem* elem, s32 index) {
#ifdef NONMATCHING_C
  MainSprite* sprite;
  HitboxData* hitbox;
  Vec3 halfSize, offset;

  elem->index = index;
  Entity5DA5Elem_SetState(elem, 0);
  elem->hideTimer = 0;
  sprite = &elem->sprite;
  MainSprite_Add(sprite, &p->gfx, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 2, PLAYMODE_PAUSE, 60, &p->screenPos);
  MainSprite_SetAnim(sprite, &p->gfx, index + 2, PLAYMODE_LOOP, 0);
  hitbox = hitbox;
  if (index == 1 || index == 2) {
    VEC3_SET(halfSize, Q8(0.094), Q8(1), Q8(0.375));
  } else {
    VEC3_SET(halfSize, Q8(0.375), Q8(1), Q8(0.094));
  }
  VEC3_SET(offset, (s16_ARRAY_085aa690[index] >> 1) - 16, Q8(1), s16_ARRAY_085aa698[index] >> 1);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetHandler(hitbox, Entity5DA5Elem_OnHit, elem);
  Hitbox_SetPos(hitbox, &p->pos, 0);
  Hitbox_Register(hitbox);
  return 0;
#else
  INCFUNC("asm/func/Entity5DA5Elem_Init.inc");
#endif
}

// index の要素が state に変わったことをスクリプトに知らせる, 全部が同じ状態になったかも渡す
void Entity5DA5_RunScript(Entity5DA5* p, s32 state, u32 index) {
  u32 argv[8];
  ScriptArgs args;

  if (p->scriptID != 0) {
    argv[0] = index;
    if (state == 1) {
      argv[1] = state;
      if ((p->litMask & 0xF) == 0xF) {
        argv[2] = 1;
      } else {
        argv[2] = 0;
      }
    } else if (state == 0) {
      argv[1] = state;
      if ((p->litMask & 0xF) == 0) {
        argv[2] = 1;
      } else {
        argv[2] = 0;
      }
    }
    argv[3] = (p->changedBits >> index) & 1;
    argv[4] = p->scriptArgs[0];
    argv[5] = p->scriptArgs[1];
    argv[6] = p->scriptArgs[2];
    argv[7] = p->scriptArgs[3];
    args.argc = 8, args.argv = argv;
    VM_ExecByID(p->scriptID, &args);
  }
}

// state 0 (消灯) の更新, 入場時に隠して litMask から自分のビットを落とし, ロウソクの位置に煙を出す
// 原典は z 側の表を別のプール定数で引き, 表を先に読んでから pos を読む, r7 を使わない (6 hunk), [i+4] / 2次元 / 別配列 / 加算順は試済
NON_MATCH void Entity5DA5Elem_UpdateUnlit(Entity5DA5* p, Entity5DA5Elem* elem) {
#ifdef NONMATCHING_C
  if (Entity5DA5Elem_ConsumeStateEntered(elem)) {
    WorldPos pos;

    elem->sprite.flags |= SPRFLAG_HIDDEN;
    p->litMask &= ~(1 << elem->index);
    pos.x = s16_ARRAY_085aa690[elem->index] + p->pos.x;
    pos.y = p->pos.y + 0x100;
    pos.z = s16_ARRAY_085aa698[elem->index] + p->pos.z;
    FUN_08015ce0(1, 2, 0x2001, 0x40, 0, 0, 0, 0, 4, 2, &pos);
  }
#else
  INCFUNC("asm/func/Entity5DA5Elem_UpdateUnlit.inc");
#endif
}

// state 1 (点灯) の更新, 入場時に見せて litMask に自分のビットを立てる
void Entity5DA5Elem_UpdateLit(Entity5DA5* p, Entity5DA5Elem* elem) {
  if (Entity5DA5Elem_ConsumeStateEntered(elem)) {
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->litMask |= 1 << elem->index;
  }
  elem->sprite.pos = p->screenPos;
  MainSprite_AdvanceAnim(&elem->sprite, &p->gfx);
}

void (*const PTR_ARRAY_085aa6a0[2])(Entity5DA5*, Entity5DA5Elem*) = {
    Entity5DA5Elem_UpdateUnlit,
    Entity5DA5Elem_UpdateLit,
};  // 0x085AA6A0

const u8 u8_ARRAY_085aa6a8[4] = {11, 12, 11, 10};  // 0x085aa6a8

// 原典は最後の return を書き忘れている
s32 Entity5DA5_Update(Entity5DA5* p) {
  Entity5DA5Elem* elem;
  s32 i;

  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, FLAG030047A4_GAMEOVER)) {
    Entity5DA5_SetState(-1, 0, 1);
  }
  WorldToScreen(&p->screenPos, &p->pos);
  elem = p->elems;
  for (i = 0; i < 4; i++, elem++) {
    PTR_ARRAY_085aa6a0[elem->state](p, elem);
    Hitbox_SetPos(&elem->hitbox, &p->pos, 0);
    if (elem->hideTimer) {
      if (--elem->hideTimer == 0) {
        elem->hitbox.flags &= ~HBFLAG_HIDDEN;
      } else {
        elem->hitbox.flags |= HBFLAG_HIDDEN;
      }
    }
    elem->timer++;
  }
  if ((p->litMask & 0xF) == 0xF) {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    MainSprite_AdvanceAnim(&p->sprite, &p->gfx);
    p->sprite.pos = p->screenPos;
    if (p->sprite.animEvents & MAIN_ANIM_EVENT_ADVANCED) {
      u32 argv[2];

      argv[0] = 16;
      argv[1] = u8_ARRAY_085aa6a8[p->sprite.animCmdIdx & 3];
      BgMapScroller_PushCmd(1, 2, 2, argv);
      SET_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    }
  } else {
    CLEAR_FLAGS(gStagedDISPCNT, DISPCNT_BG1_ON);
    p->sprite.flags |= SPRFLAG_HIDDEN;
  }
  if (p->litBits) {
    PlaySound_082406e0(SONG_331);
    for (i = 0; i < 4; i++) {
      if ((p->litBits >> i) & 1) {
        Entity5DA5_RunScript(p, 1, i);
      }
    }
  }
  if (p->unlitBits) {
    for (i = 0; i < 4; i++) {
      if ((p->unlitBits >> i) & 1) {
        Entity5DA5_RunScript(p, 0, i);
      }
    }
  }
  p->litBits = 0;
  p->unlitBits = 0;
  p->changedBits = 0;
}

// 原典は return を書き忘れている
s32 Entity5DA5_Destroy(Entity5DA5* p) {
  Entity5DA5Elem* elem;
  s32 i;

  MainSprite_Remove(&p->sprite);

  elem = &p->elems[0];
  for (i = 0; i < 4; i++, elem++) {
    Hitbox_Unregister(&elem->hitbox);
    MainSprite_Remove(&elem->sprite);
  }
  gEntity5DA5 = NULL;
}

// 原典は最後の return を書き忘れている
s32 Entity5DA5_Init(Entity5DA5* p, u32 id) {
  MainSpriteGfxFile* f;
  Entity5DA5Elem* elem;
  s32 i;

  gEntity5DA5 = p;
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_CHANDELIER);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);
  p->id = id;
  p->scriptID = VM_GetNamedArgValue('p', 0);
  p->litMask = 0;
  p->unk_1e = 0;
  p->unk_1f = 0;
  p->unk_20 = 0;
  if (VM_SeekToNamedArg('a')) {
    for (i = 0; i < 4; i++) {
      if (VM_GetPC()) {
        p->scriptArgs[i] = VM_GetValue();
      }
    }
  }
  if (VM_SeekToNamedArg('P')) {
    VEC3_SET(p->pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(p->pos, 0, 0, 0);
  }
  WorldToScreen(&p->screenPos, &p->pos);
  MainSprite_Add(&p->sprite, &p->gfx, 0, SPRFLAG_SCREEN_COORD | SPRFLAG_HIDDEN, 2, PLAYMODE_PAUSE, 60, &p->screenPos);
  MainSprite_SetAnim(&p->sprite, &p->gfx, 6, PLAYMODE_LOOP, 0);
  elem = p->elems;
  for (i = 0; i < 4; i++, elem++) {
    Entity5DA5Elem_Init(p, elem, i);
  }
}

Entity5DA5* Entity5DA5_Create(u32 id) {
  if (gEntity5DA5 == NULL) {
    Entity5DA5* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity5DA5));

    if (p != NULL) {
      SetEntityRoutine(p, Entity5DA5_Update, Entity5DA5_Destroy);
      if (Entity5DA5_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity5DA5;
}

// index の要素 (負なら全部) を state にする, notify が立っていれば changedBits にも記録する, 原典は最後の return を書き忘れている
s32 Entity5DA5_SetState(s32 index, s32 state, s32 notify) {
  Entity5DA5* p = gEntity5DA5;
  Entity5DA5Elem* elem;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  if (index < 0) {
    elem = p->elems;
    for (i = 0; i < 4; i++, elem++) {
      if (elem->state != state) {
        Entity5DA5Elem_SetState(elem, state);
        if (state == 0) {
          p->unlitBits |= 1 << i;
        } else {
          p->litBits |= 1 << i;
        }
        if (notify) {
          p->changedBits |= 1 << i;
        }
      }
    }
  } else {
    elem = &p->elems[index];
    if (elem->state != state) {
      Entity5DA5Elem_SetState(elem, state);
      if (state == 0) {
        p->unlitBits |= 1 << index;
      } else {
        p->litBits |= 1 << index;
      }
      if (notify) {
        p->changedBits |= 1 << index;
      }
    }
  }
}

s32 Entity5DA5_SetStateScripted(void) {
  s32 index = VM_GetNamedArgValue('i', -1);
  s32 state = VM_GetNamedArgValue('m', 0);
  s32 param_3 = VM_GetNamedArgValue('d', 0);

  return Entity5DA5_SetState(index, state, param_3);
}

// 4つ全部点いていれば 1, 実体が無ければ -1
s32 Entity5DA5_AreAllLit(void) {
  Entity5DA5* p = gEntity5DA5;
  Entity5DA5Elem* elem;
  s32 lit;
  s32 i;

  if (p == NULL) {
    return -1;
  }

  lit = 0;
  elem = &p->elems[0];
  for (i = 0; i < 4; i++, elem++) {
    if (elem->state == 1) {
      lit++;
    }
  }

  return (lit == 4) ? 1 : 0;
}

// 4つ全部消えていれば 1, 実体が無ければ -1
s32 Entity5DA5_AreAllUnlit(void) {
  Entity5DA5* p = gEntity5DA5;
  Entity5DA5Elem* elem;
  s32 lit;
  s32 i;

  if (p == NULL) {
    return -1;
  }

  lit = 0;
  elem = &p->elems[0];

  for (i = 0; i < 4; i++, elem++) {
    if (elem->state == 1) {
      lit++;
    }
  }

  return (lit == 0) ? 1 : 0;
}
