#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "inline.h"
#include "map_inline.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite_animation.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vec3.h"
#include "vm.h"

typedef struct {
  s16 unk_00;             // 0x000
  s16 power;              // 0x002, 要素の hitbox の攻撃力
  u8 state;               // 0x004, PTR_ARRAY_085ab9b4 の添字
  u8 unk_05;              // 0x005
  u8 unk_06;              // 0x006
  u8 animLooped;          // 0x007, anim が最後のフレームまで進んだフレームだけ 1
  u8 unk_08;              // 0x008
  u8 flashTimer;          // 0x009, 0 になったフレームにパレットを 0x22A に戻す
  u8 flags;               // 0x00A, bit0 なら hitbox を動かさない, bit1 なら FUN_08057214 を呼ぶ, _Update が毎フレーム 0 に戻す
  s8 lastDir;             // 0x00B, 前に進んだ向き, -1 ならなし
  u8 farTimer;            // 0x00C, player が範囲外にいるフレーム数, 32 で FUN_08056a34 が 1 を返す
  u8 angle;               // 0x00D, 8bit の向き, velocity を作る
  u8 unk_0e;              // 0x00E
  u8 unk_0f;              // 0x00F
  u8 unk_10;              // 0x010
  u8 unk_11[3];           // 0x011
  u32 stateTimer;         // 0x014, state を変えるたびに 0 に戻す
  u32 playerDistSq;       // 0x018, player との XZ 距離の2乗, 4フレームに1回だけ測り直す
  s16 targetX;            // 0x01C, 歩いて向かう先
  s16 targetZ;            // 0x01E
  Vec3 velocity;          // 0x020, unk_05 の向きに 8
  Vec3 origin;            // 0x028, 動き出した位置
  AuxSpriteGfx gfx;       // 0x030, SPRITE_DUNEYRR_AUX
  AuxSprite sprite;       // 0x04C
  AuxAnimState anim;      // 0x078, ANIM_31F4
  HitboxData hitbox;      // 0x088
  ParticleShadow shadow;  // 0x0D8
} Entity08058ffcElem;
static_assert(sizeof(Entity08058ffcElem) == 280);

typedef struct {
  Entity e;                      // 0x000, ENTITY_UNK_8
  AuxAnimFile* animFile;         // 0x018, ANIM_31F4
  u32 activeMask;                // 0x01C, elems のどの枠が使用中か
  u32 frameCounter;              // 0x020, _Update が毎フレーム +1, 下位2ビットで playerDistSq を測る枠を選ぶ
  u16 unk_24;                    // 0x024, _Update が毎フレーム 0 に戻す
  u16 activeCount;               // 0x026, そのフレームに動いた枠の数
  u32 unk_28;                    // 0x028
  u32 unk_2c;                    // 0x02C
  u32 unk_30;                    // 0x030
  s32 unk_34;                    // 0x034
  s32 unk_38;                    // 0x038
  Vec3 unk_3c[4];                // 0x03C, 初期値は (0x100, 0x100, 0x200), (0x800, 0x100, 0x200), (0x100, 0x100, 0x900), (0x800, 0x100, 0x900)
  Entity08058ffcElem elems[12];  // 0x05C
  HitboxData hitboxes[4];        // 0xD7C, 要素から四方へ伸ばす攻撃判定, unk_24 枚目まで使う
  Player* player;                // 0xEBC, gPlayerPtr[0]
} Entity08058ffc;
static_assert(sizeof(Entity08058ffc) == 3776);

static inline void Entity08058ffc_SetElemState(Entity08058ffc* p, Entity08058ffcElem* elem, u8 state) {
  if (p->unk_30) {
    state = 8;
  }
  elem->state = state;
  elem->unk_08 = 1;
  elem->stateTimer = 0;
}

static inline bool32 Entity08058ffc_IsPlayerNear(Entity08058ffcElem* elem, u32 distSq) {
  if (elem->playerDistSq <= distSq) {
    return TRUE;
  }
  return FALSE;
}

IWRAM_DATA Entity08058ffc* gEntity08058ffc = NULL;  // 0x0300012C

void FUN_080573a0(Entity08058ffc*, Entity08058ffcElem*, s32);
void FUN_08057478(Entity08058ffc*, Entity08058ffcElem*, s32);
void FUN_0805758c(Entity08058ffc*, Entity08058ffcElem*, s32);
void FUN_080579a4(Entity08058ffc*, Entity08058ffcElem*, s32);
void FUN_08057db0(Entity08058ffc*, Entity08058ffcElem*, s32);
void FUN_080581dc(Entity08058ffc*, Entity08058ffcElem*, s32);
void FUN_08058460(Entity08058ffc*, Entity08058ffcElem*, s32);
void FUN_080587cc(Entity08058ffc*, Entity08058ffcElem*, s32);
void FUN_08058a98(Entity08058ffc*, Entity08058ffcElem*, s32);
void FUN_08058ae4(Entity08058ffc*, Entity08058ffcElem*, s32);

s32 Entity080146e0_SpawnAtAngle(s32 count, s32 kind, Vec3* pos, s32 angle, s32 angleRange, s32 speed, s32 speedRange, s32 velY, s32 velYRange, s32 lifeBase, s32 lifeRandMask);

const u32 u32_ARRAY_085ab9a4[4] = {64, 16, 0, 0};  // 0x085AB9A4

void (*const PTR_ARRAY_085ab9b4[10])(Entity08058ffc*, Entity08058ffcElem*, s32) = {
    FUN_080573a0,
    FUN_08057478,
    FUN_0805758c,
    FUN_080579a4,
    FUN_08057db0,
    FUN_080581dc,
    FUN_08058460,
    FUN_080587cc,
    FUN_08058a98,
    FUN_08058ae4,
};  // 0x085AB9B4

// unk_3c の4点を部屋の四隅の初期位置にする
void FUN_080569f4(Entity08058ffc* p) {
  p->unk_3c[0].x = 0x100, p->unk_3c[0].y = 0x100, p->unk_3c[0].z = 0x200;
  p->unk_3c[1].x = 0x800, p->unk_3c[1].y = 0x100, p->unk_3c[1].z = 0x200;
  p->unk_3c[2].x = 0x100, p->unk_3c[2].y = 0x100, p->unk_3c[2].z = 0x900;
  p->unk_3c[3].x = 0x800, p->unk_3c[3].y = 0x100, p->unk_3c[3].z = 0x900;
}

