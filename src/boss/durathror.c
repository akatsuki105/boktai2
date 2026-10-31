#include "boss.h"
#include "entity.h"
#include "file.h"
#include "global.h"
#include "hitbox.h"
#include "map_inline.h"
#include "msgbus.h"
#include "player.h"
#include "random.h"
#include "shadow.h"
#include "sound.h"
#include "sprite.h"
#include "vec3.h"
#include "vm.h"

// Durathror の 0x648 から6個並ぶ要素, Durathror_DestroyElems が 0x124 刻みで回す
typedef struct {
  u8 unk_0;            // 0x000
  u8 unk_1;            // 0x001
  u8 state;            // 0x002, PTR_ARRAY_085aae30 の添字, 0 なら空き
  bool8 stateEntered;  // 0x003, state を変えるたびに 1 を書く
  u8 unk_4;            // 0x004
  u8 flags;            // 0x005
  s16 damage;          // 0x006, 受けたダメージ, base.hp から引いたら 0 に戻す
  u8 unk_8;            // 0x008
  u8 unk_9;            // 0x009
  u16 unk_a;           // 0x00A
  s16 maxHits;         // 0x00C
  s16 hits;            // 0x00E, 当たるたびに減り, 0 になったら maxHits に戻す
  u32 timer;           // 0x010, state を変えるたびに 0 に戻る
  u32 unk_14;          // 0x014
  u16 unk_18;          // 0x018, 0 でない間 flags の bit0 を立てて減らす
  s16 unk_1a;          // 0x01A, 0 になった瞬間 FUN_080373a4 でパレットを戻す
  Vec3 unk_1c;         // 0x01C, 出現位置, FUN_080375d4 はここを中心に揺らす
  MainSprite sprite;   // 0x024
  HitboxData hitbox;   // 0x084
  HitboxData hurtbox;  // 0x0D4, ハンドラは Durathror_OnElemHurt
} DurathrorElem;
static_assert(sizeof(DurathrorElem) == 292);

// ドゥラスロール, カワイイ
typedef struct Durathror {
  Boss base;                              // 0x000
  u8 unk_158;                             // 0x158, 最後に当てられた向き
  u8 unk_159;                             // 0x159
  u16 unk_15a;                            // 0x15A
  s16 unk_15c;                            // 0x15C, Durathror_OnHurt が受けたダメージを入れる
  s16 unk_15e;                            // 0x15E
  u8 unk_160;                             // 0x160
  u8 unk_161;                             // 0x161
  u8 unk_162;                             // 0x162
  u8 unk_163;                             // 0x163
  u16 unk_164;                            // 0x164
  u16 unk_166;                            // 0x166
  s16 unk_168;                            // 0x168, 受けたダメージで減り, 0 以下になると怯む
  u16 unk_16a;                            // 0x16A
  s16 unk_16c;                            // 0x16C
  s16 unk_16e;                            // 0x16E
  s16 shakeTimer;                         // 0x170, 0 より大きい間スプライトを乱数で揺らす
  u16 unk_172;                            // 0x172, 0 になったら FUN_08038b88 を呼ぶ
  u8 unk_174;                             // 0x174
  u8 unk_175;                             // 0x175
  u8 unk_176;                             // 0x176
  u8 unk_177;                             // 0x177
  Vec3 unk_178;                           // 0x178
  Vec3 unk_180;                           // 0x180
  s16 unk_188;                            // 0x188
  u8 unk_18a;                             // 0x18A
  u8 unk_18b;                             // 0x18B, 0 になったら効果音 0x2CF を鳴らす
  u8 quadrant;                            // 0x18C, Durathror_GetQuadrant で出す部屋の区画
  u8 playerQuadrant;                      // 0x18D, プレイヤーのいる区画
  u16 unk_18e;                            // 0x18E
  u32 unk_190;                            // 0x190
  s16 hitboxPower;                        // 0x194, '.a[0]=60'
  s16 hitboxKnockback;                    // 0x196, '.a[1]=50'
  s16 hitboxUnk44;                        // 0x198, '.a[2]=60'
  s16 unk_19a;                            // 0x19A, '.a[3]=70'
  s16 unk_19c;                            // 0x19C, '.a[4]=50'
  s16 unk_19e;                            // 0x19E, '.a[5]=65'
  s16 unk_1a0;                            // 0x1A0, '.a[6]=70'
  s16 unk_1a2;                            // 0x1A2, '.a[7]=80'
  s16 unk_1a4;                            // 0x1A4
  s16 elemHitboxPower;                    // 0x1A6, '.f[0]=50'
  s16 elemHitboxKnockback;                // 0x1A8, '.f[1]=30'
  s16 elemHitboxUnk44;                    // 0x1AA
  s16 elemMaxHits;                        // 0x1AC, '.f[3]=3'
  s16 hurtboxPower;                       // 0x1AE, '.s[1]=60'
  s16 elemHurtboxPower;                   // 0x1B0, '.f[4]=45'
  s16 elemHurtboxPower2;                  // 0x1B2, '.f[5]=55'
  s16 elemHurtboxPower3;                  // 0x1B4, '.f[6]=55'
  s16 elemHurtboxPower4;                  // 0x1B6, '.f[7]=40'
  s16 elemHurtboxPower5;                  // 0x1B8, '.f[8]=50'
  u8 unk_1ba[0x1BC - 0x1BA];              // 0x1BA
  s32 weaponExp;                          // 0x1BC, '.K'
  HitboxData hitbox;                      // 0x1C0
  HitboxData hurtbox;                     // 0x210, ハンドラは Durathror_OnHurt
  MainSpriteGfx gfx;                      // 0x260, SPRITE_DURATHROR
  MainSprite sprite_280;                  // 0x280
  rgb555 pltt[8][16];                     // 0x2E0
  rgb555 pltt_3e0[8][16];                 // 0x3E0, gObjPlttData の同じ16色を8回写す
  Vec3 unk_4e0;                           // 0x4E0
  MainSprite sprite_4e8;                  // 0x4E8
  rgb555 pltt_548[8][16];                 // 0x548, sprite_4e8 のパレット
  DurathrorElem elems[6];                 // 0x648
  ParticleSpawnParam ptclSpawn;           // 0xD20
  ParticleSpawnParam ptclSpawn2;          // 0xD48
  AuxShadow shadow;                       // 0xD70
  u16 unk_ddc;                            // 0xDDC
  u16 unk_dde;                            // 0xDDE
  u8 unk_de0;                             // 0xDE0
  u8 unk_de1;                             // 0xDE1
  u8 unk_de2;                             // 0xDE2
  u8 unk_de3;                             // 0xDE3
  struct Entity0805d79c* entity0805d79c;  // 0xDE4
  struct Entity080601a8* entity080601a8;  // 0xDE8
  struct Entity0805dcd4* entity0805dcd4;  // 0xDEC
  s32 scriptID;                           // 0xDF0, '.r'
  s32 scriptID2;                          // 0xDF4, '.b', scriptArgs の空いている値を引数にして呼ぶ
  s32 scriptID3;                          // 0xDF8, '.k'
  u32 scriptArgCount;                     // 0xDFC
  u32 scriptArgUsed;                      // 0xE00, scriptArgs のうち使ったもののビット
  u16 scriptArgs[8];                      // 0xE04, '.B'
  Entity5941Node node;                    // 0xE14
} Durathror;
static_assert(sizeof(Durathror) == 3620);

void Durathror_UnregisterHurtbox(Durathror*);
void Durathror_DestroyElems(Durathror*);
void FUN_0803787c(Durathror*, DurathrorElem*, s32);
void FUN_08037888(Durathror*, DurathrorElem*, s32);
void FUN_080378b4(Durathror*, DurathrorElem*, s32);
void FUN_080379a8(Durathror*, DurathrorElem*, s32);
void FUN_08037a48(Durathror*, DurathrorElem*, s32);
void FUN_08037e10(Durathror*, DurathrorElem*, s32);
void FUN_08037ee0(Durathror*, DurathrorElem*, s32);
void FUN_08038080(Durathror*, DurathrorElem*, s32);
void FUN_08038200(Durathror*, DurathrorElem*, s32);
void FUN_080382f0(Durathror*, DurathrorElem*, s32);
void bee_08038358(Durathror*, DurathrorElem*, s32);
void bee_08038514(Durathror*, DurathrorElem*, s32);
void FUN_080385f8(Durathror*, DurathrorElem*, s32);

void (*const PTR_ARRAY_085aae30[13])(Durathror*, DurathrorElem*, s32) = {
    FUN_0803787c,
    FUN_08037888,
    FUN_080378b4,
    FUN_080379a8,
    FUN_08037a48,
    FUN_08037e10,
    FUN_08037ee0,
    FUN_08038080,
    FUN_08038200,
    FUN_080382f0,
    bee_08038358,
    bee_08038514,
    FUN_080385f8,
};  // 0x085AAE30

void FUN_080395fc(Durathror*);
void FUN_08039680(Durathror*);
void FUN_08039704(Durathror*);
void FUN_08039754(Durathror*);
void FUN_080397a4(Durathror*);
void FUN_0803981c(Durathror*);
void FUN_08039878(Durathror*);
void FUN_08039918(Durathror*);
void FUN_08039ac4(Durathror*);

void (*const PTR_ARRAY_085aae64[9])(Durathror*) = {
    FUN_080395fc,
    FUN_08039680,
    FUN_08039704,
    FUN_08039754,
    FUN_080397a4,
    FUN_0803981c,
    FUN_08039878,
    FUN_08039918,
    FUN_08039ac4,
};  // 0x085AAE64

void FUN_08039cd8(Durathror*);
void FUN_08039d38(Durathror*);
void FUN_08039d70(Durathror*);
void FUN_08039dd0(Durathror*);

void (*const PTR_ARRAY_085aae88[4])(Durathror*) = {
    FUN_08039cd8,
    FUN_08039d38,
    FUN_08039d70,
    FUN_08039dd0,
};  // 0x085AAE88

void FUN_08039df4(Durathror*);
void FUN_08039e2c(Durathror*);
void FUN_08039e70(Durathror*);
void FUN_08039eb4(Durathror*);
void FUN_08039f14(Durathror*);
void FUN_08039f74(Durathror*);
void FUN_08039fd8(Durathror*);

void (*const PTR_ARRAY_085aae98[7])(Durathror*) = {
    FUN_08039df4,
    FUN_08039e2c,
    FUN_08039e70,
    FUN_08039eb4,
    FUN_08039f14,
    FUN_08039f74,
    FUN_08039fd8,
};  // 0x085AAE98

void FUN_0803a03c(Durathror*);

void (*const PTR_ARRAY_085aaeb4[1])(Durathror*) = {
    FUN_0803a03c,
};  // 0x085AAEB4

void FUN_0803a058(Durathror*);

void (*const PTR_ARRAY_085aaeb8[1])(Durathror*) = {
    FUN_0803a058,
};  // 0x085AAEB8

void FUN_0803a074(Durathror*);

void (*const PTR_ARRAY_085aaebc[1])(Durathror*) = {
    FUN_0803a074,
};  // 0x085AAEBC

void FUN_0803a090(Durathror*);
void FUN_0803a0cc(Durathror*);
void FUN_0803a0e8(Durathror*);

void (*const PTR_ARRAY_085aaec0[3])(Durathror*) = {
    FUN_0803a090,
    FUN_0803a0cc,
    FUN_0803a0e8,
};  // 0x085AAEC0

void FUN_0803a128(Boss*, s32);
void FUN_0803a180(Boss*, s32);
void FUN_0803a1d8(Boss*, s32);
void FUN_0803a3d0(Boss*, s32);
void FUN_0803a438(Boss*, s32);
void FUN_0803a500(Boss*, s32);
void FUN_0803a668(Boss*, s32);
void FUN_0803a6ec(Boss*, s32);
void FUN_0803a8c0(Boss*, s32);
void durathror_0803aae8(Boss*, s32);
void durathror_0803acbc(Boss*, s32);
void FUN_0803ad74(Boss*, s32);
void FUN_0803adf0(Boss*, s32);
void bee_0803aee4(Boss*, s32);
void FUN_0803af44(Boss*, s32);
void durathror_0803b024(Boss*, s32);
void FUN_0803b1a4(Boss*, s32);
void FUN_0803b1e0(Boss*, s32);
void FUN_0803b278(Boss*, s32);
void FUN_0803b310(Boss*, s32);
void FUN_0803b42c(Boss*, s32);
void FUN_0803b52c(Boss*, s32);
void FUN_0803b628(Boss*, s32);

