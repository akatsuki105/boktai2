#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "trig.h"
#include "vec3.h"

typedef struct {
  AuxSprite spr;              // 0x000, _Destroy が AuxSprite_Remove に渡す
  AuxAnimState anim;          // 0x02C
  HitboxData hitbox;          // 0x03C, 攻撃判定, 当たると Entity080dd1f8Elem_OnHit で弾かれる
  HitboxData hurtbox;         // 0x08C, 食らい判定, Entity080dd1f8Elem_OnHurt で炎と氷に反応する
  ParticleShadow shadow;      // 0x0DC, _Destroy が ParticleShadow_Remove に渡す
  Vec3 vel;                   // 0x11C, 弾かれると Entity080dd1f8Elem_OnHit が書き換える
  Vec3 unk_124;               // 0x124, Entity080dd1f8_Spawn の第3引数
  u16 unk_12c;                // 0x12C, 爆発で片付けるときに 0
  u8 unk_12e;                 // 0x12E, PTR_ARRAY_085ad33c の添字, 2 だと FUN_080dd324 が 0 を返す
  s8 unk_12f;                 // 0x12F, activeMask 上の自分のビット番号, 空きは -1, 負だと FUN_080dd324 が 0 を返す
  bool8 unk_130;              // 0x130, 立っていると Entity080dd1f8Elem_StateExplode が爆発を出してから片付ける
  u8 unk_131;                 // 0x131, 弾かれると 12
  u16 unk_132;                // 0x132, 0 だと FUN_080dd324 が 0 を返す, 0x59 を超えていると unk_13e に戻される
  u8 unk_134[2];              // 0x134
  u16 unk_136;                // 0x136, Explosion_Create の power
  u16 unk_138;                // 0x138, Explosion_Create の knockback
  u8 unk_13a;                 // 0x13A
  u8 unk_13b;                 // 0x13B, 生成時に 1
  u16 unk_13c;                // 0x13C, 攻撃判定と食らい判定の id, FUN_08240cf0 の第6引数
  u16 unk_13e;                // 0x13E, unk_132 の戻し先の値
  u8 unk_140[0x144 - 0x140];  // 0x140
} Entity080dd1f8Elem;
static_assert(sizeof(Entity080dd1f8Elem) == 324);

typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx;              // 0x018, SPRITE_BOMB
  AuxAnimFile* anim;             // 0x034, ANIM_871C
  Entity080dd1f8Elem elems[12];  // 0x038, 根拠: _Destroy の stride 0x144 × 12
  u32 activeMask;                // 0xF68, 使用中の elems のビットマスク, _Init が 0 にする
} Entity080dd1f8;
static_assert(sizeof(Entity080dd1f8) == 3948);

IWRAM_DATA Entity080dd1f8* gEntity080dd1f8 = NULL;  // 0x0300016C

struct Explosion* Explosion_Create(Vec3* pos, s32 ignoreMask, s32 power, s32 knockback, s32 plttOffset);
void FUN_08240cf0(s32 x, s32 z, s16 param_3, s32 param_4, u8 param_5, u16 param_6);
void Entity080dd1f8Elem_OnHurt(HitboxData* a, HitboxData* b, Entity080dd1f8Elem* elem);
Entity080dd1f8* Entity080dd1f8_Create(void);

const u8 u8_ARRAY_085ad338[4] = {0, 8, 4, 2};  // 0x085AD338