// player が要素の周り 0x400 の範囲外に 32 フレームいたら 1 を返す, 範囲内なら 0, それ以外は戻り値を設定しない
// min/max を (Vec3* pos, Vec3* min, Vec3* max) を取る static inline で比べると min/max がスタックに乗って 98/100 命令まで寄る, 残差はその判定結果の 0/1 の作り方
NON_MATCH s32 FUN_08056a34(Entity08058ffc* p, Entity08058ffcElem* elem) {
#ifdef NONMATCHING_C
  Player* player = p->player;
  WorldPos* pos = &player->mover.pos;
  AuxSprite* sprite = &elem->sprite;
  Vec3 min;
  Vec3 max;

  min.x = sprite->pos.x - 0x400;
  min.z = sprite->pos.z - 0x400;
  max.x = sprite->pos.x + 0x400;
  max.z = sprite->pos.z + 0x400;
  if (pos->x >= min.x && pos->x <= max.x && pos->z >= min.z && pos->z <= max.z) {
    elem->farTimer = 0;
    return 0;
  }
  elem->farTimer++;
  if (elem->farTimer > 31) {
    elem->farTimer = 0;
    return 1;
  }
#else
  INCFUNC("asm/func/FUN_08056a34.inc");
#endif
}

// 次の位置が壁か段差なら, 今のタイルの範囲に押し戻した分だけ velocity を反転させる (跳ね返り先も塞がっていればもう一度)
// 下書きで 507/520 命令, 原典は min/max/clamp 用の Vec3 をスタックに並べて語単位で読み書きする
NON_MATCH void FUN_08056b08(Entity08058ffc* p, Entity08058ffcElem* elem) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  Vec3 next;
  Vec3 min;
  Vec3 max;
  Vec3 clamped;
  Vec3 diff;

  next.x = elem->velocity.x + sprite->pos.x;
  next.z = elem->velocity.z + sprite->pos.z;
  if (!(GetTileAttrAt(&next) & TATTR_UNK_0) && TileHeightAt(&next) == 0x100) {
    return;
  }

  min.x = sprite->pos.x & 0xFF00;
  min.z = sprite->pos.z & 0xFF00;
  max.x = min.x + 0xFF;
  max.z = min.z + 0xFF;
  clamped.x = next.x;
  clamped.z = next.z;
  if (clamped.x < min.x) {
    clamped.x = min.x;
  } else if (clamped.x > max.x) {
    clamped.x = max.x;
  }
  if (clamped.z < min.z) {
    clamped.z = min.z;
  } else if (clamped.z > max.z) {
    clamped.z = max.z;
  }
  diff.x = next.x - clamped.x;
  diff.z = next.z - clamped.z;
  if (diff.x != 0) {
    elem->velocity.x = -diff.x;
  }
  if (diff.z != 0) {
    elem->velocity.z = -diff.z;
  }
  if (diff.x == 0 && diff.z == 0) {
    return;
  }

  next.x = elem->velocity.x + clamped.x;
  next.z = elem->velocity.z + clamped.z;
  if ((GetTileAttrAt(&next) & TATTR_UNK_0) || TileHeightAt(&next) != 0x100) {
    min.x = clamped.x & 0xFF00;
    min.z = clamped.z & 0xFF00;
    max.x = min.x + 0xFF;
    max.z = min.z + 0xFF;
    clamped.x = next.x;
    clamped.z = next.z;
    if (clamped.x < min.x) {
      clamped.x = min.x;
    } else if (clamped.x > max.x) {
      clamped.x = max.x;
    }
    if (clamped.z < min.z) {
      clamped.z = min.z;
    } else if (clamped.z > max.z) {
      clamped.z = max.z;
    }
    diff.x = next.x - clamped.x;
    diff.z = next.z - clamped.z;
    if (diff.x != 0) {
      elem->velocity.x = -diff.x;
    }
    if (diff.z != 0) {
      elem->velocity.z = -diff.z;
    }
  }
#else
  INCFUNC("asm/func/FUN_08056b08.inc");
#endif
}

void FUN_08056f90(void) {}

// 要素の被弾ハンドラ, 攻撃の weakness に応じた向きと速さで弾き, ダメージ表示を出して hp が尽きたら state 7 へ
// 残差は a/b の割り当て (r5/r6 対 r6/r7) と speed を ip に置く形, 193/201 命令
NON_MATCH void FUN_08056f94(HitboxData* a, HitboxData* b, Entity08058ffcElem* elem) {
#ifdef NONMATCHING_C
  u32 angle;
  s32 speed;
  Vec3 v;

  Hitbox_ApplyDamage(a, b);
  if (TEST_FLAGS(a->flags, HBFLAG_ANGLE)) {
    angle = a->angle;
  } else {
    angle = ArcTan2_8(b->center.x - a->center.x, b->center.z - a->center.z);
  }

  if (a->weakness & 1) {
    angle = ArcTan2_8(b->pos.x - gPlayerPtr[0]->mover.pos.x, b->pos.z - gPlayerPtr[0]->mover.pos.z);
    speed = 16;
  } else if (a->weakness & 2) {
    speed = 32;
  } else if (a->weakness & 4) {
    angle = ArcTan2_8(b->pos.x - a->pos.x, b->pos.z - a->pos.z);
    speed = 24;
  } else if (a->weakness & 8) {
    speed = 8;
  } else {
    speed = 16;
  }

  angle = angle - 4 + (Random() & 7);
  elem->velocity.x = FixToInt(12, COS(angle) * speed);
  elem->velocity.y = 0;
  elem->velocity.z = FixToInt(12, SIN(angle) * speed);
  Video_SetAuxSpritePltt(&elem->gfx, 0x132);
  elem->flashTimer = 10;
  VEC3_SET(v, 16, 0, 16);
  CreateDamageNumber(b, b->damage, 0, &elem->sprite.pos, &v, 1);
  a->damage += 2;
  PlaySound_082406e0(SE_UNK_274);
  elem->unk_00 -= b->damage;
  if (elem->unk_00 <= 0) {
    elem->unk_00 = 0;
    elem->state = 7;
    elem->unk_08 = 1;
    elem->stateTimer = 0;
  } else {
    elem->state = 6;
    elem->unk_08 = 1;
    elem->stateTimer = 0;
  }
#else
  INCFUNC("asm/func/FUN_08056f94.inc");
#endif
}

