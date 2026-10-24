#ifndef GUARD_ZOKTAI_PLAYER_H
#define GUARD_ZOKTAI_PLAYER_H

#include "constants/constants.h"
#include "eff_082473e0.h"
#include "enemy_target.h"
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

typedef u32 PlayerFlag20;            // Player.flag20
#define PFLAG20_UNK_0 (1 << 0)       // 0x00000001, Player_BeginAction が毎回これだけ立てた状態から始める
#define PFLAG20_UNK_1 (1 << 1)       // 0x00000002
#define PFLAG20_UNK_3 (1 << 3)       // 0x00000008
#define PFLAG20_SUNBATHING (1 << 4)  // 0x00000010, プレイヤーに日光が当たっているか
#define PFLAG20_UNK_5 (1 << 5)       // 0x00000020
#define PFLAG20_UNK_7 (1 << 7)       // 0x00000080
#define PFLAG20_UNK_8 (1 << 8)       // 0x00000100
#define PFLAG20_UNK_9 (1 << 9)       // 0x00000200, unk_4c4 (kind 1) がダメージを与えている間 Player_UpdateDamage が立てる
#define PFLAG20_UNK_12 (1 << 12)     // 0x00001000
#define PFLAG20_UNK_14 (1 << 14)     // 0x00004000, Player_UpdateDjango が先頭で毎フレーム立てる
#define PFLAG20_UNK_15 (1 << 15)     // 0x00008000, 立っていると Player_SetHitDir が被弾方向を facing ではなく unk_3e8 に書く
#define PFLAG20_SNEAKING (1 << 16)   // 0x00010000, スニーク状態(スカルスーツ装備, Cマウス形態 など), 処理的には、 "敵の視界が半分になる"
#define PFLAG20_UNK_17 (1 << 17)     // 0x00020000, 棺桶が COFFIN_SILVER のとき寝ている間だけ立つ (多分、敵から完全に見つからなくなる状態)
#define PFLAG20_UNK_18 (1 << 18)     // 0x00040000, Player_UpdateDjango が unk_1c が 2 か 4 のとき立てる
#define PFLAG20_UNK_19 (1 << 19)     // 0x00080000

// Player.flag35a, Player_BeginAction が毎フレーム 0 に戻し、行動関数が立てたものを FUN_08078bc0 がその場で反映する
typedef u16 PlayerFlag35A;
#define PFLAG35A_HIDE_SPRITE (1 << 0)     // 0x0001, sprite_88 に SPRFLAG_HIDDEN を立てる
#define PFLAG35A_BLINK (1 << 1)           // 0x0002, sprite_88 に SPRFLAG_BLINK_ODD を立てる
#define PFLAG35A_HIDE_SHADOW (1 << 2)     // 0x0004, 影を ParticleShadow_Hide する
#define PFLAG35A_NO_HITBOX (1 << 3)       // 0x0008, hurtbox に HBFLAG_UNK_2 を立てて Hitbox_SetPos を飛ばす
#define PFLAG35A_NO_TILE (1 << 4)         // 0x0010, mover.tile を NULL にして Map_InitMoverTile を飛ばす
#define PFLAG35A_UNK_5 (1 << 5)           // 0x0020, FUN_08082464 が立てるが読み手は未発見
#define PFLAG35A_SHOW_SPRITE_E8 (1 << 6)  // 0x0040, 立てたときだけ sprite_e8 の SPRFLAG_HIDDEN を落とす (既定は隠す)
#define PFLAG35A_UNK_7 (1 << 7)           // 0x0080, サバタのみ, 立てたときだけ sprite_9c8 の SPRFLAG_HIDDEN を落とす (既定は隠す)

