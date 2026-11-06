#include "camera.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "map_inline.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vm.h"

// 上から物体が落下してくるギミック(罠や敵の攻撃など)

// FallingObject.type
enum {
  TYPE_0 = 0,
  TYPE_1 = 1,
  TYPE_2 = 2,  // 夢幻街のトラップやドゥラスロールの落とす棘鉄球
};

// FallingObject.state
typedef enum {
  STATE_0 = 0,  // 落下
  STATE_1 = 1,  // 着地して揺れる
  STATE_2 = 2,  // 待機
  STATE_3 = 3,  // 消える
} FallingObjectState;

// FallingObject.flags
typedef enum {
  HAS_HURTBOX = 1 << 0,  // hurtbox を持つ
  HAS_HITBOX = 1 << 1,   // hitbox を持つ
  LARGER = 1 << 2,       // 判定とスケールを大きくする
} FallingObjectFlags;

// 空から落ちてきて地面の高さで止まる物体1個, type 0 は燃える炎で duration の間残るか氷属性の攻撃で消され, type 1/2 は着地すると跳ね返って点滅して消える
typedef struct FallingObject {
  u16 id;                      // 0x00, '.n', hurtbox と hitbox の id
  u8 type;                     // 0x02, '.t', 2 以上は 2 にして超えた分でパレットを選ぶ
  bool8 stateBegun;            // 0x03, 立っていると次の更新で state の初期化をする
  u8 state;                    // 0x04, PTR_ARRAY_085aa7a0[type][state] の添字, see FallingObjectState, TYPE_1/TYPE_2 は 1 以降ずっと跳ね返って消える
  u8 flags;                    // 0x05, '.f', see FallingObjectFlags
  u16 timer;                   // 0x06, state に入ってからのフレーム数
  u16 duration;                // 0x08, '.T', type 0 の state 2 の長さ, type 1/2 は着地時に 30/25 で上書きし, 超えると消える
  bool8 animEnded;             // 0x0A, anim が最後のコマを終えて先頭に戻ったフレームだけ 1
  bool8 hasShadow;             // 0x0B, shadow を登録している間 1
  bool8 animated;              // 0x0C, type 0 だけ 1, 立っていると毎フレーム anim を進めて sprite に反映する
  bool8 finished;              // 0x0D, 立つと次のフレームで解放する
  u8 poseTimer;                // 0x0E, type 2 で 5 フレームごとに pose を進めるためのカウンタ
  u8 pose;                     // 0x0F, type 2 で 0..2 を巡回し sprite.poseIdx に入る
  s16 hp;                      // 0x10, '.l', type 0 は氷属性の攻撃で damage の2倍ずつ減り, 0 以下で state 3 へ
  u16 fallSpeed;               // 0x12, '.s', 落下中に毎フレーム pos.y から引く
  u16 groundY;                 // 0x14, 着地する高さ, pos のタイルの高さから求める (階段は pos で補正)
  u8 unk_16[2];                // 0x16
  Vec3 pos;                    // 0x18, '.p'
  HitboxData* hurtbox;         // 0x20, HAS_HURTBOX のときだけ持つ
  HitboxData* hitbox;          // 0x24, HAS_HITBOX のときだけ持つ, TYPE_0 は HBATTR_FLAME | HBATTR_INKA
  AuxSpriteGfx gfx;            // 0x28, sFallingObjectSpriteIDs[type]
  AuxSprite sprite;            // 0x44
  AuxAnimState anim;           // 0x70, type 0 だけ使う, animIdx 3: 落下, 2: 着地後, 4: 消える
  AuxShadow shadow;            // 0x80
  struct FallingObject* prev;  // 0xEC
  struct FallingObject* next;  // 0xF0
} FallingObject;
static_assert(sizeof(FallingObject) == 244);

// FallingObject の双方向リストを持つシングルトン, VM コマンド 2B8C とドゥラスロールが要素を足す
typedef struct {
  Entity e;             // 0x00, ENTITY_UNK_8
  AuxAnimFile* anim;    // 0x18, ANIM_931E
  FallingObject* list;  // 0x1C, 双方向リストの先頭, 新しい要素は先頭に入る
} FallingObjectManager;
static_assert(sizeof(FallingObjectManager) == 32);

COMMON_DATA FallingObjectManager* gFallingObjectManager = NULL;  // 0x03002B3C

