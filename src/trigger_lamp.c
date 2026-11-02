#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "map_inline.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

typedef enum {
  LP_CHANDELIER = 0,  // シャンデリア
  LP_CANDLE = 1,      // ろうそく箱
} LampKind;

typedef enum {
  LPM_FIXED = 0,       // 固定
  LPM_HORIZONTAL = 1,  // 移動床に乗っている (水平方向に動く)
  LPM_VERTICAL = 2,    // 昇降床に乗っている (垂直方向に動く)
} LampMoveKind;

// 炎を当てると点き、氷を当てると消える照明, 1体の Entity2D2B が count 個を抱える
typedef struct {
  bool8 active;        // 0x000, 使用中の枠か
  u8 moveKind;         // 0x001, see LampMoveKind
  u8 state;            // 0x002, '.m=1', 1 消灯, 2 点灯, 3 点灯への遷移, 4 消灯への遷移, 0 は何もしない
  u8 unk_3;            // 0x003, '.f=0', 読み手が見つかっていない
  bool8 stateEntered;  // 0x004, state が変わった直後だけ立つ, 遷移時の初期化を1回で済ませるために使う
  u8 flashTimer;       // 0x005, 遷移の直後 10 フレーム, 0 でない間だけ hurtbox.flags に HBFLAG_HIDDEN が立つ
  s16 yOffset;         // 0x006, '.t[1]', エレベータの位置に足す高さ
  s16 litDuration;     // 0x008, '.d=120', 点灯から自然に消えるまでのフレーム数, 負なら消えない
  u16 waitTimer;       // 0x00A, 経路ノードでの待ちフレーム, PathNode の下位12bit が入る
  s32 stateTimer;      // 0x00C, state が変わってからのフレーム数
  u16 id;              // 0x010, '.n=0', hurtbox の id と スクリプトの第1引数を兼ねる
  u16 scriptID;        // 0x012, '.p=0', 遷移するたびに実行する, 0 なら実行しない
  ZoneID32 zoneID;     // 0x014, '.M' が 0 なら -1 でエリア無制限, それ以外は設置位置のエリア, gStat->zoneID と比べる
  s32 kind;            // 0x018, '.D=0', LampKind
  u32 scriptArg;       // 0x01C, '.a=0', スクリプトの第3引数
  Vec3* elevatorPos;   // 0x020, '.t[0]' で指定したエレベータの現在位置
  u16 speed;           // 0x024, '.r[3]', 経路上を進む速さ
  u16 radius;          // 0x026, '.r[4]', 経路ノードに着いたと見なす距離
  PathWalker walker;   // 0x028, '.r[0]' 経路番号, '.r[1]', '.r[2]' 開始ノード
  MainSprite sprite;   // 0x034
  HitboxData hurtbox;  // 0x094, 半径 {0x80, 0x80, 0x80}, offset {0, 0x80, 0}, flags 0x4001
  MainSpriteGfx* gfx;  // 0x0E4, kind が選んだ親の gfx
} Entity2D2BElem;
static_assert(sizeof(Entity2D2BElem) == 232);

typedef struct {
  Entity e;               // 0x00, ENTITY_UNK_10
  s32 count;              // 0x18, '.n=8', elems の枠数
  Entity2D2BElem* elems;  // 0x1C
  MainSpriteGfx gfx[2];   // 0x20, SPRITE_CHANDELIER と SPRITE_CANDLE_BOX
} Entity2D2B;
static_assert(sizeof(Entity2D2B) == 96);

static Entity2D2B* gEntity2D2B;  // 0x03000034

bool8 Map_GetStepToPathNode(PathWalker* w, Vec3* pos, Vec3* out, u8* outAngle, u32 rx, u32 rz, s32 speed);
void FUN_08015ce0(s32 count, u32 kind, u32 flags, u32 animSpeed, u32 angleXZ, u32 angleXZRand, u32 speedXZ, s32 speedXZRand, u32 speedY, s32 speedYRand, WorldPos* pos);
Vec3* Elevator_GetPosByID(s32 id);
void Map_ReadPathNodePos(Vec3* dst, PathNode* nodes, u8 idx);

