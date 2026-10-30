#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "malloc.h"
#include "map_inline.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "vm.h"

// リストに繋がれるノード, prev/next 以外はまだ未解析で全体の大きさも未確定
typedef struct Entity08016660Node {
  u8 unk_00;                        // 0x00, まだ未解析
  bool8 unk_01;                     // 0x01
  u8 fnIdx;                         // 0x02, PTR_ARRAY_085aa918 の添字
  u8 flags;                         // 0x03, bit0 が立っていればヒットボックスを2つ持つ
  bool8 unk_04;                     // 0x04, 立っていれば消える
  bool8 unk_05;                     // 0x05, 消えるときに立てる
  u16 timer;                        // 0x06, unk_08 を超えたら 0 に戻る
  u16 unk_08;                       // 0x08, timer の上限
  u8 unk_0a[2];                     // 0x0A, まだ未解析
  Vec3 pos;                         // 0x0C, ヒットボックスの位置
  s16 floorY;                       // 0x14, pos の足元の高さ
  s16 hp;                           // 0x16, 被弾のたびにダメージを引く, 0 止まり
  HitboxData* hitbox;               // 0x18, 非NULL なら解放時に Hitbox_Unregister して Free する
  HitboxData* hitbox2;              // 0x1C, 非NULL なら解放時に Free する, 毎フレーム Hitbox_Register する
  AuxSpriteGfx gfx;                 // 0x20, SPRITE_863A
  AuxSprite sprite;                 // 0x3C, 解放時に AuxSprite_Remove する
  AuxAnimState anim;                // 0x68
  struct Entity08016660Node* prev;  // 0x78
  struct Entity08016660Node* next;  // 0x7C
} Entity08016660Node;

typedef struct {
  Entity e;                  // ENTITY_UNK_8
  AuxAnimFile* anim;         // 0x18, 根拠: Entity08016660_Init
  Entity08016660Node* list;  // 0x1C, FUN_08016094 が先頭挿入する双方向リスト
} Entity08016660;
static_assert(sizeof(Entity08016660) == 32);

COMMON_DATA Entity08016660* gEntity08016660 = NULL;  // 0x03002B44

static inline void Entity08016660Node_SetFn(Entity08016660Node* p, u32 idx) {
  p->fnIdx = idx;
  p->timer = 0;
}

void FUN_08016430(Entity08016660Node*);
Entity08016660* Entity08016660_Create(u32 id, u32 _);
void Hitbox_SetPower(HitboxData* p, u16 power, u16 knockbackPower);
void FUN_08016454(Entity08016660Node*);

void (*const PTR_ARRAY_085aa918[2])(Entity08016660Node*) = {
    FUN_08016430,
    FUN_08016454,
};  // 0x085AA918

void FUN_08016060(void) { gEntity08016660 = NULL; }

// 氷属性なら2倍のダメージを hp から引く
void FUN_0801606c(HitboxData* a, HitboxData* b, Entity08016660Node* node) {
  s32 damage = b->damage;

  if (Hitbox_TestAttr(a, HBATTR_FROST)) {
    damage *= 2;
  }

  node->hp -= damage;
  if ((s16)node->hp < 0) {
    node->hp = 0;
  }
}

void nop_08016090(void) { return; }

// ノードをリストの先頭に繋ぐ
s32 FUN_08016094(Entity08016660* p, Entity08016660Node* node) {
  node->prev = NULL;
  node->next = p->list;
  if (node->next != NULL) {
    node->next->prev = node;
  }

  p->list = node;
  return 0;
}