void FUN_08015d3c(WorldPos* pos, u32 kind, u32 flags, u32 animSpeed, u32 speedY, s32 speedYRand, u32 speedXZ, s32 speedXZRand);
s32 FUN_08014730(s32 count, s32 kind, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask);
s32 Entity08016ba4_Spawn(s32 count, Vec3* pos, s32 lifeBase, s32 lifeRand, s32 speedBase, s32 speedRand, s32 angleBase, s32 angleRand, s32 velYBase, s32 velYRand);
FallingObjectManager* FallingObjectManager_Create(u32 id, u32 _);

static inline void FallingObject_SetState(FallingObject* p, u8 state) {
  p->state = state;
  p->timer = 0;
  p->stateBegun = TRUE;
}

void FallingObjectManager_ClearGlobal(void) { gFallingObjectManager = NULL; }

// 残差1命令 (23/24), 原典は data を r2 と r5 の2本に持ち, 属性判定の前に damage を読む
// Hitbox_TestAttr, damage を先に読むローカルは試済
NON_MATCH void FallingObject_OnHurt(HitboxData* a, HitboxData* b, FallingObject* data) {
#ifdef NONMATCHING_C
  if (data->type == TYPE_0) {
    if (a->attributes & HBATTR_FROST) {
      data->hp -= a->damage * 2;
    }
    if (data->hp < 0) {
      data->hp = 0;
    }
  }
#else
  INCFUNC("asm/func/FallingObject_OnHurt.inc");
#endif
}

void FallingObject_OnHit(HitboxData* a, HitboxData* b, FallingObject* data) {}

s32 FallingObjectManager_LinkNode(FallingObjectManager* p, FallingObject* data) {
  data->prev = NULL;
  data->next = p->list;
  if (data->next != NULL) {
    data->next->prev = data;
  }
  p->list = data;
  return 0;
}

s32 FallingObjectManager_UnlinkNode(FallingObjectManager* p, FallingObject* data) {
  FallingObject* prev = data->prev;
  FallingObject* next = data->next;

  if (prev != NULL) {
    prev->next = next;
  } else {
    p->list = next;
  }
  if (next != NULL) {
    next->prev = prev;
  }
  return 0;
}

void FallingObject_RemoveShadow(FallingObject* p) {
  if (p->hasShadow) {
    AuxShadow_Remove(&p->shadow);
    p->hasShadow = FALSE;
  }
}

s32 FallingObject_FreeNode(FallingObject* p) {
  AuxSprite_Remove(&p->sprite);
  if (gFallingObjectManager != NULL) {
    FallingObjectManager_UnlinkNode(gFallingObjectManager, p);
  }
  FallingObject_RemoveShadow(p);
  if (p->hurtbox != NULL) {
    Hitbox_Unregister(p->hurtbox);
    Free(p->hurtbox);
  }
  if (p->hitbox != NULL) {
    Free(p->hitbox);
  }
  Free(p);
}

static const SpriteID16 sFallingObjectSpriteIDs[8] = {
    [TYPE_0] = SPRITE_863A,
    [TYPE_1] = SPRITE_ROCK_9D3F,
    [TYPE_2] = SPRITE_SPIKEBALL,
};  // 0x085AA790

