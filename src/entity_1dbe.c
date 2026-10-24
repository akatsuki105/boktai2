#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

struct Entity1DBEElem;

typedef void(Entity1DBEElemFunc)(struct Entity1DBEElem* elem);

// 太陽エネルギーで state が入れ替わる設置物, 1体の Entity1DBE が最大8個を抱える
typedef struct Entity1DBEElem {
  AuxSprite sprite;                    // 0x000, poseIdx が見た目の段階 (state 0 は 0〜2, state 1 は 3〜5, state 2 は 6〜8)
  AuxSpriteGfx gfx;                    // 0x02C, SPRITE_TRAP_FLOOR
  Mover mover;                         // 0x048, moverLinked が立っているときだけリストに繋がれる
  HitboxData hitbox;                   // 0x08C, 半径 {0x80, 0x32, 0x80}, ignoreMask 0x10
  u8 state;                            // 0x0DC, '.s', 0/1/2 で updateCallback を選ぶ
  u8 lockFlags;                        // 0x0DD, '.f', bit0 が立つと state 2 へ, bit1 が立つと state 1 へ遷移しない
  u8 unk_de;                           // 0x0DE, 読み手も書き手も見つかっていない
  bool8 touched;                       // 0x0DF, 近くに来るか属性なしの攻撃を受けると立つ, state 0 が消費して点滅を始める
  u16 id;                              // 0x0E0, '.n', mover.id と hitbox の id を兼ねる
  u16 unk_e2;                          // 0x0E2, 状態が変わるたび 0x10 が入るが読み手が見つかっていない
  bool8 moverLinked;                   // 0x0E4, '.h', 立っていれば mover を使う
  bool8 flickering;                    // 0x0E5, touched のあと animTimer が 90 になるまで点滅する
  bool8 areaBound;                     // 0x0E6, '.m', 立っていれば zoneID が現在のエリアと一致する間だけ更新する
  bool8 unk_e7;                        // 0x0E7, 立っていると状態の振り分けをやり直して 0 に戻る, 書き手が見つかっていない
  ZoneID16 zoneID;                     // 0x0E8, GetZoneAt(sprite.pos) の結果, gStat->zoneID と比べる
  u8 unk_ea[2];                        // 0x0EA, 読み手も書き手も見つかっていない, padding?
  s16 counter;                         // 0x0EC, 日照で増え暗所で減る, ±300 を越えると state が切り替わる, state 1/2 では復帰までのフレーム数
  u16 animTimer;                       // 0x0EE, 遷移アニメと点滅のコマ送り
  Entity1DBEElemFunc* updateCallback;  // 0x0F0
} Entity1DBEElem;
static_assert(sizeof(Entity1DBEElem) == 244);

typedef struct {
  Entity e;                 // 0x000, ENTITY_UNK_9
  u16 count;                // 0x018, 使用中の elems の数, Cmd_1DBE は 8 未満のときだけ足す
  u8 unk_1a[2];             // 0x01A, padding?
  Entity1DBEElem elems[8];  // 0x01C
} Entity1DBE;
static_assert(sizeof(Entity1DBE) == 1980);

static Entity1DBE* gEntity1DBE;  // 0x03000144

void FUN_0809f64c(void) { gEntity1DBE = NULL; }

NAKED bool32 Entity1DBE_TouchElemNear(WorldPos* pos) { INCFUNC("asm/func/Entity1DBE_TouchElemNear.inc"); }

// 0xB6CE
// '.n' と id が一致する設置物の state を返す, 無ければ -1
s32 Cmd_B6CE(void) {
  s32 id;
  s32 i;

  if (gEntity1DBE == NULL) {
    return -1;
  }
  if (!VM_SeekToNamedArg('n')) {
    return -1;
  }

  id = VM_GetValue();
  for (i = 0; i < gEntity1DBE->count; i++) {
    if (gEntity1DBE->elems[i].id == id) {
      return gEntity1DBE->elems[i].state;
    }
  }
  return -1;
}

