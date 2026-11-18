#ifndef __INCLUDE_CONSTANTS_SPRITE_H__
#define __INCLUDE_CONSTANTS_SPRITE_H__

#define SPR_UI_MAP 0x0312                          // 0x0312, スタートメニューのマップ画面で使うスプライト, BOKHASH("obj_map_oud")?
#define SPR_EVENT_SUN 0x0C23                       // ラスボス戦のイベントで使う太陽光のエフェクト
#define SPR_DJANGO_LARGE 0x1774                    // ソルデバイスやラスボス戦のイベントで使う、ジャンゴの大きな1枚絵
#define SPR_FLAMETHROWER 0x1BC7                    // 火炎放射
#define SPR_UI_MISC 0x414C                         // 0x414C, 太陽鍛治, ショップ名, "時の家"の暗証番号入力端末 など、メニューUIのうち、用途が限定的でサイズの小さいものをここにまとめている, BOKHASH("obj_kaji_oud")?
#define SPR_UI_TITLE 0x42E2                        // 0x42E2, 太陽センサーのヘルプの手や住んでる地域のフォント, BOKHASH("obj_nam_oud")?
#define SPR_INVENTORY_ICONS 0x5D04                 // アイテムアイコン, poseIdx は "include/constants/item_icon.h"
#define SPR_SHADEMAN 0x5D36                        // シェードマン(EXE)
#define SPR_UI_GALLERY 0x5EBF                      // 0x5EBF, 図書館で見れる魔物図鑑,武器図鑑,アルバムのUI, BOKHASH("obj_bok_oud")?
#define SPR_UI_BANK 0x6893                         // 太陽バンクのUI
#define SPR_MARKERS 0x82F1                         // "Undead", "Immortal", "TRAP" といった画面上に表示されるマーカー
#define SPR_UI_LOAN 0x92F0                         // 0x92F0, 暗黒ローンのUI, BOKHASH("obj_gin_oud")?
#define SPR_JORMUNGANDR BOKHASH("lasbos_oud")      // 0x9524, ヨルムンガンド
#define SPR_SKELETONS 0xAE52                       // スケルトン
#define SPR_MEGAMAN 0xAF82                         // ロックマン(EXE)
#define SPR_UI_START_MENU 0xB343                   // 0xB343, スタート画面で表示されるUI(の大半), BOKHASH("obj_sys_oud")?
#define SPR_CANDLE_BOX 0xB991                      // ろうそくが乗ってる箱
#define SPR_PORTRAITS 0xD27A                       // 会話などで使う顔アイコン
#define SPR_TITLE 0xD353                           // 0xD353, タイトル画面のUI, BOKHASH("obj_tit_oud")?
#define SPR_DUNEYRR BOKHASH("bos00_oud")           // 0xD3CA, ドゥネイル
#define SPR_RINGO BOKHASH("bos01_oud")             // 0xD3DA, 紅のリンゴ
#define SPR_SHAIAN BOKHASH("bos02_oud")            // 0xD3EA, シャイアン
#define SPR_DURATHROR BOKHASH("bos03_oud")         // 0xD3FA, ドゥラスロール
#define SPR_DVALINN BOKHASH("bos04_oud")           // 0xD40A, ドヴァリン
#define SPR_UI_LINK 0xDCC1                         // 0xDCC1, 通信画面で使うUI, BOKHASH("obj_lnk_oud")?
#define SPR_DJANGO_SABATA 0xDE23                   // 0xDE23, 主人公, BOKHASH("ply_00_oud")?
#define SPR_UI_SENSOR_HELP 0xDF11                  // 太陽センサーのヘルプ画面で使うUI
#define SPR_SMITH_MARCELLO BOKHASH("npc00_oud")    // 0xDFCE, スミス, マルチェロ
#define SPR_RITA BOKHASH("npc01_oud")              // 0xDFDE, リタ
#define SPR_ZAJI BOKHASH("npc02_oud")              // 0xDFEE, ザジ
#define SPR_SUMIRE BOKHASH("npc03_oud")            // 0xDFFE, スミレ
#define SPR_KURO BOKHASH("npc04_oud")              // 0xE00E, クロ
#define SPR_KID BOKHASH("npc05_oud")               // 0xE01E, キッド
#define SPR_LADY BOKHASH("npc06_oud")              // 0xE02E, レディ
#define SPR_COFSELLER_HATENA BOKHASH("npc07_oud")  // 0xE03E, 棺桶屋, はてな(ゲーム内表記は"???")
#define SPR_ENNIO_LUIS BOKHASH("npc08_oud")        // 0xE04E, エンニオ, ルイス
#define SPR_CARMILLA 0xE2DE                        // カーミラ(恋人のカード のエフェクト)
#define SPR_DAINN 0xE349                           // ダーイン (人型)
#define SPR_DUNGEON_TITLE 0xE89F                   // 無幻街の最終階層とかで使う特殊フォント
#define SPR_CHANDELIER 0xF099                      // 0x2AF0 にもシャンデリアがある