// clang-format off
void (*const durathror_085aaecc[24])(Boss*, s32) = {
    NULL,
    FUN_0803a128,
    FUN_0803a180,
    FUN_0803a1d8,
    FUN_0803a3d0,
    FUN_0803a438,
    FUN_0803a500,
    FUN_0803a668,
    FUN_0803a6ec,
    FUN_0803a8c0,
    durathror_0803aae8,
    durathror_0803acbc,
    FUN_0803ad74,
    FUN_0803adf0,
    bee_0803aee4,
    FUN_0803af44,
    durathror_0803b024,
    FUN_0803b1a4,
    FUN_0803b1e0,
    FUN_0803b278,
    FUN_0803b310,
    FUN_0803b42c,
    FUN_0803b52c,
    FUN_0803b628,
};  // 0x085AAECC
// clang-format on

void FUN_080390f8(Durathror*);
s32 Map_FindPathNodeBeyond(Vec3* dst, Vec3* pos, s32 pathIdx, u32 minDistSq);
s32 Entity08015584_Spawn(s32 count, WorldPos* pos, ParticleSpawnParam* params);
void FUN_081a4e88(void);
s32 FUN_08060220(struct Entity080601a8* p, u32 angle, s32 speed, s32 velY, s32 lifetime, u32 unk_d, Vec3* pos);
void FUN_0800e594(u32 param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, s32 param_7, s32 param_8, Vec3* pos);
void FUN_08015c28(WorldPos* pos, u32 angleXZ, u32 angleXZRand, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay);
void FUN_0805dd44(struct Entity0805dcd4* p, s32 power, s32 unk_8, Vec3* pos);
s32 DustManager_Emit(s32 count, u32 angle, s32 angleRange, u32 speed, s32 speedRange, u32 delay, u32 power, s32 kind, Vec3* pos);
void LerpVec3(Vec3* dst, Vec3* a, Vec3* b, s32 t, s32 shift);
s32 FUN_0805d80c(struct Entity0805d79c* p, s32 power, u32 angle, s32 speed, Vec3* pos);
struct Entity0805d79c* Entity0805d79c_Create(void);
struct Entity0805dcd4* Entity0805dcd4_Create(void);
struct Entity080601a8* Entity080601a8_Create(s32 plttID, rgb555* pltt);

extern s32 gLightningTimer;
void FUN_0803767c(Durathror* p, DurathrorElem* elem);
void FUN_08015a90(WorldPos* pos, s32 count, u32 kind, u32 flags, u32 animSpeed, u32 speedXZ, u32 decayStart, u32 decay);
void FUN_0803a104(Durathror*);
void FUN_0803b7c4(Durathror*);
void FUN_08039280(Durathror*);

void Durathror_OnHurt(HitboxData* a, HitboxData* b, Durathror* p) {
  Boss* boss = &p->base;

  if (TEST_FLAGS(a->flags, HBFLAG_ANGLE)) {
    p->unk_158 = a->angle;
  } else {
    p->unk_158 = ArcTan2_8(b->center.x - a->center.x, b->center.z - a->center.z);
  }
  Hitbox_ApplyDamage(a, b);
  p->unk_15c = b->damage;
  a->damage += boss->damageBonus;
  Boss_SetWeaponExpMask(boss, a->weakness);
  Boss_SetHurtAttributes(boss, a->attributes);
}

void FUN_08036844(void) {}

void Durathror_UnregisterHurtbox(Durathror* p) { Hitbox_Unregister(&p->hurtbox); }

void FUN_08036858(Durathror* p, Vec3* pos) {
  p->base.mover.pos = *pos;
  Boss_SetSubStates(&p->base, 0, 0, 2);
}

void FUN_08036884(Durathror* p, s32 radius) { p->unk_16e = FixToInt(12, SIN(p->unk_16c * 4) * radius); }

s32 FUN_080368c4(Vec3* pos) {
  if (pos->x < 0x1240) {
    pos->x = 0x1240;
  } else if (pos->x > 0x18C0) {
    pos->x = 0x18C0;
  }
  if (pos->z < 0x240) {
    pos->z = 0x240;
  } else if (pos->z > 0x6C0) {
    pos->z = 0x6C0;
  }
}

s32 FUN_08036908(Vec3* pos) {
  if (pos->x < 0x1280) {
    pos->x = 0x1280;
  } else if (pos->x > 0x1880) {
    pos->x = 0x1880;
  }
  if (pos->z < 0x280) {
    pos->z = 0x280;
  } else if (pos->z > 0x680) {
    pos->z = 0x680;
  }
}

s32 Durathror_GetQuadrant(Vec3* pos) {
  if (pos->z < 0x480) {
    if (pos->x < 0x1580) {
      return 0;
    }
    return 1;
  } else {
    if (pos->x < 0x1580) {
      return 2;
    }
    return 3;
  }
}

// 残差はレジスタの割り当て (27/27), 原典は乱数表と添字のアドレスを r5 / r4 に置き 1 のマスクを最後にまとめて掛ける
NON_MATCH s32 FUN_08036990(s32 dir) {
#ifdef NONMATCHING_C
  u16* table = gRandomTable;
  s32 a = _Random(table) & 1;
  s32 b = _Random(table) & 1;

  return (dir + a + b + 1) & 3;
#else
  INCFUNC("asm/func/FUN_08036990.inc");
#endif
}

void FUN_080369d4(Vec3* pos, s32 corner) {
  u16* table = gRandomTable;
  u16 a = _Random(table);
  u16 b = _Random(table);
  u16 c = _Random(table);
  s32 dx = (a & 1) + (b & 1) + (c & 1);
  u16 d = _Random(table);
  u16 e = _Random(table);
  s32 dz = (d & 1) + (e & 1);

  dx <<= 8;
  dz <<= 8;
  switch (corner) {
    case 0: {
      pos->x = dx + 0x1280;
      pos->z = dz + 0x280;
      break;
    }
    case 1: {
      pos->x = 0x1880 - dx;
      pos->z = dz + 0x280;
      break;
    }
    case 2: {
      pos->x = dx + 0x1280;
      pos->z = 0x680 - dz;
      break;
    }
    case 3: {
      pos->x = 0x1880 - dx;
      pos->z = 0x680 - dz;
      break;
    }
  }
  FUN_08036908(pos);
  pos->y = TileHeightAt(pos);
}

// 残差は座標の乱数ずらしの順番 (107/106), 原典は乱数を先に読んでから座標を 16bit のまま読む
NON_MATCH void FUN_08036b2c(Durathror* p, s32 count, u32 speedXZ) {
#ifdef NONMATCHING_C
  Vec3 pos = p->sprite_280.pos;
  u16* table = gRandomTable;

  pos.x = pos.x - Q8(0.25) + (_Random(table) & 0x7F);
  pos.y = pos.y + Q8(0.5) + (_Random(table) & 0x3F);
  pos.z = pos.z - Q8(0.25) + (_Random(table) & 0x7F);
  FUN_08015c28(&pos, p->unk_158, 16, count, 6, 0x3001, 48, speedXZ, 512, 0);
#else
  INCFUNC("asm/func/FUN_08036b2c.inc");
#endif
}

void FUN_08036c1c(Durathror* p) { FUN_08015a90(&p->sprite_280.pos, 6, 7, 0x4001, 64, 4, 512, 0); }

// 残差は角ごとの定数の持ち方 (183/193), 原典は各 case で 1 と基準座標をレジスタに置き直し, case 1 だけ乱数表を読み直す
NON_MATCH void FUN_08036c4c(Vec3* pos, s32 corner) {
#ifdef NONMATCHING_C
  u16* table = gRandomTable;

  corner = (corner + Mod(_Random(table), 2) + 1) & 3;
  switch (corner) {
    case 0: {
      pos->x = ((_Random(table) & 1) << 8) + 0x1280;
      pos->z = ((_Random(table) & 1) << 8) + 0x280;
      break;
    }
    case 1: {
      pos->x = 0x1880 - ((_Random(table) & 1) << 8);
      pos->z = ((_Random(table) & 1) << 8) + 0x280;
      break;
    }
    case 2: {
      pos->x = ((_Random(table) & 1) << 8) + 0x1280;
      pos->z = 0x680 - ((_Random(table) & 1) << 8);
      break;
    }
    case 3: {
      pos->x = 0x1880 - ((_Random(table) & 1) << 8);
      pos->z = 0x680 - ((_Random(table) & 1) << 8);
      break;
    }
  }
  FUN_08036908(pos);
  pos->y = TileHeightAt(pos);
#else
  INCFUNC("asm/func/FUN_08036c4c.inc");
#endif
}

void FUN_08036df8(Durathror* p) {
  if (p->scriptID) {
    VM_ExecByID(p->scriptID, NULL);
  }
}

s32 Durathror_FindFreeScriptArg(Durathror* p) {
  u32 i;

  for (i = 0; i < p->scriptArgCount; i++) {
    if (!(p->scriptArgUsed & (1 << i))) {
      return i;
    }
  }
  return -1;
}

void FUN_08036e4c(Durathror* p, Vec3* pos) {
  s32 idx = Durathror_FindFreeScriptArg(p);

  if (p->scriptID2 && idx >= 0) {
    u32 argv[4];
    ScriptArgs args;

    argv[0] = p->scriptArgs[idx];
    argv[1] = pos->x;
    argv[2] = pos->y;
    argv[3] = pos->z;
    args.argc = 4, args.argv = argv;
    p->scriptArgUsed |= 1 << idx;
    VM_ExecByID(p->scriptID2, &args);
  }
}

void FUN_08036ec4(Durathror* p) {
  Mover* mover = &p->base.mover;
  Vec3 pos;
  u16* table;
  s32 i;

  pos.x = Q8(18.5), pos.y = Q8(15.625);
  table = gRandomTable;
  for (i = 0; i < 7; i++) {
    pos.y = (_Random(table) & 7) * 256 + Q8(15.625);
    pos.z = Mod(_Random(table), 5) * 256 + Q8(2.5);
    if (abs(mover->pos.x - pos.x) >= Q8(1) || abs(mover->pos.z - pos.z) >= Q8(1)) {
      FUN_0800e594(0, 2, 2, 60, 48, 32, p->unk_19a, p->unk_19c, &pos);
    }
    pos.x += Q8(1);
  }
}

s32 FUN_08036fd8(Mover* mover, s32 kind, s32 damage) {
  Durathror* p = mover->owner;

  if (kind == 0) {
    p->base.hp -= damage;
    if (damage > 0) {
      Vec3 ofs;

      VEC3_SET(ofs, Q8(0.063), 0, Q8(0.063));
      CreateDamageNumber(&p->hurtbox, damage, 0, &mover->pos, &ofs, 1);
    }
    if (p->base.hp <= 0) {
      p->unk_158 = p->base.players[0]->mover.angle;
      SET_FLAGS(p->base.flags, BOSSFLAG_UNK_1);
      Boss_SetSubStates(&p->base, 1, 0, 3);
      Boss_SetState(&p->base, durathror_0803b024, 16);
      return FALSE;
    }
    Boss_SetSubStates(&p->base, 1, 0, 1);
    Boss_SetState(&p->base, bee_0803aee4, 14);
  } else {
    Boss_SetSubStates(&p->base, 1, 0, 2);
    Boss_SetState(&p->base, FUN_0803af44, 15);
    p->unk_158 = mover->angle;
  }
  return TRUE;
}

s32 FUN_0803712c(Vec3* out) {
  Boss* boss = Boss_Get(BOSS_DURATHROR);

  if (boss == NULL || boss->bossID != BOSS_DURATHROR) {
    return FALSE;
  }
  FUN_08015a90(out, 3, 7, 0x2000, 64, 4, 512, 0);
  return TRUE;
}

// '.n' と同じ値の scriptArgs を空きに戻す
void Cmd_FreeDurathrorScriptArg(void) {
  Durathror* p = Boss_Get(BOSS_DURATHROR);

  if (p != NULL && p->base.bossID == BOSS_DURATHROR) {
    u32 arg = VM_GetNamedArgValue('n', 0);
    u32 i;

    for (i = 0; i < p->scriptArgCount; i++) {
      if (p->scriptArgs[i] == arg) {
        p->scriptArgUsed &= ~(1 << i);
      }
    }
  }
}

