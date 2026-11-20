#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "random.h"
#include "sound.h"
#include "sprite_aux.h"
#include "trig.h"
#include "vec3.h"

// HomingLaser.kind
#define HOMING_SOL 0
#define HOMING_DARK 1
#define HOMING_FLAME 2
#define HOMING_FROST 3
#define HOMING_CLOUD 4
#define HOMING_EARTH 5

// ヨルムンガンドの怪光線?(各属性のホーミングレーザー), 先頭の pos を 9 枚のスプライトが trail をたどって追いかける
// 怪光線は8個の球が数珠状に連なった見た目をしている
typedef struct {
  bool8 stateEntered;    // 0x000
  u8 state;              // 0x001, sHomingLaserUpdates の添字, 0: 追尾, 1: 跳ね返されて戻る, 2: 散る, 3: 消える
  u8 kind;               // 0x002, 0..5, see HOMING_* (e.g. HOMING_SOL)
  u8 unk_003[3];         // 0x003
  u16 timer;             // 0x006, state を変えると 0 に戻る
  u8 trailHead;          // 0x008, trail の次に書く位置, 0..8
  u8 angle;              // 0x009, 進む向き, heading の上位 8bit
  u16 targetAngle;       // 0x00A, target への向き (8.8)
  u16 heading;           // 0x00C, 進む向き (8.8)
  u16 turnRate;          // 0x00E, 1 フレームに曲がれる量は turnRate * 12, 毎フレーム 1 ずつ減る
  u16 speed;             // 0x010
  u16 unk_012;           // 0x012
  Vec3 pos;              // 0x014, 先頭の位置
  Vec3 trail[9];         // 0x01C, 2 フレームごとに pos を書き残すリングバッファ
  Vec3 startPos;         // 0x064, 跳ね返されたときの pos, ここから target へ戻る
  Vec3* target;          // 0x06C
  u8 scatterAngles[9];   // 0x070, 散るときの各スプライトの向き
  u8 scatterSpeeds[9];   // 0x079, 散るときの各スプライトの速さ
  u8 unk_082[2];         // 0x082, padding?
  Hitbox hitbox;         // 0x084
  Hitbox hurtbox;        // 0x0D4, ハンドラは HomingLaser_OnHurt
  AuxSprite sprites[9];  // 0x124, sprites[0] が先頭
  AuxSpriteGfx gfx;      // 0x2B0, SPR_LASBOS_00
} HomingLaser;
static_assert(sizeof(HomingLaser) == 716);

// ヨルムンガンドの怪光線 を 8 本まで持つ
typedef struct HomingLaserManager {
  Entity e;                // 0x0000, ENTITY_UNK_8
  u32 flags;               // 0x0018, bit i が立っていれば lasers[i] が使用中
  u16 power;               // 0x001C, 怪光線の攻撃力
  u8 unk_1e[0x24 - 0x1E];  // 0x001E, まだ未解析
  HomingLaser lasers[8];   // 0x0024
} HomingLaserManager;
static_assert(sizeof(HomingLaserManager) == 5764);

// HomingLaser.kind ごとの {攻撃の属性, 食らい判定の弱点}, 怪光線は弱点属性の攻撃で相殺できる
static const HitboxAttrs sHomingLaserAttrs[6][2] = {
    [HOMING_SOL] = {HBATTR_SOL,                    HBATTR_DARK },
    [HOMING_DARK] = {HBATTR_DARK,                   HBATTR_SOL  },
    [HOMING_FLAME] = {HBATTR_INKA | HBATTR_FLAME,    HBATTR_FROST},
    [HOMING_FROST] = {HBATTR_HYOKETU | HBATTR_FROST, HBATTR_FLAME},
    [HOMING_CLOUD] = {HBATTR_SEKIKA | HBATTR_CLOUD,  HBATTR_EARTH},
    [HOMING_EARTH] = {HBATTR_POISON | HBATTR_EARTH,  HBATTR_CLOUD},
};  // 0x08DBD7D0

