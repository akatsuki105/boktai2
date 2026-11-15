#ifndef __INCLUDE_HITBOX_H__
#define __INCLUDE_HITBOX_H__

#include "gba/gba.h"
#include "types.h"

// Hitbox.flags
typedef u16 HitboxFlags;
typedef u32 HitboxFlags32;
#define HBF_DAMAGE (1 << 0)    // 0x1, ダメージを伴う攻撃につく, 付いていない攻撃判定はフリーズとヒーリングだけ, 食らい側に立っているとこれが付いた攻撃にしか当たらない (Hitbox_CheckAllPairs)
#define HBF_SENSOR (1 << 1)    // 0x2, 重なっても相手側のハンドラは呼ばず自分のハンドラだけが呼ばれる (Hitbox_CheckAllPairs), スケルトンの dodgeHurtbox やシェードマンの hurtbox2 のような当たったことを感知するための判定につく
#define HBF_HIDDEN (1 << 2)    // 0x4, 一時的に食らい判定を外すためのフラグ？, 食らい側に立っていると、どの攻撃とも判定せず center も更新しない (Hitbox_CheckAllPairs, Hitbox_UpdateBoxes)
#define HBF_3 (1 << 3)         // 0x8
#define HBF_4 (1 << 4)         // 0x10
#define HBF_5 (1 << 5)         // 0x20, 用途不明, 太陽タケノコについていた
#define HBF_6 (1 << 6)         // 0x40
#define HBF_7 (1 << 7)         // 0x80
#define HBF_ANGLE (1 << 8)     // 0x100, 向きの概念があるものにつける, バックアタックの判定, 攻撃のノックバック方向 などで利用
#define HBF_9 (1 << 9)         // 0x200, 攻撃側の OnHit が相手の HBHITSTATE_UNK_0 を立てたときだけダメージが通り, Django_OnHurt がそれを消費する, マミーの掴み・ゴーレムの転がり・Entity081e9cac が使う
#define HBF_ONCE (1 << 10)     // 0x400, 1フレームに1回だけ当たる, 相手の HBHITSTATE_ONCE_HIT で弾き (Django_OnHurt), Player_BeginAction が毎フレーム落とす, 敵の攻撃判定 (Enemy_InitAtkHitbox) につく
#define HBF_BLOCK (1 << 11)    // 0x800, 動かせるブロックとプロパティキューブの攻撃判定につく, コウモリ・ハチ・カラス・犬・ゴースト・棺桶は無視し, スライムは押し出される
#define HBF_ACTOR (1 << 12)    // 0x1000, プレイヤーと敵の食らい判定につく, 攻撃判定に立っていると HBF_ACTOR 付きの食らい判定にしか当たらない (Hitbox_CheckAllPairs)
#define HBF_HITBOX (1 << 13)   // 0x2000, 攻撃判定 (このフラグがセットされていたら hitbox, そうでないなら食らい判定(hurtbox)として扱っているっぽい, つまり下の HBF_HURTBOX は意味がなさそう)
#define HBF_HURTBOX (1 << 14)  // 0x4000, 食らい判定 (開発用の目印かも？ このフラグを参照しているものが見つからない)

// Hitbox.hitResult, Hitbox_ApplyDamage が書く当たり方の結果, 受けた側がリアクションを変えるのに使う, 0 以外なら「被弾した」の印にもなる (敵は Enemy.unk_48c に写し, 無敵時間中は 0 に戻して打ち消す)
typedef u8 HitboxHitResult8;
#define HBRESULT_NORMAL (1 << 0)  // 0x1, 等倍また は 5/4倍
#define HBRESULT_RESIST (1 << 1)  // 0x2, 軽減されて 1/4倍, ジャンゴの場合は属性系の状態異常(引火, 氷結)も防ぐ
#define HBRESULT_WEAK (1 << 2)    // 0x4, 4倍ダメージ, 敵はこれが立つと通常の被弾の声 (PlayEnemyDamageCry) を鳴らさない
#define HBRESULT_BONUS (1 << 3)   // 0x8, 1.5倍の追加補正を適用済み, 背後から当てたとき、 黒ジャンゴが夜にエンチャントダークの攻撃を当てたとき に立つ, 敵の一部 (ボク・犬・コカトリス) はひるみ, リンゴ・シェードマンも反応する