static inline bool8 Entity2D2B_IsCurrentZone(ZoneID32 zoneID) {
  if (gStat->zoneID == zoneID) {
    return TRUE;
  } else {
    return FALSE;
  }
}

static const SpriteID16 sLampSpriteIDs[2] = {
    [LP_CHANDELIER] = SPRITE_CHANDELIER,
    [LP_CANDLE] = SPRITE_CANDLE_BOX,
};  // 0x085AA66C

// 種類ごとの [消灯時, 点灯時] のアニメ番号
static const u16 sLampAnimIdxs[2][2] = {
    [LP_CHANDELIER] = {0, 1},
    [LP_CANDLE] = {0, 1},
};  // 0x085AA670

static const u16 sLampPlttIDs[2] = {64, 739};  // 0x085AA678

// 空いている枠を先頭から探す
Entity2D2BElem* Entity2D2B_FindFreeElem(Entity2D2B* p) {
  Entity2D2BElem* elem = p->elems;
  u32 i;

  for (i = 0; i < (u32)p->count; i++, elem++) {
    if (!elem->active) {
      return elem;
    }
  }
  return NULL;
}

void Entity2D2BElem_SetState(Entity2D2BElem* p, s32 state) {
  p->state = state;
  p->stateTimer = 0;
  p->stateEntered = TRUE;
}

bool32 Entity2D2BElem_ConsumeStateEntered(Entity2D2BElem* p) {
  if (p->stateEntered != 0) {
    p->stateEntered = FALSE;
    return TRUE;
  }
  return FALSE;
}

// 消灯中に炎属性で当たると点灯へ, 点灯中に氷属性で当たると消灯へ遷移する
void Entity2D2BElem_OnHit(HitboxData* a, HitboxData* b, void* owner) {
  Entity2D2BElem* elem = owner;

  if (elem->state == 1) {
    if (Hitbox_TestAttr(a, HBATTR_FLAME)) {
      Entity2D2BElem_SetState(elem, 3);
    }
  } else if (elem->state == 2) {
    if (Hitbox_TestAttr(a, HBATTR_FROST)) {
      Entity2D2BElem_SetState(elem, 4);
    }
  }
}

s32 Entity2D2BElem_Init(Entity2D2B* p, Entity2D2BElem* elem) {
  Vec3 pos;
  Vec3 size;
  Vec3 offset;
  HitboxData* hurtbox;

  elem->gfx = p->gfx;
  Vec3_Clear(&pos);
  MainSprite_Setup(&elem->sprite, p->gfx, 0, SPRFLAG_HIDDEN, 2, 0, 60, &pos);
  MainSprite_SetAnim(&elem->sprite, elem->gfx, 0, PLAYMODE_LOOP, 0);
  hurtbox = &elem->hurtbox;
  VEC3_SET(size, Q8(0.5), Q8(0.5), Q8(0.5));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hurtbox, elem->id, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, 0, &size, &offset);
  Hitbox_SetHandler(hurtbox, Entity2D2BElem_OnHit, elem);
  Hitbox_SetPos(hurtbox, &elem->sprite.pos, 0);
  Hitbox_Register(hurtbox);
  return 0;
}

// 遷移に対応するスクリプトを (id, 点灯/消灯, scriptArg) の3引数で実行する
void Entity2D2BElem_RunScript(Entity2D2BElem* p) {
  u32 argv[3];
  ScriptArgs args;

  if (p->scriptID == 0) {
    return;
  }

  argv[0] = p->id;
  if (p->state == 3) {
    argv[1] = 1;
  } else if (p->state == 4) {
    argv[1] = 0;
  }
  argv[2] = p->scriptArg;

  args.argc = 3, args.argv = argv;
  VM_ExecByID(p->scriptID, &args);
}

void FUN_080080a8(Entity2D2B* p, Entity2D2BElem* elem) {}