// 四方の攻撃判定4枚を初期化する
// 残差は y=0x20 の合成定数 0x200000 をループ外に出してしまうことと, hitboxes[i] の番地を p 込みのポインタで進めること (80/82命令)
NON_MATCH void FUN_08057154(Entity08058ffc* p, s32 power) {
#ifdef NONMATCHING_C
  Vec3 halfSize;
  Vec3 offset;
  s32 i;

  p->unk_24 = 0;
  for (i = 0; i < 4; i++) {
    HitboxData* hitbox = &p->hitboxes[i];

    VEC3_SET(halfSize, 24, 0x20, 24);
    VEC3_SET(offset, 0, 0x20, 0);
    Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
    Hitbox_SetHandler(hitbox, FUN_08056f90, p);
    Hitbox_SetAttack(hitbox, power, 30, 0, 0, 30);
  }
#else
  INCFUNC("asm/func/FUN_08057154.inc");
#endif
}

// 要素の向き (unk_05) の先 48 に四方の攻撃判定を1枚置いて登録する
void FUN_08057214(Entity08058ffc* p, Entity08058ffcElem* elem) {
  if (p->unk_24 < 4) {
    HitboxData* hitbox = &p->hitboxes[p->unk_24];
    Vec3 pos = elem->sprite.pos;

    switch (elem->unk_05) {
      case 0: {
        pos.z -= 48;
        break;
      }
      case 1: {
        pos.x += 48;
        break;
      }
      case 2: {
        pos.z += 48;
        break;
      }
      case 3: {
        pos.x -= 48;
        break;
      }
    }
    Hitbox_SetPos(hitbox, &pos, 0);
    Hitbox_Register(hitbox);
    p->unk_24++;
  }
}

// 要素の食らい判定を作って登録する
void FUN_080572b8(Entity08058ffc* p, Entity08058ffcElem* elem) {
  HitboxData* hitbox = &elem->hitbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 0x40, 0x80, 0x40);
  VEC3_SET(offset, 0, 0x80, 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_UNK_0, 0, 16, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_08056f94, elem);
  Hitbox_SetPowerAndAttributes(hitbox, elem->power, 0x80, 0);
  Hitbox_Register(hitbox);
}

void Entity08058ffc_UnregisterElemHitbox(Entity08058ffc* p, Entity08058ffcElem* elem) { Hitbox_Unregister(&elem->hitbox); }

// unk_38 のスクリプトを要素のスプライト位置 (x, y, z) を引数にして実行する
void FUN_08057354(Entity08058ffc* p, Entity08058ffcElem* elem) {
  if (p->unk_38 != 0) {
    u32 argv[3];
    ScriptArgs args;

    argv[0] = elem->sprite.pos.x;
    argv[1] = elem->sprite.pos.y;
    argv[2] = elem->sprite.pos.z;
    args.argc = 3, args.argv = argv;
    VM_ExecByID(p->unk_38, &args);
  }
}

// 待機状態, player との距離と経過時間で次の状態 (5/4/2) を選ぶ
void FUN_080573a0(Entity08058ffc* p, Entity08058ffcElem* elem, s32 param_3) {
  if (elem->unk_08 != 0) {
    elem->unk_08 = 0;
    AuxAnim_SetAnim(&elem->anim, p->animFile, 0, (u8)(elem->unk_05 - 1) <= 1, elem->unk_05 > 1);
    AuxAnim_SetAnimSpeed(&elem->anim, 0x40);
  }

  if (elem->unk_0e != 0) {
    elem->unk_0e--;
  } else if (elem->playerDistSq <= 0x10000) {
    if (elem->unk_0f != 0) {
      elem->unk_0f--;
    } else {
      elem->unk_0f = 30;
      elem->unk_0e = 120;
      Entity08058ffc_SetElemState(p, elem, 5);
      return;
    }
  }

  if (elem->unk_10 == 0 && Entity08058ffc_IsPlayerNear(elem, 0x100000)) {
    Entity08058ffc_SetElemState(p, elem, 4);
    return;
  }
  if (elem->stateTimer > 59) {
    Entity08058ffc_SetElemState(p, elem, 2);
  } else {
    elem->stateTimer++;
  }
}

// 落下中の状態, 床に着いたら player との距離で次の状態を選ぶ
// 残差は TileHeightAt の x を sprite 経由で読む1命令と, 距離比較で定数より先にフィールドを読む順序 (124/124命令)
NON_MATCH void FUN_08057478(Entity08058ffc* p, Entity08058ffcElem* elem, s32 param_3) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  s32 floor;
  u8 state;

  if (elem->unk_08 != 0) {
    elem->unk_08 = 0;
    AuxAnim_SetAnim(&elem->anim, p->animFile, 2, 0, 0);
    elem->sprite.flags &= ~SPRFLAG_HIDDEN;
    ParticleShadow_Show(&elem->shadow);
  }

  sprite->pos.y -= 32;
  floor = TileHeightAt(&elem->sprite.pos);
  if (sprite->pos.y <= floor) {
    sprite->pos.y = floor;
    if (elem->playerDistSq <= 0x100000) {
      state = 4;
    } else {
      state = 2;
    }
    Entity08058ffc_SetElemState(p, elem, state);
    ParticleShadow_Hide(&elem->shadow);
  } else {
    elem->stateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_08057478.inc");
#endif
}