// 残差は乱数の添字と 3 のマスクの持ち方 (99/101), 原典は乱数表と添字のアドレスと 3 を r6 / sb / r8 に置いて 2 回の呼び出しで使い回す
NON_MATCH void FUN_080371d4(WorldPos* pos) {
#ifdef NONMATCHING_C
  Vec3 size;

  VEC3_SET(size, Q8(0.641), Q8(1), Q8(0.641));
  EmitSmoke(pos, 3, &size, (u8)Random(), (Random() & 3) + 2, (Random() & 3) + 20, 2, 2);
  EmitSmoke(pos, 3, &size, (u8)Random(), (Random() & 3) + 2, (Random() & 3) + 20, 2, 2);
#else
  INCFUNC("asm/func/FUN_080371d4.inc");
#endif
}

void DurathrorElem_SetFlags(DurathrorElem* elem, u32 flags) { elem->flags |= flags; }

u32 DurathrorElem_TestFlags(DurathrorElem* elem, u32 mask) { return elem->flags & mask; }

void DurathrorElem_SetState(DurathrorElem* elem, u32 state) {
  elem->state = state;
  elem->timer = 0;
  elem->stateEntered = TRUE;
}

bool32 DurathrorElem_EnterState(DurathrorElem* elem) {
  if (elem->stateEntered) {
    elem->stateEntered = FALSE;
    return TRUE;
  }
  return FALSE;
}

s32 Durathror_ApplyElemDamage(Durathror* p, DurathrorElem* elem) {
  if (elem->damage > 0) {
    Vec3 ofs;

    Boss_SetHP(&p->base, p->base.hp - elem->damage);
    elem->hits--;
    VEC3_SET(ofs, Q8(0.063), 0, Q8(0.063));
    CreateDamageNumber(&elem->hurtbox, elem->damage, 0, &elem->sprite.pos, &ofs, 1);
    elem->damage = 0;
    elem->unk_18 = 10;
    elem->unk_1a = 10;
    elem->unk_8 = 5;
    elem->sprite.plttID = 0x7F00;
    elem->sprite.pltt = p->pltt_3e0[0];
    PlaySound_0824078c(SE_ENEMY_DAMAGED);
    if ((elem->unk_0 && Boss_GetHPRatio(&p->base) <= 41) || elem->hits <= 0) {
      elem->hits = elem->maxHits;
      return TRUE;
    }
  }
  return FALSE;
}

void FUN_080373a4(Durathror* p, DurathrorElem* elem) {
  MainSprite* sprite = &elem->sprite;

  sprite->plttID = 0x6543;
  sprite->pltt = p->pltt[0];
}

void FUN_080373b8(void) {}

void Durathror_OnElemHurt(HitboxData* a, HitboxData* b, DurathrorElem* elem) {
  Boss* boss = Boss_Get(BOSS_DURATHROR);

  Hitbox_ApplyDamage(a, b);
  elem->damage = b->damage;
  if (TEST_FLAGS(a->attributes, HBATTR_DARK)) {
    FUN_080371d4(&elem->sprite.pos);
  }
  if (boss != NULL) {
    a->damage += boss->damageBonus;
  }
}

void Durathror_InitElemHitbox(Durathror* p, DurathrorElem* elem) {
  HitboxData* hitbox = &elem->hitbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.25), Q8(0.5), Q8(0.25));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &elem->sprite.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_080373b8, elem);
  Hitbox_SetAttack(hitbox, p->elemHitboxPower, p->elemHitboxKnockback, 0, 0, p->elemHitboxUnk44);
}

void Durathror_InitElemHurtbox(Durathror* p, DurathrorElem* elem) {
  HitboxData* hurtbox = &elem->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.5), Q8(0.5), Q8(0.5));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_HIDDEN | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &elem->sprite.pos, 0);
  Hitbox_SetHandler(hurtbox, Durathror_OnElemHurt, elem);
  Hitbox_SetPowerAndAttributes(hurtbox, p->elemHurtboxPower, HBATTR_IMMORTAL, 0);
  Hitbox_Register(hurtbox);
}

void Durathror_InitElem(Durathror* p, DurathrorElem* elem, u32 unk_0, u32 state, s32 maxHits, Vec3* pos) {
  MainSprite* sprite;

  elem->unk_0 = unk_0;
  elem->state = state;
  elem->maxHits = maxHits;
  elem->hits = maxHits;
  elem->unk_14 = 0;
  sprite = &elem->sprite;
  MainSprite_Add(sprite, &p->gfx, 0, SPRFLAG_HIDDEN, 2, PLAYMODE_PAUSE, 60, pos);
  MainSprite_SetAnim(sprite, &p->gfx, 0, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
  Durathror_InitElemHitbox(p, elem);
  Durathror_InitElemHurtbox(p, elem);
}

void Durathror_DestroyElem(DurathrorElem* elem) {
  MainSprite_Remove(&elem->sprite);
  Hitbox_Unregister(&elem->hurtbox);
}

void FUN_080375bc(DurathrorElem* elem) {
  MainSprite_Hide(&elem->sprite);
  DurathrorElem_SetState(elem, 0);
}

// 残差はレジスタの割り当て (75/75), 原典は elem を ip に置き乱数を 1 バイトで読む
NON_MATCH void FUN_080375d4(DurathrorElem* elem) {
#ifdef NONMATCHING_C
  MainSprite* sprite = &elem->sprite;
  Vec3 ofs;

  Vec3_SetPolar(&ofs, Random(), elem->unk_8 * 4);
  Vec3_Sum(&sprite->pos, &ofs, &elem->unk_1c);
#else
  INCFUNC("asm/func/FUN_080375d4.inc");
#endif
}

// 1 回目で打ち切り (147/144), 原典は i と p をスタックに逃がして乱数表と添字のアドレスをレジスタに置く
NON_MATCH void FUN_0803767c(Durathror* p, DurathrorElem* elem) {
#ifdef NONMATCHING_C
  u16* table = gRandomTable;
  s32 i;

  for (i = 0; i < 4; i++) {
    Vec3 pos;
    u32 angle = _Random(table) & 0xFF;
    s32 radius = (_Random(table) & 0x1F) + 32;

    Vec3_SetPolar(&pos, angle & 0xFF, radius);
    Vec3_Add(&pos, &elem->sprite.pos);
    pos.y += 0x80;
    FUN_08060220(p->entity080601a8, _Random(table) & 0xFF, (_Random(table) & 3) + 8, _Random(table) & 3, i * 8 + 30, p->unk_162, &pos);
  }
#else
  INCFUNC("asm/func/FUN_0803767c.inc");
#endif
}

void FUN_080377b8(Durathror* p) {
  DurathrorElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 6; i++, elem++) {
    if (elem->state && !elem->unk_0) {
      switch (elem->state) {
        case 2:
        case 3:
        case 4: {
          DurathrorElem_SetState(elem, 5);
          break;
        }
        case 6: {
          if (elem->unk_4 == 4) {
            DurathrorElem_SetState(elem, 5);
          } else {
            DurathrorElem_SetState(elem, 8);
          }
          break;
        }
        case 7: {
          DurathrorElem_SetState(elem, 8);
          break;
        }
      }
    }
  }
}

void FUN_0803781c(Durathror* p) {
  DurathrorElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 6; i++, elem++) {
    if (elem->state && !elem->unk_0) {
      DurathrorElem_SetState(elem, 12);
    }
  }
}

void FUN_0803784c(Durathror* p) {
  DurathrorElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 6; i++, elem++) {
    if (elem->state && !elem->unk_0) {
      FUN_080375bc(elem);
    }
  }
}

void FUN_0803787c(Durathror* p, DurathrorElem* elem, s32 idx) { DurathrorElem_EnterState(elem); }

void FUN_08037888(Durathror* p, DurathrorElem* elem, s32 idx) {
  DurathrorElem_EnterState(elem);
  DurathrorElem_SetFlags(elem, 1);
  if (elem->unk_a == 0) {
    DurathrorElem_SetState(elem, 2);
  } else {
    elem->unk_a--;
  }
}

