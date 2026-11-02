#ifndef __INCLUDE_CONSTANTS_SPRITE_PALETTE_H__
#define __INCLUDE_CONSTANTS_SPRITE_PALETTE_H__

// スプライトのパレットID (plttID, obpID)
// ID が plttID なら gObjPlttData[plttID * 16] のパレットを指す

// プレイヤーに特殊効果が付くときに, プレイヤーの元のパレットとブレンドして使う (代表例は、エレメントのエンチャント)
// 0..6, 0: ソル, 1: ダーク, 2: フレイム, 3: フロスト, 4: クラウド, 5: アース, 6: ルナ
// 特に 0 (ソル) は良い効果がかかった時の汎用カラー としてよく使われる
#define OBP_ELEMENT(elementColor) (289 + (elementColor))

#define OBP_COFFIN(coffinID) (519 + (coffinID))

#endif  // __INCLUDE_CONSTANTS_SPRITE_PALETTE_H__