// FUN_080579a4 と同じ歩行状態で, 開始時に unk_10 を 0 に戻す
// 残差も FUN_080579a4 と同じ
NON_MATCH void FUN_0805758c(Entity08058ffc* p, Entity08058ffcElem* elem, s32 idx) {
#ifdef NONMATCHING_C
  s32 speed;

  if (elem->unk_08 != 0) {
    elem->unk_08 = 0;
    elem->targetX = (Random() & 0x3FF) + p->unk_3c[idx & 3].x;
    elem->targetZ = (Random() & 0x3FF) + p->unk_3c[idx & 3].z;
    elem->unk_10 = 0;
  }
  AuxAnim_SetAnim(&elem->anim, p->animFile, 1, (u8)(elem->unk_05 - 1) <= 1, elem->unk_05 > 1);

  if (elem->unk_0e != 0) {
    elem->unk_0e--;
  } else if (elem->playerDistSq <= 0x10000) {
    if (elem->unk_0f != 0) {
      elem->unk_0f--;
    } else {
      elem->unk_0f = 30;
      elem->unk_0e = 120;
      Entity08058ffc_SetElemState(p, elem, 5);
      return;
    }
  }
  if (elem->unk_10 == 0 && Entity08058ffc_IsPlayerNear(elem, 0x100000)) {
    Entity08058ffc_SetElemState(p, elem, 4);
    return;
  }

  if (elem->anim.animIdx == 1) {
    speed = (u32_ARRAY_085ab9a4[elem->anim.cmdIdx & 3] << 3) >> 6;
  } else {
    speed = 0;
  }
  elem->unk_06 = speed;
  if (elem->unk_06 != 0) {
    s32 dx = elem->targetX - elem->sprite.pos.x;
    s32 dz = elem->targetZ - elem->sprite.pos.z;
    s32 dir;
    s32 alt;
    s32 next;
    s32 last;

    if ((dx < 0 ? -dx : dx) < 24) {
      if ((dz < 0 ? -dz : dz) < 24) {
        elem->unk_06 = 0;
        elem->lastDir = -1;
        Entity08058ffc_SetElemState(p, elem, 0);
        return;
      }
      dir = dz >= 0 ? 2 : 0;
      alt = dx < 0 ? 3 : 1;
    } else if ((dz < 0 ? -dz : dz) < 24) {
      dir = dx < 0 ? 3 : 1;
      alt = dz >= 0 ? 2 : 0;
    } else {
      last = elem->lastDir >= 0 ? elem->lastDir : idx;
      if (!(last & 1)) {
        dir = dx < 0 ? 3 : 1;
        alt = dz >= 0 ? 2 : 0;
      } else {
        dir = dz >= 0 ? 2 : 0;
        alt = dx < 0 ? 3 : 1;
      }
    }
    if (elem->lastDir >= 0 && (alt & 1) == (elem->lastDir & 1)) {
      alt = elem->lastDir;
    }

    next = alt;
    for (;;) {
      Vec3 pos;

      pos.x = elem->sprite.pos.x;
      pos.z = elem->sprite.pos.z;
      if (dir & 1) {
        pos.x += dir == 1 ? elem->unk_06 : -elem->unk_06;
      } else {
        pos.z += dir == 0 ? -elem->unk_06 : elem->unk_06;
      }
      if (!(GetTileAttrAt(&pos) & TATTR_UNK_0) && TileHeightAt(&pos) == 0x100) {
        break;
      }
      if (next < 0) {
        dir = -1;
        break;
      }
      dir = next;
      next = -1;
    }

    if (dir == alt) {
      elem->lastDir = dir;
    } else {
      elem->lastDir = -1;
    }
    if (dir < 0) {
      dir = 0;
      elem->unk_06 = 0;
    }
    elem->unk_05 = dir;
    elem->velocity.y = 0;
    switch (elem->unk_05) {
      case 0: {
        elem->velocity.x = 0;
        elem->velocity.z = -elem->unk_06;
        break;
      }
      case 1: {
        elem->velocity.x = elem->unk_06;
        elem->velocity.z = 0;
        break;
      }
      case 2: {
        elem->velocity.x = 0;
        elem->velocity.z = elem->unk_06;
        break;
      }
      case 3: {
        elem->velocity.x = -elem->unk_06;
        elem->velocity.z = 0;
        break;
      }
    }
    elem->sprite.pos.x += elem->velocity.x;
    elem->sprite.pos.z += elem->velocity.z;
  }
  elem->stateTimer++;
#else
  INCFUNC("asm/func/FUN_0805758c.inc");
#endif
}

// 目標地点 (unk_3c の隅 + 乱数) へ縦横どちらかに歩く状態, 進めなければもう一方の軸を試す, 着いたら待機へ
// 下書きの段階で 502/484 命令, 足場判定のブロック配置とレジスタが大きく違う
NON_MATCH void FUN_080579a4(Entity08058ffc* p, Entity08058ffcElem* elem, s32 idx) {
#ifdef NONMATCHING_C
  s32 speed;

  if (elem->unk_08 != 0) {
    elem->unk_08 = 0;
    elem->targetX = (Random() & 0x3FF) + p->unk_3c[idx & 3].x;
    elem->targetZ = (Random() & 0x3FF) + p->unk_3c[idx & 3].z;
  }
  AuxAnim_SetAnim(&elem->anim, p->animFile, 1, (u8)(elem->unk_05 - 1) <= 1, elem->unk_05 > 1);

  if (elem->unk_0e != 0) {
    elem->unk_0e--;
  } else if (elem->playerDistSq <= 0x10000) {
    if (elem->unk_0f != 0) {
      elem->unk_0f--;
    } else {
      elem->unk_0f = 30;
      elem->unk_0e = 120;
      Entity08058ffc_SetElemState(p, elem, 5);
      return;
    }
  }
  if (elem->unk_10 == 0 && Entity08058ffc_IsPlayerNear(elem, 0x100000)) {
    Entity08058ffc_SetElemState(p, elem, 4);
    return;
  }

  if (elem->anim.animIdx == 1) {
    speed = (u32_ARRAY_085ab9a4[elem->anim.cmdIdx & 3] << 3) >> 6;
  } else {
    speed = 0;
  }
  elem->unk_06 = speed;
  if (elem->unk_06 != 0) {
    s32 dx = elem->targetX - elem->sprite.pos.x;
    s32 dz = elem->targetZ - elem->sprite.pos.z;
    s32 dir;
    s32 alt;
    s32 next;
    s32 last;

    if ((dx < 0 ? -dx : dx) < 24) {
      if ((dz < 0 ? -dz : dz) < 24) {
        elem->unk_06 = 0;
        elem->lastDir = -1;
        Entity08058ffc_SetElemState(p, elem, 0);
        return;
      }
      dir = dz >= 0 ? 2 : 0;
      alt = dx < 0 ? 3 : 1;
    } else if ((dz < 0 ? -dz : dz) < 24) {
      dir = dx < 0 ? 3 : 1;
      alt = dz >= 0 ? 2 : 0;
    } else {
      last = elem->lastDir >= 0 ? elem->lastDir : idx;
      if (!(last & 1)) {
        dir = dx < 0 ? 3 : 1;
        alt = dz >= 0 ? 2 : 0;
      } else {
        dir = dz >= 0 ? 2 : 0;
        alt = dx < 0 ? 3 : 1;
      }
    }
    if (elem->lastDir >= 0 && (alt & 1) == (elem->lastDir & 1)) {
      alt = elem->lastDir;
    }

    next = alt;
    for (;;) {
      Vec3 pos;

      pos.x = elem->sprite.pos.x;
      pos.z = elem->sprite.pos.z;
      if (dir & 1) {
        pos.x += dir == 1 ? elem->unk_06 : -elem->unk_06;
      } else {
        pos.z += dir == 0 ? -elem->unk_06 : elem->unk_06;
      }
      if (!(GetTileAttrAt(&pos) & TATTR_UNK_0) && TileHeightAt(&pos) == 0x100) {
        break;
      }
      if (next < 0) {
        dir = -1;
        break;
      }
      dir = next;
      next = -1;
    }

    if (dir == alt) {
      elem->lastDir = dir;
    } else {
      elem->lastDir = -1;
    }
    if (dir < 0) {
      dir = 0;
      elem->unk_06 = 0;
    }
    elem->unk_05 = dir;
    elem->velocity.y = 0;
    switch (elem->unk_05) {
      case 0: {
        elem->velocity.x = 0;
        elem->velocity.z = -elem->unk_06;
        break;
      }
      case 1: {
        elem->velocity.x = elem->unk_06;
        elem->velocity.z = 0;
        break;
      }
      case 2: {
        elem->velocity.x = 0;
        elem->velocity.z = elem->unk_06;
        break;
      }
      case 3: {
        elem->velocity.x = -elem->unk_06;
        elem->velocity.z = 0;
        break;
      }
    }
    elem->sprite.pos.x += elem->velocity.x;
    elem->sprite.pos.z += elem->velocity.z;
  }
  elem->stateTimer++;
#else
  INCFUNC("asm/func/FUN_080579a4.inc");
#endif
}