void FUN_080378b4(Durathror* p, DurathrorElem* elem, s32 idx) {
  MainSprite* sprite = &elem->sprite;

  if (DurathrorElem_EnterState(elem)) {
    MainSprite_SetAnim(sprite, &p->gfx, 0, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    sprite->pos.y -= 120;
    if (elem->unk_0) {
      p->base.mover.pos = elem->unk_1c;
      if (!elem->unk_1) {
        FUN_08036df8(p);
      }
    }
    PlaySound_0824078c(SE_379);
  }
  if (elem->timer > 14) {
    if (Durathror_ApplyElemDamage(p, elem) && elem->unk_1 == 1) {
      elem->unk_9 = elem->unk_1;
    }
  } else {
    DurathrorElem_SetFlags(elem, 1);
  }
  if (elem->timer < 30) {
    if (elem->timer > 14) {
      sprite->pos.y += 8;
    }
    if ((elem->timer & 3) == 0) {
      Vec3 pos;

      Vec3_CopyOffsetY(&pos, &sprite->pos, 0xA4);
      Entity08015584_Spawn(0, &pos, &p->ptclSpawn);
    }
  }
  if (elem->timer == 15) {
    MainSprite_Show(sprite);
  } else if (elem->timer == 30) {
    MainSprite_SetAnimSpeed(sprite, 96);
  } else if (elem->timer == 45) {
    MainSprite_SetAnimSpeed(sprite, 128);
  }
  if (elem->timer > 95) {
    DurathrorElem_SetState(elem, 3);
  }
}

void FUN_080379a8(Durathror* p, DurathrorElem* elem, s32 idx) {
  Boss* boss = &p->base;
  MainSprite* sprite = &elem->sprite;

  if (DurathrorElem_EnterState(elem)) {
    MainSprite_SetAnim(sprite, &p->gfx, 1, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
  }
  DurathrorElem_SetFlags(elem, 2);
  if (Durathror_ApplyElemDamage(p, elem) && elem->unk_1 == 1) {
    elem->unk_9 = elem->unk_1;
    DurathrorElem_SetState(elem, 10);
    return;
  }
  if (elem->unk_0 && elem->unk_1 == 1) {
    p->sprite_4e8.pos = elem->sprite.pos;
    SET_FLAGS(boss->flags, BOSSFLAG_UNK_17);
  }
  if (elem->timer > 14) {
    if (elem->unk_1 == 1) {
      DurathrorElem_SetState(elem, 6);
    } else {
      DurathrorElem_SetState(elem, 4);
    }
  }
}

void FUN_08037a48(Durathror* p, DurathrorElem* elem, s32 idx) {
  Boss* boss = &p->base;
  MainSprite* sprite = &elem->sprite;

  if (DurathrorElem_EnterState(elem)) {
    MainSprite_SetAnim(sprite, &p->gfx, 1, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    p->unk_ddc = 60;
    p->unk_dde = 0;
    p->unk_de0 = 0;
    p->unk_de1 = (Random() & 15) - 23;
    p->unk_de2 = TRUE;
    p->unk_de3 = 0;
  }
  DurathrorElem_SetFlags(elem, 2);
  if (elem->unk_0 && Boss_GetHPRatio(&p->base) <= 84) {
    DurathrorElem_SetState(elem, 9);
  } else if (Durathror_ApplyElemDamage(p, elem) && elem->unk_0 && Boss_GetHPRatio(boss) <= 84) {
    DurathrorElem_SetState(elem, 9);
  } else if (!p->unk_de2) {
    if ((sprite->animEvents & MAIN_ANIM_EVENT_ADVANCED) && ++p->unk_de0 == 3) {
      Vec3 base;
      u32 angle;
      s32 i;

      p->unk_de1 -= 16;
      Vec3_CopyOffsetY(&base, &sprite->pos, 0x40);
      angle = p->unk_de1;
      for (i = 0; i < 4; i++, angle += 0x40) {
        Vec3 ofs;
        Vec3 pos;

        Vec3_SetPolar(&ofs, angle, 64);
        Vec3_Sum(&pos, &ofs, &base);
        FUN_0805d80c(p->entity0805d79c, p->unk_19e, angle, 20, &pos);
      }
      if (p->unk_ddc == 0 && p->unk_dde == 0) {
        PlaySound_0824078c(SE_378);
      }
      p->unk_de0 = 0;
      p->unk_ddc++;
    }
    if ((p->unk_ddc & 3) == 3) {
      p->unk_de1 = (Random() & 15) - 23;
    }
    if (p->unk_ddc > 7) {
      p->unk_ddc = 0;
      if (++p->unk_dde > 1) {
        p->unk_dde = 0;
        p->unk_de2 = TRUE;
        MainSprite_SetAnim(sprite, &p->gfx, 0, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
      } else {
        MainSprite_SetAnim(sprite, &p->gfx, 44, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
      }
    }
  } else {
    if (p->unk_de3 != 0) {
      if (p->unk_ddc == 16) {
        MainSprite_SetAnimSpeed(sprite, 0x80);
      } else if (p->unk_ddc == 22) {
        MainSprite_SetAnim(sprite, &p->gfx, 1, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
      }
    }
    if (p->unk_de3 <= 1) {
      if (p->unk_ddc == 96) {
        MainSprite_SetAnim(sprite, &p->gfx, 0, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
        MainSprite_SetAnimSpeed(sprite, 0x80);
      } else if (p->unk_ddc == 112) {
        MainSprite_SetAnimSpeed(sprite, 0x40);
      }
    }
    if (++p->unk_ddc > 125) {
      p->unk_ddc = 0;
      p->unk_dde = 0;
      p->unk_de0 = 0;
      p->unk_de1 = (Random() & 15) - 23;
      if (p->unk_de3 > 1) {
        DurathrorElem_SetState(elem, 5);
      } else {
        p->unk_de2 = FALSE;
        MainSprite_SetAnim(sprite, &p->gfx, 44, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
      }
      p->unk_de3++;
    }
  }
}

void FUN_08037e10(Durathror* p, DurathrorElem* elem, s32 idx) {
  MainSprite* sprite = &elem->sprite;

  if (DurathrorElem_EnterState(elem)) {
    MainSprite_SetAnim(sprite, &p->gfx, 0, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    MainSprite_SetAnimSpeed(sprite, 128);
    if (!elem->unk_1) {
      FUN_081a4e88();
    }
  }
  DurathrorElem_SetFlags(elem, 1);
  if (elem->timer == 45) {
    MainSprite_SetAnimSpeed(sprite, 64);
  } else if (elem->timer == 30) {
    MainSprite_SetAnimSpeed(sprite, 96);
  }
  if (elem->timer >= 45 && elem->timer < 60) {
    sprite->pos.y -= 8;
  }
  if (elem->timer > 9) {
    if (elem->timer == 10) {
      PlaySound_0824078c(SE_379);
    }
    if ((elem->timer & 3) == 0) {
      Vec3 pos;

      Vec3_CopyOffsetY(&pos, &sprite->pos, 0x40);
      Entity08015584_Spawn(0, &pos, &p->ptclSpawn);
    }
  }
  if (elem->timer > 59) {
    if (elem->unk_0) {
      p->unk_172 = 60;
    }
    FUN_080375bc(elem);
  }
}

void FUN_08037ee0(Durathror* p, DurathrorElem* elem, s32 idx) {
  Boss* boss = &p->base;
  MainSprite* sprite = &elem->sprite;

  if (DurathrorElem_EnterState(elem)) {
    elem->unk_4 = 0;
    MainSprite_SetAnim(sprite, &p->gfx, 2, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
  }
  DurathrorElem_SetFlags(elem, 2);
  if (elem->unk_0 && Boss_GetHPRatio(boss) <= 41) {
    DurathrorElem_SetState(elem, 10);
  } else if (Durathror_ApplyElemDamage(p, elem)) {
    elem->unk_9 = 1;
    DurathrorElem_SetState(elem, 10);
  } else {
    if (elem->unk_0) {
      if (elem->unk_4 == 4) {
        if ((elem->timer & 15) == 15) {
          elem->unk_8 = 3;
        }
      } else if (elem->unk_4 == 3) {
        if ((elem->timer & 31) == 31) {
          elem->unk_8 = 4;
        }
      } else if (elem->unk_4 == 1) {
        if ((elem->timer & 63) == 31) {
          elem->unk_8 = 3;
        }
      }
      if (elem->unk_4 <= 4) {
        p->sprite_4e8.pos = elem->sprite.pos;
        SET_FLAGS(boss->flags, BOSSFLAG_UNK_17);
      }
    }
    if ((elem->timer & 63) == 63) {
      if (++elem->unk_4 > 5) {
        DurathrorElem_SetState(elem, 7);
      } else {
        s32 anim;

        if (elem->unk_4 == 5) {
          if (elem->unk_0) {
            Vec3* target = p->base.playerPos[0];

            anim = ((Angle_ToDir4(ArcTan2_8(target->x - sprite->pos.x, target->z - sprite->pos.z)) - 1) & 3) + 7;
          } else {
            anim = 45;
          }
        } else {
          anim = elem->unk_4 + 2;
        }
        MainSprite_SetAnim(sprite, &p->gfx, anim, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_KEEP_FRAME);
        if (elem->unk_4 == 5) {
          Vec3 pos;

          Vec3_CopyOffsetY(&pos, &sprite->pos, 0x80);
          DustManager_Emit(8, 0, 0x100, 8, 6, 40, p->elemHitboxPower, 1, &pos);
          PlaySound_0824078c(SE_381);
        }
      }
    }
  }
}

void FUN_08038080(Durathror* p, DurathrorElem* elem, s32 idx) {
  Boss* boss = &p->base;
  MainSprite* sprite = &elem->sprite;
  s32 dir;

  if (elem->unk_0) {
    Vec3* target = p->base.playerPos[0];
    Vec3* pos = &elem->sprite.pos;

    dir = (Angle_ToDir4(ArcTan2_8(target->x - pos->x, target->z - pos->z)) - 1) & 3;
  } else {
    dir = 0;
  }
  if (DurathrorElem_EnterState(elem)) {
    if (elem->unk_0) {
      MainSprite_SetAnim(sprite, &p->gfx, dir + 11, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    } else {
      MainSprite_SetAnim(sprite, &p->gfx, 46, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    }
    if (elem->unk_0) {
      Hitbox_SetPowerAndAttributes(&elem->hurtbox, p->elemHurtboxPower4, HBATTR_IMMORTAL, 0);
    } else {
      Hitbox_SetPowerAndAttributes(&elem->hurtbox, p->elemHurtboxPower5, HBATTR_IMMORTAL, 0);
    }
  }
  DurathrorElem_SetFlags(elem, 2);
  if (elem->unk_0 && Boss_GetHPRatio(boss) <= 41) {
    DurathrorElem_SetState(elem, 12);
  } else {
    s32 damaged = Durathror_ApplyElemDamage(p, elem);

    if (damaged) {
      if (elem->unk_0 && Boss_GetHPRatio(boss) <= 41) {
        DurathrorElem_SetState(elem, 12);
      } else {
        DurathrorElem_SetState(elem, 11);
      }
    } else {
      if (elem->unk_0) {
        MainSprite_SetAnim(sprite, &p->gfx, dir + 11, PLAYMODE_LOOP, MAIN_ANIM_KEEP_FRAME);
      }
      if (elem->unk_0) {
        if (elem->unk_9) {
          if (elem->timer > 179) {
            DurathrorElem_SetState(elem, 8);
            elem->unk_9 = 0;
          }
        } else if (elem->timer > 7) {
          DurathrorElem_SetState(elem, 8);
        }
      } else if (elem->timer > 59) {
        DurathrorElem_SetState(elem, 8);
      }
    }
  }
}

void FUN_08038200(Durathror* p, DurathrorElem* elem, s32 idx) {
  MainSprite* sprite = &elem->sprite;
  s32 dir;

  if (elem->unk_0) {
    Vec3* target = p->base.playerPos[0];
    Vec3* pos = &elem->sprite.pos;

    dir = (Angle_ToDir4(ArcTan2_8(target->x - pos->x, target->z - pos->z)) - 1) & 3;
  } else {
    dir = 0;
  }
  if (DurathrorElem_EnterState(elem)) {
    if (elem->unk_0) {
      MainSprite_SetAnim(sprite, &p->gfx, dir + 15, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    } else {
      MainSprite_SetAnim(sprite, &p->gfx, 47, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_FORCE_POSE);
    }
    if (elem->unk_0) {
      Hitbox_SetPowerAndAttributes(&elem->hurtbox, p->elemHurtboxPower2, HBATTR_IMMORTAL, 0);
    } else {
      Hitbox_SetPowerAndAttributes(&elem->hurtbox, p->elemHurtboxPower3, HBATTR_IMMORTAL, 0);
    }
  }
  DurathrorElem_SetFlags(elem, 2);
  DurathrorElem_SetFlags(elem, 1);
  if (sprite->animEvents & MAIN_ANIM_EVENT_WILL_END) {
    DurathrorElem_SetState(elem, 5);
  }
}

void FUN_080382f0(Durathror* p, DurathrorElem* elem, s32 idx) {
  MainSprite* sprite = &elem->sprite;

  if (DurathrorElem_EnterState(elem)) {
    MainSprite_SetAnim(sprite, &p->gfx, 1, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(SE_382);
  }
  DurathrorElem_SetFlags(elem, 1);
  if (elem->timer > 59) {
    if (!p->unk_162) {
      DurathrorElem_SetState(elem, 5);
    }
  } else if (elem->timer < 30) {
    elem->unk_8 = 8;
  }
}

void bee_08038358(Durathror* p, DurathrorElem* elem, s32 idx) {
  MainSprite* sprite = &elem->sprite;

  if (DurathrorElem_EnterState(elem)) {
    if (elem->unk_4 == 4) {
      FUN_0803767c(p, elem);
    }
    PlaySound_0824078c(SE_382);
  }
  DurathrorElem_SetFlags(elem, 1);
  if (elem->timer > 29) {
    if ((elem->timer & 3) == 3) {
      if (elem->unk_4 > 4) {
        if (elem->unk_9 && !elem->unk_0) {
          Vec3 pos;

          Vec3_CopyOffsetY(&pos, &sprite->pos, 0x80);
          DustManager_Emit(8, 0, 0x100, 8, 6, 40, p->elemHitboxPower, 1, &pos);
          elem->unk_9 = 0;
          PlaySound_0824078c(SE_381);
        }
        if (p->unk_162 == 0) {
          DurathrorElem_SetState(elem, 7);
        }
      } else {
        s32 anim;

        if (++elem->unk_4 == 5) {
          if (elem->unk_0) {
            Vec3* target = p->base.playerPos[0];

            anim = ((Angle_ToDir4(ArcTan2_8(target->x - sprite->pos.x, target->z - sprite->pos.z)) - 1) & 3) + 7;
          } else {
            anim = 45;
          }
          if (elem->unk_9 && !elem->unk_0) {
            Vec3 pos;

            Vec3_CopyOffsetY(&pos, &sprite->pos, 0x80);
            DustManager_Emit(8, 0, 0x100, 8, 6, 40, p->elemHitboxPower, 1, &pos);
            FUN_08036e4c(p, &sprite->pos);
            elem->unk_9 = 0;
            PlaySound_0824078c(SE_BEE_968);
            PlaySound_0824078c(SE_381);
          }
        } else {
          anim = elem->unk_4 + 2;
        }
        MainSprite_SetAnim(sprite, &p->gfx, anim, PLAYMODE_ONCE_AND_STOP, MAIN_ANIM_KEEP_FRAME);
        if (elem->unk_4 == 4) {
          FUN_0803767c(p, elem);
        }
      }
    }
  } else {
    elem->unk_8 = 8;
  }
}

void bee_08038514(Durathror* p, DurathrorElem* elem, s32 idx) {
  MainSprite* sprite = &elem->sprite;
  s32 dir;

  if (elem->unk_0) {
    Vec3* target = p->base.playerPos[0];
    Vec3* pos = &elem->sprite.pos;

    dir = (Angle_ToDir4(ArcTan2_8(target->x - pos->x, target->z - pos->z)) - 1) & 3;
  } else {
    dir = 0;
  }
  if (DurathrorElem_EnterState(elem)) {
    if (elem->unk_0) {
      MainSprite_SetAnim(sprite, &p->gfx, dir + 11, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
      FUN_080377b8(p);
      PlaySound_0824078c(SE_BEE_DEATH);
    } else {
      MainSprite_SetAnim(sprite, &p->gfx, 46, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    }
    FUN_0803767c(p, elem);
    PlaySound_0824078c(SE_382);
  }
  DurathrorElem_SetFlags(elem, 1);
  if (elem->timer <= 30) {
    elem->unk_8 = 8;
  }
  if (!p->unk_162 && elem->timer > 29) {
    DurathrorElem_SetState(elem, 8);
  }
}

// 1 回目で打ち切り (283/282), 原典は elem を低位レジスタに置き向きの計算の 3 を sl に持つ
NON_MATCH void FUN_080385f8(Durathror* p, DurathrorElem* elem, s32 idx) {
#ifdef NONMATCHING_C
  MainSprite* sprite = &elem->sprite;

  if (DurathrorElem_EnterState(elem)) {
    if (elem->unk_0) {
      Vec3* target;
      Vec3* pos;

      Boss_SetAngle(&p->base, p->base.playerAngle[0]);
      target = p->base.playerPos[0];
      pos = &elem->sprite.pos;
      MainSprite_SetAnim(sprite, &p->gfx, ((Angle_ToDir4(ArcTan2_8(target->x - pos->x, target->z - pos->z)) - 1) & 3) + 19, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
      p->unk_162 = 1;
      FUN_0803781c(p);
      p->unk_160 = 1;
      p->unk_161 = 0;
      PlaySound_0824078c(SONG_377);
      PlaySound_0824078c(SE_BEE_DEATH);
    } else {
      FUN_0803767c(p, elem);
    }
    PlaySound_0824078c(SE_382);
  }
  DurathrorElem_SetFlags(elem, 1);
  if (elem->unk_0) {
    if (elem->timer > 63) {
      FUN_080375bc(elem);
      FUN_08036858(p, &elem->sprite.pos);
    } else if (elem->timer == 48) {
      FUN_0803784c(p);
      if (p->scriptID3) {
        VM_ExecByID(p->scriptID3, NULL);
        p->scriptArgUsed = 0;
      }
    }
    if (elem->timer & 1) {
      Vec3 pos;

      Vec3_SetPolar(&pos, Random() & 0xFF, (Random() & 0x1F) + 32);
      Vec3_Add(&pos, &elem->sprite.pos);
      pos.y += 0x80;
      FUN_08060220(p->entity080601a8, Random() & 0xFF, (Random() & 15) + 16, (Random() & 15) + 4, 60, p->unk_162, &pos);
    }
  }
  if (elem->timer <= 29) {
    elem->unk_8 = 8;
  }
#else
  INCFUNC("asm/func/FUN_080385f8.inc");
#endif
}

// 残差はループの誘導変数 (137/139), 原典は &hurtbox.flags を別の歩進ポインタで持ち &hurtbox を毎回作り直す
NON_MATCH void FUN_08038878(Durathror* p) {
#ifdef NONMATCHING_C
  DurathrorElem* elem;
  s32 i;

  if (TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    return;
  }
  p->unk_174 = 0;
  elem = p->elems;
  for (i = 0; i < 6; i++, elem++) {
    if (elem->state) {
      elem->flags = 0;
      PTR_ARRAY_085aae30[elem->state](p, elem, i);
      MainSprite_AdvanceAnim(&elem->sprite, &p->gfx);
      if (elem->unk_18) {
        elem->unk_18--;
        DurathrorElem_SetFlags(elem, 1);
      }
      if (elem->unk_1a > 0 && --elem->unk_1a == 0) {
        FUN_080373a4(p, elem);
      }
      if (DurathrorElem_TestFlags(elem, 1)) {
        SET_FLAGS(elem->hurtbox.flags, HBFLAG_HIDDEN);
        elem->damage = 0;
      } else {
        CLEAR_FLAGS(elem->hurtbox.flags, HBFLAG_HIDDEN);
        Hitbox_SetPos(&elem->hurtbox, &elem->sprite.pos, 0);
      }
      if (DurathrorElem_TestFlags(elem, 2)) {
        Hitbox_SetPos(&elem->hitbox, &elem->sprite.pos, 0);
        Hitbox_Register(&elem->hitbox);
      }
      if (elem->unk_8) {
        FUN_080375d4(elem);
        elem->unk_8--;
      }
      elem->timer++;
      p->unk_174++;
    }
  }
#else
  INCFUNC("asm/func/FUN_08038878.inc");
#endif
}

void FUN_080389b0(Durathror* p) {
  ParticleSpawnParam* param;
  DurathrorElem* elem;
  s32 i;

  param = &p->ptclSpawn;
  param->kind = 7;
  param->flags = 0x3000;
  param->animSpeed = Q6(1);
  param->speedY = 0;
  param->speedYRand = 0;
  param->speedXZ = 3;
  param->speedXZRand = 3;
  param->angleY = 0;
  param->angleYRand = 0;
  param->angleXZ = 0;
  param->angleXZRand = 64;
  param->decayStartY = 512;
  param->decayStartYRand = 0;
  param->unk_1c = 0;
  param->unk_1e = 0;
  param->decayStartXZ = 512;
  param->decayStartXZRand = 0;
  param->unk_24 = 0;
  param->unk_26 = 0;
  param = &p->ptclSpawn2;
  param->kind = 7;
  param->flags = 0x3000;
  param->animSpeed = Q6(1);
  param->speedY = 1;
  param->speedYRand = 1;
  param->speedXZ = 4;
  param->speedXZRand = 1;
  param->angleY = 64;
  param->angleYRand = 0;
  param->angleXZ = 0;
  param->angleXZRand = 64;
  param->decayStartY = 512;
  param->decayStartYRand = 0;
  param->unk_1c = 0;
  param->unk_1e = 0;
  param->decayStartXZ = 512;
  param->decayStartXZRand = 0;
  param->unk_24 = 0;
  param->unk_26 = 0;
  elem = p->elems;
  for (i = 0; i < 6; i++, elem++) {
    Durathror_InitElem(p, elem, 0, 0, p->elemMaxHits, &p->base.mover.pos);
  }
}

void Durathror_DestroyElems(Durathror* p) {
  DurathrorElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 6; i++, elem++) {
    Durathror_DestroyElem(elem);
  }
}

DurathrorElem* Durathror_FindFreeElem(Durathror* p) {
  DurathrorElem* elem = p->elems;
  s32 i;

  for (i = 0; i < 6; i++, elem++) {
    if (elem->state == 0) {
      return elem;
    }
  }
  return NULL;
}

void FUN_08038aac(Durathror* p, Vec3* pos, u32 unk_1, u32 unk_0, u32 unk_a) {
  DurathrorElem* elem = Durathror_FindFreeElem(p);

  if (elem != NULL) {
    DurathrorElem_SetState(elem, 1);
    elem->sprite.pos = *pos;
    elem->unk_1 = unk_1;
    elem->unk_8 = 0;
    elem->unk_0 = unk_0;
    elem->unk_9 = 0;
    elem->unk_a = unk_a;
    elem->hits = elem->maxHits;
    if (elem->unk_0) {
      p->base.mover.pos = *pos;
      if (elem->unk_1 == 0) {
        Hitbox_SetPowerAndAttributes(&elem->hurtbox, p->elemHurtboxPower, HBATTR_IMMORTAL, 0);
      } else {
        Hitbox_SetPowerAndAttributes(&elem->hurtbox, p->elemHurtboxPower2, HBATTR_IMMORTAL, 0);
      }
    } else {
      Hitbox_SetPowerAndAttributes(&elem->hurtbox, p->elemHurtboxPower3, HBATTR_IMMORTAL, 0);
    }
    elem->unk_1c = *pos;
    FUN_080373a4(p, elem);
  }
}

void FUN_08038b54(Durathror* p) {
  Vec3 pos;

  Map_FindPathNodeBeyond(&pos, p->base.playerPos[0], 4, 512);
  FUN_08038aac(p, &pos, 0, 1, 0);
}

// 残差はループ前の 0 の持ち方 (235/235), 原典は unk_18b に書く 0 と i の初期値を別のレジスタで作る
NON_MATCH void FUN_08038b88(Durathror* p) {
#ifdef NONMATCHING_C
  u16* table = gRandomTable;
  s32 delay = _Random(table) & 0x3F;
  Path* path = Map_GetPath(5);
  s32 idx = gFrameCounter + 1 + p->unk_18a + (_Random(table) & 15);
  Vec3 pos;
  s32 i;

  idx = Mod(idx, path->nodeCount);
  Map_GetPathNodePos(&pos, 5, idx);
  pos.y = TileHeightAt(&pos);
  FUN_08038aac(p, &pos, 1, 1, delay);
  p->unk_18b = 0;
  for (i = 0; i < 4; i++) {
    idx += (Random() & 1) + ((gFrameCounter >> i) & 1) + 1;
    idx = Mod(idx, path->nodeCount);
    Map_GetPathNodePos(&pos, 5, idx);
    pos.y = TileHeightAt(&pos);
    FUN_08038aac(p, &pos, 1, 0, delay & 0x3F);
    if (p->unk_18b < delay) {
      p->unk_18b = delay;
    }
    delay += 16;
  }
#else
  INCFUNC("asm/func/FUN_08038b88.inc");
#endif
}

void Durathror_InitHitbox(Durathror* p) {
  HitboxData* hitbox = &p->hitbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.25), Q8(0.504), Q8(0.25));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hitbox, 0, HBFLAG_HITBOX | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hitbox, &p->sprite_280.pos, 0);
  Hitbox_SetHandler(hitbox, FUN_08036844, p);
  Hitbox_SetAttack(hitbox, p->hitboxPower, p->hitboxKnockback, 0, 0, p->hitboxUnk44);
}

void Durathror_InitHurtbox(Durathror* p, u32 power) {
  HitboxData* hurtbox = &p->hurtbox;
  Vec3 halfSize, offset;

  VEC3_SET(halfSize, Q8(0.25), Q8(0.5), Q8(0.25));
  VEC3_SET(offset, 0, Q8(0.5), 0);
  Hitbox_Init(hurtbox, 0, HBFLAG_HURTBOX | HBFLAG_ACTOR | HBFLAG_ANGLE | HBFLAG_UNK_0, 0, 0x10, &halfSize, &offset);
  Hitbox_SetPos(hurtbox, &p->sprite_280.pos, 0);
  Hitbox_SetHandler(hurtbox, Durathror_OnHurt, p);
  Hitbox_SetPowerAndAttributes(hurtbox, power, HBATTR_IMMORTAL | HBATTR_SOL, HBATTR_DARK);
  Hitbox_Register(hurtbox);
}

void FUN_08038f00(Durathror* p) {}

// 残差は gMsgBus の読み直し (191/189), Duneyrr_PollMessages と同じ壁
NON_MATCH void Durathror_PollMessages(Durathror* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  MsgQueue* queue = &boss->msgQueue;
  s32 i;

  for (i = 0; i < queue->count[gMsgBus->bufIdx]; i++) {
    MsgPacket* msg = queue->msgs[gMsgBus->bufIdx][i];

    MsgQueue_BeginWait(queue, msg);
    switch (msg->cmd) {
      case 0: {
        Boss_SetSubStates(boss, 2, 0, 0);
        break;
      }
      case 2: {
        boss->destAngle = ((u8)msg->args[0] + 5) * 32;
        Boss_SetSubStates(boss, 2, 0, 1);
        break;
      }
      case 1: {
        boss->mover.pos.x = msg->args[0];
        boss->mover.pos.y = msg->args[1];
        boss->mover.pos.z = msg->args[2];
        p->sprite_280.pos.x = boss->mover.pos.x;
        p->sprite_280.pos.y = boss->mover.pos.y;
        p->sprite_280.pos.z = boss->mover.pos.z;
        MsgQueue_EndWait(&boss->msgQueue, 1);
        break;
      }
      case 10: {
        boss->destAngle = ((u8)msg->args[0] + 5) * 32;
        Boss_SetSubStates(boss, 2, 0, 2);
        break;
      }
      case 5: {
        boss->destAngle = ((u8)msg->args[0] + 5) * 32;
        Boss_SetSubStates(boss, 2, 0, 3);
        break;
      }
      case 7: {
        Boss_SetSubStates(boss, 2, 0, 4);
        break;
      }
      case 8: {
        Boss_SetSubStates(boss, 2, 0, 5);
        break;
      }
      case 9: {
        Boss_ShowEmote(boss, msg->args[0], 180, 180);
        MsgQueue_EndWait(&boss->msgQueue, 1);
        break;
      }
      case 22: {
        Boss_SetSubStates(boss, 2, 0, 6);
        break;
      }
    }
  }
#else
  INCFUNC("asm/func/Durathror_PollMessages.inc");
#endif
}

// 移動とアニメを進めてスプライトの位置とプレイヤーへの向きを更新する
// 移動とアニメを進め, スプライトの位置とプレイヤーへの向き・距離・区画を更新する
void FUN_080390f8(Durathror* p) {
  Boss* boss = &p->base;
  Mover* mover = &p->base.mover;
  Mover* bossMover;
  Vec3** playerPos;

  Durathror_PollMessages(p);
  Mover_ApplyMove(mover);
  if (p->base.isDemo == 0) {
    FUN_080368c4(&p->base.mover.pos);
  }
  Boss_AdvanceAnim(&p->base, &p->sprite_280, &p->gfx);
  p->sprite_280.pos.x = mover->pos.x;
  p->sprite_280.pos.y = mover->pos.y + p->unk_16e;
  p->sprite_280.pos.z = mover->pos.z;
  if (p->shakeTimer > 0) {
    u16* table;
    Vec3 ofs;

    p->shakeTimer--;
    table = gRandomTable;
    Vec3_SetPolar(&ofs, _Random(table) & 0xFF, _Random(table) & 15);
    Vec3_Add(&p->sprite_280.pos, &ofs);
  }
  FUN_08022e20(boss);
  bossMover = &boss->mover;
  playerPos = boss->playerPos;
  if (*playerPos != NULL) {
    s32 dx = (*playerPos)->x - bossMover->pos.x;
    s32 dz = (*playerPos)->z - bossMover->pos.z;

    boss->playerAngle[0] = ArcTan2_8(dx, dz);
    boss->playerDistSq[0] = dx * dx + dz * dz;
  }
  p->quadrant = Durathror_GetQuadrant(&boss->mover.pos);
  p->playerQuadrant = Durathror_GetQuadrant(*playerPos);
}

// 1 回目で打ち切り (355/354), 原典は千里眼の判定を真偽値に落としてから分岐し p と boss のレジスタが逆
NON_MATCH void FUN_08039280(Durathror* p) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  HitboxData* hitbox;

  FUN_08022ec0(boss);
  FUN_08038878(p);
  if (p->unk_15a != 0) {
    SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
    p->unk_15a--;
  }
  hitbox = &p->hurtbox;
  if (TEST_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX)) {
    Hitbox_SetFlags(hitbox, HBFLAG_HIDDEN);
  } else {
    Hitbox_ClearFlags(hitbox, HBFLAG_HIDDEN);
    Hitbox_SetPos(hitbox, &p->sprite_280.pos, 0);
  }
  hitbox = &p->hitbox;
  if (TEST_FLAGS(boss->flags, BOSSFLAG_NO_HITBOX)) {
    Hitbox_SetFlags(hitbox, HBFLAG_HIDDEN);
  } else {
    Hitbox_ClearFlags(hitbox, HBFLAG_HIDDEN);
    Hitbox_SetPos(hitbox, &p->sprite_280.pos, 0);
    Hitbox_Register(hitbox);
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_HIDDEN)) {
    MainSprite_Hide(&p->sprite_280);
    AuxShadow_Hide(&p->shadow);
  } else {
    MainSprite_Show(&p->sprite_280);
    if (TEST_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW)) {
      AuxShadow_Hide(&p->shadow);
    } else {
      AuxShadow_Show(&p->shadow);
    }
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_17)) {
    bool32 seen;  // 千里眼の実、 Cバットだと、どのつぼみに本物がいるか見える

    if (gGameFlags & FLAG030047A4_LINK) {
      Player* player = gPlayerPtr[0];

      seen = player != NULL && player->goodCondTimer != 0 && player->goodCondID == GOOD_SEE;
    } else {
      seen = gLightningTimer > 0 || gStat->playerKind == PLAYER_BAT || (gGoodCondTimer != 0 && gGoodCondID == GOOD_SEE);
    }
    if (seen) {
      Vec3* target;
      u32 dir;
      u32 pose;

      MainSprite_Show(&p->sprite_4e8);
      target = boss->playerPos[0];
      dir = Angle_ToDir4(ArcTan2_8(target->x - p->sprite_4e8.pos.x, target->z - p->sprite_4e8.pos.z));
      pose = (dir == 0 || dir == 3) ? 0x46 : 0x42;
      if (dir > 1) {
        MainSprite_SetFlags(&p->sprite_4e8, SPRFLAG_XFLIP);
      } else {
        p->sprite_4e8.flags &= ~SPRFLAG_XFLIP;
      }
      MainSprite_SetPose(&p->sprite_4e8, &p->gfx, pose, PLAYMODE_PAUSE);
    } else {
      MainSprite_Hide(&p->sprite_4e8);
    }
  } else {
    MainSprite_Hide(&p->sprite_4e8);
  }
  if (TEST_FLAGS(boss->flags, BOSSFLAG_UNK_18)) {
    p->node.flags &= ~1;
  } else {
    p->node.flags |= 1;
  }
  if (p->unk_15e > 0 && --p->unk_15e == 0) {
    p->sprite_280.plttID = 0x6543;
    p->sprite_280.pltt = p->pltt[0];
  }
  p->unk_190++;
  if (p->unk_160) {
    rgb555* src1 = &gObjPlttData[0x2F6 * 16];
    rgb555* src2 = &gObjPlttData[0x2F7 * 16];

    if ((s8)++p->unk_161 < 0) {
      p->unk_160 = FALSE;
      CpuCopy32(src2, p->pltt[2], 32);
    } else {
      BlendPltt(p->pltt[2], src1, src2, p->unk_161, 7);
    }
  }
  boss->weaponExpMask = 0;
  boss->hurtAttributes = 0;
  boss->frameCount++;
#else
  INCFUNC("asm/func/FUN_08039280.inc");
#endif
}

s32 FUN_080395a4(Durathror* p) {
  if (TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_1)) {
    Boss_SetSubStates(&p->base, 1, 0, 3);
    return TRUE;
  }
  if (TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_0)) {
    Boss_SetSubStates(&p->base, 1, 0, 0);
    return TRUE;
  }
  return FALSE;
}

void FUN_080395fc(Durathror* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss) == TRUE) {
    Boss_RequestState(boss, 1);
  }
  if (!p->unk_174 && p->unk_172 && --p->unk_172 == 0) {
    if (Boss_GetHPRatio(boss) <= 84) {
      p->unk_172 = 10;
      Boss_SetSubState2(boss, 1);
    } else {
      FUN_08038b54(p);
    }
  }
  boss->subStateTimer++;
}

void FUN_08039680(Durathror* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 2);
  }
  if (!p->unk_174 && p->unk_172 && --p->unk_172 == 0) {
    FUN_08038b88(p);
  }
  if (p->unk_18b && --p->unk_18b == 0) {
    PlaySound_082406e0(VO_DURATHROR_SMILE);
  }
  boss->subStateTimer++;
}

void FUN_08039704(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 3);
  }
  if (p->base.subStateTimer > 31) {
    Boss_SetSubState2(&p->base, 3);
  }
  p->base.subStateTimer++;
}