typedef u32 EquipBuffs;                  // Player.equipBuffs
#define EBUFF_WET_DURABILITY (1 << 0)    // 0x00000001, WET_DURABILITY を持った武器を装備している間セットされる
#define EBUFF_WET_ENE_COST (1 << 1)      // 0x00000002, WET_ENE_COST を持った武器を装備している間セットされる
#define EBUFF_BLOOD_SWORD (1 << 2)       // 0x00000004, WET_BLOOD_SWORD を持った武器を装備している間セットされる
#define EBUFF_ASTRO (1 << 3)             // 0x00000008, アストロ武器 を装備している間セットされる
#define EBUFF_SOLAR_WIND (1 << 4)        // 0x00000010, ブリガンダイン (AET_SOLAR_WIND)
#define EBUFF_IMMUNEPOISON (1 << 5)      // 0x00000020, ポイズンガード (AET_IMMUNE_POISON)
#define EBUFF_WEAPONGUARD (1 << 6)       // 0x00000040, ウェポンガード〃
#define EBUFF_FAIRY (1 << 7)             // 0x00000080, 精霊の衣〃
#define EBUFF_MAGICROBE (1 << 8)         // 0x00000100, マジックローブ (魔法のMP消費を軽減)
#define EBUFF_SKULLSUIT (1 << 9)         // 0x00000200, スカルスーツ (AET_SKULL_SUIT)
#define EBUFF_ALLNIGHT (1 << 10)         // 0x00000400, 闇のガーブ (AET_ALLNIGHT)
#define EBUFF_TRAININGGEAR (1 << 11)     // 0x00000800, トラックスーツ (AET_EXP_BOOST, 経験値1.5倍)
#define EBUFF_EARTHLYROBE (1 << 12)      // 0x00001000, 大地の衣 (AET_EARTHLY_ROBE)
#define EBUFF_AET_SUNLIGHT (1 << 13)     // 0x00002000, 光のガーブ装備時, ApplyLxModifiers が太陽レベルを2倍にする
#define EBUFF_AET_RES_SOL (1 << 14)      // 0x00004000, メイルオブソル装備時, 立っていると ApplySunlightGain の太陽スタンド加算が2倍になる
#define EBUFF_AET_NORMAL_DROP (1 << 15)  // 0x00008000, 盗人の服
#define EBUFF_AET_RARE_DROP (1 << 16)    // 0x00010000, 狩人の服
#define EBUFF_PARADE (1 << 17)           // 0x00020000, パレードアーマー
#define EBUFF_BLACKARMOR (1 << 19)       // 0x00080000, 黒の鎧
#define EBUFF_SPIKE (1 << 18)            // 0x00040000, スパイクメイル
#define EBUFF_MEGAPOWER (1 << 20)        // 0x00100000, ロックパワー
#define EBUFF_GUTSPOWER (1 << 21)        // 0x00200000, ガッツパワー
#define EBUFF_PROTOPOWER (1 << 22)       // 0x00400000, ブルースパワー
#define EBUFF_TOADPOWER (1 << 23)        // 0x00800000, トードパワー
#define EBUFF_HEART (1 << 28)            // 0x10000000, ハートの紋章所持
#define EBUFF_JOKER (1 << 29)            // 0x20000000, ジョーカーの紋章所持

// PlayerKind, Player.kind
#define PLAYER_SOLAR_DJANGO 0  // 赤ジャンゴ (Red Django)
#define PLAYER_DARK_DJANGO 1   // 黒ジャンゴ (Dark Django)
#define PLAYER_BAT 2           // バット, 魔法"チェンジ・バット"(Cバット)でコウモリに変身した状態
#define PLAYER_MOUSE 3         // マウス, 魔法"チェンジ・マウス"(Cマウス)でネズミに変身した状態
#define PLAYER_SLEEPING 4      // スリーピング, 魔法"スリーピング"で棺桶の中で寝ている状態
#define PLAYER_SABATA 5        // サバタ

struct Emote;

struct Player;
struct Input;
typedef void (*PlayerFunc)(struct Player*);

typedef struct {
  u16 id;                     // 0x00 (Player: 0x264), ArmorData.id, 未装備は 0xFFFF (gStat->armors は s16 で負を空き扱いするが, こちらは符号なしで読まれる)
  u16 defence;                // 0x02 (Player: 0x266), ArmorData.defence
  u16 weight;                 // 0x04 (Player: 0x268), ArmorData.weight
  u16 unk_26a;                // 0x06 (Player: 0x26A), padding?
  u16 bonus[STAT_KINDS];      // 0x08 (Player: 0x26C), 武者鎧などのステータスに対する補正値
  s16 sideBonus[STAT_KINDS];  // 0x10 (Player: 0x274), 赤/黒による符号付き補正 (赤なら+, 黒なら-), [0] が HP, [1] が Ene に効く
} PlayerArmor;
static_assert(sizeof(PlayerArmor) == 24);  // 根拠: Player_RefreshDefence が 0x264 を1本のベースにして 0x266/0x272/0x27A を触る

typedef struct {
  Particle base;  // 0x00
  Vec3 vel;       // 0x28, Player_SpawnPtcl718 が第3引数の Vec3 をそのまま入れる
  bool8 active;   // 0x30, Player_SpawnPtcl718 が 1 を書く
  u8 unk_31;      // 0x31, Player_SpawnPtcl718 が 0 を書く
  u8 frameBase;   // 0x32, Particle_SetFrame に渡すコマ番号
  u8 unk_33;      // 0x33, padding?
} Particle52;
static_assert(sizeof(Particle52) == 52);

typedef struct {
  ParticleGroup* group1;  // 0x00, PTCL_GROUP_1
  Particle ptcl;          // 0x04
  bool8 active;           // 0x2C, 0 なら更新しない, 再生が終わると 0 に戻る
  u8 timer;               // 0x2D, 毎フレーム +1, 5 を超えると終わり
  u8 frameBase;           // 0x2E, Particle_SetFrame に渡すコマ番号の起点, timer >> 2 が足される
  u8 unk_2f;              // 0x2F, padding?
} PlayerParticleGroup1;
static_assert(sizeof(PlayerParticleGroup1) == 48);

// Player_InitPtcl718 で初期化処理がされるが、アクセス方法的に構造体として扱われるっぽい
typedef struct {
  ParticleGroup* group;  // 0x00, PTCL_GROUP_2
  bool8 active;          // 0x04, Player_SpawnPtcl718 が 1 を書く
  u8 next;               // 0x05, 次に使う ptcls の添字, 0..5 を巡回する
  u8 unk_06[2];          // 0x06, padding?
  Particle52 ptcls[6];   // 0x08, Player_InitPtcl718 でのループ回数
} PlayerParticleState718;