// player の周り (idx ごとにずらした位置) を 32 フレームおきに目標にして追いかける状態, FUN_08056a34 が 1 を返したら state 2 へ
// 歩行部分は FUN_080579a4 と同じ形で残差も同じ
NON_MATCH void FUN_08057db0(Entity08058ffc* p, Entity08058ffcElem* elem, s32 idx) {
#ifdef NONMATCHING_C
  s32 speed;

  if (elem->unk_08 != 0) {
    elem->unk_08 = 0;
    elem->targetX = (p->player->mover.pos.x & 0xFF00) + (idx & 3) * 32;
    elem->targetZ = (p->player->mover.pos.z & 0xFF00) + (idx >> 2) * 32;
    elem->farTimer = 0;
    elem->unk_10 = 1;
  }
  AuxAnim_SetAnimSpeed(&elem->anim, 0x20);
  AuxAnim_SetAnim(&elem->anim, p->animFile, 1, (u8)(elem->unk_05 - 1) <= 1, elem->unk_05 > 1);
  if ((elem->stateTimer & 0x1F) == 0) {
    elem->targetX = (p->player->mover.pos.x & 0xFF00) + (idx & 3) * 32;
    elem->targetZ = (p->player->mover.pos.z & 0xFF00) + (idx >> 2) * 32;
  }

  if (elem->unk_0e != 0) {
    elem->unk_0e--;
  } else if (elem->playerDistSq <= 0x10000) {
    if (elem->unk_0f != 0) {
      elem->unk_0f--;
    } else {
      elem->unk_0f = 30;
      elem->unk_0e = 120;
      Entity08058ffc_SetElemState(p, elem, 5);
      return;
    }
  }

  if (elem->anim.animIdx == 1) {
    speed = (u32_ARRAY_085ab9a4[elem->anim.cmdIdx & 3] << 4) >> 6;
  } else {
    speed = 0;
  }
  elem->unk_06 = speed;
  if (elem->unk_06 != 0) {
    s32 dx = elem->targetX - elem->sprite.pos.x;
    s32 dz = elem->targetZ - elem->sprite.pos.z;
    s32 dir;
    s32 alt;
    s32 next;
    s32 last;

    if ((dx < 0 ? -dx : dx) < 24) {
      if ((dz < 0 ? -dz : dz) < 24) {
        elem->unk_06 = 0;
        elem->lastDir = -1;
        Entity08058ffc_SetElemState(p, elem, 0);
        return;
      }
      dir = dz >= 0 ? 2 : 0;
      alt = dx < 0 ? 3 : 1;
    } else if ((dz < 0 ? -dz : dz) < 24) {
      dir = dx < 0 ? 3 : 1;
      alt = dz >= 0 ? 2 : 0;
    } else {
      last = elem->lastDir >= 0 ? elem->lastDir : idx;
      if (!(last & 1)) {
        dir = dx < 0 ? 3 : 1;
        alt = dz >= 0 ? 2 : 0;
      } else {
        dir = dz >= 0 ? 2 : 0;
        alt = dx < 0 ? 3 : 1;
      }
    }
    if (elem->lastDir >= 0 && (alt & 1) == (elem->lastDir & 1)) {
      alt = elem->lastDir;
    }

    next = alt;
    for (;;) {
      Vec3 pos;

      pos.x = elem->sprite.pos.x;
      pos.z = elem->sprite.pos.z;
      if (dir & 1) {
        pos.x += dir == 1 ? elem->unk_06 : -elem->unk_06;
      } else {
        pos.z += dir == 0 ? -elem->unk_06 : elem->unk_06;
      }
      if (!(GetTileAttrAt(&pos) & TATTR_UNK_0) && TileHeightAt(&pos) == 0x100) {
        break;
      }
      if (next < 0) {
        dir = -1;
        break;
      }
      dir = next;
      next = -1;
    }

    if (dir == alt) {
      elem->lastDir = dir;
    } else {
      elem->lastDir = -1;
    }
    if (dir < 0) {
      dir = 0;
      elem->unk_06 = 0;
    }
    elem->unk_05 = dir;
    elem->velocity.y = 0;
    switch (elem->unk_05) {
      case 0: {
        elem->velocity.x = 0;
        elem->velocity.z = -elem->unk_06;
        break;
      }
      case 1: {
        elem->velocity.x = elem->unk_06;
        elem->velocity.z = 0;
        break;
      }
      case 2: {
        elem->velocity.x = 0;
        elem->velocity.z = elem->unk_06;
        break;
      }
      case 3: {
        elem->velocity.x = -elem->unk_06;
        elem->velocity.z = 0;
        break;
      }
    }
    elem->sprite.pos.x += elem->velocity.x;
    elem->sprite.pos.z += elem->velocity.z;
  }

  if (FUN_08056a34(p, elem)) {
    Entity08058ffc_SetElemState(p, elem, 2);
  } else {
    elem->stateTimer++;
  }
#else
  INCFUNC("asm/func/FUN_08057db0.inc");
#endif
}

