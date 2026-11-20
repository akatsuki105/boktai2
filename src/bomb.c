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

// 汎用の丸い爆弾 (SPR_BOMB), 地面で弾みながら転がり, 導火線が尽きると爆発する
// マミーが吐くもの (Mummy_SpitBombs) と, スクリプトの Cmd_PlaceBomb (爆弾設置) で置くものがある
// 後者は螺旋の塔 (Scr_st05_16_tower) のレバー3つで上から落ちてくる爆弾で, これでマミーを倒すと先へ進めるギミックになっている

// Bomb.flags
#define BOMBFLAG_FALLING (1 << 0)  // 0x01, 落ち始めている, 立つまでは target に近づくか 8 フレーム経つまで高さを保って飛ぶ

typedef struct {
  AuxSprite spr;          // 0x000, _Destroy が AuxSprite_Remove に渡す
  AuxAnimState anim;      // 0x02C
  Hitbox hitbox;          // 0x03C, 攻撃判定, 当たると Bomb_OnHit で弾かれる
  Hitbox hurtbox;         // 0x08C, 食らい判定, Bomb_OnHurt で炎と氷に反応する
  ParticleShadow shadow;  // 0x0DC, _Destroy が ParticleShadow_Remove に渡す
  Vec3 vel;               // 0x11C, 弾かれると Bomb_OnHit が書き換える
  Vec3 target;            // 0x124, 落ち始める目安の位置, マミーはプレイヤーの位置を渡し, Cmd_PlaceBomb は 0 を渡して最初から落とす
  u16 flags;              // 0x12C, BOMBFLAG_*, 片付けるときに 0
  u8 state;               // 0x12E, sBombUpdates の添字 (0:待機 1:転がる 2:爆発), 2 だと Bomb_IsAlive が 0 を返す
  s8 slotIdx;             // 0x12F, activeMask 上の自分のビット番号, 空きは -1, 負だと Bomb_IsAlive が 0 を返す
  bool8 stateBegun;       // 0x130, 状態に入った最初のフレームだけ立つ, 爆発の状態では立っていると爆発を出す
  u8 hitCooldown;         // 0x131, 0 になるまで攻撃判定を出さない, 生成時 30, 弾かれると 12
  u16 fuse;               // 0x132, 導火線の残りフレーム数, 0 で爆発へ移る, 90 未満で点滅が始まり残りが少ないほど速くなる
  u16 tileIdx;            // 0x134, 今いるタイルの索引
  u16 power;              // 0x136, 爆発の威力
  u16 knockback;          // 0x138, 爆発のノックバック
  u8 blinkTimer;          // 0x13A, 0 になると点滅のアニメを切り替える, sBombBlinkIntervals から入る
  u8 blinkAnim;           // 0x13B, 流しているアニメ番号 (1 か 2)
  u16 id;                 // 0x13C, 攻撃判定と食らい判定の id, NoiseManager_AddMoverNoise の第6引数
  u16 fuseMax;            // 0x13E, 導火線の初期値, 氷属性が当たると fuse がこれに戻る
  u16 timer;              // 0x140, 状態に入ってからのフレーム数
  u8 unk_142[2];          // 0x142
} Bomb;
static_assert(sizeof(Bomb) == 324);

typedef struct {
  Entity e;           // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx;   // 0x018, SPR_BOMB
  AuxAnimFile* anim;  // 0x034, ANIM_BOMB
  Bomb elems[12];     // 0x038, 根拠: _Destroy の stride 0x144 × 12
  u32 activeMask;     // 0xF68, 使用中の elems のビットマスク, _Init が 0 にする
} BombManager;
static_assert(sizeof(BombManager) == 3948);

IWRAM_DATA BombManager* gBombManager = NULL;  // 0x0300016C

struct Explosion* Explosion_Create(Vec3* pos, s32 ignoreMask, s32 power, s32 knockback, s32 plttOffset);
void Bomb_OnHurt(Hitbox* a, Hitbox* b, Bomb* elem);
BombManager* BombManager_Create(void);

// 導火線の残りが少ないほど短くなる点滅の間隔, [1] が残り 90 未満, [2] が 50 未満, [3] が 30 未満
const u8 sBombBlinkIntervals[4] = {0, 8, 4, 2};  // 0x085AD338

