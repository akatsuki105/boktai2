#include "entity.h"
#include "entity_cbb0.h"
#include "global.h"
#include "hitbox.h"
#include "player.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"

s32 SSEEmitter_Destroy(unknown* p);

// 触れたプレイヤーを押し返す, state で Generator_SetState が fn を差し替える
typedef struct {
  Entity e;               // 0x000, ENTITY_UNK_8
  AuxSprite sprite;       // 0x018, Generator_Init が AuxSprite_Add(&sprite, &gfx, 0) で登録し、_Destroy が外す
  AuxSpriteGfx gfx;       // 0x044, SPRITE_GENERATOR
  Vec3 pos;               // 0x060, Generator_Create の第1引数を8バイト複写したもの,Hitbox_SetPos に渡す
  HitboxData hitbox;      // 0x068, Generator_InitHitbox が Hitbox_Init / _SetPowerAndAttributes / _SetPos / _SetHandler する
  AuxAnimState anim;      // 0x0B8, FUN_08236fac(&anim, animFile, 1 か 3, unk_cc, unk_cd)
  AuxAnimFile* animFile;  // 0x0C8, 0x3449
  u8 unk_cc;              // 0x0CC, Generator_Init の第3引数,FUN_08236fac に渡す
  u8 unk_cd;              // 0x0CD, Generator_Init の第4引数,FUN_08236fac に渡す
  u8 unk_ce;              // 0x0CE, Generator_Init の第6引数,読み手が見つかっていない
  u8 state;               // 0x0CF, Generator_SetState が書き、PTR_ARRAY_085AD0B8[state] を fn に入れる,3 で GENERATOR_ENABLED, 5 で GENERATOR_DISABLED を鳴らす
  u16 stateTimer;         // 0x0D0, Generator_SetState が状態遷移のたびに 0 に戻す
  u16 unk_d2;             // 0x0D2, Init が 0、state が 4 のときは anim の先頭ハーフワードを入れる
  u16 unk_d4;             // 0x0D4, Generator_Init の第7引数
  u8 unk_d6[2];           // 0x0D6
  s16 unk_d8;             // 0x0D8, Div(unk_d4, 6)
  u16 unk_da;             // 0x0DA, Init が 0,_Update が 0 まで減らす
  u16 unk_dc;             // 0x0DC, Generator_Init の第9引数,読み手が見つかっていない
  u8 unk_de[2];           // 0x0DE
  u16 unk_e0;             // 0x0E0, _Update が 0 まで減らす
  u16 unk_e2;             // 0x0E2, 0 でない間 Generator_UpdateFlash が flashTimer を増やし、その後 0 に戻す
  u16 flashTimer;         // 0x0E4, 12 でパレット 0x1C7、1〜11 で 0x1C6、0 で plttID に戻る
  u8 unk_e6[2];           // 0x0E6
  u16 unk_e8;             // 0x0E8, gEntityCBB0 の field_0xc10 が立ち、かつ state が 4 のときだけ減る
  u8 unk_ea;              // 0x0EA, Init が 0,読み手が見つかっていない
  u8 unk_eb;              // 0x0EB, 0 でない間 Generator_UpdateFlash がパレット 0x132 を強制して減らす
  u8 unk_ec;              // 0x0EC, Init が 0,読み手が見つかっていない
  u8 unk_ed;              // 0x0ED
  u16 plttID;             // 0x0EE, Video_SetAuxSpritePltt(&gfx, plttID),Init が state に応じて 0x1C3 か 0x1C4 を入れる
  u16 unk_f0;             // 0x0F0, 点灯時のパレットID
  bool16 unk_f2;          // 0x0F2, 0 でない間は稼働中
  u16 unk_f4;             // 0x0F4, 次に音を鳴らす残り時間
  u8 unk_f6[3];           // 0x0F6
  u8 unk_f9;              // 0x0F9, 0 まで減らすだけのカウンタ
  u8 unk_fa[6];           // 0x0FA
  SSEEmitter unk_100;     // 0x100, Init が SSEEmitter_Init(&unk_100, &sprite.pos, 0, 0, 0)、_Destroy が SSEEmitter_Destroy する
  EntityFunc fn;          // 0x238, _Update が毎フレーム呼ぶ,Generator_SetState が state と一緒に書く
} Generator;
static_assert(sizeof(Generator) == 572);

void* SSEEmitter_Reset(SSEEmitter* p);
void* SSEEmitter_FadeParticle(SSEEmitter* p);

NAKED void Generator_SetState(Generator* p, s32 state) { INCFUNC("asm/func/Generator_SetState.inc"); }

// スプライトを本来の位置から ±5 揺らす
NON_MATCH void FUN_080b2888(Generator* p) {
#ifdef NONMATCHING_C
  u16* table;

  p->sprite.pos = p->pos;
  p->unk_ed = 1;
  table = gRandomTable;
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  p->sprite.pos.x = p->sprite.pos.x - 5 + Mod(table[gRandTableIdx], 10);
  gRandTableIdx = (gRandTableIdx + 1) & 0x3FF;
  p->sprite.pos.z = p->sprite.pos.z - 5 + Mod(table[gRandTableIdx], 10);
#else
  INCFUNC("asm/func/FUN_080b2888.inc");
#endif
}

NAKED void Generator_PushPlayer(Generator* p) { INCFUNC("asm/func/Generator_PushPlayer.inc"); }

static inline bool32 Hitbox_HasAttributes(HitboxData* p, u32 mask) { return p->attributes & mask; }

