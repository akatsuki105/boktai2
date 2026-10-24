#include "entity.h"
#include "file.h"
#include "game.h"
#include "global.h"
#include "hitbox.h"
#include "mover.h"
#include "sprite.h"
#include "time.h"

typedef struct {
  AuxSprite spr;           // 0x00, _Destroy が AuxSprite_Remove に渡す
  u8 unk_2c[0x3E - 0x2C];  // 0x2C
  s16 unk_3e;              // 0x3E, 2 なら FUN_080dabe4 が何もしない
  u16 unk_40;              // 0x40, FUN_080dacac が bit1、FUN_080dabe4 が bit2 を立てる
  s16 unk_42;              // 0x42, 負なら FUN_080dabe4 が何もしない
  u8 unk_44[2];            // 0x44
  ZoneID16 zoneID;         // 0x46, gStat->zoneID と一致するかを FUN_080dad94 が見る
  u8 unk_48[4];            // 0x48
  HitboxData hitbox;       // 0x4C, _Destroy が Hitbox_Unregister に渡す
  u8 unk_9c[8];            // 0x9C
} Entity080db520Elem;
static_assert(sizeof(Entity080db520Elem) == 164);

typedef struct {
  Entity e;                     // 0x000, ENTITY_UNK_10
  AuxSpriteGfx gfx;             // 0x018, SPRITE_EFF_1C1B
  AuxAnimFile* anim;            // 0x034, ANIM_3DC2
  u32 activeMask;               // 0x038, 使用中の elems のビットマスク
  Entity080db520Elem elems[8];  // 0x03C, 根拠: _Destroy の stride 0xA4 × 8
} Entity080db520;
static_assert(sizeof(Entity080db520) == 1372);

IWRAM_DATA Entity080db520* gEntity080db520 = NULL;  // 0x03000160

const u8 u8_ARRAY_085ad310[4] = {8, 4, 2, 1};  // 0x085AD310

// idx 番の枠の判定を1フレームだけ有効にする
void FUN_080dab9c(s32 idx) {
  Entity080db520* p = gEntity080db520;
  Entity080db520Elem* e;

  if (idx < 0) {
    return;
  }

  e = &p->elems[idx];
  if (e->unk_42 < 0) {
    return;
  }
  if (e->unk_3e == 2) {
    return;
  }

  e->unk_40 |= 2;
  e->hitbox.flags |= HBFLAG_UNK_2;
}

// idx 番の要素の unk_40 に bit2 を立てる
void FUN_080dabe4(s32 idx) {
  Entity080db520* p = gEntity080db520;

  if (idx >= 0) {
    Entity080db520Elem* e = &p->elems[idx];

    if (e->unk_42 >= 0 && e->unk_3e != 2) {
      e->unk_40 |= 4;
    }
  }
}

void FUN_080dac20(Entity080db520* p, Entity080db520Elem* elem) {}

NAKED void FUN_080dac24(Entity080db520* p, u32 param_2) { INCFUNC("asm/func/FUN_080dac24.inc"); }

void FUN_080dacac(Entity080db520* p, u32 param_2, Entity080db520Elem* elem) {
  elem->unk_40 |= 2;
  elem->hitbox.flags |= 4;
}

NAKED void FUN_080dacc4(Entity080db520* p) { INCFUNC("asm/func/FUN_080dacc4.inc"); }

// 空いている枠を確保して返す, 無ければ NULL
// 残差1命令 (34 対 35), 原典は &elems[i] を muls で毎回作るが agbcc は誘導変数に落として基底をループ外へ巻き上げる
// 使用中判定を static inline bool32 (attack_box.c の AttackBoxManager_IsSlotUsed と同じ形) にすると 0/1 の作り置きは再現できるが, 誘導変数の方は動かない
NON_MATCH Entity080db520Elem* FUN_080dad4c(Entity080db520* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!(p->activeMask & (1 << i))) {
      Entity080db520Elem* e = &p->elems[i];

      p->activeMask |= 1 << i;
      e->unk_42 = i;
      return e;
    }
  }
  return NULL;
#else
  INCFUNC("asm/func/FUN_080dad4c.inc");
#endif
}

// 日中で, かつ今いるゾーンがこの枠の指定と同じなら TRUE
// 残差1命令 (37/38), 原典は 0/1 を bne/movs#1/b/movs#0 の二分岐で作るが agbcc は movs#0 を手前のガードより上へ巻き上げて条件付き代入1つに畳む
// bool8 のローカルを宣言と代入に分けると 0/1 の作り置き自体は再現できる (static inline bool32 や初期化子つき宣言では畳まれる). 比較の左右入れ替え, 分岐極性反転, ?: も試済
NON_MATCH bool8 FUN_080dad94(Entity080db520Elem* elem) {
#ifdef NONMATCHING_C
  bool8 same;

  if (gClock.spanOfTime == TIME_UNK5 || gClock.spanOfTime == TIME_NIGHT || gClock.spanOfTime == TIME_UNK4) {
    return FALSE;
  }
  if (!(gStat->unk_934 & 2)) {
    return FALSE;
  }
  if (gStat->zoneID == elem->zoneID) {
    same = TRUE;
  } else {
    same = FALSE;
  }
  if (!same) {
    return FALSE;
  }
  return TRUE;
#else
  INCFUNC("asm/func/FUN_080dad94.inc");
#endif
}

