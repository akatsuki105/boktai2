#ifndef GUARD_ZOKTAI_PLAYER_H
#define GUARD_ZOKTAI_PLAYER_H

#include "entity.h"
#include "gba/gba.h"
#include "sprite.h"
#include "types.h"
#include "weapon.h"

struct Player;
struct SolarSensorEntity;

typedef void (*PlayerFunc)(struct Player*);

// Player.kind
enum PlayerKind {
  PLAYER_SOLAR_DJANGO,
  PLAYER_DARK_DJANGO,
  PLAYER_UNK_02,
  PLAYER_UNK_03,
  PLAYER_UNK_04,
  PLAYER_SABATA,
};

typedef struct {
  u8 unk_00[52];  // 0x00 (Player: 0x16C)
  u32 unk_34;     // 0x34 (Player: 0x1A0)
  u32 unk_38;     // 0x38 (Player: 0x1A4)
  u16 unk_3c;     // 0x3C (Player: 0x1A8)
  u16 unk_3e;     // 0x3E (Player: 0x1AA)
} Player_16c;     // FUN_080659e8, サイズもまだわからん

typedef struct {
  u16 unk_264;
  u16 unk_266;
  u16 unk_268;
  u16 unk_26a;
  u16 unk_26c;
  u16 unk_26e;
  u16 unk_270;
  u16 unk_272;
  s16 unk_274;
  s16 unk_276;
} Player_264;

typedef struct {
  u8 unk_0[72];  // 0x0
} Player4c4_0c;

typedef struct Player4c4 {
  u8 unk_0;  // 0x000
  u8 unk_1;  // 0x001
  u8 unk_2;  // 0x002
  u8 unk_3;  // 0x003
  u8 unk_4;  // 0x004
  u8 unk_5;  // 0x005
  u8 unk_6[2];
  u32 unk_8;                                                     // 0x008
  Player4c4_0c unk_c[4];                                         // 0x00C
  void (*fn_12c)(struct SolarSensorEntity*, struct Player4c4*);  // 0x12C, SSE_Update(0x0824736c)　で実行
  // 304バイト, これ以上続くのかは不明
} Player4c4;

// 通信対戦の相手キャラもこの構造体を使う
typedef struct Player {
  Entity e;
  u32 unk_18;  // 0x18, 0 or 1 他にもあるか不明
  u32 unk_1c;
  u16 unk_20;
  u16 unk_22;

  // FUN_08081ab0 と Player_Destroy によるとここから Entity2UnkData
  u16 unk_24;  // 0x024
  u16 unk_26;
  u8 unk_28;  // 0x028, gPlayerPtr のインデックス, 0..3
  u8 unk_29;
  u16 unk_2a;
  vec3 pos;  // 0x02C
  u8 unk_32;
  u8 unk_33;
  u8 unk_34;
  bool8 unk_35;
  u16 unk_36;
  u16 unk_38;
  u8 unk_3a[86];
  u32 unk_90;      // 0x090, FUN_08060a24 で bitfield として使われている
  u8 unk_94[284];  // 0x094
  u16 unk_1b0;     // 0x1B0
  u8 unk_1b2[178];
  Player_264 unk_264;
  u16 unk_278;
  s16 unk_27a;
  u32 unk_27c;
  s8 unk_280;  // s8の根拠: FUN_08064d04
  u8 unk_281;
  u8 unk_282;
  u8 unk_283;
  u8 unk_284[12];
  u16 unk_290[10];  // 0x290, 根拠: FUN_0806521c
  u8 unk_2a4[64];
  u16 unk_2e4;              // 0x2E4
  u8 unk_2e6[102];          // 0x2E6
  AnimationFile* anim_34c;  // 0x34c
  AnimationFile* anim_350;  // 0x350
  AnimationFile* anim_354;  // 0x354
  u8 kind;                  // 0x358: see PlayerKind
  u8 unk_359;
  u16 unk_35a;
  u16 unk_35c;
  u16 unk_35e;
  u16 unk_360;
  u16 unk_362;
  u16 hp;      // 0x364
  u16 maxHP;   // 0x366
  u16 ene;     // 0x368
  u16 maxEne;  // 0x36A
  u8 unk_36c[10];
  u16 unk_376;
  u32 unk_378;
  u8 unk_37c;
  u8 unk_37d;
  u16 unk_37e;
  u8 unk_380[14];
  bool8 isSabata;  // 0x38E, 根拠: FUN_08065270
  u8 unk_38f;
  u16 unk_390;
  u16 unk_392;
  u8 unk_394[56];
  u16 unk_3cc;
  u16 unk_3ce;
  u8 unk_3d0;
  u8 unk_3d1;
  u8 unk_3d2[36];
  s16 unk_3f6;
  u8 unk_3f8[68];
  u16 unk_43c[3];
  u8 unk_442[130];
  Player4c4 unk_4c4;  // 0x4C4
  u8 unk_5f4[968];
  u16 unk_9bc;
  u16 pad_9be;
  s32 scriptID_9c0;  // 0x9C0
  s32 scriptID_9c4;  // 0x9C4
  u8 unk_9c8[168];
  Weapon* weapon_a70;
  weapon8_t weaponID_a74;  // 武器ID
  u8 weaponKind_a75;       // 武器種
  u8 unk_a76[34];
  PlayerFunc fn_a98;  // 0xA98, weapon_08064664
  u8 unk_a9c[36];     // 0xA9C

  // 0xAC0, onUpdate で毎フレーム呼ばれる
  // CreatePlayer製:       FUN_08065270　で 0x085abb14 からのどれかが
  // CreateLinkPlayer2P製: FUN_080817ec で FUN_08084330 がセットされる
  PlayerFunc fn_ac0;
} Player;
static_assert(sizeof(Player) == 2756);

// ------------------------------------------------------------------------------------------------------------------------------------

extern Player* gPlayerPtr[4];

Player* CreatePlayer(u32 n, void* _);

Player* CreateLinkPlayer2P(UNK_PTR r0, UNK_PTR r1);     // 0x08084674
Player* CreatePlayer_080d82ec(UNK_PTR r0, UNK_PTR r1);  // 0x080D82EC

#endif  // GUARD_ZOKTAI_PLAYER_H