// --------------------------------------------

#define SPR_PLANT_2567 0x2567                     // 多分、ドゥラスロール倒すまで奥の楔の部屋への入り口を塞いでる植物
#define SPR_DEBRIS_C42D 0xC42D                    // なんかの破片?
#define SPR_DEBRIS_0334 0x0334                    // C42Dの破片の小さいやつ?
#define SPR_KOMAINU 0xF680                        // 大聖堂の狛犬
#define SPR_BOMB BOKHASH("bomb_00")               // 0xE74B, 丸い爆弾, ポイズンスパイダーの毒液, ダイナマイト, ANIM_BOMB が bomb_00_anm なので確定
#define SPR_MELEE_SHOCKWAVE 0x8F5D                // 近接攻撃の衝撃波(黒ジャンゴの追加の衝撃波のエフェクト, 武器自体は SPR_DJANGO_SABATA が担う), あと太陽鍛治の水桶も一緒に入っている
#define SPR_OTENKO_00 BOKHASH("otenko_00")        // 0x97D3, おてんこさま
#define SPR_OTENKO_01 BOKHASH("otenko_01")        // 0x97D4, おてんこさま
#define SPR_EFF_F422 0xF422                       // 複数の種類のエフェクトをまとめたエフェクト群? (サーペントの泡, リッチ+の火の玉 など中ボス系のエフェクトをまとめている?)
#define SPR_ACID_0 0xA5B3                         // 0xA5B3, 溶解液 (ホルルン液, ドヴァリンの墨玉)
#define SPR_ACID_1 0xA5B4                         // 0xA5B4, 溶解液 (ホルルン液, ドヴァリンの墨玉)
#define SPR_SPEAKER 0x5AFD                        // シェードマンがクラッシュノイズのときに出すスピーカー
#define SPR_EFF_5AFE 0x5AFE                       // 輪っかのエフェクト(シェードマン関連?)
#define SPR_GRATING 0x2C12                        // 鳴り床(上を歩くと音が鳴る床)
#define SPR_EFF_A20C 0xA20C                       // キラキラエフェクト
#define SPR_WALL_9D2D 0x9D2D                      // 壁?
#define SPR_PILLER_048A 0x048A                    // 柱?
#define SPR_LIGHT_BULB 0xB0E2                     // 電球
#define SPR_GEN_UNUSED 0xC060                     // 前作のラスボス戦でのジェネレータ(不使用)
#define SPR_WALL_DD5C 0xDD5C                      // 壁?
#define SPR_WALL_4AEE 0x4AEE                      // 壁?
#define SPR_ECT BOKHASH("ect")                    // 0xA0D5, エクトプラズム
#define SPR_CHANDELIER_2AF0 0x2AF0                // シャンデリア
#define SPR_TRAP_FLOOR 0xA680                     // トラップ床, 水たまり(PLAYER_BDJANGO, PLAYER_MOUSE のときに踏むとダメージ), 鳴り床(踏むと音が鳴る床), 太陽警報機(太陽ゲージが1以上の時に、踏むと音が鳴る床)
#define SPR_UNUSED_A6A0 0xA6A0                    // ボクタイ1の血錆の館の中庭の数字が答えになる4つのレバーの上に書いてある数字(不使用?)
#define SPR_EFF_2D41 0x2D41                       // エフェクト群 (コカトリスが石化光線で使用, 他の用途は不明)
#define SPR_HINT_PANEL BOKHASH("panel_00")        // 0xA850, ヒントパネル
#define SPR_RUBBLE_008A 0x008A                    // 瓦礫?
#define SPR_COIN BOKHASH("coin_00")               // 0x2712, コイン (通信対戦で相手を倒すと落とす)
#define SPR_MIRROR BOKHASH("mirror_00")           // 太陽ミラー (前作のデータで今作は不使用)
#define SPR_OJISAN 0x4AAE                         // おっさん
#define SPR_EFF_9FF5 0x9FF5                       // エフェクト群 (不使用?)
#define SPR_LILYPAD 0xD166                        // ハスの葉
#define SPR_MAGIC_SQUARE BOKHASH("warp_00")       // 0x0BA8, 魔方陣
#define SPR_MAGIC_SQUARE_L BOKHASH("warp_01")     // 0x0BA9, 魔方陣(大)
#define SPR_EMOTION_0 0x363C                      // "!"
#define SPR_EMOTION_1 0x363D                      // EmoteManager が SPR_EMOTION_0 と一緒に読む
#define SPR_WALL_1FBD 0x1FBD                      // なんかの壁
#define SPR_KID_SHOP_0 0x6AF6                     // キッドの店の内装
#define SPR_KID_SHOP_1 0x6AF7                     // キッドの店の内装(武者鎧)
#define SPR_HIMAWARI 0x7E82                       // ひまわり
#define SPR_PROPERTY_CUBE 0xBCA8                  // 属性キューブ
#define SPR_PUFF_4384 0x4384                      // エフェクト(地下水路の滝とかの水飛沫?)
#define SPR_WH_SHUTTER 0x34C0                     // 倉庫のシャッター (まだ倉庫の鍵を取っていないものにかかっている)
#define SPR_BLACKHOLE 0x3641                      // ブラックホール(その他の暗黒エフェクトでも流用?)
#define SPR_WEDGE 0xF070                          // 封印の楔
#define SPR_SOLAR_PLANT 0xC3C3                    // 太陽の根(ヒーリングで成長させられるもじゃもじゃ)
#define SPR_BED BOKHASH("bed00")                  // 0x1C84, ベッド
#define SPR_UNUSED_FDC5 0xFDC5                    // 不使用 (前作の"伯爵"の血槍攻撃)
#define SPR_SIGNBOARD 0x96F7                      // サンミゲルのまだ利用できない施設の入り口にある看板
#define SPR_COMBO_SCORE 0xA5BD                    // ブラックパンサー(ミニゲーム)の"COMBO:", "SCORE:" の文字
#define SPR_NUTS 0x41B1                           // 果物屋の内装
#define SPR_TREE_SAPLING 0xDC8E                   // 太陽樹の苗木
#define SPR_MOUSE_BRIDGE 0xCDAB                   // チェンジ・マウスで渡れる木片
#define SPR_LOAN_CARPET 0xB044                    // 前作の暗黒ローン入口の絨毯 (今作は不使用)
#define SPR_CURORO_SHOTS BOKHASH("curoro_shots")  // 0x3668, ダーインが放つエネルギー弾 (クロロホルルン+)
#define SPR_OJAMA_BAT 0x18A8                      // オジャマバット
#define SPR_OJAMA_BAT_CTR 0x18A9                  // オジャマバットのカウンター (オジャマバットがいくつあるかを示す)
#define SPR_TOUCH_SWITCH 0x2769                   // 接触スイッチ(+電球), BOKHASH("switch_00")?
#define SPR_DURATH_SPIKE 0x848F                   // ドゥラスロール(第1形態)の飛ばす棘
#define SPR_8490 0x8490                           // 砂に潜るエフェクト?
#define SPR_9A1F BOKHASH("start")                 // 0x9A1F, "PUSH START BUTTON"の文字(どこで使ってるか不明)
#define SPR_2817 0x2817                           // 大聖堂の水晶?
#define SPR_EFD8 0xEFD8                           // 0..9の数字とまだ何も数字が書かれていないパネルの絵
#define SPR_TIME_M_SQ 0xA152                      // タイム魔方陣 (Time Magic Square)
#define SPR_SWW_17C7 0x17C7                       // 重量スイッチ, swtow00? (ow: over weight?), 無理があるか...
#define SPR_SWW_17C8 0x17C8                       // 重量スイッチ
#define SPR_SWW_17C9 0x17C9                       // 重量スイッチ
#define SPR_SWW_17CA 0x17CA                       // 重量スイッチ
#define SPR_SWW_17CB 0x17CB                       // 重量スイッチ
#define SPR_SWW_B0BC 0xB0BC                       // 重量スイッチ
#define SPR_EBALL_210E 0x210E                     // エネルギー弾, 銃の弾やライジングサンで打ち上げる玉として使う
#define SPR_2C1A 0x2C1A                           // 岩の角みたいな何か
#define SPR_DARKGENERATOR 0xC046                  // 暗黒発電機(人が走ることで発電するベルドコンベア)
#define SPR_LEVER_SWITCH 0xBB68                   // レバースイッチ
#define SPR_WATER_SPRING 0xEED8                   // 砂漠の水汲み場
#define SPR_DISH 0x505C                           // 料理
#define SPR_STAND 0xA47C                          // 太陽スタンド, stand00_00?
#define SPR_PANTHER_BONUS 0xA8E7                  // ブラックパンサー(ミニゲーム)のボーナス表示
#define SPR_44EE 0x44EE                           // なんかのブロックor柱
#define SPR_5D7C 0x5D7C                           // 瓦礫
#define SPR_B837 0xB837                           // ??
#define SPR_LASBOS_00 BOKHASH("lasbos00")         // 0x8202, ヨルムンガンドの怪光線 + ヨルムンガンドの楔?
#define SPR_LASBOS_01 BOKHASH("lasbos01")         // 0x8203, ヨルムンガンド
#define SPR_LASBOS_02 BOKHASH("lasbos02")         // 0x8204, ヨルムンガンド
#define SPR_LASBOS_03 BOKHASH("lasbos03")         // 0x8205, ヨルムンガンドの楔
#define SPR_LASBOS_04 BOKHASH("lasbos04")         // 0x8206, ヨルムンガンドのタコ足
#define SPR_LASBOS_05 BOKHASH("lasbos05")         // 0x8207, ヨルムンガンド
#define SPR_BAMBOO 0x066A                         // 太陽ダケ
#define SPR_WALL_DB6C 0xDB6C                      // 壁?
#define SPR_CANTERA 0xD0A3                        // カンテラ
#define SPR_BEE_NEST_BROKEN 0x9385                // 壊れた蜂の巣
#define SPR_BEE_NEST BOKHASH("bee_nest")          // 0xB626, 蜂の巣
#define SPR_E7EA 0xE7EA                           // エフェクト
#define SPR_DFCF 0xDFCF                           // 棘付き根っこ
#define SPR_SPIRAL_CONSOLE 0x0E48                 // 螺旋の塔の管理コンソール
#define SPR_TREE_BUD 0xDC72                       // 太陽樹の芽
#define SPR_C039 0xC039                           // パイルドライバーの方陣の中心
#define SPR_D56D 0xD56D                           // ??, 昇降床の影の部分?
#define SPR_MOUSE BOKHASH("rat")                  // 0xD495, チェンジマウスで変身するネズミ
#define SPR_PINPAD 0x3C13                         // "時の家"の暗証番号設定端末
#define SPR_EMBLEM_7C99 0x7C99                    // 各属性のエンブレム(パズルの床に使うデカール?)
#define SPR_GENERATOR 0xC038                      // パイルドライバーのジェネレータ
#define SPR_TORCH 0x6154                          // 大聖堂の地下にあるトーチ (lod_00="Light Of Dungeon"?, hlmp_00="HurricaneLaMP"?)
#define SPR_PETAL_CC88 0xCC88                     // 散った花びらのように見えるなにか(満開の太陽樹の花びら?)
#define SPR_MONOLITH 0x96B5                       // 砂漠の(3つの石版のことが書いてある)石碑
#define SPR_DRIED_OASIS 0x2C3D                    // 3つの石版を探す砂漠で砂漠入り口から1つ上のマップにある干上がったオアシス
#define SPR_GUN_SPREAD 0x2110                     // ガンデルヘルのスプレッド攻撃
#define SPR_COFFIN_0 BOKHASH("cof00")             // 0x2499, 全ての棺桶(エレファン含む)
#define SPR_COFFIN_1 BOKHASH("cof01")             // 0x249A, 棺桶獣エレファン(自走時?)
#define SPR_F_WALL_5B54 0x5B54                    // ダイナマイトで壊せる壁
#define SPR_CACTUS 0x04B3                         // サボテン(攻撃で破壊できる小物オブジェ)
#define SPR_LAVA_FLOOR 0x4FDA                     // 溶岩床(前作のデータの消し忘れ?)
#define SPR_LAVA_8638 0x8638                      // "リッチ+"?, 火炎弾, マグマの間欠泉
#define SPR_EXPLOSION 0x8639                      // 爆発 (ライジングサンが弾ける時もこれ)
#define SPR_SPRING_863A 0x863A                    // 下から噴き出すマグマや水
#define SPR_DUNEYRR_AUX 0x61F9                    // ドゥネイルの出すエフェクトや芋虫(ドゥネイル本体は別), ドゥラスロールのものも含む
#define SPR_SHAIAN_SHOP 0x2058                    // 武器屋(シャイアンの店)の内装
#define SPR_DVALIN_00 BOKHASH("bos04_00")         // 0x2E78, ドヴァリン
#define SPR_DVALIN_01 BOKHASH("bos04_01")         // 0x2E79, ドヴァリン
#define SPR_DVALIN_02 BOKHASH("bos04_02")         // 0x2E7A, ドヴァリン
#define SPR_DVALIN_03 BOKHASH("bos04_03")         // 0x2E7B, ドヴァリン
#define SPR_DVALIN_04 BOKHASH("bos04_04")         // 0x2E7C, ドヴァリン
#define SPR_494E 0x494E                           // 遺跡ステージ前半の柱
#define SPR_2EC0 0x2EC0                           // 遺跡ステージの4人の燭台の床パネル?
#define SPR_BAT 0xDA6D                            // バット
#define SPR_EFF_SHAIAN_SPIN 0x354D                // シャイアンの回転斬りのエフェクト
#define SPR_SHAIAN_AX 0x39A3                      // シャイアンが投げる斧
#define SPR_GAMEOVER BOKHASH("over")              // 0x654B, "GAMEOVER"
#define SPR_SPIKEBALL 0x24BA                      // 棘鉄球
#define SPR_PITFALL_A945 0xA945                   // 落とし穴
#define SPR_PITFALL_70EE 0x70EE                   // 落とし穴
#define SPR_6F57 0x6F57                           // 1..12 までの数字パネル(boktai1のアセットが残ってるだけ？)
#define SPR_TOWERCLOCK 0x0C0A                     // 時計塔の時計
#define SPR_DF0E 0xDF0E                           // 暗黒樹の蔓
#define SPR_1E15 0x1E15                           // 暗黒樹の芽
#define SPR_WARDEN 0x0DDE                         // おしおき部屋の看守
#define SPR_FIRE_BREATH 0x84B4                    // ヘルハウンドのファイヤーブレス
#define SPR_FIRE_96C1 0x96C1                      // 火炎放射
#define SPR_FIRE_96C2 0x96C2                      // SPR_FIRE_96C1 の残り火
#define SPR_MIMIC 0x3876                          // 普通の宝箱も兼ねる