void FUN_08039754(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 4);
  }
  if (p->base.subStateTimer > 59) {
    Boss_SetSubState2(&p->base, 5);
  }
  p->base.subStateTimer++;
}

void FUN_080397a4(Durathror* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 5);
    p->unk_18e = 60;
    if (p->unk_175) {
      p->unk_18e = 90;
    } else {
      p->unk_18e = 90;
    }
  }
  if (boss->subStateDone) {
    Boss_SetSubState2(boss, 5);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_0803981c(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 6);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 6);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_08039878(Durathror* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 7);
  }
  if (boss->subStateTimer > 120) {
    FUN_080369d4(&boss->mover.pos, FUN_08036990(p->playerQuadrant));
    p->unk_188++;
    if ((p->unk_188 & 1) == 0) {
      p->unk_175 = TRUE;
      Boss_SetSubState2(boss, 8);
    } else {
      p->unk_175 = FALSE;
      Boss_SetSubState2(boss, 7);
    }
  } else {
    boss->subStateTimer++;
  }
}

void FUN_08039918(Durathror* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 8);
    p->unk_178 = boss->mover.pos;
    p->unk_180 = boss->mover.pos;
    p->unk_178.y = TileHeightAt(&p->unk_178);
    p->unk_180.y = TileHeightAt(&p->unk_180);
    p->unk_176 = 0;
  }
  if (boss->subStateDone) {
    Boss_SetSubState2(boss, 4);
  } else {
    boss->subStateTimer++;
  }
}

