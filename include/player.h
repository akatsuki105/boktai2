#ifndef GUARD_ZOKTAI_PLAYER_H
#define GUARD_ZOKTAI_PLAYER_H

#include "constants/constants.h"
#include "eff_elemcond.h"
#include "elevator.h"
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
#define PFLAG20_BUSY (1 << 0)        // 0x00000001, 行動中, Player_BeginAction が毎回これだけ立てた状態から始め, 待機・歩きなどの行動だけが落とす, 立っていると START/SELECT やクイックチェンジが効かない
#define PFLAG20_UNK_1 (1 << 1)       // 0x00000002
#define PFLAG20_UNK_2 (1 << 2)       // 0x00000004, 壁張り付き (PACT_WALL) の始めに立つ
#define PFLAG20_WALL_COVER (1 << 3)  // 0x00000008, 壁に張り付いている間 (PACT_WALL の state 1・2) 立つ
#define PFLAG20_SUNBATHING (1 << 4)  // 0x00000010, プレイヤーに日光が当たっているか
#define PFLAG20_QC (1 << 5)          // 0x00000020, プレイヤーが急速チャージ中, つまり (ジャンゴなら) 太陽チャージ中 && ENEがまだ最大でない && 太陽が当たっている状態, (サバタなら) 暗黒チャージ中 && ENEがまだ最大でない && 太陽が当たっていない状態
#define PFLAG20_REFUELING (1 << 6)   // 0x00000040, 太陽スタンドから ENE を受け取っている間, SolarStation_UpdateInUse が貯金から ENE を1ずつ移す
#define PFLAG20_PALM_UP (1 << 7)     // 0x00000080, 太陽チャージ (サバタは暗黒チャージ) で手をかざしている間立つ, 実際にチャージが効いているときは PFLAG20_QC も立つ
#define PFLAG20_UNK_8 (1 << 8)       // 0x00000100
#define PFLAG20_INKA (1 << 9)        // 0x00000200, ELEMCOND_INKA にかかっているか
#define PFLAG20_UNK_10 (1 << 10)     // 0x00000400
#define PFLAG20_UNK_11 (1 << 11)     // 0x00000800
#define PFLAG20_UNK_12 (1 << 12)     // 0x00001000, 掴まれたとき (Player_EnterGrabbed) や本体と食らい判定を消す特殊状態で立つ, 立っていると敵の索敵 (Enemy_FindVisiblePlayer) がプレイヤーを無視する
#define PFLAG20_UNK_13 (1 << 13)     // 0x00002000
#define PFLAG20_UPDATED (1 << 14)    // 0x00004000, このフレームに更新処理が走った, Player_UpdateDjango などフォーム別の更新関数が先頭で立てる
#define PFLAG20_UNK_15 (1 << 15)     // 0x00008000, 立っていると Player_SetupKnockback が被弾方向を facing ではなく knockbackDir に書く
#define PFLAG20_SNEAKING (1 << 16)   // 0x00010000, スニーク状態(スカルスーツ装備, Cマウス形態 など), 処理的には、 "敵の視界が半分になる"
#define PFLAG20_INVISIBLE (1 << 17)  // 0x00020000, 敵から見えない状態
#define PFLAG20_UNK_18 (1 << 18)     // 0x00040000, mode が LOCKED / DEAD のとき, バット・マウス・スリーピング形態, 縮小中に立つ, 立っているとリンゴとシェードマンの掴み系の処理が対象から外す
#define PFLAG20_UNK_19 (1 << 19)     // 0x00080000, エンチャントした武器の攻撃判定が出ている間と弾が飛んでいる間に立つ, Entity080db520 はこれか日光があると姿を見せる

// Player.action, sDjangoActionFuncs (サバタは sSabataActionFuncs) の添字, 2つの表は同じ番号に同じ種類の行動が並ぶ
#define PACT_IDLE 0           // 立ち止まっている, Player_UpdateIdle
#define PACT_WALK 1           // 歩く, Player_UpdateWalk
#define PACT_DASH 2           // ダッシュ, MagicDash_Update (サバタは Magic_ZeroShift)
#define PACT_ATTACK 3         // 攻撃中 (武器は問わない)
#define PACT_WALL 4           // 壁張り付き, 壁沿いに横歩きする状態
#define PACT_PUSH 5           // ブロック動かし中 (もう動かせないブロックを押しているときは PACT_WALL のままで、 PACT_PUSH にはならない)
#define PACT_PULL_COFFIN 6    // 棺桶を引く, 入力が無く止まっているときも含む
#define PACT_UNK_7 7          // 太陽チャージ, ワープ, 太陽鍛冶
#define PACT_REFUELING 8      // 太陽スタンド使用中 (共闘サバタだと違う用途かも?)
#define PACT_SUN_MAGIC 9      // ライジングサン (サバタはブラックサン)
#define PACT_TRANSFORM 10     // トランス, MagicTransform_0806b92c
#define PACT_CWOLF 11         // チェンジウルフ(Cウルフ)
#define PACT_CBAT 12          // チェンジバット(Cバット)
#define PACT_CMOUSE 13        // チェンジマウス(Cマウス)
#define PACT_SLEEPING 14      // スリーピング
#define PACT_FREEZE 15        // フリーズ
#define PACT_HEALING 16       // ヒーリング
#define PACT_DYNAMITE 17      // ダイナマイト
#define PACT_UNK_18 18        // ?
#define PACT_SEKIKA 19        // 石化, 石化の粒 (ELEMCOND_SEKIKA) が残っている間, 共闘サバタでは 1P の方へ向き直る行動
#define PACT_SPIDER_WEB 20    // クモの巣に捕まっている (spiderWebIdx が 0 以上の間), 共闘サバタでは暗黒銃の散弾を撃ち続ける行動
#define PACT_GRABBED 21       // 敵に掴まれて拘束されている (オクトパス, リンゴ, シェードマン, ヨルムンガンド), Player_EnterGrabbed が入れる
#define PACT_FALL 22          // 落とし穴で下のエリアに落下
#define PACT_LANDING 23       // 落下からの着地 (PACT_FALL の後, ダメージも受けないし,死亡もしない)
#define PACT_DAMAGED 24       // ダメージ時
#define PACT_BLOWN_AWAY 25    // 吹っ飛ばされて仰向けに倒れる (e.g. オクトパスの拘束から投げ飛ばされるとき)
#define PACT_DEATH_PRONE 26   // 死亡(うつ伏せ), 1番よく使われる死亡状態
#define PACT_DEATH_SUPINE 27  // 死亡(仰向け)
#define PACT_FALLDEATH 28     // 落下死
#define PACT_DROWNING 29      // 溺死 (水フィールドでの落下死)
#define PACT_HEATSTROKE 30    // オーバーヒートで倒れた (酒場2階のベッドに運ばれる)
#define PACT_SPECIALDEATH 31  // キャラ固有のゲームオーバー(ジャンゴ: ウルフイベント, サバタ: 運搬中の黒ジャンゴのHPが0になった)
#define PACT_UNK_32 32        //

