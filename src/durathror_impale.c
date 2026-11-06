#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"

// ドゥラスロールの"大棘"攻撃
// "大棘": 地面から大きな棘を生やして突き刺そうとする攻撃, ドゥラスロール第3形態の攻撃パターンの1つ

// 予兆の土煙 → 出現 → 攻撃判定を出し続ける → 引っ込む の4段階を踏む攻撃1つ分
typedef struct {
  u8 state;           // 0x00, 0: 粒子だけ出す, 1: 出現アニメ, 2: duration フレーム待つ, 3: 引っ込むアニメ
  u8 unk_01[3];       // 0x01
  u32 timer;          // 0x04, state が変わるたびに 0 に戻る
  u32 duration;       // 0x08, state 2 に留まるフレーム数
  MainSprite sprite;  // 0x0C
  HitboxData hitbox;  // 0x6C
} DurathrorImpaleSpike;
static_assert(sizeof(DurathrorImpaleSpike) == 188);

// ドゥラスロールの"大棘"(地面から大きな棘を生やす攻撃), 最大8個まとめて動かす
typedef struct DurathrorImpale {
  Entity e;                        // 0x000, ENTITY_UNK_8
  u32 activeMask;                  // 0x018, bit i が spikes[i] の使用中
  MainSpriteGfx gfx;               // 0x01C, SPRITE_DURATHROR
  ParticleSpawnParam ptcl;         // 0x03C, 棘の周りに4フレームごとに散らす粒子
  DurathrorImpaleSpike spikes[8];  // 0x064
} DurathrorImpale;
static_assert(sizeof(DurathrorImpale) == 1604);

void nop_0805d918(void) {}

void DurathrorImpaleSpike_Init(DurathrorImpale* p, DurathrorImpaleSpike* elem, s32 idx) {
  Vec3 pos;
  Vec3 size;
  Vec3 offset;
  HitboxData* hitbox;

  elem->timer = 0;
  Vec3_Clear(&pos);
  MainSprite_Setup(&elem->sprite, &p->gfx, 0, SPRFLAG_HIDDEN, 2, 0, 60, &pos);
  hitbox = &elem->hitbox;
  VEC3_SET(size, Q8(0.375), Q8(0.25), Q8(0.375));
  VEC3_SET(offset, 0, Q8(0.25), 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 16, &size, &offset);
  Hitbox_SetHandler(hitbox, nop_0805d918, elem);
  Hitbox_SetAttack(hitbox, 50, 64, 0, 0, 64);
}

// 攻撃1つ分を消して空きに戻す
void DurathrorImpaleSpike_Remove(DurathrorImpale* p, DurathrorImpaleSpike* elem, s32 idx) {
  elem->sprite.flags |= SPRFLAG_HIDDEN;
  MainSprite_Remove(&elem->sprite);
  p->activeMask &= ~(1 << idx);
}

// 4フレームごとに攻撃の周りのランダムな位置へ粒子を出す
// 残差は乱数の & 31 と SIN の & 0xFF の2箇所のレジスタ割当だけ (90/90), 原典は angle を ands の右オペランドに置いて生かす, Tier A-C (Vec3_SetPolar/POLAR 直書き, angle/radius の型と宣言順, +16 の位置) は試済
NON_MATCH void DurathrorImpaleSpike_SpawnParticle(DurathrorImpale* p, DurathrorImpaleSpike* elem) {
#ifdef NONMATCHING_C
  if ((elem->timer & 3) == 0) {
    MainSprite* sprite = &elem->sprite;
    u16* table = gRandomTable;
    u16 angle = _Random(table);
    s32 radius = _Random(table) & 31;
    Vec3 pos;

    Vec3_SetPolar(&pos, angle, radius + 16);
    Vec3_Add(&pos, &sprite->pos);
    Entity08015584_Spawn(0, &pos, &p->ptcl);
  }
#else
  INCFUNC("asm/func/DurathrorImpaleSpike_SpawnParticle.inc");
#endif
}