// 攻撃属性を持つ判定を受けたら発電量を溜め、上限に届いたら state 3 へ進む
NON_MATCH void FUN_080b29a4(HitboxData* a, HitboxData* b, Generator* p) {
#ifdef NONMATCHING_C
  if (Hitbox_HasAttributes(a, 0x7F) && p->unk_e0 == 0 && p->state == 2) {
    s32 power = a->power - b->power;

    if (power < 0) {
      power = 1;
    }
    p->unk_eb = 4;
    p->unk_d2 += power;
    if (p->unk_d2 < p->unk_d4) {
      p->unk_e0 = 12;
      PlaySound_082406e0(0x127);
    } else {
      p->unk_d2 = p->unk_d4;
      Generator_SetState(p, 3);
    }
  }
#else
  INCFUNC("asm/func/FUN_080b29a4.inc");
#endif
}

// state 0 のハンドラ
void FUN_080b2a14(Generator* p) {}

NAKED void FUN_080b2a18(Generator* p) { INCFUNC("asm/func/FUN_080b2a18.inc"); }

NAKED void FUN_080b2b68(Generator* p) { INCFUNC("asm/func/FUN_080b2b68.inc"); }

NAKED void FUN_080b2c70(Generator* p) { INCFUNC("asm/func/FUN_080b2c70.inc"); }

NAKED void FUN_080b2dec(Generator* p) { INCFUNC("asm/func/FUN_080b2dec.inc"); }

NAKED void FUN_080b2f0c(Generator* p) { INCFUNC("asm/func/FUN_080b2f0c.inc"); }

NAKED void FUN_080b31b4(Generator* p) { INCFUNC("asm/func/FUN_080b31b4.inc"); }

// 発電中はゲージ音を鳴らし、待機中は16フレームで state 4 へ進む
void FUN_080b32e0(Generator* p) {
  if (p->unk_f9 != 0) {
    p->unk_f9--;
  }
  if (p->unk_f2 == 0) {
    if (p->stateTimer == 0) {
      SSEEmitter_Reset(&p->unk_100);
    }
    p->stateTimer++;
    if (p->stateTimer > 15) {
      p->sprite.pos = p->pos;
      p->plttID = 0x1C5;
      Generator_SetState(p, 4);
      p->hitbox.damage = 0;
      p->stateTimer = 0;
    } else {
      p->plttID = p->unk_f0 - 1;
    }
  } else {
    p->plttID = p->unk_f0;
    p->unk_f2--;
    if (p->unk_f2 < p->unk_f4) {
      SSEEmitter_FadeParticle(&p->unk_100);
      p->unk_f4 -= 250;
    }
  }
}

// 被弾フラグが立っていれば点滅を強め、収まったら元のパレットに戻していく
void Generator_UpdateFlash(Generator* p) {
  if (p->unk_e2 != 0) {
    if (p->flashTimer <= 11) {
      p->flashTimer++;
    }
    p->unk_e2 = 0;
  } else {
    if (p->flashTimer != 0) {
      p->flashTimer--;
    }
  }
  if (p->flashTimer == 12) {
    Video_SetAuxSpritePltt(&p->gfx, 455);
  } else if (p->flashTimer != 0) {
    Video_SetAuxSpritePltt(&p->gfx, 454);
  } else if (p->unk_eb != 0) {
    Video_SetAuxSpritePltt(&p->gfx, 306);
    p->unk_eb--;
  } else {
    Video_SetAuxSpritePltt(&p->gfx, p->plttID);
  }
}

s32 Generator_Update(Generator* p) {
  if (p->state != 0) {
    Generator_PushPlayer(p);
  }
  if (p->unk_da != 0) {
    p->unk_da--;
  }
  if (p->unk_e0 != 0) {
    p->unk_e0--;
  }
  p->fn((Entity*)p);
  Generator_UpdateFlash(p);
  if (p->unk_e8 != 0) {
    if (gEntityCBB0->unk_c10 == 0) {
      p->unk_e8 = 0;
    } else if (p->state != 4) {
      p->unk_e8 = 0;
    } else {
      p->hitbox.damage = 0;
      p->unk_e8--;
    }
  }
  return 0;
}

s32 Generator_Destroy(Generator* p) {
  AuxSprite_Remove(&p->sprite);
  Hitbox_Unregister(&p->hitbox);
  SSEEmitter_Destroy(&p->unk_100);
  return 0;
}

void Generator_InitHitbox(Generator* p, u32 power) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize;
  Vec3 offset;

  halfSize.x = 100, halfSize.y = 200, halfSize.z = 100;
  offset.x = 0, offset.y = 200, offset.z = 0;
  Hitbox_Init(hitbox, 0, HBFLAG_UNK_14 | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPowerAndAttributes(hitbox, power, 0, 0);
  Hitbox_SetPos(hitbox, &p->pos, 0);
  Hitbox_SetHandler(hitbox, FUN_080b29a4, p);
}

NAKED s32 Generator_Init(Generator* p, Vec3* pos, s32 param_3, s32 param_4, s32 state, s32 param_6, s32 param_7, u32 power, s32 param_9) { INCFUNC("asm/func/Generator_Init.inc"); }

Generator* Generator_Create(Vec3* pos, s32 param_2, s32 param_3, s32 state, s32 param_5, s32 param_6, u32 power, s32 param_8) {
  Generator* p = CreateEntity(ENTITY_UNK_8, sizeof(Generator));

  if (p != NULL) {
    SetEntityRoutine(p, Generator_Update, Generator_Destroy);
    if (Generator_Init(p, pos, param_2, param_3, state, param_5, param_6, power, param_8) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