// 消灯のアニメとパレットを当てる
void Entity2D2BElem_UpdateUnlit(Entity2D2B* p, Entity2D2BElem* elem) {
  if (Entity2D2BElem_ConsumeStateEntered(elem)) {
    MainSprite* spr = &elem->sprite;

    MainSprite_SetAnim(spr, elem->gfx, sLampAnimIdxs[elem->kind][0], PLAYMODE_LOOP, 0);
    MainSprite_SetPlttID(spr, sLampPlttIDs[elem->kind] + 1);
  }
}

void Entity2D2BElem_UpdateLit(Entity2D2B* p, Entity2D2BElem* elem) {
  if (Entity2D2BElem_ConsumeStateEntered(elem)) {
    MainSprite* spr = &elem->sprite;

    MainSprite_SetAnim(spr, elem->gfx, sLampAnimIdxs[elem->kind][1], PLAYMODE_LOOP, 0);
    MainSprite_SetPlttID(spr, sLampPlttIDs[elem->kind]);
  }
  if (elem->litDuration >= 0 && elem->stateTimer >= elem->litDuration) {
    Entity2D2BElem_SetState(elem, 4);
  }
}

void Entity2D2BElem_UpdateLighting(Entity2D2B* p, Entity2D2BElem* elem) {
  if (Entity2D2BElem_ConsumeStateEntered(elem)) {
    MainSprite* spr = &elem->sprite;

    MainSprite_SetAnim(spr, elem->gfx, sLampAnimIdxs[elem->kind][1], PLAYMODE_LOOP, 0);
    MainSprite_SetPlttID(spr, sLampPlttIDs[elem->kind]);
    elem->flashTimer = 10;
    PlaySound_082406e0(SONG_331);
    Entity2D2BElem_RunScript(elem);
  }
  if (elem->stateTimer > 10) {
    Entity2D2BElem_SetState(elem, 2);
  }
}

void Entity2D2BElem_UpdateExtinguishing(Entity2D2B* p, Entity2D2BElem* elem) {
  if (Entity2D2BElem_ConsumeStateEntered(elem)) {
    MainSprite* spr = &elem->sprite;
    Vec3 pos;

    MainSprite_SetAnim(spr, elem->gfx, sLampAnimIdxs[elem->kind][0], PLAYMODE_LOOP, 0);
    MainSprite_SetPlttID(spr, sLampPlttIDs[elem->kind] + 1);
    elem->flashTimer = 10;
    Entity2D2BElem_RunScript(elem);
    pos = elem->sprite.pos;
    VEC3_SET(pos, elem->sprite.pos.x, elem->sprite.pos.y + 400, elem->sprite.pos.z);
    FUN_08015ce0(1, 2, 0x2001, Q6(1), 0, 0, 0, 0, 4, 2, &pos);
    VEC3_SET(pos, elem->sprite.pos.x - 64, elem->sprite.pos.y + 192, elem->sprite.pos.z + 64);
    FUN_08015ce0(1, 2, 0x2001, Q6(1), 0, 0, 0, 0, 4, 2, &pos);
    VEC3_SET(pos, elem->sprite.pos.x + 64, elem->sprite.pos.y + 192, elem->sprite.pos.z - 64);
    FUN_08015ce0(1, 2, 0x2001, Q6(1), 0, 0, 0, 0, 4, 2, &pos);
  }
  if (elem->stateTimer > 10) {
    Entity2D2BElem_SetState(elem, 1);
  }
}

void Entity2D2BElem_WalkPath(Entity2D2BElem* p) {
  PathWalker* walker = &p->walker;

  if (p->waitTimer != 0) {
    p->waitTimer--;
  } else {
    Vec3* pos = &p->sprite.pos;
    Vec3 step;
    u8 angle;

    if (Map_GetStepToPathNode(walker, pos, &step, &angle, p->radius, p->radius, p->speed)) {
      Map_AdvancePathWalker(walker);
      p->waitTimer = walker->node->delay & 0xFFF;
    }
    pos->x += step.x;
    p->sprite.pos.z += step.z;
  }
}

// エレベータの現在位置に yOffset を足した高さへ貼り付く
void Entity2D2BElem_FollowElevator(Entity2D2BElem* p) {
  Vec3* pos = p->elevatorPos;

  if (pos != NULL) {
    p->sprite.pos.x = pos->x;
    p->sprite.pos.y = pos->y + p->yOffset;
    p->sprite.pos.z = pos->z;
  }
}

