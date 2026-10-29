#include "entity.h"
#include "global.h"
#include "particle.h"
#include "player.h"
#include "sound.h"
#include "sprite.h"

// 12個を使い回す粒子の枠
typedef struct {
  Particle ptcl;  // 0x00, FUN_080ab6d8 が Particle_Remove に渡す
  u8 unk_28[28];  // 0x28
} Entity080abd14Particle;
static_assert(sizeof(Entity080abd14Particle) == 68);

// FUN_080ab780 / FUN_080ab848 が受け取る一式, 呼び出し元は自分の中の AuxSprite の先頭を渡す
typedef struct {
  AuxSprite spr;           // 0x00
  u8 unk_2c[0x6C - 0x2C];  // 0x2C, まだ未解析
  u8 unk_6c;               // 0x6C, FUN_080ab848 が timer 0 のとき 0 を書く
  u8 timer;                // 0x6D, FUN_080ab848 が 0 でなければ -1
} Entity080abd14Sprite;

typedef struct {
  Entity e;                          // 0x000, ENTITY_UNK_8
  u8 unk_18;                         // 0x018, _Init の第5引数, 0 かどうかで鳴らす SE が変わる
  u8 unk_19;                         // 0x019, _Update が 0 以外なら 0x03002BF0 を1減らして 0 に戻す
  u16 unk_1a;                        // 0x01A, 下位バイトは _Init の第6引数, 上位バイトは _Update が owner の状態が 4 のとき 1 にする, _Destroy は2バイトまとめて 0 かを見る
  Player* owner;                     // 0x01C, _Init の第2引数, _Update が owner->unk_1c == 4 を見る
  AuxSprite spr0;                    // 0x020, FUN_080abb08 が AuxSprite_Remove に渡す
  u8 unk_4c[0x68 - 0x4C];            // 0x04C
  AuxSprite spr1;                    // 0x068, FUN_080abb08 が AuxSprite_Remove に渡す
  u8 unk_94[0xB0 - 0x94];            // 0x094
  u8 unk_b0;                         // 0x0B0, _Destroy が 0 以外かを見る
  u8 unk_b1;                         // 0x0B1, _Destroy が 0 かを見る
  u8 unk_b2[6];                      // 0x0B2
  void (*spriteFunc)(AuxSprite*);    // 0x0B8, FUN_080abac8 が spr0 を渡して呼ぶ
  u8 unk_bc[4];                      // 0x0BC
  AuxSprite spr2;                    // 0x0C0, FUN_080ab8ec が AuxSprite_Remove に渡す
  u8 unk_ec[0x140 - 0xEC];           // 0x0EC
  Entity080abd14Particle ptcls[12];  // 0x140, 根拠: FUN_080ab6d8 の stride 0x44 × 12
} Entity080abd14;
static_assert(sizeof(Entity080abd14) == 1136);

extern u16 gRisingSunCount;

