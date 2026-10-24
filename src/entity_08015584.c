#include "constants/sprite.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "random.h"
#include "sprite.h"
#include "sprite_animation.h"
#include "trig.h"

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

s32 Entity08015584_Init(Entity08015584* p, u32 _) {
  Vec3 pos;
  s32 i;

  gEntity08015584 = p;

  for (i = 0; i < 2; i++) {
    p->animFiles[i] = GetFile(DIR_ANIMATION, FileID_ARRAY_085aa914[i]);
  }

  pos.x = 0, pos.y = 0, pos.z = 0;

  for (i = 0; i < 32; i++) {
    Entity08015584Elem* elem = &p->elems[i];

    elem->active = FALSE;
    elem->speedY = 0;
    elem->dirX = 0;
    elem->dirY = 0;
    elem->dirZ = 0;
    if (!Video_GetAuxSprite(&elem->gfx, SPRITE_4384)) {
      return -1;
    }
    AuxSprite_Setup(&elem->sprite, &elem->gfx, 0);
    AuxAnim_SetAnim(&elem->anim, p->animFiles[0], 0, 0, 0);
    elem->sprite.priority = 2;
    elem->sprite.pos = pos;
  }

  p->counter = 0;
  return 0;
}

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

// count 個を 256 を等分した向きへ1つずつ発生させる
// 命令数・順序とも一致 (66/66) するが pos / count / step の3つがレジスタ3つ分入れ替わる. 原典は pos を r8, count を r7 に置くが agbcc は逆, 宣言順の入れ替えでは動かない
// angleYRand を angleY より先に代入すると格納順が原典と揃う
NON_MATCH void FUN_08015a90(WorldPos* pos, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay) {
#ifdef NONMATCHING_C
  ParticleSpawnParam param;
  s32 step;
  s32 i;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = 0;
  param.speedYRand = 0;
  param.speedXZ = speedXZ;
  param.speedXZRand = 0;
  step = Div(0x100, count);
  param.angleYRand = 0;
  param.angleY = 0;
  param.decayStartY = decayStart;
  param.decayStartYRand = 0;
  param.unk_1c = decay;
  param.unk_1e = 0;
  param.decayStartXZ = decayStart;
  param.decayStartXZRand = 0;
  param.unk_24 = decay;
  param.unk_26 = 0;
  param.angleXZRand = 10;
  param.angleXZ = 0;

  for (i = count; i > 0; i--) {
    FUN_080155e4(1, pos, &param);
    param.angleXZ += step;
  }
#else
  INCFUNC("asm/func/FUN_08015a90.inc");
#endif
}

// base を中心に mask でマスクした乱数ぶんずらした位置へ count 個発生させる
// 残差1命令 (124/125). base/mask は Vec3* ではなく u16* (原典は ldrh で読む) で, それに直すと 135→124 まで寄る. 残るのは count と &spawnPos のレジスタ入れ替えのみ
NON_MATCH void FUN_08015b18(u16* base, u16* mask, u32 angleXZ, u32 angleXZRand, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay) {
#ifdef NONMATCHING_C
  ParticleSpawnParam param;
  Vec3 spawnPos;
  u16* table = gRandomTable;
  s32 i;

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

  for (i = count; i > 0; i--) {
    spawnPos.x = (_Random(table) & mask[0]) + base[0];
    spawnPos.y = (_Random(table) & mask[1]) + base[1];
    spawnPos.z = (_Random(table) & mask[2]) + base[2];
    FUN_080155e4(1, &spawnPos, &param);
  }
#else
  INCFUNC("asm/func/FUN_08015b18.inc");
#endif
}

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

// ランダムな向きへ speedXZ * 40 ぶんずらした位置に1個発生させる
// 命令数・順序とも一致 (108/108) するが &param (sp のコピー) の作り位置が1つ手前にずれる. 原典は乱数テーブルのプール読みの後に作る
// ずらし量は COS/SIN(angleXZ + 0x80, speedXZ * 40), agbcc は (speedXZ*40)*table を speedXZ*(40*table) に再結合する
NON_MATCH void UNUSED FUN_08015dfc(WorldPos* pos, u32 param_2, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay) {
#ifdef NONMATCHING_C
  ParticleSpawnParam param;
  Vec3 spawnPos;

  param.kind = kind;
  param.flags = flags;
  param.animSpeed = animSpeed;
  param.speedY = 0;
  param.speedYRand = 0;
  param.speedXZ = speedXZ;
  param.speedXZRand = 0;
  param.angleXZ = (u8)Random();
  param.angleXZRand = 0;
  param.angleYRand = 0;
  param.angleY = 0;
  param.decayStartY = decayStart;
  param.decayStartYRand = 0;
  param.unk_1c = decay;
  param.unk_1e = 0;
  param.decayStartXZ = decayStart;
  param.decayStartXZRand = 0;
  param.unk_24 = decay;
  param.unk_26 = 0;

  spawnPos.x = pos->x + COS(param.angleXZ + 0x80, speedXZ * 40);
  spawnPos.y = pos->y;
  spawnPos.z = pos->z + SIN(param.angleXZ + 0x80, speedXZ * 40);
  FUN_080155e4(1, &spawnPos, &param);
#else
  INCFUNC("asm/func/FUN_08015dfc.inc");
#endif
}

NAKED void VM_Sub4383(void) { INCFUNC("asm/func/VM_Sub4383.inc"); }