WorldPos* FUN_080230c4(void);

// from から to への向き (8bit)
static inline s32 HomingLaser_AngleTo(Vec3* from, Vec3* to) { return ArcTan2_8(to->x - from->x, to->z - from->z); }

static inline void HomingLaser_SetState(HomingLaser* e, u32 state) {
  e->state = state;
  e->stateEntered = TRUE;
  e->timer = 0;
}

// 空いている枠を返す, 無ければ NULL
HomingLaser* HomingLaserManager_FindFree(HomingLaserManager* p, s32* outIndex) {
  s32 i;

  for (i = 0; i < 8; i++) {
    if (!(p->flags & 1 << i)) {
      *outIndex = i;
      return &p->lasers[i];
    }
  }
  return NULL;
}

// 近接武器で斬られたら, 弾かれたときは跳ね返されて戻り, 属性つきの攻撃なら散る
void HomingLaser_OnHurt(Hitbox* a, Hitbox* b, HomingLaser* e) {
  HomingLaser* laser = e;

  e->angle = a->angle;
  if (Hitbox_HasSource(a, HBSRC_SWORD | HBSRC_SPEAR | HBSRC_HAMMER)) {
    Hitbox_ApplyDamage(a, b);
    if (b->hitResult & HBRESULT_RESIST) {
      PlaySound_082406e0(SONG_553);
      HomingLaser_SetState(e, 1);
    } else if (Hitbox_TestAttr(a, HBATTR_ELEMENT_MASK)) {
      PlaySound_082406e0(SE_554);
      HomingLaser_SetState(laser, 2);
    }
  }
}

void nop_08245cf8(void) {}

