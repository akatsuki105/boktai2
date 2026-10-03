#ifndef GUARD_ZOKTAI_PLAYER_H
#define GUARD_ZOKTAI_PLAYER_H

#include "constants/constants.h"
#include "eff_082473e0.h"
#include "entity.h"
#include "gba/gba.h"
#include "hitbox.h"
#include "mover.h"
#include "msgbus.h"
#include "particle.h"
#include "shadow.h"
#include "sprite.h"
#include "struct.h"
#include "types.h"
#include "weapon.h"

struct Player;
struct Input;

typedef u32 PlayerFlag20;  // Player.unk_20

typedef u32 PlayerFlag378;               // Player.flag378
#define FLAG378_WET_DURABILITY (1 << 0)  // 0x00000001, WET_DURABILITY を持った武器を装備している間セットされる
#define FLAG378_WET_ENE_COST (1 << 1)    // 0x00000002, WET_ENE_COST を持った武器を装備している間セットされる
#define FLAG378_BLOOD_SWORD (1 << 2)     // 0x00000004, WET_BLOOD_SWORD を持った武器を装備している間セットされる
#define FLAG378_ASTRO (1 << 3)           // 0x00000008, アストロ武器 を装備している間セットされる
#define FLAG378_WEAPONGUARD (1 << 6)     // 0x00000040, ウェポンガード〃
#define FLAG378_FAIRY (1 << 7)           // 0x00000080, 精霊の衣〃
#define FLAG378_UNK_8 (1 << 8)           // 0x00000100, ???
#define FLAG378_UNK_10 (1 << 10)         // 0x00000400, ???
#define FLAG378_UNK_11 (1 << 11)         // 0x00000800, 立っていると FUN_0807a798 の経験値が1.5倍になる
#define FLAG378_AET_SUNLIGHT (1 << 13)   // 0x00002000, 光のガーブ装備時, ApplyLxModifiers が太陽レベルを2倍にする
#define FLAG378_AET_RES_SOL (1 << 14)    // 0x00004000, メイルオブソル装備時, 立っていると ApplySunlightGain の太陽スタンド加算が2倍になる
#define FLAG378_UNK_19 (1 << 19)         // 0x00080000, 立っていると FUN_0806f900 が HP 割合ぶんの補正を足す
#define FLAG378_UNK_18 (1 << 18)         // 0x00040000, 立っていると FUN_0807e784 が被弾後に FUN_0807e2cc を呼ぶ
#define FLAG378_HEART (1 << 28)          // 0x10000000, ハートの紋章所持
#define FLAG378_JOKER (1 << 29)          // 0x20000000, ジョーカーの紋章所持

// プレイヤーの向き
typedef u8 Facing8;
typedef u16 Facing16;
typedef u32 Facing32;
#define FACE_UP 0          // 上
#define FACE_UP_RIGHT 1    // 右上
#define FACE_RIGHT 2       // 右
#define FACE_DOWN_RIGHT 3  // 右下
#define FACE_DOWN 4        // 下
#define FACE_DOWN_LEFT 5   // 左下
#define FACE_LEFT 6        // 左
#define FACE_UP_LEFT 7     // 左上

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
  Particle base;         // 0x00
  u8 unk_2c[52 - 0x28];  // 0x28
} Particle52;
static_assert(sizeof(Particle52) == 52);

typedef struct {
  ParticleGroup* group1;  // 0x00, PTCL_GROUP_1
  Particle ptcl;          // 0x04
  u8 unk_2c;              // 0x2C
  u8 unk_2d;              // 0x2D
  u8 unk_2e;              // 0x2E, FUN_080613ec
  u8 unk_2f;              // 0x2F, padding?
} PlayerParticleGroup1;
static_assert(sizeof(PlayerParticleGroup1) == 48);

// FUN_08061dd4 で初期化処理がされるが、アクセス方法的に構造体として扱われるっぽい
typedef struct {
  ParticleGroup* group;  // 0x00, PTCL_GROUP_2
  u8 unk_04[4];
  Particle52 ptcls[6];  // FUN_08061dd4 でのループ回数
} PlayerParticleState718;

