#include "collision_map.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "sprite.h"

// ドヴァリンの"墨玉"の着弾後

// 墨だまり1つ, 8個で使い回す, InkBallPuddleManager_FindFree が ttl == 0 かつ非表示のものを空きとして拾う
typedef struct {
  AuxSprite sprite;   // 0x00
  AuxAnimState anim;  // 0x2C
  HitboxData hitbox;  // 0x3C
  Vec3 pos;           // 0x8C, Hitbox_SetPos の第2引数, InkBallPuddleManager_Add が引数の Vec3 を写す
  u16 ttl;            // 0x94, 残りフレーム数, _Update が毎フレーム -1 して 0 で InkBallPuddleManager_Remove が解放する, 60未満でフェードに入る
  u8 unk_96[2];       // 0x96, padding?
} InkBallPuddle;
static_assert(sizeof(InkBallPuddle) == 152);

typedef struct {
  Entity e;                  // 0x000, ENTITY_UNK_8
  AuxSpriteGfx gfx;          // 0x018, SPRITE_ACID_0
  u8 unk_34[4];              // 0x034, 読み手も書き手も未発見
  u32 unk_38;                // 0x038, _Init が 0 を入れるだけで読み手が見つからない
  u8 activeCount;            // 0x03C, 使用中の puddles の数, InkBallPuddleManager_FindFree が 8 未満か見て InkBallPuddleManager_Add が +1 / InkBallPuddleManager_Remove が -1
  u8 unk_3d[3];              // 0x03D, padding?
  InkBallPuddle puddles[8];  // 0x040
} InkBallPuddleManager;
static_assert(sizeof(InkBallPuddleManager) == 1280);

static InkBallPuddleManager* gInkBallPuddleManager;  // 0x0300021C

NAKED void InkBallPuddle_OnHit(HitboxData* a, HitboxData* b, InkBallPuddle* puddle) { INCFUNC("asm/func/InkBallPuddle_OnHit.inc"); }

NAKED void InkBallPuddle_InitHitbox(InkBallPuddle* puddle, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes) { INCFUNC("asm/func/InkBallPuddle_InitHitbox.inc"); }