// Player.mode, 毎フレーム gPlayerModes[idx] にも写される
typedef u32 PlayerMode;
#define PMODE_ACTIVE (1 << 0)  // 0x1, 通常更新中, Player_Unlock が入れる
#define PMODE_LOCKED (1 << 1)  // 0x2, 操作できない状態, Player_EnterLockedState が入れる
#define PMODE_DEAD (1 << 2)    // 0x4, HP0
#define PMODE_UNK_3 (1 << 3)   // 0x8, 用途不明, 立っているとミミックの標的やマップアイテムの取得対象から外れる

// Player.flag35a, Player_BeginAction が毎フレーム 0 に戻し、行動関数が立てたものを Player_PostUpdateHuman がその場で反映する
typedef u16 PlayerFlag35A;
#define PFLAG35A_HIDE_BODY (1 << 0)    // 0x0001, 今のフォームの本体スプライトに SPRFLAG_HIDDEN を立てる, ジャンゴ / サバタは human, バット / マウス / スリーピングは beast
#define PFLAG35A_BLINK (1 << 1)        // 0x0002, human に SPRFLAG_BLINK_ODD を立てる
#define PFLAG35A_HIDE_SHADOW (1 << 2)  // 0x0004, 影を ParticleShadow_Hide する
#define PFLAG35A_NO_HURTBOX (1 << 3)   // 0x0008, hurtbox に HBFLAG_HIDDEN をセット, ワープ魔法陣のワープ中などプレイヤーの食らい判定を無効化するためのフラグ
#define PFLAG35A_NO_TILE (1 << 4)      // 0x0010, mover.tile を NULL にして Map_InitMoverTile を飛ばす
#define PFLAG35A_UNK_5 (1 << 5)        // 0x0020, FUN_08082464 が立てるが読み手は未発見
#define PFLAG35A_SHOW_OTHER (1 << 6)   // 0x0040, 立てたときだけ本体でない方のスプライトの SPRFLAG_HIDDEN を落とす (既定は隠す), ジャンゴ / サバタは beast, バット / マウス / スリーピングは human
#define PFLAG35A_UNK_7 (1 << 7)        // 0x0080, サバタのみ, 立てたときだけ wpn.sprite の SPRFLAG_HIDDEN を落とす (既定は隠す)

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
#define EBUFF_TOADPOWER (1 << 23)        // 0x00800000, トードパワー (雨を浴びるとエナジー回復)
#define EBUFF_HEART (1 << 28)            // 0x10000000, ハートの紋章所持 (素手の攻撃力UP)
#define EBUFF_JOKER (1 << 29)            // 0x20000000, ジョーカーの紋章所持 (チャージショットのタメ時間が半分になる)

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
static_assert(sizeof(PlayerArmor) == 24);  // 根拠: Player_RefreshHurtbox が 0x264 を1本のベースにして 0x266/0x272/0x27A を触る

// 武器のエンチャント属性の粒1つ, vel で飛び 6フレーム目で小さいコマに変わり 12フレームで消える
typedef struct {
  Particle base;  // 0x00
  Vec3 vel;       // 0x28
  bool8 active;   // 0x30, 0 なら更新しない
  u8 timer;       // 0x31, 毎フレーム +1, 6 でコマを1つ進め, 12 で消える
  u8 poseIdx;     // 0x32, PTCL_GROUP_2 の属性の「大」のコマ (element * 2 + 2)
  u8 unk_33;      // 0x33, padding?
} EnchantPtcl;
static_assert(sizeof(EnchantPtcl) == 52);

typedef struct {
  ParticleGroup* group1;  // 0x00, PTCL_GROUP_1
  Particle ptcl;          // 0x04
  bool8 active;           // 0x2C, 0 なら更新しない, 再生が終わると 0 に戻る
  u8 timer;               // 0x2D, 毎フレーム +1, 5 を超えると終わり
  u8 poseIdx;             // 0x2E, Particle_SetPose に渡すコマ番号の起点, timer >> 2 が足される
  u8 unk_2f;              // 0x2F, padding?
} PlayerParticleGroup1;
static_assert(sizeof(PlayerParticleGroup1) == 48);

// 剣/槍/ハンマーの攻撃中に出すエンチャント属性の粒6個
typedef struct {
  ParticleGroup* group2;  // 0x00, PTCL_GROUP_2
  bool8 active;           // 0x04, 生きている要素が無くなると 0 に戻る
  u8 next;                // 0x05, 次に使う ptcls の添字, 0..5 を巡回する
  u8 unk_06[2];           // 0x06, padding?
  EnchantPtcl ptcls[6];   // 0x08
} PlayerEnchantPtcls;

// チャージ中に chargePos へ吸い寄せられる光/闇の粒1つ, timer が 4 になると小さいコマに変わり, ±15 以内まで寄ると消える
typedef struct {
  Particle base;  // 0x00
  bool8 active;   // 0x28, 0 なら更新しない
  u8 timer;       // 0x29, 毎フレーム +1
  u8 speed;       // 0x2A, 中心へ寄る速さ
  u8 poseIdx;     // 0x2B, Particle_SetPose に渡すコマ番号の起点
  Vec3 offset;    // 0x2C, chargePos からのずれ, y と val は使われない
} ChargePtcl;
static_assert(sizeof(ChargePtcl) == 52);

typedef struct {
  ParticleGroup* group2;  // 0x00, PTCL_GROUP_2
  bool8 active;           // 0x04, 生きている要素が無くなると 0 に戻る
  u8 next;                // 0x05, 次に使う ptcls の添字, 0..3 を巡回する
  u8 spawnTimer;          // 0x06, 太陽チャージでは毎フレーム 太陽ゲージ + 2 を貯め 0x28 を超えると1つ出す, 暗黒チャージでは 4 フレームに1つ出す
  u8 pad_07;              // 0x07, padding
  ChargePtcl ptcls[4];    // 0x08
} PlayerChargePtcls;