static inline bool8 BombManager_IsActive(u32* mask, s32 i) {
  if (TEST_FLAGS(*mask, 1 << i)) return TRUE;
  return FALSE;
}

void Bomb_StateIdle(BombManager* p, Bomb* elem) {}

// 攻撃判定が当たったら当てた相手から離れる向きへ弾かれる, 相手より上なら跳ね上がり, そうでなければ横へ押される
void Bomb_OnHit(Hitbox* a, Hitbox* b, Bomb* elem) {
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
  elem->hitCooldown = 12;
  PlaySound_082406e0(358);
}

// 炎属性が当たると導火線が尽きてすぐ爆発し, 氷属性が当たると導火線が初期値に戻る (点滅が始まる前だけ)
// 残差2命令 (28 対 30), 原典は elem を r12 に逃がして第2分岐で add r1, ip を使うが, こちらは r3 に置けてしまう (leaf なので r4-r7 は使えない)
// && / 条件の反転 / u16* ローカルは試済
NON_MATCH void Bomb_OnHurt(Hitbox* a, Hitbox* b, Bomb* elem) {
#ifdef NONMATCHING_C
  if (Hitbox_TestAttr(a, HBATTR_FLAME)) {
    elem->fuse = 0;
  } else if (Hitbox_TestAttr(a, HBATTR_FROST)) {
    if (elem->fuse > 0x59) {
      elem->fuse = elem->fuseMax;
    }
  }
#else
  INCFUNC("asm/func/Bomb_OnHurt.inc");
#endif
}

// 攻撃判定と食らい判定を作る
void Bomb_InitHitboxes(Bomb* elem, u16 power, u16 knockback) {
  Hitbox* hitbox;
  Hitbox* hurtbox;
  Vec3 halfSize;
  Vec3 offset;

  VEC3_SET(halfSize, 32, 32, 32);
  VEC3_SET(offset, 0, 32, 0);
  hitbox = &elem->hitbox;
  Hitbox_Init(hitbox, elem->id, HBF_HITBOX | HBF_SENSOR | HBF_DAMAGE, 0, 16, &halfSize, &offset);
  Hitbox_SetAttack(hitbox, (s16)power, (s16)knockback, 0, 0, 0);
  Hitbox_SetPos(hitbox, &elem->spr.pos, 0);
  Hitbox_SetHandler(hitbox, Bomb_OnHit, elem);
  VEC3_SET(halfSize, 64, 128, 64);
  VEC3_SET(offset, 0, 128, 0);
  hurtbox = &elem->hurtbox;
  Hitbox_Init(hurtbox, elem->id, HBF_HURTBOX | HBF_DAMAGE, 0, 16, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &elem->spr.pos, 0);
  Hitbox_SetHandler(hurtbox, Bomb_OnHurt, elem);
  Hitbox_Register(hurtbox);
}

Bomb* BombManager_Alloc(BombManager* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (!BombManager_IsActive(&p->activeMask, i)) {
      Bomb* elem = &p->elems[i];

      p->activeMask |= 1 << i;
      elem->slotIdx = i;
      return elem;
    }
  }
  return NULL;
}