void FUN_0809f890(Entity1DBEElem* elem);
void FUN_0809fa80(Entity1DBEElem* elem);
void FUN_0809fabc(Entity1DBEElem* elem);

void Entity1DBEElem_SetState(Entity1DBEElem* elem, u8 state, Entity1DBEElemFunc* fn) {
  elem->state = state;
  elem->updateCallback = fn;
  elem->counter = 0;
  elem->animTimer = 0;
}

NAKED void Entity1DBEElem_OnHit(HitboxData* a, HitboxData* b, Entity1DBEElem* owner) { INCFUNC("asm/func/Entity1DBEElem_OnHit.inc"); }

// 日が出ている間だけ counter を進め, 0x12B を越えたら次の状態へ移る
void FUN_0809f7fc(Entity1DBEElem* elem) {
  if (gStat->sunGauge > 0) {
    elem->counter++;
    if (elem->counter > 0x12B) {
      Entity1DBEElem_SetState(elem, 0, FUN_0809f890);
    }
  }
}

void FUN_0809f840(Entity1DBEElem* elem) {
  if (elem->animTimer == 0) {
    PlaySound_082406e0(SONG_415);
  }
  elem->animTimer++;
  if (elem->animTimer <= 7) {
    elem->sprite.poseIdx = 3;
  } else if (elem->animTimer <= 0xF) {
    elem->sprite.poseIdx = 4;
  } else {
    elem->sprite.poseIdx = 5;
    Entity1DBEElem_SetState(elem, 1, FUN_0809f7fc);
  }
}

// 太陽エネルギーで state 1 へ上がる間のコマ送り
void FUN_0809f890(Entity1DBEElem* elem) {
  if (elem->animTimer == 0) {
    PlaySound_082406e0(SONG_416);
  }
  elem->animTimer++;
  if (elem->animTimer <= 7) {
    elem->sprite.poseIdx = 4;
  } else if (elem->animTimer <= 0xF) {
    elem->sprite.poseIdx = 3;
  } else {
    elem->sprite.poseIdx = 2;
    PlaySound_082406e0(SONG_416);
    Entity1DBEElem_SetState(elem, 0, FUN_0809fabc);
  }
}

// gStat->unk_934 の bit11 が立っている間だけ数え, 300 フレームで state 0 へ戻す
// 残差5命令 (27 対 32), 原典はフラグ判定の結果を 1/0 として一度作ってから改めて 0 と比べる (いわゆる 0/1 の作り置き)
// enemy_manager.c の Stat_SetFlag934 と同じ形の static inline bool32 Stat_TestFlag934(u16 bit) にすると 0x800 を先に作る並びまでは一致する
NON_MATCH void FUN_0809f8e4(Entity1DBEElem* elem) {
#ifdef NONMATCHING_C
  if (gStat->unk_934 & SF934_RAIN) {
    elem->counter++;
    if (elem->counter > 299) {
      Entity1DBEElem_SetState(elem, 0, FUN_0809fa80);
    }
  }
#else
  INCFUNC("asm/func/FUN_0809f8e4.inc");
#endif
}

NAKED void FUN_0809f938(Entity1DBEElem* elem) { INCFUNC("asm/func/FUN_0809f938.inc"); }

void FUN_0809fa80(Entity1DBEElem* elem) {
  elem->animTimer++;
  if (elem->animTimer <= 7) {
    elem->sprite.poseIdx = 7;
  } else if (elem->animTimer <= 0xF) {
    elem->sprite.poseIdx = 6;
  } else {
    elem->sprite.poseIdx = 2;
    Entity1DBEElem_SetState(elem, 0, FUN_0809fabc);
  }
}

NAKED void FUN_0809fabc(Entity1DBEElem* elem) { INCFUNC("asm/func/FUN_0809fabc.inc"); }

NAKED void Entity1DBEElem_Update(Entity1DBEElem* elem) { INCFUNC("asm/func/Entity1DBEElem_Update.inc"); }