s32 FallingObject_Spawn(u16 id, s32 type, u32 flags, s32 duration, s32 fallSpeed, s32 hp, s32 power, s32 knockback, Vec3* pos) {
  FallingObject* data;
  s32 plttOffset;
  Vec3 size, offset;
  HitboxAttributes attrs;

  if (gFallingObjectManager == NULL && FallingObjectManager_Create(0xC0DB, 0) == NULL) {
    return -1;
  }
  data = Malloc(sizeof(FallingObject));
  if (data == NULL) {
    return -1;
  }
  ClearMemory(data, sizeof(FallingObject));

  data->id = id;
  plttOffset = 0;
  if (type >= TYPE_2) {
    data->type = TYPE_2;
    plttOffset = type - TYPE_2;
  } else {
    data->type = type;
  }
  FallingObject_SetState(data, STATE_0);
  data->flags = flags;
  data->duration = duration;
  data->pos = *pos;
  if (data->type == TYPE_0) {
    data->animated = TRUE;
  } else {
    data->animated = FALSE;
  }
  data->fallSpeed = fallSpeed;
  data->groundY = TileHeightAt(&data->pos);
  data->hp = hp;

  if (data->flags & HAS_HURTBOX) {
    data->hurtbox = Malloc(sizeof(HitboxData));
    if (data->hurtbox == NULL) {
      return -1;
    }
    ClearMemory(data->hurtbox, sizeof(HitboxData));
    if (data->flags & LARGER) {
      VEC3_SET(size, 180, 256, 180);
      VEC3_SET(offset, 0, 256, 0);
    } else {
      VEC3_SET(size, 90, 128, 90);
      VEC3_SET(offset, 0, 128, 0);
    }
    Hitbox_Init(data->hurtbox, data->id, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
    Hitbox_SetHandler(data->hurtbox, FallingObject_OnHurt, data);
    Hitbox_Register(data->hurtbox);
    Hitbox_SetPos(data->hurtbox, &data->pos, 0);
  } else {
    data->hurtbox = NULL;
  }

  if (data->flags & HAS_HITBOX) {
    data->hitbox = Malloc(sizeof(HitboxData));
    if (data->hitbox == NULL) {
      return -1;
    }
    ClearMemory(data->hitbox, sizeof(HitboxData));
    if (data->flags & LARGER) {
      VEC3_SET(size, 120, 160, 120);
      VEC3_SET(offset, 0, 80, 0);
    } else {
      VEC3_SET(size, 60, 80, 60);
      VEC3_SET(offset, 0, 40, 0);
    }
    attrs = 0;
    if (data->type == TYPE_0) {
      attrs = HBATTR_FLAME | HBATTR_INKA;
    }
    Hitbox_Init(data->hitbox, data->id, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, HIM_5, &size, &offset);
    Hitbox_SetAttack(data->hitbox, power, knockback, 0x2000, attrs, 60);
    Hitbox_SetHandler(data->hitbox, FallingObject_OnHit, data);
    Hitbox_SetPos(data->hitbox, &data->pos, 0);
  } else {
    data->hitbox = NULL;
  }

  if (!Video_GetAuxSprite(&data->gfx, sFallingObjectSpriteIDs[data->type])) {
    return -1;
  }
  AuxSprite_Add(&data->sprite, &data->gfx, 0);
  data->sprite.priority = 2;
  data->sprite.pos = data->pos;
  if (type >= TYPE_2) {
    Video_SetAuxSpritePltt(&data->gfx, plttOffset + 635);
  }
  if (data->flags & LARGER) {
    data->sprite.flags |= SPRFLAG_AFFINE;
    data->sprite.scaleX = data->sprite.scaleY = 120;
  } else {
    data->sprite.flags &= ~SPRFLAG_AFFINE;
    data->sprite.scaleX = data->sprite.scaleY = 64;
  }
  if (data->animated) {
    AuxAnim_SetAnim(&data->anim, gFallingObjectManager->anim, 3, 0, 0);
  }
  AuxShadow_Init(&data->shadow, &data->pos, 80, 7, 107, 107, 0xC80, 1, 5, 1, 0);
  data->hasShadow = TRUE;
  data->finished = FALSE;
  data->prev = NULL;
  data->next = NULL;
  return FallingObjectManager_LinkNode(gFallingObjectManager, data);
}

s32 Cmd_SpawnFallingObject(void) {
  u16 id = VM_GetNamedArgValue('n', 0);
  s32 type = VM_GetNamedArgValue('t', 0);
  s32 flags = VM_GetNamedArgValue('f', 0);
  s32 duration = VM_GetNamedArgValue('T', 0);
  s32 fallSpeed = VM_GetNamedArgValue('s', 0);
  s32 hp = VM_GetNamedArgValue('l', 0);
  s32 power = VM_GetNamedArgValue('P', 200);
  s32 knockback = VM_GetNamedArgValue('F', 50);
  Vec3 pos;

  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  return FallingObject_Spawn(id, type, flags, duration, fallSpeed, hp, power, knockback, &pos);
}

void FallingObject_UpdateFall(FallingObject* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    if (p->animated) {
      AuxAnim_SetAnim(&p->anim, gFallingObjectManager->anim, 3, 0, 0);
    }
  }

  p->pos.y -= p->fallSpeed;
  if (p->pos.y <= p->groundY) {
    p->pos.y = p->groundY;
    if (p->type == TYPE_2) {
      if (p->flags & LARGER) {
        PlaySound_082406e0(SE_669);
      } else {
        PlaySound_082406e0(SE_SPIKEBALL);
      }
    } else {
      PlaySound_082406e0(SE_326);
    }
    FallingObject_SetState(p, STATE_1);
    p->pose = 0;
    p->poseTimer = 0;
  }

  if (p->type > TYPE_1) {
    p->poseTimer++;
    if (p->poseTimer == 5) {
      p->pose++;
      if (p->pose > 2) {
        p->pose = 0;
      }
      p->poseTimer = 0;
    }
    AuxSprite_SetPoseIdx(&p->sprite, p->pose);
  }

  if (p->hurtbox != NULL) {
    Hitbox_SetPos(p->hurtbox, &p->pos, 0);
  }
  if (p->hitbox != NULL) {
    Hitbox_SetPos(p->hitbox, &p->pos, 0);
    Hitbox_Register(p->hitbox);
  }
}

