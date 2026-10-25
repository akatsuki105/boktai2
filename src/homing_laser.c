#include "entity.h"
#include "global.h"
#include "hitbox.h"
#include "sprite_aux.h"

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
  HitboxData hitbox;     // 0x084
  HitboxData hurtbox;    // 0x0D4, ハンドラは HomingLaser_OnHurt
  AuxSprite sprites[9];  // 0x124, sprites[0] が先頭
  AuxSpriteGfx gfx;      // 0x2B0, SPRITE_JORMUNGANDR_8202
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
static const HitboxAttributes sHomingLaserAttrs[6][2] = {
    [HOMING_SOL] = {HBATTR_SOL,                   HBATTR_DARK },
    [HOMING_DARK] = {HBATTR_DARK,                  HBATTR_SOL  },
    [HOMING_FLAME] = {HBATTR_21 | HBATTR_FLAME,     HBATTR_FROST},
    [HOMING_FROST] = {HBATTR_22 | HBATTR_FROST,     HBATTR_FLAME},
    [HOMING_CLOUD] = {HBATTR_14 | HBATTR_CLOUD,     HBATTR_EARTH},
    [HOMING_EARTH] = {HBATTR_POISON | HBATTR_EARTH, HBATTR_CLOUD},
};  // 0x08DBD7D0

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

NAKED void HomingLaser_OnHurt(HitboxData* a, HitboxData* b, HomingLaser* e) { INCFUNC("asm/func/HomingLaser_OnHurt.inc"); }

void nop_08245cf8(void) {}

NAKED void HomingLaser_Init(HomingLaserManager* p, HomingLaser* e, s32 idx) { INCFUNC("asm/func/HomingLaser_Init.inc"); }

// 枠のスプライト9枚を外して判定を無効にし, 使用中ビットを落とす
s32 HomingLaser_Free(HomingLaserManager* p, HomingLaser* e, s32 idx) {
  AuxSprite* spr = e->sprites;
  HitboxData* hurtbox;
  s32 i;

  for (i = 0; i < 9; i++, spr++) {
    AuxSprite_Remove(spr);
  }

  hurtbox = &e->hurtbox;
  hurtbox->flags |= HBFLAG_HIDDEN;
  p->flags &= ~(1 << idx);
}

NAKED void HomingLaser_UpdateTrail(HomingLaser* e) { INCFUNC("asm/func/HomingLaser_UpdateTrail.inc"); }

NAKED void HomingLaser_UpdateScatter(HomingLaser* e) { INCFUNC("asm/func/HomingLaser_UpdateScatter.inc"); }

NAKED void HomingLaser_TurnToTarget(HomingLaser* e) { INCFUNC("asm/func/HomingLaser_TurnToTarget.inc"); }

NAKED void HomingLaser_StateHoming(HomingLaserManager* p, HomingLaser* e, s32 idx) { INCFUNC("asm/func/HomingLaser_StateHoming.inc"); }

NAKED void FUN_0824617c(HomingLaserManager* p, HomingLaser* e, s32 idx) { INCFUNC("asm/func/FUN_0824617c.inc"); }

NAKED void HomingLaser_StateScatter(HomingLaserManager* p, HomingLaser* e, s32 idx) { INCFUNC("asm/func/HomingLaser_StateScatter.inc"); }

// 食らい判定を外して尾がたどり着くのを待ち, 30 フレームで片付ける
void FUN_082463cc(HomingLaserManager* p, HomingLaser* e, s32 idx) {
  if (e->stateEntered) {
    HitboxData* hurtbox;

    e->stateEntered = FALSE;
    hurtbox = &e->hurtbox;
    hurtbox->flags |= HBFLAG_HIDDEN;
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
      FUN_0824617c,
      HomingLaser_StateScatter,
      FUN_082463cc,
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

NAKED s32 CreateHomingLaser(HomingLaserManager* p, Vec3* pos, Vec3* target, u32 angle, u32 speed, u32 kind) { INCFUNC("asm/func/CreateHomingLaser.inc"); }

// 追尾中の怪光線をすべて消える状態にする
void* FUN_08246624(HomingLaserManager* p) {
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
