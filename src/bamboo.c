#include "collision_map.h"
#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "shadow.h"
#include "spirit_bugs.h"
#include "sprite.h"
#include "vm.h"

// 太陽ダケ, プレイヤーが攻撃すると月光虫を出す
typedef struct {
  Entity e;                // ENTITY_UNK_8
  u16 id;                  // 0x18
  u8 unk_1a[0x20 - 0x1A];  // 0x1A
  ZoneID32 zoneID;         // 0x20
  u16 hp;                  // 0x24
  u16 maxHP;               // 0x26, '.l=200'
  u16 unk_28;              // 0x28
  u16 unk_2a;              // 0x2A
  u16 unk_2c;              // 0x2C
  u16 unk_2e;              // 0x2E
  u8 floatDir;             // 0x30, 縦の揺れ方向 (0: 上向き, 1: 下向き)
  s16 baseY;               // 0x32, 縦にふわふわと揺れる処理をするので、初期のy座標を保持
  s16 offsetY;             // 0x34, 縦の揺れ量
  u16 count;               // 0x36, '.n=4'
  u16 amount;              // 0x38, '.e=50', 回復量
  AuxSpriteGfx gfx;        // 0x3C, SPRITE_SOLAR_BAMBOO
  AuxSprite sprite;        // 0x58, ->gfx
  ParticleShadow shadow;   // 0x84
  HitboxData hurtbox;      // 0xC4
} SolarBamboo;
static_assert(sizeof(SolarBamboo) == 276);

const u16 u16_ARRAY_085aa76c[4] = {0x6F, 0x3, 0x3, 0x3};  // 0x085aa76c

// 被弾時に呼ばれる, 点滅させて耐久を削り、0 以下になったら月光虫を出して耐久を戻す
void SolarBamboo_OnHurt(HitboxData* a, HitboxData* b, SolarBamboo* p) {
  s32 damage;
  Vec3 pos;

  damage = a->damage;
  if (damage == 0) {
    damage = Hitbox_TestAttr(a, HBATTR_ALL) ? 50 : 30;
  }
  if (p->unk_28 == 0 && damage > 0) {
    p->unk_28 = 8;
    Video_SetAuxSpritePltt(&p->gfx, 362);
    p->unk_2e = 8;
    if ((s16)(p->hp -= damage) <= 0) {
      p->hp = p->maxHP;
      pos = p->sprite.pos;
      pos.y += Q8(0.25);
      SpawnSpiritBugsAt(p->count, MOONBUG, p->amount, &pos, NULL, SECOND(10), 0x64);
    }
  }
}

// 別のマップにいる間は隠し、いる間はアニメーションと揺れを進める
// ゾーン一致を bool8 を返す static inline (gStat->zoneID == zoneID) にすると 0/1 の作り置きは出るが, 他の場所のレジスタとフィールドの読み方が合わない (126/125)
NON_MATCH s32 SolarBamboo_Update(SolarBamboo* p) {
#ifdef NONMATCHING_C
  bool32 active;

  active = (p->zoneID == gStat->zoneID) ? TRUE : FALSE;
  if (!active) {
    p->sprite.flags |= SPRFLAG_HIDDEN;
    p->hurtbox.flags |= HBFLAG_HIDDEN;
    ParticleShadow_Hide(&p->shadow);
  } else {
    p->sprite.flags &= ~SPRFLAG_HIDDEN;
    p->hurtbox.flags &= ~HBFLAG_HIDDEN;
    ParticleShadow_Show(&p->shadow);
    if (p->unk_28 != 0) {
      p->unk_28--;
    }
    if (p->unk_2e != 0) {
      if (--p->unk_2e == 0) {
        Video_SetAuxSpritePltt(&p->gfx, 361);
      }
    }
    if (++p->unk_2c >= u16_ARRAY_085aa76c[p->unk_2a]) {
      p->unk_2c = 0;
      if (++p->unk_2a > 3) {
        p->unk_2a = 0;
      }
      p->sprite.poseIdx = p->unk_2a;
    }

    // 縦にふわふわとする動き
    if (p->floatDir != 0) {
      p->offsetY += 2;
      if (p->offsetY > 50) {
        p->offsetY = 50;
        p->floatDir = 0;
      }
    } else {
      p->offsetY -= 2;
      if (p->offsetY < -50) {
        p->offsetY = -50;
        p->floatDir = 1;
      }
    }
    p->sprite.pos.y = p->offsetY + p->baseY;
  }
  return 0;
#else
  INCFUNC("asm/func/SolarBamboo_Update.inc");
#endif
}

s32 SolarBamboo_Destroy(SolarBamboo* p) {
  Hitbox_Unregister(&p->hurtbox);
  AuxSprite_Remove(&p->sprite);
  ParticleShadow_Remove(&p->shadow);
  return 0;
}

// スクリプトから位置と耐久を読み、当たり判定・スプライト・影を用意する
s32 SolarBamboo_Init(SolarBamboo* p, u32 id, u32 _) {
  HitboxData* hurtbox;
  AuxSpriteGfx* gfx;
  AuxSprite* spr;
  Vec3 pos, size, offset;

  p->id = id;
  p->maxHP = VM_GetNamedArgValue('l', 200);
  p->hp = 1;
  p->unk_28 = 0;
  p->count = VM_GetNamedArgValue('n', 4);
  p->amount = VM_GetNamedArgValue('e', 50);
  p->unk_2a = 0;
  p->unk_2c = 0;
  p->unk_2e = 0;
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue() + Q8(0.391), VM_GetValue());
  } else {
    VEC3_SET(pos, 0, 0, 0);
  }
  p->zoneID = GetZoneAt(&pos);
  p->floatDir = 0;
  p->baseY = pos.y;
  p->offsetY = 0;
  VEC3_SET(size, Q8(0.12), Q8(1.25), Q8(0.12));
  VEC3_SET(offset, 0, Q8(0.625), 0);
  hurtbox = &p->hurtbox;
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_UNK_0, 0, HIM_4, &size, &offset);
  Hitbox_SetHandler(hurtbox, SolarBamboo_OnHurt, p);
  Hitbox_SetPos(hurtbox, &pos, 0);
  Hitbox_Register(hurtbox);
  gfx = &p->gfx;
  Video_GetAuxSprite(gfx, SPRITE_SOLAR_BAMBOO);
  spr = &p->sprite;
  AuxSprite_Add(spr, gfx, 0);
  spr->poseIdx = 0;
  Video_SetAuxSpritePltt(gfx, 361);
  p->sprite.pos = pos;
  ParticleShadow_Init(&p->shadow, &p->sprite.pos, 0);
  return 0;
}

// 0x95A8, HashName("太陽竹")
SolarBamboo* SolarBamboo_Create(u32 id, u32 _) {
  SolarBamboo* p = CreateEntity(ENTITY_UNK_8, sizeof(SolarBamboo));
  if (p != NULL) {
    SetEntityRoutine(p, SolarBamboo_Update, SolarBamboo_Destroy);
    if (SolarBamboo_Init(p, id, _) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