static inline bool8 Entity080dd1f8_IsElemUsed(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void FUN_080dc4a4(Entity080dd1f8* p, Entity080dd1f8Elem* elem) {}

// 攻撃判定が当たったら当てた相手から離れる向きへ弾かれる, 相手より上なら跳ね上がり, そうでなければ横へ押される
void Entity080dd1f8Elem_OnHit(HitboxData* a, HitboxData* b, Entity080dd1f8Elem* elem) {
  Vec3 diff;
  Vec3 v;
  s32 angle;

  Vec3_Delta(&diff, &b->pos, &a->pos);
  angle = ArcTan2_8(diff.x, diff.z);
  angle = ((angle + 16) & 0xFF) >> 5 << 5;
  if (diff.y > 0) {
    Vec3_SetPolar(&v, angle, 4);
    v.y = -4;
    elem->vel.x = v.x;
    elem->vel.y = v.y;
    elem->vel.z = v.z;
  } else {
    Vec3_SetPolar(&v, angle, 18);
    v.y = 32;
    elem->vel.x += v.x;
    elem->vel.y += v.y;
    elem->vel.z += v.z;
  }
  elem->spr.pos.y++;
  elem->unk_131 = 12;
  PlaySound_082406e0(358);
}

// 判定の属性でタイマーを止めるか初期値に戻すかを決める
// 残差2命令 (28 対 30), 原典は elem を r12 に逃がして第2分岐で add r1, ip を使うが, こちらは r3 に置けてしまう (leaf なので r4-r7 は使えない)
// && / 条件の反転 / u16* ローカルは試済
NON_MATCH void Entity080dd1f8Elem_OnHurt(HitboxData* a, HitboxData* b, Entity080dd1f8Elem* elem) {
#ifdef NONMATCHING_C
  if (Hitbox_TestAttr(a, HBATTR_FLAME)) {
    elem->unk_132 = 0;
  } else if (Hitbox_TestAttr(a, HBATTR_FROST)) {
    if (elem->unk_132 > 0x59) {
      elem->unk_132 = elem->unk_13e;
    }
  }
#else
  INCFUNC("asm/func/Entity080dd1f8Elem_OnHurt.inc");
#endif
}

// 攻撃判定と食らい判定を作る
void Entity080dd1f8Elem_InitHitboxes(Entity080dd1f8Elem* elem, u16 power, u16 knockback) {
  HitboxData* hitbox;
  HitboxData* hurtbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 32, 32, 32);
  VEC3_SET(offset, 0, 32, 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, elem->unk_13c, HBFLAG_HITBOX | HBFLAG_UNK_1 | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, (s16)power, (s16)knockback, 0, 0, 0);
  Hitbox_SetPos(hitbox, &elem->spr.pos, 0);
  Hitbox_SetHandler(hitbox, Entity080dd1f8Elem_OnHit, elem);
  VEC3_SET(halfSize, 64, 128, 64);
  VEC3_SET(offset, 0, 128, 0);
  hurtbox = &elem->hurtbox;
  Hitbox_Init(hurtbox, elem->unk_13c, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &elem->spr.pos, 0);
  Hitbox_SetHandler(hurtbox, Entity080dd1f8Elem_OnHurt, elem);
  Hitbox_Register(hurtbox);
}

Entity080dd1f8Elem* Entity080dd1f8_AllocElem(Entity080dd1f8* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!Entity080dd1f8_IsElemUsed(&p->activeMask, i)) {
      Entity080dd1f8Elem* elem = &p->elems[i];

      p->activeMask |= 1 << i;
      elem->unk_12f = i;
      return elem;
    }
  }
  return NULL;
}

NAKED void FUN_080dc7bc(Entity080dd1f8* p, Entity080dd1f8Elem* elem) { INCFUNC("asm/func/FUN_080dc7bc.inc"); }

// 爆発の印が立っていれば爆発と効果音を出し, 自分を片付ける
// 79/79命令, activeMask を落とすところで原典は gEntity080dd1f8 を読み &unk_12f を作って添字を読んでから +0xF68 する (こちらは &activeMask を先に作る), 試済: CLEAR_BIT, グローバルのローカル写し, a = a & ~b の形
NON_MATCH void Entity080dd1f8Elem_StateExplode(Entity080dd1f8* p, Entity080dd1f8Elem* elem) {
#ifdef NONMATCHING_C
  if (elem->unk_130) {
    Explosion_Create(&elem->spr.pos, 32, elem->unk_136, elem->unk_138, 0);
    FUN_08240cf0(elem->spr.pos.x, elem->spr.pos.z, 0x400, 0, 1, elem->unk_13c);
    elem->unk_130 = FALSE;
  }
  gEntity080dd1f8->activeMask &= ~(1 << elem->unk_12f);
  elem->unk_12e = 0;
  AuxSprite_Remove(&elem->spr);
  ParticleShadow_Remove(&elem->shadow);
  Hitbox_Unregister(&elem->hurtbox);
  elem->unk_12f = -1;
  elem->unk_12c = 0;
  elem->unk_132 = 0;
#else
  INCFUNC("asm/func/Entity080dd1f8Elem_StateExplode.inc");
#endif
}

