#include "entity.h"
#include "game.h"
#include "global.h"
#include "hitbox.h"
#include "particle.h"
#include "sprite.h"
#include "vm.h"

// Entity95A8_Init で太陽ダケのスプライトをロードしているので太陽ダケのEntityだと思われる
typedef struct {
  Entity e;                // ENTITY_UNK_8
  u16 q_unk_18;            // 0x18
  u8 unk_1a[0x20 - 0x1A];  // 0x1A
  u32 q_unk_20;            // 0x20
  u16 q_unk_24;            // 0x24
  u16 q_unk_26;            // 0x26
  u16 q_unk_28;            // 0x28
  u16 q_unk_2a;            // 0x2A
  u16 q_unk_2c;            // 0x2C
  u16 q_unk_2e;            // 0x2E
  u8 q_unk_30;             // 0x30
  u8 unk_31;               // 0x31
  u16 q_unk_32;            // 0x32
  u16 q_unk_34;            // 0x34
  u16 q_unk_36;            // 0x36
  u16 q_unk_38;            // 0x38
  u8 unk_3a[2];            // 0x3A
  AuxSpriteGfx sprite;     // 0x3C
  AuxSprite q_node;        // 0x58, sprite を指す描画ノード
  ParticleShadow shadow;   // 0x84, 根拠: Entity95A8_Destroy が FUN_080138fc に渡している
  HitboxData hitbox;       // 0xC4, 0x0800c33a
} SolarBamboo;
static_assert(sizeof(SolarBamboo) == 276);

const u16 u16_ARRAY_085aa76c[4] = {
    0x6F,
    0x3,
    0x3,
    0x3,
};  // 0x085aa76c

void FUN_0800ac80(u16 param_1, s32 param_2, u16 param_3, Vec3* pos, s32 param_5, s32 param_6, s32 param_7);

static inline u32 TestHitboxUnk38(HitboxData* p, u32 flags) { return p->unk_38 & flags; }

// 被弾時に呼ばれる。点滅させて耐久を削り、0 以下になったら演出を出して耐久を戻す
void FUN_0800c0b0(HitboxData* a, HitboxData* b, SolarBamboo* p) {
  s32 damage;
  Vec3 pos;

  damage = a->wear;
  if (damage == 0) {
    damage = TestHitboxUnk38(a, 0x40) ? 0x32 : 0x1E;
  }
  if (p->q_unk_28 == 0 && damage > 0) {
    p->q_unk_28 = 8;
    Video_SetAuxSpritePltt(&p->sprite, 0x16A);
    p->q_unk_2e = 8;
    if ((s16)(p->q_unk_24 -= damage) <= 0) {
      p->q_unk_24 = p->q_unk_26;
      pos = p->q_node.q_pos;
      pos.y += 0x40;
      FUN_0800ac80(p->q_unk_36, 1, p->q_unk_38, &pos, 0, 0x258, 0x64);
    }
  }
}

void FUN_08013698(ParticleShadow* shadow);
void FUN_080136b4(ParticleShadow* shadow);

// 別のマップにいる間は隠し、いる間はアニメーションと揺れを進める
NON_MATCH s32 Entity95A8_Update(SolarBamboo* p) {
#ifdef NONMATCHING_C
  bool32 active;

  active = (p->q_unk_20 == gStat->unk_248) ? TRUE : FALSE;
  if (!active) {
    p->q_node.flags |= 1;
    p->hitbox.flags |= 4;
    FUN_080136b4(&p->shadow);
  } else {
    p->q_node.flags &= ~1;
    p->hitbox.flags &= ~4;
    FUN_08013698(&p->shadow);
    if (p->q_unk_28 != 0) {
      p->q_unk_28--;
    }
    if (p->q_unk_2e != 0) {
      if (--p->q_unk_2e == 0) {
        Video_SetAuxSpritePltt(&p->sprite, 0x169);
      }
    }
    if (++p->q_unk_2c >= u16_ARRAY_085aa76c[p->q_unk_2a]) {
      p->q_unk_2c = 0;
      if (++p->q_unk_2a > 3) {
        p->q_unk_2a = 0;
      }
      p->q_node.q_metaspriteIdx = p->q_unk_2a;
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
    p->q_node.q_pos.y = p->q_unk_34 + p->q_unk_32;
  }
  return 0;
#else
  INCFUNC("asm/func/Entity95A8_Update.inc");
#endif
}

void FUN_08236424(HitboxData* p);
s32 FUN_080138fc(ParticleShadow* shadow);

s32 Entity95A8_Destroy(SolarBamboo* p) {
  FUN_08236424(&p->hitbox);
  FUN_0822a4e0(&p->q_node);
  FUN_080138fc(&p->shadow);
  return 0;
}

s32 FUN_08241574(Vec3* pos);
s32 FUN_0801385c(ParticleShadow* shadow, Vec3* ownerPos, u8 kind);
void FUN_08236514(HitboxData* p, u32 val1, u32 val2, u32 val3);
void FUN_08236400(HitboxData* p);
void FUN_0822a470(AuxSprite* p, AuxSpriteGfx* s, SpriteFlags flags);

// スクリプトから位置と耐久を読み、当たり判定・スプライト・影を用意する
s32 Entity95A8_Init(SolarBamboo* p, u32 param, u32 _) {
  HitboxData* hitbox;
  AuxSpriteGfx* sprite;
  AuxSprite* node;
  Vec3 pos;
  Vec3 size;
  Vec3 offset;

  p->q_unk_18 = param;
  p->q_unk_26 = VM_GetKeywordValue('l', 0xC8);
  p->q_unk_24 = 1;
  p->q_unk_28 = 0;
  p->q_unk_36 = VM_GetKeywordValue('n', 4);
  p->q_unk_38 = VM_GetKeywordValue('e', 0x32);
  p->q_unk_2a = 0;
  p->q_unk_2c = 0;
  p->q_unk_2e = 0;
  if (VM_SeekToKeyword('p')) {
    pos.x = Script_GetValue();
    pos.y = Script_GetValue() + 0x64;
    pos.z = Script_GetValue();
  } else {
    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
  }
  p->q_unk_20 = FUN_08241574(&pos);
  p->q_unk_30 = 0;
  p->q_unk_32 = pos.y;
  p->q_unk_34 = 0;
  size.x = 0x1E;
  size.y = 0x140;
  size.z = 0x1E;
  offset.x = 0;
  offset.y = 0xA0;
  offset.z = 0;
  hitbox = &p->hitbox;
  FUN_0823646c(hitbox, 0, 0x4001, 0, 0x10, &size, &offset);
  FUN_0823651c(hitbox, FUN_0800c0b0, p);
  FUN_082364c4(hitbox, &pos, 0);
  FUN_08236400(hitbox);
  sprite = &p->sprite;
  Video_GetAuxSprite(sprite, SPRITE_SOLAR_BAMBOO);
  node = &p->q_node;
  FUN_0822a470(node, sprite, 0);
  node->q_metaspriteIdx = 0;
  Video_SetAuxSpritePltt(sprite, 0x169);
  p->q_node.q_pos = pos;
  FUN_0801385c(&p->shadow, &p->q_node.q_pos, 0);
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