// Player_InitPtcl858 で初期化処理がされるが、アクセス方法的に構造体として扱われるっぽい
// ptcl_858 の要素, Particle のうしろに中心へ寄っていくための状態が並ぶ
// 根拠: Player_UpdatePtcl858 が offsetX/offsetZ を見て寄せ, timer が 4 になるとコマを1つ進める
typedef struct {
  Particle base;  // 0x00
  bool8 active;   // 0x28, 0 なら更新しない
  u8 timer;       // 0x29, 毎フレーム +1
  u8 speed;       // 0x2A, 中心へ寄る速さ
  u8 frameBase;   // 0x2B, Particle_SetFrame に渡すコマ番号の起点
  Vec3 offset;    // 0x2C, pos_930 からのずれ, y と val は使われない
} PlayerPtcl858;
static_assert(sizeof(PlayerPtcl858) == 52);

typedef struct {
  ParticleGroup* group;    // 0x00, PTCL_GROUP_2
  bool8 active;            // 0x04, 生きている要素が無くなると 0 に戻る
  u8 unk_05;               // 0x05
  u8 unk_06;               // 0x06
  u8 unk_07;               // 0x07
  PlayerPtcl858 ptcls[4];  // 0x08, Player_InitPtcl858 でのループ回数
} PlayerParticleState858;

// 装備している魔法の情報一式, Player の 0x280 に置かれている
typedef struct {
  magic8_t id;          // 0x280, 現在装備している(画面左下に表示されている)魔法のID
  u8 cat;               // 0x281, 現在装備している魔法のカテゴリ (MC_LUNA, MC_SOL, MC_DARK)
  bool8 availableForm;  // 0x282, 今のプレイヤーのフォームでこの魔法が使えるか (フォームと魔法の組み合わせのみで決まる, MPコストや太陽ゲージは見ない)
  bool8 enchanted;      // 0x283, エンチャント○○ がアクティブかどうか (プレイヤーが対応する色に光っているかどうか)
  u8 basicCost;         // 0x284, この魔法の消費MP (マジックローブなどの影響を抜いた元々の値)
  u8 unk_285;           // 0x285, FUN_0807b5d0 が 1 を、FUN_0807b5f8 が 0 を書く
  u8 unk_286[2];        // 0x286, padding
} PlayerMagic;
static_assert(sizeof(PlayerMagic) == 8);

// 近接攻撃の衝撃波 (ジャンゴ) / 銃の散弾 (サバタ) に使うスプライト一式
typedef struct PlayerShockwave {
  AuxSprite sprite;                         // 0x00 -> gfx
  AuxSpriteGfx gfx;                         // 0x2C, ジャンゴ: SPRITE_MELEE_SHOCKWAVE, サバタ: SPRITE_GUN_SPREAD
  AuxAnimState anim;                        // 0x48
  AuxAnimFile* animFile;                    // 0x58
  Vec3 vel;                                 // 0x5C, 毎フレーム sprite.pos に加算する, y と val は使われない, 根拠: PlayerShockwave_UpdateAnim
  bool8 finished;                           // 0x64, アニメーションが最後まで行くと立つ, 読んだ側は 0 に戻す
  u8 unk_65[3];                             // 0x65, padding?
  void (*update)(struct PlayerShockwave*);  // 0x68, PlayerShockwave_UpdateAnim か PlayerShockwave_UpdateFlash
} PlayerShockwave;
static_assert(sizeof(PlayerShockwave) == 108);