// state 1, target の近くまで来るか 8 フレーム経つと落ち始め, 地面で弾みながら転がり, 導火線が尽きたら爆発へ移る
// 698/714命令, 2回目の下書き (呼び出し列は一致), 原典は &spr.pos をスタック (sp+0x24) に置き vel を r4 から触る, pos / vel をポインタのローカルにすると 16 命令少なくなり, 直接アクセスだと 727 命令
NON_MATCH void Bomb_StateRoll(BombManager* p, Bomb* elem) {
#ifdef NONMATCHING_C
  AuxSprite* spr = &elem->spr;
  Vec3* pos;
  Vec3* vel;
  u32 tile;
  s32 height;

  if (elem->stateBegun) {
    elem->spr.flags &= ~SPRFLAG_HIDDEN;
    elem->timer = 0;
    elem->stateBegun = FALSE;
  }
  pos = &elem->spr.pos;
  elem->tileIdx = GetCollisionTileIdx(pos);
  if (elem->flags & BOMBFLAG_FALLING) {
    if (spr->pos.y > TileHeightAtIndex(elem->tileIdx, &spr->pos)) {
      elem->vel.y -= 4;
    }
  } else {
    Vec3 d;

    Vec3_Delta(&d, &spr->pos, &elem->target);
    if (d.x * d.x + d.z * d.z < 0x40000 || elem->timer > 8) {
      elem->flags |= BOMBFLAG_FALLING;
      elem->vel.y -= 4;
    }
  }
  tile = elem->tileIdx;
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
      gBombManager->activeMask &= ~(1 << elem->slotIdx);
      elem->state = 0;
      AuxSprite_Remove(&elem->spr);
      ParticleShadow_Remove(&elem->shadow);
      Hitbox_Unregister(&elem->hurtbox);
      elem->slotIdx = -1;
      elem->flags = 0;
      elem->fuse = 0;
    } else {
      pos->x += vel->x;
      pos->y += vel->y;
      pos->z += vel->z;
    }
  }
  Hitbox_SetPos(&elem->hurtbox, &spr->pos, 0);
  if (elem->hitCooldown == 0) {
    Hitbox_SetPos(&elem->hitbox, &spr->pos, 0);
    Hitbox_Register(&elem->hitbox);
  } else {
    elem->hitCooldown--;
  }
  if (elem->blinkTimer == 0) {
    s32 k;

    if (elem->fuse < 30) {
      k = 3;
    } else if (elem->fuse < 50) {
      k = 2;
    } else if (elem->fuse <= 89) {
      k = 1;
    } else {
      goto skip;
    }
    {
      u16 tick = elem->anim.tick;
      u16 cmdIdx = elem->anim.cmdIdx;

      if (elem->blinkAnim == 1) {
        AuxAnim_SetAnim(&elem->anim, p->anim, 2, 0, 0);
        elem->blinkAnim = 2;
      } else {
        AuxAnim_SetAnim(&elem->anim, p->anim, 1, 0, 0);
        elem->blinkAnim = 1;
      }
      elem->anim.tick = tick;
      elem->anim.cmdIdx = cmdIdx;
      elem->blinkTimer = sBombBlinkIntervals[k];
    }
  } else {
    elem->blinkTimer--;
  }
skip:
  AuxSprite_AdvanceAnim(spr, &elem->anim);
  elem->timer++;
  if (elem->fuse == 0) {
    elem->state = 2;
    elem->stateBegun = TRUE;
  } else {
    elem->fuse--;
  }
#else
  INCFUNC("asm/func/Bomb_StateRoll.inc");
#endif
}

// 爆発の印が立っていれば爆発と効果音を出し, 自分を片付ける
// 79/79命令, activeMask を落とすところで原典は gBombManager を読み &slotIdx を作って添字を読んでから +0xF68 する (こちらは &activeMask を先に作る), 試済: CLEAR_BIT, グローバルのローカル写し, a = a & ~b の形
NON_MATCH void Bomb_StateExplode(BombManager* p, Bomb* elem) {
#ifdef NONMATCHING_C
  if (elem->stateBegun) {
    Explosion_Create(&elem->spr.pos, 32, elem->power, elem->knockback, 0);
    NoiseManager_AddMoverNoise(elem->spr.pos.x, elem->spr.pos.z, 0x400, 0, 1, elem->id);
    elem->stateBegun = FALSE;
  }
  gBombManager->activeMask &= ~(1 << elem->slotIdx);
  elem->state = 0;
  AuxSprite_Remove(&elem->spr);
  ParticleShadow_Remove(&elem->shadow);
  Hitbox_Unregister(&elem->hurtbox);
  elem->slotIdx = -1;
  elem->flags = 0;
  elem->fuse = 0;
#else
  INCFUNC("asm/func/Bomb_StateExplode.inc");
#endif
}