void FallingObject_UpdateLanded(FallingObject* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    AuxAnim_SetAnim(&p->anim, gFallingObjectManager->anim, 2, 0, 0);
    FallingObject_RemoveShadow(p);
    Entity08016ba4_Spawn((Random() & 3) + 6, &p->pos, 9, 20, 8, 8, 0, 256, 24, 16);
  }

  if (p->type > TYPE_1) {
    p->poseTimer++;
    if (p->poseTimer == 10) {
      p->pose++;
      if (p->pose > 2) {
        p->pose = 0;
      }
      p->poseTimer = 0;
    }
    AuxSprite_SetPoseIdx(&p->sprite, p->pose);
  }

  if (p->hp <= 0) {
    FallingObject_SetState(p, STATE_3);
    return;
  }

  if (p->timer++ > 30) {
    FallingObject_SetState(p, STATE_2);
  } else {
    s32 d = (30 - p->timer) >> 1;

    if (!(p->timer & 1)) {
      p->sprite.pos.x += d;
      p->sprite.pos.z -= d;
    } else {
      p->sprite.pos.x -= d;
      p->sprite.pos.z += d;
    }
  }

  if (p->hurtbox != NULL) {
    Hitbox_SetPos(p->hurtbox, &p->pos, 0);
  }
  if (p->hitbox != NULL) {
    Hitbox_SetPos(p->hitbox, &p->pos, 0);
    Hitbox_Register(p->hitbox);
  }
}

void FallingObject_UpdateBounceType1(FallingObject* p) {
  Vec3 vel, velRange;

  if (p->stateBegun) {
    p->stateBegun = FALSE;
    FallingObject_RemoveShadow(p);
    if (!(gGameFlags & GAMEFLAG_LINK)) {
      VEC3_SET(vel, -15, 8, -15);
      VEC3_SET(velRange, 30, 22, 30);
      FUN_08014730(8, 3, &p->pos, &vel, &velRange, 60, 60);
    }
    p->duration = 30;
  }

  if (p->timer < 12) {
    p->pos.y += 8;
    Camera_Shake(40);
  } else {
    p->pos.y -= 4;
    if (p->pos.y < p->groundY) {
      p->pos.y = p->groundY;
    }
  }

  if (p->hurtbox != NULL) {
    Hitbox_SetPos(p->hurtbox, &p->pos, 0);
  }
  if (p->hitbox != NULL) {
    Hitbox_SetPos(p->hitbox, &p->pos, 0);
    Hitbox_Register(p->hitbox);
  }

  if ((p->timer & 7) < 2) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
  if (p->timer++ > p->duration) {
    p->finished = TRUE;
  }
}

void FallingObject_UpdateBounceType2(FallingObject* p) {
  Vec3 vel, velRange;

  if (p->stateBegun) {
    p->stateBegun = FALSE;
    if (!(gGameFlags & GAMEFLAG_LINK)) {
      VEC3_SET(vel, -15, 8, -15);
      VEC3_SET(velRange, 30, 22, 30);
      FUN_08014730(8, 3, &p->pos, &vel, &velRange, 60, 60);
    }
    p->duration = 25;
  }

  if (p->timer < 15) {
    p->pos.y -= (p->timer >> 2) - 16;
    Camera_Shake(40);
  } else {
    s32 dy = p->timer - 15;

    if (dy <= 15) {
      p->pos.y -= dy;
    } else {
      p->pos.y -= 16;
    }
    if (p->pos.y < p->groundY) {
      p->pos.y = p->groundY;
    }
  }

  if (p->hurtbox != NULL) {
    Hitbox_SetPos(p->hurtbox, &p->pos, 0);
  }
  if (p->hitbox != NULL) {
    Hitbox_SetPos(p->hitbox, &p->pos, 0);
    Hitbox_Register(p->hitbox);
  }

  if ((p->timer & 7) < 2) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
  }
  if (p->timer++ > p->duration) {
    FallingObject_RemoveShadow(p);
    p->finished = TRUE;
  }
}

