#ifndef __INCLUDE_EFF_SCATTER_H__
#define __INCLUDE_EFF_SCATTER_H__

#include "gba/gba.h"
#include "particle.h"
#include "types.h"

// ScatterEffect_Spawn / ScatterEffect_SpawnAtAngle の kind, 下位8bit が粒子の種類 (sScatterTileOffsets の添字) で, 9 未満は床で跳ね, 21 以上は PTCL_GROUP_2 の絵を使う
#define SCATTER_KIND_0 0
#define SCATTER_KIND_1 1
#define SCATTER_ICE 2    // 氷のかけら, 凍結魔法, 氷結の解除, 氷のブロック
#define SCATTER_STONE 3  // 石のかけら, 石化の解除, 落石, 壊せる岩
#define SCATTER_CLAY 4   // 敵がやられたときの破片 (FUN_080f8abc が variant 0 などで返す)
#define SCATTER_KIND_5 5
#define SCATTER_KIND_6 6
#define SCATTER_KIND_7 7
#define SCATTER_CONFUSE 8   // PTCL1_CONFUSE の絵
#define SCATTER_KIND_9 9    // クモ (variant 0), Jormungandr, Larva が吐き出すもの
#define SCATTER_KIND_10 10  // クモ (variant 0 以外) が吐き出すもの
#define SCATTER_KIND_11 11  // タコが吐き出すもの
#define SCATTER_KIND_12 12
#define SCATTER_KIND_13 13
#define SCATTER_KIND_14 14
#define SCATTER_KIND_15 15
#define SCATTER_KIND_16 16
#define SCATTER_KIND_17 17  // 錆びたレバーを叩いたとき, 蜂の巣の破片
#define SCATTER_KIND_18 18
#define SCATTER_KIND_19 19
#define SCATTER_KIND_20 20
#define SCATTER_KIND_21 21
#define SCATTER_KIND_22 22
#define SCATTER_SOL_L 23    // ソル(大)
#define SCATTER_SOL_S 24    // ソル(小), 鍛冶で伝説の武器 (グラム, グングニル, ミョルニル) ができたとき
#define SCATTER_DARK_L 25   // ダーク(大)
#define SCATTER_DARK_S 26   // ダーク(小)
#define SCATTER_FLAME_L 27  // フレイム(大)
#define SCATTER_FLAME_S 28  // フレイム(小)
#define SCATTER_FROST_L 29  // フロスト(大)
#define SCATTER_FROST_S 30  // フロスト(小)
#define SCATTER_CLOUD_L 31  // クラウド(大)
#define SCATTER_CLOUD_S 32  // クラウド(小)
#define SCATTER_EARTH_L 33  // アース(大)
#define SCATTER_EARTH_S 34  // アース(小)
#define SCATTER_KIND_35 35
#define SCATTER_KIND_36 36
#define SCATTER_KIND_37 37  // SCATTER_DARK_S と同じ絵
#define SCATTER_KIND_38 38  // FUN_08044a90 (Actor)
#define SCATTER_SHADOW 39   // 床で跳ねる粒子の影, kind としては渡さない

// kind の上位8bit で粒子の描画優先度を指定する, 指定しなければ 2
#define SCATTER_PRIORITY(n) (((n) + 1) << 8)

/**
 * @brief 空いている ScatterBurst を1つ使い, pos から count 個の破片を乱数つきの速度で撒く
 * @param count 粒子の数, 8 を超える分は切り捨てる
 * @param kind 下位8bit が SCATTER_* の種類, 上位8bit が SCATTER_PRIORITY(n) で指定する描画優先度 (省略すると 2)
 * @param pos 撒き始める位置
 * @param vel 速度の基準, y は上向きで, 撒いた後は重力で毎フレーム 1 ずつ減る
 * @param velRange 軸ごとに vel へ足す乱数の幅 (0..velRange-1), 0 の軸は vel のまま
 * @param lifeBase 寿命 (フレーム) の基準
 * @param lifeRandMask 寿命に足す乱数のマスク, 寿命は lifeBase + (乱数 & lifeRandMask)
 * @return ScatterEffect を作れなければ -1, それ以外は 0 (ScatterBurst の空きが無くて撒けなかったときも 0)
 */
s32 ScatterEffect_Spawn(s32 count, s32 kind, Vec3* pos, Vec3* vel, Vec3* velRange, s32 lifeBase, s32 lifeRandMask);

/**
 * @brief 空いている ScatterBurst を1つ使い, pos から count 個の破片を angle を中心とした扇の向きへ撒く
 * @param count 粒子の数, 8 を超える分は切り捨てる
 * @param kind 下位8bit が SCATTER_* の種類, 上位8bit が SCATTER_PRIORITY(n) で指定する描画優先度 (省略すると 2), 21 以上の種類は PTCL_GROUP_2 の次のパレットを使う
 * @param pos 撒き始める位置
 * @param angle 撒く向きの中心 (0..255)
 * @param angleRange 扇の幅, 向きは angle - angleRange / 2 から angleRange の範囲の乱数で決まる, 0 なら angle ちょうど
 * @param speed 水平方向の速さの基準
 * @param speedRange speed に足す乱数の幅 (0..speedRange-1)
 * @param velY 上向きの速度の基準, 撒いた後は重力で毎フレーム 1 ずつ減る
 * @param velYRange velY に足す乱数の幅 (0..velYRange-1)
 * @param lifeBase 寿命 (フレーム) の基準
 * @param lifeRandMask 寿命に足す乱数のマスク, 寿命は lifeBase + (乱数 & lifeRandMask)
 * @return ScatterEffect を作れなければ -1, それ以外は 0 (ScatterBurst の空きが無くて撒けなかったときも 0)
 */
s32 ScatterEffect_SpawnAtAngle(s32 count, s32 kind, Vec3* pos, s32 angle, s32 angleRange, s32 speed, s32 speedRange, s32 velY, s32 velYRange, s32 lifeBase, s32 lifeRandMask);

#endif  // __INCLUDE_EFF_SCATTER_H__