void FUN_08039ac4(Durathror* p) {
  Boss* boss = &p->base;

  if (Boss_EnterSubState(boss)) {
    Boss_RequestState(boss, 8);
    p->unk_178 = boss->mover.pos;
    p->unk_180 = boss->mover.pos;
    p->unk_178.y = TileHeightAt(&p->unk_178);
    FUN_08036c4c(&p->unk_180, p->quadrant);
    p->unk_176 = 0;
    p->unk_177 = 0;
  }
  if (boss->subStateDone) {
    if (++p->unk_177 > 3) {
      Boss_SetSubState2(boss, 4);
    } else {
      Boss_RequestState(boss, 9);
      p->unk_178 = boss->mover.pos;
      p->unk_180 = boss->mover.pos;
      p->unk_178.y = TileHeightAt(&p->unk_178);
      FUN_08036c4c(&p->unk_180, p->quadrant);
      p->unk_176 = 0;
    }
  } else {
    boss->subStateTimer++;
  }
}

void FUN_08039cd8(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 13);
  }
  if (!TEST_FLAGS(p->base.flags, BOSSFLAG_UNK_0)) {
    Boss_SetSubStates(&p->base, 0, 0, 5);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_08039d38(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 14);
  }
  p->base.subStateTimer++;
}

void FUN_08039d70(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 15);
  }
  if (p->base.subStateDone) {
    Boss_SetSubStates(&p->base, 0, 0, 5);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_08039dd0(Durathror* p) {
  Boss_EnterSubState(&p->base);
  p->base.subStateTimer++;
}

void FUN_08039df4(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 17);
  }
  p->base.subStateTimer++;
}

void FUN_08039e2c(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 18);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
  p->base.subStateTimer++;
}

void FUN_08039e70(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 19);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  }
  p->base.subStateTimer++;
}

void FUN_08039eb4(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 20);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 1);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_08039f14(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 21);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 1);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_08039f74(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 22);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 0);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_08039fd8(Durathror* p) {
  if (Boss_EnterSubState(&p->base)) {
    Boss_RequestState(&p->base, 23);
  }
  if (p->base.subStateDone) {
    Boss_SetSubState2(&p->base, 0);
    MsgQueue_EndWait(&p->base.msgQueue, 1);
  } else {
    p->base.subStateTimer++;
  }
}

void FUN_0803a03c(Durathror* p) { PTR_ARRAY_085aae64[p->base.subState2](p); }

void FUN_0803a058(Durathror* p) { PTR_ARRAY_085aae88[p->base.subState2](p); }

void FUN_0803a074(Durathror* p) { PTR_ARRAY_085aae98[p->base.subState2](p); }

void FUN_0803a090(Durathror* p) {
  if (!TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2) && !FUN_080395a4(p)) {
    PTR_ARRAY_085aaeb4[p->base.subState1](p);
  }
}

void FUN_0803a0cc(Durathror* p) { PTR_ARRAY_085aaeb8[p->base.subState1](p); }

void FUN_0803a0e8(Durathror* p) { PTR_ARRAY_085aaebc[p->base.subState1](p); }

void FUN_0803a104(Durathror* p) {
  p->base.unk_9d = 0;
  PTR_ARRAY_085aaec0[p->base.subState0](p);
}

void FUN_0803a128(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite_280, &p->gfx, 0, PLAYMODE_LOOP, 0);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_HIDDEN);
  p->unk_15c = 0;
  boss->stateRequestCallback(boss);
}