// 通常プレイでは gPlayerPtr[0] にこの構造体がある, 通信対戦の相手キャラもこの構造体を使う
typedef struct Player {
  Entity e;                         // 0x000
  u32 playerIdx;                    // 0x018, `.i`, 0 or 1 他にもあるか不明
  u32 unk_1c;                       // 0x01C, 入る値は 0 / 1 / 2 / 4 の4通り (1: 通常更新中, 2: 操作できない状態, 4: HP0), switch で引く箇所と & 1 / & 4 で見る箇所が混在する
  PlayerFlag20 flag20;              // 0x020, see PlayerFlag20
  Mover mover;                      // 0x024
  MainSpriteGfx spriteSet_68;       // 0x068, 根拠： Player_PlayAnim
  MainSprite sprite_88;             // 0x088, 根拠： Player_PlayAnim
  AuxSprite sprite_e8;              // 0x0E8, Player_Destroy が AuxSprite_Remove に渡す, pos は 0x104 で FUN_0807a91c が mover.pos / sprite_88.pos と一緒に書く
  AuxSpriteGfx* gfx_114;            // 0x114
  AuxSpriteGfx gfxForms[3];         // 0x118, 変身3種のグラフィック, gfx_114 がこのどれかを指す [Bat, Mouse, Sleeping]
  HitboxData hurtbox;               // 0x16C
  MoverTile tile;                   // 0x1BC, mover.tile がここを指す
  ZoneEventSource zoneEvents;       // 0x1CC, pos は mover.pos を指す, 毎フレーム FUN_08234660 に渡して範囲内のイベントを拾う
  NavAgent navAgent;                // 0x1FC, FUN_08081ab0 が Map_InitNavAgent に渡す
  EnemyTarget target;               // 0x220, kindMask 2 で登録される
  MsgQueue mq;                      // 0x230, FUN_0807ddd4 が MsgQueue_Unregister に渡す
  PlayerArmor armor;                // 0x264
  HitboxAttributes hbattrs;         // 0x27C
  PlayerMagic magic;                // 0x280, 装備魔法まわりの一群, 根拠: Player_RefreshMagicInfo が1本のベースレジスタで5フィールドを書く
  Weapon* unk_288;                  // 0x288, 根拠: FUN_080cf54c が +1 要素目を player_weapon_080ceafc に渡す
  struct Input* input;              // 0x28C, &gInput[n]
  DirU16 facingHistory[10];         // 0x290, 入力方向の履歴, 添字 0 が今フレームで大きいほど古い, 入力なしは -1
  rgb555 pltt_2a4[32];              // 0x2A4
  u16 animID;                       // 0x2E4, 今 sprite_88 で再生しているアニメのID, Player_PlayAnim が前回と同じIDかどうかの判定に使う
  u8 animIDOffset;                  // 0x2E6, Player_PlayAnim がアニメIDに足すオフセット
  bool8 xflip;                      // 0x2E7, 0 以外なら Player_PlayAnim が sprite_88.flags に SPRFLAG_XFLIP を立てる
  DirU8 facing;                     // 0x2E8
  u8 unk_2e9[2];                    // 0x2E9
  u8 hitboxTimer;                   // 0x2EB, hitbox_2ec を Hitbox_Register し続ける残りフレーム数, Django_Spike が 6 を入れる
  HitboxData hitbox_2ec;            // 0x2EC
  AuxAnimState anim_33c;            // 0x33C, 変身アニメの再生状態, 根拠: Player_GetMagicAction が AuxAnim_RestartAnim に渡す
  AuxAnimFile* anim_34c;            // 0x34C
  AuxAnimFile* anim_350;            // 0x350
  AuxAnimFile* anim_354;            // 0x354
  u8 kind;                          // 0x358: see PlayerKind
  u8 unk_359;                       // 0x359
  PlayerFlag35A flag35a;            // 0x35A, see PlayerFlag35A
  u16 stats[STAT_KINDS];            // 0x35C, プレイヤーのステータス値 (武者鎧などの装備品の補正値は含まない, タロットカードのドーピングは含む)
  u16 hp;                           // 0x364
  u16 maxHP;                        // 0x366
  u16 ene;                          // 0x368
  u16 maxEne;                       // 0x36A
  u8 unk_36c[10];                   // 0x36C
  u16 damage;                       // 0x376, プレイヤーのダメージ量, あとで HP から引く
  EquipBuffs equipBuffs;            // 0x378, see EquipBuffs
  u8 action;                        // 0x37C, いま実行している行動, kind ごとの PlayerFunc テーブル (0x085abcac など) の添字
  u8 state;                         // 0x37D, action の中の段階, 行動関数はこれで switch する
  u16 stateTimer;                   // 0x37E, Player_SetAction が 0 に戻してから経ったフレーム数, 行動関数が自分で数える
  bool8 formRequest;                // 0x380, 0 以外なら Player_ApplyFormRequest が formRequestKind のフォームに切り替えて 0 に戻す
  u8 formRequestKind;               // 0x381, 切り替え先の kind (see PlayerKind), 2/3/4 以外は PLAYER_DARK_DJANGO に戻る
  u8 unk_382;                       // 0x382, Player_GetMagicAction がコウモリ変身時に 0xBE を入れる
  u8 unk_383[4];                    // 0x383
  coffin8_t coffin;                 // 0x387, MagicSleeping_0806c124
  u16 unk_388;                      // 0x388, Player_ApplyFormRequest が寝るときに 0 にする
  u16 unk_38a;                      // 0x38A, 0 のときだけ FUN_0806e404 が専用の効果音を鳴らして 40 を入れる
  u16 eneAccum;                     // 0x38C, 棺桶で寝ている間の ENE 回復の端数, 棺桶ごとの寝心地を毎フレーム足して 0x80 ごとに ene を 1 増やす
  bool8 isSabata;                   // 0x38E, 根拠: Player_InitState
  u8 unk_38f;                       // 0x38F
  u16 unk_390;                      // 0x390
  u16 elevatorID;                   // 0x392, 搭乗中のエレベータのID
  u8 unk_394;                       // 0x394, FUN_0807a9b8 が 1 を書く
  u8 unk_395;                       // 0x395, Player_Unlock が 0 を入れる
  u8 unk_396;                       // 0x396, FUN_08065dac が 1 を書く
  u8 unk_397;                       // 0x397, 0 以外だと FUN_08065dac が何もしない
  Vec3* ptr_398;                    // 0x398, FUN_0807a9b8 の第2引数, FUN_08065dac は pos_39c を指させる
  Vec3 pos_39c;                     // 0x39C, FUN_08065dac が今踏んでいるタイルの中心を書く
  u8 useForcedDelta;                // 0x3A4, 0 以外だと FUN_080672b0 が移動速度を設定しない
  u8 unk_3a5[3];                    // 0x3A5, padding?
  Vec3 forcedDelta;                 // 0x3A8, useForcedDelta が 0 以外のとき Player_UpdateDjango が mover.delta にそのまま写す移動量
  Vec3 unk_3b0;                     // 0x3B0, FUN_0807a528 が引数の座標をそのまま写す
  u16 unk_3b8;                      // 0x3B8, FUN_0807a528 の第3引数
  u16 unk_3ba;                      // 0x3BA, FUN_0807b5a8 が 1 を書く
  u8 unk_3bc;                       // 0x3BC, FUN_08066d2c が見る
  DirU8 actionDir;                  // 0x3BD, 行動4/5 の基準方向, FUN_0807a44c が設定して facing をその反対向きにし, FUN_0807b0c0 は行動4/5 のときだけ facing の代わりに (actionDir + 4) & 7 を返す
  u16 unk_3be;                      // 0x3BE, Player_UpdateDjango が毎フレーム +1 し, 5 になった回だけ処理をする
  Vec3 pos_3c0;                     // 0x3C0, Player_UpdateCameraLookAt が mover.pos とカメラの注視点から作って Camera_LookAt に渡す
  Vec3 lookAroundOffset;            // 0x3C8, 見回し開始時のカメラ注視点からプレイヤーへのオフセット, val は見回しモード中か(0 or 1)
  u8 unk_3d0;                       // 0x3D0
  u8 unk_3d1;                       // 0x3D1
  u8 unk_3d2;                       // 0x3D2, Player_SetHitDir が被弾時に 1/0 を書く
  u8 unk_3d3;                       // 0x3D3
  u16 knockbackTimer;               // 0x3D4, 吹き飛ばされている間のカウンタ, 0x55 を超えた偶数フレームに効果音を鳴らす
  u16 unk_3d6;                      // 0x3D6, 審判のカードで復活するときに 0 が入る
  u16 poisonTick;                   // 0x3D8, 毒(badCondTimer[1])が残っている間の経過フレーム, 60 ごとに damage を1増やす, Player_ApplyBadCondition が毒が切れると 0 を書く
  u16 unk_3da;                      // 0x3DA, Player_StartFormEffect が変身を始めるときに 0 に戻す
  u16 sunburn;                      // 0x3DC, Player_StepSunburn が毎回 太陽ゲージ+2 を足し、100 を超えるたびに Player_TakeSunburnDamage を呼んで 100 引く
  u8 unk_3de[2];                    // 0x3DE
  u16 desertTimer;                  // 0x3E0, 砂漠エリアでの経過フレーム, 120 ごとに damage を1増やす (エリア外では 120 を入れておく)
  u16 blackArmorTimer;              // 0x3E2, 黒の鎧を装備している間の経過フレーム, 15 ごとに damage を1増やす
  u8 unk_3e4[2];                    // 0x3E4
  u16 unk_3e6;                      // 0x3E6, Player_SetHitDir が相手の HitboxData.unk_40 を退避する
  DirU16 hitDir;                    // 0x3E8, Player_SetHitDir が被弾方向 (0..7) を入れる
  u16 unk_3ea;                      // 0x3EA, FUN_0807ad60 が 1 を書く
  u16 unk_3ec;                      // 0x3EC, 0 以外だと FUN_0807ad60 が上書きを断る
  u8 unk_3ee[0x3F0 - 0x3EE];        // 0x3EE
  u8 unk_3f0;                       // 0x3F0, FUN_0807bdc8 が unk_4a6 と同じ値を書く
  u8 unk_3f1;                       // 0x3F1
  u8 unk_3f2;                       // 0x3F2, 目的地が遠い間 0..5 で増減し, 5 で姿を消して 1 以上で点滅する
  u8 unk_3f3[0x3F6 - 0x3F3];        // 0x3F3
  u16 floatHeight;                  // 0x3F6, sprite_88 の表示高さに足す浮き上がり量
  s16 heightAboveTile;              // 0x3F8, action 23 に入った時点の pos.y から足元タイルの高さ(階段補正込み)を引いた値
  u8 magicFired;                    // 0x3FA, 魔法の発動フレームに Player_HasEnoughSunGauge (太陽ゲージ判定) の結果が入る, 1 のときだけ効果が生成され、以降のフレームの演出判定にも使われる
  u8 dynamiteCount;                 // 0x3FB, 生存中の Entity080a8ff8 の数, Entity080a8ff8_Init が +1、消滅時に -1, MAGIC_DYNAMITE は 0 でないと再発動できない (Player_GetMagicAction)
  u8 dashSpeed;                     // 0x3FC, 太陽ゲージ*2+14 (上限32), Player_SetMoveDelta に渡す1フレームの移動量
  u8 dashFrames;                    // 0x3FD, 512 / dashSpeed, 移動距離を一定にするためのダッシュ継続フレーム数
  u8 unk_3fe;                       // 0x3FE, FUN_0806a050 が見て Player_SetFlag35a に渡す番号を選ぶ
  s8 unk_3ff;                       // 0x3FF, -1 なら未使用, Entity080db520 の枠番号が入る
  u8 angle_400;                     // 0x400, FUN_08063478 が angle_400 - angle_401 + 0x100 を 8bit に丸めて返す
  u8 angle_401;                     // 0x401, 同上
  u8 speedPenalty;                  // 0x402, 移動速度から引かれる量, FUN_0807a904 が +1 する
  u8 unk_403;                       // 0x403
  u16 unk_404;                      // 0x404, 行動7 を続けたフレーム数 (5 で効果音)
  u8 unk_406[3];                    // 0x406
  u8 unk_409;                       // 0x409, 行動7 の効果音を鳴らしているかどうか
  u8 unk_40a[2];                    // 0x40A
  u8 unk_40c[32];                   // 0x40C, 根拠: FUN_080bfa74 が32要素とも 0 で埋める
  u8 unk_42c[2];                    // 0x42C
  u16 unk_42e;                      // 0x42E, 根拠: FUN_080bfa74 が 0 を入れる
  u8 unk_430[0x43A - 0x430];        // 0x430
  u16 unk_43a;                      // 0x43A, FUN_0807b580 が 1 を書く
  u16 badCondTimer[3];              // 0x43C, 時間経過で治る状態異常の残り時間 [0: 腹痛, 1: 毒, 2: 混乱]
  u16 goodCondID;                   // 0x442, よいステータス効果のID, see GOOD_XXXX (e.g. GOOD_NINJA)
  u16 unk_444;                      // 0x444
  u16 goodCondTimer;                // 0x446, 0 でなければ goodCondID が有効
  u8 unk_448[0x456 - 0x448];        // 0x448
  s8 controlUp;                     // 0x456, 通常は gStat->controlUp が入るが、混乱(移動方向がおかしくなる状態異常)のときに書き換えられる
  u8 unk_457[0x464 - 0x457];        // 0x457
  u8 unk_464;                       // 0x464, FUN_08081ab0 が 1 を入れる
  u8 unk_465;                       // 0x465
  bool8 approachUsed;               // 0x466, 1 なら今の接近チャンスを使い切った状態, gPlayerPtr[0] の action が 0x15 でなくなると 0 に戻る
  u8 unk_467;                       // 0x467, 接近を試みる確率 (%)
  u8 blockLimit;                    // 0x468, blockCount の上限
  u8 blockCount;                    // 0x469, 行動8 で弾いた回数, blockLimit に達すると弾き返す
  u8 namakuraLimit;                 // 0x46A, namakuraCount の上限
  u8 namakuraCount;                 // 0x46B, 行動8 で HBATTR_NAMAKURA の攻撃を受けた回数, namakuraLimit に達すると行動 0x14 に移る
  u8 unk_46c;                       // 0x46C, '.G[0]', 既定 4
  u8 unk_46d;                       // 0x46D
  u8 unk_46e;                       // 0x46E, 行動3 で斬った回数
  u8 slashCount;                    // 0x46F, 行動3 で斬る回数 (2 か 3 を乱数で決める)
  u8 pathEndAction;                 // 0x470, 経路の終点に着いたときに移る action
  u8 pathEndFacing;                 // 0x471, 経路の終点に着いたときの facing
  s16 unk_472;                      // 0x472, Emote_Show の第6引数
  u16 unk_474;                      // 0x474, 行動 0x12 の残りフレーム数, Emote_Show に書き込み先として渡される
  u8 unk_476;                       // 0x476, 非0なら FUN_08084540 が無敵中の点滅をしない
  u8 unk_477;                       // 0x477
  WorldPos waypoints[4];            // 0x478, 巡回地点, val に着いたときの向きが入る
  PlayerFunc fn_498;                // 0x498, Player_UpdateDjango
  Vec3 unk_49c;                     // 0x49C, FUN_0807c88c が引数の座標をそのまま写す
  u16 unk_4a4;                      // 0x4A4, FUN_0807bee0 の第3引数
  u8 unk_4a6;                       // 0x4A6, FUN_0807bc14 の第2引数
  u8 unk_4a7;                       // 0x4A7, FUN_0807c748 の第3引数
  u8 unk_4a8;                       // 0x4A8
  DirS8 dir_4a9;                    // 0x4A9
  u8 unk_4aa;                       // 0x4AA, FUN_080726b4
  u8 unk_4ab;                       // 0x4AB, FUN_08072670 が 1 を書く
  u8 unk_4ac;                       // 0x4AC
  u8 footHitboxOn;                  // 0x4AD, 0 以外なら FUN_080726ec が footHitboxTimer を数える
  u8 footHitboxTimer;               // 0x4AE, 8 フレームごとに Player_EmitBurnSmoke を呼ぶためのカウンタ
  u8 unk_4af;                       // 0x4AF
  s32 scriptID_4b0;                 // 0x4B0, FUN_08072650
  u8 unk_4b4[0x4BC - 0x4B4];        // 0x4B4
  s16 unk_4bc;                      // 0x4BC, unk_4c0 と対で (乱数 & 0xF) - 7 とその符号反転が入る (FUN_0806e4b4), Player_UpdateSleeping が両方 0 に戻す
  u8 unk_4be[0x4C0 - 0x4BE];        // 0x4BE
  s16 unk_4c0;                      // 0x4C0, unk_4bc の符号反転
  u8 unk_4c2[0x4C4 - 0x4C2];        // 0x4C2
  Eff082473e0Emitter unk_4c4;       // 0x4C4
  Vec3 shadowPos;                   // 0x5FC, mover.pos に下の3つを足した値, 根拠: Player_UpdatePoseAndShadow
  Vec3 shadowOffset;                // 0x604, shadowPos を作るときに mover.pos に足す分, Player_BeginAction が 0 に戻す
  ParticleShadow shadow;            // 0x60C, 根拠: Player_DestroyEffects が ParticleShadow_Remove に渡す, FUN_081d40b4 がエレベータ搭乗中に flags の bit0 を立てる
  PlayerParticleGroup1 ptcl_64c;    // 0x64C, FUN_08061458
  PlayerParticleGroup1 ptcl_67c;    // 0x67C, FUN_0806161c
  PlayerShockwave meleeShockwave;   // 0x6AC
  PlayerParticleState718 ptcl_718;  // 0x718, 根拠: Player_InitPtcl718
  PlayerParticleState858 ptcl_858;  // 0x858, 根拠: Player_InitPtcl858
  Vec3 pos_930;                     // 0x930, FUN_08067f88 が mover.pos をずらして書く
  u16 plttIDs[9];                   // 0x938, unk_94c で引くパレットIDの表, 根拠: Player_BuildPltt
  u16 plttID_94a;                   // 0x94A, Player_ResetPltt
  s16 unk_94c;                      // 0x94C, Player_ResetPltt
  u8 unk_94e;                       // 0x94E, Player_UpdatePltt
  u8 unk_94f;                       // 0x94F
  u8 unk_950;                       // 0x950, Player_ResetPltt
  u8 unk_951;                       // 0x951, FUN_0806f780 が enchantIdx + 1 (負なら 0) を入れる
  u16 altPose;                      // 0x952, Player_ApplyPoseHold が pose が変わったときに控える値
  u16 altPoseTimer;                 // 0x954, 変化時に 0x40 を入れて毎回 1 減らす, bit2 が立つ間は altPose を返す
  u16 badCondBlinkTimer;            // 0x956, Player_TickBadCondTimers が状態異常1の残り時間が切れたあと 0x40 から減らす点滅タイマ
  u16 sunDrainBlinkTimer;           // 0x958, 同じく太陽ゲージ消費側の点滅タイマ
  u16 flashPose;                    // 0x95A, flashTimer の bit2 が立っている間 Player_ApplyFlashPose が pose の代わりに返す値
  u16 flashTimer;                   // 0x95C, Player_ApplyFlashPose が毎フレーム 1 減らす点滅タイマ
  u16 plttID_95e;                   // 0x95E, FUN_0807b890 / FUN_0807b8a8 が第2引数を書く
  u16 unk_960;                      // 0x960, FUN_08074994 が plttID_95e と対で書く
  u16 unk_962;                      // 0x962, Player_EquipMagic がエンチャント開始時に magic.id + 0x121 を入れる
  u16 unk_964;                      // 0x964, 同じ呼び出しで 0x20 を入れる, unk_962 が 0 のときだけ 0 に戻される
  u8 unk_966[0x96C - 0x966];        // 0x966
  u16 unk_96c;                      // 0x96C, FUN_0807b8c0 が 0 を書く
  u8 unk_96e[2];                    // 0x96E, padding?
  Vec3 pos_970;                     // 0x970, Player_UpdateBloodSword が FUN_0805fe7c の第5引数に渡す
  u8 unk_978;                       // 0x978, 同じく第6引数
  bool8 enchantStarted;             // 0x979, エンチャントが始まったフレームだけ立つ, Player_Update が効果音を鳴らして 0 に戻す
  u16 unk_97a;                      // 0x97A, Player_InitEffects が条件付きで 0x40 を入れる
  u8 mosaicFrom[4];                 // 0x97C, MosaicFader_Start の from, 初期値は全部 4
  u8 unk_980[4];                    // 0x980, 同じく to, 初期値は全部 0
  u16 mosaicInterval[4];            // 0x984, 同じく interval, 初期値は全部 4
  struct Emote* emote;              // 0x98C
  u8 emoteKind;                     // 0x990, see EmoteKind
  u8 unk_991;                       // 0x991
  u16 unk_992;                      // 0x992, 0 でなければ毎フレーム 1 減らし, 0 になった回に Emote_Show を呼ぶ
  MsgPacket msg_994;                // 0x994, FUN_0807e278 が組み立てて送る, args は可変長なので後ろの unk_9a0 まで伸びる
  u8 unk_9a0[0x9BC - 0x9A0];        // 0x9A0
  u16 unk_9bc;                      // 0x9BC
  u16 pad_9be;                      // 0x9BE, padding
  s32 scriptID_9c0;                 // 0x9C0
  s32 scriptID_9c4;                 // 0x9C4, 0x0089 (Script_0089) を指しているときがあった
  AuxSprite sprite_9c8;             // 0x9C8, 根拠: PlayerSabata_Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx_9f4;             // 0x9F4, SPRITE_2110, sprite_9c8 が参照する
  HitboxData unk_a10;               // 0xA10, 根拠: 0x08064644
  u8 unk_a60[0xA70 - 0xA60];        // 0xA60
  Weapon* weapon;                   // 0xA70, 装備中の武器の実体, Player_ApplyWeapon が差し替え, 外すときは NULL
  weapon8_t weaponID;               // 0xA74, 装備中(画面右下に表示される攻撃ボタンで使用する)武器のID
  u8 weaponKind;                    // 0xA75, 装備中の武器種 (see WeaponKind)
  u8 unk_a76[2];                    // 0xA76, padding?
  u16 weaponAtk;                    // 0xA78, WeaponData.atk の複写, 根拠: Player_ApplyWeapon
  u16 totalAtk_a7a;                 // 0xA7A, ステータス画面に表示される"コウゲキ"の値と等しくなる(力, 防具込みの最終値っぽい), 装備してすぐに更新されず、クイックチェンジ(セレクトでの武器切り替え)のタイミングで更新される
  u16 unk_a7c;                      // 0xA7C, Hitbox_SetAttack の第3引数, 武器種ごとの値
  u16 unk_a7e;                      // 0xA7E, 同じく第6引数
  u8 unk_a80[0xA8A - 0xA80];        // 0xA80
  u16 gunSpreadAngle;               // 0xA8A, Player_ShowGunSpread が散弾スプライトの rotation に入れる向き
  u8 unk_a8c;                       // 0xA8C
  s8 enchantIdx;                    // 0xA8D, FUN_0806f780 が Player_CheckMagicEnchant の結果を入れる, 負ならエンチャントなし
  u8 unk_a8e;                       // 0xA8E
  u8 charge;                        // 0xA8F, Entity08080be8 が毎フレーム charge に写す, 威力を 1 + n/2 倍にし、スプライトの絵も選ぶ
  u8 unk_a90[5];                    // 0xA90
  u8 unk_a95;                       // 0xA95, アストロ武器の種類ごとの値 (剣: 0, 槍: 4, 槌: 8)
  u8 unk_a96[2];                    // 0xA96, padding?
  PlayerFunc attackCB;              // 0xA98, sPlayerAttackUpdates

  // 武器の特殊効果のコールバック関数の配列
  u32 (*weaponExDamageCb[WEAPON_EFFECT_SLOT_COUNT])(struct Player*);  // 0xA9C, プレイヤーの状態を参照する武器の特殊効果コールバック
  u32 (*weaponEffectCb2[WEAPON_EFFECT_SLOT_COUNT])(struct Player*);   // 0xAA8, 状態を参照しない武器の特殊効果コールバック, 防御無視効果と麻痺のハンドラはここ
  void* weaponEffectCb3[WEAPON_EFFECT_SLOT_COUNT];                    // 0xAB4,　敵の状態を参照する武器の特殊効果コールバック, xx特効系のハンドラはここ, シグネチャはまだ不明

  // 0xAC0
  // CreatePlayer製:       FUN_08065270　で 0x085abb14 の関数テーブル or FUN_08079f1c
  // CreateLinkPlayer2P製: FUN_080817ec で FUN_08084330 がセットされる
  PlayerFunc updateCallback;
} Player;
static_assert(sizeof(Player) == 2756);