// ノードをリストから外す
s32 FUN_080160b0(Entity08016660* p, Entity08016660Node* node) {
  Entity08016660Node* prev = node->prev;
  Entity08016660Node* next = node->next;

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

// ノードの持ち物を外して Free する
s32 FUN_080160cc(Entity08016660Node* node) {
  AuxSprite_Remove(&node->sprite);

  if (gEntity08016660 != NULL) {
    FUN_080160b0(gEntity08016660, node);
  }

  if (node->hitbox != NULL) {
    Hitbox_Unregister(node->hitbox);
    Free(node->hitbox);
  }

  if (node->hitbox2 != NULL) {
    Free(node->hitbox2);
  }

  Free(node);
}

// 残差は最後の初期化で 0 を入れる定数の持ち方だけ (258/259), 原典は fnIdx / timer に r6 の 0 を使い, unk_05 / prev / next には改めて movs r0, #0 を作る
// Entity08016660_Create は2引数で呼んでいたので宣言を (u32 id, u32 _) にした, ヒットボックスは flags bit0 が立っている側を then にすると分岐の並びが合う
// 燃えるエフェクトのノードを作って pos に置き, flags bit0 なら食らい判定と攻撃判定も付けてリストに繋ぐ
NON_MATCH s32 FUN_08016110(u32 val1, u32 val2, u32 val3, u32 val4, Vec3* pos) {
#ifdef NONMATCHING_C
  Entity08016660Node* node;
  Vec3 size, offset;

  if (gEntity08016660 == NULL && Entity08016660_Create(0xC0DB, 0) == NULL) {
    return -1;
  }
  node = Malloc(sizeof(Entity08016660Node));
  if (node == NULL) {
    return -1;
  }
  ClearMemory(node, sizeof(Entity08016660Node));
  node->unk_00 = val1;
  node->flags = val2;
  node->unk_08 = val3;
  node->pos = *pos;
  node->floorY = TileHeightAt(&node->pos);
  node->hp = val4;

  if (node->flags & 1) {
    node->hitbox = Malloc(sizeof(HitboxData));
    if (node->hitbox == NULL) {
      return -1;
    }
    ClearMemory(node->hitbox, sizeof(HitboxData));
    size.x = 90, size.y = 128, size.z = 90;
    offset.x = 0, offset.y = 128, offset.z = 0;
    Hitbox_Init(node->hitbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
    Hitbox_SetHandler(node->hitbox, FUN_0801606c, node);
    Hitbox_Register(node->hitbox);
    Hitbox_SetPos(node->hitbox, &node->pos, 0);
  } else {
    node->hitbox = NULL;
  }

  if (node->flags & 1) {
    node->hitbox2 = Malloc(sizeof(HitboxData));
    if (node->hitbox2 == NULL) {
      return -1;
    }
    ClearMemory(node->hitbox2, sizeof(HitboxData));
    size.x = 100, size.y = 120, size.z = 100;
    offset.x = 0, offset.y = 0, offset.z = 0;
    Hitbox_Init(node->hitbox2, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
    Hitbox_SetHandler(node->hitbox2, nop_08016090, node);
    Hitbox_SetPower(node->hitbox2, 50, 20);
    Hitbox_Register(node->hitbox2);
    Hitbox_SetPos(node->hitbox2, &node->pos, 0);
  } else {
    node->hitbox2 = NULL;
  }

  if (!Video_GetAuxSprite(&node->gfx, SPRITE_863A)) {
    return -1;
  }
  AuxSprite_Add(&node->sprite, &node->gfx, SPRFLAG_HIDDEN);
  node->sprite.priority = 2;
  AuxAnim_SetAnim(&node->anim, gEntity08016660->anim, 1, 0, 0);
  Video_SetAuxSpritePltt(&node->gfx, node->unk_00 + 275);
  if (node->unk_08 == 0) {
    Entity08016660Node_SetFn(node, 1);
  } else {
    Entity08016660Node_SetFn(node, 0);
  }
  node->unk_01 = TRUE;
  node->unk_05 = FALSE;
  node->prev = NULL;
  node->next = NULL;
  return FUN_08016094(gEntity08016660, node);
#else
  INCFUNC("asm/func/FUN_08016110.inc");
#endif
}

// VM の名前付き引数から FUN_08016110 を呼ぶ
s32 UNUSED FUN_0801638c(void) {
  u32 t = VM_GetNamedArgValue('t', 0);
  u32 f = VM_GetNamedArgValue('f', 0);
  u32 e = VM_GetNamedArgValue('e', 0);
  u32 l = VM_GetNamedArgValue('l', 0);
  Vec3 pos;

  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetValue();
    pos.y = VM_GetValue();
    pos.z = VM_GetValue();
  } else {
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
  }
  return FUN_08016110(t, f, e, l, &pos);
}

// timer が上限を超えたら FUN_08016454 へ進める
void FUN_08016430(Entity08016660Node* p) {
  if (p->timer++ > p->unk_08) {
    Entity08016660Node_SetFn(p, 1);
    p->unk_01 = 1;
  }
}

// 表示して動きを始め, hp が尽きるか unk_04 で消える印を立てる, それまでヒットボックスを毎フレーム置く
void FUN_08016454(Entity08016660Node* p) {
  if (p->unk_01) {
    p->unk_01 = FALSE;
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    AuxAnim_SetAnim(&p->anim, gEntity08016660->anim, 1, 0, 0);
  }
  if (p->hp <= 0 || p->unk_04) {
    p->unk_05 = TRUE;
  } else {
    if (p->hitbox != NULL) {
      Hitbox_SetPos(p->hitbox, &p->pos, 0);
    }
    if (p->hitbox2 != NULL) {
      Hitbox_SetPos(p->hitbox2, &p->pos, 0);
      Hitbox_Register(p->hitbox2);
    }
    p->timer++;
  }
}

// 各ノードのアニメを1コマ進め, 位置を合わせて fnIdx の処理を呼ぶ, 消える印のノードは解放する
s32 Entity08016660_Update(Entity08016660* p) {
  Entity08016660Node* node = p->list;

  while (node != NULL) {
    Entity08016660Node* next = node->next;

    if (node->unk_05) {
      FUN_080160cc(node);
    } else {
      node->unk_04 = AuxSprite_AdvanceAnim(&node->sprite, &node->anim);
      node->sprite.pos = node->pos;
      PTR_ARRAY_085aa918[node->fnIdx](node);
    }
    node = next;
  }
  return 0;
}

s32 Entity08016660_Destroy(Entity08016660* p) {
  Entity08016660Node* node = p->list;

  while (node != NULL) {
    Entity08016660Node* next = node->next;

    FUN_080160cc(node);
    node = next;
  }

  gEntity08016660 = NULL;
  return 0;
}

s32 Entity08016660_Init(Entity08016660* p, u32 id) {
  gEntity08016660 = p;
  p->anim = GetFile(DIR_ANIMATION, ANIM_931E);
  p->list = NULL;
  return 0;
}

Entity08016660* Entity08016660_Create(u32 id, u32 _) {
  Entity08016660* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity08016660));

  if (p != NULL) {
    SetEntityRoutine(p, Entity08016660_Update, Entity08016660_Destroy);
    if (Entity08016660_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }

  return p;
}
