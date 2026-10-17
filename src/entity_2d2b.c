#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "sprite.h"
#include "vm.h"

// 炎を当てると点き、氷を当てると消える照明, 1体の Entity2D2B が count 個を抱える
typedef struct {
  bool8 active;        // 0x000, 使用中の枠か
  u8 moveKind;         // 0x001, 0 固定, 1 経路に沿って動く, 2 エレベータに乗る
  u8 state;            // 0x002, '.m=1', 1 消灯, 2 点灯, 3 点灯への遷移, 4 消灯への遷移, 0 は何もしない
  u8 unk_3;            // 0x003, '.f=0', 読み手が見つかっていない
  bool8 stateEntered;  // 0x004, state が変わった直後だけ立つ, 遷移時の初期化を1回で済ませるために使う
  u8 flashTimer;       // 0x005, 遷移の直後 10 フレーム, 0 でない間だけ hitbox.flags に HBFLAG_UNK_2 が立つ
  s16 yOffset;         // 0x006, '.t[1]', エレベータの位置に足す高さ
  s16 litDuration;     // 0x008, '.d=120', 点灯から自然に消えるまでのフレーム数, 負なら消えない
  u16 waitTimer;       // 0x00A, 経路ノードでの待ちフレーム, PathNode の下位12bit が入る
  s32 stateTimer;      // 0x00C, state が変わってからのフレーム数
  u16 id;              // 0x010, '.n=0', hitbox の id と スクリプトの第1引数を兼ねる
  u16 scriptID;        // 0x012, '.p=0', 遷移するたびに実行する, 0 なら実行しない
  s32 areaID;          // 0x014, '.M' が 0 なら -1 でエリア無制限, それ以外は設置位置のエリア, gStat->unk_248 と比べる
  s32 kindIdx;         // 0x018, '.D=0', 0 シャンデリア, 1 ろうそく箱
  u32 scriptArg;       // 0x01C, '.a=0', スクリプトの第3引数
  Vec3* elevatorPos;   // 0x020, '.t[0]' で指定したエレベータの現在位置
  s16 speed;           // 0x024, '.r[3]', 経路上を進む速さ
  s16 radius;          // 0x026, '.r[4]', 経路ノードに着いたと見なす距離
  PathWalker walker;   // 0x028, '.r[0]' 経路番号, '.r[1]', '.r[2]' 開始ノード
  MainSprite sprite;   // 0x034
  HitboxData hitbox;   // 0x094, 半径 {0x80, 0x80, 0x80}, offset {0, 0x80, 0}, flags 0x4001
  MainSpriteGfx* gfx;  // 0x0E4, kindIdx が選んだ親の gfx
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

const FileID u16_ARRAY_085aa66c[2] = {
    SPRITE_CHANDELIER,
    SPRITE_CANDLE_BOX,
};  // 0x085aa66c

const u16 u16_ARRAY_085aa670[4] = {0, 1, 0, 1};

const u16 u16_ARRAY_085aa678[2] = {64, 739};

void FUN_080080a8(Entity2D2B*, Entity2D2BElem*);
void Entity2D2BElem_UpdateUnlit(Entity2D2B*, Entity2D2BElem*);
void Entity2D2BElem_UpdateLit(Entity2D2B*, Entity2D2BElem*);
void Entity2D2BElem_UpdateLighting(Entity2D2B*, Entity2D2BElem*);
void Entity2D2BElem_UpdateExtinguishing(Entity2D2B*, Entity2D2BElem*);

void (*const PTR_ARRAY_085aa67c[5])(Entity2D2B*, Entity2D2BElem*) = {
    FUN_080080a8,
    Entity2D2BElem_UpdateUnlit,
    Entity2D2BElem_UpdateLit,
    Entity2D2BElem_UpdateLighting,
    Entity2D2BElem_UpdateExtinguishing,
};  // 0x085aa67c

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

void Entity2D2BElem_SetState(Entity2D2BElem* p, u8 state) {
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
// 残差1命令, 原典は owner のレジスタから写しを作って2つ目の遷移に使う (FUN_0807b1a4 系と同じ)
NON_MATCH void Entity2D2BElem_OnHit(HitboxData* a, HitboxData* b, Entity2D2BElem* owner) {
#ifdef NONMATCHING_C
  if (owner->state == 1) {
    if (Hitbox_TestAttribute(a, HBATTR_FLAME)) {
      Entity2D2BElem_SetState(owner, 3);
    }
  } else if (owner->state == 2) {
    if (Hitbox_TestAttribute(a, HBATTR_FROST)) {
      Entity2D2BElem_SetState(owner, 4);
    }
  }
#else
  INCFUNC("asm/func/Entity2D2BElem_OnHit.inc");
#endif
}

NAKED s32 Entity2D2BElem_Init(Entity2D2B* p, Entity2D2BElem* elem) { INCFUNC("asm/func/Entity2D2BElem_Init.inc"); }

NAKED void Entity2D2BElem_RunScript(Entity2D2BElem* p) { INCFUNC("asm/func/Entity2D2BElem_RunScript.inc"); }

void FUN_080080a8(Entity2D2B* p, Entity2D2BElem* elem) {}

NAKED void Entity2D2BElem_UpdateUnlit(Entity2D2B* p, Entity2D2BElem* elem) { INCFUNC("asm/func/Entity2D2BElem_UpdateUnlit.inc"); }

NAKED void Entity2D2BElem_UpdateLit(Entity2D2B* p, Entity2D2BElem* elem) { INCFUNC("asm/func/Entity2D2BElem_UpdateLit.inc"); }

NAKED void Entity2D2BElem_UpdateLighting(Entity2D2B* p, Entity2D2BElem* elem) { INCFUNC("asm/func/Entity2D2BElem_UpdateLighting.inc"); }

NAKED void Entity2D2BElem_UpdateExtinguishing(Entity2D2B* p, Entity2D2BElem* elem) { INCFUNC("asm/func/Entity2D2BElem_UpdateExtinguishing.inc"); }

NAKED void Entity2D2BElem_WalkPath(Entity2D2BElem* p) { INCFUNC("asm/func/Entity2D2BElem_WalkPath.inc"); }

// エレベータの現在位置に yOffset を足した高さへ貼り付く
void Entity2D2BElem_FollowElevator(Entity2D2BElem* p) {
  Vec3* pos = p->elevatorPos;

  if (pos != NULL) {
    p->sprite.pos.x = pos->x;
    p->sprite.pos.y = pos->y + p->yOffset;
    p->sprite.pos.z = pos->z;
  }
}

NAKED s32 Entity2D2B_Update(Entity2D2B* p) { INCFUNC("asm/func/Entity2D2B_Update.inc"); }

// 原典は return を書き忘れている
s32 Entity2D2B_Destroy(Entity2D2B* p) {
  Entity2D2BElem* elem = p->elems;
  u32 i;

  for (i = 0; i < (u32)p->count; i++, elem++) {
    if (elem->active) {
      Hitbox_Unregister(&elem->hitbox);
      MainSprite_Remove(&elem->sprite);
    }
  }
  if (p->elems != NULL) {
    Free(p->elems);
    p->elems = NULL;
  }
  gEntity2D2B = NULL;
}

NAKED s32 Entity2D2B_Init(Entity2D2B* p) { INCFUNC("asm/func/Entity2D2B_Init.inc"); }

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

NAKED s32 Entity2D2B_AddElemScripted(void) { INCFUNC("asm/func/Entity2D2B_AddElemScripted.inc"); }

// '.n' で指定した枠の点灯時間を '.d' に差し替える
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

NAKED void Entity2D2B_SetStateScripted(void) { INCFUNC("asm/func/Entity2D2B_SetStateScripted.inc"); }