// ------------------------------------------------------------------------------------------------------------------------------------

extern Player* gPlayerPtr[4];
void FUN_0807a524(Vec3* pos);
void FUN_0807a8e0(Player* p);
void FUN_0807aa30(Player* p, s32 amount);

extern u16 gGoodCondID;      // 0x03002B60
extern u16 gConfusedDir;     // 0x03002B64
extern u16 u16_03002b68[4];  // 0x03002B68, 多分プレイヤーの moverID
extern u16 gGoodCondTimer;   // 0x03002B8C, Player.goodCondTimer の退避, 他Entityからの参照用
extern u16 gWindAngle;

Player* CreatePlayer(u32 n, void* _);
s32 FUN_0806f900(Player* player);
s32 FUN_080d1b04(Player* player);
void Player_ReduceENE_0807aa60(Player* player, s32 amount);
void Player_Unlock(Player* p);
void FUN_0807bb3c(Player* p, Vec3* pos, DirS32 dir, s32 param_4, u32 scriptID);
void FUN_0807bc64(Player* p, u32 scriptID);
void Player_SetAction(Player* p, u32 action, u32 state);
void Player_ApplyBadCondition(Player* p, s32 badcondID, s32 frames);
void Player_ClearBadCondition(Player* p, s32 badcondID);
void Player_RefreshAllStats(Player* p);
void Player_EquipMagic(Player* p, magic32_t n);
u32 FUN_08066ee4(s32 playerKind, s32 idx);
void FUN_0807a91c(Player* p, Vec3* pos);

static inline void Player_SetFlag20(Player* p, PlayerFlag20 bit) { p->flag20 |= bit; }
static inline bool32 Player_TestFlag20(Player* p, PlayerFlag20 bit) { return p->flag20 & bit; }

static inline void Player_SetEquipBuff(Player* p, EquipBuffs bits) { p->equipBuffs |= bits; }
static inline void Player_ClearEquipBuff(Player* p, EquipBuffs bits) { p->equipBuffs &= ~bits; }
static inline bool32 Player_TestEquipBuff(Player* p, EquipBuffs bits) { return p->equipBuffs & bits; }

#endif  // GUARD_ZOKTAI_PLAYER_H