// 汎用エフェクト系
#define PTCL_GROUP_0 BOKHASH("eff_eff_00")        // 0x1C1A, ROMにこの文字列があるのでこれは確定
#define SPR_EFF_1C1B BOKHASH("eff_eff_01")        // 0x1C1B, エフェクト群(煙、蜘蛛の巣,影)
#define PTCL_GROUP_1 BOKHASH("eff_eff_02")        // 0x1C1C, ANIM_D41F が "eff_eff_02_anm" で一致し、利用箇所も一致するので、 可能性はかなり高いと思われる
#define SPR_LVUP_INDICATOR BOKHASH("eff_eff_03")  // 0x1C1D, レベルアップのインジケータ, 全然汎用エフェクトではないのでこれだけは根拠が薄い
#define PTCL_GROUP_2 BOKHASH("eff_eff_04")        // 0x1C1E, エレメントのパーティクル

// エネミー系, 共通の接頭辞 + 1文字の連番 (接頭辞は未特定), SPR_DOG_E369 / SPR_WORM_E76x / SPR_EF69 は本体の名前 + "_1"〜"_3"
#define SPR_DOG 0xD635        // 犬
#define SPR_WORM 0xD636       // ワーム系
#define SPR_GHOST 0xD637      // ゴースト, レイス
#define SPR_DARKROOT 0xD638   // 暗黒の根
#define SPR_DOG_E369 0xE369   // 犬
#define SPR_WORM_E769 0xE769  // ワーム系(センチピード, サンドウォーム, サーペント)
#define SPR_WORM_E76A 0xE76A  // リッチ+の出す炎の蛇
#define SPR_WORM_E76B 0xE76B  // リッチ+の出す炎の蛇
#define SPR_EF69 0xEF69       // 暗黒の根