// Hitbox.hitState, 多段ヒットを抑えるために相手の攻撃側 flags と組で見る
typedef u8 HitboxHitState8;
#define HBHITSTATE_UNK_0 (1 << 0)     // 0x1, 相手の HBF_9 が消費する
#define HBHITSTATE_ONCE_HIT (1 << 1)  // 0x2, このフレームで HBF_ONCE の攻撃に1回当たった印, Player_BeginAction が毎フレーム落とす

typedef u32 HitboxAttrs;                 // 低位7bitが自分の属性マスク, 攻撃側の属性と守備側の耐性を兼ねる, bit7-11 は Django_OnWeaponHit が別の用途で見る
#define HBATTR_SOL (1 << 0)              // 0x1, ソル属性
#define HBATTR_DARK (1 << 1)             // 0x2, ダーク属性
#define HBATTR_FLAME (1 << 2)            // 0x4, 炎属性 (a.k.a. フレイム属性)
#define HBATTR_FROST (1 << 3)            // 0x8, 氷属性 (a.k.a. フロスト属性)
#define HBATTR_CLOUD (1 << 4)            // 0x10, 風属性 (a.k.a. クラウド属性)
#define HBATTR_EARTH (1 << 5)            // 0x20, 地属性 (a.k.a. アース属性)
#define HBATTR_ALL (1 << 6)              // 0x40, 全属性
#define HBATTR_ELEMENT_MASK 0x7F         // bit0-6, 属性 (HBATTR_SOL..HBATTR_ALL) の部分
#define HBATTR_BEAST (1 << 7)            // 0x80, ビースト系の敵
#define HBATTR_THING (1 << 8)            // 0x100, シング系の敵
#define HBATTR_PHANTOM (1 << 9)          // 0x200, ファントム系の敵
#define HBATTR_UNDEAD (1 << 10)          // 0x400, アンデッド系の敵
#define HBATTR_IMMORTAL (1 << 11)        // 0x800, イモータル系の敵
#define HBATTR_NAMAKURA (1 << 12)        // 0x1000, 防御力無視の攻撃
#define HBATTR_IGNORE_ELEMENT (1 << 13)  // 0x2000, 守備側の属性を無視する, 耐性も弱点も効かず常に 5/4倍 (Hitbox_ApplyDamage)
#define HBATTR_SEKIKA (1 << 14)          // 0x4000, (プレイヤーに)当たると石化の状態異常
#define HBATTR_POISON (1 << 15)          // 0x8000, 当たると毒になる (EBUFF_IMMUNEPOISON なら防ぐ)
#define HBATTR_16 (1 << 16)              // 0x10000, ???
#define HBATTR_17 (1 << 17)              // 0x20000, 当たると Player_HandleHurt が SpawnBlood を呼ぶ
#define HBATTR_18 (1 << 18)              // 0x40000, ???
#define HBATTR_19 (1 << 19)              // 0x80000, ???
#define HBATTR_CONFUSE (1 << 20)         // 0x100000, 当たると混乱になる
#define HBATTR_INKA (1 << 21)            // 0x200000, (プレイヤーに)当たると引火の状態異常
#define HBATTR_HYOKETU (1 << 22)         // 0x400000, (プレイヤーに)当たると氷結の状態異常

