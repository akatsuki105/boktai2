#include "entity.h"
#include "game.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "shadow.h"
#include "sprite.h"
#include "vm.h"

// Entity95A8_Init で太陽ダケのスプライトをロードしているので太陽ダケのEntityだと思われる
typedef struct {
  Entity e;                // ENTITY_UNK_8
  u16 unk_18;              // 0x18
  u8 unk_1a[0x20 - 0x1A];  // 0x1A
  u32 unk_20;              // 0x20
  u16 hp;                  // 0x24
  u16 maxHP;               // 0x26, '.l=200'
  u16 q_unk_28;            // 0x28
  u16 q_unk_2a;            // 0x2A
  u16 q_unk_2c;            // 0x2C
  u16 q_unk_2e;            // 0x2E
  u8 q_unk_30;             // 0x30
  u8 unk_31;               // 0x31
  u16 q_unk_32;            // 0x32
  u16 q_unk_34;            // 0x34
  u16 q_unk_36;            // 0x36, '.n=4'
  u16 q_unk_38;            // 0x38, '.e=50'
  u8 unk_3a[2];            // 0x3A, padding?
  AuxSpriteGfx gfx;        // 0x3C
  AuxSprite sprite;        // 0x58, gfx を指す描画ノード
  ParticleShadow shadow;   // 0x84, 根拠: Entity95A8_Destroy が ParticleShadow_Remove に渡している
  HitboxData hitbox;       // 0xC4, 0x0800c33a
} SolarBamboo;
static_assert(sizeof(SolarBamboo) == 276);

const u16 u16_ARRAY_085aa76c[4] = {0x6F, 0x3, 0x3, 0x3};  // 0x085aa76c

void Entity0800a89c_SpawnAt(u16 param_1, s32 param_2, u16 param_3, Vec3* pos, s32 param_5, s32 param_6, s32 param_7);

static inline u32 TestHitboxAttributes(HitboxData* p, u32 flags) { return p->attributes & flags; }

// 被弾時に呼ばれる。点滅させて耐久を削り、0 以下になったら演出を出して耐久を戻す
void FUN_0800c0b0(HitboxData* a, HitboxData* b, SolarBamboo* p) {
  s32 damage;
  Vec3 pos;

  damage = a->damage;
  if (damage == 0) {
    damage = TestHitboxAttributes(a, 0x40) ? 50 : 30;
  }
  if (p->q_unk_28 == 0 && damage > 0) {
    p->q_unk_28 = 8;
    Video_SetAuxSpritePltt(&p->gfx, 362);
    p->q_unk_2e = 8;
    if ((s16)(p->hp -= damage) <= 0) {
      p->hp = p->maxHP;
      pos = p->sprite.pos;
      pos.y += 0x40;
      Entity0800a89c_SpawnAt(p->q_unk_36, 1, p->q_unk_38, &pos, 0, 600, 0x64);
    }
  }
}

// 別のマップにいる間は隠し、いる間はアニメーションと揺れを進める
NON_MATCH s32 Entity95A8_Update(SolarBamboo* p) {
#ifdef NONMATCHING_C
  bool32 active;

  active = (p->unk_20 == gStat->unk_248) ? TRUE : FALSE;
  if (!active) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
    p->hitbox.flags |= HBFLAG_UNK_2;
    ParticleShadow_Hide(&p->shadow);
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->hitbox.flags &= ~HBFLAG_UNK_2;
    ParticleShadow_Show(&p->shadow);
    if (p->q_unk_28 != 0) {
      p->q_unk_28--;
    }
    if (p->q_unk_2e != 0) {
      if (--p->q_unk_2e == 0) {
        Video_SetAuxSpritePltt(&p->gfx, 361);
      }
    }
    if (++p->q_unk_2c >= u16_ARRAY_085aa76c[p->q_unk_2a]) {
      p->q_unk_2c = 0;
      if (++p->q_unk_2a > 3) {
        p->q_unk_2a = 0;
      }
      p->sprite.metaspriteIdx = p->q_unk_2a;
    }
    if (p->q_unk_30 != 0) {
      p->q_unk_34 += 2;
      if ((s16)p->q_unk_34 > 0x32) {
        p->q_unk_34 = 0x32;
        p->q_unk_30 = 0;
      }
    } else {
      p->q_unk_34 -= 2;
      if ((s16)p->q_unk_34 < -0x32) {
        p->q_unk_34 = -0x32;
        p->q_unk_30 = 1;
      }
    }
    p->sprite.pos.y = p->q_unk_34 + p->q_unk_32;
  }
  return 0;
#else
  INCFUNC("asm/func/Entity95A8_Update.inc");
#endif
}

s32 Entity95A8_Destroy(SolarBamboo* p) {
  Hitbox_Unregister(&p->hitbox);
  AuxSprite_Remove(&p->sprite);
  ParticleShadow_Remove(&p->shadow);
  return 0;
}

s32 FUN_08241574(Vec3* pos);
void Hitbox_SetPowerAndAttributes(HitboxData* p, u32 val1, u32 val2, u32 val3);
void Hitbox_Register(HitboxData* p);

// スクリプトから位置と耐久を読み、当たり判定・スプライト・影を用意する
s32 Entity95A8_Init(SolarBamboo* p, u32 param, u32 _) {
  HitboxData* hitbox;
  AuxSpriteGfx* gfx;
  AuxSprite* spr;
  Vec3 pos;
  Vec3 size;
  Vec3 offset;

  p->unk_18 = param;
  p->maxHP = VM_GetKeywordValue('l', 200);
  p->hp = 1;
  p->q_unk_28 = 0;
  p->q_unk_36 = VM_GetKeywordValue('n', 4);
  p->q_unk_38 = VM_GetKeywordValue('e', 50);
  p->q_unk_2a = 0;
  p->q_unk_2c = 0;
  p->q_unk_2e = 0;
  if (VM_SeekToKeyword('p')) {
    pos.x = Script_GetValue();
    pos.y = Script_GetValue() + 0x64;
    pos.z = Script_GetValue();
  } else {
    pos.x = 0, pos.y = 0, pos.z = 0;
  }
  p->unk_20 = FUN_08241574(&pos);
  p->q_unk_30 = 0;
  p->q_unk_32 = pos.y;
  p->q_unk_34 = 0;
  size.x = 30, size.y = 320, size.z = 30;
  offset.x = 0, offset.y = 160, offset.z = 0;
  hitbox = &p->hitbox;
  Hitbox_Init(hitbox, 0, HBFLAG_UNK_14 | HBFLAG_UNK_0, 0, 0x10, &size, &offset);
  Hitbox_SetHandler(hitbox, FUN_0800c0b0, p);
  Hitbox_SetPos(hitbox, &pos, 0);
  Hitbox_Register(hitbox);
  gfx = &p->gfx;
  Video_GetAuxSprite(gfx, SPRITE_SOLAR_BAMBOO);
  spr = &p->sprite;
  AuxSprite_Add(spr, gfx, 0);
  spr->metaspriteIdx = 0;
  Video_SetAuxSpritePltt(gfx, 361);
  p->sprite.pos = pos;
  ParticleShadow_Init(&p->shadow, &p->sprite.pos, 0);
  return 0;
}

SolarBamboo* Entity95A8_Create(u32 param, u32 _) {
  SolarBamboo* p = CreateEntity(ENTITY_UNK_8, sizeof(SolarBamboo));
  if (p != NULL) {
    SetEntityRoutine(p, Entity95A8_Update, Entity95A8_Destroy);
    if (Entity95A8_Init(p, param, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