// エネミー系 (2), 共通の接頭辞 + 1文字の連番 (接頭辞は未特定)
#define SPR_CURORO 0xD28E     // クロロホルルン
#define SPR_OCTOPUS_0 0xD291  // オクトパス
#define SPR_OCTOPUS_1 0xD292  // オクトパスが水中にいるときのシルエット

// エネミー系 (3), 共通の接頭辞 + 1文字の連番 (接頭辞は未特定)
#define SPR_SPIDER 0x528F          // スパイダー
#define SPR_GOLEM 0x5290           // ゴーレム
#define SPR_SWORD_AX 0x5291        // ソード(敵)、アックス(敵)
#define SPR_SLAVE_SWORD_AX 0x5292  // スレイブソード, リンゴ(ダーイン)の出す剣

// エネミー系 (4), ボクとマミーの組, 共通の接頭辞 + 1文字の連番 (接頭辞は未特定)
#define SPR_BOKU_0 0x9247      // ボク(今作では グール)
#define SPR_BOKU_1 0x9248      // ボク(今作では グール)
#define SPR_MUMMY_924B 0x924B  // マミー

// エネミー系 (5), ボクとマミーの組, 共通の接頭辞 + 1文字の連番 (接頭辞は未特定)
#define SPR_BOKU_D4EA 0xD4EA   // ボク
#define SPR_MUMMY_D4EE 0xD4EE  // マミー

