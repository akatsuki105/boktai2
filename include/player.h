#ifndef GUARD_ZOKTAI_PLAYER_H
#define GUARD_ZOKTAI_PLAYER_H

#include "animation.h"
#include "constants/constants.h"
#include "entity.h"
#include "gba/gba.h"
#include "hitbox.h"
#include "sprite.h"
#include "struct.h"
#include "types.h"
#include "weapon.h"

struct Player;
struct SolarSensorEntity;

typedef u32 PlayerFlag378;               // Player.flag378
#define FLAG378_WET_DURABILITY (1 << 0)  // 0x00000001, WET_DURABILITY を持った武器を装備している間セットされる
#define FLAG378_WET_ENE_COST (1 << 1)    // 0x00000002, WET_ENE_COST を持った武器を装備している間セットされる
#define FLAG378_BLOOD_SWORD (1 << 2)     // 0x00000004, WET_BLOOD_SWORD を持った武器を装備している間セットされる
#define FLAG378_ASTRO (1 << 3)           // 0x00000008, アストロ武器 を装備している間セットされる
#define FLAG378_WEAPONGUARD (1 << 6)     // 0x00000040, ウェポンガード〃
#define FLAG378_FAIRY (1 << 7)           // 0x00000080, 精霊の衣〃
#define FLAG378_UNK_8 (1 << 8)           // 0x00000100, ???
#define FLAG378_HEART (1 << 28)          // 0x10000000, ハートの紋章所持
#define FLAG378_JOKER (1 << 29)          // 0x20000000, ジョーカーの紋章所持

typedef void (*PlayerFunc)(struct Player*);

// Player.kind, 0x085abb14 (Player.fn_ac0) のインデックスでもある
enum PlayerKind {
  PLAYER_SOLAR_DJANGO,
  PLAYER_DARK_DJANGO,
  PLAYER_BAT,
  PLAYER_MOUSE,
  PLAYER_SLEEPING,
  PLAYER_SABATA,
};

// WeaponKind とは別
enum AttackStyle {
  STYLE_SWORD,
  STYLE_SPEAR,
  STYLE_HAMMER,
  STYLE_GUN,
  STYLE_FIST,
  STYLE_NONE,
};

typedef struct {
  armor16_t id;           // 0x00 (Player: 0x264), ArmorData.id
  u16 defence;            // 0x02 (Player: 0x266), ArmorData.defence
  u16 weight;             // 0x04 (Player: 0x268), ArmorData.weight
  u16 unk_26a;            // 0x06 (Player: 0x26A)
  u16 bonus[STAT_KINDS];  // 0x08 (Player: 0x26C), 武者鎧などのステータスに対する補正値
  s16 hpBonus;            // 0x10 (Player: 0x274), 鎧のHP補正値(赤なら+, 黒なら-)
  s16 eneBonus;           // 0x12 (Player: 0x276), 鎧のEne補正値(赤なら+, 黒なら-)
} PlayerArmor;

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