void FallingObject_UpdateWait(FallingObject* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    AuxAnim_SetAnim(&p->anim, gFallingObjectManager->anim, 2, 0, 0);
  }
  if (p->hp <= 0 || p->timer++ > p->duration) {
    FallingObject_SetState(p, STATE_3);
    return;
  }
  if (p->hurtbox != NULL) {
    Hitbox_SetPos(p->hurtbox, &p->pos, 0);
  }
  if (p->hitbox != NULL) {
    Hitbox_SetPos(p->hitbox, &p->pos, 0);
    Hitbox_Register(p->hitbox);
  }
}

s32 FallingObject_SpawnParticles(FallingObject* p) {
  Vec3 pos;

  VEC3_SET(pos, p->sprite.pos.x, p->sprite.pos.y, p->sprite.pos.z);
  FUN_08015d3c(&pos, 2, 0, 64, 8, 4, 0, 0);
}

void FallingObject_UpdateVanish(FallingObject* p) {
  if (p->stateBegun) {
    p->stateBegun = FALSE;
    AuxAnim_SetAnim(&p->anim, gFallingObjectManager->anim, 4, 0, 0);
    if (p->hurtbox != NULL) {
      p->hurtbox->flags |= HBFLAG_HIDDEN;
    }
    FallingObject_RemoveShadow(p);
  }
  if (p->animEnded) {
    if (!p->finished) {
      FallingObject_SpawnParticles(p);
    }
    p->finished = TRUE;
  }
}

void (*const PTR_ARRAY_085aa7a0[7][4])(FallingObject*) = {
    [TYPE_0] = {FallingObject_UpdateFall, FallingObject_UpdateLanded,      FallingObject_UpdateWait,        FallingObject_UpdateVanish     },
    [TYPE_1] = {FallingObject_UpdateFall, FallingObject_UpdateBounceType1, FallingObject_UpdateBounceType1, FallingObject_UpdateBounceType1},
    [TYPE_2] = {FallingObject_UpdateFall, FallingObject_UpdateBounceType2, FallingObject_UpdateBounceType2, FallingObject_UpdateBounceType2},
};  // 0x085AA7A0

s32 FallingObjectManager_Update(FallingObjectManager* p) {
  FallingObject* node = p->list;

  while (node != NULL) {
    FallingObject* next = node->next;

    if (node->finished) {
      FallingObject_FreeNode(node);
    } else {
      if (node->animated) {
        node->animEnded = AuxSprite_AdvanceAnim(&node->sprite, &node->anim);
      }
      node->sprite.pos = node->pos;
      PTR_ARRAY_085aa7a0[node->type][node->state](node);
    }
    node = next;
  }
  return 0;
}

s32 FallingObjectManager_Destroy(FallingObjectManager* p) {
  FallingObject* node = p->list;

  while (node != NULL) {
    FallingObject* next = node->next;

    FallingObject_FreeNode(node);
    node = next;
  }

  gFallingObjectManager = NULL;
  return 0;
}

s32 FallingObjectManager_Init(FallingObjectManager* p, u32 _) {
  gFallingObjectManager = p;
  p->anim = GetFile(DIR_ANIMATION, ANIM_931E);
  p->list = NULL;
  return 0;
}

FallingObjectManager* FallingObjectManager_Create(u32 id, u32 _) {
  if (gFallingObjectManager == NULL) {
    FallingObjectManager* p = CreateEntity(ENTITY_UNK_8, sizeof(FallingObjectManager));
    if (p != NULL) {
      SetEntityRoutine(p, FallingObjectManager_Update, FallingObjectManager_Destroy);
      if (FallingObjectManager_Init(p, id) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gFallingObjectManager;
}