// エネミー系 (6), ボクとマミーの組, ID の差が 0x100 (後ろから2文字目の違い?)
#define SPR_BOKU_47DE 0x47DE  // ボク
#define SPR_MUMMY 0x48DE      // マミー

// エネミー系
#define SPR_BEE BOKHASH("bee")      // 0x9506, ビー
#define SPR_SLIME BOKHASH("slime")  // 0xB96C, スライム
#define SPR_CROW_0 0x5A6E           // クロウ
#define SPR_CROW_1 0x5A6F           // クロウ
#define SPR_COCKATRICE_0 0x41CF     // コカトリス
#define SPR_COCKATRICE_1 0x43CF     // コカトリス
#define SPR_SKELETON_MISC 0xD45E    // スケルトン (リッチやアーチャといったスケルトンの派生タイプのスプライト?)
#define SPR_EFF_D85E 0xD85E         // エフェクト群(電気っぽい), リッチの攻撃エフェクト?
#define SPR_SLIME_7031 0x7031       // 0x7031, スライムの破片, BOKHASH("slime_nec_00")? (nec は necro?)
#define SPR_SLIME_7032 0x7032       // 0x7032, スライムの破片, BOKHASH("slime_nec_01")? (nec は necro?)

// 移動ブロック系, 共通の接頭辞 + 1文字の連番 (接頭辞は未特定), 破片は本体の名前 + "a" (大) / "b" (小)
#define SPR_ROCK_9D3F 0x9D3F           // 岩石, "オフセット"(=offset), "20・20"(=32x32) というデバッグ用の文字列がある
#define SPR_WOODEN_BOX 0x9D40          // 木ブロック (海外版の名称が Wooden Box)
#define SPR_BLOCK_ROCK 0x9D41          // 岩ブロック
#define SPR_BLOCK_9D43 0x9D43          // 前作の太陽都市で使われていたブロック (今作不使用?)
#define SPR_CUBE_WOOD_DEBRIS_L 0xA874  // 木ブロックの破片(大)
#define SPR_CUBE_WOOD_DEBRIS_S 0xA875  // 木ブロックの破片(小)
#define SPR_CUBE_ROCK_DEBRIS_L 0xA894  // 岩ブロックの破片(大)
#define SPR_CUBE_ROCK_DEBRIS_S 0xA895  // 岩ブロックの破片(小)