// 装備している魔法の情報一式, Player の 0x280 に置かれている
typedef struct {
  magic8_t id;          // 0x280, 現在装備している(画面左下に表示されている)魔法のID
  u8 cat;               // 0x281, 現在装備している魔法のカテゴリ (MC_LUNA, MC_SOL, MC_DARK)
  bool8 availableForm;  // 0x282, 今のプレイヤーのフォームでこの魔法が使えるか (フォームと魔法の組み合わせのみで決まる, MPコストや太陽ゲージは見ない)
  bool8 enchanted;      // 0x283, エンチャント○○ がアクティブかどうか (プレイヤーが対応する色に光っているかどうか)
  u8 basicCost;         // 0x284, この魔法の消費MP (マジックローブなどの影響を抜いた元々の値)
  u8 unk_285;           // 0x285, Cmd_41D3 が 1 を、Cmd_8CFE が 0 を書く
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

// 通常プレイでは gPlayerPtr[0] にこの構造体がある, 通信対戦の相手キャラ, 共闘サバタ もこの構造体を使う
// 装備中の武器と, その攻撃判定・散弾スプライトの一群 (Player.wpn)
typedef struct {
  AuxSprite sprite;    // 0x00, 根拠: AllySabata_Destroy が AuxSprite_Remove に渡す
  AuxSpriteGfx gfx;    // 0x2C, SPRITE_GUN_SPREAD, sprite が参照する
  HitboxData hitbox;   // 0x48, 武器の攻撃判定, Player_SetWeaponHitbox が設定し, 当てたダメージを Player_UpdateWeaponWear が武器の損傷に回す
  Vec3 atkPos;         // 0x98, basePos から angle の向きへ進めた位置, 攻撃判定の基準位置になる
  Vec3 basePos;        // 0xA0, 攻撃を出した瞬間の自分の位置を上へずらしたもの
  Weapon* weapon;      // 0xA8, 装備中の武器の実体, Player_ApplyWeapon が差し替え, 外すときは NULL
  weapon8_t weaponID;  // 0xAC, 装備中(画面右下に表示される攻撃ボタンで使用する)武器のID
  u8 weaponKind;       // 0xAD, 装備中の武器種 (see WeaponKind)
  u8 unk_ae[2];        // 0xAE, padding?
  u16 weaponAtk;       // 0xB0, WeaponData.atk の複写, 根拠: Player_ApplyWeapon
  u16 atkPower;        // 0xB2, ステータス画面に表示される"コウゲキ"の値と等しくなる(力, 防具込みの最終値っぽい), 装備してすぐに更新されず、クイックチェンジ(セレクトでの武器切り替え)のタイミングで更新される
  u16 knockback;       // 0xB4, 攻撃判定の HitboxData.knockback, 武器種ごとに Player_SetWeaponHitbox が決める
  u16 iframes;         // 0xB6, 攻撃判定の HitboxData.iframes (当てた相手に与える無敵時間), 武器種ごとに決まる
  u16 unk_b8[5];       // 0xB8, 攻撃判定の形の値, 槍は武器の状態に応じて 56 / 27 か 28 / 2 か 4 / 3, 4, 7 / 0, 1, 5 を入れる
  u16 gunSpreadAngle;  // 0xC2, Player_ShowGunSpread が散弾スプライトの rotation に入れる向き, 攻撃処理では経過フレーム数として数える
  u8 angle;            // 0xC4, 攻撃の向き (8bit), ((facing + 5) & 7) << 5 で決める
  s8 enchantIdx;       // 0xC5, Player_RefreshEnchant が Player_CheckMagicEnchant の結果を入れる, 負ならエンチャントなし
  u8 unk_c6;           // 0xC6
  u8 charge;           // 0xC7, Bullet が毎フレーム charge に写す, 威力を 1 + n/2 倍にし、スプライトの絵も選ぶ
} PlayerWeapon;
static_assert(sizeof(PlayerWeapon) == 200);

typedef struct Player {
  Entity e;                         // 0x000
  u32 inputIdx;                     // 0x018, `.i`, 0 or 1, gInput の添字, 0 は操作中のプレイヤー, 1 はスクリプトのサバタや通信対戦の相手
  PlayerMode mode;                  // 0x01C, see PlayerMode, 0 か PMODE_* のどれか1つ, switch で引く箇所と & で見る箇所が混在する
  PlayerFlag20 flag20;              // 0x020, see PlayerFlag20
  Mover mover;                      // 0x024
  MainSpriteGfx humanGfx;           // 0x068, SPRITE_DJANGO_SABATA
  MainSprite human;                 // 0x088, 根拠： Player_PlayAnim
  AuxSprite beast;                  // 0x0E8, 人型以外 (バット / マウス / スリーピング) のときに使うスプライト
  AuxSpriteGfx* beastGfx;           // 0x114, beastGfxs のどれかを指す
  AuxSpriteGfx beastGfxs[3];        // 0x118, 変身3種のグラフィック [Bat, Mouse, Sleeping]
  HitboxData hurtbox;               // 0x16C
  MoverTile tile;                   // 0x1BC, mover.tile がここを指す
  ZoneEventSource zoneEvents;       // 0x1CC, pos は mover.pos を指す, 毎フレーム Map_UpdateZoneEvents に渡して範囲内のイベントを拾う
  NavAgent navAgent;                // 0x1FC, FUN_08081ab0 が Map_InitNavAgent に渡す
  EnemyTarget target;               // 0x220, kindMask 2 で登録される
  MsgQueue mq;                      // 0x230, Player_UnregisterMsgQueue が MsgQueue_Unregister に渡す
  PlayerArmor armor;                // 0x264
  HitboxAttributes hbattrs;         // 0x27C
  PlayerMagic magic;                // 0x280, 装備魔法まわりの一群, 根拠: Player_RefreshMagicInfo が1本のベースレジスタで5フィールドを書く
  Weapon* unk_288;                  // 0x288, ここらへんは union の可能性がある (通信時とか)
  struct Input* input;              // 0x28C, &gInput[n]
  DirU16 facingHistory[10];         // 0x290, 入力方向の履歴, 添字 0 が今フレームで大きいほど古い, 入力なしは -1
  rgb555 pltt[32];                  // 0x2A4, 自前のパレット, [0..15] は plttIDs[plttIdx] を plttBrightness ぶん明るくしたもの, [16..31] は flashPlttID と混ぜた結果, スプライトのパレットがどちらかを指す
  u16 animID;                       // 0x2E4, 今 human で再生しているアニメのID, Player_PlayAnim が前回と同じIDかどうかの判定に使う
  u8 animDir;                       // 0x2E6, アニメの向き (0..4 か 0..2), アニメIDに足す, 左向きは右向きの番号を xflip で反転して使う
  bool8 xflip;                      // 0x2E7, 0 以外なら Player_PlayAnim が human.flags に SPRFLAG_XFLIP を立てる
  DirU8 facing;                     // 0x2E8, プレイヤーの向き, 壁に背を向けている場合は壁と反対方向(=プレイヤーの顔が向いている方)
  u8 unk_2e9[2];                    // 0x2E9
  u8 hitboxTimer;                   // 0x2EB, spikeHitbox を Hitbox_Register し続ける残りフレーム数, Django_Spike が 6 を入れる
  HitboxData spikeHitbox;           // 0x2EC, スパイクメイルの反撃の攻撃判定, hitboxTimer が残っている間だけ登録される
  AuxAnimState beastAnim;           // 0x33C, beast の変身アニメの再生状態, 根拠: Player_GetMagicAction が AuxAnim_RestartAnim に渡す
  AuxAnimFile* batAnim;             // 0x34C, ANIM_BAT
  AuxAnimFile* mouseAnim;           // 0x350, ANIM_MOUSE
  AuxAnimFile* coffinAnim;          // 0x354, ANIM_COFFIN
  u8 kind;                          // 0x358: see PlayerKind
  u8 useAuxSprite;                  // 0x359, バット / マウス / スリーピングで AuxSprite を使っている間 1
  PlayerFlag35A flag35a;            // 0x35A, see PlayerFlag35A
  u16 stats[STAT_KINDS];            // 0x35C, プレイヤーのステータス値 (武者鎧などの装備品の補正値は含まない, タロットカードのドーピングは含む)
  u16 hp;                           // 0x364
  u16 maxHP;                        // 0x366
  u16 ene;                          // 0x368
  u16 maxEne;                       // 0x36A
  u8 unk_36c[10];                   // 0x36C
  u16 damage;                       // 0x376, プレイヤーのダメージ量, あとで HP から引く
  EquipBuffs equipBuffs;            // 0x378, see EquipBuffs
  u8 action;                        // 0x37C, いま実行している行動, see PACT_*
  u8 state;                         // 0x37D, action の中の段階, 行動関数はこれで switch する
  u16 stateTimer;                   // 0x37E, Player_SetAction が 0 に戻してから経ったフレーム数, 行動関数が自分で数える
  bool8 formRequest;                // 0x380, 0 以外なら Player_ApplyFormRequest が formRequestKind のフォームに切り替えて 0 に戻す
  u8 formRequestKind;               // 0x381, 切り替え先の kind (see PlayerKind), 2/3/4 以外は PLAYER_DARK_DJANGO に戻る
  u8 batHeight;                     // 0x382, バットの浮遊高さ, beast.pos.y に足す, 変身時 190, 石化中は 60 ずつ下げて 0 にする
  u8 batHeightTarget;               // 0x383, batHeight の目標, 140..239 を乱数で決める
  u8 batHeightTimer;                // 0x384, batHeightTarget を引き直すまでの残りフレーム (16)
  u8 batWanderTimer;                // 0x385, バットの歩きで向きを決め直すまでの残り, まっすぐなら 9, ふらついたら 3
  bool8 mouseStepAlt;               // 0x386, マウスの足音を左右交互に鳴らすための 0/1
  coffin8_t coffin;                 // 0x387, MagicSleeping_0806c124
  u16 walkVoiceTimer;               // 0x388, 棺桶獣の歩き声 (VO_ELEFAN_WALK) を次に鳴らすまでの残りフレーム, 鳴らすたびに 64..127 を乱数で入れる
  u16 attackVoiceCooldown;          // 0x38A, 棺桶獣の攻撃の声 (VO_ELEFAN_ATTACK) を再び鳴らせるまでの残りフレーム, 鳴らすと 40 を入れて毎フレーム 1 減る
  u16 eneAccum;                     // 0x38C, 棺桶で寝ている間の ENE 回復の端数, 棺桶ごとの寝心地を毎フレーム足して 0x80 ごとに ene を 1 増やす
  bool8 isSabata;                   // 0x38E, 根拠: Player_InitState
  u8 toadTick;                      // 0x38F, トードパワー時に 雨を浴びているフレームをカウントする (15でENEを1回復)
  ElevatorFlagsU16 elevatorFlags;   // 0x390, see ElevatorFlagsU16, 0 ならどのエレベータにも乗っていない
  u16 elevatorID;                   // 0x392, 乗っているエレベータの id, Player_ClearElevatorFlags が 0 にするので止まっているエレベータに乗っている間は 0
  bool8 originHitPending;           // 0x394, knockbackOrigin から弾かれる被弾が保留中, Player_SetKnockbackOrigin が立て Player_UpdateDamage が Player_ApplyOriginHit で処理して落とす
  bool8 originKnockback;            // 0x395, 今の吹き飛ばしが knockbackOrigin から離れる向き, Player_ApplyOriginHit が立てダメージの行動 (PACT_DAMAGED) の終わりと Player_Unlock が落とす
  bool8 tileHitPending;             // 0x396, 太陽で切り替わる水たまり (Puddle) を踏んだ被弾が保留中, Player_CheckPuddleHurt が立て Player_UpdateDamage が Player_ApplyTileHit で処理して落とす
  bool8 tileKnockback;              // 0x397, 今の吹き飛ばしが設置物を踏んだことによるもの, Player_ApplyTileHit が立てダメージの行動 (PACT_DAMAGED) の終わりに落とす, 立っている間 Player_CheckPuddleHurt は何もしない
  Vec3* knockbackOrigin;            // 0x398, 弾き飛ばす側の位置, この位置から離れる向きに吹き飛ぶ, エレベーター (Elevator_KnockbackPlayer) が Player_SetKnockbackOrigin で渡すか Player_CheckPuddleHurt が knockbackTileCenter を指させる
  Vec3 knockbackTileCenter;         // 0x39C, Player_CheckPuddleHurt が今踏んでいるタイルの中心を書く
  u8 useForcedDelta;                // 0x3A4, 0 以外だと Player_UpdateWalk が移動速度を設定しない
  u8 slip_3a5[2];                   // 0x3A5, すべり床でのスリップに関係
  DirU8 slideDir;                   // 0x3A7, 氷の床で滑っている向き, 滑り始めに facing を写し, 斜めで壁に当たると Player_GetSlideDeflectDir の向きに変わる
  Vec3 forcedDelta;                 // 0x3A8, useForcedDelta が 0 以外のとき Player_UpdateDjango が mover.delta にそのまま写す移動量
  Vec3 refuelPos;                   // 0x3B0, 太陽スタンドを使うときに歩いて立つ位置 (共闘サバタは PACT_SPIDER_WEB でうろつく先の座標に使い回す)
  u16 refuelFacing;                 // 0x3B8, refuelPos に着いたときに向く方向
  u16 unk_3ba;                      // 0x3BA, Cmd_E9E2 が 1 を書く
  u8 wallSidling;                   // 0x3BC, 壁張り付き (PACT_WALL) が横歩きの段階 (state 1) に入っているか, 立っている間だけ PACT_WALL 中に R で見回せる
  DirU8 actionDir;                  // 0x3BD, PACT_WALL / PACT_PUSH の基準方向, Player_EnterWall が設定して facing をその反対向きにし, Cmd_7017 は PACT_WALL / PACT_PUSH のときだけ facing の代わりに (actionDir + 4) & 7 を返す
  u16 wallPressTimer;               // 0x3BE, 氷でない床でまっすぐ壁に歩き当たっている連続フレーム数, 5 になった回に前方が十分高い壁なら PACT_WALL に入る
  Vec3 cameraLookAt;                // 0x3C0, カメラの注視点, mover.pos + lookAroundOffset (+150 上) と今の注視点を 1:4 で混ぜて作る
  Vec3 lookAroundOffset;            // 0x3C8, 見回し開始時のカメラ注視点からプレイヤーへのオフセット, val は見回しモード中か(0 or 1)
  u8 unk_3d0;                       // 0x3D0
  u8 unk_3d1;                       // 0x3D1
  bool8 blownAway;                  // 0x3D2, 今の被弾が吹き飛ばされるものか, Player_SetupKnockback が攻撃側の HBATTR_18 を見て立て, 被弾の行動を PACT_DAMAGED / PACT_DEATH_PRONE でなく PACT_BLOWN_AWAY / PACT_DEATH_SUPINE にする
  u8 unk_3d3;                       // 0x3D3, padding?
  u16 knockbackTimer;               // 0x3D4, 吹き飛ばされている間のカウンタ, 0x55 を超えた偶数フレームに効果音を鳴らす
  SoundID16 hurtSound;              // 0x3D6, 被弾の行動 (PACT_DAMAGED) に入るときに一度だけ鳴らす音, 吹き飛ばしなしは SONG_NONE, 通常は SE_DAMAGE, 引火と knockbackOrigin からの弾きは SE_IGNITE, 氷結は SE_SOLIDIFY
  u16 poisonTick;                   // 0x3D8, 毒(badCondTimer[1])が残っている間の経過フレーム, 60 ごとに damage を1増やす, Player_ApplyBadCondition が毒が切れると 0 を書く
  u16 inkaTick;                     // 0x3DA, 引火(ELEMCOND_INKA) の経過フレーム
  u16 sunburn;                      // 0x3DC, Player_StepSunburn が毎回 太陽ゲージ+2 を足し、100 を超えるたびに Player_TakeSunburnDamage を呼んで 100 引く
  u16 rainTick;                     // 0x3DE, 雨に当たっている間のフレーム数, 15 になるたびに煙を出してダメージを1増やす
  u16 desertTimer;                  // 0x3E0, 砂漠エリアでの経過フレーム, 120 ごとに damage を1増やす (エリア外では 120 を入れておく)
  u16 blackArmorTimer;              // 0x3E2, 黒の鎧を装備している間の経過フレーム, 15 ごとに damage を1増やす
  u16 heatstrokeTick;               // 0x3E4, gStat->heatstroke が 0 でない間毎フレーム 1 (2500 以上は 2) ずつ増え, 15 を超えるたびに煙を出して 0 に戻る
  u16 knockbackSpeed;               // 0x3E6, Player_SetupKnockback が相手の HitboxData.knockback を退避する, FUN_080835d8 が knockbackDir へ滑らせる速さに使い毎回 3/4 倍する
  DirU16 knockbackDir;              // 0x3E8, Player_SetupKnockback が入れる押し出し方向 (0..7), 攻撃の向きか攻撃側から離れる向き
  u16 unk_3ea;                      // 0x3EA, FUN_0807ad60 が 1 を書く
  u16 mashRecoverTimer;             // 0x3EC, PACT_UNK_18 から立ち直るまでの残り, 毎フレーム 1 (A/B/方向キーを押した瞬間は 2) 減って 0 で終わる, 0 以外の間は他の行動より PACT_UNK_18 を優先する
  u8 unk_3ee[0x3F0 - 0x3EE];        // 0x3EE
  u8 fallFadeMode;                  // 0x3F0, 落とし穴に落ちるときの画面フェード, 0 なら objSkipMask を 1, 0 以外は 16 にする, 2 以上ならフェードしない
  bool8 isMiniHuman;                // 0x3F1, ITEM_RED_MUSHROOM で体が縮んでいるか
  u8 dashVanish;                    // 0x3F2, 共闘サバタの経路移動で目的地が遠い間 0..5 で増減する消え具合, 5 で姿を消し 1 以上で点滅する
  u8 wallLockCount;                 // 0x3F3, 乗っている Entity71BA の上書きタイルの数, 0 以外の間は PACT_WALL に戻され Player_CanKeepWall が常に TRUE
  u8 unk_3f4[0x3F6 - 0x3F4];        // 0x3F4
  u16 floatHeight;                  // 0x3F6, human の表示高さに足す浮き上がり量
  s16 heightAboveTile;              // 0x3F8, action 23 に入った時点の pos.y から足元タイルの高さ(階段補正込み)を引いた値
  u8 magicFired;                    // 0x3FA, 魔法の発動フレームに Player_HasEnoughSunGauge (太陽ゲージ判定) の結果が入る, 1 のときだけ効果が生成され、以降のフレームの演出判定にも使われる
  u8 dynamiteCount;                 // 0x3FB, 生存中の DynamiteEffect の数, DynamiteEffect_Init が +1、消滅時に -1, MAGIC_DYNAMITE は 0 でないと再発動できない (Player_GetMagicAction)
  u8 dashSpeed;                     // 0x3FC, 太陽ゲージ*2+14 (上限32), Player_SetMoveDelta に渡す1フレームの移動量
  u8 dashFrames;                    // 0x3FD, 512 / dashSpeed, 移動距離を一定にするためのダッシュ継続フレーム数
  u8 grabbedVisible;                // 0x3FE, 掴まれている間 (PACT_GRABBED) 本体を見せるか, 0 なら PFLAG35A_HIDE_BODY も立てる
  s8 spiderWebIdx;                  // 0x3FF, 捕まっているクモの巣 (Entity080db520) の枠番号, 負なら捕まっていない, 0 以上の間は PACT_SPIDER_WEB に入る
  u8 mashCount;                     // 0x400, A / B / 方向キーを押した瞬間に +1 する連打のカウンタ (256 で一周), つかみや状態異常の振りほどきに使う
  u8 mashCountBase;                 // 0x401, 数え始めたときの mashCount, Player_GetMashCount が mashCount との差を返す
  u8 speedPenalty;                  // 0x402, 移動速度から引かれる量, Player_AddSpeedPenalty が +1 する
  u8 spinRounds;                    // 0x403, 共闘サバタの PACT_SPIDER_WEB の長さ (0 か 1 を乱数で), 構えを spinRounds+1 回繰り返し (spinRounds+1)*32 フレーム続ける
  u16 chargeVoiceTimer;             // 0x404, チャージが効き始めてからのフレーム数 (5 で止まる), 5 になった回に掛け声を鳴らす
  u8 unk_406[3];                    // 0x406
  u8 chargeSoundOn;                 // 0x409, チャージ音 (NOISE_SOLAR_CHARGE / NOISE_DARK_CHARGE) を鳴らしているか
  u8 unk_40a[2];                    // 0x40A
  bool8 mashHistory[32];            // 0x40C, 直近32フレームに mashKeys のどれかを押した瞬間があったか, 添字 0 が今フレーム, PACT_UNK_32 が毎フレームずらす
  Keys16 mashKeys;                  // 0x42C, mashHistory で数えるキー
  u16 mashHits;                     // 0x42E, mashHistory のうち押した瞬間があったフレームの数
  u16 mashAnimSpeed;                // 0x430, mashHits から決める PACT_UNK_32 のアニメ速度, mashHits が多いほど小さい (0 なら止まる)
  u8 unk_432[2];                    // 0x432
  u16 countdown;                    // 0x434, '.t=600', 画面に出すカウントダウンの残りフレーム数
  u16 timedCharge;                  // 0x436, スクリプトの時間制限チャージで貯めた量, ジャンゴは毎フレーム太陽ゲージぶん, 暗黒は 4 ずつ増え timedChargeGoal に届くと終わる
  u16 timedChargeGoal;              // 0x438, timedCharge の目標値, '.c=720'
  u16 noSunburn;                    // 0x43A, 0 以外なら日焼けダメージを受けない, Cmd_FD12 で立つ
  u16 badCondTimer[3];              // 0x43C, 時間経過で治る状態異常の残り時間 [0: 腹痛, 1: 毒, 2: 混乱]
  u16 goodCondID;                   // 0x442, よいステータス効果のID, see GOOD_XXXX (e.g. GOOD_NINJA)
  u16 goodFrom;                     // 0x444, よいステータス効果がどのアイテム由来か
  u16 goodCondTimer;                // 0x446, 0 でなければ goodCondID が有効
  bool8 berserkHitCounted;          // 0x448, この攻撃でバーサークの攻撃回数を数え済み, 攻撃の始めに 0 に戻す
  bool8 berserkHurt;                // 0x449, 黒ジャンゴが被弾した印, しきい値に届いていればバーサークの準備に変わる
  bool8 berserkReady;               // 0x44A, しきい値に届いたあと被弾してバーサークの準備ができた, 素立ちか歩きになるとバーサークに入る
  u8 shakeTimer;                    // 0x44B, human の表示位置を乱数で揺らす残りフレーム
  u8 unk_44c[0x456 - 0x44C];        // 0x44C
  s8 controlUp;                     // 0x456, 通常は gStat->controlUp が入るが、混乱(移動方向がおかしくなる状態異常)のときに書き換えられる
  u8 unk_457[0x464 - 0x457];        // 0x457
  u8 navAgentReady;                 // 0x464, navAgent が今の位置で初期化済みか, 0 なら次の更新で Map_InitNavAgent し直す
  u8 unk_465;                       // 0x465
  bool8 approachUsed;               // 0x466, 1 なら今の接近チャンスを使い切った状態, gPlayerPtr[0] の action が 0x15 でなくなると 0 に戻る
  u8 approachChance;                // 0x467, 1P が掴まれているときに助けに寄る確率 (%), '.r=50'
  u8 blockLimit;                    // 0x468, blockCount の上限
  u8 blockCount;                    // 0x469, PACT_REFUELING で弾いた回数, blockLimit に達すると弾き返す
  u8 namakuraLimit;                 // 0x46A, namakuraCount の上限
  u8 namakuraCount;                 // 0x46B, PACT_REFUELING で HBATTR_NAMAKURA の攻撃を受けた回数, namakuraLimit に達すると PACT_SPIDER_WEB に移る
  u8 blownLimit;                    // 0x46C, blownCount がこれに達すると pauseTime だけ止まる, '.G[0]=4'
  u8 blownCount;                    // 0x46D, 吹き飛ばされて起き上がった回数
  u8 slashDone;                     // 0x46E, PACT_ATTACK で斬り終えた回数, slashCount に達すると攻撃を終える
  u8 slashCount;                    // 0x46F, PACT_ATTACK で斬る回数 (2 か 3 を乱数で決める)
  u8 pathEndAction;                 // 0x470, 経路の終点に着いたときに移る action
  u8 pathEndFacing;                 // 0x471, 経路の終点に着いたときの facing
  s16 pauseTime;                    // 0x472, 止まる (PACT_UNK_18) フレーム数, '.G[1]=180'
  u16 pauseTimer;                   // 0x474, PACT_UNK_18 の残りフレーム, Emote_Show のゲージにも渡す, 0 以外の間は PACT_UNK_18 を続ける
  u8 blockFlashTimer;               // 0x476, 攻撃を弾いた (PACT_REFUELING) ときにパレット 306 で白く光らせる残りフレーム (4), 間は被弾の点滅をしない
  u8 unk_477;                       // 0x477
  WorldPos waypoints[4];            // 0x478, 巡回地点, val に着いたときの向きが入る
  PlayerFunc lockedUpdate;          // 0x498, mode == PMODE_LOCKED のときの update
  Vec3 moveTarget;                  // 0x49C, 操作不能中の移動ルーチンが向かう座標
  u16 knockbackSpeed_4a4;           // 0x4A4, スクリプト (Cmd_7A25 の '.f'=30) が入れる吹き飛びの速さ, 操作不能中の吹き飛び処理が向きの反対へ押し出しながら毎フレーム 3/4 に減らし 0 で止まる
  u8 unk_4a6;                       // 0x4A6, FUN_0807bc14 の第2引数
  u8 unk_4a7;                       // 0x4A7, FUN_0807c748 の第3引数
  u8 unk_4a8;                       // 0x4A8
  DirS8 targetDir;                  // 0x4A9, 操作不能中の移動や向き直りを終えたときに向く方向, 負なら向きを変えない
  u8 doneNotify;                    // 0x4AA, 操作不能中の処理を終えたときに Player_NotifyLockedDone が行う通知, see PlayerDoneNotify
  bool8 doneWaitPending;            // 0x4AB, 非0ならメッセージの待ちをまだ解いていない
  u8 plttPulsePhase;                // 0x4AC, 0..15 を巡回するパレットの明滅の位相, pltt の色 5/6/13 を作り直す
  u8 footHitboxOn;                  // 0x4AD, 0 以外なら Player_StepBurnSmoke が footHitboxTimer を数える
  u8 footHitboxTimer;               // 0x4AE, 8 フレームごとに Player_EmitBurnSmoke を呼ぶためのカウンタ
  u8 revertNotifyPending;           // 0x4AF, 黒ジャンゴに戻る演出を終えた印, 次の操作不能中の待機で Player_NotifyLockedDone を呼んで落とす
  s32 doneScriptID;                 // 0x4B0, '.e', 操作不能中の処理を終えたときに実行するスクリプト
  u8 unk_4b4[0x4BC - 0x4B4];        // 0x4B4
  Vec3 coffinShake;                 // 0x4BC, 棺桶の蓋を閉じるときの揺れ, beast.pos の x / z に足す, x に (乱数 & 0xF) - 7, z にその符号反転が入る, y と val は使われない
  ElementalCondEmitter emitter;     // 0x4C4
  Vec3 shadowPos;                   // 0x5FC, mover.pos に下の3つを足した値, 根拠: Player_UpdatePoseAndShadow
  Vec3 shadowOffset;                // 0x604, shadowPos を作るときに mover.pos に足す分, Player_BeginAction が 0 に戻す
  ParticleShadow shadow;            // 0x60C, 根拠: Player_DestroyEffects が ParticleShadow_Remove に渡す, Elevator_UpdatePlayerRiding がエレベータ搭乗中に flags の bit0 を立てる
  PlayerParticleGroup1 noise;       // 0x64C, 物音を表す漫符(小/大)のパーティクル
  PlayerParticleGroup1 spurl;       // 0x67C, 混乱(BAD_CONFUSE)したときにプレイヤーの頭上に PTCL1_CONFUSE を出すための Emitter
  PlayerShockwave meleeShockwave;   // 0x6AC
  PlayerEnchantPtcls enchantPtcls;  // 0x718
  PlayerChargePtcls chargePtcls;    // 0x858
  Vec3 chargePos;                   // 0x930, チャージの光が集まる点, 向きに応じて mover.pos から少しずらして高さ Q8(1.29) に置く
  u16 plttIDs[9];                   // 0x938, plttIdx で引くパレットIDの表, 根拠: Player_BuildPltt
  u16 basePlttID;                   // 0x94A, スプライトに割り当てる OBJ パレット番号, 1P は 29, 2P は 40 (共闘サバタは 39)
  s16 plttIdx;                      // 0x94C, pltt を作ったときの plttIDs の添字 (pose), 0xFFFF で次の更新に作り直させる
  u8 plttBrightness;                // 0x94E, pltt の全チャンネルに足す明るさ, Player_GetSunbathBrightness の値
  u8 unk_94f;                       // 0x94F
  u8 enchantColorIdx;               // 0x950, pltt の色 5/6/13 に今入っている 3色組の番号, 0xFF で次に必ず差し替える
  u8 nextEnchantColorIdx;           // 0x951, 次に使う 3色組の番号, エンチャントは enchantIdx + 1, なしは 0, 変わると enchantColorIdx に写して色を差し替える
  u16 altPose;                      // 0x952, Player_ApplyPoseHold が pose が変わったときに控える値
  u16 altPoseTimer;                 // 0x954, 変化時に 0x40 を入れて毎回 1 減らす, bit2 が立つ間は altPose を返す
  u16 badCondBlinkTimer;            // 0x956, Player_TickBadCondTimers が状態異常1の残り時間が切れたあと 0x40 から減らす点滅タイマ
  u16 sunDrainBlinkTimer;           // 0x958, 同じく太陽ゲージ消費側の点滅タイマ
  u16 flashPose;                    // 0x95A, flashTimer の bit2 が立っている間 Player_ApplyFlashPose が pose の代わりに返す値
  u16 flashTimer;                   // 0x95C, Player_ApplyFlashPose が毎フレーム 1 減らす点滅タイマ
  u16 flashPlttID;                  // 0x95E, plttFlashTimer の重みで pltt と混ぜるパレットの ID
  u16 plttFlashTimer;               // 0x960, enchantPlttID とプレイヤー自身のパレットのブレンドを pulse させるタイマ
  u16 enchantPlttID;                // 0x962, エレメントエンチャント時にプレイヤー自身のパレットとブレンドされるパレット
  u16 enchantPlttTimer;             // 0x964, 同じ呼び出しで 0x20 を入れる, enchantPlttID が 0 のときだけ 0 に戻される
  u8 unk_966[0x96C - 0x966];        // 0x966
  u16 lockedPlttFx;                 // 0x96C, 操作不能中のパレット演出, 0: なし, 1: flashPlttID へフェードイン, 2: 明滅
  u8 unk_96e[2];                    // 0x96E, padding?
  Vec3 damageNumOffset;             // 0x970, ダメージ / 回復の数字を mover.pos からずらして出すオフセット, 掴まれ中は当たった位置が入り, 数字を出したあと 0 に戻る
  u8 unk_978;                       // 0x978, 同じく第6引数
  bool8 enchantStarted;             // 0x979, エンチャントが始まったフレームだけ立つ, Player_Update が効果音を鳴らして 0 に戻す
  u16 shrink;                       // 0x97A, 縮み具合 0..64, GOOD_MINI の間 1 ずつ増え切れると 1 ずつ減る, human の拡縮は Q6(1) - shrink / 2
  u8 mosaicFrom[4];                 // 0x97C, MosaicFader_Start の from, 初期値は全部 4
  u8 mosaicTo[4];                   // 0x980, MosaicFader_Start の to, 初期値は全部 0
  u16 mosaicInterval[4];            // 0x984, 同じく interval, 初期値は全部 4
  struct Emote* emote;              // 0x98C
  u8 emoteKind;                     // 0x990, see EmoteKind
  u8 unk_991;                       // 0x991
  u16 emoteTimer;                   // 0x992, エモートを出しておく残りフレーム, 0 になった回に Emote_Show で消す, 0 なら時間では消さない
  MsgPacket selfMsg;                // 0x994, Player_SendMsgToSelf が組み立てて自分宛てに送るメッセージ, args は可変長なので後ろの unk_9a0 まで伸びる
  u8 unk_9a0[0x9BC - 0x9A0];        // 0x9A0
  u16 forbidFlags;                  // 0x9BC, スクリプト (Cmd_CD57 '.f') が立てる禁止ビット, bit0: 武器での攻撃, bit1: MAGIC_EARTH 以下の魔法, bit2〜: MAGIC_TRANSFORM 以降の魔法を1つずつ, 0x4000: 攻撃すべて
  u16 pad_9be;                      // 0x9BE, padding
  s32 forbidScriptID;               // 0x9C0, 禁止された攻撃を B で出そうとしたときに実行するスクリプト, '.p'
  s32 eventScriptID;                // 0x9C4, カーモス化 (0), 熱中症で倒れた (1), 黒ジャンゴの暴走 (2) のときに kind を引数にして実行するスクリプト, '.R'
  PlayerWeapon wpn;                 // 0x9C8, 装備中の武器と攻撃判定の一群, 根拠: 武器種ごとの攻撃処理が p + 0x9C8 を基点に読み書きする
  u16 chargeStepTime;               // 0xA90, サバタの攻撃 (PACT_ATTACK) で暗黒銃のチャージが1段上がるまでのフレーム数, 構えたときに 30 を入れる
  u16 solarGunTime;                 // 0xA92, 太陽銃を撃ってからチャージ中も数え続けるフレーム数, 15 を超えると黒ジャンゴは日焼けダメージを受けて 0 に戻る
  u8 unk_a94;                       // 0xA94
  u8 unk_a95;                       // 0xA95, アストロ武器の種類ごとの値 (剣: 0, 槍: 4, 槌: 8)
  u8 unk_a96[2];                    // 0xA96, padding?
  PlayerFunc attackCB;              // 0xA98, sPlayerAttackUpdates

  // 武器の特殊効果のコールバック関数の配列
  u32 (*weaponExDamageCb[WEAPON_EFFECT_SLOT_COUNT])(struct Player*);                               // 0xA9C, プレイヤーの状態を参照する武器の特殊効果コールバック
  u32 (*weaponEffectCb2[WEAPON_EFFECT_SLOT_COUNT])(struct Player*);                                // 0xAA8, 状態を参照しない武器の特殊効果コールバック, 防御無視効果と麻痺のハンドラはここ
  u32 (*weaponEffectCb3[WEAPON_EFFECT_SLOT_COUNT])(struct Player*, HitboxData* a, HitboxData* b);  // 0xAB4, 敵の状態を参照する武器の特殊効果コールバック, xx特効系のハンドラはここ, 戻り値は b->damage に足す

  PlayerFunc updateCallback;  // 0xAC0
} Player;
static_assert(sizeof(Player) == 2756);

// 8方向の dir8 からアニメの向きオフセット (0..4) と左右反転を決める, 5..7 は 3..1 を左右反転して使う
#define PLAYER_SET_ANIM_8DIR(p, dir8) \
  ({                                  \
    if (IS_8DIR_LEFT(dir8)) {         \
      (p)->animDir = 8 - (dir8);      \
      (p)->xflip = TRUE;              \
    } else {                          \
      (p)->animDir = (dir8);          \
      (p)->xflip = FALSE;             \
    }                                 \
  })

// 同上, ただし向きを2方向ずつまとめてオフセットを 0..2 にする (アニメが3方向ぶんしかない姿用)
#define PLAYER_SET_ANIM_4DIR(p, dir8)   \
  ({                                    \
    if (IS_8DIR_LEFT(dir8)) {           \
      (p)->animDir = (8 - (dir8)) >> 1; \
      (p)->xflip = TRUE;                \
    } else {                            \
      (p)->animDir = (dir8) >> 1;       \
      (p)->xflip = FALSE;               \
    }                                   \
  })

// ------------------------------------------------------------------------------------------------------------------------------------

extern u16 gPlayerCount;
extern Player* gPlayerPtr[4];
extern u16 gGoodCondID;             // 0x03002B60
extern u16 gConfusedDir;            // 0x03002B64
extern u16 gPlayerMoverIDs[4];      // 0x03002B68, 多分プレイヤーの moverID
extern u16 gGoodCondTimer;          // 0x03002B8C, Player.goodCondTimer の退避, 他Entityからの参照用
extern PlayerMode gPlayerModes[4];  // 0x03002BC0, プレイヤーごとの Player.mode の写し (see PlayerMode)
extern u16 gWindAngle;
extern u16 gRisingSunCount;  // 0x03002BF0

void FUN_0807a524(Vec3* pos);
void Player_AddENE(Player* p, s32 amount);
s32 Player_GetAttackPower(Player* player);
s32 FUN_080d1b04(Player* player);
void Player_ReduceENE(Player* player, s32 amount);
void Player_Unlock(Player* p);
void Player_LockPullCoffinTo(Player* p, Vec3* pos, DirS32 dir, s32 param_4, u32 scriptID);
void FUN_0807bc64(Player* p, u32 scriptID);
void Player_ApplyBadCondition(Player* p, s32 badcondID, s32 frames);
void Player_AddWeaponExp(u32 mask, s32 amount);
void Player_ClearBadCondition(Player* p, s32 badcondID);
void Player_RefreshAllStats(Player* p);
void Player_EquipMagic(Player* p, magic32_t n);
u32 Player_GetAnimIdx(s32 playerKind, s32 idx);
void Player_SetPosAndSave(Player* p, Vec3* pos);
s32 Player_TakeInstantHit(Player* p, s32 power, s32 knockback, s32 angle, s32 iframes, HitboxAttributes attrs);
void Player_EnterDeadState(Player* p);
bool32 FUN_0807ad60(Player* p, s32 param_2);
DirS32 Player_GetDpadFacing(Player* p);
void AddPlayerExp(s32 amount);
void Player_MoveTo(Player* p, Vec3* pos, u32 scriptID, DirS32 dir);

bool32 Player_TestElevatorFlags(Player* p, ElevatorFlagsU16 mask);
void Player_SetElevatorFlags(Player* p, u32 flags, u32 elevatorID);
void Player_ClearElevatorFlags(Player* p, u32 flags);
void Player_SetKnockbackOrigin(Player* p, Vec3* origin);
s32 Player_HoldGrabbed(Player* p, Vec3* pos, Vec3* hitPos, s32 animOffset, s32 xflip, s32 flashPose, bool32 hidden, s32 power, HitboxAttributes attrs);
s32 Player_ReleaseGrabbed(Player* p, Vec3* pos, s32 knockback, s32 angle, s32 iframes, s32 flashPose, s32 power, HitboxAttributes attrs);

static inline void Player_SetFlag20(Player* p, PlayerFlag20 bit) { p->flag20 |= bit; }
static inline bool32 Player_TestFlag20(Player* p, PlayerFlag20 bit) { return p->flag20 & bit; }

static inline void Player_SetEquipBuff(Player* p, EquipBuffs bits) { p->equipBuffs |= bits; }
static inline void Player_ClearEquipBuff(Player* p, EquipBuffs bits) { p->equipBuffs &= ~bits; }
static inline bool32 Player_TestEquipBuff(Player* p, EquipBuffs bits) { return p->equipBuffs & bits; }

#endif  // GUARD_ZOKTAI_PLAYER_H