// FUN_08062278 で初期化処理がされるが、アクセス方法的に構造体として扱われるっぽい
typedef struct {
  ParticleGroup* group;  // 0x00, PTCL_GROUP_2
  u8 unk_04[4];
  Particle52 ptcls[4];  // FUN_08062278 でのループ回数
} PlayerParticleState858;

// 通常プレイでは gPlayerPtr[0] にこの構造体がある
// 通信対戦の相手キャラもこの構造体を使う
// 近接攻撃の衝撃波 (ジャンゴ) / 銃の散弾 (サバタ) に使うスプライト一式
// 根拠: Player_Update_Helper_080639f8 が &meleeShockwave を update に渡して呼ぶ, update は PlayerShockwave_UpdateAnim か PlayerShockwave_UpdateFlash
struct PlayerShockwave;
typedef void (*PlayerShockwaveFunc)(struct PlayerShockwave*);

typedef struct PlayerShockwave {
  AuxSprite sprite;            // 0x00
  AuxSpriteGfx gfx;            // 0x2C, ジャンゴ: SPRITE_MELEE_SHOCKWAVE, サバタ: SPRITE_GUN_SPREAD
  AuxAnimState anim;           // 0x48
  AuxAnimFile* animFile;       // 0x58
  u16 velX;                    // 0x5C, 毎フレーム sprite.pos.x に加算する, 根拠: PlayerShockwave_UpdateAnim
  u16 unk_5e;                  // 0x5E
  u16 velZ;                    // 0x60, 毎フレーム sprite.pos.z に加算する
  u16 unk_62;                  // 0x62
  bool8 finished;              // 0x64, アニメーションが最後まで行くと立つ, 読んだ側は 0 に戻す
  u8 unk_65[3];                // 0x65
  PlayerShockwaveFunc update;  // 0x68, PlayerShockwave_UpdateAnim か PlayerShockwave_UpdateFlash
} PlayerShockwave;
static_assert(sizeof(PlayerShockwave) == 108);