void Entity1DBEElem_InitParams(Entity1DBEElem* elem, u32 id, Vec3* pos, u32 state, u32 lockFlags, u32 areaBound) {
  elem->id = id;
  elem->state = state;
  elem->unk_e2 = 0;
  elem->flickering = FALSE;
  elem->touched = FALSE;
  elem->lockFlags = lockFlags;
  elem->areaBound = areaBound;
  if (elem->areaBound) {
    elem->zoneID = GetZoneAt(pos);
  }
}

// スプライトを pos に立てて, '.h' が立っていれば Mover も繋ぐ
void Entity1DBEElem_InitSprite(Entity1DBEElem* elem, Vec3* pos, u32 moverLinked) {
  AuxSpriteGfx* gfx = &elem->gfx;

  Video_GetAuxSprite(gfx, SPRITE_TRAP_FLOOR);
  AuxSprite_Add(&elem->sprite, gfx, 0);
  Video_SetAuxSpritePltt(gfx, 0x43);
  elem->sprite.priority = 3;
  elem->sprite.pos = *pos;
  elem->moverLinked = moverLinked;
  if (elem->moverLinked) {
    Mover_Init(&elem->mover, elem->id, &elem->sprite.pos, 0, 7, elem);
    FUN_08002a48(&elem->mover);
  }
}

void Entity1DBEElem_InitHitbox(Entity1DBEElem* elem) {
  HitboxData* hitbox = &elem->hitbox;
  Vec3 size;
  Vec3 offset;

  size.x = 0x80, size.y = 0x32, size.z = 0x80;
  offset.x = 0, offset.y = 0, offset.z = 0;
  Hitbox_Init(hitbox, elem->id, HBFLAG_HURTBOX | HBFLAG_UNK_1 | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
  Hitbox_SetHandler(hitbox, Entity1DBEElem_OnHit, elem);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
  Hitbox_Register(hitbox);
  hitbox->damage = 600;
}

// '.s' の値ごとに見た目と更新関数を決める
void Entity1DBEElem_InitState(Entity1DBEElem* elem) {
  if (elem->state == 0) {
    elem->sprite.poseIdx = 0;
    Entity1DBEElem_SetState(elem, 0, FUN_0809fabc);
  } else if (elem->state == 2) {
    elem->sprite.poseIdx = 8;
    Entity1DBEElem_SetState(elem, 2, FUN_0809f8e4);
  } else if (elem->state == 1) {
    elem->sprite.poseIdx = 5;
    Entity1DBEElem_SetState(elem, 1, FUN_0809f7fc);
  }
}

void Entity1DBE_AddElem(Entity1DBE* p, u32 id, Vec3* pos, u32 state, u32 moverLinked, u32 lockFlags, u32 areaBound) {
  Entity1DBEElem* elem = &p->elems[p->count];

  Entity1DBEElem_InitParams(elem, id, pos, state, lockFlags, areaBound);
  Entity1DBEElem_InitSprite(elem, pos, moverLinked);
  Entity1DBEElem_InitHitbox(elem);
  Entity1DBEElem_InitState(elem);
}

s32 Entity1DBE_Update(Entity1DBE* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    Entity1DBEElem_Update(&p->elems[i]);
  }
  return 0;
}

s32 Entity1DBE_Destroy(Entity1DBE* p) {
  s32 i;

  for (i = 0; i < p->count; i++) {
    if (p->elems[i].moverLinked) {
      Mover_Unlink(&p->elems[i].mover);
    }
    AuxSprite_Remove(&p->elems[i].sprite);
    Hitbox_Unregister(&p->elems[i].hitbox);
  }
  gEntity1DBE = NULL;
  return 0;
}

s32 Entity1DBE_Init(Entity1DBE* p) {
  p->count = 0;
  gEntity1DBE = p;
  return 0;
}

Entity1DBE* Entity1DBE_Create(void) {
  Entity1DBE* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity1DBE));

  if (p != NULL) {
    SetEntityRoutine(p, Entity1DBE_Update, Entity1DBE_Destroy);
    if (Entity1DBE_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

NAKED void Cmd_1DBE(void) { INCFUNC("asm/func/Cmd_1DBE.inc"); }