s32 Entity2D2B_Update(Entity2D2B* p) {
  static void (*const PTR_ARRAY_085aa67c[5])(Entity2D2B*, Entity2D2BElem*) = {
      FUN_080080a8,
      Entity2D2BElem_UpdateUnlit,
      Entity2D2BElem_UpdateLit,
      Entity2D2BElem_UpdateLighting,
      Entity2D2BElem_UpdateExtinguishing,
  };  // 0x085aa67c

  Entity2D2BElem* elem = p->elems;
  u32 i;

  for (i = 0; i < (u32)p->count; i++, elem++) {
    if (elem->active) {
      if (elem->zoneID >= 0 && !Entity2D2B_IsCurrentZone(elem->zoneID)) {
        elem->sprite.flags |= SPRFLAG_HIDDEN;
        elem->hurtbox.flags |= HBFLAG_HIDDEN;
      } else {
        elem->sprite.flags &= ~SPRFLAG_HIDDEN;
        elem->hurtbox.flags &= ~HBFLAG_HIDDEN;
        PTR_ARRAY_085aa67c[elem->state](p, elem);
        if (elem->moveKind == LPM_HORIZONTAL) {
          Entity2D2BElem_WalkPath(elem);
        } else if (elem->moveKind == LPM_VERTICAL) {
          Entity2D2BElem_FollowElevator(elem);
        }
        MainSprite_AdvanceAnim(&elem->sprite, elem->gfx);
        Hitbox_SetPos(&elem->hurtbox, &elem->sprite.pos, 0);
        if (elem->flashTimer != 0) {
          if (--elem->flashTimer == 0) {
            elem->hurtbox.flags &= ~HBFLAG_HIDDEN;
          } else {
            elem->hurtbox.flags |= HBFLAG_HIDDEN;
          }
        }
        elem->stateTimer++;
      }
    }
  }
}

// 原典は return を書き忘れている
s32 Entity2D2B_Destroy(Entity2D2B* p) {
  Entity2D2BElem* elem = p->elems;
  u32 i;

  for (i = 0; i < (u32)p->count; i++, elem++) {
    if (elem->active) {
      Hitbox_Unregister(&elem->hurtbox);
      MainSprite_Remove(&elem->sprite);
    }
  }
  if (p->elems != NULL) {
    Free(p->elems);
    p->elems = NULL;
  }
  gEntity2D2B = NULL;
}

s32 Entity2D2B_Init(Entity2D2B* p) {
  Entity2D2BElem* elem;
  s32 size;
  s32 i;

  gEntity2D2B = p;
  for (i = 0; i < 2; i++) {
    MainSpriteGfxFile* f = GetFile(DIR_MAIN_SPRITE, sLampSpriteIDs[i]);

    if (f == NULL) {
      return -1;
    }
    p->gfx[i] = *f;
    OpenMainSpriteFile(&p->gfx[i], f);
  }
  p->count = VM_GetNamedArgValue('n', 8);
  size = p->count * sizeof(Entity2D2BElem);
  p->elems = Malloc(size);
  ClearMemory(p->elems, size);
  elem = p->elems;
  for (i = 0; (u32)i < (u32)p->count; i++, elem++) {
    Entity2D2BElem_Init(p, elem);
  }
}