// スプライト9枚と攻撃判定, 食らい判定を用意する, 食らい判定は隠したまま登録しておく
// 残差 (152/151): 原典は e を r9, Vec3_Clear の 0 を r7 に置き, 0 を byte 用と halfword 用の2本に分ける, こちらは e が r7
// Tier A-C は試済 (SetState inline と直書き, 添字ループ, state の型), 未: Tier D
NON_MATCH void HomingLaser_Init(HomingLaserManager* p, HomingLaser* e, s32 idx) {
#ifdef NONMATCHING_C
  AuxSprite* spr;
  Vec3 size;
  Vec3 offset;
  s32 i;

  HomingLaser_SetState(e, 0);
  e->angle = 0;
  e->targetAngle = 0;
  Video_GetAuxSprite(&e->gfx, SPR_LASBOS_00);
  Video_SetAuxSpritePltt(&e->gfx, 351);
  spr = e->sprites;
  for (i = 0; i < 9; i++, spr++) {
    AuxSprite_Setup(spr, &e->gfx, 1);
    spr->poseIdx = 8 - i;
    spr->priority = 1;
    Vec3_Clear(&spr->pos);
  }

  VEC3_SET(size, 32, 100, 32);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(&e->hurtbox, 0, HBF_HURTBOX | HBF_HIDDEN | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetPos(&e->hurtbox, &e->pos, 0);
  Hitbox_SetHandler(&e->hurtbox, HomingLaser_OnHurt, e);
  Hitbox_SetPowerAndAttributes(&e->hurtbox, 0, 0, 0);
  Hitbox_Register(&e->hurtbox);

  VEC3_SET(size, 32, 100, 32);
  VEC3_SET(offset, 0, 0, 0);
  Hitbox_Init(&e->hitbox, 0, HBF_HITBOX | HBF_DAMAGE, 0, HIM_4, &size, &offset);
  Hitbox_SetPos(&e->hitbox, &e->pos, 0);
  Hitbox_SetHandler(&e->hitbox, nop_08245cf8, e);
  Hitbox_SetAttack(&e->hitbox, p->power, 30, HBSRC_GUN, 0, 30);
#else
  INCFUNC("asm/func/HomingLaser_Init.inc");
#endif
}

// 枠のスプライト9枚を外して判定を無効にし, 使用中ビットを落とす
s32 HomingLaser_Free(HomingLaserManager* p, HomingLaser* e, s32 idx) {
  AuxSprite* spr = e->sprites;
  Hitbox* hurtbox;
  s32 i;

  for (i = 0; i < 9; i++, spr++) {
    AuxSprite_Remove(spr);
  }

  hurtbox = &e->hurtbox;
  hurtbox->flags |= HBF_HIDDEN;
  p->flags &= ~(1 << idx);
}

// 2 フレームごとに先頭の位置を trail に書き残し, 後ろの 8 枚を trail の古い順にたどらせる
// 残差2箇所 (63/63): trail[idx] の番地の adds の向きだけ, 原典は idx*8 が先で e が後, *(idx + e->trail) と書くと向きは揃う
// Tier A-B は試済 (Vec3* trail ローカル, 取り出し inline, (u32) 添字), 未: pos と trail を1つの配列にする形
NON_MATCH void HomingLaser_UpdateTrail(HomingLaser* e) {
#ifdef NONMATCHING_C
  AuxSprite* spr;
  s32 idx;
  s32 i;

  if (!(e->timer & 1)) {
    e->sprites[0].pos = e->pos;
  }
  idx = e->trailHead - 1;
  if (idx < 0) {
    idx = 8;
  }
  spr = &e->sprites[1];
  for (i = 0; i < 8; i++, spr++) {
    spr->pos = e->trail[idx];
    if (--idx < 0) {
      idx = 8;
    }
  }
  if (!(e->timer & 1)) {
    e->trail[e->trailHead] = e->sprites[0].pos;
    if (++e->trailHead > 8) {
      e->trailHead = 0;
    }
  }
#else
  INCFUNC("asm/func/HomingLaser_UpdateTrail.inc");
#endif
}

// まだ散っていないスプライトは trail をたどり, 散ったスプライトは各自の向きと速さで飛ぶ, 後ろから 2 フレームに 1 枚ずつ散っていく
void HomingLaser_UpdateScatter(HomingLaser* e) {
  AuxSprite* spr;
  s32 idx;
  s32 i;

  idx = e->trailHead - 1;
  if (idx < 0) {
    idx = 8;
  }
  spr = e->sprites;
  for (i = 0; i < 9; i++, spr++) {
    if (i * 2 > e->timer) {
      spr->pos = e->trail[idx];
      if (--idx < 0) {
        idx = 8;
      }
    } else {
      Vec3 d;

      Vec3_SetPolar(&d, e->scatterAngles[i], e->scatterSpeeds[i]);
      Vec3_Add(&spr->pos, &d);
    }
  }
  if (!(e->timer & 1)) {
    e->trail[e->trailHead] = e->sprites[0].pos;
    if (++e->trailHead > 8) {
      e->trailHead = 0;
    }
  }
}

// target の方へ向きを変える, 1 フレームに曲がれるのは turnRate * 12 まで
void HomingLaser_TurnToTarget(HomingLaser* e) {
  s16 diff;
  s16 limit;

  e->targetAngle = ArcTan2_8(e->target->x - e->pos.x, e->target->z - e->pos.z) << 8;
  limit = e->turnRate * 12;
  diff = e->targetAngle - e->heading;
  if (diff < -limit) {
    diff = -limit;
  } else if (diff > limit) {
    diff = limit;
  }
  e->heading += diff;
  e->angle = e->heading >> 8;
}

// 食らい判定を出して target を追いかける, 150 フレームで消える
void HomingLaser_StateHoming(HomingLaserManager* p, HomingLaser* e, s32 idx) {
  Vec3 d;

  if (e->stateEntered) {
    e->stateEntered = FALSE;
    Hitbox_ClearFlags(&e->hurtbox, HBF_HIDDEN);
    e->heading = e->angle << 8;
    e->turnRate = 64;
  }
  if (e->turnRate != 0) {
    e->turnRate--;
  }
  HomingLaser_TurnToTarget(e);
  Vec3_SetPolar(&d, e->angle, e->speed);
  Vec3_Add(&e->pos, &d);
  Hitbox_SetPos(&e->hitbox, &e->pos, 0);
  Hitbox_SetPos(&e->hurtbox, &e->pos, 0);
  Hitbox_Register(&e->hitbox);
  HomingLaser_UpdateTrail(e);
  if (e->timer >= 150) {
    HomingLaser_SetState(e, 3);
  } else {
    e->timer++;
  }
}

// 跳ね返されてボスへ蛇行しながら戻る, 32 フレームで散る
// 残差1箇所 (170/170): Random() の表の番地の仮レジスタが原典は r6, こちらは r1, black_panther.c の Spawn 3関数と似た壁
// Tier A-C は試済 (pos ポインタを Hide の後に取る, AngleTo inline, if/else), 未: 乱数の inline の形
NON_MATCH void HomingLaser_StateReflected(HomingLaserManager* p, HomingLaser* e, s32 idx) {
#ifdef NONMATCHING_C
  Vec3 d;
  s32 amp;

  if (e->stateEntered) {
    Vec3* pos;
    s32 angle;

    e->stateEntered = FALSE;
    Hitbox_Hide(&e->hurtbox);
    pos = &e->pos;
    e->startPos = *pos;
    e->target = FUN_080230c4();
    angle = HomingLaser_AngleTo(pos, e->target);
    e->angle = (Random() & 0xFF) < 128 ? angle - 64 : angle + 64;
    e->hitbox.ignoreMask = 1;
    e->hurtbox.ignoreMask = 1;
  }
  LerpVec3(&e->pos, &e->startPos, e->target, e->timer, 5);
  amp = (SIN(e->timer * 4) * 3) >> 5;
  Vec3_SetPolar(&d, e->angle, amp);
  Vec3_Add(&e->pos, &d);
  Hitbox_SetPos(&e->hitbox, &e->pos, 0);
  Hitbox_SetPos(&e->hurtbox, &e->pos, 0);
  Hitbox_Register(&e->hitbox);
  HomingLaser_UpdateTrail(e);
  if (e->timer >= 32) {
    HomingLaser_SetState(e, 2);
  } else {
    e->timer++;
  }
#else
  INCFUNC("asm/func/HomingLaser_StateReflected.inc");
#endif
}

// 先頭の向きを中心にスプライトごとに向きと速さを決めて散らせ, 30 フレームで片付ける
void HomingLaser_StateScatter(HomingLaserManager* p, HomingLaser* e, s32 idx) {
  if (e->stateEntered) {
    s32 i;

    e->stateEntered = FALSE;
    Hitbox_Hide(&e->hurtbox);
    e->angle = HomingLaser_AngleTo(&e->sprites[1].pos, &e->sprites[0].pos);
    for (i = 0; i < 9; i++) {
      e->scatterAngles[i] = (u8)((RandomNext() & 0x1F) - 16) + e->angle;
      e->scatterSpeeds[i] = (RandomNext() & 0xF) + 24;
    }
  }
  HomingLaser_UpdateScatter(e);
  if (e->timer >= 30) {
    HomingLaser_Free(p, e, idx);
  } else {
    e->timer++;
  }
}

// 食らい判定を外して尾がたどり着くのを待ち, 30 フレームで片付ける
void HomingLaser_StateVanish(HomingLaserManager* p, HomingLaser* e, s32 idx) {
  if (e->stateEntered) {
    Hitbox* hurtbox;

    e->stateEntered = FALSE;
    hurtbox = &e->hurtbox;
    hurtbox->flags |= HBF_HIDDEN;
  }

  HomingLaser_UpdateTrail(e);

  if (e->timer >= 30) {
    HomingLaser_Free(p, e, idx);
  } else {
    e->timer++;
  }
}

s32 HomingLaserManager_Update(HomingLaserManager* p) {
  static void (*const sHomingLaserUpdates[4])(HomingLaserManager*, HomingLaser*, s32) = {
      HomingLaser_StateHoming,
      HomingLaser_StateReflected,
      HomingLaser_StateScatter,
      HomingLaser_StateVanish,
  };  // 0x08DBD800

  HomingLaser* e = p->lasers;
  s32 i;

  for (i = 0; i < 8; i++, e++) {
    if (p->flags & 1 << i) {
      sHomingLaserUpdates[e->state](p, e, i);
    }
  }
  return 0;
}

s32 HomingLaserManager_Destroy(HomingLaserManager* p) {
  HomingLaser* e;
  s32 i;

  e = p->lasers;
  i = 0;
  while (i < 8) {
    if (p->flags & (1 << i)) {
      HomingLaser_Free(p, e, i);
    }
    Hitbox_Unregister(&e->hurtbox);
    i++;
    e++;
  }
  return 0;
}

s32 HomingLaserManager_Init(HomingLaserManager* p, s32 power) {
  HomingLaser* e;
  s32 i;

  p->power = power;
  e = p->lasers;
  i = 0;
  while (i < 8) {
    HomingLaser_Init(p, e, i);
    i++;
    e++;
  }
  return 0;
}

HomingLaserManager* HomingLaserManager_Create(s32 val, s32 _) {
  HomingLaserManager* p = CreateEntity(ENTITY_UNK_8, sizeof(HomingLaserManager));

  if (p != NULL) {
    SetEntityRoutine(p, HomingLaserManager_Update, HomingLaserManager_Destroy);
    if (HomingLaserManager_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 空いている枠に怪光線を1本出す, 空きが無ければ -1
// 残差 (140/137): trail[i] = pos のループを原典は i*8 + e で毎回作り誘導変数にしない, こちらはポインタに強度削減する (UpdateTrail と同じ壁)
// Tier A-B は試済 (sprites[i] の添字), 未: trail の添字の形
NON_MATCH s32 CreateHomingLaser(HomingLaserManager* p, Vec3* pos, Vec3* target, u32 angle, u32 speed, u32 kind) {
#ifdef NONMATCHING_C
  s32 idx;
  HomingLaser* e = HomingLaserManager_FindFree(p, &idx);
  AuxSprite* spr;
  s32 i;

  if (e == NULL) {
    return -1;
  }
  HomingLaser_SetState(e, 0);
  e->angle = angle;
  e->targetAngle = angle << 8;
  e->heading = angle << 8;
  e->speed = speed;
  e->kind = kind;
  e->turnRate = 64;
  e->trailHead = 0;
  e->target = target;
  e->pos = *pos;
  spr = e->sprites;
  for (i = 0; i < 9; i++, spr++) {
    e->trail[i] = e->pos;
    spr->pos = e->pos;
    AuxSprite_Show(spr);
    Video_AddAuxSpriteIntoDrawList(spr, 0);
  }
  Video_SetAuxSpritePltt(&e->gfx, e->kind + 351);
  Hitbox_SetPos(&e->hitbox, &e->pos, 0);
  Hitbox_SetPos(&e->hurtbox, &e->pos, 0);
  Hitbox_Hide(&e->hurtbox);
  e->hitbox.ignoreMask = HIM_4;
  e->hurtbox.ignoreMask = HIM_4;
  Hitbox_SetAttack(&e->hitbox, p->power, 30, HBSRC_GUN, sHomingLaserAttrs[e->kind][0], 30);
  Hitbox_SetPowerAndAttributes(&e->hurtbox, 0, sHomingLaserAttrs[e->kind][0], sHomingLaserAttrs[e->kind][1]);
  p->flags |= 1 << idx;
  return 0;
#else
  INCFUNC("asm/func/CreateHomingLaser.inc");
#endif
}

// 追尾中の怪光線をすべて消える状態にする
void* HomingLaserManager_VanishAll(HomingLaserManager* p) {
  HomingLaser* e = p->lasers;
  s32 i;

  for (i = 0; i < 8; i++, e++) {
    if ((p->flags & 1 << i) && e->state == 0) {
      e->state = 3;
      e->stateEntered = TRUE;
      e->timer = 0;
    }
  }
}
