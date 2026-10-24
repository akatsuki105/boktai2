#include "entity.h"
#include "file.h"
#include "global.h"
#include "sprite.h"

// パーティクル1個分, FUN_080155e4 で発生させる
typedef struct {
  bool8 active;       // 0x00, 0 でなければ Update/Destroy が処理する, アニメが終わると 0
  u8 kind;            // 0x01, 5/6/7 は別スプライト (0x61F9) と animFiles[1], それ以外はパレット kind + 0x7D
  u16 timer;          // 0x02, 発生からのフレーム数
  s16 speedY;         // 0x04, decayStartY に達したら *= decayY / 256
  s16 speedXZ;        // 0x06, decayStartXZ に達したら *= decayXZ / 256
  u16 decayStartY;    // 0x08
  u16 decayY;         // 0x0A, 8.8 固定小数の倍率, どこでも書き込まれないので常に 0 (decayStartY で止まる)
  u16 decayStartXZ;   // 0x0C
  u16 decayXZ;        // 0x0E, 同上
  s4_12 dirX;         // 0x10, gSineTable[(angleXZ + 0x40) & 0xFF], ここから unk_16 (含む)　まで、 Vec3 (の s4_12 版) かも
  s4_12 dirY;         // 0x12, gSineTable[angleY & 0xFF]
  s4_12 dirZ;         // 0x14, gSineTable[angleXZ & 0xFF]
  u8 unk_16[2];       // 0x16
  u16 velX;           // 0x18, dirX * speedXZ >> 12, 毎フレーム sprite.pos.x に加算
  u16 velY;           // 0x1A, dirY * speedY >> 12, 毎フレーム sprite.pos.y に加算
  u16 velZ;           // 0x1C, dirZ * speedXZ >> 12, SCREEN_COORD でなければ sprite.pos.z に加算
  u8 unk_1e[2];       // 0x1E
  AuxSpriteGfx gfx;   // 0x20
  AuxSprite sprite;   // 0x3C
  AuxAnimState anim;  // 0x68
} Entity08015584Elem;
static_assert(sizeof(Entity08015584Elem) == 120);

typedef struct {
  Entity e;                      // 0x00, ENTITY_UNK_9
  AuxAnimFile* animFiles[2];     // 0x18, id: FileID_ARRAY_085aa914[i]
  u32 counter;                   // 0x20, Init で 0, Update で毎フレーム +1
  Entity08015584Elem elems[32];  // 0x24
} Entity08015584;
static_assert(sizeof(Entity08015584) == 3876);

IWRAM_DATA Entity08015584* gEntity08015584 = NULL;  // 0x03000060

const FileID FileID_ARRAY_085aa914[2] = {ANIM_F62B, ANIM_31F4};  // 0x085AA914

void FUN_08015264(void) { gEntity08015584 = NULL; }

NAKED s32 Entity08015584_Update(Entity08015584* p) { INCFUNC("asm/func/Entity08015584_Update.inc"); }

s32 Entity08015584_Destroy(Entity08015584* p) {
  s32 i;

  for (i = 0; i < 32; i++) {
    if (p->elems[i].active) {
      AuxSprite_Remove(&p->elems[i].sprite);
    }
  }

  gEntity08015584 = NULL;
  return 0;
}

NAKED s32 Entity08015584_Init(Entity08015584* p, u32 _) { INCFUNC("asm/func/Entity08015584_Init.inc"); }