// player の方へ origin から sin 波で伸び縮みしながら突進する状態, 壁か段差に当たるか 32 フレームで待機に戻る
// 残差は dir 計算のレジスタと, 壁判定の GetTileAt 展開がブロック配置ごとずれること (288/291命令)
NON_MATCH void FUN_080581dc(Entity08058ffc* p, Entity08058ffcElem* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  Vec3* vel;
  Vec3 next;
  s32 r;
  u8 angle;
  bool32 blocked;

  if (elem->unk_08 != 0) {
    u8 dir;

    elem->unk_08 = 0;
    elem->origin = sprite->pos;
    elem->angle = ArcTan2_8(p->player->mover.pos.x - elem->origin.x, p->player->mover.pos.z - elem->origin.z);
    dir = ((((elem->angle + 0x20) & 0xFF) >> 6) + 1) & 3;
    elem->unk_05 = dir;
    AuxAnim_SetAnim(&elem->anim, p->animFile, 1, (u8)(dir - 1) <= 1, dir > 1);
    AuxAnim_SetAnimSpeed(&elem->anim, 0x10);
  }

  r = FixToInt(12, SIN(elem->stateTimer * 4) * 0x80);
  vel = &elem->velocity;
  angle = elem->angle;
  vel->x = FixToInt(12, r * COS(angle));
  vel->y = 0;
  vel->z = FixToInt(12, r * SIN(angle));
  if (elem->stateTimer - 8 < 8) {
    elem->flags |= 2;
  }

  next.x = elem->origin.x + elem->velocity.x;
  next.y = elem->origin.y + elem->velocity.y;
  next.z = elem->origin.z + elem->velocity.z;
  if (GetTileAttrAt(&next) & TATTR_UNK_0) {
    blocked = TRUE;
  } else if (TileHeightAt(&next) != 0x100) {
    blocked = TRUE;
  } else {
    blocked = FALSE;
  }

  if (!blocked) {
    sprite->pos.x = next.x;
    sprite->pos.y = next.y;
    sprite->pos.z = next.z;
    if (elem->stateTimer < 32) {
      elem->stateTimer++;
      return;
    }
  }
  Entity08058ffc_SetElemState(p, elem, 0);
#else
  INCFUNC("asm/func/FUN_080581dc.inc");
#endif
}

// 被弾して飛ばされる状態, 32 フレームで着地して state 4 へ
// 残差は FUN_080587cc と同じ GetTileAttrAt の x/z の読み元の違い (376/375命令)
NON_MATCH void FUN_08058460(Entity08058ffc* p, Entity08058ffcElem* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  s32 floor;
  s32 vx;
  s32 vz;

  if (elem->unk_08 != 0) {
    elem->unk_08 = 0;
    ParticleShadow_Show(&elem->shadow);
    if (!(GetTileAttrAt(&sprite->pos) & TATTR_UNK_0)) {
      TileHeightAt(&sprite->pos);
    }
  }

  FUN_08056b08(p, elem);
  sprite->pos.x += elem->velocity.x;
  sprite->pos.z += elem->velocity.z;
  floor = TileHeightAt(&sprite->pos);
  sprite->pos.y = floor + FixToInt(12, SIN(elem->stateTimer * 4) * 250);

  vx = elem->velocity.x;
  if (vx < 0) {
    vx = -vx;
  }
  vz = elem->velocity.z;
  if (vz < 0) {
    vz = -vz;
  }
  if (vx < vz) {
    AuxAnim_SetAnim(&elem->anim, p->animFile, 2, 0, 0);
  } else {
    AuxAnim_SetAnim(&elem->anim, p->animFile, 2, 0, ANIM_PLAY_XFLIP);
  }
  elem->flags |= 1;

  if (elem->stateTimer >= 32) {
    Entity08058ffc_SetElemState(p, elem, 4);
    sprite->pos.y = TileHeightAt(&sprite->pos);
    if (!(GetTileAttrAt(&sprite->pos) & TATTR_UNK_0)) {
      TileHeightAt(&sprite->pos);
    }
    ParticleShadow_Hide(&elem->shadow);
  }
  elem->stateTimer++;
#else
  INCFUNC("asm/func/FUN_08058460.inc");
#endif
}

// 倒された要素が揺れながら飛ばされて消える状態, 消えたら '.R' 系スクリプトと経験値を出す
// 残差は最初の GetTileAttrAt で原典が x を sprite (+0x1c), z を pos で読む形 (FUN_08058ae4 と同じ) で 310/310 命令
NON_MATCH void FUN_080587cc(Entity08058ffc* p, Entity08058ffcElem* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  s32 floor;
  s32 vx;
  s32 vz;

  if (elem->unk_08 != 0) {
    elem->unk_08 = 0;
    ParticleShadow_Show(&elem->shadow);
    if (!(GetTileAttrAt(&sprite->pos) & TATTR_UNK_0)) {
      TileHeightAt(&sprite->pos);
    }
  }

  if ((elem->stateTimer & 7) == 0) {
    Entity080146e0_SpawnAtAngle(3, 9, &sprite->pos, (u8)Random(), 32, 6, 2, 3, 2, 16, 0);
  }
  FUN_08056b08(p, elem);
  sprite->pos.x += elem->velocity.x;
  sprite->pos.z += elem->velocity.z;
  floor = TileHeightAt(&sprite->pos);
  sprite->pos.y = floor + FixToInt(12, SIN(elem->stateTimer * 4) * 250);

  vx = elem->velocity.x;
  if (vx < 0) {
    vx = -vx;
  }
  vz = elem->velocity.z;
  if (vz < 0) {
    vz = -vz;
  }
  if (vx < vz) {
    AuxAnim_SetAnim(&elem->anim, p->animFile, 2, 0, 0);
  } else {
    AuxAnim_SetAnim(&elem->anim, p->animFile, 2, 0, ANIM_PLAY_XFLIP);
  }
  elem->flags |= 1;

  if (elem->stateTimer > 7) {
    if ((elem->stateTimer & 3) == 0) {
      sprite->flags |= SPRFLAG_HIDDEN;
    } else {
      sprite->flags &= ~SPRFLAG_HIDDEN;
    }
  } else if (elem->stateTimer > 15) {
    if ((elem->stateTimer & 3) <= 2) {
      sprite->flags |= SPRFLAG_HIDDEN;
    } else {
      sprite->flags &= ~SPRFLAG_HIDDEN;
    }
  }

  if (elem->stateTimer > 31) {
    FUN_08057354(p, elem);
    ParticleShadow_Hide(&elem->shadow);
    AuxSprite_Remove(sprite);
    Entity08058ffc_UnregisterElemHitbox(p, elem);
    p->activeMask &= ~(1 << idx);
    AddPlayerExp(p->unk_34);
    p->unk_2c++;
  }
  elem->stateTimer++;
#else
  INCFUNC("asm/func/FUN_080587cc.inc");
#endif
}