// 空いている枠を探す, ttl が 0 で非表示のものが空き
// 残差1命令: 原典は return puddle のブロックをループの手前に置くので、ガードが bls + b の2段になる
NON_MATCH InkBallPuddle* InkBallPuddleManager_FindFree(void) {
#ifdef NONMATCHING_C
  InkBallPuddleManager* p = gInkBallPuddleManager;

  if (p->activeCount <= 7) {
    InkBallPuddle* puddle = p->puddles;
    s32 i;

    for (i = 0; i < 8; puddle++, i++) {
      if (puddle->ttl == 0 && (puddle->sprite.flags & SPRFLAG_HIDDEN)) {
        return puddle;
      }
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/InkBallPuddleManager_FindFree.inc");
#endif
}

// 空き枠を1つ取って墨だまりを出す, Y座標は足元のタイルの高さに合わせる
void InkBallPuddleManager_Add(Vec3* pos, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 ttl) {
  InkBallPuddleManager* p = gInkBallPuddleManager;
  InkBallPuddle* puddle = InkBallPuddleManager_FindFree();

  if (puddle != NULL) {
    Vec3* dst;
    s32 x, y, z;

    p->activeCount++;
    puddle->pos = *pos;

    x = pos->x, y = pos->y, z = pos->z;
    dst = &puddle->sprite.pos;
    puddle->sprite.pos.x = x - 0x80;
    dst->y = y;
    dst->z = z;

    puddle->sprite.pos.y = (GetTileAt(&puddle->sprite.pos)->heightStairs & 0xF) << 8;
    puddle->ttl = ttl;
    puddle->sprite.flags &= ~SPRFLAG_HIDDEN;
    InkBallPuddle_InitHitbox(puddle, power, knockback, attrs, iframes);
  }
}

// 枠を解放する, ttl を 0 にしてスプライトを隠し、使用中の数を1つ減らす
void InkBallPuddleManager_Remove(InkBallPuddle* puddle) {
  InkBallPuddleManager* p = gInkBallPuddleManager;

  if (puddle != NULL) {
    p->activeCount--;
    puddle->ttl = 0;
    puddle->sprite.flags |= SPRFLAG_HIDDEN;
  }
}

// 使用中の墨だまりのアニメを進めて当たり判定を出し, 寿命が尽きたら外す
void InkBallPuddleManager_Update(InkBallPuddleManager* p) {
  InkBallPuddle* puddle = p->puddles;
  s32 i;

  for (i = 0; i < 8; puddle++, i++) {
    if (puddle->ttl != 0) {
      AuxSprite_AdvanceAnim(&puddle->sprite, &puddle->anim);
      Hitbox_SetPos(&puddle->hitbox, &puddle->pos, 0);
      Hitbox_Register(&puddle->hitbox);
      if (puddle->ttl < 60) {
        Sprite_UpdateVanishBlink(&puddle->sprite.flags, 60 - puddle->ttl, 20, 30);
      }
      if (--puddle->ttl == 0) {
        InkBallPuddleManager_Remove(puddle);
      }
    }
  }
}

s32 InkBallPuddleManager_Destroy(InkBallPuddleManager* p) {
  InkBallPuddle* puddle = p->puddles;
  s32 i;

  for (i = 0; i < 8; puddle++, i++) {
    if (puddle->sprite.active) {
      AuxSprite_Remove(&puddle->sprite);
    }
  }
  gInkBallPuddleManager = NULL;
  return 0;
}

// 8つの枠を全部作り直す, スプライトとアニメを割り当ててヒットボックスを初期化し、全部空きにする
s32 InkBallPuddleManager_InitPuddles(InkBallPuddleManager* p) {
  AuxAnimFile* files;
  InkBallPuddle* puddle;
  s32 i;

  Video_GetAuxSprite(&p->gfx, SPRITE_ACID_0);
  Video_SetAuxSpritePltt(&p->gfx, 566);
  files = GetFile(DIR_ANIMATION, ANIM_1752);

  puddle = p->puddles;
  for (i = 0; i < 8; puddle++, i++) {
    AuxSprite_Add(&puddle->sprite, &p->gfx, 0);
    AuxAnim_SetAnim(&puddle->anim, files, 1, 0, 0);
    puddle->sprite.flags |= SPRFLAG_HIDDEN;
    InkBallPuddle_InitHitbox(puddle, 0, 0, 0, 0);
    puddle->ttl = 0;
  }
  return 0;
}

s32 InkBallPuddleManager_Init(InkBallPuddleManager* p) {
  p->activeCount = 0;
  p->unk_38 = 0;
  Video_GetAuxSprite(&p->gfx, SPRITE_ACID_0);
  if (InkBallPuddleManager_InitPuddles(p) < 0) {
    return -1;
  } else {
    return 0;
  }
}

InkBallPuddleManager* InkBallPuddleManager_Create(void) {
  InkBallPuddleManager* p;

  if (gInkBallPuddleManager != NULL) {
    return gInkBallPuddleManager;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(InkBallPuddleManager));
  if (p != NULL) {
    SetEntityRoutine(p, InkBallPuddleManager_Update, InkBallPuddleManager_Destroy);
    if (InkBallPuddleManager_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 墨だまりを出す入口, エンティティがまだなければ先に作る
s32 InkBallPuddle_Spawn(Vec3* pos, s32 power, s32 knockback, HitboxAttributes attrs, s32 iframes, s32 ttl) {
  if (gInkBallPuddleManager == NULL) {
    gInkBallPuddleManager = InkBallPuddleManager_Create();
  }
  InkBallPuddleManager_Add(pos, power, knockback, attrs, iframes, ttl);
}
