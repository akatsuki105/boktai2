#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "player.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "trig.h"
#include "vec3.h"
#include "vm.h"

typedef struct {
  AuxSprite spr;          // 0x000, _Destroy が AuxSprite_Remove に渡す
  AuxAnimState anim;      // 0x02C
  HitboxData hitbox;      // 0x03C, 攻撃判定, 当たると Entity080dd1f8Elem_OnHit で弾かれる
  HitboxData hurtbox;     // 0x08C, 食らい判定, Entity080dd1f8Elem_OnHurt で炎と氷に反応する
  ParticleShadow shadow;  // 0x0DC, _Destroy が ParticleShadow_Remove に渡す
  Vec3 vel;               // 0x11C, 弾かれると Entity080dd1f8Elem_OnHit が書き換える
  Vec3 unk_124;           // 0x124, Entity080dd1f8_Spawn の第3引数
  u16 unk_12c;            // 0x12C, 爆発で片付けるときに 0
  u8 unk_12e;             // 0x12E, PTR_ARRAY_085ad33c の添字, 2 だと FUN_080dd324 が 0 を返す
  s8 unk_12f;             // 0x12F, activeMask 上の自分のビット番号, 空きは -1, 負だと FUN_080dd324 が 0 を返す
  bool8 unk_130;          // 0x130, 状態に入った最初のフレームだけ立つ, 爆発の状態では立っていると爆発を出す
  u8 unk_131;             // 0x131, 弾かれると 12
  u16 unk_132;            // 0x132, 0 だと FUN_080dd324 が 0 を返す, 0x59 を超えていると unk_13e に戻される
  u16 unk_134;            // 0x134, 今いるタイルの索引
  u16 unk_136;            // 0x136, Explosion_Create の power
  u16 unk_138;            // 0x138, Explosion_Create の knockback
  u8 unk_13a;             // 0x13A, 0 になると点滅のアニメを切り替える
  u8 unk_13b;             // 0x13B, 流しているアニメ番号 (1 か 2)
  u16 unk_13c;            // 0x13C, 攻撃判定と食らい判定の id, FUN_08240cf0 の第6引数
  u16 unk_13e;            // 0x13E, unk_132 の戻し先の値
  u16 unk_140;            // 0x140, 状態に入ってからのフレーム数
  u8 unk_142[2];          // 0x142
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

// state 1, 目標の近くまで来るか 8 フレーム経つと落ち始め, 地面で弾みながら転がり, 導火線が尽きたら爆発へ移る
// 698/714命令, 2回目の下書き (呼び出し列は一致), 原典は &spr.pos をスタック (sp+0x24) に置き vel を r4 から触る, pos / vel をポインタのローカルにすると 16 命令少なくなり, 直接アクセスだと 727 命令
NON_MATCH void Entity080dd1f8Elem_StateRoll(Entity080dd1f8* p, Entity080dd1f8Elem* elem) {
#ifdef NONMATCHING_C
  AuxSprite* spr = &elem->spr;
  Vec3* pos;
  Vec3* vel;
  u32 tile;
  s32 height;

  if (elem->unk_130) {
    elem->spr.flags &= ~SPRFLAG_HIDDEN;
    elem->unk_140 = 0;
    elem->unk_130 = FALSE;
  }
  pos = &elem->spr.pos;
  elem->unk_134 = GetCollisionTileIdx(pos);
  if (elem->unk_12c & 1) {
    if (spr->pos.y > TileHeightAtIndex(elem->unk_134, &spr->pos)) {
      elem->vel.y -= 4;
    }
  } else {
    Vec3 d;

    Vec3_Delta(&d, &spr->pos, &elem->unk_124);
    if (d.x * d.x + d.z * d.z < 0x40000 || elem->unk_140 > 8) {
      elem->unk_12c |= 1;
      elem->vel.y -= 4;
    }
  }
  tile = elem->unk_134;
  vel = &elem->vel;
  ArcTan2_8(vel->x, vel->z);
  height = TileHeightAtIndex(tile, pos);
  if (vel->x + vel->z + vel->y != 0) {
    WorldPos next;
    u32 nextTile;
    s32 nextHeight;
    TileAttr attr;

    if (pos->y <= height) {
      vel->x = Div(vel->x * 6, 10);
      vel->y = -Div(vel->y * 4, 10);
      vel->z = Div(vel->z * 6, 10);
      if (abs(vel->x + vel->z + vel->y) <= 2) {
        vel->x = 0;
        vel->y = 0;
        vel->z = 0;
      } else {
        PlaySound_082406e0(358);
      }
      pos->y = height;
    }
    Vec3_Sum(&next, pos, vel);
    nextTile = GetCollisionTileIdx(&next);
    nextHeight = TileHeightAtIndex(nextTile, &next);
    attr = TileAtIndex(nextTile)->attr;
    if (tile != nextTile && (height < nextHeight || (TileAtIndex(nextTile)->attr & 3))) {
      vel->x = -Div(vel->x * 5, 10);
      vel->z = -Div(vel->z * 5, 10);
      PlaySound_082406e0(358);
    }
    if ((nextHeight <= 0 || (attr & 0x40)) && (s16)(vel->y + pos->y) <= nextHeight) {
      gEntity080dd1f8->activeMask &= ~(1 << elem->unk_12f);
      elem->unk_12e = 0;
      AuxSprite_Remove(&elem->spr);
      ParticleShadow_Remove(&elem->shadow);
      Hitbox_Unregister(&elem->hurtbox);
      elem->unk_12f = -1;
      elem->unk_12c = 0;
      elem->unk_132 = 0;
    } else {
      pos->x += vel->x;
      pos->y += vel->y;
      pos->z += vel->z;
    }
  }
  Hitbox_SetPos(&elem->hurtbox, &spr->pos, 0);
  if (elem->unk_131 == 0) {
    Hitbox_SetPos(&elem->hitbox, &spr->pos, 0);
    Hitbox_Register(&elem->hitbox);
  } else {
    elem->unk_131--;
  }
  if (elem->unk_13a == 0) {
    s32 k;

    if (elem->unk_132 < 30) {
      k = 3;
    } else if (elem->unk_132 < 50) {
      k = 2;
    } else if (elem->unk_132 <= 89) {
      k = 1;
    } else {
      goto skip;
    }
    {
      u16 tick = elem->anim.tick;
      u16 cmdIdx = elem->anim.cmdIdx;

      if (elem->unk_13b == 1) {
        AuxAnim_SetAnim(&elem->anim, p->anim, 2, 0, 0);
        elem->unk_13b = 2;
      } else {
        AuxAnim_SetAnim(&elem->anim, p->anim, 1, 0, 0);
        elem->unk_13b = 1;
      }
      elem->anim.tick = tick;
      elem->anim.cmdIdx = cmdIdx;
      elem->unk_13a = u8_ARRAY_085ad338[k];
    }
  } else {
    elem->unk_13a--;
  }
skip:
  AuxSprite_AdvanceAnim(spr, &elem->anim);
  elem->unk_140++;
  if (elem->unk_132 == 0) {
    elem->unk_12e = 2;
    elem->unk_130 = TRUE;
  } else {
    elem->unk_132--;
  }
#else
  INCFUNC("asm/func/Entity080dd1f8Elem_StateRoll.inc");
#endif
}

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
    Entity080dd1f8Elem_StateRoll,
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

// スクリプトから爆弾を1つ置く, '.p' が位置, '.a' が威力とノックバック, '.v' が速度, '.l' が爆発までの時間, '.n' が判定の id
void Cmd_AE71(void) {
  Vec3 pos;
  Vec3 vel;
  Vec3 zero;
  s32 knockback = 0;
  s32 power = 0;
  s32 timer;
  s32 id;

  if (VM_SeekToNamedArg('p')) {
    pos.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    pos.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    pos.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  if (VM_SeekToNamedArg('a')) {
    power = VM_GetPC() != NULL ? VM_GetValue() : 0;
    knockback = VM_GetPC() != NULL ? VM_GetValue() : 0;
  }
  if (VM_SeekToNamedArg('v')) {
    vel.x = VM_GetPC() != NULL ? VM_GetValue() : 0;
    vel.y = VM_GetPC() != NULL ? VM_GetValue() : 0;
    vel.z = VM_GetPC() != NULL ? VM_GetValue() : 0;
  } else {
    VEC3_SET(vel, 0, 0, 0);
  }
  timer = VM_GetNamedArgValue('l', 0);
  id = VM_GetNamedArgValue('n', 0);
  Vec3_Clear(&zero);
  Entity080dd1f8_Spawn(&pos, &vel, &zero, power, knockback, timer, id)->unk_12c |= 1;
}
