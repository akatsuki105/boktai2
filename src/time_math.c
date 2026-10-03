#include "global.h"
#include "time.h"

// 多分、緯度経度に基づいた計算処理 (f64 を多用する, asm直書きの関数もあるかも)
// Time_SetLocation が gClock に書き込みをしているので時間関連であることは確か

/**
 * @brief 日付から修正ユリウス日 (MJD) を求める, MJD は 太陽の位置計算の基準日として使われる
 * @param year 西暦の年, 2026年なら 2026 をそのまま渡す
 * @param month 1..12, 1月と2月は前年の13月と14月として扱われる
 * @param day 1..31
 * @return MJD, 1858/11/17 を 0 とする通算日数, 途中の計算で切り捨てが入るので小数部は出ず常に整数値になる
 * @note (1858, 11, 17) -> 0, (2000, 1, 1) -> 51544, (2026, 10, 2) -> 61315
 */
NAKED f64 Time_GetModifiedJulianDate(s32 year, s32 month, s32 day) { INCFUNC("asm/func/Time_GetModifiedJulianDate.inc"); }

/**
 * @brief 黄道傾斜角を求める, 黄道座標から赤道座標へ直すのに使う
 * @param mjd 修正ユリウス日
 * @return 黄道傾斜角 (度), 23.4393 - 0.0130 * T に章動の補正項を足したもの (T は J2000 からのユリウス世紀)
 */
NAKED f64 Time_GetEclipticObliquity(f64 mjd) { INCFUNC("asm/func/Time_GetEclipticObliquity.inc"); }

/**
 * @brief 月の黄経を求める
 * @param mjd 修正ユリウス日
 * @return 月の黄経 (度), 平均黄経 218.317 + 481268 * T に周期項を足したもの
 */
NAKED f64 Time_GetMoonLongitude(f64 mjd) { INCFUNC("asm/func/Time_GetMoonLongitude.inc"); }

/**
 * @brief 太陽の黄経を求める
 * @param mjd 修正ユリウス日
 * @return 太陽の黄経 (度), 平均黄経 280.46 + 360.008 * y に中心差と章動の補正を足したもの (y は J2000 からの年数)
 */
NAKED f64 Time_GetSunLongitude(f64 mjd) { INCFUNC("asm/func/Time_GetSunLongitude.inc"); }

/**
 * @brief 太陽の黄緯を求める
 * @param mjd 修正ユリウス日, 読まれない
 * @return 常に 0.0, 太陽は定義上ほぼ黄道上にあるので補正していない
 */
f64 Time_GetSunLatitude(f64 mjd) { return 0.0; }

/**
 * @brief 日付から月齢を計算する, 月の黄経と太陽の黄経の差を朔望月で日数に直したもの
 * @param out 読まれない, 呼び出し元が Time_GetModifiedJulianDate などと同じ構造体を渡している
 * @param year 西暦の年
 * @param month 1..12
 * @param day 1..31
 * @return 月齢 (日), 0.0 以上 29.5523 未満
 */
NAKED f64 Time_CalcMoonAge(unknown* out, s32 year, s32 month, s32 day) { INCFUNC("asm/func/Time_CalcMoonAge.inc"); }

/**
 * @brief 太陽の黄経・黄緯・黄道傾斜角から観測地点での位置を出し、out に角度を f64 で書き込む
 * @param out 書き込み先, +0x18 / +0x20 / +0x28 などに f64 が入る (構造体は未解析)
 * @param flag 1 と比べて経路が分かれる, 日の出側か日の入側かの選択と思われる
 * @param mjd 修正ユリウス日
 * @param n 呼び出し元が日数を整数に直して渡す
 * @param longitude 経度 (度)
 * @param latitude 緯度 (度)
 * @note 1.58563 rad = 90.85 度は日の出・日の入の定義に使う天頂距離 (大気差と視半径の補正込み)
 */
NAKED void FUN_0823f618(unknown* out, s32 flag, f64 mjd, s32 n, f64 longitude, f64 latitude) { INCFUNC("asm/func/FUN_0823f618.inc"); }

/**
 * @brief 日付と観測地点から日の出・日の入の時刻と月齢を求め、Time_SetMorning / Time_SetSunset / Time_SetMoonAge で gClock に入れる
 * @param year 西暦の年
 * @param month 1..12
 * @param day 1..31
 * @param latitudeHi 緯度 (度) の f64 の上位ワード, f64 1個が r3 とスタックに跨るので2つに割って宣言している
 * @param latitudeLo 緯度 (度) の f64 の下位ワード
 * @param longitude 経度 (度), 東経が正
 * @param tz 協定世界時からの時差 (時)
 * @return 常に 0
 */
NAKED s32 Time_UpdateSunAndMoon(s32 year, s32 month, s32 day, s32 latitudeHi, s32 latitudeLo, f64 longitude, s32 tz) { INCFUNC("asm/func/Time_UpdateSunAndMoon.inc"); }

/**
 * @brief 観測地点を gClock に設定し、現在の日付で日の出・日の入・月齢を引き直す
 * @param latitude 緯度, 16.16 固定小数の度
 * @param longitude 経度, 16.16 固定小数の度, 東経が正
 * @param tz 協定世界時からの時差 (時)
 * @return Time_UpdateSunAndMoon の戻り値 (常に 0)
 */
NAKED s32 Time_SetLocation(s32 latitude, s32 longitude, s32 tz) { INCFUNC("asm/func/Time_SetLocation.inc"); }