void FUN_0803a180(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite_280, &p->gfx, 0, PLAYMODE_LOOP, 0);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_HIDDEN);
  p->unk_15c = 0;
  boss->stateRequestCallback(boss);
}

// 残差は乱数まわりのレジスタ (237/229), FUN_0803b628 と同じ形, 原典は乱数を先に計算して entity080601a8 を最後に読む
NON_MATCH void FUN_0803a1d8(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Durathror* p = (Durathror*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 23, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    p->unk_16c = 0;
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  p->unk_15c = 0;
  if (timer < 32) {
    Vec3_SetPolar(&boss->mover.delta, mover->angle + 0x80, 4);
    p->unk_16c = timer;
    FUN_08036884(p, 128);
  }
  if (timer & 1) {
    Vec3 pos;

    Vec3_SetPolar(&pos, Random() & 0xFF, (Random() & 0x1F) + 32);
    Vec3_Add(&pos, &p->sprite_280.pos);
    pos.y += 0x80;
    FUN_08060220(p->entity080601a8, Random() & 0xFF, (Random() & 15) + 16, (Random() & 15) + 4, 60, p->unk_162, &pos);
  }
  if (boss->stateRequestCallback(boss)) {
    p->unk_16c = 0;
  }
#else
  INCFUNC("asm/func/FUN_0803a1d8.inc");
#endif
}

void FUN_0803a3d0(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 27, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(VO_DURATHROR_YOKUMO);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  p->unk_15c = 0;
  boss->stateRequestCallback(boss);
}

void FUN_0803a438(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  Boss_SetAngle(boss, boss->playerAngle[0]);
  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 27, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  } else {
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 27, PLAYMODE_LOOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss) && timer >= p->unk_18e) {
    boss->subStateDone = TRUE;
  }
}

void FUN_0803a500(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite_280, &p->gfx, 29, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    p->unk_16c = 0;
    PlaySound_0824078c(SE_373);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
  p->unk_15c = 0;
  if (!boss->stateRequestCallback(boss)) {
    if ((timer & 3) == 0) {
      Vec3 pos = p->sprite_280.pos;

      pos.y = TileHeightAt(&pos);
      Entity08015584_Spawn(0, &pos, &p->ptclSpawn);
    }
    if (timer > 40) {
      p->unk_16c--;
      FUN_08036884(p, 512);
      if (p->unk_16c < -6) {
        boss->subStateDone = TRUE;
        PlaySound_0824078c(SE_380);
      }
    }
  }
}

void FUN_0803a668(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite_280, &p->gfx, 29, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    p->unk_16c = -6;
    FUN_08036884(p, 512);
    p->unk_168 = p->unk_166;
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_HIDDEN);
  p->unk_15c = 0;
  boss->stateRequestCallback(boss);
}

void FUN_0803a6ec(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnim(boss, &p->sprite_280, &p->gfx, 29, PLAYMODE_LOOP, MAIN_ANIM_FORCE_POSE);
    PlaySound_0824078c(SE_380);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
  p->unk_15c = 0;
  if (!boss->stateRequestCallback(boss)) {
    if (p->unk_16c <= 3 && (timer & 3) == 0) {
      Vec3 pos = p->sprite_280.pos;

      pos.y = TileHeightAt(&pos);
      Entity08015584_Spawn(0, &pos, &p->ptclSpawn);
    }
    if (timer <= 29) {
      SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
    } else {
      p->unk_16c++;
      FUN_08036884(p, 512);
      if (++p->unk_176 > 31) {
        boss->mover.pos = p->unk_180;
      } else {
        LerpVec3(&boss->mover.pos, &p->unk_178, &p->unk_180, p->unk_176, 5);
      }
      if (p->unk_16c > 3) {
        Boss_SetState(boss, FUN_0803a8c0, 9);
      }
    }
  }
}

void FUN_0803a8c0(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  Boss_SetAngle(boss, boss->playerAngle[0]);
  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->playerAngle[0]);
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 30, PLAYMODE_LOOP, 5, MAIN_ANIM_FORCE_POSE);
  }
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX);
  p->unk_15c = 0;
  if (boss->stateRequestCallback(boss)) {
    return;
  }
  p->unk_16c++;
  if (p->unk_16c == 12) {
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 31, PLAYMODE_LOOP, 5, MAIN_ANIM_FORCE_POSE);
  } else if (p->unk_16c == 20) {
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 30, PLAYMODE_LOOP, 5, MAIN_ANIM_FORCE_POSE);
  } else if (p->unk_16c == 32) {
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 32, PLAYMODE_LOOP, 5, MAIN_ANIM_FORCE_POSE);
  }
  if (p->unk_16c > 31) {
    if (p->sprite_280.animEvents & MAIN_ANIM_EVENT_WILL_END) {
      p->unk_16c = 0;
      if (p->unk_175) {
        Boss_SetState(boss, durathror_0803acbc, 11);
      } else {
        Boss_SetState(boss, durathror_0803aae8, 10);
        PlaySound_082406e0(SE_375);
      }
      FUN_08036c1c(p);
    } else {
      p->unk_16c = 32;
    }
  }
  if (++p->unk_176 > 31) {
    boss->mover.pos = p->unk_180;
  } else {
    LerpVec3(&boss->mover.pos, &p->unk_178, &p->unk_180, p->unk_176, 5);
  }
  FUN_08036884(p, 512);
}

// 残差は乱数で散らす位置の計算のレジスタ (214/209), 原典は乱数表を ip に置き角度に 0x40 を足すのを別にする
NON_MATCH void durathror_0803aae8(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 33, PLAYMODE_LOOP, 5, MAIN_ANIM_FORCE_POSE);
    FUN_08022c24(boss, 10, 10);
    p->unk_164 = 0;
    p->unk_163 = boss->playerAngle[0];
    PlaySound_0824078c(VO_DURATHROR_YAHH_718);
  }
  if (boss->damageCallback(boss) || boss->stateRequestCallback(boss)) {
    return;
  }
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_18);
  if ((timer & 31) == 0 && ++p->unk_164 <= 8) {
    u16* table = gRandomTable;
    Vec3 ofs;
    Vec3 pos;
    s32 radius = _Random(table) & 0xFF;
    s32 angle = boss->players[0]->mover.angle;

    Vec3_SetPolar(&ofs, angle + (_Random(table) & 31) - 16, radius);
    Vec3_Sum(&pos, boss->playerPos[0], &ofs);
    FUN_08036908(&pos);
    FUN_0805dd44(p->entity0805dcd4, p->unk_1a2, 32, &pos);
  }
  if (timer > 255) {
    Boss_SetState(boss, FUN_0803ad74, 12);
  }
#else
  INCFUNC("asm/func/durathror_0803aae8.inc");
#endif
}

void durathror_0803acbc(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 33, PLAYMODE_LOOP, 5, MAIN_ANIM_FORCE_POSE);
    FUN_08022c24(boss, 20, 20);
    FUN_08036ec4(p);
    PlaySound_0824078c(SE_375);
    PlaySound_0824078c(VO_DURATHROR_YAHH_717);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss)) {
    SET_FLAGS(boss->flags, BOSSFLAG_UNK_18);
    if (timer > 89) {
      Boss_SetState(boss, FUN_0803ad74, 12);
    }
  }
}

void FUN_0803ad74(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 34, PLAYMODE_ONCE_AND_STOP, 5, MAIN_ANIM_FORCE_POSE);
  }
  if (!boss->damageCallback(boss) && !boss->stateRequestCallback(boss) && (p->sprite_280.animEvents & MAIN_ANIM_EVENT_WILL_END)) {
    boss->subStateDone = TRUE;
  }
}

void FUN_0803adf0(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 23, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    p->unk_168 = p->unk_166;
    FUN_08036b2c(p, 5, 12);
  }
  p->unk_190 = 0;
  p->unk_15c = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (timer <= 9) {
    Vec3_SetPolar(&boss->mover.delta, p->unk_158, 12);
  }
  if (timer > 19) {
    Boss_SetState(boss, FUN_0803a500, 6);
  }
}

void bee_0803aee4(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 23, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    PlaySound_082406e0(SE_BEE_DEATH);
  }
  p->unk_15c = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_18);
}

void FUN_0803af44(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 23, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    FUN_08036b2c(p, 5, 12);
  }
  p->unk_190 = 0;
  p->unk_15c = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    if (timer <= 9) {
      Vec3_SetPolar(&boss->mover.delta, p->unk_158, 24);
    }
    if (timer > 19) {
      boss->subStateDone = TRUE;
    }
  }
}

void durathror_0803b024(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->playerAngle[0]);
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 40, PLAYMODE_ONCE_AND_STOP, 1, MAIN_ANIM_FORCE_POSE);
    FUN_08022fb8(boss, &p->sprite_280.pos);
    Boss_GiveWeaponExp(boss, p->weaponExp);
    p->unk_16c = 0;
    PlaySound_0824078c(VO_DURATHROR_DEATH);
  }
  p->unk_15c = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_UNK_0 | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (timer < 128) {
    Vec3_SetPolar(&boss->mover.delta, p->unk_158, 2);
    p->unk_16c = timer >> 2;
    FUN_08036884(p, 128);
    if ((timer & 15) == 0) {
      FUN_08036b2c(p, 1, 6);
    }
  } else if (timer == 128) {
    p->unk_16c = 0;
    FUN_08036884(p, 128);
    PlaySound_0824078c(SE_899);
  } else if (timer == 164) {
    PlaySound_0824078c(SE_826);
  }
  if (p->sprite_280.animEvents & MAIN_ANIM_EVENT_WILL_END) {
    FUN_08023024(boss, &p->sprite_280.pos);
  }
}

void FUN_0803b1a4(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
  }
  p->unk_15c = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX | BOSSFLAG_HIDDEN);
  boss->stateRequestCallback(boss);
}

void FUN_0803b1e0(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->destAngle);
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 25, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  }
  p->unk_15c = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  boss->stateRequestCallback(boss);
}

void FUN_0803b278(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_SetAngle(boss, boss->destAngle);
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 25, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  }
  p->unk_15c = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  boss->stateRequestCallback(boss);
}

void FUN_0803b310(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 25, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  } else {
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 25, PLAYMODE_LOOP, 1, MAIN_ANIM_KEEP_FRAME);
  }
  p->unk_15c = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    s8 d = mover->angle - boss->destAngle;

    if (abs(d) <= 3) {
      Boss_SetAngle(boss, boss->destAngle);
      boss->subStateDone = TRUE;
    } else {
      Boss_SetAngle(boss, d < 0 ? mover->angle + 4 : mover->angle - 4);
    }
  }
}

void FUN_0803b42c(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 25, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
    SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
    boss->targetPos = mover->pos;
    PlaySound_0824078c(SE_808);
  }
  p->unk_15c = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    mover->pos = boss->targetPos;
    if (timer > 31) {
      boss->subStateDone = TRUE;
    } else {
      Vec3_SetPolar(&boss->mover.delta, (~timer & 3) * 64, (32 - timer) * 8);
    }
  }
}

void FUN_0803b52c(Boss* boss, s32 timer) {
  Durathror* p = (Durathror*)boss;
  Mover* mover = &boss->mover;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 25, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
    boss->targetPos = mover->pos;
    PlaySound_0824078c(SE_808);
  }
  p->unk_15c = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_SHADOW | BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (!boss->stateRequestCallback(boss)) {
    Vec3_SetPolar(&boss->mover.delta, (timer & 3) * 64, timer * 8);
    mover->pos = boss->targetPos;
    if (timer > 31) {
      boss->subStateDone = TRUE;
    }
  }
}

// 残差は乱数まわりのレジスタ (192/189), 原典は 2 組目の乱数で表を読み直し添字のアドレスを使い回し, entity080601a8 を最後に読む
NON_MATCH void FUN_0803b628(Boss* boss, s32 timer) {
#ifdef NONMATCHING_C
  Durathror* p = (Durathror*)boss;

  if (boss->stateEntered) {
    boss->stateEntered = FALSE;
    Boss_PlayAnimFacing(boss, &p->sprite_280, &p->gfx, 25, PLAYMODE_LOOP, 1, MAIN_ANIM_FORCE_POSE);
  }
  p->unk_15c = 0;
  SET_FLAGS(boss->flags, BOSSFLAG_NO_HURTBOX | BOSSFLAG_NO_HITBOX);
  if (timer > 5) {
    SET_FLAGS(boss->flags, BOSSFLAG_HIDDEN);
  }
  if (boss->stateRequestCallback(boss)) {
    return;
  }
  if (timer & 1) {
    u16* table;
    Vec3 pos;

    table = gRandomTable;
    Vec3_SetPolar(&pos, _Random(table) & 0xFF, (_Random(table) & 0x1F) + 32);
    Vec3_Add(&pos, &p->sprite_280.pos);
    pos.y += 0x80;
    FUN_08060220(p->entity080601a8, Random() & 0xFF, (Random() & 15) + 16, (Random() & 15) + 4, 60, p->unk_162, &pos);
  }
  if (timer > 9) {
    boss->subStateDone = TRUE;
  }
#else
  INCFUNC("asm/func/FUN_0803b628.inc");
#endif
}