// 攻撃判定 (HBF_HITBOX が立っている場合) の Hitbox.typeMask, その攻撃の種別を表す
#define HBSRC_SWORD (1 << WK_SWORD)    // 0x1, 剣, bit0-4 は武器の種類で Player_AddWeaponExp が経験値を入れる武器を選ぶ
#define HBSRC_SPEAR (1 << WK_SPEAR)    // 0x2, 槍
#define HBSRC_HAMMER (1 << WK_HAMMER)  // 0x4, 槌, 錆びたレバースイッチなどがこれをチェックする
#define HBSRC_FIST (1 << WK_OTHERS)    // 0x8, 拳
#define HBSRC_GUN (1 << WK_GUN)        // 0x10, 銃, コカトリスの石化光線もこれ
#define HBSRC_NON_WEAPON (1 << 6)      // 0x40, 武器以外の攻撃 (爆発, 火炎放射)
#define HBSRC_7 (1 << 7)               // 0x80, ゴーレムの攻撃
#define HBSRC_8 (1 << 8)               // 0x100, 設定元は見つかっていない, 太陽タケノコが 0x40 / 0x80 と合わせて無視する
#define HBSRC_9 (1 << 9)               // 0x200, 使っている箇所は見つかっていない
#define HBSRC_10 (1 << 10)             // 0x400, 使っている箇所は見つかっていない
#define HBSRC_11 (1 << 11)             // 0x800, コカトリスの攻撃
#define HBSRC_12 (1 << 12)             // 0x1000, リンゴのコウモリ (RingoBatSwarm), サバタは太陽スタンド使用中にこれを受けると弾く
#define HBSRC_13 (1 << 13)             // 0x2000, 落下物 (FallingObject) と氷の破片 (Entity7B9F)
#define HBSRC_MFREEZE (1 << 14)        // 0x4000, 魔法"フリーズ"
#define HBSRC_MHEALING (1 << 15)       // 0x8000, 魔法"ヒーリング" (HealingEffect), 太陽の根・ハスの葉がこれを受けて育つ

// Hitbox.ignoreMask
#define HIM_0 (1 << 0)  // 0x1
#define HIM_1 (1 << 1)  // 0x2
#define HIM_2 (1 << 2)  // 0x4
#define HIM_3 (1 << 3)  // 0x8
#define HIM_4 (1 << 4)  // 0x10
#define HIM_5 (1 << 5)  // 0x20

// 当たり判定も食らい判定も同じ構造体で扱う, HBF_HITBOX で攻撃判定かどうかを区別する
typedef struct Hitbox {
  struct Hitbox* next;                                          // 0x00, HitboxManager の targets / attacks リストで次の Hitbox, どちらに繋がるかは HBF_HITBOX で決まる, 末尾は NULL
  u16 id;                                                       // 0x04
  HitboxFlags flags;                                            // 0x06, see HitboxFlags
  u16 unk_8;                                                    // 0x08
  u16 ignoreMask;                                               // 0x0A, ((this.ignoreMask & other.ignoreMask) == 0) なら、Overlap 判定を行う, != 0 でなく == 0 に注意
  WorldPos pos;                                                 // 0x0C, Hitbox_SetPos が毎フレーム書く判定の基準位置
  Vec3 offset;                                                  // 0x14, pos からのずれ
  Vec3 halfSize;                                                // 0x1C, 判定の直方体の各軸の半径, Hitbox_Init が引数の Vec3 を8バイトまるごとコピーする
  WorldPos center;                                              // 0x24, 判定の直方体の中心, Hitbox_UpdateBoxes が毎フレーム pos + offset で作る
  Vec3 unk_2c;                                                  // 0x2C, ShadeManCrossover_OnHurt が 8 バイトまるごと写す
  u32 typeMask;                                                 // 0x34, 攻撃判定(HBF_HITBOX) では 攻撃元の種別 (HBSRC_*), 食らい判定では弱点属性 (HBATTR_* の bit0..6)
  HitboxAttrs attributes;                                       // 0x38, see HitboxAttrs
  u16 power;                                                    // 0x3C, Hitbox_ApplyDamage の基礎ダメージ = a->power - b->power (1未満なら1), 攻撃側では攻撃力、守備側では防御力
  u16 damage;                                                   // 0x3E, 発生したダメージ
  u16 knockback;                                                // 0x40, ノックバック量
  u8 angle;                                                     // 0x42, 8bit の向き
  HitboxHitResult8 hitResult;                                   // 0x43, see HBRESULT_*
  u16 iframes;                                                  // 0x44, 攻撃側では当てた相手に与える無敵時間, 食らい側では残りの無敵時間 (毎フレーム減り,0でない間は食らわない), 被弾時に Player_HandleHurt / EnemyBat_OnHurt が a から b へそのままコピーする
  HitboxHitState8 hitState;                                     // 0x46, 多段ヒット管理, see HBHITSTATE_*
  u8 unk_47;                                                    // 0x47, Hitbox_Init が 1 にする, 読み手が見つかっていない
  void (*fn)(struct Hitbox* a, struct Hitbox* b, void* owner);  // 0x48, a: 攻撃側, b: 被攻撃側, owner: このHitboxの持ち主 (大抵 a->owner or b->owner のどちらか)
  void* owner;                                                  // 0x4C, このHitboxの持ち主
} Hitbox;
static_assert(sizeof(Hitbox) == 80);