// 移動ブロック系
#define SPR_BLOCK_EMBLEM 0xB306       // 紋章ブロック(炎氷地風)
#define SPR_BLOCK_EMBLEM_16F5 0x16F5  // 紋章ブロック
#define SPR_TOMBSTONE 0x05A2          // 大聖堂の(偽物の)墓, 移動ブロックのように押せる
#define SPR_BLOCK_ICE 0x84EE          // 氷ブロック, 1番小さいやつはドヴァリンやオクトパスの投げる岩としても使う
#define SPR_BLOCK_IRON 0xE0C9         // 鉄ブロック
#define SPR_BLOCK_ARITH 0x2097        // 算術ブロック(前作のデータが消し忘れ？)

// 天窓の光
#define SPR_1D78 0x1D78         // 天窓の光と、あと砂っぽい地面?
#define SPR_SPOTLIGHT 0x3640    // 天窓の光(汎用?, 魔方陣などのエフェクトもこれかも？)
#define SPR_WINDOW_5B78 0x5B78  // 天窓の光
#define SPR_WINDOW_5BA7 0x5BA7  // 天窓の光
#define SPR_WINDOW_5BB7 0x5BB7  // 天窓の光
#define SPR_DC07 0xDC07         // 天窓の光
#define SPR_WINDOW_DDE7 0xDDE7  // 天窓の光
#define SPR_9E08 0x9E08         // 天窓の光