void FUN_0803b7c4(Durathror* p) {
  p->base.subStateDone = FALSE;
  if (!TEST_FLAGS(gPlayerStates[0], FLAG03002BC0_UNK_2)) {
    Boss_UpdateState(&p->base);
  }
}

s32 FUN_0803b7ec(Durathror* p) {
  if (p->base.state == 0 || p->base.state > 24) {
    return FALSE;
  } else {
    Boss_SetState(&p->base, durathror_085aaecc[p->base.state], p->base.state);
    return TRUE;
  }
}

s32 Durathror_HandleDamage(Durathror* p) {
  HitboxData* hurtbox = &p->hurtbox;
  s32 damage = p->unk_15c;

  p->unk_15c = 0;
  if (damage > 0) {
    Vec3 ofs;

    p->unk_168 -= p->unk_16a + damage;
    p->base.hp -= damage;
    p->unk_15a = 15;
    p->unk_15e = 10;
    p->sprite_280.plttID = 306;
    p->sprite_280.pltt = p->pltt_3e0[0];
    VEC3_SET(ofs, Q8(0.063), 0, Q8(0.063));
    CreateDamageNumber(hurtbox, damage, 0, &p->base.mover.pos, &ofs, 1);
    if (p->base.hp <= 0) {
      p->base.hp = 0;
      SET_FLAGS(p->base.flags, BOSSFLAG_UNK_1);
      Boss_SetState(&p->base, durathror_0803b024, 16);
      return TRUE;
    }
    p->shakeTimer = 8;
    if (p->base.hurtAttributes & HBATTR_DARK) {
      FUN_080371d4(&p->sprite_280.pos);
    }
    if (p->unk_168 > 0) {
      PlaySound_0824078c(SE_ENEMY_DAMAGED);
      return FALSE;
    }
    PlaySound_0824078c(SE_BEE_DEATH);
    SET_FLAGS(p->base.flags, BOSSFLAG_UNK_0);
    Boss_SetState(&p->base, FUN_0803adf0, 13);
    return TRUE;
  }
  return FALSE;
}

s32 Durathror_Update(Durathror* p) {
  FUN_080390f8(p);
  FUN_0803a104(p);
  FUN_0803b7c4(p);
  FUN_08039280(p);
  return 0;
}

s32 Durathror_Destroy(Durathror* p) {
  AuxShadow_Remove(&p->shadow);
  Durathror_DestroyElems(p);
  Durathror_UnregisterHurtbox(p);
  MainSprite_Remove(&p->sprite_280);
  MainSprite_Remove(&p->sprite_4e8);
  Entity5941_Unregister(&p->node);
  Boss_Destroy(&p->base);
  return 0;
}

// 1 回目で打ち切り (805/805), 原典は &boss->stateRequestCallback もパレット複写の前にスタックへ控える
NON_MATCH s32 Durathror_Init(Durathror* p, u32 id) {
#ifdef NONMATCHING_C
  Boss* boss = &p->base;
  BossID bossID = VM_GetNamedArgValue('t', 2);
  MainSpriteGfxFile* f;
  Vec3 pos;
  u32 angle;
  s32 hp;

  Boss_Register(boss, bossID);
  if (gPlayerPtr[0] != NULL) {
    boss->players[0] = gPlayerPtr[0];
    boss->playerPos[0] = &gPlayerPtr[0]->mover.pos;
  } else {
    boss->players[0] = NULL;
    boss->playerPos[0] = NULL;
  }
  f = GetFile(DIR_MAIN_SPRITE, SPRITE_DURATHROR);
  if (f == NULL) {
    return -1;
  }
  p->gfx = *(MainSpriteGfx*)f;
  OpenMainSpriteFile(&p->gfx, f);
  if (VM_SeekToNamedArg('p')) {
    VEC3_SET(pos, VM_GetValue(), VM_GetValue(), VM_GetValue());
    angle = VM_GetValue();
  } else {
    VEC3_SET(pos, gStat->playerX, gStat->playerY, gStat->playerZ);
    angle = 0x40;
  }
  if (VM_SeekToNamedArg('s')) {
    hp = VM_GetValue();
    p->hurtboxPower = VM_GetValue();
  } else {
    hp = 600;
    p->hurtboxPower = 60;
  }
  if (VM_SeekToNamedArg('a')) {
    p->hitboxPower = VM_GetValue();
    p->hitboxKnockback = VM_GetValue();
    p->hitboxUnk44 = VM_GetValue();
    p->unk_19a = VM_GetValue();
    p->unk_19c = VM_GetValue();
    p->unk_19e = VM_GetValue();
    p->unk_1a0 = VM_GetValue();
    p->unk_1a2 = VM_GetValue();
  } else {
    p->hitboxPower = 60;
    p->hitboxKnockback = 50;
    p->hitboxUnk44 = 60;
    p->unk_19a = 70;
    p->unk_19c = 50;
    p->unk_19e = 65;
    p->unk_1a0 = 70;
    p->unk_1a2 = 80;
  }
  if (VM_SeekToNamedArg('f')) {
    p->elemHitboxPower = VM_GetValue();
    p->elemHitboxKnockback = VM_GetValue();
    p->elemHitboxUnk44 = VM_GetValue();
    p->elemMaxHits = VM_GetValue();
    p->elemHurtboxPower = VM_GetValue();
    p->elemHurtboxPower2 = VM_GetValue();
    p->elemHurtboxPower3 = VM_GetValue();
    p->elemHurtboxPower4 = VM_GetValue();
    p->elemHurtboxPower5 = VM_GetValue();
  } else {
    p->elemHitboxPower = 50;
    p->elemHitboxKnockback = 30;
    p->elemHitboxUnk44 = 30;
    p->elemMaxHits = 3;
    p->elemHurtboxPower = 45;
    p->elemHurtboxPower2 = 55;
    p->elemHurtboxPower3 = 55;
    p->elemHurtboxPower4 = 40;
    p->elemHurtboxPower5 = 50;
  }
  Boss_Init(boss, id, bossID, &pos, angle);
  boss->destAngle = angle;
  boss->isDemo = VM_GetNamedArgValue('i', 0);
  MainSprite_Add(&p->sprite_280, &p->gfx, 0, 0, 2, PLAYMODE_PAUSE, 60, &pos);
  Boss_PlayAnim(boss, &p->sprite_280, &p->gfx, 0, PLAYMODE_LOOP, 0);
  CpuCopy32(&gObjPlttData[0x2F4 * 16], p->pltt, sizeof(p->pltt));
  {
    rgb555* src = &gObjPlttData[0x132 * 16];
    s32 i;

    for (i = 0; i < 8; i++) {
      CpuCopy32(src, p->pltt_3e0[i], sizeof(p->pltt_3e0[i]));
    }
  }
  p->unk_4e0 = pos;
  MainSprite_Add(&p->sprite_4e8, &p->gfx, 0x40, SPRFLAG_HIDDEN | SPRFLAG_BLINK_ODD, 2, PLAYMODE_PAUSE, 60, &pos);
  {
    s32 i;

    for (i = 0; i < 8; i++) {
      s32 j;

      for (j = 0; j < 16; j++) {
        p->pltt_548[i][j] = 0x7FE8;
      }
    }
  }
  p->sprite_4e8.plttID = 0x6583;
  p->sprite_4e8.pltt = p->pltt_548[0];
  if (boss->isDemo) {
    switch (VM_GetNamedArgValue('D', 1)) {
      case 0: {
        Boss_SetSubStates(boss, 2, 0, 0);
        Boss_SetState(boss, FUN_0803b1a4, 17);
        break;
      }
      case 1: {
        Boss_SetSubStates(boss, 2, 0, 1);
        Boss_SetState(boss, FUN_0803b1e0, 18);
        break;
      }
      case 2: {
        Boss_SetSubStates(boss, 2, 0, 2);
        Boss_SetState(boss, FUN_0803b278, 19);
        break;
      }
    }
  } else {
    Boss_SetSubStates(boss, 0, 0, 0);
    Boss_SetState(boss, FUN_0803a128, 1);
    MainSprite_Hide(&p->sprite_280);
    MainSprite_Hide(&p->sprite_4e8);
  }
  boss->damageCallback = (BossCheckFunc)Durathror_HandleDamage;
  boss->stateRequestCallback = (BossCheckFunc)FUN_0803b7ec;
  Boss_InitHP(boss, hp, hp, p->hurtboxPower);
  Durathror_InitHitbox(p);
  Durathror_InitHurtbox(p, p->hurtboxPower);
  if (VM_SeekToNamedArg('c')) {
    u32 scriptA = VM_GetValue();
    u32 scriptB = VM_GetValue();

    FUN_08022fac(boss, scriptA, scriptB);
  } else {
    FUN_08022fac(boss, 0, 0);
  }
  if (VM_SeekToNamedArg('A')) {
    s32 i;

    for (i = 0; i < 4 && VM_GetPC() != NULL; i++) {
      boss->unk_e8[i] = VM_GetValue();
    }
  }
  p->unk_1a4 = 500;
  p->weaponExp = VM_GetNamedArgValue('K', 0);
  boss->damageBonus = VM_GetNamedArgValue('x', 2);
  FUN_08038f00(p);
  if (VM_SeekToNamedArg('j')) {
    p->unk_166 = VM_GetValue();
    p->unk_16a = VM_GetValue();
  } else {
    p->unk_166 = 150;
    p->unk_16a = 50;
  }
  p->unk_168 = p->unk_166;
  if (!boss->isDemo) {
    Path* path = Map_GetPath(5);

    p->unk_18a = Mod(Random(), path->nodeCount);
  } else {
    p->unk_18a = 0;
  }
  p->scriptID = VM_GetNamedArgValue('r', 0);
  p->scriptID2 = VM_GetNamedArgValue('b', 0);
  p->scriptID3 = VM_GetNamedArgValue('k', 0);
  p->unk_172 = 20;
  p->scriptArgUsed = 0;
  p->scriptArgCount = 0;
  if (VM_SeekToNamedArg('B')) {
    s32 i;

    for (i = 0; i < 8 && VM_GetPC() != NULL; i++) {
      p->scriptArgs[i] = VM_GetValue();
      p->scriptArgCount++;
    }
  }
  Entity5941_Register(&p->node, &boss->mover, FUN_08036fd8);
  p->node.flags &= ~1;
  AuxShadow_Init(&p->shadow, &p->sprite_280.pos, 0x40, 0x18, 0x48, 0, 0x200, 1, 5, 1, 0);
  AuxShadow_Hide(&p->shadow);
  FUN_080389b0(p);
  p->entity0805d79c = Entity0805d79c_Create();
  if (p->entity0805d79c == NULL) {
    return -1;
  }
  p->entity080601a8 = Entity080601a8_Create(0x6545, p->pltt[2]);
  if (p->entity080601a8 == NULL) {
    return -1;
  }
  p->entity0805dcd4 = Entity0805dcd4_Create();
  if (p->entity0805dcd4 == NULL) {
    return -1;
  }
  return 0;
#else
  INCFUNC("asm/func/Durathror_Init.inc");
#endif
}

Durathror* Durathror_Create(u32 id) {
  Durathror* p = Boss_Get(BOSS_DURATHROR);
  if (p != NULL) {
    return p;
  }

  p = CreateEntity(ENTITY_UNK_8, sizeof(Durathror));
  if (p != NULL) {
    SetEntityRoutine(p, Durathror_Update, Durathror_Destroy);
    if (Durathror_Init(p, id) < 0) {
      KillEntity((Entity*)p);
      return NULL;
    }
  }
  return p;
}
