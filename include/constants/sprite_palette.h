#ifndef __INCLUDE_CONSTANTS_SPRITE_PALETTE_H__
#define __INCLUDE_CONSTANTS_SPRITE_PALETTE_H__

// スプライトのパレットID (plttID, obpID)
// ID が plttID なら gObjPlttData[plttID * 16] のパレットを指す

#define OBP_EMBLEM_BLOCK(idx) (2 + (idx))  // 紋章ブロック, idx は 0..3 (0: 赤緑(暗), 1: 青紫(暗), 2: 赤緑(明), 3: 青紫(明))

#define OBP_RDJANGO 29  // 赤ジャンゴのベースカラー
#define OBP_POISON 32   // 毒時
#define OBP_KAAMOS 33   // カーモス
#define OBP_BDJANGO 38  // 黒ジャンゴのベースカラー
#define OBP_SABATA 39   // サバタのベースカラー

#define OBP_HINT_PANEL(level) (76 + (level))  // ヒントパネル, 0: 光っている, 1: 中間, 2: 通常

#define OBP_MIRROR 87  // 太陽ミラー

#define OBP_MSQUARE(color) (97 + (color * 3))  // 魔方陣, color は 0: 黄赤, 1: 赤青, 2: 紫緑, 3: 黒紫, 間の 0..2 が明るさ

#define OBP_PROPERTY_CUBE(prop) (120 + (prop))  // 0: 属性なし, 1: フレイム, 2: フロスト, 3: アース, 4: クラウド

#define OBP_TOMBSTONE 139

#define OBP_RINGO(idx) (195 + (idx))  // 0: ??, 1: BOSS_RINGO のベースカラー, 2: ??, 3: BOSS_DAINN のベースカラー

#define OBP_MEGAPOWER 296  // ロックパワー適用時のプレイヤーのベースカラー (OBP_MEGAMAN とは別)
#define OBP_GUTSPOWER 297  // ガッツパワー
#define OBP_PROTOPOWER 298
#define OBP_TOADPOWER 299

// プレイヤーに特殊効果が付くときに, プレイヤーの元のパレットとブレンドして使う (代表例は、エレメントのエンチャント)
// 0..6, 0: ソル, 1: ダーク, 2: フレイム, 3: フロスト, 4: クラウド, 5: アース, 6: ルナ
// 特に 0 (ソル) は良い効果がかかった時の汎用カラー としてよく使われる
#define OBP_ELEMENT(elementColor) (289 + (elementColor))

#define OBP_WHITE_306 306  // 色0 が RGB(24, 24, 24), それ以外は真っ白, 被弾時の白塗り

#define OBP_LEVER_SWITCH 313
#define OBP_LEVER_SWITCH_RUSTY 314  // 錆びたレバースイッチ

#define OBP_GENERATOR(idx) (451 + (idx))  // SPRITE_GENERATOR

#define OBP_COFFIN(coffinID) (519 + (coffinID))

#define OBP_LAVA_FLOOR 531

#define OBP_CUBE_ICE 577  // 氷ブロック
#define OBP_OCTOROK 579   // ドヴァリン、オクトパスの投げる岩

#define OBP_SPIKEBALL(idx) (635 + (idx))  // SPRITE_SPIKEBALL, 0: 棘鉄球, 1: ??, 2: 正義のカード

#define OBP_MEGAMAN 695  // ロックマンのベースカラー

#endif  // __INCLUDE_CONSTANTS_SPRITE_PALETTE_H__