typedef struct Player {
  Entity e;
  u32 unk_18;                  // 0x18, 0 or 1 他にもあるか不明
  u32 unk_1c;                  // 0x1C, ステート?, (0: ??, 1: 通常状態, 2: マップ移動などの操作できない状態?, 3: ???, 4: HP0, 5: ???, ...)
  PlayerFlag20 unk_20;         // 0x20, see PlayerFlag20
  Mover mover;                 // 0x024, 根拠: FUN_08081ab0 と Player_Destroy によるとここから Mover
  MainSpriteGfx spriteSet_68;  // 0x068, 根拠： FUN_08060a24
  MainSprite sprite_88;        // 0x088, 根拠： FUN_08060a24
  AuxSprite sprite_e8;         // 0x0E8, Player_Destroy が AuxSprite_Remove に渡す, pos は 0x104 で FUN_0807a91c が mover.pos / sprite_88.pos と一緒に書く
  u8 unk_114[0x16C - 0x114];
  HitboxData unk_16c;  // 0x16C
  MoverTile tile;      // 0x1BC, mover.tile がここを指す
  u8 unk_1cc[0x220 - 0x1CC];
  u8 unk_220[0x230 - 0x220];  // 0x220, Player_Destroy が FUN_080f8cac に渡す EntityD854Node
  EntityMsgBox msgbox;        // 0x230, FUN_0807ddd4 が EntityMsgBus_Unregister に渡す
  PlayerArmor armor;          // 0x264
  u16 unk_278;
  s16 unk_27a;
  u32 unk_27c;
  magic8_t equippedMagic;              // 0x280, 現在装備している(画面左下に表示されている)魔法のID
  u8 equippedMagicCat;                 // 0x281, 現在装備している魔法のカテゴリ (MC_LUNA, MC_SOL, MC_DARK)
  bool8 isEquippedMagicAvailableForm;  // 0x282, 現在のプレイヤーのフォームで装備している魔法が使用可能かどうか (例えば、赤ジャンゴならエンチャントソルならtrue, チェンジウルフならfalse), フォームと魔法の組み合わせのみで決まる(MPコストや太陽ゲージとかは関係ない), TODO: もっと短い名前を考える
  bool8 isEnchanted;                   // 0x283, エンチャント○○ がアクティブかどうか(プレイヤーが対応する色に光っているかどうか)
  u8 equippedMagicBasicCost;           // 0x284, 装備している魔法の消費MP(マジックローブなどの影響を抜いた元々の消費MP)
  u8 unk_285;                          // 0x285, FUN_0807b5d0 が 1 を、FUN_0807b5f8 が 0 を書く
  u8 unk_286[0x28C - 0x286];
  struct Input* input_28c;  // 0x28C, &gInput[n]
  Keys16 unk_290[10];       // 0x290, 根拠: FUN_0806521c, 多分プレイヤーの操作履歴
  rgb555 pltt_2a4[32];      // 0x2A4, pltt_2a4 から rgb555 が入っているのは確定だが、長さは不明
  u16 animID;               // 0x2E4, 今 sprite_88 で再生しているアニメのID, FUN_08060a24 が前回と同じIDかどうかの判定に使う
  u8 animIDOffset;          // 0x2E6, FUN_08060a24 がアニメIDに足すオフセット
  bool8 xflip;              // 0x2E7, 0 以外なら FUN_08060a24 が sprite_88.flags に SPRFLAG_XFLIP を立てる
  Facing8 facing;           // 0x2E8, see Facing8
  u8 unk_2e9[2];            // 0x2E9
  u8 hitboxTimer;           // 0x2EB, hitbox_2ec を Hitbox_Register し続ける残りフレーム数, FUN_0807e2cc が 6 を入れる
  HitboxData hitbox_2ec;    // 0x2EC
  u8 unk_33c[0x34C - 0x33C];
  AuxAnimFile* anim_34c;  // 0x34C
  AuxAnimFile* anim_350;  // 0x350
  AuxAnimFile* anim_354;  // 0x354
  u8 kind;                // 0x358: see PlayerKind
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
  u8 action;              // 0x37C, いま実行している行動, kind ごとの PlayerFunc テーブル (0x085abcac など) の添字
  u8 state;               // 0x37D, action の中の段階, 行動関数はこれで switch する
  u16 stateTimer;         // 0x37E, Player_SetAction が 0 に戻してから経ったフレーム数, 行動関数が自分で数える
  u8 unk_380[7];
  coffin8_t coffin_387;  // 0x387, MagicSleeping_0806c124
  u8 unk_388[0x38A - 0x388];
  u16 unk_38a;  // 0x38A, 0 のときだけ FUN_0806e404 が専用の効果音を鳴らして 40 を入れる
  u8 unk_38c[0x38E - 0x38C];
  bool8 isSabata;  // 0x38E, 根拠: Player_Init_Helper_08065270
  u8 unk_38f;
  u16 unk_390;
  u16 elevatorID;  // 0x392, 搭乗中のエレベータのID
  u8 unk_394;      // 0x394, FUN_0807a9b8 が 1 を書く
  u8 unk_395;      // 0x395, FUN_0807d118 が 0 を入れる
  u8 unk_396;      // 0x396, FUN_08065dac が 1 を書く
  u8 unk_397;      // 0x397, 0 以外だと FUN_08065dac が何もしない
  Vec3* ptr_398;   // 0x398, FUN_0807a9b8 の第2引数, FUN_08065dac は pos_39c を指させる
  Vec3 pos_39c;    // 0x39C, FUN_08065dac が今踏んでいるタイルの中心を書く
  u8 unk_3a4;      // 0x3A4, 0 以外だと FUN_080672b0 が移動速度を設定しない
  u8 unk_3a5[0x3B0 - 0x3A5];
  Vec3 unk_3b0;  // 0x3B0, FUN_0807a528 が引数の座標をそのまま写す
  u16 unk_3b8;   // 0x3B8, FUN_0807a528 の第3引数
  u16 unk_3ba;   // 0x3BA, FUN_0807b5a8 が 1 を書く
  u8 unk_3bc;    // 0x3BC, FUN_08066d2c が見る
  u8 unk_3bd;    // 0x3BD, FUN_080674dc / FUN_0807b0c0 が見る
  u8 unk_3be[0x3C0 - 0x3BE];
  Vec3 pos_3c0;  // 0x3C0, FUN_08066df8 が mover.pos とカメラの注視点から作って FUN_0823bac8 に渡す
  s16 unk_3c8;   // 0x3C8, FUN_08066df8 が pos_3c0.x を作るとき mover.pos.x に足す
  s16 unk_3ca;   // 0x3CA, 同じく pos_3c0.y
  s16 unk_3cc;   // 0x3CC, 同じく pos_3c0.z
  s16 unk_3ce;   // 0x3CE, FUN_0807856c が ldrsh で読む
  u8 unk_3d0;
  u8 unk_3d1;
  u8 unk_3d2[0x3DC - 0x3D2];
  u16 unk_3dc;  // 0x3DC, FUN_080667b0 が毎回 太陽ゲージ+2 を足し、100 を超えるたびに FUN_08066794 を呼んで 100 引く
  u8 unk_3de[0x3EA - 0x3DE];
  u16 unk_3ea;  // 0x3EA, FUN_0807ad60 が 1 を書く
  u16 unk_3ec;  // 0x3EC, 0 以外だと FUN_0807ad60 が上書きを断る
  u8 unk_3ee[0x3F0 - 0x3EE];
  u8 unk_3f0;  // 0x3F0, FUN_0807bdc8 が unk_4a6 と同じ値を書く
  u8 unk_3f1[0x3F6 - 0x3F1];
  s16 unk_3f6;
  u8 unk_3f8[2];
  u8 magicFired;     // 0x3FA, 魔法の発動フレームに FUN_08064d6c (太陽ゲージ判定) の結果が入る, 1 のときだけ効果が生成され、以降のフレームの演出判定にも使われる
  u8 dynamiteCount;  // 0x3FB, 生存中の Entity080a8ff8 の数, Entity080a8ff8_Init が +1、消滅時に -1, MAGIC_DYNAMITE は 0 でないと再発動できない (FUN_08064db0)
  u8 unk_3fc[2];
  u8 unk_3fe;  // 0x3FE, FUN_0806a050 が見て FUN_08060c40 に渡す番号を選ぶ
  u8 unk_3ff;
  u8 angle_400;     // 0x400, FUN_08063478 が angle_400 - angle_401 + 0x100 を 8bit に丸めて返す
  u8 angle_401;     // 0x401, 同上
  u8 speedPenalty;  // 0x402, 移動速度から引かれる量, FUN_0807a904 が +1 する
  u8 unk_403[0x43A - 0x403];
  u16 unk_43a;     // 0x43A, FUN_0807b580 が 1 を書く
  u16 unk_43c[3];  // 0x43C, 多分状態異常の残り時間
  u16 unk_442;     // 0x442, FUN_0807b2dc が unk_446 が 0 でないときに返す値
  u16 unk_444;
  u16 unk_446;  // 0x446, 0 でなければ unk_442 が有効
  u8 unk_448[0x456 - 0x448];
  s8 unk_456;  // 0x456, FUN_080784fc が unk_290[0] の補正に足す
  u8 unk_457[0x498 - 0x457];
  PlayerFunc fn_498;  // 0x498, FUN_08078d5c
  Vec3 unk_49c;       // 0x49C, FUN_0807c88c が引数の座標をそのまま写す
  u16 unk_4a4;        // 0x4A4, FUN_0807bee0 の第3引数
  u8 unk_4a6;         // 0x4A6, FUN_0807bc14 の第2引数
  u8 unk_4a7;         // 0x4A7, FUN_0807c748 の第3引数
  u8 unk_4a8;
  s8 unk_4a9;  // 0x4A9, FUN_0807b9dc の第2引数
  u8 unk_4aa;  // 0x4AA, FUN_080726b4
  u8 unk_4ab;  // 0x4AB, FUN_08072670 が 1 を書く
  u8 unk_4ac;
  u8 unk_4ad;  // 0x4AD, 0 以外なら FUN_080726ec が unk_4ae を数える
  u8 unk_4ae;  // 0x4AE, 8 フレームごとに FUN_080612d8 を呼ぶためのカウンタ
  u8 unk_4af;
  s32 scriptID_4b0;  // 0x4B0, FUN_08072650
  u8 unk_4b4[0x4c4 - 0x4b4];
  Eff082473e0Emitter unk_4c4;  // 0x4C4
  u8 unk_5fc[0x60C - 0x5FC];
  ParticleShadow shadow;            // 0x60C, 根拠: Player_DestroyEffects が ParticleShadow_Remove に渡す, FUN_081d40b4 がエレベータ搭乗中に flags の bit0 を立てる
  PlayerParticleGroup1 ptcl_64c;    // 0x64C, FUN_08061458
  PlayerParticleGroup1 ptcl_67c;    // 0x67C, FUN_0806161c
  PlayerShockwave meleeShockwave;   // 0x6AC
  PlayerParticleState718 ptcl_718;  // 0x718, 根拠: FUN_08061dd4
  PlayerParticleState858 ptcl_858;  // 0x858, 根拠: FUN_08062278
  Vec3 pos_930;                     // 0x930, FUN_08067f88 が mover.pos をずらして書く
  u8 unk_938[0x94A - 0x938];

  u16 plttID_94a;  // 0x94A, FUN_08063084
  s16 unk_94c;     // 0x94C, FUN_08063084
  u8 unk_94e;      // 0x94E, FUN_08062688
  u8 unk_94f;      // 0x94F
  u8 unk_950;      // 0x950, FUN_08063084
  u8 unk_951;      // 0x951, FUN_0806f780 が unk_a8d + 1 (負なら 0) を入れる
  u8 unk_952[0x95A - 0x952];
  u16 flashPose;   // 0x95A, flashTimer の bit2 が立っている間 Player_ApplyFlashPose が pose の代わりに返す値
  u16 flashTimer;  // 0x95C, Player_ApplyFlashPose が毎フレーム 1 減らす点滅タイマ
  u16 unk_95e;     // 0x95E, FUN_0807b890 / FUN_0807b8a8 が第2引数を書く
  u16 unk_960;     // 0x960, FUN_08074994 が unk_95e と対で書く
  u8 unk_962[0x96C - 0x962];
  u16 unk_96c;  // 0x96C, FUN_0807b8c0 が 0 を書く
  u8 unk_96e[0x994 - 0x96E];
  EntityMsg msg_994;  // 0x994, FUN_0807e278 が組み立てて送る, args は可変長なので後ろの unk_9a0 まで伸びる
  u8 unk_9a0[0x9BC - 0x9A0];
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
  u8 unk_a76[0xA8A - 0xA76];
  u16 unk_a8a;  // 0xA8A, Player_ShowGunSpread が散弾スプライトの rotation に入れる向き
  u8 unk_a8c;   // 0xA8C
  s8 unk_a8d;   // 0xA8D, FUN_0806f780 が Player_CheckMagicEnchant の結果を入れる, 負ならエンチャントなし
  u8 unk_a8e;
  u8 unk_a8f;  // 0xA8F, Entity08080be8 が毎フレーム charge に写す, 威力を 1 + n/2 倍にし、スプライトの絵も選ぶ
  u8 unk_a90[8];
  PlayerFunc attackCB;  // 0xA98, gPlayerAttackUpdates

  // 武器の特殊効果のコールバック関数の配列
  u32 (*weaponExDamageCb[WEAPON_EFFECT_SLOT_COUNT])(struct Player*);  // 0xA9C, プレイヤーの状態を参照する武器の特殊効果コールバック
  u32 (*weaponEffectCb2[WEAPON_EFFECT_SLOT_COUNT])(struct Player*);   // 0xAA8, 状態を参照しない武器の特殊効果コールバック, 防御無視効果と麻痺のハンドラはここ
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
s32 FUN_0806f900(Player* player);
s32 FUN_080d1b04(Player* player);
void Player_ReduceENE_0807aa60(Player* player, s32 amount);

static inline void Player_SetFlag20(Player* p, PlayerFlag20 bit) { p->unk_20 |= bit; }
static inline bool32 Player_TestFlag20(Player* p, PlayerFlag20 bit) { return p->unk_20 & bit; }

static inline void Player_SetFlag378(Player* p, PlayerFlag378 bits) { p->flag378 |= bits; }
static inline bool32 Player_TestFlag378(Player* p, PlayerFlag378 bits) { return p->flag378 & bits; }

#endif  // GUARD_ZOKTAI_PLAYER_H