// 爆弾を1つ置く, ゲームオーバー中や 1P が倒れているときと空きが無いときは NULL
Entity080dd1f8Elem* Entity080dd1f8_Spawn(Vec3* pos, Vec3* vel, Vec3* unk_124, s32 power, s32 knockback, s32 timer, s32 id) {
  Entity080dd1f8* p = gEntity080dd1f8;
  Entity080dd1f8Elem* elem;
  AuxSprite* spr;

  if (p == NULL) {
    p = Entity080dd1f8_Create();
    if (p == NULL) {
      return NULL;
    }
  }
  if (TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER)) {
    return NULL;
  }
  if (TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    return NULL;
  }
  elem = Entity080dd1f8_AllocElem(p);
  if (elem == NULL) {
    return NULL;
  }
  elem->unk_12e = 1;
  elem->unk_12c = 0;
  elem->unk_124 = *unk_124;
  elem->unk_130 = TRUE;
  elem->vel = *vel;
  elem->unk_136 = power;
  elem->unk_138 = knockback;
  elem->unk_13e = timer;
  elem->unk_132 = timer;
  elem->unk_131 = 30;
  elem->unk_13c = id;
  elem->unk_13b = 1;
  spr = &elem->spr;
  elem->spr.pos = *pos;
  AuxSprite_Add(spr, &p->gfx, 0);
  AuxAnim_SetAnim(&elem->anim, p->anim, 1, 0, 0);
  AuxSprite_AdvanceAnim(spr, &elem->anim);
  spr->flags |= SPRFLAG_HIDDEN;
  spr->priority = 1;
  ParticleShadow_Init(&elem->shadow, &spr->pos, 0);
  Entity080dd1f8Elem_InitHitboxes(elem, 0, 0);
  return elem;
}

void (*const PTR_ARRAY_085ad33c[3])(Entity080dd1f8*, Entity080dd1f8Elem*) = {
    FUN_080dc4a4,
    FUN_080dc7bc,
    Entity080dd1f8Elem_StateExplode,
};  // 0x085AD33C

s32 Entity080dd1f8_Update(Entity080dd1f8* p) {
  Entity080dd1f8Elem* elems = p->elems;
  s32 i;

  if (p->activeMask != 0 && !TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER) && !TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    for (i = 0; i < 12; i++) {
      if (Entity080dd1f8_IsElemUsed(&p->activeMask, i)) {
        PTR_ARRAY_085ad33c[elems[i].unk_12e](p, &elems[i]);
      }
    }
  }
  return 0;
}

s32 Entity080dd1f8_Destroy(Entity080dd1f8* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (Entity080dd1f8_IsElemUsed(&p->activeMask, i)) {
      Entity080dd1f8Elem* elem = &p->elems[i];

      AuxSprite_Remove(&elem->spr);
      ParticleShadow_Remove(&elem->shadow);
    }
  }
  gEntity080dd1f8 = NULL;
  return 0;
}

s32 Entity080dd1f8_Init(Entity080dd1f8* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_BOMB);
  p->anim = GetFile(DIR_ANIMATION, ANIM_871C);
  p->activeMask = 0;
  gEntity080dd1f8 = p;
  return 0;
}

Entity080dd1f8* Entity080dd1f8_Create(void) {
  if (gEntity080dd1f8 == NULL) {
    Entity080dd1f8* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity080dd1f8));
    if (p != NULL) {
      SetEntityRoutine(p, Entity080dd1f8_Update, Entity080dd1f8_Destroy);
      if (Entity080dd1f8_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080dd1f8;
}

void FUN_080dd244(void) { gEntity080dd1f8 = NULL; }

// pos から 320 未満の距離にある生きた爆弾を探し, 見つかればその向きを返す, 無ければ -1
s32 FUN_080dd250(Vec3* pos) {
  Entity080dd1f8* p = gEntity080dd1f8;
  Entity080dd1f8Elem* elems;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  elems = p->elems;
  if (p->activeMask == 0) {
    return -1;
  }
  for (i = 0; i < 12; i++) {
    if (Entity080dd1f8_IsElemUsed(&p->activeMask, i) && elems[i].unk_12f >= 0 && elems[i].unk_132 != 0 && elems[i].unk_12e != 2) {
      Vec3 diff;

      Vec3_Delta(&diff, pos, &elems[i].spr.pos);
      if (diff.x * diff.x + diff.z * diff.z < 0x19000) {
        return ArcTan2_8(diff.x, diff.z);
      }
    }
  }
  return -1;
}

// elem が生きていて片付け待ちでもないかを返す
s32 FUN_080dd324(void* p) {
  Entity080dd1f8Elem* elem = p;

  if (elem == NULL) {
    return 0;
  }
  if (elem->unk_12f < 0) {
    return 0;
  }
  if (elem->unk_132 == 0) {
    return 0;
  }
  if (elem->unk_12e == 2) {
    return 0;
  }
  return 1;
}

NAKED void Cmd_AE71(void) { INCFUNC("asm/func/Cmd_AE71.inc"); }
