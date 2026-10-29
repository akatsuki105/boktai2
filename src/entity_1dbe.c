#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "vm.h"

// Entity1DBEElem.lockFlags
typedef enum {
  E1DBE_LOCK_STATE2 = 1 << 0,  // 0x1, 日照が強くても state 2 へ遷移しない
  E1DBE_LOCK_STATE1 = 1 << 1,  // 0x2, 日が落ちても state 1 へ遷移しない
} Entity1DBELockFlags;

// 太陽エネルギーで state が入れ替わる設置物, 1体の Entity1DBE が最大8個を抱える
typedef struct Entity1DBEElem {
  AuxSprite sprite;                                // 0x000, poseIdx が見た目の段階 (state 0 は 0〜2, state 1 は 3〜5, state 2 は 6〜8)
  AuxSpriteGfx gfx;                                // 0x02C, SPRITE_TRAP_FLOOR
  Mover mover;                                     // 0x048, moverLinked が立っているときだけリストに繋がれる
  HitboxData hitbox;                               // 0x08C, 半径 {0x80, 0x32, 0x80}, ignoreMask 0x10
  u8 state;                                        // 0x0DC, '.s', 0/1/2 で updateCallback を選ぶ
  u8 lockFlags;                                    // 0x0DD, '.f', see Entity1DBELockFlags
  u8 unk_de;                                       // 0x0DE, 読み手も書き手も見つかっていない
  bool8 touched;                                   // 0x0DF, 近くに来るか属性なしの攻撃を受けると立つ, state 0 が消費して点滅を始める
  u16 id;                                          // 0x0E0, '.n', mover.id と hitbox の id を兼ねる
  u16 unk_e2;                                      // 0x0E2, 状態が変わるたび 0x10 が入るが読み手が見つかっていない
  bool8 moverLinked;                               // 0x0E4, '.h', 立っていれば mover を使う
  bool8 flickering;                                // 0x0E5, touched のあと animTimer が 90 になるまで点滅する
  bool8 areaBound;                                 // 0x0E6, '.m', 立っていれば zoneID が現在のエリアと一致する間だけ更新する
  bool8 unk_e7;                                    // 0x0E7, 立っていると状態の振り分けをやり直して 0 に戻る, 書き手が見つかっていない
  ZoneID16 zoneID;                                 // 0x0E8, GetZoneAt(sprite.pos) の結果, gStat->zoneID と比べる
  u8 unk_ea[2];                                    // 0x0EA, 読み手も書き手も見つかっていない, padding?
  s16 counter;                                     // 0x0EC, 日照で増え暗所で減る, ±300 を越えると state が切り替わる, state 1/2 では復帰までのフレーム数
  u16 animTimer;                                   // 0x0EE, 遷移アニメと点滅のコマ送り
  void (*updateCallback)(struct Entity1DBEElem*);  // 0x0F0
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

void FUN_08015c90(s32 count, u32 kind, u32 flags, u32 animSpeed, WorldPos* pos);

static inline bool8 TestMapFlag(u32 mapflag) {
  if (TEST_FLAGS(gStat->mapFlags, mapflag)) return TRUE;
  return FALSE;
}

void FUN_0809f64c(void) { gEntity1DBE = NULL; }

// pos から半径 0x80 以内にある state 0 の設置物に touched を立てる, 立てたら TRUE
bool32 Entity1DBE_TouchElemNear(WorldPos* pos) {
  s32 i;

  if (gEntity1DBE == NULL) {
    return FALSE;
  }

  for (i = 0; i < gEntity1DBE->count; i++) {
    Entity1DBEElem* elem = &gEntity1DBE->elems[i];
    s32 dx;
    s32 dz;

    if (elem->state != 0) {
      continue;
    }
    if (elem->sprite.pos.y < pos->y) {
      continue;
    }

    dx = abs(pos->x - elem->sprite.pos.x);
    if (dx > Q8(0.5)) {
      continue;
    }
    dz = abs(pos->z - elem->sprite.pos.z);
    if (dz > Q8(0.5)) {
      continue;
    }
    if (dx * dx + dz * dz <= Q8(0.5) * Q8(0.5)) {
      elem->touched = TRUE;
      return TRUE;
    }
  }

  return FALSE;
}

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

void FUN_0809f840(Entity1DBEElem*);
void FUN_0809f890(Entity1DBEElem*);
void FUN_0809f938(Entity1DBEElem*);
void FUN_0809fa80(Entity1DBEElem*);
void FUN_0809fabc(Entity1DBEElem*);

void Entity1DBEElem_SetState(Entity1DBEElem* elem, u8 state, void* fn) {
  elem->state = state;
  elem->updateCallback = fn;
  elem->counter = 0;
  elem->animTimer = 0;
}

// 炎属性で状態を進め, 氷属性で凍らせ, 属性なしなら touched だけ立てる
void Entity1DBEElem_OnHit(HitboxData* a, HitboxData* b, void* owner) {
  Entity1DBEElem* elem = owner;

  if (b->invincibleTime != 0) {
    return;
  }
  if (!Hitbox_HasWeakness(a, HBATTR_FLAME)) {
    return;
  }

  if (Hitbox_TestAttr(a, HBATTR_FLAME)) {
    if (elem->state == 0) {
      Entity1DBEElem_SetState(elem, 2, FUN_0809f938);
    } else if (elem->state == 1) {
      Entity1DBEElem_SetState(elem, 0, FUN_0809f890);
    }
    b->invincibleTime = 30;
  } else if (Hitbox_TestAttr(a, HBATTR_FROST)) {
    if (elem->state == 0) {
      Entity1DBEElem_SetState(elem, 1, FUN_0809f840);
    }
    b->invincibleTime = 30;
  } else if (elem->state == 0) {
    elem->touched = TRUE;
  }
}

// 日が出ている間だけ counter を進め, 299 を越えたら次の状態へ移る
void FUN_0809f7fc(Entity1DBEElem* elem) {
  if (gStat->sunGauge > 0) {
    elem->counter++;
    if (elem->counter >= 300) {
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
void FUN_0809f8e4(Entity1DBEElem* elem) {
  if (TestMapFlag(MPF_RAIN)) {
    elem->counter++;
    if (elem->counter > 299) {
      Entity1DBEElem_SetState(elem, 0, FUN_0809fa80);
    }
  }
}

// 凍結が解けるまでのアニメ, 4フレームごとに足元へ水しぶきを散らす
// 残差0命令 (141/141) でレジスタ名だけ違う: 原典は elem を r4, &animTimer を r5 に置くが agbcc は逆に割り当てる
// ブロック内の table と pos の宣言順を入れ替えると上は合うが, 代わりに乱数と pos.x の読み出し順が入れ替わる (static inline に切り出しても同じ)
NON_MATCH void FUN_0809f938(Entity1DBEElem* elem) {
#ifdef NONMATCHING_C
  if (elem->animTimer == 0) {
    PlaySound_082406e0(SONG_348);
  }

  elem->animTimer++;
  if (elem->animTimer <= 7) {
    elem->sprite.poseIdx = 6;
    if ((elem->animTimer & 3) == 0) {
      u16* table = gRandomTable;
      WorldPos pos = elem->sprite.pos;

      pos.x = (u16)pos.x - 0x7F + (u8)_Random(table);
      pos.z = (u16)pos.z - 0x7F + (u8)_Random(table);
      FUN_08015c90(1, 0, 1, 0x40, &pos);
    }
  } else if (elem->animTimer <= 15) {
    elem->sprite.poseIdx = 7;
    elem->animTimer++;
    if ((elem->animTimer & 3) == 0) {
      u16* table = gRandomTable;
      WorldPos pos = elem->sprite.pos;

      pos.x = (u16)pos.x - 0x7F + (u8)_Random(table);
      pos.z = (u16)pos.z - 0x7F + (u8)_Random(table);
      FUN_08015c90(1, 0, 1, 0x40, &pos);
    }
  } else {
    elem->sprite.poseIdx = 8;
    Entity1DBEElem_SetState(elem, 2, FUN_0809f8e4);
  }
#else
  INCFUNC("asm/func/FUN_0809f938.inc");
#endif
}

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

// 点滅の進行と, 日照に応じた state 0 からの遷移
void FUN_0809fabc(Entity1DBEElem* elem) {
  s32 sun;

  if (elem->touched) {
    elem->flickering = TRUE;
    elem->touched = FALSE;
    if (elem->animTimer > 0x3F) {
      elem->animTimer = ((elem->animTimer - 0x40) & 0x1F) >> 1;
    } else {
      elem->animTimer = elem->animTimer & 0xF;
    }
  }

  if (elem->flickering) {
    if (++elem->animTimer > 0x5F) {
      elem->sprite.poseIdx = 2;
      elem->flickering = FALSE;
      elem->animTimer = 0;
    } else if (elem->animTimer <= 0x3F) {
      if ((elem->animTimer & 0xF) <= 7) {
        elem->sprite.poseIdx = 1;
      } else {
        elem->sprite.poseIdx = 2;
      }
    } else {
      if ((elem->animTimer & 0x1F) <= 0xF) {
        elem->sprite.poseIdx = 1;
      } else {
        elem->sprite.poseIdx = 2;
      }
    }
  }

  sun = gStat->sunGauge;
  if (sun == 0) {
    if (elem->lockFlags & E1DBE_LOCK_STATE1) {
      elem->counter--;
      if (elem->counter < 0) {
        elem->counter = 0;
      }
    } else {
      elem->counter--;
      if (elem->counter < -300) {
        Entity1DBEElem_SetState(elem, 1, FUN_0809f840);
      }
    }
  } else if (sun > 7) {
    if (elem->lockFlags & E1DBE_LOCK_STATE2) {
      elem->counter++;
      if (elem->counter > 0) {
        elem->counter = 0;
      }
    } else {
      elem->counter++;
      if (elem->counter > 300) {
        Entity1DBEElem_SetState(elem, 2, FUN_0809f938);
      }
    }
  }
}

// '.m' が立っていればエリア外では更新を止め, 戻ってきたときに状態を組み直す
void Entity1DBEElem_Update(Entity1DBEElem* elem) {
  if (elem->areaBound) {
    if (elem->zoneID == gStat->zoneID) {
      if (!elem->unk_e7) {
        elem->hitbox.flags &= ~HBFLAG_HIDDEN;
      }
      elem->updateCallback(elem);
    } else if (elem->unk_e7) {
      if (elem->state == 0) {
        Entity1DBEElem_SetState(elem, 0, FUN_0809fabc);
        elem->sprite.poseIdx = 0;
        elem->flickering = FALSE;
        elem->touched = FALSE;
      } else if (elem->state == 2) {
        Entity1DBEElem_SetState(elem, 2, FUN_0809f8e4);
        elem->sprite.poseIdx = 8;
        elem->unk_e2 = 0x10;
      } else if (elem->state == 1) {
        Entity1DBEElem_SetState(elem, 2, FUN_0809f7fc);
        elem->sprite.poseIdx = 5;
        elem->unk_e2 = 0x10;
      }
      elem->hitbox.flags |= HBFLAG_HIDDEN;
      elem->unk_e7 = FALSE;
    }
  } else {
    elem->updateCallback(elem);
  }

  if (elem->hitbox.invincibleTime != 0) {
    elem->hitbox.invincibleTime--;
  }
}

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
  Video_SetAuxSpritePltt(gfx, 67);
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
  Vec3 size, offset;
  VEC3_SET(size, Q8(0.5), Q8(0.196), Q8(0.5));
  VEC3_SET(offset, 0, 0, 0);
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

// 0x1DBE, '.p' に設置物を1個足す, 8個まで
void Cmd_1DBE(void) {
  Entity1DBE* p = gEntity1DBE;
  Vec3 pos;
  s32 id;
  s32 state;
  s32 moverLinked;
  s32 lockFlags;
  s32 areaBound;

  if (p == NULL) {
    p = Entity1DBE_Create();
  }
  if (p->count >= 8) {
    return;
  }

  id = VM_SeekToNamedArg('n') ? VM_GetValue() : 0;

  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }

  state = VM_SeekToNamedArg('s') ? VM_GetValue() : 0;
  moverLinked = VM_SeekToNamedArg('h') ? VM_GetValue() : 0;
  lockFlags = VM_SeekToNamedArg('f') ? VM_GetValue() : 0;
  areaBound = VM_SeekToNamedArg('m') ? VM_GetValue() : 0;

  Entity1DBE_AddElem(p, id, &pos, state, moverLinked, lockFlags, areaBound);
  p->count++;
}