NAKED void FUN_080dadec(Entity080db520* p) { INCFUNC("asm/func/FUN_080dadec.inc"); }

NAKED void FUN_080dae60(Entity080db520* p, Entity080db520Elem* elem) { INCFUNC("asm/func/FUN_080dae60.inc"); }

NAKED void FUN_080db040(Entity080db520* p, Entity080db520Elem* elem) { INCFUNC("asm/func/FUN_080db040.inc"); }

NAKED void FUN_080db0f8(Entity080db520* p) { INCFUNC("asm/func/FUN_080db0f8.inc"); }

// 向きから象限を出して, アニメーションの variant と反転フラグを決める
void Mover_GetAnimQuadrant(Mover* mover, u8* variant, u8* flags) {
  u32 q = ((((mover->angle + 0x20) & 0xFF) >> 6) + 1) & 3;

  if (q > 1) {
    *flags = 1;
    *variant = 3 - q;
  } else {
    *flags = 0;
    *variant = q;
  }
}

NAKED s32 FUN_080db290(Entity080db520* p, u32 param_2) { INCFUNC("asm/func/FUN_080db290.inc"); }

void (*const PTR_ARRAY_085ad314[3])(Entity080db520*, Entity080db520Elem*) = {
    FUN_080dac20,
    FUN_080dae60,
    FUN_080db040,
};  // 0x085AD314

// 使用中の枠について unk_3e ごとの更新関数を呼ぶ
// 残差5命令 (35/40) でこちらが短い, 使用中判定の 0/1 が畳まれる (FUN_080dad4c / Entity080db520_Destroy / attack_box.c と同じ壁)
// static inline bool32, 明示的な if/else での TRUE/FALSE 代入, != 0, ?:, !used + continue の5通りを試したがどれも作り置きは出ない. elems の基底をローカルに取ると 9→5 ハンクまで寄る
NON_MATCH s32 Entity080db520_Update(Entity080db520* p) {
#ifdef NONMATCHING_C
  if (p->activeMask != 0) {
    Entity080db520Elem* elems = p->elems;
    s32 i;

    for (i = 0; i < 8; i++) {
      if (p->activeMask & (1 << i)) {
        Entity080db520Elem* e = &elems[i];

        PTR_ARRAY_085ad314[e->unk_3e](p, e);
      }
    }
    FUN_080dadec(p);
  }

  return 0;
#else
  INCFUNC("asm/func/Entity080db520_Update.inc");
#endif
}

// 残差5命令 (30 対 35), 原典は使用中判定の結果を 1/0 として一度作ってから改めて 0 と比べる (いわゆる 0/1 の作り置き)
// static inline bool32 の判定関数にすると 32 対 35 まで寄るが作り置きは出ない, FUN_080dad4c と同じ壁
NON_MATCH s32 Entity080db520_Destroy(Entity080db520* p) {
#ifdef NONMATCHING_C
  s32 i;

  for (i = 0; i < 8; i++) {
    if (p->activeMask & (1 << i)) {
      Entity080db520Elem* e = &p->elems[i];

      if (e->spr.active) {
        AuxSprite_Remove(&e->spr);
      }
      Hitbox_Unregister(&e->hitbox);
    }
  }

  gEntity080db520 = NULL;
  return 0;
#else
  INCFUNC("asm/func/Entity080db520_Destroy.inc");
#endif
}

s32 Entity080db520_Init(Entity080db520* p) {
  Video_GetAuxSprite(&p->gfx, SPRITE_EFF_1C1B);
  p->activeMask = 0;
  p->anim = GetFile(DIR_ANIMATION, ANIM_3DC2);
  gEntity080db520 = p;
  return 0;
}

Entity080db520* Entity080db520_Create(void) {
  if (gEntity080db520 == NULL) {
    Entity080db520* p = CreateEntity(ENTITY_UNK_10, sizeof(Entity080db520));
    if (p != NULL) {
      SetEntityRoutine(p, Entity080db520_Update, Entity080db520_Destroy);
      if (Entity080db520_Init(p) < 0) {
        KillEntity((Entity*)p);
        return NULL;
      }
    }
    return p;
  }
  return gEntity080db520;
}

void FUN_080db56c(void) { gEntity080db520 = NULL; }

// 不使用?
NAKED void FUN_080db578(void) { INCFUNC("asm/func/FUN_080db578.inc"); }

// 不使用?
NAKED void FUN_080db780(void) { INCFUNC("asm/func/FUN_080db780.inc"); }