// unk_08 が立っていたら unk_05 に応じたアニメを最初から再生し直す
void FUN_08058a98(Entity08058ffc* p, Entity08058ffcElem* elem, s32 param_3) {
  if (elem->unk_08 != 0) {
    elem->unk_08 = 0;
    AuxAnim_SetAnim(&elem->anim, p->animFile, 0, (u8)(elem->unk_05 - 1) <= 1, elem->unk_05 > 1);
    AuxAnim_SetAnimSpeed(&elem->anim, 0x40);
  }
}

// 消滅中の状態, 揺れながら点滅して 32 フレームで枠を空ける
// 残差は TileHeightAt の x を原典は sprite (r6) 経由の [r6, #0x1c] で読み, こちらは pos (r7) 経由になる1命令だけ (200/200命令), FUN_08057478 と同じ
NON_MATCH void FUN_08058ae4(Entity08058ffc* p, Entity08058ffcElem* elem, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* sprite = &elem->sprite;
  s32 floor;

  if (elem->unk_08 != 0) {
    elem->unk_08 = 0;
    ParticleShadow_Show(&elem->shadow);
    Video_SetAuxSpritePltt(&elem->gfx, 0x132);
  }
  elem->flags |= 1;
  elem->flashTimer = 10;
  if ((elem->stateTimer & 7) == 0) {
    Entity080146e0_SpawnAtAngle(3, 9, &elem->sprite.pos, (u8)Random(), 32, 6, 2, 3, 2, 16, 0);
  }

  floor = TileHeightAt(&elem->sprite.pos);
  sprite->pos.y = floor + FixToInt(12, SIN(elem->stateTimer * 4) * 250);
  AuxAnim_SetAnim(&elem->anim, p->animFile, 2, 0, 0);

  if (elem->stateTimer > 7) {
    if ((elem->stateTimer & 3) == 0) {
      sprite->flags |= SPRFLAG_HIDDEN;
    } else {
      sprite->flags &= ~SPRFLAG_HIDDEN;
    }
  } else if (elem->stateTimer > 15) {
    if ((elem->stateTimer & 3) <= 2) {
      sprite->flags |= SPRFLAG_HIDDEN;
    } else {
      sprite->flags &= ~SPRFLAG_HIDDEN;
    }
  }

  if (elem->stateTimer > 31) {
    ParticleShadow_Hide(&elem->shadow);
    AuxSprite_Remove(sprite);
    Entity08058ffc_UnregisterElemHitbox(p, elem);
    p->activeMask &= ~(1 << idx);
  }
  elem->stateTimer++;
#else
  INCFUNC("asm/func/FUN_08058ae4.inc");
#endif
}

// 使用中の要素ごとにアニメを手動で1コマ進め, 4フレームに1回 player との距離を測り, state のハンドラを呼んで hitbox を更新する
// 251/249命令, 手動送りは AuxSprite_AdvanceAnim で揃った, 残差はループの誘導変数: 原典は &elem->anim を歩進ポインタ (r8) にして &elem->sprite.pos を毎回作ってスタックに置くが, こちらは pos 側が歩進になり p が高位レジスタに回る
// 試済: elem の代入を初期化の後へ, sprite / anim のローカル化, anim / pos をループ頭で取る (anim を頭で取ると 242 命令に崩れる)
NON_MATCH s32 Entity08058ffc_Update(Entity08058ffc* p) {
#ifdef NONMATCHING_C
  Entity08058ffcElem* elem;
  s32 i;

  p->unk_24 = 0;
  p->activeCount = 0;
  elem = p->elems;
  for (i = 0; i < 12; i++, elem++) {
    Vec3* pos = &elem->sprite.pos;

    if (p->activeMask & (1 << i)) {
      elem->animLooped = AuxSprite_AdvanceAnim(&elem->sprite, &elem->anim);
      elem->flags = 0;

      if ((p->frameCounter & 3) == (i & 3)) {
        s32 dx = p->player->mover.pos.x - pos->x;
        s32 dz = p->player->mover.pos.z - pos->z;

        elem->playerDistSq = dx * dx + dz * dz;
      }
      PTR_ARRAY_085ab9b4[elem->state](p, elem, i);

      if (elem->flags & 1) {
        elem->hitbox.flags |= HBFLAG_HIDDEN;
      } else {
        elem->hitbox.flags &= ~HBFLAG_HIDDEN;
        Hitbox_SetPos(&elem->hitbox, pos, 0);
      }
      if (elem->flags & 2) {
        FUN_08057214(p, elem);
      }
      if (elem->flashTimer != 0) {
        elem->flashTimer--;
        if (elem->flashTimer == 0) {
          Video_SetAuxSpritePltt(&elem->gfx, 0x22A);
        }
      }
      p->activeCount++;
    }
  }
  p->frameCounter++;
  return 0;
#else
  INCFUNC("asm/func/Entity08058ffc_Update.inc");
#endif
}

s32 Entity08058ffc_Destroy(Entity08058ffc* p) {
  Entity08058ffcElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 12; i++, elem++) {
    ParticleShadow_Remove(&elem->shadow);
    if (p->activeMask & (1 << i)) {
      AuxSprite_Remove(&elem->sprite);
      Entity08058ffc_UnregisterElemHitbox(p, elem);
      p->activeMask &= ~(1 << i);
    }
  }
  gEntity08058ffc = NULL;
  return 0;
}