Entity08015584* Entity08015584_Create(u32 val, u32 _) {
  Entity08015584* p = CreateEntity(ENTITY_UNK_9, sizeof(Entity08015584));
  if (p != NULL) {
    SetEntityRoutine(p, Entity08015584_Update, Entity08015584_Destroy);
    if (Entity08015584_Init(p, val) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}

// 残差2命令, 原典は結果を r1 に置いて最後に r0 へ写す (n が r0 = 引数レジスタに残る) が,
// ローカルの宣言順・引数の使い回し・三項/if の書き換えでは n と結果のレジスタが入れ替わらない
NON_MATCH u32 FUN_080155c8(s32 flags) {
#ifdef NONMATCHING_C
  s32 n = ((flags & 0xF000) >> 12) - 1;

  return (n >= 0 && n <= 3) ? n : 2;
#else
  INCFUNC("asm/func/FUN_080155c8.inc");
#endif
}

NAKED s32 FUN_080155e4(s32 count, WorldPos* pos, ParticleSpawnParam* params) { INCFUNC("asm/func/FUN_080155e4.inc"); }

NAKED void FUN_08015a90(WorldPos* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8) { INCFUNC("asm/func/FUN_08015a90.inc"); }

NAKED void FUN_08015b18(WorldPos* pos, s32 param_2, s32 param_3, s32 param_4, s32 param_5, s32 param_6, s32 param_7, s32 param_8, s32 param_9, s32 param_10, s32 param_11) { INCFUNC("asm/func/FUN_08015b18.inc"); }

void FUN_08015c28(WorldPos* pos, u32 angleXZ, u32 angleXZRand, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay) {
  ParticleSpawnParam param;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = 0;
  param.speedYRand = 0;
  param.speedXZ = speedXZ;
  param.speedXZRand = 0;
  param.angleY = 0;
  param.angleYRand = 0;
  param.angleXZ = angleXZ;
  param.angleXZRand = angleXZRand;
  param.decayStartY = decayStart;
  param.decayStartYRand = 0;
  param.unk_1c = decay;
  param.unk_1e = 0;
  param.decayStartXZ = decayStart;
  param.decayStartXZRand = 0;
  param.unk_24 = decay;
  param.unk_26 = 0;
  FUN_080155e4(count, pos, &param);
}

// 発生パラメータを決め打ちで組んで count 個ぶん発生させる
void FUN_08015c90(s32 count, u32 kind, u32 flags, u32 animSpeed, WorldPos* pos) {
  ParticleSpawnParam param;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = 0xC;
  param.speedYRand = 0xC;
  param.speedXZ = 4;
  param.speedXZRand = 4;
  param.angleY = 0x3C;
  param.angleYRand = 8;
  param.angleXZ = 0;
  param.angleXZRand = 0xFF;
  param.decayStartY = 0xFF;
  param.decayStartYRand = 0;
  param.unk_1c = 0xFF;
  param.unk_1e = 0;
  param.decayStartXZ = 0xFF;
  param.decayStartXZRand = 0;
  param.unk_24 = 0xFF;
  param.unk_26 = 0;
  FUN_080155e4(count, pos, &param);
}

void FUN_08015ce0(s32 count, u32 kind, u32 flags, u32 animSpeed, u32 angleXZ, u32 angleXZRand, u32 speedXZ, s32 speedXZRand, u32 speedY, s32 speedYRand, WorldPos* pos) {
  ParticleSpawnParam param;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = speedY;
  param.speedYRand = speedYRand;
  param.speedXZ = speedXZ;
  param.speedXZRand = speedXZRand;
  param.angleY = 0x3C;
  param.angleYRand = 8;
  param.angleXZ = angleXZ;
  param.angleXZRand = angleXZRand;
  param.decayStartY = 0xFF;
  param.decayStartYRand = 0;
  param.unk_1c = 0xFF;
  param.unk_1e = 0;
  param.decayStartXZ = 0xFF;
  param.decayStartXZRand = 0;
  param.unk_24 = 0xFF;
  param.unk_26 = 0;
  FUN_080155e4(count, pos, &param);
}

void FUN_08015d3c(WorldPos* pos, u32 kind, u32 flags, u32 animSpeed, u32 speedY, s32 speedYRand, u32 speedXZ, s32 speedXZRand) {
  ParticleSpawnParam param;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = speedY;
  param.speedYRand = speedYRand;
  param.speedXZ = speedXZ;
  param.speedXZRand = speedXZRand;
  param.angleY = 0x3C;
  param.angleYRand = 8;
  param.angleXZ = 0;
  param.angleXZRand = 0xFF;
  param.decayStartY = 0xFF;
  param.decayStartYRand = 0;
  param.unk_1c = 0xFF;
  param.unk_1e = 0;
  param.decayStartXZ = 0xFF;
  param.decayStartXZRand = 0;
  param.unk_24 = 0xFF;
  param.unk_26 = 0;
  FUN_080155e4(1, pos, &param);
}

void UNUSED FUN_08015d9c(WorldPos* pos, u32 kind, u32 flags, u32 animSpeed, u32 speedY, s32 speedYRand, u32 speedXZ, s32 speedXZRand, u32 angleY, u32 angleYRand) {
  ParticleSpawnParam param;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = speedY;
  param.speedYRand = speedYRand;
  param.speedXZ = speedXZ;
  param.speedXZRand = speedXZRand;
  param.angleY = angleY;
  param.angleYRand = angleYRand;
  param.angleXZ = 0;
  param.angleXZRand = 0xFF;
  param.decayStartY = 0xFF;
  param.decayStartYRand = 0;
  param.unk_1c = 0xFF;
  param.unk_1e = 0;
  param.decayStartXZ = 0xFF;
  param.decayStartXZRand = 0;
  param.unk_24 = 0xFF;
  param.unk_26 = 0;
  FUN_080155e4(1, pos, &param);
}

NAKED void UNUSED FUN_08015dfc(void* param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7, u32 param_8) { INCFUNC("asm/func/FUN_08015dfc.inc"); }

NAKED void VM_Sub4383(void) { INCFUNC("asm/func/VM_Sub4383.inc"); }