// 床系
#define SPR_LIFT_IRON 0xB019    // 昇降床(金属)
#define SPR_LIFT_ROCK0 0xDA09   // 移動床(岩), 変異域の溶岩のところや地下水路で使用
#define SPR_LIFT_MECHA 0xC3BD   // 移動床(機械), 汎用 (水平,垂直)
#define SPR_LIFT_ROCK1 0x9462   // 移動床(岩), SPR_LIFT_ROCK0 と似てるけど微妙に違う
#define SPR_SOLAR_FLOOR 0xC459  // 太陽床
#define SPR_LIFT_SMOVE 0x75D6   // 太陽移動床(太陽床とは別物), 森 1F で使用
#define SPR_LIFT_WEIGHT 0x7605  // 重量昇降床(乗ったものの重量に応じて行き先が変わる), 暗黒街で使用

// 扉系
#define SPR_IRON_BARS_1B59 0x1B59                  // 扉(鉄格子)
#define SPR_DOOR_WOOD_0 BOKHASH("door_obj_00")     // 0x7ACD, 扉(木)
#define SPR_DOOR_WOOD_1 BOKHASH("door_obj_01")     // 0x7ACE, 扉(木)
#define SPR_DOOR_WOOD_2 BOKHASH("door_obj_02")     // 0x7ACF, 扉(木)
#define SPR_DOOR_WOOD_3 BOKHASH("door_obj_03")     // 0x7AD0, 扉(木)
#define SPR_DOOR_WOOD_4 BOKHASH("door_obj_04")     // 0x7AD1, 扉(木)
#define SPR_IRON_BARS_7AD2 BOKHASH("door_obj_05")  // 0x7AD2, 扉(鉄格子)
#define SPR_DOOR_LOCKED_0 BOKHASH("door_obj_06")   // 0x7AD3, 鍵のかかった青い扉
#define SPR_DOOR_LOCKED_1 BOKHASH("door_obj_07")   // 0x7AD4, 鍵のかかった青い扉
#define SPR_DOOR_LOCKED_2 BOKHASH("door_obj_08")   // 0x7AD5, 鍵のかかった青い扉
#define SPR_DOOR_LOCKED_3 BOKHASH("door_obj_09")   // 0x7AD6, 鍵のかかった青い扉
#define SPR_DOOR_LOCKED_4 BOKHASH("door_obj_10")   // 0x7AED, 鍵のかかった青い扉
#define SPR_DOOR_LOAN_0 BOKHASH("door_obj_11")     // 0x7AEE, 暗黒ローンの扉
#define SPR_DOOR_LOAN_1 BOKHASH("door_obj_12")     // 0x7AEF, 暗黒ローンの扉
#define SPR_DOOR_LOAN_2 BOKHASH("door_obj_13")     // 0x7AF0, 暗黒ローンの扉
#define SPR_DOOR_LOAN_3 BOKHASH("door_obj_14")     // 0x7AF1, 暗黒ローンの扉
#define SPR_DOOR_LOAN_4 BOKHASH("door_obj_15")     // 0x7AF2, 暗黒ローンの扉
#define SPR_DOOR_16 BOKHASH("door_obj_16")         // 0x7AF3, 扉, 前作の暗黒城で使っていた
#define SPR_DOOR_17 BOKHASH("door_obj_17")         // 0x7AF4, 扉, 前作の暗黒城で使っていた
#define SPR_DOOR_18 BOKHASH("door_obj_18")         // 0x7AF5, 扉, 前作の暗黒城で使っていた
#define SPR_DOOR_19 BOKHASH("door_obj_19")         // 0x7AF6, 扉, 前作の暗黒城で使っていた
#define SPR_DOOR_20 BOKHASH("door_obj_20")         // 0x7B0D, 扉, 前作の暗黒城で使っていた
#define SPR_DOOR_SEALED 0xD962                     // タレット封印の扉(地下水路の入り口), 螺旋の塔の入り口, etc