static inline void Hitbox_SetFlags(Hitbox* hitbox, HitboxFlags flags) { hitbox->flags |= flags; }
static inline void Hitbox_ClearFlags(Hitbox* hitbox, HitboxFlags flags) { hitbox->flags &= ~flags; }
static inline HitboxFlags Hitbox_TestFlags(Hitbox* hitbox, HitboxFlags flags) { return hitbox->flags & flags; }
static inline void Hitbox_Hide(Hitbox* hitbox) { hitbox->flags |= HBF_HIDDEN; }
static inline void Hitbox_SetHalfSize(Hitbox* hitbox, Vec3* halfSize) { hitbox->halfSize = *halfSize; }
static inline bool32 Hitbox_HasSource(Hitbox* hitbox, u32 mask) { return hitbox->typeMask & mask; }  // 攻撃判定の typeMask (攻撃元の種別) を調べる, mask も HBATTR_* ではなく HBSRC_* などの攻撃元のビットで指定する
static inline u32 Hitbox_TestAttr(Hitbox* hitbox, HitboxAttrs mask) { return (hitbox->attributes & mask); }
static inline s32 Hitbox_GetDamage(Hitbox* hb) { return hb->damage; }
static inline void Hitbox_ClearDamage(Hitbox* hb) { hb->damage = 0; }
static inline void Hitbox_SetAttackPower(Hitbox* hitbox, s32 power) { hitbox->power = power; }  // 攻撃判定の攻撃力だけを差し替える

void Hitbox_Register(Hitbox* p);
void Hitbox_Init(Hitbox* p, u16 id, HitboxFlags32 flags, u32 unk_8, u16 ignoreMask, Vec3* halfSize, Vec3* offset);
void Hitbox_SetPos(Hitbox* p, Vec3* pos, u32 unk_8);
void Hitbox_SetPower(Hitbox* p, s32 power, s32 knockback);
void Hitbox_SetAttack(Hitbox* p, s32 power, s32 knockback, s32 source, HitboxAttrs attrs, s32 iframes);  // source には攻撃元の種別 (HBSRC_* など, see Hitbox.typeMask) を渡す
void Hitbox_SetPowerAndAttributes(Hitbox* p, u32 power, HitboxAttrs attrs, u32 weakness);                // weakness には食らい判定の弱点の属性 (HBATTR_*, see Hitbox.typeMask) を渡す
void Hitbox_SetHandler(Hitbox* p, void* handler, void* owner);
void Hitbox_Unregister(Hitbox* p);
void Hitbox_ApplyDamage(Hitbox* a, Hitbox* b);

s32 CreateDamageNumber(Hitbox* hitbox, s32 amount, s32 kind, Vec3* pos, Vec3* param_5, s32 priority);

#endif  // __INCLUDE_HITBOX_H__