s32 DurathrorImpale_Update(DurathrorImpale* p) {
  DurathrorImpaleSpike* elem = p->spikes;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    if (p->activeMask & (1 << i)) {
      MainSprite* sprite = &elem->sprite;
      HitboxData* hitbox = &elem->hitbox;

      switch (elem->state) {
        case 0: {
          DurathrorImpaleSpike_SpawnParticle(p, elem);
          if (elem->timer >= 30) {
            elem->state++;
            elem->timer = 0;
            sprite->flags &= ~SPRFLAG_HIDDEN;
            MainSprite_SetAnim(sprite, &p->gfx, 42, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
            PlaySound_082406e0(SONG_376);
          }
          break;
        }
        case 1: {
          if (sprite->animCmdIdx < 5) {
            DurathrorImpaleSpike_SpawnParticle(p, elem);
          }
          if (elem->timer >= 15) {
            Hitbox_Register(hitbox);
          }
          if (sprite->animEvents & MAIN_ANIM_EVENT_WILL_END) {
            elem->state++;
            elem->timer = 0;
            MainSprite_SetAnim(sprite, &p->gfx, 43, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
          }
          break;
        }
        case 2: {
          Hitbox_Register(hitbox);
          if (elem->timer >= elem->duration) {
            elem->state++;
            elem->timer = 0;
            MainSprite_SetAnim(sprite, &p->gfx, 42, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE | MAIN_ANIM_REVERSE);
          }
          break;
        }
        case 3: {
          if (sprite->animCmdIdx < 5) {
            DurathrorImpaleSpike_SpawnParticle(p, elem);
          }
          if (sprite->animEvents & MAIN_ANIM_EVENT_WILL_END) {
            DurathrorImpaleSpike_Remove(p, elem, i);
            continue;
          }
          break;
        }
      }
      MainSprite_AdvanceAnim(sprite, &p->gfx);
      elem->timer++;
    }
  }
  return 0;
}

s32 DurathrorImpale_Destroy(DurathrorImpale* p) {
  DurathrorImpaleSpike* elem = p->spikes;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    if (p->activeMask & (1 << i)) {
      DurathrorImpaleSpike_Remove(p, elem, i);
    }
  }
  return 0;
}

s32 DurathrorImpale_Init(DurathrorImpale* p) {
  MainSpriteGfxFile* f;
  ParticleSpawnParam* param;
  DurathrorImpaleSpike* elem;
  s32 i;

  p->activeMask = 0;
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_DURATHROR);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *f;
  OpenMainSpriteFile(&p->gfx, f);

  param = &p->ptcl;
  param->kind = 7;
  param->flags = 0x3000;
  param->animSpeed = 64;
  param->speedY = 0;
  param->speedYRand = 0;
  param->speedXZ = 3;
  param->speedXZRand = 3;
  param->angleY = 0;
  param->angleYRand = 0;
  param->angleXZ = 0;
  param->angleXZRand = 256;
  param->decayStartY = 512;
  param->decayStartYRand = 0;
  param->unk_1c = 0;
  param->unk_1e = 0;
  param->decayStartXZ = 512;
  param->decayStartXZRand = 0;
  param->unk_24 = 0;
  param->unk_26 = 0;

  elem = p->spikes;
  for (i = 0; i < 8; i++, elem++) {
    DurathrorImpaleSpike_Init(p, elem, i);
  }
  return 0;
}

DurathrorImpale* DurathrorImpale_Create(void) {
  DurathrorImpale* p = CreateEntity(ENTITY_UNK_8, sizeof(DurathrorImpale));

  if (p != NULL) {
    SetEntityRoutine(p, DurathrorImpale_Update, DurathrorImpale_Destroy);
    if (DurathrorImpale_Init(p) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

DurathrorImpaleSpike* DurathrorImpale_FindFreeSpike(DurathrorImpale* p, s32* idx) {
  DurathrorImpaleSpike* elem = p->spikes;
  s32 i;

  for (i = 0; i < 8; i++, elem++) {
    if (!(p->activeMask & (1 << i))) {
      *idx = i;
      return elem;
    }
  }
  *idx = 0;
  return NULL;
}

// 空いている枠を使って pos に攻撃を1つ出す, 空きが無ければ -1
s32 DurathrorImpale_Spawn(DurathrorImpale* p, s32 power, u32 duration, Vec3* pos) {
  s32 idx;
  DurathrorImpaleSpike* elem = DurathrorImpale_FindFreeSpike(p, &idx);
  MainSprite* sprite;
  HitboxData* hitbox;

  if (elem == NULL) {
    return -1;
  }

  sprite = &elem->sprite;
  hitbox = &elem->hitbox;
  elem->state = 0;
  elem->timer = 0;
  elem->duration = duration;
  MainSprite_SetAnim(sprite, &p->gfx, 42, 2, MAIN_ANIM_FORCE_POSE);
  elem->sprite.pos = *pos;
  Video_AddMainSpriteIntoDrawList(sprite, 0);
  Hitbox_SetAttack(hitbox, power, 64, 0, HBATTR_18, 64);
  Hitbox_SetPos(hitbox, pos, 0);
  p->activeMask |= 1 << idx;
  return 0;
}