NAKED void FUN_080ab018(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab018.inc"); }

NAKED void FUN_080ab074(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab074.inc"); }

NAKED void FUN_080ab134(Entity080abd14* p, u32 param_2) { INCFUNC("asm/func/FUN_080ab134.inc"); }

NAKED void FUN_080ab278(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab278.inc"); }

NAKED void FUN_080ab3a0(Entity080abd14* p, u32 param_2) { INCFUNC("asm/func/FUN_080ab3a0.inc"); }

NAKED void FUN_080ab4e8(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab4e8.inc"); }

NAKED void FUN_080ab540(Entity080abd14* p, u32 param_2) { INCFUNC("asm/func/FUN_080ab540.inc"); }

NAKED void FUN_080ab67c(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab67c.inc"); }

void FUN_080ab6d8(Entity080abd14* p) {
  s32 i;

  for (i = 0; i < 12; i++) {
    Particle_Remove(&p->ptcls[i].ptcl);
  }
}

NAKED void FUN_080ab6f8(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab6f8.inc"); }

NAKED void FUN_080ab780(Entity080abd14Sprite* s) { INCFUNC("asm/func/FUN_080ab780.inc"); }

NAKED void FUN_080ab7f0(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab7f0.inc"); }

void FUN_080ab848(Entity080abd14Sprite* s) {
  if (s->timer <= 5) {
    s->spr.flags |= SPRFLAG_BLINK_EVEN;
  } else {
    s->spr.flags &= ~SPRFLAG_BLINK_EVEN;
  }

  if (s->timer == 0) {
    s->spr.flags |= SPRFLAG_HIDDEN;
    s->unk_6c = 0;
  } else {
    s->timer--;
    FUN_080ab780(s);
  }
}

NAKED void FUN_080ab898(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab898.inc"); }

void FUN_080ab8ec(Entity080abd14* p) { AuxSprite_Remove(&p->spr2); }

NAKED void FUN_080ab8f8(Entity080abd14* p, WorldPos* pos) { INCFUNC("asm/func/FUN_080ab8f8.inc"); }

NAKED void FUN_080ab99c(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab99c.inc"); }

NAKED void FUN_080ab9e0(Entity080abd14* p) { INCFUNC("asm/func/FUN_080ab9e0.inc"); }

void FUN_080abac8(Entity080abd14* p) {
  if (p->unk_b0 == 0) {
    if (*(u16*)&p->owner->action == 0x209) {
      p->unk_b0 = 1;
    }

    if (p->unk_b0 == 0) {
      return;
    }
  }

  p->spriteFunc(&p->spr0);
}

void FUN_080abb08(Entity080abd14* p) {
  AuxSprite_Remove(&p->spr0);
  AuxSprite_Remove(&p->spr1);
}

NAKED void FUN_080abb20(Entity080abd14* p, WorldPos* pos) { INCFUNC("asm/func/FUN_080abb20.inc"); }

NAKED s32 Entity080abd14_Update(Entity080abd14* p) { INCFUNC("asm/func/Entity080abd14_Update.inc"); }

s32 Entity080abd14_Destroy(Entity080abd14* p) {
  if (p->unk_b0 && !p->unk_b1 && p->unk_1a == 0) {
    FUN_080ab018(p);
  }

  FUN_080abb08(p);
  FUN_080ab8ec(p);
  FUN_080ab6d8(p);
  if (p->unk_19) {
    gRisingSunCount--;
  }
}

// 残差1命令, 原典は第6引数を 0x1A の下位1バイトに strb するが, u16 unk_1a だと strh になる
// union (u16 / u8[2]) で両方を表そうとすると agbcc が共用体を4バイト境界に置くので sizeof が狂う
NON_MATCH s32 Entity080abd14_Init(Entity080abd14* p, void* owner, WorldPos* pos1, WorldPos* pos2, u32 param_5, u32 param_6) {
#ifdef NONMATCHING_C
  p->unk_18 = param_5;
  p->owner = owner;
  FUN_080abb20(p, pos2);
  FUN_080ab8f8(p, pos1);
  FUN_080ab6f8(p);

  if (param_5 == 0) {
    PlaySound_082406e0(SONG_924);
  } else {
    PlaySound_082406e0(SONG_925);
  }

  p->unk_1a = param_6;
  return 0;
#else
  INCFUNC("asm/func/Entity080abd14_Init.inc");
#endif
}

Entity080abd14* Entity080abd14_Create(void* owner, WorldPos* pos1, WorldPos* pos2, u32 param_4, u32 param_5) {
  Entity080abd14* p = CreateEntity(ENTITY_UNK_8, sizeof(Entity080abd14));

  if (p != NULL) {
    SetEntityRoutine(p, Entity080abd14_Update, Entity080abd14_Destroy);
    if (Entity080abd14_Init(p, owner, pos1, pos2, param_4, param_5) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