// 爆弾を1つ置く, ゲームオーバー中や 1P が倒れているときと空きが無いときは NULL
Bomb* Bomb_Spawn(Vec3* pos, Vec3* vel, Vec3* target, s32 power, s32 knockback, s32 timer, s32 id) {
  BombManager* p = gBombManager;
  Bomb* elem;
  AuxSprite* spr;

  if (p == NULL) {
    p = BombManager_Create();
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
  elem = BombManager_Alloc(p);
  if (elem == NULL) {
    return NULL;
  }
  elem->state = 1;
  elem->flags = 0;
  elem->target = *target;
  elem->stateBegun = TRUE;
  elem->vel = *vel;
  elem->power = power;
  elem->knockback = knockback;
  elem->fuseMax = timer;
  elem->fuse = timer;
  elem->hitCooldown = 30;
  elem->id = id;
  elem->blinkAnim = 1;
  spr = &elem->spr;
  elem->spr.pos = *pos;
  AuxSprite_Add(spr, &p->gfx, 0);
  AuxAnim_SetAnim(&elem->anim, p->anim, 1, 0, 0);
  AuxSprite_AdvanceAnim(spr, &elem->anim);
  spr->flags |= SPRFLAG_HIDDEN;
  spr->priority = 1;
  ParticleShadow_Init(&elem->shadow, &spr->pos, 0);
  Bomb_InitHitboxes(elem, 0, 0);
  return elem;
}

void (*const sBombUpdates[3])(BombManager*, Bomb*) = {
    Bomb_StateIdle,
    Bomb_StateRoll,
    Bomb_StateExplode,
};  // 0x085AD33C

s32 BombManager_Update(BombManager* p) {
  Bomb* elems = p->elems;
  s32 i;

  if (p->activeMask != 0 && !TEST_FLAGS(gGameFlags | gDebugGameFlags, GAMEFLAG_GAMEOVER) && !TEST_FLAGS(gPlayerModes[0], PMODE_DEAD)) {
    for (i = 0; i < 12; i++) {
      if (BombManager_IsActive(&p->activeMask, i)) {
        sBombUpdates[elems[i].state](p, &elems[i]);
      }
    }
  }
  return 0;
}

s32 BombManager_Destroy(BombManager* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    if (BombManager_IsActive(&p->activeMask, i)) {
      Bomb* elem = &p->elems[i];

      AuxSprite_Remove(&elem->spr);
      ParticleShadow_Remove(&elem->shadow);
    }
  }
  gBombManager = NULL;
  return 0;
}

s32 BombManager_Init(BombManager* p) {
  Video_GetAuxSprite(&p->gfx, SPR_BOMB);
  p->anim = GetFile(DIR_ANIMATION, ANIM_BOMB);
  p->activeMask = 0;
  gBombManager = p;
  return 0;
}

BombManager* BombManager_Create(void) {
  if (gBombManager == NULL) {
    BombManager* p = CreateEntity(ENTITY_UNK_8, sizeof(BombManager));
    if (p != NULL) {
      SetEntityRoutine(p, BombManager_Update, BombManager_Destroy);
      if (BombManager_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gBombManager;
}

void BombManager_ClearGlobal(void) { gBombManager = NULL; }

// pos から 320 未満の距離にある生きた爆弾を探し, 見つかればその向きを返す, 無ければ -1
s32 BombManager_FindNearbyAngle(Vec3* pos) {
  BombManager* p = gBombManager;
  Bomb* elems;
  s32 i;

  if (p == NULL) {
    return -1;
  }
  elems = p->elems;
  if (p->activeMask == 0) {
    return -1;
  }
  for (i = 0; i < 12; i++) {
    if (BombManager_IsActive(&p->activeMask, i) && elems[i].slotIdx >= 0 && elems[i].fuse != 0 && elems[i].state != 2) {
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
s32 Bomb_IsAlive(void* p) {
  Bomb* elem = p;

  if (elem == NULL) {
    return 0;
  }
  if (elem->slotIdx < 0) {
    return 0;
  }
  if (elem->fuse == 0) {
    return 0;
  }
  if (elem->state == 2) {
    return 0;
  }
  return 1;
}

// 0xAE71 (爆弾設置), スクリプトから爆弾を1つ置いて最初から落とす, '.p' が位置, '.a' が威力とノックバック, '.v' が速度, '.l' が爆発までの時間, '.n' が判定の id
void Cmd_PlaceBomb(void) {
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
  Bomb_Spawn(&pos, &vel, &zero, power, knockback, timer, id)->flags |= BOMBFLAG_FALLING;
}