// 0x2D2B
Entity2D2B* Entity2D2B_Create(void) {
  if (gEntity2D2B == NULL) {
    Entity2D2B* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity2D2B));

    if (p != NULL) {
      SetEntityRoutine(p, Entity2D2B_Update, Entity2D2B_Destroy);
      if (Entity2D2B_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity2D2B;
}

// 0x2E1C
s32 Entity2D2B_AddElemScripted(void) {
  Entity2D2B* p = gEntity2D2B;
  Entity2D2BElem* elem;
  Vec3 pos;
  bool32 hasPos;

  if (p == NULL) {
    return -1;
  }
  elem = Entity2D2B_FindFreeElem(p);
  if (elem == NULL) {
    return -1;
  }
  elem->moveKind = LPM_FIXED;
  hasPos = FALSE;
  if (VM_SeekToNamedArg('r')) {
    u32 pathIdx = VM_GetValue();
    u32 param_3 = VM_GetValue();
    u32 nodeIdx = VM_GetValue();

    if (!Map_InitPathWalker(&elem->walker, pathIdx, param_3, nodeIdx)) {
      return -1;
    }
    elem->moveKind = LPM_HORIZONTAL;
    elem->waitTimer = elem->walker.node->delay & 0xFFF;
    elem->speed = VM_GetValue();
    elem->radius = VM_GetValue();
    Map_ReadPathNodePos(&pos, elem->walker.node, 0);
    hasPos = TRUE;
  }
  if (VM_SeekToNamedArg('t')) {
    s32 id = VM_GetValue();

    elem->yOffset = VM_GetValue();
    elem->elevatorPos = Elevator_GetPosByID(id);
    if (elem->elevatorPos == NULL) {
      return -1;
    }
    elem->moveKind = LPM_VERTICAL;
    pos = *elem->elevatorPos;
    hasPos = TRUE;
  }
  if (VM_SeekToNamedArg('P')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    hasPos = TRUE;
  }
  if (!hasPos) {
    return -1;
  }
  Entity2D2BElem_SetState(elem, VM_GetNamedArgValue('m', 1));
  elem->unk_3 = VM_GetNamedArgValue('f', 0);
  elem->litDuration = VM_GetNamedArgValue('d', 120);
  elem->id = VM_GetNamedArgValue('n', 0);
  elem->kind = VM_GetNamedArgValue('D', 0);
  elem->gfx = &p->gfx[elem->kind];
  elem->scriptID = VM_GetNamedArgValue('p', 0);
  elem->scriptArg = VM_GetNamedArgValue('a', 0);
  if (elem->moveKind != LPM_VERTICAL) {
    pos.y = TileHeightAt(&pos);
  }
  elem->zoneID = VM_GetNamedArgValue('M', 0) ? GetZoneAt(&pos) : -1;
  elem->sprite.pos = pos;
  elem->sprite.flags &= ~SPRFLAG_HIDDEN;
  if (elem->state == 1) {
    MainSprite* spr = &elem->sprite;

    MainSprite_SetAnim(spr, elem->gfx, sLampAnimIdxs[elem->kind][0], PLAYMODE_LOOP, 0);
    MainSprite_SetPlttID(spr, sLampPlttIDs[elem->kind] + 1);
  } else {
    MainSprite* spr = &elem->sprite;

    MainSprite_SetAnim(spr, elem->gfx, sLampAnimIdxs[elem->kind][1], PLAYMODE_LOOP, 0);
    MainSprite_SetPlttID(spr, sLampPlttIDs[elem->kind]);
  }
  Video_AddMainSpriteIntoDrawList(&elem->sprite, 0);
  elem->active = TRUE;
  return 0;
}

// 0x8602, '.n' で指定した枠の点灯時間を '.d' に差し替える
void Entity2D2B_SetLitDurationScripted(void) {
  Entity2D2B* p = gEntity2D2B;

  if (p != NULL) {
    s32 id = VM_GetNamedArgValue('n', 0);
    s32 duration = VM_GetNamedArgValue('d', -1);
    Entity2D2BElem* elem = p->elems;
    u32 i;

    for (i = 0; i < (u32)p->count; i++, elem++) {
      if (elem->active == 1 && elem->id == id) {
        elem->litDuration = duration;
      }
    }
  }
}

// 0x19CC
void Entity2D2B_SetStateScripted(void) {
  Entity2D2B* p = gEntity2D2B;

  if (p != NULL) {
    s32 id = VM_GetNamedArgValue('n', 0);
    s32 state = VM_GetNamedArgValue('m', -1);

    if (state != -1 && state < 5) {
      Entity2D2BElem* elem = p->elems;
      u32 i;

      for (i = 0; i < (u32)p->count; i++, elem++) {
        if (elem->active == 1 && elem->id == id) {
          Entity2D2BElem_SetState(elem, state);
        }
      }
    }
  }
}