s32 Entity08058ffc_Init(Entity08058ffc* p, s32 param_2, s32 param_3, s32 param_4) {
  Entity08058ffcElem* elem;
  Player* player;
  s32 i;

  gEntity08058ffc = p;
  p->animFile = GetFile(DIR_ANIMATION, ANIM_31F4);
  FUN_080569f4(p);
  FUN_08057154(p, param_2);
  p->unk_34 = param_3;
  p->unk_38 = param_4;
  p->activeMask = 0;
  p->activeCount = 0;
  p->unk_28 = 0;
  p->unk_2c = 0;
  p->unk_30 = 0;

  elem = p->elems;
  for (i = 0; i < 12; i++, elem++) {
    elem->unk_06 = 0;
    elem->unk_05 = 0;
    if (!Video_GetAuxSprite(&elem->gfx, SPRITE_DUNEYRR_AUX)) {
      return -1;
    }
    AuxSprite_Setup(&elem->sprite, &elem->gfx, 0);
    AuxAnim_SetAnim(&elem->anim, p->animFile, 2, 0, 0);
    elem->sprite.priority = 2;
    Vec3_Clear(&elem->sprite.pos);
    ParticleShadow_Init(&elem->shadow, &elem->sprite.pos, 0);
    ParticleShadow_Hide(&elem->shadow);
  }

  player = gPlayerPtr[0];
  p->player = player;
  return 0;
}

Entity08058ffc* Entity08058ffc_Create(s32 param_1, s32 param_2, s32 param_3) {
  Entity08058ffc* p;

  if (gEntity08058ffc == NULL) {
    p = CreateEntity(ENTITY_UNK_8, sizeof(Entity08058ffc));
    if (p != NULL) {
      SetEntityRoutine(p, Entity08058ffc_Update, Entity08058ffc_Destroy);
      if (Entity08058ffc_Init(p, param_1, param_2, param_3) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity08058ffc;
}

// 空き枠に count 個まで要素を出す, 足りなければ管理エンティティを作る, 成功時の戻り値は設定しない
// 残差は原典が要素内の5つの番地 (anim/gfx/velocity/sprite/elem) を別々のポインタで回し引数を全部スタックに退避する形にならないこと (185/195命令)
NON_MATCH s32 FUN_08059054(s32 count, s32 dir, s32 param_3, s32 power, s32 param_5, Vec3* pos) {
#ifdef NONMATCHING_C
  Entity08058ffc* p = gEntity08058ffc;
  s32 n;
  s32 i;

  if (p == NULL) {
    p = Entity08058ffc_Create(param_5, 1, 0);
    if (p == NULL) {
      return -1;
    }
  }

  n = 0;
  for (i = 0; i < 12; i++) {
    Entity08058ffcElem* elem = &p->elems[i];

    if (!(p->activeMask & (1 << i))) {
      AuxSprite* sprite = &elem->sprite;
      s32 dx;
      s32 dz;

      elem->unk_00 = param_3;
      elem->power = power;
      elem->unk_05 = dir;
      elem->unk_06 = 8;
      elem->velocity.y = 0;
      switch (elem->unk_05) {
        case 0: {
          elem->velocity.x = 0;
          elem->velocity.z = -8;
          break;
        }
        case 1: {
          elem->velocity.x = 8;
          elem->velocity.z = 0;
          break;
        }
        case 2: {
          elem->velocity.x = 0;
          elem->velocity.z = 8;
          break;
        }
        case 3: {
          elem->velocity.x = -8;
          elem->velocity.z = 0;
          break;
        }
      }
      sprite->pos = *pos;
      elem->flashTimer = 0;
      elem->flags = 0;
      elem->lastDir = -1;
      elem->unk_10 = 0;
      Entity08058ffc_SetElemState(p, elem, 1);
      Video_SetAuxSpritePltt(&elem->gfx, 0x22A);
      AuxAnim_SetAnim(&elem->anim, p->animFile, 2, 0, 0);
      Video_AddAuxSpriteIntoDrawList(sprite, 0);
      FUN_080572b8(p, elem);
      dx = p->player->mover.pos.x - sprite->pos.x;
      dz = p->player->mover.pos.z - sprite->pos.z;
      elem->playerDistSq = dx * dx + dz * dz;
      p->activeMask |= 1 << i;
      p->unk_28++;
      if (++n >= count) {
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/FUN_08059054.inc");
#endif
}

s32 Entity08058ffc_GetActiveCount(void) {
  if (gEntity08058ffc == NULL) {
    return 0;
  }
  return gEntity08058ffc->activeCount;
}

s32 FUN_08059210(void) {
  if (gEntity08058ffc == NULL) {
    return 0;
  }
  return gEntity08058ffc->unk_28;
}

s32 FUN_0805922c(void) {
  if (gEntity08058ffc == NULL) {
    return 0;
  }
  return gEntity08058ffc->unk_2c;
}

// 残差はループ外に出した定数 (state 値と 0) を r8/ip に置く順序が逆になる2命令だけ (41/41命令)
NON_MATCH s32 FUN_08059248(void) {
#ifdef NONMATCHING_C
  Entity08058ffc* p = gEntity08058ffc;
  s32 i;

  if (p == NULL) {
    return 0;
  }
  p->unk_30 = 1;
  for (i = 0; i < 12; i++) {
    Entity08058ffcElem* elem = &p->elems[i];

    if ((p->activeMask & (1 << i)) && elem->state <= 5) {
      elem->state = 8;
      elem->unk_08 = 1;
      elem->stateTimer = 0;
    }
  }
#else
  INCFUNC("asm/func/FUN_08059248.inc");
#endif
}

// 残差はループ外に出した定数 (state 値と 0) を r8/ip に置く順序が逆になる2命令だけ (41/41命令)
NON_MATCH s32 FUN_080592a4(void) {
#ifdef NONMATCHING_C
  Entity08058ffc* p = gEntity08058ffc;
  s32 i;

  if (p == NULL) {
    return 0;
  }
  for (i = 0; i < 12; i++) {
    Entity08058ffcElem* elem = &p->elems[i];

    if ((p->activeMask & (1 << i)) && elem->state != 7) {
      elem->state = 9;
      elem->unk_08 = 1;
      elem->stateTimer = 0;
    }
  }
#else
  INCFUNC("asm/func/FUN_080592a4.inc");
#endif
}