// OcclusionMask 用, 壁の裏に入ったキャラを隠す壁の形 (黒塗り)
#define SPR_MASK_E1D2 0xE1D2                 // 黒塗り
#define SPR_MASK_76DB 0x76DB                 // 黒塗り
#define SPR_MASK_A606 0xA606                 // 黒塗り
#define SPR_MASK_E857 BOKHASH("lk00_mask")   // 0xE857, 黒塗り, 通信対戦のマップ
#define SPR_MASK_E505 0xE505                 // 黒塗り
#define SPR_MASK_22E7 0x22E7                 // 黒塗り
#define SPR_MASK_9DFF 0x9DFF                 // 黒塗り
#define SPR_MASK_1FE0 0x1FE0                 // 黒塗り
#define SPR_MASK_DC38 0xDC38                 // 黒塗り
#define SPR_MASK_8393 0x8393                 // 黒塗り
#define SPR_MASK_9803 0x9803                 // 黒塗り
#define SPR_MASK_9B09 0x9B09                 // 黒塗り
#define SPR_MASK_D454 0xD454                 // 黒塗り
#define SPR_MASK_35C7 0x35C7                 // 黒塗り
#define SPR_MASK_3B53 0x3B53                 // 黒塗り
#define SPR_MASK_7C07 BOKHASH("a00_mask")    // 0x7C07, 黒塗り, 廃墟 (a00)
#define SPR_MASK_FC07 BOKHASH("a20_mask")    // 0xFC07, 黒塗り, a20 のマップ
#define SPR_MASK_BC08 0xBC08                 // 黒塗り
#define SPR_MASK_BE6D 0xBE6D                 // 黒塗り
#define SPR_MASK_7BE7 0x7BE7                 // 黒塗り
#define SPR_MASK_7AC6 0x7AC6                 // 黒塗り
#define SPR_MASK_7BE2 0x7BE2                 // 黒塗り
#define SPR_MASK_0D44 BOKHASH("field_mask")  // 0x0D44, 黒塗り, フィールド (f00〜f05)

// データが存在しないスプライトのID
#define SPR_2117 0x2117  // 多分デバッグ用
#define SPR_NODATA_9DA7 0x9DA7

#endif  // __INCLUDE_CONSTANTS_SPRITE_H__