// 通常プレイでは gPlayerPtr[0] にこの構造体がある
// 通信対戦の相手キャラもこの構造体を使う
typedef struct Player {
  Entity e;
  u32 unk_18;             // 0x18, 0 or 1 他にもあるか不明
  u32 unk_1c;             // 0x1C, ステート?, (0: ??, 1: 通常状態, 2: マップ移動などの操作できない状態?, 3: ???, 4: HP0, 5: ???, ...)
  u32 unk_20;             // 0x20, bitfield
  Entity2UnkData unk_24;  // 0x024, 根拠: FUN_08081ab0 と Player_Destroy によるとここから Entity2UnkData
  SpriteData sprite;      // 0x068, 根拠： FUN_08060a24
  u8 unk_e8[0x16C - 0xE8];
  HitboxData unk_16c;  // 0x16C
  u8 unk_1bc;          // 0x1BC, Entity2UnkData.unk_18 が &Player.unk_1bc
  u8 unk_1bd[167];
  PlayerArmor armor;  // 0x264
  u16 unk_278;
  s16 unk_27a;
  u32 unk_27c;
  magic8_t equippedMagic;              // 0x280, 現在装備している(画面左下に表示されている)魔法のID
  u8 equippedMagicCat;                 // 0x281, 現在装備している魔法のカテゴリ (MC_LUNA, MC_SOL, MC_DARK)
  bool8 isEquippedMagicAvailableForm;  // 0x282, 現在のプレイヤーのフォームで装備している魔法が使用可能かどうか (例えば、赤ジャンゴならエンチャントソルならtrue, チェンジウルフならfalse), フォームと魔法の組み合わせのみで決まる(MPコストや太陽ゲージとかは関係ない), TODO: もっと短い名前を考える
  bool8 isEnchanted;                   // 0x283, エンチャント○○ がアクティブかどうか(プレイヤーが対応する色に光っているかどうか)
  u8 equippedMagicBasicCost;           // 0x284, 装備している魔法の消費MP(マジックローブなどの影響を抜いた元々の消費MP)
  u8 unk_285[0x28C - 0x285];
  void* input_28c;      // 0x28C, 0x030044E0 (&gInput)
  u16 unk_290[10];      // 0x290, 根拠: FUN_0806521c, 多分プレイヤーの操作履歴
  rgb555 pltt_2a4[32];  // 0x2A4, pltt_2a4 から rgb555 が入っているのは確定だが、長さは不明
  u16 unk_2e4;          // 0x2E4
  u8 unk_2e6;           // 0x2E6
  bool8 xflip_2e7;      // 0x2E7, 多分プレイヤーのxflip(0: 右向き, 1: 左向き)
  u8 unk_2e8;           // 0x2E8, FUN_0801fb08, プレイヤーの向きに関連?
  u8 unk_2e9[0x34C - 0x2E9];
  AnimationFile* anim_34c;  // 0x34C
  AnimationFile* anim_350;  // 0x350
  AnimationFile* anim_354;  // 0x354
  u8 kind;                  // 0x358: see PlayerKind
  u8 unk_359;
  u16 unk_35a;
  u16 stats[STAT_KINDS];  // 0x35C, プレイヤーのステータス値 (武者鎧などの装備品の補正値は含まない, タロットカードのドーピングは含む)
  u16 hp;                 // 0x364
  u16 maxHP;              // 0x366
  u16 ene;                // 0x368
  u16 maxEne;             // 0x36A
  u8 unk_36c[10];
  u16 unk_376;
  PlayerFlag378 flag378;  // 0x378, see PlayerFlag378
  u8 unk_37c;             // 0x37C, 0x085abcac の idx
  u8 unk_37d;             // 0x37D, 0x085abcacの関数内でステートとして使用されている
  u16 unk_37e;
  u8 unk_380[7];
  coffin8_t coffin_387;  // 0x387, MagicSleeping_0806c124
  u8 unk_388[6];
  bool8 isSabata;  // 0x38E, 根拠: Player_Init_Helper_08065270
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
  u16 unk_43c[3];  // 0x43C, 多分状態異常の残り時間
  u8 unk_442[86];
  PlayerFunc fn_498;  // 0x498, FUN_08078d5c
  u8 unk_49c[0x4aa - 0x49c];
  u8 unk_4aa;  // 0x4AA, FUN_080726b4
  u8 unk_4ab[0x4b0 - 0x4ab];
  s32 scriptID_4b0;  // 0x4B0, FUN_08072650
  u8 unk_4b4[0x4c4 - 0x4b4];
  Player4c4 unk_4c4;  // 0x4C4
  u8 unk_5f4[0x6AC - 0x5F4];
  u8 unk_6ac[0x704 - 0x6AC];  // 0x6AC
  AnimationFile* anim_704;    // 0x704
  u8 unk_708[8];
  u8 unk_710;  // 0x710, Player_Init_Anim_08061bac
  u8 unk_711[3];
  void* fn_714;  // 0x714, Player_Init_Anim_08061bac シグネチャ不明, FUN_08061680 or FUN_080617bc
  u8 unk_718[0x94A - 0x718];
  u16 plttID_94a;  // 0x94A, FUN_08063084
  s16 unk_94c;     // 0x94C, FUN_08063084
  u8 unk_94e;      // 0x94E, FUN_08062688
  u8 unk_94f;      // 0x94F
  u8 unk_950;      // 0x950, FUN_08063084
  u8 unk_951[0x9bc - 0x951];
  u16 unk_9bc;  // 0x9BC
  u16 pad_9be;
  s32 scriptID_9c0;  // 0x9C0
  s32 scriptID_9c4;  // 0x9C4
  u8 unk_9c8[0xA10 - 0x9C8];
  HitboxData unk_a10;  // 0xA10, 根拠: 0x08064644
  u8 unk_a60[0xA70 - 0xA60];
  Weapon* weapon_a70;
  weapon8_t weaponID_a74;  // 武器ID
  u8 weaponKind_a75;       // 0xA75, 武器種
  u8 unk_a76[34];
  PlayerFunc attackCB;  // 0xA98, gPlayerAttackUpdates

  // 武器の特殊効果のコールバック関数の配列
  u32 (*weaponExDamageCb[WEAPON_EFFECT_SLOT_COUNT])(struct Player*);  // 0xA9C, プレイヤーの状態を参照する武器の特殊効果コールバック
  u32 (*weaponEffectCb2[WEAPON_EFFECT_SLOT_COUNT])(void);             // 0xAA8, 状態を参照しない武器の特殊効果コールバック, 防御無視効果と麻痺のハンドラはここ
  void* weaponEffectCb3[WEAPON_EFFECT_SLOT_COUNT];                    // 0xAB4,　敵の状態を参照する武器の特殊効果コールバック, xx特効系のハンドラはここ, シグネチャはまだ不明

  // 0xAC0, onUpdate (Player_Update) で毎フレーム呼ばれる
  // CreatePlayer製:       FUN_08065270　で 0x085abb14 の関数テーブル or FUN_08079f1c
  // CreateLinkPlayer2P製: FUN_080817ec で FUN_08084330 がセットされる
  PlayerFunc fn_ac0;
} Player;
static_assert(sizeof(Player) == 2756);

// ------------------------------------------------------------------------------------------------------------------------------------

extern Player* gPlayerPtr[4];
extern const PlayerFunc gPlayerAttackUpdates[5];  // 0: 剣, 1: 槍, 2: ハンマー, 3: 拳, 4: 銃

Player* CreatePlayer(u32 n, void* _);

Player* CreateLinkPlayer2P(unknown* r0, unknown* r1);     // 0x08084674
Player* CreatePlayer_080d82ec(unknown* r0, unknown* r1);  // 0x080D82EC

#endif  // GUARD_ZOKTAI_PLAYER_H
